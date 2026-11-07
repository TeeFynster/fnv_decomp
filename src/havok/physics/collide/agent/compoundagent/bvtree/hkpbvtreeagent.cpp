
// src/havok/physics/collide/agent/compoundagent/bvtree/hkpbvtreeagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/compoundagent/bvtree/hkpbvtreeagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkArray.h"
#include "../../../../../../../include/Transform.h"

struct S_d2f5a0_Obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9(int a);
};
struct S_d2f5a0_Entry
{
    int unk0;
    int unk4;
    S_d2f5a0_Obj* m_obj;
};
typedef hkArrayBase<S_d2f5a0_Entry> S_d2f5a0_Array;
struct S_d2f5a0
{
    int unk0;
    int unk4;
    int unk8;
    S_d2f5a0_Array m_aiIndexedValues;
    void hkpBvTreeAgent_invalidateTim(int a);
};
// Iterates the entry array and calls v9(a) on each entry whose m_obj is non-null.
// @fnv 0x00d2f5a0
// src: HAVOK_LIB 0x00d2f5a0
void S_d2f5a0::hkpBvTreeAgent_invalidateTim(int a)
{
    for (S_d2f5a0_Entry *it = m_aiIndexedValues.begin(), *pEnd = m_aiIndexedValues.end(); it != pEnd; ++it)
        if (it->m_obj)
            it->m_obj->v9(a);
}


struct TargetObject
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void Apply(Transform* apTransform, float afAmount, void* apContext);
};

struct Holder
{
    TargetObject* m_pFlagTarget;
    int unk04;
    void* m_pData;
};

struct ValueSource
{
    int unk00;
    int unk04;
    float m_fAmount;
};

// Builds a Transform from the two holders' data and applies it to the first holder's target object with the value source's amount.
// @fnv 0x00d2f710
void __cdecl ApplyTransformToTarget(Holder* apFirst, Holder* apSecond, ValueSource* apValue, void* apContext)
{
    __declspec(align(16)) Transform kTransform(apSecond->m_pData, apFirst->m_pData);
    apFirst->m_pFlagTarget->Apply(&kTransform, apValue->m_fAmount, apContext);
}

struct Allocator
{
    virtual void* release();
    virtual void* allocate(int size);
};
struct Built
{
    int field00;
    short field04;
    int field08;
    void __thiscall FUN_00d2f980(int);
};
extern "C" hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
// Allocates a 0x40-byte Built from the global allocator, sets its field04 to 0x40, and calls FUN_00d2f980 with arg4.
// @fnv 0x00d2f9d0
// src: HAVOK_LIB 0x00d2f9d0
void __cdecl hkpBvTreeAgent_createShapeBvAgent(int aiUnused1, int aiUnused2, int aiUnused3, int arg4)
{
    hkMemoryRouter* global = hkMemoryRouter_getInstance();
    Built* pBuilt = (Built*)global->m_heap->blockAlloc(0x40);
    pBuilt->field04 = 0x40;
    pBuilt->FUN_00d2f980(arg4);
}

void __cdecl hkpBvTreeAgent_staticLinearCast(void* apFirst, void* apSecond, void* apThird, void* apFourth, void* apFifth);

// Calls FUN_00d30f50, passing along all five arguments unchanged.
// @fnv 0x00d315a0
// src: HAVOK_SRC 0x00d315a0
void __stdcall hkpBvTreeAgent_linearCast(void* apFirst, void* apSecond, void* apThird, void* apFourth, void* apFifth)
{
    hkpBvTreeAgent_staticLinearCast(apFirst, apSecond, apThird, apFourth, apFifth);
}

extern "C" void __cdecl hkpBvTreeAgent_staticGetClosestPoints(void* arg0, void* arg1, void* arg2, void* arg3);
// @fnv 0x00d315d0
// src: HAVOK_SRC 0x00d315d0
extern "C" void __stdcall hkpBvTreeAgent_getClosestPoints(void* arg0, void* arg1, void* arg2, void* arg3)
{
    hkpBvTreeAgent_staticGetClosestPoints(arg0, arg1, arg2, arg3);
}

void __cdecl hkpBvTreeAgent_staticGetPenetrations(void* apA, void* apB, void* apC, void* apD);

// @fnv 0x00d315f0
// src: HAVOK_SRC 0x00d315f0
void __stdcall hkpBvTreeAgent_getPenetrations(void* apA, void* apB, void* apC, void* apD)
{
    hkpBvTreeAgent_staticGetPenetrations(apA, apB, apC, apD);
}

struct D2FA00Allocator
{
    virtual void unk00();
    virtual void* AllocateMemoryBlock(int numBytes);
};

namespace fnvc_adapt {
extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance();
}

