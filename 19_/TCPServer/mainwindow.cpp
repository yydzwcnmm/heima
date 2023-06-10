#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

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
    displayCurrentPortAndIPAddress();
    setWindowTitle("服务器--本机IP：" + localIP);
  //  ui->lineEdit->setText(localIP);
    ui->actStart->setEnabled(true);
    ui->actStop->setEnabled(false);
    // tcp服务器
    tcpServer = new QTcpServer(this);
    connect(tcpServer,SIGNAL(newConnection()),this,SLOT(onNewConnection()));
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

// "发送消息": 发送一行字符串，以换行符结束
/*****
这段代码是一个在QT中定义的槽函数（slot function）。在这个函数中，当名为btnSend的按钮被点击时，将执行以下操作：

QString msg = ui->editMessage->text();:

这行代码从名为editMessage的输入字段中获取文本，并将其赋值给一个名为msg的QString变量。
它假设editMessage是一个在界面上定义的输入字段。
ui->plainTextEdit->appendPlainText("[发送] " + msg);:

这行代码将文本消息添加到名为plainTextEdit的文本编辑框中。
它在已有文本的末尾追加了一个字符串"[发送] "，然后添加了msg变量中的文本。
ui->editMessage->clear();:

这行代码清除了editMessage输入字段中的文本。
ui->editMessage->setFocus();:

这行代码将焦点设置回editMessage输入字段，以便用户可以继续输入新的消息。
QByteArray str = msg.toUtf8();:

这行代码将msg字符串转换为UTF-8编码的字节数组，并将结果赋值给一个名为str的QByteArray变量。
它使用toUtf8()函数将QString转换为QByteArray。
str.append("\n");:

这行代码在str字节数组的末尾追加一个换行符（\n）。
tcpSocket->write(str);:

这行代码使用tcpSocket对象将str字节数组中的数据发送到网络上的目标。
假设tcpSocket是在代码中定义并初始化的QTcpSocket对象。
综合来说，这段代码实现了从editMessage输入字段获取文本消息，并将消息添加到plainTextEdit文本编辑框中，然后将消息通过tcpSocket发送到网络上的目标。
 ****/


void MainWindow::on_btnSend_clicked()
{
    QString msg = ui->editMessage->text();
    ui->plainTextEdit->appendPlainText("[发送] " + msg);
    ui->editMessage->clear();
    ui->editMessage->setFocus();
    QByteArray str = msg.toUtf8();
    str.append("\n");
    tcpSocket->write(str);

}

// QTcpSocket::readyRead()：缓冲区有待读取数据
void MainWindow::onReadyRead()
{
    while (tcpSocket->canReadLine()) {
        ui->plainTextEdit->appendPlainText("[接收] " + tcpSocket->readLine());
    }

}

// 窗口关闭事件处理函数

/*****
这段代码是在`MainWindow`类中重写了关闭事件处理函数`closeEvent(QCloseEvent *event)`。当窗口关闭时，该函数会被调用。

解释如下：

- `tcpServer`是一个`QTcpServer`对象，用于监听和接受传入的网络连接。
- `isListening()`是`QTcpServer`类的一个方法，用于检查服务器是否正在监听传入的连接。
- `close()`是`QTcpServer`类的一个方法，用于停止监听传入的连接。

在这段代码中，当窗口关闭时，首先检查`tcpServer`是否正在监听传入的连接。如果正在监听，那么调用`tcpServer`的`close()`方法停止监听。

接着，`event->accept()`表示接受关闭事件，允许窗口关闭。

简而言之，这段代码的作用是在窗口关闭时检查并停止`tcpServer`对象的监听，确保网络连接不再接受新的连接请求。然后，允许窗口关闭。

*******/
void MainWindow::closeEvent(QCloseEvent *event)
{
    if(tcpServer->isListening()){
        tcpServer->close();

    }
    event->accept();
}

// "清空文本框"
void MainWindow::on_actTextClear_triggered()
{
    ui->plainTextEdit->clear();
}

// "开始监听"
void MainWindow::on_actStart_triggered()
{
    //QString ip = ui->cmbIp->currentText();
    if(!ui->lineEdit->isVisible()){

        //quint16 port = ui->spinPort->value();
         tcpServer->listen(QHostAddress::Any,0);
    }

    QString ip = ui->lineEdit->text();
    quint16 port = ui->spinPort->value();
    QHostAddress addr(ip);
    tcpServer->listen(addr,port);

    ui->plainTextEdit->appendPlainText("**开始监听...");
    ui->plainTextEdit->appendPlainText("**服务器地址：" +
                                  tcpServer->serverAddress().toString());
    ui->plainTextEdit->appendPlainText("**正在监听的端口号：" +
                                  QString::number(tcpServer->serverPort()));
    ui->actStart->setEnabled(false);
    ui->actStop->setEnabled(true);
    labelListen->setText("监听状态：正在监听...");
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



