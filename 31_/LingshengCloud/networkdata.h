#ifndef NETWORKDATA_H
#define NETWORKDATA_H

#include <QObject>
#include <QByteArray>
#include <QList>
#include <QString>
#include <QStringList>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QDebug>
#include "fileinfo.h"



class NetworkData : public QObject
{
    Q_OBJECT


public:
    explicit NetworkData(QObject *parent = nullptr);



public:
    //static FileInfo* fileInfo;
    static QStringList getFileCount(QByteArray json);
    static QList<FileInfo*> getFileInfo(QByteArray json);
    static QString getCode(QByteArray json);
    static int getCount(QByteArray json);
signals:


};

#endif // NETWORKDATA_H
