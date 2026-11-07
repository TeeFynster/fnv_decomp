
// src/staging/blk_00c40000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#pragma pack(push, 4)
#include "../../include/MemoryManager.h"
#include "../../include/NiColor.h"
#include "../../include/NiColorA.h"
#include "../../include/NiRTTI.h"
#include "../../include/NiStream.h"
#include "../../include/NiTPrimitiveArray.h"
#include "../../include/NiTObjectArray.h"
#include "../../include/NiTListItem.h"
#include "../../include/NiTPointerList.h"
#include "../../include/BSSimpleArray.h"
#include "../../include/NiPointer.h"
#include "../../include/NiRefObject.h"
#include "../../include/GO.h"
#include "../../include/NiAVObject.h"
#include "../../include/NiObject.h"
#include "../../include/NiExtraData.h"
#include "../../include/NiIntegerExtraData.h"
#include "../../include/NiTriShape.h"
#include "../../include/RegSettingCollection.h"
#include "../../include/Setting.h"
#include "../../include/NiTimeController.h"
#include "../../include/NiUpdateData.h"
#include "../../include/BSFaceGenMorphData.h"
#include "../../include/BSPSysMultiTargetEmitterCtlr.h"
#include "../../include/NiPSysEmitterCtlr.h"
#include "../../include/BSBound.h"
#include "../../include/NiBinaryExtraData.h"
#include "../../include/NiStringExtraData.h"
#include "../../include/NiPSysModifier.h"
#include "../../include/NiMemObject.h"
#include "../../include/NiNode.h"
#include "../../include/NiPSysPositionModifier.h"
#include "../../include/NiBound.h"
#include "../../include/NiTransform.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiFrustum.h"


extern int DAT_010c1670;

struct FUN_00c40990_Class {
    void __thiscall SetVtableAndProcessState_00c40990();
};

// @fnv 0x00c40990
// src: GUESS 0x00c40990 (confidence: low)
void __thiscall FUN_00c40990_Class::SetVtableAndProcessState_00c40990()
{
    *(int*)this = (int)&DAT_010c1670;
}

struct FUN_00c42b60_class {
    int __thiscall CopyData_00c42b80();
    int a;
    int b;
    void ProcessEntries_00c42b60();
};

// @fnv 0x00c42b60
// src: GUESS 0x00c42b60 (confidence: low)
void FUN_00c42b60_class::ProcessEntries_00c42b60()
{
    while (*(int*)((char*)this + 0xc))
        CopyData_00c42b80();
}

void __cdecl EnsureArenaAllocated(void*);

struct FUN_00c42da0_Class {
    virtual void vfn_0000();
    virtual void vfn_0004();
};

// @fnv 0x00c42da0
// src: COMMUNITY 0x00c42da0
int __stdcall BSTaskThread_ThreadProc(FUN_00c42da0_Class* p)
{
    EnsureArenaAllocated((char*)p + 0x24);
    p->vfn_0004();
    return 0;
}

struct FUN_00c430a0_class
{
    int __thiscall BSXFlags_CreateClone(int);
};

// @fnv 0x00c430a0
// src: COMMUNITY 0x00c430a0
int __thiscall FUN_00c430a0_class::BSXFlags_CreateClone(int)
{
    return (int)this;
}

struct FUN_00c430b0_class {
    void __thiscall NiIntegerExtraData_CopyMembers(int a1, int a2);
    void __thiscall ForwardCall_00c430b0(int a1, int a2);
};

// @fnv 0x00c430b0
// src: GUESS 0x00c430b0 (confidence: low)
void __thiscall FUN_00c430b0_class::ForwardCall_00c430b0(int a1, int a2)
{
    NiIntegerExtraData_CopyMembers(a1, a2);
}

struct NiStream;
struct FUN_00c430d0 : public NiIntegerExtraData { void LoadBinary(NiStream&); };
// @fnv 0x00c430d0
void FUN_00c430d0::LoadBinary(NiStream& stream)
{
    NiIntegerExtraData::LoadBinary(stream);
}

// @fnv 0x00c430f0
// src: XBOX_PDB 0x00c430f0
void __thiscall NiBinaryExtraData::BSXFlags_LinkObject(NiAVObject* apObject)
{
    NiBinaryExtraData_LinkObject(apObject);
}

// Returns the negation of FUN_00a89ae0(arg).
// @fnv 0x00c43110
// src: XBOX_PDB 0x00c43110
bool NiBinaryExtraData::BSXFlags_RegisterStreamables(void* apData)
{
    return !RegisterStreamables_00a89ae0(apData);
}

struct FUN_00c43140_StandIn {
    void FUN_00a9a4e0(int a);
    void BSXFlags_SaveBinary(int a);
};

// @fnv 0x00c43140
// src: XBOX_PDB 0x00c43140
void FUN_00c43140_StandIn::BSXFlags_SaveBinary(int aiValue)
{
    FUN_00a9a4e0(aiValue);
}


bool NiStringExtraData::IsEqual(NiObject* other) const
{
    return 0;
}

// @fnv 0x00c43160
// src: XBOX_PDB 0x00c43160
char NiStringExtraData::BSXFlags_IsEqual(const char* other)
{
    char result = NiStringExtraData::IsEqual(reinterpret_cast<NiObject*>(const_cast<char*>(other)));
    return result;
}

struct NiFixedString;
extern NiFixedString* DAT_01202ddc;
// @fnv 0x00c43470
// src: XBOX_PDB 0x00c43470
void NiAVObject::BSXFlags_Init()
{
    SetName(*DAT_01202ddc);
}

extern "C" void* g_01202de0;

struct FUN_00c43650_Class {
    void* __thiscall BSXFlags_GetRTTI();
};

// @fnv 0x00c43650
// src: COMMUNITY 0x00c43650
void* __thiscall FUN_00c43650_Class::BSXFlags_GetRTTI()
{
    return &g_01202de0;
}


struct FUN_00c43900_class {
    void __thiscall BSValueNode_LinkObject(void* apParam);
};

// @fnv 0x00c43900
// src: XBOX_PDB 0x00c43900
void __thiscall FUN_00c43900_class::BSValueNode_LinkObject(void* apParam)
{
    ((NiNode*)this)->ReadChildListFromStream(apParam);
}

extern "C" void* g_01202de8;

struct FUN_00c43cf0_Class {
    void* __thiscall BSValueNode_GetRTTI();
};

// @fnv 0x00c43cf0
// src: COMMUNITY 0x00c43cf0
void* __thiscall FUN_00c43cf0_Class::BSValueNode_GetRTTI()
{
    return &g_01202de8;
}

struct FUN_00c43d60_cls {
    char pad[0x108];
    int m_pSelf;
    char InitSelfPointer(int a);
};

// @fnv 0x00c43d60
char FUN_00c43d60_cls::InitSelfPointer(int aiUnused)
{
    m_pSelf = (int)this;
    return 1;
}

extern "C" void __cdecl DoThreadShutdown(void*);

struct FUN_00c44940_Class {
    void __thiscall BSParallelTaskThread_OnShutdown();
};

// @fnv 0x00c44940
// src: XBOX_PDB 0x00c44940
void __thiscall FUN_00c44940_Class::BSParallelTaskThread_OnShutdown()
{
    DoThreadShutdown(this + 0x50);
}

struct FUN_00c44960_class {
    void __thiscall CallStoredCallback();
    void __thiscall BSParallelTaskThread_RunLinearTasks();
};

// @fnv 0x00c44960
// src: XBOX_PDB 0x00c44960
void __thiscall FUN_00c44960_class::BSParallelTaskThread_RunLinearTasks()
{
    ((FUN_00c44960_class**)((char*)this + 0x4c))[0]->CallStoredCallback();
}

struct FUN_00c44cb0_class {
    void* m0;
    void* m1;
    void* m2;
    void CallStoredCallback();
};

// @fnv 0x00c44cb0
void FUN_00c44cb0_class::CallStoredCallback()
{
    ((void (*)(void*))m1)(m2);
}

extern int DAT_010178bc;
void __cdecl UpdateFields_00c5faa0(void*);
struct FUN_00c44e20 {
    void UpdateFields_00c5faa0();
    ~FUN_00c44e20();
};
// @fnv 0x00c44e20
FUN_00c44e20::~FUN_00c44e20()
{
    *reinterpret_cast<int**>(this) = &DAT_010178bc;
    UpdateFields_00c5faa0();
}

struct FUN_00c452a0_Class {
    void __thiscall ReadChildListFromStream(int a);
    void __thiscall BSRangeNode_LinkObject(int a);
};

// @fnv 0x00c452a0
// src: XBOX_PDB 0x00c452a0
void __thiscall FUN_00c452a0_Class::BSRangeNode_LinkObject(int aiValue)
{
    ReadChildListFromStream(aiValue);
}

struct NiStream;

struct FUN_00a5e5b0_helper {
    unsigned char RegisterChildStreamables(NiStream*);
};

struct FUN_00c452c0_class {
    unsigned char BSRangeNode_RegisterStreamables(NiStream*);
};

// @fnv 0x00c452c0
// src: XBOX_PDB 0x00c452c0
unsigned char FUN_00c452c0_class::BSRangeNode_RegisterStreamables(NiStream* stream)
{
    if (!((FUN_00a5e5b0_helper*)this)->RegisterChildStreamables(stream))
        return 0;
    return 1;
}

extern char const* const g_01202e7c_arg1;

struct FUN_00c457d0_Class
{
    char const* const* __thiscall BSRangeNode_GetRTTI();
};

// @fnv 0x00c457d0
// src: COMMUNITY 0x00c457d0
char const* const* __thiscall FUN_00c457d0_Class::BSRangeNode_GetRTTI()
{
    return &g_01202e7c_arg1;
}

extern unsigned short DAT_01202e2c;

// @fnv 0x00c45ab0
// src: COMMUNITY 0x00c45ab0
bool NiObjectGarbage_IsEmpty()
{
    if (DAT_01202e2c)
        return false;
    return true;
}

struct NiStream;
// @fnv 0x00c467f0
// src: XBOX_PDB 0x00c467f0
void NiPSysModifier::BSWindModifier_LinkObject(NiStream& stream)
{
    NiPSysModifier::LinkObject(stream);
}

struct FUN_00c46810_Class {
    void __thiscall FUN_00c31670(int);
    void __thiscall BSWindModifier_RegisterStreamables(int);
};

// @fnv 0x00c46810
// src: XBOX_PDB 0x00c46810
void __thiscall FUN_00c46810_Class::BSWindModifier_RegisterStreamables(int aiValue)
{
    FUN_00c31670(aiValue);
}

// @fnv 0x00c46ca0
// src: XBOX_PDB 0x00c46ca0
void NiNode::BSMultiBoundNode_LoadBinary(NiStream& stream)
{
    NiNode::LoadBinary(stream);
    stream.ResetStreamState();
}

extern "C" void* g_01202e74;

struct FUN_00c47650_Class {
    void* __thiscall BSMultiBoundNode_GetRTTI();
};

// @fnv 0x00c47650
// src: COMMUNITY 0x00c47650
void* __thiscall FUN_00c47650_Class::BSMultiBoundNode_GetRTTI()
{
    return &g_01202e74;
}

struct P03MM { void* Allocate(unsigned int); void* AllocateScaled(unsigned int count); };
extern P03MM g_memoryManager;

// @fnv 0x00c4a860
void* P03MM::AllocateScaled(unsigned int count)
{
    void* result = g_memoryManager.Allocate(count * 100);
    return result;
}

namespace fnv_00c4a890 {
extern MemoryManager g_memoryManager;
struct FUN_00c4a890 { void __thiscall Deallocate(void* p); };
// @fnv 0x00c4a890
void __thiscall FUN_00c4a890::Deallocate(void* apMemory)
{
    g_memoryManager.Deallocate(apMemory);
}
}  // namespace fnv_00c4a890

namespace fnv_00c4a900 {
struct P03MM {
    void* Allocate(unsigned int);
    void* AllocateStorage_00c4a900(unsigned int a);
};
extern P03MM g_memoryManager;

// @fnv 0x00c4a900
// src: GUESS 0x00c4a900 (confidence: medium)
void* P03MM::AllocateStorage_00c4a900(unsigned int a)
{
    void* r = g_memoryManager.Allocate(a * 12);
    return r;
}
}  // namespace fnv_00c4a900

namespace fnv_00c4a930 {
extern MemoryManager g_memoryManager;

struct FUN_00c4a930_Class {
    void* __thiscall AllocateArray(void* oldPtr, unsigned int count);
};

// @fnv 0x00c4a930
void* __thiscall FUN_00c4a930_Class::AllocateArray(void* oldPtr, unsigned int count)
{
    return g_memoryManager.Reallocate(oldPtr, count * 0xc);
}
}  // namespace fnv_00c4a930

struct FUN_00c4aae0_class {
    void __thiscall CopyStateTo(int a, int b);
    void __thiscall BSRangeNode_CopyMembers(int a, int b);
};

// @fnv 0x00c4aae0
// src: XBOX_PDB 0x00c4aae0
void __thiscall FUN_00c4aae0_class::BSRangeNode_CopyMembers(int a, int b)
{
    CopyStateTo(a, b);
}

struct FUN_00c4ab40_class {
    void __thiscall BSRangeNode_LoadBinary(int);
    void __thiscall BSBlastNode_LoadBinary(int);
};

// @fnv 0x00c4ab40
// src: XBOX_PDB 0x00c4ab40
void __thiscall FUN_00c4ab40_class::BSBlastNode_LoadBinary(int aiValue)
{
    BSRangeNode_LoadBinary(aiValue);
}

struct FUN_00c452a0_class {
    void BSRangeNode_LinkObject(int a);
};

// src: XBOX_PDB 0x00c452a0
void FUN_00c452a0_class::BSRangeNode_LinkObject(int a)
{
}

struct FUN_00c4ab60_class {
    void BSBlastNode_LinkObject(int a);
};

// @fnv 0x00c4ab60
// src: XBOX_PDB 0x00c4ab60
void FUN_00c4ab60_class::BSBlastNode_LinkObject(int a)
{
    ((FUN_00c452a0_class*)this)->BSRangeNode_LinkObject(a);
}

struct FUN_00c4abb0_class {
    void BSRangeNode_SaveBinary(int);
    void BSBlastNode_SaveBinary(int a);
};

// @fnv 0x00c4abb0
// src: XBOX_PDB 0x00c4abb0
void FUN_00c4abb0_class::BSBlastNode_SaveBinary(int a)
{
    BSRangeNode_SaveBinary(a);
}

struct FUN_00c4abd0_class {
    char BSRangeNode_IsEqual(int);
    char BSBlastNode_IsEqual(int a1);
};

// Calls FUN_00c45380 with a1 and returns its result.
// @fnv 0x00c4abd0
// src: XBOX_PDB 0x00c4abd0
char FUN_00c4abd0_class::BSBlastNode_IsEqual(int a1)
{
    char result = BSRangeNode_IsEqual(a1);
    return result;
}

extern "C" void* g_01202e7c;

struct FUN_00c4ac90_Class {
    void* __thiscall BSBlastNode_GetRTTI();
};

// @fnv 0x00c4ac90
// src: COMMUNITY 0x00c4ac90
void* __thiscall FUN_00c4ac90_Class::BSBlastNode_GetRTTI()
{
    return &g_01202e7c;
}

struct FUN_00c4ad40_class {
    void __thiscall CopyStateTo(int, int);
    void __thiscall BSDebrisNode_CopyMembers(int a, int b);
};

// @fnv 0x00c4ad40
// src: XBOX_PDB 0x00c4ad40
void __thiscall FUN_00c4ad40_class::BSDebrisNode_CopyMembers(int a, int b)
{
    CopyStateTo(a, b);
}

extern "C" void __cdecl BSRangeNode_LoadBinary(int);

struct FUN_00c4ada0_Class {
    void __thiscall BSDebrisNode_LoadBinary(int a);
};

// @fnv 0x00c4ada0
// src: XBOX_PDB 0x00c4ada0
void __thiscall FUN_00c4ada0_Class::BSDebrisNode_LoadBinary(int a)
{
    ((void (__thiscall*)(void*, int))BSRangeNode_LoadBinary)(this, a);
}

namespace fnv_00c4adc0 {
struct FUN_00c4adc0_class {
    void __thiscall BSDebrisNode_LinkObject(int);
};

struct FUN_00c452a0_class {
    void __thiscall BSRangeNode_LinkObject(int);
};

// @fnv 0x00c4adc0
// src: XBOX_PDB 0x00c4adc0
void __thiscall FUN_00c4adc0_class::BSDebrisNode_LinkObject(int arg)
{
    ((FUN_00c452a0_class*)this)->BSRangeNode_LinkObject(arg);
}
}  // namespace fnv_00c4adc0

struct FUN_00c4ade0_class {
    unsigned char BSRangeNode_RegisterStreamables(int);
    unsigned char BSDebrisNode_RegisterStreamables(int);
};
// @fnv 0x00c4ade0
// src: XBOX_PDB 0x00c4ade0
unsigned char FUN_00c4ade0_class::BSDebrisNode_RegisterStreamables(int a)
{
    if (!BSRangeNode_RegisterStreamables(a))
        return 0;
    return 1;
}

struct FUN_00c4ae10_Class {
    void BSRangeNode_SaveBinary(int);
    void BSDebrisNode_SaveBinary(int a);
};

// @fnv 0x00c4ae10
// src: XBOX_PDB 0x00c4ae10
void FUN_00c4ae10_Class::BSDebrisNode_SaveBinary(int a)
{
    BSRangeNode_SaveBinary(a);
}

struct FUN_00c4ae30_class {
    unsigned char BSRangeNode_IsEqual(unsigned int a);
    unsigned char BSDebrisNode_IsEqual(unsigned int a);
};

// Calls FUN_00c45380 with a and returns its result.
// @fnv 0x00c4ae30
// src: XBOX_PDB 0x00c4ae30
unsigned char FUN_00c4ae30_class::BSDebrisNode_IsEqual(unsigned int a)
{
    unsigned char result = BSRangeNode_IsEqual(a);
    return result;
}

extern int g_01202e84;

struct FUN_00c4aef0_Class {
    int* __thiscall BSDebrisNode_GetRTTI();
};

// @fnv 0x00c4aef0
// src: COMMUNITY 0x00c4aef0
int* __thiscall FUN_00c4aef0_Class::BSDebrisNode_GetRTTI()
{
    return &g_01202e84;
}

struct FUN_00c4afa0_class {
    void __thiscall CopyStateTo(int a, int b);
    void __thiscall BSDamageStage_CopyMembers(int a, int b);
};

// @fnv 0x00c4afa0
// src: XBOX_PDB 0x00c4afa0
void __thiscall FUN_00c4afa0_class::BSDamageStage_CopyMembers(int aiArg1, int aiArg2)
{
    CopyStateTo(aiArg1, aiArg2);
}

struct FUN_00c4b000_class {
    void __thiscall BSRangeNode_LoadBinary(int);
    void __thiscall BSDamageStage_LoadBinary(int a);
};

// @fnv 0x00c4b000
// src: XBOX_PDB 0x00c4b000
void __thiscall FUN_00c4b000_class::BSDamageStage_LoadBinary(int aiValue)
{
    BSRangeNode_LoadBinary(aiValue);
}

struct FUN_00c4b020_Class {
    void __thiscall BSRangeNode_LinkObject(int);
    void __thiscall BSDamageStage_LinkObject(int a);
};

// @fnv 0x00c4b020
// src: XBOX_PDB 0x00c4b020
void __thiscall FUN_00c4b020_Class::BSDamageStage_LinkObject(int aiValue)
{
    BSRangeNode_LinkObject(aiValue);
}

namespace fnv_00c4b040 {
struct FUN_00c452c0_class {
    unsigned char BSRangeNode_RegisterStreamables(int);
    char IsNonZero(int a);
};

// src: XBOX_PDB 0x00c452c0
unsigned char FUN_00c452c0_class::BSRangeNode_RegisterStreamables(int a) { return (unsigned char)a; }

// Returns 1 when FUN_00c452c0(a) is non-zero, otherwise returns 0.
// @fnv 0x00c4b040
char FUN_00c452c0_class::IsNonZero(int aiValue)
{
    if (!BSRangeNode_RegisterStreamables(aiValue))
        return 0;
    return 1;
}
}  // namespace fnv_00c4b040

struct FUN_00c452f0_cls {
    void __thiscall BSRangeNode_SaveBinary(int a1);
};

// src: XBOX_PDB 0x00c452f0
void __thiscall FUN_00c452f0_cls::BSRangeNode_SaveBinary(int a1)
{
}

struct FUN_00c4b070_cls {
    void __thiscall BSDamageStage_SaveBinary(int a1);
};

// @fnv 0x00c4b070
// src: XBOX_PDB 0x00c4b070
void __thiscall FUN_00c4b070_cls::BSDamageStage_SaveBinary(int a1)
{
    ((FUN_00c452f0_cls*)this)->BSRangeNode_SaveBinary(a1);
}

struct GlobalObject_00a7b610;
extern GlobalObject_00a7b610 g_01202e8c;

struct FUN_00c4b210_Class {
    GlobalObject_00a7b610* BSDamageStage_GetRTTI();
};

// @fnv 0x00c4b210
// src: COMMUNITY 0x00c4b210
GlobalObject_00a7b610* FUN_00c4b210_Class::BSDamageStage_GetRTTI()
{
    return &g_01202e8c;
}

struct FUN_00c51550 { void __thiscall Copy(NiNode* a, void* b); };
// @fnv 0x00c51550
void __thiscall FUN_00c51550::Copy(NiNode* apNode, void* b)
{
    reinterpret_cast<NiNode*>(this)->NiNode::CopyMemberData(apNode, *static_cast<CloningProcess*>(b));
}

struct FUN_00c51570_Class {
    void* __thiscall NiNode_GetViewerStrings(void* arg);
    void* __thiscall BSParticleSystemManager_GetViewerStrings(void* arg);
};

// @fnv 0x00c51570
// src: XBOX_PDB 0x00c51570
void* __thiscall FUN_00c51570_Class::BSParticleSystemManager_GetViewerStrings(void* arg)
{
    return NiNode_GetViewerStrings(arg);
}

struct BaseT {
    ~BaseT();
};

struct FUN_00c516d0 : BaseT {
    void DoIt();
};

// @fnv 0x00c516d0
void FUN_00c516d0::DoIt()
{
    BaseT::~BaseT();
}

extern void* g_01203110;

struct FUN_00c516f0_Class {
    void* __thiscall BSParticleSystemManager_GetRTTI();
};

// @fnv 0x00c516f0
// src: COMMUNITY 0x00c516f0
void* __thiscall FUN_00c516f0_Class::BSParticleSystemManager_GetRTTI()
{
    return &g_01203110;
}

extern const char* const g_011df0c0_arg1;

struct FUN_00c52870_class
{
    const char* const* BSSceneGraph_GetRTTI();
};

// @fnv 0x00c52870
// src: COMMUNITY 0x00c52870
const char* const* FUN_00c52870_class::BSSceneGraph_GetRTTI()
{
    return &g_011df0c0_arg1;
}

struct FUN_00c54dc0_class {
    int __thiscall BSBound_CreateClone(int);
};
// @fnv 0x00c54dc0
// src: COMMUNITY 0x00c54dc0
int __thiscall FUN_00c54dc0_class::BSBound_CreateClone(int)
{
    return (int)this;
}

struct NiStream;
// @fnv 0x00c54e70
// src: XBOX_PDB 0x00c54e70
void BSBound::LinkObject_00c54e70(NiStream& stream)
{
    NiExtraData::LinkObject(stream);
}


// Returns the logical negation of FUN_00a7b290(arg).
// @fnv 0x00c54e90
// src: XBOX_PDB 0x00c54e90
int BSBound::RegisterStreamables_00c54e90(int arg)
{
    return !FUN_00a7b290(arg);
}

extern "C" void* g_012031e8;

struct FUN_00c55320_Class {
    void* __thiscall BSBound_GetRTTI();
};

// @fnv 0x00c55320
// src: COMMUNITY 0x00c55320
void* __thiscall FUN_00c55320_Class::BSBound_GetRTTI()
{
    return &g_012031e8;
}

struct FUN_00c5b5d0_class {
    unsigned int BSPortalGraph_GetAlwaysRenderArrayCount();
};

// @fnv 0x00c5b5d0
// src: COMMUNITY 0x00c5b5d0
unsigned int FUN_00c5b5d0_class::BSPortalGraph_GetAlwaysRenderArrayCount()
{
    return *(unsigned short*)((char*)this + 0x48);
}

struct NiStream;



// @fnv 0x00c5cc90
void BSPSysMultiTargetEmitterCtlr::LinkObject(NiStream& stream)
{
    NiPSysEmitterCtlr::LinkObject(stream);
}

struct NiStream;
struct FUN_00c1be10_shell {
    bool RegisterEmitterInterpolatorStreamables(NiStream&);
    char BSPSysMultiTargetEmitterCtlr_RegisterStreamables(NiStream&);
};
// @fnv 0x00c5ccb0
// src: XBOX_PDB 0x00c5ccb0
char FUN_00c1be10_shell::BSPSysMultiTargetEmitterCtlr_RegisterStreamables(NiStream& stream)
{
    if (!RegisterEmitterInterpolatorStreamables(stream))
        return 0;
    return 1;
}

extern int g_01203340;

struct FUN_00c5cea0_Class {
    int* __thiscall BSPSysMultiTargetEmitterCtlr_GetRTTI();
};

// @fnv 0x00c5cea0
// src: COMMUNITY 0x00c5cea0
int* __thiscall FUN_00c5cea0_Class::BSPSysMultiTargetEmitterCtlr_GetRTTI()
{
    return &g_01203340;
}

extern int DAT_010c2e7c;

struct FUN_00a744a0 {
    void* vtbl;
    FUN_00a744a0();
};

FUN_00a744a0::FUN_00a744a0()
{
}

struct FUN_00c5ceb0 : public FUN_00a744a0 {
    FUN_00c5ceb0();
};

// @fnv 0x00c5ceb0
FUN_00c5ceb0::FUN_00c5ceb0()
{
    vtbl = &DAT_010c2e7c;
}

extern "C" void __fastcall FUN_00a89760(void*);
extern int DAT_010c2e7c;

struct FUN_00c5cfb0 {
    virtual void vfn();
    void FUN_00a89760();
    ~FUN_00c5cfb0();
};

// @fnv 0x00c5cfb0
FUN_00c5cfb0::~FUN_00c5cfb0()
{
    FUN_00a89760();
}

struct Caller74690 {
    void FUN_00a74690(NiTPrimitiveArray<char*>*);
    void ForwardTo74690(NiTPrimitiveArray<char*>* p);
};

// @fnv 0x00c5d0f0
void Caller74690::ForwardTo74690(NiTPrimitiveArray<char*>* pStrArr)
{
    FUN_00a74690(pStrArr);
}

extern "C" void* g_01203348;

struct FUN_00c5d2a0_Class {
    void* __thiscall BSScissorTriShape_GetRTTI();
};

// @fnv 0x00c5d2a0
// src: COMMUNITY 0x00c5d2a0
void* __thiscall FUN_00c5d2a0_Class::BSScissorTriShape_GetRTTI()
{
    return &g_01203348;
}

struct FUN_00c5dcb0_class {
    void SetShortAtOffsetBA(short param);
};

// @fnv 0x00c5dcb0
void FUN_00c5dcb0_class::SetShortAtOffsetBA(short asValue)
{
    *(short*)((char*)this + 0xba) = asValue;
}

extern "C" void* g_0120436c;

struct FUN_00c5ec90_class
{
    void* __thiscall GetGlobalPtr();
};

// @fnv 0x00c5ec90
void* __thiscall FUN_00c5ec90_class::GetGlobalPtr()
{
    return &g_0120436c;
}

struct GlobalObject_00a7b610 {
    GlobalObject_00a7b610* __thiscall GetGlobalInstance();
};

extern GlobalObject_00a7b610 g_01204378;

// @fnv 0x00c5f560
GlobalObject_00a7b610* __thiscall GlobalObject_00a7b610::GetGlobalInstance()
{
    return &g_01204378;
}

namespace fnv_00c5f570 {
extern int DAT_010c31a4;


struct FUN_00c5f570 : NiNode {
    FUN_00c5f570();
};

// @fnv 0x00c5f570
FUN_00c5f570::FUN_00c5f570() : NiNode(0)
{
}
}  // namespace fnv_00c5f570

extern int DAT_010c31a4;
struct Unk_00a5e930 {
    void __thiscall UpdateFields_00c5faa0();
};
struct FUN_00c5faa0 {
    void UpdateFields_00c5faa0();
};
// @fnv 0x00c5faa0
// src: GUESS 0x00c5faa0 (confidence: low)
void FUN_00c5faa0::UpdateFields_00c5faa0()
{
    *reinterpret_cast<int**>(this) = &DAT_010c31a4;
    reinterpret_cast<Unk_00a5e930*>(this)->UpdateFields_00c5faa0();
}

extern const char* const g_01201f84_arg1;

struct FUN_00c5fc60_class {
    const char* const* BSNiNode_GetRTTI();
};

// @fnv 0x00c5fc60
// src: COMMUNITY 0x00c5fc60
const char* const* FUN_00c5fc60_class::BSNiNode_GetRTTI()
{
    return &g_01201f84_arg1;
}

// Original RTTI identifies this type as BSPSysStripUpdateModifier, derived from NiPSysModifier.
class BSPSysStripUpdateModifier : public NiPSysModifier {
public:
    BSPSysStripUpdateModifier();
    unsigned int unk18;
};
// @fnv 0x00c5fd30
BSPSysStripUpdateModifier::BSPSysStripUpdateModifier()
{
}

// @fnv 0x00c5fec0
// src: XBOX_PDB 0x00c5fec0
void __thiscall NiPSysModifier::BSPSysStripUpdateModifier_CopyMembers(NiPSysModifier* apDest, CloningProcess& apProcess)
{
    this->CopyMemberData(apDest, apProcess);
}

namespace fnv_00c5ff90 {
struct NiPSysModifierSub : NiPSysModifier {
    void BSPSysStripUpdateModifier_LinkObject(NiStream& stream);
};
// @fnv 0x00c5ff90
// src: XBOX_PDB 0x00c5ff90
void NiPSysModifierSub::BSPSysStripUpdateModifier_LinkObject(NiStream& stream)
{
    NiPSysModifier::LinkObject(stream);
}
}  // namespace fnv_00c5ff90

struct FUN_00c5ffb0_Class {
    void __thiscall FUN_00c31670(int param);
    void __thiscall BSPSysStripUpdateModifier_RegisterStreamables(int param);
};

// @fnv 0x00c5ffb0
// src: XBOX_PDB 0x00c5ffb0
void __thiscall FUN_00c5ffb0_Class::BSPSysStripUpdateModifier_RegisterStreamables(int param)
{
    FUN_00c31670(param);
}

extern int DAT_010c30b8;
void NiFreeAlias(void*);
struct FUN_00c5eb60_Class {
    int m0;
    int m1;
    void ResetAndFreeAlias();
};
// Stores the address of DAT_010c30b8 into m0, then frees m1 through NiFreeAlias.
// @fnv 0x00c5eb60
void FUN_00c5eb60_Class::ResetAndFreeAlias()
{
    m0 = (int)&DAT_010c30b8;
    void* alias = (void*)m1;
    NiFreeAlias(alias);
}

void __cdecl FUN_00c3f8c0();
struct FUN_00c40930_Class {
    void __thiscall FUN_00c3f8c0();
    void* __thiscall FUN_00c40930(unsigned int flags);
};
// @fnv 0x00c40930
void* __thiscall FUN_00c40930_Class::FUN_00c40930(unsigned int flags)
{
    FUN_00c3f8c0();
    if (flags & 1)
        ((MemoryManager*)&g_memoryManager)->Deallocate(this);
    return this;
}

namespace fnv_00c40960 {
struct FUN_00c40960_Class {
    void* __thiscall FUN_00c40960(int flags);
    void __thiscall FUN_00c3fa70();
};
// @fnv 0x00c40960
void* __thiscall FUN_00c40960_Class::FUN_00c40960(int flags)
{
    FUN_00c3fa70();
    if (flags & 1)
        reinterpret_cast<MemoryManager*>(&g_memoryManager)->Deallocate(this);
    return this;
}
}  // namespace fnv_00c40960

namespace fnv_00c409b0 {
struct FUN_00c409e0_Class {
    void __thiscall SetVirtualTable_00c409e0();
};
struct FUN_00c409b0_Class {
    void* __thiscall FUN_00c409b0(unsigned int flags);
};
// @fnv 0x00c409b0
void* __thiscall FUN_00c409b0_Class::FUN_00c409b0(unsigned int flags)
{
    ((FUN_00c409e0_Class*)this)->SetVirtualTable_00c409e0();
    if (flags & 1)
        ((MemoryManager*)&g_memoryManager)->Deallocate(this);
    return this;
}
}  // namespace fnv_00c409b0

namespace fnv_00c40a70 {
struct FUN_00c40a70_Class {
    void __thiscall FUN_00c40aa0();
    void* __thiscall FUN_00c40a70(unsigned int flags);
};
// @fnv 0x00c40a70
void* FUN_00c40a70_Class::FUN_00c40a70(unsigned int flags)
{
    FUN_00c40aa0();
    if (flags & 1)
        ((MemoryManager*)&g_memoryManager)->Deallocate(this);
    return this;
}
}  // namespace fnv_00c40a70

namespace fnv_00c40b40 {
struct FUN_00c40b40_class {
    int vtbl;
    FUN_00c40b40_class* __thiscall FUN_00c40b40(int a);
};
// Sets the vtable pointer, and if bit 0 of a is set, deallocates this object through g_memoryManager; returns this.
// @fnv 0x00c40b40
FUN_00c40b40_class* __thiscall FUN_00c40b40_class::FUN_00c40b40(int a)
{
    vtbl = (int)&DAT_010c1670;
    if (a & 1)
        reinterpret_cast<MemoryManager*>(&g_memoryManager)->Deallocate(this);
    return this;
}
}  // namespace fnv_00c40b40

void __cdecl SetVtableAndProcessState_00c43070(void*);
struct FUN_00c43620_Class {
    void __thiscall SetVtableAndProcessState_00c43070();
    void* __thiscall FUN_00c43620(unsigned int flags);
    static void __cdecl operator delete(void* p, unsigned int size);
};
// @fnv 0x00c43620
void* __thiscall FUN_00c43620_Class::FUN_00c43620(unsigned int flags)
{
    SetVtableAndProcessState_00c43070();
    if (flags & 1)
        operator delete(this, 16);
    return this;
}

struct FUN_00c43850_Class {
    void __thiscall ForwardToBase(void* dst, unsigned int size);
    void __thiscall BSNiNode_CopyMembers(void* dst, unsigned int size);
};
// @fnv 0x00c43850
// src: XBOX_PDB 0x00c43850
void __thiscall FUN_00c43850_Class::BSNiNode_CopyMembers(void* dst, unsigned int size)
{
    int v;
    ForwardToBase(dst, size);
    v = *(int*)((char*)this + 0xb0);
    *(int*)((char*)dst + 0xb0) = v;
    *(char*)((char*)dst + 0xac) = *(char*)((char*)this + 0xac);
}

extern "C" char* __cdecl _strchr(const char*, int);
extern "C" int __cdecl _strcpy_s(char*, unsigned int, const char*);
// @fnv 0x00c43da0
void __cdecl CopyMainNameFromPath(int param_1, char* pDest)
{
    const char* name = "MAIN";
    if (pDest) {
        const char* path = *(const char**)((char*)param_1 + 8);
        if (path) {
            const char* colon = _strchr(path, ':');
            if (colon) name = colon + 1;
        }
        _strcpy_s(pDest, 0x40, name);
    }
}

void __cdecl EnsureArenaAllocated(void*);
struct FUN_00c448f0_Class {
    char pad[0x50];
    int m50;
    int m54;
    int m58;
    void __thiscall BSParallelTaskThread_OnStartup();
};
// Zeroes m50 and m54, copies the int at offset 0x24 into m58, then calls EnsureArenaAllocated with &m50.
// @fnv 0x00c448f0
// src: XBOX_PDB 0x00c448f0
void __thiscall FUN_00c448f0_Class::BSParallelTaskThread_OnStartup()
{
    m50 = 0;
    m54 = 0;
    int tmp = *(int*)((char*)this + 0x24);
    m58 = tmp;
    EnsureArenaAllocated(&m50);
}

struct FUN_00c44cd0_class {
    void __thiscall BSParallelTaskManager_StartThreads();
    void __thiscall WaitForWorkers();
};
struct FUN_00c44c40_class {
    void __thiscall BSParallelTaskManager_RunTask_0(int a1, int a2);
};
// Stores a1 and a2 into fields at offsets 4 and 8, sets the byte at 0xc, then calls FUN_00c44cd0, CallStoredCallback and WaitForWorkers before clearing the byte at 0xc.
// @fnv 0x00c44c40
// src: COMMUNITY 0x00c44c40
void __thiscall FUN_00c44c40_class::BSParallelTaskManager_RunTask_0(int a1, int a2)
{
    *(char*)((char*)this + 0xc) = 1;
    *(int*)((char*)this + 4) = a1;
    *(int*)((char*)this + 8) = a2;
    ((FUN_00c44cd0_class*)this)->BSParallelTaskManager_StartThreads();
    ((FUN_00c44cb0_class*)this)->CallStoredCallback();
    ((FUN_00c44cd0_class*)this)->WaitForWorkers();
    *(char*)((char*)this + 0xc) = 0;
}

