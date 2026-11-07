#define FNV64_HKVECTOR4_OWN_ASSIGN   // this unit defines its own hkVector4 assign form

// src/havok/physics/collide/agent/convexagent/spherecapsule/hkpspherecapsuleagent_gs_nogs_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/agent/convexagent/spherecapsule/hkpspherecapsuleagent_gs_nogs_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/collide/agent/convexagent/spherecapsule/hkpspherecapsuleagent_gs_nogs_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/collide/agent/convexagent/spherecapsule/hkpspherecapsuleagent.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/collide/agent/convexagent/spherecapsule/hkpspherecapsuleagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/spherecapsule/hkpspherecapsuleagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <xmmintrin.h>
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkContactPoint.h"
#include "../../../../../../../include/hkMatrix3.h"
#include "../../../../../../../include/hkRotation.h"
#include "../../../../../../../include/hkTransform.h"
#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/hkpCapsuleShape.h"
#include "../../../../../../../include/hkpCdBody.h"
#include "../../../../../../../include/hkpCdPointCollector.h"
#include "../../../../../../../include/hkpConvexShape.h"
#include "../../../../../../../include/hkpShape.h"
#include "../../../../../../../include/hkpSphereShape.h"

struct S_00d3ef70_Input;
struct S_00d3ef70_Agent;
struct S_00d3ef70_Collector;
typedef S_00d3ef70_Agent* (*S_00d3ef70_CreateFunc)(const hkpCdBody&, const hkpCdBody&,
                                                   const S_00d3ef70_Input&, void*);
typedef void (*S_00d3ef70_GetPenetrationsFunc)(const hkpCdBody&, const hkpCdBody&,
                                               const S_00d3ef70_Input&, S_00d3ef70_Collector&);
typedef void (*S_00d3ef70_GetClosestPointsFunc)(const hkpCdBody&, const hkpCdBody&,
                                                const S_00d3ef70_Input&, S_00d3ef70_Collector&);
typedef void (*S_00d3ef70_LinearCastFunc)(const hkpCdBody&, const hkpCdBody&, const S_00d3ef70_Input&,
                                          S_00d3ef70_Collector&, S_00d3ef70_Collector*);
struct S_00d3ef70_AgentFuncs
{
    S_00d3ef70_CreateFunc m_pCreateFunc;
    S_00d3ef70_GetPenetrationsFunc m_pQueryPenetrationsFunc;
    S_00d3ef70_GetClosestPointsFunc m_getClosestPointsFunc;
    S_00d3ef70_LinearCastFunc m_pLinearCastFunc;
    bool m_bIsFlipped;
    bool m_bIsPredictive;
};
struct S_00d3ef70_Dispatcher
{
    void registerCollisionAgent(S_00d3ef70_AgentFuncs& f, int typeA, int typeB);
};
S_00d3ef70_Agent* hkpSphereCapsuleAgent_createCapsuleSphereAgent(const hkpCdBody&, const hkpCdBody&, const S_00d3ef70_Input&, void*);
void Object_UpdateFields_00d3f040(const hkpCdBody&, const hkpCdBody&, const S_00d3ef70_Input&, S_00d3ef70_Collector&);
void Object_ProcessAndReturnValue_00d3f4c0(const hkpCdBody&, const hkpCdBody&, const S_00d3ef70_Input&, S_00d3ef70_Collector&);
void Object_UpdateFields_00d3ac80(const hkpCdBody&, const hkpCdBody&, const S_00d3ef70_Input&, S_00d3ef70_Collector&,
                  S_00d3ef70_Collector*);
S_00d3ef70_Agent* hkMemoryRouter_getInstance_AllocateAndInitializeObject16(const hkpCdBody&, const hkpCdBody&, const S_00d3ef70_Input&, void*);
void hkpSphereCapsuleAgent_staticGetPenetrations(const hkpCdBody&, const hkpCdBody&, const S_00d3ef70_Input&, S_00d3ef70_Collector&);
void FUN_00d3ebe0(const hkpCdBody&, const hkpCdBody&, const S_00d3ef70_Input&, S_00d3ef70_Collector&);
void Object_ProcessEntries_00daf8e0(const hkpCdBody&, const hkpCdBody&, const S_00d3ef70_Input&, S_00d3ef70_Collector&,
                  S_00d3ef70_Collector*);
