#include "../../../include/hkArray.h"

// src/fallout/ai/actor_o2_variant_gs_nogs_variant.cpp - flag-variant unit created 2026-10-29 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/fallout/ai/actor_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
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
#include "../../../include/hkBool.h"
#include "../../../include/hkMemoryRouter.h"
#include "../../../include/hkArray.h"
#include "../../../include/hkVector4.h"
#include "../../../include/hkQuaternion.h"
#include "../../../include/hkQsTransform.h"
#include "../../../include/hkaSkeleton.h"
#include "../../../include/hkaPose.h"

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
struct Head
{
    hkBool a, b;
    int c;
    Head() : a(true), b(true), c(0)
    {}
};

struct FUN_00c7bfd0
{
    int m_00, m_04, m_08;
    float m_0c;
    float m_10;
    hkArray<void*> m_14, m_20, m_2c;
    Head m_38;
    int m_40, m_44, m_48;
    float m_4c, m_50;
    FUN_00c7bfd0();
};
// FUN_00cb9650 @ 0x00cb9650, 97 bytes, __cdecl caller-pops
// flags: /MT /O2 /GS /EHsc /Gy
// Recursive child-visitor: controller fetch/set via members, virtual node
// fetch (vtable slot 3), loop over children (ptr @0xA0, count u16 @0xA6).
struct FUN_00cb9650_Object
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual NiNode* vf0C();

    void* NiObjectNET_GetController(const void* typeInfo);
    void NiObjectNET_RemoveController(int value);
};
extern const char DAT_012683f4[];
void __cdecl bhkForceController_RemoveForce(FUN_00cb9650_Object* object);
#include <xmmintrin.h>
#include "../../../include/MemoryManager.h"
#include "../../../include/bhkRagdollController.h"
extern "C" __declspec(align(16)) __m128 DAT_010c71b0;
struct RagController
{
    unsigned char& controlFlag()
    {
        return *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0x43);
    }
    unsigned char& activeFlag()
    {
        return *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0xb1);
    }
    unsigned char& stateFlag()
    {
        return *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0xb3);
    }
    __m128& poseA()
    {
        return *reinterpret_cast<__m128*>(reinterpret_cast<char*>(this) + 0x120);
    }
    __m128& poseB()
    {
        return *reinterpret_cast<__m128*>(reinterpret_cast<char*>(this) + 0x170);
    }
    unsigned char& dirtyA()
    {
        return *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0x130);
    }
    unsigned char& dirtyB()
    {
        return *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0x180);
    }
    void bhkRagdollController_SetLookIKActive(unsigned char enabled);
};
extern "C" double __cdecl sqrt(double x);
__int64 __cdecl BSPrecisionTimer_GetTimer();
extern float DAT_011b02e4;
extern float DAT_011ac39c;
struct NodeC
{
    int n000;
    int n004;
    int n008;
    int n00c;
    int n010;
    int n014;
    NodeC* parent;
    int n01c;
    int n020;
    int n024;
    int n028;
    int n02c;
    int n030;
    Xform local;
    Xform world;
};
struct InnerC
{
    int i000;
    int i004;
    int i008;
    int i00c;
    int i010;
    int i014;
    int i018;
    unsigned int count;
};
struct MidC
{
    int m000;
    int m004;
    int m008;
    int m00c;
    int m010;
    int m014;
    int m018;
    int m01c;
    int m020;
    int m024;
    int m028;
    InnerC* inner;
    void hkaRagdollInstance_getPoseModelSpace(void*, void*);
};
struct Obj248
{
    int hkaPoseMatchingUtility_findBestCandidatePoseIndex(void*, float*);
};
struct Obj250
{
    void bhkPoseArray_CreatePoseForRagdoll(void*, void*, int);
};
struct ScrapMarker
{
    char* p;
    unsigned int size;
    ScrapMarker(unsigned int count)
    {
        char** top = (char**)hkMemoryRouter_getInstance();
        unsigned int size = (count * 48 + 0x7f) & ~0x7fu;
        char* old = *top;
        *top = old + size;
        p = old;
    }
    ~ScrapMarker()
    {
        *(char**)hkMemoryRouter_getInstance() = p;
    }
};
struct Cls
{
    int u000;
    bool m_004;
    float m_008;
    int m_00c;
    int u010;
    int u014;
    int u018;
    int u01c;
    int u020;
    int u024;
    int u028;
    int u02c;
    int u030;
    int u034;
    int u038;
    int u03c;
    int u040;
    int u044;
    MidC* m_048;
    int u04c;
    int u050;
    int u054;
    NodeC* m_058;
    int u05c;
    int u060;
    int u064;
    int u068;
    int u06c;
    int u070;
    int u074;
    int u078;
    int u07c;
    int u080;
    int u084;
    int u088;
    int u08c;
    int u090;
    int u094;
    int u098;
    int u09c;
    int u0a0;
    int u0a4;
    int u0a8;
    int u0ac;
    int u0b0;
    int u0b4;
    int u0b8;
    int u0bc;
    int u0c0;
    int u0c4;
    int u0c8;
    int u0cc;
    int u0d0;
    int u0d4;
    int u0d8;
    int u0dc;
    int u0e0;
    int u0e4;
    int u0e8;
    int u0ec;
    int u0f0;
    int u0f4;
    int u0f8;
    int u0fc;
    int u100;
    int u104;
    int u108;
    int u10c;
    int u110;
    int u114;
    int u118;
    int u11c;
    int u120;
    int u124;
    int u128;
    int u12c;
    int u130;
    int u134;
    int u138;
    int u13c;
    int u140;
    int u144;
    int u148;
    int u14c;
    int u150;
    int u154;
    int u158;
    int u15c;
    int u160;
    int u164;
    int u168;
    int u16c;
    int u170;
    int u174;
    int u178;
    int u17c;
    int u180;
    int u184;
    int u188;
    int u18c;
    int u190;
    int u194;
    int u198;
    int u19c;
    int u1a0;
    int u1a4;
    int u1a8;
    int u1ac;
    int u1b0;
    int u1b4;
    int u1b8;
    int u1bc;
    int u1c0;
    int u1c4;
    int u1c8;
    int u1cc;
    int u1d0;
    int u1d4;
    int u1d8;
    int u1dc;
    int u1e0;
    int u1e4;
    int u1e8;
    int u1ec;
    int u1f0;
    int u1f4;
    int u1f8;
    int u1fc;
    int u200;
    int u204;
    int u208;
    int u20c;
    int u210;
    int u214;
    int u218;
    int u21c;
    int u220;
    int u224;
    int u228;
    int u22c;
    int u230;
    int u234;
    int u238;
    int u23c;
    int u240;
    int u244;
    Obj248* m_248;
    int u24c;
    Obj250* m_250;
    int u254;
    int m_258;
    int u25c;
    __int64 m_260;
    __int64 m_268;
    NiPoint3 m_pos;
    float m_27c;
    float m_280;
    bool m_284;
    int m_288;

