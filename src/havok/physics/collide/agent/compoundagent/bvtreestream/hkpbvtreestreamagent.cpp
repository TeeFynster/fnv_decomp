#include <xmmintrin.h>
typedef ::__m128 LocalM128;

// src/havok/physics/collide/agent/compoundagent/bvtreestream/hkpbvtreestreamagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/compoundagent/bvtreestream/hkpbvtreestreamagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkpBvTreeStreamAgent.h"
#include "../../../../../../../include/hkpSymmetricAgentFlipBodyCollector.h"
#include "../../../../../../../include/hkpSymmetricAgentFlipCollector.h"

extern "C" void __cdecl hkpBvTreeAgent_staticGetPenetrations(void*, void*, void*, void*);

// @fnv 0x00d2dd30
__declspec(noinline) void hkpBvTreeStreamAgent::getPenetrations(const hkpCdBody& apArg1, const hkpCdBody& apArg2, const CollisionAgentContext& apArg3, hkpCdBodyPairCollector& apArg4)
{
    hkpBvTreeAgent_staticGetPenetrations((void*)&apArg1, (void*)&apArg2, (void*)&apArg3, &apArg4);
}

extern "C" void __cdecl hkpAgent1nSector_ProcessEntries_00da3510(void* a, void* b);

// @fnv 0x00d2ddd0
void hkpBvTreeStreamAgent::RemovePoint(const CollisionAgentContext& aiValue)
{
    hkpAgent1nSector_ProcessEntries_00da3510(&m_kAgentNnTrack, (void*)&aiValue);
}

extern "C" void __cdecl hkpBvTreeAgent_staticGetClosestPoints(void*, void*, void*, void*);
// @fnv 0x00d2dd50
__declspec(noinline) void hkpBvTreeStreamAgent::getClosestPoints(const hkpCdBody& apArg1, const hkpCdBody& apArg2, const CollisionAgentContext& apArg3, hkpCdPointCollector& apArg4)
{
    hkpBvTreeAgent_staticGetClosestPoints((void*)&apArg1, (void*)&apArg2, (void*)&apArg3, &apArg4);
}

void __cdecl hkpBvTreeAgent_staticLinearCast(void*, void*, void*, void*, void*);
// Forwards all five arguments to FUN_00d30f50.
// @fnv 0x00d2dd70
__declspec(noinline) void hkpBvTreeStreamAgent::linearCast(const hkpCdBody& a, const hkpCdBody& b, const ShapeSweepParameters& c, hkpCdPointCollector& d, hkpCdPointCollector* e)
{
    hkpBvTreeAgent_staticLinearCast((void*)&a, (void*)&b, (void*)&c, &d, e);
}


extern void __cdecl hkAgent1nMachine_Destroy(void*, int, int, int);
// Cleans up the agent track, then invokes the deleting destructor through its virtual slot.
// @fnv 0x00d2dda0
void hkpBvTreeStreamAgent::cleanup(hkpConstraintOwner& value)
{
    hkAgent1nMachine_Destroy(&m_kAgentNnTrack, (int)m_pCollisionDispatcher, (int)m_pContactManager, (int)&value);
    typedef void (__thiscall* DeleteFunc)(hkpBvTreeStreamAgent*, int);
    (*(DeleteFunc**)this)[0](this, 1);
}

void __cdecl _hkAgent1nMachine_WarpTime(void* self, float a, float b, void* c);
// Calls FUN_00da35f0 with the subobject at offset 0x30 of this object and the three arguments.
// @fnv 0x00d2ddf0
void hkpBvTreeStreamAgent::WarpTime(hkTime a, hkTime b, const CollisionAgentContext& c)
{
    _hkAgent1nMachine_WarpTime(&m_kAgentNnTrack, a, b, (void*)&c);
}

struct BSAudio;
BSAudio* __cdecl hkMemoryRouter_getInstance();
inline hkMemoryRouter* audio()
{
    return (hkMemoryRouter*)hkMemoryRouter_getInstance();
}

