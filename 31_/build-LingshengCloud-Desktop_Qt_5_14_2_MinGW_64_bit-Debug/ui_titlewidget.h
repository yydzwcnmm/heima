/********************************************************************************
** Form generated from reading UI file 'titlewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TITLEWIDGET_H
#define UI_TITLEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TitleWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *title;
    QSpacerItem *horizontalSpacer;
    QPushButton *set;
    QPushButton *close;
    QPushButton *min;

    void setupUi(QWidget *TitleWidget)
    {
        if (TitleWidget->objectName().isEmpty())
            TitleWidget->setObjectName(QString::fromUtf8("TitleWidget"));
        TitleWidget->resize(650, 50);
        TitleWidget->setStyleSheet(QString::fromUtf8("backgroud-color:rgb(255, 0, 0)"));
        horizontalLayout = new QHBoxLayout(TitleWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        title = new QLabel(TitleWidget);
        title->setObjectName(QString::fromUtf8("title"));
        title->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"font: 10pt \"\351\273\221\344\275\223\";"));

        horizontalLayout->addWidget(title);

        horizontalSpacer = new QSpacerItem(455, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        set = new QPushButton(TitleWidget);
        set->setObjectName(QString::fromUtf8("set"));
        set->setStyleSheet(QString::fromUtf8("border-image: url(:/images/login_setting.png);"));

        horizontalLayout->addWidget(set);

        close = new QPushButton(TitleWidget);
        close->setObjectName(QString::fromUtf8("close"));
        close->setStyleSheet(QString::fromUtf8("border-image: url(:/images/login_close.png);"));

        horizontalLayout->addWidget(close);

        min = new QPushButton(TitleWidget);
        min->setObjectName(QString::fromUtf8("min"));
        min->setStyleSheet(QString::fromUtf8("border-image: url(:/images/login_min.png);"));

        horizontalLayout->addWidget(min);


        retranslateUi(TitleWidget);

        QMetaObject::connectSlotsByName(TitleWidget);
    } // setupUi

    void retranslateUi(QWidget *TitleWidget)
    {
        TitleWidget->setWindowTitle(QCoreApplication::translate("TitleWidget", "Form", nullptr));
        title->setText(QCoreApplication::translate("TitleWidget", "\347\244\274\345\240\202\344\272\221", nullptr));
        set->setText(QString());
        close->setText(QString());
        min->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TitleWidget: public Ui_TitleWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TITLEWIDGET_H
