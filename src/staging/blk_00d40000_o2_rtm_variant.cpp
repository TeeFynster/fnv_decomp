#include "../../include/hkArray.h"
// src/staging/blk_00d40000_o2_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00d40000_o2.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/staging/blk_00d40000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
#include "../../include/AutoMemContext.h"
#include "../../include/NiObject.h"
#include "../../include/NiTMap.h"
#include "../../include/NiTMapItem.h"
#include "../../include/bhkListShape.h"
#include "../../include/bhkRefObject.h"
#include "../../include/bhkWorldObject.h"
#include "../../include/hkAabb.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/FinishingFlag.h"
#include "../../include/NiStream.h"
#include "../../include/hkBool.h"
#include "../../include/hkError.h"
#include "../../include/hkRotation.h"
#include "../../include/hkpConstraintData.h"
#include "../../include/hkpWorld.h"

#include "../../include/hkReferencedObject.h"
#include "../../include/hkStringPtr.h"
#include "../../include/hkVector4.h"
#include "../../include/hkBaseObject.h"
#include "../../include/hkMemoryAllocator.h"
#include "../../include/hkMemoryRouter.h"

// The shared router and finish-loaded flag retain their checked canonical names.

__forceinline void hkVector4::set(float x, float y, float z, float w)
{
    m_vComponents = _mm_setr_ps(x, y, z, w);
}

struct FUN_00c9ce00_cls
{
    void __thiscall FUN_00c9ce00(int);
};
extern int DAT_010c7888;
void __cdecl finishLoadedObjecthkpRigidBody(FUN_00c9ce00_cls* pObject, int aiValue);
extern "C" void __cdecl AppendEventRecord(int, int, int, int);
void __stdcall hkpBreakableConstraintData_buildNopJacobian(int a, int b);
struct FUN_00d53200_class
{
    void hkConstraintCinfo_LoadBinary(NiStream& stream);
    void hkConstraintChainCinfo_LoadBinary(NiStream& stream);
};
void* __cdecl InitAndGetOffset(void*, void*, void*);
void __cdecl RemoveEntryByKey(void);
void __cdecl FindOrClaimEntry(void);
void __cdecl nullsub_16(void);
void __cdecl ResetEntryAgents(void);
void __cdecl Runtime_ResetEntryAgents_Thunk(void);
void __cdecl hkBoxBoxAgent3_process(void);
void __cdecl hkBoxBoxAgent3_initAgentFunc(void* apObject);
void __cdecl DispatchInputRecord();
void __cdecl hkPredGskAgent3_process();
void __cdecl hkPredGskAgent3_sepNormal();
void __cdecl FUN_00d41860();
void __cdecl RemoveEntryById();
void __cdecl InsertSlotId();
void __cdecl FindEntryByKey();
void __cdecl ForwardToTarget();
void __cdecl hkPredGskAgent3_initAgentFunc(int* pObject);
extern int DAT_010cf9a4;
void __cdecl Runtime_UpdateState_00d48350(int* p);
struct FUN_00d49580_vtbl
{
    virtual void v0(int);
};
void __cdecl Object_InvokeVirtualMethod_00d49580(FUN_00d49580_vtbl* p);
extern int DAT_010305a8;
extern int DAT_010ce31c;
extern int DAT_010cfb34;
void __cdecl Object_UpdateFields_00d495a0(int* pObject, int b);
void __cdecl Runtime_Helper_00d4b190(void* p);
struct FUN_00d4b250_class
{
    void __thiscall Runtime_ForwardCall_00d4b250(int);
};
struct FUN_00d4b250_vt
{
    virtual void __thiscall Runtime_ForwardCall_00d4b250(int);
};
void __cdecl Runtime_ForwardCall_00d4b250(FUN_00d4b250_vt* p);
struct FUN_00d4be50_vt
{
    virtual void Runtime_ForwardCall_00d4be50(int);
};
void __cdecl Runtime_ForwardCall_00d4be50(FUN_00d4be50_vt* p);
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
void __cdecl hkpShapeCollectionAgent_registerAgent(Agent* a);
struct FUN_00d48330_vt
{
    virtual void v0(int);
};
void __cdecl Runtime_ForwardCall_00d48330(FUN_00d48330_vt* p);
void __cdecl Runtime_ForwardCall_00d49510(FUN_00d49580_vtbl* p);
struct FUN_00d4b1f0_vt
{
    virtual void __thiscall Runtime_ForwardCall_00d4b1f0(int);
};
void __cdecl Runtime_ForwardCall_00d4b1f0(FUN_00d4b1f0_vt* p);
struct FUN_00d4b320_vt
{
    virtual void v0(int);
};
void __cdecl Object_InvokeVirtualMethod_00d4b320(FUN_00d4b320_vt* p);
void __cdecl Runtime_ForwardCall_00d4beb0(FUN_00d49580_vtbl* p);
struct FUN_00d4bf30_vt
{
    virtual void Runtime_ForwardCall_00d4bf30(int);
};
void __cdecl Runtime_ForwardCall_00d4bf30(FUN_00d4bf30_vt* p);
extern const char* const g_01268eb4_arg1;
const char* const* __cdecl Object_GetGlobalObjectAddress_00d4bf60();
struct FUN_00d4fe40_cls
{
    char pad[0xa2];
    bool b0;
    char pad2[0xb2 - 0xa3];
    bool b1;
    void __thiscall hkpPrismaticConstraintData_setMotorActive(void* a, bool b);
};
struct FUN_00d532a0_cls
{
    void __thiscall DispatchToInnerSlot(int);
    void __thiscall ApplyToAllEntries(int arg);
};
// CreateSpawnObject: cdecl factory. Allocates one of two object sizes through the
// global allocator holder. A non-zero flag selects the large object (0x80 bytes,
// constructor takes the flag, then the vtable is stored); zero selects the small
// object (0x30 bytes, constructor returns the object).
struct ObjAllocator
{
    virtual void unk00();
    virtual void* Alloc(unsigned int size);
};
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
void* __cdecl CreateSpawnObject(int a1, int a2, int a3, int a4);
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
int __cdecl DispatchToType1dNodes(FNVDispatchNode* pNodeA, FNVDispatchNode* pNodeB, int iCode);
void __cdecl Object_ProcessAndReturnValue_00d42800();
void __cdecl CallVirtualMethod();
void __cdecl nullsub_17();
void __cdecl nullsub_18();
void __cdecl Object_UpdateFields_00d42960(Agent* apAgent);
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
extern int DAT_01268b9c;
void* __cdecl Object_GetGlobalObjectAddress_00d48340();
extern int DAT_010cf9a4;
int* __cdecl Object_GetGlobalObjectAddress_00d48360();
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
S_00d483a0_Result CheckMagicPair(unsigned uiFirst, unsigned uiSecond);
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
void* __cdecl InitAndCall(void* volatile a1, void* volatile a2, void* volatile a3, void* volatile a4,
                          void* volatile a5);
