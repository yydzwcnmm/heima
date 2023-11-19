#include "myfilewidget.h"
#include "ui_myfilewidget.h"

MyFileWidget::MyFileWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyFileWidget)
{
    ui->setupUi(this);
    initListWidget();
    addMenu();
    //getNetworkAccessManager()!!!!
    //m_manager = Common::getInstance()->getNetworkAccessManager();

}

MyFileWidget::~MyFileWidget()
{
    delete ui;
}


void MyFileWidget::initListWidget()
{

    m_common = Common::getInstance();
    m_loginInfo = LoginInfoInstance::getInstance();

    ui->listWidget->setViewMode(QListView::IconMode);
    ui->listWidget->setIconSize(QSize(80,80));
    ui->listWidget->setGridSize(QSize(100,200));
    //ui->listWidget->addItem(new QListWidgetItem(QIcon("conf/fileType/jpg.png"),"图标1"));
    //ui->listWidget->addItem(new QListWidgetItem(QIcon("D:/+/++/kl/heima/31_/LingshengCloud/conf/fileType/eps.png"), "图标1"));
    ui->listWidget->addItem(new QListWidgetItem(QIcon(":conf/fileType/css.png"), "图标2"));
    //设置QListView大小改变时，图标的调整模式, 默认时固定的，可以改成自动调整
    ui->listWidget->setResizeMode(QListView::Adjust);//自适应布局
    //设置图标拖动状态，QListView::Static表示不可拖动
    ui->listWidget->setMovement(QListView::Static);
    //listWidget右键菜单
    //发出QWidget::customContextMenuRequested() 信号
    ui->listWidget->setContextMenuPolicy(Qt::CustomContextMenu);

    connect(ui->listWidget,&QListWidget::customContextMenuRequested,this,&MyFileWidget::onRightMenu);
}

/***
 * QListWidgetItem *item = ui->listWidget->itemAt(pos);：这一行代码通过 itemAt 方法获取
 * 了鼠标点击位置 pos 处对应的 QListWidgetItem 对象。
 * 如果鼠标点击的位置没有对应的列表项，item 将会是一个空指针（NULL）。
 * ***/
//显示右键菜单
    void MyFileWidget::onRightMenu(const QPoint &pos)
 {
    qDebug()<<"显示右键菜单信号接收" ;
    QListWidgetItem *item = ui->listWidget->itemAt(pos);
    if(item ==NULL){
        qDebug() << "NULL";
        m_menuEmpty->exec(QCursor::pos()); //QCursor::pos() 鼠标当前位置
    }else{
        //点击了图标
         qDebug() << "clieck";
         if(item->text() == "上传文件"){
             return;
         }
         m_menuItem->exec(QCursor::pos()); //QCursor::pos() 鼠标当前位置
    }

 }

void MyFileWidget::addMenu()
{
    //点击item显示的菜单
    m_menuItem = new MyMenu(this);
    m_actionDownload = new QAction("下载" ,this);
    m_actionShare = new QAction("分享",this);
    m_actionDelete = new QAction("删除",this);
    m_actionProperty = new QAction("属性",this);

    m_menuItem->addAction(m_actionDownload);
    m_menuItem->addAction(m_actionShare);
    m_menuItem->addAction(m_actionDelete);
    m_menuItem->addAction(m_actionProperty);

    //点击空白位置显示的菜单
    m_menuEmpty = new MyMenu(this);
    m_actionDownloadAsc = new QAction("按下载量升序", this);
    m_actionDownloadDesc = new QAction("按下载量降序", this);
    m_actionRefresh = new QAction("刷新", this);
    m_actionUpload = new QAction("上传", this);

    m_menuEmpty->addAction(m_actionDownloadAsc);
    m_menuEmpty->addAction(m_actionDownloadDesc);
    m_menuEmpty->addAction(m_actionRefresh);
    m_menuEmpty->addAction(m_actionUpload);

    menuActions();
}

