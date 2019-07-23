#include "pluginmanager/iwidget.h"
#include <QApplication>
#include <QDebug>
#include <QFile>
#include <QPluginLoader>

QString getLibPath()
{
    qDebug() << QApplication::applicationDirPath();
    return QApplication::applicationDirPath() + "\\..\\lib\\core.dll";
}

int main(int argc, char **argv)
{
    QApplication a(argc, argv);
    if (QFile::exists(getLibPath()))
        qDebug() << "the file exists";
    QPluginLoader loader(getLibPath());

    QObject *instance = loader.instance();
    if (!loader.isLoaded())
        qDebug() << loader.errorString();
    IWidget *widget = reinterpret_cast<IWidget *>(instance);
    widget->mainWidget()->show();
    return a.exec();
}
