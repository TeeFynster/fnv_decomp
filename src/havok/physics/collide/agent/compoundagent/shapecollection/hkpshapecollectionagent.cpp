#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/Pair.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkpCdBody.h"
#include "../../../../../../../include/hkpCollisionDispatcher.h"
#include "../../../../../../../include/hkpCollisionFilter.h"
#include "../../../../../../../include/hkpShape.h"
#include "../../../../../../../include/hkpShapeCollection.h"
#include "../../../../../../../include/hkpShapeCollectionFilter.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkBool.h"

// These operations were inlined in the original game. Keep their bodies local.

inline hkpCdBody::hkpCdBody() {}

inline hkpCdBody::hkpCdBody(const hkpCdBody* parent)
{
    m_parent = parent;
    m_pMotionState = parent->m_pMotionState;
}

inline const hkpShape* hkpCdBody::getShape() const
{
    return m_pCollisionShape;
}

inline void hkpCdBody::SetCollisionShapeAndKey(const hkpShape* shape, unsigned int key)
{
    m_pCollisionShape = shape;
    m_uiCollisionShapeKey = key;
}

inline hkpShapeType hkpShape::getType() const
{
    return reinterpret_cast<const hkpShapeType&>(m_type);
}

// src/havok/physics/collide/agent/compoundagent/shapecollection/hkpshapecollectionagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/compoundagent/shapecollection/hkpshapecollectionagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct hkpShapeCollectionAgent
{
    const void* vtbl;
    void* p0;
    void* p1;
    void* p2;
    int count;
    void cleanup_00d436f0(int arg);
};

// @fnv 0x00d436f0
// src: HAVOK_SRC 0x00d436f0
void hkpShapeCollectionAgent::cleanup_00d436f0(int arg)
{
    for (int i = 0; i < count; ++i)
    {
        void** arr = reinterpret_cast<void**>(reinterpret_cast<void**>(this)[3]);
        void* obj = arr[i * 2 + 1];
        ((void(__thiscall*)(void*, int))(*reinterpret_cast<void***>(obj))[7])(obj, arg);
    }
    ((void(__thiscall*)(void*, int))(*reinterpret_cast<void***>(this))[0])(this, 1);
}

struct ShapeItem
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int arg);
};

struct ShapeEntry
{
    int unk00;
    ShapeItem* m_pInventoryEntryData;  // +0x4
};

class FUN_00d43730_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    ShapeEntry* m_entries;  // +0xc
    int m_uiItemCount;      // +0x10

    void CallShapeItems(int arg);
};

// @fnv 0x00d43730
void FUN_00d43730_cls::CallShapeItems(int arg)
{
    int i = 0;
    if (m_uiItemCount > 0)
    {
        do
        {
            m_entries[i].m_pInventoryEntryData->v09(arg);
            ++i;
        } while (i < m_uiItemCount);
    }
}

namespace fnv_00d43760 {
struct ShapeItem
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10(float a, float b, int c);
};

struct ShapeEntry
{
    int unk00;
    ShapeItem* m_pInventoryEntryData;  // +0x4
};

class FUN_00d43760_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    ShapeEntry* m_entries;  // +0xc
    int m_uiItemCount;      // +0x10

    void DispatchToEntries(float a, float b, int c);
};

// @fnv 0x00d43760
void FUN_00d43760_cls::DispatchToEntries(float afArg1, float afArg2, int aiArg3)
{
    int i = 0;
    if (m_uiItemCount > 0)
    {
        do
        {
            m_entries[i].m_pInventoryEntryData->v10(afArg1, afArg2, aiArg3);
            ++i;
        } while (i < m_uiItemCount);
    }
}
}  // namespace fnv_00d43760

extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

extern "C" unsigned long DAT_0126835c;

struct CollisionAgentContext
{
    hkpCollisionDispatcher* m_pCollisionDispatcher;
    int m_unk04;
    int m_unk08;
    hkpCollisionFilter* m_pCollisionFilter;
    int unk10;
    int m_bCreatePredictiveAgents;
};

typedef void(__cdecl* AgentFunc)(const hkpCdBody* local_body, const hkpCdBody* bodyB,
                                 const CollisionAgentContext* input, void* collector);

