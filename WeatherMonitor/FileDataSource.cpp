#include <QFile>
#include <QTextStream>

#include "FileDataSource.h"

FileDataSource::FileDataSource(QObject *parent)
{

}

FileDataSource::~FileDataSource()
{

}

int FileDataSource::getTemperature(QString name, QString data)
{
    int temp = -100;

    QFile file(data);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text) == false)
        return temp;

    QTextStream in(&file);
    in.setCodec("UTF-8");
    while (in.atEnd() == false) {
        QString line = in.readLine();
        QStringList sl = line.split(';');
        QString cityName = sl.at(0);
        if (cityName == name)
        {
            temp = sl.at(1).toInt();
            break;
        }
    }

    return temp;
}
