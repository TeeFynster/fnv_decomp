
// src/havok/physics/dynamics/constraint/bilateral/pointtopath/hkplinearparametriccurve.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/bilateral/pointtopath/hkplinearparametriccurve.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Exe 0x00e47440 FUN_00e47440: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;

#include "../../../../../../../include/hkpLinearParametricCurve.h"
#include "../../../../../../../include/hkArray.h"
#include "../../../../../../../include/hkBaseObject.h"
#include "../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/hkSimdReal.h"
#include "../../../../../../../include/MemoryManager.h"
#include <new>

extern "C"
{
    LocalM128 _mm_load_ps1(const float*);
    LocalM128 _mm_load_ps(const float*);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_sub_ss(LocalM128, LocalM128);
    LocalM128 _mm_mul_ss(LocalM128, LocalM128);
    LocalM128 _mm_rsqrt_ss(LocalM128);
    LocalM128 _mm_cmpeq_ss(LocalM128, LocalM128);
    LocalM128 _mm_andnot_ps(LocalM128, LocalM128);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, int);
    LocalM128 _mm_set_ss(float);
    LocalM128 _mm_set_ps1(float);
    LocalM128 _mm_setr_ps(float, float, float, float);
    LocalM128 _mm_setzero_ps(void);
    void _mm_store_ss(float*, LocalM128);
}

// Storage-free method helpers below supply declarations absent from the shared curve header;
// all curve storage and construction use include/hkpLinearParametricCurve.h.
struct CurveEndParameter : public hkpLinearParametricCurve
{
    double hkpLinearParametricCurve_getEnd() const;
};

// @fnv 0x00e47c20
// src: HAVOK_LIB 0x00e47c20
double CurveEndParameter::hkpLinearParametricCurve_getEnd() const
{
    return static_cast<double>(m_kPoints.m_iElementCount - 1);
}

struct CurvePointTransformer : public hkpLinearParametricCurve
{
    void hkpLinearParametricCurve_transformPoints(void const*);
};

// Transforms every curve point in place with the supplied hkTransform.
// @fnv 0x00e47e50
// src: HAVOK_LIB 0x00e47e50
void CurvePointTransformer::hkpLinearParametricCurve_transformPoints(void const* data)
{
    int pointCount = m_kPoints.m_iElementCount;
    for (int i = 0; i < pointCount; ++i)
        m_kPoints.m_data[i].setTransformedPos_00c7f640(*static_cast<const hkTransform*>(data), m_kPoints.m_data[i]);
}

struct CurveSmoothingSetter : public hkpLinearParametricCurve
{
    void hkpLinearParametricCurve_setSmoothingFactor(float input);
};
// @fnv 0x00e47430
// src: XBOX_PDB 0x00e47430
void CurveSmoothingSetter::hkpLinearParametricCurve_setSmoothingFactor(float input)
{
    m_fSmoothingValue = input;
}

struct CurveLoopGetter : public hkpLinearParametricCurve
{
    unsigned char* hkpLinearParametricCurve_isClosedLoop(unsigned char* output);
};
// @fnv 0x00e47400
// src: HAVOK_SRC 0x00e47400
unsigned char* CurveLoopGetter::hkpLinearParametricCurve_isClosedLoop(unsigned char* output)
{
    *output = m_bClosedLoop.m_cBooleanValue;
    return output;
}

// Returns the constant float value 0.0f.
// @fnv 0x00e47410
float __cdecl GetZeroFloat()
{
    return 0.0f;
}

class CurveSmoothingGetter : public hkpLinearParametricCurve
{
  public:
    float hkpLinearParametricCurve_getSmoothingFactor() const;
};

// @fnv 0x00e47420
// src: XBOX_PDB 0x00e47420
float CurveSmoothingGetter::hkpLinearParametricCurve_getSmoothingFactor() const
{
    return m_fSmoothingValue;
}


extern const LocalM128 DAT_010ec7f0;

int __cdecl hkMath_hkFloatToInt(float f);

