#ifndef JSON_READER_H
#define JSON_READER_H

#include <QCoreApplication>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QDebug>
#include <iostream>

using namespace std;

void jsonExample(QString filename){
    QFile file;
    QString val;
    file.setFileName(filename);
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    val = file.readAll();
    file.close();
    QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject jsonObject = d.object();
    qDebug()<< "Dimension:";
    qDebug()<< jsonObject.value(QStringLiteral("dimension")).toInt();

    QJsonObject artista = jsonObject["casillas"].toObject();
    QJsonArray jsonArray3 = artista["dobles"].toArray();
    QJsonArray jsonArray4 = artista["triples"].toArray();

    foreach (const QJsonValue & value, jsonArray3) {
        QJsonObject obj = value.toObject();
        QJsonArray arrayEvento = obj["dobles"].toArray();
        //nombre.append(artista["Name"].toString());
        qDebug()<< "Coordenada doble x y ";
        qDebug()<< obj.value(QStringLiteral("x")).toInt();
        qDebug()<< obj.value(QStringLiteral("y")).toInt();
    }
    foreach (const QJsonValue & value, jsonArray4) {
        QJsonObject obj = value.toObject();
        QJsonArray arrayEvento = obj["triples"].toArray();
        //nombre.append(artista["Name"].toString());
        qDebug()<< "Coordenada trple x y ";
        qDebug()<< obj.value(QStringLiteral("x")).toInt();
        qDebug()<< obj.value(QStringLiteral("y")).toInt();
    }
    QJsonArray jsonArray5 = jsonObject["diccionario"].toArray();
    qDebug()<< "DICCIONARIO";
    foreach (const QJsonValue & value, jsonArray5) {
        QJsonObject obj = value.toObject();
        QJsonObject palabra = obj["palabra"].toObject();
        //nombre.append(artista["Name"].toString());
        qDebug()<< "Palabra de diccionario";
        qDebug() << obj.value(QStringLiteral("palabra")).toString();\
    }

}


#endif // JSON_READER_H
