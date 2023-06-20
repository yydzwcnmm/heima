#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include  <opencv2/opencv.hpp>
#include <vector>

using namespace cv;
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void on_btnDetect_clicked();

private:
    void initWidget();
    void imgProc();
    void imgShow();
private:
    Ui::Widget *ui;

    Mat myImg;
    QImage myQImg;
};
#endif // WIDGET_H
