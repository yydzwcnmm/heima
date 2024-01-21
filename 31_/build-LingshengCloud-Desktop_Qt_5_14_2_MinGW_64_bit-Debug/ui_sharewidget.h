/********************************************************************************
** Form generated from reading UI file 'sharewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHAREWIDGET_H
#define UI_SHAREWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShareWidget
{
public:
    QListWidget *listWidget;

    void setupUi(QWidget *ShareWidget)
    {
        if (ShareWidget->objectName().isEmpty())
            ShareWidget->setObjectName(QString::fromUtf8("ShareWidget"));
        ShareWidget->resize(800, 500);
        listWidget = new QListWidget(ShareWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(10, 20, 770, 470));

        retranslateUi(ShareWidget);

        QMetaObject::connectSlotsByName(ShareWidget);
    } // setupUi

    void retranslateUi(QWidget *ShareWidget)
    {
        ShareWidget->setWindowTitle(QCoreApplication::translate("ShareWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShareWidget: public Ui_ShareWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHAREWIDGET_H
