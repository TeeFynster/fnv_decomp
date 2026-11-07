#define FNV64_HKVECTOR4_OWN_ASSIGN   // this unit defines its own hkVector4 assign form
#include <new>
#include "../../../../../../../include/hkArray.h"
#include "../../../../../../../include/hkpCollisionAgent.h"
#include "../../../../../../../include/hkpCollisionInput.h"
#include "../../../../../../../include/hkpSymmetricAgent.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/RootContactPoint.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkContactPoint.h"
#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/hkpClosestCdPointCollector.h"
#include "../../../../../../../include/hkpCollisionDispatcher.h"
#include "../../../../../../../include/hkpConvexListShape.h"
#include "../../../../../../../include/hkpFlagCdBodyPairCollector.h"
#include "../../../../../../../include/hkpGskfAgent.h"
#include "../../../../../../../include/hkpConvexListAgent.h"
#include "../../../../../../../include/hkpCdBody.h"
#include "../../../../../../../include/hkpCdPointCollector.h"
#include "../../../../../../../include/hkpSimpleClosestContactCollector.h"

// src/havok/physics/collide/agent/deprecated/convexlist/hkpconvexlistagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/deprecated/convexlist/hkpconvexlistagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

class Allocator
{
public:
    virtual void V0() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
};


inline void hkVector4::operator=(const hkVector4& other)
{
    m_vComponents = other.m_vComponents;
}
inline float hkContactPoint::getDistance() const
{
    return m_vSeparatingNormal.m_vComponents.m128_f32[3];
}
inline hkContactPoint& hkContactPoint::operator=(const hkContactPoint& other)
{
    m_vContactPosition = other.m_vContactPosition;
    m_vSeparatingNormal = other.m_vSeparatingNormal;
    return *this;
}

// Methods absent from the shared class use adapters with the original ECX/stack ABI.
extern "C" void __cdecl FUN_00dacb20();
extern "C" void __cdecl SetValueIfExpected();
extern "C" void* __cdecl FUN_00dacbd0();
extern "C" void* __cdecl FUN_00d33940();
extern "C" void __cdecl hkpAgent1nSector_ProcessEntries_00da3510(void*, void*);

// @fnv 0x00d33770
void __thiscall hkpConvexListAgent::vf09(int a)
{
    if (*(char*)((char*)this + 0x84))
        RemovePoint(a);
    else
        hkpAgent1nSector_ProcessEntries_00da3510((char*)this + 0x30, (void*)a);
}

extern "C" void __cdecl hkpConvexListAgent_QueryClosestPointsAfterHullTest(int, int, int, int);

// @fnv 0x00d33b70
// src: HAVOK_SRC 0x00d33b70
void __fastcall hkpConvexListAgent_getClosestPoints(hkpConvexListAgent* self, void*, int aiArg1, int aiArg2, int aiArg3, int aiArg4)
{
    hkpConvexListAgent_QueryClosestPointsAfterHullTest(aiArg1, aiArg2, aiArg3, aiArg4);
}

extern "C"
{
    void __cdecl hkpConvexListAgent_staticGetPenetrations(void* a, void* b, void* c, void* d);
}

// @fnv 0x00d33c80
// src: HAVOK_SRC 0x00d33c80
void __fastcall hkpConvexListAgent_getPenetrations(hkpConvexListAgent* self, void*, void* apArg1, void* apArg2, void* apArg3, void* apArg4)
{
    hkpConvexListAgent_staticGetPenetrations(apArg1, apArg2, apArg3, apArg4);
}

