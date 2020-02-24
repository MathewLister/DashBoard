#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include <QJsonObject>
#include <QFileDialog>

#include "httpmanager.h"
#include "todolistmodel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void setCurrentTime();
    void processImage(QPixmap *);
    void processWeatherJson(QJsonObject *json);
    void processAlbum(QPixmap *);

    void loadWeatherImages(QString current);

    void on_ImageDownloadButton_clicked();

    void on_WeatherDownloadButton_clicked();

    void on_actionAdd_To_do_list_triggered();

    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    HTTPManager *httpManager;
    todolistmodel *myModel;


    QPixmap clearIcon;
    QPixmap cloudIcon;
    QPixmap snowIcon;
    QPixmap rainIcon;
    QPixmap drizzleIcon;
    QPixmap thunderIcon;
};
#endif // MAINWINDOW_H
