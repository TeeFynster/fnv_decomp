#pragma once

#include "FinishingFlag.h"

struct ClassMemberDescriptor;

class hkpBroadPhaseHandle
{
public:
    static const ClassMemberDescriptor Members[];

    hkpBroadPhaseHandle() : m_iOwnerObjectOffset(0) {}
    hkpBroadPhaseHandle(FinishingFlag flag);

    unsigned int m_iOwnerObjectOffset;
};
