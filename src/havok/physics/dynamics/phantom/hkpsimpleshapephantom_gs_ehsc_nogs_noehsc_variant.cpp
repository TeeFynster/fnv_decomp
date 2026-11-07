
// src/havok/physics/dynamics/phantom/hkpsimpleshapephantom_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/dynamics/phantom/hkpsimpleshapephantom.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/dynamics/phantom/hkpsimpleshapephantom.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/phantom/hkpsimpleshapephantom.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../include/hkArray.h"
#include "../../../../../include/hkBool.h"
#include "../../../../../include/hkStatisticsCollector.h"
#include "../../../../../include/hkpCdBody.h"
#include "../../../../../include/hkpCollidable.h"
#include "../../../../../include/hkpCollisionDispatcher.h"
#include "../../../../../include/hkpShape.h"
#include "../../../../../include/hkpSimpleShapePhantom.h"
#include "../../../../../include/hkpWorld.h"

#include <xmmintrin.h>
struct LcVec4
{
    __m128 m_vComponents;
    void operator=(const LcVec4& v)
    {
        m_vComponents = v.m_vComponents;
    }
};
struct LcAabb
{
    LcVec4 unk00;
    LcVec4 unk10;
};

struct LcPadReal
{
    float m_kStorage;
    void operator=(const float& t)
    {
        m_kStorage = t;
    }
    operator float() const
    {
        return m_kStorage;
    }
};

struct LcCollisionInput
{
    int unk00;
    int unk04;
    LcPadReal unk08;
    int unk0c;
    int unk10;
    int unk14;
    LcVec4 unk20;
    LcVec4 unk30;
    LcVec4 unk40;
};
struct LcProcessInput : LcCollisionInput
{
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
};
struct LcCastInput : LcCollisionInput
{
    LcVec4 unk50;
    float unk60;
    float unk64;
    int unk68;
    LcCastInput()
    {
        unk04 = 0;
        unk60 = LC_EPS;
    }
    static const float LC_EPS;
};

typedef void (*LcCastFunc)(const hkpCollidable&, const hkpCollidable&, const LcCastInput&, void*, void*);

struct LcCastIn
{
    LcVec4 unk00;
    float unk10;
    float unk14;
};

class hkpSimpleShapePhantomCollisionDetail
{
public:
    hkpCollidable* m_kCollidable;
};

// 0x00d1f270 uses the shared phantom layout; this extension supplies methods absent from its header.
struct PositionAndLinearCastPhantom : hkpSimpleShapePhantom
{
    void hkpPhantom_updateBroadPhase(LcAabb* aabb);
    void hkpSimpleShapePhantom_setPositionAndLinearCast(const LcVec4& position, const LcCastIn& input, void* castCollector, void* startCollector);
};

// @fnv 0x00d1f270
// src: HAVOK_SRC 0x00d1f270
void PositionAndLinearCastPhantom::hkpSimpleShapePhantom_setPositionAndLinearCast(const LcVec4& position, const LcCastIn& input, void* castCollector, void* startCollector)
{
    m_kMotionState.m_kMotionTransform.m_vTranslation = position.m_vComponents;
    LcAabb aabb;
    hkpCollidable* collidable = &m_kCollidable;
    float halfTolerance = static_cast<LcProcessInput*>(static_cast<hkpWorld*>(m_pOwningWorld)->m_pCollisionInput)->unk08 * 0.5;
    m_kCollidable.m_pCollisionShape->CalculateAabb(m_kMotionState.m_kMotionTransform, halfTolerance + input.unk14,
                               reinterpret_cast<hkAabb&>(aabb));

    LcVec4 path;
    path.m_vComponents = _mm_sub_ps(input.unk00.m_vComponents, position.m_vComponents);
    __m128 zero = _mm_setzero_ps();
    __m128 pathMin = _mm_min_ps(zero, path.m_vComponents);
    __m128 pathMax = _mm_max_ps(zero, path.m_vComponents);
    aabb.unk00.m_vComponents = _mm_add_ps(aabb.unk00.m_vComponents, pathMin);
    aabb.unk10.m_vComponents = _mm_add_ps(aabb.unk10.m_vComponents, pathMax);
    hkpPhantom_updateBroadPhase(&aabb);

    LcCastInput lcInput;
    const LcProcessInput* in = static_cast<const LcProcessInput*>(static_cast<hkpWorld*>(m_pOwningWorld)->m_pCollisionInput);
    static_cast<LcCollisionInput&>(lcInput) = *in;
    lcInput.unk68 = in->unk70;
    lcInput.unk50 = path;
    __m128 x2 = _mm_mul_ps(path.m_vComponents, path.m_vComponents);
    __m128 len = _mm_sqrt_ss(_mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2)));
    float l;
    _mm_store_ss(&l, len);
    lcInput.unk64 = l;
    lcInput.unk08 = input.unk14;
    lcInput.unk60 = input.unk10;

    hkpCollisionDispatcher* dispatcher = static_cast<hkpCollisionDispatcher*>(static_cast<hkpWorld*>(m_pOwningWorld)->m_pDispatcher);
    for (int i = m_kCollisionDetails.GetLogicalSize() - 1; i >= 0; i--)
    {
        hkpCollidable* const& collidableB = m_kCollisionDetails[i].m_kCollidable;
        LcCastFunc func = reinterpret_cast<LcCastFunc>(
            dispatcher->m_agent2Funcs[
                dispatcher->m_agent2TypeMap[reinterpret_cast<const hkpShapeType&>(collidable->m_pCollisionShape->m_type)]
                                          [reinterpret_cast<const hkpShapeType&>(collidableB->m_pCollisionShape->m_type)]]
                .m_pLinearCastFunc);
        func(*collidable, *collidableB, lcInput, castCollector, startCollector);
    }
}
