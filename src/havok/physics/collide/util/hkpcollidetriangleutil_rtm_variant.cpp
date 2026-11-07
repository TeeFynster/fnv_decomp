
// src/havok/physics/collide/util/hkpcollidetriangleutil_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/util/hkpcollidetriangleutil.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/collide/util/hkpcollidetriangleutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/util/hkpcollidetriangleutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Exe 0x00cd7850 FUN_00cd7850: retain this LocalM128 view; the CRT type changes the matched code.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    struct
    {
        float x, y, z, w;
    };
} __m128, LocalM128;
extern "C"
{
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_sub_ss(LocalM128, LocalM128);
    LocalM128 _mm_mul_ss(LocalM128, LocalM128);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, int);
    LocalM128 _mm_rsqrt_ss(LocalM128);
    LocalM128 _mm_set_ss(float);
    LocalM128 _mm_set_ps1(float);
    LocalM128 _mm_cmpeq_ss(LocalM128, LocalM128);
    LocalM128 _mm_cmplt_ps(LocalM128, LocalM128);
    LocalM128 _mm_andnot_ps(LocalM128, LocalM128);
    LocalM128 _mm_xor_ps(LocalM128, LocalM128);
    void _mm_store_ss(float*, LocalM128);
    LocalM128 _mm_load_ss(const float*);
    LocalM128 _mm_load_ps1(const float*);
    int _mm_movemask_ps(LocalM128);
}

#include <math.h>

// Triangle closest-point query.

typedef LocalM128 hkQuadReal;

struct TriangleLaneComparison
{
    hkQuadReal q;
    TriangleLaneComparison()
    {}
    TriangleLaneComparison(const hkQuadReal& x) : q(x)
    {}
    __forceinline int get() const
    {
        return _mm_movemask_ps(q);
    }
    __forceinline bool all() const
    {
        return (_mm_movemask_ps(q) & 7) == 7;
    }
};
struct __declspec(align(16)) S_00cd7850_Vec
{
    hkQuadReal quad;

    __forceinline void setSub4(const S_00cd7850_Vec& a, const S_00cd7850_Vec& b)
    {
        quad = _mm_sub_ps(a.quad, b.quad);
    }
    __forceinline void setCross(const S_00cd7850_Vec& v0, const S_00cd7850_Vec& v1)
    {
        const hkQuadReal cross0 =
            _mm_mul_ps(_mm_shuffle_ps(v0.quad, v0.quad, 201), _mm_shuffle_ps(v1.quad, v1.quad, 210));
        const hkQuadReal cross1 =
            _mm_mul_ps(_mm_shuffle_ps(v0.quad, v0.quad, 210), _mm_shuffle_ps(v1.quad, v1.quad, 201));
        quad = _mm_sub_ps(cross0, cross1);
    }
    __forceinline void mul4(const float& s)
    {
        const hkQuadReal t = _mm_load_ss(&s);
        quad = _mm_mul_ps(_mm_shuffle_ps(t, t, 0), quad);
    }
    __forceinline float dot3(const S_00cd7850_Vec& a) const
    {
        const hkQuadReal x2 = _mm_mul_ps(quad, a.quad);
        const hkQuadReal r = _mm_add_ss(_mm_shuffle_ps(x2, x2, 170), _mm_add_ss(_mm_shuffle_ps(x2, x2, 85), x2));
        float f;
        _mm_store_ss(&f, r);
        return f;
    }
    __forceinline hkQuadReal lengthSquared3() const
    {
        const hkQuadReal x2 = _mm_mul_ps(quad, quad);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 170), _mm_add_ss(_mm_shuffle_ps(x2, x2, 85), x2));
    }
    __forceinline float normalizeWithLength3()
    {
        S_00cd7850_Vec original;
        original.quad = quad;
        const hkQuadReal len2 = original.lengthSquared3();
        const hkQuadReal e = _mm_rsqrt_ss(len2);
        const hkQuadReal zero = _mm_set_ss(0.0f);
        const hkQuadReal ree = _mm_mul_ss(_mm_mul_ss(len2, e), e);
        const hkQuadReal isZero = _mm_cmpeq_ss(len2, zero);
        const hkQuadReal t = _mm_sub_ss(_mm_set_ss(3.0f), ree);
        const hkQuadReal r = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), e), t);
        const hkQuadReal invLen = _mm_andnot_ps(isZero, r);
        const hkQuadReal s = _mm_shuffle_ps(invLen, invLen, 0);
        quad = _mm_mul_ps(quad, s);
        float f;
        _mm_store_ss(&f, _mm_mul_ss(original.lengthSquared3(), s));
        return f;
    }
    __forceinline void set(float a, float b, float c, float d)
    {
        quad.x = a;
        quad.y = b;
        quad.z = c;
        quad.w = d;
    }
};

extern const hkQuadReal DAT_01267e30;
extern const hkQuadReal DAT_010c44d0;
extern const signed char DAT_010cb438[8];
extern const signed char DAT_010cb440[];

struct S_00cd7850_Cache
{
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
};

struct S_00cd7850_Result
{
    S_00cd7850_Vec m_kNearestPoint;
    float distance;
};

struct S_00cd7850_Features
{
    unsigned char m_uiMaterialIndex;
    unsigned short m_auiVertexIds[3];
};

int hkLineSegmentUtil_closestPointLineSeg(const S_00cd7850_Vec& pos, const S_00cd7850_Vec& a, const S_00cd7850_Vec& b, S_00cd7850_Vec* out);

