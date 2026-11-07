#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit keeps the out-of-line hkVector4 form

// src/havok/physics/collide/agent/convexagent/spheretriangle/hkpspheretriangleagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/spheretriangle/hkpspheretriangleagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Keep the unit's intrinsic declaration: the CRT's extra byte-array members
// change the original compiler's /GS parameter handling.
#ifndef _INCLUDED_MM2
#define _INCLUDED_MM2
// Exe 0x00d3d2a0 FUN_00d3d2a0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C"
{
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_xor_ps(LocalM128, LocalM128);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
}
#endif

#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkThreadMemory.h"
#include "../../../../../../../include/hkVector4q.h"


struct D3DD50CollectorBase
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();

    bool m_bFound;

    D3DD50CollectorBase() : m_bFound(false)
    {}
};

struct D3DD50Collector : D3DD50CollectorBase
{
    int m_iData;

    D3DD50Collector(int iData) : m_iData(iData)
    {}

    virtual void unk00();
    virtual void unk04();
};

void __cdecl D3DD50Query(int a, int b, int c, D3DD50CollectorBase* collector);

// Constructs a D3DD50Collector from d and passes it to D3DD50Query with b, a, c.
// @fnv 0x00d3dd50
void __cdecl QueryD3DCollector(int aiArg1, int aiArg2, int aiArg3, int aiData)
{
    D3DD50Collector collector(aiData);
    D3DD50Query(aiArg2, aiArg1, aiArg3, &collector);
}

extern char DAT_010ce7fc[];

struct Functor_d3e110
{
    void* m_vtbl;
    float m_fHitFraction;
    int m_uiFilterValue;
};

void __cdecl hkpCdBody_ProcessAndReturnValue_00d3d8c0(int a, int b, int c, Functor_d3e110* f);

// Builds a Functor_d3e110 with a max-float value and d, sets its vtable to DAT_010ce7fc, and calls FUN_00d3d8c0(b, a, c, &f).
// @fnv 0x00d3e110
// src: GUESS 0x00d3e110 (confidence: low)
void __cdecl Hkpspheretriangleagent_UpdateState_00d3e110(int a, int b, int aiArg3, int d)
{
    Functor_d3e110 f;
    f.m_fHitFraction = 3.40282e+38f;
    f.m_uiFilterValue = d;
    f.m_vtbl = DAT_010ce7fc;
    hkpCdBody_ProcessAndReturnValue_00d3d8c0(b, a, aiArg3, &f);
}

struct SpawnedInner
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14(unsigned short flags, void* param);
};

class FUN_00d3d200_cls
{
  public:
    virtual void unk00(int flags);
    int m_unk04;              // +0x04
    SpawnedInner* m_pInner;   // +0x08
    unsigned short m_wFlags;  // +0x0C

    void hkpSphereTriangleAgent_cleanup(void* param);
};

// If m_wFlags is not 0xFFFF, forwards m_wFlags and param to m_pInner->unk14, then calls unk00(1) on this object.
// @fnv 0x00d3d200
// src: HAVOK_SRC 0x00d3d200
void FUN_00d3d200_cls::hkpSphereTriangleAgent_cleanup(void* param)
{
    if (m_wFlags != 0xFFFF)
    {
        m_pInner->unk14(m_wFlags, param);
    }
    this->unk00(1);
}

struct hkMemory
{
    virtual void unk0();
    virtual void* allocateChunk(int size);
};

inline void* hkThreadMemory::allocateChunk(int size) throw()
{
    return m_pMemoryAllocator->allocateChunk(size);
}
extern "C" void __cdecl hkpCollideTriangleUtil_setupClosestPointTriangleCache(void* src, void* dst);
extern "C" const void* DAT_010cf060;
extern "C" const void* DAT_010cf09c;

struct TargetAgent
{
    const void* vtable;
    short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_pContactManager;
    unsigned short m_padC;
    short m_padE;
    char m_pAccessManager[0x10];

    TargetAgent(const void* bodyA, void* mgr)
        : m_usMemSizeAndFlags(0x20), m_sReferenceCount(1), m_pContactManager(mgr), m_padC(0xffff)
    {
        vtable = &DAT_010cf060;
        void* triangle = *(void**)bodyA;
        hkpCollideTriangleUtil_setupClosestPointTriangleCache((char*)triangle + 0x20, m_pAccessManager);
        vtable = &DAT_010cf09c;
    }
};

