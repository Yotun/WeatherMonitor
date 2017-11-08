#include "WeatherMonitor.h"
#include "WeatherMonitorApp.h"

int main(int argc, char *argv[])
{
    WeatherMonitorApp a(argc, argv);
    int err = a.init();
    if (err != 0)
        return err;

    WeatherMonitor w;
    w.show();

    int ret = a.exec();

    a.done();
    return ret;
}
