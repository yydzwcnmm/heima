#ifndef FILEDATAPROGRESS_H
#define FILEDATAPROGRESS_H

#include <QWidget>

namespace Ui {
class FileDataProgress;
}

class FileDataProgress : public QWidget
{
    Q_OBJECT

public:
    explicit FileDataProgress(QWidget *parent = nullptr);
    ~FileDataProgress();
    void setProgress(int value,int max);
    void setFileName(QString fileName);

private:
    Ui::FileDataProgress *ui;
};

#endif // FILEDATAPROGRESS_H
