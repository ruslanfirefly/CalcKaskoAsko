#-------------------------------------------------
#
# Project created by QtCreator 2013-02-02T21:44:26
#
#-------------------------------------------------
DEFINES += BUILD_WITH_EDITOR
RESOURCES += resources.qrc

QMAKE_CXXFLAGS += -std=c++11
QMAKE_CXXFLAGS_DEBUG += -std=c++11
QMAKE_CXXFLAGS += -g
QMAKE_CXXFLAGS_DEBUG += -g
CONFIG += debug
QT       += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Osago
TEMPLATE = app



SOURCES += main.cpp\
        mainwindow.cpp \
    agentsdialog.cpp \
    database.cpp \
    dateDelegate.cpp \
    databaseeditor.cpp \
    json.cpp

HEADERS  += mainwindow.h \
    agentsdialog.h \
    database.h \
    custom_exceptions.h \
    dateDelegate.h \
    databaseeditor.h \
    json.h

FORMS    += mainwindow.ui \
    agentsdialog.ui \
    databaseeditor.ui

RESOURCES += \
    resources.qrc