struct RefObj
{
    void* vtbl;
    short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

inline void* __cdecl operator new(unsigned int, void* p)
{
    return p;
}

inline void* hkAlloc(int n)
{
    RefObj* p = (RefObj*)audio()->heap().blockAlloc(n);
    p->m_usMemSizeAndFlags = (short)n;
    return p;
}

// Allocates and constructs a stream agent from the audio heap.
// @fnv 0x00d2df50
// src: HAVOK_LIB 0x00d2df50
void* __cdecl hkpBvTreeStreamAgent_createShapeBvAgent(int aiArg0, int aiArg1, int aiArg2, int aiArg3)
{
    return ::new (hkAlloc(sizeof(hkpBvTreeStreamAgent))) hkpBvTreeStreamAgent((void*)aiArg0, (void*)aiArg1, (void*)aiArg2, (void*)aiArg3);
}

void hkpBvTreeStreamAgent_createBvTreeShapeAgent();
void hkpSymmetricAgentFlipBodyCollector_UpdateState_00d2e970();
void hkpSymmetricAgentFlipCollector_UpdateState_00d2e9b0();
void hkpBvTreeAgent_staticLinearCast_UpdateState_00d2e9f0();
void hkpBvTreeStreamAgent_createShapeBvAgent();

void hkpBvTreeAgent_staticGetClosestPoints();
void hkpBvTreeAgent_staticLinearCast();
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
// @fnv 0x00d2e760
// src: XBOX_PDB 0x00d2e760
void hkpBvTreeStreamAgent_registerMultiRayAgent(Registry* registry)
{
    Conversion conversionEntry;
    conversionEntry.convert = hkpBvTreeStreamAgent_createBvTreeShapeAgent;
    conversionEntry.create = hkpSymmetricAgentFlipBodyCollector_UpdateState_00d2e970;
    conversionEntry.copy = hkpSymmetricAgentFlipCollector_UpdateState_00d2e9b0;
    conversionEntry.destroy = hkpBvTreeAgent_staticLinearCast_UpdateState_00d2e9f0;
    conversionEntry.enabled = true;
    conversionEntry.supported = true;
    registry->AppendRecordAndRegisterAgents(&conversionEntry, 8, 24);
    conversionEntry.convert = hkpBvTreeStreamAgent_createShapeBvAgent;
    conversionEntry.create = (void (*)())hkpBvTreeAgent_staticGetPenetrations;
    conversionEntry.copy = hkpBvTreeAgent_staticGetClosestPoints;
    conversionEntry.destroy = hkpBvTreeAgent_staticLinearCast;
    conversionEntry.enabled = false;
    conversionEntry.supported = true;
    registry->AppendRecordAndRegisterAgents(&conversionEntry, 24, 8);
}

typedef void*(__cdecl* S_00d2e8e0_CreateFunc)(void*, void*, void*, void*);
typedef void(__cdecl* S_00d2e8e0_GetPenetrationsFunc)(void*, void*, void*, void*);
typedef void(__cdecl* S_00d2e8e0_GetClosestPointsFunc)(void*, void*, void*, void*);
typedef void(__cdecl* S_00d2e8e0_LinearCastFunc)(void*, void*, void*, void*, void*);

void* hkpBvTreeStreamAgent_dispatchBvTreeConvexList(void*, void*, void*, void*);
void hkpSymmetricAgentFlipBodyCollector_UpdateState_00d2e970(void*, void*, void*, void*);
void hkpSymmetricAgentFlipCollector_UpdateState_00d2e9b0(void*, void*, void*, void*);
void hkpBvTreeAgent_staticLinearCast_UpdateState_00d2e9f0(void*, void*, void*, void*, void*);
void* hkpBvTreeStreamAgent_dispatchConvexListBvTree(void*, void*, void*, void*);
void hkpBvTreeAgent_staticGetClosestPoints(void*, void*, void*, void*);
void hkpBvTreeAgent_staticLinearCast(void*, void*, void*, void*, void*);

struct S_00d2e8e0_AgentFuncs
{
    S_00d2e8e0_CreateFunc m_pCreateFunc;
    S_00d2e8e0_GetPenetrationsFunc m_pQueryPenetrationsFunc;
    S_00d2e8e0_GetClosestPointsFunc m_pGetPenetrationsFunc;
    S_00d2e8e0_LinearCastFunc m_pLinearCastFunc;
    bool m_bIsFlipped;
    bool m_bIsPredictive;
};

struct S_00d2e8e0_Dispatcher
{
    void AppendRecordAndRegisterAgents(S_00d2e8e0_AgentFuncs& f, int typeA, int typeB);
};

// Fills an agent function table twice and registers it with the dispatcher for type pairs (8,0x16) and (0x16,8).
// @fnv 0x00d2e8e0
// src: GUESS 0x00d2e8e0 (confidence: medium)
void Object_RegisterSymmetricAgentFunctions(S_00d2e8e0_Dispatcher* dispatcher)
{
    S_00d2e8e0_AgentFuncs f;
    f.m_pCreateFunc = hkpBvTreeStreamAgent_dispatchBvTreeConvexList;
    f.m_pQueryPenetrationsFunc = hkpSymmetricAgentFlipBodyCollector_UpdateState_00d2e970;
    f.m_pGetPenetrationsFunc = hkpSymmetricAgentFlipCollector_UpdateState_00d2e9b0;
    f.m_pLinearCastFunc = hkpBvTreeAgent_staticLinearCast_UpdateState_00d2e9f0;
    f.m_bIsFlipped = true;
    f.m_bIsPredictive = true;
    dispatcher->AppendRecordAndRegisterAgents(f, 8, 0x16);

    f.m_pCreateFunc = hkpBvTreeStreamAgent_dispatchConvexListBvTree;
    f.m_pQueryPenetrationsFunc = (S_00d2e8e0_GetPenetrationsFunc)hkpBvTreeAgent_staticGetPenetrations;
    f.m_pGetPenetrationsFunc = hkpBvTreeAgent_staticGetClosestPoints;
    f.m_pLinearCastFunc = hkpBvTreeAgent_staticLinearCast;
    f.m_bIsFlipped = false;
    f.m_bIsPredictive = true;
    dispatcher->AppendRecordAndRegisterAgents(f, 0x16, 8);
}

// Raw stack storage preserves these wrappers' original lack of constructor and destructor calls.
extern float g_D2E9B0MaxDistance;
extern unsigned char DAT_010ce7fc;
void __cdecl hkpBvTreeAgent_staticGetClosestPoints(int a, int b, int c, hkpCdPointCollector* collector);

// @fnv 0x00d2e9b0
// src: GUESS 0x00d2e9b0 (confidence: low)
void __cdecl hkpSymmetricAgentFlipCollector_UpdateState_00d2e9b0(int aiArg1, int aiArg2, int aiArg3, int aiData)
{
    unsigned int storage[sizeof(hkpSymmetricAgentFlipCollector) / sizeof(unsigned int)];
    hkpSymmetricAgentFlipCollector& collector = *(hkpSymmetricAgentFlipCollector*)storage;
    collector.m_fEarlyOutDistance = g_D2E9B0MaxDistance;
    collector.unk08 = (void*)aiData;
    *(void**)&collector = &DAT_010ce7fc;
    hkpBvTreeAgent_staticGetClosestPoints(aiArg2, aiArg1, aiArg3, &collector);
}

extern float DAT_0104da48;

struct Context
{
    void hkpShapeCollectionAgent_getClosestPoints(void* first, void* second, void* third, hkpSymmetricAgentFlipCollector* collector);
    void UpdateState_00d2edd0(void* first, void* second, void* third, void* fourth);
};
// Builds a collector with early-out distance DAT_0104da48 and payload fourth, then calls FUN_00d43880 with second, first, third and the collector.
// @fnv 0x00d2edd0
// src: GUESS 0x00d2edd0 (confidence: low)
void Context::UpdateState_00d2edd0(void* first, void* second, void* third, void* fourth)
{
    unsigned int storage[sizeof(hkpSymmetricAgentFlipCollector) / sizeof(unsigned int)];
    hkpSymmetricAgentFlipCollector& collector = *(hkpSymmetricAgentFlipCollector*)storage;
    *(void**)&collector = &DAT_010ce7fc;
    collector.m_fEarlyOutDistance = DAT_0104da48;
    collector.unk08 = fourth;
    hkpShapeCollectionAgent_getClosestPoints(second, first, third, &collector);
}

extern "C" void* __cdecl hkStatisticsCollector_getAllocatedSize(void* ptr, unsigned int size);
extern "C" void __cdecl hkpAgentMachineUtil_calc1nStatistics(void* a, int b, void* c);
extern "C" const char str_010ce828[];

struct VisitTarget
{
    virtual void v00()
    {}
    virtual void v01()
    {}
    virtual void v02()
    {}
    virtual void v03()
    {}
    virtual void v04()
    {}
    virtual void Visit(int kind, const char* name, void* data, unsigned int size, void* extra)
    {}
    int unk04;
    int m_08;
    int unk0C;
    unsigned char m_10;
};

// @fnv 0x00d2de90
void hkpBvTreeStreamAgent::calcContentStatistics(hkStatisticsCollector* collector, const hkClass* cls) const
{
    VisitTarget* target = (VisitTarget*)collector;
    hkArray<hkpAgent1nSector*>* pBuffer = const_cast<hkArray<hkpAgent1nSector*>*>(&m_kAgentNnTrack.m_kSectors);
    unsigned int uiFlags = pBuffer->m_iCapacityState;
    if ((uiFlags & 0x80000000u) == 0 || target->m_10 != 0)
    {
        void* p = pBuffer->m_data;
        unsigned int uiByteSize = (uiFlags & 0x3fffffffu) * 4;
        void* mem = hkStatisticsCollector_getAllocatedSize(p, uiByteSize);
        target->Visit(3, str_010ce828, pBuffer->m_data, pBuffer->m_iElementCount * 4, mem);
    }
    hkpAgentMachineUtil_calc1nStatistics(pBuffer, target->m_08, target);
}

extern "C" const void* DAT_010ce81c;

// Builds a flip-body collector on the stack with the given collector and vtable, then calls FUN_00d312f0 with bodyB, bodyA, arg3 and the Collector.
// @fnv 0x00d2e970
// src: GUESS 0x00d2e970 (confidence: low)
void __cdecl hkpSymmetricAgentFlipBodyCollector_UpdateState_00d2e970(void* bodyA, void* bodyB, void* arg3, void* orig_collector)
{
    unsigned int storage[sizeof(hkpSymmetricAgentFlipBodyCollector) / sizeof(unsigned int)];
    hkpSymmetricAgentFlipBodyCollector& c = *(hkpSymmetricAgentFlipBodyCollector*)storage;
    c.payload = orig_collector;
    c.unk04[0] = 0;
    *(const void**)&c = &DAT_010ce81c;
    hkpBvTreeAgent_staticGetPenetrations(bodyB, bodyA, arg3, &c);
}

struct FUN_00d2eb50_nib
{
    unsigned char lo : 4;
    unsigned char hi : 4;
};

struct FUN_00d2eb50_cls
{
    unsigned short m_w00;
    unsigned short m_w02;
    unsigned short m_w04;
    unsigned char m_unk06;
    unsigned char m_unk07;
    unsigned char m_b08;
    unsigned char m_b09;
    FUN_00d2eb50_nib m_nib0a;
    void __thiscall SwapFields();
};

// @fnv 0x00d2eb50
void FUN_00d2eb50_cls::SwapFields()
{
    unsigned char lo = m_nib0a.lo;
    m_nib0a.lo = m_nib0a.hi;
    m_nib0a.hi = lo;

    unsigned char t = m_b08;
    m_b08 = m_b09;
    m_b09 = t;

    unsigned short* w = (unsigned short*)this;
    unsigned int uiIndex = (unsigned int)m_b08 + (unsigned int)m_b09 - 1;
    unsigned short first = w[0];
    unsigned short usTemp = w[uiIndex];
    w[0] = usTemp;
    w[uiIndex] = first;

    if ((unsigned char)(m_b08 & m_b09) == 2)
    {
        unsigned short a = m_w02;
        m_w02 = m_w04;
        m_w04 = a;
    }
}

namespace fnv_00d2ebb0 {
extern char DAT_010ce81c;

struct FUN_00d2ebb0_cls
{
    void __thiscall DispatchWithFlag(void* a1, void* a2, void* a3, unsigned int a4);
};

// Builds a temporary holding a4 and a zero flag with a vtable pointer, then forwards a2, a1, a3 and the temporary to FUN_00d2dd30.
// @fnv 0x00d2ebb0
void FUN_00d2ebb0_cls::DispatchWithFlag(void* a1, void* a2, void* a3, unsigned int a4)
{
    unsigned int storage[sizeof(hkpSymmetricAgentFlipBodyCollector) / sizeof(unsigned int)];
    hkpSymmetricAgentFlipBodyCollector& t = *(hkpSymmetricAgentFlipBodyCollector*)storage;
    t.payload = (void*)a4;
    t.unk04[0] = 0;
    *(const void**)&t = &DAT_010ce81c;
    ((hkpBvTreeStreamAgent*)this)->hkpBvTreeStreamAgent::getPenetrations(*(const hkpCdBody*)a2, *(const hkpCdBody*)a1, *(const CollisionAgentContext*)a3, *(hkpCdBodyPairCollector*)&t);
}
}  // namespace fnv_00d2ebb0

extern float DAT_0104da48;
extern unsigned char DAT_010ce7fc;
struct CpuObject
{
    void DispatchWithBoundData(void*, void*, unsigned int, unsigned int);
};
// Builds a flip collector from fourth, DAT_0104da48 and DAT_010ce7fc, then forwards second, first, third and the data to FUN_00d2dd50.
// @fnv 0x00d2ebf0
void CpuObject::DispatchWithBoundData(void* first, void* second, unsigned int third, unsigned int fourth)
{
    unsigned int storage[sizeof(hkpSymmetricAgentFlipCollector) / sizeof(unsigned int)];
    hkpSymmetricAgentFlipCollector& data = *(hkpSymmetricAgentFlipCollector*)storage;
    data.unk08 = (void*)fourth;
    data.m_fEarlyOutDistance = DAT_0104da48;
    *(void**)&data = &DAT_010ce7fc;
    ((hkpBvTreeStreamAgent*)this)->hkpBvTreeStreamAgent::getClosestPoints(*(const hkpCdBody*)second, *(const hkpCdBody*)first, *(const CollisionAgentContext*)third, data);
}

struct SearchObject
{
    void CallTarget(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3);
};
// @fnv 0x00d2ec30
void SearchObject::CallTarget(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3)
{
    ((hkpBvTreeStreamAgent*)this)->hkpBvTreeStreamAgent::ProcessContactPoints(*(const hkpCdBody*)arg1, *(const hkpCdBody*)arg0, *(const CollisionAgentContext*)arg2, *(hkpConstraintOwner*)arg3);
}

namespace fnv_00d2ed70 {
struct CallTarget_00d43f10
{
    int hkpShapeCollectionAgent_updateShapeCollectionFilter(int, int, int, int);
};
struct SearchObject
{
    int UpdateState_00d2ed70(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3);
};
// @fnv 0x00d2ed70
// src: GUESS 0x00d2ed70 (confidence: low)
int SearchObject::UpdateState_00d2ed70(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3)
{
    unsigned int callResult0 =
        (unsigned int)((CallTarget_00d43f10*)this)->hkpShapeCollectionAgent_updateShapeCollectionFilter((int)arg1, (int)arg0, (int)arg2, (int)arg3);
    return (int)callResult0;
}
}  // namespace fnv_00d2ed70

// Game side wrapper that fills the collector and hands it to the query routine.
struct FUN_00d43cd0_class
{
    void __thiscall ProcessCollisionEntries(void* a, void* b, void* c, void* d);
    void __thiscall UpdateState_00d2ed90(void* a1, void* a2, void* a3, void* a4);
};

// Builds a flip-body collector holding a4 and forwards a2, a1, a3 and the collector to ProcessCollisionEntries.
// @fnv 0x00d2ed90
// src: GUESS 0x00d2ed90 (confidence: low)
void __thiscall FUN_00d43cd0_class::UpdateState_00d2ed90(void* a1, void* a2, void* a3, void* apPayload)
{
    unsigned int storage[sizeof(hkpSymmetricAgentFlipBodyCollector) / sizeof(unsigned int)];
    hkpSymmetricAgentFlipBodyCollector& collector = *(hkpSymmetricAgentFlipBodyCollector*)storage;
    collector.unk04[0] = 0;
    *(const void**)&collector = &DAT_010ce81c;
    collector.payload = apPayload;
    this->ProcessCollisionEntries(a2, a1, a3, &collector);
}

#include <xmmintrin.h>
extern "C" void __cdecl hkAgent1nMachine_UpdateShapeCollectionFilter(void* a, void* b);

struct FUN_00d2de20_obj
{
    virtual void vSlot00();
    virtual void vSlot04();
    virtual void vSlot08();
    virtual void vSlot0C();
    virtual int vSlot10();
};

struct __declspec(align(16)) ArgPack
{
    int m_00;
    void* m_04;
    int unk08;
    int m_0C;
    int m_10;
    int m_14;
    int m_18;
};

// The raw entry retains the scalar stack arguments used by ProcessContactPoints.
// An unused EDX parameter gives this helper the original ECX and stack calling convention.
// @fnv 0x00d2de20
// src: HAVOK_SRC 0x00d2de20
void __fastcall hkpBvTreeStreamAgent_updateShapeCollectionFilter(hkpBvTreeStreamAgent* self, void*, int a0, FUN_00d2de20_obj** a1, int a2, int a3)
{
    self->m_kBoundingBox.m_kMinimumCorner.m_vComponents = _mm_setzero_ps();
    self->m_kBoundingBox.m_kMaximumCorner.m_vComponents = _mm_setzero_ps();
    ArgPack args;
    int r = (*a1)->vSlot10();
    args.m_00 = a0;
    args.m_04 = a1;
    args.m_10 = a2;
    args.m_14 = (int)self->m_pContactManager;
    args.m_0C = r;
    args.m_18 = a3;
    hkAgent1nMachine_UpdateShapeCollectionFilter(&self->m_kAgentNnTrack, &args);
}

extern int DAT_010ce838;
extern "C" void __cdecl InitBlockPool(void* p);

// Raw constructor entry: initialize the shared fields without implicit base or hkAabb constructor calls.
// EDX is unused, preserving the original constructor's ECX and stack calling convention.
// @fnv 0x00d2def0
// src: XBOX_PDB 0x00d2def0
hkpBvTreeStreamAgent* __fastcall hkpBvTreeStreamAgent_hkpBvTreeStreamAgent(hkpBvTreeStreamAgent* self, void*, void* a1, void* apUnused, int* piSource, int a4)
{
    self->m_sReferenceCount = 1;
    self->m_pContactManager = (hkpContactMgr*)a4;
    *(int*)self = (int)&DAT_010ce838;
    int* pBlockPool = (int*)&self->m_kAgentNnTrack;
    *pBlockPool = 0;
    pBlockPool[1] = 0;
    pBlockPool[2] = 0x80000000;
    self->m_pCollisionDispatcher = (hkpCollisionDispatcher*)*piSource;
    self->m_kBoundingBox.m_kMinimumCorner.m_vComponents = _mm_setzero_ps();
    self->m_kBoundingBox.m_kMaximumCorner.m_vComponents = _mm_setzero_ps();
    InitBlockPool(pBlockPool);
    return self;
}

extern float DAT_0104da48;
extern const LocalM128 DAT_010c44d0;
extern unsigned int DAT_010ce80c;

struct __declspec(align(16)) Key_d2e9
{
    unsigned int m_k0;
    unsigned int m_k1;
    unsigned int m_k2;
    unsigned int m_k3;
};

struct Input_d2e9
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    int unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    union
    {
        LocalM128 m_vComponents;
        Key_d2e9 m_key;
    };
    int unk60, unk64, unk68, unk6c;
};

