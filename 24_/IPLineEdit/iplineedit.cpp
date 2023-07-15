#include "iplineedit.h"


IPLineEdit::IPLineEdit(QWidget *parent)
    :QLineEdit(parent)
{
    hboxLayout = new QHBoxLayout(this);
    hboxLayout-> setContentsMargins(1,1,1,1);
    QRegExp regExp("(25[0-5]|2[0-4][0-9]|1?[0-9]{1,2})");


    for(int i=0;i<IP_INPUT_SIZE;i++){
        m_lineEdit[i] = new QLineEdit(this);
        //保存线条编辑是否使用边框绘制本身
        m_lineEdit[i]->setFrame(false);
        //输入框最大位数
        m_lineEdit[i]->setMaxLength(3);
        //消除布局中的空隙，居中
        m_lineEdit[i]->setAlignment(Qt::AlignCenter);
        //保存小部件的默认布局
        m_lineEdit[i]->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        //添加验证规则
        m_lineEdit[i]->setValidator(new QRegExpValidator(regExp,this));
        //安装事件过滤器， 过滤子控件事件，截获控件按键，鼠标事件
        m_lineEdit[i]->installEventFilter(this);
        hboxLayout->addWidget(m_lineEdit[i]);
        if(i<3){
            labelDot[i] = new QLabel(this);
            labelDot[i]->setText(".");
            labelDot[i]->setFixedWidth(2);
            hboxLayout->addWidget(labelDot[i]);
        }


    }
        this->setReadOnly(true);
        m_lineEdit[0]->setFocus();
        m_lineEdit[0]->selectAll();

}
IPLineEdit::~IPLineEdit()
{
    delete hboxLayout;
    hboxLayout = nullptr;
    //delete[] labelDot[3];
    //labelDot[3] = nullptr;
    for(int i=0;i<3;i++){
        delete labelDot[i];
        labelDot[i] = nullptr;
    }

}

bool IPLineEdit::eventFilter(QObject *obj, QEvent *event)
{
    if (children().contains(obj) && QEvent::KeyPress == event->type()) {
        QKeyEvent *keyEvent = dynamic_cast<QKeyEvent*>(event);
        QLineEdit *pCurrentEdit = qobject_cast<QLineEdit*>(obj);
        int index = getIndex(pCurrentEdit);
        switch (keyEvent->key()) {
            case Qt::Key_0:
            case Qt::Key_1:
            case Qt::Key_2:
            case Qt::Key_3:
            case Qt::Key_4:
            case Qt::Key_5:
            case Qt::Key_6:
            case Qt::Key_7:
            case Qt::Key_8:
            case Qt::Key_9:
            {
                QString strText = pCurrentEdit->text();
                if (strText.length() <=3 && strText.toInt()*10 > 255) {
                    //int index = getIndex(pCurrentEdit);
                    if (index !=-1 && index !=3) {
                        m_lineEdit[index+1]->setFocus();
                        m_lineEdit[index+1]->selectAll();
                    }

                return QLineEdit::eventFilter(obj, event);
            }
            break;
            }
        case Qt::Key_Left:
        {
            if (!pCurrentEdit->cursorPosition()) {
                //int index = getIndex(pCurrentEdit);
                if (index != -1 && index !=0) {
                    m_lineEdit[index-1]->setFocus();
                    int length = m_lineEdit[index-1]->text().length();
                    m_lineEdit[index-1]->setCursorPosition(length?length:0);
                }
            }

            return QLineEdit::eventFilter(obj, event);

            break;
        }
        case Qt::Key_Right:{
            int cursorPos = pCurrentEdit->cursorPosition();
            QString text = pCurrentEdit->text();
            bool atEnd = (cursorPos == text.length());
            if(atEnd){
                m_lineEdit[index+1]->setFocus();
                int length = m_lineEdit[index+1]->text().length();
                m_lineEdit[index+1]->setCursorPosition(0);
            }

            return QLineEdit::eventFilter(obj, event);
            break;
        }


        }
    }
 }


int IPLineEdit::getIndex(QLineEdit *pLineEdit)
{
    int index = -1;
    for (int i=0;i<IP_INPUT_SIZE;i++) {
        if (pLineEdit == m_lineEdit[i]) {
            index = i;
        }
    }
    return index;
}


