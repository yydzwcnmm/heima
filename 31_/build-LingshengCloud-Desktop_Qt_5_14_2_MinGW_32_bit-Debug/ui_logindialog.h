/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include <titlewidget.h>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QStackedWidget *stackedWidget;
    QWidget *login_page;
    QLabel *label;
    QWidget *widget_2;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *username;
    QLabel *label_3;
    QLineEdit *password;
    QWidget *widget_3;
    QWidget *widget_4;
    QPushButton *login;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QCheckBox *chk_remeber;
    QToolButton *notReg;
    QWidget *set_page;
    QWidget *widget;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLineEdit *server_ip;
    QLineEdit *server_port;
    QToolButton *set_ok;
    QWidget *reg_page;
    QWidget *widget_5;
    QLabel *label_4;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout_2;
    QLabel *label_5;
    QLineEdit *reg_username;
    QLabel *label_6;
    QLineEdit *reg_nickname;
    QLabel *label_7;
    QLineEdit *reg_pwd;
    QLabel *label_8;
    QLineEdit *reg_pwd2;
    QLabel *label_9;
    QLineEdit *reg_phone;
    QLabel *label_10;
    QLineEdit *reg_email;
    QToolButton *btn_reg;
    TitleWidget *title_widget;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QString::fromUtf8("LoginDialog"));
        LoginDialog->resize(650, 500);
        LoginDialog->setStyleSheet(QString::fromUtf8("background-color:rgb(85, 255, 255)"));
        stackedWidget = new QStackedWidget(LoginDialog);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(30, 50, 591, 431));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255)"));
        login_page = new QWidget();
        login_page->setObjectName(QString::fromUtf8("login_page"));
        label = new QLabel(login_page);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(230, 100, 121, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(16);
        font.setKerning(true);
        label->setFont(font);
        widget_2 = new QWidget(login_page);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(90, 150, 401, 91));
        layoutWidget = new QWidget(widget_2);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(80, 30, 224, 50));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        username = new QLineEdit(layoutWidget);
        username->setObjectName(QString::fromUtf8("username"));

        gridLayout->addWidget(username, 0, 1, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        password = new QLineEdit(layoutWidget);
        password->setObjectName(QString::fromUtf8("password"));
        password->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(password, 1, 1, 1, 1);

        widget_3 = new QWidget(login_page);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(160, 260, 311, 41));
        widget_4 = new QWidget(login_page);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setGeometry(QRect(190, 280, 201, 51));
        login = new QPushButton(widget_4);
        login->setObjectName(QString::fromUtf8("login"));
        login->setGeometry(QRect(60, 10, 81, 41));
        login->setStyleSheet(QString::fromUtf8("border-image: url(:/images/balckButton.png);\n"
"color: rgb(255, 255, 255);"));
        layoutWidget1 = new QWidget(login_page);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(150, 240, 282, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        chk_remeber = new QCheckBox(layoutWidget1);
        chk_remeber->setObjectName(QString::fromUtf8("chk_remeber"));

        horizontalLayout->addWidget(chk_remeber);

        notReg = new QToolButton(layoutWidget1);
        notReg->setObjectName(QString::fromUtf8("notReg"));
        notReg->setStyleSheet(QString::fromUtf8("color: rgb(230, 50, 14);\n"
"text-decoration: underline;\n"
"font: 10pt \"\351\273\221\344\275\223\";"));
        notReg->setAutoRaise(true);

        horizontalLayout->addWidget(notReg);

        stackedWidget->addWidget(login_page);
        set_page = new QWidget();
        set_page->setObjectName(QString::fromUtf8("set_page"));
        widget = new QWidget(set_page);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(70, 30, 441, 351));
        label_11 = new QLabel(widget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(70, 70, 285, 27));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(16);
        label_11->setFont(font1);
        label_11->setAlignment(Qt::AlignCenter);
        label_12 = new QLabel(widget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(84, 130, 90, 21));
        label_13 = new QLabel(widget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(84, 190, 90, 21));
        server_ip = new QLineEdit(widget);
        server_ip->setObjectName(QString::fromUtf8("server_ip"));
        server_ip->setGeometry(QRect(180, 130, 171, 21));
        server_ip->setMaximumSize(QSize(200, 16777215));
        server_port = new QLineEdit(widget);
        server_port->setObjectName(QString::fromUtf8("server_port"));
        server_port->setGeometry(QRect(180, 190, 171, 21));
        server_port->setMaximumSize(QSize(200, 16777215));
        set_ok = new QToolButton(widget);
        set_ok->setObjectName(QString::fromUtf8("set_ok"));
        set_ok->setGeometry(QRect(150, 250, 130, 35));
        set_ok->setMinimumSize(QSize(130, 35));
        set_ok->setMaximumSize(QSize(130, 35));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(12);
        set_ok->setFont(font2);
        set_ok->setStyleSheet(QString::fromUtf8("border-image: url(:/images/balckButton.png);\n"
"color: rgb(255, 255, 255);"));
        stackedWidget->addWidget(set_page);
        reg_page = new QWidget();
        reg_page->setObjectName(QString::fromUtf8("reg_page"));
        widget_5 = new QWidget(reg_page);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setGeometry(QRect(60, 20, 461, 361));
        label_4 = new QLabel(widget_5);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(100, 60, 260, 27));
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignCenter);
        layoutWidget2 = new QWidget(widget_5);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(110, 100, 261, 241));
        gridLayout_2 = new QGridLayout(layoutWidget2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 0, 0, 1, 1);

        reg_username = new QLineEdit(layoutWidget2);
        reg_username->setObjectName(QString::fromUtf8("reg_username"));
        reg_username->setMaximumSize(QSize(200, 16777215));

        gridLayout_2->addWidget(reg_username, 0, 2, 1, 1);

        label_6 = new QLabel(layoutWidget2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 1, 0, 1, 1);

        reg_nickname = new QLineEdit(layoutWidget2);
        reg_nickname->setObjectName(QString::fromUtf8("reg_nickname"));
        reg_nickname->setMaximumSize(QSize(200, 16777215));

        gridLayout_2->addWidget(reg_nickname, 1, 2, 1, 1);

        label_7 = new QLabel(layoutWidget2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 2, 0, 1, 1);

        reg_pwd = new QLineEdit(layoutWidget2);
        reg_pwd->setObjectName(QString::fromUtf8("reg_pwd"));
        reg_pwd->setMaximumSize(QSize(200, 16777215));
        reg_pwd->setEchoMode(QLineEdit::Password);

        gridLayout_2->addWidget(reg_pwd, 2, 2, 1, 1);

        label_8 = new QLabel(layoutWidget2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_2->addWidget(label_8, 3, 0, 1, 2);

        reg_pwd2 = new QLineEdit(layoutWidget2);
        reg_pwd2->setObjectName(QString::fromUtf8("reg_pwd2"));
        reg_pwd2->setMaximumSize(QSize(200, 16777215));
        reg_pwd2->setEchoMode(QLineEdit::Password);

        gridLayout_2->addWidget(reg_pwd2, 3, 2, 1, 1);

        label_9 = new QLabel(layoutWidget2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_2->addWidget(label_9, 4, 0, 1, 1);

        reg_phone = new QLineEdit(layoutWidget2);
        reg_phone->setObjectName(QString::fromUtf8("reg_phone"));
        reg_phone->setMaximumSize(QSize(200, 16777215));

        gridLayout_2->addWidget(reg_phone, 4, 2, 1, 1);

        label_10 = new QLabel(layoutWidget2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_2->addWidget(label_10, 5, 0, 1, 1);

        reg_email = new QLineEdit(layoutWidget2);
        reg_email->setObjectName(QString::fromUtf8("reg_email"));
        reg_email->setMaximumSize(QSize(200, 16777215));

        gridLayout_2->addWidget(reg_email, 5, 2, 1, 1);

        btn_reg = new QToolButton(layoutWidget2);
        btn_reg->setObjectName(QString::fromUtf8("btn_reg"));
        btn_reg->setMinimumSize(QSize(150, 35));
        btn_reg->setFont(font2);
        btn_reg->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border-image: url(:/images/balckButton.png);"));

        gridLayout_2->addWidget(btn_reg, 6, 1, 1, 2);

        stackedWidget->addWidget(reg_page);
        title_widget = new TitleWidget(LoginDialog);
        title_widget->setObjectName(QString::fromUtf8("title_widget"));
        title_widget->setGeometry(QRect(10, 10, 611, 41));

        retranslateUi(LoginDialog);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QCoreApplication::translate("LoginDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("LoginDialog", "\347\224\250\346\210\267\347\231\273\345\275\225", nullptr));
        label_2->setText(QCoreApplication::translate("LoginDialog", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_3->setText(QCoreApplication::translate("LoginDialog", "\345\257\206\347\240\201", nullptr));
        login->setText(QCoreApplication::translate("LoginDialog", "\347\231\273\345\275\225", nullptr));
        chk_remeber->setText(QCoreApplication::translate("LoginDialog", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
        notReg->setText(QCoreApplication::translate("LoginDialog", "\346\262\241\346\234\211\350\264\246\345\217\267\357\274\214\347\253\213\345\215\263\346\263\250\345\206\214", nullptr));
        label_11->setText(QCoreApplication::translate("LoginDialog", "\346\234\215\345\212\241\345\231\250\350\256\276\347\275\256", nullptr));
        label_12->setText(QCoreApplication::translate("LoginDialog", "\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200\357\274\232", nullptr));
        label_13->setText(QCoreApplication::translate("LoginDialog", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243\357\274\232", nullptr));
        set_ok->setText(QCoreApplication::translate("LoginDialog", "\347\241\256\345\256\232", nullptr));
        label_4->setText(QCoreApplication::translate("LoginDialog", "\347\224\250\346\210\267\346\263\250\345\206\214", nullptr));
        label_5->setText(QCoreApplication::translate("LoginDialog", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_6->setText(QCoreApplication::translate("LoginDialog", "\346\230\265\347\247\260", nullptr));
        label_7->setText(QCoreApplication::translate("LoginDialog", "\345\257\206\347\240\201", nullptr));
        label_8->setText(QCoreApplication::translate("LoginDialog", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        label_9->setText(QCoreApplication::translate("LoginDialog", "\346\211\213\346\234\272", nullptr));
        label_10->setText(QCoreApplication::translate("LoginDialog", "\351\202\256\347\256\261", nullptr));
        btn_reg->setText(QCoreApplication::translate("LoginDialog", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
