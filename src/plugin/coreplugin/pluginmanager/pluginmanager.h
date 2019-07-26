#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

#include <QWidget>

namespace Ui {
class PluginManager;
}
namespace plugin {
namespace core {
class PluginManagerPrivate;
class PluginManager : public QWidget
{
    Q_OBJECT

public:
    explicit PluginManager(QWidget *parent = nullptr);
    ~PluginManager();

protected:
    void closeEvent(QCloseEvent *) override;

private:
    Ui::PluginManager *ui;
    PluginManagerPrivate *d;
    void filter(const QString &filter);
};
}
}
#endif // PLUGINMANAGER_H
