#ifndef TRANSFORMWIDGET_H
#define TRANSFORMWIDGET_H

#include <QWidget>
#include "uploadlayout.h"
#include "common.h"
#include <downloadlayout.h>
#include "logininfoinstance.h"

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

public:
    void dispayDataRecord(QString path = RECORD_DIR);

private slots:
    void on_toolButton_clicked();
};

#endif // TRANSFORMWIDGET_H
