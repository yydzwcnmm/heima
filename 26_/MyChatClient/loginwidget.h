#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include "customwidget.h"
#include"databasemagr.h"
#include"clientsocket.h"

namespace Ui {
class LoginWidget;
}

class LoginWidget : public CustomMoveWidget
{
    Q_OBJECT

public:
    explicit LoginWidget(QWidget *parent = 0);
    ~LoginWidget();

private slots:
    void on_btnWinMenu_clicked();

    void on_btnCancel_clicked();

    void on_btnLogin_clicked();
    void onSignalStatus(const quint8& state);

private:
    Ui::LoginWidget *ui;
    ClientSocket *m_tcpSocket;
};

#endif // LOGINWIDGET_H
