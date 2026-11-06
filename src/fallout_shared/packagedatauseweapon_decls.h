// Local package target and location declarations.
#ifndef FNV_PACKAGEDATAUSEWEAPON_DECLS_H
#define FNV_PACKAGEDATAUSEWEAPON_DECLS_H

#include <stddef.h>
#define FNV_JOIN_IMPL(a, b) a##b
#define FNV_JOIN(a, b) FNV_JOIN_IMPL(a, b)
#define FNV_STATIC_ASSERT(condition) typedef char FNV_JOIN(fnv_static_assert_, __LINE__)[(condition) ? 1 : -1]
#include "../../include/TESForm.h"

class BSFileEntry;
class TESBoundObject;

// API declarations only: these objects are neither allocated nor inspected here.
class LocationDescriptor
{
  public:
    BSFileEntry* SetLocRef();
    int GetLocationType();
    TESObjectREFR* GetLocationReference();
};

extern TESBoundObject* DAT_011ca244;
extern TESBoundObject* DAT_011ca248;

void* __cdecl operator new(unsigned int size);
void __cdecl operator delete(void* pointer);

FNV_STATIC_ASSERT(sizeof(PackageTargetRecord) == 0x10);
FNV_STATIC_ASSERT(sizeof(TESUseWeaponPackageData) == 0x24);
FNV_STATIC_ASSERT(offsetof(TESUseWeaponPackageData, m_pUseTarget) == 4);
FNV_STATIC_ASSERT(offsetof(TESUseWeaponPackageData, pWeapon) == 0x20);
FNV_STATIC_ASSERT(sizeof(UseWeaponActorPackageData) == 8);
FNV_STATIC_ASSERT(offsetof(UseWeaponActorPackageData, m_pUseTarget) == 4);

#endif
