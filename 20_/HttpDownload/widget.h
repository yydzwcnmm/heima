#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

private slots:
    void on_btnDefaultPath_clicked();
    void on_btnDownload_clicked();
    void onReadyRead();
    void onDownloadProgress(qint64 bytesReceived, qint64 bytesTotal);
    void onFinished();

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    QNetworkAccessManager networkManager;//网络管理
    QNetworkReply* reply; // 网络响应
    QFile* downloadFile;    // 保存下载的临时文件


};
#endif // WIDGET_H
