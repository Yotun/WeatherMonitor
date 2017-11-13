#ifndef OWMDATASOURCE_H
#define OWMDATASOURCE_H

#include "DataSource.h"

class OwmDataSource : public DataSource
{
    Q_OBJECT

public:
    OwmDataSource(QObject *parent);
    ~OwmDataSource();

    int getTemperature(QString name, QString data);

};

#endif // OWMDATASOURCE_H
