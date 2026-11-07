// ProcessInput_hkpconvexlistagent3: local type (was include/ProcessInput.h, which had no evidence of one real class); no method of it is bound to a named game function
#include "../../../../../../include/Transform.h"
#include "../../../../../../include/hkpCdBody.h"

class CollisionInput;
class Manager;
class Context;

class ProcessInput_hkpconvexlistagent3
{
public:
    hkpCdBody* bodyA;
    hkpCdBody* bodyB;
    int unk08;
    CollisionInput* input;
    Manager* manager;
    int unk14;
    int unk18;
    int unk1c;
    __declspec(align(16)) Transform transform;
    int extra60;
    int extra64;
    int extra68;
    int extra6c;
    int extra70;
    int extra74;
    int extra78;
    int extra7c;

    void FUN_00d33260(Context*);
    float getTolerance() const;
};
#include "../../../../../../include/hkTransform.h"
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkpShape.h"
#include "../../../../../../include/hkpShapeContainer.h"
#include "../../../../../../include/hkpConvexListShape.h"
#include "../../../../../../include/hkpCdBody.h"
#include "../../../../../../include/hkpCollidable.h"
#include "../../../../../../include/hkContactPoint.h"
#include "../../../../../../include/hkpCollisionDispatcher.h"

inline hkpCdBody::hkpCdBody() {}
inline hkpShapeType hkpShape::getType() const
{
    return reinterpret_cast<const hkpShapeType&>(m_type);
}

inline hkpCollisionDispatcher::Agent3FunctionTable::Agent3FunctionTable()
{
    m_bIsPredictive = false;
    m_bAgentFlag1 = false;
    m_bAgentFlag2 = false;
    m_pUpdateFilterFunc = 0;
    m_pCalcStats = 0;
    m_pAgentFunction10 = 0;
    m_pAgentFunction11 = 0;
    m_pAgentFunction7 = 0;
}

// src/havok/physics/collide/agent3/convexlist3/hkpconvexlistagent3.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent3/convexlist3/hkpconvexlistagent3.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

void __cdecl hkpAgent1nSector_ProcessEntries_00da3510(void* a, void* b);

// @fnv 0x00d32b20
void __cdecl CallIfNotFlagged(int aiUnused, int pObject, int c)
{
    if (!(*(char*)(pObject + 0xb) & 0x20))
        hkpAgent1nSector_ProcessEntries_00da3510((void*)(pObject + 0x10), (void*)c);
}

void __cdecl SetFlagAndCall(int, int, int);
void __cdecl hkConvexListAgent3_process(int, int, int);
void __cdecl Object_ProcessAndReturnValue_00d32ca0(int, int, int);
void __cdecl Hkpconvexlistagent3_ForwardCall_00d32bd0(int, int, int);
void __cdecl Object_UpdateFields_00d32be0(int, int, int);
void __cdecl Object_UpdateFields_00d32c00(int, int, int);
void __cdecl Object_ProcessState_00d32c20(int, int, int);
void __cdecl hkConvexListAgent3_updateFilter(int, int, int);
void __cdecl hkConvexListAgent3_calcStatistics(int, int, int);
void __cdecl hkConvexListAgent3_warpTime(int, int, int);
void __cdecl hkConvexListAgent3_destroy(int, int, int);
// Installs the convex-list callbacks and marks the agent as predictive.
// @fnv 0x00d33140
// src: HAVOK_LIB 0x00d33140
void __cdecl hkConvexListAgent3_initAgentFunc(hkpCollisionDispatcher::Agent3FunctionTable& kFuncs)
{
    hkpCollisionDispatcher::Agent3FunctionTable* p = &kFuncs;
    p->m_pCreateFunc = reinterpret_cast<hkAgent3::CreateFunc>(&SetFlagAndCall);
    p->m_pAgentFunction8 = reinterpret_cast<hkAgent3::ProcessFunc>(&hkConvexListAgent3_process);
    p->m_pAgentFunction7 = reinterpret_cast<hkAgent3::SepNormalFunc>(&Object_ProcessAndReturnValue_00d32ca0);
    p->m_pAgentFunction3 = reinterpret_cast<hkAgent3::CleanupFunc>(&Hkpconvexlistagent3_ForwardCall_00d32bd0);
    p->m_pAgentFunction4 = reinterpret_cast<hkAgent3::RemovePointFunc>(&Object_UpdateFields_00d32be0);
    p->m_pAgentFunction5 = reinterpret_cast<hkAgent3::CommitPotentialFunc>(&Object_UpdateFields_00d32c00);
    p->m_pCreateZombieFunc = reinterpret_cast<hkAgent3::CreateZombieFunc>(&Object_ProcessState_00d32c20);
    p->m_pUpdateFilterFunc = reinterpret_cast<hkAgent3::UpdateFilterFunc>(&hkConvexListAgent3_updateFilter);
    p->m_pCalcStats = reinterpret_cast<hkAgent3::CalcStatisticsFunc>(&hkConvexListAgent3_calcStatistics);
    p->m_pAgentFunction10 = reinterpret_cast<hkAgent3::InvalidateTimFunc>(&CallIfNotFlagged);
    p->m_pAgentFunction11 = reinterpret_cast<hkAgent3::WarpTimeFunc>(&hkConvexListAgent3_warpTime);
    p->m_pAgent3DestroyFuncs = reinterpret_cast<hkAgent3::DestroyFunc>(&hkConvexListAgent3_destroy);
    p->m_bIsPredictive = true;
}

