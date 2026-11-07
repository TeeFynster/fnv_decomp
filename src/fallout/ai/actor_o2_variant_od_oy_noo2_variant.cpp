#include "../../../include/NiQuaternion.h"

// src/fallout/ai/actor_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Oy- (unit src/fallout/ai/actor_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout/ai/actor_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/ai/actor.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
#include "../../../include/Actor.h"
#include "../../../include/MemoryManager.h"
#include "../../../include/hkMemoryAllocator.h"
#include "../../../include/hkMemoryRouter.h"
#include "../../../include/Creature.h"
#include "../../../include/Mat3.h"
#include "../../../include/NiNode.h"
#include "../../../include/NiTransform.h"
#include "../../../include/NiUpdateData.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/NiMatrix3.h"
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern MemoryManager g_memoryManager;
extern "C" void* g_012685f8;
void* __cdecl bhkStiffSpringConstraint_GetRTTI();
extern "C" void __cdecl _delete(void*, int);
void __cdecl FUN_00cc58c0();
struct FUN_00c7fa70_Class
{
    void* __thiscall FUN_00c7fa70(int);
};
extern "C" void __cdecl FUN_0062d4b0();
extern int DAT_01084e54;
struct FUN_00cb9900_cls
{
    void __thiscall UpdateFields_00cb9900();
};
void __cdecl hkaPose_syncModelSpace();
void __cdecl FUN_00cd9fe0();
struct FUN_00cda4b0_cls
{
    void __thiscall hkaPose_accessSyncedPoseModelSpace();
};
struct FUN_00cda8d0_class
{
    void hkaPose_syncModelSpace();
    void* hkaPose_getSyncedPoseModelSpace();
};
struct FUN_00cdb290
{
    void __thiscall syncLocalSpace();
    void* __thiscall GetPlus4();
};
struct VObj
{
    virtual void f0();
    virtual void f1();
    virtual void f2(void*, unsigned int);
};
struct Holder
{
    char pad[16];
    VObj* p;
};
Holder* _FUN_00c85750();
struct Outer
{
    int _0;
    unsigned short _4;
    void __thiscall FUN_00c7dc40();
    Outer* __thiscall FUN_00c7e970(unsigned int);
};
struct MyNode
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int Pred();
    char _pad0[0x18];
    MyNode* field_1c;
    char _pad1[0x80];
    MyNode** children;
    char _pad2[2];
    unsigned short count;
};
MyNode* __cdecl bhkUtilFunctions_FindNextCollisionObject(MyNode* p);
struct MyRef
{
    virtual ~MyRef();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement((long*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((long*)&m_uiRefCount) == 0)
        {
            DeleteThis();
        }
    }
};
struct Target;
struct Target18
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
    virtual void MethodE4(Target* p, NiPointer<MyRef>& sp);
};
struct Target
{
    char pad[0x18];
    Target18* field_18;
};
struct FUN_00c6ffc0_Class
{
    Target* bhkCharacterController_GetCollisionDebugNode();
    void bhkCharacterController_RemoveCollisionDebug();
};
extern char* EmptyFS;
struct FixedStr
{
    char* h;
    FixedStr(const FixedStr& o)
    {
        if (o.h != EmptyFS)
            InterlockedIncrement((long volatile*)(o.h - 8));
        h = o.h;
    }
    ~FixedStr()
    {
        if (h != EmptyFS)
            InterlockedDecrement((long volatile*)(h - 8));
    }
    bool Equals(const char*) const;
};
struct Xform
{
    Mat3 rot;
    NiPoint3 trans;
    float scale;
};
struct RNode;
struct RObj
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual RNode* GetAsNode();
    int _4;
    FixedStr name;
    char _c[0xc];
    RObj* parent;
    char _1c[0x18];
    Xform local;
};
struct RNode
{
    char _0[0xa0];
    RObj** children;
    unsigned short _a4;
    unsigned short count;
};
struct RKey
{
    FixedStr name;
    RObj* obj;
    RKey(const FixedStr& n) : name(n)
    {}
};
struct RElem
{
    RObj* obj;
    Xform x;
};
struct RArr
{
    int _0;
    RElem* data;
    int AppendSlot();
    void ConstructElementArray(RElem*, int);
};
struct RCtx;
RObj* __cdecl BSUtilities_GetObjectByName_00c4b470(RCtx*, RKey*, int);
void __cdecl CopyPoseFunctor(RCtx* ctx, RObj* obj, RArr* arr);
void __cdecl SetFlagRecursive(int, void*);
void __cdecl CopyPoseFunctor(void*, void*, void*);
inline unsigned char GetFlag6(unsigned short w)
{
    return (unsigned char)(w >> 6) & 1;
}
void __cdecl bhkRagdollController_CopyPoseTo3D(NiNode* param_1, void* param_2, void* param_3, char* param_4, unsigned int* param_5);
void NI2HK_00c74dd0(void*, NiTransform*);
extern bool DAT_01267c28;
extern bool DAT_01267c34;
extern bool DAT_01267c40;
extern bool DAT_01267c4c;
extern bool DAT_01267c58;
extern bool DAT_01267c64;
struct RagScrapMarker
{
    char* p;
    unsigned int size;
    RagScrapMarker(unsigned int count)
    {
        char** top = (char**)_FUN_00c85750();
        unsigned int size = (count * 48 + 0x7f) & ~0x7fu;
        char* old = *top;
        *top = old + size;
        p = old;
    }
    ~RagScrapMarker()
    {
        *(char**)_FUN_00c85750() = p;
    }
};
struct RagNode
{
    char pad0[0x18];
    RagNode* m_pParentNode;
    char pad1c[0x34 - 0x1c];
    NiTransform m_kLocalTransform;
    NiTransform m_kWorldSpaceTransform;
    RagNode* GetParent() const
    {
        return m_pParentNode;
    }
};
struct RagInner
{
    char pad[0x1c];
    unsigned int count;
    unsigned int GetCount() const
    {
        return count;
    }
};
struct RagMid
{
    char pad[0x2c];
    RagInner* inner;
    RagInner* GetInner() const
    {
        return inner;
    }
};
struct FUN_00c7d630_t
{
    char pad0[0x48];
    RagMid* m_48;
    char pad4c[0x58 - 0x4c];
    RagNode* m_pkNode;
    char pad5c[4];
    NiMatrix3 m_kRot;
    void bhkRagdollController_DoRagdollAnim(float);
    void bhkRagdollController_GetSGPoseLocalSpace();
    void bhkRagdollController_UpdateDebugLines(int);
    void bhkRagdollController_DoFootIK(void*);
    void bhkRagdollController_DoGrabIK(void*);
    void bhkRagdollController_DoLookAtIK(void*);
    void bhkRagdollController_DoPoseMatching(void*, void*, bool*);
    void bhkRagdollController_UpdateRagdollRigidBodies(void*);
    void bhkRagdollController_DoRagdollFeedback();
    void bhkRagdollController_SetSGPoseLocalSpace();
};
struct FUN_00cb0c00_class
{
    void Object_UpdateFields_00cb0c00();
};
struct VObjExt : VObj
{
    virtual void v3();
    virtual void v4(void*, unsigned int);
};
struct FUN_00c7d890_cls
{
    void* _0;
    int _4;
    unsigned int _8;
    void ProcessEntries_00c7d890();
};
void* __cdecl FUN_00ec7230(char*, char const*, unsigned int);
void __stdcall BSSimpleArray_bhkUtilFunctions_AVLevel_1024_CopyItems(char* dst, char* src, unsigned int count);
void __cdecl hkaKeyFrameHierarchyUtility_initialize(void*, unsigned int);
struct FUN_00cdb3e0_cls
{
    char pad[0x2c];
    void hkaRagdollRigidBodyController_reinitialize();
};
struct S_c6a200_Info
{
    int unk00, unk04, unk08, unk0c;
};
struct S_c6a200_Ev
{
    int unk00;
    unsigned char unk04;
    int unk08;
    int unk0c;
    int unk10, unk14, unk18;
};
extern void* DAT_011afecc;
S_c6a200_Info* __cdecl GetExtraDataChecked(void* obj);
void __cdecl bhkWorld_DoObjectRec(void* obj, S_c6a200_Ev* ev, void* extra);
bool __cdecl bhkWorld_SetDisabled(void* obj, unsigned char a1, unsigned char a2, unsigned char a3);
struct FlagController
{
    void bhkRagdollController_SetRagdollFeedbackActive(int);
    void bhkRagdollController_EnableRagdollFeedback(bool);
};
struct HkAllocator
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void Deallocate(void*, int);
};
struct HkMemHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    HkAllocator* allocator;
    HkAllocator* GetAllocator()
    {
        return allocator;
    }
};
HkMemHolder* GetHkMemHolder();
template <class T> inline void HkDeallocT(HkAllocator* a, T* p, int n)
{
    a->Deallocate(p, n * (int)sizeof(T));
}
struct HkElem30
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
};
template <class T> struct HkArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    ~HkArray()
    {
        HkAllocator* alloc = GetHkMemHolder()->GetAllocator();
        m_iElementCount = 0;
        if (!(m_iCapacityState & 0x80000000))
            HkDeallocT<T>(alloc, m_data, m_iCapacityState & 0x3fffffff);
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};
struct FUN_00c7c030
{
    int unk00;
    HkArray<HkElem30> arr04;
    HkArray<HkElem30> arr10;
    HkArray<int> arr1C;
    int unk28;
    HkArray<int> arr2C;
    ~FUN_00c7c030();
};
struct FreeIface
{
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void Free(void* p, unsigned int size);
};
struct FUN_00c7d480_cls
{
    void* m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    void UpdateFields_00c7d480();
};
struct ScopeGuard
{
    FUN_00c7d480_cls* owner;
// @fnv 0x00c7d480
    ScopeGuard(void* p) : owner((FUN_00c7d480_cls*)p)
    {}
    __forceinline ~ScopeGuard()
    {
        Holder* h = _FUN_00c85750();
        FreeIface* a = (FreeIface*)h->p;
        unsigned int flags = owner->m_08;
        owner->m_04 = 0;
        if (!(flags & 0x80000000))
        {
            a->Free(owner->m_00, (flags & 0x3fffffff) * 4);
        }
        owner->m_08 = 0x80000000;
        owner->m_00 = 0;
    }
};
// src: GUESS 0x00c7d480 (confidence: low)
void FUN_00c7d480_cls::UpdateFields_00c7d480()
{
    ScopeGuard guard(this);
    unsigned int count = m_0c;
    bool differs = count != (unsigned int)m_00;
    if (!differs)
    {
        m_04 = 0;
    }
    *(unsigned int*)_FUN_00c85750() = count;
}
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();
struct FUN_00c7d5c0_elem
{
    int unk00;
    void Release();
};
struct FUN_00c7d5c0_cls
{
    FUN_00c7d5c0_elem* m_pData;
    int m_iArrayLength;
    unsigned int m_uCap;

    void ProcessEntries_00c7d5c0();
};
extern unsigned int g_01268188;
extern unsigned int g_012685f4;
extern const char DAT_0108febc[];
extern const char DAT_010c52bc[];
struct BaseObject
{
    const char* classTable;
    unsigned int unknown04;
    unsigned int unknown08;
    BaseObject();
};
struct MiddleObject : BaseObject
{
    unsigned int initialized0c;
    MiddleObject() : initialized0c(0)
    {
        classTable = DAT_0108febc;
        ++g_01268188;
    }
    ~MiddleObject();
};
struct FUN_00c7f9e0 : MiddleObject
{
    FUN_00c7f9e0(void* context);
    void SpawnAndAttach(void* context);
};
extern __declspec(thread) int g_iCB9810AllocTag;
struct BCB9810AllocTagScope
{
    int m_iSaved;

    BCB9810AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCB9810AllocTag;
        g_iCB9810AllocTag = aiAllocationTag;
    }
    ~BCB9810AllocTagScope()
    {
        g_iCB9810AllocTag = m_iSaved;
    }
};
struct BCB9810Node
{
    int unk00;
    int unk04;
    int unk08;
    BCB9810Node* m_pParentNode;
};
struct BCB9810Entry
{
    int unk00;
    int unk04;
    BCB9810Node* m_pkTreeNode;
    int unk0C;
};
class BCB9810Registry
{
  public:
    void AppendTailPair(void* pvOwner, BCB9810Node* pkNode);
    void bhkFilteredCdBodyCollector_addCdBodyPair(void* pvOwner, BCB9810Node* pkNode);

    int unk00;
    int unk04;
    BCB9810Entry* m_pkEntryArray;
    int m_iArrayLength;
};
struct CE4360Iter
{
    int* GetFirst();
    int* GetSecond();
    int* GetThird();
    int* GetFourth();
};
struct CE4360Context
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
    int m_iMode;
};
void __cdecl mapPose(CE4360Context* pkContext, int a, int b, int c, int d);
void __cdecl hkaSkeletonMapper_mapPoseLocalSpace_00ce4330(CE4360Context* pkContext, int a, int b, int c);
void __cdecl hkaSkeletonMapper_mapPose(CE4360Context* pkContext, CE4360Iter* pkFrom, CE4360Iter* pkTo, int iValue);
struct RTTI_c9b
{
    const char* m_pcName;
    RTTI_c9b* m_pBaseRTTI;
};
extern unsigned char DAT_011f4428;
class GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_012043f8;
extern float DAT_01267e30;
struct S
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void SetMode(int iMode);
    void bhkRigidBody_SetLinearVelocity_00561690(int);
    void bhkRigidBody_SetAngularVelocity_005617c0(float* pf);
};
struct Cast_c9b
{
    char pad[0x10];
    S* m_10;
};
struct Ctrl_c9b
{
    Cast_c9b* FUN_00653290(GlobalObjectO2_00a7b610* pkType);
};
class Obj_c9b
{
  public:
    virtual void v00();
    virtual void v01();
    virtual RTTI_c9b* GetRTTI();
    char padCur[0x1c - 4];
    Ctrl_c9b* m_1c;
    char kad[0xa0 - 0x20];
    Obj_c9b** m_ppChildren;
    unsigned short m_usMax;
    unsigned short m_usElementCount;
};
void __cdecl ApplyCollisionEffect(Obj_c9b* pkObj, float f);
__forceinline bool IsNode_c9b(Obj_c9b* pkObj)
{
    RTTI_c9b* pkRTTI = pkObj->GetRTTI();
    while (pkRTTI)
    {
        if (pkRTTI == (RTTI_c9b*)&DAT_011f4428)
            return true;
        pkRTTI = pkRTTI->m_pBaseRTTI;
    }
    return false;
}
void __cdecl bhkBlendController_DoGetUp(Obj_c9b* pkObj, float f);
void __stdcall BSSimpleArray_bhkUtilFunctions_AVLevel_1024_CopyItems(char* dst, char* src, unsigned int count);
class FUN_00c7f970_cls
{
  public:
    virtual void vfn_0();
    virtual char* Alloc(unsigned int n);
    virtual void Free(char* p);
    virtual char* Realloc(char* p, unsigned int n);

    char* m_pData;
    void* unk;
    unsigned int m_uiSize;
    void BSSimpleArray_bhkUtilFunctions_AVLevel_1024_ReallocateBuffer(unsigned int uiNew, unsigned int uiOld);
};

#include <xmmintrin.h>
#include "../../../include/MemoryManager.h"
#include "../../../include/bhkRagdollController.h"
int __cdecl FUN_00458620(int value, int extra);

struct __declspec(align(16)) ScratchVec
{
    __m128 m_vComponents;
    ScratchVec();
};

struct QueryOwner
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
    virtual int vfn_d4(ScratchVec* out);

    int bhkRigidBody_GetPosition(int param);
};

// @fnv 0x00560bc0
// src: XBOX_PDB 0x00560bc0
int QueryOwner::bhkRigidBody_GetPosition(int param)
{
    ScratchVec v;
    return FUN_00458620(param, vfn_d4(&v));
}

class NiPoint3T8
{
  public:
    NiPoint3T8();
    NiPoint3T8 operator+(const NiPoint3T8& kPt) const;
    NiPoint3T8 operator-(const NiPoint3T8& kPt) const;
    NiPoint3T8 operator*(float fScale) const;
    NiPoint3T8& operator*=(float fScale);
    void Unitize();
    float x;
    float y;
    float z;
};
extern NiPoint3T8 g_kUnitZT8;

class hkSimdRealT8
{
  public:
    hkSimdRealT8(float fValue);
    __m128 m_vValue;
};

class hkVector4T8
{
  public:
    hkVector4T8();
    void SetFrom(const void* pvSource);
    void Sub(const hkVector4T8& kOther);
    hkVector4T8 Copy() const;
    float Length3() const;
    float& operator()(int i);
    void Normalize3();
    void AddMul4(const hkSimdRealT8& kScale, const hkVector4T8& kWorldPosition);
    __m128 m_vComponents;
};
void __cdecl NI2HK(hkVector4T8& kOut, const NiPoint3T8& kIn);
NiPoint3T8& __cdecl FUN_00458620(NiPoint3T8& kOut, const hkVector4T8& kIn);
hkVector4T8 __cdecl Object_ProcessAndReturnValue_00891060(const hkVector4T8& kVec, const hkSimdRealT8& kScale);
float __cdecl NI2HK_004a3e90(float fValue);
float __cdecl BSMIN(float fA, float fB);

