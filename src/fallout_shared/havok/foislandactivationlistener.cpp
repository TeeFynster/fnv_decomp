
// src/fallout_shared/havok/foislandactivationlistener.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/havok/foislandactivationlistener.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/BSXFlags.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/TESObjectREFR.h"
#include "../../../include/hkpIslandActivationListener.h"
extern "C" void __cdecl _Deallocate(void*);

// Calls InitPtr, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x006241e0
void* hkpIslandActivationListener::vf00(unsigned int flags)
{
    InitPtr();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

extern int DAT_0104de10;

// @fnv 0x00624210
void hkpIslandActivationListener::InitPtr()
{
    *reinterpret_cast<int**>(this) = &DAT_0104de10;
}

extern int DAT_011f942c;

// @fnv 0x00624bd0
// src: COMMUNITY 0x00624bd0
void BSShaderManager_ResetMotionBluredObject()
{
    DAT_011f942c = 0;
}

struct hkVector4;
struct NiTransform;
struct TopicH
{
    NiPoint3* GetAddTopicList();
    NiPoint3& _ref_006815c0();
};
void HK2NI_00624b10(NiTransform*, NiPoint3*);
NiPoint3& SetNiPoint3FromHkVector4(NiPoint3&, const hkVector4&);

// @fnv 0x00624ad0
// src: COMMUNITY 0x00624ad0
NiTransform* HK2NI_00624ad0(NiTransform* arNiTran, TopicH* arTopicH)
{
    HK2NI_00624b10(arNiTran, &arTopicH->_ref_006815c0());
    SetNiPoint3FromHkVector4(*(NiPoint3*)((char*)arNiTran + 0x24), *(const hkVector4*)arTopicH->GetAddTopicList());
    return arNiTran;
}

// FUN_006228e0 is an NiTArray<T>::SetAtGrow of an unknown element type: this local view holds its SetSize call
struct FUN_006228e0_ArrayView
{
    void SetSize(unsigned int);
};
struct FUN_006228e0_shell
{
    unsigned int SetAt(unsigned int, void*);
    unsigned short m_iElementCount;
    unsigned short m_cap;
    unsigned int NiTObjectArray_NiPointer_bhkRigidBody_SetAtGrow(unsigned int, void*);
};
// @fnv 0x006228e0
// src: COMMUNITY 0x006228e0
unsigned int FUN_006228e0_shell::NiTObjectArray_NiPointer_bhkRigidBody_SetAtGrow(unsigned int n, void* p)
{
    if (n >= *(unsigned short*)((char*)this + 8))
        ((FUN_006228e0_ArrayView*)this)->SetSize(*(unsigned short*)((char*)this + 0xe) + n);
    SetAt(n, p);
    return n;
}

extern "C" void __cdecl _Deallocate(void*);
struct FUN_00624190_shell
{
    void FUN_00624230();
    void* FUN_00624190(unsigned int flags);
};
// Calls FUN_00624230, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00624190
void* FUN_00624190_shell::FUN_00624190(unsigned int flags)
{
    FUN_00624230();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

// @fnv 0x006241c0
hkpIslandActivationListener* __fastcall InitializeIslandActivationListener(hkpIslandActivationListener* listener)
{
    *reinterpret_cast<int**>(listener) = &DAT_0104de10;
    return listener;
}

extern "C" int __cdecl bhkUtilFunctions_GetNiAVObject(int);
struct FUN_00807730_shell
{
    TESObjectREFR* bhkCharacterListenerSpell_GetObjectREFR(void* p);
};
// Calls FUN_00c7fa90 on p; if it returns non-zero, resolves that value to a TESObjectREFR and returns it, otherwise returns null.
// @fnv 0x00807730
// src: XBOX_PDB 0x00807730
TESObjectREFR* FUN_00807730_shell::bhkCharacterListenerSpell_GetObjectREFR(void* p)
{
    TESObjectREFR* result = 0;
    int blood = bhkUtilFunctions_GetNiAVObject((int)p);
    if (blood)
        result = TESObjectREFR::GetReferenceFromNiAVObject((void*)blood);
    return result;
}

extern int DAT_011f942c;

// @fnv 0x00624560
// src: COMMUNITY 0x00624560
void __cdecl BSShaderManager_AddMotionBluredObject()
{
    DAT_011f942c = DAT_011f942c + 1;
}

struct FUN_00573eb0_Class
{
    int NiPathInterpolator_GetBit(int);
    int bhkNiCollisionObject_GSetLocal();
};

// src: XBOX_PDB 0x0047b4d0
int FUN_00573eb0_Class::NiPathInterpolator_GetBit(int)
{
    return NiPathInterpolator_GetBit(8);
}

// @fnv 0x00624bb0
// src: COMMUNITY 0x00624bb0
int FUN_00573eb0_Class::bhkNiCollisionObject_GSetLocal()
{
    return NiPathInterpolator_GetBit(8);
}

extern "C" unsigned int __cdecl GetExtraDataChecked(unsigned int);
// @fnv 0x00624b70
unsigned int GetBSXFlags(unsigned int a, unsigned int uiFlags)
{
    BSXFlags* p = (BSXFlags*)GetExtraDataChecked(a);
    return p ? p->GetFlags(uiFlags) : 0;
}

struct FUN_00c91840_shell
{
    void RemovePointer(void*);
};
struct FUN_00c917a0_shell
{
    void hkpWorld_removeEntityListener(void*);
};
struct FUN_006242f0_shell
{
    void NotifyListener(void*);
};
// If listener is non-null, calls its RemovePointer with this and its FUN_00c917a0 with this+4.
// @fnv 0x006242f0
void FUN_006242f0_shell::NotifyListener(void* listener)
{
    if (listener)
    {
        ((FUN_00c91840_shell*)listener)->RemovePointer(this);
        ((FUN_00c917a0_shell*)listener)->hkpWorld_removeEntityListener(this ? (char*)this + 4 : 0);
    }
}

struct BaseDtor_b4091
{
    virtual void unk00();
    ~BaseDtor_b4091();
};

struct MemberDtor_b4091
{
    virtual void unk00();
    ~MemberDtor_b4091();
};

struct FUN_00624230 : BaseDtor_b4091, MemberDtor_b4091
{
    virtual void unk08();
    ~FUN_00624230();
};

// @fnv 0x00624230
FUN_00624230::~FUN_00624230()
{}

NiPoint3& SetNiPoint3FromHkVector4_004a3970(NiPoint3& dest, const hkVector4& src);

struct FUN_004b4cf0_shell
{
    hkVector4* FUN_004b4cf0(unsigned int i);
};

struct FUN_004769c0_shell
{
    void FUN_004769c0(unsigned int i, float* p);
};

// @fnv 0x00624b10
// src: COMMUNITY 0x00624b10
FUN_004769c0_shell* HK2NI_00624b10(FUN_004769c0_shell* dest, FUN_004b4cf0_shell* src)
{
    NiPoint3 vec;

    for (unsigned int i = 0; i < 3; i++)
    {
        SetNiPoint3FromHkVector4_004a3970(vec, *src->FUN_004b4cf0(i));
        dest->FUN_004769c0(i, (float*)&vec);
    }

    return dest;
}

struct ActivationBaseA
{
    int value;
};
struct ActivationBaseB
{
    int value;
};
struct ActivationListener
{
    void hkpWorld_addIslandActivationListener(void* owner);
    void hkpWorld_addEntityListener(ActivationBaseB* owner);
};
struct FUN_006242a0_cls : ActivationBaseA, ActivationBaseB
{
    void NotifyActivation(ActivationListener* listener);
};
// If listener is non-null, calls its FUN_00c938a0 with this and its FUN_00c93820 with this cast to ActivationBaseB.
// @fnv 0x006242a0
void FUN_006242a0_cls::NotifyActivation(ActivationListener* listener)
{
    if (listener)
    {
        listener->hkpWorld_addIslandActivationListener(this);
        listener->hkpWorld_addEntityListener(static_cast<ActivationBaseB*>(this));
    }
}

struct FUN_005609f0_shell
{
    char m_val;
    FUN_005609f0_shell(const FUN_005609f0_shell&);
    bool FUN_005609f0();
};

struct Type8
{
    int hkpCollidable_getCollisionFilterInfo();
};

struct ArgType
{
    FUN_005609f0_shell isActive_00c9bff0();
    Type8* TESDataHandler_GetWorldSpaceList();
};

struct CF845
{
    int m_val;
    CF845(int);
    int CFilter_GetLayer();
};

class NiRTTI;
extern NiRTTI DAT_012681c0;

struct Type2;
struct Type5;

struct Type4
{
    Type5* FUN_005497a0();
};

struct Type3
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
    virtual void v39();
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
    virtual bool vfunc_100();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v4a();
    virtual void v4b();
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual bool vfunc_150();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v5a();
    virtual void v5b();
    virtual void v5c();
    virtual void v5d();
    virtual void v5e();
    virtual void v5f();
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
    virtual void v6a();
    virtual void v6b();
    virtual void v6c();
    virtual void v6d();
    virtual void v6e();
    virtual void v6f();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void* vfunc_1d0(int);

    Type4* FUN_008d6f30();
};

struct Type5
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
    virtual void vfunc_dc(void*);
};

