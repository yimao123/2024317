#-------------------------------------------------
#
# Project created by QtCreator 2023-12-01T22:41:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testqwt
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += QT_DLL QWT_DLL
# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui

win32:CONFIG(release, debug|release): LIBS += -LC:/Qt/Qt5.7.1_X86/5.7/msvc2015/lib/ -lqwt
else:win32:CONFIG(debug, debug|release): LIBS += -LC:/Qt/Qt5.7.1_X86/5.7/msvc2015/lib/ -lqwtd
else:unix: LIBS += -LC:/Qt/Qt5.7.1_X86/5.7/msvc2015/lib/ -lqwt

INCLUDEPATH += C:/Qt/Qt5.7.1_X86/5.7/msvc2015/include/Qwt
DEPENDPATH += C:/Qt/Qt5.7.1_X86/5.7/msvc2015/include/Qwt

win32:CONFIG(release, debug|release): LIBS += -LC:/Qt/Qt5.7.1_X86/5.7/msvc2015/lib/ -lqwt
else:win32:CONFIG(debug, debug|release): LIBS += -LC:/Qt/Qt5.7.1_X86/5.7/msvc2015/lib/ -lqwtd
else:unix: LIBS += -LC:/Qt/Qt5.7.1_X86/5.7/msvc2015/lib/ -lqwt

INCLUDEPATH += C:/Qt/Qt5.7.1_X86/5.7/msvc2015/include/Qwt
DEPENDPATH += C:/Qt/Qt5.7.1_X86/5.7/msvc2015/include/Qwt
