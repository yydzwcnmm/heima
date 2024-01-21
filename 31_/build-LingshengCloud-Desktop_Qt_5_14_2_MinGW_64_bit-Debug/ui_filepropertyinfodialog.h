/********************************************************************************
** Form generated from reading UI file 'filepropertyinfodialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEPROPERTYINFODIALOG_H
#define UI_FILEPROPERTYINFODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FilePropertyInfoDialog
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *lbl_fileName;
    QLabel *val_fileName;
    QLabel *lbl_uploadUser;
    QLabel *val_uploadUser;
    QLabel *lbl_uploadTime;
    QLabel *val_uploadTime;
    QLabel *lbl_fileSize;
    QLabel *val_fileSize;
    QLabel *lbl_shareStatus;
    QLabel *val_shareStatus;
    QLabel *lbl_download;
    QLabel *val_download;
    QLabel *lbl_pv;
    QLabel *val_pv;

    void setupUi(QDialog *FilePropertyInfoDialog)
    {
        if (FilePropertyInfoDialog->objectName().isEmpty())
            FilePropertyInfoDialog->setObjectName(QString::fromUtf8("FilePropertyInfoDialog"));
        FilePropertyInfoDialog->resize(312, 335);
        widget = new QWidget(FilePropertyInfoDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 20, 281, 301));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lbl_fileName = new QLabel(widget);
        lbl_fileName->setObjectName(QString::fromUtf8("lbl_fileName"));

        gridLayout->addWidget(lbl_fileName, 0, 0, 1, 1);

        val_fileName = new QLabel(widget);
        val_fileName->setObjectName(QString::fromUtf8("val_fileName"));

        gridLayout->addWidget(val_fileName, 0, 1, 1, 1);

        lbl_uploadUser = new QLabel(widget);
        lbl_uploadUser->setObjectName(QString::fromUtf8("lbl_uploadUser"));

        gridLayout->addWidget(lbl_uploadUser, 1, 0, 1, 1);

        val_uploadUser = new QLabel(widget);
        val_uploadUser->setObjectName(QString::fromUtf8("val_uploadUser"));

        gridLayout->addWidget(val_uploadUser, 1, 1, 1, 1);

        lbl_uploadTime = new QLabel(widget);
        lbl_uploadTime->setObjectName(QString::fromUtf8("lbl_uploadTime"));

        gridLayout->addWidget(lbl_uploadTime, 2, 0, 1, 1);

        val_uploadTime = new QLabel(widget);
        val_uploadTime->setObjectName(QString::fromUtf8("val_uploadTime"));

        gridLayout->addWidget(val_uploadTime, 2, 1, 1, 1);

        lbl_fileSize = new QLabel(widget);
        lbl_fileSize->setObjectName(QString::fromUtf8("lbl_fileSize"));

        gridLayout->addWidget(lbl_fileSize, 3, 0, 1, 1);

        val_fileSize = new QLabel(widget);
        val_fileSize->setObjectName(QString::fromUtf8("val_fileSize"));

        gridLayout->addWidget(val_fileSize, 3, 1, 1, 1);

        lbl_shareStatus = new QLabel(widget);
        lbl_shareStatus->setObjectName(QString::fromUtf8("lbl_shareStatus"));

        gridLayout->addWidget(lbl_shareStatus, 4, 0, 1, 1);

        val_shareStatus = new QLabel(widget);
        val_shareStatus->setObjectName(QString::fromUtf8("val_shareStatus"));

        gridLayout->addWidget(val_shareStatus, 4, 1, 1, 1);

        lbl_download = new QLabel(widget);
        lbl_download->setObjectName(QString::fromUtf8("lbl_download"));

        gridLayout->addWidget(lbl_download, 5, 0, 1, 1);

        val_download = new QLabel(widget);
        val_download->setObjectName(QString::fromUtf8("val_download"));

        gridLayout->addWidget(val_download, 5, 1, 1, 1);

        lbl_pv = new QLabel(widget);
        lbl_pv->setObjectName(QString::fromUtf8("lbl_pv"));

        gridLayout->addWidget(lbl_pv, 6, 0, 1, 1);

        val_pv = new QLabel(widget);
        val_pv->setObjectName(QString::fromUtf8("val_pv"));

        gridLayout->addWidget(val_pv, 6, 1, 1, 1);


        retranslateUi(FilePropertyInfoDialog);

        QMetaObject::connectSlotsByName(FilePropertyInfoDialog);
    } // setupUi

    void retranslateUi(QDialog *FilePropertyInfoDialog)
    {
        FilePropertyInfoDialog->setWindowTitle(QCoreApplication::translate("FilePropertyInfoDialog", "Dialog", nullptr));
        lbl_fileName->setText(QCoreApplication::translate("FilePropertyInfoDialog", "\346\226\207\344\273\266\345\220\215\347\247\260", nullptr));
        val_fileName->setText(QCoreApplication::translate("FilePropertyInfoDialog", "\346\226\207\344\273\2661", nullptr));
        lbl_uploadUser->setText(QCoreApplication::translate("FilePropertyInfoDialog", "\344\270\212\344\274\240\350\200\205", nullptr));
        val_uploadUser->setText(QCoreApplication::translate("FilePropertyInfoDialog", "milo", nullptr));
        lbl_uploadTime->setText(QCoreApplication::translate("FilePropertyInfoDialog", "\344\270\212\344\274\240\346\227\266\351\227\264", nullptr));
        val_uploadTime->setText(QCoreApplication::translate("FilePropertyInfoDialog", "\346\227\266\351\227\264", nullptr));
        lbl_fileSize->setText(QCoreApplication::translate("FilePropertyInfoDialog", "\346\226\207\344\273\266\345\244\247\345\260\217", nullptr));
        val_fileSize->setText(QCoreApplication::translate("FilePropertyInfoDialog", "1024 KB", nullptr));
        lbl_shareStatus->setText(QCoreApplication::translate("FilePropertyInfoDialog", "\345\210\206\344\272\253\347\212\266\346\200\201", nullptr));
        val_shareStatus->setText(QCoreApplication::translate("FilePropertyInfoDialog", "\345\267\262\347\273\217\345\210\206\344\272\253", nullptr));
        lbl_download->setText(QCoreApplication::translate("FilePropertyInfoDialog", "\344\270\213\350\275\275\345\234\260\345\235\200", nullptr));
        val_download->setText(QCoreApplication::translate("FilePropertyInfoDialog", "\346\265\213\350\257\225", nullptr));
        lbl_pv->setText(QCoreApplication::translate("FilePropertyInfoDialog", "\344\270\213\350\275\275\351\207\217", nullptr));
        val_pv->setText(QCoreApplication::translate("FilePropertyInfoDialog", "1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FilePropertyInfoDialog: public Ui_FilePropertyInfoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEPROPERTYINFODIALOG_H
