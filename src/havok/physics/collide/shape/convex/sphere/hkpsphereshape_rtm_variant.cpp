typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
#define _INCLUDED_MM2

// src/havok/physics/collide/shape/convex/sphere/hkpsphereshape_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/shape/convex/sphere/hkpsphereshape.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/collide/shape/convex/sphere/hkpsphereshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/convex/sphere/hkpsphereshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpSphereShape.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMonitorStream.h"
extern char const* const g_01268970_arg1;
void __cdecl hkReferencedObject_calcContentStatistics(char const* const*, char const* const*);
void __cdecl hkpSphereShape_calcContentStatistics(char const* const* a1, char const* const* a2);
extern int DAT_010cb5ac;
struct FUN_00cd8160
{
    FUN_00cd8160(float radius);
};
int __cdecl hkpSphereShape_ReturnOne();
int __stdcall hkpSphereShape_ReturnConstant_0x20(int a1, int a2);
// Exe 0x00cd85c0 FUN_00cd85c0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).

extern "C" LocalM128 _mm_load_ps1(const float*);
extern "C" LocalM128 _mm_sub_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_add_ps(LocalM128, LocalM128);
struct Shape_00cd8100
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    float m_fSphereRadius;
};
struct Vec_00cd8100
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    LocalM128 m_pos;
};
struct Aabb_00cd8100
{
    LocalM128 m_kMinimumCorner;
    LocalM128 m_kMaximumCorner;
};
struct Shape_00cd8100_cls
{
    void GetAabb(const Vec_00cd8100* t, float tol, Aabb_00cd8100* out);
    Shape_00cd8100 self;
};
extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern unsigned long DAT_0126835c;
extern const char DAT_010cb5f4[];
extern const char DAT_010c41f8[];
void* __cdecl Object_ProcessAndReturnValue_00cd85c0(void* pvResult, float fValue, int a, int b);
class HostCD81
{
  public:
    int unk00, unk04, unk08, unk0C;
    float m_fValue;
    void* RecordTimerCommands(void* pvResult, int a, int b);
};
extern "C" LocalM128 _mm_set_ps(float, float, float, float);
extern "C" LocalM128 _mm_setr_ps(float, float, float, float);
extern "C" LocalM128 _mm_set_ps1(float);
extern "C" LocalM128 _mm_load_ps(const float*);
extern "C" void _mm_store_ps(float*, LocalM128);
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_cmplt_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_cmple_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_setzero_ps(void);
extern "C" LocalM128 _mm_and_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_andnot_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_or_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_xor_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_rcp_ps(LocalM128);
extern "C" LocalM128 _mm_rsqrt_ps(LocalM128);
extern "C" LocalM128 _mm_load_ss(const float*);
extern "C" LocalM128 _mm_unpacklo_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, int);
extern "C" int _mm_movemask_ps(LocalM128);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_0126835c;
extern "C" unsigned __int64 __rdtsc();
extern "C" void _ReadWriteBarrier();
class RayMask
{
    LocalM128 bits;
    friend class RayVector;

  public:
    enum Component
    {
        X = 1,
        Y = 2,
        Z = 4,
        W = 8
    };
    static const Component components[4];
    __forceinline void intersect(const RayMask& a, const RayMask& b)
    {
        bits = _mm_and_ps(a.bits, b.bits);
    }
    __forceinline int any(Component lane) const
    {
        return _mm_movemask_ps(bits) & lane;
    }
};
const RayMask::Component RayMask::components[4] = {RayMask::X, RayMask::Y, RayMask::Z, RayMask::W};
static const LocalM128 signVector = {{-0.0f, -0.0f, -0.0f, -0.0f}};
static const LocalM128 tripleVector = {{3.0f, 3.0f, 3.0f, 3.0f}};
static const LocalM128 halfVector = {{0.5f, 0.5f, 0.5f, 0.5f}};
extern LocalM128 kOne;
static __forceinline LocalM128 reciprocalVector(LocalM128 value)
{
    LocalM128 estimate = _mm_rcp_ps(value);
    return _mm_sub_ps(_mm_add_ps(estimate, estimate), _mm_mul_ps(_mm_mul_ps(estimate, value), estimate));
}
class RayVector
{
    LocalM128 value;

