#include "automatic.h"
#include <QRegExp>
#include <QVector>

using namespace plugin;
using namespace automatic;

Automatic::Automatic()
{
}

void Automatic::registered(const QString &name, QString model)
{
    registry[model] = registry.value(model, QString()) + " " + name;
}

void Automatic::registered(const QVector<QString> &nameVector, QString model)
{
    QString name = registry.value(model, QString()) + " ";
    for (auto i : nameVector)
        name = name + i + " ";
    registry[model] = name;
}

QVector<QString> Automatic::filter(const QString &filter)
{

    QVector<QString> returnVector;
    /*构建正则表达式*/
    QString reg;
    for (auto i : filter)
        reg = reg + i + "\\w*";
    reg = reg + "\\s?";

    for (auto i : registry) {
    }
}
