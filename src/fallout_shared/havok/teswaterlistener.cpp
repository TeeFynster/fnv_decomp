#include "../../../include/SettingT.h"
#include "../../../include/EffectItem.h"
#include "../../../include/NiTMap.h"
#include "../../../include/SETTING_VALUE.h"
#include "../../../include/BSAudio.h"
#include "../../../include/PlayerCharacter.h"
#include "../../../include/TESDataHandler.h"
#include "../../../include/TESObjectCELL.h"
#include "../../../include/TESObjectREFR.h"
#include "../../../include/TESWaterForm.h"
#include "../../../include/NiMatrix3.h"
#include "../../../include/BSOcclusionPlane.h"
#include "../../../include/BSSoundHandle.h"
#include "../../../include/BSThread.h"
#include "../../../include/EffectSetting.h"
#include "../../../include/ExtraDataList.h"
#include "../../../include/GameTimerRecord.h"
#include "../../../include/TESBoundObject.h"
#include "../../../include/BGSPlaceableWater.h"
#include "../../../include/TESWaterSystem.h"
#include "../../../include/NiPoint3.h"

// src/fallout_shared/havok/teswaterlistener.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/havok/teswaterlistener.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_0062e750_shell
{
    void* __thiscall FUN_0062e750(unsigned int flags);
    void __thiscall FUN_0062e860();
};

void __cdecl _Deallocate(void* p);

// Calls FUN_0062e860, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0062e750
void* FUN_0062e750_shell::FUN_0062e750(unsigned int flags)
{
    FUN_0062e860();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

extern int DAT_011c7a3c;

// @fnv 0x0062f310
// src: COMMUNITY 0x0062f310
void TESWaterSystem_SetCurrentWaterType(int value)
{
    DAT_011c7a3c = value;
}

extern unsigned char DAT_011c7a5a;

// @fnv 0x0062f8e0
// src: COMMUNITY 0x0062f8e0
void TESWaterSystem_SetCameraInPlaceableWater(unsigned char value)
{
    DAT_011c7a5a = value;
}

extern float _DAT_011c7a5c;

// @fnv 0x0062f8f0
// src: COMMUNITY 0x0062f8f0
void TESWaterSystem_SetCameraRelevantWaterHeight(float value)
{
    _DAT_011c7a5c = value;
}

// Returns the thread ID reached through the plane's cull result and its extra data, or 0 if any step is null.
// @fnv 0x0062fec0
unsigned int __cdecl GetOcclusionPlaneThreadID(BSOcclusionPlane* pPlane)
{
    unsigned int result = 0;
    if (pPlane)
    {
        unsigned int cullResult = pPlane->GetCullResult();
        if (cullResult)
        {
            bhkWorld* room = ((ExtraDataList*)cullResult)->GetRoomId();
            if (room)
            {
                result = ((BSThread*)room)->GetThreadID();
            }
        }
    }
    return result;
}

extern "C" float __cdecl ExpFloat(float);

// @fnv 0x00630aa0
// src: COMMUNITY 0x00630aa0
float exp_00630aa0(float value)
{
    return ExpFloat(value);
}

extern "C" double __cdecl _exp(double);

// @fnv 0x00630ac0
float ExpFloat(float value)
{
    return static_cast<float>(_exp(value));
}

extern float _gModifierZero;

// Returns 1.0 for a positive input, -1.0 for a negative input, and 0.0 for zero.
// @fnv 0x00631070
float __cdecl SignOfFloat(float afValue)
{
    float result;
    if (afValue > 0.0f)
        result = 1.0f;
    else
    {
        float t;
        if (afValue < 0.0f)
            t = -1.0f;
        else
            t = 0.0f;
        result = t;
    }
    return result;
}

struct FUN_005631e0_shell
{
    int __thiscall MaskWithField(int a);
    bool __thiscall IsNonZero(int a);
};

// @fnv 0x005631e0
bool __thiscall FUN_005631e0_shell::IsNonZero(int aiValue)
{
    return MaskWithField(aiValue) != 0;
}

float __cdecl NI2HK_004a3e90(float);

struct FUN_0062e710_shell
{
    void __thiscall SetValueAt(float f, int a, int b);
};

// @fnv 0x0062e710
void __thiscall FUN_0062e710_shell::SetValueAt(float afValue, int a, int b)
{
    int index = a + b * (*(int*)((char*)this + 0x28));
    *(float*)((*(int*)((char*)this + 0x20)) + index * 4) = NI2HK_004a3e90(afValue);
}

struct BSSimpleList_Ragdoll
{
    void* __thiscall hkpMotion_getCenterOfMassInWorld();
};
struct FUN_006310c0_shell
{
    void __thiscall hkpRigidBody_getCenterOfMassInWorld();
};

// @fnv 0x006310c0
// src: XBOX_PDB 0x006310c0
void FUN_006310c0_shell::hkpRigidBody_getCenterOfMassInWorld()
{
    ((BSSimpleList_Ragdoll*)((TESDataHandler*)this)->GetBGSRagdollList())->hkpMotion_getCenterOfMassInWorld();
}

void* __cdecl bhkEntity_Getbhk(const void* p);
struct FUN_00c9a520_shell
{
    void __thiscall bhkEntityListener_RemoveEntity(void* q);
};
struct FUN_0062e940_shell
{
    void __thiscall ProcessAndForward(const void* p);
};
// @fnv 0x0062e940
void __thiscall FUN_0062e940_shell::ProcessAndForward(const void* p)
{
    void* q = bhkEntity_Getbhk(p);
    ((FUN_00c9a520_shell*)this)->bhkEntityListener_RemoveEntity(q);
}

struct FUN_00576830_shell
{
    void* __thiscall BGSZoneTargetListener_GetZoneEntry(BSOcclusionPlane* pPlane);
};

// Calls GetOcclusionPlaneThreadID on pPlane; if it returns non-null, calls FUN_00576830 on the object at offset 0x14 and returns its result, otherwise returns null.
// @fnv 0x0062fe80
// src: COMMUNITY 0x0062fe80
void* TESWaterListener_FindWater(BSOcclusionPlane* pPlane)
{
    void* result = 0;
    unsigned int cull = GetOcclusionPlaneThreadID(pPlane);
    if (cull)
        result = reinterpret_cast<FUN_00576830_shell*>(reinterpret_cast<char*>(cull) + 0x14)->BGSZoneTargetListener_GetZoneEntry(pPlane);
    return result;
}

struct FUN_0062b0a0_shell
{
    void* __thiscall FUN_0062b0a0(void* a, void* b);
};
struct FUN_00630100_shell
{
    void* __thiscall hkVector4_lengthSquared3(void* arg);
};
// Calls FUN_0062b0a0 with arg and this, then returns arg.
// @fnv 0x00630100
// src: COMMUNITY 0x00630100
void* __thiscall FUN_00630100_shell::hkVector4_lengthSquared3(void* arg)
{
    ((FUN_0062b0a0_shell*)this)->FUN_0062b0a0(arg, this);
    return arg;
}

struct PackedByteIntRecord
{
    char* __thiscall Endian();
};
// @fnv 0x006310e0
// src: XBOX_PDB 0x006310e0
void* BSSimpleList_Ragdoll::hkpMotion_getCenterOfMassInWorld()
{
    return (char*)((PackedByteIntRecord*)((char*)this + 0x10))->Endian() + 0x10;
}

struct UnkCall
{
    void __thiscall activate_00c9c1d0();
};
struct VList
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void Target(float a, int b);
};
struct FUN_00631100_shell
{
    void __thiscall hkpRigidBody_applyForce(float a, int b);
};
// Calls FUN_00c9c1d0 on this, then forwards a and b to Target on the BGSRagdollList from TESDataHandler.
// @fnv 0x00631100
// src: XBOX_PDB 0x00631100
void __thiscall FUN_00631100_shell::hkpRigidBody_applyForce(float afValue, int aiValue)
{
    ((UnkCall*)this)->activate_00c9c1d0();
    ((VList*)((TESDataHandler*)this)->GetBGSRagdollList())->Target(afValue, aiValue);
}

