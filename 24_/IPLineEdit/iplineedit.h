#ifndef IPLINEEDIT_H
#define IPLINEEDIT_H

#include <QLineEdit>
#include <QWidget>
#include <QSizePolicy>
#include <QHBoxLayout>
#include <QLabel>
#include <QRegExp>
#include <QRegExpValidator>
#include <QEvent>
#include <QKeyEvent>

class IPLineEdit : public QLineEdit
{
public:
    IPLineEdit(QWidget *parent = 0);
    ~IPLineEdit();
    enum MyEnum{
        IP_INPUT_SIZE = 4
    };

protected:
    bool eventFilter(QObject *watched ,QEvent *event);

private:
    QLineEdit *m_lineEdit[IP_INPUT_SIZE];
    int getIndex(QLineEdit *pLineEdit);
    QHBoxLayout *hboxLayout;
    QLabel *labelDot[3];

};

#endif // IPLINEEDIT_H
