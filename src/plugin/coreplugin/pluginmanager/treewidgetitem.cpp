#include "treewidgetitem.h"
#include "coreplugin_global.h"

using namespace plugin;
using namespace core;

namespace plugin {
namespace core {
class TreeWidgetItemPrivate
{
public:
    explicit TreeWidgetItemPrivate();
    TreeWidgetItem::Type type;
    PluginMessage message;
};
}
}

TreeWidgetItemPrivate::TreeWidgetItemPrivate()
{
}

TreeWidgetItem::TreeWidgetItem(Type type)
    : d(new TreeWidgetItemPrivate)
{
    d->type = type;
}

TreeWidgetItem::TreeWidgetItem(const PluginMessage &message, TreeWidgetItem::Type type)
    : d(new TreeWidgetItemPrivate)
{
    d->type = type;
    setPlugin(message);
}

void TreeWidgetItem::setPlugin(const PluginMessage &message)
{
    d->message = message;
    if (d->type == Child) {
        this->setText(0, message.pluginName);
        this->setCheckState(1, Qt::CheckState::Checked);
        this->setText(2, message.pluginOrganization);
        this->setText(3, message.pluginAuthor);
    } else {
        this->setText(0, message.pluginName);
        this->setCheckState(1, Qt::CheckState::PartiallyChecked);
        this->setText(2, QString());
        this->setText(3, QString());
    }
}

QString TreeWidgetItem::pluginName()
{
    return d->message.pluginName;
}

bool TreeWidgetItem::load()
{
    return this->checkState(1);
}

QString TreeWidgetItem::group()
{
    return d->message.group;
}

void TreeWidgetItem::updateParentChecked()
{
    int trueCount = 0;
    int falseCount = 0;
    for (auto i : this->childrens())
        i->load() ? trueCount++ : falseCount++;
    if (trueCount && !falseCount)
        this->setChecked(Qt::CheckState::Checked);
    else if (!trueCount && falseCount)
        this->setChecked(Qt::CheckState::Unchecked);
    else
        this->setChecked(Qt::CheckState::PartiallyChecked);
}

void TreeWidgetItem::setFilter(const QString &filter)
{
    if (filter.isEmpty()) {
        this->setHidden(false);
        return;
    }
    if (d->message.pluginName.contains(filter) || d->message.group.contains(filter)
        || d->message.pluginAuthor.contains(filter)
        || d->message.pluginOrganization.contains(filter)) {
        this->setHidden(false);
    } else {
        this->setHidden(true);
    }
}

void TreeWidgetItem::setChecked(Qt::CheckState state)
{
    this->setCheckState(1, state);
}

QVector<TreeWidgetItem *> TreeWidgetItem::childrens()
{
    QVector<TreeWidgetItem *> returnChilds;
    for (auto i = 0; i < this->childCount(); i++)
        returnChilds.append(reinterpret_cast<TreeWidgetItem *>(this->child(i)));
    return returnChilds;
}
