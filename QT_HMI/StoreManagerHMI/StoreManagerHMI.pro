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
    removeitemfrominventory.cpp \
    backendSource/AccessConfig.cpp \
    backendSource/Billing.cpp \
    backendSource/HMI.cpp \
    backendSource/Item.cpp \
    backendSource/ItemManager.cpp

HEADERS  += primaryhmi.h \
    createbill.h \
    WidgetManager.h \
    Defines.h \
    additemtoinventory.h \
    removeitemfrominventory.h \
    backendSource/AccessConfig.h \
    backendSource/Billing.h \
    backendSource/HMI.h \
    backendSource/Item.h \
    backendSource/ItemManager.h

FORMS    += primaryhmi.ui \
    createbill.ui \
    additemtoinventory.ui \
    removeitemfrominventory.ui
