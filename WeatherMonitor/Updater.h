#ifndef UPDATER_H
#define UPDATER_H

#include <QObject>

#include "ControllerCities.h"

class Updater : public QObject
{
    Q_OBJECT

public:
    Updater();
    ~Updater();

private:
    void init();
    void done();

private:
    QSqlTableModel   *modelCities;
    ControllerCities *controllerCities;

public slots :
    void doWork();

signals:
    void updateDone();
    
};

#endif // UPDATER_H
