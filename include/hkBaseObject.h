#pragma once

// Havok 7.1 Common/Base/Object/hkBaseObject.h.
// FinishingFlag is this tree's name for hkFinishLoadedObjectFlag (int m_finishing).
#include "FinishingFlag.h"

// ClassMemberDescriptor is this tree's name for hkInternalClassMember.
struct ClassMemberDescriptor;
class hkClass;

class hkBaseObject
{
public:
    // HK_DECLARE_REFLECTION()
    static const ClassMemberDescriptor Members[];
    static const hkClass& __cdecl staticClass();

    // Virtual destructor for derived objects
    __forceinline virtual ~hkBaseObject() {}

public:
    __forceinline hkBaseObject() {}
    __forceinline hkBaseObject(FinishingFlag flag) {}
};
