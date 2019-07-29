#include "automaticplugin.h"
using namespace plugin;
using namespace automatic;

automaticplugin::automaticplugin()
{
}

automaticplugin::~automaticplugin()
{
}

bool automaticplugin::inheritInterface()
{
    return true;
}

bool plugin::automatic::automaticplugin::inheritWidget()
{
    return false;
}

void automaticplugin::registered(const QString &name, QString model)
{
}

void automaticplugin::registered(const QVector<QString> &nameVector, QString model)
{
}

QVector<QString> automaticplugin::filter(const QString &filter)
{
}
