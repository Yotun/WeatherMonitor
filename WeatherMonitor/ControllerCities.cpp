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

int ControllerCities::addCity(QString name, QString data)
{
    QSqlField cityName("name", QVariant::String);
    cityName.setValue(name);

    QSqlField cityData("data", QVariant::String);
    cityData.setValue(data);

    QSqlRecord city;
    city.append(cityName);
    city.append(cityData);

    bool err = model->insertRecord(-1, city);
    if (err == false)
        return -1;

    model->select();

    return 0;
}

int ControllerCities::updateCity(QString name, QString data, int index)
{
    QSqlField cityName("name", QVariant::String);
    cityName.setValue(name);

    QSqlField cityData("data", QVariant::String);
    cityData.setValue(data);

    QSqlRecord city;
    city.append(cityName);
    city.append(cityData);

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
