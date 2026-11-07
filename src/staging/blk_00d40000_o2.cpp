#include "../../include/hkArray.h"

// src/staging/blk_00d40000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

// Keep the unit's SIMD intrinsic ABI when loading the shared vector declaration.
// Exe 0x00d48fc0 FUN_00d48fc0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;

// This unit supplies the original out-of-line vector assignment at 0x00d54e40.
#define FNV64_HKVECTOR4_OWN_ASSIGN
#include "../../include/hkVector4.h"
#include "../../include/layout_support.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/FinishingFlag.h"
#include "../../include/NiStream.h"
#include "../../include/hkStringPtr.h"
#include "../../include/hkBool.h"

#include "../../include/hkReferencedObject.h"
#include "../../include/hkMemoryAllocator.h"
#include "../../include/AutoMemContext.h"
#include "../../include/hkError.h"
#include "../../include/hkOstream.h"
#include "../../include/hkBaseObject.h"
#include "../../include/NiObject.h"
#include "../../include/NiTPointerMap.h"
#include "../../include/NiTMapItem.h"
#include "../../include/bhkRefObject.h"
#include "../../include/bhkListShape.h"
#include "../../include/bhkWorldObject.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/hkRotation.h"
#include "../../include/hkpConvexShape.h"
#include "../../include/hkpSingleShapeContainer.h"
#include "../../include/hkpShapeContainer.h"


extern __declspec(thread) int g_ThreadMemoryContext;

__forceinline AutoMemContext::AutoMemContext(int context)
{
    m_eMemoryContext = static_cast<MEM_CONTEXT>(g_ThreadMemoryContext);
    g_ThreadMemoryContext = context;
}
__forceinline AutoMemContext::~AutoMemContext()
{
    g_ThreadMemoryContext = m_eMemoryContext;
}

// Keep the original inline construction and destruction on the shared layouts.

struct FUN_00c9ce00_cls
{
    void __thiscall FUN_00c9ce00(int);
};
extern int DAT_010c7888;

// @fnv 0x00d49530
// src: HAVOK_LIB 0x00d49530
void __cdecl finishLoadedObjecthkpRigidBody(FUN_00c9ce00_cls* pObject, int aiValue)
{
    if (pObject)
    {
        pObject->FUN_00c9ce00(aiValue);
        *(int*)pObject = (int)&DAT_010c7888;
    }
}

extern "C" void __cdecl AppendEventRecord(int, int, int, int);

// @fnv 0x00d4de30
// src: HAVOK_LIB 0x00d4de30
void __stdcall hkpBreakableConstraintData_buildNopJacobian(int a, int b)
{
    AppendEventRecord(a, b, 0, 8);
}

struct FUN_00d53200_class
{
    void hkConstraintCinfo_LoadBinary(NiStream& stream);
    void hkConstraintChainCinfo_LoadBinary(void* stream);
};

// @fnv 0x00d53200
// src: XBOX_PDB 0x00d53200
void FUN_00d53200_class::hkConstraintChainCinfo_LoadBinary(void* stream)
{
    NiStream& input = *static_cast<NiStream*>(stream);
    input.ReadUnsignedInteger();
    hkConstraintCinfo_LoadBinary(input);
}

void* __cdecl InitAndGetOffset(void*, void*, void*);
void __cdecl RemoveEntryByKey(void);
void __cdecl FindOrClaimEntry(void);
void __cdecl nullsub_16(void);
void __cdecl ResetEntryAgents(void);
void __cdecl Runtime_ResetEntryAgents_Thunk(void);
void __cdecl hkBoxBoxAgent3_process(void);

// Fills the object's function-pointer slots with the given handlers, zeroes slots 6 and 10, and clears the byte at offset 0x30.
// @fnv 0x00d400f0
// src: HAVOK_LIB 0x00d400f0
void __cdecl hkBoxBoxAgent3_initAgentFunc(void* apObject)
{
    void** f = (void**)apObject;
    f[0] = (void*)&InitAndGetOffset;
    f[11] = (void*)&hkBoxBoxAgent3_process;
    f[10] = 0;
    f[2] = (void*)&ResetEntryAgents;
    f[3] = (void*)&RemoveEntryByKey;
    f[4] = (void*)&FindOrClaimEntry;
    f[5] = (void*)&nullsub_16;
    f[6] = 0;
    f[1] = (void*)&Runtime_ResetEntryAgents_Thunk;
    ((char*)f)[0x30] = 0;
}

void __cdecl DispatchInputRecord();
void __cdecl hkPredGskAgent3_process();
void __cdecl hkPredGskAgent3_sepNormal();
void __cdecl FUN_00d41860();
void __cdecl RemoveEntryById();
void __cdecl InsertSlotId();
void __cdecl FindEntryByKey();
void __cdecl ForwardToTarget();

// Fills the object's vtable slots with function pointers and sets the byte at p+48 to 1.
// @fnv 0x00d41ec0
// src: HAVOK_LIB 0x00d41ec0
void __cdecl hkPredGskAgent3_initAgentFunc(int* pObject)
{
    *pObject = (int)&DispatchInputRecord;
    pObject[0x2c / 4] = (int)&hkPredGskAgent3_process;
    pObject[0x28 / 4] = (int)&hkPredGskAgent3_sepNormal;
    pObject[2] = (int)&FUN_00d41860;
    pObject[3] = (int)&RemoveEntryById;
    pObject[4] = (int)&InsertSlotId;
    pObject[5] = (int)&FindEntryByKey;
    pObject[1] = (int)&ForwardToTarget;
    *(unsigned char*)(pObject + 12) = 1;
}

extern int DAT_010cf9a4;
// @fnv 0x00d48350
// src: GUESS 0x00d48350 (confidence: low)
void __cdecl Runtime_UpdateState_00d48350(int* p)
{
    if (p)
        *p = (int)&DAT_010cf9a4;
}

struct FUN_00d49580_vtbl
{
    virtual void v0(int);
};

// @fnv 0x00d49580
// src: GUESS 0x00d49580 (confidence: low)
void __cdecl Object_InvokeVirtualMethod_00d49580(FUN_00d49580_vtbl* p)
{
    p->v0(0);
}

extern int DAT_010305a8;
extern int DAT_010ce31c;
extern int DAT_010cfb34;

// @fnv 0x00d495a0
// src: GUESS 0x00d495a0 (confidence: low)
void __cdecl Object_UpdateFields_00d495a0(int* pObject, int b)
{
    if (pObject)
    {
        *pObject = (int)&DAT_010305a8;
        if (b)
            pObject[3] = 0;
        pObject[3] = 0x19;
        *pObject = (int)&DAT_010ce31c;
        if (b)
            pObject[3] = 0xd;
        *pObject = (int)&DAT_010cfb34;
        if (b)
            ((char*)pObject)[0x1d] = 0;
    }
}

// @fnv 0x00d4b190
// src: GUESS 0x00d4b190 (confidence: low)
void __cdecl Runtime_Helper_00d4b190(void* p)
{
    ((void(__thiscall*)(void*, int))(*reinterpret_cast<void***>(p))[0])(p, 0);
}

struct FUN_00d4b250_class
{
    void __thiscall Runtime_ForwardCall_00d4b250(int);
};
struct FUN_00d4b250_vt
{
    virtual void __thiscall Runtime_ForwardCall_00d4b250(int);
};
// @fnv 0x00d4b250
// src: GUESS 0x00d4b250 (confidence: low)
void __cdecl Runtime_ForwardCall_00d4b250(FUN_00d4b250_vt* p)
{
    p->Runtime_ForwardCall_00d4b250(0);
}

struct FUN_00d4be50_vt
{
    virtual void Runtime_ForwardCall_00d4be50(int);
};
// @fnv 0x00d4be50
// src: GUESS 0x00d4be50 (confidence: low)
void __cdecl Runtime_ForwardCall_00d4be50(FUN_00d4be50_vt* p)
{
    p->Runtime_ForwardCall_00d4be50(0);
}

struct CollisionAgentFunctionTable
{
    void* f0;
    void* f1;
    void* f2;
    void* f3;
    bool b0;
    bool b1;
};
struct Agent
{
    void __thiscall AppendRecordAndRegisterAgents(CollisionAgentFunctionTable*, int, int);
};
void __cdecl Object_ConstructObject_00d442c0();
void __cdecl hkCollectorD347_ProcessState_00d34790();
void __cdecl QueryClosestPoints();
void __cdecl hkpShapeCollectionAgent_staticLinearCast_UpdateState_00d34810();
void __cdecl AllocateAndInitBlock();
void __cdecl hkpShapeCollectionAgent_staticGetPenetrations();
void __cdecl GetClosestPointsShapeCollection();
void __cdecl hkpShapeCollectionAgent_staticLinearCast();
// @fnv 0x00d44310
// src: HAVOK_LIB 0x00d44310
void __cdecl hkpShapeCollectionAgent_registerAgent(Agent* a)
{
    CollisionAgentFunctionTable af;
    af.f0 = (void*)&Object_ConstructObject_00d442c0;
    af.f1 = (void*)&hkCollectorD347_ProcessState_00d34790;
    af.f2 = (void*)&QueryClosestPoints;
    af.f3 = (void*)&hkpShapeCollectionAgent_staticLinearCast_UpdateState_00d34810;
    af.b0 = true;
    af.b1 = true;
    a->AppendRecordAndRegisterAgents(&af, -1, 7);
    af.f0 = (void*)&AllocateAndInitBlock;
    af.f1 = (void*)&hkpShapeCollectionAgent_staticGetPenetrations;
    af.f2 = (void*)&GetClosestPointsShapeCollection;
    af.f3 = (void*)&hkpShapeCollectionAgent_staticLinearCast;
    af.b0 = false;
    af.b1 = true;
    a->AppendRecordAndRegisterAgents(&af, 7, -1);
}

struct FUN_00d48330_vt
{
    virtual void v0(int);
};
// @fnv 0x00d48330
// src: GUESS 0x00d48330 (confidence: low)
void __cdecl Runtime_ForwardCall_00d48330(FUN_00d48330_vt* p)
{
    p->v0(0);
}

// @fnv 0x00d49510
// src: GUESS 0x00d49510 (confidence: low)
void __cdecl Runtime_ForwardCall_00d49510(FUN_00d49580_vtbl* p)
{
    p->v0(0);
}

struct FUN_00d4b1f0_vt
{
    virtual void __thiscall Runtime_ForwardCall_00d4b1f0(int);
};
// @fnv 0x00d4b1f0
// src: GUESS 0x00d4b1f0 (confidence: low)
void __cdecl Runtime_ForwardCall_00d4b1f0(FUN_00d4b1f0_vt* p)
{
    p->Runtime_ForwardCall_00d4b1f0(0);
}

struct FUN_00d4b320_vt
{
    virtual void v0(int);
};
// @fnv 0x00d4b320
// src: GUESS 0x00d4b320 (confidence: low)
void __cdecl Object_InvokeVirtualMethod_00d4b320(FUN_00d4b320_vt* p)
{
    p->v0(0);
}

// @fnv 0x00d4beb0
// src: GUESS 0x00d4beb0 (confidence: low)
void __cdecl Runtime_ForwardCall_00d4beb0(FUN_00d49580_vtbl* p)
{
    p->v0(0);
}

struct FUN_00d4bf30_vt
{
    virtual void Runtime_ForwardCall_00d4bf30(int);
};

// @fnv 0x00d4bf30
// src: GUESS 0x00d4bf30 (confidence: low)
void __cdecl Runtime_ForwardCall_00d4bf30(FUN_00d4bf30_vt* p)
{
    p->Runtime_ForwardCall_00d4bf30(0);
}

extern const char* const g_01268eb4_arg1;
// @fnv 0x00d4bf60
// src: GUESS 0x00d4bf60 (confidence: low)
const char* const* __cdecl Object_GetGlobalObjectAddress_00d4bf60()
{
    return &g_01268eb4_arg1;
}

struct FUN_00d4fe40_cls
{
    char pad[0xa2];
    bool b0;
    char pad2[0xb2 - 0xa3];
    bool b1;
    void __thiscall hkpPrismaticConstraintData_setMotorActive(void* a, bool b);
};
// Stores the flag and its inverse, then zeroes four floats at a nested pointer when the argument and its sub-pointers are non-null.
// @fnv 0x00d4fe40
// src: HAVOK_LIB 0x00d4fe40
void FUN_00d4fe40_cls::hkpPrismaticConstraintData_setMotorActive(void* apObject, bool abFlag)
{
    b0 = abFlag;
    b1 = !abFlag;
    if (apObject)
    {
        void* p = *(void**)((char*)apObject + 0x30);
        if (p)
        {
            float* f = (float*)*(void**)((char*)p + 0x1c);
            if (f)
            {
                float fZero = 0.0f;
                f[0] = fZero;
                f[1] = fZero;
                f[2] = fZero;
                f[3] = fZero;
            }
        }
    }
}

struct FUN_00d532a0_cls
{
    void __thiscall DispatchToInnerSlot(int);
    void __thiscall ApplyToAllEntries(int arg);
};

// @fnv 0x00d532a0
void __thiscall FUN_00d532a0_cls::ApplyToAllEntries(int aiValue)
{
    int* p = this ? *(int**)((char*)this + 8) : 0;
    int i = 0;
    if (p[0xf] > 0)
    {
        do
        {
            int* e = *(int**)((char*)p + 0x38);
            int* obj = *(int**)((char*)e + i * 4);
            int* v;
            if (obj)
                v = *(int**)((char*)obj + 0xc);
            else
                v = 0;
            void(__thiscall * pfnMethod)(void*, int) = *(void(__thiscall**)(void*, int))(*(int*)v + 0x54);
            pfnMethod(v, aiValue);
            ++i;
        } while (i < p[0xf]);
    }
    DispatchToInnerSlot(aiValue);
}

// CreateSpawnObject: cdecl factory. Allocates one of two object sizes through the
// global allocator holder. A non-zero flag selects the large object (0x80 bytes,
// constructor takes the flag, then the vtable is stored); zero selects the small
// object (0x30 bytes, constructor returns the object).

struct SpawnSmall
{
    int unk00;
    unsigned short m_w04;
    SpawnSmall* __thiscall FUN_00dabf10(int, int, int);
};

struct SpawnLarge
{
    void* m_vptr;
    unsigned short m_w04;
    void __thiscall FUN_00dacbd0(int, int, int);
};

extern char DAT_010ceb94[];

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();

inline void* hkReferencedObject::operator new(std::size_t nbytes)
{
    hkMemoryRouter* holder = hkMemoryRouter_getInstance();
    hkReferencedObject* object = static_cast<hkReferencedObject*>(
        reinterpret_cast<hkMemoryAllocator*>(holder->m_heap)->blockAlloc(nbytes));
    object->m_usMemSizeAndFlags = static_cast<unsigned short>(nbytes);
    return object;
}

// Allocates a 0x80-byte SpawnLarge (or 0x30-byte SpawnSmall when a4 is 0) from the holder's allocator, sets its size field and initializes it.
// @fnv 0x00d41f50
void* __cdecl CreateSpawnObject(int a1, int a2, int a3, int a4)
{
    if (a4 != 0)
    {
        hkMemoryRouter* holder = hkMemoryRouter_getInstance();
        hkMemoryAllocator* allocator = (hkMemoryAllocator*)holder->m_heap;
        SpawnLarge* obj = (SpawnLarge*)allocator->blockAlloc(0x80);
        obj->m_w04 = 0x80;
        obj->FUN_00dacbd0(a1, a2, a4);
        obj->m_vptr = DAT_010ceb94;
        return obj;
    }
    hkMemoryRouter* holder = hkMemoryRouter_getInstance();
    hkMemoryAllocator* allocator = (hkMemoryAllocator*)holder->m_heap;
    SpawnSmall* obj = (SpawnSmall*)allocator->blockAlloc(0x30);
    obj->m_w04 = 0x30;
    return obj->FUN_00dabf10(a1, a2, 0);
}

namespace fnv_00d42800 {

struct D42800MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocator* m_pStreamAllocator;

    hkMemoryAllocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" D42800MemoryRouter& __cdecl hkMemoryRouter_getInstance();

struct D42800Collidable;
struct D42800CollisionInput;
struct D42800ContactMgr;

class D42800Shape
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void HandleCollision(const D42800Collidable* pkA, const D42800Collidable* pkB,
                                 const D42800CollisionInput& kInput);
};

struct D42800CdBody
{
    D42800Shape* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const D42800CdBody* m_parent;

    const D42800Collidable* getRootCollidable() const
    {
        const D42800CdBody* pkBody = this;
        while (pkBody->m_parent)
            pkBody = pkBody->m_parent;
        return reinterpret_cast<const D42800Collidable*>(pkBody);
    }
};

class D42800Agent : public hkReferencedObject
{
  public:
    D42800Agent(const D42800CdBody& kBodyA, const D42800CdBody& kBodyB, D42800ContactMgr* pkMgr) throw();

    int unk08;
    int unk0C;
    int unk10;
    D42800Shape* m_pkShapeA;
    D42800Shape* m_pkShapeB;
    int m_iTypeA;
    int m_iTypeB;
};

// @fnv 0x00d42800
// src: GUESS 0x00d42800 (confidence: low)
D42800Agent* Object_ProcessAndReturnValue_00d42800(const D42800CdBody& kBodyA, const D42800CdBody& kBodyB, const D42800CollisionInput& kInput,
                          D42800ContactMgr* pkMgr)
{
    D42800Agent* pkAgent = new D42800Agent(kBodyA, kBodyB, pkMgr);
    if (pkAgent->m_iTypeA == 0x1d)
    {
        D42800Shape* pkShape = kBodyA.m_pCollisionShape;
        pkShape->HandleCollision(kBodyA.getRootCollidable(), kBodyB.getRootCollidable(), kInput);
        pkAgent->m_pkShapeA = pkShape;
    }
    if (pkAgent->m_iTypeB == 0x1d)
    {
        D42800Shape* pkShape = kBodyB.m_pCollisionShape;
        pkShape->HandleCollision(kBodyB.getRootCollidable(), kBodyA.getRootCollidable(), kInput);
        pkAgent->m_pkShapeB = pkShape;
    }
    return pkAgent;
}
}  // namespace fnv_00d42800

struct FNVDispatchType
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
    virtual void v10();
    virtual void v11(void* first, void* second, int code);
    int m_unk04;
    int m_unk08;
    int m_typeId;
};

struct FNVDispatchNode
{
    FNVDispatchType* m_pName;
    int m_unk04;
    int m_unk08;
    FNVDispatchNode* m_pNext;
};

static FNVDispatchNode* FNVTailOf(FNVDispatchNode* n)
{
    FNVDispatchNode* t = n;
    while (t->m_pNext != 0)
    {
        t = t->m_pNext;
    }
    return t;
}

