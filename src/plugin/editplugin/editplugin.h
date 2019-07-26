#pragma once
#include "pluginmanager/iwidget.h"
#include "interface/editinterface.h"
#include "editplugin_global.h"

namespace plugin {
namespace edit {
class MainWidget;
class EDITPLUGIN_EXPORT EditPlugin : public IWidget, EditInterface
{
public:
    EditPlugin();
    bool inheritWidget() override;
    bool inheritInterface() override;
    QWidget *centralWidget() override;
    void addFile(const QString &fileName) override;
    void saveAllFile() override;
    void saveCurrentFile() override;

private:
    class MainWidget *widegt;
};
}
}