// hkSimdReal is the shared hkSimdReal representation (hkSimdRealParameter).
__forceinline hkSimdReal::hkSimdReal(float f)
{
    m_vValue = _mm_load_ps1(&f);
}

__forceinline void hkVector4::setInterpolate4(const hkVector4& a, const hkVector4& b,
                                            const hkSimdReal& t)
{
    const LocalM128 kOneMinusT = _mm_sub_ps(DAT_010ec7f0, t.m_vValue);
    m_vComponents = _mm_add_ps(_mm_mul_ps(kOneMinusT, a.m_vComponents), _mm_mul_ps(b.m_vComponents, t.m_vValue));
}

// The shared curve does not yet declare its point sampler; this helper adds no storage.
class CurvePointSampler : public hkpLinearParametricCurve
{
  public:
    void hkpLinearParametricCurve_getPoint(float t, hkVector4& kPointOut) const;
};

// Selects a point from m_kPoints using t, interpolates with the next point when available, and writes the result to kPointOut.
// @fnv 0x00e47440
// src: HAVOK_SRC 0x00e47440
void CurvePointSampler::hkpLinearParametricCurve_getPoint(float afParam, hkVector4& kPointOut) const
{
    const int i = (afParam < 0.0f) ? 0 : hkMath_hkFloatToInt(afParam);
    const float fFrac = afParam - i;
    const int iNextIndex = i + 1;
    if (iNextIndex < m_kPoints.GetLogicalSize())
    {
        kPointOut.setInterpolate4(m_kPoints[i], m_kPoints[iNextIndex], fFrac);
    }
    else
    {
        kPointOut = m_kPoints[i];
    }
}

