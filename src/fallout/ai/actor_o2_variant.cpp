#include "../../../include/hkArray.h"

// src/fallout/ai/actor_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/ai/actor.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "../../../include/Actor.h"
#include "../../../include/hkMemoryRouter.h"
#include "../../../include/hkMemoryAllocator.h"
#include "../../../include/MemoryManager.h"
#include "../../../include/Creature.h"
#include "../../../include/Mat3.h"
#include "../../../include/NiNode.h"
#include "../../../include/NiTransform.h"
#include "../../../include/NiUpdateData.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/NiMatrix3.h"
#include "../../../include/hkBool.h"
#include "../../../include/bhkRagdollController.h"


inline NiTransform::NiTransform() {}
inline NiUpdateData::NiUpdateData() {}
inline NiNode* NiAVObject::GetParent() const { return m_pkParent; }

extern MemoryManager g_memoryManager;
// @fnv 0x00c7de30
void* bhkRagdollController::FUN_00c7de30(unsigned int flag)
{
    bhkRagdollController::~bhkRagdollController();
    if ((flag & 1) && this)
    {
        g_memoryManager.Deallocate((char*)this - *(unsigned char*)((char*)this - 1));
    }
    return this;
}

extern "C" void* g_012685f8;

// @fnv 0x00c7fa60
// src: COMMUNITY 0x00c7fa60
void* __cdecl bhkStiffSpringConstraint_GetRTTI()
{
    return &g_012685f8;
}

extern "C" void __cdecl _delete(void*, int);
void __cdecl FUN_00cc58c0();

struct FUN_00c7fa70_Class
{
    void* __thiscall FUN_00c7fa70(int);
};

// @fnv 0x00c7fa70
void* __thiscall FUN_00c7fa70_Class::FUN_00c7fa70(int flags)
{
    FUN_00cc58c0();
    if (flags & 1)
        _delete(this, 0x10);
    return this;
}

extern "C" void __cdecl FUN_0062d4b0();
extern int DAT_01084e54;

struct FUN_00cb9900_cls
{
    void __thiscall UpdateFields_00cb9900();
};

// @fnv 0x00cb9900
// src: GUESS 0x00cb9900 (confidence: low)
void __thiscall FUN_00cb9900_cls::UpdateFields_00cb9900()
{
    *(int*)this = (int)&DAT_01084e54;
    FUN_0062d4b0();
}

void __cdecl hkaPose_syncModelSpace();
void __cdecl FUN_00cd9fe0();

struct FUN_00cda4b0_cls
{
    void __thiscall hkaPose_accessSyncedPoseModelSpace();
};

// @fnv 0x00cda4b0
// src: COMMUNITY 0x00cda4b0
void __thiscall FUN_00cda4b0_cls::hkaPose_accessSyncedPoseModelSpace()
{
    hkaPose_syncModelSpace();
    ((void(__thiscall*)(void*))FUN_00cd9fe0)(this);
}

struct FUN_00cda8d0_class
{
    void hkaPose_syncModelSpace();
    void* hkaPose_getSyncedPoseModelSpace();
};

// @fnv 0x00cda8d0
// src: HAVOK_LIB 0x00cda8d0
void* FUN_00cda8d0_class::hkaPose_getSyncedPoseModelSpace()
{
    hkaPose_syncModelSpace();
    return (char*)this + 0x10;
}

struct FUN_00cdb290
{
    void __thiscall syncLocalSpace();
    void* __thiscall GetPlus4();
};
// @fnv 0x00cdb290
void* __thiscall FUN_00cdb290::GetPlus4()
{
    syncLocalSpace();
    return (char*)this + 4;
}

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
// @fnv 0x00c7e970
Outer* __thiscall Outer::FUN_00c7e970(unsigned int a)
{
    FUN_00c7dc40();
    if (a & 1)
    {
        Holder* h = _FUN_00c85750();
        h->p->f2(this, _4);
    }
    return this;
}