namespace fnv_00c44df0 {
extern MemoryManager _g_memoryManager;
struct FUN_00c44df0_class {
    void __thiscall FUN_008c77c0();
    void* __thiscall FUN_00c44df0(unsigned int flags);
};
// @fnv 0x00c44df0
void* FUN_00c44df0_class::FUN_00c44df0(unsigned int flags)
{
    FUN_008c77c0();
    if (flags & 1)
        _g_memoryManager.Deallocate(this);
    return this;
}
}  // namespace fnv_00c44df0

struct FUN_00c455a0_Class {
    void __thiscall BSRangeNode_SetCurrent(unsigned char);
};
struct FUN_00c5fb60_Class {
    void __thiscall ForwardToBase(int a, int b);
};
struct FUN_00c451b0_class {
    void __thiscall CopyStateTo(int a, int b);
};
// @fnv 0x00c451b0
void __thiscall FUN_00c451b0_class::CopyStateTo(int pTarget, int b)
{
    ((FUN_00c5fb60_Class*)this)->ForwardToBase(pTarget, b);
    char c3 = *(char*)((char*)this + 0xae);
    *(char*)(pTarget + 0xae) = c3;
    char c1 = *(char*)((char*)this + 0xaf);
    *(char*)(pTarget + 0xaf) = c1;
    unsigned char c2 = *(unsigned char*)((char*)this + 0xad);
    ((FUN_00c455a0_Class*)pTarget)->BSRangeNode_SetCurrent(c2);
}

extern int DAT_011af758;
// @fnv 0x00c45820
// src: COMMUNITY 0x00c45820
void NiObjectGarbage_Init(int value)
{
    DAT_011af758 = value;
}

// @fnv 0x00c45ad0
// src: COMMUNITY 0x00c45ad0
int NiObjectGarbage_GetCount()
{
    return DAT_01202e2c;
}

extern unsigned short DAT_01202e2e;

// @fnv 0x00c45b10
// src: COMMUNITY 0x00c45b10
void __cdecl NiObjectGarbage_SetIncreaseSize(unsigned short value)
{
    DAT_01202e2e = value;
}

struct CloningProcess;
// The constructor at 0x00c465a0 installs BSWindModifier RTTI; CopyModifier copies its strength at +0x18.
struct BSWindModifier : public NiPSysModifier {
    float fStrength;
    void __thiscall CopyModifier(BSWindModifier* dst, CloningProcess& proc);
};
// @fnv 0x00c46700
void __thiscall BSWindModifier::CopyModifier(BSWindModifier* dst, CloningProcess& proc)
{
    this->CopyMemberData(dst, proc);
    float f = this->fStrength;
    dst->fStrength = f;
}

struct SStream;
struct SObj;
void __cdecl CallAnimCallback(SStream*, SObj*);
struct FUN_00c46830_class {
    void __thiscall FUN_00c31950(NiStream* stream);
    void __thiscall Load(NiStream* stream);
};
// Calls FUN_00c31950 on the stream, then CallAnimCallback with the stream and the object at this+0x18.
// @fnv 0x00c46830
void __thiscall FUN_00c46830_class::Load(NiStream* stream)
{
    FUN_00c31950(stream);
    CallAnimCallback(reinterpret_cast<SStream*>(stream), reinterpret_cast<SObj*>(this + 0x18));
}

void* __cdecl FUN_00ec7230(char* dst, const char* src, unsigned int size);
struct FUN_00c4a640_class {
    void __thiscall BSSimpleArray_NiFrustumPlanes_1024_CopyItems(char* dst, char* src, unsigned int count);
};
// @fnv 0x00c4a640
// src: COMMUNITY 0x00c4a640
void __thiscall FUN_00c4a640_class::BSSimpleArray_NiFrustumPlanes_1024_CopyItems(char* dst, char* src, unsigned int count)
{
    if (count <= 0)
        return;
    if (dst < src) {
        for (unsigned int i = 0; i < count; i++)
            FUN_00ec7230(dst + i * 100, src + i * 100, 100);
    } else if (dst > src) {
        for (int i = (int)count - 1; i >= 0; i--)
            FUN_00ec7230(dst + i * 100, src + i * 100, 100);
    }
}

namespace fnv_00c4a990 {
extern P03MM g_memoryManager;
void __cdecl FUN_00c4a8e0(void*);
struct FUN_00c4a990_class {
    void __thiscall FUN_00c4a8e0();
    void* __thiscall FUN_00c4a990(unsigned int flags);
};
// @fnv 0x00c4a990
void* FUN_00c4a990_class::FUN_00c4a990(unsigned int flags)
{
    FUN_00c4a8e0();
    if (flags & 1)
        ((MemoryManager*)&g_memoryManager)->Deallocate(this);
    return this;
}
}  // namespace fnv_00c4a990

extern "C" void* g_01202e7c;
extern "C" void* __cdecl NiViewerStrings_NiGetViewerString_Title(void*);
struct FUN_00c4ab00_Class {
    void __thiscall BSRangeNode_GetViewerStrings(int);
    void __thiscall BSBlastNode_GetViewerStrings(int a);
};
// @fnv 0x00c4ab00
// src: XBOX_PDB 0x00c4ab00
void __thiscall FUN_00c4ab00_Class::BSBlastNode_GetViewerStrings(int pArray)
{
    void* v;
    unsigned int x8;
    int pad1;
    int pad2;
    int pad3;
    int pad4;
    BSRangeNode_GetViewerStrings(pArray);
    v = g_01202e7c;
    x8 = (unsigned int)NiViewerStrings_NiGetViewerString_Title(v);
    ((NiTPrimitiveArray<unsigned int>*)pArray)->AddFirstEmpty(x8);
}

struct FUN_00c4f2d0_class {
    void __thiscall BSCullingProcess_PopCullMode();
};
// Decrements the counter at offset 0xbc, reads the item at that index from the array at 0x94, and stores it at 0x90.
// @fnv 0x00c4f2d0
// src: COMMUNITY 0x00c4f2d0
void __thiscall FUN_00c4f2d0_class::BSCullingProcess_PopCullMode()
{
    *(int*)((char*)this + 0xbc) = *(int*)((char*)this + 0xbc) - 1;
    int item = *(int*)((char*)this + 0x94 + *(int*)((char*)this + 0xbc) * 4);
    *(int*)((char*)this + 0x90) = item;
}

struct FUN_00c5dcd0_Class {
    void __thiscall BSMasterParticleSystem_AddEmitterObj(void* a);
};
struct FUN_00c50f30_Class {
    FUN_00c5dcd0_Class* __thiscall GetEntryValue(int a);
};
struct FUN_00c505c0_Class {
    void __thiscall BSParticleSystemManager_AddEmitter(int a, void* b);
};
void __cdecl FNV_Warning(const char* fmt, ...);
// @fnv 0x00c505c0
// src: XBOX_PDB 0x00c505c0
void FUN_00c505c0_Class::BSParticleSystemManager_AddEmitter(int aiIndex, void* pEmitter)
{
    FUN_00c5dcd0_Class* p = reinterpret_cast<FUN_00c50f30_Class*>(this)->GetEntryValue(aiIndex);
    if (p)
        p->BSMasterParticleSystem_AddEmitterObj(pEmitter);
    else {
        void* s = *(void**)((char*)pEmitter + 8);
        FNV_Warning("DEFAULT: Trying to add an emitter (%s) to a master particle system (idx: %d) that hasn't been loaded.", s, aiIndex);
    }
}

struct FUN_00c50f30_class {
    int __thiscall GetEntryValue(int a);
};

// @fnv 0x00c50f30
int __thiscall FUN_00c50f30_class::GetEntryValue(int aiIndex)
{
    int r = 0;
    if (aiIndex < *(unsigned int*)(this + 0xb0)) {
        int v = ((int*)*(void**)(this + 0xac))[aiIndex];
        if (v != -1) {
            int* p = (int*)(*(void**)(this + 0xa0)) + v;
            int t = *p;
            r = t;
        }
    }
    return r;
}

extern int DAT_0106c814;
extern int DAT_010c256c;
struct FUN_00c51640_Class {
    const char* s;
    int i;
    unsigned char b;
    int d;
    unsigned char c;
    int p;
    void* __thiscall UpdateMasterPsysTaskletData_UpdateMasterPsysTaskletData();
};
// Initializes the object's fields: clears the byte at offset 4, the int at offset 8, sets the byte at 0xc to 1, and clears the int at 0x10.
// @fnv 0x00c51640
// src: COMMUNITY 0x00c51640
void* __thiscall FUN_00c51640_Class::UpdateMasterPsysTaskletData_UpdateMasterPsysTaskletData()
{
    s = (const char*)&DAT_0106c814;
    *(unsigned char*)((char*)this + 4) = 0;
    s = "@yl";
    *(int*)((char*)this + 8) = 0;
    *(unsigned char*)((char*)this + 0xc) = 1;
    int* q = (int*)((char*)this + 0x10);
    *q = 0;
    s = (const char*)&DAT_010c256c;
    return this;
}

struct FUN_00878690_shell {
    void __thiscall FUN_00c51df0();
};
void __cdecl operator delete(void* ptr, unsigned int size);
struct FUN_00c52830_class {
    void* __thiscall FUN_00c52830(unsigned int flags);
};
// @fnv 0x00c52830
void* __thiscall FUN_00c52830_class::FUN_00c52830(unsigned int flags)
{
    reinterpret_cast<FUN_00878690_shell*>(this)->FUN_00c51df0();
    if (flags & 1)
        operator delete(this, 0xc0);
    return this;
}

namespace fnv_00c54d70 {
extern MemoryManager _g_memoryManager;
extern int DAT_010c2b2c;
struct FUN_00c54d70_class {
    int* vtbl;
    void* data;
    FUN_00c54d70_class* __thiscall FUN_00c54d70(unsigned int flags);
};
// Sets the vtable pointer, deallocates the data pointer, and if flags has bit 0 set, deallocates this object.
// @fnv 0x00c54d70
FUN_00c54d70_class* __thiscall FUN_00c54d70_class::FUN_00c54d70(unsigned int flags)
{
    vtbl = &DAT_010c2b2c;
    void* tmp2 = data;
    void* tmp = tmp2;
    _g_memoryManager.Deallocate(tmp);
    if (flags & 1)
        _g_memoryManager.Deallocate(this);
    return this;
}
}  // namespace fnv_00c54d70

struct NiStream;
struct FUN_00c54ec0_class {
    void __thiscall BSBound_SaveBinary(NiStream& stream);
};
// Saves the extra data helper and two NiColor members at offsets 0xc and 0x18 to the stream.
// @fnv 0x00c54ec0
// src: XBOX_PDB 0x00c54ec0
void __thiscall FUN_00c54ec0_class::BSBound_SaveBinary(NiStream& stream)
{
    ((NiExtraData*)this)->NiExtraData::SaveBinary(stream);
    ((NiColor*)((char*)this + 0xc))->SaveBinary(stream);
    ((NiColor*)((char*)this + 0x18))->SaveBinary(stream);
}

struct FUN_00c55330_class {
    void* __thiscall FUN_00c55330(unsigned int flags);
    void operator delete(void* p, unsigned int size);
};
// @fnv 0x00c55330
void* __thiscall FUN_00c55330_class::FUN_00c55330(unsigned int flags)
{
    reinterpret_cast<NiExtraData*>(this)->DestroyFields_00a7b300();
    if (flags & 1)
        operator delete(this, 0x24);
    return this;
}

namespace fnv_00c5bae0 {
extern "C" void __cdecl operator delete(void*, unsigned int);

struct FUN_00c5ac00_class {
    void __thiscall FUN_00c5ac00();
    void* __thiscall FUN_00c5bae0(unsigned int flags);
};

// Calls FUN_00c5ac00, then frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00c5bae0
void* __thiscall FUN_00c5ac00_class::FUN_00c5bae0(unsigned int flags)
{
    FUN_00c5ac00();
    if (flags & 1)
        operator delete(this, 0x78);
    return this;
}
}  // namespace fnv_00c5bae0

extern int DAT_010c2d54;
struct FUN_00c1c280_class {
    void __thiscall FUN_00c1c280(int a);
};
struct FUN_00c5c3c0_class : FUN_00c1c280_class {
    int __thiscall InitWithParams(int a, int b, unsigned short c);
};
// @fnv 0x00c5c3c0
int __thiscall FUN_00c5c3c0_class::InitWithParams(int aiArg, int aiValue, unsigned short ausValue)
{
    FUN_00c1c280(aiArg);
    *(int*)this = (int)&DAT_010c2d54;
    *(int*)(this + 0x5c) = aiValue;
    *(unsigned short*)(this + 0x60) = ausValue;
    return (int)this;
}

extern int DAT_010c2d54;
struct FUN_00c1c390_Class {
    void __thiscall FUN_00c1c390();
};
struct FUN_00c5c400_Class : FUN_00c1c390_Class {
    void* vtbl;
    char pad[0x5c - 4];
    int m_0x5c;
    unsigned short m_0x60;
    FUN_00c5c400_Class* __thiscall SetVirtualTableAndProcessState_00c5c400();
};
// @fnv 0x00c5c400
// src: GUESS 0x00c5c400 (confidence: low)
FUN_00c5c400_Class* __thiscall FUN_00c5c400_Class::SetVirtualTableAndProcessState_00c5c400()
{
    FUN_00c1c390_Class::FUN_00c1c390(); vtbl = (void*)&DAT_010c2d54; m_0x5c = 0; m_0x60 = 0; return this; }

struct NiStream;
void __cdecl NiStreamSaveBinary_unsigned_short(NiStream&, unsigned short*);
struct S_00c1be40 {
    void FUN_00c1be40(NiStream& stream);
};
struct FUN_00c5cce0_Class {
    char pad[0x5c];
    int m_0x5c;
    void __thiscall BSPSysMultiTargetEmitterCtlr_SaveBinary(NiStream& stream);
};
// @fnv 0x00c5cce0
// src: XBOX_PDB 0x00c5cce0
void __thiscall FUN_00c5cce0_Class::BSPSysMultiTargetEmitterCtlr_SaveBinary(NiStream& stream)
{
    ((S_00c1be40*)this)->FUN_00c1be40(stream);
    NiStreamSaveBinary_unsigned_short(stream, (unsigned short*)((char*)this + 0x60));
    ((void (__thiscall*)(NiStream*, int))*((void***)*(void**)&stream + 12))(&stream, m_0x5c);
}

struct FUN_00c1be60_StandIn {
    unsigned char __thiscall NiPSysEmitterCtlr_IsEqual(void*);
    char BSPSysMultiTargetEmitterCtlr_IsEqual(void* other);
};
// @fnv 0x00c5cd20
// src: XBOX_PDB 0x00c5cd20
char FUN_00c1be60_StandIn::BSPSysMultiTargetEmitterCtlr_IsEqual(void* other)
{
    if (!NiPSysEmitterCtlr_IsEqual(other))
        return 0;
    void* p = other;
    if (*(int*)((char*)this + 0x5c) == *(int*)((char*)p + 0x5c) &&
        *(unsigned short*)((char*)this + 0x60) == *(unsigned short*)((char*)p + 0x60))
        return 1;
    else
        return 0;
}

namespace fnv_00c5ce10 {
extern "C" void __cdecl operator delete(void*, unsigned int);
struct FUN_00c5ce10_Class {
    void __thiscall Constructor();
    void* __thiscall FUN_00c5ce10(unsigned int a);
};
// Calls Constructor on this, deletes this with size 0x64 when bit 0 of a is set, and returns this.
// @fnv 0x00c5ce10
void* FUN_00c5ce10_Class::FUN_00c5ce10(unsigned int uiFlags)
{
    this->Constructor();
    if (uiFlags & 1)
        operator delete(this, 0x64);
    return this;
}
}  // namespace fnv_00c5ce10

struct FUN_00c5ced0 : FUN_00a744a0 {
    FUN_00c5ced0(int a, int b, int c, int d);
};
// Sets the vtable pointer and stores the four constructor arguments at offsets 0xc4, 0xc8, 0xcc and 0xd0.
// @fnv 0x00c5ced0
FUN_00c5ced0::FUN_00c5ced0(int a, int b, int c, int d)
{
    *(int**)((char*)this + 0) = (int*)&DAT_010c2e7c;
    *(int*)((char*)this + 0xc4) = a;
    *(int*)((char*)this + 0xc8) = b;
    *(int*)((char*)this + 0xcc) = c;
    *(int*)((char*)this + 0xd0) = d;
}

struct FUN_00c5cfd0_class {
    void __thiscall UpdateState_00c5cfd0(int a, int b, int c, int d);
};
// Stores the four int arguments into the object's fields at offsets 0xc4, 0xc8, 0xcc and 0xd0.
// @fnv 0x00c5cfd0
// src: GUESS 0x00c5cfd0 (confidence: low)
void __thiscall FUN_00c5cfd0_class::UpdateState_00c5cfd0(int a, int b, int c, int d)
{
    *(int*)((char*)this + 0xc4) = a;
    *(int*)((char*)this + 0xc8) = b;
    *(int*)((char*)this + 0xcc) = c;
    *(int*)((char*)this + 0xd0) = d;
}

extern "C" void __cdecl BSAttachPoints_InitSDM();
extern "C" void __cdecl BSBound_InitSDM();
extern "C" void __cdecl BSFurnitureMarker_InitSDM();
extern "C" void __cdecl PArrayPoint_InitSDM();
extern "C" void __cdecl BSTextureData_InitSDM();
extern "C" void __cdecl BSWArray_InitSDM();
extern "C" void __cdecl BSXFlags_InitSDM();
extern "C" unsigned char DAT_01204364;

// @fnv 0x00c5d4e0
// src: COMMUNITY 0x00c5d4e0
void __cdecl BSMain_InitSDM()
{
    if (!DAT_01204364) {
        BSAttachPoints_InitSDM();
        BSBound_InitSDM();
        BSFurnitureMarker_InitSDM();
        PArrayPoint_InitSDM();
        BSTextureData_InitSDM();
        BSWArray_InitSDM();
        BSXFlags_InitSDM();
        DAT_01204364 = 1;
    }
}

extern unsigned char DAT_01204364;
void __cdecl Runtime_ReleaseStorage_00c655d0();
void __cdecl Object_UpdateFields_00c552a0();
void __cdecl Object_UpdateFields_00c54760();
void __cdecl Runtime_ReleaseReference_00c61990();
void __cdecl Object_UpdateFields_00c5f2e0();
void __cdecl Object_UpdateFields_00c61760();
void __cdecl Object_UpdateFields_00c435a0();

// @fnv 0x00c5d520
// src: GUESS 0x00c5d520 (confidence: low)
void __cdecl Object_UpdateFields_00c5d520()
{
    if (DAT_01204364) {
        Runtime_ReleaseStorage_00c655d0();
        Object_UpdateFields_00c552a0();
        Object_UpdateFields_00c54760();
        Runtime_ReleaseReference_00c61990();
        Object_UpdateFields_00c5f2e0();
        Object_UpdateFields_00c61760();
        Object_UpdateFields_00c435a0();
        DAT_01204364 = 0;
    }
}

struct FUN_00c5dea0_Entry {
    unsigned char mFlag;
};
struct FUN_00c5dea0_Class {
    int* pData;
    unsigned short mCount;
    void __thiscall BSMasterParticleSystem_ResetSystems();
};
// Iterates the entries in the array at offset 0xd0 up to the count at 0xd6 and sets byte 0xd8 to 1 on each non-null entry.
// @fnv 0x00c5dea0
// src: COMMUNITY 0x00c5dea0
void __thiscall FUN_00c5dea0_Class::BSMasterParticleSystem_ResetSystems()
{
    unsigned int count = *(unsigned short*)((char*)this + 0xd6);
    for (unsigned int i = 0; i < count; i++) {
        FUN_00c5dea0_Entry* e = (FUN_00c5dea0_Entry*)((*(int**)((char*)this + 0xd0))[i]);
        if (e)
            ((unsigned char*)e)[0xd8] = 1;
    }
}

struct FUN_00c5e560_class {
    void __thiscall NiNode_CopyMembers(NiNode* a, void* b);
};
// @fnv 0x00c5e560
// src: XBOX_PDB 0x00c5e560
void __thiscall FUN_00c5e560_class::NiNode_CopyMembers(NiNode* pNode, void* b)
{
    reinterpret_cast<NiNode*>(this)->NiNode::CopyMemberData(pNode, *static_cast<CloningProcess*>(b));
    *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(pNode) + 0xba) =
        *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(this) + 0xba);
}

struct FUN_00c5db90_Class {
    void __thiscall FUN_00c5db90();
};
void __cdecl operator delete(void* p, unsigned int size);
struct FUN_00c5eb20_Class {
    void* __thiscall FUN_00c5eb20(unsigned int flags);
};
// @fnv 0x00c5eb20
void* __thiscall FUN_00c5eb20_Class::FUN_00c5eb20(unsigned int flags)
{
    ((FUN_00c5db90_Class*)this)->FUN_00c5db90();
    if (flags & 1) operator delete(this, 0xe0);
    return this;
}

namespace fnv_00c5eca0 {
extern int DAT_010c30b8;
extern "C" void __cdecl NiFree(void*);
struct P03MM_Deallocate {
    void __thiscall Deallocate(void*);
};
struct FUN_00c5eca0_Class {
    int* __thiscall FUN_00c5eca0(int arg);
};
// @fnv 0x00c5eca0
int* __thiscall FUN_00c5eca0_Class::FUN_00c5eca0(int aiFlags)
{
    int* result;
    *(int*)this = (int)&DAT_010c30b8;
    result = *(int**)((char*)this + 4);
    NiFree(result);
    if (aiFlags & 1)
        ((P03MM_Deallocate*)&g_memoryManager)->Deallocate(this);
    return (int*)this;
}
}  // namespace fnv_00c5eca0

void __cdecl operator delete(void* p, unsigned int size);

struct FUN_00c5ed60_Class {
    void __thiscall FUN_00c5ed60();
};

struct FUN_00c5f360_Class {
    void* __thiscall FUN_00c5f360(unsigned int flags);
};

// Calls FUN_00c5ed60 on this, then deletes this with size 0x1c if flags has bit 0 set, and returns this.
// @fnv 0x00c5f360
void* __thiscall FUN_00c5f360_Class::FUN_00c5f360(unsigned int flags)
{
    ((FUN_00c5ed60_Class*)this)->FUN_00c5ed60();
    if (flags & 1)
        operator delete(this, 0x1c);
    return this;
}

struct FUN_00c5f390_class {
    void __thiscall BSSimpleArray_enum_hkpConstraintData_ConstraintType_1024_SetSize(int a, int b);
};
struct FUN_00c5f500_class {
    void __thiscall BSSimpleArray_NiAVObject_1024_CopyTo_1024(FUN_00c5f500_class* other);
    int pad;
    int* data;
    unsigned int count;
};
// Calls FUN_00c5f390 on other with count and 1, then copies count elements from data into other->data.
// @fnv 0x00c5f500
// src: XBOX_PDB 0x00c5f500
void __thiscall FUN_00c5f500_class::BSSimpleArray_NiAVObject_1024_CopyTo_1024(FUN_00c5f500_class* other)
{
    ((FUN_00c5f390_class*)other)->BSSimpleArray_enum_hkpConstraintData_ConstraintType_1024_SetSize(count, 1);
    for (unsigned int i = 0; i < count; ++i)
        other->data[i] = data[i];
}

struct FUN_00c5fc20_class {
    void* __thiscall FUN_00c5fc20(unsigned int flags);
    void __cdecl operator delete(void* p, unsigned int size);
    void __thiscall FUN_00c5faa0();
};
// Calls FUN_00c5faa0, then frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00c5fc20
void* __thiscall FUN_00c5fc20_class::FUN_00c5fc20(unsigned int flags)
{
    FUN_00c5faa0();
    if (flags & 1)
        operator delete(this, 0xac);
    return this;
}

struct BaseForCall { bool NiNode_IsEqual(NiObject*); };
struct FUN_00c439b0_class : BaseForCall {
    char BSValueNode_IsEqual(NiObject* apParam);
};
// Calls FUN_00a5e600 on apParam; if true, returns whether this and apParam have equal p and byte at 0xac.
// @fnv 0x00c439b0
// src: XBOX_PDB 0x00c439b0
char FUN_00c439b0_class::BSValueNode_IsEqual(NiObject* apParam)
{
    bool result2 = NiNode_IsEqual(apParam);
    if (result2) {
        NiObject* localParam2 = apParam;
        int localOther3 = *(int*)((char*)this + 0xb0);
        int localThis = *(int*)((char*)localParam2 + 0xb0);
        result2 = (localOther3 == localThis && ((unsigned char*)this)[0xac] == ((unsigned char*)localParam2)[0xac]) ? 1 : 0;
    }
    return result2;
}

// Copy-assigns the held NiRefObject pointer, releasing the old one and incrementing the new one's reference count.
// @fnv 0x00c46270
template <>
NiPointer<NiRefObject>& NiPointer<NiRefObject>::operator=(const NiPointer<NiRefObject>& other)
{
    if (m_pObject != other.m_pObject)
    {
        if (m_pObject)
        {
            NiRefObject* object = m_pObject;
            if (InterlockedDecrement((volatile long*)&object->m_uiRefCount) == 0)
                object->DeleteThis();
        }
        m_pObject = other.m_pObject;
        if (m_pObject)
        {
            NiRefObject* object = m_pObject;
            InterlockedIncrement((volatile long*)&object->m_uiRefCount);
        }
    }
    return *this;
}

extern GlobalObject_00a7b610 g_01202e60;

struct FUN_00c46960_Class {
    GlobalObject_00a7b610* BSWindModifier_GetRTTI();
};

// @fnv 0x00c46960
// src: COMMUNITY 0x00c46960
GlobalObject_00a7b610* FUN_00c46960_Class::BSWindModifier_GetRTTI()
{
    return &g_01202e60;
}

struct Elem_00c48a10 { int p; int a; int b; };
struct Arr_00c48a10 {
    int _0;
    Elem_00c48a10* m_pData;
    int _8;
    int m_iCapacity;
    void FUN_00c4a1e0(int, bool);
};
struct FUN_00c48a10_t {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    Arr_00c48a10 m_kArray;
    int _24;
    int m_iArrayLength;
    void ShiftElements(int iDelta, bool bClear);
};

// @fnv 0x00c48a10
void FUN_00c48a10_t::ShiftElements(int iDelta, bool bClear)
{
    int i;
    int j;
    int iNegShift;
    int iShift;
    if (iDelta > 0)
    {
        iShift = iDelta;
        int iCap = m_kArray.m_iCapacity;
        if (m_iArrayLength + iShift >= iCap)
        {
            int iOldCap;
            m_kArray.FUN_00c4a1e0((iOldCap = m_kArray.m_iCapacity) + (iShift > 10 ? iShift : 10), true);
        }
        i = 0;
        for (i = m_iArrayLength + iShift - 1; i >= iShift; i--)
        {
            Elem_00c48a10* pSrc = &m_kArray.m_pData[i - iShift];
            m_kArray.m_pData[i].p = pSrc->p;
        }
        if (bClear)
        {
            for (; i > 0; i--)
                m_kArray.m_pData[i].p = 0;
        }
        m_iArrayLength += iShift;
    }
    else if (iDelta < 0)
    {
        iNegShift = -iDelta;
        if (m_iArrayLength > iNegShift)
        {
            for (j = 0; j < m_iArrayLength - iNegShift; j++)
            {
                Elem_00c48a10* pSrc2 = &m_kArray.m_pData[j + iNegShift];
                m_kArray.m_pData[j].p = pSrc2->p;
            }
            m_iArrayLength -= iNegShift;
        }
        else
        {
            m_iArrayLength = 0;
        }
    }
}

struct FUN_00c4a9c0_class {
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08(void*);
    void* m_p;
    unsigned int m_uiItemCount;
    int m_auiShapeKeys;
    void __thiscall ReleaseBuffer(unsigned char a);
};
// @fnv 0x00c4a9c0
void __thiscall FUN_00c4a9c0_class::ReleaseBuffer(unsigned char a)
{
    if (m_p) {
        for (int i = 0; i < m_uiItemCount; ++i) {
        }
        if (a) {
            vfn_08(m_p);
            m_p = 0;
            m_p = 0;
            m_auiShapeKeys = 0;
        }
        m_uiItemCount = 0;
    }
}

void* __cdecl NiMalloc(unsigned int);

class NiParticles;

// @fnv 0x00c5ec10
template <>
NiTArray<NiParticles*, NiTMallocInterface<NiParticles*> >::NiTArray(unsigned int ausCount, unsigned int b)
{
    m_usMaxSize = (unsigned short)ausCount;
    m_usGrowBy = (unsigned short)b;
    m_usSize = 0;
    m_usESize = 0;
    if (m_usMaxSize > 0) {
        unsigned int n = m_usMaxSize;
        m_pBase = (NiParticles**)NiMalloc(n * 4);
    } else {
        m_pBase = 0;
    }
}

extern int DAT_010c1b2c;
struct FUN_00c5f570_Class {
    void __thiscall FUN_00c5f570();
};
struct FUN_00c450d0 : FUN_00c5f570_Class {
    int vtbl;
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    unsigned char b4;
    unsigned char b5;
    unsigned char b6;
    unsigned char b7;
    unsigned char b8;
    unsigned char b9;
    unsigned char ba;
    unsigned char bb;
    unsigned char bc;
    unsigned char bd;
    unsigned char be;
    unsigned char bf;
    unsigned char c0;
    unsigned char c1;
    unsigned char c2;
    unsigned char c3;
    unsigned char c4;
    unsigned char c5;
    unsigned char c6;
    unsigned char c7;
    unsigned char c8;
    unsigned char c9;
    unsigned char ca;
    unsigned char cb;
    unsigned char cc;
    unsigned char cd;
    unsigned char ce;
    unsigned char cf;
    unsigned char d0;
    unsigned char d1;
    unsigned char d2;
    unsigned char d3;
    unsigned char d4;
    unsigned char d5;
    unsigned char d6;
    unsigned char d7;
    unsigned char d8;
    unsigned char d9;
    unsigned char da;
    unsigned char db;
    unsigned char dc;
    unsigned char dd;
    unsigned char de;
    unsigned char df;
    unsigned char e0;
    unsigned char e1;
    unsigned char e2;
    unsigned char e3;
    unsigned char e4;
    unsigned char e5;
    unsigned char e6;
    unsigned char e7;
    unsigned char e8;
    unsigned char e9;
    unsigned char ea;
    unsigned char eb;
    unsigned char ec;
    unsigned char ed;
    unsigned char ee;
    unsigned char ef;
    unsigned char f0;
    unsigned char f1;
    unsigned char f2;
    unsigned char f3;
    unsigned char f4;
    unsigned char f5;
    unsigned char f6;
    unsigned char f7;
    unsigned char f8;
    unsigned char f9;
    unsigned char fa;
    unsigned char fb;
    unsigned char fc;
    unsigned char fd;
    unsigned char fe;
    unsigned char ff;
    unsigned char a0;
    unsigned char a1;
    unsigned char a2;
    unsigned char a3;
    unsigned char a4;
    unsigned char a5;
    unsigned char a6;
    unsigned char a7;
    unsigned char a8;
    unsigned char a9;
    unsigned char aa;
    unsigned char ab;
    unsigned char ac;
    unsigned char ad;
    unsigned char ae;
    unsigned char af;
    FUN_00c450d0();
};
// Calls the base constructor, installs the vtable, and initialises the bytes at offsets 0xac-0xaf to 1, 0, 0, 0xff.
// @fnv 0x00c450d0
FUN_00c450d0::FUN_00c450d0()
{
    FUN_00c5f570_Class::FUN_00c5f570();
    vtbl = (int)&DAT_010c1b2c;
    *(unsigned char*)((char*)this + 0xae) = 0;
    *(unsigned char*)((char*)this + 0xaf) = 0xff;
    *(unsigned char*)((char*)this + 0xad) = 0;
    *(unsigned char*)((char*)this + 0xac) = 1;
}

struct FUN_00c465a0_class {
    void* operator new(unsigned int);
    FUN_00c465a0_class();
    char pad[0x1c];
};
struct FUN_00c46670_class {
    void* __thiscall BSWindModifier_CreateClone(CloningProcess& process);
};
// Allocates a FUN_00c465a0_class object, passes it with process to CopyModifier, and returns the new object.
// @fnv 0x00c46670
// src: XBOX_PDB 0x00c46670
void* __thiscall FUN_00c46670_class::BSWindModifier_CreateClone(CloningProcess& process)
{
    BSWindModifier* p = (BSWindModifier*)new FUN_00c465a0_class;
    ((BSWindModifier*)this)->CopyModifier(p, process);
    return (void*)p;
}

struct FUN_00c465a0 {
    char* p;
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    FUN_00c465a0();
    ~FUN_00c465a0();
    static void* operator new(unsigned int);
};
// Allocates and constructs a new FUN_00c465a0 object, returning its pointer.
// @fnv 0x00c46740
// src: EXE 0x00c46740
FUN_00c465a0* __cdecl BSWindModifier_CreateObject()
{
    return new FUN_00c465a0;
}

struct FUN_00c48fe0_Class {
    int m_0000;
    int m_0004;
    int m_0008;
    int m_000c;
    int m_0010;
    int m_0014;
    int m_0018;
    int m_001c;
    int m_0020;
    int m_0024;
    int m_0028;
    int CountTypeSevenAndEightEntries();
};

// Counts entries in the array at m_0018 whose first int is 7 or 8, skipping the following entry each time.
// @fnv 0x00c48fe0
// src: GUESS 0x00c48fe0 (confidence: medium)
int FUN_00c48fe0_Class::CountTypeSevenAndEightEntries()
{
    int iCount = 0;
    for (int i = 0; i < m_0028; i++) {
        if (*((int*)((char*)m_0018 + i * 12)) == 7 || *((int*)((char*)m_0018 + i * 12)) == 8) {
            iCount++;
            i++;
        }
    }
    return iCount;
}

struct FUN_00c4a5a0_class {
    virtual void vfn_0000();
    virtual void* vfn_0004(unsigned int);
    void* m1;
    unsigned int m2;
    unsigned int m3;
    void __thiscall BSSimpleArray_BSCompoundFrustum_FunctionOp_1024_InitialSetup(unsigned int a, unsigned int b);
};

// @fnv 0x00c4a5a0
// src: COMMUNITY 0x00c4a5a0
void FUN_00c4a5a0_class::BSSimpleArray_BSCompoundFrustum_FunctionOp_1024_InitialSetup(unsigned int uiCapacity, unsigned int b)
{
    m1 = 0;
    m2 = 0;
    m3 = 0;
    if (b > uiCapacity)
        uiCapacity = b;
    if (uiCapacity > 0) {
        m1 = vfn_0004(uiCapacity);
        m3 = uiCapacity;
    }
    if (b > 0) {
        for (unsigned int i = 0; i < b; ++i) {
            void* p = &((char*)m1)[i * 12];
        }
        m2 = b;
    }
}

struct CloningProcess;
struct NiFloatsExtraData;
struct FUN_00c54dd0 : NiExtraData {
    void CopyMembers_00a7b330(NiBinaryExtraData*, CloningProcess*);
    int d;
    int e;
    int f;
    int g;
    int h;
    int i;
};
struct FUN_00c54dd0_3i {
    int x;
    int y;
    int z;
};
// @fnv 0x00c54dd0
// src: XBOX_PDB 0x00a7b330
void FUN_00c54dd0::CopyMembers_00a7b330(NiBinaryExtraData* dest, CloningProcess* proc)
{
    NiExtraData::CopyMembers_00a7b330(dest, proc);
    *(FUN_00c54dd0_3i*)((char*)dest + 0xc) = *(FUN_00c54dd0_3i*)((char*)this + 0xc);
    *(FUN_00c54dd0_3i*)((char*)dest + 0x18) = *(FUN_00c54dd0_3i*)((char*)this + 0x18);
}

struct Elem4 { void FUN_008228f0(int); };
struct FUN_0042fb60_shell { void FUN_0042fb60(char*, char*, unsigned int); };
struct FUN_00c5bef0_class {
    char* m0;
    char* m1;
    unsigned int m2;
    void RemoveRange(unsigned int a, unsigned int b);
};
// Clears b elements starting at index a, moves the tail block down by count elements, and shrinks m2 by b.
// @fnv 0x00c5bef0
void FUN_00c5bef0_class::RemoveRange(unsigned int uiStart, unsigned int b)
{
    unsigned int i;
    unsigned int count;
    char* dst2;
    unsigned int aLimit;
    unsigned int unused1;
    unsigned int unused2;
    unsigned int FlushUsageData;
    aLimit = m2 - uiStart - b;
    count = aLimit < b ? aLimit : b;
    dst2 = m1 + uiStart * 4;
    for (i = 0; i < b; i++)
        ((Elem4*)(dst2 + i * 4))->FUN_008228f0(0);
    ((FUN_0042fb60_shell*)this)->FUN_0042fb60(m1 + uiStart * 4, m1 + m2 * 4 - count * 4, count);
    m2 -= b;
}

void __cdecl NiStreamLoadBinary_unsigned_short(NiStream*, void const*);
struct FUN_00c5cc30_class {
    void LoadBinary(NiStream&);
    void BSPSysMultiTargetEmitterCtlr_LoadBinary(NiStream&);
};
// @fnv 0x00c5cc30
// src: XBOX_PDB 0x00c5cc30
void FUN_00c5cc30_class::BSPSysMultiTargetEmitterCtlr_LoadBinary(NiStream& stream)
{
    LoadBinary(stream);
    NiStreamLoadBinary_unsigned_short(&stream, (void*)((char*)this + 0x60));
    if (*((unsigned short*)((char*)this + 0x60)) < 1)
        *((unsigned short*)((char*)this + 0x60)) = 1;
    *((NiObject**)((char*)this + 0x5c)) = stream.DeserializeObject();
}

