#include "weathermonitor.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WeatherMonitor w;
    w.show();
    return a.exec();
}