class ScriptVarsT8
{
  public:
    char GetVariable(const char* pcName, unsigned int* puiIndex);
};

class LocalsT8
{
  public:
    double GetVar(unsigned int uiIndex, int iUnused);
    void SetVar(unsigned int uiIndex, double dValue);
};

class ScriptHostT8
{
  public:
    ScriptVarsT8* GetScriptVars();
    LocalsT8* GetLocals();
};

class GlobalT8
{
  public:
    float GetValue();
};
extern GlobalT8 g_kTrapMultT8;

class ShapeT8;
class ObjT8
{
  public:
    ObjT8* GetObj();
    const void* GetPos();
    int GetFlagsValue();
};

class HitSubT8
{
  public:
    class RefT8* GetReferenceWrapper();
    ObjT8* GetObj();
};

class HitT8
{
  public:
    int m_iUnused;
    HitSubT8 m_kSub;
};

class TrapFlagsT8
{
  public:
    TrapFlagsT8(int iValue);
    int GetType();
    int m_iValue;
};

class BodyT8
{
  public:
    const void* GetLinearVelocityVector();
    const void* GetNavMeshData();
};
BodyT8* __cdecl hkpGetRigidBody(ObjT8* pkObj);
int __cdecl bhkEntity_Getbhk(BodyT8* pkBody);

class WeapT8
{
  public:
    bool IsStatic();
    const void* GetPos();
    const void* GetDir();
    int GetFormType();
    void Finish(int iValue);
};

class ProjT8
{
  public:
    const void* GetSourceVelocity();
    void ApplyImpulse(const NiPoint3T8& kImpulse, float fScale);
};

class NodeT8
{
  public:
    const NiPoint3T8& GetWorldTranslate();
};

class ImpulseT8
{
  public:
    ImpulseT8();
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0c;
    int m_i10;
    int m_aiPad[9];
    NiPoint3T8 m_kFrom;
    NiPoint3T8 m_kTo;
    __m128 m_kPad;
};

class EventT8
{
  public:
    EventT8();
    NiPoint3T8 m_kPos;
    float m_fAngleZ;
    float m_fScale;
    unsigned char m_ucType;
    unsigned char m_ucForm;
    void* m_pvTarget;
    int m_i1c;
    int m_iFirstValue;
};
void __cdecl ImpactMixer_PlayCollisionSound(EventT8* pkEvent);
void __cdecl bhkWorld_SetMotion(void* pvTarget, int iMode, int iA, int iB, int iC);
void __cdecl bhkForceController_RemoveForce(void* pvTarget);
void __cdecl SetCollisionScale(void* pvNode, hkVector4T8* pkVelocity, float fScale, int iFlags);

class AVOwnerT8
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual float GetActorValue(int iAV);
};

class RefT8
{
  public:
    virtual void r000();
    virtual void r001();
    virtual void r002();
    virtual void r003();
    virtual void r004();
    virtual void r005();
    virtual void r006();
    virtual void r007();
    virtual void r008();
    virtual void r009();
    virtual void r00a();
    virtual void r00b();
    virtual void r00c();
    virtual void r00d();
    virtual void r00e();
    virtual void r00f();
    virtual void r010();
    virtual void r011();
    virtual void r012();
    virtual void r013();
    virtual void r014();
    virtual void r015();
    virtual void r016();
    virtual void r017();
    virtual void r018();
    virtual void r019();
    virtual void r01a();
    virtual void r01b();
    virtual void r01c();
    virtual void r01d();
    virtual void r01e();
    virtual void r01f();
    virtual void r020();
    virtual void r021();
    virtual void r022();
    virtual void r023();
    virtual void r024();
    virtual void r025();
    virtual void r026();
    virtual void r027();
    virtual void r028();
    virtual void r029();
    virtual void r02a();
    virtual void r02b();
    virtual void r02c();
    virtual void r02d();
    virtual void r02e();
    virtual void r02f();
    virtual void r030();
    virtual void r031();
    virtual void r032();
    virtual void r033();
    virtual void r034();
    virtual void r035();
    virtual void r036();
    virtual void r037();
    virtual void r038();
    virtual void r039();
    virtual void r03a();
    virtual void r03b();
    virtual void r03c();
    virtual void r03d();
    virtual void r03e();
    virtual void r03f();
    virtual void r040();
    virtual void r041();
    virtual void r042();
    virtual void r043();
    virtual void r044();
    virtual void r045();
    virtual void r046();
    virtual void r047();
    virtual void r048();
    virtual void r049();
    virtual void r04a();
    virtual void r04b();
    virtual void r04c();
    virtual void r04d();
    virtual void r04e();
    virtual void r04f();
    virtual void r050();
    virtual void r051();
    virtual void r052();
    virtual void r053();
    virtual void r054();
    virtual void r055();
    virtual void r056();
    virtual void r057();
    virtual void r058();
    virtual void r059();
    virtual void r05a();
    virtual void r05b();
    virtual void r05c();
    virtual void r05d();
    virtual void r05e();
    virtual void r05f();
    virtual void r060();
    virtual void r061();
    virtual void r062();
    virtual void r063();
    virtual void r064();
    virtual void r065();
    virtual void r066();
    virtual void r067();
    virtual void r068();
    virtual void r069();
    virtual void r06a();
    virtual void r06b();
    virtual void r06c();
    virtual void r06d();
    virtual void r06e();
    virtual void r06f();
    virtual void r070();
    virtual void r071();
    virtual void r072();
    virtual void r073();
    virtual NodeT8* Get3D();
    virtual void r075();
    virtual void r076();
    virtual void r077();
    virtual void r078();
    virtual void r079();
    virtual void r07a();
    virtual void r07b();
    virtual void r07c();
    virtual const NiPoint3T8* GetPos();
    virtual void r07e();
    virtual void r07f();
    virtual void r080();
    virtual void r081();
    virtual void r082();
    virtual void r083();
    virtual void r084();
    virtual void r085();
    virtual void r086();
    virtual void r087();
    virtual void r088();
    virtual void r089();
    virtual void r08a();
    virtual bool IsDead(int iValue);
    virtual void r08c();
    virtual void r08d();
    virtual void r08e();
    virtual void r08f();
    virtual void r090();
    virtual void r091();
    virtual void r092();
    virtual void r093();
    virtual void r094();
    virtual void r095();
    virtual void r096();
    virtual void r097();
    virtual void r098();
    virtual void r099();
    virtual void r09a();
    virtual void r09b();
    virtual void r09c();
    virtual void r09d();
    virtual void r09e();
    virtual void r09f();
    virtual void r0a0();
    virtual void r0a1();
    virtual void r0a2();
    virtual void r0a3();
    virtual void r0a4();
    virtual void r0a5();
    virtual void r0a6();
    virtual void r0a7();
    virtual void r0a8();
    virtual void r0a9();
    virtual void r0aa();
    virtual void r0ab();
    virtual void r0ac();
    virtual void r0ad();
    virtual void r0ae();
    virtual void r0af();
    virtual void r0b0();
    virtual void r0b1();
    virtual void r0b2();
    virtual void r0b3();
    virtual void r0b4();
    virtual void r0b5();
    virtual void r0b6();
    virtual void r0b7();
    virtual void r0b8();
    virtual void r0b9();
    virtual void r0ba();
    virtual void r0bb();
    virtual void r0bc();
    virtual void r0bd();
    virtual void r0be();
    virtual void r0bf();
    virtual void r0c0();
    virtual void r0c1();
    virtual void r0c2();
    virtual void r0c3();
    virtual void r0c4();
    virtual void r0c5();
    virtual void r0c6();
    virtual void r0c7();
    virtual void r0c8();
    virtual void r0c9();
    virtual void r0ca();
    virtual void r0cb();
    virtual void r0cc();
    virtual void r0cd();
    virtual void DamageHealth(float afDamageAmount, float fUnused, int iFlags);
    ScriptHostT8* GetHost();
    unsigned short GetLevel();
    ProjT8* GetProjectileData();
    float GetHeight();
    void ApplyHit(float fForce, ImpulseT8* pkImpulse);
    void UpdateHit(int iA, int iB);
    RefT8* GetPlayerTarget();
    char m_acPad[0xa4 - 4];
    AVOwnerT8 m_kAVOwner;
    void Actor_DoTrap(HitT8* pkHit, WeapT8* pkWeap);
};
extern RefT8* g_pkPlayerT8;
extern const double g_dMaxDeathPushBackT8;

// @fnv 0x00890610
// src: XBOX_PDB 0x00890610
void RefT8::Actor_DoTrap(HitT8* pkHit, WeapT8* pkWeap)
{
    float afDamageAmount = 0.0f;
    float fPushBack = 0.0f;
    float fDeathPushBack = 0.0f;
    float fMinVelocity = 0.0f;
    bool bContinuous = false;
    float fVelocityMult = 1.0f;
    RefT8* pkAttacker = pkHit->m_kSub.GetReferenceWrapper();
    ScriptHostT8* pkHost = pkAttacker->GetHost();
    ScriptVarsT8* pkVars = pkHost->GetScriptVars();
    if (this == g_pkPlayerT8 && pkAttacker && pkAttacker == g_pkPlayerT8->GetPlayerTarget())
        return;
    if (pkVars)
    {
        LocalsT8* pkLocals = pkHost->GetLocals();
        if (pkLocals)
        {
            unsigned int uiDamage;
            if (pkVars->GetVariable("fTrapDamage", &uiDamage))
                afDamageAmount = pkLocals->GetVar(uiDamage, 0);
            unsigned int uiLevelled;
            if (pkVars->GetVariable("fLevelledDamage", &uiLevelled))
                afDamageAmount += GetLevel() * (float)pkLocals->GetVar(uiLevelled, 0);
            unsigned int uiPushBack;
            if (pkVars->GetVariable("fTrapPushBack", &uiPushBack))
                fPushBack = pkLocals->GetVar(uiPushBack, 0);
            unsigned int uiMinVelocity;
            if (pkVars->GetVariable("fTrapMinVelocity", &uiMinVelocity))
            {
                fMinVelocity = pkLocals->GetVar(uiMinVelocity, 0);
                if (fMinVelocity < 0.0)
                    fMinVelocity = 0.0f;
                else
                    fMinVelocity = NI2HK_004a3e90(fMinVelocity);
            }
            unsigned int uiContinuous;
            if (pkVars->GetVariable("bTrapContinuous", &uiContinuous))
                bContinuous = pkLocals->GetVar(uiContinuous, 0) != 0.0;
            unsigned int uiDeathPushBack;
            if (pkVars->GetVariable("fTrapDeathPushBack", &uiDeathPushBack))
                fDeathPushBack = pkLocals->GetVar(uiDeathPushBack, 0);
            else
                fDeathPushBack = fPushBack / 10.0;
        }
    }
    if (bContinuous || !pkWeap->IsStatic())
    {
        ProjT8* pkProj = GetProjectileData();
        BodyT8* pkBody = hkpGetRigidBody(pkHit->m_kSub.GetObj());
        hkVector4T8 kMotionVelocity;
        hkVector4T8 kSource;
        if (pkBody)
        {
            if (!pkWeap->IsStatic())
            {
                kMotionVelocity.SetFrom(pkWeap->GetPos());
                kSource.SetFrom(pkWeap->GetDir());
            }
            else
            {
                kMotionVelocity.SetFrom(pkBody->GetLinearVelocityVector());
                kSource.SetFrom(pkBody->GetNavMeshData());
            }
            hkVector4T8 kProjVel;
            if (fMinVelocity == 0.0 || kMotionVelocity.Copy().Length3() >= fMinVelocity)
            {
                if (pkProj)
                {
                    kProjVel.SetFrom(pkProj->GetSourceVelocity());
                    kProjVel.Sub(kMotionVelocity);
                    float fMin = fMinVelocity != 0.0 ? fMinVelocity : 10.0f;
                    fVelocityMult = kProjVel.Copy().Length3() / fMin;
                    if (fVelocityMult > 2.0)
                        fVelocityMult = 2.0f;
                }
            }
            else
            {
                afDamageAmount = 0.0f;
            }
        }
        else
        {
            if (!pkWeap->IsStatic())
            {
                kSource.SetFrom(pkWeap->GetDir());
            }
            else
            {
                ObjT8* pkObj = pkHit->m_kSub.GetObj()->GetObj();
                kSource.SetFrom(pkObj->GetPos());
            }
            NI2HK(kMotionVelocity, *GetPos());
            kMotionVelocity.Sub(kSource);
            float& rfZ = kMotionVelocity(2);
            rfZ += NI2HK_004a3e90(GetHeight() / 2.0);
        }
        bool bWasAlive = !IsDead(0);
        TrapFlagsT8 kFlags(pkHit->m_kSub.GetObj()->GetFlagsValue());
        if (kFlags.GetType() == 0x10)
        {
            float fResist = m_kAVOwner.GetActorValue(0x13) / 100.0;
            fResist = 1.0f - BSMIN(fResist, 1.0f);
            afDamageAmount *= fResist;
        }
        else
        {
            float fResist = 0.0f;
            fResist = 1.0f - BSMIN(fResist, 1.0f);
            afDamageAmount *= fResist;
        }
        if (afDamageAmount > 0.0)
        {
            if (bContinuous)
                afDamageAmount *= g_kTrapMultT8.GetValue() * fVelocityMult;
            DamageHealth(afDamageAmount, 0.0f, 0);
            NiPoint3T8 kTargetCenter = Get3D()->GetWorldTranslate() + g_kUnitZT8 * (GetHeight() * 0.5);
            NiPoint3T8 kWorldPosition;
            FUN_00458620(kWorldPosition, kSource);
            if (kFlags.GetType() != 0x10)
            {
                ImpulseT8 kImpulse;
                kImpulse.m_i08 = 0;
                kImpulse.m_kFrom = kTargetCenter;
                kImpulse.m_kTo = kTargetCenter - kWorldPosition;
                kImpulse.m_i00 = 0;
                kImpulse.m_i10 = -1;
                ApplyHit(afDamageAmount * 2.0, &kImpulse);
                if (!bContinuous && pkBody && pkWeap->GetFormType() != 0x24)
                {
                    NiPoint3T8 kPos = FUN_00458620(kPos, kSource);
                    int iOffset = bhkEntity_Getbhk(pkBody);
                    EventT8 kEvent;
                    kEvent.m_fScale = 0.5f;
                    kEvent.m_i1c = 0;
                    kEvent.m_iFirstValue = iOffset;
                    kEvent.m_ucType = 0x24;
                    kEvent.m_ucForm = pkWeap->GetFormType();
                    kEvent.m_kPos = kPos;
                    kEvent.m_fAngleZ = Object_ProcessAndReturnValue_00891060(kMotionVelocity.Copy(), hkSimdRealT8(3.0f)).Length3();
                    kEvent.m_pvTarget = (char*)this + iOffset;
                    ImpactMixer_PlayCollisionSound(&kEvent);
                }
            }
            UpdateHit(1, 1);
            bool bKilled = bWasAlive && IsDead(0);
            if (fPushBack > 0.0)
            {
                if (fDeathPushBack > g_dMaxDeathPushBackT8)
                    fDeathPushBack = 200.0f;
                if (bKilled && this != g_pkPlayerT8)
                {
                    bhkWorld_SetMotion(Get3D(), 1, 1, 0, 1);
                    bhkForceController_RemoveForce(Get3D());
                    kMotionVelocity.Normalize3();
                    hkSimdRealT8 kScale(1024.0f);
                    kSource.AddMul4(kScale, kMotionVelocity);
                    SetCollisionScale(Get3D(), &kSource, fDeathPushBack, 0);
                }
                else if (pkProj)
                {
                    if (fPushBack > 1000.0)
                        fPushBack = 1000.0f;
                    if (bContinuous)
                        fPushBack *= g_kTrapMultT8.GetValue() * fVelocityMult;
                    ObjT8* pkObj = pkHit->m_kSub.GetObj();
                    if (pkObj)
                    {
                        NiPoint3T8 kImpulse;
                        FUN_00458620(kImpulse, kMotionVelocity);
                        kImpulse.Unitize();
                        kImpulse *= fPushBack;
                        pkProj->ApplyImpulse(kImpulse, 0.5f);
                    }
                }
            }
            if (pkVars)
            {
                LocalsT8* pkLocals = pkHost->GetLocals();
                if (pkLocals)
                {
                    unsigned int uiHasHit;
                    if (pkVars->GetVariable("bTrapHasHit", &uiHasHit))
                        pkLocals->SetVar(uiHasHit, 1.0);
                }
            }
        }
        pkWeap->Finish(1);
    }
}

