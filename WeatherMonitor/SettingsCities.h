#ifndef SETTINGSCITIES_H
#define SETTINGSCITIES_H

#include <QDialog>
#include "ui_SettingsCities.h"

class SettingsCities : public QDialog
{
    Q_OBJECT

public:
    SettingsCities(QWidget *parent = 0);
    ~SettingsCities();

private:
    Ui::SettingsCities ui;
};

#endif // SETTINGSCITIES_H
