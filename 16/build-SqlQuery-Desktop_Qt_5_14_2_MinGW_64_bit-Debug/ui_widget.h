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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *editStuNo;
    QPushButton *btnInsert;
    QLabel *label_2;
    QLineEdit *editStuName;
    QPushButton *btnUpdate;
    QLabel *label_3;
    QLineEdit *editStuPhone;
    QPushButton *btnDelete;
    QLabel *label_4;
    QSpinBox *spinBoxCNo;
    QPushButton *btnSelect;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(278, 196);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        editStuNo = new QLineEdit(Widget);
        editStuNo->setObjectName(QString::fromUtf8("editStuNo"));

        gridLayout->addWidget(editStuNo, 0, 1, 1, 1);

        btnInsert = new QPushButton(Widget);
        btnInsert->setObjectName(QString::fromUtf8("btnInsert"));

        gridLayout->addWidget(btnInsert, 0, 2, 1, 1);

        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        editStuName = new QLineEdit(Widget);
        editStuName->setObjectName(QString::fromUtf8("editStuName"));

        gridLayout->addWidget(editStuName, 1, 1, 1, 1);

        btnUpdate = new QPushButton(Widget);
        btnUpdate->setObjectName(QString::fromUtf8("btnUpdate"));

        gridLayout->addWidget(btnUpdate, 1, 2, 1, 1);

        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        editStuPhone = new QLineEdit(Widget);
        editStuPhone->setObjectName(QString::fromUtf8("editStuPhone"));

        gridLayout->addWidget(editStuPhone, 2, 1, 1, 1);

        btnDelete = new QPushButton(Widget);
        btnDelete->setObjectName(QString::fromUtf8("btnDelete"));

        gridLayout->addWidget(btnDelete, 2, 2, 1, 1);

        label_4 = new QLabel(Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        spinBoxCNo = new QSpinBox(Widget);
        spinBoxCNo->setObjectName(QString::fromUtf8("spinBoxCNo"));
        spinBoxCNo->setMinimum(1);

        gridLayout->addWidget(spinBoxCNo, 3, 1, 1, 1);

        btnSelect = new QPushButton(Widget);
        btnSelect->setObjectName(QString::fromUtf8("btnSelect"));

        gridLayout->addWidget(btnSelect, 3, 2, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\345\255\246    \345\217\267 ", nullptr));
        btnInsert->setText(QCoreApplication::translate("Widget", "\346\217\222\345\205\245", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\345\247\223    \345\220\215", nullptr));
        btnUpdate->setText(QCoreApplication::translate("Widget", "\344\277\256\346\224\271", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\350\201\224\347\263\273\346\226\271\345\274\217", nullptr));
        btnDelete->setText(QCoreApplication::translate("Widget", "\345\210\240\351\231\244", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "\347\217\255    \345\217\267", nullptr));
        btnSelect->setText(QCoreApplication::translate("Widget", "\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