extern int DAT_01268bcc;
int* __cdecl Object_GetGlobalObjectAddress_00d49520();
extern int DAT_01268c14;
int __cdecl Runtime_EvaluateValue_00d49590();
extern int DAT_010cfb34;
int __cdecl Runtime_EvaluateValue_00d495f0();
extern int DAT_010cfd10;
struct FnvVtObj
{
    int m_vptr;

    FnvVtObj* SetVirtualTable_00d49c40(unsigned int unusedArg);
};
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
void __cdecl Runtime_ProcessState_00d4b170(S_00d4b170* pTarget, int a);
extern int DAT_01268cbc;
void* __cdecl Object_GetGlobalObjectAddress_00d4b1c0();
struct S_00d49c40
{
    void __thiscall SetVirtualTable_00d49c40(int a);
};
void __cdecl Object_ProcessState_00d4b1d0(S_00d49c40* pObject, int a);
extern int DAT_01268d04;
int __cdecl Object_ComputeValue_00d4b220();
// Forwarding helper: if the object pointer is valid, pass the second
// argument on to the object's own handler.
struct FUN_00d4a180_cls
{
    void __thiscall FUN_00d4a180(int a);
};
void __cdecl Runtime_ProcessState_00d4b230(FUN_00d4a180_cls* pTarget, int aiValue);
extern int DAT_01268d4c;
int* __cdecl Object_GetGlobalObjectAddress_00d4b280();
extern int DAT_01268d94;
void* __cdecl Object_GetGlobalObjectAddress_00d4b2a0();
extern unsigned char DAT_01268dc4;
void* __cdecl Object_GetGlobalObjectAddress_00d4b2c0();
// Null-guarded forwarder: the first argument is an object pointer; when it
// is non-null the second argument is handed to a member function of that
// object.
class FUN_00d4b2d0_cls
{
  public:
    void hkpExtendedMeshShape_ShapesSubpart_ShapesSubpart(int a1);
};
void __cdecl hkpExtendedMeshShape_ShapesSubpart_ShapesSubpart_ProcessState_00d4b2d0(FUN_00d4b2d0_cls* pObject, int aiValue);
extern int DAT_01268df4;
void* __cdecl Runtime_GetDAT01268df4Address();
// Null-guarded forwarder: the first argument is an object pointer; when it
// is non-null the second argument is handed to a member function of that
// object.
class FUN_00d4b300_cls
{
  public:
    void FUN_00d56f10(int a1);
};
void __cdecl Object_ProcessState_00d4b300(FUN_00d4b300_cls* pObject, int aiValue);
extern int DAT_01268e24;
void* Runtime_GetDAT01268e24Address();
struct TailTarget
{
    void Run();
};
void __cdecl Object_InvokeVirtualMethod_00d4b380(TailTarget* pTarget);
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
class D4BE30World
{
  public:
    void UpdateEntity(void* pvEntity);
};
void Runtime_ProcessState_00d4be30(D4BE30World* pkWorld, void* pvEntity);
extern int DAT_01268e6c;
int* Object_GetGlobalObjectAddress_00d4be80();
struct FUN_00d4ba30_class
{
    void __thiscall FUN_00d4ba30(int);
};
void __cdecl Object_ProcessState_00d4be90(FUN_00d4ba30_class* pObject, int value);
extern int g_unk01268eb4;
void* __cdecl Object_GetGlobalObjectAddress_00d4bee0();
extern int g_unk01268efc;
void* __cdecl Object_GetGlobalObjectAddress_00d4bf00();
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
void Runtime_AllocateStorage_00d4bf10(void* apMemory, int finishing);
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
extern int DAT_01268188;
extern int DAT_01268f74;
extern __declspec(thread) int g_ThreadMemoryContext;
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
struct MemoryContextScope
{
    int previousContext;
    MemoryContextScope()
    {
        previousContext = g_ThreadMemoryContext;
        g_ThreadMemoryContext = 16;
    }
    ~MemoryContextScope()
    {
        g_ThreadMemoryContext = previousContext;
    }
};
struct DataFactory
{
    void bhkConstraint_CopyMembers(DataObject* object, int id);
    DataObject* bhkGenericConstraint_Clone(int id);
};
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
void __cdecl hkpConstraintConstructionKit_computeConstraintInfo(D51760Buffer* buf, D51760Stats* stats);
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
extern double DAT_0101ffa0;
extern double DAT_010d0f08;
extern float DAT_011b5be0;
extern float DAT_011b5be4;
void ComputeByteScale(int bits);
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
struct CallTarget_00d5ecc0
{
    int Splice(int, int, int, int, int);
};
struct SearchObject
{
    int Search(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3);
};
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
extern __declspec(thread) int g_tlsMemContext;
struct ScopedMemoryContextD53
{
    int iOldContext;
    __forceinline ScopedMemoryContextD53(int aiContext)
    {
        iOldContext = g_tlsMemContext;
        g_tlsMemContext = aiContext;
    }
    __forceinline ~ScopedMemoryContextD53()
    {
        g_tlsMemContext = iOldContext;
    }
};
class FUN_00cc0500
{
  public:
    char pad00[12];
    FUN_00cc0500(void* pvBuffer, int iSize, hkBool bIsString);
    ~FUN_00cc0500();
};
struct OstreamD53
{
    OstreamD53& ProcessAndReturnValue_00cc01c0(const char* pcText);
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
struct D53970Scope
{
    int m_saved;
    int* m_pVar;
    D53970Scope()
    {
        m_pVar = &g_ThreadMemoryContext;
        m_saved = *m_pVar;
        *m_pVar = 16;
    }
    ~D53970Scope()
    {
        *m_pVar = m_saved;
    }
};
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
void __cdecl hkString_memCpy16_64(int* aiDest, const int* aiSrc);
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
template <class T> struct AddBackArg
{
    typedef T Type;
};
// hkArray<T>::pushBack as this unit's original inlines it (the router's allocator is read only on the grow path).
template <class T> inline void AddBack(hkArray<T>& a, const typename AddBackArg<T>::Type& e)
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
void nullsub_17();
void __cdecl nullsub_18();
class hkListNodeD46D
{
  public:
    int unk00;
    hkListNodeD46D* m_next;

