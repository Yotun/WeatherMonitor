#ifndef DATASOURCEFACTORY_H
#define DATASOURCEFACTORY_H

#include <QObject>

#include "DataSource.h"

class DataSourceFactory : public QObject
{
    Q_OBJECT

public:
    DataSourceFactory(QObject *parent);
    ~DataSourceFactory();

    DataSource * getDataSource(int type);

private:
    
};

#endif // DATASOURCEFACTORY_H
