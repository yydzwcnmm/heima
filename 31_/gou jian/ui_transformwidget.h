/********************************************************************************
** Form generated from reading UI file 'transformwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSFORMWIDGET_H
#define UI_TRANSFORMWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TransformWidget
{
public:
    QTabWidget *tabWidget;
    QWidget *tabUpload;
    QScrollArea *scrollArea;
    QWidget *upload_scroll;
    QWidget *tabDownload;
    QScrollArea *scrollArea_2;
    QWidget *download_scroll;
    QWidget *tabTransform;

    void setupUi(QWidget *TransformWidget)
    {
        if (TransformWidget->objectName().isEmpty())
            TransformWidget->setObjectName(QString::fromUtf8("TransformWidget"));
        TransformWidget->resize(800, 500);
        tabWidget = new QTabWidget(TransformWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(30, 30, 760, 450));
        tabUpload = new QWidget();
        tabUpload->setObjectName(QString::fromUtf8("tabUpload"));
        scrollArea = new QScrollArea(tabUpload);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(0, 0, 750, 420));
        scrollArea->setWidgetResizable(true);
        upload_scroll = new QWidget();
        upload_scroll->setObjectName(QString::fromUtf8("upload_scroll"));
        upload_scroll->setGeometry(QRect(0, 0, 748, 418));
        scrollArea->setWidget(upload_scroll);
        tabWidget->addTab(tabUpload, QString());
        tabDownload = new QWidget();
        tabDownload->setObjectName(QString::fromUtf8("tabDownload"));
        scrollArea_2 = new QScrollArea(tabDownload);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(0, 0, 750, 420));
        scrollArea_2->setWidgetResizable(true);
        download_scroll = new QWidget();
        download_scroll->setObjectName(QString::fromUtf8("download_scroll"));
        download_scroll->setGeometry(QRect(0, 0, 748, 418));
        scrollArea_2->setWidget(download_scroll);
        tabWidget->addTab(tabDownload, QString());
        tabTransform = new QWidget();
        tabTransform->setObjectName(QString::fromUtf8("tabTransform"));
        tabWidget->addTab(tabTransform, QString());

        retranslateUi(TransformWidget);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(TransformWidget);
    } // setupUi

    void retranslateUi(QWidget *TransformWidget)
    {
        TransformWidget->setWindowTitle(QCoreApplication::translate("TransformWidget", "Form", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabUpload), QCoreApplication::translate("TransformWidget", "\344\270\212\344\274\240\345\210\227\350\241\250", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabDownload), QCoreApplication::translate("TransformWidget", "\344\270\213\350\275\275\345\210\227\350\241\250", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabTransform), QCoreApplication::translate("TransformWidget", "\344\274\240\350\276\223\350\256\260\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TransformWidget: public Ui_TransformWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSFORMWIDGET_H
