// src/fallout_shared/tesland_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Oy- (unit src/fallout_shared/tesland.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include "tesland_decls.h"
#pragma optimize("", off)
int TruncateFloatToInt(float value);

#include <xmmintrin.h>
struct S_00538f40
{
    __m128 m;
    void hkVector4_setZero4();
};

// @fnv 0x00538f40
// src: XBOX_PDB 0x00538f40
void S_00538f40::hkVector4_setZero4()
{
    m = _mm_setzero_ps();
}
