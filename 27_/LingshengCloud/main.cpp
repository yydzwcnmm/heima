#include "mainwindow.h"
#include "logindialog.h"
//#include"titlewidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    LoginDialog lg;
    lg.show();
   // TitleWidget qw;
   // qw.show();
    return a.exec();
}