    void bhkRagdollController_DoPoseMatching(void* a1, void* a2, bool* a3);
};
extern __m128 g_hkQuadZero;
struct RagMotion
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    bool unk14;
};
struct RagRigid
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
    virtual RagMotion* GetMotion();
};
struct RagBone
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    RagRigid* rigid;
};
struct RagSkelInfo
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int boneCount;
};
struct RagSkel
{
    int unk00;
    int unk04;
    int unk08;
    RagSkelInfo* info;
};
struct RagEntry
{
    int unk00;
    int unk04;
    void* owner;
};
struct RagSystem
{
    void bhkWorld_Add_00c6b320(RagEntry* entry);
};
struct RagWorld
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
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
    RagSystem* system;
};
struct RagWorldRef
{
    int unk00;
    int unk04;
    RagWorld* world;
};
struct RagCtrl48
{
    int unk00;
    int unk04;
    RagWorldRef** worldRef;
    int unk0c;
    int unk10;
    RagEntry** entries;
    int entryCount;
    void* GetOwner()
    {
        return entries[0] ? entries[0]->owner : 0;
    }
    RagWorld* GetWorld()
    {
        RagWorldRef* wr = *worldRef;
        return wr ? wr->world : 0;
    }
    __forceinline void Reattach()
    {
        void* owner = GetOwner();
        RagWorld* w = GetWorld();
        if (!w)
            return;
        if (owner)
            return;
        RagSystem* sys = w->system;
        for (int i = 0; i < entryCount; i++)
        {
            RagEntry* e = entries[i];
            if (!e->owner)
                sys->bhkWorld_Add_00c6b320(e);
        }
    }
};
struct RagdollCtl
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
    char unk040;
    bool unk41;
    bool active;
    bool unk43;
    int unk044;
    RagCtrl48* ctrl48;
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
    RagBone** bones;
    int unk0a8;
    int unk0ac;
    char unk0b0;
    char unk0b1;
    bool unkb2;
    bool unkb3;
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
    __m128 vec120;
    bool unk130;
    char unk131;
    char unk132;
    char unk133;
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
    __m128 vec170;
    bool unk180;
    char unk181;
    char unk182;
    char unk183;
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
    float unk1b8;
    bool unk1bc;
    char unk1bd;
    char unk1be;
    char unk1bf;
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
    float unk1e8;
    bool unk1ec;
    char unk1ed;
    char unk1ee;
    char unk1ef;
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
    char unk21c;
    char unk21d;
    bool unk21e;
    char unk21f;
    char unk220;
    bool unk221;
    bool unk222;
    bool unk223;
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
    char unk28c;
    bool unk28d;
    char unk28e;
    bool unk28f;
    float unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    RagSkel* skel;
    int unk2a8;
    int unk2ac;
    void bhkRagdollController_SetRagdollFeedbackActive(bool);
    void bhkRagdollController_DisableRagdollAnim(bool);
};
static unsigned char* hkVector4isOk(unsigned char* out, const float* src, int count);
unsigned char* S00c7f4a0_Call(unsigned char* out, const float* src, int count);
struct HkFloatCheck
{
    void hkVector4_isOk4(bool* pOut);
};
static inline bool IsFiniteFloat(float r)
{
    return ((*(unsigned int*)&r) & 0x7f800000) != 0x7f800000;
}
static __declspec(noinline) bool* CheckFloatsValid(const float* pData, int iCount, bool* pOut)
{
    for (int i = 0; i < iCount; i++)
        if (!IsFiniteFloat(pData[i]))
        {
            *pOut = false;
            return pOut;
        }
    *pOut = true;
    return pOut;
}
extern int DAT_01267b70;
struct S_Out
{
    int unk00;
    int unk04;
};
struct S_Inner
{
    int bhkWorldObject_GetAVObject(int arg);
};
struct S_Val
{
    int unk00;
    int unk04;
    int unk08;
};
struct S_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    signed char unk10;
    char unk11;
    char unk12;
    char unk13;
    char unk14;
    char unk15;
    char unk16;
    char unk17;
    unsigned char unk18;
};
struct S_Elem
{
    int unk00;
    int unk04;
    int unk08;
    S_Inner* unk0c;
};
int* __cdecl bhkWorldObject_GetProperty(S_Out* out, void* ptr, void* tag);
inline void* GetOwner(S_Obj* c)
{
    return (char*)c + c->unk10;
}
inline S_Elem* GetEntity(S_Obj* c)
{
    return c->unk18 == 1 ? (S_Elem*)GetOwner(c) : 0;
}
inline S_Elem* GetPhantom(S_Obj* c)
{
    return c->unk18 == 2 ? (S_Elem*)GetOwner(c) : 0;
}
int __cdecl bhkUtilFunctions_GetNiAVObject(S_Obj* p);
extern const __m128 DAT_010c71e0;
struct __declspec(align(16)) MVec4
{
    __m128 q;
    __forceinline void Rotate(const MVec4& rotation, const MVec4& position)
    {
        __m128 scalar = _mm_shuffle_ps(rotation.q, rotation.q, 255);
        __m128 factor = _mm_add_ps(DAT_010c71e0, _mm_mul_ps(scalar, scalar));
        __m128 sum = _mm_mul_ps(position.q, factor);
        __m128 product = _mm_mul_ps(rotation.q, position.q);
        __m128 dot = _mm_add_ss(_mm_shuffle_ps(product, product, 85), product);
        dot = _mm_add_ss(_mm_shuffle_ps(product, product, 170), dot);
        dot = _mm_shuffle_ps(dot, dot, 0);
        sum = _mm_add_ps(sum, _mm_mul_ps(dot, rotation.q));
        __m128 cross = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(rotation.q, rotation.q, 201), _mm_shuffle_ps(position.q, position.q, 210)),
            _mm_mul_ps(_mm_shuffle_ps(rotation.q, rotation.q, 210), _mm_shuffle_ps(position.q, position.q, 201)));
        sum = _mm_add_ps(sum, _mm_mul_ps(scalar, cross));
        q = _mm_add_ps(sum, sum);
    }
    __forceinline void Add(const MVec4& a)
    {
        q = _mm_add_ps(q, a.q);
    }
};
struct BoneTransform
{
    MVec4 position;
    MVec4 rotation;
    MVec4 scale;
};
struct BoneDesc
{
    int unk00;
    unsigned char locked;
};
struct BoneFlags
{
    unsigned int bits;
    __forceinline BoneFlags& Set(unsigned int mask)
    {
        bits |= mask;
        return *this;
    }
    __forceinline BoneFlags& Clear(unsigned int mask)
    {
        bits &= ~mask;
        return *this;
    }
};
struct SkeletonModel
{
    int unk00, unk04, unk08;
    short* parents;
    int unk10, unk14;
    BoneDesc* bones;
    int count;
    int unk20;
    BoneTransform* reference;
};
struct PoseState
{
    SkeletonModel* model;
    BoneTransform* local;
    int unk08, unk0c;
    BoneTransform* world;
    int unk14, unk18;
    unsigned int* flags;
    int count;
    int unk24;
    bool ready;
    void hkaPose_syncModelSpace();
    void ProcessEntries_00cda4c0();
};
struct C7C2B0_Pair
{
    int a;
    int b;
};
typedef hkArray<C7C2B0_Pair> C7C2B0_Array;
template<> __forceinline hkArray<C7C2B0_Pair>::~hkArray()
{
        Holder* holder = _FUN_00c85750();
        hkMemoryAllocator* heap = (hkMemoryAllocator*)holder->p;
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            int cap = m_iCapacityState & 0x3fffffff;
            C7C2B0_Pair* data = m_data;
            heap->bufFree(data, cap * sizeof(C7C2B0_Pair));
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    
}
struct ShapeArrays
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    C7C2B0_Array m_iThirdValue;
    C7C2B0_Array m_kPointB;
    C7C2B0_Array m_kPointA;
    ~ShapeArrays();
};
extern "C" void _ReadWriteBarrier(void);

