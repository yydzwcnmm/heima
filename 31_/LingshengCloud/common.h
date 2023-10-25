#ifndef COMMON_H
#define COMMON_H

#include <QString>
#include "des.h"
#include <QNetworkAccessManager>

// 正则表达式
#define USER_REG        "^[a-zA-Z\\d_@#-\*]\{3,16\}$"
#define PASSWD_REG      "^[a-zA-Z\\d_@#-\*]\{6,18\}$"
#define PHONE_REG       "1\\d\{10\}"
#define EMAIL_REG       "^[a-zA-Z\\d\._-]\+@[a-zA-Z\\d_\.-]\+(\.[a-zA-Z0-9_-]\+)+$"
#define IP_REG          "((2[0-4]\\d|25[0-5]|[01]?\\d\\d?)\\.){3}(2[0-4]\\d|25[0-5]|[01]?\\d\\d?)"
#define PORT_REG        "^[1-9]$|(^[1-9][0-9]$)|(^[1-9][0-9][0-9]$)|(^[1-9][0-9][0-9][0-9]$)|(^[1-6][0-5][0-5][0-3][0-5]$)"
#include <QDir>
//配置文件路径
#define CONF_FILE       "conf/cfg.json"

#define CONF_REMEBER_YES "yes"
#define CONF_REMEBER_NO  "no"

class Common
{
private:
    Common();
    static Common* m_instance;
    QNetworkAccessManager *m_manager;
public:
    static Common* getInstance();

    //读取文件数据
    QString getConfValue(QString title, QString key, QString path=CONF_FILE);

    //写入数据到文件
    void writeLoginInfo(QString user, QString pwd, bool isRemeber, QString path=CONF_FILE);

    // 服务器信息，写入配置文件
    void writeWebInfo(QString ip, QString port, QString path=CONF_FILE);

    //md5加密字符串
    QString getStrMd5(QString str);

    QNetworkAccessManager* getNetworkAccessManager();

};

#endif // COMMON_H
