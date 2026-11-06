
// src/havok/common/base/math/vector/hkvector4_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/common/base/math/vector/hkvector4.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/base/math/vector/hkvector4.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/math/vector/hkvector4.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../include/hkBool.h"
#include "../../../../../../include/hkVector4.h"
#include <math.h>

extern "C" double fabs(double x);
extern const double DAT_01012070;

// hkVector4.h omits the finite/normalization methods at 0x00c7f4e0..0x00c7f5b0; spell out their ABI here.
// This pointer aggregate keeps the hkBool return buffer on the stack while __fastcall passes hkVector4 in ECX.
struct VectorBoolResult
{
    hkBool* value;
};

hkBool* __fastcall VectorCheckFinite3(const hkVector4* vector, VectorBoolResult result);
hkBool* __fastcall VectorCheckFinite4(const hkVector4* vector, VectorBoolResult result);

// @fnv 0x00c7f520
hkBool* __fastcall VectorIsNormalized3(const hkVector4* vector, VectorBoolResult result, float eps)
{
    hkBool finite;
    VectorBoolResult finiteResult = {&finite};
    if (*VectorCheckFinite3(vector, finiteResult))
    {
        __m128 sq = _mm_mul_ps(vector->m_vComponents, vector->m_vComponents);
        __m128 len = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
        len = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), len);
        float lenSq;
        _mm_store_ss(&lenSq, len);
        float lenZero = (float)(lenSq - DAT_01012070);
        hkBool normalized = (float)fabs(lenZero) < eps;
        hkBool* const out = result.value;
        *out = normalized;
        return out;
    }
    hkBool* const out = result.value;
    *out = false;
    return out;
}

// @fnv 0x00c7f5b0
hkBool* __fastcall VectorIsNormalized4(const hkVector4* vector, VectorBoolResult result, float eps)
{
    hkBool finite;
    VectorBoolResult finiteResult = {&finite};
    if (*VectorCheckFinite4(vector, finiteResult))
    {
        __m128 sq = _mm_mul_ps(vector->m_vComponents, vector->m_vComponents);
        __m128 sum = _mm_add_ps(_mm_shuffle_ps(sq, sq, 0x4e), sq);
        __m128 len = _mm_add_ps(_mm_shuffle_ps(sum, sum, 0xb1), sum);
        float lenSq;
        _mm_store_ss(&lenSq, len);
        float lenZero = (float)(lenSq - DAT_01012070);
        hkBool normalized = (float)fabs(lenZero) < eps;
        hkBool* const out = result.value;
        *out = normalized;
        return out;
    }
    hkBool* const out = result.value;
    *out = false;
    return out;
}
