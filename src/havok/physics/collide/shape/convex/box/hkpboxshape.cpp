
// src/havok/physics/collide/shape/convex/box/hkpboxshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/convex/box/hkpboxshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Keep this unit's intrinsic declaration: extra union views in the CRT __m128
// change alias analysis and the original scalar/SIMD instruction scheduling.
// Exe 0x00c9dc40 FUN_00c9dc40: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) { float m128_f32[4]; unsigned __int64 m128_u64[2]; } __m128, LocalM128;
#define _INCLUDED_MM2
extern "C" LocalM128 _mm_set_ps1(float);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
#include <string.h>
#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/hkTransform.h"
#include "../../../../../../../include/hkAabb.h"
#include "../../../../../../../include/hkpBoxShape.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/MemoryManager.h"

// @fnv 0x00c9db70
// src: GUESS 0x00c9db70 (confidence: high)
int __cdecl hkpBoxShape_ReturnConstant_8()
{
    return 8;
}

// Returns the smaller of the two float arguments.
// @fnv 0x00c9e0f0
// src: GAMEBRYO_LIB 0x00c9e0f0
float __cdecl NiMin(float a, float b)
{
    return a < b ? a : b;
}

hkMemoryRouter* __cdecl _D1A0E0GetMemoryRouter();


// @fnv 0x00c9db80
__declspec(noinline) hkpBoxShape::~hkpBoxShape() throw() {}

// The deleting-destructor entry receives this in ECX and flags on the stack; EDX is unused.
// @fnv 0x00c9e1b0
void* __fastcall DeleteBoxShape(hkpBoxShape* shape, void*, unsigned char flags)
{
    shape->hkpBoxShape::~hkpBoxShape();
    if (flags & 1)
    {
        hkMemoryRouter* router = _D1A0E0GetMemoryRouter();
        // The shared MemoryManager has no sized allocator Free; preserve slot 2's dispatch.
        typedef void (__thiscall* SizedFree)(void*, void*, unsigned short);
        void* allocator = router->m_heap;
        (*reinterpret_cast<SizedFree**>(allocator))[2](allocator, shape, shape->m_usMemSizeAndFlags);
    }
    return shape;
}

// FUN_00c9e1a0: __stdcall stub returning constant 0x30 (two unused stack params).
// @fnv 0x00c9e1a0
// src: GUESS 0x00c9e1a0 (confidence: high)
int __stdcall Object_Return0x30(int a1, int a2)
{
    return 0x30;
}

extern "C" int DAT_01268940;

void __cdecl hkReferencedObject_calcContentStatistics(int a, int* b);

// @fnv 0x00c9db60
// src: HAVOK_SRC 0x00c9db60
void __cdecl hkpBoxShape_calcContentStatistics(int a, int* b) {
    return hkReferencedObject_calcContentStatistics(a, &DAT_01268940);
}

void __cdecl ComputeAabbFromTransform(const hkTransform& transform, const hkVector4& halfExtents, hkReal tolerance, hkAabb& out);

// Computes the shape's AABB by calling ComputeAabbFromTransform with the transform, the shape's half extents and tolerance added to a stored value.
// @fnv 0x00c9dc10
void __thiscall hkpBoxShape::GetAabb(const hkTransform& transform, hkReal tolerance, hkAabb& out) const
{
    ComputeAabbFromTransform(transform, m_vHalfExtents, m_fSphereRadius + tolerance, out);
}

extern void* DAT_010c70b4;

// @fnv 0x00c9ddb0
hkpBoxShape* hkpBoxShape::SetExtentsAndRadius(const hkVector4& extents, float radius)
{
    m_fSphereRadius = radius;
    m_sReferenceCount = 1;
    m_ulUserData = 0;
    *reinterpret_cast<int*>(&m_type) = 4;
    *reinterpret_cast<void**>(this) = &DAT_010c70b4;
    memcpy(&m_vHalfExtents, &extents, sizeof(m_vHalfExtents));

    float smaller = m_vHalfExtents.x < m_vHalfExtents.y ? m_vHalfExtents.x : m_vHalfExtents.y;
    m_vHalfExtents.w = smaller;
    m_vHalfExtents.w = m_vHalfExtents.z < m_vHalfExtents.w ? m_vHalfExtents.z : m_vHalfExtents.w;
    return this;
}

