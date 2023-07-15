#include "widget.h"
#include "iplineedit.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *vlayout = new QVBoxLayout(this);
    QPushButton *btn = new QPushButton(this);
    IPLineEdit *ip = new IPLineEdit(this);
    vlayout->addWidget(ip);
    vlayout->addWidget(btn);
}

Widget::~Widget()
{
}

