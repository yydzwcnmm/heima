#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMetaEnum>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 状态栏
    labelSocketState = new QLabel("Socket状态：");
    labelSocketState->setMinimumWidth(300);
    ui->statusbar->addWidget(labelSocketState);

    // 本机IP
    QString localIP = getLocalIP();
    setWindowTitle(windowTitle() + "客户端--本机IP：" + localIP);
     ui->lineEdit->setText(localIP);
     displayCurrentPortAndIPAddress();

    // socket
    tcpClient = new QTcpSocket(this);    // 创建QTcpSocket对象
    connect(tcpClient,SIGNAL(connected()),this,SLOT(onConnected()));
    connect(tcpClient,SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this,SLOT(onStateChanged(QAbstractSocket::SocketState)));
    connect(tcpClient,SIGNAL(readyRead()),this,SLOT(onReadyRead()));
    connect(tcpClient,SIGNAL(disconnected()),this,SLOT(onDisconnected()));

    ui->actConn->setEnabled(true);
    ui->actDisconn->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}
// 获取本机IP
QString MainWindow::getLocalIP()
{
    QString hostName = QHostInfo::localHostName();  // 本地主机名
    QHostInfo hostInfo = QHostInfo::fromName(hostName);  // 本地主机信息
    QString localIP = "";
    QList<QHostAddress> addrList = hostInfo.addresses(); // IP地址列表
    if(!addrList.isEmpty()){
        for(int i=0;i<addrList.count();i++){
            QHostAddress addr = addrList.at(i);
            if(addr.protocol() == QAbstractSocket::IPv4Protocol){
                localIP = addr.toString();
                break;
            }
        }
    }
    return localIP;
}
// "连接到服务器"
void MainWindow::on_actConn_triggered()
{
    QString ip = ui->lineEdit->text();
    quint16 port = ui->spinServerPort->value();
    tcpClient->connectToHost(ip,port);
}
// QTcpSocket::connected()信号
void MainWindow::onConnected()
{
    ui->plainTextEdit->appendPlainText("++已连接到服务器");
    ui->plainTextEdit->appendPlainText("++peer address:" +
                                      tcpClient->peerAddress().toString());
    ui->plainTextEdit->appendPlainText("++peer port:" +
                                      QString::number(tcpClient->peerPort()));
    ui->actConn->setEnabled(false);
    ui->actDisconn->setEnabled(true);
}
// "断开连接"
void MainWindow::on_actDisconn_triggered()
{
    if(tcpClient->state() == QAbstractSocket::ConnectedState)
        tcpClient->disconnectFromHost();
}
// QTcpSocket::disconnected()信号
void MainWindow::onDisconnected()
{
    ui->plainTextEdit->appendPlainText("**已断开和服务器的连接");
    ui->actConn->setEnabled(true);
    ui->actDisconn->setEnabled(false);
}
// QTcpSocket::stateChanged(...)
void MainWindow::onStateChanged(QAbstractSocket::SocketState socketState)
{
    QMetaEnum metaEnum = QMetaEnum::fromType<QAbstractSocket::SocketState>();
    labelSocketState->setText("Socket状态：" + QString(metaEnum.valueToKey(socketState)));
}
// "发送消息"
void MainWindow::on_btnSend_clicked()
{
    QString msg = ui->editMessage->text();
    ui->plainTextEdit->appendPlainText("[发送] " + msg);
    ui->editMessage->clear();
    ui->editMessage->setFocus();

    QByteArray str = msg.toUtf8();
    str.append("\n");
    tcpClient->write(str);
}
// QTcpSocket::readyRead()信号：读取缓冲区中的数据
void MainWindow::onReadyRead()
{
    while(tcpClient->canReadLine())
        ui->plainTextEdit->appendPlainText("[接收] " + tcpClient->readLine());
}
// 窗口关闭事件处理函数
void MainWindow::closeEvent(QCloseEvent *event)
{
    if(tcpClient->state() == QAbstractSocket::ConnectedState)
        tcpClient->disconnectFromHost();
    event->accept();
}
// "清空文本框"
void MainWindow::on_actTextClear_triggered()
{
    ui->plainTextEdit->clear();
}


void MainWindow::displayCurrentPortAndIPAddress()
{
    QList<QNetworkInterface> interfaces = QNetworkInterface::allInterfaces();
        ui->plainTextEdit->appendPlainText("本机所有IP");
        foreach (QNetworkInterface interface, interfaces) {
            // 只显示活动的网络接口
            if (interface.flags().testFlag(QNetworkInterface::IsUp) &&
                    !interface.flags().testFlag(QNetworkInterface::IsLoopBack)) {
                QList<QNetworkAddressEntry> entries = interface.addressEntries();

                foreach (QNetworkAddressEntry entry, entries) {
                    // 显示IPv4地址和端口号
                    if (entry.ip().protocol() == QAbstractSocket::IPv4Protocol) {
                        //qDebug() << "Interface:" << interface.name();
                        //qDebug() << "IP Address:" << entry.ip().toString();
                        //qDebug() << "Port:" << entry.port();

                        ui->plainTextEdit->appendPlainText("Interface:" + interface.name());
                        ui->plainTextEdit->appendPlainText("IP Address:" + entry.ip().toString());

                    }
                }
            }
        }
    }
