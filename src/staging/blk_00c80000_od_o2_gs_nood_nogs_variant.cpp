
// src/staging/blk_00c80000_od_o2_gs_nood_nogs_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/staging/blk_00c80000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00c80000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"

#include <xmmintrin.h>
extern double DAT_01011598;
extern double DAT_01011588;
struct S_00c90db0_V
{
    float x, y, z, w;
};
struct S_00c90db0_Foo
{
    int unk00[12];
    __m128 unk30;
    __m128 unk40;
    void __thiscall hkpWorldCinfo_setBroadPhaseWorldSize(float f);
};
static inline __m128 SplatC90(float x)
{
    return _mm_set1_ps(x);
}
// @fnv 0x00c90db0
// src: XBOX_PDB 0x00c90db0
void __thiscall S_00c90db0_Foo::hkpWorldCinfo_setBroadPhaseWorldSize(float f)
{
    unk30 = SplatC90(f * -0.5);
    unk40 = SplatC90(f * 0.5);
}
