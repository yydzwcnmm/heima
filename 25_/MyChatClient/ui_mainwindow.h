/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *GCStackedWidget;
    QWidget *page2;
    QVBoxLayout *verticalLayout_4;
    QWidget *widgetFrindT;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLabel *label_4;
    QWidget *frindListWidget;
    QWidget *page3;
    QVBoxLayout *verticalLayout_3;
    QWidget *widgetGroupT;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLabel *label_6;
    QWidget *groupListWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_10;
    QWidget *widgetConVT;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QWidget *convationListWidget;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_6;
    QWidget *widgetApply;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QLabel *label_8;
    QWidget *widget_5;
    QWidget *widgetUserInfo;
    QVBoxLayout *verticalLayout_9;
    QWidget *widgetWinBar;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnWinMenu;
    QPushButton *btnWinMin;
    QPushButton *btnWinClose;
    QHBoxLayout *horizontalLayout_8;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_4;
    QWidget *widgetHead;
    QHBoxLayout *horizontalLayout_9;
    QLabel *labelUser;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout_7;
    QSpacerItem *verticalSpacer_2;
    QLabel *labelUserName;
    QLabel *labelUserMask;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_10;
    QLabel *label_12;
    QWidget *widgetBottom;
    QVBoxLayout *verticalLayout_5;
    QWidget *widgetButtons;
    QHBoxLayout *horizontalLayout;
    QToolButton *btnFrind;
    QToolButton *btnGroup;
    QToolButton *btnConversation;
    QToolButton *btnApplay;
    QWidget *widgetMenu;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btnSysMenu;
    QToolButton *tbtnAddUser;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *tbtnWeather;
    QToolButton *tbtnCalendar;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(338, 680);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setGeometry(QRect(0, 0, 337, 682));
        GCStackedWidget = new QStackedWidget(centralWidget);
        GCStackedWidget->setObjectName(QString::fromUtf8("GCStackedWidget"));
        GCStackedWidget->setGeometry(QRect(0, 172, 337, 398));
        GCStackedWidget->setStyleSheet(QString::fromUtf8(""));
        page2 = new QWidget();
        page2->setObjectName(QString::fromUtf8("page2"));
        verticalLayout_4 = new QVBoxLayout(page2);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        widgetFrindT = new QWidget(page2);
        widgetFrindT->setObjectName(QString::fromUtf8("widgetFrindT"));
        widgetFrindT->setMaximumSize(QSize(16777215, 30));
        widgetFrindT->setStyleSheet(QString::fromUtf8("QWidget#widgetFrindT  {\n"
"	background-color: #5AFFFFFF;\n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(widgetFrindT);
        horizontalLayout_3->setSpacing(10);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(10, 0, 0, 0);
        label_3 = new QLabel(widgetFrindT);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/resource/images/ic_user.png")));
        label_3->setScaledContents(false);

        horizontalLayout_3->addWidget(label_3);

        label_4 = new QLabel(widgetFrindT);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        horizontalLayout_3->setStretch(1, 1);

        verticalLayout_4->addWidget(widgetFrindT);

        frindListWidget = new QWidget(page2);
        frindListWidget->setObjectName(QString::fromUtf8("frindListWidget"));

        verticalLayout_4->addWidget(frindListWidget);

        GCStackedWidget->addWidget(page2);
        page3 = new QWidget();
        page3->setObjectName(QString::fromUtf8("page3"));
        verticalLayout_3 = new QVBoxLayout(page3);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        widgetGroupT = new QWidget(page3);
        widgetGroupT->setObjectName(QString::fromUtf8("widgetGroupT"));
        widgetGroupT->setMaximumSize(QSize(16777215, 30));
        widgetGroupT->setStyleSheet(QString::fromUtf8("QWidget#widgetGroupT  {\n"
"	background-color: #5AFFFFFF;\n"
"}"));
        horizontalLayout_4 = new QHBoxLayout(widgetGroupT);
        horizontalLayout_4->setSpacing(10);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(10, 0, 0, 0);
        label_5 = new QLabel(widgetGroupT);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/resource/images/ic_group.png")));
        label_5->setScaledContents(false);

        horizontalLayout_4->addWidget(label_5);

        label_6 = new QLabel(widgetGroupT);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_4->addWidget(label_6);

        horizontalLayout_4->setStretch(1, 1);

        verticalLayout_3->addWidget(widgetGroupT);

        groupListWidget = new QWidget(page3);
        groupListWidget->setObjectName(QString::fromUtf8("groupListWidget"));

        verticalLayout_3->addWidget(groupListWidget);

        GCStackedWidget->addWidget(page3);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout_10 = new QVBoxLayout(page);
        verticalLayout_10->setSpacing(0);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        widgetConVT = new QWidget(page);
        widgetConVT->setObjectName(QString::fromUtf8("widgetConVT"));
        widgetConVT->setMaximumSize(QSize(16777215, 30));
        widgetConVT->setStyleSheet(QString::fromUtf8("QWidget#widgetConVT  {\n"
"	background-color: #5AFFFFFF;\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(widgetConVT);
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(10, 0, 0, 0);
        label = new QLabel(widgetConVT);
        label->setObjectName(QString::fromUtf8("label"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/resource/images/ic_chat.png")));
        label->setScaledContents(false);

        horizontalLayout_2->addWidget(label);

        label_2 = new QLabel(widgetConVT);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        horizontalLayout_2->setStretch(1, 1);

        verticalLayout_10->addWidget(widgetConVT);

        convationListWidget = new QWidget(page);
        convationListWidget->setObjectName(QString::fromUtf8("convationListWidget"));

        verticalLayout_10->addWidget(convationListWidget);

        GCStackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        verticalLayout_6 = new QVBoxLayout(page_2);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        widgetApply = new QWidget(page_2);
        widgetApply->setObjectName(QString::fromUtf8("widgetApply"));
        widgetApply->setMaximumSize(QSize(16777215, 30));
        widgetApply->setStyleSheet(QString::fromUtf8("QWidget#widgetApply  {\n"
"	background-color: #5AFFFFFF;\n"
"}"));
        horizontalLayout_6 = new QHBoxLayout(widgetApply);
        horizontalLayout_6->setSpacing(10);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(10, 0, 0, 0);
        label_7 = new QLabel(widgetApply);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setPixmap(QPixmap(QString::fromUtf8(":/resource/images/ic_app.png")));
        label_7->setScaledContents(false);

        horizontalLayout_6->addWidget(label_7);

        label_8 = new QLabel(widgetApply);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_6->addWidget(label_8);

        horizontalLayout_6->setStretch(1, 1);

        verticalLayout_6->addWidget(widgetApply);

        widget_5 = new QWidget(page_2);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));

        verticalLayout_6->addWidget(widget_5);

        GCStackedWidget->addWidget(page_2);
        widgetUserInfo = new QWidget(centralWidget);
        widgetUserInfo->setObjectName(QString::fromUtf8("widgetUserInfo"));
        widgetUserInfo->setGeometry(QRect(0, 2, 337, 170));
        widgetUserInfo->setMinimumSize(QSize(0, 170));
        widgetUserInfo->setMaximumSize(QSize(16777215, 170));
        verticalLayout_9 = new QVBoxLayout(widgetUserInfo);
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(1, 1, 1, 1);
        widgetWinBar = new QWidget(widgetUserInfo);
        widgetWinBar->setObjectName(QString::fromUtf8("widgetWinBar"));
        widgetWinBar->setMinimumSize(QSize(0, 30));
        widgetWinBar->setMaximumSize(QSize(16777215, 30));
        horizontalLayout_7 = new QHBoxLayout(widgetWinBar);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 5, 0);
        label_9 = new QLabel(widgetWinBar);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(30, 0));
        label_9->setPixmap(QPixmap(QString::fromUtf8(":/resource/images/robot.png")));

        horizontalLayout_7->addWidget(label_9);

        horizontalSpacer = new QSpacerItem(220, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        btnWinMenu = new QPushButton(widgetWinBar);
        btnWinMenu->setObjectName(QString::fromUtf8("btnWinMenu"));
        btnWinMenu->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resource/common/ic_login_cfg.png"), QSize(), QIcon::Normal, QIcon::On);
        btnWinMenu->setIcon(icon);

        horizontalLayout_7->addWidget(btnWinMenu);

        btnWinMin = new QPushButton(widgetWinBar);
        btnWinMin->setObjectName(QString::fromUtf8("btnWinMin"));
        btnWinMin->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resource/common/ic_min.png"), QSize(), QIcon::Normal, QIcon::On);
        btnWinMin->setIcon(icon1);

        horizontalLayout_7->addWidget(btnWinMin);

        btnWinClose = new QPushButton(widgetWinBar);
        btnWinClose->setObjectName(QString::fromUtf8("btnWinClose"));
        btnWinClose->setFocusPolicy(Qt::NoFocus);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resource/common/ic_close_white.png"), QSize(), QIcon::Normal, QIcon::On);
        btnWinClose->setIcon(icon2);

        horizontalLayout_7->addWidget(btnWinClose);


        verticalLayout_9->addWidget(widgetWinBar);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(5);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(5, -1, 5, -1);
        widget = new QWidget(widgetUserInfo);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        widgetHead = new QWidget(widget);
        widgetHead->setObjectName(QString::fromUtf8("widgetHead"));
        widgetHead->setMinimumSize(QSize(64, 64));
        widgetHead->setMaximumSize(QSize(64, 64));
        widgetHead->setStyleSheet(QString::fromUtf8("border: 1px solid #000000;"));
        horizontalLayout_9 = new QHBoxLayout(widgetHead);
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);

        verticalLayout_2->addWidget(widgetHead);

        labelUser = new QLabel(widget);
        labelUser->setObjectName(QString::fromUtf8("labelUser"));
        labelUser->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(labelUser);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);


        horizontalLayout_8->addWidget(widget);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(15);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_2);

        labelUserName = new QLabel(widgetUserInfo);
        labelUserName->setObjectName(QString::fromUtf8("labelUserName"));

        verticalLayout_7->addWidget(labelUserName);

        labelUserMask = new QLabel(widgetUserInfo);
        labelUserMask->setObjectName(QString::fromUtf8("labelUserMask"));

        verticalLayout_7->addWidget(labelUserMask);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer);


        horizontalLayout_8->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        label_10 = new QLabel(widgetUserInfo);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(label_10);

        label_12 = new QLabel(widgetUserInfo);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(label_12);


        horizontalLayout_8->addLayout(verticalLayout_8);


        verticalLayout_9->addLayout(horizontalLayout_8);

        widgetBottom = new QWidget(centralWidget);
        widgetBottom->setObjectName(QString::fromUtf8("widgetBottom"));
        widgetBottom->setGeometry(QRect(0, 570, 337, 110));
        widgetBottom->setMinimumSize(QSize(0, 110));
        widgetBottom->setMaximumSize(QSize(16777215, 110));
        verticalLayout_5 = new QVBoxLayout(widgetBottom);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        widgetButtons = new QWidget(widgetBottom);
        widgetButtons->setObjectName(QString::fromUtf8("widgetButtons"));
        widgetButtons->setMinimumSize(QSize(0, 65));
        horizontalLayout = new QHBoxLayout(widgetButtons);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnFrind = new QToolButton(widgetButtons);
        btnFrind->setObjectName(QString::fromUtf8("btnFrind"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/resource/images/contacts.png"), QSize(), QIcon::Normal, QIcon::On);
        btnFrind->setIcon(icon3);
        btnFrind->setIconSize(QSize(24, 24));
        btnFrind->setCheckable(true);
        btnFrind->setChecked(true);
        btnFrind->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(btnFrind);

        btnGroup = new QToolButton(widgetButtons);
        btnGroup->setObjectName(QString::fromUtf8("btnGroup"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/resource/images/group_normal.png"), QSize(), QIcon::Normal, QIcon::On);
        btnGroup->setIcon(icon4);
        btnGroup->setIconSize(QSize(24, 24));
        btnGroup->setCheckable(true);
        btnGroup->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(btnGroup);

        btnConversation = new QToolButton(widgetButtons);
        btnConversation->setObjectName(QString::fromUtf8("btnConversation"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/resource/images/conversation_normal.png"), QSize(), QIcon::Normal, QIcon::On);
        btnConversation->setIcon(icon5);
        btnConversation->setIconSize(QSize(24, 24));
        btnConversation->setCheckable(true);
        btnConversation->setChecked(false);
        btnConversation->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(btnConversation);

        btnApplay = new QToolButton(widgetButtons);
        btnApplay->setObjectName(QString::fromUtf8("btnApplay"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/resource/images/applay.png"), QSize(), QIcon::Normal, QIcon::On);
        btnApplay->setIcon(icon6);
        btnApplay->setIconSize(QSize(24, 24));
        btnApplay->setCheckable(true);
        btnApplay->setChecked(false);
        btnApplay->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(btnApplay);


        verticalLayout_5->addWidget(widgetButtons);

        widgetMenu = new QWidget(widgetBottom);
        widgetMenu->setObjectName(QString::fromUtf8("widgetMenu"));
        widgetMenu->setMinimumSize(QSize(0, 35));
        widgetMenu->setMaximumSize(QSize(16777215, 35));
        horizontalLayout_5 = new QHBoxLayout(widgetMenu);
        horizontalLayout_5->setSpacing(5);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(10, 2, 10, 2);
        btnSysMenu = new QPushButton(widgetMenu);
        btnSysMenu->setObjectName(QString::fromUtf8("btnSysMenu"));
        btnSysMenu->setMinimumSize(QSize(0, 30));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/resource/common/ic_sysmen.png"), QSize(), QIcon::Normal, QIcon::On);
        btnSysMenu->setIcon(icon7);
        btnSysMenu->setIconSize(QSize(24, 24));

        horizontalLayout_5->addWidget(btnSysMenu);

        tbtnAddUser = new QToolButton(widgetMenu);
        tbtnAddUser->setObjectName(QString::fromUtf8("tbtnAddUser"));
        tbtnAddUser->setMinimumSize(QSize(0, 30));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/resource/common/ic_user_add.png"), QSize(), QIcon::Normal, QIcon::On);
        tbtnAddUser->setIcon(icon8);
        tbtnAddUser->setIconSize(QSize(24, 24));

        horizontalLayout_5->addWidget(tbtnAddUser);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        tbtnWeather = new QToolButton(widgetMenu);
        tbtnWeather->setObjectName(QString::fromUtf8("tbtnWeather"));
        tbtnWeather->setMinimumSize(QSize(0, 30));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/resource/common/ic_weather.png"), QSize(), QIcon::Normal, QIcon::On);
        tbtnWeather->setIcon(icon9);
        tbtnWeather->setIconSize(QSize(24, 24));

        horizontalLayout_5->addWidget(tbtnWeather);

        tbtnCalendar = new QToolButton(widgetMenu);
        tbtnCalendar->setObjectName(QString::fromUtf8("tbtnCalendar"));
        tbtnCalendar->setMinimumSize(QSize(0, 30));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/resource/common/ic_calendar.png"), QSize(), QIcon::Normal, QIcon::On);
        tbtnCalendar->setIcon(icon10);
        tbtnCalendar->setIconSize(QSize(24, 24));

        horizontalLayout_5->addWidget(tbtnCalendar);


        verticalLayout_5->addWidget(widgetMenu);


        retranslateUi(MainWindow);

        GCStackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_3->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "\350\201\224\347\263\273\344\272\272", nullptr));
        label_5->setText(QString());
        label_6->setText(QCoreApplication::translate("MainWindow", "\347\276\244\347\273\204", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "\344\274\232\350\257\235", nullptr));
        label_7->setText(QString());
        label_8->setText(QCoreApplication::translate("MainWindow", "\345\272\224\347\224\250", nullptr));
        label_9->setText(QString());
        btnWinMenu->setText(QString());
        btnWinMin->setText(QString());
        btnWinClose->setText(QString());
        labelUser->setText(QCoreApplication::translate("MainWindow", "Tourist", nullptr));
        labelUserName->setText(QCoreApplication::translate("MainWindow", "\347\244\274\345\240\202\350\212\202\345\272\246\344\275\277", nullptr));
        labelUserMask->setText(QCoreApplication::translate("MainWindow", "\351\233\252\350\261\271\345\217\202\344\270\212", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\345\260\217\351\233\250", nullptr));
        label_12->setText(QString());
        btnFrind->setText(QCoreApplication::translate("MainWindow", "\345\245\275\345\217\213", nullptr));
        btnGroup->setText(QCoreApplication::translate("MainWindow", "\347\276\244\347\273\204", nullptr));
#if QT_CONFIG(tooltip)
        btnConversation->setToolTip(QCoreApplication::translate("MainWindow", "\344\274\232\350\257\235", nullptr));
#endif // QT_CONFIG(tooltip)
        btnConversation->setText(QCoreApplication::translate("MainWindow", "\344\274\232\350\257\235", nullptr));
#if QT_CONFIG(tooltip)
        btnApplay->setToolTip(QCoreApplication::translate("MainWindow", "\345\272\224\347\224\250", nullptr));
#endif // QT_CONFIG(tooltip)
        btnApplay->setText(QCoreApplication::translate("MainWindow", "\345\272\224\347\224\250", nullptr));
#if QT_CONFIG(tooltip)
        btnSysMenu->setToolTip(QCoreApplication::translate("MainWindow", "\347\263\273\347\273\237\350\217\234\345\215\225", nullptr));
#endif // QT_CONFIG(tooltip)
        btnSysMenu->setText(QString());
#if QT_CONFIG(tooltip)
        tbtnAddUser->setToolTip(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\345\245\275\345\217\213", nullptr));
#endif // QT_CONFIG(tooltip)
        tbtnAddUser->setText(QString());
#if QT_CONFIG(tooltip)
        tbtnWeather->setToolTip(QCoreApplication::translate("MainWindow", "\345\244\251\346\260\224\346\237\245\350\257\242", nullptr));
#endif // QT_CONFIG(tooltip)
        tbtnWeather->setText(QString());
#if QT_CONFIG(tooltip)
        tbtnCalendar->setToolTip(QCoreApplication::translate("MainWindow", "\346\227\245\345\216\206", nullptr));
#endif // QT_CONFIG(tooltip)
        tbtnCalendar->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
