#ifndef WEATHERMONITORAPP_H
#define WEATHERMONITORAPP_H

#include <QApplication>
#include <QtSql>

#include "ControllerCities.h"

class WeatherMonitorApp : public QApplication
{
    Q_OBJECT

public:
    WeatherMonitorApp(int &argc, char *argv[]);
    ~WeatherMonitorApp();

private:

    QSqlTableModel   *modelCities;
    ControllerCities *controllerCities;


private:
    int createDbTables();

public:
    int init();
    int done();

    QSqlTableModel   *getModelCities();
    ControllerCities *getControllerCities();
};

#endif // WEATHERMONITORAPP_H
