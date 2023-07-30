#ifndef TITLEWIDGET_H
#define TITLEWIDGET_H

#include <QWidget>
#include <QStyleOption>
#include <QPainter>
#include <QMouseEvent>

namespace Ui {
class TitleWidget;
}

class TitleWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TitleWidget(QWidget *parent = 0);
    ~TitleWidget();

private:
    Ui::TitleWidget *ui;
    QWidget *m_parent;
    QPoint m_pt;

protected:
    //void paintEvent(QPaintEvent *);

    //鼠标拖动
    void mouseMoveEvent(QMouseEvent *event);
    //鼠标按下
    void mousePressEvent(QMouseEvent *event);
private slots:
    void on_min_clicked();
    void on_set_clicked();

    void on_close_clicked();
signals:
    void closeButton();
    void showSetPage();
};

#endif // TITLEWIDGET_H
