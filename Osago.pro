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
QT += webkit

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Osago
TEMPLATE = app



SOURCES += main.cpp\
        mainwindow.cpp \
    agentsdialog.cpp \
    database.cpp \
    dateDelegate.cpp \
    databaseeditor.cpp \
    json.cpp \
    osagocalcform.cpp \
    calculatorosago.cpp \
    printer.cpp \
    osagoblankdataform.cpp \
    osagomaster.cpp \
    osagotsblank.cpp \
    osagousinginfoform.cpp

HEADERS  += mainwindow.h \
    agentsdialog.h \
    database.h \
    custom_exceptions.h \
    dateDelegate.h \
    databaseeditor.h \
    json.h \
    osagocalcform.h \
    calculatorosago.h \
    printer.h \
    osagoblankdataform.h \
    osagomaster.h \
    osagotsblank.h \
    osagousinginfoform.h \
    dataObjects.h

FORMS    += mainwindow.ui \
    agentsdialog.ui \
    databaseeditor.ui \
    osagocalcform.ui \
    osagoblankdataform.ui \
    osagotsblank.ui \
    osagousinginfoform.ui

RESOURCES += \
    resources.qrc

OTHER_FILES += \
    templates/polis-osago-2009 .jpg \
    templates/osago_zayavlenie.html \
    templates/osago_zayavlenie.back.html \
    templates/logo.jpg \
    templates/logo.gif \
    templates/logo.bmp \
    templates/blank_osago.html \
    Osago.db.json \
    calc.db \
    agents.db
