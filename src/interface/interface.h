#pragma once
#include "interface_global.h"

class INTERFACE_EXPORT Interface
{
public:
    Interface();
    virtual ~Interface();
    virtual bool inheritInterface();
    virtual QString pluginName() = 0;
};
