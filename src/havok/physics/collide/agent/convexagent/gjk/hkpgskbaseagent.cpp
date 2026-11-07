
// src/havok/physics/collide/agent/convexagent/gjk/hkpgskbaseagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/gjk/hkpgskbaseagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Keep the original floating-point-only intrinsic type: the CRT union's byte
// arrays change this compiler's stack protection and alias analysis.
#define _INCLUDED_MM2
// Exe 0x00dabeb0 RemovePoint: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
} __m128, LocalM128;
extern "C" LocalM128 _mm_load_ss(const float*);
extern "C" LocalM128 _mm_add_ss(LocalM128, LocalM128);
extern "C" void _mm_store_ss(float*, LocalM128);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);

#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkContactPoint.h"
#include "../../../../../../../include/hkTransform.h"
#include "../../../../../../../include/hkpCdBody.h"
#include "../../../../../../../include/hkpCdPointCollector.h"
#include "../../../../../../../include/hkpCdBodyPairCollector.h"
#include "../../../../../../../include/hkpGskBaseAgent.h"
#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/hkMatrix3.h"
#include "../../../../../../../include/hkpConvexShape.h"

// These empty/value operations were inline in this unit's original definitions.
inline hkTransform::hkTransform() {}

inline hkpShapeType hkpShape::getType() const
{
    return *(const hkpShapeType*)&m_type;
}

// This virtual deleting thunk is absent from the shared method declarations.
// Keep its calling convention and dispatch without duplicating the agent class.
// @fnv 0x00dabe90
// src: HAVOK_LIB 0x00dabe90
void __fastcall hkpGskBaseAgent_cleanup(hkpGskBaseAgent* agent, void*, bool)
{
    if (agent)
    {
        typedef void (__thiscall* DeleteAgent)(hkpGskBaseAgent*, bool);
        (*(DeleteAgent**)agent)[0](agent, true);
    }
}

extern "C" LocalM128 _mm_setzero_ps(void);
extern "C" LocalM128 _mm_xor_ps(LocalM128, LocalM128);

extern float DAT_01012054;

// @fnv 0x00dabeb0
void hkpGskBaseAgent::RemovePoint(const CollisionAgentContext&)
{
    m_fFloatValue = DAT_01012054;
    m_vSeparatingNormal.m_vComponents = _mm_setzero_ps();
}

// Updates the cached time when it matches expected; otherwise invalidates it and clears the separating normal.
// @fnv 0x00dabed0
void hkpGskBaseAgent::WarpTime(hkTime expected, hkTime value, const CollisionAgentContext&)
{
    if (m_fFloatValue == expected)
    {
        m_fFloatValue = value;
    }
    else
    {
        m_fFloatValue = DAT_01012054;
        m_vSeparatingNormal.m_vComponents = _mm_setzero_ps();
    }
}

extern unsigned int DAT_0126835c;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);

struct CollisionAgentContext
{
    void* m_pCollisionDispatcher;
    float m_weldTolerance;
    float m_fScalar;
};

struct GskInput
{
    const hkTransform* m_kTransform;
    const void* m_pTransformB;
    const void* m_pShapeA;
    const void* m_pShapeB;
    float m_fScalar;
};

struct GskOutput
{
    LocalM128 m_pos;
    LocalM128 m_vHitNormal;
};

struct ContactPointPair
{
    hkContactPoint m_kPoint;
    const hkpCdBody* m_pBodyA;
    const hkpCdBody* m_pBodyB;
};

int hkpGsk_getClosestPoint(const GskInput* input, void* status, LocalM128* out1, LocalM128* out2);