class D2FA00ReferencedObject
{
  public:
    static void* operator new(unsigned int nbytes)
    {
        D2FA00ReferencedObject* b =
            static_cast<D2FA00ReferencedObject*>(reinterpret_cast<D2FA00Allocator*>((&fnvc_adapt::hkMemoryRouter_getInstance().heap()))->AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    static void operator delete(void* p);

    virtual ~D2FA00ReferencedObject();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class D2FA00Agent : public D2FA00ReferencedObject
{
  public:
    __declspec(nothrow) D2FA00Agent(void* mgr);

    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
};

class D2FA00ShapeAgent : public D2FA00Agent
{
  public:
    D2FA00ShapeAgent(void* mgr) : D2FA00Agent(mgr)
    {}
    virtual ~D2FA00ShapeAgent();
};

// Allocates and constructs a D2FA00ShapeAgent from mgr and returns it; bodyA, bodyB and input are unused.
// @fnv 0x00d2fa00
// src: HAVOK_LIB 0x00d2fa00
D2FA00Agent* __cdecl hkpBvTreeAgent_createBvTreeShapeAgent(const void* bodyA, const void* bodyB, const void* input, void* mgr)
{
    return new D2FA00ShapeAgent(mgr);
}

extern char str_010ce9a4[];
extern char str_010ce9ac[];

extern "C" void* __cdecl hkStatisticsCollector_getAllocatedSize(void* apBuffer, int aiCount);

struct S_00d2f8f0_Elem
{
    int unk00;
    int unk04;
    int unk08;
};

struct S_00d2f8f0_Array
{
    S_00d2f8f0_Elem* m_pEntries;
    int m_iArrayLength;

    S_00d2f8f0_Elem* begin() const
    {
        return m_pEntries;
    }
    S_00d2f8f0_Elem* end() const
    {
        return m_pEntries + m_iArrayLength;
    }
};

struct S_00d2f8f0_ArgVtbl
{
    void* unk00;
    void* unk04;
    void* unk08;
    void(__thiscall* unk0c)(void*, char*, int, int);
    void* unk10;
    void(__thiscall* unk14)(void*, int, char*, void*, int, void*);
};

struct S_00d2f8f0_Arg
{
    S_00d2f8f0_ArgVtbl* m_pVtbl;
    int unk04;
    int unk08;
    int unk0c;
    char m_bFlag10;
};

struct S_00d2f8f0
{
    int unk00;
    int unk04;
    int unk08;
    S_00d2f8f0_Array m_aiIndexedValues;
    int m_iFlags;

    void WriteToStream(S_00d2f8f0_Arg* apStream, int aiUnused);
};

// @fnv 0x00d2f8f0
void S_00d2f8f0::WriteToStream(S_00d2f8f0_Arg* apStream, int aiUnused)
{
    if ((m_iFlags & 0x80000000u) == 0 || apStream->m_bFlag10 != 0)
    {
        void* pEntries = m_aiIndexedValues.m_pEntries;
        unsigned int uiByteCount = (unsigned int)m_iFlags & 0x3fffffffu;
        uiByteCount *= sizeof(S_00d2f8f0_Elem);

        void* pResult = hkStatisticsCollector_getAllocatedSize(pEntries, (int)uiByteCount);

        unsigned int uiArrayBytes = (unsigned int)m_aiIndexedValues.m_iArrayLength;
        uiArrayBytes *= sizeof(S_00d2f8f0_Elem);

        apStream->m_pVtbl->unk14(apStream, 3, str_010ce9ac, m_aiIndexedValues.m_pEntries, (int)uiArrayBytes, pResult);
    }

    S_00d2f8f0_Elem* p = m_aiIndexedValues.begin();
    S_00d2f8f0_Elem* pEnd = m_aiIndexedValues.end();
    while (p != pEnd)
    {
        if (p->unk08 != 0)
        {
            apStream->m_pVtbl->unk0c(apStream, str_010ce9a4, p->unk08, 0);
        }
        ++p;
    }
}

class ListenerD2F5
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C(void* pArg);
};

struct EntryD2F5
{
    int unk00;
    int unk04;
    ListenerD2F5* m_pkListener;
};

class OwnerD2F5
{
  public:
    virtual ~OwnerD2F5();

    int unk04[2];
    hkArray<EntryD2F5> m_entries;

    void hkpBvTreeAgent_cleanup(void* pArg);
};

// Invokes vf1C on each non-null listener in m_entries with pArg, then deletes this object.
// @fnv 0x00d2f550
// src: HAVOK_LIB 0x00d2f550
void OwnerD2F5::hkpBvTreeAgent_cleanup(void* pArg)
{
    for (EntryD2F5 *it = m_entries.begin(), *itEnd = m_entries.end(); it != itEnd; ++it)
    {
        if (it->m_pkListener)
            it->m_pkListener->vf1C(pArg);
    }
    delete this;
}

typedef void(__thiscall* TUpdateFn)(void* self, float, float, int);

struct SUpdated
{
    TUpdateFn* vtable;
};

struct SElement
{
    int unk00;
    int unk04;
    SUpdated* unk08;
};

struct CUpdateList
{
    int unk00;
    int unk04;
    int unk08;
    SElement* unk0c;
    int unk10;
    void hkpBvTreeAgent_warpTime(float a, float b, int c);
};

// Iterates the SElement array and calls the vtable slot 10 on each non-null SUpdated pointer with the given float and int arguments.
// @fnv 0x00d2f5e0
// src: HAVOK_LIB 0x00d2f5e0
void CUpdateList::hkpBvTreeAgent_warpTime(float a, float b, int c)
{
    int count = unk10;
    SElement* p = unk0c;
    SElement*& arr = unk0c;
    SElement* end = arr + count;
    for (; p != end; ++p)
    {
        if (p->unk08)
        {
            p->unk08->vtable[10](p->unk08, a, b, c);
        }
    }
}

class hkBoolR
{
  public:
    hkBoolR()
    {}
    hkBoolR(bool b) : m_cBooleanValue((char)b)
    {}
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
    char m_cBooleanValue;
};

struct __declspec(align(16)) ShapeBuffer
{
    int m_data[128];
};

struct HkShape
{
    virtual void v00();
    int unk04;
    int unk08;
    int m_type;
};

struct ShapeContainer
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual const HkShape* GetShapeForKey(unsigned int key, ShapeBuffer& buffer) const;
};

struct ShapeCollection : HkShape
{
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual const ShapeContainer* GetShapeContainer() const;
};

// local form of hkpCdBody: 0x00d2f760 needs inline parent construction/getShape/SetCollisionShapeAndKey; canonical form does not reproduce exe bytes.
struct CdBody
{
    const HkShape* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const CdBody* m_parent;