struct ImpactPoint
{
    float x, y, z;
    ImpactPoint();
    ImpactPoint operator-(const ImpactPoint&) const;
    ImpactPoint operator*(float) const;
    void Normalize();
};
// FUN_008a4af0 v04 - pack types used directly; shells only for callees the pack does not declare
struct GhostH
{
    bool GetGhost();
};
struct SettingString
{
    const char* GetString();
};
extern SettingString DAT_011cc83c;
NiAVObject* __cdecl BSUtilities_GetObjectByName(NiAVObject* a, NiFixedString* b);
struct GetterObj
{
    float FUN_00450410();
};
extern GetterObj DAT_011cc77c;
extern GetterObj DAT_011cc86c;
extern GetterObj DAT_011cc860;
extern GetterObj DAT_011cc7dc;
extern Actor* DAT_011dea3c;
struct NormObj
{
    void Unitize_004a0c10();
};
struct NodeObj
{
    struct ImpactPositionView_00461130;
    ImpactPositionView_00461130 NiAVObject_GetWorldRotate(int arg);
};
// 0x00461130 returns three float coordinates (12 bytes); shared Pair is an 8-byte integer/reference pair.
struct NodeObj::ImpactPositionView_00461130
{
    float x, y, z;
    ImpactPoint* ComputeValue_00524c40();
};
struct ParamObj
{
    virtual void z000();
    virtual void z001();
    virtual void z002();
    virtual void z003();
    virtual void z004();
    virtual void z005();
    virtual void z006();
    virtual void z007();
    virtual void z008();
    virtual void z009();
    virtual void z010();
    virtual void z011();
    virtual void z012();
    virtual void z013();
    virtual void z014();
    virtual void z015();
    virtual void z016();
    virtual void z017();
    virtual void z018();
    virtual void z019();
    virtual void z020();
    virtual void z021();
    virtual void z022();
    virtual void z023();
    virtual void z024();
    virtual void z025();
    virtual void z026();
    virtual void z027();
    virtual void z028();
    virtual void z029();
    virtual void z030();
    virtual void z031();
    virtual void z032();
    virtual void z033();
    virtual void z034();
    virtual void z035();
    virtual void z036();
    virtual void z037();
    virtual void z038();
    virtual void z039();
    virtual void z040();
    virtual void z041();
    virtual void z042();
    virtual void z043();
    virtual void z044();
    virtual void z045();
    virtual void z046();
    virtual void z047();
    virtual void z048();
    virtual void z049();
    virtual void z050();
    virtual void z051();
    virtual void z052();
    virtual void z053();
    virtual void z054();
    virtual void z055();
    virtual void z056();
    virtual void z057();
    virtual void z058();
    virtual void z059();
    virtual void z060();
    virtual void z061();
    virtual void z062();
    virtual void z063();
    virtual void z064();
    virtual void z065();
    virtual void z066();
    virtual void z067();
    virtual void z068();
    virtual void z069();
    virtual void z070();
    virtual void z071();
    virtual void z072();
    virtual void z073();
    virtual void z074();
    virtual void z075();
    virtual void z076();
    virtual void z077();
    virtual void z078();
    virtual void z079();
    virtual void z080();
    virtual void z081();
    virtual void z082();
    virtual void z083();
    virtual void z084();
    virtual void z085();
    virtual void z086();
    virtual void z087();
    virtual void z088();
    virtual void z089();
    virtual void z090();
    virtual void z091();
    virtual void z092();
    virtual void z093();
    virtual void z094();
    virtual void z095();
    virtual void z096();
    virtual void z097();
    virtual void z098();
    virtual void z099();
    virtual void z100();
    virtual void z101();
    virtual void z102();
    virtual void z103();
    virtual void z104();
    virtual void z105();
    virtual void z106();
    virtual void z107();
    virtual void z108();
    virtual void z109();
    virtual void z110();
    virtual void z111();
    virtual void z112();
    virtual void z113();
    virtual void z114();
    virtual void z115();
    virtual void* GetNode116();
    virtual void q117();
    virtual void q118();
    virtual void q119();
    virtual void q120();
    virtual void q121();
    virtual void q122();
    virtual void q123();
    virtual void q124();
    virtual void q125();
    virtual void q126();
    virtual void q127();
    virtual void q128();
    virtual void q129();
    virtual void q130();
    virtual void q131();
    virtual void q132();
    virtual void q133();
    virtual void q134();
    virtual void q135();
    virtual void q136();
    virtual void q137();
    virtual void q138();
    virtual void q139();
    virtual void q140();
    virtual void q141();
    virtual void q142();
    virtual void q143();
    virtual void q144();
    virtual void q145();
    virtual void q146();
    virtual void q147();
    virtual void q148();
    virtual void q149();
    virtual void q150();
    virtual void q151();
    virtual void q152();
    virtual void q153();
    virtual void q154();
    virtual void q155();
    virtual void q156();
    virtual void q157();
    virtual void q158();
    virtual void q159();
    virtual void q160();
    virtual void q161();
    virtual void q162();
    virtual void q163();
    virtual void q164();
    virtual void q165();
    virtual void q166();
    virtual void q167();
    virtual void q168();
    virtual void q169();
    virtual void q170();
    virtual void q171();
    virtual void q172();
    virtual void q173();
    virtual void q174();
    virtual void q175();
    virtual void q176();
    virtual void q177();
    virtual void q178();
    virtual void q179();
    virtual void q180();
    virtual void q181();
    virtual void q182();
    virtual void q183();
    virtual void q184();
    virtual void q185();
    virtual void q186();
    virtual void q187();
    virtual void q188();
    virtual void q189();
    virtual void q190();
    virtual void q191();
    virtual void q192();
    virtual void q193();
    virtual void q194();
    virtual void q195();
    virtual void q196();
    virtual void q197();
    virtual void q198();
    virtual void q199();
    virtual void q200();
    virtual void q201();
    virtual void q202();
    virtual void q203();
    virtual void q204();
    virtual void q205();
    virtual void q206();
    virtual void q207();
    virtual void q208();
    virtual void q209();
    virtual void q210();
    virtual void q211();
    virtual void q212();
    virtual void q213();
    virtual void q214();
    virtual void q215();
    virtual bool IsSpecial();
};
struct SubObjSrc
{
    void* FUN_009306d0();
};
struct Sub410
{
    bool bhkCharacterListener_QQuadruped();
};
void __cdecl bhkBlendController_DoHit(void* mgr, float z, bool flag);
struct GlobalCount
{
    int FUN_004503f0();
};
extern GlobalCount DAT_011df838;

extern SettingString DAT_011cc8cc;
struct __declspec(align(16)) ImpactVector
{
    __m128 value;
    ImpactVector();
};
struct ImpactQuery
{
    float x, y, z, radius;
    ImpactQuery();
    void SetPoint(ImpactPoint const&);
    void SetMagnitude(float);
};
struct ImpactColor
{
    float r, g, b, a;
    ImpactColor(float, float, float, float);
};
struct ImpactEffect
{
    void SetPosition(ImpactPoint const&);
};
struct ImpactEffectManager
{
    void Add(ImpactEffect*, float);
};
extern ImpactEffectManager* DAT_011dea10;
extern GetterObj DAT_011df754;
ImpactEffect* __cdecl CreateImpactEffect(ImpactPoint const&, ImpactColor const&);
void __cdecl ConvertImpact(ImpactVector*, ImpactPoint const*);
void __cdecl ConvertPoint(ImpactPoint*, ImpactPoint const*);
struct HitObject
{
    void* GetIdentity();
};
struct HitIdentity
{
    int GetIndex();
};
struct HitQueryResult
{
    void* GetIdentity();
};
HitQueryResult* __cdecl QueryImpact(void*, ImpactQuery*, int);
HitIdentity* __cdecl LookupImpact(void*);
struct HitName
{
    char const* GetName();
};
struct HitPart
{
    HitName* GetNameObject();
};
void __cdecl PrintImpact(char const*, ...);
void __cdecl ApplyImpact(void*, ImpactVector*, int);
int __cdecl ImpactSelection();
struct ImpactNode
{
    void* GetScene();
    bool IsGhost();
    bool IsActive();
    int SelectPart(void*, int);
};
struct HostShell : Actor
{
    void Actor_HitMeAlt(ParamObj* source, float strength, float secondary, int start, int end);
};
// @fnv 0x008a4af0
// src: COMMUNITY 0x008a4af0
void HostShell::Actor_HitMeAlt(ParamObj* source, float strength, float secondary, int start, int end)
{
    void* scene = ((ImpactNode*)this)->GetScene();
    if (((ImpactNode*)this)->IsGhost())
        return;
    void* manager = BSUtilities_GetObjectByName((NiAVObject*)scene, (NiFixedString*)DAT_011cc83c.GetString());
    ImpactPoint origin;
    ImpactPoint target;
    NodeObj* node = (NodeObj*)source->GetNode116();
    if (node)
    {
        origin = *node->NiAVObject_GetWorldRotate(start).ComputeValue_00524c40();
        target = *node->NiAVObject_GetWorldRotate(end).ComputeValue_00524c40();
    }
    ImpactPoint direction;
    direction = target - origin;
    direction.Normalize();
    int part = 0;
    if (manager)
    {
        if (strength > 100.0)
            strength = 100.0f;
        float difference = DAT_011cc77c.FUN_00450410() - DAT_011cc86c.FUN_00450410();
        float primary = difference * strength * 0.009999999776482582 + DAT_011cc86c.FUN_00450410();
        difference = DAT_011cc860.FUN_00450410() - DAT_011cc7dc.FUN_00450410();
        float amount = difference * secondary + DAT_011cc7dc.FUN_00450410();
        if (secondary > 75.0)
            primary = 0.0f;
        if (primary != 0.0 || amount != 0.0)
        {
            bool enabled = true;
            if (this == DAT_011dea3c)
                enabled = ((ImpactNode*)this)->IsActive();
            if (!GetHasKnockedState() && enabled)
            {
                bool special = false;
                void* sub = ((SubObjSrc*)this)->FUN_009306d0();
                if (sub)
                    special = ((Sub410*)((char*)sub + 0x410))->bhkCharacterListener_QQuadruped();
                bhkBlendController_DoHit(manager, 0.0f, special);
            }
            if (primary != 0.0)
            {
                ImpactPoint impulse = direction * primary;
                if (DAT_011df838.FUN_004503f0() > 0)
                {
                    ImpactColor color(0.0f, 0.0f, 0.0f, 0.0f);
                    if (source->IsSpecial())
                        color = ImpactColor(0.0f, 0.0f, 1.0f, 1.0f);
                    else
                        color = ImpactColor(1.0f, 0.0f, 0.0f, 1.0f);
                    ImpactEffect* effect = CreateImpactEffect(impulse * 0.1f, color);
                    effect->SetPosition(target);
                    DAT_011dea10->Add(effect, DAT_011df754.FUN_00450410());
                }
                if (enabled)
                {
                    ImpactVector worldImpulse;
                    ConvertImpact(&worldImpulse, &impulse);
                    ImpactQuery query;
                    __declspec(align(16)) ImpactPoint position;
                    ConvertPoint(&position, &target);
                    query.SetPoint(position);
                    query.SetMagnitude(30.0f);
                    HitQueryResult* result = QueryImpact(scene, &query, 0);
                    if (result)
                    {
                        HitIdentity* identity = LookupImpact(result->GetIdentity());
                        if (identity)
                            part = identity->GetIndex();
                    }
                    if (!part)
                        part = (int)BSUtilities_GetObjectByName((NiAVObject*)scene,
                                                 (NiFixedString*)((SettingString*)&DAT_011cc8cc)->GetString());
                    if (part)
                    {
                        const char* name = ((HitPart*)part)->GetNameObject()->GetName();
                        PrintImpact("Hit At %s\r\n", name);
                    }
                    ApplyImpact(manager, &worldImpulse, part);
                }
            }
            if (amount != 0.0 && enabled)
            {
                direction.x = (float)(direction.x + 1.0);
                direction.y = (float)(direction.y + 1.0);
                direction.Normalize();
                ImpactPoint impulse = direction * primary;
                ImpactVector worldImpulse;
                ConvertImpact(&worldImpulse, &impulse);
                part = ((ImpactNode*)this)->SelectPart(scene, ImpactSelection());
                ApplyImpact(manager, &worldImpulse, part);
            }
        }
    }
}

struct VectorXYZ
{
    __m128 vector;
    void hkVector4_setXYZ(const __m128*);
};
// @fnv 0x008a5110
// src: XBOX_PDB 0x008a5110
void VectorXYZ::hkVector4_setXYZ(const __m128* source)
{

    vector = _mm_shuffle_ps(*source, _mm_unpackhi_ps(*source, vector), 0xc4);
}

class NiPoint3H
{
  public:
    float x, y, z;
    NiPoint3H operator-(const NiPoint3H& kPt) const;
    NiPoint3H& operator*=(float fScalar);
    NiPoint3H& operator+=(const NiPoint3H& kPt);
    void Unitize();
};
extern const NiPoint3H g_kZeroH;

class NiMatrix3H
{
  public:
    NiPoint3H GetForward() const;
};

class hkVector4H
{
  public:
    hkVector4H();
    __m128 m_vComponents;
};

class TargetInfoH
{
  public:
    TargetInfoH(float fValue, int a, int b);
    float m_f00;
    int m_i04;
    int m_i08;
};

class BSFixedStringH
{
  public:
    const char* m_pcString;
    int m_iReferenceCount;
    int m_iHash;
};

class NiNodeRefH
{
  public:
    NiPoint3H& GetWorldTranslate();
    void* m_pkNode;
    int m_iIndex;
    int m_iFlags;
};

class NiNodeH
{
  public:
    NiNodeRefH GetObjectByName(const BSFixedStringH& kName);
};