// @fnv 0x00dac9e0
void hkpGskBaseAgent::getClosestPoints(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const CollisionAgentContext& input,
                                      hkpCdPointCollector& collector)
{
    hkMonitorStream* pProfilerBuffer = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    char* pWriteCursor = pProfilerBuffer->m_end.m_storage;
    if (pWriteCursor < pProfilerBuffer->m_capacityMinus16.val())
    {
        *(const char**)pWriteCursor = "TtGsk";
        _ReadWriteBarrier();
        volatile unsigned int uiTimestamp = (unsigned int)__rdtsc();
        *(unsigned int*)(pWriteCursor + 4) = uiTimestamp;
        pWriteCursor += 12;
        pProfilerBuffer->m_end.m_storage = pWriteCursor;
    }

    hkTransform aTb;
    aTb.hkTransform_setMulInverseMul(bodyA.m_pMotionState, bodyB.m_pMotionState);

    GskInput queryInput;
    queryInput.m_pShapeA = bodyA.m_pCollisionShape;
    queryInput.m_pShapeB = bodyB.m_pCollisionShape;
    queryInput.m_kTransform = &aTb;
    queryInput.m_pTransformB = bodyA.m_pMotionState;
    queryInput.m_fScalar = input.m_fScalar;

    GskOutput out;
    if (hkpGsk_getClosestPoint(&queryInput, m_pAccess, &out.m_vHitNormal, &out.m_pos) == 0)
    {
        // The temporary is filled below; avoid the approved hkVector4's
        // out-of-line default constructor for this raw solver result.
        LocalM128 pointStorage[sizeof(ContactPointPair) / sizeof(LocalM128)];
        ContactPointPair& point = *(ContactPointPair*)pointStorage;
        point.m_kPoint.m_vContactPosition.m_vComponents = out.m_pos;
        point.m_pBodyA = &bodyA;
        point.m_pBodyB = &bodyB;
        point.m_kPoint.m_vSeparatingNormal.m_vComponents = out.m_vHitNormal;
        collector.AddCdPoint(point);
    }

    pProfilerBuffer = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    pWriteCursor = pProfilerBuffer->m_end.m_storage;
    if (pWriteCursor < pProfilerBuffer->m_capacityMinus16.val())
    {
        *(const char**)pWriteCursor = "Et";
        _ReadWriteBarrier();
        volatile unsigned int uiTimestamp = (unsigned int)__rdtsc();
        *(unsigned int*)(pWriteCursor + 4) = uiTimestamp;
        pWriteCursor += 12;
        pProfilerBuffer->m_end.m_storage = pWriteCursor;
    }
}

// @fnv 0x00dabe80
void hkpGskBaseAgent::ProcessContactPoints(const hkpCdBody&, const hkpCdBody&, const CollisionAgentContext&, hkpConstraintOwner&)
{}

extern "C" LocalM128 _mm_shuffle_ps(LocalM128 a, LocalM128 b, unsigned int imm);
extern "C" LocalM128 _mm_mul_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_add_ps(LocalM128 a, LocalM128 b);

__forceinline void hkVector4::_setMul3(const hkMatrix3& r, const hkVector4& b)
{
    const LocalM128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    const LocalM128 r0 = _mm_mul_ps(b0, r.m_kColumn0.m_vComponents);
    const LocalM128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    const LocalM128 r1 = _mm_mul_ps(b1, r.m_kColumn1.m_vComponents);
    const LocalM128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    const LocalM128 r2 = _mm_mul_ps(b2, r.m_kColumn2.m_vComponents);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}

struct FUN_00daad40_solver
{
    void hkpGsk_getClosestFeature(const hkpConvexShape* pkShapeA, const hkpConvexShape* pkShapeB,
                      const hkTransform& kAtB, hkVector4& kPointOut);
};

// Builds kAtB, calls the solver, rotates its result by body A's rotation into kSeparatingNormal, and sets w to the solver's w minus both sphere radii.
// @fnv 0x00dac020
void __cdecl hkpGskBaseAgent::ComputeClosestPoint(const hkpCdBody& kBodyA, const hkpCdBody& kBodyB, hkReal earlyOutTolerance,
                                               ConvexShapePairCache& gsk, hkVector4& separatingNormalOut)
{
    const hkpConvexShape* pkShapeA = (const hkpConvexShape*)kBodyA.m_pCollisionShape;
    const hkpConvexShape* pkShapeB = (const hkpConvexShape*)kBodyB.m_pCollisionShape;

    hkTransform kAtB;
    kAtB.hkTransform_setMulInverseMul(*(const hkTransform*)kBodyA.m_pMotionState, *(const hkTransform*)kBodyB.m_pMotionState);

    hkVector4 kNormal;
    ((FUN_00daad40_solver*)&gsk)->hkpGsk_getClosestFeature(pkShapeA, pkShapeB, kAtB, kNormal);

    separatingNormalOut._setMul3(*(const hkMatrix3*)kBodyA.m_pMotionState, kNormal);
    separatingNormalOut.w = kNormal.w - pkShapeA->m_fSphereRadius - pkShapeB->m_fSphereRadius;
}

