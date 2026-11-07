
// src/havok/animation/animation/ik/footplacement/hkafootplacementiksolver.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/ik/footplacement/hkafootplacementiksolver.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/hkaRaycastInterface.h"

// @fnv 0x00cd8800
hkBool hkaRaycastInterface::castRay(const hkVector4& fromWS, const hkVector4& toWS,
                                    float& hitFractionOut, hkVector4& normalWSOut)
{
    return false;
}

struct GlobalMgr
{
    void Release(void* apObject);
};

extern "C" GlobalMgr DAT_011f6238;
extern "C" int DAT_010c4b60;

struct FUN_00c74e70_cls
{
    int m_vptr;

    FUN_00c74e70_cls* FUN_00c74e70(unsigned char acFlags);
};

// Sets the object's vtable pointer to DAT_010c4b60 and, when bit 0 of acFlags is set, releases the object through DAT_011f6238, returning this.
// @fnv 0x00c74e70
FUN_00c74e70_cls* FUN_00c74e70_cls::FUN_00c74e70(unsigned char acFlags)
{
    m_vptr = (int)&DAT_010c4b60;
    if (acFlags & 1)
    {
        DAT_011f6238.Release(this);
    }
    return this;
}

// @fnv 0x00cd8810
hkBool hkaRaycastInterface::castRay(const hkVector4& fromWS, const hkVector4& toWS,
                                    unsigned int collisionFilterInfo, float& hitFractionOut,
                                    hkVector4& normalWSOut)
{
    return false;
}

#include <xmmintrin.h>
extern __m128 DAT_010c44d0;

class NormVec_cls
{
  public:
    __m128 m_v;
    __m128* hkQuaternion_getAxis(__m128* out);
};

// Computes the normalized version of m_v using an approximate reciprocal square root and one Newton-Raphson refinement, storing the result in out.
// @fnv 0x00c74c90
// src: COMMUNITY 0x00c74c90
__m128* NormVec_cls::hkQuaternion_getAxis(__m128* out)
{
    __m128 vVec = m_v;
    __m128 vSq = _mm_mul_ps(vVec, vVec);
    __m128 vLenSq = _mm_add_ss(_mm_shuffle_ps(vSq, vSq, 0xaa), _mm_add_ss(_mm_shuffle_ps(vSq, vSq, 0x55), vSq));
    __m128 vInvLen = _mm_rsqrt_ss(vLenSq);
    __m128 vZeroMask = _mm_cmpeq_ss(vLenSq, _mm_set_ss(0.0f));
    __m128 vT = _mm_mul_ss(_mm_mul_ss(vLenSq, vInvLen), vInvLen);
    __m128 vRefined = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), vInvLen), _mm_sub_ss(_mm_set_ss(3.0f), vT));
    __m128 s = _mm_andnot_ps(vZeroMask, vRefined);
    s = _mm_shuffle_ps(s, s, 0);
    __m128 vResult = _mm_mul_ps(s, vVec);
    if ((_mm_movemask_ps(_mm_cmplt_ps(vVec, _mm_setzero_ps())) & 8) != 0)
    {
        vResult = _mm_xor_ps(DAT_010c44d0, vResult);
    }
    *out = vResult;
    return out;
}
