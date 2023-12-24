#include "uploadlayout.h"

UploadLayout *UploadLayout::m_instance = new UploadLayout;


UploadLayout::UploadLayout()
{

}

UploadLayout::~UploadLayout()
{

}
UploadLayout* UploadLayout::getInstance()
{
    return m_instance;
}

void UploadLayout::setUploadLayout(QWidget *parent)
{
    //parent upload_scroll
    //使用垂直布局
    QVBoxLayout *vLayout = new QVBoxLayout;


#if 1
    m_vLayout = vLayout;
    //添加弹簧
    //m_vLayout->addStretch(2);


    qDebug()<<" parent->setLayout(vLayout);+++++++++++++++++++++++++";


#endif
#if 0
    for(int i=0;i<10;i++){
        FileDataProgress *f1 = new FileDataProgress;
        f1->setFileName(QString("I = %1").arg(i));
        vLayout->insertWidget(0,f1);

    }
 #endif


    parent->setLayout(vLayout);

}

QVBoxLayout* UploadLayout::getUploadLayout() {
    return m_vLayout;
}
