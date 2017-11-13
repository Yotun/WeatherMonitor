#ifndef OWMDATASOURCE_H
#define OWMDATASOURCE_H

#include "DataSource.h"

class OwmDataSource : public DataSource
{
    Q_OBJECT

public:
    OwmDataSource(QObject *parent);
    ~OwmDataSource();

    int getTemperature(QString id);

private:
    
};

#endif // OWMDATASOURCE_H