// If either node's dispatch type has typeId 0x1d, calls its v11 with the two lists' tails and the code, then returns 0.
// @fnv 0x00d428d0
int __cdecl DispatchToType1dNodes(FNVDispatchNode* pNodeA, FNVDispatchNode* pNodeB, int iCode)
{
    if (pNodeA->m_pName->m_typeId == 0x1d)
    {
        FNVDispatchNode* pTailB = FNVTailOf(pNodeB);
        FNVDispatchNode* pTailA = FNVTailOf(pNodeA);
        pNodeA->m_pName->v11(pTailA, pTailB, iCode);
    }
    if (pNodeB->m_pName->m_typeId == 0x1d)
    {
        FNVDispatchNode* pTailA = FNVTailOf(pNodeA);
        FNVDispatchNode* pTailB = FNVTailOf(pNodeB);
        pNodeB->m_pName->v11(pTailB, pTailA, iCode);
    }
    return 0;
}

void __cdecl Object_ProcessAndReturnValue_00d42800();
void __cdecl CallVirtualMethod();
void __cdecl nullsub_17();
void __cdecl nullsub_18();

// @fnv 0x00d42960
// src: GUESS 0x00d42960 (confidence: low)
void __cdecl Object_UpdateFields_00d42960(Agent* apAgent)
{
    CollisionAgentFunctionTable s;
    s.b0 = 0;
    s.f0 = (void*)Object_ProcessAndReturnValue_00d42800;
    s.f1 = (void*)CallVirtualMethod;
    s.f2 = (void*)nullsub_17;
    s.f3 = (void*)nullsub_18;
    s.b1 = 1;
    apAgent->AppendRecordAndRegisterAgents(&s, 0x1d, -1);
    apAgent->AppendRecordAndRegisterAgents(&s, -1, 0x1d);
}

namespace fnv_00d44280 {
// AllocateAndInitBlock : allocates a 0x38 byte block through the global allocator holder,
// stamps the block header size and runs the block constructor with the four
// incoming arguments.

// The freshly allocated block: a 4 byte header prefix followed by a 16 bit
// size stamp, the rest of the 0x38 byte block is filled by the constructor.
struct FUN_00d440f0_cls
{
    int unk00;
    unsigned short unk04;
    void __thiscall FUN_00d440f0(int, int, int, int);
};

// Allocator vtable: slot 0 is unused, slot 1 hands out raw blocks.

// Global allocator holder: the allocator pointer sits at +0x10.

extern hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();

// @fnv 0x00d44280
void __cdecl AllocateAndInitBlock(int a1, int a2, int a3, int a4)
{
    hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAlloc = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
    FUN_00d440f0_cls* pBlock = (FUN_00d440f0_cls*)pAlloc->blockAlloc(0x38);
    pBlock->unk04 = 0x38;
    pBlock->FUN_00d440f0(a1, a2, a3, a4);
}
}  // namespace fnv_00d44280

namespace fnv_00d442c0 {

struct D442C0MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocator* m_pStreamAllocator;

    hkMemoryAllocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" D442C0MemoryRouter& __cdecl hkMemoryRouter_getInstance();

class D442C0Agent : public hkReferencedObject
{
  public:
    __declspec(nothrow) D442C0Agent(const void* a, const void* b, const void* input, void* mgr);

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
};

class D442C0ShapeAgent : public D442C0Agent
{
  public:
    D442C0ShapeAgent(const void* a, const void* b, const void* input, void* mgr) : D442C0Agent(a, b, input, mgr)
    {}
    virtual ~D442C0ShapeAgent();
};

// Allocates a D442C0ShapeAgent with bodyB, bodyA, input and mgr, and returns it as a D442C0Agent pointer.
// @fnv 0x00d442c0
// src: GUESS 0x00d442c0 (confidence: medium)
D442C0Agent* __cdecl Object_ConstructObject_00d442c0(const void* bodyA, const void* bodyB, const void* input, void* mgr)
{
    return new D442C0ShapeAgent(bodyB, bodyA, input, mgr);
}
}  // namespace fnv_00d442c0

struct S_00d48300_Callee
{
    int unk00;

    void __thiscall ReturnSelf(int);
};

struct S_00d48300_Foo
{
    S_00d48300_Callee unk00;
    S_00d48300_Callee unk04;

    S_00d48300_Foo* __thiscall ProcessAndReturnValue_00d48300(volatile int);
};

// Calls FUN_00cb0a70 with a on both unk00 and unk04, then returns this.
// @fnv 0x00d48300
// src: GUESS 0x00d48300 (confidence: low)
S_00d48300_Foo* __thiscall S_00d48300_Foo::ProcessAndReturnValue_00d48300(volatile int a)
{
    unk00.ReturnSelf(a);
    unk04.ReturnSelf(a);
    return this;
}

extern int DAT_01268b9c;

// @fnv 0x00d48340
// src: GUESS 0x00d48340 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00d48340()
{
    return &DAT_01268b9c;
}

extern int DAT_010cf9a4;
// @fnv 0x00d48360
// src: GUESS 0x00d48360 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00d48360()
{
    return &DAT_010cf9a4;
}

struct S_00d483a0_Result
{
    char v;
    S_00d483a0_Result()
    {}
    S_00d483a0_Result(char c)
    {
        v = c;
    }
};

static inline unsigned S_00d483a0_Swap(unsigned value)
{
    unsigned r;
    unsigned char* p = (unsigned char*)&r;
    p[0] = (unsigned char)(value >> 24);
    p[1] = (unsigned char)(value >> 16);
    p[2] = (unsigned char)(value >> 8);
    p[3] = (unsigned char)value;
    return r;
}

// @fnv 0x00d483a0
S_00d483a0_Result CheckMagicPair(unsigned uiFirst, unsigned uiSecond)
{
    char bMatch;
    if ((uiFirst == 0xcab00d1e && uiSecond == 0xd011face) ||
        (S_00d483a0_Swap(uiFirst) == 0xcab00d1e && S_00d483a0_Swap(uiSecond) == 0xd011face))
        bMatch = 1;
    else
        bMatch = 0;
    return S_00d483a0_Result(bMatch);
}

// InitAndCall: cdecl, 5 stack args. Builds a 12-byte temp from (a1, a2),
// reads a field of the temp's returned pointer, calls a 4-arg cdecl helper,
// then disposes the temp and returns the helper result.

struct KeyTemp
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    KeyTemp* Init(void* a, void* b);
    void Dispose();
};

struct KeyTempRef
{
    unsigned int m_00;
    unsigned int m_04;
    void* m_08;
};

void* __cdecl hkSerializeUtil_loadOnHeap(void* p, void* b, void* c, void* d);

// Initialises a KeyTemp from a1 and a2, calls FUN_00d48fc0 with the stored pointer and a3/a4/a5, disposes the temp and returns the result.
// @fnv 0x00d491f0
void* __cdecl InitAndCall(void* volatile a1, void* volatile a2, void* volatile a3, void* volatile a4, void* volatile a5)
{
    KeyTemp keyTemp;
    KeyTempRef* r = (KeyTempRef*)keyTemp.Init(a1, a2);
    void* p = r->m_08;
    void* result = hkSerializeUtil_loadOnHeap(p, a3, a4, a5);
    keyTemp.Dispose();
    return result;
}

extern int DAT_01268bcc;

// @fnv 0x00d49520
// src: GUESS 0x00d49520 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00d49520()
{
    return &DAT_01268bcc;
}

extern int DAT_01268c14;

// @fnv 0x00d49590
// src: GUESS 0x00d49590 (confidence: low)
int __cdecl Runtime_EvaluateValue_00d49590()
{
    return (int)&DAT_01268c14;
}

extern int DAT_010cfb34;

// @fnv 0x00d495f0
// src: GUESS 0x00d495f0 (confidence: low)
int __cdecl Runtime_EvaluateValue_00d495f0()
{
    return reinterpret_cast<int>(&DAT_010cfb34);
}

extern int DAT_010cfd10;

struct FnvVtObj
{
    int m_vptr;

    FnvVtObj* SetVirtualTable_00d49c40(unsigned int unusedArg);
};

// @fnv 0x00d49c40
// src: GUESS 0x00d49c40 (confidence: low)
FnvVtObj* FnvVtObj::SetVirtualTable_00d49c40(unsigned int unusedArg)
{
    m_vptr = (int)&DAT_010cfd10;
    return this;
}

extern int DAT_010cfd44;
extern int DAT_010cfd20;

struct FUN_00d49c50_cls
{
    volatile void* m_pVtbl;
    int m_unk04;
    int m_unk08;
    int m_unk0c;
    volatile void* m_pVtblAlt;
    int m_unk14;
    int m_unk18;
    int m_unk1C;
    int m_unk20;
    int m_unk24;
    int m_unk28;
    int m_unk2C;
    int m_unk30;
    int m_unk34;
    int m_unk38;
    int m_unk3C;
    int m_unk40;
    int m_unk44;
    int m_unk48;
    int m_unk4C;
    int m_unk50;
    int m_unk54;
    int m_unk58;
    int m_unk5C;
    int m_unk60;
    int m_unk64;
    int m_unk68;
    int m_unk6C;
    int m_unk70;
    int m_unk74;
    int m_unk78;
    int m_unk7C;
    int m_unk80;
    int m_unk84;
    int m_unk88;
    int m_unk8C;
    int m_unk90;
    int m_unk94;
    int m_unk98;
    int m_unk9C;
    int m_unkA0;
    int m_unkA4;
    int m_unkA8;
    int m_unkAC;
    int m_unkB0;
    int m_unkB4;
    int m_unkB8;
    int m_unkBC;
    int m_unkC0;
    int m_unkC4;
    int m_unkC8;
    int m_unkCC;
    int m_unkD0;
    int m_unkD4;
    int m_unkD8;
    int m_unkDC;
    int m_unkE0;
    int m_unkE4;
    int m_unkE8;
    int m_unkEC;
    volatile int m_iF0;
    volatile int m_iF4;
    volatile int m_iF8;
    volatile int m_iFC;
    volatile int m_i100;
    volatile int m_i104;
    void FUN_00d569c0(float f, int i);
    void* hkpStorageExtendedMeshShape_hkpStorageExtendedMeshShape(float f, int i);
};

// Calls FUN_00d569c0, sets both vtables, and initializes the six fields at offsets 0xF0-0x104, returning this.
// @fnv 0x00d49c50
// src: HAVOK_LIB 0x00d49c50
void* FUN_00d49c50_cls::hkpStorageExtendedMeshShape_hkpStorageExtendedMeshShape(float afValue, int i)
{
    FUN_00d569c0(afValue, i);
    m_pVtbl = (void*)&DAT_010cfd44;
    m_pVtblAlt = (void*)&DAT_010cfd20;
    m_iF0 = 0;
    m_iF4 = 0;
    m_iF8 = 0x80000000u;
    m_iFC = 0;
    m_i100 = 0;
    m_i104 = 0x80000000u;
    return this;
}

extern "C" int DAT_01268c8c;

// @fnv 0x00d4b160
// src: GUESS 0x00d4b160 (confidence: low)
extern "C" void* __cdecl Object_GetGlobalObjectAddress_00d4b160()
{
    return &DAT_01268c8c;
}

struct S_00d4b170
{
    void SetVptr_00d4a170(int a);
};
// @fnv 0x00d4b170
// src: GUESS 0x00d4b170 (confidence: low)
void __cdecl Runtime_ProcessState_00d4b170(S_00d4b170* pTarget, int a)
{
    if (pTarget)
        pTarget->SetVptr_00d4a170(a);
}

extern int DAT_01268cbc;

// @fnv 0x00d4b1c0
// src: GUESS 0x00d4b1c0 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00d4b1c0()
{
    return &DAT_01268cbc;
}

struct S_00d49c40
{
    void __thiscall SetVirtualTable_00d49c40(int a);
};
// @fnv 0x00d4b1d0
// src: GUESS 0x00d4b1d0 (confidence: low)
void __cdecl Object_ProcessState_00d4b1d0(S_00d49c40* pObject, int a)
{
    if (pObject)
        pObject->SetVirtualTable_00d49c40(a);
}

extern int DAT_01268d04;

// @fnv 0x00d4b220
// src: GUESS 0x00d4b220 (confidence: low)
int __cdecl Object_ComputeValue_00d4b220()
{
    return reinterpret_cast<int>(&DAT_01268d04);
}

// Forwarding helper: if the object pointer is valid, pass the second
// argument on to the object's own handler.
struct FUN_00d4a180_cls
{
    void __thiscall FUN_00d4a180(int a);
};

// @fnv 0x00d4b230
// src: GUESS 0x00d4b230 (confidence: low)
void __cdecl Runtime_ProcessState_00d4b230(FUN_00d4a180_cls* pTarget, int aiValue)
{
    if (pTarget != 0)
        pTarget->FUN_00d4a180(aiValue);
}

extern int DAT_01268d4c;
// @fnv 0x00d4b280
// src: GUESS 0x00d4b280 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00d4b280()
{
    return &DAT_01268d4c;
}

extern int DAT_01268d94;
// @fnv 0x00d4b2a0
// src: GUESS 0x00d4b2a0 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00d4b2a0()
{
    return &DAT_01268d94;
}

extern unsigned char DAT_01268dc4;
// @fnv 0x00d4b2c0
// src: GUESS 0x00d4b2c0 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00d4b2c0()
{
    return &DAT_01268dc4;
}

// Null-guarded forwarder: the first argument is an object pointer; when it
// is non-null the second argument is handed to a member function of that
// object.
class FUN_00d4b2d0_cls
{
  public:
    void hkpExtendedMeshShape_ShapesSubpart_ShapesSubpart(int a1);
};

// @fnv 0x00d4b2d0
// src: GUESS 0x00d4b2d0 (confidence: low)
void __cdecl hkpExtendedMeshShape_ShapesSubpart_ShapesSubpart_ProcessState_00d4b2d0(FUN_00d4b2d0_cls* pObject, int aiValue)
{
    if (pObject != 0)
    {
        pObject->hkpExtendedMeshShape_ShapesSubpart_ShapesSubpart(aiValue);
    }
}

extern int DAT_01268df4;

// @fnv 0x00d4b2f0
// src: GUESS 0x00d4b2f0 (confidence: low)
void* __cdecl Runtime_GetDAT01268df4Address()
{
    return &DAT_01268df4;
}

// Null-guarded forwarder: the first argument is an object pointer; when it
// is non-null the second argument is handed to a member function of that
// object.
class FUN_00d4b300_cls
{
  public:
    void FUN_00d56f10(int a1);
};

// @fnv 0x00d4b300
// src: GUESS 0x00d4b300 (confidence: low)
void __cdecl Object_ProcessState_00d4b300(FUN_00d4b300_cls* pObject, int aiValue)
{
    if (pObject != 0)
    {
        pObject->FUN_00d56f10(aiValue);
    }
}

extern int DAT_01268e24;

// @fnv 0x00d4b350
// src: GUESS 0x00d4b350 (confidence: low)
void* Runtime_GetDAT01268e24Address()
{
    return &DAT_01268e24;
}

struct TailTarget
{
    void Run();
};

// @fnv 0x00d4b380
// src: GUESS 0x00d4b380 (confidence: low)
void __cdecl Object_InvokeVirtualMethod_00d4b380(TailTarget* pTarget)
{
    pTarget->Run();
}

namespace fnv_00d4b3b0 {
extern int DAT_010d052c;

struct FnvVtObj
{
    int m_vptr;

    FnvVtObj* SetVptr(unsigned int unusedArg);
};

// @fnv 0x00d4b3b0
// src: GUESS 0x00d4b3b0 (confidence: low)
FnvVtObj* FnvVtObj::SetVptr(unsigned int unusedArg)
{
    m_vptr = (int)&DAT_010d052c;
    return this;
}
}  // namespace fnv_00d4b3b0

// Constructor of a scene-graph style node: initialises the base node
// (FUN_00dcd310) and then the derived node's own vtable pointers and
// member state.
extern int DAT_010d055c;
extern int DAT_010d053c;

struct FUN_00d4b3c0_cls
{
    volatile void* m_pVtbl;
    int m_unk04;
    int m_unk08;
    int m_unk0c;
    volatile void* m_pVtblAlt;
    int m_unk14;
    int m_unk18;
    int m_unk1c;
    int m_unk20;
    int m_unk24;
    int m_unk28;
    int m_unk2c;
    int m_unk30;
    int m_unk34;
    int m_unk38;
    int m_unk3c;
    int m_unk40;
    int m_unk44;
    int m_unk48;
    int m_unk4c;
    int m_unk50;
    int m_unk54;
    int m_unk58;
    int m_unk5c;
    volatile int m_i60;
    volatile int m_i64;
    volatile int m_i68;
    void FUN_00dcd310(float f, int i);
    void* hkpStorageMeshShape_hkpStorageMeshShape(float f, int i);
};

// @fnv 0x00d4b3c0
// src: HAVOK_LIB 0x00d4b3c0
void* FUN_00d4b3c0_cls::hkpStorageMeshShape_hkpStorageMeshShape(float afValue, int aiValue)
{
    FUN_00dcd310(afValue, aiValue);
    m_pVtbl = (void*)&DAT_010d055c;
    m_pVtblAlt = (void*)&DAT_010d053c;
    m_i60 = 0;
    m_i64 = 0;
    m_i68 = 0x80000000u;
    return this;
}

class D4BE30World
{
  public:
    void UpdateEntity(void* pvEntity);
};

// @fnv 0x00d4be30
// src: GUESS 0x00d4be30 (confidence: low)
void Runtime_ProcessState_00d4be30(D4BE30World* pkWorld, void* pvEntity)
{
    if (pkWorld)
        pkWorld->UpdateEntity(pvEntity);
}

extern int DAT_01268e6c;

// @fnv 0x00d4be80
// src: GUESS 0x00d4be80 (confidence: low)
int* Object_GetGlobalObjectAddress_00d4be80()
{
    return &DAT_01268e6c;
}

struct FUN_00d4ba30_class
{
    void __thiscall FUN_00d4ba30(int);
};

// @fnv 0x00d4be90
// src: GUESS 0x00d4be90 (confidence: low)
void __cdecl Object_ProcessState_00d4be90(FUN_00d4ba30_class* pObject, int value)
{
    if (pObject != 0)
        pObject->FUN_00d4ba30(value);
}

extern int g_unk01268eb4;

// @fnv 0x00d4bee0
// src: GUESS 0x00d4bee0 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00d4bee0()
{
    return &g_unk01268eb4;
}

extern int g_unk01268efc;

// @fnv 0x00d4bf00
// src: GUESS 0x00d4bf00 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00d4bf00()
{
    return &g_unk01268efc;
}

struct D4BF10FinishFlag
{
    int m_bFinishing;
};

class D4BF10Object
{
  public:
    D4BF10Object(D4BF10FinishFlag flag);

