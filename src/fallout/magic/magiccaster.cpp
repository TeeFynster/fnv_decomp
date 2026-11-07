#include "../../../include/BSStringT.h"
// fallout/magic/magiccaster.cpp: MagicCaster, Caster, PhantomOverlapAccess, CastingCheck and more (34 functions)

#include "../../../include/BSSimpleList.h"
#include "../../../include/EffectItem.h"

// Avoid a collision with MSVC's generated constructor closure.
#define __local_vftable_ctor_closure DeclaredVftableConstructorClosure
#include "../../../include/ActiveEffect.h"
#include "../../../include/Actor.h"
#include "../../../include/AlchemyItem.h"
#include "../../../include/IngredientItem.h"
#include "../../../include/Character.h"
#include "../../../include/EnchantmentItem.h"
#include "../../../include/EffectSetting.h"
#include "../../../include/MobileObjectProcessArray.h"
// EffectNode_magiccaster: local type (was include/EffectNode.h, which had no evidence of one real class); its methods are 0x006815c0 ReturnThis, 0x00726070 TESHealthForm::GetHealth, 0x008256d0 BSSimpleList<Actor *>::IsEmpty
class ActiveEffect;
class TESForm;

class EffectNode_magiccaster
{
public:
    TESForm* form;
    EffectNode_magiccaster* next;

    bool __thiscall FUN_008256d0();
    ActiveEffect** __thiscall FUN_006815c0();
    EffectNode_magiccaster* __thiscall FUN_00726070();
    EffectItem** GetItem();
    EffectNode_magiccaster* GetNext();
};
// Effects_magiccaster: local type (was include/Effects.h, which had no evidence of one real class); its methods are 0x00405c00 EffectItemList::GetEffectScore, 0x004065e0 EffectItemList::GetAssociatedSkill
class EffectLink;
class ImageSpaceEffect;
class LightObject;

class Effects_magiccaster
{
public:
    union
    {
        char prefix[200];
        struct
        {
            unsigned int unk00;
            unsigned int unk04;
            unsigned int unk08;
            EffectLink* lights;
            char unk10[184];
        };
    };
    ImageSpaceEffect* noise;

    EffectLink* Head() const { return lights; }
    LightObject* Next(EffectLink*& iter) const;
    void DispelAllEffects();
    float FUN_00405c00(int, int, int);
    int count();
};
// MagicEffectSystem_magiccaster: local type (was include/MagicEffectSystem.h, which had no evidence of one real class); its methods are 0x00403ab0 EffectArchetypes::Activate, 0x00403c80 EffectArchetypes::CheckFlag, 0x00810fd0 EffectSetting::GetEffectArchetype
class ActiveEffect;
class MagicCaster;
class MagicItem;
class TESBoundObject;

class MagicEffectSystem_magiccaster
{
public:
    struct _Type
    {
        enum Type
        {
            VALUE_MODIFIER,
            SCRIPT,
            DISPEL,
            CURE_DISEASE,
            ABSORB,
            SHIELD,
            CALM,
            DEMORALIZE,
            FRENZY,
            COMMAND_CREATURE,
            COMMAND_HUMANOID,
            INVISIBILITY,
            CHAMELEON,
            LIGHT,
            DARKNESS,
            NIGHT_EYE,
            LOCK,
            OPEN,
            BOUND_ITEM,
            SUMMON_CREATURE,
            DETECT_LIFE,
            TELEKINESIS,
            DISINTEGRATE_ARMOR,
            DISINTEGRATE_WEAPON,
            PARALYSIS,
            REANIMATE,
            SOUL_TRAP,
            TURN_UNDEAD,
            SUN_DAMAGE,
            VAMPIRISM,
            CURE_PARALYSIS,
            CURE_ADDICTION,
            CURE_POISON,
            CONCUSSION,
            VALUE_AND_PARTS,
            LIMB_CONDITION,
            TURBO,
            COUNT,
        };
    };

    typedef _Type::Type Type;

    static bool __cdecl IsFlagSet(Type type, unsigned int flags);
    static bool __cdecl IsFlagSet(int type, unsigned int flags);
    static ActiveEffect* Activate(MagicCaster*, MagicItem*, EffectItem*, TESBoundObject*);
};
#include "../../../include/bhkFilter.h"
#include "../../../include/NiNode.h"
#include "../../../include/SpellItem.h"
#include "../../../include/NiTransform.h"
#include "../../../include/NiPoint3.h"
// In-class bodies of the former Point stand-in.
__forceinline NiPoint3::NiPoint3(float px, float py, float pz) : x(px), y(py), z(pz)
{}

inline NiPoint3 NiPoint3::operator-() const
{
    return NiPoint3(-x, -y, -z);
}

__forceinline NiPoint3 NiPoint3::operator*(float scalar) const
{
    return NiPoint3(scalar * x, scalar * y, scalar * z);
}

__forceinline NiPoint3 NiPoint3::operator/(float scalar) const
{
    float inverse = 1.0f / scalar;
    return NiPoint3(x * inverse, y * inverse, z * inverse);
}

inline bool NiPoint3::operator==(const NiPoint3& other) const
{
    return other.x == x && other.y == y && other.z == z;
}
extern const NiPoint3 MagicPointZero;
#include "../../../include/Setting.h"
#include "../../../include/TES.h"
#include "../../../include/TESSound.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/hkVector4.h"
#undef __local_vftable_ctor_closure
class MagicEffectCollection
{
  public:
    void* FUN_0080fcc0(unsigned int flags);
};

class ModelLoader
{
  public:
    void QueueModelLoad(const char*, bool, unsigned int);
};
extern ModelLoader* g_modelLoader;

#include "../../../include/BSSoundHandle.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/bhkWorldObject.h"
#include "../../../include/TESResponse.h"

// Handoff for the remaining four functions of this unit (all decoded, none
// attempted): 0x815B00 RemoveCastingArt calls GetCasterActor plus slots
// +0x34/+0x24/+0x40/+0x48 and direct callees 0x453470, 0x4DEF90, 0x80FCC0
// 0x48CEE0, 0x445300 (global 0x11C3B3C). 0x815C50 HasActiveEffect does
// dynamic_cast (via __RTDynamicCast at 0xEC43FB with RTTI refs 0x11A1224 /
// bool(MagicTarget*, NiPoint3, MagicItem*, ActiveEffect*, bool)) with a
// global NiPoint3 at 0x11F426C whose name is still unknown. 0x818C60
// 0x4839C0) then GetIsReference (+0xF0) then TESObjectREFR::GetMagicCaster
// (+0x198); the canonical TESObjectREFR.h lacks that name (its slot-102
// virtual is currently Unk_66). 0x815D00 LaunchMagicProjectile is the 4611-byte
// dispatcher with EH/GS frames and dozens of callees.

// @fnv 0x00815410
Actor* MagicCaster::GetCasterActor()
{
    TESObjectREFR* pStatsObject = GetCasterReference();
    return (pStatsObject && pStatsObject->IsActor()) ? (Actor*)this : NULL;
}

// @fnv 0x00815600
void MagicCaster::CastSpellOnCaster(SpellItem* pSpell, bool bImmediate)
{
    if (pSpell->GetSpellType() == MagicSystem__SpellType_ABILITY)
    {
        SetSelectedMagicItem(pSpell);
        LaunchMagicProjectile(0.0f, NULL, bImmediate, 1.0f, false);
    }
}

// @fnv 0x00815740
void MagicCaster::CastMagicItem(MagicItem* pItem, bool bArg1, MagicTarget* pTarget, float fValue, bool bArg2)
{
    if (pTarget)
        SetMagicTarget(pTarget);
    SetSelectedMagicItem(pItem);
    LaunchMagicProjectile(0.0f, NULL, bArg1, fValue, bArg2);
}

// @fnv 0x008157a0
void MagicCaster::CastSpellAtTarget(SpellItem* pSpell, MagicTarget* pTarget, bool bImmediate)
{
    if (pSpell->GetSpellType() == MagicSystem__SpellType_DISEASE && pTarget)
    {
        SetSelectedMagicItem(pSpell);
        LaunchMagicProjectile(0.0f, NULL, bImmediate, 1.0f, false);
    }
}

// Forwards the caster, item, effect and source to Activate and returns the resulting ActiveEffect.
// @fnv 0x00815cd0
ActiveEffect* MagicCaster::CreateActiveEffect(MagicItem* pItem, EffectItem* pEffect, TESBoundObject* pSource)
{
    return MagicEffectSystem_magiccaster::Activate(this, pItem, pEffect, pSource);
}

// @fnv 0x00818af0
void MagicCaster::SetState(MagicCaster::State state, char* reason)
{
    eState = state;
}

// Qualified covered-body mapping; position is unused in the original.
// @fnv 0x00817940
struct blob12 { float x, y, z; };
bool MagicCaster::AddEffectToTarget(MagicTarget* target, blob12 position, MagicItem* spell, ActiveEffect* effect,
                                    bool immediate)
{
    return target->AddEffectToTarget(this, spell, effect, immediate);
}

// @fnv 0x00815c50
bool MagicCaster::HasActiveEffect(ActiveEffect* effect)
{
    MagicTarget* pTarget;
    bool bRetVal = false;
    pTarget = dynamic_cast<MagicTarget*>(this);
    if (pTarget)
    {
        bRetVal = AddEffectToTarget(pTarget, reinterpret_cast<const blob12&>(MagicPointZero), GetSelectedMagicItem(), effect, false);
    }
    return bRetVal;
}

// Looks up the form by formID, and if it is a reference, returns that reference's magic caster; otherwise returns NULL.
// @fnv 0x00818c60
MagicCaster* MagicCaster::GetCasterByHandle(unsigned int formID)
{
    TESForm* form = TESForm::GetFormByID(formID);
    if (form && form->GetIsReference())
    {
        TESObjectREFR* reference = static_cast<TESObjectREFR*>(form);
        return reference->GetMagicCaster();
    }
    return NULL;
}

struct CastingActor : Actor { using MagicCaster::GetMagicNode; };

// @fnv 0x00815b00
void MagicCaster::RemoveCastingArt()
{
    Actor* actor = GetCasterActor();
    bool hadNode = false;
    NiNode* effect;
    if (actor)
    {
        effect = ((CastingActor*)actor)->GetMagicNode();
        if (effect && (unsigned int)effect->NiNode_GetChildCount() > 0)
        {
            hadNode = true;
            effect->NiNode_RemoveAllChildren();
        }
        if (apTargetLight)
        {
            MagicEffectCollection* light = apTargetLight;
            MagicEffectCollection* deletingLight = light;
            deletingLight ? deletingLight->FUN_0080fcc0(1) : 0;
        }
        apTargetLight = NULL;
    }
    EffectSetting* node;
    if (!GetSelectedMagicItem())
        return;
    SetState(MagicCaster::ERR_CANNOT_CAST, "Cannot Cast");
    SpellCast(GetSelectedMagicItem(), false);
    if (hadNode)
    {
        node = GetSelectedMagicItem()->GetEffectSettingForRange((MagicSystem::Range)0);
        if (node && node->TESModel::GetModelLength() > 0)
            g_modelLoader->QueueModelLoad(node->GetModelFilePath(), false, 1);
    }
    SetSelectedMagicItem((MagicItem*)NULL);
    SetMagicTarget(NULL);
}

struct BSS819
{
    operator bhkWorldObject*() const;
};
struct S819
{
    char p[0x594];
    BSS819 s;
    int bhkCharacterController_GetCollisionGroup();
};
// @fnv 0x00819250
// src: XBOX_PDB 0x00819250
int S819::bhkCharacterController_GetCollisionGroup()
{
    return ((bhkWorldObject*)s) ? ((bhkWorldObject*)s)->bhkWorldObject_GetCollisionFilter().CFilter_GetGroup() : 0;
}

struct MagicCaster_shell : MagicCaster
{
    MagicTarget* pTarget;
    MagicTarget* TESMain_GetThread();
};

// @fnv 0x0044edb0
// src: COMMUNITY 0x0044edb0
MagicTarget* MagicCaster_shell::TESMain_GetThread()
{
    return *(MagicTarget**)((char*)this + 0x10);
}

struct FUN_008153a0_shell
{
    float MagicCaster_GetMagicEffectivenessModifier(bool abJustArmor, float afUseThisFatigue);
};

// @fnv 0x008153a0
// src: XBOX_PDB 0x008153a0
float FUN_008153a0_shell::MagicCaster_GetMagicEffectivenessModifier(bool abJustArmor, float afUseThisFatigue)
{
    return 1.0f;
}

struct FUN_00818cb0_shell
{
    bool __thiscall MagicCaster_CheckCast(MagicItem* apSpell, float* afEffectStrength, MagicItem::CannotCastReason* apReason,
                                 bool abUseBaseMagicka);
};

// Initializes the optional effect strength to 1.0 and the reason to 0, then returns true.
// @fnv 0x00818cb0
// src: XBOX_PDB 0x00818cb0
bool __thiscall FUN_00818cb0_shell::MagicCaster_CheckCast(MagicItem* apSpell, float* afEffectStrength,
                                                 MagicItem::CannotCastReason* apReason, bool abUseBaseMagicka)
{
    if (afEffectStrength)
        *afEffectStrength = 1.0f;
    if (apReason)
        *apReason = 0;
    return true;
}