struct FUN_00d32ae0_agent
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6(const char*);
    virtual void f7();
};

void __cdecl hkpAgentMachineUtil_calc1nStatistics(void*, void*, void*);

// If the flag at offset 0x0b of b is clear, calls f6 with "hkConvexListAgent3", FUN_00d97250 on b+0x10, then f7 on the agent.
// @fnv 0x00d32ae0
// src: HAVOK_LIB 0x00d32ae0
void __cdecl hkConvexListAgent3_calcStatistics(int aiUnused, int b, int c)
{
    if (reinterpret_cast<unsigned char*>(b)[0x0b] & 0x20)
        return;

    FUN_00d32ae0_agent* agent = *reinterpret_cast<FUN_00d32ae0_agent**>(reinterpret_cast<char*>(&c) + 4);

    agent->f6("hkConvexListAgent3");
    hkpAgentMachineUtil_calc1nStatistics(reinterpret_cast<char*>(b) + 0x10, reinterpret_cast<void*>(c), agent);
    agent->f7();
}

void __cdecl _FUN_00da35f0(void*, float, float, int);

// If the object's byte at offset 0xb lacks flag 0x20, forwards its fields at +0x10 plus three stack arguments to _FUN_00da35f0.
// @fnv 0x00d32b40
// src: HAVOK_LIB 0x00d32b40
void __cdecl hkConvexListAgent3_warpTime(int aiUnused, int aiArg1, int aiArg2)
{
    struct StackArguments
    {
        void* object;
        float first;
        float second;
        int third;
    };

    StackArguments* pStackArgs = reinterpret_cast<StackArguments*>(&aiArg1);
    if (!(reinterpret_cast<unsigned char*>(pStackArgs->object)[0xb] & 0x20))
    {
        _FUN_00da35f0(reinterpret_cast<unsigned char*>(pStackArgs->object) + 0x10, pStackArgs->first,
                      pStackArgs->second, pStackArgs->third);
    }
}

void __cdecl DispatchInputRecord(int a, int b, void* c);

// Calls DispatchInputRecord with a, b and c, then sets bit 0x20 and clears bit 0x40 in byte 0xb of c.
// @fnv 0x00d32b70
void __cdecl SetFlagAndCall(int aiArg1, int aiArg2, int c)
{
    char* p = (char*)c;
    DispatchInputRecord(aiArg1, aiArg2, p);
    p[0xb] = (p[0xb] & 0xbf) | 0x20;
}

void __cdecl RemoveEntryById(void);

// @fnv 0x00d32be0
// src: GUESS 0x00d32be0 (confidence: low)
void __cdecl Object_UpdateFields_00d32be0(int, int apObject, int)
{
    if ((reinterpret_cast<unsigned char*>(apObject)[0x0b] & 0x20) != 0)
    {
        *reinterpret_cast<volatile int*>(&apObject) = apObject;
        RemoveEntryById();
    }
}

void __cdecl InsertSlotId(void);

// @fnv 0x00d32c00
// src: GUESS 0x00d32c00 (confidence: low)
void __cdecl Object_UpdateFields_00d32c00(int aiUnused, int apObject, int aiUnused2)
{
    if ((reinterpret_cast<unsigned char*>(apObject)[0x0b] & 0x20) != 0)
    {
        *(volatile int*)&apObject = apObject;
        InsertSlotId();
    }
}

void __cdecl FindEntryByKey(int, int, int);

// @fnv 0x00d32c20
// src: GUESS 0x00d32c20 (confidence: low)
void __cdecl Object_ProcessState_00d32c20(int aiArg1, int apArg2, int aiArg3)
{
    if ((reinterpret_cast<unsigned char*>(apArg2)[0x0b] & 0x20) != 0)
        FindEntryByKey(aiArg1, apArg2, aiArg3);
}

struct PackTarget
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
};

struct FUN_00d33210_cls
{
    int unk00;
    int unk04;
    int unk08;
    PackTarget* m_0c;
    void hkpMapPointsToSubShapeContactMgr_cleanup();
};

// @fnv 0x00d33210
// src: HAVOK_LIB 0x00d33210
void FUN_00d33210_cls::hkpMapPointsToSubShapeContactMgr_cleanup()
{
    m_0c->v24();
}

// FUN_00d33220 (0x00d33220, 10 bytes)
//
//	8b 49 0c        mov ecx, dword ptr [ecx+0xc]
//	8b 01           mov eax, dword ptr [ecx]
//	8b 40 10        mov eax, dword ptr [eax+0x10]
//	ff e0           jmp eax
//
// A __thiscall member of a wrapper class: it loads the polymorphic
// sub-object pointer at +0xc, then tail-jumps to the sub-object's
// virtual at vtable offset 0x10 (the fifth virtual), forwarding the
// incoming 4-byte stack argument in place (that is what puts the jump
// target in EAX instead of EDX).

struct Sub_d33220
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(int);
};