    static void* operator new(unsigned int, void* p)
    {
        return p;
    }
};

// @fnv 0x00d4bf10
// src: GUESS 0x00d4bf10 (confidence: low)
void Runtime_AllocateStorage_00d4bf10(void* apMemory, int finishing)
{
    if (apMemory)
    {
        D4BF10FinishFlag flag;
        flag.m_bFinishing = finishing;
        new (apMemory) D4BF10Object(flag);
    }
}

namespace fnv_00d4ce60 {

struct S_00d4ce60_Router
{
    int unk00, unk04, unk08, unk0C;
    hkMemoryAllocator* unk10;
    hkMemoryAllocator& heap()
    {
        return *unk10;
    }
};
S_00d4ce60_Router* hkMemoryRouter_getInstance();
struct S_00d4ce60_MsgBase
{
    virtual void v00();
    short unk04;
    short unk06;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    S_00d4ce60_MsgBase() throw()
    {
        unk06 = 1;
    }
};
struct S_00d4ce60_Msg : S_00d4ce60_MsgBase
{
    virtual void v00();
    S_00d4ce60_Msg() throw()
    {}
};
struct S_00d4ce60_Target
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void handle(S_00d4ce60_Msg* m) throw();
};
struct S_00d4ce60_Entry
{
    S_00d4ce60_Target* m_target;
    int unk04;
};
struct S_00d4ce60_Base
{
    virtual ~S_00d4ce60_Base() throw();
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
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
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
};
struct FUN_00d4ce60 : S_00d4ce60_Base
{
    S_00d4ce60_Entry* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    ~FUN_00d4ce60() throw();
};
// @fnv 0x00d4ce60
FUN_00d4ce60::~FUN_00d4ce60() throw()
{
    S_00d4ce60_Msg msg;
    for (int i = m_iElementCount - 1; i >= 0; i--)
    {
        S_00d4ce60_Entry* e = &m_data[i];
        e->m_target->handle(&msg);
    }
    m_iElementCount = 0;
    hkMemoryAllocator& alloc = hkMemoryRouter_getInstance()->heap();
    m_iElementCount = 0;
    if ((m_iCapacityState & 0x80000000) == 0)
    {
        alloc.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(S_00d4ce60_Entry));
    }
    m_data = 0;
    m_iCapacityState = 0x80000000;
}
}  // namespace fnv_00d4ce60

namespace fnv_00d4de00 {

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
struct FnvCpu_FUN_00d4de00_CpuObject
{
    unsigned int unk00;
    unsigned short size;
    void ReleaseReferencedObjectsAndLock();
    FnvCpu_FUN_00d4de00_CpuObject* FUN_00d4de00(unsigned int flags);
};
// @fnv 0x00d4de00
FnvCpu_FUN_00d4de00_CpuObject* FnvCpu_FUN_00d4de00_CpuObject::FUN_00d4de00(unsigned int flags)
{
    ReleaseReferencedObjectsAndLock();
    if (flags & 1)
    {
        hkMemoryRouter* holder = hkMemoryRouter_getInstance();
        reinterpret_cast<hkMemoryAllocator*>(holder->m_heap)->blockFree(this, size);
    }
    return this;
}
}  // namespace fnv_00d4de00

extern int DAT_01268f74;

class FUN_00d50020_base
{
  public:
    virtual void unk00();
    ~FUN_00d50020_base();
    int unk04;
};

class FUN_00d50020 : public FUN_00d50020_base
{
  public:
    virtual ~FUN_00d50020();
    void unk08();
};

// Calls unk08() on this object and decrements the global counter DAT_01268f74.
// @fnv 0x00d50020
FUN_00d50020::~FUN_00d50020()
{
    this->unk08();
    DAT_01268f74--;
}

namespace fnv_00d50140 {

class SpawnedObject
{
  public:
    unsigned int unk00;
    unsigned short m_04;
    unsigned short unk06;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    static void* operator new(unsigned int size);
    SpawnedObject();
};

hkMemoryRouter* hkMemoryRouter_getInstance();

class FUN_00d50140_cls
{
  public:
    unsigned int unk00;
    SpawnedObject* m_04;
    int EnsureSpawnedObject();
};

void* SpawnedObject::operator new(unsigned int size)
{
    hkMemoryRouter* h = hkMemoryRouter_getInstance();
    void* p = reinterpret_cast<hkMemoryAllocator*>(h->m_heap)->blockAlloc(size);
    ((SpawnedObject*)p)->m_04 = (unsigned short)size;
    return p;
}

// If m_04 is null, allocates a SpawnedObject via operator new and stores it in m_04; returns sizeof(SpawnedObject).
// @fnv 0x00d50140
int FUN_00d50140_cls::EnsureSpawnedObject()
{
    AutoMemContext guard(16);
    if (m_04 == 0)
    {
        m_04 = new SpawnedObject();
    }
    return sizeof(SpawnedObject);
}
}  // namespace fnv_00d50140

extern int DAT_01268188;
extern int DAT_01268f74;

void* __cdecl Object_DispatchCommandFour(unsigned int size);
void __cdecl bhkSerializable_CloneCritLock();
void __cdecl bhkSerializable_CloneCritUnlock();

struct DataBase
{
    DataBase();
    virtual ~DataBase();
    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
};

struct DataIntermediate : DataBase
{
    int unk04;
    int unk08;
    int unk0c;
    DataIntermediate() : unk0c(0)
    {
        ++DAT_01268188;
    }
};

struct DataObject : DataIntermediate
{
    DataObject()
    {
        ++DAT_01268f74;
    }
};

struct DataFactory
{
    void bhkConstraint_CopyMembers(DataObject* object, int id);
    DataObject* bhkGenericConstraint_Clone(int id);
};

// @fnv 0x00d501f0
// src: COMMUNITY 0x00d501f0
DataObject* DataFactory::bhkGenericConstraint_Clone(int id)
{
    AutoMemContext context(16);
    bhkSerializable_CloneCritLock();
    DataObject* object = new DataObject();
    bhkConstraint_CopyMembers(object, id);
    bhkSerializable_CloneCritUnlock();
    return object;
}

class FUN_00d51720_helper
{
  public:
    unsigned int Query();
};

class FUN_00d51720_cls
{
  public:
    void* m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned char unk10;
    unsigned char unk11;
    unsigned char unk12;
    unsigned char unk13;
    unsigned char unk14;
    unsigned char unk15;
    unsigned char unk16;
    unsigned char unk17;
    unsigned char unk18;
    unsigned char unk19;

    void InitFromHelper(void* p);
};

// Stores the helper pointer, its Query() result in m_04, and zeroes m_08, m_0c and the trailing byte fields.
// @fnv 0x00d51720
void FUN_00d51720_cls::InitFromHelper(void* pHelper)
{
    m_04 = reinterpret_cast<FUN_00d51720_helper*>(pHelper)->Query();
    m_00 = pHelper;
    m_08 = 0;
    m_0c = 0;
    unk10 = 0;
    unk11 = 0;
    unk12 = 0;
    unk13 = 0;
    unk14 = 0;
    unk15 = 0;
    unk18 = 0;
    unk19 = 0;
    unk16 = 0;
    *(volatile unsigned char*)&unk17 = 0;
}

struct D51760Buffer
{
    unsigned int* data;
    int count;
};

struct D51760Stats
{
    int unk00;
    int bytes;
    int unk08;
    int unk0C;
};

// @fnv 0x00d51760
// src: HAVOK_LIB 0x00d51760
void __cdecl hkpConstraintConstructionKit_computeConstraintInfo(D51760Buffer* buf, D51760Stats* stats)
{
    unsigned int* p = buf->data;
    unsigned int* end = p + buf->count;
    while (p < end)
    {
        switch (*p)
        {
        case 0:
            return;
        case 6:
            p++;
            stats->bytes += 0x30;
            stats->unk08 += 1;
            stats->unk0C += 1;
            break;
        case 7:
            stats->bytes += 0x90;
            stats->unk08 += 3;
            stats->unk0C += 3;
            break;
        case 12:
            p++;
            stats->bytes += 0x60;
            stats->unk08 += 2;
            stats->unk0C += 2;
            break;
        case 13:
            stats->bytes += 0x90;
            stats->unk08 += 3;
            stats->unk0C += 3;
            break;
        case 16:
            p++;
            stats->bytes += 0x40;
            stats->unk08 += 1;
            stats->unk0C += 1;
            break;
        case 17:
            p++;
            stats->bytes += 0x30;
            stats->unk08 += 1;
            stats->unk0C += 1;
            break;
        case 18:
            p++;
            stats->bytes += 0x30;
            stats->unk08 += 1;
            stats->unk0C += 1;
            break;
        case 19:
            p += 2;
            stats->bytes += 0x30;
            stats->unk08 += 1;
            stats->unk0C += 1;
            break;
        case 14:
            p++;
            stats->bytes += 0x40;
            stats->unk08 += 1;
            stats->unk0C += 3;
            break;
        case 15:
            p++;
            stats->bytes += 0x50;
            stats->unk08 += 1;
            stats->unk0C += 3;
            break;
        case 20:
            p++;
            stats->bytes += 0x30;
            stats->unk08 += 1;
            stats->unk0C += 2;
            break;
        case 21:
            p++;
            stats->bytes += 0x40;
            stats->unk08 += 1;
            stats->unk0C += 2;
            break;
        case 3:
        case 4:
        case 5:
        case 24:
            p++;
            break;
        }
        p++;
    }
}

namespace fnv_00d51b30 {
struct FUN_00d51b30_arr
{
    int* m_pBase;
    unsigned int m_uiCount;
    unsigned int m_uiCap;
};

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
void __cdecl ResizeAudioStream(void* alloc, FUN_00d51b30_arr* arr, int n);

struct FUN_00d51b30_obj
{
    int unk00;
    int m_04;
    unsigned int m_08;
    unsigned int m_0C;
    int unk10;
    int unk14;
    int unk18;
    FUN_00d51b30_arr m_1c;
};

struct FUN_00d51b30_cls
{
    int unk00;
    FUN_00d51b30_obj* m_pEntryObject;
    void __thiscall AppendTwoIntsAndAdvance(int v);
};

// @fnv 0x00d51b30
void FUN_00d51b30_cls::AppendTwoIntsAndAdvance(int aiValue)
{
    FUN_00d51b30_arr* arr = &m_pEntryObject->m_1c;
    hkMemoryRouter* h = hkMemoryRouter_getInstance();
    if (arr->m_uiCount == (arr->m_uiCap & 0x3fffffff))
    {
        ResizeAudioStream(h->m_heap, arr, 4);
    }
    int* slot = arr->m_pBase + arr->m_uiCount;
    *slot = 6;
    if (*slot == 0)
        *slot = 0;
    arr->m_uiCount++;

    arr = &m_pEntryObject->m_1c;
    h = hkMemoryRouter_getInstance();
    if (arr->m_uiCount == (arr->m_uiCap & 0x3fffffff))
    {
        ResizeAudioStream(h->m_heap, arr, 4);
    }
    slot = arr->m_pBase + arr->m_uiCount;
    *slot = aiValue;
    if (*slot == aiValue)
        *slot = aiValue;
    arr->m_uiCount++;

    FUN_00d51b30_obj* o = m_pEntryObject;
    o->m_08++;
    o->m_0C++;
    o->m_04 += 0x30;
}
}  // namespace fnv_00d51b30

namespace fnv_00d51e50 {

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();
void __cdecl ResizeAudioStream(void* apAllocator, void* apVec, int aElemSize);

struct FUN_00d51e50_vec
{
    int* m_00;
    int m_04;
    unsigned int m_08;
};

struct FUN_00d51e50_inner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    FUN_00d51e50_vec m_1c;
};

class FUN_00d51e50_cls
{
  public:
    int unk00;
    FUN_00d51e50_inner* m_04;
    int unk08;
    int unk0c;
    int unk10;
    unsigned short unk14;
    unsigned char unk16;

    void hkpConstraintConstructionKit_setAngularBasisABodyFrame();
};

// @fnv 0x00d51e50
// src: HAVOK_LIB 0x00d51e50
void FUN_00d51e50_cls::hkpConstraintConstructionKit_setAngularBasisABodyFrame()
{
    FUN_00d51e50_vec* pVec = &m_04->m_1c;
    hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
    if (pVec->m_04 == (int)(pVec->m_08 & 0x3fffffff))
    {
        ResizeAudioStream(pHolder->m_heap, pVec, 4);
    }
    int* pSlot = pVec->m_00 + pVec->m_04;
    *pSlot = 0xa;
    *pSlot = 0xa;
    pVec->m_04 += 1;
    unk16 = 1;
}
}  // namespace fnv_00d51e50

namespace fnv_00d51f90 {
struct S_00d51f90_Heap
{
    int unk00;
};
struct S_00d51f90_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00d51f90_Heap* m_pStreamAllocator;
};
S_00d51f90_Router* hkMemoryRouter_getInstance();
struct S_00d51f90_Arr
{
    int* m_data;
    int m_iElementCount;
    int m_cap;
};
void ResizeAudioStream(S_00d51f90_Heap* heap, S_00d51f90_Arr* arr, int elemSize);
struct S_00d51f90_Info
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    S_00d51f90_Arr m_aiIndexedValues;
};
struct S_00d51f90_Obj
{
    int unk00;
    S_00d51f90_Info* m_info;
    void AppendEntryAndAdvance();
};
// @fnv 0x00d51f90
void S_00d51f90_Obj::AppendEntryAndAdvance()
{
    S_00d51f90_Arr* a = &m_info->m_aiIndexedValues;
    S_00d51f90_Router* r = hkMemoryRouter_getInstance();
    if (a->m_iElementCount == (a->m_cap & 0x3fffffff))
        ResizeAudioStream(r->m_pStreamAllocator, a, 4);
    int* p = a->m_data + a->m_iElementCount;
    for (int k = 0; k < 1; k++)
        p[k] = 13;
    a->m_iElementCount++;
    {
        S_00d51f90_Info* p = m_info;
        p->unk08 += 1;
        p->unk0c += 1;
        p->unk04 += 0x30;
    }
    {
        S_00d51f90_Info* p = m_info;
        p->unk04 += 0x30;
        p->unk08 += 1;
        p->unk0c += 1;
    }
    {
        S_00d51f90_Info* p = m_info;
        p->unk04 += 0x30;
        p->unk08 += 1;
        p->unk0c += 1;
    }
}
}  // namespace fnv_00d51f90

namespace fnv_00d52ba0 {
struct D52BA0Allocator;

struct D52BA0MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D52BA0Allocator* m_pStreamAllocator;

    D52BA0Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" D52BA0MemoryRouter& __cdecl hkMemoryRouter_getInstance();
void __cdecl ResizeAudioStream(void* alloc, void* array, int sizeElem);

static __forceinline void D52BA0IntArray_construct(int* p, int n, const int& e);

static __forceinline void D52BA0IntArray__pushBack(hkArrayBase<int>& self, D52BA0Allocator& alloc, const int& value);

static __forceinline void D52BA0IntArray_AddBack(hkArrayBase<int>& self, const int& value);

static __forceinline void D52BA0IntArray_construct(int* p, int n, const int& e)
{
        for (int i = 0; i < n; i++)
            p[i] = e;
    }

static __forceinline void D52BA0IntArray__pushBack(hkArrayBase<int>& self, D52BA0Allocator& alloc, const int& value)
{
        if (self.m_iElementCount == (self.m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(&alloc, (&self), sizeof(int));
        D52BA0IntArray_construct(self.m_data + self.m_iElementCount, 1, value);
        self.m_iElementCount++;
    }

static __forceinline void D52BA0IntArray_AddBack(hkArrayBase<int>& self, const int& value)
{
        D52BA0IntArray__pushBack(self, hkMemoryRouter_getInstance().heap(), value);
    }

struct D52BA0Commands
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    hkArrayBase<int> m_commands;
};

class D52BA0Builder
{
  public:
    int unk00;
    D52BA0Commands* m_pkCommands;
    int m_iDepth;

    void hkpConstraintConstructionKit_restoreStrength();
};

// Decrements m_iDepth and appends command 0x17 to m_pkCommands->m_commands.
// @fnv 0x00d52ba0
// src: HAVOK_LIB 0x00d52ba0
void D52BA0Builder::hkpConstraintConstructionKit_restoreStrength()
{
    m_iDepth--;
    D52BA0IntArray_AddBack(m_pkCommands->m_commands, 0x17);
}
}  // namespace fnv_00d52ba0

namespace fnv_00d52be0 {
extern "C" void _ReadWriteBarrier(void);

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();
void __cdecl ResizeAudioStream(void* pAllocator, void* pArray, unsigned int auiNewSize) throw();

struct FUN_00d52be0_arr
{
    int* data;
    int count;
    unsigned int capFlags;
};

struct FUN_00d52be0_S
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    FUN_00d52be0_arr m_arr1c;
    FUN_00d52be0_arr m_arr28;
};

struct FUN_00d52be0_cls
{
    int unk00;
    FUN_00d52be0_S* m_pS;

    void hkpConstraintConstructionKit_addConstraintModifierCallback(int a1, int a2);
};

// Appends 0x18, a1 and a2 to the two arrays in m_pS, growing each array via ResizeAudioStream when it is full.
// @fnv 0x00d52be0
// src: HAVOK_LIB 0x00d52be0
void FUN_00d52be0_cls::hkpConstraintConstructionKit_addConstraintModifierCallback(int aiFirstValue, int aiSecondValue)
{
    FUN_00d52be0_arr* arr = &m_pS->m_arr1c;
    hkMemoryRouter* holder = hkMemoryRouter_getInstance();
    if (arr->count == (int)(arr->capFlags & 0x3fffffffu))
    {
        ResizeAudioStream(holder->m_heap, arr, 4);
    }
    int* slot0 = (int*)((unsigned int)arr->data + (unsigned int)arr->count * 4);
    _ReadWriteBarrier();
    *slot0 = 0x18;
    arr->count++;

    arr = &m_pS->m_arr28;
    holder = hkMemoryRouter_getInstance();
    if (arr->count == (int)(arr->capFlags & 0x3fffffffu))
    {
        ResizeAudioStream(holder->m_heap, arr, 4);
    }
    int* slot1 = (int*)((unsigned int)arr->data + (unsigned int)arr->count * 4);
    _ReadWriteBarrier();
    *slot1 = aiFirstValue;
    arr->count++;

    arr = &m_pS->m_arr1c;
    holder = hkMemoryRouter_getInstance();
    if (arr->count == (int)(arr->capFlags & 0x3fffffffu))
    {
        ResizeAudioStream(holder->m_heap, arr, 4);
    }
    int* slot2 = (int*)((unsigned int)arr->data + (unsigned int)arr->count * 4);
    _ReadWriteBarrier();
    *slot2 = aiSecondValue;
    arr->count++;
}
}  // namespace fnv_00d52be0