struct FUN_008156e0_This : MagicCaster
{
    void MagicCaster_CastRadiation(SpellItem* apSpell, bool abLoadCast);
};
// @fnv 0x008156e0
// src: XBOX_PDB 0x008156e0
void FUN_008156e0_This::MagicCaster_CastRadiation(SpellItem* apSpell, bool abLoadCast)
{
    SetSelectedMagicItem(apSpell);
    LaunchMagicProjectile(0.0F, 0, abLoadCast, 1.0F, 0);
}

struct ProxyFor15820
{
    void MagicCaster_CastWornEnchantment(MagicItem* apSpell, TESBoundObject* apSource, bool abLoadCast);
};
// @fnv 0x00815820
// src: XBOX_PDB 0x00815820
void ProxyFor15820::MagicCaster_CastWornEnchantment(MagicItem* apSpell, TESBoundObject* apSource, bool abLoadCast)
{
    if (apSpell == 0)
        return;
    ((MagicCaster*)this)->SetSelectedMagicItem(apSpell);
    ((MagicCaster*)this)->LaunchMagicProjectile(0.0f, apSource, abLoadCast, 1.0f, false);
}

// 0x004ae750 is the nullable bhkWorldObject accessor; 0x0045c650 returns the Havok object's overlap array at +0xD0.
struct PhantomOverlapAccess
{
    void* GetHavokObject();
    void* GetOverlaps();
};
struct HavokOverlapStorageAccess
{
    void* GetOverlaps();
};
// @fnv 0x00818110
void* PhantomOverlapAccess::GetOverlaps()
{
    void* p = GetHavokObject();
    return p ? ((HavokOverlapStorageAccess*)p)->GetOverlaps() : 0;
}

extern "C" void __cdecl TryCast(void*);

struct FUN_00815380_shell
{
    void __thiscall TryCast(int);
    void __thiscall MagicCaster_StartCast();
};

// @fnv 0x00815380
// src: XBOX_PDB 0x00815380
void __thiscall FUN_00815380_shell::MagicCaster_StartCast()
{
    TryCast(0);
}

struct ActorVT
{
    virtual void A0();
    virtual void A1();
    virtual void A2();
    virtual void A3();
    virtual void A4();
    virtual void A5();
    virtual void A6();
    virtual void A7();
    virtual void A8();
    virtual void A9();
    virtual void A10();
    virtual void A11();
    virtual void A12();
    virtual void A13();
    virtual void A14();
    virtual void A15();
    virtual void A16();
    virtual void A17();
    virtual void A18();
    virtual void A19();
    virtual void A20();
    virtual void A21();
    virtual void A22();
    virtual void A23();
    virtual void A24();
    virtual void A25();
    virtual void A26();
    virtual void A27();
    virtual void A28();
    virtual void A29();
    virtual void A30();
    virtual void A31();
    virtual void A32();
    virtual void A33();
    virtual void A34();
    virtual void A35();
    virtual void A36();
    virtual void A37();
    virtual void A38();
    virtual void A39();
    virtual void A40();
    virtual void A41();
    virtual void A42();
    virtual void A43();
    virtual void A44();
    virtual void A45();
    virtual void A46();
    virtual void A47();
    virtual void A48();
    virtual void A49();
    virtual void A50();
    virtual void A51();
    virtual void A52();
    virtual void A53();
    virtual void A54();
    virtual void A55();
    virtual void A56();
    virtual void A57();
    virtual void A58();
    virtual void A59();
    virtual void A60();
    virtual void A61();
    virtual void A62();
    virtual void A63();
    virtual void A64();
    virtual void A65();
    virtual void A66();
    virtual void A67();
    virtual void A68();
    virtual void A69();
    virtual void A70();
    virtual void A71();
    virtual void A72();
    virtual void A73();
    virtual void A74();
    virtual void A75();
    virtual void A76();
    virtual void A77();
    virtual void A78();
    virtual void A79();
    virtual void A80();
    virtual void A81();
    virtual void A82();
    virtual void A83();
    virtual void A84();
    virtual void A85();
    virtual void A86();
    virtual void A87();
    virtual void A88();
    virtual void A89();
    virtual void A90();
    virtual void A91();
    virtual void A92();
    virtual void A93();
    virtual void A94();
    virtual void A95();
    virtual void A96();
    virtual void A97();
    virtual void A98();
    virtual void A99();
    virtual void A100();
    virtual void A101();
    virtual void A102();
    virtual void A103();
    virtual void A104();
    virtual void A105();
    virtual void A106();
    virtual void A107();
    virtual void A108();
    virtual void A109();
    virtual void A110();
    virtual void A111();
    virtual void A112();
    virtual void A113();
    virtual void A114();
    virtual void A115();
    virtual void A116();
    virtual void A117();
    virtual void A118();
    virtual void A119();
    virtual void A120();
    virtual void A121();
    virtual void A122();
    virtual void A123();
    virtual void A124();
    virtual void A125();
    virtual void A126();
    virtual void A127();
    virtual void A128();
    virtual void A129();
    virtual void A130();
    virtual void A131();
    virtual void A132();
    virtual void A133();
    virtual void A134();
    virtual void A135();
    virtual void A136();
    virtual void A137();
    virtual void A138();
    virtual bool V139(int);
    virtual void A140();
    virtual void A141();
    virtual void A142();
    virtual void A143();
    virtual void A144();
    virtual void A145();
    virtual void A146();
    virtual void A147();
    virtual void A148();
    virtual void A149();
    virtual void A150();
    virtual void A151();
    virtual void A152();
    virtual void A153();
    virtual void A154();
    virtual void A155();
    virtual void A156();
    virtual void A157();
    virtual void A158();
    virtual void A159();
    virtual void A160();
    virtual void A161();
    virtual void A162();
    virtual void A163();
    virtual void A164();
    virtual void A165();
    virtual void A166();
    virtual void A167();
    virtual void A168();
    virtual void A169();
    virtual void A170();
    virtual void A171();
    virtual void A172();
    virtual void A173();
    virtual void A174();
    virtual void A175();
    virtual void A176();
    virtual void A177();
    virtual void A178();
    virtual void A179();
    virtual void A180();
    virtual void A181();
    virtual void A182();
    virtual void A183();
    virtual void A184();
    virtual void A185();
    virtual void A186();
    virtual void A187();
    virtual void A188();
    virtual void A189();
    virtual void A190();
    virtual void A191();
    virtual void A192();
    virtual void A193();
    virtual void A194();
    virtual void A195();
    virtual void A196();
    virtual void A197();
    virtual void A198();
    virtual void A199();
    virtual void A200();
    virtual void A201();
    virtual void A202();
    virtual void A203();
    virtual void A204();
    virtual void A205();
    virtual void A206();
    virtual void A207();
    virtual void A208();
    virtual void A209();
    virtual void A210();
    virtual void A211();
    virtual void A212();
    virtual void A213();
    virtual void A214();
    virtual void A215();
    virtual void A216();
    virtual void A217();
    virtual void A218();
    virtual void A219();
    virtual void A220();
    virtual void A221();
    virtual void A222();
    virtual void A223();
    virtual float V224();
};
struct ActorV_S
{
    float GetScale();
};

struct TgtOps
{
    void* GetPosition();
};


extern Setting originalRuntimeFloatSetting594;
extern Actor* _g_thePlayer;
extern int DAT_011e0e80;
float __cdecl CombatUtilities_GetDistanceBetweenFacingActors(Actor*, Actor*, int);
bool __cdecl IsTargetInCone(Actor*, Actor*, float*);

struct FUN_00817620_shell : MagicCaster
{
    MagicTarget* FindClosestMagicTarget();
};

// Scans nearby actors within reach and strike angle of the caster and returns the closest valid target, falling back to the player.
// @fnv 0x00817620
MagicTarget* FUN_00817620_shell::FindClosestMagicTarget()
{
    Actor* pactor = GetCasterActor();
    float freach =
        pactor ? ((ActorVT*)pactor)->V224() * ((ActorV_S*)pactor)->GetScale() : *originalRuntimeFloatSetting594.Float();
    TESObjectREFR* pcaster = pactor ? pactor : GetCasterReference();
    Actor* pclosestTarget = 0;
    float fclosestDelta = 3.402823466e+38f;
    if (CombatUtilities_GetDistanceBetweenFacingActors((Actor*)pcaster, _g_thePlayer, 0) <= freach)
    {
        float fdelta = 3.402823466e+38f;
        bool binStrikeAngle = pactor ? IsTargetInCone(pactor, _g_thePlayer, &fdelta) : true;
        if (binStrikeAngle && fdelta <= fclosestDelta)
        {
            pclosestTarget = _g_thePlayer;
            fclosestDelta = fdelta;
        }
    }
    MobileObjectProcessArray* parray = (MobileObjectProcessArray*)((TgtOps*)&DAT_011e0e80)->GetPosition();
    for (unsigned int i = 0; i < parray->GetTail((PROCESS_TYPE)0); i++)
    {
        MobileObject* pmob = parray->GetItem(i);
        Actor* ptargetActor = (pmob && pmob->IsActor()) ? (Actor*)pmob : 0;
        BSSimpleList<Actor*>* ptempfollower = 0;
        while (ptargetActor)
        {
            if (ptargetActor != pcaster && !((ActorVT*)ptargetActor)->V139(0) && ptargetActor->GetNiNode())
            {
                if (CombatUtilities_GetDistanceBetweenFacingActors((Actor*)pcaster, ptargetActor, 0) <= freach)
                {
                    float fdelta = 3.402823466e+38f;
                    bool binStrikeAngle = pactor ? IsTargetInCone(pactor, ptargetActor, &fdelta) : true;
                    if (binStrikeAngle && fdelta <= fclosestDelta)
                    {
                        pclosestTarget = ptargetActor;
                        fclosestDelta = fdelta;
                    }
                }
            }
            if (ptempfollower && ptempfollower->GetItem())
            {
                ptargetActor = dynamic_cast<Character*>(ptempfollower->GetItem());
                ptempfollower = ptempfollower->GetNext();
                while (ptargetActor && (!((TES*)ptargetActor)->GetLogDate() ||
                                        ((TESResponse*)((TES*)ptargetActor)->GetLogDate())->GetNext()))
                {
                    ptargetActor = 0;
                    if (ptempfollower)
                        ptargetActor = dynamic_cast<Character*>(ptempfollower->GetItem());
                    if (ptempfollower)
                        ptempfollower = ptempfollower->GetNext();
                }
            }
            else
                ptargetActor = 0;
        }
    }
    return pclosestTarget;
}

extern int DAT_0107ac5c;

class FUN_008153b0_cls
{
  public:
    void* m_vtbl;
    MagicEffectCollection* m_pLight;
    void UpdateState_008153b0();
};

// @fnv 0x008153b0
// src: GUESS 0x008153b0 (confidence: low)
void FUN_008153b0_cls::UpdateState_008153b0()
{
    MagicEffectCollection* target;
    MagicEffectCollection* light;
    m_vtbl = (void*)&DAT_0107ac5c;
    if (m_pLight != 0)
    {
        target = m_pLight;
        light = target;
        (light != 0) ? light->FUN_0080fcc0(1) : 0;
    }
    m_pLight = 0;
}

struct ChildCell
{
    virtual void Unk_00(void);
    virtual void Unk_01(void);
    virtual void Unk_02(void);
    virtual void Unk_03(void);
    virtual void Unk_04(void);
    virtual void Unk_05(void);
    virtual int Unk_06(void);
};

struct RefShell
{
    char unk00[0x18];
    ChildCell child;
};

struct FUN_00815670_cls
{
    virtual void Unk_00(void);
    virtual void Unk_01(void);
    virtual void Unk_02(void);
    virtual void Unk_03(void);
    virtual void Unk_04(void);
    virtual void Unk_05(void);
    virtual void Unk_06(void);
    virtual void Unk_07(void);
    virtual void Unk_08(void);
    virtual void Unk_09(void);
    virtual void Unk_0A(void);
    virtual void Unk_0B(void);
    virtual void Unk_0C(void);
    virtual void Unk_0D(void);
    virtual void Unk_0E(void);
    virtual void Unk_0F(void);
    virtual void Unk_10(ChildCell* target);
    void MagicCaster_FindTargets(float a1, int a2, bool a3, float a4, int a5);
    void MagicCaster_CastAddiction(RefShell* ref, bool flag);
};

// @fnv 0x00815670
// src: XBOX_PDB 0x00815670
void FUN_00815670_cls::MagicCaster_CastAddiction(RefShell* ref, bool flag)
{
    if (ref->child.Unk_06() == 10)
    {
        Unk_10(ref ? &ref->child : 0);
        MagicCaster_FindTargets(0.0f, 0, flag, 1.0f, 0);
    }
}

class B8182D0Target
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
    virtual void vfunc0C();
    virtual void vfunc0D();
    virtual void vfunc0E();
    virtual void vfunc0F();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void Apply(void* pvArg);
};

class B8182D0Object
{
  public:
    void activate_00c9c1d0();
    B8182D0Target* CombatGroup_GetLastSearchAreaUpdateTimer();
    void ApplyToTarget(void* pvArg);
};

