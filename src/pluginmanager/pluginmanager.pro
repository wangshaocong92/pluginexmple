TARGET = pluginmanager
TEMPLATE = lib
include(../../pluginexample.pri)

DESTDIR = $$PROJECT_LIB_PATH

win32:DLLDESTDIR = $$PROJECT_BIN_PATH

HEADERS += \
    iwidget.h \
    pluginmanager_global.h

SOURCES += \
    iwidget.cpp
