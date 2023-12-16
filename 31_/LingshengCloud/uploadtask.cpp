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
    UploadFileInfo *uploadFile = new UploadFileInfo;
    //filePath 文件的路径
    //user=\"%1\" filename=\"%2\" md5=\"%3\" size=%4
    qint64 fileSize = QFileInfo(filePath).size();
    //判断文件的大小， 最大30M
    if(fileSize>30*1024*1024){
       qDebug()<<"文件太大，最大允许上传30M";
        return -1;
    }
    //截取字符串
    qDebug()<<"判断文件的大小---成功";
    int pos = filePath.lastIndexOf("/",-1)+1;
    QString myString = QString::number(pos);
    qDebug()<<"pos ="<<myString;
    qDebug()<<"filePath ="<<filePath;
    uploadFile->fileName = filePath.mid(pos);
    qDebug()<<"uploadFile->fileName ="<<uploadFile->fileName;
    uploadFile->filePath = filePath;
    qDebug()<<"uploadFile->filePath ="<<uploadFile->filePath;
    uploadFile->size = fileSize;
    QString myString2 = QString::number(uploadFile->size);
    qDebug()<<"uploadFile->size ="<<myString2;
    uploadFile->md5 = Common::getInstance()->getFileMd5(filePath);
    //uploadFile->uploadStatus = UP
    //m_fileList保存上传文件的列表
    qDebug()<<"m_fileList保存上传文件的列表---成功";
    m_fileList.append(uploadFile);
    //delete uploadFile;
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
    for (int i=0; i<m_fileList.size(); i++) {
        UploadFileInfo *tmp = m_fileList.at(i);
        if (tmp->uploadStatus == UPLOAD_FINISHED ||
                tmp->uploadStatus == UPLOAD_FAILD ||
                tmp->uploadStatus == UPLOAF_FILE_EXISTE) {
            UploadFileInfo *uploadFileInfo = m_fileList.takeAt(0);
            qDebug()<<" UploadFileInfo *uploadFileInfo = m_fileList.takeAt(0) ";
            if (uploadFileInfo != NULL) {
                //第三步
                delete uploadFileInfo;
                qDebug()<<" 执行delete uploadFileInfo ";
            }
        }
    }
        qDebug()<<"删除已经完成的上传任务 --- 成功";
        if(isEmpty()){
            qDebug()<<"上传列表为空";
        }else {

            qDebug()<<"上传列表不为空";
        }
}

