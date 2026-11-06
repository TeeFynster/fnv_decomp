#pragma once

#include "hkClass.h"

class hkClassEnumItem;
class hkCustomAttributes;

class hkStreamWriter;

class hkClassEnum
{
public:
    void FUN_00db7600(hkStreamWriter* writer) const;
    enum FlagValues
    {
        FLAGS_NONE = 0
    };

    char* m_name;
    hkSimpleArray<hkClassEnumItem> m_items;
    hkCustomAttributes* m_pCustomAttributes;
    hkUint32 m_flags;
};
