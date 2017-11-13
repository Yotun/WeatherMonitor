#include "DataSourceFactory.h"
#include "DataSource.h"
#include "OwmDataSource.h"
#include "FileDataSource.h"

DataSourceFactory::DataSourceFactory(QObject *parent)
    : QObject(parent)
{

}

DataSourceFactory::~DataSourceFactory()
{

}

DataSource * DataSourceFactory::getDataSource(int type)
{
    switch (type)
    {
    case DataSourceType::OpenWeatherMap:
        return new OwmDataSource(this);
    case DataSourceType::File:
        return new FileDataSource(this);
    default:
        break;
    }

    return nullptr;
}