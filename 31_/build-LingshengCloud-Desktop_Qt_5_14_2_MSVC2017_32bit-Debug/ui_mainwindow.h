/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>
#include <myfilewidget.h>
#include "buttongroup.h"
#include "sharewidget.h"
#include "transformwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    MyFileWidget *myFile_page;
    ShareWidget *share_page;
    QWidget *download_page;
    TransformWidget *transform_page;
    ButtonGroup *button_group;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 750);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 120, 801, 631));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        stackedWidget->setFrameShape(QFrame::NoFrame);
        myFile_page = new MyFileWidget();
        myFile_page->setObjectName(QString::fromUtf8("myFile_page"));
        myFile_page->setStyleSheet(QString::fromUtf8(""));
        stackedWidget->addWidget(myFile_page);
        share_page = new ShareWidget();
        share_page->setObjectName(QString::fromUtf8("share_page"));
        stackedWidget->addWidget(share_page);
        download_page = new QWidget();
        download_page->setObjectName(QString::fromUtf8("download_page"));
        stackedWidget->addWidget(download_page);
        transform_page = new TransformWidget();
        transform_page->setObjectName(QString::fromUtf8("transform_page"));
        stackedWidget->addWidget(transform_page);
        button_group = new ButtonGroup(centralwidget);
        button_group->setObjectName(QString::fromUtf8("button_group"));
        button_group->setGeometry(QRect(0, 0, 800, 120));
        button_group->setStyleSheet(QString::fromUtf8(""));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