struct Record_d2e9
{
    const unsigned int* m_vtbl;
    float m_fScalar;
    Key_d2e9 m_key;
    int m_uiFilterValue;
};

void __cdecl hkpBvTreeAgent_staticLinearCast(int a1, int a2, Input_d2e9* input, Record_d2e9* rec, Record_d2e9* optRec);

// Copies input, XORs its m_vComponents with DAT_010c44d0, builds a Record_d2e9 with a4, and calls FUN_00d30f50 with an optional second record when a5 is non-zero.
// @fnv 0x00d2e9f0
// src: GUESS 0x00d2e9f0 (confidence: low)
void __cdecl hkpBvTreeAgent_staticLinearCast_UpdateState_00d2e9f0(int a2, int a1, const Input_d2e9* input, int aiRecordValue, int aiOptionalRecordValue)
{
    Input_d2e9 local = *input;
    local.m_vComponents = _mm_xor_ps(input->m_vComponents, DAT_010c44d0);

    Record_d2e9 rec;
    rec.m_vtbl = &DAT_010ce80c;
    rec.m_fScalar = DAT_0104da48;
    rec.m_key = input->m_key;
    rec.m_uiFilterValue = aiRecordValue;

    if (aiOptionalRecordValue != 0)
    {
        Record_d2e9 rec2;
        rec2.m_vtbl = &DAT_010ce80c;
        rec2.m_fScalar = DAT_0104da48;
        rec2.m_key = input->m_key;
        rec2.m_uiFilterValue = aiOptionalRecordValue;
        hkpBvTreeAgent_staticLinearCast(a1, a2, &local, &rec, &rec2);
    }
    else
    {
        hkpBvTreeAgent_staticLinearCast(a1, a2, &local, &rec, 0);
    }
}