// @fnv 0x00cd7850
// src: XBOX_PDB 0x00cd7850
int hkpCollideTriangleUtil_closestPointTriangle(const S_00cd7850_Vec& position, const S_00cd7850_Vec* tri, const S_00cd7850_Cache& cache,
                 S_00cd7850_Result& result, S_00cd7850_Features* featuresOut)
{
    if (featuresOut)
    {
        featuresOut->m_uiMaterialIndex = 0;
    }

    S_00cd7850_Vec relPos;
    relPos.setSub4(tri[1], position);
    S_00cd7850_Vec q;
    q.setSub4(tri[0], tri[1]);
    const float qRel = q.dot3(relPos);
    S_00cd7850_Vec w;
    w.setSub4(tri[2], tri[1]);
    const float wRel = w.dot3(relPos);

    const float eps = 0.001f;
    float u = cache.unk08 * wRel - cache.unk04 * qRel;
    float v = cache.unk08 * qRel - cache.unk00 * wRel;

    S_00cd7850_Vec uvw;
    uvw.set(u + eps, 1.0f + eps - u - v, v + eps, eps);

    TriangleLaneComparison c;
    c.q = _mm_cmplt_ps(DAT_01267e30, uvw.quad);
    int mask = c.get();
    if (c.all())
    {
        result.m_kNearestPoint.setCross(q, w);
        result.m_kNearestPoint.mul4(cache.unk0c);
        float dist = result.m_kNearestPoint.dot3(relPos);
        result.distance = dist;
        if (dist > 0.0f)
        {
            result.m_kNearestPoint.quad = _mm_xor_ps(result.m_kNearestPoint.quad, DAT_010c44d0);
        }
        else
        {
            result.distance = -dist;
        }
        if (featuresOut)
        {
            featuresOut->m_uiMaterialIndex = 3;
            featuresOut->m_auiVertexIds[0] = 0;
            featuresOut->m_auiVertexIds[1] = 1;
            featuresOut->m_auiVertexIds[2] = 2;
        }
        return 0;
    }

    int index = DAT_010cb438[mask & 7];
    if (index < 0)
    {
        index += 8;
        int code = hkLineSegmentUtil_closestPointLineSeg(position, tri[DAT_010cb440[index + 2]], tri[DAT_010cb440[index]], &uvw);
        if (featuresOut)
        {
            if (code == 4)
            {
                featuresOut->m_auiVertexIds[0] = DAT_010cb440[index];
                featuresOut->m_uiMaterialIndex = 1;
            }
            else if (code == 8)
            {
                featuresOut->m_auiVertexIds[0] = DAT_010cb440[index + 2];
                featuresOut->m_uiMaterialIndex = 1;
            }
            else
            {
                featuresOut->m_auiVertexIds[0] = DAT_010cb440[index];
                featuresOut->m_auiVertexIds[1] = DAT_010cb440[index + 2];
                featuresOut->m_uiMaterialIndex = 2;
            }
        }
        result.m_kNearestPoint.setSub4(position, uvw);
        result.distance = result.m_kNearestPoint.normalizeWithLength3();
        return 1;
    }

    S_00cd7850_Vec p1;
    int code0 = hkLineSegmentUtil_closestPointLineSeg(position, tri[index], tri[DAT_010cb440[index + 2]], &uvw);
    int code1 = hkLineSegmentUtil_closestPointLineSeg(position, tri[DAT_010cb440[index]], tri[index], &p1);
    S_00cd7850_Vec deltaA;
    deltaA.setSub4(position, uvw);
    S_00cd7850_Vec deltaB;
    deltaB.setSub4(position, p1);
    float len0 = deltaA.dot3(deltaA);
    float len1 = deltaB.dot3(deltaB);
    if (len0 < len1)
    {
        float invLen = 1.0f / float(sqrt(len0));
        if (featuresOut)
        {
            if (code0 == 4)
            {
                featuresOut->m_uiMaterialIndex = 1;
                featuresOut->m_auiVertexIds[0] = (unsigned short)index;
            }
            else if (code0 == 8)
            {
                featuresOut->m_uiMaterialIndex = 1;
                featuresOut->m_auiVertexIds[0] = DAT_010cb440[index + 2];
            }
            else
            {
                featuresOut->m_uiMaterialIndex = 2;
                featuresOut->m_auiVertexIds[0] = (unsigned short)index;
                featuresOut->m_auiVertexIds[1] = DAT_010cb440[index + 2];
            }
        }
        result.distance = len0 * invLen;
        result.m_kNearestPoint.quad =
            _mm_mul_ps(_mm_shuffle_ps(_mm_load_ss(&invLen), _mm_load_ss(&invLen), 0), deltaA.quad);
        return 1;
    }
    else
    {
        float invLen = 1.0f / float(sqrt(len1));
        if (featuresOut)
        {
            if (code1 == 4)
            {
                featuresOut->m_uiMaterialIndex = 1;
                featuresOut->m_auiVertexIds[0] = (unsigned short)index;
            }
            else if (code1 == 8)
            {
                featuresOut->m_uiMaterialIndex = 1;
                featuresOut->m_auiVertexIds[0] = DAT_010cb440[index];
            }
            else
            {
                featuresOut->m_uiMaterialIndex = 2;
                featuresOut->m_auiVertexIds[0] = (unsigned short)index;
                featuresOut->m_auiVertexIds[1] = DAT_010cb440[index];
            }
        }
        result.distance = len1 * invLen;
        result.m_kNearestPoint.quad =
            _mm_mul_ps(_mm_shuffle_ps(_mm_load_ss(&invLen), _mm_load_ss(&invLen), 0), deltaB.quad);
        return 1;
    }
}
