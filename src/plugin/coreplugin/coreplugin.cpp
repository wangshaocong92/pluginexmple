#include "coreplugin.h"
using namespace plugin;
using namespace core;

CorePlugin::CorePlugin(QObject *parent)
    : IWidget(parent)
{
}

bool CorePlugin::inheritWidget()
{
    return true;
}

QMainWindow *CorePlugin::mainWidget()
{
    return new MainWindow;
}

QPixmap CorePlugin::icon()
{
    return QPixmap();
}

QString CorePlugin::title()
{
    return QString();
}