namespace fnv_00d2ec50 {
typedef ::__m128 LocalM128;
extern "C"
{
using ::_mm_shuffle_ps;
using ::_mm_mul_ps;
using ::_mm_add_ps;
using ::_mm_xor_ps;
}

extern LocalM128 DAT_010c4c00;

struct SimplexVertex
{
    LocalM128 m_kPointA;
    LocalM128 m_kPointB;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
};

struct DimNibbles
{
    unsigned char m_ucLowNibble : 4;
    unsigned char m_ucHighNibble : 4;
};

struct Simplex
{
    SimplexVertex* m_kRayEnd;
    int unk04;
    int unk08;
    int unk0C;
    SimplexVertex m_kVertices[256];
    int unk3010;
    int unk3014;
    int unk3018;
    int unk301C;
    LocalM128 m_vHitNormal;
    float m_fClosestPointDistanceSquared;
    int unk3034;
    int unk3038;
    int unk303C;
    unsigned short m_ids[4];
    unsigned char m_ucDimensionA;
    unsigned char m_ucDimensionB;
    DimNibbles m_dims;
};

struct AgentBase
{
    void FUN_00d2df90(int a, int b, int c, Simplex* s);
};

struct Agent : AgentBase
{
    void ProcessEntries_00d2ec50(int a, int b, int c, Simplex* s);
};

// Calls base FUN_00d2df90 with a and b swapped, post-processes the new simplex vertices, and swaps the dimension fields and ids if the closest distance changed.
// @fnv 0x00d2ec50
// src: GUESS 0x00d2ec50 (confidence: low)
void Agent::ProcessEntries_00d2ec50(int a, int b, int c, Simplex* apSimplex)
{
    SimplexVertex* v = apSimplex->m_kRayEnd;
    float oldDistance = apSimplex->m_fClosestPointDistanceSquared;
    AgentBase::FUN_00d2df90(b, a, c, apSimplex);
    for (; v < apSimplex->m_kRayEnd; v++)
    {
        const LocalM128* pb = &v->m_kPointB;
        LocalM128 w = _mm_shuffle_ps(*pb, *pb, 0xff);
        v->m_kPointA = _mm_add_ps(_mm_mul_ps(w, v->m_kPointB), v->m_kPointA);
        v->m_kPointB = _mm_xor_ps(v->m_kPointB, DAT_010c4c00);
    }
    if (oldDistance != apSimplex->m_fClosestPointDistanceSquared)
    {
        LocalM128* n = &apSimplex->m_vHitNormal;
        *n = _mm_xor_ps(*n, DAT_010c4c00);
        {
            unsigned char t = apSimplex->m_dims.m_ucLowNibble;
            apSimplex->m_dims.m_ucLowNibble = apSimplex->m_dims.m_ucHighNibble;
            apSimplex->m_dims.m_ucHighNibble = t;
        }
        {
            unsigned char t = apSimplex->m_ucDimensionA;
            apSimplex->m_ucDimensionA = apSimplex->m_ucDimensionB;
            apSimplex->m_ucDimensionB = t;
        }
        int last = apSimplex->m_ucDimensionA + apSimplex->m_ucDimensionB - 1;
        unsigned short usId0 = apSimplex->m_ids[0];
        apSimplex->m_ids[0] = apSimplex->m_ids[last];
        apSimplex->m_ids[last] = usId0;
        if ((apSimplex->m_ucDimensionA & apSimplex->m_ucDimensionB) == 2)
        {
            unsigned short usId1 = apSimplex->m_ids[1];
            apSimplex->m_ids[1] = apSimplex->m_ids[2];
            apSimplex->m_ids[2] = usId1;
        }
    }
}
}  // namespace fnv_00d2ec50

