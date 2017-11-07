#include "WeatherMonitorApp.h"

WeatherMonitorApp::WeatherMonitorApp(int &argc, char *argv[])
    : QApplication(argc, argv)
{

}

WeatherMonitorApp::~WeatherMonitorApp()
{

}

int WeatherMonitorApp::init()
{
    int ret = 0;

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("WeatherMonitor.sqlite");

    bool err = db.open();
    if (err == false)
    {
        qDebug() << "Error opening database";
        return -1;
    }

    QSqlQuery query;
    QString queryString = "SELECT * FROM settings;";

    err = query.exec(queryString);
    if (err == false)
    {
        ret = createDbTables();
    }

    return ret;
}

int WeatherMonitorApp::clean()
{
    db.close();

    return 0;
}

int WeatherMonitorApp::createDbTables()
{
    QSqlQuery query;
    QString queryString = "CREATE TABLE settings (id INT PRIMARY KEY,"
        " setting_name VARCHAR(64), setting_value VARCHAR(256));";
    bool err = query.exec(queryString);
    if (err == false)
    {
        qDebug() << "Error creating tables";
        return -2;
    }
    queryString = "CREATE TABLE cities (id INT PRIMARY KEY,"
        " name VARCHAR(64), temp INTEGER, data VARCHAR(1024));";
    err = query.exec(queryString);
    if (err == false)
    {
        qDebug() << "Error creating tables";
        return -2;
    }
    queryString = "INSERT INTO settings (setting_name, setting_value) VALUES ('version', '1');";
    err = query.exec(queryString);
    if (err == false)
    {
        qDebug() << "Error creating tables";
        return -2;
    }

    return 0;
}
