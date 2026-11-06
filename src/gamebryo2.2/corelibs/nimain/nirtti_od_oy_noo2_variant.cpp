
// src/gamebryo2.2/corelibs/nimain/nirtti_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Oy- (unit src/gamebryo2.2/corelibs/nimain/nirtti.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// NiRTTI: the Gamebryo runtime type descriptor.
#include "layout_support.h"
#include "../../../../include/NiRTTI.h"
FNV_STATIC_ASSERT(sizeof(NiRTTI) == 0x8);

extern const char DAT_0104d448[];
void __cdecl FUN_004ede70(const void*);
struct RTTIEntry
{
    const void* name;
    const void* base;
    void FUN_0061bcf0();
};
// @fnv 0x0061bcf0
void RTTIEntry::FUN_0061bcf0()
{
    name = DAT_0104d448;
    FUN_004ede70(base);
}