namespace fnv_00e474e0 {
extern int __cdecl hkMath_hkFloatToInt(float f);

extern const LocalM128 DAT_010ec7f0;

static __forceinline float curveDot3(const hkVector4& a, const hkVector4& b)
{
    LocalM128 x2 = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    LocalM128 y = _mm_shuffle_ps(x2, x2, 0x55);
    LocalM128 xy = _mm_add_ss(y, x2);
    LocalM128 z = _mm_shuffle_ps(x2, x2, 0xaa);
    LocalM128 r = _mm_add_ss(z, xy);
    float f;
    _mm_store_ss(&f, r);
    return f;
}

static __forceinline void curveNormalize3(hkVector4& v)
{
    LocalM128 x2 = _mm_mul_ps(v.m_vComponents, v.m_vComponents);
    LocalM128 y = _mm_shuffle_ps(x2, x2, 0x55);
    LocalM128 xy = _mm_add_ss(y, x2);
    LocalM128 z = _mm_shuffle_ps(x2, x2, 0xaa);
    LocalM128 len = _mm_add_ss(z, xy);
    LocalM128 e = _mm_rsqrt_ss(len);
    LocalM128 he = _mm_mul_ss(_mm_set_ss(0.5f), e);
    LocalM128 ree = _mm_mul_ss(_mm_mul_ss(len, e), e);
    LocalM128 r = _mm_andnot_ps(_mm_cmpeq_ss(len, _mm_set_ss(0.0f)),
                            _mm_mul_ss(he, _mm_sub_ss(_mm_set_ss(3.0f), ree)));
    v.m_vComponents = _mm_mul_ps(_mm_shuffle_ps(r, r, 0), v.m_vComponents);
}

// Override the shared virtual declaration without repeating the curve's layout.
struct CurveNearestPoint : public hkpLinearParametricCurve
{
    virtual float FindNearestPoint(float t, const VectorQ& nearPoint, VectorQ& pointOnCurve);
};

// Clamps t, walks the point array to find the segment nearest to nearPoint, interpolates pointOnCurve, and adjusts for closed loops.
// @fnv 0x00e474e0
float CurveNearestPoint::FindNearestPoint(float t, const VectorQ& nearPointValue, VectorQ& pointOnCurveValue)
{
    const hkVector4& nearPoint = reinterpret_cast<const hkVector4&>(nearPointValue);
    hkVector4& pointOnCurve = reinterpret_cast<hkVector4&>(pointOnCurveValue);
    if (t < 0.0f)
    {
        t = 0.0f;
    }
    int ia = hkMath_hkFloatToInt(t);
    int ib = ia + 1;
    if (ib >= m_kPoints.GetLogicalSize())
    {
        ib = m_kPoints.GetLogicalSize() - 1;
        ia = ib - 1;
    }

    float fraction = 0.0f;
    while (1)
    {
        hkVector4 dir;
        dir.setSub4(m_kPoints[ib], m_kPoints[ia]);
        hkVector4 a;
        a.setSub4(nearPoint, m_kPoints[ia]);
        fraction = curveDot3(a, dir) / curveDot3(dir, dir);
        if (fraction < 0.0f)
        {
            if (ia == 0)
            {
                break;
            }
            ia--;
            ib--;
            continue;
        }
        hkVector4 b;
        b.setSub4(nearPoint, m_kPoints[ib]);
        int ic = ib + 1;
        if (!(curveDot3(b, dir) <= 0.0f) && ic < m_kPoints.GetLogicalSize())
        {
            hkVector4 dir1;
            dir1.setSub4(m_kPoints[ic], m_kPoints[ib]);
            if (curveDot3(dir1, b) > 0.0f)
            {
                ia++;
                ib++;
                continue;
            }
            curveNormalize3(dir);
            curveNormalize3(dir1);
            float fDot0 = curveDot3(dir, b);
            float fDot1 = curveDot3(dir1, b);
            if (-fDot1 > fDot0)
            {
                fraction = 0.99f;
            }
            else
            {
                fraction = 0.01f;
                ia++;
                ib++;
            }
        }
        break;
    }

    pointOnCurve.setInterpolate4(m_kPoints[ia], m_kPoints[ib], fraction);
    float result = (float)ia + fraction;
    if (m_bClosedLoop)
    {
        float end = (float)(m_kPoints.GetLogicalSize() - 1);
        if (result < 0.25f)
        {
            result = FindNearestPoint(end - (1.0f - result), nearPointValue, pointOnCurveValue);
        }
        else if (result > end - 0.25)
        {
            result = FindNearestPoint(1.0f - (end - result), nearPointValue, pointOnCurveValue);
        }
    }
    return result;
}
}  // namespace fnv_00e474e0

namespace fnv_00e478d0 {


extern LocalM128 DAT_010ec7f0;

int __cdecl hkMath_hkFloatToInt(hkReal r);

static __forceinline void hkSetSub4(hkVector4& out, const hkVector4& a, const hkVector4& b)
{
    out.m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
}

static __forceinline void hkNormalize3(hkVector4& v)
{
    LocalM128 p = _mm_mul_ps(v.m_vComponents, v.m_vComponents);
    LocalM128 len2 = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
    len2 = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), len2);
    LocalM128 e = _mm_rsqrt_ss(len2);
    LocalM128 r =
        _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), e), _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(len2, e), e)));
    r = _mm_andnot_ps(_mm_cmpeq_ss(len2, _mm_set_ss(0.0f)), r);
    v.m_vComponents = _mm_mul_ps(_mm_shuffle_ps(r, r, 0), v.m_vComponents);
}

static __forceinline void hkSetInterpolate4(hkVector4& out, const hkVector4& v0, const hkVector4& v1, hkReal t)
{
    LocalM128 tt = _mm_set_ps1(t);
    LocalM128 s = _mm_sub_ps(DAT_010ec7f0, tt);
    out.m_vComponents = _mm_add_ps(_mm_mul_ps(v1.m_vComponents, tt), _mm_mul_ps(s, v0.m_vComponents));
}

struct LinearCurveT : public hkpLinearParametricCurve
{
    __forceinline const hkVector4& P(int i) const
    {
        return m_kPoints.m_data[i];
    }
    void GetTangent(hkReal t, hkVector4& tangentOut) const;
};