    int ProcessEntries_00d46d70() const;
};
class hkBlockD46E
{
  public:
    int unk00;
    hkBlockD46E* m_next;
    int unk08;
    int m_iVertexCount;

    int SumLinkedValues() const;
};
int __stdcall Object_ReturnZero_00d46e00(int arg0);
int __stdcall Runtime_ReturnZero_00d46e10(int arg0);
struct FUN_00d46e20_cls
{
    void* unk00;
    void* unk04;
    void* unk08;
    int unk0C;
    int __thiscall GetUnk0C_00d46e20();
};
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
int* __fastcall GetEntryAt(char* self, int edx, int index);
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
struct FUN_00c90510_Obj
{
    void FUN_00c90510();
};
struct FUN_00d47730_cls
{
    FUN_00c90510_Obj* unk00;
    FUN_00d47730_cls* SetObject(FUN_00c90510_Obj* p, int unk);
};
struct FUN_00d48300_Obj
{
    void ProcessAndReturnValue_00d48300(int a1);
};
void __cdecl Object_ProcessState_00d47f40(FUN_00d48300_Obj* obj, int aiValue);
class GlobalObjectO2_00d472a0;
extern GlobalObjectO2_00d472a0 g_01268b24;
GlobalObjectO2_00d472a0* __cdecl Object_GetGlobalObjectAddress_00d47f60();
struct FnvCpu_FUN_00d47f70_CpuTarget
{
    void FUN_00d48320(int value);
};
void __cdecl Runtime_ProcessState_00d47f70(FnvCpu_FUN_00d47f70_CpuTarget* pCpuTarget, int value);
struct CpuOpaque;
extern CpuOpaque DAT_01268b54;
CpuOpaque* __cdecl Runtime_GetDAT01268b54Address();
struct Sh00c905b0
{
    void FUN_00c905b0();
};
struct Sh00cb0c00
{
    void Object_UpdateFields_00cb0c00();
};
void __cdecl Object_UpdateFields_00d47fa0(void* obj);
struct FUN_00d47fe0_cls
{
    void __thiscall Destroy(int value);
};
void __cdecl cleanupLoadedObjecthkRootLevelContainer(FUN_00d47fe0_cls* object);
class FUN_00d48320
{
  public:
    FUN_00d48320(FinishingFlag flag);
};
class FUN_00dcc160_cls
{
  public:
    FUN_00dcc160_cls* InitFromValue(void* pvSource);
    void SetVirtualTable_00dcc160();

