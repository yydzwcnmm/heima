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

struct FileInfo
{
    QString user;           //用户名
    QString md5;            //md5
    QString createTime;     //上传时间
    QString fileName;       //文件名称
    int shareStatus;        //共享状态, 0为没有共享， 1为共享
    int pv;                 //文件下载量，下载一次加1
    QString url;            //文件url
    int size;               //文件大小
    QString type;           //文件类型

};


class NetworkData : public QObject
{
    Q_OBJECT


public:
    explicit NetworkData(QObject *parent = nullptr);



public:
    //static FileInfo* fileInfo;
    static QStringList getFileCount(QByteArray json);
    static QList<FileInfo*> getFileInfo(QByteArray json);
signals:


};

#endif // NETWORKDATA_H