class ProcessH
{
  public:
    virtual void vp000();
    virtual void vp004();
    virtual void vp008();
    virtual void vp00c();
    virtual void vp010();
    virtual void vp014();
    virtual void vp018();
    virtual void vp01c();
    virtual void vp020();
    virtual void vp024();
    virtual void vp028();
    virtual void vp02c();
    virtual void vp030();
    virtual void vp034();
    virtual void vp038();
    virtual void vp03c();
    virtual void vp040();
    virtual void vp044();
    virtual void vp048();
    virtual void vp04c();
    virtual void vp050();
    virtual void vp054();
    virtual void vp058();
    virtual void vp05c();
    virtual void vp060();
    virtual void vp064();
    virtual void vp068();
    virtual void vp06c();
    virtual void vp070();
    virtual void vp074();
    virtual void vp078();
    virtual void vp07c();
    virtual void vp080();
    virtual void vp084();
    virtual void vp088();
    virtual void vp08c();
    virtual void vp090();
    virtual void vp094();
    virtual void vp098();
    virtual void vp09c();
    virtual void vp0a0();
    virtual void vp0a4();
    virtual void vp0a8();
    virtual void vp0ac();
    virtual void vp0b0();
    virtual void vp0b4();
    virtual void vp0b8();
    virtual void vp0bc();
    virtual void vp0c0();
    virtual void vp0c4();
    virtual void vp0c8();
    virtual void vp0cc();
    virtual void vp0d0();
    virtual void vp0d4();
    virtual void vp0d8();
    virtual void vp0dc();
    virtual void vp0e0();
    virtual void vp0e4();
    virtual void vp0e8();
    virtual void vp0ec();
    virtual void vp0f0();
    virtual void vp0f4();
    virtual void vp0f8();
    virtual void vp0fc();
    virtual void vp100();
    virtual void vp104();
    virtual void vp108();
    virtual void vp10c();
    virtual void vp110();
    virtual void vp114();
    virtual void vp118();
    virtual void vp11c();
    virtual void vp120();
    virtual void vp124();
    virtual void vp128();
    virtual void vp12c();
    virtual void vp130();
    virtual void vp134();
    virtual void vp138();
    virtual void vp13c();
    virtual void vp140();
    virtual void vp144();
    virtual void vp148();
    virtual void vp14c();
    virtual void vp150();
    virtual void vp154();
    virtual void vp158();
    virtual void vp15c();
    virtual void vp160();
    virtual void vp164();
    virtual void vp168();
    virtual void vp16c();
    virtual void vp170();
    virtual void vp174();
    virtual void vp178();
    virtual void vp17c();
    virtual void vp180();
    virtual void vp184();
    virtual void vp188();
    virtual void vp18c();
    virtual void vp190();
    virtual void vp194();
    virtual void vp198();
    virtual void vp19c();
    virtual void vp1a0();
    virtual void vp1a4();
    virtual void vp1a8();
    virtual void vp1ac();
    virtual void vp1b0();
    virtual void vp1b4();
    virtual void vp1b8();
    virtual void vp1bc();
    virtual void vp1c0();
    virtual void vp1c4();
    virtual void vp1c8();
    virtual void vp1cc();
    virtual void vp1d0();
    virtual void vp1d4();
    virtual void vp1d8();
    virtual void vp1dc();
    virtual void vp1e0();
    virtual void vp1e4();
    virtual void vp1e8();
    virtual void vp1ec();
    virtual void vp1f0();
    virtual void vp1f4();
    virtual void vp1f8();
    virtual void vp1fc();
    virtual void vp200();
    virtual void vp204();
    virtual void vp208();
    virtual void vp20c();
    virtual void vp210();
    virtual void vp214();
    virtual void vp218();
    virtual void vp21c();
    virtual void vp220();
    virtual void vp224();
    virtual void vp228();
    virtual void vp22c();
    virtual void vp230();
    virtual void vp234();
    virtual void vp238();
    virtual void vp23c();
    virtual void vp240();
    virtual void vp244();
    virtual void vp248();
    virtual void vp24c();
    virtual void vp250();
    virtual void vp254();
    virtual void vp258();
    virtual void vp25c();
    virtual void vp260();
    virtual void vp264();
    virtual void vp268();
    virtual void vp26c();
    virtual void vp270();
    virtual void vp274();
    virtual void vp278();
    virtual void vp27c();
    virtual void vp280();
    virtual void vp284();
    virtual void vp288();
    virtual void vp28c();
    virtual void vp290();
    virtual void vp294();
    virtual void vp298();
    virtual void vp29c();
    virtual void vp2a0();
    virtual void vp2a4();
    virtual void vp2a8();
    virtual void vp2ac();
    virtual void vp2b0();
    virtual void vp2b4();
    virtual void vp2b8();
    virtual void vp2bc();
    virtual void vp2c0();
    virtual void vp2c4();
    virtual void vp2c8();
    virtual void vp2cc();
    virtual void vp2d0();
    virtual void vp2d4();
    virtual void vp2d8();
    virtual void vp2dc();
    virtual void vp2e0();
    virtual void vp2e4();
    virtual void vp2e8();
    virtual void vp2ec();
    virtual void vp2f0();
    virtual void vp2f4();
    virtual void vp2f8();
    virtual void vp2fc();
    virtual void vp300();
    virtual void vp304();
    virtual void vp308();
    virtual void vp30c();
    virtual void vp310();
    virtual void vp314();
    virtual void vp318();
    virtual void vp31c();
    virtual void vp320();
    virtual void vp324();
    virtual void vp328();
    virtual void vp32c();
    virtual void vp330();
    virtual void vp334();
    virtual void vp338();
    virtual void vp33c();
    virtual void vp340();
    virtual void vp344();
    virtual void vp348();
    virtual void vp34c();
    virtual void vp350();
    virtual void vp354();
    virtual void vp358();
    virtual void vp35c();
    virtual void vp360();
    virtual void vp364();
    virtual void vp368();
    virtual void vp36c();
    virtual void vp370();
    virtual void vp374();
    virtual void vp378();
    virtual void vp37c();
    virtual void vp380();
    virtual void vp384();
    virtual void vp388();
    virtual void vp38c();
    virtual void vp390();
    virtual void vp394();
    virtual void vp398();
    virtual void vp39c();
    virtual void vp3a0();
    virtual void vp3a4();
    virtual void vp3a8();
    virtual void vp3ac();
    virtual void vp3b0();
    virtual void vp3b4();
    virtual void vp3b8();
    virtual void vp3bc();
    virtual void vp3c0();
    virtual void vp3c4();
    virtual void vp3c8();
    virtual void vp3cc();
    virtual void vp3d0();
    virtual void vp3d4();
    virtual void vp3d8();
    virtual void vp3dc();
    virtual void vp3e0();
    virtual void vp3e4();
    virtual void vp3e8();
    virtual void vp3ec();
    virtual void vp3f0();
    virtual void vp3f4();
    virtual void vp3f8();
    virtual void vp3fc();
    virtual void vp400();
    virtual void vp404();
    virtual void vp408();
    virtual void vp40c();
    virtual void vp410();
    virtual void vp414();
    virtual void vp418();
    virtual void vp41c();
    virtual void vp420();
    virtual void vp424();
    virtual void vp428();
    virtual void vp42c();
    virtual void vp430();
    virtual void vp434();
    virtual void vp438();
    virtual void vp43c();
    virtual void vp440();
    virtual void vp444();
    virtual void vp448();
    virtual void vp44c();
    virtual void vp450();
    virtual void vp454();
    virtual void vp458();
    virtual void vp45c();
    virtual const BSFixedStringH& GetWeaponNodeName();
};

class WeaponH
{
  public:
    float GetImpulseScale();
    float GetImpulseRange();
};

class HavokObjectH
{
  public:
    const NiPoint3H& GetPosition();
    void SetTargetInfo(TargetInfoH* pkInfo);
};

class TESObjectREFRH
{
  public:
    virtual void vr000();
    virtual void vr004();
    virtual void vr008();
    virtual void vr00c();
    virtual void vr010();
    virtual void vr014();
    virtual void vr018();
    virtual void vr01c();
    virtual void vr020();
    virtual void vr024();
    virtual void vr028();
    virtual void vr02c();
    virtual void vr030();
    virtual void vr034();
    virtual void vr038();
    virtual void vr03c();
    virtual void vr040();
    virtual void vr044();
    virtual void vr048();
    virtual void vr04c();
    virtual void vr050();
    virtual void vr054();
    virtual void vr058();
    virtual void vr05c();
    virtual void vr060();
    virtual void vr064();
    virtual void vr068();
    virtual void vr06c();
    virtual void vr070();
    virtual void vr074();
    virtual void vr078();
    virtual void vr07c();
    virtual void vr080();
    virtual void vr084();
    virtual void vr088();
    virtual void vr08c();
    virtual void vr090();
    virtual void vr094();
    virtual void vr098();
    virtual void vr09c();
    virtual void vr0a0();
    virtual void vr0a4();
    virtual void vr0a8();
    virtual void vr0ac();
    virtual void vr0b0();
    virtual void vr0b4();
    virtual void vr0b8();
    virtual void vr0bc();
    virtual void vr0c0();
    virtual void vr0c4();
    virtual void vr0c8();
    virtual void vr0cc();
    virtual void vr0d0();
    virtual void vr0d4();
    virtual void vr0d8();
    virtual void vr0dc();
    virtual void vr0e0();
    virtual void vr0e4();
    virtual void vr0e8();
    virtual void vr0ec();
    virtual void vr0f0();
    virtual void vr0f4();
    virtual void vr0f8();
    virtual void vr0fc();
    virtual void vr100();
    virtual void vr104();
    virtual void vr108();
    virtual void vr10c();
    virtual void vr110();
    virtual void vr114();
    virtual void vr118();
    virtual void vr11c();
    virtual void vr120();
    virtual void vr124();
    virtual void vr128();
    virtual void vr12c();
    virtual void vr130();
    virtual void vr134();
    virtual void vr138();
    virtual void vr13c();
    virtual void vr140();
    virtual void vr144();
    virtual void vr148();
    virtual void vr14c();
    virtual void vr150();
    virtual void vr154();
    virtual void vr158();
    virtual void vr15c();
    virtual void vr160();
    virtual void vr164();
    virtual void vr168();
    virtual void vr16c();
    virtual void vr170();
    virtual void vr174();
    virtual void vr178();
    virtual void vr17c();
    virtual void vr180();
    virtual void vr184();
    virtual void vr188();
    virtual void vr18c();
    virtual void vr190();
    virtual void vr194();
    virtual void vr198();
    virtual void vr19c();
    virtual void vr1a0();
    virtual void vr1a4();
    virtual void vr1a8();
    virtual void vr1ac();
    virtual void vr1b0();
    virtual void vr1b4();
    virtual void vr1b8();
    virtual void vr1bc();
    virtual void vr1c0();
    virtual void vr1c4();
    virtual void vr1c8();
    virtual void vr1cc();
    virtual void vr1d0();
    virtual void vr1d4();
    virtual void vr1d8();
    virtual void vr1dc();
    virtual void vr1e0();
    virtual void vr1e4();
    virtual void vr1e8();
    virtual void vr1ec();
    virtual void vr1f0();
    virtual void vr1f4();
    virtual void vr1f8();
    virtual void vr1fc();
    virtual void vr200();
    virtual void vr204();
    virtual void vr208();
    virtual void vr20c();
    virtual void vr210();
    virtual void vr214();
    virtual void vr218();
    virtual bool IsDead();
    virtual void vr220();
    virtual bool IsActor();
    virtual void vs228();
    virtual void vs22c();
    virtual void vs230();
    virtual void vs234();
    virtual void vs238();
    virtual void vs23c();
    virtual void vs240();
    virtual void vs244();
    virtual void vs248();
    virtual void vs24c();
    virtual void vs250();
    virtual void vs254();
    virtual void vs258();
    virtual void vs25c();
    virtual void vs260();
    virtual void vs264();
    virtual void vs268();
    virtual void vs26c();
    virtual void vs270();
    virtual void vs274();
    virtual void vs278();
    virtual void vs27c();
    virtual void vs280();
    virtual void vs284();
    virtual void vs288();
    virtual void vs28c();
    virtual void vs290();
    virtual void vs294();
    virtual void vs298();
    virtual void vs29c();
    virtual void vs2a0();
    virtual void vs2a4();
    virtual void vs2a8();
    virtual void vs2ac();
    virtual void vs2b0();
    virtual void vs2b4();
    virtual void vs2b8();
    virtual void vs2bc();
    virtual void vs2c0();
    virtual void vs2c4();
    virtual void vs2c8();
    virtual void vs2cc();
    virtual void vs2d0();
    virtual void vs2d4();
    virtual void vs2d8();
    virtual void vs2dc();
    virtual void vs2e0();
    virtual void vs2e4();
    virtual void vs2e8();
    virtual void vs2ec();
    virtual void vs2f0();
    virtual void vs2f4();
    virtual void vs2f8();
    virtual void vs2fc();
    virtual void vs300();
    virtual void vs304();
    virtual void vs308();
    virtual void vs30c();
    virtual void vs310();
    virtual void vs314();
    virtual void vs318();
    virtual void vs31c();
    virtual void vs320();
    virtual void vs324();
    virtual void vs328();
    virtual void vs32c();
    virtual void vs330();
    virtual void vs334();
    virtual void vs338();
    virtual void vs33c();
    virtual void vs340();
    virtual void vs344();
    virtual void vs348();
    virtual void vs34c();
    virtual void vs350();
    virtual void vs354();
    virtual void vs358();
    virtual void vs35c();
    virtual void vs360();
    virtual void vs364();
    virtual void vs368();
    virtual void vs36c();
    virtual void vs370();
    virtual void vs374();
    virtual void vs378();
    virtual void vs37c();
    virtual void vs380();
    virtual void vs384();
    virtual void vs388();
    virtual bool IsRagdollable();
    HavokObjectH* GetHavokObject();
};

class HitDataH
{
  public:
    int unk00;
    TESObjectREFRH* m_pkTarget;
    TESObjectREFRH* m_pkSource;
    int unk0c;
    int unk10;
    float m_fForce;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    WeaponH* m_pkWeapon;
    int unk34;
    NiPoint3H m_kHitPos;
    NiMatrix3H m_kRotationMatrix;
};

float __cdecl RemapValueBySettings(float fForce, bool bActor);
float __cdecl BSMAX_00404010(float a, float b);
void __cdecl bhkForceController_RemoveForce(HavokObjectH* pkObject);
void __cdecl bhkWorld_SetMotion(HavokObjectH* pkObject, int a, int b, int c, int d);
void __cdecl NI2HK(hkVector4H* pkOut, const NiPoint3H* pkIn);
void __cdecl SetCollisionScale(HavokObjectH* pkObject, hkVector4H* pkImpulse, float fImpulse, HitDataH* pkHit);

class ActorH
{
  public:
    virtual void va000();
    virtual void va004();
    virtual void va008();
    virtual void va00c();
    virtual void va010();
    virtual void va014();
    virtual void va018();
    virtual void va01c();
    virtual void va020();
    virtual void va024();
    virtual void va028();
    virtual void va02c();
    virtual void va030();
    virtual void va034();
    virtual void va038();
    virtual void va03c();
    virtual void va040();
    virtual void va044();
    virtual void va048();
    virtual void va04c();
    virtual void va050();
    virtual void va054();
    virtual void va058();
    virtual void va05c();
    virtual void va060();
    virtual void va064();
    virtual void va068();
    virtual void va06c();
    virtual void va070();
    virtual void va074();
    virtual void va078();
    virtual void va07c();
    virtual void va080();
    virtual void va084();
    virtual void va088();
    virtual void va08c();
    virtual void va090();
    virtual void va094();
    virtual void va098();
    virtual void va09c();
    virtual void va0a0();
    virtual void va0a4();
    virtual void va0a8();
    virtual void va0ac();
    virtual void va0b0();
    virtual void va0b4();
    virtual void va0b8();
    virtual void va0bc();
    virtual void va0c0();
    virtual void va0c4();
    virtual void va0c8();
    virtual void va0cc();
    virtual void va0d0();
    virtual void va0d4();
    virtual void va0d8();
    virtual void va0dc();
    virtual void va0e0();
    virtual void va0e4();
    virtual void va0e8();
    virtual void va0ec();
    virtual void va0f0();
    virtual void va0f4();
    virtual void va0f8();
    virtual void va0fc();
    virtual void va100();
    virtual void va104();
    virtual void va108();
    virtual void va10c();
    virtual void va110();
    virtual void va114();
    virtual void va118();
    virtual void va11c();
    virtual void va120();
    virtual void va124();
    virtual void va128();
    virtual void va12c();
    virtual void va130();
    virtual void va134();
    virtual void va138();
    virtual void va13c();
    virtual void va140();
    virtual void va144();
    virtual void va148();
    virtual void va14c();
    virtual void va150();
    virtual void va154();
    virtual void va158();
    virtual void va15c();
    virtual void va160();
    virtual void va164();
    virtual void va168();
    virtual void va16c();
    virtual void va170();
    virtual void va174();
    virtual void va178();
    virtual void va17c();
    virtual void va180();
    virtual void va184();
    virtual void va188();
    virtual void va18c();
    virtual void va190();
    virtual void va194();
    virtual void va198();
    virtual void va19c();
    virtual void va1a0();
    virtual void va1a4();
    virtual void va1a8();
    virtual void va1ac();
    virtual void va1b0();
    virtual void va1b4();
    virtual void va1b8();
    virtual void va1bc();
    virtual void va1c0();
    virtual void va1c4();
    virtual void va1c8();
    virtual void va1cc();
    virtual NiNodeH* Get3D();
    ProcessH* GetProcess();
    BSFixedStringH GetTorsoNodeName(int iFlag);

    void Actor_DoWeaponKillForce(HitDataH* pkHit);
};

// @fnv 0x008ae000
// src: XBOX_PDB 0x008ae000
void ActorH::Actor_DoWeaponKillForce(HitDataH* pkHit)
{
    TESObjectREFRH* pkTarget = pkHit->m_pkTarget;
    float fForce = pkHit->m_fForce;
    bool bActorSource = pkHit->m_pkSource && pkHit->m_pkSource->IsActor();
    NiNodeH* pk3D = Get3D();
    NiPoint3H kFrom = g_kZeroH;
    NiPoint3H kTo = g_kZeroH;
    if (pk3D)
    {
        ProcessH* pkProcess = GetProcess();
        kFrom = pk3D->GetObjectByName(pkProcess->GetWeaponNodeName()).GetWorldTranslate();
    }
    if (pkTarget)
    {
        if (!pkTarget->IsDead() || pkTarget->IsRagdollable())
        {
            HavokObjectH* pkObject = pkTarget->GetHavokObject();
            if (pkObject)
            {
                NiPoint3H kWorldPosition = g_kZeroH;
                if (bActorSource)
                {
                    kWorldPosition = pkHit->m_kRotationMatrix.GetForward();
                    kWorldPosition.Unitize();
                    kWorldPosition *= 2048.0f;
                    kWorldPosition += pkHit->m_kHitPos;
                }
                else
                {
                    if (pk3D)
                        kTo = pk3D->GetObjectByName(GetTorsoNodeName(0)).GetWorldTranslate();
                    kWorldPosition = kFrom - kTo;
                    kWorldPosition.Unitize();
                    kWorldPosition += pkHit->m_kRotationMatrix.GetForward();
                    kWorldPosition *= 1024.0f;
                    kWorldPosition += kFrom;
                }
                float fImpulse = RemapValueBySettings(fForce, bActorSource);
                if (pkHit->m_pkWeapon)
                {
                    fImpulse = pkHit->m_pkWeapon->GetImpulseScale() * 2.5;
                    if (bActorSource && pkHit->m_pkWeapon->GetImpulseRange() > 0.0)
                    {
                        NiPoint3H kPos = pkObject->GetPosition();
                        NiPoint3H kDelta = kPos - kFrom;
                        float fImpulseRadiusSquared = pkHit->m_pkWeapon->GetImpulseRange();
                        fImpulseRadiusSquared = fImpulseRadiusSquared * fImpulseRadiusSquared;
                        float fDistSq = kDelta.x * kDelta.x + kDelta.y * kDelta.y;
                        if (fDistSq > fImpulseRadiusSquared)
                        {
                            if (2.0 * pkHit->m_pkWeapon->GetImpulseRange() < fDistSq)
                            {
                                fImpulse = fImpulse * (double)0.1f;
                            }
                            else
                            {
                                float fScale = (2.0 * fImpulseRadiusSquared - fDistSq) / fImpulseRadiusSquared * (double)0.9f + (double)0.1f;
                                fScale = BSMAX_00404010(fScale, 0.1f);
                                fImpulse = fImpulse * fScale;
                            }
                        }
                    }
                }
                bhkForceController_RemoveForce(pkObject);
                bhkWorld_SetMotion(pkObject, 1, 1, 0, 1);
                TargetInfoH kInfo(0.0f, 0, 0);
                pkObject->SetTargetInfo(&kInfo);
                hkVector4H kImpulse;
                NI2HK(&kImpulse, &kWorldPosition);
                SetCollisionScale(pkObject, &kImpulse, fImpulse, pkHit);
            }
        }
    }
}