    int m_iUnk00;
    int m_iUnk04;
    void* m_pResource;
};
void* __cdecl hkSerializeUtil_loadOnHeap_00d491b0(void* pvSource, void* pvArg, void* pvArgCur, void* kvArg);
void nullsub_97();
void __cdecl nullsub_99();
void __cdecl nullsub_101();
void nullsub_98();
void nullsub_100();
void nullsub_102();
void __cdecl hkConstraintCinfo_LoadBinary(int* param_1, int param_2);
void __cdecl hkGenericConstraintCinfo_LoadBinary(int* param_1, int param_2);
struct FUN_00c89920_cls
{
    void __thiscall InvokeRefTarget(int);
};
struct FUN_00d53290_cls
{
    void __thiscall bhkConstraintChain_SaveBinary(int a);
};
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
struct hkVectorD541
{
    float m_uiX;
    float m_uiY;
    float m_uiZ;
    float m_w;

    void hkVector4_setTransformedInversePos(const hkVectorD541& kOther, const float& fT);
};
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
    hkVectorD541 m_kPointA;
    hkVectorD541 m_kPointB;

    void hkpBallAndSocketConstraintData_setInWorldSpace(const hkVectorD541& kA, const hkVectorD541& kB, const float& fT);
};
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
struct FUN_00d54da0_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    float m_10;

    void SetField10_00d54da0(float value);
};
struct FnvCpu_FUN_00d54db0_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    float value;
    float hkpMoppCompilerInput_getRelativeFitToleranceOfInternalNodes();
};
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
float __fastcall hkpMoppCompilerInput_getAbsoluteFitToleranceOfInternalNodes(char* self, int);
void __cdecl Runtime_DoNothing_00d55510();
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
void __cdecl CopySixteenByteBlocks(int* pDest, const int* pSrc);
void Runtime_DoNothing_00d57150();
int __stdcall Runtime_ReturnConstant_0x60(int iUnused0, int iUnused1);
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
extern double DAT_010229c0;
struct FUN_00d5d660_cls
{
    int m_i00;
    int m_i04;
    void __thiscall NextFloat4(float* pOut);
};
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
struct FUN_00d5f740_cls
{
    char pad[0x24];
    int m_24;
    char pad2[0xc0 - 0x28];
    int m_c0;
    void __thiscall SetValue(int a);
};
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
// FUN_00d48fc0 - loads a Havok packfile/tagfile from a stream and dispatches
// on the format that was detected in it.
extern const char str_010cfacc[];
extern const char str_010cfab8[];
extern const char str_010cfa94[];
extern const char str_010cf830[];
extern const unsigned char DAT_011b7b88[];
extern void* DAT_01269b70;
struct Hk48fc0_Bool
{
    char m_bVal;
    Hk48fc0_Bool()
    {}
    operator bool() const
    {
        return m_bVal != 0;
    }
};
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
    Hk48fc0_Bool __thiscall MatchesTag(const unsigned char* pExpected);
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
    virtual Hk48fc0_Bool __thiscall IsStreamValid();
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
void* __cdecl hkSerializeUtil_loadOnHeap(void* pStream, void* pError, void* pAllocator, void* pLoader);
struct d20base
{
    int f0;
};
d20base* volatile g_d20_self;
extern "C" int d20_sel(void);
static int numIndices_00d49c20(d20base* self, int sel);
int d20_probe(void);
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
static int storageMeshShape_numIndices(int base, int code);
void elem_size_case_d4b390(void);
struct hkpD500Stream;
class hkpD500Object
{
  public:
    void hkConstraintCinfo_SaveBinary(hkpD500Stream* pkStream);
    void hkGenericConstraintCinfo_SaveBinary(hkpD500Stream* pkStream);
};
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
extern __declspec(thread) unsigned int t_uiMemContextD53;
hkMemoryRouter& __cdecl GetMemoryRouterD53();
class hkRefObjD549
{
  public:
    void FUN_00c905b0();
};
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

    hkRefObjD549* m_pReference;
};
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
struct D47180Cls
{
    int FUN_00d47130(int, int*, int*);
    int IsHelperResultFalse_00d47180(int arg);
};
static char* Object_ProcessEntries_00d48420(char* p);
volatile char* g_d48420_p;
char* d48420_caller();
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
struct AllocatorD500
{
    virtual void v00();
    virtual void* allocate(unsigned int);
    virtual void free(void*, unsigned int);
};
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
struct D502D0_TlsBlock
{
    unsigned char unk000[0x2b4];
    unsigned int m_2b4;
};
extern __declspec(thread) D502D0_TlsBlock g_d502d0Tls;
struct D502D0_TlsGuard
{
    unsigned int m_saved;
    D502D0_TlsGuard()
    {
        m_saved = g_d502d0Tls.m_2b4;
        g_d502d0Tls.m_2b4 = 0x10;
    }
    ~D502D0_TlsGuard()
    {
        g_d502d0Tls.m_2b4 = m_saved;
    }
};
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
extern volatile unsigned int DAT_0126fd98;
struct AudioTlsState
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int context;
};
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
        return ((FUN_00dd0530*)((ObjAllocator*)h->m_heap)->Alloc(n))->SetSizeAndGrow(n);
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
extern __declspec(thread) unsigned int t_uiMemContext35D0;
inline unsigned int GetMemContext35D0()
{
    return t_uiMemContext35D0;
}
inline void SetMemContext35D0(unsigned int m_uiGeometryShaderFlags)
{
    t_uiMemContext35D0 = m_uiGeometryShaderFlags;
}
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
    hkpWorld* GetWorld() const
    {
        return m_pkWorld;
    }
    hkpWorld* m_pkWorld;
};
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
__forceinline hkMemoryRouter* getRouter()
{
    return (hkMemoryRouter*)hkMemoryRouter_getInstance();
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
    hkArray<TrianglesSubpart> m_kTrianglesSubparts;
    hkArray<ShapesSubpart> m_kShapesSubparts;
    int m_unkCC;
    int m_unkD0;
    int m_unkD4;
    int m_unkD8;
    int m_unkDC;
    int m_iFinishingFlag;

    FUN_00d56f10(FinishingFlag flag);
    virtual ~FUN_00d56f10();
};
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
void LoadIntoArray(const InputBuffer* src, unsigned int flags, ArrayData* dst);
namespace hkRouterD47F {
extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance() throw();
}
template <class T> class hkRefPtrD47F
{
  public:
    T* m_pRetainedObject;
    ~hkRefPtrD47F()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        m_pRetainedObject = 0;
    }
};
struct hkNamedVariantD47F
{
    hkStringPtr m_name;
    hkStringPtr m_pClassName;
    hkRefPtrD47F<hkReferencedObject> m_pReferencedResource;
};
namespace hkArrayUtilD47F {
template <class T> __forceinline void destruct(T* t, int numElements)
{
    for (int i = 0; i < numElements; i++)
        t[i].~T();
}
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
    __m128 field20;
    __m128 field30;
    void InitializeFields_00d541b0(hkVector4* input0, hkVector4* input1);
};
struct FnvCpu_FUN_00d54e40_CpuObject
{
    __m128 field00;
    void CopyFrom(hkVector4* input0);
};
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
// Constraint command storage has vector/command arrays at 0x10/0x1c; shared Data is 0x10 bytes.
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
struct S
{
    char pad[2];
    char val;
};
extern "C" void __cdecl ReleaseAllEntries(S* a, int b, int c);
static void resetGskManifold(S* dst, S* src, int b, int c);
volatile S* g_dst;
volatile S* g_src;
volatile int g_b;
volatile int g_c;
void caller();
class FUN_00cb0a60 : public hkStringPtr
{
  public:
    FUN_00cb0a60() throw();
    using hkStringPtr::operator=;
};
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
                ((FUN_00c90510_Obj*)pkNew)->FUN_00c90510();
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
    FUN_00cb0a60 m_name;
    FUN_00cb0a60 m_pClassName;
    RefPtrD482 m_object;

    FUN_00d48250(const char* pcName, int iParam) throw();
};
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
inline void setZero4(hkVector4& v)
{
    _mm_store_ps(&v.x, _mm_setzero_ps());
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
struct hkpRagdollDataS : hkpConstraintData
{
    void setConeStab(hkBool b);
};
struct FUN_00d4f2a0 : hkpRagdollDataS
{
    hkpRagdollAtomsS m_kBridgeAtoms;
    FUN_00d4f2a0();
    virtual ~FUN_00d4f2a0();
};
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
        ::_mm_store_ps(&m00, ::_mm_setzero_ps());
        ::_mm_store_ps(&m10, ::_mm_setzero_ps());
        ::_mm_store_ps(&m20, ::_mm_setzero_ps());
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

template <class T> __forceinline void CopyItems(T* destination, int count, const T& item)
{
    for (int i = 0; i < count; ++i)
        destination[i] = item;
}
template <class T> struct RecordQueue
{
    T* data;
    int count;
    int capacity;
    __forceinline int GetLogicalSize() const
    {
        return count;
    }
    __forceinline void AddBack(const T& item)
    {
        hkMemoryRouter* arena = hkMemoryRouter_getInstance();
        if (count == (capacity & 0x3fffffff))
            ResizeAudioStream(arena->m_heap, this, sizeof(T));
        CopyItems(data + count, 1, item);
        ++count;
    }
};
struct ConstraintState
{
    int unk00, unk04, unk08, unk0C;
    RecordQueue<hkVector4> values;
    RecordQueue<int> events;
};
struct ConstraintBuilder
{
    int unk00;
    ConstraintState* state;
    int count;
    int ProcessAndReturnValue_00d52ae0(float value);
};
// @fnv 0x00d52ae0
// src: GUESS 0x00d52ae0 (confidence: low)
int ConstraintBuilder::ProcessAndReturnValue_00d52ae0(float value)
{
    ++count;
    state->events.AddBack(0x16);
    hkVector4 record;
    record.set(value, 0.0f, 0.0f, 0.0f);
    int result = state->values.GetLogicalSize();
    state->values.AddBack(record);
    return result;
}

extern const void* DAT_010d0fc4[];
extern "C" void _ReadWriteBarrier();
struct Scalar380
{
    __m128 value;
    Scalar380(float scalar)
    {
        value = _mm_load_ss(&scalar);
    }
    __m128 Broadcast() const
    {
        return _mm_shuffle_ps(value, value, 0);
    }
};
inline void MultiplyVector(hkVector4& vector, const Scalar380& scalar)
{
    vector.m_vComponents = _mm_mul_ps(scalar.Broadcast(), vector.m_vComponents);
}
struct ConvexBase380
{
    const void** vtable;
    unsigned short memorySize, references;
    unsigned int userData, shapeType;
    float radius;
    ConvexBase380(float r) : userData(0), shapeType(6), radius(r)
    {}
};
template <class T> struct Array380
{
    T* data;
    int size;
    unsigned int capacityAndFlags;
    Array380(T* p, int n) : data(p), size(n), capacityAndFlags((unsigned int)n | 0x80000000u)
    {}
};
struct TransposedPoints380
{
    hkVector4 x, y, z;
};
struct PointArray380
{
    TransposedPoints380* data;
    int size;
    unsigned int capacityAndFlags;
    PointArray380(TransposedPoints380* p, int n)
    {
        data = p;
        size = ((n + 3) & ~3) / 4;
        capacityAndFlags = (unsigned int)size | 0x80000000u;
    }
};

struct FUN_00d59760 : ConvexBase380
{
    hkVector4 halfExtents, center;
    PointArray380 vertices;
    int vertexCount;
    unsigned int unk50;
    Array380<hkVector4> planes;
    void* connectivity;

    FUN_00d59760(TransposedPoints380*, int, hkVector4*, int, const hkAabb&, float);
};
// @fnv 0x00d59760
FUN_00d59760::FUN_00d59760(TransposedPoints380* vertexData, int count, hkVector4* planeData, int planeCount,
                           const hkAabb& bounds, float r)
    : ConvexBase380(r), vertices((vtable = DAT_010d0fc4, references = 1, vertexData), count), vertexCount(count),
      unk50(0), planes(planeData, planeCount), connectivity(0)
{
    halfExtents.setSub4(bounds.m_kMaximumCorner, bounds.m_kMinimumCorner);
    MultiplyVector(halfExtents, 0.5f);
    center.setAdd4(bounds.m_kMinimumCorner, bounds.m_kMaximumCorner);
    MultiplyVector(center, 0.5f);
}

struct AngularFrictionBudget
{
    int unk00;
    int counter04;
    int counter08;
    int counter0c;
    void add(int bytes, int count, int results)
    {
        counter04 += bytes;
        counter08 += count;
        counter0c += results;
    }
};
struct AngularFrictionState
{
    AngularFrictionBudget budget;
    hkArray<hkVector4> records;
    hkArray<int> values;
};
struct AngularFrictionWriter
{
    int unk00;
    AngularFrictionState* state;
    int ProcessAndReturnValue_00d528e0(unsigned char value, float f);
};
// @fnv 0x00d528e0
// src: GUESS 0x00d528e0 (confidence: low)
int AngularFrictionWriter::ProcessAndReturnValue_00d528e0(unsigned char value, float f)
{
    d51::AddBack(state->values, 0x14);
    d51::AddBack(state->values, value);
    __declspec(align(16)) struct { unsigned __int64 low, high; } tmpStorage;
    hkVector4& tmp = *reinterpret_cast<hkVector4*>(&tmpStorage);
    ::_mm_store_ps(&tmp.x, _mm_setr_ps(f, 0.0f, 0.0f, 0.0f));
    int result = state->records.m_iElementCount;
    d51::AddBack(state->records, tmp);
    state->budget.add(0x30, 1, 2);
    return result;
}


// The MOPP path still needs this scalar-field representation: adopting hkVector4
// changes FUN_00d54a40 from 642 bytes to 679 bytes with VC9 RTM.
namespace D4F2A0Simd {
// Exe 0x00d54a40 FUN_00d54a40: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) {
    struct
    {
        float x, y, z, w;
    };
} __m128, LocalM128;
extern "C" LocalM128 _mm_setzero_ps();
extern "C" void _mm_store_ps(float*, LocalM128);
}
struct __declspec(align(16)) D4F2A0Vector
{
    float x, y, z, w;
};
namespace MoppBuildSimd {
extern "C" ::D4F2A0Simd::LocalM128 _mm_load_ps(const float*);
extern "C" ::D4F2A0Simd::LocalM128(_mm_setr_ps)(float, float, float, float);
}

