
// src/havok/physics/collide/agent/convexagent/spherecapsule/hkpspherecapsuleagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/spherecapsule/hkpspherecapsuleagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkMemoryRouter.h"

struct S_00d3ef70_CdBody;
struct S_00d3ef70_Input;
struct S_00d3ef70_Agent;
struct S_00d3ef70_Collector;

typedef S_00d3ef70_Agent* (*S_00d3ef70_CreateFunc)(const S_00d3ef70_CdBody&, const S_00d3ef70_CdBody&, const S_00d3ef70_Input&, void*);
typedef void (*S_00d3ef70_GetPenetrationsFunc)(const S_00d3ef70_CdBody&, const S_00d3ef70_CdBody&, const S_00d3ef70_Input&, S_00d3ef70_Collector&);
typedef void (*S_00d3ef70_GetClosestPointsFunc)(const S_00d3ef70_CdBody&, const S_00d3ef70_CdBody&, const S_00d3ef70_Input&, S_00d3ef70_Collector&);
typedef void (*S_00d3ef70_LinearCastFunc)(const S_00d3ef70_CdBody&, const S_00d3ef70_CdBody&, const S_00d3ef70_Input&, S_00d3ef70_Collector&, S_00d3ef70_Collector*);

struct S_00d3ef70_AgentFuncs {
    S_00d3ef70_CreateFunc m_pCreateFunc;
    S_00d3ef70_GetPenetrationsFunc m_pQueryPenetrationsFunc;
    S_00d3ef70_GetClosestPointsFunc m_getClosestPointsFunc;
    S_00d3ef70_LinearCastFunc m_pLinearCastFunc;
    bool m_bIsFlipped;
    bool m_bIsPredictive;
};

struct S_00d3ef70_Dispatcher {
    void registerCollisionAgent(S_00d3ef70_AgentFuncs& f, int typeA, int typeB);
};

S_00d3ef70_Agent* hkpSphereCapsuleAgent_createCapsuleSphereAgent(const S_00d3ef70_CdBody&, const S_00d3ef70_CdBody&, const S_00d3ef70_Input&, void*);
void Object_UpdateFields_00d3f040(const S_00d3ef70_CdBody&, const S_00d3ef70_CdBody&, const S_00d3ef70_Input&, S_00d3ef70_Collector&);
void Object_ProcessAndReturnValue_00d3f4c0(const S_00d3ef70_CdBody&, const S_00d3ef70_CdBody&, const S_00d3ef70_Input&, S_00d3ef70_Collector&);
void Object_UpdateFields_00d3ac80(const S_00d3ef70_CdBody&, const S_00d3ef70_CdBody&, const S_00d3ef70_Input&, S_00d3ef70_Collector&, S_00d3ef70_Collector*);
S_00d3ef70_Agent* hkMemoryRouter_getInstance_AllocateAndInitializeObject16(const S_00d3ef70_CdBody&, const S_00d3ef70_CdBody&, const S_00d3ef70_Input&, void*);
void hkpSphereCapsuleAgent_staticGetPenetrations(const S_00d3ef70_CdBody&, const S_00d3ef70_CdBody&, const S_00d3ef70_Input&, S_00d3ef70_Collector&);
void FUN_00d3ebe0(const S_00d3ef70_CdBody&, const S_00d3ef70_CdBody&, const S_00d3ef70_Input&, S_00d3ef70_Collector&);
void Object_ProcessEntries_00daf8e0(const S_00d3ef70_CdBody&, const S_00d3ef70_CdBody&, const S_00d3ef70_Input&, S_00d3ef70_Collector&, S_00d3ef70_Collector*);

