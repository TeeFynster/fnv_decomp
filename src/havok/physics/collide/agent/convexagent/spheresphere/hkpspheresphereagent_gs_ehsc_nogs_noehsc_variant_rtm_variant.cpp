// src/havok/physics/collide/agent/convexagent/spheresphere/hkpspheresphereagent_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/agent/convexagent/spheresphere/hkpspheresphereagent_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/collide/agent/convexagent/spheresphere/hkpspheresphereagent_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/agent/convexagent/spheresphere/hkpspheresphereagent.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/collide/agent/convexagent/spheresphere/hkpspheresphereagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/spheresphere/hkpspheresphereagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C" void __cdecl hkpSphereSphereAgent_staticGetPenetrations(void* a, void* b, void* c, void* d);
void __stdcall hkpSphereSphereAgent_getPenetrations(void* a, void* c, void* b, void* d);
struct S_00d3f660_Owner
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void Release(unsigned short id, void* arg);
};
struct S_00d3f660
{
    virtual ~S_00d3f660();
    int unk4;
    S_00d3f660_Owner* unk8;
    unsigned short unkC;
    void ReleaseAndDelete(void* arg);
};
#include <xmmintrin.h>
#include <windows.h>
unsigned __int64 __cdecl __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern DWORD DAT_0126835c;
struct SRadius
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float m_fBoundRadius;
    float getRadius() const
    {
        return m_fBoundRadius;
    }
};
struct Vect
{
    __m128 quad;
    void sub(const Vect& a, const Vect& b)
    {
        quad = _mm_sub_ps(a.quad, b.quad);
    }
    float lengthSquared() const
    {
        __m128 p = _mm_mul_ps(quad, quad);
        __m128 s = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        float r;
        _mm_store_ss(&r, _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), s));
        return r;
    }
};
struct SCenter
{
    float unk00;
    float unk04;
    float unk08;
    float unk0C;
    float unk10;
    float unk14;
    float unk18;
    float unk1C;
    float unk20;
    float unk24;
    float unk28;
    float unk2C;
    Vect m_vCenter;
};
struct SProxy
{
    SRadius* m_pProxyRadius;
    void* unk04;
    SCenter* m_pCenter;
};
struct STraceRec
{
    const char* unk00;
    unsigned int unk04;
    unsigned int unk08;
};
struct STraceBuf
{
    void* unk00;
    STraceRec* unk04;
    void* unk08;
    STraceRec* unk0C;
};
struct SListener
{
    virtual void v00() = 0;
    virtual void v04(SProxy* a, SProxy* b) = 0;
};
// @fnv 0x00d3f6a0
// src: XBOX_PDB 0x00d3f6a0
extern "C" void __cdecl hkpSphereSphereAgent_staticGetPenetrations(void* a, void* b, void* c, void* d)
{
    STraceBuf* pBuf = (STraceBuf*)TlsGetValue(DAT_0126835c);
    if (pBuf->unk04 < pBuf->unk0C)
    {
        STraceRec* pRec = pBuf->unk04;
        pRec->unk00 = "TtSphereSphere";
        {
            _ReadWriteBarrier();
            volatile unsigned int stamp = (unsigned int)__rdtsc();
            pRec->unk04 = stamp;
        }
        pBuf->unk04 = pRec + 1;
    }
    SProxy* pA = (SProxy*)a;
    SProxy* pB = (SProxy*)b;
    Vect delta;
    delta.sub(pB->m_pCenter->m_vCenter, pA->m_pCenter->m_vCenter);
    float sumRadius = pA->m_pProxyRadius->getRadius() + pB->m_pProxyRadius->getRadius();
    float dist2 = delta.lengthSquared();
    if (dist2 < sumRadius * sumRadius)
    {
        ((SListener*)d)->v04(pA, pB);
    }
    STraceBuf* pBuf2 = (STraceBuf*)TlsGetValue(DAT_0126835c);
    if (pBuf2->unk04 < pBuf2->unk0C)
    {
        STraceRec* pRec2 = pBuf2->unk04;
        pRec2->unk00 = "Et";
        {
            _ReadWriteBarrier();
            volatile unsigned int stamp = (unsigned int)__rdtsc();
            pRec2->unk04 = stamp;
        }
        pBuf2->unk04 = pRec2 + 1;
    }
}