__forceinline void hkTimerBegin(const char* tag)
{
    hkMonitorStream* stream = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    char* cur = stream->m_end.m_storage;
    if (cur < stream->m_capacityMinus16.m_storage)
    {
        *(const char**)cur = tag;
        _ReadWriteBarrier();
        volatile unsigned int time = (unsigned int)__rdtsc();
        *(unsigned int*)(cur + 4) = (unsigned int)time;
        cur += 12;
        stream->m_end.m_storage = cur;
    }
}

__forceinline void hkTimerEnd()
{
    hkMonitorStream* stream = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    char* cur = stream->m_end.m_storage;
    if (cur < stream->m_capacityMinus16.m_storage)
    {
        *(const char**)cur = "Et";
        _ReadWriteBarrier();
        volatile unsigned int time = (unsigned int)__rdtsc();
        *(unsigned int*)(cur + 4) = (unsigned int)time;
        cur += 12;
        stream->m_end.m_storage = cur;
    }
}

// Iterates the shape collection's keys, filters each child shape, and dispatches the static get-closest-points agent for each accepted pair.
// @fnv 0x00d43960
void __cdecl GetClosestPointsShapeCollection(const hkpCdBody* bodyA, const hkpCdBody* bodyB,
                                             const CollisionAgentContext* input, void* collector)
{
    hkTimerBegin("TtShapeCollection");

    const hkpShapeContainer* collection = bodyA->m_pCollisionShape->GetShapeContainer();
    const hkpShape* shapeB = bodyB->m_pCollisionShape;

    hkpCdBody local_body;
    local_body.m_pMotionState = bodyA->m_pMotionState;
    local_body.m_parent = bodyA;

    int typeB = shapeB->getType();

    unsigned int key = collection->GetFirstKey();
    while (key != (unsigned int)-1)
    {
        if (input->m_pCollisionFilter->IsCollisionEnabled(*input, *bodyB, *bodyA, *collection, key)
                .m_cBooleanValue)
        {
            __declspec(align(16)) int buffer[128];
            const hkpShape* childShape = collection->GetShapeForKey(key, *(hkpShapeBuffer*)buffer);
            local_body.m_pCollisionShape = childShape;
            local_body.m_uiCollisionShapeKey = key;

            int typeA = childShape->getType();
            hkpCollisionDispatcher* pDispatcher = input->m_pCollisionDispatcher;
            unsigned char uiAgentIndex = pDispatcher->m_agent2TypeMap[typeA][typeB];
            AgentFunc func = (AgentFunc)pDispatcher->m_agent2Funcs[uiAgentIndex].m_pGetPenetrationsFunc;
            func(&local_body, bodyB, input, collector);
        }
        key = collection->GetNextShapeKey(key);
    }

    hkTimerEnd();
}

extern "C" void __cdecl QueryClosestPoints();

// @fnv 0x00d36920
// src: GUESS 0x00d36920 (confidence: medium)
void __cdecl Object_QueryClosestPoints_Thunk()
{
    QueryClosestPoints();
}

void hkCollectorD347_ProcessState_00d34790();
// @fnv 0x00d36990
// src: GUESS 0x00d36990 (confidence: low)
void Hkpshapecollectionagent_ForwardCall_00d36990()
{
    hkCollectorD347_ProcessState_00d34790();
}

extern char DAT_010cf318[];

struct ContactMgrS;
struct AgentS;

typedef AgentS*(__cdecl* CreateFunc)(const hkpCdBody&, const hkpCdBody&, const CollisionAgentContext&, ContactMgrS*);

inline AgentS* getNewCollisionAgent(const hkpCollisionDispatcher* dispatcher, const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                                                 const CollisionAgentContext& input, ContactMgrS* mgr)
{
    const int typeA = bodyA.m_pCollisionShape->getType();
    const int typeB = bodyB.m_pCollisionShape->getType();
    const unsigned char(*table)[32] = input.m_bCreatePredictiveAgents ? dispatcher->m_agent3TypeMap : dispatcher->m_agent2TypeMap;
    int idx = table[typeA][typeB];
    CreateFunc f = (CreateFunc)dispatcher->m_agent2Funcs[idx].m_pCreateFunc;
    return f(bodyA, bodyB, input, mgr);
}