// Registers two collision agent function tables with the dispatcher for the type pairs (5,1) and (1,5).
// @fnv 0x00d3ef70
// src: HAVOK_LIB 0x00d3ef70
void hkpSphereCapsuleAgent_registerAgent(S_00d3ef70_Dispatcher* dispatcher)
{
    {
        S_00d3ef70_AgentFuncs agentFuncs;
        agentFuncs.m_pCreateFunc = hkpSphereCapsuleAgent_createCapsuleSphereAgent;
        agentFuncs.m_pQueryPenetrationsFunc = Object_UpdateFields_00d3f040;
        agentFuncs.m_getClosestPointsFunc = Object_ProcessAndReturnValue_00d3f4c0;
        agentFuncs.m_pLinearCastFunc = Object_UpdateFields_00d3ac80;
        agentFuncs.m_bIsFlipped = true;
        agentFuncs.m_bIsPredictive = false;
        dispatcher->registerCollisionAgent(agentFuncs, 5, 1);
    }
    {
        S_00d3ef70_AgentFuncs agentFuncs;
        agentFuncs.m_pCreateFunc = hkMemoryRouter_getInstance_AllocateAndInitializeObject16;
        agentFuncs.m_pQueryPenetrationsFunc = hkpSphereCapsuleAgent_staticGetPenetrations;
        agentFuncs.m_getClosestPointsFunc = FUN_00d3ebe0;
        agentFuncs.m_pLinearCastFunc = Object_ProcessEntries_00daf8e0;
        agentFuncs.m_bIsFlipped = false;
        agentFuncs.m_bIsPredictive = false;
        dispatcher->registerCollisionAgent(agentFuncs, 1, 5);
    }
}

class InnerCls {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(unsigned short a, int b);
};

inline void InnerCls::v0() {}
inline void InnerCls::v1() {}
inline void InnerCls::v2() {}
inline void InnerCls::v3() {}
inline void InnerCls::v4() {}
inline void InnerCls::v5(unsigned short a, int b) { a; b; }

class FUN_00d3e2b0_cls {
public:
    virtual void v0(int a);
    int m_i04;
    InnerCls *m_pInner;
    unsigned short m_w0c;
    void hkpSphereCapsuleAgent_cleanup(int a1);
};

// @fnv 0x00d3e2b0
inline void FUN_00d3e2b0_cls::v0(int aiValue) { aiValue; }

// src: HAVOK_SRC 0x00d3e2b0
void FUN_00d3e2b0_cls::hkpSphereCapsuleAgent_cleanup(int a1)
{
    if (m_w0c != 0xffff) {
        m_pInner->v5(m_w0c, a1);
    }
    v0(1);
}

struct ObjAllocator {
    virtual void unk00();
    virtual void* Alloc(unsigned int size);
};

struct SmallRecord {
    void* m_vptr;
    unsigned short m_w04;
    unsigned short m_w06;
    int m_i08;
    unsigned short m_w0C;
};

extern char DAT_010cf018[];

hkMemoryRouter* hkMemoryRouter_getInstance();

// @fnv 0x00d3e2f0
// src: XBOX_PDB 0x00d3e2f0
void __cdecl hkpSphereCapsuleAgent_createCapsuleSphereAgent(int aiUnused1, int aiUnused2, int aiUnused3, int aiValue) {
    hkMemoryRouter* pAllocHolder = hkMemoryRouter_getInstance();
    ObjAllocator* allocator = (ObjAllocator*)pAllocHolder->m_heap;
    SmallRecord* pRecord = (SmallRecord*)allocator->Alloc(0x10);
    pRecord->m_w04 = 0x10;
    pRecord->m_w06 = 1;
    pRecord->m_i08 = aiValue;
    pRecord->m_w0C = 0xffff;
    pRecord->m_vptr = DAT_010cf018;
}

void __cdecl hkpSphereCapsuleAgent_staticGetPenetrations(int a, int b, int c, int d);

// @fnv 0x00d3e510
// src: HAVOK_SRC 0x00d3e510
void __stdcall hkpSphereCapsuleAgent_getPenetrations(int a, int b, int c, int d)
{
    hkpSphereCapsuleAgent_staticGetPenetrations(a, b, c, d);
}

extern char DAT_010ce81c;

struct FUN_00d3f040_tmp {
    const char* str;
    unsigned char flag;
    unsigned int value;
};

void __cdecl hkpSphereCapsuleAgent_staticGetPenetrations(unsigned int a, unsigned int b, unsigned int c, FUN_00d3f040_tmp* p);

// Builds a FUN_00d3f040_tmp with value a3, flag 0 and str pointing at DAT_010ce81c, then calls FUN_00d3e330(a1, a0, a2, &t).
// @fnv 0x00d3f040
// src: GUESS 0x00d3f040 (confidence: low)
void __cdecl Object_UpdateFields_00d3f040(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int uiValue)
{
    FUN_00d3f040_tmp t;
    t.value = uiValue;
    t.flag = 0;
    t.str = &DAT_010ce81c;
    hkpSphereCapsuleAgent_staticGetPenetrations(a1, a0, a2, &t);
}