char* __cdecl NiViewerStrings_NiGetViewerString_Title(char const*);
char* __cdecl NiGetViewerString_00a7d510(char const*, unsigned int);
struct FUN_00c5d610_StandIn {
    unsigned int SettingCollectionList_Setting_GetViewerStrings(NiTPrimitiveArray<unsigned int>&);
};
struct FUN_00c5d610_Class {
    unsigned int __thiscall AddRegSettingsStrings(NiTPrimitiveArray<unsigned int>& arr);
};
// @fnv 0x00c5d610
unsigned int FUN_00c5d610_Class::AddRegSettingsStrings(NiTPrimitiveArray<unsigned int>& arrStrings)
{
    char pad[0x38];
    unsigned int p = (unsigned int)NiViewerStrings_NiGetViewerString_Title("RegSettings");
    arrStrings.AddFirstEmpty(p);
    unsigned int v6 = ((FUN_00c5d610_StandIn*)this)->SettingCollectionList_Setting_GetViewerStrings(arrStrings);
    unsigned int p2 = (unsigned int)NiGetViewerString_00a7d510("Total RegSettings", v6);
    arrStrings.AddFirstEmpty(p2);
    return v6;
}

int __cdecl Setting_DataType_00c33090(int);

// Calls FUN_00c33090 on apParams[2] and maps the returned state to 3, 1, or 4.
// @fnv 0x00c5da10
int __cdecl GetStateResult(int* apParams)
{
    int iResult = 0;
    int iState = Setting_DataType_00c33090(apParams[2]);
    switch (iState)
    {
    case 0: iResult = 3; break;
    case 6: iResult = 1; break;
    default: iResult = 4; break;
    }
    return iResult;
}

struct FUN_00c5e620_Class {
    void __thiscall BSMasterParticleSystem_LoadBinary(NiStream* stream);
};


struct NiStream_ReadMultipleLinkIDs_Helper {
    unsigned int __thiscall ReadUnsignedInteger();
};

// @fnv 0x00c5e620
// src: XBOX_PDB 0x00c5e620
void __thiscall FUN_00c5e620_Class::BSMasterParticleSystem_LoadBinary(NiStream* stream)
{
    reinterpret_cast<NiNode*>(this)->NiNode::LoadBinary(*stream);
    NiStreamLoadBinary_unsigned_short(stream, (char*)this + 0xba);
    if (*(unsigned int*)((char*)stream + 4) > 0xf) {
        ((NiStream_ReadMultipleLinkIDs_Helper*)stream)->ReadUnsignedInteger();
    }
}

struct ObjA { void __thiscall BSTask_int64_DecRefCount(); };
struct FUN_00c40910_Class {
    ObjA* m_p;
    void __thiscall CallObjA();
};
// @fnv 0x00c40910
void __thiscall FUN_00c40910_Class::CallObjA()
{
    int a;
    int b;
    int c;
    if (m_p)
        m_p->BSTask_int64_DecRefCount();
}

struct FUN_00c42060_Class {
    virtual void vfn_0000();
    virtual void vfn_0004();
    int m4;            // +0x4
    int m8;            // +0x8
    char pad[0xc];
    unsigned char m18; // +0x18
    void __thiscall SetArg(int arg);
};

// @fnv 0x00c42060
void FUN_00c42060_Class::SetArg(int arg)
{
    vfn_0004();
    m8 = arg;
    if (0) {
        m18 |= 1;
    } else {
        m18 &= ~1;
    }
    if (0) {
        m18 |= 2;
    } else {
        m18 &= ~2;
    }
}

extern int DAT_010c1844;

// @fnv 0x00c42f00
void __fastcall DestroyResources(void* thisPtr)
{
    *(int*)thisPtr = (int)&DAT_010c1844;
    FreeLibrary(*(HMODULE*)((char*)thisPtr + 4));
    DeleteObject(*(void**)((char*)thisPtr + 4));
    DeleteObject(*(void**)((char*)thisPtr + 0x1c));
    DeleteObject(*(void**)((char*)thisPtr + 0x10));
}

extern int DAT_010a0d24;
extern int DAT_010c1854;
struct FUN_00c43070_shell {
    void DestroyFields_00a7b300();
    void SetVtableAndProcessState_00c43070();
};
// @fnv 0x00c43070
// src: GUESS 0x00c43070 (confidence: low)
void FUN_00c43070_shell::SetVtableAndProcessState_00c43070()
{
    *reinterpret_cast<int**>(this) = &DAT_010c1854;
    *reinterpret_cast<int**>(this) = &DAT_010a0d24;
    DestroyFields_00a7b300();
}



extern void* _g_01202de0;

// Returns the extra data attached to obj under DAT_01202ddc if its vfn_0008 matches _g_01202de0, otherwise null.
// @fnv 0x00c43490
void* GetExtraDataChecked(NiAVObject* obj)
{
    void* result5 = 0;
    if (obj != 0) {
        NiExtraData* extra;
        NiFixedString* name = DAT_01202ddc;
        extra = obj->GetExtraData(*name);
        bool ok2;
        if (extra == 0) {
            ok2 = false;
        } else {
            ok2 = (extra->GetRTTI() == (void*)&_g_01202de0);
        }
        if (ok2) {
            result5 = extra;
        }
    }
    return result5;
}

extern int DAT_010c195c;

struct FUN_00c43660 : FUN_00c5f570_Class {
    char pad[0xb0];
    int f1;
    int f2;
    FUN_00c43660();
};
// @fnv 0x00c43660
FUN_00c43660::FUN_00c43660()
{
    FUN_00c5f570();
    *(int*)this = (int)&DAT_010c195c;
    f1 = 0;
    f2 = 0;
}


void __cdecl ReadBinaryValue(NiStream& stream, unsigned int& value);
void __cdecl NiStreamLoadBinary_char_00a643b0(NiStream& stream, unsigned int& value);

// LoadBinary at 0x00c438a0 belongs to BSValueNode; include/ has no BSValueNode header yet.
struct BSValueNode : NiNode {
    unsigned int m_field_ac;
    unsigned int m_field_b0;
    void LoadBinary_00c438a0(NiStream& stream);
};

// @fnv 0x00c438a0
// src: XBOX_PDB 0x00c438a0
void BSValueNode::LoadBinary_00c438a0(NiStream& stream)
{
    unsigned int local2;
    NiNode::LoadBinary(stream);
    ReadBinaryValue(stream, local2);
    unsigned int val = local2;
    m_field_b0 = val;
    if (*(unsigned int*)((char*)&stream + 4) > 0x18) {
        NiStreamLoadBinary_char_00a643b0(stream, m_field_ac);
    }
}

struct FUN_00c43920_class {
    char BSValueNode_RegisterStreamables(NiStream* stream);
};

// @fnv 0x00c43920
// src: XBOX_PDB 0x00c43920
char FUN_00c43920_class::BSValueNode_RegisterStreamables(NiStream* stream)
{
    if (!((FUN_00a5e5b0_helper*)this)->RegisterChildStreamables(stream))
        return 0;
    return 1;
}

struct MyBase {
    void __thiscall NiNode_SaveBinary(NiStream& stream);
};

void __cdecl Runtime_UpdateState_00a29550(NiStream& stream, unsigned char* p);

struct FUN_00c43950_Class : MyBase {
    void __thiscall BSValueNode_SaveBinary(NiStream& stream);
};

// @fnv 0x00c43950
// src: XBOX_PDB 0x00c43950
void __thiscall FUN_00c43950_Class::BSValueNode_SaveBinary(NiStream& stream)
{
    NiNode_SaveBinary(stream);
    int b = *(int*)((char*)this + 0xb0);
    int a = b;
    CallAnimCallback((SStream*)&stream, (SObj*)&a);
    Runtime_UpdateState_00a29550(stream, (unsigned char*)this + 0xac);
}

struct FUN_00c43cb0_class {
    void __thiscall FUN_00c5faa0();
    void* __thiscall FUN_00c43cb0(unsigned int flags);
};
// Calls FUN_00c5faa0, then frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00c43cb0
void* FUN_00c43cb0_class::FUN_00c43cb0(unsigned int flags)
{
    FUN_00c5faa0();
    if (flags & 1)
        operator delete(this, 0xb8);
    return this;
}

struct FUN_00c457e0_class {
    char pad[0xb0];
    void __thiscall FUN_00c5faa0();
    void* __thiscall FUN_00c457e0(unsigned int flags);
};

// Calls FUN_00c5faa0, frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00c457e0
void* __thiscall FUN_00c457e0_class::FUN_00c457e0(unsigned int flags)
{
    FUN_00c5faa0();
    if (flags & 1)
        operator delete(this, 0xb0);
    return this;
}

struct FUN_00c46230_Class {
    void* m0;
    void __thiscall StoreAndAddReference_00c46230();
};
// @fnv 0x00c46230
// src: GUESS 0x00c46230 (confidence: medium)
void __thiscall FUN_00c46230_Class::StoreAndAddReference_00c46230()
{
    void* tmp;
    m0 = 0;
    if (m0)
    {
        tmp = m0;
        InterlockedIncrement((long*)((char*)tmp + 4));
    }
}

void __cdecl FUN_00c31750();

struct FUN_00c46930_class {
    void __thiscall FUN_00c31750();
    void* __thiscall FUN_00c46930(unsigned int flags);
};

// @fnv 0x00c46930
void* FUN_00c46930_class::FUN_00c46930(unsigned int flags)
{
    FUN_00c31750();
    if (flags & 1)
        operator delete(this, 0x1c);
    return this;
}

struct A51BF0Base {
    char pad[0xb4];

    static void* __cdecl operator new(unsigned int size);
    A51BF0Base();

    void __thiscall BSMultiBoundNode_CopyMembers(A51BF0Base* copy, int a);
    A51BF0Base* __thiscall BSMultiBoundNode_CreateClone(int a);
};

// Allocates a new A51BF0Base, initialises it from a via FUN_00c46c30, and returns the new object.
// @fnv 0x00c46ba0
// src: XBOX_PDB 0x00c46ba0
A51BF0Base* __thiscall A51BF0Base::BSMultiBoundNode_CreateClone(int aiValue)
{
    A51BF0Base* copy = new A51BF0Base;
    BSMultiBoundNode_CopyMembers(copy, aiValue);
    return copy;
}


struct NiStreamHelper {
    void* __thiscall GetLoadedObject();
};

struct FUN_00c46cd0_Class {
    char pad[0xac];
    GO m_go;

    void __thiscall LoadFromStream(void* stream);
};

// @fnv 0x00c46cd0
void FUN_00c46cd0_Class::LoadFromStream(void* stream)
{
    void* unused1;
    void* unused2;

    reinterpret_cast<NiNode*>(this)->ReadChildListFromStream(stream);
    m_go = reinterpret_cast<NiStreamHelper*>(stream)->GetLoadedObject();
}

struct FUN_00c46af0 {
    void __thiscall Destruct();
    void* __thiscall FUN_00c47610(unsigned int flags);
};
// Calls Destruct, then frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00c47610
void* FUN_00c46af0::FUN_00c47610(unsigned int flags)
{
    FUN_00c46af0::Destruct();
    if (flags & 1)
        operator delete(this, 0xb4);
    return this;
}

struct FUN_00c47a00_Class {
    char pad0[0x18];
    char* m18;             // +0x18
    char pad1[0x4];
    int m20;               // +0x20
    char pad2[0x4];
    int m28;               // +0x28
    void BSCompoundFrustum_StartGroupIntersection();
};

// @fnv 0x00c47a00
// src: COMMUNITY 0x00c47a00
void FUN_00c47a00_Class::BSCompoundFrustum_StartGroupIntersection()
{
    int count = m20;
    if (!(m28 + 1 < count))
    {
        int c = m20;
        ((Arr_00c48a10*)((char*)this + 0x14))->FUN_00c4a1e0(c + 0xa, true);
    }
    *(int*)(m18 + m28 * 0xc) = 4;
    m28 = m28 + 1;
}

struct FUN_00c47a70_Class {
    void BSCompoundFrustum_StartGroupUnion();
};

// @fnv 0x00c47a70
// src: COMMUNITY 0x00c47a70
void FUN_00c47a70_Class::BSCompoundFrustum_StartGroupUnion()
{
    int cap = *(int*)((char*)this + 0x20);
    if (*(int*)((char*)this + 0x28) + 1 >= cap) {
        int c = *(int*)((char*)this + 0x20);
        ((Arr_00c48a10*)((char*)this + 0x14))->FUN_00c4a1e0(c + 0xa, true);
    }
    *(char*)this = 0;
    *(int*)(*(int*)((char*)this + 0x18) + *(int*)((char*)this + 0x28) * 0xc) = 5;
    *(int*)((char*)this + 0x28) = *(int*)((char*)this + 0x28) + 1;
}

struct FUN_006dc6e0_Class
{
    virtual void* v0();
    virtual char* v4(unsigned int);
    virtual void v8(char*);
    virtual char* vc(char*, unsigned int);

    char* m_p;
    unsigned int m_ucUnknownByte;
    unsigned int m_uiFilterValue;

    void __thiscall BSSimpleArray_BSCompoundFrustum_FunctionOp_1024_MoveItems(char*, char*, unsigned int);
    void __thiscall BSSimpleArray_BSCompoundFrustum_FunctionOp_1024_ReallocateBuffer(unsigned int, unsigned int);
};

// @fnv 0x00c4a4e0
// src: XBOX_PDB 0x00c4a4e0
void FUN_006dc6e0_Class::BSSimpleArray_BSCompoundFrustum_FunctionOp_1024_ReallocateBuffer(unsigned int a, unsigned int b)
{
    char* GetObject;
    {
        void* unused;
        {
            void* unused;
        }
    }

    if (m_p != 0)
    {
        if (b == m_uiFilterValue)
        {
            m_p = vc(m_p, a);
        }
        else
        {
            GetObject = v4(a);
            BSSimpleArray_BSCompoundFrustum_FunctionOp_1024_MoveItems(GetObject, m_p, b);
            v8(m_p);
            m_p = 0;
            m_p = GetObject;
        }
    }
    else
    {
        m_p = v4(a);
        m_uiFilterValue = a;
    }
}

struct FUN_00c4a960_Class {
    void UpdateFields_00c4a840();
    void* FUN_00c4a960(unsigned int flags);
};
// Calls FUN_00c4a840, then deallocates this via the memory manager if flags has bit 0 set, and returns this.
// @fnv 0x00c4a960
void* FUN_00c4a960_Class::FUN_00c4a960(unsigned int flags)
{
    UpdateFields_00c4a840();
    if (flags & 1)
        ((MemoryManager*)&g_memoryManager)->Deallocate(this);
    return this;
}

struct FUN_00c4ab80_class {
    unsigned char BSRangeNode_RegisterStreamables(int);
    char BSBlastNode_RegisterStreamables(int a);
};

// @fnv 0x00c4ab80
// src: XBOX_PDB 0x00c4ab80
char FUN_00c4ab80_class::BSBlastNode_RegisterStreamables(int a)
{
    if (!BSRangeNode_RegisterStreamables(a))
        return 0;
    return 1;
}

unsigned int __cdecl _FUN_00a7d330(int a);

struct FUN_00c4ad60_class : public FUN_00c4ab00_Class {
    void __thiscall AddFirstEmptyFromGlobal(int a);
};

// @fnv 0x00c4ad60
void FUN_00c4ad60_class::AddFirstEmptyFromGlobal(int pArray)
{
    BSRangeNode_GetViewerStrings(pArray);

    unsigned int result;
    {
        int value = g_01202e84;
        {
            int padding1;
            int padding2;
            int padding3;
            int padding4;
        }
        result = _FUN_00a7d330(value);
    }

    reinterpret_cast<NiTPrimitiveArray<unsigned int>*>(pArray)->
        AddFirstEmpty(result);
}

unsigned int __cdecl _FUN_00a7d330(void*);

struct FUN_00c4afc0_class {
    void __thiscall AddValueToArray(NiTPrimitiveArray<unsigned int>* array);
};

// @fnv 0x00c4afc0
void __thiscall FUN_00c4afc0_class::AddValueToArray(NiTPrimitiveArray<unsigned int>* array)
{
    {
        int padding[4];
    }

    unsigned int p;
    void* value;

    reinterpret_cast<FUN_00c4ab00_Class*>(this)->BSRangeNode_GetViewerStrings(reinterpret_cast<int>(array));

    value = *reinterpret_cast<void**>(&g_01202e8c);
    p = _FUN_00a7d330(value);

    array->AddFirstEmpty(p);
}

struct FUN_00c4b090_class {
    char BSDamageStage_IsEqual(int a1);
};

// Calls FUN_00c45380 on this with a1 and returns its char result.
// @fnv 0x00c4b090
// src: XBOX_PDB 0x00c4b090
char FUN_00c4b090_class::BSDamageStage_IsEqual(int a1)
{
    char result = ((FUN_00c4abd0_class*)this)->BSRangeNode_IsEqual(a1);
    return result;
}


void* _NiMalloc(unsigned int size);
void NiFree(void* ptr);

// Resizes the array to count entries, zeroing dropped slots, reallocating storage, copying existing entries and freeing the old buffer.
// @fnv 0x00c4c920
template <>
void NiTArray<unsigned int, NiTMallocInterface<unsigned int> >::SetSize(unsigned int count)
{
    unsigned short i;
    unsigned int* oldData;
    unsigned int capacitySize;

    if (count == this->m_usMaxSize)
        return;

    if (count < this->m_usSize) {
        for (i = (unsigned short)count; i < this->m_usSize; ++i) {
            if (this->m_pBase[i] != 0) {
                this->m_pBase[i] = 0;
                --this->m_usESize;
            }
        }
        this->m_usSize = (unsigned short)count;
    }

    oldData = this->m_pBase;
    this->m_usMaxSize = (unsigned short)count;

    if (count > 0) {
        capacitySize = this->m_usMaxSize;
        this->m_pBase = (unsigned int*)_NiMalloc(capacitySize << 2);

        for (i = 0; i < this->m_usSize; ++i)
            this->m_pBase[i] = oldData[i];

        for (i = this->m_usSize; i < this->m_usMaxSize; ++i)
            this->m_pBase[i] = 0;
    } else {
        this->m_pBase = 0;
    }

    NiFree(oldData);
}

namespace fnv_00c4e160 {
struct A51BF0Base {
    static void* __cdecl operator new(unsigned int);
};

struct FUN_00a74480 : A51BF0Base {
    char pad[0xc4];
    FUN_00a74480(unsigned int);
};

struct FUN_00c4e160_Class {
    FUN_00a74480* __thiscall CreateInstance(unsigned int);
};

// Allocates and constructs a FUN_00a74480 object with the given value, returning the new instance.
// @fnv 0x00c4e160
FUN_00a74480* __thiscall FUN_00c4e160_Class::CreateInstance(unsigned int auiValue)
{
    return new FUN_00a74480(auiValue);
}
}  // namespace fnv_00c4e160

struct FUN_00c4f270_Class {
    char pad[0x90];
    int m_type;
    char pad2[0x28];
    int m_uiItemCount;
    int m_aiEntries[1];
    void __thiscall BSCullingProcess_PushCullMode(int aeType);
};

// @fnv 0x00c4f270
// src: COMMUNITY 0x00c4f270
void __thiscall FUN_00c4f270_Class::BSCullingProcess_PushCullMode(int aeType)
{
    int saved = m_type;
    ((int*)((char*)this + 0x94))[m_uiItemCount] = saved;
    m_uiItemCount = m_uiItemCount + 1;
    m_type = aeType;
}

namespace fnv_00c513f0 {
struct A51BF0Base {
    static void* __cdecl operator new(unsigned int size);
};

struct FUN_00c5da70 : public A51BF0Base {
    char pad[0xdc];

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
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55(int, int);

    void BSMasterParticleSystem_UpdateParticleSystemList();

    FUN_00c5da70();
};

FUN_00c5da70::FUN_00c5da70()
{
}

unsigned char __cdecl BSParticleSystemManager_CheckEmitterRecurse(int, int);
void __cdecl SetParticleSystemTarget(int, FUN_00c5da70*);

// @fnv 0x00c513f0
FUN_00c5da70* __cdecl CreateAndInitObject(int a)
{
    FUN_00c5da70* result = 0;

    if (BSParticleSystemManager_CheckEmitterRecurse(a, 0)) {
        result = new FUN_00c5da70;
        SetParticleSystemTarget(a, result);
        result->v55(a, 1);
        result->BSMasterParticleSystem_UpdateParticleSystemList();
    }

    return result;
}
}  // namespace fnv_00c513f0

namespace fnv_00c514c0 {
struct A51BF0Base {
    static void* __cdecl operator new(unsigned int size);
};

int _data_011c16bc;

struct FUN_00c503d0 : public A51BF0Base {
    char pad[0xb8];
    FUN_00c503d0();
};

struct FUN_00c514c0_Class : public FUN_00c51550 {
    void* __thiscall BSParticleSystemManager_CreateClone(void* source);
};

// @fnv 0x00c514c0
// src: XBOX_PDB 0x00c514c0
void* __thiscall FUN_00c514c0_Class::BSParticleSystemManager_CreateClone(void* source)
{
    FUN_00c503d0* copy = new FUN_00c503d0;
    Copy(reinterpret_cast<NiNode*>(copy), source);
    return copy;
}
}  // namespace fnv_00c514c0

// 0x00c5cb20 copies the multi-target count at +0x60 after the emitter base at 0x00c1bd30; this helper adds only the missing operation.
struct MultiTargetEmitterCloneWriter : BSPSysMultiTargetEmitterCtlr {
    void BSPSysMultiTargetEmitterCtlr_CopyMembers(MultiTargetEmitterCloneWriter* a, void* b);
};

// @fnv 0x00c5cb20
// src: XBOX_PDB 0x00c5cb20
void MultiTargetEmitterCloneWriter::BSPSysMultiTargetEmitterCtlr_CopyMembers(MultiTargetEmitterCloneWriter* apTarget, void* apArg)
{
    NiPSysEmitterCtlr::CopyMemberData(apTarget, *static_cast<CloningProcess*>(apArg));
    *(unsigned short*)((char*)apTarget + 0x60) = *(unsigned short*)((char*)this + 0x60);
}

struct FUN_00c5ce40_Class {
    int PopFrontNode();
};

// @fnv 0x00c5ce40
int FUN_00c5ce40_Class::PopFrontNode()
{
    int* pList = (int*)((char*)this + 0xc0);
    int* pNode2 = (int*)(*pList + 8);
    *pList = *(int*)*pList;
    int result2 = *pNode2;
    if (*(int*)((char*)this + 0xc0) == 0) {
        int v2 = *(int*)((char*)this + 0xac);
        *(int*)((char*)this + 0xc0) = v2;
    }
    return result2;
}

struct FUN_00c5d260_view {
    void __thiscall Destruct();
    static void __cdecl operator delete(void* p, unsigned int sz);
};
struct FUN_00c5d260 : FUN_00c5d260_view {
    void* __thiscall FUN_00c5d260_method(unsigned int flags);
};
// Calls Destruct, frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00c5d260
void* __thiscall FUN_00c5d260::FUN_00c5d260_method(unsigned int flags)
{
    reinterpret_cast<FUN_00c5d260_view*>(this)->Destruct();
    if (flags & 1)
        FUN_00c5d260_view::operator delete(this, 0xd4);
    return this;
}

extern double runtimeInitializationDouble5;
extern double DAT_01034208;

// Evaluates a quintic polynomial in x using two global double constants and returns the float result.
// @fnv 0x00c5d2b0
float __cdecl EvaluateQuinticPolynomial(float x)
{
    float result;
    result = x * x * x * x * x * DAT_01034208
           - x * x * x * x * runtimeInitializationDouble5
           + x * x * x * 10.0;
    return result;
}

// @fnv 0x00c5d300
// src: COMMUNITY 0x00c5d300
float BSNoise1D_lerp(float afFactor, float afStart, float afEnd)
{
    return afFactor * (afEnd - afStart) + afStart;
}

namespace fnv_00c5e4d0 {
struct A51BF0Base {
    static void* __cdecl operator new(unsigned int size);
};

struct FUN_00c5da70 : public A51BF0Base {
    char pad[0xe0];

    FUN_00c5da70();
};

FUN_00c5da70::FUN_00c5da70()
{
}

struct FUN_00c5e4d0_class : public FUN_00c5e560_class {
    FUN_00c5da70* __thiscall CreateNode(void*);
};

// @fnv 0x00c5e4d0
FUN_00c5da70* __thiscall FUN_00c5e4d0_class::CreateNode(void* arg)
{
    FUN_00c5da70* object = new FUN_00c5da70;
    this->NiNode_CopyMembers(reinterpret_cast<NiNode*>(object), arg);
    return object;
}
}  // namespace fnv_00c5e4d0

namespace fnv_00c5e5a0 {
struct A51BF0Base {
    static void* __cdecl operator new(unsigned int);
};

struct FUN_00c5da70_Class : public A51BF0Base {
    char pad[0xe0];
    FUN_00c5da70_Class();
};

// Allocates and constructs a FUN_00c5da70_Class object, returning the new instance.
// @fnv 0x00c5e5a0
// src: EXE 0x00c5e5a0
FUN_00c5da70_Class* __cdecl BSMasterParticleSystem_CreateObject()
{
    FUN_00c5da70_Class* result = new FUN_00c5da70_Class;
    return result;
}
}  // namespace fnv_00c5e5a0

struct NiObjectNET_stub {
    void NiObjectNET_PostLinkObject(int);
};
struct FUN_00c5de70_stub {
    void BSMasterParticleSystem_UpdateParticleSystemList();
};
struct FUN_00c5e6f0_class {
    void BSMasterParticleSystem_PostLinkObject(int a);
};
// Calls FUN_00a5c6a0 with a, then calls FUN_00c5de70 if the value at a+4 is below 0x10.
// @fnv 0x00c5e6f0
// src: XBOX_PDB 0x00c5e6f0
void FUN_00c5e6f0_class::BSMasterParticleSystem_PostLinkObject(int a)
{
    ((NiObjectNET_stub*)this)->NiObjectNET_PostLinkObject(a);
    if (*(unsigned int*)(a + 4) < 0x10) {
        ((FUN_00c5de70_stub*)this)->BSMasterParticleSystem_UpdateParticleSystemList();
    }
}

struct FUN_00c5e720_Class {
    unsigned char BSMasterParticleSystem_RegisterStreamables(NiStream* stream);
};

// @fnv 0x00c5e720
// src: XBOX_PDB 0x00c5e720
unsigned char FUN_00c5e720_Class::BSMasterParticleSystem_RegisterStreamables(NiStream* stream)
{
    unsigned int i;
    void* obj;

    if (!((FUN_00a5e5b0_helper*)this)->RegisterChildStreamables(stream))
        return 0;

    for (i = 0; i < *(unsigned short*)((char*)this + 0xd6); ++i)
    {
        obj = *(void**)(*(int*)((char*)this + 0xd0) + i * 4);
        if (obj)
            (*(void(__thiscall**)(void*, NiStream*))(*(int*)obj + 0x54))(obj, stream);
    }
    return 1;
}

struct FUN_00c5ede0_Class {
    int __thiscall GetEntryAt(int a);
};
// @fnv 0x00c5ede0
int FUN_00c5ede0_Class::GetEntryAt(int aiIndex)
{
    return ((int*)*(int**)((char*)this + 0x10))[aiIndex];
}

namespace fnv_00c5ee00 {
struct A51BF0Base {
    static void* __cdecl operator new(unsigned int size);
};

struct FUN_00c5ecf0 : A51BF0Base {
    char m_data[0x1c];
    FUN_00c5ecf0();
};

struct FUN_00c5ee00_Class {
    void __thiscall BSTextureData_CopyMembers(A51BF0Base* object, int value);
    A51BF0Base* __thiscall CreateObjectWithValue(int value);
};

// Allocates a FUN_00c5ecf0 object, passes it with value to FUN_00c5ee90, and returns the object.
// @fnv 0x00c5ee00
A51BF0Base* __thiscall FUN_00c5ee00_Class::CreateObjectWithValue(int value)
{
    A51BF0Base* object = new FUN_00c5ecf0;

    this->BSTextureData_CopyMembers(object, value);
    return object;
}
}  // namespace fnv_00c5ee00

struct S_00a953b0_Node {
    void __thiscall CopyMemberData(S_00a953b0_Node*, void*);
};

struct FUN_00c5fb60_class : public S_00a953b0_Node {
    void __thiscall ForwardToBase(S_00a953b0_Node*, void*);
};

// @fnv 0x00c5fb60
void FUN_00c5fb60_class::ForwardToBase(S_00a953b0_Node* apNode, void* apArg)
{
    CopyMemberData(apNode, apArg);
}

struct FUN_00c25d40_Class {
    void __thiscall ResetEntry(unsigned short);
};
struct FUN_00c5fd70_Class {
    void __thiscall BSPSysStripUpdateModifier_Initialize(void* a, unsigned short b);
};
// Forwards the unsigned short argument to the target object's ResetEntry method.
// @fnv 0x00c5fd70
// src: XBOX_PDB 0x00c5fd70
void __thiscall FUN_00c5fd70_Class::BSPSysStripUpdateModifier_Initialize(void* pTarget, unsigned short usValue)
{
    void* t = pTarget;
    ((FUN_00c25d40_Class*)t)->ResetEntry(usValue);
}

struct FUN_00c5ffd0 : NiPSysModifier {
    void Method(NiStream* stream);
};
// @fnv 0x00c5ffd0
void FUN_00c5ffd0::Method(NiStream* stream)
{
    NiPSysModifier::FUN_00c31950(*stream);
    CallAnimCallback((SStream*)stream, (SObj*)((char*)this + 0x18));
}

struct C40B20Timer {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned __int64 m_uiElapsedTime;

    void LockFreeMap_int64_NiPointer_BSTask_int64_LockFreeMapIterator_ClearKey();
};

// @fnv 0x00c40b20
// src: XBOX_PDB 0x00c40b20
void C40B20Timer::LockFreeMap_int64_NiPointer_BSTask_int64_LockFreeMapIterator_ClearKey()
{
    m_uiElapsedTime = 0;
}

struct S_0044dd60 {
    void __thiscall BSTask_int64_DecRefCount();
};

extern "C" void (__stdcall *FUN_00fdf1c0)(void*);

struct FUN_00c41050_Class {
    S_0044dd60* m_pIntegerData;

    FUN_00c41050_Class* __thiscall AssignRef(S_0044dd60** other);
};

// @fnv 0x00c41050
FUN_00c41050_Class* __thiscall FUN_00c41050_Class::AssignRef(S_0044dd60** other)
{
    S_0044dd60* unk0;
    int unk1;
    int unk2;
    if (m_pIntegerData != *other) {
        if (m_pIntegerData) {
            m_pIntegerData->BSTask_int64_DecRefCount();
        }

        m_pIntegerData = *other;

        if (m_pIntegerData) {
            S_0044dd60* temp = m_pIntegerData;
            FUN_00fdf1c0(reinterpret_cast<char*>(temp) + 8);
        }
    }

    return this;
}

struct FUN_00c42b60_class;
struct SpawnHeap_cls { void __thiscall MemoryManager_Deallocate(void* pObject); };
extern "C" char DAT_011f6238;
typedef void (__stdcall *S_00c422d0_IAT_Fn)(void*);
extern "C" S_00c422d0_IAT_Fn DAT_0fdf050;
struct S_00c422d0_Entry { unsigned int unk00; FUN_00c42b60_class* m_pObject; };
struct S_00c422d0_Foo {
    unsigned int m_uiItemCount;
    unsigned int m_unk04;
    S_00c422d0_Entry* m_pEntries;
    void __thiscall DestroyEntries();
};
// @fnv 0x00c422d0
void __thiscall S_00c422d0_Foo::DestroyEntries()
{
    unsigned int uiIndex;
    unsigned int V_h;
    FUN_00c42b60_class* pItem;
    FUN_00c42b60_class* pBase;
    FUN_00c42b60_class* V_k;
    S_00c422d0_Entry* pObject;
    unsigned int V_n;
    for (uiIndex = 0; uiIndex < (V_h = m_uiItemCount); uiIndex++) {
        pItem = m_pEntries[uiIndex].m_pObject;
        pBase = pItem;
        pBase != 0 ? (V_k = pBase, V_k->ProcessEntries_00c42b60(), ((0,1)&1) ? reinterpret_cast<SpawnHeap_cls*>(&DAT_011f6238)->MemoryManager_Deallocate(V_k) : (void)0, V_k) : 0;
    }
    pObject = (S_00c422d0_Entry*)m_pEntries;
    reinterpret_cast<SpawnHeap_cls*>(&DAT_011f6238)->MemoryManager_Deallocate(pObject);
    V_n = m_unk04;
    DAT_0fdf050((void*)V_n);
}

class FUN_00c42b40_cls
{
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int m_20;
    void Step();
    void StepUntilStateIsZero();
};

// Calls Step repeatedly while m_20 is non-zero, stopping once it reaches zero.
// @fnv 0x00c42b40
// src: GUESS 0x00c42b40 (confidence: medium)
void FUN_00c42b40_cls::StepUntilStateIsZero()
{
    unsigned int scratch[22];
    int tmp;
    while (m_20 != 0)
    {
        Step();
    }
}

void* __cdecl Object_DispatchCommandFour(unsigned int size);
extern int DAT_011f49e0;

struct SpawnedObject_b9874 {
    char m00[0x10];
    SpawnedObject_b9874();
    void Init(int* arg);
    static void* operator new(unsigned int size) { return Object_DispatchCommandFour(size); }
};

// @fnv 0x00c43190
// src: EXE 0x00c43190
SpawnedObject_b9874* BSXFlags_CreateObject() {
    SpawnedObject_b9874* obj = new SpawnedObject_b9874();
    obj->Init(&DAT_011f49e0);
    return obj;
}

struct S_00c437c0_Obj {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4;
    static void* operator new(unsigned int);
    S_00c437c0_Obj();
};
struct S_00c437c0 : FUN_00c43850_Class {
    S_00c437c0_Obj* CreateObject(unsigned int stream);
};
// @fnv 0x00c437c0
S_00c437c0_Obj* S_00c437c0::CreateObject(unsigned int stream)
{
    S_00c437c0_Obj* p = new S_00c437c0_Obj;
    this->BSNiNode_CopyMembers(p, stream);
    return p;
}

void* __cdecl Object_DispatchCommandFour(unsigned int size);

struct SpawnedObject_b9504 : FUN_00c43660 {
    static void* operator new(unsigned int size) throw() { return Object_DispatchCommandFour(size); }
};

// Allocates and returns a new SpawnedObject_b9504 instance via its class-specific operator new.
// @fnv 0x00c43a30
// src: EXE 0x00c43a30
FUN_00c43660* __cdecl BSValueNode_CreateObject() {
    return new SpawnedObject_b9504();
}

class FUN_00c43be0_cls {
public:
    int unk00;
    int unk04;
    char* m_08;
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
    int m_b0;
    bool HasTrailingSuffix();
};

extern "C" int __cdecl FUN_00ec6130(const char* s);
extern "C" int __cdecl FUN_00eca6d3(const char* s);

// @fnv 0x00c43be0
bool FUN_00c43be0_cls::HasTrailingSuffix()
{
    bool found3 = false;
    char* name = m_08;
    char* p4 = name;
    int len4 = FUN_00ec6130(p4);
    int i = 1;
    while (((p4[len4 - i] >= 0x30 && p4[len4 - i] <= 0x39) || p4[len4 - i] == 0x23 || p4[len4 - i] == 0x40) && (unsigned int)i <= (unsigned int)len4) {
        i++;
    }
    p4 = p4 + (len4 - i) + 1;
    if (*p4 != 0) {
        found3 = true;
    }
    m_b0 = FUN_00eca6d3(p4);
    return found3;
}

// CopyStringBeforeColon
// Copies the leading part of a path (up to the first ':') into a caller buffer.

struct FUN_00c43e00_Obj {
    int unk00;
    int unk04;
    char* m_pStr;
};

extern "C" char* __cdecl FNV_StrChr(const char* s, int c);
extern "C" unsigned int __cdecl FNV_StrLen(const char* s);
extern "C" void __cdecl FNV_CopyPath(char* dest, unsigned int destSize, const char* src, unsigned int count);

// Copies the object's string into pDest up to the first ':' (or the whole string), null-terminating it; clears pDest if the string is null.
// @fnv 0x00c43e00
void __cdecl CopyStringBeforeColon(FUN_00c43e00_Obj* pObj, char* pDest)
{
    if (pDest) {
        unsigned int nLen = 0;
        *pDest = 0;
        const char* pStr = pObj->m_pStr;
        if (pStr) {
            const char* pColon = FNV_StrChr(pStr, ':');
            nLen = pColon ? (unsigned int)(pColon - pStr) : FNV_StrLen(pStr);
            FNV_CopyPath(pDest, nLen + 1, pStr, nLen);
            pDest[nLen] = 0;
        }
    }
}

struct S_00c44d90_Item;

struct S_00c44d90_Cls {
    void (__cdecl *m_pfnWork)(int, int);
    int* m_pArg;
    unsigned int m_uiCount;
    volatile long m_lIndex;
};