// Allocates a 0x20-byte chunk from the thread memory and constructs a TargetAgent from bodyA and mgr, returning it.
// @fnv 0x00d3d240
void* __cdecl CreateTargetAgent(void* bodyA, void* bodyB, void* input, void* mgr)
{
    TargetAgent* agent = (TargetAgent*)hkThreadMemory::GetMonitorStream()->allocateChunk(0x20);
    agent->TargetAgent::TargetAgent(bodyA, mgr);
    return agent;
}

extern char DAT_010ce81c[];

struct D3DD10Data
{
    void* vt;
    unsigned char flag;
    unsigned int value;
};

struct D3DD10Object
{
    void __thiscall hkpSphereTriangleAgent_getPenetrations(unsigned int a1, unsigned int a2, unsigned int a3, D3DD10Data* data);

    void __thiscall hkpSymmetricAgentLinearCast_hkpSphereTriangleAgent_getPenetrations(unsigned int p0, unsigned int p1, unsigned int p2, unsigned int p3);
};

// Builds a D3DD10Data with value p3, flag 0 and vt DAT_010ce81c, then calls FUN_00d3d2a0 with p1, p0, p2 and that data.
// @fnv 0x00d3dd10
// src: XBOX_PDB 0x00d3dd10
void __thiscall D3DD10Object::hkpSymmetricAgentLinearCast_hkpSphereTriangleAgent_getPenetrations(unsigned int p0, unsigned int p1, unsigned int p2, unsigned int uiValue)
{
    D3DD10Data data;

    data.value = uiValue;
    data.flag = 0;
    data.vt = &DAT_010ce81c[0];

    this->hkpSphereTriangleAgent_getPenetrations(p1, p0, p2, &data);
}

__forceinline void hkVector4q::setBroadcast3(const hkVector4q& v)
{
    m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xff);
}

__forceinline void hkVector4q::addMul4(const hkVector4q& a, const hkVector4q& b)
{
    m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.m_vComponents, b.m_vComponents));
}

__forceinline void hkVector4q::xor4(const hkVector4q& b)
{
    m_vComponents = _mm_xor_ps(m_vComponents, b.m_vComponents);
}

__forceinline void hkVector4q::setXor4(const hkVector4q& a, const hkVector4q& b)
{
    m_vComponents = _mm_xor_ps(a.m_vComponents, b.m_vComponents);
}

template <typename T> __forceinline void hkSwap(T& a, T& b)
{
    T t = a;
    a = b;
    b = t;
}

struct NibblePair
{
    unsigned char lo : 4;
    unsigned char hi : 4;
};

struct SpawnedParticle
{
    hkVector4q m_vContactPosition;
    hkVector4q m_fVelocity;
    hkVector4q m_extra;
};

struct ParticleSystemState
{
    SpawnedParticle* m_kRayEnd;
    int unk0004;
    int unk0008;
    int unk000C;
    SpawnedParticle m_particles[256];
    int unk3010;
    int unk3014;
    int unk3018;
    int unk301C;
    hkVector4q m_3020;
    float m_3030;
    int unk3034;
    int unk3038;
    int unk303C;
    struct Info
    {
        unsigned short m_3040;
        unsigned short m_3042;
        unsigned short m_3044;
        unsigned short unk3046;
        unsigned char m_3048;
        unsigned char m_3049;
        NibblePair m_304a;
        unsigned char unk304b;
    } m_info;
};

extern hkVector4q DAT_010c4c00;

class ParticleSystemOps
{
  public:
    void hkpSphereTriangleAgent_processCollision(int a, int b, int c, ParticleSystemState* state);
    void hkpSymmetricAgentLinearCast_hkpSphereTriangleAgent_processCollision(int a1, int a2, int a3, ParticleSystemState* s);
};