void hkArrayUtil__reserve(void* alloc, void* arr, int n, int size);

struct CollisionAgentMapRecord
{
    unsigned int m_key;
    AgentS* m_pCollisionAgent;
};

struct AgentArray
{
    CollisionAgentMapRecord* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    CollisionAgentMapRecord m_kStorage[4];

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void GrowArrayCapacity(void* alloc, int n)
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayUtil__reserve(alloc, this, newSize, sizeof(CollisionAgentMapRecord));
        }
    }
    void reserve(int n)
    {
        hkMemoryRouter& r = hkMemoryRouter::getInstance();
        GrowArrayCapacity(r.m_heap, n);
    }
    void init()
    {
        m_data = m_kStorage;
        m_iElementCount = 0;
        m_iCapacityState = 0x80000004;
    }
    CollisionAgentMapRecord* expandByUnchecked(int n)
    {
        int oldSize = m_iElementCount;
        m_iElementCount = oldSize + n;
        return m_data + oldSize;
    }
};

struct RefObjS
{
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
    RefObjS()
    {
        m_sReferenceCount = 1;
    }
    virtual void r00();
};
struct CollisionAgentS : RefObjS
{
    ContactMgrS* m_pContactManager;
    CollisionAgentS(ContactMgrS* mgr)
    {
        m_pContactManager = mgr;
    }
    virtual void a01();
};
struct InplaceArrayS : AgentArray
{
    InplaceArrayS()
    {
        init();
    }
};
struct FUN_00d440f0 : CollisionAgentS
{
    InplaceArrayS m_agents2;
    FUN_00d440f0(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const CollisionAgentContext& input, ContactMgrS* mgr);
    virtual void a02();
};

// Reserves space for the shapes in bodyA's container and appends a key/agent pair for each shape accepted by the filter.
// @fnv 0x00d440f0
FUN_00d440f0::FUN_00d440f0(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const CollisionAgentContext& input,
                           ContactMgrS* apContactMgr)
    : CollisionAgentS(apContactMgr)
{
    hkpCdBody newOperandA(&bodyA);

    const hkpShapeContainer* shapeContainer = bodyA.m_pCollisionShape->GetShapeContainer();
    int size = shapeContainer->GetNumChildShapes();
    m_agents2.reserve(size);

    __declspec(align(16)) unsigned int shapeBuffer[128];

    for (unsigned int key = shapeContainer->GetFirstKey(); key != 0xffffffff;
         key = shapeContainer->GetNextShapeKey(key))
    {
        const hkpShape* shape = shapeContainer->GetShapeForKey(key, *(hkpShapeBuffer*)&shapeBuffer);
        newOperandA.SetCollisionShapeAndKey(shape, key);
        if (input.m_pCollisionFilter->IsCollisionEnabled(input, bodyB, bodyA, *shapeContainer, key).m_cBooleanValue)
        {
            CollisionAgentMapRecord& newPair = *m_agents2.expandByUnchecked(1);
            newPair.m_pCollisionAgent =
                getNewCollisionAgent(input.m_pCollisionDispatcher, newOperandA, bodyB, input, apContactMgr);
            newPair.m_key = key;
        }
    }
}

struct __declspec(align(16)) ShapeBuffer
{
    int m_data[128];
};

struct ConstraintOwner;
struct ContactMgr;
struct CollisionAgent;

typedef CollisionAgent*(__cdecl* CreateFuncA)(const hkpCdBody& a, const hkpCdBody& b, const CollisionAgentContext& input,
                                              ContactMgr* mgr);

inline CollisionAgent* getNewCollisionAgent(const hkpCollisionDispatcher* dispatcher, const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                                                                 const CollisionAgentContext& input, ContactMgr* mgr)
{
    int typeA = bodyA.getShape()->getType();
    int typeB = bodyB.getShape()->getType();
    const unsigned char* agentTypeTablePtr =
        (input.m_bCreatePredictiveAgents) ? &dispatcher->m_agent3TypeMap[0][0] : &dispatcher->m_agent2TypeMap[0][0];
    int agentType = agentTypeTablePtr[typeA * 32 + typeB];
    CreateFuncA f = (CreateFuncA)dispatcher->m_agent2Funcs[agentType].m_pCreateFunc;
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
    virtual void ProcessContactPoints(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const CollisionAgentContext& input,
                                      ConstraintOwner& owner);
};

