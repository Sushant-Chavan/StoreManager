#-------------------------------------------------
#
# Project created by QtCreator 2014-11-30T09:48:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StoreManagerHMI
TEMPLATE = app


SOURCES += main.cpp\
        primaryhmi.cpp \
    createbill.cpp \
    WidgetManager.cpp \
    additemtoinventory.cpp \
    removeitemfrominventory.cpp

HEADERS  += primaryhmi.h \
    createbill.h \
    WidgetManager.h \
    Defines.h \
    additemtoinventory.h \
    removeitemfrominventory.h

FORMS    += primaryhmi.ui \
    createbill.ui \
    additemtoinventory.ui \
    removeitemfrominventory.ui
