#include "datadialog.h"
#include "ui_datadialog.h"
#include<QDebug>

DataDialog::DataDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DataDialog)
{
    ui->setupUi(this);
}

DataDialog::~DataDialog()
{
    delete ui;
}

void DataDialog::setDept(const QMap<int,QString>& map)
{
    // 将部门信息保存到本地变量中
    dept = map;
    ui->cmbDept->clear();
    foreach(int id,dept.keys())
        ui->cmbDept->addItem(dept.value(id),id);
}

void DataDialog::setInsertRecord(QSqlRecord& recData)
{
    record = recData;
    ui->editEmpNo->setReadOnly(false);
    setWindowTitle("插入记录");
}
 QSqlRecord DataDialog::getRecord()
 {
     record.setValue("empNo",ui->editEmpNo->text());
     record.setValue("empName",ui->editEmpName->text());
     record.setValue("gender",ui->cmbGedner->currentText());
     record.setValue("deptId",ui->cmbDept->currentData().toInt());
     record.setValue("salary",ui->dSpinBoxSalary->value());

 }

 void DataDialog::setUpdataRecord(QSqlRecord& recData)
 {
     record = recData;
    ui->editEmpNo->setReadOnly(true);
    setWindowTitle("编辑记录");
    ui->editEmpNo->setText(recData.value("empNo").toString());
    ui->editEmpName->setText(recData.value("empName").toString());
    ui->cmbGedner->setCurrentText(recData.value("gender").toString());
    ui->cmbDept->setCurrentText(dept.value(recData.value("deptId").toInt()));
    ui->dSpinBoxSalary->setValue(recData.value("salary").toFloat());
 }
