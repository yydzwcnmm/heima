#include "logindialog.h"
#include "ui_logindialog.h"
#include <QPainter>
#include <QDebug>
#include <QRegExp>


LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    //去掉标题栏
    this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    //如果设置了样式表，则不生效
    //this->setFont可以设置当前窗口所有的字体，loginDialog窗口中的所有控件都生效
    m_common = Common::getInstance();
    this->setFont(QFont("楷体", 12, QFont::Bold, false));

    QObject::connect(ui->title_widget, &TitleWidget::showSetPage, this, &LoginDialog::onshowSetPage);
    QObject::connect(ui->title_widget, &TitleWidget::closeButton, this, &LoginDialog::oncloseButton);
    ui->stackedWidget->setCurrentIndex(0);

    //不需要指定父窗口
    m_mainwindow = new MainWindow;
    m_mainwindow->setWindowIcon(QIcon(":/images/logo.ico"));

    //读取cfg.json文件
    readConf();
    serverSet();

    connect(m_mainwindow,&MainWindow::sigChangeUser,this,[=](){
                m_mainwindow->hide();
                this->show();
              }
            );
    connect(m_mainwindow,&MainWindow::sigLoginAgain,this,[=](){
               //重新登录
        m_mainwindow->hide();
        this->show();
    });
}

void LoginDialog::onshowSetPage()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void LoginDialog::oncloseButton()
{
    if(ui->stackedWidget->currentIndex() == 0){
        this->close();
    }else {
        ui->stackedWidget->setCurrentIndex(0);
   }

}


LoginDialog::~LoginDialog()
{
    //delete loginInfo;
    //delete m_common;
    delete ui;
    //delete loginInfo;
    //delete m_common;

}


void LoginDialog::on_notReg_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void LoginDialog::on_login_clicked()
{
    QString username = ui->username->text();
    QString password = ui->password->text();
    QRegExp regexp(USER_REG );
    if(!regexp.exactMatch(username)){
       //校验失败
        QMessageBox::warning(this,"警告", "用户名格式不正确");
        ui->username->clear();
        ui->username->setFocus();
        return;
    }
    regexp.setPattern(PASSWD_REG);
    if(!regexp.exactMatch(password)){
        //校验失败
        QMessageBox::warning(this,"警告", "密码格式不正确");
        ui->password->clear();
        ui->password->setFocus();
        return;
    }
    QMessageBox::information(this, "提示", "用户名和密码格式正确");

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkRequest request; //栈
    QString ip = m_common->getConfValue("web_server","ip");
    QString port = m_common->getConfValue("web_server","port");
    QString url = QString("http://%1:%2/login").arg(ip).arg(port);
    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json"));
    QJsonObject paramsObj;
    paramsObj.insert("user", username);
    paramsObj.insert("pwd", m_common->getStrMd5(password));
    QJsonDocument doc(paramsObj);
    QByteArray data = doc.toJson();
    QNetworkReply *reply = manager->post(request,data);

    //读取服务器返回的数据
    connect(reply,&QNetworkReply::readyRead,this,[=]{
           //读数据
        qDebug() << "收到数据";
        QByteArray data = reply->readAll();
        qDebug() << "服务器返回数据:" << QString(data);
        //解析返回数据
        QJsonParseError err;
        QJsonDocument rootDoc = QJsonDocument::fromJson(data,&err);
        if(err.error != QJsonParseError::NoError){
            qDebug() << "Json格式错误 on_btn_reg_clicked()";
        }else {
                //解析json
                QJsonObject rootObj = rootDoc.object();
                QJsonValue codeValue = rootObj.value("code");
                if(codeValue.type() == QJsonValue::String){
                    QString code = codeValue.toString();
                    if(code == "000"){
                        QMessageBox::information(this,"提示","接收成功");
                       bool isCheck = ui->chk_remeber->isChecked();
                        if(isCheck == false){
                            ui->password->setText("");
                        }
                        //获取Common对象
                        m_common->writeLoginInfo(username,password,isCheck);
                        //跳转到其他页面
                        //获取token
                        QJsonValue tokenValue = rootObj.value("token");
                        saveLoginInfoData(username,tokenValue.toString(),ip,port);
                        //跳到主界面
                        //m_mainwindow->setUser(username);
                        m_mainwindow->show();
                        this->hide();
                        m_mainwindow->init();
                        qDebug()<<"跳到主界面";
                        m_mainwindow->setUser(username);

                    }else if (code == "001") {
                                QMessageBox::critical(this, "错误", "失败");
                                qDebug() << "001格式错误";
                            }
                }
        }


        //立即销毁
        //delete reply;
        //延迟销毁,
        //调用QObject::deleteLater并没有立即校徽，而是向主消息循环发送了一个event,
        //下一次主循环收到这个event之后才会销毁对象。
        reply->deleteLater();


    });






}

