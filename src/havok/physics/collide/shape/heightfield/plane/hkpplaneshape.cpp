
// src/havok/physics/collide/shape/heightfield/plane/hkpplaneshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/heightfield/plane/hkpplaneshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Keep the non-byte intrinsic lanes used by this unit's original /GS code.
#define _INCLUDED_MM2
// Exe 0x00d552f0 FUN_00d552f0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    __int32 m128_i32[4];
    __int64 m128_i64[2];
    unsigned __int32 m128_u32[4];
} __m128, LocalM128;
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_add_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_sub_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
extern "C" LocalM128 _mm_add_ss(LocalM128, LocalM128);
extern "C" float _mm_cvtss_f32(LocalM128);

extern "C" LocalM128 _mm_and_ps(LocalM128 _A, LocalM128 _B);
extern "C" LocalM128 _mm_cmple_ps(LocalM128 _A, LocalM128 _B);
extern "C" LocalM128 _mm_set_ps1(float _A);
extern "C" void _mm_store_ss(float* _V, LocalM128 _A);
extern "C" int _mm_movemask_ps(LocalM128 _A);
#define FNV_VEC4_NO_SSE
#define FNV_VEC4_SIMD
#include "../../../../../../../include/Vec4.h"
#include "../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../include/hkpPlaneShape.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMonitorStream.h"

__forceinline void Vec4::operator=(const Vec4& v)
{
    m_vComponents = v.m_vComponents;
}

void __cdecl hkAabbUtil_calcAabb_00d26230(void*, void*, void*, float, int);

struct FUN_00d552c0_StandIn
{
    void hkpPlaneShape_getAabbImpl(void*, float, int);
};

// Forwards param1, the objects at offsets 0x30 and 0x20 of this, param2 and param3 to FUN_00d26230.
// @fnv 0x00d552c0
// src: HAVOK_LIB 0x00d552c0
void FUN_00d552c0_StandIn::hkpPlaneShape_getAabbImpl(void* param1, float param2, int param3)
{
    hkAabbUtil_calcAabb_00d26230(param1, (void*)((char*)this + 0x30), (void*)((char*)this + 0x20), param2, param3);
}

extern const hkClass g_01269b84;

class hkObjectD54F : public hkReferencedObject
{
  public:
    void hkpPlaneShape_calcContentStatistics(hkStatisticsCollector* pkCollector, const hkClass* pkClass) const;
};

// @fnv 0x00d54f80
// src: XBOX_PDB 0x00d54f80
void hkObjectD54F::hkpPlaneShape_calcContentStatistics(hkStatisticsCollector* pkCollector, const hkClass* pkClass) const
{
    hkReferencedObject::calcContentStatistics(pkCollector, &g_01269b84);
}

struct __declspec(align(16)) Vector4D54F90
{
    float x;
    float y;
    float z;
    float w;
};
struct RayCastOutputD54F90
{
    RayCastOutputD54F90() : m_iExtraInfo(-1), m_uiShapeKeyIndex(0)
    {
        m_uiShapeKeys[0] = -1;
    }
    Vector4D54F90 m_vHitNormal;
    float m_fHitFraction;
    int m_iExtraInfo;
    int m_pad18;
    int m_pad1C;
    int m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;
};
struct BoolD54F90
{
    char m_cBooleanValue;
};
struct RayCastInputD54F90;
struct CdBodyD54F90
{
    int unk00;
    int unk04;
    const void* m_pMotionState;
};
struct CollectorD54F90
{
    virtual void CollectRayHit(const CdBodyD54F90& kBody, const RayCastOutputD54F90& kOutput);
    float m_fEarlyOutHitFraction;
};
void __stdcall hkVector4_setMul3(const void* pkTransform, Vector4D54F90& kNormal);
struct ShapeD54F90
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual BoolD54F90 RayCast(const RayCastInputD54F90& kInput, RayCastOutputD54F90& kOutput) const;
    void hkpPlaneShape_castRayWithCollectorImpl(const RayCastInputD54F90& kInput, const CdBodyD54F90& kBody, CollectorD54F90& kCollector) const;
};

