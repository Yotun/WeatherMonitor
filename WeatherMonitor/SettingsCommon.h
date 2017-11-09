#ifndef SETTINGSCOMMON_H
#define SETTINGSCOMMON_H

#include <QDialog>
#include "ui_SettingsCommon.h"

class SettingsCommon : public QDialog
{
    Q_OBJECT

public:
    SettingsCommon(QWidget *parent = 0);
    ~SettingsCommon();

private:
    Ui::SettingsCommon ui;

private slots:
    void onBtnOk();
};

#endif // SETTINGSCOMMON_H
