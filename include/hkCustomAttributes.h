#pragma once

#include "hkVariant.h"

class hkCustomAttributes
{
public:
    struct Attribute
    {
        const char* m_name;
        hkVariant m_value;
    };

    Attribute* m_data;
    int m_iElementCount;

    void* __thiscall getAttribute(void* arg);
    const hkVariant* getAttribute(const char* name) const;
    const hkVariant* FindEntry(const char* name) const;
};
