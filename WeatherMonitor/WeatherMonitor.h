#ifndef WEATHERMONITOR_H
#define WEATHERMONITOR_H

#include <QtWidgets/QMainWindow>
#include "ui_WeatherMonitor.h"

class WeatherMonitor : public QMainWindow
{
    Q_OBJECT

public:
    WeatherMonitor(QWidget *parent = 0);
    ~WeatherMonitor();

private:
    Ui::WeatherMonitorClass ui;

private slots:
    void on_openSettingsCommon();
    void on_openSettingsCities();
};

#endif // WEATHERMONITOR_H
