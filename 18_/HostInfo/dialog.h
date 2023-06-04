#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QHostInfo>
#include <QDebug>
#include <QNetworkInterface>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);

    ~Dialog();

private:
    QString protocolName(QAbstractSocket::NetworkLayerProtocol protocol);
    void lookedUp(const QHostInfo &hostInfo);

private slots:
    void on_btnGetLocalHostInfo_clicked();
    void on_btnGetDomainHostInfo_clicked();
    void on_btnTextClear_clicked();

    void on_btnAllAddresses_clicked();

    void on_btnAllInterfaces_clicked();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