// After FUN_00d3dd90, adds each new particle's w-scaled velocity to its first vector and flips its sign; if m_3030 changed, swaps several info fields.
// @fnv 0x00d3e150
// src: XBOX_PDB 0x00d3e150
void ParticleSystemOps::hkpSymmetricAgentLinearCast_hkpSphereTriangleAgent_processCollision(int a1, int a2, int a3, ParticleSystemState* s)
{
    float x;
    x = s->m_3030;
    SpawnedParticle* t;
    t = s->m_kRayEnd;
    this->hkpSphereTriangleAgent_processCollision(a2, a1, a3, s);
    for (; t < s->m_kRayEnd; t++)
    {
        hkVector4q pObj;
        pObj.setBroadcast3(t->m_fVelocity);
        t->m_vContactPosition.addMul4(pObj, t->m_fVelocity);
        t->m_fVelocity.setXor4(t->m_fVelocity, DAT_010c4c00);
    }
    if (x != s->m_3030)
    {
        hkVector4q* v3020;
        v3020 = &s->m_3020;
        v3020->xor4(DAT_010c4c00);
        ParticleSystemState::Info* p;
        p = &s->m_info;
        char val;
        val = p->m_304a.lo;
        p->m_304a.lo = p->m_304a.hi;
        p->m_304a.hi = val;
        unsigned char* bytes;
        bytes = (unsigned char*)&p->m_3048;
        unsigned char res;
        res = bytes[0];
        unsigned char j;
        j = p->m_3049;
        bytes[1] = res;
        unsigned int uiIndex;
        uiIndex = (unsigned int)j + (unsigned int)res - 1;
        bytes[0] = j;
        unsigned short* z;
        z = &p->m_3040;
        unsigned int a;
        a = z[0];
        z[0] = z[uiIndex];
        z[uiIndex] = a;
        unsigned char* last;
        last = (unsigned char*)&p->m_3049;
        if ((last[-1] & last[0]) == 2)
        {
            hkSwap(p->m_3042, p->m_3044);
        }
    }
}

typedef unsigned long DWORD;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(DWORD);

extern "C"
{
    unsigned __int64 __rdtsc();
    void _ReadWriteBarrier();
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_unpacklo_ps(LocalM128, LocalM128);
    LocalM128 _mm_unpackhi_ps(LocalM128, LocalM128);
    LocalM128 _mm_movelh_ps(LocalM128, LocalM128);
    LocalM128 _mm_movehl_ps(LocalM128, LocalM128);
    void _mm_store_ps(float*, LocalM128);
}

extern "C" DWORD DAT_0126835c;

struct Res
{
    hkVector4q pt;
    float d;
};

struct Arg3S
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float f10;
};



struct XForm
{
    LocalM128 r0;
    LocalM128 r1;
    LocalM128 r2;
    LocalM128 t;
};

struct BodyB
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};

struct BodyHolderB
{
    BodyB* obj;
    int unk04;
    XForm* xf;
};

struct Sink
{
    virtual void unk00();
    virtual void unk04(BodyHolderB& a, BodyHolderB& b);
};

extern void __cdecl hkpCollideTriangleUtil_closestPointTriangle(hkVector4q* v, void* tri, float* f, Res* out, void* flag);

// non-POD 1-dword wrapper params: block the entry-enregister pass so the
// params are read lazily from their incoming arg slots (see e2fbc0)
struct BHWrap
{
    BodyHolderB* p;
    BHWrap(BodyHolderB* q) : p(q)
    {}
};

struct SinkWrap
{
    Sink* p;
    SinkWrap(Sink* q) : p(q)
    {}
};

class SphereTriAgent
{
  public:
    int unk00, unk04, unk08, unk0C;
    float unk10;
    void hkpSphereTriangleAgent_getPenetrations(BodyHolderB* a, BodyHolderB* b, int c_, Sink* sink);
};

