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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout_2;
    QLabel *labelMjpg;
    QGridLayout *gridLayout;
    QLabel *labelJpeg1;
    QLabel *labelJpeg2;
    QLabel *labelJpeg3;
    QLabel *labelJpeg4;
    QPushButton *btnGetMjpg;
    QPushButton *btnGetJpeg;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(663, 292);
        gridLayout_2 = new QGridLayout(Widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        labelMjpg = new QLabel(Widget);
        labelMjpg->setObjectName(QString::fromUtf8("labelMjpg"));
        labelMjpg->setFrameShape(QFrame::Box);
        labelMjpg->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(labelMjpg, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        labelJpeg1 = new QLabel(Widget);
        labelJpeg1->setObjectName(QString::fromUtf8("labelJpeg1"));
        labelJpeg1->setFrameShape(QFrame::Box);
        labelJpeg1->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(labelJpeg1, 0, 0, 1, 1);

        labelJpeg2 = new QLabel(Widget);
        labelJpeg2->setObjectName(QString::fromUtf8("labelJpeg2"));
        labelJpeg2->setFrameShape(QFrame::Box);
        labelJpeg2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(labelJpeg2, 0, 1, 1, 1);

        labelJpeg3 = new QLabel(Widget);
        labelJpeg3->setObjectName(QString::fromUtf8("labelJpeg3"));
        labelJpeg3->setFrameShape(QFrame::Box);
        labelJpeg3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(labelJpeg3, 1, 0, 1, 1);

        labelJpeg4 = new QLabel(Widget);
        labelJpeg4->setObjectName(QString::fromUtf8("labelJpeg4"));
        labelJpeg4->setFrameShape(QFrame::Box);
        labelJpeg4->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(labelJpeg4, 1, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 1, 1, 1);

        btnGetMjpg = new QPushButton(Widget);
        btnGetMjpg->setObjectName(QString::fromUtf8("btnGetMjpg"));

        gridLayout_2->addWidget(btnGetMjpg, 1, 0, 1, 1);

        btnGetJpeg = new QPushButton(Widget);
        btnGetJpeg->setObjectName(QString::fromUtf8("btnGetJpeg"));

        gridLayout_2->addWidget(btnGetJpeg, 1, 1, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\350\277\234\347\250\213\350\247\206\351\242\221\347\233\221\346\216\247\347\263\273\347\273\237", nullptr));
        labelMjpg->setText(QString());
        labelJpeg1->setText(QString());
        labelJpeg2->setText(QString());
        labelJpeg3->setText(QString());
        labelJpeg4->setText(QString());
        btnGetMjpg->setText(QCoreApplication::translate("Widget", "\350\216\267\345\217\226\350\247\206\351\242\221", nullptr));
        btnGetJpeg->setText(QCoreApplication::translate("Widget", "\350\216\267\345\217\226\345\277\253\347\205\247", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