  public:
    __forceinline RayVector()
    {}
    __forceinline RayVector(const RayVector& other)
    {
        value = other.value;
    }
    __forceinline RayVector(const LocalM128& other)
    {
        value = other;
    }
    __forceinline void operator=(const RayVector& other)
    {
        value = other.value;
    }
    __forceinline LocalM128& quad()
    {
        return value;
    }
    __forceinline const LocalM128& quad() const
    {
        return value;
    }
    __forceinline operator LocalM128() const
    {
        return value;
    }
    __forceinline float& operator()(int lane)
    {
        return ((float*)&value)[lane];
    }
    __forceinline void splat(float number)
    {
        value = _mm_set_ps1(number);
    }
    __forceinline void zero()
    {
        value = _mm_setzero_ps();
    }
    __forceinline void set(float x, float y, float z, float w)
    {
        value = _mm_setr_ps(x, y, z, w);
    }
    __forceinline void product(const RayVector& a, const RayVector& b)
    {
        value = _mm_mul_ps(a.value, b.value);
    }
    __forceinline void accumulate(const RayVector& a, const RayVector& b)
    {
        value = _mm_add_ps(value, _mm_mul_ps(a.value, b.value));
    }
    __forceinline void difference(const RayVector& a, const RayVector& b)
    {
        value = _mm_sub_ps(a.value, b.value);
    }
    __forceinline void multiply(const RayVector& rhs)
    {
        value = _mm_mul_ps(value, rhs.value);
    }
    __forceinline void add(const RayVector& rhs)
    {
        value = _mm_add_ps(value, rhs.value);
    }
    __forceinline void subtract(const RayVector& rhs)
    {
        value = _mm_sub_ps(value, rhs.value);
    }
    __forceinline void negate(const RayVector& rhs)
    {
        value = _mm_xor_ps(rhs.value, signVector);
    }
    __forceinline void reciprocal(const RayVector& rhs)
    {
        value = reciprocalVector(rhs.value);
    }
    __forceinline void choose(const RayVector& a, const RayVector& b, const RayMask& mask)
    {
        value = _mm_or_ps(_mm_and_ps(mask.bits, b.value), _mm_andnot_ps(mask.bits, a.value));
    }
    __forceinline RayMask greater(const RayVector& rhs) const
    {
        RayMask result;
        result.bits = _mm_cmplt_ps(rhs.value, value);
        return result;
    }
    __forceinline RayMask less(const RayVector& rhs) const
    {
        RayMask result;
        result.bits = _mm_cmplt_ps(value, rhs.value);
        return result;
    }
    __forceinline RayMask atLeast(const RayVector& rhs) const
    {
        RayMask result;
        result.bits = _mm_cmple_ps(rhs.value, value);
        return result;
    }
};
struct RayQuerySet
{
    RayVector m_vFrom[3], m_vTo[3];
    unsigned filter;
    const void* collectionFilter;
};
struct RayHitBase
{
    RayVector m_vHitNormal;
    float m_fHitFraction;
    int unk14, unk18, unk1c;
};
struct RayHit : RayHitBase
{
    unsigned m_uiShapeKeys[8];

  private:
    int m_uiShapeKeyIndex;

  public:
    __forceinline void setKey(unsigned key)
    {
        m_uiShapeKeys[m_uiShapeKeyIndex] = key;
    }
};
struct RayHits
{
    RayHit m_akRayOutputs[4];
};
static __forceinline void transposeVectors(LocalM128& r0, LocalM128& r1, LocalM128& r2, LocalM128& r3)
{
    LocalM128 t0 = _mm_shuffle_ps(r0, r1, 0x44);
    LocalM128 t2 = _mm_shuffle_ps(r0, r1, 0xee);
    LocalM128 t1 = _mm_shuffle_ps(r2, r3, 0x44);
    LocalM128 t3 = _mm_shuffle_ps(r2, r3, 0xee);
    r0 = _mm_shuffle_ps(t0, t1, 0x88);
    r1 = _mm_shuffle_ps(t0, t1, 0xdd);
    r2 = _mm_shuffle_ps(t2, t3, 0x88);
    r3 = _mm_shuffle_ps(t2, t3, 0xdd);
}
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_0126835c;
extern "C" unsigned __int64 __rdtsc();
extern "C" void _ReadWriteBarrier();
struct ProbeSphere : hkpSphereShape
{
    RayMask hkpSphereShape_castRayBundleImpl(const RayQuerySet&, RayHits&, const RayMask&) const;
};
extern "C" LocalM128 _mm_setzero_ps(void);
extern "C" void _mm_store_ps(float*, LocalM128);
void __stdcall hkpSphereShape_getSupportingVertexImpl(int direction, float* vertexOut);
extern "C" void __movsd(unsigned long*, const unsigned long*, unsigned long);
void __stdcall hkpSphereShape_convertVertexIdsToVerticesImpl(int a0, __int64 packed);
extern "C" LocalM128 _mm_setzero_ps(void);
struct __declspec(align(16)) CentreVectorCD80
{
    LocalM128 m_vComponents;

