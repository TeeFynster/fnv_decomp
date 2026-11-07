// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprimitivedrawer_gs_nogs_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprimitivedrawer_gs_nogs_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprimitivedrawer_gs_nogs_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprimitivedrawer.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprimitivedrawer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprimitivedrawer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct CpuObject
{
    int value;
    void hkpPrimitiveDrawer_setDisplayHandler(int value);
};

#include "../../../../../../../../../include/hkRotation.h"


__forceinline hkRotation::hkRotation()
{
}

__forceinline void hkVector4::normalize3()
{
    __m128 m = _mm_mul_ps(m_vComponents, m_vComponents);
    __m128 len2 = _mm_add_ss(_mm_shuffle_ps(m, m, 0xaa), _mm_add_ss(_mm_shuffle_ps(m, m, 0x55), m));
    __m128 est = _mm_rsqrt_ss(len2);
    __m128 zero = _mm_set_ss(0.0f);
    __m128 three = _mm_set_ss(3.0f);
    __m128 half = _mm_set_ss(0.5f);
    __m128 step = _mm_mul_ss(_mm_mul_ss(half, est), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len2, est), est)));
    __m128 inv = _mm_andnot_ps(_mm_cmpeq_ss(len2, zero), step);
    m_vComponents = _mm_mul_ps(_mm_shuffle_ps(inv, inv, 0), m_vComponents);
}

struct DisplayTarget
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void DisplayLine(const hkVector4* a, const hkVector4* b, int c, int d, int e);
};

struct CpuObjectDerived : CpuObject
{
    void ProcessEntries_00e10a20(const hkVector4* center, hkVector4* axis, hkVector4* perp, float startAngle, float endAngle,
                      float radius, int numSegments, int a8, int a9, int a10);
};

// @fnv 0x00e10a20
// src: GUESS 0x00e10a20 (confidence: low)
void CpuObjectDerived::ProcessEntries_00e10a20(const hkVector4* center, hkVector4* axis, hkVector4* perp, float startAngle,
                                    float endAngle, float radius, int numSegments, int a8, int a9, int a10)
{
    perp->normalize3();
    axis->normalize3();
    hkRotation rot;
    rot.FUN_00cb2e30(axis, startAngle);
    __m128 rad4 = _mm_load_ss(&radius);
    rad4 = _mm_shuffle_ps(rad4, rad4, 0);
    hkVector4 cur;
    cur.m_vComponents = _mm_mul_ps(rad4, perp->m_vComponents);
    cur.hkVector4_setRotatedDir(&rot, &cur);
    cur.m_vComponents = _mm_add_ps(center->m_vComponents, cur.m_vComponents);
    float stepAngle = (endAngle - startAngle) / numSegments;
    rot.FUN_00cb2e30(axis, stepAngle);
    for (int i = 0; i < numSegments; ++i)
    {
        hkVector4 next;
        next.m_vComponents = _mm_sub_ps(cur.m_vComponents, center->m_vComponents);
        next.hkVector4_setRotatedDir(&rot, &next);
        next.m_vComponents = _mm_add_ps(center->m_vComponents, next.m_vComponents);
        ((DisplayTarget*)value)->DisplayLine(&cur, &next, a8, a9, a10);
        cur.m_vComponents = next.m_vComponents;
    }
}