typedef ::D4F2A0Vector hkQuadReal;

struct FUN_00dd5150_Class
{
    float f0, f1, f2, f3, f4, f5;
    FUN_00dd5150_Class(int);
};

struct FUN_00dd50f0_Class
{
    float m_00;
    int m_04, m_08, m_0c, m_10;
    bool m_14;
    FUN_00dd50f0_Class(int);
};

struct Sub3
{
    float f0;
    float f1;
    float f2;
    hkQuadReal v;
    int i20;
    bool b24;

    __forceinline Sub3() : f0(0.5f), f1(0.2f), f2(1.0f), i20(5), b24(true)
    {
        __declspec(align(16))::D4F2A0Simd::LocalM128 q = MoppBuildSimd::_mm_setr_ps(0.2f, 0.2f, 0.05f, 0.0f);
        v = *reinterpret_cast<const hkQuadReal*>(&q);
    }
};

struct FUN_00d549d0_Class
{
    int m_00;
    int* m_arr1_data;
    int m_arr1_size;
    int m_arr1_capacity;
    int* m_arr2_data;
    int m_arr2_size;
    int m_arr2_capacity;
    int m_1c;
    int m_20;

    void ClearArrays();
};

struct FUN_00dd4bf0_Class
{
    int m_unk00;
    void* m_ptr4;
    FUN_00dd50f0_Class m_sub1;
    FUN_00dd5150_Class m_sub2;
    int m_unk38;
    int m_unk3c;
    Sub3 m_sub3;