void MyFileWidget::menuActions()
{
    //点击item显示的菜单
    connect(m_actionDownload,&QAction::triggered,this,[=](){
        qDebug()<<"下载";
    });
    connect(m_actionShare,&QAction::triggered,this,[=](){
        qDebug()<<"分享";
        dealfile("share");
    });
    connect(m_actionDelete,&QAction::triggered,this,[=](){
        qDebug()<<"删除";
        dealfile("delete");
    });
    connect(m_actionProperty,&QAction::triggered,this,[=](){
        qDebug()<<"属性";
        dealfile("property");
    });

    //点击空白位置显示的菜单
    connect(m_actionDownloadAsc,&QAction::triggered,this,[=](){
        qDebug()<<"按下载量升序";
        getMyFileCount(Asc);
    });
    connect(m_actionDownloadDesc,&QAction::triggered,this,[=](){
        qDebug()<<"按下载量降序";
        getMyFileCount(Desc);
    });
    connect(m_actionRefresh,&QAction::triggered,this,[=](){
        qDebug()<<"刷新";
        getMyFileCount(Normal);
    });
    connect(m_actionUpload,&QAction::triggered,this,[=](){
        qDebug()<<"上传";
    });

}
//获取用户文件数量
void MyFileWidget::getMyFileCount(MyFileDisplay cmd)
{

/***
    QNetworkRequest request; //栈
    QString ip = m_common->getConfValue("web_server", "ip");
    QString port = m_common->getConfValue("web_server", "port");
     qDebug() << "1.1" ;
    //http://192.168.52.139/myfiles?cmd=count
    //QString url = QString("http://%1:%2/login").arg(ip).arg(port);

    QString url = QString("http://%1:%2/myfiles?cmd=count").arg(ip).arg(port);
    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json"));
    QJsonObject paramsObj;
    qDebug() << "1.2" ;
    paramsObj.insert("user", m_loginInfo->user());
    paramsObj.insert("token", m_loginInfo->token());
    QJsonDocument doc(paramsObj);
    QByteArray data = doc.toJson();
    qDebug() << "1.3" ;
    QNetworkReply *reply = m_manager->post(request, data);
    qDebug() << "2" ;

    ****/
    QNetworkRequest request; //栈
    QString ip = m_common->getConfValue("web_server", "ip");
    QString port = m_common->getConfValue("web_server", "port");
    //m_manager = new QNetworkAccessManager(this);
    m_manager = m_common->getNetworkAccessManager();
    //http://192.168.52.139/myfiles?cmd=count
    QString url = QString("http://%1:%2/myfiles?cmd=count").arg(ip).arg(port);
    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json"));

    QJsonObject paramsObj;
    paramsObj.insert("user", m_loginInfo->user());
    paramsObj.insert("token", m_loginInfo->token());
    QJsonDocument doc(paramsObj);

    QByteArray data = doc.toJson();

    QNetworkReply *reply = m_manager->post(request, data);


    //读取服务器返回的数据
    connect(reply, &QNetworkReply::readyRead, this, [=](){
        //读数据
        QByteArray data = reply->readAll();
       // qDebug() << "服务器返回数据:" << QString(data);

                QStringList list = NetworkData::getFileCount(data);
        if(!list.isEmpty()){
            QString code = list.at(0);
            if(code == "110"){   //成功
                m_myFilesCount = list.at(1).toInt();
                qDebug() << "m_myFilesCount:" << m_myFilesCount;
            }else if(code == "111") {
                QMessageBox::critical(this,"账号异常", "请重新登录");
                emit sigLoginAgain();
                return ;
            }
        }

        if(m_myFilesCount>0){
            //请求用户文件信息
            getMyFileList(Normal);
        }else {
            //用户文件数量等于0

        }

        //立即销毁
        //delete reply;
        //延迟销毁,
        //调用QObject::deleteLater并没有立即校徽，而是向主消息循环发送了一个event,
        //下一次主循环收到这个event之后才会销毁对象。
        reply->deleteLater();

    });
}

void MyFileWidget::addUploadItem()
{
    QString filePath = QString(":/images/main/upload.png");
    ui->listWidget->addItem(new QListWidgetItem(QIcon(filePath), QString("上传文件")));
}


