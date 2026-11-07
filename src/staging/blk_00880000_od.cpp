
// src/staging/blk_00880000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/Bound.h"
#include "../../include/NiFixedString.h"
#include "../../include/NiPoint3.h"
#include "../../include/TESObject.h"
#include "../../include/TESPackage.h"
#include "../../include/TESActorBase.h"
#include "../../include/TESCreature.h"
#include "../../include/Actor.h"
#include "../../include/TESObjectREFR.h"

// Intrinsic copies preserve the original point-copy instructions in this /Od unit.
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
#pragma intrinsic(memcpy)

// @fnv 0x00884c60
// src: COMMUNITY 0x00884c60
void Actor::ClearMoveModeAll()
{
    StopMoving();
}

struct FUN_00885a30_Class
{
    bool __thiscall IsFlag20000000Set();
};

// @fnv 0x00885a30
bool FUN_00885a30_Class::IsFlag20000000Set()
{
    return ((*(int*)((char*)this + 8)) & 0x20000000) ? true : false;
}

struct FUN_00888a20_Class
{
    void SetFloats(float a, float b);
};

// Stores two float arguments at offsets 0x150 and 0x154 of this object.
// @fnv 0x00888a20
void FUN_00888a20_Class::SetFloats(float afFirst, float afSecond)
{
    *(float*)((char*)this + 0x150) = afFirst;
    *(float*)((char*)this + 0x154) = afSecond;
}

struct FUN_00888a70_class
{
    void __thiscall bhkRagdollController_GetEyeAngles(float* a, float* b);
};

// Reads the two floats at offsets 0x19c and 0x1a0 of this object and writes them to the output pointers.
// @fnv 0x00888a70
// src: COMMUNITY 0x00888a70
void __thiscall FUN_00888a70_class::bhkRagdollController_GetEyeAngles(float* a, float* b)
{
    *a = *(float*)((char*)this + 0x19c);
    *b = *(float*)((char*)this + 0x1a0);
}

struct FUN_00888aa0_Class
{
    void ClearField23C();
};

// @fnv 0x00888aa0
void FUN_00888aa0_Class::ClearField23C()
{
    *(float*)((char*)this + 0x23c) = 0.0f;
}

struct FUN_00620760_class
{
    void SetFlags(int, int);
};

struct FUN_00891130_class
{
    void SetFlags_Thunk(unsigned char a);
};

// @fnv 0x00891130
// src: GUESS 0x00891130 (confidence: medium)
void FUN_00891130_class::SetFlags_Thunk(unsigned char aValue)
{
    ((FUN_00620760_class*)((char*)this + 0x10))->SetFlags(1, (int)aValue);
}


struct FUN_008859e0_Class
{
    bool __thiscall Actor_CanChildUseObject(TESObject* a);
};

// Returns true unless the next form's type is 0x15, 0x27 or 0x30, in which case it returns the result of IsFlag20000000Set on that form.
// @fnv 0x008859e0
// src: XBOX_PDB 0x008859e0
bool __thiscall FUN_008859e0_Class::Actor_CanChildUseObject(TESObject* pObject)
{
    bool result = true;
    switch (pObject->GetNext()->FNV_GetFormType())
    {
    case 0x15:
    case 0x27:
    case 0x30:
        result = ((FUN_00885a30_Class*)pObject->GetNext())->IsFlag20000000Set();
        break;
    }
    return result;
}

struct FUN_008c1be0_Class
{
    unsigned int bhkTTNode_TESObjectREFR_GetFlags(unsigned int);
};
struct FUN_00891150_Class
{
    bool TargetEntry_QHit();
};
// @fnv 0x00891150
// src: XBOX_PDB 0x00891150
bool FUN_00891150_Class::TargetEntry_QHit()
{
    return ((FUN_008c1be0_Class*)((char*)this + 0x10))->bhkTTNode_TESObjectREFR_GetFlags(1) != 0;
}

void* operator new(unsigned int);

void* __fastcall Actor_ForceStopMoving(void*);

struct LocationDescriptor
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;

    LocationDescriptor();
    ~LocationDescriptor();
    void PackageLocation_SetLocReference(TESObjectREFR*);
};

// @fnv 0x008984c0
// src: COMMUNITY 0x008984c0
void TESObjectREFR::Actor_InitiateSurfacePackage()
{
    Actor_ForceStopMoving(this);

    TESPackage* packageLocation = TESPackage::CreatePackageForType(0x1d);
    packageLocation->SetPackageType(0x1d);
    packageLocation->SetMustReachLocation(true);
    packageLocation->SetMustComplete(true);

    LocationDescriptor* package = new LocationDescriptor;
    package->PackageLocation_SetLocReference(this);
    packageLocation->SetPackageLocation(package);

    delete package;

    packageLocation->SetTargetFromReference(0);
    // The package virtual at 0x2f4 is not declared by the shared header.
    (*(void (__thiscall**)(TESObjectREFR*, TESPackage*, int, int))(*(char**)this + 0x2f4))(this, packageLocation, 1, 1);
}

