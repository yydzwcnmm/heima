#include "logindialog.h"
#include "ui_logindialog.h"
#include <QPainter>
#include <QDebug>
#include <QRegExp>


LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    //去掉标题栏
    this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    //如果设置了样式表，则不生效
    //this->setFont可以设置当前窗口所有的字体，loginDialog窗口中的所有控件都生效

    this->setFont(QFont("楷体", 12, QFont::Bold, false));

    QObject::connect(ui->title_widget, &TitleWidget::showSetPage, this, &LoginDialog::onshowSetPage);
    QObject::connect(ui->title_widget, &TitleWidget::closeButton, this, &LoginDialog::oncloseButton);


}

void LoginDialog::onshowSetPage()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void LoginDialog::oncloseButton()
{
    if(ui->stackedWidget->currentIndex() == 0){
        this->close();
    }else {
        ui->stackedWidget->setCurrentIndex(0);
   }

}


LoginDialog::~LoginDialog()
{
    delete ui;
}


void LoginDialog::on_notReg_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void LoginDialog::on_login_clicked()
{
    QString username = ui->username->text();
    QString password = ui->password->text();
    QRegExp regexp(USER_REG );
    if(!regexp.exactMatch(username)){
       //校验失败
        QMessageBox::warning(this,"警告", "用户名格式不正确");
        ui->username->clear();
        ui->username->setFocus();
        return;
    }
    regexp.setPattern(PASSWD_REG);
    if(!regexp.exactMatch(password)){
        //校验失败
        QMessageBox::warning(this,"警告", "密码格式不正确");
        ui->password->clear();
        ui->password->setFocus();
        return;
    }
    QMessageBox::information(this, "提示", "用户名和密码格式正确");
}
