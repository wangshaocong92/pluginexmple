#pragma once
#include <QObject>
#include <QMap>
#include "interface_global.h"
#include "pluginmanager/iwidget.h"
class EditInterface;
class Interface;
class INTERFACE_EXPORT InterfaceManager : public QObject
{
    Q_OBJECT
public:
    static InterfaceManager *interfaceManager();
    static void deleteInterfaceManager();
    EditInterface *editInterface();
    void loadInterface();

protected:
    void readSetting();
signals:
    void newWidgetReady(IWidget *widget, IWidget::WidgetType type);

private:
    InterfaceManager();
    QMap<QString, bool> pluginMap;
    QMap<QString, Interface *> interfaceMap;
};
