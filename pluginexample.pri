QT += widgets core gui

isEmpty(PROJECT_BUILD_TREE):PROJECT_BUILD_TREE = $$shadowed($$PWD)
isEqual(TARGET ,pluginexample):TEMPLATE = app
INCLUDEPATH += $$PWD/src/
DEFINES += LIB$$upper($$TARGET)_BUILD

PROJECT_BIN_PATH = $$PROJECT_BUILD_TREE/bin
PROJECT_LIB_PATH = $$PROJECT_BUILD_TREE/lib
PROJECT_PLUGIN_PATH = $$PROJECT_LIB_PATH/plugin
PROJECT_DATA_PATH = $$PROJECT_BUILD_TREE/share



