#include "pluginmanager/iwidget.h"
#include <QApplication>
#include <QDebug>
#include <QFile>
#include <QPluginLoader>

QString getLibPath()
{
    qDebug() << QApplication::applicationDirPath();
    return QApplication::applicationDirPath() + "/../lib/plugin/core.dll";
}

int main(int argc, char **argv)
{
    QApplication a(argc, argv);

    QCoreApplication::setOrganizationName("FBTBJ");
    QCoreApplication::setOrganizationDomain("www.shaocong.com");
    QCoreApplication::setApplicationName("PluginExample");
    if (QFile::exists(getLibPath()))
        qDebug() << "the file exists";
    QPluginLoader loader(getLibPath());
    QJsonObject json = loader.metaData();
    qDebug() << json;
    QObject *instance = loader.instance();
    if (!instance)
        qDebug() << "Dont import this dll";

    if (!loader.isLoaded())
        qDebug() << loader.errorString();
    auto widget = reinterpret_cast<IWidget *>(instance);

    widget->mainWidget()->showMaximized();
    return a.exec();
}
