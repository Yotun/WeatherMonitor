#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QEventLoop>
#include <QJsonDocument>
#include <QJsonObject>

#include "OwmDataSource.h"

OwmDataSource::OwmDataSource(QObject *parent)
{

}

OwmDataSource::~OwmDataSource()
{

}

int OwmDataSource::getTemperature(QString name, QString data)
{
    // ������ �������
    QString requestString = "http://api.openweathermap.org/data/2.5/weather?appid=e1b720106d8703cd61f456cdc032b489&units=metric&id=";

    requestString += data;

    // ������
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkReply *reply = manager->get(QNetworkRequest(QUrl(requestString)));

    // ������� ���������� ���������� ����������� ��������
    QEventLoop wait;
    connect(reply, SIGNAL(finished()), &wait, SLOT(quit()));
    wait.exec();

    // ������ json ������
    QJsonDocument json = QJsonDocument::fromJson(reply->readAll());
    QJsonObject   jsonRoot = json.object();

    QJsonObject main = jsonRoot["main"].toObject();

    // ������������ ����������� ������������ ������,��������� �� ������
    return main["temp"].toDouble();
}
