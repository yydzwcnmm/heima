#include "buttongroup.h"
#include "ui_buttongroup.h"

ButtonGroup::ButtonGroup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ButtonGroup)
{
    ui->setupUi(this);
    //m_parent = parent;
    defaultPage();
    //将一组由标识的发送者的signal连接在一起，通过setMapping来实现的
    m_mapper = new QSignalMapper(this);
    m_map.insert(ui->btnMyFile->text(), ui->btnMyFile);
    m_map.insert(ui->btnShare->text(), ui->btnShare);
    m_map.insert(ui->btnDownload->text(), ui->btnDownload);
    m_map.insert(ui->btnTransform->text(), ui->btnTransform);
    QMap<QString,QToolButton*>::iterator iter = m_map.begin();
    for(;iter != m_map.end();iter++){
        m_mapper->setMapping(iter.value(),iter.key());
        connect(iter.value(),SIGNAL(clicked(bool)),m_mapper,SLOT(map()));

    }
    connect(m_mapper,SIGNAL(mapped(QString)),this,SLOT(onMapperButtonsClicked(QString)));
}

ButtonGroup::~ButtonGroup()
{
    delete ui;
}

void ButtonGroup::mouseMoveEvent(QMouseEvent *event)
{
    //只允许鼠标左键拖动
    if(event->buttons() == Qt::LeftButton){
        //窗口需要跟着鼠标移动
        //窗口左上角点 = 鼠标当前位置 - 差值
        m_parent->move(event->globalPos() - m_pt);
        qDebug()<<"窗口需要跟着鼠标移动" ;
    }
}

void ButtonGroup::mousePressEvent(QMouseEvent *event)
{
    //只允许鼠标左键按下
    if(event->buttons() == Qt::LeftButton){
        //求差值 = 鼠标当前位置 - 窗口左上角位置
        m_pt = event->globalPos()-m_parent->geometry().topLeft();//m_parent main左上角
        qDebug()<<"求差值" ;
    }
}


void ButtonGroup::setParent(QWidget* parent)
{
    m_parent = parent;
}

void ButtonGroup::setUser(QString user)
{
    ui->btnUser->setText(user);
}

/***
void ButtonGroup::on_btnMyFile_clicked()
{
    emit sigMyFile();
    ui->btnMyFile->setStyleSheet("color:red");
    ui->btnShare->setStyleSheet("color:black");
    ui->btnDownload->setStyleSheet("color:black");
    ui->btnTransform->setStyleSheet("color:black");
    ui->btnSwitchUser->setStyleSheet("color:black");
}

void ButtonGroup::on_btnShare_clicked()
{
    emit sigShare();
    ui->btnMyFile->setStyleSheet("color:black");
    ui->btnShare->setStyleSheet("color:red");
    ui->btnDownload->setStyleSheet("color:black");
    ui->btnTransform->setStyleSheet("color:black");
    ui->btnSwitchUser->setStyleSheet("color:black");
}

void ButtonGroup::on_btnDownload_clicked()
{
    emit sigDownload();
    ui->btnMyFile->setStyleSheet("color:black");
    ui->btnShare->setStyleSheet("color:black");
    ui->btnDownload->setStyleSheet("color:red");
    ui->btnTransform->setStyleSheet("color:black");
    ui->btnSwitchUser->setStyleSheet("color:black");
}

void ButtonGroup::on_btnTransform_clicked()
{
    emit sigTransform();
    ui->btnMyFile->setStyleSheet("color:black");
    ui->btnShare->setStyleSheet("color:black");
    ui->btnDownload->setStyleSheet("color:black");
    ui->btnTransform->setStyleSheet("color:red");
    ui->btnSwitchUser->setStyleSheet("color:black");
}
***/
void ButtonGroup::on_btnSwitchUser_clicked()
{
    emit sigSwitchUser();
    defaultPage();

}




void ButtonGroup::defaultPage()
{
    //默认是btnMyFile;
    ui->btnMyFile->setStyleSheet("color:red");
    ui->btnShare->setStyleSheet("color:black");
    ui->btnDownload->setStyleSheet("color:black");
    ui->btnTransform->setStyleSheet("color:black");
    ui->btnSwitchUser->setStyleSheet("color:black");
    m_curBtn = ui->btnMyFile;
}


void  ButtonGroup::onMapperButtonsClicked(QString text)
{
    qDebug() << " in onMapperButtonsClicked:";
    QToolButton* btnTemp = nullptr;  //选中按钮
    QMap<QString,QToolButton*>::iterator iter = m_map.begin();
    for(;iter != m_map.end();iter++){
        if(iter.key()==text){
            btnTemp = *(iter);
        }
    }
    m_curBtn->setStyleSheet("color:black");

    //1. 当前按钮设置选中颜色
    m_curBtn =  btnTemp;
    m_curBtn->setStyleSheet("color:red");

    //2. 发送信号
    if (text == ui->btnMyFile->text()) {
        emit sigMyFile();
    } else if (text == ui->btnShare->text()) {
        emit sigShare();
    } else if (text == ui->btnDownload->text()) {
        emit sigDownload();
    } else if (text == ui->btnTransform->text()) {
        emit sigTransform();
    }
}