struct FUN_00c9c1d0_shell
{
    void __thiscall activate_00c9c1d0();
};
struct ListCall00631140
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void Target(float, int, int);
};
struct FUN_00631140_shell
{
    void __thiscall hkpRigidBody_applyForce_00631140(float, int, int);
};
// Calls FUN_00c9c1d0 on this, then forwards a, b and c to Target on the BGSRagdollList from the data handler.
// @fnv 0x00631140
// src: COMMUNITY 0x00631140
void __thiscall FUN_00631140_shell::hkpRigidBody_applyForce_00631140(float afValue, int aiArg1, int aiArg2)
{
    ((FUN_00c9c1d0_shell*)this)->activate_00c9c1d0();
    ((ListCall00631140*)((TESDataHandler*)this)->GetBGSRagdollList())->Target(afValue, aiArg1, aiArg2);
}

struct AX
{
    void __thiscall BSSimpleArray_float_1024_InitialSetup(unsigned int, unsigned int);
};
extern int DAT_0104e4bc;

struct FUN_00631750_shell
{
    void* __thiscall BSSimpleArray_hkpCollidable_const_1024_BSSimpleArray_hkpCollidable_const_1024();
};

// Sets the object's vtable pointer to DAT_0104e4bc, calls FUN_006b3eb0 with 0, 0, and returns this.
// @fnv 0x00631750
// src: XBOX_PDB 0x00631750
void* __thiscall FUN_00631750_shell::BSSimpleArray_hkpCollidable_const_1024_BSSimpleArray_hkpCollidable_const_1024()
{
    *(void**)this = &DAT_0104e4bc;
    reinterpret_cast<AX*>(this)->BSSimpleArray_float_1024_InitialSetup(0, 0);
    return this;
}

struct FUN_00628f30_shell
{
    int m0;
    int m4;
    int m8;
    int m12;
    int m16;
    int m20;
    void __thiscall bhkWorldObject_ClearFlags(int arg);
    void __thiscall SetFlag(int a, bool b);
};
// @fnv 0x00628f30
void __thiscall FUN_00628f30_shell::SetFlag(int aiFlag, bool abSet)
{
    if (abSet)
        m16 |= aiFlag;
    else
        bhkWorldObject_ClearFlags(aiFlag);
}

// Exe 0x0062e500: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct TeswaterlistenerOffset08View
{
    unsigned int GetFlags() const;
};
struct LS3de0
{
    unsigned int Find(unsigned int&, unsigned int, bool(__cdecl*)(int const*, int const*));
    void UpdateEntryValue(unsigned int, unsigned int);
};
struct FUN_0057b700_class
{
    int ZoneEntry_GetTargetEntry(int);
    void ZoneEntry_RemoveTargetEntry(int);
};
bool __cdecl Actor_AreReferencedValuesEqual(int const*, int const*);
// @fnv 0x0062e500
void EffectItem::Process(TESObjectREFR* aiKey, int auiValue)
{
    int ptarget2 = m_pEffectSetting ? ((FUN_0057b700_class*)this)->ZoneEntry_GetTargetEntry((int)aiKey) : 0;
    unsigned int uindex;
    if (ptarget2)
    {
        uindex = ((LS3de0*)((char*)ptarget2 + 0x50))->Find(*(unsigned int*)&auiValue, 0, Actor_AreReferencedValuesEqual);
        if (uindex != (unsigned int)-1)
            ((LS3de0*)((char*)ptarget2 + 0x50))->UpdateEntryValue(uindex, 1);
        if (!((TeswaterlistenerOffset08View*)((char*)ptarget2 + 0x50))->GetFlags())
            ((FUN_0057b700_class*)this)->ZoneEntry_RemoveTargetEntry(ptarget2);
    }
}

