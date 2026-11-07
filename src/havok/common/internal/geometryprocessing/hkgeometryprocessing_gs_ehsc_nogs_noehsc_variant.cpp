#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit defines its own form

// src/havok/common/internal/geometryprocessing/hkgeometryprocessing_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/common/internal/geometryprocessing/hkgeometryprocessing.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/internal/geometryprocessing/hkgeometryprocessing.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/geometryprocessing/hkgeometryprocessing.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/NiPoint3.h"
#include "../../../../../include/hkSimdReal.h"
#include "../../../../../include/hkVector4.h"

extern "C" void __cdecl Deallocate(void*);
extern int DAT_010d9fc4;
struct FUN_00dee620
{
    void* m_pVTable;
    __thiscall FUN_00dee620(int testFlag);
};
extern "C" void __cdecl hkVector4_ProcessEntries_00dedf10(void*, void*, void*, void*, int, int);
void __cdecl hkGeometryProcessing_generateRandomDistribution(void* first, void* second, void* third, void* fourth);
struct FUN_00dee6b0_Class
{
    int unk00;
    float unk04;
    float GetUnk04(int testFlag);
};
extern int DAT_010cd664;
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();
struct FUN_00dee6c0_cls
{
    int m_vptr;

    FUN_00dee6c0_cls* FUN_00dee6c0(unsigned char acFlags);
};

#include <xmmintrin.h>
#include <math.h>
double __cdecl Atan2(float y, float x);


// @fnv 0x00de98c0
// src: GUESS 0x00de98c0 (confidence: low)
void NiPoint3_UpdateFields_00de98c0(const NiPoint3* v, __m128* out)
{
    float ly = v->y;
    float lx = v->x;
    float a = (Atan2(ly, lx) * 2) / 3.1415927410125732;
    float b;
    if (v->z < 0)
    {
        float r = (float)(v->z + 1.0);
        r = (float)sqrt(r);
        if (a >= 0)
        {
            if (a <= 1)
            {
                a = 1.0 - a * r;
                b = 2.0 - r - a;
            }
            else
            {
                a = (2.0 - a) * r - 1.0;
                b = 2.0 - r + a;
            }
        }
        else if (a >= -1.0f)
        {
            a = a * r + 1.0;
            b = r - 2.0 + a;
        }
        else
        {
            a = (a + 2.0) * r - 1.0;
            b = r - 2.0 - a;
        }
    }
    else
    {
        float r = (float)(1.0 - v->z);
        r = (float)sqrt(r);
        if (a >= 0)
        {
            if (a < 1)
            {
                b = a * r;
                a = r - b;
            }
            else
            {
                b = (2.0 - a) * r;
                a = b - r;
            }
        }
        else if (a > -1.0f)
        {
            b = a * r;
            a = r + b;
        }
        else
        {
            b = (a + 2.0) * -r;
            a = -(r + b);
        }
    }
    a = (float)((a + 1.0) * 0.5);
    b = (float)((b + 1.0) * 0.5);
    *out = _mm_setr_ps(a, b, 0, 0);
}

__forceinline hkSimdReal::hkSimdReal()
{}

__forceinline hkSimdReal::hkSimdReal(const __m128& x) : m_vValue(x)
{}

__forceinline hkSimdReal::operator float() const
{
    float s;
    _mm_store_ss(&s, m_vValue);
    return s;
}


__forceinline void hkVector4::setSub4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
}
__forceinline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
{
    m_vComponents =
        _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, _MM_SHUFFLE(3, 0, 2, 1)),
                              _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, _MM_SHUFFLE(3, 1, 0, 2))),
                   _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, _MM_SHUFFLE(3, 1, 0, 2)),
                              _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, _MM_SHUFFLE(3, 0, 2, 1))));
}
__forceinline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
    const __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
    const __m128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(1, 1, 1, 1)), x2);
    const __m128 z = _mm_shuffle_ps(x2, x2, _MM_SHUFFLE(2, 2, 2, 2));
    return _mm_add_ss(z, xySum);
}

