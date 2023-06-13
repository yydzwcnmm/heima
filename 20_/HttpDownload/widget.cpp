#include "widget.h"
#include "ui_widget.h"
#include <QDir>
#include <QMessageBox>
#include <QUrl>
#include <QDesktopServices>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

// "缺省路径"
void Widget::on_btnDefaultPath_clicked()
{
    QString curPath = QDir::currentPath();   //它以 QString 的形式返回当前的工作目录。当前工作目录是程序当前运行的目录。
    QDir dir(curPath);  //创建了一个 QDir 对象 dir，它代表了当前工作目录。现在可以使用 dir 对象执行各种与当前工作目录相关的操作。
    QString sub = "temp";
    dir.mkdir(sub);
    ui->editSavePath->setText(curPath + "/" + sub + "/");
}

// "下载"
void Widget::on_btnDownload_clicked()
{
    QString urlSpec = ui->editURL->text().trimmed();
    if(urlSpec.isEmpty()){
        QMessageBox::critical(this,"下载","请指定要下载的URL");
        return;
    }

    QUrl newUrl = QUrl::fromUserInput(urlSpec); //QUrl 类是 Qt 框架提供的用于处理 URL 的类，可以解析和操作 URL 地址。
    if(!newUrl.isValid()){
        QMessageBox::critical(this,"下载",
                QString("无效URL：%1 \n 错误: %2").arg(urlSpec,newUrl.errorString()));
        return;
    }
    QString tempDir = ui->editSavePath->text().trimmed();
    if(tempDir.isEmpty()){
        QMessageBox::critical(this,"下载","请指定保存下载文件的路径");
        return;
    }
    //目录下存在文件，需要先移除
   QString fullFileName = tempDir + newUrl.fileName();
    if(QFile::exists(fullFileName)){
            QFile::remove(fullFileName);
    }
    /**创建一个QFile对象并尝试以只写模式打开文件。
     * 如果文件打开失败，就会显示一个错误消息框，并终止后续的代码执行。
     * */
    downloadFile = new QFile(fullFileName);
    if(!downloadFile->open(QIODevice::WriteOnly)){
        QMessageBox::critical(this,"下载","临时文件打开失败");
        return;
    }
    ui->btnDownload->setEnabled(false);
    reply = networkManager.get(QNetworkRequest(newUrl));
    connect(reply,SIGNAL(downloadProgress(qint64,qint64)),this,
              SLOT(onDownloadProgress(qint64,qint64)));
    connect(reply,SIGNAL(readyRead()),this,SLOT(onReadyRead()));
    connect(reply,SIGNAL(finished()),this,SLOT(onFinished()));

}
    // 读取下载数据
void Widget::onReadyRead()
{
    downloadFile->write(reply->readAll());

}

// 下载进度
void Widget::onDownloadProgress(qint64 bytesReceived, qint64 bytesTotal)
{
        ui->progressBar->setMaximum(bytesTotal);
        ui->progressBar->setValue(bytesReceived);
}




/***
这段代码使用Qt的信号槽机制建立了与网络请求相关的信号和槽的连接。下面是对每一行代码的解释：

```cpp
connect(reply, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(onDownloadProgress(qint64, qint64)));
```
这行代码将`reply`对象的`downloadProgress`信号连接到当前对象的`onDownloadProgress`槽函数。`downloadProgress`信号在下载进度更新时触发，它带有两个参数：已下载的字节数和总字节数。

```cpp
connect(reply, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
```
这行代码将`reply`对象的`readyRead`信号连接到当前对象的`onReadyRead`槽函数。`readyRead`信号在有可读数据可供读取时触发，可以用于读取服务器发送的数据。

```cpp
connect(reply, SIGNAL(finished()), this, SLOT(onFinished()));
```
这行代码将`reply`对象的`finished`信号连接到当前对象的`onFinished`槽函数。`finished`信号在网络请求完成后触发，表示请求已完成。

这些连接的作用是在网络请求的不同阶段触发相应的信号，然后执行相应的槽函数来处理这些信号。具体来说：

1. 当下载进度更新时，`reply`对象会发出`downloadProgress`信号，触发当前对象的`onDownloadProgress`槽函数进行处理。
2. 当有可读数据可供读取时，`reply`对象会发出`readyRead`信号，触发当前对象的`onReadyRead`槽函数进行处理。
3. 当网络请求完成时，`reply`对象会发出`finished`信号，触发当前对象的`onFinished`槽函数进行处理。

程序的下载执行顺序可能如下：

1. 发送HTTP GET请求并获取到`reply`对象。
2. 开始下载时，根据下载进度更新，触发`onDownloadProgress`槽函数进行处理。
3. 当有可读数据可供读取时，触发`onReadyRead`槽函数进行处理。
4. 网络请求完成时，触发`onFinished`槽函数进行处理。

需要注意的是，这只是一个大致的执行顺序，具体的实现可能会有其他的代码逻辑和异步操作。具体的执行顺序还取决于程序的其他部分和事件循环的处理方式。


这行代码定义了一个名为onDownloadProgress的槽函数，
它接受两个参数：bytesReceived表示已接收的字节数，bytesTotal表示总字节数。
Widget是当前类的名称，假设是继承自QWidget类的自定义窗口类。

这两行代码使用Qt的UI控件来更新进度条的最大值和当前值。ui->progressBar表示名为progressBar的进度条控件，其中ui是指向当前窗口的UI对象的指针。

第一行代码ui->progressBar->setMaximum(bytesTotal);将进度条的最大值设置为bytesTotal，即下载文件的总字节数。这样进度条的最大范围就被设置为文件的大小。

第二行代码ui->progressBar->setValue(bytesReceived);将进度条的当前值设置为bytesReceived，即已接收的字节数。这样进度条的当前值就会随着下载进行而更新。

这段代码的作用是在下载过程中更新进度条的显示，以反映已接收的字节数和总字节数的比例。通过设置进度条的最大值和当前值，用户可以看到下载进度的可视化表示。

**/

// 网络响应结束
void Widget::onFinished()
{
    QFileInfo fileInfo;
    fileInfo.setFile(downloadFile->fileName());
    downloadFile->close();
    delete downloadFile;
    downloadFile = nullptr;
    reply->deleteLater();
    reply = nullptr;
    if(ui->checkBox->isChecked()){
         QDesktopServices::openUrl(QUrl::fromLocalFile(fileInfo.absoluteFilePath()));
    }
    ui->btnDownload->setEnabled(true);

}
