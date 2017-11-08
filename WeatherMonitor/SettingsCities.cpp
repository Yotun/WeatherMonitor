#include "SettingsCities.h"
#include "WeatherMonitorApp.h"
#include "EditCity.h"

SettingsCities::SettingsCities(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);

    QSqlTableModel *model = qobject_cast<WeatherMonitorApp *>(qApp)->getModelCities();

    ui.tableView->setModel(model);
    ui.tableView->hideColumn(0);
    ui.tableView->hideColumn(3);

    ctrl = qobject_cast<WeatherMonitorApp *>(qApp)->getControllerCities();
}

SettingsCities::~SettingsCities()
{

}

void SettingsCities::onBtnAddClick()
{
    EditCity dlg(this);
    dlg.exec();
}

void SettingsCities::onBtnEditClick()
{
    QModelIndexList sel = ui.tableView->selectionModel()->selectedIndexes();

    QModelIndex index;
    
    index = sel.at(1);
    QString name = index.data().toString();

    index = sel.at(3);
    QString data = index.data().toString();

    EditCity dlg(this, name, data, index.row());
    dlg.exec();
}

void SettingsCities::onBtnDelClick()
{
    QModelIndexList sel = ui.tableView->selectionModel()->selectedRows();
    QModelIndex index = sel.at(0);

    ctrl->deleteCity(index.row());
}