class B5512Target;
class FUN_00884ae0_cls;
class B5512Target
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
    virtual void v54();
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
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v7a();
    virtual void v7b();
    virtual void v7c();
    virtual void v7d();
    virtual void v7e();
    virtual void v7f();
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
    virtual void v8a();
    virtual B5512Target* v8b();
    int FUN_0041ca90();
};
class FUN_00884ae0_cls
{
  public:
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
    B5512Target* m_pFlagTarget;
    bool Actor_IsFightingOrAlarmed();
};
// @fnv 0x00884ae0
// src: COMMUNITY 0x00884ae0
bool FUN_00884ae0_cls::Actor_IsFightingOrAlarmed()
{
    bool result = false;
    B5512Target* t = (m_pFlagTarget != 0) ? m_pFlagTarget->v8b() : 0;
    if (t != 0)
    {
        if (t->FUN_0041ca90() == 0x12 || t->FUN_0041ca90() == 0x15)
        {
            result = true;
        }
    }
    return result;
}

struct FUN_004939d0_Class
{
    void __thiscall UpdateAnimationForRef(void*);
};

struct FUN_008885a0_Class
{
    virtual void d000();
    virtual void d001();
    virtual void d002();
    virtual void d003();
    virtual void d004();
    virtual void d005();
    virtual void d006();
    virtual void d007();
    virtual void d008();
    virtual void d009();
    virtual void d010();
    virtual void d011();
    virtual void d012();
    virtual void d013();
    virtual void d014();
    virtual void d015();
    virtual void d016();
    virtual void d017();
    virtual void d018();
    virtual void d019();
    virtual void d020();
    virtual void d021();
    virtual void d022();
    virtual void d023();
    virtual void d024();
    virtual void d025();
    virtual void d026();
    virtual void d027();
    virtual void d028();
    virtual void d029();
    virtual void d030();
    virtual void d031();
    virtual void d032();
    virtual void d033();
    virtual void d034();
    virtual void d035();
    virtual void d036();
    virtual void d037();
    virtual void d038();
    virtual void d039();
    virtual void d040();
    virtual void d041();
    virtual void d042();
    virtual void d043();
    virtual void d044();
    virtual void d045();
    virtual void d046();
    virtual void d047();
    virtual void d048();
    virtual void d049();
    virtual void d050();
    virtual void d051();
    virtual void d052();
    virtual void d053();
    virtual void d054();
    virtual void d055();
    virtual void d056();
    virtual void d057();
    virtual void d058();
    virtual void d059();
    virtual void d060();
    virtual void d061();
    virtual void d062();
    virtual void d063();
    virtual void d064();
    virtual void d065();
    virtual void d066();
    virtual void d067();
    virtual void d068();
    virtual void d069();
    virtual void d070();
    virtual void d071();
    virtual void d072();
    virtual void d073();
    virtual void d074();
    virtual void d075();
    virtual void d076();
    virtual void d077();
    virtual void d078();
    virtual void d079();
    virtual void d080();
    virtual void d081();
    virtual void d082();
    virtual void d083();
    virtual void d084();
    virtual void d085();
    virtual void d086();
    virtual void d087();
    virtual void d088();
    virtual void d089();
    virtual void d090();
    virtual void d091();
    virtual void d092();
    virtual void d093();
    virtual void d094();
    virtual void d095();
    virtual void d096();
    virtual void d097();
    virtual void d098();
    virtual void d099();
    virtual void d100();
    virtual void d101();
    virtual void d102();
    virtual void d103();
    virtual void d104();
    virtual void d105();
    virtual void d106();
    virtual void d107();
    virtual void d108();
    virtual void d109();
    virtual void d110();
    virtual void d111();
    virtual void d112();
    virtual void d113();
    virtual void d114();
    virtual void d115();
    virtual void d116();
    virtual void d117();
    virtual void d118();
    virtual void d119();
    virtual void d120();
    virtual FUN_004939d0_Class* FUN_008885a0_Get();

    void __thiscall Actor_UpdateAnimMovement();
};

// @fnv 0x008885a0
// src: COMMUNITY 0x008885a0
void __thiscall FUN_008885a0_Class::Actor_UpdateAnimMovement()
{
    FUN_004939d0_Class* result = FUN_008885a0_Get();
    if (result)
        result->UpdateAnimationForRef(this);
}

