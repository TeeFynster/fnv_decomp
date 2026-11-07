#include "../../../../../../../include/hkArray.h"

// src/havok/physics/internal/collide/mopp/machine/hkpmoppraybundlevirtualmachine_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/internal/collide/mopp/machine/hkpmoppraybundlevirtualmachine.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include "fnv_asm_helpers.h"
#define FNV_VEC4_SIMD
#include "../../../../../../../include/Vec4.h"
#include "../../../../../../../include/CodeInfo.h"
// src/havok/physics/internal/collide/mopp/machine/hkpmoppraybundlevirtualmachine.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/mopp/machine/hkpmoppraybundlevirtualmachine.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <xmmintrin.h>
__declspec(align(16)) struct FUN_00dd4a50_cls
{
    __m128 m_v00;
    unsigned int m_i10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    __m128 m_v20;
    unsigned int m_i30;
    unsigned int m_i34;

    FUN_00dd4a50_cls* InitializeFields_00dd4a50(const FUN_00dd4a50_cls* src);
};

extern const double DAT_010d5198;
extern const __m128 DAT_01268460;

__forceinline void Vec4::operator=(const Vec4& v)
{
    m_vComponents = v.m_vComponents;
}

__forceinline void Vec4::setZero4()
{
    m_vComponents = _mm_setzero_ps();
}

__forceinline void Vec4::setSub4(const Vec4& v0, const Vec4& v1)
{
    m_vComponents = _mm_sub_ps(v0.m_vComponents, v1.m_vComponents);
}

__forceinline void Vec4::mul4(const Vec4& v)
{
    m_vComponents = _mm_mul_ps(m_vComponents, v.m_vComponents);
}

// These operations have no matching overload in the shared Vec4 declaration.
static __forceinline void SetAllComponents(Vec4& value, float a)
{
    value.m_vComponents = _mm_set_ps1(a);
}

static __forceinline void setBroadcast(Vec4& value, const hkVector4& v, int i)
{
    if (i == 0)
    {
        value.m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, _MM_SHUFFLE(0, 0, 0, 0));
    }
    else if (i == 1)
    {
        value.m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, _MM_SHUFFLE(1, 1, 1, 1));
    }
    else if (i == 2)
    {
        value.m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, _MM_SHUFFLE(2, 2, 2, 2));
    }
    else if (i == 3)
    {
        value.m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, _MM_SHUFFLE(3, 3, 3, 3));
    }
}

class __declspec(align(16)) Vec4Comp
{
public:
    enum Mask
    {
        MASK_NONE = 0
    };

    __forceinline void set(Mask)
    {
        m_uiMask = DAT_01268460;
    }

private:
    __m128 m_uiMask;
    friend class Vec4;
};



inline float CodeInfo::getScale() const
{
    return m_offset.m_f[3];
}

struct TreeCode
{
    void* vftable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    CodeInfo m_info;
    hkArrayBase<unsigned char> m_data;
    signed char m_eBuildType;
};

struct RayBundleInput
{
    Vec4 m_vFrom[3];
    Vec4 m_vTo[3];
    unsigned int m_uiFilterInfo;
    const void* m_pRayShapeCollectionFilter;
};

struct RayBundleOutput;
class ShapeContainer;

struct PointBundle
{
    Vec4 m_vec[3];
};

class BaseMachine
{
public:
    void* m_pPrimitiveInfoArray;
    int unk04;
    int unk08;
    int unk0c;
};

class BundleMachine : public BaseMachine
{
public:
    struct MachineVectorIndexRecord
    {
        Vec4 m_kVectorBeforeIndex;
        int m_iIndex;
        Vec4 m_kVectorAfterIndex;
        unsigned int m_uiPropertyCount;
        unsigned int m_kProperties[1];
    };

    struct PointBundlePairAndVector
    {
        PointBundle m_kPointBundles[2];
        Vec4Comp m_kVectorComponent;
    };

    const TreeCode* m_pMoppCode;
    Vec4 m_vRayDirectionVector;
    const RayBundleInput* m_kRays;
    PointBundle m_vTo;
    PointBundle m_vFrom;
    Vec4Comp m_vRayDelta;
    Vec4 m_fEarlyOutHitFraction;
    RayBundleOutput* m_pRayBundleOutput;
    void* m_kCollector;
    const void* m_kCollisionBody;
    const ShapeContainer* m_pShapeCollection;
    int m_iCurrentChunkId;