extern "C" void __cdecl AppendRecordAndRegisterAgents();
extern void* __cdecl CreateConvexListAgent();
extern void* __cdecl InitSpawnedBuffer();
extern void* __cdecl Runtime_UpdateState_00d34970();
extern void* __cdecl hkpConvexListAgent_staticLinearCast_UpdateState_00d349b0();
extern void* __cdecl hkpConvexListAgent_createConvexConvexListAgent();
extern void* __cdecl _FUN_00d33b90();
extern void* __cdecl _FUN_00d339d0();
extern void* __cdecl hkpConvexListAgent_staticLinearCast();
extern void* __cdecl hkpConvexListAgent_createConvexListConvexListAgent();
// Fills a collision-function table three times and registers it with the dispatcher for the 0x16/0x12, 0x12/0x16 and 0x16/0x16 type pairs.
// @fnv 0x00d346b0
void __cdecl RegisterConvexListAgentCollisionFuncs(hkpCollisionDispatcher* self)
{
    // Preserve the original uninitialized table; its shared constructor adds initialization.
    void* funcTableStorage[sizeof(hkpCollisionDispatcher::CollisionAgentFunctionTable) / sizeof(void*)];
    hkpCollisionDispatcher::CollisionAgentFunctionTable& funcTable =
        *(hkpCollisionDispatcher::CollisionAgentFunctionTable*)funcTableStorage;
    funcTable.m_pCreateFunc = (hkpCollisionDispatcher::CreateFunc)CreateConvexListAgent;
    funcTable.m_pQueryPenetrationsFunc = (hkpCollisionDispatcher::GetPenetrationsFunc)InitSpawnedBuffer;
    funcTable.m_pGetPenetrationsFunc = (hkpCollisionDispatcher::GetClosestPointsFunc)Runtime_UpdateState_00d34970;
    funcTable.m_pLinearCastFunc = (hkpCollisionDispatcher::LinearCastFunc)hkpConvexListAgent_staticLinearCast_UpdateState_00d349b0;
    funcTable.m_bIsFlipped.m_cBooleanValue = 1;
    funcTable.m_bIsPredictive.m_cBooleanValue = 1;
    ((void (__thiscall*)(hkpCollisionDispatcher*, hkpCollisionDispatcher::CollisionAgentFunctionTable*, int, int))AppendRecordAndRegisterAgents)(self, &funcTable, 0x16, 0x12);
    funcTable.m_pCreateFunc = (hkpCollisionDispatcher::CreateFunc)hkpConvexListAgent_createConvexConvexListAgent;
    funcTable.m_pQueryPenetrationsFunc = (hkpCollisionDispatcher::GetPenetrationsFunc)_FUN_00d33b90;
    funcTable.m_pGetPenetrationsFunc = (hkpCollisionDispatcher::GetClosestPointsFunc)_FUN_00d339d0;
    funcTable.m_pLinearCastFunc = (hkpCollisionDispatcher::LinearCastFunc)hkpConvexListAgent_staticLinearCast;
    funcTable.m_bIsFlipped.m_cBooleanValue = 0;
    funcTable.m_bIsPredictive.m_cBooleanValue = 1;
    ((void (__thiscall*)(hkpCollisionDispatcher*, hkpCollisionDispatcher::CollisionAgentFunctionTable*, int, int))AppendRecordAndRegisterAgents)(self, &funcTable, 0x12, 0x16);
    funcTable.m_pCreateFunc = (hkpCollisionDispatcher::CreateFunc)hkpConvexListAgent_createConvexListConvexListAgent;
    funcTable.m_pQueryPenetrationsFunc = (hkpCollisionDispatcher::GetPenetrationsFunc)_FUN_00d33b90;
    funcTable.m_pGetPenetrationsFunc = (hkpCollisionDispatcher::GetClosestPointsFunc)_FUN_00d339d0;
    funcTable.m_pLinearCastFunc = (hkpCollisionDispatcher::LinearCastFunc)hkpConvexListAgent_staticLinearCast;
    funcTable.m_bIsFlipped.m_cBooleanValue = 0;
    funcTable.m_bIsPredictive.m_cBooleanValue = 1;
    ((void (__thiscall*)(hkpCollisionDispatcher*, hkpCollisionDispatcher::CollisionAgentFunctionTable*, int, int))AppendRecordAndRegisterAgents)(self, &funcTable, 0x16, 0x16);
}

// @fnv 0x00d337f0
// src: HAVOK_SRC 0x00d337f0
void __fastcall hkpConvexListAgent_removePoint(hkpConvexListAgent* self, void*, int a)
{
    if (*(char*)((char*)self + 0x84))
        ((void (__thiscall*)(hkpGskfAgent*, int))FUN_00dacb20)(self, a);
}

// @fnv 0x00d33810
// src: HAVOK_SRC 0x00d33810
void __fastcall hkpConvexListAgent_commitPotential(hkpConvexListAgent* self, void*, int a)
{
    if (*(char*)((char*)self + 0x84))
        self->hkpGskfAgent::AddPotential(a);
}

namespace fnv_00d33830 {
// @fnv 0x00d33830
// src: HAVOK_SRC 0x00d33830
void __fastcall hkpConvexListAgent_createZombie(hkpConvexListAgent* self, void*, int aiArg)
{
    if (*(char*)((char*)self + 0x84))
        self->hkpGskfAgent::ClearSlotById(aiArg);
}
}  // namespace fnv_00d33830

extern void __cdecl hkpAgentMachineUtil_calc1nStatistics(void*, void*, void*);

// If the byte at offset 0x84 is zero, calls FUN_00d97250 with this+0x30, the pointer at a+8 and a.
// @fnv 0x00d33740
// src: HAVOK_LIB 0x00d33740
void __fastcall hkpConvexListAgent_calcContentStatistics(hkpConvexListAgent* self, void*, int a, int iUnused)
{
    if (*(char*)((char*)self + 0x84) == 0)
    {
        hkpAgentMachineUtil_calc1nStatistics((char*)&self->m_kContactManifold, *(void**)(a + 8), (void*)a);
    }
}

void __cdecl hkAgent1nMachine_Destroy(void*, int, int, int);
// Calls FUN_00da42b0 with fields at offsets 0x30, 0x80 and 8 plus a, then clears the field at 0x30 and sets the byte at 0x84 to 1.
// @fnv 0x00d33850
// src: HAVOK_LIB 0x00d33850
void __fastcall hkpConvexListAgent_switchToGskMode(hkpConvexListAgent* self, void*, int a)
{
    hkAgent1nMachine_Destroy((char*)&self->m_kContactManifold, *(int*)((char*)self + 0x80), (int)self->m_pContactManager, a);
    *(int*)&self->m_kContactManifold = 0;
    *(char*)((char*)self + 0x84) = 1;
}

