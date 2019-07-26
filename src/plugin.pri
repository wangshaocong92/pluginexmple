include(../pluginexample.pri)
TEMPLATE = lib
CONFIG += plugin
win32:LIBS += $$PROJECT_LIB_PATH/pluginmanager.lib
win32:LIBS += $$PROJECT_LIB_PATH/interface.lib

DESTDIR = $$PROJECT_LIB_PATH
DLLDESTDIR = $$PROJECT_PLUGIN_PATH