struct Own_d33220
{
    int unk00;
    int unk04;
    int unk08;
    Sub_d33220* unk0c;
    void hkpMapPointsToSubShapeContactMgr_reserveContactPointsImpl(int);
};

// @fnv 0x00d33220
// src: HAVOK_LIB 0x00d33220
void Own_d33220::hkpMapPointsToSubShapeContactMgr_reserveContactPointsImpl(int a)
{
    unk0c->v4(a);
}

struct FnvCpu_FUN_00d33230_CpuInterface
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void Invoke(int arg0);
};
struct FnvCpu_FUN_00d33230_CpuOwner
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    FnvCpu_FUN_00d33230_CpuInterface* target;
    void hkpMapPointsToSubShapeContactMgr_removeContactPointImpl(int arg0);
};
// @fnv 0x00d33230
// src: HAVOK_LIB 0x00d33230
void FnvCpu_FUN_00d33230_CpuOwner::hkpMapPointsToSubShapeContactMgr_removeContactPointImpl(int arg0)
{
    target->Invoke(arg0);
}

struct Target
{
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0c();
    virtual void vfn10();
    virtual void vfn14();
    virtual void vfn18(int a);
};

struct Self
{
    int unk00;
    int unk04;
    int unk08;
    Target* unk0c;
};

// @fnv 0x00d33240
// src: HAVOK_LIB 0x00d33240
void __fastcall hkpMapPointsToSubShapeContactMgr_processContactImpl(Self* self, int unused, int arg)
{
    self->unk0c->vfn18(arg);
}

struct FnvCpu_FUN_00d33250_CpuInterface
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void Invoke(int arg0);
};
struct FnvCpu_FUN_00d33250_CpuOwner
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    FnvCpu_FUN_00d33250_CpuInterface* target;
    void hkpMapPointsToSubShapeContactMgr_removeToiImpl(int arg0);
};
// @fnv 0x00d33250
// src: HAVOK_LIB 0x00d33250
void FnvCpu_FUN_00d33250_CpuOwner::hkpMapPointsToSubShapeContactMgr_removeToiImpl(int arg0)
{
    target->Invoke(arg0);
}

struct TargetInterface
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual int slot10();
};

struct Arg3
{
    TargetInterface* target;
};

struct Arg1
{
    int unk00;
    int unk04;
    short unk08;
    char unk0a;
    unsigned char flags;
    int unk0c;
    int field_10;
};

struct EventData
{
    int m00;
    Arg3* m04;
    int m08;
    int m0c;
    int m10;
    int m14;
    int m18;
    int m1c;
};

void __cdecl hkAgent1nMachine_UpdateShapeCollectionFilter(void*, void*);

// @fnv 0x00d32c40
// src: HAVOK_LIB 0x00d32c40
void __cdecl hkConvexListAgent3_updateFilter(int aiUnused, Arg1* a1, int a2, Arg3* a3, int aiArg4, int aiArg5, int aiArg6)
{
    if (a1->flags & 0x20)
    {
        return;
    }
    int iSlotResult;
    iSlotResult = a3->target->slot10();
    EventData j;
    j.m00 = a2;
    j.m04 = a3;
    j.m10 = aiArg4;
    j.m14 = aiArg5;
    j.m18 = aiArg6;
    j.m0c = iSlotResult;
    hkAgent1nMachine_UpdateShapeCollectionFilter(&a1->field_10, &j);
}

// The shared hkpGskCache header is not available yet; retain the accessed cache fields here.
struct hkpGskCache
{
    unsigned short m_kVertices[4];
    unsigned char m_ucDimensionA;
    unsigned char m_ucDimensionB;
};

struct __declspec(align(16)) hkpShapeBuffer
{
    unsigned int m_buffer[128];
};

class hkpChildProcessorD333
{
  public:
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual int process(const hkpCdBody& kBodyA, const hkpCdBody& kBodyB, const void* pvInput,
                        const void* pvTransform, hkpGskCache* pkCache, void* pvOutput) throw();
};

class hkpConvexListProcessorD333
{
  public:
    int m_00;
    int m_04;
    int m_08;
    hkpChildProcessorD333* m_processor;
    bool m_invalidCache;

    int ProcessConvexListChildren(const hkpCdBody& kBodyA, const hkpCdBody& kBodyB, const void* pvInput,
                                  const void* pvTransform, hkpGskCache* pkCache, void* pvOutput) throw();
};