__forceinline void FreeObjX(void* p, unsigned int n)
{
    Holder* h = _FUN_00c85750();
    h->p->f2(p, n);
}
template <class T> struct HkArrX
{
    T* m_data;
    int m_iElementCount;
    int m_capFlags;
    ~HkArrX()
    {
        hkMemoryRouter* h = (hkMemoryRouter*)_FUN_00c85750();
        HkAllocator* alloc = reinterpret_cast<HkAllocator*>(h->GetAllocator());
        m_iElementCount = 0;
        if (!(m_capFlags & 0x80000000))
            HkDeallocT<T>(alloc, m_data, m_capFlags & 0x3fffffff);
        m_data = 0;
        m_capFlags = 0x80000000;
    }
};
struct HkRef
{
    void removeReference();
};
struct RefObj
{
    virtual void vf0();
    virtual void vf1();
    long m_iObjectReferenceCount;
};
struct RefPtr
{
    RefObj* m_p;
    void Reset()
    {
        RefObj* p = m_p;
        if (p)
        {
            if (InterlockedDecrement(&p->m_iObjectReferenceCount) == 0)
                p->vf1();
            m_p = 0;
        }
    }
    ~RefPtr()
    {
        RefObj* p = m_p;
        if (p)
        {
            if (InterlockedDecrement(&p->m_iObjectReferenceCount) == 0)
                p->vf1();
        }
    }
};
extern int DAT_0109b220;
struct FixedStr9
{
    char* m_h;
    char* GetChars()
    {
        return m_h;
    }
    ~FixedStr9()
    {
        if (m_h != (char*)DAT_0109b220)
            InterlockedDecrement((long volatile*)(m_h - 8));
    }
};
struct PolyBase
{
    virtual void vf0(void* p);
    virtual void vf1(void* p);
    virtual void vf2(void* p);
    virtual void vf3(void* p);
};
struct PolyArr : PolyBase
{
    void* m_data;
    int m_iElementCount;
    int m_cap;
    ~PolyArr()
    {
        PolyBase* b = this;
        if (m_data)
        {
            b->vf2(m_data);
            m_data = 0;
            m_cap = 0;
            m_iElementCount = 0;
        }
    }
};
struct T48
{
    int m_00, m_04, m_08, m_0c, m_10, m_14, m_18, m_1c, m_20, m_24, m_28, m_2c;
};
struct T32
{
    int m_00, m_04, m_08, m_0c, m_10, m_14, m_18, m_1c;
};
struct T208
{
    HkRef* m_p0;
    int m_004;
    int m_008;
    int m_00c;
    int m_010;
    int m_014;
    int m_018;
    int m_01c;
    int m_020;
    int m_024;
    int m_028;
    int m_02c;
    int m_030;
    int m_034;
    int m_038;
    int m_03c;
    int m_040;
    int m_044;
    int m_048;
    int m_04c;
    int m_050;
    int m_054;
    int m_058;
    int m_05c;
    int m_060;
    int m_064;
    int m_068;
    int m_06c;
    int m_070;
    int m_074;
    int m_078;
    int m_07c;
    int m_080;
    int m_084;
    int m_088;
    int m_08c;
    int m_090;
    int m_094;
    int m_098;
    int m_09c;
    int m_0a0;
    int m_0a4;
    int m_0a8;
    int m_0ac;
    int m_0b0;
    int m_0b4;
    int m_0b8;
    int m_0bc;
    int m_0c0;
    int m_0c4;
    int m_0c8;
    int m_0cc;
};
struct Arr32
{
    HkArrX<T32> m_aiIndexedValues;
    int m_0c, m_10, m_14, m_18, m_1c, m_20, m_24, m_28, m_2c;
};
struct X48
{
    void ClearArrays();
};
struct MapStd
{
    void FUN_00e92760(char* key, void** out);
    void FUN_00e91fd0(char* key);
};
extern MapStd DAT_011b02f0;
extern MapStd DAT_011b0300;
struct BaseC7
{
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual ~BaseC7()
    {}
};
struct FUN_00c7d900 : BaseC7
{
    int m_004;
    int m_008;
    int m_00c;
    int m_010;
    int m_014;
    int m_018;
    int m_01c;
    int m_020;
    int m_024;
    int m_028;
    int m_02c;
    int m_030;
    int m_034;
    int m_038;
    int m_03c;
    int m_040;
    int m_044;
    HkRef* m_p48;
    X48* m_p4c;
    int m_050;
    FUN_00c7c030* m_p54;
    int m_058;
    int m_05c;
    int m_060;
    int m_064;
    int m_068;
    int m_06c;
    int m_070;
    int m_074;
    int m_078;
    int m_07c;
    int m_080;
    RefPtr m_84;
    FUN_00c7c030* m_p88;
    int m_08c;
    int m_090;
    HkArrX<T48> m_94;
    PolyArr m_a0;
    int m_0b0;
    int m_0b4;
    int m_0b8;
    int m_0bc;
    int m_0c0;
    int m_0c4;
    int m_0c8;
    int m_0cc;
    int m_0d0;
    int m_0d4;
    int m_0d8;
    int m_0dc;
    int m_0e0;
    int m_0e4;
    int m_0e8;
    int m_0ec;
    int m_0f0;
    int m_0f4;
    int m_0f8;
    int m_0fc;
    int m_100;
    int m_104;
    int m_108;
    int m_10c;
    int m_110;
    int m_114;
    int m_118;
    int m_11c;
    int m_120;
    int m_124;
    int m_128;
    int m_12c;
    int m_130;
    int m_134;
    int m_138;
    int m_13c;
    int m_140;
    int m_144;
    int m_148;
    int m_14c;
    int m_150;
    int m_154;
    int m_158;
    int m_15c;
    int m_160;
    int m_164;
    int m_168;
    int m_16c;
    int m_170;
    int m_174;
    int m_178;
    int m_17c;
    int m_180;
    int m_184;
    int m_188;
    int m_18c;
    int m_190;
    int m_194;
    int m_198;
    int m_19c;
    int m_1a0;
    int m_1a4;
    int m_1a8;
    int m_1ac;
    int m_1b0;
    int m_1b4;
    int m_1b8;
    int m_1bc;
    int m_1c0;
    int m_1c4;
    int m_1c8;
    int m_1cc;
    int m_1d0;
    int m_1d4;
    int m_1d8;
    int m_1dc;
    int m_1e0;
    int m_1e4;
    int m_1e8;
    int m_1ec;
    int m_1f0;
    int m_1f4;
    int m_1f8;
    int m_1fc;
    int m_200;
    int m_204;
    int m_208;
    int m_20c;
    int m_210;
    int m_214;
    int m_218;
    int m_21c;
    int m_220;
    int m_224;
    int m_228;
    HkArrX<T208> m_22c;
    int m_238;
    int m_23c;
    int m_240;
    int m_244;
    Arr32* m_p248;
    FixedStr9 m_24c;
    RefPtr m_250;
    int m_254;
    int m_258;
    int m_25c;
    int m_260;
    int m_264;
    int m_268;
    int m_26c;
    int m_270;
    int m_274;
    int m_278;
    int m_27c;
    int m_280;
    int m_284;
    int m_288;
    int m_28c;
    int m_290;
    int m_294;
    int m_298;
    int m_29c;
    FixedStr9 m_2a0;
    RefPtr m_2a4;
    ~FUN_00c7d900();
};

