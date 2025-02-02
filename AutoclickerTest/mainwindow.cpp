#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "keyconvert.h"
#include <windows.h>
#include <chrono>

#include <QIntValidator>
#include <QKeyEvent>
#include <QKeySequence>
#include <QString>
#include <QTimer>
#include <QApplication>
#include <QDebug>
#include <QRandomGenerator>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QFile>


HHOOK hHook;
static Qt::Key globalToggleKey;
static MainWindow* mainWindowInstance = nullptr;

LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode == HC_ACTION) {
        KBDLLHOOKSTRUCT* p = (KBDLLHOOKSTRUCT*)lParam;
        if (wParam == WM_KEYDOWN) {
            Qt::Key qt_key = virtualKeyToQtKey(p->vkCode);
            if (qt_key == globalToggleKey) {
                if (mainWindowInstance) {
                    mainWindowInstance->keyPressActivate();
                }
            }
        }
    }
    return CallNextHookEx(hHook, nCode, wParam, lParam);
}

std::chrono::system_clock::time_point target_time = std::chrono::system_clock::now() + std::chrono::seconds(60*60*24*365*20);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(500,400);

    globalToggleKey = toggle_key;
    mainWindowInstance = this;
    hHook = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, NULL, 0);

    clicking_active = false;
    clickTimer = new QTimer(this);
    clickTimer->setInterval(click_length);

    connect(clickTimer, &QTimer::timeout, this, &MainWindow::performClick);
    clickTimer->stop();

    ui->cpsEdit->setValidator(new QIntValidator(0, 999, this));

    ui->infiniteClickButton->setChecked(true);
    ui->totalClicksEdit->setEnabled(false);
    ui->totalClicksEdit->setValidator(new QIntValidator(0, 99999, this));

    ui->matchCursorSetting->setChecked(true);
    ui->xPosEdit->setValidator(new QIntValidator(0, screen_width, this));
    ui->xPosEdit->setEnabled(false);
    ui->yPosEdit->setValidator(new QIntValidator(0, screen_height, this));
    ui->yPosEdit->setEnabled(false);
    choosing_location = false;

    ui->indefiniteTimeButton->setChecked(true);
    ui->hoursEdit->setValidator(new QIntValidator(0, 23, this));
    ui->hoursEdit->setEnabled(false);
    ui->minutesEdit->setValidator(new QIntValidator(0, 59, this));
    ui->minutesEdit->setEnabled(false);
    ui->secondsEdit->setValidator(new QIntValidator(0, 59, this));
    ui->secondsEdit->setEnabled(false);
    ui->millisecondsEdit->setValidator(new QIntValidator(0, 999, this));
    ui->millisecondsEdit->setEnabled(false);

    ui->funTimeOff->setChecked(true);
    ui->vineBoomCheck->setEnabled(false);
    ui->costcoBoomCheck->setEnabled(false);
    ui->smackCheck->setEnabled(false);
    ui->powCheck->setEnabled(false);
    ui->superSmashCheck->setEnabled(false);
    ui->wompCheck->setEnabled(false);
    ui->verticalSlider->setEnabled(false);

    fun_time = false;
    soundPlayer = new QMediaPlayer(this);

    connect(soundPlayer, &QMediaPlayer::errorOccurred, [](QMediaPlayer::Error error) {
        qDebug() << "Error occurred while playing sound: " << error;
    });

    ui->verticalSlider->setValue(99);
    QAudioOutput *audioOutput = new QAudioOutput(this);
    soundPlayer->setAudioOutput(audioOutput);
    audioOutput->setVolume(.99);
}

MainWindow::~MainWindow()
{
    if (hHook != NULL) {
        UnhookWindowsHookEx(hHook);
    }
    delete ui;
}

void MainWindow::performClick() {

    if (total_clicks <= click_count || std::chrono::system_clock::now() >= target_time) {
        clicking_active = false;
        click_count = 0;
        clickTimer->stop();
        return;
    }
    if (pos_X > 0 && pos_Y > 0) {
        SetCursorPos(pos_X, pos_Y);
    }
    switch (click_type) {
        case LEFT:
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            break;
        case RIGHT:
            mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
            break;
        case MIDDLE:
            mouse_event(MOUSEEVENTF_MIDDLEDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_MIDDLEUP, 0, 0, 0, 0);
            break;
    }
    click_count++;
    if (fun_time && !sounds.empty()) {
        QList<QString> soundsList = sounds.values();
        int index = QRandomGenerator::global()->bounded(soundsList.size());
        QString random_sound = soundsList.at(index);
        soundPlayer->setSource(QUrl("qrc" + random_sound));
        soundPlayer->play();
    }
}

