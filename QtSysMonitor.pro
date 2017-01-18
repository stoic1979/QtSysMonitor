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
    diskinfo.cpp \
    qfilelogger.cpp \
    aboutdialog.cpp \
    settingsdialog.cpp \
    platforminfo.cpp \
    process.cpp \
    disk.cpp \
    networksocket.cpp \
    batteryinfo.cpp \
    systemutil.cpp \
    processwidget.cpp \
    resourceswidget.cpp

HEADERS  += mainwindow.h \
    systemmonitor.h \
    diskinfo.h \
    qfilelogger.h \
    aboutdialog.h \
    settingsdialog.h \
    platforminfo.h \
    process.h \
    disk.h \
    networksocket.h \
    batteryinfo.h \
    defs.h \
    systemutil.h \
    processwidget.h \
    resourceswidget.h


FORMS    += mainwindow.ui \
    aboutdialog.ui \
    settingsdialog.ui

RESOURCES += \
    images.qrc

DISTFILES += \
    images/linux.png \
    images/mac.png \
    images/windows.png
