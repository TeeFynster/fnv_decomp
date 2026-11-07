
// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpconvexradiusbuilder_gs_nogs_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/utilities/visualdebugger/viewer/collide/hkpconvexradiusbuilder.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpconvexradiusbuilder.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/collide/hkpconvexradiusbuilder.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>
struct __declspec(align(16)) hkVector4f
{
    float x;
    float y;
    float z;
    float w;
};

struct __declspec(align(16)) hkTransformf
{
    hkVector4f m_kColumn0;
    hkVector4f m_kColumn1;
    hkVector4f m_kColumn2;
    hkVector4f m_vTranslation;
};

struct RootPair
{
    const void* m_rootA;
    const void* m_rootB;
};

struct PairArray
{
    RootPair* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void clear()
    {
        m_iElementCount = 0;
    }
};

struct OutputStandIn
{
    void* m_vtbl;
    int m_unk04;
};

struct CollectorStandIn
{
    void* m_vtbl;
    int m_unk04;
    PairArray m_kHits;

    void ClearField0c();
    void hkpConvexRadiusBuilder_buildShapeDisplay(const char* pInput, const hkTransformf* pTransform, OutputStandIn* pOutput);
    void UpdateFields_00de4420(const char* pInput, OutputStandIn* pOutput);
};

// src: GUESS 0x00de3090 (confidence: low)
__declspec(noinline) void CollectorStandIn::ClearField0c()
{
    m_kHits.clear();
}

// @fnv 0x00de4420
// src: GUESS 0x00de4420 (confidence: low)
void CollectorStandIn::UpdateFields_00de4420(const char* pInput, OutputStandIn* pOutput)
{
    hkTransformf t;
    float one = 1.0f;
    *(__m128*)&t.m_kColumn0 = _mm_setzero_ps();
    t.m_kColumn0.x = one;
    *(__m128*)&t.m_kColumn1 = _mm_setzero_ps();
    t.m_kColumn1.y = one;
    *(__m128*)&t.m_kColumn2 = _mm_setzero_ps();
    t.m_kColumn2.z = one;
    *(__m128*)&t.m_vTranslation = _mm_setzero_ps();
    ClearField0c();
    pOutput->m_unk04 = 0;
    hkpConvexRadiusBuilder_buildShapeDisplay(pInput, &t, pOutput);
}
