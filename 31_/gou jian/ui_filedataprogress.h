/********************************************************************************
** Form generated from reading UI file 'filedataprogress.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEDATAPROGRESS_H
#define UI_FILEDATAPROGRESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileDataProgress
{
public:
    QLabel *label;
    QProgressBar *progressBar;

    void setupUi(QWidget *FileDataProgress)
    {
        if (FileDataProgress->objectName().isEmpty())
            FileDataProgress->setObjectName(QString::fromUtf8("FileDataProgress"));
        FileDataProgress->resize(651, 50);
        label = new QLabel(FileDataProgress);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(21, 11, 111, 16));
        progressBar = new QProgressBar(FileDataProgress);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(135, 11, 491, 23));
        progressBar->setValue(0);

        retranslateUi(FileDataProgress);

        QMetaObject::connectSlotsByName(FileDataProgress);
    } // setupUi

    void retranslateUi(QWidget *FileDataProgress)
    {
        FileDataProgress->setWindowTitle(QCoreApplication::translate("FileDataProgress", "Form", nullptr));
        label->setText(QCoreApplication::translate("FileDataProgress", "\346\226\207\344\273\2661", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FileDataProgress: public Ui_FileDataProgress {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEDATAPROGRESS_H