// Tests sphere-triangle collision between two bodies and calls the sink if the distance is within the combined radii.
// @fnv 0x00d3d2a0
// src: HAVOK_SRC 0x00d3d2a0
void SphereTriAgent::hkpSphereTriangleAgent_getPenetrations(BodyHolderB* apBodyA, BodyHolderB* apBodyB, int aiUnused, Sink* sink)
{
    volatile unsigned int lo;
    {
        hkMonitorStream* pProfBuf = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
        hkMonitorStream::TimerCommand* pProfRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pProfBuf->m_end.m_storage);
        if (reinterpret_cast<char*>(pProfRec) < pProfBuf->m_capacityMinus16.m_storage)
        {
            pProfRec->m_commandAndMonitor = "TtSphereTri";
            _ReadWriteBarrier();
            lo = (unsigned int)__rdtsc();
            pProfRec->m_time0 = lo;
            pProfBuf->m_end.m_storage = reinterpret_cast<char*>(pProfRec + 1);
        }
    }
    BodyB* shapeA = apBodyA->obj;
    LocalM128 vTransA = apBodyA->xf->t;
    BodyB* shapeB = apBodyB->obj;
    XForm* pXFormB = apBodyB->xf;
    LocalM128 d = _mm_sub_ps(vTransA, pXFormB->t);
    LocalM128 r0 = pXFormB->r0, r1 = pXFormB->r1, r2 = pXFormB->r2;
    LocalM128 tmpLo = _mm_unpacklo_ps(r0, r1);
    LocalM128 tmpThird = _mm_shuffle_ps(_mm_unpackhi_ps(r0, r1), r2, 0xe4);
    r0 = _mm_movelh_ps(tmpLo, r2);
    r1 = _mm_shuffle_ps(_mm_movehl_ps(r0, tmpLo), r2, 0xd4);
    r2 = tmpThird;
    LocalM128 p0 = _mm_mul_ps(r0, _mm_shuffle_ps(d, d, 0));
    LocalM128 p1 = _mm_mul_ps(r1, _mm_shuffle_ps(d, d, 0x55));
    LocalM128 p2 = _mm_mul_ps(r2, _mm_shuffle_ps(d, d, 0xaa));
    LocalM128 v = _mm_add_ps(_mm_add_ps(p0, p1), p2);
    hkVector4q vv;
    _mm_store_ps(&vv.m_vComponents.m128_f32[0], v);
    Res out;
    hkpCollideTriangleUtil_closestPointTriangle(&vv, &shapeB->unk20, &unk10, &out, 0);
    float dist = shapeB->unk10 + shapeA->unk10;
    if (out.d < dist)
    {
        sink->unk04(*apBodyA, *apBodyB);
    }
    {
        hkMonitorStream* pProfBuf = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
        hkMonitorStream::TimerCommand* pProfRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pProfBuf->m_end.m_storage);
        if (reinterpret_cast<char*>(pProfRec) < pProfBuf->m_capacityMinus16.m_storage)
        {
            pProfRec->m_commandAndMonitor = "Et";
            _ReadWriteBarrier();
            lo = (unsigned int)__rdtsc();
            pProfRec->m_time0 = lo;
            pProfBuf->m_end.m_storage = reinterpret_cast<char*>(pProfRec + 1);
        }
    }
}

// rotate the translation difference by the inverse of B's rotation (HK_TRANSPOSE3), compute the
// closest point, and report a contact when the distance is below the summed radii.

extern DWORD DAT_0126835c;
extern char DAT_010cf0d4[];  // "TtSphereTri"
extern char DAT_010c41f8[];  // "Et"

struct S_00d3d3e0_Mat
{
    hkVector4q r0, r1, r2, t;
};
struct S_00d3d3e0_Shape
{
    int unk00, unk04, unk08, unk0c;
    float f10;
};
struct S_00d3d3e0_Obj
{
    int unk00, unk04, unk08, unk0c;
    float f10;
    int unk14, unk18, unk1c;
    int unk20;
};
struct S_00d3d3e0_P1
{
    S_00d3d3e0_Shape* shape;
    int unk04;
    S_00d3d3e0_Mat* mat;
};
struct S_00d3d3e0_P2
{
    S_00d3d3e0_Obj* obj;
    int unk04;
    S_00d3d3e0_Mat* mat;
};
struct S_00d3d3e0_P3
{
    virtual void v0();
    virtual void v1(S_00d3d3e0_P1* a, S_00d3d3e0_P2* b);
};
struct __declspec(align(16)) S_00d3d3e0_Out
{
    int unk00, unk04, unk08, unk0c;
    float f10;
};

void __cdecl hkpCollideTriangleUtil_setupClosestPointTriangleCache(void* a, hkVector4q* out);
void __cdecl hkpCollideTriangleUtil_closestPointTriangle(hkVector4q* a, void* b, hkVector4q* c, S_00d3d3e0_Out* d, bool* e);

struct S_00d3d3e0_P1P
{
    S_00d3d3e0_P1* p;
    S_00d3d3e0_P1* val() const
    {
        return p;
    }
};
struct S_00d3d3e0_P2P
{
    S_00d3d3e0_P2* p;
    S_00d3d3e0_P2* val() const
    {
        return p;
    }
};
struct S_00d3d3e0_P3P
{
    S_00d3d3e0_P3* p;
    S_00d3d3e0_P3* val() const
    {
        return p;
    }
};