void MyFileWidget::getMyFileList(MyFileDisplay cmd)
{

    QString strCmd;
    if(cmd == MyFileDisplay::Normal){
        strCmd = "normal";
    }
    if(cmd == MyFileDisplay::Desc){
        strCmd = "pvdesc";
    }
    if(cmd == MyFileDisplay::Asc){
        strCmd = "pvasc";
    }
    qDebug()<<"IN getMyFileList "<<strCmd;

    QNetworkRequest request; //栈
    QString ip = m_common->getConfValue("web_server", "ip");
    QString port = m_common->getConfValue("web_server", "port");
    m_manager = m_common->getNetworkAccessManager();
    //http://192.168.52.139/myfiles?cmd=normal
    //http://192.168.52.139/myfiles?cmd=asc
    //http://192.168.52.139/myfiles?cmd=pvasc
    QString url = QString("http://%1:%2/myfiles?cmd=%3").arg(ip).arg(port).arg(strCmd);
    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json"));

    QJsonObject paramsObj;
    paramsObj.insert("user", m_loginInfo->user());
    paramsObj.insert("token", m_loginInfo->token());
    QJsonDocument doc(paramsObj);
    QByteArray data = doc.toJson();
    QNetworkReply *reply = m_manager->post(request, data);
/***
    "files": [{
    "user": "milo",
    "md5": "a89390d867d5da18c8b1a95908d7c653",
    "create_time": "2020-07-04 14:26:41",
    "file_name": "ui_buttongroup.h",
    "share_status": 1,
    "pv": 0,
    "url": "http://172.16.0.15:80/group1/M00/00/00/rBAAD18AISGAP6QrAAACRhizVvQ79062.h",
    "size": 582,
    "type": "h"
    }]
 ***/




    //读取服务器返回的数据
    connect(reply, &QNetworkReply::readyRead, this, [=](){
        //读数据
        QByteArray data = reply->readAll();


        qDebug() << "服务器返回数据:" << QString(data);
        qDebug() << "/////////";
        //清空m_fileList
        clearFileList();
        m_fileList = NetworkData::getFileInfo(data);

        //清空ui->listWidget中items
        clearItems();

        //在ui->listWidget显示图标
        showFileItems();

        //立即销毁
        //delete reply;
        //延迟销毁,
        //调用QObject::deleteLater并没有立即校徽，而是向主消息循环发送了一个event,
        //下一次主循环收到这个event之后才会销毁对象。
        reply->deleteLater();
    });

}

void MyFileWidget::showFileItems()
{

    for(int i=0;i<m_fileList.length();i++)
    {
        FileInfo *fileInfo = m_fileList.at(i);
        QString fileTypeName = QString("%1.png").arg(fileInfo->type);
        QString fileTypeName2 = m_common->getFileType(fileTypeName);
        qDebug() << "showFileItems fileTypeName2 1:" << fileTypeName2;
        QString filePath = QString("%1/%2").arg(FILE_TYPE_DIR).arg(fileTypeName2);
        //添加items(图片/文字)到listWidget
        ui->listWidget->addItem(new QListWidgetItem(QIcon(filePath), fileInfo->fileName));
        qDebug() << "filePath:" << filePath;
    }
    //添加上传文件图标
    this->addUploadItem();
}

void MyFileWidget::clearFileList()
{
    int size = m_fileList.size();
    for(int i=0;i<size;i++)
    {
        FileInfo *temp = m_fileList.takeFirst();
        if(temp != nullptr){
            delete temp;
        }
    }
}

void MyFileWidget::clearItems()
{
    int count = ui->listWidget->count();
    for (int i=0;i<count;i++){
        QListWidgetItem *item = ui->listWidget->takeItem(0);
        if(item!=nullptr){
            delete item;
        }
    }
}

//分享文件 删除文件接口函数
void MyFileWidget::dealfile(QString cmd)
{
    //获取当前选中的item
    QListWidgetItem *item = ui->listWidget->currentItem();
    if(item == NULL){
        qDebug()<<"选中item NULL";
        return;
    }
    for(int i=0;i<m_fileList.length();i++){
        FileInfo *fileInfo = m_fileList.at(i);
        qDebug() << "fileInfo->fileName:" << fileInfo->fileName << "   item->text():" << item->text();
        if(fileInfo->fileName == item->text()){
            //分享文件
            if(cmd == "share"){
                //分享文件
                shareFile(fileInfo);
            }
            if(cmd == "delete"){
                //删除文件
                deleteFile(fileInfo);
            }
            if(cmd == "property"){
                //显示文件信息
                showFileProperty(fileInfo);
            }
        }
    }
}