namespace fnv_00d52ca0 {

struct PairList
{
    int* m_data;
    int m_uiItemCount;
    unsigned int m_capBits;
};

hkMemoryRouter* hkMemoryRouter_getInstance();
void ResizeAudioStream(void* allocator, PairList* list, unsigned int elemSize);

struct SubOwner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    PairList m_items;
};

struct FUN_00d52ca0_cls
{
    int unk00;
    SubOwner* m_pSub;

    void AppendZeroItem();
};

// Appends a zero element to m_pSub->m_items, growing the list via ResizeAudioStream when it is full, then increments the count.
// @fnv 0x00d52ca0
void FUN_00d52ca0_cls::AppendZeroItem()
{
    PairList* items = &m_pSub->m_items;
    hkMemoryRouter* holder = hkMemoryRouter_getInstance();
    if ((unsigned int)items->m_uiItemCount == (items->m_capBits & 0x3fffffff))
    {
        ResizeAudioStream(holder->m_heap, items, 4);
    }
    int n = items->m_uiItemCount;
    int* volatile* pdata = &items->m_data;
    int* slot = (*pdata) + n;
    *slot = 0;
    items->m_uiItemCount++;
}
}  // namespace fnv_00d52ca0

// FUN_00d53220 — destructor of a polymorphic class.
//
// Shape deduced from the target disassembly:
//   * SEH prologue (push -1 / handler / fs:[0]) with an EH state slot at
//     [esp+0x14] and a saved `this` slot at [esp+8]  -> destructor whose
//     unwind funclet must run the base class destructor.
//   * `mov [esi], vftable`  -> class with a virtual destructor.
//   * state 0 guards the body call to the free routine at 0x00c876a0.
//   * `dec dword ptr [0x1268f80]` -> body decrements a global counter.
//   * `mov ecx, esi / state -1 / call 0x00c89640` -> compiler-generated
//     base class destructor call (stand-in base named by its address).

extern int DAT_01268f80;
void __cdecl bhkSerializable_Kill(void);

// Stand-in for the polymorphic base class whose destructor lives at
// 0x00c89640. The base supplies the vfptr at offset 0, so the generated
// base-destructor call in ~FUN_00d53220 passes `this` unchanged.
struct FUN_00c89640
{
    virtual ~FUN_00c89640();
};

struct FUN_00d53220 : FUN_00c89640
{
    virtual ~FUN_00d53220();
};

// @fnv 0x00d53220
FUN_00d53220::~FUN_00d53220()
{
    bhkSerializable_Kill();
    --DAT_01268f80;
}

struct S_00d532f0_Data
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
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
    int* unk38;
    int unk3c;
};

struct S_00d532f0_Class
{
    int unk00;
    int unk04;
    S_00d532f0_Data* unk08;

    bool __thiscall IsEqualWithValues(S_00d532f0_Class* p);
    bool __thiscall CompareData(S_00d532f0_Class* p);
};

// Calls IsEqualWithValues, then compares the unk3c counts and each of the unk38 entries of this's and p's unk08 data, returning whether all match.
// @fnv 0x00d532f0
bool S_00d532f0_Class::CompareData(S_00d532f0_Class* apOther)
{
    bool result = IsEqualWithValues(apOther);

    if (result)
    {
        S_00d532f0_Data* pLeftData = this ? this->unk08 : 0;
        S_00d532f0_Data* pRightData = apOther ? apOther->unk08 : 0;
        int count = pLeftData->unk3c;

        result &= (count == pRightData->unk3c);

        for (int i = 0; i < count; ++i)
        {
            if (!result)
            {
                break;
            }

            result &= (pLeftData->unk38[i] == pRightData->unk38[i]);
        }
    }

    return result;
}

class D53360BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(D53360BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(D53360BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
};

class D53360Object;

class D53360Stream
{
  public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2C();
    virtual void SaveLinkID(D53360Object* pkObject);
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
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    D53360BinaryStream* m_pBackingStream;
};

template <class T>
inline void D53360BinaryStreamSave(D53360BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void D53360SaveBinary(D53360Stream& kStream, const T& value)
{
    D53360BinaryStreamSave(*kStream.m_pBackingStream, &value);
}

struct D53360Entry
{
    int unk00;
    int unk04;
    int unk08;
    D53360Object* m_pPointer;
};

class D53360Owner
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    D53360Entry** m_ppkEntries;
    unsigned int m_uiCount;

    void hkConstraintCinfo_SaveBinary(D53360Stream& kStream);
    void hkConstraintChainCinfo_SaveBinary(D53360Stream& kStream);
};

// @fnv 0x00d53360
// src: XBOX_PDB 0x00d53360
void D53360Owner::hkConstraintChainCinfo_SaveBinary(D53360Stream& kStream)
{
    unsigned int ItemUpdateArray = m_uiCount;
    D53360SaveBinary(kStream, ItemUpdateArray);
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
    {
        D53360Entry* pkEntry = m_ppkEntries[i];
        kStream.SaveLinkID(pkEntry ? pkEntry->m_pPointer : 0);
    }
    hkConstraintCinfo_SaveBinary(kStream);
}

namespace fnv_00d57120 {

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
struct FnvCpu_FUN_00d57120_CpuObject
{
    unsigned int unk00;
    unsigned short size;
    void ReleaseMeshArrays();
    FnvCpu_FUN_00d57120_CpuObject* hkpExtendedMeshShape_Destroy(unsigned int flags);
};
// @fnv 0x00d57120
// src: COMMUNITY 0x00d57120
FnvCpu_FUN_00d57120_CpuObject* FnvCpu_FUN_00d57120_CpuObject::hkpExtendedMeshShape_Destroy(unsigned int flags)
{
    ReleaseMeshArrays();
    if (flags & 1)
    {
        hkMemoryRouter* holder = hkMemoryRouter_getInstance();
        reinterpret_cast<hkMemoryAllocator*>(holder->m_heap)->blockFree(this, size);
    }
    return this;
}
}  // namespace fnv_00d57120

extern double DAT_0101ffa0;
extern double DAT_010d0f08;
extern float DAT_011b5be0;
extern float DAT_011b5be4;

// Converts a bit count to bytes, computes a normalized scale from it, and stores the scale and its reciprocal in two globals.
// @fnv 0x00d57160
void ComputeByteScale(int bits)
{
    int bytes = bits / 8;
    float v = (float)(((double)bytes - DAT_0101ffa0) / DAT_010d0f08);
    DAT_011b5be0 = v;
    DAT_011b5be4 = 1.0f / v;
}

class ObjBaseA
{
  public:
    virtual ~ObjBaseA();
    int m_04;
    int m_08;
    int m_0c;

    ObjBaseA(int flag)
    {
        if (flag)
            *(volatile int*)&m_0c = 0;
        m_0c = 0x12;
    }
};

class FUN_00d59830 : public ObjBaseA
{
  public:
    virtual ~FUN_00d59830();
    FUN_00d59830(int flag);
};

// Constructs the object via ObjBaseA(flag) and, when flag is set, sets m_0c to 6.
// @fnv 0x00d59830
FUN_00d59830::FUN_00d59830(int flag) : ObjBaseA(flag)
{
    if (flag)
        m_0c = 6;
}

struct CallTarget_00d5ecc0
{
    int Splice(int, int, int, int, int);
};
struct SearchObject
{
    int Search(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3);
};
// @fnv 0x00d5ed80
int SearchObject::Search(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3)
{
    unsigned int callResult0 =
        (unsigned int)((CallTarget_00d5ecc0*)this)->Splice((int)arg0, (int)arg1, (int)0u, (int)arg2, (int)arg3);
    return (int)callResult0;
}

void __cdecl ResizeAudioStream(void*, void*, int);

struct FUN_00d51ea0_Vec
{
    int* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapacityFlags;
};

struct FUN_00d51ea0_Inner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    FUN_00d51ea0_Vec m_vec1c;
};

struct FUN_00d51ea0_Cls
{
    int unk00;
    FUN_00d51ea0_Inner* m_pInner;
    int unk08;
    int unk0c;
    int unk10;
    char unk14;
    char unk15;
    char unk16;
    bool m_b17;

    bool hkpConstraintConstructionKit_setAngularBasisBBodyFrame();
};

// Appends a zeroed entry to the inner vector (growing it if full), sets it to 0xb, increments the count, sets m_b17 and returns true.
// @fnv 0x00d51ea0
// src: HAVOK_LIB 0x00d51ea0
bool FUN_00d51ea0_Cls::hkpConstraintConstructionKit_setAngularBasisBBodyFrame()
{
    FUN_00d51ea0_Vec* vec = &m_pInner->m_vec1c;
    hkMemoryRouter* holder = hkMemoryRouter_getInstance();
    if (vec->m_iArrayLength == (int)(vec->m_uCapacityFlags & 0x3fffffff))
        ResizeAudioStream(holder->m_heap, vec, 4);
    int* pSlot = &vec->m_pData[vec->m_iArrayLength];
    *pSlot = 0;
    *pSlot = 0xb;
    vec->m_iArrayLength = vec->m_iArrayLength + 1;
    m_b17 = 1;
    return true;
}

class FUN_00cc0500
{
  public:
    char pad00[12];
    FUN_00cc0500(void* pvBuffer, int iSize, hkBool bIsString);
    ~FUN_00cc0500();
};

extern hkError* DAT_01268360;

struct WorldObjD53
{
    char pad00[0x24];
    void* m_pvEntity;
};

struct ParamD53
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual WorldObjD53* v037();
    virtual void v038();
    virtual void v039();
    char pad04[0x14];
    unsigned int m_uiCount;
};

struct HolderD53
{
    char pad00[8];
    void* m_pvWorld;
};

struct InfoD53
{
    char pad00[0x2c];
    unsigned int m_uiFilterInfo;
};

struct ConstraintD53
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual int v037();
    virtual void v038();
    virtual void v039(ParamD53* pkParam);
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050(ParamD53* pkParam);
    char pad04[4];
    HolderD53* m_pkHolder;
    char pad0c[4];
    unsigned char m_ucFlags;

    void Object_DoNothing();
};

struct EntryD53
{
    char pad00[0xc];
    ConstraintD53* m_pkConstraint;
    char pad10[0x1c];
    unsigned int m_uiFilterInfo;
};

struct ListD53
{
    char pad00[0x38];
    EntryD53** m_ppkEntries;
    int m_iArrayLength;
};

__forceinline hkBool IsInWorldD53(HolderD53* pkHolder)
{
    return pkHolder->m_pvWorld != 0;
}
__forceinline bool HasWorldD53(ConstraintD53* pkConstraint, HolderD53* pkHolder)
{
    pkConstraint->Object_DoNothing();
    bool bResult = IsInWorldD53(pkHolder);
    pkConstraint->Object_DoNothing();
    return bResult;
}

__forceinline void* GetEntityD53(WorldObjD53* pkObj)
{
    void* pvEntity = 0;
    if (pkObj)
        pvEntity = pkObj->m_pvEntity;
    return pvEntity;
}

struct FUN_00d536a0_shell
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050(void* pvEntity);
    virtual InfoD53* v051();
    char pad04[4];
    ListD53* m_pkList;

    bool UpdateConstraintEntries(ParamD53* pkParam, bool bAdd);
};

// @fnv 0x00d536a0
bool FUN_00d536a0_shell::UpdateConstraintEntries(ParamD53* pkParam, bool bAdd)
{
    AutoMemContext kContext(0x10);
    bool bResult = false;
    ListD53* pkList = this ? m_pkList : 0;
    for (int i = 0; i < pkList->m_iArrayLength; i++)
    {
        EntryD53* pkEntry = pkList->m_ppkEntries[i];
        if (bAdd)
        {
            ConstraintD53* pkConstraint;
            if (!pkEntry || !(pkConstraint = pkEntry->m_pkConstraint))
            {
                bResult = true;
                v050(GetEntityD53(pkParam->v037()));
                continue;
            }
            HolderD53* pkHolder = pkConstraint->m_pkHolder;
            if (pkHolder)
            {
                if (!HasWorldD53(pkConstraint, pkHolder))
                {
                    unsigned int uiInfo = v051()->m_uiFilterInfo;
                    unsigned int uiLayer = (unsigned short)pkEntry->m_uiFilterInfo;
                    pkEntry->m_uiFilterInfo = (uiInfo & 0xffff0000) | uiLayer;
                }
            }
            else
            {
                unsigned int uiInfo = v051()->m_uiFilterInfo;
                unsigned int uiLayer = (unsigned short)pkEntry->m_uiFilterInfo;
                pkEntry->m_uiFilterInfo = (uiInfo & 0xffff0000) | uiLayer;
            }
            if (pkParam->m_uiCount <= 0)
            {
                pkConstraint->v039(pkParam);
                if (!pkConstraint->v037() && !(pkConstraint->m_ucFlags & 0x30))
                {
                    {
                        char acBuffer[0x200];
                        FUN_00cc0500 kStream(acBuffer, sizeof(acBuffer), true);
                        ((hkOstream&)kStream)
                            .ProcessAndReturnValue_00cc01c0(
                                "A Constraint is being added to the world before its target bodies have been added. Did an bad actor skeleton just switch from keyframed?\n");
                        DAT_01268360->message(1, 0x234f24fc, acBuffer,
                                              "D:\\_Fallout3\\Platforms\\Common\\Code\\BSHavok\\bhkConstraintChain.cpp",
                                              0x168);
                    }
                    pkConstraint->v050(pkParam);
                }
            }
        }
        else
        {
            if (pkEntry == GetEntityD53(pkParam->v037()))
                v050(0);
        }
    }
    return bResult;
}

struct D53970Stream
{
    unsigned int ReadCount();
    struct D53970Link* ReadLink();
};
struct D53970Link
{
    int unk00;
    int unk04;
    int m_uiFilterValue;
};
struct D53970Alloc
{
    int unk00;
};
struct D53970Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    D53970Alloc* m_pStreamAllocator;
    D53970Alloc& Heap()
    {
        return *m_pStreamAllocator;
    }
};
D53970Router& GetMemoryRouter();
struct D53970HeapAlloc
{
    D53970Alloc& Get()
    {
        return GetMemoryRouter().Heap();
    }
};
static __forceinline int D53970Array_GetCapacity(hkArrayBase<int>& self);

void __cdecl hkArrayUtil__reserve(D53970Alloc* alloc, hkArrayBase<int>* arr, int n, int elemSize);
static __forceinline void D53970Array_Reserve(hkArrayBase<int>& self, D53970Alloc& alloc, int n);

static __forceinline void D53970Array_SetSizeA(hkArrayBase<int>& self, D53970Alloc& alloc, int n);

static __forceinline void D53970Array_SetSize(hkArrayBase<int>& self, int n);

static __forceinline int D53970Array_GetCapacity(hkArrayBase<int>& self)
{
        return self.m_iCapacityState & 0x3fffffff;
    }

static __forceinline void D53970Array_Reserve(hkArrayBase<int>& self, D53970Alloc& alloc, int n)
{
    if (D53970Array_GetCapacity(self) < n)
    {
        int cap2 = 2 * D53970Array_GetCapacity(self);
        int newSize = (n < cap2) ? cap2 : n;
        hkArrayUtil__reserve(&alloc, (&self), newSize, 4);
    }
}

static __forceinline void D53970Array_SetSizeA(hkArrayBase<int>& self, D53970Alloc& alloc, int n)
{
        D53970Array_Reserve(self, alloc, n);
        self.m_iElementCount = n;
    }

static __forceinline void D53970Array_SetSize(hkArrayBase<int>& self, int n)
{
        D53970Array_SetSizeA(self, D53970HeapAlloc().Get(), n);
    }

void __cdecl hkArrayUtil__reserve(D53970Alloc* alloc, hkArrayBase<int>* arr, int n, int elemSize);

struct D53970BaseA
{
    virtual void unk00();
};
struct D53970BaseB
{
    virtual void unk00();
    int unk08;
    int unk0c;
    int unk10;
};
struct D53970Data : D53970BaseA, D53970BaseB
{
    hkArrayBase<int> m_ppData;
};
struct D53970Obj
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual D53970BaseB* GetData(int* out);
    void bhkConstraint_LinkObject(D53970Stream* stream);
    void ReadDataArray(D53970Stream* stream);
};

// @fnv 0x00d53970
void D53970Obj::ReadDataArray(D53970Stream* stream)
{
    AutoMemContext scope(16);
    int count = stream->ReadCount();
    int out;
    hkArrayBase<int>& arr = static_cast<D53970Data*>(GetData(&out))->m_ppData;
    D53970Array_SetSize(arr, count);
    for (unsigned int i = 0; i < (unsigned int)count; i++)
        arr.m_data[i] = stream->ReadLink()->m_uiFilterValue;
    bhkConstraint_LinkObject(stream);
}

// Copies 16 consecutive ints from s to d, four at a time, in a loop of four iterations.
// @fnv 0x00d570d0
// src: HAVOK_LIB 0x00d570d0
void __cdecl hkString_memCpy16_64(int* aiDest, const int* aiSrc)
{
    int n = 4;
    const int* piSrc = aiSrc;
    int* p = aiDest;
    do
    {
        p[0] = piSrc[0];
        p[1] = piSrc[1];
        p[2] = piSrc[2];
        p[3] = piSrc[3];
        p += 4;
        piSrc += 4;
    } while (--n > 0);
}

struct PlaceTag
{
};
inline void* operator new(unsigned int, void* p, PlaceTag)
{
    __assume(p != 0);
    return p;
}
inline void operator delete(void*, void*, PlaceTag)
{}
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
void __cdecl ResizeAudioStream(void*, void*, int);
namespace d51 {
// hkArray<T>::pushBack as this unit's original inlines it (the router's allocator is read only on the grow path).
template <class T> inline void AddBack(hkArray<T>& a, const T& e)
{
    hkMemoryRouter* h = hkMemoryRouter_getInstance();
    if (a.m_iElementCount == (a.m_iCapacityState & 0x3fffffff))
        ResizeAudioStream(h->m_heap, &a, sizeof(T));
    ::new (&a.m_data[a.m_iElementCount], PlaceTag()) T(e);
    a.m_iElementCount++;
}
struct Writer
{
    int unk;
    int m_iBytes;
    int m_iArrayLength;
    int m_iCount2;
    char pad[0x1c - 0x10];
    hkArray<int> m_kArr;
    void Add()
    {
        m_iArrayLength++;
        m_iCount2++;
        m_iBytes += 0x30;
    }
};
struct Owner
{
    int unk;
    Writer* m_pkWriter;
    void AppendPairAndAdvance(int v);
};
// Appends 0xc and v to the writer's int array, then calls Add twice to advance the writer's counters and byte count.
// @fnv 0x00d51ef0
void Owner::AppendPairAndAdvance(int aiValue)
{
    AddBack(m_pkWriter->m_kArr, 0xc);
    AddBack(m_pkWriter->m_kArr, aiValue);
    m_pkWriter->Add();
    m_pkWriter->Add();
}
}

