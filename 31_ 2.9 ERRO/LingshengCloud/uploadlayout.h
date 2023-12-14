#ifndef UPLOADLAYOUT_H
#define UPLOADLAYOUT_H
#include <QWidget>
#include <QLayout>

//上传进度布局类, 单例模式

class UploadLayout
{

public:
    static UploadLayout* getInstance();
    void setUploadLayout(QWidget *parent);
     QVBoxLayout *m_vLayout;

private:
    UploadLayout();
    ~UploadLayout();
    static UploadLayout *m_instance;

    QVBoxLayout *vLayout;
};

#endif // UPLOADLAYOUT_H
