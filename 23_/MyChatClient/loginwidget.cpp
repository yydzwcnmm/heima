#include "loginwidget.h"
#include "ui_loginwidget.h"

LoginWidget::LoginWidget(QWidget *parent) :
   QWidget(parent),
    ui(new Ui::LoginWidget)
{
    ui->setupUi(this);
}

LoginWidget::~LoginWidget()
{
    delete ui;
}



void LoginWidget::on_btnWinMenu_clicked()
{

}

void LoginWidget::on_btnWinClose_clicked()
{

}