// Resolves convex-list child shapes for both bodies from the cache keys, flags an invalid cache on mismatch, and delegates to m_processor->process.
// @fnv 0x00d33390
int hkpConvexListProcessorD333::ProcessConvexListChildren(const hkpCdBody& kBodyA, const hkpCdBody& kBodyB,
                                                          const void* pvInput, const void* pvTransform,
                                                          hkpGskCache* pkCache, void* pvOutput) throw()
{
    hkpShapeBuffer kBuffer;
    const hkpCdBody* pkBodyA = &kBodyA;
    const hkpCdBody* pkBodyB = &kBodyB;
    hkpCdBody kChildA;
    hkpCdBody kChildB;

    if (kBodyA.m_pCollisionShape->getType() == 0x16)
    {
        int iKey = pkCache->m_kVertices[0] >> 8;
        for (int i = 1; i < pkCache->m_ucDimensionA; i++)
        {
            if ((pkCache->m_kVertices[i] >> 8) != iKey)
            {
                m_invalidCache = true;
                return 0xffff;
            }
        }
        const hkpShape* pkChild = static_cast<const hkpConvexListShape*>(kBodyA.m_pCollisionShape)
                                          ->GetShapeForKey(iKey, kBuffer);
        kChildA.m_uiCollisionShapeKey = iKey;
        kChildA.m_parent = &kBodyA;
        kChildA.m_pMotionState = kBodyA.m_pMotionState;
        kChildA.m_pCollisionShape = pkChild;
        pkBodyA = &kChildA;
    }
    if (kBodyB.m_pCollisionShape->getType() == 0x16)
    {
        int iKey = pkCache->m_kVertices[pkCache->m_ucDimensionA] >> 8;
        for (int i = pkCache->m_ucDimensionA + 1; i < pkCache->m_ucDimensionA + pkCache->m_ucDimensionB; i++)
        {
            if ((pkCache->m_kVertices[i] >> 8) != iKey)
            {
                m_invalidCache = true;
                return 0xffff;
            }
        }
        const hkpShape* pkChild = static_cast<const hkpConvexListShape*>(kBodyB.m_pCollisionShape)
                                          ->GetShapeForKey(iKey, kBuffer);
        kChildB.m_parent = &kBodyB;
        kChildB.m_pMotionState = kBodyB.m_pMotionState;
        kChildB.m_pCollisionShape = pkChild;
        kChildB.m_uiCollisionShapeKey = iKey;
        pkBodyB = &kChildB;
    }
    return m_processor->process(*pkBodyA, *pkBodyB, pvInput, pvTransform, pkCache, pvOutput);
}

struct ValueBlock
{
    void CopyMemory_00d33330(ValueBlock* destination);
};

struct Callback
{
    virtual void Reserved00();
    virtual void Reserved04();
    virtual void Reserved08();
    virtual void Reserved0c();
    virtual void Reserved10();
    virtual void Reserved14();
    virtual void Reserved18();
    virtual void Reserved1c();
    virtual void OnValueChange(unsigned int identifier, void* data);
};

void __cdecl FUN_00ec44d0(void* target, const void* input, unsigned int byteCount);

struct Container
{
    unsigned int tag;
    void hkpProcessCollisionOutputBackup_rollbackOutput(void* unusedA, void* unusedB, char* source, Callback* callback);
};

// Compares the source's time field with this object's, notifies the callback and copies the value block on change, then copies the tag and payload.
// @fnv 0x00d33600
// src: HAVOK_LIB 0x00d33600
void Container::hkpProcessCollisionOutputBackup_rollbackOutput(void* unusedA, void* unusedB, char* source, Callback* callback)
{
    float sourceTime = *reinterpret_cast<float*>(source + 0x3030);
    char* destination = reinterpret_cast<char*>(this);

    if (sourceTime != *reinterpret_cast<float*>(destination + 0x1030))
    {
        callback->OnValueChange(*reinterpret_cast<unsigned int*>(source + 4), source + 0x3050);
        reinterpret_cast<ValueBlock*>(source + 0x3010)
            ->CopyMemory_00d33330(reinterpret_cast<ValueBlock*>(destination + 0x1010));
    }

    *reinterpret_cast<unsigned int*>(source) = tag;
    void* output = *reinterpret_cast<void**>(source + 0x3080);
    if (output != 0)
    {
        FUN_00ec44d0(output, destination + 4, 0x1008);
    }
}

// Agent flags at +0x0b and cache data at +0x10 identify an agent record, not a polymorphic hkpShape.
struct ConvexListAgentRecord
{
    int unk00;
    int unk04;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0A;
    unsigned char m_flags;
    int unk0C;
    int m_data;
};

void __cdecl ForwardToTarget(void* agent, ConvexListAgentRecord* shape, void* input, void* output, void* collector);
void __cdecl hkAgent1nMachine_Destroy(int* data, void* collector, void* input, void* output);

// If the ConvexListAgentRecord flag 0x20 is set, forward the call to ForwardToTarget; otherwise call FUN_00da42b0 with the shape data.
// @fnv 0x00d32ba0
// src: HAVOK_LIB 0x00d32ba0
void __cdecl hkConvexListAgent3_destroy(void* agent, ConvexListAgentRecord* shape, void* input, void* output, void* collector)
{
    if (shape->m_flags & 0x20)
    {
        ForwardToTarget(agent, shape, input, output, collector);
        return;
    }
    hkAgent1nMachine_Destroy(&shape->m_data, collector, input, output);
}

void __cdecl FUN_00d41860();
// @fnv 0x00d32bd0
// src: GUESS 0x00d32bd0 (confidence: low)
void __cdecl Hkpconvexlistagent3_ForwardCall_00d32bd0(int a, int b, int c)
{
    FUN_00d41860();
}

