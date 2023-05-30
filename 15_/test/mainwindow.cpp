#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
       QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
     db.setHostName("localhost");
     db.setPort(3306);
     db.setDatabaseName("mysql");
     db.setUserName("root");
     db.setPassword("tarena");
     bool ok = db.open();
     if (ok){
         QMessageBox::information(this, "infor", "success");
     }
     else {
         QMessageBox::information(this, "infor", "open failed");
     }



}

MainWindow::~MainWindow()
{
    delete ui;
}