extern __m128 DAT_010c7170;
extern __m128 DAT_010c44d0;
extern __m128 DAT_010c4c00;
extern __m128 DAT_010c4c10;

__forceinline hkSimdReal::hkSimdReal(const __m128& value) : m_vValue(value) {}
__forceinline hkQuaternion::hkQuaternion() {}
__forceinline hkQsTransform::hkQsTransform() {}
__forceinline void hkQuaternion::operator=(const hkQuaternion& q)
{
    reinterpret_cast<hkVector4&>(*this) = reinterpret_cast<const hkVector4&>(q);
}
__forceinline void hkQsTransform::operator=(const hkQsTransform& t)
{
    m_vTranslation = t.m_vTranslation;
    m_rotation = t.m_rotation;
    m_vScale = t.m_vScale;
}

__forceinline void hkVector4::addMul4(__m128 s, const hkVector4& b)
{
    m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(_mm_shuffle_ps(s, s, 0), b.m_vComponents));
}

__forceinline void hkVector4::setNeg4(const hkVector4& a)
{
    m_vComponents = _mm_xor_ps(a.m_vComponents, DAT_010c44d0);
}

__forceinline __m128 crossValue(__m128 a, __m128 b)
{
        return _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2)),
                          _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9)));
    }

__forceinline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
{
    m_vComponents = crossValue(v1.m_vComponents, v2.m_vComponents);
}

