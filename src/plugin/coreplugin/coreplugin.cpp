#include "coreplugin.h"

CorePlugin::CorePlugin(QObject *parent)
    : IWidget(parent)
{
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