struct Interval
{
    hkSimdReal m_kMinimumCorner;
    hkSimdReal m_kMaximumCorner;
};

static __forceinline void projectTriangle(const hkVector4* tri, const hkVector4& axis, Interval& out)
{
    out.m_kMaximumCorner = tri[0].dot3(axis);
    out.m_kMinimumCorner = out.m_kMaximumCorner;
    for (int i = 1; i < 3; i++)
    {
        hkSimdReal d = tri[i].dot3(axis);
        if (d < out.m_kMinimumCorner)
        {
            out.m_kMinimumCorner = d;
        }
        else if (d > out.m_kMaximumCorner)
        {
            out.m_kMaximumCorner = d;
        }
    }
}

static __forceinline bool isSeparatingAxis(const hkVector4* triA, const hkVector4* triB, const hkVector4& axis,
                                           Interval& a, Interval& b)
{
    projectTriangle(triA, axis, a);
    projectTriangle(triB, axis, b);
    return a.m_kMinimumCorner > b.m_kMaximumCorner || a.m_kMaximumCorner < b.m_kMinimumCorner;
}

static __forceinline void calcEdgeAxis(const hkVector4& a0, const hkVector4& a1, const hkVector4& b0,
                                       const hkVector4& b1, hkVector4& axis)
{
    hkVector4 ea;
    ea.setSub4(a1, a0);
    hkVector4 eb;
    eb.setSub4(b1, b0);
    axis.setCross(ea, eb);
}

// @fnv 0x00deab10
// src: XBOX_PDB 0x00deab10
int __cdecl hkGeometryProcessing_checkTrianglesIntersection(const hkVector4* triA, const hkVector4* triB)
{
    hkVector4 axis;
    Interval a;
    Interval b;
    {
        hkVector4 e0;
        e0.setSub4(triA[1], triA[0]);
        hkVector4 e1;
        e1.setSub4(triA[2], triA[0]);
        axis.setCross(e0, e1);
        if (isSeparatingAxis(triA, triB, axis, a, b))
        {
            return 0;
        }
    }
    {
        hkVector4 e0;
        e0.setSub4(triB[1], triB[0]);
        hkVector4 e1;
        e1.setSub4(triB[2], triB[0]);
        axis.setCross(e0, e1);
        if (isSeparatingAxis(triA, triB, axis, a, b))
        {
            return 0;
        }
    }
    {
        calcEdgeAxis(triA[0], triA[1], triB[0], triB[1], axis);
        if (isSeparatingAxis(triA, triB, axis, a, b))
        {
            return 0;
        }
    }
    {
        calcEdgeAxis(triA[0], triA[1], triB[1], triB[2], axis);
        if (isSeparatingAxis(triA, triB, axis, a, b))
        {
            return 0;
        }
    }
    {
        calcEdgeAxis(triA[0], triA[1], triB[2], triB[0], axis);
        if (isSeparatingAxis(triA, triB, axis, a, b))
        {
            return 0;
        }
    }
    {
        calcEdgeAxis(triA[1], triA[2], triB[0], triB[1], axis);
        if (isSeparatingAxis(triA, triB, axis, a, b))
        {
            return 0;
        }
    }
    {
        calcEdgeAxis(triA[1], triA[2], triB[1], triB[2], axis);
        if (isSeparatingAxis(triA, triB, axis, a, b))
        {
            return 0;
        }
    }
    {
        calcEdgeAxis(triA[1], triA[2], triB[2], triB[0], axis);
        if (isSeparatingAxis(triA, triB, axis, a, b))
        {
            return 0;
        }
    }
    {
        calcEdgeAxis(triA[2], triA[0], triB[0], triB[1], axis);
        if (isSeparatingAxis(triA, triB, axis, a, b))
        {
            return 0;
        }
    }
    {
        calcEdgeAxis(triA[2], triA[0], triB[1], triB[2], axis);
        if (isSeparatingAxis(triA, triB, axis, a, b))
        {
            return 0;
        }
    }
    {
        calcEdgeAxis(triA[2], triA[0], triB[2], triB[0], axis);
        if (isSeparatingAxis(triA, triB, axis, a, b))
        {
            return 0;
        }
    }
    {
        axis.setSub4(triA[0], triB[0]);
        if (isSeparatingAxis(triA, triB, axis, a, b))
        {
            return 0;
        }
    }
    {
        axis.setSub4(triA[0], triB[1]);
        if (isSeparatingAxis(triA, triB, axis, a, b))
        {
            return 0;
        }
    }
    {
        axis.setSub4(triA[0], triB[2]);
        if (isSeparatingAxis(triA, triB, axis, a, b))
        {
            return 0;
        }
    }
    {
        axis.setSub4(triA[1], triB[0]);
        if (isSeparatingAxis(triA, triB, axis, a, b))
        {
            return 0;
        }
    }
    {
        axis.setSub4(triA[1], triB[1]);
        if (isSeparatingAxis(triA, triB, axis, a, b))
        {
            return 0;
        }
    }
    {
        axis.setSub4(triA[1], triB[2]);
        if (isSeparatingAxis(triA, triB, axis, a, b))
        {
            return 0;
        }
    }
    {
        axis.setSub4(triA[2], triB[0]);
        if (isSeparatingAxis(triA, triB, axis, a, b))
        {
            return 0;
        }
    }
    {
        axis.setSub4(triA[2], triB[1]);
        if (isSeparatingAxis(triA, triB, axis, a, b))
        {
            return 0;
        }
    }
    {
        axis.setSub4(triA[2], triB[2]);
        if (isSeparatingAxis(triA, triB, axis, a, b))
        {
            return 0;
        }
    }
    return 1;
}

