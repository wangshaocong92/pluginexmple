TARGET = pluginexample
include(../../pluginexample.pri)

DESTDIR = $$PROJECT_BIN_PATH
win32:LIBS += $$PROJECT_LIB_PATH/pluginmanager.lib

SOURCES += \
    main.cpp