// Forwards all five arguments to FUN_00d33ca0 and returns its result.
// @fnv 0x00d33da0
// src: HAVOK_SRC 0x00d33da0
void* __stdcall hkpConvexListAgent_linearCast(void* a, void* b, void* c, void* d, void* e)
{
    return ((void*(__cdecl*)(void*, void*, void*, void*, void*))hkpConvexListAgent_staticLinearCast)(a, b, c, d, e);
}


// @fnv 0x00d34770
void hkpSimpleClosestContactCollector::Reset()
{
    float max = 3.402820018375656e+38f;
    *(char*)((char*)this + 8) = 0;
    *(float*)((char*)this + 0x2c) = max;
    *(float*)((char*)this + 4) = max;
}

struct D338e0Local
{
    int field00;
    int field04;
    int field08;
    int field0C;
    int field10;
    int field14;
    int field18;
    int field1C;
};

extern "C" void __cdecl hkAgent1nMachine_UpdateShapeCollectionFilter(int*, D338e0Local*);

inline void D338e0Dispatch(D338e0Local* local, int* ownerField, int result)
{
    local->field0C = result;
    hkAgent1nMachine_UpdateShapeCollectionFilter(ownerField, local);
}

// If unk84 is zero, fills a D338e0Local from the parameters and unk08, calls vf10 on the agent at param2, and dispatches the result with unk30.
// @fnv 0x00d338e0
// src: HAVOK_LIB 0x00d338e0
void __fastcall hkpConvexListAgent_updateShapeCollectionFilter(hkpConvexListAgent* self, void*, int aiArg1, int apAgentPtr, int aiArg3, int aiArg4)
{
    if (*(unsigned char*)((char*)self + 0x84) == 0)
    {
        D338e0Local local;
        local.field00 = aiArg1;
        local.field04 = apAgentPtr;
        local.field10 = aiArg3;
        local.field14 = (int)self->m_pContactManager;
        local.field18 = aiArg4;

        hkpCollisionAgent** ppAgent = reinterpret_cast<hkpCollisionAgent**>(apAgentPtr);
        // This virtual slot is not yet declared by the shared base.
        int result = ((int (__thiscall*)(hkpCollisionAgent*))(*(void***)*ppAgent)[4])(*ppAgent);

        D338e0Dispatch(&local, (int*)&self->m_kContactManifold, result);
    }
}

extern "C" hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

// The convex-list filter is not yet supplied by a shared header.
class hkpConvexListFilter
{
  public:
    virtual ~hkpConvexListFilter() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual int ShouldBodiesCollide(const hkpCdBody& kBodyA, const hkpCdBody& kBodyB,
                                    const hkpCollisionInput& kInput) const throw();
};

// The original allocation body was inlined in both factory functions.
__forceinline void* hkpCollisionAgent::operator new(std::size_t uiSize)
{
    hkpCollisionAgent* p = (hkpCollisionAgent*)hkMemoryRouter_getInstance()->heap().blockAlloc(uiSize);
    p->m_usMemSizeAndFlags = (unsigned short)uiSize;
    return p;
}

static __forceinline hkpCollisionAgent* MakePredGskfAgent(
    const hkpCdBody& bodyA, const hkpCdBody& bodyB, hkpContactMgr* mgr) throw()
{
    void* agent = hkpCollisionAgent::operator new(0x80);
    ((void (__thiscall*)(hkpGskfAgent*, const hkpCdBody&, const hkpCdBody&,
                        hkpContactMgr*))FUN_00dacbd0)((hkpGskfAgent*)agent, bodyA, bodyB, mgr);
    *(void**)agent = (void*)0x010ceb94;
    return (hkpCollisionAgent*)agent;
}

static __forceinline hkpCollisionAgent* MakeFlippedConvexListAgent(
    const hkpCdBody& bodyA, const hkpCdBody& bodyB,
    const hkpCollisionInput& input, hkpContactMgr* mgr) throw()
{
    void* agent = hkpCollisionAgent::operator new(0x90);
    ((void (__thiscall*)(hkpConvexListAgent*, const hkpCdBody&, const hkpCdBody&,
                        const hkpCollisionInput&, hkpContactMgr*))FUN_00d33940)(
        (hkpConvexListAgent*)agent, bodyA, bodyB, input, mgr);
    *(void**)agent = (void*)0x010cec68;
    return (hkpCollisionAgent*)agent;
}

// hkpshapecollectionagent.cpp binds its shape-collection constructor to 0x00d440f0.
extern "C" void* __cdecl FUN_00d440f0();
class hkpShapeCollectionAgent;

static __forceinline hkpCollisionAgent* MakeShapeCollectionAgent(
    const hkpCdBody& bodyA, const hkpCdBody& bodyB,
    const hkpCollisionInput& input, hkpContactMgr* mgr) throw()
{
    void* agent = hkpCollisionAgent::operator new(0x38);
    return ((hkpCollisionAgent* (__thiscall*)(void*, const hkpCdBody&, const hkpCdBody&,
              const hkpCollisionInput&, hkpContactMgr*))FUN_00d440f0)(agent, bodyA, bodyB, input, mgr);
}

