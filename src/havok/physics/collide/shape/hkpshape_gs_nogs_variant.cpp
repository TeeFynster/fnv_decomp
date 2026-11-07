
// src/havok/physics/collide/shape/hkpshape_gs_nogs_variant.cpp - flag-variant unit created 2026-10-25 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/collide/shape/hkpshape.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/shape/hkpshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/hkpshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpShape.h"
int __stdcall hkpConvexTransformShapeBase_calcSizeForSpu(void* p, int size);

#include <xmmintrin.h>
struct hkSimdVector4
{
    __m128 m_vComponents;
};

struct Vector4Comparison
{
    __m128 m_uiMask;
    static const int s_masks[4];
    static const __m128 s_maskToComparison[16];
};

struct hkFourTransposedPoints
{
    hkSimdVector4 m_kVertices[3];
};

struct ShapeRayCastQuery
{
    hkSimdVector4 m_vFrom;
    hkSimdVector4 m_vTo;
    hkUint32 m_uiFilterInfo;
    const void* m_pRayShapeCollectionFilter;
};

struct ShapeRayBundleCastInput
{
    hkFourTransposedPoints m_vFrom;
    hkFourTransposedPoints m_vTo;
    hkUint32 m_uiFilterInfo;
    const void* m_pRayShapeCollectionFilter;
};

struct ShapeRayCastOutput
{
    char m_data[0x50];
};

struct ShapeRayCastOutputArray
{
    ShapeRayCastOutput m_akRayOutputs[4];
};

struct hkBoolRet
{
    hkBool m_cBooleanValue;
};

class hkpShapeBase : public hkpShape
{
  public:
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual hkBoolRet RayCast(const ShapeRayCastQuery& input, ShapeRayCastOutput& output) const;
    Vector4Comparison hkpBoxShape_castRayBundleImpl(const ShapeRayBundleCastInput& input, ShapeRayCastOutputArray& results,
                                   const Vector4Comparison& mask) const;
};

static inline void extractPoints(const hkFourTransposedPoints& p, __m128* out)
{
    __m128 r0 = p.m_kVertices[0].m_vComponents;
    __m128 r1 = p.m_kVertices[1].m_vComponents;
    __m128 r2 = p.m_kVertices[2].m_vComponents;
    __m128 r3 = _mm_setzero_ps();
    _MM_TRANSPOSE4_PS(r0, r1, r2, r3);
    out[0] = r0;
    out[1] = r1;
    out[2] = r2;
    out[3] = r3;
}

// @fnv 0x00c9e400
// src: HAVOK_SRC 0x00c9e400
Vector4Comparison hkpShapeBase::hkpBoxShape_castRayBundleImpl(const ShapeRayBundleCastInput& input, ShapeRayCastOutputArray& results,
                                             const Vector4Comparison& mask) const
{
    __m128 from[4];
    __m128 to[4];
    extractPoints(input.m_vFrom, from);
    extractPoints(input.m_vTo, to);

    ShapeRayCastQuery singleInput;
    singleInput.m_uiFilterInfo = input.m_uiFilterInfo;
    singleInput.m_pRayShapeCollectionFilter = input.m_pRayShapeCollectionFilter;

    int resultMask = 0;
    for (int i = 0; i < 4; i++)
    {
        if (_mm_movemask_ps(mask.m_uiMask) & Vector4Comparison::s_masks[i])
        {
            singleInput.m_vFrom.m_vComponents = from[i];
            singleInput.m_vTo.m_vComponents = to[i];
            hkBool hit = IntersectRayWithShape(singleInput, results.m_akRayOutputs[i]);
            if (hit.m_cBooleanValue)
            {
                resultMask |= Vector4Comparison::s_masks[i];
            }
        }
    }

    Vector4Comparison result;
    result.m_uiMask = Vector4Comparison::s_maskToComparison[resultMask];
    return result;
}