// Initializes the function table and registers the convex/convex-list and convex-list/convex-list pairs.
// @fnv 0x00d331a0
void __cdecl RegisterAgent3Entries(hkpCollisionDispatcher* pkDispatcher)
{
    __declspec(align(16)) hkpCollisionDispatcher::Agent3FunctionTable kFuncs;
    hkConvexListAgent3_initAgentFunc(kFuncs);
    pkDispatcher->AddEntry(&kFuncs, 0x12, 0x16);
    pkDispatcher->AddEntry(&kFuncs, 0x16, 0x16);
}

#include <xmmintrin.h>
// Builds on an earlier contributor's 2026-10-25 reconstruction of this routine.
extern float DAT_010CEB6C;
extern __m128 DAT_01268370;
void __cdecl hkPredGskAgent3_sepNormal(int, int, int, int);
// If bit 5 of the flag byte at c+11 is set, delegates to FUN_00d41930; otherwise writes DAT_01268370 to output and sets its fourth float to DAT_010CEB6C.
// @fnv 0x00d32ca0
// src: GUESS 0x00d32ca0 (confidence: low)
void __cdecl Object_ProcessAndReturnValue_00d32ca0(int a, int b, int c, int output)
{
    if ((*reinterpret_cast<const unsigned char*>(c + 11) & 0x20) != 0)
    {
        hkPredGskAgent3_sepNormal(a, b, c, output);
        return;
    }
    __m128* __restrict p = reinterpret_cast<__m128*>(output);
    float finalComponent = DAT_010CEB6C;
    *p = DAT_01268370;
    reinterpret_cast<float*>(p)[3] = finalComponent;
}

struct __declspec(align(16)) HK_Stage_t
{
    int d00;
    int d04;
    int d08;
    int d0c;
    int d10;
    int d14;
    int d18;
    int d1c;
    int d20;
    int d24;
    int d28;
    int d2c;
    int d30;
    int d34;
    int d38;
    int d3c;
};

// Copies the body, collision input, manager, and transform from the source context.
// @fnv 0x00d33260
ProcessInput_hkpconvexlistagent3& __fastcall CopyProcessInput(ProcessInput_hkpconvexlistagent3* destination, int, const ProcessInput_hkpconvexlistagent3& a)
{
    destination->bodyA = a.bodyA;
    destination->bodyB = a.bodyB;
    destination->unk08 = a.unk08;
    destination->input = a.input;
    destination->manager = a.manager;
    HK_Stage_t stagedTail;
    stagedTail.d00 = reinterpret_cast<const int*>(&a.transform)[0];
    stagedTail.d04 = reinterpret_cast<const int*>(&a.transform)[1];
    stagedTail.d08 = reinterpret_cast<const int*>(&a.transform)[2];
    stagedTail.d0c = reinterpret_cast<const int*>(&a.transform)[3];
    stagedTail.d10 = reinterpret_cast<const int*>(&a.transform)[4];
    stagedTail.d14 = reinterpret_cast<const int*>(&a.transform)[5];
    stagedTail.d18 = reinterpret_cast<const int*>(&a.transform)[6];
    stagedTail.d1c = reinterpret_cast<const int*>(&a.transform)[7];
    stagedTail.d20 = reinterpret_cast<const int*>(&a.transform)[8];
    stagedTail.d24 = reinterpret_cast<const int*>(&a.transform)[9];
    stagedTail.d28 = reinterpret_cast<const int*>(&a.transform)[10];
    stagedTail.d2c = reinterpret_cast<const int*>(&a.transform)[11];
    stagedTail.d30 = reinterpret_cast<const int*>(&a.transform)[12];
    stagedTail.d34 = reinterpret_cast<const int*>(&a.transform)[13];
    stagedTail.d38 = reinterpret_cast<const int*>(&a.transform)[14];
    stagedTail.d3c = reinterpret_cast<const int*>(&a.transform)[15];
    __m128* d = (__m128*)&destination->transform;
    const __m128* s = (const __m128*)&stagedTail.d00;
    d[0] = s[0];
    d[1] = s[1];
    d[2] = s[2];
    d[3] = s[3];
    return *destination;
}

#include <string.h>
struct __declspec(align(16)) FUN_00d33330_t
{
    __m128 first;
    __m128 second;
    int alpha, beta;
    int VirtualFunction28, reserved2c;
    int gamma, delta;
    volatile int epsilon, zeta;
    int coefficients[12];
    FUN_00d33330_t& CopyMemory_00d33330(const FUN_00d33330_t& other);
};
// Copies first, second, alpha, beta, gamma, delta, epsilon, zeta and 48 bytes of coefficients from other, and returns *this.
// @fnv 0x00d33330
// src: GUESS 0x00d33330 (confidence: low)
FUN_00d33330_t& FUN_00d33330_t::CopyMemory_00d33330(const FUN_00d33330_t& other)
{
    first = other.first;
    second = other.second;
    alpha = other.alpha;
    beta = other.beta;
    gamma = other.gamma;
    delta = other.delta;
    epsilon = other.epsilon;
    zeta = other.zeta;
    memcpy(coefficients, other.coefficients, 48);
    return *this;
}