static __forceinline hkpCollisionAgent* MakeFlippedShapeCollectionAgent(
    const hkpCdBody& bodyA, const hkpCdBody& bodyB,
    const hkpCollisionInput& input, hkpContactMgr* mgr) throw()
{
    // The shared symmetric declaration has no Agent base; initialize the full 0x38-byte agent through its bound constructor.
    hkpSymmetricAgent<hkpShapeCollectionAgent>* agent =
        (hkpSymmetricAgent<hkpShapeCollectionAgent>*)hkpCollisionAgent::operator new(0x38);
    ((void (__thiscall*)(hkpSymmetricAgent<hkpShapeCollectionAgent>*, const hkpCdBody&,
              const hkpCdBody&, const hkpCollisionInput&, hkpContactMgr*))FUN_00d440f0)(
        agent, bodyB, bodyA, input, mgr);
    *(void**)agent = (void*)0x010ce8b0;
    return (hkpCollisionAgent*)agent;
}

// Creates a collision agent for the two bodies: picks the agent class from the convex list filter's result, or a default agent when pkMgr is null.
// @fnv 0x00d33dd0
hkpCollisionAgent* __cdecl CreateConvexListAgent(const hkpCdBody& kBodyA, const hkpCdBody& kBodyB,
                                                     const hkpCollisionInput& kInput,
                                                     hkpContactMgr* pkMgr) throw()
{
    if (pkMgr)
    {
        switch (kInput.m_pConvexListCollisionFilter->ShouldBodiesCollide(kBodyA, kBodyB, kInput))
        {
        case 0:
            return MakeFlippedConvexListAgent(kBodyB, kBodyA, kInput, pkMgr);
        case 1:
            return MakeShapeCollectionAgent(kBodyA, kBodyB, kInput, pkMgr);
        case 2:
            return MakePredGskfAgent(kBodyA, kBodyB, pkMgr);
        }
        return 0;
    }
    return MakeShapeCollectionAgent(kBodyA, kBodyB, kInput, 0);
}

void __cdecl ReleaseAllEntries(void* out, void* src, void* arg);
void InitBlockPool(void* p);

// Reinitializes the embedded array, clears m_84 and m_3c, and sets m_86 to 0x19.
// @fnv 0x00d33ef0
// src: HAVOK_LIB 0x00d33ef0
void __fastcall hkpConvexListAgent_switchToStreamMode(hkpConvexListAgent* self, void*, void* arg)
{
    ReleaseAllEntries(((char*)&self->m_kContactManifold), self->m_pContactManager, arg);
    *(char*)((char*)self + 0x84) = 0;
    new (((char*)&self->m_kContactManifold)) hkArray<void*>();
    InitBlockPool(((char*)&self->m_kContactManifold));
    *(float*)((char*)self + 0x3c) = 0.0f;
    *(short*)((char*)self + 0x86) = 0x19;
}

namespace fnv_00d343f0 {
extern "C" hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

static __forceinline hkpCollisionAgent* MakeConvexListAgent(
    const hkpCdBody& bodyA, const hkpCdBody& bodyB,
    const hkpCollisionInput& input, hkpContactMgr* mgr) throw()
{
    void* agent = hkpCollisionAgent::operator new(0x90);
    return ((hkpCollisionAgent* (__thiscall*)(hkpConvexListAgent*, const hkpCdBody&, const hkpCdBody&,
                        const hkpCollisionInput&, hkpContactMgr*))FUN_00d33940)(
        (hkpConvexListAgent*)agent, bodyA, bodyB, input, mgr);
}

// @fnv 0x00d343f0
// src: HAVOK_LIB 0x00d343f0
hkpCollisionAgent* __cdecl hkpConvexListAgent_createConvexConvexListAgent(const hkpCdBody& kBodyA, const hkpCdBody& kBodyB,
                                            const hkpCollisionInput& kInput, hkpContactMgr* pkMgr) throw()
{
    if (pkMgr)
    {
        switch (kInput.m_pConvexListCollisionFilter->ShouldBodiesCollide(kBodyB, kBodyA, kInput))
        {
        case 0:
            return MakeConvexListAgent(kBodyA, kBodyB, kInput, pkMgr);
        case 1:
            return MakeFlippedShapeCollectionAgent(kBodyA, kBodyB, kInput, pkMgr);
        case 2:
            return MakePredGskfAgent(kBodyA, kBodyB, pkMgr);
        }
        return 0;
    }
    return MakeFlippedShapeCollectionAgent(kBodyA, kBodyB, kInput, 0);
}
}  // namespace fnv_00d343f0

class hkCollectorBaseD347
{
  public:
    hkCollectorBaseD347() : m_bHasHit(false)
    {}
    virtual void AddHit(void* hit) = 0;

    bool m_bHasHit;
};

class hkCollectorD347 : public hkCollectorBaseD347
{
  public:
    hkCollectorD347(int filter) : m_iFilter(filter)
    {}
    virtual void AddHit(void* hit);

    int m_iFilter;
};