struct FUN_0061fef0_Node
{
    void* TargetEntry_QNextEntry();
};
struct WaterEntry;

// Water-specific methods not yet declared by the shared extra-data header.
struct WaterExtraDataAccess : ExtraDataList
{
    bool SetWaterZone(void*);
    void ExtraDataList_SetInWaterZone(void*, int);
    WaterEntry* Find();
    int ExtraDataList_GetFirstWaterZone();
    NiTMap<unsigned int, void*>* ExtraDataList_GetWaterZoneMap();
};
struct FUN_006205e0_shell
{
    void RemoveNode(void*);
};
struct ref_0084e3a0_shell
{
    void* ref_0084e3a0();
};
struct FUN_006312d0_shell
{
    void TESWaterListener_RemoveWaterZoneForReference(void* apWaterRef);
};
// @fnv 0x006312d0
// src: COMMUNITY 0x006312d0
void FUN_006312d0_shell::TESWaterListener_RemoveWaterZoneForReference(void* apWaterRef)
{
    void* pzone = TESWaterListener_FindWater((BSOcclusionPlane*)apWaterRef);
    if (pzone)
    {
        GameTimerRecord* pentry = (GameTimerRecord*)((GameTimerRecord*)pzone)->GetTime();
        while (pentry)
        {
            TESObjectREFR* pActor = (TESObjectREFR*)((ref_0084e3a0_shell*)((char*)pentry + 0x10))->ref_0084e3a0();
            if (pActor)
            {
                while (((WaterExtraDataAccess*)pActor->GetExtra())->SetWaterZone(pzone))
                    ((WaterExtraDataAccess*)pActor->GetExtra())->ExtraDataList_SetInWaterZone(pzone, 0);
            }
            pentry = (GameTimerRecord*)((FUN_0061fef0_Node*)pentry)->TargetEntry_QNextEntry();
        }
        ((FUN_006205e0_shell*)((char*)this + 0x14))->RemoveNode(pzone);
    }
}

extern int g_TES;
struct FUN_00631230_shell
{
    FUN_00631230_shell(TESObjectREFR*, void*);
    char m0[0x1c];
    void* pGroup;
};
struct FUN_00631180_shell
{
    FUN_00631230_shell* TESWaterListener_CreateZoneEntry(TESObjectREFR*, void*);
};
// Allocates a FUN_00631230_shell for apRef and apCol, stores the result of a call on the effect setting's object into pGroup, and returns it.
// @fnv 0x00631180
// src: XBOX_PDB 0x00631180
FUN_00631230_shell* FUN_00631180_shell::TESWaterListener_CreateZoneEntry(TESObjectREFR* apRef, void* apCol)
{
    FUN_00631230_shell* apWZone = new FUN_00631230_shell(apRef, apCol);
    apWZone->pGroup = ((TESWaterSystem*)(void*)((EffectSetting*)g_TES)->GetEffectID())
                          ->GetWaterZone(apRef, (TESObjectREFR*)0, 0.0f);
    return apWZone;
}

bool __cdecl Actor_AreReferencedValuesEqual(int const*, int const*);

struct RefList : LS3de0
{
    int list00;
    int list04;
    int list08;
    int list0C;
    unsigned int Add(unsigned int& item);
};

struct LinkBase
{
    int link00;
    int link04;
    int link08;
    int link0C;
    int link10;
    int link14;
    int link18;
    int link1C;
    int link20;
    int link24;
    int link28;
    int link2C;
    int link30;
    int link34;
    int link38;
    int link3C;
    void InsertAfterLink(int a, int b);
    void LinkTo(LinkBase* prev);
};

struct NodeHead
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

struct LinkedNode : NodeHead, LinkBase
{
    LinkedNode(int a, unsigned int b);
    static void* operator new(unsigned int size);
    static void operator delete(void*);
    RefList refs;
};

struct NodeOwner : FUN_0057b700_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    LinkedNode* pHead;
    LinkedNode* FindOrCreateNode(int key, unsigned int ref, int arg);
};

// Looks up a node by key, adds ref to its ref list if missing, or creates and links a new node into the head list.
// @fnv 0x0062e3d0
LinkedNode* NodeOwner::FindOrCreateNode(int key, unsigned int ref, int arg)
{
    LinkedNode* pNode = pHead ? (LinkedNode*)ZoneEntry_GetTargetEntry(key) : 0;
    if (pNode)
    {
        if (pNode->refs.Find(ref, 0, Actor_AreReferencedValuesEqual) == -1)
            pNode->refs.Add(ref);
    }
    else
    {
        pNode = new LinkedNode(key, ref);
        pNode->InsertAfterLink(arg, 1);
        pNode->LinkTo(pHead);
        pHead = pNode;
    }
    return pNode;
}

struct SpawnedBase
{
    SpawnedBase(int a, int b);
    virtual void Vf();
};

struct SpawnedSub
{
    SpawnedSub();
    ~SpawnedSub();
    unsigned int FUN_00719b20(const int* a, int b, bool(__cdecl* cmp)(int const*, int const*));
    void FUN_007cb2e0(const int* a);
};

