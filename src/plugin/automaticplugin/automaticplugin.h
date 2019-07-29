#ifndef AUTOMATICPLUGIN_H
#define AUTOMATICPLUGIN_H
#include <pluginmanager/iwidget.h>
#include <interface/automaticinterface.h>

namespace plugin {
namespace automatic {

class automaticplugin : public IWidget, AutomaticInterface
{
public:
    automaticplugin();
    ~automaticplugin();
    bool inheritInterface() override;
    bool inheritWidget() override;

    void registered(const QString &name, QString model = "General") override;
    void registered(const QVector<QString> &nameVector, QString model = "General") override;

    QVector<QString> filter(const QString &filter) override;
};
}
}

#endif // AUTOMATICPLUGIN_H