void __cdecl ResizeAudioStream(void* alloc, void* arr, int elemSize);

__forceinline hkMemoryRouter* getRouter()
{
    return &hkMemoryRouter::getInstance();
}

inline hkMemoryAllocator& getRouterHeap(hkMemoryRouter* router)
{
    return *router->m_heap;
}

__forceinline void memCpyOneAligned8(void* dst, const void* src)
{
    int i = 0;
    do
    {
        static_cast<unsigned int*>(dst)[i] = static_cast<const unsigned int*>(src)[i];
    } while (++i < 2);
}

struct KeyAgentPairA
{
    unsigned int m_key;
    CollisionAgent* m_pCollisionAgent;
};

struct AgentPairArrayLocalForm
{ // local form of hkArray: 0x00d43f10 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    KeyAgentPairA* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    KeyAgentPairA& operator[](int i)
    {
        return m_data[i];
    }

    KeyAgentPairA& AllocatePair()
    {
        hkMemoryAllocator& a = getRouterHeap(getRouter());
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&a, this, sizeof(KeyAgentPairA));
        return m_data[m_iElementCount++];
    }

    void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
        {
            memCpyOneAligned8(m_data + index, m_data + m_iElementCount);
        }
    }
};

class ShapeCollectionAgentA
{
  public:
    virtual void v00();
    int unk04;
    ContactMgr* m_pContactManager;
    AgentPairArrayLocalForm m_pAgents;

    int findAgent(unsigned int key) const
    {
        for (int i = 0; i < m_pAgents.m_iElementCount; i++)
        {
            if (m_pAgents.m_data[i].m_key == key)
                return i;
        }
        return -1;
    }

    void hkpShapeCollectionAgent_updateShapeCollectionFilter(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const CollisionAgentContext& input,
                      ConstraintOwner& constraintOwner);
};

// Iterates shape keys in bodyA's container, creating or updating collision agents for enabled pairs and removing agents for disabled ones.
// @fnv 0x00d43f10
// src: HAVOK_LIB 0x00d43f10
void ShapeCollectionAgentA::hkpShapeCollectionAgent_updateShapeCollectionFilter(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const CollisionAgentContext& input,
                                         ConstraintOwner& constraintOwner)
{
    hkpCdBody newOperandA(&bodyA);
    const hkpShapeContainer* container = bodyA.getShape()->GetShapeContainer();
    ShapeBuffer shapeBuffer;

    for (unsigned int key = container->GetFirstKey(); key != 0xffffffff; key = container->GetNextShapeKey(key))
    {
        int index = findAgent(key);

        if (input.m_pCollisionFilter->IsCollisionEnabled(input, bodyB, bodyA, *container, key))
        {
            newOperandA.SetCollisionShapeAndKey(container->GetShapeForKey(key, *(hkpShapeBuffer*)&shapeBuffer), key);
            if (index == -1)
            {
                KeyAgentPairA& pair = m_pAgents.AllocatePair();
                pair.m_key = key;
                pair.m_pCollisionAgent =
                    getNewCollisionAgent(input.m_pCollisionDispatcher, newOperandA, bodyB, input, m_pContactManager);
            }
            else
            {
                m_pAgents[index].m_pCollisionAgent->ProcessContactPoints(newOperandA, bodyB, input, constraintOwner);
            }
        }
        else if (index != -1)
        {
            m_pAgents[index].m_pCollisionAgent->cleanup(constraintOwner);
            m_pAgents.removeAt(index);
        }
    }
}

#include <windows.h>
extern DWORD g_tlsIndex;

struct Rec
{
    const char* name;
    unsigned int ticks;
    int unk08;
};

struct Handler
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14(hkpCdBody* packet, int a, int b, int c, int d);
};

struct __declspec(align(16)) B16
{
    int a;
    int b;
    int c;
    int d;
};
struct B64
{
    B16 a;
    B16 b;
    B16 c;
    B16 d;
};
struct B256
{
    B64 a;
    B64 b;
    B64 c;
    B64 d;
};
struct B512
{
    B256 a;
    B256 b;
};

