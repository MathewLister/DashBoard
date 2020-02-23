#ifndef HTTPMANAGER_H
#define HTTPMANAGER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QPixmap>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTimer>

class HTTPManager : public QObject
{
    Q_OBJECT
public:
    explicit HTTPManager(QObject *parent = nullptr);
    ~HTTPManager();

    void sendMapRequest(QString zip);
    void sendWeatherRequest(QString zip);

signals:
    void MapReady(QPixmap *image);
    void WeatherJsonReady(QJsonObject *json);
    void AlbumReady(QPixmap *image);

public slots:
    void sendAlbumRequest();


private slots:
    void MapDownloadedHandler(QNetworkReply *reply);
    void WeatherDownloadedHandler(QNetworkReply *reply);
    void AlbumDownloadedHandler(QNetworkReply *reply);

private:
    QNetworkAccessManager *MapDownloadManager;
    QNetworkAccessManager *weatherAPIManager;
    QNetworkAccessManager *albumDownloadManager;
    QByteArray downloadedData;
    QTimer *timer;

    int albumIndex = 0;

};

#endif // HTTPMANAGER_H