extern "C" void __cdecl hkpShapeCollectionAgent_staticGetPenetrations(void* a, void* b, void* c, hkCollectorBaseD347& collector);

// Constructs an hkCollectorD347 with the given filter and passes it to FUN_00d43dc0 along with a, b and c.
// @fnv 0x00d34790
// src: GUESS 0x00d34790 (confidence: low)
void __cdecl hkCollectorD347_ProcessState_00d34790(void* b, void* a, void* c, int filter)
{
    hkCollectorD347 collector(filter);
    hkpShapeCollectionAgent_staticGetPenetrations(a, b, c, collector);
}

extern "C" void __cdecl hkpShapeCollectionAgent_staticLinearCast_UpdateState_00d34810();
// @fnv 0x00d36930
// src: GUESS 0x00d36930 (confidence: low)
extern "C" void __cdecl hkpConvexListAgent_ForwardCall_00d36930()
{
    hkpShapeCollectionAgent_staticLinearCast_UpdateState_00d34810();
}

struct hkMemberD337
{
    int unk00;
};

void __cdecl _hkAgent1nMachine_WarpTime(hkMemberD337* member, float a, float b, int c);

// Sets a value on the object, calling SetValueIfExpected when m_84 is true, otherwise delegating to FUN_00da35f0 on m_30.
// @fnv 0x00d337a0
void __fastcall SetValue(hkpConvexListAgent* self, void*, float a, float b, int c)
{
    if (*(bool*)((char*)self + 0x84))
        ((void (__thiscall*)(hkpConvexListAgent*, float, float, int))SetValueIfExpected)(self, a, b, c);
    else
        _hkAgent1nMachine_WarpTime((hkMemberD337*)((char*)&self->m_kContactManifold), a, b, c);
}

// @fnv 0x00d33890
extern void __cdecl ReleaseAllEntries(void*, int, void*);
// src: HAVOK_LIB 0x00d33890
void __fastcall hkpConvexListAgent_cleanup(hkpConvexListAgent* self, void*, void* input)
{
    if (*(unsigned char*)((char*)self + 0x84))
    {
        ReleaseAllEntries(((char*)&self->m_kContactManifold), (int)self->m_pContactManager, input);
    }
    else
    {
        hkAgent1nMachine_Destroy(((char*)&self->m_kContactManifold), *(int*)((char*)self + 0x80), (int)self->m_pContactManager, (int)input);
    }
    ((void (__thiscall*)(hkpConvexListAgent*, int))(*(void***)self)[0])(self, 1);
}

extern float DAT_01012054;
extern char DAT_010cebf0[];

struct __declspec(align(16)) S00d33940_Out
{
    float x;
    float y;
    float z;
    float w;
    float x1;
    float y1;
    float z1;
    float w1;
    float x2;
    float y2;
    float z2;
    float w2;
    float x3;
    float y3;
    float z3;
    float w3;
    void hkTransform_setMulInverseMul(int a, int b);
};

struct S00d33940_Sub
{
    void hkpGskCache_init(int a, int b, S00d33940_Out* c);
};

// Calls FUN_00dacbd0(a, b, d), sets vt to DAT_010cebf0 and unk80 to *c, sets unk84/85, calls FUN_00dafcd0 on unk0c, and sets unk18 and unk2c to DAT_01012054.
// @fnv 0x00d33940
hkpConvexListAgent* __fastcall InitializeConvexListAgent(hkpConvexListAgent* self, void*, int* a, int* b, int* c, void* d)
{
    ((void (__thiscall*)(hkpGskfAgent*, int*, int*, void*))FUN_00dacbd0)(self, a, b, d);
    *(void**)self = DAT_010cebf0;
    *(int*)((char*)self + 0x80) = *c;
    *(unsigned char*)((char*)self + 0x84) = 1;
    *(unsigned char*)((char*)self + 0x85) = 0;
    int v1 = a[0];
    int v0 = b[0];
    S00d33940_Out o;
    o.hkTransform_setMulInverseMul(a[2], b[2]);
    ((S00d33940_Sub*)((char*)self + 0x0c))->hkpGskCache_init(v1, v0, &o);
    float* __restrict p2 = &self->m_vSeparatingNormal.m_vComponents.m128_f32[3];
    float* __restrict p1 = &self->m_fFloatValue;
    *p1 = *p2 = DAT_01012054;
    return self;
}

extern "C" unsigned __int64 __rdtsc(void);
#include <windows.h>
extern "C" void _ReadWriteBarrier(void);
extern DWORD DAT_0126835c;
extern char DAT_010cebd0;

void __cdecl TestGsk(void* a, void* b, void* c, hkpFlagCdBodyPairCollector* col);
void __cdecl hkCollectorD347_ProcessState_00d34790(void* a, void* b, void* c, void* d);

