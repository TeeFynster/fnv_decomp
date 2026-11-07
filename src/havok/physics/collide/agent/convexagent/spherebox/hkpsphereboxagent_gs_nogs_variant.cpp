
// src/havok/physics/collide/agent/convexagent/spherebox/hkpsphereboxagent_gs_nogs_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/collide/agent/convexagent/spherebox/hkpsphereboxagent.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/agent/convexagent/spherebox/hkpsphereboxagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/spherebox/hkpsphereboxagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkpSymmetricAgentFlipCollector.h"

extern void __cdecl hkpSphereBoxAgent_staticGetPenetrations(int a, int b, int c, int d);
void __stdcall ForwardToD3C440(int a, int b, int c, int d);
struct Conversion
{
    void (*convert)();
    void (*create)();
    void (*copy)();
    void (*destroy)();
    bool enabled;
    bool supported;
};
struct Registry
{
    void AppendRecordAndRegisterAgents(Conversion*, int, int);
};
void hkpSphereBoxAgent_createBoxSphereAgent();
void Object_UpdateFields_00d3cfc0();
void FlipAndDispatchCollector();
void Object_UpdateFields_00d3ac80();
void CreateD3C380Obj();
void hkpSphereBoxAgent_staticGetPenetrations();
void hkpSphereBoxAgent_staticGetClosestPoints();
void Object_ProcessEntries_00daf8e0();
void __cdecl hkpSphereBoxAgent_registerAgent(Registry* registry);
extern float DAT_0104da48;
extern void __cdecl hkpSphereBoxAgent_staticGetClosestPoints(void*, void*, int, void*);
void __cdecl FlipAndDispatchCollector(void* arg1, void* arg2, int arg3, int arg4);
struct S_00d3c3c0_Holder
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14(unsigned int idx, int arg);
};
struct S_00d3c3c0_Obj
{
    virtual void v00(int flag);
    int unk04;
    S_00d3c3c0_Holder* unk08;
    unsigned short unk0c;
    void hkpSphereBoxAgent_cleanup(int arg);
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
void __cdecl hkpSphereBoxAgent_createBoxSphereAgent(int a, int b, int c, int d);
class D3CF80CollectorBase
{
  public:
    D3CF80CollectorBase() : m_bHit(false)
    {}
    virtual void AddCdPoint(const void* pkEvent) = 0;

    bool m_bHit;
};
class D3CF80Collector : public D3CF80CollectorBase
{
  public:
    D3CF80Collector(int iFilter) : m_iFilter(iFilter)
    {}
    virtual void AddCdPoint(const void* pkEvent);

    int m_iFilter;
};
class D3CF80Agent
{
  public:
    void ForwardToD3C440(void* pkA, void* pkB, void* pkInput, D3CF80Collector* pkCollector);
    void CollectFilteredEvents(void* pkA, void* pkB, void* pkInput, int iFilter);
};
extern void __cdecl hkpSphereBoxAgent_staticGetPenetrations(int a, int b, int c, int d);
extern char DAT_010ce81c[];
struct FlipCollectorLocal
{
    void* unk00;
    unsigned char unk04;
    int unk08;
};
void __cdecl Object_UpdateFields_00d3cfc0(int a1, int a2, int a3, int a4);
struct CpuCallData
{
    void* descriptor;
    float bound;
    unsigned int value;
};
extern float DAT_0104da48;
extern unsigned char DAT_010ce7fc;
struct CpuObject
{
    void hkpSphereBoxAgent_getClosestPoints(void*, void*, unsigned int, CpuCallData*);
    void hkpSymmetricAgentLinearCast_hkpSphereBoxAgent_getClosestPoints(void*, void*, unsigned int, unsigned int);
};

extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
#include <xmmintrin.h>
#include <windows.h>
extern DWORD hkMonitorStreamTls;

struct S_00d3c440_TimerCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
};

struct S_00d3c440_MonitorStream
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
};

static inline void S_00d3c440_Timer(const char* name)
{
    S_00d3c440_MonitorStream* s = (S_00d3c440_MonitorStream*)TlsGetValue(hkMonitorStreamTls);
    if (s->m_kRayEnd < s->m_pCurrentCommand)
    {
        S_00d3c440_TimerCommand* h = (S_00d3c440_TimerCommand*)s->m_kRayEnd;
        h->m_pCommandName = name;
        _ReadWriteBarrier();
        unsigned int t = (unsigned int)__rdtsc();
        h->m_uiStartTicks = *(volatile unsigned int*)&t;
        s->m_kRayEnd = (char*)(h + 1);
    }
}

