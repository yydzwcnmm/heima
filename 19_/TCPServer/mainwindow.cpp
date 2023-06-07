#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 状态栏
    labelListen = new QLabel ("监听状态");
    labelListen->setMinimumWidth(200);
    ui->statusbar->addWidget(labelListen);
    labelSocketState = new QLabel("Socket状态");
    labelSocketState->setMinimumWidth(200);
    ui->statusbar->addWidget(labelSocketState);
     // 获得本机IP
    QString localIP = getLocalIP();
    setWindowTitle("--本机IP：" + localIP);
    ui->actStart->setEnabled(true);
    ui->actStop->setEnabled(false);
    // tcp服务器
    tcpServer = new QTcpServer(this);
    connect(tcpServer,SIGNAL(newConnection()),this,SLOT(onNewConnection()))
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 获取本机IP
QString MainWindow::getLocalIP()
{
    QString hostName = QHostInfo::localHostName();
    QHostInfo hostInfo = QHostInfo::fromName(hostName);
    QString localIP = "";
    QList<QHostAddress>addrList = hostInfo.addresses();
    if(!addrList.isEmpty()){
        for(int i = 0;i<addrList.count();i++){
            QHostAddress addr = addrList.at(i);
            if(addr.protocol()==QAbstractSocket::IPv4Protocol){
                localIP = addr.toString();
                break;
            }
        }
    }
    return localIP;

}

// 客户端接入时，发射QTcpServer::newConnection()
void MainWindow::onNewConnection(){
    tcpSocket = tcpServer->nextPendingConnection();  // 获取一个用于通信的socket
    connect(tcpSocket,SIGNAL(connected()),this,SLOT(onConnected()));
    onConnected();
    connect(tcpSocket,SIGNAL(stateChanged(QAbstractSocket::SocketState)),this,
              SLOT(onStateChanged(QAbstractSocket::SocketState)));
    onStateChanged(tcpSocket->state());
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(onReadyRead()));
    connect(tcpSocket,SIGNAL(disconnected()),this,SLOT(onDisconnected()));
}

// QTcpSocket::connected() 显示客户端的IP与端口
void MainWindow::onConnected()
{
    ui->plainTextEdit->appendPlainText(" *****client socket connected ");
    ui->plainTextEdit->appendPlainText("  ***peer address: " +
                                       tcpSocket->peerAddress().toString());
    ui->plainTextEdit->appendPlainText(" ***peer port : " +
                                        QString::number(tcpSocket->peerPort()));

}

// QTcpSocket::disconnected()
void MainWindow::onDisconnected()
{
    ui->plainTextEdit->appendPlainText("**client sokcet disconnected");
    tcpSocket->deleteLater();
}

// QTcpSocket::stateChanged(...)
void MainWindow::onStateChanged(QAbstractSocket::SocketState socketState)
{
    QMetaEnum metaEnum = QMetaEnum::fromType<QAbstractSocket::SocketState>();
    labelSocketState->setText("Socket状态：" + QString(metaEnum.valueToKey(socketState)));
}

// "停止监听"


void MainWindow::on_actStop_triggered()
{
    if(tcpServer->isListening()){
        tcpServer->close();
        ui->actStart->setEnabled(true);
        ui->actStop->setEnabled(false);
        labelListen->setText("停止监听");

    }
}
