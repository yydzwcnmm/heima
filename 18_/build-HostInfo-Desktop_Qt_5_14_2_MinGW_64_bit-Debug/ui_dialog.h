/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout;
    QPushButton *btnGetLocalHostInfo;
    QPushButton *btnAllAddresses;
    QCheckBox *ckbIPv4Only;
    QPushButton *btnAllInterfaces;
    QPushButton *mainHostInfo;
    QLineEdit *editDomainName;
    QPushButton *btnTextClear;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(468, 568);
        gridLayout = new QGridLayout(Dialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        btnGetLocalHostInfo = new QPushButton(Dialog);
        btnGetLocalHostInfo->setObjectName(QString::fromUtf8("btnGetLocalHostInfo"));

        gridLayout->addWidget(btnGetLocalHostInfo, 0, 0, 1, 1);

        btnAllAddresses = new QPushButton(Dialog);
        btnAllAddresses->setObjectName(QString::fromUtf8("btnAllAddresses"));

        gridLayout->addWidget(btnAllAddresses, 0, 1, 1, 1);

        ckbIPv4Only = new QCheckBox(Dialog);
        ckbIPv4Only->setObjectName(QString::fromUtf8("ckbIPv4Only"));

        gridLayout->addWidget(ckbIPv4Only, 1, 0, 1, 1);

        btnAllInterfaces = new QPushButton(Dialog);
        btnAllInterfaces->setObjectName(QString::fromUtf8("btnAllInterfaces"));

        gridLayout->addWidget(btnAllInterfaces, 1, 1, 1, 1);

        mainHostInfo = new QPushButton(Dialog);
        mainHostInfo->setObjectName(QString::fromUtf8("mainHostInfo"));

        gridLayout->addWidget(mainHostInfo, 2, 0, 1, 1);

        editDomainName = new QLineEdit(Dialog);
        editDomainName->setObjectName(QString::fromUtf8("editDomainName"));

        gridLayout->addWidget(editDomainName, 2, 1, 1, 1);

        btnTextClear = new QPushButton(Dialog);
        btnTextClear->setObjectName(QString::fromUtf8("btnTextClear"));

        gridLayout->addWidget(btnTextClear, 3, 1, 1, 1);

        plainTextEdit = new QPlainTextEdit(Dialog);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));

        gridLayout->addWidget(plainTextEdit, 4, 0, 1, 2);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        btnGetLocalHostInfo->setText(QCoreApplication::translate("Dialog", "\350\216\267\345\217\226\346\234\254\345\234\260\344\270\273\346\234\272\345\220\215\345\222\214IP\345\234\260\345\235\200", nullptr));
        btnAllAddresses->setText(QCoreApplication::translate("Dialog", "allAddresses", nullptr));
        ckbIPv4Only->setText(QCoreApplication::translate("Dialog", "\345\217\252\346\230\276\347\244\272IPv4 \345\215\217\350\256\256\345\234\260\345\235\200", nullptr));
        btnAllInterfaces->setText(QCoreApplication::translate("Dialog", "allInterfaces", nullptr));
        mainHostInfo->setText(QCoreApplication::translate("Dialog", " \346\237\245\346\211\276\345\237\237\345\220\215\347\232\204IP\345\234\260\345\235\200", nullptr));
        btnTextClear->setText(QCoreApplication::translate("Dialog", "\346\270\205\347\251\272\346\226\207\346\234\254\346\241\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