extern const float DAT_0104da48 = 3.402820018375656e+38F;
struct CollisionRecord
{
    __m128 position;
    __m128 normal;
    __m128 properties;
};
struct SmallState
{
    float a;
    float b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int h;
    int i;
    int j;
    int k;
    int l;
};
struct CollisionState
{
    SmallState* copyScalars(const CollisionState& s)
    {
        unk40 = s.unk40;
        unk44 = s.unk44;
        unk48 = s.unk48;
        unk4c = s.unk4c;
        return &extra;
    }
    __m128 vector0;
    __m128 vector1;
    float distance;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    SmallState extra;
};
struct LargeOutput
{
    int header;
    int unk04;
    int unk08;
    int unk0c;
    CollisionRecord contacts[256];
    CollisionState state;
    void* data;
};
class FUN_00d33670
{
  public:
    int header;
    unsigned char data[0x1008];
    int unk100c;
    CollisionState state;
    FUN_00d33670(const LargeOutput& src);
};
// Copies header, state vectors, distance, scalars, and data buffer from a LargeOutput into this collision object.
// @fnv 0x00d33670
FUN_00d33670::FUN_00d33670(const LargeOutput& src)
{
    float d = DAT_0104da48;
    header = src.header;
    state.distance = d;
    state.extra.a = 0.0f;
    state.extra.b = 0.0f;
    state.vector0 = src.state.vector0;
    state.vector1 = src.state.vector1;
    memcpy(&state.distance, &src.state.distance, 8);
    SmallState* pExtra = state.copyScalars(src.state);
    memcpy(pExtra, &src.state.extra, sizeof(state.extra));
    if (src.data)
        FUN_00ec44d0(data, src.data, sizeof(data));
}