    CdBody(const CdBody* parent)
    {
        m_parent = parent;
        m_pMotionState = parent->m_pMotionState;
    }
    const HkShape* getShape() const
    {
        return m_pCollisionShape;
    }
    void SetCollisionShapeAndKey(const HkShape* shape, unsigned int key)
    {
        m_pCollisionShape = shape;
        m_uiCollisionShapeKey = key;
    }
};

struct CollisionInput;

struct ShapeCollectionFilter
{
    virtual void v00();
    virtual hkBoolR IsCollisionEnabled(const CollisionInput& input, const CdBody& a, const CdBody& b,
                                       const ShapeContainer& bContainer, unsigned int bKey) const;
};

struct ReferencedObject
{
    virtual void v00();
    int unk04;
};

struct CollidableCollidableFilter
{
    virtual void v00();
};

struct CollisionFilter : ReferencedObject, CollidableCollidableFilter, ShapeCollectionFilter
{
    virtual hkBoolR IsCollisionEnabled(const CollisionInput& input, const CdBody& a, const CdBody& b,
                                       const ShapeContainer& bContainer, unsigned int bKey) const;
};

struct ConstraintOwner;
struct ContactMgr;
struct CollisionAgent;

typedef CollisionAgent*(__cdecl* CreateFunc)(const CdBody& a, const CdBody& b, const CollisionInput& input,
                                             ContactMgr* mgr);

struct CollisionAgentFunctionTable
{
    CreateFunc m_pCreateFunc;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
};

struct CollisionDispatcher
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    unsigned char m_ucAgent2TypeTable[32][32];
    unsigned char m_ucAgent3TypeTable[32][32];
    CollisionAgentFunctionTable m_kAgent3FunctionTable[32];

    CollisionAgent* getNewCollisionAgent(const CdBody& bodyA, const CdBody& bodyB, const CollisionInput& input,
                                         ContactMgr* mgr) const;
};

struct CollisionInput
{
    CollisionDispatcher* m_pCollisionDispatcher;
    int unk04;
    int unk08;
    CollisionFilter* m_iFilter;
    int unk10;
    int m_bCreatePredictiveAgents;
};

inline CollisionAgent* CollisionDispatcher::getNewCollisionAgent(const CdBody& bodyA, const CdBody& bodyB,
                                                                 const CollisionInput& input, ContactMgr* mgr) const
{
    int typeA = bodyA.getShape()->m_type;
    int typeB = bodyB.getShape()->m_type;
    const unsigned char* agentTypeTablePtr =
        (input.m_bCreatePredictiveAgents) ? &m_ucAgent3TypeTable[0][0] : &m_ucAgent2TypeTable[0][0];
    int agentType = agentTypeTablePtr[typeA * 32 + typeB];
    CreateFunc f = m_kAgent3FunctionTable[agentType].m_pCreateFunc;
    return f(bodyA, bodyB, input, mgr);
}

struct CollisionAgent
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void cleanup(ConstraintOwner& owner);
    virtual void ProcessContactPoints(const CdBody& bodyA, const CdBody& bodyB, const CollisionInput& input,
                                      ConstraintOwner& owner);
};

CollisionAgent* __cdecl hkpNullAgent_getNullAgent();

struct CollisionAgentMapRecord
{
    unsigned int m_key;
    int unk04;
    CollisionAgent* m_pCollisionAgent;
};

typedef hkArrayBase<CollisionAgentMapRecord> AgentArray;

