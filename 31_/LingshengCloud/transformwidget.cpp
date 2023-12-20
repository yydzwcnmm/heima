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
    UploadLayout *uploadLayout =  UploadLayout::getInstance();
    uploadLayout->setUploadLayout(ui->upload_scroll);

}

TransformWidget::~TransformWidget()
{
    delete ui;
}