struct xP3
{
    xP3();
    float x, y, z;
    xP3 operator+(const xP3&) const;
    void Unitize_004a0c10();
};
struct xMat
{
    xMat();
    float m[9];
    void FUN_004a0c90(float);
    void NiMatrix3_GetCol(unsigned int, xP3&);
};
xP3 xFUN_004a3760(float, const xP3&);
struct xFltSetting
{
    float* Setting_Float_00403e20();
};
extern xFltSetting xg_11d1200;
struct xBoolSetting
{
    unsigned char* FUN_00408d60();
};
extern xBoolSetting xg_11df868;
extern float xg_1022958;
struct xFilter
{
    xFilter(int);
    void CFilter_SetLayer(int);
    void CFilter_SetGroup(unsigned int);
    int CFilter_GetGroup();
    unsigned int m_uiFilterValue;
};
struct xAllHits
{
    xAllHits();
    virtual ~xAllHits();
    int m_q[0xc9];
};
struct xHitInfo
{
    xHitInfo(const xHitInfo*);
    int m_iWordAt00[4];
    float m_10;
    int m_14[15];
    void* m_50;
    int m_54[5];
};
struct xHitList
{
    int FUN_00726070();
    xHitInfo* GetEntryAt(int);
};
struct xHitOwner
{
    xHitList* TESDataHandler_GetWorldSpaceList();
};
struct __declspec(align(16)) xPick
{
    xPick();
    void bhkPickData_SetFrom(xP3*);
    void bhkPickData_SetTo(const xP3&);
    void bhkPickData_SetFilter(xFilter);
    void bhkPickData_SetAllCollector(xAllHits*);
    xHitOwner* DialoguePackage_GetCurrentDialogItem();
    char m_buf[0xb0];
};
struct xWorld
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
    virtual void FUN_c8(xPick*);
};

struct xCell;
xWorld* __fastcall xFUN_004543c0(xCell*);
struct xPlayer
{
    xCell* FUN_008d6f30();
};
extern xPlayer* xg_player_11dea3c;
void* xFUN_004b5820(void*);
struct xActor;
xActor* xFUN_0056f930(void*);
void* xFUN_004b59f0(void*);
struct xISParam
{
    xISParam(float, float, float, float);
    float m[4];
};
void* xFUN_004b3890(const xP3&, const xISParam&, const xP3&, const xISParam&, int);
struct xTES
{
    void FUN_00458e20(void*, float);
};
extern xTES* xg_TES_11dea10;
struct xActor
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
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual xP3* FUN_1f4();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual float FUN_2bc(int);
    xFilter FUN_00931ed0();
    float Actor_GetVATSAreaFree(int aiUnused, float afHeight);
};

// @fnv 0x008bd830
// src: XBOX_PDB 0x008bd830
float xActor::Actor_GetVATSAreaFree(int aiUnused, float afHeight)
{
    xP3 POS = *FUN_1f4();
    POS.z = POS.z + *xg_11d1200.Setting_Float_00403e20();
    xP3 DIR;
    xMat MAT;
    MAT.FUN_004a0c90(FUN_2bc(0) + afHeight);
    MAT.NiMatrix3_GetCol(1, DIR);
    DIR.Unitize_004a0c10();
    float DIST = xg_1022958;
    xP3 END = POS + xFUN_004a3760(DIST, DIR);
    bool HIT = false;
    float BEST = 3.402823466e+38F;
    xPick PICK;
    PICK.bhkPickData_SetFrom(&POS);
    PICK.bhkPickData_SetTo(END);
    xFilter FILTER(0);
    FILTER.CFilter_SetLayer(0x23);
    FILTER.CFilter_SetGroup(FUN_00931ed0().CFilter_GetGroup());
    PICK.bhkPickData_SetFilter(FILTER);
    xAllHits HITS;
    PICK.bhkPickData_SetAllCollector(&HITS);
    xWorld* WORLD = xFUN_004543c0(xg_player_11dea3c->FUN_008d6f30());
    WORLD->FUN_c8(&PICK);
    for (int I = 0; !HIT && I < PICK.DialoguePackage_GetCurrentDialogItem()->TESDataHandler_GetWorldSpaceList()->FUN_00726070(); I++)
    {
        xHitInfo INFO(PICK.DialoguePackage_GetCurrentDialogItem()->TESDataHandler_GetWorldSpaceList()->GetEntryAt(I));
        void* OBJ = xFUN_004b5820(INFO.m_50);
        xActor* ACTOR = xFUN_0056f930(OBJ);
        void* OTHER = xFUN_004b59f0(INFO.m_50);
        if (OBJ && OTHER && ACTOR != this)
        {
            HIT = true;
            BEST = INFO.m_10 * DIST;
        }
    }
    if (*xg_11df868.FUN_00408d60())
    {
        xISParam COLOR(1.0f, 1.0f, 0.0f, 1.0f);
        void* LINE = xFUN_004b3890(POS, COLOR, POS + xFUN_004a3760(BEST, DIR), COLOR, 1);
        xg_TES_11dea10->FUN_00458e20(LINE, 10.0f);
    }
    return BEST;
}

namespace fnv_008bdbd0 {
struct xP3
{
    xP3();
    float x, y, z;
    xP3 operator+(const xP3&) const;
    xP3 operator-(const xP3&) const;
    float FUN_00457990() const;
    xP3* FUN_006815c0();
    void Unitize_004a0c10();
};
struct xMat
{
    xMat();
    float m[9];
    void FUN_004a0c90(float);
    void NiMatrix3_GetCol(unsigned int, xP3&);
};
xP3 xFUN_004a3760(float, const xP3&);
struct xFltSetting
{
    float* Setting_Float_00403e20();
};
extern xFltSetting xg_11d1200;
struct xBoolSetting
{
    unsigned char* FUN_00408d60();
};
extern xBoolSetting xg_11df868;
extern xFltSetting xg_11d0850;
extern xFltSetting xg_11d09e8;
extern const double xg_10231d8;
struct xBound
{
    xP3* FUN_006815c0();
};
struct xAVObj
{
    xBound* NiAVObject_GetWorldBound();
};
struct xFilter
{
    xFilter(int);
    void CFilter_SetLayer(int);
    void CFilter_SetGroup(unsigned int);
    int CFilter_GetGroup();
    unsigned int m_uiFilterValue;
};
struct __declspec(align(16)) xAllHits
{
    xAllHits();
    virtual ~xAllHits();
    int m_q[0xc7];
};
struct __declspec(align(16)) xHitInfo
{
    xHitInfo(const xHitInfo*);
    int m_iWordAt00[4];
    float m_10;
    int m_14[15];
    void* m_50;
    int m_54[3];
};
struct xHitList
{
    int FUN_00726070();
    xHitInfo* GetEntryAt(int);
};
struct xHitOwner
{
    xHitList* TESDataHandler_GetWorldSpaceList();
};
struct __declspec(align(16)) xPick
{
    xPick();
    void bhkPickData_SetFrom(xP3*);
    void bhkPickData_SetTo(const xP3&);
    void bhkPickData_SetFilter(xFilter);
    void bhkPickData_SetAllCollector(xAllHits*);
    xHitOwner* DialoguePackage_GetCurrentDialogItem();
    char m_buf[0xb0];
};
struct xWorld
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
    virtual void FUN_c8(xPick*);
};

struct xCell;
xWorld* __fastcall xFUN_004543c0(xCell*);
struct xPlayer
{
    xCell* FUN_008d6f30();
};
extern xPlayer* xg_player_11dea3c;
void* xFUN_004b5820(void*);
struct xActor;
xActor* xFUN_0056f930(void*);
void* xFUN_004b59f0(void*);
struct xISParam
{
    xISParam(float, float, float, float);
    float m[4];
};
void* xFUN_004b3890(const xP3&, const xISParam&, const xP3&, const xISParam&, int);
struct xTES
{
    void FUN_00458e20(void*, float);
};
extern xTES* xg_TES_11dea10;
struct xActor
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
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual bool FUN_100();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual xAVObj* FUN_1d0();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual xP3* FUN_1f4();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual float FUN_2bc(int);
    xFilter FUN_00931ed0();
    float Actor_GetVATSTargetVisible(xActor* apTarget, float afHeight);
};

// @fnv 0x008bdbd0
// src: XBOX_PDB 0x008bdbd0
float xActor::Actor_GetVATSTargetVisible(xActor* apTarget, float afHeight)
{
    if (!apTarget || !apTarget->FUN_1d0())
        return 0.0f;
    xP3 POS = *FUN_1f4();
    POS.z = POS.z + *xg_11d1200.Setting_Float_00403e20();
    xP3 DIR;
    xMat MAT;
    MAT.FUN_004a0c90(FUN_2bc(0) + afHeight);
    MAT.NiMatrix3_GetCol(1, DIR);
    DIR.Unitize_004a0c10();
    xP3 TPOS = *apTarget->FUN_1d0()->NiAVObject_GetWorldBound()->FUN_006815c0();
    bool DONE = false;
    float RESULT = 0.0f;
    for (int I = 0; !DONE && I < *xg_11d0850.Setting_Float_00403e20(); I++)
    {
        float DIST = (I + 1) * *xg_11d09e8.Setting_Float_00403e20();
        xP3 START = POS + xFUN_004a3760(DIST, DIR);
        xPick PICK;
        PICK.bhkPickData_SetFrom(&START);
        PICK.bhkPickData_SetTo(TPOS);
        xFilter FILTER(0);
        FILTER.CFilter_SetLayer(0x23);
        FILTER.CFilter_SetGroup(FUN_00931ed0().CFilter_GetGroup());
        PICK.bhkPickData_SetFilter(FILTER);
        xAllHits HITS;
        PICK.bhkPickData_SetAllCollector(&HITS);
        if (*xg_11df868.FUN_00408d60())
        {
            xISParam COLOR(1.0f, 1.0f, 0.0f, 1.0f);
            void* LINE = xFUN_004b3890(TPOS, COLOR, START, COLOR, 1);
            xg_TES_11dea10->FUN_00458e20(LINE, 10.0f);
        }
        xWorld* WORLD = xFUN_004543c0(xg_player_11dea3c->FUN_008d6f30());
        WORLD->FUN_c8(&PICK);
        for (int J = 0; !DONE && J < PICK.DialoguePackage_GetCurrentDialogItem()->TESDataHandler_GetWorldSpaceList()->FUN_00726070(); J++)
        {
            xHitInfo INFO(PICK.DialoguePackage_GetCurrentDialogItem()->TESDataHandler_GetWorldSpaceList()->GetEntryAt(J));
            void* OBJ = xFUN_004b5820(INFO.m_50);
            xActor* ACTOR = xFUN_0056f930(OBJ);
            void* OTHER = xFUN_004b59f0(INFO.m_50);
            if (OBJ && OTHER && ACTOR != apTarget)
            {
                DONE = true;
                if (INFO.m_10 > 0.8500000238418579)
                    DONE = false;
                if (ACTOR && ACTOR->FUN_100())
                {
                    float D = (TPOS - START).FUN_00457990() * INFO.m_10;
                    if (D > xg_10231d8)
                        DONE = false;
                }
            }
        }
        if (!DONE)
            RESULT = (I + 1) * *xg_11d09e8.Setting_Float_00403e20();
    }
    return RESULT;
}
}  // namespace fnv_008bdbd0

class NiPoint3C7
{
  public:
    NiPoint3C7(float fX, float fY, float fZ);
    float x;
    float y;
    float z;
};



class NameC7
{
  public:
    NameC7(const char* pcName);
    ~NameC7();
    const char* m_pcName;
};
extern const char* g_apcNamesC7[];
bool __cdecl Actor_AreReferencedValuesEqual(const char* pcA, const NameC7& kB);

class ModelC7
{
  public:
    const char* GetName();
};

class ClipC7
{
  public:
    ModelC7* GetModelFilePath();
    unsigned int GetCount();
    void* GetAt(unsigned int uiIndex);
};
void __cdecl bhkWorld_SetDisabled(void* pvItem, int iA, int iB, int iC);

struct SlotC7
{
    unsigned char m_ucValue;
};

class AnimDataC7
{
  public:
    unsigned int GetCount();
    SlotC7* GetAt(unsigned int uiIndex);
};

class LinkC7
{
  public:
    AnimDataC7* GetAnimData();
    void* GetSkeletonA();
    void* GetSkeletonB();
};

class HandleC7
{
  public:
    void* Get();
    unsigned int m_uiHandle;
};

class FlagsC7
{
  public:
    FlagsC7();
    void SetTarget(void* pvTarget);
    int m_iValue;
};

class ListenerC7
{
  public:
    FlagsC7 GetFlags();
    void SetFlags(FlagsC7 kFlags);
};

class BitsC7
{
  public:
    void SetBit(unsigned int uiBit, bool bSet);
};

class ProjC7;
template <class T> class NiPointerC7
{
  public:
    NiPointerC7(T* pkObject);
    ~NiPointerC7();
    T* m_pPointer;
};