#include <windows.h>
#include <intrin.h>
#include <xmmintrin.h>
#include <math.h>

extern DWORD DAT_0126835c;

struct S_00d3fb20_TimerCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
};

struct S_00d3fb20_MonitorStream
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
};

static inline void S_00d3fb20_Timer(const char* name, unsigned int& t)
{
    S_00d3fb20_MonitorStream* s = (S_00d3fb20_MonitorStream*)TlsGetValue(DAT_0126835c);
    if (s->m_kRayEnd < s->m_pCurrentCommand)
    {
        S_00d3fb20_TimerCommand* h = (S_00d3fb20_TimerCommand*)s->m_kRayEnd;
        h->m_pCommandName = name;
        _ReadWriteBarrier();
        t = (unsigned int)__rdtsc();
        h->m_uiStartTicks = *(volatile unsigned int*)&t;
        s->m_kRayEnd = (char*)(h + 1);
    }
}

// hkVector4 stand-in: 4 floats (an __m128 member would add a GS cookie)
struct __declspec(align(16)) S_00d3fb20_Vector4
{
    float x, y, z, w;
    __m128& q()
    {
        return reinterpret_cast<__m128&>(*this);
    }
    const __m128& q() const
    {
        return reinterpret_cast<const __m128&>(*this);
    }
    void setSub4(const S_00d3fb20_Vector4& a, const S_00d3fb20_Vector4& b)
    {
        q() = _mm_sub_ps(a.q(), b.q());
    }
    float dot3(const S_00d3fb20_Vector4& v) const
    {
        const __m128 p = _mm_mul_ps(q(), v.q());
        const __m128 s = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        float r;
        _mm_store_ss(&r, _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), s));
        return r;
    }
    void setMul4(float r, const S_00d3fb20_Vector4& v)
    {
        q() = _mm_mul_ps(_mm_shuffle_ps(_mm_load_ss(&r), _mm_load_ss(&r), 0), v.q());
    }
    __forceinline void setAddMul4(const S_00d3fb20_Vector4& a, const S_00d3fb20_Vector4& b, float r)
    {
        q() = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(_mm_load_ss(&r), _mm_load_ss(&r), 0), b.q()), a.q());
    }
    void setXYZ(const S_00d3fb20_Vector4& v)
    {
        q() = _mm_shuffle_ps(v.q(), _mm_unpackhi_ps(v.q(), q()), _MM_SHUFFLE(3, 0, 1, 0));
    }
};

extern S_00d3fb20_Vector4 DAT_01268370;

struct __declspec(align(16)) S_00d3fb20_Transform
{
    S_00d3fb20_Vector4 m_kColumn0;
    S_00d3fb20_Vector4 m_kColumn1;
    S_00d3fb20_Vector4 m_kColumn2;
    S_00d3fb20_Vector4 m_vTranslation;
};

struct S_00d3fb20_SphereShape
{
    void* vtbl;
    int unk4;
    int unk8;
    int unkC;
    float m_fSphereRadius;
    float getRadius() const
    {
        return m_fSphereRadius;
    }
};

struct S_00d3fb20_CdBody
{
    const S_00d3fb20_SphereShape* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const S_00d3fb20_Transform* m_pMotionState;
    const S_00d3fb20_CdBody* m_parent;
};

struct S_00d3fb20_Input
{
    void* m_pCollisionDispatcher;
    int unk4;
    float m_fScalar;
};

struct __declspec(align(16)) S_00d3fb20_ContactPoint
{
    S_00d3fb20_Vector4 m_vContactPosition;
    S_00d3fb20_Vector4 m_vSeparatingNormal;
};