void LoginDialog::on_btn_reg_clicked()
{
    //用户注册
    QString username = ui->reg_username->text();
    QString nickname = ui->reg_nickname->text();
    QString pwd = ui->reg_pwd->text();
    QString pwd2 = ui->reg_pwd2->text();
    QString email = ui->reg_email->text();
    QString phone = ui->reg_phone->text();
    //用户名校验
    QRegExp regUserName(USER_REG);
    if(!regUserName.exactMatch(username)){
        QMessageBox::warning(this, "警告", "用户名格式不正确");
        ui->reg_username->clear();
        ui->reg_username->setFocus();
        return ;
    }
    //昵称校验
    QRegExp regNickName(USER_REG);
    if(!regNickName.exactMatch(nickname)){
        QMessageBox::warning(this, "警告", "昵称格式不正确");
        ui->reg_nickname->clear();
        ui->reg_nickname->setFocus();
        return ;
    }
    //phone校验
    QRegExp phonePwd(PHONE_REG);
    if (!phonePwd.exactMatch(phone)) {
        QMessageBox::warning(this, "警告", "电话格式不正确");
        ui->password->clear();
        ui->password->setFocus();
        return;
    }
    //pwd校验
    QRegExp regPwd(PASSWD_REG);
    if(!regPwd.exactMatch(pwd)){
        QMessageBox::warning(this, "警告", "密码格式不正确");
        ui->reg_pwd->clear();
        ui->reg_pwd->setFocus();
    }
    if (pwd != pwd2) {
        QMessageBox::warning(this, "警告", "两次输入的密码不一致");
        ui->reg_pwd2->clear();
        ui->reg_pwd2->setFocus();
        return;
    }

    //email校验
    QRegExp emailPwd(EMAIL_REG);
    if(!emailPwd.exactMatch(email)){
      QMessageBox::warning(this, "警告", "邮箱格式不正确");
      ui->reg_email->clear();
      ui->reg_email->setFocus();
      return ;
    }

    //1. 获取输入框的数据
    //2. 校验数据
    //3. 发送http请求
    //    1). 设置url
    //    2). 设置请求头
    //    3). 封装请求数据(json)
    //    4). 发送请求(get/post/put/delete)
    //    5). 读取服务器返回的数据
    //    6). 解析返回数据
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkRequest request; //栈
    QString ip = m_common->getConfValue("web_server","ip");
    QString port = m_common->getConfValue("web_server", "port");

    QString url = QString("http://%1:%2/reg").arg(ip).arg(port);
    qDebug() << "IP AND PORT" <<ip<<port ;
    qDebug() << "REG URL :" <<url ;

    //QString url = QString("http://192.168.6.194/reg");
    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
    /***
    request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json"));

    这一行代码设置了HTTP请求头部信息。QNetworkRequest::ContentTypeHeader是一个枚举值，
    表示请求头中的Content-Type字段，它用于指示请求体的数据类型。
    "application/json"是一个具体的Content-Type值，表示请求体是JSON格式的数据。
    这里，代码将请求头的Content-Type字段设置为JSON数据格式。

    总体来说，这段代码是用于构建一个带有特定URL和请求头部信息的HTTP请求。
    URL是由ip和port变量构成的，头部信息指定请求体的数据类型为JSON格式。
    ***/

    QJsonObject paramsObj;
    paramsObj.insert("email",email);
    paramsObj.insert("email", email);
    paramsObj.insert("userName", username);
    paramsObj.insert("nickName", nickname);
    paramsObj.insert("phone", phone);
    paramsObj.insert("firstPwd", m_common->getStrMd5(pwd));
    QJsonDocument doc(paramsObj);
    QByteArray data = doc.toJson();
    QNetworkReply *reply = manager ->post(request,data);

    //读取服务器返回的数据
    connect(reply,&QNetworkReply::readyRead,this,[=](){
        //读数据
        QByteArray data = reply->readAll();
        qDebug() << "服务器返回数据:" << QString(data);

        QJsonParseError err;
        //解析返回数据
        QJsonDocument rootDoc = QJsonDocument::fromJson(data,&err);
        if(err.error!=QJsonParseError::NoError){
            qDebug()<<"Json格式错误 on_btn_reg_clicked";
        }else{
            //解析json
            //{\n\t\"code\":\t\"002\"\n}
            QJsonObject rootObj = rootDoc.object();
            QJsonValue codeValue = rootObj.value("code");
            if(codeValue.type() == QJsonValue::String){
                QString code = codeValue.toString();
                //qDebug() << "code:" << code;
                if(code == "002"){
                    QMessageBox::information(this, "提示", "成功");

                }else if (code == "003") {
                    QMessageBox::information(this, "提示", "该用户已存在");
                } else if (code == "004") {
                    QMessageBox::critical(this, "错误", "失败");
                }
                    /***
                     *
                            {
                                "code": "002"
                            }

                     * **/

            }
        }
        //立即销毁
        //delete reply;
        //延迟销毁,
        //调用QObject::deleteLater并没有立即校徽，而是向主消息循环发送了一个event,
        //下一次主循环收到这个event之后才会销毁对象。
        reply->deleteLater();
    });

}
void LoginDialog::on_set_ok_clicked()
{
    //要处理json
    QString ip = ui->server_ip->text();
    QString port = ui->server_port->text();
    // 数据判断
    // 服务器IP
    // \\d 和 \\. 中第一个\是转义字符, 这里使用的是标准正则
    QRegExp regexp(IP_REG);
    if(!regexp.exactMatch(ip))
    {
        QMessageBox::warning(this, "警告", "您输入的IP格式不正确, 请重新输入!");
        return;
    }
    // 端口号
    regexp.setPattern(PORT_REG);
    if(!regexp.exactMatch(port))
    {
        QMessageBox::warning(this, "警告", "您输入的端口格式不正确, 请重新输入!");
        return;
    }

    QMessageBox::information(this, "提示", "设置成功");
    // 将配置信息写入配置文件中
    m_common->writeWebInfo(ip,port);
    // 跳转到登陆界面
    ui->stackedWidget->setCurrentWidget(ui->login_page);

}