    void zero()
    {
        m_vComponents = _mm_setzero_ps();
    }
};
CentreVectorCD80 __stdcall hkpSphereShape_getCentreImpl();
struct FUN_00cd8140_Result
{
    int unk00;
    int unk04;
    int unk08;
    float unk0C;
};
struct FUN_00cd8140_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float unk10;

    void hkpSphereShape_getCollisionSpheresImpl(FUN_00cd8140_Result* result);
};
void __stdcall hkpSphereShape_getFirstVertex(float* output);

extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_add_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, int);
extern "C" void _mm_store_ss(float*, LocalM128);
extern "C" LocalM128 _mm_load_ps(const float*);
extern "C" LocalM128 _mm_load_ss(const float*);
#include <math.h>

struct FnvBool
{
    FnvBool(bool v)
    {
        m = (char)v;
    }
    char m;
};

struct RayIn
{
    LocalM128 m_vFrom;
    LocalM128 m_vTo;
};

extern const LocalM128 DAT_010ec7f0;

static __forceinline float dot3(LocalM128 a, LocalM128 b)
{
    LocalM128 p = _mm_mul_ps(a, b);
    LocalM128 s = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
    s = _mm_add_ss(_mm_shuffle_ps(p, p, 0xAA), s);
    float r;
    _mm_store_ss(&r, s);
    return r;
}

static __forceinline LocalM128 lerp(LocalM128 a, LocalM128 b, const float& t)
{
    LocalM128 scalar = _mm_load_ss(&t);
    LocalM128 ts = _mm_shuffle_ps(scalar, scalar, 0);
    LocalM128 one = DAT_010ec7f0;
    return _mm_add_ps(_mm_mul_ps(a, _mm_sub_ps(one, ts)), _mm_mul_ps(b, ts));
}

// @fnv 0x00cd85c0
// src: GUESS 0x00cd85c0 (confidence: low)
FnvBool __cdecl Object_ProcessAndReturnValue_00cd85c0(float radius, const RayIn& input, RayHit& results)
{
    float extra, p2, gap, disc, negative, root, nearDist;
    LocalM128 point;
    float radiusSq = radius * radius;
    LocalM128 dir = _mm_sub_ps(input.m_vTo, input.m_vFrom);
    float b = dot3(input.m_vFrom, dir);
    if (b >= 0.0f)
        goto miss;

    const float& a = dot3(dir, dir);
    if (b * b > (float)(radiusSq * a * 100.0))
    {
        if (!(a < radiusSq))
        {
            extra = -b;
            float closestFraction = extra / a;
            point = lerp(input.m_vFrom, input.m_vTo, closestFraction);
            b = 0.0f;
        }
        else
            goto miss;
    }
    else
    {
        point = input.m_vFrom;
        extra = 0.0f;
    }

    p2 = dot3(point, point);
    gap = p2 - radiusSq;
    disc = b * b - a * gap;
    if (disc <= 0.0f)
        goto miss;

    negative = -b;
    root = sqrtf(disc);
    nearDist = negative - root;
    extra = nearDist + extra;

    if (extra >= (float)(a * results.m_fHitFraction))
        goto miss;
    if (extra < 0.0f)
    {
    miss:
        return false;
    }
    {
        extra = extra / a;
        results.m_fHitFraction = extra;
        LocalM128 hit = lerp(input.m_vFrom, input.m_vTo, extra);
        float invRadius = 1.0f / radius;
        results.m_vHitNormal = RayVector(hit);
        LocalM128 invScalar = _mm_load_ss(&invRadius);
        results.m_vHitNormal = RayVector(_mm_mul_ps(_mm_shuffle_ps(invScalar, invScalar, 0), hit));
        results.setKey(0xffffffff);
        return true;
    }
}
