#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    CustomMoveWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint);      //去掉qt自带的标题栏
}

MainWindow::~MainWindow()
{
    delete ui;
}