// @fnv 0x00d42760
// src: COMMUNITY 0x00d42760
void nullsub_17()
{}

// @fnv 0x00d42780
// src: COMMUNITY 0x00d42780
void __cdecl nullsub_18()
{}

class hkListNodeD46D
{
  public:
    int unk00;
    hkListNodeD46D* m_next;

    int ProcessEntries_00d46d70() const;
};

// @fnv 0x00d46d70
// src: GUESS 0x00d46d70 (confidence: low)
int hkListNodeD46D::ProcessEntries_00d46d70() const
{
    int iCount = 0;
    for (const hkListNodeD46D* pkNode = this; pkNode; pkNode = pkNode->m_next)
        iCount++;
    return iCount;
}

class hkBlockD46E
{
  public:
    int unk00;
    hkBlockD46E* m_next;
    int unk08;
    int m_iVertexCount;

    int SumLinkedValues() const;
};

// @fnv 0x00d46de0
int hkBlockD46E::SumLinkedValues() const
{
    const hkBlockD46E* pkBlock = m_next;
    int iTotal = m_iVertexCount;
    while (pkBlock)
    {
        iTotal += pkBlock->m_iVertexCount;
        pkBlock = pkBlock->m_next;
    }
    return iTotal;
}

// @fnv 0x00d46e00
// src: GUESS 0x00d46e00 (confidence: high)
int __stdcall Object_ReturnZero_00d46e00(int arg0)
{
    return 0;
}

// @fnv 0x00d46e10
// src: GUESS 0x00d46e10 (confidence: high)
int __stdcall Runtime_ReturnZero_00d46e10(int arg0)
{
    return 0;
}

struct FUN_00d46e20_cls
{
    void* unk00;
    void* unk04;
    void* unk08;
    int unk0C;
    int __thiscall GetUnk0C_00d46e20();
};

// @fnv 0x00d46e20
// src: GUESS 0x00d46e20 (confidence: low)
int FUN_00d46e20_cls::GetUnk0C_00d46e20()
{
    return unk0C;
}

struct hkListNodeD46E
{
    int m_00;
    hkListNodeD46E* m_next;
    int m_08;
    int m_0c;
    int m_10;
    int m_iElementCount;

    int SumListValues() const;
};

// @fnv 0x00d46e30
int hkListNodeD46E::SumListValues() const
{
    const hkListNodeD46E* pkNode = m_next;
    int iTotal = m_iElementCount;
    while (pkNode)
    {
        iTotal += pkNode->m_iElementCount;
        pkNode = pkNode->m_next;
    }
    return iTotal;
}

int __cdecl hkString_strCmp(int, int);

struct hkNamedEntryD46E
{
    int m_name;
};

class hkEntryListD46E
{
  public:
    int SumListValues() const;
    hkNamedEntryD46E* hkClass_getEnum(int i);

    hkNamedEntryD46E* FindByName(int iName);
};

// Scans the entries and returns the first whose m_name matches iName via FUN_00cb0fa0, or null if none match.
// @fnv 0x00d46e90
hkNamedEntryD46E* hkEntryListD46E::FindByName(int iName)
{
    for (int i = 0; i < SumListValues(); i++)
    {
        hkNamedEntryD46E* pkEntry = hkClass_getEnum(i);
        if (hkString_strCmp(pkEntry->m_name, iName) == 0)
            return pkEntry;
    }
    return 0;
}

// @fnv 0x00d46ee0
int* __fastcall GetEntryAt(char* self, int edx, int index)
{
    int* base = (int*)(*(int*)(self + 0x10));
    return &base[index * 5];
}

struct FnvCpu_FUN_00d46ef0_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    int value;
    int GetValue();
};
// @fnv 0x00d46ef0
// src: GUESS 0x00d46ef0 (confidence: low)
int FnvCpu_FUN_00d46ef0_CpuObject::GetValue()
{
    return value;
}

struct FUN_00d47730_cls
{
    hkReferencedObject* unk00;
    FUN_00d47730_cls* SetObject(hkReferencedObject* p, int unk);
};

// @fnv 0x00d47730
FUN_00d47730_cls* FUN_00d47730_cls::SetObject(hkReferencedObject* pObject, int aiUnused)
{
    if (pObject)
    {
        pObject->addReference();
    }
    unk00 = pObject;
    return this;
}

struct FUN_00d48300_Obj
{
    void ProcessAndReturnValue_00d48300(int a1);
};
// @fnv 0x00d47f40
// src: GUESS 0x00d47f40 (confidence: low)
void __cdecl Object_ProcessState_00d47f40(FUN_00d48300_Obj* obj, int aiValue)
{
    if (obj)
    {
        obj->ProcessAndReturnValue_00d48300(aiValue);
    }
}

class GlobalObjectO2_00d472a0;
extern GlobalObjectO2_00d472a0 g_01268b24;

// @fnv 0x00d47f60
// src: GUESS 0x00d47f60 (confidence: low)
GlobalObjectO2_00d472a0* __cdecl Object_GetGlobalObjectAddress_00d47f60()
{
    return &g_01268b24;
}

struct FnvCpu_FUN_00d47f70_CpuTarget
{
    void FUN_00d48320(int value);
};
// @fnv 0x00d47f70
// src: GUESS 0x00d47f70 (confidence: low)
void __cdecl Runtime_ProcessState_00d47f70(FnvCpu_FUN_00d47f70_CpuTarget* pCpuTarget, int value)
{
    if (pCpuTarget)
        pCpuTarget->FUN_00d48320(value);
}

struct CpuOpaque;
extern CpuOpaque DAT_01268b54;
// @fnv 0x00d47f90
// src: GUESS 0x00d47f90 (confidence: low)
CpuOpaque* __cdecl Runtime_GetDAT01268b54Address()
{
    return &DAT_01268b54;
}

struct Sh00cb0c00
{
    void Object_UpdateFields_00cb0c00();
};

// @fnv 0x00d47fa0
// src: GUESS 0x00d47fa0 (confidence: low)
void __cdecl Object_UpdateFields_00d47fa0(void* obj)
{
    void** ref = (void**)((char*)obj + 8);
    if (*ref)
        ((hkReferencedObject*)*ref)->removeReference();
    *ref = 0;
    ((Sh00cb0c00*)((char*)obj + 4))->Object_UpdateFields_00cb0c00();
    ((Sh00cb0c00*)obj)->Object_UpdateFields_00cb0c00();
}

struct FUN_00d47fe0_cls
{
    void __thiscall Destroy(int value);
};

// @fnv 0x00d47fd0
// src: HAVOK_LIB 0x00d47fd0
void __cdecl cleanupLoadedObjecthkRootLevelContainer(FUN_00d47fe0_cls* object)
{
    object->Destroy(0);
}

class FUN_00d48320
{
  public:
    FUN_00d48320(FinishingFlag flag);
};

// @fnv 0x00d48320
FUN_00d48320::FUN_00d48320(FinishingFlag flag)
{}

class FUN_00dcc160_cls
{
  public:
    FUN_00dcc160_cls* InitFromValue(void* pvSource);
    void SetVirtualTable_00dcc160();

    int m_iUnk00;
    int m_iUnk04;
    void* m_pResource;
};

// @fnv 0x00d491b0
// src: XBOX_PDB 0x00d491b0
void* __cdecl hkSerializeUtil_loadOnHeap_00d491b0(void* pvSource, void* pvArg, void* pvArgCur, void* kvArg)
{
    FUN_00dcc160_cls kData;
    void* pvData = kData.InitFromValue(pvSource)->m_pResource;
    void* pvResult = hkSerializeUtil_loadOnHeap(pvData, pvArg, pvArgCur, kvArg);
    kData.SetVirtualTable_00dcc160();
    return pvResult;
}

// @fnv 0x00d4b150
// src: COMMUNITY 0x00d4b150
void nullsub_97()
{}

// @fnv 0x00d4b290
// src: COMMUNITY 0x00d4b290
void __cdecl nullsub_99()
{}

// @fnv 0x00d4b2b0
// src: COMMUNITY 0x00d4b2b0
void __cdecl nullsub_101()
{}

// @fnv 0x00d4b360
// src: COMMUNITY 0x00d4b360
void nullsub_98()
{}

// @fnv 0x00d4b370
// src: COMMUNITY 0x00d4b370
void nullsub_100()
{}

// @fnv 0x00d4bef0
// src: COMMUNITY 0x00d4bef0
void nullsub_102()
{}

void __cdecl hkConstraintCinfo_LoadBinary(int* param_1, int param_2);

// @fnv 0x00d50000
// src: XBOX_PDB 0x00d50000
void __cdecl hkGenericConstraintCinfo_LoadBinary(int* param_1, int param_2)
{
    hkConstraintCinfo_LoadBinary(param_1, param_2);
}

struct FUN_00c89920_cls
{
    void __thiscall InvokeRefTarget(int);
};
struct FUN_00d53290_cls
{
    void __thiscall bhkConstraintChain_SaveBinary(int a);
};
// @fnv 0x00d53290
// src: XBOX_PDB 0x00d53290
void __thiscall FUN_00d53290_cls::bhkConstraintChain_SaveBinary(int a)
{
    ((FUN_00c89920_cls*)this)->InvokeRefTarget(a);
}


namespace hkRouterD539 {
extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance() throw();
}
void __cdecl hkArrayUtil__reserve(hkMemoryAllocator& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();

struct hkInfoD539
{
    int unk00[5];
    hkArray<int> m_keys;
};

struct hkContainerD539
{
    int unk00[14];
    int* m_keys;
    int m_numKeys;
};

class FUN_00c89c80_obj
{
  public:
    void CopyFromSource(unsigned int info) throw();
};

class hkShapeD539 : public FUN_00c89c80_obj
{
  public:
    int unk00;
    int unk04;
    hkContainerD539* m_container;

    void CopyContainerKeysToInfo(hkInfoD539& info);
};

// Calls CopyFromSource on info, then if m_container is set resizes info.m_keys to m_numKeys and copies the container's keys into it.
// @fnv 0x00d53900
void hkShapeD539::CopyContainerKeysToInfo(hkInfoD539& info)
{
    CopyFromSource((unsigned int)&info);
    if (this && m_container)
    {
        hkContainerD539* c = m_container;
        info.m_keys.setSize(c->m_numKeys);
        for (int i = 0; i < c->m_numKeys; i++)
            info.m_keys.m_data[i] = c->m_keys[i];
    }
}

class FUN_00d54180_cls
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    hkVector4 m_kPointA;
    hkVector4 m_kPointB;

    void hkpBallAndSocketConstraintData_setInWorldSpace(const hkTransform& kA, const hkTransform& kB, const hkVector4& fT);
};

// @fnv 0x00d54180
// src: HAVOK_LIB 0x00d54180
void FUN_00d54180_cls::hkpBallAndSocketConstraintData_setInWorldSpace(const hkTransform& kA, const hkTransform& kB, const hkVector4& fT)
{
    m_kPointA.hkVector4_setTransformedInversePos(kA, fT);
    m_kPointB.hkVector4_setTransformedInversePos(kB, fT);
}

struct FnvCpu_FUN_00d54d60_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    float value;
    void SetValue_00d54d60(float input);
};
// @fnv 0x00d54d60
// src: GUESS 0x00d54d60 (confidence: medium)
void FnvCpu_FUN_00d54d60_CpuObject::SetValue_00d54d60(float input)
{
    value = input;
}

struct FnvCpu_FUN_00d54d70_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    float value;
    float hkpMoppCompilerInput_getAbsoluteFitToleranceOfTriangles();
};
// @fnv 0x00d54d70
// src: COMMUNITY 0x00d54d70
float FnvCpu_FUN_00d54d70_CpuObject::hkpMoppCompilerInput_getAbsoluteFitToleranceOfTriangles()
{
    return value;
}

struct FUN_00d54da0_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    float m_10;

    void SetField10_00d54da0(float value);
};

// @fnv 0x00d54da0
// src: GUESS 0x00d54da0 (confidence: low)
void FUN_00d54da0_Class::SetField10_00d54da0(float value)
{
    m_10 = value;
}

struct FnvCpu_FUN_00d54db0_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    float value;
    float hkpMoppCompilerInput_getRelativeFitToleranceOfInternalNodes();
};
// @fnv 0x00d54db0
// src: COMMUNITY 0x00d54db0
float FnvCpu_FUN_00d54db0_CpuObject::hkpMoppCompilerInput_getRelativeFitToleranceOfInternalNodes()
{
    return value;
}

struct FUN_00d54dc0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    float unk14;

    void __thiscall SetUnk14_00d54dc0(float value);
};

// @fnv 0x00d54dc0
// src: GUESS 0x00d54dc0 (confidence: low)
void __thiscall FUN_00d54dc0_cls::SetUnk14_00d54dc0(float value)
{
    unk14 = value;
}

// @fnv 0x00d54dd0
// src: COMMUNITY 0x00d54dd0
float __fastcall hkpMoppCompilerInput_getAbsoluteFitToleranceOfInternalNodes(char* self, int)
{
    return *(float*)(self + 0x14);
}

// @fnv 0x00d55510
// src: GUESS 0x00d55510 (confidence: high)
void __cdecl Runtime_DoNothing_00d55510()
{}

typedef unsigned int D57Uint32;

static __forceinline void D57MemCpy16NonEmpty(void* dst, const void* src, int numQuads)
{
    const D57Uint32* src32 = reinterpret_cast<const D57Uint32*>(src);
    D57Uint32* dst32 = reinterpret_cast<D57Uint32*>(dst);
    do
    {
        dst32[0] = src32[0];
        dst32[1] = src32[1];
        dst32[2] = src32[2];
        dst32[3] = src32[3];
        dst32 += 4;
        src32 += 4;
    } while (--numQuads > 0);
}

// Copies six 16-byte blocks from s to d using D57MemCpy16NonEmpty.
// @fnv 0x00d57090
void __cdecl CopySixteenByteBlocks(int* pDest, const int* pSrc)
{
    D57MemCpy16NonEmpty(pDest, pSrc, 6);
}

// @fnv 0x00d57150
// src: GUESS 0x00d57150 (confidence: high)
void Runtime_DoNothing_00d57150()
{}

// @fnv 0x00d584f0
// src: GUESS 0x00d584f0 (confidence: high)
int __stdcall Runtime_ReturnConstant_0x60(int iUnused0, int iUnused1)
{
    return 0x60;
}

struct FUN_00d58ce0_DisplayObj
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08(int, int);
};

struct FUN_00d58ce0_Class
{
    int unk00;
    unsigned short unk04;

    int __thiscall FUN_00d58ce0(unsigned char flag);
};

extern "C" void __cdecl FUN_00da2560();

// @fnv 0x00d58ce0
int __thiscall FUN_00d58ce0_Class::FUN_00d58ce0(unsigned char flag)
{
    FUN_00da2560();

    if ((flag & 1) != 0)
    {
        hkMemoryRouter* holder = hkMemoryRouter_getInstance();
        FUN_00d58ce0_DisplayObj* display = (FUN_00d58ce0_DisplayObj*)holder->m_heap;
        display->vf08((int)this, (int)this->unk04);
    }

    return (int)this;
}

extern double DAT_010229c0;
struct FUN_00d5d660_cls
{
    int m_i00;
    int m_i04;
    void __thiscall NextFloat4(float* pOut);
};
// Advances the linear congruential state four times and writes each new state, scaled to [0,1), into pOut[0..3].
// @fnv 0x00d5d660
void __thiscall FUN_00d5d660_cls::NextFloat4(float* pOut)
{
    m_i04 = (int)((long long)m_i04 * 0x19660dLL + 0x3c6ef35fLL);
    *pOut = (float)(unsigned int)m_i04 * 2.3283064365386963e-10;
    m_i04 = (int)((long long)m_i04 * 0x19660dLL + 0x3c6ef35fLL);
    *(pOut + 1) = (float)(unsigned int)m_i04 * 2.3283064365386963e-10;
    m_i04 = (int)((long long)m_i04 * 0x19660dLL + 0x3c6ef35fLL);
    *(pOut + 2) = (float)(unsigned int)m_i04 * 2.3283064365386963e-10;
    m_i04 = (int)((long long)m_i04 * 0x19660dLL + 0x3c6ef35fLL);
    *(pOut + 3) = (float)(unsigned int)m_i04 * 2.3283064365386963e-10;
}


inline void hkReferencedObject::operator delete(void* p)
{
    reinterpret_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance())
        ->heap().blockFree(p, static_cast<hkReferencedObject*>(p)->m_usMemSizeAndFlags);
}

// 0x00d5e070 (ConvexChildShapeOwner) is in blk_00d40000_o2_ehsc_noehsc_variant.cpp: no EH frame in the original.

inline hkpShapeContainer::~hkpShapeContainer() {}
inline hkpSingleShapeContainer::~hkpSingleShapeContainer()
{
    if (m_pContainedShape)
        const_cast<hkpShape*>(m_pContainedShape)->removeReference();
}


struct FUN_00d5e0c0_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
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
    unsigned char unk40;

    unsigned char __thiscall hkpConvexListShape_getUseCachedAabb();
};

// @fnv 0x00d5e0c0
// src: XBOX_PDB 0x00d5e0c0
unsigned char FUN_00d5e0c0_Obj::hkpConvexListShape_getUseCachedAabb()
{
    return unk40;
}

struct FUN_00d5f740_cls
{
    char pad[0x24];
    int m_24;
    char pad2[0xc0 - 0x28];
    int m_c0;
    void __thiscall SetValue(int a);
};

// @fnv 0x00d5f740
void __thiscall FUN_00d5f740_cls::SetValue(int aiValue)
{
    m_24 = aiValue;
    m_c0 = aiValue;
}

struct D46E50Node
{
    int unk00;
    D46E50Node* m_pNext;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;

    int hkClass_getEnum(int param);
};

struct D46E50Helper
{
    int unk00;
    void* m_pNext;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;

    __declspec(noinline) int SumListValues();
};

int D46E50Helper::SumListValues()
{
    int sum = unk14;
    for (void* p = m_pNext; p; p = ((D46E50Helper*)p)->m_pNext)
        sum += ((D46E50Helper*)p)->unk14;
    return sum + unk00;
}

// Walks nodes adding unk14 to param minus SumListValues() until it is non-negative, returning that node's unk10 + value * 20; otherwise this->unk10.
// @fnv 0x00d46e50
// src: HAVOK_LIB 0x00d46e50
int D46E50Node::hkClass_getEnum(int param)
{
    D46E50Node* node = this;
    int d = param - ((D46E50Helper*)this)->SumListValues();
    if (this)
    {
        do
        {
            d += node->unk14;
            if (d >= 0)
            {
                return node->unk10 + d * 20;
            }
            node = node->m_pNext;
        } while (node);
    }
    return this->unk10;
}

