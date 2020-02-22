#include "httpmanager.h"

HTTPManager::HTTPManager(QObject *parent) :
    QObject(parent),
    imageDownloadManager(new QNetworkAccessManager),
    weatherAPIManager(new QNetworkAccessManager)
{
    connect(imageDownloadManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(ImageDownloadedHandler(QNetworkReply*)));

    connect(weatherAPIManager, SIGNAL(finished(QNetworkReply*)),
                this, SLOT(WeatherDownloadedHandler(QNetworkReply*)));
}

HTTPManager::~HTTPManager()
{
    delete imageDownloadManager;
    delete weatherAPIManager;
}

void HTTPManager::sendImageRequest(QString zip)
{
    QNetworkRequest request;
    QString address = "https://dev.virtualearth.net/REST/V1/Imagery/Map/Road/"
            + zip
            + "/7?mapSize=400,200&mapLayer=TrafficFlow&format=png&key=FhQdjAWB1J8o8GlTzHJV~xpALs9aBGPV-zaqaSqCe9w~Am9NYh5zW-mnFBgsGFNSGgDX1Ex4UI-Y8typVQoH1VTjRTA-s-Jff7FCtAzhsMZo";
    request.setUrl(QUrl(address));
    imageDownloadManager->get(request);
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

void HTTPManager::ImageDownloadedHandler(QNetworkReply *reply)
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

    emit ImageReady(image);
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
