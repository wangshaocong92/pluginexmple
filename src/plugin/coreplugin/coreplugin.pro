TARGET = core

include(../../plugin.pri)


FORMS += \
    mainwindow.ui \
   pluginmanager\pluginmanager.ui

HEADERS += \
    mainwindow.h \
    coreplugin_global.h \
    coreplugin.h \
   pluginmanager\pluginmanager.h \
    pluginmanager\treewidgetitem.h

SOURCES += \
    mainwindow.cpp \
    coreplugin.cpp \
   pluginmanager\pluginmanager.cpp \
    pluginmanager\treewidgetitem.cpp
