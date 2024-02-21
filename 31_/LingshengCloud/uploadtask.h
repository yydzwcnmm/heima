#ifndef UPLOADTASK_H
#define UPLOADTASK_H
#include <QString>
#include <QList>
#include "common.h"
#include <QFileInfo>
#include <QVBoxLayout>
#include "filedataprogress.h"
#include "uploadlayout.h".h"

#define UPLOAD_NOT          0   //未上传
#define UPLOADING           1   //正在上传
#define UPLOAD_FINISHED     2   //上传完成
#define UPLOAD_FAILD        3   //上传失败
#define UPLOAF_FILE_EXISTE  4   //上传的文件已存在

struct UploadFileInfo
{
    QString md5;            //文件的md5值
    QString fileName;       //文件名称
    QString filePath;       //文件路径
    qint64 size;            //文件大小
    FileDataProgress *fdp;  //进度条
    int uploadStatus;       //0.未上传，1.正在上传，2.上传完成
};

//上传任务列表类, 单例模式
class UploadTask
{

public:
    //获取UploadTask唯一实例对象
    static UploadTask* getInstance();
    int appendUploadTask(QString filePath);
    UploadFileInfo* takeTask();
    bool isEmpty();
    void delUploadTask();
    void clearList();

private:
    UploadTask();
    ~UploadTask();
    //静态数据成员，类中声明，类外必须定义
    static UploadTask* m_instance;
    UploadFileInfo *temp;



    QList<UploadFileInfo*>m_fileList;
    //判断任务列表是否为空


};

#endif // UPLOADTASK_H