struct FUN_0062e590 : SpawnedBase
{
    FUN_0062e590(int a1, int a2);
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
    SpawnedSub m_50;
};

// Constructs the base with a1 and zero, then initializes m_50 from a2, falling back to FUN_007cb2e0 when FUN_00719b20 returns -1.
// @fnv 0x0062e590
FUN_0062e590::FUN_0062e590(int a1, int aiValue) : SpawnedBase(a1, 0), m_50()
{
    if (m_50.FUN_00719b20(&aiValue, 0, Actor_AreReferencedValuesEqual) == -1)
    {
        m_50.FUN_007cb2e0(&aiValue);
    }
}

struct FUN_00cb75d0
{
    virtual void OnEvent();
    void* owner;
    unsigned int flags;
    void* context;
    unsigned int referenceCount;
    FUN_00cb75d0();
    ~FUN_00cb75d0();
};
struct FUN_0061ffb0
{
    virtual void Update();
    unsigned int state;
    FUN_0061ffb0();
    ~FUN_0061ffb0();
};
struct FUN_0048f200
{
    FUN_0048f200();
    ~FUN_0048f200();
};
struct FUN_0062e630 : FUN_00cb75d0, FUN_0061ffb0
{
    float scale;
    int* data;
    unsigned int capacity;
    unsigned int enabled;
    int predecessor;
    int successor;
    FUN_0048f200 synchronization;
    FUN_0062e630(float value);
};
// Initializes the object: sets scale to 1.0, enabled to 1, allocates data, calls SetValueAt with value, and clears predecessor and successor.
// @fnv 0x0062e630
FUN_0062e630::FUN_0062e630(float value) : scale(1.0f)
{
    enabled = 1;
    data = new int;
    reinterpret_cast<FUN_0062e710_shell*>(this)->SetValueAt(value, 0, 0);
    predecessor = 0;
    successor = 0;
}

struct S_0062f320_Tmp
{
    int unk00;
};
struct S_0062f320_Type
{
    int CFilter_GetLayer();
};
struct S_0062f320_Form
{
    int bhkRigidBody_GetMotionType();
    S_0062f320_Type* bhkWorldObject_GetCollisionFilter(S_0062f320_Tmp* t);
};
extern int DAT_012681c0;
const char* __cdecl bhkEntity_Getbhk(const char* p);
S_0062f320_Form* __cdecl NiObject_DynamicCast(int* table, const char* name);
struct S_0062f320_This
{
    S_0062f320_Form* TESWaterListener_GetRB(const char* name);
};
// Looks up a form by name in DAT_012681c0, rejects it if FUN_00517630 returns 5, and returns it only when FUN_0043b4d0 yields one of the listed values.
// @fnv 0x0062f320
// src: XBOX_PDB 0x0062f320
S_0062f320_Form* S_0062f320_This::TESWaterListener_GetRB(const char* name)
{
    const char* akey = bhkEntity_Getbhk(name);
    S_0062f320_Form* bform = NiObject_DynamicCast(&DAT_012681c0, akey);
    if (bform->bhkRigidBody_GetMotionType() == 5)
    {
        return 0;
    }
    if (bform)
    {
        S_0062f320_Tmp tmp;
        switch (bform->bhkWorldObject_GetCollisionFilter(&tmp)->CFilter_GetLayer())
        {
        case 4:
        case 5:
        case 6:
        case 8:
        case 10:
        case 12:
        case 13:
        case 14:
        case 29:
            return bform;
        }
    }
    return 0;
}

struct S_0062f5b0_Obj;

struct S_0062f5b0_Ptr
{
    S_0062f5b0_Obj* unk0;
    S_0062f5b0_Ptr(S_0062f5b0_Obj* p);
    ~S_0062f5b0_Ptr();
};

struct S_0062f5b0_Sub
{
    void BSSimpleList_NiPointer_bhkAction_AddHead(const S_0062f5b0_Ptr& p);
};

S_0062f5b0_Obj* __cdecl hkpGetRigidBody(void* a);

struct S_0062f5b0_Cls
{
    int unk00;
    int unk04;
    int unk08;
    S_0062f5b0_Sub unk0c;
    bool __thiscall TESWaterListener_collidableEnterCallback(void* a, int b);
};

// Wraps the object returned by FUN_004b59f0 in a scoped pointer, passes it to unk0c.FUN_00631540, and returns false.
// @fnv 0x0062f5b0
// src: COMMUNITY 0x0062f5b0
bool S_0062f5b0_Cls::TESWaterListener_collidableEnterCallback(void* a, int b)
{
    bool result = false;
    {
        S_0062f5b0_Ptr p(hkpGetRigidBody(a));
        unk0c.BSSimpleList_NiPointer_bhkAction_AddHead(p);
    }
    return result;
}

void* __cdecl hkpGetRigidBody(int a);

struct LocalObj
{
    unsigned int unk00;
    LocalObj(void* src);
    ~LocalObj();
};

struct MemberObj
{
    unsigned int unk00;
    void __thiscall BSSimpleList_NiPointer_bhkAction_Remove(LocalObj* p);
};

struct FUN_0062f630_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    MemberObj m_0c;

    bool ApplyToMember(int a, int unused);
};

// Builds a LocalObj from FUN_004b59f0(a), passes it to m_0c.FUN_00631620, then returns true.
// @fnv 0x0062f630
bool FUN_0062f630_cls::ApplyToMember(int a, int unused)
{
    bool done = false;
    {
        LocalObj tmp(hkpGetRigidBody(a));
        m_0c.BSSimpleList_NiPointer_bhkAction_Remove(&tmp);
    }
    done = true;
    return done;
}