// Writes timer entries (LtCvxList/StcheckHull, Stchildren, lt), calls TestGsk with a collector, and calls FUN_00d34790 if the collector registered a hit.
// @fnv 0x00d33b90
// src: HAVOK_LIB 0x00d33b90
extern "C" void __cdecl hkpConvexListAgent_staticGetPenetrations(void* a, void* b, void* c, void* d)
{
    volatile DWORD tick;
    hkMonitorStream* pBuf = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    if (pBuf->m_end.m_storage < pBuf->m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* pRec = (hkMonitorStream::TimerCommand*)pBuf->m_end.m_storage;
        pRec->m_commandAndMonitor = "LtCvxList";
        ((hkMonitorStream::TimerBeginListCommand*)pRec)->m_nameOfFirstSplit = "StcheckHull";
        _ReadWriteBarrier();
        tick = (DWORD)__rdtsc();
        pRec->m_time0 = tick;
        pBuf->m_end.m_storage = reinterpret_cast<char*>((hkMonitorStream::TimerCommand*)((char*)pRec + 0x10));
    }

    void* flagStorage[sizeof(hkpFlagCdBodyPairCollector) / sizeof(void*)];
    hkpFlagCdBodyPairCollector& col = *(hkpFlagCdBodyPairCollector*)flagStorage;
    *(const void**)&col = &DAT_010cebd0;
    col.m_flag = false;
    TestGsk(a, b, c, &col);
    if (col.m_flag)
    {
        pBuf = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
        if (pBuf->m_end.m_storage < pBuf->m_capacityMinus16.m_storage)
        {
            hkMonitorStream::TimerCommand* pRec = (hkMonitorStream::TimerCommand*)pBuf->m_end.m_storage;
            pRec->m_commandAndMonitor = "Stchildren";
            _ReadWriteBarrier();
            tick = (DWORD)__rdtsc();
            pRec->m_time0 = tick;
            pBuf->m_end.m_storage = reinterpret_cast<char*>((hkMonitorStream::TimerCommand*)((char*)pRec + 0xc));
        }
        hkCollectorD347_ProcessState_00d34790(a, b, c, d);
    }

    pBuf = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    if (pBuf->m_end.m_storage < pBuf->m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* pRec = (hkMonitorStream::TimerCommand*)pBuf->m_end.m_storage;
        pRec->m_commandAndMonitor = "lt";
        _ReadWriteBarrier();
        tick = (DWORD)__rdtsc();
        pRec->m_time0 = tick;
        pBuf->m_end.m_storage = reinterpret_cast<char*>((hkMonitorStream::TimerCommand*)((char*)pRec + 0xc));
    }
}

extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);

extern unsigned long DAT_0126835c;
extern const char str_010cec28[];
extern const char str_01076f38[];
extern int DAT_010c476c;
extern float DAT_0104da48;

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

extern "C" int __cdecl TestGsk(const void* a, const void* b, const void* c, void* d);
extern "C" void __cdecl FUN_00dac450(const void* a, const void* b, const void* c, void* d);
extern "C" void __cdecl QueryClosestPoints(const void* a, const void* b, const void* c, void* d);

struct ContactPointPair
{
    hkContactPoint m_kPoint;
    const void* m_pBodyA;
    const void* m_pBodyB;
};


