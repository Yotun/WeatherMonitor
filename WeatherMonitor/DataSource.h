#ifndef DATASOURCE_H
#define DATASOURCE_H

#include <QObject>

enum DataSourceType { OpenWeatherMap = 0, File };

class DataSource : public QObject
{
public:
    DataSource();
    ~DataSource();

    virtual int getTemperature(QString id) = 0;

private:
    
};

#endif // DATASOURCE_H