extern char g_gskBaseAgentVtbl;

struct GskNode;

__declspec(align(16)) struct GskTmp
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    void Setup(int a, int b);
};

struct GskSub
{
    int m_00;
    int m_04;
    int m_08;
    void Init(GskNode* a, GskNode* b, GskTmp* t);
    void Init2(GskNode* a, GskNode* b, GskTmp* t);
};

struct GskNode
{
    GskNode* m_00;
    int unk04;
    int m_08;
    GskNode* m_0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    float m_4c;
};

// The shared iterative base has no constructor forwarding the contact manager.
// Keep this initializer outside the class while using its shared layout.
// Initializes the feature cache and stores the smaller root-body radius.
// @fnv 0x00dabf10
hkpGskBaseAgent* __fastcall ConstructGskBaseAgent(hkpGskBaseAgent* agent, void*, const hkpCdBody& bodyA, const hkpCdBody& bodyB, hkpContactMgr* mgr)
{
    agent->m_sReferenceCount = 1;
    agent->m_pContactManager = mgr;
    *(void**)agent = &g_gskBaseAgentVtbl;

    const GskNode* apNodeA = (const GskNode*)&bodyA;
    const GskNode* apNodeB = (const GskNode*)&bodyB;

    GskNode* ebx = apNodeB->m_00;
    int a2k = apNodeB->m_08;
    int a1k = apNodeA->m_08;
    GskNode* a1base = apNodeA->m_00;
    GskTmp tmp;
    tmp.Setup(a1k, a2k);

    if ((int)ebx->m_0c == 3)
    {
        ((GskSub*)agent->m_pAccess)->Init(a1base, ebx, &tmp);
    }
    else
    {
        ((GskSub*)agent->m_pAccess)->Init2(a1base, ebx, &tmp);
    }

    agent->m_vSeparatingNormal.m_vComponents = _mm_setzero_ps();
    agent->m_vSeparatingNormal.w = -1.0f;
    agent->m_fFloatValue = -1.0f;

    const GskNode* p = apNodeA;
    while (p->m_0c != 0)
    {
        p = p->m_0c;
    }
    float fa = p->m_4c;

    const GskNode* r = apNodeB;
    while (r->m_0c != 0)
    {
        r = r->m_0c;
    }
    float fb = r->m_4c;

    agent->m_fSeparationDistance = (fa < fb) ? fa : fb;
    return agent;
}

struct ContactData
{
    LocalM128 m_vHitNormal;
    LocalM128 m_vContactPosition;
    float m_fClosestPointDistanceSquared;
    LocalM128 m_data30;
    LocalM128 m_data40;
};

struct GskCache
{
    short m_kVertices[4];
    unsigned char m_ucDimensionA, m_ucDimensionB, m_features, unk17;
};
struct GskStatus
{
    int m_ucDimensionA;
    int m_ucDimensionB;
    int m_featureA;
    int m_featureB;
    int unk10;
    int unk14;
    int pad18;
    int pad1c;
    LocalM128 m_vertsA[12];
    LocalM128 m_vertsB[10];

    void hkpGsk_getClosestFeature(const void* shapeA, const void* shapeB, const hkTransform* bTa, void* out10);
    void hkpGsk_exitAndExportCacheImpl(void* cache);
    void hkpGsk_convertFeatureToClosestDistance(void* out10, hkContactPoint* pointOut);
};

