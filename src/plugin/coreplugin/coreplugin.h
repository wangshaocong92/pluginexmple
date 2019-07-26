#ifndef PLUGINEXPORTER_H
#define PLUGINEXPORTER_H

#include "coreplugin_global.h"
#include "mainwindow.h"
#include "pluginmanager/iwidget.h"

namespace plugin {
namespace core {
class COREPLUGIN_EXPORT CorePlugin : public IWidget
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "CorePlugin" FILE "coreplugin.json")
public:
    CorePlugin(QObject *parent = nullptr);
    bool inheritWidget() override;
    QMainWindow *mainWidget() override;
    //  BottomAreaWidget *bottomAreaWidget();
    //  QWidget *rightAreaWidget();
    QPixmap icon() override;
    QString title() override;
};
}
}

#endif // PLUGINEXPORTER_H