const NiFixedString& FixedStrings_QDVPG();
struct MeshPart
{
    unsigned short count, unk02;
    NiPoint3 positions[8];
    NiPoint3 normals[8];
};
struct MeshParts
{
    int unk00, unk04, unk08, unk0c;
    unsigned short count, unk12;
    MeshPart* entries[1];
};
struct AnimGroup
{
    unsigned char TESAnimGroup_GetDecal();
};
struct AnimSequence
{
    AnimGroup* FUN_0048f7f0();
};
struct AnimView
{
    AnimSequence* Animation_GetCurrentSequence(int);
};
struct NodeView
{
    const NiPoint3& NiAVObject_GetWorldTranslate();
    const Bound& NiAVObject_GetWorldBound();
    float NiAVObject_GetWorldScale();
    NodeView* NiNode_GetAtChecked(int);
    NodeView* FUN_0043b4a0(int);
    MeshParts* FUN_00a5bdd0(const NiFixedString&);
};
struct BipedView
{
    NodeView* FUN_004ab230();
};
struct EffectView
{
    float BGSImpactData_GetDecalMinWidth();
    float GetModifierValue();
    float FUN_004a40e0();
    float FUN_00598040();
    float TESCombatStyle_GetWeaponMinRangeMult();
    bool CallMemberAtOffset54();
    bool BGSImpactData_GetIsAlphaBlend();
    unsigned int GetNextFromSubobject();
};
// 0x0058e9d0 selects BGSImpactData by material; 0x006733e0 returns its decal texture set.
struct MaterialImpactRecord : EffectView
{
    EffectView* FUN_006733e0();
};
struct EffectList
{
    MaterialImpactRecord* FUN_0058e9d0(int);
};
struct WeaponView
{
    bool TESObjectWEAP_IsRangedWeapon();
};
struct InventoryView
{
    EffectList* GetAVEffect();
};
struct EquipmentView
{
    InventoryView* GetValueByIndex(int);
};
struct ValueView
{
    virtual void v0();
    virtual void v4();
    virtual int get(int);
};
struct HitSource
{
    NodeView* node;
    int unk04, unk08, unk0c;
    int kind;
    int unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40;
    NiPoint3 normal;
};
struct BaseData;
struct FUN_004a37b0;
struct AppliedEffect;
struct ProcessView
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
    virtual NodeView* getNode(int);
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual bool blocked();
};
struct AppliedEffect
{
    void TESObjectCELL_AddDecal(FUN_004a37b0*, int, char);
};
struct FUN_004a37b0
{
    NiPoint3 point, normal;
    int unk18, unk1c, unk20, unk24;
    NodeView* node;
    NodeView* other;
    EffectView* effect;
    int index;
    float minSize, maxSize, unk40, global;
    int unk48, unk4c, unk50;
    float radius, f58, f5c;
    NiPoint3 color;
    int unk6c;
    unsigned char f70, f71, f72, f73, f74, f75, f76, f77, f78, f79, f7a, f7b;
    int unk7c;
    FUN_004a37b0();
};
struct BaseData
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
    virtual EquipmentView* equipment();
};
struct WeaponHolder;
struct OwnerInfo
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
    virtual WeaponHolder* weapon();
};
struct SpellActor
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
    virtual int mode();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual bool isCreature();
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
    OwnerInfo* owner;
    TESActorBase* FUN_004181e0();
    ProcessView* FUN_008d8520();
    NiPoint3 GetNodePosition(bool);
    BipedView* GetBiped(bool, bool);
    bool PlayerCharacter_Is3rdPerson();
    AnimView* PlayerCharacter_GetAnimation();
    AnimView* Actor_GetAnimation();
    AppliedEffect* FUN_008d6f30();
    void Actor_CreateBloodOnWeapon(float, HitSource*, SpellActor*);
};
struct TargetView
{
    BaseData* FUN_004181e0();
    bool Actor_IsPowerArmorHelmetWorn();
    bool Actor_IsPowerBodyArmorWorn();
};
struct WeaponHolder
{
    WeaponView* FUN_0044ddc0();
};
struct BoolSetting
{
    bool* FUN_00408d60();
};
struct FloatSetting
{
    float* Setting_Float_00403e20();
};
extern BoolSetting DAT_011df7f8;
extern FloatSetting DAT_011df748;
extern SpellActor* DAT_011dea3c;
float BSMAX_00404010(float, float);
float FUN_00476b70(float, float);
float FUN_00406cc0(float);
float RandomFloatTwoPi();
unsigned int FUN_00944460(int, int);
// @fnv 0x0088fb00
// src: XBOX_PDB 0x0088fb00
void SpellActor::Actor_CreateBloodOnWeapon(float distance, HitSource* hit, SpellActor* target)
{
    TESCreature* creature5 = dynamic_cast<TESCreature*>(FUN_004181e0());
    if (((creature5 && creature5->IsHumanoidCreature()) || isCreature()) && *DAT_011df7f8.FUN_00408d60())
        return;
    bool specialTmp = hit->node && ((ValueView*)((char*)hit->node + 0xa4))->get(55) > 0 ? true : false;
    int index7 = -1;
    ProcessView* process = FUN_008d8520();
    bool alternateVal = hit && (hit->kind == 1 || hit->kind == 2);
    bool invalid3 = alternateVal ? ((TargetView*)target)->Actor_IsPowerArmorHelmetWorn() : ((TargetView*)target)->Actor_IsPowerBodyArmorWorn();
    int type = invalid3 ? 4 : ((const TESActorBaseData*)((char*)target->FUN_004181e0() + 0x30))->GetBloodImpactMaterial();
    EquipmentView* equipment3 = target ? ((TargetView*)target)->FUN_004181e0()->equipment() : 0;
    InventoryView* item = equipment3 ? equipment3->GetValueByIndex(hit->kind) : 0;
    EffectList* effects2 = item ? item->GetAVEffect() : 0;
    MaterialImpactRecord* _projectile = effects2 ? effects2->FUN_0058e9d0(type) : 0;
    EffectView* effect = _projectile ? _projectile->FUN_006733e0() : 0;
    if (hit && target && effect && !invalid3 && !process->blocked())
    {
        NodeView* node2;
        node2 = process ? node2 = process->getNode(mode()) : 0;
        WeaponView* weapon = owner->weapon() ? owner->weapon()->FUN_0044ddc0() : 0;
        if (node2 && weapon && !weapon->TESObjectWEAP_IsRangedWeapon() && distance > BSMAX_00404010(1.0f, *DAT_011df748.Setting_Float_00403e20()))
        {
            NodeView* other_2 = 0;
            NiPoint3 point, playerNormal4, FlushUsageData;
            float scale = 0.0f;
            if (this == DAT_011dea3c)
            {
                NodeView* bipedNode5 = DAT_011dea3c->GetBiped(true, true)->FUN_004ab230();
                memcpy(&point, &(node2->NiAVObject_GetWorldTranslate() - GetNodePosition(true)).ProcessAndReturnValue_0053d280(2.0f), sizeof(point));
                other_2 = DAT_011dea3c->PlayerCharacter_Is3rdPerson() ? bipedNode5 : node2;
                node2 = DAT_011dea3c->PlayerCharacter_Is3rdPerson() ? node2 : bipedNode5;
                Bound bound = node2->NiAVObject_GetWorldBound();
                scale = bound.FUN_0084d030() / node2->NiAVObject_GetWorldScale();
                NiPoint3 origin6 = bound.FUN_006815c0() - node2->NiAVObject_GetWorldTranslate();
                int h = 0;
                AnimView* s = DAT_011dea3c->PlayerCharacter_GetAnimation();
                if (s)
                {
                    AnimSequence* sequence = s->Animation_GetCurrentSequence(4);
                    if (sequence)
                    {
                        AnimGroup* group = sequence->FUN_0048f7f0();
                        if (group)
                            h = group->TESAnimGroup_GetDecal();
                    }
                }
                MeshParts* parts3 =
                    node2->NiNode_GetAtChecked(0) ? node2->FUN_0043b4a0(0)->FUN_00a5bdd0(NiFixedString("DVPG")) : 0;
                if (!parts3)
                    parts3 = node2->FUN_00a5bdd0(FixedStrings_QDVPG());
                if (parts3 && h < parts3->count)
                {
                    unsigned int choice = FUN_00944460(0, parts3->entries[h]->count - 1);
                    memcpy(&point, &parts3->entries[h]->positions[choice], sizeof(point));
                    memcpy(&playerNormal4, &parts3->entries[h]->normals[choice], sizeof(playerNormal4));
                }
                else
                    return;
            }
            else
            {
                AnimView* s = Actor_GetAnimation();
                if (s && s->Animation_GetCurrentSequence(4))
                {
                    int h = s->Animation_GetCurrentSequence(4)->FUN_0048f7f0()->TESAnimGroup_GetDecal();
                    memcpy(&point, &(node2->NiAVObject_GetWorldTranslate() + (GetNodePosition(false) - node2->NiAVObject_GetWorldTranslate()).ProcessAndReturnValue_0053d280(2.0f)), sizeof(point));
                }
            }
            char randomIndex2 = (char)(int)FUN_00406cc0(FUN_00476b70(0.0f, 4.0f));
            float global = RandomFloatTwoPi();
            float size = FUN_00476b70(_projectile->BGSImpactData_GetDecalMinWidth(), _projectile->GetModifierValue());
            NiPoint3 normal9;
            if (this == DAT_011dea3c)
                memcpy(&normal9, &playerNormal4, sizeof(normal9));
            else
                memcpy(&normal9, &hit->normal.GetNegatedVector(), sizeof(normal9));
            FUN_004a37b0 data;
            memcpy(&data.point, &point, sizeof(data.point));
            memcpy(&data.normal, &normal9, sizeof(data.normal));
            data.node = node2;
            data.index = index7;
            data.other = other_2;
            data.global = global;
            data.f70 = randomIndex2;
            data.effect = effect;
            data.minSize = size;
            data.maxSize = size;
            data.unk40 = 48.0f;
            data.radius = _projectile->FUN_004a40e0();
            data.f72 = 0;
            data.f5c = _projectile->FUN_00598040();
            data.f58 = _projectile->TESCombatStyle_GetWeaponMinRangeMult();
            data.f77 = 1;
            data.f74 = _projectile->CallMemberAtOffset54();
            data.f75 = _projectile->BGSImpactData_GetIsAlphaBlend();
            memcpy(&data.color, &NiPoint3((unsigned char)(_projectile->GetNextFromSubobject() & 0xff) / 255.0,
                                        (unsigned char)(((unsigned short)_projectile->GetNextFromSubobject() >> 8) & 0xff) / 255.0,
                                        (unsigned char)((_projectile->GetNextFromSubobject() >> 16) & 0xff) / 255.0), sizeof(data.color));
            data.f78 = 1;
            if (specialTmp)
            {
                data.minSize *= 1.5;
                data.maxSize *= 1.5;
            }
            FUN_008d6f30()->TESObjectCELL_AddDecal(&data, 1, 0);
            data.node = other_2;
            FUN_008d6f30()->TESObjectCELL_AddDecal(&data, 1, 0);
        }
    }
}

