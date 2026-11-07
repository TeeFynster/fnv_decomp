
// src/havok/physics/collide/shape/heightfield/plane/hkpplaneshape_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/shape/heightfield/plane/hkpplaneshape.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/shape/heightfield/plane/hkpplaneshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/heightfield/plane/hkpplaneshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../../include/hkpPlaneShape.h"
#include "../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../include/Vec4.h"
#include <xmmintrin.h>
extern __m128 DAT_010ec7f0;
extern __m128 DAT_01017d10;

struct SimdReal
{
    __m128 m_vValue;
    operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
};

struct VecCompare
{
    __m128 m_uiMask;
    bool allAreSetXYZ() const
    {
        return (_mm_movemask_ps(m_uiMask) & 7) == 7;
    }
};

inline __m128& Vec4::getQuad()
{
    return *reinterpret_cast<__m128*>(this);
}

inline const __m128& Vec4::getQuad() const
{
    return *reinterpret_cast<const __m128*>(this);
}

inline SimdReal Vec4::dot4xyz1(const Vec4& x) const
{
    __m128 x2 = _mm_mul_ps(getQuad(), x.getQuad());
    __m128 w = _mm_shuffle_ps(getQuad(), getQuad(), _MM_SHUFFLE(3, 3, 3, 3));
    __m128 r = _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(2, 2, 2, 2)), w);
    SimdReal s;
    s.m_vValue = _mm_add_ps(r, _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(1, 1, 1, 1)), x2));
    return s;
}

inline void Vec4::setInterpolate4(const Vec4& a, const Vec4& b, float t)
{
    __m128 tt = _mm_set1_ps(t);
    getQuad() = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(DAT_010ec7f0, tt), a.getQuad()), _mm_mul_ps(b.getQuad(), tt));
}

inline void Vec4::sub4(const Vec4& a)
{
    getQuad() = _mm_sub_ps(getQuad(), a.getQuad());
}

inline void Vec4::setAbs4(const Vec4& a)
{
    getQuad() = _mm_and_ps(a.getQuad(), DAT_01017d10);
}

inline VecCompare Vec4::compareLessThanEqual4(const Vec4& a) const
{
    VecCompare c;
    c.m_uiMask = _mm_cmple_ps(getQuad(), a.getQuad());
    return c;
}

struct __declspec(align(16)) AlignedVec4
{
    float x;
    float y;
    float z;
    float w;
};

struct RayInput
{
    Vec4 m_vFrom;
    Vec4 m_vTo;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    float m_fSphereRadius;
    float m_fRayDistance;
};

struct RayOutput
{
    RayOutput()
    {
        m_uiShapeKeyIndex = 0;
        m_iExtraInfo = -1;
        m_shapeKey0 = -1;
    }
    AlignedVec4 m_vHitNormal;
    float m_fHitFraction;
    int m_iExtraInfo;
    void* unk18;
    int unk1C;
    int m_shapeKey0;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int m_uiShapeKeyIndex;
    int unk44;
    int unk48;
    int unk4C;
};

struct CdBody;

struct RayCollector
{
    virtual void CollectRayHit(const CdBody& body, const RayOutput& out) = 0;
};

struct PlaneShapeStandIn
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Vec4 m_kTriangleNormal;
    Vec4 m_kAabbCenter;
    Vec4 m_kAabbHalfExtents;

    void hkpPlaneShape_castSphere(const RayInput& input, const CdBody& body, RayCollector& collector) const;
};

// @fnv 0x00d55000
// src: XBOX_PDB 0x00d55000
void PlaneShapeStandIn::hkpPlaneShape_castSphere(const RayInput& input, const CdBody& body, RayCollector& collector) const
{
    float radius = input.m_fSphereRadius;
    float fromDist = m_kTriangleNormal.dot4xyz1(input.m_vFrom) - radius;
    float toDist = m_kTriangleNormal.dot4xyz1(input.m_vTo) - radius;
    if (!(toDist >= 0.0f))
    {
        if (!(fromDist - toDist < input.m_fRayDistance))
        {
            float frac = (fromDist <= 0.0f) ? 0.0f : fromDist / (fromDist - toDist);
            __declspec(align(16)) Vec4 hitPoint;
            hitPoint.setInterpolate4(input.m_vFrom, input.m_vTo, frac);
            hitPoint.sub4(m_kAabbCenter);
            hitPoint.setAbs4(hitPoint);
            if (hitPoint.compareLessThanEqual4(m_kAabbHalfExtents).allAreSetXYZ())
            {
                RayOutput out;
                _mm_store_ps(&out.m_vHitNormal.x, m_kTriangleNormal.getQuad());
                out.m_fHitFraction = frac;
                collector.CollectRayHit(body, out);
            }
        }
    }
}

struct FUN_00d55160_Source
{
    float* points;
    int count;
};
class FUN_00d55160_StandIn : public hkpPlaneShape
{
  public:
    void __thiscall hkpPlaneShape_collideSpheres(FUN_00d55160_Source* source, float* destination);
};
// @fnv 0x00d55160
// src: XBOX_PDB 0x00d55160
void __thiscall FUN_00d55160_StandIn::hkpPlaneShape_collideSpheres(FUN_00d55160_Source* source, float* destination)
{
    float* output = destination;
    float* points = source->points;
    int count = source->count - 1;
    if (count < 0)
        return;
    do
    {
        __m128 plane = _mm_load_ps(&this->m_kTriangleNormal.x);
        _mm_store_ps(output, plane);
        __m128 planeForProduct = _mm_load_ps(&this->m_kTriangleNormal.x);
        __m128 point = _mm_load_ps(points);
        __m128 product = _mm_mul_ps(point, planeForProduct);
        __m128 planeW = _mm_shuffle_ps(planeForProduct, planeForProduct, _MM_SHUFFLE(3, 3, 3, 3));
        __m128 sum = _mm_shuffle_ps(product, product, _MM_SHUFFLE(2, 2, 2, 2));
        sum = _mm_add_ss(sum, planeW);
        __m128 term = _mm_shuffle_ps(product, product, _MM_SHUFFLE(1, 1, 1, 1));
        term = _mm_add_ss(term, product);
        sum = _mm_add_ps(sum, term);
        float value;
        _mm_store_ss(&value, sum);
        output[3] = value - points[3];
        output += 4;
        points += 4;
        --count;
    } while (count >= 0);
}
