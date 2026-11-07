#include "../../include/NiRect.h"
#include "../../include/NiTListItem.h"
#include "../../include/NiTPointerListBase.h"

// src/staging/blk_00c40000_od_ob1_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/staging/blk_00c40000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00c40000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include <windows.h>
#include <string.h>
#include <d3d9.h>
#include "../../include/MapEntryCount.h"
// NavAllocator_blk_00c40000_od_ob1_variant: local type (was include/NavAllocator.h, which had no evidence of one real class); its methods are 0x00aa54a0 ScrapHeap::Allocate
class NavAllocator_blk_00c40000_od_ob1_variant {
public:
    int* Alloc(unsigned int size, unsigned int tag);
};
// NavEntryItem_blk_00c40000_od_ob1_variant: local type (was include/NavEntryItem.h, which had no evidence of one real class); no method of it is bound to a named game function
class NavEntryItem_blk_00c40000_od_ob1_variant
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
    int m_60;
};
// NavHolder_blk_00c40000_od_ob1_variant: local type (was include/NavHolder.h, which had no evidence of one real class); its methods are 0x00aa42e0 MemoryManager::GetThreadScrapHeap
class NavAllocator_blk_00c40000_od_ob1_variant;

class NavHolder_blk_00c40000_od_ob1_variant
{
public:
    NavAllocator_blk_00c40000_od_ob1_variant* GetAllocator();
};
#include "../../include/NiTPointerMap.h"
#include "../../include/SETTING_VALUE.h"

#define FNV64_NIPOINTER_INLINE_BODIES
#include "../../include/NiPointer.h"

// Comparisons are not declared by the shared pointer; keep this unit's inline
// equality operation alongside its list lookup bodies.
template <class T> inline bool operator==(const NiPointer<T>& left, const NiPointer<T>& right)
{
    return left.m_pObject == right.m_pObject;
}

#include "../../include/NiTListItem.h"
#include "../../include/NiTPointerAllocator.h"
#include "../../include/NiTListBase.h"
#include "../../include/NiTPointerListBase.h"

// The game pool's lock is needed by this unit's inline Deallocate; the shared
// allocator declares the free list but has no lock member.
#include "../../include/RecursiveSpinLock.h"
extern RecursiveSpinLock g_pointerAllocatorPoolState;









#include "../../include/BSLinearTaskThread.h"
#include "../../include/BSPSysMultiTargetEmitterCtlr.h"
#include "../../include/NiNode.h"
#include "../../include/BSDebrisNode.h"
#include "../../include/NiTriShape.h"
#include "../../include/Pair.h"
#include "../../include/RegSettingCollection.h"
#include "../../include/Vec4.h"
#include "../../include/BSThread.h"
#include "../../include/NiRefObject.h"
#include "../../include/NiBSBoneLODController.h"
#include "../../include/BSShaderAccumulator.h"
#include "../../include/AutoMemContext.h"
#include "../../include/NavMeshPtr.h"
#include "../../include/NiAVObject.h"
#include "../../include/NiPSysEmitterCtlr.h"
#include "../../include/NiPSysPositionModifier.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiStream.h"
#include "../../include/NiStringExtraData.h"
#include "../../include/Setting.h"
#include "../../include/NiMatrix3.h"
// LocalVec3: unit-local copy of the former shared stand-in Vec3. Same layout as NiPoint3; this unit defines inline bodies for both NiPoint3 and the stand-in in different forms (constructor/temporary, operand order), so one NiPoint3 cannot carry both.
#include "../../include/NiPoint3.h"
class Allocator;
class Elem16;
struct Mat;
struct Matrix4;
class NiPoint3;

struct LocalVec3
{
public:
    union
    {
        float x;
        unsigned int xb;
    };
    union
    {
        float y;
        unsigned int yb;
    };
    union
    {
        float z;
        unsigned int zb;
    };

    LocalVec3();
    // Keep the implicit copy constructor trivial for by-value calls.
    LocalVec3(float x, float y = 0.0f, float z = 0.0f);
    LocalVec3(const float* data);

    __forceinline LocalVec3& operator=(const LocalVec3& other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }

    LocalVec3 operator+(const LocalVec3& other) const;
    LocalVec3 operator-(const LocalVec3& other) const;
    NiPoint3 operator-(const NiPoint3& other) const;
    LocalVec3 operator-() const;
    LocalVec3 operator*(float scale) const;
    LocalVec3 operator*(double scale) const;
    LocalVec3& operator+=(const LocalVec3& other);
    LocalVec3& operator*=(float scale);
    LocalVec3& operator/=(float scale);
    bool operator==(const LocalVec3& other) const;
    bool operator!=(const LocalVec3& other) const;
    float& operator[](int index);
    float& operator[](unsigned int index);

    LocalVec3* Self();
    void Set(float x, float y, float z);
    void AssignOutput(const LocalVec3& other);
    LocalVec3 Neg() const;
    LocalVec3 Add(const LocalVec3& other) const;
    LocalVec3 Added(const LocalVec3& other) const;
    LocalVec3& AddTo(const LocalVec3& other);
    LocalVec3 AddVector(const LocalVec3& other);
    LocalVec3 AddVector(const LocalVec3& other) const;
    void Subtract(const LocalVec3& other);
    LocalVec3 Scale(float scale) const;
    LocalVec3 ApplyScaled(float scale);
    LocalVec3 ApplyScaled(float scale) const;
    LocalVec3 ScaleSwizzled(float scale);
    LocalVec3 ScaleSwizzled(float scale) const;
    void ScaleByInverse(float scale);
    void Normalize();
    void Unitize();
    LocalVec3 Cross(const LocalVec3& other) const;
    float Dot(const LocalVec3& other) const;
    float DotProduct(const LocalVec3& other);
    float DotProduct(const LocalVec3& other) const;
    float DotProduct(const LocalVec3* other) const;
    float Length() const;
    float LengthSquared() const;
    float GetSquaredXYLength();
    float GetSquaredXYLength() const;
    Elem16& expand(Allocator& allocator);

    void SetComponents(float x, float y, float z);
    bool FUN_00439090(const LocalVec3* other);
    bool HasEqualComponents(const LocalVec3* other);
    bool HasEqualComponents(const LocalVec3* other) const;
    bool HasEqualComponents(const char* other);
    void ScaleComponents(float scale);
    LocalVec3 FUN_00439e90(const LocalVec3& other);
    LocalVec3 FUN_00439e90(const LocalVec3& other) const;
    void SubtractIntoVector();
    LocalVec3 SubtractIntoVector(const LocalVec3& other);
    LocalVec3 SubtractIntoVector(const LocalVec3& other) const;
    LocalVec3 SubtractIntoVector(LocalVec3* other);
    LocalVec3 SubtractIntoVector(const LocalVec3* other);
    void SubtractIntoVector(LocalVec3* output, const LocalVec3* other);
    LocalVec3* SubtractIntoVector(void* output, void* other);
    void FUN_0043d410(float x, int y, int z);
    void FUN_0043d410(float x, unsigned int y, unsigned int z);
    float FUN_00457910();
    float FUN_00457990();
    float FUN_00457990() const;
    void Unitize_004a0c10();
    float FUN_004a7290();
    float FUN_004a7290() const;
    LocalVec3 FUN_004b3800(const LocalVec3& other) const;
    LocalVec3 ProcessAndReturnValue_0053d280(float divisor);
    float NiPoint3_XYLength();
    float NiPoint3_XYLength() const;
    void ComputeValue_0063c8a0(const LocalVec3* other);
    void ComputeValue_0063c8a0(void* other);
    void FUN_006815c0();
    float CVec3_Distance(LocalVec3* other);
    float CVec3_Distance(const LocalVec3& other) const;
    LocalVec3 TransformPointByMatrix4(const Mat& matrix);
    LocalVec3 TransformPointByMatrix4(const Matrix4* matrix);
    void Normalize_00b12790();
    LocalVec3 Diff_00b13040(void* other);
    LocalVec3 Diff_00b13040(const LocalVec3& other) const;
    float FUN_00b2a180(void* other);
    LocalVec3& AddComponents(void* other);
    void ProcessEntries_00ddc870();
    void FUN_00e0f6e0();
};
#include "../../include/MemoryManager.h"
#include "../../include/NiRTTI.h"
#include "../../include/NiFixedString.h"
#include "../../include/NiGlobalStringTable.h"
#include "../../include/NiTPrimitiveArray.h"
#include "../../include/NiTObjectArray.h"
#include "../../include/NiParticles.h"
#include "../../include/NiTNewInterface.h"
#include "../../include/NiTMallocInterface.h"

// Keep this unit's /Ob1 bodies on the shared array declarations.
template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::GetSize() const
{
    return m_usSize;
}
template <class T, class TAlloc> inline T& NiTArray<T, TAlloc>::GetAt(unsigned int uiIndex)
{
    return m_pBase[uiIndex];
}
template <class T, class TAlloc> inline const T& NiTArray<T, TAlloc>::GetAt(unsigned int uiIndex) const
{
    return m_pBase[uiIndex];
}


#include "../../include/BSBound.h"
#include "../../include/BSFaceGenMorphData.h"

#include "../../include/GO.h"
#include "../../include/NiBinaryExtraData.h"
#include "../../include/NiColor.h"
#include "../../include/NiExtraData.h"
#include "../../include/NiIntegerExtraData.h"
#include "../../include/NiMemObject.h"
#include "../../include/NiObject.h"
#include "../../include/NiObjectNET.h"

#include "../../include/NiPSysModifier.h"

#include "../../include/ThreadSemaphore.h"
#include "../../include/BSNiNode.h"
#include "../../include/NiBound.h"
#include "../../include/NiTransform.h"
#include "../../include/NiDX9Renderer.h"
#include "../../include/PathingSolution.h"



extern int DAT_010c1670;
extern int DAT_01016024;
struct FUN_00c40990_Class
{
    void __thiscall SetVtableAndProcessState_00c40990();
};
struct FUN_00c42b60_class
{
    int __thiscall CopyData_00c42b80();
    int a;
    int b;
    void ProcessEntries_00c42b60();
};
void __cdecl EnsureArenaAllocated(void*);
struct FUN_00c42da0_Class
{
    virtual void vfn_0000();
    virtual void vfn_0004();
};
int __stdcall BSTaskThread_ThreadProc(FUN_00c42da0_Class* p);
struct FUN_00c430a0_class
{
    int __thiscall BSXFlags_CreateClone(int);
};
struct FUN_00c430b0_class
{
    void __thiscall NiIntegerExtraData_CopyMembers(int a1, int a2);
    void __thiscall ForwardCall_00c430b0(int a1, int a2);
};

struct FUN_00c430d0 : public NiIntegerExtraData
{
    void LoadBinary(NiStream&);
};

struct FUN_00c43140_StandIn
{
    void FUN_00a9a4e0(int a);
    void BSXFlags_SaveBinary(int a);
};

bool NiStringExtraData::IsEqual(NiObject* other) const
{
    return 0;
}
extern NiFixedString* DAT_01202ddc;

extern "C" void* g_01202de0;
struct FUN_00c43650_Class
{
    void* __thiscall BSXFlags_GetRTTI();
};

struct FUN_00c43900_class
{
    void __thiscall BSValueNode_LinkObject(void* apParam);
};
extern "C" void* g_01202de8;
struct FUN_00c43cf0_Class
{
    void* __thiscall BSValueNode_GetRTTI();
};
struct FUN_00c43d60_cls
{
    char pad[0x108];
    int m_pSelf;
    char InitSelfPointer(int a);
};
extern "C" void __cdecl DoThreadShutdown(void*);
struct FUN_00c44940_Class
{
    void __thiscall BSParallelTaskThread_OnShutdown();
};
struct FUN_00c44960_class
{
    void __thiscall CallStoredCallback();
    void __thiscall BSParallelTaskThread_RunLinearTasks();
};
struct FUN_00c44cb0_class
{
    void* m0;
    void* m1;
    void* m2;
    void CallStoredCallback();
};
extern int DAT_010178bc;
void __cdecl UpdateFields_00c5faa0(void*);
struct FUN_00c44e20
{
    void UpdateFields_00c5faa0();
    ~FUN_00c44e20();
};
struct FUN_00c452a0_Class
{
    void __thiscall ReadChildListFromStream(int a);
    void __thiscall BSRangeNode_LinkObject(int a);
};

struct FUN_00a5e5b0_helper
{
    unsigned char RegisterChildStreamables(NiStream*);
};
struct FUN_00c452c0_class
{
    unsigned char BSRangeNode_RegisterStreamables(NiStream*);
};
extern char const* const g_01202e7c_arg1;
struct FUN_00c457d0_Class
{
    char const* const* __thiscall BSRangeNode_GetRTTI();
};
extern unsigned short DAT_01202e2c;
bool NiObjectGarbage_IsEmpty();

struct FUN_00c46810_Class
{
    void __thiscall FUN_00c31670(int);
    void __thiscall BSWindModifier_RegisterStreamables(int);
};
extern "C" void* g_01202e74;
struct FUN_00c47650_Class
{
    void* __thiscall BSMultiBoundNode_GetRTTI();
};
struct P03MM
{
    void* Allocate(unsigned int);
    void* AllocateScaled(unsigned int count);
};
extern P03MM g_memoryManager;
struct FUN_00c4aae0_class
{
    void __thiscall CopyStateTo(int a, int b);
    void __thiscall BSRangeNode_CopyMembers(int a, int b);
};
struct FUN_00c4ab40_class
{
    void __thiscall BSRangeNode_LoadBinary(int);
    void __thiscall BSBlastNode_LoadBinary(int);
};
struct FUN_00c452a0_class
{
    void BSRangeNode_LinkObject(int a);
};
// src: XBOX_PDB 0x00c452a0
void FUN_00c452a0_class::BSRangeNode_LinkObject(int a)
{}
struct FUN_00c4ab60_class
{
    void BSBlastNode_LinkObject(int a);
};
struct FUN_00c4abb0_class
{
    void BSRangeNode_SaveBinary(int);
    void BSBlastNode_SaveBinary(int a);
};
struct FUN_00c4abd0_class
{
    char BSRangeNode_IsEqual(int);
    char BSBlastNode_IsEqual(int a1);
};
extern "C" void* g_01202e7c;
struct FUN_00c4ac90_Class
{
    void* __thiscall BSBlastNode_GetRTTI();
};
struct FUN_00c4ad40_class
{
    void __thiscall CopyStateTo(int, int);
    void __thiscall BSDebrisNode_CopyMembers(int a, int b);
};
extern "C" void __cdecl BSRangeNode_LoadBinary(int);
struct FUN_00c4ada0_Class
{
    void __thiscall BSDebrisNode_LoadBinary(int a);
};
struct FUN_00c4ade0_class
{
    unsigned char BSRangeNode_RegisterStreamables(int);
    unsigned char BSDebrisNode_RegisterStreamables(int);
};
struct FUN_00c4ae10_Class
{
    void BSRangeNode_SaveBinary(int);
    void BSDebrisNode_SaveBinary(int a);
};
struct FUN_00c4ae30_class
{
    unsigned char BSRangeNode_IsEqual(unsigned int a);
    unsigned char BSDebrisNode_IsEqual(unsigned int a);
};
extern int g_01202e84;
struct FUN_00c4aef0_Class
{
    int* __thiscall BSDebrisNode_GetRTTI();
};
struct FUN_00c4afa0_class
{
    void __thiscall CopyStateTo(int a, int b);
    void __thiscall BSDamageStage_CopyMembers(int a, int b);
};
struct FUN_00c4b000_class
{
    void __thiscall BSRangeNode_LoadBinary(int);
    void __thiscall BSDamageStage_LoadBinary(int a);
};
struct FUN_00c4b020_Class
{
    void __thiscall BSRangeNode_LinkObject(int);
    void __thiscall BSDamageStage_LinkObject(int a);
};
struct FUN_00c452f0_cls
{
    void __thiscall BSRangeNode_SaveBinary(int a1);
};
// src: XBOX_PDB 0x00c452f0
void __thiscall FUN_00c452f0_cls::BSRangeNode_SaveBinary(int a1)
{}
struct FUN_00c4b070_cls
{
    void __thiscall BSDamageStage_SaveBinary(int a1);
};
struct GlobalObject_00a7b610;
extern GlobalObject_00a7b610 g_01202e8c;
struct FUN_00c4b210_Class
{
    GlobalObject_00a7b610* BSDamageStage_GetRTTI();
};

struct FUN_00c51550 : NiNode
{
    void __thiscall Copy(NiNode* a, void* b);
};
struct FUN_00c51570_Class
{
    void* __thiscall NiNode_GetViewerStrings(void* arg);
    void* __thiscall BSParticleSystemManager_GetViewerStrings(void* arg);
};
struct BaseT
{
    ~BaseT();
};
struct FUN_00c516d0 : BaseT
{
    void DoIt();
};
extern void* g_01203110;
struct FUN_00c516f0_Class
{
    void* __thiscall BSParticleSystemManager_GetRTTI();
};
extern const char* const g_011df0c0_arg1;
struct FUN_00c52870_class
{
    const char* const* BSSceneGraph_GetRTTI();
};
struct FUN_00c54dc0_class
{
    int __thiscall BSBound_CreateClone(int);
};

struct FUN_00a7b290_shell
{
    bool FUN_00a7b290(int);
    int RegisterStreamables_00c54e90(int arg);
};
extern "C" void* g_012031e8;
struct FUN_00c55320_Class
{
    void* __thiscall BSBound_GetRTTI();
};
struct FUN_00c5b5d0_class
{
    unsigned int BSPortalGraph_GetAlwaysRenderArrayCount();
};



struct FUN_00c1be10_shell
{
    bool RegisterEmitterInterpolatorStreamables(NiStream&);
    char BSPSysMultiTargetEmitterCtlr_RegisterStreamables(NiStream&);
};
extern int g_01203340;
struct FUN_00c5cea0_Class
{
    int* __thiscall BSPSysMultiTargetEmitterCtlr_GetRTTI();
};
extern int DAT_010c2e7c;
struct FUN_00a744a0
{
    void* vtbl;
    FUN_00a744a0();
};
FUN_00a744a0::FUN_00a744a0()
{}
struct FUN_00c5ceb0 : public FUN_00a744a0
{
    FUN_00c5ceb0();
};
extern "C" void __fastcall FUN_00a89760(void*);
extern int DAT_010c2e7c;
struct FUN_00c5cfb0
{
    virtual void vfn();
    void FUN_00a89760();
    ~FUN_00c5cfb0();
};
struct StrArr;
struct Caller74690
{
    void FUN_00a74690(StrArr*);
    void ForwardTo74690(StrArr* p);
};
extern "C" void* g_01203348;
struct FUN_00c5d2a0_Class
{
    void* __thiscall BSScissorTriShape_GetRTTI();
};
struct FUN_00c5dcb0_class
{
    void SetShortAtOffsetBA(short param);
};
extern "C" void* g_0120436c;
struct FUN_00c5ec90_class
{
    void* __thiscall GetGlobalPtr();
};
struct GlobalObject_00a7b610
{
    GlobalObject_00a7b610* __thiscall GetGlobalInstance();
};
extern GlobalObject_00a7b610 g_01204378;
extern int DAT_010c31a4;
struct Unk_00a5e930
{
    void __thiscall UpdateFields_00c5faa0();
};
struct FUN_00c5faa0
{
    void UpdateFields_00c5faa0();
};
extern const char* const g_01201f84_arg1;
struct FUN_00c5fc60_class
{
    const char* const* BSNiNode_GetRTTI();
};
extern void* DAT_010c32c4;

struct FUN_00c5fd30 : NiPSysPositionModifier
{
    FUN_00c5fd30();
};
NiPSysPositionModifier::NiPSysPositionModifier() throw()
{}
struct FUN_00c5ffb0_Class
{
    void __thiscall FUN_00c31670(int param);
    void __thiscall BSPSysStripUpdateModifier_RegisterStreamables(int param);
};
extern int DAT_010c30b8;
void NiFreeAlias(void*);
struct FUN_00c5eb60_Class
{
    int m0;
    int m1;
    void ResetAndFreeAlias();
};
void __cdecl FUN_00c3f8c0();

struct FUN_00c40930_Class
{
    void __thiscall FUN_00c3f8c0();
    void* __thiscall FUN_00c40930(unsigned int flags);
};
void __cdecl SetVtableAndProcessState_00c43070(void*);
struct FUN_00c43620_Class
{
    void __thiscall SetVtableAndProcessState_00c43070();
    void* __thiscall FUN_00c43620(unsigned int flags);
    static void __cdecl operator delete(void* p, unsigned int size);
};
struct FUN_00c43850_Class
{
    void __thiscall ForwardToBase(void* dst, unsigned int size);
    void __thiscall BSNiNode_CopyMembers(void* dst, unsigned int size);
};
extern "C" char* __cdecl _strchr(const char*, int);
extern "C" int __cdecl _strcpy_s(char*, unsigned int, const char*);
void __cdecl CopyMainNameFromPath(int param_1, char* param_2);
void __cdecl EnsureArenaAllocated(void*);
struct FUN_00c448f0_Class
{
    char pad[0x50];
    int m50;
    int m54;
    int m58;
    void __thiscall BSParallelTaskThread_OnStartup();
};
struct FUN_00c44cd0_class
{
    void __thiscall BSParallelTaskManager_StartThreads();
    void __thiscall WaitForWorkers();
};
struct FUN_00c44c40_class
{
    void __thiscall BSParallelTaskManager_RunTask_0(int a1, int a2);
};
struct FUN_00c455a0_Class
{
    void __thiscall BSRangeNode_SetCurrent(unsigned char);
};
struct FUN_00c5fb60_Class
{
    void __thiscall ForwardToBase(int a, int b);
};
struct FUN_00c451b0_class
{
    void __thiscall CopyStateTo(int a, int b);
};
extern int DAT_011af758;
void NiObjectGarbage_Init(int value);
int NiObjectGarbage_GetCount();
extern unsigned short DAT_01202e2e;
void __cdecl NiObjectGarbage_SetIncreaseSize(unsigned short value);

struct CloningProcess;

struct SStream;
struct SObj;
void __cdecl CallAnimCallback(SStream*, SObj*);
struct FUN_00c46830_class
{
    void __thiscall FUN_00c31950(NiStream* stream);
    void __thiscall Load(NiStream* stream);
};
void* __cdecl FUN_00ec7230(char* dst, const char* src, unsigned int size);
struct FUN_00c4a640_class
{
    void __thiscall BSSimpleArray_NiFrustumPlanes_1024_CopyItems(char* dst, char* src, unsigned int count);
};
extern "C" void* g_01202e7c;
extern "C" void* __cdecl NiViewerStrings_NiGetViewerString_Title(void*);

struct FUN_00c4ab00_Class
{
    void __thiscall BSRangeNode_GetViewerStrings(int);
    void __thiscall BSBlastNode_GetViewerStrings(int a);
};
struct FUN_00c4f2d0_class
{
    void __thiscall BSCullingProcess_PopCullMode();
};
struct FUN_00c5dcd0_Class
{
    void __thiscall BSMasterParticleSystem_AddEmitterObj(void* a);
};
struct FUN_00c50f30_Class
{
    FUN_00c5dcd0_Class* __thiscall GetEntryValue(int a);
};
struct FUN_00c505c0_Class
{
    void __thiscall BSParticleSystemManager_AddEmitter(int a, void* b);
};
void __cdecl FNV_Warning(const char* fmt, ...);
struct FUN_00c50f30_class
{
    int __thiscall GetEntryValue(int a);
};
extern int DAT_0106c814;
extern int DAT_010c256c;
struct FUN_00c51640_Class
{
    const char* s;
    int i;
    unsigned char b;
    int d;
    unsigned char c;
    int p;
    void* __thiscall UpdateMasterPsysTaskletData_UpdateMasterPsysTaskletData();
};
struct FUN_00878690_shell
{
    void __thiscall FUN_00c51df0();
};
void __cdecl operator delete(void* ptr, unsigned int size);
struct FUN_00c52830_class
{
    void* __thiscall FUN_00c52830(unsigned int flags);
};

struct NiExtraDataSaveHelper
{
    void SaveBinary(NiStream&);
};
struct FUN_00c54ec0_class
{
    void __thiscall BSBound_SaveBinary(NiStream& stream);
};
struct FUN_00a7b300_shell
{
    void __thiscall DestroyFields_00a7b300();
};
struct FUN_00c55330_class
{
    void* __thiscall FUN_00c55330(unsigned int flags);
    void operator delete(void* p, unsigned int size);
};
extern int DAT_010c2d54;
struct FUN_00c1c280_class
{
    void __thiscall FUN_00c1c280(int a);
};
struct FUN_00c5c3c0_class : FUN_00c1c280_class
{
    int __thiscall InitWithParams(int a, int b, unsigned short c);
};
extern int DAT_010c2d54;
struct FUN_00c1c390_Class
{
    void __thiscall FUN_00c1c390();
};


void __cdecl NiStreamSaveBinary_unsigned_short(NiStream&, unsigned short*);
struct S_00c1be40
{
    void FUN_00c1be40(NiStream& stream);
};
struct FUN_00c5cce0_Class
{
    char pad[0x5c];
    int m_0x5c;
    void __thiscall BSPSysMultiTargetEmitterCtlr_SaveBinary(NiStream& stream);
};
struct FUN_00c1be60_StandIn
{
    unsigned char __thiscall NiPSysEmitterCtlr_IsEqual(void*);
    char BSPSysMultiTargetEmitterCtlr_IsEqual(void* other);
};
struct FUN_00c5ced0 : FUN_00a744a0
{
    FUN_00c5ced0(int a, int b, int c, int d);
};
struct FUN_00c5cfd0_class
{
    void __thiscall UpdateState_00c5cfd0(int a, int b, int c, int d);
};
extern "C" void __cdecl BSAttachPoints_InitSDM();
extern "C" void __cdecl BSBound_InitSDM();
extern "C" void __cdecl BSFurnitureMarker_InitSDM();
extern "C" void __cdecl PArrayPoint_InitSDM();
extern "C" void __cdecl BSTextureData_InitSDM();
extern "C" void __cdecl BSWArray_InitSDM();
void __cdecl BSXFlags_InitSDM();
extern "C" unsigned char DAT_01204364;
void __cdecl BSMain_InitSDM();
extern unsigned char DAT_01204364;
void __cdecl Runtime_ReleaseStorage_00c655d0();
void __cdecl Object_UpdateFields_00c552a0();
void __cdecl Object_UpdateFields_00c54760();
void __cdecl Runtime_ReleaseReference_00c61990();
void __cdecl Object_UpdateFields_00c5f2e0();
void __cdecl Object_UpdateFields_00c61760();
void __cdecl Object_UpdateFields_00c435a0();
void __cdecl Object_UpdateFields_00c5d520();
struct FUN_00c5dea0_Entry
{
    unsigned char mFlag;
};
struct FUN_00c5dea0_Class
{
    int* pData;
    unsigned short mCount;
    void __thiscall BSMasterParticleSystem_ResetSystems();
};
struct FUN_00c5e560_class : public NiNode
{
    void __thiscall NiNode_CopyMembers(NiNode* a, void* b);
};
struct FUN_00c5db90_Class
{
    void __thiscall FUN_00c5db90();
};
void __cdecl operator delete(void* p, unsigned int size);
struct FUN_00c5eb20_Class
{
    void* __thiscall FUN_00c5eb20(unsigned int flags);
};
void __cdecl operator delete(void* p, unsigned int size);
struct FUN_00c5ed60_Class
{
    void __thiscall FUN_00c5ed60();
};
struct FUN_00c5f360_Class
{
    void* __thiscall FUN_00c5f360(unsigned int flags);
};
struct FUN_00c5f390_class
{
    void __thiscall BSSimpleArray_enum_hkpConstraintData_ConstraintType_1024_SetSize(int a, int b);
};
struct FUN_00c5f500_class
{
    void __thiscall BSSimpleArray_NiAVObject_1024_CopyTo_1024(FUN_00c5f500_class* other);
    int pad;
    int* data;
    unsigned int count;
};
struct FUN_00c5fc20_class
{
    void* __thiscall FUN_00c5fc20(unsigned int flags);
    void __cdecl operator delete(void* p, unsigned int size);
    void __thiscall FUN_00c5faa0();
};
struct BaseForCall
{
    bool NiNode_IsEqual(NiObject*);
};

struct FUN_00c439b0_class : BaseForCall
{
    char BSValueNode_IsEqual(NiObject* apParam);
};
struct RefCountedObject
{
    virtual ~RefCountedObject();
    virtual void vfn_0004();
    volatile long m_lObjectReferenceCount;
};
struct FUN_00c46270_Class
{
    RefCountedObject* m_pObject;
    FUN_00c46270_Class& __thiscall AssignRefCounted(const FUN_00c46270_Class& other);
};
extern GlobalObject_00a7b610 g_01202e60;
struct FUN_00c46960_Class
{
    GlobalObject_00a7b610* BSWindModifier_GetRTTI();
};
struct Elem_00c48a10
{
    int p;
    int a;
    int b;
};
struct Arr_00c48a10
{
    int _0;
    Elem_00c48a10* m_pData;
    int _8;
    int m_iCapacity;
    void FUN_00c4a1e0(int, bool);
};
struct FUN_00c48a10_t
{
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
struct FUN_00c4a9c0_class
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08(void*);
    void* m_p;
    unsigned int m_uiItemCount;
    int m_auiShapeKeys;
    void __thiscall ReleaseBuffer(unsigned char a);
};
void* __cdecl NiMalloc(unsigned int);

extern int DAT_010c1b2c;
struct FUN_00c5f570_Class
{
    void __thiscall FUN_00c5f570();
};
struct FUN_00c450d0 : FUN_00c5f570_Class
{
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
struct FUN_00c465a0_class
{
    void* operator new(unsigned int);
    FUN_00c465a0_class();
    char pad[0x1c];
};
struct FUN_00c46670_class
{
    void* __thiscall BSWindModifier_CreateClone(CloningProcess& process);
};
struct FUN_00c465a0
{
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
FUN_00c465a0* __cdecl BSWindModifier_CreateObject();
struct FUN_00c48fe0_Class
{
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
struct FUN_00c4a5a0_class
{
    virtual void vfn_0000();
    virtual void* vfn_0004(unsigned int);
    void* m1;
    unsigned int m2;
    unsigned int m3;
    void __thiscall BSSimpleArray_BSCompoundFrustum_FunctionOp_1024_InitialSetup(unsigned int a, unsigned int b);
};
struct CloningProcess;

struct NiFloatsExtraData;
struct NiExtraData_Shell
{
    void CopyMembers_00a7b330(NiBinaryExtraData*, CloningProcess*);
};
struct FUN_00c54dd0 : NiExtraData_Shell
{
    void CopyMembers_00a7b330(NiBinaryExtraData*, CloningProcess*);
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int h;
    int i;
};
struct FUN_00c54dd0_3i
{
    int x;
    int y;
    int z;
};
struct Elem4
{
    void FUN_008228f0(int);
};
struct FUN_0042fb60_shell
{
    void FUN_0042fb60(char*, char*, unsigned int);
};
struct FUN_00c5bef0_class
{
    char* m0;
    char* m1;
    unsigned int m2;
    void RemoveRange(unsigned int a, unsigned int b);
};

void __cdecl NiStreamLoadBinary_unsigned_short(NiStream*, void const*);
struct FUN_00c5cc30_class
{
    void LoadBinary(NiStream&);
    void BSPSysMultiTargetEmitterCtlr_LoadBinary(NiStream&);
};
char* __cdecl NiViewerStrings_NiGetViewerString_Title(char const*);
char* __cdecl NiGetViewerString_00a7d510(char const*, unsigned int);
struct FUN_00c5d610_StandIn
{
    unsigned int SettingCollectionList_Setting_GetViewerStrings(NiTPrimitiveArray<unsigned int>&);
};
struct FUN_00c5d610_Class
{
    unsigned int __thiscall AddRegSettingsStrings(NiTPrimitiveArray<unsigned int>& arr);
};
int __cdecl Setting_DataType_00c33090(int);

int __cdecl GetStateResult(int* apParams);
struct FUN_00c5e620_Class
{
    void __thiscall BSMasterParticleSystem_LoadBinary(NiStream* stream);
};

struct NiStream_ReadMultipleLinkIDs_Helper
{
    unsigned int __thiscall ReadUnsignedInteger();
};
struct ObjA
{
    void __thiscall BSTask_int64_DecRefCount();
};
struct FUN_00c40910_Class
{
    ObjA* m_p;
    void __thiscall CallObjA();
};
struct FUN_00c42060_Class
{
    virtual void vfn_0000();
    virtual void vfn_0004();
    int m4;  // +0x4
    int m8;  // +0x8
    char pad[0xc];
    unsigned char m18;  // +0x18
    void __thiscall SetArg(int arg);
};
extern int DAT_010c1844;
void __fastcall DestroyResources(void* thisPtr);
extern int DAT_010a0d24;
extern int DAT_010c1854;
struct FUN_00c43070_shell
{
    void DestroyFields_00a7b300();
    void SetVtableAndProcessState_00c43070();
};


extern void* _g_01202de0;
void* GetExtraDataChecked(NiAVObject* obj);
extern int DAT_010c195c;
struct FUN_00c43660 : FUN_00c5f570_Class
{
    char pad[0xb0];
    int f1;
    int f2;
    FUN_00c43660();
};

void __cdecl ReadBinaryValue(NiStream& stream, unsigned int& value);
void __cdecl NiStreamLoadBinary_char_00a643b0(NiStream& stream, unsigned int& value);

struct FUN_00c43920_class
{
    char BSValueNode_RegisterStreamables(NiStream* stream);
};
struct MyBase
{
    void __thiscall NiNode_SaveBinary(NiStream& stream);
};
void __cdecl Runtime_UpdateState_00a29550(NiStream& stream, unsigned char* p);
struct FUN_00c43950_Class : MyBase
{
    void __thiscall BSValueNode_SaveBinary(NiStream& stream);
};
struct FUN_00c43cb0_class
{
    void __thiscall FUN_00c5faa0();
    void* __thiscall FUN_00c43cb0(unsigned int flags);
};
struct FUN_00c457e0_class
{
    char pad[0xb0];
    void __thiscall FUN_00c5faa0();
    void* __thiscall FUN_00c457e0(unsigned int flags);
};
struct FUN_00c46230_Class
{
    void* m0;
    void __thiscall StoreAndAddReference_00c46230();
};
void __cdecl FUN_00c31750();
struct FUN_00c46930_class
{
    void __thiscall FUN_00c31750();
    void* __thiscall FUN_00c46930(unsigned int flags);
};
struct A51BF0Base
{
    char pad[0xb4];

    static void* __cdecl operator new(unsigned int size);
    A51BF0Base();

    void __thiscall BSMultiBoundNode_CopyMembers(A51BF0Base* copy, int a);
    A51BF0Base* __thiscall BSMultiBoundNode_CreateClone(int a);
};

struct NiStreamHelper
{
    void* __thiscall GetLoadedObject();
};
struct FUN_00c46cd0_Class
{
    char pad[0xac];
    GO m_go;

    void __thiscall LoadFromStream(void* stream);
};
struct FUN_00c46af0
{
    void __thiscall Destruct();
    void* __thiscall FUN_00c47610(unsigned int flags);
};
struct FUN_00c47a00_Class
{
    char pad0[0x18];
    char* m18;  // +0x18
    char pad1[0x4];
    int m20;  // +0x20
    char pad2[0x4];
    int m28;  // +0x28
    void BSCompoundFrustum_StartGroupIntersection();
};
struct FUN_00c47a70_Class
{
    void BSCompoundFrustum_StartGroupUnion();
};
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
struct FUN_00c4a960_Class
{
    void UpdateFields_00c4a840();
    void* FUN_00c4a960(unsigned int flags);
};
struct FUN_00c4ab80_class
{
    unsigned char BSRangeNode_RegisterStreamables(int);
    char BSBlastNode_RegisterStreamables(int a);
};
unsigned int __cdecl _FUN_00a7d330(int a);
struct FUN_00c4ad60_class : public FUN_00c4ab00_Class
{
    void __thiscall AddFirstEmptyFromGlobal(int a);
};
#include "../../include/NiTPrimitiveArray.h"
unsigned int __cdecl _FUN_00a7d330(void*);
struct FUN_00c4afc0_class
{
    void __thiscall AddValueToArray(NiTPrimitiveArray<unsigned int>* array);
};
struct FUN_00c4b090_class
{
    char BSDamageStage_IsEqual(int a1);
};

void* _NiMalloc(unsigned int size);
void NiFree(void* ptr);
struct FUN_00c4f270_Class
{
    char pad[0x90];
    int m_type;
    char pad2[0x28];
    int m_uiItemCount;
    int m_aiEntries[1];
    void __thiscall BSCullingProcess_PushCullMode(int aeType);
};

struct FUN_00c5ce40_Class
{
    int PopFrontNode();
};
struct FUN_00c5d260_view
{
    void __thiscall Destruct();
    static void __cdecl operator delete(void* p, unsigned int sz);
};
struct FUN_00c5d260 : FUN_00c5d260_view
{
    void* __thiscall FUN_00c5d260_method(unsigned int flags);
};
extern double runtimeInitializationDouble5;
extern double DAT_01034208;
float __cdecl EvaluateQuinticPolynomial(float x);
float BSNoise1D_lerp(float a, float b, float c);
struct NiObjectNET_stub
{
    void NiObjectNET_PostLinkObject(int);
};
struct FUN_00c5de70_stub
{
    void BSMasterParticleSystem_UpdateParticleSystemList();
};
struct FUN_00c5e6f0_class
{
    void BSMasterParticleSystem_PostLinkObject(int a);
};
struct FUN_00c5e720_Class
{
    unsigned char BSMasterParticleSystem_RegisterStreamables(NiStream* stream);
};
struct FUN_00c5ede0_Class
{
    int __thiscall GetEntryAt(int a);
};
struct S_00a953b0_Node
{
    void __thiscall CopyMemberData(S_00a953b0_Node*, void*);
};
struct FUN_00c5fb60_class : public S_00a953b0_Node
{
    void __thiscall ForwardToBase(S_00a953b0_Node*, void*);
};
struct FUN_00c25d40_Class
{
    void __thiscall ResetEntry(unsigned short);
};
struct FUN_00c5fd70_Class
{
    void __thiscall BSPSysStripUpdateModifier_Initialize(void* a, unsigned short b);
};

struct FUN_00c5ffd0 : NiPSysModifier
{
    void Method(NiStream* stream);
};
struct C40B20Timer
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned __int64 m_uiElapsedTime;

    void LockFreeMap_int64_NiPointer_BSTask_int64_LockFreeMapIterator_ClearKey();
};
struct S_0044dd60
{
    void __thiscall BSTask_int64_DecRefCount();
};
extern "C" void(__stdcall* FUN_00fdf1c0)(void*);
struct FUN_00c41050_Class
{
    S_0044dd60* m_pIntegerData;

    FUN_00c41050_Class* __thiscall AssignRef(S_0044dd60** other);
};
struct FUN_00c42b60_class;
struct SpawnHeap_cls
{
    void __thiscall MemoryManager_Deallocate(void* pObject);
};
extern "C" char DAT_011f6238;
typedef void(__stdcall* S_00c422d0_IAT_Fn)(void*);
extern "C" S_00c422d0_IAT_Fn DAT_0fdf050;
struct S_00c422d0_Entry
{
    unsigned int unk00;
    FUN_00c42b60_class* m_pObject;
};
struct S_00c422d0_Foo
{
    unsigned int m_uiItemCount;
    unsigned int m_unk04;
    S_00c422d0_Entry* m_pEntries;
    void __thiscall DestroyEntries();
};
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
void* __cdecl Object_DispatchCommandFour(unsigned int size);
extern int DAT_011f49e0;
struct SpawnedObject_b9874
{
    char m00[0x10];
    SpawnedObject_b9874();
    void Init(int* arg);
    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
};
SpawnedObject_b9874* BSXFlags_CreateObject();
struct S_00c437c0_Obj
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c,
        unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c,
        unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4;
    static void* operator new(unsigned int);
    S_00c437c0_Obj();
};
struct S_00c437c0 : FUN_00c43850_Class
{
    S_00c437c0_Obj* CreateObject(unsigned int stream);
};
void* __cdecl Object_DispatchCommandFour(unsigned int size);
struct SpawnedObject_b9504 : FUN_00c43660
{
    static void* operator new(unsigned int size) throw()
    {
        return Object_DispatchCommandFour(size);
    }
};
FUN_00c43660* __cdecl BSValueNode_CreateObject();
class FUN_00c43be0_cls
{
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
// CopyStringBeforeColon
// Copies the leading part of a path (up to the first ':') into a caller buffer.
struct FUN_00c43e00_Obj
{
    int unk00;
    int unk04;
    char* m_pStr;
};
extern "C" char* __cdecl FNV_StrChr(const char* s, int c);
extern "C" unsigned int __cdecl FNV_StrLen(const char* s);
extern "C" void __cdecl FNV_CopyPath(char* dest, unsigned int destSize, const char* src, unsigned int count);
void __cdecl CopyStringBeforeColon(FUN_00c43e00_Obj* pObj, char* pDest);
struct S_00c44d90_Item;
struct S_00c44d90_Cls
{
    void(__cdecl* m_pfnWork)(int, int);
    int* m_pArg;
    unsigned int m_uiCount;
    volatile long m_lIndex;
};
void __cdecl RunWorkItems(S_00c44d90_Cls* pParam);

void NiStreamLoadBinary_char_00a643b0(NiStream& kStream, bool& m_bHeaderParsed);

class BSNodeC45 : public NiNode
{
  public:
    short unkAC;
    bool m_bFlagAE;
    bool m_bFlagAF;
    void SetFlag(bool m_bHeaderParsed);
    void BSRangeNode_LoadBinary(NiStream& kStream);
};
struct S_00c45380_Base
{
    bool NiNode_IsEqual(S_00c45380_Base*);
};
struct S_00c45380_Obj : S_00c45380_Base
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
    unsigned char unkAC;
    unsigned char unkAD;
    unsigned char unkAE;
    unsigned char unkAF;
    char BSRangeNode_IsEqual(S_00c45380_Obj* other);
};
extern "C" __declspec(dllimport) int __stdcall fnv_Import_TryEnterCriticalSection(void* cs);
extern "C" __declspec(dllimport) void __stdcall fnv_Import_LeaveCriticalSection(void* cs);
class GameLockA
{
  public:
    bool BSSpinLock_TryLock();
    void BSSpinLock_Lock(int a);
};
extern GameLockA DAT_01202e40;
extern NiTObjectArray<NiPointer<NiRefObject> > DAT_01202e20;
extern unsigned int DAT_01202e44;
extern unsigned int DAT_011f4380;
void __cdecl TruncateStringToMaxLength();
struct FUN_00c459d0_frame
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
};
void __cdecl NiObjectGarbage_ClearAll(unsigned char a1);
extern int DAT_010c1c5c;
extern void* __cdecl Runtime_GetIndexedValue_00c46170(unsigned int count);
struct S_00c46530_Class
{
    void* m_vtbl;
    void* m_result;
    unsigned short m_uiItemCount;
    unsigned short m_field_0a;
    unsigned short m_field_0c;
    unsigned short m_field_0e;

    S_00c46530_Class* __thiscall FUN_00c46530(unsigned short param1, unsigned short param2);
};
// @fnv 0x00c46530
S_00c46530_Class* __thiscall S_00c46530_Class::FUN_00c46530(unsigned short param1, unsigned short param2)
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;

    this->m_vtbl = &DAT_010c1c5c;
    this->m_uiItemCount = param1;
    this->m_field_0e = param2;
    this->m_field_0a = 0;
    this->m_field_0c = 0;

    if (this->m_uiItemCount > 0)
    {
        this->m_result = Runtime_GetIndexedValue_00c46170(this->m_uiItemCount);
    }
    else
    {
        this->m_result = 0;
    }

    return this;
}
class FUN_00c46860_cls
{
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
void __cdecl BSWindModifier_SetWind(float a1, float a2);
class C46D60Stream
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
    virtual void vfunc0B();
    virtual void SaveLinkID(void* pvObject);
};
class C46D60Base
{
  public:
    void NiNode_SaveBinary(C46D60Stream& kStream);
};
class C46D60Node : public C46D60Base
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
    void* m_pkChild;

    void BSMultiBoundNode_SaveBinary(C46D60Stream& kStream);
};
struct FUN_00c46da0_class : BaseForCall
{
    bool __thiscall BSMultiBoundNode_IsEqual(NiObject* other);
};
void* __cdecl Object_DispatchCommandFour(unsigned int size);
struct NewObject_b9649
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
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    NewObject_b9649();
    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
};
NewObject_b9649* CreateNewObject();
struct UpdateContext
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c;
    int state;
};
struct BoundBase
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
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual bool Test(void*);
};
struct BoundTester : BoundBase
{
    int unk04;
    int state;
};
struct BoundReference
{
    int unk00, unk04, unk08;
    BoundTester* object;
};
struct UpdateChild
{
    void FUN_00a59e00(UpdateContext*);
};
struct UpdateOwner
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    UpdateChild** children;
    unsigned short capacity, count, enabled, unkAA;
    BoundReference* reference;
    int replacement;
    void BSMultiBoundNode_OnVisible(UpdateContext*);
};
// Stand-in model of CheckProcStateAndPlane (0x00c47150, 252 bytes) - an /Od member function.
//
// The original is:
//   bool CheckProcStateAndPlane(LocalVec3 pt, Proc* proc, Plane* plane)
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
struct FNV_Vec3
{
    float x;
    float y;
    float z;
};
struct FNV_Proc
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
};
struct FNV_Local
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
    void FUN_0045c620();
};
struct FNV_Target
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
    virtual bool v40(FNV_Local* pObj);
    int unk04;
    int unk08;
};
struct FNV_Holder
{
    int unk00;
    int unk04;
    int unk08;
    FNV_Target* unk0c;
};
struct FNV_Plane
{
    void BSOcclusionPlane_UpdateFrustumPlanes(FNV_Vec3 pt, FNV_Local* pObj);
};
struct FNV_Owner
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
    FNV_Holder* unkAC;
    bool CheckProcStateAndPlane(FNV_Vec3 pt, FNV_Proc* proc, FNV_Plane* plane);
};
struct TargetCls
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
    virtual void v35(int a);
};
struct OwnerCls
{
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
struct Rec64
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
};
struct Vec12
{
    int x;
    int y;
    int z;
};
struct Elem0C
{
    int a;
    int b;
    int c;
};
struct ArrRec64
{
    void* vtbl;
    Rec64* m_pData;
    int unk08;
    unsigned int m_uiSize;
    void SetSizeRec(unsigned int n, bool b);
};
struct ArrElem0C
{
    void* vtbl;
    Elem0C* m_pData;
    int unk08;
    unsigned int m_uiSize;
    void Resize(unsigned int n, bool b);
};
struct Obj_c477f0
{
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
extern NavHolder_blk_00c40000_od_ob1_variant g_navHolder;
extern unsigned int g_navTag;


extern NiPoint3 DAT_011f426c;
struct SSNode
{
    bool __thiscall BSOcclusionPlane_WithinFrustumDistFirst(void*, void*);
    bool __thiscall BSOcclusionPlane_WithinFrustum(void*, int, NiPoint3);
    bool __thiscall BSOcclusionPlane_CompletelyWithinFrustum(void*);
};
struct DecisionNode
{
    int type;
    int trueIndex;
    int falseIndex;
};
struct VolumeRecord
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
};
struct DecisionTree
{
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
extern int DAT_010c1e9c;
struct FUN_00c4a1b0_cls
{
    int m_vptr;

    FUN_00c4a1b0_cls* SetVtableAndProcessState_00c4a1b0();
};
class CachedRef_b5611
{
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
struct FUN_00c4a8e0
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual ~FUN_00c4a8e0();
};
struct FUN_00c4b150_cls
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
    int m_30;
    void FUN_00a5dd70(int a1, int a2);
    void CallIfNotFlagged(int a1, int a2);
};
struct S_c4b190_Base
{
    void FUN_00a5ded0(int a, int b);
};
struct S_c4b190 : S_c4b190_Base
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    int unk30;
    void CallBaseIfFlagClear(int a, int b);
};
struct S_00c4b1d0_Cls
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
    unsigned int flags;
    void NiNode_UpdateRigidDownwardPass(int a, int b);
    void BSDamageStage_UpdateRigidDownwardPass(int a, int b);
};
class FUN_00c4b470_owner
{
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
int __cdecl BSUtilities_GetObjectByName_00c4b470(FUN_00c4b470_owner* a1, void** a2, unsigned char a3);
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
struct FUN_00c4cf00_Entry
{
    int m_iA;
    int m_iB;
    float m_fC;
};
struct FUN_00c4cf00_Data
{
    int unk00;
    FUN_00c4cf00_Entry* m_pItems;
};
struct FUN_00c4cf00_cls
{
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
struct S_00c4dcf0
{
    int GetPointSide(float a, float b, float c, float d, float e, float f, float g, float h, float i);
};
struct S_00c4e0a0_Data
{
    int unk00;
    unsigned short* m_pValues;
};
struct S_00c4e0a0_Class
{
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

    bool __thiscall BSPolygon2D_IsPointInsideTri(int arg1, int arg2, int arg3, int arg4, int arg5);
    bool __thiscall ContainsMatchingTriple(int arg1, int arg2);
};
struct S_00c4e900_Elem
{
    int a;
    int b;
    int c;
};
struct S_00c4e900_Arr
{
    int unk00;
    S_00c4e900_Elem* data;
    int count;
    void ReverseElements();
};
extern unsigned char DAT_012030a4;
struct S_00c4ed70_Object
{
    virtual void vfn_0000();
    virtual void vfn_0004();
    virtual void vfn_0008();
    virtual void vfn_000c();
    virtual void vfn_0010();
    virtual void vfn_0014();
    virtual void __stdcall vfn_0018(int);
};
struct S_00c4ed70_Class
{
    S_00c4ed70_Object* m_pObject;
    bool __thiscall BSOcclusionQuery_Begin();
};
void S_00c4ed70_Object::vfn_0000()
{}
void S_00c4ed70_Object::vfn_0004()
{}
void S_00c4ed70_Object::vfn_0008()
{}
void S_00c4ed70_Object::vfn_000c()
{}
void S_00c4ed70_Object::vfn_0010()
{}
void S_00c4ed70_Object::vfn_0014()
{}
void __stdcall S_00c4ed70_Object::vfn_0018(int)
{}
// Candidate v2 for FUN_00c4edb0 (zai_04).
// Same guard logic; callee hypothesis: virtual __stdcall member taking one int,
// called as m_p->vfn(1). MSVC passes this as the first __stdcall stack argument
// (push 1 then push m_p), vtable slot 6 (+0x18), no ecx requirement at call.
extern unsigned char DAT_012030a4;
struct FUN_00c4edb0_Virt
{
    virtual void vfn_0000();
    virtual void vfn_0004();
    virtual void vfn_0008();
    virtual void vfn_000c();
    virtual void vfn_0010();
    virtual void vfn_0014();
    virtual void __stdcall vfn_0018(int one);
};
struct FUN_00c4edb0_Class
{
    FUN_00c4edb0_Virt* m_p;
    void BSOcclusionQuery_End();
};
struct S_00c4edf0_Obj
{
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0c();
    virtual void vfn10();
    virtual void vfn14();
    virtual void vfn18();
    virtual int __stdcall vfn1c(int, int, int);
};
struct S_00c4edf0_cls
{
    S_00c4edf0_Obj* unk00;
    bool BSOcclusionQuery_GetResult(int a1, bool a2);
};
struct DispatchObject
{
    virtual void __stdcall reserved0();
    virtual void __stdcall reserved1();
    virtual void __stdcall reserved2();
    virtual void __stdcall reserved3();
    virtual void __stdcall FunctionAtSlot4();
    virtual void __stdcall FunctionAtSlot5();
    virtual void __stdcall FunctionAtSlot6();
    virtual int __stdcall Execute(int code, int mode, int flag);
};
struct DispatchOwner
{
    DispatchObject* object;
    bool __thiscall BSOcclusionQuery_GetResultNoWait(int code, unsigned char enabled);
};
struct FUN_00c509a0_Class
{
    void* __thiscall GetEntryValue(int);
    void __thiscall BSParticleSystemManager_RemoveMasterParticleSystem_00c51700(void*);
    void __thiscall BSParticleSystemManager_RemoveMasterParticleSystem(int);
};
extern "C" char DAT_010c2580;
extern "C" void __cdecl Warning_005b5e40(void*, int);
// FUN_00c50dd0: clears (releases) the pointer held by the second argument's
// smart-pointer holder. The two dword locals reproduce the original /Od frame
// layout (named locals above the hidden 'this' spill at [ebp-0xc]).
struct FUN_00c50dd0_Holder
{
    void* __thiscall FUN_0066b0d0(void* value);
};
struct FUN_00c50dd0_cls
{
    int unk00;
    void BSParticleSystemManager_DetachChildAt_00c50dd0(int* p1, FUN_00c50dd0_Holder* p2);
};
struct S_00c50ea0_T
{
    void FUN_0066b0d0(int a);
};
struct S_00c50ea0
{
    void BSParticleSystemManager_SetAt_00c50ea0(int a1, int a2, S_00c50ea0_T* a3);
};
// Layout up to the item array (+0xa0) and the 16-bit item count (+0xa8).
struct FUN_00c50ec0_cls
{
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

extern const NiRTTI DAT_012024e0;
extern const NiRTTI DAT_01203340;
void __cdecl FNV_Warning(const char* fmt, ...);




bool __cdecl SetParticleSystemTarget(NiAVObject* pkObject, int iTarget);
void __cdecl FUN_00aa1460(void* apMemory, unsigned int auiSize);
struct FUN_00c51590_cls
{
    int unk00;

    void BaseCleanup();

    FUN_00c51590_cls* FUN_00c51590(unsigned int acFlags);
};
struct FUN_00c516a0_Virtual
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
    virtual void v41(void*, int);
};
struct FUN_00c516a0_Class
{
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
struct FNV_MemoryManager
{
    void Deallocate(void* p);
};
extern FNV_MemoryManager FNV_g_memoryManager;
struct FNV_SubObject
{
    int* m_vtbl;        // +0x00
    FNV_Item* m_pBase;  // +0x04
};
struct FNV_Base
{
    int unk00;  // +0x04
    int unk04;  // +0x08
    virtual void vfn();
    ~FNV_Base();
};
struct FUN_00c53fa0_Class : public FNV_Base
{
    FNV_SubObject m_sub;  // +0x0c
    ~FUN_00c53fa0_Class();
};
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
struct C00c541e0
{
    int unk00;
    int unk04;
    int unk08;
    bool FUN_00a7b3d0(int other);
};
struct C00c54f00 : C00c541e0
{
    NiPoint3 m_vec0C;
    NiPoint3 m_vec18;
    bool BSBound_IsEqual(int other);
};
struct C55CD0Point3
{
    float x;
    float y;
    float z;
};
void C55CD0DrawBox(const C55CD0Point3& kMinBoundsCur, const C55CD0Point3& kMaxPoint, float fA, float fB, float fC, float fD,
                   unsigned int uiColor, unsigned int uiOutline);
void Runtime_UpdateState_00c55cd0(const C55CD0Point3& kTargetCenter, float fSize, unsigned int uiColor);
struct S_00c5ae70_Result
{
    int unk00;
    int unk04;
    int unk08;
};
struct S_00c5ae70_Inner2
{
    int unk00;
    int unk04;
    int unk08;

    S_00c5ae70_Result* __thiscall NiGeometry_AddProperty();
};
struct S_00c5ae70_Inner1
{
    int unk00;
    int unk04;
    S_00c5ae70_Inner2 m_inner2;

    void __thiscall NiTListBase_NiTPointerAllocator_unsigned_int_BSFaceGenKeyframe_AddNodeTail(S_00c5ae70_Result* result);
};
struct S_00c5ae70_Class
{
    int unk00;
    int unk04;
    S_00c5ae70_Inner1 m_inner1;

    void __thiscall BSPortalGraph_AddOccluder(int param);
};
struct FUN_00c3a250_Obj
{
    void __thiscall FUN_00c3a250(int* a1);
};
void __thiscall FUN_00c3a250_Obj::FUN_00c3a250(int* a1)
{}
struct FUN_00c5aec0_Class
{
    int unk00;
    int unk04;
    void __thiscall BSPortalGraph_RemoveOccluder(int a1);
};
struct FUN_00c5b190_Sub
{
    void Process(int* p);
};
struct FUN_00c5b190_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    FUN_00c5b190_Sub m_14;
    void BSPortalGraph_RemovePortal(int a1);
};
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


struct FUN_00a53c30_cls
{
    bool FUN_00a53c30(unsigned int key, void** out);
};
struct FUN_00c5cb50_pad
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
};
struct FUN_00c5cb50_cls
{
    void FUN_00c1bdc0(int a1);
    void BSPSysMultiTargetEmitterCtlr_ProcessClone(int a1);
};
class BC5CBB0Object
{
  public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);
};
class BC5CBB0Controller : public BC5CBB0Object
{
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
BC5CBB0Object* __cdecl BSPSysMultiTargetEmitterCtlr_CreateObject();
struct EmitterObjectStub
{
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
struct EmitterOwnerStub
{
    void Attach(EmitterObjectStub* pkObject, int iParam);
    EmitterObjectStub* CreateAndAttachEmitterObject(int iParam);
};
struct FUN_00c5d0a0_cls;
struct FUN_00c5d0a0_cls
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
    Vec4 m_c4;
    void Helper(FUN_00c5d0a0_cls* other, int b);
    void CopyVec4AndHelper(FUN_00c5d0a0_cls* a1, int a2);
};
typedef void* HKEY_t;
int __cdecl Setting_DataType_00c33090(int);
extern "C" int __cdecl strcpy_s(char* dst, unsigned int size, const char* src);
struct RegSetting
{
    int unk00;
    int value;
    char* pName;
    unsigned int GetSize();
};
struct RegStore
{
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0C();
    virtual void vfn10();
    virtual void vfn14();
    virtual void Open(bool bWrite);
    virtual void Close();
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
    HKEY_t m_hKey;

    bool WriteSetting(RegSetting* pSetting);
};
typedef struct HKEY__* HKEY;
typedef unsigned long DWORD;
typedef unsigned char BYTE;
extern "C" __declspec(dllimport) long __stdcall RegQueryValueExA(HKEY hKey, const char* lpValueName, DWORD* lpReserved,
                                                                 DWORD* lpType, BYTE* lpData, DWORD* lpcbData);
extern "C" int __cdecl strcpy_s(char* dst, unsigned int size, const char* src);


int __cdecl GetStateResult(int* apParams);

// FUN_00c5de30: thiscall, zero two fields, reset sub-object at +0xac
struct ResetHelper
{
    unsigned int unk00, unk04, unk08;
    void __thiscall Reset();
};
class FUN_00c5de30_cls
{
  public:
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34,
        unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74,
        unk78, unk7C, unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8;
    ResetHelper m_ac;
    unsigned short m_b8;
    unsigned short unkBA;
    unsigned int unkBC;
    unsigned int m_c0;
    void __thiscall UpdateState_00c5de30();
};
struct FUN_00c5de70_sub
{
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
extern int g_01203340;
struct FUN_00c5e010_Node
{
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
inline void FUN_00c5e010_Node::vf04()
{}
inline int FUN_00c5e010_Node::vf08()
{
    return 0;
}
// src: GUESS 0x00c5e010 (confidence: low)
bool __cdecl Runtime_ProcessEntries_00c5e010(int object)
{
    FUN_00c5e010_Node* initial = *reinterpret_cast<FUN_00c5e010_Node**>(reinterpret_cast<char*>(object) + 0x0C);
    FUN_00c5e010_Node* current = initial;

    while (current != 0)
    {
        bool found;
        if (current == 0)
            found = false;
        else
            found = current->vf08() == reinterpret_cast<int>(&g_01203340);

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
struct S_00c5e3d0
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
struct S_00c5e3d0_pad
{
    int a, b, c, d;
    float saved;
};
struct FUN_00c5e450_cls
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
class C5E7A0Object;
class C5E7A0Stream
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
    virtual void vfunc0B();
    virtual void SaveLinkID(C5E7A0Object* pkObject);
};
void C5E7A0SaveShort(C5E7A0Stream& kStream, unsigned short* pusValue);
void C5E7A0SaveUInt(C5E7A0Stream& kStream, unsigned int* puiValue);
class C5E7A0Node
{
  public:
    void SaveBinary(C5E7A0Stream& kStream);
};
class C5E7A0Switch : public C5E7A0Node
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
struct SwitchChild
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual bool IsEqual(SwitchChild* pOther);
};
// Exe 0x00c5fe30: unit-local ListNode view; declarations and layout are preserved.
struct BlkListNodeView
{
    BlkListNodeView* m_pkNext;
    BlkListNodeView* m_pkPrev;
    int m_element;
};
struct ListOwner_c5e830 : BaseForCall
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
struct FUN_007530a0
{
    virtual ~FUN_007530a0()
    {}
};
struct FUN_00a7b300
{
    virtual ~FUN_00a7b300()
    {}
};
struct FUN_00c5ed60 : FUN_00a7b300
{
    int unk04;
    int unk08;
    FUN_007530a0 m_00c;
    virtual ~FUN_00c5ed60();
};
NiObject* __cdecl CreateShaderAccumulator(void);
struct FUN_00a7b4a0_cls
{
    void __thiscall FUN_00a7b4a0(int a);
};
struct FUN_00a645b0_cls
{
    void __thiscall ReadLinkID();
};
void __cdecl NiStreamLoadBinary_float(int a, int* out);
class FUN_00c5ef50_cls
{
  public:
    void __thiscall BSTextureData_LoadBinary(int a1);
};
class FUN_00c5f100_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    void** m_ppItems;
    unsigned int m_uiCount;

    bool Equals(FUN_00c5f100_cls* other);
};

struct CloneNode : NiMemObject
{
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
struct CloneOwnerObj : FUN_00c5fb60_Class
{
    CloneNode* __thiscall BSNiNode_CreateClone(void* context);
};
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
char* __cdecl ConcatPrefixAndSuffix(FUN_00c5fb80_rec* rec, const char* suffix);
extern void* DAT_010c32c4;
struct FUN_00c5fd50_cls
{
    void* m_vtbl;
    void FUN_00c31750();
    void UpdateState_00c5fd50();
};
void* __cdecl Object_DispatchCommandFour(unsigned int);
struct PositionModifierInstance
{
    FUN_00c5fd30 modifier;
    void* name;
    unsigned int order;
    void* target;
    bool active;
    float lastTime;
    void* next;
    static __forceinline void* operator new(unsigned int amount)
    {
        return Object_DispatchCommandFour(amount);
    }
};
FUN_00c5fd30* __cdecl CreatePositionModifierInstance();
struct MyStream;
void NiStreamLoadBinary_float(MyStream* stream, void* value);
struct ParticlePositionModifier
{
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
char* __cdecl NiGetViewerString(const char* name, bool value);

struct KwHi
{
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
struct KwLo
{
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
struct ThisC43220
{
    int f00;
    int f04;
    int f08;
    unsigned int m_flags;
    void FUN_00a99d70(NiTPrimitiveArray<unsigned int>* arr);
    void AppendKeywordFlags(NiTPrimitiveArray<unsigned int>* arr);
};
class BC45120CloningProcess;
class BC45120Object
{
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
struct Ref462f0
{
    void* vtable;
    volatile long references;
};
struct Slot462f0
{
    Ref462f0* p;
    Slot462f0& AssignRefCounted(const Slot462f0&);
};
extern Ref462f0* DAT_01202e14;
extern unsigned int DAT_01202e18;
void __cdecl FUN_00fdd690();
int __cdecl FUN_00ec658f(void(__cdecl*)());

struct Entry
{
    int type;
    int a;
    int b;
};
struct Target
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    Entry* data;
    int unk1c, unk20, unk24;
    int count;
    void CompactEntries();
};
struct MeshStatsData
{
    unsigned int unk00, unk04;
    unsigned short vertices, unk0a;
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
struct MeshStatsEntry
{
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
    unsigned int unkbc, unkc0, unkc4, unkc8, unkcc;
    unsigned int bytes;
};
struct Statistics
{
    unsigned int meshes, triangles, vertices, materials, other, bytes;
};
struct MeshCollection
{
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
    unsigned short materials, unkba;
    unsigned int unkbc, unkc0, unkc4, unkc8, unkcc;
    MeshStatsEntry** meshes;
    unsigned short capacity, used;
    void AccumulateStatistics(Statistics*);
};
// Refresh every key whose time lags the given time by more than the controller's threshold.
struct FDA0Key
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};
class FDA0Data
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
class FDA0Controller
{
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
extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(long volatile* dest, long exchange,
                                                                           long comparand);
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
struct Pad16_5b
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
};
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
struct RefObj
{
    int unk00;
    int unk04;
    volatile long m_iObjectReferenceCount;
};
struct RefPtr
{
    RefObj* m_pObject;
};
struct NodeKey
{
    int a;
    int b;
};
struct NodeFlags
{
    unsigned int m_uiValue1;
};
struct Node
{
    NodeKey m_key;
    RefPtr m_pReferencedObject;
    NodeFlags m_flags;
};
struct TaggedNodePtr
{
    unsigned int m_uiBits;
};
struct Handler
{
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
struct NodeQueue
{
    Handler* m_pHandler;
    int* m_p04;
    int* m_p08;
    int* m_p0C;
    int unk10;
    TaggedNodePtr m_kSecond;
    TaggedNodePtr m_kFirst;

    bool __thiscall LockFreeMapInterface_Find_0(int arg, NodeKey key);
    bool LockFreeMap_int64_NiPointer_BSTask_int64_LockFreeMapInterface_GetNext(int arg, NodeKey* pKey, RefPtr* pOut);
};
struct FUN_00c42560_pad
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
};
struct C45440_Obj : FUN_00c450d0
{
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
C45440_Obj* __cdecl CreateC45440Obj(void);
struct Animation;

struct C5EDC0_AnimExtra
{
    int unk00;
    int unk04;
    int unk08;
    NiTObjectArray<Animation*> m_kAnimations;
    unsigned int __thiscall AddAnimation(Animation* apAnim);
};

namespace c30 {
struct FUN_00c5fd30 : BSFaceGenMorphData
{
    FUN_00c5fd30();
    int m[7];
};
struct Owner30
{
    void BSPSysStripUpdateModifier_CopyMembers(FUN_00c5fd30* mod, int arg);
    FUN_00c5fd30* CreateMorphData(int arg);
};
// @fnv 0x00c5fe30
FUN_00c5fd30* Owner30::CreateMorphData(int arg)
{
    FUN_00c5fd30* mod = new FUN_00c5fd30;
    BSPSysStripUpdateModifier_CopyMembers(mod, arg);
    return mod;
}
}

struct ShapeEntry
{
    virtual ~ShapeEntry();
};
extern void* DAT_010c16dc;

struct ShapeList
{
    void* vtable;
    ShapeEntry** data;
    unsigned count;
    void SetVirtualTable_00c409e0();
};
static inline void FreeShapeArray(void* memory)
{
    ((SpawnHeap_cls*)&DAT_011f6238)->MemoryManager_Deallocate(memory);
}
// @fnv 0x00c409e0
// src: GUESS 0x00c409e0 (confidence: low)
void ShapeList::SetVirtualTable_00c409e0()
{
    vtable = &DAT_010c16dc;
    unsigned index;
    for (index = 0; index < count; ++index)
    {
        delete data[index];
    }
    FreeShapeArray(data);
}

struct FNV_Base_c40aa0
{
    virtual __forceinline ~FNV_Base_c40aa0()
    {}
};

struct FNV_MM_c40aa0
{
    void __thiscall Deallocate(void* p);
};

extern "C" char DAT_011f6238;

struct FUN_00c40aa0 : FNV_Base_c40aa0
{
    int unk04;
    int unk08;
    int unk0c;
    void* m_pData;
    void __thiscall LockFreeQueue_NiPointer_IOTask_RemoveAll_00c41330(int clearAll);
    virtual ~FUN_00c40aa0();
};

// @fnv 0x00c40aa0
FUN_00c40aa0::~FUN_00c40aa0()
{
    LockFreeQueue_NiPointer_IOTask_RemoveAll_00c41330(1);
    void* pData = m_pData;
    void* pvMem = pData;
    ((FNV_MM_c40aa0*)&DAT_011f6238)->Deallocate(pvMem);
}

typedef void* HANDLE;
typedef unsigned long(__stdcall* LPTHREAD_START_ROUTINE)(void*);
void __cdecl FUN_00aa2740(unsigned long, const char*);
struct Semaphore42A
{
    long count;
    HANDLE handle;
    long maximum;
    Semaphore42A()
    {
        count = 0;
        maximum = 0x7fffffff;
        handle = CreateSemaphoreA(0, count, maximum, 0);
    }
    ~Semaphore42A();
};
struct Semaphore42B
{
    long count;
    HANDLE handle;
    long maximum;
    Semaphore42B()
    {
        count = 1;
        maximum = 1;
        handle = CreateSemaphoreA(0, count, maximum, 0);
    }
    ~Semaphore42B();
};
struct FUN_00c42dd0
{
    virtual void vfn();
    HANDLE thread;
    unsigned long threadId;
    Semaphore42A first;
    Semaphore42B second;
    int unk24;
    int unk28;
    unsigned long unk2c;
    FUN_00c42dd0(int, const char* name);
};
// @fnv 0x00c42dd0
FUN_00c42dd0::FUN_00c42dd0(int, const char* name)
{
    thread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)BSTaskThread_ThreadProc, this, 4, &threadId);
    if (name)
        FUN_00aa2740(threadId, name);
    unk24 = 0;
    unk28 = 0;
    unk2c = threadId;
}

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct Pointer354
{
    NiRefObject* value;
    ~Pointer354()
    {
        if (value)
            value->DecRefCount();
    }
};

extern NiTObjectArray<Pointer354> _DAT_01202e20;
struct LockState354
{
    unsigned int owner, recursion;
    void BSSpinLock_Lock(int);
};
extern LockState354 _DAT_01202e40;
unsigned int gm_GetCurrentThreadId();
long BSAtomicCompareExchange(volatile long*, long comparand, long exchange);
void BSSleep(unsigned long);
void ProgramFlow();
// src: XBOX_PDB 0x0040fbf0
inline void LockState354::BSSpinLock_Lock(int)
{
    unsigned int thread = gm_GetCurrentThreadId();
    if (owner == thread)
    {
        ++recursion;
    }
    else
    {
        unsigned int attempts = 0;
        while (BSAtomicCompareExchange((volatile long*)&owner, 0, thread))
        {
            ++attempts;
            if (attempts > 10000)
                BSSleep(1);
            else
                BSSleep(0);
        }
        ProgramFlow();
        recursion = 1;
    }
}
inline unsigned int CleanupDeadline354()
{
    unsigned int start = GetTickCount();
    return start + DAT_011af758;
}
// @fnv 0x00c458f0
// src: COMMUNITY 0x00c458f0
void NiObjectGarbage_Update()
{
    _DAT_01202e40.BSSpinLock_Lock(0);
    unsigned int deadline = CleanupDeadline354();
    unsigned int now5 = 0;
    unsigned int remaining7 = DAT_01202e2c;
    if (remaining7 > 200)
        deadline += 1000;
    for (; remaining7 > 0 && now5 < deadline; --remaining7)
    {
        _DAT_01202e20.RemoveAt(remaining7 - 1);
        now5 = GetTickCount();
    }
    if (remaining7 == 0)
        TruncateStringToMaxLength();
    --DAT_01202e44;
    if (!DAT_01202e44)
        _DAT_01202e40.owner = 0;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct Pointer351
{
    NiRefObject* pointer;
    Pointer351() : pointer(0)
    {
        if (pointer)
            pointer->IncRefCount();
    }
    ~Pointer351()
    {
        if (pointer)
            pointer->DecRefCount();
    }
    static void* operator new[](unsigned int size)
    {
        return g_memoryManager.Allocate(size);
    }
    static void operator delete[](void* memory)
    {
        reinterpret_cast<MemoryManager*>(&g_memoryManager)->Deallocate(memory);
    }
};
// @fnv 0x00c46170
// src: GUESS 0x00c46170 (confidence: low)
void* Runtime_GetIndexedValue_00c46170(unsigned int count)
{
    return new Pointer351[count];
}

struct C46Child
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
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54(NiStream* s);
};
struct C46Class : FUN_00a5e5b0_helper
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8;
    C46Child* m_pChildObject;
    C46Child* GetChild() const
    {
        return m_pChildObject;
    }
    bool BSMultiBoundNode_RegisterStreamables(NiStream* s);
};
// @fnv 0x00c46d10
// src: XBOX_PDB 0x00c46d10
bool C46Class::BSMultiBoundNode_RegisterStreamables(NiStream* s)
{
    if (!RegisterChildStreamables(s))
        return false;
    GetChild()->v54(s);
    return true;
}

extern "C" void* g_01202e74;

struct Node_00c474a0
{
    virtual void vf00();
    virtual void vf04();
    virtual void* vf08();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    Node_00c474a0* next;
};
inline void Node_00c474a0::vf00()
{}
inline void Node_00c474a0::vf04()
{}
inline void* Node_00c474a0::vf08()
{
    return 0;
}

__forceinline bool ContainsActor(Node_00c474a0* p)
{
    bool found;
    if (p == 0)
        found = false;
    else
        found = p->vf08() == &g_01202e74;
    return found;
}

// @fnv 0x00c474a0
// src: XBOX_PDB 0x00c474a0
Node_00c474a0* __cdecl BSMultiBoundNode_FindMultiboundNode(Node_00c474a0* a1)
{
    Node_00c474a0* cur = a1;

    while (cur != 0 && !ContainsActor(cur))
        cur = cur->next;

    if (ContainsActor(cur))
        return cur;

    return 0;
}

struct ChainInner
{
    virtual void v00(), v01(), v02(), v03(), v04(), v05(), v06(), v07();
    virtual void v08(), v09(), v10(), v11(), v12(), v13(), v14(), v15();
    virtual void v16(), v17(), v18(), v19(), v20(), v21(), v22(), v23();
    virtual void v24(), v25(), v26(), v27(), v28(), v29(), v30(), v31();
    virtual void v32(), v33(), v34(), v35(), v36();
    virtual int v37(int a);
};
struct ChainMid
{
    int unk00, unk04, unk08;
    ChainInner* m_0c;
};
struct ChainOwner
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8;
    ChainMid* m_ac;
    ChainInner* GetInner()
    {
        ChainMid* mid = m_ac;
        ChainInner* inner = mid->m_0c;
        return inner;
    }
    int BSMultiBoundNode_CheckBound_00c475c0(int a);
};
// @fnv 0x00c475c0
// src: XBOX_PDB 0x00c475c0
int ChainOwner::BSMultiBoundNode_CheckBound_00c475c0(int a)
{
    int r = GetInner()->v37(a);
    return r;
}

struct SimpleArrayBase
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void Free(void* p);
    void* m_p;
    unsigned int m_uiItemCount;
    unsigned int m_alloc;
    void Clear(bool bFree)
    {
        if (m_p)
        {
            for (unsigned int i = 0; i < m_uiItemCount; i++)
            {
            }
            if (bFree)
            {
                Free(m_p);
                m_p = 0;
                m_p = 0;
                m_alloc = 0;
            }
            m_uiItemCount = 0;
        }
    }
};
struct SimpleArrayA : SimpleArrayBase
{
    ~SimpleArrayA();
};
struct SimpleArrayB : SimpleArrayBase
{
    ~SimpleArrayB();
};
struct FUN_00c47770
{
    int m_00;
    SimpleArrayA m_kList1;
    SimpleArrayB m_kList2;
    ~FUN_00c47770();
};
// @fnv 0x00c47770
FUN_00c47770::~FUN_00c47770()
{
    m_kList1.Clear(true);
    m_kList2.Clear(true);
}

struct TokElem_c48ca0
{
    int iType;
    int a;
    int b;
};
struct TokArr_c48ca0
{
    int _0;
    TokElem_c48ca0* m_pData;
    int _8;
    int m_iCapacity;
    void FUN_00c4a1e0(int, bool);
};
struct TokStack_c48ca0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    TokArr_c48ca0 m_kArray;
    int _24;
    int m_iArrayLength;
    int TopIdx()
    {
        return 0;
    }
    void ShiftElements(int iDelta, bool bClear);
    void ProcessEntries_00c48ca0();
};

// @fnv 0x00c48ca0
// src: GUESS 0x00c48ca0 (confidence: low)
void TokStack_c48ca0::ProcessEntries_00c48ca0()
{
    bool bPush = true;
    if (m_kArray.m_pData[TopIdx()].iType == 4)
    {
        int iLevel = 1;
        int i = 1;
        while (iLevel > 0 && i < m_iArrayLength)
        {
            switch (m_kArray.m_pData[i].iType)
            {
            case 4:
            case 5:
                iLevel++;
                break;
            case 6:
                iLevel--;
                break;
            }
            i++;
        }
        if (i == m_iArrayLength && iLevel == 0)
            bPush = false;
    }
    if (bPush)
    {
        int iCap = m_kArray.m_iCapacity;
        if (m_iArrayLength + 1 >= iCap)
        {
            int iOld = m_kArray.m_iCapacity;
            m_kArray.FUN_00c4a1e0(iOld + 10, true);
        }
        ShiftElements(1, false);
        m_kArray.m_pData[TopIdx()].iType = 4;
    }
    else
    {
        m_iArrayLength--;
    }
}
TokStack_c48ca0 g_ts;
void __cdecl use_all()
{
    g_ts.ProcessEntries_00c48ca0();
}

struct C4F320Child
{
    virtual void v00(), v04(), v08(), v0c(), v10(), v14(), v18(), v1c();
    virtual void v20(), v24(), v28(), v2c(), v30(), v34(), v38(), v3c();
    virtual void v40(), v44(), v48(), v4c(), v50(), v54(), v58(), v5c();
    virtual void v60(), v64(), v68(), v6c(), v70(), v74(), v78(), v7c();
    virtual void v80(), v84(), v88(), v8c(), v90(), v94(), v98();
    virtual void V9c(int a);
};
template <class T> struct C4F320Ptr
{
    T* m_pObject;
    T* operator->() const
    {
        return m_pObject;
    }
    operator T*() const
    {
        return m_pObject;
    }
};
struct C4F320Obj
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc, unkc0;
    C4F320Child* m_pc4;
    C4F320Child* GetChild() const
    {
        return m_pc4;
    }
    void BSCullingProcess_AddShared(int a);
};
// @fnv 0x00c4f320
// src: COMMUNITY 0x00c4f320
void C4F320Obj::BSCullingProcess_AddShared(int a)
{
    GetChild()->V9c(a);
}

__forceinline void* NiFixedString::operator new(size_t size)
{
    return g_memoryManager.Allocate(size);
}
inline void NiFixedString::operator delete(void* memory)
{
    ((MemoryManager*)&g_memoryManager)->Deallocate(memory);
}

inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement((long*)&m_uiRefCount);
}
inline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement((long*)&m_uiRefCount) == 0)
        DeleteThis();
}

__forceinline void NiRefObject::AcquireReference()
{
    InterlockedIncrement((long*)&m_uiRefCount);
}
__forceinline void NiRefObject::DecRef()
{
    if (InterlockedDecrement((long*)&m_uiRefCount) == 0)
        DeleteThis();
}

struct Mgr_00c50b80
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
    virtual void v55();
    virtual void v56();
    virtual void v57(NiRefObject* a1, NiPointer<NiRefObject>& out);
    void BSParticleSystemManager_DetachChild(NiRefObject* a1);
};

// @fnv 0x00c50b80
// src: XBOX_PDB 0x00c50b80
void Mgr_00c50b80::BSParticleSystemManager_DetachChild(NiRefObject* a1)
{
    NiPointer<NiRefObject> tmp(0);
    v57(a1, tmp);
}


class DispatchRefPtr
{
  public:
    NiRefObject* m_pObject;
    __forceinline DispatchRefPtr(NiRefObject* object = 0)
    {
        m_pObject = object;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    __forceinline ~DispatchRefPtr()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
};

class DispatchHelper
{
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
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void Invoke(int a, int b, DispatchRefPtr* out);
    void BSParticleSystemManager_SetAt(int a, int b);
};

// @fnv 0x00c50df0
// src: XBOX_PDB 0x00c50df0
void DispatchHelper::BSParticleSystemManager_SetAt(int a, int b)
{
    DispatchRefPtr ref;
    Invoke(a, b, &ref);
}

struct RefTarget
{
    virtual void Reserved();
    virtual void DeleteThis();
    volatile long refCount;
};
struct ScopedRef
{
    RefTarget* object;
    __forceinline ScopedRef() : object(0)
    {
        if (object)
        {
            RefTarget* retained = object;
            InterlockedIncrement(&retained->refCount);
        }
    }
    __forceinline ~ScopedRef()
    {
        if (object)
        {
            RefTarget* released = object;
            if (InterlockedDecrement(&released->refCount) == 0)
                released->DeleteThis();
        }
    }
};
struct Owner
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
    virtual void v55();
    virtual void v56();
    virtual void GetRefTarget(int, RefTarget**);
    void BSParticleSystemManager_RemoveMasterParticleSystem_00c51700(int);
};
// @fnv 0x00c51700
// src: XBOX_PDB 0x00c51700
void Owner::BSParticleSystemManager_RemoveMasterParticleSystem_00c51700(int arg)
{
    ScopedRef ptr;
    GetRefTarget(arg, &ptr.object);
}

extern "C" char DAT_011f6238;
struct HeapAB
{
    void MemoryManager_Deallocate(void* pObject);
};
void __cdecl _NiFree_00aa10f0(void* p);
inline void FreeAB(void* p)
{
    _NiFree_00aa10f0(p);
}

struct ItemAB
{
    void* m_pData;
    ~ItemAB()
    {
        FreeAB(m_pData);
    }
    static void operator delete(void* p)
    {
        ((HeapAB*)&DAT_011f6238)->MemoryManager_Deallocate(p);
    }
};
template <> __forceinline void NiTArray<ItemAB*, NiTMallocInterface<ItemAB*> >::RemoveAll()
{
    for (unsigned short i = 0; i < m_usSize; i++)
        m_pBase[i] = 0;
    m_usSize = 0;
    m_usESize = 0;
}

struct OwnerAB
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38;
    NiTPrimitiveArray<ItemAB*> m_kArray;
    void NiBSBoneLODController_CleanUp();
};
// @fnv 0x00c52880
// src: XBOX_PDB 0x00c52880
void OwnerAB::NiBSBoneLODController_CleanUp()
{
    for (unsigned int i = 0; i < m_kArray.GetSize(); i++)
    {
        ItemAB* pkItem = m_kArray.GetAt(i);
        delete pkItem;
    }
    m_kArray.RemoveAll();
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct Heap_c55
{
    void Deallocate(void* apMem);
};
extern int EmptyFS_c55;
extern NiFixedString* g_pkString_c55;
// @fnv 0x00c552a0
// src: GUESS 0x00c552a0 (confidence: low)
void Object_UpdateFields_00c552a0()
{
    delete g_pkString_c55;
    g_pkString_c55 = 0;
}

void* __cdecl Object_DispatchCommandFour(unsigned int);
struct Vec3A
{
    float x, y, z;
    Vec3A()
    {}
    Vec3A(float a, float b, float c) : x(a), y(b), z(c)
    {}
};
struct Vec2A
{
    float x, y;
    Vec2A()
    {}
    Vec2A(float a, float b) : x(a), y(b)
    {}
};
struct ColorA
{
    float r, g, b, a;
    ColorA() : r(0), g(0), b(0), a(0)
    {}
};
extern const NiPoint3 DAT_011a9484;



inline void* __cdecl operator new[](unsigned int size)
{
    return g_memoryManager.Allocate(size);
}
// @fnv 0x00c55360
#pragma intrinsic(memcpy)
// src: COMMUNITY 0x00c55360
NiTriShape* __cdecl BSTestObjects_CreateSquare(float extent, NiPoint3* center, ColorA* color)
{
    NiPoint3* srcPtr4 = center ? center : &DAT_011f426c;
    float centerVal2[3];
    memcpy(&centerVal2, srcPtr4, sizeof(centerVal2));
    Vec3A* verts = new Vec3A[4];
    Vec3A* normals = new Vec3A[4];
    ColorA* colors = color ? new ColorA[4] : 0;
    Vec2A* tex = new Vec2A[4];
    unsigned short* indices = new unsigned short[6];
    verts[0] = Vec3A(centerVal2[0] - extent, centerVal2[1] + extent, 0.0f);
    normals[0] = *(const Vec3A*)&DAT_011a9484;
    if (color)
        colors[0] = *color;
    tex[0] = Vec2A(0.0f, 0.0f);
    verts[1] = Vec3A(centerVal2[0] + extent, centerVal2[1] + extent, 0.0f);
    normals[1] = *(const Vec3A*)&DAT_011a9484;
    if (color)
        colors[1] = *color;
    tex[1] = Vec2A(1.0f, 0.0f);
    verts[2] = Vec3A(centerVal2[0] - extent, centerVal2[1] - extent, 0.0f);
    normals[2] = *(const Vec3A*)&DAT_011a9484;
    if (color)
        colors[2] = *color;
    tex[2] = Vec2A(0.0f, 1.0f);
    verts[3] = Vec3A(centerVal2[0] + extent, centerVal2[1] - extent, 0.0f);
    normals[3] = *(const Vec3A*)&DAT_011a9484;
    if (color)
        colors[3] = *color;
    tex[3] = Vec2A(1.0f, 1.0f);
    indices[0] = 0;
    indices[1] = 1;
    indices[2] = 2;
    indices[3] = 2;
    indices[4] = 1;
    indices[5] = 3;
    NiTriShape* shape5 =
        new NiTriShape(4, (NiPoint3*)verts, (NiPoint3*)normals, colors, (NiPoint2*)tex, 0, 0, 2, indices);
    shape5->CalculateNormals();
    return shape5;
}

struct RefObj5b : NiRefObject
{

    virtual ~RefObj5b();

    virtual void DeleteThis();


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

    unsigned int m_uiValue1;

    void SetBit(bool bVal, unsigned int uiMask)
    {

        if (bVal)
            m_uiValue1 |= uiMask;

        else
            m_uiValue1 &= ~uiMask;
    }
};

struct SPtr5b
{

    RefObj5b* m_pObject;

    SPtr5b(const SPtr5b& other)
    {

        m_pObject = other.m_pObject;

        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }

    ~SPtr5b()
    {

        if (m_pObject)
        {

            m_pObject->DecRefCount();
        }
    }

    operator RefObj5b*() const
    {
        return m_pObject;
    }

    RefObj5b* operator->() const
    {
        return m_pObject;
    }

    bool operator==(RefObj5b* p) const
    {
        return m_pObject == p;
    }
};



struct Owner5b
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

    NiTObjectArray<SPtr5b> m_kArray;

    SPtr5b* m_pBase;

    unsigned short unk44;

    unsigned short m_usSize;

    void BSPortalGraph_DetachQAlwaysRenderChild(RefObj5b* pkObj);
};

// @fnv 0x00c5b740
// src: COMMUNITY 0x00c5b740
void Owner5b::BSPortalGraph_DetachQAlwaysRenderChild(RefObj5b* pkObj)

{

    for (unsigned int i = 0; i < m_kArray.m_usSize; i++)
    {

        SPtr5b pSceneObject = m_kArray.GetAt(i);

        if (pSceneObject && pSceneObject == pkObj)
        {

            m_kArray.RemoveAtAndFill(i);

            pSceneObject->SetBit(false, 1);

            break;
        }
    }
}

struct EmptyBase332
{
    ~EmptyBase332()
    {}
};
int FUN_004019a0(long*);
unsigned int NiAtomicIncrement_0040b460(void*);
inline void PathingSolution::DecRefCount()
{
    if (!FUN_004019a0((long*)&m_uiRefCount))
        DeleteThis();
}
inline void PathingSolution::IncRefCount()
{
    NiAtomicIncrement_0040b460(&m_uiRefCount);
}
struct PathReference332
{
    PathingSolution* value;
    void Reset(PathingSolution* replacement)
    {
        if (value != replacement)
        {
            if (value)
                value->DecRefCount();
            value = replacement;
            if (value)
                value->IncRefCount();
        }
    }
};
struct ListNode332
{
    ListNode332* next;
    ListNode332* previous;
    PathReference332 path;
};
void ProgramFlow();
unsigned int gm_GetCurrentThreadId();
long BSAtomicCompareExchange(volatile long* target, long comparand, long exchange);
void BSSleep(unsigned long);
struct PoolLock332
{
    volatile long owner;
    unsigned int recursion;
    void Lock(const char*)
    {
        unsigned int thread = gm_GetCurrentThreadId();
        if ((unsigned int)owner == thread)
        {
            ++recursion;
        }
        else
        {
            unsigned int attempts = 0;
            while (BSAtomicCompareExchange(&owner, 0, thread))
            {
                ++attempts;
                BSSleep(attempts > 10000 ? 1 : 0);
            }
            ProgramFlow();
            recursion = 1;
        }
    }
    void Unlock()
    {
        ProgramFlow();
        --recursion;
        if (!recursion)
            owner = 0;
    }
};
extern PoolLock332 g_011c5f80;
extern ListNode332* NiTAbstractPoolAllocator_unsigned_int_instance;
struct Pool332
{
    unsigned int count;
// src: XBOX_PDB 0x0045cee0
    void NiTPointerAllocator_unsigned_int_Deallocate(void* memory)
    {
        g_011c5f80.Lock(0);
        ListNode332* node = (ListNode332*)memory;
        node->previous = 0;
        node->next = NiTAbstractPoolAllocator_unsigned_int_instance;
        NiTAbstractPoolAllocator_unsigned_int_instance = node;
        g_011c5f80.Unlock();
    }
};
struct List332 : EmptyBase332
{
    ListNode332* head;
    ListNode332* tail;
    Pool332 pool;
// src: XBOX_PDB 0x004a4930
    void NiTPointerListBase_NiTPointerAllocator_unsigned_int_NiPointer_BSMultiBoundRoom_DeleteItem(void* memory)
    {
        ((ListNode332*)memory)->path.Reset(0);
        pool.NiTPointerAllocator_unsigned_int_Deallocate(memory);
    }
// src: XBOX_PDB 0x004a4650
    void NiTPointerListBase_NiTPointerAllocator_unsigned_int_NiPointer_BSMultiBoundRoom_RemoveAll()
    {
        ListNode332* current = head;
        while (current)
        {
            ListNode332* retired = current;
            current = current->next;
            NiTPointerListBase_NiTPointerAllocator_unsigned_int_NiPointer_BSMultiBoundRoom_DeleteItem(retired);
        }
        pool.count = 0;
        head = 0;
        tail = 0;
    }
};
struct FUN_00c5bb10 : List332
{
    ~FUN_00c5bb10();
};
// @fnv 0x00c5bb10
FUN_00c5bb10::~FUN_00c5bb10()
{
    NiTPointerListBase_NiTPointerAllocator_unsigned_int_NiPointer_BSMultiBoundRoom_RemoveAll();
}


struct RefPtrSI
{
    NiRefObject* m_pObject;
    RefPtrSI(const RefPtrSI& o) : m_pObject(o.m_pObject)
    {
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    ~RefPtrSI()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
    bool operator==(const RefPtrSI& o) const
    {
        return m_pObject == o.m_pObject;
    }
};

typedef NiTListItem<RefPtrSI > ListItemSI;

struct MapSI
{
    ListItemSI* m_pkHead;
    ListItemSI* GetHeadPos() const
    {
        return m_pkHead;
    }
    RefPtrSI& GetNext(ListItemSI*& pos) const
    {
        RefPtrSI& e = pos->m_element;
        pos = pos->m_pkNext;
        return e;
    }
    ListItemSI* FindPos(const RefPtrSI& key, ListItemSI* pos = 0) const
    {
        if (!pos)
            pos = GetHeadPos();
        while (pos)
        {
            ListItemSI* cur = pos;
            if (key == GetNext(pos))
                return cur;
        }
        return 0;
    }
    RefPtrSI Resolve(ListItemSI* const& pos);
    RefPtrSI ProcessAndReturnValue_00c5bda0(const RefPtrSI& key);
};

// @fnv 0x00c5bda0
// src: GUESS 0x00c5bda0 (confidence: low)
RefPtrSI MapSI::ProcessAndReturnValue_00c5bda0(const RefPtrSI& key)
{
    ListItemSI* pos = FindPos(key);
    return pos ? Resolve(pos) : key;
}

void* NiMalloc660(unsigned int uiSize);
void NiFree660(void* p);

template <> inline void** NiTMallocInterface<void*>::Allocate(unsigned int auiCount)
    {
        return (void**)NiMalloc660(sizeof(void*) * auiCount);
    }

template <> inline void NiTArray<void*, NiTMallocInterface<void*> >::SetSize(unsigned int uiMaxSize)
    {
        if (uiMaxSize == m_usMaxSize)
            return;
        unsigned int i;
        if (uiMaxSize < m_usSize)
        {
            for (i = uiMaxSize; i < m_usSize; i++)
            {
                if (m_pBase[i] != (void*)0)
                {
                    m_pBase[i] = (void*)0;
                    m_usESize--;
                }
            }
            m_usSize = (unsigned short)uiMaxSize;
        }
        void** pSaveBase = m_pBase;
        m_usMaxSize = (unsigned short)uiMaxSize;
        if (uiMaxSize > 0)
        {
            m_pBase = NiTMallocInterface<void*>::Allocate(m_usMaxSize);
            for (i = 0; i < m_usSize; i++)
                m_pBase[i] = pSaveBase[i];
            for (i = m_usSize; i < m_usMaxSize; i++)
                m_pBase[i] = (void*)0;
        }
        else
        {
            m_pBase = 0;
        }
        NiFree660(pSaveBase);
    }

template <> inline void NiTArray<void*, NiTMallocInterface<void*> >::SetAt(unsigned int uiIndex, void* const& element)
    {
        if (uiIndex >= m_usSize)
        {
            m_usSize = (unsigned short)(uiIndex + 1);
            if (element != (void*)0)
                m_usESize++;
        }
        else
        {
            if (element != (void*)0)
            {
                if (m_pBase[uiIndex] == (void*)0)
                    m_usESize++;
            }
            else
            {
                if (m_pBase[uiIndex] != (void*)0)
                    m_usESize--;
            }
        }
        m_pBase[uiIndex] = element;
    }


struct Stream660
{
    int m_00;
    unsigned int m_uiFormatVersion;
    unsigned int FUN_00a63460();
    void* FUN_00a63430();
};

struct Base660
{
    void ReadChildListFromStream(Stream660* pkStream);
};

struct Obj660 : Base660
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    int unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC;
    int unkC0, unkC4, unkC8;
    NiTPrimitiveArray<void*> m_kLinks;

    void BSMasterParticleSystem_LinkObject(Stream660* pkStream);
};

// @fnv 0x00c5e660
// src: XBOX_PDB 0x00c5e660
void Obj660::BSMasterParticleSystem_LinkObject(Stream660* pkStream)
{
    Base660::ReadChildListFromStream(pkStream);
    if (pkStream->m_uiFormatVersion > 0xf)
    {
        unsigned int ItemUpdateArray = pkStream->FUN_00a63460();
        if (ItemUpdateArray)
        {
            m_kLinks.SetSize(ItemUpdateArray);
            for (unsigned int i = 0; i < ItemUpdateArray; i++)
            {
                void* pkLink = pkStream->FUN_00a63430();
                m_kLinks.SetAt(i, pkLink);
            }
        }
    }
}

struct Key8
{
    int a;
    int b;
};
struct Lock40
{
    int owner;
    int count;
    void BSSpinLock_Lock(int a);
    void Unlock()
    {
        count--;
        if (count == 0)
            owner = 0;
    }
};
struct Iter40
{
    int u00;
    int u04;
    unsigned int idx;
    int u0C;
    __int64 key;
    unsigned char flags;
    bool GetFlag1()
    {
        return (flags & 1) ? true : false;
    }
    bool GetFlag2()
    {
        int aiD[46];
        return flags & 2;
    }
    void SetFlag1(bool v)
    {
        if (v)
            flags |= 1;
        else
            flags &= ~1;
    }
    void SetFlag2(bool v)
    {
        if (v)
            flags |= 2;
        else
            flags &= ~2;
    }
};
struct Bucket40
{
    bool LockFreeMap_int64_NiPointer_BSTask_int64_LockFreeMapInterface_GetFirst(__int64* k, int arg);
    bool LockFreeMap_int64_NiPointer_BSTask_int64_LockFreeMapInterface_GetNext(__int64* k, int arg);
};
class Map40
{
  public:
    int u00;
    int u04;
    unsigned int cap;
    int u0C, u10, u14, u18, u1C;
    Lock40 lock;
    Bucket40* LockFreeMap_GetInterface(unsigned int idx);
    unsigned int GetCap()
    {
        return cap;
    }
    bool LockFreeMap_int64_NiPointer_BSTask_int64_GetNext(Iter40* it, __int64* out, int arg, bool b);
};
// @fnv 0x00c40e70
// src: COMMUNITY 0x00c40e70
bool Map40::LockFreeMap_int64_NiPointer_BSTask_int64_GetNext(Iter40* it, __int64* out, int arg, bool b)
{
    lock.BSSpinLock_Lock(0);
    bool r = false;
    if (it->GetFlag2())
    {
        r = false;
    }
    else
    {
        while (1)
        {
            if (!it->GetFlag1())
            {
                r = LockFreeMap_GetInterface(it->idx)->LockFreeMap_int64_NiPointer_BSTask_int64_LockFreeMapInterface_GetFirst(&it->key, arg);
                it->SetFlag1(true);
            }
            else
            {
                r = LockFreeMap_GetInterface(it->idx)->LockFreeMap_int64_NiPointer_BSTask_int64_LockFreeMapInterface_GetNext(&it->key, arg);
            }
            if (!r)
            {
                it->idx++;
                if (it->idx >= GetCap())
                {
                    it->SetFlag2(true);
                }
                else if (b)
                {
                    it->SetFlag1(false);
                    continue;
                }
            }
            else
            {
                *out = it->key;
            }
            break;
        }
    }
    lock.Unlock();
    return r;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);

struct MM
{
    void* Allocate(unsigned int size);
    void Deallocate(void* p);
};
extern MM _g_memoryManager;

extern __declspec(thread) int g_tlsHeapState;

__forceinline int GetTlsHeapState()
{
    return g_tlsHeapState;
}
__forceinline void SetTlsHeapState(int v)
{
    g_tlsHeapState = v;
}

struct TlsHeapStateGuard
{
    int saved;
    __forceinline TlsHeapStateGuard(int v)
    {
        saved = GetTlsHeapState();
        SetTlsHeapState(v);
    }
    __forceinline ~TlsHeapStateGuard()
    {
        SetTlsHeapState(saved);
    }
};

struct QueueRefObj
{
    int unk00;
    int unk04;
    volatile long refCount;
    void BSTask_int64_DecRefCount();
    __forceinline void AcquireReference()
    {
        InterlockedIncrement(&refCount);
    }
};

struct QueueRefPtr
{
    QueueRefObj* m_p;
    __forceinline QueueRefPtr(QueueRefObj* p = 0)
    {
        m_p = p;
        if (m_p)
            m_p->AcquireReference();
    }
    __forceinline ~QueueRefPtr()
    {
        if (m_p)
            m_p->BSTask_int64_DecRefCount();
    }
    __forceinline QueueRefPtr& operator=(QueueRefObj* p)
    {
        if (m_p != p)
        {
            if (m_p)
                m_p->BSTask_int64_DecRefCount();
            m_p = p;
            if (m_p)
                m_p->AcquireReference();
        }
        return *this;
    }
};

struct HandlerRegistration
{
    HandlerRegistration* next;
    QueueRefPtr item;
    __forceinline HandlerRegistration() : next(0)
    {}
    __forceinline static void* operator new(unsigned int size)
    {
        return _g_memoryManager.Allocate(size);
    }
    __forceinline static void operator delete(void* p)
    {
        _g_memoryManager.Deallocate(p);
    }
};

struct InnerOwnedItem
{
    ~InnerOwnedItem();
    static void operator delete(void* p)
    {
        _g_memoryManager.Deallocate(p);
    }
};
struct InnerEntry
{
    unsigned int key;
    InnerOwnedItem* object;
};

struct Inner
{
    unsigned int unk00;
    void* unk04;
    InnerEntry* unk08;
    int unk0C;
    __forceinline int GetCount()
    {
        return unk00;
    }
    Inner(int a);
    ~Inner()
    {
        for (unsigned int i = 0; i < unk00; ++i)
            delete unk08[i].object;
        _g_memoryManager.Deallocate(unk08);
        DAT_0fdf050(unk04);
    }
    __forceinline static void* operator new(unsigned int size)
    {
        return _g_memoryManager.Allocate(size);
    }
    __forceinline static void operator delete(void* p)
    {
        _g_memoryManager.Deallocate(p);
    }
};

unsigned int gm_GetCurrentThreadId();
void BSSleep(unsigned long);
void ProgramFlow();

struct Lock
{
    int owner;
    int count;
    void Acquire(const char* name)
    {
        unsigned int currentThread = gm_GetCurrentThreadId();
        if (owner == currentThread)
        {
            count = count + 1;
        }
        else
        {
            unsigned int spins = 0;
            while (BSAtomicCompareExchange((volatile long*)&owner, 0, currentThread))
            {
                spins = spins + 1;
                if (spins > 10000)
                    BSSleep(1);
                else
                    BSSleep(0);
            }
            ProgramFlow();
            count = 1;
        }
    }
    __forceinline void Release()
    {
        count = count - 1;
        if (count == 0)
            owner = 0;
    }
};

struct Queue
{
    int unk00;
    HandlerRegistration* head;
    HandlerRegistration* tail;
    int unk0C;
    int unk10;
    Inner* inner;
    int unk18;
    int unk1C;
    Lock lock;
    void LockFreeQueue_NiPointer_IOTask_RemoveAll_00c41330(bool keep);
};

// @fnv 0x00c41330
// src: COMMUNITY 0x00c41330
void Queue::LockFreeQueue_NiPointer_IOTask_RemoveAll_00c41330(bool keep)
{
    lock.Acquire(0);
    TlsHeapStateGuard guard(6);
    int first = inner->GetCount();
    delete inner;
    inner = 0;
    unk18 = 0;
    while (head)
    {
        HandlerRegistration* next = head->next;
        head->item = 0;
        delete head;
        head = next;
    }
    if (!keep)
    {
        head = new HandlerRegistration;
        tail = head;
        inner = new Inner(first);
    }
    lock.Release();
}

#pragma function(memcpy)
namespace fnv_00c416a0 {
// Byte-identical with the pack's accepted /Ob1 flag set (1044 bytes).
// Nested declaration scopes preserve slot order; unused retains the 16-byte frame gap.
struct HandlerRegistration;
struct QueuePtr
{
    unsigned int bits;
    void LockFreeMap_MarkedPointer_SetMark(bool);
};
struct HandlerRegistration
{
    NodeKey key;
    unsigned int object;
    QueuePtr next;
};
__forceinline unsigned int MaskExplicit(QueuePtr* p)
{
    return p->bits & ~1u;
}
struct QueueHandler
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
    virtual bool Test(NodeKey, NodeKey);
    virtual bool Result(NodeKey, NodeKey);
    int padding04, padding08;
    QueuePtr* buckets;
};
extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(volatile long*, long, long);
struct QueueSearch
{
    QueueHandler* handler;
    HandlerRegistration** outNext;
    HandlerRegistration** outCurrent;
    HandlerRegistration** outPrevious;
    QueuePtr* link;
    QueuePtr current;
    QueuePtr next;
    void LockFreeMap_TESObjectREFR_NiPointer_QueuedReference_LockFreeMapInterface_DeleteNode(HandlerRegistration*);
    bool LockFreeMapInterface_Find_0(int index, NodeKey key);
};
// @fnv 0x00c416a0
// src: COMMUNITY 0x00c416a0
bool QueueSearch::LockFreeMapInterface_Find_0(int index, NodeKey key)
{
    QueuePtr* bucket;
    {
        bool retry;
        {
            QueuePtr initial;
            {
                QueuePtr expected;
                {
                    NodeKey found;
                    {
                        QueuePtr replacement;
                        {
                            QueuePtr* t20;
                            {
                                QueuePtr* t24;
                                {
                                    unsigned int t28;
                                    {
                                        QueuePtr* t2c;
                                        {
                                            unsigned int t30;
                                            {
                                                QueuePtr* t34;
                                                {
                                                    QueuePtr* t38;
                                                    {
                                                        QueuePtr* t3c;
                                                        {
                                                            QueuePtr* t40;
                                                            {
                                                                QueuePtr* t44;
                                                                {
                                                                    unsigned int t48;
                                                                    {
                                                                        QueuePtr* t4c;
                                                                        {
                                                                            HandlerRegistration* t50;
                                                                            {
                                                                                QueuePtr* t54;
                                                                                {
                                                                                    QueuePtr* t58;
                                                                                    {
                                                                                        QueuePtr* t5c;
                                                                                        {
                                                                                            QueuePtr* t60;
                                                                                            {
                                                                                                unsigned int t64;
                                                                                                {
                                                                                                    QueuePtr* t68;
                                                                                                    {
                                                                                                        unsigned int
                                                                                                            t6c;
                                                                                                        {
                                                                                                            QueuePtr*
                                                                                                                t70;
                                                                                                            {
                                                                                                                QueuePtr*
                                                                                                                    t74;
                                                                                                                {
                                                                                                                    QueuePtr*
                                                                                                                        t78;
                                                                                                                    {
                                                                                                                        QueuePtr*
                                                                                                                            t7c;
                                                                                                                        {
                                                                                                                            QueuePtr*
                                                                                                                                t80;
                                                                                                                            {
                                                                                                                                QueuePtr*
                                                                                                                                    t84;
                                                                                                                                {
                                                                                                                                    unsigned int
                                                                                                                                        t88;
                                                                                                                                    {
                                                                                                                                        QueuePtr*
                                                                                                                                            t8c;
                                                                                                                                        {
                                                                                                                                            unsigned int
                                                                                                                                                t90;
                                                                                                                                            {
                                                                                                                                                QueuePtr*
                                                                                                                                                    t94;
                                                                                                                                                {
                                                                                                                                                    unsigned int
                                                                                                                                                        t98;
                                                                                                                                                    {
                                                                                                                                                        bool
                                                                                                                                                            t99;
                                                                                                                                                        {
                                                                                                                                                            QueuePtr*
                                                                                                                                                                ta0;
                                                                                                                                                            {
                                                                                                                                                                QueuePtr*
                                                                                                                                                                    ta4;
                                                                                                                                                                {
                                                                                                                                                                    struct
                                                                                                                                                                        Unused
                                                                                                                                                                    {
                                                                                                                                                                        int a,
                                                                                                                                                                            b,
                                                                                                                                                                            c,
                                                                                                                                                                            d;
                                                                                                                                                                    } unused;
                                                                                                                                                                    {
                                                                                                                                                                        QueuePtr*
                                                                                                                                                                            tb8;
                                                                                                                                                                        bucket =
                                                                                                                                                                            &handler
                                                                                                                                                                                 ->buckets
                                                                                                                                                                                     [index];
                                                                                                                                                                        while (
                                                                                                                                                                            true)
                                                                                                                                                                        {
                                                                                                                                                                            retry =
                                                                                                                                                                                false;
                                                                                                                                                                            link =
                                                                                                                                                                                bucket;
                                                                                                                                                                            current =
                                                                                                                                                                                *link;
                                                                                                                                                                            t20 =
                                                                                                                                                                                &current;
                                                                                                                                                                            *outCurrent =
                                                                                                                                                                                (HandlerRegistration*)
                                                                                                                                                                                    MaskExplicit(
                                                                                                                                                                                        t20);
                                                                                                                                                                            t24 =
                                                                                                                                                                                &current;
                                                                                                                                                                            t28 =
                                                                                                                                                                                t24->bits &
                                                                                                                                                                                ~1u;
                                                                                                                                                                            initial
                                                                                                                                                                                .bits =
                                                                                                                                                                                t28;
                                                                                                                                                                            initial
                                                                                                                                                                                .LockFreeMap_MarkedPointer_SetMark(
                                                                                                                                                                                    false);
                                                                                                                                                                            t2c =
                                                                                                                                                                                link;
                                                                                                                                                                            t30 =
                                                                                                                                                                                t2c->bits;
                                                                                                                                                                            t34 =
                                                                                                                                                                                &initial;
                                                                                                                                                                            if (t30 !=
                                                                                                                                                                                (volatile unsigned int&)
                                                                                                                                                                                    t34->bits)
                                                                                                                                                                                continue;
                                                                                                                                                                            while (
                                                                                                                                                                                true)
                                                                                                                                                                            {
                                                                                                                                                                                t38 =
                                                                                                                                                                                    &current;
                                                                                                                                                                                if (!(t38->bits &
                                                                                                                                                                                      ~1u))
                                                                                                                                                                                    return false;
                                                                                                                                                                                t3c =
                                                                                                                                                                                    &current;
                                                                                                                                                                                next =
                                                                                                                                                                                    ((HandlerRegistration*)(t3c->bits &
                                                                                                                                                                                                            ~1u))
                                                                                                                                                                                        ->next;
                                                                                                                                                                                t40 =
                                                                                                                                                                                    &next;
                                                                                                                                                                                *outNext =
                                                                                                                                                                                    (HandlerRegistration*)
                                                                                                                                                                                        MaskExplicit(
                                                                                                                                                                                            t40);
                                                                                                                                                                                t44 =
                                                                                                                                                                                    &next;
                                                                                                                                                                                t48 =
                                                                                                                                                                                    t44->bits;
                                                                                                                                                                                t4c =
                                                                                                                                                                                    &current;
                                                                                                                                                                                t50 =
                                                                                                                                                                                    (HandlerRegistration*)(t4c->bits &
                                                                                                                                                                                                           ~1u);
                                                                                                                                                                                t54 =
                                                                                                                                                                                    &t50->next;
                                                                                                                                                                                if (t48 !=
                                                                                                                                                                                    (volatile unsigned int&)
                                                                                                                                                                                        t54->bits)
                                                                                                                                                                                {
                                                                                                                                                                                    retry =
                                                                                                                                                                                        true;
                                                                                                                                                                                    break;
                                                                                                                                                                                }
                                                                                                                                                                                t58 =
                                                                                                                                                                                    &current;
                                                                                                                                                                                *(__int64*)&found =
                                                                                                                                                                                    *(__int64*)&(
                                                                                                                                                                                         (HandlerRegistration*)(t58->bits &
                                                                                                                                                                                                                ~1u))
                                                                                                                                                                                         ->key;
                                                                                                                                                                                t5c =
                                                                                                                                                                                    &current;
                                                                                                                                                                                t64 =
                                                                                                                                                                                    t5c->bits &
                                                                                                                                                                                    ~1u;
                                                                                                                                                                                expected
                                                                                                                                                                                    .bits =
                                                                                                                                                                                    t64;
                                                                                                                                                                                t60 =
                                                                                                                                                                                    &expected;
                                                                                                                                                                                if (false)
                                                                                                                                                                                    t60->bits |=
                                                                                                                                                                                        1;
                                                                                                                                                                                else
                                                                                                                                                                                    t60->bits &=
                                                                                                                                                                                        ~1u;
                                                                                                                                                                                t68 =
                                                                                                                                                                                    link;
                                                                                                                                                                                t6c =
                                                                                                                                                                                    t68->bits;
                                                                                                                                                                                t70 =
                                                                                                                                                                                    &expected;
                                                                                                                                                                                if (t6c !=
                                                                                                                                                                                    (volatile unsigned int&)
                                                                                                                                                                                        t70->bits)
                                                                                                                                                                                {
                                                                                                                                                                                    retry =
                                                                                                                                                                                        true;
                                                                                                                                                                                    break;
                                                                                                                                                                                }
                                                                                                                                                                                t74 =
                                                                                                                                                                                    &next;
                                                                                                                                                                                if ((unsigned char)((t74->bits &
                                                                                                                                                                                                     1) !=
                                                                                                                                                                                                    0) ==
                                                                                                                                                                                    0)
                                                                                                                                                                                {
                                                                                                                                                                                    if (handler
                                                                                                                                                                                            ->Test(
                                                                                                                                                                                                found,
                                                                                                                                                                                                key))
                                                                                                                                                                                        return handler
                                                                                                                                                                                            ->Result(
                                                                                                                                                                                                found,
                                                                                                                                                                                                key);
                                                                                                                                                                                    t78 =
                                                                                                                                                                                        &current;
                                                                                                                                                                                    link =
                                                                                                                                                                                        &((HandlerRegistration*)(t78->bits &
                                                                                                                                                                                                                 ~1u))
                                                                                                                                                                                             ->next;
                                                                                                                                                                                    t7c =
                                                                                                                                                                                        &current;
                                                                                                                                                                                    *outPrevious =
                                                                                                                                                                                        (HandlerRegistration*)
                                                                                                                                                                                            MaskExplicit(
                                                                                                                                                                                                t7c);
                                                                                                                                                                                }
                                                                                                                                                                                else
                                                                                                                                                                                {
                                                                                                                                                                                    t80 =
                                                                                                                                                                                        &next;
                                                                                                                                                                                    t88 =
                                                                                                                                                                                        t80->bits &
                                                                                                                                                                                        ~1u;
                                                                                                                                                                                    replacement
                                                                                                                                                                                        .bits =
                                                                                                                                                                                        t88;
                                                                                                                                                                                    t84 =
                                                                                                                                                                                        &replacement;
                                                                                                                                                                                    if (false)
                                                                                                                                                                                        t84->bits |=
                                                                                                                                                                                            1;
                                                                                                                                                                                    else
                                                                                                                                                                                        t84->bits &=
                                                                                                                                                                                            ~1u;
                                                                                                                                                                                    t8c =
                                                                                                                                                                                        &expected;
                                                                                                                                                                                    t90 =
                                                                                                                                                                                        t8c->bits;
                                                                                                                                                                                    t94 =
                                                                                                                                                                                        &replacement;
                                                                                                                                                                                    t98 =
                                                                                                                                                                                        t94->bits;
                                                                                                                                                                                    ta0 =
                                                                                                                                                                                        link;
                                                                                                                                                                                    t99 =
                                                                                                                                                                                        InterlockedCompareExchange(
                                                                                                                                                                                            (volatile long*)
                                                                                                                                                                                                ta0,
                                                                                                                                                                                            t98,
                                                                                                                                                                                            t90) ==
                                                                                                                                                                                        t90;
                                                                                                                                                                                    if (t99)
                                                                                                                                                                                    {
                                                                                                                                                                                        ta4 =
                                                                                                                                                                                            &current;
                                                                                                                                                                                        LockFreeMap_TESObjectREFR_NiPointer_QueuedReference_LockFreeMapInterface_DeleteNode((
                                                                                                                                                                                            HandlerRegistration*)(ta4->bits &
                                                                                                                                                                                                                  ~1u));
                                                                                                                                                                                    }
                                                                                                                                                                                    else
                                                                                                                                                                                    {
                                                                                                                                                                                        retry =
                                                                                                                                                                                            true;
                                                                                                                                                                                        break;
                                                                                                                                                                                    }
                                                                                                                                                                                }
                                                                                                                                                                                current =
                                                                                                                                                                                    next;
                                                                                                                                                                                tb8 =
                                                                                                                                                                                    &next;
                                                                                                                                                                                *outCurrent =
                                                                                                                                                                                    (HandlerRegistration*)
                                                                                                                                                                                        MaskExplicit(
                                                                                                                                                                                            tb8);
                                                                                                                                                                            }
                                                                                                                                                                            if (retry)
                                                                                                                                                                                continue;
                                                                                                                                                                        }
                                                                                                                                                                    }
                                                                                                                                                                }
                                                                                                                                                            }
                                                                                                                                                        }
                                                                                                                                                    }
                                                                                                                                                }
                                                                                                                                            }
                                                                                                                                        }
                                                                                                                                    }
                                                                                                                                }
                                                                                                                            }
                                                                                                                        }
                                                                                                                    }
                                                                                                                }
                                                                                                            }
                                                                                                        }
                                                                                                    }
                                                                                                }
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
}  // namespace fnv_00c416a0

struct RttiX
{
    const char* m_pcName;
    const RttiX* m_pBaseRTTI;
};
extern RttiX DAT_011f4aa0;
extern int DAT_010c195c;
struct ObjX
{
    virtual void v00();
    virtual void v01();
    virtual const RttiX* GetRTTI() const;
};
inline bool IsDerivedType(const RttiX* pkRTTI, const RttiX* pkTarget)
{
    while (pkRTTI)
    {
        if (pkRTTI == pkTarget)
            return true;
        pkRTTI = pkRTTI->m_pBaseRTTI;
    }
    return false;
}
inline bool IsKindOfType(const RttiX& kRTTI, const ObjX* pkObj)
{
    if (!pkObj)
        return false;
    return IsDerivedType(pkObj->GetRTTI(), &kRTTI);
}
struct AVX : ObjX
{
    char pad[0xa8];
    unsigned short m_usFlags;
    unsigned short GetField(unsigned short usMask, unsigned short usPos) const
    {
        return (m_usFlags & usMask) >> usPos;
    }
};
struct FUN_00c5f680
{
    char pad[0xac];
    unsigned char m_ucFlags;
    FUN_00c5f680(AVX* pkObj, int i);
    ~FUN_00c5f680();
    void SetBit(bool bVal, unsigned char ucMask)
    {
        if (bVal)
            m_ucFlags |= ucMask;
        else
            m_ucFlags &= ~ucMask;
    }
};
struct FUN_00c436a0 : FUN_00c5f680
{
    FUN_00c436a0(AVX* pkObj);
};
// @fnv 0x00c436a0
FUN_00c436a0::FUN_00c436a0(AVX* pkObj) : FUN_00c5f680(pkObj, 0)
{
    *(int**)this = &DAT_010c195c;
    if (IsKindOfType(DAT_011f4aa0, pkObj))
    {
        AVX* pkAV = pkObj;
        if (pkAV->GetField(7, 0) == 5)
            SetBit(true, 1);
    }
}

struct ElemX
{
    char ac[0x64];
};
struct FUN_00c4a070
{
    virtual void v00();
    virtual ElemX* Allocate(unsigned int uiElementCount);
    ElemX* m_pBuffer;
    unsigned int m_uiSize;
    unsigned int m_uiCapacity;
    void ReleaseBuffer(bool bFree);
    void UpdateCachedRef(unsigned int uiNewSize, unsigned int uiCopy);
    void BSSimpleArray_NiFrustumPlanes_1024_ConstructItems(ElemX* pkItems, unsigned int uiElementCount);
    void DestructItems(ElemX* pkItems, unsigned int uiElementCount)
    {
        int aiA[9];
        for (unsigned int i = 0; i < uiElementCount; i++)
            pkItems[i].~ElemX();
    }
    void Shrink(unsigned int uiNewSize)
    {
        int aiB[8];
        UpdateCachedRef(uiNewSize, uiNewSize);
        m_uiCapacity = uiNewSize;
    }
    void SetSize(unsigned int uiNewSize, bool bFree);
};
// @fnv 0x00c4a070
void FUN_00c4a070::SetSize(unsigned int uiNewSize, bool bFree)
{
    if (uiNewSize == 0)
    {
        ReleaseBuffer(bFree);
        return;
    }
    if (uiNewSize > m_uiCapacity)
    {
        if (m_uiCapacity == 0)
        {
            m_pBuffer = Allocate(uiNewSize);
            m_uiCapacity = uiNewSize;
        }
        else
        {
            UpdateCachedRef(uiNewSize, m_uiSize);
            m_uiCapacity = uiNewSize;
        }
        BSSimpleArray_NiFrustumPlanes_1024_ConstructItems(m_pBuffer + m_uiSize, uiNewSize - m_uiSize);
        m_uiSize = uiNewSize;
    }
    else if (uiNewSize < m_uiSize)
    {
        DestructItems(m_pBuffer + uiNewSize, m_uiSize - uiNewSize);
        m_uiSize = uiNewSize;
        if (bFree && uiNewSize <= m_uiCapacity >> 2)
        {
            Shrink(uiNewSize);
        }
    }
    else
    {
        BSSimpleArray_NiFrustumPlanes_1024_ConstructItems(m_pBuffer + m_uiSize, uiNewSize - m_uiSize);
        m_uiSize = uiNewSize;
    }
}

inline void* operator new(unsigned int, void* pv)
{
    return pv;
}
struct ElemY
{
    int a, b, c;
};
struct FUN_00c4a1e0
{
    virtual void v00();
    virtual ElemY* Allocate(unsigned int uiElementCount);
    ElemY* m_pBuffer;
    unsigned int m_uiSize;
    unsigned int m_uiCapacity;
    void ReleaseBuffer(bool bFree);
    void BSSimpleArray_BSCompoundFrustum_FunctionOp_1024_ReallocateBuffer(unsigned int uiNewSize, unsigned int uiCopy);
    void ConstructItems(ElemY* pkItems, unsigned int uiElementCount)
    {
        int aiA[4];
        for (unsigned int i = 0; i < uiElementCount; i++)
            new (&pkItems[i]) ElemY;
    }
    void ConstructItems2(ElemY* pkItems, unsigned int uiElementCount)
    {
        int aiB[3];
        for (unsigned int i = 0; i < uiElementCount; i++)
            new (&pkItems[i]) ElemY;
    }
    void DestructItems(ElemY* pkItems, unsigned int uiElementCount)
    {
        for (unsigned int i = 0; i < uiElementCount; i++)
            pkItems[i].~ElemY();
    }
    void SetSize(unsigned int uiNewSize, bool bFree);
};
// @fnv 0x00c4a1e0
void FUN_00c4a1e0::SetSize(unsigned int uiNewSize, bool bFree)
{
    if (uiNewSize == 0)
    {
        ReleaseBuffer(bFree);
        return;
    }
    if (uiNewSize > m_uiCapacity)
    {
        if (m_uiCapacity == 0)
        {
            m_pBuffer = Allocate(uiNewSize);
            m_uiCapacity = uiNewSize;
        }
        else
        {
            BSSimpleArray_BSCompoundFrustum_FunctionOp_1024_ReallocateBuffer(uiNewSize, m_uiSize);
            m_uiCapacity = uiNewSize;
        }
        ConstructItems(m_pBuffer + m_uiSize, uiNewSize - m_uiSize);
        m_uiSize = uiNewSize;
    }
    else if (uiNewSize < m_uiSize)
    {
        DestructItems(m_pBuffer + uiNewSize, m_uiSize - uiNewSize);
        m_uiSize = uiNewSize;
        if (bFree && uiNewSize <= m_uiCapacity >> 2)
        {
            BSSimpleArray_BSCompoundFrustum_FunctionOp_1024_ReallocateBuffer(uiNewSize, uiNewSize);
            m_uiCapacity = uiNewSize;
        }
    }
    else
    {
        ConstructItems2(m_pBuffer + m_uiSize, uiNewSize - m_uiSize);
        m_uiSize = uiNewSize;
    }
}

extern char DAT_010c1eb4;
struct DerQ : FUN_00c450d0
{
    int unk64, unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0,
        unkA4, unkA8, unkAC;
    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
    DerQ()
    {
        vtbl = (int)&DAT_010c1eb4;
    }
};
// @fnv 0x00c4ac00
// src: EXE 0x00c4ac00
DerQ* BSBlastNode_CreateObject()
{
    return new DerQ;
}

struct S_00c4aca0_Base
{
    S_00c4aca0_Base();
    virtual void vf0();
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
    static void* operator new(unsigned int);
};
struct S_00c4aca0_Obj : S_00c4aca0_Base
{
    S_00c4aca0_Obj()
    {}
    virtual void vf0();
};
struct S_00c4aca0_Self
{
    void __thiscall BSDebrisNode_CopyMembers(S_00c4aca0_Obj* obj, int arg);
    S_00c4aca0_Obj* __thiscall BSDebrisNode_CreateClone(int arg);
};
// @fnv 0x00c4aca0
// src: XBOX_PDB 0x00c4aca0
S_00c4aca0_Obj* __thiscall S_00c4aca0_Self::BSDebrisNode_CreateClone(int arg)
{
    S_00c4aca0_Obj* p = new S_00c4aca0_Obj;
    this->BSDebrisNode_CopyMembers(p, arg);
    return p;
}

extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
struct ItemW
{
    int a, b, c;
};
struct ArrW
{
    virtual void v00();
    virtual ItemW* Allocate(unsigned int uiElementCount);
    virtual void Free(ItemW* pkItems);
    ItemW* m_pBuffer;
    unsigned int m_uiSize;
    unsigned int m_uiCapacity;
// src: XBOX_PDB 0x006dc6e0
    void BSSimpleArray_BSCompoundFrustum_FunctionOp_1024_MoveItems(ItemW* pkDst, ItemW* pkSrc, unsigned int uiElementCount)
    {
        if (pkDst < pkSrc)
        {
            for (unsigned int i = 0; i < uiElementCount; i++)
                memcpy(&pkDst[i], &pkSrc[i], sizeof(ItemW));
        }
        else
        {
            for (unsigned int i = uiElementCount; i > 0; i--)
                memcpy(&pkDst[i - 1], &pkSrc[i - 1], sizeof(ItemW));
        }
    }
    void DestructItems(ItemW* pkItems, unsigned int uiElementCount)
    {
        for (unsigned int i = 0; i < uiElementCount; i++)
            pkItems[i].~ItemW();
    }
    bool ShouldShrink()
    {
        if (m_uiCapacity > 0x400)
        {
            if (m_uiSize <= m_uiCapacity - 0x800)
                return true;
        }
        else if (m_uiSize <= m_uiCapacity >> 2)
            return true;
        return false;
    }
    void AllocateStorage_00c4e760(unsigned int uiIndex, bool bShrink);
};
// @fnv 0x00c4e760
// src: GUESS 0x00c4e760 (confidence: low)
void ArrW::AllocateStorage_00c4e760(unsigned int uiIndex, bool bShrink)
{
    if (bShrink && ShouldShrink())
    {
        unsigned int uiNew = m_uiCapacity > 0x800 ? m_uiCapacity - 0x400 : m_uiCapacity >> 1;
        ItemW* pkNew = Allocate(uiNew);
        BSSimpleArray_BSCompoundFrustum_FunctionOp_1024_MoveItems(pkNew, m_pBuffer, uiIndex);
        DestructItems(m_pBuffer + uiIndex, 1);
        BSSimpleArray_BSCompoundFrustum_FunctionOp_1024_MoveItems(pkNew + uiIndex, m_pBuffer + uiIndex + 1, m_uiSize - 1);
        Free(m_pBuffer);
        m_pBuffer = 0;
        m_pBuffer = pkNew;
        m_uiCapacity = uiNew;
    }
    else
    {
        DestructItems(m_pBuffer + uiIndex, 1);
        BSSimpleArray_BSCompoundFrustum_FunctionOp_1024_MoveItems(m_pBuffer + uiIndex, m_pBuffer + uiIndex + 1, m_uiSize - uiIndex - 1);
    }
    m_uiSize--;
}

extern "C" char* __cdecl FUN_00ec7750(const char* pcString, const char* pcSearch);  // strstr

struct BoneRootRTTI
{
    const char* m_pcName;
    const BoneRootRTTI* m_pBaseRTTI;
};
extern BoneRootRTTI DAT_011f4a38;

struct FixedQ
{
    char* m;
    operator const char*() const
    {
        return m;
    }
};
class BoneRootExtraData
{
  public:
    virtual void v00();
    virtual void v01();
    virtual const BoneRootRTTI* GetRTTI() const;
    int unk04;
    int unk08;
    FixedQ m_kString;  // +0x0c

    bool IsKindOfType(const BoneRootRTTI* pkTarget) const
    {
        const BoneRootRTTI* pkRTTI = GetRTTI();
        while (pkRTTI)
        {
            if (pkRTTI == pkTarget)
                return true;
            pkRTTI = pkRTTI->m_pBaseRTTI;
        }
        return false;
    }
    const char* GetValue() const
    {
        return m_kString;
    }
};

class BoneRootNode;
class BoneRootChild
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual BoneRootNode* IsSceneNode();  // +0x0c
};

struct PtrQ
{
    BoneRootChild* m;
    operator BoneRootChild*() const
    {
        return m;
    }
};


class BoneRootNode
{
  public:
    int unk00[4];
    BoneRootExtraData** m_ppExtraData;  // +0x10
    unsigned short m_usExtraCount;      // +0x14
    unsigned short unk16;
    int unk18[33];
    NiTObjectArray<PtrQ> m_kChildList;  // +0x9c

    BoneRootChild* GetChild(unsigned int ui)
    {
        int aiD[3];
        return m_kChildList.GetAt(ui);
    }
    unsigned short GetExtraDataSize() const
    {
        return m_usExtraCount;
    }
};

class BoneRootSet
{
  public:
    void AppendLinkID(BoneRootNode*& pkNode);
};

// @fnv 0x00c52c30
// src: XBOX_PDB 0x00c52c30
void __cdecl NiBSBoneLODController_FindBoneRootNodes(BoneRootNode* pkNode, BoneRootSet* pkSet)
{
    unsigned int i;
    BoneRootExtraData* pkExtra;
    for (i = 0; i < pkNode->GetExtraDataSize(); i++)
    {
        BoneRootExtraData* pkString;
        pkExtra = pkNode->m_ppExtraData[(unsigned short)i];
        if (!pkExtra)
            pkString = 0;
        else
            pkString = pkExtra->IsKindOfType(&DAT_011f4a38) ? pkExtra : 0;
        if (pkString)
        {
            const char* pcValue = pkString->GetValue();
            if (pcValue && FUN_00ec7750(pcValue, "BSBoneLOD#BoneRoot#"))
            {
                pkSet->AppendLinkID(pkNode);
                return;
            }
        }
    }
    for (i = 0; i < pkNode->m_kChildList.m_usSize; i++)
    {
        BoneRootChild* pkChild = pkNode->GetChild(i);
        if (pkChild && pkChild->IsSceneNode())
            NiBSBoneLODController_FindBoneRootNodes((BoneRootNode*)pkChild, pkSet);
    }
}

extern NiPoint3 DAT_011f426c;
extern NiFixedString* DAT_012031e4;
extern int DAT_011f49e0;

#pragma intrinsic(memcpy)
struct C55010Obj : NiExtraData
{
    NiPoint3 m_0c;
    NiPoint3 m_18;
    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
    C55010Obj(const NiFixedString& name) : NiExtraData(name)
    {
        memcpy(&m_0c, &DAT_011f426c, sizeof(m_0c));
        memcpy(&m_18, &DAT_011f426c, sizeof(m_18));
    }
};

// @fnv 0x00c55010
// src: EXE 0x00c55010
C55010Obj* BSBound_CreateObject()
{
    C55010Obj* p = new C55010Obj(*DAT_012031e4);
    ((NiAVObject*)p)->SetName(*(const NiFixedString*)&DAT_011f49e0);
    return p;
}

#pragma function(memcpy)
namespace fnv_00c5f390 {
inline void* operator new(unsigned int, void* p)
{
    return p;
}
struct T4
{
    int v;
};
inline void Construct(T4* p, unsigned int n)
{
    for (unsigned int i = 0; i < n; i++)
        new (&p[i]) T4;
}
inline void DeadB()
{
    int d0;
    int d1;
    int d2;
}
inline void Destroy(T4* p, unsigned int n)
{
    for (unsigned int i = 0; i < n; i++)
        p[i].~T4();
    DeadB();
}
inline void DeadA()
{
    int a0;
    int a1;
    int a2;
    int a3;
}
struct ArrX
{
    virtual void V0();
    virtual T4* Alloc(unsigned int n);
    T4* m4;
    unsigned int m8;
    unsigned int mc;
    void FUN_008454f0(bool b);
    void FUN_0042fc00(unsigned int a, unsigned int b);
    void BSSimpleArray_enum_hkpConstraintData_ConstraintType_1024_SetSize(unsigned int n, bool b);
};
// @fnv 0x00c5f390
// src: XBOX_PDB 0x00c5f390
void ArrX::BSSimpleArray_enum_hkpConstraintData_ConstraintType_1024_SetSize(unsigned int n, bool b)
{
    DeadA();
    if (n == 0)
    {
        FUN_008454f0(b);
    }
    else if (n > mc)
    {
        if (mc == 0)
        {
            m4 = Alloc(n);
            mc = n;
        }
        else
        {
            FUN_0042fc00(n, m8);
            mc = n;
        }
        Construct(m4 + m8, n - m8);
        m8 = n;
    }
    else if (n < m8)
    {
        Destroy(m4 + n, m8 - n);
        m8 = n;
        if (b && n <= mc >> 2)
        {
            FUN_0042fc00(n, n);
            mc = n;
        }
    }
    else
    {
        Construct(m4 + m8, n - m8);
        m8 = n;
    }
}
}  // namespace fnv_00c5f390

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* p);

struct MemMgr
{
    void* Allocate(unsigned int size);
    void Deallocate(void* p);
};
extern MemMgr g_memMgr;

extern unsigned int DAT_0126fd98;
extern "C" unsigned long __readfsdword(unsigned long);
struct MapThreadData
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
    int heapContext;
};
__declspec(thread) MapThreadData mapTls;
inline int GetHeapContext()
{
    int value = mapTls.heapContext;
    return value;
}
inline void SetHeapContext(int value)
{
    mapTls.heapContext = value;
}

struct HeapCtxGuard
{
    int saved;
    __forceinline HeapCtxGuard(int ctx)
    {
        saved = GetHeapContext();
        SetHeapContext(ctx);
    }
    __forceinline ~HeapCtxGuard()
    {
        int v = saved;
        SetHeapContext(v);
    }
};

long __cdecl FinishMapRef(void*);
struct MapRefObj
{
    virtual ~MapRefObj();
    int unk04;
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        long refs = FinishMapRef(&m_uiRefCount);
        if (refs == 0)
            delete this;
    }
};

struct MapRefPtr
{
    MapRefObj* m_pObject;
    ~MapRefPtr()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
    MapRefPtr& operator=(MapRefObj* object)
    {
        if (m_pObject != object)
        {
            if (m_pObject != 0)
                m_pObject->DecRefCount();
            m_pObject = object;
            if (m_pObject != 0)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};

struct WeightedMapNode;
struct TaggedMapLink
{
    unsigned int value;
    WeightedMapNode* Get()
    {
        TaggedMapLink* link = this;
        return (WeightedMapNode*)(link->value & ~1);
    }
    void Clear()
    {
        value = 0;
    }
    void Detach()
    {
        TaggedMapLink* link = this;
        link->value = 0;
    }
};
struct WeightedMapNode
{
    int unk00;
    int unk04;
    MapRefPtr m_spObj;
    TaggedMapLink m_next;
    static void operator delete(void* p)
    {
        g_memMgr.Deallocate(p);
    }
};

unsigned int __cdecl GetMapThreadId();
int __cdecl CompareMapLock(volatile long*, long, long);
void __cdecl YieldMapThread(unsigned long);
void __cdecl MapLockBarrier();
struct SpinLock
{
    int owner;
    int count;
    void Lock(const char* name)
    {
        unsigned int threadId = GetMapThreadId();
        if (owner == threadId)
        {
            count = count + 1;
        }
        else
        {
            unsigned int spins = 0;
            while (CompareMapLock((volatile long*)&owner, 0, threadId))
            {
                ++spins;
                if (spins > 10000)
                    YieldMapThread(1);
                else
                    YieldMapThread(0);
            }
            MapLockBarrier();
            count = 1;
        }
    }
    void Unlock()
    {
        count = count - 1;
        if (count == 0)
            owner = 0;
    }
};

struct Pool
{
    int unk00, unk04, unk08, unk0C;
    int GetSize()
    {
        return unk00;
    }
    Pool(int a);
    ~Pool();
    static void* operator new(unsigned int size)
    {
        return g_memMgr.Allocate(size);
    }
    static void operator delete(void* p)
    {
        g_memMgr.Deallocate(p);
    }
};

struct NodeMap
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
    virtual void ReleaseKey(int, int);
    int unk04;
    unsigned int m_uiHashSize;
    TaggedMapLink* m_ppBuckets;
    int unk10;
    Pool* m_pLinkPool;
    int m_uiCount;
    int unk1C;
    SpinLock m_lock;
    void FreeNode(WeightedMapNode* node)
    {
        ReleaseKey(node->unk00, node->unk04);
        delete node;
    }
    void LockFreeMap_int64_NiPointer_BSTask_int64_RemoveAll(bool keepPool);
};

// @fnv 0x00c40b70
// src: COMMUNITY 0x00c40b70
void NodeMap::LockFreeMap_int64_NiPointer_BSTask_int64_RemoveAll(bool keepPool)
{
    HeapCtxGuard heapContext(6);
    if (m_pLinkPool == 0)
        return;
    m_lock.Lock(0);
    int poolSize = m_pLinkPool->GetSize();
    delete m_pLinkPool;
    m_pLinkPool = 0;
    m_uiCount = 0;
    for (unsigned int i = 0; i < m_uiHashSize; i++)
    {
        WeightedMapNode* node = m_ppBuckets[i].Get();
        m_ppBuckets[i].Clear();
        while (node)
        {
            WeightedMapNode* next = node->m_next.Get();
            node->m_next.Detach();
            node->m_spObj = 0;
            FreeNode(node);
            node = next;
        }
    }
    if (!keepPool)
    {
        m_pLinkPool = new Pool(poolSize);
    }
    m_lock.Unlock();
}

typedef unsigned int U32;
int __cdecl FUN_004019a0(void*);
struct C41RefObject
{
    virtual ~C41RefObject();
    void Release();
    U32 m_04, m_08;
// src: XBOX_PDB 0x0044dd60
    inline void BSTask_int64_DecRefCount()
    {
        int count = FUN_004019a0(&m_08);
        if (!count)
        {
            delete this;
        }
    }
};
struct C41Object : C41RefObject
{
};
extern "C" void(__stdcall* FUN_00fdf1c0)(void*);
extern "C" U32(__stdcall* FUN_00fdf1bc)(void*, U32, U32);
struct C41Guard
{
    C41Object* m_00;
    C41Guard(C41Object* const& p) : m_00(p)
    {
        if (m_00)
        {
            C41Object* object = m_00;
            FUN_00fdf1c0(&object->m_08);
        }
    }
    inline ~C41Guard()
    {
        if (m_00)
            m_00->BSTask_int64_DecRefCount();
    }
};
struct C41Node;
struct C41Link
{
    U32 m_00;
    C41Link()
    {}
    C41Link(C41Node* p) : m_00((U32)p)
    {}
    inline void Initialize(C41Node* p, bool b)
    {
        m_00 = (U32)p;
        Flag(b);
    }
    inline C41Node* Get() volatile
    {
        return (C41Node*)(m_00 & ~1U);
    }
    inline U32 Raw() volatile
    {
        return m_00;
    }
    inline U32 Flag()
    {
        C41Link* link = this;
        return link->m_00 & 1U;
    }
    inline void Flag(bool b) volatile
    {
        if (b)
            m_00 |= 1;
        else
            m_00 &= ~1U;
    }
    inline bool Compare(U32 desired, U32 expected) volatile
    {
        bool success = FUN_00fdf1bc((void*)this, desired, expected) == expected;
        return success;
    }
    inline bool Equal(const C41Link& r) const
    {
        return m_00 == r.m_00;
    }
    void LockFreeMap_MarkedPointer_SetMark(bool);
};
struct C41ObjectSlot
{
    C41Object* value;
    inline void operator=(C41Object* p)
    {
        if (value != p)
        {
            if (value)
                value->Release();
            value = p;
            if (value)
            {
                C41Object* object = value;
                FUN_00fdf1c0(&object->m_08);
            }
        }
    }
};
struct C41Node
{
    U32 m_00, m_04;
    C41ObjectSlot m_08;
    C41Link m_0c;
};
struct C41Table
{
    U32 m_00, m_04, m_08;
    C41Link* m_0c;
    U32 m_10;
};
struct C41DestSingle
{
    C41Node* ptr;
};
struct C41Owner
{
    C41Table* m_00;
    C41DestSingle* m_04;
    C41DestSingle* m_08;
    C41DestSingle* m_0c;
    C41Link* m_10;
    C41Link m_14, m_18;
    C41Node* retired;
    U32 retiredCount;
    void LockFreeMap_TESObjectREFR_NiPointer_QueuedReference_LockFreeMapInterface_ScanForDeletedNodes();
// src: COMMUNITY 0x00c41f40
    inline void LockFreeMap_TESObjectREFR_NiPointer_QueuedReference_LockFreeMapInterface_DeleteNode(C41Node* node)
    {
        node->m_08 = 0;
        C41Node* head = retired;
        node->m_08.value = (C41Object*)head;
        retired = node;
        ++retiredCount;
        U32 threshold = m_00->m_10;
        if (retiredCount == threshold)
            LockFreeMap_TESObjectREFR_NiPointer_QueuedReference_LockFreeMapInterface_ScanForDeletedNodes();
    }
    bool ProcessEntries_00c41ac0(int, C41Object**);
};

// @fnv 0x00c41ac0
// src: GUESS 0x00c41ac0 (confidence: low)
bool C41Owner::ProcessEntries_00c41ac0(int index, C41Object** wanted)
{
    C41Link* bucket = &m_00->m_0c[index];
    bool retry;
    while (true)
    {
        retry = false;
        m_10 = bucket;
        m_14 = *m_10;
        m_08->ptr = m_14.Get();
        C41Link initial(m_14.Get());
        initial.LockFreeMap_MarkedPointer_SetMark(false);
        if (m_10->Raw() != initial.Raw())
            continue;
        while (true)
        {
            if (!m_14.Get())
                return false;
            m_18 = m_14.Get()->m_0c;
            m_04->ptr = m_18.Get();
            if (m_18.Raw() != m_14.Get()->m_0c.Raw())
            {
                retry = true;
                break;
            }
            C41Guard object(m_14.Get()->m_08.value);
            C41Link current(m_14.Get());
            current.LockFreeMap_MarkedPointer_SetMark(false);
            if (m_10->Raw() != current.Raw())
            {
                retry = true;
                goto retryIteration;
            }
            if (!(bool)(int)m_18.Flag())
            {
                if ((bool)(int)(object.m_00 == *wanted))
                    return true;
                m_10 = &m_14.Get()->m_0c;
                m_0c->ptr = m_14.Get();
            }
            else
            {
                C41Link next;
                next.Initialize(m_18.Get(), false);
                if (m_10->Compare(next.Raw(), current.Raw()))
                    LockFreeMap_TESObjectREFR_NiPointer_QueuedReference_LockFreeMapInterface_DeleteNode(m_14.Get());
                else
                {
                    retry = true;
                    break;
                }
            }
            m_14 = m_18;
            m_08->ptr = m_18.Get();
        }
    retryIteration:
        if (retry)
            continue;
    }
}



struct Ref41fe0
{
    ObjA* m_pObject;
    ~Ref41fe0()
    {
        if (m_pObject)
            m_pObject->BSTask_int64_DecRefCount();
    }
};

struct DtorScratch41fe0
{
    unsigned int m_kPointA;
    unsigned int m_kPointB;
    unsigned int m_iThirdValue;
    DtorScratch41fe0()
    {}
};

struct Arg41fe0
{
    Pair pair;
    Ref41fe0 m_08;
    ~Arg41fe0()
    {
        DtorScratch41fe0 scratch;
    }
    static void operator delete(void* p)
    {
        reinterpret_cast<MemoryManager*>(&DAT_011f6238)->Deallocate(p);
    }
};

class C41FE0_Owner
{
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
    virtual void v10(Pair pair);

    void LockFreeMap_TESObjectREFR_NiPointer_QueuedReference_DeleteNode(Arg41fe0* p);
};

// @fnv 0x00c41fe0
// src: COMMUNITY 0x00c41fe0
void C41FE0_Owner::LockFreeMap_TESObjectREFR_NiPointer_QueuedReference_DeleteNode(Arg41fe0* p)
{
    v10(p->pair);
    delete p;
}

extern char DAT_011f6238;

inline int S00c420d0_One()
{
    return 1;
}

struct S00c420d0_Item
{
    void __thiscall StepUntilStateIsZero();
};

struct S00c420d0_Pair
{
    unsigned int unk00;
    S00c420d0_Item* m_pObject;
};

struct S00c420d0_cls
{
    unsigned int m_uiItemCount;
    unsigned int m_unk04;
    S00c420d0_Pair* m_pairs;
    void ProcessEntries_00c420d0();
};

// @fnv 0x00c420d0
// src: GUESS 0x00c420d0 (confidence: low)
void S00c420d0_cls::ProcessEntries_00c420d0()
{
    unsigned int i = 0;
    {
        S00c420d0_Item* item;
        S00c420d0_Item* p;
        {
            S00c420d0_Pair* pairs;
            {
                unsigned int count;
                S00c420d0_Item* r;
                for (; i < (count = this->m_uiItemCount); ++i)
                {
                    item = this->m_pairs[i].m_pObject;
                    p = item;
                    (p != 0) ? (r = p, reinterpret_cast<FUN_00c42b40_cls*>(r)->StepUntilStateIsZero(),
                                (S00c420d0_One() & 1) ? reinterpret_cast<SpawnHeap_cls*>(&DAT_011f6238)->MemoryManager_Deallocate(r)
                                                      : (void)0,
                                r)
                             : 0;
                }
                pairs = this->m_pairs;
                reinterpret_cast<SpawnHeap_cls*>(&DAT_011f6238)->MemoryManager_Deallocate(pairs);
            }
        }
    }
    {
        unsigned int tls = this->m_unk04;
        DAT_0fdf050((void*)tls);
    }
}

namespace fnv_00c42180 {
struct TlsMem
{
    char pad[0x2b4];
    int iCtx;
};
extern __declspec(thread) TlsMem DAT_0126fd98;
struct MemMgrQ
{
    void* __thiscall Game_DoHeapAlloc(unsigned int size);
};
extern "C" char DAT_011f6238;
typedef unsigned long(__stdcall* TidFnQ)();
extern "C" TidFnQ DAT_00fdf048;
inline int GetMemCtx()
{
    return DAT_0126fd98.iCtx;
}
inline void SetMemCtx(int c)
{
    DAT_0126fd98.iCtx = c;
}

}  // namespace fnv_00c42180
inline AutoMemContext::AutoMemContext(int c)
{
    m_eMemoryContext = (MEM_CONTEXT)fnv_00c42180::GetMemCtx();
    fnv_00c42180::DAT_0126fd98.iCtx = c;
}
inline AutoMemContext::~AutoMemContext()
{
    fnv_00c42180::SetMemCtx((int)m_eMemoryContext);
}
namespace fnv_00c42180 {
struct BucketQ
{
    void* p0;
    void* p4;
    BucketQ()
    {
        BucketQ* pThis = this;
        pThis->p0 = 0;
        pThis->p4 = 0;
    }
    static void* operator new[](unsigned int size)
    {
        return ((MemMgrQ*)&DAT_011f6238)->Game_DoHeapAlloc(size);
    }
};
struct FUN_00c42180
{
    unsigned int m_uiItemCount;
    unsigned long m_tid;
    BucketQ* m_pBuckets;
    int m_C;
    FUN_00c42180(unsigned int n);
};
// @fnv 0x00c42180
FUN_00c42180::FUN_00c42180(unsigned int n)
{
    AutoMemContext ctx(6);
    m_C = 0;
    m_uiItemCount = n;
    m_pBuckets = new BucketQ[m_uiItemCount];
    m_tid = DAT_00fdf048();
}
}  // namespace fnv_00c42180

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
int __cdecl FinishScriptRunLock(void*);

struct RefObject
{
    virtual ~RefObject();
    int unk04;
    long references;
// src: XBOX_PDB 0x0044dd60
    inline void BSTask_int64_DecRefCount()
    {
        long count = FinishScriptRunLock(&references);
        if (count == 0)
            delete this;
    }
    __forceinline void AddRef()
    {
        InterlockedIncrement(&references);
    }
};
struct ObjectRef
{
    RefObject* ptr;
    __forceinline ObjectRef& operator=(const ObjectRef& rhs)
    {
        if (ptr != rhs.ptr)
        {
            if (ptr)
                ptr->BSTask_int64_DecRefCount();
            ptr = rhs.ptr;
            if (ptr)
                ptr->AddRef();
        }
        return *this;
    }
};
struct MapEntry;
struct TaggedPointer
{
    unsigned int raw;
    __forceinline MapEntry* Get() const
    {
        return reinterpret_cast<MapEntry*>(raw & ~1u);
    }
    __forceinline unsigned int Bits() const
    {
        return raw;
    }
    __forceinline bool NextMarked() const;
};
struct MapEntry
{
    unsigned __int64 key;
    ObjectRef value;
    TaggedPointer next;
};
__forceinline bool TaggedPointer::NextMarked() const
{
    const TaggedPointer* self = this;
    MapEntry* n6 = reinterpret_cast<MapEntry*>(self->raw & ~1u);
    TaggedPointer* nX2 = &n6->next;
    return (nX2->raw & 1) != 0 ? true : false;
}
struct BucketMap
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
    virtual void Visit(unsigned __int64, int);
    int unk04, unk08;
    TaggedPointer* buckets;
};
struct Iterator
{
    BucketMap* map;
    MapEntry** hazard0;
    MapEntry** hazard1;
    MapEntry** hazard2;
    TaggedPointer* slot;
    TaggedPointer current;
    bool LockFreeMap_int64_NiPointer_BSTask_int64_LockFreeMapInterface_GetFirst(unsigned int, int, ObjectRef&);
};

// @fnv 0x00c42380
// src: COMMUNITY 0x00c42380
bool Iterator::LockFreeMap_int64_NiPointer_BSTask_int64_LockFreeMapInterface_GetFirst(unsigned int index, int context, ObjectRef& output)
{
    bool success = false;
    while (true)
    {
        TaggedPointer* c5;
        TaggedPointer* cY;
        TaggedPointer* CSA;
        TaggedPointer* sn;
        unsigned int _raw;
        TaggedPointer* s;
        MapEntry* PN;
        TaggedPointer* sp;
        TaggedPointer* cR;
        TaggedPointer* CN;
        TaggedPointer* en;
        TaggedPointer sN7;

        en = &map->buckets[index];
        slot = en;
        current = *slot;
        CN = &current;
        *hazard1 = CN->Get();
        cR = &current;
        PN = reinterpret_cast<MapEntry*>(cR->raw & ~1u);
        sN7.raw = reinterpret_cast<unsigned int>(PN);
        sp = &sN7;
        if (0)
            sp->raw |= 1;
        else
            sp->raw &= ~1u;
        s = slot;
        _raw = s->raw;
        sn = &sN7;
        if (_raw != static_cast<volatile TaggedPointer*>(sn)->raw)
            continue;
        CSA = &current;
        if ((CSA->raw & ~1u) == 0)
        {
            success = false;
            break;
        }
        cY = &current;
        map->Visit(reinterpret_cast<MapEntry*>(cY->raw & ~1u)->key, context);
        c5 = &current;
        output = reinterpret_cast<MapEntry*>(c5->raw & ~1u)->value;
        success = true;
        if (current.NextMarked())
            continue;
        break;
    }
    *hazard0 = 0;
    *hazard1 = 0;
    *hazard2 = 0;
    return success;
}

struct AllocationTLS
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
    int context;
};
__declspec(thread) AllocationTLS g_allocationTLS;

struct S_00c42960_Scope
{
    int m_old;
    __forceinline S_00c42960_Scope(int context) : m_old(Get())
    {
        Set(context);
    }
    __forceinline ~S_00c42960_Scope()
    {
        Set(m_old);
    }
    static __forceinline int Get()
    {
        return g_allocationTLS.context;
    }
    static __forceinline void Set(int context)
    {
        g_allocationTLS.context = context;
    }
};

extern "C" char DAT_011f6238;

struct S_00c42960_Heap
{
    void* __thiscall Game_DoHeapAlloc(unsigned int size);
    void __thiscall MemoryManager_Deallocate(void* p);
};

struct ReleaseObject
{
    virtual ~ReleaseObject();
    int unk04;
    long refs;
// src: XBOX_PDB 0x0044dd60
    inline void BSTask_int64_DecRefCount()
    {
        long remaining = InterlockedDecrement(&refs);
        if (remaining == 0)
            delete this;
    }
};
struct S_00c42960_Node;
struct NodeLink
{
    S_00c42960_Node* value;
    __forceinline ~NodeLink();
};
struct S_00c42960_Node
{
    int unk00;
    int unk04;
    NodeLink m_pNext;
    void BSTask_int64_DecRefCount();
    static __forceinline void operator delete(void* p)
    {
        reinterpret_cast<S_00c42960_Heap*>(&DAT_011f6238)->MemoryManager_Deallocate(p);
    }
    __forceinline S_00c42960_Node* GetNext()
    {
        return m_pNext.value;
    }
};
__forceinline NodeLink::~NodeLink()
{
    if (value)
        reinterpret_cast<ReleaseObject*>(value)->BSTask_int64_DecRefCount();
}

struct S_00c42960_Slot
{
    S_00c42960_Node* m_pReferencedNode;
    static void* operator new[](unsigned int bytes)
    {
        return reinterpret_cast<S_00c42960_Heap*>(&DAT_011f6238)->Game_DoHeapAlloc(bytes);
    }
    static void operator delete[](void* p)
    {
        reinterpret_cast<S_00c42960_Heap*>(&DAT_011f6238)->MemoryManager_Deallocate(p);
    }
};

struct S_00c42960_Counter
{
    unsigned int m_uiItemCount;
    __forceinline unsigned int GetCount()
    {
        return m_uiItemCount;
    }
};

struct S_00c42960_Owner
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void FreePair(int key, int value);
    S_00c42960_Slot* m_pEntryData;
    int unk08;
    int unk0C;
    int unk10;
    S_00c42960_Counter* m_pCounter;
    __forceinline S_00c42960_Slot* GetArray()
    {
        return m_pEntryData;
    }
    __forceinline S_00c42960_Counter* GetCounter()
    {
        return m_pCounter;
    }
// src: COMMUNITY 0x00c41fe0
    inline void LockFreeMap_TESObjectREFR_NiPointer_QueuedReference_DeleteNode(S_00c42960_Node* node)
    {
        FreePair(node->unk00, node->unk04);
        delete node;
    }
};

void* __cdecl FUN_00ec44d0(void* dst, const void* src, unsigned int n);

struct S_00c42960
{
    S_00c42960_Owner* m_pSharedOwner;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    S_00c42960_Node* m_pHead;
    unsigned int m_uiItemCount;
    void LockFreeMap_TESObjectREFR_NiPointer_QueuedReference_LockFreeMapInterface_ScanForDeletedNodes();
};

// @fnv 0x00c42960
// src: COMMUNITY 0x00c42960
void S_00c42960::LockFreeMap_TESObjectREFR_NiPointer_QueuedReference_LockFreeMapInterface_ScanForDeletedNodes()
{
    S_00c42960_Scope scope2(6);
    unsigned int n9 = m_pSharedOwner->GetCounter()->GetCount() * 3;
    S_00c42960_Slot* p = new S_00c42960_Slot[n9];
    FUN_00ec44d0(p, m_pSharedOwner->GetArray(), n9 * 4);
    S_00c42960_Node* headR = 0;
    unsigned int cnt2 = 0;
    while (m_pHead)
    {
        S_00c42960_Node* node2 = m_pHead;
        m_pHead = m_pHead->GetNext();
        bool found2 = false;
        for (unsigned int i = 0; i < n9; ++i)
        {
            if (node2 == p[i].m_pReferencedNode)
            {
                found2 = true;
                break;
            }
        }
        if (found2)
        {
            node2->m_pNext.value = headR;
            headR = node2;
            ++cnt2;
        }
        else
        {
            node2->m_pNext.value = 0;
            m_pSharedOwner->LockFreeMap_TESObjectREFR_NiPointer_QueuedReference_DeleteNode(node2);
        }
    }
    delete[] p;
    m_pHead = headR;
    m_uiItemCount = cnt2;
}

struct ExtraBase_c42ff0
{
    int m_vtbl;
    int unk04;
    int unk08;
    ExtraBase_c42ff0();
};

struct IntMid_c42ff0 : ExtraBase_c42ff0
{
    __forceinline IntMid_c42ff0()
    {
        m_vtbl = (int)&DAT_010a0d24;
    }
};

struct IntData_c42ff0 : IntMid_c42ff0
{
    int m_iValue;
    __forceinline IntData_c42ff0(int v) : m_iValue(v)
    {}
    ~IntData_c42ff0();
};

struct FUN_00c42ff0 : IntData_c42ff0
{
    FUN_00c42ff0(int v);
    void BSXFlags_Init();
};

// @fnv 0x00c42ff0
FUN_00c42ff0::FUN_00c42ff0(int v) : IntData_c42ff0(v)
{
    m_vtbl = (int)&DAT_010c1854;
    BSXFlags_Init();
}

extern void* DAT_01202de8;
extern "C" void* __cdecl NiViewerStrings_NiGetViewerString_Title(void*);
extern "C" void* __cdecl NiGetViewerString_00a7d4d0(const char*, void*);
extern "C" void* __cdecl NiGetViewerString_00a7d5e0(const char*, const char*);

inline bool TestBit(unsigned char value, unsigned mask, unsigned zero)
{
    return (value & (mask | zero)) != 0;
}

class ObjArg
{
  public:
    void FUN_0096a610(void** slot);
};

class FUN_00c43ab0_cls
{
  public:
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
    unsigned char m_ac;
    unsigned char unkAD;
    unsigned char unkAE;
    unsigned char unkAF;
    unsigned int m_b0;

    void* NiNode_GetViewerStrings(void* arg);
    void BSValueNode_GetViewerStrings(ObjArg* a1);
};

struct ValKeep
{
    unsigned u0;
    unsigned u1;
    unsigned u2;
    unsigned u3;
    unsigned u4;
    unsigned val;
    unsigned u5;
};

// @fnv 0x00c43ab0
// src: XBOX_PDB 0x00c43ab0
void FUN_00c43ab0_cls::BSValueNode_GetViewerStrings(ObjArg* a1)
{
    void* text;
    void* vtext;
    void* line;
    void* rtti;
    ValKeep stored;

    this->NiNode_GetViewerStrings(a1);
    rtti = DAT_01202de8;
    text = NiViewerStrings_NiGetViewerString_Title(rtti);
    a1->FUN_0096a610(&text);
    stored.val = this->m_b0;
    vtext = NiGetViewerString_00a7d4d0("Value", (void*)stored.val);
    a1->FUN_0096a610(&vtext);
    if (TestBit(this->m_ac, 1u, 0u))
    {
        line = NiGetViewerString_00a7d5e0("Billboard", TestBit(this->m_ac, 1u, 0u) ? "true" : "false");
        a1->FUN_0096a610(&line);
    }
}

struct NiUpdateData;

struct S00c43b90_Bound
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
};

extern S00c43b90_Bound DAT_011a9448;

struct S00c43b90_t
{
    void* unk00;
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
    S00c43b90_Bound unk68;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    unsigned char unkAC;

    inline bool GetBit(unsigned char mask) const
    {
        return (unkAC & mask) != 0;
    }
    void UpdateWorldData(NiUpdateData& data);
    void BSValueNode_UpdateWorldData(NiUpdateData& data);
};

// @fnv 0x00c43b90
// src: XBOX_PDB 0x00c43b90
void S00c43b90_t::BSValueNode_UpdateWorldData(NiUpdateData& data)
{
    UpdateWorldData(data);

    if (GetBit(1))
    {
        unk68 = *reinterpret_cast<S00c43b90_Bound*>(&DAT_011a9448);
    }
}

extern "C" __declspec(dllimport) unsigned long __stdcall GetPrivateProfileStringA(const char*, const char*, const char*,
                                                                                  char*, unsigned long, const char*);
extern "C" __declspec(dllimport) unsigned int __stdcall GetPrivateProfileIntA(const char*, const char*, int,
                                                                              const char*);
int __cdecl FUN_00ec6da0(const char*, const char*);
char* __cdecl FUN_00ec6370(char*, const char*);
int __cdecl FUN_00eca4a6(const char*, const char*, ...);

extern SETTING_VALUE DAT_01202800;
struct IniSetting
{
    int flags;
    SETTING_VALUE value;
    char* name;
    void SetStringAndPromoteKeyOwnership(const char* value);
    __forceinline char* GetName()
    {
        char* resultName = name;
        return resultName;
    }
    __forceinline int& GetInteger()
    {
        SETTING_VALUE* original = this ? &value : (DAT_01202800.i = 0, &DAT_01202800);
        return original->i;
    }
    __forceinline float& GetReal()
    {
        SETTING_VALUE* original = this ? &value : (DAT_01202800.f = 0.0f, &DAT_01202800);
        return original->f;
    }
    __forceinline bool& GetBoolean()
    {
        SETTING_VALUE* original = this ? &value : (DAT_01202800.b = false, &DAT_01202800);
        return original->b;
    }
    __forceinline void SetInteger(int number)
    {
        if (this)
            value.i = number;
    }
};
struct LanguageSetting
{
    int flags;
    char* value;
    __forceinline char* GetString()
    {
        return this ? value : 0;
    }
};
extern LanguageSetting DAT_011c3cb4;
extern SETTING_VALUE DAT_01202800;
unsigned int __cdecl Setting_DataType_00c33090(const char* name);
int __cdecl BSsprintf(char*, unsigned int, const char*, ...);
__forceinline unsigned int MakeIniColor(unsigned int red, unsigned int green, unsigned int blue, unsigned int alpha)
{
    unsigned int color = red << 24;
    color |= (green & 255) << 16;
    color |= (blue & 255) << 8;
    color |= alpha & 255;
    return color;
}
struct IniCollection
{
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0c();
    virtual void vfn10();
    virtual void vfn14();
    virtual void Open(bool create);
    virtual void Close();
    char filename[260];
    void* file;
    bool INISettingCollection_ReadSetting(IniSetting* setting);
};

// @fnv 0x00c44280
// src: XBOX_PDB 0x00c44280
bool IniCollection::INISettingCollection_ReadSetting(IniSetting* setting)
{
    bool success3 = false;
    bool opened3;
    DWORD count;
    {
        char defaultValue3[256];
        char key17[64];
        unsigned int type6;
        char section2[64];
        char value2[256];
        char stringValue2[1024];
        char language[1024];
        if (setting->GetName())
        {
            opened3 = file == 0;
            if (opened3)
                Open(true);
            if (file)
            {
                type6 = Setting_DataType_00c33090(setting->name);
                CopyMainNameFromPath((int)setting, key17);
                CopyStringBeforeColon((FUN_00c43e00_Obj*)setting, section2);
                switch (type6)
                {
                case 6:
                    if (FUN_00ec6da0(key17, "LANGUAGE") == 0)
                    {
                        count = GetPrivateProfileStringA("General", "sLanguage", DAT_011c3cb4.GetString(), language,
                                                         256, filename);
                        FUN_00ec6370(key17, language);
                    }
                    {
                        count = GetPrivateProfileStringA(key17, section2, setting ? setting->value.str : 0,
                                                         stringValue2, 256, filename);
                        setting->SetStringAndPromoteKeyOwnership(stringValue2);
                    }
                    break;
                case 1: {
                    setting->value.c =
                        (char)GetPrivateProfileIntA(key17, section2, setting->GetInteger(), filename);
                }
                break;
                case 3: {
                    setting->SetInteger(GetPrivateProfileIntA(key17, section2, setting->GetInteger(), filename));
                }
                break;
                case 5: {
                    BSsprintf(defaultValue3, 256, "%f", setting->GetReal());
                    count = GetPrivateProfileStringA(key17, section2, defaultValue3, value2, 256, filename);
                    if (count)
                        success3 = FUN_00eca4a6(value2, "%f", &setting->value.f) == 1;
                }
                break;
                case 7: {
                    count = GetPrivateProfileStringA(key17, section2, "", value2, 256, filename);
                    if (count)
                    {
                        unsigned int red, green2, blue3;
                        success3 = FUN_00eca4a6(value2, "%u,%u,%u", &red, &green2, &blue3) == 3;
                        setting->value.u = MakeIniColor(red, green2, blue3, 255);
                    }
                }
                break;
                case 8: {
                    count = GetPrivateProfileStringA(key17, section2, "", value2, 256, filename);
                    if (count)
                    {
                        unsigned int red, green2, blue3, alpha;
                        success3 = FUN_00eca4a6(value2, "%u,%u,%u,%u", &red, &green2, &blue3, &alpha) == 4;
                        setting->value.u = MakeIniColor(red, green2, blue3, alpha);
                    }
                }
                break;
                case 0: {
                    int defaultBoolean = setting->GetBoolean() ? 1 : 0;
                    int number6 = GetPrivateProfileIntA(key17, section2, defaultBoolean, filename);
                    setting->value.b = number6 != 0;
                }
                break;
                default: {
                    setting->SetInteger(GetPrivateProfileIntA(key17, section2, setting->GetInteger(), filename));
                }
                break;
                }
            }
            if (opened3)
                Close();
        }
    }
    return success3;
}

typedef void(__cdecl* CbQ)(void*, bool);
extern CbQ DAT_01202e08;
struct FUN_00c455a0_cls
{
    char pad[0x30];
    unsigned int m_uiObjectFlags;
    char pad2[0xae - 0x34];
    unsigned char m_ucLo;
    unsigned char m_ucHi;
    void SetBitQ(bool b, unsigned int m)
    {
        if (b)
            m_uiObjectFlags |= m;
        else
            m_uiObjectFlags &= ~m;
    }
    bool IsHiddenQ()
    {
        return (m_uiObjectFlags & 1) != 0;
    }
    unsigned char GetLo()
    {
        unsigned char c = m_ucLo;
        return c;
    }
    unsigned char GetHi()
    {
        unsigned char c = m_ucHi;
        return c;
    }
    bool __thiscall BSRangeNode_SetCurrent(unsigned char ucLevel);
};
// @fnv 0x00c455a0
// src: XBOX_PDB 0x00c455a0
bool __thiscall FUN_00c455a0_cls::BSRangeNode_SetCurrent(unsigned char ucLevel)
{
    bool bNew;
    bool bOld = !IsHiddenQ();
    bNew = ucLevel >= GetLo() && ucLevel <= GetHi();
    if (bOld != bNew)
    {
        SetBitQ(!bNew, 1);
        if (DAT_01202e08)
            DAT_01202e08(this, bNew);
    }
    return bNew;
}


struct OwnerWord
{
    int owner;
};

// /Ob1 tries to inline these and then refuses on size. The refused locals stay
// in the caller's frame (two for the lock, one for the insert) and the calls remain.
// src: XBOX_PDB 0x0040fbf0
inline void GameLockA::BSSpinLock_Lock(int a)
{
    int passes;
    int spins;
    passes = a;
    spins = passes;
    passes = passes + 1;
    passes = passes + 2;
    passes = passes + 3;
    passes = passes + 4;
    passes = passes + 5;
    passes = passes + 6;
    passes = passes + 7;
    passes = passes + 8;
    passes = passes + 9;
    passes = passes + 10;
    passes = passes + 11;
    passes = passes + 12;
    passes = passes + 13;
    passes = passes + 14;
    passes = passes + 15;
    passes = passes + 16;
    passes = passes + 17;
    passes = passes + 18;
    passes = passes + 19;
    passes = passes + 20;
    passes = passes + 21;
    passes = passes + 22;
    passes = passes + 23;
    passes = passes + 24;
    passes = passes + 25;
    passes = passes + 26;
    passes = passes + 27;
    passes = passes + 28;
    passes = passes + 29;
    passes = passes + 30;
    passes = passes + 31;
    passes = passes + 32;
    passes = passes + 33;
    passes = passes + 34;
    passes = passes + 35;
    passes = passes + 36;
    passes = passes + 37;
    passes = passes + 38;
    passes = passes + 39;
    passes = passes + 40;
    spins = passes;
}

template <> inline unsigned int NiTArray<NiPointer<NiRefObject>, NiTNewInterface<NiPointer<NiRefObject> > >::Add(const NiPointer<NiRefObject>& element)
{
    int slot;
    slot = (unsigned int)&element;
    slot = slot + 1;
    slot = slot + 2;
    slot = slot + 3;
    slot = slot + 4;
    slot = slot + 5;
    slot = slot + 6;
    slot = slot + 7;
    slot = slot + 8;
    slot = slot + 9;
    slot = slot + 10;
    slot = slot + 11;
    slot = slot + 12;
    slot = slot + 13;
    slot = slot + 14;
    slot = slot + 15;
    slot = slot + 16;
    slot = slot + 17;
    slot = slot + 18;
    slot = slot + 19;
    slot = slot + 20;
    slot = slot + 21;
    slot = slot + 22;
    slot = slot + 23;
    slot = slot + 24;
    slot = slot + 25;
    slot = slot + 26;
    slot = slot + 27;
    slot = slot + 28;
    slot = slot + 29;
    slot = slot + 30;
    slot = slot + 31;
    slot = slot + 32;
    slot = slot + 33;
    slot = slot + 34;
    slot = slot + 35;
    slot = slot + 36;
    slot = slot + 37;
    slot = slot + 38;
    slot = slot + 39;
    slot = slot + 40;
    return slot;
}

// @fnv 0x00c45830
// src: XBOX_PDB 0x00c45830
void __cdecl NiObjectGarbage_Add(NiRefObject* object)
{
    DAT_01202e40.BSSpinLock_Lock(0);
    {
        NiPointer<NiRefObject> local(object);
        DAT_01202e20.Add(local);
    }
    DAT_01202e44 = DAT_01202e44 - 1;
    if (DAT_01202e44 == 0)
        reinterpret_cast<OwnerWord&>(DAT_01202e40).owner = 0;
}

struct C45Object
{
    virtual void v00();
    virtual void v04();
    volatile long m04;
    void Inc()
    {
        InterlockedIncrement(&m04);
    }
    void Dec()
    {
        if (!InterlockedDecrement(&m04))
            v04();
    }
};
struct C45Pointer
{
    C45Object* m00;
    C45Pointer(C45Object* p = 0) : m00(p)
    {
        if (m00)
            m00->Inc();
    }
    C45Pointer(const C45Pointer& p) : m00(p.m00)
    {
        if (m00)
            m00->Inc();
    }
    ~C45Pointer()
    {
        if (m00)
            m00->Dec();
    }
    C45Pointer& AssignRefCounted(const C45Pointer& p);
    bool operator!=(const C45Pointer& p) const
    {
        return m00 != p.m00;
    }
};

inline void C45TemporaryStorage()
{
    struct Storage
    {
        int m00, m04;
    } storage;
    (void)&storage;
}
// @fnv 0x00c45e50
template <> C45Pointer NiTArray<C45Pointer, NiTNewInterface<C45Pointer> >::RemoveAt(unsigned int index)
{
    if (index >= m_usSize)
        return C45Pointer();
    C45Pointer result = m_pBase[index];
    (m_pBase[index].AssignRefCounted(C45Pointer()), C45TemporaryStorage());
    if (result != C45Pointer())
        --m_usESize;
    if (index == (unsigned short)(m_usSize - 1))
        --m_usSize;
    return result;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

struct S00c46080_Tmp : public FUN_00c46270_Class
{
    S00c46080_Tmp(RefCountedObject* object = 0)
    {
        m_pObject = object;
        if (m_pObject)
        {
            RefCountedObject* obj = m_pObject;
            InterlockedIncrement(&obj->m_lObjectReferenceCount);
        }
    }
    ~S00c46080_Tmp()
    {
        int u1;
        int u2;
        if (m_pObject)
        {
            RefCountedObject* obj = m_pObject;
            if (InterlockedDecrement(&obj->m_lObjectReferenceCount) == 0)
            {
                obj->vfn_0004();
            }
        }
    }
};



// @fnv 0x00c46080
template <> void __thiscall NiTArray<FUN_00c46270_Class, NiTNewInterface<FUN_00c46270_Class> >::RemoveAll()
{
    for (unsigned short i = 0; i < m_usSize; ++i)
    {
        m_pBase[i].AssignRefCounted(S00c46080_Tmp());
    }
    m_usSize = 0;
    m_usESize = 0;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);


// operator= is inline but far past VC9's /Ob1 size limit, so the call stays
// out of line and its two locals remain reserved in the caller frame.
template <class T> struct MultiBoundPtr
{
    T* m_pObject;
    __forceinline ~MultiBoundPtr()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
    inline MultiBoundPtr& operator=(T* p);
};

template <class T> inline MultiBoundPtr<T>& MultiBoundPtr<T>::operator=(T* p)
{
    int gap0;
    int gap1;
    gap0 = (int)p;
    gap1 = gap0;
    gap0 = gap1 + 1;
    gap1 = gap0 + 2;
    gap0 = gap1 + 3;
    gap1 = gap0 + 4;
    gap0 = gap1 + 1;
    gap1 = gap0 + 2;
    gap0 = gap1 + 3;
    gap1 = gap0 + 4;
    gap0 = gap1 + 1;
    gap1 = gap0 + 2;
    gap0 = gap1 + 3;
    gap1 = gap0 + 4;
    gap0 = gap1 + 1;
    gap1 = gap0 + 2;
    gap0 = gap1 + 3;
    gap1 = gap0 + 4;
    gap0 = gap1 + 1;
    gap1 = gap0 + 2;
    gap0 = gap1 + 3;
    gap1 = gap0 + 4;
    gap0 = gap1 + 1;
    gap1 = gap0 + 2;
    gap0 = gap1 + 3;
    gap1 = gap0 + 4;
    gap0 = gap1 + 1;
    gap1 = gap0 + 2;
    gap0 = gap1 + 3;
    gap1 = gap0 + 4;
    gap0 = gap1 + 1;
    gap1 = gap0 + 2;
    gap0 = gap1 + 3;
    gap1 = gap0 + 4;
    gap0 = gap1 + 1;
    gap1 = gap0 + 2;
    gap0 = gap1 + 3;
    gap1 = gap0 + 4;
    gap0 = gap1 + 1;
    gap1 = gap0 + 2;
    gap0 = gap1 + 3;
    gap1 = gap0 + 4;
    gap0 = gap1 + 1;
    gap1 = gap0 + 2;
    gap0 = gap1 + 3;
    gap1 = gap0 + 4;
    gap0 = gap1 + 1;
    gap1 = gap0 + 2;
    gap0 = gap1 + 3;
    gap1 = gap0 + 4;
    gap0 = gap1 + 1;
    gap1 = gap0 + 2;
    gap0 = gap1 + 3;
    gap1 = gap0 + 4;
    gap0 = gap1 + 1;
    gap1 = gap0 + 2;
    gap0 = gap1 + 3;
    gap1 = gap0 + 4;
    gap0 = gap1 + 1;
    gap1 = gap0 + 2;
    gap0 = gap1 + 3;
    gap1 = gap0 + 4;
    gap0 = gap1 + 1;
    gap1 = gap0 + 2;
    gap0 = gap1 + 3;
    gap1 = gap0 + 4;
    gap0 = gap1 + 1;
    gap1 = gap0 + 2;
    gap0 = gap1 + 3;
    gap1 = gap0 + 4;
    gap0 = gap1 + 1;
    gap1 = gap0 + 2;
    gap0 = gap1 + 3;
    gap1 = gap0 + 4;
    gap0 = gap1 + 1;
    gap1 = gap0 + 2;
    gap0 = gap1 + 3;
    gap1 = gap0 + 4;
    gap0 = gap1 + 1;
    gap1 = gap0 + 2;
    gap0 = gap1 + 3;
    gap1 = gap0 + 4;
    if (p == (T*)1)
        return operator=((T*)0);
    return *this;
}

namespace mb {
struct FUN_00c46af0 : BSNiNode
{
    MultiBoundPtr<NiRefObject> multiBound;
    ~FUN_00c46af0();
};
}

// @fnv 0x00c46af0
mb::FUN_00c46af0::~FUN_00c46af0()
{
    multiBound = 0;
}

// FUN_00c47570 candidate
class FNV_Base_cls
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual int v98(int a1);
};
class FNV_Inner_cls : public FNV_Base_cls
{
};
class FNV_Mid_cls
{
  public:
    int unk00, unk04, unk08;
    FNV_Inner_cls* m_0c;
};
inline FNV_Base_cls* AsBase(FNV_Inner_cls* p)
{
    return p;
}
class FUN_00c47570_cls
{
  public:
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C,
        unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C,
        unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8;
    FNV_Mid_cls* m_ac;
    int BSMultiBoundNode_CheckBound(int a1);
};
// @fnv 0x00c47570
// src: XBOX_PDB 0x00c47570
int FUN_00c47570_cls::BSMultiBoundNode_CheckBound(int a1)
{
    FNV_Mid_cls* p2 = m_ac;
    FNV_Inner_cls* q = p2->m_0c;
    int res = AsBase(q)->v98(a1);
    return res;
}

// Geometry command emission for a polygon and its adjoining polygon.
struct GeometryPoint
{
    float x, y, z;
    GeometryPoint()
    {}
};
struct FUN_00a699d0
{
    GeometryPoint normal;
    float distance;
    FUN_00a699d0();
    FUN_00a699d0(const GeometryPoint*, const GeometryPoint*, const GeometryPoint*);
    int ClassifyPoint(const GeometryPoint* point)
    {
        float value = normal.x * point->x + normal.y * point->y + normal.z * point->z - distance;
        if (value < 0.0)
            return 2;
        else if (value > 0.0)
            return 1;
        else
            return 0;
    }
};
struct FUN_0045c620
{
    FUN_00a699d0 planes[6];
    int unk60;
    FUN_0045c620()
    {
        unk60 = 0x3f;
    }
    __forceinline void ClearPlane(int bit)
    {
        unk60 &= ~(1 << bit);
    }
};
struct CommandPolygon
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int type;
    int unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc;
    int unke0, unke4, unke8;
    CommandPolygon* neighbors[4];
    int BSOcclusionPlane_GetJoinedPlaneType();
    void BSOcclusionPlane_UpdateFrustumPlanes(GeometryPoint, void*);
    void BSOcclusionPlane_GetVertices(GeometryPoint*);
    __forceinline CommandPolygon* NeighborAt(int i) const
    {
        return neighbors[i];
    }
    __forceinline int GetType() const
    {
        int value = type;
        return value;
    }
    __forceinline int SideIndex() const
    {
        int value = neighbors[1] ? 1 : 3;
        return value;
    }
    __forceinline int EndIndex() const
    {
        int value = neighbors[0] ? 0 : 2;
        return value;
    }
    __forceinline CommandPolygon* SideNeighbor() const
    {
        int index1 = SideIndex();
        return NeighborAt(index1);
    }
    __forceinline CommandPolygon* EndNeighbor() const
    {
        int index1 = neighbors[0] ? 0 : 2;
        return NeighborAt(index1);
    }
};
struct CommandRecords
{
    void* vtable;
    FUN_0045c620* data;
    int allocated;
    int capacity;
    void FUN_00c4a070(int, bool);
    __forceinline int GetCapacity() const
    {
        int value = capacity;
        return value;
    }
    __forceinline FUN_0045c620& operator[](int i)
    {
        return data[i];
    }
};
struct CommandArray
{
    void* vtable;
    Elem0C* m_pData;
    int allocated, m_uiSize;
    void FUN_00c4a1e0(int, bool);
    __forceinline int GetCapacity() const
    {
        int value = m_uiSize;
        return value;
    }
    __forceinline Elem0C& operator[](int i)
    {
        return m_pData[i];
    }
};
struct GeometryCommands
{
    unsigned char state;
    CommandRecords records;
    CommandArray commands;
    int recordCount, commandCount, unknown2c;
    FNV_Local workingRecord;
    GeometryPoint origin;
    void BSCompoundFrustum_AddOcclusionPlane(CommandPolygon* polygon);
};
// @fnv 0x00c47d20
// src: COMMUNITY 0x00c47d20
void GeometryCommands::BSCompoundFrustum_AddOcclusionPlane(CommandPolygon* polygon)
{
    int type = polygon->BSOcclusionPlane_GetJoinedPlaneType();
    CommandPolygon* neighborTriangleA =
        type == 1 ? polygon->NeighborAt(polygon->SideIndex()) : polygon->NeighborAt(polygon->EndIndex());
    bool kA1_1 = false;
    int side = 0;
    if (neighborTriangleA)
    {
        GeometryPoint verticesCheck2[4];
        FUN_0045c620 record2_2;
        polygon->BSOcclusionPlane_UpdateFrustumPlanes(origin, &record2_2);
        polygon->BSOcclusionPlane_GetVertices(verticesCheck2);
        FUN_00a699d0 plane4(&verticesCheck2[0], &verticesCheck2[1], &verticesCheck2[2]);
        side = plane4.ClassifyPoint(&origin);
        neighborTriangleA->BSOcclusionPlane_UpdateFrustumPlanes(origin, &record2_2);
        neighborTriangleA->BSOcclusionPlane_GetVertices(verticesCheck2);
        plane4 = FUN_00a699d0(&verticesCheck2[0], &verticesCheck2[1], &verticesCheck2[2]);
        kA1_1 = side == plane4.ClassifyPoint(&origin);
    }
    if ((neighborTriangleA && neighborTriangleA->GetType() != 1) || !kA1_1)
    {
        if (commandCount + 2 >= commands.GetCapacity())
        {
            commands.FUN_00c4a1e0(commands.GetCapacity() + 10, true);
        }
        if (recordCount + 1 >= records.GetCapacity())
            records.FUN_00c4a070(records.GetCapacity() + 4, true);
        commands[commandCount].a = 8;
        ++commandCount;
        commands[commandCount].a = recordCount;
        ++commandCount;
        polygon->BSOcclusionPlane_UpdateFrustumPlanes(origin, &records[recordCount]);
        ++recordCount;
        return;
    }
    switch (type)
    {
    case 0: {
        if (commandCount + 2 >= commands.GetCapacity())
        {
            commands.FUN_00c4a1e0(commands.GetCapacity() + 10, true);
        }
        if (recordCount + 1 >= records.GetCapacity())
            records.FUN_00c4a070(records.GetCapacity() + 4, true);
        commands[commandCount].a = 8;
        ++commandCount;
        commands[commandCount].a = recordCount;
        ++commandCount;
        polygon->BSOcclusionPlane_UpdateFrustumPlanes(origin, &records[recordCount]);
        ++recordCount;
        return;
        break;
    }
    case 1: {
        if (commandCount + 12 >= commands.GetCapacity())
        {
            commands.FUN_00c4a1e0(commands.GetCapacity() + 12, true);
        }
        if (recordCount + 4 >= records.GetCapacity())
            records.FUN_00c4a070(records.GetCapacity() + 4, true);
        commands[commandCount++].a = 4;
        commands[commandCount++].a = 8;
        commands[commandCount++].a = recordCount;
        commands[commandCount++].a = 8;
        commands[commandCount++].a = recordCount + 1;
        commands[commandCount++].a = 5;
        commands[commandCount++].a = 8;
        commands[commandCount++].a = recordCount + 2;
        commands[commandCount++].a = 8;
        commands[commandCount++].a = recordCount + 3;
        commands[commandCount++].a = 6;
        commands[commandCount++].a = 6;
        polygon->BSOcclusionPlane_UpdateFrustumPlanes(origin, &records[recordCount]);
        polygon->BSOcclusionPlane_UpdateFrustumPlanes(origin, &records[recordCount + 2]);
        int index1 = polygon->neighbors[1] ? 1 : 3;
        int kA114_2 = 0;
        side = 1;
        if (index1 == 1)
            kA114_2 = side == 1 ? 2 : 3;
        else
            kA114_2 = side == 1 ? 3 : 5;
        records[recordCount + 2].ClearPlane(kA114_2);
        CommandPolygon* adjacent3 = polygon->neighbors[index1];
        adjacent3->BSOcclusionPlane_UpdateFrustumPlanes(origin, &records[recordCount + 1]);
        adjacent3->BSOcclusionPlane_UpdateFrustumPlanes(origin, &records[recordCount + 3]);
        if (index1 == 1)
            kA114_2 = kA114_2 == 2 ? 3 : 2;
        else
            kA114_2 = kA114_2 == 4 ? 5 : 4;
        records[recordCount + 3].ClearPlane(kA114_2);
        recordCount += 4;
        break;
    }
    }
}

struct Elem_c48800
{
    int field0;
    int field4;
    int field8;
};

__forceinline Elem_c48800* elemAt(Elem_c48800* p, int i)
{
    return &p[i];
}

struct Sub_c4a070
{
    int unk00;
    void FUN_00c4a070(int, bool);
};

struct Sub_c4a1e0
{
    int unk00;
    void FUN_00c4a1e0(int, bool);
};

struct FUN_00c48800_cls
{
    char m_00;
    char unk01;
    char unk02;
    char unk03;
    Sub_c4a070 m_04;
    NavEntryItem_blk_00c40000_od_ob1_variant* m_08;
    int unk0C;
    int m_10;
    Sub_c4a1e0 m_14;
    Elem_c48800* m_18;
    int unk1C;
    int m_20;
    int m_24;
    int m_28;

    void BSCompoundFrustum_AddCompoundFrustum(FUN_00c48800_cls* arg);
};

// @fnv 0x00c48800
// src: COMMUNITY 0x00c48800
void FUN_00c48800_cls::BSCompoundFrustum_AddCompoundFrustum(FUN_00c48800_cls* arg)
{
    int cf;
    int q;
    int b;
    int ba;
    int k;
    int l;
    int c;
    Elem_c48800* e;
    NavEntryItem_blk_00c40000_od_ob1_variant* j;

    ba = this->m_20;
    if (arg->m_28 + this->m_28 + 1 >= ba)
    {
        this->m_14.FUN_00c4a1e0((k = this->m_20) + (arg->m_28 + 1 > 10 ? arg->m_28 + 1 : 10), true);
    }
    l = this->m_10;
    if (arg->m_24 + this->m_24 + 1 >= l)
    {
        this->m_04.FUN_00c4a070((c = this->m_10) + (arg->m_24 + 1 > 4 ? arg->m_24 + 1 : 4), true);
    }
    this->m_00 = 0;
    for (cf = 0; cf < arg->m_28; ++cf)
    {
        e = &arg->m_18[cf];
        this->m_18[this->m_28 + cf].field0 = e->field0;
    }
    for (q = 0; q < arg->m_24; ++q)
    {
        j = &arg->m_08[q];
        this->m_08[this->m_24 + q] = *j;
    }
    if (this->m_24 != 0)
    {
        for (b = this->m_28; b < this->m_28 + arg->m_28; ++b)
        {
            switch (this->m_18[b].field0)
            {
            case 7:
            case 8:
                elemAt(this->m_18, b + 1)->field0 += this->m_24;
                b++;
                break;
            }
        }
    }
    this->m_28 += arg->m_28;
    this->m_24 += arg->m_24;
}

struct Q48Tok
{
    int m_type;
    int m_kPointA;
    int m_kPointB;
};
struct Q48Arr
{
    void* vtbl;
    Q48Tok* m_data;
    int m_auiShapeKeys;
    int m_alloc;
    inline Q48Tok& At(int i)
    {
        return m_data[i];
    }
    inline int Alloc()
    {
        return m_alloc;
    }
    void FUN_00c4a1e0(int n, bool b);
};
struct Q48Obj
{
    char pad[0x14];
    Q48Arr m_toks;
    int m_24;
    int m_uiItemCount;
    void ShiftElements(bool a, bool b);
    void BSCompoundFrustum_MakeIntoUnion();
};
// @fnv 0x00c48b90
// src: COMMUNITY 0x00c48b90
void Q48Obj::BSCompoundFrustum_MakeIntoUnion()
{
    bool ok = true;
    if (m_toks.At(0).m_type == 5)
    {
        int iDepth = 1;
        int iTok5 = 1;
        while (iDepth > 0 && iTok5 < m_uiItemCount)
        {
            switch (m_toks.At(iTok5).m_type)
            {
            case 4:
            case 5:
                iDepth++;
                break;
            case 6:
                iDepth--;
                break;
            }
            iTok5++;
        }
        if (iTok5 == m_uiItemCount && iDepth == 0)
            ok = false;
    }
    if (ok)
    {
        if (m_uiItemCount + 1 >= m_toks.Alloc())
            m_toks.FUN_00c4a1e0(m_toks.Alloc() + 10, true);
        ShiftElements(true, false);
        m_toks.At(0).m_type = 5;
    }
    else
    {
        m_uiItemCount--;
    }
}

struct TreeVector;
struct TreePlane
{
    float x, y, z, distance;
    float EvaluatePlane(const TreeVector& vector) const;
};
struct TreeVector
{
    float x;
    float y;
    float z;
    float w;
    float GetW() const
    {
        return w;
    }
    int ClassifySphereAgainstPlane(TreePlane* plane) const;
    int ClassifySphereAgainstPlane(TreePlane* plane)
    {
        float distance = plane->EvaluatePlane(*this);
        if (distance < -w)
            return 2;
        else if (distance > w)
            return 1;
        else
            return 0;
    }
};
extern TreeVector DAT_011f4288;

struct TreeQuery
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    TreeVector* m_pkVector;  // +0x20

    int HasVector() const
    {
        return m_pkVector && m_pkVector->GetW() != 0.0;
    }
    const TreeVector& GetAudioPosition() const
    {
        return m_pkVector ? *m_pkVector : DAT_011f4288;
    }
};

struct TreeEntry
{
    TreePlane planes[6];
    unsigned int activePlanes;
};

struct TreeNode
{
    int m_iType;
    int m_iField04;
    int m_iFail;
};

class TreeEvaluator
{
  public:
    int unk00;
    int unk04;
    TreeEntry* m_pkEntryArray;  // +0x08
    int unk0c;
    int unk10;
    int unk14;
    TreeNode* m_pkNodes;  // +0x18
    int unk1c;
    int unk20;
    int unk24;
    int m_iNodeCount;        // +0x28
    int m_iRoot;             // +0x2c
    TreeEntry m_kRootEntry;  // +0x30
    int unk94;
    int unk98;
    int unk9c;
    bool m_bSkipRoot;  // +0xa0

    TreeEntry* GetEntry(int index)
    {
        TreeNode* pkNext = &m_pkNodes[index];
        return &m_pkEntryArray[pkNext->m_iType];
    }
    template <class Bound> bool ProcessEntries(Bound* pkVector, TreeEntry* pkEntry)
    {
        if (!pkEntry->activePlanes)
            return true;
        else
        {
            int planeIndex;
            for (planeIndex = 0; planeIndex < 6; ++planeIndex)
            {
                if (pkEntry->activePlanes & (1 << planeIndex))
                {
                    int side = pkVector->ClassifySphereAgainstPlane(&pkEntry->planes[planeIndex]);
                    if (side == 2)
                        break;
                    if (side == 1)
                        pkEntry->activePlanes &= ~(1 << planeIndex);
                }
            }
            if (planeIndex == 6)
                return true;
        }
        return false;
    }
// src: COMMUNITY 0x00c4a790
    bool BSCompoundFrustum_TestNotContained(TreeVector* pkVector, TreeEntry* pkEntry)
    {
        if (!pkEntry->activePlanes)
            return false;
        else
        {
            int planeIndex;
            for (planeIndex = 0; planeIndex < 6; ++planeIndex)
            {
                if (pkEntry->activePlanes & (1 << planeIndex))
                {
                    int side = pkVector->ClassifySphereAgainstPlane(&pkEntry->planes[planeIndex]);
                    if (side != 1)
                        break;
                    else if (side == 1)
                        pkEntry->activePlanes &= ~(1 << planeIndex);
                }
            }
            if (planeIndex == 6)
                return false;
        }
        return true;
    }
    bool BSCompoundFrustum_Process(TreeQuery* pkQuery);
};

// @fnv 0x00c491a0
// src: COMMUNITY 0x00c491a0
bool TreeEvaluator::BSCompoundFrustum_Process(TreeQuery* pkQuery)
{
    if (!pkQuery->HasVector())
        return false;
    TreeEntry* pkEntry = 0;
    TreeVector kVector = pkQuery->GetAudioPosition();
    bool bResultTmp = true;
    if (!m_bSkipRoot)
        bResultTmp = ProcessEntries(static_cast<const TreeVector*>(&kVector), &m_kRootEntry);
    if (bResultTmp && m_iNodeCount > 0)
    {
        int i = m_iRoot;
        while (m_pkNodes[i].m_iType != 2 && m_pkNodes[i].m_iType != 3)
        {
            bool bPass = false;
            switch (m_pkNodes[i].m_iType)
            {
            case 7: {
                pkEntry = GetEntry(i + 1);
                bPass = ProcessEntries(&kVector, pkEntry);
                break;
            }
            case 8: {
                pkEntry = GetEntry(i + 1);
                bPass = BSCompoundFrustum_TestNotContained(&kVector, pkEntry);
                break;
            }
            }
            i = bPass ? m_pkNodes[i].m_iField04 : m_pkNodes[i].m_iFail;
        }
        bResultTmp = m_pkNodes[i].m_iType == 2;
    }
    return bResultTmp;
}

struct ObjC4aa40 : FUN_00c450d0
{
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
    __forceinline static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
    __forceinline ObjC4aa40()
    {
        vtbl = (int)&DAT_010c1eb4;
    }
};

struct OwnerC4aa40 : FUN_00c4aae0_class
{
    ObjC4aa40* BSBlastNode_CreateClone(int a1);
};

// @fnv 0x00c4aa40
// src: XBOX_PDB 0x00c4aa40
ObjC4aa40* OwnerC4aa40::BSBlastNode_CreateClone(int a1)
{
    ObjC4aa40* p = new ObjC4aa40();
    this->BSRangeNode_CopyMembers((int)p, a1);
    return p;
}

extern unsigned int DAT_010c1fc4;

// @fnv 0x00c4ae60
// src: EXE 0x00c4ae60
BSDebrisNode* __cdecl BSDebrisNode_CreateObject()
{
    return new BSDebrisNode;
}

void* __cdecl Object_DispatchCommandFour(unsigned int size);

extern int DAT_010c20d4;

struct S00c4af00_Obj : FUN_00c450d0
{
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
    S00c4af00_Obj() : FUN_00c450d0()
    {
        vtbl = (int)&DAT_010c20d4;
    }
    static void* operator new(unsigned int size) throw()
    {
        return Object_DispatchCommandFour(size);
    }
};

struct S00c4af00_Cls
{
    void __thiscall BSDamageStage_CopyMembers(S00c4af00_Obj* obj, unsigned int arg);
    S00c4af00_Obj* BSDamageStage_CreateClone(unsigned int arg);
};

// @fnv 0x00c4af00
// src: XBOX_PDB 0x00c4af00
S00c4af00_Obj* S00c4af00_Cls::BSDamageStage_CreateClone(unsigned int arg)
{
    S00c4af00_Obj* obj = new S00c4af00_Obj();
    this->BSDamageStage_CopyMembers(obj, arg);
    return obj;
}

extern int DAT_010c20d4;
struct C4B0C0_Obj : FUN_00c450d0
{
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
    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
    __forceinline C4B0C0_Obj()
    {
        vtbl = (int)&DAT_010c20d4;
    }
};
// @fnv 0x00c4b0c0
// src: EXE 0x00c4b0c0
C4B0C0_Obj* BSDamageStage_CreateObject()
{
    return new C4B0C0_Obj;
}

// Same-TU body is visible, so /Ob1 tries to inline it and refuses.
// The four locals are the caller's unreferenced 16-byte hole; the call stays.
struct FUN_00546780_shell
{
    virtual void v00();
    virtual void v04();
    virtual const NiRTTI* GetRTTI() const;
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
    unsigned int flags30;
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
    FUN_00546780_shell** children;
    unsigned short unkA4;
    unsigned short count;

// src: COMMUNITY 0x00546780
    void NiAVObject_SetAlwaysDraw(bool b)
    {
        int a = b ? 1 : 2;
        int c = a + 1;
        int d = c + 2;
        int e = d + 3;
        a = e + 4;
        c = a + 5;
        d = c + 6;
        e = d + 7;
        a = e + 8;
        c = a + 9;
        d = c + 10;
        e = d + 11;
        a = e + 12;
        c = a + 13;
        d = c + 14;
        e = d + 15;
        flags30 = a + c + d + e;
    }

    void SetFlag(bool b, unsigned int mask)
    {
        if (b)
            flags30 |= mask;
        else
            flags30 &= ~mask;
    }
};

extern NiRTTI DAT_011f4428;

inline bool KindOfShell(const NiRTTI& query, const NiRTTI* p)
{
    while (p)
    {
        if (p == &query)
            return true;
        p = p->m_pBaseRTTI;
    }
    return false;
}

inline FUN_00546780_shell* ChildAtShell(FUN_00546780_shell* node, unsigned int i)
{
    FUN_00546780_shell** slot = &node->children[i];
    return *slot;
}

// @fnv 0x00c4b220
// src: COMMUNITY 0x00c4b220
void __cdecl BSUtilities_SetAlwaysDraw(FUN_00546780_shell* obj)
{
    if (obj != 0)
    {
        obj->NiAVObject_SetAlwaysDraw(true);
        obj->SetFlag(true, 0x2000);
    }
    FUN_00546780_shell* node;
    if (!obj)
        node = 0;
    else
        node = KindOfShell(DAT_011f4428, obj->GetRTTI()) ? obj : 0;
    if (node)
    {
        for (unsigned int i = 0; i < node->count; ++i)
            BSUtilities_SetAlwaysDraw(ChildAtShell(node, i));
    }
}

#include <math.h>
extern const double DAT_01017cf8;
float __cdecl NiSqrt_004579e0(float);
#pragma intrinsic(memcpy)
class BasisVector : public NiPoint3
{
  public:
    float SquaredLength() const;
// src: XBOX_PDB 0x004a0c10
    inline void Unitize_004a0c10()
    {
        float squaredLength = SquaredLength();
        float length = NiSqrt_004579e0(squaredLength);
        if (length > DAT_01017cf8)
        {
            float inverse = 1.0f / length;
            x *= inverse;
            y *= inverse;
            z *= inverse;
        }
        else
        {
            x = 0.0f;
            y = 0.0f;
            z = 0.0f;
        }
    }
    inline BasisVector Cross(const BasisVector& other) const
    {
        return BasisVector(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
    }
    __forceinline BasisVector()
    {}
    __forceinline BasisVector(float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }
};

__forceinline void NiMatrix3::SetCol(unsigned int col, const NiPoint3& v)
{
    (&m_pEntry[0][0])[col] = v.x;
    (&m_pEntry[1][0])[col] = v.y;
    (&m_pEntry[2][0])[col] = v.z;
}
// @fnv 0x00c4b8a0
// src: XBOX_PDB 0x00c4b8a0
NiMatrix3 __cdecl BSUtilities_GetRotationZToVectorTranspose(NiPoint3 direction)
{
    BasisVector normal_2;
    memcpy(&normal_2, &direction, sizeof(normal_2));
    normal_2.Unitize_004a0c10();
    float ax = fabs(normal_2.x);
    float ayVal = fabs(normal_2.y);
    float normal7 = fabs(normal_2.z);
    BasisVector cross2;
    if (ax <= ayVal && ax <= normal7)
    {
        memcpy(&cross2, &(const BasisVector&)BasisVector(0.0f, -normal_2.z, normal_2.y), sizeof(cross2));
    }
    else if (ayVal <= ax && ayVal <= normal7)
    {
        memcpy(&cross2, &(const BasisVector&)BasisVector(-normal_2.z, 0.0f, normal_2.x), sizeof(cross2));
    }
    else
    {
        memcpy(&cross2, &(const BasisVector&)BasisVector(-normal_2.y, normal_2.x, 0.0f), sizeof(cross2));
    }
    cross2.Unitize_004a0c10();
    BasisVector crossTmp;
    memcpy(&crossTmp, &(const BasisVector&)cross2.Cross(normal_2), sizeof(crossTmp));
    crossTmp.Unitize_004a0c10();
    memcpy(&cross2, &(const BasisVector&)crossTmp.Cross(normal_2), sizeof(cross2));
    cross2.Unitize_004a0c10();
    NiMatrix3 rotationB;
    rotationB.SetCol(0, cross2);
    rotationB.SetCol(1, crossTmp);
    rotationB.SetCol(2, normal_2);
    return rotationB;
}

#pragma function(memcpy)
struct SPQ
{
    NiRefObject* m_pObject;
    SPQ(NiRefObject* p = 0)
    {
        m_pObject = p;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    ~SPQ()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
    SPQ& __thiscall FUN_0066b0d0(NiRefObject* p);
};
inline void DeadQ4()
{
    int aiQ[4];
}
struct FUN_00c4ca80
{
    void* m_00;
    void* m_04;
    void* m_08;
    char pad0c[0x24 - 0x0c];
    void* m_24;
    void* m_28;
    SPQ m_sp2c;
    SPQ m_sp30;
    NiPoint3 m_pt34;
    FUN_00c4ca80();
};
// @fnv 0x00c4ca80
#pragma intrinsic(memcpy)
FUN_00c4ca80::FUN_00c4ca80()
{
    m_24 = 0;
    m_00 = 0;
    m_08 = 0;
    m_04 = 0;
    m_28 = 0;
    m_sp30.FUN_0066b0d0(0);
    m_sp2c.FUN_0066b0d0(0);
    memcpy(&m_pt34, &DAT_011f426c, sizeof(m_pt34));
    DeadQ4();
}

#pragma function(memcpy)
namespace fnv_00c4cba0 {
struct SPQ
{
    NiRefObject* m_pObject;
    SPQ(NiRefObject* p = 0)
    {
        m_pObject = p;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    ~SPQ()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
    SPQ& __thiscall FUN_0066b0d0(NiRefObject* p);
};
inline void DeadQ4()
{
    int aiQ[4];
}
struct OwnerQ
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* GetM8()
    {
        return m_08;
    }
};
struct FUN_00c4cba0
{
    OwnerQ* m_00;
    void* m_04;
    void* m_08;
    char pad0c[0x24 - 0x0c];
    void* m_24;
    void* m_28;
    SPQ m_sp2c;
    SPQ m_sp30;
    NiPoint3 m_pt34;
    FUN_00c4cba0(OwnerQ* p);
    void __thiscall BSPolygon2D_Initialize();
};
// @fnv 0x00c4cba0
#pragma intrinsic(memcpy)
FUN_00c4cba0::FUN_00c4cba0(OwnerQ* p)
{
    m_24 = p->GetM8();
    m_00 = p;
    m_08 = 0;
    m_04 = 0;
    m_28 = 0;
    m_sp30.FUN_0066b0d0(0);
    m_sp2c.FUN_0066b0d0(0);
    memcpy(&m_pt34, &DAT_011f426c, sizeof(m_pt34));
    BSPolygon2D_Initialize();
    DeadQ4();
}
#pragma function(memcpy)
}  // namespace fnv_00c4cba0

struct Obj
{
    virtual int V0(int a);
    virtual void V1();
    long rc;
};
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
struct Ref
{
    Obj* p;
    ~Ref()
    {
        if (p)
        {
            Obj* q = p;
            if (InterlockedDecrement(&q->rc) == 0)
                q->V1();
        }
    }
};
struct FUN_00c4ccd0
{
    Obj* m00;
    int u04, u08, u0c, u10, u14, u18, u1c, u20, u24;
    int m28;
    Ref r2c;
    Ref r30;
    ~FUN_00c4ccd0();
};
// @fnv 0x00c4ccd0
FUN_00c4ccd0::~FUN_00c4ccd0()
{
    if (m28 == 0)
    {
        Obj* o = m00;
        Obj* p = o;
        (void)(p ? p->V0(1) : 0);
    }
}

// These arithmetic calls bind to NiPoint3 at 0x0063c8a0 and 0x0053d280.
// Keep the /Ob1 bodies visible on the shared declaration.
// src: GUESS 0x0053d280 (confidence: low)
inline NiPoint3 NiPoint3::ProcessAndReturnValue_0053d280(float scale) const
{
    float inverse = 1.0f / scale;
    return NiPoint3(x * inverse, y * inverse, z * inverse);
}
// src: GUESS 0x00439ef0 (confidence: high)
inline NiPoint3 NiPoint3::SubtractIntoVector(const NiPoint3& other) const
{
    return NiPoint3(x - other.x, y - other.y, z - other.z);
}
extern NiPoint3 _DAT_011f426c;
struct Points370
{
    unsigned int unk00;
    NiPoint3* points;
    NiPoint3& GetPoint(int index)
    {
        return points[index];
    }
    void SetPoint(int index, const NiPoint3& point)
    {
        points[index] = point;
    }
};
struct Mesh370
{
    Points370* data;
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    int count;
    unsigned int unk28, unk2c, unk30;
    NiPoint3 center;
    void ProcessEntries_00c4ce00();
};
// @fnv 0x00c4ce00
// src: GUESS 0x00c4ce00 (confidence: low)
void Mesh370::ProcessEntries_00c4ce00()
{
    NiPoint3 sum = _DAT_011f426c;
    for (int i = 0; i < count; ++i)
        sum.ComputeValue_0063c8a0(data->points[i]);
    NiPoint3 average = sum.ProcessAndReturnValue_0053d280((float)count);
    for (int j = 0; j < count; ++j)
    {
        data->SetPoint(j, static_cast<const NiPoint3&>(data->GetPoint(j)).SubtractIntoVector(average));
    }
    center = average;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
inline long NiIncrement086(volatile long* value)
{
    long result = InterlockedIncrement(value);
    return result;
}
inline long NiDecrement086(volatile long* value)
{
    long result = InterlockedDecrement(value);
    return result;
}

extern int DAT_01016024;
extern int DAT_0106abe4;
struct FUN_00438690
{
    int* table;
    unsigned int* data;
    unsigned int size;
    unsigned int capacity;
    void BSSimpleArray_float_1024_InitialSetup(unsigned int, unsigned int);
    unsigned int FUN_007cad50();
    void Construct(unsigned int*, unsigned int);
    inline unsigned int FUN_007cb2e0(unsigned int* value)
    {
        unsigned int index = FUN_007cad50();
        Construct(&data[index], 1);
        data[index] = *value;
        return index;
    }
    void BSSimpleArray_unsigned_int_1024_Remove(unsigned int, unsigned int);
    __forceinline FUN_00438690()
    {
        table = &DAT_01016024;
        BSSimpleArray_float_1024_InitialSetup(0, 0);
    }
    __forceinline void Wrap(int& index)
    {
        volatile int divisor = size;
        if (divisor < 0)
            return;
        if (index < 0)
        {
            index = index % divisor + divisor;
            return;
        }
        else
            index = index % divisor;
    }
    __forceinline unsigned int GetSize() const
    {
        return size;
    }
    __forceinline const unsigned int& GetAt(unsigned int index)
    {
        return data[index];
    }
    __forceinline unsigned int& operator[](unsigned int index)
    {
        return data[index];
    }
    ~FUN_00438690();
};
struct WrappedIndex086
{
    union
    {
        int value;
        unsigned int bits : 32;
    };
    __forceinline void Wrap(const FUN_00438690& array)
    {
        volatile int divisor = array.size;
        if (divisor < 0)
            return;
        if (value < 0)
        {
            value = (int)bits % divisor + divisor;
            return;
        }
        else
            value = (int)bits % divisor;
    }
};
struct Vertex086
{
    union
    {
        struct
        {
            float x, y, z;
        };
        float coordinates[3];
    };
    inline bool operator==(const Vertex086& rhs) const
    {
        for (unsigned int i = 0; i < 3; i++)
            if (coordinates[i] != rhs.coordinates[i])
                return false;
        return true;
    }
    inline bool operator!=(const Vertex086& rhs) const
    {
        return !(*this == rhs);
    }
};
struct Vertices086
{
    int table;
    Vertex086* data;
    unsigned int size;
    __forceinline unsigned int GetSize() const
    {
        return size;
    }
    __forceinline Vertex086& operator[](unsigned int index)
    {
        return data[index];
    }
};
__forceinline bool ShortEquals(const unsigned short& a, const unsigned int& b)
{
    return a == b;
}
struct Shorts086
{
    int* table;
    unsigned short* data;
    unsigned int size;
    unsigned int capacity;
    void BSSimpleArray_unsigned_short_1024_InitialSetup(unsigned int, unsigned int);
    unsigned int GetNextPosition();
    void FUN_005ef650(unsigned short*, unsigned int);
    inline unsigned int Append(const unsigned short& value)
    {
        unsigned int index = GetNextPosition();
        FUN_005ef650(&data[index], 1);
        data[index] = value;
        return index;
    }
    void BSSimpleArray_unsigned_short_1024_Remove(unsigned int, unsigned int);
    __forceinline unsigned int Find(const unsigned int& value)
    {
        for (unsigned int i = 0; i < size; i++)
        {
            if (data && ShortEquals(data[i], value))
                return i;
        }
        return -1;
    }
};
struct Alloc086
{
    void* Game_DoHeapAlloc(unsigned int);
};
extern "C" char DAT_011f6238;
struct NewShorts086 : Shorts086
{
    __forceinline NewShorts086()
    {
        table = &DAT_0106abe4;
        BSSimpleArray_unsigned_short_1024_InitialSetup(0, 0);
    }
    __forceinline static void* operator new(unsigned int n)
    {
        return ((Alloc086*)&DAT_011f6238)->Game_DoHeapAlloc(n);
    }
    static void operator delete(void*);
};
struct RefBase086
{
    virtual void v0();
    virtual void v1();
    int unk04;
    inline void AcquireReference()
    {
        NiIncrement086((volatile long*)&unk04);
    }
    inline void DecRef()
    {
        if (!NiDecrement086((volatile long*)&unk04))
            v1();
    }
};
// The original allocator's inline expansion reserved these two stack slots.
inline void ReserveNiNodeAllocationStack()
{
    unsigned int requested;
    unsigned int alignment;
}
struct Holder086
{
    NiNode* value;
    inline Holder086& operator=(NiNode* object)
    {
        if (value != object)
        {
            if (value)
                reinterpret_cast<RefBase086*>(value)->DecRef();
            value = object;
            if (value)
                reinterpret_cast<RefBase086*>(value)->AcquireReference();
        }
        return *this;
    }
    __forceinline operator NiNode*() const
    {
        return value;
    }
    __forceinline NiNode* operator->() const
    {
        return value;
    }
};
struct Triangulator086
{
    Vertices086* vertices;
    Shorts086* reflex;
    Shorts086* triangles;
    int unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    int count;
    Holder086 node, mesh;
    bool IsKeyValid(unsigned int, unsigned int, unsigned int);
    int GetPointSide(Vertex086, Vertex086, Vertex086);
    unsigned int BSPolygon2D_CreateTriData();
    void* CreateInstance(unsigned int);
    void BSPolygon2D_Triangulate();
};
__forceinline void WrapIndex(int& index, const int& size)
{
    if (size < 0)
        return;
    if (index < 0)
    {
        index = index % size + size;
        return;
    }
    else
        index = index % size;
}
// @fnv 0x00c4cf80
// src: COMMUNITY 0x00c4cf80
void Triangulator086::BSPolygon2D_Triangulate()
{
    FUN_00438690 remainingVal;
    unsigned int currentItem;
    Vertex086 point21, first;
    unsigned int i1;
    WrappedIndex086 indexC_, previous4, old44, before8, after4;
    unsigned int foundPos8;
    int direction5, dir5;
    unsigned int total3;
    for (i1 = 0; i1 < vertices->GetSize(); i1++)
        remainingVal.FUN_007cb2e0(&i1);
    currentItem = 2;
    point21 = (*vertices)[currentItem];
    first = (*vertices)[0];
    while (point21 != first && remainingVal.GetSize() > 3)
    {
        indexC_.value = currentItem - 2;
        previous4.value = currentItem - 1;
        indexC_.Wrap(remainingVal);
        previous4.Wrap(remainingVal);
        if (IsKeyValid(remainingVal[previous4.value], remainingVal[indexC_.value], remainingVal[currentItem]))
        {
            if (!triangles)
                triangles = new NewShorts086;
            triangles->Append((unsigned short)remainingVal.GetAt(currentItem));
            triangles->Append((unsigned short)remainingVal.GetAt(previous4.value));
            triangles->Append((unsigned short)remainingVal.GetAt(indexC_.value));
            count++;
            currentItem--;
            remainingVal.BSSimpleArray_unsigned_int_1024_Remove(currentItem, 1);
            if (reflex)
            {
                before8.value = currentItem - 1;
                after4.value = currentItem + 1;
                before8.Wrap(remainingVal);
                after4.Wrap(remainingVal);
                foundPos8 = reflex->Find(remainingVal[currentItem]);
                if (foundPos8 != -1)
                {
                    direction5 =
                        GetPointSide((*vertices)[remainingVal[currentItem]], (*vertices)[remainingVal[before8.value]],
                                     (*vertices)[remainingVal[after4.value]]);
                    if (direction5 == 1)
                        reflex->BSSimpleArray_unsigned_short_1024_Remove(foundPos8, 1);
                }
                before8.value = currentItem - 1;
                after4.value = currentItem - 2;
                before8.Wrap(remainingVal);
                after4.Wrap(remainingVal);
                foundPos8 = reflex->Find(remainingVal[before8.value]);
                if (foundPos8 != -1)
                {
                    dir5 =
                        GetPointSide((*vertices)[remainingVal[before8.value]], (*vertices)[remainingVal[after4.value]],
                                     (*vertices)[remainingVal[currentItem]]);
                    if (dir5 == 1)
                        reflex->BSSimpleArray_unsigned_short_1024_Remove(foundPos8, 1);
                }
            }
            old44.value = currentItem - 1;
            old44.Wrap(remainingVal);
            if (remainingVal.GetAt(old44.value) == 0)
            {
                currentItem++;
                point21 = (*vertices)[remainingVal[currentItem % remainingVal.GetSize()]];
            }
        }
        else
        {
            currentItem++;
            point21 = (*vertices)[remainingVal[currentItem % remainingVal.GetSize()]];
        }
    }
    if (triangles && remainingVal.GetSize() == 3)
    {
        triangles->Append((unsigned short)remainingVal.GetAt(2));
        triangles->Append((unsigned short)remainingVal.GetAt(1));
        triangles->Append((unsigned short)remainingVal.GetAt(0));
        count++;
    }
    if (count > 0)
    {
        total3 = BSPolygon2D_CreateTriData();
        mesh = (NiNode*)CreateInstance(total3);
        ReserveNiNodeAllocationStack();
        node = new NiNode(0);
        node->AttachChildInAvailableSlot(static_cast<NiAVObject*>(static_cast<NiNode*>(mesh)), true);
        if (mesh)
        {
            unk0c = 0;
            unk14 = 0;
            unk18 = 0;
            unk1c = 0;
            unk10 = 0;
        }
    }
}

// Keep the point arithmetic bodies visible under this unit's /Ob1 flags.
inline NiPoint3::NiPoint3(float a, float b, float c) : x(a), y(b), z(c)
{}
inline NiPoint3 NiPoint3::operator-(const NiPoint3& other) const
{
    return NiPoint3(x - other.x, y - other.y, z - other.z);
}

struct Owner299
{
    NiTPrimitiveArray<NiPoint3>* points;
    float ProcessAndReturnValue_00c4da80(int first, int second, int third);
};
// @fnv 0x00c4da80
// src: GUESS 0x00c4da80 (confidence: low)
float Owner299::ProcessAndReturnValue_00c4da80(int first, int second, int third)
{

    NiPoint3 delta[2] = {points->GetAt(second) - points->GetAt(first), points->GetAt(third) - points->GetAt(first)};
    return (float)fabs((float)((delta[0].x * delta[1].y - delta[0].y * delta[1].x) / 2.0));
}

struct S00c4db20_Pt
{
    float x, y, z;
};

struct FUN_006917d0_Arr
{
    int unk00, unk04, unk08, unk0c;
    FUN_006917d0_Arr();
    static __forceinline void* operator new(unsigned int size)
    {
        S00c4db20_Pt t;
        return g_memoryManager.Allocate(size);
    }
    unsigned int Append(const unsigned short& p);
};

struct S00c4db20_Child
{
    int unk00;
    S00c4db20_Pt* m_pPoints;
    void AllocateStorage_00c4e760(int idx, int b);
    S00c4db20_Pt& GetPt(int n)
    {
        return m_pPoints[n];
    }
};

struct S00c4db20_Self
{
    S00c4db20_Child* m_pChildObject;
    FUN_006917d0_Arr* m_pArr;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int m_iArrayLength;

    void BSPolygon2D_StoreConcaveVertices();
    void RemovePt(int n)
    {
        S00c4db20_Pt u;
        m_pChildObject->AllocateStorage_00c4e760(n, 1);
    }
    int GetPointSide(S00c4db20_Pt curr, S00c4db20_Pt prev, S00c4db20_Pt next);
};

// @fnv 0x00c4db20
// src: COMMUNITY 0x00c4db20
void S00c4db20_Self::BSPolygon2D_StoreConcaveVertices()
{
    if (m_pArr == 0)
    {
        m_pArr = new FUN_006917d0_Arr();
        bool removed3 = false;
        for (int iA = 0; iA < m_iArrayLength; iA++)
        {
            if (removed3)
            {
                iA--;
            }
            int prevA = (iA == 0) ? (m_iArrayLength - 1) : (iA - 1);
            int next = (iA + 1) % m_iArrayLength;
            int res3 =
                GetPointSide(m_pChildObject->GetPt(iA), m_pChildObject->GetPt(prevA), m_pChildObject->GetPt(next));
            removed3 = false;
            if (res3 == -1)
            {
                m_pArr->Append((unsigned short)iA);
            }
            else if (res3 == 0)
            {
                RemovePt(iA);
                m_iArrayLength--;
                removed3 = true;
            }
        }
    }
}

// Reconstruction of 0x00c4e1e0
typedef unsigned int size_t;
extern "C" void* memmove(void*, const void*, size_t);
void* __cdecl NiMalloc(unsigned int);

struct MMgr
{
    void* __thiscall Allocate(unsigned int);
};
extern "C" char DAT_011f6238;
inline void* NiAlloc(unsigned int n)
{
    return ((MMgr*)&DAT_011f6238)->Allocate(n);
}

struct NP3
{
    float x, y, z;
    NP3()
    {}
    NP3(float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }
    __forceinline static void* operator new[](size_t n)
    {
        return NiAlloc(n);
    }
    static void operator delete[](void*)
    {}
};
struct NP2
{
    float x, y;
    NP2()
    {}
    NP2(float a, float b)
    {
        x = a;
        y = b;
    }
    __forceinline static void* operator new[](size_t n)
    {
        return NiAlloc(n);
    }
    static void operator delete[](void*)
    {}
};
struct NC4
{
    float r, g, b, a;
    NC4() : r(0.0f), g(0.0f), b(0.0f), a(0.0f)
    {}
    NC4(float q, float w, float e, float t)
    {
        r = q;
        g = w;
        b = e;
        a = t;
    }
    __forceinline static void* operator new[](size_t n)
    {
        return NiAlloc(n);
    }
    static void operator delete[](void*)
    {}
};

inline NP3* At3(NP3* p, int i)
{
    return p + i;
}
inline unsigned short* At2(unsigned short* p, int i)
{
    return p + i;
}
inline void CopyMem(void* dest, const void* src, unsigned int size)
{
    memmove(dest, src, size);
}

struct P3Arr
{
    int unk0;
    NP3* p;
};
struct ShArr
{
    int unk0;
    unsigned short* p;
};

struct TESObjectDoorController
{
    char pad[0x58];
    static void* operator new(unsigned int n);
    static void operator delete(void*);
    TESObjectDoorController(unsigned short a1, NP3* a2, NP3* a3, NC4* a4, NP2* a5, int a6, int a7, unsigned short a8,
                            void* a9);
};

struct C4E1E0
{
    P3Arr* m0;
    int m4;
    ShArr* m8;
    NP3* m0c;
    unsigned char* m10;
    NP3* m14;
    NP2* m18;
    NC4* m1c;
    int m20;
    int m24;
    int m28;
    TESObjectDoorController* BSPolygon2D_CreateTriData();
};

// @fnv 0x00c4e1e0
// src: COMMUNITY 0x00c4e1e0
TESObjectDoorController* C4E1E0::BSPolygon2D_CreateTriData()
{
    m0c = new NP3[m24];
    m14 = new NP3[m24];
    m18 = new NP2[m24];
    m1c = new NC4[m24];
    m10 = (unsigned char*)NiMalloc(m28 * 3 * 2);
    CopyMem(m0c, At3(m0->p, 0), m24 * 12);
    CopyMem(m10, At2(m8->p, 0), m28 * 6);
    for (int i = 0; i < m24; i++)
    {
        m14[i] = NP3(0.0f, 0.0f, 1.0f);
    }
    float fDiv = 100.0f;
    for (int j = 0; j < m24; j++)
    {
        m18[j] = NP2(m0c[j].x / fDiv, m0c[j].y / fDiv);
    }
    for (int k = 0; k < m24; k++)
    {
        m1c[k] = NC4(1.0f, 1.0f, 1.0f, 1.0f);
    }
    TESObjectDoorController* pCtrl =
        new TESObjectDoorController((unsigned short)m24, m0c, m14, m1c, m18, 1, 0, (unsigned short)m28, m10);
    return pCtrl;
}

struct Q4E9
{
    virtual void v0();
    virtual int* Allocate(unsigned n);
    virtual void Free(int* p);
    int* m_data;
    unsigned m_iElementCount;
    unsigned m_alloc;
    void FUN_0042fb60(int* dst, int* src, unsigned n);
    inline bool ShouldShrink()
    {
        if (m_alloc > 0x400)
        {
            if (m_iElementCount <= m_alloc - 0x800)
                return true;
        }
        else
        {
            if (m_iElementCount <= m_alloc >> 2)
                return true;
        }
        return false;
    }
    inline unsigned GetShrinkSize()
    {
        return m_alloc > 0x800 ? m_alloc - 0x400 : m_alloc >> 1;
    }
    inline void DestructItemsA(int* p, unsigned n)
    {
        int pad[1];
        unsigned uiIdx;
        int pad2[2];
        for (uiIdx = 0; uiIdx < n; uiIdx++)
        {
        }
    }
    inline void DestructItems(int* p, unsigned n)
    {
        int pad[2];
        unsigned uiIdx;
        int pad2[1];
        for (uiIdx = 0; uiIdx < n; uiIdx++)
        {
        }
    }
    void BSSimpleArray_unsigned_int_1024_Remove(unsigned idx, bool resize);
};
// @fnv 0x00c4e9b0
// src: COMMUNITY 0x00c4e9b0
void Q4E9::BSSimpleArray_unsigned_int_1024_Remove(unsigned idx, bool resize)
{
    if (resize && ShouldShrink())
    {
        unsigned newSize = GetShrinkSize();
        int* newData2 = Allocate(newSize);
        FUN_0042fb60(newData2, m_data, idx);
        DestructItemsA(m_data + idx, 1);
        FUN_0042fb60(newData2 + idx, m_data + idx + 1, m_iElementCount - 1);
        Free(m_data);
        m_data = 0;
        m_data = newData2;
        m_alloc = newSize;
    }
    else
    {
        DestructItems(m_data + idx, 1);
        FUN_0042fb60(m_data + idx, m_data + idx + 1, m_iElementCount - idx - 1);
    }
    m_iElementCount--;
}

struct Q4E
{
    virtual void v0();
    virtual short* Allocate(unsigned n);
    virtual void Free(short* p);
    short* m_data;
    unsigned m_iElementCount;
    unsigned m_alloc;
    void BSSimpleArray_MoveItems_0(short* dst, short* src, unsigned n);
    inline bool ShouldShrink()
    {
        if (m_alloc > 0x400)
        {
            if (m_iElementCount <= m_alloc - 0x800)
                return true;
        }
        else
        {
            if (m_iElementCount <= m_alloc >> 2)
                return true;
        }
        return false;
    }
    inline unsigned GetShrinkSize()
    {
        return m_alloc > 0x800 ? m_alloc - 0x400 : m_alloc >> 1;
    }
    inline void DestructItemsA(short* p, unsigned n)
    {
        int pad[1];
        unsigned uiIdx;
        int pad2[2];
        for (uiIdx = 0; uiIdx < n; uiIdx++)
        {
        }
    }
    inline void DestructItems(short* p, unsigned n)
    {
        int pad[2];
        unsigned uiIdx;
        int pad2[1];
        for (uiIdx = 0; uiIdx < n; uiIdx++)
        {
        }
    }
    void BSSimpleArray_unsigned_short_1024_Remove(unsigned idx, bool resize);
};
// @fnv 0x00c4eb50
// src: COMMUNITY 0x00c4eb50
void Q4E::BSSimpleArray_unsigned_short_1024_Remove(unsigned idx, bool resize)
{
    if (resize && ShouldShrink())
    {
        unsigned newSize = GetShrinkSize();
        short* newData2 = Allocate(newSize);
        BSSimpleArray_MoveItems_0(newData2, m_data, idx);
        DestructItemsA(m_data + idx, 1);
        BSSimpleArray_MoveItems_0(newData2 + idx, m_data + idx + 1, m_iElementCount - 1);
        Free(m_data);
        m_data = 0;
        m_data = newData2;
        m_alloc = newSize;
    }
    else
    {
        DestructItems(m_data + idx, 1);
        BSSimpleArray_MoveItems_0(m_data + idx, m_data + idx + 1, m_iElementCount - idx - 1);
    }
    m_iElementCount--;
}

class QueryTarget
{
  public:
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void Unk_28();
};

class QueryOwner
{
  public:
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
    QueryTarget* m_pkTarget;
    QueryTarget* GetTarget()
    {
        return m_pkTarget;
    }
    void BSCullingProcess_ClearSharedMap();
};

// @fnv 0x00c4f360
// src: COMMUNITY 0x00c4f360
void QueryOwner::BSCullingProcess_ClearSharedMap()
{
    GetTarget()->Unk_28();
}

struct FUN_00c504e0_pool
{
    void MemoryManager_Deallocate(void* p);
};
struct FUN_00c504e0_mgr
{
    void ReleaseItem(void* p);
};
FUN_00c504e0_mgr* __cdecl FUN_00b00a00(void);

struct FUN_00c504e0_task
{
// @fnv 0x00c504e0
    ~FUN_00c504e0_task()
    {}
    static void operator delete(void* p)
    {
        ((FUN_00c504e0_pool*)&DAT_011f6238)->MemoryManager_Deallocate(p);
    }
};

struct ScopeBase_c5
{
    virtual ~ScopeBase_c5();
};

struct FUN_00c504e0 : ScopeBase_c5
{
    virtual ~FUN_00c504e0();
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
    void* m_ac;
    int m_b0;
    FUN_00c504e0_task* m_b4;
};

FUN_00c504e0::~FUN_00c504e0()
{
    void* old = m_ac;
    ((FUN_00c504e0_pool*)&DAT_011f6238)->MemoryManager_Deallocate(old);
    m_ac = 0;
    m_b0 = 0;
    FUN_00b00a00()->ReleaseItem(m_b4);
    delete m_b4;
}

struct C50Type
{
    const char* field_00;
    C50Type* field_04;
};
struct C50Object
{
    virtual void slot_00();
    virtual void slot_04();
    virtual C50Type* slot_08();
    virtual C50Object* slot_0c();
    virtual void slot_10();
    virtual void slot_14();
    virtual void slot_18();
    virtual void slot_1c();
    virtual void slot_20();
    virtual void slot_24();
    virtual void slot_28();
    virtual void slot_2c();
    virtual C50Object* slot_30();
    inline bool GetParentWorldSpace()
    {
        return field_c4;
    }
    inline const char* GetName()
    {
        return field_08;
    }
    inline C50Object* GetModifiers()
    {
        C50Object* head = field_0c;
        return head;
    }
    inline C50Object* GetNext()
    {
        C50Object* next = field_30;
        return next;
    }
    inline void* GetRoot()
    {
        return field_5c;
    }
    unsigned field_04;
    const char* field_08;
    C50Object* field_0c;
    unsigned field_10;
    unsigned field_14;
    unsigned field_18;
    unsigned field_1c;
    unsigned field_20;
    unsigned field_24;
    unsigned field_28;
    unsigned field_2c;
    C50Object* field_30;
    unsigned field_34;
    unsigned field_38;
    C50Object* field_3c;
    unsigned field_40;
    unsigned field_44;
    unsigned field_48;
    unsigned field_4c;
    unsigned field_50;
    unsigned field_54;
    unsigned field_58;
    void* field_5c;
    unsigned field_60;
    unsigned field_64;
    unsigned field_68;
    unsigned field_6c;
    unsigned field_70;
    unsigned field_74;
    unsigned field_78;
    unsigned field_7c;
    unsigned field_80;
    unsigned field_84;
    unsigned field_88;
    unsigned field_8c;
    unsigned field_90;
    unsigned field_94;
    unsigned field_98;
    unsigned field_9c;
    C50Object** field_a0;
    unsigned short field_a4, field_a6;
    unsigned field_a8;
    unsigned field_ac;
    unsigned field_b0;
    unsigned field_b4;
    unsigned field_b8;
    unsigned field_bc;
    unsigned field_c0;
    bool field_c4;
};
extern C50Type DAT_012027d8;
extern char DAT_010c2678[], DAT_010c2628[], DAT_010c25d8[];
inline bool C50Exact(C50Object* object, const void* type)
{
    if (!object)
        return false;
    return object->slot_08() == type;
}
inline bool C50Kind(C50Object* object)
{
    C50Type* type = object->slot_08();
    while (type)
    {
        if (type == &DAT_012027d8)
            return true;
        type = type->field_04;
    }
    return false;
}
inline bool C50IsKind(C50Object* object)
{
    if (!object)
        return false;
    return C50Kind(object);
}
struct C50ChildLookup
{
    C50Object* value;
    C50Object** entry;
};
inline C50Object* C50ChildAt(C50Object* node, unsigned int index)
{
    C50ChildLookup lookup;
    lookup.entry = &node->field_a0[index];
    lookup.value = *lookup.entry;
    return lookup.value;
}
// @fnv 0x00c50f90
// src: XBOX_PDB 0x00c50f90
bool __cdecl BSParticleSystemManager_CheckEmitterRecurse(C50Object* object, void* material)
{
    if (!object)
        return false;
    if (object->slot_30())
    {
        if (C50Exact(object, &DAT_012024e0))
        {
            C50Object* system = object;
            if (!system->GetParentWorldSpace())
            {
                FNV_Warning(DAT_010c2678, object->GetName());
                return false;
            }
            C50Object* modifier = system->GetModifiers();
            while (modifier)
            {
                if (C50Exact(modifier, &DAT_01203340))
                {
                    C50Object* emitter = modifier;
                    C50Object* target7 = emitter->field_3c;
                    if (material)
                    {
                        if (emitter->GetRoot() != material)
                        {
                            FNV_Warning(DAT_010c2628, object->GetName());
                            return false;
                        }
                    }
                    if (C50IsKind(target7))
                        return true;
                    return false;
                }
                else
                {
                    modifier = modifier->GetNext();
                }
            }
        }
        FNV_Warning(DAT_010c25d8, object->GetName());
        return false;
    }
    else
    {
        C50Object* node = object ? object->slot_0c() : 0;
        if (node)
        {
            unsigned int count = node->field_a6;
            for (unsigned int index = 0; index < count; ++index)
            {
                C50Object* child = C50ChildAt(node, index);
                if (child && !BSParticleSystemManager_CheckEmitterRecurse(child, material))
                    return false;
            }
        }
    }
    return true;
}

inline void NiMatrix3::SetRow(unsigned int row, float a, float b, float c)
{
    reinterpret_cast<float (*)[3]>(&m_pEntry[0][0])[row][0] = a;
    reinterpret_cast<float (*)[3]>(&m_pEntry[0][0])[row][1] = b;
    reinterpret_cast<float (*)[3]>(&m_pEntry[0][0])[row][2] = c;
}
namespace fnv_00c517b0 {
struct NiVisibleArray;

extern float DAT_01202800;

int _sprintf_s(char* buffer, unsigned int size, const char* format, ...);

inline unsigned int NiAtomicIncrement(unsigned int& uiValue)
{
    return InterlockedIncrement((long*)&uiValue);
}
static __forceinline void fnvDead4()
{
    int aiDead[4];
}





}  // namespace fnv_00c517b0
namespace fnv_00c517b0 {
// The shared rectangle has no four-value constructor; initialize its fields here.
template <class T> inline void InitializeViewPort(NiRect<T>& port, T left, T right, T top, T bottom)
{
    port.m_fMinimumU = left;
    port.m_fMaximumU = right;
    port.m_fMinimumV = top;
    port.m_fMaximumV = bottom;
}




inline float& SettingFloat(Setting* setting)
{
    return setting ? setting->uValue.f : (DAT_01202800 = 0.0f, DAT_01202800);
}
extern Setting g_01203144;
extern Setting g_01203150;






}  // namespace fnv_00c517b0
inline void NiAVObject::IncRefCount()
{
    fnv_00c517b0::NiAtomicIncrement(m_uiRefCount);
}
inline void NiAVObject::SetLocalRotation(const NiMatrix3& rotation)
{
    m_kLocal.m_Rotate = rotation;
}
inline void NiAVObject::SetBit(bool value, unsigned int mask)
{
    if (value)
        m_uFlags |= mask;
    else
        m_uFlags &= ~mask;
}
namespace fnv_00c517b0 {
class FUN_00a712f0 : public NiAVObject
{
  public:
    FUN_00a712f0();
    void SetMinNearPlaneDist(float fDist)
    {
        m_fMinNearPlaneDist = fDist;
    }
    void SetMaxFarNearRatio(float fRatio)
    {
        m_fMaxFarNearRatio = fRatio;
    }
    void SetViewPort(const NiRect<float>& kPort)
    {
        m_kPort = kPort;
    }
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
    float m_fMinNearPlaneDist;
    float m_fMaxFarNearRatio;
    NiRect<float> m_kPort;
    float m_fTrailingValue;
};



class FUN_004a0eb0
{
  public:
    FUN_004a0eb0(NiVisibleArray* pkArray);
    static void* operator new(unsigned int uiSize)
    {
        return g_memoryManager.Allocate(uiSize);
    }
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
};

class CamPointer
{
  public:
    CamPointer(FUN_00a712f0* object = 0)
    {
        m_pObject = object;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    ~CamPointer();
    CamPointer& operator=(FUN_00a712f0* object);
    FUN_00a712f0* operator->() const
    {
        return m_pObject;
    }
    FUN_00a712f0* m_pObject;
};

class FUN_00c517b0 : public NiNode
{
  public:
    FUN_00c517b0(const char* pcName, bool bFlag, FUN_00a712f0* pkCamera);
    virtual ~FUN_00c517b0();
    void NiAVObject_SetAlwaysDraw(bool value);
    float BSSceneGraph_GetFarDistance();
    void SceneGraph_SetCameraFOV(float value, int a, int b, int c);
    void BSSceneGraph_SetCameraScene();
    CamPointer m_spCamera;
    int unkB0;
    FUN_004a0eb0* m_pkVisible;
    bool m_bFlag;
};

__forceinline void InitializeCameraName(NiFixedString& value, const char* text)
{
    // VC9's explicit call avoids placement new's allocation-null check.
#if defined(_MSC_VER) && _MSC_VER <= 1500
    value.NiFixedString::NiFixedString(text);
#else
    ::new (&value) NiFixedString(text);
#endif
}
// Keep this caller's out-of-line table release while constructing a shared string.
#pragma inline_depth(1)
__forceinline void ReleaseCameraName(NiFixedString& value)
{
    NiGlobalStringTable::DecRefCount(value.m_kHandle);
}
#pragma inline_depth()
template <class T, void (*Initialize)(T&, const char*), void (*Cleanup)(T&)> class ScopedValue
{
    union
    {
        unsigned int storage[(sizeof(T) + sizeof(unsigned int) - 1) / sizeof(unsigned int)];
        T* alignment;
    };
public:
    __forceinline ScopedValue(const char* text)
    {
        Initialize(*reinterpret_cast<T*>(storage), text);
    }
    __forceinline ~ScopedValue()
    {
        Cleanup(*reinterpret_cast<T*>(storage));
    }
};

// @fnv 0x00c517b0
FUN_00c517b0::FUN_00c517b0(const char* pcName, bool bFlag, FUN_00a712f0* pkCamera) : NiNode(0)
{
    m_bFlag = bFlag;
    m_pkVisible = new FUN_004a0eb0(0);
    unkB0 = 0;

    char acName[512];
    _sprintf_s(acName, 512, "%sRoot Node", pcName);
    SetName(NiFixedString((const char*)acName));
    fnvDead4();

    NiNode* pkCameraNode = new NiNode(0);
    _sprintf_s(acName, 512, "%sRoot CameraNode", pcName);
    pkCameraNode->SetName((const NiFixedString&)ScopedValue<NiFixedString, InitializeCameraName, ReleaseCameraName>((const char*)acName));
    AttachChildInAvailableSlot(pkCameraNode, true);

    if (pkCamera)
    {
        m_spCamera = pkCamera;
    }
    else
    {
        m_spCamera = new FUN_00a712f0;
        _sprintf_s(acName, 512, "%sRoot Camera", pcName);
        m_spCamera->SetName((const NiFixedString&)ScopedValue<NiFixedString, InitializeCameraName, ReleaseCameraName>((const char*)acName));
        NiRect<float> kPort;
        InitializeViewPort(kPort, 0.0f, 1.0f, 1.0f, 0.0f);
        m_spCamera->SetViewPort(kPort);
        NiMatrix3 kRot2;
        kRot2.SetRow(0, 0.0f, 0.0f, 1.0f);
        kRot2.SetRow(1, 1.0f, 0.0f, 0.0f);
        kRot2.SetRow(2, 0.0f, 1.0f, 0.0f);
        m_spCamera->SetLocalRotation(kRot2);
        m_spCamera->SetMinNearPlaneDist(1.0f);
        m_spCamera->SetMaxFarNearRatio(BSSceneGraph_GetFarDistance() / SettingFloat(&g_01203144));
        SceneGraph_SetCameraFOV(SettingFloat(&g_01203150), 1, 0, 0);
        fnvDead4();
    }
    BSSceneGraph_SetCameraScene();
    NiAVObject_SetAlwaysDraw(true);
    SetBit(true, 0x2000);
}
}  // namespace fnv_00c517b0

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
struct BaseForC51df0
{
    virtual ~BaseForC51df0();
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
};
inline long NiAtomicIncrementC51(long& lValue)
{
    return InterlockedIncrement(&lValue);
}
inline long NiAtomicDecrementC51(long& lValue)
{
    return InterlockedDecrement(&lValue);
}
inline void NiRefObject::IncrementReferenceCount()
{
    NiAtomicIncrementC51(reinterpret_cast<long&>(m_uiRefCount));
}
inline void NiRefObject::DecrementReferenceCount()
{
    if (NiAtomicDecrementC51(reinterpret_cast<long&>(m_uiRefCount)) == 0)
        DeleteThis();
}

struct OwnedA
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual ~OwnedA();
};
extern MemoryManager g_011f6238;
struct OwnedB
{
    void* data;
    ~OwnedB()
    {
        NiFree(data);
    }
    static void operator delete(void* p)
    {
        g_011f6238.Deallocate(p);
    }
};
struct FUN_00c51df0 : BaseForC51df0
{
    NiPointer<NiRefObject> m_spNode;
    OwnedB* m_pUserData;
    OwnedA* m_pkOwned;
    virtual ~FUN_00c51df0();
};
// @fnv 0x00c51df0
FUN_00c51df0::~FUN_00c51df0()
{
    m_spNode = 0;
    delete m_pkOwned;
    delete m_pUserData;
}

namespace fn_00c51f20 {

struct ParamBlock
{
    float fValue;
    unsigned char ucFlag0;
    unsigned char ucFlag1;
    unsigned char ucFlag2;
    unsigned char ucFlag3;
    unsigned char ucFlag4;
};

struct Target
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    void* pKey;
    void NiAVObject_Update(ParamBlock* block);
};

struct Child
{
    virtual void vfn_000();
    virtual void vfn_004();
    virtual void vfn_008();
    virtual void vfn_00C();
    virtual void vfn_010();
    virtual void vfn_014();
    virtual void vfn_018();
    virtual void vfn_01C();
    virtual void vfn_020();
    virtual void vfn_024();
    virtual void vfn_028();
    virtual void vfn_02C();
    virtual void vfn_030();
    virtual void vfn_034();
    virtual void vfn_038();
    virtual void vfn_03C();
    virtual void vfn_040();
    virtual void vfn_044();
    virtual void vfn_048();
    virtual void vfn_04C();
    virtual void vfn_050();
    virtual void vfn_054();
    virtual void vfn_058();
    virtual void vfn_05C();
    virtual void vfn_060();
    virtual void vfn_064();
    virtual void vfn_068();
    virtual void vfn_06C();
    virtual void vfn_070();
    virtual void vfn_074();
    virtual void vfn_078();
    virtual void vfn_07C();
    virtual void vfn_080();
    virtual void vfn_084();
    virtual void vfn_088();
    virtual void vfn_08C();
    virtual void vfn_090();
    virtual void vfn_094();
    virtual void vfn_098();
    virtual void vfn_09C();
    virtual void vfn_0A0();
    virtual void vfn_0A4();
    virtual void vfn_0A8();
    virtual void vfn_0AC();
    virtual void vfn_0B0();
    virtual void vfn_0B4();
    virtual void vfn_0B8();
    virtual void vfn_0BC();
    virtual void vfn_0C0();
    virtual void vfn_0C4();
    virtual void vfn_0C8();
    virtual void vfn_0CC();
    virtual void vfn_0D0();
    virtual void vfn_0D4();
    virtual void vfn_0D8();
    virtual void vfn_0DC(Target* target, int flag);
};

struct Owner
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
    void* pChildrenVtbl;
    Child** m_ppObjects;
    unsigned short m_usMaxChildren;
    unsigned short m_usChildren;
    unsigned int unkA8;
    Target* pTarget;
    Child*& GetChildRef(unsigned int i)
    {
        return m_ppObjects[i];
    }
    Target* GetTarget()
    {
        return pTarget;
    }
    Child* GetFirstChild()
    {
        return GetChild(0);
    }
    void* GetKey()
    {
        return GetTarget()->pKey;
    }
    Child* GetChild(unsigned int i)
    {
        if (i >= m_usChildren)
        {
            return 0;
        }
        else
        {
            Child*& ref = GetChildRef(i);
            Child* pkChild = ref;
            return pkChild;
        }
    }
    void BSSceneGraph_SetCameraScene();
};

// @fnv 0x00c51f20
// src: COMMUNITY 0x00c51f20
void Owner::BSSceneGraph_SetCameraScene()
{
    if (GetKey() != GetChild(0))
    {
        GetFirstChild()->vfn_0DC(GetTarget(), 1);
        ParamBlock block;
        block.fValue = 0.0f;
        block.ucFlag0 = 0;
        block.ucFlag1 = 0;
        block.ucFlag2 = 0;
        block.ucFlag3 = 0;
        block.ucFlag4 = 0;
        GetTarget()->NiAVObject_Update(&block);
    }
}

}

namespace fnv_00c52450 {
extern float DAT_01083c64;
extern float DAT_0120312c;
extern float DAT_01203130;
extern float DAT_01202800;
extern float DAT_01203138;
extern float DAT_0120313c;
extern float DAT_01203120;
extern float DAT_01203124;

// Inlined under /Ob1. Argument order keeps (max-min) on the x87 stack under the
// normalized percent, so the addend is the right operand and becomes faddp.
inline float MapNoLODFar(float value, float inMin, float inMax, float outMin, float outMax)
{
    return ((value - inMin) / (inMax - inMin)) * (outMax - outMin) + outMin;
}

class FUN_00c52450_cls
{
  public:
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
    unsigned int unkB4;
    unsigned char unkB8;
    float BSSceneGraph_GetFarDistance();
};

// @fnv 0x00c52450
// src: XBOX_PDB 0x00c52450
float FUN_00c52450_cls::BSSceneGraph_GetFarDistance()
{
    float result5;
    float a;
    float b;
    float* pA3;
    float* pB6;
    float* pC;
    if (unkB8 != 0)
    {
        result5 = DAT_01083c64;
    }
    else
    {
        pA3 = (&DAT_0120312c != 0) ? &DAT_01203130 : (DAT_01202800 = 0.0f, &DAT_01202800);
        a = *pA3;
        pB6 = (&DAT_01203138 != 0) ? &DAT_0120313c : (DAT_01202800 = 0.0f, &DAT_01202800);
        pC = (&DAT_01203120 != 0) ? &DAT_01203124 : (DAT_01202800 = 0.0f, &DAT_01202800);
        b = *pC;
        result5 = MapNoLODFar(*pB6, 0.0f, 1.0f, b, a);
    }
    return result5;
}
}  // namespace fnv_00c52450

namespace fnv_00c52590 {
extern SETTING_VALUE DAT_01202800;
// Preserve this unit's null-safe inline accessors on the shared Setting layout.
inline const bool& GetBool(const Setting* setting)
{
    const bool* selected = setting ? &setting->uValue.b : (DAT_01202800.b = false, &DAT_01202800.b);
    return *selected;
}
inline const int& GetInt(const Setting* setting)
{
    const int* selected = setting ? &setting->uValue.i : (DAT_01202800.i = 0, &DAT_01202800.i);
    return *selected;
}
extern Setting g_01203188;
extern Setting g_01203194;
extern Setting g_012031a0;
extern Setting g_012031ac;
struct Frustum189
{
    float left, right, top, bottom, nearPlane, farPlane;
    bool orthographic;
};
struct Camera189
{
    unsigned unk000;
    unsigned unk004;
    unsigned unk008;
    unsigned unk00c;
    unsigned unk010;
    unsigned unk014;
    unsigned unk018;
    unsigned unk01c;
    unsigned unk020;
    unsigned unk024;
    unsigned unk028;
    unsigned unk02c;
    unsigned unk030;
    unsigned unk034;
    unsigned unk038;
    unsigned unk03c;
    unsigned unk040;
    unsigned unk044;
    unsigned unk048;
    unsigned unk04c;
    unsigned unk050;
    unsigned unk054;
    unsigned unk058;
    unsigned unk05c;
    unsigned unk060;
    unsigned unk064;
    unsigned unk068;
    unsigned unk06c;
    unsigned unk070;
    unsigned unk074;
    unsigned unk078;
    unsigned unk07c;
    unsigned unk080;
    unsigned unk084;
    unsigned unk088;
    unsigned unk08c;
    unsigned unk090;
    unsigned unk094;
    unsigned unk098;
    unsigned unk09c;
    unsigned unk0a0;
    unsigned unk0a4;
    unsigned unk0a8;
    unsigned unk0ac;
    unsigned unk0b0;
    unsigned unk0b4;
    unsigned unk0b8;
    unsigned unk0bc;
    unsigned unk0c0;
    unsigned unk0c4;
    unsigned unk0c8;
    unsigned unk0cc;
    unsigned unk0d0;
    unsigned unk0d4;
    unsigned unk0d8;
    Frustum189 frustum;
    void FUN_00a6faf0(const Frustum189*);
};
struct DistanceController189
{
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
    virtual void slot0a();
    virtual void slot0b();
    virtual void slot0c();
    virtual void slot0d();
    virtual void slot0e();
    virtual void slot0f();
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
    virtual void slot1a();
    virtual void slot1b();
    virtual void slot1c();
    virtual void slot1d();
    virtual void slot1e();
    virtual void slot1f();
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
    virtual void slot2a();
    virtual void slot2b();
    virtual void slot2c();
    virtual void slot2d();
    virtual void slot2e();
    virtual void slot2f();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot3a();
    virtual void slot3b();
    virtual void slot3c();
    virtual void slot3d();
    virtual void slot3e();
    virtual void slot3f();
    virtual float GetFarPlane();
    unsigned unk004;
    unsigned unk008;
    unsigned unk00c;
    unsigned unk010;
    unsigned unk014;
    unsigned unk018;
    unsigned unk01c;
    unsigned unk020;
    unsigned unk024;
    unsigned unk028;
    unsigned unk02c;
    unsigned unk030;
    unsigned unk034;
    unsigned unk038;
    unsigned unk03c;
    unsigned unk040;
    unsigned unk044;
    unsigned unk048;
    unsigned unk04c;
    unsigned unk050;
    unsigned unk054;
    unsigned unk058;
    unsigned unk05c;
    unsigned unk060;
    unsigned unk064;
    unsigned unk068;
    unsigned unk06c;
    unsigned unk070;
    unsigned unk074;
    unsigned unk078;
    unsigned unk07c;
    unsigned unk080;
    unsigned unk084;
    unsigned unk088;
    unsigned unk08c;
    unsigned unk090;
    unsigned unk094;
    unsigned unk098;
    unsigned unk09c;
    unsigned unk0a0;
    unsigned unk0a4;
    unsigned unk0a8;
    Camera189* camera;
    inline Camera189* GetCamera() const
    {
        Camera189* result = camera;
        return result;
    }
    void BSSceneGraph_SetViewDistanceBasedOnFrameRate(float deltaTime);
};
// @fnv 0x00c52590
// src: XBOX_PDB 0x00c52590
void DistanceController189::BSSceneGraph_SetViewDistanceBasedOnFrameRate(float deltaTime)
{
    if (GetBool(&g_01203188))
    {
        static float previous = GetFarPlane();
        float blend_ = deltaTime;
        if (1.0 / GetInt(&g_01203194) < blend_ || 1.0 / GetInt(&g_012031a0) > blend_)
        {
            float current4 = GetFarPlane();
            float minimum2 = (float)GetInt(&g_012031ac);
            float target7 = minimum2;
            blend_ = (1.0 / deltaTime - GetInt(&g_01203194)) * 1.0 / GetInt(&g_012031a0);
            if (blend_ > 1.0)
                target7 = current4;
            else if (blend_ > 0.0)
                target7 += (current4 - minimum2) * blend_;
            float difference = target7 - previous;
            if (fabs(difference) > 10.0)
            {
                Camera189* viewCamera = GetCamera();
                Frustum189 view = viewCamera->frustum;
                previous += difference * deltaTime;
                view.farPlane = previous;
                viewCamera->FUN_00a6faf0(&view);
            }
        }
    }
}
}  // namespace fnv_00c52590

struct Q52Ent
{
    char pad[0x30];
    unsigned m_flags;
    inline void SetFlag(unsigned m, bool b)
    {
        if (b)
            m_flags |= m;
        else
            m_flags &= ~m;
    }
};
struct Q52Arr
{
    Q52Ent** m_data;
    unsigned pad4;
    unsigned m_uiItemCount;
    inline unsigned Count()
    {
        return m_uiItemCount;
    }
};
struct Q52Obj
{
    char pad[0x34];
    unsigned m_cur;
    unsigned m_num;
    char pad3c[4];
    Q52Arr** m_arrs;
    char pad44[2];
    unsigned short m_arrCount;
    bool NiBSBoneLODController_SetBoneLOD(unsigned idx);
};
// @fnv 0x00c52960
// src: XBOX_PDB 0x00c52960
bool Q52Obj::NiBSBoneLODController_SetBoneLOD(unsigned idx)
{
    if (m_num > 0 && m_cur != idx)
    {
        if (idx == -1 || ((int)idx > -1 && idx < m_num))
        {
            unsigned i;
            bool sel = false;
            unsigned j;
            for (i = 0; i < m_arrCount; i++)
            {
                Q52Arr* arr = m_arrs[i];
                if (arr)
                {
                    if (i == idx)
                        sel = true;
                    for (j = 0; j < arr->Count(); j++)
                    {
                        if (arr->m_data[j])
                        {
                            arr->m_data[j]->SetFlag(2, sel);
                        }
                    }
                }
            }
            m_cur = idx;
            return true;
        }
    }
    return false;
}

void* __cdecl _NiMalloc_00aa1070(unsigned int);
void __cdecl _NiFree_00aa10f0(void*);
void* __cdecl Object_DispatchCommandFour(unsigned int);
struct Q5Item;
struct Q5Hold
{
    Q5Item** m_data;
    unsigned m_alloc;
    unsigned m_uiItemCount;
    inline Q5Hold(unsigned n = 0)
    {
        if (n > 0)
            m_data = (Q5Item**)_NiMalloc_00aa1070(n * 4);
        else
            m_data = 0;
        m_alloc = 0;
        m_uiItemCount = 0;
    }
    inline ~Q5Hold()
    {
        void* p = m_data;
        _NiFree_00aa10f0(p);
    }
    inline unsigned Count()
    {
        return m_uiItemCount;
    }
};
struct Q5Obj
{
    virtual void v00(), v04(), v08(), v0c(), v10(), v14(), v18(), v1c(), v20(), v24(), v28(), v2c(), v30(), v34(),
        v38(), v3c(), v40(), v44(), v48(), v4c(), v50(), v54(), v58(), v5c(), v60(), v64(), v68(), v6c(), v70(), v74(),
        v78(), v7c(), v80(), v84(), v88(), v8c(), v90(), v94();
    virtual void v98(Q5Item*);
    char pad[0x48];
    static __forceinline void* operator new(unsigned int amount)
    {
        int dq[2];
        return Object_DispatchCommandFour(amount);
    }
    Q5Obj();
    bool InitializeData_00c52d80(Q5Item* it);
    bool NiBSBoneLODController_SetBoneLOD(unsigned idx);
};
struct Q5Item
{
    void NiObjectNET_RemoveController(Q5Obj* o);
};
void __cdecl NiBSBoneLODController_FindBoneRootNodes(void* p, Q5Hold* h);
// @fnv 0x00c52a80
// src: COMMUNITY 0x00c52a80
bool __cdecl NiBSBoneLODController_ProcessScene(void* param)
{
    Q5Hold items9;
    NiBSBoneLODController_FindBoneRootNodes(param, &items9);
    if (items9.Count() == 0)
        return false;
    for (unsigned i6 = 0; i6 < items9.Count(); i6++)
    {
        Q5Item* it2 = items9.m_data[i6];
        Q5Obj* obj = new Q5Obj;
        obj->v98(it2);
        bool ok = obj->InitializeData_00c52d80(it2);
        if (ok)
            obj->NiBSBoneLODController_SetBoneLOD(0);
        if (!ok)
        {
            it2->NiObjectNET_RemoveController(obj);
            return false;
        }
    }
    return true;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern int DAT_011f4400;

// RTTI at 0x0101fbd4 identifies the scene-object smart-pointer array.
template <> __forceinline NiTObjectArray<NiPointer<NiAVObject> >::NiTObjectArray(unsigned int uiMaxSize, unsigned int uiGrowBy)
    : NiTArray<NiPointer<NiAVObject>, NiTNewInterface<NiPointer<NiAVObject> > >(uiMaxSize, uiGrowBy)
{
}

namespace reconstruct_c5a9d0 {
struct Base
{
    virtual ~Base();
    int field_04;
    __forceinline Base()
    {
        field_04 = 0;
        InterlockedIncrement((volatile long*)&DAT_011f4400);
    }
};
struct List
{
    int field_00, field_04, field_08;
    __forceinline List()
    {
        field_08 = 0;
        field_00 = 0;
        field_04 = 0;
    }
    ~List();
};
struct Object
{
    int field_00;
    volatile long field_04;
};
struct Ref
{
    Object* field_00;
    __forceinline Ref()
    {
        field_00 = 0;
        if (field_00)
        {
            Object* object = field_00;
            InterlockedIncrement(&object->field_04);
        }
    }
    ~Ref();
    void Reset(void*);
};
struct Tail
{
    int field_00;
    void BSSimpleArray_NiPointer_ObstacleUndoData_1024_InitialSetup(unsigned int, bool);
    __forceinline Tail()
    {
        field_00 = (int)&DAT_010840e4;
        BSSimpleArray_NiPointer_ObstacleUndoData_1024_InitialSetup(0, false);
    }
    ~Tail();
    static int DAT_010840e4;
};
struct FUN_00c5a9d0 : Base
{
    List field_08, field_14, field_20;
    Ref field_2c;
    List field_30;
    NiTObjectArray<NiPointer<NiAVObject> > field_3c;
    Ref field_4c;
    List field_50, field_5c;
    Tail field_68;
    FUN_00c5a9d0();
    virtual ~FUN_00c5a9d0();
};
__forceinline void Reserve()
{
    struct
    {
        int field_00, field_04, field_08, field_0c;
    } unused;
    (void)&unused;
}
// @fnv 0x00c5a9d0
FUN_00c5a9d0::FUN_00c5a9d0()
{
    Reserve();
    field_2c.Reset(0);
    field_4c.Reset(0);
}
}

__forceinline NiRefObject::~NiRefObject()
{
    InterlockedDecrement((long*)&ms_lObjectCount);
}

namespace fnv_00c5ac00 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" volatile long DAT_011f4400;
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
inline long RefDecrement(volatile long* count)
{
    return InterlockedDecrement(count);
}
inline long RefIncrement(volatile long* count)
{
    return InterlockedIncrement(count);
}
struct PTSmart
{
    NiRefObject* ptr;
    PTSmart(NiRefObject*);
    PTSmart& operator=(const PTSmart&);
    inline PTSmart& FUN_0066b0d0(NiRefObject* value)
    {
        NiRefObject* previous = ptr;
        NiRefObject* replacement = value;
        if (previous != replacement)
        {
            if (previous)
                previous->DecrementReferenceCount();
            ptr = replacement;
            if (ptr)
                ptr->IncrementReferenceCount();
        }
        return *this;
    }
    __forceinline ~PTSmart()
    {
        if (ptr)
        {
            NiRefObject* old = ptr;
            if (!InterlockedDecrement((long*)&old->m_uiRefCount))
                old->DeleteThis();
        }
    }
};
struct PTListItem
{
    PTListItem* next;
    PTListItem* prev;
    NiRefObject* data;
};
struct ListFields
{
    PTListItem* head;
    PTListItem* tail;
    int count;
    __forceinline ~ListFields()
    {}
};
struct FUN_00b71300_class : ListFields
{
    void DeleteItem(PTListItem*);
    inline void FUN_00b71300()
    {
        PTListItem* item = head;
        while (item)
        {
            PTListItem* old = item;
            item = item->next;
            DeleteItem(old);
        }
        count = 0;
        head = 0;
        tail = 0;
    }
    __forceinline ~FUN_00b71300_class()
    {
        FUN_00b71300();
    }
};
struct FUN_004a4650_class : ListFields
{
    void NiTPointerListBase_NiTPointerAllocator_unsigned_int_NiPointer_BSMultiBoundRoom_RemoveAll();
    __forceinline ~FUN_004a4650_class()
    {
        NiTPointerListBase_NiTPointerAllocator_unsigned_int_NiPointer_BSMultiBoundRoom_RemoveAll();
    }
};
struct FUN_004ed900_class : ListFields
{
    void DeleteItem(PTListItem*);
    inline void FUN_004ed900()
    {
        PTListItem* item = head;
        while (item)
        {
            PTListItem* old = item;
            item = item->next;
            DeleteItem(old);
        }
        count = 0;
        head = 0;
        tail = 0;
    }
    __forceinline ~FUN_004ed900_class()
    {
        FUN_004ed900();
    }
};
struct FUN_00e74d40_class : ListFields
{
    void FUN_00e74d40();
    __forceinline ~FUN_00e74d40_class()
    {
        FUN_00e74d40();
    }
};
struct FUN_0087d480_class
{
    int head, tail, count;
    ~FUN_0087d480_class();
};
struct PTElement
{
    NiRefObject* ptr;
    PTElement(NiRefObject* value)
    {
        ptr = value;
        if (ptr)
            ptr->IncrementReferenceCount();
    }
    PTElement& operator=(const PTElement&);
    ~PTElement();
};
}  // namespace fnv_00c5ac00

template <> __forceinline void NiTNewInterface<fnv_00c5ac00::PTElement>::Deallocate(fnv_00c5ac00::PTElement* data)
{
    delete[] data;
}
template <> __forceinline NiTArray<fnv_00c5ac00::PTElement, NiTNewInterface<fnv_00c5ac00::PTElement> >::~NiTArray()
{
    NiTNewInterface<fnv_00c5ac00::PTElement>::Deallocate(m_pBase);
}
template <> inline void NiTArray<fnv_00c5ac00::PTElement, NiTNewInterface<fnv_00c5ac00::PTElement> >::RemoveAll()
{
    for (unsigned short i = 0; i < m_usSize; ++i)
        m_pBase[i] = fnv_00c5ac00::PTElement(0);
    m_usSize = 0;
    m_usESize = 0;
}

namespace fnv_00c5ac00 {
struct FUN_00c5ac00 : NiRefObject
{
    FUN_004ed900_class sub08;
    FUN_00b71300_class sub14;
    FUN_004a4650_class sub20;
    PTSmart ptr2c;
    FUN_004a4650_class sub30;
    NiTObjectArray<PTElement> arr3c;
    PTSmart ptr4c;
    FUN_00e74d40_class sub50, sub5c;
    FUN_0087d480_class sub68;
    virtual ~FUN_00c5ac00();
};
// @fnv 0x00c5ac00
FUN_00c5ac00::~FUN_00c5ac00()
{
    sub14.FUN_00b71300();
    sub20.NiTPointerListBase_NiTPointerAllocator_unsigned_int_NiPointer_BSMultiBoundRoom_RemoveAll();
    sub08.FUN_004ed900();
    arr3c.RemoveAll();
    ptr2c.FUN_0066b0d0(0);
    ptr4c.FUN_0066b0d0(0);
}
}  // namespace fnv_00c5ac00

namespace fnv_00c5aef0 {

template <class T> struct PtrListQ
{
    NiTListItem<T>* m_pkHead;
    NiTListItem<T>* m_pkTail;
    unsigned int m_uiCount;
    void* GetHeadPos() const
    {
        return m_pkHead;
    }
    T& GetNext(void*& pos) const
    {
        T& e = ((NiTListItem<T>*)pos)->m_element;
        pos = ((NiTListItem<T>*)pos)->m_pkNext;
        return e;
    }
    void* FindPos(const T& val, void* pos = 0) const
    {
        if (pos == 0)
            pos = GetHeadPos();
        while (pos)
        {
            void* pkFound = pos;
            if (val == GetNext(pos))
                return pkFound;
        }
        return 0;
    }
    void __thiscall FUN_00a5a310(const T& item);
};
inline void DeadQ4()
{
    int aiQ[4];
}
struct FUN_00c5aef0_cls
{
    char pad[0x20];
    PtrListQ<NiPointer<NiRefObject> > m_kNode;
    void __thiscall BSPortalGraph_AddRoom(NiRefObject* pObj);
};
// @fnv 0x00c5aef0
// src: XBOX_PDB 0x00c5aef0
void __thiscall FUN_00c5aef0_cls::BSPortalGraph_AddRoom(NiRefObject* pObj)
{
    if (pObj)
    {
        if (!m_kNode.FindPos(pObj))
        {
            m_kNode.FUN_00a5a310(pObj), DeadQ4();
        }
    }
}
}  // namespace fnv_00c5aef0

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);

inline long NiAtomicIncrementB06(long& lValue)
{
    return InterlockedIncrement(&lValue);
}
inline long NiAtomicDecrementB06(long& lValue)
{
    return InterlockedDecrement(&lValue);
}

struct RefSetB06
{
    NiPointer<NiRefObject> ProcessAndReturnValue_00c5bda0(const NiPointer<NiRefObject>& spRetainedObject);
    void* m_pUserData;
};

struct OwnerB06
{
    void* m_pVTable;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    RefSetB06 m_kSet;

    void BSPortalGraph_RemoveRoom(NiRefObject* pkObject);
};

// @fnv 0x00c5b060
// src: COMMUNITY 0x00c5b060
void OwnerB06::BSPortalGraph_RemoveRoom(NiRefObject* pkObject)
{
    if (pkObject)
    {
        NiPointer<NiRefObject> spRetainedObject(pkObject);
        m_kSet.ProcessAndReturnValue_00c5bda0(spRetainedObject);
    }
}

struct S_C5B4D0_Node : NiRefObject
{
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
    unsigned int m_uiValue1;

    __forceinline void SetBit(bool bSet, unsigned int uiMask)
    {
        if (bSet)
            m_uiValue1 |= uiMask;
        else
            m_uiValue1 &= ~uiMask;
    }
};

// /Od /Ob1 tries to inline this, keeps its six locals in the caller, then leaves the call.
struct FUN_004dffa0_Class
{
    inline void FUN_004dffa0();
};

inline void FUN_004dffa0_Class::FUN_004dffa0()
{
    int l0, l1, l2, l3, l4, l5;
    l0 = 1;
    l1 = 2;
    l2 = 3;
    l3 = 4;
    l4 = 5;
    l5 = 6;
    l0 = l5 + 0;
    l1 = l0 + 0;
    l2 = l1 + 0;
    l3 = l2 + 0;
    l4 = l3 + 0;
    l5 = l4 + 0;
    l0 = l5 + 1;
    l1 = l0 + 1;
    l2 = l1 + 1;
    l3 = l2 + 1;
    l4 = l3 + 1;
    l5 = l4 + 1;
    l0 = l5 + 2;
    l1 = l0 + 2;
    l2 = l1 + 2;
    l3 = l2 + 2;
    l4 = l3 + 2;
    l5 = l4 + 2;
    l0 = l5 + 3;
    l1 = l0 + 3;
    l2 = l1 + 3;
    l3 = l2 + 3;
    l4 = l3 + 3;
    l5 = l4 + 3;
    l0 = l5 + 4;
    l1 = l0 + 4;
    l2 = l1 + 4;
    l3 = l2 + 4;
    l4 = l3 + 4;
    l5 = l4 + 4;
    l0 = l5 + 5;
    l1 = l0 + 5;
    l2 = l1 + 5;
    l3 = l2 + 5;
    l4 = l3 + 5;
    l5 = l4 + 5;
    l0 = l5 + 6;
    l1 = l0 + 6;
    l2 = l1 + 6;
    l3 = l2 + 6;
    l4 = l3 + 6;
    l5 = l4 + 6;
    l0 = l5 + 7;
    l1 = l0 + 7;
    l2 = l1 + 7;
    l3 = l2 + 7;
    l4 = l3 + 7;
    l5 = l4 + 7;
}

struct TempEffectList
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
    FUN_004dffa0_Class unk3c;
    S_C5B4D0_Node** unk40;
    unsigned short unk44;
    unsigned short unk46;

    void __thiscall UpdateReferenceState_00c5b4d0();
};

// @fnv 0x00c5b4d0
// src: GUESS 0x00c5b4d0 (confidence: low)
void __thiscall TempEffectList::UpdateReferenceState_00c5b4d0()
{
    unsigned int i = 0;
    for (; i < (unsigned int)unk46; ++i)
    {
        S_C5B4D0_Node** element = &unk40[i];
        S_C5B4D0_Node* p = *element;
        if (p)
        {
            S_C5B4D0_Node* p1 = p;
            InterlockedIncrement((long*)&p1->m_uiRefCount);
        }
        if (p)
        {
            S_C5B4D0_Node* p2 = p;
            p2->SetBit(false, 1u);
        }
        if (p)
        {
            S_C5B4D0_Node* p3 = p;
            if (InterlockedDecrement((long*)&p3->m_uiRefCount) == 0)
                p3->DeleteThis();
        }
    }
    unk3c.FUN_004dffa0();
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);

namespace fnv5b5f0 {

struct RefPtr
{
    NiRefObject* m_pObject;
    __forceinline RefPtr(NiRefObject* pkObj)
    {
        m_pObject = pkObj;
        if (m_pObject)
            m_pObject->AcquireReference();
    }
    __forceinline RefPtr(const RefPtr& kOther)
    {
        m_pObject = kOther.m_pObject;
        if (m_pObject)
            m_pObject->AcquireReference();
    }
    __forceinline ~RefPtr()
    {
        if (m_pObject)
            m_pObject->DecRef();
    }
    __forceinline operator NiRefObject*() const
    {
        return m_pObject;
    }
    __forceinline bool operator==(NiRefObject* pkObj) const
    {
        return m_pObject == pkObj;
    }
};


// Held by value at Owner_c5b5f0+0x3c. Replacing this with
// NiTObjectArray<RefPtr>, GetAt and AddFirstEmpty changes 0x00c5b5f0's
// stack allocation from 0x60 to 0x28 (nine byte differences). Keep the
// original inline-body visibility until that codegen can be reproduced.
struct LocalObjectArrayForB5F0
{
    void* m_pVtbl;
    RefPtr* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    __forceinline RefPtr& operator[](unsigned int uiIndex)
    {
        return m_pBase[uiIndex];
    }
    void Grow(unsigned int uiGrowBy);
// src: XBOX_PDB 0x00a5eb20
    unsigned int NiTArray_NiPointer_NiAVObject_NiTNewInterface_NiPointer_NiAVObject_AddFirstEmpty(const RefPtr& kElement)
    {
        int pad0, pad1, pad2, pad3, pad4, pad5, pad6, pad7, pad8, pad9, pad10, pad11, pad12;
        pad0 = m_usSize;
        pad1 = m_usSize;
        pad2 = m_usSize;
        pad3 = m_usSize;
        pad4 = m_usSize;
        pad5 = m_usSize;
        pad6 = m_usSize;
        pad7 = m_usSize;
        pad8 = m_usSize;
        pad9 = m_usSize;
        pad10 = m_usSize;
        pad11 = m_usSize;
        pad12 = m_usSize;
        if (kElement.m_pObject == 0)
            return (unsigned int)(pad0 + pad1 + pad2 + pad3 + pad4 + pad5 + pad6 + pad7 + pad8 + pad9 + pad10 + pad11 +
                                   pad12);
        unsigned int uiIndex = 0;
        while (uiIndex < m_usSize)
        {
            if (m_pBase[uiIndex].m_pObject == 0)
                break;
            uiIndex++;
        }
        if (uiIndex >= m_usSize)
        {
            if (m_usSize >= m_usMaxSize)
                Grow(m_usGrowBy);
            uiIndex = m_usSize;
            m_usSize++;
        }
        m_pBase[uiIndex] = kElement;
        return uiIndex + (pad0 + pad1 + pad2 + pad3 + pad4 + pad5 + pad6 + pad7 + pad8 + pad9 + pad10 + pad11 + pad12);
    }
};

struct Owner_c5b5f0
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
    LocalObjectArrayForB5F0 m_kArray;
    void BSPortalGraph_AttachQAlwaysRenderChild(NiRefObject* pkObj);
};

// @fnv 0x00c5b5f0
// src: COMMUNITY 0x00c5b5f0
void Owner_c5b5f0::BSPortalGraph_AttachQAlwaysRenderChild(NiRefObject* pkObj)
{
    if (pkObj == 0)
        return;
    bool bFound = false;
    for (unsigned int i = 0; i < m_kArray.m_usSize; i++)
    {
        RefPtr spEntry = m_kArray[i];
        if (spEntry && spEntry == pkObj)
            bFound = true;
    }
    if (!bFound)
    {
        RefPtr spNew = pkObj;
        m_kArray.NiTArray_NiPointer_NiAVObject_NiTNewInterface_NiPointer_NiAVObject_AddFirstEmpty(spNew);
    }
}
}




__forceinline NavMeshPtr::NavMeshPtr(NavObject* object)
{
    m_pObject = reinterpret_cast<NavMesh*>(object);
    if (m_pObject)
        reinterpret_cast<NiRefObject*>(m_pObject)->IncRefCount();
}
__forceinline NavMeshPtr::~NavMeshPtr()
{
    if (m_pObject)
        reinterpret_cast<NiRefObject*>(m_pObject)->DecRefCount();
}

struct S2f850
{
    unsigned int BSSimpleArray_NiPointer_NiAVObject_1024_Add(const NavMeshPtr& value);
};

// Body is past the /Ob1 size cutoff, so the call stays out of line and these
// eight locals stay reserved in the caller between the pointer ctor and dtor.
// src: XBOX_PDB 0x006c61b0
inline unsigned int S2f850::BSSimpleArray_NiPointer_NiAVObject_1024_Add(const NavMeshPtr& value)
{
    unsigned int s0, s1, s2, s3, s4, s5, s6, s7;
    s0 = s0 + 0;
    s0 = s0 + 1;
    s0 = s0 + 2;
    s0 = s0 + 3;
    s0 = s0 + 4;
    s0 = s0 + 5;
    s0 = s0 + 6;
    s0 = s0 + 7;
    s0 = s0 + 8;
    s0 = s0 + 9;
    s0 = s0 + 10;
    s0 = s0 + 11;
    s0 = s0 + 12;
    s0 = s0 + 13;
    s0 = s0 + 14;
    s0 = s0 + 15;
    s0 = s0 + 16;
    s0 = s0 + 17;
    s0 = s0 + 18;
    s0 = s0 + 19;
    s0 = s0 + 20;
    s0 = s0 + 21;
    s0 = s0 + 22;
    s0 = s0 + 23;
    s0 = s0 + 24;
    s0 = s0 + 25;
    s0 = s0 + 26;
    s0 = s0 + 27;
    s0 = s0 + 28;
    s0 = s0 + 29;
    s0 = s0 + 30;
    s0 = s0 + 31;
    s0 = s0 + 32;
    s0 = s0 + 33;
    s0 = s0 + 34;
    s0 = s0 + 35;
    s0 = s0 + 36;
    s0 = s0 + 37;
    s0 = s0 + 38;
    s0 = s0 + 39;
    s0 = s0 + 40;
    s0 = s0 + 41;
    s0 = s0 + 42;
    s0 = s0 + 43;
    s0 = s0 + 44;
    s0 = s0 + 45;
    s0 = s0 + 46;
    s0 = s0 + 47;
    s0 = s0 + 48;
    s0 = s0 + 49;
    s0 = s0 + 50;
    s0 = s0 + 51;
    s0 = s0 + 52;
    s0 = s0 + 53;
    s0 = s0 + 54;
    s0 = s0 + 55;
    s0 = s0 + 56;
    s0 = s0 + 57;
    s0 = s0 + 58;
    s0 = s0 + 59;
    s0 = s0 + 60;
    s0 = s0 + 61;
    s0 = s0 + 62;
    s0 = s0 + 63;
    s0 = s0 + 64;
    s0 = s0 + 65;
    s0 = s0 + 66;
    s0 = s0 + 67;
    s0 = s0 + 68;
    s0 = s0 + 69;
    s0 = s0 + 70;
    s0 = s0 + 71;
    s0 = s0 + 72;
    s0 = s0 + 73;
    s0 = s0 + 74;
    s0 = s0 + 75;
    s0 = s0 + 76;
    s0 = s0 + 77;
    s0 = s0 + 78;
    s0 = s0 + 79;
    return s0;
}

struct OwnerC5
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64;
    S2f850 unk68;
    void __thiscall BSPortalGraph_AddUnboundNode(NiRefObject* arg);
};

// @fnv 0x00c5b9a0
// src: COMMUNITY 0x00c5b9a0
void __thiscall OwnerC5::BSPortalGraph_AddUnboundNode(NiRefObject* arg)
{
    if (arg)
    {
        NavMeshPtr local(reinterpret_cast<NavObject*>(arg));
        unk68.BSSimpleArray_NiPointer_NiAVObject_1024_Add(local);
    }
}

// Find's bool compare and the declined RemoveAt inline are /Ob1 (accept_also).
// The size-refused body reserves the 7 dead slots between this and the array temp.
inline bool ElemEq(unsigned int a, unsigned int b)
{
    return a == b;
}

inline unsigned int FindIndex(FUN_00c5bef0_class* self, unsigned int value)
{
    unsigned int i;
    for (i = 0; i < self->m2; ++i)
    {
        if (self->m1 != 0 && ElemEq(reinterpret_cast<unsigned int*>(self->m1)[i], value))
            return i;
    }
    return 0xffffffffu;
}

inline void FUN_00c5bef0_class::RemoveRange(unsigned int a, unsigned int b)
{
    unsigned int u0, u1, u2, u3, u4, u5, u6;
    u0 = a;
    u1 = b;
    u2 = a;
    u3 = b;
    u4 = a;
    u5 = b;
    u6 = a;
    u0 = u1;
    u1 = u2;
    u2 = u3;
    u3 = u4;
    u4 = u5;
    u5 = u6;
    u6 = u0;
    u0 = u1;
    u1 = u2;
    u2 = u3;
    u3 = u4;
    u4 = u5;
    u5 = u6;
    u6 = u0;
    u0 = u1;
    u1 = u2;
    u2 = u3;
    u3 = u4;
    u4 = u5;
    u5 = u6;
    u6 = u0;
    u0 = u1;
    u1 = u2;
    u2 = u3;
    u3 = u4;
    u4 = u5;
    u5 = u6;
    u6 = u0;
    u0 = u1;
    u1 = u2;
    u2 = u3;
    u3 = u4;
    u4 = u5;
    u5 = u6;
    u6 = u0;
    u0 = u1;
    u1 = u2;
    u2 = u3;
    u3 = u4;
    u4 = u5;
    u5 = u6;
    u6 = u0;
    u0 = u1;
    u1 = u2;
    u2 = u3;
    u3 = u4;
    u4 = u5;
    u5 = u6;
    u6 = u0;
    u0 = u1;
    u1 = u2;
    u2 = u3;
    u3 = u4;
    u4 = u5;
    u5 = u6;
    u6 = u0;
    u0 = u1;
    u1 = u2;
    u2 = u3;
    u3 = u4;
    u4 = u5;
    u5 = u6;
    u6 = u0;
    u0 = u1;
    u1 = u2;
    u2 = u3;
    u3 = u4;
    u4 = u5;
    u5 = u6;
    u6 = u0;
    if (u0 == u6)
        RemoveRange(a + 1, b);
}

struct S_00c5ba50_Class
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
    FUN_00c5bef0_class unk68;

    void __thiscall BSPortalGraph_RemoveUnboundNode(unsigned int value);
};

// @fnv 0x00c5ba50
// src: COMMUNITY 0x00c5ba50
void __thiscall S_00c5ba50_Class::BSPortalGraph_RemoveUnboundNode(unsigned int value)
{
    unsigned int result2;
    result2 = FindIndex(&unk68, value);
    if (result2 != 0xffffffffu)
        unk68.RemoveRange(result2, 1);
}

struct RefC5BB
{
    virtual void v_00();
    virtual void v_04();
    volatile long field_04;
    void IncRefCount()
    {
        InterlockedIncrement(&field_04);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement(&field_04))
            v_04();
    }
};
struct PtrC5BB
{
    RefC5BB* field_00;
    PtrC5BB(RefC5BB* p = 0)
    {
        field_00 = p;
        if (field_00)
            field_00->IncRefCount();
    }
    PtrC5BB(const PtrC5BB& p)
    {
        field_00 = p.field_00;
        if (field_00)
            field_00->IncRefCount();
    }
    ~PtrC5BB()
    {
        if (field_00)
            field_00->DecRefCount();
    }
    PtrC5BB& operator=(const PtrC5BB& other)
    {
        if (field_00 != other.field_00)
        {
            if (field_00)
                field_00->DecRefCount();
            field_00 = other.field_00;
            if (field_00)
                field_00->IncRefCount();
        }
        return *this;
    }
    bool operator!=(const PtrC5BB& p) const
    {
        return field_00 != p.field_00;
    }
};

// @fnv 0x00c5bb60
template <> PtrC5BB NiTArray<PtrC5BB, NiTNewInterface<PtrC5BB> >::RemoveAtAndFill(unsigned int index)
{
    if (index >= m_usSize)
        return PtrC5BB();
    --m_usSize;
    PtrC5BB value = m_pBase[index];
    m_pBase[index] = m_pBase[m_usSize];
    m_pBase[m_usSize] = PtrC5BB();
    if (value != PtrC5BB())
        --m_usESize;
    return value;
}

namespace fnv_00c5c290 {
struct SPQ
{
    NiRefObject* m_pObject;
    SPQ(const SPQ& o)
    {
        m_pObject = o.m_pObject;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    ~SPQ()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
    SPQ& __thiscall FUN_0066b0d0(NiRefObject* p);
};
inline void DeadQ5()
{
    int aiQ[5];
}
typedef NiTListItem<SPQ > ItemQ;
struct AllocQ
{
    void __thiscall NiTPointerAllocator_unsigned_int_Deallocate(ItemQ* p);
};
typedef NiTPointerListBase<fnv_00c5c290::AllocQ, fnv_00c5c290::SPQ > FUN_00c5c290_cls;

// @fnv 0x00c5c290
}
template <> fnv_00c5c290::SPQ NiTPointerListBase<fnv_00c5c290::AllocQ, fnv_00c5c290::SPQ >::RemoveTail()
{
    using namespace fnv_00c5c290;
    ItemQ* pkNode = m_pkTail;
    m_pkTail = m_pkTail->m_pkPrev;
    if (m_pkTail)
        m_pkTail->m_pkNext = 0;
    else
        m_pkHead = 0;
    fnv_00c5c290::SPQ element = pkNode->m_element;
    pkNode->m_element.FUN_0066b0d0(0);
    reinterpret_cast<AllocQ*>(&m_kItemCount)->NiTPointerAllocator_unsigned_int_Deallocate(pkNode);
    m_kItemCount.m_uiCount--;
    DeadQ5();
    return element;
}
namespace fnv_00c5c290 {
}  // namespace fnv_00c5c290

double __cdecl FUN_00ec9130(double x, double y);
inline float FMod(float x, float y)
{
    return ((float)FUN_00ec9130((double)x, (double)y));
}
extern float DAT_010c2d4c;
extern double DAT_01012060;

struct SeqNode
{
    int u00, u04, u08, u0c, u10, u14, u18, u1c, u20, u24, u28, u2c, u30, u34, u38, u3c;
    int u40, u44, u48, u4c, u50, u54, u58, u5c, u60, u64, u68, u6c, u70, u74, u78, u7c;
    int u80, u84, u88, u8c, u90, u94, u98, u9c, ua0, ua4, ua8, uac, ub0, ub4, ub8, ubc;
    int uc0, uc4, uc8, ucc, ud0;
    float m_d4;
};
struct SeqInner
{
    int u00, u04, u08, u0c, u10, u14, u18, u1c, u20, u24, u28, u2c, u30, u34, u38, u3c;
    int u40, u44, u48, u4c, u50, u54, u58, u5c, u60, u64, u68, u6c, u70, u74, u78, u7c;
    int u80, u84, u88, u8c, u90, u94, u98, u9c, ua0, ua4, ua8, uac, ub0, ub4;
    unsigned short m_b8;
};
struct SeqIface
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual bool v27(float t, SeqNode* n, float* out);
};

struct SeqBase
{
    int unk00;
    int unk04;
    unsigned short m_flags;
    unsigned short unk0A;
    float m_0c;
    float m_10;
    int unk14;
    float m_18;
    float m_1c;
    float m_20;
    float m_24;
    float m_28;
    SeqNode* m_2c;
    int unk30;
    int unk34;
    int unk38;
    int m_3c;
    int unk40;
    int unk44;
    float m_48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    SeqInner* m_5c;

    inline bool GetBit(unsigned short mask) const
    {
        return (m_flags & mask) != 0;
    }
    inline bool GetActive() const
    {
        return GetBit(8);
    }
    inline bool GetForceUpdate() const
    {
        return GetBit(0x80);
    }

// src: XBOX_PDB 0x00639b60
    inline SeqIface* NiPSysEmitterCtlr_GetBirthRateInterpolator()
    {
        unsigned a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10;
        if (m_flags)
            return NiPSysEmitterCtlr_GetBirthRateInterpolator();
        a0 = a1 = a2 = a3 = a4 = a5 = a6 = a7 = a8 = a9 = a10 = 0;
        return 0;
    }
    void BSPSysMultiTargetEmitterCtlr_EmitParticles(float a, float b, float c, float d, float e, float f);
};

struct NW
{
    unsigned short n;
    char unk;
    bool w;
};

struct FUN_00c5c470_cls : SeqBase
{
    void BSPSysMultiTargetEmitterCtlr_Update(float* pTime);
};

// @fnv 0x00c5c470
// src: XBOX_PDB 0x00c5c470
void FUN_00c5c470_cls::BSPSysMultiTargetEmitterCtlr_Update(float* pTime)
{
    float fx2;
    NW nw;
    SeqIface* obj5;
    float dt6;
    float out4;
    float c3;
    float d8;
    float lim;
    obj5 = 0;
    c3 = 0.0f;
    lim = 0.0f;
    nw.n = m_5c->m_b8;
    if (nw.n == 0)
    {
        m_20 = *pTime;
        return;
    }
    else
    {
        if (m_20 > *pTime)
            m_48 = -DAT_010c2d4c;
        if (m_2c == 0 || m_3c == 0)
        {
            return;
        }
        else
        {
            if (!GetActive() || (m_20 == *pTime && !GetForceUpdate()))
            {
                return;
            }
            else
            {
                if (m_1c == -DAT_010c2d4c)
                    m_1c = *pTime;
                if (m_20 == -DAT_010c2d4c)
                    dt6 = 0.0f;
                else
                    dt6 = *pTime - m_20;
                m_24 = dt6 * m_0c + m_24;
                m_28 = m_24 + m_10;
                m_20 = *pTime;
                lim = m_18;
                if (lim != DAT_01012060)
                {
                    fx2 = m_28;
                    m_28 = FMod(fx2, lim);
                    if (m_28 < DAT_01012060)
                        m_28 = m_28 + lim;
                }
                else
                {
                    m_28 = 0.0f;
                }
                if (m_48 == -DAT_010c2d4c)
                {
                    if (m_28 > DAT_01012060)
                    {
                        m_48 = 0.0f;
                    }
                    else
                    {
                        m_48 = m_28;
                        return;
                        return;
                    }
                }
                obj5 = NiPSysEmitterCtlr_GetBirthRateInterpolator();
                c3 = m_2c->m_d4;
                nw.w = false;
                if (m_28 > m_48)
                {
                    d8 = m_28 - m_48;
                }
                else
                {
                    d8 = m_18 - m_48 + m_28;
                    nw.w = true;
                }
                if (obj5 != 0)
                {
                    if (obj5->v27(0.0f, m_2c, &out4))
                    {
                        BSPSysMultiTargetEmitterCtlr_EmitParticles(c3 + d8, nw.w ? m_18 : m_28, m_48, 0.0f, m_18, out4);
                    }
                }
                m_48 = m_28;
            }
        }
    }
}

inline int MinCount(unsigned short a, int b)
{
    return a < b ? a : b;
}
struct Emitted
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
    unsigned int flags;
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
    float time;
    float GetTime() const
    {
        return time;
    }
};
struct ParticleNode
{
    ParticleNode* next;
    ParticleNode* previous;
    Emitted* value;
};
struct Emitter
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
    ParticleNode* first;
    int unkb0;
    int unkb4;
    unsigned short count;
    unsigned short GetCount() const
    {
        return count;
    }
    int unkbc;
    ParticleNode* next;
    inline Emitted* PopFrontNode()
    {
        ParticleNode** cursor = &next;
        Emitted** value = &(*cursor)->value;
        *cursor = (*cursor)->next;
        Emitted* result = *value;
        if (!next)
        {
            ParticleNode* head = first;
            next = head;
        }
        return result;
    }
};
struct S240
{
    float* data;
    float* GetData() const
    {
        return data;
    }
    unsigned int capacity;
    unsigned int count;
    void PushBack(const float& value);
};
struct ParticleSystem
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
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void Emit(float now, unsigned short count, float* times);
    virtual void va8();
    virtual void SetCurrent(Emitted* particle);
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
    float time;
    Emitted* current;
    void SetTime(float value)
    {
        time = value;
    }
};
extern unsigned short DAT_011afa9c;
struct Controller
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
    ParticleSystem* system;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    S240 times;
    Emitter* emitter;
    unsigned short maxCount;
    void BSPSysMultiTargetEmitterCtlr_EmitParticles(float now, float start, float end, float emitStart, float emitEnd, float rate);
};
// @fnv 0x00c5c790
// src: XBOX_PDB 0x00c5c790
void Controller::BSPSysMultiTargetEmitterCtlr_EmitParticles(float now, float start, float end, float emitStart, float emitEnd, float rate)
{
    float age;
    Emitted* particle5;
    unsigned short idx2;
    float interval;
    ParticleSystem* ps1;
    unsigned short count2;
    unsigned short steps2;
    unsigned short remainingVal;
    float savedTime;
    unsigned short limitA5;
    Emitted* saved;
    unsigned short previousB;
    unsigned short addedB;
    unsigned short total_13;
    float duration20;
    float elapsed_2;

    if (emitter && rate > 0.0 && emitStart < emitEnd && start > emitStart && end < emitEnd)
    {

        if (start <= emitEnd)
            duration20 = start - emitStart;
        else
            duration20 = emitEnd - emitStart;
        elapsed_2 = 0.0f;
        if (end >= emitStart)
            elapsed_2 = end - emitStart;
        if (emitter->GetCount())
        {
            total_13 = (unsigned short)(rate * duration20);
            previousB = (unsigned short)(rate * elapsed_2);
            addedB = total_13 - previousB;
            if (addedB > 0)
            {
                remainingVal = emitter->count;
                limitA5 = maxCount * addedB;
                count2 = MinCount(limitA5, addedB * remainingVal);
                steps2 = count2 / remainingVal;
                if (steps2 > DAT_011afa9c)
                    steps2 = DAT_011afa9c;
                if (!steps2)
                {
                    remainingVal = count2;
                    steps2 = 1;
                }
                interval = 1.0f / rate;
                times.count = 0;
                for (idx2 = 0; idx2 < steps2; idx2++)
                {
                    previousB++;
                    age = duration20 - previousB * interval;
                    times.PushBack(age);
                }
                ps1 = system;
                saved = ps1->current;
                savedTime = ps1->time;
                while (remainingVal > 0)
                {
                    particle5 = emitter->PopFrontNode();
                    if (particle5 && !(bool)(particle5->flags & 1 ? 1 : 0))
                    {
                        ps1->SetCurrent(particle5);
                        ps1->SetTime(particle5->GetTime());
                        ps1->Emit(now, steps2, times.GetData());
                        remainingVal--;
                    }
                }
                ps1->SetCurrent(saved);
                ps1->time = savedTime;
            }
        }
    }
}

inline IDirect3DDevice9* GetD3DDevice(NiDX9Renderer* renderer)
{
    return renderer->pD3DDevice;
}

struct ScissorBase_Stub
{
    void BaseRender_a745c0(NiDX9Renderer* pkRenderer);
};

struct ScissorProperty_Stub : ScissorBase_Stub
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
    RECT m_kScissorRect;

    void BSScissorTriShape_RenderImmediate(NiDX9Renderer* pkRenderer);
};

// @fnv 0x00c5d110
// src: XBOX_PDB 0x00c5d110
void ScissorProperty_Stub::BSScissorTriShape_RenderImmediate(NiDX9Renderer* pkRenderer)
{
    NiDX9Renderer* pkDX9Renderer = pkRenderer;
    unsigned long dwOldValue = 0;
    bool bScissorSetRes = false;

    if (m_kScissorRect.bottom != 0 || m_kScissorRect.top != 0 || m_kScissorRect.left != 0 || m_kScissorRect.right != 0)
    {
        if ((m_kScissorRect.left < 0 && m_kScissorRect.right < 0) ||
            (m_kScissorRect.left > 1 && m_kScissorRect.right > 1) ||
            (m_kScissorRect.top < 0 && m_kScissorRect.bottom < 0) ||
            (m_kScissorRect.top > 1 && m_kScissorRect.bottom > 1))
        {
            GetD3DDevice(pkDX9Renderer)->SetRenderState(D3DRS_SCISSORTESTENABLE, 1);
            GetD3DDevice(pkDX9Renderer)->SetScissorRect(&m_kScissorRect);
            bScissorSetRes = true;
        }
    }

    BaseRender_a745c0(pkRenderer);

    if (bScissorSetRes)
        GetD3DDevice(pkDX9Renderer)->SetRenderState(D3DRS_SCISSORTESTENABLE, dwOldValue);
}

extern "C" char DAT_010c2fb4;
inline void DeadQ1()
{
    int aiQ[1];
}
inline void DeadQ7()
{
    int aiQ[7];
}
struct NodeBaseQ
{
    virtual ~NodeBaseQ();
    char pad[0xa8];
    NodeBaseQ(unsigned int n);
};
struct ListQ
{
    void* m_pkHead;
    void* m_pkTail;
    unsigned int m_uiCount;
    ListQ()
    {
        m_uiCount = 0;
        m_pkHead = 0;
        m_pkTail = 0;
    }
    ~ListQ();
    void __thiscall FUN_00e74d40();
};
// RTTI at 0x010c2fa8 identifies NiTPrimitiveArray<NiParticles*>.
template <> inline NiTPrimitiveArray<NiParticles*>::NiTPrimitiveArray(unsigned int uiMaxSize, unsigned int uiGrowBy)
    : NiTArray<NiParticles*, NiTMallocInterface<NiParticles*> >(uiMaxSize, uiGrowBy)
{
    DeadQ1();
}
struct FUN_00c5da70 : NodeBaseQ
{
    virtual void v0();
    ListQ m_kNode;
    unsigned short m_b8, m_ba, m_bc;
    unsigned int m_c0;
    int m_c4, m_c8;
    NiTPrimitiveArray<NiParticles*> m_aiIndexedValues;
    float m_dc;
    FUN_00c5da70();
};
// @fnv 0x00c5da70
FUN_00c5da70::FUN_00c5da70() : NodeBaseQ(0)
{
    m_c4 = -1;
    m_c8 = -1;
    m_ba = 0x14;
    m_bc = 0;
    m_b8 = 0;
    m_c0 = 0;
    m_kNode.FUN_00e74d40();
    m_dc = 0.0f;
    DeadQ7();
}

namespace fnv_00c5dcd0 {

template <class T> struct PtrListQ
{
    NiTListItem<T>* m_pkHead;
    NiTListItem<T>* m_pkTail;
    unsigned int m_uiCount;
    void* GetHeadPos() const
    {
        return m_pkHead;
    }
    T& GetNext(void*& pos) const
    {
        T& e = ((NiTListItem<T>*)pos)->m_element;
        pos = ((NiTListItem<T>*)pos)->m_pkNext;
        return e;
    }
    void* FindPos(const T& val, void* pos = 0) const
    {
        if (pos == 0)
            pos = GetHeadPos();
        while (pos)
        {
            void* pkFound = pos;
            if (val == GetNext(pos))
                return pkFound;
        }
        return 0;
    }
    void __thiscall FUN_00a5a310(const T& item);
};
inline void DeadQ4()
{
    int aiQ[4];
}
struct FUN_00c5dcd0_cls
{
    char pad[0xac];
    PtrListQ<NiPointer<NiRefObject> > m_kNode;
    void __thiscall BSMasterParticleSystem_AddEmitterObj(NiRefObject* pObj);
};
// @fnv 0x00c5dcd0
// src: COMMUNITY 0x00c5dcd0
void __thiscall FUN_00c5dcd0_cls::BSMasterParticleSystem_AddEmitterObj(NiRefObject* pObj)
{
    void* pos = m_kNode.FindPos(pObj);
    if (!pos)
        m_kNode.FUN_00a5a310(pObj), DeadQ4();
}
}  // namespace fnv_00c5dcd0

struct EB90Sub
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
    virtual unsigned short GetFlags();
};

struct EB90Item
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    int unkA0, unkA4, unkA8, unkAC, unkB0, unkB4;
    EB90Sub* m_pSub;
};

struct EB90Obj
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    int unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC;
    int unkC0, unkC4, unkC8, unkCC;
    EB90Item** m_ppItems;
    unsigned short unkD4;
    unsigned short m_usElementCount;

    bool BSMasterParticleSystem_ChildHasActiveParticles();
};

// /Ob1 inlines this. The comma reads the uninitialized parameter slot, then
// overwrites that return temporary with the real pointer. That is the
// never-written load into the slot below `this`.
__forceinline EB90Sub* eb90_pick(EB90Sub* b)
{
    return (b, b);
}

// @fnv 0x00c5eb90
// src: XBOX_PDB 0x00c5eb90
bool EB90Obj::BSMasterParticleSystem_ChildHasActiveParticles()
{
    unsigned int count = m_usElementCount;
    for (unsigned int i = 0; i < count; i++)
    {
        EB90Item* item3 = m_ppItems[i];
        if (item3)
            if ((int)eb90_pick(item3->m_pSub)->GetFlags() > 0)
                return true;
    }
    return false;
}

struct NiSmallValue
{
    int unk00;
};

extern NiSmallValue DAT_01204374;

struct NiBaseStandIn
{
    virtual void vfn_0000();
    int unk04;
    int unk08;
    ~NiBaseStandIn();
    NiBaseStandIn(NiSmallValue value);
};

struct NiMemberStandIn
{
    int unk00;
    NiMemberStandIn();
    ~NiMemberStandIn();
};

struct FUN_00c5ecf0 : public NiBaseStandIn
{
    virtual void vfn_0000();
    NiMemberStandIn m_0c;
    FUN_00c5ecf0();
};

inline NiSmallValue c5ecf0_base_arg()
{
    int a;
    int b;
    int c;
    return DAT_01204374;
}

// @fnv 0x00c5ecf0
FUN_00c5ecf0::FUN_00c5ecf0() : NiBaseStandIn(c5ecf0_base_arg()), m_0c()
{}

class F010Item
{
  public:
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
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54(void* a);
};
class F010Cls
{
  public:
    int m_00, m_04, m_08, m_0c;
    F010Item** m_10;
    unsigned int m_14;
    bool FUN_00a7b290(void* a);
    unsigned int Count() const
    {
        return m_14;
    }
    F010Item*& Get(unsigned int i) const
    {
        return m_10[i];
    }
    bool BSTextureData_RegisterStreamables(void* a);
};
// @fnv 0x00c5f010
// src: XBOX_PDB 0x00c5f010
bool F010Cls::BSTextureData_RegisterStreamables(void* a)
{
    if (!FUN_00a7b290(a))
        return false;

    for (unsigned int i = 0; i < Count(); ++i)
    {

        Get(i)->v54(a);
    }
    return true;
}

namespace fnv_00c5f190 {
struct C5F190Elem
{
    int unk00;
    int unk04;
    const char* m_pcObjectName;
};

struct C5F190Global
{
    const char* m_pcName;
    int m_unk04;
};

struct C5F190Line
{
    int gap;
    void* pc;
};

struct C5F190Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    C5F190Elem** m_ppItems;
    unsigned int m_uiCount;

    // /Ob1 tries to inline this and refuses on size. The four locals stay
    // reserved in the caller; the call itself stays out of line.
    inline void FUN_00a7b580(NiTPrimitiveArray<unsigned int>* out)
    {
        unsigned int w0, w1, w2, w3;
        w0 = (unsigned int)out;
        w1 = w0 + 1;
        w2 = w1 + 4;
        w3 = w2 + 7;
        w0 = w3 + 10;
        w1 = w0 + 13;
        w2 = w1 + 16;
        w3 = w2 + 19;
        w0 = w3 + 22;
        w1 = w0 + 25;
        w2 = w1 + 28;
        w3 = w2 + 31;
        w0 = w3 + 34;
        w1 = w0 + 37;
        w2 = w1 + 40;
        w3 = w2 + 43;
        w0 = w3 + 46;
        w1 = w0 + 49;
        w2 = w1 + 52;
        w3 = w2 + 55;
        w0 = w3 + 58;
        w1 = w0 + 61;
        w2 = w1 + 64;
        w3 = w2 + 67;
        w0 = w3 + 70;
        w1 = w0 + 73;
        w2 = w1 + 76;
        w3 = w2 + 79;
        w0 = w3 + 82;
        w1 = w0 + 85;
        w2 = w1 + 88;
        w3 = w2 + 91;
        w0 = w3 + 94;
        w1 = w0 + 97;
        w2 = w1 + 100;
        w3 = w2 + 103;
        w0 = w3 + 106;
        w1 = w0 + 109;
        w2 = w1 + 112;
        w3 = w2 + 115;
        w0 = w3 + 118;
        w1 = w0 + 121;
        w2 = w1 + 124;
        w3 = w2 + 127;
        w0 = w3 + 130;
        w1 = w0 + 133;
        w2 = w1 + 136;
        w3 = w2 + 139;
        w0 = w3 + 142;
        w1 = w0 + 145;
        w2 = w1 + 148;
        w3 = w2 + 151;
        w0 = w3 + 154;
        w1 = w0 + 157;
        w2 = w1 + 160;
        w3 = w2 + 163;
        w0 = w3 + 166;
        w1 = w0 + 169;
        w2 = w1 + 172;
        w3 = w2 + 175;
        w0 = w3 + 178;
        w1 = w0 + 181;
        w2 = w1 + 184;
        w3 = w2 + 187;
        w0 = w3 + 190;
        w1 = w0 + 193;
        w2 = w1 + 196;
        w3 = w2 + 199;
        w0 = w3 + 202;
        w1 = w0 + 205;
        w2 = w1 + 208;
        w3 = w2 + 211;
        w0 = w3 + 214;
        w1 = w0 + 217;
        w2 = w1 + 220;
        w3 = w2 + 223;
        w0 = w3 + 226;
        w1 = w0 + 229;
        w2 = w1 + 232;
        w3 = w2 + 235;
        w0 = w3 + 238;
        (void)w0;
        (void)w1;
        (void)w2;
        (void)w3;
    }

    void BSTextureData_GetViewerStrings(NiTPrimitiveArray<unsigned int>* out);
};

extern "C" char* __cdecl NiGetViewerString_00a7d5e0(const char* name, const char* value);

// @fnv 0x00c5f190
// src: XBOX_PDB 0x00c5f190
void C5F190Holder::BSTextureData_GetViewerStrings(NiTPrimitiveArray<unsigned int>* out)
{
    C5F190Line line;
    unsigned int res;
    unsigned int elem;
    unsigned int cur;
    unsigned int it;
    FUN_00a7b580(out);
    line.pc = (void*)((C5F190Global&)g_01204378).m_pcName;
    res = (unsigned int)NiViewerStrings_NiGetViewerString_Title(line.pc);
    out->AddFirstEmpty(res);
    for (it = 0; it < (cur = m_uiCount); it++)
    {
        C5F190Elem** ptr = m_ppItems + it;
        const char** row = &(*ptr)->m_pcObjectName;
        const char* pName = *row;
        elem = (unsigned int)NiGetViewerString_00a7d5e0("ObjectName", pName);
        out->AddFirstEmpty(elem);
    }
}
}  // namespace fnv_00c5f190

namespace fnv_00c5f240 {
extern const char str_010c3194[];
extern NiFixedString* DAT_01204374;

// @fnv 0x00c5f240
// src: COMMUNITY 0x00c5f240
void BSTextureData_InitSDM()
{
    DAT_01204374 = new NiFixedString(str_010c3194);
}
}  // namespace fnv_00c5f240

namespace fnv_00c5f5a0 {
struct SubQ
{
    char pad[0x10];
    void* m_10;
};
struct GeomQ
{
    char pad[0xbc];
    SubQ* m_pkSub;
    SubQ* GetSub()
    {
        return m_pkSub;
    }
};
struct AVQ
{
    virtual void v00(), v01(), v02();
    virtual void* AsNode();
    virtual void v04(), v05();
    virtual GeomQ* AsGeom();
};
struct AVPtrQ
{
    AVQ* m_pObject;
    operator AVQ*() const
    {
        AVQ* p = m_pObject;
        return p;
    }
};

struct NodeQ
{
    char pad[0x9c];
    NiTObjectArray<AVPtrQ> m_kChildList;
};
struct FUN_00c5f5a0_cls
{
    virtual void v00(), v01(), v02(), v03(), v04(), v05(), v06(), v07(), v08(), v09(), v10(), v11(), v12(), v13(),
        v14(), v15(), v16(), v17(), v18(), v19(), v20(), v21(), v22(), v23(), v24(), v25(), v26(), v27(), v28(), v29(),
        v30(), v31(), v32(), v33(), v34(), v35(), v36(), v37(), v38(), v39(), v40(), v41(), v42(), v43(), v44(), v45(),
        v46(), v47(), v48(), v49(), v50(), v51(), v52(), v53(), v54(), v55(), v56(), v57(), v58(), v59(), v60(), v61(),
        v62(), v63();
    virtual void Apply(void* pNode, void* pVal);
    void __thiscall BSNiNode_ReparentSkinInstances(NodeQ* pNode, void* pVal);
};
// @fnv 0x00c5f5a0
// src: XBOX_PDB 0x00c5f5a0
void __thiscall FUN_00c5f5a0_cls::BSNiNode_ReparentSkinInstances(NodeQ* pParent, void* pVal)
{
    if (pParent && pVal)
    {
        for (unsigned int i = 0; i < pParent->m_kChildList.m_usSize; i++)
        {
            AVQ* pChild = pParent->m_kChildList.GetAt(i);
            if (pChild)
            {
                void* pNode = pChild->AsNode();
                if (pNode)
                    Apply(pNode, pVal);
                else
                {
                    GeomQ* pGeom = pChild->AsGeom();
                    if (pGeom && pGeom->GetSub())
                        pGeom->GetSub()->m_10 = pVal;
                }
            }
        }
    }
}
}  // namespace fnv_00c5f5a0

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* p);

extern void* DAT_0109b220;  // empty string handle
extern void* DAT_010c32c4;

void* __cdecl FUN_00a5b690(const char* p);


class S00c5fc70_Object
{
  public:
    void FUN_00c316a0(const NiFixedString& kName, int iFlags);
    S00c5fc70_Object* BSPSysStripUpdateModifier_BSPSysStripUpdateModifier(const char* pSource, float f);
    void* m_vt;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    float m_f18;
};

// @fnv 0x00c5fc70
// src: EXE 0x00c5fc70
S00c5fc70_Object* S00c5fc70_Object::BSPSysStripUpdateModifier_BSPSysStripUpdateModifier(const char* pSource, float f)
{
    FUN_00c316a0(NiFixedString(pSource), 0x9c4);
    m_vt = &DAT_010c32c4;
    m_f18 = f;
    return this;
}

namespace fnv_00c4ecf0 {

extern NiDX9Renderer* DAT_011f4748;

class OcclusionQuery
{
  public:
    IDirect3DQuery9* m_pkQuery;
    OcclusionQuery();
};

// @fnv 0x00c4ecf0
OcclusionQuery::OcclusionQuery()
{
    m_pkQuery = 0;
    NiDX9Renderer* pkRenderer = DAT_011f4748;
    GetD3DDevice(pkRenderer)->CreateQuery(D3DQUERYTYPE_OCCLUSION, &m_pkQuery);
}
}  // namespace fnv_00c4ecf0

unsigned int __cdecl FUN_0040fc90();
void __cdecl BSSleep(unsigned long);
void __cdecl ProgramFlow();
inline void RecursiveSpinLock::Lock(const char*)
{
    unsigned int thread = FUN_0040fc90();
    if (m_uiOwningThreadID == (long)thread)
        ++m_uiRecursionCount;
    else
    {
        unsigned int attempts = 0;
        while (BSAtomicCompareExchange((volatile long*)&m_uiOwningThreadID, 0, thread))
        {
            ++attempts;
            BSSleep(attempts > 10000 ? 1 : 0);
        }
        ProgramFlow();
        m_uiRecursionCount = 1;
    }
}

template <> inline void NiTPointerAllocator<unsigned int>::Deallocate(void* pointer)
{
    g_pointerAllocatorPoolState.Lock(0);
    AllocNode* node = static_cast<AllocNode*>(pointer);
    node->m_pkData = 0;
    node->m_pkNext = ms_pkFreeMem;
    ms_pkFreeMem = node;
    ProgramFlow();
    g_pointerAllocatorPoolState.Unlock();
}



// @fnv 0x00c5c160
template <> NiPointer<NiRefObject> NiTPointerListBase<NiTPointerAllocator<unsigned int>, NiPointer<NiRefObject> >::RemoveHead()
{
    NiTListItem<NiPointer<NiRefObject> >* pkNode = this->m_pkHead;
    this->m_pkHead = this->m_pkHead->m_pkNext;
    if (this->m_pkHead)
        this->m_pkHead->m_pkPrev = 0;
    else
        this->m_pkTail = 0;

    NiPointer<NiRefObject> element = pkNode->m_element;
    pkNode->m_element = 0;
    reinterpret_cast<NiTPointerAllocator<unsigned int>*>(&this->m_kItemCount)->Deallocate(pkNode);
    this->m_kItemCount.m_uiCount--;
    return element;
}

struct Pool41f40_obj : S_0044dd60
{
    int unk00;
    int unk04;
    long m_iRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_iRefCount);
    }
};

struct Pool41f40_ptr
{
    Pool41f40_obj* m_pObject;
    Pool41f40_ptr& operator=(Pool41f40_obj* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
                m_pObject->BSTask_int64_DecRefCount();
            m_pObject = pObject;
            if (m_pObject != 0)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};

struct Pool41f40_node
{
    int unk00;
    int unk04;
    union
    {
        Pool41f40_ptr m_pReferencedObject;
        Pool41f40_node* m_pkNext;
    };
};

struct Pool41f40_owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    unsigned int m_uiMaxFree;
};

struct Pool41f40_cls
{
    Pool41f40_owner* m_pkOwnerManager;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    Pool41f40_node* m_pkFreeList;
    unsigned int m_uiFreeCount;
    Pool41f40_node* GetFreeList()
    {
        Pool41f40_node* p = m_pkFreeList;
        return p;
    }
    unsigned int GetMaxFree()
    {
        unsigned int u = m_pkOwnerManager->m_uiMaxFree;
        return u;
    }
    void LockFreeMap_TESObjectREFR_NiPointer_QueuedReference_LockFreeMapInterface_ScanForDeletedNodes();
    void LockFreeMap_TESObjectREFR_NiPointer_QueuedReference_LockFreeMapInterface_DeleteNode(Pool41f40_node* pkNode);
};

static __forceinline void Dead23()
{
    int aiD[23];
}

// @fnv 0x00c41f40
// src: COMMUNITY 0x00c41f40
void Pool41f40_cls::LockFreeMap_TESObjectREFR_NiPointer_QueuedReference_LockFreeMapInterface_DeleteNode(Pool41f40_node* pkNode)
{
    int iA, iB, iC;
    pkNode->m_pReferencedObject = 0;
    pkNode->m_pkNext = GetFreeList();
    m_pkFreeList = pkNode;
    m_uiFreeCount++;
    if (m_uiFreeCount == GetMaxFree())
        LockFreeMap_TESObjectREFR_NiPointer_QueuedReference_LockFreeMapInterface_ScanForDeletedNodes();
    Dead23();
}

struct FUN_00a7b2e0
{
    int unk04;
    int unk08;
    FUN_00a7b2e0();
    virtual ~FUN_00a7b2e0();
};

struct Mid_c42f70 : FUN_00a7b2e0
{
    int m_0c;
    Mid_c42f70()
    {
        m_0c = 0;
    }
    virtual ~Mid_c42f70()
    {}
};

struct Node_c42f70 : Mid_c42f70
{
    Node_c42f70();
    virtual ~Node_c42f70();
    void BSXFlags_Init();
};

// @fnv 0x00c42f70
Node_c42f70::Node_c42f70()
{
    BSXFlags_Init();
}

class CloneObj
{
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
    virtual CloneObj* MakeClone(unsigned int cloning);
    volatile long m_uiRefCount;
    void DeleteThis();
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};
struct CloneOwner
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
    NiPointer<CloneObj> m_ac;
    unsigned int m_b0;
    void SetB0(unsigned int v)
    {
        m_b0 = v;
    }
    void __thiscall ForwardToBase(CloneOwner* a, unsigned int b);
    void __thiscall BSMultiBoundNode_CopyMembers(CloneOwner* a1, unsigned int a2);
};
// @fnv 0x00c46c30
// src: XBOX_PDB 0x00c46c30
void CloneOwner::BSMultiBoundNode_CopyMembers(CloneOwner* pDest, unsigned int kCloning)
{
    ForwardToBase(pDest, kCloning);
    CloneObj* pNewInstance = m_ac->MakeClone(kCloning);
    pDest->m_ac = pNewInstance;
    pDest->SetB0(m_b0);
}

namespace fnv_00c44980 {
extern unsigned int DAT_011af714[];
extern char DAT_010c1ad4[];
extern int DAT_010c1af0[];
int __cdecl BSsprintf(char*, unsigned int, const char*, ...);
__forceinline void* operator new[](unsigned int size)
{
    return g_memoryManager.Allocate(size);
}
extern "C" __declspec(dllimport) void* __stdcall GetCurrentThread();
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();
extern "C" __declspec(dllimport) void* __stdcall CreateThread(void*, unsigned int, unsigned long(__stdcall*)(void*),
                                                              void*, unsigned long, unsigned long*);
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
extern "C" __declspec(dllimport) unsigned long __stdcall ResumeThread(void*);
unsigned long __stdcall RunThreadProc(void*);
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(void*);

}  // namespace fnv_00c44980
inline BSThread::BSThread() : m_pThreadHandle(0), m_pCurrentThreadHandle(0), m_uiCreatedThreadId(0), m_uiCurrentThreadId(0), m_bThreadStarted(false)
{
    int criticalSectionScratch;  // Stack slot reserved by the original critical-section initializer.
    fnv_00c44980::InitializeCriticalSection(&CriticalSection);
}
inline void BSThread::FUN_00aa6430(int stackSize, const char* name, bool suspended)
{
    using namespace fnv_00c44980;
    if (m_pThreadHandle)
        return;
    m_pCurrentThreadHandle = fnv_00c44980::GetCurrentThread();
    m_uiCurrentThreadId = fnv_00c44980::GetCurrentThreadId();
    m_pThreadHandle = fnv_00c44980::CreateThread(0, stackSize, fnv_00c44980::RunThreadProc, this, suspended ? 4 : 0, reinterpret_cast<unsigned long*>(&m_uiCreatedThreadId));
    EnterCriticalSection(&CriticalSection);
    FUN_00aa6560(-1);
    m_bThreadStarted = true;
    unsigned long previousSuspendCount = fnv_00c44980::ResumeThread(m_pThreadHandle);
    LeaveCriticalSection(&CriticalSection);
}
namespace fnv_00c44980 {

struct FUN_00c44980;
struct WorkerThread : BSLinearTaskThread
{
    FUN_00c44980* manager;
    int unk50, unk54, unk58;
    static __forceinline void* operator new(unsigned int size)
    {
        return g_memoryManager.Allocate(size);
    }
    static void operator delete(void*);
    virtual ~WorkerThread();
    WorkerThread(FUN_00c44980* owner)
    {
        manager = owner;
    }
};
struct FUN_00c44980
{
    WorkerThread** threads;
    int unk04;
    int unk08;
    bool unk0c;
    FUN_00c44980();
};
// @fnv 0x00c44980
FUN_00c44980::FUN_00c44980()
{
    threads = 0;
    unk04 = 0;
    unk08 = 0;
    unk0c = false;
    if (1)
    {
        threads = new WorkerThread*[1];
        for (unsigned int i = 0; i < 1; ++i)
        {
            threads[i] = new WorkerThread(this);
            char name[260];
            BSsprintf(name, 260, DAT_010c1ad4, DAT_011af714[i]);
            threads[i]->FUN_00aa6430(0x8000, name, false);
            threads[i]->FUN_00aa6540(name);
            threads[i]->FUN_00aa6550(DAT_011af714[i]);
            threads[i]->FUN_00aa6560(15);
        }
    }
}
}  // namespace fnv_00c44980

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle,
                                                                             unsigned long dwMilliseconds);

struct SyncC44
{
    volatile long count;
    void* handle;
};

// 8-byte local: only the pointer is stored. The second dword is the unreferenced
// slot at [ebp-0x14]; VC9 /Od places this struct at [ebp-0x18].
struct SyncPtrC44
{
    SyncC44* p;
    int unk04;
};

struct ObjC44
{
    virtual ~ObjC44();
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
    SyncC44 sync;
    void __thiscall FUN_008c74b0();
    __forceinline void WaitDec()
    {
        SyncPtrC44 b;
        b.p = &sync;
        WaitForSingleObject(b.p->handle, 0xFFFFFFFF);
        InterlockedDecrement(&b.p->count);
    }
};

inline void operator delete[](void* p)
{
    _g_memoryManager.Deallocate(p);
}

struct OwnerC44
{
    ObjC44** unk00;
    void ReleaseStorage_00c44b70();
};

// @fnv 0x00c44b70
// src: GUESS 0x00c44b70 (confidence: low)
void OwnerC44::ReleaseStorage_00c44b70()
{
    for (unsigned int i = 0; i < 1; ++i)
    {
        unk00[i]->FUN_008c74b0();
        unk00[i]->WaitDec();
        delete unk00[i];
        unk00[i] = 0;
    }
    delete[] unk00;
}

namespace fnv_00c45b20 {
__forceinline void* operator new[](unsigned int size)
{
    return g_memoryManager.Allocate(size);
}
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct ResizeObject
{
    virtual void first();
    virtual void destroy();
    volatile long refs;
    __forceinline void retain()
    {
        InterlockedIncrement(&refs);
    }
    __forceinline void release()
    {
        if (!InterlockedDecrement(&refs))
            destroy();
    }
};
struct ResizePointer
{
    ResizeObject* object;
    __forceinline ResizePointer(ResizeObject* value = 0)
    {
        object = value;
        if (object)
            object->retain();
    }
    __forceinline ~ResizePointer()
    {
        if (object)
            object->release();
    }
    __forceinline bool operator!=(const ResizePointer& other) const
    {
        return object != other.object;
    }
    ResizePointer& assign(const ResizePointer& other)
    {
        if (object != other.object)
        {
            if (object)
                object->release();
            object = other.object;
            if (object)
                object->retain();
        }
        return *this;
    }
};
inline ResizePointer* __cdecl allocatePointers(unsigned int count)
{
    return new ResizePointer[count];
}
inline void freePointers(ResizePointer* data)
{
    delete[] data;
}

}  // namespace fnv_00c45b20

// @fnv 0x00c45b20
template <> void NiTArray<fnv_00c45b20::ResizePointer, NiTNewInterface<fnv_00c45b20::ResizePointer> >::SetSize(unsigned int newSize)
{
    using namespace fnv_00c45b20;
    if (newSize == m_usMaxSize)
        return;
    unsigned short index3;
    if (newSize < m_usSize)
    {
        for (index3 = (unsigned short)newSize; index3 < m_usSize; index3++)
        {
            if (m_pBase[index3] != ResizePointer())
            {
                m_pBase[index3].assign(ResizePointer());
                m_usESize--;
            }
        }
        m_usSize = (unsigned short)newSize;
    }
    ResizePointer* oldData = m_pBase;
    m_usMaxSize = (unsigned short)newSize;
    if (newSize > 0)
    {
        m_pBase = allocatePointers(m_usMaxSize);
        for (index3 = 0; index3 < m_usSize; index3++)
            m_pBase[index3].assign(oldData[index3]);
        for (index3 = m_usSize; index3 < m_usMaxSize; index3++)
            m_pBase[index3].assign(ResizePointer());
    }
    else
        m_pBase = 0;
    freePointers(oldData);
}

namespace fnv_00c46970 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* value);

extern int DAT_010c1d14;

struct SpawnedBase
{
    SpawnedBase();
    ~SpawnedBase();
};

struct NodeObj
{
    void* vtbl;
    volatile long refs;
    __forceinline void AcquireReference()
    {
        InterlockedIncrement(&refs);
    }
};

struct SpawnedHolder
{
    NodeObj* m_p;
    __forceinline SpawnedHolder()
    {
        m_p = 0;
        if (m_p)
            m_p->AcquireReference();
    }
    ~SpawnedHolder();
    void FUN_0066b0d0(int flag);
};

struct FUN_00c46970 : SpawnedBase
{
    void* m_vtbl;
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
    int m_30;
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
    SpawnedHolder m_ac;
    __forceinline void SetFormFlag(int flag, bool set)
    {
        int maskHome;
        int setHome;
        if (set)
            m_30 |= flag;
        else
            m_30 &= ~flag;
    }
    FUN_00c46970();
};

// @fnv 0x00c46970
FUN_00c46970::FUN_00c46970() : SpawnedBase(), m_vtbl(&DAT_010c1d14)
{
    m_ac.FUN_0066b0d0(0);
    SetFormFlag(0x800, true);
}
}  // namespace fnv_00c46970

namespace fnv_00c46a40 {
extern int DAT_010c1d14;
extern "C" void(__stdcall* FUN_00fdf1c0)(void*);
extern "C" long(__stdcall* FUN_00fdf1c4)(void*);

struct FUN_00c5f680
{
    FUN_00c5f680(int a, int b);
    ~FUN_00c5f680();
};
FUN_00c5f680::~FUN_00c5f680()
{}

struct NodeRef
{
    virtual void v0();
    virtual void v1();
    __forceinline void IncRefCount()
    {
        FUN_00fdf1c0((char*)this + 4);
    }
    __forceinline void DecRefCount()
    {
        if (FUN_00fdf1c4((char*)this + 4) == 0)
            v1();
    }
};

// Exe 0x00c46a40: same one-pointer Gamebryo ownership; retain this unit's inline forms.
} // namespace fnv_00c46a40
template <> __forceinline NiPointer<fnv_00c46a40::NodeRef>::NiPointer()
{
    m_pObject = 0;
    if (m_pObject != 0) m_pObject->IncRefCount();
}
template <> __forceinline NiPointer<fnv_00c46a40::NodeRef>::~NiPointer()
{
    if (m_pObject != 0) m_pObject->DecRefCount();
}
template <> inline NiPointer<fnv_00c46a40::NodeRef>& NiPointer<fnv_00c46a40::NodeRef>::operator=(fnv_00c46a40::NodeRef* object)
{
    if (m_pObject != object) {
        if (m_pObject != 0) m_pObject->DecRefCount();
        m_pObject = object;
        if (m_pObject != 0) m_pObject->IncRefCount();
    }
    return *this;
}
namespace fnv_00c46a40 {


struct FUN_00c46a40 : FUN_00c5f680
{
    int* vfptr;
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
    NiPointer<NodeRef> node;
    FUN_00c46a40(int a);
};

// @fnv 0x00c46a40
FUN_00c46a40::FUN_00c46a40(int a) : FUN_00c5f680(a, 1), vfptr(&DAT_010c1d14)
{
    node = 0;
}
}  // namespace fnv_00c46a40

namespace fnv_00c50c30 {
static __forceinline void fnvDead2()
{
    int aiDead[2];
}
template <class T> class SmartPtr
{
  public:
    T* m_pObject;
    SmartPtr(T* object = 0)
    {
        m_pObject = object;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    ~SmartPtr()
    {
        if (m_pObject)
        {
            fnvDead2();
            m_pObject->DecRefCount();
        }
    }
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
    bool operator!=(T* object) const
    {
        return m_pObject != object;
    }
};
struct NodeC4 : NiRefObject
{
    int GetIndex()
    {
        return unkC4;
    }
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
};
struct SpOwner
{
    void FUN_006e5cc0(SmartPtr<NodeC4>* p);
};
struct C50c30
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
    int* unkAC;
    void NiNode_DetachChild_00a5e780(int a, SmartPtr<NodeC4>* out);
    void BSParticleSystemManager_DetachChild_00c50c30(int a, SpOwner* b);
};
// @fnv 0x00c50c30
// src: XBOX_PDB 0x00c50c30
void C50c30::BSParticleSystemManager_DetachChild_00c50c30(int a, SpOwner* b)
{
    SmartPtr<NodeC4> m_pController;
    NiNode_DetachChild_00a5e780(a, &m_pController);
    if (m_pController != 0)
    {
        NodeC4* pNode = m_pController;
        unkAC[pNode->GetIndex()] = -1;
    }
    b->FUN_006e5cc0(&m_pController);
}
}  // namespace fnv_00c50c30


namespace fnv_00c52d80 {
extern int DAT_0109a284;
extern int DAT_01030f8c;
struct MapItem
{
    MapItem* next;
    unsigned int key;
    unsigned int value;
};
struct MapVTable
{
    void(__thiscall* destroy)(void*);
    unsigned int(__thiscall* hash)(const void*, unsigned int);
};
struct FUN_00a54060_class
{
    void* InitBuffer(unsigned int n);
};
struct ArrA : FUN_00a54060_class
{
    int* vtable;
    unsigned int count;
    unsigned int* data;
    unsigned int cap;
    __forceinline ArrA(unsigned int n)
    {
        InitBuffer(n);
        vtable = &DAT_0109a284;
    }
    ~ArrA();
    __forceinline unsigned int First() const
    {
        for (unsigned int i = 0; i < count; ++i)
            if (data[i])
                return data[i];
        return 0;
    }
    inline void AdvanceToNextEntry(unsigned int* cur, unsigned int* idxOut, unsigned int* valOut)
    {
        MapItem* item = (MapItem*)*cur;
        *idxOut = item->key;
        *valOut = item->value;
        if (item->next)
            *cur = (unsigned int)item->next;
        else
        {
            unsigned int bucket = ((MapVTable*)vtable)->hash(this, item->key) + 1;
            for (; bucket < count; ++bucket)
                if (data[bucket])
                {
                    *cur = data[bucket];
                    return;
                }
            *cur = 0;
        }
    }
};
struct FUN_0057c960
{
    int* vtable;
    unsigned int count;
    unsigned int* data;
    unsigned int cap;
    FUN_0057c960(int n);
};
struct ArrB : FUN_0057c960
{
    __forceinline ArrB(int n) : FUN_0057c960(n)
    {
        vtable = &DAT_01030f8c;
    }
    ~ArrB();
    __forceinline unsigned int First() const
    {
        for (unsigned int i = 0; i < count; ++i)
            if (data[i])
                return data[i];
        return 0;
    }
    inline void GetNextEntry(unsigned int* cur, unsigned int* out, unsigned char* outB)
    {
        MapItem* item = (MapItem*)*cur;
        *out = item->key;
        *outB = (unsigned char)item->value;
        if (item->next)
            *cur = (unsigned int)item->next;
        else
        {
            unsigned int bucket = ((MapVTable*)vtable)->hash(this, item->key) + 1;
            for (; bucket < count; ++bucket)
                if (data[bucket])
                {
                    *cur = data[bucket];
                    return;
                }
            *cur = 0;
        }
    }
};
}  // namespace fnv_00c52d80
struct LinkAllocator
{
    void* Game_DoHeapAlloc(unsigned int);
};
struct LinkSet
{
    int* data;
    unsigned int count;
    unsigned int capacity;
    static __forceinline void* operator new(unsigned int n)
    {
        return ((LinkAllocator*)&DAT_011f6238)->Game_DoHeapAlloc(n);
    }
    __forceinline LinkSet(int n)
    {
        FUN_00a54110(n);
    }
    void FUN_00a54110(int);
    void AppendLinkID(unsigned int* p);
};
namespace fnv_00c52d80 {
void* __cdecl _NiMalloc_00aa1070(unsigned int);
void __cdecl _NiFree_00aa10f0(void*);
}  // namespace fnv_00c52d80
inline void NiBSBoneLODController::SubObj::FUN_00a90180(unsigned int n)
{
    if (n == capacity)
        return;
    if (n < high)
    {
        for (unsigned short i = (unsigned short)n; i < high; ++i)
        {
            if (data[i])
            {
                data[i] = 0;
                --used;
            }
        }
        high = (unsigned short)n;
    }
    LinkSet** oldData = data;
    capacity = (unsigned short)n;
    if (n > 0)
    {
        data = (LinkSet**)_NiMalloc_00aa1070(capacity * sizeof(LinkSet*));
        unsigned short i;
        for (i = 0; i < high; ++i)
            data[i] = oldData[i];
        for (i = high; i < capacity; ++i)
            data[i] = 0;
    }
    else
        data = 0;
    _NiFree_00aa10f0(oldData);
}
// @fnv 0x00c52d80
// src: COMMUNITY 0x00c52d80
bool NiBSBoneLODController::InitializeData_00c52d80(Node_cls* arg)
{
    NiBSBoneLODController_CleanUp();
    fnv_00c52d80::ArrA a9(0x25);
    fnv_00c52d80::ArrB b2(0x25);
    NiBSBoneLODController_CollectMarkedBones(arg, reinterpret_cast<ArrA*>(&a9), reinterpret_cast<ArrB*>(&b2));
    unsigned int maxVal = 0;
    unsigned int cur5 = b2.First();
    unsigned int i5;
    while (cur5)
    {
        unsigned int kOut1;
        unsigned char outB6;
        b2.GetNextEntry(&cur5, &kOut1, &outB6);
        if (kOut1 > maxVal)
            maxVal = kOut1;
    }
    f38 = maxVal + 1;
    sub.FUN_00a90180(f38);
    for (i5 = 0; i5 < f38; ++i5)
    {
        sub.FUN_00ba3aa0(i5, 0);
    }
    cur5 = a9.First();
    while (cur5)
    {
        unsigned int idxOutVal;
        unsigned int valOut8;
        a9.AdvanceToNextEntry(&cur5, &idxOutVal, &valOut8);
        LinkSet* entry = sub.data[valOut8];
        if (!entry)
        {
            entry = new LinkSet(0);
            sub.FUN_00ba3aa0(valOut8, entry);
        }
        entry->AppendLinkID(&idxOutVal);
    }
    unsigned int out5 = 0;
    UpdateMaxValue(arg, reinterpret_cast<ArrA*>(&a9), &out5);
    NiBSBoneLODController_SetBoneLOD((void*)-1);
    return true;
}


namespace fnv_00c53030 {
#include <string.h>
#include <stdlib.h>

extern NiRTTI DAT_011f4a38;

struct TreeNode
{
    virtual void First();
    virtual void Second();
    virtual const NiRTTI* GetTypeList();
    virtual void* IsActive();
    int unk04;
    int unk08;
    const char* descriptor;
    TreeNode** elements;
    unsigned short elementCount;
    unsigned short unk16;
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
    TreeNode** children;
    unsigned short unka4;
    unsigned short childCount;
};

struct MemoryMgr
{
    void* __thiscall Game_DoHeapAlloc(unsigned int);
    void __thiscall MemoryManager_Deallocate(void*);
};
extern "C" char DAT_011f6238;

struct CollectionSink
{
    void InsertOrUpdate(TreeNode*, unsigned int);
};
struct ValueSink
{
    void NiTMapBase_NiTPointerAllocator_unsigned_int_TESObjectREFR_bool_SetAt(unsigned int, bool);
};

// Two leading bytes keep the count at +2, which is where this frame spills elementCount.
struct ElementCount
{
    char align0;
    char align1;
    unsigned short value;
};

struct FUN_00c53030_Shell
{
    void NiBSBoneLODController_CollectMarkedBones(TreeNode* group, CollectionSink* collector, ValueSink* values);
};

// /Ob1 inline. return stores the caller bool and jumps once to the ternary.
__forceinline void IsBoneLODExtra(TreeNode* node, const NiRTTI*& inner, bool& prior)
{
    inner = node->GetTypeList();
    while (inner)
    {
        if (inner == &DAT_011f4a38)
        {
            prior = true;
            return;
        }
        inner = inner->m_pBaseRTTI;
    }
    prior = false;
}

// @fnv 0x00c53030
// src: COMMUNITY 0x00c53030
void FUN_00c53030_Shell::NiBSBoneLODController_CollectMarkedBones(TreeNode* group, CollectionSink* collector, ValueSink* values)
{
    TreeNode* component;
    unsigned int b;
    {
        TreeNode* descriptorFromObject;
        {
            const char* kIter;
            char* slot;
            char* child;
            {
                char* token;
                unsigned long loadedChild;
                unsigned int s;
                {
                    TreeNode* count;
                    char* allocatedBuffer;
                    char* freedBuffer5;
                    ElementCount lod;
                    const NiRTTI* inner;
                    bool prior;
                    const char* z;
                    unsigned int edge, feed, fire, frac, head, heap;
                    TreeNode** state5;
                    TreeNode* length4;

                    for (b = 0; lod.value = group->elementCount, b < lod.value; b++)
                    {
                        component = group->elements[(unsigned short)b];
                        if (0 == component)
                        {
                            descriptorFromObject = 0;
                        }
                        else
                        {
                            IsBoneLODExtra(component, inner, prior);
                            descriptorFromObject = prior ? component : 0;
                        }
                        if (descriptorFromObject)
                        {
                            z = descriptorFromObject->descriptor;
                            kIter = z;
                            if (kIter && strstr(kIter, "BSBoneLOD#Bone#"))
                            {
                                loadedChild = strlen(kIter) + 1;
                                allocatedBuffer = (char*)((MemoryMgr*)&DAT_011f6238)->Game_DoHeapAlloc(loadedChild);
                                child = allocatedBuffer;
                                strcpy_s(child, loadedChild, kIter);
                                token = strtok_s(child, "#", &slot);
                                if (token && !strcmp(token, "BSBoneLOD"))
                                {
                                    token = strtok_s(0, "#", &slot);
                                    if (token && !strcmp(token, "Bone"))
                                    {
                                        token = strtok_s(0, "#", &slot);
                                        if (token)
                                        {
                                            s = atoi(token);
                                            collector->InsertOrUpdate(group, s);
                                            values->NiTMapBase_NiTPointerAllocator_unsigned_int_TESObjectREFR_bool_SetAt(s, true);
                                        }
                                    }
                                }
                                freedBuffer5 = child;
                                ((MemoryMgr*)&DAT_011f6238)->MemoryManager_Deallocate(freedBuffer5);
                                break;
                            }
                        }
                    }

                    for (b = 0; b < group->childCount; b++)
                    {
                        state5 = &group->children[b];
                        length4 = *state5;
                        count = length4;
                        if (count && count->IsActive())
                        {
                            NiBSBoneLODController_CollectMarkedBones(count, collector, values);
                        }
                    }
                }
            }
        }
    }
}
}  // namespace fnv_00c53030

namespace fnv_00c55170 {
extern int DAT_012031e4;

struct AvCaller
{
    NiExtraData* FUN_00a5bdd0(const NiFixedString& name);
};

// Inlined under /Ob1. GetRTTI stays outside so the virtual call keeps the
// caller's registers; kind and node are caller locals.
inline void WalkRTTI(const NiRTTI*& kind, const NiRTTI* target, bool& node)
{
    while (kind)
    {
        if (kind == target)
        {
            node = true;
            return;
        }
        kind = kind->m_pBaseRTTI;
    }
    node = false;
}

// @fnv 0x00c55170
// src: COMMUNITY 0x00c55170
NiExtraData* __cdecl BSBound_Find(AvCaller* a)
{
    NiExtraData* result = 0;
    if (a)
    {
        NiFixedString* name = (NiFixedString*)DAT_012031e4;
        NiExtraData* extra = a->FUN_00a5bdd0(*name);
        if (!extra)
        {
            result = 0;
        }
        else
        {
            const NiRTTI* kind = ((NiObject*)extra)->GetRTTI();
            bool node;
            WalkRTTI(kind, (const NiRTTI*)&g_012031e8, node);
            result = node ? extra : 0;
        }
    }
    return result;
}
}  // namespace fnv_00c55170

#include <math.h>
inline LocalVec3::LocalVec3() {}
inline LocalVec3::LocalVec3(float a, float b, float c) : x(a), y(b), z(c) {}
inline LocalVec3 LocalVec3::operator*(float f) const { return LocalVec3(f*x, f*y, f*z); }
inline LocalVec3 LocalVec3::operator+(const LocalVec3& v) const { return LocalVec3(v.x+x, v.y+y, v.z+z); }
inline LocalVec3 LocalVec3::operator-(const LocalVec3& v) const { return LocalVec3(x-v.x, y-v.y, z-v.z); }
inline LocalVec3& LocalVec3::operator*=(float f) { x*=f; y*=f; z*=f; return *this; }
namespace fnv_00c57d70 {
#include <math.h>

extern float DAT_010c2c34;
extern double DAT_01011590;
extern char DAT_010c2c98[];
double __cdecl FUN_00ec9f30(double);
double __cdecl FUN_00eca060(double);
inline float TrigCos(float a)
{
    return (float)FUN_00ec9f30((double)a);
}
inline float TrigSin(float a)
{
    return (float)FUN_00eca060((double)a);
}


__forceinline void* operator new[](unsigned int n)
{
    return g_memoryManager.Allocate(n);
}
struct TESObjectDoorController
{
    static void* operator new(unsigned int);
};
char* __cdecl FUN_00a5b690(const char*);
extern char* DAT_0109b220;
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);



struct ObjC57 : TESObjectDoorController
{
    void __thiscall SetName(const NiFixedString& name);
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
    virtual void vfn_00c0();
    virtual void vfn_00c4();
    virtual void vfn_00c8();
    virtual void vfn_00cc();
    virtual void vfn_00d0();
    virtual void vfn_00d4();
    virtual void vfn_00d8();
    virtual void vfn_00dc();
    virtual void vfn_00e0();
    virtual void vfn_00e4();
    virtual ObjC57* vfn_00e8();
    int f_04;
    int f_08;
    int f_0c;
    int f_10;
    int f_14;
    int f_18;
    int f_1c;
    int f_20;
    int f_24;
    int f_28;
    int f_2c;
    int f_30;
    int f_34;
    int f_38;
    int f_3c;
    int f_40;
    int f_44;
    int f_48;
    int f_4c;
    int f_50;
    int f_54;
    int f_58;
    int f_5c;
    int f_60;
    int f_64;
    int f_68;
    int f_6c;
    int f_70;
    int f_74;
    int f_78;
    int f_7c;
    int f_80;
    int f_84;
    int f_88;
    int f_8c;
    int f_90;
    int f_94;
    int f_98;
    int f_9c;
    int f_a0;
    int f_a4;
    int f_a8;
    int f_ac;
    int f_b0;
    int f_b4;
    int f_b8;
    int f_bc;
    int f_c0;
    ObjC57(int a1, LocalVec3* a2, LocalVec3* a3, Vec4* a4, int a5, int a6, int a7, int a8, int a9, unsigned short* a10,
           unsigned short* a11);
};
// @fnv 0x00c57d70
#pragma intrinsic(memcpy)
// src: COMMUNITY 0x00c57d70
ObjC57* __cdecl TES_DrawTorus(float p0, float p1, unsigned short w, unsigned short h, Vec4* src)
{
    float angleStep8;
    angleStep8 = (float)(DAT_010c2c34 * DAT_01011590 / (float)w);
    float step9;
    step9 = (float)(DAT_010c2c34 * DAT_01011590 / (float)h);
    unsigned short n24;
    n24 = (unsigned short)(2 * h + 2);
    unsigned int capacity19;
    capacity19 = w * n24;
    LocalVec3* ver654;
    ver654 = new LocalVec3[capacity19];
    LocalVec3* norm_2;
    norm_2 = new LocalVec3[capacity19];
    Vec4* q0;
    q0 = src ? new Vec4[capacity19] : 0;
    unsigned short* idxA6;
    idxA6 = new unsigned short[w];
    unsigned short* indices5;
    indices5 = new unsigned short[capacity19];
    unsigned short indexA6;
    indexA6 = 0;
    unsigned short strip3;
    strip3 = 0;
    float angle3;
    angle3 = 0.0f;
    float cosPrev4;
    cosPrev4 = 1.0f;
    float sineA;
    sineA = 0.0f;
    for (int i = w - 1; i >= 0; --i)
    {
        float angA4;
        angA4 = angle3 + angleStep8;
        float c3;
        c3 = (float)cos(angA4);
        float sine2;
        sine2 = (float)sin(angA4);
        float angB3;
        angB3 = 0.0f;
        for (int j = h; j >= 0; --j)
        {
            angB3 += step9;
            float cosBA;
            cosBA = (float)cos(angB3);
            float r16;
            r16 = (float)sin(angB3);
            float radius9;
            radius9 = p0 * cosBA + p1;
            memcpy(&ver654[indexA6], &(const LocalVec3&) (LocalVec3(c3 * radius9, -sine2 * radius9, p0 * r16)), sizeof(LocalVec3));
            memcpy(&norm_2[indexA6], &(const LocalVec3&) (LocalVec3(c3 * cosBA, -sine2 * cosBA, r16)), sizeof(LocalVec3));
            if (src)
                q0[indexA6] = *src;
            indices5[indexA6] = indexA6;
            ++indexA6;
            memcpy(&ver654[indexA6], &(const LocalVec3&) (LocalVec3(cosPrev4 * radius9, -sineA * radius9, p0 * r16)), sizeof(LocalVec3));
            memcpy(&norm_2[indexA6], &(const LocalVec3&) (LocalVec3(cosPrev4 * cosBA, -sineA * cosBA, r16)), sizeof(LocalVec3));
            if (src)
                q0[indexA6] = *src;
            indices5[indexA6] = indexA6;
            ++indexA6;
        }
        idxA6[strip3] = n24;
        ++strip3;
        angle3 = angA4;
        cosPrev4 = c3;
        sineA = sine2;
    }
    ObjC57* obj15;
    obj15 = new ObjC57(indexA6, ver654, norm_2, q0, 0, 0, 0, 2 * w * h, w, idxA6, indices5);
    obj15->SetName(NiFixedString((const char*)DAT_010c2c98));
    obj15->vfn_00e8();
    return obj15;
}
#pragma function(memcpy)
}  // namespace fnv_00c57d70

#include <math.h>
namespace fnv_00c584a0 {
struct MeshAllocator
{
    void* Allocate(unsigned int);
};
extern MeshAllocator meshMemory;
__forceinline void* operator new[](unsigned int n)
{
    return meshMemory.Allocate(n);
}
struct MeshPoint
{
    float x, y, z;
    __forceinline MeshPoint()
    {}
    __forceinline MeshPoint(float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }
    static __forceinline void* operator new[](unsigned int n) throw()
    {
        return meshMemory.Allocate(n);
    }
};
struct MeshUV
{
    float x, y;
    __forceinline MeshUV()
    {}
    __forceinline MeshUV(float a, float b)
    {
        x = a;
        y = b;
    }
    static __forceinline void* operator new[](unsigned int n) throw()
    {
        return meshMemory.Allocate(n);
    }
};
struct MeshColor
{
    float r, g, b, a;
    __forceinline MeshColor() : r(0), g(0), b(0), a(0)
    {}
    static __forceinline void* operator new[](unsigned int n) throw()
    {
        return meshMemory.Allocate(n);
    }
};
extern float DAT_010c2c34;
struct CylinderMesh
{
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
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
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
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void Update();
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
    static void* operator new(unsigned int);
    CylinderMesh(unsigned short, MeshPoint*, MeshPoint*, MeshColor*, MeshUV*, unsigned short, int, unsigned short,
                 unsigned short, unsigned short*, unsigned short*);
    void SetMeshName(const NiFixedString&);
};
extern "C" double __cdecl sin(double);
extern "C" double __cdecl cos(double);
__forceinline float meshSin(float a)
{
    return float(sin(a));
}
__forceinline float meshCos(float a)
{
    return float(cos(a));
}
// @fnv 0x00c584a0
// src: XBOX_PDB 0x00c584a0
CylinderMesh* __cdecl BSTestObjects_CreateCylinder(float bottom, float top, float height, unsigned short slices, unsigned short stacks,
                                   MeshColor* color)
{
    unsigned short stripSizeX = 2 * slices + 2;
    unsigned int count7 = stacks * stripSizeX;
    MeshPoint* point15 = new MeshPoint[count7];
    MeshPoint* normal6 = new MeshPoint[count7];
    MeshColor* pkColors8 = color ? new MeshColor[count7] : 0;
    MeshUV* finalTexcoords6 = new MeshUV[count7];
    unsigned short* lengthsVal = new unsigned short[stacks];
    unsigned short* indices_19 = new unsigned short[count7];
    unsigned short index4 = 0;
    float angleStep6 = 2.0f * DAT_010c2c34 / slices;
    float radiusStep2 = (top - bottom) / stacks;
    float heightStep = height / stacks;
    float uStep9 = 1.0f / slices;
    float kVStep = 1.0f / stacks;
    float v2 = 1.0f;
    float zl = 0.0f;
    float rRadius = bottom;
    float _normal = (bottom - top) / height;  // Z component of the unnormalized surface normal.
    float aNormalScale = 1.0f;
    for (unsigned int row = 0; row < stacks; row++)
    {
        float u = 0.0f;
        for (unsigned int col = 0; col <= slices; col++)
        {
            float sine, cosine;
            if (col == slices)
            {
                sine = 0.0f;
                cosine = 1.0f;
            }
            else
            {
                sine = (double)meshSin(col * angleStep6);
                cosine = (double)meshCos(col * angleStep6);
            }
            point15[index4] = MeshPoint(sine * rRadius, cosine * rRadius, zl);
            normal6[index4] = MeshPoint(sine * aNormalScale, cosine * aNormalScale, _normal * aNormalScale);
            if (color)
                pkColors8[index4] = *color;
            finalTexcoords6[index4] = MeshUV(u, v2);
            indices_19[index4] = index4;
            index4++;
            point15[index4] =
                MeshPoint(sine * (rRadius + radiusStep2), cosine * (rRadius + radiusStep2), zl + heightStep);
            normal6[index4] = MeshPoint(sine * aNormalScale, cosine * aNormalScale, _normal * aNormalScale);
            if (color)
                pkColors8[index4] = *color;
            finalTexcoords6[index4] = MeshUV(u, v2 - kVStep);
            indices_19[index4] = index4;
            index4++;
            u += uStep9;
        }
        rRadius += radiusStep2;
        v2 -= kVStep;
        zl += heightStep;
        lengthsVal[row] = stripSizeX;
    }
    CylinderMesh* mesh2 = new CylinderMesh(index4, point15, normal6, pkColors8, finalTexcoords6, 1, 0,
                                           2 * stacks * slices, stacks, lengthsVal, indices_19);
    mesh2->SetMeshName(NiFixedString("BSTestObjects Cylinder"));
    mesh2->Update();
    return mesh2;
}
}  // namespace fnv_00c584a0

#include <math.h>
namespace fnv_00c58f00 {
struct FUN_00aa3e40_alloc
{
    void* __thiscall Game_DoHeapAlloc(unsigned int size);
};
extern "C" char DAT_011f6238;
void* __cdecl Object_DispatchCommandFour(unsigned int size);
extern "C" double __cdecl cos(double angle);
extern "C" double __cdecl sin(double angle);

struct Vec3Item
{
    float x;
    float y;
    float z;
    __forceinline Vec3Item()
    {}
    __forceinline Vec3Item(float a, float b, float c) : x(a), y(b), z(c)
    {}
    static __forceinline void* operator new[](unsigned int size)
    {
        return ((FUN_00aa3e40_alloc*)&DAT_011f6238)->Game_DoHeapAlloc(size);
    }
};


struct SpawnedObject_b10495 : NiMemObject
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
    SpawnedObject_b10495(unsigned short count, Vec3Item* a, Vec4* b, int c, int d, int e, unsigned char* flags);
};

__forceinline float CircleTrigA(float a)
{
    return (double)(float)cos(a);
}
__forceinline float CircleTrigB(float a)
{
    return (double)(float)sin(a);
}
__forceinline void* operator new[](unsigned int size)
{
    return ((FUN_00aa3e40_alloc*)&DAT_011f6238)->Game_DoHeapAlloc(size);
}

// @fnv 0x00c58f00
// src: COMMUNITY 0x00c58f00
void* __cdecl BSTestObjects_CreateCircle(float radius, unsigned short count, Vec4* color)
{
    Vec3Item* aVal = new Vec3Item[count];
    unsigned char* flagsB = new unsigned char[count];
    Vec4* b5 = color ? new Vec4[count] : 0;
    float step3 = 6.2831854820251465 / (int)count;
    for (unsigned int i = 0; i < count; ++i)
    {
        if (b5 != 0)
        {
            b5[i] = *color;
        }
        flagsB[i] = 1;
        aVal[i] = Vec3Item(CircleTrigB(step3 * i) * radius, CircleTrigA(step3 * i) * radius, 0.0f);
    }
    SpawnedObject_b10495* result5 = new SpawnedObject_b10495(count, aVal, b5, 0, 1, 0, flagsB);
    return result5;
}
}  // namespace fnv_00c58f00

#include <math.h>
// Preserve trivial block-copy semantics where shared vector assignment is component-wise.
template <unsigned int Size> struct CopyBytes { unsigned char bytes[Size]; };
namespace fnv_00c5a0f0 {
#include <math.h>


struct Vec2
{
    float u, v;
    Vec2()
    {}
    Vec2(float a, float b) : u(a), v(b)
    {}
};
struct Color4
{
    float r, g, b, a;
    Color4() : r(0), g(0), b(0), a(0)
    {}
};
__forceinline void* operator new[](unsigned int size)
{
    return g_memoryManager.Allocate(size);
}

extern float DAT_010c2c34;
extern double DAT_01011590;
extern const float DAT_01016248;
extern const float DAT_01012054;
extern char DAT_010c2c80[];

void* __cdecl Object_DispatchCommandFour(unsigned int size);
int* __cdecl FUN_00a5b690(const char* value);
extern int DAT_0109b220;








extern const double DAT_01017cf8;
}  // namespace fnv_00c5a0f0
inline float LocalVec3::FUN_00457990() const
{
    return sqrt(x * x + y * y + z * z);
}
inline float LocalVec3::FUN_00457910()
{
    float magnitude = static_cast<const LocalVec3*>(this)->FUN_00457990();
    if (magnitude > fnv_00c5a0f0::DAT_01017cf8)
    {
        float inverse = 1.0f / magnitude;
        x *= inverse;
        y *= inverse;
        z *= inverse;
    }
    else
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
        magnitude = 0.0f;
    }
    return magnitude;
}
// src: GUESS 0x00439ef0 (confidence: high)
inline LocalVec3 LocalVec3::SubtractIntoVector(const LocalVec3& v) const
{
    return LocalVec3(x - v.x, y - v.y, z - v.z);
}
inline LocalVec3 LocalVec3::FUN_00439e90(const LocalVec3& v) const
{
    return LocalVec3(x + v.x, y + v.y, z + v.z);
}
inline LocalVec3 LocalVec3::FUN_004b3800(const LocalVec3& v) const
{
    return LocalVec3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
}
namespace fnv_00c5a0f0 {
NiAVObject* BSTestObjects_CreateBox(const LocalVec3&, const LocalVec3&, float, float, float, float, const Color4*, const Color4*);
void* _NiMalloc_00aa1070(unsigned int);
void* FUN_00ec44d0(void*, const void*, unsigned int);
extern const unsigned short DAT_010c2d10[];
extern double DAT_01034208, DAT_0101db80, DAT_01012060;
// @fnv 0x00c5a0f0
#pragma intrinsic(memcpy)
// src: COMMUNITY 0x00c5a0f0
NiNode* BSTestObjects_Create3DArrow(const LocalVec3& start, const LocalVec3& end, float width, float height, const Color4* shaftColor,
                       const Color4* tipColor)
{
    NiNode* rootNode4 = new NiNode(0);
    LocalVec3 direction6 = end.SubtractIntoVector(start);
    float lengthX = direction6.FUN_00457910();
    float length = 0.0f;
    float tipLength3 = width * DAT_01034208;
    if (lengthX > tipLength3)
        length = lengthX - tipLength3;
    else
        tipLength3 = lengthX;
    LocalVec3 nearEnd4 = start.FUN_00439e90(direction6 * length);
    if (length > DAT_01012060)
    {
        NiAVObject* shaft2 = BSTestObjects_CreateBox(start, nearEnd4, width, width, height, 0.0f, shaftColor, tipColor);
        rootNode4->AttachChildInAvailableSlot(shaft2, true);
    }
    LocalVec3* verticesX3 = new LocalVec3[6];
    LocalVec3 up4(0.0f, 0.0f, 1.0f);
    LocalVec3 sideC7 = direction6.FUN_004b3800(up4);
    sideC7 *= width * DAT_0101db80;
    LocalVec3 elevation5(0.0f, 0.0f, height);
    memcpy(&verticesX3[0], &(const LocalVec3&) (elevation5 + end), sizeof(LocalVec3));
    memcpy(&verticesX3[1], &(const LocalVec3&) (elevation5 + (sideC7 + nearEnd4)), sizeof(LocalVec3));
    reinterpret_cast<CopyBytes<sizeof(LocalVec3)>&>(verticesX3[2]) = reinterpret_cast<const CopyBytes<sizeof(LocalVec3)>&>(end);
    memcpy(&verticesX3[3], &(const LocalVec3&) (sideC7 + nearEnd4), sizeof(LocalVec3));
    memcpy(&verticesX3[4], &(const LocalVec3&) (elevation5 + (nearEnd4 - sideC7)), sizeof(LocalVec3));
    memcpy(&verticesX3[5], &(const LocalVec3&) (nearEnd4 - sideC7), sizeof(LocalVec3));
    if (shaftColor && !tipColor)
        tipColor = shaftColor;
    Color4* colors = tipColor ? new Color4[6] : 0;
    if (colors)
    {
        for (unsigned int i2 = 0; i2 < 6; ++i2)
            colors[i2] = *tipColor;
    }
    unsigned short* indices_10 = (unsigned short*)_NiMalloc_00aa1070(48);
    FUN_00ec44d0(indices_10, DAT_010c2d10, 48);
    NiTriShape* meshTmp = new NiTriShape(6, reinterpret_cast<NiPoint3*>(verticesX3), 0, colors, (NiPoint2*)0, 0, 0, 8, indices_10);
    meshTmp->CalculateNormals();
    rootNode4->AttachChildInAvailableSlot(reinterpret_cast<NiAVObject*>(meshTmp), true);
    return rootNode4;
}
#pragma function(memcpy)
}  // namespace fnv_00c5a0f0

#include <math.h>
namespace fnv_00c5a800 {
#include <math.h>

struct PerpPoint
{
    float x, y, z;
    PerpPoint()
    {}
    PerpPoint(float a, float b, float c) : x(a), y(b), z(c)
    {}
    float Length() const
    {
        return (float)sqrt(x * x + y * y + z * z);
    }
    PerpPoint operator/(float length) const
    {
        float inverse = 1.0f / length;
        return PerpPoint(x * inverse, y * inverse, z * inverse);
    }
    PerpPoint CrossProduct(const PerpPoint& v) const
    {
        PerpPoint cross(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
        float length = cross.Length();
        if (length > 0.0)
            return cross / length;
        else
            return PerpPoint(0.0f, 0.0f, 0.0f);
    }
    PerpPoint NiPoint3_Perpendicular() const;
};
extern const PerpPoint DAT_011a9484;
extern PerpPoint DAT_011a946c;
extern PerpPoint DAT_011a9478;
// @fnv 0x00c5a800
// src: COMMUNITY 0x00c5a800
PerpPoint PerpPoint::NiPoint3_Perpendicular() const
{
    if (fabs(x) < fabs(y))
    {
        if (fabs(z) < fabs(x))
            return CrossProduct(DAT_011a9484);
        else
            return CrossProduct(DAT_011a946c);
    }
    else
    {
        if (fabs(z) < fabs(y))
            return CrossProduct(DAT_011a9484);
        else
            return CrossProduct(DAT_011a9478);
    }
}
}  // namespace fnv_00c5a800

namespace fnv_00c5f2e0 {
extern char* DAT_0109b220;
extern MemoryManager _g_memoryManager;




extern NiFixedString* DAT_01204374;

// @fnv 0x00c5f2e0
// src: GUESS 0x00c5f2e0 (confidence: low)
void __cdecl Object_UpdateFields_00c5f2e0()
{
    delete DAT_01204374;
    DAT_01204374 = 0;
}
}  // namespace fnv_00c5f2e0

extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(volatile long*, long, long);
struct RemovalMapNode;
struct RemovalMapLink
{
    long bits;
    inline long Pointer()
    {
        RemovalMapLink* source = this;
        return source->bits & ~1;
    }
    inline long Value()
    {
        RemovalMapLink* source = this;
        return source->bits;
    }
    inline const long& Raw() const
    {
        const RemovalMapLink* source = this;
        return source->bits;
    }
    inline bool IsMarked()
    {
        RemovalMapLink* source = this;
        return (source->bits & 1) != 0;
    }
    void LockFreeMap_MarkedPointer_SetMark(bool);
    RemovalMapLink()
    {}
    inline RemovalMapLink(long pointer)
    {
        bits = pointer;
    }
    inline RemovalMapLink(long pointer, bool mark)
    {
        bits = pointer;
        Mark(mark);
    }
    inline bool Compare(long replacement, long expected)
    {
        bool succeeded = InterlockedCompareExchange(&bits, replacement, expected) == expected;
        return succeeded;
    }
    inline void Mark(bool mark)
    {
        RemovalMapLink* target = this;
        if (mark)
            target->bits |= 1;
        else
            target->bits &= ~1;
    }
};
struct RemovalMapObject
{
    long unk00, unk04;
    volatile long count;
    void BSTask_int64_DecRefCount();
};
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct RemovalMapHold
{
    RemovalMapObject* object;
    inline RemovalMapHold(RemovalMapObject* p) : object(p)
    {
        if (object)
            InterlockedIncrement(&object->count);
    }
    inline ~RemovalMapHold()
    {
        if (object)
            object->BSTask_int64_DecRefCount();
    }
};
struct RemovalMapHeader
{
    long unk00, unk04, unk08;
    volatile long* entries;
    unsigned int threshold;
};
struct RemovalMapNode
{
    long unk00, unk04;
    RemovalMapObject* object;
    RemovalMapLink next;
    inline bool CompareNext(long replacement, long expected)
    {
        bool succeeded = InterlockedCompareExchange(&next.bits, replacement, expected) == expected;
        return succeeded;
    }
};
struct RemovalMapState
{
    RemovalMapHeader* owner;
    long* slot04;
    long* slot08;
    long* slot0c;
    volatile long* head;
    RemovalMapLink current;
    RemovalMapLink next;
    RemovalMapNode* retired;
    unsigned int retiredCount;
// src: GUESS 0x00c41ac0 (confidence: low)
    inline bool ProcessEntries_00c41ac0(int index, int value)
    {
        volatile long* link = &owner->entries[index];
        while (true)
        {
            bool retry = false;
            head = link;
            current.bits = *head;
            *slot08 = current.Pointer();
            RemovalMapLink observed(current.Pointer());
            observed.LockFreeMap_MarkedPointer_SetMark(false);
            if (((RemovalMapLink*)head)->Value() != observed.Raw())
                continue;
            while (true)
            {
                if (!current.Pointer())
                    return false;
                next = ((RemovalMapNode*)current.Pointer())->next;
                *slot04 = next.Pointer();
                if (next.Value() != ((RemovalMapNode*)current.Pointer())->next.Raw())
                {
                    retry = true;
                    break;
                }
                RemovalMapHold hold(((RemovalMapNode*)current.Pointer())->object);
                RemovalMapLink previous(current.Pointer());
                previous.LockFreeMap_MarkedPointer_SetMark(false);
                if (((RemovalMapLink*)head)->Value() != previous.Raw())
                {
                    retry = true;
                    break;
                }
                if (!next.IsMarked())
                {
                    if (hold.object == *(RemovalMapObject**)value)
                        return true;
                    head = &((RemovalMapNode*)current.Pointer())->next.bits;
                    *slot0c = current.Pointer();
                }
                else
                {
                    RemovalMapLink replacement(next.Pointer(), false);
                    if (((RemovalMapLink*)head)->Compare(replacement.Value(), previous.Value()))
                        LockFreeMap_TESObjectREFR_NiPointer_QueuedReference_LockFreeMapInterface_DeleteNode((RemovalMapNode*)current.Pointer());
                    else
                    {
                        retry = true;
                        break;
                    }
                }
                current = next;
                *slot08 = next.Pointer();
            }
            if (retry)
                continue;
        }
    }
// src: COMMUNITY 0x00c41f40
    inline void LockFreeMap_TESObjectREFR_NiPointer_QueuedReference_LockFreeMapInterface_DeleteNode(RemovalMapNode* node)
    {
        RemovalMapObject** object = &node->object;
        if (*object)
        {
            if (*object)
                (*object)->BSTask_int64_DecRefCount();
            *object = 0;
            if (*object)
            {
                RemovalMapObject* incoming = *object;
                InterlockedIncrement(&incoming->count);
            }
        }
        RemovalMapNode* previous = retired;
        node->object = (RemovalMapObject*)previous;
        retired = node;
        ++retiredCount;
        unsigned int limit = owner->threshold;
        if (retiredCount == limit)
            Collect();
    }
    void Collect();
    bool ProcessEntries_00c40680(int, int);
};
// @fnv 0x00c40680
// src: GUESS 0x00c40680 (confidence: low)
bool RemovalMapState::ProcessEntries_00c40680(int arg1, int arg2)
{
    bool result = false;
    while (true)
    {
        if (!ProcessEntries_00c41ac0(arg1, arg2))
        {
            result = false;
            break;
        }
        RemovalMapLink expected(next.Pointer());
        expected.LockFreeMap_MarkedPointer_SetMark(false);
        RemovalMapLink desired(next.Pointer());
        desired.LockFreeMap_MarkedPointer_SetMark(true);
        if (!((RemovalMapNode*)current.Pointer())->CompareNext(desired.Value(), expected.Value()))
            continue;
        RemovalMapLink old(current.Pointer(), false);
        if (((RemovalMapLink*)head)->Compare(expected.Value(), old.Value()))
            LockFreeMap_TESObjectREFR_NiPointer_QueuedReference_LockFreeMapInterface_DeleteNode((RemovalMapNode*)current.Pointer());
        else
            ProcessEntries_00c41ac0(arg1, arg2);
        result = true;
        break;
    }
    *slot04 = 0;
    *slot08 = 0;
    *slot0c = 0;
    return result;
}

extern "C" __declspec(dllimport) int __stdcall ReleaseSemaphore(void*, long, long*);

struct WorkerSemaphore
{
    volatile long count;
    void* handle;
    inline void Wait()
    {
        WaitForSingleObject(handle, ~0UL);
        InterlockedDecrement(&count);
    }
    inline bool IsEmpty()
    {
        return WaitForSingleObject(handle, 0) == 258;
    }
    inline void Signal()
    {
        ReleaseSemaphore(handle, 1, 0);
        InterlockedIncrement(&count);
    }
};

struct WorkerEventBase
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned char flags;
    inline WorkerEventBase() : unk08(0), unk10(0), unk14(0), flags(0)
    {}
    virtual ~WorkerEventBase()
    {}
};
struct WorkerEvent : WorkerEventBase
{
    int unk1c;
    inline WorkerEvent()
    {}
    inline bool Done()
    {
        return (flags & 2) != 0;
    }
    inline void SetFlag(unsigned int mask, bool value)
    {
        if (value)
            flags |= mask;
        else
            flags &= ~mask;
    }
    void SetArg(int);
};
struct WorkerJob
{
    virtual ~WorkerJob();
    int unk04;
    volatile long refs;
    volatile long state;
    inline void AddRef()
    {
        InterlockedIncrement(&refs);
    }
// src: XBOX_PDB 0x0044dd60
    inline void BSTask_int64_DecRefCount()
    {
        long remaining = InterlockedDecrement(&refs);
        if (remaining == 0)
            delete this;
    }
};
inline bool WorkerTryStart(WorkerJob*& job)
{
    WorkerJob* self = job;
    {
        bool result = InterlockedCompareExchange(&self->state, 3, 1) == 1;
        return result;
    }
}
struct WorkerJobRef
{
    WorkerJob* value;
    inline WorkerJobRef(WorkerJob* p = 0) : value(p)
    {
        if (value)
            value->AddRef();
    }
    inline ~WorkerJobRef()
    {
        if (value)
            value->BSTask_int64_DecRefCount();
    }
    inline void operator=(WorkerJob* p)
    {
        if (value)
            value->BSTask_int64_DecRefCount();
        value = p;
        if (value)
            value->AddRef();
    }
};
struct WorkerQueueLock
{
    long owner, depth;
    void Lock(const char*);
    inline void Unlock()
    {
        --depth;
        if (depth == 0)
            owner = 0;
    }
};
struct WorkerJobContainer
{
    bool First(unsigned int, unsigned __int64*, WorkerJobRef*);
    bool Next(unsigned int, unsigned __int64*, WorkerJobRef*);
};
struct WorkerQueue;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
struct WorkerQueueTLS
{
    int unk00;
    unsigned long index;
    WorkerJobContainer* Create(WorkerQueue*);
};
struct WorkerQueue
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
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void Process(WorkerJob*);
    virtual void Finish(WorkerJob*);
    int unk04, unk08, unk0c, unk10;
    WorkerQueueTLS* tls;
    int unk18, unk1c;
    WorkerQueueLock lock;
    int unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned char stopping;
    bool LockFreeMap_int64_NiPointer_BSTask_int64_GetNext(WorkerEvent*, unsigned __int64*, WorkerJobRef*, bool);
    inline WorkerJobContainer* Container()
    {
        unsigned long index = tls->index;
        WorkerJobContainer* value = static_cast<WorkerJobContainer*>(TlsGetValue(index));
        return value ? value : tls->Create(this);
    }
};
// src: COMMUNITY 0x00c40e70
inline bool WorkerQueue::LockFreeMap_int64_NiPointer_BSTask_int64_GetNext(WorkerEvent* event, unsigned __int64* output, WorkerJobRef* job, bool wait)
{
    lock.Lock(0);
    bool found = false;
    if (static_cast<bool>(event->flags & 2))
    {
        found = false;
    }
    else
    {
        while (true)
        {
            if (!static_cast<bool>(event->flags & 1))
            {
                found = Container()->First(event->unk08, reinterpret_cast<unsigned __int64*>(&event->unk10), job);
                event->SetFlag(1, true);
            }
            else
            {
                found = Container()->Next(event->unk08, reinterpret_cast<unsigned __int64*>(&event->unk10), job);
            }
            if (!found)
            {
                ++event->unk08;
                unsigned int count = unk08;
                if (static_cast<unsigned int>(event->unk08) >= count)
                {
                    event->SetFlag(2, true);
                }
                else if (wait)
                {
                    event->SetFlag(1, false);
                    continue;
                }
            }
            else
            {
                *output = *reinterpret_cast<unsigned __int64*>(&event->unk10);
            }
            break;
        }
    }
    lock.Unlock();
    return found;
}
struct WorkerThread
{
    int unk00, unk04, unk08;
    WorkerSemaphore start;
    int unk14;
    WorkerSemaphore available;
    int unk20, unk24, unk28, unk2c;
    WorkerQueue* queue;
    void BSTaskManagerThread_int64_ThreadUpdate();
};
// @fnv 0x00c410b0
// src: XBOX_PDB 0x00c410b0
void WorkerThread::BSTaskManagerThread_int64_ThreadUpdate()
{
    while (queue->stopping != 1)
    {
        start.Wait();
        WorkerEvent event;
        bool result = false;
        while (!static_cast<bool>(event.flags & 2))
        {
            if (available.IsEmpty())
            {
                available.Wait();
                event.SetArg(0);
            }
            WorkerJobRef job;
            unsigned __int64 output;
            if (queue->LockFreeMap_int64_NiPointer_BSTask_int64_GetNext(&event, &output, &job, !result))
            {
                if (job.value->state == 1 && WorkerTryStart(job.value))
                {
                    result = true;
                    queue->Process(job.value);
                    queue->Finish(job.value);
                }
            }
            else if (!static_cast<bool>(event.flags & 2))
            {
                event.SetArg(0);
                result = false;
            }
            if (job.value)
                job = 0;
            available.Signal();
        }
    }
}

extern "C++" void* __cdecl FUN_00a5b690(const char* text);



// @fnv 0x00c43500
// src: COMMUNITY 0x00c43500
void __cdecl BSXFlags_InitSDM()
{
    DAT_01202ddc = (NiFixedString*)new NiFixedString("BSX");
}

namespace fnv_00c435a0 {

// @fnv 0x00c435a0
// src: GUESS 0x00c435a0 (confidence: low)
void __cdecl Object_UpdateFields_00c435a0()
{
    delete (NiFixedString*)DAT_01202ddc;
    DAT_01202ddc = 0;
}
}  // namespace fnv_00c435a0

struct CameraViewportC52
{
    float left, right, top, bottom;
    inline CameraViewportC52()
    {}
    inline CameraViewportC52(float x0, float x1, float y1, float y0) : left(x0), right(x1), top(y1), bottom(y0)
    {}
};
struct C52020Obj
{
    virtual void vfn_00();
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
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    CameraViewportC52 viewport;
};
struct C52520Camera
{
    virtual void vfn_00();
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
    C52020Obj* m_ac;
    int unkb0;
    int unkb4;
    unsigned char m_b8;
    float m_bc;
    inline C52020Obj* GetObj() const
    {
        return m_ac;
    }
    void SceneGraph_SetCameraFOV(float m_fFirstFloat, unsigned char ucFlag, C52020Obj* pObj, unsigned char ucArg4);
    void BSSceneGraph_UpdateCameraFOV();
};
// @fnv 0x00c52520
// src: XBOX_PDB 0x00c52520
void C52520Camera::BSSceneGraph_UpdateCameraFOV()
{
    CameraViewportC52 port(0.0f, 1.0f, 1.0f, 0.0f);
    GetObj()->viewport = port;
    SceneGraph_SetCameraFOV(m_bc, 1, 0, 0);
}

struct BoxColor
{
    float r, g, b, a;
};
extern unsigned short DAT_010c2c38[36];
extern const float DAT_01016248;
extern const float DAT_0102295c;

// Inlined under /Ob1. Its locals are reserved after the caller's new-expression
// temps, which is where this function's frame puts the cursor and colour state.
__forceinline void buildBox(NiPoint3* boxCorners, const NiPoint3& size, const BoxColor* color, BoxColor*& colors,
                            unsigned short*& indices, NiPoint3*& vertices, int& i, unsigned int& j,
                            NiPoint3*& vertexResult, NiPoint3*& vertexAllocation, BoxColor*& colorResult,
                            BoxColor*& colorAllocation, unsigned short*& indexAllocation)
{
    {
        NiPoint3* vertexCursor;
        int vertexRemaining;
        {
            BoxColor* colorCursor;
            {
                int colorRemaining;
                {
                    NiPoint3* vertexInitialized;
                    vertexAllocation = (NiPoint3*)g_memoryManager.Allocate(96);
                    if (vertexAllocation)
                    {
                        vertexRemaining = 8;
                        vertexCursor = vertexAllocation;
                        while (--vertexRemaining >= 0)
                        {
                            ++vertexCursor;
                        }
                        vertexInitialized = vertexAllocation;
                    }
                    else
                    {
                        vertexInitialized = 0;
                    }
                    vertexResult = vertexInitialized;
                    vertices = vertexResult;
                    {
                        volatile float fx, afDepth, fy;
                        for (i = 0; i < 8; ++i)
                        {
                            fx = (float)(boxCorners[i].x * size.x);
                            vertices[i].x = fx;
                            afDepth = (float)(boxCorners[i].y * size.y);
                            vertices[i].y = afDepth;
                            fy = (float)(boxCorners[i].z * size.z);
                            vertices[i].z = fy;
                        }
                        {
                            BoxColor* colorInitialized;
                            {
                                BoxColor* conditionalColor;
                                if (color)
                                {
                                    colorAllocation = (BoxColor*)g_memoryManager.Allocate(128);
                                    if (colorAllocation)
                                    {
                                        colorRemaining = 8;
                                        colorCursor = colorAllocation;
                                        while (--colorRemaining >= 0)
                                        {
                                            colorCursor->r = 0.0f;
                                            colorCursor->g = 0.0f;
                                            colorCursor->b = 0.0f;
                                            colorCursor->a = 0.0f;
                                            ++colorCursor;
                                        }
                                        colorInitialized = colorAllocation;
                                    }
                                    else
                                    {
                                        colorInitialized = 0;
                                    }
                                    colorResult = colorInitialized;
                                    conditionalColor = colorResult;
                                }
                                else
                                {
                                    conditionalColor = 0;
                                }
                                colors = conditionalColor;
                            }
                        }
                    }
                    if (colors)
                    {
                        for (j = 0; j < 8; ++j)
                        {
                            colors[j] = *color;
                        }
                    }
                    indexAllocation = (unsigned short*)g_memoryManager.Allocate(72);
                    indices = indexAllocation;
                    memcpy(indices, DAT_010c2c38, 72);
                }
            }
        }
    }
}

float boxCorners[8][3];
struct InitializeBoxCorners
{
    __forceinline InitializeBoxCorners() throw()
    {
        boxCorners[0][0] = DAT_01016248;
        boxCorners[0][1] = DAT_01016248;
        boxCorners[0][2] = DAT_01016248;
        boxCorners[1][0] = DAT_01016248;
        boxCorners[1][1] = DAT_01016248;
        boxCorners[1][2] = DAT_0102295c;
        boxCorners[2][0] = DAT_01016248;
        boxCorners[2][1] = DAT_0102295c;
        boxCorners[2][2] = DAT_01016248;
        boxCorners[3][0] = DAT_01016248;
        boxCorners[3][1] = DAT_0102295c;
        boxCorners[3][2] = DAT_0102295c;
        boxCorners[4][0] = DAT_0102295c;
        boxCorners[4][1] = DAT_01016248;
        boxCorners[4][2] = DAT_01016248;
        boxCorners[5][0] = DAT_0102295c;
        boxCorners[5][1] = DAT_01016248;
        boxCorners[5][2] = DAT_0102295c;
        boxCorners[6][0] = DAT_0102295c;
        boxCorners[6][1] = DAT_0102295c;
        boxCorners[6][2] = DAT_01016248;
        boxCorners[7][0] = DAT_0102295c;
        boxCorners[7][1] = DAT_0102295c;
        boxCorners[7][2] = DAT_0102295c;
    }
};
// @fnv 0x00c55920
// src: COMMUNITY 0x00c55920
NiTriShape* __cdecl BSTestObjects_CreateBox_0(const NiPoint3& size, const BoxColor* color)
{
    static InitializeBoxCorners initializedCorners;
    {
        BoxColor* colors;
        unsigned short* indices;
        NiPoint3* vertices;
        NiTriShape* shape;
        {
            int i;
            {
                unsigned int j;
                {
                    NiPoint3* vertexResult;
                    NiPoint3* vertexAllocation;
                    {
                        BoxColor* colorResult;
                        {
                            BoxColor* colorAllocation;
                            {
                                unsigned short* indexAllocation;
                                buildBox(reinterpret_cast<NiPoint3*>(boxCorners), size, color, colors, indices, vertices, i, j, vertexResult,
                                         vertexAllocation, colorResult, colorAllocation, indexAllocation);
                                shape = new NiTriShape(8, vertices, 0, colors, (NiPoint2*)0, 0, 0, 12, indices);
                                shape->CalculateNormals();
                                return shape;
                            }
                        }
                    }
                }
            }
        }
    }
}

struct S00c59660_Pt3 : public NiPoint3
{
    S00c59660_Pt3()
    {}
    S00c59660_Pt3(float fx, float fy, float afDepth)
    {
        x = fx;
        y = fy;
        z = afDepth;
    }
};
inline void* operator new[](unsigned int size, S_00c42960_Heap& pool)
{
    return pool.Game_DoHeapAlloc(size);
}
inline void operator delete[](void*, S_00c42960_Heap&)
{}

class FUN_00a746e0 : public NiAVObject
{
  public:
    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
    static void operator delete(void* p);
    FUN_00a746e0(int n, NiPoint3* pts, ColorA* cols, int a, int b, int c, unsigned char* flags);
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
};

extern ColorA DAT_012032f8;

// @fnv 0x00c59660
#pragma intrinsic(memcpy)
// src: XBOX_PDB 0x00c59660
FUN_00a746e0* __cdecl BSTestObjects_CreateArrow(float length, ColorA* color)
{
    float dBA = length / 6.0;
    S00c59660_Pt3* pts = ::new (*(S_00c42960_Heap*)&DAT_011f6238) S00c59660_Pt3[5];
    memcpy(&pts[0], &(const S00c59660_Pt3&)S00c59660_Pt3(0.0f, 0.0f, 0.0f), sizeof(pts[0]));
    memcpy(&pts[1], &(const S00c59660_Pt3&)S00c59660_Pt3(0.0f, 0.0f, length), sizeof(pts[1]));
    memcpy(&pts[2], &(const S00c59660_Pt3&)S00c59660_Pt3(dBA, 0.0f, length - dBA), sizeof(pts[2]));
    memcpy(&pts[3], &(const S00c59660_Pt3&)S00c59660_Pt3(0.0f, 0.0f, length), sizeof(pts[3]));
    memcpy(&pts[4], &(const S00c59660_Pt3&)S00c59660_Pt3(-dBA, 0.0f, length - dBA), sizeof(pts[4]));
    if (!color)
    {
        color = &DAT_012032f8;
    }
    ColorA* cols = new (*(S_00c42960_Heap*)&DAT_011f6238) ColorA[6];
    cols[0] = *color;
    cols[1] = *color;
    cols[2] = *color;
    cols[3] = *color;
    cols[4] = *color;
    unsigned char* flags2 = new (*(S_00c42960_Heap*)&DAT_011f6238) unsigned char[6];
    flags2[0] = 1;
    flags2[1] = 1;
    flags2[2] = 0;
    flags2[3] = 1;
    flags2[4] = 0;
    FUN_00a746e0* obj4 = new FUN_00a746e0(5, pts, cols, 0, 0, 0, flags2);
    memcpy(&obj4->m_kLocal.m_Translate, &DAT_011f426c, sizeof(NiPoint3));
    obj4->m_kLocal.m_Rotate = *(NiMatrix3*)&DAT_011a9448;
    obj4->SetName((const NiFixedString&)NiFixedString("BSTestObjects Arrow"));
    return obj4;
}

#pragma function(memcpy)
// Scene-graph ownership-transfer constructor.
// Copies a source node's controller chain, properties, extra data, transform and
// children onto "this", guarded by an is-kind-of test on the source.

extern "C" char DAT_010c32a8;
extern "C" __declspec(dllimport) void __stdcall FUN_00fdf05c(void* pvLock);
extern "C" __declspec(dllimport) void __stdcall FUN_00fdf100(void* pvLock);

struct C5RTTI
{
    const char* m_pcName;
    C5RTTI* m_pkBase;
};

struct C5Fixed
{
    int m_p;
};

struct C5RefObj
{
    virtual void vfn_00();
    virtual void vfn_04();
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            vfn_04();
    }
    volatile long m_uiRefCount;
};

struct C5Mat3
{
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
};

struct C5Vec3
{
    float x, y, z;
};

struct C5TimeCtl
{
    void SetTarget(void* pkTarget);
};

struct C5Chain
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual C5RTTI* vfn_08();
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
    virtual void vfn_98(void* pkArg);
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    NiPointer<C5Chain> next;
    C5Chain* GetNext() const
    {
        return next;
    }
};

struct C5Ctl
{
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
    virtual void vfn_dc(void* pkArg, int iFlag);
    virtual void vfn_e0();
    virtual void vfn_e4(void* pkArg, NiPointer<C5RefObj>* pkOut);
};

struct C5Base;
struct C5Collision : C5RefObj
{
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void SetOwner(C5Base*);
    C5Base* owner;
    C5Base* GetOwner() const
    {
        return owner;
    }
};
struct C5ListItem
{
    C5ListItem* next;
    C5ListItem* prev;
    NiPointer<C5RefObj> value;
    NiPointer<C5RefObj>& GetElement()
    {
        return value;
    }
};
struct C5List
{
    C5ListItem* head;
    C5ListItem* tail;
    unsigned int count;
    NiPointer<C5RefObj> Remove(NiPointer<C5RefObj>&);
    bool IsEmpty() const
    {
        return count == 0;
    }
    NiPointer<C5RefObj>& GetHead() const
    {
        return head->GetElement();
    }
};

struct C5Base
{
    C5Base(unsigned int uiFlags);
    ~C5Base();
    virtual void vfn_base();
    int unk04;
    C5Fixed name;
    NiPointer<C5Chain> chain;
    void** extraData;
    unsigned short extraCount, extraCapacity;
    C5Ctl* controller;
    NiPointer<C5Collision> collision;
    int unk20;
    C5List properties;
    int unk30;
    C5Mat3 rotation;
    C5Vec3 translation;
    float scale;
    C5Mat3 worldRotation;
    C5Vec3 worldTranslation;
    float worldScale;
    NiTObjectArray<NiPointer<C5RefObj> > children;
    C5Chain* GetControllers() const
    {
        return chain;
    }
    void* GetChild(unsigned int index) const
    {
        return children.GetAt(index);
    }
    void* GetCollision() const
    {
        return collision;
    }
    unsigned short GetExtraCount() const
    {
        return extraCount;
    }
    void* GetExtra(unsigned short index) const
    {
        return extraData[index];
    }
    float GetScale() const
    {
        return scale;
    }
    void SetName(const C5Fixed& kName);
    void AttachProperty(void* pkProperty);
    void AddExtraData(void* pkExtra);
    void AttachChildInAvailableSlot(void* pkChild, bool bFlag);
    void FUN_00a5bba0(unsigned short usValue);
    void UpdateWorldBoundFromChildren();
    void BSNiNode_ReparentSkinInstances(void* pkA, void* pkB);
    void AttachTarget(void* pkArg)
    {
        collision = static_cast<C5Collision*>(pkArg);
        if (collision && collision->GetOwner() != this)
            collision->SetOwner(this);
    }
    bool NiObject_IsKindOf_006532c0(const void* pkRTTI);
    void ForwardToSubobject(int iValue)
    {
        NiPointer<C5RefObj> property(reinterpret_cast<C5RefObj*>(iValue));
        C5List& propertyList = properties;
        propertyList.Remove(property);
    }
    bool RemoveExtraDataAt(unsigned short usValue);
};
typedef C5Base C5Src;

__forceinline bool SafeSource(C5Src* source)
{
    if (source == 0)
        return false;
    return source->NiObject_IsKindOf_006532c0(&DAT_011f4aa0);
}
__forceinline bool ControllerKind(C5Chain* object)
{
    C5RTTI* type = object->vfn_08();
    while (type != 0)
    {
        if (type == (C5RTTI*)&DAT_011f36ac)
            return true;
        type = type->m_pkBase;
    }
    return false;
}
__forceinline bool SafeController(C5Chain* object)
{
    if (object == 0)
        return false;
    return ControllerKind(object);
}

namespace C5Transfer {
struct FUN_00c5f680 : C5Base
{
    FUN_00c5f680(C5Src* pkSource, bool bCopy);
    ~FUN_00c5f680();
    virtual void vfn_00();
};

// @fnv 0x00c5f680
FUN_00c5f680::FUN_00c5f680(C5Src* pkSource, bool bCopy) : C5Base(0)
{
    bool ok5 = true;
    C5Ctl* pCtl = pkSource->controller;
    SetName(pkSource->name);

    if (bCopy)
    {
        if (pkSource->GetControllers() != 0 || SafeSource(pkSource))
        {
            ok5 = false;
            ConcatPrefixAndSuffix((FUN_00c5fb80_rec*)pkSource, &DAT_010c32a8);
        }
    }

    if (ok5)
    {
        C5Chain* p = pkSource->GetControllers();
        while (p != 0)
        {
            C5Chain* pNext = p->GetNext();
            if (SafeController(p))
                ((C5TimeCtl*)p)->SetTarget(this);
            else
                p->vfn_98(this);
            p = pNext;
        }

        AttachTarget(pkSource->GetCollision());
        pkSource->AttachTarget(0);

        for (unsigned int i = 0; i < pkSource->children.m_usSize; i++)
        {
            void* pkChild = pkSource->GetChild(i);
            if (pkChild != 0)
                AttachChildInAvailableSlot(pkChild, true);
        }

        while (!pkSource->properties.IsEmpty())
        {
            void* pkProperty = pkSource->properties.GetHead();
            AttachProperty(pkProperty);
            pkSource->ForwardToSubobject((int)pkProperty);
        }

        translation = pkSource->translation;
        rotation = pkSource->rotation;
        scale = (float)fabs(pkSource->GetScale());

        FUN_00fdf05c(&DAT_011f4380);
        FUN_00a5bba0(pkSource->GetExtraCount());
        while (pkSource->GetExtraCount() != 0)
        {
            void* pkExtra = pkSource->GetExtra(0);
            AddExtraData(pkExtra);
            pkSource->RemoveExtraDataAt(0);
        }
        FUN_00fdf100(&DAT_011f4380);

        if (pCtl != 0)
        {
            NiPointer<C5RefObj> spRetainedObject;
            pCtl->vfn_e4(pkSource, &spRetainedObject);
        }

        BSNiNode_ReparentSkinInstances(this, this);
    }
    else
    {
        AttachChildInAvailableSlot(pkSource, true);
    }

    if (pCtl != 0)
        pCtl->vfn_dc(this, 1);

    UpdateWorldBoundFromChildren();
}
}

struct WorkItem_j61
{
    virtual ~WorkItem_j61();
    int unk04, unk08, unk0c, unk10, unk14;
    void* child4;
    void* context;
    WorkItem_j61();
    void Setup(void* c, void* x)
    {
        child4 = c;
        context = x;
    }
};
struct TaskEvent_j61
{
    virtual void v00();
    virtual void Wait(int);
    virtual void Signal(int);
    bool ready;
};
struct EventRef_j61;
struct TaskManager_j61
{
    void Begin(EventRef_j61*);
    void Queue(EventRef_j61*, void*, int);
    void Finish(EventRef_j61*);
};
TaskManager_j61& GetTaskletManager();
struct EventRef_j61
{
    TaskEvent_j61* value;
    void Signal(int x)
    {
        if (value)
            value->Signal(x);
    }
    void Begin()
    {
        GetTaskletManager().Begin(this);
    }
    void Queue(void* task, int x)
    {
        GetTaskletManager().Queue(this, task, x);
    }
    void Finish()
    {
        GetTaskletManager().Finish(this);
    }
    void Wait(int x)
    {
        if (value)
        {
            bool ready = value->ready;
            if (!ready)
                value->Wait(x);
        }
    }
};
struct TaskRef_j61
{
    virtual ~TaskRef_j61()
    {}
    WorkItem_j61* value;
    TaskRef_j61() : value(0)
    {}
};
struct ChildObject_j61
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
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void Process(void*, int);
};
__forceinline ChildObject_j61*& ChildAt(ChildObject_j61** children, unsigned int index)
{
    ChildObject_j61** entry = &children[index];
    return *entry;
}
struct ProcessOwner_j61
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
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void Finish();
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
    ChildObject_j61** children;
    unsigned short capacity, count;
    int unka8, unkac, unkb0;
    EventRef_j61* event;
    void BSParticleSystemManager_UpdateParallel(void* context);
};
// @fnv 0x00c50610
// src: COMMUNITY 0x00c50610
void ProcessOwner_j61::BSParticleSystemManager_UpdateParallel(void* context)
{
    unsigned int total8 = count;
    WorkItem_j61* jobs3 = 0;
    bool parallelA = false;
    unsigned int queued = 0;
    if (parallelA)
    {
        jobs3 = new WorkItem_j61[total8];
        event->Signal(0);
        event->Begin();
    }
    ChildObject_j61* child4;
    for (unsigned int index = 0; index < total8; ++index)
    {
        child4 = ChildAt(children, index);
        if (child4)
        {
            if (parallelA)
            {
                TaskRef_j61 task;
                jobs3[index].Setup(child4, context);
                task.value = &jobs3[index];
                event->Queue(&task, 0);
                ++queued;
            }
            else
                child4->Process(context, 0);
        }
    }
    if (parallelA)
    {
        event->Finish();
        if (queued != 0)
        {
            event->Signal(99);
            event->Wait(0);
        }
        delete[] jobs3;
    }
    Finish();
}

double __cdecl FUN_00eca060(double);
double __cdecl FUN_00ec9f30(double);
inline float SphereCosValue(float angle)
{
    return static_cast<float>(FUN_00eca060(static_cast<double>(angle)));
}
inline float SphereSinValue(float angle)
{
    return static_cast<float>(FUN_00ec9f30(static_cast<double>(angle)));
}
inline float SphereCos(float angle)
{
    return static_cast<double>(SphereCosValue(angle));
}
inline float SphereSin(float angle)
{
    return static_cast<double>(SphereSinValue(angle));
}


struct Vec2
{
    float u, v;
    Vec2()
    {}
    Vec2(float a, float b) : u(a), v(b)
    {}
};
struct Color4
{
    float r, g, b, a;
    Color4() : r(0), g(0), b(0), a(0)
    {}
};

extern float DAT_010c2c34;
extern double DAT_01011590;
extern const float DAT_01016248;
extern const float DAT_01012054;
extern char DAT_010c2c80[];

void* __cdecl Object_DispatchCommandFour(unsigned int size);

struct Mesh : NiMemObject
{
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
    Mesh(unsigned short vertexCount, LocalVec3* vertices, LocalVec3* normals, Color4* colors, Vec2* uv, bool hasNormals,
         bool flag, unsigned short triangleCount, unsigned short stripCount, unsigned short* stripLengths,
         unsigned short* indices);
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
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void Update();
};





// @fnv 0x00c56680
#pragma intrinsic(memcpy)
// src: XBOX_PDB 0x00c56680
NiNode* __cdecl BSTestObjects_CreateSphere(float radius, unsigned short slices, unsigned short stacks, const Color4* color)
{
    NiNode* rootUpdate6;
    LocalVec3* capNormals7;
    unsigned int capacity0;
    float angle36;
    float vStep3;
    Vec2* capUVs2;
    float uvX;
    float radius5;
    NiTriShape* capShape2;
    LocalVec3* capVertices2;
    unsigned short poleIndex8;
    float southernLatitude7;
    Mesh* sideShape8;
    float uStep;
    unsigned short* strips2;
    unsigned short vertexCount5;
    unsigned short* sideD3;
    unsigned short* capIndicesA;
    float angle28;
    Color4* color9;
    unsigned short indexB;
    float capUX;
    unsigned short intermediateBands5;
    unsigned short strip;
    rootUpdate6 = new NiNode(0);
    rootUpdate6->SetName(NiFixedString((const char*)DAT_010c2c80));

    radius5 = 1.0f;
    angle36 = DAT_010c2c34 / static_cast<float>(stacks);
    angle28 = DAT_010c2c34 * DAT_01011590 / static_cast<float>(slices);
    uStep = 1.0f / static_cast<float>(slices);
    vStep3 = 1.0f / static_cast<float>(stacks);

    capVertices2 = new LocalVec3[2 * slices + 2];
    capNormals7 = new LocalVec3[2 * slices + 2];
    color9 = color ? new Color4[2 * slices + 2] : 0;
    capUVs2 = new Vec2[2 * slices + 2];
    capIndicesA = new unsigned short[slices * 6];

    vertexCount5 = 0;
    indexB = 0;
    poleIndex8 = vertexCount5;

    memcpy(&capVertices2[vertexCount5], &(const LocalVec3&) (LocalVec3(0.0f, 0.0f, radius5 * radius)), sizeof(LocalVec3));
    memcpy(&capNormals7[vertexCount5], &(const LocalVec3&) (LocalVec3(0.0f, 0.0f, 1.0f)), sizeof(LocalVec3));
    if (color)
        color9[vertexCount5] = *color;
    capUVs2[vertexCount5] = Vec2(0.5f, 0.0f);
    ++vertexCount5;
    capUX = 0.0f;
    uvX = vStep3;
    for (unsigned int slice9 = 0; slice9 < slices; ++slice9)
    {
        float angle44;
        float z6;
        float x15;
        float y23;
        angle44 = static_cast<float>(slice9) * angle28;
        x15 = -static_cast<float>(SphereCos(angle44)) * static_cast<float>(SphereCosValue(angle36));
        y23 = static_cast<float>(SphereSin(angle44)) * static_cast<float>(SphereCosValue(angle36));
        z6 = radius5 * static_cast<float>(SphereSinValue(angle36));
        memcpy(&capVertices2[vertexCount5], &(const LocalVec3&) (LocalVec3(x15 * radius, y23 * radius, z6 * radius)), sizeof(LocalVec3));
        memcpy(&capNormals7[vertexCount5], &(const LocalVec3&) (LocalVec3(x15 * radius5, y23 * radius5, z6 * radius5)), sizeof(LocalVec3));
        if (color)
            color9[vertexCount5] = *color;
        capUVs2[vertexCount5] = Vec2(capUX, uvX);
        ++vertexCount5;
        capUX += uStep;
        if (slice9 > 0)
        {
            capIndicesA[indexB++] = poleIndex8;
            capIndicesA[indexB++] = static_cast<unsigned short>(vertexCount5 - 2);
            capIndicesA[indexB++] = static_cast<unsigned short>(vertexCount5 - 1);
        }
    }
    capIndicesA[indexB++] = poleIndex8;
    capIndicesA[indexB++] = static_cast<unsigned short>(vertexCount5 - 1);
    capIndicesA[indexB++] = static_cast<unsigned short>(poleIndex8 + 1);

    poleIndex8 = vertexCount5;

    memcpy(&capVertices2[vertexCount5], &(const LocalVec3&) (LocalVec3(0.0f, 0.0f, -radius * radius5)), sizeof(LocalVec3));
    memcpy(&capNormals7[vertexCount5], &(const LocalVec3&) (LocalVec3(0.0f, 0.0f, -1.0f)), sizeof(LocalVec3));
    if (color)
        color9[vertexCount5] = *color;
    capUVs2[vertexCount5] = Vec2(0.5f, 1.0f);
    ++vertexCount5;
    southernLatitude7 = DAT_010c2c34 - angle36;
    capUX = 1.0f;
    uvX = 1.0f - vStep3;
    for (unsigned int indexA4 = slices; indexA4 > 0; --indexA4)
    {
        float angle57;
        float z7;
        float x26;
        float fY5;
        angle57 = indexA4 == slices ? 0.0f : static_cast<float>(indexA4) * angle28;
        x26 = -static_cast<float>(SphereCos(angle57)) * static_cast<float>(SphereCosValue(southernLatitude7));
        fY5 = static_cast<float>(SphereSin(angle57)) * static_cast<float>(SphereCosValue(southernLatitude7));
        z7 = radius5 * static_cast<float>(SphereSinValue(southernLatitude7));
        memcpy(&capVertices2[vertexCount5], &(const LocalVec3&) (LocalVec3(x26 * radius, fY5 * radius, z7 * radius)), sizeof(LocalVec3));
        memcpy(&capNormals7[vertexCount5], &(const LocalVec3&) (LocalVec3(x26 * radius5, fY5 * radius5, z7 * radius5)), sizeof(LocalVec3));
        if (color)
            color9[vertexCount5] = *color;
        capUVs2[vertexCount5] = Vec2(capUX, uvX);
        ++vertexCount5;
        capUX -= uStep;
        if (indexA4 != slices)
        {
            capIndicesA[indexB++] = poleIndex8;
            capIndicesA[indexB++] = static_cast<unsigned short>(vertexCount5 - 2);
            capIndicesA[indexB++] = static_cast<unsigned short>(vertexCount5 - 1);
        }
    }
    capIndicesA[indexB++] = poleIndex8;
    capIndicesA[indexB++] = static_cast<unsigned short>(vertexCount5 - 1);
    capIndicesA[indexB++] = static_cast<unsigned short>(poleIndex8 + 1);

    capShape2 =
        new NiTriShape(vertexCount5, reinterpret_cast<NiPoint3*>(capVertices2), reinterpret_cast<NiPoint3*>(capNormals7), color9, reinterpret_cast<NiPoint2*>(capUVs2), true, false, indexB / 3, capIndicesA);
    capShape2->CalculateNormals();
    rootUpdate6->AttachChildInAvailableSlot(reinterpret_cast<NiAVObject*>(capShape2), true);

    uvX = 0.0f;
    intermediateBands5 = static_cast<unsigned short>(stacks - 2);
    strip = static_cast<unsigned short>(2 * slices + 2);
    capacity0 = static_cast<unsigned int>(intermediateBands5) * strip;
    capVertices2 = new LocalVec3[capacity0];
    capNormals7 = new LocalVec3[capacity0];
    color9 = color ? new Color4[capacity0] : 0;
    capUVs2 = new Vec2[capacity0];
    strips2 = new unsigned short[intermediateBands5];
    sideD3 = new unsigned short[capacity0];
    vertexCount5 = 0;
    for (unsigned int band = 0; band < intermediateBands5; ++band)
    {
        southernLatitude7 = (band + 1) * angle36;
        capUX = 0.0f;
        for (unsigned int vertexCount9 = 0; vertexCount9 <= slices; ++vertexCount9)
        {
            float angle72;
            float zq;
            float x29;
            float fYA;
            angle72 = vertexCount9 == slices ? 0.0f : static_cast<float>(vertexCount9) * angle28;
            x29 = -static_cast<float>(SphereCos(angle72)) * static_cast<float>(SphereCosValue(southernLatitude7));
            fYA = static_cast<float>(SphereSin(angle72)) * static_cast<float>(SphereCosValue(southernLatitude7));
            zq = radius5 * static_cast<float>(SphereSinValue(southernLatitude7));
            memcpy(&capVertices2[vertexCount5], &(const LocalVec3&) (LocalVec3(x29 * radius, fYA * radius, zq * radius)), sizeof(LocalVec3));
            memcpy(&capNormals7[vertexCount5], &(const LocalVec3&) (LocalVec3(x29 * radius5, fYA * radius5, zq * radius5)), sizeof(LocalVec3));
            if (color)
                color9[vertexCount5] = *color;
            capUVs2[vertexCount5] = Vec2(capUX, uvX);
            sideD3[vertexCount5] = vertexCount5;
            ++vertexCount5;
            x29 = -static_cast<float>(SphereCos(angle72)) *
                  static_cast<float>(SphereCosValue(southernLatitude7 + angle36));
            fYA = static_cast<float>(SphereSin(angle72)) *
                  static_cast<float>(SphereCosValue(southernLatitude7 + angle36));
            zq = radius5 * static_cast<float>(SphereSinValue(southernLatitude7 + angle36));
            memcpy(&capVertices2[vertexCount5], &(const LocalVec3&) (LocalVec3(x29 * radius, fYA * radius, zq * radius)), sizeof(LocalVec3));
            memcpy(&capNormals7[vertexCount5], &(const LocalVec3&) (LocalVec3(x29 * radius5, fYA * radius5, zq * radius5)), sizeof(LocalVec3));
            if (color)
                color9[vertexCount5] = *color;
            capUVs2[vertexCount5] = Vec2(capUX, uvX + vStep3);
            sideD3[vertexCount5] = vertexCount5;
            ++vertexCount5;
            capUX += uStep;
        }
        uvX += vStep3;
        strips2[band] = strip;
    }

    sideShape8 = new Mesh(vertexCount5, capVertices2, capNormals7, color9, capUVs2, true, false,
                          intermediateBands5 * (slices * 2), intermediateBands5, strips2, sideD3);
    sideShape8->Update();
    rootUpdate6->AttachChildInAvailableSlot(reinterpret_cast<NiAVObject*>(sideShape8), true);
    return rootUpdate6;
}

#pragma function(memcpy)
namespace fnv_00c42b80 {
// Diagnostic /Ob1 build matches all 540 bytes; shipped flag set does not.
struct C42Tls
{
    int m_000[173];
    int m_2b4;
};
extern "C" __declspec(thread) C42Tls c42tls;
inline int C42GetState()
{
    return c42tls.m_2b4;
}
inline void C42SetState(int x)
{
    c42tls.m_2b4 = x;
}
struct C42Guard
{
    int m_00;
    C42Guard(int x)
    {
        m_00 = C42GetState();
        C42SetState(x);
    }
    ~C42Guard()
    {
        C42SetState(m_00);
    }
};
struct C42Heap
{
    void* Game_DoHeapAlloc(unsigned);
    void MemoryManager_Deallocate(void*);
};
extern "C" C42Heap c42heap;
struct C42Object
{
    void BSTask_int64_DecRefCount();
};
struct C42Node;
// Preserve the target's unreferenced 12-byte inline-local region.
struct C42Hole
{
    int m_00, m_04, m_08;
};
inline void C42Padding()
{
    C42Hole hole;
    (void)&hole;
}
struct C42Ref
{
    C42Node* m_00;
    ~C42Ref()
    {
        if (m_00)
            ((C42Object*)m_00)->BSTask_int64_DecRefCount();
    }
};
struct C42Node
{
    int m_00;
    C42Ref m_04;
    C42Node* Next()
    {
        return m_04.m_00;
    }
    static void operator delete(void* p)
    {
        c42heap.MemoryManager_Deallocate(p);
    }
};
inline void* operator new[](unsigned n)
{
    return c42heap.Game_DoHeapAlloc(n);
}
inline void operator delete[](void* p)
{
    c42heap.MemoryManager_Deallocate(p);
}
struct C42Count
{
    unsigned m_00;
    unsigned Get()
    {
        return m_00;
    }
};
struct C42Owner
{
    int m_00, m_04, m_08, m_0c;
    C42Node** m_10;
    C42Count* m_14;
    unsigned Count()
    {
        return m_14->Get();
    }
    C42Node** Data()
    {
        return m_10;
    }
};
struct C42List
{
    C42Owner* m_00;
    int m_04, m_08;
    unsigned m_0c;
    C42Node* m_10;
    void CopyData_00c42b80();
};
extern "C" void* __cdecl memmove(void*, const void*, unsigned);
// @fnv 0x00c42b80
// src: GUESS 0x00c42b80 (confidence: low)
void C42List::CopyData_00c42b80()
{
    C42Guard _ctx(6);
    unsigned _iCount = m_00->Count() * 2;
    C42Node** _file = new C42Node*[_iCount];
    memmove(_file, m_00->Data(), _iCount * 4);
    C42Node* _count = 0;
    unsigned _len = 0;
    while (m_10)
    {
        C42Node* _handle = m_10;
        m_10 = m_10->Next();
        bool _found = false;
        for (unsigned i = 0; i < _iCount; ++i)
        {
            if (_handle == _file[i])
            {
                _found = true;
                break;
            }
        }
        if (_found)
        {
            _handle->m_04.m_00 = _count;
            _count = _handle;
            ++_len;
        }
        else
        {
            _handle->m_04.m_00 = 0;
            C42Padding();
            delete _handle;
        }
    }
    delete[] _file;
    m_10 = _count;
    m_0c = _len;
}
}  // namespace fnv_00c42b80
