#包含一个目录
INCLUDEPATH += $$PWD
#如果DEPENDPATH目录里的头文件发生了变化，所有的cpp都会重新编译
DEPENDPATH += $$PWD

#$$PWD  当前目录  D:\work\workspace\qtstudyspace\MyChatClient\basewidget

HEADERS += \
    $$PWD/animationstackedwidget.h \
    $$PWD/clineedit.h \
    $$PWD/customwidget.h

SOURCES += \
    $$PWD/animationstackedwidget.cpp \
    $$PWD/clineedit.cpp \
    $$PWD/customwidget.cpp
