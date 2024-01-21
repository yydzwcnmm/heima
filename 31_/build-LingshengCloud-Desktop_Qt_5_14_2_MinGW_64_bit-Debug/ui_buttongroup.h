/********************************************************************************
** Form generated from reading UI file 'buttongroup.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUTTONGROUP_H
#define UI_BUTTONGROUP_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ButtonGroup
{
public:
    QToolButton *btnUser;
    QToolButton *btnTransform;
    QToolButton *btnDownload;
    QToolButton *btnSwitchUser;
    QToolButton *btnMyFile;
    QToolButton *btnShare;
    QWidget *widget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *btnMin;
    QPushButton *btnMax;
    QPushButton *btnClose;
    QWidget *widget_2;

    void setupUi(QWidget *ButtonGroup)
    {
        if (ButtonGroup->objectName().isEmpty())
            ButtonGroup->setObjectName(QString::fromUtf8("ButtonGroup"));
        ButtonGroup->resize(800, 120);
        btnUser = new QToolButton(ButtonGroup);
        btnUser->setObjectName(QString::fromUtf8("btnUser"));
        btnUser->setGeometry(QRect(16, 10, 67, 90));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(12);
        btnUser->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/main/title_user.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnUser->setIcon(icon);
        btnUser->setIconSize(QSize(60, 60));
        btnUser->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnUser->setAutoRaise(true);
        btnTransform = new QToolButton(ButtonGroup);
        btnTransform->setObjectName(QString::fromUtf8("btnTransform"));
        btnTransform->setGeometry(QRect(384, 10, 107, 90));
        btnTransform->setFont(font);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/main/title_data.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnTransform->setIcon(icon1);
        btnTransform->setIconSize(QSize(60, 60));
        btnTransform->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnTransform->setAutoRaise(true);
        btnDownload = new QToolButton(ButtonGroup);
        btnDownload->setObjectName(QString::fromUtf8("btnDownload"));
        btnDownload->setGeometry(QRect(297, 10, 87, 90));
        btnDownload->setFont(font);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/main/title_hot.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDownload->setIcon(icon2);
        btnDownload->setIconSize(QSize(60, 60));
        btnDownload->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnDownload->setAutoRaise(true);
        btnSwitchUser = new QToolButton(ButtonGroup);
        btnSwitchUser->setObjectName(QString::fromUtf8("btnSwitchUser"));
        btnSwitchUser->setGeometry(QRect(491, 10, 107, 90));
        btnSwitchUser->setFont(font);
        btnSwitchUser->setIcon(icon1);
        btnSwitchUser->setIconSize(QSize(60, 60));
        btnSwitchUser->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnSwitchUser->setAutoRaise(true);
        btnMyFile = new QToolButton(ButtonGroup);
        btnMyFile->setObjectName(QString::fromUtf8("btnMyFile"));
        btnMyFile->setGeometry(QRect(83, 10, 107, 90));
        btnMyFile->setFont(font);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/main/title_file.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnMyFile->setIcon(icon3);
        btnMyFile->setIconSize(QSize(60, 60));
        btnMyFile->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnMyFile->setAutoRaise(true);
        btnShare = new QToolButton(ButtonGroup);
        btnShare->setObjectName(QString::fromUtf8("btnShare"));
        btnShare->setGeometry(QRect(190, 10, 107, 90));
        btnShare->setFont(font);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/main/title_share.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnShare->setIcon(icon4);
        btnShare->setIconSize(QSize(60, 60));
        btnShare->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnShare->setAutoRaise(true);
        widget = new QWidget(ButtonGroup);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(630, 10, 161, 81));
        widget->setStyleSheet(QString::fromUtf8(""));
        layoutWidget = new QWidget(widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 0, 137, 71));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        btnMin = new QPushButton(layoutWidget);
        btnMin->setObjectName(QString::fromUtf8("btnMin"));
        btnMin->setStyleSheet(QString::fromUtf8("border-image: url(:/images/main/window/title_min.png);"));

        gridLayout->addWidget(btnMin, 0, 0, 1, 1);

        btnMax = new QPushButton(layoutWidget);
        btnMax->setObjectName(QString::fromUtf8("btnMax"));
        btnMax->setStyleSheet(QString::fromUtf8("border-image: url(:/images/main/window/title_max.png);"));

        gridLayout->addWidget(btnMax, 0, 1, 1, 1);

        btnClose = new QPushButton(layoutWidget);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        btnClose->setStyleSheet(QString::fromUtf8("border-image: url(:/images/main/window/title_close.png);"));

        gridLayout->addWidget(btnClose, 0, 2, 1, 1);

        widget_2 = new QWidget(layoutWidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));

        gridLayout->addWidget(widget_2, 1, 0, 1, 3);


        retranslateUi(ButtonGroup);

        QMetaObject::connectSlotsByName(ButtonGroup);
    } // setupUi

    void retranslateUi(QWidget *ButtonGroup)
    {
        ButtonGroup->setWindowTitle(QCoreApplication::translate("ButtonGroup", "Form", nullptr));
        btnUser->setText(QCoreApplication::translate("ButtonGroup", "\346\270\270\345\256\242", nullptr));
        btnTransform->setText(QCoreApplication::translate("ButtonGroup", "\344\274\240\350\276\223\345\210\227\350\241\250", nullptr));
        btnDownload->setText(QCoreApplication::translate("ButtonGroup", "\344\270\213\350\275\275\346\246\234", nullptr));
        btnSwitchUser->setText(QCoreApplication::translate("ButtonGroup", "\345\210\207\346\215\242\347\224\250\346\210\267", nullptr));
        btnMyFile->setText(QCoreApplication::translate("ButtonGroup", "\346\210\221\347\232\204\346\226\207\344\273\266", nullptr));
        btnShare->setText(QCoreApplication::translate("ButtonGroup", "\345\205\261\344\272\253\345\210\227\350\241\250", nullptr));
        btnMin->setText(QString());
        btnMax->setText(QString());
        btnClose->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ButtonGroup: public Ui_ButtonGroup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUTTONGROUP_H
