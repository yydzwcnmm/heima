#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QPainter>
#include <QDebug>
#include <QRegExp>
#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include "common.h"
#include "logininfoinstance.h"
#include "mainwindow.h"

// 正则表达式
#define USER_REG        "^[a-zA-Z\\d_@#-\*]\{3,16\}$"
#define PASSWD_REG      "^[a-zA-Z\\d_@#-\*]\{6,18\}$"
#define PHONE_REG       "1\\d\{10\}"
#define EMAIL_REG       "^[a-zA-Z\\d\._-]\+@[a-zA-Z\\d_\.-]\+(\.[a-zA-Z0-9_-]\+)+$"
#define IP_REG          "((2[0-4]\\d|25[0-5]|[01]?\\d\\d?)\\.){3}(2[0-4]\\d|25[0-5]|[01]?\\d\\d?)"
#define PORT_REG        "^[1-9]$|(^[1-9][0-9]$)|(^[1-9][0-9][0-9]$)|(^[1-9][0-9][0-9][0-9]$)|(^[1-6][0-5][0-5][0-3][0-5]$)"


namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

private:
    Ui::LoginDialog *ui;
    Common *m_common;
    void readConf();
    void serverSet();
    LoginInfoInstance *loginInfo;
    void saveLoginInfoData(QString username, QString token, QString ip, QString port);

    MainWindow* m_mainwindow;

private slots:
    void onshowSetPage();
    void oncloseButton();
    void on_notReg_clicked();
    void on_login_clicked();
    void on_btn_reg_clicked();
    void on_set_ok_clicked();
};

#endif // LOGINDIALOG_H