// Calls FUN_00c9c1d0, then gets the target via FUN_009d9f40 and calls its Apply with pvArg.
// @fnv 0x008182d0
void B8182D0Object::ApplyToTarget(void* pvArg)
{
    activate_00c9c1d0();
    CombatGroup_GetLastSearchAreaUpdateTimer()->Apply(pvArg);
}

// Update the owned effect; drop it once it has finished (unless this owner keeps finished effects).

class B8B10Effect
{
  public:
    ~B8B10Effect();
    void Update(float fTime);
    bool IsActive();
};

class B8B10Owner
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual int KeepsFinishedEffects();

    B8B10Effect* m_pkEffect;

    void UpdateEffect(float fTime);
};

// Updates m_pkEffect with fTime and deletes it when finished effects are not kept and the effect is no longer active.
// @fnv 0x00818b10
void B8B10Owner::UpdateEffect(float fTime)
{
    if (m_pkEffect)
    {
        m_pkEffect->Update(fTime);
        if (!KeepsFinishedEffects() && !m_pkEffect->IsActive())
        {
            delete m_pkEffect;
            m_pkEffect = 0;
        }
    }
}

struct EmbV
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
    virtual void* v11();
};

struct OuterB
{
    int unk00;
    int unk04;
    int unk08;
    EmbV emb;
};

struct Callee00815410
{
    void* FUN_00815410();
};

struct Callee0084e3a0
{
    void* GetHavokWorldObjectCountInSceneGraph_0084e3a0();
};

extern int DAT_01184638;
extern int DAT_011a1224;
void* __cdecl FUN_00ec43fb(void* a0, int a1, int* a2, int* a3, int a4);

struct FUN_00818be0_cls
{
    void* MagicCaster_GetMagicCasterFormID();
};

// @fnv 0x00818be0
// src: COMMUNITY 0x00818be0
void* FUN_00818be0_cls::MagicCaster_GetMagicCasterFormID()
{
    void* a = ((Callee00815410*)this)->FUN_00815410();
    OuterB* b = (OuterB*)FUN_00ec43fb(this, 0, &DAT_011a1224, &DAT_01184638, 0);
    if (a != 0)
    {
        return ((Callee0084e3a0*)a)->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    }
    else
    {
        if (b != 0)
        {
            if (b->emb.v11() != 0)
            {
                return ((Callee0084e3a0*)b->emb.v11())->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
            }
        }
    }
    return 0;
}


struct FeedbackActor
{
    virtual void Unk000();
    virtual void Unk001();
    virtual void Unk002();
    virtual void Unk003();
    virtual void Unk004();
    virtual void Unk005();
    virtual void Unk006();
    virtual void Unk007();
    virtual void Unk008();
    virtual void Unk009();
    virtual void Unk010();
    virtual void Unk011();
    virtual void Unk012();
    virtual void Unk013();
    virtual void Unk014();
    virtual void Unk015();
    virtual void Unk016();
    virtual void Unk017();
    virtual void Unk018();
    virtual void Unk019();
    virtual void Unk020();
    virtual void Unk021();
    virtual void Unk022();
    virtual void Unk023();
    virtual void Unk024();
    virtual void Unk025();
    virtual void Unk026();
    virtual void Unk027();
    virtual void Unk028();
    virtual void Unk029();
    virtual void Unk030();
    virtual void Unk031();
    virtual void Unk032();
    virtual void Unk033();
    virtual void Unk034();
    virtual void Unk035();
    virtual void Unk036();
    virtual void Unk037();
    virtual void Unk038();
    virtual void Unk039();
    virtual void Unk040();
    virtual void Unk041();
    virtual void Unk042();
    virtual void Unk043();
    virtual void Unk044();
    virtual void Unk045();
    virtual void Unk046();
    virtual void Unk047();
    virtual void Unk048();
    virtual void Unk049();
    virtual void Unk050();
    virtual void Unk051();
    virtual void Unk052();
    virtual void Unk053();
    virtual void Unk054();
    virtual void Unk055();
    virtual void Unk056();
    virtual void Unk057();
    virtual void Unk058();
    virtual void Unk059();
    virtual void Unk060();
    virtual void Unk061();
    virtual void Unk062();
    virtual void Unk063();
    virtual void Unk064();
    virtual void Unk065();
    virtual void Unk066();
    virtual void Unk067();
    virtual void Unk068();
    virtual void Unk069();
    virtual void Unk070();
    virtual void Unk071();
    virtual void Unk072();
    virtual void Unk073();
    virtual void Unk074();
    virtual void Unk075();
    virtual void Unk076();
    virtual void Unk077();
    virtual void Unk078();
    virtual void Unk079();
    virtual void Unk080();
    virtual void Unk081();
    virtual void Unk082();
    virtual void Unk083();
    virtual void Unk084();
    virtual void Unk085();
    virtual void Unk086();
    virtual void Unk087();
    virtual void Unk088();
    virtual void Unk089();
    virtual void Unk090();
    virtual void Unk091();
    virtual void Unk092();
    virtual void Unk093();
    virtual void Unk094();
    virtual void Unk095();
    virtual void Unk096();
    virtual void Unk097();
    virtual void Unk098();
    virtual void Unk099();
    virtual void Unk100();
    virtual void Unk101();
    virtual void Unk102();
    virtual void Unk103();
    virtual void Unk104();
    virtual void Unk105();
    virtual void Unk106();
    virtual void Unk107();
    virtual void Unk108();
    virtual void Unk109();
    virtual void Unk110();
    virtual void Unk111();
    virtual void Unk112();
    virtual void Unk113();
    virtual void Unk114();
    virtual void Unk115();
    virtual void Unk116();
    virtual void Unk117();
    virtual void Unk118();
    virtual void Unk119();
    virtual void Unk120();
    virtual void Unk121();
    virtual void Unk122();
    virtual void Unk123();
    virtual void Unk124();
    virtual void Unk125();
    virtual void Unk126();
    virtual void Unk127();
    virtual void Unk128();
    virtual void Unk129();
    virtual void Unk130();
    virtual void Unk131();
    virtual void Unk132();
    virtual void Unk133();
    virtual void Unk134();
    virtual void Unk135();
    virtual void Unk136();
    virtual void Unk137();
    virtual void Unk138();
    virtual void Unk139();
    virtual void Unk140();
    virtual void Unk141();
    virtual void Unk142();
    virtual void Unk143();
    virtual void Unk144();
    virtual void Unk145();
    virtual void Unk146();
    virtual void Unk147();
    virtual void Unk148();
    virtual void Unk149();
    virtual void Unk150();
    virtual void Unk151();
    virtual void Unk152();
    virtual void Unk153();
    virtual void Unk154();
    virtual void Unk155();
    virtual void Unk156();
    virtual void Unk157();
    virtual void Unk158();
    virtual void Unk159();
    virtual void Unk160();
    virtual void Unk161();
    virtual void Unk162();
    virtual void Unk163();
    virtual void Unk164();
    virtual void Unk165();
    virtual void Unk166();
    virtual void Unk167();
    virtual void Unk168();
    virtual void Unk169();
    virtual void Unk170();
    virtual void Unk171();
    virtual void Unk172();
    virtual void Unk173();
    virtual void Unk174();
    virtual void Unk175();
    virtual void Unk176();
    virtual void Unk177();
    virtual void Unk178();
    virtual void Unk179();
    virtual void Unk180();
    virtual void Unk181();
    virtual void Unk182();
    virtual void Unk183();
    virtual void Unk184();
    virtual void Unk185();
    virtual void Unk186();
    virtual void Unk187();
    virtual void Unk188();
    virtual void Unk189();
    virtual void Unk190();
    virtual void Unk191();
    virtual void Unk192();
    virtual void Unk193();
    virtual void Unk194();
    virtual void Unk195();
    virtual void Unk196();
    virtual void Unk197();
    virtual void Unk198();
    virtual void Unk199();
    virtual void Unk200();
    virtual void Unk201();
    virtual void Unk202();
    virtual void Unk203();
    virtual void Unk204();
    virtual void Unk205();
    virtual void Unk206();
    virtual void Unk207();
    virtual void Unk208();
    virtual void Unk209();
    virtual void Unk210();
    virtual void Unk211();
    virtual void Unk212();
    virtual void Unk213();
    virtual void Unk214();
    virtual void Unk215();
    virtual bool IsPlayer();
    BSSoundHandle PlaySoundAtOwner(const char*, int, unsigned int);
};
// Legacy food-effect interface at +0x3c; the shared IngredientItem has no declaration for this call.
struct IngredientData
{
    virtual void Unk0();
    virtual bool HasFoodEffect();
};

struct SoundFile
{
    const char* TESModel_GetModel();
};

struct SpellFeedback : MagicItem
{
    EffectSetting* FUN_0040a300(int);
    ::BSStringT<char> GetNameForType(int);
};
struct FUN_0081c470_shell
{
    void MagicLight_Fade(bool, float);
};
struct CastingCheck : MagicCaster
{
    bool TryCast(TESBoundObject* source);
    FeedbackActor* FUN_00815410();
    void MagicCaster_FindTargets(float, TESBoundObject*, bool, float, bool);
};
bool __cdecl QueueUIMessage(const char*, int, const char*, const char*, float, bool);

// @fnv 0x00815870
bool CastingCheck::TryCast(TESBoundObject* source)
{
    if (!GetSelectedMagicItem())
        return false;
    float cost = 0.0f;
    MagicItem* releasedSpell = GetSelectedMagicItem();
    IngredientItem* pCastSpell = dynamic_cast<IngredientItem*>(releasedSpell);
    int eReason = 0;
    if (!CanCast(GetSelectedMagicItem(), &cost, &eReason, false))
    {
        FeedbackActor* actor = FUN_00815410();
        EffectSetting* effect = ((SpellFeedback*)GetSelectedMagicItem())->FUN_0040a300(0);
        if (actor && effect)
        {
            TESSound* sound = 0;
            if (sound && ((SoundFile*)((char*)sound + sizeof(TESBoundAnimObject)))->TESModel_GetModel() && !pCastSpell)
            {
                const char* filename = sound->TESSound_GetFilename();
                actor->PlaySoundAtOwner(filename, 0, 0x40000102);
            }
        }
        ::BSStringT<char> message = ((SpellFeedback*)GetSelectedMagicItem())->GetNameForType(eReason);
        if (actor && actor->IsPlayer() && (!pCastSpell || reinterpret_cast<IngredientData*>((char*)pCastSpell + 0x3c)->HasFoodEffect()))
            QueueUIMessage(message.String(), 0, 0, 0, 2.0f, false);
        SetState(MagicCaster::ERR_CANNOT_CAST, (char*)message.String());
        SpellCast(GetSelectedMagicItem(), false);
        SetSelectedMagicItem((MagicItem*)0);
        SetMagicTarget(0);
        return false;
    }
    SetState(MagicCaster::RELEASE, "Release Cast");
    MagicItem* spell = GetSelectedMagicItem();
    MagicCaster_FindTargets(cost, source, false, 1.0f, false);
    SpellCast(spell, true);
    if (apTargetLight)
        ((FUN_0081c470_shell*)apTargetLight)->MagicLight_Fade(false, 0.75f);
    return true;
}

