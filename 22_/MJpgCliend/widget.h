#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "facedetection.h"
#include <QLabel>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QThread>
#include <QImage>

#include <QFile>
#include <QDir>
#include <QDateTime>
#include <QImageWriter>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

signals:
    // 自定义信号
    void imageAcquired(QImage);

public slots:
    void onMjpgReadyRead(); // 接收到视频流数据时
    void onHaveFace(QImage faceImg,bool isFace);

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_btnGetMjpg_clicked();

private:
    Ui::Widget *ui;

    QNetworkAccessManager* manager; // 管理整个通信过程
    QNetworkRequest request;        // 根据url生成请求包

    QNetworkReply* mjpgReply;       // 获取视频流响应数据包
    QByteArray mjpgBuffer;           // 保存视频流响应数据的缓冲区
    QImage mjpgImg;                 // 保存从视频流中截取的图片帧

    QNetworkReply* jepgReply;       // 快照
    QByteArray jepgBuffer;
    QImage jepgImg;

    QThread* thread;
    FaceDetection* detectWork;      // 人脸检测工作对象

    QVector<QLabel*> labelJpegs;    // 保存显示的快照的label
    int m_index;                     // 索引
};
#endif // WIDGET_H
