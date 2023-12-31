#ifndef TRANSFORMWIDGET_H
#define TRANSFORMWIDGET_H

#include <QWidget>
#include "uploadlayout.h"
#include "common.h"
#include <downloadlayout.h>


namespace Ui {
class TransformWidget;
}

class TransformWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TransformWidget(QWidget *parent = nullptr);
    ~TransformWidget();

private:
    Ui::TransformWidget *ui;

public:
    void showPage(TransformStatus status);


};

#endif // TRANSFORMWIDGET_H
