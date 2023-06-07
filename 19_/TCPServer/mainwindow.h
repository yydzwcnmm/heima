#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostInfo>
#include <QLabel>
#include <QMetaEnum>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // QTcpServer::newConnection()
    void onNewConnection();
    // QTcpSocket::connected()
    void onConnected();
    // QTcpSocket::disconnected()
    void onDisconnected();
    // QTcpSocket::stateChanged(...)
    void onStateChanged(QAbstractSocket::SocketState socketState);

private:
    QString getLocalIP();

private:
    Ui::MainWindow *ui;
    QLabel* labelListen;
    QLabel* labelSocketState;
    QTcpServer* tcpServer;
    QTcpSocket* tcpSocket;



};
#endif // MAINWINDOW_H