// Calling convention note: declared __thiscall as in the packet (this in ecx, callee pops 20 bytes).
struct Agent : hkpShapeCollectionAgent
{
    void hkpShapeCollectionAgent_linearCast(hkpCdBody* holder, int a, int b, int c, int d);
};

// Records profiler markers, resolves each pair's shape key, and dispatches its child body to the handler.
// @fnv 0x00d43aa0
// src: HAVOK_LIB 0x00d43aa0
void Agent::hkpShapeCollectionAgent_linearCast(hkpCdBody* holder, int a, int b, int c, int d)
{
    hkMonitorStream* pb = (hkMonitorStream*)TlsGetValue(g_tlsIndex);
    Rec* cur = (Rec*)pb->m_end.val();
    if (cur < (Rec*)pb->m_capacityMinus16.val())
    {
        volatile unsigned int t;
        cur->name = "TtShapeCollection";
        _ReadWriteBarrier();
        t = (unsigned int)__rdtsc();
        cur->ticks = t;
        pb->m_end.m_storage = (char*)(cur + 1);
    }
    const hkpShapeContainer* q = holder->m_pCollisionShape->GetShapeContainer();
    hkpCdBody packet;
    B512 buf;
    packet.m_pMotionState = holder->m_pMotionState;
    packet.m_parent = holder;
    Pair* p = (Pair*)p2;
    for (int i = count - 1; i >= 0; i--)
    {
        int id = p->a;
        const hkpShape* r = q->GetShapeForKey(id, *(hkpShapeBuffer*)&buf);
        packet.m_pCollisionShape = r;
        packet.m_uiCollisionShapeKey = id;
        ((Handler*)p->b)->v14(&packet, a, b, c, d);
        p++;
    }
    pb = (hkMonitorStream*)TlsGetValue(g_tlsIndex);
    cur = (Rec*)pb->m_end.val();
    if (cur < (Rec*)pb->m_capacityMinus16.val())
    {
        volatile unsigned int t;
        cur->name = "Et";
        _ReadWriteBarrier();
        t = (unsigned int)__rdtsc();
        cur->ticks = t;
        pb->m_end.m_storage = (char*)(cur + 1);
    }
}

extern DWORD DAT_0126835c;

struct S_00d43cd0_TimerCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
};

static inline void S_00d43cd0_Timer(const char* name)
{
    hkMonitorStream* s = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    if (s->m_end.m_storage < s->m_capacityMinus16.m_storage)
    {
        S_00d43cd0_TimerCommand* h = (S_00d43cd0_TimerCommand*)s->m_end.val();
        h->m_pCommandName = name;
        _ReadWriteBarrier();
        unsigned int t = (unsigned int)__rdtsc();
        h->m_uiStartTicks = *(volatile unsigned int*)&t;
        s->m_end.m_storage = (char*)(h + 1);
    }
}

struct __declspec(align(16)) S_00d43cd0_ShapeBuffer
{
    unsigned int m_data[128];
};

struct S_00d43cd0_Input;

struct S_00d43cd0_Collector
{
    void* vtbl;
    char m_fHitDistance;
};

struct S_00d43cd0_Agent
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void process(const hkpCdBody& a, const hkpCdBody& b, const S_00d43cd0_Input& input,
                         S_00d43cd0_Collector& c);
};

struct S_00d43cd0_Entry
{
    unsigned int m_key;
    S_00d43cd0_Agent* m_pCollisionAgent;
};

struct S_00d43cd0
{
    void* vtbl;
    int unk04;
    int unk08;
    S_00d43cd0_Entry* m_entries;
    int m_iElementCount;
    void ProcessCollisionEntries(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                                 const S_00d43cd0_Input& input, S_00d43cd0_Collector& collector);
};