struct Type7
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
    virtual void vfunc_e4(int);
};

struct Type1
{
    Type2* FUN_0044ddc0();
};

Type1* __cdecl FUN_004b5a50(void*);
Type3* __cdecl TESObjectREFR_FindReferenceFor3D(Type2*);
bool __cdecl AILinearTaskThreadManager_ShouldQueue3DTask();
void __cdecl TESObjectCELL_QueueAttachChild(Type3*, Type5*);
void* __cdecl bhkEntity_Getbhk(void*);
bool __cdecl NiObject_IsKindOf(const NiRTTI*, void*);

struct FUN_00624340_shell
{
    void ProcessArgType(ArgType* arg1);
};

// @fnv 0x00624340
void FUN_00624340_shell::ProcessArgType(ArgType* apArg)
{
    if (apArg)
    {
        Type3* kVar4;
        Type2* _var8;
        Type1* varC6;
        Type4* varX;
        Type5* var5;
        Type3* var18;
        Type2* var1C8;
        Type1* var2;
        void* varVal;
        Type7* var3;

        if (apArg->isActive_00c9bff0().FUN_005609f0())
        {
            varC6 = FUN_004b5a50(apArg);
            _var8 = varC6 ? varC6->FUN_0044ddc0() : 0;
            kVar4 = _var8 ? TESObjectREFR_FindReferenceFor3D(_var8) : 0;
            if (kVar4 && !kVar4->vfunc_100())
            {
                varX = kVar4->FUN_008d6f30();
                var5 = varX ? varX->FUN_005497a0() : 0;
                if (var5)
                {
                    if (AILinearTaskThreadManager_ShouldQueue3DTask())
                    {
                        TESObjectCELL_QueueAttachChild(kVar4, var5);
                    }
                    else
                    {
                        var5->vfunc_dc(kVar4->vfunc_1d0(1));
                    }
                }
                if (kVar4->vfunc_150())
                {
                    BSShaderManager_AddMotionBluredObject();
                }
            }
        }
        else
        {
            if (CF845(apArg->TESDataHandler_GetWorldSpaceList()->hkpCollidable_getCollisionFilterInfo()).CFilter_GetLayer() == 0x14)
            {
                var2 = FUN_004b5a50(apArg);
                var1C8 = var2 ? var2->FUN_0044ddc0() : 0;
                var18 = var1C8 ? TESObjectREFR_FindReferenceFor3D(var1C8) : 0;
                if (var18 && !var18->vfunc_100())
                {
                    varVal = bhkEntity_Getbhk(apArg);
                    if (varVal && NiObject_IsKindOf(&DAT_012681c0, varVal))
                    {
                        var3 = (Type7*)varVal;
                        var3->vfunc_e4(4);
                    }
                }
            }
        }
    }
}