struct FnvHolder;

struct FnvActorProxy
{
    virtual int vfn_0000();
    virtual int vfn_0004();
    virtual int vfn_0008();
    virtual int vfn_000C();
    virtual int vfn_0010();
    virtual int vfn_0014();
    virtual int vfn_0018();
    virtual int vfn_001C();
    virtual int vfn_0020();
    virtual int vfn_0024();
    virtual int vfn_0028();
    virtual int vfn_002C();
    virtual int vfn_0030();
    virtual int vfn_0034();
    virtual int vfn_0038();
    virtual int vfn_003C();
    virtual int vfn_0040();
    virtual int vfn_0044();
    virtual int vfn_0048();
    virtual int vfn_004C();
    virtual int vfn_0050();
    virtual int vfn_0054();
    virtual int vfn_0058();
    virtual int vfn_005C();
    virtual int vfn_0060();
    virtual int vfn_0064();
    virtual int vfn_0068();
    virtual int vfn_006C();
    virtual int vfn_0070();
    virtual int vfn_0074();
    virtual int vfn_0078();
    virtual int vfn_007C();
    virtual int vfn_0080();
    virtual int vfn_0084();
    virtual int vfn_0088();
    virtual int vfn_008C();
    virtual int vfn_0090();
    virtual int vfn_0094();
    virtual int vfn_0098();
    virtual int vfn_009C();
    virtual int vfn_00A0();
    virtual int vfn_00A4();
    virtual int vfn_00A8();
    virtual int vfn_00AC();
    virtual int vfn_00B0();
    virtual int vfn_00B4();
    virtual int vfn_00B8();
    virtual int vfn_00BC();
    virtual int vfn_00C0();
    virtual int vfn_00C4();
    virtual int vfn_00C8();
    virtual int vfn_00CC();
    virtual int vfn_00D0();
    virtual int vfn_00D4();
    virtual int vfn_00D8();
    virtual int vfn_00DC();
    virtual int vfn_00E0();
    virtual int vfn_00E4();
    virtual int vfn_00E8();
    virtual int vfn_00EC();
    virtual int vfn_00F0();
    virtual int vfn_00F4();
    virtual int vfn_00F8();
    virtual int vfn_00FC();
    virtual int vfn_0100();
    virtual int vfn_0104();
    virtual int vfn_0108();
    virtual int vfn_010C();
    virtual int vfn_0110();
    virtual int vfn_0114();
    virtual int vfn_0118();
    virtual int vfn_011C();
    virtual int vfn_0120();
    virtual int vfn_0124();
    virtual int vfn_0128();
    virtual int vfn_012C();
    virtual int vfn_0130();
    virtual int vfn_0134();
    virtual int vfn_0138();
    virtual int vfn_013C();
    virtual int vfn_0140();
    virtual int vfn_0144();
    virtual int vfn_0148();
    virtual int vfn_014C();
    virtual int vfn_0150();
    virtual int vfn_0154();
    virtual int vfn_0158();
    virtual int vfn_015C();
    virtual int vfn_0160();
    virtual int vfn_0164();
    virtual int vfn_0168();
    virtual int vfn_016C();
    virtual int vfn_0170();
    virtual int vfn_0174();
    virtual int vfn_0178();
    virtual int vfn_017C();
    virtual int vfn_0180();
    virtual int vfn_0184();
    virtual int vfn_0188();
    virtual int vfn_018C();
    virtual int vfn_0190();
    virtual int vfn_0194();
    virtual int vfn_0198();
    virtual int vfn_019C();
    virtual int vfn_01A0();
    virtual int vfn_01A4();
    virtual int vfn_01A8();
    virtual int vfn_01AC();
    virtual int vfn_01B0();
    virtual int vfn_01B4();
    virtual int vfn_01B8();
    virtual int vfn_01BC();
    virtual int vfn_01C0();
    virtual int vfn_01C4();
    virtual int vfn_01C8();
    virtual int vfn_01CC();
    virtual int vfn_01D0();

