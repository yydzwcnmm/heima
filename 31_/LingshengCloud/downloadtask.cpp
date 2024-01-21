#include "downloadtask.h"


DownloadTask* DownloadTask::m_instance= new DownloadTask;

DownloadTask::DownloadTask()
{
     m_fileList = QList<DownloadFileInfo*>();
     qDebug() << "DownloadTask::DownloadTask() " ;
     qDebug() << "m_fileList size before append: " << m_fileList.size();
}

DownloadTask::~DownloadTask()
{

}

DownloadTask* DownloadTask::getInstance()
{
    return m_instance;
}


//判断任务列表是否为空
bool DownloadTask::isEmpty()
{
    return m_fileList.isEmpty();
}

//取出任务
DownloadFileInfo* DownloadTask::takeTask()
{
    DownloadFileInfo *temp = NULL;
    if (m_fileList.size() > 0) {
        temp = m_fileList.at(0);
    }

    return temp;
}

#if 0
//添加文件到上传任务列表中
int DownloadTask::appendDownloadTask(FileInfo *fileInfo, QString filePath, bool isShareTask)
{
    QFile* file = new QFile(filePath);
    if(!file->open(QIODevice::WriteOnly)){
        qDebug()<<"get err";
        delete file;
        file = NULL;
        return -2;
    }else {
        //只写的方式打开文件
        //添加到下载任务列表
        //对象有哪些属性
        qDebug()<<"DownloadFileInfo* downloadFile = new DownloadFileInfo;";
        DownloadFileInfo* downloadFile = new DownloadFileInfo;
        downloadFile->filePath = filePath;
        downloadFile->user = fileInfo->user;
        downloadFile->md5 = fileInfo->md5;
        downloadFile->isShareTask = isShareTask;
        downloadFile->url = fileInfo->url;
        downloadFile->file = file;
        downloadFile->fileName = fileInfo->fileName;

        qDebug()<<"downloadFile->filePath :"<<downloadFile->filePath;
        qDebug()<<"downloadFile->user :"<<downloadFile->user;
        qDebug()<<"downloadFile->md5r :"<<downloadFile->md5;
        qDebug()<<"downloadFile->isShareTask :"<<downloadFile->isShareTask;
        qDebug()<<"downloadFile->url :"<<downloadFile->url;
        qDebug()<<"downloadFile->file:"<<downloadFile->file;
        qDebug()<<"downloadFile->fileName :"<<downloadFile->fileName ;



        //m_fileList保存上传文件的列表
        //上传进度条（显示）, 将进度条UI显示在vLayout上
        FileDataProgress *fdp = new FileDataProgress();       
        fdp->setFileName(downloadFile->fileName);        
        downloadFile->fdp = fdp;
        QVBoxLayout *vLayout = DownloadLayout::getInstance()->getDownloadLayout();        
        vLayout->insertWidget(0, fdp);
        qDebug()<<"vLayout->addWidget(fdp);";


        m_fileList.append(downloadFile);        
        qDebug()<<"m_fileList.append(downloadFile);";

        return 0;

    }
}

#endif

int DownloadTask::appendDownloadTask(FileInfo *fileInfo, QString filePath, bool isShareTask)
{
    qDebug() << "Entering appendDownloadTask";
    qDebug() << "Before accessing m_fileList. m_fileList size: " << m_fileList.size();
    QFile *file = new QFile(filePath);
    if (!file->open(QIODevice::WriteOnly)) {
        qDebug() << "get err";

        delete file;
        file = NULL;
        return -2;
    } else {
        //只写的方式打开文件

        //添加到下载任务列表
        //对象有哪些属性

        DownloadFileInfo *downloadFile = new DownloadFileInfo;
        downloadFile->user = fileInfo->user;
        downloadFile->fileName = fileInfo->fileName;
        downloadFile->filePath = filePath;
        downloadFile->md5 = fileInfo->md5;
        downloadFile->url = fileInfo->url;
        downloadFile->file = file;
        downloadFile->isShareTask = isShareTask;

        qDebug()<<"downloadFile->filePath :"<<downloadFile->filePath;
        qDebug()<<"downloadFile->user :"<<downloadFile->user;
        qDebug()<<"downloadFile->md5r :"<<downloadFile->md5;
        qDebug()<<"downloadFile->isShareTask :"<<downloadFile->isShareTask;
        qDebug()<<"downloadFile->url :"<<downloadFile->url;
        qDebug()<<"downloadFile->file:"<<downloadFile->file;
        qDebug()<<"downloadFile->fileName :"<<downloadFile->fileName ;

        qDebug() << "m_fileList size before append: " << m_fileList.size();
        //下载进度条（显示）, 将进度条UI显示在vLayout上
        FileDataProgress *fdp = new FileDataProgress();
        fdp->setFileName(downloadFile->fileName);
        downloadFile->fdp = fdp;

        QVBoxLayout *vLayout = DownloadLayout::getInstance()->getDownloadLayout();
        //每一个都添加最上面
        vLayout->insertWidget(0, fdp);
        qDebug()<<"vLayout->addWidget(fdp);";

        if (downloadFile != nullptr) {
            qDebug() << "Before accessing m_fileList. downloadFile->filePath: " << downloadFile->filePath;
            // ... 其他代码
        } else {
            qDebug() << "downloadFile is null!";
        }

        //m_fileList保存下载文件的列表
        m_fileList.append(downloadFile);

        qDebug()<<"m_fileList.append(downloadFile);";


        return 0;

    }

}


//删除任务
void DownloadTask::delDownloadTask()
{
    //下载完成后需要处理的

    //1. FileDataProgress（fdp）对象从vLayout中移除
    //2. 删除FileDataProgress（fdp）对象
    //3. 删除DownloadFileInfo对象

    while (m_fileList.size()>0) {
    //for (int i=0; i<m_fileList.size(); i++) {
        //DownloadFileInfo *tmp = m_fileList.at(i);
        //if (tmp->uploadStatus == UPLOAD_FINISHED || tmp->uploadStatus == UPLOAD_FAILD) {
            DownloadFileInfo *downloadFileInfo = m_fileList.takeAt(0);
            if (downloadFileInfo != NULL) {
                //第一步
                QVBoxLayout *vLayout = DownloadLayout::getInstance()->getDownloadLayout();
                vLayout->removeWidget(downloadFileInfo->fdp);

                //第二步
                delete downloadFileInfo->fdp;
                downloadFileInfo->fdp = NULL;
                QFile *file = downloadFileInfo->file;
                if (file->isOpen()) {
                    file->close();
                }
                delete file;
                file = NULL;
                //第三步
                delete downloadFileInfo;
                downloadFileInfo = NULL;

            }
        //}
    }
}

void DownloadTask::clearList()
{

}
