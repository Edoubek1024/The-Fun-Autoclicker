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


// Establishes a low-level keyboard hook as a listener for key presses
HHOOK hHook;
static Qt::Key globalToggleKey;
static MainWindow* mainWindowInstance = nullptr;

LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode == HC_ACTION) {
        KBDLLHOOKSTRUCT* p = (KBDLLHOOKSTRUCT*)lParam;
        if (wParam == WM_KEYDOWN) {
            Qt::Key qt_key = virtualKeyToQtKey(p->vkCode);
            // If the key pressed is the toggle key set by the user, the clicking is toggled on
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

// Used to toggle on or off fun time features of the GUI
void MainWindow::funTimeToggle(bool set) {
    ui->funTimeOff->setChecked(!set);
    ui->funTimeOn->setChecked(set);
    ui->vineBoomCheck->setEnabled(set);
    ui->costcoBoomCheck->setEnabled(set);
    ui->smackCheck->setEnabled(set);
    ui->powCheck->setEnabled(set);
    ui->superSmashCheck->setEnabled(set);
    ui->wompCheck->setEnabled(set);
    ui->verticalSlider->setEnabled(set);
    fun_time = set;
}

// Used to toggle on or off interval features of the GUI
void MainWindow::intervalToggle(bool set) {
    ui->indefiniteTimeButton->setChecked(!set);
    ui->definiteTimeButton->setChecked(set);
    ui->hoursEdit->setEnabled(set);
    ui->minutesEdit->setEnabled(set);
    ui->secondsEdit->setEnabled(set);
    ui->millisecondsEdit->setEnabled(set);
}

// Used to toggle on or off position features of the GUI
void MainWindow::positionToggle(bool set) {
    ui->matchCursorSetting->setChecked(!set);
    ui->specificLocationSetting->setChecked(set);
    ui->xPosEdit->setEnabled(set);
    ui->yPosEdit->setEnabled(set);
}

// Constructor for the MainWindow class and sets up all initial states for the app
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

    ui->xPosEdit->setValidator(new QIntValidator(0, screen_width, this));
    ui->yPosEdit->setValidator(new QIntValidator(0, screen_height, this));
    positionToggle(false);
    choosing_location = false;

    ui->hoursEdit->setValidator(new QIntValidator(0, 23, this));
    ui->minutesEdit->setValidator(new QIntValidator(0, 59, this));
    ui->secondsEdit->setValidator(new QIntValidator(0, 59, this));
    ui->millisecondsEdit->setValidator(new QIntValidator(0, 999, this));
    intervalToggle(false);


    funTimeToggle(false);
    soundPlayer = new QMediaPlayer(this);


    ui->verticalSlider->setValue(99);
    QAudioOutput *audioOutput = new QAudioOutput(this);
    soundPlayer->setAudioOutput(audioOutput);
    audioOutput->setVolume(.99);
}

// Destructor of MainWindow
MainWindow::~MainWindow()
{
    if (hHook != NULL) {
        UnhookWindowsHookEx(hHook);
    }
    delete ui;
}

// This is the function that actually performs each click
void MainWindow::performClick() {

    // If the total clicks reach the maximum click amount or the click time reaches the maximum interval, the clicking ends
    if (total_clicks <= click_count || std::chrono::system_clock::now() >= target_time) {
        clicking_active = false;
        click_count = 0;
        clickTimer->stop();
        return;
    }
    // If the specific location setting is enabled, the cursor is set to the position given
    if (ui->specificLocationSetting->isEnabled()) {
        SetCursorPos(pos_X, pos_Y);
    }
    // The click is then performed corresponding to the type of click requested
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
    // The click count is then incremented
    click_count++;
    // If fun time is enabled, this carries out any sounds that have been checked off
    if (fun_time && !sounds.empty()) {
        QList<QString> soundsList = sounds.values();
        int index = QRandomGenerator::global()->bounded(soundsList.size());
        QString random_sound = soundsList.at(index);
        soundPlayer->setSource(QUrl("qrc:/sounds/sounds/" + random_sound));
        soundPlayer->play();
    }
}

// Activates the timer that carries out the performClick function
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

// Checks if there are any key presses while the window is in focus (Handles everything but autoclicker toggle)
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape) {
        QApplication::quit();
    } else if (event->key() == Qt::Key_C && choosing_location) {
        QPoint cursorPos = QCursor::pos();
        pos_X = 2 * cursorPos.x();
        pos_Y = 2 * cursorPos.y();
        ui->xPosEdit->setText(QString::number(pos_X));
        ui->yPosEdit->setText(QString::number(pos_Y));
        ui->chooseLocationButton->setText("Choose Location");
        choosing_location = false;
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

// Handles the setting of a new toggle key
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

// Handles the setting of a new click type using the Click_type enum
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

// Handles the setting of infinite clicks
void MainWindow::on_infiniteClickButton_clicked()
{
    total_clicks = std::numeric_limits<int>::max();
    ui->totalClicksEdit->setEnabled(false);
}

// Handles the setting of a finite amount of clicks to be performed
void MainWindow::on_finiteClickButton_clicked()
{
    total_clicks = ui->totalClicksEdit->text().toInt();
    ui->totalClicksEdit->setEnabled(true);

    if (total_clicks <= 0) {
        total_clicks = 1;
    }
}

// Handles the setting of the specific location mode
void MainWindow::on_specificLocationSetting_clicked()
{
    positionToggle(true);
}

// Handles the setting of the match cursor mode
void MainWindow::on_matchCursorSetting_clicked()
{
    positionToggle(false);
}

// Allows the user to change the x position for specific location mode
void MainWindow::on_xPosEdit_textChanged(const QString &arg1)
{
    if (arg1.toInt() > screen_width) {
        ui->xPosEdit->setText(QString::number(screen_width));
    }
    pos_X = ui->xPosEdit->text().toInt();
}

// Allows the user to change the y position for specific location mode
void MainWindow::on_yPosEdit_textChanged(const QString &arg1)
{
    if (arg1.toInt() > screen_height) {
        ui->yPosEdit->setText(QString::number(screen_height));
    }
    pos_Y = ui->yPosEdit->text().toInt();
}

// Handles the activation of indefinite interval mode
void MainWindow::on_indefiniteTimeButton_clicked()
{
    intervalToggle(false);
    total_interval = std::numeric_limits<int>::max();
}

// Changes the total interval to whatever has been provided by the user
void MainWindow::changeTimer() {
    total_interval = (ui->hoursEdit->text().toInt() * 3600000) +
                     (ui->minutesEdit->text().toInt() * 60000) +
                     (ui->secondsEdit->text().toInt() * 1000) +
                     ui->millisecondsEdit->text().toInt();
}

// Handles the activation of definite time mode
void MainWindow::on_definiteTimeButton_clicked()
{
    intervalToggle(true);
    changeTimer();
}

// The longest amount of time that the time interval will go to is one second less than 24 hours
// This means that each measure of time maxes out at -1 (mod (next time measure / current time measure))
// So, 23 hours for hours,
// 59 minutes for minutes,
// 59 seconds for seconds,
// and 9999 milliseconds for milliseconds

// Handles any changes to the maximum hours allowed for the autoclicker
void MainWindow::on_hoursEdit_textChanged(const QString &arg1)
{
    if (arg1.toInt() > 23) {
        ui->hoursEdit->setText("23");
    }
    changeTimer();
}

// Handles any changes to the maximum minutes allowed for the autoclicker
void MainWindow::on_minutesEdit_textChanged(const QString &arg1)
{
    if (arg1.toInt() > 59) {
        ui->minutesEdit->setText("59");
    }
    changeTimer();
}

// Handles any changes to the maximum seconds allowed for the autoclicker
void MainWindow::on_secondsEdit_textChanged(const QString &arg1)
{
    if (arg1.toInt() > 59) {
        ui->secondsEdit->setText("59");
    }
    changeTimer();
}

// Handles any changes to the maximum milliseconds allowed for the autoclicker
void MainWindow::on_millisecondsEdit_textChanged(const QString &arg1)
{
    if (arg1.toInt() > 999) {
        ui->millisecondsEdit->setText("999");
    }
    changeTimer();
}


// Handles any changes to the volume of Fun Time
void MainWindow::on_verticalSlider_valueChanged(int value)
{
    ui->volumeAmount->setText(QString::number(value));
    if (soundPlayer->audioOutput()) {
        soundPlayer->audioOutput()->setVolume(value / 100.0);
    }
}

// Handles any changes to the total clicks allowed by the autoclicker in one interval
void MainWindow::on_totalClicksEdit_textChanged(const QString &arg1)
{
    total_clicks = arg1.toInt();
}

// Handles any changes to the clicks per second set by the user
void MainWindow::on_cpsEdit_textChanged(const QString &arg1)
{
    click_length = 1000.0 / arg1.toDouble();
    clickTimer->setInterval(click_length);
}

// Sets Fun Time on
void MainWindow::on_funTimeOn_clicked()
{
    funTimeToggle(true);
}

// Sets Fun Time off
void MainWindow::on_funTimeOff_clicked()
{
    funTimeToggle(false);
}

// The function handling changes to the choose location button
void MainWindow::on_chooseLocationButton_clicked()
{
    // If the button is in default mode before clicked, activate choosing location mode
    if (!choosing_location) {
        choosing_location = true;
        ui->chooseLocationButton->setText("Press 'c' to choose");
    // If not, return to default mode
    } else {
        choosing_location = false;
        ui->chooseLocationButton->setText("Choose Location");
    }
}

// Changes the sounds set
void MainWindow::soundsSetChange(Qt::CheckState arg, const QString &sound) {
    if (arg == Qt::Checked) {
        sounds.insert(sound);
    } else {
        sounds.remove(sound);
    }
}

// The following six functions handle adding or removing sounds from the possible sounds to be played during Fun Time


void MainWindow::on_vineBoomCheck_checkStateChanged(const Qt::CheckState &arg1)
{
    QString sound = "Vine_boom.mp3";
    soundsSetChange(arg1, sound);
}


void MainWindow::on_smackCheck_checkStateChanged(const Qt::CheckState &arg1)
{
    QString sound = "Smack.mp3";
    soundsSetChange(arg1, sound);
}


void MainWindow::on_superSmashCheck_checkStateChanged(const Qt::CheckState &arg1)
{
    QString sound = "Super_smash.mp3";
    soundsSetChange(arg1, sound);
}


void MainWindow::on_powCheck_checkStateChanged(const Qt::CheckState &arg1)
{
    QString sound = "Pow.mp3";
    soundsSetChange(arg1, sound);
}


void MainWindow::on_wompCheck_checkStateChanged(const Qt::CheckState &arg1)
{
    QString sound = "Womp.mp3";
    soundsSetChange(arg1, sound);
}


void MainWindow::on_costcoBoomCheck_checkStateChanged(const Qt::CheckState &arg1)
{
    QString sound = "Bam.mp3";
    soundsSetChange(arg1, sound);
}
