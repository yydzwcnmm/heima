#include "titlewidget.h"
#include "ui_titlewidget.h"

TitleWidget::TitleWidget(QWidget *parent) : QWidget(parent),
    ui(new Ui::TitleWidget)
{
    ui->setupUi(this);
    //或者这样设置背景色
    //this->setStyleSheet("color:rgb(85, 170, 255);");
    //style ()->polish(this);
    //传入父对象
    m_parent = parent;
}

TitleWidget::~TitleWidget()
{
    delete ui;
}

/***
void TitleWidget::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);//绘制样式
}
***/
void TitleWidget::mouseMoveEvent(QMouseEvent *event)
{
    //只允许鼠标左键拖动
    if(event->buttons() == Qt::LeftButton){
        //窗口需要跟着鼠标移动
        //窗口左上角点 = 鼠标当前位置 - 差值
        m_parent->move(event->globalPos() - m_pt);
    }
}

void TitleWidget::mousePressEvent(QMouseEvent *event)
{
    //只允许鼠标左键按下
    if(event->buttons() == Qt::LeftButton){
        //求差值 = 鼠标当前位置 - 窗口左上角位置
        m_pt = event->globalPos()-m_parent->geometry().topLeft();//m_parent loginDialog左上角
    }
}

void TitleWidget::on_min_clicked()
{
    m_parent->setWindowState(Qt::WindowMinimized);
}

void TitleWidget::on_set_clicked()
{
    emit showSetPage();
}



void TitleWidget::on_close_clicked()
{
   emit closeButton();
}
