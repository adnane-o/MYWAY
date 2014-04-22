#-------------------------------------------------
#
# Project created by QtCreator 2013-05-26T14:10:32
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = app
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Dijkstra.cpp

HEADERS  += mainwindow.h \
    Dijkstra.h

FORMS    += mainwindow.ui
RESOURCES += ./app.qrc