void MainWindow::keyPressActivate() {
    if (clicking_active) {
        clicking_active = false;
        clickTimer->stop();
    } else {
        clicking_active = true;
        clickTimer->start();
        click_count = 0;
        auto now = std::chrono::system_clock::now();
        target_time = now + std::chrono::milliseconds(total_interval);
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape) {
        QApplication::quit();
    } else if (event->key() == Qt::Key_C && choosing_location) {
        QPoint cursorPos = QCursor::pos();
        pos_X = cursorPos.x();
        pos_Y = cursorPos.y();
        ui->xPosEdit->setText(QString::number(pos_X));
        ui->yPosEdit->setText(QString::number(pos_Y));
    }
    if (new_toggle) {
        toggle_key = static_cast<Qt::Key>(event->key());
        globalToggleKey = toggle_key;
        ui->toggleKeyButton->setText(QKeySequence(toggle_key).toString());
        new_toggle = false;
    } else {
        QMainWindow::keyPressEvent(event);
    }

    event->accept();
}

void MainWindow::on_toggleKeyButton_clicked()
{
    new_toggle = !new_toggle;
    if (new_toggle) {
        ui->toggleKeyButton->setText("Press any key");
    } else {
        if (toggle_key == Qt::Key_unknown) {
            ui->toggleKeyButton->setText("Set toggle key");
        } else {
            QString s = QKeySequence(toggle_key).toString();
            ui->toggleKeyButton->setText(s);
        }
    }
}


void MainWindow::on_clickTypeButton_clicked()
{
    switch(click_type) {
        case LEFT:
            click_type = RIGHT;
            ui->clickTypeButton->setText("Right Click");
            break;
        case RIGHT:
            click_type = MIDDLE;
            ui->clickTypeButton->setText("Middle Click");
            break;
        case MIDDLE:
            click_type = LEFT;
            ui->clickTypeButton->setText("Left Click");
            break;
    }
}


void MainWindow::on_infiniteClickButton_clicked()
{
    total_clicks = std::numeric_limits<int>::max();
    ui->totalClicksEdit->setEnabled(false);
}


void MainWindow::on_finiteClickButton_clicked()
{
    total_clicks = ui->totalClicksEdit->text().toInt();
    ui->totalClicksEdit->setEnabled(true);

    if (total_clicks <= 0) {
        total_clicks = 1;
    }
}


void MainWindow::on_specificLocationSetting_clicked()
{
    ui->xPosEdit->setEnabled(true);
    ui->yPosEdit->setEnabled(true);
}


void MainWindow::on_matchCursorSetting_clicked()
{
    ui->xPosEdit->setEnabled(false);
    ui->yPosEdit->setEnabled(false);
}


void MainWindow::on_xPosEdit_editingFinished()
{
    if (ui->xPosEdit->text().toInt() > screen_width) {
        ui->xPosEdit->setText(QString::number(screen_width));
    }
}


void MainWindow::on_xPosEdit_textChanged(const QString &arg1)
{
    if (arg1.toInt() > screen_width) {
        ui->xPosEdit->setText(QString::number(screen_width));
    }
}


void MainWindow::on_yPosEdit_textChanged(const QString &arg1)
{
    if (arg1.toInt() > screen_height) {
        ui->yPosEdit->setText(QString::number(screen_height));
    }
}


void MainWindow::on_indefiniteTimeButton_clicked()
{
    ui->hoursEdit->setEnabled(false);
    ui->minutesEdit->setEnabled(false);
    ui->secondsEdit->setEnabled(false);
    ui->millisecondsEdit->setEnabled(false);
    total_interval = std::numeric_limits<int>::max();
}

void MainWindow::changeTimer() {
    total_interval = (ui->hoursEdit->text().toInt() * 3600000) +
                     (ui->minutesEdit->text().toInt() * 60000) +
                     (ui->secondsEdit->text().toInt() * 1000) +
                     ui->millisecondsEdit->text().toInt();
}

void MainWindow::on_definiteTimeButton_clicked()
{
    ui->hoursEdit->setEnabled(true);
    ui->minutesEdit->setEnabled(true);
    ui->secondsEdit->setEnabled(true);
    ui->millisecondsEdit->setEnabled(true);
    changeTimer();
}