// Calls m_pfnWork for each index obtained by incrementing m_lIndex, while the index is below m_uiCount.
// @fnv 0x00c44d90
void __cdecl RunWorkItems(S_00c44d90_Cls* pWorkQueue)
{
    S_00c44d90_Cls* p = pWorkQueue;
    unsigned int i = 0;
    while (i < p->m_uiCount) {
        i = InterlockedIncrement(&p->m_lIndex);
        i = i - 1;
        if (i < p->m_uiCount)
            p->m_pfnWork(*(int*)&p->m_pArg, i);
    }
}

class NiStream;

void NiStreamLoadBinary_char_00a643b0(NiStream& kStream, bool& m_bHeaderParsed);

class BSNodeC45 : public NiNode {
public:
    short unkAC;
    bool m_bFlagAE;
    bool m_bFlagAF;
    void SetFlag(bool m_bHeaderParsed);
    void BSRangeNode_LoadBinary(NiStream& kStream);
};

// Loads the base node binary, reads three booleans from the stream into m_bFlagAE, m_bFlagAF and SetFlag.
// @fnv 0x00c45220
// src: XBOX_PDB 0x00c45220
void BSNodeC45::BSRangeNode_LoadBinary(NiStream& kStream)
{
    NiNode::LoadBinary(kStream);

    bool m_bHeaderParsed;
    NiStreamLoadBinary_char_00a643b0(kStream, m_bHeaderParsed);
    bool bFirst = m_bHeaderParsed;
    m_bFlagAE = bFirst;

    NiStreamLoadBinary_char_00a643b0(kStream, m_bHeaderParsed);
    bool bSecond = m_bHeaderParsed;
    m_bFlagAF = bSecond;

    NiStreamLoadBinary_char_00a643b0(kStream, m_bHeaderParsed);
    SetFlag(m_bHeaderParsed);
}

struct S_00c45380_Base { bool NiNode_IsEqual(S_00c45380_Base*); };
struct S_00c45380_Obj : S_00c45380_Base {
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
    int unkA0;
    int unkA4;
    int unkA8;
    unsigned char unkAC;
    unsigned char unkAD;
    unsigned char unkAE;
    unsigned char unkAF;
    char BSRangeNode_IsEqual(S_00c45380_Obj* other);
};

// Calls FUN_00a5e600 on other, then if true compares unkAE, unkAF and unkAD against other's and returns the result.
// @fnv 0x00c45380
// src: XBOX_PDB 0x00c45380
char S_00c45380_Obj::BSRangeNode_IsEqual(S_00c45380_Obj* other) {
    bool r7 = NiNode_IsEqual(other);
    if (r7) {
        S_00c45380_Obj* oB = other;
        unsigned char a8, b, c5, d, e, f7;
        r7 = ((a8 = unkAE, b = oB->unkAE, a8 == b) && (c5 = unkAF, d = oB->unkAF, c5 == d) && (e = unkAD, f7 = oB->unkAD, e == f7)) ? 1 : 0;
    }
    return r7;
}

extern "C" __declspec(dllimport) int __stdcall fnv_Import_TryEnterCriticalSection(void* cs);
extern "C" __declspec(dllimport) void __stdcall fnv_Import_LeaveCriticalSection(void* cs);

class GameLockA {
public:
    bool BSSpinLock_TryLock();
    void BSSpinLock_Lock(int a);
};

class GameLockB {
public:
    void FUN_00c46080();
};

extern GameLockA DAT_01202e40;
extern GameLockB DAT_01202e20;
extern unsigned int DAT_01202e44;
extern unsigned int DAT_011f4380;

void __cdecl TruncateStringToMaxLength();

struct FUN_00c459d0_frame {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};

// @fnv 0x00c459d0
// src: XBOX_PDB 0x00c459d0
void __cdecl NiObjectGarbage_ClearAll(unsigned char a1)
{
    FUN_00c459d0_frame frame;
    bool flag = true;
    bool got;
    if (a1 != 0) {
        flag = DAT_01202e40.BSSpinLock_TryLock();
    } else {
        DAT_01202e40.BSSpinLock_Lock(0);
    }
    if (flag) {
        got = fnv_Import_TryEnterCriticalSection(&DAT_011f4380) ? true : false;
        if (!got) {
            if (--DAT_01202e44 == 0) {
                *reinterpret_cast<unsigned int*>(&DAT_01202e40) = 0;
            }
            return;
        }
    }
    if (flag) {
        DAT_01202e20.FUN_00c46080();
        TruncateStringToMaxLength();
        fnv_Import_LeaveCriticalSection(&DAT_011f4380);
        if (--DAT_01202e44 == 0) {
            *reinterpret_cast<unsigned int*>(&DAT_01202e40) = 0;
        }
    }
}

namespace fnv_00c45a80 {
// TruncateStringToMaxLength: clamps the maximum length of the global fixed string object
// DAT_01202e20 down to 100 characters when it has grown past that limit.


extern NiTObjectArray<NiPointer<NiRefObject> > DAT_01202e20;
extern unsigned short DAT_01202e2a;

// Scratch space kept by the original implementation.
struct ScratchBuffer
{
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i12;
    int m_i16;
    int m_i20;
    int m_i24;
    int m_i28;
    int m_i32;
    int m_i36;
    int m_i40;
    int m_i44;
    int m_i48;
    int m_i52;
    int m_i56;
    int m_i60;
    int m_i64;
    int m_i68;
    int m_i72;
    int m_i76;
    int m_i80;
    int m_i84;
    int m_i88;
    int m_i92;
    int m_i96;
    int m_i100;
};

// If the string's length exceeds 100, resizes it to a maximum length of 100 via FUN_00c45b20.
// @fnv 0x00c45a80
void TruncateStringToMaxLength()
{
    ScratchBuffer scratch;
    if ((unsigned int)DAT_01202e2a > 100u)
    {
        DAT_01202e20.SetSize(100);
    }
}
}  // namespace fnv_00c45a80

namespace fnv_00c45ae0 {
extern "C" unsigned short DAT_01202e2a;


extern "C" NiTObjectArray<NiPointer<NiRefObject> > DAT_01202e20;

struct FUN_00c45ae0_LocalState {
    int field00;
    int field04;
    int field08;
    int field0C;
    int field10;
    int field14;
    int field18;
    int field1C;
    int field20;
    int field24;
    int field28;
    int field2C;
    int field30;
    int field34;
    int field38;
    int field3C;
    int field40;
    int field44;
    int field48;
    int field4C;
    int field50;
    int field54;
    int field58;
    int field5C;
    int field60;
    int field64;
};

// If the global DAT_01202e2a is less than value, calls FUN_00c45b20 on DAT_01202e20 with value.
// @fnv 0x00c45ae0
// src: COMMUNITY 0x00c45ae0
void __cdecl NiObjectGarbage_IncreaseBuffer(unsigned int value)
{
    FUN_00c45ae0_LocalState localState;

    if (DAT_01202e2a < value) {
        DAT_01202e20.SetSize(value);
    }
}
}  // namespace fnv_00c45ae0

template <>
void NiTArray<NiPointer<NiRefObject>, NiTNewInterface<NiPointer<NiRefObject> > >::SetAt(unsigned int index, const NiPointer<NiRefObject>& value);

// AppendElement @ 0x00c45e00 (75 bytes) - __thiscall member, 1 stack parameter (ret 4).
// Add(element) of an NiTArray-style growable array:
//   +0x00 vtable, +0x04 m_pBase, +0x08 m_usMaxSize (u16),
//   +0x0A m_usSize (u16), +0x0C m_usESize (u16), +0x0E m_usGrowBy (u16).
// index = m_usSize; if (index >= m_usMaxSize) grow via FUN_00c45b20
// (m_usGrowBy + index); store element at index via SetSlot; return index.


// Appends uiElement to the array, growing it by m_usGrowBy if full, and returns the index where it was stored.
// @fnv 0x00c45e00
template <>
unsigned int NiTArray<NiPointer<NiRefObject>, NiTNewInterface<NiPointer<NiRefObject> > >::Add(const NiPointer<NiRefObject>& uiElement)
{
    struct FUN_00c45e00_pad
    {
        int m00; int m04; int m08; int m0c; int m10; int m14;
        int m18; int m1c; int m20; int m24; int m28; int m2c;
        int m30; int m34; int m38; int m3c; int m40; int m44;
        int m48; int m4c; int m50; int m54; int m58; int m5c;
    };
    FUN_00c45e00_pad kPad;
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
        {
            SetSize(m_usGrowBy + uiIndex);
        }
        SetAt(uiIndex, uiElement);
        return uiIndex;
    }
}

namespace fnv_00c46420 {
struct S_00c46420_Callback
{
    virtual void unk00();
    virtual void Slot1();
    void* unk08;
};

struct S_00c46420_Class
{
    S_00c46420_Callback* unk00;

    void* FUN_00c46420(unsigned int flags);
};

struct S_00aa4060_Class
{
    void MemoryManager_Deallocate(void*);
};

extern S_00aa4060_Class DAT_011f6238;

extern "C" void* DAT_00fdf1c4;

extern "C" void __cdecl UpdateState_00ae9290();
extern "C" void __stdcall FUN_00ec5fce(
    void* object,
    int elementSize,
    int count,
    void (__cdecl *callback)()
);

// @fnv 0x00c46420
void* S_00c46420_Class::FUN_00c46420(unsigned int flags)
{
    if (flags & 2)
    {
        FUN_00ec5fce(
            this,
            4,
            reinterpret_cast<int*>(this)[-1],
            UpdateState_00ae9290
        );

        if (flags & 1)
        {
            DAT_011f6238.MemoryManager_Deallocate(
                reinterpret_cast<char*>(this) - 4
            );
        }

        return reinterpret_cast<char*>(this) - 4;
    }

    if (this->unk00 != 0)
    {
        S_00c46420_Callback* p = this->unk00;

        if (reinterpret_cast<int (__stdcall *)(void*)>(DAT_00fdf1c4)(
                reinterpret_cast<char*>(p) + 4) == 0)
        {
            p->Slot1();
        }
    }

    if (flags & 1)
    {
        DAT_011f6238.MemoryManager_Deallocate(this);
    }

    return this;
}
}  // namespace fnv_00c46420

namespace fnv_00c464c0 {
extern int DAT_010c1c5c;

class FUN_00c464c0_child {
public:
    void* FUN_00c46420(int aiMode);
};

class AudioPool {
public:
    void MemoryManager_Deallocate(void* apMemory);
};
extern AudioPool DAT_011f6238;

struct FUN_00c464c0_cls {
    int m_vptr;
    FUN_00c464c0_child* m_04;

    FUN_00c464c0_cls* FUN_00c464c0(unsigned int acFlags);
};

// @fnv 0x00c464c0
FUN_00c464c0_cls* FUN_00c464c0_cls::FUN_00c464c0(unsigned int acFlags)
{
    m_vptr = (int)&DAT_010c1c5c;
    FUN_00c464c0_child* pObj = m_04;
    FUN_00c464c0_child* pChild_;
    FUN_00c464c0_child* pExtra;
    FUN_00c464c0_child* pSecond = pObj;
    pChild_ = pSecond;
    (pChild_ != 0) ? pChild_->FUN_00c46420(3) : 0;
    if (acFlags & 1) {
        DAT_011f6238.MemoryManager_Deallocate(this);
    }
    return this;
}
}  // namespace fnv_00c464c0

extern int DAT_010c1c5c;
extern void* __cdecl Runtime_GetIndexedValue_00c46170(unsigned int count);


// Sets the vtable, stores param1 and param2, zeroes two fields, and allocates m_result for param1 entries when param1 is greater than zero.
// Initializes the object by setting the vtable, storing param1 and usValue, zeroing two fields, and allocating m_result via FUN_00c46170 when param1 is positive.
// @fnv 0x00c46530
template <>
NiTArray<NiPointer<NiRefObject>, NiTNewInterface<NiPointer<NiRefObject> > >::NiTArray(unsigned int param1, unsigned int usValue)
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;

    this->m_usMaxSize = (unsigned short)param1;
    this->m_usGrowBy = (unsigned short)usValue;
    this->m_usSize = 0;
    this->m_usESize = 0;

    if (this->m_usMaxSize > 0) {
        this->m_pBase = (NiPointer<NiRefObject>*)Runtime_GetIndexedValue_00c46170(this->m_usMaxSize);
    } else {
        this->m_pBase = 0;
    }

}

class FUN_00c46860_cls {
public:
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    float m_18;

    bool unkCheck(FUN_00c46860_cls* other);
    bool BSWindModifier_IsEqual(FUN_00c46860_cls* other);
};

// Calls unkCheck on other and, if it passes, returns whether m_18 equals other's m_18.
// @fnv 0x00c46860
// src: XBOX_PDB 0x00c46860
bool FUN_00c46860_cls::BSWindModifier_IsEqual(FUN_00c46860_cls* other) {
    bool ok = unkCheck(other);
    if (ok) {
        FUN_00c46860_cls* p = other;
        float a = m_18;
        ok = (a == p->m_18) ? 1 : 0;
    }
    return ok;
}

extern double DAT_01017a40;

struct FNVPad18
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct FNVPad1C
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};

struct FNVVec3B
{
    float x;
    float y;
    float z;
    void Init(float s);
};

extern FNVVec3B DAT_01202e68;

FNVVec3B* __cdecl CombineVec3B(FNVVec3B* dst, FNVVec3B* a, FNVVec3B* b);

// Scales a1 by DAT_01017a40, builds a vector from it and a2, combines them, and stores the result in DAT_01202e68.
// @fnv 0x00c468c0
// src: XBOX_PDB 0x00c468c0
void __cdecl BSWindModifier_SetWind(float a1, float a2)
{
    FNVVec3B da7;
    {
    FNVVec3B erdl2;
    FNVVec3B acgt2;
    FNVPad18 eui;
    FNVPad1C tlp;

    a1 = (float)((double)a1 * DAT_01017a40);
    da7.x = 0.0f;
    da7.y = a1;
    da7.z = 0.0f;
    erdl2.Init(a2);
    DAT_01202e68 = *CombineVec3B(&acgt2, &da7, &erdl2);
    }}

class C46D60Stream {
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
    virtual void vfunc0B();
    virtual void SaveLinkID(void* pvObject);
};

class C46D60Base {
public:
    void NiNode_SaveBinary(C46D60Stream& kStream);
};

class C46D60Node : public C46D60Base {
public:
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
    int unkA0;
    int unkA4;
    int unkA8;
    void* m_pkChild;

    void BSMultiBoundNode_SaveBinary(C46D60Stream& kStream);
};

// @fnv 0x00c46d60
// src: XBOX_PDB 0x00c46d60
void C46D60Node::BSMultiBoundNode_SaveBinary(C46D60Stream& kStream) {
    C46D60Base::NiNode_SaveBinary(kStream);
    void* pkChild = m_pkChild;
    kStream.SaveLinkID(pkChild);
}

struct FUN_00c46da0_class : BaseForCall {
    bool __thiscall BSMultiBoundNode_IsEqual(NiObject* other);
};
// Calls FUN_00a5e600 on other, then returns whether the int at offset 0xAC matches between this and other.
// @fnv 0x00c46da0
// src: XBOX_PDB 0x00c46da0
bool __thiscall FUN_00c46da0_class::BSMultiBoundNode_IsEqual(NiObject* other)
{
    bool result = NiNode_IsEqual(other);
    NiObject* comparison = other;
    if (static_cast<int>(static_cast<unsigned char>(static_cast<int>(
        *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0xAC) ==
        *reinterpret_cast<int*>(reinterpret_cast<char*>(comparison) + 0xAC))))) {
        result = true;
    } else {
        result = false;
    }
    return result;
}

void* __cdecl Object_DispatchCommandFour(unsigned int size);

struct NewObject_b9649 {
    unsigned int unk00;
    unsigned int unk04;
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
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    NewObject_b9649();
    static void* operator new(unsigned int size) { return Object_DispatchCommandFour(size); }
};

// Allocates and constructs a NewObject_b9649 via its operator new and returns the pointer.
// @fnv 0x00c46df0
NewObject_b9649* CreateNewObject() {
    return new NewObject_b9649();
}

struct UpdateContext {
 int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
 int unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
 int unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c;
 int unk60,unk64,unk68,unk6c,unk70,unk74,unk78,unk7c;
 int unk80,unk84,unk88,unk8c;
 int state;
};
struct BoundBase {
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
 virtual void v35();
 virtual void v36();
 virtual void v37();
 virtual void v38();
 virtual bool Test(void*);
};
struct BoundTester : BoundBase {
 int unk04;
 int state;
};
struct BoundReference { int unk00,unk04,unk08; BoundTester* object; };
struct UpdateChild { void FUN_00a59e00(UpdateContext*); };
struct UpdateOwner {
 int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
 int unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
 int unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c;
 int unk60,unk64,unk68,unk6c,unk70,unk74,unk78,unk7c;
 int unk80,unk84,unk88,unk8c,unk90,unk94,unk98,unk9c;
 UpdateChild** children;
 unsigned short capacity,count,enabled,unkAA;
 BoundReference* reference;
 int replacement;
 void BSMultiBoundNode_OnVisible(UpdateContext*);
};
// @fnv 0x00c46f60
// src: XBOX_PDB 0x00c46f60
void UpdateOwner::BSMultiBoundNode_OnVisible(UpdateContext* pContext) {
 UpdateChild** slot;
 int replacementState2;
 BoundTester* cacheObject5;
 BoundReference* cacheReference;
 BoundTester* volatile _unknownObject;
 BoundReference* unknownReference;
 BoundTester* volatile specialObject2;
 BoundReference* specialReference6;
 int kRequestState;
 BoundTester* aReadObject;
 BoundReference* readReference8;
 BoundReference* checkReference;
 UpdateChild* child;
 unsigned int i;
 int state2;
 bool accepted9;
 int oldState9;
 UpdateContext* context4;

 context4=0;
 oldState9=0;
 if (!enabled) return;
 context4=pContext;
 oldState9=context4->state;
 accepted9=true;
 if (oldState9!=3 && oldState9!=1) {
  checkReference=reference;
  if (checkReference) {
   readReference8=reference;
   aReadObject=readReference8->object;
   state2=aReadObject->state;
   kRequestState=context4->state;
   if (kRequestState==4) {
    specialReference6=reference;
    specialObject2=specialReference6->object;
    accepted9=specialObject2->Test(reinterpret_cast<char*>(pContext)+0x2c);
    state2=accepted9?1:2;
   }
   switch(state2) {
   case 0:
    unknownReference=reference;
    _unknownObject=unknownReference->object;
    accepted9=_unknownObject->Test(reinterpret_cast<char*>(pContext)+0x2c);
    cacheReference=reference;
    cacheObject5=cacheReference->object;
    cacheObject5->state=accepted9?1:2;
    break;
   case 1: accepted9=true;break;
   default:accepted9=false;break;
   }
  }
 }
 if (!accepted9) return;
 if (oldState9!=3) {
  replacementState2=replacement;
  context4->state=replacementState2;
 }
 for (i=0;i<count;i++) {
  slot=&children[i];
  child=*slot;
  if (child) child->FUN_00a59e00(pContext);
 }
 context4->state=oldState9;
}

// Stand-in model of CheckProcStateAndPlane (0x00c47150, 252 bytes) - an /Od member function.
//
// The original is:
//   bool CheckProcStateAndPlane(Vec3 pt, Proc* proc, Plane* plane)
//   {
//       if (proc->unk90 == 3 || proc->unk90 == 1) return true;
//       if (plane) {
//           obj.FUN_0045c620();                  // 0x0045c620
//           plane->FUN_00c33870(pt, &obj);      // 0x00c33870
//           Target* t = this->unkAC->unk0c;
//           if (t->v40(&obj)) {                 // vtable slot 0xA0
//               Target* u = this->unkAC->unk0c;
//               u->unk08 = 2;
//               return false;
//           }
//       }
//       return true;
//   }
//
// The local NAMES below are not arbitrary: under /Od the frame slot of every local is
// decided by the 16-bucket hash of its name, so the names are chosen to put each local on
// the frame slot the original uses (see attempts.txt).  The three dead int locals exist
// only to reserve the four unused 4-byte slots that the original's frame shows.

struct FNV_Vec3 {
    float x;
    float y;
    float z;
};

struct FNV_Proc {
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
};

struct FNV_Local {
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
    void FUN_0045c620();
};

struct FNV_Target {
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
    virtual bool v40(FNV_Local* pObj);
    int unk04;
    int unk08;
};

struct FNV_Holder {
    int unk00;
    int unk04;
    int unk08;
    FNV_Target* unk0c;
};

struct FNV_Plane {
    void BSOcclusionPlane_UpdateFrustumPlanes(FNV_Vec3 pt, FNV_Local* pObj);
};

struct FNV_Owner {
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
    int unkA0;
    int unkA4;
    int unkA8;
    FNV_Holder* unkAC;
    bool CheckProcStateAndPlane(FNV_Vec3 pt, FNV_Proc* proc, FNV_Plane* plane);
};

// @fnv 0x00c47150
bool FNV_Owner::CheckProcStateAndPlane(FNV_Vec3 vecPoint, FNV_Proc* proc, FNV_Plane* plane)
{
    int F;                       // dead local, frame filler only
    int C;                       // dead local, frame filler only
    int EG;                      // dead local, frame filler only
    FNV_Local B;                 // the 0x64-byte object at [ebp-0x70]

    FNV_Proc* J = proc;          // the copied pointer, [ebp-4]
    int K;                       // the first state,  [ebp-0x74]
    int b;                       // the second state, [ebp-0x78]
    if ((K = J->unk90) == 3 || (b = J->unk90) == 1) return true;
    if (plane) {
        B.FUN_0045c620();        // the object's initialiser, 0x0045c620
        plane->BSOcclusionPlane_UpdateFrustumPlanes(vecPoint, &B);
        FNV_Holder* A = this->unkAC;             // [ebp-0x84]
        FNV_Target* volatile c = A->unk0c;      // [ebp-0x88]
        if (c->v40(&B)) {
            FNV_Holder* I = this->unkAC;         // [ebp-0x8c]
            FNV_Target* L = I->unk0c;            // [ebp-0x90]
            L->unk08 = 2;
            return false;
        }
    }
    return true;
}

struct TargetCls {
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
    virtual void v35(int a);
};

struct OwnerCls {
    int unk00;
    int unk01;
    int unk02;
    int unk03;
    int unk04;
    int unk05;
    int unk06;
    int unk07;
    int unk08;
    int unk09;
    int unk10;
    int unk11;
    int unk12;
    int unk13;
    int unk14;
    int unk15;
    int unk16;
    int unk17;
    int unk18;
    int unk19;
    int unk20;
    int unk21;
    int unk22;
    int unk23;
    int unk24;
    int unk25;
    int unk26;
    int unk27;
    int unk28;
    int unk29;
    int unk30;
    int unk31;
    int unk32;
    int unk33;
    int unk34;
    int unk35;
    int unk36;
    int unk37;
    int unk38;
    int unk39;
    int unk40;
    int unk41;
    int unk42;
    TargetCls* m_pFlagTarget;
    void CallVirtual35(int a);
};

// @fnv 0x00c47530
void OwnerCls::CallVirtual35(int aiValue)
{
    TargetCls* volatile pTarget = m_pFlagTarget;
    pTarget->v35(aiValue);
}

struct Rec64 {
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
};
struct Vec12 { int x; int y; int z; };
struct Elem0C { int a; int b; int c; };
struct ArrRec64 {
    void* vtbl;
    Rec64* m_pData;
    int unk08;
    unsigned int m_uiSize;
    void SetSizeRec(unsigned int n, bool b);
};
struct ArrElem0C {
    void* vtbl;
    Elem0C* m_pData;
    int unk08;
    unsigned int m_uiSize;
    void Resize(unsigned int n, bool b);
};
struct Obj_c477f0 {
    unsigned char b00;
    ArrRec64 m_kArr04;
    ArrElem0C m_kArr14;
    int unk24;
    int unk28;
    int unk2C;
    Rec64 m_kRec30;
    Vec12 m_kVec94;
    void CopyTo(Obj_c477f0* dst);
};
// Copies scalar fields, m_kVec94, m_kRec30 and both arrays (resizing the destination arrays first) from this object into dst.
// @fnv 0x00c477f0
void Obj_c477f0::CopyTo(Obj_c477f0* apDest)
{
    unsigned int i;
    unsigned int j;
    apDest->unk28 = unk28;
    apDest->unk24 = unk24;
    apDest->unk2C = unk2C;
    apDest->m_kVec94 = m_kVec94;
    apDest->m_kRec30 = m_kRec30;
    apDest->b00 = b00;
    {
        unsigned int uiSize = m_kArr14.m_uiSize;
        apDest->m_kArr14.Resize(uiSize, true);
    }
    {
    unsigned int ItemUpdateArray;
    for (i = 0; i < (ItemUpdateArray = m_kArr14.m_uiSize); i++) {
        {
            Elem0C* pA = &m_kArr14.m_pData[i];
            apDest->m_kArr14.m_pData[i].a = pA->a;
        }
        {
            Elem0C* pB = &m_kArr14.m_pData[i];
            apDest->m_kArr14.m_pData[i].b = pB->b;
        }
        {
            Elem0C* pC = &m_kArr14.m_pData[i];
            apDest->m_kArr14.m_pData[i].c = pC->c;
        }
    }
    }
    {
        unsigned int uiRecCount = m_kArr04.m_uiSize;
        apDest->m_kArr04.SetSizeRec(uiRecCount, true);
    }
    {
    unsigned int uiCount2;
    for (j = 0; j < (uiCount2 = m_kArr04.m_uiSize); j++) {
        {
            Rec64* pR = &m_kArr04.m_pData[j];
            apDest->m_kArr04.m_pData[j] = *pR;
        }
    }
    }
}

class FUN_00c47980_sub
{
public:
    void SetFromFrustum(void* a, void* b);
};

class FUN_00c47980_arg
{
public:
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
};

class FUN_00c47980_vec3
{
public:
    int x;
    int y;
    int z;
};

class FUN_00c47980_cls
{
public:
    void InitFromArg(FUN_00c47980_arg* a1);

    unsigned char m_00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int m_24;
    int m_28;
    int m_2c;
    FUN_00c47980_sub m_30;
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
    FUN_00c47980_vec3 m_94;
    unsigned char m_A0;
};

// @fnv 0x00c47980
void FUN_00c47980_cls::InitFromArg(FUN_00c47980_arg* a1)
{
    if (a1 != 0)
    {
        m_30.SetFromFrustum((void*)&a1->unkDC, (void*)&a1->unk68);
        m_94 = *(FUN_00c47980_vec3*)&a1->unk8C;
    }
    m_24 = 0;
    m_28 = 0;
    m_00 = 0;
    m_2c = 0;
    m_A0 = 0;
}

struct Sub_c47ae0
{
    int unk00;
    void FUN_00c4a1e0(int, bool);
};

struct FUN_00c47ae0_cls
{
    unsigned char m_00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    Sub_c47ae0 m_14;
    char* m_18;
    int unk1C;
    int m_20;
    int unk24;
    int m_28;
    void BSCompoundFrustum_EndGroup();
};

// @fnv 0x00c47ae0
// src: COMMUNITY 0x00c47ae0
void FUN_00c47ae0_cls::BSCompoundFrustum_EndGroup()
{
    int cap = m_20;
    if (m_28 + 1 >= cap)
    {
        int a = m_20;
        m_14.FUN_00c4a1e0(a + 10, true);
    }
    m_00 = 0;
    *(int*)(m_18 + m_28 * 12) = 6;
    m_28 = m_28 + 1;
}

struct NavEntryItem {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int m_60;
};

class NavAllocator {
public:
    int* Alloc(unsigned int size, unsigned int tag);
};

class NavHolder {
public:
    NavAllocator* GetAllocator();
};

extern NavHolder g_navHolder;
extern unsigned int g_navTag;

class NavEntryOwner {
public:
    int unk00;
    int unk04;
    NavEntryItem* m_08;
    int unk0C;
    int m_10;
    int unk14, unk18, unk1C, unk20;
    int m_24;
    int unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44;
    int unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64;
    int unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84;
    int unk88, unk8C;
    int m_90;

    int* BuildEntryValueArray();
};

// @fnv 0x00c49050
int* NavEntryOwner::BuildEntryValueArray() {
    NavAllocator* alloc7 = g_navHolder.GetAllocator();
    int count = this->m_10;
    int* result5 = alloc7->Alloc(count * 4, g_navTag);
    int firstB = this->m_90;
    result5[0] = firstB;
    int i6;
    int limit;
    NavEntryItem* item;
    int value7;
    for (i6 = 1; i6 < this->m_24 + 1 && i6 < (limit = this->m_10); i6++) {
        item = this->m_08 + (i6 - 1);
        value7 = item->m_60;
        result5[i6] = value7;
    }
    return result5;
}

namespace fnv_00c49100 {
struct FUN_00aa42e0_holder;

struct GlobalGetter
{
    FUN_00aa42e0_holder* Get();
};

extern unsigned char DAT_011f6238;

class ActorTable
{
public:
    unsigned char unk00[8];
    char* m_08;
    unsigned char unk0C[4];
    int m_10;
    unsigned char unk14[0x10];
    int m_24;
    unsigned char unk28[0x68];
    int m_90;

    void SetActorList(int* list);
};

struct FUN_00aa42e0_holder
{
    void Store(int* arg);
};

// @fnv 0x00c49100
void ActorTable::SetActorList(int* list)
{
    int _first = *list;
    m_90 = _first;
    int i;
    int count4;
    for (i = 1; i < m_24 + 1 && i < (count4 = m_10); i++)
    {
        int value7 = list[i];
        char* entry = m_08 + (i - 1) * 100;
        *(int*)(entry + 0x60) = value7;
    }
    FUN_00aa42e0_holder* holder = reinterpret_cast<GlobalGetter*>(&DAT_011f6238)->Get();
    holder->Store(list);
}
}  // namespace fnv_00c49100

extern FNV_Vec3 DAT_011f426c;
struct SSNode {
 bool __thiscall BSOcclusionPlane_WithinFrustumDistFirst(void*, void*);
 bool __thiscall BSOcclusionPlane_WithinFrustum(void*, int, FNV_Vec3);
 bool __thiscall BSOcclusionPlane_CompletelyWithinFrustum(void*);
};
struct DecisionNode { int type; int trueIndex; int falseIndex; };
struct VolumeRecord {
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
};
struct DecisionTree {
 int unk00;
 int unk04;
 VolumeRecord* volumes;
 int unk0c;
 int unk10;
 int unk14;
 DecisionNode* nodes;
 int unk1c;
 int unk20;
 int unk24;
 int nodeCount;
 int rootIndex;
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
 int unk90;
 int unk94;
 int unk98;
 int unk9c;
 bool skipBounds;
 bool __thiscall EvaluateQuery(SSNode* query);
};
// @fnv 0x00c49560
bool DecisionTree::EvaluateQuery(SSNode* query) {
 VolumeRecord* result = 0;
 bool bResult = true;
 if (!skipBounds)
  bResult = query->BSOcclusionPlane_WithinFrustumDistFirst(&unk30, &unk94);
 if (bResult && nodeCount > 0) {
  int index = rootIndex;
  while (nodes[index].type != 2 && nodes[index].type != 3) {
   bool passed = false;
   switch (nodes[index].type) {
   case 7: {
    DecisionNode* next = &nodes[index+1];
    result = &volumes[next->type];
    passed = query->BSOcclusionPlane_WithinFrustum(result, 0, DAT_011f426c);
    break;
   }
   case 8: {
    DecisionNode* next = &nodes[index+1];
    result = &volumes[next->type];
    passed = !query->BSOcclusionPlane_CompletelyWithinFrustum(result);
    break;
   }
   }
   index = passed ? nodes[index].trueIndex : nodes[index].falseIndex;
  }
  bResult = nodes[index].type == 2;
 }
 return bResult;
}

extern int DAT_010c1e9c;

struct FUN_00c4a1b0_cls
{
    int m_vptr;

    FUN_00c4a1b0_cls* SetVtableAndProcessState_00c4a1b0();
};

// Sets m_vptr to &DAT_010c1e9c, calls FUN_00c4a5a0 with 0, 0, and returns this.
// @fnv 0x00c4a1b0
// src: GUESS 0x00c4a1b0 (confidence: low)
FUN_00c4a1b0_cls* FUN_00c4a1b0_cls::SetVtableAndProcessState_00c4a1b0()
{
    // two spare scratch words; they only shape the stack frame of the
    // original routine.
    int iScratch0;
    int iScratch1;

    m_vptr = reinterpret_cast<int>(&DAT_010c1e9c);
    reinterpret_cast<FUN_00c4a5a0_class*>(this)->BSSimpleArray_BSCompoundFrustum_FunctionOp_1024_InitialSetup(0, 0);
    return this;
}

class CachedRef_b5611 {
public:
    virtual void v00();
    virtual void* v01(unsigned int a);
    virtual void v02(void* a);
    virtual void* v03(void* b, unsigned int a);
    void CopyRange_b5611(void* c, void* b, unsigned int a);
    void UpdateCachedRef(unsigned int a1, unsigned int a2);

    void* m_pCachedReference;
    unsigned int unk08;
    unsigned int m_key;
};

// @fnv 0x00c4a420
void CachedRef_b5611::UpdateCachedRef(unsigned int uiKey, unsigned int a2)
{
    if (m_pCachedReference != 0) {
        if (a2 == m_key) {
            m_pCachedReference = v03(m_pCachedReference, uiKey);
        } else {
            unsigned int uiUnusedA;
            unsigned int uiUnusedB;
            void* tmp = v01(uiKey);
            CopyRange_b5611(tmp, m_pCachedReference, a2);
            v02(m_pCachedReference);
            m_pCachedReference = 0;
            m_pCachedReference = tmp;
        }
    } else {
        m_pCachedReference = v01(uiKey);
        m_key = uiKey;
    }
}

struct FUN_00c4a6e0_cls
{
    int unk00;
    bool ProcessEntries(struct CallerObj_b3918* a1, struct EntrySet_b3918* a2);
};

struct CallerObj_b3918
{
    int ClassifySphereAgainstPlane(void* p);
};

struct EntrySet_b3918
{
    unsigned int unk00;
    unsigned int unk04;
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
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int m_60;
};

// Iterates the six bits of m_60, calls ClassifySphereAgainstPlane on each 16-byte entry, clears bits returning 1, and returns false if any returns 2.
// @fnv 0x00c4a6e0
bool FUN_00c4a6e0_cls::ProcessEntries(CallerObj_b3918* apCaller, EntrySet_b3918* apEntries)
{
    int i;
    int tmp;
    int code;
    (void)tmp;
    if (!(bool)(apEntries->m_60 != 0))
    {
        return true;
    }
    else
    {
        for (i = 0; i < 6; i++)
        {
            if ((bool)((apEntries->m_60 & (1u << i)) != 0))
            {
                code = apCaller->ClassifySphereAgainstPlane((char*)apEntries + i * 16);
                if (code == 2)
                {
                    break;
                }
                if (code == 1)
                {
                    apEntries->m_60 &= ~(1u << i);
                }
            }
        }
        if (i == 6)
        {
            return true;
        }
    }
    return false;
}

namespace fnv_00c4a8b0 {
struct ParticleAllocator {
    void* Reallocate(void* memory, unsigned int bytes);
};
extern ParticleAllocator DAT_011f6238;

struct ParticleArrayAllocator {
    void* AllocateParticleArray(void* memory, unsigned int count);
};

// Allocates count particles of 100 bytes each from the particle allocator and returns the resulting pointer.
// @fnv 0x00c4a8b0
void* ParticleArrayAllocator::AllocateParticleArray(void* memory, unsigned int count)
{
    return DAT_011f6238.Reallocate(memory, count * 100);
}
}  // namespace fnv_00c4a8b0

struct FUN_00c4a8e0
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual ~FUN_00c4a8e0();
};

// Destructor that calls ReleaseBuffer with argument 1 on this object.
// @fnv 0x00c4a8e0
FUN_00c4a8e0::~FUN_00c4a8e0()
{
    int unk04;
    ((FUN_00c4a9c0_class*)this)->ReleaseBuffer(1);
}

struct FUN_00c4b150_cls {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C;
    int m_30;
    void FUN_00a5dd70(int a1, int a2);
    void CallIfNotFlagged(int a1, int a2);
};
// Calls FUN_00a5dd70 with the two arguments unless bit 0 of m_30 is set.
// @fnv 0x00c4b150
void FUN_00c4b150_cls::CallIfNotFlagged(int a1, int a2)
{
    if (!(bool)((m_30 & 1) != 0 ? 1 : 0)) {
        FUN_00a5dd70(a1, a2);
    }
}

struct S_c4b190_Base { void FUN_00a5ded0(int a, int b); };
struct S_c4b190 : S_c4b190_Base {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    int unk30;
    void CallBaseIfFlagClear(int a, int b);
};
// Calls the base FUN_00a5ded0 with a and b when bit 0 of unk30 is clear.
// @fnv 0x00c4b190
void S_c4b190::CallBaseIfFlagClear(int a, int b) {
    if (!(unsigned char)(-((unk30 & 1) != 0 ? -1 : 0))) FUN_00a5ded0(a, b);
}

struct S_00c4b1d0_Cls {
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
    unsigned int flags;
    void NiNode_UpdateRigidDownwardPass(int a, int b);
    void BSDamageStage_UpdateRigidDownwardPass(int a, int b);
};
// If the flags bit 0 is clear, forwards a and b to FUN_00a5e1f0.
// @fnv 0x00c4b1d0
// src: XBOX_PDB 0x00c4b1d0
void S_00c4b1d0_Cls::BSDamageStage_UpdateRigidDownwardPass(int a, int b) {
    if (!(bool)(flags & 1 ? 1 : 0)) {
        NiNode_UpdateRigidDownwardPass(a, b);
    }
}

