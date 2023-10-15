#include "myfilewidget.h"
#include "ui_myfilewidget.h"

MyFileWidget::MyFileWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyFileWidget)
{
    ui->setupUi(this);
    initListWidget();
}

MyFileWidget::~MyFileWidget()
{
    delete ui;
}


void MyFileWidget::initListWidget()
{
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
    }else{
        //点击了图标
         qDebug() << "clieck";
    }

 }