#include <xmmintrin.h>
namespace fnv_00d32cd0 {

#include <windows.h>
#include <string.h>

extern "C" unsigned __int64 __rdtsc();
extern "C" void _ReadWriteBarrier();

struct CollisionInput
{
    int unk00, unk04;
    float tolerance;
};
struct Cache
{
    int first, second;
    unsigned int state;
};
struct Basis
{
    hkVector4 x, y, z;
};
struct ContactIDs
{
    int id0, id1, id2, id3;
};
struct CacheState
{
    hkVector4 first, second;
    union
    {
        float time;
        unsigned int timeBits;
    };
    int key;
    int unk28, unk2c;
    ContactIDs ids;
    Basis transform;
    __forceinline void assign(const CacheState& source)
    {
        first.v = source.first.v;
        second.v = source.second.v;
        timeBits = source.timeBits;
        key = source.key;
        ids = source.ids;
        memcpy(&transform, &source.transform, sizeof(transform));
    }
};
struct Output
{
    int count;
    int owner;
    int unk08, unk0c;
    hkContactPoint contacts[384];
    CacheState cache;
    void* savedContacts;
};
struct Manager
{
    virtual void f00();
    virtual void f04();
    virtual void f08();
    virtual void f0c();
    virtual void f10();
    virtual void f14();
    virtual void f18();
    virtual void f1c();
    virtual void f20(int, Basis*);
};
struct Context
{
    hkpCdBody* bodyA;
    hkpCdBody* bodyB;
    int unk08;
    CollisionInput* input;
    Manager* manager;
    int unk14, unk18, unk1c;
    hkTransform transform;
    int extra60, extra64, extra68, extra6c, extra70, extra74, extra78, extra7c;
};
struct StateRecord
{
    union
    {
        int packed;
        struct
        {
            short countdown;
            unsigned char count;
            char unk0f;
        };
    };
    Cache cache;
};
struct Agent
{
    int unk00, unk04;
    short unk08;
    char unk0a;
    unsigned char flags;
    StateRecord state;
};
struct FUN_00d33670
{
    int count;
    int owner;
    int unk08, unk0c;
    hkContactPoint contacts[128];
    CacheState cache;
    FUN_00d33670(Output*);
    void hkpProcessCollisionOutputBackup_rollbackOutput(hkpCdBody*, hkpCdBody*, Output*, Manager*);
};

struct CollisionResult
{
    float unk00, unk04, unk08, distance;
};
struct ProbeInput
{
    hkTransform* relative;
    const void* world;
    const hkpShape* a;
    const hkpShape* b;
    float tolerance;
};
struct Collector
{
    void* vtable;
    short unk04;
    short capacity;
    int mode;
    Manager* manager;
    bool hit;
};
struct MonitorEntry
{
    const char* volatile name;
    unsigned int time;
    int unk08;
    const char* volatile detail;
};
struct Monitor
{
    int unk00;
    MonitorEntry* current;
    int unk08;
    MonitorEntry* end;
};
extern DWORD DAT_0126835c;
extern void* DAT_010ceb44;
extern float DAT_010ceb6c;
int __cdecl hkpGsk_getClosestPoint(ProbeInput*, Agent*, void*, hkVector4*);
void __cdecl hkAgent1nMachine_Destroy(Cache*, int, Manager*, int);
void* __cdecl hkPredGskAgent3_process(ProcessInput_hkpconvexlistagent3*, int, Agent*, void*, Output*);
void __cdecl FUN_00d41860(int, Agent*, Manager*, int);
void __cdecl InitBlockPool(Cache*);
void __cdecl hkAgent1nMachine_Process(Cache*, Context*, int*, int*, Output*);
void* __cdecl hkMemoryRouter_getInstance();

struct TLSArgument
{
    DWORD value;
};
// Runs a collision probe or stream on two bodies, updates the agent cache and contact output, and returns a 16-byte-aligned result pointer.
// @fnv 0x00d32cd0
// src: COMMUNITY 0x00d32cd0
void* __cdecl hkConvexListAgent3_process(Context* context, int stream, Agent* agent, CollisionResult* collisionOutput, Output* output)
{
    struct Scratch
    {
        volatile unsigned int stamp;
        union
        {
            hkpConvexListShape* shape;
            volatile unsigned int stamp;
        } shapeEnd;

        union
        {
            void* result;
            Monitor* monitor;
        } outcome;
    } scratch;

    {
        Monitor* monitor = (Monitor*)TlsGetValue(DAT_0126835c);
        MonitorEntry* entry = monitor->current;
        if (entry < monitor->end)
        {
            entry->name = "LtCvxLst";
            entry->detail = "StTim";
            _ReadWriteBarrier();
            scratch.stamp = (unsigned int)__rdtsc();
            _ReadWriteBarrier();
            entry->time = scratch.stamp;
            monitor->current = (MonitorEntry*)((char*)entry + 16);
        }
    }
    scratch.shapeEnd.shape = static_cast<hkpConvexListShape*>(const_cast<hkpShape*>(context->bodyB->m_pCollisionShape));
    FUN_00d33670 temporary(output);

    hkVector4 separating;
    ProcessInput_hkpconvexlistagent3 phase;
    union
    {
        ProbeInput probe;
        Collector collector;
    } arguments;
    if (agent->flags & 0x20)
        goto processStream;
    for (;;)
    {
        {
            scratch.outcome.monitor = (Monitor*)TlsGetValue(DAT_0126835c);
            MonitorEntry* entry = scratch.outcome.monitor->current;
            if (entry < scratch.outcome.monitor->end)
            {
                entry->name = "StStream";
                _ReadWriteBarrier();
                scratch.stamp = (unsigned int)__rdtsc();
                _ReadWriteBarrier();
                entry->time = scratch.stamp;
                scratch.outcome.monitor->current = (MonitorEntry*)((char*)entry + 12);
            }
            if (agent->state.countdown-- >= 0)
                goto fallback;
            agent->state.countdown = 25;
            {

                reinterpret_cast<hkTransform&>(phase).hkTransform_setMulInverseMul(context->bodyA->m_pMotionState, context->bodyB->m_pMotionState);

                arguments.probe.a = context->bodyA->m_pCollisionShape;
                arguments.probe.b = context->bodyB->m_pCollisionShape;
                arguments.probe.relative = reinterpret_cast<hkTransform*>(&phase);
                arguments.probe.world = context->bodyA->m_pMotionState;
                arguments.probe.tolerance = context->input->tolerance;

                if (!hkpGsk_getClosestPoint(&arguments.probe, agent, collisionOutput, &separating))
                    goto fallback;
            }
            hkAgent1nMachine_Destroy(&agent->state.cache, context->input->unk00, context->manager, output->owner);
            agent->flags |= 0x20;
            agent->state.packed = 0;
            temporary.hkpProcessCollisionOutputBackup_rollbackOutput(context->bodyA, context->bodyB, output, context->manager);
        }
    processStream: {

        arguments.collector.capacity = 1;
        arguments.collector.mode = 2;
        arguments.collector.vtable = &DAT_010ceb44;
        arguments.collector.manager = context->manager;
        arguments.collector.hit = false;

        phase.FUN_00d33260(reinterpret_cast<::Context*>(context));
        phase.extra60 = context->extra60;
        phase.extra70 = context->extra70;
        phase.extra74 = context->extra74;
        phase.extra78 = context->extra78;
        phase.extra7c = context->extra7c;
        phase.manager = reinterpret_cast<::Manager*>(&arguments.collector);
        scratch.outcome.result = hkPredGskAgent3_process(&phase, stream, agent, collisionOutput, output);
        phase.manager = reinterpret_cast<::Manager*>(arguments.collector.manager);
        if (!arguments.collector.hit)
        {
            if (!agent->state.count || (agent->flags & 0x40))
                goto finished;
            const hkpCdBody* body = context->bodyB;
            while (body->m_parent)
                body = body->m_parent;
            float radiusB = reinterpret_cast<const hkpCollidable*>(body)->m_fAllowedPenetrationDepth;
            body = context->bodyA;
            while (body->m_parent)
                body = body->m_parent;
            float radiusA = reinterpret_cast<const hkpCollidable*>(body)->m_fAllowedPenetrationDepth;
            float radius = radiusA < radiusB ? radiusA : radiusB;
            float twice = radius * 2.0f;
            if (!(collisionOutput->distance < -twice))
                goto finished;
        }
        Manager* manager = context->manager;
        if (output->cache.time != temporary.cache.time)
        {
            manager->f20(output->owner, &output->cache.transform);
            output->cache.assign(temporary.cache);
        }
        output->count = temporary.count;
        if (output->savedContacts)
            memmove(output->savedContacts, &temporary.owner, 0x1008);
        FUN_00d41860(stream, agent, context->manager, output->owner);
        agent->flags &= 0xdf;
        StateRecord* state = &agent->state;
        if (state)
        {
            state->cache.first = 0;
            state->cache.second = 0;
            state->cache.state = 0x80000000;
        }
        InitBlockPool(&agent->state.cache);
        agent->state.countdown = 25;
    }
    }
fallback:
    collisionOutput->distance = -1.701410009187828e+38f;
    {
        int count = scratch.shapeEnd.shape->m_kChildShapes.m_iElementCount;
        int** arena = (int**)hkMemoryRouter_getInstance();
        int* keys = *arena;
        *arena = (int*)((char*)keys + ((count * 4 + 0x83) & ~0x7f));
        for (int i = 0; i < count; ++i)
            keys[i] = i;
        int* sub = reinterpret_cast<int*>(
            reinterpret_cast<char*>(*(hkpConvexListShape* volatile*)&scratch.shapeEnd.shape) + sizeof(hkpConvexShape));
        Cache* cache = &agent->state.cache;
        hkAgent1nMachine_Process((keys[count] = -1, cache), context, sub, keys, output);
        *(int**)hkMemoryRouter_getInstance() = keys;
        scratch.outcome.result = cache + 1;
    }
finished:
    agent->flags |= 0x40;
    Monitor* monitor = (Monitor*)TlsGetValue(DAT_0126835c);
    MonitorEntry* entry;
    entry = monitor->current;
    if (entry < monitor->end)
    {
        entry->name = "lt";
        _ReadWriteBarrier();
        scratch.shapeEnd.stamp = (unsigned int)__rdtsc();
        _ReadWriteBarrier();
        entry->time = scratch.shapeEnd.stamp;
        monitor->current = (MonitorEntry*)((char*)entry + 12);
    }
    return (void*)(((unsigned int)scratch.outcome.result + 15) & ~15);
}
}  // namespace fnv_00d32cd0

