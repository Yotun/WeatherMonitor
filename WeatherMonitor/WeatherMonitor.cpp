#include "WeatherMonitor.h"
#include "SettingsCommon.h"
#include "SettingsCities.h"

WeatherMonitor::WeatherMonitor(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

WeatherMonitor::~WeatherMonitor()
{

}

void WeatherMonitor::on_openSettingsCommon()
{
    SettingsCommon dlg;
    dlg.exec();
}

void WeatherMonitor::on_openSettingsCities()
{
    SettingsCities dlg;
    dlg.exec();
}