class ProcessC7
{
  public:
    virtual void p000();
    virtual void p001();
    virtual void p002();
    virtual void p003();
    virtual void p004();
    virtual void p005();
    virtual void p006();
    virtual void p007();
    virtual void p008();
    virtual void p009();
    virtual void p00a();
    virtual void p00b();
    virtual void p00c();
    virtual void p00d();
    virtual void p00e();
    virtual void p00f();
    virtual void p010();
    virtual void p011();
    virtual void p012();
    virtual void p013();
    virtual void p014();
    virtual void p015();
    virtual void p016();
    virtual void p017();
    virtual void p018();
    virtual void p019();
    virtual void p01a();
    virtual void p01b();
    virtual void p01c();
    virtual void p01d();
    virtual void p01e();
    virtual void p01f();
    virtual void p020();
    virtual void p021();
    virtual void p022();
    virtual void p023();
    virtual void p024();
    virtual void p025();
    virtual void p026();
    virtual void p027();
    virtual void p028();
    virtual void p029();
    virtual void p02a();
    virtual void p02b();
    virtual void p02c();
    virtual void p02d();
    virtual void p02e();
    virtual void p02f();
    virtual void p030();
    virtual void p031();
    virtual void p032();
    virtual void p033();
    virtual void p034();
    virtual void p035();
    virtual void p036();
    virtual void p037();
    virtual void p038();
    virtual void p039();
    virtual void p03a();
    virtual void p03b();
    virtual void p03c();
    virtual void p03d();
    virtual void p03e();
    virtual void p03f();
    virtual void p040();
    virtual void p041();
    virtual void p042();
    virtual void p043();
    virtual void p044();
    virtual void p045();
    virtual void p046();
    virtual void p047();
    virtual void p048();
    virtual void p049();
    virtual void p04a();
    virtual void p04b();
    virtual void p04c();
    virtual void p04d();
    virtual void p04e();
    virtual void p04f();
    virtual void p050();
    virtual void p051();
    virtual void p052();
    virtual void p053();
    virtual void p054();
    virtual void p055();
    virtual void p056();
    virtual void p057();
    virtual void p058();
    virtual void p059();
    virtual void p05a();
    virtual void p05b();
    virtual void p05c();
    virtual void p05d();
    virtual void p05e();
    virtual void p05f();
    virtual void p060();
    virtual void p061();
    virtual void p062();
    virtual void p063();
    virtual void p064();
    virtual void p065();
    virtual void p066();
    virtual void p067();
    virtual void p068();
    virtual void p069();
    virtual void p06a();
    virtual void p06b();
    virtual void p06c();
    virtual void p06d();
    virtual void p06e();
    virtual void p06f();
    virtual void p070();
    virtual void p071();
    virtual void p072();
    virtual void p073();
    virtual void p074();
    virtual void p075();
    virtual void p076();
    virtual void p077();
    virtual void p078();
    virtual void p079();
    virtual void p07a();
    virtual void p07b();
    virtual void p07c();
    virtual void p07d();
    virtual void p07e();
    virtual void p07f();
    virtual void p080();
    virtual void p081();
    virtual void p082();
    virtual void p083();
    virtual void p084();
    virtual void p085();
    virtual void p086();
    virtual void p087();
    virtual void p088();
    virtual void p089();
    virtual void p08a();
    virtual void p08b();
    virtual void p08c();
    virtual void p08d();
    virtual void p08e();
    virtual void p08f();
    virtual void p090();
    virtual void p091();
    virtual void p092();
    virtual void p093();
    virtual void p094();
    virtual void p095();
    virtual void p096();
    virtual void p097();
    virtual void p098();
    virtual void p099();
    virtual void p09a();
    virtual void p09b();
    virtual void p09c();
    virtual void p09d();
    virtual void p09e();
    virtual void p09f();
    virtual void p0a0();
    virtual void p0a1();
    virtual void p0a2();
    virtual void p0a3();
    virtual void SetProjectile(NiPointerC7<ProjC7> spProj);
    virtual void p0a5();
    virtual void p0a6();
    virtual void p0a7();
    virtual void p0a8();
    virtual void p0a9();
    virtual void p0aa();
    virtual void p0ab();
    virtual void p0ac();
    virtual void p0ad();
    virtual void p0ae();
    virtual void p0af();
    virtual void p0b0();
    virtual void p0b1();
    virtual void p0b2();
    virtual void p0b3();
    virtual void p0b4();
    virtual void p0b5();
    virtual void p0b6();
    virtual void p0b7();
    virtual void p0b8();
    virtual void p0b9();
    virtual void p0ba();
    virtual void p0bb();
    virtual void p0bc();
    virtual void p0bd();
    virtual void p0be();
    virtual void p0bf();
    virtual void p0c0();
    virtual void p0c1();
    virtual void p0c2();
    virtual void p0c3();
    virtual void p0c4();
    virtual void p0c5();
    virtual void p0c6();
    virtual void p0c7();
    virtual void p0c8();
    virtual void p0c9();
    virtual void p0ca();
    virtual void p0cb();
    virtual void p0cc();
    virtual void p0cd();
    virtual void p0ce();
    virtual void p0cf();
    virtual void p0d0();
    virtual void p0d1();
    virtual void p0d2();
    virtual void p0d3();
    virtual void p0d4();
    virtual void p0d5();
    virtual void p0d6();
    virtual void p0d7();
    virtual void p0d8();
    virtual void p0d9();
    virtual void p0da();
    virtual void p0db();
    virtual void p0dc();
    virtual void p0dd();
    virtual void p0de();
    virtual void p0df();
    virtual void p0e0();
    virtual void p0e1();
    virtual void p0e2();
    virtual void p0e3();
    virtual void p0e4();
    virtual void p0e5();
    virtual void p0e6();
    virtual void p0e7();
    virtual void p0e8();
    virtual void p0e9();
    virtual void p0ea();
    virtual void p0eb();
    virtual void p0ec();
    virtual void p0ed();
    virtual void p0ee();
    virtual void p0ef();
    virtual void p0f0();
    virtual void p0f1();
    virtual void p0f2();
    virtual void p0f3();
    virtual void p0f4();
    virtual void p0f5();
    virtual void p0f6();
    virtual void p0f7();
    virtual void p0f8();
    virtual void p0f9();
    virtual void p0fa();
    virtual void p0fb();
    virtual void p0fc();
    virtual void p0fd();
    virtual void p0fe();
    virtual void p0ff();
    virtual void p100();
    virtual void p101();
    virtual void p102();
    virtual void p103();
    virtual void p104();
    virtual void p105();
    virtual void p106();
    virtual void p107();
    virtual void p108();
    virtual void p109();
    virtual void p10a();
    virtual void p10b();
    virtual void p10c();
    virtual void p10d();
    virtual void p10e();
    virtual void p10f();
    virtual void p110();
    virtual void p111();
    virtual void p112();
    virtual void p113();
    virtual void p114();
    virtual void p115();
    virtual void p116();
    virtual void p117();
    virtual void p118();
    virtual void p119();
    virtual void p11a();
    virtual void p11b();
    virtual void p11c();
    virtual void p11d();
    virtual void p11e();
    virtual void p11f();
    virtual void p120();
    virtual void p121();
    virtual void p122();
    virtual void p123();
    virtual void p124();
    virtual void p125();
    virtual void p126();
    virtual void p127();
    virtual void p128();
    virtual void p129();
    virtual void p12a();
    virtual void p12b();
    virtual void p12c();
    virtual void p12d();
    virtual void p12e();
    virtual void p12f();
    virtual void p130();
    virtual void p131();
    virtual void p132();
    virtual void p133();
    virtual void p134();
    virtual void p135();
    virtual void p136();
    virtual void p137();
    virtual void p138();
    virtual void p139();
    virtual void p13a();
    virtual void p13b();
    virtual void p13c();
    virtual void p13d();
    virtual void p13e();
    virtual void p13f();
    virtual void p140();
    virtual void p141();
    virtual void p142();
    virtual void p143();
    virtual void p144();
    virtual void p145();
    virtual void p146();
    virtual void p147();
    virtual void p148();
    virtual void p149();
    virtual void p14a();
    virtual void p14b();
    virtual void p14c();
    virtual void p14d();
    virtual void p14e();
    virtual void p14f();
    virtual void p150();
    virtual void p151();
    virtual void p152();
    virtual void p153();
    virtual void p154();
    virtual void p155();
    virtual void p156();
    virtual void p157();
    virtual void p158();
    virtual void p159();
    virtual void p15a();
    virtual void p15b();
    virtual void p15c();
    virtual void p15d();
    virtual void p15e();
    virtual void p15f();
    virtual void p160();
    virtual void p161();
    virtual void p162();
    virtual void p163();
    virtual void p164();
    virtual void p165();
    virtual void p166();
    virtual void p167();
    virtual void p168();
    virtual void p169();
    virtual void p16a();
    virtual void p16b();
    virtual void p16c();
    virtual void p16d();
    virtual void p16e();
    virtual void p16f();
    virtual void p170();
    virtual void p171();
    virtual void p172();
    virtual void p173();
    virtual void p174();
    virtual void p175();
    virtual void p176();
    virtual void p177();
    virtual void p178();
    virtual void p179();
    virtual void p17a();
    virtual void p17b();
    virtual void p17c();
    virtual void p17d();
    virtual void p17e();
    virtual void p17f();
    virtual void p180();
    virtual void p181();
    virtual void p182();
    virtual void p183();
    virtual void p184();
    virtual void p185();
    virtual void p186();
    virtual void p187();
    virtual void p188();
    virtual void p189();
    virtual void p18a();
    virtual void p18b();
    virtual void p18c();
    virtual void p18d();
    virtual void p18e();
    virtual void p18f();
    virtual void p190();
    virtual void p191();
    virtual void p192();
    virtual void p193();
    virtual void p194();
    virtual void p195();
    virtual void p196();
    virtual void p197();
    virtual void p198();
    virtual void p199();
    virtual void p19a();
    virtual void p19b();
    virtual void p19c();
    virtual void p19d();
    virtual void p19e();
    virtual void p19f();
    virtual void p1a0();
    virtual void p1a1();
    virtual void p1a2();
    virtual void p1a3();
    virtual void p1a4();
    virtual void p1a5();
    virtual void p1a6();
    virtual void p1a7();
    virtual void p1a8();
    virtual void p1a9();
    virtual void p1aa();
    virtual void p1ab();
    virtual void p1ac();
    virtual void p1ad();
    virtual void p1ae();
    virtual void p1af();
    virtual void p1b0();
    virtual void p1b1();
    virtual void p1b2();
    virtual void p1b3();
    virtual ClipC7* GetClip(unsigned char m_ucClipIdentifier);
    int GetLevel();
    ListenerC7* GetListener();
    bool IsInDialogue();
    void SetDialogueActor(void* pvActor);
};

class InitC7
{
  public:
    InitC7(int iType);
    ~InitC7();
    void SetOwner(void* pvOwner);
    void SetParent(void* pvParent);
    void SetFlag857(int iValue);
    void SetScale(float fScale);
    void SetFlagA(bool bValue);
    void SetFlagB(bool bValue);
    void SetSpeed(float fSpeed);
    void SetDefault(int iValue);
    __m128 m_akData[12];
};

class ProjC7
{
  public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pv);
    ProjC7(const InitC7& kInit);
    virtual void j000();
    virtual void j001();
    virtual void j002();
    virtual void j003();
    virtual void j004();
    virtual void j005();
    virtual void j006();
    virtual void j007();
    virtual void j008();
    virtual void j009();
    virtual void j00a();
    virtual void j00b();
    virtual void j00c();
    virtual void j00d();
    virtual void j00e();
    virtual void j00f();
    virtual void j010();
    virtual void j011();
    virtual void j012();
    virtual void j013();
    virtual void j014();
    virtual void j015();
    virtual void j016();
    virtual void j017();
    virtual void j018();
    virtual void j019();
    virtual void j01a();
    virtual void j01b();
    virtual void j01c();
    virtual void j01d();
    virtual void j01e();
    virtual void j01f();
    virtual void j020();
    virtual void j021();
    virtual void j022();
    virtual void j023();
    virtual void j024();
    virtual void j025();
    virtual void j026();
    virtual void j027();
    virtual void j028();
    virtual void j029();
    virtual void j02a();
    virtual void j02b();
    virtual void j02c();
    virtual void j02d();
    virtual void j02e();
    virtual void j02f();
    virtual void j030();
    virtual void j031();
    virtual void j032();
    virtual void j033();
    virtual void Reset(int iValue);
    void SetSource(void* pvSource);
    void SetSpeed(float fSpeed);
    void SetFlag(bool bValue);
    void* GetTarget();
    void SetTarget(void* pvTarget);
    void SetFlag931(int iValue);
    HandleC7 GetHandle();
    char m_acPad[0x410 - 4];
    BitsC7 m_kBits;
    char m_acPad2[0x650 - 0x411];
};
void __cdecl bhkWorld_SetMotion(void* pvTarget, int iMode, int iA, int iB, int iC);
void __cdecl CopyBlock48(void* pvTarget, int iValue);
void __cdecl TESHavokUtilities_AddVelocity(void* pvTarget, NiPoint3C7& kPoint, int iValue);
void __cdecl PropagateNameToHavokEntity(void* pvTarget);
bool __cdecl Main_GetSceneIsComplex();

class WorldC7
{
  public:
    bool IsBusy();
    bool CheckC7();
};

class CellC7
{
  public:
    bool IsLoaded();
    bool IsAttached();
    WorldC7* GetWorld();
};

class SubC7
{
  public:
    bool IsSet();
};

class OwnerC7
{
  public:
    char m_acPad[0x30];
    SubC7 m_kSub;
};

class ControllerC7
{
  public:
    bool GetFlagA();
    bool GetFlagB();
};

class MiddleC7
{
  public:
    void SetMode(int iMode);
    void SetFlag(int iValue);
};

class RagdollC7
{
  public:
    void Attach(void* pvNode, void* pvTarget);
};

class RefC7
{
  public:
    virtual void r000();
    virtual void r001();
    virtual void r002();
    virtual void r003();
    virtual void r004();
    virtual void r005();
    virtual void r006();
    virtual void r007();
    virtual void r008();
    virtual void r009();
    virtual void r00a();
    virtual void r00b();
    virtual void r00c();
    virtual void r00d();
    virtual void r00e();
    virtual void r00f();
    virtual void r010();
    virtual void r011();
    virtual void r012();
    virtual void r013();
    virtual void r014();
    virtual void r015();
    virtual void r016();
    virtual void r017();
    virtual void r018();
    virtual void r019();
    virtual void r01a();
    virtual void r01b();
    virtual void r01c();
    virtual void r01d();
    virtual void r01e();
    virtual void r01f();
    virtual void r020();
    virtual void r021();
    virtual void r022();
    virtual void r023();
    virtual void r024();
    virtual void r025();
    virtual void r026();
    virtual void r027();
    virtual void r028();
    virtual void r029();
    virtual void r02a();
    virtual void r02b();
    virtual void r02c();
    virtual void r02d();
    virtual void r02e();
    virtual void r02f();
    virtual void r030();
    virtual void r031();
    virtual void r032();
    virtual void r033();
    virtual void r034();
    virtual void r035();
    virtual void r036();
    virtual void r037();
    virtual void r038();
    virtual void r039();
    virtual void r03a();
    virtual void r03b();
    virtual void r03c();
    virtual void r03d();
    virtual void r03e();
    virtual void r03f();
    virtual bool IsActor();
    virtual void r041();
    virtual void r042();
    virtual void r043();
    virtual void r044();
    virtual void r045();
    virtual void r046();
    virtual void r047();
    virtual void r048();
    virtual void r049();
    virtual void r04a();
    virtual void r04b();
    virtual void r04c();
    virtual void r04d();
    virtual void r04e();
    virtual void r04f();
    virtual void r050();
    virtual void r051();
    virtual void r052();
    virtual void r053();
    virtual void r054();
    virtual void r055();
    virtual void r056();
    virtual void r057();
    virtual void r058();
    virtual void r059();
    virtual void r05a();
    virtual void r05b();
    virtual void r05c();
    virtual void r05d();
    virtual void r05e();
    virtual void r05f();
    virtual void r060();
    virtual void r061();
    virtual void r062();
    virtual void r063();
    virtual void r064();
    virtual void r065();
    virtual void r066();
    virtual void r067();
    virtual void r068();
    virtual void r069();
    virtual void r06a();
    virtual void r06b();
    virtual void r06c();
    virtual void r06d();
    virtual void r06e();
    virtual void r06f();
    virtual void r070();
    virtual void r071();
    virtual void r072();
    virtual void r073();
    virtual void* Get3D();
    virtual void r075();
    virtual void r076();
    virtual void r077();
    virtual void r078();
    virtual void r079();
    virtual void r07a();
    virtual void r07b();
    virtual void r07c();
    virtual void r07d();
    virtual void r07e();
    virtual void SetUpdate(int iValue);
    virtual void r080();
    virtual void r081();
    virtual void r082();
    virtual void r083();
    virtual void r084();
    virtual void r085();
    virtual void r086();
    virtual bool IsMoving();
    virtual void r088();
    virtual void r089();
    virtual void r08a();
    virtual bool IsDead(int iValue);
    virtual void r08c();
    virtual void r08d();
    virtual void r08e();
    virtual void r08f();
    virtual void r090();
    virtual void r091();
    virtual void r092();
    virtual void r093();
    virtual void r094();
    virtual void r095();
    virtual void r096();
    virtual void r097();
    virtual void r098();
    virtual void r099();
    virtual void r09a();
    virtual void r09b();
    virtual void r09c();
    virtual void r09d();
    virtual void r09e();
    virtual void r09f();
    virtual void r0a0();
    virtual void r0a1();
    virtual void r0a2();
    virtual void r0a3();
    virtual void r0a4();
    virtual void r0a5();
    virtual void r0a6();
    virtual void r0a7();
    virtual void r0a8();
    virtual void r0a9();
    virtual void r0aa();
    virtual void r0ab();
    virtual void r0ac();
    virtual void r0ad();
    virtual void r0ae();
    virtual void r0af();
    virtual void r0b0();
    virtual void r0b1();
    virtual void r0b2();
    virtual void r0b3();
    virtual void r0b4();
    virtual void r0b5();
    virtual void r0b6();
    virtual void r0b7();
    virtual void r0b8();
    virtual float GetScaleV();
    void PreUpdate(int iValue);
    CellC7* GetParentCell();
    void* GetTarget();
    void* GetParent();
    LinkC7* GetLink();
    ProjC7* GetProjectileData();
    ControllerC7* GetController();
    float GetAnimationSpeed();
    OwnerC7* GetOwner();
    char m_acPad[0x68 - 4];
    ProcessC7* m_pkProcess;
    void MobileObject_InitHavok();
};

class ActorC7 : public RefC7
{
  public:
    int GetState();
    int GetLifeState();
    bool IsInState(int iState);
    bool IsBusy();
    HandleC7 GetHandle();
    void StartCombat(void* pvTarget, int iA, int iB, int iC);
    char m_acPad2[0xac - 0x6c];
    MiddleC7* m_pkMiddle;
    RagdollC7* m_pkRagdoll;
};
extern RefC7* g_pkPlayerC7;