namespace fnv_00d2ef30 {
extern float DAT_0104da48;
extern unsigned int DAT_010c44d0;
extern unsigned int DAT_010ce80c;

struct Head50
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
};

// Exe 0x00d2ef30: unit-local Vector4f view; declarations and layout are preserved.
struct HkpbvtreestreamagentVector4fView
{
    int x, y, z, w;
};

struct Tail10
{
    int unk00, unk04, unk08, unk0c;
};

struct QueryCtx
{
    Head50 head;
    HkpbvtreestreamagentVector4fView vec;
    Tail10 tail;
};

struct Handle
{
    int value;
};

__declspec(align(16)) struct QueryObj
{
    const void* vtable;
    float scale;
    int unk08;
    int unk0c;
    HkpbvtreestreamagentVector4fView vec;
    int extra;
    void Init(const HkpbvtreestreamagentVector4fView& v, int e)
    {
        vtable = &DAT_010ce80c;
        scale = DAT_0104da48;
        vec = v;
        extra = e;
    }
};

// ABI overload for the original by-value handles; EDX is ignored by the base method.
void __fastcall StreamLinearCastAbi(hkpBvTreeStreamAgent*, hkpBvTreeStreamAgent*, Handle, Handle, void*, void*, void*);

struct SymmetricStreamCast
{
    void __thiscall UpdateState_00d2ef30(Handle p1, Handle p2, QueryCtx* ctx, int e1, int e2);
};