struct __declspec(align(16)) S_00d3fb20_CdPoint
{
    S_00d3fb20_ContactPoint m_kPoint;
    const S_00d3fb20_CdBody& m_pBodyA;
    const S_00d3fb20_CdBody& m_pBodyB;
    S_00d3fb20_CdPoint(const S_00d3fb20_CdBody& a, const S_00d3fb20_CdBody& b) : m_pBodyA(a), m_pBodyB(b)
    {}
};

struct S_00d3fb20_Collector
{
    virtual void v00();
    virtual void AddCdPoint(const S_00d3fb20_CdPoint& event);
};

template <class T> struct S_00d3fb20_Ptr
{
    T* p;
    T& val() const
    {
        return *p;
    }
};

static __forceinline void S_00d3fb20_SetDist(S_00d3fb20_Vector4& n, float dist, float ra, float rb)
{
    n.w = dist - (rb + ra);
}

static __forceinline float S_00d3fb20_W(float dist, const float& rb, const float& ra)
{
    return dist - (rb + ra);
}

// @fnv 0x00d3fb20
// src: XBOX_PDB 0x00d3fb20
void __cdecl hkpSphereSphereAgent_staticGetClosestPoints(const S_00d3fb20_CdBody& pA, const S_00d3fb20_CdBody& pB, const S_00d3fb20_Input& pI,
                          S_00d3fb20_Collector& collector)
{
    union
    {
        float f;
        unsigned int u;
    } reusable;
    float& reused = reusable.f;
    union
    {
        volatile unsigned int tick;
        float distance;
    } scratch;
    {
        S_00d3fb20_MonitorStream* stream = (S_00d3fb20_MonitorStream*)TlsGetValue(DAT_0126835c);
        if (stream->m_kRayEnd < stream->m_pCurrentCommand)
        {
            S_00d3fb20_TimerCommand* h = (S_00d3fb20_TimerCommand*)stream->m_kRayEnd;
            h->m_pCommandName = "TtSphereSphere";
            _ReadWriteBarrier();
            scratch.tick = (unsigned int)__rdtsc();
            h->m_uiStartTicks = scratch.tick;
            stream->m_kRayEnd = (char*)(h + 1);
        }
    }
    const S_00d3fb20_CdBody& bodyA = pA;
    const S_00d3fb20_CdBody& bodyB = pB;
    const S_00d3fb20_Input& input = pI;

    const S_00d3fb20_SphereShape* sphereA = bodyA.m_pCollisionShape;
    const S_00d3fb20_Vector4& posB = bodyB.m_pMotionState->m_vTranslation;
    const S_00d3fb20_SphereShape* sphereB = bodyB.m_pCollisionShape;
    S_00d3fb20_CdPoint event(bodyA, bodyB);
    const S_00d3fb20_Vector4& posA = bodyA.m_pMotionState->m_vTranslation;

    S_00d3fb20_Vector4 vec;
    vec.setSub4(posA, posB);
    reused = sphereA->getRadius() + sphereB->getRadius() + input.m_fScalar;
    const float& radiusSum = reused;
    const __m128 p = _mm_mul_ps(vec.q(), vec.q());
    const __m128 s = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
    _mm_store_ss(&scratch.distance, _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), s));
    const float& distSquared = scratch.distance;

    if (distSquared < radiusSum * radiusSum)
    {
        float dist;
        if (distSquared > 0.0f)
        {
            const float invDist = 1.0f / sqrtf(distSquared);
            event.m_kPoint.m_vSeparatingNormal.setMul4(invDist, vec);
            dist = distSquared * invDist;
        }
        else
        {
            dist = 0.0f;
            event.m_kPoint.m_vSeparatingNormal.setXYZ(DAT_01268370);
        }
        float w = S_00d3fb20_W(dist, sphereB->getRadius(), sphereA->getRadius());
        event.m_kPoint.m_vContactPosition.setAddMul4(posB, event.m_kPoint.m_vSeparatingNormal, sphereB->getRadius());
        event.m_kPoint.m_vSeparatingNormal.w = w;
        collector.AddCdPoint(event);
    }

    S_00d3fb20_Timer("Et", reusable.u);
}
