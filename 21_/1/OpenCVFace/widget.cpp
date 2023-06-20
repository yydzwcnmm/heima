#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);
    /***
     * setWindowFlag函数用于设置窗口的标志位，以便控制窗口的行为和外观。
     * Qt::MSWindowsFixedSizeDialogHint标志位用于指示窗口在Microsoft Windows平台上
     * 是一个固定大小的对话框
     * **/
    initWidget();

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_btnDetect_clicked()
{
    imgProc();
}


// 界面初始化
void Widget::initWidget()
{
    QString imgPath = "../OpenCVFace/3.jpeg";
    Mat imgData = imread(imgPath.toLatin1().data());
    cvtColor(imgData,imgData,COLOR_BGR2RGB);  //图像数据将从BGR格式转换为RGB格式，以便后续在RGB颜色空间下进行图像处理和显示。
    myImg = imgData;
    myQImg = QImage(imgData.data,imgData.cols,imgData.rows,QImage::Format_RGB888);
    imgShow();
}

// 图片显示
void Widget::imgShow()
{
    ui->labelView->setPixmap(
                QPixmap::fromImage(myQImg.scaled(ui->labelView->size(),Qt::KeepAspectRatio)));
}

// 图片处理(人脸识别)
void Widget::imgProc()
{
    CascadeClassifier face_detector; // 定义人脸识别分类器
    string faceDetectorPath = "../OpenCVFace/haarcascade_frontalface_alt.xml";
    face_detector.load(faceDetectorPath);  // 加载人脸识别分类器
    vector<Rect> faces; // 保存识别出的人脸的数据
    Mat imgSrc = myImg;
    Mat imgGray;
    cvtColor(imgSrc,imgGray,COLOR_BGR2GRAY);// 转换成灰度图片
    equalizeHist(imgGray,imgGray);// 直方图均衡化  图片增强
    // 多尺寸识别
    face_detector.detectMultiScale(
                imgGray,       // 要检测的灰度图片
                faces,         // 保存检测结果的向量
                1.1,           // 每次检测是的缩放比例
                3,             // 至少检测三次才确认目标
                0,
                Size(30,30)    // 检测的最小尺寸);
                    );
    for(unsigned int i=0;i<faces.size();i++){
        Point faceCenter(faces[i].x+faces[i].width*0.5,faces[i].y+faces[i].height*0.5);
        ellipse(imgSrc,faceCenter,Size(faces[i].width*0.5,faces[i].height*0.5),0,0,360,
                Scalar(255,0,255),4,8,0);   //imgSrc上画一椭圆

    }
    Mat imgDest = imgSrc;
    myQImg = QImage(imgDest.data,imgDest.cols,imgDest.rows,QImage::Format_RGB888);
    imgShow();
}