__forceinline hkSimdReal hkVector4::dot3(const hkVector4& v) const
{
    __m128 x2 = _mm_mul_ps(m_vComponents, v.m_vComponents);
    __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(1, 1, 1, 1)), x2);
    return hkSimdReal(_mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(2, 2, 2, 2)), sum));
}

__forceinline void hkQuaternion::SetConjugate(const hkQuaternion& q)
{
    reinterpret_cast<hkVector4&>(*this).m_vComponents = _mm_xor_ps(reinterpret_cast<const hkVector4&>(q).m_vComponents, DAT_010c4c00);
}

// 0x00c66320: keep the original inline linkage and non-inlined call behavior.
inline __declspec(noinline) void hkQuaternion::SetProduct(const hkQuaternion& q0, const hkQuaternion& q1)
{
    __m128 a = reinterpret_cast<const hkVector4&>(q0).m_vComponents;
    __m128 b = reinterpret_cast<const hkVector4&>(q1).m_vComponents;
    __m128 cross = _mm_sub_ps(
        _mm_mul_ps(_mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 1, 0, 2)), _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 0, 2, 1))),
        _mm_mul_ps(_mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 0, 2, 1)), _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 1, 0, 2))));
    __m128 aw = _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 3, 3, 3));
    __m128 bw = _mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 3, 3, 3));
    __m128 imag = _mm_add_ps(_mm_mul_ps(bw, a), _mm_add_ps(_mm_mul_ps(aw, b), cross));
    __m128 prod = _mm_mul_ps(b, a);
    __m128 dot = _mm_add_ss(_mm_shuffle_ps(prod, prod, _MM_SHUFFLE(2, 2, 2, 2)),
                            _mm_add_ss(_mm_shuffle_ps(prod, prod, _MM_SHUFFLE(1, 1, 1, 1)), prod));
    __m128 real = _mm_sub_ps(prod, _mm_shuffle_ps(dot, dot, 0));
    reinterpret_cast<hkVector4&>(*this).m_vComponents = _mm_shuffle_ps(imag, _mm_unpackhi_ps(imag, real), _MM_SHUFFLE(3, 0, 1, 0));
}

