#ifndef BUTTONGROUP_H
#define BUTTONGROUP_H

#include <QWidget>
#include <QDebug>
#include <QPainter>
#include <QSignalMapper>
#include <QMouseEvent>
#include <QToolButton>
#include <QSignalMapper>

namespace Ui {
class ButtonGroup;
}

class ButtonGroup : public QWidget
{
    Q_OBJECT

public:
    explicit ButtonGroup(QWidget *parent = 0);
    ~ButtonGroup();
    void setParent(QWidget* parent);
    void setUser(QString user);

private:
    QWidget *m_parent;
    QPoint m_pt;
    QToolButton *m_curBtn;  //选中按钮
    QMap<QString, QToolButton*> m_map;
    QSignalMapper *m_mapper;

protected:

    //鼠标拖动
    void mouseMoveEvent(QMouseEvent *event);
    //鼠标按下
    void mousePressEvent(QMouseEvent *event);

private:
    Ui::ButtonGroup *ui;
    void defaultPage();

signals:
    void sigMyFile();
    void sigShare();
    void sigDownload();
    void sigTransform();
    void sigSwitchUser();

private slots:
    //void on_btnMyFile_clicked();
    //void on_btnShare_clicked();
    //void on_btnDownload_clicked();
    //void on_btnTransform_clicked();
    void on_btnSwitchUser_clicked();
    void onMapperButtonsClicked(QString text);
};

#endif // BUTTONGROUP_H
