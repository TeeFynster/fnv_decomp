// src/havok/common/base/math/qstransform/hkqstransform_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/common/base/math/qstransform/hkqstransform_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/common/base/math/qstransform/hkqstransform_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-29 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/common/base/math/qstransform/hkqstransform.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/common/base/math/qstransform/hkqstransform.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/math/qstransform/hkqstransform.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../include/hkBool.h"
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkQuaternion.h"

extern "C" void _ReadWriteBarrier();
extern const float DAT_01012054;
extern "C" const __declspec(align(16)) unsigned int DAT_01017d10[4];

#include "../../../../../../include/hkQsTransform.h"

// @fnv 0x00ce5120
// src: GUESS 0x00ce5120 (confidence: low)
hkBool hkQsTransform::ProcessAndReturnValue_00ce5120(const hkQsTransform& other, float epsilon) const
{
    __m128 eps = _mm_set1_ps(epsilon);
    __m128 absMask = *(const __m128*)DAT_01017d10;
    __m128 t = _mm_and_ps(_mm_sub_ps(m_vTranslation.m_vComponents, other.m_vTranslation.m_vComponents), absMask);
    if ((_mm_movemask_ps(_mm_cmple_ps(t, eps)) & 7) != 7)
        return false;
    t = _mm_and_ps(_mm_sub_ps(m_vScale.m_vComponents, other.m_vScale.m_vComponents), absMask);
    if ((_mm_movemask_ps(_mm_cmple_ps(t, eps)) & 7) != 7)
        return false;
    __m128 rot = reinterpret_cast<const __m128&>(m_rotation);
    _ReadWriteBarrier();
    t = reinterpret_cast<const __m128&>(other.m_rotation);
    __m128 p = _mm_mul_ps(t, rot);
    __m128 s = _mm_add_ps(_mm_shuffle_ps(p, p, 0x4e), p);
    s = _mm_add_ps(_mm_shuffle_ps(s, s, 0xb1), s);
    float dot;
    _mm_store_ss(&dot, s);
    if (dot < 0.0f)
    {
        __m128 m1 = _mm_load_ss(&DAT_01012054);
        rot = _mm_mul_ps(_mm_shuffle_ps(m1, m1, 0), rot);
    }
    t = _mm_and_ps(_mm_sub_ps(rot, t), absMask);
    return (_mm_movemask_ps(_mm_cmple_ps(t, eps)) & 0xf) == 0xf;
}
