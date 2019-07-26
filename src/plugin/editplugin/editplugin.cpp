#include "editplugin.h"
#include "mainwidget.h"
using namespace plugin;
using namespace edit;

EditPlugin::EditPlugin()
    : widegt(new class MainWidget)
{
}

bool EditPlugin::inheritWidget()
{
    return true;
}

bool EditPlugin::inheritInterface()
{
    return true;
}

QWidget *EditPlugin::centralWidget()
{
    return widegt;
}

void EditPlugin::addFile(const QString &fileName)
{
    widegt->addFile(fileName);
}

void EditPlugin::saveAllFile()
{
    widegt->saveAllFile();
}

void EditPlugin::saveCurrentFile()
{
    widegt->saveCurrentFile();
}
