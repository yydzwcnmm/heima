#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostInfo>
#include <QLabel>
#include <QMetaEnum>
#include <QNetworkInterface>
#include <QString>
#include <QDebug>

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

    void on_actStop_triggered();

    void on_btnSend_clicked();
    void onReadyRead();
    void on_actTextClear_triggered();

    void on_actStart_triggered();

protected:
    void closeEvent(QCloseEvent *event);
    void displayCurrentPortAndIPAddress();
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
