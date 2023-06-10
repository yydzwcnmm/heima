#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QLabel>
#include <QHostInfo>
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
protected:
    void closeEvent(QCloseEvent *event);
    void displayCurrentPortAndIPAddress();
private:
    QString getLocalIP();
private slots:
    // 自定义槽函数
    // QTcpSocket::connected()
    void onConnected();
    // QTcpSocket::disconnected()
    void onDisconnected();
    // QTcpSocket::stateChanged(...)
    void onStateChanged(QAbstractSocket::SocketState socketState);
    // QTcpSocket::readyRead()
    void onReadyRead();
    void on_actConn_triggered();

    void on_actDisconn_triggered();

    void on_btnSend_clicked();

    void on_actTextClear_triggered();

private:
    Ui::MainWindow *ui;

    QTcpSocket* tcpClient;  // 通信用的socket
    QLabel* labelSocketState;  // socket状态
};
#endif // MAINWINDOW_H