struct Point4;
extern Point4 DAT_01267e30;
struct __declspec(align(16)) Point4
{
    float x, y, z, w;
    __forceinline Point4()
    {
        *this = DAT_01267e30;
    }
};
extern Point4 DAT_01267e30;
struct VertexArray
{
    Point4* data;
    int size;
    int capacity;
};
struct FourPoints
{
    Point4 x, y, z;
    __forceinline void transpose(const Point4* p)
    {
        _mm_store_ps(&x.x, _mm_setr_ps(p[0].x, p[1].x, p[2].x, p[3].x));
        _mm_store_ps(&y.x, _mm_setr_ps(p[0].y, p[1].y, p[2].y, p[3].y));
        _mm_store_ps(&z.x, _mm_setr_ps(p[0].z, p[1].z, p[2].z, p[3].z));
    }
};
struct FourPointArray
{
    FourPoints* data;
    int size;
    int capacity;
};
void __cdecl hkArrayUtil__reserve(hkMemoryAllocator*, void*, int, int);
// @fnv 0x00dedcf0
// src: XBOX_PDB 0x00dedcf0
void __cdecl hkGeometryProcessing_buildTransposedArray(const VertexArray& vertices, FourPointArray& output)
{
    Point4 points[4];
    int used = 0;
    int count = (vertices.size + 3) >> 2;
    hkMemoryRouter* holder = hkMemoryRouter_getInstance();
    hkMemoryAllocator* allocator = reinterpret_cast<hkMemoryAllocator*>(holder->m_heap);
    int start = output.size;
    int required = start + count;
    int capacity = output.capacity & 0x3fffffff;
    if (capacity < required)
    {
        int grown = required >= capacity * 2 ? required : capacity * 2;
        hkArrayUtil__reserve(allocator, &output, grown, sizeof(FourPoints));
    }
    output.size += count;
    FourPoints* destination = output.data + start;
    int vertexCount = vertices.size;
    for (int i = 0; i < vertexCount; ++i)
    {
        _mm_store_ps(&points[used++].x, _mm_load_ps(&vertices.data[i].x));
        if (used == 4)
        {
            destination->transpose(points);
            used = 0;
            ++destination;
        }
    }
    if (used)
    {
        for (int i = used; i < 4;)
            _mm_store_ps(&points[i++].x, _mm_load_ps(&points[0].x));
        destination->transpose(points);
    }
}
