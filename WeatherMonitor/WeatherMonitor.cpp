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

void WeatherMonitor::onOpenSettingsCommon()
{
    SettingsCommon dlg(this);
    dlg.exec();
}

void WeatherMonitor::onOpenSettingsCities()
{
    SettingsCities dlg(this);
    dlg.exec();
}
