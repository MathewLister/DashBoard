#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , timer(new QTimer)
    , httpManager(new HTTPManager)
    , myModel(new todolistmodel(this))
{
    ui->setupUi(this);
    ui->ToDoList->setModel(myModel);
    myModel->openFile(":/tasksDefault.csv");
    connect(timer, SIGNAL(timeout()), this, SLOT(setCurrentTime()));
    setCurrentTime();
    timer->start(1000);

    connect(httpManager, SIGNAL(MapReady(QPixmap *)),
            this, SLOT(processImage(QPixmap *)));

    connect(httpManager, SIGNAL(WeatherJsonReady(QJsonObject *)),
            this, SLOT(processWeatherJson(QJsonObject *)));

    connect(httpManager, SIGNAL(AlbumReady(QPixmap *)),
            this, SLOT(processAlbum(QPixmap *)));

    httpManager->sendAlbumRequest();
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
    QString zeroH = ""; //Holds 0 for hours if need be
    QString zeroM = ""; //Hold 0 for mins if need be
    int twelveHour = hour.toInt();
    if (twelveHour > 12) {
        twelveHour = twelveHour - 12;
        hour = QString::number(twelveHour);
        ui->ampm->setText("pm");
    }

    //Takes care of keeping the clock in this format xx:xx
    //I do not wnat the font from qLCD so I will use qLabel and need to handle this edge case
    if (hour != "10" || hour != "11" || hour != "12")
        zeroH = "0";
    if (min == "1" || min == "2" || min == "3" || min == "4" || min == "5"
            || min == "6" || min == "7" || min == "8" || min == "9")
        zeroM = "0";

    ui->Hours->setText(zeroH + hour);
    ui->Mins->setText(zeroM + min);
}

void MainWindow::processImage(QPixmap *image)
{
    *image = image->scaled(ui->ImageLabel->size(), Qt::KeepAspectRatio);
            //scaled(ui->WeatherIcon->size(), Qt::KeepAspectRatio);
    ui->ImageLabel->setPixmap(*image);
}

void MainWindow::processWeatherJson(QJsonObject *json)
{
        qDebug() << "Json ready";
        QString weather = json->value("weather").toArray()[0].toObject()["main"].toString();
        QString weatherDesc = json->value("weather").toArray()[0].toObject()["description"].toString();
        double temp = json->value("main").toObject()["temp"].toDouble();
        double temp_min = json->value("main").toObject()["temp_min"].toDouble();
        double temp_max = json->value("main").toObject()["temp_max"].toDouble();

        qDebug() << weather;
        qDebug() << weatherDesc;
        qDebug() << temp;
        qDebug() << temp_min;
        qDebug() << temp_max;

        loadWeatherImages(weather);

        ui->WeatherLabel->setText("Current Weather: " + weather + ", temp: " + QString::number(temp));

        /*
         * {
         *    "coord": {"lon":-122.38,"lat":47.64},
         *    "weather":[{"id":803,"main":"Clouds","description":"broken clouds","icon":"04d"}],
         *    "base":"stations",
         *    "main":{"temp":288.38,"pressure":1015,"humidity":72,"temp_min":287.04,"temp_max":289.82},
         *    "visibility":16093,
         *    "wind":{"speed":2.22,"deg":329.191},
         *    "clouds":{"all":75},
         *    "dt":1558543054,
         *    "sys":{"type":1,"id":3417,"message":0.0113,"country":"US","sunrise":1558527857,"sunset":1558583303},
         *    "timezone":-25200,"id":420040214,"name":"Seattle","cod":200
         * }
         * */
}

void MainWindow::processAlbum(QPixmap *image)
{
    *image = image->scaled(ui->PhotoAlbum->size(), Qt::KeepAspectRatio);
    ui->PhotoAlbum->setPixmap(*image);
}

void MainWindow::loadWeatherImages(QString current)
{
        QString clearFileName(":/Images/sun.png");
        QString cloudFileName(":/Images/Cloudy.png");
        QString snowFileName(":/Images/Snow.png");
        QString rainFileName(":/Images/Rain.png");
        QString drizzleFileName(":/Images/Drizzle.png");
        QString thunderFileName(":/Images/Thunder.png");


        if(current == "Clear"){
            if(clearIcon.load(clearFileName)){
               qDebug() << "Image loaded successfully";
               clearIcon = clearIcon.scaled(ui->WeatherIcon->size(), Qt::KeepAspectRatio);

               ui->WeatherIcon->setPixmap(clearIcon);
            }
        }
        else if(current == "Clouds"){
            if(cloudIcon.load(cloudFileName)){
               qDebug() << "Image loaded successfully";
               cloudIcon = cloudIcon.scaled(ui->WeatherIcon->size(), Qt::KeepAspectRatio);
            }

            ui->WeatherIcon->setPixmap(cloudIcon);
        }
        else if(current == "Snow"){
            if(snowIcon.load(snowFileName)){
               qDebug() << "Image loaded successfully";
               snowIcon = snowIcon.scaled(ui->WeatherIcon->size(), Qt::KeepAspectRatio);
            }

            ui->WeatherIcon->setPixmap(snowIcon);
        }
        else if(current == "Rain"){
            if(rainIcon.load(rainFileName)){
               qDebug() << "Image loaded successfully";
               rainIcon = rainIcon.scaled(ui->WeatherIcon->size(), Qt::KeepAspectRatio);
            }

            ui->WeatherIcon->setPixmap(rainIcon);
        }
        else if(current == "Drizzle"){
            if(drizzleIcon.load(drizzleFileName)){
               qDebug() << "Image loaded successfully";
               drizzleIcon = drizzleIcon.scaled(ui->WeatherIcon->size(), Qt::KeepAspectRatio);
            }

            ui->WeatherIcon->setPixmap(drizzleIcon);
        }
        else if(current == "Thunderstorm"){
            if(thunderIcon.load(thunderFileName)){
               qDebug() << "Image loaded successfully";
               thunderIcon = thunderIcon.scaled(ui->WeatherIcon->size(), Qt::KeepAspectRatio);
            }

            ui->WeatherIcon->setPixmap(thunderIcon);
        }
}


void MainWindow::on_ImageDownloadButton_clicked()
{
    QString zip = ui->ZipcodeEdit->text();
    qDebug() << zip;
    httpManager->sendMapRequest(zip);
}

void MainWindow::on_WeatherDownloadButton_clicked()
{
    QString zip = ui->ZipcodeEdit->text();
    qDebug() << zip;
    httpManager->sendWeatherRequest(zip);
}

void MainWindow::on_actionAdd_To_do_list_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                   tr("Open Address Book"), "",
                                                   tr("Address Book (*.csv);;All Files (*)"));
    std::cout << fileName.toStdString() << std::endl;

    myModel->openFile(fileName);
}

void MainWindow::on_actionExit_triggered()
{
    close();
}
