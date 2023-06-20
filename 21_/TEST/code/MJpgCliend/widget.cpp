#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);

    labelJpegs.append(ui->labelJpeg1);
    labelJpegs.append(ui->labelJpeg2);
    labelJpegs.append(ui->labelJpeg3);
    labelJpegs.append(ui->labelJpeg4);

    manager = new QNetworkAccessManager(this);
    thread = new QThread(this);
    detectWork = new FaceDetection;   // 不能指定父对象
    detectWork->moveToThread(thread);  // 将工作对象移动到线程
    connect(this,SIGNAL(imageAcquired(QImage)),detectWork,SLOT(onFaceDetection(QImage)));

    thread->start();
}

Widget::~Widget()
{
    delete manager;
    manager = nullptr;
    thread->terminate();
    thread->wait();
    delete ui;
}
// "获取视频"
void Widget::on_btnGetMjpg_clicked()
{
    // 1. 准备请求包,设置url地址，根据url自动生成请求包
    request.setUrl(QUrl("http://192.168.116.138:8080?action=stream"));
    // 2. 发送请求包，使用get方法请求获取视频流数据，返回专门用于接收视频流数据的响应对象
    mjpgReply = manager->get(request);
    // 3. 放服务器发送来数据时，触发readyRead()信号的发射
    connect(mjpgReply,SIGNAL(readyRead()),this,SLOT(onMjpgReadyRead()));
}
// 接收mjpg视频流数据，从中剥离一张图片帧
void Widget::onMjpgReadyRead()
{
    // 1. 接收数据
    mjpgBuffer += mjpgReply->readAll();
    // 2. 定义变量保存图片帧的起始标记  开始标记：0xff 0xd8  结束标记：0xff 0xd9
    char startFlag[3] = {(char)0xff,(char)0xd8};  // 开始标记
    char endFlag[3] = {(char)0xff,(char)0xd9};    // 结束标记
    // 3. 查找发送来的数据流中的图片的起始标记
    int startIndex = mjpgBuffer.indexOf(startFlag,0); // 从0开始查找图片的开始标记
    if(startIndex == -1){ // 没有找到
        mjpgBuffer.clear();
        return;
    }
    int endIndex = mjpgBuffer.indexOf(endFlag,startIndex); // 从开始标记位子向后查找结束标记的位置
    if(endIndex == -1) // 找到开始标记，但是没有找到结束标记：图片数据还没有接收完毕
        return;
    // 4. 从视频流中截取一张图片帧数据
    QByteArray imgBuff = mjpgBuffer.mid(startIndex,(endIndex-startIndex)+2);
    // 5. 将QByteArray的数据加载到图片QImage中，图片格式为JPG
    bool ret = mjpgImg.loadFromData(imgBuff,"JPG");
    if(ret == false){
        mjpgBuffer.clear();
        return;
    }
    else{
        // 加载图片成功，显示到labelMjpg上
        ui->labelMjpg->setPixmap(QPixmap::fromImage(mjpgImg));
        emit imageAcquired(mjpgImg);  // 发射信号，进行人脸检测
        mjpgBuffer.clear();
    }
}
// "获取快照"
void Widget::on_btnGetJpeg_clicked()
{
    // 1. 准备请求包,设置url地址，根据url自动生成请求包
    request.setUrl(QUrl("http://192.168.116.138:8080?action=snapshot"));
    // 2. 发送请求包，使用get方法请求获取快照数据，返回专门用于接收快照数据的响应对象
    jpegReply = manager->get(request);
    // 3. 放服务器发送来数据时，触发readyRead()信号的发射
    connect(jpegReply,SIGNAL(readyRead()),this,SLOT(onJpegReadyRead()));
}
// 有快照数据时
void Widget::onJpegReadyRead()
{
    // 1. 接收数据
    jpegBuffer += jpegReply->readAll();
    // 2. 定义变量保存图片帧的起始标记  开始标记：0xff 0xd8  结束标记：0xff 0xd9
    char startFlag[3] = {(char)0xff,(char)0xd8};  // 开始标记
    char endFlag[3] = {(char)0xff,(char)0xd9};    // 结束标记
    // 3. 查找发送来的数据流中的图片的起始标记
    int startIndex = jpegBuffer.indexOf(startFlag,0); // 从0开始查找图片的开始标记
    if(startIndex == -1){ // 没有找到
        jpegBuffer.clear();
        return;
    }
    int endIndex = jpegBuffer.indexOf(endFlag,startIndex); // 从开始标记位子向后查找结束标记的位置
    if(endIndex == -1) // 找到开始标记，但是没有找到结束标记：图片数据还没有接收完毕
        return;
    // 4. 从快照数据流中截取一张图片帧数据
    QByteArray imgBuff = jpegBuffer.mid(startIndex,(endIndex-startIndex)+2);
    // 5. 将QByteArray的数据加载到图片QImage中，图片格式为JPG
    bool ret = jpegImg.loadFromData(imgBuff,"JPG");
    if(ret == false){
        jpegBuffer.clear();
        return;
    }
    else{
        // 加载图片成功，显示到labelMjpg上
        labelJpegs[m_index]->setPixmap(
           QPixmap::fromImage(jpegImg.scaled(labelJpegs[m_index]->size(),Qt::KeepAspectRatio)));
        m_index = (++m_index)%4;
        jpegBuffer.clear();
    }
}
