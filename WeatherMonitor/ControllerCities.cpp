#include "ControllerCities.h"
#include <QSqlField>
#include <QSqlRecord>
#include <QVariant>

ControllerCities::ControllerCities(QObject *parent, QSqlTableModel *model)
    : QObject(parent)
{
    this->model = model;
}

ControllerCities::~ControllerCities()
{

}

int ControllerCities::addCity(QString name, QString data, int dataSource)
{
    QSqlField cityName("name", QVariant::String);
    cityName.setValue(name);

    QSqlField cityData("data", QVariant::String);
    cityData.setValue(data);

    QSqlField cityDataSource("datasource", QVariant::Int);
    cityDataSource.setValue(dataSource);

    QSqlRecord city;
    city.append(cityName);
    city.append(cityData);
    city.append(cityDataSource);

    bool err = model->insertRecord(-1, city);
    if (err == false)
        return -1;

    model->select();

    return 0;
}

int ControllerCities::updateCity(QString name, QString data, int dataSource, int index)
{
    QSqlField cityName("name", QVariant::String);
    cityName.setValue(name);

    QSqlField cityData("data", QVariant::String);
    cityData.setValue(data);

    QSqlField cityDataSource("datasource", QVariant::Int);
    cityDataSource.setValue(dataSource);

    QSqlRecord city;
    city.append(cityName);
    city.append(cityData);
    city.append(cityDataSource);

    bool err = model->setRecord(index, city);
    if (err == false)
        return -1;

    model->select();

    return 0;
}

int ControllerCities::deleteCity(int index)
{
    bool err = model->removeRow(index);
    if (err == false)
        return -1;

    model->select();

    return 0;
}

int ControllerCities::setTemperature(int temp, int index)
{
    QSqlField cityTemp("temperature", QVariant::Int);
    cityTemp.setValue(temp);

    QSqlRecord city;
    city.append(cityTemp);

    bool err = model->setRecord(index, city);
    if (err == false)
        return -1;

    return 0;
}