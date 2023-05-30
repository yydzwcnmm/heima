#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQueryModel>
#include <QItemSelectionModel>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlError>
#include <QDebug>
#include <QtCore/QVariant>
#include <QtCore/QTextCodec>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actOpen_triggered();

    void on_actInsert_triggered();

    void on_actUpdate_triggered();

    void on_tableView_doubleClicked(const QModelIndex &index);

private:
    void readTable();
    void depMap();
    void updateRecord(int rowNo);

private:
    Ui::MainWindow *ui;
    QSqlQueryModel* queryModel;
    QItemSelectionModel* selection;
    QSqlDatabase db;
    QMap<int,QString> map;

};
#endif // MAINWINDOW_H
