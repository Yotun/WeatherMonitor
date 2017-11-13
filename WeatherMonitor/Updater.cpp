#include <QtSql>

#include "Updater.h"
#include "DataSource.h"
#include "DataSourceFactory.h"
#include "OwmDataSource.h"
#include "FileDataSource.h"

Updater::Updater()
{
    
}

Updater::~Updater()
{

}

void Updater::doWork()
{
    init();

    DataSourceFactory dsFactory(this);

    int num = modelCities->rowCount();
    for (int i = 0; i < num; i++)
    {
        DataSource *ds = dsFactory.getDataSource(modelCities->record(i).value("datasource").toInt());
        int temperature = ds->getTemperature(modelCities->record(i).value("name").toString(),
            modelCities->record(i).value("data").toString());
        controllerCities->setTemperature(temperature, i);
        delete ds;
    }

    emit updateDone();

    done();
}

void Updater::init()
{
    QSqlDatabase db = QSqlDatabase::database();

    modelCities = new QSqlTableModel(this, db);
    modelCities->setTable("cities");
    modelCities->select();

    controllerCities = new ControllerCities(this, modelCities);
}

void Updater::done()
{
    delete controllerCities;
    delete modelCities;
}
