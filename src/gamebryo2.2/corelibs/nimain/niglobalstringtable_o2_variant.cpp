
// src/gamebryo2.2/corelibs/nimain/niglobalstringtable_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nimain/niglobalstringtable.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "niglobalstringtable_decls.h"
// 1 Nov: the base unit's #pragma optimize lines removed here (they turned /O2 off for every function added; 0x00a5b630)
#pragma intrinsic(strlen)
#pragma function(strlen, strcpy)

struct P03MM
{
    void* Allocate(unsigned int);
};
extern P03MM g_memoryManager;
NiGlobalStringTable* __fastcall FUN_00a5b530(NiGlobalStringTable* allocatedTable);

// @fnv 0x00a5b630
// src: COMMUNITY 0x00a5b630
void NiGlobalStringTable__SDMInit()
{
    NiGlobalStringTable* allocatedTable = static_cast<NiGlobalStringTable*>(g_memoryManager.Allocate(0x2100));
    if (allocatedTable)
    {
        DAT_011f42c0 = FUN_00a5b530(allocatedTable);
        return;
    }
    DAT_011f42c0 = 0;
}
