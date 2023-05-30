#include "mainwindow.h"

#include <QApplication>

#include <QtCore/QTextCodec>
#include <QtCore/QString>
#include <iostream>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QString str = "Hello";

    QTextCodec *code = QTextCodec::codecForName("UTF-8");
     QTextCodec::setCodecForLocale(code);

    // 获取系统的本地编解码器
       QTextCodec* codec = QTextCodec::codecForLocale();

        // 获取编解码器的名称和描述
        QString codecName = codec->name();
        QString codecDescription = codec->codecForUtfText(str.toUtf8())->name();

        std::cout << "System Locale Codec: " << codecName.toStdString() << std::endl;
        std::cout << "Codec Description: " << codecDescription.toStdString() << std::endl;

           // 输出字符串
          std::cout << str.toStdString() << std::endl;


        return 0;

    return a.exec();
}