class ShapeCollectionAgent
{
  public:
    virtual void v00();
    int unk04;
    ContactMgr* m_pContactManager;
    AgentArray m_pAgents;

    void hkpBvTreeAgent_updateShapeCollectionFilter(const CdBody& bodyA, const CdBody& bodyB, const CollisionInput& input,
                      ConstraintOwner& constraintOwner);
};

// Iterates m_pAgents, creating or cleaning up collision agents per shape key based on filter results, and processes contact points when enabled.
// @fnv 0x00d2f760
// src: HAVOK_LIB 0x00d2f760
void ShapeCollectionAgent::hkpBvTreeAgent_updateShapeCollectionFilter(const CdBody& bodyA, const CdBody& bodyB, const CollisionInput& input,
                                        ConstraintOwner& constraintOwner)
{
    const ShapeCollection* collection = static_cast<const ShapeCollection*>(bodyB.getShape());
    const ShapeContainer* shapeContainer = collection->GetShapeContainer();

    for (int i = 0; i < m_pAgents.GetLogicalSize(); i++)
    {
        ShapeBuffer shapeBuffer;
        const HkShape* shape = shapeContainer->GetShapeForKey(m_pAgents[i].m_key, shapeBuffer);
        CdBody newOperandB(&bodyB);
        newOperandB.SetCollisionShapeAndKey(shape, m_pAgents[i].m_key);

        if (input.m_iFilter->IsCollisionEnabled(input, bodyA, bodyB, *shapeContainer, m_pAgents[i].m_key))
        {
            if (m_pAgents[i].m_pCollisionAgent == hkpNullAgent_getNullAgent())
            {
                m_pAgents[i].m_pCollisionAgent =
                    input.m_pCollisionDispatcher->getNewCollisionAgent(bodyA, newOperandB, input, m_pContactManager);
            }
            else
            {
                m_pAgents[i].m_pCollisionAgent->ProcessContactPoints(bodyA, newOperandB, input, constraintOwner);
            }
        }
        else
        {
            if (m_pAgents[i].m_pCollisionAgent != hkpNullAgent_getNullAgent())
            {
                m_pAgents[i].m_pCollisionAgent->cleanup(constraintOwner);
                m_pAgents[i].m_pCollisionAgent = hkpNullAgent_getNullAgent();
            }
        }
    }
}

#include <xmmintrin.h>
struct S_00d2f980_Vec
{
    float x, y, z, w;
    void SetAllComponents(float a)
    {
        reinterpret_cast<__m128&>(*this) = _mm_set1_ps(a);
    }
    void setAllL(const float& a)
    {
        reinterpret_cast<__m128&>(*this) = _mm_load1_ps(&a);
    }
    S_00d2f980_Vec& operator=(const S_00d2f980_Vec& o)
    {
        reinterpret_cast<__m128&>(*this) = reinterpret_cast<const __m128&>(o);
        return *this;
    }
};
struct S_00d2f980_Base
{
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
    S_00d2f980_Base()
    {
        m_sReferenceCount = 1;
    }
    virtual void vfn_00();
};
struct S_00d2f980_Array
{
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    S_00d2f980_Array() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};
struct S_00d2f980_Mid : S_00d2f980_Base
{
    int m8;
    S_00d2f980_Mid(int p) : m8(p)
    {}
};
struct FUN_00d2f980 : S_00d2f980_Mid
{
    S_00d2f980_Array m_aiIndexedValues;
    int unk18;
    int unk1C;
    __declspec(align(16)) S_00d2f980_Vec m20;
    S_00d2f980_Vec m30;
    FUN_00d2f980(int p);
};
// Initializes m30 and m20 to FLT_MAX, delegating to the S_00d2f980_Mid base constructor with p.
// @fnv 0x00d2f980
FUN_00d2f980::FUN_00d2f980(int p) : S_00d2f980_Mid(p)
{
    m30.SetAllComponents(3.40282e+38f);
    m20 = m30;
}

extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
#include <windows.h>

extern DWORD DAT_0126835c;

struct S_00d30f50_TimerCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
    void setTime(unsigned int& t)
    {
        t = (unsigned int)__rdtsc();
        m_uiStartTicks = *(volatile unsigned int*)&t;
    }
};

struct S_00d30f50_TimerBeginListCommand : S_00d30f50_TimerCommand
{
    const char* m_pFirst;
};

struct S_00d30f50_MonitorStream
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
    static S_00d30f50_MonitorStream& GetMonitorStream()
    {
        return *(S_00d30f50_MonitorStream*)TlsGetValue(DAT_0126835c);
    }
    bool memoryAvailable() const
    {
        return m_kRayEnd < m_pCurrentCommand;
    }
};