struct Target;
struct Ref;
struct Item;
struct Target
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
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
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual void slot125();
    virtual void slot126();
    virtual void slot127();
    virtual void slot128();
    virtual void slot129();
    virtual void slot130();
    virtual void slot131();
    virtual void slot132();
    virtual void slot133();
    virtual void slot134();
    virtual void slot135();
    virtual void slot136();
    virtual void slot137();
    virtual void slot138();
    virtual void slot139();
    virtual void slot140();
    virtual void slot141();
    virtual void slot142();
    virtual void slot143();
    virtual void slot144();
    virtual void slot145();
    virtual void slot146();
    virtual void slot147();
    virtual void slot148();
    virtual void slot149();
    virtual void slot150();
    virtual void slot151();
    virtual void slot152();
    virtual void slot153();
    virtual void slot154();
    virtual void slot155();
    virtual void slot156();
    virtual void slot157();
    virtual void slot158();
    virtual void slot159();
    virtual void slot160();
    virtual void slot161();
    virtual void slot162();
    virtual void slot163();
    virtual void slot164();
    virtual void slot165();
    virtual void slot166();
    virtual void slot167();
    virtual void slot168();
    virtual void slot169();
    virtual void slot170();
    virtual void slot171();
    virtual void slot172();
    virtual void slot173();
    virtual void slot174();
    virtual void slot175();
    virtual void slot176();
    virtual void slot177();
    virtual void slot178();
    virtual void slot179();
    virtual void slot180();
    virtual void slot181();
    virtual void slot182();
    virtual void slot183();
    virtual void slot184();
    virtual void slot185();
    virtual void slot186();
    virtual void slot187();
    virtual void slot188();
    virtual void slot189();
    virtual void slot190();
    virtual void slot191();
    virtual void slot192();
    virtual void slot193();
    virtual void slot194();
    virtual void slot195();
    virtual void slot196();
    virtual void slot197();
    virtual void slot198();
    virtual void slot199();
    virtual void slot200();
    virtual void slot201();
    virtual void slot202();
    virtual void slot203();
    virtual void slot204();
    virtual void slot205();
    virtual void slot206();
    virtual void slot207();
    virtual void slot208();
    virtual void slot209();
    virtual void slot210();
    virtual void slot211();
    virtual void slot212();
    virtual void slot213();
    virtual void slot214();
    virtual void slot215();
    virtual void slot216();
    virtual void slot217();
    virtual void slot218();
    virtual void slot219();
    virtual void slot220();
    virtual void slot221();
    virtual void slot222();
    virtual void slot223();
    virtual void slot224();
    virtual void slot225();
    virtual void slot226();
    virtual void slot227();
    virtual void slot228();
    virtual void slot229();
    virtual void slot230();
    virtual void slot231();
    virtual void slot232();
    virtual void slot233();
    virtual void slot234();
    virtual void slot235();
    virtual void slot236();
    virtual void slot237();
    virtual void slot238();
    virtual void slot239();
    virtual void slot240();
    virtual void slot241();
    virtual void slot242();
    virtual void slot243();
    virtual void slot244();
    virtual void slot245();
    virtual void slot246();
    virtual void slot247();
    virtual void slot248();
    virtual void slot249();
    virtual void slot250();
    virtual void slot251();
    virtual void slot252();
    virtual void slot253();
    virtual void slot254();
    virtual void slot255();
    virtual void slot256();
    virtual void slot257();
    virtual void slot258();
    virtual void slot259();
    virtual void slot260();
    virtual void slot261();
    virtual void slot262();
    virtual void slot263();
    virtual void slot264();
    virtual void slot265();
    virtual void slot266();
    virtual void slot267();
    virtual void slot268();
    virtual void slot269();
    virtual void slot270();
    virtual void slot271();
    virtual void slot272();
    virtual void slot273();
    virtual void slot274();
    virtual void slot275();
    virtual void slot276();
    virtual void slot277();
    virtual void slot278();
    virtual void slot279();
    virtual void slot280();
    virtual void slot281();
    virtual void slot282();
    virtual void slot283();
    virtual void slot284();
    virtual void slot285();
    virtual void slot286();
    virtual void slot287();
    virtual void notify(int, int, float);
};
struct ActorTarget : Target
{
    bool GetGhost();
};
struct Ref
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
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
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual Target* target();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual int eligible();
    float distance(NiPoint3*);
};
struct TargetView
{
    ActorTarget* actor();
};
struct Filter
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
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
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual void slot125();
    virtual void slot126();
    virtual void slot127();
    virtual void slot128();
    virtual void slot129();
    virtual void slot130();
    virtual void slot131();
    virtual void slot132();
    virtual void slot133();
    virtual void slot134();
    virtual void slot135();
    virtual void slot136();
    virtual void slot137();
    virtual void slot138();
    virtual void slot139();
    virtual void slot140();
    virtual void slot141();
    virtual void slot142();
    virtual void slot143();
    virtual void slot144();
    virtual void slot145();
    virtual void slot146();
    virtual void slot147();
    virtual void slot148();
    virtual void slot149();
    virtual void slot150();
    virtual void slot151();
    virtual void slot152();
    virtual void slot153();
    virtual void slot154();
    virtual void slot155();
    virtual void slot156();
    virtual void slot157();
    virtual void slot158();
    virtual void slot159();
    virtual void slot160();
    virtual void slot161();
    virtual void slot162();
    virtual void slot163();
    virtual void slot164();
    virtual void slot165();
    virtual void slot166();
    virtual void slot167();
    virtual void slot168();
    virtual void slot169();
    virtual void slot170();
    virtual void slot171();
    virtual void slot172();
    virtual void slot173();
    virtual void slot174();
    virtual void slot175();
    virtual void slot176();
    virtual void slot177();
    virtual void slot178();
    virtual void slot179();
    virtual void slot180();
    virtual void slot181();
    virtual void slot182();
    virtual void slot183();
    virtual void slot184();
    virtual void slot185();
    virtual void slot186();
    virtual void slot187();
    virtual void slot188();
    virtual void slot189();
    virtual void slot190();
    virtual void slot191();
    virtual void slot192();
    virtual void slot193();
    virtual void applied(Target*, Item*);
    virtual void slot195();
    virtual void slot196();
    virtual void slot197();
    virtual bool accepts(Target*, Item*);
};
struct Magic
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual int kind();
    int unk04;
    int unk08;
    Effects_magiccaster effects;
};
struct Item
{
    EffectItem* area();
};
struct Node
{
    Ref** data();
    Node* next();
};
struct FloatSetting
{
    float* Float();
};
extern FloatSetting originalRuntimeFloatSetting1112;
struct Caster
{
    ActorTarget* owner();
    bool apply(Target*, NiPoint3, Magic*, Item*, int);
    void ApplyAreaEffect(Magic*, Item*, int, NiPoint3, Target*, Filter*, Node*, bool*, float);
};
// @fnv 0x00816f10
void Caster::ApplyAreaEffect(Magic* magic, Item* item, int enabled, NiPoint3 pos, Target* exclude, Filter* filter,
                             Node* list, bool* done, float scale)
{
    if (!enabled)
        return;
    int radius5 = item->area()->GetArea();
    if (radius5 > 0)
    {
        radius5 *= (int)(*originalRuntimeFloatSetting1112.Float() * scale);
        ActorTarget* source7 = owner();
        bool notified5 = *done;
        Node* nodeB = list;
        while (nodeB && *nodeB->data())
        {
            Ref* ref5 = *nodeB->data();
            if (ref5)
            {
                Target* target = ref5->target();
                bool isSource = false;
                ActorTarget* actorA = target ? ((TargetView*)target)->actor() : 0;
                if (source7)
                    isSource = actorA == source7;
                if (target && !isSource && target != exclude && ref5->eligible())
                {
                    float distance4 = ref5->distance(&pos);
                    if (distance4 <= radius5 && (!actorA || !actorA->GetGhost()))
                    {
                        if (!filter || filter->accepts(target, item))
                        {
                            if (apply(target, pos, magic, item, 1))
                            {
                                if (filter)
                                    filter->applied(target, item);
                                if (!exclude && !notified5 && source7 && (!magic->kind() || magic->kind() == 5))
                                {
                                    notified5 = true;
                                    *done = true;
                                    source7->notify(magic->effects.count(), 1, 0.0f);
                                }
                            }
                        }
                    }
                }
            }
            nodeB = nodeB->next();
        }
    }
}


struct P142Node
{
    EffectItem* item;
    P142Node* next;
    EffectItem** FUN_006815c0();
    P142Node* FUN_00726070();
};
struct P142Prefix
{
    int unknown;
};
struct P142EffectList : P142Prefix, P142Node
{
    EffectItem* FindCostliestEffectItem(int, int);
    int EffectItemList_GetAssociatedSkill(int, float);
};
struct P142Spell : TESFullName, P142EffectList
{
    virtual bool IsAutoCalculated();
    virtual void SetPlayable(bool);
    virtual int GetSpellType();
};
struct P142Caster;
struct P142Ref
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
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
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual bool IsActor();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual MagicTarget* GetMagicTarget();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual void slot125();
    virtual void slot126();
    virtual void slot127();
    virtual void slot128();
    virtual void slot129();
    virtual void slot130();
    virtual void slot131();
    virtual void slot132();
    virtual void slot133();
    virtual void slot134();
    virtual void slot135();
    virtual void slot136();
    virtual void slot137();
    virtual void slot138();
    virtual void slot139();
    virtual void slot140();
    virtual void slot141();
    virtual void slot142();
    virtual void slot143();
    virtual void slot144();
    virtual void slot145();
    virtual void slot146();
    virtual void slot147();
    virtual void slot148();
    virtual void slot149();
    virtual void slot150();
    virtual void slot151();
    virtual void slot152();
    virtual void slot153();
    virtual void slot154();
    virtual void slot155();
    virtual void slot156();
    virtual void slot157();
    virtual void slot158();
    virtual void slot159();
    virtual void slot160();
    virtual void slot161();
    virtual void slot162();
    virtual void slot163();
    virtual void slot164();
    virtual void slot165();
    virtual void slot166();
    virtual void slot167();
    virtual void slot168();
    virtual void slot169();
    virtual void slot170();
    virtual void slot171();
    virtual void slot172();
    virtual void slot173();
    virtual void slot174();
    virtual void slot175();
    virtual void slot176();
    virtual void slot177();
    virtual void slot178();
    virtual void slot179();
    virtual void slot180();
    virtual void slot181();
    virtual void slot182();
    virtual void slot183();
    virtual void slot184();
    virtual void slot185();
    virtual void slot186();
    virtual void slot187();
    virtual void slot188();
    virtual void slot189();
    virtual void slot190();
    virtual void slot191();
    virtual void slot192();
    virtual void slot193();
    virtual void slot194();
    virtual void slot195();
    virtual void slot196();
    virtual void slot197();
    virtual bool AllowsEffect(MagicTarget*, ActiveEffect*);
    virtual void slot199();
    virtual void slot200();
    virtual void slot201();
    virtual void slot202();
    virtual void slot203();
    virtual void slot204();
    virtual void slot205();
    virtual void slot206();
    virtual void slot207();
    virtual void slot208();
    virtual void slot209();
    virtual void slot210();
    virtual void slot211();
    virtual void slot212();
    virtual void slot213();
    virtual void slot214();
    virtual void slot215();
    virtual void slot216();
    virtual void slot217();
    virtual void slot218();
    virtual void slot219();
    virtual void slot220();
    virtual void slot221();
    virtual void slot222();
    virtual void slot223();
    virtual void slot224();
    virtual void slot225();
    virtual void slot226();
    virtual void slot227();
    virtual void slot228();
    virtual void slot229();
    virtual void slot230();
    virtual void slot231();
    virtual void slot232();
    virtual void slot233();
    virtual void slot234();
    virtual void slot235();
    virtual void slot236();
    virtual void slot237();
    virtual void slot238();
    virtual void slot239();
    virtual void slot240();
    virtual void slot241();
    virtual void slot242();
    virtual void slot243();
    virtual void slot244();
    virtual void slot245();
    virtual void slot246();
    virtual void slot247();
    virtual void slot248();
    virtual void slot249();
    virtual void slot250();
    virtual void slot251();
    virtual void slot252();
    virtual void slot253();
    virtual void slot254();
    virtual void slot255();
    virtual void slot256();
    virtual void slot257();
    virtual void slot258();
    virtual void slot259();
    virtual void slot260();
    virtual void slot261();
    virtual void slot262();
    virtual void slot263();
    virtual void slot264();
    virtual void slot265();
    virtual void slot266();
    virtual void slot267();
    virtual void slot268();
    virtual void slot269();
    virtual void slot270();
    virtual void slot271();
    virtual void slot272();
    virtual void slot273();
    virtual void slot274();
    virtual void slot275();
    virtual void slot276();
    virtual void slot277();
    virtual void slot278();
    virtual void slot279();
    virtual void slot280();
    virtual void slot281();
    virtual void slot282();
    virtual void slot283();
    virtual void slot284();
    virtual void slot285();
    virtual void slot286();
    virtual void slot287();
    virtual void NotifySpell(int);
    P142Caster* FUN_009185e0();
    P142Ref* GetAVEffect();
    int FUN_004086a0();
};
struct P142Caster : MagicCaster
{
    P142Ref* FUN_00815410();
    void GatherTargetsInArea(P142Spell*, int, NiPoint3, BSSimpleList<const char*>*);
    bool FUN_00817940(MagicTarget*, NiPoint3, P142Spell*, ActiveEffect*, bool);
    void ApplyAreaEffect(P142Spell*, ActiveEffect*, int, NiPoint3, MagicTarget*, P142Ref*, BSSimpleList<const char*>*,
                         bool*, float);
    void MagicCaster_DoExplosion(NiPoint3, int, P142Spell*, EffectItem*, BSSimpleList<const char*>*, float, float);
    bool CheckHealthDamageKill(MagicTarget*, P142Spell*);
    void ApplyExplosion(Actor*, NiPoint3, EffectItem*, float);
    void ApplySpellEffects(P142Spell*, int, NiPoint3, P142Ref*, P142Ref*, int, float, float);
};
// Applies each effect item of the spell to the target, creating active effects, notifying the caster, and handling secondary effects.
// @fnv 0x00817160
void P142Caster::ApplySpellEffects(P142Spell* spell, int flags, NiPoint3 position, P142Ref* source, P142Ref* target,
                                   int unused, float effectiveness, float magnitude)
{
    P142EffectList* targets = spell;
    float entry = spell->GetSpellType() == 0 ? GetCasterEffectiveness(false, 0.0f) : 1.0f;
    entry *= effectiveness;
    EffectItem* notified = spell->FindCostliestEffectItem(2, 0);
    BSSimpleList<const char*> special;
    special.RemoveAll();
    GatherTargetsInArea(spell, 2, position, &special);
    bool modifier = false;
    while (targets)
    {
        EffectItem* item = *targets->FUN_006815c0();
        if (item && item->GetRange() == 2)
        {
            ActiveEffect* effect = CreateActiveEffect((MagicItem*)spell, item, 0);
            if (item != notified)
            {
                effect->AddFlags(4);
                effect->AddFlags(2);
                effect->AddFlags(8);
            }
            effect->FUN_00804bc0(entry);
            if (target && target->GetMagicTarget() && target != (P142Ref*)GetCasterReference() &&
                (!source || source->AllowsEffect(target->GetMagicTarget(), effect)))
            {
                bool added = FUN_00817940(target->GetMagicTarget(), position, spell, effect, false);
                if (added)
                {
                    P142Caster* caster = source->FUN_009185e0();
                    P142Ref* ref = caster ? caster->FUN_00815410() : 0;
                    if ((ref && !modifier && spell->GetSpellType() == 0) || spell->GetSpellType() == 5)
                    {
                        modifier = true;
                        ref->NotifySpell(spell->EffectItemList_GetAssociatedSkill(1, 0.0f));
                    }
                }
            }
            ApplyAreaEffect(spell, effect, flags, position, target ? target->GetMagicTarget() : 0, source, &special,
                            &modifier, magnitude);
            delete effect;
        }
        targets = static_cast<P142EffectList*>(targets->FUN_00726070());
    }
    bool primary = source->GetAVEffect()->FUN_004086a0() == 3;
    EffectItem* secondary = spell->FindCostliestEffectItem(2, 1);
    if (!primary)
    {
        if (secondary)
            MagicCaster_DoExplosion(position, flags, spell, secondary, &special, effectiveness, magnitude);
        else if (target && target->IsActor() && notified && notified->GetEffectSetting()->IsFlagSet_00403e60(0x20000000))
        {
            Actor* actor = (Actor*)target;
            if (CheckHealthDamageKill(actor, spell))
                ApplyExplosion(actor, position, notified, notified->GetRawCost());
        }
    }
    special.RemoveAll();
}