// Iterates m_entries, resolving each key to a shape, and calls the agent's process on bodyA/bodyB until the collector reports a hit.
// @fnv 0x00d43cd0
void S_00d43cd0::ProcessCollisionEntries(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                                         const S_00d43cd0_Input& input, S_00d43cd0_Collector& collector)
{
    S_00d43cd0_Timer("TtShapeCollection");

    const hkpShapeContainer* container = bodyA.m_pCollisionShape->GetShapeContainer();
    hkpCdBody newBodyA(&bodyA);
    S_00d43cd0_ShapeBuffer shapeBuffer;

    S_00d43cd0_Entry* pEntry = m_entries;
    int n = m_iElementCount - 1;
    if (n >= 0)
    {
        do
        {
            unsigned int key = pEntry->m_key;
            const hkpShape* shape = container->GetShapeForKey(key, *(hkpShapeBuffer*)&shapeBuffer);
            newBodyA.SetCollisionShapeAndKey(shape, key);
            pEntry->m_pCollisionAgent->process(newBodyA, bodyB, input, collector);
            if (collector.m_fHitDistance)
                break;
            pEntry++;
        } while (--n >= 0);
    }

    S_00d43cd0_Timer("Et");
}

extern DWORD hkMonitorStreamTls;

struct S_00d43dc0_TimerCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
};

static inline void S_00d43dc0_Timer(const char* name)
{
    hkMonitorStream* s = (hkMonitorStream*)TlsGetValue(hkMonitorStreamTls);
    if (s->m_end.m_storage < s->m_capacityMinus16.m_storage)
    {
        S_00d43dc0_TimerCommand* h = (S_00d43dc0_TimerCommand*)s->m_end.val();
        h->m_pCommandName = name;
        _ReadWriteBarrier();
        unsigned int t = (unsigned int)__rdtsc();
        h->m_uiStartTicks = *(volatile unsigned int*)&t;
        s->m_end.m_storage = (char*)(h + 1);
    }
}

struct S_00d43dc0_Bool
{
    char m_cBooleanValue;
    S_00d43dc0_Bool()
    {}
    S_00d43dc0_Bool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct __declspec(align(16)) S_00d43dc0_ShapeBuffer
{
    unsigned int m_data[128];
};

struct S_00d43dc0_CdBodyPairCollector
{
    void* vtbl;
    S_00d43dc0_Bool m_fHitDistance;
    S_00d43dc0_Bool getEarlyOut() const
    {
        return m_fHitDistance;
    }
};

typedef void(__cdecl* S_00d43dc0_GetPenetrationsFunc)(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                                                      const CollisionAgentContext& input,
                                                      S_00d43dc0_CdBodyPairCollector& collector);

// Iterates shapes in bodyA's container, calls the dispatcher's penetration query for each enabled shape, and stops early if the collector requests it.
// @fnv 0x00d43dc0
// src: HAVOK_LIB 0x00d43dc0
void __cdecl hkpShapeCollectionAgent_staticGetPenetrations(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                          const CollisionAgentContext& input, S_00d43dc0_CdBodyPairCollector& collector)
{
    S_00d43dc0_Timer("TtShapeCollection");

    const hkpShapeContainer* shapeContainer = bodyA.getShape()->GetShapeContainer();
    hkpCdBody newOperandA(&bodyA);

    int typeB = bodyB.getShape()->getType();
    S_00d43dc0_ShapeBuffer shapeBuffer;

    for (unsigned int key = shapeContainer->GetFirstKey(); key != 0xffffffff;
         key = shapeContainer->GetNextShapeKey(key))
    {
        if (input.m_pCollisionFilter->IsCollisionEnabled(input, bodyB, bodyA, *shapeContainer, key))
        {
            const hkpShape* shape = shapeContainer->GetShapeForKey(key, *(hkpShapeBuffer*)&shapeBuffer);
            newOperandA.SetCollisionShapeAndKey(shape, key);
            S_00d43dc0_GetPenetrationsFunc getPenetrationsFunc =
                (S_00d43dc0_GetPenetrationsFunc)input.m_pCollisionDispatcher->m_agent2Funcs[
                    input.m_pCollisionDispatcher->m_agent2TypeMap[shape->getType()][typeB]].m_pQueryPenetrationsFunc;
            getPenetrationsFunc(newOperandA, bodyB, input, collector);
            if (collector.getEarlyOut())
            {
                break;
            }
        }
    }

    S_00d43dc0_Timer("Et");
}

extern "C" void _ReadWriteBarrier(void);

extern DWORD DAT_0126835c;

unsigned __int64 __cdecl __rdtsc(void);

struct KeyedPointerEntry
{
    DWORD m_key;
    void* m_pEntryObject;
};

__declspec(align(16)) struct ShapeKeyBuf
{
    DWORD m_key;
    DWORD unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C,
        unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C,
        unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC,
        unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC, unkE0, unkE4, unkE8, unkEC, unkF0, unkF4, unkF8, unkFC,
        unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C, unk120, unk124, unk128, unk12C, unk130, unk134,
        unk138, unk13C, unk140, unk144, unk148, unk14C, unk150, unk154, unk158, unk15C, unk160, unk164, unk168, unk16C,
        unk170, unk174, unk178, unk17C, unk180, unk184, unk188, unk18C, unk190, unk194, unk198, unk19C, unk1A0, unk1A4,
        unk1A8, unk1AC, unk1B0, unk1B4, unk1B8, unk1BC, unk1C0, unk1C4, unk1C8, unk1CC, unk1D0, unk1D4, unk1D8, unk1DC,
        unk1E0, unk1E4, unk1E8, unk1EC, unk1F0;
};

class ShapeObject
{
  public:
    virtual void vtbl00(void);
    virtual void vtbl04(void);
    virtual void vtbl08(void);
    virtual void vtbl0C(void);
    virtual void vtbl10(void* pKey, DWORD a1, DWORD a2, DWORD a3);
};

struct FUN_00d43880_cls : public hkpShapeCollectionAgent
{
    void hkpShapeCollectionAgent_getClosestPoints(hkpCdBody* pHolder, DWORD a1, DWORD a2, DWORD a3);
};

// Between profiler records, resolves each key to a child body and passes it to the pair's object.
// @fnv 0x00d43880
// src: HAVOK_LIB 0x00d43880
void FUN_00d43880_cls::hkpShapeCollectionAgent_getClosestPoints(hkpCdBody* pHolder, DWORD a1, DWORD a2, DWORD a3)
{
    hkMonitorStream* pBuf = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    if (pBuf->m_end.m_storage < pBuf->m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* pRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pBuf->m_end.m_storage);
        pRec->m_commandAndMonitor = "TtShapeCollection";
        _ReadWriteBarrier();
        volatile DWORD tick = (DWORD)__rdtsc();
        pRec->m_time0 = tick;
        pBuf->m_end.m_storage = reinterpret_cast<char*>(pRec + 1);
    }

