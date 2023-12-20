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

private:
    Ui::FileDataProgress *ui;
public:
    void setFileName(QString fileName);
    void setProgress(int value, int max);

};

#endif // FILEDATAPROGRESS_H
