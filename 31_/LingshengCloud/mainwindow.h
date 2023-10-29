#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include "buttongroup.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setUser(QString user);

private:
    //处理按钮信号
    void buttonsSignals();

    void windowSignals();

private:
    Ui::MainWindow *ui;


signals:
    //切换用户
    void sigChangeUser();

    void sigLoginAgain();


};
#endif // MAINWINDOW_H
