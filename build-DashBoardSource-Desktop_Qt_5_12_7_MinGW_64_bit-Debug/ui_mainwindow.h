/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLCDNumber *Hours;
    QLCDNumber *Mins;
    QLabel *ampm;
    QLabel *Greeting;
    QPushButton *ImageDownloadButton;
    QLabel *ImageLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1304, 763);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Hours = new QLCDNumber(centralwidget);
        Hours->setObjectName(QString::fromUtf8("Hours"));
        Hours->setGeometry(QRect(40, 100, 131, 101));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Serif"));
        Hours->setFont(font);
        Hours->setDigitCount(2);
        Hours->setProperty("value", QVariant(22.000000000000000));
        Mins = new QLCDNumber(centralwidget);
        Mins->setObjectName(QString::fromUtf8("Mins"));
        Mins->setGeometry(QRect(180, 100, 131, 101));
        Mins->setDigitCount(2);
        Mins->setProperty("value", QVariant(22.000000000000000));
        ampm = new QLabel(centralwidget);
        ampm->setObjectName(QString::fromUtf8("ampm"));
        ampm->setGeometry(QRect(320, 180, 69, 20));
        QFont font1;
        font1.setPointSize(10);
        ampm->setFont(font1);
        Greeting = new QLabel(centralwidget);
        Greeting->setObjectName(QString::fromUtf8("Greeting"));
        Greeting->setGeometry(QRect(50, 40, 251, 41));
        QFont font2;
        font2.setPointSize(12);
        Greeting->setFont(font2);
        ImageDownloadButton = new QPushButton(centralwidget);
        ImageDownloadButton->setObjectName(QString::fromUtf8("ImageDownloadButton"));
        ImageDownloadButton->setGeometry(QRect(60, 250, 191, 51));
        ImageLabel = new QLabel(centralwidget);
        ImageLabel->setObjectName(QString::fromUtf8("ImageLabel"));
        ImageLabel->setGeometry(QRect(70, 330, 781, 431));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1304, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        ampm->setText(QApplication::translate("MainWindow", "am", nullptr));
        Greeting->setText(QApplication::translate("MainWindow", "Hi!", nullptr));
        ImageDownloadButton->setText(QApplication::translate("MainWindow", "Image Downlad ", nullptr));
        ImageLabel->setText(QApplication::translate("MainWindow", "ImageLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