struct MemberD472
{
    int m_data;
};

class OwnerD472
{
  public:
    MemberD472* GetMember();

    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    MemberD472 m_kMember;
};

// @fnv 0x00d47290
MemberD472* OwnerD472::GetMember()
{
    return &m_kMember;
}

// FUN_00d48fc0 - loads a Havok packfile/tagfile from a stream and dispatches
// on the format that was detected in it.

extern const char str_010cfacc[];
extern const char str_010cfab8[];
extern const char str_010cfa94[];
extern const char str_010cf830[];
extern const unsigned char DAT_011b7b88[];
extern void* DAT_01269b70;

struct Hk48fc0_String
{
    char* m_pText;
    void __thiscall FUN_00cb0a60();
    void __thiscall Object_UpdateFields_00cb0c00();
    Hk48fc0_String* __thiscall UpdateState_00cb0c10(const char* pText);
    int __thiscall Equals(const char* pText);
};

struct Hk48fc0_Magic
{
    unsigned int m_uValue;
    hkBool __thiscall MatchesTag(const unsigned char* pExpected);
};

struct Hk48fc0_Format
{
    int m_nType;
    Hk48fc0_String m_strVersion;
    Hk48fc0_Magic m_kMagic;
};

struct Hk48fc0_Error
{
    int m_nCode;
    Hk48fc0_String m_strMsg;
};

struct Hk48fc0_Stream
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual hkBool __thiscall IsStreamValid();
};

struct Hk48fc0_Factory
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void* __thiscall getLoader();
    virtual void* __thiscall getAllocator();
};
extern Hk48fc0_Factory* DAT_01268b08;

struct Hk48fc0_Loader
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void* __thiscall load(void* pStream, Hk48fc0_Format* pFormat, void* pError);
};
extern Hk48fc0_Loader* DAT_01269b74;

struct Hk48fc0_Contents
{
    void* m_pData;
    void __thiscall ReleaseStorage_00dba7f0();
    void __thiscall hkVersionPatchManager_applyPatches(void* pArg1, void* pArg2);
};

struct Hk48fc0_Data
{
    void* m_pVtbl;
    void* m_pData;
    int m_nRef;
    void __thiscall hkDataWorldDict_hkDataWorldDict();
    void __thiscall ReleaseStorage_00dc8080();
    void* __thiscall ForwardToReceiver(Hk48fc0_Contents* pOut);
};

void __cdecl hkSerializeUtil_detectFormat(void* pStream, Hk48fc0_Format* pFormat);
void* __cdecl hkDataObjectUtil_toObjectWithRegistry(void* pData, void* pAllocator, void* pLoader);
int __cdecl Hkserializeutil_UpdateState_00d48950(void* pObj, void* pArg1, void* pArg2, void* pArg3);
void __cdecl hkBinaryTagfileReader_load(void* pArg1, void* pArg2, void* pArg3);

// module-local helper: object in ESI, error in EDI, stream on the stack
__declspec(noinline) static int Hk48fc0_ReadTagfile(Hk48fc0_Data* pObj, void* pError, void* pStream, void* pAllocator)
{
    Hk48fc0_Contents kBuf;
    hkBinaryTagfileReader_load(&kBuf, &pStream, pObj);
    if (pError)
    {
        if (Hkserializeutil_UpdateState_00d48950(pObj, pError, DAT_01269b70, pAllocator) == 0)
        {
            return 1;
        }
    }
    kBuf.hkVersionPatchManager_applyPatches(pObj, pAllocator);
    return 0;
}

// module-local helper: allocator in EAX, the rest on the stack
__declspec(noinline) static void* Hk48fc0_LoadPackfile(void* pAllocator, void* pStream, Hk48fc0_Format* pFormat,
                                                       void* pError, void* pLoader)
{
    if (pAllocator == 0)
    {
        return 0;
    }
    hkBinaryTagfileReader_load(pAllocator, &pStream, &pFormat);
    return hkDataObjectUtil_toObjectWithRegistry(&pError, &pLoader, 0);
}

// @fnv 0x00d48fc0
// src: XBOX_PDB 0x00d48fc0
void* __cdecl hkSerializeUtil_loadOnHeap(void* pStream, void* pError, void* pAllocator, void* pLoader)
{
    Hk48fc0_Contents kContents;
    if (!pStream)
    {
        if (pError)
        {
            reinterpret_cast<Hk48fc0_Error*>(pError)->m_nCode = 1;
            reinterpret_cast<Hk48fc0_Error*>(pError)->m_strMsg.UpdateState_00cb0c10(str_010cfacc);
        }
        return 0;
    }
    if (!reinterpret_cast<Hk48fc0_Stream*>(pStream)->IsStreamValid())
    {
        if (pError)
        {
            reinterpret_cast<Hk48fc0_Error*>(pError)->m_nCode = 1;
            reinterpret_cast<Hk48fc0_Error*>(pError)->m_strMsg.UpdateState_00cb0c10(str_010cfab8);
        }
        return 0;
    }
    if (!pAllocator)
    {
        pAllocator = DAT_01268b08->getAllocator();
    }
    if (!pLoader)
    {
        pLoader = DAT_01268b08->getLoader();
    }
    Hk48fc0_Format kFormat;
    kFormat.m_strVersion.FUN_00cb0a60();
    hkSerializeUtil_detectFormat(pStream, &kFormat);
    switch (kFormat.m_nType)
    {
    case 4: {
        Hk48fc0_Data kData;
        kData.hkDataWorldDict_hkDataWorldDict();
        if (!Hk48fc0_ReadTagfile(&kData, pError, pStream, pAllocator))
        {
            void* pResult = hkDataObjectUtil_toObjectWithRegistry(kData.ForwardToReceiver(&kContents), pAllocator, pLoader);
            kContents.ReleaseStorage_00dba7f0();
            kData.ReleaseStorage_00dc8080();
            kFormat.m_strVersion.Object_UpdateFields_00cb0c00();
            return pResult;
        }
        kData.ReleaseStorage_00dc8080();
        kFormat.m_strVersion.Object_UpdateFields_00cb0c00();
        return 0;
    }
    case 2: {
        if (kFormat.m_kMagic.MatchesTag(DAT_011b7b88) && kFormat.m_strVersion.Equals(str_010cf830))
        {
            void* pResult = Hk48fc0_LoadPackfile(pAllocator, pStream, &kFormat, pError, pLoader);
            kFormat.m_strVersion.Object_UpdateFields_00cb0c00();
            return pResult;
        }
    }
    // fall through
    case 3: {
        void* pResult = DAT_01269b74->load(pStream, &kFormat, pError);
        kFormat.m_strVersion.Object_UpdateFields_00cb0c00();
        return pResult;
    }
    default:
        if (pError)
        {
            reinterpret_cast<Hk48fc0_Error*>(pError)->m_nCode = 2;
            reinterpret_cast<Hk48fc0_Error*>(pError)->m_strMsg.UpdateState_00cb0c10(str_010cfa94);
        }
        kFormat.m_strVersion.Object_UpdateFields_00cb0c00();
        return 0;
    }
}

struct d20base
{
    int f0;
};

d20base* volatile g_d20_self;

extern "C" int d20_sel(void);

// @fnv 0x00d49c20
// src: HAVOK_LIB 0x00d49c20
static __declspec(noinline) int numIndices_00d49c20(d20base* self, int sel)
{
    switch (sel)
    {
    case 1:
        return (int)self + 2;
    case 2:
        return 2 * (int)self + 1;
    default:
        return 4 * (int)self;
    }
}

int d20_probe(void)
{
    return numIndices_00d49c20((d20base*)g_d20_self, d20_sel());
}

// FUN_00d4b390: element-size helper of the BGS load-form buffer code.
// Takes the base element size and a small type code, and returns the
// element size for that type code: type 1 -> base + 2, type 2 -> base*2 + 1,
// anything else -> base * 3.
//
// The original keeps its operands in registers (base in ecx, type code in
// eax): it is a helper VC9 gives a private register convention because its
// callers are known at compile time. Defining it as a static noinline
// helper with its caller in this file reproduces that convention.
volatile int g_base_d4b390;
volatile int g_code_d4b390;
volatile int g_sink_d4b390;

// @fnv 0x00d4b390
// src: HAVOK_LIB 0x00d4b390
static __declspec(noinline) int storageMeshShape_numIndices(int base, int code)
{
    switch (code)
    {
    case 1:
        return base + 2;
    case 2:
        return base * 2 + 1;
    default:
        return base * 3;
    }
}

// Stand-in for the in-binary caller: reads both operands at call time and
// stores the result, so the helper call and its register convention stay.
void elem_size_case_d4b390(void)
{
    g_sink_d4b390 = storageMeshShape_numIndices(g_base_d4b390, g_code_d4b390);
}

struct hkpD500Stream;

class hkpD500Object
{
  public:
    void hkConstraintCinfo_SaveBinary(hkpD500Stream* pkStream);
    void hkGenericConstraintCinfo_SaveBinary(hkpD500Stream* pkStream);
};

// @fnv 0x00d50010
// src: XBOX_PDB 0x00d50010
void hkpD500Object::hkGenericConstraintCinfo_SaveBinary(hkpD500Stream* pkStream)
{
    hkConstraintCinfo_SaveBinary(pkStream);
}


class FUN_00d21ce0_cls
{
  public:
    FUN_00d21ce0_cls(FinishingFlag flag)
    {
        if (flag.m_bFinishing)
            hkpBridgeConstraintAtom_init(m_pOwnerObject);
    }
    void hkpBridgeConstraintAtom_init(void* owner);

    int unk00;
    int unk04;
    void* m_pOwnerObject;
};

class FUN_00dd0420_Class
{
  public:
    FUN_00dd0420_Class* hkpGenericConstraintDataScheme_hkpGenericConstraintDataScheme(int flag);

    int unk00;
};

class FUN_00d50c00
{
  public:
    FUN_00d50c00(FinishingFlag flag);
    virtual ~FUN_00d50c00();

    int unk04;
    int unk08;
    FUN_00d21ce0_cls m_kListeners;
    FUN_00dd0420_Class m_data;
};

// @fnv 0x00d50c00
FUN_00d50c00::FUN_00d50c00(FinishingFlag flag) : m_kListeners(flag)
{
    m_data.hkpGenericConstraintDataScheme_hkpGenericConstraintDataScheme(flag.m_bFinishing);
    if (flag.m_bFinishing)
        m_kListeners.hkpBridgeConstraintAtom_init(this);
}

class ObjD534
{
  public:
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual int GetType94();
    virtual void slot38();
    virtual void slot39();
    virtual void ResetA0();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void AttachD8(ObjD534* other, int flag);
    int unk04;
    int m_08;
    void bhkWorld_Add_00c6b320(int value);
    bool bhkConstraintChain_Add(ObjD534* other);
};
// When m_08 is nonzero: resets and attaches other (passing it m_08, returning true) if its type differs, or just resets when other is null.
// @fnv 0x00d534e0
// src: XBOX_PDB 0x00d534e0
bool ObjD534::bhkConstraintChain_Add(ObjD534* other)
{
    AutoMemContext context(16);
    int value = this ? m_08 : 0;
    bool result = false;
    if (value)
    {
        if (other)
        {
            int myType = GetType94();
            int theirType = other->GetType94();
            if (myType != theirType)
            {
                ResetA0();
                AttachD8(other, 1);
                other->bhkWorld_Add_00c6b320(value);
                result = true;
            }
        }
        else
        {
            ResetA0();
        }
    }
    return result;
}


hkMemoryRouter& __cdecl GetMemoryRouterD53();
template <typename T> __forceinline void hkArrayBase<T>::clear()
{
    m_iElementCount = 0;
}
template <typename T> __forceinline void hkArrayBase<T>::GrowArrayCapacity(hkMemoryAllocator& kHeap, int iWanted)
{
    const int iHave = getCapacity();
    if (iHave < iWanted)
    {
        int iTwice = 2 * iHave;
        int iGrowTo = (iWanted < iTwice) ? iTwice : iWanted;
        hkArrayUtil::_reserve(kHeap, this, iGrowTo, sizeof(T));
    }
}
template <typename T> __forceinline void hkArrayBase<T>::_setSize(hkMemoryAllocator& alloc, int n)
{
    GrowArrayCapacity(alloc, n);
    m_iElementCount = n;
}
__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return GetMemoryRouterD53().heap();
}
template <typename T, typename A> __forceinline hkArray<T, A>::~hkArray()
{
    hkMemoryAllocator& alloc = A().get(this);
    m_iElementCount = 0;
    if ((m_iCapacityState & 0x80000000) == 0)
        alloc.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
    m_data = 0;
    m_iCapacityState = 0x80000000;
}


template <class A, class K, class V>
inline bool NiTMapBase<A, K, V>::GetAt(K key, V& val) const
{
    unsigned int index = KeyToHashIndex(key);
    NiTMapItem<K, V>* item = m_ppkHashTable[index];
    while (item)
    {
        if (IsKeysEqual(key, item->m_key))
        {
            val = item->m_val;
            return true;
        }
        item = item->m_pkNext;
    }
    return false;
}

// The shared bhkListShape hierarchy does not declare the base copy routine at 0x00c89730.
extern "C" void CopyListShapeBase();

// This record stores a wrapper pointer at +0x0c; shared hkpShape stores its type there.
class WrapperLinkedHavokObject
{
  public:
    virtual void v00();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned int m_ulUserData;
    bhkRefObject* m_pkWrapper;
};

// The clone record has a pointer array at +0x14, unlike hkpListShape's ChildInfo array at +0x18.
class ShapeClonePointerArrayOwner
{
  public:
    unsigned int unk00;
    void* m_containerVptr;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    hkArray<WrapperLinkedHavokObject*> m_kChildShapes;
};

inline ShapeClonePointerArrayOwner* GetShapeClonePointerArrayOwner(void* pkContainer)
{
    return pkContainer ? reinterpret_cast<ShapeClonePointerArrayOwner*>(reinterpret_cast<char*>(pkContainer) - 4) : 0;
}

// @fnv 0x00d53a80
void __fastcall CopyListShapeMembers(bhkListShape* self, void*, NiObject* pkDest, CloningProcess& kCloning)
{
    AutoMemContext kContext(0x10);
    char cTmp;
    ShapeClonePointerArrayOwner* pkList = GetShapeClonePointerArrayOwner(self->slotB4(&cTmp));

    hkArray<bhkRefObject*> kChildren;
    kChildren.setSize(pkList->m_kChildShapes.GetLogicalSize());
    for (int i = 0; i < pkList->m_kChildShapes.GetLogicalSize(); i++)
    {
        WrapperLinkedHavokObject* pkShape = pkList->m_kChildShapes[i];
        kChildren[i] = pkShape ? pkShape->m_pkWrapper : 0;
    }
    pkList->m_kChildShapes.clear();

    hkArray<WrapperLinkedHavokObject*>& kShapes = pkList->m_kChildShapes;
    kShapes.setSize(kChildren.GetLogicalSize());
    for (int j = 0; j < kChildren.GetLogicalSize(); j++)
    {
        NiObject* pkClone;
        // CloningProcess is opaque in the shared headers; its clone-map pointer is at +0.
        if (!(*reinterpret_cast<NiTPointerMap<NiObject*, NiObject*>**>(&kCloning))->GetAt(kChildren[j], pkClone))
            pkClone = kChildren[j]->MakeClone(kCloning);
        WrapperLinkedHavokObject* pkShape = reinterpret_cast<WrapperLinkedHavokObject*>(static_cast<bhkRefObject*>(pkClone)->m_pHavokObject);
        kShapes[j] = pkShape;
    }

    reinterpret_cast<void(__thiscall*)(bhkListShape*, NiObject*, CloningProcess&)>(&CopyListShapeBase)(self, pkDest, kCloning);
}

class FUN_00d543e0
{
  public:
    virtual ~FUN_00d543e0();
    char unk04[0x3c];
};

class FUN_00d54960 : public FUN_00d543e0
{
  public:
    virtual ~FUN_00d54960();

    hkReferencedObject* m_pReference;
};

// Releases the hkReferencedObject reference held by m_pReference if it is non-null.
// @fnv 0x00d54960
FUN_00d54960::~FUN_00d54960()
{
    if (m_pReference)
        static_cast<const hkReferencedObject*>(m_pReference)->removeReference();
}

struct QuadD54D
{
    int unk00, unk04, unk08, unk0C;
};

class HolderD54D
{
  public:
    QuadD54D m_kValue;

    QuadD54D GetValue() const;
};

// @fnv 0x00d54d80
QuadD54D HolderD54D::GetValue() const
{
    return m_kValue;
}

extern char* DAT_01268f90;
char* __cdecl NiViewerStrings_NiGetViewerString_Title(char*);
struct FUN_00d54ed0_Obj
{
    unsigned int unk00, unk04;
    unsigned short unk08, unk0A, unk0C, unk0E;
    void __thiscall FUN_0096ad30(unsigned int);
    void __thiscall FUN_0096ae90(unsigned int, char**);
};
struct FNVMemoryManager
{
    void __thiscall bhkShape_GetViewerStrings(FUN_00d54ed0_Obj*);
    void __thiscall bhkHeightFieldShape_GetViewerStrings(FUN_00d54ed0_Obj*);
};
// Calls FUN_00c851c0 on object, then appends a string from FUN_00a7d330(DAT_01268f90) via FUN_0096ae90, growing with FUN_0096ad30 first when full.
// @fnv 0x00d54ed0
// src: XBOX_PDB 0x00d54ed0
void __thiscall FNVMemoryManager::bhkHeightFieldShape_GetViewerStrings(FUN_00d54ed0_Obj* object)
{
    AutoMemContext scope(16);
    this->bhkShape_GetViewerStrings(object);
    char* result = NiViewerStrings_NiGetViewerString_Title(DAT_01268f90);
    unsigned int n = object->unk0A;
    if (n >= object->unk08)
        object->FUN_0096ad30(object->unk0E + n);
    object->FUN_0096ae90(n, &result);
}

struct D47180Cls
{
    int FUN_00d47130(int, int*, int*);
    int IsHelperResultFalse_00d47180(int arg);
};

// Calls FUN_00d47130 with arg and two local pointers, returning 0 if the call is true, else 1.
// @fnv 0x00d47180
// src: GUESS 0x00d47180 (confidence: low)
int D47180Cls::IsHelperResultFalse_00d47180(int arg)
{
    int a;
    return FUN_00d47130(arg, &a, &arg) ? 0 : 1;
}

// @fnv 0x00d48420
// src: GUESS 0x00d48420 (confidence: low)
static __declspec(noinline) char* Object_ProcessEntries_00d48420(char* p)
{
    while (*p != 0 && *p == ' ')
        ++p;
    return p;
}

