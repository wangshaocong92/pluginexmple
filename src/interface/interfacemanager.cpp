#include "interfacemanager.h"
#include "editinterface.h"
#include <QApplication>
#include <QSettings>
#include <QDir>
#include <QPluginLoader>
#include <editinterface.h>

/*
 * interfacemanager 提供一系列的interface单例，用于各插件和主程序之间的通信
 * interface 本身不会去调用其他组件，其相关的操作完全由interface提供的方法作业
 * 相关插件仅需要继承相关的interface类即可使用
 */
QString getLibPath()
{
    return QApplication::applicationDirPath() + "/../lib/plugin/";
}
InterfaceManager::InterfaceManager()
{
    readSetting();
}

InterfaceManager *InterfaceManager::interfaceManager()
{
    static InterfaceManager *inter = nullptr;
    if (inter)
        return inter;
    inter = new InterfaceManager;
    return inter;
}

void InterfaceManager::deleteInterfaceManager()
{
    if (InterfaceManager::interfaceManager())
        delete InterfaceManager::interfaceManager();
}

void InterfaceManager::loadInterface()
{
    QDir dir(getLibPath());
    if (!dir.exists())
        return;
    for (auto i : dir.entryList()) {
        QPluginLoader loader(getLibPath() + i);
        QJsonObject json = loader.metaData().value("MetaData").toObject();
        if (json.isEmpty())
            continue;
        if (!pluginMap.value(json.value("Name").toString(), false))
            continue;
        QObject *obj = loader.instance();
        IWidget *widget = reinterpret_cast<IWidget *>(obj);
        if (widget->inheritWidget()) {
            if (widget->mainWidget())
                emit newWidgetReady(widget, IWidget::MainWidget);
            if (widget->centralWidget())
                emit newWidgetReady(widget, IWidget::CentralWidget);
            if (widget->widget())
                emit newWidgetReady(widget, IWidget::CommonWidget);
            if (widget->bottomAreaWidget())
                emit newWidgetReady(widget, IWidget::BottomWidget);
            if (widget->rightAreaWidget())
                emit newWidgetReady(widget, IWidget::RightWidget);
        }
        Interface *interface = reinterpret_cast<Interface *>(obj);
        if (interface->inheritInterface()) {
            if (json.value("Interface").toString() == "EditInterface") {
                interfaceMap["EditInterface"] = interface;
            }
        }
    }
}

EditInterface *InterfaceManager::editInterface()
{
    return reinterpret_cast<EditInterface *>(interfaceMap.value("EditInterface"));
}

void InterfaceManager::readSetting()
{
    QSettings setting;
    setting.beginGroup("PluginManager");
    for (auto i : setting.allKeys())
        pluginMap[i] = setting.value(i).toBool();
    setting.endGroup();
}
