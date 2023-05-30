#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "datadialog.h"
#include  <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->tableView);
    ui->actInsert->setEnabled(false);
    ui->actUpdate->setEnabled(false);
    ui->actDelete->setEnabled(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actOpen_triggered()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("tarena");
    db.setDatabaseName("emp");
    if(!(db.open())){
        QMessageBox::critical(this,"error","打开数据库失败"+db.lastError().text());
        return;

    }
    readTable();
    depMap();
}

void MainWindow::readTable(){


    QTextCodec *code = QTextCodec::codecForName("UTF-8");

    QTextCodec::setCodecForLocale(code);

    queryModel =new QSqlQueryModel(this);
    selection = new QItemSelectionModel(queryModel);

    queryModel->setQuery("select * from emp order by empNo");
    if(queryModel->lastError().isValid()){
        QMessageBox::critical(this,"error","查询错误\n"+queryModel->lastError().text());
    }



    // 输出查询结果
        for (int row = 0; row < queryModel->rowCount(); ++row) {
            QString rowData;
            for (int column = 0; column <queryModel->columnCount(); ++column) {
                rowData += queryModel->data(queryModel->index(row, column)).toString() + " ";
            }
            qDebug() << rowData;
        }

    queryModel->setHeaderData(0,Qt::Horizontal,"工号");
    queryModel->setHeaderData(1,Qt::Horizontal,"姓名");
    queryModel->setHeaderData(2,Qt::Horizontal,"性别");
    queryModel->setHeaderData(3,Qt::Horizontal,"学院");
    queryModel->setHeaderData(4,Qt::Horizontal,"工资");

   ui->tableView->setModel(queryModel);
   ui->tableView->setSelectionModel(selection);

    ui->actOpen->setEnabled(false);
    ui->actInsert->setEnabled(true);
    ui->actUpdate->setEnabled(true);
    ui->actDelete->setEnabled(true);

}
    void MainWindow::depMap()
{
    QSqlQuery query;
    query.exec("select * from dept");
    while(query.next())
            map.insert(query.value(0).toInt(),query.value(1).toString());

}

void MainWindow::on_actInsert_triggered()
{
    QSqlQuery query;
    query.exec("select * from emp where empNo=-1");
    QSqlRecord curRec = query.record();

    DataDialog* dataDlg = new DataDialog(this);
    dataDlg->setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);
    dataDlg->setDept(map);
    dataDlg->setInsertRecord(curRec);

     int ret = dataDlg->exec();
    if(ret==QDialog::Accepted){
        QSqlRecord recData = dataDlg->getRecord();
        query.prepare("insert into emp values(?,?,?,?,?)");
        query.addBindValue(recData.value("empNo"));
        query.addBindValue(recData.value("empName"));
        query.addBindValue(recData.value("gender"));
        query.addBindValue(recData.value("deptId"));
        query.addBindValue(recData.value("salary"));
        if(!query.exec())
        {
            QMessageBox::critical(this,"error","插入失败\n");
        }
        else
        {
            queryModel->setQuery("SELECT * FROM emp;");
        }
    }

    delete dataDlg;
}

// 更新记录
void MainWindow::updateRecord(int rowNo)
{
    QSqlRecord curRec = queryModel->record(rowNo);  // 获取rowNo对应的记录
    int empNo = curRec.value("empNo").toInt();
    QSqlQuery query;
    query.prepare("select * from emp where empNo=?");
    query.addBindValue(empNo);
    query.exec();
    query.first();
    if(!query.isValid())
        return;
    curRec = query.record();  // 获取当前行

    DataDialog dataDlg(this);
    dataDlg.setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);
    dataDlg.setDept(map);   // 加载学院信息到对话框的cmdDept
    dataDlg.setUpdataRecord(curRec);  // 初始化对话框窗口的record

    int ret = dataDlg.exec();
    if(ret == QDialog::Accepted){ //"确定"按钮被点击
        QSqlRecord recData = dataDlg.getRecord(); // 获取用户输入的信息
        query.prepare(
           "update emp set empName=:empName,gender=:gender,deptId=:id,salary=:sal"
           " where empNo=:empNo");
        query.bindValue(":empNo",recData.value("empNo"));
        query.bindValue(":empName",recData.value("empName"));
        query.bindValue(":gender",recData.value("gender"));
        query.bindValue(":id",recData.value("deptId"));
        query.bindValue(":sal",recData.value("salary"));
        if(!query.exec())
            QMessageBox::critical(this,"error","更新记录失败\n"+query.lastError().text());
        else
            queryModel->setQuery("select empNo,empName,gender,deptId ,salary from emp order by empNo");

    }
    qDebug()<<"333";


    qDebug()<<"222";
}

void MainWindow::on_actUpdate_triggered()
{
    int curNo=selection->currentIndex().row();
    updateRecord(curNo);
}

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    int curNo = index.row();
    updateRecord(curNo);
}
