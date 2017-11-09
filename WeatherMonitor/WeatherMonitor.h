#ifndef WEATHERMONITOR_H
#define WEATHERMONITOR_H

#include <QtWidgets/QMainWindow>
#include <QSqlTableModel>
#include "ui_WeatherMonitor.h"

class WeatherMonitor : public QMainWindow
{
    Q_OBJECT

public:
    WeatherMonitor(QWidget *parent = 0);
    ~WeatherMonitor();

private:
    Ui::WeatherMonitorClass ui;

    QSqlTableModel *model;

    int index;

    QTimer *timer;

private slots:
    void onOpenSettingsCommon();
    void onOpenSettingsCities();
    void onShowCity(int index);
    void onBtnPrevClick();
    void onBtnNextClick();
    void onApplySettings();
};

#endif // WEATHERMONITOR_H