void hkpSphereCapsuleAgent_registerAgent(S_00d3ef70_Dispatcher* dispatcher);
class InnerCls
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(unsigned short a, int b);
};
inline void InnerCls::v0()
{}
inline void InnerCls::v1()
{}
inline void InnerCls::v2()
{}
inline void InnerCls::v3()
{}
inline void InnerCls::v4()
{}
inline void InnerCls::v5(unsigned short a, int b)
{
    a;
    b;
}
class FUN_00d3e2b0_cls
{
  public:
    virtual void v0(int a);
    int m_i04;
    InnerCls* m_pInner;
    unsigned short m_w0c;
    void hkpSphereCapsuleAgent_cleanup(int a1);
};

struct ObjAllocator
{
    virtual void unk00();
    virtual void* Alloc(unsigned int size);
};
struct SmallRecord
{
    void* m_vptr;
    unsigned short m_w04;
    unsigned short m_w06;
    int m_i08;
    unsigned short m_w0C;
};
extern char DAT_010cf018[];
hkMemoryRouter* hkMemoryRouter_getInstance();
void __cdecl hkpSphereCapsuleAgent_createCapsuleSphereAgent(int a, int b, int c, int d);
void __cdecl hkpSphereCapsuleAgent_staticGetPenetrations(int a, int b, int c, int d);
void __stdcall hkpSphereCapsuleAgent_getPenetrations(int a, int b, int c, int d);
extern char DAT_010ce81c;
struct FUN_00d3f040_tmp
{
    const char* str;
    unsigned char flag;
    unsigned int value;
};
void __cdecl hkpSphereCapsuleAgent_staticGetPenetrations(unsigned int a, unsigned int b, unsigned int c, FUN_00d3f040_tmp* p);
void __cdecl Object_UpdateFields_00d3f040(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3);

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern "C" double __cdecl sqrt(double);
extern "C" double __cdecl fabs(double);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);

extern unsigned long g_hkMonitorStreamTls;

// Inline operations declared by the shared headers.
inline void hkVector4::operator=(const hkVector4& vector)
{
    // Keep the scalar component copies emitted by the original aggregate assignment.
    m_vComponents.m128_i32[0] = vector.m_vComponents.m128_i32[0];
    m_vComponents.m128_i32[1] = vector.m_vComponents.m128_i32[1];
    m_vComponents.m128_i32[2] = vector.m_vComponents.m128_i32[2];
    m_vComponents.m128_i32[3] = vector.m_vComponents.m128_i32[3];
}
inline float& hkVector4::operator()(int i)
{
    return m_vComponents.m128_f32[i];
}
inline const float& hkVector4::operator()(int i) const
{
    return ((const float*)&m_vComponents)[i];
}
inline const hkTransform& hkpCdBody::getTransform() const
{
    return *static_cast<const hkTransform*>(m_pMotionState);
}
inline const hkRotation& hkTransform::getRotation() const
{
    return reinterpret_cast<const hkRotation&>(m_row0);
}
inline const hkVector4& hkTransform::getTranslation() const
{
    return reinterpret_cast<const hkVector4&>(m_row3);
}

static inline float hkMathSqrt(float r)
{
    volatile float v = (float)sqrt(r);
    return v;
}

static inline float hkMathFabs(float r, volatile float& v)
{
    v = (float)fabs(r);
    return v;
}

struct hkMonitorTimerCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
};

struct CollisionAgentContext
{
    void* m_pCollisionDispatcher;
    void* m_iFilter;
    float m_fScalar;
};

