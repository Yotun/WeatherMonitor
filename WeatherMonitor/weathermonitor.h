#ifndef WEATHERMONITOR_H
#define WEATHERMONITOR_H

#include <QtWidgets/QDialog>
#include "ui_weathermonitor.h"

class WeatherMonitor : public QDialog
{
    Q_OBJECT

public:
    WeatherMonitor(QWidget *parent = 0);
    ~WeatherMonitor();

private:
    Ui::WeatherMonitorClass ui;
};

#endif // WEATHERMONITOR_H
