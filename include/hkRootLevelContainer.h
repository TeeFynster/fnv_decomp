#pragma once

#include "hkArray.h"

class hkRootLevelContainerNamedVariant;

class hkRootLevelContainer
{
public:
    hkArray<hkRootLevelContainerNamedVariant> m_kNamedVariants;

    __forceinline hkRootLevelContainer() {}
    __forceinline ~hkRootLevelContainer() {}
};