// Computes the smoothed tangent at parameter t by interpolating between adjacent segment directions and writing the result to tangentOut.
// @fnv 0x00e478d0
void LinearCurveT::GetTangent(hkReal t, hkVector4& tangentOut) const
{
    hkReal smooth = m_fSmoothingValue;
    hkReal invSmooth = 1.0f / smooth;

    int ia = hkMath_hkFloatToInt(t);
    int ib = ia + 1;
    if (ib >= m_kPoints.m_iElementCount)
    {
        ib = m_kPoints.m_iElementCount - 1;
        ia = ib - 1;
    }
    else if (ia < 0)
    {
        ia = 0;
        ib = 1;
    }

    hkVector4& tangent = tangentOut;

    hkReal dist = t - ia;
    hkSetSub4(tangent, P(ib), P(ia));
    hkNormalize3(tangent);

    if (dist < smooth && ia > 0)
    {
        ia--;
        ib--;
        hkVector4 prev;
        hkSetSub4(prev, P(ib), P(ia));
        hkNormalize3(prev);
        hkReal f = (smooth - dist) * 0.5 * invSmooth;
        hkSetInterpolate4(tangent, tangent, prev, f);
        hkNormalize3(tangent);
    }

    dist = ib - t;
    if (dist < smooth && ib < m_kPoints.m_iElementCount - 1)
    {
        hkVector4 next;
        hkSetSub4(next, P(ib + 1), P(ia + 1));
        hkNormalize3(next);
        hkReal f = (smooth - dist) * 0.5 * invSmooth;
        hkSetInterpolate4(tangent, tangent, next, f);
        hkNormalize3(tangent);
    }
}
}  // namespace fnv_00e478d0

int __cdecl hkMath_hkFloatToInt(float f);

class CurveDistanceInterpolator : public hkpLinearParametricCurve
{
  public:
    float GetInterpolatedValue(float t) const;
};

// Linearly interpolates, or extrapolates past the ends, between entries of m_fClosestPointDistanceSquared.m_data at t using the index from FUN_00cbfef0.
// @fnv 0x00e47c30
float CurveDistanceInterpolator::GetInterpolatedValue(float t) const
{
    int i = hkMath_hkFloatToInt(t);
    float fInterval;
    if (i >= m_kPoints.m_iElementCount - 1)
    {
        i = m_kPoints.m_iElementCount - 1;
        fInterval = m_fClosestPointDistanceSquared.m_data[i] - m_fClosestPointDistanceSquared.m_data[i - 1];
    }
    else
    {
        if (i < 0)
            i = 0;
        fInterval = m_fClosestPointDistanceSquared.m_data[i + 1] - m_fClosestPointDistanceSquared.m_data[i];
    }
    return (t - i) * fInterval + m_fClosestPointDistanceSquared.m_data[i];
}

struct Allocator
{
    virtual void dummy0();
    virtual void* allocateChunk(int size);
    virtual void dummy2();
    virtual void* allocate(int* reqSize);
    virtual void deallocate(void* ptr, int size);
};

struct ThreadMemory
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Allocator* m_pMemoryAllocator;
};

void* hkMemoryRouter_getInstance();

struct CurveHelper : public hkpLinearParametricCurve
{
    void CopyPoints(hkArray<hkVector4>& out) const;
};