    FUN_00dd4bf0_Class(int);
    void SetValues(const FUN_00dd5150_Class*);
    void CopyFromSourceData(const Sub3*);
    void AssignFromSource(const FUN_00dd50f0_Class*);
    int ComputeRequiredSize(void*);
    void* AllocateStorage_00dd4cb0(void*, void*, int);
    void Object_DoNothing_00dd4b00();
};

struct Arg2Struct
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    unsigned char m_1c;
    unsigned char m_1d;
    unsigned char m_1e;
    unsigned char m_1f;

    float hkpMoppCompilerInput_getRelativeFitToleranceOfInternalNodes();
    float hkpMoppCompilerInput_getAbsoluteFitToleranceOfInternalNodes();
    float hkpMoppCompilerInput_getAbsoluteFitToleranceOfTriangles();
    hkQuadReal* GetValue(hkQuadReal* out);
};

struct StackAllocator
{
    virtual void v00();
    virtual void* allocate(int size);
    virtual void deallocate(void* ptr, int size);
};

__forceinline void DisableSub2Tail(FUN_00dd5150_Class& sub2, ::hkBool bNoFirst, const Arg2Struct* arg2)
{
    if (bNoFirst || arg2->m_1e)
    {
        sub2.f4 = 0.0f;
    }
}