    FnvHolder* FUN_008d6f30();
    void TESObjectREFR_MarkAsPickedUp();
};

struct FnvHolder
{
    void TESObjectCELL_RemoveReference(FnvActorProxy* a1);
};

void __cdecl bhkWorld_Activate(int a, int b, int c, int d);
void __cdecl GarbageCollector_Add_TESObjectREFR(FnvActorProxy* a1);

// @fnv 0x00892460
// src: COMMUNITY 0x00892460
void __cdecl Actor_RemovePickedUpObjectFromWorld(FnvActorProxy* a1, unsigned char a2)
{
    FnvHolder* holder;
    bhkWorld_Activate(a1->vfn_01D0(), 1, 1, 0);
    if (a2 != 0)
    {
        holder = a1->FUN_008d6f30();
        a1->vfn_01C0();
        GarbageCollector_Add_TESObjectREFR(a1);
        if (holder != 0)
        {
            holder->TESObjectCELL_RemoveReference(a1);
        }
    }
    else
    {
        a1->TESObjectREFR_MarkAsPickedUp();
    }
}

struct S981990
{
    bool IsFleeing_00981990();
    bool FUN_0047c850();
};

bool __fastcall TESPackage_GetAllowsSwim(B5512Target*);

struct SubActor
{
    virtual void v_00();
    virtual void v_01();
    virtual void v_02();
    virtual void v_03();
    virtual void v_04();
    virtual void v_05();
    virtual void v_06();
    virtual void v_07();
    virtual void v_08();
    virtual void v_09();
    virtual void v_0a();
    virtual void v_0b();
    virtual void v_0c();
    virtual void v_0d();
    virtual void v_0e();
    virtual void v_0f();
    virtual void v_10();
    virtual void v_11();
    virtual void v_12();
    virtual void v_13();
    virtual void v_14();
    virtual void v_15();
    virtual void v_16();
    virtual void v_17();
    virtual void v_18();
    virtual void v_19();
    virtual void v_1a();
    virtual void v_1b();
    virtual void v_1c();
    virtual void v_1d();
    virtual void v_1e();
    virtual void v_1f();
    virtual void v_20();
    virtual void v_21();
    virtual void v_22();
    virtual void v_23();
    virtual void v_24();
    virtual void v_25();
    virtual void v_26();
    virtual void v_27();
    virtual void v_28();
    virtual void v_29();
    virtual void v_2a();
    virtual void v_2b();
    virtual void v_2c();
    virtual void v_2d();
    virtual void v_2e();
    virtual void v_2f();
    virtual void v_30();
    virtual void v_31();
    virtual void v_32();
    virtual void v_33();
    virtual void v_34();
    virtual void v_35();
    virtual void v_36();
    virtual void v_37();
    virtual void v_38();
    virtual void v_39();
    virtual void v_3a();
    virtual void v_3b();
    virtual void v_3c();
    virtual void v_3d();
    virtual void v_3e();
    virtual void v_3f();
    virtual void v_40();
    virtual void v_41();
    virtual void v_42();
    virtual void v_43();
    virtual void v_44();
    virtual void v_45();
    virtual void v_46();
    virtual void v_47();
    virtual void v_48();
    virtual void v_49();
    virtual void v_4a();
    virtual void v_4b();
    virtual void v_4c();
    virtual void v_4d();
    virtual void v_4e();
    virtual void v_4f();
    virtual void v_50();
    virtual void v_51();
    virtual void v_52();
    virtual void v_53();
    virtual void v_54();
    virtual void v_55();
    virtual void v_56();
    virtual void v_57();
    virtual void v_58();
    virtual void v_59();
    virtual void v_5a();
    virtual void v_5b();
    virtual void v_5c();
    virtual void v_5d();
    virtual void v_5e();
    virtual void v_5f();
    virtual void v_60();
    virtual void v_61();
    virtual void v_62();
    virtual void v_63();
    virtual void v_64();
    virtual void v_65();
    virtual void v_66();
    virtual void v_67();
    virtual void v_68();
    virtual void v_69();
    virtual void v_6a();
    virtual void v_6b();
    virtual void v_6c();
    virtual void v_6d();
    virtual void v_6e();
    virtual void v_6f();
    virtual void v_70();
    virtual void v_71();
    virtual void v_72();
    virtual void v_73();
    virtual void v_74();
    virtual void v_75();
    virtual void v_76();
    virtual void v_77();
    virtual void v_78();
    virtual void v_79();
    virtual void v_7a();
    virtual void v_7b();
    virtual void v_7c();
    virtual void v_7d();
    virtual void v_7e();
    virtual void v_7f();
    virtual void v_80();
    virtual void v_81();
    virtual void v_82();
    virtual void v_83();
    virtual void v_84();
    virtual void v_85();
    virtual bool v218();
    virtual void v_87();
    virtual void v_88();
    virtual void v_89();
    virtual void v_8a();
    virtual void v_8b();
    virtual void v_8c();
    virtual void v_8d();
    virtual void v_8e();
    virtual void v_8f();
    virtual void v_90();
    virtual void v_91();
    virtual void v_92();
    virtual void v_93();
    virtual void v_94();
    virtual void v_95();
    virtual void v_96();
    virtual void v_97();
    virtual void v_98();
    virtual void v_99();
    virtual void v_9a();
    virtual void v_9b();
    virtual void v_9c();
    virtual void v_9d();
    virtual void v_9e();
    virtual void v_9f();
    virtual void v_a0();
    virtual void v_a1();
    virtual void v_a2();
    virtual void v_a3();
    virtual void v_a4();
    virtual void v_a5();
    virtual void v_a6();
    virtual void v_a7();
    virtual void v_a8();
    virtual void v_a9();
    virtual void v_aa();
    virtual void v_ab();
    virtual void v_ac();
    virtual void v_ad();
    virtual void v_ae();
    virtual void v_af();
    virtual void v_b0();
    virtual void v_b1();
    virtual void v_b2();
    virtual void v_b3();
    virtual void v_b4();
    virtual void v_b5();
    virtual void v_b6();
    virtual void v_b7();
    virtual void v_b8();
    virtual void v_b9();
    virtual void v_ba();
    virtual void v_bb();
    virtual void v_bc();
    virtual void v_bd();
    virtual void v_be();
    virtual void v_bf();
    virtual void v_c0();
    virtual void v_c1();
    virtual void v_c2();
    virtual void v_c3();
    virtual void v_c4();
    virtual void v_c5();
    virtual void v_c6();
    virtual void v_c7();
    virtual void v_c8();
    virtual void v_c9();
    virtual void v_ca();
    virtual void v_cb();
    virtual void v_cc();
    virtual void v_cd();
    virtual void v_ce();
    virtual void v_cf();
    virtual void v_d0();
    virtual void v_d1();
    virtual void v_d2();
    virtual void v_d3();
    virtual void v_d4();
    virtual void v_d5();
    virtual void v_d6();
    virtual void v_d7();
    virtual void v_d8();
    virtual void v_d9();
    virtual void v_da();
    virtual void v_db();
    virtual void v_dc();
    virtual void v_dd();
    virtual void v_de();
    virtual void v_df();
    virtual void v_e0();
    virtual void v_e1();
    virtual void v_e2();
    virtual void v_e3();
    virtual void v_e4();
    virtual void v_e5();
    virtual void v_e6();
    virtual void v_e7();
    virtual void v_e8();
    virtual void v_e9();
    virtual void v_ea();
    virtual void v_eb();
    virtual void v_ec();
    virtual void v_ed();
    virtual void v_ee();
    virtual void v_ef();
    virtual void v_f0();
    virtual void v_f1();
    virtual void v_f2();
    virtual void v_f3();
    virtual void v_f4();
    virtual void v_f5();
    virtual void v_f6();
    virtual void v_f7();
    virtual void v_f8();
    virtual void v_f9();
    virtual void v_fa();
    virtual void v_fb();
    virtual void v_fc();
    virtual void v_fd();
    virtual void v_fe();
    virtual void v_ff();
    virtual void v_100();
    virtual void v_101();
    virtual void v_102();
    virtual void v_103();
    virtual void v_104();
    virtual void v_105();
    virtual void v_106();
    virtual void v_107();
    virtual void v_108();
    virtual void v_109();
    virtual S981990* v428();

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
    B5512Target* m_pFlagTarget;
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
    bool unk14c;

