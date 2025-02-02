#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <windows.h>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void keyPressActivate();

    Qt::Key virtualKeyToQtKey(int vkCode);

private slots:
    void performClick();

    void on_toggleKeyButton_clicked();

    void on_clickTypeButton_clicked();

    void on_infiniteClickButton_clicked();

    void on_finiteClickButton_clicked();

    void on_specificLocationSetting_clicked();

    void on_matchCursorSetting_clicked();

    void on_xPosEdit_editingFinished();

    void on_xPosEdit_textChanged(const QString &arg1);

    void on_yPosEdit_textChanged(const QString &arg1);

    void on_indefiniteTimeButton_clicked();

    void on_definiteTimeButton_clicked();

    void on_hoursEdit_textChanged(const QString &arg1);

    void on_minutesEdit_textChanged(const QString &arg1);

    void on_secondsEdit_textChanged(const QString &arg1);

    void on_millisecondsEdit_textChanged(const QString &arg1);

    void changeTimer();

    void on_verticalSlider_valueChanged(int value);

    void on_totalClicksEdit_textChanged(const QString &arg1);

    void on_cpsEdit_textChanged(const QString &arg1);

    void on_funTimeOn_clicked();

    void on_funTimeOff_clicked();

    void on_chooseLocationButton_clicked();

    void on_vineBoomCheck_checkStateChanged(const Qt::CheckState &arg1);

    void on_smackCheck_checkStateChanged(const Qt::CheckState &arg1);

    void on_superSmashCheck_checkStateChanged(const Qt::CheckState &arg1);

    void on_powCheck_checkStateChanged(const Qt::CheckState &arg1);

    void on_wompCheck_checkStateChanged(const Qt::CheckState &arg1);

    void on_costcoBoomCheck_checkStateChanged(const Qt::CheckState &arg1);


protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    enum Click_Type {
        LEFT,
        RIGHT,
        MIDDLE
    };

    Ui::MainWindow *ui;
    QMediaPlayer *player;

    bool clicking_active;
    QTimer *clickTimer;

    Qt::Key toggle_key = Qt::Key_unknown;
    bool new_toggle = false;

    Click_Type click_type = LEFT;

    double click_length = 100.0;

    int total_clicks = std::numeric_limits<int>::max();
    int click_count = 0;

    bool choosing_location;
    int screen_width = GetSystemMetrics(SM_CXSCREEN);
    int screen_height = GetSystemMetrics(SM_CYSCREEN);
    int pos_X = 0;
    int pos_Y = 0;

    int start_time;
    int total_interval = std::numeric_limits<int>::max();

    bool fun_time;
    QMediaPlayer *soundPlayer;
    QSet<QString> sounds;
    int volume;

};
#endif // MAINWINDOW_H
