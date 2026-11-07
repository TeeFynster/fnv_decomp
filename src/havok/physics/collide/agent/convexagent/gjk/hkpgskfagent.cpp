// src/havok/physics/collide/agent/convexagent/gjk/hkpgskfagent.cpp
// Functions are listed by their @fnv annotations.

#include "../../../../../../../include/hkpGskfAgent.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkMemoryRouter.h"
// This placement form has no deallocation callback: the original factory
// constructs directly in storage owned by the Havok allocator.
struct GskAgentStorage
{
    void* p;
    explicit GskAgentStorage(void* storage) : p(storage) {}
};
inline void* __cdecl operator new(std::size_t, GskAgentStorage storage) { return storage.p; }

inline hkpCollisionDispatcher::CollisionAgentFunctionTable::CollisionAgentFunctionTable() {}

void __cdecl TestGsk();
void __cdecl FUN_00dac450();
void __cdecl Object_ProcessEntries_00daf8e0();

// @fnv 0x00dacc70
__declspec(noinline) void __cdecl hkpGskfAgent::InitAgentFunc(hkpCollisionDispatcher::CollisionAgentFunctionTable& f)
{
    f.m_pCreateFunc = m_pVirtualFunction0;
    f.m_pQueryPenetrationsFunc = (hkpCollisionDispatcher::GetPenetrationsFunc)TestGsk;
    f.m_pGetPenetrationsFunc = (hkpCollisionDispatcher::GetClosestPointsFunc)FUN_00dac450;
    f.m_pLinearCastFunc = (hkpCollisionDispatcher::LinearCastFunc)Object_ProcessEntries_00daf8e0;
    f.m_bIsFlipped = false;
    f.m_bIsPredictive = false;
}

void __cdecl ReleaseAllEntries(void*, void*, void*);

// @fnv 0x00dacaf0
void hkpGskfAgent::cleanup(hkpConstraintOwner& arg)
{
    ReleaseAllEntries(&m_kContactManifold, m_pContactManager, &arg);
    delete this;
}

void __cdecl _hkGskManifold_removePoint(void*, int);

// @fnv 0x00dacb20
void hkpGskfAgent::removePoint(hkContactPointId id)
{
    int count = m_kContactManifold.m_usNumContactPoints;
    int i = 0;
    if (count > 0)
    {
        char* p = (char*)&m_kContactManifold.m_akContactPoints[0].m_iOwnerObjectOffset;
        do
        {
            if (*(unsigned short*)p == id)
            {
                _hkGskManifold_removePoint(&m_kContactManifold, i);
                return;
            }
            ++i;
            p += 8;
        } while (i < count);
    }
}

// @fnv 0x00dacb60
void hkpGskfAgent::CommitPotentialContactPoint(hkContactPointId value)
{
    int count = m_kContactManifold.m_usNumContactPoints;
    int i;

    for (i = 0; i < count; ++i)
    {
        if (m_kContactManifold.m_akContactPoints[i].m_iOwnerObjectOffset == 0xffff)
        {
            m_kContactManifold.m_akContactPoints[i].m_iOwnerObjectOffset = value;
            return;
        }
    }
}

// @fnv 0x00dacbd0
__declspec(noinline) hkpGskfAgent::hkpGskfAgent(const hkpCdBody& a, const hkpCdBody& b, hkpContactMgr* c) : hkpGskBaseAgent(a, b, c)
{
    *(int*)&m_kContactManifold = 0;
}

// @fnv 0x00dacba0
void hkpGskfAgent::MarkContactPointAsZombie(hkContactPointId id)
{
    for (int i = 0; i < m_kContactManifold.m_usNumContactPoints; i++)
    {
        ConvexContactManifold::AlignedPairData& kSlot = m_kContactManifold.m_akContactPoints[i];
        if (kSlot.m_iOwnerObjectOffset == id)
        {
            kSlot.m_ucDimensionA = 0;
            kSlot.m_ucDimensionB = 0;
            return;
        }
    }
}

struct Dvec4
{
    float x, y, z, w;
};

struct __declspec(align(16)) Dsub
{
    Dvec4 v0, v1, v2, v3;
    Dvec4 unk40, unk50;
    void hkTransform_setMulInverseMul(Dvec4* pts, Dvec4* other);
};

struct Dtask
{
    void* f00;
    void* f04;
    int f08;
    void* f0c;
    int f10;
    int unk14;
    int unk18;
    int unk1c;
    Dsub sub;
};

struct Dctx
{
    int f0;
    int f1;
    int f2;
    int f3;
};

struct Dsrc
{
    int unk00;
    int unk04;
    Dvec4* f08;
};

void ProcessCollision(Dtask* task, int* ctx1, int* ctx2, int* node, int* a5, int* a6, int a7);

// @fnv 0x00daccd0
void hkpGskfAgent::ProcessAgent(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const GskAgentInput& input, WorldOperationEntry& result)
{
    Dsrc* a1 = (Dsrc*)&bodyA;
    Dsrc* a2 = (Dsrc*)&bodyB;
    Dsrc* a3 = (Dsrc*)&input;
    int a4 = (int)&result;
    Dctx ctx;
    Dtask res;
    res.f08 = 0;
    res.f00 = a1;
    res.f04 = a2;
    res.f10 = (int)m_pContactManager;
    res.f0c = a3;
    res.sub.hkTransform_setMulInverseMul(a1->f08, a2->f08);
    ProcessCollision(&res, &ctx.f0, &ctx.f1, (int*)m_pAccess, (int*)&m_kContactManifold, (int*)&m_vSeparatingNormal, a4);
}

struct hkAllocHeaderDACC
{
    void* vtable;
    unsigned short allocationSize;
};

// Read the router heap slot as its allocator type, preserving the original aliasing.
inline hkMemoryAllocator& getAgentHeap(hkMemoryRouter& router)
{
    return **reinterpret_cast<hkMemoryAllocator**>(&router.m_heap);
}

inline void* allocateAgentDACC(int nbytes)
{
    void* b = getAgentHeap(*(&hkMemoryRouter::getInstance())).blockAlloc(nbytes);
    static_cast<hkAllocHeaderDACC*>(b)->allocationSize = (unsigned short)nbytes;
    return b;
}

// @fnv 0x00dacc00
hkpCollisionAgent* __cdecl hkpGskfAgent::m_pVirtualFunction0(const hkpCdBody& a, const hkpCdBody& b, const CollisionAgentContext& unused, hkpContactMgr* c)
{
    if (c)
        return ::new (GskAgentStorage(allocateAgentDACC(0x80))) hkpGskfAgent(a, b, c);
    return ::new (GskAgentStorage(allocateAgentDACC(0x30))) hkpGskBaseAgent(a, b, 0);
}

// The approved dispatcher header does not yet declare this registration entry.
struct GskAgentRegistration
{
    void registerCollisionAgent(hkpCollisionDispatcher::CollisionAgentFunctionTable& funcs, int a, int b);
};

// @fnv 0x00dacca0
void __cdecl hkpGskfAgent::RegisterCapsuleCapsuleAgent(hkpCollisionDispatcher* dispatcher)
{
    hkpCollisionDispatcher::CollisionAgentFunctionTable funcs;
    funcs.m_bIsFlipped = false;
    funcs.m_bIsPredictive = false;
    InitAgentFunc(funcs);
    ((GskAgentRegistration*)dispatcher)->registerCollisionAgent(funcs, 0x12, 0x12);
}
