#ifndef EDITCITY_H
#define EDITCITY_H

#include <QDialog>
#include "ui_EditCity.h"
#include "ControllerCities.h"

class EditCity : public QDialog
{
    Q_OBJECT

public:
    EditCity(QWidget *parent);
    EditCity(QWidget *parent, QString name, QString data, int index);
    ~EditCity();

private:
    Ui::EditCity ui;

    bool edit;
    int index;

    ControllerCities *ctrl;

private slots:
    void onBtnOk();

};

#endif // EDITCITY_H