// Copies m_kPoints into out, growing out's buffer via the thread memory manager if its capacity is too small.
// @fnv 0x00e47fa0
void CurveHelper::CopyPoints(hkArray<hkVector4>& out) const
{
    Allocator* mgr = ((ThreadMemory*)hkMemoryRouter_getInstance())->m_pMemoryAllocator;
    int cap = out.m_iCapacityState & 0x3fffffff;
    if (cap < this->m_kPoints.m_iElementCount)
    {
        if ((out.m_iCapacityState & 0x80000000) == 0)
        {
            mgr->deallocate(out.m_data, cap * sizeof(hkVector4));
        }
        int reqBytes = this->m_kPoints.m_iElementCount * sizeof(hkVector4);
        out.m_data = (hkVector4*)mgr->allocate(&reqBytes);
        out.m_iCapacityState = reqBytes / 16;
    }
    int count = this->m_kPoints.m_iElementCount;
    out.m_iElementCount = count;
    LocalM128* dst = (LocalM128*)out.m_data;
    const LocalM128* src = (const LocalM128*)this->m_kPoints.m_data;
    for (int i = 0; i < count; ++i)
    {
        dst[i] = src[i];
    }
}




inline void hkVector4::set(float a, float b, float c, float d)
{
    m_vComponents = _mm_setr_ps(a, b, c, d);
}

static const float curveZero = 0.0f;
static const float DAT_01012068 = 1.0f;

// @fnv 0x00e48030
hkpLinearParametricCurve::hkpLinearParametricCurve() throw() : m_fSmoothingValue(0.01f), m_bClosedLoop(false)
{
    m_kVector4.set(curveZero, DAT_01012068, curveZero, curveZero);
}



struct CurveThreadMemory
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Allocator* m_pThreadAllocator;
};
inline hkSimdReal::hkSimdReal(const LocalM128& v) : m_vValue(v) {}

inline hkSimdReal::operator float() const
{
    float component;
    _mm_store_ss(&component, m_vValue);
    return component;
}

static __forceinline hkSimdReal curveLane(const hkVector4& vector, int i)
{
    switch (i)
    {
    case 0:
        return vector.m_vComponents;
    case 1:
        return _mm_shuffle_ps(vector.m_vComponents, vector.m_vComponents, 85);
    case 2:
        return _mm_shuffle_ps(vector.m_vComponents, vector.m_vComponents, 170);
    default:
        return _mm_shuffle_ps(vector.m_vComponents, vector.m_vComponents, 255);
    }
}

// The shared curve does not yet declare clone/add-point; no layout is repeated.
struct LinearCurveClone : public hkpLinearParametricCurve
{
    LinearCurveClone* hkpLinearParametricCurve_clone();
    void FUN_00e47e80(const hkVector4*);
};
static __forceinline LinearCurveClone* createCurve()
{
    CurveThreadMemory* memory = (CurveThreadMemory*)hkMemoryRouter_getInstance();
    void* chunk = memory->m_pThreadAllocator->allocateChunk(0x40);
    ((hkReferencedObject*)chunk)->m_usMemSizeAndFlags = 0x40;
    return static_cast<LinearCurveClone*>(::new (chunk) hkpLinearParametricCurve);
}
template <class T> static __forceinline void arrCopy_e48090(T* dst, int start, const T* src, int n)
{
    for (; start < n; ++start)
    {
        dst[start] = src[start];
    }
}
template <class T>
static __forceinline void copyFromArray_e48090(hkArray<T>& self, Allocator* alloc, const hkArray<T>& a)
{
    if ((self.m_iCapacityState & 0x3fffffff) < a.m_iElementCount)
    {
        if ((self.m_iCapacityState & 0x80000000) == 0)
        {
            alloc->deallocate(self.m_data, (self.m_iCapacityState & 0x3fffffff) * int(sizeof(T)));
        }
        int numBytes = a.m_iElementCount * int(sizeof(T));
        self.m_data = (T*)alloc->allocate(&numBytes);
        self.m_iCapacityState = numBytes / int(sizeof(T));
    }
    self.m_iElementCount = a.m_iElementCount;
    arrCopy_e48090(self.m_data, 0, a.m_data, self.m_iElementCount);
}
// @fnv 0x00e48090
// src: HAVOK_SRC 0x00e48090
LinearCurveClone* LinearCurveClone::hkpLinearParametricCurve_clone()
{
    LinearCurveClone* clone = createCurve();
    int numPoints = this->m_kPoints.m_iElementCount;
    if (0 < numPoints)
    {
        for (int i = 0; i < numPoints; ++i)
        {
            clone->FUN_00e47e80(&this->m_kPoints.m_data[i]);
        }
    }
    clone->m_bClosedLoop = this->m_bClosedLoop;
    clone->m_kVector4.set(curveLane(m_kVector4, 0),
                         curveLane(m_kVector4, 1),
                         curveLane(m_kVector4, 2), 0.0f);
    copyFromArray_e48090(clone->m_fClosestPointDistanceSquared,
                         ((CurveThreadMemory*)hkMemoryRouter_getInstance())->m_pThreadAllocator,
                         this->m_fClosestPointDistanceSquared);
    clone->m_fSmoothingValue = this->m_fSmoothingValue;
    return clone;
}