// @fnv 0x00930c70
// src: XBOX_PDB 0x00930c70
void RefC7::MobileObject_InitHavok()
{
    PreUpdate(0);
    if (!m_pkProcess || (m_pkProcess->GetLevel() && m_pkProcess->GetLevel() != 1))
        return;
    CellC7* pkCell = GetParentCell();
    ProcessC7* pkProcess = !m_pkProcess->GetLevel() ? m_pkProcess : 0;
    if (pkCell && !pkCell->IsLoaded() && !pkCell->IsAttached())
        return;
    WorldC7* pkWorld = pkCell ? pkCell->GetWorld() : 0;
    ActorC7* pkActor = IsActor() ? (ActorC7*)this : 0;
    bool bCombat;
    if (pkActor)
    {
        switch (pkActor->GetState())
        {
        case 2:
        case 4:
            return;
        }
        bCombat = pkActor->GetLifeState() == 2 || pkActor->IsInState(-1);
        PropagateNameToHavokEntity(GetTarget());
    }
    else
    {
        bCombat = false;
    }
    AnimDataC7* pkAnim = GetLink()->GetAnimData();
    if (pkAnim && m_pkProcess && Get3D())
    {
        unsigned int ItemUpdateArray = pkAnim->GetCount();
        for (unsigned int i = 0; i < ItemUpdateArray; i++)
        {
            SlotC7* pkSlot = pkAnim->GetAt(i);
            ClipC7* pkClip = m_pkProcess->GetClip(pkSlot->m_ucValue);
            ModelC7* pkModel = pkClip->GetModelFilePath();
            NameC7 kName(g_apcNamesC7[pkSlot->m_ucValue]);
            if (pkModel && Actor_AreReferencedValuesEqual(pkModel->GetName(), kName))
                continue;
            for (unsigned int j = 0; j < pkClip->GetCount(); j++)
            {
                void* pvItem = pkClip->GetAt(j);
                if (pvItem)
                    bhkWorld_SetDisabled(pvItem, 1, 1, 1);
            }
        }
    }
    ProjC7* pkProj = GetProjectileData();
    if (!pkProj)
    {
        InitC7 kInit(1);
        kInit.SetOwner(GetTarget());
        kInit.SetParent(GetParent());
        kInit.SetFlag857(0);
        kInit.SetScale(GetScaleV());
        if (pkActor && GetController() && pkActor->IsMoving())
        {
            kInit.SetFlagA(pkActor->GetController()->GetFlagA());
            kInit.SetFlagB(pkActor->GetController()->GetFlagB());
            kInit.SetSpeed(GetAnimationSpeed());
        }
        else
        {
            kInit.SetDefault(1);
        }
        pkProj = new ProjC7(kInit);
        if (pkActor && GetController())
            pkProj->m_kBits.SetBit(0x10004000, GetOwner()->m_kSub.IsSet());
        m_pkProcess->SetProjectile(pkProj);
        pkProj->SetSource(this);
        pkProj->SetSpeed(GetAnimationSpeed());
        pkProj->SetFlag(Main_GetSceneIsComplex());
        pkProj->m_kBits.SetBit(0x200000, true);
        if (pkProcess)
        {
            ListenerC7* pkListener = pkProcess->GetListener();
            if (pkListener)
            {
                FlagsC7 kFlags = pkListener->GetFlags();
                kFlags.SetTarget(pkProj->GetHandle().Get());
                pkListener->SetFlags(kFlags);
            }
        }
    }
    if (pkWorld && pkWorld->CheckC7())
        pkProj->SetFlag931(1);
    if (pkActor && bCombat)
        pkActor->m_pkRagdoll->Attach(pkActor->Get3D(), pkActor->GetHandle().Get());
    void* pvOld = pkProj->GetTarget();
    void* pvTarget = GetTarget();
    if (pvOld != pvTarget)
    {
        pkProj->SetTarget(pvTarget);
        ::NiQuaternion kRot(0.0f, 0.0f, 0.0f, 0.0f);
        kRot.m_fVectorX = 1.0f;
        kRot.m_fVectorY = 0.0f;
        kRot.m_fVectorZ = 0.0f;
        kRot.m_fScalarPart = 0.25f;
        CellC7* pkCell2 = GetParentCell();
        WorldC7* pkWorld2 = pkCell2 ? pkCell2->GetWorld() : 0;
        if (pkWorld2 && pkWorld2->IsBusy())
        {
            pkProj->Reset(0);
            CopyBlock48(pkProj->GetTarget(), 1);
        }
        bhkWorld_SetMotion(pvTarget, bCombat ? 1 : 4, 1, 0, 0);
        if (pkActor && !pkActor->IsDead(0))
        {
            pkActor->StartCombat(pvTarget, 1, 1, 0);
            if (this == g_pkPlayerC7 && pkActor->m_pkMiddle)
            {
                pkActor->m_pkMiddle->SetMode(0);
                pkActor->m_pkMiddle->SetFlag(1);
            }
        }
    }
    if (m_pkProcess && !m_pkProcess->GetLevel() && this != g_pkPlayerC7 && pkActor && pkActor->GetOwner() &&
        !pkActor->IsBusy())
    {
        ProcessC7* pkHigh = m_pkProcess;
        if (!pkHigh->IsInDialogue())
            pkHigh->SetDialogueActor(pkActor);
    }
    SetUpdate(0);
    if (bCombat && !GetLink()->GetSkeletonA() && !GetLink()->GetSkeletonB())
    {
        NiPoint3C7 kWorldPosition(0.0f, 0.0f, -1.0f);
        TESHavokUtilities_AddVelocity(pvTarget, kWorldPosition, 1);
    }
}

namespace fnv_0094cae0 {
struct kRef;
struct kShape;
struct kActor;

template <class T> struct kNodeT
{
    T** Get();
    kNodeT* Next();
    void FUN_00470470();
    bool FUN_008256d0();
};

struct kP3
{
    float x, y, z;
    kP3();
    void Subtract(kP3* o);
    float FUN_00457990();
};

struct kP4
{
    __m128 v;
    kP4();
};
void __cdecl NI2HK(kP4* a, kP3* b);

struct kP2
{
    float x, y;
    kP2(float a, float b);
    kP2(kP3* p);
};

struct kE
{
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
    virtual int v2c();
    virtual int v30();
    bool TESRegionData_GetOverride();
    unsigned char TESRegionData_GetPriority();
    kNodeT<kRef>* GetOffsetC();
    void TESRegionDataImposter_SetImpostersVisible(int a, int b);
    kNodeT<kRef>* FUN_00413f40();
};

struct kExt
{
    kE* TESRegionDataList_Find();
};

struct kRef
{
    bool FUN_00440d80();
    void* BGSSaveFormBuffer_GetForm();
    kNodeT<kShape>* FUN_00441110();
    kExt* NiAVObject_GetParent(int k);
    bool TESForm_GetHasSpokenFlag();
};

struct kShape
{
    bool TESRegionPointList_IsInsideRegion(kP2* p);
    bool FUN_008256d0();
};

struct kRefList
{
    int unk0;
    kNodeT<kRef> head;
};

struct kPA2
{
    void SetFlags_004893c0(int a);
};
struct kPA
{
    kPA2* FUN_0045cd60();
};
struct kU2
{
    int FUN_00500940();
};
struct kU
{
    kU2* TESObjectCELL_GetUsableImageSpace();
};
struct kCell
{
    bool IsFlag8Set();
};
struct kProc
{
    void FUN_0063c8f0();
};
kProc* __stdcall FUN_0046dd00(void* p);
void __cdecl BSShaderManager_SetImageSpaceParameters(int a);

struct kActor
{
    bool FUN_004518e0();
    float TESObjectCELL_GetWaterHeight();
    bool FUN_00425fd0();
    int TESObjectCELL_GetMusicType(int a);
    kPA* TESObjectCELL_GetbhkWorld();
    void* TESObjectCELL_GetClimate(int a);
    kU2* TESObjectCELL_GetUsableImageSpace();
    kCell* FUN_0054ddd0();
    int FUN_00544c30();
    int FUN_00544c60();
    kRefList* FUN_00547110(int a);
    void FUN_00548230(kRef* r, int a);
};

bool __cdecl TESWaterSystem_GetCameraInPlaceableWater();
void __cdecl TESWaterSystem_SetCameraRelevantWaterHeight(float f);
void __cdecl FalloutRadio_NewCellEntered();
struct kQ2
{
    void DecalCaster_Add(kPA* a);
};
kQ2* __cdecl FUN_00622a70(float f, int a);
float __cdecl DecalCaster_GetMaxDecalWidthLarge();
float __cdecl DecalCaster_GetMaxDecalWidthSmall();
void __cdecl TESRegionDataImposter_SetImposterVisible(kRef* r, int a, int b);

struct kZ
{
    int unk0, unk4, unk8, unkC, unk10;
    static void* operator new(unsigned int n);
    kZ();
    void bhkSphereShape_Init(float f);
};

struct __declspec(align(16)) kH
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
    kH();
    ~kH();
    void bhkRigidBodyCinfo_SetShape(kZ* z);
    void bhkRigidBodyCinfo_SetCollisionFilter(int f);
};

struct kW
{
    int unk0, unk4, unk8, unkC, unk10, unk14, unk18;
    static void* operator new(unsigned int n);
    kW(kH* h);
};

struct kVV
{
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
    virtual void v9c(kPA* a);
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void ve4(int a);
    void bhkRigidBody_SetActive(int a);
    void bhkRigidBody_SetNiPosition(kP3* p);
    struct kVV3* bhkWorldObject_GetCollidableRw();
};
struct kVV3
{
    void NiAlphaProperty_SetTestRef(int a);
};

struct kDec
{
    bool FUN_00822510(int a);
    void FUN_0066b0d0(kW* w);
    kVV* Modelloader_GetReferencedThis();
};

struct kG1
{
    void UpdateRelationStates(int a);
};
extern kG1* DAT_011c3b3c;
struct kG2
{
    unsigned char* FUN_00408d60();
};
extern kG2 DAT_011e08e0;
struct kG3
{
    bool TES_CellTestRunning();
};
extern kG3* DAT_011dea10;
extern kE* DAT_011dd380;
extern float DAT_01015f5c;
extern float DAT_01017d00;
extern double DAT_01017a10;
extern double DAT_01016968;

struct kO
{
    virtual ~kO();
    int unk4, unk8, unkC;
    kO(int a, int b);
    void NiTArray_char_NiTMallocInterface_char_RemoveAll();
    void FUN_0096a610(kRef** r);
};

struct kTyped
{
    int FUN_00401170();
};

struct kRList
{
    void FUN_00470470();
    bool FUN_008256d0();
    void FUN_005ae3d0(kRef** r);
};

struct kRList2
{
    kNodeT<kRef> head;
    int unk4;
    kRList2();
    ~kRList2();
    void FUN_005ae3d0(kRef** r);
    bool BSSimpleList_TESLevSpell_IsInList(kRef** r);
    void RemoveMatchingItem(kRef** r);
    void FUN_00470470();
    bool FUN_008256d0();
};

struct kContainer
{
    int unk0;
    kNodeT<kRef> head;
    void AddRegion(kRef* r);
};

struct kS8
{
    int a, b;
    kS8(int v);
    kS8(const kS8& o);
    ~kS8();
};
void __cdecl Interface_SetRegionText(kRef* r, kS8 s, int a);
void __cdecl FUN_0082d7c0();

struct kArea
{
    int unk00, unk04, unk08, unk0c;
    kP3 pos;
};

struct kSelf
{
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
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual kP3* v1f4();
    virtual void v1f8();
    virtual void v1fc(int a);
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual bool v22c(int a);
    virtual bool v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual bool v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void v3fc();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual void v420();
    virtual void v424();
    virtual void v428();
    virtual void v42c();
    virtual void v430();
    virtual void v434();
    virtual void v438();
    virtual void v43c();
    virtual void v440();
    virtual void v444();
    virtual void v448();
    virtual void v44c();
    virtual void v450();
    virtual void v454();
    virtual void v458();
    virtual void v45c();
    virtual void v460();
    virtual void v464();
    virtual void v468();
    virtual void v46c();
    virtual void v470();
    virtual void v474();
    virtual void v478();
    virtual void v47c();
    virtual void v480();
    virtual void v484();
    virtual void v488();
    virtual void v48c();
    virtual void v490();
    virtual void v494();
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
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
    int unk410;
    int unk414;
    int unk418;
    int unk41C;
    int unk420;
    int unk424;
    int unk428;
    int unk42C;
    int unk430;
    int unk434;
    int unk438;
    int unk43C;
    int unk440;
    int unk444;
    int unk448;
    int unk44C;
    int unk450;
    int unk454;
    int unk458;
    int unk45C;
    int unk460;
    int unk464;
    int unk468;
    int unk46C;
    int unk470;
    int unk474;
    int unk478;
    int unk47C;
    int unk480;
    int unk484;
    int unk488;
    int unk48C;
    int unk490;
    int unk494;
    int unk498;
    int unk49C;
    int unk4A0;
    int unk4A4;
    int unk4A8;
    int unk4AC;
    int unk4B0;
    int unk4B4;
    int unk4B8;
    int unk4BC;
    int unk4C0;
    int unk4C4;
    int unk4C8;
    int unk4CC;
    int unk4D0;
    int unk4D4;
    int unk4D8;
    int unk4DC;
    int unk4E0;
    int unk4E4;
    int unk4E8;
    int unk4EC;
    int unk4F0;
    int unk4F4;
    int unk4F8;
    int unk4FC;
    int unk500;
    int unk504;
    int unk508;
    int unk50C;
    int unk510;
    int unk514;
    int unk518;
    int unk51C;
    int unk520;
    int unk524;
    int unk528;
    int unk52C;
    int unk530;
    int unk534;
    int unk538;
    int unk53C;
    int unk540;
    int unk544;
    int unk548;
    int unk54C;
    int unk550;
    int unk554;
    int unk558;
    int unk55C;
    int unk560;
    int unk564;
    int unk568;
    int unk56C;
    int unk570;
    int unk574;
    int unk578;
    int unk57C;
    int unk580;
    int unk584;
    int unk588;
    int unk58C;
    int unk590;
    int unk594;
    int unk598;
    int unk59C;
    int unk5A0;
    int unk5A4;
    int unk5A8;
    int unk5AC;
    int unk5B0;
    int unk5B4;
    int unk5B8;
    int unk5BC;
    int unk5C0;
    int unk5C4;
    int unk5C8;
    int unk5CC;
    int unk5D0;
    int unk5D4;
    int unk5D8;
    int unk5DC;
    int unk5E0;
    int unk5E4;
    int unk5E8;
    int unk5EC;
    int unk5F0;
    int unk5F4;
    int unk5F8;
    int unk5FC;
    int unk600;
    int unk604;
    int unk608;
    int unk60C;
    int unk610;
    int unk614;
    int unk618;
    int unk61C;
    int unk620;
    int unk624;
    int unk628;
    int unk62C;
    int unk630;
    int unk634;
    int unk638;
    int unk63C;
    int unk640;
    int unk644;
    int unk648;
    int unk64C;
    int unk650;
    int unk654;
    int unk658;
    int unk65C;
    int unk660;
    int unk664;
    int unk668;
    int unk66C;
    int unk670;
    int unk674;
    int unk678;
    int unk67C;
    int unk680;
    int unk684;
    int unk688;
    int unk68C;
    int unk690;
    int unk694;
    int unk698;
    int unk69C;
    int unk6A0;
    int unk6A4;
    int unk6A8;
    int unk6AC;
    int unk6B0;
    int unk6B4;
    int unk6B8;
    int unk6BC;
    int unk6C0;
    int unk6C4;
    int unk6C8;
    int unk6CC;
    int unk6D0;
    int unk6D4;
    int unk6D8;
    int unk6DC;
    int unk6E0;
    int unk6E4;
    int unk6E8;
    int unk6EC;
    int unk6F0;
    int unk6F4;
    int unk6F8;
    int unk6FC;
    int unk700;
    int unk704;
    int unk708;
    int unk70C;
    int unk710;
    int unk714;
    int unk718;
    int unk71C;
    int unk720;
    int unk724;
    int unk728;
    int unk72C;
    int unk730;
    int unk734;
    int unk738;
    int unk73C;
    int unk740;
    int unk744;
    int unk748;
    int unk74C;
    int unk750;
    int unk754;
    int unk758;
    int unk75C;
    kRef* m760;
    kContainer m764;
    int unk76C;
    int unk770;
    kRList m774;
    int unk778;
    int unk77C;
    int unk780;
    int unk784;
    int unk788;
    int unk78C;
    int unk790;
    int unk794;
    int unk798;
    char m79c;
    char m79d;
    short unk79e;
    kP3 m7a0;
    kTyped* m7ac;
    kO* m7b0;
    int m7b4;
    int unk7B8;
    int unk7BC;
    int unk7C0;
    int unk7C4;
    int unk7C8;
    int unk7CC;
    int unk7D0;
    int unk7D4;
    int unk7D8;
    int unk7DC;
    int unk7E0;
    int unk7E4;
    int unk7E8;
    int unk7EC;
    int unk7F0;
    int unk7F4;
    int unk7F8;
    int unk7FC;
    int unk800;
    int unk804;
    int unk808;
    int unk80C;
    int unk810;
    int unk814;
    int unk818;
    int unk81C;
    int unk820;
    int unk824;
    int unk828;
    int unk82C;
    int unk830;
    int unk834;
    int unk838;
    int unk83C;
    int unk840;
    int unk844;
    int unk848;
    int unk84C;
    int unk850;
    int unk854;
    int unk858;
    int unk85C;
    int unk860;
    int unk864;
    int unk868;
    int unk86C;
    int unk870;
    int unk874;
    int unk878;
    int unk87C;
    int unk880;
    int unk884;
    int unk888;
    int unk88C;
    int unk890;
    int unk894;
    int unk898;
    int unk89C;
    int unk8A0;
    int unk8A4;
    int unk8A8;
    int unk8AC;
    int unk8B0;
    int unk8B4;
    int unk8B8;
    int unk8BC;
    int unk8C0;
    int unk8C4;
    int unk8C8;
    int unk8CC;
    int unk8D0;
    int unk8D4;
    int unk8D8;
    int unk8DC;
    int unk8E0;
    int unk8E4;
    int unk8E8;
    int unk8EC;
    int unk8F0;
    int unk8F4;
    int unk8F8;
    int unk8FC;
    int unk900;
    int unk904;
    int unk908;
    int unk90C;
    int unk910;
    int unk914;
    int unk918;
    int unk91C;
    int unk920;
    int unk924;
    int unk928;
    int unk92C;
    int unk930;
    int unk934;
    int unk938;
    int unk93C;
    int unk940;
    int unk944;
    int unk948;
    int unk94C;
    int unk950;
    int unk954;
    int unk958;
    int unk95C;
    int unk960;
    int unk964;
    int unk968;
    int unk96C;
    int unk970;
    int unk974;
    int unk978;
    int unk97C;
    int unk980;
    int unk984;
    int unk988;
    int unk98C;
    int unk990;
    int unk994;
    int unk998;
    int unk99C;
    int unk9A0;
    int unk9A4;
    int unk9A8;
    int unk9AC;
    int unk9B0;
    int unk9B4;
    int unk9B8;
    int unk9BC;
    int unk9C0;
    int unk9C4;
    int unk9C8;
    int unk9CC;
    int unk9D0;
    int unk9D4;
    int unk9D8;
    int unk9DC;
    int unk9E0;
    int unk9E4;
    int unk9E8;
    int unk9EC;
    int unk9F0;
    int unk9F4;
    int unk9F8;
    int unk9FC;
    int unkA00;
    int unkA04;
    int unkA08;
    int unkA0C;
    int unkA10;
    int unkA14;
    int unkA18;
    int unkA1C;
    int unkA20;
    int unkA24;
    int unkA28;
    int unkA2C;
    int unkA30;
    int unkA34;
    int unkA38;
    int unkA3C;
    int unkA40;
    int unkA44;
    int unkA48;
    int unkA4C;
    int unkA50;
    int unkA54;
    int unkA58;
    int unkA5C;
    int unkA60;
    int unkA64;
    int unkA68;
    int unkA6C;
    int unkA70;
    int unkA74;
    int unkA78;
    int unkA7C;
    int unkA80;
    int unkA84;
    int unkA88;
    int unkA8C;
    int unkA90;
    int unkA94;
    int unkA98;
    int unkA9C;
    int unkAA0;
    int unkAA4;
    int unkAA8;
    int unkAAC;
    int unkAB0;
    int unkAB4;
    int unkAB8;
    int unkABC;
    int unkAC0;
    int unkAC4;
    int unkAC8;
    int unkACC;
    int unkAD0;
    int unkAD4;
    int unkAD8;
    int unkADC;
    int unkAE0;
    int unkAE4;
    int unkAE8;
    int unkAEC;
    int unkAF0;
    int unkAF4;
    int unkAF8;
    int unkAFC;
    int unkB00;
    int unkB04;
    int unkB08;
    int unkB0C;
    int unkB10;
    int unkB14;
    int unkB18;
    int unkB1C;
    int unkB20;
    int unkB24;
    int unkB28;
    int unkB2C;
    int unkB30;
    int unkB34;
    int unkB38;
    int unkB3C;
    int unkB40;
    int unkB44;
    int unkB48;
    int unkB4C;
    int unkB50;
    int unkB54;
    int unkB58;
    int unkB5C;
    int unkB60;
    int unkB64;
    int unkB68;
    int unkB6C;
    int unkB70;
    int unkB74;
    int unkB78;
    int unkB7C;
    int unkB80;
    int unkB84;
    int unkB88;
    int unkB8C;
    int unkB90;
    int unkB94;
    int unkB98;
    int unkB9C;
    int unkBA0;
    int unkBA4;
    int unkBA8;
    int unkBAC;
    int unkBB0;
    int unkBB4;
    int unkBB8;
    int unkBBC;
    int unkBC0;
    int unkBC4;
    int unkBC8;
    int unkBCC;
    int unkBD0;
    int unkBD4;
    int unkBD8;
    int unkBDC;
    int unkBE0;
    int unkBE4;
    int unkBE8;
    int unkBEC;
    int unkBF0;
    int unkBF4;
    int unkBF8;
    int unkBFC;
    int unkC00;
    int unkC04;
    int unkC08;
    int unkC0C;
    int unkC10;
    int unkC14;
    int unkC18;
    int unkC1C;
    int unkC20;
    int unkC24;
    int unkC28;
    int unkC2C;
    int unkC30;
    int unkC34;
    int unkC38;
    int unkC3C;
    int unkC40;
    int unkC44;
    int unkC48;
    int unkC4C;
    int unkC50;
    int unkC54;
    int unkC58;
    int unkC5C;
    int unkC60;
    int unkC64;
    int unkC68;
    int unkC6C;
    int unkC70;
    int unkC74;
    int unkC78;
    int unkC7C;
    int unkC80;
    int unkC84;
    int unkC88;
    int unkC8C;
    int unkC90;
    int unkC94;
    int unkC98;
    int unkC9C;
    int unkCA0;
    int unkCA4;
    int unkCA8;
    int unkCAC;
    int unkCB0;
    int unkCB4;
    int unkCB8;
    int unkCBC;
    int unkCC0;
    int unkCC4;
    int unkCC8;
    int unkCCC;
    int unkCD0;
    int unkCD4;
    int unkCD8;
    int unkCDC;
    int unkCE0;
    int unkCE4;
    int unkCE8;
    int unkCEC;
    int unkCF0;
    int unkCF4;
    int unkCF8;
    int unkCFC;
    int unkD00;
    int unkD04;
    int unkD08;
    int unkD0C;
    int unkD10;
    int unkD14;
    int unkD18;
    int unkD1C;
    int unkD20;
    int unkD24;
    int unkD28;
    int unkD2C;
    int unkD30;
    int unkD34;
    int unkD38;
    int unkD3C;
    int unkD40;
    int unkD44;
    int unkD48;
    int unkD4C;
    int unkD50;
    int unkD54;
    int unkD58;
    int unkD5C;
    int unkD60;
    int unkD64;
    int unkD68;
    int unkD6C;
    int unkD70;
    int unkD74;
    int unkD78;
    int unkD7C;
    int unkD80;
    int unkD84;
    int unkD88;
    int unkD8C;
    int unkD90;
    int unkD94;
    int unkD98;
    int unkD9C;
    int unkDA0;
    int unkDA4;
    int unkDA8;
    int unkDAC;
    int unkDB0;
    int unkDB4;
    int unkDB8;
    int unkDBC;
    int unkDC0;
    int unkDC4;
    int unkDC8;
    int unkDCC;
    int unkDD0;
    int unkDD4;
    int unkDD8;
    int unkDDC;
    int unkDE0;
    int unkDE4;
    int unkDE8;
    kDec mdec;