struct SearchCall_d54a40
{
    int Search(unsigned int, unsigned int, unsigned int, unsigned int);
};

__forceinline void ReportResults(::SearchObject* s3, int* data, int size)
{
    ::hkMemoryRouter* alloc = hkMemoryRouter_getInstance();
    ((SearchCall_d54a40*)s3)->Search((unsigned int)alloc->m_heap, 0, (unsigned int)data, size);
}

// @fnv 0x00d54a40
// src: XBOX_PDB 0x00d54a40
void* __cdecl hkpMoppUtility_buildCodeInternal(void* arg0, void* arg1, Arg2Struct* arg2, ::SearchObject* arg3)
{
    void* buffer;
    bool flag17;

    FUN_00dd4bf0_Class big_obj(0);
    {
        FUN_00dd5150_Class sub2(0);
        sub2.f0 = 1.0f;
        DisableSub2Tail(sub2, arg2->m_1c == 0, arg2);
        big_obj.SetValues(&sub2);
    }

    flag17 = arg2->m_1f != 0;
    if (arg2->m_1e)
    {
        flag17 = false;
    }

    {
        Sub3 sub3;
        sub3.f0 = arg2->hkpMoppCompilerInput_getRelativeFitToleranceOfInternalNodes();
        sub3.f1 = arg2->hkpMoppCompilerInput_getAbsoluteFitToleranceOfInternalNodes();
        sub3.f2 = arg2->hkpMoppCompilerInput_getAbsoluteFitToleranceOfTriangles();
        hkQuadReal tmp;
        ::D4F2A0Simd::_mm_store_ps((float*)&sub3.v, MoppBuildSimd::_mm_load_ps((const float*)arg2->GetValue(&tmp)));
        sub3.b24 = flag17;
        big_obj.CopyFromSourceData(&sub3);
    }

    {
        FUN_00dd50f0_Class sub1(0);
        if (arg2->m_1d)
        {
            sub1.m_08 = 0x32;
        }
        else
        {
            sub1.m_04 = 0;
            sub1.m_08 = 0;
        }
        sub1.m_0c = 5;
        sub1.m_14 = flag17;
        big_obj.AssignFromSource(&sub1);
    }

    int size = big_obj.ComputeRequiredSize(arg0);
    ::hkMemoryRouter* a = hkMemoryRouter_getInstance();
    buffer = ((StackAllocator*)a->m_temp)->allocate(size);

    FUN_00d549d0_Class struct4c;
    struct4c.m_00 = 0x200;
    struct4c.m_arr1_data = 0;
    struct4c.m_arr1_size = 0;
    struct4c.m_arr1_capacity = 0x80000000;
    struct4c.m_arr2_data = 0;
    struct4c.m_arr2_size = 0;
    struct4c.m_arr2_capacity = 0x80000000;
    struct4c.m_1c = 0;
    struct4c.m_20 = 0x14;

    if (arg2->m_1e)
    {
        big_obj.m_ptr4 = &struct4c;
    }

    ::hkBool prevWarning = DAT_01268360->isEnabled(0x7dd65995);
    hkError* error = DAT_01268360;
    error->setEnabled(0x7dd65995, false);

    void* retVal = big_obj.AllocateStorage_00dd4cb0(arg0, buffer, size);

    DAT_01268360->setEnabled(0x7dd65995, prevWarning);

    ::SearchObject* s3 = arg3;
    if (s3 != 0)
    {
        ReportResults(s3, struct4c.m_arr1_data, struct4c.m_arr1_size);
    }

    ::hkMemoryRouter* a2 = hkMemoryRouter_getInstance();
    ((StackAllocator*)a2->m_temp)->deallocate(buffer, size);

    struct4c.ClearArrays();
    big_obj.Object_DoNothing_00dd4b00();

    return retVal;
}
