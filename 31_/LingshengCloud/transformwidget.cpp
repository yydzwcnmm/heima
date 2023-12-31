#include "transformwidget.h"
#include "ui_transformwidget.h"

TransformWidget::TransformWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TransformWidget)
{
    ui->setupUi(this);
    //垂直布局 (进度条UI)，
    //布局单独的做成一个类
    //设置上传布局类
    ui->tabWidget->setCurrentWidget(ui->tabUpload);
    UploadLayout *uploadLayout =  UploadLayout::getInstance();

    //设置下载布局类
    DownloadLayout *downloadLayout = DownloadLayout::getInstance();
    downloadLayout->setDownloadLayout(ui->download_scroll);

    uploadLayout->setUploadLayout(ui->upload_scroll);

}

TransformWidget::~TransformWidget()
{
    delete ui;
}

void TransformWidget::showPage(TransformStatus status)
{
    if(status ==TransformStatus::Upload)
    {
        ui->tabWidget->setCurrentWidget(ui->tabUpload);
    }
    if(status == TransformStatus::Download)
    {
        ui->tabWidget->setCurrentWidget(ui->tabDownload);
    }
}
