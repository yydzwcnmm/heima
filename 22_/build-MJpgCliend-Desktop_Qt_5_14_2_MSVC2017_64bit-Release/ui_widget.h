/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *labelMjpg;
    QPushButton *btnGetMjpg;
    QLabel *labelJpeg1;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(921, 581);
        labelMjpg = new QLabel(Widget);
        labelMjpg->setObjectName(QString::fromUtf8("labelMjpg"));
        labelMjpg->setGeometry(QRect(40, 40, 351, 341));
        labelMjpg->setFrameShape(QFrame::Box);
        labelMjpg->setFrameShadow(QFrame::Sunken);
        btnGetMjpg = new QPushButton(Widget);
        btnGetMjpg->setObjectName(QString::fromUtf8("btnGetMjpg"));
        btnGetMjpg->setGeometry(QRect(70, 400, 271, 28));
        labelJpeg1 = new QLabel(Widget);
        labelJpeg1->setObjectName(QString::fromUtf8("labelJpeg1"));
        labelJpeg1->setGeometry(QRect(550, 50, 301, 321));
        labelJpeg1->setFrameShape(QFrame::Box);
        labelJpeg1->setFrameShadow(QFrame::Sunken);
        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(120, 500, 631, 23));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        labelMjpg->setText(QString());
        btnGetMjpg->setText(QCoreApplication::translate("Widget", "\350\216\267\345\217\226\350\247\206\351\242\221", nullptr));
        labelJpeg1->setText(QString());
        label->setText(QCoreApplication::translate("Widget", "\346\234\215\345\212\241\345\231\250IP", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