// @fnv 0x00d3d3e0
// src: XBOX_PDB 0x00d3d3e0
void hkpSphereTriangleAgent_staticGetPenetrations(S_00d3d3e0_P1P a1, S_00d3d3e0_P2P a2, int unused, S_00d3d3e0_P3P a3)
{
    hkMonitorStream* h = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    if (h->m_end.m_storage < h->m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* e = reinterpret_cast<hkMonitorStream::TimerCommand*>(h->m_end.m_storage);
        e->m_commandAndMonitor = DAT_010cf0d4;
        _ReadWriteBarrier();
        volatile unsigned t = (unsigned)__rdtsc();
        e->m_time0 = t;
        h->m_end.m_storage = reinterpret_cast<char*>(e + 1);
    }
    S_00d3d3e0_P1* p1 = a1.val();
    S_00d3d3e0_Shape* shape = p1->shape;
    S_00d3d3e0_Obj* obj = a2.val()->obj;
    hkVector4q q;
    hkpCollideTriangleUtil_setupClosestPointTriangleCache(&obj->unk20, &q);
    S_00d3d3e0_Mat* m2 = a2.val()->mat;
    S_00d3d3e0_Mat* m1 = p1->mat;
    LocalM128 d = _mm_sub_ps(*(LocalM128*)&m1->t, *(LocalM128*)&m2->t);
    LocalM128 c0 = *(LocalM128*)&m2->r0;
    LocalM128 c1 = *(LocalM128*)&m2->r1;
    LocalM128 c2 = *(LocalM128*)&m2->r2;
    {
        LocalM128 tmp0 = _mm_unpacklo_ps(c0, c1);
        LocalM128 tmp1 = _mm_unpackhi_ps(c0, c1);
        c0 = _mm_movelh_ps(tmp0, c2);
        c1 = _mm_shuffle_ps(_mm_movehl_ps(c0, tmp0), c2, 0xd4);
        c2 = _mm_shuffle_ps(tmp1, c2, 0xe4);
    }
    const LocalM128 b0 = _mm_shuffle_ps(d, d, 0x00);
    const LocalM128 t0 = _mm_mul_ps(c0, b0);
    const LocalM128 b1 = _mm_shuffle_ps(d, d, 0x55);
    const LocalM128 t1 = _mm_mul_ps(c1, b1);
    const LocalM128 b2 = _mm_shuffle_ps(d, d, 0xaa);
    const LocalM128 t2 = _mm_mul_ps(c2, b2);
    hkVector4q v;
    *(LocalM128*)&v = _mm_add_ps(_mm_add_ps(t0, t1), t2);
    S_00d3d3e0_Out out;
    hkpCollideTriangleUtil_closestPointTriangle(&v, &obj->unk20, &q, &out, 0);
    float sum = shape->f10 + obj->f10;
    if (out.f10 < sum)
        a3.val()->v1(p1, a2.val());
    h = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    if (h->m_end.m_storage < h->m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* e = reinterpret_cast<hkMonitorStream::TimerCommand*>(h->m_end.m_storage);
        e->m_commandAndMonitor = DAT_010c41f8;
        _ReadWriteBarrier();
        volatile unsigned t = (unsigned)__rdtsc();
        e->m_time0 = t;
        h->m_end.m_storage = reinterpret_cast<char*>(e + 1);
    }
}

namespace fnv_00d3e0d0 {
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
    void hkpSphereTriangleAgent_getClosestPoints(void*, void*, unsigned int, CpuCallData*);
    void hkpSymmetricAgentLinearCast_hkpSphereTriangleAgent_getClosestPoints(void*, void*, unsigned int, unsigned int);
};
// Fills a CpuCallData with fourth, DAT_0104da48 and &DAT_010ce7fc, then calls FUN_00d3d6b0 with second, first, third and the data pointer.
// @fnv 0x00d3e0d0
// src: XBOX_PDB 0x00d3e0d0
void CpuObject::hkpSymmetricAgentLinearCast_hkpSphereTriangleAgent_getClosestPoints(void* first, void* second, unsigned int third, unsigned int uiValue)
{
    CpuCallData data;
    data.value = uiValue;
    data.bound = DAT_0104da48;
    data.descriptor = &DAT_010ce7fc;
    hkpSphereTriangleAgent_getClosestPoints(second, first, third, &data);
}
}  // namespace fnv_00d3e0d0