// @fnv 0x00d2ef30
// src: GUESS 0x00d2ef30 (confidence: low)
void __thiscall SymmetricStreamCast::UpdateState_00d2ef30(Handle p1, Handle p2, QueryCtx* ctx, int aiExtra1, int aiExtra2)
{
    QueryObj q2;
    QueryObj q1;
    float s = DAT_0104da48;
    LocalM128 v = *(const LocalM128*)&ctx->vec;
    q1.scale = s;
    LocalM128 neg = _mm_xor_ps(v, *(const LocalM128*)&DAT_010c44d0);
    QueryCtx local = *ctx;
    *(LocalM128*)&local.vec = neg;
    q1.vec = ctx->vec;
    q1.extra = aiExtra1;
    q1.vtable = &DAT_010ce80c;
    if (aiExtra2)
    {
        q2.Init(ctx->vec, aiExtra2);
        StreamLinearCastAbi((hkpBvTreeStreamAgent*)this, (hkpBvTreeStreamAgent*)this, p2, p1, &local, &q1, &q2);
    }
    else
    {
        StreamLinearCastAbi((hkpBvTreeStreamAgent*)this, (hkpBvTreeStreamAgent*)this, p2, p1, &local, &q1, 0);
    }
}
}  // namespace fnv_00d2ef30

namespace fnv_00d2f000 {
extern float DAT_0104da48;
extern LocalM128 DAT_010c44d0;

struct S_00d2f000_V4
{
    unsigned x, y, z, w;
};

struct S_00d2f000_Input
{
    unsigned unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38,
        unk3C, unk40, unk44, unk48, unk4C;
    union
    {
        LocalM128 m_q50;
        S_00d2f000_V4 m_v50;
    };
    unsigned unk60, unk64, unk68, unk6C;
};

struct S_00d2f000_Base
{
    float m_f04;
    unsigned unk08, unk0C;
    S_00d2f000_V4 m_v10;
    unsigned m_p20;
    unsigned unk24, unk28, unk2C;
    S_00d2f000_Base()
    {}
    S_00d2f000_Base(float f, const S_00d2f000_V4& v, unsigned p)
    {
        m_f04 = f;
        m_v10 = v;
        m_p20 = p;
    }
};

struct __declspec(align(16)) S_00d2f000_Flip : public S_00d2f000_Base
{
    S_00d2f000_Flip()
    {}
    S_00d2f000_Flip(float f, const S_00d2f000_V4& v, unsigned p) : S_00d2f000_Base(f, v, p)
    {}
    virtual void vtbl00(void);
    virtual void vtbl04(void);
};

struct FUN_00d2f000_class
{
    void linearCast(unsigned a, unsigned b, S_00d2f000_Input* c, void* d, void* e);
    void LinearCastFlip(unsigned a1, unsigned a2, S_00d2f000_Input* in, unsigned a4, unsigned a5);
};

// Copies in with its vector at +0x50 sign-flipped, builds a record from a4 (and a5 if non-zero), and calls linearCast(a2, a1, ...).
// @fnv 0x00d2f000
void FUN_00d2f000_class::LinearCastFlip(unsigned a1, unsigned a2, S_00d2f000_Input* in, unsigned a4, unsigned a5)
{
    LocalM128 v = in->m_q50;
    LocalM128 mask = DAT_010c44d0;
    S_00d2f000_Input local = *in;
    local.m_q50 = _mm_xor_ps(v, mask);
    S_00d2f000_Flip fr;
    fr.m_f04 = DAT_0104da48;
    fr.m_v10 = in->m_v50;
    fr.m_p20 = a4;

    if (a5 != 0)
    {
        S_00d2f000_Flip fl;
        fl.m_f04 = DAT_0104da48;
        fl.m_v10 = in->m_v50;
        fl.m_p20 = a5;
        this->linearCast(a2, a1, &local, &fr, &fl);
    }
    else
        this->linearCast(a2, a1, &local, &fr, 0);
}
}  // namespace fnv_00d2f000