extern "C" LocalM128 _mm_and_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_xor_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_cmplt_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_setzero_ps(void);
extern "C" LocalM128 _mm_load_ps(const float*);
extern "C" void _mm_store_ps(float*, LocalM128);
extern "C" int _mm_movemask_ps(LocalM128);

extern float DAT_010c44d0[4];

// @fnv 0x00c9dc40
// src: HAVOK_SRC 0x00c9dc40
void __thiscall hkpBoxShape::getSupportingVertexImpl(const float* src, float* dst)
{
    hkVector4 e;
    memcpy(&e, &m_vHalfExtents, sizeof(e));
    LocalM128 v = _mm_and_ps(_mm_load_ps(src), _mm_load_ps(DAT_010c44d0));
    v = _mm_xor_ps(v, _mm_load_ps(&e.x));
    _mm_store_ps(&e.x, v);
    int m = _mm_movemask_ps(_mm_cmplt_ps(v, _mm_setzero_ps()));
    *(unsigned*)&e.w = (m & 7) | 0x3F000000;
    _mm_store_ps(dst, _mm_load_ps(&e.x));
}

// @fnv 0x00c9dcb0
extern "C" void __stdcall ZeroResult(LocalM128* result)
{
    *result = _mm_setzero_ps();
}

extern const LocalM128 DAT_01017d10;
extern const LocalM128 g_brSignMask;

inline void hkVector4::setAbs4(const hkVector4& v) { m_vComponents = _mm_and_ps(v.m_vComponents, DAT_01017d10); }
inline void hkVector4::setNeg4(const hkVector4& v) { m_vComponents = _mm_xor_ps(v.m_vComponents, g_brSignMask); }
inline void hkVector4::SetAllComponents(float f) { m_vComponents = _mm_set_ps1(f); }

// Computes an AABB in world space from a transform, a point, and an extra radius, storing the result in kAabbOut.
// @fnv 0x00c9e120
void __cdecl ComputeAabbFromTransform(const hkTransform& kLocalToWorld, const hkVector4& m_kPoint2, float fExtraRadius, hkAabb& kAabbOut)
{
    hkVector4 kX;
    kX.m_vComponents = _mm_mul_ps(_mm_shuffle_ps(m_kPoint2.m_vComponents, m_kPoint2.m_vComponents, 0x00), reinterpret_cast<const hkVector4&>(kLocalToWorld.m_kColumn0).m_vComponents);
    hkVector4 kY;
    kY.m_vComponents = _mm_mul_ps(_mm_shuffle_ps(m_kPoint2.m_vComponents, m_kPoint2.m_vComponents, 0x55), reinterpret_cast<const hkVector4&>(kLocalToWorld.m_kColumn1).m_vComponents);
    hkVector4 kZ;
    kZ.m_vComponents = _mm_mul_ps(_mm_shuffle_ps(m_kPoint2.m_vComponents, m_kPoint2.m_vComponents, 0xaa), reinterpret_cast<const hkVector4&>(kLocalToWorld.m_kColumn2).m_vComponents);
    kX.setAbs4(kX);
    kY.setAbs4(kY);
    kZ.setAbs4(kZ);
    hkVector4 kExtra;
    kExtra.SetAllComponents(fExtraRadius);
    hkVector4 kExtent;
    kExtent.setAdd4(kX, kY);
    kZ.add4(kExtra);
    kExtent.add4(kZ);
    hkVector4 kNeg;
    kNeg.setNeg4(kExtent);
    hkVector4 kMinPoint;
    kMinPoint.setAdd4(kNeg, reinterpret_cast<const hkVector4&>(kLocalToWorld.m_vTranslation));
    hkVector4 kMaxPoint;
    kMaxPoint.setAdd4(reinterpret_cast<const hkVector4&>(kLocalToWorld.m_vTranslation), kExtent);
    kAabbOut.m_kMaximumCorner = kMaxPoint;
    kAabbOut.m_kMinimumCorner = kMinPoint;
}

