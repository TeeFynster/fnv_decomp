
// src/staging/blk_00880000_o2_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy (unit src/staging/blk_00880000_o2.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00880000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"

#include <xmmintrin.h>
struct S008910c0_Vector
{
    __m128 m_vComponents;
    S008910c0_Vector* hkSimdReal_broadcast(S008910c0_Vector* pOut) const;             // broadcast x
    void hkVector4_subMul4(const S008910c0_Vector* a, const S008910c0_Vector* b);  // subMul
};

// @fnv 0x008910c0
// src: XBOX_PDB 0x008910c0
void S008910c0_Vector::hkVector4_subMul4(const S008910c0_Vector* a, const S008910c0_Vector* b)
{
    S008910c0_Vector kScale;
    m_vComponents = _mm_sub_ps(m_vComponents, _mm_mul_ps(a->hkSimdReal_broadcast(&kScale)->m_vComponents, b->m_vComponents));
}