struct Allocator
{
    virtual void unk00();
    virtual void* Alloc(unsigned int size);
};

namespace fnv_00d2e5a0 {

hkMemoryRouter* hkMemoryRouter_getInstance();

struct Dispatch
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual int Select(void* a, void* b, void* c);
};

struct Arg3Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Dispatch* m_pDispatch;
};

struct FUN_00d440f0_cls
{
    void* FUN_00d440f0(void* a, void* b, void* c, void* d);
};

struct SpawnedObject
{
    virtual ~SpawnedObject() throw()
    {}
    unsigned short m_iElementCount;
};

// Allocates and constructs a 0x40 or 0x38 byte object chosen by a3's Select(a1, a2, a3) when a4 is non-zero; with a4 zero it builds a 0x40 one and destructs it.
// @fnv 0x00d2e5a0
// src: HAVOK_LIB 0x00d2e5a0
void* hkpBvTreeStreamAgent_dispatchConvexListBvTree(void* a1, void* a2, void* a3, void* a4)
{
    if (a4 != 0)
    {
        Arg3Obj* o3 = (Arg3Obj*)a3;
        int r = o3->m_pDispatch->Select(a1, a2, a3);
        switch (r)
        {
        case 0:
        case 2: {
            hkMemoryRouter* holder = hkMemoryRouter_getInstance();
            Allocator* pAllocator = reinterpret_cast<Allocator*>(holder->m_heap);
            SpawnedObject* obj = (SpawnedObject*)pAllocator->Alloc(0x40);
            obj->m_iElementCount = 0x40;
            return (::new (obj) hkpBvTreeStreamAgent(a1, a2, a3, a4));
        }
        case 1: {
            hkMemoryRouter* holder = hkMemoryRouter_getInstance();
            Allocator* pAllocator = reinterpret_cast<Allocator*>(holder->m_heap);
            SpawnedObject* obj = (SpawnedObject*)pAllocator->Alloc(0x38);
            obj->m_iElementCount = 0x38;
            return ((FUN_00d440f0_cls*)obj)->FUN_00d440f0(a1, a2, a3, a4);
        }
        default:
            return 0;
        }
    }

    hkMemoryRouter* holder = hkMemoryRouter_getInstance();
    Allocator* pAllocator = reinterpret_cast<Allocator*>(holder->m_heap);
    SpawnedObject* obj = (SpawnedObject*)pAllocator->Alloc(0x40);
    obj->m_iElementCount = 0x40;
    ::new (obj) hkpBvTreeStreamAgent(a2, a1, a3, 0);
    obj->SpawnedObject::~SpawnedObject();
    return obj;
}
}  // namespace fnv_00d2e5a0

struct AllocationManager
{
    virtual void* GetHeap();
    virtual void* Allocate(unsigned int size);
};

struct GlobalOwner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    AllocationManager* allocator;
};

// local form of hkpSymmetricAgent: 0x00d2e680 needs the inline swapped-argument Agent constructor and Agent base (shared form has no matching compiled factory).
template <class Agent> struct SymmetricAgentLocal_hkpbvtreestreamagent : Agent
{
    SymmetricAgentLocal_hkpbvtreestreamagent(void* a, void* b, void* c, void* d) : Agent(b, a, c, d)
    {}
    virtual void Destroy();
};

// Allocates 0x40 bytes from the global owner's allocator, sets the size field at offset 4, and constructs a SymmetricAgentLocal_hkpbvtreestreamagent<hkpBvTreeStreamAgent> in place.
// @fnv 0x00d2e680
// src: HAVOK_LIB 0x00d2e680
SymmetricAgentLocal_hkpbvtreestreamagent<hkpBvTreeStreamAgent>* __cdecl hkpBvTreeStreamAgent_createBvTreeShapeAgent(void* a, void* b, void* c, void* d)
{
    GlobalOwner* owner = (GlobalOwner*)hkMemoryRouter_getInstance();
    void* object = owner->allocator->Allocate(0x40);
    *(unsigned short*)((char*)object + 4) = 0x40;
    return ::new (object) SymmetricAgentLocal_hkpbvtreestreamagent<hkpBvTreeStreamAgent>(a, b, c, d);
}

namespace fnv_00d2e6d0 {
struct RegEntry
{
    void* fn0;
    void* fn1;
    void* fn2;
    void* fn3;
    bool b0;
    bool b1;
};

struct TargetClass
{
    void __thiscall AppendRecordAndRegisterAgents(RegEntry* entry, int a, int b);
};

extern "C"
{
    void hkpBvTreeStreamAgent_createBvTreeShapeAgent();
    void hkpSymmetricAgentFlipBodyCollector_UpdateState_00d2e970();
    void hkpSymmetricAgentFlipCollector_UpdateState_00d2e9b0();
    void hkpBvTreeAgent_staticLinearCast_UpdateState_00d2e9f0();

    void hkpBvTreeStreamAgent_createShapeBvAgent();
    void hkpBvTreeAgent_staticGetClosestPoints();
    void hkpBvTreeAgent_staticLinearCast();
}

// Fills a RegEntry with four function pointers and two flags and passes it to obj->FUN_00cfbbe0 with (8, 0x12), then again with different pointers and (0x12, 8).
// @fnv 0x00d2e6d0
// src: HAVOK_LIB 0x00d2e6d0
void __cdecl hkpBvTreeStreamAgent_registerAgent(TargetClass* obj)
{
    RegEntry entry;
    entry.fn0 = (void*)hkpBvTreeStreamAgent_createBvTreeShapeAgent;
    entry.fn1 = (void*)hkpSymmetricAgentFlipBodyCollector_UpdateState_00d2e970;
    entry.fn2 = (void*)hkpSymmetricAgentFlipCollector_UpdateState_00d2e9b0;
    entry.fn3 = (void*)hkpBvTreeAgent_staticLinearCast_UpdateState_00d2e9f0;
    entry.b0 = true;
    entry.b1 = true;
    obj->AppendRecordAndRegisterAgents(&entry, 8, 0x12);

    entry.fn0 = (void*)hkpBvTreeStreamAgent_createShapeBvAgent;
    entry.fn1 = (void*)hkpBvTreeAgent_staticGetPenetrations;
    entry.fn2 = (void*)hkpBvTreeAgent_staticGetClosestPoints;
    entry.fn3 = (void*)hkpBvTreeAgent_staticLinearCast;
    entry.b0 = false;
    entry.b1 = true;
    obj->AppendRecordAndRegisterAgents(&entry, 0x12, 8);
}
}  // namespace fnv_00d2e6d0