struct ContactPointPair
{
    ContactPointPair(const hkpCdBody& a, const hkpCdBody& b) : m_pBodyA(a), m_pBodyB(b)
    {}
    hkContactPoint m_kPoint;
    const hkpCdBody& m_pBodyA;
    const hkpCdBody& m_pBodyB;
};

static inline void timerCommand(const char* name, volatile unsigned int& ticks)
{
    hkMonitorStream* s = (hkMonitorStream*)TlsGetValue(g_hkMonitorStreamTls);
    if (s->m_end.val() < s->m_capacityMinus16.val())
    {
        hkMonitorTimerCommand* h = (hkMonitorTimerCommand*)s->m_end.val();
        h->m_pCommandName = name;
        _ReadWriteBarrier();
        ticks = (unsigned int)__rdtsc();
        _ReadWriteBarrier();
        h->m_uiStartTicks = ticks;
        s->m_end.m_storage = (char*)(h + 1);
    }
}

// @fnv 0x00d3e850
// src: HAVOK_SRC 0x00d3e850
void __stdcall hkpSphereCapsuleAgent_getClosestPoints(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const CollisionAgentContext& input,
                            hkpCdPointCollector& collector)
{
    union
    {
        unsigned int startTicks;
        float distanceSquared;
        float minimumAbs;
    } scal0;
    struct
    {
        union
        {
            float radiusSum;
            unsigned int endTicks;
        };
        float absZ;
    } scal2;
    float absY;
    timerCommand("TtSphereCapsule", scal0.startTicks);

    const hkpSphereShape* sphereA = static_cast<const hkpSphereShape*>(bodyA.m_pCollisionShape);
    const hkpCapsuleShape* capsuleB = static_cast<const hkpCapsuleShape*>(bodyB.m_pCollisionShape);
    const hkVector4& posA = bodyA.getTransform().getTranslation();
    hkVector4 first;
    hkVector4 second;
    hkVector4 third;
    hkVector4 fourth[2];
    ContactPointPair event(bodyA, bodyB);
    const hkTransform& tB = bodyB.getTransform();
    first = tB.getRotation().m_kColumn0;
    fourth[0].m_vComponents.m128_i32[0] = tB.getRotation().m_kColumn1.m_vComponents.m128_i32[0];
    fourth[0].m_vComponents.m128_i32[1] = tB.getRotation().m_kColumn1.m_vComponents.m128_i32[1];
    fourth[0].m_vComponents.m128_i32[2] = tB.getRotation().m_kColumn1.m_vComponents.m128_i32[2];
    __m128 c0 = _mm_load_ps(first.m_vComponents.m128_f32);
    fourth[0].m_vComponents.m128_i32[3] = tB.getRotation().m_kColumn1.m_vComponents.m128_i32[3];
    second = tB.getRotation().m_kColumn2;
    __m128 c1 = _mm_load_ps(fourth[0].m_vComponents.m128_f32);
    third.m_vComponents.m128_i32[0] = tB.getTranslation().m_vComponents.m128_i32[0];
    __m128 c2 = _mm_load_ps(second.m_vComponents.m128_f32);
    third.m_vComponents.m128_i32[1] = tB.getTranslation().m_vComponents.m128_i32[1];
    third.m_vComponents.m128_i32[2] = tB.getTranslation().m_vComponents.m128_i32[2];
    third.m_vComponents.m128_i32[3] = tB.getTranslation().m_vComponents.m128_i32[3];
    __m128 tr = _mm_load_ps(third.m_vComponents.m128_f32);
    const hkVector4* in = &capsuleB->m_kVertexA;
    int i = 1;
    do
    {
        __m128 v = in[i].m_vComponents;
        __m128 xb = _mm_shuffle_ps(v, v, _MM_SHUFFLE(0, 0, 0, 0));
        __m128 yb = _mm_shuffle_ps(v, v, _MM_SHUFFLE(1, 1, 1, 1));
        __m128 zb = _mm_shuffle_ps(v, v, _MM_SHUFFLE(2, 2, 2, 2));
        __m128 r0 = _mm_mul_ps(c0, xb);
        __m128 r1 = _mm_mul_ps(c1, yb);
        __m128 r2 = _mm_mul_ps(c2, zb);
        fourth[i].m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), _mm_add_ps(r2, tr));
    } while (--i >= 0);

    hkpCapsuleShape::GetClosestPointOnLineSegment(posA, fourth[0], fourth[1], third);

    scal2.radiusSum = sphereA->m_fSphereRadius + capsuleB->m_fSphereRadius;
    float refDist = scal2.radiusSum + input.m_fScalar;

    second.m_vComponents = _mm_sub_ps(posA.m_vComponents, third.m_vComponents);
    {
        __m128 len = _mm_mul_ps(second.m_vComponents, second.m_vComponents);
        __m128 s0 = _mm_shuffle_ps(len, len, _MM_SHUFFLE(1, 1, 1, 1));
        __m128 s1 = _mm_shuffle_ps(len, len, _MM_SHUFFLE(2, 2, 2, 2));
        _mm_store_ss(&scal0.distanceSquared, _mm_add_ss(s1, _mm_add_ss(s0, len)));
    }

    float refDist2 = refDist * refDist;
    if (!(scal0.distanceSquared >= refDist2))
    {
        float distance;
        hkVector4& normal = event.m_kPoint.m_vSeparatingNormal;
        if (scal0.distanceSquared > 0.0f)
        {
            distance = hkMathSqrt(scal0.distanceSquared);
            normal.m_vComponents = second.m_vComponents;
        }
        else
        {
            distance = 0.0f;
            first.m_vComponents = _mm_sub_ps(fourth[1].m_vComponents, fourth[0].m_vComponents);

            int min = 0;
            int ok1 = 1;
            int ok2 = 2;
            scal0.minimumAbs = hkMathFabs(first(0), scal0.minimumAbs);
            absY = hkMathFabs(first(1), scal2.absZ);
            scal2.absZ = hkMathFabs(first(2), scal2.absZ);
            if (absY < scal0.minimumAbs)
            {
                ok1 = 0;
                min = 1;
                scal0.minimumAbs = absY;
            }
            if (scal2.absZ < scal0.minimumAbs)
            {
                ok2 = min;
                min = 2;
            }
            normal.m_vComponents = _mm_setzero_ps();
            normal(ok1) = first(ok2);
            normal(ok2) = -first(ok1);
        }

        {
            __m128 len = _mm_mul_ps(normal.m_vComponents, normal.m_vComponents);
            __m128 s0 = _mm_shuffle_ps(len, len, _MM_SHUFFLE(1, 1, 1, 1));
            __m128 s1 = _mm_shuffle_ps(len, len, _MM_SHUFFLE(2, 2, 2, 2));
            __m128 len2 = _mm_add_ss(s1, _mm_add_ss(s0, len));
            __m128 e = _mm_rsqrt_ss(len2);
            __m128 eq = _mm_cmpeq_ss(len2, _mm_set_ss(0.0f));
            __m128 he = _mm_mul_ss(_mm_set_ss(0.5f), e);
            __m128 ee = _mm_mul_ss(_mm_mul_ss(len2, e), e);
            __m128 r = _mm_mul_ss(he, _mm_sub_ss(_mm_set_ss(3.0f), ee));
            r = _mm_andnot_ps(eq, r);
            hkVector4 broadcast;
            broadcast.m_vComponents = r;
            normal.m_vComponents =
                _mm_mul_ps(_mm_shuffle_ps(broadcast.m_vComponents, broadcast.m_vComponents, 0), normal.m_vComponents);
        }

        absY = capsuleB->m_fSphereRadius - distance;
        event.m_kPoint.m_vContactPosition.m_vComponents =
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(_mm_load_ss(&absY), _mm_load_ss(&absY), 0), normal.m_vComponents),
                       posA.m_vComponents);
        normal(3) = distance - scal2.radiusSum;
        collector.AddCdPoint(event);
    }

    timerCommand("Et", scal2.endTicks);
}