__forceinline void hkVector4::SetRotatedDirection(const hkQuaternion& quat, const hkVector4& direction)
{
    hkVector4 qreal;
    qreal.m_vComponents = _mm_shuffle_ps(reinterpret_cast<const hkVector4&>(quat).m_vComponents, reinterpret_cast<const hkVector4&>(quat).m_vComponents, _MM_SHUFFLE(3, 3, 3, 3));
    hkVector4 q2minus1;
    q2minus1.setMul4(qreal, qreal);
    q2minus1.m_vComponents = _mm_add_ps(q2minus1.m_vComponents, DAT_010c71e0);
    hkVector4 ret;
    ret.setMul4(direction, q2minus1);
    __m128 imagDotDir = reinterpret_cast<const hkVector4&>(quat).dot3(direction).m_vValue;
    ret.addMul4(imagDotDir, reinterpret_cast<const hkVector4&>(quat));
    hkVector4 imagCrossDir;
    imagCrossDir.setCross(reinterpret_cast<const hkVector4&>(quat), direction);
    ret.addMul4(imagCrossDir, qreal);
    setAdd4(ret, ret);
}

__forceinline void hkVector4::setRotatedInverseDir(const hkQuaternion& quat, const hkVector4& direction)
{

    const hkVector4& d = direction;
    hkVector4 qreal;
    qreal.m_vComponents = _mm_shuffle_ps(reinterpret_cast<const hkVector4&>(quat).m_vComponents, reinterpret_cast<const hkVector4&>(quat).m_vComponents, _MM_SHUFFLE(3, 3, 3, 3));
    hkVector4 q2minus1;
    q2minus1.setMul4(qreal, qreal);
    q2minus1.m_vComponents = _mm_add_ps(q2minus1.m_vComponents, DAT_010c71e0);
    hkVector4 ret;
    ret.setMul4(d, q2minus1);
    __m128 imagDotDir = reinterpret_cast<const hkVector4&>(quat).dot3(d).m_vValue;
    ret.addMul4(imagDotDir, reinterpret_cast<const hkVector4&>(quat));
    hkVector4 imagCrossDir;
    imagCrossDir.setCross(d, reinterpret_cast<const hkVector4&>(quat));
    ret.addMul4(imagCrossDir, qreal);
    setAdd4(ret, ret);
}

