#include "uploadtask.h"
#include "common.h"

UploadTask* UploadTask::m_instance=new UploadTask;

UploadTask::UploadTask()
{

}

UploadTask* UploadTask::getInstance(){
    return m_instance;
}

//静态数据成员，类中声明，类外必须定义
int UploadTask::appendUploadTask(QString filePath)
{
    //filePath 文件的路径
    //user=\"%1\" filename=\"%2\" md5=\"%3\" size=%4
    qint64 fileSize = QFileInfo(filePath).size();
    //判断文件的大小， 最大30M
    if(fileSize>30*1024*1024){
       qDebug()<<"文件太大，最大允许上传30M";
        return -1;
    }
    //截取字符串
    int pos = filePath.lastIndexOf("/",-1)+1;
    uploadFile->fileName = filePath.mid(pos);
    uploadFile->filePath = filePath;
    uploadFile->size = fileSize;
    uploadFile->md5 = Common::getInstance()->getFileMd5(filePath);
    //uploadFile->uploadStatus = UP
    //m_fileList保存上传文件的列表
    m_fileList.append(uploadFile);
    return 0;
    
}

bool UploadTask::isEmpty() {
    return m_fileList.isEmpty();
}

UploadFileInfo* UploadTask::takeTask()
{
    //取出上传任务列表中 第一个任务信息
    temp = NULL;
    if(m_fileList.size()>0){
        temp = m_fileList.at(0);
        temp->uploadStatus = UPLOADING;
    }
    return temp;
}
void UploadTask::delUploadTask()
{
    //上传完成后需要处理的
    uploadFileInfo = m_fileList.takeAt(0);
    if(uploadFileInfo!=NULL){
        delete uploadFileInfo;
    }

}

