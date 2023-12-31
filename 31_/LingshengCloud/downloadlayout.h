#ifndef DOWNLOADLAYOUT_H
#define DOWNLOADLAYOUT_H
#include <QLayout>
#include <QWidget>

//上传进度布局类, 单例模式
class DownloadLayout
{
public:





public:
    static DownloadLayout* getInstance();
    void setDownloadLayout(QWidget *parent);

    //获取上传的布局变量
    QVBoxLayout* getDownloadLayout();

private:
    DownloadLayout();
    ~DownloadLayout();


    static DownloadLayout *m_instance;

    QVBoxLayout *m_vLayout;


};

#endif // DOWNLOADLAYOUT_H