// If TestGsk reports a hit calls QueryClosestPoints; else adds the closest point to a4 when its distance exceeds b's shape threshold, otherwise calls QueryClosestPoints.
// @fnv 0x00d339d0
// src: GUESS 0x00d339d0 (confidence: medium)
extern "C" void __cdecl hkpConvexListAgent_QueryClosestPointsAfterHullTest(int apBodyA, int apBodyB, int a3, int apCollector)
{
    {
        hkMonitorStream* pForm = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
        char* p = pForm->m_end.m_storage;
        if (p < pForm->m_capacityMinus16.m_storage)
        {
            *(const char**)p = "LtCvxList";
            *(const char**)(p + 12) = "StcheckHull";
            _ReadWriteBarrier();
            volatile unsigned int t = (unsigned int)__rdtsc();
            *(unsigned int*)(p + 4) = t;
            pForm->m_end.m_storage = p + 16;
        }
    }

    void* flagStorage[sizeof(hkpFlagCdBodyPairCollector) / sizeof(void*)];
    hkpFlagCdBodyPairCollector& flagCollector = *(hkpFlagCdBodyPairCollector*)flagStorage;
    *(const void**)&flagCollector = &DAT_010cebd0;
    flagCollector.m_flag = false;
    TestGsk((const void*)apBodyA, (const void*)apBodyB, (const void*)a3, &flagCollector);
    if (flagCollector.DidHit())
    {
        hkMonitorStream* pForm = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
        char* p = pForm->m_end.m_storage;
        if (p < pForm->m_capacityMinus16.m_storage)
        {
            *(const char**)p = "Stchildren";
            _ReadWriteBarrier();
            volatile unsigned int t = (unsigned int)__rdtsc();
            // Keep this timer read separate from the child-path timer read.
            _ReadWriteBarrier();
            *(unsigned int*)(p + 4) = t;
            pForm->m_end.m_storage = p + 12;
        }
        QueryClosestPoints((const void*)apBodyA, (const void*)apBodyB, (const void*)a3,
                           (hkpCdPointCollector*)apCollector);
    }
    else
    {
        // Pointer storage keeps the original stack layout and avoids constructors/destructors.
        __declspec(align(16)) void* closestStorage[sizeof(hkpClosestCdPointCollector) / sizeof(void*)];
        hkpClosestCdPointCollector& x = *(hkpClosestCdPointCollector*)closestStorage;
        x.m_kHitPoint.m_kPoint.m_vSeparatingNormal.m_vComponents.m128_f32[3] = DAT_0104da48;
        x.m_fEarlyOutDistance = DAT_0104da48;
        *(const void**)&x = &DAT_010c476c;
        x.m_kHitPoint.m_pRootCollidableA = 0;
        FUN_00dac450((const void*)apBodyA, (const void*)apBodyB, (const void*)a3, &x);
        if (!x.m_kHitPoint.m_pRootCollidableA)
        {
            goto timer_end;
        }
        const hkpConvexListShape* shapeB = (const hkpConvexListShape*)((const hkpCdBody*)apBodyB)->m_pCollisionShape;
        if (x.m_kHitPoint.m_kPoint.getDistance() > shapeB->m_minDistanceToUseConvexHull)
        {
            __declspec(align(16)) void* pointStorage[sizeof(ContactPointPair) / sizeof(void*)];
            ContactPointPair& point = *(ContactPointPair*)pointStorage;
            point.m_pBodyA = (const void*)apBodyA;
            point.m_pBodyB = (const void*)apBodyB;
            point.m_kPoint = x.m_kHitPoint.m_kPoint;
            ((hkpCdPointCollector*)apCollector)->AddCdPoint(point);
            goto timer_end;
        }
        hkMonitorStream* pForm = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
        char* p = pForm->m_end.m_storage;
        if (p < pForm->m_capacityMinus16.m_storage)
        {
            *(const char**)p = str_010cec28;
            _ReadWriteBarrier();
            volatile unsigned int t = (unsigned int)__rdtsc();
            *(unsigned int*)(p + 4) = t;
            pForm->m_end.m_storage = p + 12;
        }
        QueryClosestPoints((const void*)apBodyA, (const void*)apBodyB, (const void*)a3,
                           (hkpCdPointCollector*)apCollector);
    }

timer_end: {
    hkMonitorStream* pForm = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    char* p = pForm->m_end.m_storage;
    if (p < pForm->m_capacityMinus16.m_storage)
    {
        *(const char**)p = str_01076f38;
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        *(unsigned int*)(p + 4) = t;
        pForm->m_end.m_storage = p + 12;
    }
}
}

namespace fnv_00d33ca0 {
#include <intrin.h>

extern "C" __declspec(dllimport) unsigned long __stdcall TlsGetValue(unsigned long);
extern "C" void __cdecl hkpShapeCollectionAgent_staticLinearCast_UpdateState_00d34810(int, int, int, int, int);
extern "C" void __cdecl Object_ProcessEntries_00daf8e0(int, int, int, void*, void*);

extern int DAT_0126835c;
extern float DAT_0104da48;
extern int DAT_010cebe0;
extern char str_010cec54[];
extern char str_010cec34[];
extern char str_010cec4c[];
extern char str_01076f38[];

struct __declspec(align(16)) S00d33ca0_Local
{
    void* unk00;
    float unk04;
    char unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    volatile float unk2c;
};

// Writes a timer entry, calls FUN_00daf8e0, and if local.unk08 is set writes another entry and calls FUN_00d34810; then writes a closing timer entry.
// @fnv 0x00d33ca0
// src: HAVOK_LIB 0x00d33ca0
extern "C" void __cdecl hkpConvexListAgent_staticLinearCast(int a, int b, int c, int d, int e)
{
    hkMonitorStream* buf;
    unsigned int* p;
    volatile unsigned int ts;

    buf = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    p = (unsigned int*)buf->m_end.m_storage;
    if (p < (unsigned int*)buf->m_capacityMinus16.m_storage)
    {
        p[0] = (unsigned int)&str_010cec54[0];
        p[3] = (unsigned int)&str_010cec34[0];
        _ReadWriteBarrier();
        ts = __rdtsc();
        p[1] = ts;
        buf->m_end.m_storage = reinterpret_cast<char*>((hkMonitorStream::TimerCommand*)(p + 4));
    }

    {
        S00d33ca0_Local local;
        local.unk2c = DAT_0104da48;
        local.unk04 = DAT_0104da48;
        local.unk00 = &DAT_010cebe0;
        local.unk08 = 0;
        Object_ProcessEntries_00daf8e0(a, b, c, &local, &local);
        if (local.unk08 != 0)
        {
            buf = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
            p = (unsigned int*)buf->m_end.m_storage;
            if (p < (unsigned int*)buf->m_capacityMinus16.m_storage)
            {
                p[0] = (unsigned int)&str_010cec4c[0];
                _ReadWriteBarrier();
                ts = __rdtsc();
                p[1] = ts;
                buf->m_end.m_storage = reinterpret_cast<char*>((hkMonitorStream::TimerCommand*)(p + 3));
            }
            hkpShapeCollectionAgent_staticLinearCast_UpdateState_00d34810(a, b, c, d, e);
        }
    }

    buf = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    p = (unsigned int*)buf->m_end.m_storage;
    if (p < (unsigned int*)buf->m_capacityMinus16.m_storage)
    {
        p[0] = (unsigned int)&str_01076f38[0];
        _ReadWriteBarrier();
        ts = __rdtsc();
        p[1] = ts;
        buf->m_end.m_storage = reinterpret_cast<char*>((hkMonitorStream::TimerCommand*)(p + 3));
    }
}
}  // namespace fnv_00d33ca0

