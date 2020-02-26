/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAdd_To_do_list;
    QAction *actionExit;
    QWidget *centralwidget;
    QLabel *ampm;
    QLabel *Greeting;
    QPushButton *ImageDownloadButton;
    QLabel *ImageLabel;
    QLineEdit *ZipcodeEdit;
    QPushButton *WeatherDownloadButton;
    QLabel *WeatherLabel;
    QLabel *WeatherIcon;
    QLabel *PhotoAlbum;
    QTableView *ToDoList;
    QLabel *Hours;
    QLabel *Colon;
    QLabel *Mins;
    QLabel *TaksHeader;
    QMenuBar *menubar;
    QMenu *menuTools;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1302, 1037);
        actionAdd_To_do_list = new QAction(MainWindow);
        actionAdd_To_do_list->setObjectName(QString::fromUtf8("actionAdd_To_do_list"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        ampm = new QLabel(centralwidget);
        ampm->setObjectName(QString::fromUtf8("ampm"));
        ampm->setGeometry(QRect(290, 140, 71, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Roboto Medium"));
        font.setPointSize(20);
        font.setBold(false);
        font.setWeight(50);
        ampm->setFont(font);
        Greeting = new QLabel(centralwidget);
        Greeting->setObjectName(QString::fromUtf8("Greeting"));
        Greeting->setGeometry(QRect(20, 30, 361, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Roboto Medium"));
        font1.setPointSize(23);
        font1.setBold(false);
        font1.setWeight(50);
        Greeting->setFont(font1);
        Greeting->setAlignment(Qt::AlignCenter);
        ImageDownloadButton = new QPushButton(centralwidget);
        ImageDownloadButton->setObjectName(QString::fromUtf8("ImageDownloadButton"));
        ImageDownloadButton->setGeometry(QRect(610, 430, 141, 51));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Roboto Medium"));
        font2.setBold(false);
        font2.setWeight(50);
        ImageDownloadButton->setFont(font2);
        ImageLabel = new QLabel(centralwidget);
        ImageLabel->setObjectName(QString::fromUtf8("ImageLabel"));
        ImageLabel->setGeometry(QRect(390, 20, 871, 391));
        ImageLabel->setFont(font2);
        ZipcodeEdit = new QLineEdit(centralwidget);
        ZipcodeEdit->setObjectName(QString::fromUtf8("ZipcodeEdit"));
        ZipcodeEdit->setGeometry(QRect(440, 430, 151, 31));
        ZipcodeEdit->setFont(font2);
        WeatherDownloadButton = new QPushButton(centralwidget);
        WeatherDownloadButton->setObjectName(QString::fromUtf8("WeatherDownloadButton"));
        WeatherDownloadButton->setGeometry(QRect(310, 430, 111, 41));
        WeatherDownloadButton->setFont(font2);
        WeatherLabel = new QLabel(centralwidget);
        WeatherLabel->setObjectName(QString::fromUtf8("WeatherLabel"));
        WeatherLabel->setGeometry(QRect(10, 360, 301, 111));
        WeatherLabel->setFont(font2);
        WeatherIcon = new QLabel(centralwidget);
        WeatherIcon->setObjectName(QString::fromUtf8("WeatherIcon"));
        WeatherIcon->setGeometry(QRect(170, 210, 261, 181));
        WeatherIcon->setFont(font2);
        PhotoAlbum = new QLabel(centralwidget);
        PhotoAlbum->setObjectName(QString::fromUtf8("PhotoAlbum"));
        PhotoAlbum->setGeometry(QRect(20, 560, 591, 391));
        PhotoAlbum->setFont(font2);
        ToDoList = new QTableView(centralwidget);
        ToDoList->setObjectName(QString::fromUtf8("ToDoList"));
        ToDoList->setGeometry(QRect(850, 530, 301, 431));
        ToDoList->setFont(font2);
        ToDoList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ToDoList->horizontalHeader()->setVisible(false);
        ToDoList->verticalHeader()->setVisible(false);
        Hours = new QLabel(centralwidget);
        Hours->setObjectName(QString::fromUtf8("Hours"));
        Hours->setGeometry(QRect(60, 100, 101, 81));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Roboto Medium"));
        font3.setPointSize(40);
        font3.setBold(false);
        font3.setWeight(50);
        Hours->setFont(font3);
        Colon = new QLabel(centralwidget);
        Colon->setObjectName(QString::fromUtf8("Colon"));
        Colon->setGeometry(QRect(160, 100, 31, 71));
        Colon->setFont(font3);
        Mins = new QLabel(centralwidget);
        Mins->setObjectName(QString::fromUtf8("Mins"));
        Mins->setGeometry(QRect(190, 100, 101, 81));
        Mins->setFont(font3);
        TaksHeader = new QLabel(centralwidget);
        TaksHeader->setObjectName(QString::fromUtf8("TaksHeader"));
        TaksHeader->setGeometry(QRect(810, 470, 361, 51));
        TaksHeader->setFont(font1);
        TaksHeader->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1302, 30));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuTools->menuAction());
        menuTools->addAction(actionAdd_To_do_list);
        menuTools->addSeparator();
        menuTools->addAction(actionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionAdd_To_do_list->setText(QApplication::translate("MainWindow", "Add To do list", nullptr));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        ampm->setText(QApplication::translate("MainWindow", "am", nullptr));
        Greeting->setText(QApplication::translate("MainWindow", "Hi!", nullptr));
        ImageDownloadButton->setText(QApplication::translate("MainWindow", "Download Map ", nullptr));
        ImageLabel->setText(QApplication::translate("MainWindow", "ImageLabel", nullptr));
        ZipcodeEdit->setText(QApplication::translate("MainWindow", "98113", nullptr));
        WeatherDownloadButton->setText(QApplication::translate("MainWindow", "Get Weather", nullptr));
        WeatherLabel->setText(QApplication::translate("MainWindow", "WeatherLabel", nullptr));
        WeatherIcon->setText(QApplication::translate("MainWindow", "WEATHER ICON", nullptr));
        PhotoAlbum->setText(QApplication::translate("MainWindow", "PhotoAlbum", nullptr));
        Hours->setText(QApplication::translate("MainWindow", "12", nullptr));
        Colon->setText(QApplication::translate("MainWindow", ":", nullptr));
        Mins->setText(QApplication::translate("MainWindow", "12", nullptr));
        TaksHeader->setText(QApplication::translate("MainWindow", "Tasks", nullptr));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