extern "C"
{
    void _mm_store_ps(float*, LocalM128);
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
    LocalM128 _mm_unpacklo_ps(LocalM128, LocalM128);
    LocalM128 _mm_unpackhi_ps(LocalM128, LocalM128);
    LocalM128 _mm_movehl_ps(LocalM128, LocalM128);
    LocalM128 _mm_movelh_ps(LocalM128, LocalM128);
    LocalM128 _mm_load_ss(const float*);
    LocalM128 _mm_set_ss(float);
}

static __forceinline short* unpackCache(GskCache& c, int& b, unsigned& f, int& a)
{
    b = c.m_ucDimensionB;
    f = c.m_features;
    a = c.m_ucDimensionA;
    return c.m_kVertices;
}

// Runs the GSK solver on the two shapes, writes the contact point to pointOut, and returns true if the separation minus radii is below input.m_fScalar.
// @fnv 0x00dac7f0
hkBool hkpGskBaseAgent::_getClosestPoint(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const CollisionAgentContext& input,
                                     GskAgentData& output)
{
    hkContactPoint& pointOut = (hkContactPoint&)output;
    const hkpConvexShape* pShapeB = (const hkpConvexShape*)bodyB.m_pCollisionShape;
    const hkpConvexShape* shapeA = (const hkpConvexShape*)bodyA.m_pCollisionShape;

    hkTransform tRelativeTransform;
    tRelativeTransform.hkTransform_setMulInverseMul(bodyA.m_pMotionState, bodyB.m_pMotionState);

    const hkpConvexShape* __restrict convertShapeA = shapeA;
    int dimB, r1;
    unsigned uiFeatures;
    short* i = unpackCache(*(GskCache*)m_pAccess, dimB, uiFeatures, r1);
    GskStatus gskStatus;
    gskStatus.m_ucDimensionB = dimB;
    gskStatus.unk10 = 0;
    gskStatus.m_featureA = uiFeatures & 0x0f;
    gskStatus.m_ucDimensionA = r1;
    gskStatus.m_featureB = uiFeatures >> 4;
    gskStatus.unk14 = 0;

    convertShapeA->GetVerticesFromIds((const hkpVertexId*)i, r1, (Vector4WithInt24W*)gskStatus.m_vertsA);
    pShapeB->GetVerticesFromIds((const hkpVertexId*)&i[gskStatus.m_ucDimensionA], gskStatus.m_ucDimensionB,
                              (Vector4WithInt24W*)gskStatus.m_vertsB);

    LocalM128 c1;
    gskStatus.hkpGsk_getClosestFeature(shapeA, pShapeB, &tRelativeTransform, &c1);

    if (gskStatus.unk14 != 0)
    {
        gskStatus.hkpGsk_exitAndExportCacheImpl(i);
    }

    gskStatus.hkpGsk_convertFeatureToClosestDistance(&c1, &pointOut);

    const hkTransform* b = (const hkTransform*)bodyA.m_pMotionState;
    ContactData* pContactData = (ContactData*)&pointOut;
    LocalM128 verts = pContactData->m_vHitNormal;

    LocalM128 feat = _mm_mul_ps(_mm_shuffle_ps(verts, verts, 0x55), b->m_row1);
    LocalM128 aTransform = _mm_mul_ps(_mm_shuffle_ps(verts, verts, 0), b->m_row0);
    LocalM128 v3 = _mm_mul_ps(_mm_shuffle_ps(verts, verts, 0xaa), b->m_row2);
    pContactData->m_data40 = _mm_add_ps(_mm_add_ps(feat, aTransform), v3);

    float dimA;
    dimA = pContactData->m_fClosestPointDistanceSquared - shapeA->m_fSphereRadius - pShapeB->m_fSphereRadius;
    pContactData->m_fClosestPointDistanceSquared = dimA;

    if (dimA < input.m_fScalar)
    {
        float fRadiusA = shapeA->m_fSphereRadius;
        LocalM128 vRadiusA = _mm_load_ss(&fRadiusA);
        LocalM128 vRadiusASplatted = _mm_shuffle_ps(vRadiusA, vRadiusA, 0);
        _mm_store_ps(pContactData->m_vContactPosition.m128_f32,
                     _mm_sub_ps(pContactData->m_vContactPosition, _mm_mul_ps(vRadiusASplatted, verts)));

        float negDist = -dimA;
        LocalM128 negV = _mm_load_ss(&negDist);
        LocalM128 cnt = _mm_shuffle_ps(negV, negV, 0);
        LocalM128 r0 = _mm_sub_ps(_mm_add_ps(pContactData->m_vContactPosition, _mm_mul_ps(cnt, pContactData->m_vHitNormal)),
                               tRelativeTransform.m_row3);

        struct Rows
        {
            LocalM128 a, c;
        } rows;

        LocalM128 vColumn0 = tRelativeTransform.m_row0, kIter = tRelativeTransform.m_row1,
               s = tRelativeTransform.m_row2;
        LocalM128 v2 = _mm_unpacklo_ps(vColumn0, kIter);
        rows.a = _mm_unpackhi_ps(vColumn0, kIter);
        LocalM128 v4 = _mm_movelh_ps(v2, s);
        rows.c = _mm_shuffle_ps(_mm_movehl_ps(v4, v2), s, 0xd4);
        LocalM128 tmp = _mm_shuffle_ps(rows.a, s, 0xe4);
        LocalM128 bTa = _mm_mul_ps(_mm_shuffle_ps(r0, r0, 0x55), rows.c);
        LocalM128 r2 = _mm_mul_ps(_mm_shuffle_ps(r0, r0, 0), v4);
        LocalM128 m3 = _mm_mul_ps(_mm_shuffle_ps(r0, r0, 0xaa), tmp);
        pContactData->m_data30 = _mm_add_ps(_mm_add_ps(bTa, r2), m3);

        return true;
    }

    return false;
}

