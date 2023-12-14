#include "networkdata.h"

NetworkData::NetworkData(QObject *parent) : QObject(parent)
{

}

 QStringList NetworkData::getFileCount(QByteArray json)
 {
     QStringList list;
     QJsonParseError err;
     //解析返回数据
     QJsonDocument rootDoc = QJsonDocument::fromJson(json, &err);
     if (err.error != QJsonParseError::NoError) {
         qDebug() << "Json格式错误";
     } else {
         //解析json
         QJsonObject rootObj = rootDoc.object();
         QJsonValue codeValue = rootObj.value("code");

         /*
         {
             "num":	"1",
             "code":	"110"
         }
         */

         if (codeValue.type() == QJsonValue::String) {
             QString code = codeValue.toString();
             list.append(code);
         }
         QJsonValue numValue = rootObj.value("num");
         if (numValue.type() == QJsonValue::String) {
             QString num = numValue.toString();
             list.append(num);
         }
     }

     return list;
 }
 QList<FileInfo*> NetworkData::getFileInfo(QByteArray json)
 {
     qDebug() << "11111111111:";
     FileInfo* fileInfo = new FileInfo;
     QList<FileInfo*> list;
     QJsonParseError err;
     //解析返回数据
     QJsonDocument rootDoc = QJsonDocument::fromJson(json, &err);
     if (err.error != QJsonParseError::NoError) {
         qDebug() << "Json格式错误";
     }else {
         //解析json

         //解析json
         QJsonObject rootObj = rootDoc.object();
         QJsonValue filesValue = rootObj.value("files");
         if (filesValue.type() == QJsonValue::Array) {
             QJsonArray filesArr = filesValue.toArray();

             for (int i=0;i<filesArr.count();i++) {
                 QJsonValue fileValue = filesArr.at(i);
                 if (fileValue.type() == QJsonValue::Object) {
                     FileInfo *fileInfo = new FileInfo;

                     QJsonObject fileObj = fileValue.toObject();
                     QJsonValue userValue = fileObj.value("user");
                     QJsonValue md5Value = fileObj.value("md5");
                     QJsonValue createTimeValue = fileObj.value("create_time");
                     QJsonValue fileNameValue = fileObj.value("file_name");
                     QJsonValue shareStatus = fileObj.value("share_status");
                     QJsonValue pvValue = fileObj.value("pv");
                     QJsonValue urlValue = fileObj.value("url");
                     QJsonValue sizeValue = fileObj.value("size");
                     QJsonValue typeValue = fileObj.value("type");

                     fileInfo->user = userValue.toString();
                     fileInfo->md5 = md5Value.toString();
                     fileInfo->createTime = createTimeValue.toString();
                     fileInfo->fileName = fileNameValue.toString();
                     fileInfo->shareStatus = shareStatus.toInt();
                     fileInfo->pv = pvValue.toInt();
                     fileInfo->url = urlValue.toString();
                     fileInfo->size = sizeValue.toInt();
                     fileInfo->type = typeValue.toString();

                     list.append(fileInfo);
                }
             }
         }

     }

     //fileInfo->deleteLater();
     free(fileInfo);
     fileInfo=nullptr;
     qDebug() << "11111111111:";
     return list;
 }
 QString NetworkData::getCode(QByteArray json)
 {
     QString code;
     QJsonParseError err;
     //解析返回数据
     QJsonDocument rootDoc = QJsonDocument::fromJson(json,&err);
     if(err.error != QJsonParseError::NoError){
         qDebug() << "Json格式错误";
     }else {
         //解析json
         QJsonObject rootObj = rootDoc.object();
         QJsonValue codeValue = rootObj.value("code");
         code = codeValue.toString();
     }
     return code;
 }
