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
    // Строка запроса
    QString requestString = "http://api.openweathermap.org/data/2.5/weather?appid=e1b720106d8703cd61f456cdc032b489&units=metric&id=";

    requestString += data;

    // Запрос
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkReply *reply = manager->get(QNetworkRequest(QUrl(requestString)));

    // Ожидаем завершения выполнения асинхронной операции
    QEventLoop wait;
    connect(reply, SIGNAL(finished()), &wait, SLOT(quit()));
    wait.exec();

    // Парсим json ответа
    QJsonDocument json = QJsonDocument::fromJson(reply->readAll());
    QJsonObject   jsonRoot = json.object();

    QJsonObject main = jsonRoot["main"].toObject();

    // Возвращается температура вещественным числом,округляем до целого
    return main["temp"].toDouble();
}
