#pragma once

#include "INISettingCollection.h"

class INIPrefSettingCollection : public INISettingCollection
{
public:
    INIPrefSettingCollection();
    virtual ~INIPrefSettingCollection();
    virtual void Add(Setting* setting);
    virtual void Remove(Setting* setting);
};