extern char DAT_010ce81c;
struct AgentDispatchDescriptor {
    const void* dispatchTable;
    unsigned char isFlipped;
    volatile unsigned int tag;
};
struct CollisionDispatcher {
    void hkpSphereCapsuleAgent_getPenetrations(void* bodyB, void* bodyA, void* input, AgentDispatchDescriptor* descriptor);
    void hkpSymmetricAgentLinearCast_hkpSphereCapsuleAgent_getPenetrations(void* bodyA, void* bodyB, void* volatile input, unsigned int tag);
};
// Builds an AgentDispatchDescriptor with the given tag and a fixed dispatch table, then calls FUN_00d3e510 with the bodies swapped.
// @fnv 0x00d3f000
// src: XBOX_PDB 0x00d3f000
void CollisionDispatcher::hkpSymmetricAgentLinearCast_hkpSphereCapsuleAgent_getPenetrations(void* bodyA, void* bodyB, void* volatile input, unsigned int tag)
{
    AgentDispatchDescriptor descriptor;
    descriptor.tag = tag;
    descriptor.isFlipped = false;
    descriptor.dispatchTable = &DAT_010ce81c;
    hkpSphereCapsuleAgent_getPenetrations(bodyB, bodyA, input, &descriptor);
}

// Exe 0x00d3e330 FUN_00d3e330: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C" LocalM128 _mm_load_ps(const float*);
extern "C" LocalM128 _mm_mul_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_add_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_sub_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_add_ss(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128 a, LocalM128 b, unsigned int imm);
extern "C" void _mm_store_ss(float* p, LocalM128 a);

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);

extern unsigned long DAT_0126835c;
extern const char str_010cf158[];
extern const char str_010c41f8[];

struct SphCap_Mon {
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_cap;
    char* m_capMinus16;
};

struct SphCap_Timer {
    const char* m_name;
    unsigned int m_ticks;
    unsigned int m_unk08;
};

struct SphCap_Vector4 {
    LocalM128 m_vComponents;
};

struct SphCap_Transform {
    SphCap_Vector4 m_kColumn0;
    SphCap_Vector4 m_kColumn1;
    SphCap_Vector4 m_kColumn2;
    SphCap_Vector4 m_vTranslation;
};

struct __declspec(align(16)) SphCap_Vector4F {
    float x;
    float y;
    float z;
    float w;
};

struct SphCap_TransformF {
    SphCap_Vector4F c0;
    SphCap_Vector4F c1;
    SphCap_Vector4F c2;
    SphCap_Vector4F c3;
};

struct SphCap_SegResult {
    SphCap_Vector4 m_kClosestPoint;
};

struct SphCap_Frame {
    SphCap_SegResult closest;
    SphCap_Vector4F t0;
    SphCap_Vector4F t1;
    SphCap_Vector4F t2;
    SphCap_Vector4F t3;
    SphCap_Vector4 points[2];
};

struct SphCap_Shape {
    void* m_vtbl;
    int m_unk04;
    int m_unk08;
    int m_unk0C;
    float m_fSphereRadius;
    int m_unk14;
    int m_unk18;
    int m_unk1C;
    SphCap_Vector4 m_kVertexA;
    SphCap_Vector4 m_kVertexB;
};

struct S_00d3ef70_CdBody {
    const SphCap_Shape* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const SphCap_Transform* m_pMotionState;
};

struct S_00d3ef70_Collector {
    virtual void slot00();
    virtual void AddCdBodyPair(const S_00d3ef70_CdBody& a, const S_00d3ef70_CdBody& b);
};

int __cdecl hkLineSegmentUtil_closestPointLineSeg(const SphCap_Vector4& pos, const SphCap_Vector4& a, const SphCap_Vector4& b, SphCap_SegResult& out);

struct Group1 {
    SphCap_Vector4F t0;
    SphCap_Vector4F t1;
};
struct Group2 {
    SphCap_Vector4F t2;
    SphCap_Vector4F t3;
};

