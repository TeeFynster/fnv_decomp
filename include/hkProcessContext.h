#pragma once

#include "InplaceArray6.h"

// RTTI: hkProcessContext has no base classes (Havok 7.1 Common/Visualize/hkProcessContext.h).
class hkProcessContext
{
public:
    int m_04;
    InplaceArray6 m_08;
    InplaceArray6 m_2c;

    hkProcessContext() : m_04(0)
    {}
    virtual ~hkProcessContext() throw();

    virtual void p04();
    virtual void p08();
};