extern float g_fB630120Invalid;

class B630120Grid
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
    float* m_pfValues;
    int unk24;
    unsigned int m_uiSize;

    float GetValue(unsigned int uiX, unsigned int uiY);
};

// Returns the grid value at (uiX, uiY) if the computed index is within m_uiSize squared, otherwise g_fB630120Invalid.
// @fnv 0x00630120
float B630120Grid::GetValue(unsigned int uiX, unsigned int uiY)
{
    unsigned int uiIndex = uiY * m_uiSize + uiX;
    return uiIndex < m_uiSize * m_uiSize ? m_pfValues[uiIndex] : g_fB630120Invalid;
}

struct FilterTmp_62e970
{
    int unk00;
};
struct Filter_62e970
{
    int CFilter_GetLayer();
};
struct Body_62e970
{
    Filter_62e970* bhkWorldObject_GetCollisionFilter(FilterTmp_62e970* t);
    void bhkRigidBody_GetLinearVelocity(NiPoint3& v);
    void bhkRigidBody_GetPosition(NiPoint3& v);
};
float __fastcall bhkRigidBody_GetMass(void* p);
float NiAbs_00408820(float f);
struct FloatSetting_62e970
{
    float* Float();
};
extern FloatSetting_62e970 originalRuntimeFloatSetting984;
extern FloatSetting_62e970 originalRuntimeFloatSetting985;
extern FloatSetting_62e970 originalRuntimeFloatSetting986;
struct Splash_62e970
{
    void Play(NiPoint3 pos, float scale);
};
struct TES_62e970
{
    void* GetInteriorCell();
    bool UpdateTESState(NiPoint3& pos, float& height);
    Splash_62e970* GetSplash();
};
struct TaskQueue_62e970
{
    static TaskQueue_62e970* GetInstance();
    void QueueSplash(float scale, NiPoint3* pos);
    void QueueSplashFx(float scale, NiPoint3* pos);
};
bool AILinearTaskThreadManager_ShouldQueue3DTask();
void __cdecl TESWaterListener_PlaySplashEffects(float scale, NiPoint3 pos);
extern const float kSplashScale_62e970;

struct WaterSplash_62e970
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    float fCooldown;
    void SpawnWaterSplash(Body_62e970* apBody, float afWaterZ);
};

// @fnv 0x0062e970
void WaterSplash_62e970::SpawnWaterSplash(Body_62e970* apBody, float afWaterZ)
{
    FilterTmp_62e970 tmp4;
    float fMass;
    float fScale;
    float fSpeed;
    float fHeight4;

    if (!apBody || fCooldown > 0.0)
        return;
    if (apBody->bhkWorldObject_GetCollisionFilter(&tmp4)->CFilter_GetLayer() == 8)
        return;
    fMass = bhkRigidBody_GetMass(apBody);
    NiPoint3 vel;
    apBody->bhkRigidBody_GetLinearVelocity(vel);
    fSpeed = NiAbs_00408820(vel.z);
    if (fSpeed < 0.001)
        return;
    fScale = *originalRuntimeFloatSetting985.Float() * fSpeed + fMass;
    if (vel.z > 0.0)
        fScale = fScale * *originalRuntimeFloatSetting986.Float();
    NiPoint3 _pos;
    apBody->bhkRigidBody_GetPosition(_pos);
    fHeight4 = afWaterZ;
    if (!((TES_62e970*)g_TES)->GetInteriorCell() && ((TES_62e970*)g_TES)->UpdateTESState(_pos, fHeight4) &&
        fHeight4 > afWaterZ)
        return;
    _pos.z = afWaterZ;
    if (!AILinearTaskThreadManager_ShouldQueue3DTask())
        TESWaterListener_PlaySplashEffects(fScale, _pos);
    else
        TaskQueue_62e970::GetInstance()->QueueSplash(fScale, &_pos);
    if (!AILinearTaskThreadManager_ShouldQueue3DTask())
        ((TES_62e970*)g_TES)->GetSplash()->Play(_pos, kSplashScale_62e970);
    else
        TaskQueue_62e970::GetInstance()->QueueSplashFx(kSplashScale_62e970, &_pos);
    fCooldown = *originalRuntimeFloatSetting984.Float();
}

class GameSettingCollection;
using ::SettingT;

class GlobalObject_0040e0b0
{
  public:
    float* Float();
};

class GlobalObject_0040c150
{
  public:
    const char* String();
};

extern SettingT<GameSettingCollection> originalRuntimeFloatSetting981;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting982;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting983;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting987;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting988;
extern GlobalObject_0040e0b0 g_011d1458;
extern GlobalObject_0040c150 g_011d12c0;

extern PlayerCharacter* _g_thePlayer;

float __cdecl RandomFloatTwoPi();
// These external entries take trivial by-value data. Keep their ABI argument
// storage separate from the shared types' nontrivial copy constructors; live
// matrices and points continue to use the shared definitions.
template <class T> struct TrivialValueArgument
{
    unsigned int words[sizeof(T) / sizeof(unsigned int)];
};
void* __cdecl BSTempEffectParticle_Spawn_00689210(TESObjectCELL* cell, float f1, const char* str,
                           TrivialValueArgument<NiMatrix3> mat, TrivialValueArgument<NiPoint3> pos, float f2,
                           int b1, void* p0);
bool __cdecl AILinearTaskThreadManager_ShouldQueue3DTask();

class TES_Ext
{
  public:
    TESWaterSystem* GetWaterMgr();
};