volatile char* g_d48420_p;

char* d48420_caller()
{
    return Object_ProcessEntries_00d48420((char*)g_d48420_p);
}

struct FieldWord
{
    unsigned char value;
    FieldWord(unsigned char x) : value(x)
    {}
    FieldWord& operator=(unsigned char x)
    {
        value = x;
        return *this;
    }
    operator unsigned char() const
    {
        return value;
    }
};
extern "C" void _ReadWriteBarrier();
struct S_00d49660_Foo
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
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
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    FieldWord unk64;
    int unk68;
    float unk6c;
    unsigned char unk70;

    void __thiscall ProcessAndReturnValue_00d248a0(int, int);
    S_00d49660_Foo* __thiscall hkpStorageSampledHeightFieldShape_hkpStorageSampledHeightFieldShape(int, int, float);
};

extern int DAT_010cfb34;
extern double DAT_01012070;
int __cdecl FUN_00ec62c0();

// Calls FUN_00d248a0(a, 0), sets unk00 to the address of DAT_010cfb34, stores b in unk60 and c in unk6c, derives unk68 from unk14, and returns this.
// @fnv 0x00d49660
// src: EXE 0x00d49660
S_00d49660_Foo* __thiscall S_00d49660_Foo::hkpStorageSampledHeightFieldShape_hkpStorageSampledHeightFieldShape(int a, int b, float c)
{
    ProcessAndReturnValue_00d248a0(a, 0);
    unk00 = reinterpret_cast<int>(&DAT_010cfb34);
    unk64 = 0;
    unk70 = 0;
    unk60 = b;
    unk68 = (int)((double)unk14 - 1.0);

    unk6c = c;
    return this;
}

class FUN_00d50c90
{
  public:
    virtual ~FUN_00d50c90();
    unsigned short sizeAndFlags, referenceCount;
    int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    void* data28;
    int size2c, flags30;
    void* data34;
    int size38, flags3c;
    void* data40;
    int size44, flags48;
    void* data4c;
    int size50, flags54;
    FUN_00d50c90();
    static void* operator new(unsigned int bytes)
    {
        FUN_00d50c90* p = (FUN_00d50c90*)hkRouterD539::hkMemoryRouter_getInstance().heap().blockAlloc(bytes);
        p->sizeAndFlags = (unsigned short)bytes;
        return p;
    }
    static void operator delete(void* p)
    {
        hkRouterD539::hkMemoryRouter_getInstance().heap().blockFree(p, sizeof(FUN_00d50c90));
    }
};
struct OwnerD500
{
    void ReleaseObject(FUN_00d50c90*, int);
    void hkGenericConstraintCinfo_CloneData(FUN_00d50c90*, int);
};
// Creates a new FUN_00d50c90 object if object is null, then calls ReleaseObject on it with the given argument.
// @fnv 0x00d50090
// src: XBOX_PDB 0x00d50090
void OwnerD500::hkGenericConstraintCinfo_CloneData(FUN_00d50c90* object, int arg)
{
    AutoMemContext context(0x10);
    if (!object)
        object = new FUN_00d50c90;
    ReleaseObject(object, arg);
}

struct D502D0_Allocator
{
    void* __thiscall Game_DoHeapAlloc(unsigned int size);
};
extern D502D0_Allocator DAT_011f6238;
extern int DAT_010c9f38;
struct D502D0_RefData
{
    unsigned int m_uiFilterValue;
};
struct D502D0_RefObject
{
    void* m_pVtable;
    D502D0_RefData m_data;
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    unsigned int m_uiReserved;
};
static __forceinline D502D0_RefData* D502D0_CreateReference()
{
    D502D0_RefObject* object = reinterpret_cast<D502D0_RefObject*>(DAT_011f6238.Game_DoHeapAlloc(sizeof(D502D0_RefObject)));
    if (object)
    {
        D502D0_RefData* data = &object->m_data;
        object->m_uiRefCount = 1;
        object->m_uiValue1 = 0;
        object->m_uiReserved = 0;
        object->m_pVtable = &DAT_010c9f38;
        data->m_uiFilterValue = 0;
        return data;
    }
    return 0;
}
struct D502D0_Owner
{
    unsigned int m_unk00, m_unk04, m_flag08;
    D502D0_RefData* m_pData;
    void __thiscall CopyFromSource(D502D0_RefObject* object);
    D502D0_RefData* __thiscall EnsureReference(bool* created);
};
// Sets *created to true when m_pData is null, then creates a new D502D0_RefData via D502D0_CreateReference and copies from source if m_flag08 is set.
// @fnv 0x00d502d0
D502D0_RefData* D502D0_Owner::EnsureReference(bool* created)
{
    AutoMemContext guard(16);
    *created = m_pData == 0;
    if (*created)
    {
        D502D0_RefData* data = D502D0_CreateReference();
        m_pData = data;
        if (m_flag08)
            CopyFromSource(data ? reinterpret_cast<D502D0_RefObject*>(reinterpret_cast<char*>(data) - 4) : 0);
    }
    return m_pData;
}

inline void* operator new(unsigned int, void* p)
{
    return p;
}
struct Mem_d51b
{
    virtual void v00();
};

void __cdecl ResizeAudioStream(void* mem, void* array, int sizeOfElement);

struct Info_d51b
{
    int unk00;
    int m_iSchemaByteSize;
    int m_iSolverResultCount;
    int m_iSolverElementTemporaryCount;
    int unk10, unk14, unk18;
    hkArray<int> m_kBridgeAtoms;
    void add(int schema, int results, int temps)
    {
        m_iSchemaByteSize += schema;
        m_iSolverResultCount += results;
        m_iSolverElementTemporaryCount += temps;
    }
};

struct Kit_d51b
{
    int unk00;
    Info_d51b* m_info;
    void AddBridgeAtoms();
};

// Adds a bridge atom to m_info and accumulates schema byte size, solver result count, and temporary element count three times.
// @fnv 0x00d51bc0
void Kit_d51b::AddBridgeAtoms()
{
    d51::AddBack(m_info->m_kBridgeAtoms, 7);
    m_info->add(0x30, 1, 1);
    m_info->add(0x30, 1, 1);
    m_info->add(0x30, 1, 1);
}

extern volatile unsigned int DAT_0126fd98;

struct FUN_00dd0530
{
    unsigned int unk00;
    unsigned short size, flags;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    FUN_00dd0530(int);
    void AddReferencedObject(int);

    __forceinline void* SetSizeAndGrow(unsigned int n)
    {
        size = (unsigned short)n;
        return this;
    }
    static void* operator new(unsigned int n)
    {
        hkMemoryRouter* h = hkMemoryRouter_getInstance();
        return ((FUN_00dd0530*)((hkMemoryAllocator*)h->m_heap)->blockAlloc(n))->SetSizeAndGrow(n);
    }
    static void operator delete(void*);
};
struct Input
{
    unsigned int unk00;
    int value;
    unsigned int unk08, unk0c, unk10;
    int* items;
    int count;
};
struct Target
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
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35(FUN_00dd0530*);
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47(void*);
    void bhkConstraintChain_Init(void*);
};
// Allocates a FUN_00dd0530, adds each item from the Input's items array as a referenced object, then calls v35, FUN_00c905b0, and v47.
// @fnv 0x00d533e0
// src: XBOX_PDB 0x00d533e0
void Target::bhkConstraintChain_Init(void* arg)
{
    FUN_00dd0530* p;
    AutoMemContext context(16);
    Input* input = arg ? (Input*)((char*)arg - 4) : 0;
    int value = input->value;
    p = new FUN_00dd0530(value);
    for (int i = 0; i < input->count; ++i)
        p->AddReferencedObject(input->items[i]);
    v35(p);
    ((hkReferencedObject*)p)->removeReference();
    v47(arg);
}

// 0x00c68d50 uses a virtual Havok-world accessor and a Bethesda pending-entity queue (+0x44), unlike hkpWorld.
struct PhysicsWorldWrapperView
{
    bool UpdateEntity(void* m_pHavokObject);
};
struct Entity35D0
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
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    PhysicsWorldWrapperView* GetWorld() const
    {
        return m_pkWorld;
    }
    PhysicsWorldWrapperView* m_pkWorld;
};
// Gets the owning entity's world, calls UpdateEntity on m_phkObject, invokes OnRemoved, and returns the world's result or false if no world.
// @fnv 0x00d535d0
bool __fastcall RemovePhysicsWorldObject(bhkWorldObject* self, void*)
{
    AutoMemContext kContext(0x10);
    // This unit uses slot +0x94; the shared GetWorld declaration currently occupies +0x98.
    Entity35D0* pkEntity = reinterpret_cast<Entity35D0*(__thiscall*)(bhkWorldObject*)>(
        (*reinterpret_cast<void***>(self))[0x94 / 4])(self);
    PhysicsWorldWrapperView* pkWorld = pkEntity ? pkEntity->GetWorld() : 0;
    if (pkWorld)
    {
        bool bResult = pkWorld->UpdateEntity(self->m_pHavokObject);
        // The derived removal callback at +0xd8 is not declared by the shared base.
        reinterpret_cast<void(__thiscall*)(bhkWorldObject*, PhysicsWorldWrapperView*, int)>(
            (*reinterpret_cast<void***>(self))[0xd8 / 4])(self, pkWorld, 0);
        return bResult;
    }
    return false;
}

typedef signed char hkInt8;
typedef unsigned char hkUint8;

template <typename ENUM, typename STORAGE> struct hkEnumF
{
    STORAGE m_kStorage;

    __forceinline hkEnumF(FinishingFlag)
    {}
    __forceinline operator ENUM() const
    {
        return (ENUM)m_kStorage;
    }
    __forceinline void operator=(ENUM e)
    {
        m_kStorage = (STORAGE)e;
    }
};

template <unsigned int ELEMENTSIZE, unsigned int ALIGNMENT_SIZE>
__forceinline void memCpyOneAligned(void* dst, const void* src)
{
    for (unsigned int i = 0; i < ELEMENTSIZE / 8; i++)
    {
        static_cast<unsigned __int64*>(dst)[i] = static_cast<const unsigned __int64*>(src)[i];
    }
}

struct hkMemoryRouterF
{
    int m_unk00;
    int m_unk04;
    int m_unk08;
    int m_unk0C;
    hkMemoryAllocator* m_pStreamAllocator;

    __forceinline hkMemoryAllocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

__forceinline hkMemoryRouterF* getRouter()
{
    return (hkMemoryRouterF*)hkMemoryRouter_getInstance();
}

template <class T>
static __forceinline void hkArrayF__clearAndDeallocate(hkArrayBase<T>& self, hkMemoryAllocator& alloc);

template <class T>
static __forceinline void hkArrayF_ClearAndRelease(hkArrayBase<T>& self) throw();

template <class T>
static __forceinline void hkArrayF_setDataUserFree(hkArrayBase<T>& self, T* p, int size, int capacity);

template <class T>
static __forceinline void hkArrayF__clearAndDeallocate(hkArrayBase<T>& self, hkMemoryAllocator& alloc)
{
        self.m_iElementCount = 0;
        if ((self.m_iCapacityState & 0x80000000) == 0)
        {
            alloc.bufFree(self.m_data, self.getCapacity() * sizeof(T));
        }
        self.m_data = 0;
        self.m_iCapacityState = 0x80000000;
    }

template <class T>
static __forceinline void hkArrayF_ClearAndRelease(hkArrayBase<T>& self) throw()
{
        hkArrayF__clearAndDeallocate(self, getRouter()->heap());
    }

template <class T>
static __forceinline void hkArrayF_setDataUserFree(hkArrayBase<T>& self, T* p, int size, int capacity)
{
        self.m_data = p;
        self.m_iElementCount = size;
        self.m_iCapacityState = capacity | 0x80000000;
    }

class hkpShapeF : public hkReferencedObject
{
  public:
    unsigned int m_ulUserData;
    int m_type;

    __forceinline hkpShapeF(FinishingFlag flag) : hkReferencedObject(flag)
    {
        if (flag.m_bFinishing)
        {
            m_type = 0;
        }
    }
};

class hkpShapeContainerF
{
  public:
    virtual void unkContainer0();
    virtual int GetNumChildShapes() const;
};

class hkpShapeCollectionF : public hkpShapeF, public hkpShapeContainerF
{
  public:
    enum CollectionType
    {
        COLLECTION_LIST,
        COLLECTION_EXTENDED_MESH,
        COLLECTION_TRISAMPLED_HEIGHTFIELD,
        COLLECTION_USER
    };

    bool m_bDisableWelding;
    hkEnumF<CollectionType, hkUint8> m_eCollectionType;

    __forceinline hkpShapeCollectionF(FinishingFlag flag) : hkpShapeF(flag), m_eCollectionType(flag)
    {
        if (flag.m_bFinishing)
        {
            m_type = 7;
            m_eCollectionType = COLLECTION_USER;
        }
    }
};

enum MaterialIndexStridingType
{
    MATERIAL_INDICES_INVALID,
    MATERIAL_INDICES_INT8,
    MATERIAL_INDICES_INT16
};

struct Subpart
{
    hkEnumF<int, hkInt8> m_type;
    hkEnumF<MaterialIndexStridingType, hkInt8> m_iMaterialIndexType;
    short m_iIndexStriding;
    int m_pVertexBase;
    unsigned short m_iVertexStriding;
    unsigned short m_iNumTriangles;
    int m_pIndexBase;
    unsigned int m_ulUserData;

    __forceinline Subpart(FinishingFlag flag) : m_type(flag), m_iMaterialIndexType(flag)
    {}
};

struct TrianglesSubpart : public Subpart
{
    int m_unk14;
    int m_unk18;
    int m_unk1C;
    int m_unk20;
    int m_unk24;
    int m_unk28;
    int m_unk2C;
    hkVector4 m_kVertexTransform;
    int m_unk40;
    int m_unk44;
    int m_unk48;
    int m_unk4C;
    int m_unk50;
    int m_unk54;
    int m_unk58;
    int m_unk5C;

    __forceinline TrianglesSubpart(FinishingFlag flag) : Subpart(flag)
    {}
};

struct ShapesSubpart : public Subpart
{
    int m_unk14;
    int m_unk18;
    int m_unk1C;
    int m_unk20;
    int m_unk24;
    int m_unk28;
    int m_unk2C;
    int m_unk30;
    int m_unk34;
    int m_unk38;
    int m_unk3C;
};

class FUN_00d56f10 : public hkpShapeCollectionF
{
  public:
    int m_unk18;
    int m_unk1C;
    TrianglesSubpart m_kTrianglesSubpart;
    int m_unk80;
    int m_unk84;
    int m_unk88;
    int m_unk8C;
    int m_unk90;
    int m_unk94;
    int m_unk98;
    int m_unk9C;
    int m_unkA0;
    int m_unkA4;
    int m_unkA8;
    int m_unkAC;
    int m_unkB0;
    hkArrayBase<TrianglesSubpart> m_kTrianglesSubparts;
    hkArrayBase<ShapesSubpart> m_kShapesSubparts;
    int m_unkCC;
    int m_unkD0;
    int m_unkD4;
    int m_unkD8;
    int m_unkDC;
    int m_iFinishingFlag;

    FUN_00d56f10(FinishingFlag flag);
    virtual ~FUN_00d56f10();
};

// Initializes an extended-mesh shape collection, defaulting invalid material index types to INT8 and inlining a single triangle subpart.
// @fnv 0x00d56f10
FUN_00d56f10::FUN_00d56f10(FinishingFlag flag)
    : hkpShapeCollectionF(flag), m_kTrianglesSubpart(flag), m_kTrianglesSubparts(flag), m_kShapesSubparts(flag)
{
    if (flag.m_bFinishing)
    {
        m_eCollectionType = COLLECTION_EXTENDED_MESH;

        for (int i = 0; i < m_kTrianglesSubparts.GetLogicalSize(); i++)
        {
            if (m_kTrianglesSubparts[i].m_iMaterialIndexType == MATERIAL_INDICES_INVALID)
            {
                m_kTrianglesSubparts[i].m_iMaterialIndexType = MATERIAL_INDICES_INT8;
            }
        }
        for (int i = 0; i < m_kShapesSubparts.GetLogicalSize(); i++)
        {
            if (m_kShapesSubparts[i].m_iMaterialIndexType == MATERIAL_INDICES_INVALID)
            {
                m_kShapesSubparts[i].m_iMaterialIndexType = MATERIAL_INDICES_INT8;
            }
        }

        if (m_kTrianglesSubparts.GetLogicalSize() == 1)
        {
            memCpyOneAligned<sizeof(TrianglesSubpart), 16>(&m_kTrianglesSubpart, &m_kTrianglesSubparts[0]);
            hkArrayF_ClearAndRelease(m_kTrianglesSubparts);
            hkArrayF_setDataUserFree(m_kTrianglesSubparts, &m_kTrianglesSubpart, 1, 1);
        }
        if (m_iFinishingFlag == -1)
        {
            m_iFinishingFlag = 0x80000000;
        }
    }
    m_type = 0xe;
}

struct InputBuffer
{
    unsigned int data;
    unsigned int size;
    unsigned int flags;
};
struct ArrayData
{
    unsigned int data;
    unsigned int size;
    unsigned int capacityAndFlags;
};
struct LoadResult
{
    ArrayData primary;
    ArrayData secondary;
    LoadResult()
    {
        primary.data = 0;
        primary.size = 0;
        primary.capacityAndFlags = 0x80000000;
        secondary.data = 0;
        secondary.size = 0;
        secondary.capacityAndFlags = 0x80000000;
    }
    ~LoadResult();
};
void hkGeometryUtility_createConvexGeometry(InputBuffer*, LoadResult*, unsigned int);
// Copies src into a temporary InputBuffer, calls FUN_00d5a630 to fill a LoadResult, then swaps result.primary into dst.
// @fnv 0x00d5a510
void LoadIntoArray(const InputBuffer* src, unsigned int flags, ArrayData* dst)
{
    InputBuffer input;
    input.data = src->data;
    input.size = src->size;
    input.flags = 0x10;
    LoadResult result;
    hkGeometryUtility_createConvexGeometry(&input, &result, flags);
    unsigned int old = dst->data;
    dst->data = result.primary.data;
    result.primary.data = old;
    old = dst->size;
    dst->size = result.primary.size;
    result.primary.size = old;
    old = dst->capacityAndFlags;
    dst->capacityAndFlags = result.primary.capacityAndFlags;
    result.primary.capacityAndFlags = old;
}


// 0x00d47fe0 (DestroyNamedVariantArray) is in blk_00d40000_o2_ehsc_noehsc_variant.cpp: no EH frame in the original.
template <typename T> __forceinline void hkArrayUtil::destruct(T* t, int n, hkTypeIsClass)
{
    for (int i = 0; i < n; i++)
        t[i].~T();
}
template <typename T> __forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& alloc)
{
    hkArrayUtil::destruct(m_data, m_iElementCount, hkTypeIsClass());
    m_iElementCount = 0;
    if ((m_iCapacityState & DONT_DEALLOCATE_FLAG) == 0)
        alloc.bufFree(m_data, getCapacity() * sizeof(T));
    m_data = 0;
    m_iCapacityState = DONT_DEALLOCATE_FLAG;
}