    void hkpMoppRayBundleVirtualMachine_queryRayOnTree(const MachineVectorIndexRecord* query, const unsigned char* pc, PointBundlePairAndVector* fQuery, int chunkId);
    __forceinline void querySub(const TreeCode* code, const RayBundleInput& input, const Vec4Comp& mask);
    Vec4Comp UpdateState_00dd4870(const ShapeContainer* collection, const TreeCode* code, const RayBundleInput& input, RayBundleOutput& rayResult, const Vec4Comp& mask);
};

inline void BundleMachine::querySub(const TreeCode* code, const RayBundleInput& input, const Vec4Comp& mask)
{
    m_pMoppCode = code;
    const unsigned char* programCounter = &m_pMoppCode->m_data[0];

    MachineVectorIndexRecord query;
    query.m_kVectorBeforeIndex.setZero4();

    SetAllComponents(m_vRayDirectionVector, 1.0f / m_pMoppCode->m_info.getScale());
    SetAllComponents(query.m_kVectorAfterIndex, float(m_pMoppCode->m_info.getScale() * DAT_010d5198));

    Vec4 offset;
    PointBundlePairAndVector fQuery;

    setBroadcast(offset, code->m_info.m_offset, 0);
    fQuery.m_kPointBundles[0].m_vec[0].setSub4(m_vFrom.m_vec[0], offset);
    fQuery.m_kPointBundles[1].m_vec[0].setSub4(m_vTo.m_vec[0], offset);
    fQuery.m_kPointBundles[0].m_vec[0].mul4(query.m_kVectorAfterIndex);
    fQuery.m_kPointBundles[1].m_vec[0].mul4(query.m_kVectorAfterIndex);

    setBroadcast(offset, code->m_info.m_offset, 1);
    fQuery.m_kPointBundles[0].m_vec[1].setSub4(m_vFrom.m_vec[1], offset);
    fQuery.m_kPointBundles[1].m_vec[1].setSub4(m_vTo.m_vec[1], offset);
    fQuery.m_kPointBundles[0].m_vec[1].mul4(query.m_kVectorAfterIndex);
    fQuery.m_kPointBundles[1].m_vec[1].mul4(query.m_kVectorAfterIndex);

    setBroadcast(offset, code->m_info.m_offset, 2);
    fQuery.m_kPointBundles[0].m_vec[2].setSub4(m_vFrom.m_vec[2], offset);
    fQuery.m_kPointBundles[1].m_vec[2].setSub4(m_vTo.m_vec[2], offset);
    fQuery.m_kPointBundles[0].m_vec[2].mul4(query.m_kVectorAfterIndex);
    fQuery.m_kPointBundles[1].m_vec[2].mul4(query.m_kVectorAfterIndex);

    fQuery.m_kVectorComponent = mask;
    m_kRays = &input;
    m_vRayDelta.set(Vec4Comp::MASK_NONE);

    query.m_uiPropertyCount = 0;
    query.m_iIndex = 0;
    for (int p = 0; p < 1; p++)
    {
        query.m_kProperties[p] = 0;
    }

    m_iCurrentChunkId = (programCounter[0] != 0x0d) - 1;

    hkpMoppRayBundleVirtualMachine_queryRayOnTree(&query, programCounter, &fQuery, 0);
}

// @fnv 0x00dd4870
// src: GUESS 0x00dd4870 (confidence: low)
Vec4Comp BundleMachine::UpdateState_00dd4870(const ShapeContainer* collection, const TreeCode* code, const RayBundleInput& input, RayBundleOutput& rayResult, const Vec4Comp& mask)
{
    m_pShapeCollection = collection;
    m_pRayBundleOutput = &rayResult;
    SetAllComponents(m_fEarlyOutHitFraction, 1.0f);

    m_vFrom.m_vec[0] = input.m_vFrom[0];
    m_vFrom.m_vec[1] = input.m_vFrom[1];
    m_vFrom.m_vec[2] = input.m_vFrom[2];

    m_vTo.m_vec[0] = input.m_vTo[0];
    m_vTo.m_vec[1] = input.m_vTo[1];
    m_vTo.m_vec[2] = input.m_vTo[2];

    querySub(code, input, mask);

    return m_vRayDelta;
}