class TaskQueueInterface
{
  public:
    static TaskQueueInterface* GetSingleton();
    void QueueRipple(float amount, NiPoint3* pos);
};

// The shared audio header still declares this factory with the old handle type.
struct WaterSoundAudio : BSAudio
{
    BSSoundHandle BSAudio_GetSoundHandleByEditorName(const char* editorID, unsigned int flags);
};

// @fnv 0x0062eb50
// src: XBOX_PDB 0x0062eb50
void __cdecl TESWaterListener_PlaySplashEffects(float a1, NiPoint3 aPosition)
{
    float fMult = 1.0f;
    BSSoundHandle kSound;

    if (a1 > originalRuntimeFloatSetting981.Float()[0])
    {
        kSound = static_cast<WaterSoundAudio*>(BSAudio::GetSingleton())->BSAudio_GetSoundHandleByEditorName("CWaterLarge", 0x102);
        fMult = *g_011d1458.Float();
    }
    if (!kSound.IsValid() && a1 > originalRuntimeFloatSetting982.Float()[0])
    {
        kSound = static_cast<WaterSoundAudio*>(BSAudio::GetSingleton())->BSAudio_GetSoundHandleByEditorName("CWaterMedium", 0x102);
        fMult = originalRuntimeFloatSetting987.Float()[0];
    }
    if (!kSound.IsValid() && a1 > originalRuntimeFloatSetting983.Float()[0])
    {
        kSound = static_cast<WaterSoundAudio*>(BSAudio::GetSingleton())->BSAudio_GetSoundHandleByEditorName("CWaterSmall", 0x102);
        fMult = originalRuntimeFloatSetting988.Float()[0];
    }
    if (kSound.IsValid())
    {
        kSound.SetPosition(aPosition.x, aPosition.y, aPosition.z);
        kSound.Play(false);
        if (fMult > 0.0 && _g_thePlayer->GetParentCell() && _g_thePlayer->GetParentCell()->Actor_GetRadiationLevel() &&
            !_g_thePlayer->GetParentCell()->Actor_GetRadiationLevel()->IsDangerous())
        {
            NiMatrix3 kMat;
            kMat.MakeZRotation(RandomFloatTwoPi());
            BSTempEffectParticle_Spawn_00689210(_g_thePlayer->GetParentCell(), 1.0f, g_011d12c0.String(),
                         reinterpret_cast<const TrivialValueArgument<NiMatrix3>&>(kMat),
                         reinterpret_cast<const TrivialValueArgument<NiPoint3>&>(aPosition), fMult, 1, 0);
        }
    }
    if (!AILinearTaskThreadManager_ShouldQueue3DTask())
    {
        ((TES_Ext*)g_TES)->GetWaterMgr()->AddWaterRipple(aPosition, 0.01f);
    }
    else
    {
        TaskQueueInterface::GetSingleton()->QueueRipple(0.01f, &aPosition);
    }
}

#include <xmmintrin.h>
struct FUN_00630d30_cls
{
    __m128 m_vec;
    void AddComponentProductInPlace(const __m128* a, const __m128* b);
};
// Adds the element-wise product of two vectors to m_vec using SSE intrinsics.
// @fnv 0x00630d30
// src: GUESS 0x00630d30 (confidence: high)
void FUN_00630d30_cls::AddComponentProductInPlace(const __m128* apFirst, const __m128* apSecond)
{
    m_vec = _mm_add_ps(m_vec, _mm_mul_ps(*apFirst, *apSecond));
}