//分享文件
void MyFileWidget::shareFile(FileInfo *fileInfo)
{
    qDebug() << " in shareFile";
    QNetworkRequest request;
    QString ip = m_common->getConfValue("web_server", "ip");
    QString port = m_common->getConfValue("web_server", "port");
    //http://192.168.52.139/dealfile?cmd=share
    QString url = QString("http://%1:%2/dealfile?cmd=share").arg(ip).arg(port);
    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json"));

    QJsonObject paramsObj;
    paramsObj.insert("user", m_loginInfo->user());
    paramsObj.insert("token", m_loginInfo->token());
    paramsObj.insert("filename",fileInfo->fileName);
    paramsObj.insert("md5",fileInfo->md5);
    QJsonDocument doc(paramsObj);
    QByteArray data = doc.toJson();
    //qDebug() << " in QByteArray data = doc.toJson(); ";
    QNetworkReply *reply = m_manager->post(request, data);
    //读取服务器返回的数据
    connect(reply, &QNetworkReply::readyRead, this, [=](){
        //读数据
        //qDebug() << " in 读取服务器返回的数据 ";
        QByteArray data = reply->readAll();
        qDebug() << "服务器返回数据:" << QString(data);
        QString code = NetworkData::getCode(data);
/*
        010： 成功
        011： 失败
        012： 别人已经分享此文件
        013： token验证失败
*/
        if(code=="010"){//成功
            fileInfo->shareStatus = 1;
            QMessageBox::information(this, "分享成功", QString("【%1】分享成功!").arg(fileInfo->fileName));
        }
        if(code=="011"){
            QMessageBox::warning(this, "分享失败", QString("【%1】分享失败!").arg(fileInfo->fileName));
        }
        if(code=="012"){
            QMessageBox::warning(this, "分享失败", QString("【%1】别人已经分享此文件!").arg(fileInfo->fileName));
        }
        if(code=="013"){
            QMessageBox::critical(this, "账号异常", "请重新登录");
            emit sigLoginAgain();
            return;
        }
         delete reply;
    });
}

//文件删除
void MyFileWidget::deleteFile(FileInfo *fileInfo)
{
    qDebug() << " in deleteFile(FileInfo *fileInfo) ";
    QNetworkRequest request;
    QString ip = m_common->getConfValue("web_server", "ip");
    QString port = m_common->getConfValue("web_server", "port");

    //http://192.168.52.139/dealfile?cmd=del
    QString url = QString("http://%1:%2/dealfile?cmd=del").arg(ip).arg(port);
    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json"));

/*
{
    "filename": "Makefile",
    "md5": "602fdf30db2aacf517badf4565124f51",
    "token": "ecf3ac6f8863cd17ed1d3909c4386684",
    "user": "milo"
}
*/
    QJsonObject paramsObj;
    paramsObj.insert("user", m_loginInfo->user());
    paramsObj.insert("token", m_loginInfo->token());
    paramsObj.insert("filename", fileInfo->fileName);
    paramsObj.insert("md5", fileInfo->md5);
    QJsonDocument doc(paramsObj);

    QByteArray data = doc.toJson();
    QNetworkReply *reply = m_manager->post(request, data);
    qDebug() << " in  QNetworkReply *reply = m_manager->post(request, data); ";
    //读取服务器返回的数据
    connect(reply, &QNetworkReply::readyRead, this, [=](){
            //读数据
        qDebug() << " in  connect(reply, &QNetworkReply::readyRead, this, [=](){ ";
        QByteArray data = reply->readAll();
        qDebug() << "服务器返回数据:" << QString(data);
        QString code = NetworkData::getCode(data);
        if (code == "014") {  //失败
               QMessageBox::warning(this, "文件删除失败", QString("【%1】文件删除失败!").arg(fileInfo->fileName));
        }else if(code == "013"){
               QMessageBox::information(this, "文件删除成功", QString("【%1】文件删除成功!").arg(fileInfo->fileName));
               for(int i=0;i<m_fileList.size();i++){
                   if(m_fileList.at(i)->fileName==fileInfo->fileName){
                       //获取对应的 listWidget
                       for(int k = 0;k<ui->listWidget->count();k++){
                           QListWidgetItem *item = ui->listWidget->item(k);
                           if(item->text()==fileInfo->fileName){
                               //删除listWidget上的图标
                               ui->listWidget->removeItemWidget(item);
                                delete item;
                               break;
                           }
                       }
                    m_fileList.removeAt(i);
                    free(fileInfo);
                    //delete reply;
                    break;
                   }
               }
        }
         delete reply;
    });
    //delete reply;
}

void MyFileWidget::showFileProperty(FileInfo *fileInfo)
{
    //显示文件信息
    FilePropertyInfoDialog dlg;
    dlg.setFileInfo(fileInfo);
    dlg.exec();
    //通过模态对话框显示
}


