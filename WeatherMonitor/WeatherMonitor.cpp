#include "WeatherMonitor.h"
#include "SettingsCommon.h"
#include "SettingsCities.h"
#include "WeatherMonitorApp.h"

WeatherMonitor::WeatherMonitor(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    model = qobject_cast<WeatherMonitorApp *>(qApp)->getModelCities();

    index = 0;
    onShowCity(index);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onBtnNextClick()));

    onApplySettings();
}

WeatherMonitor::~WeatherMonitor()
{

}

void WeatherMonitor::onOpenSettingsCommon()
{
    SettingsCommon dlg(this);
    int result = dlg.exec();
    if (result == QDialog::Accepted)
        onApplySettings();
}

void WeatherMonitor::onOpenSettingsCities()
{
    SettingsCities dlg(this);
    dlg.exec();
}

void WeatherMonitor::onShowCity(int index)
{
    QString name = model->record(index).value("name").toString();
    QString temp = model->record(index).value("temperature").toString() + " C";

    ui.labelName->setText(name);
    ui.labelTemp->setText(temp);
}

void WeatherMonitor::onBtnPrevClick()
{
    index--;
    if (index < 0)
        index = model->rowCount() - 1;
    onShowCity(index);
}

void WeatherMonitor::onBtnNextClick()
{
    index++;
    if (index > model->rowCount() - 1)
        index = 0;
    onShowCity(index);
}

void WeatherMonitor::onApplySettings()
{
    // TODO: переделать на модель
    QSqlQuery query("SELECT setting_name, setting_value FROM settings WHERE setting_name LIKE 'change_city';");
    query.next();
    int changeCity = query.value(1).toInt();

    timer->start(changeCity*1000);
}