// @fnv 0x00c802d0
// src: COMMUNITY 0x00c802d0
NiCollisionObject* __cdecl bhkUtilFunctions_FindNextCollisionObject(NiAVObject* p)
{
    NiCollisionObject* r = p->m_spCollisionObject.m_pObject;
    if (!r && p->IsSceneNode())
    {
        for (unsigned i = 0; i < static_cast<NiNode*>(p)->m_kChildren.m_usSize; ++i)
        {
            if (r)
                break;
            NiAVObject* child = static_cast<NiNode*>(p)->m_kChildren.m_pBase[i].m_pObject;
            if (child)
                r = bhkUtilFunctions_FindNextCollisionObject(child);
        }
    }
    return r;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
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

template <> inline NiPointer<MyRef>::NiPointer() : m_pObject(0) {}
template <> inline NiPointer<MyRef>::~NiPointer()
{
    if (m_pObject != 0)
        m_pObject->DecRefCount();
}

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

// @fnv 0x00c6ffc0
// src: COMMUNITY 0x00c6ffc0
void FUN_00c6ffc0_Class::bhkCharacterController_RemoveCollisionDebug()
{
    Target* p = bhkCharacterController_GetCollisionDebugNode();
    NiPointer<MyRef> sp;
    Target18* t;
    if (p && (t = p->field_18))
    {
        t->MethodE4(p, sp);
    }
    *(unsigned int*)((char*)this + 0x414) &= 0xffff7fff;
}

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

struct RObj
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual NiNode* GetAsNode();
    int _4;
    FixedStr name;
    char _c[0xc];
    RObj* parent;
    char _1c[0x18];
    NiTransform local;
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
    NiTransform x;
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

// @fnv 0x00c7bcb0
// src: COMMUNITY 0x00c7bcb0
void __cdecl CopyPoseFunctor(RCtx* ctx, RObj* obj, RArr* arr)
{
    RKey key(obj->name);
    key.obj = obj;
    if (key.name.Equals("Bip01 NonAccum"))
        key.obj = obj->parent;
    RObj* bone = BSUtilities_GetObjectByName_00c4b470(ctx, &key, 1);
    if (bone)
    {
        RElem e;
        e.obj = bone;
        e.x = bone->local;
        int idx = arr->AppendSlot();
        arr->ConstructElementArray(&arr->data[idx], 1);
        const NiTransform& src = key.obj->local;
        arr->data[idx] = e;
        bone->local.m_Rotate = src.m_Rotate;
        bone->local.m_Translate = src.m_Translate;
    }
    NiNode* node = obj->GetAsNode();
    if (node)
    {
        for (unsigned int i = 0; i < node->m_kChildren.m_usSize; i++)
        {
            RObj* child = (RObj*)node->m_kChildren.m_pBase[i].m_pObject;
            if (child)
                CopyPoseFunctor(ctx, child, arr);
        }
    }
}

void __cdecl SetFlagRecursive(int, void*);
void __cdecl CopyPoseFunctor(void*, void*, void*);

inline unsigned char GetFlag6(unsigned short w)
{
    return (unsigned char)(w >> 6) & 1;
}

// @fnv 0x00c7d3b0
// src: XBOX_PDB 0x00c7d3b0
void __cdecl bhkRagdollController_CopyPoseTo3D(NiNode* param_1, void* param_2, void* param_3, char* param_4, unsigned int* param_5)
{
    NiCollisionObject* node = bhkUtilFunctions_FindNextCollisionObject(param_1);
    char flag;
    if (!node || !(*(unsigned short*)((char*)node + 0xc) & 0x20) || GetFlag6(*(unsigned short*)((char*)node + 0xc)))
    {
        flag = 0;
    }
    else
    {
        flag = 1;
    }
    *param_4 = flag;
    if (flag)
    {
        SetFlagRecursive(0, param_1);
    }
    if (node)
    {
        unsigned int val;
        char* n10 = *(char**)((char*)node + 0x10);
        if (n10 && *(char**)(n10 + 8))
        {
            val = *(unsigned char*)(*(char**)(n10 + 8) + 0xe8);
        }
        else
        {
            val = 5;
        }
        *param_5 = val;
    }
    if (*param_5 != 4)
    {
        Creature::SetNodeFlagsRecursive(param_1, 4, true, false, true);
    }
    if (param_1 && param_2)
    {
        CopyPoseFunctor(param_1, param_2, param_3);
        NiUpdateData updateData;
        updateData.fTime = 0.0f;
        updateData.pad1 = false;
        updateData.pad2 = false;
        updateData.pad3 = false;
        updateData.pad4 = false;
        updateData.pad5 = false;
        param_1->Update(static_cast<const NiUpdateData&>(updateData));
    }
}

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
    NiNode* m_pkNode;
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

// @fnv 0x00c7d630
// src: XBOX_PDB 0x00c7d630
void FUN_00c7d630_t::bhkRagdollController_DoRagdollAnim(float)
{
    char* self = (char*)this;
    if (*(bool*)(self + 0x43) && !*(bool*)(self + 0xb3) && !*(bool*)(self + 0x222) && !*(bool*)(self + 0x21e) &&
        !*(bool*)(self + 0x28e))
    {
        *(bool*)(self + 0x43) = false;
        *(bool*)(self + 0x41) = false;
    }
    if (DAT_01267c28 && *(bool*)(self + 0x41))
    {
        NiTransform kWorld = static_cast<const NiAVObject*>(m_pkNode)->GetParent()->m_kWorld * m_pkNode->m_kLocal;
        kWorld.m_Rotate = static_cast<const NiMatrix3&>(m_kRot) * kWorld.m_Rotate;
        kWorld.m_fScale = 1.0f;
        NI2HK_00c74dd0(self + 0x10, &kWorld);
        if (!*(bool*)(self + 0x40))
        {
            bhkRagdollController_GetSGPoseLocalSpace();
            bhkRagdollController_UpdateDebugLines(0);
            if (DAT_01267c34 && (*(bool*)(self + 0x222) || *(bool*)(self + 0x223)))
                bhkRagdollController_DoFootIK(self + 0x10);
            if (DAT_01267c40 && *(bool*)(self + 0x21e))
                bhkRagdollController_DoGrabIK(self + 0x10);
            if (DAT_01267c4c && *(bool*)(self + 0xb3))
                bhkRagdollController_DoLookAtIK(self + 0x10);
        }
        unsigned int count = m_48->GetInner()->GetCount();
        bool bOk = false;
        RagScrapMarker kScrap(count);
        bhkRagdollController_UpdateRagdollRigidBodies((DAT_01267c64 && *(bool*)(self + 0x256) && (bhkRagdollController_DoPoseMatching(self + 0x10, kScrap.p, &bOk), bOk))
                         ? kScrap.p
                         : 0);
        bhkRagdollController_UpdateDebugLines(1);
        if (!*(bool*)(self + 0x40))
        {
            if (DAT_01267c58 && *(bool*)(self + 0x28e))
                bhkRagdollController_DoRagdollFeedback();
            bhkRagdollController_UpdateDebugLines(2);
            bhkRagdollController_SetSGPoseLocalSpace();
        }
    }
}

namespace fnv_00c7d810 {

void __cdecl NI2HK_00c74dd0(void*, void*);

struct XObj
{
    void hkaRagdollRigidBodyController_reinitialize();
};

struct FUN_00c7d810_Cls
{
    void bhkRagdollController_GetSGPoseLocalSpace();
    void bhkRagdollController_UpdateRagdollRigidBodies(int);
    void bhkRagdollController_SyncRagdollTo3D();
};

// @fnv 0x00c7d810
// src: XBOX_PDB 0x00c7d810
void FUN_00c7d810_Cls::bhkRagdollController_SyncRagdollTo3D()
{
    NiTransform nitrans;
    nitrans = *(NiTransform*)((char*)(*(void**)((char*)this + 0x58)) + 0x68);
    nitrans.m_Rotate = *(const NiMatrix3*)((char*)this + 0x60) * nitrans.m_Rotate;
    nitrans.m_fScale = 1.0f;
    NI2HK_00c74dd0((char*)this + 0x10, &nitrans);
    bhkRagdollController_GetSGPoseLocalSpace();
    int etype = *(int*)((char*)this + 0xc);
    *(int*)((char*)this + 0xc) = 1;
    bhkRagdollController_UpdateRagdollRigidBodies(0);
    *(int*)((char*)this + 0xc) = etype;
    XObj* p = *(XObj**)((char*)this + 0x4c);
    if (p)
        p->hkaRagdollRigidBodyController_reinitialize();
}
}  // namespace fnv_00c7d810

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

// @fnv 0x00c7d890
// src: GUESS 0x00c7d890 (confidence: low)
void FUN_00c7d890_cls::ProcessEntries_00c7d890()
{
    VObjExt* p = (VObjExt*)_FUN_00c85750()->p;
    int count = _4;
    char* base = (char*)_0;
    for (int i = 0; i < count; i++)
        ((FUN_00cb0c00_class*)(base + i * 8))->Object_UpdateFields_00cb0c00();
    unsigned int flags = _8;
    _4 = 0;
    if (!(flags & 0x80000000))
        p->v4(_0, (flags & 0x3fffffff) * 8);
    _8 = 0x80000000;
    _0 = 0;
}

void* __cdecl FUN_00ec7230(char*, char const*, unsigned int);

// @fnv 0x00c7f900
// src: COMMUNITY 0x00c7f900
void __stdcall BSSimpleArray_bhkUtilFunctions_AVLevel_1024_CopyItems(char* dst, char* src, unsigned int count)
{
    if (count <= 0)
        return;

    if (dst < src)
    {
        for (unsigned int i = 0; i < count; ++i)
            FUN_00ec7230(dst + i * 8, src + i * 8, 8);
    }
    else if (dst > src)
    {
        for (int i = (int)count - 1; i >= 0; --i)
            FUN_00ec7230(dst + i * 8, src + i * 8, 8);
    }
}

void __cdecl hkaKeyFrameHierarchyUtility_initialize(void*, unsigned int);

struct FUN_00cdb3e0_cls
{
    char pad[0x2c];
    void hkaRagdollRigidBodyController_reinitialize();
};

// @fnv 0x00cdb3e0
// src: HAVOK_LIB 0x00cdb3e0
void FUN_00cdb3e0_cls::hkaRagdollRigidBodyController_reinitialize()
{
    hkaKeyFrameHierarchyUtility_initialize((char*)this + 0x18, *(unsigned int*)((char*)this + 0x2c));
}

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
// @fnv 0x00c6a200
// src: XBOX_PDB 0x00c6a200
bool __cdecl bhkWorld_SetDisabled(void* obj, unsigned char a1, unsigned char a2, unsigned char a3)
{
    bool r = false;
    if (obj)
    {
        S_c6a200_Info* info;
        if (a3 || ((info = GetExtraDataChecked(obj)) ? (info->unk0c & 2) : 0))
        {
            S_c6a200_Ev ev;
            ev.unk04 = a2;
            r = true;
            ev.unk00 = 0;
            ev.unk08 = 0x11;
            ev.unk0c = a1;
            if (DAT_011afecc)
                bhkWorld_DoObjectRec(obj, &ev, DAT_011afecc);
        }
    }
    return r;
}

struct FlagController
{
    void bhkRagdollController_SetRagdollFeedbackActive(int);
    void bhkRagdollController_EnableRagdollFeedback(bool);
};
// @fnv 0x00c7ba10
// src: XBOX_PDB 0x00c7ba10
void FlagController::bhkRagdollController_EnableRagdollFeedback(bool enabled)
{
    unsigned char* state = (unsigned char*)this;
    bool target = state[0x28c] && enabled;
    if (!target && state[0x28e])
        bhkRagdollController_SetRagdollFeedbackActive(0);
    state[0x28d] = target;
}

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



template<> __forceinline hkArray<HkElem30>::~hkArray()
{

        HkAllocator* alloc = GetHkMemHolder()->GetAllocator();
        m_iElementCount = 0;
        if (!(m_iCapacityState & 0x80000000))
            HkDeallocT<HkElem30>(alloc, m_data, m_iCapacityState & 0x3fffffff);
        m_data = 0;
        m_iCapacityState = 0x80000000;

}
template<> __forceinline hkArray<int>::~hkArray()
{

        HkAllocator* alloc = GetHkMemHolder()->GetAllocator();
        m_iElementCount = 0;
        if (!(m_iCapacityState & 0x80000000))
            HkDeallocT<int>(alloc, m_data, m_iCapacityState & 0x3fffffff);
        m_data = 0;
        m_iCapacityState = 0x80000000;

}
struct RagdollPoseArrays
{
    int unk00;
    hkArray<HkElem30> arr04;
    hkArray<HkElem30> arr10;
    hkArray<int> arr1C;
    int unk28;
    hkArray<int> arr2C;
    ~RagdollPoseArrays();
};

// @fnv 0x00c7c030
RagdollPoseArrays::~RagdollPoseArrays()
{}

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

namespace fnv_00c7d520 {
struct FreeIface
{
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void Free(void* p, unsigned int size);
};

struct FUN_00c7d520_cls
{
    void* m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    void UpdateFields_00c7d520();
};

struct ScopeGuard
{
    FUN_00c7d520_cls* owner;
// @fnv 0x00c7d520
    ScopeGuard(void* p) : owner((FUN_00c7d520_cls*)p)
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

// src: GUESS 0x00c7d520 (confidence: low)
void FUN_00c7d520_cls::UpdateFields_00c7d520()
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
}  // namespace fnv_00c7d520


// hkMemoryRouter::m_pAllocator (+0x10) is the thread's heap, an hkMemoryAllocator (slot 4 = bufFree); the
// "AudioAllocator" stand-in used here before was that class.

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

// @fnv 0x00c7d5c0
// src: GUESS 0x00c7d5c0 (confidence: low)
void FUN_00c7d5c0_cls::ProcessEntries_00c7d5c0()
{
    hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
    FUN_00c7d5c0_elem* pElem = m_pData;
    if (m_iArrayLength > 0)
    {
        int n = m_iArrayLength;
        do
        {
            pElem->Release();
            ++pElem;
        } while (--n != 0);
    }
    unsigned int uCap = m_uCap;
    m_iArrayLength = 0;
    if ((uCap & 0x80000000u) == 0)
    {
        pAllocator->bufFree(m_pData, (uCap & 0x3fffffffu) * 4u);
    }
    m_pData = 0;
    m_uCap = 0x80000000u;
}

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

// @fnv 0x00c7f9e0
FUN_00c7f9e0::FUN_00c7f9e0(void* context) : MiddleObject()
{
    classTable = DAT_010c52bc;
    SpawnAndAttach(context ? (char*)context + 4 : 0);
    ++g_012685f4;
}

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

// @fnv 0x00cb9810
// src: XBOX_PDB 0x00cb9810
void BCB9810Registry::bhkFilteredCdBodyCollector_addCdBodyPair(void* pvOwner, BCB9810Node* pkNode)
{
    BCB9810AllocTagScope kScope(0x10);
    bool bFound = false;
    for (int i = 0; i < m_iArrayLength; i++)
    {
        if (bFound)
            break;
        BCB9810Node* pkRoot = pkNode;
        while (pkRoot->m_pParentNode)
            pkRoot = pkRoot->m_pParentNode;
        if (pkRoot == m_pkEntryArray[i].m_pkTreeNode)
            bFound = true;
    }
    if (!bFound)
        AppendTailPair(pvOwner, pkNode);
}

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

// @fnv 0x00ce4360
// src: HAVOK_LIB 0x00ce4360
void __cdecl hkaSkeletonMapper_mapPose(CE4360Context* pkContext, CE4360Iter* pkFrom, CE4360Iter* pkTo, int iValue)
{
    if (pkContext->m_iMode == 0)
    {
        int a = *pkFrom->GetFirst();
        int b = *pkTo->GetSecond();
        mapPose(pkContext, a, b, *pkTo->GetThird(), iValue);
    }
    else if (pkContext->m_iMode == 1)
    {
        int a = *pkFrom->GetSecond();
        int b = *pkTo->GetFourth();
        hkaSkeletonMapper_mapPoseLocalSpace_00ce4330(pkContext, a, b, 0);
    }
}

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

// @fnv 0x00c9bdf0
// src: XBOX_PDB 0x00c9bdf0
void __cdecl bhkBlendController_DoGetUp(Obj_c9b* pkObj, float f)
{
    if (pkObj && IsNode_c9b(pkObj) && pkObj->m_usElementCount > 0)
    {
        Obj_c9b* pkChild = pkObj->m_ppChildren[0];
        if (pkChild && IsNode_c9b(pkChild) && pkChild->m_usElementCount > 0)
        {
            Obj_c9b* pkGrand = pkChild->m_ppChildren[0];
            if (pkGrand && pkGrand->m_1c)
            {
                Cast_c9b* pkCast = pkGrand->m_1c->FUN_00653290(&g_012043f8);
                if (pkCast)
                {
                    S* pkS = pkCast->m_10;
                    if (pkS)
                    {
                        pkS->SetMode(4);
                        pkS->bhkRigidBody_SetLinearVelocity_00561690((int)&DAT_01267e30);
                        pkS->bhkRigidBody_SetAngularVelocity_005617c0(&DAT_01267e30);
                    }
                }
            }
        }
    }
    ApplyCollisionEffect(pkObj, f);
}

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

// @fnv 0x00c7f970
// src: COMMUNITY 0x00c7f970
void FUN_00c7f970_cls::BSSimpleArray_bhkUtilFunctions_AVLevel_1024_ReallocateBuffer(unsigned int uiNew, unsigned int uiOld)
{
    if (m_pData)
    {
        if (uiOld == m_uiSize)
        {
            m_pData = Realloc(m_pData, uiNew);
        }
        else
        {
            char* pNew = Alloc(uiNew);
            ((void(__thiscall*)(void*, char*, char*, unsigned int))BSSimpleArray_bhkUtilFunctions_AVLevel_1024_CopyItems)(this, pNew, m_pData, uiOld);
            Free(m_pData);
            m_pData = pNew;
        }
    }
    else
    {
        m_pData = Alloc(uiNew);
        m_uiSize = uiNew;
    }
}


struct Head
{
    hkBool a, b;
    int c;
    Head() : a(true), b(true), c(0)
    {}
};
// The arrays initialized at 0x00c7bfd0 are released as eight-byte pairs at 0x00c7c2b0.
struct C7C2B0_Pair
{
    int a;
    int b;
};
struct FUN_00c7bfd0
{
    int m_00, m_04, m_08;
    float m_0c;
    float m_10;
    hkArray<C7C2B0_Pair> m_14, m_20, m_2c;
    Head m_38;
    int m_40, m_44, m_48;
    float m_4c, m_50;
    FUN_00c7bfd0();
};
// @fnv 0x00c7bfd0
FUN_00c7bfd0::FUN_00c7bfd0()
    : m_00(0), m_04(0), m_08(0), m_0c(0.0f), m_10(0.5235988f), m_40(0), m_44(0), m_48(0), m_4c(1.0f), m_50(1.0f)
{}

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

// @fnv 0x00cb9650
// src: XBOX_PDB 0x00cb9650
void __cdecl bhkForceController_RemoveForce(FUN_00cb9650_Object* object)
{
    if (object != 0)
    {
        void* controller = object->NiObjectNET_GetController(DAT_012683f4);
        if (controller != 0)
        {
            object->NiObjectNET_RemoveController((int)controller);
        }

        NiNode* node = object->vf0C();
        if (node != 0)
        {
            for (unsigned int index = 0; index < node->m_kChildren.m_usSize; ++index)
            {
                bhkForceController_RemoveForce((FUN_00cb9650_Object*)node->m_kChildren.m_pBase[index].m_pObject);
            }
        }
    }
}

#include <xmmintrin.h>
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
// @fnv 0x00c75580
// src: XBOX_PDB 0x00c75580
void RagController::bhkRagdollController_SetLookIKActive(unsigned char enabled)
{
    int state;
    if (controlFlag() == 0)
    {
        if (activeFlag() != 0 && enabled != 0)
        {
            state = 1;
        }
        else
        {
            state = 0;
        }
    }
    else
    {
        state = stateFlag();
    }
    stateFlag() = (unsigned char)state;
    if (enabled == 0)
    {
        poseA() = DAT_010c71b0;
        poseB() = DAT_010c71b0;
        dirtyB() = 1;
        dirtyA() = 1;
    }
}

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
    NiTransform local;
    NiTransform world;
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

// @fnv 0x00c7ba50
// src: COMMUNITY 0x00c7ba50
void Cls::bhkRagdollController_DoPoseMatching(void* a1, void* a2, bool* a3)
{
    NiPoint3* wp = &m_058->world.m_Translate;
    float dx = m_pos.x - wp->x;
    float dy = m_pos.y - wp->y;
    float dz = m_pos.z - wp->z;
    float lenSq = dx * dx + dy * dy + dz * dz;
    double d = (float)sqrt((double)lenSq);
    float dist = (float)d;
    if (BSPrecisionTimer_GetTimer() - m_260 > m_268 || (m_284 && dist > m_27c) || m_288 != -1)
    {
        if (m_288 != -1)
        {
            m_250->bhkPoseArray_CreatePoseForRagdoll(a2, m_048->inner, m_288);
            m_00c = 3;
            *a3 = true;
            m_258 = m_288;
            m_288 = -1;
        }
        else
        {
            m_pos = *(const NiPoint3*)&m_058->world.m_Translate;
            InnerC* inner = m_048->inner;
            ScrapMarker marker(inner->count);
            m_048->hkaRagdollInstance_getPoseModelSpace(marker.p, a1);
            int id = m_248->hkaPoseMatchingUtility_findBestCandidatePoseIndex(marker.p, &m_008);
            if (m_008 < DAT_011b02e4 && id != m_258)
            {
                m_258 = id;
                if (id != -1)
                {
                    Obj250* o250 = m_250;
                    o250->bhkPoseArray_CreatePoseForRagdoll(a2, inner, id);
                    m_00c = 3;
                    *a3 = true;
                }
                else if (!*a3)
                {
                    m_00c = 0;
                    *a3 = false;
                    m_004 = true;
                }
            }
            else if (!*a3)
            {
                m_00c = 0;
                *a3 = false;
                m_004 = true;
            }
        }
        volatile float f = m_280;
        m_260 = BSPrecisionTimer_GetTimer();
        m_268 = (__int64)(f * DAT_011ac39c);
    }
}

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

// @fnv 0x00c7c150
// src: XBOX_PDB 0x00c7c150
void RagdollCtl::bhkRagdollController_DisableRagdollAnim(bool b)
{
    if (active)
    {
        bool old = unk222;
        unk41 = false;
        unk43 = false;
        unk222 = false;
        if (old)
            unk223 = true;
        unk21e = false;
        unkb3 = false;
        vec120 = g_hkQuadZero;
        vec170 = g_hkQuadZero;
        unk180 = true;
        unk130 = true;
        if (unk28d)
            bhkRagdollController_SetRagdollFeedbackActive(false);
        if (skel)
        {
            int n = skel->info->boneCount;
            for (int i = 0; i < n; i++)
            {
                RagRigid* r = bones[i]->rigid;
                if (r)
                {
                    RagMotion* m = r->GetMotion();
                    if (m)
                        m->unk14 = false;
                }
            }
        }
        unkb2 = false;
        unk1b8 = unk1e8 = 0.0f;
        unk1ec = false;
        unk1bc = false;
        unk221 = false;
        unk290 = 1.0f;
        unk228 = 0;
        unk28f = false;
        unk294 = 0;
        if (b)
            ctrl48->Reattach();
        for (int j = 0; j < 0; ++j)
        {
        }
    }
}

// @fnv 0x00c7f4a0
// src: HAVOK_LIB 0x00c7f4a0
static __declspec(noinline) unsigned char* hkVector4isOk(unsigned char* out, const float* src, int count)
{
    int i = 0;
    if (count > 0)
    {
        do
        {
            float value = src[i];
            unsigned int bits = *(const unsigned int*)&value;
            if ((bits & 0x7f800000u) == 0x7f800000u)
            {
                *out = 0;
                return out;
            }
            ++i;
        } while (i < count);
    }
    *out = 1;
    return out;
}
unsigned char* S00c7f4a0_Call(unsigned char* out, const float* src, int count)
{
    return hkVector4isOk(out, src, count);
}

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
// @fnv 0x00c7f500
// src: HAVOK_LIB 0x00c7f500
void HkFloatCheck::hkVector4_isOk4(bool* pOut)
{
    CheckFloatsValid((const float*)this, 4, pOut);
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
// @fnv 0x00c7fa90
// src: XBOX_PDB 0x00c7fa90
int __cdecl bhkUtilFunctions_GetNiAVObject(S_Obj* p)
{
    int result = 0;
    if (S_Elem* e = GetEntity(p))
    {
        S_Out out;
        S_Val* v = *(S_Val**)bhkWorldObject_GetProperty(&out, e, &DAT_01267b70);
        if (v)
            result = v->unk08;
    }
    else if (S_Elem* ph = GetPhantom(p))
    {
        S_Out out;
        S_Val* v = *(S_Val**)bhkWorldObject_GetProperty(&out, ph, &DAT_01267b70);
        if (v)
            result = v->unk08;
        else if (ph->unk0c)
            result = ph->unk0c->bhkWorldObject_GetAVObject(0);
    }
    return result;
}

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
// @fnv 0x00cda4c0
// src: GUESS 0x00cda4c0 (confidence: low)
void PoseState::ProcessEntries_00cda4c0()
{
    int n = model->count;
    hkaPose_syncModelSpace();
    for (int i = 0; i < n; ++i)
    {
        bool locked = model->bones[i].locked != 0;
        short parent = model->parents[i];
        if (locked)
        {
            const BoneTransform& ref = model->reference[i];
            if (parent != -1)
            {
                const BoneTransform& p = world[parent];
                world[i].position.Rotate(p.rotation, ref.position);
                world[i].position.Add(p.position);
            }
            else
            {
                world[i].position.q = ref.position.q;
            }
            flags[i] |= 1;
            flags[i] |= 4;
        }
        else if (parent != -1)
        {
            unsigned int* f = flags;
            if (f[parent] & 4)
                f[i] |= 1;
        }
    }
    int m = count;
    for (int j = 0; j < m; ++j)
        flags[j] &= ~28;
}

template <> __forceinline hkArray<C7C2B0_Pair>::~hkArray()
{
    hkMemoryRouter* holder = reinterpret_cast<hkMemoryRouter*>(_FUN_00c85750());
    hkMemoryAllocator* heap = holder->m_heap;
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
    hkArray<C7C2B0_Pair> m_iThirdValue;
    hkArray<C7C2B0_Pair> m_kPointB;
    hkArray<C7C2B0_Pair> m_kPointA;
    ~ShapeArrays();
};
// @fnv 0x00c7c2b0
ShapeArrays::~ShapeArrays()
{}

extern "C" void _ReadWriteBarrier(void);
__forceinline void FreeObjX(void* p, unsigned int n)
{
    Holder* h = _FUN_00c85750();
    h->p->f2(p, n);
}
template <class T> inline bhkRagdollController::HkArrX<T>::~HkArrX()
{
    hkMemoryRouter* h = reinterpret_cast<hkMemoryRouter*>(_FUN_00c85750());
    HkAllocator* alloc = reinterpret_cast<HkAllocator*>(h->m_heap);
    m_iElementCount = 0;
    if (!(m_capFlags & 0x80000000))
        HkDeallocT<T>(alloc, m_data, m_capFlags & 0x3fffffff);
    m_data = 0;
    m_capFlags = 0x80000000;
}
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
inline void bhkRagdollController::RefPtr::Reset()
{
    RefObj* p = m_p;
    if (p)
    {
        if (InterlockedDecrement(&p->m_iObjectReferenceCount) == 0)
            p->vf1();
        m_p = 0;
    }
}
inline bhkRagdollController::RefPtr::~RefPtr()
{
    RefObj* p = m_p;
    if (p)
    {
        if (InterlockedDecrement(&p->m_iObjectReferenceCount) == 0)
            p->vf1();
    }
}
extern int DAT_0109b220;
inline bhkRagdollController::FixedStr9::~FixedStr9()
{
    if (m_h != (char*)DAT_0109b220)
        InterlockedDecrement((long volatile*)(m_h - 8));
}
inline bhkRagdollController::PolyArr::~PolyArr()
{
    PolyArr* b = this;
    if (m_data)
    {
        b->vf2(m_data);
        m_data = 0;
        m_cap = 0;
        m_iElementCount = 0;
    }
}
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
    bhkRagdollController::HkArrX<T32> m_aiIndexedValues;
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
// @fnv 0x00c7d900
bhkRagdollController::~bhkRagdollController()
{
    int n = m_22c.m_iElementCount;
    for (int i = 0; i < n; ++i)
        m_22c.m_data[i].m_p0->removeReference();
    m_22c.m_iElementCount = 0;
    _ReadWriteBarrier();
    X48* pk4c = m_p4c;
    if (pk4c)
    {
        pk4c->ClearArrays();
        FreeObjX(pk4c, 0x48);
    }
    HkRef* pk48 = m_p48;
    if (pk48)
        pk48->removeReference();
    RagdollPoseArrays* pk54 = m_p54;
    if (pk54)
    {
        pk54->~RagdollPoseArrays();
        FreeObjX(pk54, 0x38);
    }
    RagdollPoseArrays* pk88 = m_p88;
    if (pk88)
    {
        pk88->~RagdollPoseArrays();
        FreeObjX(pk88, 0x38);
    }
    DAT_011b02f0.FUN_00e92760(m_24c.GetChars(), (void**)&m_250);
    if (m_250.m_p && ((int*)m_250.m_p)[1] == 2)
        DAT_011b02f0.FUN_00e91fd0(m_24c.GetChars());
    if (m_2a4.m_p && ((int*)m_2a4.m_p)[1] == 2)
        DAT_011b0300.FUN_00e91fd0(m_2a0.GetChars());
    m_2a4.Reset();
    m_250.Reset();
    Arr32* pk248 = m_p248;
    if (pk248)
    {
        pk248->~Arr32();
        FreeObjX(pk248, 0x30);
    }
}

namespace fnv_00cda110 {
void hkString_memCpy(void*, void*, unsigned int);

struct A
{
    char pad0[0x1c];
    int count;  // 0x1c
    char pad20[4];
    void* p24;  // 0x24
    char pad28[0xc];
    int n34;  // 0x34
};
struct S
{
    A* a;       // 0x00
    void* p04;  // 0x04
    char pad08[0x14];
    int* arr1c;  // 0x1c
    char pad20[8];
    char b28;  // 0x28
    char b29;  // 0x29
    char pad2a[2];
    float* arr2c;  // 0x2c
};
// @fnv 0x00cda110
// src: HAVOK_LIB 0x00cda110
void __fastcall hkaPose_setToReferencePose(S* s)
{
    int i;
    hkString_memCpy(s->p04, s->a->p24, s->a->count * 0x30);
    for (i = 0; i < s->a->count; i++)
        s->arr1c[i] = 2;
    s->b28 = 0;
    s->b29 = 1;
    _ReadWriteBarrier();
    A* d = s->a;
    i = 0;
    if (d->n34 > 0)
    {
        float* f = s->arr2c;
        do
        {
            *f++ = 0.0f;
            i++;
        } while (i < d->n34);
    }
}
}  // namespace fnv_00cda110

struct KPoint3
{
    float x, y, z;
    __declspec(noalias) KPoint3& Sub(const KPoint3& o);
};

struct KMatrix3
{
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
};

struct KTransform
{
    KMatrix3 rot;
    KPoint3 trans;
    float scale;
};

struct KQuat
{
    float w, x, y, z;
    __declspec(noalias) void ToRotationMatrix(KMatrix3& m) const;
    __declspec(noalias) void FromRotationMatrix(const KMatrix3& m);
};

struct KUpdateData
{
    float fTime;
    bool b0;
    bool b1;
    bool b2;
    bool b3;
    bool b4;
};

struct KRigidBody
{
    __declspec(noalias) bool IsActive();
    __declspec(noalias) void GetPosition(KPoint3& p);
    __declspec(noalias) void GetRotation(KQuat& q);
};

struct KRagInfo
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    KRigidBody* body;
    int unk14;
    float weight;
    bool IsKeyframed() const
    {
        return weight == 0.0f;
    }
};

struct KNode;

struct KObject
{
    __declspec(noalias) virtual void v00();
    __declspec(noalias) virtual void v01();
    __declspec(noalias) virtual void v02();
    __declspec(noalias) virtual KNode* GetAsNode();
    __declspec(noalias) virtual void v04();
    __declspec(noalias) virtual void v05();
    __declspec(noalias) virtual void v06();
    __declspec(noalias) virtual void v07();
    __declspec(noalias) virtual void v08();
    __declspec(noalias) virtual void v09();
    __declspec(noalias) virtual void v10();
    __declspec(noalias) virtual void v11();
    __declspec(noalias) virtual void v12();
    __declspec(noalias) virtual void v13();
    __declspec(noalias) virtual void v14();
    __declspec(noalias) virtual void v15();
    __declspec(noalias) virtual void v16();
    __declspec(noalias) virtual void v17();
    __declspec(noalias) virtual void v18();
    __declspec(noalias) virtual void v19();
    __declspec(noalias) virtual void v20();
    __declspec(noalias) virtual void v21();
    __declspec(noalias) virtual void v22();
    __declspec(noalias) virtual void v23();
    __declspec(noalias) virtual void v24();
    __declspec(noalias) virtual void v25();
    __declspec(noalias) virtual void v26();
    __declspec(noalias) virtual void v27();
    __declspec(noalias) virtual void v28();
    __declspec(noalias) virtual void v29();
    __declspec(noalias) virtual void v30();
    __declspec(noalias) virtual void v31();
    __declspec(noalias) virtual void v32();
    __declspec(noalias) virtual void v33();
    __declspec(noalias) virtual void v34();
    __declspec(noalias) virtual void v35();
    __declspec(noalias) virtual void v36();
    __declspec(noalias) virtual void v37();
    __declspec(noalias) virtual void v38();
    __declspec(noalias) virtual void v39();
    __declspec(noalias) virtual void v40();
    __declspec(noalias) virtual void v41();
    __declspec(noalias) virtual void v42();
    __declspec(noalias) virtual void v43();
    __declspec(noalias) virtual void v44();
    __declspec(noalias) virtual void v45();
    __declspec(noalias) virtual void UpdateDownward(KUpdateData& data);
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
    KTransform local;
    KTransform world;
    __declspec(noalias) void UpdateWorldLoc();
};

struct KNode : KObject
{
    int unk9c;
    KObject** children;
    unsigned short unka4;
    unsigned short childCount;
    KObject* GetAt(unsigned int i)
    {
        return i < childCount ? children[i] : 0;
    }
};

__declspec(noalias) void* bhkBlendCollisionObject_GetFirstCollisionObject(void* node);

// @fnv 0x00c821b0
// src: XBOX_PDB 0x00c821b0
void bhkBlendCollisionObject_SetBipTransform(KObject* root, KPoint3* outDelta, bool update)
{
    bool weightless;
    bool fromNode;
    if (!root)
        return;
    KNode* node = root->GetAsNode();
    if (!node)
        return;
    KObject* c0 = node->childCount > 0 ? node->children[0] : 0;
    if (!c0)
        return;
    KNode* child = c0->GetAsNode();
    if (!child)
        return;
    KObject* c1 = child->childCount > 0 ? child->children[0] : 0;
    if (!c1)
        return;
    KNode* grand = c1->GetAsNode();
    if (!grand)
        return;
    KRagInfo* info = (KRagInfo*)bhkBlendCollisionObject_GetFirstCollisionObject(child);
    if (!info)
        return;
    weightless = true;
    if (info->weight != 0.0f)
        weightless = false;
    if (grand->unk1c || weightless)
    {
        KTransform t;
        KRigidBody* body = info->body;
        fromNode = false;
        if (body && body->IsActive())
        {
            KQuat q;
            fromNode = false;
            body->GetPosition(t.trans);
            body->GetRotation(q);
            q.ToRotationMatrix(t.rot);
        }
        else if (weightless)
        {
            KQuat q;
            fromNode = true;
            t.trans = node->local.trans;
            q.FromRotationMatrix(node->local.rot);
            q.ToRotationMatrix(t.rot);
        }
        else
        {
            t = grand->world;
        }

        KTransform old = node->local;
        if (update || !weightless)
            t.trans.z = old.trans.z;

        KPoint3 pos = t.trans;
        if (!fromNode)
        {
            *outDelta = pos;
            outDelta->Sub(node->local.trans);
        }
        node->local.trans = pos;
        if (weightless)
            node->local.rot = t.rot;
        if (update)
        {
            node->UpdateWorldLoc();
            KUpdateData data;
            data.fTime = 0.0f;
            data.b0 = false;
            data.b1 = false;
            data.b2 = false;
            data.b3 = false;
            data.b4 = false;
            node->UpdateDownward(data);
        }
    }
}

template <class T> __forceinline void ShortFree(hkMemoryAllocator& a, void* p, const int& cnt)
{
    a.bufFree(p, cnt * (unsigned int)sizeof(T));
}
template <class T> __forceinline void FreeArr(hkMemoryAllocator& a, void* p, int cnt)
{
    a.bufFree(p, cnt * (unsigned int)sizeof(T));
}
struct StringPtr
{
    void* m_data;
    __forceinline ~StringPtr()
    {
        Object_UpdateFields_00cb0c00();
    }
    void Object_UpdateFields_00cb0c00();
};
struct Bone
{
    StringPtr m_name;
    bool m_bLockTranslation;
};
struct QsTransform
{
    float v[12];
};
struct RefObject
{
    virtual ~RefObject();
    void removeReference() throw();
};
struct LocalFrameOnBone
{
    RefObject* m_pLocalFrame;
    int m_iBoneIndex;
};
template <class T> __forceinline void GenericFree(hkMemoryAllocator& a, T* const& p, const int& cnt)
{
    a.bufFree(p, cnt * (unsigned int)sizeof(T));
}
template <class T> __forceinline void AlternateFree(hkMemoryAllocator& a, void* p, const int& cnt)
{
    a.bufFree(p, cnt * (unsigned int)sizeof(T));
}
template <class T, class A> __forceinline hkArray<T, A>::~hkArray()
{
        hkMemoryAllocator& alloc = *reinterpret_cast<hkMemoryAllocator*>(hkMemoryRouter_getInstance()->m_heap);
        int sz = m_iElementCount;
        T* p = m_data;
        for (int i = 0; i < sz; ++i, ++p)
        {
            p->~T();
        }
        unsigned int flag = 0x80000000;
        unsigned int cap = m_iCapacityState;
        m_iElementCount = 0;
        if (!(cap & flag))
        {
            GenericFree<T>(alloc, m_data, cap & 0x3fffffff);
        }
        m_data = 0;
        m_iCapacityState = flag;

}
template<> __forceinline hkArray<LocalFrameOnBone>::~hkArray()
{
        hkMemoryRouter* holder = hkMemoryRouter_getInstance();
        hkMemoryAllocator& alloc = *reinterpret_cast<hkMemoryAllocator*>(holder->m_heap);
        int sz = m_iElementCount;
        LocalFrameOnBone* const p = m_data;
        for (int i = 0; i < sz; ++i)
        {
            RefObject* obj = p[i].m_pLocalFrame;
            if (obj)
            {
                obj->removeReference();
            }
            p[i].m_pLocalFrame = 0;
        }
        unsigned int flag = 0x80000000;
        unsigned int cap = m_iCapacityState;
        m_iElementCount = 0;
        if (!(cap & flag))
        {
            AlternateFree<LocalFrameOnBone>(alloc, m_data, cap & 0x3fffffff);
        }
        m_data = 0;
        m_iCapacityState = flag;
    
}
template<> __forceinline hkArray<short>::~hkArray()
{
        hkMemoryRouter* holder = hkMemoryRouter_getInstance();
        hkMemoryAllocator& alloc = *reinterpret_cast<hkMemoryAllocator*>(holder->m_heap);
        unsigned int flag = 0x80000000;
        unsigned int cap = m_iCapacityState;
        m_iElementCount = 0;
        if (!(cap & flag))
        {
            ShortFree<short>(alloc, m_data, cap & 0x3fffffff);
        }
        m_data = 0;
        m_iCapacityState = flag;
    
}
template<> __forceinline hkArray<QsTransform>::~hkArray()
{
        hkMemoryRouter* holder = hkMemoryRouter_getInstance();
        hkMemoryAllocator& alloc = *reinterpret_cast<hkMemoryAllocator*>(holder->m_heap);
        unsigned int flag = 0x80000000;
        unsigned int cap = m_iCapacityState;
        m_iElementCount = 0;
        if (!(cap & flag))
        {
            FreeArr<QsTransform>(alloc, m_data, cap & 0x3fffffff);
        }
        m_data = 0;
        m_iCapacityState = flag;
    
}
struct Base
{
    virtual ~Base()
    {}
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
class __declspec(novtable) FUN_00c7dc40 : public Base
{
  public:
    StringPtr m_name;
    hkArray<short> m_kParentIndices;
    hkArray<Bone> m_kBones;
    hkArray<QsTransform> m_kReferencePose;
    hkArray<StringPtr> m_kBoneNames;
    hkArray<LocalFrameOnBone> m_kLocalFrames;
    virtual ~FUN_00c7dc40();
};
// @fnv 0x00c7dc40
FUN_00c7dc40::~FUN_00c7dc40()
{}

typedef unsigned char u8;

struct RagdollAnimationResetView
{
    __declspec(noinline) void hkaRagdollRigidBodyController_reinitialize();
};

struct RagdollAnimBodyView
{
    void bhkWorld_Remove_00c68d50(int a1);
};

struct RagdollAnimEntry
{
    int unk00;
    int unk04;
    void* p08;
};

struct RagdollAnimOwner
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
    RagdollAnimBodyView* p350;
};

struct RagdollAnimReference
{
    int unk00;
    int unk04;
    RagdollAnimOwner* p08;
};

struct RagdollAnimHandle
{
    RagdollAnimReference* p00;
};

struct RagdollAnimData
{
    int unk00;
    int unk04;
    RagdollAnimHandle* p08;
    int unk0C;
    int unk10;
    RagdollAnimEntry** arr14;
    int count18;
};

struct RagdollAnimControllerView
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
    u8 unk40;
    u8 b41;
    u8 b42;
    u8 b43;
    int unk44;
    RagdollAnimData* p48;
    RagdollAnimationResetView* p4C;
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
    u8 unk21C;
    u8 b21D;
    u8 b21E;
    u8 unk21F;
    u8 b220;
    u8 unk221;
    u8 b222;
    u8 b223;
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
    u8 unk28C;
    u8 unk28D;
    u8 b28E;
    u8 unk28F;
    int bhkRagdollController_EnableRagdollAnim();
};

// @fnv 0x00c7a8d0
// src: XBOX_PDB 0x00c7a8d0
int RagdollAnimControllerView::bhkRagdollController_EnableRagdollAnim()
{
    if (b41 == 0 && p4C != 0)
    {
        p4C->hkaRagdollRigidBodyController_reinitialize();
    }
    u8 old = b222;
    u8 flag = b42;
    int now = b220 != 0;
    b41 = flag;
    b43 = 0;
    b222 = (u8)now;
    if (old != 0 && (u8)now == 0)
    {
        b223 = 1;
    }
    int now2 = b21D != 0;
    b21E = (u8)now2;
    if (b28E != 0 || flag == 0)
        return now2;
    {
        RagdollAnimData* z = p48;
        void* u = z->arr14[0] ? z->arr14[0]->p08 : 0;
        RagdollAnimReference* s = z->p08->p00;
        if (s != 0 && s->p08 != 0 && u != 0)
        {
            RagdollAnimBodyView* obj = s->p08->p350;
            for (int i = 0; i < z->count18; ++i)
            {
                RagdollAnimEntry* b = z->arr14[i];
                if (!!b->p08)
                {
                    obj->bhkWorld_Remove_00c68d50((int)b);
                }
            }
        }
    }
}