class FUN_00c4b470_owner {
public:
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
    virtual int v35(void** a2);
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual int v39(void** a2);
    unsigned int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    unsigned int unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40;
    unsigned int unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60;
    unsigned int unk64, unk68, unk6C, unk70, unk74;
    FUN_00c4b470_owner* unk78;
    FUN_00c4b470_owner* NiObjectNET_GetController(void* p);
};

extern char DAT_011f36ac;

// Looks up a node via FUN_00a5c570, calls its unk78 object's v35 with a2, and falls back to a1->v39 when a3 is nonzero.
// @fnv 0x00c4b470
// src: XBOX_PDB 0x00c4b470
int __cdecl BSUtilities_GetObjectByName_00c4b470(FUN_00c4b470_owner* pOwner, void** a2, unsigned char bFallback)
{
    FUN_00c4b470_owner* node7;
    int r7;
    void* cur;
    FUN_00c4b470_owner* m78;
    FUN_00c4b470_owner* obj;
    if (pOwner == 0 || (cur = *a2) == 0) {
        return 0;
    }
    node7 = pOwner->NiObjectNET_GetController(&DAT_011f36ac);
    if (node7 != 0) {
        m78 = node7->unk78;
        obj = m78;
        r7 = obj->v35(a2);
        if (r7 != 0) {
            return r7;
        }
    }
    if (bFallback != 0) {
        return pOwner->v39(a2);
    }
    return 0;
}

extern double DAT_01012060;

struct FUN_00c4cdc0_child
{
    void ReverseElements();
};

struct FUN_00c4cdc0_cls
{
    FUN_00c4cdc0_child* m_pChildObject;
    double BSPolygon2D_Area();
    void BSPolygon2D_StoreConcaveVertices();
    void BSPolygon2D_Initialize();
};

// @fnv 0x00c4cdc0
// src: COMMUNITY 0x00c4cdc0
void FUN_00c4cdc0_cls::BSPolygon2D_Initialize()
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    if (BSPolygon2D_Area() >= DAT_01012060)
    {
        m_pChildObject->ReverseElements();
    }
    BSPolygon2D_StoreConcaveVertices();
}

struct FUN_00c4cf00_Entry {
    int m_iA;
    int m_iB;
    float m_fC;
};

struct FUN_00c4cf00_Data {
    int unk00;
    FUN_00c4cf00_Entry* m_pItems;
};

struct FUN_00c4cf00_cls {
    FUN_00c4cf00_Data* m_pData;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int m_iArrayLength;

    void BSPolygon2D_RemoveZ();
};

// @fnv 0x00c4cf00
// src: COMMUNITY 0x00c4cf00
void FUN_00c4cf00_cls::BSPolygon2D_RemoveZ()
{
    for (int i = 0; i < m_iArrayLength; i++) {
        FUN_00c4cf00_Entry tmp = m_pData->m_pItems[i];
        tmp.m_fC = 0.0f;
        {
            FUN_00c4cf00_Data* pData = m_pData;
            pData->m_pItems[i] = tmp;
        }
    }
}

struct S_00c4dcf0 {
    int GetPointSide(float a, float b, float c, float d, float e, float f, float g, float h, float i);
};
// @fnv 0x00c4dcf0
int S_00c4dcf0::GetPointSide(float afX1, float afY1, float afUnused1, float afX2, float afY2, float afUnused2, float afX3, float afY3, float afUnused3) {
    float r = (afX1 - afX2) * (afY3 - afY1) - (afY1 - afY2) * (afX3 - afX1);
    if (r < 0.0) {
        return 1;
    } else if (r > 0.0) {
        return -1;
    } else {
        return 0;
    }
}

struct S_00c4e0a0_Data {
    int unk00;
    unsigned short* m_pValues;
};

struct S_00c4e0a0_Class {
    int unk00;
    int unk04;
    S_00c4e0a0_Data* m_pData;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int m_iArrayLength;

    bool __thiscall BSPolygon2D_IsPointInsideTri(int arg1, int arg2, int arg3,
                               int arg4, int arg5);
    bool __thiscall ContainsMatchingTriple(int arg1, int arg2);
};

// @fnv 0x00c4e0a0
bool S_00c4e0a0_Class::ContainsMatchingTriple(int arg1, int arg2) {
    for (int i = 0; i < this->m_iArrayLength; i = i + 1) {
        int value0 = i * 3;
        int value1 = i * 3 + 1;
        int valueTmp = i * 3 + 2;

        unsigned short* pA = this->m_pData->m_pValues + valueTmp;
        unsigned short* p1 = this->m_pData->m_pValues + value1;
        unsigned short* p5 = this->m_pData->m_pValues + value0;

        if (this->BSPolygon2D_IsPointInsideTri(arg1, arg2, *p5, *p1, *pA)) {
            return true;
        }
    }

    return false;
}

struct S_00c4e900_Elem {
    int a;
    int b;
    int c;
};
struct S_00c4e900_Arr {
    int unk00;
    S_00c4e900_Elem* data;
    int count;
    void ReverseElements();
};
// Reverses the array in place by swapping elements from both ends toward the middle.
// @fnv 0x00c4e900
void S_00c4e900_Arr::ReverseElements() {
    int i = 0;
    int iRight = count - 1;
    for (; i < iRight; i++, iRight--) {
        S_00c4e900_Elem tmp = data[i];
        S_00c4e900_Elem* p3 = &data[iRight];
        data[i] = *p3;
        data[iRight] = tmp;
    }
}

extern unsigned char DAT_012030a4;

struct S_00c4ed70_Object {
    virtual void vfn_0000();
    virtual void vfn_0004();
    virtual void vfn_0008();
    virtual void vfn_000c();
    virtual void vfn_0010();
    virtual void vfn_0014();
    virtual void __stdcall vfn_0018(int);
};

struct S_00c4ed70_Class {
    S_00c4ed70_Object* m_pObject;
    bool __thiscall BSOcclusionQuery_Begin();
};

void S_00c4ed70_Object::vfn_0000() {}
void S_00c4ed70_Object::vfn_0004() {}
void S_00c4ed70_Object::vfn_0008() {}
void S_00c4ed70_Object::vfn_000c() {}
void S_00c4ed70_Object::vfn_0010() {}
void S_00c4ed70_Object::vfn_0014() {}
void __stdcall S_00c4ed70_Object::vfn_0018(int) {}

// If DAT_012030a4 is unset, sets it to 1, calls vfn_0018(2) on m_pObject, and returns true; otherwise returns false.
// @fnv 0x00c4ed70
// src: COMMUNITY 0x00c4ed70
bool __thiscall S_00c4ed70_Class::BSOcclusionQuery_Begin() {
    if (DAT_012030a4) {
        return false;
    } else {
        DAT_012030a4 = 1;
    }

    m_pObject->vfn_0018(2);
    return true;
}

// Candidate v2 for FUN_00c4edb0 (zai_04).
// Same guard logic; callee hypothesis: virtual __stdcall member taking one int,
// called as m_p->vfn(1). MSVC passes this as the first __stdcall stack argument
// (push 1 then push m_p), vtable slot 6 (+0x18), no ecx requirement at call.

extern unsigned char DAT_012030a4;

struct FUN_00c4edb0_Virt {
    virtual void vfn_0000();
    virtual void vfn_0004();
    virtual void vfn_0008();
    virtual void vfn_000c();
    virtual void vfn_0010();
    virtual void vfn_0014();
    virtual void __stdcall vfn_0018(int one);
};

struct FUN_00c4edb0_Class {
    FUN_00c4edb0_Virt* m_p;
    void BSOcclusionQuery_End();
};

// If DAT_012030a4 is set, clears it and calls vfn_0018(1) on m_p.
// @fnv 0x00c4edb0
// src: COMMUNITY 0x00c4edb0
void FUN_00c4edb0_Class::BSOcclusionQuery_End() {
    if (DAT_012030a4) {
        DAT_012030a4 = 0;
        m_p->vfn_0018(1);
    }
}

struct S_00c4edf0_Obj {
    virtual void vfn00(); virtual void vfn04(); virtual void vfn08(); virtual void vfn0c();
    virtual void vfn10(); virtual void vfn14(); virtual void vfn18();
    virtual int __stdcall vfn1c(int, int, int);
};
struct S_00c4edf0_cls {
    S_00c4edf0_Obj* unk00;
    bool BSOcclusionQuery_GetResult(int a1, bool a2);
};
// Calls vfn1c on unk00 with a1, 4 and a flag derived from a2, returning true when the call returns 0.
// @fnv 0x00c4edf0
// src: XBOX_PDB 0x00c4edf0
bool S_00c4edf0_cls::BSOcclusionQuery_GetResult(int a1, bool abFlag)
{
    int flag = 0;
    if (abFlag)
        flag = 1;
    int r = unk00->vfn1c(a1, 4, flag);
    if (r == 0)
        return true;
    return false;
}

struct DispatchObject {
    virtual void __stdcall reserved0();
    virtual void __stdcall reserved1();
    virtual void __stdcall reserved2();
    virtual void __stdcall reserved3();
    virtual void __stdcall FunctionAtSlot4();
    virtual void __stdcall FunctionAtSlot5();
    virtual void __stdcall FunctionAtSlot6();
    virtual int __stdcall Execute(int code, int mode, int flag);
};
struct DispatchOwner {
    DispatchObject* object;
    bool __thiscall BSOcclusionQuery_GetResultNoWait(int code, unsigned char enabled);
};
// Forwards code, mode 4 and a 0/1 flag derived from enabled to object->Execute and returns true when it returns 0.
// @fnv 0x00c4ee40
// src: COMMUNITY 0x00c4ee40
bool __thiscall DispatchOwner::BSOcclusionQuery_GetResultNoWait(int code, unsigned char enabled) {
    int flag = 0;
    int result;
    if (enabled) flag = 1;
    result = object->Execute(code, 4, flag);
    if (result == 0) return true;
    return false;
}

namespace fnv_00c503d0 {
struct FUN_00a5ecb0 {
 virtual void v0();
 ~FUN_00a5ecb0();
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
 int unk90;
 int unk94;
 int unk98;
 int unk9c;
 int unka0;
 int unka4;
 int unka8;
 FUN_00a5ecb0(unsigned int);
};
struct WorkerMemory { void* Allocate(unsigned int); };
extern WorkerMemory DAT_011f6238;
void* __cdecl FUN_00ec61c0(void*,int,unsigned int);
struct WorkerTask { unsigned int value; };
struct WorkerTaskManager { void GetTaskletValue(); };
WorkerTaskManager& __stdcall FUN_00b00a00(WorkerTask*);
struct FUN_00c503d0 : FUN_00a5ecb0 {
    unsigned int* data;
    unsigned int count;
    WorkerTask* task;
    FUN_00c503d0();
};
// @fnv 0x00c503d0
FUN_00c503d0::FUN_00c503d0() : FUN_00a5ecb0(0) {
    count = 10;
    void* allocated = DAT_011f6238.Allocate(40);
    data = (unsigned int*)allocated;
    unsigned int result = count * 4;
    void* destination = data;
    FUN_00ec61c0(destination,-1,result);
    WorkerTask* storage = (WorkerTask*)DAT_011f6238.Allocate(4);
    WorkerTask* size = storage ? (storage->value = 0, storage) : 0;
    task = size;
    FUN_00b00a00(task).GetTaskletValue();
}
}  // namespace fnv_00c503d0

struct FUN_00c509a0_Class {
    void* __thiscall GetEntryValue(int);
    void __thiscall BSParticleSystemManager_RemoveMasterParticleSystem_00c51700(void*);
    void __thiscall BSParticleSystemManager_RemoveMasterParticleSystem(int);
};

extern "C" char DAT_010c2580;
extern "C" void __cdecl Warning_005b5e40(void*, int);

// @fnv 0x00c509a0
// src: XBOX_PDB 0x00c509a0
void FUN_00c509a0_Class::BSParticleSystemManager_RemoveMasterParticleSystem(int a)
{
    int local1;
    int local2;
    int local3;
    void* p = this->GetEntryValue(a);

    if (p != 0) {
        this->BSParticleSystemManager_RemoveMasterParticleSystem_00c51700(p);
    } else {
        Warning_005b5e40(&DAT_010c2580, a);
    }
}

// FUN_00c50dd0: clears (releases) the pointer held by the second argument's
// smart-pointer holder. The two dword locals reproduce the original /Od frame
// layout (named locals above the hidden 'this' spill at [ebp-0xc]).
struct FUN_00c50dd0_Holder {
    void* __thiscall FUN_0066b0d0(void* value);
};

struct FUN_00c50dd0_cls {
    int unk00;
    void BSParticleSystemManager_DetachChildAt_00c50dd0(int* p1, FUN_00c50dd0_Holder* p2);
};

// @fnv 0x00c50dd0
// src: XBOX_PDB 0x00c50dd0
void FUN_00c50dd0_cls::BSParticleSystemManager_DetachChildAt_00c50dd0(int* pUnused, FUN_00c50dd0_Holder* pHolder)
{
    int m_iUnusedA;
    int m_iUnusedB;
    pHolder->FUN_0066b0d0(0);
}

struct S_00c50ea0_T {
    void FUN_0066b0d0(int a);
};
struct S_00c50ea0 {
    void BSParticleSystemManager_SetAt_00c50ea0(int a1, int a2, S_00c50ea0_T* a3);
};
// @fnv 0x00c50ea0
// src: XBOX_PDB 0x00c50ea0
void S_00c50ea0::BSParticleSystemManager_SetAt_00c50ea0(int a1, int a2, S_00c50ea0_T* pTarget)
{
    int unk1;
    int unk2;
    pTarget->FUN_0066b0d0(0);
}

// Layout up to the item array (+0xa0) and the 16-bit item count (+0xa8).
struct FUN_00c50ec0_cls {
    unsigned int unk00;
    unsigned int unk04;
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
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    int* m_pItems;
    unsigned int unkA4;
    unsigned short m_usElementCount;

    int FindItemIndex(int key);
};
// @fnv 0x00c50ec0
int FUN_00c50ec0_cls::FindItemIndex(int key) {
    unsigned int n = m_usElementCount;
    unsigned int i;
    for (i = 0; i < n; i++) {
        int* pItem = &m_pItems[i];
        int item = *pItem;
        int value = item;
        if (value == key) {
            return i;
        }
    }
    return -1;
}


extern const NiRTTI DAT_012024e0;
extern const NiRTTI DAT_01203340;

void __cdecl FNV_Warning(const char* fmt, ...);



struct EmitterModifier : NiTimeController {
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
    int m_iTarget;
};

struct MasterPSys : NiAVObject {
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    bool m_bFlag;
};


// Recursively finds the multi-target emitter under a master particle system and sets its m_iTarget, warning if none is found.
// @fnv 0x00c51250
bool __cdecl SetParticleSystemTarget(NiAVObject* pkObject, int iTarget)
{
    NiAVObject* pkObj;
    unsigned int j;
    unsigned int uiChildren;
    NiNode* pkNode;
    EmitterModifier* pkEmitter;
    EmitterModifier* pkMod;
    MasterPSys* pkMaster;

    if (!pkObject)
        return false;

    if (pkObject->IsParticlesGeom())
    {
        {
            bool bIsMaster;
            if (!pkObject)
                bIsMaster = false;
            else
                bIsMaster = pkObject->GetRTTI() == &DAT_012024e0;
            if (bIsMaster)
            {
                pkMaster = (MasterPSys*)pkObject;
                pkMaster->m_bFlag = true;
                {
                    EmitterModifier* pkCurrentObject = reinterpret_cast<EmitterModifier*>(pkMaster->m_spControllers);
                    pkMod = pkCurrentObject;
                }
                while (pkMod)
                {
                    bool bIsEmitter;
                    if (!pkMod)
                        bIsEmitter = false;
                    else
                        bIsEmitter = pkMod->GetRTTI() == &DAT_01203340;
                    if (bIsEmitter)
                    {
                        pkEmitter = pkMod;
                        pkEmitter->m_iTarget = iTarget;
                        return true;
                    }
                    else
                    {
                        EmitterModifier* pkNext = reinterpret_cast<EmitterModifier*>(pkMod->m_spNextController.m_pObject);
                        pkMod = pkNext;
                    }
                }
            }
        }
        {
            const char* pcName = pkObject->m_kName.m_kHandle;
            FNV_Warning("DEFAULT: \"%s\" is a Master Particle System without a multi-target emitter.", pcName);
        }
        return false;
    }
    else
    {
        pkNode = pkObject ? reinterpret_cast<NiNode*>(pkObject->IsSceneNode()) : 0;
        if (pkNode)
        {
            uiChildren = pkNode->m_kChildren.m_usSize;
            for (j = 0; j < uiChildren; j++)
            {
                {
                    NiPointer<NiAVObject>* ppkSlot = &pkNode->m_kChildren.m_pBase[j];
                    NiAVObject* pkTmp = ppkSlot->m_pObject;
                    pkObj = pkTmp;
                }
                if (pkObj)
                {
                    if (!SetParticleSystemTarget(pkObj, iTarget))
                        return false;
                }
            }
        }
    }
    return true;
}

void __cdecl FUN_00aa1460(void* apMemory, unsigned int auiSize);

struct FUN_00c51590_cls {
    int unk00;

    void BaseCleanup();

    FUN_00c51590_cls* FUN_00c51590(unsigned int acFlags);
};

// @fnv 0x00c51590
FUN_00c51590_cls* FUN_00c51590_cls::FUN_00c51590(unsigned int acFlags)
{
    BaseCleanup();
    if (acFlags & 1) {
        FUN_00aa1460(this, 0xb8);
    }
    return this;
}

namespace fnv_00c515d0 {
struct FNVHeap {
    void MemoryManager_Deallocate(void* allocation);
};
extern FNVHeap DAT_011f6238;
extern "C" void __cdecl FUN_00c516d0();
extern "C" void __stdcall FUN_00ec5fce(void* objects, unsigned int objectSize, unsigned int count, void (__cdecl *destructor)());

struct DynamicObject {
    void FUN_00b00ec0();
    void* FUN_00c515d0(unsigned int flags);
};
// @fnv 0x00c515d0
void* DynamicObject::FUN_00c515d0(unsigned int flags)
{
    if (flags & 2) {
        FUN_00ec5fce(this, 0x20, *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) - 4), &FUN_00c516d0);
        if (flags & 1) {
            DAT_011f6238.MemoryManager_Deallocate(reinterpret_cast<char*>(this) - 4);
        }
        return reinterpret_cast<char*>(this) - 4;
    }
    FUN_00b00ec0();
    if (flags & 1) {
        DAT_011f6238.MemoryManager_Deallocate(this);
    }
    return this;
}
}  // namespace fnv_00c515d0

struct FUN_00c516a0_Virtual {
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
    virtual void v41(void*, int);
};

struct FUN_00c516a0_Class {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    FUN_00c516a0_Virtual* unk18;
    void* unk1C;

    void __thiscall UpdateMasterPsysTaskletData_Process();
};

// Calls the virtual method v41 on unk18 with unk1C and 0 as arguments.
// @fnv 0x00c516a0
// src: XBOX_PDB 0x00c516a0
void __thiscall FUN_00c516a0_Class::UpdateMasterPsysTaskletData_Process()
{
    unk18->v41(unk1C, 0);
}

struct Node_cls
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int v0c();
    unsigned int unk04;
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
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    Node_cls** m_a0;
    unsigned short unkA4;
    unsigned short m_a6;
};

struct ItemCtx_cls
{
    bool FUN_00a53c30(Node_cls* a1, unsigned int* out);
    void InsertOrUpdate(Node_cls* a1, unsigned int v);
};

struct FUN_00c53280_cls
{
    void UpdateMaxValue(Node_cls* a1, ItemCtx_cls* a2, unsigned int* out);
};

// @fnv 0x00c53280
void FUN_00c53280_cls::UpdateMaxValue(Node_cls* pNode, ItemCtx_cls* pContext, unsigned int* puiMax)
{
    unsigned int bestX = *puiMax;
    unsigned int local2;
    for (unsigned int i = 0; i < pNode->m_a6; i++) {
        Node_cls* item3;
        Node_cls** slot = pNode->m_a0 + i;
        Node_cls* cur4 = *slot;
        item3 = cur4;
        unsigned int local;
        unsigned int spare[5];
        if (item3 != 0 && item3->v0c()) {
            local = bestX;
            UpdateMaxValue(item3, pContext, &local);
            if (local > *puiMax) {
                *puiMax = local;
            }
        }
    }
    if (pContext->FUN_00a53c30(pNode, &local2)) {
        if (local2 > *puiMax) {
            *puiMax = local2;
        }
    } else {
        pContext->InsertOrUpdate(pNode, *puiMax);
    }
}

// Stand-in model of the destructor at 0x00c53fa0 (an /Od member function of a
// polymorphic class with a non-trivial base).
//
// The original is:
//   push ebp / mov ebp,esp / push -1 / push <eh handler> / mov eax,fs:[0] / push eax
//   sub esp,0x10 / <security cookie> / lea eax,[ebp-0xc] / mov fs:[0],eax
//   mov dword ptr [ebp-0x1c], ecx      ; the 'this' home
//   mov eax,dword ptr [ebp-0x1c]
//   mov dword ptr [eax], 0x10c2a94     ; the class' own vftable
//   mov dword ptr [ebp - 4], 0         ; EH state 0
//   mov ecx,dword ptr [ebp-0x1c] / add ecx,0xc / mov dword ptr [ebp-0x18],ecx
//   mov edx,dword ptr [ebp-0x18] / mov dword ptr [edx], 0x10c2b2c
//   mov eax,dword ptr [ebp-0x18] / mov ecx,dword ptr [eax+4]
//   mov dword ptr [ebp-0x14], ecx
//   mov edx,dword ptr [ebp-0x14] / mov dword ptr [ebp-0x10], edx
//   mov eax,dword ptr [ebp-0x10] / push eax
//   mov ecx, 0x11f6238 / call 0xaa4060   ; g_memoryManager.Deallocate(...)
//   mov dword ptr [ebp - 4], -1        ; EH state -1
//   mov ecx,dword ptr [ebp-0x1c] / call 0xa7b300   ; the base destructor

extern int FNV_vtbl_NiTArrayBase;

struct FNV_Item;

struct FNV_MemoryManager {
    void Deallocate(void* p);
};
extern FNV_MemoryManager FNV_g_memoryManager;

// Local view of the array destruction expanded in 0x00c53fa0: only the vtable and
// buffer are represented here. The original writes 0x010c2b2c and frees +4 inline;
// a full NiTArray member adds counts and automatic destruction to this partial
// owner model. Keep the view until the complete owner layout is recovered.
struct LocalInlineArrayDestructionView {
    int* m_vtbl;         // +0x00
    FNV_Item* m_pBase;   // +0x04
};

struct FNV_Base {
    int unk00;           // +0x04
    int unk04;           // +0x08
    virtual void vfn();
    ~FNV_Base();
};

struct FUN_00c53fa0_Class : public FNV_Base {
    LocalInlineArrayDestructionView m_sub;    // +0x0c
    ~FUN_00c53fa0_Class();
};

// Destructor: sets m_sub's vtable to FNV_vtbl_NiTArrayBase and deallocates m_sub.m_pBase via FNV_g_memoryManager.
// @fnv 0x00c53fa0
FUN_00c53fa0_Class::~FUN_00c53fa0_Class()
{
    LocalInlineArrayDestructionView* p3 = &m_sub;
    p3->m_vtbl = &FNV_vtbl_NiTArrayBase;
    FNV_Item* q = p3->m_pBase;
    void* r6 = q;
    FNV_g_memoryManager.Deallocate(r6);
}

struct SpawnedSubObject
{
    int unk00;
    int unk04;
    int unk08;
    void Attach(int a1);
};

struct FUN_00c54e30_cls
{
    int unk00;
    int unk04;
    int unk08;
    SpawnedSubObject m_0c;
    SpawnedSubObject m_18;
    void BindOwner(int a1);
    void BindAndAttachSubObjects(int a1);
};

// Calls BindOwner with a1, then attaches both contained sub-objects to a1.
// @fnv 0x00c54e30
void FUN_00c54e30_cls::BindAndAttachSubObjects(int a1)
{
    BindOwner(a1);
    m_0c.Attach(a1);
    m_18.Attach(a1);
}


struct C00c541e0 {
    int unk00;
    int unk04;
    int unk08;
    bool FUN_00a7b3d0(int other);
};

struct C00c54f00 : C00c541e0 {
    NiPoint3 m_vec0C;
    NiPoint3 m_vec18;
    bool BSBound_IsEqual(int other);
};

// Calls the base comparison and, if it passes, also compares m_vec0C and m_vec18 component-wise with the other object's vectors.
// @fnv 0x00c54f00
// src: XBOX_PDB 0x00c54f00
bool C00c54f00::BSBound_IsEqual(int other)
{
    bool result = C00c541e0::FUN_00a7b3d0(other);
    if (result) {
        C00c54f00* pOther = (C00c54f00*)other;
        {
            const NiPoint3& b = pOther->m_vec0C;
            const NiPoint3& a = m_vec0C;
            result = a.x == b.x && a.y == b.y && a.z == b.z;
        }
        {
            const NiPoint3& b = pOther->m_vec18;
            const NiPoint3& a = m_vec18;
            result &= (bool)(int)(a.x == b.x && a.y == b.y && a.z == b.z);
        }
    }
    return result;
}

struct C55CD0Point3 {
    float x;
    float y;
    float z;
};

void C55CD0DrawBox(const C55CD0Point3& kMinBoundsCur, const C55CD0Point3& kMaxPoint, float fA, float fB, float fC, float fD,
                   unsigned int uiColor, unsigned int uiOutline);

// @fnv 0x00c55cd0
// src: GUESS 0x00c55cd0 (confidence: low)
void Runtime_UpdateState_00c55cd0(const C55CD0Point3& aCenter, float fSize, unsigned int uiColor)
{
    C55CD0Point3 kMinBoundsCur = aCenter;
    kMinBoundsCur.y -= fSize;
    C55CD0Point3 kMaxPoint = aCenter;
    kMaxPoint.y += fSize;
    C55CD0DrawBox(kMinBoundsCur, kMaxPoint, fSize, fSize, fSize, fSize, uiColor, uiColor);
}

struct S_00c5ae70_Result {
    int unk00;
    int unk04;
    int unk08;
};

struct S_00c5ae70_Inner2 {
    int unk00;
    int unk04;
    int unk08;

    S_00c5ae70_Result* __thiscall NiGeometry_AddProperty();
};

struct S_00c5ae70_Inner1 {
    int unk00;
    int unk04;
    S_00c5ae70_Inner2 m_inner2;

    void __thiscall NiTListBase_NiTPointerAllocator_unsigned_int_BSFaceGenKeyframe_AddNodeTail(S_00c5ae70_Result* result);
};

struct S_00c5ae70_Class {
    int unk00;
    int unk04;
    S_00c5ae70_Inner1 m_inner1;

    void __thiscall BSPortalGraph_AddOccluder(int param);
};

// If param is non-zero, obtains a result object from m_inner1.m_inner2, stores param in its unk08, and passes it to m_inner1.FUN_00559a70.
// @fnv 0x00c5ae70
// src: COMMUNITY 0x00c5ae70
void __thiscall S_00c5ae70_Class::BSPortalGraph_AddOccluder(int aiValue)
{
    S_00c5ae70_Result* res2;
    int ie;
    int el;
    int a;
    int c;
    int e;
    int g;
    int k;

    if (aiValue != 0) {
        S_00c5ae70_Inner1* p = &m_inner1;
        res2 = p->m_inner2.NiGeometry_AddProperty();
        res2->unk08 = aiValue;
        p->NiTListBase_NiTPointerAllocator_unsigned_int_BSFaceGenKeyframe_AddNodeTail(res2);
    }
}

struct FUN_00c3a250_Obj {
    void __thiscall FUN_00c3a250(int* a1);
};

void __thiscall FUN_00c3a250_Obj::FUN_00c3a250(int* a1) {
}

struct FUN_00c5aec0_Class {
    int unk00;
    int unk04;
    void __thiscall BSPortalGraph_RemoveOccluder(int a1);
};

// If a1 is non-zero, calls FUN_00c3a250 on the object at this+8, passing the address of a1.
// @fnv 0x00c5aec0
// src: COMMUNITY 0x00c5aec0
void __thiscall FUN_00c5aec0_Class::BSPortalGraph_RemoveOccluder(int aiValue) {
    int dummy00;
    int dummy01;
    int dummy02;
    int dummy03;
    int dummy04;
    int dummy05;
    int dummy06;
    int dummy07;
    int dummy08;
    int dummy09;
    int dummy10;
    int dummy11;
    int dummy12;
    int dummy13;
    int dummy14;
    int dummy15;
    int dummy16;
    int dummy17;
    int dummy18;

    if (aiValue != 0) {
        ((FUN_00c3a250_Obj*)((char*)this + 8))->FUN_00c3a250(&aiValue);
    }
}

struct FUN_00c5b190_Sub {
    void Process(int* p);
};


struct FUN_00c5b190_cls {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    FUN_00c5b190_Sub m_14;
    void BSPortalGraph_RemovePortal(int a1);
};

// If a1 is non-zero, calls m_14.Process with the address of a1.
// @fnv 0x00c5b190
// src: COMMUNITY 0x00c5b190
void FUN_00c5b190_cls::BSPortalGraph_RemovePortal(int aiValue) {
    int loc1;
    int loc2;
    int loc3;
    int loc4;
    int loc5;
    int loc6;
    int loc7;
    int loc8;
    int loc9;
    int loc10;
    int loc11;
    int loc12;
    int loc13;
    int loc14;
    int loc15;
    int loc16;
    int loc17;
    int loc18;
    int loc19;
    if (aiValue != 0) { m_14.Process(&aiValue); }
}

// Constructor: member routine that installs the class vtable pointer into
// the object, clears the flag member at +0x5c and then hands the object to
// the shared cleanup routine (FUN_00c1c300).
extern int DAT_010c2d54;

struct FUN_00c5c440_cls
{
    void* m_pVTable;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    void FUN_00c1c300();
    void Constructor();
};

// Sets the vtable pointer, clears m_5c, then calls FUN_00c1c300.
// @fnv 0x00c5c440
void FUN_00c5c440_cls::Constructor()
{
    // four spare scratch words; they only shape the stack frame of the
    // original routine.
    int iScratch0;
    int iScratch1;
    int iScratch2;
    int iScratch3;

    m_pVTable = (void*)&DAT_010c2d54;
    m_5c = 0;
    FUN_00c1c300();
}

struct FUN_00c5c400 {
    unsigned int unk00;
    unsigned int unk04;
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
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int m_0x5c;
    unsigned int m_0x60;
    static void* __cdecl operator new(unsigned int size);
    FUN_00c5c400();
};
// The factory at 0x00c5ca90 constructs a 0x64-byte multi-target controller, including its +0x60 count.
struct MultiTargetEmitterCloneFactory : MultiTargetEmitterCloneWriter {
    FUN_00c5c400* BSPSysMultiTargetEmitterCtlr_CreateClone(void* process);
};
// @fnv 0x00c5ca90
// src: XBOX_PDB 0x00c5ca90
FUN_00c5c400* MultiTargetEmitterCloneFactory::BSPSysMultiTargetEmitterCtlr_CreateClone(void* process) {
    FUN_00c5c400* clone = new FUN_00c5c400;
    BSPSysMultiTargetEmitterCtlr_CopyMembers(reinterpret_cast<MultiTargetEmitterCloneWriter*>(clone), process);
    return clone;
}

struct FUN_00a53c30_cls {
    bool FUN_00a53c30(unsigned int key, void** out);
};

struct FUN_00c5cb50_pad {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
};

struct FUN_00c5cb50_cls {
    void FUN_00c1bdc0(int a1);
    void BSPSysMultiTargetEmitterCtlr_ProcessClone(int a1);
};

// @fnv 0x00c5cb50
// src: XBOX_PDB 0x00c5cb50
void FUN_00c5cb50_cls::BSPSysMultiTargetEmitterCtlr_ProcessClone(int a1)
{
    FUN_00c5cb50_pad pad;
    void* found;
    void* value;
    bool ok;

    this->FUN_00c1bdc0(a1);
    value = 0;
    ok = ((FUN_00a53c30_cls*)*(void**)a1)->FUN_00a53c30((unsigned int)this, &value);
    found = value;
    ok = ((FUN_00a53c30_cls*)*(void**)a1)->FUN_00a53c30(*(unsigned int*)((char*)this + 0x5c), &value);
    *(void**)((char*)found + 0x5c) = value;
}

class BC5CBB0Object {
public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);
};

class BC5CBB0Controller : public BC5CBB0Object {
public:
    BC5CBB0Controller();

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
};

// Allocates and constructs a BC5CBB0Controller, returning it as a BC5CBB0Object pointer.
// @fnv 0x00c5cbb0
// src: EXE 0x00c5cbb0
BC5CBB0Object* __cdecl BSPSysMultiTargetEmitterCtlr_CreateObject()
{
    BC5CBB0Controller* pkController = new BC5CBB0Controller;
    return pkController;
}

struct EmitterObjectStub {
    void* m_ppVirtualMethodTable;
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
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    EmitterObjectStub();
    static void* operator new(unsigned int size);
    static void operator delete(void* p);
};

struct EmitterOwnerStub {
    void Attach(EmitterObjectStub* pkObject, int iParam);
    EmitterObjectStub* CreateAndAttachEmitterObject(int iParam);
};

// Allocates a new EmitterObjectStub, attaches it to this owner with iParam, and returns the new object.
// @fnv 0x00c5d010
EmitterObjectStub* EmitterOwnerStub::CreateAndAttachEmitterObject(int iParam) {
    EmitterObjectStub* pkObject = new EmitterObjectStub;
    Attach(pkObject, iParam);
    return pkObject;
}

struct FUN_00c5d0a0_cls;
struct FUN_00c5d0a0_Vec4 { int x; int y; int z; int w; };
struct FUN_00c5d0a0_cls {
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
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    FUN_00c5d0a0_Vec4 m_c4;
    void Helper(FUN_00c5d0a0_cls* other, int b);
    void CopyVec4AndHelper(FUN_00c5d0a0_cls* a1, int a2);
};
// Copies m_c4 into a1->m_c4, then calls Helper(a1, a2).
// @fnv 0x00c5d0a0
void FUN_00c5d0a0_cls::CopyVec4AndHelper(FUN_00c5d0a0_cls* apOther, int aiArg) {
    apOther->m_c4 = m_c4;
    Helper(apOther, aiArg);
}

typedef HKEY HKEY_t;
int __cdecl Setting_DataType_00c33090(int);
extern "C" int __cdecl strcpy_s(char* dst, unsigned int size, const char* src);


struct RegStore : RegSettingCollection {
    bool WriteSetting(Setting* pSetting);
};

// @fnv 0x00c5d670
bool RegStore::WriteSetting(Setting* pSetting)
{
    bool bResultTmp = false;
    const char* pName4 = pSetting->pKey;
    bool bOpened5;
    HKEY_t hKey1;
    HKEY_t hKey2;
    HKEY_t hKey7;
    unsigned int uiSize;
    int iType7;
    char acName[64];
    if (pName4 != 0) {
        hKey1 = hKey;
        bOpened5 = (hKey1 == 0);
        if (bOpened5)
            Open(true);
        hKey2 = hKey;
        if (hKey2 != 0) {
            uiSize = pSetting->GetFormatSize();
            iType7 = Setting_DataType_00c33090((int)pName4);
            if (iType7 == 1) {
                strcpy_s(acName, 64, pName4);
                acName[0] = 's';
                pName4 = acName;
            }
            hKey7 = hKey;
            bResultTmp = RegSetValueExA(hKey7, pName4, 0, iType7, (const unsigned char*)&pSetting->uValue, uiSize) == 0;
        }
        if (bOpened5)
            Close();
    }
    return bResultTmp;
}

typedef struct HKEY__* HKEY;
typedef unsigned long DWORD;
typedef unsigned char BYTE;
extern "C" __declspec(dllimport) long __stdcall RegQueryValueExA(HKEY hKey, const char* lpValueName, DWORD* lpReserved, DWORD* lpType, BYTE* lpData, DWORD* lpcbData);

extern "C" int __cdecl strcpy_s(char* dst, unsigned int size, const char* src);


int __cdecl GetStateResult(int* apParams);


// @fnv 0x00c5d780
bool RegSettingCollection::ReadFromRegistry(Setting* pSetting) {
    bool bResultTmp = false;
    char shortName6[64];
    char strBuf_[260];
    const char* pName4 = pSetting->pKey;
    if (pName4) {
        bool bOpened5;
        DWORD dwSize3;
        DWORD kDwType;
        BYTE* pData6;
        {
            HKEY hOpenKeyX = hKey;
            bOpened5 = hOpenKeyX == 0;
        }
        if (bOpened5) {
            Open(0);
        }
        {
            HKEY hCurKey5 = hKey;
            if (hCurKey5) {
                dwSize3 = pSetting->GetFormatSize();
                kDwType = GetStateResult((int*)pSetting);
                if (kDwType == 1) {
                    strcpy_s(shortName6, 0x40, pName4);
                    shortName6[0] = 's';
                    pName4 = shortName6;
                    strBuf_[0] = 0;
                    dwSize3 = 0x104;
                    pData6 = (BYTE*)strBuf_;
                } else {
                    pData6 = (BYTE*)&pSetting->uValue;
                }
                HKEY hQueryKey = hKey;
                bResultTmp = RegQueryValueExA(hQueryKey, pName4, 0, &kDwType, pData6, &dwSize3) == 0;
                if (bResultTmp && kDwType == 1) {
                    pSetting->SetStringAndPromoteKeyOwnership(strBuf_);
                }
            }
        }
        if (bOpened5) {
            Close();
        }
    }
    return bResultTmp;
}

