#include "httpmanager.h"

HTTPManager::HTTPManager(QObject *parent) :
    QObject(parent),
    timer(new QTimer),
    MapDownloadManager(new QNetworkAccessManager),
    weatherAPIManager(new QNetworkAccessManager),
    albumDownloadManager(new QNetworkAccessManager)
{
    connect(MapDownloadManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(MapDownloadedHandler(QNetworkReply*)));

    connect(weatherAPIManager, SIGNAL(finished(QNetworkReply*)),
                this, SLOT(WeatherDownloadedHandler(QNetworkReply*)));

    connect(albumDownloadManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(AlbumDownloadedHandler(QNetworkReply*)));

    connect(timer, SIGNAL(timeout()),
            this, SLOT(sendAlbumRequest()));

    timer->start(10000);
}

HTTPManager::~HTTPManager()
{
    delete MapDownloadManager;
    delete weatherAPIManager;
    delete albumDownloadManager;
}

void HTTPManager::sendMapRequest(QString zip)
{
    QNetworkRequest request;
    QString address = "https://dev.virtualearth.net/REST/V1/Imagery/Map/Road/"
            + zip
            + "/7?mapSize=400,200&mapLayer=TrafficFlow&format=png&key=FhQdjAWB1J8o8GlTzHJV~xpALs9aBGPV-zaqaSqCe9w~Am9NYh5zW-mnFBgsGFNSGgDX1Ex4UI-Y8typVQoH1VTjRTA-s-Jff7FCtAzhsMZo";
    request.setUrl(QUrl(address));
    MapDownloadManager->get(request);
    qDebug() << "Image request sent to address" << request.url();
}

void HTTPManager::sendWeatherRequest(QString zip)
{
    QNetworkRequest request;
    QString address = "https://api.openweathermap.org/data/2.5/weather?zip="
                      + zip
                      + ",us&units=imperial&appid=a748eb0705eab14adb2f03da49fae7d9";
    request.setUrl(QUrl(address));
    weatherAPIManager->get(request);
    qDebug() << "Weather request sent to address" << request.url();
}

void HTTPManager::sendAlbumRequest()
{
    QNetworkRequest request;
    QString address0 = "https://nssdc.gsfc.nasa.gov/image/planetary/mars/hst_mars_9927.jpg";
    QString address1 = "https://upload.wikimedia.org/wikipedia/commons/8/85/Venus_globe.jpg";
    QString address2 = "https://cdn.spacetelescope.org/archives/images/screen/opo0328a.jpg";
    QString address3 = "https://upload.wikimedia.org/wikipedia/commons/7/7b/Earth_Western_Hemisphere.jpg";
    QString address4 = "https://upload.wikimedia.org/wikipedia/commons/5/56/Neptune_Full.jpg";

    //Roll the album
    if(albumIndex == 4) //Restart the album
        albumIndex = 0;
    if(albumIndex == 0){
        request.setUrl(QUrl(address0));
        albumDownloadManager->get(request);
        qDebug() << "Image request sent to address" << request.url();
    }
    else if(albumIndex == 1){
        request.setUrl(QUrl(address1));
        albumDownloadManager->get(request);
        qDebug() << "Image request sent to address" << request.url();
    }
    else if(albumIndex == 2){
        request.setUrl(QUrl(address2));
        albumDownloadManager->get(request);
        qDebug() << "Image request sent to address" << request.url();
    }
    else if(albumIndex == 3){
        request.setUrl(QUrl(address3));
        albumDownloadManager->get(request);
        qDebug() << "Image request sent to address" << request.url();
    }
    else if(albumIndex == 4){
        request.setUrl(QUrl(address4));
        albumDownloadManager->get(request);
        qDebug() << "Image request sent to address" << request.url();
    }

    albumIndex++;
}


void HTTPManager::MapDownloadedHandler(QNetworkReply *reply)
{
    qDebug() << "Image reply has arrived";
    if(reply->error()) {
        qDebug() << reply->errorString();
        return;
    }

    qDebug() << "Download was successful";
    QPixmap *image = new QPixmap();
    image->loadFromData(reply->readAll());
    reply->deleteLater();

    emit MapReady(image);
}

void HTTPManager::WeatherDownloadedHandler(QNetworkReply *reply)
{
    qDebug() << "Weather reply has arrived";
    if(reply->error()) {
        qDebug() << reply->errorString();
        return;
    }

    qDebug() << "Download was successful";

    QString answer = reply->readAll();
    reply->deleteLater();

    QJsonDocument jsonRespnose = QJsonDocument::fromJson(answer.toUtf8());
    QJsonObject *jsonObj = new QJsonObject(jsonRespnose.object());

    emit WeatherJsonReady(jsonObj);
}

void HTTPManager::AlbumDownloadedHandler(QNetworkReply *reply)
{
    qDebug() << "Image reply has arrived";
    if(reply->error()) {
        qDebug() << reply->errorString();
        return;
    }

    qDebug() << "Download was successful";
    QPixmap *image = new QPixmap();
    image->loadFromData(reply->readAll());
    reply->deleteLater();

    emit AlbumReady(image);
}