#include <windows.h>

struct S_00dac2b0_TimerCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
    void setTime()
    {
        volatile unsigned int t = (unsigned int)__rdtsc();
        m_uiStartTicks = t;
    }
};

static inline void GskTimer(const char* name)
{
    hkMonitorStream& stream = *(hkMonitorStream*)TlsGetValue(DAT_0126835c);
    if (stream.m_end.val() < stream.m_capacityMinus16.val())
    {
        S_00dac2b0_TimerCommand* h = (S_00dac2b0_TimerCommand*)stream.m_end.val();
        h->m_pCommandName = name;
        _ReadWriteBarrier();
        h->setTime();
        stream.m_end.m_storage = (char*)(h + 1);
    }
}

struct S_00dac2b0_Cache
{
    unsigned short id0, id1, id2, id3;
    unsigned char dimA, dimB, dims;
    void hkpGskCache_initTriangle(const hkpConvexShape* a, const hkpConvexShape* b, const hkTransform* t);
    void hkpGskCache_init(const hkpConvexShape* a, const hkpConvexShape* b, const hkTransform* t);
};

struct __declspec(align(16)) S_00dac2b0_Gsk
{
    int m_ucDimensionA;
    int m_ucDimensionB;
    int m_maxA;
    int m_maxB;
    int m_iCachedVertexCount;
    int m_zero;
    int unk18;
    int unk1C;
    hkVector4 m_vertsA[12];
    hkVector4 m_vertsB[10];
    int hkpGsk_getClosestFeature(const hkpConvexShape* a, const hkpConvexShape* b, const hkTransform* t,
                     hkVector4* out);
};

