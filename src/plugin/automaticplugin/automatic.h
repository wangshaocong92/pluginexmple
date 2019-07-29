#pragma once

#include <QMap>

class QString;
namespace plugin {
namespace automatic {

class Automatic
{
public:
    Automatic();

    void registered(const QString &name, QString model = "General");
    void registered(const QVector<QString> &nameVector, QString model = "General");

    QVector<QString> filter(const QString &filter);

private:
    QMap<QString, QString> registry;
};
}
}
