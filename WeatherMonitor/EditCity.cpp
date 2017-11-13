#include <QMessageBox>

#include "WeatherMonitorApp.h"
#include "EditCity.h"

EditCity::EditCity(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);

    ui.cmbDataSource->insertItem(0, "OpenWeatherMap");
    ui.cmbDataSource->insertItem(1, "File");

    edit = false;

    ctrl = qobject_cast<WeatherMonitorApp *>(qApp)->getControllerCities();
}

EditCity::EditCity(QWidget *parent, QString name, QString data, int dataSource, int index)
    : QDialog(parent)
{
    ui.setupUi(this);

    ui.cmbDataSource->insertItem(0, "OpenWeatherMap");
    ui.cmbDataSource->insertItem(1, "File");

    edit = true;
    this->index = index;

    ui.edtName->setText(name);
    ui.edtData->setText(data);
    ui.cmbDataSource->setCurrentIndex(dataSource);

    ctrl = qobject_cast<WeatherMonitorApp *>(qApp)->getControllerCities();
}

EditCity::~EditCity()
{

}

void EditCity::onBtnOk()
{
    QString cityName = ui.edtName->text();
    QString cityData = ui.edtData->text();
    int cityDataSource = ui.cmbDataSource->currentIndex();

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
        ctrl->updateCity(cityName, cityData, cityDataSource, index);
    else
        ctrl->addCity(cityName, cityData, cityDataSource);

    close();
}