// Performs a ray cast against the shape, and if a hit is found, transforms the hit normal and forwards the result to the collector.
// @fnv 0x00d54f90
// src: HAVOK_LIB 0x00d54f90
void ShapeD54F90::hkpPlaneShape_castRayWithCollectorImpl(const RayCastInputD54F90& kInput, const CdBodyD54F90& kBody,
                               CollectorD54F90& kCollector) const
{
    RayCastOutputD54F90 kOutput;
    kOutput.m_fHitFraction = kCollector.m_fEarlyOutHitFraction;
    BoolD54F90 kHit = RayCast(kInput, kOutput);
    if (kHit.m_cBooleanValue)
    {
        hkVector4_setMul3(kBody.m_pMotionState, kOutput.m_vHitNormal);
        kCollector.CollectRayHit(kBody, kOutput);
    }
}

extern char DAT_010d0e18;
extern LocalM128 DAT_010c71d0;

struct PlaneShape_00d551d0 : hkpPlaneShape
{
    PlaneShape_00d551d0* hkpPlaneShape_hkpPlaneShape(const hkVector4& p, const hkVector4* box);
};

// Sets type 0x1c, stores p in m_kTriangleNormal, and sets the AABB center and half-extents from the two corner vectors in box.
// @fnv 0x00d551d0
// src: XBOX_PDB 0x00d551d0
PlaneShape_00d551d0* PlaneShape_00d551d0::hkpPlaneShape_hkpPlaneShape(const hkVector4& p, const hkVector4* box)
{
    m_ulUserData = 0;
    *(unsigned int*)&m_type = 0x1c;
    *(void**)this = &DAT_010d0e18;
    m_sReferenceCount = 1;
    *(LocalM128*)&m_kTriangleNormal = *(const LocalM128*)&p;
    *(LocalM128*)&m_kAabbCenter = _mm_mul_ps(_mm_add_ps(*(const LocalM128*)&box[1], *(const LocalM128*)&box[0]), DAT_010c71d0);
    *(LocalM128*)&m_kAabbHalfExtents =
        _mm_mul_ps(_mm_sub_ps(*(const LocalM128*)&box[1], *(const LocalM128*)&box[0]), DAT_010c71d0);
    return this;
}

struct __declspec(align(16)) PlaneVector
{
    LocalM128 value;
    __forceinline float Dot3(const PlaneVector& other) const
    {
        LocalM128 product = _mm_mul_ps(value, other.value);
        LocalM128 y = _mm_shuffle_ps(product, product, 0x55);
        LocalM128 z = _mm_shuffle_ps(product, product, 0xaa);
        LocalM128 sum = _mm_add_ss(y, product);
        LocalM128 total = _mm_add_ss(z, sum);
        return _mm_cvtss_f32(total);
    }
};
struct PlaneReference
{
    unsigned short memoryFlags;
    short referenceCount;
    PlaneReference() : referenceCount(1)
    {}
    virtual ~PlaneReference();
};
struct PlaneShapeBase : PlaneReference
{
    unsigned int userData;
    unsigned int type;
    PlaneShapeBase(unsigned int shapeType) : userData(0), type(shapeType)
    {}
};
struct FUN_00d55240 : PlaneShapeBase
{
    PlaneVector plane, centerVector, extentVector;
    FUN_00d55240(const PlaneVector& normal, const PlaneVector& center, const PlaneVector& extents);
    virtual ~FUN_00d55240();
};
// Initialises a plane shape with the given normal, center and extents, computing the plane offset as the negative dot of normal and center.
// @fnv 0x00d55240
FUN_00d55240::FUN_00d55240(const PlaneVector& normal, const PlaneVector& center, const PlaneVector& extents)
    : PlaneShapeBase(28)
{
    plane.value = normal.value;
    plane.value.m128_f32[3] = -normal.Dot3(center);
    centerVector.value = center.value;
    extentVector.value = extents.value;
}

