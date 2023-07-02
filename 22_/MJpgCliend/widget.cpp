#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);
    manager = new QNetworkAccessManager(this);
    thread = new QThread(this);
    detectWork = new FaceDetection;         // 不能指定父对象
    detectWork->moveToThread(thread);       // 将工作对象移动到线程
    connect(this,SIGNAL(imageAcquired(QImage)),detectWork,SLOT(onFaceDetection(QImage)));
    connect(detectWork,SIGNAL(haveFace(QImage,bool)),this,SLOT(onHaveFace(QImage,bool)));
    thread->start();
    ui->lineEdit->setText("192.168.100.130");
    ui->lineEdit->show();
}

Widget::~Widget()
{
    delete ui;
    thread->terminate();
    thread->wait();
}

// "获取视频"

void Widget::on_btnGetMjpg_clicked()
{
    // 1. 准备请求包,设置url地址，根据url自动生成请求包
   // request.setUrl(QUrl("http://192.168.100.130:8080?action=stream"));
    QString ipText = ui->lineEdit->text().trimmed();
    QString ipUrl = "http://" + ipText + ":8080?action=stream";
    request.setUrl(QUrl(ipUrl));
    qDebug() << ipUrl;
    // 2. 发送请求包，使用get方法请求获取视频流数据，返回专门用于接收视频流数据的响应对象
    mjpgReply = manager->get(request);
    // 3. 放服务器发送来数据时，触发readyRead()信号的发射
    connect(mjpgReply,SIGNAL(readyRead()),this,SLOT(onMjpgReadyRead()));
}

// 接收mjpg视频流数据，从中剥离一张图片帧
void Widget::onMjpgReadyRead()
{
    // 1. 接收数据
    mjpgBuffer +=mjpgReply->readAll();
    // 2. 定义变量保存图片帧的起始标记  开始标记：0xff 0xd8  结束标记：0xff 0xd9
    char startFlag[3] = {(char)0xff,(char)0xd8};  // 开始标记
    char endFlag[3] = {(char)0xff,(char)0xd9};    // 结束标记
    // 3. 查找发送来的数据流中的图片的起始标记
    int startIndex = mjpgBuffer.indexOf(startFlag,0);
    if(startIndex == -1){
        mjpgBuffer.clear();
        return ;
    }
    int endIndex = mjpgBuffer.indexOf(endFlag,startIndex); // 从开始标记位子向后查找结束标记的位置
    if(endIndex == -1) // 找到开始标记，但是没有找到结束标记：图片数据还没有接收完毕
        {return;}
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
        emit imageAcquired(mjpgImg);
      //  qDebug() << "进入识别";
        mjpgBuffer.clear();
    }
}

void Widget::onHaveFace(QImage faceImg,bool isFace)
{
    qDebug() << "反馈识别人脸图像";

    if(isFace){
            qDebug() << "有人 ";
            QImage image=faceImg;
            QString folderPath = "../MJpgCliend/face/";
            // 获取当前系统时间，用于图片名称
            QString currentTime = QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss_zzz");
            QString fileName = "Image_" + currentTime + ".jpg"; // 可以根据需要更改图片格式
            // 构建完整的文件路径
            QString filePath = folderPath +fileName;
            // 使用QImageWriter将图像写入文件
            QImageWriter writer(filePath);
            if (writer.write(image))
                {
                    // 图像保存成功
                    qDebug() << "Image saved to:" << filePath;
                    // 将 QImage 转换为 QPixmap
                    QPixmap pixmap = QPixmap::fromImage(image);
                    // 将 QPixmap 设置为 QLabel 的 pixmap
                    ui->labelJpeg1->setPixmap(pixmap);
                    // 设置 QLabel 的大小适应图像大小
                    ui->labelJpeg1->setFixedSize(pixmap.size());
                    // 显示 QLabel
                    ui->labelJpeg1->show();

                }
                else
                {
                    // 图像保存失败
                    qDebug() << "Failed to save image.";
                }
    }
    if(!isFace){
        qDebug() << "无人 ";
        ui->labelJpeg1->clear();
    }

}