namespace fnv_00817970 {
struct HealthRef : TESObjectREFR
{
    float GetHealth();
    float Actor_DifficultyLevelAdjustHealthModifier(float amount, Actor* sourceActor);
};
struct EffectSettingOps : EffectSetting
{
    bool FUN_00403e80();
    int CombatController_GetCombatState();
    bool IsFlagSet_00403e60(unsigned int flag);
};

struct Recipient
{
    virtual void TargetSlot0();
    virtual HealthRef* GetActor();
    virtual EffectNode_magiccaster* GetEffects();
};
struct EffectDuration
{
    bool IsHostile_00405d80();
};
struct EffectSpec
{
    int magnitude;
    int area;
    int duration;
    EffectDuration data;
};
float __cdecl BSMAX_00404010(float a, float b);
float __cdecl BSMIN(float a, float b);
struct CasterOps : MagicCaster
{
    Actor* FUN_00815410();
    bool CheckHealthDamageKill(Recipient* target, EffectSpec* spell);
};
// @fnv 0x00817970
bool CasterOps::CheckHealthDamageKill(Recipient* pRecipient, EffectSpec* pEffectSpec)
{
    if (!pRecipient || !pEffectSpec || !pRecipient->GetActor() || !pRecipient->GetActor()->IsActor() ||
        !pRecipient->GetActor()->GetNiNode())
        return false;
    if (pEffectSpec->data.IsHostile_00405d80())
    {
        Actor* sourceActor = FUN_00815410();
        HealthRef* actor = pRecipient->GetActor();
        float health = actor->GetHealth();
        EffectNode_magiccaster* node = pRecipient->GetEffects();
        float total = 0.0f;
        while (node && !node->FUN_008256d0())
        {
            ActiveEffect* effect = *node->FUN_006815c0();
            if (effect && effect->FUN_0044ddc0() == (MagicItem*)pEffectSpec)
            {
                EffectSettingOps* setting = (EffectSettingOps*)effect->FUN_007df1d0();
                int value;
                if (setting->FUN_00403e80())
                    value = setting->CombatController_GetCombatState();
                else
                    value = effect->GetHavokWorldObjectCountInSceneGraph_0084e3a0()->GetAffectedActorValue();
                if (value == 16 && setting->IsFlagSet_00403e60(4) && !setting->IsFlagSet_00403e60(2))
                {
                    float magnitude = effect->GetFloatAtOffset1C();
                    if (effect->FUN_007df1f0() > 0.0)
                    {
                        float factor = BSMIN(4.0f, BSMAX_00404010(0.0f, effect->FUN_007df1f0()));
                        magnitude *= factor;
                    }
                    total += magnitude;
                }
            }
            node = node->FUN_00726070();
        }
        total = -actor->Actor_DifficultyLevelAdjustHealthModifier(-total, sourceActor);
        if (total >= health)
            return true;
    }
    return false;
}
}  // namespace fnv_00817970

namespace fnv_00818310 {
struct ExplosionValues
{
    int FUN_0066ef20(int);
};
class ExplosionPoint : public NiPoint3
{
  public:
    NiPoint3 __thiscall SubtractIntoVector(const NiPoint3&) const;
    float __thiscall FUN_00457990() const;
};

struct TransformNode
{
    void FUN_004b4880();
};
struct ExplosionNode
{
    TransformNode* NiAVObject_GetWorldRotate(NiTransform*);
};
class ExplosionActor;
class ExplosionProcess
{
  public:
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
    virtual void v125();
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
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual void v258();
    virtual void v259();
    virtual void v260();
    virtual void v261();
    virtual void Stagger(ExplosionActor*, NiPoint3, float);
};
class ExplosionActor
{
  public:
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
    virtual ExplosionNode* GetNode();
    virtual void v117();
    virtual NiPoint3 GetMinimum();
    virtual NiPoint3 GetMaximum();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual NiPoint3* GetPosition();
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
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual void v258();
    virtual void v259();
    virtual void v260();
    virtual void v261();
    virtual void v262();
    virtual void v263();
    virtual void v264();
    virtual void v265();
    virtual void v266();
    virtual void v267();
    virtual void v268();
    virtual void v269();
    virtual void v270();
    virtual void v271();
    virtual void v272();
    virtual void v273();
    virtual void v274();
    virtual void v275();
    virtual void v276();
    virtual void v277();
    virtual void v278();
    virtual void v279();
    virtual void v280();
    virtual void v281();
    virtual void v282();
    virtual void v283();
    virtual void v284();
    virtual void v285();
    virtual void Impulse(Actor*, float, float, NiPoint3*, NiPoint3*);
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
    ExplosionValues values;
    float GetFatigueRatio();
    ExplosionProcess* FUN_008d8520();
    const char* TESObjectREFR_GetFullName();
};
struct ExplosionCaster
{
    Actor* FUN_00815410();
    void ApplyExplosion(ExplosionActor*, NiPoint3, EffectItem*, float);
};
extern Setting originalRuntimeFloatSetting1112;
extern Setting originalRuntimeFloatSetting1131;
extern Setting g_011d180c;
extern NiPoint3 DAT_011a9478;
float __cdecl ComputeBlastPower(int, int, float, int, int, float);
bool __cdecl CombatController_GetShowVerboseMessages();
void __cdecl DebugLog(const char*, ...);
// Computes explosion magnitude from the target's height and distance to origin, clamps it, then staggers or impulses the target and logs the hit.
// @fnv 0x00818310
void ExplosionCaster::ApplyExplosion(ExplosionActor* target, NiPoint3 origin, EffectItem* effect, float strength)
{
    float h;  // Distance from the explosion origin.
    // Actor height from the upper and lower bounds.
    float a = target->GetMaximum().z - target->GetMinimum().z;
    float i;  // Explosion magnitude, capped before choosing the reaction.
    // Position raised to three quarters of the actor height.
    NiPoint3 s = *target->GetPosition();
    s.z += a * 0.75;
    // Displacement used to calculate the distance.
    NiPoint3 p = ((ExplosionPoint&)s).SubtractIntoVector(origin);
    h = ((ExplosionPoint&)p).FUN_00457990();
    i = ComputeBlastPower((int)strength, (int)(effect->GetArea() * *originalRuntimeFloatSetting1112.Float()), h,
                          target->values.FUN_0066ef20(10), target->values.FUN_0066ef20(11), target->GetFatigueRatio());
    if (i > *originalRuntimeFloatSetting1131.Float())
        i = *originalRuntimeFloatSetting1131.Float();
    if (i > *g_011d180c.Float())
    {
        target->FUN_008d8520()->Stagger(target, origin, i);
    }
    else if (i > 0.0)
    {
        Actor* caster = FUN_00815410();
        if (caster)
        {
            NiPoint3 localOrigin = DAT_011a9478;
            NiPoint3 localPosition = MagicPointZero;
            ExplosionNode* node = ((ExplosionActor*)caster)->GetNode();
            if (node)
            {
                NiTransform transform;
                node->NiAVObject_GetWorldRotate(&transform)->FUN_004b4880();
                localOrigin = *reinterpret_cast<NiPoint3*>(&transform.ComputeValue_00524c40(reinterpret_cast<const NiPoint3&>(origin)));
                localPosition = *reinterpret_cast<NiPoint3*>(&transform.ComputeValue_00524c40(reinterpret_cast<const NiPoint3&>(s)));
            }
            target->Impulse(caster, 2.0 * i, 0.0f, &localPosition, &localOrigin);
        }
    }
    if (i > 0.0 && CombatController_GetShowVerboseMessages())
        DebugLog("An explosion of %.1f magnitude hits %.20s!", i, target->TESObjectREFR_GetFullName());
}
}  // namespace fnv_00818310

struct AimPoint
{
    float x, y, z;
    AimPoint();
    AimPoint operator+(const AimPoint&) const;
    AimPoint& operator+=(const AimPoint&);
};
extern AimPoint AimZero;
struct AimRef
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
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
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual AimPoint Lower();
    virtual AimPoint Upper();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual AimPoint* Position();
    const AimPoint& FUN_00430830() const;
};
struct AimTarget
{
    virtual void slot0();
    virtual TESObjectREFR* Reference();
};
struct EffectDistance
{
    float FUN_009b0bd0() const;
};
struct EffectList
{
    EffectItem* FindCostliestEffectItem(int, int);
};
struct SpellOps
{
    int unk00, unk04, unk08;
    EffectList effects;
};
struct NodeAim
{
    const AimPoint& NiAVObject_GetWorldTranslate() const;
};
struct ActorLooking
{
    float GetLooking() const;
};
struct AimAux
{
    int GetPackageRefCount();
};
struct ActorAim : ActorVT
{
    virtual void slot225();
    virtual void slot226();
    virtual void slot227();
    virtual void slot228();
    virtual void slot229();
    virtual void slot230();
    virtual void slot231();
    virtual void slot232();
    virtual void slot233();
    virtual void slot234();
    virtual void slot235();
    virtual void slot236();
    virtual void slot237();
    virtual void slot238();
    virtual void slot239();
    virtual void slot240();
    virtual void slot241();
    virtual void slot242();
    virtual void slot243();
    virtual void slot244();
    virtual void slot245();
    virtual void slot246();
    virtual void slot247();
    virtual void slot248();
    virtual void slot249();
    virtual void slot250();
    virtual void slot251();
    virtual void slot252();
    virtual void slot253();
    virtual void slot254();
    virtual void slot255();
    virtual void slot256();
    virtual void slot257();
    virtual void slot258();
    virtual void slot259();
    virtual void slot260();
    virtual void slot261();
    virtual void slot262();
    virtual void slot263();
    virtual void slot264();
    virtual void slot265();
    virtual AimAux* Aux();
};
struct LightDelete
{
    ~LightDelete();
};
extern Setting AimRangeSetting;
AimPoint ComputeRelativeFiringAngle(TESObjectREFR*, TESObjectREFR*, float, float, int);
AimPoint CombatUtilities_GetAngleToProjectedTarget(AimPoint, TESObjectREFR*, float, float, int);
void MagicProjectile_Launch(MagicCaster*, int, MagicEffectCollection*, MagicItem*, EffectItem*, EffectSetting*, AimPoint, AimPoint);
struct FUN_00818610_class : MagicCaster
{
    void CastAimEffect();
};
// If the caster has a valid spell and effect item, computes aim points from the aim reference or actor and dispatches the magic effect via FUN_0081e040.
// @fnv 0x00818610
void FUN_00818610_class::CastAimEffect()
{
    if (!GetSelectedMagicItem())
        return;
    AimRef* s = (AimRef*)GetCasterReference();
    Actor* h = GetCasterActor();
    TESObjectREFR* p = GetCurrentMagicTarget() ? ((AimTarget*)GetCurrentMagicTarget())->Reference() : 0;
    EffectItem* i = ((SpellOps*)GetSelectedMagicItem())->effects.FindCostliestEffectItem(2, 0);
    EffectSetting* a = GetSelectedMagicItem()->GetEffectSettingForRange(MagicSystem::SELF);
    if (!i)
        return;
    if (s)
    {
        bool f = true;
        AimPoint b;
        AimPoint q = AimZero;
        AimPoint cf = AimZero;
        if (h)
        {
            cf.z = h->GetCurrentTargetDistance(false);
            cf.x = ((ActorLooking*)h)->GetLooking();
            b = *s->Position();
            float delta = s->Upper().z - s->Lower().z;
            q.z = delta * 0.699999988079071;
            b += q;
        }
        else
        {
            float distance = ((EffectDistance*)a)->FUN_009b0bd0() * *AimRangeSetting.Float();
            cf = s->FUN_00430830() + ComputeRelativeFiringAngle((TESObjectREFR*)s, p, distance, 0.0f, 2);
            b = *s->Position();
            b.z += (s->Upper().z - s->Lower().z) * 0.5;
        }
        NiNode* eb = GetMagicNode();
        if (eb)
            b = ((NodeAim*)eb)->NiAVObject_GetWorldTranslate();
        if (this != static_cast<MagicCaster*>(_g_thePlayer) && h && p)
        {
            AimAux* hDistance;
            float aAux = *AimRangeSetting.Float() * (a ? ((EffectDistance*)a)->FUN_009b0bd0() : 1.0f);
            float iMode = 0;
            hDistance = ((ActorAim*)h)->Aux();
            int pElevation = hDistance ? hDistance->GetPackageRefCount() : 1;
            cf = CombatUtilities_GetAngleToProjectedTarget(b, p, aAux, iMode, pElevation);
        }
        if (i && f)
        {
            MagicProjectile_Launch(this, 0, apTargetLight, GetSelectedMagicItem(), i, a, b, cf);
            apTargetLight = 0;
        }
        if (apTargetLight)
            delete (LightDelete*)apTargetLight;
        apTargetLight = 0;
    }
}


