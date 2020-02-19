#ifndef HTTPMANAGER_H
#define HTTPMANAGER_H

#include <QObject>
#include <QNetworkAccessManager>

class HTTPManager : public QObject
{
    Q_OBJECT
public:
    explicit HTTPManager(QObject *parent = nullptr);
    void sendImageRequest();

signals:

public slots:

private:
    QNetworkAccessManager *imageDownloadManager;

};

#endif // HTTPMANAGER_H
