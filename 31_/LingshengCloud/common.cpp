#include "common.h"
#include <QCryptographicHash>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMap>
#include <QFile>
#include <QDebug>

Common* Common::m_instance = new Common;

Common::Common()
{
    m_manager = new QNetworkAccessManager();
    getFileTypeList();
}

Common* Common::getInstance()
{
    return m_instance;
}

//从配置文件中得到对应的参数值
QString Common::getConfValue(QString title, QString key, QString path)
{
    QFile file(path);
    if (false == file.open(QIODevice::ReadOnly)) {
        //打开失败
        qDebug() << "打开conf.json文件失败";
        return "";
    }

    QByteArray json = file.readAll();//读取文件所有数据
    file.close(); //文件关闭

    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(json, &err);
    if (err.error == QJsonParseError::NoError) {
        //没有出错
        if (doc.isNull() || doc.isEmpty()) {
            qDebug() << "doc is null or doc is empty";
            return "";
        }

        if (doc.isObject()) {
           QJsonObject rootObj =  doc.object();
           QJsonValue titleValue = rootObj.value(title);

           /***
                检查从标题值中获取的 JSON 值是否为 JSON 对象。如果是 JSON 对象，就会执行以下代码块。
           ***/

           if (titleValue.type() == QJsonValue::Object) {
               QJsonObject titleObj = titleValue.toObject();

               QStringList list = titleObj.keys();
               for (int i=0;i<list.size();i++) {

                   /***
                    * 获取循环中当前迭代的键
                    * 检查当前键是否与传入的 key 参数匹配。
                    * 如果找到匹配的键，从标题对象中获取对应的值，并将其转换为字符串后返回。
                    * ***/


                   QString keyTemp = list.at(i);
                   if (keyTemp == key) {
                        return titleObj.value(key).toString();
                   }
               }

           }

        }

    } else {
        qDebug() << "err = " << err.errorString();
    }

    return "";
}

void Common::writeLoginInfo(QString user, QString pwd, bool isRemeber, QString path)
{
    //web_server
    QString ip = getConfValue("web_server", "ip");
    QString port = getConfValue("web_server", "port");
    qDebug() << "ip:" << ip << ",port:" << port;
    QMap<QString, QVariant> web_server;
    web_server.insert("ip", ip);
    web_server.insert("port", port);

    //login

    //做两次加密
    //1. 进行des加密
    //2. 进行base64加密

    //第一步：进行des加密
    //用户名
    unsigned char encUsr[1024] = {0};
    int encUsrLen;

    //toLocal8Bit，转换为本地字符集, 如果是windows则为gbk编码, 如果linux则为utf-8
    int ret = DesEnc((unsigned char*)user.toLocal8Bit().data(),user.toLocal8Bit().length(),
        encUsr, &encUsrLen);
    if (ret != 0) {
        //加密失败
        qDebug() << "DesEnc 加密用户名失败";
        return;
    }

    //密码
    unsigned char encPwd[1024] = {0};
    int encPwdLen;
    ret = DesEnc((unsigned char*)pwd.toLocal8Bit().data(),pwd.toLocal8Bit().length(),
        encPwd, &encPwdLen);
    if (ret != 0) {
        //加密失败
        qDebug() << "DesEnc 加密密码失败";
        return;
    }

    //第二步: 进行base64加密
    QString base64User = QByteArray((char *)encUsr, encUsrLen).toBase64();
    QString base64Pwd = QByteArray((char *)encPwd, encPwdLen).toBase64();

    QMap<QString, QVariant> login;
    login.insert("pwd", base64Pwd);
    login.insert("user", base64User);
    if (isRemeber == true) {
        login.insert("remember", CONF_REMEBER_YES);
    } else {
        login.insert("remember", CONF_REMEBER_NO);
    }
   //QString ip1 = getConfValue("web_server","ip");
   
    
    QMap<QString, QVariant> json;
    json.insert("login", login);
    json.insert("web_server", web_server);

    QJsonDocument jsonDocument = QJsonDocument::fromVariant(json);
    if (jsonDocument.isNull() == true) {
        qDebug() << "QJsonDocument::fromVariant错误";
        return;
    }

    //保存到文件
    QFile file(path);
    if (false == file.open(QIODevice::WriteOnly)) {
        qDebug() << "文件打开失败";
    } else {
        file.write(jsonDocument.toJson());
        file.close();
    }

}

