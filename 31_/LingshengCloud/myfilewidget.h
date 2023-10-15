#ifndef MYFILEWIDGET_H
#define MYFILEWIDGET_H

#include <QWidget>
#include <QListView>
#include <QDebug>
#include <QAction>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>


namespace Ui {
class MyFileWidget;
}

class MyFileWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyFileWidget(QWidget *parent = nullptr);
    ~MyFileWidget();

private slots:
    void onRightMenu(const QPoint &pos);

private:
    Ui::MyFileWidget *ui;
    void initListWidget();



};

#endif // MYFILEWIDGET_H
