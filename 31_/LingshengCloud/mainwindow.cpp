#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //这段代码的作用是将当前窗口的标志设置为没有窗口边框和标题栏
     this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    ui->button_group->setParent(this);
    buttonsSignals();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setUser(QString user)
{
    ui->button_group->setUser(user);
}


void MainWindow::buttonsSignals()
{
    //默认设置myFile_page
    ui->stackedWidget->setCurrentWidget(ui->myFile_page);

    connect(ui->button_group,&ButtonGroup::sigMyFile,this,[=](){
            ui->stackedWidget->setCurrentWidget(ui->myFile_page);
    });

    connect(ui->button_group,&ButtonGroup::sigShare,this,[=](){
            ui->stackedWidget->setCurrentWidget(ui->share_page);
    });

    connect(ui->button_group,&ButtonGroup::sigDownload,this,[=](){
            ui->stackedWidget->setCurrentWidget(ui->download_page);
    });

    connect(ui->button_group,&ButtonGroup::sigTransform,this,[=](){
            ui->stackedWidget->setCurrentWidget(ui->transform_page);
    });

    //切换用户
    connect(ui->button_group,&ButtonGroup::sigSwitchUser,this,[=](){
            emit sigChangeUser();
    });


}