struct S_00d3c440_Transform;
struct __declspec(align(16)) S_00d3c440_Vector4
{
    __m128 m_vComponents;
    void setAbs(const S_00d3c440_Vector4& a);
    void setMin4(const S_00d3c440_Vector4& a, const S_00d3c440_Vector4& b)
    {
        m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents);
    }
    void setFlipSign(const S_00d3c440_Vector4& a, const S_00d3c440_Vector4& b);
    void SetTransformedPoint(const S_00d3c440_Transform& t, const S_00d3c440_Vector4& v);
    void setSub4(const S_00d3c440_Vector4& a, const S_00d3c440_Vector4& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    float lengthSquared3() const
    {
        __m128 d = _mm_mul_ps(m_vComponents, m_vComponents);
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(d, d, 0x55), d);
        __m128 xyz = _mm_add_ss(_mm_shuffle_ps(d, d, 0xaa), xy);
        float f;
        _mm_store_ss(&f, xyz);
        return f;
    }
    __m128& q()
    {
        return m_vComponents;
    }
    const __m128& q() const
    {
        return m_vComponents;
    }
};

struct __declspec(align(16)) S_00d3c440_Transform
{
    S_00d3c440_Vector4 m_kColumn0;
    S_00d3c440_Vector4 m_kColumn1;
    S_00d3c440_Vector4 m_kColumn2;
    S_00d3c440_Vector4 m_vTranslation;
};

struct __declspec(align(16)) S_00d3c440_Local : S_00d3c440_Vector4
{
    void hkVector4_setTransformedInversePos(const S_00d3c440_Transform* t, const S_00d3c440_Vector4* v);
};

extern const S_00d3c440_Vector4 DAT_01017d10;
extern const S_00d3c440_Vector4 DAT_010c44d0;
inline void S_00d3c440_Vector4::setAbs(const S_00d3c440_Vector4& a)
{
    m_vComponents = _mm_and_ps(DAT_01017d10.m_vComponents, a.m_vComponents);
}
inline void S_00d3c440_Vector4::setFlipSign(const S_00d3c440_Vector4& a, const S_00d3c440_Vector4& b)
{
    m_vComponents = _mm_xor_ps(a.m_vComponents, _mm_and_ps(DAT_010c44d0.m_vComponents, b.m_vComponents));
}
inline void S_00d3c440_Vector4::SetTransformedPoint(const S_00d3c440_Transform& t, const S_00d3c440_Vector4& v)
{
    const __m128 xx = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0);
    const __m128 yy = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x55);
    const __m128 zz = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xaa);
    m_vComponents =
        _mm_add_ps(_mm_add_ps(_mm_mul_ps(yy, t.m_kColumn1.m_vComponents), _mm_mul_ps(xx, t.m_kColumn0.m_vComponents)),
                   _mm_add_ps(_mm_mul_ps(zz, t.m_kColumn2.m_vComponents), t.m_vTranslation.m_vComponents));
}

struct S_00d3c440_SphereShape
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float m_fSphereRadius;
    float getRadius() const
    {
        return m_fSphereRadius;
    }
};

struct S_00d3c440_BoxShape
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float m_fSphereRadius;
    float getRadius() const
    {
        return m_fSphereRadius;
    }
    int unk14;
    int unk18;
    int unk1C;
    S_00d3c440_Vector4 m_vHalfExtents;
};

struct S_00d3c440_Body
{
    const void* m_pCollisionShape;
    int unk04;
    const S_00d3c440_Transform* m_pMotionState;
};

struct S_00d3c440_Collector
{
    virtual ~S_00d3c440_Collector();
    virtual void AddCdBodyPair(const S_00d3c440_Body& a, const S_00d3c440_Body& b);
};

template <class T> struct S_00d3c440_Pad
{
    T p;
    __forceinline T val() const
    {
        return p;
    }
};

// @fnv 0x00d3c440
// src: XBOX_PDB 0x00d3c440
void __cdecl hkpSphereBoxAgent_staticGetPenetrations(const S_00d3c440_Body* bodyA, const S_00d3c440_Body* bodyB, int c,
                          S_00d3c440_Collector* collector)
{
    S_00d3c440_Timer("TtSphereBox");
    const S_00d3c440_SphereShape* sphere = (const S_00d3c440_SphereShape*)bodyA->m_pCollisionShape;
    const S_00d3c440_Vector4* posA = &bodyA->m_pMotionState->m_vTranslation;
    const S_00d3c440_Body* b = bodyB;
    const S_00d3c440_BoxShape* box = (const S_00d3c440_BoxShape*)b->m_pCollisionShape;

    S_00d3c440_Local centerInB;
    centerInB.hkVector4_setTransformedInversePos(b->m_pMotionState, posA);

    const S_00d3c440_Transform* tB = b->m_pMotionState;
    const float boxRadius = box->m_fSphereRadius;
    S_00d3c440_Vector4 closest;
    closest.setAbs(centerInB);
    closest.setMin4(closest, box->m_vHalfExtents);
    closest.setFlipSign(closest, centerInB);
    S_00d3c440_Vector4 world;
    world.SetTransformedPoint(*tB, closest);
    S_00d3c440_Vector4 diff;
    diff.setSub4(world, *posA);
    const float radiusSum = boxRadius + sphere->m_fSphereRadius;
    float distSq = diff.lengthSquared3();

    if ((double)distSq < (double)radiusSum * radiusSum)
        collector->AddCdBodyPair(*bodyA, *b);
    S_00d3c440_Timer("Et");
}