static inline void S_00d30f50_TimerBeginList(const char* name, const char* split, unsigned int& t)
{
    S_00d30f50_MonitorStream& mStream = S_00d30f50_MonitorStream::GetMonitorStream();
    if (mStream.memoryAvailable())
    {
        S_00d30f50_TimerBeginListCommand* h = (S_00d30f50_TimerBeginListCommand*)mStream.m_kRayEnd;
        h->m_pCommandName = name;
        h->m_pFirst = split;
        _ReadWriteBarrier();
        h->setTime(t);
        mStream.m_kRayEnd = (char*)(h + 1);
    }
}

static inline void S_00d30f50_Timer(const char* name, unsigned int& t)
{
    S_00d30f50_MonitorStream& mStream = S_00d30f50_MonitorStream::GetMonitorStream();
    if (mStream.memoryAvailable())
    {
        S_00d30f50_TimerCommand* h = (S_00d30f50_TimerCommand*)mStream.m_kRayEnd;
        h->m_pCommandName = name;
        _ReadWriteBarrier();
        h->setTime(t);
        mStream.m_kRayEnd = (char*)(h + 1);
    }
}

struct S_00d30f50_Heap
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void ReturnMemory(void* p, int numBytes);
};

namespace fnv_linear_cast {
hkMemoryRouter& __cdecl hkMemoryRouter_getInstance();
}

template <class T> struct S_00d30f50_ArrayLocalForm
{ // local form of hkArray: 0x00d30f50 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T* begin()
    {
        return m_data;
    }
    T* end()
    {
        return m_data + m_iElementCount;
    }
    void clear()
    {
        m_iElementCount = 0;
    }
    void _clearAndDeallocate(S_00d30f50_Heap& alloc) throw()
    {
        clear();
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    ~S_00d30f50_ArrayLocalForm() throw()
    {
        _clearAndDeallocate(*reinterpret_cast<S_00d30f50_Heap*>((&fnv_linear_cast::hkMemoryRouter_getInstance().heap())));
    }
};

template <class T, int N> struct S_00d30f50_InplaceArray : S_00d30f50_ArrayLocalForm<T>
{
    T m_kStorage[N];
    S_00d30f50_InplaceArray() throw()
    {
        this->m_data = m_kStorage;
        this->m_iElementCount = 0;
        this->m_iCapacityState = N | 0x80000000;
    }
    ~S_00d30f50_InplaceArray() throw()
    {}
};

struct __declspec(align(16)) S_00d30f50_ShapeBuffer
{
    unsigned int m_data[128];
};

struct __declspec(align(16)) S_00d30f50_Aabb
{
    float m_kMinimumCorner[4];
    float m_kMaximumCorner[4];
};

struct S_00d30f50_ShapeContainer;

struct S_00d30f50_Shape
{
    virtual ~S_00d30f50_Shape();
    int unk04;
    int unk08;
    int m_type;
    int getType() const
    {
        return m_type;
    }
};

struct S_00d30f50_ShapeContainer
{
    virtual ~S_00d30f50_ShapeContainer();
    virtual int GetNumChildShapes() const;
    virtual unsigned int GetFirstKey() const;
    virtual unsigned int GetNextShapeKey(unsigned int oldKey) const;
    virtual unsigned int GetFilterInfoForKey(unsigned int key) const;
    virtual const S_00d30f50_Shape* GetShapeForKey(unsigned int key, S_00d30f50_ShapeBuffer& buffer) const;
};

struct S_00d30f50_BvTreeShape : S_00d30f50_Shape
{
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual const S_00d30f50_ShapeContainer* GetShapeContainer() const;
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void GetAabbHits(const S_00d30f50_Aabb& aabb, S_00d30f50_ArrayLocalForm<unsigned int>& hits) const;
};

struct S_00d30f50_MotionState;

struct S_00d30f50_CdBody
{
    const S_00d30f50_Shape* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const S_00d30f50_MotionState* m_pMotionState;
    const S_00d30f50_CdBody* m_parent;

    S_00d30f50_CdBody(const S_00d30f50_CdBody* parent)
    {
        m_parent = parent;
        m_pMotionState = parent->m_pMotionState;
    }
    void SetCollisionShapeAndKey(const S_00d30f50_Shape* shape, unsigned int key)
    {
        m_pCollisionShape = shape;
        m_uiCollisionShapeKey = key;
    }
    const S_00d30f50_Shape* getShape() const
    {
        return m_pCollisionShape;
    }
};

struct S_00d30f50_LinearCastInput;
struct S_00d30f50_CdPointCollector;

typedef void(__cdecl* S_00d30f50_LinearCastFunc)(const S_00d30f50_CdBody& bodyA, const S_00d30f50_CdBody& bodyB,
                                                 const S_00d30f50_LinearCastInput& input,
                                                 S_00d30f50_CdPointCollector& collector,
                                                 S_00d30f50_CdPointCollector* startCollector);

struct S_00d30f50_Agent2Funcs
{
    void* m_pCreateFunc;
    void* m_pQueryPenetrationsFunc;
    void* m_getClosestPointsFunc;
    S_00d30f50_LinearCastFunc m_pLinearCastFunc;
    void* unk10;
};

struct S_00d30f50_Dispatcher
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    unsigned char m_agent2TypeMap[32][32];
    unsigned char m_agent3TypeMap[32][32];
    S_00d30f50_Agent2Funcs m_agent2Funcs[32];

    S_00d30f50_LinearCastFunc getLinearCastFunc(int typeA, int typeB) const
    {
        int idx = m_agent2TypeMap[typeA][typeB];
        return m_agent2Funcs[idx].m_pLinearCastFunc;
    }
};

