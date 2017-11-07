#ifndef WEATHERMONITORAPP_H
#define WEATHERMONITORAPP_H

#include <QApplication>
#include <QtSql>

class WeatherMonitorApp : public QApplication
{
public:
    WeatherMonitorApp(int &argc, char *argv[]);
    ~WeatherMonitorApp();

    QSqlDatabase db;

private:
    int createDbTables();

public:
    int init();
    int clean();

};

#endif // WEATHERMONITORAPP_H
