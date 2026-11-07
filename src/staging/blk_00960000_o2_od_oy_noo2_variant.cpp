
// src/staging/blk_00960000_o2_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Oy- (unit src/staging/blk_00960000_o2.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00960000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"

#include <xmmintrin.h>
struct V
{
    __m128 v;
    void hkVector4_sub4(const V& o);
};
// @fnv 0x00961190
// src: XBOX_PDB 0x00961190
void V::hkVector4_sub4(const V& o)
{
    v = _mm_sub_ps(v, o.v);
}
