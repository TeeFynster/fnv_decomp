#pragma once

#include "hkStringPtr.h"
#include "hkaAnimation.h"

class hkxAttribute;

class hkxAttributeGroup
{
public:
    hkStringPtr m_name;
    hkArray<hkxAttribute> m_pCustomAttributes;
};