    bool Actor_IsFightingOrAlarmed();
    bool Actor_FightsInWater();
    bool Actor_DoesSwim();
    bool Actor_IsAllowedToSwim();
};

// @fnv 0x00884b50
// src: COMMUNITY 0x00884b50
bool SubActor::Actor_IsAllowedToSwim()
{
    if (this->unk14c)
    {
        return true;
    }
    if (this->Actor_IsFightingOrAlarmed())
    {
        S981990* target = this->v428();
        if (target)
        {
            if (!this->Actor_FightsInWater() && !target->IsFleeing_00981990())
            {
                return false;
            }
            else if (!target->FUN_0047c850())
            {
                return false;
            }
        }
        return this->Actor_DoesSwim();
    }
    bool result = false;
    if (this->v218())
    {
        B5512Target* pTarget = this->m_pFlagTarget ? this->m_pFlagTarget->v8b() : 0;
        if (pTarget && TESPackage_GetAllowsSwim(pTarget))
        {
            result = true;
        }
    }
    else
    {
        result = this->Actor_DoesSwim();
    }
    return result;
}

struct TargetInfo;
struct World;
struct Cell
{
    bool __thiscall FUN_00425fd0();
};
extern FloatSetting DAT_011cd744;
extern FloatSetting DAT_011cd9b4;
extern FloatSetting DAT_011cd5f0;
extern FloatSetting DAT_011cdf9c;
extern FloatSetting DAT_011cd354;
extern double DAT_01021798;