void LoginDialog::readConf()
{
    QString user = m_common->getConfValue("login","user");
    QString pwd = m_common->getConfValue("login","pwd");
    QString remeber = m_common->getConfValue("login","remember");
    int ret = 0;
    qDebug()<<"remeber : " << remeber;
    if(remeber == CONF_REMEBER_YES){
        //记住密码
        //对密码信息进行解密
         //1. base64解密

        /***
         * 这里的fromBase64()函数需要一个QByteArray作为参数，
         * 因此你需要将pwd的QString类型转换为字节数组，以便进行Base64解码操作。
         * ***/

        QByteArray pwdTemp = QByteArray::fromBase64(pwd.toLocal8Bit());
        unsigned char encPwd[512] = {0};
        int encPwdLen = 0;
        //第二步:des解密
        ret = DesDec((unsigned char*)pwdTemp.data(),pwdTemp.size(),encPwd,&encPwdLen);
        if(ret != 0){
            qDebug()<< " 解密失败";
        }
        QString password = QString::fromLocal8Bit((const char*)encPwd, encPwdLen);
        qDebug()<<"password : " << password;
        ui->chk_remeber->setChecked(true);
        ui->password->setText(password);
    }else {
            //没有记住密码
        ui->chk_remeber->setChecked(false);
        ui->password->setText("");
            }

    //对账户信息进行解密
    //1. base64解密
    //第二步:des解密
    QByteArray userTemp = QByteArray::fromBase64(user.toLocal8Bit());

    unsigned char encUsr[512] = {0};
    int encUsrLen = 0;
    ret = DesDec((unsigned char*)userTemp.data(), userTemp.size(), encUsr, &encUsrLen);
    if (ret != 0) {
        qDebug() << "解密失败";
    }

    QString userName = QString::fromLocal8Bit((const char*)encUsr, encUsrLen);
    qDebug() << "userName:" << userName;
    ui->username->setText(userName);
}

void LoginDialog::serverSet()
{
    QString ip = m_common->getConfValue("web_server","ip");
    QString port = m_common->getConfValue("web_server","port");
    qDebug()<<"ip : "<<ip<<" ,port" <<port;
    ui->server_ip->setText(ip);
    ui->server_port->setText(port);
}


void LoginDialog::saveLoginInfoData(QString username, QString token, QString ip, QString port)
{
    //跳转到其他页面
    //保存数据, token, user, ip, 端口
    //除了登录外：每一个请求都需要校验token,每一个请求都需要带token
    loginInfo = LoginInfoInstance::getInstance();
    qDebug() << "token:" << token;
    loginInfo->setToken(token);
    loginInfo->setUser(username);
    loginInfo->setIp(ip);
    loginInfo->setPort(port);

}