namespace fnv_00d2eae0 {
// ---------------------------------------------------------------------------
// The agent object that the game tears down in FUN_00d2eae0.
//
// The first word of the object holds the vtable pointer.  While the agent is
// alive the pointer refers to the table of the agent class, once the agent
// has been released it is reset to the table of the base class.
// ---------------------------------------------------------------------------

// A vtable: a list of function pointers.
struct VTable
{
    void* entries[4];
};

// The functions the vtables of the agent class and of its base class point
// at (the game keeps them in the tables).
void __cdecl AgentRelease(void* agent, unsigned short id);
void __cdecl AgentFlush(void* buffer, int bytes);

// The vtables of the agent class and of its base class.
static const VTable g_vtblAgent = {
    {(void*)&AgentRelease, (void*)&AgentFlush, (void*)&AgentRelease, (void*)&AgentFlush}};

static const VTable g_vtblBase = {{(void*)&AgentFlush, (void*)&AgentRelease, (void*)&AgentFlush, (void*)&AgentRelease}};

// The handler that owns the agents.
struct AgentHandler
{
    virtual void unk00();
    virtual void unk04();
    virtual void release(hkpBvTreeStreamAgent* agent, unsigned short id);
    virtual void unk0c();
    virtual void flush(void* buffer, int bytes);
};

// The global that hands out the manager of the agents.
struct AgentManagerHolder
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    AgentHandler* unk10;
};

extern "C" AgentManagerHolder* __cdecl hkMemoryRouter_getInstance();

}  // namespace fnv_00d2eae0

// Resets the vtable, frees its buffer through the handler if owned, and if flags bit 0 is set calls the handler's release(this, id); returns this.
// @fnv 0x00d2eae0
void* __thiscall hkpBvTreeStreamAgent::FUN_00d2eae0(unsigned int flags)
{
    using namespace fnv_00d2eae0;
    *(const VTable**)this = &g_vtblAgent;

    AgentManagerHolder* holder = fnv_00d2eae0::hkMemoryRouter_getInstance();
    AgentHandler* handler = holder->unk10;

    int count = m_kAgentNnTrack.m_kSectors.m_iCapacityState;
    m_kAgentNnTrack.m_kSectors.m_iElementCount = 0;
    if (!(count & 0x80000000))
        handler->flush(m_kAgentNnTrack.m_kSectors.m_data, (count & 0x3fffffff) * 4);

    m_kAgentNnTrack.m_kSectors.m_data = 0;
    m_kAgentNnTrack.m_kSectors.m_iCapacityState = 0x80000000;
    *(const VTable**)this = &g_vtblBase;

    if (flags & 1)
    {
        AgentManagerHolder* holder2 = fnv_00d2eae0::hkMemoryRouter_getInstance();
        holder2->unk10->release(this, m_usMemSizeAndFlags);
    }

    return this;
}

struct StreamDispatchInput;
struct Selector
{
    virtual void Unknown0() = 0;
    virtual void Unknown1() = 0;
    virtual void Unknown2() = 0;
    virtual int Classify(void* second, void* first, StreamDispatchInput* context) = 0;
};
struct StreamDispatchInput
{
    unsigned int unk00, unk04, unk08, unk0c;
    Selector* selector;
};
extern "C" void* g_010ce8b0[];
extern "C" void* g_010ce874[];
struct Header
{
    void** vtable;
    unsigned short size, unk06;
};
struct Obj56 : Header
{
    void FUN_00d440f0(void* second, void* first, StreamDispatchInput* context, unsigned int flags);
};
static __forceinline Obj56* Create56(void* second, void* first, StreamDispatchInput* context, unsigned int flags)
{
    hkMemoryRouter* owner = audio();
    hkMemoryAllocator* allocator = owner->m_heap;
    Obj56* obj = static_cast<Obj56*>(allocator->blockAlloc(0x38));
    obj->size = 0x38;
    obj->FUN_00d440f0(second, first, context, flags);
    obj->vtable = g_010ce8b0;
    return obj;
}
static __forceinline Header* Create64(void* second, void* first, StreamDispatchInput* context, unsigned int flags)
{
    hkMemoryRouter* owner = audio();
    hkMemoryAllocator* allocator = owner->m_heap;
    hkpBvTreeStreamAgent* obj = static_cast<hkpBvTreeStreamAgent*>(allocator->blockAlloc(0x40));
    obj->m_usMemSizeAndFlags = 0x40;
    ::new (obj) hkpBvTreeStreamAgent(second, first, context, (void*)flags);
    *(void***)obj = g_010ce874;
    return (Header*)obj;
}
// Creates a 0x38 or 0x40 byte stream object from the selector, defaulting to a stream agent when flags is zero.
// @fnv 0x00d2e7f0
// src: HAVOK_LIB 0x00d2e7f0
Header* hkpBvTreeStreamAgent_dispatchBvTreeConvexList(void* first, void* second, StreamDispatchInput* context, unsigned int flags)
{
    if (flags)
    {
        switch (context->selector->Classify(second, first, context))
        {
        case 1:
            return Create56(second, first, context, flags);
        case 0:
        case 2:
            return Create64(second, first, context, flags);
        default:
            return 0;
        }
    }
    return Create64(second, first, context, 0);
}