// FUN_00c5de30: thiscall, zero two fields, reset sub-object at +0xac
struct ResetHelper {
    unsigned int unk00, unk04, unk08;
    void __thiscall Reset();
};
class FUN_00c5de30_cls {
public:
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8;
    ResetHelper m_ac;
    unsigned short m_b8;
    unsigned short unkBA;
    unsigned int unkBC;
    unsigned int m_c0;
    void __thiscall UpdateState_00c5de30();
};
// Clears m_b8 and m_c0 and resets the m_ac helper.
// @fnv 0x00c5de30
// src: GUESS 0x00c5de30 (confidence: low)
void FUN_00c5de30_cls::UpdateState_00c5de30() {
    ResetHelper scratch;
    unsigned int scratchBuf[4];
    m_b8 = 0;
    m_c0 = 0;
    m_ac.Reset();
}

struct FUN_00c5de70_sub {
    void NiTArray_char_NiTMallocInterface_char_RemoveAll();
};

struct FUN_00c5de70_cls
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
    FUN_00c5de70_sub m_cc;
    void WalkTree(FUN_00c5de70_cls* a, FUN_00c5de70_sub* b);
    void BSMasterParticleSystem_UpdateParticleSystemList();
};

// Calls FUN_005e03d0 on m_cc, then WalkTree with this and &m_cc.
// @fnv 0x00c5de70
// src: XBOX_PDB 0x00c5de70
void FUN_00c5de70_cls::BSMasterParticleSystem_UpdateParticleSystemList()
{
    int tmp;
    m_cc.NiTArray_char_NiTMallocInterface_char_RemoveAll();
    WalkTree(this, &m_cc);
}

extern int g_01203340;

struct FUN_00c5e010_Node {
    virtual void vf00();
    virtual void vf04();
    virtual int vf08();

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
    FUN_00c5e010_Node* next;
};

// @fnv 0x00c5e010
inline void FUN_00c5e010_Node::vf00() {}
inline void FUN_00c5e010_Node::vf04() {}
inline int FUN_00c5e010_Node::vf08() { return 0; }

// src: GUESS 0x00c5e010 (confidence: low)
bool __cdecl Runtime_ProcessEntries_00c5e010(int object) {
    FUN_00c5e010_Node* initial =
        *reinterpret_cast<FUN_00c5e010_Node**>(
            reinterpret_cast<char*>(object) + 0x0C);
    FUN_00c5e010_Node* current = initial;

    while (current != 0) {
        bool found;
        if (current == 0)
            found = false;
        else
            found = current->vf08() ==
                reinterpret_cast<int>(&g_01203340);

        if (found)
            return true;

        FUN_00c5e010_Node* next = current->next;
        current = next;
    }

    return false;
}

struct Walk_TreeNode_cls
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual Walk_TreeNode_cls* v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual int v12();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    unsigned int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    unsigned int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    Walk_TreeNode_cls** m_a0;
    unsigned short unkA4;
    unsigned short m_a6;
};

struct Walk_Helper_cls
{
    void FUN_00c4c8d0(Walk_TreeNode_cls** p);
};

struct Walk_Walker_cls
{
    void WalkTree(Walk_TreeNode_cls* node, int a2);
};

// Recursively walks a tree node: if the node has a non-null v12 result it is passed to the helper, otherwise each child in m_a0 is visited recursively.
// @fnv 0x00c5e280
void Walk_Walker_cls::WalkTree(Walk_TreeNode_cls* node, int pHelper)
{
    if (0 == node)
        return;
    if (node->v12() != 0) {
        Walk_TreeNode_cls* j;
        j = node;
        ((Walk_Helper_cls*)pHelper)->FUN_00c4c8d0(&j);
        return;
    }
    {
    Walk_TreeNode_cls* tmp3 = node != 0 ? node->v03() : 0;
    if (!!tmp3) {
        long v;
        v = tmp3->m_a6;
        for (unsigned int uiIndex = 0; uiIndex < v; uiIndex++) {
            unsigned int scratchA, scratchB, scratchC, scratchD;
            Walk_TreeNode_cls** item = &tmp3->m_a0[uiIndex];
            Walk_TreeNode_cls* value7 = *item;
            Walk_TreeNode_cls* p = value7;
            if (0 != p)
                this->WalkTree(p, pHelper);
        }
    }
    }}

struct S_00c5e3d0 {
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
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    unsigned short unkb8;
    unsigned short unkba;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    float unkdc;
    void BSMasterParticleSystem_ClearUnreferencedEmitters();
    bool BSMasterParticleSystem_ChildHasActiveParticles();
    void FUN_00a5ded0(float* p, int b);
    void BSMasterParticleSystem_UpdateSelectedDownwardPass(float* p, int b);
};
struct S_00c5e3d0_pad { int a, b, c, d; float saved; };
// Calls FUN_00c5e080, then if unkb8 > 0 or FUN_00c5eb90() adds *p to unkdc, passes the sum to FUN_00a5ded0, and restores *p.
// @fnv 0x00c5e3d0
// src: XBOX_PDB 0x00c5e3d0
void S_00c5e3d0::BSMasterParticleSystem_UpdateSelectedDownwardPass(float* p, int b)
{
    S_00c5e3d0_pad tmp;
    BSMasterParticleSystem_ClearUnreferencedEmitters();
    if (unkb8 > 0 || BSMasterParticleSystem_ChildHasActiveParticles()) {
        unkdc += *p;
        tmp.saved = *p;
        *p = unkdc;
        FUN_00a5ded0(p, b);
        *p = tmp.saved;
    }
}

struct FUN_00c5e450_cls {
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
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    unsigned short m_b8;
    unsigned short unkBA;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    float m_dc;

    void BSMasterParticleSystem_ClearUnreferencedEmitters();
    unsigned char BSMasterParticleSystem_ChildHasActiveParticles();
    void NiNode_UpdateRigidDownwardPass(float* f, int b);
    void BSMasterParticleSystem_UpdateRigidDownwardPass(float* f, int b);
};

// Calls FUN_00c5e080, then if m_b8 > 0 or FUN_00c5eb90() is true, adds *f to m_dc, passes the sum to FUN_00a5e1f0, and restores *f.
// @fnv 0x00c5e450
// src: XBOX_PDB 0x00c5e450
void FUN_00c5e450_cls::BSMasterParticleSystem_UpdateRigidDownwardPass(float* pfValue, int b)
{
    float saved;
    int a0;
    int a1;
    int a2;
    int a3;
    BSMasterParticleSystem_ClearUnreferencedEmitters();
    if (m_b8 > 0 || BSMasterParticleSystem_ChildHasActiveParticles())
    {
        m_dc += *pfValue;
        saved = *pfValue;
        *pfValue = m_dc;
        NiNode_UpdateRigidDownwardPass(pfValue, b);
        *pfValue = saved;
    }
}

class C5E7A0Object;

class C5E7A0Stream {
public:
    virtual void vfunc00(); virtual void vfunc01(); virtual void vfunc02(); virtual void vfunc03();
    virtual void vfunc04(); virtual void vfunc05(); virtual void vfunc06(); virtual void vfunc07();
    virtual void vfunc08(); virtual void vfunc09(); virtual void vfunc0A(); virtual void vfunc0B();
    virtual void SaveLinkID(C5E7A0Object* pkObject);
};

void C5E7A0SaveShort(C5E7A0Stream& kStream, unsigned short* pusValue);
void C5E7A0SaveUInt(C5E7A0Stream& kStream, unsigned int* puiValue);

class C5E7A0Node {
public:
    void SaveBinary(C5E7A0Stream& kStream);
};

class C5E7A0Switch : public C5E7A0Node {
public:
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
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    unsigned short unkB8;
    unsigned short m_usFlags;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    C5E7A0Object** m_ppkChildren;
    unsigned short unkD4;
    unsigned short m_usChildCount;

    void BSMasterParticleSystem_SaveBinary(C5E7A0Stream& kStream);
};

// SaveBinary
// Saves the node via C5E7A0Node::SaveBinary, then writes m_usFlags, the child count and each child's link ID to kStream.
// @fnv 0x00c5e7a0
// src: XBOX_PDB 0x00c5e7a0
void C5E7A0Switch::BSMasterParticleSystem_SaveBinary(C5E7A0Stream& kStream)
{
    C5E7A0Node::SaveBinary(kStream);
    C5E7A0SaveShort(kStream, &m_usFlags);
    unsigned int ItemUpdateArray = m_usChildCount;
    C5E7A0SaveUInt(kStream, &ItemUpdateArray);
    for (unsigned int i = 0; i < ItemUpdateArray; i++) {
        C5E7A0Object* pkChild = m_ppkChildren[i];
        kStream.SaveLinkID(pkChild);
    }
}

struct SwitchChild {
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C();
    virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C();
    virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2C();
    virtual void vf30(); virtual void vf34(); virtual void vf38(); virtual void vf3C();
    virtual void vf40(); virtual void vf44(); virtual void vf48(); virtual void vf4C();
    virtual void vf50(); virtual void vf54(); virtual void vf58();
    virtual bool IsEqual(SwitchChild* pOther);
};

// Exe 0x00c5e830: unit-local ListNode view; declarations and layout are preserved.
struct BlkListNodeView {
    BlkListNodeView* m_pkNext;
    BlkListNodeView* m_pkPrev;
    int m_element;
};

struct ListOwner_c5e830 : BaseForCall {
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
    int unkA0;
    int unkA4;
    int unkA8;
    BlkListNodeView* m_pkHead;
    int unkB0;
    int unkB4;
    unsigned short m_usB8;
    unsigned short m_usBA;
    unsigned short m_usBC;
    unsigned short unkBE;
    int unkC0;
    int m_iC4;
    int unkC8;
    int unkCC;
    SwitchChild** m_ppChildren;
    unsigned short unkD4;
    unsigned short m_usChildCount;

    bool BSMasterParticleSystem_IsEqual(NiObject* pObject);
};

// @fnv 0x00c5e830
// src: XBOX_PDB 0x00c5e830
bool ListOwner_c5e830::BSMasterParticleSystem_IsEqual(NiObject* pObject)
{
    ListOwner_c5e830* kPOther;
    BlkListNodeView* kPos8;
    BlkListNodeView* kPos4;
    int a7;
    int b2;
    unsigned int aUiCount1;
    unsigned int uiCount2;
    unsigned int i_;
    SwitchChild* p1;
    SwitchChild* p6;

    if (!BaseForCall::NiNode_IsEqual(pObject))
        return false;

    kPOther = (ListOwner_c5e830*)pObject;
    {
        BlkListNodeView* pHead4 = m_pkHead;
        kPos8 = pHead4;
    }
    {
        BlkListNodeView* pHead7 = kPOther->m_pkHead;
        kPos4 = pHead7;
    }

    if (m_usB8 != kPOther->m_usB8 || m_usBA != kPOther->m_usBA || m_iC4 != kPOther->m_iC4
        || m_usBC != kPOther->m_usBC)
        return false;

    while (kPos8 && kPos4)
    {
        {
            int* pElemA = &kPos8->m_element;
            kPos8 = kPos8->m_pkNext;
            a7 = *pElemA;
        }
        {
            int* pElem4 = &kPos4->m_element;
            kPos4 = kPos4->m_pkNext;
            b2 = *pElem4;
        }
        if (a7 != b2)
            return false;
    }

    aUiCount1 = m_usChildCount;
    uiCount2 = kPOther->m_usChildCount;
    if (aUiCount1 != uiCount2)
        return false;

    for (i_ = 0; i_ < aUiCount1; i_++)
    {
        p1 = m_ppChildren[i_];
        p6 = kPOther->m_ppChildren[i_];
        if ((p1 && !p6) || (!p1 && p6))
            return false;
        if (p1 && !p1->IsEqual(p6))
            return false;
    }

    if (kPos8 || kPos4)
        return false;
    else
        return true;
}

// BSTextureData : NiExtraData (RTTI vftable 0x010c30f4, set by its constructor 0x00c5ecf0 and destructor 0x00c5ed60;
// CreateObject 0x00c5eed0 allocates 0x1c) with a BSSimpleArray<NiAVObject*,1024> at 0x0c.
struct BSTextureData : NiExtraData {
    BSSimpleArray<NiAVObject*, 1024> m_00c;
    BSTextureData();
    virtual ~BSTextureData();
};

// Destructs a BSTextureData object, destroying its embedded array member and base NiExtraData.
// @fnv 0x00c5ed60
BSTextureData::~BSTextureData() {}

// BSTextureData::CreateObject: allocates a BSTextureData and returns it as a NiObject pointer.
// @fnv 0x00c5eed0
NiObject* __cdecl CreateShaderAccumulator(void) {
    NiObject* obj = (NiObject*)new BSTextureData();
    return obj;
}


struct FUN_00a645b0_cls {
    void __thiscall ReadLinkID();
};

void __cdecl NiStreamLoadBinary_float(int a, int* out);

class FUN_00c5ef50_cls {
public:
    void __thiscall FUN_00a7b4a0(int a);
    void __thiscall BSTextureData_LoadBinary(int a1);
};

// @fnv 0x00c5ef50
// src: XBOX_PDB 0x00c5ef50
void FUN_00c5ef50_cls::BSTextureData_LoadBinary(int pTarget) {
    int n;
    FUN_00a7b4a0(pTarget);
    NiStreamLoadBinary_float(pTarget, &n);
    for (int i = 0; i < n; ++i) {
        ((FUN_00a645b0_cls*)pTarget)->ReadLinkID();
    }
    ((FUN_00c5f390_class*)((char*)this + 0xc))->BSSimpleArray_enum_hkpConstraintData_ConstraintType_1024_SetSize(n, 1);
}

class FUN_00c5f100_cls {
public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    void** m_ppItems;
    unsigned int m_uiCount;

    bool Equals(FUN_00c5f100_cls* other);
};

// Returns false if other is null or its item count or any item pointer differs from this object's; otherwise returns true.
// @fnv 0x00c5f100
bool FUN_00c5f100_cls::Equals(FUN_00c5f100_cls* other) {
    if (other == 0) {
        return false;
    }
    FUN_00c5f100_cls* rhs3 = other;
    unsigned int lhsCountB = m_uiCount;
    unsigned int rhsCount = rhs3->m_uiCount;
    if (lhsCountB != rhsCount) {
        return false;
    }
    unsigned int i;
    unsigned int n3;
    for (i = 0; i < (n3 = m_uiCount); i++) {
        void** item = &m_ppItems[i];
        if (*item != rhs3->m_ppItems[i]) {
            return false;
        }
    }
    return true;
}

struct CloneNode : NiMemObject {
    virtual void vfn_0000();
    virtual void vfn_0004();
    virtual void vfn_0008();
    virtual void vfn_000c();
    virtual void vfn_0010();
    virtual void vfn_0014();
    virtual void vfn_0018();
    virtual void vfn_001c();
    virtual void vfn_0020();
    virtual void vfn_0024();
    virtual void vfn_0028();
    virtual void vfn_002c();
    virtual void vfn_0030();
    virtual void vfn_0034();
    virtual void vfn_0038();
    virtual void vfn_003c();
    virtual void vfn_0040();
    virtual void vfn_0044();
    virtual void vfn_0048();
    virtual void vfn_004c();
    virtual void vfn_0050();
    virtual void vfn_0054();
    virtual void vfn_0058();
    virtual void vfn_005c();
    virtual void vfn_0060();
    virtual void vfn_0064();
    virtual void vfn_0068();
    virtual void vfn_006c();
    virtual void vfn_0070();
    virtual void vfn_0074();
    virtual void vfn_0078();
    virtual void vfn_007c();
    virtual void vfn_0080();
    virtual void vfn_0084();
    virtual void vfn_0088();
    virtual void vfn_008c();
    virtual void vfn_0090();
    virtual void vfn_0094();
    virtual void vfn_0098();
    virtual void vfn_009c();
    virtual void vfn_00a0();
    virtual void vfn_00a4();
    virtual void vfn_00a8();
    virtual void vfn_00ac();
    virtual void vfn_00b0();
    virtual void vfn_00b4();
    virtual void vfn_00b8();
    virtual void vfn_00bc();
    CloneNode();
    unsigned int referenceCount;
    const char* name;
    void* extraData;
    unsigned short extraDataCount;
    unsigned short extraDataCapacity;
    void* controller;
    CloneNode* parent;
    void* collisionObject;
    unsigned int flags;
    NiTransform localTransform;
    NiTransform worldTransform;
    NiBound worldBound;
    CloneNode** children;
    unsigned int childCapacity;
    unsigned int childCount;
    void* runtimeState;
};
struct CloneOwnerObj : FUN_00c5fb60_Class {
    CloneNode* __thiscall BSNiNode_CreateClone(void* context);
};
// @fnv 0x00c5fac0
// src: XBOX_PDB 0x00c5fac0
CloneNode* CloneOwnerObj::BSNiNode_CreateClone(void* context)
{
    CloneNode* clone = new CloneNode();
    ForwardToBase(reinterpret_cast<int>(clone), reinterpret_cast<int>(context));
    clone->vfn_00bc();
    return clone;
}

struct FUN_00c5fb80_str
{
    char* m_p;
};

struct FUN_00c5fb80_rec
{
    int unk00;
    int unk04;
    FUN_00c5fb80_str m_08;
};

struct FUN_00c5fb80_pool
{
    char* __thiscall Alloc(unsigned int size);
};

extern "C" char DAT_011f6238;

unsigned int __cdecl FUN_00c5fb80_strlen(const char* s);
void __cdecl FUN_00c5fb80_copyPrefix(char* dst, unsigned int len, const char* src);
char* __cdecl FUN_00c5fb80_appendTail(char* dst, unsigned int len, const char* src);

// Allocates a buffer sized for the record's prefix plus the suffix, copies the prefix if present, appends the suffix and returns the result.
// @fnv 0x00c5fb80
char* __cdecl ConcatPrefixAndSuffix(FUN_00c5fb80_rec* rec, const char* suffix)
{
    FUN_00c5fb80_str pre = rec->m_08;
    char* prefix = pre.m_p;
    unsigned int prefixLen2;
    if (prefix != 0)
        prefixLen2 = FUN_00c5fb80_strlen(prefix);
    else
        prefixLen2 = 0;
    unsigned int total = prefixLen2 + FUN_00c5fb80_strlen(suffix) + 1;
    char* allocated4 = reinterpret_cast<FUN_00c5fb80_pool*>(&DAT_011f6238)->Alloc(total);
    char* buf3 = allocated4;
    if (prefix != 0)
        FUN_00c5fb80_copyPrefix(buf3, total, prefix);
    return FUN_00c5fb80_appendTail(buf3, total, suffix);
}

extern void* DAT_010c32c4;

struct FUN_00c5fd50_cls
{
    void* m_vtbl;
    void FUN_00c31750();
    void UpdateState_00c5fd50();
};

// @fnv 0x00c5fd50
// src: GUESS 0x00c5fd50 (confidence: low)
void FUN_00c5fd50_cls::UpdateState_00c5fd50()
{
    m_vtbl = &DAT_010c32c4;
    FUN_00c31750();
}

// Allocates a BSPSysStripUpdateModifier.
// @fnv 0x00c5fee0
BSPSysStripUpdateModifier* __cdecl CreatePositionModifierInstance() {
    BSPSysStripUpdateModifier* instance = new BSPSysStripUpdateModifier;
    return instance;
}

struct MyStream;
void NiStreamLoadBinary_float(MyStream* stream, void* value);

struct ParticlePositionModifier {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    void FUN_00c318b0(MyStream* stream);
    void BSPSysStripUpdateModifier_LoadBinary(MyStream* stream);
};

// @fnv 0x00c5ff60
// src: XBOX_PDB 0x00c5ff60
void ParticlePositionModifier::BSPSysStripUpdateModifier_LoadBinary(MyStream* stream)
{
    FUN_00c318b0(stream);
    NiStreamLoadBinary_float(stream, &unk18);
}

namespace fnv_00c41610 {
#include <windows.h>


class SlotValueSource {
public:
    virtual void Reserved0();
    virtual unsigned int GetSlotValue(unsigned int index);
};

struct FUN_00c41610_Entry {
    unsigned int m_uiThreadId;
    unsigned int m_uiFilterValue;
};

class FUN_00c41610_cls {
public:
    unsigned int m_uiItemCount;             // +0x00
    unsigned int m_tlsIndex;          // +0x04
    FUN_00c41610_Entry* m_entries;    // +0x08
    LONG m_seq;                       // +0x0c

    unsigned int SetSlotValue(SlotValueSource* source);
};

// @fnv 0x00c41610
unsigned int FUN_00c41610_cls::SetSlotValue(SlotValueSource* source) {
    unsigned int uiSlotValue = 0;
    unsigned int c = (unsigned int)(InterlockedIncrement(&m_seq) - 1);
    if (c < m_uiItemCount) {
        uiSlotValue = source->GetSlotValue(c);
        m_entries[c].m_uiFilterValue = uiSlotValue;
        DWORD threadId;
        threadId = GetCurrentThreadId();
        m_entries[c].m_uiThreadId = threadId;
        DWORD result = m_tlsIndex;
        TlsSetValue(result, (LPVOID)uiSlotValue);
    }
    return uiSlotValue;
}
}  // namespace fnv_00c41610

char* __cdecl NiGetViewerString(const char* name, bool value);


struct KwHi {
    int n0;
    char c4;
    char c5;
    char c6;
    bool bDynamic;
    int n8;
    char c12;
    char c13;
    char c14;
    bool bEditorMarker;
    int n16;
    char c20;
    char c21;
    char c22;
    bool bAddon;
    int n24;
    char c28;
    char c29;
    char c30;
    bool bComplex;
    int n32;
    char c36;
    char c37;
    char c38;
    bool bRagDoll;
    int n40;
    short s44;
    bool bHavok;
    bool bAnimated;
};

struct KwLo {
    int n0;
    int n4;
    int n8;
    int n12;
    char c16;
    char c17;
    char c18;
    bool bIKTarget;
    int n20;
    int n24;
    int n28;
    int n32;
    char c36;
    char c37;
    char c38;
    bool bArticulated;
};

struct ThisC43220 {
    int f00;
    int f04;
    int f08;
    unsigned int m_flags;
    void FUN_00a99d70(NiTPrimitiveArray<unsigned int>* arr);
    void AppendKeywordFlags(NiTPrimitiveArray<unsigned int>* arr);
};

// @fnv 0x00c43220
void ThisC43220::AppendKeywordFlags(NiTPrimitiveArray<unsigned int>* arr)
{
    unsigned int v6;
    unsigned int e4;
    unsigned int v3;
    unsigned int e0;
    unsigned int v1;
    unsigned int e6;
    unsigned int n4;
    unsigned int e3;
    unsigned int id2;
    unsigned int id8;
    void* s2;
    KwHi v8;
    KwLo obj;
    this->FUN_00a99d70(arr);
    s2 = g_01202de0;
    v6 = (unsigned int)NiViewerStrings_NiGetViewerString_Title(s2);
    arr->SetAtGrow(arr->m_usSize, v6);
    v8.bAnimated = (this->m_flags & 1) != 0;
    e4 = (unsigned int)NiGetViewerString("bAnimated", v8.bAnimated);
    arr->SetAtGrow(arr->m_usSize, e4);
    v8.bHavok = (this->m_flags & 2) != 0;
    v3 = (unsigned int)NiGetViewerString("bHavok", v8.bHavok);
    arr->AddFirstEmpty(v3);
    v8.bRagDoll = (this->m_flags & 4) != 0;
    e0 = (unsigned int)NiGetViewerString("bRagDoll", v8.bRagDoll);
    arr->AddFirstEmpty(e0);
    v8.bComplex = (this->m_flags & 8) != 0;
    v1 = (unsigned int)NiGetViewerString("bComplex", v8.bComplex);
    arr->AddFirstEmpty(v1);
    v8.bAddon = (this->m_flags & 0x10) != 0;
    e6 = (unsigned int)NiGetViewerString("bAddon", v8.bAddon);
    arr->AddFirstEmpty(e6);
    v8.bEditorMarker = (this->m_flags & 0x20) != 0;
    n4 = (unsigned int)NiGetViewerString("bEditorMarker", v8.bEditorMarker);
    arr->AddFirstEmpty(n4);
    v8.bDynamic = (this->m_flags & 0x40) != 0;
    e3 = (unsigned int)NiGetViewerString("bDynamic", v8.bDynamic);
    arr->AddFirstEmpty(e3);
    obj.bArticulated = (this->m_flags & 0x80) != 0;
    id2 = (unsigned int)NiGetViewerString("bArticulated", obj.bArticulated);
    arr->AddFirstEmpty(id2);
    obj.bIKTarget = (this->m_flags & 0x100) != 0;
    id8 = (unsigned int)NiGetViewerString("bIKTarget", obj.bIKTarget);
    arr->AddFirstEmpty(id8);
}

class BC45120CloningProcess;

class BC45120Object {
public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    BC45120Object();
    virtual ~BC45120Object();

    void CopyMemberData(BC45120Object* pkDest, BC45120CloningProcess& kCloning);
    BC45120Object* Clone(BC45120CloningProcess& kCloning);

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
};

// @fnv 0x00c45120
BC45120Object* BC45120Object::Clone(BC45120CloningProcess& kCloning)
{
    BC45120Object* pkClone = new BC45120Object;
    CopyMemberData(pkClone, kCloning);
    return pkClone;
}

extern NiRefObject* DAT_01202e14;
extern unsigned int DAT_01202e18;
void __cdecl FUN_00fdd690();
int __cdecl FUN_00ec658f(void (__cdecl*)());
// @fnv 0x00c462f0
template <>
void NiTArray<NiPointer<NiRefObject>, NiTNewInterface<NiPointer<NiRefObject> > >::SetAt(unsigned int index, const NiPointer<NiRefObject>& aSlot) {
 NiRefObject* j;
 if (!(DAT_01202e18 & 1)) {
  DAT_01202e18 |= 1;
  DAT_01202e14 = 0;
  if (DAT_01202e14) {
   j = DAT_01202e14;
   NiPointer<NiRefObject>* destination;
   NiRefObject* previous;
   InterlockedIncrement((volatile long*)&j->m_uiRefCount);
  }
  FUN_00ec658f(FUN_00fdd690);
 }
 if (index >= m_usSize) {
  m_usSize = index + 1;
  if ((bool)(int)(aSlot.m_pObject != DAT_01202e14)) ++m_usESize;
 } else {
  if ((bool)(int)(aSlot.m_pObject != DAT_01202e14)) {
   if ((bool)(int)(m_pBase[index].m_pObject == DAT_01202e14)) ++m_usESize;
  } else {
   if ((bool)(int)(m_pBase[index].m_pObject != DAT_01202e14)) --m_usESize;
  }
 }
 m_pBase[index].operator=(aSlot);
}

struct Entry { int type; int a; int b; };
struct Target {
 int unk00, unk04, unk08, unk0c, unk10, unk14;
 Entry* data;
 int unk1c, unk20, unk24;
 int count;
 void CompactEntries();
};
// Compacts the entry array in place, skipping type 4/5 pairs followed by type 6 and copying type 7/8 entries with their following entry.
// @fnv 0x00c49700
void Target::CompactEntries() {
 int original = 0;
 int removed = count;
 for (int i = 0; i < count; i++) {
  while (i < count && count > 0 && (data[i + original].type == 4 || data[i + original].type == 5) && data[i + original + 1].type == 6) {
   original += 2;
   count -= 2;
  }
  if (i + original < removed) {
   int* source = &data[i + original].type;
   data[i].type = *source;
   if (data[i].type == 7 || data[i].type == 8) {
    int* next = &data[i + original + 1].type;
    data[i + 1].type = *next;
    i++;
   }
  }
 }
}

struct MeshStatsData {
    unsigned int unk00,unk04;
    unsigned short vertices,unk0a;
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
    unsigned int unk48;
    unsigned int unk4c;
    unsigned short triangles;
};
struct MeshStatsEntry {
    unsigned int unk00;
    unsigned int unk04;
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
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    MeshStatsData* data;
    unsigned int unkbc,unkc0,unkc4,unkc8,unkcc;
    unsigned int bytes;
};
struct Statistics { unsigned int meshes,triangles,vertices,materials,other,bytes; };
struct MeshCollection {
    unsigned int unk00;
    unsigned int unk04;
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
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int other;
    unsigned short materials,unkba;
    unsigned int unkbc,unkc0,unkc4,unkc8,unkcc;
    MeshStatsEntry** meshes;
    unsigned short capacity,used;
    void AccumulateStatistics(Statistics*);
};
// Sums triangles, vertices and bytes over the used mesh entries and writes them, along with materials, other and mesh count, into output.
// @fnv 0x00c5df00
void MeshCollection::AccumulateStatistics(Statistics* pStats)
{
    unsigned int cf = 0;
    unsigned int eb = 0;
    unsigned int f = 0;
    unsigned int s = used;
    unsigned int q;
    MeshStatsEntry* b;
    MeshStatsData* ba;
    __declspec(align(2)) unsigned short k;
    MeshStatsData* l;
    __declspec(align(2)) unsigned short c;
    unsigned int e;
    unsigned int j;
    for (q = 0; q < s; ++q) {
        b = meshes[q];
        if (b) {
            ba = b->data;
            k = ba->triangles;
            cf += k;
            l = b->data;
            c = l->vertices;
            eb += c;
            e = b->bytes;
            f += e;
        }
    }
    pStats->triangles = cf;
    pStats->vertices = eb;
    pStats->bytes = f;
    pStats->materials = materials;
    j = other;
    pStats->other = j;
    pStats->meshes = s;
}

namespace fnv_00c5e350 {
struct Target {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4;
    unsigned short count_b8, unkba;
    int unkbc, unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8;
    float elapsed_dc;
    void BSMasterParticleSystem_ClearUnreferencedEmitters();
    unsigned char BSMasterParticleSystem_ChildHasActiveParticles();
    void FUN_00a5dd70(float* time, int arg);
    void UpdateTimed(float* time, int arg);
};
// Calls FUN_00c5e080, then if count_b8 > 0 or FUN_00c5eb90() adds *time to elapsed_dc and calls FUN_00a5dd70 with elapsed_dc, restoring *time.
// @fnv 0x00c5e350
void Target::UpdateTimed(float* time, int arg) {
    float savedTime;
    BSMasterParticleSystem_ClearUnreferencedEmitters();
    if (count_b8 > 0 || BSMasterParticleSystem_ChildHasActiveParticles()) {
        elapsed_dc += *time;
        float previousTime, accumulatedTime, updateTime, deltaTime;
        savedTime = *time;
        *time = elapsed_dc;
        FUN_00a5dd70(time, arg);
        *time = savedTime;
    }
}
}  // namespace fnv_00c5e350

// Refresh every key whose time lags the given time by more than the controller's threshold.

struct FDA0Key {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};

class FDA0Data {
public:
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
    unsigned short m_usKeyCount;
    unsigned short unk52;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    FDA0Key* m_pKeyArray;

    float GetKeyTime(unsigned short usIndex);
    void SetKeyTime(unsigned short usIndex, float fTime);
};

class FDA0Controller {
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    float m_fThreshold;

    void UpdateKeyTimes(float fTime, FDA0Data* pkArg);
};