struct C
{
    C();
    volatile unsigned short f00;
    short unk02;
    int unk04;
    int unk08;
    int unk0c;
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
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    volatile unsigned short f90;
    volatile bool f92;
    char unk93;
    volatile unsigned short f94;
    volatile unsigned short f96;
    int unk98;
    int unk9c;
    volatile unsigned short fa0;
    bool fa2;
    char unka3;
    int unka4;
    volatile unsigned short fa8;
    short unkaa;
    volatile unsigned short fac;
    short unkae;
    volatile unsigned short fb0;
    short unkb2;
    volatile unsigned short fb4;
};
// Constructor for C that initializes f00, f90, f92, f94, f96, fa0, fa2, fa8, fac, fb0, and fb4 to fixed values.
// @fnv 0x00d4ff60
C::C() : f00(2), f90(0xb), f92(1), f94(0), f96(0), fa0(0xa), fa2(1), fa8(0xd), fac(7), fb0(7), fb4(9)
{}

struct FnvCpu_FUN_00d541b0_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    LocalM128 field20;
    LocalM128 field30;
    void InitializeFields_00d541b0(hkVector4* input0, hkVector4* input1);
};
// Copies input0 into field20 and input1 into field30.
// @fnv 0x00d541b0
// src: GUESS 0x00d541b0 (confidence: low)
void FnvCpu_FUN_00d541b0_CpuObject::InitializeFields_00d541b0(hkVector4* input0, hkVector4* input1)
{
    this->field20 = input0->m_vComponents;
    this->field30 = input1->m_vComponents;
}

// @fnv 0x00d54e40
void hkVector4::operator=(const hkVector4& vector)
{
    m_vComponents = vector.m_vComponents;
}

// sub ecx,0x10; jmp FUN_00d57120
// MSVC adjustor thunk: a class derives from two bases that both declare the same
// virtual, so the secondary base's vtable entry is an adjustor thunk that moves
// `this` back by the size of the primary base (0x10 = vptr + three int fields).
struct PrimaryBase
{
    virtual void FUN_00d57110();
    int unk04;
    int unk08;
    int unk0C;
};

struct SecondaryBase
{
    virtual void FUN_00d57110();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d57110
    virtual void FUN_00d57110();
};

Derived::Derived()
{}

// Constraint vectors at +0x10 and command array at +0x1c distinguish this from the 16-byte include/Data.h.
struct ConstraintCommandStorage
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkArray<hkVector4> vectors;
    hkArray<int> commands;
};
struct OwnerS
{
    int unk00;
    ConstraintCommandStorage* data;
    int unk08;
    int unk0c;
    char unk10;
    char unk11;
    char unk12;
    unsigned char flags[5];
    int AppendVectorCommandAndSetFlag(const hkVector4& value, int index);
};
// Appends command 4 and index to commands, adds value to vectors, and sets flags[index] to 1.
// @fnv 0x00d51970
// src: GUESS 0x00d51970 (confidence: medium)
int OwnerS::AppendVectorCommandAndSetFlag(const hkVector4& value, int index)
{
    d51::AddBack(data->commands, 4);
    d51::AddBack(data->commands, index);
    int result = data->vectors.m_iElementCount;
    d51::AddBack(data->vectors, value);
    flags[index] = 1;
    return result;
}

struct S
{
    char pad[2];
    char val;
};

extern "C" void __cdecl ReleaseAllEntries(S* a, int b, int c);

// @fnv 0x00d409b0
// src: HAVOK_LIB 0x00d409b0
static __declspec(noinline) void resetGskManifold(S* dst, S* src, int b, int c)
{
    ReleaseAllEntries(src, b, c);
    dst->val = src->val;
}

volatile S* g_dst;
volatile S* g_src;
volatile int g_b;
volatile int g_c;

void caller()
{
    resetGskManifold((S*)g_dst, (S*)g_src, g_b, g_c);
}

struct FUN_00d46d40_s
{
    const char* FUN_00d46d40() throw();
};

class RefPtrD482
{
  public:
    hkReferencedObject* m_pRetainedObject;

    RefPtrD482() throw()
    {}
    RefPtrD482(hkReferencedObject* pkObject) throw() : m_pRetainedObject(pkObject)
    {}
    ~RefPtrD482() throw()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
    }
    void operator=(const RefPtrD482& rp) throw()
    {
        if (this != &rp)
        {
            hkReferencedObject* pkNew = rp.m_pRetainedObject;
            if (pkNew)
                pkNew->addReference();
            if (m_pRetainedObject)
                m_pRetainedObject->removeReference();
            m_pRetainedObject = pkNew;
        }
    }
    FUN_00d46d40_s* hkRefVariant_getClass() const throw();
    void AssignObject(int iParam) throw();
};

class FUN_00d48250
{
  public:
    hkStringPtr m_name;
    hkStringPtr m_pClassName;
    RefPtrD482 m_object;

    FUN_00d48250(const char* pcName, int iParam) throw();
};

// Stores pcName in m_name, builds a ref-counted object via FUN_00d47750(iParam) into m_object, and sets m_pClassName from FUN_00d46d40 if available.
// @fnv 0x00d48250
FUN_00d48250::FUN_00d48250(const char* pcName, int iParam) throw() : m_object(0)
{
    m_name = pcName;
    {
        RefPtrD482 spTemp;
        spTemp.AssignObject(iParam);
        m_object = spTemp;
    }
    m_pClassName = m_object.hkRefVariant_getClass() ? m_object.hkRefVariant_getClass()->FUN_00d46d40() : 0;
}

namespace SpringSimd {
// Exe 0x00d48fc0 FUN_00d48fc0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) {
    struct { float x, y, z, w; };
    float m128_f32[4];
} __m128, LocalM128;
extern "C" LocalM128 _mm_setzero_ps(void);
extern "C" void _mm_store_ps(float*, LocalM128);
}
struct S_00d4f0f0_B1
{
    virtual void v0();
    short unk04;
    short unk06;
    __forceinline S_00d4f0f0_B1()
    {
        unk06 = 1;
    }
};
struct S_00d4f0f0_B2 : S_00d4f0f0_B1
{
    int unk08;
    int unk0c;
    __forceinline S_00d4f0f0_B2()
    {
        unk08 = 0;
    }
};
struct S_00d4f0f0_H
{
    short unk10;
    __forceinline S_00d4f0f0_H() : unk10(3)
    {}
};
struct S_00d4f0f0_S
{
    short unk40;
    __forceinline S_00d4f0f0_S() : unk40(6)
    {}
};
struct FUN_00d4f0f0 : S_00d4f0f0_B2
{
    S_00d4f0f0_H h;
    int unk14;
    int unk18;
    int unk1c;
    hkVector4 unk20;
    hkVector4 unk30;
    S_00d4f0f0_S s;
    float unk44;
    FUN_00d4f0f0();
    virtual void v0();
};

// Constructor for FUN_00d4f0f0 that zero-initializes unk44 and the two hkVector4 fields unk20 and unk30.
// @fnv 0x00d4f0f0
FUN_00d4f0f0::FUN_00d4f0f0()
{
    unk44 = 0.0f;
    SpringSimd::_mm_store_ps(unk20.m_vComponents.m128_f32, SpringSimd::_mm_setzero_ps());
    SpringSimd::_mm_store_ps(unk30.m_vComponents.m128_f32, SpringSimd::_mm_setzero_ps());
}

namespace D4F2A0Simd {
// Exe 0x00d48fc0 FUN_00d48fc0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) {
    struct { float x, y, z, w; };
} __m128, LocalM128;
extern "C" LocalM128 _mm_setzero_ps();
extern "C" void _mm_store_ps(float*, LocalM128);
}


// Retained: shared hkBaseObject/hkReferencedObject/hkpConstraintData add an aligned constructor frame at 0x00d4f2a0 (310 bytes vs 294).
struct hkBaseObjectS
{
    virtual void unk00();
};

struct hkReferencedObjectS : hkBaseObjectS
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkReferencedObjectS() : m_sReferenceCount(1)
    {}
};

struct hkpConstraintDataS : hkReferencedObjectS
{
    unsigned int m_ulUserData;
    hkpConstraintDataS() : m_ulUserData(0)
    {}
};

inline void setZero4(hkVector4& v)
{
    D4F2A0Simd::_mm_store_ps(&v.x, D4F2A0Simd::_mm_setzero_ps());
}

__forceinline hkRotation::hkRotation() {}
inline void hkRotation::setIdentity()
{
    setZero4(m_kColumn0);
    setZero4(m_kColumn1);
    setZero4(m_kColumn2);
    m_kColumn0.x = 1.0f;
    m_kColumn1.y = 1.0f;
    m_kColumn2.z = 1.0f;
}

struct hkpSetLocalRotationsAtomS
{
    unsigned short m_type;
    hkRotation m_kRotationA;
    hkRotation m_kRotationB;
    hkpSetLocalRotationsAtomS()
    {
        m_type = 4;
    }
};

struct hkpTwistLimitAtomS
{
    unsigned short m_type;
    unsigned char m_bLimitEnabled;
    unsigned char m_ucTwistAxis;
    unsigned char m_ucReferenceAxis;
    float m_fMinAngle;
    float m_fMaxAngle;
    float m_fAngularLimitsTauFactor;
    hkpTwistLimitAtomS()
    {
        m_type = 0xf;
        m_bLimitEnabled = 1;
    }
};

struct hkpConeLimitAtomS
{
    unsigned short m_type;
    unsigned char m_bLimitEnabled;
    unsigned char m_ucMemOffsetToAngleOffset;
    unsigned char m_ucMemOffsetToOldAngleOffset;
    unsigned char m_ucMemOffsetToFirstConstrainedDof;
    unsigned char m_ucAngleMeasurementMode;
    float m_fMinAngle;
    float m_fMaxAngle;
    float m_fAngularLimitsTauFactor;
    hkpConeLimitAtomS()
    {
        m_type = 0x10;
        m_bLimitEnabled = 1;
        m_ucAngleMeasurementMode = 0;
    }
};

struct hkpRagdollAtomsS
{
    hkpSetLocalRotationsAtomS m_kLocalRotations;
    hkpTwistLimitAtomS m_kTwistLimit;
    hkpConeLimitAtomS m_kConeLimit;
    hkpConeLimitAtomS m_kPlaneLimit;
    hkpRagdollAtomsS()
    {}
};

struct hkpRagdollDataS : hkpConstraintDataS
{
    void setConeStab(hkBool b);
};

struct FUN_00d4f2a0 : hkpRagdollDataS
{
    hkpRagdollAtomsS m_kBridgeAtoms;
    FUN_00d4f2a0();
    virtual ~FUN_00d4f2a0();
};

__declspec(noinline) void hkpRagdollDataS::setConeStab(hkBool b)
{
    static_cast<FUN_00d4f2a0*>(this)->m_kBridgeAtoms.m_kConeLimit.m_ucAngleMeasurementMode = b.m_cBooleanValue ? 16 : 0;
}

// Initializes bridge ragdoll atoms with identity rotations, twist limits of +/-0.5236 rad, cone limits, and plane limits with tau factor 0.8.
// @fnv 0x00d4f2a0
FUN_00d4f2a0::FUN_00d4f2a0()
{
    m_kBridgeAtoms.m_kLocalRotations.m_kRotationA.setIdentity();
    m_kBridgeAtoms.m_kLocalRotations.m_kRotationB.setIdentity();

    m_kBridgeAtoms.m_kTwistLimit.m_ucTwistAxis = 0;
    m_kBridgeAtoms.m_kTwistLimit.m_ucReferenceAxis = 1;
    m_kBridgeAtoms.m_kTwistLimit.m_fMinAngle = -0.5236f;
    m_kBridgeAtoms.m_kTwistLimit.m_fMaxAngle = 0.5236f;
    m_kBridgeAtoms.m_kTwistLimit.m_fAngularLimitsTauFactor = 0.8f;

    m_kBridgeAtoms.m_kConeLimit.m_ucMemOffsetToAngleOffset = 0;
    m_kBridgeAtoms.m_kConeLimit.m_ucMemOffsetToOldAngleOffset = 0;
    m_kBridgeAtoms.m_kConeLimit.m_ucMemOffsetToFirstConstrainedDof = 0;
    m_kBridgeAtoms.m_kConeLimit.m_fMinAngle = -100.0f;
    m_kBridgeAtoms.m_kConeLimit.m_fMaxAngle = 1.0f;
    m_kBridgeAtoms.m_kConeLimit.m_fAngularLimitsTauFactor = 0.8f;
    setConeStab(true);

    m_kBridgeAtoms.m_kPlaneLimit.m_ucMemOffsetToAngleOffset = 0;
    m_kBridgeAtoms.m_kPlaneLimit.m_ucMemOffsetToOldAngleOffset = 1;
    m_kBridgeAtoms.m_kPlaneLimit.m_ucMemOffsetToFirstConstrainedDof = 1;
    m_kBridgeAtoms.m_kPlaneLimit.m_fMinAngle = -0.025f;
    m_kBridgeAtoms.m_kPlaneLimit.m_fMaxAngle = 0.025f;
    m_kBridgeAtoms.m_kPlaneLimit.m_fAngularLimitsTauFactor = 0.8f;
}

extern int DAT_010d0be4;
extern float DAT_0106b648;
extern float DAT_0102b3c8;

namespace HingeLimitsD52FC0Detail {
struct Matrix
{
    float m00, m01, m02, m03;
    float m10, m11, m12, m13;
    float m20, m21, m22, m23;
    __forceinline void setZero()
    {
        ::D4F2A0Simd::_mm_store_ps(&m00, ::D4F2A0Simd::_mm_setzero_ps());
        ::D4F2A0Simd::_mm_store_ps(&m10, ::D4F2A0Simd::_mm_setzero_ps());
        ::D4F2A0Simd::_mm_store_ps(&m20, ::D4F2A0Simd::_mm_setzero_ps());
    }
    __forceinline void setDiagonal(float x, float y, float z)
    {
        setZero();
        m00 = x;
        m11 = y;
        m22 = z;
    }
    __forceinline void setIdentity()
    {
        setDiagonal(1.0f, 1.0f, 1.0f);
    }
};
}

class FUN_00d52fc0
{
  public:
    int* m_vptr;
    unsigned short unk04;
    unsigned short m_06;
    unsigned int m_08;
    unsigned int unk0c;
    unsigned short m_10;
    unsigned short unk12;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    HingeLimitsD52FC0Detail::Matrix m_20;
    HingeLimitsD52FC0Detail::Matrix m_50;
    volatile unsigned short m_80;
    volatile unsigned char m_82;
    unsigned char m_83;
    float m_84;
    float m_88;
    float m_8C;
    unsigned short m_90;
    unsigned char m_92;

    FUN_00d52fc0();
};

// Constructor: sets the vptr, several small integer fields, two identity matrices, and three floats (two from globals, one 1.0).
// @fnv 0x00d52fc0
FUN_00d52fc0::FUN_00d52fc0()
{
    m_vptr = &DAT_010d0be4;
    m_06 = 1;
    m_08 = 0;
    m_10 = 4;
    m_82 = 1;
    m_80 = 0xe;
    m_90 = 0xc;
    m_20.setIdentity();
    m_50.setIdentity();
    m_92 = 0;
    m_84 = DAT_0106b648;
    m_83 = 0;
    m_88 = DAT_0102b3c8;
    m_8C = 1.0f;
}

extern int DAT_010d0cd4;
extern float DAT_0104da48;
struct FUN_00ca9360_sub
{
    void __fastcall FindFloatTableIndex(int count, float* value);
};
struct FUN_00d54290
{
    void* volatile m_vptr;
    unsigned short m_unk04;
    unsigned short m_word06;
    int m_value08;
    int m_unk0c;
    volatile unsigned short m_word10;
    unsigned short m_unk12;
    int m_unk14;
    int m_unk18;
    int m_unk1c;
    hkVector4 m_zero20;
    hkVector4 m_zero30;
    unsigned short m_word40;
    volatile unsigned char m_byte42;
    FUN_00ca9360_sub m_data43;
    volatile float m_float44;
    FUN_00d54290();
};
// Initializes a FUN_00d54290 object, setting m_word06 to 1, m_word10 to 3, m_word40 to 5, and calling m_data43.FUN_00ca9360(5, &one).
// @fnv 0x00d54290
FUN_00d54290::FUN_00d54290()
{
    float one = 1.0f;
    m_word06 = 1;
    m_value08 = 0;
    m_vptr = &DAT_010d0cd4;
    m_word10 = 3;
    m_byte42 = 0;
    m_word40 = 5;
    m_data43.FindFloatTableIndex(5, &one);
    m_float44 = DAT_0104da48;
    ::D4F2A0Simd::_mm_store_ps((float*)&m_zero20, ::D4F2A0Simd::_mm_setzero_ps());
    ::D4F2A0Simd::_mm_store_ps((float*)&m_zero30, ::D4F2A0Simd::_mm_setzero_ps());
}

extern "C" ::D4F2A0Simd::LocalM128 _mm_setr_ps(float x, float y, float z, float w);

static const float DAT_010181bc = 0.05f;
static const float DAT_01011d78 = 0.0f;
static const float DAT_01017870 = 0.3f;
static const float DAT_010231a8 = 0.4f;
static const float DAT_0101e2bc = 0.1f;

static inline char& MoppInputSetBool(char& rcBool, bool b)
{
    rcBool = static_cast<char>(b);
    return rcBool;
}

struct FUN_00d54de0
{
    FUN_00d54de0();

    ::hkVector4 m_vector;
    float m_value10;
    float m_value14;
    float m_value18;
    char m_flag1C;
    char m_flag1D;
    char m_flag1E;
    char m_flag1F;
    char m_flag20;
};

// Initializes a FUN_00d54de0 with default vector, scalar values, and boolean flags.
// @fnv 0x00d54de0
FUN_00d54de0::FUN_00d54de0()
{
    m_value18 = DAT_01017870;
    m_value10 = DAT_010231a8;
    m_value14 = DAT_0101e2bc;
    ::D4F2A0Simd::_mm_store_ps(&m_vector.x, _mm_setr_ps(DAT_010181bc, DAT_010181bc, DAT_010181bc, DAT_01011d78));
    MoppInputSetBool(m_flag1C, true);
    MoppInputSetBool(m_flag1D, true);
    MoppInputSetBool(m_flag1F, true);
    MoppInputSetBool(m_flag20, false);
    MoppInputSetBool(m_flag1E, false);
}
