#ifndef PLUGINEXPORTER_H
#define PLUGINEXPORTER_H

#include "coreplugin_global.h"
#include "mainwindow.h"
#include "pluginmanager/iwidget.h"

class COREPLUGIN_EXPORT CorePlugin : public IWidget
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "core")
public:
    CorePlugin(QObject *parent = nullptr);
    QMainWindow *mainWidget() override;
    //  BottomAreaWidget *bottomAreaWidget();
    //  QWidget *rightAreaWidget();
    QPixmap icon() override;
    QString title() override;
};

#endif // PLUGINEXPORTER_H