// For each key, if the elapsed time since its stored time exceeds m_fThreshold, resets that key's time to fTime.
// @fnv 0x00c5fda0
void FDA0Controller::UpdateKeyTimes(float fTime, FDA0Data* pkArg)
{
    FDA0Data* pkData = pkArg;
    unsigned short usKeyCount = pkArg->m_usKeyCount;
    FDA0Key* pkKey = pkArg->m_pKeyArray;
    for (unsigned short i = 0; i < usKeyCount; i++, pkKey++) {
        float fTimeSinceScaleStart = fTime - pkData->GetKeyTime(i);
        if (fTimeSinceScaleStart > m_fThreshold)
            pkData->SetKeyTime(i, fTime);
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(long volatile* dest, long exchange, long comparand);

struct Inner5b
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
    virtual void Fire();
};

struct Tag5b
{
    unsigned int bits;
    void Init(int flag);
};

struct Scratch5b
{
    unsigned int unk00;
    unsigned int unk04;
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
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
};

struct Pad16_5b { unsigned int unk00; unsigned int unk04; unsigned int unk08; unsigned int unk0C; };

struct Lock5b
{
    Inner5b* m00;
    unsigned int* m04;
    unsigned int* m08;
    unsigned int* m0c;
    unsigned int* m10;
    unsigned int m14;
    unsigned int m18;

    bool Check(unsigned int a, unsigned int b, unsigned int c);
    void Step(unsigned int p);
    bool TryAcquireAndFire(unsigned int a, unsigned int b, unsigned int c);
};

// @fnv 0x00c403d0
bool Lock5b::TryAcquireAndFire(unsigned int a, unsigned int b, unsigned int c)
{
    bool result2 = false;
    Tag5b t1;
    Tag5b t2;
    Tag5b t7;
    {
        Scratch5b scratch;
    }
    while (true)
    {
        unsigned int* aP_m10;
        bool _ok5;
        unsigned int aNVv;
        Tag5b* _pt1;
        unsigned int AEQ;
        Tag5b* pt3_2;
        unsigned int node;
        Tag5b* pt3b;
        unsigned int* p14b3;
        bool aOk5;
        unsigned int nodeB5;
        unsigned int* p14bLen;
        unsigned int inv5;
        Tag5b* pt2_2;
        unsigned int _oldJk;
        Tag5b* pt1bPtr;
        unsigned int _v18;
        unsigned int* _p18a;
        unsigned int v18a;
        unsigned int* p18aP;

        if (!Check(a, b, c))
        {
            result2 = false;
            break;
        }

        p18aP = &m18;
        v18a = *p18aP & ~1u;
        t1.bits = v18a;
        t1.Init(0);

        _p18a = &m18;
        _v18 = *_p18a & ~1u;
        t2.bits = _v18;
        t2.Init(1);

        pt1bPtr = &t1;
        _oldJk = pt1bPtr->bits;
        pt2_2 = &t2;
        inv5 = pt2_2->bits;
        p14bLen = &m14;
        nodeB5 = *p14bLen & ~1u;
        aOk5 = InterlockedCompareExchange((long volatile*)(nodeB5 + 0xc), (long)inv5, (long)_oldJk) == (long)_oldJk;
        if (!aOk5)
            continue;

        p14b3 = &m14;
        node = *p14b3 & ~1u;
        t7.bits = node;
        pt3b = &t7;
        if (0)
            pt3b->bits |= 1u;
        else
            pt3b->bits &= ~1u;

        pt3_2 = &t7;
        AEQ = pt3_2->bits;
        _pt1 = &t1;
        aNVv = _pt1->bits;
        aP_m10 = m10;
        _ok5 = InterlockedCompareExchange((long volatile*)aP_m10, (long)aNVv, (long)AEQ) == (long)AEQ;
        if (_ok5)
        {
            Pad16_5b aOld2;
            unsigned int* p14c = &m14;
            Step(*p14c & ~1u);
        }
        else
        {
            Check(a, b, c);
        }

        m00->Fire();
        result2 = true;
        break;
    }

    *m04 = 0;
    *m08 = 0;
    *m0c = 0;
    return result2;
}

// FUN_00c42560 increments the reference count at offset 0x08; NiRefObject uses offset 0x04.
struct RefObj {
    int unk00;
    int unk04;
    volatile long m_iObjectReferenceCount;
};

struct NodeKey {
    int a;
    int b;
};

struct NodeFlags {
    unsigned int m_uiValue1;
};

struct Node {
    NodeKey m_key;
    NiPointer<RefObj> m_pReferencedObject;
    NodeFlags m_flags;
};

struct TaggedNodePtr {
    unsigned int m_uiBits;
};

struct Handler {
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0C();
    virtual void vfn10();
    virtual void vfn14();
    virtual void vfn18();
    virtual void vfn1C();
    virtual void vfn20();
    virtual void vfn24();
    virtual void vfn28();
    virtual void vfn2C();
    virtual void Process(NodeKey key, NodeKey* pKey);
};

struct NodeQueue {
    Handler* m_pHandler;
    int* m_p04;
    int* m_p08;
    int* m_p0C;
    int unk10;
    TaggedNodePtr m_kSecond;
    TaggedNodePtr m_kFirst;

    bool __thiscall LockFreeMapInterface_Find_0(int arg, NodeKey key);
    bool LockFreeMap_int64_NiPointer_BSTask_int64_LockFreeMapInterface_GetNext(int arg, NodeKey* pKey, NiPointer<RefObj>* pOut);
};

struct FUN_00c42560_pad {
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
};

// @fnv 0x00c42560
// src: COMMUNITY 0x00c42560
bool NodeQueue::LockFreeMap_int64_NiPointer_BSTask_int64_LockFreeMapInterface_GetNext(int arg, NodeKey* pKey, NiPointer<RefObj>* pOut)
{
    FUN_00c42560_pad pad;
    bool it;
    {
        RefObj* bit;
        int AA;
        int AC;
        int BL;
        NodeFlags* it9;
        Node* aIt;
        TaggedNodePtr* nx;
        NiPointer<RefObj>* itP;
        RefObj* itZ;
        TaggedNodePtr* nx5;
        TaggedNodePtr* unX;
        NodeFlags* enX;
        Node* itK;
        TaggedNodePtr* ret;
        TaggedNodePtr* val;
        RefObj* itH;
        NodeFlags* itX;
        Node* hit;
        TaggedNodePtr* itC;
        NiPointer<RefObj>* src1;
        RefObj* nX;
        TaggedNodePtr* aIT;
        TaggedNodePtr* aNx;
        NodeFlags* it7;
        Node* lim;
        TaggedNodePtr* tag;
        TaggedNodePtr* iT;
        int A9;
        it = false;
        while (1) {
            it = LockFreeMapInterface_Find_0(arg, *pKey);
            if (it) {
                iT = &m_kFirst;
                if ((iT->m_uiBits & ~1u) != 0) {
                    tag = &m_kFirst;
                    lim = (Node*)(tag->m_uiBits & ~1u);
                    it7 = &lim->m_flags;
                    if (it7->m_uiValue1 & 1 ? true : false)
                        continue;
                    aNx = &m_kFirst;
                    m_pHandler->Process(((Node*)(aNx->m_uiBits & ~1u))->m_key, pKey);
                    aIT = &m_kFirst;
                    src1 = &((Node*)(aIT->m_uiBits & ~1u))->m_pReferencedObject;
                    if (pOut->m_pObject != src1->m_pObject) {
                        if (pOut->m_pObject)
                            ((ObjA*)pOut->m_pObject)->BSTask_int64_DecRefCount();
                        pOut->m_pObject = src1->m_pObject;
                        if (pOut->m_pObject) {
                            nX = pOut->m_pObject;
                            FUN_00fdf1c0((void*)&nX->m_iObjectReferenceCount);
                        }
                    }
                    it = true;
                    itC = &m_kFirst;
                    hit = (Node*)(itC->m_uiBits & ~1u);
                    itX = &hit->m_flags;
                    if (itX->m_uiValue1 & 1 ? true : false) {
                        if (pOut->m_pObject != 0) {
                            if (pOut->m_pObject)
                                ((ObjA*)pOut->m_pObject)->BSTask_int64_DecRefCount();
                            pOut->m_pObject = 0;
                            if (pOut->m_pObject) {
                                itH = pOut->m_pObject;
                                FUN_00fdf1c0((void*)&itH->m_iObjectReferenceCount);
                            }
                        }
                        continue;
                    }
                    break;
                } else {
                    it = false;
                    break;
                }
            } else {
                val = &m_kSecond;
                if ((val->m_uiBits & ~1u) != 0) {
                    ret = &m_kSecond;
                    itK = (Node*)(ret->m_uiBits & ~1u);
                    enX = &itK->m_flags;
                    if (enX->m_uiValue1 & 1 ? true : false)
                        continue;
                    unX = &m_kSecond;
                    m_pHandler->Process(((Node*)(unX->m_uiBits & ~1u))->m_key, pKey);
                    nx5 = &m_kSecond;
                    itP = &((Node*)(nx5->m_uiBits & ~1u))->m_pReferencedObject;
                    if (pOut->m_pObject != itP->m_pObject) {
                        if (pOut->m_pObject)
                            ((ObjA*)pOut->m_pObject)->BSTask_int64_DecRefCount();
                        pOut->m_pObject = itP->m_pObject;
                        if (pOut->m_pObject) {
                            itZ = pOut->m_pObject;
                            FUN_00fdf1c0((void*)&itZ->m_iObjectReferenceCount);
                        }
                    }
                    it = true;
                    nx = &m_kSecond;
                    aIt = (Node*)(nx->m_uiBits & ~1u);
                    it9 = &aIt->m_flags;
                    if (it9->m_uiValue1 & 1 ? true : false) {
                        if (pOut->m_pObject != 0) {
                            if (pOut->m_pObject)
                                ((ObjA*)pOut->m_pObject)->BSTask_int64_DecRefCount();
                            pOut->m_pObject = 0;
                            if (pOut->m_pObject) {
                                bit = pOut->m_pObject;
                                FUN_00fdf1c0((void*)&bit->m_iObjectReferenceCount);
                            }
                        }
                        continue;
                    }
                    break;
                } else {
                    it = false;
                    break;
                }
            }
        }
        *m_p04 = 0;
        *m_p08 = 0;
        *m_p0C = 0;
    }
    return it;
}

struct C45440_Obj : FUN_00c450d0 {
    int u64;
    int u68;
    int u6C;
    int u70;
    int u74;
    int u78;
    int u7C;
    int u80;
    int u84;
    int u88;
    int u8C;
    int u90;
    int u94;
    int u98;
    int u9C;
    int uA0;
    int uA4;
    int uA8;
    int uAC;
    static void* __cdecl operator new(unsigned int size);
};

// Allocates and returns a new C45440_Obj instance via its operator new.
// @fnv 0x00c45440
C45440_Obj* __cdecl CreateC45440Obj(void) {
    return new C45440_Obj;
}

struct Animation;

struct C5EDC0_AnimExtra {
    int unk00;
    int unk04;
    int unk08;
    NiTObjectArray<Animation*> m_kAnimations;
    unsigned int __thiscall AddAnimation(Animation* apAnim);
};

// @fnv 0x00c5edc0
unsigned int C5EDC0_AnimExtra::AddAnimation(Animation* apAnim)
{
    unsigned int uiIndex;
    unsigned int ItemUpdateArray;
    unsigned int uiCapacity;
    return m_kAnimations.Add(apAnim);
}

namespace c30 {
struct FUN_00c5fd30 : BSFaceGenMorphData { FUN_00c5fd30(); int m[5]; };
struct Owner30 {
    void BSPSysStripUpdateModifier_CopyMembers(FUN_00c5fd30* mod, int arg);
    FUN_00c5fd30* CreateMorphData(int arg);
};
// Allocates a FUN_00c5fd30, initialises it via FUN_00c5fec0 with arg, and returns the new object.
// @fnv 0x00c5fe30
FUN_00c5fd30* Owner30::CreateMorphData(int arg)
{
    FUN_00c5fd30* mod = new FUN_00c5fd30;
    BSPSysStripUpdateModifier_CopyMembers(mod, arg);
    return mod;
}
}

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds);
struct SemaphoreC44 {
    volatile long m_lCount;
    void* m_pSemaphore;
};
struct WorkerC44 {
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
    SemaphoreC44 m_kCompletionSemaphore;
};
struct FUN_00c44d30_cls {
    WorkerC44** m_ppkWorkers;
    void WaitForWorkers();
};
// Waits on each worker's semaphore handle and decrements its count.
// @fnv 0x00c44d30
void FUN_00c44d30_cls::WaitForWorkers() {
    for (unsigned int i = 0; i < 1; i++) {
        WorkerC44* pkWorker2 = m_ppkWorkers[i];
        SemaphoreC44* pkSemaphore = &pkWorker2->m_kCompletionSemaphore;
        WaitForSingleObject(pkSemaphore->m_pSemaphore, 0xffffffff);
        InterlockedDecrement(&pkSemaphore->m_lCount);
    }
}

struct FUN_00c467c0_cls : ParticlePositionModifier {
    void BSWindModifier_LoadBinary(MyStream* stream);
};
// Calls FUN_00c318b0 on stream, then FUN_00a26df0 on stream and unk18.
// @fnv 0x00c467c0
// src: XBOX_PDB 0x00c467c0
void FUN_00c467c0_cls::BSWindModifier_LoadBinary(MyStream* stream) {
    FUN_00c318b0(stream);
    NiStreamLoadBinary_float(stream, &unk18);
}

struct FUN_00c47b50Vec3;

struct FUN_00c47b50Transform { float v0; float v1; float v2; float v3; float v4; float v5; };

struct FUN_00c47b50Record {

    int m00; int m04; int m08; int m0c; int m10; int m14; int m18; int m1c;

    int m20; int m24; int m28; int m2c; int m30; int m34; int m38; int m3c;

    int m40; int m44; int m48; int m4c; int m50; int m54; int m58; int m5c;

    int m60;

};

struct FUN_00c47b50Vec3 {

    float x; float y; float z;

    void SetPlaneFromThreePoints(FUN_00c47b50Vec3*, FUN_00c47b50Vec3*, FUN_00c47b50Transform*);

    float DotProduct(FUN_00c47b50Vec3*);

};

struct FUN_00c47b50Arg {

    void BSOcclusionPlane_GetVertices(FUN_00c47b50Vec3*);

    void BSOcclusionPlane_UpdateFrustumPlanes(FUN_00c47b50Vec3, FUN_00c47b50Record*);

};

struct FUN_00c47b50Array {

    int unk00;

    FUN_00c47b50Record* m_pData;

    int unk08;

    int m_iCapacity;

    void FUN_00c4a070(int, bool);

};

struct FUN_00c47b50Elem { int value; int index; int unused; };

struct FUN_00c47b50SmallArray {

    int unk00;

    FUN_00c47b50Elem* m_pData;

    int unk08;

    int m_iCapacity;

    void FUN_00c4a1e0(int, bool);

};

struct FUN_00c47b50Class {

    int unk00;

    FUN_00c47b50Array first;

    FUN_00c47b50SmallArray second;

    int index;

    int count;

    int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48;

    int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68;

    int unk6c; int unk70; int unk74; int unk78; int unk7c; int unk80; int unk84; int unk88;

    int unk8c; int unk90;

    FUN_00c47b50Vec3 position;

    void UpdateRecords(FUN_00c47b50Arg*, int);

};

extern "C" double __cdecl FUN_00ec6cde(double);

// @fnv 0x00c47b50
void FUN_00c47b50Class::UpdateRecords(FUN_00c47b50Arg* arg, int unused)
{
    long itemsCapacity5;
    int itemsCapacityAgain5;
    int recordsCapacity;
    long recordsCapacityAgain;
    FUN_00c47b50Vec3 v1;
    FUN_00c47b50Transform matrix8;
    FUN_00c47b50Vec3 v;
    FUN_00c47b50Vec3 aV2;
    float fStack_8;
    int iStack_5c7;
    FUN_00c47b50Vec3* p5;

    itemsCapacity5 = second.m_iCapacity;
    if (count + 2 >= itemsCapacity5) {
        itemsCapacityAgain5 = second.m_iCapacity;
        second.FUN_00c4a1e0(itemsCapacityAgain5 + 10, true);
    }
    recordsCapacity = first.m_iCapacity;
    if (1 + index >= recordsCapacity) {
        recordsCapacityAgain = first.m_iCapacity;
        first.FUN_00c4a070(recordsCapacityAgain + 4, true);
    }
    iStack_5c7 = 4;
    p5 = &v1;
    while (--iStack_5c7 >= 0) {
        p5++;
    }
    arg->BSOcclusionPlane_GetVertices(&v1);
    v.SetPlaneFromThreePoints(&v1, &aV2, &matrix8);
    second.m_pData[count].value = 7;
    count += 1;
    second.m_pData[count].value = index;
    count++;
    arg->BSOcclusionPlane_UpdateFrustumPlanes(position, &first.m_pData[index]);
    {
        float records;
        records = v.DotProduct(&position) - fStack_8;
    if ((float)FUN_00ec6cde((double)records) > 5.0) {
        FUN_00c47b50Record* r1 = &first.m_pData[index];
        r1->m60 = 0x3f;
    } else {
        FUN_00c47b50Record* r2 = &first.m_pData[index];
        r2->m60 = 0;
    }
    }
    index++;
}

struct S_00c4dd60_Key {
    unsigned short unk00;
    unsigned short w16;
};

struct S_00c4dd60_Vec2 {
    float x;
    float y;
};

struct S_00c4dd60_Elem {
    S_00c4dd60_Vec2 v;
    int unk08;
};

struct S_00c4dd60_Table {
    int unk00;
    S_00c4dd60_Elem* m_pElems;
};

struct S_00c4dd60_Words {
    int unk00;
    unsigned short* m_pWords;
    unsigned int m_uiItemCount;

    bool __thiscall Contains(unsigned short* key);
};

struct S_00c4dd60_Owner {
    S_00c4dd60_Table* m_pTable;
    S_00c4dd60_Words* m_pWords;

    bool __thiscall IsKeyValid(int key, int a, int b);
    bool __thiscall Helper00c4de80(S_00c4dd60_Vec2 p, int a, int key, int b);
};

// Checks whether key is absent from m_pWords and no other word's element position passes Helper00c4de80; returns false if either check fails.
// @fnv 0x00c4dd60
bool S_00c4dd60_Owner::IsKeyValid(int key, int aiExcludeA, int aiExcludeB)
{
    int w;
    S_00c4dd60_Vec2 pos2;
    int TJ;
    if (m_pWords != 0) {
        unsigned int cnt5;
        S_00c4dd60_Key k;
        cnt5 = m_pWords->m_uiItemCount;
        if (cnt5 > 0) {
            S_00c4dd60_Vec2 pad2;
            k.w16 = (unsigned short)key;
            if (!m_pWords->Contains(&k.w16)) {
                unsigned int count2;
                for (TJ = 0; TJ < (count2 = m_pWords->m_uiItemCount); ++TJ) {
                    w = m_pWords->m_pWords[TJ];
                    if (w == aiExcludeA || w == aiExcludeB) {
                        continue;
                    }
                    S_00c4dd60_Elem* AE = &m_pTable->m_pElems[w];
                    float FX = m_pTable->m_pElems[w].v.x;
                    float fy = AE->v.y;
                    pos2.x = FX;
                    pos2.y = fy;
                    if (Helper00c4de80(pos2, aiExcludeA, key, aiExcludeB)) {
                        return false;
                    }
                }
                return true;
            } else {
                return false;
            }
        }
    }
    return true;
}

struct FUN_00c5ee90_cls : NiExtraData {
    FUN_00c5f500_class unk0C;
    void BSTextureData_CopyMembers(NiBinaryExtraData* dest, CloningProcess* cloning);
};
// @fnv 0x00c5ee90
// src: XBOX_PDB 0x00c5ee90
void FUN_00c5ee90_cls::BSTextureData_CopyMembers(NiBinaryExtraData* dest, CloningProcess* cloning) {
    FUN_00c5ee90_cls* other;
    NiExtraData::CopyMembers_00a7b330(dest, cloning);
    unk0C.BSSimpleArray_NiAVObject_1024_CopyTo_1024(&((FUN_00c5ee90_cls*)dest)->unk0C);
}

struct FUN_00a63430_Obj {
    unsigned int FUN_00a63430();
};

struct FUN_00c5efb0_Class : NiExtraData {
    int unk0C;
    unsigned int* unk10;
    unsigned int unk14;
    void BSTextureData_LinkObject(NiStream& stream);
};

// Links the stream, then reads unk14 unsigned ints from the stream into the array at unk10.
// @fnv 0x00c5efb0
// src: XBOX_PDB 0x00c5efb0
void FUN_00c5efb0_Class::BSTextureData_LinkObject(NiStream& stream)
{
    unsigned int i;
    unsigned int count;
    NiExtraData::LinkObject(stream);
    for (count = 0; count < (i = unk14); count++) {
        unsigned int* slot = unk10 + count;
        *slot = ((FUN_00a63430_Obj*)&stream)->FUN_00a63430();
    }
}

#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged

// FUN_00c43d00: builds the INISettings list snapshot ("INISettings" name + AddFirstEmpty,
// then count via FUN_0044f890 and "Total INISettings" message + AddFirstEmpty).
// SinkSave is a stand-in for the TU's local aggregate frame reservation.

struct SinkSave { unsigned int data[15]; };

struct FUN_00c43d00_Host {
    unsigned int SettingCollectionList_Setting_GetViewerStrings(NiTPrimitiveArray<unsigned int>& arr);
    unsigned int INISettingCollection_GetViewerStrings(NiTPrimitiveArray<unsigned int>& arr);
};

// @fnv 0x00c43d00
// src: XBOX_PDB 0x00c43d00
unsigned int FUN_00c43d00_Host::INISettingCollection_GetViewerStrings(NiTPrimitiveArray<unsigned int>& arr)
{
    SinkSave save;
    unsigned int key = (unsigned int)NiViewerStrings_NiGetViewerString_Title("INISettings");
    ((NiTPrimitiveArray<unsigned int>*)&arr)->AddFirstEmpty(key);
    unsigned int count = SettingCollectionList_Setting_GetViewerStrings(arr);
    unsigned int msg = (unsigned int)NiGetViewerString_00a7d510("Total INISettings", count);
    ((NiTPrimitiveArray<unsigned int>*)&arr)->AddFirstEmpty(msg);
    return count;
}

struct SetView {
    int unk00;
    union {
        int i;
        unsigned int u;
        float f;
        char* s;
    } data;
    char* name;
};

int __cdecl sprintf_s(char*, unsigned int, const char*, ...);
extern "C" __declspec(dllimport) int __stdcall WritePrivateProfileStringA(const char*, const char*, const char*, const char*);

struct IniFile {
    virtual void z0();
    virtual void z1();
    virtual void z2();
    virtual void z3();
    virtual void z4();
    virtual void z5();
    virtual void Open(int);
    virtual void Close();
    char path[0x104];
    int fileHandle;
    bool INISettingCollection_WriteSetting(SetView* setting);
};

// Writes setting to the INI file at path via WritePrivateProfileStringA, formatting data by the type from FUN_00c33090(name); opens and closes the file if needed.
// @fnv 0x00c43e90
// src: XBOX_PDB 0x00c43e90
bool IniFile::INISettingCollection_WriteSetting(SetView* setting) {
    bool handle;
    bool result = false;
    {
        char Dir[0x40];
        int Dir2;
        char Left[0x40];
        char EndLoc2[0x100];
        unsigned int Diff;
        unsigned int EndLoc;
        unsigned int EndLoc9;
        unsigned int LeftX;
        unsigned int Right;
        unsigned int Dir4;
        unsigned int Diff4;
        unsigned int Diff7;
        char* Diff3 = setting->name;
        unsigned int Dir3;
        unsigned int EndLoc5;
        if (Diff3 != 0) {
            handle = (this->fileHandle == 0);
            if (handle)
                this->Open(1);
            if (this->fileHandle != 0) {
                Dir2 = Setting_DataType_00c33090((int)setting->name);
                CopyMainNameFromPath((int)setting, Dir);
                CopyStringBeforeColon((FUN_00c43e00_Obj*)setting, Left);
                switch (Dir2) {
                case 6:
                    result = WritePrivateProfileStringA(Dir, Left, setting ? setting->data.s : 0, this->path) != 0;
                    break;
                case 1:
                case 3:
                    sprintf_s(EndLoc2, 0x100, "%d", setting->data.i);
                    result = WritePrivateProfileStringA(Dir, Left, EndLoc2, this->path) != 0;
                    break;
                case 5:
                    sprintf_s(EndLoc2, 0x100, "%.4f", setting->data.f);
                    result = WritePrivateProfileStringA(Dir, Left, EndLoc2, this->path) != 0;
                    break;
                case 7:
                    Dir3 = setting->data.u;
                    LeftX = (Dir3 >> 24) & 0xFF;
                    EndLoc9 = (Dir3 >> 16) & 0xFF;
                    EndLoc = (Dir3 >> 8) & 0xFF;
                    Diff = Dir3 & 0xFF;
                    sprintf_s(EndLoc2, 0x100, "%u,%u,%u", LeftX, EndLoc9, EndLoc);
                    result = WritePrivateProfileStringA(Dir, Left, EndLoc2, this->path) != 0;
                    break;
                case 8:
                    EndLoc5 = setting->data.u;
                    Diff7 = (EndLoc5 >> 24) & 0xFF;
                    Diff4 = (EndLoc5 >> 16) & 0xFF;
                    Dir4 = (EndLoc5 >> 8) & 0xFF;
                    Right = EndLoc5 & 0xFF;
                    sprintf_s(EndLoc2, 0x100, "%u,%u,%u,%u", Diff7, Diff4, Dir4, Right);
                    result = WritePrivateProfileStringA(Dir, Left, EndLoc2, this->path) != 0;
                    break;
                case 2:
                case 4:
                default:
                    sprintf_s(EndLoc2, 0x100, "%u", setting->data.u);
                    result = WritePrivateProfileStringA(Dir, Left, EndLoc2, this->path) != 0;
                    break;
                }
            }
            if (handle)
                this->Close();
        }
    }
    return result;
}

char* __cdecl NiGetViewerString_00a7d410(const char* s, unsigned char v);
char* __cdecl NiGetViewerString(const char* s, bool v);
extern const char str_010c1c40[];
extern const char str_010c1c3c[];
extern const char str_010c1c34[];
extern const char str_0109c7d8[];
struct S_00c454c0_Bool8 {
    unsigned char unk00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    unsigned char unk04;
    unsigned char unk05;
    unsigned char unk06;
    bool v;
};
struct S_00c454c0_Pad {
    int unkP00;
    int unkP04;
    int unkP08;
};
struct S_00c454c0_Low {
    int unkL00;
    int unkL04;
    int unkL08;
};
struct S_00c454c0_Byte8 {
    unsigned char unk00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    unsigned char unk04;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char v;
};
struct S_00c454c0 {
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
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    unsigned char unkac;
    unsigned char unkad;
    unsigned char unkae;
    unsigned char unkaf;
    void NiNode_GetViewerStrings(NiTPrimitiveArray<char*>* s);
    void BSRangeNode_GetViewerStrings(NiTPrimitiveArray<char*>* s);
};
// Calls FUN_00a5ea70, then writes formatted strings for unkae, unkaf, unkad, and a bool derived from unkac into the stream s.
// @fnv 0x00c454c0
// src: XBOX_PDB 0x00c454c0
void S_00c454c0::BSRangeNode_GetViewerStrings(NiTPrimitiveArray<char*>* s) {
    S_00c454c0_Pad pad;
    S_00c454c0_Low CNVal;
    NiNode_GetViewerStrings(s);
    S_00c454c0_Byte8 aT1;
    aT1.v = unkae;
    char* a = NiGetViewerString_00a7d410(str_010c1c40, aT1.v);
    s->AddFirstEmpty(a);
    S_00c454c0_Byte8 t2;
    t2.v = unkaf;
    char* b9 = NiGetViewerString_00a7d410(str_010c1c3c, t2.v);
    s->AddFirstEmpty(b9);
    S_00c454c0_Byte8 t3;
    t3.v = unkad;
    char* aC = NiGetViewerString_00a7d410(str_010c1c34, t3.v);
    s->AddFirstEmpty(aC);
    S_00c454c0_Bool8 t4;
    t4.v = unkac != 0;
    char* d_ = NiGetViewerString(str_0109c7d8, t4.v);
    s->AddFirstEmpty(d_);
}

struct P465 {
    float x;
    float y;
    float z;
    void ApplyScaled(P465* result, float s);
    P465& ComputeValue_0063c8a0(const P465& other);
};

struct R465 {
    P465 point;
    int unk0c;
    int unk10;
    float time;
    int unk18;
};

struct A465 {
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
    unsigned short unk50;
    unsigned short unk52;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    R465* unk70;
};

struct H465 {
    unsigned short n;
    unsigned short scale;
};

struct C465 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    float unk18;

    void BSWindModifier_Update(float value, A465* arg);
};

// For each of arg->unk50 entries at arg->unk70, scales DAT_01202e68 by (value - time)*unk18 and passes the result to the entry point's FUN_0063c8a0.
// @fnv 0x00c465e0
// src: XBOX_PDB 0x00c465e0
void C465::BSWindModifier_Update(float value, A465* arg)
{
    H465 half;
    R465* h;
    int w;
    P465 x;
    P465 block;

    half.scale = arg->unk50;
    if (half.scale == 0) {
    } else {
        h = arg->unk70;
        half.n = arg->unk50;
        w = half.n;
        while (w-- != 0) {
            reinterpret_cast<P465&>(DAT_01202e68).ApplyScaled(&x, (value - h->time) * unk18);
            h->point.ComputeValue_0063c8a0(x);
            ++h;
        }
    }
}


struct E70Target
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
    virtual void v24(NiTPrimitiveArray<char*>* stream);
};

struct E70LinkRef
{
    int unk00;
    int unk04;
    int unk08;
    E70Target* object;
};

// link is the only live field. The two words above it are the frame holes at -0x14 and -0x10.
struct E70FirstSlot
{
    E70LinkRef* link;
    int unk04;
    int unk08;
};

extern char str_01090d1c[];
extern char str_010c1e3c[];
extern char str_010c1e34[];
extern char str_010c1e28[];

char* __cdecl NiViewerStrings_NiGetViewerString_Title(char const* name);
unsigned int __cdecl NiGetViewerString_00a7d5e0(const char* label, const char* value);

struct E70Owner : UpdateOwner
{
    void NiNode_GetViewerStrings(NiTPrimitiveArray<char*>* stream);
    void BSMultiBoundNode_GetViewerStrings(NiTPrimitiveArray<char*>* stream);
};

// Calls FUN_00a5ea70, adds a name string and a string chosen by replacement to the stream, then calls v24 on the linked object with the stream.
// @fnv 0x00c46e70
// src: XBOX_PDB 0x00c46e70
void E70Owner::BSMultiBoundNode_GetViewerStrings(NiTPrimitiveArray<char*>* stream)
{
    NiNode_GetViewerStrings(stream);

    void* _global = g_01202e74;
    char* name5 = NiViewerStrings_NiGetViewerString_Title((const char*)_global);
    ((NiTPrimitiveArray<unsigned int>*)stream)->AddFirstEmpty(*(unsigned int*)&name5);

    unsigned int value = NiGetViewerString_00a7d5e0(str_010c1e28,
        replacement == 0 ? str_01090d1c : (replacement == 1 ? str_010c1e3c : str_010c1e34));
    ((NiTPrimitiveArray<unsigned int>*)stream)->AddFirstEmpty(value);
    {
        E70FirstSlot slot;
        slot.link = (E70LinkRef*)reference;
        if (slot.link != 0) {
            E70LinkRef* second = (E70LinkRef*)reference;
            E70Target* target2 = second->object;
            if (target2 != 0) {
                E70LinkRef* thirdB = (E70LinkRef*)reference;
                E70Target* volatile found3 = thirdB->object;
                found3->v24(stream);
            }
        }
    }
}

extern NiBound DAT_011f4288;
struct Provider47250 {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6c();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7c();
    virtual void v80(); virtual void v84(); virtual void v88(); virtual void v8c();
    virtual void v90(); virtual void v94(); virtual void v98(); virtual void v9c();
    virtual void va0(); virtual void va4(NiBound*);
};
struct Ref47250 { unsigned int m_00,m_04,m_08; Provider47250* m_0c; };
struct Node47250 {
    unsigned int m_00[8]; NiBound* m_20;
    unsigned int m_24[3]; unsigned int m_30;
    unsigned int m_34[27]; Node47250** m_a0;
    unsigned short m_a4,m_a6,m_a8,m_aa; Ref47250* m_ac;
    void FUN_005467e0();
    void BSMultiBoundNode_UpdateWorldBound();
};
struct Pad47250 { unsigned int m_00,m_04,m_08; };
// Fills m_20 via the m_ac provider if present, else copies the first child bound with nonzero m_0c and merges later such bounds via FUN_00a7f3f0.
// @fnv 0x00c47250
// src: XBOX_PDB 0x00c47250
void Node47250::BSMultiBoundNode_UpdateWorldBound() {
    const NiBound* local14;
    float local35;
    Node47250** local37;
    NiBound* local40;
    float local49;
    const NiBound* local69;
    Pad47250 local78;
    float local100;
    Node47250** local104;
    NiBound* local108;
    Pad47250 local150;
    Provider47250* local154;
    Ref47250* local158;
    Ref47250* local163;
    Node47250* local167;
    unsigned int local172;
    unsigned int local176;
    Provider47250* local260;
    bool local264 = true;
    local163 = m_ac;
    if (local163) {
        local158 = m_ac;
        local154 = local158->m_0c;
        local260 = local154;
        if (local260) { FUN_005467e0(); local260->va4(m_20); local264 = false; }
    }
    if (local264) {
        if (m_20 && (bool)(m_30 & 0x80000 ? 1 : 0)) {
            local108 = m_20; local108->m_fRadius = 0.0f;
        }
        local172 = m_a6;
        for (local176 = 0; local176 < local172; ++local176) {
            local104 = &m_a0[local176]; local167 = *local104;
            if (local167) {
                if (local167->m_20 && (local100 = local167->m_20->m_fRadius) != 0.0 ? 1 : 0) {
                    FUN_005467e0();
                    local69 = local167->m_20 ? local167->m_20 : &DAT_011f4288;
                    local40 = m_20;
                    local49 = local69->m_fRadius;
                    local40->m_kCenter = local69->m_kCenter;
                    local40->m_fRadius = local49;
                    ++local176; break;
                }
            }
        }
        for (; local176 < local172; ++local176) {
            local37 = &m_a0[local176]; local167 = *local37;
            if (local167) {
                if (local167->m_20 && (local35 = local167->m_20->m_fRadius) != 0.0 ? 1 : 0) {
                    local14 = local167->m_20 ? local167->m_20 : &DAT_011f4288;
                    m_20->NiBound_Merge(local14);
                }
            }
        }
    }
}

struct TargetClass {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v0a(); virtual void v0b();
    virtual void v0c(); virtual void v0d(); virtual void v0e(); virtual void v0f();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1a(); virtual void v1b();
    virtual void v1c(); virtual void v1d(); virtual void v1e(); virtual void v1f();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26();
    virtual bool vfn_9c(void*);
    virtual bool vfn_a0(void*);
};

struct QueryParam {
    int unk00;
    int unk04;
    int unk08;
    TargetClass* target;
};

struct DecisionTreeExt : DecisionTree {
    bool ProcessEntries_00c493a0(QueryParam* query);
};

// Checks the target against bounds unless skipBounds is set, then walks the nodes using vfn_9c/vfn_a0 on volumes and returns whether the end node's type is 2.
// @fnv 0x00c493a0
// src: GUESS 0x00c493a0 (confidence: low)
bool DecisionTreeExt::ProcessEntries_00c493a0(QueryParam* query) {
    VolumeRecord* vol = 0;
    bool result5 = true;
    int iNodeIndex;
    bool branchTaken;
    if (!this->skipBounds) {
        TargetClass* volatile target = query->target;
        result5 = target->vfn_9c((VolumeRecord*)&this->unk30);
    }
    if (result5) {
        if (this->nodeCount > 0) {
            iNodeIndex = this->rootIndex;
            while (this->nodes[iNodeIndex].type != 2 && this->nodes[iNodeIndex].type != 3) {
                branchTaken = false;
                switch (this->nodes[iNodeIndex].type) {
                case 7: {
                    DecisionNode* pNext = &this->nodes[iNodeIndex + 1];
                    vol = &this->volumes[pNext->type];
                    TargetClass* volatile target = query->target;
                    branchTaken = target->vfn_9c(vol);
                    break;
                }
                case 8: {
                    DecisionNode* pNext = &this->nodes[iNodeIndex + 1];
                    vol = &this->volumes[pNext->type];
                    TargetClass* volatile target = query->target;
                    branchTaken = !target->vfn_a0(vol);
                    break;
                }
                }
                iNodeIndex = branchTaken ? this->nodes[iNodeIndex].trueIndex : this->nodes[iNodeIndex].falseIndex;
            }
            result5 = (this->nodes[iNodeIndex].type == 2);
        }
    }
    return result5;
}

struct GraphRecord { int kind, yes, no; };
struct RecordArray {
    int unk00;
    GraphRecord* data;
    int unk08;
    int capacity;
    void FUN_00c4a1e0(int, bool);
};
struct GraphHeap {
    void* Allocate(unsigned int, unsigned int);
    void Deallocate(void*);
};
struct GraphMemory { GraphHeap* FUN_00aa42e0(); };
extern GraphMemory _g_memoryManager;
extern unsigned int DAT_010a2720;
extern char DAT_010c1e44[];
void __cdecl Warning_005b5e40(const char*);
void* __cdecl fnv_zlib_memset(void*, int, unsigned int);
struct ControlGraph {
    bool ready;
    int unk04, unk08, unk0c, unk10;
    RecordArray records;
    int unk24;
    int count;
    int first;
    void BSCompoundFrustum_PrethreadOpList();
};

// If not ready, assigns yes/no target indices to records by kind, shortens kind 7/8 links past intermediate records, then sets ready.
// @fnv 0x00c49850
// src: COMMUNITY 0x00c49850
void ControlGraph::BSCompoundFrustum_PrethreadOpList() {
    if (!ready && count > 0) {
        GraphRecord* local60;
        GraphRecord* recordE4;
        GraphRecord* recordD5;
        GraphRecord* recordCTmp;
        GraphRecord* recordB3;
        GraphRecord* local57;
        int grow8;
        int capacity;
        int local55;
        int local53;
        int kd;
        int j8;
        int i22;
        bool found3;
        GraphHeap* heapA;
        int* local26;
        int depth5;
        int* endsX;
        int* groups_;
        int endIndex9;
        int stackCapacity7;
        int local19;
        int local8;
        endIndex9 = count + 1;
        local19 = count + 2;
        capacity = records.capacity;
        if (count + 3 >= capacity) {
            grow8 = records.capacity;
            records.FUN_00c4a1e0(grow8 + 10, true);
        }
        records.data[count].kind = 1;
        records.data[count + 1].kind = 2;
        records.data[count + 2].kind = 3;
        stackCapacity7 = count / 2;
        heapA = _g_memoryManager.FUN_00aa42e0();
        local26 = (int*)heapA->Allocate(stackCapacity7 * sizeof(int), DAT_010a2720);
        local26[0] = 0;
        depth5 = 0;
        local8 = 1;
        endsX = (int*)heapA->Allocate(stackCapacity7 * sizeof(int), DAT_010a2720);
        groups_ = (int*)heapA->Allocate(stackCapacity7 * sizeof(int), DAT_010a2720);
        for (i22 = 0; i22 < count + 1; ++i22) {
            switch (records.data[i22].kind) {
            case 1:
                endsX[0] = i22;
                if (depth5 != 0) { count = 0; return; }
                break;
            case 4:
            case 5:
                ++depth5;
                local26[depth5] = local8;
                ++local8;
                break;
            case 6:
                endsX[local26[depth5]] = i22;
                --depth5;
                break;
            case 7:
            case 8:
                ++i22;
                break;
            }
        }
        fnv_zlib_memset(local26, 0, stackCapacity7 * sizeof(int));
        local26[0] = 0;
        groups_[0] = 0;
        depth5 = 1;
        local8 = 1;
        found3 = false;
        for (j8 = 0; j8 < count + 1; ++j8) {
            switch (records.data[j8].kind) {
            case 1:
                records.data[j8].yes = endIndex9;
                records.data[j8].no = local19;
                break;
            case 6:
                --depth5;
                switch (local26[depth5 - 1]) {
                case 0:
                    records.data[j8].yes = j8 + 1;
                    records.data[j8].no = j8 + 1;
                    break;
                case 5:
                    records.data[j8].yes = endsX[groups_[depth5 - 1]];
                    records.data[j8].no = j8 + 1;
                    break;
                case 4:
                    records.data[j8].yes = j8 + 1;
                    records.data[j8].no = endsX[groups_[depth5 - 1]];
                    break;
                }
                break;
            case 7:
            case 8:
                if (!found3) { first = j8; found3 = true; }
                switch (local26[depth5 - 1]) {
                case 0:
                    records.data[j8].yes = count;
                    records.data[j8].no = count;
                    break;
                case 5:
                    records.data[j8].yes = endsX[groups_[depth5 - 1]];
                    records.data[j8].no = j8 + 2;
                    break;
                case 4:
                    records.data[j8].yes = j8 + 2;
                    records.data[j8].no = endsX[groups_[depth5 - 1]];
                    break;
                }
                ++j8;
                break;
            case 4:
            case 5:
                local26[depth5] = records.data[j8].kind;
                groups_[depth5] = local8;
                ++local8;
                ++depth5;
                records.data[j8].yes = j8 + 1;
                records.data[j8].no = j8 + 1;
                break;
            }
        }
        if (!found3) {
            Warning_005b5e40(DAT_010c1e44);
            first = endIndex9;
            ready = true;
            return;
        }
        for (kd = first; kd < count; ++kd) {
            switch (records.data[kd].kind) {
            case 7:
            case 8:
                while (true) {
                    local57 = &records.data[kd];
                    local53 = records.data[local57->yes].kind;
                    if (local53 == 7 || local53 == 8 || local53 == 2 || local53 == 3) break;
                    else {
                        recordB3 = &records.data[kd];
                        recordCTmp = &records.data[recordB3->yes];
                        records.data[kd].yes = recordCTmp->yes;
                    }
                }
                while (true) {
                    recordD5 = &records.data[kd];
                    local55 = records.data[recordD5->no].kind;
                    if (local55 == 7 || local55 == 8 || local55 == 2 || local55 == 3) break;
                    else {
                        recordE4 = &records.data[kd];
                        local60 = &records.data[recordE4->no];
                        records.data[kd].no = local60->no;
                    }
                }
                ++kd;
                break;
            }
        }
        heapA->Deallocate(local26);
        heapA->Deallocate(endsX);
        heapA->Deallocate(groups_);
    }
    ready = true;
}

extern int DAT_010c1e88;

struct S00c49fe0_Vt
{
    virtual void v0();
    virtual void* v1(unsigned int n);
};

struct FUN_00c49fe0_Cls
{
    void* vtbl;
    void* data;
    int unk08;
    int unk0C;

    void BSSimpleArray_NiFrustumPlanes_1024_ConstructItems(void* data, int flag);
    FUN_00c49fe0_Cls();
};

// Sets vtbl to DAT_010c1e88 and zeroes data, unk08 and unk0C; the size is a constant 0, so the allocation path is never reached.
// @fnv 0x00c49fe0
FUN_00c49fe0_Cls::FUN_00c49fe0_Cls()
{
    int u1;
    int u2;
    int u3;
    int u4;
    int u5;
    vtbl = (void*)&DAT_010c1e88;
    {
    unsigned int nSize = 0;
    data = 0;
    unk08 = 0;
    unk0C = 0;
    if (nSize < 0)
        nSize = 0;
    if (nSize > 0) {
        data = ((S00c49fe0_Vt*)this)->v1(nSize);
        unk0C = nSize;
    }
    }
    if ((0, (unsigned)0) > 0u) {
        BSSimpleArray_NiFrustumPlanes_1024_ConstructItems(data, 0);
        unk08 = 0;
    }}