class B631230Base
{
  public:
    B631230Base(TESObjectREFR* pkActor, unsigned int uiType);
    virtual ~B631230Base();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class FUN_00631230 : public B631230Base
{
  public:
    float m_fStartValue;
    int m_iArrayLength;

    FUN_00631230(TESObjectREFR* pkActor, unsigned int uiType);
    virtual ~FUN_00631230();
};

// @fnv 0x00631230
FUN_00631230::FUN_00631230(TESObjectREFR* pkActor, unsigned int uiType) : B631230Base(pkActor, uiType)
{
    m_fStartValue = pkActor ? static_cast<const TESObjectREFR*>(pkActor)->GetPos()->z : 0.0f;
    m_iArrayLength = 0;
}

struct PhysBody
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
    virtual PhysBody* Body();
};
struct Collision
{
    PhysBody* GetWorld();
};
struct Scene
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
    virtual Collision* CollisionData();
};
struct SceneHolder
{
    Scene* GetScene();
};
TESObjectREFR* __cdecl TESHavokUtilities_FindCollidableRef(void*);
// The shared cell header does not yet declare the water-height accessor.
struct CellWaterAccess : TESObjectCELL
{
    float Height();
};
struct WaterSub
{
    TESObjectREFR* Ref();
};
struct WaterEntry
{
    int unk00;
    WaterSub sub;
};
struct PlayerHandle
{
    void* Get();
};
struct SettingWater
{
    unsigned char* Bool();
};
extern SettingWater g_011cc5a8;
void __cdecl ResetWater(int);
void TESWaterSystem_SetCameraRelevantWaterHeight(float);
void TESWaterSystem_SetCameraInPlaceableWater(unsigned char);
void TESWaterSystem_SetCurrentWaterType(int);
struct WaterRecord
{
    TESObjectREFR* reference;
    PhysBody* body;
    TESObjectREFR* water;
    struct Group* group;
    void* source;
};
struct Group
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    void* data;
};
struct GroupMap
{
    Group* Find(void*);
};
struct RecordList
{
    void* Head();
    WaterRecord*& Get(void*);
    void* Next(void*);
    void Add(WaterRecord* const&);
};
struct EventWater
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    void* water;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    void* reference;
};
extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int);
void* __cdecl operator new(unsigned int);
struct WaterManager
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    GroupMap* groups;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    RecordList records;
    void Process(WaterRecord*);
    bool TESWaterListener_contactPointRemovedCallback(EventWater* event);
};
// Resolves the event's water and reference, checks restrictions, then handles the player case or records or processes the reference.
// @fnv 0x0062f900
// src: COMMUNITY 0x0062f900
bool WaterManager::TESWaterListener_contactPointRemovedCallback(EventWater* event)
{
    bool f = false;
    TESObjectREFR* s = TESHavokUtilities_FindCollidableRef(event->reference);
    TESObjectREFR* eb = TESHavokUtilities_FindCollidableRef(event->water);
    if (!eb)
        return false;
    BGSPlaceableWater* i = dynamic_cast<BGSPlaceableWater*>(eb->GetBase());
    if (!*g_011cc5a8.Bool() && i->IsRestricted())
        return false;
    Group* p = groups ? groups->Find(event->water) : 0;
    Group* q = p;
    void* cf = q ? q->data : 0;
    if (!s && _g_thePlayer->GetParentCell())
    {
        if (event->reference == ((PlayerHandle*)_g_thePlayer->QCameraRigidBody())->Get())
        {
            ResetWater(0);
            TESWaterSystem_SetCameraRelevantWaterHeight(((CellWaterAccess*)_g_thePlayer->GetParentCell())->Height());
            TESWaterSystem_SetCameraInPlaceableWater(0);
            WaterEntry* entry = ((WaterExtraDataAccess*)_g_thePlayer->TESObjectREFR::BSFile_GetDevice())->Find();
            if (entry)
            {
                TESBoundObject* ref = entry->sub.Ref()->GetBase();
                TESWaterSystem_SetCurrentWaterType((int)static_cast<const TESObject*>(ref)->GetAssociatedWaterForm());
            }
            else
            {
                TESWaterSystem_SetCurrentWaterType((int)_g_thePlayer->GetParentCell()->Actor_GetRadiationLevel());
            }
            return true;
        }
        return false;
    }
    else if (!s)
    {
        return false;
    }
    else if (s->IsDeleted())
    {
        return false;
    }
    PhysBody* a = 0;
    Scene* h = ((SceneHolder*)s->GetNiNode())->GetScene();
    if (h)
    {
        Collision* collision = h->CollisionData();
        if (collision)
        {
            PhysBody* world = collision->GetWorld();
            if (world)
                a = world->Body();
        }
    }
    {
        void* p;
        int h;
        bool found8;
        WaterRecord* item5;
        WaterRecord* record3;
        WaterRecord recordX;
        unsigned int size;
        void* allocationX;
        if (a)
        {
            p = records.Head();
            h = 0;
            found8 = false;
            while (p)
            {
                item5 = records.Get(p);
                p = records.Next(p);
                if (item5->body == a)
                {
                    found8 = true;
                    break;
                }
            }
            if (!found8)
            {
                size = sizeof(WaterRecord);
                allocationX = operator new(size);
                record3 = allocationX ? (fnv_zlib_memset(allocationX, 0, size), (WaterRecord*)allocationX) : 0;
                record3->reference = s;
                record3->body = a;
                record3->water = eb;
                record3->group = q;
                record3->source = event->reference;
                records.Add(record3);
            }
        }
        else
        {

            recordX.reference = s;
            recordX.body = a;
            recordX.water = eb;
            recordX.group = q;
            recordX.source = event->reference;
            Process(&recordX);
        }
    }
    return true;
}

TESObjectREFR* __cdecl TESHavokUtilities_FindCollidableRef(void* handle);
struct PlayerWaterReference
{
    void* GetSourceFilesFromObject();
};
// Water-contact methods not yet declared by the shared reference header.
struct WaterContactReference : TESObjectREFR
{
    void TESObjectREFR_SetInZone(void* update, int enabled);
    void TESObjectREFR_SetUnderwater(int enabled);
};
void __cdecl TESWaterSystem_SetPlayerForceUnderwater(int enabled);
struct WaterRequest
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    void* source;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    void* destination;
};
struct WaterUpdates
{
    void* BGSZoneTargetListener_AddZoneTargetPair(WaterRequest*, TESObjectREFR*, TESObjectREFR*, int, int);
};
struct WaterTaskQueue
{
    void TaskQueueInterface_QueueWaterObjectForAdd(TESObjectREFR*, TESObjectREFR*, float);
};
WaterTaskQueue* __cdecl FUN_004537b0();
bool __cdecl AILinearTaskThreadManager_ShouldQueue3DTask();
struct TESWaterAccess
{
    TESWaterSystem* DetailedActorPathHandler_GetCurrentNodeIndex();
};
struct WaterOwner
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    WaterUpdates updates;
    void TESWaterListener_HandleQueuedRemovals(TESObjectREFR*, int, int);
    bool TESWaterListener_contactPointAddedCallback(WaterRequest* request);
};
// Processes a water request by resolving source and destination references, checking restrictions, and dispatching water contact updates.
// @fnv 0x0062f6b0
// src: XBOX_PDB 0x0062f6b0
bool WaterOwner::TESWaterListener_contactPointAddedCallback(WaterRequest* request)
{
    bool e = false;
    TESObjectREFR* d = TESHavokUtilities_FindCollidableRef(request->destination);
    if (!d)
    {
        if (request->destination == ((PlayerWaterReference*)_g_thePlayer->QCameraRigidBody())->GetSourceFilesFromObject())
        {
            TESObjectREFR* f = TESHavokUtilities_FindCollidableRef(request->source);
            if (!f)
                return false;
            BGSPlaceableWater* g = dynamic_cast<BGSPlaceableWater*>(f->GetBase());
            if (!*g_011cc5a8.Bool() && g->IsRestricted())
                return false;
            TESWaterSystem_SetCameraRelevantWaterHeight(static_cast<const TESObjectREFR*>(f)->GetPos()->z);
            TESWaterSystem_SetPlayerForceUnderwater(1);
            TESWaterSystem_SetCameraInPlaceableWater(1);
            TESWaterSystem_SetCurrentWaterType((int)static_cast<const TESObject*>(g)->GetAssociatedWaterForm());
            return true;
        }
        return false;
    }
    TESObjectREFR* b = TESHavokUtilities_FindCollidableRef(request->source);
    if (!b)
        return false;
    BGSPlaceableWater* c = dynamic_cast<BGSPlaceableWater*>(b->GetBase());
    if (!*g_011cc5a8.Bool() && c->IsRestricted())
        return false;
    if (d == (TESObjectREFR*)_g_thePlayer)
        TESWaterSystem_SetCurrentWaterType((int)static_cast<const TESObject*>(c)->GetAssociatedWaterForm());
    void* a = updates.BGSZoneTargetListener_AddZoneTargetPair(request, b, d, 0, 0);
    ((WaterContactReference*)d)->TESObjectREFR_SetInZone(a, 1);
    if (AILinearTaskThreadManager_ShouldQueue3DTask() && FUN_004537b0())
    {
        FUN_004537b0()->TaskQueueInterface_QueueWaterObjectForAdd(b, d, 0.0f);
    }
    else
    {
        TESWaterSystem* h = ((TESWaterAccess*)g_TES)->DetailedActorPathHandler_GetCurrentNodeIndex();
        h->SetWaterHeight(b, d, 0.0f);
    }
    TESWaterListener_HandleQueuedRemovals(d, 0, 1);
    return true;
}