struct S_00d30f50_LinearCastInput
{
    S_00d30f50_Dispatcher* m_pCollisionDispatcher;
};

void __cdecl hkpBvTreeAgent_calcAabbLinearCast(const S_00d30f50_CdBody& bodyA, const S_00d30f50_CdBody& bodyB,
                          const S_00d30f50_LinearCastInput& input, S_00d30f50_Aabb& aabbOut);

void __cdecl hkpBvTreeAgent_staticLinearCast(const S_00d30f50_CdBody& bodyA, const S_00d30f50_CdBody& bodyB,
                          const S_00d30f50_LinearCastInput& input, S_00d30f50_CdPointCollector& collector,
                          S_00d30f50_CdPointCollector* startCollector) throw();

// Performs a linear cast against a BvTree shape by querying AABB hits and dispatching narrow-phase linear cast for each hit shape.
// @fnv 0x00d30f50
// src: XBOX_PDB 0x00d30f50
void __cdecl hkpBvTreeAgent_staticLinearCast(const S_00d30f50_CdBody& bodyA, const S_00d30f50_CdBody& bodyB,
                          const S_00d30f50_LinearCastInput& input, S_00d30f50_CdPointCollector& collector,
                          S_00d30f50_CdPointCollector* startCollector) throw()
{
    unsigned int timerTmp;
    S_00d30f50_TimerBeginList("LtBvTree", "StQueryTree", timerTmp);

    S_00d30f50_Aabb aabb;
    hkpBvTreeAgent_calcAabbLinearCast(bodyA, bodyB, input, aabb);

    const S_00d30f50_BvTreeShape* pBvTreeShapeB = static_cast<const S_00d30f50_BvTreeShape*>(bodyB.getShape());
    S_00d30f50_InplaceArray<unsigned int, 128> hitList;
    pBvTreeShapeB->GetAabbHits(aabb, hitList);

    S_00d30f50_Timer("StNarrowPhase", timerTmp);

    {
        int typeA = bodyA.getShape()->getType();
        unsigned int* itr = hitList.begin();
        unsigned int* end = hitList.end();
        S_00d30f50_CdBody modifiedBodyB(&bodyB);
        const S_00d30f50_ShapeContainer* shapeContainer = pBvTreeShapeB->GetShapeContainer();
        for (; itr != end; itr++)
        {
            S_00d30f50_ShapeBuffer shapeBuffer;
            const S_00d30f50_Shape* shape = shapeContainer->GetShapeForKey(*itr, shapeBuffer);
            modifiedBodyB.SetCollisionShapeAndKey(shape, *itr);
            S_00d30f50_LinearCastFunc linCastFunc =
                input.m_pCollisionDispatcher->getLinearCastFunc(typeA, shape->getType());
            linCastFunc(bodyA, modifiedBodyB, input, collector, startCollector);
        }
    }

    S_00d30f50_Timer("lt", timerTmp);
}

namespace fnv_00d2fa40 {
struct FloatSub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    float m_a0;
};

struct FloatOwner
{
    int unk00;
    int unk04;
    FloatSub* m_08;
};

class SlotAllocator
{
  public:
    virtual void* vSlot0();
    virtual void* Alloc(unsigned int size);
};

struct SpawnedObject
{
    virtual ~SpawnedObject()
    {}
    unsigned short m_04;
    SpawnedObject* FUN_00d2f980(int arg);
};

hkMemoryRouter* hkMemoryRouter_getInstance();

// Allocates a 0x40-byte object and calls FUN_00d2f980 with a4; unless the first m_a0 is less than the second, it then calls the destructor; returns the object.
// @fnv 0x00d2fa40
// src: HAVOK_LIB 0x00d2fa40
SpawnedObject* hkpBvTreeAgent_createBvBvAgent(FloatOwner* apFirstOwner, FloatOwner* apSecondOwner, int aiUnused, int a4)
{
    FloatSub* pFirstSub = apFirstOwner->m_08;
    FloatSub* pSecondSub = apSecondOwner->m_08;
    if (pFirstSub->m_a0 < pSecondSub->m_a0)
    {
        hkMemoryRouter* holder = hkMemoryRouter_getInstance();
        SlotAllocator* alloc = (SlotAllocator*)holder->m_heap;
        SpawnedObject* obj = (SpawnedObject*)alloc->Alloc(0x40);
        obj->m_04 = 0x40;
        return obj->FUN_00d2f980(a4);
    }
    hkMemoryRouter* holder = hkMemoryRouter_getInstance();
    SlotAllocator* alloc = (SlotAllocator*)holder->m_heap;
    SpawnedObject* obj = (SpawnedObject*)alloc->Alloc(0x40);
    obj->m_04 = 0x40;
    obj->FUN_00d2f980(a4);
    obj->SpawnedObject::~SpawnedObject();
    return obj;
}
}  // namespace fnv_00d2fa40

