#ifndef WEATHERMONITORAPP_H
#define WEATHERMONITORAPP_H

#include <QApplication>
#include <QtSql>

#include "ControllerCities.h"
#include "Updater.h"

class WeatherMonitorApp : public QApplication
{
    Q_OBJECT

public:
    WeatherMonitorApp(int &argc, char *argv[]);
    ~WeatherMonitorApp();

private:

    QSqlTableModel   *modelCities;
    ControllerCities *controllerCities;
    Updater          *updater;

    QThread workerThread;

    QTimer *timer;

private:
    int createDbTables();

public:
    int init();
    int done();

    QSqlTableModel   *getModelCities();
    ControllerCities *getControllerCities();

public slots:
    void updatePending();
    void onApplySettings();

};

#endif // WEATHERMONITORAPP_H
