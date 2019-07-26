#ifndef TREEWIDGETITEM_H
#define TREEWIDGETITEM_H
#include <QTreeWidgetItem>

namespace plugin {
namespace core {
class TreeWidgetItemPrivate;
struct PluginMessage
{
    QString pluginName;
    QString pluginOrganization;
    QString pluginAuthor;
    bool enable;
    QString group;
    PluginMessage() {}
    PluginMessage(QString pluginName, QString pluginVersion, QString pluginMessage,
                  QString group = QString(), bool enable = false)
        : pluginName(pluginName)
        , pluginOrganization(pluginVersion)
        , pluginAuthor(pluginMessage)
        , enable(enable)
        , group(group)
    {
    }
};

class TreeWidgetItem : public QTreeWidgetItem
{
public:
    enum Type { Child, Parent };
    explicit TreeWidgetItem(Type type = Child);
    TreeWidgetItem(const PluginMessage &message, Type type = Child);
    void setPlugin(const PluginMessage &message);
    QString pluginName();
    bool load();
    QString group();
    void updateParentChecked();
    void setFilter(const QString &filter);
    void setChecked(Qt::CheckState state);

    QVector<TreeWidgetItem *> childrens();

private:
    TreeWidgetItemPrivate *d;
};
}
}

#endif // TREEWIDGETITEM_H
