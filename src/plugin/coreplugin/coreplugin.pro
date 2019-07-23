TARGET = core

include(../../../pluginexample.pri)
DESTDIR = $$PROJECT_LIB_PATH
win32:LIBS += $$PROJECT_LIB_PATH/pluginmanager.lib

CONFIG += plugin

FORMS += \
    mainwindow.ui

HEADERS += \
    mainwindow.h \
    coreplugin_global.h \
    coreplugin.h

SOURCES += \
    mainwindow.cpp \
    coreplugin.cpp