// Runs the GSK step (timed as TtGsk) on the two bodies' shapes and adds the pair to the collector if the result is nonzero or the distance is below the radii.
// @fnv 0x00dac2b0
void __cdecl hkpGskBaseAgent::m_pVirtualFunction1(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const CollisionAgentContext& input,
                                               hkpCdBodyPairCollector& collector)
{
    GskTimer("TtGsk");

    const hkpConvexShape* shapeA = (const hkpConvexShape*)bodyA.m_pCollisionShape;
    const hkpConvexShape* shapeB = (const hkpConvexShape*)bodyB.m_pCollisionShape;

    hkTransform aTb;
    aTb.hkTransform_setMulInverseMul(bodyA.m_pMotionState, bodyB.m_pMotionState);

    S_00dac2b0_Cache cache;
    if (shapeB->getType() == HK_SHAPE_TRIANGLE)
    {
        cache.hkpGskCache_initTriangle(shapeA, shapeB, &aTb);
    }
    else
    {
        cache.hkpGskCache_init(shapeA, shapeB, &aTb);
    }

    S_00dac2b0_Gsk gsk;
    gsk.m_ucDimensionA = cache.dimA;
    gsk.m_ucDimensionB = cache.dimB;
    gsk.m_maxA = cache.dims & 0xf;
    gsk.m_iCachedVertexCount = 1;
    gsk.m_maxB = cache.dims >> 4;
    gsk.m_zero = 0;
    shapeA->GetVerticesFromIds(&cache.id0, cache.dimA, (Vector4WithInt24W*)gsk.m_vertsA);
    shapeB->GetVerticesFromIds(&cache.id0 + gsk.m_ucDimensionA, gsk.m_ucDimensionB, (Vector4WithInt24W*)gsk.m_vertsB);

    hkVector4 out;
    int iResult = gsk.hkpGsk_getClosestFeature(shapeA, shapeB, &aTb, &out);

    GskTimer("Et");

    if (iResult == 0)
    {
        float d = out.w - shapeA->m_fSphereRadius - shapeB->m_fSphereRadius;
        if (d < 0.0f)
        {
            collector.AddCdBodyPair(bodyA, bodyB);
        }
    }
    else
    {
        collector.AddCdBodyPair(bodyA, bodyB);
    }
}

union EarlyScratch
{
    volatile unsigned int ticks;
    int result;
    float distance;
};

extern "C" LocalM128 _mm_add_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
extern unsigned long hkMonitorStreamTls;

struct S_00dac0b0_TimerCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
};

struct S_00dac0b0_TimerBeginListCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
    const char* m_pFirst;
};

static inline void S_00dac0b0_TimerBeginList(const char* name, const char* firstSplit, EarlyScratch& scratch)
{
    hkMonitorStream* s = (hkMonitorStream*)TlsGetValue(hkMonitorStreamTls);
    if (s->m_end.val() < s->m_capacityMinus16.val())
    {
        S_00dac0b0_TimerBeginListCommand* h = (S_00dac0b0_TimerBeginListCommand*)s->m_end.val();
        h->m_pCommandName = name;
        h->m_pFirst = firstSplit;
        _ReadWriteBarrier();
        scratch.ticks = (unsigned int)__rdtsc();
        h->m_uiStartTicks = scratch.ticks;
        s->m_end.m_storage = (char*)(h + 1);
    }
}

static inline void S_00dac0b0_Timer(const char* name, EarlyScratch& scratch)
{
    hkMonitorStream* s = (hkMonitorStream*)TlsGetValue(hkMonitorStreamTls);
    if (s->m_end.val() < s->m_capacityMinus16.val())
    {
        S_00dac0b0_TimerCommand* h = (S_00dac0b0_TimerCommand*)s->m_end.val();
        h->m_pCommandName = name;
        _ReadWriteBarrier();
        scratch.ticks = (unsigned int)__rdtsc();
        h->m_uiStartTicks = scratch.ticks;
        s->m_end.m_storage = (char*)(h + 1);
    }
}

static inline void S_00dac0b0_TimerEnd()
{
    {
        hkMonitorStream* s = (hkMonitorStream*)TlsGetValue(hkMonitorStreamTls);
        if (s->m_end.val() < s->m_capacityMinus16.val())
        {
            S_00dac0b0_TimerCommand* h = (S_00dac0b0_TimerCommand*)s->m_end.val();
            h->m_pCommandName = "lt";
            _ReadWriteBarrier();
            struct Tk
            {
                unsigned int v;
            };
            Tk t;
            *(volatile unsigned int*)&t.v = (unsigned int)__rdtsc();
            *(Tk*)&h->m_uiStartTicks = t;
            s->m_end.m_storage = (char*)(h + 1);
        }
    }
}

struct S_00dac0b0_PackedCache
{
    unsigned short id0, id1, id2, id3;
    unsigned char m_ucDimensionA;
    unsigned char m_ucDimensionB;
    unsigned char m_flags;
};

