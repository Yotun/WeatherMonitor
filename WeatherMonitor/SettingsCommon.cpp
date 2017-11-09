#include <QtSql>

#include "SettingsCommon.h"

SettingsCommon::SettingsCommon(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);

    // TODO: переделать на модель
    QSqlQuery query("SELECT setting_name, setting_value FROM settings WHERE setting_name LIKE 'change_city';");
    query.next();
    QString changeCity = query.value(1).toString();

    ui.edtChangeCity->setText(changeCity);
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
    accept();
}
