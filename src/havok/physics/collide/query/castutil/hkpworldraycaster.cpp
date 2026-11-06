#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit keeps the out-of-line hkVector4 form

// src/havok/physics/collide/query/castutil/hkpworldraycaster.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/query/castutil/hkpworldraycaster.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Preserve the original intrinsic declaration: the byte/short lanes in the
// toolchain's xmmintrin.h change MSVC's alias analysis and generated code.
#ifndef _INCLUDED_MM2
#define _INCLUDED_MM2

// Exe 0x00cbf710 CastRay: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    __int32 m128_i32[4];
    __int64 m128_i64[2];
    unsigned __int32 m128_u32[4];
} __m128, LocalM128;

extern "C" LocalM128 _mm_mul_ps(LocalM128 _A, LocalM128 _B);
extern "C" LocalM128 _mm_add_ps(LocalM128 _A, LocalM128 _B);
extern "C" LocalM128 _mm_sub_ps(LocalM128 _A, LocalM128 _B);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128 _A, LocalM128 _B, unsigned int _Imm8);
extern "C" LocalM128 _mm_unpacklo_ps(LocalM128 _A, LocalM128 _B);
extern "C" LocalM128 _mm_unpackhi_ps(LocalM128 _A, LocalM128 _B);
extern "C" LocalM128 _mm_movelh_ps(LocalM128 _A, LocalM128 _B);
extern "C" LocalM128 _mm_movehl_ps(LocalM128 _A, LocalM128 _B);

#endif

#include "../../../../../../include/hkBool.h"
#include "../../../../../../include/hkRotation.h"
#include "../../../../../../include/hkTransform.h"
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkpCdBody.h"
#include "../../../../../../include/hkpCollidable.h"
#include "../../../../../../include/hkpRayCollidableFilter.h"
#include "../../../../../../include/hkpRayHitCollector.h"
#include "../../../../../../include/hkpShape.h"
#include "../../../../../../include/hkpTypedBroadPhaseHandle.h"



__forceinline void hkVector4::_setRotatedInverseDir(const hkRotation& r, const hkVector4& b)
{
    LocalM128 v = b.m_vComponents;
    LocalM128 c0 = r.m_kColumn0.m_vComponents;
    LocalM128 c1 = r.m_kColumn1.m_vComponents;
    LocalM128 c2 = r.m_kColumn2.m_vComponents;
    LocalM128 tmp = _mm_unpacklo_ps(c0, c1);
    LocalM128 ctmp = _mm_shuffle_ps(_mm_unpackhi_ps(c0, c1), c2, 0xe4);
    c0 = _mm_movelh_ps(tmp, c2);
    c1 = _mm_movehl_ps(c0, tmp);
    c1 = _mm_shuffle_ps(c1, c2, 0xd4);
    c2 = ctmp;
    LocalM128 r1 = _mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), c1);
    LocalM128 r0 = _mm_mul_ps(_mm_shuffle_ps(v, v, 0x00), c0);
    LocalM128 r2 = _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), c2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r1, r0), r2);
}

__forceinline const hkRotation& hkTransform::getRotation() const
{
    return reinterpret_cast<const hkRotation&>(m_row0);
}

__forceinline const hkVector4& hkTransform::getTranslation() const
{
    return reinterpret_cast<const hkVector4&>(m_row3);
}

__forceinline void hkVector4::SetTransformedPosition(const hkTransform& a, const hkVector4& b)
{
    hkVector4 t0;
    t0.m_vComponents = _mm_sub_ps(b.m_vComponents, a.getTranslation().m_vComponents);
    _setRotatedInverseDir(a.getRotation(), t0);
}

inline const hkpShape* hkpCdBody::getShape() const
{
    return m_pCollisionShape;
}

inline const hkTransform& hkpCdBody::getTransform() const
{
    return *static_cast<const hkTransform*>(m_pMotionState);
}

inline void* hkpTypedBroadPhaseHandle::getOwner() const
{
    return (void*)((char*)this + m_iOwnerOffset);
}

struct WorldRayCastInput
{
    hkVector4 m_vFrom;
    hkVector4 m_vTo;
    hkBool m_bEnableShapeCollectionFilter;
    unsigned int m_uiFilterInfo;
};

struct ShapeRayCastQuery
{
    hkVector4 m_vFrom;
    hkVector4 m_vTo;
    unsigned int m_uiFilterInfo;
};

class hkpWorldRayCaster
{
  public:
    void* m_vtbl;
    const WorldRayCastInput* m_pRayCastInput;
    const hkpRayCollidableFilter* m_iFilter;
    hkpRayHitCollector* m_pCollectorBase;
    int m_iCollectorStriding;
    ShapeRayCastQuery m_kShapeRayInput;

    float CastRay(const hkpTypedBroadPhaseHandle* broadPhaseHandle, int castIndex);
};

// @fnv 0x00cbf710
float hkpWorldRayCaster::CastRay(const hkpTypedBroadPhaseHandle* broadPhaseHandle, int castIndex)
{
    const hkpCollidable* col = (const hkpCollidable*)broadPhaseHandle->getOwner();
    const hkpCdBody* body = reinterpret_cast<const hkpCdBody*>(col);
    const hkpShape* shape = body->getShape();

    hkpRayHitCollector* collector = (hkpRayHitCollector*)((char*)m_pCollectorBase + m_iCollectorStriding * castIndex);

    if (shape)
    {
        const WorldRayCastInput& input = m_pRayCastInput[castIndex];
        if (m_iFilter->IsCollisionEnabled(input, *col))
        {
            const hkTransform& trans = body->getTransform();
            m_kShapeRayInput.m_vFrom.SetTransformedPosition(trans, m_pRayCastInput->m_vFrom);
            m_kShapeRayInput.m_vTo.SetTransformedPosition(trans, input.m_vTo);
            m_kShapeRayInput.m_uiFilterInfo = input.m_uiFilterInfo;
            shape->CastRayWithCollector(m_kShapeRayInput, *body, *collector);
        }
    }
    return collector->m_fEarlyOutHitFraction;
}