__forceinline void hkQsTransform::SetConjugate(const hkQsTransform& t)
{
    m_vTranslation.setRotatedInverseDir(t.m_rotation, t.m_vTranslation);
    m_vTranslation.setNeg4(m_vTranslation);
    m_rotation.SetConjugate(t.m_rotation);
    hkVector4 s;
    s.m_vComponents = _mm_shuffle_ps(
        t.m_vScale.m_vComponents, _mm_unpackhi_ps(t.m_vScale.m_vComponents, DAT_010c7170), _MM_SHUFFLE(3, 0, 1, 0));
    // Compute the reciprocal before storing it, as in this unit's original inline body.
    __m128 r = _mm_rcp_ps(s.m_vComponents);
    __m128 rr = _mm_mul_ps(_mm_mul_ps(r, s.m_vComponents), r);
    m_vScale.m_vComponents = _mm_sub_ps(_mm_add_ps(r, r), rr);
    m_vScale.m_vComponents = _mm_and_ps(m_vScale.m_vComponents, DAT_010c4c10);
}

__forceinline void hkQsTransform::SetProduct(const hkQsTransform& t1, const hkQsTransform& t2)
{
    hkVector4 temp;
    temp.SetRotatedDirection(t1.m_rotation, t2.m_vTranslation);
    m_vTranslation.setAdd4(temp, t1.m_vTranslation);
    m_rotation.SetProduct(t1.m_rotation, t2.m_rotation);
    m_vScale.setMul4(t1.m_vScale, t2.m_vScale);
}