struct AEEffectListBase
{
    virtual void v00();
};

struct AEEffectList : AEEffectListBase, BSSimpleList<EffectItem*>
{
};

struct AEMagicItem : MagicItem, AEEffectList
{
};

struct AESpellItem : SpellItem
{
    bool IsFlagSet(unsigned int auiFlag);
};

struct AEProcess
{
    int FUN_0045cd60();
};

struct AEMobile : MobileObject
{
    AEProcess* GetCurrentProcess();
    float GetDistance(NiPoint3* apPos);
};

struct AEActor : Actor
{
    bool IsGhost();
};

struct AERefVtbl
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void v0B8();
    virtual void v0BC();
    virtual void v0C0();
    virtual void v0C4();
    virtual void v0C8();
    virtual void v0CC();
    virtual void v0D0();
    virtual void v0D4();
    virtual void v0D8();
    virtual void v0DC();
    virtual void v0E0();
    virtual void v0E4();
    virtual void v0E8();
    virtual void v0EC();
    virtual void v0F0();
    virtual void v0F4();
    virtual void v0F8();
    virtual void v0FC();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10C();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11C();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12C();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13C();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14C();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15C();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16C();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17C();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18C();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual int Unk_67();
    virtual void v1A0();
    virtual void v1A4();
    virtual void v1A8();
    virtual void v1AC();
    virtual void v1B0();
    virtual void v1B4();
    virtual void v1B8();
    virtual void v1BC();
    virtual void v1C0();
    virtual void v1C4();
    virtual void v1C8();
    virtual void v1CC();
    virtual void* GetNiNode();
};

struct AEActorArray
{
    unsigned int GetCount(int aiUnk);
    MobileObject* GetAt(unsigned int auiIndex);
};

struct AEProcessLists
{
    AEActorArray* GetHighActors();
};

extern AEProcessLists g_kAEProcessLists;
extern Setting g_kAEAreaMult;

struct AETargetList
{
    TESObjectREFR* pItem;
    AETargetList* pNext;

    void AddHead(TESObjectREFR* const& arItem);
};

struct AEGatherer
{
    Actor* GetCaster();
    bool CanTarget(NiPoint3 akPos, Actor* apActor);
    void GatherTargetsInArea(MagicItem* apItem, unsigned int auiEffectCode, NiPoint3 akPos, AETargetList* apTargets);
};

// Finds the largest area of the matching effect, then adds nearby high actors and the player within the scaled radius to apTargets.
// @fnv 0x00818ce0
void AEGatherer::GatherTargetsInArea(MagicItem* apItem, unsigned int auiEffectCode, NiPoint3 akPos,
                                     AETargetList* apTargets)
{
    if (!apTargets)
        return;

    int iMaxAreaA = 0;
    AEEffectList* pIter = apItem ? reinterpret_cast<AEEffectList*>((char*)apItem + sizeof(TESFullName)) : 0;
    while (pIter && !pIter->IsEmpty())
    {
        EffectItem* pEffect = pIter->GetItem();
        if (pEffect && pEffect->GetRange() == auiEffectCode && pEffect->GetArea() > iMaxAreaA)
            iMaxAreaA = pEffect->GetArea();
        pIter = static_cast<AEEffectList*>(pIter->GetNext());
    }
    if (!iMaxAreaA)
        return;

    SpellItem* pSpell5 = dynamic_cast<SpellItem*>(apItem);
    bool bNoCheck2 = pSpell5 && static_cast<AESpellItem*>(pSpell5)->IsFlagSet(0x10);
    float fRadius4 = iMaxAreaA * *g_kAEAreaMult.Float();
    Actor* m_pEffectInstance = GetCaster();
    AEActorArray* pActors3 = g_kAEProcessLists.GetHighActors();
    for (unsigned int i = 0; i < pActors3->GetCount(0); i++)
    {
        MobileObject* pMobile4 = pActors3->GetAt(i);
        BSSimpleList<Actor*>* pNode = 0;
        while (pMobile4)
        {
            int iValid = ((AERefVtbl*)pMobile4)->Unk_67();
            bool bIsCaster = false;
            Actor* pActor4 = dynamic_cast<Actor*>(pMobile4);
            if (m_pEffectInstance)
                bIsCaster = pActor4 == m_pEffectInstance;
            if (iValid && !bIsCaster && ((AERefVtbl*)pMobile4)->GetNiNode())
            {
                float fDist = static_cast<AEMobile*>(pMobile4)->GetDistance(&akPos);
                if (fDist <= fRadius4 && (!pActor4 || !static_cast<AEActor*>(pActor4)->IsGhost()) &&
                    (bNoCheck2 || CanTarget(akPos, pActor4)))
                {
                    apTargets->AddHead(pActor4);
                }
            }
            if (pNode && pNode->GetItem())
            {
                pMobile4 = dynamic_cast<Character*>(pNode->GetItem());
                pNode = pNode->GetNext();
                while (pMobile4 && (!static_cast<AEMobile*>(pMobile4)->GetCurrentProcess() ||
                                    static_cast<AEMobile*>(pMobile4)->GetCurrentProcess()->FUN_0045cd60()))
                {
                    if (pNode)
                        pMobile4 = dynamic_cast<Character*>(pNode->GetItem());
                    else
                        pMobile4 = 0;
                    if (pNode)
                        pNode = pNode->GetNext();
                }
            }
            else
                pMobile4 = 0;
        }
    }

    if (_g_thePlayer != m_pEffectInstance && ((AERefVtbl*)_g_thePlayer)->GetNiNode())
    {
        float fPlayerDist = static_cast<AEMobile*>(static_cast<MobileObject*>(_g_thePlayer))->GetDistance(&akPos);
        if (fPlayerDist <= fRadius4 && !static_cast<AEActor*>(_g_thePlayer)->IsGhost() &&
            (bNoCheck2 || CanTarget(akPos, _g_thePlayer)))
        {
            apTargets->AddHead(_g_thePlayer);
        }
    }
}

#include <xmmintrin.h>

struct RayGroupSrc
{
    unsigned int GetGroup();
};

struct RayCaster
{
    unsigned int GetGroup();
};

struct RayInput
{
    __m128 q00;
    __m128 q10;
    __m128 q20;
    __m128 q30;
    __m128 q40;
    __m128 q50;
    __m128 q60;
    __m128 q70;
    __m128 q80;
    __m128 q90;
    __m128 qa0;
    RayInput();
    void SetFilter(unsigned int f);
    void SetFrom(NiPoint3* p);
    void SetTo(NiPoint3* p);
};

struct RayFilter
{
    unsigned int value;
    RayFilter(int a);
    void SetLayer(int l);
    void SetGroup(unsigned int g);
};

struct RayWorld
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
    virtual bool CastRay(RayInput* input);
};

struct RayCell
{
    RayWorld* GetWorld();
};

struct RayRef
{
    virtual void w000();
    virtual void w004();
    virtual void w008();
    virtual void w00c();
    virtual void w010();
    virtual void w014();
    virtual void w018();
    virtual void w01c();
    virtual void w020();
    virtual void w024();
    virtual void w028();
    virtual void w02c();
    virtual void w030();
    virtual void w034();
    virtual void w038();
    virtual void w03c();
    virtual void w040();
    virtual void w044();
    virtual void w048();
    virtual void w04c();
    virtual void w050();
    virtual void w054();
    virtual void w058();
    virtual void w05c();
    virtual void w060();
    virtual void w064();
    virtual void w068();
    virtual void w06c();
    virtual void w070();
    virtual void w074();
    virtual void w078();
    virtual void w07c();
    virtual void w080();
    virtual void w084();
    virtual void w088();
    virtual void w08c();
    virtual void w090();
    virtual void w094();
    virtual void w098();
    virtual void w09c();
    virtual void w0a0();
    virtual void w0a4();
    virtual void w0a8();
    virtual void w0ac();
    virtual void w0b0();
    virtual void w0b4();
    virtual void w0b8();
    virtual void w0bc();
    virtual void w0c0();
    virtual void w0c4();
    virtual void w0c8();
    virtual void w0cc();
    virtual void w0d0();
    virtual void w0d4();
    virtual void w0d8();
    virtual void w0dc();
    virtual void w0e0();
    virtual void w0e4();
    virtual void w0e8();
    virtual void w0ec();
    virtual void w0f0();
    virtual void w0f4();
    virtual void w0f8();
    virtual void w0fc();
    virtual void w100();
    virtual void w104();
    virtual void w108();
    virtual void w10c();
    virtual void w110();
    virtual void w114();
    virtual void w118();
    virtual void w11c();
    virtual void w120();
    virtual void w124();
    virtual void w128();
    virtual void w12c();
    virtual void w130();
    virtual void w134();
    virtual void w138();
    virtual void w13c();
    virtual void w140();
    virtual void w144();
    virtual void w148();
    virtual void w14c();
    virtual void w150();
    virtual void w154();
    virtual void w158();
    virtual void w15c();
    virtual void w160();
    virtual void w164();
    virtual void w168();
    virtual void w16c();
    virtual void w170();
    virtual void w174();
    virtual void w178();
    virtual void w17c();
    virtual void w180();
    virtual void w184();
    virtual void w188();
    virtual void w18c();
    virtual void w190();
    virtual void w194();
    virtual void w198();
    virtual void w19c();
    virtual void w1a0();
    virtual void w1a4();
    virtual void w1a8();
    virtual void w1ac();
    virtual void w1b0();
    virtual void w1b4();
    virtual void w1b8();
    virtual void w1bc();
    virtual void w1c0();
    virtual void w1c4();
    virtual void w1c8();
    virtual void w1cc();
    virtual void w1d0();
    virtual void w1d4();
    virtual void w1d8();
    virtual void w1dc();
    virtual void w1e0();
    virtual void w1e4();
    virtual void w1e8();
    virtual void w1ec();
    virtual void w1f0();
    virtual NiPoint3* GetPos();
    RayCell* GetParentCell();
    float GetHeight();
    RayCaster* GetCaster();
};

void __cdecl RayLog(int a, unsigned __int64 b);
unsigned int GetDefaultRayGroup();
extern const double RayHeightScale;

struct RayObj
{
    bool MagicCaster_RunExplosionLOSPick(NiPoint3 from, RayRef* ref);
};

// Sets a ray from from to the reference position plus a height offset, then returns the negation of CastRay.
// @fnv 0x008190d0
// src: XBOX_PDB 0x008190d0
bool RayObj::MagicCaster_RunExplosionLOSPick(NiPoint3 from, RayRef* ref)
{
    if (!ref)
        return false;
    RayWorld* world = ref->GetParentCell() ? ref->GetParentCell()->GetWorld() : 0;
    if (!world)
        return false;
    unsigned int flag = 0x26206;
    RayLog(0x27, flag);
    NiPoint3 vTo = *ref->GetPos();
    vTo.z += ref->GetHeight() * RayHeightScale;
    RayInput input;
    RayFilter filter(0);
    filter.SetLayer(0x27);
    if (ref->GetCaster())
        filter.SetGroup(ref->GetCaster()->GetGroup());
    else
        filter.SetGroup(GetDefaultRayGroup());
    input.SetFilter(filter.value);
    input.SetFrom(&from);
    input.SetTo(&vTo);
    return !world->CastRay(&input);
}

