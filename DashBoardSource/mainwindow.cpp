#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , timer(new QTimer)
{
    ui->setupUi(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(setCurrentTime()));
    setCurrentTime();
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setCurrentTime()
{
    QTime time = QTime::currentTime();
    QString hour = time.toString("hh");
    QString min = time.toString("mm");

    //Good evening!
    if(hour.toInt() == 17 || hour.toInt() <= 24) {
        ui->Greeting->setText("Good evening!");
    }

    //Good afternoon!
    if(hour.toInt() == 12 || hour.toInt() <= 16) {
        ui->Greeting->setText("Good afternoon!");
    }

    //Good morning!
    if(hour.toInt() == 7 || hour.toInt() <= 11) {
        ui->Greeting->setText("Good morning!");
    }

    //Go to bed!
    if(hour.toInt() == 0 || hour.toInt() <= 6) {
        ui->Greeting->setText("Go to bed!");
    }

    //Make the clock 12 hrs instead of 24
    int twelveHour = hour.toInt();
    if (twelveHour > 12) {
        twelveHour = twelveHour - 12;
        hour = QString::number(twelveHour);
        ui->ampm->setText("pm");
    }
    ui->Hours->display(hour);
    ui->Mins->display(min);
}