namespace fnv_00d314e0 {
// Descriptor record built on the stack: four callback slots plus two flag bytes.
struct DescRecord
{
    void (*fn0)();
    void (*fn1)();
    void (*fn2)();
    void (*fn3)();
    unsigned char flagA;
    unsigned char flagB;
};

// Stand-in class for the thiscall helper.
struct SpawnedObject
{
    void AppendRecordAndRegisterAgents(DescRecord* rec, int a, int b);
};

extern "C" void hkpBvTreeAgent_createBvTreeShapeAgent();
extern "C" void hkpSymmetricAgentFlipBodyCollector_UpdateState_00d2e970();
extern "C" void hkpSymmetricAgentFlipCollector_UpdateState_00d2e9b0();
extern "C" void hkpBvTreeAgent_staticLinearCast_UpdateState_00d2e9f0();
extern "C" void hkpBvTreeAgent_createShapeBvAgent();
extern "C" void hkpBvTreeAgent_staticGetPenetrations();
extern "C" void hkpBvTreeAgent_staticGetClosestPoints();
extern "C" void hkpBvTreeAgent_staticLinearCast();
extern "C" void hkpBvTreeAgent_createBvBvAgent();

// Sets up three DescRecord entries with function pointers and flags, then passes each to self->FUN_00cfbbe0 with different index pairs.
// @fnv 0x00d314e0
// src: HAVOK_LIB 0x00d314e0
void hkpBvTreeAgent_registerAgent(SpawnedObject* self)
{
    DescRecord desc;
    desc.fn0 = hkpBvTreeAgent_createBvTreeShapeAgent;
    desc.fn1 = hkpSymmetricAgentFlipBodyCollector_UpdateState_00d2e970;
    desc.fn2 = hkpSymmetricAgentFlipCollector_UpdateState_00d2e9b0;
    desc.fn3 = hkpBvTreeAgent_staticLinearCast_UpdateState_00d2e9f0;
    desc.flagA = 1;
    desc.flagB = 1;
    self->AppendRecordAndRegisterAgents(&desc, 8, -1);

    desc.fn0 = hkpBvTreeAgent_createShapeBvAgent;
    desc.fn1 = hkpBvTreeAgent_staticGetPenetrations;
    desc.fn2 = hkpBvTreeAgent_staticGetClosestPoints;
    desc.fn3 = hkpBvTreeAgent_staticLinearCast;
    desc.flagA = 0;
    desc.flagB = 1;
    self->AppendRecordAndRegisterAgents(&desc, -1, 8);

    desc.fn0 = hkpBvTreeAgent_createBvBvAgent;
    desc.fn1 = hkpBvTreeAgent_staticGetPenetrations;
    desc.fn2 = hkpBvTreeAgent_staticGetClosestPoints;
    desc.fn3 = hkpBvTreeAgent_staticLinearCast;
    desc.flagA = 0;
    desc.flagB = 1;
    self->AppendRecordAndRegisterAgents(&desc, 8, 8);
}
}  // namespace fnv_00d314e0

extern "C" void __cdecl ApplyTransformToTarget(void*, void*, void*, void*);
extern char str_010cea04[];
extern char str_010ce7e0[];
extern char str_010ce9f4[];
extern char str_01076f38[];

struct S00d31110_Stream
{
    char* m_kRayStart;
    unsigned int* m_cur;
    char* m_capEnd;
    unsigned int* m_kRayEnd;
};

struct S00d31110_Shape;

struct S00d31110_Body
{
    S00d31110_Shape* m_pCollisionShape;
    unsigned int m_key;
    void* m_pMotionState;
    S00d31110_Body* m_parent;

    void SetCollisionShapeAndKey(S00d31110_Shape* shape, unsigned int key)
    {
        m_pCollisionShape = shape;
        m_key = key;
    }
};

struct S00d31110_Array
{
    unsigned int* m_data;
    int m_iElementCount;
    int m_capFlags;
};

struct S00d31110_InplaceArray : S00d31110_Array
{
    unsigned int m_kStorage[128];
};

struct S00d31110_Shape
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual S00d31110_Shape* GetShapeContainer();
    virtual S00d31110_Shape* GetShapeForKey(unsigned int key, void* buffer);
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void GetAabbHits(void* aabb, S00d31110_Array* hits);
    int unk04;
    int unk08;
    int m_type;
};

struct S00d31110_Filter
{
    virtual void v00();
    virtual const bool* IsCollisionEnabled(bool* result, void* input, S00d31110_Body* a, S00d31110_Body* b,
                                           S00d31110_Shape* container, unsigned int key);
};