namespace CastTargets {
struct Object;
struct Target;
struct SpellNode;
struct Context
{
    unsigned int unk00, unk04;
    Context();
    ~Context();
    void FUN_00470470();
};

extern Setting DAT_011d1a90, DAT_011d1bbc, DAT_011d1acc, DAT_011d15a4;
extern Object* DAT_011dea3c;
extern NiPoint3 DAT_011f426c;
struct EffectSettings
{
    bool IsFlagSet_00403e60(unsigned int);
    float FUN_00639b20();
};

struct EffectLink
{
    EffectItem* value;
    EffectLink* next;
    EffectItem** FUN_006815c0();
    EffectLink* FUN_00726070();
};
struct UnsignedIntegerValue
{
    unsigned int unk00;
};
struct EffectList : UnsignedIntegerValue, EffectLink
{
    bool CanBePoison();
    bool HasTouchEffect();
    bool HasNonDetrimentalEffect();
    EffectItem* FindCostliestEffectItem(int, bool);
    void* EffectItemList_GetAssociatedSkill(bool);
};
struct NameView
{
    virtual void Slot0();
    unsigned int unk04, unk08;
};
struct MagicView : NameView, EffectList
{
};
struct IngredientFlags
{
    virtual void slot0();
    virtual bool HasFoodEffect();
};

struct SpellView
{
    bool FUN_0040e210(unsigned int);
};
struct Source
{
    int FUN_00401170();
};
struct Model
{
    virtual void slot0();
    virtual void slot4();
    virtual void slot8();
    virtual void slotc();
    virtual void slot10();
    virtual const char* GetModelFilePath();
    unsigned int FUN_0048cee0();
};
struct MagicArt
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    Model model;
};
struct MagicAccessor
{
    MagicArt* FUN_0040a300(bool);
};
struct Node
{
    unsigned int NiNode_GetChildCount();
    void NiAVObject_SetScale(float);
};
struct ModelInstance
{
    void PlaySequence(const char*);
    Node* FUN_00490e40();
};
struct PositionProvider
{
    NiPoint3* NiAVObject_GetWorldTranslate();
};
struct CasterPart
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
    virtual void slot28();
    virtual void slot2c();
    virtual PositionProvider* GetSourcePosition();
    unsigned int unk04, unk08;
};
struct TargetPart
{
    unsigned int unk00;
    void ApplyAddiction(AlchemyItem*);
};
struct Object
{
    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual void slot00c();
    virtual void slot010();
    virtual void slot014();
    virtual void slot018();
    virtual void slot01c();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot02c();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03c();
    virtual void slot040();
    virtual void slot044();
    virtual void slot048();
    virtual void slot04c();
    virtual void slot050();
    virtual void slot054();
    virtual void slot058();
    virtual void slot05c();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot06c();
    virtual void slot070();
    virtual void slot074();
    virtual void slot078();
    virtual void slot07c();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot08c();
    virtual void slot090();
    virtual void slot094();
    virtual void slot098();
    virtual void slot09c();
    virtual void slot0a0();
    virtual void slot0a4();
    virtual void slot0a8();
    virtual void slot0ac();
    virtual void slot0b0();
    virtual void slot0b4();
    virtual void slot0b8();
    virtual void slot0bc();
    virtual void slot0c0();
    virtual void slot0c4();
    virtual void slot0c8();
    virtual void slot0cc();
    virtual void slot0d0();
    virtual void slot0d4();
    virtual void slot0d8();
    virtual void slot0dc();
    virtual void slot0e0();
    virtual void slot0e4();
    virtual void slot0e8();
    virtual void slot0ec();
    virtual void slot0f0();
    virtual void slot0f4();
    virtual void slot0f8();
    virtual void slot0fc();
    virtual bool IsActor();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13c();
    virtual void slot140();
    virtual void slot144();
    virtual void slot148();
    virtual void slot14c();
    virtual void slot150();
    virtual void slot154();
    virtual void slot158();
    virtual void slot15c();
    virtual void slot160();
    virtual void slot164();
    virtual void slot168();
    virtual void slot16c();
    virtual void slot170();
    virtual void slot174();
    virtual void slot178();
    virtual void slot17c();
    virtual void slot180();
    virtual void slot184();
    virtual void slot188();
    virtual void slot18c();
    virtual void slot190();
    virtual void slot194();
    virtual void slot198();
    virtual void slot19c();
    virtual void slot1a0();
    virtual void slot1a4();
    virtual void slot1a8();
    virtual void slot1ac();
    virtual void slot1b0();
    virtual void slot1b4();
    virtual void slot1b8();
    virtual void slot1bc();
    virtual void slot1c0();
    virtual void slot1c4();
    virtual void slot1c8();
    virtual void slot1cc();
    virtual void slot1d0();
    virtual void slot1d4();
    virtual void slot1d8();
    virtual void slot1dc();
    virtual void slot1e0();
    virtual void slot1e4();
    virtual void slot1e8();
    virtual void slot1ec();
    virtual void slot1f0();
    virtual NiPoint3* GetPosition();
    virtual void slot1f8();
    virtual void slot1fc();
    virtual void slot200();
    virtual void slot204();
    virtual void slot208();
    virtual void slot20c();
    virtual void slot210();
    virtual int GetActorType();
    virtual void slot218();
    virtual void slot21c();
    virtual void slot220();
    virtual void slot224();
    virtual void slot228();
    virtual void slot22c();
    virtual void slot230();
    virtual void slot234();
    virtual void slot238();
    virtual void slot23c();
    virtual void slot240();
    virtual void slot244();
    virtual void slot248();
    virtual void slot24c();
    virtual void slot250();
    virtual void slot254();
    virtual void slot258();
    virtual void slot25c();
    virtual void slot260();
    virtual void slot264();
    virtual void slot268();
    virtual void slot26c();
    virtual void slot270();
    virtual void slot274();
    virtual void slot278();
    virtual void slot27c();
    virtual void slot280();
    virtual void slot284();
    virtual void slot288();
    virtual void slot28c();
    virtual void slot290();
    virtual void slot294();
    virtual void slot298();
    virtual void slot29c();
    virtual void slot2a0();
    virtual void slot2a4();
    virtual void slot2a8();
    virtual void slot2ac();
    virtual void slot2b0();
    virtual void slot2b4();
    virtual void slot2b8();
    virtual void slot2bc();
    virtual void slot2c0();
    virtual void slot2c4();
    virtual void slot2c8();
    virtual void slot2cc();
    virtual void slot2d0();
    virtual void slot2d4();
    virtual void slot2d8();
    virtual void slot2dc();
    virtual void slot2e0();
    virtual void slot2e4();
    virtual void slot2e8();
    virtual void slot2ec();
    virtual void slot2f0();
    virtual void slot2f4();
    virtual void slot2f8();
    virtual void slot2fc();
    virtual void slot300();
    virtual void slot304();
    virtual void slot308();
    virtual void slot30c();
    virtual void slot310();
    virtual void slot314();
    virtual void slot318();
    virtual void slot31c();
    virtual void slot320();
    virtual void slot324();
    virtual void slot328();
    virtual void slot32c();
    virtual void slot330();
    virtual void slot334();
    virtual void slot338();
    virtual void slot33c();
    virtual void slot340();
    virtual void slot344();
    virtual void slot348();
    virtual void slot34c();
    virtual void slot350();
    virtual void slot354();
    virtual void slot358();
    virtual void slot35c();
    virtual bool IsCharacter();
    virtual void slot364();
    virtual void slot368();
    virtual void slot36c();
    virtual void slot370();
    virtual void slot374();
    virtual void slot378();
    virtual void slot37c();
    virtual float GetReach();
    virtual void slot384();
    virtual void slot388();
    virtual void slot38c();
    virtual void slot390();
    virtual void slot394();
    virtual void slot398();
    virtual void slot39c();
    virtual void slot3a0();
    virtual void slot3a4();
    virtual void slot3a8();
    virtual void slot3ac();
    virtual void slot3b0();
    virtual void slot3b4();
    virtual void slot3b8();
    virtual void slot3bc();
    virtual void slot3c0();
    virtual void slot3c4();
    virtual void slot3c8();
    virtual void slot3cc();
    virtual void slot3d0();
    virtual void slot3d4();
    virtual void slot3d8();
    virtual void slot3dc();
    virtual void slot3e0();
    virtual void slot3e4();
    virtual void slot3e8();
    virtual void slot3ec();
    virtual void slot3f0();
    virtual void slot3f4();
    virtual void slot3f8();
    virtual void slot3fc();
    virtual void slot400();
    virtual void slot404();
    virtual void slot408();
    virtual void slot40c();
    virtual void slot410();
    virtual void slot414();
    virtual void slot418();
    virtual void slot41c();
    virtual void slot420();
    virtual void slot424();
    virtual void slot428();
    virtual void slot42c();
    virtual void slot430();
    virtual void slot434();
    virtual void slot438();
    virtual void slot43c();
    virtual void slot440();
    virtual void slot444();
    virtual void slot448();
    virtual void slot44c();
    virtual void slot450();
    virtual void slot454();
    virtual void slot458();
    virtual void slot45c();
    virtual void slot460();
    virtual void slot464();
    virtual void slot468();
    virtual void slot46c();
    virtual void slot470();
    virtual void slot474();
    virtual void slot478();
    virtual void slot47c();
    virtual void UseSkill(void*, float);
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
    CasterPart caster;
    TargetPart target;
    float TESObjectREFR_GetScale_00567400();
    float AttachSubObject();
    float Actor_GetSurvivalEffectivenessMultiplier();
    void* FUN_008d6f30();
    NiPoint3* FUN_00430830();
};
struct Target
{
    virtual void slot0();
    virtual Object* GetObject();
};
struct Loader
{
    void ModelLoader_ReleaseModel(const char*, bool, int);
};
extern Loader* DAT_011c3b3c;
extern const char DAT_0107acfc[];
extern const char DAT_0102054c[];
float BSMAX_00404010(float, float);
float CombatUtilities_GetDistanceBetweenFacingActors(Object*, Object*, bool);
bool EnchantmentItem_IsValidEffectForEnchantment(Source*, int, EffectSettings*, bool);
void ComputeDerivedValues(float*, float*, float, float, int, int, float, float, float, int);
void ComputeScaledResult(float*, float, float, int, int, float, float, float, int);
void ComputeSettingAdjustedValue(float*, float, float, int, int, float, float, float, int);
float FUN_004bd510(float, float);
void FUN_005e58f0(int, Object*, float*);
float NiCos(float);
float NiSin_005c53d0(float);
ModelInstance* BSTempEffectParticle_Spawn(void*, float, const char*, NiPoint3, NiPoint3, float, int, int);
struct Caster
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual Target* GetSpellTarget();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual Object* GetCasterObject();
    virtual Node* GetMagicNode();
    virtual MagicItem* GetSpell();
    virtual bool HasActiveEffect(ActiveEffect*);
    virtual float Effectiveness(bool, float);
    virtual void SetSpell(MagicItem*);
    virtual Target* GetCurrentMagicTarget();
    virtual void SetMagicTarget(Target*);
    virtual ActiveEffect* CreateActiveEffect(MagicItem*, EffectItem*, Source*);
    void FUN_00818af0(int, const char*);
    Object* FUN_00815410();
    void GatherTargetsInArea(MagicItem*, bool, NiPoint3, Context*);
    bool FUN_00817940(Target*, NiPoint3, MagicItem*, ActiveEffect*, bool);
    void ApplyAreaEffect(MagicItem*, ActiveEffect*, void*, NiPoint3, Target*, bool, Context*, bool*, float);
    void MagicCaster_DoExplosion(NiPoint3, void*, MagicItem*, EffectItem*, Context*, float, float);
    bool CheckHealthDamageKill(MagicTarget*, MagicItem*);
    void ApplyExplosion(Actor*, NiPoint3, EffectItem*, float);
    void CastAimEffect();
    void MagicCaster_FindTargets(float, Source*, bool, float, bool);
};
// Casts the current spell on a target, creating active effects, applying area effects, and updating the caster's state.
// @fnv 0x00815d00
// src: XBOX_PDB 0x00815d00
void Caster::MagicCaster_FindTargets(float power, Source* source, bool immediate, float multiplier, bool abFlag4)
{
    MagicItem* spellB = GetSpell();
    if (!spellB)
        return;
    FUN_00818af0(4, DAT_0107acfc);
    Object* casterObjectSlot2 = GetCasterObject();
    Object* casterActorSlot25 = FUN_00815410();
    Target* target6 = 0;
    bool potion = spellB->GetSpellType() == 7;
    bool touchPotionSlot30 = potion && reinterpret_cast<MagicView*>(spellB)->CanBePoison();
    AlchemyItem* alchemy2 = potion ? dynamic_cast<AlchemyItem*>(spellB) : 0;
    if (reinterpret_cast<MagicView*>(spellB)->HasTouchEffect() || touchPotionSlot30)
    {
        bool noTouch = source ? source->FUN_00401170() == 0x29 : false;
        if (!noTouch && spellB->GetSpellType() == 6)
        {
            EnchantmentItem* enchantment = dynamic_cast<EnchantmentItem*>(spellB);
            if (enchantment)
                noTouch = enchantment->FUN_005f36f0() == 2;
        }
        if (!noTouch && (casterActorSlot25 || !GetCurrentMagicTarget()))
            target6 = GetSpellTarget();
        if (!target6)
        {
            target6 = GetCurrentMagicTarget();
            if (target6 && !source && !noTouch && target6->GetObject())
            {
                float reach = *DAT_011d1a90.Setting_Float_00403e20();
                if (casterObjectSlot2->IsActor() &&
                    (casterObjectSlot2 == DAT_011dea3c || !target6->GetObject()->IsActor() ||
                     target6->GetObject()->GetActorType() != 9))
                    reach = casterObjectSlot2->GetReach();
                reach *= BSMAX_00404010(1.0f, casterObjectSlot2->TESObjectREFR_GetScale_00567400());
                if (reach < CombatUtilities_GetDistanceBetweenFacingActors(casterObjectSlot2, target6->GetObject(), false))
                    target6 = 0;
            }
        }
    }
    bool releaseModel = false;
    Node* magicNode = GetMagicNode();
    if (magicNode && magicNode->NiNode_GetChildCount() > 0 && !source)
        releaseModel = true;
    Object* aTargetObject = target6 ? target6->GetObject() : 0;
    bool didTarget2 = false;
    MagicItem* castSpell9 = spellB;
    IngredientItem* ingredientSlot11 = dynamic_cast<IngredientItem*>(castSpell9);
    EffectItem* kSelfEffect = reinterpret_cast<MagicView*>(castSpell9)->FindCostliestEffectItem(0, false);
    EffectItem* aTouchEffect = reinterpret_cast<MagicView*>(castSpell9)->FindCostliestEffectItem(1, false);
    SpellItem* spellFormSlot1 = dynamic_cast<SpellItem*>(spellB);
    Context contextSlot12;
    contextSlot12.FUN_00470470();
    if (aTargetObject)
        GatherTargetsInArea(castSpell9, true, *aTargetObject->GetPosition(), &contextSlot12);
    else if (casterActorSlot25 && spellFormSlot1 && reinterpret_cast<SpellView*>(spellFormSlot1)->FUN_0040e210(0x80))
        GatherTargetsInArea(castSpell9, true, *casterActorSlot25->GetPosition(), &contextSlot12);
    EffectList* cursorA = static_cast<EffectList*>(reinterpret_cast<MagicView*>(spellB));
    while (cursorA)
    {
        EffectItem* effect = *cursorA->FUN_006815c0();
        if (effect && spellB->GetSpellType() == 6 && source && !EnchantmentItem_IsValidEffectForEnchantment(source, 0, reinterpret_cast<EffectSettings*>(effect->GetEffectSetting()), false))
            effect = 0;
        if (effect)
        {
            ActiveEffect* active = CreateActiveEffect(spellB, effect, source);
            EffectItem* activeEffect = (EffectItem*)active->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
            float _cost = reinterpret_cast<EffectSettings*>(activeEffect->GetEffectSetting())->FUN_00639b20();
            if (immediate)
            {
                active->AddFlags(4);
                active->AddFlags(16);
            }
            switch (spellB->GetSpellType())
            {
            case 8: {
                if (ingredientSlot11 && reinterpret_cast<IngredientFlags*>((char*)ingredientSlot11 + 0x3c)->HasFoodEffect())
                    active->BaseProcess_SetLastTimeProcessed(1.0f);
                else
                {
                    EffectSettings* _settings = (EffectSettings*)active->FUN_007df1d0();
                    float magnitude = 0, _duration = 0;
                    if (!_settings->IsFlagSet_00403e60(0x80) && !_settings->IsFlagSet_00403e60(0x100))
                        ComputeDerivedValues(&magnitude, &_duration, _cost, power, 6, 0, 0, 0, 0, 0);
                    else if (!_settings->IsFlagSet_00403e60(0x80) && _settings->IsFlagSet_00403e60(0x100))
                        ComputeScaledResult(&_duration, _cost, power, 6, 0, 0, 0, 0, 0);
                    else if (_settings->IsFlagSet_00403e60(0x80) && !_settings->IsFlagSet_00403e60(0x100))
                        ComputeSettingAdjustedValue(&magnitude, _cost, power, 6, 0, 0, 0, 0, 0);
                    _duration = FUN_004bd510(_duration, 1.0f);
                    magnitude = FUN_004bd510(magnitude, 1.0f);
                    active->BaseProcess_SetLastTimeProcessed(_duration);
                    active->ActiveEffect_SetMagnitude(magnitude);
                }
                break;
            }
            case 0:
                if (!abFlag4 || (abFlag4 && ((EffectItem*)active->GetHavokWorldObjectCountInSceneGraph_0084e3a0())->IsHostile()))
                    active->FUN_00804bc0(Effectiveness(false, 0) * multiplier);
                break;
            case 7: {
                if (alchemy2 && alchemy2->AlchemyItem_IsFlagSet(4))
                {
                    float potency = casterActorSlot25->AttachSubObject() * multiplier;
                    if (casterActorSlot25->IsCharacter() && ((EffectItem*)active->GetHavokWorldObjectCountInSceneGraph_0084e3a0())->GetAffectedActorValue() == 16)
                        FUN_005e58f0(12, casterActorSlot25, &potency);
                    active->FUN_00804bc0(potency);
                }
                if (alchemy2 && alchemy2->AlchemyItem_IsFlagSet(2) && ((EffectItem*)active->GetHavokWorldObjectCountInSceneGraph_0084e3a0())->GetAffectedActorValue() != 54)
                {
                    float foodPower = casterActorSlot25->Actor_GetSurvivalEffectivenessMultiplier() * multiplier;
                    if (casterActorSlot25->IsCharacter() && ((EffectItem*)active->GetHavokWorldObjectCountInSceneGraph_0084e3a0())->GetAffectedActorValue() == 16)
                        FUN_005e58f0(12, casterActorSlot25, &foodPower);
                    active->FUN_00804bc0(foodPower);
                }
                else if (alchemy2 && alchemy2->AlchemyItem_IsFlagSet(2) && ((EffectItem*)active->GetHavokWorldObjectCountInSceneGraph_0084e3a0())->GetAffectedActorValue() == 54)
                {
                    float modifier = 1.0f;
                    FUN_005e58f0(44, casterActorSlot25, &modifier);
                    active->FUN_00804bc0(multiplier * modifier);
                }
                break;
            }
            }
            if (effect->GetRange() == 0 && !touchPotionSlot30)
            {
                if (effect != kSelfEffect)
                {
                    active->AddFlags(4);
                    active->AddFlags(2);
                    active->AddFlags(8);
                }
                bool accepted = HasActiveEffect(active);
                if (accepted)
                    didTarget2 = true;
            }
            else if (effect->GetRange() == 1 || touchPotionSlot30)
            {
                if (effect != (touchPotionSlot30 ? kSelfEffect : aTouchEffect))
                {
                    active->AddFlags(4);
                    active->AddFlags(2);
                    active->AddFlags(8);
                }
                if (target6)
                {
                    if (FUN_00817940(target6, DAT_011f426c, spellB, active, false))
                        didTarget2 = true;
                    if (effect->GetArea() > 0 && aTargetObject)
                    {
                        bool blocked = false;
                        ApplyAreaEffect(spellB, active, aTargetObject->FUN_008d6f30(), *aTargetObject->GetPosition(),
                                        target6, false, &contextSlot12, &blocked, 1.0f);
                        if (blocked)
                            didTarget2 = false;
                    }
                }
                else if (!touchPotionSlot30 && spellFormSlot1 &&
                         reinterpret_cast<SpellView*>(spellFormSlot1)->FUN_0040e210(0x80) &&
                         effect->GetArea() > 0 && casterActorSlot25)
                {
                    bool blockedCaster = false;
                    ApplyAreaEffect(spellB, active, casterActorSlot25->FUN_008d6f30(),
                                    *casterActorSlot25->GetPosition(), target6, false, &contextSlot12, &blockedCaster,
                                    1.0f);
                    if (blockedCaster)
                        didTarget2 = false;
                }
            }
            delete active;
        }
        if (spellB->GetSpellType() == 8)
            cursorA = 0;
        else
            cursorA = static_cast<EffectList*>(cursorA->FUN_00726070());
    }
    MagicArt* artSlot15 = reinterpret_cast<MagicAccessor*>(spellB)->FUN_0040a300(false);
    EffectItem* areaEffect7 = reinterpret_cast<MagicView*>(spellB)->FindCostliestEffectItem(1, true);
    bool specialSlot29 = spellFormSlot1 && reinterpret_cast<SpellView*>(spellFormSlot1)->FUN_0040e210(0x80);
    Object* areaTarget3 =
        aTargetObject ? aTargetObject : ((casterActorSlot25 && specialSlot29) ? casterActorSlot25 : 0);
    if (areaTarget3)
    {
        NiPoint3 position;
        PositionProvider* provider3 =
            (casterActorSlot25 && !source) ? casterActorSlot25->caster.GetSourcePosition() : 0;
        position = provider3 ? *provider3->NiAVObject_GetWorldTranslate() : *areaTarget3->GetPosition();
        if (areaEffect7)
        {
            MagicCaster_DoExplosion(position, areaTarget3->FUN_008d6f30(), spellB, areaEffect7, &contextSlot12, 1.0f, 1.0f);
            if (artSlot15 && artSlot15->model.FUN_0048cee0())
            {
                NiPoint3 direction(-NiSin_005c53d0(-areaTarget3->FUN_00430830()->x),
                                NiCos(-areaTarget3->FUN_00430830()->x), 0);
                ModelInstance* instance2 =
                    BSTempEffectParticle_Spawn(areaTarget3->FUN_008d6f30(), 1.0f, artSlot15->model.GetModelFilePath(), direction,
                                 position, 1.0f, 7, 0);
                instance2->PlaySequence(DAT_0102054c);
                if (instance2->FUN_00490e40())
                {
                    float areaScale = areaEffect7->GetArea() * *DAT_011d1bbc.Setting_Float_00403e20();
                    if (areaScale > *DAT_011d1acc.Setting_Float_00403e20())
                        areaScale = *DAT_011d1acc.Setting_Float_00403e20();
                    else if (areaScale < *DAT_011d15a4.Setting_Float_00403e20())
                        areaScale = *DAT_011d15a4.Setting_Float_00403e20();
                    instance2->FUN_00490e40()->NiAVObject_SetScale(areaScale);
                }
            }
        }
        else if (areaTarget3->IsActor() && aTouchEffect && aTouchEffect->GetEffectSetting()->IsFlagSet_00403e60(0x20000000))
        {
            Actor* actor = reinterpret_cast<Actor*>(areaTarget3);
            if (CheckHealthDamageKill(static_cast<MagicTarget*>(actor), spellB))
                ApplyExplosion(actor, position, aTouchEffect, aTouchEffect->GetRawCost());
        }
    }
    contextSlot12.FUN_00470470();
    if (reinterpret_cast<MagicView*>(spellB)->HasNonDetrimentalEffect())
        CastAimEffect();
    else if (didTarget2 && casterActorSlot25 && (spellB->GetSpellType() == 0 || spellB->GetSpellType() == 5))
        casterActorSlot25->UseSkill(reinterpret_cast<MagicView*>(spellB)->EffectItemList_GetAssociatedSkill(true), 0);
    if (releaseModel && artSlot15 && artSlot15->model.FUN_0048cee0() > 0)
        DAT_011c3b3c->ModelLoader_ReleaseModel(artSlot15->model.GetModelFilePath(), false, 1);
    SetSpell(0);
    SetMagicTarget(0);
    FUN_00818af0(0, 0);
    if (potion && casterActorSlot25)
    {
        AlchemyItem* consumed = dynamic_cast<AlchemyItem*>(spellB);
        if (consumed)
            casterActorSlot25->target.ApplyAddiction(consumed);
    }
}
}

