#-------------------------------------------------
#
# Project created by QtCreator 2016-11-18T18:41:16
#
#-------------------------------------------------

QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtSysMonitor
TEMPLATE = app

RC_FILE = icon.rc

SOURCES += main.cpp\
        mainwindow.cpp \
    systemmonitor.cpp \
    diskinfo.cpp

HEADERS  += mainwindow.h \
    systemmonitor.h \
    diskinfo.h

FORMS    += mainwindow.ui