// 服务器信息，写入配置文件
void Common::writeWebInfo(QString ip, QString port, QString path)
{
    // web_server信息
    QMap<QString, QVariant> web_server;
    web_server.insert("ip", ip);
    web_server.insert("port", port);

    // login信息
    QString user = getConfValue("login", "user");
    QString pwd = getConfValue("login", "pwd");
    QString remember = getConfValue("login", "remember");

    QMap<QString, QVariant> login;
    login.insert("user", user);
    login.insert("pwd", pwd);
    login.insert("remember", remember);


    QMap<QString, QVariant> json;
    json.insert("web_server", web_server);
    json.insert("login", login);

    QJsonDocument jsonDocument = QJsonDocument::fromVariant(json);
    if ( jsonDocument.isNull() == true)
    {
        qDebug() << "QJsonDocument::fromVariant错误";
        return;
    }


    QFile file(path);
    qDebug() <<path;
    if (false == file.open(QIODevice::WriteOnly) )
    {
        qDebug() << "file open err";
        return;
    }


    file.write(jsonDocument.toJson());
    file.close();
}

QString Common::getStrMd5(QString str)
{
    QByteArray arr;
    arr = QCryptographicHash::hash(str.toLocal8Bit(), QCryptographicHash::Md5);

    return arr.toHex();
}
QNetworkAccessManager* Common::getNetworkAccessManager()
{

    return m_manager;
}

void Common::getFileTypeList()
{
    QDir dir(FILE_TYPE_DIR);
    if(!dir.exists()){
        dir.mkpath(FILE_TYPE_DIR);
        qDebug()<<FILE_TYPE_DIR<<"创建成功";
    }
    /*
            QDir::Dirs      列出目录；
            QDir::AllDirs   列出所有目录，不对目录名进行过滤；
            QDir::Files     列出文件；
            QDir::Drives    列出逻辑驱动器名称，该枚举变量在Linux/Unix中将被忽略；
            QDir::NoSymLinks        不列出符号链接；
            QDir::NoDotAndDotDot    不列出文件系统中的特殊文件.及..；
            QDir::NoDot             不列出.文件，即指向当前目录的软链接
            QDir::NoDotDot          不列出..文件；
            QDir::AllEntries        其值为Dirs | Files | Drives，列出目录、文件、驱动器及软链接等所有文件；
            QDir::Readable      列出当前应用有读权限的文件或目录；
            QDir::Writable      列出当前应用有写权限的文件或目录；
            QDir::Executable    列出当前应用有执行权限的文件或目录；
            Readable、Writable及Executable均需要和Dirs或Files枚举值联合使用；
            QDir::Modified      列出已被修改的文件，该值在Linux/Unix系统中将被忽略；
            QDir::Hidden        列出隐藏文件；
            QDir::System        列出系统文件；
            QDir::CaseSensitive 设定过滤器为大小写敏感。
        */

    dir.setFilter(QDir::Files|QDir::NoDot|QDir::NoDot|QDir::NoDotAndDotDot | QDir::NoSymLinks);
    dir.setSorting(QDir::Size);
    //遍历文件夹(conf/fileType)
    QFileInfoList fileInfoList = dir.entryInfoList();
    for(int i=0;i<fileInfoList.size();i++){
        QFileInfo fileInfo = fileInfoList.at(i);
        m_fileTypeList.append(fileInfo.fileName());
    }
}


//根据文件名，从m_fileTypeList查找，如果能找到，返回此类型，如果不能找到,返回other.png
//fileTypeName  cpp.png/dll.png

QString Common::getFileType(QString fileTypeName)
{
    if(m_fileTypeList.contains(fileTypeName)){
        //如果能找到
        return fileTypeName;
    }else {
        return "other.png";
    }
}

QString Common::getFileMd5(QString filePath)
{
    QFile localFile(filePath);

    if (!localFile.open(QFile::ReadOnly))
    {
        qDebug() << "file open error.";
        return 0;
    }

    QCryptographicHash ch(QCryptographicHash::Md5);

    quint64 totalBytes = 0;
    quint64 bytesWritten = 0;
    quint64 bytesToWrite = 0;
    quint64 loadSize = 1024 * 4;
    QByteArray buf;

    totalBytes = localFile.size();
    bytesToWrite = totalBytes;

    while (1)
    {
        if(bytesToWrite > 0)
        {
            buf = localFile.read(qMin(bytesToWrite, loadSize));
            ch.addData(buf);
            bytesWritten += buf.length();
            bytesToWrite -= buf.length();
            buf.resize(0);
        }
        else
        {
            break;
        }

        if(bytesWritten == totalBytes)
        {
            break;
        }
    }

    localFile.close();
    QByteArray md5 = ch.result();
    return md5.toHex();
}
QString Common::getBoundary()
{
    //随机生成16个字符
    char randoms[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    //随机种子
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    QString temp;
    int len = strlen(randoms);
    for(int i = 0;i<16;i++){
        int rand = qrand()%len;
        temp [i] = randoms[rand];
    }
    qDebug()<<"temp:"<<temp;
    QString boundary = "------WebKitFormBoundary" + temp;
    return boundary;

}