class hkpLinearCastProcessorD334
{
  public:
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void V4() throw();
    virtual void V5() throw();
    virtual void V6() throw();
    virtual int process(const hkpCdBody* pkBodyA, const hkpCdBody* pkBodyB, int iArg3, int iArg4, float fArg5,
                        int iArg6, hkpGskCache* pkCache, int iArg8, int iArg9) throw();
};

class hkpConvexListLinearCastD334 : public hkpConvexListProcessorD333
{
  public:
    int hkpMapPointsToSubShapeContactMgr_addToiImpl(const hkpCdBody* a1, const hkpCdBody* a2, int a3, int a4, float a5, int a6,
                     hkpGskCache* a7, int a8, int a9);
};

// Resolves shape collection sub-shapes for both bodies if needed, then delegates to the linear cast processor's process method.
// @fnv 0x00d334c0
// src: HAVOK_SRC 0x00d334c0
int hkpConvexListLinearCastD334::hkpMapPointsToSubShapeContactMgr_addToiImpl(const hkpCdBody* apBodyA, const hkpCdBody* apBodyB, int a3,
                                              int a4, float a5, int a6, hkpGskCache* apCache, int a8, int a9)
{
    hkpCdBody wrapper2;
    hkpShapeBuffer buffer;
    hkpCdBody wrapper1;

    const hkpCdBody* bodyA = apBodyA;
    const hkpCdBody* bodyB = apBodyB;

    if (apBodyA->m_pCollisionShape->getType() == 0x16)
    {
        int keyA = apCache->m_kVertices[0] >> 8;
        for (int i = 1; i < apCache->m_ucDimensionA; ++i)
        {
            if ((apCache->m_kVertices[i] >> 8) != keyA)
            {
                m_invalidCache = 1;
                return 1;
            }
        }
        const hkpShape* shape = static_cast<const hkpConvexListShape*>(apBodyA->m_pCollisionShape)
                                        ->GetShapeForKey(keyA, buffer);
        wrapper1.m_uiCollisionShapeKey = keyA;
        wrapper1.m_parent = apBodyA;
        wrapper1.m_pMotionState = apBodyA->m_pMotionState;
        wrapper1.m_pCollisionShape = shape;
        bodyA = &wrapper1;
    }

    if (apBodyB->m_pCollisionShape->getType() == 0x16)
    {
        int keyB = apCache->m_kVertices[apCache->m_ucDimensionA] >> 8;
        for (int i = apCache->m_ucDimensionA + 1; i < apCache->m_ucDimensionB + apCache->m_ucDimensionA; ++i)
        {
            if ((apCache->m_kVertices[i] >> 8) != keyB)
            {
                m_invalidCache = 1;
                return 1;
            }
        }
        const hkpShape* shape = static_cast<const hkpConvexListShape*>(apBodyB->m_pCollisionShape)
                                        ->GetShapeForKey(keyB, buffer);
        wrapper2.m_parent = apBodyB;
        wrapper2.m_pMotionState = apBodyB->m_pMotionState;
        wrapper2.m_pCollisionShape = shape;
        wrapper2.m_uiCollisionShapeKey = keyB;
        bodyB = &wrapper2;
    }

    return reinterpret_cast<hkpLinearCastProcessorD334*>(m_processor)
        ->process(bodyA, bodyB, a3, a4, a5, a6, apCache, a8, a9);
}
