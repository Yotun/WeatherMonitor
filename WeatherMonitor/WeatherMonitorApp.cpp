#include <QtSql>
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

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
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
        if (ret != 0)
        {
            qDebug() << "Error creating tables";
            return ret;
        }
    }

    modelCities = new QSqlTableModel(this, db);
    modelCities->setTable("cities");
    modelCities->select();
    modelCities->setHeaderData(1, Qt::Horizontal, "Название");
    modelCities->setHeaderData(2, Qt::Horizontal, "Температура");

    controllerCities = new ControllerCities(this, modelCities);

    return ret;
}

int WeatherMonitorApp::done()
{
    delete controllerCities;
    delete modelCities;

    QSqlDatabase db = QSqlDatabase::database();
    db.close();

    return 0;
}

int WeatherMonitorApp::createDbTables()
{
    QSqlQuery query;
    QString queryString = "CREATE TABLE settings (id INTEGER PRIMARY KEY,"
        " setting_name VARCHAR(64), setting_value VARCHAR(256));";
    bool err = query.exec(queryString);
    if (err == false)
        return -2;
    queryString = "CREATE TABLE cities (id INTEGER PRIMARY KEY,"
        " name VARCHAR(64), temperature INTEGER, data VARCHAR(1024));";
    err = query.exec(queryString);
    if (err == false)
        return -2;
    queryString = "INSERT INTO settings (setting_name, setting_value) VALUES ('version', '1'), ('change_city', '5');";
    err = query.exec(queryString);
    if (err == false)
        return -2;

    return 0;
}

QSqlTableModel * WeatherMonitorApp::getModelCities()
{
    return modelCities;
}

ControllerCities * WeatherMonitorApp::getControllerCities()
{
    return controllerCities;
}
