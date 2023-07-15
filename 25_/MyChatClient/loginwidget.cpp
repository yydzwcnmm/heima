#include "loginwidget.h"
#include "mainwindow.h"
#include "ui_loginwidget.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

LoginWidget::LoginWidget(QWidget *parent) :
    CustomMoveWidget(parent),
    ui(new Ui::LoginWidget)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint);      //去掉qt自带的标题栏
    this->setAttribute(Qt::WA_TranslucentBackground);   //使透明生效

    QFile file(":/qss/resource/qss/default.css");
    file.open(QIODevice::ReadOnly);

    //设置样式表
    qApp->setStyleSheet(file.readAll());
    file.close();


    ui->stackedWidget->setCurrentIndex(0);

    //给lineEditUser添加图片
    ui->lineEditUser->SetIcon(QPixmap(":/resource/common/ic_user.png"));
    ui->lineEditPasswd->SetIcon(QPixmap(":/resource/common/ic_lock.png"));
    ui->labelWinTitle->setText("用户登录");
    m_tcpSocket = new ClientSocket;


    //检查是否连接到服务器
    m_tcpSocket->CheckConnected();
    connect(m_tcpSocket,&ClientSocket::signalMessage,this,&LoginWidget::onSignalStatus);
    connect(m_tcpSocket,&ClientSocket::signalStatus,this,&LoginWidget::onSignalStatus);
}

LoginWidget::~LoginWidget()
{
    delete ui;
}

void LoginWidget::on_btnWinMenu_clicked()
{
    ui->stackedWidget->setStartVal(0);   //翻转的起始值
    ui->stackedWidget->setEndVal(180);     //翻转的结束值
    //m_asw实现动画效果
    ui->stackedWidget->animation(1);
}

void LoginWidget::on_btnCancel_clicked()
{
    ui->stackedWidget->setStartVal(0);   //翻转的起始值
    ui->stackedWidget->setEndVal(-180);     //翻转的结束值
    //m_asw实现动画效果
    ui->stackedWidget->animation(0);
}

void LoginWidget::on_btnLogin_clicked()
{
    QString username = ui->lineEditUser->text();
    QString passwd = ui->lineEditPasswd->text();
    // 构建 Json 对象
    QJsonObject json;
    json.insert("name",username);
    json.insert("paaswd",passwd);
    m_tcpSocket->SltSendMessage(0x11,json);
}

void LoginWidget::onSignalStatus(const quint8& state)
{
    switch (state) {
        case 0x01:
        {
            ui->labelWinTitle->setText("已连接服务器");

        }break;
        case 0x03:
        {
            qDebug()<<"用户登录成功";
            MainWindow *mainWindow = new MainWindow;
            mainWindow->show();
            this->hide();
        }break;
        case 0x04:
        {
            qDebug()<<"用户未注册";

        }break;
        case 0x13:
        {
            qDebug()<<"用户已在线";

        }break;
    }
}

