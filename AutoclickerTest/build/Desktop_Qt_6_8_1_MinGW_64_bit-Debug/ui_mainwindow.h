/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *toggleKeyButton;
    QPushButton *clickTypeButton;
    QGroupBox *clickLocationGroup;
    QRadioButton *matchCursorSetting;
    QRadioButton *specificLocationSetting;
    QPushButton *chooseLocationButton;
    QTextBrowser *textBrowser_4;
    QLineEdit *xPosEdit;
    QTextBrowser *textBrowser_5;
    QLineEdit *yPosEdit;
    QTextBrowser *textBrowser;
    QTextBrowser *textBrowser_2;
    QTextBrowser *textBrowser_3;
    QGroupBox *clickAmountBox;
    QRadioButton *infiniteClickButton;
    QRadioButton *finiteClickButton;
    QTextBrowser *textBrowser_6;
    QLineEdit *totalClicksEdit;
    QGroupBox *groupBox;
    QRadioButton *indefiniteTimeButton;
    QRadioButton *definiteTimeButton;
    QLineEdit *hoursEdit;
    QLabel *label;
    QLineEdit *minutesEdit;
    QLabel *label_2;
    QLineEdit *secondsEdit;
    QLabel *label_3;
    QLineEdit *millisecondsEdit;
    QLabel *label_4;
    QTextBrowser *textBrowser_7;
    QLineEdit *cpsEdit;
    QLabel *label_5;
    QGroupBox *groupBox_2;
    QLabel *label_6;
    QRadioButton *funTimeOn;
    QRadioButton *funTimeOff;
    QSlider *verticalSlider;
    QLabel *volumeAmount;
    QGroupBox *groupBox_3;
    QCheckBox *vineBoomCheck;
    QCheckBox *costcoBoomCheck;
    QCheckBox *smackCheck;
    QCheckBox *superSmashCheck;
    QCheckBox *powCheck;
    QCheckBox *wompCheck;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(500, 417);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        toggleKeyButton = new QPushButton(centralwidget);
        toggleKeyButton->setObjectName("toggleKeyButton");
        toggleKeyButton->setGeometry(QRect(70, 50, 101, 31));
        toggleKeyButton->setIconSize(QSize(16, 16));
        clickTypeButton = new QPushButton(centralwidget);
        clickTypeButton->setObjectName("clickTypeButton");
        clickTypeButton->setGeometry(QRect(240, 50, 101, 31));
        clickLocationGroup = new QGroupBox(centralwidget);
        clickLocationGroup->setObjectName("clickLocationGroup");
        clickLocationGroup->setGeometry(QRect(0, 80, 321, 111));
        matchCursorSetting = new QRadioButton(clickLocationGroup);
        matchCursorSetting->setObjectName("matchCursorSetting");
        matchCursorSetting->setGeometry(QRect(10, 20, 111, 22));
        specificLocationSetting = new QRadioButton(clickLocationGroup);
        specificLocationSetting->setObjectName("specificLocationSetting");
        specificLocationSetting->setGeometry(QRect(10, 40, 111, 22));
        chooseLocationButton = new QPushButton(clickLocationGroup);
        chooseLocationButton->setObjectName("chooseLocationButton");
        chooseLocationButton->setGeometry(QRect(180, 30, 121, 61));
        textBrowser_4 = new QTextBrowser(clickLocationGroup);
        textBrowser_4->setObjectName("textBrowser_4");
        textBrowser_4->setGeometry(QRect(10, 70, 21, 31));
        xPosEdit = new QLineEdit(clickLocationGroup);
        xPosEdit->setObjectName("xPosEdit");
        xPosEdit->setGeometry(QRect(30, 70, 41, 31));
        textBrowser_5 = new QTextBrowser(clickLocationGroup);
        textBrowser_5->setObjectName("textBrowser_5");
        textBrowser_5->setGeometry(QRect(80, 70, 21, 31));
        yPosEdit = new QLineEdit(clickLocationGroup);
        yPosEdit->setObjectName("yPosEdit");
        yPosEdit->setGeometry(QRect(100, 70, 41, 31));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(0, 50, 71, 31));
        textBrowser_2 = new QTextBrowser(centralwidget);
        textBrowser_2->setObjectName("textBrowser_2");
        textBrowser_2->setGeometry(QRect(170, 50, 71, 31));
        textBrowser_3 = new QTextBrowser(centralwidget);
        textBrowser_3->setObjectName("textBrowser_3");
        textBrowser_3->setGeometry(QRect(0, 0, 501, 51));
        clickAmountBox = new QGroupBox(centralwidget);
        clickAmountBox->setObjectName("clickAmountBox");
        clickAmountBox->setGeometry(QRect(320, 80, 181, 111));
        infiniteClickButton = new QRadioButton(clickAmountBox);
        infiniteClickButton->setObjectName("infiniteClickButton");
        infiniteClickButton->setGeometry(QRect(10, 20, 91, 22));
        finiteClickButton = new QRadioButton(clickAmountBox);
        finiteClickButton->setObjectName("finiteClickButton");
        finiteClickButton->setGeometry(QRect(10, 40, 91, 22));
        textBrowser_6 = new QTextBrowser(clickAmountBox);
        textBrowser_6->setObjectName("textBrowser_6");
        textBrowser_6->setGeometry(QRect(10, 70, 91, 31));
        totalClicksEdit = new QLineEdit(clickAmountBox);
        totalClicksEdit->setObjectName("totalClicksEdit");
        totalClicksEdit->setGeometry(QRect(100, 70, 71, 31));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(0, 190, 501, 80));
        indefiniteTimeButton = new QRadioButton(groupBox);
        indefiniteTimeButton->setObjectName("indefiniteTimeButton");
        indefiniteTimeButton->setGeometry(QRect(10, 20, 111, 22));
        definiteTimeButton = new QRadioButton(groupBox);
        definiteTimeButton->setObjectName("definiteTimeButton");
        definiteTimeButton->setGeometry(QRect(130, 20, 181, 22));
        hoursEdit = new QLineEdit(groupBox);
        hoursEdit->setObjectName("hoursEdit");
        hoursEdit->setGeometry(QRect(40, 50, 41, 21));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(90, 50, 41, 16));
        minutesEdit = new QLineEdit(groupBox);
        minutesEdit->setObjectName("minutesEdit");
        minutesEdit->setGeometry(QRect(140, 50, 41, 21));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(190, 50, 49, 16));
        secondsEdit = new QLineEdit(groupBox);
        secondsEdit->setObjectName("secondsEdit");
        secondsEdit->setGeometry(QRect(250, 50, 41, 21));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(300, 50, 49, 16));
        millisecondsEdit = new QLineEdit(groupBox);
        millisecondsEdit->setObjectName("millisecondsEdit");
        millisecondsEdit->setGeometry(QRect(360, 50, 41, 21));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(410, 50, 71, 16));
        textBrowser_7 = new QTextBrowser(centralwidget);
        textBrowser_7->setObjectName("textBrowser_7");
        textBrowser_7->setGeometry(QRect(340, 50, 91, 31));
        cpsEdit = new QLineEdit(centralwidget);
        cpsEdit->setObjectName("cpsEdit");
        cpsEdit->setGeometry(QRect(430, 50, 41, 31));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(470, 55, 31, 21));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(0, 270, 161, 101));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(0, 20, 51, 21));
        funTimeOn = new QRadioButton(groupBox_2);
        funTimeOn->setObjectName("funTimeOn");
        funTimeOn->setGeometry(QRect(50, 70, 111, 22));
        funTimeOff = new QRadioButton(groupBox_2);
        funTimeOff->setObjectName("funTimeOff");
        funTimeOff->setGeometry(QRect(50, 50, 111, 22));
        verticalSlider = new QSlider(groupBox_2);
        verticalSlider->setObjectName("verticalSlider");
        verticalSlider->setGeometry(QRect(10, 40, 20, 51));
        verticalSlider->setMaximumSize(QSize(20, 51));
        verticalSlider->setOrientation(Qt::Orientation::Vertical);
        volumeAmount = new QLabel(groupBox_2);
        volumeAmount->setObjectName("volumeAmount");
        volumeAmount->setGeometry(QRect(50, 20, 21, 21));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(170, 269, 331, 101));
        vineBoomCheck = new QCheckBox(groupBox_3);
        vineBoomCheck->setObjectName("vineBoomCheck");
        vineBoomCheck->setGeometry(QRect(10, 30, 81, 22));
        costcoBoomCheck = new QCheckBox(groupBox_3);
        costcoBoomCheck->setObjectName("costcoBoomCheck");
        costcoBoomCheck->setGeometry(QRect(10, 60, 101, 22));
        smackCheck = new QCheckBox(groupBox_3);
        smackCheck->setObjectName("smackCheck");
        smackCheck->setGeometry(QRect(110, 30, 77, 22));
        superSmashCheck = new QCheckBox(groupBox_3);
        superSmashCheck->setObjectName("superSmashCheck");
        superSmashCheck->setGeometry(QRect(110, 60, 91, 22));
        powCheck = new QCheckBox(groupBox_3);
        powCheck->setObjectName("powCheck");
        powCheck->setGeometry(QRect(210, 30, 77, 22));
        wompCheck = new QCheckBox(groupBox_3);
        wompCheck->setObjectName("wompCheck");
        wompCheck->setGeometry(QRect(210, 60, 77, 22));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 500, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        toggleKeyButton->setText(QCoreApplication::translate("MainWindow", "Set toggle key", nullptr));
        clickTypeButton->setText(QCoreApplication::translate("MainWindow", "Left Click", nullptr));
        clickLocationGroup->setTitle(QCoreApplication::translate("MainWindow", "Click Location", nullptr));
        matchCursorSetting->setText(QCoreApplication::translate("MainWindow", "Match Cursor", nullptr));
        specificLocationSetting->setText(QCoreApplication::translate("MainWindow", "Specific Location", nullptr));
        chooseLocationButton->setText(QCoreApplication::translate("MainWindow", "Choose Location", nullptr));
        textBrowser_4->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">X:</p></body></html>", nullptr));
        xPosEdit->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        textBrowser_5->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Y:</p></body></html>", nullptr));
        yPosEdit->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Toggle Key:</p></body></html>", nullptr));
        textBrowser_2->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Click Type:</p></body></html>", nullptr));
        textBrowser_3->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:22pt; font-weight:700;\">THE FUN AUTOCLICKER</span></p></body></html>", nullptr));
        clickAmountBox->setTitle(QCoreApplication::translate("MainWindow", "Click Amount", nullptr));
        infiniteClickButton->setText(QCoreApplication::translate("MainWindow", "Infinite", nullptr));
        finiteClickButton->setText(QCoreApplication::translate("MainWindow", "Finite", nullptr));
        textBrowser_6->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Total Clicks:</p></body></html>", nullptr));
        totalClicksEdit->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Click Interval", nullptr));
        indefiniteTimeButton->setText(QCoreApplication::translate("MainWindow", "Click Indefinitely", nullptr));
        definiteTimeButton->setText(QCoreApplication::translate("MainWindow", "Click for this amount of time:", nullptr));
        hoursEdit->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Hours", nullptr));
        minutesEdit->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Minutes", nullptr));
        secondsEdit->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Seconds", nullptr));
        millisecondsEdit->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Milliseconds", nullptr));
        textBrowser_7->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Click Speed:</p></body></html>", nullptr));
        cpsEdit->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt;\">cps</span></p></body></html>", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Fun Time", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Volume:</p></body></html>", nullptr));
        funTimeOn->setText(QCoreApplication::translate("MainWindow", "Fun Time ON", nullptr));
        funTimeOff->setText(QCoreApplication::translate("MainWindow", "Fun Time OFF", nullptr));
        volumeAmount->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">0</p></body></html>", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Fun Time Sounds", nullptr));
        vineBoomCheck->setText(QCoreApplication::translate("MainWindow", "Vine Boom", nullptr));
        costcoBoomCheck->setText(QCoreApplication::translate("MainWindow", "Bam", nullptr));
        smackCheck->setText(QCoreApplication::translate("MainWindow", "Smack", nullptr));
        superSmashCheck->setText(QCoreApplication::translate("MainWindow", "Super Smash", nullptr));
        powCheck->setText(QCoreApplication::translate("MainWindow", "Pow", nullptr));
        wompCheck->setText(QCoreApplication::translate("MainWindow", "Womp", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
