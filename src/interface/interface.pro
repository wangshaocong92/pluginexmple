TARGET = interface
TEMPLATE = lib
include(../../pluginexample.pri)

DESTDIR = $$PROJECT_LIB_PATH

win32:DLLDESTDIR = $$PROJECT_BIN_PATH
win32:LIBS += $$PROJECT_LIB_PATH/pluginmanager.lib

HEADERS += \
    editinterface.h \
    interface_global.h \
    interfacemanager.h \
    interface.h \
    automaticinterface.h

SOURCES += \
    editinterface.cpp \
    interfacemanager.cpp \
    interface.cpp \
    automaticinterface.cpp