// @fnv 0x00d3e330
// src: XBOX_PDB 0x00d3e330
void hkpSphereCapsuleAgent_staticGetPenetrations(const S_00d3ef70_CdBody& bodyA, const S_00d3ef70_CdBody& bodyB, const S_00d3ef70_Input& input, S_00d3ef70_Collector& collector)
{
    {
        SphCap_Mon* mon = (SphCap_Mon*)TlsGetValue(DAT_0126835c);
        char* pos = mon->m_kRayEnd;
        if (pos < mon->m_capMinus16) {
            volatile unsigned int ticks;
            SphCap_Timer* t = (SphCap_Timer*)pos;
            t->m_name = str_010cf158;
            { unsigned int ticks;
__asm {
    rdtsc
    mov dword ptr[ticks], eax
}
t->m_ticks = ticks; }
            mon->m_kRayEnd = pos + sizeof(SphCap_Timer);
        }
    }

    SphCap_SegResult local_closest;
    Group1 group1;
    Group2 group2;
    SphCap_Vector4 local_points[2];

    SphCap_SegResult& closest = local_closest;
    const SphCap_Shape* sphere = bodyA.m_pCollisionShape;
    const SphCap_Vector4& spherePos = bodyA.m_pMotionState->m_vTranslation;
    const SphCap_Shape* capsule = bodyB.m_pCollisionShape;

    SphCap_Vector4 (&points)[2] = local_points;
    {
        const SphCap_Transform& tin = *bodyB.m_pMotionState;
        group1.t0 = *(const SphCap_Vector4F*)&tin.m_kColumn0;
        group1.t1 = *(const SphCap_Vector4F*)&tin.m_kColumn1;
        group2.t2 = *(const SphCap_Vector4F*)&tin.m_kColumn2;
        group2.t3 = *(const SphCap_Vector4F*)&tin.m_vTranslation;
        LocalM128 c0 = _mm_load_ps((const float*)&group1.t0);
        LocalM128 c1 = _mm_load_ps((const float*)&group1.t1);
        LocalM128 c2 = _mm_load_ps((const float*)&group2.t2);
        LocalM128 c3 = _mm_load_ps((const float*)&group2.t3);
        const SphCap_Vector4* in = &capsule->m_kVertexA;
        for (int i = 1; i >= 0; i--) {
            LocalM128 v = in[i].m_vComponents;
            LocalM128 b = _mm_shuffle_ps(v, v, 0x55);
            LocalM128 a = _mm_shuffle_ps(v, v, 0);
            LocalM128 c = _mm_shuffle_ps(v, v, 0xaa);
            points[i].m_vComponents = _mm_add_ps(_mm_add_ps(_mm_mul_ps(b, c1), _mm_mul_ps(a, c0)), _mm_add_ps(_mm_mul_ps(c, c2), c3));
        }
    }

    {
        hkLineSegmentUtil_closestPointLineSeg(spherePos, points[0], points[1], closest);

        float radiusSum = capsule->m_fSphereRadius + sphere->m_fSphereRadius;
        LocalM128 d = _mm_sub_ps(closest.m_kClosestPoint.m_vComponents, spherePos.m_vComponents);
        d = _mm_mul_ps(d, d);
        LocalM128 s = _mm_add_ss(_mm_shuffle_ps(d, d, 0x55), d);
        s = _mm_add_ss(_mm_shuffle_ps(d, d, 0xaa), s);
        float rr = radiusSum * radiusSum;
        float distSq;
        _mm_store_ss(&distSq, s);
        if (distSq < rr)
            collector.AddCdBodyPair(bodyA, bodyB);
    }

    {
        SphCap_Mon* mon = (SphCap_Mon*)TlsGetValue(DAT_0126835c);
        char* pos = mon->m_kRayEnd;
        if (pos < mon->m_capMinus16) {
            volatile unsigned int ticks;
            SphCap_Timer* t = (SphCap_Timer*)pos;
            t->m_name = str_010c41f8;
            { unsigned int ticks;
__asm {
    rdtsc
    mov dword ptr[ticks], eax
}
t->m_ticks = ticks; }
            mon->m_kRayEnd = pos + sizeof(SphCap_Timer);
        }
    }
}
