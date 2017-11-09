#ifndef CONTROLLERCITIES_H
#define CONTROLLERCITIES_H

#include <QObject>
#include <QSqlTableModel>

class ControllerCities : public QObject
{
    Q_OBJECT

public:
    ControllerCities(QObject *parent, QSqlTableModel *model);
    ~ControllerCities();

    int addCity(QString name, QString data);
    int updateCity(QString name, QString data, int index);
    int deleteCity(int index);

private:
    QSqlTableModel *model;
    
};

#endif // CONTROLLERCITIES_H
