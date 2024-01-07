#include "downloadtask.h"


DownloadTask* DownloadTask::m_instance= new DownloadTask;

DownloadTask::DownloadTask()
{

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

#if 1
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
        DownloadFileInfo* downloadFile = new DownloadFileInfo;

        downloadFile->filePath = filePath;
        downloadFile->user = fileInfo->user;
        downloadFile->md5 = Common::getInstance()->getFileMd5(filePath);
        downloadFile->isShareTask = isShareTask;
        downloadFile->md5 = fileInfo->md5;
        downloadFile->url = fileInfo->url;
        downloadFile->file = file;
        downloadFile->fileName = fileInfo->fileName;

        //m_fileList保存上传文件的列表
        //上传进度条（显示）, 将进度条UI显示在vLayout上
        FileDataProgress *fdp = new FileDataProgress();
        fdp->setFileName(downloadFile->fileName);
        downloadFile->fdp = fdp;
        QVBoxLayout *vLayout = DownloadLayout::getInstance()->getDownloadLayout();
        vLayout->addWidget(fdp);
        m_fileList.append(downloadFile);
        return 0;
    }
}

#endif

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
                QFile *file = downloadFileInfo->file;
                if (file->isOpen()) {
                    file->close();
                }
                delete file;
                //第三步
                delete downloadFileInfo;

            }
        //}
    }
}

void DownloadTask::clearList()
{

}