// Copies halfExtents into m_vHalfExtents and stores the minimum of x, y, and z into the w component.
// @fnv 0x00c9db90
void __thiscall hkpBoxShape::SetHalfExtents(const hkVector4& halfExtents)
{
    *(LocalM128*)&m_vHalfExtents = *(LocalM128*)&halfExtents;
    m_vHalfExtents.w = (m_vHalfExtents.x < m_vHalfExtents.y) ? m_vHalfExtents.x : m_vHalfExtents.y;
    m_vHalfExtents.w = (m_vHalfExtents.w > m_vHalfExtents.z) ? m_vHalfExtents.z : m_vHalfExtents.w;
}

// @fnv 0x00c9dbf0
void hkpBoxShape::GetHalfExtents(hkVector4& result) const
{
    _mm_store_ps(reinterpret_cast<float*>(&result),
                 _mm_load_ps(reinterpret_cast<const float*>(&m_vHalfExtents)));
}

extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);

extern "C" const LocalM128 DAT_010c7030[8];

// Multiplies the half-extents and sphere radius by DAT_010c7030 coefficients and writes the results into sphereBuffer.
// @fnv 0x00c9dd30
// src: HAVOK_SRC 0x00c9dd30
void* hkpBoxShape::getCollisionSpheresImpl(LocalM128* sphereBuffer) const
{
    __declspec(align(16)) hkVector4 extents;
    memcpy(&extents, &m_vHalfExtents, sizeof(extents));
    extents.w = m_fSphereRadius;

    LocalM128 v = *(LocalM128*)&extents;
    int i = 3;
    const LocalM128* src = DAT_010c7030 + 1;
    LocalM128* dst = sphereBuffer + 1;
    for (; i >= 0; i--) {
        LocalM128 b = _mm_mul_ps(src[0], v);
        LocalM128 a = _mm_mul_ps(src[-1], v);
        dst[-1] = a;
        dst[0] = b;
        src += 2; dst += 2;
    }

    return sphereBuffer;
}

extern "C"
{
    unsigned __int64 __rdtsc(void);
    void _ReadWriteBarrier(void);
    LocalM128 _mm_set_ps1(float);
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_xor_ps(LocalM128, LocalM128);
    LocalM128 _mm_setzero_ps(void);
    LocalM128 _mm_cmple_ps(LocalM128, LocalM128);
    int _mm_movemask_ps(LocalM128);
}

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

inline void hkMonitorStream::TimerCommand::setTime()
{
    _ReadWriteBarrier();
    hkUint32 ticks;
    __asm {
        rdtsc
        mov dword ptr[ticks], eax
    }
    m_time0 = ticks;
}

struct BRMonitorStream
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;

    static unsigned long ms_uiThreadLocalStorageIndex;

    static BRMonitorStream& GetMonitorStream() { return *(BRMonitorStream*)TlsGetValue(ms_uiThreadLocalStorageIndex); }
    bool memoryAvailable() const { return m_kRayEnd < m_pCurrentCommand; }


    void timerCommandEarly(const char* name) {
        if (memoryAvailable()) {
            hkMonitorStream::TimerCommand* h=(hkMonitorStream::TimerCommand*)m_kRayEnd;
            h->m_commandAndMonitor=name;
            _ReadWriteBarrier();
            hkUint32 ticks;
            __asm {
                rdtsc
                mov dword ptr[ticks], eax
            }
            _ReadWriteBarrier();
            h->m_time0=ticks;
            m_kRayEnd=(char*)(h+1);
        }
    }

    void timerCommand(const char* name)
    {
        if (memoryAvailable())
        {
            hkMonitorStream::TimerCommand* h = (hkMonitorStream::TimerCommand*)m_kRayEnd;
            h->m_commandAndMonitor = name;
            h->setTime();
            m_kRayEnd = (char*)(h + 1);
        }
    }
};