namespace fnv_00d34510 {
struct ChunkAllocator
{
    virtual void* vfunc0();
    virtual void* allocate(int size);
};

extern "C"
{
    hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
    void* __cdecl FUN_00dacbd0();
    void* __cdecl FUN_00d440f0();
    void* __cdecl FUN_00d33940();
}

typedef void*(__thiscall* PfnDacbd0)(void* self, void* bodyA, void* bodyB, void* contactMgr);
typedef void*(__thiscall* PfnD440f0)(void* self, void* bodyA, void* bodyB, void* input, void* contactMgr);
typedef void*(__thiscall* PfnD33940)(void* self, void* bodyA, void* bodyB, void* input, void* contactMgr);

// Dispatches on collision type to allocate and initialize the appropriate agent object for the given body pair and contact manager.
// @fnv 0x00d34510
// src: HAVOK_LIB 0x00d34510
void* __cdecl hkpConvexListAgent_createConvexListConvexListAgent(void* bodyA, void* bodyB, hkpCollisionInput* input, void* contactMgr)
{
    if (contactMgr)
    {
        switch (input->m_pConvexListCollisionFilter->ShouldBodiesCollide(
            *(const hkpCdBody*)bodyA, *(const hkpCdBody*)bodyB, *input))
        {
        case 0: {
            hkMemoryRouter* pMemoryRouter = hkMemoryRouter_getInstance();
            int iAllocSize = 0x90;
            void* agent = ((ChunkAllocator*)pMemoryRouter->m_heap)->allocate(iAllocSize);
            ((hkpCollisionAgent*)agent)->m_usMemSizeAndFlags = (unsigned short)iAllocSize;
            ((PfnD33940)FUN_00d33940)(agent, bodyB, bodyA, input, contactMgr);
            *(void**)agent = (void*)0x10cec68;
            return agent;
        }
        case 1: {
            hkMemoryRouter* pMemoryRouter = hkMemoryRouter_getInstance();
            int iAllocSize = 0x38;
            void* agent = ((ChunkAllocator*)pMemoryRouter->m_heap)->allocate(iAllocSize);
            ((hkpCollisionAgent*)agent)->m_usMemSizeAndFlags = (unsigned short)iAllocSize;
            return ((PfnD440f0)FUN_00d440f0)(agent, bodyA, bodyB, input, contactMgr);
        }
        case 2: {
            switch (input->m_pConvexListCollisionFilter->ShouldBodiesCollide(
                *(const hkpCdBody*)bodyB, *(const hkpCdBody*)bodyA, *input))
            {
            case 0: {
                hkMemoryRouter* pMemoryRouter = hkMemoryRouter_getInstance();
                int iAllocSize = 0x90;
                void* agent = ((ChunkAllocator*)pMemoryRouter->m_heap)->allocate(iAllocSize);
                ((hkpCollisionAgent*)agent)->m_usMemSizeAndFlags = (unsigned short)iAllocSize;
                return ((PfnD33940)FUN_00d33940)(agent, bodyA, bodyB, input, contactMgr);
            }
            case 1: {
                hkMemoryRouter* pMemoryRouter = hkMemoryRouter_getInstance();
                int iAllocSize = 0x38;
                void* agent = ((ChunkAllocator*)pMemoryRouter->m_heap)->allocate(iAllocSize);
                ((hkpCollisionAgent*)agent)->m_usMemSizeAndFlags = (unsigned short)iAllocSize;
                ((PfnD440f0)FUN_00d440f0)(agent, bodyB, bodyA, input, contactMgr);
                *(void**)agent = (void*)0x10ce8b0;
                return agent;
            }
            case 2: {
                hkMemoryRouter* pMemoryRouter = hkMemoryRouter_getInstance();
                int iAllocSize = 0x80;
                void* agent = ((ChunkAllocator*)pMemoryRouter->m_heap)->allocate(iAllocSize);
                ((hkpCollisionAgent*)agent)->m_usMemSizeAndFlags = (unsigned short)iAllocSize;
                ((PfnDacbd0)FUN_00dacbd0)(agent, bodyA, bodyB, contactMgr);
                *(void**)agent = (void*)0x10ceb94;
                return agent;
            }
            }
            break;
        }
        }
        return 0;
    }
    else
    {
        hkMemoryRouter* pMemoryRouter = hkMemoryRouter_getInstance();
        int iAllocSize = 0x38;
        void* agent = ((ChunkAllocator*)pMemoryRouter->m_heap)->allocate(iAllocSize);
        ((hkpCollisionAgent*)agent)->m_usMemSizeAndFlags = (unsigned short)iAllocSize;
        return ((PfnD440f0)FUN_00d440f0)(agent, bodyA, bodyB, input, 0);
    }
}
}  // namespace fnv_00d34510
