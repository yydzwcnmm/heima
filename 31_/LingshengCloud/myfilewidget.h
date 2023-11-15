#ifndef MYFILEWIDGET_H
#define MYFILEWIDGET_H

#include "myfilewidget.h"
#include "ui_myfilewidget.h"
#include "mymenu.h"
#include "common.h"
#include <QListView>
#include <QDebug>
#include <QAction>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include "logininfoinstance.h"
#include <QWidget>
#include "networkdata.h"
#include "common.h"
#include "networkdata.h"


namespace Ui {
class MyFileWidget;
}

class MyFileWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyFileWidget(QWidget *parent = nullptr);
    ~MyFileWidget();

signals:
    sigLoginAgain();

private slots:
    void onRightMenu(const QPoint &pos);

private:
    Ui::MyFileWidget *ui;
    MyMenu *m_menuItem;
    QAction *m_actionDownload;
    QAction *m_actionShare;
    QAction *m_actionDelete;
    QAction *m_actionProperty;
    MyMenu *m_menuEmpty;
    QAction *m_actionDownloadAsc;
    QAction *m_actionDownloadDesc;
    QAction *m_actionRefresh;
    QAction *m_actionUpload;
    Common *m_common;
    LoginInfoInstance *m_loginInfo;
    QNetworkAccessManager *m_manager;
    enum MyFileDisplay { Normal, Asc, Desc};
    int m_myFilesCount;
    QList<FileInfo*>m_fileList;


    void initListWidget();
    void addMenu();
    void menuActions();
    void getMyFileCount(MyFileDisplay cmd = Normal);
    void getMyFileList(MyFileDisplay cmd = Normal);
    void addUploadItem();
    void showFileItems();
    void clearFileList();
    void clearItems();
    void dealfile(QString cmd);
    void shareFile(FileInfo *FileInfo);
    void deleteFile(FileInfo *fileInfo);


};

#endif // MYFILEWIDGET_H