float __cdecl AiFormulas_GetFollowRadiusStop(float a);
float __cdecl fSelf(float a);
float __cdecl AddRuntimeFloatSetting(float a);
float __cdecl BSMAX_00404010(float a, float b);
float __cdecl BSMIN(float a, float b);
void __cdecl BSClamp_float(float* a, float b, float c);

struct Refr
{
    virtual void fn00();
    virtual void fn01();
    virtual void fn02();
    virtual void fn03();
    virtual void fn04();
    virtual void fn05();
    virtual void fn06();
    virtual void fn07();
    virtual void fn08();
    virtual void fn09();
    virtual void fn10();
    virtual void fn11();
    virtual void fn12();
    virtual void fn13();
    virtual void fn14();
    virtual void fn15();
    virtual void fn16();
    virtual void fn17();
    virtual void fn18();
    virtual void fn19();
    virtual void fn20();
    virtual void fn21();
    virtual void fn22();
    virtual void fn23();
    virtual void fn24();
    virtual void fn25();
    virtual void fn26();
    virtual void fn27();
    virtual void fn28();
    virtual void fn29();
    virtual void fn30();
    virtual void fn31();
    virtual void fn32();
    virtual void fn33();
    virtual void fn34();
    virtual void fn35();
    virtual void fn36();
    virtual void fn37();
    virtual void fn38();
    virtual void fn39();
    virtual void fn40();
    virtual void fn41();
    virtual void fn42();
    virtual void fn43();
    virtual void fn44();
    virtual void fn45();
    virtual void fn46();
    virtual void fn47();
    virtual void fn48();
    virtual void fn49();
    virtual void fn50();
    virtual void fn51();
    virtual void fn52();
    virtual void fn53();
    virtual void fn54();
    virtual void fn55();
    virtual void fn56();
    virtual void fn57();
    virtual void fn58();
    virtual void fn59();
    virtual void fn60();
    virtual void fn61();
    virtual void fn62();
    virtual void fn63();
    virtual bool fn64();
    TargetInfo* __thiscall FUN_009344a0();
    Refr* __thiscall Actor_GetCurrentPackageTarget();
    Cell* __thiscall FUN_008d6f30();
    World* __thiscall TESObjectREFR_GetWorldSpace();
    float __thiscall Actor_GetCurrentSpeed();
    float __thiscall TESObjectREFR_GetScale_00567400();
    unsigned int __thiscall GetVtbl20Result();
    void __thiscall Actor_AdjustSpeedForFollowing(float* a, float b, float c);
};