#include <xmmintrin.h>
class GameSettingCollection;
namespace fnv_00818150 {
#include <xmmintrin.h>

struct MassVec;

hkVector4& NI2HK(hkVector4& out, const NiPoint3& in);
struct RefNode;
void GetRefPosition(NiPoint3* out, RefNode* node);

struct PushRef
{
    float GetMass();
    void Activate();
    void ApplyImpulse(hkVector4& v);
    RefNode* GetNode();
};

struct MassVec
{
    __m128 v;
    MassVec(float f);
};


extern Setting originalRuntimeFloatSetting1112;
extern Setting originalRuntimeFloatSetting1131;
extern Setting originalRuntimeFloatSetting1136;
extern const double _gModifierZero;

float CalcForce(int a, int b, float dist, int c, int d, float e);

struct Pusher
{
    void MagicCaster_ExplodeRigidBody(PushRef* target, NiPoint3 origin, EffectItem* effect, float magnitude);
};

// Computes a force on target from origin and effect, clamps and scales it, then applies the resulting impulse to the target.
// @fnv 0x00818150
// src: XBOX_PDB 0x00818150
void Pusher::MagicCaster_ExplodeRigidBody(PushRef* target, NiPoint3 origin, EffectItem* effect, float magnitude)
{
    NiPoint3 pos;
    GetRefPosition(&pos, target->GetNode());
    NiPoint3 vDirection = pos - origin;
    float dist = vDirection.FUN_00457910();
    float force = CalcForce((int)magnitude, (int)((double)effect->GetArea() * *originalRuntimeFloatSetting1112.Float()),
                            dist, 0, 0, 0.0f);
    if (force > _gModifierZero)
    {
        if (force > *originalRuntimeFloatSetting1131.Float())
            force = *originalRuntimeFloatSetting1131.Float();
        force = force * *originalRuntimeFloatSetting1136.Float();
        vDirection[2u] += 0.5;
        NiPoint3 vImpulse = vDirection * force;
        hkVector4 v;
        NI2HK(v, vImpulse);
        MassVec m(target->GetMass());
        v.Mul(reinterpret_cast<const ::MassVec&>(m));
        target->Activate();
        target->ApplyImpulse(v);
    }
}
}  // namespace fnv_00818150

