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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *labelView;
    QPushButton *btnDetect;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(269, 209);
        labelView = new QLabel(Widget);
        labelView->setObjectName(QString::fromUtf8("labelView"));
        labelView->setGeometry(QRect(10, 10, 140, 185));
        labelView->setFrameShape(QFrame::Box);
        labelView->setFrameShadow(QFrame::Sunken);
        btnDetect = new QPushButton(Widget);
        btnDetect->setObjectName(QString::fromUtf8("btnDetect"));
        btnDetect->setGeometry(QRect(160, 166, 93, 28));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        labelView->setText(QString());
        btnDetect->setText(QCoreApplication::translate("Widget", "\350\257\206\345\210\253", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