extern const LocalM128 g_brSignMask;

inline float& hkVector4::operator()(int i) { return m_vComponents.m128_f32[i]; }
inline const float& hkVector4::operator()(int i) const { return m_vComponents.m128_f32[i]; }
inline void hkVector4::setZero4() { m_vComponents = _mm_setzero_ps(); }

// The shared comparison returns an undeclared CompareBits type; this unit needs its integer mask.
inline int RayComparisonMask(const hkVector4& a, const hkVector4& b)
{
    return _mm_movemask_ps(_mm_cmple_ps(a.m_vComponents, b.m_vComponents));
}

struct BRRayCastInput
{
    hkVector4 m_vFrom;
    hkVector4 m_vTo;
};

struct BRRayCastOutput
{
    hkVector4 m_vHitNormal;
    hkReal m_fHitFraction;
    int m_iExtraInfo;
    int unk18; int unk1c;
    hkUint32 m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;

    void setKey(hkUint32 key) { m_uiShapeKeys[m_uiShapeKeyIndex] = key; }
};

// @fnv 0x00c9de40
// src: HAVOK_SRC 0x00c9de40
hkBool hkpBoxShape::castRayImpl(const BRRayCastInput& input, BRRayCastOutput& results) const
{
    BRMonitorStream::GetMonitorStream().timerCommand("TtrcBox");

    hkVector4 tolerance4;
    tolerance4.SetAllComponents(m_fSphereRadius);
    hkVector4 halfExtents;
    halfExtents.setAdd4(tolerance4, m_vHalfExtents);
    hkVector4 negHalfExtents;
    negHalfExtents.setNeg4(halfExtents);

    int fromOutsidePos = RayComparisonMask(halfExtents, input.m_vFrom) & 7;
    int fromOutsideNeg = RayComparisonMask(input.m_vFrom, negHalfExtents) & 7;
    int toOutsidePos = RayComparisonMask(halfExtents, input.m_vTo) & 7;
    int toOutsideNeg = RayComparisonMask(input.m_vTo, negHalfExtents) & 7;

    if ((fromOutsidePos & toOutsidePos) || (fromOutsideNeg & toOutsideNeg) || !(fromOutsideNeg | fromOutsidePos))
    {
        BRMonitorStream::GetMonitorStream().timerCommandEarly("Et");
        return false;
    }

    hkReal tEnter = 0.0f;
    hkVector4 normal;

    const int axisMasks[3] = { 1, 2, 4 };
    int checkMask = fromOutsidePos | toOutsidePos;
    int enterMask = fromOutsidePos;
    hkReal tExit = results.m_fHitFraction;
    hkReal sign = 1.0f;

    for (int side = 1; side >= 0; side--)
    {
        int i = 0;
        const float* component = &input.m_vFrom(2);
        do
        {
            if (checkMask & axisMasks[i + 2])
            {
                hkReal ext = negHalfExtents(i + 2);
                hkReal fromDist = sign * component[0] + ext;
                hkReal toDist = component[4] * sign + ext;
                hkReal t = fromDist / (fromDist - toDist);
                if (enterMask & axisMasks[i + 2])
                {
                    if (t >= tEnter)
                    {
                        tEnter = t;
                        normal.setZero4();
                        normal(i + 2) = sign;
                    }
                }
                else
                {
                    if (!(t > tExit))
                    {
                        tExit = t;
                    }
                }
                if (tExit < tEnter)
                {
                    BRMonitorStream::GetMonitorStream().timerCommand("Et");
                    return false;
                }
            }
        } while (--component, --i >= -2);
        checkMask = toOutsideNeg | fromOutsideNeg;
        enterMask = fromOutsideNeg;
        sign = -1.0f;
    }

    results.m_fHitFraction = tEnter;
    results.m_vHitNormal = normal;
    results.setKey(0xffffffff);

    BRMonitorStream::GetMonitorStream().timerCommand("Et");
    return true;
}

