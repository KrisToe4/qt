#-------------------------------------------------
#
# Project created by QtCreator 2018-02-04T06:55:48
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CpsData
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# QMAKE configuration options
CONFIG += c++14

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    logindialog.cpp \
    techcredential.cpp \
    apiwebservice.cpp \
    startup.cpp \
    utils.cpp \
    settings.cpp \
    provider.cpp

HEADERS += \
        mainwindow.h \
    logindialog.h \
    techcredential.h \
    apiwebservice.h \
    startup.h \
    utils.h \
    settings.h \
    provider.h

FORMS += \
        mainwindow.ui \
    logindialog.ui

RESOURCES += \
    resources.qrc
