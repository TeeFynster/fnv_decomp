
// src/havok/common/base/math/matrix/hktransform_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/common/base/math/matrix/hktransform.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/base/math/matrix/hktransform.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/math/matrix/hktransform.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../include/Transform.h"

// @fnv 0x00cb2240
// src: XBOX_PDB 0x00cb2240
void Transform::hkTransform_setMul(const Transform* __restrict a, const Transform* __restrict b)
{
    const __m128& c1 = a->r[1];
    const __m128& c0 = a->r[0];
    const __m128& c2 = a->r[2];
    for (int i = 3; i >= 0; i--)
    {
        const __m128& v = b->r[i];
        r[i] =
            _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0), c0), _mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), c1)),
                       _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), c2));
    }
    r[3] = _mm_add_ps(a->r[3], r[3]);
}
