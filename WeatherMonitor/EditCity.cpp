#include <QMessageBox>

#include "WeatherMonitorApp.h"
#include "EditCity.h"

EditCity::EditCity(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);

    edit = false;

    ctrl = qobject_cast<WeatherMonitorApp *>(qApp)->getControllerCities();
}

EditCity::EditCity(QWidget *parent, QString name, QString data, int index)
    : QDialog(parent)
{
    ui.setupUi(this);

    edit = true;
    this->index = index;

    ui.edtName->setText(name);
    ui.edtData->setText(data);

    ctrl = qobject_cast<WeatherMonitorApp *>(qApp)->getControllerCities();
}

EditCity::~EditCity()
{

}

void EditCity::onBtnOk()
{
    QString cityName = ui.edtName->text();
    QString cityData = ui.edtData->text();

    if (cityName.length() == 0)
    {
        QMessageBox msg;
        msg.setText("Введите название города");
        msg.exec();
        return;
    }

    if (cityData.length() == 0)
    {
        QMessageBox msg;
        msg.setText("Введите данные");
        msg.exec();
        return;
    }

    if (edit == true)
        ctrl->updateCity(cityName, cityData, index);
    else
        ctrl->addCity(cityName, cityData);

    close();
}