namespace fnv_00624580 {
struct SceneList
{
    SceneList* GetExtraPartList();
    int FUN_00726070();
    void** NiTSet_NiControllerSequence_NiTMallocInterface_NiControllerSequence_GetAt(int offset);
};
struct Geometry
{
    Geometry* FUN_0044ddc0();
    Geometry* FUN_005497a0();
};
struct SceneObject
{
    Geometry* FUN_008d6f30();
};
Geometry* __cdecl FUN_004b5a50(void* object);
SceneObject* __cdecl TESObjectREFR_FindReferenceFor3D(Geometry* object);
bool __cdecl AILinearTaskThreadManager_ShouldQueue3DTask();
void __cdecl TESObjectCELL_QueueAttachChild(SceneObject* object, Geometry* geometry);
void __cdecl BSShaderManager_AddMotionBluredObject();
struct FUN_00624580_Class
{
    void __thiscall FOIslandActivationListener_islandActivatedCallback(SceneList* object);
};
// @fnv 0x00624580
// src: COMMUNITY 0x00624580
void FUN_00624580_Class::FOIslandActivationListener_islandActivatedCallback(SceneList* pSceneList)
{
    if (!pSceneList)
        return;
    SceneList* count = pSceneList->GetExtraPartList();
    int iItemCount = count->FUN_00726070();
    void* pEntry;
    for (int sceneObject = 0; sceneObject < iItemCount; ++sceneObject)
    {
        pEntry = *count->NiTSet_NiControllerSequence_NiTMallocInterface_NiControllerSequence_GetAt(sceneObject);
        Geometry* handle = FUN_004b5a50(pEntry);
        Geometry* geometry = handle ? handle->FUN_0044ddc0() : 0;
        SceneObject* parent = geometry ? TESObjectREFR_FindReferenceFor3D(geometry) : 0;
        if (parent)
        {
            typedef unsigned char(__thiscall * Predicate)(SceneObject*);
            typedef void(__thiscall * Dispatch)(SceneObject*, int);
            typedef int(__thiscall * Retrieve)(SceneObject*, int);
            if (!reinterpret_cast<Predicate>((*reinterpret_cast<void***>(parent))[64])(parent))
            {
                reinterpret_cast<Dispatch>((*reinterpret_cast<void***>(parent))[18])(parent, 4);
                Geometry* target;
                Geometry* owner = parent->FUN_008d6f30();
                target = owner ? owner->FUN_005497a0() : 0;
                if (target)
                {
                    if (AILinearTaskThreadManager_ShouldQueue3DTask())
                        TESObjectCELL_QueueAttachChild(parent, target);
                    else
                        reinterpret_cast<Dispatch>((*reinterpret_cast<void***>(target))[55])(
                            reinterpret_cast<SceneObject*>(target),
                            reinterpret_cast<Retrieve>((*reinterpret_cast<void***>(parent))[116])(parent, 1));
                }
                if (reinterpret_cast<Predicate>((*reinterpret_cast<void***>(parent))[84])(parent))
                    BSShaderManager_AddMotionBluredObject();
            }
        }
    }
}
}  // namespace fnv_00624580
