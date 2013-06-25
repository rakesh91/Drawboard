#-------------------------------------------------
#
# Project created by QtCreator 2013-06-10T20:58:29
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = udpTry
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    mainview.cpp \
    helpwidget.cpp

HEADERS  += widget.h \
    mainview.h \
    helpwidget.h

FORMS    += widget.ui \
    mainview.ui \
    helpwidget.ui