struct c4a790_Plane {
    unsigned int normalX;
    unsigned int normalY;
    unsigned int normalZ;
    unsigned int constant;
};

struct c4a790_Obj {
    c4a790_Plane planes[6];
    unsigned int mask;
};

struct c4a790_Side {
    int unusedSide;
    int value;
};

struct c4a790_Owner {
    bool BSCompoundFrustum_TestNotContained(CallerObj_b3918* target, c4a790_Obj* object);
};

// Clears mask bit i while target->ClassifySphereAgainstPlane(plane i) returns 1; returns true if a masked plane returned another value, else false.
// @fnv 0x00c4a790
// src: COMMUNITY 0x00c4a790
bool c4a790_Owner::BSCompoundFrustum_TestNotContained(CallerObj_b3918* target, c4a790_Obj* apPlanes)
{
    int i;
    c4a790_Side result;

    if (!(apPlanes->mask != 0 ? true : false)) {
        return false;
    } else {
        for (i = 0; i < 6; i++) {
            if ((apPlanes->mask & (1u << i)) != 0 ? true : false) {
                result.value = target->ClassifySphereAgainstPlane(&apPlanes->planes[i]);
                if (result.value != 1) {
                    break;
                } else if (result.value == 1) {
                    apPlanes->mask = apPlanes->mask & ~(1u << i);
                }
            }
        }
        if (i == 6)
            return false;
    }
    return true;
}

extern int DAT_010c1e88;

// Sets the vtable pointer to DAT_010c1e88 and calls ReleaseBuffer(1) on the object.
// @fnv 0x00c4a840
// src: GUESS 0x00c4a840 (confidence: low)
void FUN_00c4a960_Class::UpdateFields_00c4a840() {
    int x;
    *(int**)this = &DAT_010c1e88;
    ((FUN_00c4a9c0_class*)this)->ReleaseBuffer(1);
}

struct VertexDE80 {
    float m_00, m_04, m_08;
};
// FUN_00c4de80 indexes a 12-byte vertex array through +0x04; shared Data stores a skill level there.
struct TriangleVertexStorage {
    int m_00;
    VertexDE80* m_04;
};
struct ObjectDE80 {
    TriangleVertexStorage* m_00;
    bool BSPolygon2D_IsPointInsideTri(float x, float y, int A, int B, int C);
};

// Checks whether point (x, y) lies inside the triangle formed by vertices A, B, C using cross-product sign tests.
// @fnv 0x00c4de80
// src: COMMUNITY 0x00c4de80
bool ObjectDE80::BSPolygon2D_IsPointInsideTri(float x, float y, int A, int B, int C)
{
    float p, h, a, i, s, f, eb, cf, q, b, ba, k, l, c, e;
    VertexDE80& j = m_00->m_04[C];
    eb = (double)j.m_00 - m_00->m_04[B].m_00;
    {
        VertexDE80* j;
        a = (j = &m_00->m_04[C])->m_04 - m_00->m_04[B].m_04;
        {
            VertexDE80* j;
            cf = (double)(j = &m_00->m_04[A])->m_00 - m_00->m_04[C].m_00;
            {
                VertexDE80* j;
                e = (j = &m_00->m_04[A])->m_04 - m_00->m_04[C].m_04;
                {
                    VertexDE80* j;
                    h = (double)(j = &m_00->m_04[B])->m_00 - m_00->m_04[A].m_00;
                    {
                        VertexDE80* j;
                        k = (j = &m_00->m_04[B])->m_04 - m_00->m_04[A].m_04;
                        p = (double)x - m_00->m_04[A].m_00;
                        f = y - m_00->m_04[A].m_04;
                        ba = (double)x - m_00->m_04[B].m_00;
                        b = y - m_00->m_04[B].m_04;
                        q = (double)x - m_00->m_04[C].m_00;
                        c = y - m_00->m_04[C].m_04;
                        l = eb * b - a * ba;
                        i = h * f - k * p;
                        s = cf * c - e * q;
                        return l <= 0.0 && s <= 0.0 && i <= 0.0;
                    }
                }
            }
        }
    }
}

class FUN_00c511f0_cls {
public:
    virtual void v0();
    virtual void v1();
    virtual void* v2();
};

extern char g_sentinel_0120436c;

bool BSParticleSystemManager_CheckEmitterRecurse(FUN_00c511f0_cls* a, FUN_00c511f0_cls* b);

// If obj is non-null and obj->v2() equals &g_sentinel_0120436c, returns FUN_00c50f90(obj, obj); otherwise returns false.
// @fnv 0x00c511f0
// src: XBOX_PDB 0x00c511f0
bool __cdecl BSParticleSystemManager_IsValidMasterParticleSystem(FUN_00c511f0_cls* obj)
{
    bool result2 = false;
    FUN_00c511f0_cls* tmp;
    {
        bool gate;
        if (obj == 0) {
            gate = false;
        } else {
            gate = obj->v2() == (void*)&g_sentinel_0120436c;
        }
        if (gate) {
            tmp = obj;
            result2 = BSParticleSystemManager_CheckEmitterRecurse(obj, tmp);
        }
    }
    return result2;
}

// 0x00c52020  1072 bytes  /MT /Od /Oy- /GS /EHsc /Gy   -- byte-identical reconstruction
// thiscall (ret 0x10): (float fov, unsigned char flag, C52020Obj* obj, unsigned char arg4)
// called from 0xc51d67 as FUN_00c52020(*pSetting, 1, 0, 0).
//
// Frame 0xcc + push esi.  Named band -0x04..-0x88 (bucket-sorted: descending name-hash
// bucket, ties by reverse declaration order), expression temps -0x8c..-0xcc in code order.
// Slot roles are annotated on the declarations below; aFlag is the 0x18-byte hole at
// -0x6c that nothing ever reads, and the two setting divides use a two-member record
// read because only a "computed" right operand makes MSVC9 /Od emit
// `mov edx,[p] / fld [edx] / fdivr [ebp+8]` instead of the mirrored
// `fld [ebp+8] / mov edx,[p] / fdiv [edx]`.
extern "C" char DAT_01203144[];
extern "C" char DAT_01203150[];
extern "C" float DAT_01202800;
extern "C" double DAT_01023128;
extern "C" double DAT_01011588;
struct C52020Dev;
extern "C" C52020Dev* DAT_011f4748;

double tan(double);



struct C52020Res {
    char pad0[8];
    unsigned int m_08;
    unsigned int m_0c;
};

struct C52020Obj;

struct C52020Dev {
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual C52020Res* vfn_b0(int);
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual C52020Dev* vfn_c8();
    virtual C52020Dev* vfn_cc();
    unsigned int FUN_004dee70();
    unsigned int FUN_004dee10();
};

struct C52020Setting { float m_fReserved; float m_fValue; };

struct C52020Filler {
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
};

struct C52020Obj {
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
    virtual float vfn_100();
    char pad0[0xa8];
    C52020Obj* m_ac;
    char pad1[8];
    unsigned char m_b8;
    char pad2[3];
    float m_bc;
    char pad3[0x3c];
    float m_fc;
    float m_100;
    float m_104;
    float m_108;
    float m_10c;
    float m_110;
    void FUN_00a6faf0(NiFrustum* apFrustum);
    void Update(const NiUpdateData& kData);
    void SceneGraph_SetCameraFOV(float m_fFirstFloat, unsigned char ucFlag, C52020Obj* pObj, unsigned char ucArg4);
};

// Builds a NiFrustum from m_fFirstFloat and a width/height ratio (from DAT_011f4748 when set), applies it to the target (pObj or m_ac) and calls Update.
// @fnv 0x00c52020
// src: COMMUNITY 0x00c52020
void C52020Obj::SceneGraph_SetCameraFOV(float afFov, unsigned char ucFlag, C52020Obj* apTarget, unsigned char ucArg4)
{
    C52020Obj* aTarget;      // pTarget          [ebp-0x08]
    float aStart;
    float aState;            // fAspect          [ebp-0x0c]
    C52020Dev* aValue;       // pDev             [ebp-0x10]
    float aSize;             // fScale           [ebp-0x30]
    float aLen;
    float aHdr;              // fHalfFov         [ebp-0x44]
    float* aPtr;             // pSetting         [ebp-0x48]
    float aKey;              // fRatio           [ebp-0x4c]
    float* aTmp;             // pSet             [ebp-0x50]
    C52020Filler aFlag;      // 0x18-byte unreferenced local -> frame hole [ebp-0x6c]
    float aPath;             // fLOD             [ebp-0x54]
    C52020Res* aNode;        // pRes             [ebp-0x70]
    unsigned int aObj;       // uiHeight         [ebp-0x74]
    float aHandle;           // fRatio2          [ebp-0x84]
    float* aPData;           // pSetting2        [ebp-0x80]
    unsigned int aHit;       // uiWidth          [ebp-0x7c]
    C52020Res* aRef;         // pRes2            [ebp-0x78]

    aTarget = apTarget;
    if (!aTarget)
        aTarget = this->m_ac;

    if (!apTarget)
    {
        if (!ucFlag && this->m_bc == afFov)
        {
            if (ucArg4)
            {
                aPtr = DAT_01203150 ? (float*)&DAT_01203150[4]
                                    : (DAT_01202800 = 0.0f, (float*)&DAT_01202800);
                aKey = afFov / (((C52020Setting*)((char*)aPtr - 4))->m_fReserved,
                               ((C52020Setting*)((char*)aPtr - 4))->m_fValue);
                aTarget->m_110 = aKey;
            }
            return;
        }
        this->m_bc = afFov;
    }

    aHdr = afFov * DAT_01023128 * DAT_01011588;
    NiFrustum aTile;
    aTile.Init(false);
    aTile.farPlane = vfn_100();
    aTmp = DAT_01203144 ? (float*)&DAT_01203144[4]
                        : (DAT_01202800 = 0.0f, (float*)&DAT_01202800);
    // the near-plane store inside the divisor is the original's assignment-expression
    // form: it is what produces `fld [near]/fdivr` (a plain two-statement version
    // emits `fld far / fdiv [near]`).
    aPath = aTile.farPlane / (aTile.nearPlane = *aTmp);
    aTarget->m_fc = aPath;

    aValue = DAT_011f4748;
    if (aValue)
    {
        aStart = (float)aValue->FUN_004dee70() * (aTarget->m_108 - aTarget->m_10c);
        aLen = (float)aValue->FUN_004dee10() * (aTarget->m_104 - aTarget->m_100);
    }
    else
    {
        aStart = aTarget->m_108 - aTarget->m_10c;
        aLen = aTarget->m_104 - aTarget->m_100;
    }
    if (aValue)
    {
        if (aValue->vfn_cc() && aValue->vfn_cc() != aValue->vfn_c8())
        {
            aNode = aValue->vfn_cc()->vfn_b0(0);
            aObj = aNode->m_0c;
            aStart = (float)aObj;
            aRef = aValue->vfn_cc()->vfn_b0(0);
            aHit = aRef->m_08;
            aLen = (float)aHit;
        }
    }
    aState = aStart / aLen;
    if (this->m_b8 && !apTarget)
        aSize = 1.0f;
    else
        aSize = 0.75 / (aStart / aLen);

    aTile.left = -(float)tan(aHdr) * aSize;
    aTile.right = (float)tan(aHdr) * aSize;
    aTile.bottom = -(float)tan(aHdr) * aState * aSize;
    aTile.top = (float)tan(aHdr) * aState * aSize;

    aTarget->FUN_00a6faf0(&aTile);

    // The original initializes the stream record in place without a constructor call.
    union {
        float time;
        struct { unsigned int word0, word1, word2; } storage;
    } aOut;
    aOut.time = 0.0f;
    reinterpret_cast<unsigned char*>(&aOut)[offsetof(NiUpdateData, pad1)] = false;
    reinterpret_cast<unsigned char*>(&aOut)[offsetof(NiUpdateData, pad2)] = false;
    reinterpret_cast<unsigned char*>(&aOut)[offsetof(NiUpdateData, pad3)] = false;
    reinterpret_cast<unsigned char*>(&aOut)[offsetof(NiUpdateData, pad4)] = false;
    reinterpret_cast<unsigned char*>(&aOut)[offsetof(NiUpdateData, pad5)] = false;
    aTarget->Update(*reinterpret_cast<const NiUpdateData*>(&aOut));

    if (ucArg4)
    {
        aPData = DAT_01203150 ? (float*)&DAT_01203150[4]
                              : (DAT_01202800 = 0.0f, (float*)&DAT_01202800);
        aHandle = afFov / (((C52020Setting*)((char*)aPData - 4))->m_fReserved,
                          ((C52020Setting*)((char*)aPData - 4))->m_fValue);
        aTarget->m_110 = aHandle;
    }
}

extern "C" void* g_012031e8;
extern unsigned int DAT_010c1040;
extern unsigned int DAT_010c2bf8;

struct W5Sub {
    int pad;
    unsigned int __thiscall GetViewerString_00a59af0(void* desc);
};

struct W5Big {
    int u00;
    int u04;
    int u08;
    int u0c;
    int u10;
    int u14;
    int u18;
    int u1c;
    int u20;
    void* p;
};

struct W5Self {
    int f00;
    int f04;
    int f08;
    W5Sub subC;
    int f10;
    int f14;
    W5Sub sub18;
    void __thiscall FUN_00a7b580(NiTPrimitiveArray<unsigned int>* a1);
    void __thiscall BSBound_GetViewerStrings(NiTPrimitiveArray<unsigned int>* a1);
};

// Calls FUN_00a7b580(a1), then a1->FUN_0096a610 with FUN_00a7d330(g_012031e8), then with the results of FUN_00a59af0 on subC and sub18.
// @fnv 0x00c550f0
// src: XBOX_PDB 0x00c550f0
void W5Self::BSBound_GetViewerStrings(NiTPrimitiveArray<unsigned int>* a1) {
    FUN_00a7b580(a1);
    unsigned int r1;
    unsigned int p;
    unsigned int r2;
    {
        W5Big big;
        big.p = g_012031e8;
        p = (unsigned int)NiViewerStrings_NiGetViewerString_Title(big.p);
        a1->AddFirstEmpty(p);
        r1 = subC.GetViewerString_00a59af0(&DAT_010c1040);
        a1->AddFirstEmpty(r1);
        r2 = sub18.GetViewerString_00a59af0(&DAT_010c2bf8);
        a1->AddFirstEmpty(r2);
    }
}

struct S_00c5b140_Node {
    int unk00;
    int unk04;
    void* unk08;
};

struct S_00c5b140_Allocator {
    S_00c5b140_Node* __thiscall NiGeometry_AddProperty();
};

struct S_00c5b140_List {
    int unk00;
    int unk04;
    S_00c5b140_Allocator unk08;
    void __thiscall NiTListBase_NiTPointerAllocator_unsigned_int_BSFaceGenKeyframe_AddNodeTail(S_00c5b140_Node* node);
};

struct S_00c5b140 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    S_00c5b140_List unk14;
    void __thiscall BSPortalGraph_AddPortal(void* value);
};

// If value is non-null, gets a node from unk14.unk08.FUN_0043a010, stores value in it, and passes the node to unk14.FUN_00559a70.
// @fnv 0x00c5b140
// src: COMMUNITY 0x00c5b140
void S_00c5b140::BSPortalGraph_AddPortal(void* value)
{
    if (value != 0) {
        // The original frame reserves seven dead slots between the two live
        // locals (reserved-but-untouched region); kept as unused scalars.
        int item; int entry; int data; int pElem; int val; int keep; int next;
        S_00c5b140_List* pool = &this->unk14;
        S_00c5b140_Node* pNode = pool->unk08.NiGeometry_AddProperty();
        pNode->unk08 = value;
        pool->NiTListBase_NiTPointerAllocator_unsigned_int_BSFaceGenKeyframe_AddNodeTail(pNode);
    }
}

extern void* DAT_01203328;

typedef NiTListItem<NiPointer<NiProperty> > SpawnNode;
typedef NiTPointerList<NiPointer<NiProperty> > SpawnList;

struct SpawnedObject {
    unsigned int unk00;
    unsigned int unk04;
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
    SpawnList m_50;
    SpawnList m_5c;
    void BSPortalGraph_AttachQAlwaysRenderChild(void* value);
    void BSPortalGraph_DetachQAlwaysRenderChild(void* value);
    void BSPortalGraph_ProcessQueue();
};

struct LoopPadA { unsigned int a; unsigned int b; unsigned int c; unsigned int d; };
struct LoopPadB { unsigned int a; unsigned int b; unsigned int c; unsigned int d; unsigned int e; unsigned int f; unsigned int g; };

// Under a critical section, calls FUN_00c5b5f0 on each element of m_50 and FUN_00c5b740 on each of m_5c, removing all entries from each list afterward.
// @fnv 0x00c5b8d0
// src: COMMUNITY 0x00c5b8d0
void SpawnedObject::BSPortalGraph_ProcessQueue()
{
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_01203328);
    void* value;
    SpawnNode* node;
    {
        SpawnNode* head = m_50.m_pkHead;
        node = head;
        value = 0;
        while (node != 0) {
            NiPointer<NiProperty>* ref = &node->m_element;
            LoopPadA tmp;
            node = node->m_pkNext;
            value = ref->m_pObject;
            if (value != 0) {
                BSPortalGraph_AttachQAlwaysRenderChild(value);
            }
        }
    }
    m_50.RemoveAll();
    {
        SpawnNode* head = m_5c.m_pkHead;
        node = head;
        value = 0;
        while (node != 0) {
            NiPointer<NiProperty>* ref = &node->m_element;
            LoopPadB tmp;
            node = node->m_pkNext;
            value = ref->m_pObject;
            if (value != 0) {
                BSPortalGraph_DetachQAlwaysRenderChild(value);
            }
        }
    }
    m_5c.RemoveAll();
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_01203328);
}

unsigned int __cdecl NiGetViewerString_00a7d5a0(const char* name, int value);
unsigned int __cdecl NiGetViewerString_00a7d490(const char* name, unsigned int value);

struct S00c5cd80_Scratch {
    int f00;
    int f04;
    int f08;
    int f0C;
    int f10;
    int f14;
    int f18;
    int f1C;
    int f20;
    int f24;
    int f28;
    int f2C;
};

struct S00c5cd80_Owner {
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
    int m_5c;
    unsigned short m_60;
    void FUN_00c1ce70(NiTPrimitiveArray<unsigned int>* a);
    void BSPSysMultiTargetEmitterCtlr_GetViewerStrings(NiTPrimitiveArray<unsigned int>* arg);
};

// Calls FUN_00c1ce70, then appends to arg a global-derived entry, one for "Master Particle System" with m_5c, and one for "Max Full Emitters" with m_60.
// @fnv 0x00c5cd80
// src: XBOX_PDB 0x00c5cd80
void S00c5cd80_Owner::BSPSysMultiTargetEmitterCtlr_GetViewerStrings(NiTPrimitiveArray<unsigned int>* apArray) {
    S00c5cd80_Scratch j;
    FUN_00c1ce70(apArray);
    int global = g_01203340;
    unsigned int full = (unsigned int)NiViewerStrings_NiGetViewerString_Title((void*)global);
    apArray->AddFirstEmpty(full);
    unsigned int named = NiGetViewerString_00a7d5a0("Master Particle System", m_5c);
    apArray->AddFirstEmpty(named);
    unsigned int slot = NiGetViewerString_00a7d490("Max Full Emitters", m_60);
    apArray->AddFirstEmpty(slot);
}

struct Node_00c5e080 {
    virtual void vfunc00();
    virtual void DeleteThis();
    volatile long m_uiRefCount; // offset 4
    char pad08[0x28];           // 0x08..0x2f
    unsigned int m_uiValue1;     // 0x30
};

struct MapHelper_00c5e080 {
    void FUN_00c5bfb0(Node_00c5e080** ppObj, int* ppCur);
};

struct Limits_00c5e080 {
    unsigned short maxCount; // offset 0 -> [ebp - 0x2c]
    unsigned short curCount; // offset 2 -> [ebp - 0x2a]
};

// Scans entries from cursor unkc0, removing those whose object has refcount 1 or m_uiValue1 bit 0 set, and recounts kept entries in unkb8, capped at unkba.
// @fnv 0x00c5e080
// src: XBOX_PDB 0x00c5e080
void S_00c5e3d0::BSMasterParticleSystem_ClearUnreferencedEmitters()
{
    int p;
    unsigned int v;
    Node_00c5e080* a;
    Node_00c5e080* n;
    int s;
    Node_00c5e080** f;
    int Flag;
    Node_00c5e080* Tmp;
    int BB;
    int b;
    Limits_00c5e080 Mgr;

    this->unkb8 = 0;
    if (!this->unkc0) {
        s = this->unkac;
        this->unkc0 = s;
    }
    p = 0;
    v = this->unkb4;
    while (this->unkc0 && v-- > 0) {
        f = (Node_00c5e080**)((char*)this->unkc0 + 8);
        a = *f;
        Flag = a->m_uiRefCount;
        if (Flag == 1 || (bool)(a->m_uiValue1 & 1 ? 1 : 0)) {
            ((MapHelper_00c5e080*)&this->unkac)->FUN_00c5bfb0(&n, &this->unkc0);
            if (n) {
                Tmp = n;
                if (!InterlockedDecrement(&Tmp->m_uiRefCount)) {
                    Tmp->DeleteThis();
                }
            }
        } else {
            if (this->unkb8 == this->unkba) {
                p = this->unkc0;
            }
            this->unkb8++;
            BB = this->unkc0;
            this->unkc0 = BB ? *(int*)BB : 0;
        }
        if (!this->unkc0) {
            b = this->unkac;
            this->unkc0 = b;
        }
    }
    if (p) {
        this->unkc0 = p;
    }
    Mgr.maxCount = this->unkba;
    Mgr.curCount = this->unkb8;
    this->unkb8 = (Mgr.curCount < Mgr.maxCount) ? Mgr.curCount : Mgr.maxCount;
    if (!this->unkb8) {
        this->unkc0 = 0;
    }
}

struct C48Entry { int type; int a; int b; };

struct C48Rec {
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
    int m_60;
};

struct C48Sub {
    int m_04;
    C48Rec* m_08;
    int m_0c;
    int m_10;
    void FUN_00c4a070(int, bool);
};

struct C48Arr {
    int m_14;
    C48Entry* m_18;
    int m_1c;
    int m_20;
    void FUN_00c4a1e0(int, bool);
};

struct C48Obj {
    int GetPackedZeroFlags();
    bool BSPortal_WithinFrustumFullTest(C48Rec* p);
};

struct C48Owner {
    int unk00;
    C48Sub m_04;
    C48Arr m_14;
    int m_24;
    int m_28;
    void CompactEntries();
    void BSCompoundFrustum_BuildForPortal(C48Owner* src, C48Obj* obj);
};

// Copies entry data from src into this owner, compacting the entry array and updating the record table.
// @fnv 0x00c48db0
// src: COMMUNITY 0x00c48db0
void C48Owner::BSCompoundFrustum_BuildForPortal(C48Owner* src, C48Obj* obj)
{
    int kRemovedZ = 0;
    int TKz3 = 0;
    int BN = src->m_28;
    int PIn;
    bool ok;
    C48Entry* nXT;
    C48Rec* rec;
    C48Entry* FCur;
    C48Entry* unXT;
    C48Rec* rec2;
    C48Entry* aNxT;
    C48Entry* nxT;
    C48Rec* aDst4;
    C48Entry* sCur;

    m_14.FUN_00c4a1e0(BN, true);
    m_04.FUN_00c4a070(src->m_24, true);

    for (PIn = 0; PIn < BN; PIn++) {
        ok = true;
        switch (src->m_14.m_18[PIn].type) {
        case 7:
        case 8:
            {
                nXT = &src->m_14.m_18[PIn + 1];
                rec = &src->m_04.m_08[nXT->type];
                ok = obj->BSPortal_WithinFrustumFullTest(rec);
                FCur = &src->m_14.m_18[PIn];
                m_14.m_18[PIn - kRemovedZ].type = FCur->type;
                m_28++;
                m_14.m_18[PIn - kRemovedZ + 1].type = m_24;
                m_28++;
                unXT = &src->m_14.m_18[PIn + 1];
                rec2 = &src->m_04.m_08[unXT->type];
                aNxT = &src->m_14.m_18[PIn + 1];
                m_04.m_08[aNxT->type - TKz3] = *rec2;
                m_24++;
                if (ok && obj->GetPackedZeroFlags() == 0xf) {
                    nxT = &src->m_14.m_18[PIn + 1];
                    aDst4 = &m_04.m_08[nxT->type - TKz3];
                    aDst4->m_60 = 0;
                }
                PIn++;
            }
            break;
        default:
            sCur = &src->m_14.m_18[PIn];
            m_14.m_18[PIn - kRemovedZ].type = sCur->type;
            m_28++;
            break;
        }
    }
    m_28 = BN - kRemovedZ;
    CompactEntries();
}

struct S_Pt {
    float x;
    float y;
    float z;
};

struct S_Poly {
    int unk00;
    S_Pt* pts;

};

class S_cls {
public:
    S_Poly* m_pPoly;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int m_uiItemCount;
    float BSPolygon2D_Area();
};
// @fnv 0x00c4d9d0
// src: COMMUNITY 0x00c4d9d0
float S_cls::BSPolygon2D_Area()
{
    int i;
    float area8 = 0.0f;
    for (i = 0; i < m_uiItemCount; i++) {
        int j3 = (i + 1) % m_uiItemCount;
        S_Pt* a9 = &m_pPoly->pts[i];
        area8 += a9->x * m_pPoly->pts[j3].y;
        S_Pt* b = &m_pPoly->pts[i]; area8 -= (double)b->y * m_pPoly->pts[j3].x;
    }
    return area8 * 0.5;
}

struct FUN_00c31720_base
{
    void Init();
};

extern char g_unkVtable[];

// Calls Init on the FUN_00c31720_base part, sets p to g_unkVtable, f to 1.0f and c to 4000.
// @fnv 0x00c465a0
FUN_00c465a0::FUN_00c465a0()
{
    reinterpret_cast<FUN_00c31720_base*>(this)->Init();
    p = g_unkVtable;
    *(float*)&f = 1.0f;
    c = 4000;
}

struct NiPoint3;
struct NiPoint2;
struct FUN_00c5cf30 : NiTriShape {
    FUN_00c5cf30(unsigned short usVertices, NiPoint3* pkVertex, NiPoint3* pkNormal,
                      NiColorA* pkColor, NiPoint2* pkTexture, unsigned short usNumTextureSets,
                      NiGeometryDataFlags eNBTMethod, unsigned short usTriangles,
                      unsigned short* pusTriList, int aiLeft, int aiTop, int aiRight,
                      int aiBottom);
};
// Constructs the NiTriShape base, sets its vtable, and stores aiLeft, aiTop, aiRight and aiBottom at offsets 0xc4 through 0xd0.
// @fnv 0x00c5cf30
FUN_00c5cf30::FUN_00c5cf30(unsigned short usVertices, NiPoint3* pkVertex,
    NiPoint3* pkNormal, NiColorA* pkColor, NiPoint2* pkTexture,
    unsigned short usNumTextureSets, NiGeometryDataFlags eNBTMethod,
    unsigned short usTriangles, unsigned short* pusTriList, int aiLeft, int aiTop,
    int aiRight, int aiBottom)
    : NiTriShape(usVertices, pkVertex, pkNormal, static_cast<void*>(pkColor), pkTexture, usNumTextureSets,
                 eNBTMethod, usTriangles, pusTriList)
{
    *(int*)((char*)this + 0xc4) = aiLeft;
    *(int*)((char*)this + 0xc8) = aiTop;
    *(int*)((char*)this + 0xcc) = aiRight;
    *(int*)((char*)this + 0xd0) = aiBottom;
}

namespace fnv_00c4b500 {
#include <windows.h>

struct Node;
struct NodeV { void* v0; void* v1; void* v2; Node* (__thiscall *GetNode)(Node*); };
struct Node {
    NodeV* vt;
    char unk04[0x2C];
    unsigned int flags;
    char unk34[0x6C];
    Node** children;
    char unkA4[2];
    unsigned short count;
};
// Sets flag bits 2 and 4 and clears 0x10 on n, then recurses on each child of the node returned by its GetNode virtual.
// @fnv 0x00c4b500
// src: XBOX_PDB 0x00c4b500
void BSUtilities_ProcessSelectiveUpdate(Node* apNode)
{
    if (apNode) {
                if (1) apNode->flags |= 2; else apNode->flags &= ~(unsigned)(apNode, 2);
                if (1) apNode->flags |= 4; else apNode->flags &= ~(unsigned)(apNode, 4);
                if (0) apNode->flags |= 0x10; else apNode->flags &= ~(unsigned)(apNode, 0x10);
        Node* g = apNode->vt->GetNode(apNode);
        if (g) {
            for (unsigned i = 0; i < g->count; i++) {
                Node** p = &g->children[i];
                Node* pChildNode = *p;
                BSUtilities_ProcessSelectiveUpdate(pChildNode);
            }
        }
    }
}
}  // namespace fnv_00c4b500

// for each of one listed worker, release its semaphore and bump its counter.
extern "C" __declspec(dllimport) int __stdcall ReleaseSemaphore(void* hSemaphore, long lReleaseCount, long* lpPreviousCount);

struct WorkerItemC44 {
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
    SemaphoreC44 m_kCompletionSemaphore;
};

// Releases the completion semaphore of the worker item at index 0 and increments its count.
// @fnv 0x00c44cd0
// src: COMMUNITY 0x00c44cd0
void FUN_00c44cd0_class::BSParallelTaskManager_StartThreads() {
    for (unsigned int i = 0; i < 1; i++) {
        WorkerItemC44* item = (*(WorkerItemC44***)this)[i];
        SemaphoreC44* sem = &item->m_kCompletionSemaphore;
        ReleaseSemaphore(sem->m_pSemaphore, 1, 0);
        InterlockedIncrement(&sem->m_lCount);
    }
}

extern "C" __declspec(dllimport) void __stdcall DebugBreak();

struct FUN_00c49f10_Entry {
    int unk00;
    int unk04;
    int unk08;
};

struct FUN_00c49f10_Obj {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    FUN_00c49f10_Entry* unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;

    void __thiscall BSCompoundFrustum_VerifyGroups();
};

// Walks the entry array, tracking a running balance from entry types, and triggers DebugBreak if the balance goes negative or is non-zero at the end.
// @fnv 0x00c49f10
// src: COMMUNITY 0x00c49f10
void __thiscall FUN_00c49f10_Obj::BSCompoundFrustum_VerifyGroups() {
    int balance = 0;

    for (int index = 0; index < this->unk28; ++index) {
        if (this->unk18[index].unk00 == 4 ||
            this->unk18[index].unk00 == 5) {
            ++balance;
        }
        else if (this->unk18[index].unk00 == 6) {
            --balance;
        }
        else if (this->unk18[index].unk00 == 7 ||
                 this->unk18[index].unk00 == 8) {
            ++index;
        }

        if (balance < 0) {
            DebugBreak();
        }
    }

    if (balance != 0) {
        DebugBreak();
    }
}

extern "C" unsigned int __cdecl strlen(const char*);

struct RangeNameObj {
    int unk00;
    int unk04;
    const char* m_pcName;
    int unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8;
    short unkAC;
    unsigned char m_ucMin;
    unsigned char m_ucMax;
    void BSRangeNode_ParseNameForRanges();
};

// Parses a trailing numeric range from m_pcName, extracting min and max values into m_ucMin and m_ucMax.
// @fnv 0x00c45670
// src: XBOX_PDB 0x00c45670
void RangeNameObj::BSRangeNode_ParseNameForRanges()
{
    const char* pcName2 = m_pcName;
    const char* pcStr = pcName2;
    unsigned int uiLen = strlen(pcStr);
    unsigned int i = 1;
    while (((pcStr[uiLen - i] >= '0' && pcStr[uiLen - i] <= '9') || pcStr[uiLen - i] == '-') && i <= uiLen)
        i++;
    pcStr = pcStr + (uiLen - i) + 1;
    int iMin = 0;
    int iMax_2 = 0xff;
    const char* pcDash = strstr(const_cast<char*>(pcStr), "-");
    if (pcDash) {
        if (pcDash != pcStr)
            iMin = FUN_00eca6d3(pcStr);
        pcStr = pcDash + 1;
        if (*pcStr)
            iMax_2 = FUN_00eca6d3(pcStr);
    } else if (*pcStr) {
        iMin = FUN_00eca6d3(pcStr);
        iMax_2 = iMin;
    }
    int iLow6;
    if (iMin < iMax_2)
        iLow6 = iMin;
    else
        iLow6 = iMax_2;
    m_ucMin = (unsigned char)iLow6;
    int iHigh4;
    if (iMin > iMax_2)
        iHigh4 = iMin;
    else
        iHigh4 = iMax_2;
    m_ucMax = (unsigned char)iHigh4;
}

extern "C" __declspec(dllimport) long __stdcall RegCloseKey(HKEY);

struct RegistryClose : RegSettingCollection
{
    bool RegSettingCollection_Close();
};

// Closes the open registry key hKey via RegCloseKey, clears hKey to zero, and returns whether the close succeeded.
// @fnv 0x00c5d9b0
// src: XBOX_PDB 0x00c5d9b0
bool RegistryClose::RegSettingCollection_Close()
{
    bool ok = true;
    HKEY key = hKey;
    if (key != 0)
    {
        HKEY h = hKey;
        ok = (RegCloseKey(h) == 0);
        hKey = 0;
    }
    return ok;
}

class C5F080Node : public NiExtraData {

public:

    unsigned int unk0C;

    C5E7A0Object** items;

    unsigned int count;



    void BSTextureData_SaveBinary(C5E7A0Stream& stream);

};



// Saves the node's binary data by calling the base class, writing the item count, and saving the link ID of each item in the items array.
// @fnv 0x00c5f080
// src: XBOX_PDB 0x00c5f080
void C5F080Node::BSTextureData_SaveBinary(C5E7A0Stream& stream)

{

    unsigned int iterationCount;

    unsigned int initialCount;

    unsigned int countToWrite;

    unsigned int index;



    NiExtraData::SaveBinary(reinterpret_cast<NiStream&>(stream));



    initialCount = count;

    countToWrite = initialCount;

    C5E7A0SaveUInt(stream, &countToWrite);



    for (index = 0; index < (iterationCount = count); ++index)

        stream.SaveLinkID(items[index]);

}

extern "C" __declspec(dllimport) unsigned long __stdcall ResumeThread(void*);

struct TaskThreadResume {
    void* virtualTable;
    void* threadHandle;
    void BSTaskThread_StartThread();
};

// @fnv 0x00c42f50
// src: COMMUNITY 0x00c42f50
void TaskThreadResume::BSTaskThread_StartThread()
{
    ResumeThread(threadHandle);
}

struct Base_00c452f0 {
    void __thiscall NiNode_SaveBinary(NiStream& stream);
};


struct FUN_00c452f0_fields {
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    int m_a4;
    int m_a8;
    unsigned char m_ac;
    unsigned char field_ad;
    unsigned char field_ae;
    unsigned char field_af;
    void __thiscall BSRangeNode_SaveBinary(int a1);
};

// Calls the base class stream write, then writes field_ae, field_af, and field_ad to the NiStream via FUN_00a29550.
// @fnv 0x00c452f0
// src: XBOX_PDB 0x00c452f0
void FUN_00c452f0_fields::BSRangeNode_SaveBinary(int apStream)
{
    unsigned char value;

    ((Base_00c452f0*)this)->NiNode_SaveBinary(
        *reinterpret_cast<NiStream*>(apStream));

    {
        unsigned char value_ae;
        value_ae = field_ae;
        value = value_ae;
        Runtime_UpdateState_00a29550(
            *reinterpret_cast<NiStream*>(apStream),
            &value);

        {
            unsigned char value_af;
            value_af = field_af;
            value = value_af;
            Runtime_UpdateState_00a29550(
                *reinterpret_cast<NiStream*>(apStream),
                &value);

            {
                unsigned char value_ad;
                value_ad = field_ad;
                value = value_ad;
                Runtime_UpdateState_00a29550(
                    *reinterpret_cast<NiStream*>(apStream),
                    &value);
            }
        }
    }
}

extern "C" __declspec(dllimport) long __stdcall RegOpenKeyExA(
    HKEY, const char*, DWORD, DWORD, HKEY*);

struct RegistryOpen : RegSettingCollection {
    bool RegSettingCollection_Open(bool create);
};

// Opens or creates the registry key under HKEY_LOCAL_MACHINE using RegOpenKeyExA or RegCreateKeyExA depending on the create flag.
// @fnv 0x00c5d920
// src: XBOX_PDB 0x00c5d920
bool RegistryOpen::RegSettingCollection_Open(bool create)
{
    DWORD disposition;
    bool result;
    result = false;
    if (create) {
        result = (RegCreateKeyExA((HKEY)0x80000002, reinterpret_cast<const char*>(&unk004), 0, 0, 0, 0xf003f, 0, &hKey, &disposition) == 0);
    } else {
        result = (RegOpenKeyExA((HKEY)0x80000002, reinterpret_cast<const char*>(&unk004), 0, 0xf003f, &hKey) == 0);
    }
    return result;
}
