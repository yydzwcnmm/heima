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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QGroupBox *groupBox;
    QLineEdit *editURL;
    QPushButton *btnDownload;
    QGroupBox *groupBox_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QProgressBar *progressBar;
    QCheckBox *checkBox;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *editSavePath;
    QPushButton *btnDefaultPath;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 50, 54, 12));
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 20, 751, 81));
        editURL = new QLineEdit(groupBox);
        editURL->setObjectName(QString::fromUtf8("editURL"));
        editURL->setGeometry(QRect(71, 31, 571, 22));
        btnDownload = new QPushButton(groupBox);
        btnDownload->setObjectName(QString::fromUtf8("btnDownload"));
        btnDownload->setGeometry(QRect(660, 30, 80, 20));
        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 130, 751, 111));
        widget = new QWidget(groupBox_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 60, 721, 22));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        progressBar = new QProgressBar(widget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        horizontalLayout->addWidget(progressBar);

        checkBox = new QCheckBox(widget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        horizontalLayout->addWidget(checkBox);

        widget1 = new QWidget(groupBox_2);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(10, 30, 731, 24));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        editSavePath = new QLineEdit(widget1);
        editSavePath->setObjectName(QString::fromUtf8("editSavePath"));

        horizontalLayout_2->addWidget(editSavePath);

        btnDefaultPath = new QPushButton(widget1);
        btnDefaultPath->setObjectName(QString::fromUtf8("btnDefaultPath"));

        horizontalLayout_2->addWidget(btnDefaultPath);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "url", nullptr));
        groupBox->setTitle(QString());
        btnDownload->setText(QCoreApplication::translate("Widget", "\344\270\213\350\275\275", nullptr));
        groupBox_2->setTitle(QString());
        label_3->setText(QCoreApplication::translate("Widget", "\346\226\207\344\273\266\344\270\213\350\275\275\350\277\233\345\272\246 ", nullptr));
        checkBox->setText(QCoreApplication::translate("Widget", "\345\256\214\346\210\220\345\220\216\346\211\223\345\274\200", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\344\270\213\350\275\275\346\226\207\344\273\266\344\277\235\345\255\230\350\267\257\345\276\204 ", nullptr));
        btnDefaultPath->setText(QCoreApplication::translate("Widget", "\347\274\272\347\234\201\350\267\257\345\276\204", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
