#ifndef DATADIALOG_H
#define DATADIALOG_H

#include <QDialog>
#include<QMap>
#include <QSqlRecord>

namespace Ui {
class DataDialog;
}

class DataDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DataDialog(QWidget *parent = nullptr);
    ~DataDialog();

    void setDept(const QMap<int,QString>&map);
    void setInsertRecord(QSqlRecord& recData);
    QSqlRecord getRecord();
    void setUpdataRecord(QSqlRecord& recData);


private:
    Ui::DataDialog *ui;
    QMap<int,QString> dept;
    QSqlRecord record;
};

#endif // DATADIALOG_H
