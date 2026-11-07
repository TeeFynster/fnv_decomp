
// src/staging/blk_00440000_o2_od_noo2_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy (unit src/staging/blk_00440000_o2.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00440000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"

#include <xmmintrin.h>
struct Vec4Sum
{
    __m128 v;
    void hkVector4_setAdd4(const __m128* a, const __m128* b);
};

// @fnv 0x00458880
// src: COMMUNITY 0x00458880
void Vec4Sum::hkVector4_setAdd4(const __m128* a, const __m128* b)
{
    v = _mm_add_ps(*a, *b);
}