struct S00d31110_RefObj
{
    virtual void v00();
    int unk04;
    int unk08;
};

struct S00d31110_FilterHolder : S00d31110_RefObj, S00d31110_Filter
{
};

typedef void(__cdecl* S00d31110_Func)(S00d31110_Body* a, S00d31110_Body* b, void* input, void* collector);

struct S00d31110_FuncEntry
{
    S00d31110_Func m_func;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};

struct S00d31110_Dispatcher
{
    unsigned char m_types[0x9a8];
    S00d31110_FuncEntry m_entries[1];
};

struct S00d31110_Input
{
    S00d31110_Dispatcher* m_pCollisionDispatcher;
    int unk04;
    int unk08;
    S00d31110_FilterHolder* m_iFilter;
};

struct S00d31110_Aabb
{
    __declspec(align(16)) float m_kMinimumCorner[4];
    float m_kMaximumCorner[4];
};

struct S00d31110_Free
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void deallocate(void* p, int size);
};

// Computes the AABB of bodyB, collects shape hits, and dispatches collision callbacks for each enabled child shape via the dispatcher.
// @fnv 0x00d31110
// src: HAVOK_LIB 0x00d31110
extern "C" void __cdecl hkpBvTreeAgent_staticGetClosestPoints(void* apBodyA, void* apBodyB, void* apInput, void* apCollector)
{
    S00d31110_Input* input = (S00d31110_Input*)apInput;
    volatile unsigned int tick;

    {
        S00d31110_Stream* pStream = (S00d31110_Stream*)TlsGetValue(DAT_0126835c);
        unsigned int* p = pStream->m_cur;
        if (p < pStream->m_kRayEnd)
        {
            p[0] = (unsigned int)str_010cea04;
            p[3] = (unsigned int)str_010ce7e0;
            _ReadWriteBarrier();
            tick = (unsigned int)__rdtsc();
            p[1] = tick;
            pStream->m_cur = p + 4;
        }
    }

    S00d31110_Aabb aabb;
    S00d31110_Body* bodyB = (S00d31110_Body*)apBodyB;
    ApplyTransformToTarget(apBodyA, bodyB, input, &aabb);

    S00d31110_Shape* shape = bodyB->m_pCollisionShape;
    S00d31110_InplaceArray hits;
    hits.m_data = hits.m_kStorage;
    hits.m_iElementCount = 0;
    hits.m_capFlags = 0x80000080;
    shape->GetAabbHits(&aabb, &hits);

    {
        S00d31110_Stream* pStream = (S00d31110_Stream*)TlsGetValue(DAT_0126835c);
        unsigned int* p = pStream->m_cur;
        if (p < pStream->m_kRayEnd)
        {
            p[0] = (unsigned int)str_010ce9f4;
            _ReadWriteBarrier();
            tick = (unsigned int)__rdtsc();
            p[1] = tick;
            pStream->m_cur = p + 3;
        }
    }

    int typeA = ((S00d31110_Body*)apBodyA)->m_pCollisionShape->m_type;
    {
        unsigned int* it = hits.m_data;
        unsigned int* end = it + hits.m_iElementCount;
        S00d31110_Body child;
        child.m_pMotionState = ((S00d31110_Body*)apBodyB)->m_pMotionState;
        child.m_parent = (S00d31110_Body*)apBodyB;
        S00d31110_Shape* container = shape->GetShapeContainer();
        unsigned int childBuffer[128];
        bool enabled;
        for (; it != end; ++it)
        {
            if (*input->m_iFilter->IsCollisionEnabled(&enabled, input, (S00d31110_Body*)apBodyA,
                                                      (S00d31110_Body*)apBodyB, container, *it))
            {
                S00d31110_Shape* childShape = container->GetShapeForKey(*it, childBuffer);
                child.SetCollisionShapeAndKey(childShape, *it);
                unsigned char t = input->m_pCollisionDispatcher->m_types[(typeA + 13) * 32 + childShape->m_type];
                input->m_pCollisionDispatcher->m_entries[t].m_func((S00d31110_Body*)apBodyA, &child, input,
                                                                   apCollector);
            }
        }
    }

    {
        S00d31110_Stream* pStream = (S00d31110_Stream*)TlsGetValue(DAT_0126835c);
        unsigned int* p = pStream->m_cur;
        if (p < pStream->m_kRayEnd)
        {
            p[0] = (unsigned int)str_01076f38;
            _ReadWriteBarrier();
            tick = (unsigned int)__rdtsc();
            p[1] = tick;
            pStream->m_cur = p + 3;
        }
    }

    hkMemoryRouter* g = hkMemoryRouter_getInstance();
    int iCapFlags = hits.m_capFlags;
    S00d31110_Free* pAllocator = (S00d31110_Free*)g->m_heap;
    hits.m_iElementCount = 0;
    if ((iCapFlags & 0x80000000) == 0)
        pAllocator->deallocate(hits.m_data, (iCapFlags & 0x3fffffff) * 4);
}