struct Holder0087b4f0
{
    void TaskQueueInterface_QueueWaterObjectForRemove(int a, int b, float c);
};

bool AILinearTaskThreadManager_ShouldQueue3DTask();

unsigned int __fastcall DetailedActorPathHandler_GetCurrentNodeIndex(char* p);

struct ParamStruct
{
    TESObjectREFR* unk00;
    FUN_00628f30_shell* unk04;
    TESObjectREFR* unk08;
    EffectItem* unk0c;
    int unk10;
};

struct WaterZoneRemoval : WaterSplash_62e970
{
    void TESWaterListener_RemoveReferenceFromZone(ParamStruct* param);
};

// @fnv 0x0062fc70
// src: XBOX_PDB 0x0062fc70
void WaterZoneRemoval::TESWaterListener_RemoveReferenceFromZone(ParamStruct* apParams)
{
    bool b5;
    bool b8 = false;
    bool b9;
    void* var_8 = apParams->unk0c ? apParams->unk0c->Conditions.m_kConditionItems.m_item : 0;

    if (apParams->unk00 == (TESObjectREFR*)_g_thePlayer && b8)
    {
        if (_g_thePlayer->GetParentCell())
        {
            TESWaterSystem_SetCurrentWaterType((int)_g_thePlayer->GetParentCell()->Actor_GetRadiationLevel());
        }
    }

    b9 = false;
    if (apParams->unk0c)
    {
        apParams->unk0c->Process(apParams->unk00, apParams->unk10);
        if (!apParams->unk0c->GetEffectSetting())
        {
            b9 = true;
        }
    }

    if (apParams->unk04)
    {
        this->SpawnWaterSplash((Body_62e970*)apParams->unk04, static_cast<const TESObjectREFR*>(apParams->unk08)->GetPos()->z);
        apParams->unk04->SetFlag(0x80, false);
    }

    if (apParams->unk0c)
    {
        ((WaterContactReference*)apParams->unk00)->TESObjectREFR_SetInZone(apParams->unk0c, 0);
    }
    ((WaterContactReference*)apParams->unk00)->TESObjectREFR_SetUnderwater(0);

    b5 = true;
    if (!((WaterExtraDataAccess*)apParams->unk00->GetExtraData())->ExtraDataList_GetFirstWaterZone())
    {
        NiTMap<unsigned int, void*>* map4 = ((WaterExtraDataAccess*)apParams->unk00->GetExtraData())->ExtraDataList_GetWaterZoneMap();
        if (map4)
        {
            void* pos4 = map4->GetFirstPos();
            while (pos4)
            {
                void* val = 0;
                unsigned int keyTmp = 0;
                map4->GetNext(pos4, keyTmp, val);
                if (var_8 != 0 && ((EffectItem*)keyTmp)->Conditions.m_kConditionItems.m_item == var_8)
                {
                    b5 = false;
                    break;
                }
            }
        }
    }

    if (b5)
    {
        if (AILinearTaskThreadManager_ShouldQueue3DTask() && TaskQueueInterface::GetSingleton())
        {
            ((Holder0087b4f0*)TaskQueueInterface::GetSingleton())
                ->TaskQueueInterface_QueueWaterObjectForRemove((int)apParams->unk08, (int)apParams->unk00, 0.0f);
        }
        else
        {
            TESWaterSystem* pWaterSystem7 = (TESWaterSystem*)DetailedActorPathHandler_GetCurrentNodeIndex((char*)g_TES);
            pWaterSystem7->UpdateWaterZone((TESObjectREFR*)apParams->unk08, (TESObjectREFR*)apParams->unk00, 0.0f);
        }
    }
}
