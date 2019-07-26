/*
 *此接口用于主编辑界面的调用
 */
#pragma once
#include "interface_global.h"
#include <QString>
#include "interface.h"

class INTERFACE_EXPORT EditInterface : public Interface
{
public:
    explicit EditInterface();
    virtual ~EditInterface();
    virtual void addFile(const QString &fileName) = 0;
    virtual void saveAllFile() = 0;
    virtual void saveCurrentFile() = 0;
    QString pluginName() override;
};
