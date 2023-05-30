#include "widget.h"
#include "ui_widget.h"

#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>

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
// "查询"
void Widget::on_btnSelect_clicked()
{
    QSqlQuery query;
    query.exec("select * from student");
    while(query.next()){
        qDebug() << query.value(0).toString() << '\t'
                 << query.value(1).toString() << '\t'
                 << query.value(2).toString() << '\t'
                 << query.value(3).toInt();
    }

/*    qDebug() << "执行next()，定位到第一行："; // first()或seek(0)
    if(query.next()){
        // 获取query所指向的记录在结果集中的编号
        int rowNo = query.at();
        // 获取每条记录中的列数
        int colCount = query.record().count();
        // 获取"studentNo"字段的列号
        int fieldNo = query.record().indexOf("studentNo");
        // 获取"studentNo"字段的值，并转换为QString
        QString stuNo = query.value(fieldNo).toString();
        // 同样方式获取其它字段的值
        fieldNo = query.record().indexOf("studentName");
        QString stuName = query.value(fieldNo).toString();
        fieldNo = query.record().indexOf("studentConcate");
        QString stuPhone = query.value(fieldNo).toString();
        fieldNo = query.record().indexOf("classNo");
        int cNo = query.value(fieldNo).toInt();
        // 输出
        qDebug() << "行号:" << rowNo;
        qDebug() << "列数:" << colCount;
        qDebug() << "studentNo:" << stuNo;
        qDebug() << "studentName:" << stuName;
        qDebug() << "studentConcate:" << stuPhone;
        qDebug() << "classNo:" << cNo;
    }
    // 定位到结果集中行号为2的记录，即第三行
    qDebug() << "-----------------------------";
    qDebug() << "执行seek(2)，定位到第三行：";
    if(query.seek(2)){
        qDebug() << "行号：" << query.at();
        qDebug() << "studentNo:" << query.value("studentNo").toString();
        qDebug() << "studentName:" << query.value("studentName").toString();
        qDebug() << "studentConcate:" << query.value("studentConcate").toString();
        qDebug() << "classNo:" << query.value("classNo").toInt();
    }
    // 定位到结果集的最后一行记录
    qDebug() << "-----------------------------";
    qDebug() << "执行last()，定位到最后一行：";
    if(query.last()){
        qDebug() << "行号：" << query.at();
        qDebug() << "studentNo:" << query.value("studentNo").toString();
        qDebug() << "studentName:" << query.value("studentName").toString();
        qDebug() << "studentConcate:" << query.value("studentConcate").toString();
        qDebug() << "classNo:" << query.value("classNo").toInt();
    }*/
}
// "插入"
void Widget::on_btnInsert_clicked()
{
    QSqlQuery query;
    QString  stuNo = ui->editStuNo->text();
    QString stuName = ui->editStuName->text();
    QString stuPhone = ui->editStuPhone->text();
    int cNo = ui->spinBoxCNo->value();
    QString sql = QString("insert into student values('%1','%2','%3',%4)")
            .arg(stuNo).arg(stuName).arg(stuPhone).arg(cNo);
/*    QString sql = QString::asprintf("insert into student values('%s','%s','%s',%d)"
              ,stuNo.unicode(),stuName.unicode(),stuPhone.unicode(),cNo);*/
    qDebug() << sql;
    if(!query.exec(sql)){
        QMessageBox::critical(this,"error","插入记录失败\n"+query.lastError().text());
        return;
    }
    QMessageBox::information(this,"插入","插入记录成功");
}
// "修改"
void Widget::on_btnUpdate_clicked()
{
    QSqlQuery query;
    QString stuNo = ui->editStuNo->text();
    QString stuName = ui->editStuName->text();
    QString stuPhone = ui->editStuPhone->text();
    int cNo = ui->spinBoxCNo->value();
    query.prepare(
       "update student set studentName=:stuName,studentConcate=:stuPhone,classNo=:cNo"
       " where studentNo=:stuNo");
    query.bindValue(":stuNo",stuNo);   // 第一个参数是占位符(QString)
    query.bindValue(":stuName",stuName);
    query.bindValue(1,stuPhone);       // 第一个参数是位置(int)
    query.bindValue(2,cNo);
    if(!query.exec()){
        QMessageBox::critical(this,"error","修改记录失败\n"+query.lastError().text());
        return;
    }
    if(query.numRowsAffected() == 0)
        QMessageBox::information(this,"修改","没有符合条件的记录");
    else
        QMessageBox::information(this,"修改","修改记录成功");
}
// "删除"
void Widget::on_btnDelete_clicked()
{
    QSqlQuery query;
    QString stuNo = ui->editStuNo->text();
    query.prepare("delete from student where studentNo=?");
//    query.bindValue(0,stuNo);
    query.addBindValue(stuNo);
    if(!query.exec()){
        QMessageBox::critical(this,"error","删除记录失败\n"+query.lastError().text());
        return;
    }
    if(query.numRowsAffected() == 0)
        QMessageBox::information(this,"删除","没有符合条件的记录");
    else
        QMessageBox::information(this,"删除","删除记录成功");
}
