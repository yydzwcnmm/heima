#ifndef FACEDETECTION_H
#define FACEDETECTION_H

#include <QObject>
#include <QImage>
#include <opencv2/opencv.hpp>
#include <iostream>
#include<QImage>
#include <QDebug>

class FaceDetection : public QObject
{
    Q_OBJECT
public:
    explicit FaceDetection(QObject *parent = nullptr);

public:
    bool retFace;
signals:
    // 自定义信号
    void haveFace(QImage,bool);

public slots:
    void onFaceDetection(QImage img);

};

#endif // FACEDETECTION_H
