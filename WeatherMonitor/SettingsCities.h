#ifndef SETTINGSCITIES_H
#define SETTINGSCITIES_H

#include <QDialog>
#include "ui_SettingsCities.h"
#include "ControllerCities.h"

class SettingsCities : public QDialog
{
    Q_OBJECT

public:
    SettingsCities(QWidget *parent = 0);
    ~SettingsCities();

private slots:
    void onBtnAddClick();
    void onBtnDelClick();
    void onBtnEditClick();

private:
    Ui::SettingsCities ui;

    QSqlTableModel *model;
    ControllerCities *ctrl;
};

#endif // SETTINGSCITIES_H