__forceinline void hkQsTransform::SetMulInverse(const hkQsTransform& a, const hkQsTransform& b)
{
    hkQsTransform h;
    h.SetConjugate(a);
    SetProduct(h, b);
}

// @fnv 0x00cda690
// src: COMMUNITY 0x00cda690
void hkaPose::syncLocalSpace()
{
    if (m_bPoseInitialized)
        return;
    const int numBones = m_pSkeleton->m_kBones.m_iElementCount;
    for (int boneIdx = 0; boneIdx < numBones; boneIdx++)
    {
        if (m_pBoneFlags.m_data[boneIdx] & F_DIRTY_LOCAL)
        {
            const short parentIdx = m_pSkeleton->m_kParentIndices.m_data[boneIdx];
            const hkQsTransform& modelFromBone = m_pModelPose.m_data[boneIdx];
            if (parentIdx != -1)
            {
                const hkQsTransform& modelFromParent = (m_pBoneFlags.m_data[parentIdx] & F_DIRTY_MODEL) == 0
                                                              ? m_pModelPose.m_data[parentIdx]
                                                              : GetBoneModelSpace(parentIdx);
                m_pLocalPose.m_data[boneIdx].SetMulInverse(modelFromParent, modelFromBone);
            }
            else
            {
                m_pLocalPose.m_data[boneIdx] = modelFromBone;
            }
            m_pBoneFlags.m_data[boneIdx] &= ~F_DIRTY_LOCAL;
        }
    }
    m_bPoseInitialized = true;
}
