#include "pluginmanager.h"
#include "ui_pluginmanager.h"
#include "coreplugin_global.h"
#include "treewidgetitem.h"
#include <QDir>
#include <QPluginLoader>
#include <QDebug>
#include <QSettings>

using namespace plugin;
using namespace core;
namespace plugin {
namespace core {

QString getLibPath()
{
    return QApplication::applicationDirPath() + "/../lib/plugin/";
}

class PluginManagerPrivate
{
public:
    explicit PluginManagerPrivate(PluginManager *manager);

    PluginManager *manager;

    QMap<QString, bool> pluginMap;
    QMap<QString, TreeWidgetItem *> itemMap;

    void writePluginMap();

    void writeSettings();
    void readSettings();

    void updateParentChecked(TreeWidgetItem *item = nullptr);
};
}
}

PluginManagerPrivate::PluginManagerPrivate(PluginManager *manager)
    : manager(manager)
{
    readSettings();
}

void PluginManagerPrivate::writePluginMap()
{
    QDir dir(getLibPath());
    qDebug() << getLibPath();
    if (!dir.exists())
        return;
    QStringList dllList = dir.entryList();
    for (auto i : dllList) {
        qDebug() << i;
        if (!i.endsWith(".dll"))
            continue;

        QPluginLoader loader(getLibPath() + i);
        QJsonObject json = loader.metaData().value("MetaData").toObject();
        if (json.isEmpty())
            continue;
        QString group = json.value("Group").toString();
        qDebug() << group;
        if (group.isEmpty())
            continue;
        if (!itemMap.value(group)) {
            TreeWidgetItem *item = new TreeWidgetItem(TreeWidgetItem::Parent);
            item->setPlugin(PluginMessage(group, QString(), QString(), QString(), false));
            itemMap[group] = item;
        };
        itemMap.value(group)->addChild(new TreeWidgetItem(
            PluginMessage(json.value("Name").toString(), json.value("Organization").toString(),
                          json.value("Author").toString(), json.value("Group").toString(), false),
            TreeWidgetItem::Child));
    }
}

void PluginManagerPrivate::writeSettings()
{
    QSettings setting;
    setting.beginGroup("PluginManage");
    foreach (auto key, pluginMap.keys())
        setting.setValue(key, pluginMap.value(key));
    setting.endGroup();
}

void PluginManagerPrivate::readSettings()
{
    QSettings setting;
    setting.beginGroup("PluginManage");

    for (auto i : setting.allKeys())
        pluginMap[i] = setting.value(i).toBool();
    setting.endGroup();
}

void PluginManagerPrivate::updateParentChecked(TreeWidgetItem *item)
{
    if (!item) {
        for (auto i : itemMap)
            i->updateParentChecked();
        return;
    }
    for (auto i : itemMap) {
        if (i->group() == item->group())
            i->updateParentChecked();
    }
}

PluginManager::PluginManager(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PluginManager)
    , d(new PluginManagerPrivate(this))
{
    ui->setupUi(this);
    ui->filterEdit->setToolTip("Filter");
    QStringList list = { "Name", "Load", "Origation", "Author" };
    ui->treeWidget->setHeaderItem(new QTreeWidgetItem(list));
    d->writePluginMap();
    for (auto i : d->itemMap.values())
        ui->treeWidget->addTopLevelItem(i);
    for (auto i : d->itemMap.values()) {
        for (auto j : i->childrens()) {
            j->setChecked(d->pluginMap.value(j->pluginName(), false) ? Qt::CheckState::Checked
                                                                     : Qt::CheckState::Unchecked);
        }
    }
    d->updateParentChecked();

    connect(ui->treeWidget, &QTreeWidget::itemClicked, [=](QTreeWidgetItem *item) {
        auto items = reinterpret_cast<TreeWidgetItem *>(item);
        if (items->childCount() > 0) {
            for (auto i : items->childrens())
                i->setChecked(items->load() ? Qt::CheckState::Checked : Qt::CheckState::Unchecked);
            return;
        }
        d->updateParentChecked();
        ui->label->setText("Restart loading");
    });
    connect(ui->filterEdit, &QLineEdit::textChanged, this, &PluginManager::filter);
    connect(ui->closeButton, &QPushButton::clicked, [=]() { this->close(); });
}

PluginManager::~PluginManager()
{
    delete ui;
}

void PluginManager::closeEvent(QCloseEvent *)
{
    for (auto i : d->itemMap) {
        for (auto j : i->childrens())
            d->pluginMap[j->pluginName()] = j->load();
    }
    ui->label->setText("");
    d->writeSettings();
}

void PluginManager::filter(const QString &filter)
{
    for (auto i : d->itemMap.values()) {
        for (auto j : i->childrens())
            j->setFilter(filter);
    }
}