    kActor* FUN_008d6f30();
    void SetParentCellAndUpdateController(kActor* p);
    void PlayerCharacter_SetOccupiedRegion(kRef* r);
    struct X5
    {
        void ExtraDataList_SetMultiBoundRef();
    };
    X5* BSFile_GetDevice(int a);
    bool Actor_IsUnConscious();
    bool PlayerCharacter_IsSleeping();
    kArea* FUN_00891170();
    void* TESObjectREFR_GetWorldSpace();
    void PlayerCharacter_ResetAudioMarkerList();
    void PlayerCharacter_ResetMapMarkerStructList();
    void PlayerCharacter_SetParentCell(kActor* p);
};

// @fnv 0x0094cae0
// src: COMMUNITY 0x0094cae0
void kSelf::PlayerCharacter_SetParentCell(kActor* p)
{
    if (p == FUN_008d6f30())
        return;
    if (!TESWaterSystem_GetCameraInPlaceableWater())
        TESWaterSystem_SetCameraRelevantWaterHeight((p && p->FUN_004518e0()) ? p->TESObjectCELL_GetWaterHeight() : DAT_01015f5c);
    BSFile_GetDevice(0)->ExtraDataList_SetMultiBoundRef();
    SetParentCellAndUpdateController(p);
    if (p)
    {
        if (!p->FUN_00425fd0())
            PlayerCharacter_SetOccupiedRegion(0);
        FalloutRadio_NewCellEntered();
        m7b4 = p->TESObjectCELL_GetMusicType(0);
        kPA* pa = p->TESObjectCELL_GetbhkWorld();
        if (pa)
        {
            kPA2* pa2 = pa->FUN_0045cd60();
            pa2->SetFlags_004893c0(1);
        }
        v1fc(0);
        if (FUN_008d6f30() && FUN_008d6f30()->TESObjectCELL_GetbhkWorld() && FUN_00622a70(DecalCaster_GetMaxDecalWidthLarge(), 0))
            FUN_00622a70(DecalCaster_GetMaxDecalWidthLarge(), 1)->DecalCaster_Add(FUN_008d6f30()->TESObjectCELL_GetbhkWorld());
        if (FUN_008d6f30() && FUN_008d6f30()->TESObjectCELL_GetbhkWorld() && FUN_00622a70(DecalCaster_GetMaxDecalWidthSmall(), 0))
            FUN_00622a70(DecalCaster_GetMaxDecalWidthSmall(), 1)->DecalCaster_Add(FUN_008d6f30()->TESObjectCELL_GetbhkWorld());
        if (mdec.FUN_00822510(0))
        {
            kZ* z = new kZ;
            z->bhkSphereShape_Init(DAT_01017d00);
            kH h;
            h.bhkRigidBodyCinfo_SetShape(z);
            int flags = 0x30000;
            flags |= 0x21;
            h.bhkRigidBodyCinfo_SetCollisionFilter(flags);
            mdec.FUN_0066b0d0(new kW(&h));
            mdec.Modelloader_GetReferencedThis()->bhkRigidBody_SetActive(1);
            mdec.Modelloader_GetReferencedThis()->ve4(4);
            mdec.Modelloader_GetReferencedThis()->bhkWorldObject_GetCollidableRw()->NiAlphaProperty_SetTestRef(9);
            kP4 q;
            kP3 r = *v1f4();
            NI2HK(&q, &r);
            mdec.Modelloader_GetReferencedThis()->bhkRigidBody_SetNiPosition(&r);
        }
        mdec.Modelloader_GetReferencedThis()->v9c(FUN_008d6f30()->TESObjectCELL_GetbhkWorld());
        bool busy = Actor_IsUnConscious() || v22c(0) || v2e8() || v230();
        bool idle = !busy && !PlayerCharacter_IsSleeping();
        if (idle)
            v494();
        DAT_011c3b3c->UpdateRelationStates(0);
        FUN_0046dd00(p->TESObjectCELL_GetClimate(0))->FUN_0063c8f0();
        BSShaderManager_SetImageSpaceParameters(p->TESObjectCELL_GetUsableImageSpace()->FUN_00500940());
        kCell* cell = p->FUN_0054ddd0();
        bool found = false;
        m79c = 0;
        if (m7b0)
        {
            m7b0->NiTArray_char_NiTMallocInterface_char_RemoveAll();
            delete m7b0;
            m7b0 = 0;
        }
        int ix = p->FUN_00544c30();
        int iy = p->FUN_00544c60();
        float x0 = ix << 12;
        float x1 = x0 + DAT_01017a10;
        float y0 = iy << 12;
        float y1 = y0 + DAT_01017a10;
        kP2 c0(x0, y0);
        kP2 c1(x0, y1);
        kP2 c2(x1, y0);
        kP2 c3(x1, y1);
        m774.FUN_00470470();
        DAT_011dd380 = 0;
        kRList2 list;
        kNodeT<kRef>* n = &m764 ? &m764.head : 0;
        while (n && *n->Get())
        {
            kRef* x = *n->Get();
            if (x)
                list.FUN_005ae3d0(&x);
            n = n->Next();
        }
        m764.head.FUN_00470470();
        kE* best = 0;
        kRefList* rl = p->FUN_00547110(1);
        kRef* ref;
        for (kNodeT<kRef>* it = rl ? &rl->head : 0; it && (ref = *it->Get()) != 0; it = it->Next())
        {
            kP2 pos(&FUN_00891170()->pos);
            kNodeT<kRef>* sub = 0;
            if (ref->FUN_00440d80() || (ref->BGSSaveFormBuffer_GetForm() && ref->BGSSaveFormBuffer_GetForm() != TESObjectREFR_GetWorldSpace()) ||
                !ref->FUN_00441110() || ref->FUN_00441110()->FUN_008256d0())
                continue;
            bool done = false;
            kShape* sh;
            for (kNodeT<kShape>* m = ref->FUN_00441110(); !done && m && (sh = *m->Get()) != 0; m = m->Next())
            {
                if (sh->TESRegionPointList_IsInsideRegion(&pos))
                {
                    m764.AddRegion(ref);
                    if (list.BSSimpleList_TESLevSpell_IsInList(&ref))
                        list.RemoveMatchingItem(&ref);
                    kE* e = ref->NiAVObject_GetParent(7)->TESRegionDataList_Find();
                    if (e)
                    {
                        if (e->TESRegionData_GetOverride() && (!best || (best != e && best->TESRegionData_GetPriority() < e->TESRegionData_GetPriority())))
                        {
                            m774.FUN_00470470();
                            best = e;
                        }
                        if (!best || best == e)
                        {
                            sub = e->GetOffsetC();
                            while (sub && *sub->Get())
                            {
                                m774.FUN_005ae3d0(sub->Get());
                                sub = sub->Next();
                            }
                            if (e->v30())
                                DAT_011dd380 = e;
                        }
                    }
                    if (ref->TESForm_GetHasSpokenFlag())
                    {
                        found = true;
                        if (sh->TESRegionPointList_IsInsideRegion(&c0) && sh->TESRegionPointList_IsInsideRegion(&c1) && sh->TESRegionPointList_IsInsideRegion(&c2) &&
                            sh->TESRegionPointList_IsInsideRegion(&c3))
                            m79c = 1;
                    }
                    if (m760)
                    {
                        kE* a = m760->NiAVObject_GetParent(3)->TESRegionDataList_Find();
                        kE* b = ref->NiAVObject_GetParent(3)->TESRegionDataList_Find();
                        if (b && (!a || (b->TESRegionData_GetOverride() && !a->TESRegionData_GetOverride()) ||
                                  (b->TESRegionData_GetOverride() == a->TESRegionData_GetOverride() && b->TESRegionData_GetPriority() > a->TESRegionData_GetPriority())))
                            PlayerCharacter_SetOccupiedRegion(ref);
                    }
                    else
                    {
                        PlayerCharacter_SetOccupiedRegion(ref);
                    }
                    done = true;
                }
            }
            if (ref->TESForm_GetHasSpokenFlag())
            {
                if (!m7b0)
                    m7b0 = new kO(1, 1);
                m7b0->FUN_0096a610(&ref);
            }
        }
        if (*DAT_011e08e0.FUN_00408d60() && cell && cell->IsFlag8Set() && !DAT_011dea10->TES_CellTestRunning() && !found)
        {
            kTyped* t39 = 0;
            kTyped* t41 = 0;
            if (m7ac)
            {
                switch (m7ac->FUN_00401170())
                {
                case 0x39:
                    t39 = m7ac;
                    break;
                case 0x41:
                    t41 = m7ac;
                    break;
                }
            }
            if (t39 && t39 != (kTyped*)p)
                m79d = 1;
            else if (t41 && t41 != (kTyped*)p->FUN_0054ddd0())
                m79d = 1;
            else
            {
                kP3 d = *v1f4();
                d.Subtract(&m7a0);
                if (d.FUN_00457990() > DAT_01016968)
                    m79d = 1;
            }
        }
        kE* e4 = m760 ? m760->NiAVObject_GetParent(4)->TESRegionDataList_Find() : 0;
        Interface_SetRegionText(m760, e4 ? e4->v2c() : 0, 1);
        PlayerCharacter_ResetAudioMarkerList();
        PlayerCharacter_ResetMapMarkerStructList();
        kNodeT<kRef>* n2 = &list.head;
        while (n2 && *n2->Get())
        {
            kRef* x = *n2->Get();
            if (x)
            {
                kE* e = x->NiAVObject_GetParent(8)->TESRegionDataList_Find();
                if (e)
                {
                    kE* e2 = e;
                    e2->TESRegionDataImposter_SetImpostersVisible(0, 0);
                }
            }
            n2 = n2->Next();
        }
        n2 = &m764 ? &m764.head : 0;
        while (n2 && *n2->Get())
        {
            kRef* x = *n2->Get();
            if (x)
            {
                kE* e = x->NiAVObject_GetParent(8)->TESRegionDataList_Find();
                if (e)
                {
                    kE* e2 = e;
                    kNodeT<kRef>* k = e2->FUN_00413f40();
                    while (k)
                    {
                        if (*k->Get())
                        {
                            FUN_008d6f30()->FUN_00548230(*k->Get(), 0);
                            TESRegionDataImposter_SetImposterVisible(*k->Get(), 1, 0);
                        }
                        k = k->Next();
                    }
                }
            }
            n2 = n2->Next();
        }
        list.FUN_00470470();
    }
    else
    {
        m774.FUN_00470470();
        FUN_0082d7c0();
    }
}
}  // namespace fnv_0094cae0