struct S_00dac0b0_Gsk
{
    int m_ucDimensionA;
    int m_ucDimensionB;
    int m_ucLowNibble;
    int m_ucHighNibble;
    int m_iCachedVertexCount;
    int m_changed;
    int unk18;
    int unk1C;
    hkVector4 a00;
    hkVector4 a01;
    hkVector4 a02;
    hkVector4 a03;
    hkVector4 a04;
    hkVector4 a05;
    hkVector4 a06;
    hkVector4 a07;
    hkVector4 a08;
    hkVector4 a09;
    hkVector4 a10;
    hkVector4 a11;
    hkVector4 b00;
    hkVector4 b01;
    hkVector4 b02;
    hkVector4 b03;
    hkVector4 b04;
    hkVector4 b05;
    hkVector4 b06;
    hkVector4 b07;
    hkVector4 b08;
    hkVector4 b09;
    hkTransform aTb;
    int hkpGsk_getClosestFeature(const hkpConvexShape* a, const hkpConvexShape* b, const hkTransform& aTb, hkVector4* out);
    void hkpGsk_exitAndExportCacheImpl(S_00dac0b0_PackedCache* dst);
};

// @fnv 0x00dac0b0
void hkpGskBaseAgent::getPenetrations(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                                     const CollisionAgentContext& input, hkpCdBodyPairCollector& collector)
{
    EarlyScratch scratch;
    S_00dac0b0_TimerBeginList("LtGsk", "Sttim", scratch);
    S_00dac0b0_Timer("StSepNormal", scratch);

    const hkpConvexShape* shapeA = (const hkpConvexShape*)bodyA.m_pCollisionShape;
    const hkpConvexShape* shapeB = (const hkpConvexShape*)bodyB.m_pCollisionShape;
    S_00dac0b0_Gsk gsk;
    gsk.aTb.hkTransform_setMulInverseMul(bodyA.m_pMotionState, bodyB.m_pMotionState);

    S_00dac0b0_PackedCache* c = (S_00dac0b0_PackedCache*)m_pAccess;
    gsk.m_ucDimensionA = c->m_ucDimensionA;
    gsk.m_ucDimensionB = c->m_ucDimensionB;
    gsk.m_ucLowNibble = c->m_flags & 0xf;
    gsk.m_ucHighNibble = c->m_flags >> 4;
    gsk.m_iCachedVertexCount = 1;
    gsk.m_changed = 0;
    shapeA->GetVerticesFromIds(&c->id0, gsk.m_ucDimensionA, (Vector4WithInt24W*)&gsk.a00);
    shapeB->GetVerticesFromIds(&c->id0 + gsk.m_ucDimensionA, gsk.m_ucDimensionB, (Vector4WithInt24W*)&gsk.b00);

    hkVector4 normal;
    scratch.result = gsk.hkpGsk_getClosestFeature(shapeA, shapeB, gsk.aTb, &normal);
    if (gsk.m_changed)
        gsk.hkpGsk_exitAndExportCacheImpl(c);

    if (scratch.result == 0)
    {
        LocalM128 n = *(LocalM128*)&normal;
        scratch.distance = normal.w - shapeA->m_fSphereRadius - shapeB->m_fSphereRadius;
        const hkTransform* ta = (const hkTransform*)bodyA.m_pMotionState;
        LocalM128 r0 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(n, n, 0x55), *(const LocalM128*)&ta->m_row1),
                                          _mm_mul_ps(_mm_shuffle_ps(n, n, 0x00), *(const LocalM128*)&ta->m_row0)),
                               _mm_mul_ps(_mm_shuffle_ps(n, n, 0xaa), *(const LocalM128*)&ta->m_row2));
        *(LocalM128*)&m_vSeparatingNormal = r0;
        m_vSeparatingNormal.w = scratch.distance;
        if (scratch.distance < 0.0f)
            collector.AddCdBodyPair(bodyA, bodyB);
    }
    else
    {
        *(LocalM128*)&m_vSeparatingNormal = _mm_setzero_ps();
        collector.AddCdBodyPair(bodyA, bodyB);
    }
    S_00dac0b0_TimerEnd();
}
