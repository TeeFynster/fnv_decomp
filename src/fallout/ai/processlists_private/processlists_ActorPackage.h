#ifndef FNV_ACTORPACKAGE_H
#define FNV_ACTORPACKAGE_H

#include "processlists_layout_support.h"
class ActorPackageContext
{
  public:
    float ActorPackage_GetPackageStartTime();
    TESPackage* pPackage;     // +0x0
    ActorPackageData* pData;  // +0x4
    TESObjectREFR* pTarget;   // +0x8
    int m_iPackageValue;      // +0xC
    float m_fPackageValue;    // +0x10
    unsigned int iFlags;      // +0x14
};
FNV_STATIC_ASSERT(sizeof(ActorPackageContext) == 0x18);
FNV_STATIC_ASSERT(offsetof(ActorPackageContext, pPackage) == 0x0);
FNV_STATIC_ASSERT(offsetof(ActorPackageContext, pData) == 0x4);
FNV_STATIC_ASSERT(offsetof(ActorPackageContext, pTarget) == 0x8);
FNV_STATIC_ASSERT(offsetof(ActorPackageContext, m_iPackageValue) == 0xC);
FNV_STATIC_ASSERT(offsetof(ActorPackageContext, m_fPackageValue) == 0x10);
FNV_STATIC_ASSERT(offsetof(ActorPackageContext, iFlags) == 0x14);
#endif