void MainWindow::on_hoursEdit_textChanged(const QString &arg1)
{
    if (arg1.toInt() > 23) {
        ui->hoursEdit->setText("23");
    }
    changeTimer();
}


void MainWindow::on_minutesEdit_textChanged(const QString &arg1)
{
    if (arg1.toInt() > 59) {
        ui->minutesEdit->setText("59");
    }
    changeTimer();
}


void MainWindow::on_secondsEdit_textChanged(const QString &arg1)
{
    if (arg1.toInt() > 59) {
        ui->secondsEdit->setText("59");
    }
    changeTimer();
}


void MainWindow::on_millisecondsEdit_textChanged(const QString &arg1)
{
    if (arg1.toInt() > 999) {
        ui->millisecondsEdit->setText("999");
    }
    changeTimer();
}



void MainWindow::on_verticalSlider_valueChanged(int value)
{
    ui->volumeAmount->setText(QString::number(value));
    if (soundPlayer->audioOutput()) {
        soundPlayer->audioOutput()->setVolume(value / 100.0);
    }
}


void MainWindow::on_totalClicksEdit_textChanged(const QString &arg1)
{
    total_clicks = arg1.toInt();
}


void MainWindow::on_cpsEdit_textChanged(const QString &arg1)
{
    click_length = 1000.0 / arg1.toDouble();
    clickTimer->setInterval(click_length);
}


void MainWindow::on_funTimeOn_clicked()
{
    ui->vineBoomCheck->setEnabled(true);
    ui->costcoBoomCheck->setEnabled(true);
    ui->smackCheck->setEnabled(true);
    ui->powCheck->setEnabled(true);
    ui->superSmashCheck->setEnabled(true);
    ui->wompCheck->setEnabled(true);
    ui->verticalSlider->setEnabled(true);
    fun_time = true;
}


void MainWindow::on_funTimeOff_clicked()
{
    ui->vineBoomCheck->setEnabled(false);
    ui->costcoBoomCheck->setEnabled(false);
    ui->smackCheck->setEnabled(false);
    ui->powCheck->setEnabled(false);
    ui->superSmashCheck->setEnabled(false);
    ui->wompCheck->setEnabled(false);
    ui->verticalSlider->setEnabled(false);
    fun_time = false;
}


void MainWindow::on_chooseLocationButton_clicked()
{
    if (!choosing_location) {
        choosing_location = true;
        ui->chooseLocationButton->setText("Press 'c' to choose");
    } else {
        choosing_location = false;
        ui->chooseLocationButton->setText("Choose Location");
    }
}


void MainWindow::on_vineBoomCheck_checkStateChanged(const Qt::CheckState &arg1)
{
    QString sound = ":/sounds/sounds/Vine_boom.mp3";
    if (arg1) {
        sounds.insert(sound);
    } else if (sounds.contains(sound)) {
        sounds.remove(sound);
    }
}


void MainWindow::on_smackCheck_checkStateChanged(const Qt::CheckState &arg1)
{
    QString sound = ":/sounds/sounds/Smack.mp3";
    if (arg1) {
        sounds.insert(sound);
    } else if (sounds.contains(sound)) {
        sounds.remove(sound);
    }
}


void MainWindow::on_superSmashCheck_checkStateChanged(const Qt::CheckState &arg1)
{
    QString sound = ":/sounds/sounds/Super_smash.mp3";
    if (arg1) {
        sounds.insert(sound);
    } else if (sounds.contains(sound)) {
        sounds.remove(sound);
    }
}


void MainWindow::on_powCheck_checkStateChanged(const Qt::CheckState &arg1)
{
    QString sound = ":/sounds/sounds/Pow.mp3";
    if (arg1) {
        sounds.insert(sound);
    } else if (sounds.contains(sound)) {
        sounds.remove(sound);
    }
}


void MainWindow::on_wompCheck_checkStateChanged(const Qt::CheckState &arg1)
{
    QString sound = ":/sounds/sounds/Womp.mp3";
    if (arg1) {
        sounds.insert(sound);
    } else if (sounds.contains(sound)) {
        sounds.remove(sound);
    }
}


void MainWindow::on_costcoBoomCheck_checkStateChanged(const Qt::CheckState &arg1)
{
    QString sound = ":/sounds/sounds/Bam.mp3";
    if (arg1) {
        sounds.insert(sound);
    } else if (sounds.contains(sound)) {
        sounds.remove(sound);
    }
}

