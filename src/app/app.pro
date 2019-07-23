TARGET = pluginexample
include(../../pluginexample.pri)

DESTDIR = $$PROJECT_BIN_PATH
win32:LIBS += $$PROJECT_LIB_PATH/pluginmanager.lib
DEFINES += BINPATH
BINPATH =$$PROJECT_LIB_PATH

SOURCES += \
    main.cpp