// @fnv 0x008855f0
// src: COMMUNITY 0x008855f0
void __thiscall Refr::Actor_AdjustSpeedForFollowing(float* pfValue, float b, float c)
{
    TargetInfo* tInfoX = FUN_009344a0();
    Refr* obj3 = Actor_GetCurrentPackageTarget();
    if (!obj3 || !obj3->fn64() || obj3 == this)
        return;
    Cell* cellThis = FUN_008d6f30();
    Cell* cellObj5 = obj3->FUN_008d6f30();
    World* worldThis = TESObjectREFR_GetWorldSpace();
    World* worldObj6 = obj3->TESObjectREFR_GetWorldSpace();
    bool b8 = (cellObj5 && cellObj5->FUN_00425fd0()) || (cellThis && cellThis->FUN_00425fd0());
    bool b2 = b8 ? (cellObj5 == cellThis) : (worldObj6 == TESObjectREFR_GetWorldSpace());
    if (b2)
    {
        float f2 = AiFormulas_GetFollowRadiusStop(b);
        float f7 = fSelf(b);
        float fd0 = AddRuntimeFloatSetting(b);
        float scale = obj3->fn64() ? obj3->Actor_GetCurrentSpeed() : 0.0f;
        scale = (obj3->TESObjectREFR_GetScale_00567400() / TESObjectREFR_GetScale_00567400()) * scale;
        int mask9 = 0x20f;
        bool flag = (GetVtbl20Result() & mask9) == mask9;
        float out28 = *pfValue * (flag ? *DAT_011cd744.Setting_Float_00403e20() : *DAT_011cd9b4.Setting_Float_00403e20());
        float out34 = *pfValue * (flag ? *DAT_011cd5f0.Setting_Float_00403e20() : *DAT_011cdf9c.Setting_Float_00403e20());
        if (c < f7)
        {
            float rA = BSMAX_00404010(0.0f, c - f2);
            float denomA3 = f7 - f2;
            *pfValue = BSMIN(*pfValue, scale) * (rA / denomA3);
        }
        else if (c >= fd0 && flag)
        {
            *pfValue = scale * DAT_01021798;
        }
        else
        {
            float d8 = c - f7;
            float d2 = fd0 - f7;
            *pfValue = (1.0f + *DAT_011cd354.Setting_Float_00403e20() * (d8 / d2)) * scale;
        }
        BSClamp_float(pfValue, out34, out28);
    }
}
