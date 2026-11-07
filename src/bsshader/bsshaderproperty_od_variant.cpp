
// src/bsshader/bsshaderproperty_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/bsshader/bsshaderproperty.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "bsshaderproperty_decls.h"

#include "../../include/RecursiveSpinLock.h"
extern RecursiveSpinLock g_011c5f80;
struct PoolMemoryAllocator
{
    static void __cdecl CreateFreeMem();
};
extern void* DAT_011c5f58;
struct FUN_0043a010_t
{
    unsigned int m_pNext;
    unsigned int m_pInventoryEntryData;
    unsigned int m_pItem2;
};
struct FUN_0043a010_shell
{
    FUN_0043a010_t* NiGeometry_AddProperty();
};
// @fnv 0x0043a010
// src: COMMUNITY 0x0043a010
FUN_0043a010_t* FUN_0043a010_shell::NiGeometry_AddProperty()
{
    g_011c5f80.Lock(0);
    if (DAT_011c5f58 == 0)
        PoolMemoryAllocator::CreateFreeMem();
    FUN_0043a010_t* pkNode = (FUN_0043a010_t*)DAT_011c5f58;
    DAT_011c5f58 = (void*)((FUN_0043a010_t*)DAT_011c5f58)->m_pNext;
    pkNode->m_pItem2 = 0;
    pkNode->m_pNext = 0;
    pkNode->m_pInventoryEntryData = 0;
    g_011c5f80.Unlock();
    return pkNode;
}