namespace fnv_00d552f0 {
extern "C" const LocalM128 DAT_010ec7f0;
extern "C" const LocalM128 DAT_01017d10;

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern "C" unsigned long DAT_0126835c;
extern "C" const char DAT_010d1074[];
extern "C" const char DAT_010c41f8[];
extern "C" unsigned __int64 __rdtsc();
extern "C" void _ReadWriteBarrier();

static const char s_kEndTimer[] = "Et";
static __forceinline void TimerMark(const char* name, volatile unsigned int& t)
{
    hkMonitorStream* s = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    if (s->m_end.m_storage < s->m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* h = (hkMonitorStream::TimerCommand*)s->m_end.m_storage;
        h->m_commandAndMonitor = name;
        _ReadWriteBarrier();
        t = (unsigned int)__rdtsc();
        _ReadWriteBarrier();
        h->m_time0 = t;
        s->m_end.m_storage = (char*)(h + 1);
    }
}

struct TimerScopeD55
{
    volatile unsigned int& m_t;
    __forceinline TimerScopeD55(const char* name, volatile unsigned int& t) : m_t(t)
    {
        TimerMark(name, m_t);
    }
    __forceinline ~TimerScopeD55()
    {
        TimerMark("Et", m_t);
    }
};

class HkBoolD55
{
  public:
    char m_cBooleanValue;
    HkBoolD55(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

struct RayInputD55
{
    Vec4 m_vFrom;
    Vec4 m_vTo;
};

struct RayOutputD55
{
    Vec4 m_vHitNormal;
    float m_fromDist;
    int m_iExtraInfo;
    int pad[2];
    unsigned int m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;
    void setKey(unsigned int key)
    {
        m_uiShapeKeys[m_uiShapeKeyIndex] = key;
    }
};

static inline void Dot4xyz1(float* out, const Vec4& p, const Vec4& a)
{
    LocalM128 x2 = _mm_mul_ps(a.m_vComponents, p.m_vComponents);
    LocalM128 w = _mm_shuffle_ps(p.m_vComponents, p.m_vComponents, 0xff);
    LocalM128 z = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), w);
    LocalM128 y = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    _mm_store_ss(out, _mm_add_ps(z, y));
}

class PlaneShapeD55
{
  public:
    int pad[4];
    Vec4 m_kTriangleNormal;
    Vec4 m_kAabbCenter;
    Vec4 m_kAabbHalfExtents;
    HkBoolD55 hkpPlaneShape_castRayImpl(const RayInputD55& input, RayOutputD55& results) const;
};

// @fnv 0x00d552f0
// src: XBOX_PDB 0x00d552f0
HkBoolD55 PlaneShapeD55::hkpPlaneShape_castRayImpl(const RayInputD55& input, RayOutputD55& results) const
{
    union
    {
        volatile unsigned int t;
        float d;
    } u;
    TimerScopeD55 timer("TtrcPlane", u.t);
    float& fromDist = u.d;
    Dot4xyz1(&fromDist, m_kTriangleNormal, input.m_vFrom);
    float toDist;
    Dot4xyz1(&toDist, m_kTriangleNormal, input.m_vTo);
    if (fromDist >= 0.0f && toDist < 0.0f)
    {
        fromDist = fromDist / (fromDist - toDist);
        LocalM128 t = _mm_set_ps1(fromDist);
        LocalM128 s = _mm_sub_ps(DAT_010ec7f0, t);
        LocalM128 hit = _mm_add_ps(_mm_mul_ps(s, input.m_vFrom.m_vComponents), _mm_mul_ps(input.m_vTo.m_vComponents, t));
        LocalM128 diff = _mm_and_ps(_mm_sub_ps(hit, m_kAabbCenter.m_vComponents), DAT_01017d10);
        if ((_mm_movemask_ps(_mm_cmple_ps(diff, m_kAabbHalfExtents.m_vComponents)) & 7) == 7)
        {
            results.m_fromDist = fromDist;
            results.m_vHitNormal = m_kTriangleNormal;
            results.setKey(0xffffffff);
            return true;
        }
    }
    return false;
}
}  // namespace fnv_00d552f0
