#ifndef LOGININFOINSTANCE_H
#define LOGININFOINSTANCE_H


#include <QString>
#include <QObject>

//单例
class LoginInfoInstance
{

private:
    static LoginInfoInstance* m_instance;

public:
    LoginInfoInstance();
    static LoginInfoInstance* getInstance();

private:
    QString m_user;
    QString m_token;
    QString m_ip;
    QString m_port;

public:
    void setUser(QString user);
    void setToken(QString token);
    void setIp(QString ip);
    void setPort(QString port);

    QString user();
    QString token();
    QString ip();
    QString port();

};

#endif // LOGININFOINSTANCE_H
