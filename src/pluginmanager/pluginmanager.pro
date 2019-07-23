TARGET = pluginmanager

include(../../pluginexample.pri)

DESTDIR = $$PROJECT_LIB_PATH

HEADERS += \
    iwidget.h \
    pluginmanager_global.h

SOURCES += \
    iwidget.cpp
