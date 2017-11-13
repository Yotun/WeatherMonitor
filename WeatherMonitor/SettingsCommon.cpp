#include <QtSql>

#include "SettingsCommon.h"
#include "WeatherMonitorApp.h"

SettingsCommon::SettingsCommon(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);

    // TODO: переделать на модель
    QSqlQuery queryChangeCity("SELECT setting_name, setting_value FROM settings WHERE setting_name LIKE 'change_city';");
    queryChangeCity.next();
    QString changeCity = queryChangeCity.value(1).toString();

    ui.edtChangeCity->setText(changeCity);

    QSqlQuery queryUpdatePeriod("SELECT setting_name, setting_value FROM settings WHERE setting_name LIKE 'update_period';");
    queryUpdatePeriod.next();
    QString updatePeriod = queryUpdatePeriod.value(1).toString();

    ui.edtChangeCity->setText(changeCity);
    ui.edtUpdatePeriod->setText(updatePeriod);

    WeatherMonitorApp *app = qobject_cast<WeatherMonitorApp *>(qApp);
    connect(this, SIGNAL(changedSettings()), app, SLOT(onApplySettings()));
}

SettingsCommon::~SettingsCommon()
{

}

void SettingsCommon::onBtnOk()
{
    // TODO: переделать на модель
    QSqlQuery query;
    query.prepare("UPDATE settings SET setting_value = :change_city WHERE setting_name LIKE 'change_city';");
    query.bindValue(":change_city", ui.edtChangeCity->text());
    query.exec();
    query.prepare("UPDATE settings SET setting_value = :update_period WHERE setting_name LIKE 'update_period';");
    query.bindValue(":update_period", ui.edtUpdatePeriod->text());
    query.exec();
    emit changedSettings();
    accept();
}
