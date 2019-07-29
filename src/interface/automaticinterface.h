/*
 *
 *本接口用于自动补全模块的处理
 *
 */

#pragma once
#include "interface_global.h"
#include <QString>
#include "interface.h"

class AutomaticInterface : public Interface
{
public:
    explicit AutomaticInterface();
    virtual ~AutomaticInterface();
    QString pluginName() override;

    virtual void registered(const QString &name, QString model = "General") = 0;
    virtual void registered(const QVector<QString> &nameVector, QString model = "General") = 0;

    virtual QVector<QString> filter(const QString &filter) = 0;
};