    const hkpShapeContainer* pHandler = pHolder->m_pCollisionShape->GetShapeContainer();
    hkpCdBody res;
    res.m_pMotionState = pHolder->m_pMotionState;
    int i = this->count - 1;
    res.m_parent = pHolder;
    KeyedPointerEntry* apPairs = (KeyedPointerEntry*)this->p2;
    ShapeKeyBuf keyBuf;
    if (i >= 0)
    {
        do
        {
            DWORD key = apPairs->m_key;
            res.m_pCollisionShape = pHandler->GetShapeForKey(key, *(hkpShapeBuffer*)&keyBuf);
            res.m_uiCollisionShapeKey = key;
            ShapeObject* pObj = (ShapeObject*)apPairs->m_pEntryObject;
            pObj->vtbl10(&res, a1, a2, a3);
            apPairs++;
            i--;
        } while (i >= 0);
    }

    pBuf = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    if (pBuf->m_end.m_storage < pBuf->m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* pRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pBuf->m_end.m_storage);
        pRec->m_commandAndMonitor = "Et";
        _ReadWriteBarrier();
        volatile DWORD tick = (DWORD)__rdtsc();
        pRec->m_time0 = tick;
        pBuf->m_end.m_storage = reinterpret_cast<char*>(pRec + 1);
    }
}

extern const char str_010cf300[];
extern const char str_010c41f8[];

__declspec(align(16)) struct hkpShapeBuffer
{
    unsigned long m_data[125];
};

typedef void(__cdecl* LinearCastFunc)(const hkpCdBody* local_body, const hkpCdBody* bodyB,
                                      const CollisionAgentContext* input, void* a4, void* a5);

