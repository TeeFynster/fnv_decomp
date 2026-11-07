
// src/staging/blk_00660000_o2_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy (unit src/staging/blk_00660000_o2.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00660000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
#include "../../include/Vec4.h"

#include <xmmintrin.h>
struct ScalarValue
{
    __m128 value;
    ScalarValue(const __m128&);
    const __m128& Get() const;
    __m128 Broadcast() const;
};
// @fnv 0x0066c930
// src: XBOX_PDB 0x0066c930
void Vec4::hkVector4_fastNormalize3()
{
    __m128 d = Dot(*this).Get();
    ScalarValue s(_mm_rsqrt_ss(d));
    *reinterpret_cast<__m128*>(this) = _mm_mul_ps(*reinterpret_cast<__m128*>(this), s.Broadcast());
}
