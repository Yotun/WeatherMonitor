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

    Updater *updater = new Updater;
    updater->moveToThread(&workerThread);
    connect(&workerThread, SIGNAL(finished()), updater, SLOT(deleteLater()));
    connect(updater, SIGNAL(updateDone()), this, SLOT(updatePending()));
    workerThread.start();

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), updater, SLOT(doWork()));
    onApplySettings();

    return ret;
}

int WeatherMonitorApp::done()
{
    delete timer;

    workerThread.quit();
    workerThread.wait();

    delete updater;

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
        " name VARCHAR(64), temperature INTEGER, data VARCHAR(1024), datasource INTEGER);";
    err = query.exec(queryString);
    if (err == false)
        return -2;
    queryString = "INSERT INTO settings (setting_name, setting_value) "
        "VALUES ('version', '1'), ('change_city', '5'), ('update_period', '10');";
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

void WeatherMonitorApp::updatePending()
{
    modelCities->select();
}

void WeatherMonitorApp::onApplySettings()
{
    // TODO: переделать на модель
    QSqlQuery query("SELECT setting_name, setting_value FROM settings WHERE setting_name LIKE 'update_period';");
    query.next();
    int updatePeriod = query.value(1).toInt();

    //timer->start(updatePeriod * 60 * 1000);
    timer->start(updatePeriod * 1000);

    return;
}
