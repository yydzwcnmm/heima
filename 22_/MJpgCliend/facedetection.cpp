#include "facedetection.h"

FaceDetection::FaceDetection(QObject *parent) : QObject(parent)
{

// connect(this,SIGNAL(haveFace(QImage faceImg)),w,SLOT(onHaveFace(QImage faceImg)));
    retFace = true;
}

using namespace cv;

// 人脸检测槽函数
void FaceDetection::onFaceDetection(QImage img)
{
    qDebug()<<"进入人脸检测槽函数 ";
    QImage imageBack = img;
    // 将图像转换为RGB24位色
    QImage image = img.convertToFormat(QImage::Format_RGB888);
    // 将QImage格式 转换为Mat格式
    Mat matImg = Mat(image.height(),image.width(),CV_8UC3,
                        image.bits(),image.bytesPerLine());
     // 将图片进行灰度处理
    Mat imgGray;
    cvtColor(matImg,imgGray,COLOR_BGR2GRAY);
    // 加载分类器
    CascadeClassifier faceDetector;
    std::string detectPath = "../MJpgCliend/haarcascade_frontalface_alt.xml" ;
    faceDetector.load(detectPath);  // 加载分类器
    std::vector<Rect> faces;  //名为faces的变量，它是一个存储矩形（Rect）对象的向量（vector）。
    equalizeHist(imgGray,imgGray);
    // 多尺寸检测人脸
    faceDetector.detectMultiScale(imgGray,faces,1.1,3,0,Size(30,30));
    /***
1.1：表示每一次尺度变换时图像的缩放比例因子。如果设置为1.1，则每次将图像缩小10%进行检测。
3：表示在进行人脸检测时，每个候选矩形至少需要被多少个正样本分类器接受，才会被认为是一个人脸。该参数越高，过滤掉的误检测就越多。
0：额外的缩放因子，一般设置为0。
Size(30,30)：表示检测窗口的最小尺寸，人脸小于该尺寸的矩形将被忽略。
   ***/
    if(!faces.empty()){
        QString str = "人进入监控区域 ";
        qDebug() << str;
        retFace = true;
        emit haveFace(img,retFace);

    }else {

        retFace = false;
        emit haveFace(img,retFace);
    }

}
