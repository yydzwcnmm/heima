/********************************************************************************
** Form generated from reading UI file 'myfilewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYFILEWIDGET_H
#define UI_MYFILEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyFileWidget
{
public:
    QVBoxLayout *vboxLayout;
    QListWidget *listWidget;

    void setupUi(QWidget *MyFileWidget)
    {
        if (MyFileWidget->objectName().isEmpty())
            MyFileWidget->setObjectName(QString::fromUtf8("MyFileWidget"));
        MyFileWidget->resize(800, 500);
        vboxLayout = new QVBoxLayout(MyFileWidget);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        listWidget = new QListWidget(MyFileWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        vboxLayout->addWidget(listWidget);


        retranslateUi(MyFileWidget);

        QMetaObject::connectSlotsByName(MyFileWidget);
    } // setupUi

    void retranslateUi(QWidget *MyFileWidget)
    {
        MyFileWidget->setWindowTitle(QCoreApplication::translate("MyFileWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyFileWidget: public Ui_MyFileWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYFILEWIDGET_H
