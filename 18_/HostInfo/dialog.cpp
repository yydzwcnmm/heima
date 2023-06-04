#include "dialog.h"
#include "ui_dialog.h"
#include <QMetaEnum>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

// "QHostInfo 获取本机主机名和IP地址"
void Dialog::on_btnGetLocalHostInfo_clicked()
{
    QString localName = QHostInfo::localHostName(); // 本机主机名
    ui->plainTextEdit->appendPlainText("本地主机名" + localName+ "\n");
    QHostInfo hostInfo = QHostInfo::fromName(localName);    // 本机主机信息
    QList<QHostAddress> addrList = hostInfo.addresses();    // 获取本机地址信息列表
    if(!addrList.isEmpty()){
        for(int i = 0;i<addrList.count();i++)
        {
            QHostAddress addr = addrList.at(i); // 每一项是一个QHostAddress对象
            bool ipv4ShowOnly = ui->ckbIPv4Only->isChecked();
            bool isIPv4 = addr.protocol() == QAbstractSocket::IPv4Protocol;  //bool isIPv4 = addr.protocol() == QAbstractSocket::IPv4Protocol; 这行代码检查 QHostAddress 对象 addr 的协议是否为 IPv4。它将比较的结果赋值给布尔变量 isIPv4。
            if(ipv4ShowOnly&&isIPv4){
                ui->plainTextEdit->appendPlainText("协议：" +protocolName(addr.protocol()) );
                ui->plainTextEdit->appendPlainText("IP地址" + addr.toString());
                ui->plainTextEdit->appendPlainText("\n");
            }
            if(!ipv4ShowOnly){
                ui->plainTextEdit->appendPlainText("协议：" +protocolName(addr.protocol()) );
                ui->plainTextEdit->appendPlainText("IP地址" + addr.toString());
                ui->plainTextEdit->appendPlainText("\n");
            }

        }
    }
    
}

QString Dialog::protocolName(QAbstractSocket::NetworkLayerProtocol protocol)
{
    QMetaEnum mateEnum = QMetaEnum::fromType<QAbstractSocket::NetworkLayerProtocol>();
    return mateEnum.valueToKey(protocol);
}

    // 查找主机信息的槽函数
void Dialog::on_btnGetDomainHostInfo_clicked()
{
    QString hostName = ui->editDomainName->text();
    ui->plainTextEdit->appendPlainText("查找主机信息  "+ hostName);
    QHostInfo::lookupHost(hostName,this,SLOT(lookedUp(QHostIfo)));  //使用 QHostInfo 类的 lookupHost 静态函数查询指定主机名的主机信息。这个函数会发送一个异步请求来获取主机信息。第一个参数是要查询的主机名，第二个参数是发送请求的对象（this 表示当前对象），第三个参数是槽函数（lookedUp(QHostInfo)）的指针，用于在查询完成后接收和处理结果。
    //注意：在这段代码中，槽函数 lookedUp(QHostInfo) 应该在相同的类中定义，用于处理查询结果。

}

void Dialog::lookedUp(const QHostInfo& hostInfo)
{


    QList<QHostAddress> addrList = hostInfo.addresses();
    if(!addrList.isEmpty()){
        for(int i = 0;i<addrList.count();i++)
        {
            QHostAddress addr = addrList.at(i); // 每一项是一个QHostAddress对象
            bool ipv4ShowOnly = ui->ckbIPv4Only->isChecked();
            bool isIPv4 = addr.protocol() == QAbstractSocket::IPv4Protocol;  //bool isIPv4 = addr.protocol() == QAbstractSocket::IPv4Protocol; 这行代码检查 QHostAddress 对象 addr 的协议是否为 IPv4。它将比较的结果赋值给布尔变量 isIPv4。
            if(ipv4ShowOnly&&isIPv4){
                ui->plainTextEdit->appendPlainText("协议：" +protocolName(addr.protocol()) );
                ui->plainTextEdit->appendPlainText("IP地址" + addr.toString());
                ui->plainTextEdit->appendPlainText("\n");
            }
            if(!ipv4ShowOnly){
                ui->plainTextEdit->appendPlainText("协议：" +protocolName(addr.protocol()) );
                ui->plainTextEdit->appendPlainText("IP地址" + addr.toString());
                ui->plainTextEdit->appendPlainText("\n");
            }

          }
        }
}

void Dialog::on_btnTextClear_clicked()
{
     ui->plainTextEdit->clear();
}

void Dialog::on_btnAllAddresses_clicked()
{
    QList<QHostAddress>addrList = QNetworkInterface::allAddresses();
    if(!addrList.isEmpty()){
        for(int i = 0;i<addrList.count();i++)
        {
            QHostAddress addr = addrList.at(i); // 每一项是一个QHostAddress对象
            bool ipv4ShowOnly = ui->ckbIPv4Only->isChecked();
            bool isIPv4 = addr.protocol() == QAbstractSocket::IPv4Protocol;  //bool isIPv4 = addr.protocol() == QAbstractSocket::IPv4Protocol; 这行代码检查 QHostAddress 对象 addr 的协议是否为 IPv4。它将比较的结果赋值给布尔变量 isIPv4。
            if(ipv4ShowOnly&&isIPv4){
                ui->plainTextEdit->appendPlainText("协议：" +protocolName(addr.protocol()) );
                ui->plainTextEdit->appendPlainText("IP地址" + addr.toString());
                ui->plainTextEdit->appendPlainText("\n");
            }
            if(!ipv4ShowOnly){
                ui->plainTextEdit->appendPlainText("协议：" +protocolName(addr.protocol()) );
                ui->plainTextEdit->appendPlainText("IP地址" + addr.toString());
                ui->plainTextEdit->appendPlainText("\n");
            }
    }
  }
}

void Dialog::on_btnAllInterfaces_clicked()
{
    QList<QNetworkInterface> interfaceList = QNetworkInterface::allInterfaces(); // 网络接口列表
    if(interfaceList.isEmpty())
        return;
    for(int i=0;i<interfaceList.count();i++){
        QNetworkInterface interface = interfaceList.at(i);
        if(!interface.isValid())
            continue;
        ui->plainTextEdit->appendPlainText("设备名称：" + interface.humanReadableName());
        ui->plainTextEdit->appendPlainText("硬件地址：" + interface.hardwareAddress());
        QList<QNetworkAddressEntry> entryList = interface.addressEntries();
        for(int j=0;j<entryList.count();j++){
            QNetworkAddressEntry entry = entryList.at(j);
            ui->plainTextEdit->appendPlainText("  IP地址：" + entry.ip().toString());
            ui->plainTextEdit->appendPlainText("  广播地址：" + entry.broadcast().toString());
            ui->plainTextEdit->appendPlainText("  子网掩码：" + entry.netmask().toString()+"\n");
        }
        ui->plainTextEdit->appendPlainText("\n");
    }
}
