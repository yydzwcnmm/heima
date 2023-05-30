#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>

static bool createConn(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");   // 设置主机名或IP地址
    db.setUserName("root");        // 设置登录名
    db.setPassword("tarena");      // 设置密码
    db.setPort(3306);              // 设置端口号
    db.setDatabaseName("choose");  // 设置数据库名
    if(!db.open()){
        QMessageBox::critical(0,"error","打开数据库失败\n"+db.lastError().text());
        return false;
    }
    return true;
}

#endif // CONNECTION_H