// Iterates each shape in bodyA's collection, dispatches the linear-cast agent for enabled shapes against bodyB, and times the work.
// @fnv 0x00d43b90
// src: HAVOK_LIB 0x00d43b90
void __cdecl hkpShapeCollectionAgent_staticLinearCast(const hkpCdBody* bodyA, const hkpCdBody* bodyB, const CollisionAgentContext* input, void* a4,
                          void* a5)
{
    hkTimerBegin(str_010cf300);

    const hkpShapeContainer* collection = bodyA->m_pCollisionShape->GetShapeContainer();
    hkpCdBody localBody;
    localBody.m_pMotionState = bodyA->m_pMotionState;
    localBody.m_parent = bodyA;

    int typeB = bodyB->m_pCollisionShape->getType();
    unsigned int key = collection->GetFirstKey();
    if (key != -1)
    {
        do
        {
            if (input->m_pCollisionFilter->IsCollisionEnabled(*input, *bodyB, *bodyA, *collection, key)
                    .m_cBooleanValue)
            {
                hkpShapeBuffer buffer;
                const hkpShape* childShape = collection->GetShapeForKey(key, buffer);
                localBody.m_pCollisionShape = childShape;
                localBody.m_uiCollisionShapeKey = key;

                int typeA = childShape->getType();
                unsigned char agentType = input->m_pCollisionDispatcher->m_agent2TypeMap[typeA][typeB];
                LinearCastFunc func = (LinearCastFunc)input->m_pCollisionDispatcher->m_agent2Funcs[agentType].m_pLinearCastFunc;
                func(&localBody, bodyB, input, a4, a5);
            }
            key = collection->GetNextShapeKey(key);
        } while (key != -1);
    }

    hkTimerBegin(str_010c41f8);
}

extern "C" void _ReadWriteBarrier(void);

extern DWORD DAT_0126835c;

unsigned __int64 __cdecl __rdtsc(void);

struct CollectionProcessHandler
{
    virtual void v00(void);
    virtual void v04(void);
    virtual void v08(void);
    virtual void v0c(void);
    virtual CollectionProcessHandler* v10(void);
    virtual void* v14(void* pShape, void* pOut);
    virtual void v18(void* apPairs, unsigned int a0, unsigned int a1, unsigned int a2);
};

struct CollectionProcessEntry
{
    void* pShape;
    CollectionProcessHandler* pHandler;
};

struct CollectionProcessAgent : hkpShapeCollectionAgent
{
    void hkpShapeCollectionAgent_processCollision(hkpCdBody* arg, unsigned int a0, unsigned int a1, unsigned int a2);
};

// Records profiler ticks around resolving child bodies and dispatching each through v18.
// @fnv 0x00d437a0
// src: HAVOK_LIB 0x00d437a0
void CollectionProcessAgent::hkpShapeCollectionAgent_processCollision(hkpCdBody* arg, unsigned int a0, unsigned int a1, unsigned int a2)
{
    hkMonitorStream* pBuf = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    if (pBuf->m_end.m_storage < pBuf->m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* pRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pBuf->m_end.m_storage);
        pRec->m_commandAndMonitor = "TtShapeCollection";
        _ReadWriteBarrier();
        volatile DWORD tick = (DWORD)__rdtsc();
        pRec->m_time0 = tick;
        pBuf->m_end.m_storage = reinterpret_cast<char*>(pRec + 1);
    }

    const hkpShapeContainer* pRes = arg->m_pCollisionShape->GetShapeContainer();
    hkpCdBody pair;
    hkpShapeBuffer out;
    pair.m_pMotionState = arg->m_pMotionState;
    pair.m_parent = arg;

    CollectionProcessEntry* pEntry = (CollectionProcessEntry*)p2;
    for (int i = count - 1; i >= 0; i--)
    {
        void* shape = pEntry->pShape;
        pair.m_pCollisionShape = pRes->GetShapeForKey((unsigned int)shape, out);
        pair.m_uiCollisionShapeKey = (unsigned int)shape;
        pEntry->pHandler->v18(&pair, a0, a1, a2);
        pEntry++;
    }

    pBuf = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    if (pBuf->m_end.m_storage < pBuf->m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* pRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pBuf->m_end.m_storage);
        pRec->m_commandAndMonitor = "Et";
        _ReadWriteBarrier();
        volatile DWORD tick = (DWORD)__rdtsc();
        pRec->m_time0 = tick;
        pBuf->m_end.m_storage = reinterpret_cast<char*>(pRec + 1);
    }
}