#include <math.h>


__forceinline hkReal& hkVector4::operator()(int i)
{
    return reinterpret_cast<hkReal*>(&m_vComponents)[i];
}

inline const hkReal& hkVector4::operator()(int i) const
{
    return reinterpret_cast<const hkReal*>(&m_vComponents)[i];
}

extern hkVector4 DAT_01268380;

static __forceinline hkReal hkFabs(hkReal r)
{
    return (hkReal)fabs(r);
}

static __forceinline hkReal hkDot3(const hkVector4& a, const hkVector4& b)
{
    LocalM128 x2 = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    LocalM128 xy = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    LocalM128 xyz = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xy);
    hkReal r;
    _mm_store_ss(&r, xyz);
    return r;
}

static __forceinline void hkNormalize3(hkVector4& v)
{
    LocalM128 p = _mm_mul_ps(v.m_vComponents, v.m_vComponents);
    LocalM128 len2 = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
    len2 = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), len2);
    LocalM128 e = _mm_rsqrt_ss(len2);
    LocalM128 r =
        _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), e), _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(len2, e), e)));
    r = _mm_andnot_ps(_mm_cmpeq_ss(len2, _mm_set_ss(0.0f)), r);
    v.m_vComponents = _mm_mul_ps(_mm_shuffle_ps(r, r, 0), v.m_vComponents);
}

static __forceinline void hkCalculatePerpendicularVector(const hkVector4& in, hkVector4& out)
{
    int min = 0;
    int ok1 = 1;
    int ok2 = 2;

    hkReal a0 = hkFabs(in(0));
    hkReal a1 = hkFabs(in(1));
    hkReal a2 = hkFabs(in(2));

    if (a1 < a0)
    {
        ok1 = 0;
        min = 1;
        a0 = a1;
    }

    if (a2 < a0)
    {
        ok2 = min;
        min = 2;
    }

    out.m_vComponents = _mm_setzero_ps();
    out(ok1) = in(ok2);
    out(ok2) = -in(ok1);
}

static __forceinline void hkSetCross(hkVector4& out, const hkVector4& v0, const hkVector4& v1)
{
    LocalM128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xc9),
                               _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2));
    LocalM128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xd2),
                               _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9));
    out.m_vComponents = _mm_sub_ps(cross0, cross1);
}

struct LinearCurve : public hkpLinearParametricCurve
{
    void hkpLinearParametricCurve_getBinormal(hkReal t, hkVector4& up) const;
};

// Computes a normalized up vector for the curve at t by crossing or perpendicularizing the tangent against m_kVector4.
// @fnv 0x00e47cb0
// src: HAVOK_SRC 0x00e47cb0
void LinearCurve::hkpLinearParametricCurve_getBinormal(hkReal t, hkVector4& up) const
{
    hkVector4 tangent;
    const_cast<LinearCurve*>(this)->GetTangentAt(t, reinterpret_cast<VectorQ&>(tangent));

    hkVector4& out = up;
    if (hkDot3(DAT_01268380, tangent) < (double)0.98f)
    {
        hkSetCross(out, tangent, m_kVector4);
    }
    else
    {
        hkCalculatePerpendicularVector(tangent, out);
    }
    hkNormalize3(out);
}
