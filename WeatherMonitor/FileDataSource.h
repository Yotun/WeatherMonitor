#ifndef FILEDATASOURCE_H
#define FILEDATASOURCE_H

#include "DataSource.h"

class FileDataSource : public DataSource
{
    Q_OBJECT

public:
    FileDataSource(QObject *parent);
    ~FileDataSource();

    int getTemperature(QString name, QString data);

private:
    
};

#endif // FILEDATASOURCE_H
