// fallout/magic/valuemodifiereffect.cpp: ValueModifierEffect, ActorValue, LocalEffect, Cls (16 functions)

#include "../../../include/ActorValue.h"
namespace ActorValue {
bool IsSkill(Index);
bool IsDerivedAttribute(Index);
}
bool ActorValue_IsAttribute(ActorValue::Index);

#include "../../../include/ActiveEffect.h"
#include "../../../include/ValueModifierEffect.h"
#include "../../../include/ActorValueOwner.h"
#include "../../../include/EffectSetting.h"
#include "../../../include/HighProcess.h"
#include "../../../include/PlayerCharacter.h"
#include "../../../include/SettingT_GameSettingCollection_.h"
#include "../../../include/AlchemyItem.h"
#include "../../../include/LimbConditionEffect.h"
#include "../../../include/MagicItem.h"
#include "../../../include/BGSMessageIcon.h"
#include "../../../include/BaseFormComponent.h"
#include "../../../include/TESFullName.h"
#include "../../../include/TESIcon.h"
#include "../../../include/TESTexture.h"
#include "../../../include/BSThread.h"
#include "../../../include/NiQuatTransform.h"
#include "../../../include/TESObjectREFR.h"
#include "../../../include/TESScriptableForm.h"
#include "../../../include/TESWeightForm.h"
#include "../../../include/ActorMover.h"
#include "../../../include/EffectItem.h"
#include "../../../include/TESSaveLoadGame.h"

extern PlayerCharacter* g_thePlayer;
#include "../../../include/InventoryStackRecord.h"
class MagicItemComponent
{
  public:
    virtual void vfn_0();
    virtual bool HasFoodEffect();
};
int __cdecl Warning(const char*, ...);
extern SettingT_GameSettingCollection_ g_011d21a8, g_011d4a5c, g_011d2ce8;
namespace ActorValue {
const char* GetActorValueName(Index);
}
// Exe 0x0082bbe0: unit-local Interface view; declarations and layout are preserved.
class ValuemodifiereffectInterfaceView
{
  public:
    static bool ShowMessage(const char*, int, const char*, const char*, float, bool);
};
extern "C" int __cdecl sprintf(char*, const char*, ...);

class TaskQueueInterface
{
  public:
    static TaskQueueInterface* GetSingleton();
};
void __cdecl TaskQueueInterface_QueueScriptFunctionCall(TaskQueueInterface*, int, Actor*, ...);

// Getter bodies are shared by the original linker. The receiver overlays below
// preserve canonical symbol bindings: +0x24 target, +0x28 caster, +0x0c source.
void* __cdecl operator new(unsigned int);


// @fnv 0x0082bbe0
void ValueModifierEffect::CopyData(ActiveEffect* other)
{
    ActiveEffect::CopyData(other);
    ValueModifierEffect* modifier = dynamic_cast<ValueModifierEffect*>(other);
    if (modifier)
        modifier->m_eActorValue = m_eActorValue;
}

// Returns true if the target resolves to an actor that has no health, otherwise false.
// @fnv 0x0082bcb0
bool ValueModifierEffect::IsEffectValid(MagicTarget* target)
{
    Actor* actor = target ? target->GetOwnerActor() : 0;
    return actor && !actor->HasHealth(false);
}

// Allocates a new ValueModifierEffect from the current effect's data, copies state into it via CopyFrom, and returns the copy.
// @fnv 0x0082bb30
ActiveEffect* ValueModifierEffect::Copy()
{
    ActiveEffect* copy = new ValueModifierEffect(m_pEffectInstance, pSpell, pEffect);
    CopyData(copy);
    return copy;
}

// @fnv 0x0082bd20
void ValueModifierEffect::Finalize()
{
    Actor* actor = ((ActorMover*)this)->GetCurrentMoveModeType()
                       ? ((MagicTarget*)((ActorMover*)this)->GetCurrentMoveModeType())->GetOwnerActor()
                       : 0;
    if (pEffect->GetEffectSetting()->IsDetrimentalToActorValue(GetActorValue()))
    {
        m_fElapsedTime = -m_fElapsedTime;
        if (actor && GetActorValue() == 16 &&
            ((ActiveEffect*)this)->GetHavokWorldObjectCountInSceneGraph_0084e3a0()->GetRange())
        {
            Actor* caster = ((HighProcess*)this)->GetProcessLevel()
                                ? ((MagicCaster*)((HighProcess*)this)->GetProcessLevel())->GetCasterActor()
                                : 0;
            m_fElapsedTime = actor->AdjustEffectElapsedTime(m_fElapsedTime, caster);
        }
    }
    ActiveEffect::Finalize();
}

// @fnv 0x0082ce70
float ValueModifierEffect::GetModifiedMagnitude(float magnitude)
{
    float adjusted = magnitude;
    if (HasConditions())
        return adjusted;
    if ((ActorValue_IsAttribute(GetActorValue()) || ActorValue::IsDerivedAttribute(GetActorValue()) ||
         ActorValue::IsSkill(GetActorValue())) &&
        magnitude <= 0.0)
    {
        Actor* actor = ((ActorMover*)this)->GetCurrentMoveModeType()
                           ? ((MagicTarget*)((ActorMover*)this)->GetCurrentMoveModeType())->GetOwnerActor()
                           : 0;
        float result = actor->GetCurrentActorValue(GetActorValue()) + adjusted;
        if (result < 0.0)
            adjusted = -result + adjusted;
    }
    return adjusted;
}

// @fnv 0x0082c660
void ValueModifierEffect::Update(float delta)
{
    if (!pEffect->GetEffectSetting()->IsFlagSet(2))
    {
        Actor* actor = ((ActorMover*)this)->GetCurrentMoveModeType()
                           ? ((MagicTarget*)((ActorMover*)this)->GetCurrentMoveModeType())->GetOwnerActor()
                           : 0;
        if (IsFlagged() || fDuration > 0.0 || m_eSpellType == 4 || m_eSpellType == 1)
        {
            ApplyActorValueModifier(actor, m_fElapsedTime * delta, ActorValue::ActorValue__Index_VALUE_NONE);
            if (m_eActorValue == 16 && actor == (Actor*)g_thePlayer)
            {
                MagicItem* object = (MagicItem*)((InventoryStackRecord*)this)->GetObject();
                if (object && ((MagicItemComponent*)((char*)object + 0xc))->HasFoodEffect())
                    Warning("Using a food?");
                else if (object->GetSpellType() == 7)
                    Warning("Using a stimpak?\n");
            }
            if (m_eActorValue == 7 && m_fElapsedTime < 0.0 &&
                actor->GetCurrentActorValue((ActorValue::Index)16) <= 1.0)
            {
                Actor* caster = ((HighProcess*)this)->GetProcessLevel()
                                    ? ((MagicCaster*)((HighProcess*)this)->GetProcessLevel())->GetCasterActor()
                                    : 0;
                actor->Kill(caster, 0.0f);
            }
        }
    }
}

// @fnv 0x0082be10
void ValueModifierEffect::RefreshPlayerActorValue()
{
    if ((MagicTarget*)((ActorMover*)this)->GetCurrentMoveModeType() ==
            (g_thePlayer ? (MagicTarget*)((char*)g_thePlayer + (sizeof(MobileObject) + sizeof(MagicCaster))) : 0) &&
        (ActorValue_IsAttribute((ActorValue::Index)pEffect->GetAffectedActorValue()) ||
         ActorValue::IsSkill((ActorValue::Index)pEffect->GetAffectedActorValue())) &&
        pEffect->IsHostile())
    {
        if (((MagicItem*)((InventoryStackRecord*)this)->GetObject())->GetSpellType() != 4 &&
            pEffect->GetEffectSetting()->IsFlagSet(4))
        {
            bool continuous = pEffect->GetEffectSetting()->IsFlagSet(2) || IsFlagged();
            char buffer[200];
            sprintf(buffer, "%s %s %s", g_011d2ce8.String(),
                    ActorValue::GetActorValueName((ActorValue::Index)pEffect->GetAffectedActorValue()),
                    continuous ? g_011d21a8.String()
                               : g_011d4a5c.String());
            ValuemodifiereffectInterfaceView::ShowMessage(buffer, 0, 0, 0, 2.0f, false);
        }
    }
}

// @fnv 0x0082ca50
void ValueModifierEffect::ApplyActorValueModifier(Actor* actor, float magnitude, ActorValue::Index requested)
{
    if (!actor)
        return;
    ActorValue::Index value = requested == ActorValue::ActorValue__Index_VALUE_NONE ? (ActorValue::Index)m_eActorValue : requested;
    if (value == ActorValue::ActorValue__Index_VALUE_NONE)
    {
        if (magnitude != 0.0)
            Warning("ValueModifierEffect tried to modify an actor value without specifying which actor value to");
        return;
    }
    bool ability = m_eSpellType == 4 && !HasConditions();
    if (actor->IsPlayerRef() && ability && pEffect->GetEffectSetting()->IsFlagSet(2))
        actor->ForceActorValue(value, magnitude, 0);
    else
    {
        Actor* caster = ((HighProcess*)this)->GetProcessLevel()
                            ? ((MagicCaster*)((HighProcess*)this)->GetProcessLevel())->GetCasterActor()
                            : 0;
        if (!((ActiveEffect*)this)->GetHavokWorldObjectCountInSceneGraph_0084e3a0()->GetRange() ||
            !((ActiveEffect*)this)->GetHavokWorldObjectCountInSceneGraph_0084e3a0()->IsHostile())
            caster = 0;
        if (pEffect->GetEffectSetting()->IsFlagSet(2))
            actor->ModActorValue(value, magnitude, caster);
        else
        {
            if (caster && magnitude < 0.0 && value == 16 && caster->IsPlayerRef() && actor != caster &&
                actor->GetProcess() && !actor->IsEssentialActor())
                actor->GetProcess()->ApplyDamageToActor(g_thePlayer, -magnitude);
            actor->DamageActorValue(value, magnitude, caster);
            if (magnitude < 0.0 && value == 16)
                TaskQueueInterface_QueueScriptFunctionCall(TaskQueueInterface::GetSingleton(), 0x116c, actor, -magnitude);
        }
    }
}

// Allocates and constructs a ValueModifierEffect from the three given arguments and returns it.
// @fnv 0x0082bc30
// src: XBOX_PDB 0x0082bc30
ValueModifierEffect* __cdecl ValueModifierEffect_Instantiate(void* p1, void* p2, void* p3)
{
    return new ValueModifierEffect(p1, p2, p3);
}

// Constructs a ValueModifierEffect by forwarding the three arguments to the base class constructor.
// @fnv 0x0080a900
LimbConditionEffect::LimbConditionEffect(void* apArg1, void* apArg2, void* apArg3) : ValueModifierEffect(apArg1, apArg2, apArg3)
{}

struct FUN_0082ccb0_Cls : ActiveEffect
{
    EffectSetting* GetEffectSetting();
    bool ValueModifierEffect_IsCausingDamage();
};
// @fnv 0x0082ccb0
// src: XBOX_PDB 0x0082ccb0
bool FUN_0082ccb0_Cls::ValueModifierEffect_IsCausingDamage()
{
    return *(int*)((char*)this + 0x48) == 16 && GetEffectSetting()->IsFlagSet(4) && !GetEffectSetting()->IsFlagSet(2);
}

extern int DAT_0107c68c;

struct FUN_0080bc70_base
{
    ~FUN_0080bc70_base();
    FUN_0080bc70_base(MagicCaster*, MagicItem*, EffectItem*);
};



struct FUN_0082ba60 : public FUN_0080bc70_base
{
    FUN_0082ba60(MagicCaster* apCaster, MagicItem* apSpell, EffectItem* apEffect);
};

// Initializes the base with caster, spell and effect, stores a value derived from the effect setting or effect, and sets a float to 1.0 when flag 0x100 is set.
// @fnv 0x0082ba60
FUN_0082ba60::FUN_0082ba60(MagicCaster* apCaster, MagicItem* apSpell, EffectItem* apEffect)
    : FUN_0080bc70_base(apCaster, apSpell, apEffect)
{
    *(void**)this = &DAT_0107c68c;
    EffectSetting* psetting = apEffect->GetEffectSetting();
    if (psetting->HasAssociatedActorValue())
        *(int*)((char*)this + 0x48) = psetting->GetAssociatedActorValue();
    else
        *(int*)((char*)this + 0x48) = apEffect->GetAffectedActorValue();

    if (apEffect->GetEffectSetting()->IsFlagSet(0x100))
        *(float*)((char*)this + 0x1c) = 1.0f;
}

// The shared Actor slot 0x3B4 has no setter signature yet. Call that slot
// directly so loading preserves the original arguments and virtual dispatch.
typedef void (__thiscall* SetLoadedActorValue)(Actor*, ActorValue::Index, float);

struct ParentCellStub
{
    Actor* GetActorRef();
};

struct CasterStub
{
    Actor* GetActorRef();
};

extern TESSaveLoadGame* g_TESSaveLoadGame;

struct LoadedValueEffect : ValueModifierEffect
{
    void Restart(Actor* apActor);
    ParentCellStub* GetParentCell();
    CasterStub* GetCaster();
    float GetMagnitude();
    void ValueModifierEffect_FinishInitLoadGame(Actor* apActor);
};

// Restarts the effect on the actor, then for save versions 0x5f-0x61 re-applies the magnitude to the player target via SetActorValueF and ModActorValue.
// @fnv 0x0082cd10
// src: XBOX_PDB 0x0082cd10
void LoadedValueEffect::ValueModifierEffect_FinishInitLoadGame(Actor* apActor)
{
    Restart(apActor);
    if (g_TESSaveLoadGame->GetCurrentVersion() >= 0x5f && g_TESSaveLoadGame->GetCurrentVersion() < 0x62)
    {
        Actor* pTarget = GetParentCell() ? GetParentCell()->GetActorRef() : 0;
        if (pTarget && pTarget->IsPlayerRef() && IsFlagged() &&
            pEffect->GetEffectSetting()->IsFlagSet(2))
        {
            Actor* pCasterActor = GetCaster() ? GetCaster()->GetActorRef() : 0;
            (*(SetLoadedActorValue**)pTarget)[0x3b4 / sizeof(void*)](pTarget, GetActorValue(), -GetMagnitude());
            pTarget->ModActorValue(GetActorValue(), GetMagnitude(), pCasterActor);
        }
    }
}

struct TargetGetter
{
    Actor* FUN_00822b40();
};
float __cdecl BSMIN(float, float);
void __cdecl FUN_004d5e10(int, int);
struct LocalEffect
{
    int unk00;
    int unk04;
    int unk08;
    EffectItem* effect;
    int unk10;
    int unk14;
    int unk18;
    float magnitude;
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
    int which;
    TargetGetter* FUN_0059bb30();
    MagicItem* FUN_0044ddc0();
    void ValueModifierEffect_Continue();
};
// @fnv 0x0082c490
// src: XBOX_PDB 0x0082c490
void LocalEffect::ValueModifierEffect_Continue()
{
    Actor* target = FUN_0059bb30() ? FUN_0059bb30()->FUN_00822b40() : 0;
    if (target == (Actor*)g_thePlayer && effect && effect->GetDuration() > 0 && which == 16)
    {
        float missing = g_thePlayer->GetPermanentActorValueAdjustment((ActorValue::Index)16) -
                        g_thePlayer->GetCurrentActorValue((ActorValue::Index)16);
        MagicItem* pMagicItem = FUN_0044ddc0();
        bool potion = pMagicItem->GetSpellType() == 7;
        AlchemyItem* item = potion ? dynamic_cast<AlchemyItem*>(pMagicItem) : 0;
        if (item && item->AlchemyItem_IsFlagSet(2))
        {
            FUN_004d5e10(18, (int)BSMIN(magnitude * effect->GetDuration(), missing));
        }
        if (item && item->AlchemyItem_IsFlagSet(4))
        {
            FUN_004d5e10(16, (int)BSMIN(magnitude * effect->GetDuration(), missing));
        }
    }
}

struct Obj822b40
{
    Actor* FUN_00822b40();
};
extern "C" double gModifierZero;
struct Cls
{
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
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
    virtual ActorValue::Index GetActorValue();
    virtual void ApplyActorValueModifier(Actor*, float, ActorValue::Index);
    unsigned char field04[4];
    void* field08;
    EffectItem* pEffect;
    unsigned char field10[12];
    float m_fElapsedTime;
    float fDuration;
    void* pTarget;
    void* m_pEffectInstance;
    int m_eSpellType;
    unsigned char field30[24];
    int m_eActorValue;
    float FUN_0082ce70(float);
    void ApplyEffect();
};

// @fnv 0x0082c810
void Cls::ApplyEffect()
{
    Actor* pActor =
        ((BSThread*)this)->GetThreadID() ? ((Obj822b40*)((BSThread*)this)->GetThreadID())->FUN_00822b40() : 0;
    if (pEffect->GetEffectSetting()->IsFlagSet(2))
    {
        if (pActor != 0 && m_fElapsedTime > gModifierZero)
        {
            float fValue = FUN_0082ce70(-m_fElapsedTime) + m_fElapsedTime;
            if (GetActorValue() == 0x10)
            {
                if (((TESObjectREFR*)pActor)->GetHealth() + fValue <= 1.0 + m_fElapsedTime)
                    fValue += 1.0;
            }
            if (fValue != gModifierZero)
            {
                pActor->DamageActorValue((ActorValue::Index)m_eActorValue, fValue,
                                         ((HighProcess*)this)->GetProcessLevel()
                                             ? ((MagicCaster*)((HighProcess*)this)->GetProcessLevel())->GetCasterActor()
                                             : 0);
            }
        }
        ApplyActorValueModifier(pActor, -m_fElapsedTime, (ActorValue::Index)-1);
        if (pActor != 0 && pActor->HasHealth(0) && (m_eActorValue == 0x10 || m_eActorValue == 7))
        {
            float fTemp = (float)pActor->GetActorValue((ActorValue::Index)0x10);
            if (fTemp > gModifierZero)
                pActor->DamageActorValue((ActorValue::Index)0x10, -fTemp, 0);
        }
    }
    if (m_eActorValue == 0x36)
    {
        if (pEffect->GetEffectSetting()->IsFlagSet(4))
        {
            if (pActor != 0 && pActor->GetProcess() != 0)
            {
                pActor->GetProcess()->SetMovementTimer(((NiQuatTransform*)this)->GetFloatAtOffset1C());
            }
            if (pActor == (Actor*)g_thePlayer)
                g_thePlayer->UpdateRadiationEffects();
        }
    }
}

typedef char _sizecheck_LimbConditionEffect[sizeof(LimbConditionEffect) == 80 ? 1 : -1];
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
typedef char _sizecheck_TESFullName[sizeof(TESFullName) == 12 ? 1 : -1];
typedef char _sizecheck_TESTexture[sizeof(TESTexture) == 12 ? 1 : -1];
typedef char _sizecheck_TESIcon[sizeof(TESIcon) == 12 ? 1 : -1];
typedef char _sizecheck_BGSMessageIcon[sizeof(BGSMessageIcon) == 16 ? 1 : -1];
typedef char _sizecheck_TESScriptableForm[sizeof(TESScriptableForm) == 12 ? 1 : -1];
typedef char _sizecheck_TESWeightForm[sizeof(TESWeightForm) == 8 ? 1 : -1];
struct FUN_0082c000_shell : public ValueModifierEffect
{
    void ValueModifierEffect_Start();
};

struct BGSMessageInitAccess
{
    unsigned int GetIconFormID();
};





struct ProcessRads
{
    virtual void vfn_000();
    virtual void vfn_004();
    virtual void vfn_008();
    virtual void vfn_00c();
    virtual void vfn_010();
    virtual void vfn_014();
    virtual void vfn_018();
    virtual void vfn_01c();
    virtual void vfn_020();
    virtual void vfn_024();
    virtual void vfn_028();
    virtual void vfn_02c();
    virtual void vfn_030();
    virtual void vfn_034();
    virtual void vfn_038();
    virtual void vfn_03c();
    virtual void vfn_040();
    virtual void vfn_044();
    virtual void vfn_048();
    virtual void vfn_04c();
    virtual void vfn_050();
    virtual void vfn_054();
    virtual void vfn_058();
    virtual void vfn_05c();
    virtual void vfn_060();
    virtual void vfn_064();
    virtual void vfn_068();
    virtual void vfn_06c();
    virtual void vfn_070();
    virtual void vfn_074();
    virtual void vfn_078();
    virtual void vfn_07c();
    virtual void vfn_080();
    virtual void vfn_084();
    virtual void vfn_088();
    virtual void vfn_08c();
    virtual void vfn_090();
    virtual void vfn_094();
    virtual void vfn_098();
    virtual void vfn_09c();
    virtual void vfn_0a0();
    virtual void vfn_0a4();
    virtual void vfn_0a8();
    virtual void vfn_0ac();
    virtual void vfn_0b0();
    virtual void vfn_0b4();
    virtual void vfn_0b8();
    virtual void vfn_0bc();
    virtual void vfn_0c0();
    virtual void vfn_0c4();
    virtual void vfn_0c8();
    virtual void vfn_0cc();
    virtual void vfn_0d0();
    virtual void vfn_0d4();
    virtual void vfn_0d8();
    virtual void vfn_0dc();
    virtual void vfn_0e0();
    virtual void vfn_0e4();
    virtual void vfn_0e8();
    virtual void vfn_0ec();
    virtual void vfn_0f0();
    virtual void vfn_0f4();
    virtual void vfn_0f8();
    virtual void vfn_0fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual void vfn_1a0();
    virtual void vfn_1a4();
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc();
    virtual void vfn_1d0();
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual void vfn_1e4();
    virtual void vfn_1e8();
    virtual void vfn_1ec();
    virtual void vfn_1f0();
    virtual void vfn_1f4();
    virtual void vfn_1f8();
    virtual void vfn_1fc();
    virtual void vfn_200();
    virtual void vfn_204();
    virtual void vfn_208();
    virtual void vfn_20c();
    virtual void vfn_210();
    virtual void vfn_214();
    virtual void vfn_218();
    virtual void vfn_21c();
    virtual void vfn_220();
    virtual void vfn_224();
    virtual void vfn_228();
    virtual void vfn_22c();
    virtual void vfn_230();
    virtual void vfn_234();
    virtual void vfn_238();
    virtual void vfn_23c();
    virtual void vfn_240();
    virtual void vfn_244();
    virtual void vfn_248();
    virtual void vfn_24c();
    virtual void vfn_250();
    virtual void vfn_254();
    virtual void vfn_258();
    virtual void vfn_25c();
    virtual void vfn_260();
    virtual void vfn_264();
    virtual void vfn_268();
    virtual void vfn_26c();
    virtual void vfn_270();
    virtual void vfn_274();
    virtual void vfn_278();
    virtual void vfn_27c();
    virtual void vfn_280();
    virtual void vfn_284();
    virtual void vfn_288();
    virtual void vfn_28c();
    virtual void vfn_290();
    virtual void vfn_294();
    virtual void vfn_298();
    virtual void vfn_29c();
    virtual void vfn_2a0();
    virtual void vfn_2a4();
    virtual void vfn_2a8();
    virtual void vfn_2ac();
    virtual void vfn_2b0();
    virtual void vfn_2b4();
    virtual void vfn_2b8();
    virtual void vfn_2bc();
    virtual void vfn_2c0();
    virtual void vfn_2c4();
    virtual void vfn_2c8();
    virtual void vfn_2cc();
    virtual void vfn_2d0();
    virtual void vfn_2d4();
    virtual void vfn_2d8();
    virtual void vfn_2dc();
    virtual void vfn_2e0();
    virtual void vfn_2e4();
    virtual void vfn_2e8();
    virtual void vfn_2ec();
    virtual void vfn_2f0();
    virtual void vfn_2f4();
    virtual void vfn_2f8();
    virtual void vfn_2fc();
    virtual void vfn_300();
    virtual void vfn_304();
    virtual void vfn_308();
    virtual void vfn_30c();
    virtual void vfn_310();
    virtual void vfn_314();
    virtual void vfn_318();
    virtual void vfn_31c();
    virtual void vfn_320();
    virtual void vfn_324();
    virtual void vfn_328();
    virtual void vfn_32c();
    virtual void vfn_330();
    virtual void vfn_334();
    virtual void vfn_338();
    virtual void vfn_33c();
    virtual void vfn_340();
    virtual void vfn_344();
    virtual void vfn_348();
    virtual void vfn_34c();
    virtual void vfn_350();
    virtual void vfn_354();
    virtual void vfn_358();
    virtual void vfn_35c();
    virtual void vfn_360();
    virtual void vfn_364();
    virtual void vfn_368();
    virtual void vfn_36c();
    virtual void vfn_370();
    virtual void vfn_374();
    virtual void vfn_378();
    virtual void vfn_37c();
    virtual void vfn_380();
    virtual void vfn_384();
    virtual void vfn_388();
    virtual void vfn_38c();
    virtual void vfn_390();
    virtual void vfn_394();
    virtual void vfn_398();
    virtual void vfn_39c();
    virtual void vfn_3a0();
    virtual void vfn_3a4();
    virtual void vfn_3a8();
    virtual void vfn_3ac();
    virtual void vfn_3b0();
    virtual void vfn_3b4();
    virtual void vfn_3b8();
    virtual void vfn_3bc();
    virtual void vfn_3c0();
    virtual void vfn_3c4();
    virtual void vfn_3c8();
    virtual void vfn_3cc();
    virtual void vfn_3d0();
    virtual void vfn_3d4();
    virtual void vfn_3d8();
    virtual void vfn_3dc();
    virtual void vfn_3e0();
    virtual void vfn_3e4();
    virtual void vfn_3e8();
    virtual void vfn_3ec();
    virtual void vfn_3f0();
    virtual void vfn_3f4();
    virtual void vfn_3f8();
    virtual void vfn_3fc();
    virtual void vfn_400();
    virtual void vfn_404();
    virtual void vfn_408();
    virtual void vfn_40c();
    virtual void vfn_410();
    virtual void vfn_414();
    virtual void vfn_418();
    virtual void vfn_41c();
    virtual void vfn_420();
    virtual void vfn_424();
    virtual void vfn_428();
    virtual void vfn_42c();
    virtual void vfn_430();
    virtual void vfn_434();
    virtual void vfn_438();
    virtual void vfn_43c();
    virtual void vfn_440();
    virtual void vfn_444();
    virtual void vfn_448();
    virtual void vfn_44c();
    virtual void vfn_450();
    virtual void vfn_454();
    virtual void vfn_458();
    virtual void vfn_45c();
    virtual void vfn_460();
    virtual void vfn_464();
    virtual void vfn_468();
    virtual void vfn_46c();
    virtual void vfn_470();
    virtual void vfn_474();
    virtual void vfn_478();
    virtual void vfn_47c();
    virtual void vfn_480();
    virtual void vfn_484();
    virtual void vfn_488();
    virtual void vfn_48c();
    virtual void vfn_490();
    virtual void vfn_494();
    virtual void vfn_498();
    virtual void vfn_49c();
    virtual void vfn_4a0();
    virtual void vfn_4a4();
    virtual void vfn_4a8();
    virtual void vfn_4ac();
    virtual void vfn_4b0();
    virtual void vfn_4b4();
    virtual void vfn_4b8();
    virtual void vfn_4bc();
    virtual void vfn_4c0();
    virtual void vfn_4c4();
    virtual void vfn_4c8();
    virtual void vfn_4cc();
    virtual void vfn_4d0();
    virtual void vfn_4d4();
    virtual void vfn_4d8();
    virtual void vfn_4dc();
    virtual void vfn_4e0();
    virtual void vfn_4e4();
    virtual void vfn_4e8();
    virtual void vfn_4ec();
    virtual void vfn_4f0();
    virtual void vfn_4f4();
    virtual void vfn_4f8();
    virtual void vfn_4fc();
    virtual void vfn_500();
    virtual void vfn_504();
    virtual void vfn_508();
    virtual void vfn_50c();
    virtual void vfn_510();
    virtual void vfn_514();
    virtual void vfn_518();
    virtual void vfn_51c();
    virtual void vfn_520();
    virtual void vfn_524();
    virtual void vfn_528();
    virtual void vfn_52c();
    virtual void vfn_530();
    virtual void vfn_534();
    virtual void vfn_538();
    virtual void vfn_53c();
    virtual void vfn_540();
    virtual void vfn_544();
    virtual void vfn_548();
    virtual void vfn_54c();
    virtual void vfn_550();
    virtual void vfn_554();
    virtual void vfn_558();
    virtual void vfn_55c();
    virtual void vfn_560();
    virtual void vfn_564();
    virtual void vfn_568();
    virtual void vfn_56c();
    virtual void vfn_570();
    virtual void vfn_574();
    virtual void vfn_578();
    virtual void vfn_57c();
    virtual void vfn_580();
    virtual void vfn_584();
    virtual void vfn_588();
    virtual void vfn_58c();
    virtual void vfn_590();
    virtual void vfn_594();
    virtual void vfn_598();
    virtual void vfn_59c();
    virtual void vfn_5a0();
    virtual void vfn_5a4();
    virtual void vfn_5a8();
    virtual void vfn_5ac();
    virtual void vfn_5b0();
    virtual void vfn_5b4();
    virtual void vfn_5b8();
    virtual void vfn_5bc();
    virtual void vfn_5c0();
    virtual void vfn_5c4();
    virtual void vfn_5c8();
    virtual void vfn_5cc();
    virtual void vfn_5d0();
    virtual void vfn_5d4();
    virtual void vfn_5d8();
    virtual void vfn_5dc();
    virtual void vfn_5e0();
    virtual void vfn_5e4();
    virtual void vfn_5e8();
    virtual void vfn_5ec();
    virtual void vfn_5f0();
    virtual void vfn_5f4();
    virtual void vfn_5f8();
    virtual void vfn_5fc();
    virtual void vfn_600();
    virtual void vfn_604();
    virtual void vfn_608();
    virtual void vfn_60c();
    virtual void vfn_610();
    virtual void vfn_614();
    virtual void vfn_618();
    virtual void vfn_61c();
    virtual void vfn_620();
    virtual void vfn_624();
    virtual void vfn_628();
    virtual void vfn_62c();
    virtual void vfn_630();
    virtual void vfn_634();
    virtual void vfn_638();
    virtual void vfn_63c();
    virtual void vfn_640();
    virtual void vfn_644();
    virtual void vfn_648();
    virtual void vfn_64c();
    virtual void vfn_650();
    virtual void vfn_654();
    virtual void vfn_658();
    virtual void vfn_65c();
    virtual void vfn_660();
    virtual void vfn_664();
    virtual void vfn_668();
    virtual void vfn_66c();
    virtual void vfn_670();
    virtual void vfn_674();
    virtual void vfn_678();
    virtual void vfn_67c();
    virtual void vfn_680();
    virtual void vfn_684();
    virtual void vfn_688();
    virtual void vfn_68c();
    virtual void vfn_690();
    virtual void vfn_694();
    virtual void vfn_698();
    virtual void vfn_69c();
    virtual void vfn_6a0();
    virtual void vfn_6a4();
    virtual void vfn_6a8();
    virtual void vfn_6ac();
    virtual void vfn_6b0();
    virtual void vfn_6b4();
    virtual void vfn_6b8();
    virtual void vfn_6bc();
    virtual void vfn_6c0();
    virtual void vfn_6c4();
    virtual void vfn_6c8();
    virtual void vfn_6cc();
    virtual void vfn_6d0();
    virtual void vfn_6d4();
    virtual void vfn_6d8();
    virtual void vfn_6dc();
    virtual void vfn_6e0();
    virtual void vfn_6e4();
    virtual void vfn_6e8();
    virtual void vfn_6ec();
    virtual void vfn_6f0();
    virtual void vfn_6f4();
    virtual void vfn_6f8();
    virtual void vfn_6fc();
    virtual void vfn_700();
    virtual void vfn_704();
    virtual void vfn_708();
    virtual void vfn_70c();
    virtual void vfn_710();
    virtual void vfn_714();
    virtual void vfn_718();
    virtual void vfn_71c();
    virtual void vfn_720();
    virtual void vfn_724();
    virtual void vfn_728();
    virtual void vfn_72c();
    virtual void vfn_730();
    virtual void vfn_734();
    virtual void vfn_738();
    virtual void vfn_73c();
    virtual void vfn_740();
    virtual void vfn_744();
    virtual void vfn_748();
    virtual void vfn_74c();
    virtual void vfn_750();
    virtual void SetRadsSec(float);
};

#include "../../../include/MiscStatManager.h"


float BSMIN(float, float);
float __fastcall GetFloatAtOffset1C(char*);
extern double _gModifierZero;

// Updates a modifier, may add misc stats or call Kill, and may update radiation rate and player effects.
// @fnv 0x0082c000
// src: XBOX_PDB 0x0082c000
void FUN_0082c000_shell::ValueModifierEffect_Start()
{
    Actor* pActor = ((ActorMover*)this)->GetCurrentMoveModeType()
                        ? ((MagicTarget*)((ActorMover*)this)->GetCurrentMoveModeType())->GetOwnerActor()
                        : 0;

    if ((*(EffectItem**)((char*)this + 0xc))->GetEffectSetting()->IsFlagSet(2) ||
        (!(*(EffectItem**)((char*)this + 0xc))->GetDuration() && !((ActiveEffect*)this)->IsFlagged() &&
         ((BGSMessageInitAccess*)this)->GetIconFormID() != 4 && ((BGSMessageInitAccess*)this)->GetIconFormID() != 1))
    {
        *(float*)((char*)this + 0x1c) =
            ((ValueModifierEffect*)this)->GetModifiedMagnitude(*(float*)((char*)this + 0x1c));
        if (*(int*)((char*)this + 0x48) == 16 && pActor == (Actor*)g_thePlayer)
        {
            float fPlayerHealthDiff =
                g_thePlayer->GetPermanentActorValueAdjustment((ActorValue::Index)16) -
                g_thePlayer->GetCurrentActorValue((ActorValue::Index)16);
            MagicItem* pMagicItem = (MagicItem*)((InventoryStackRecord*)this)->GetObject();
            bool bpotion = pMagicItem->GetSpellType() == 7;
            AlchemyItem* ppotion = bpotion ? dynamic_cast<AlchemyItem*>(pMagicItem) : 0;
            if (ppotion && ppotion->AlchemyItem_IsFlagSet(2))
                MiscStatManager::AddMiscStat((MiscStatManager::MiscStat)0x12,
                                             (int)BSMIN(*(float*)((char*)this + 0x1c), fPlayerHealthDiff));
            if (ppotion && ppotion->AlchemyItem_IsFlagSet(4))
                MiscStatManager::AddMiscStat((MiscStatManager::MiscStat)0x10,
                                             (int)BSMIN(*(float*)((char*)this + 0x1c), fPlayerHealthDiff));
        }
        if (*(int*)((char*)this + 0x48) == 7 && *(float*)((char*)this + 0x1c) < _gModifierZero &&
            pActor->GetCurrentActorValue((ActorValue::Index)16) <= 1.0)
        {
            Actor* pcasterActor = ((HighProcess*)this)->GetProcessLevel()
                                      ? ((MagicCaster*)((HighProcess*)this)->GetProcessLevel())->GetCasterActor()
                                      : 0;
            pActor->Kill(pcasterActor, 0.0f);
        }
        ((ValueModifierEffect*)this)
            ->ApplyActorValueModifier(pActor, *(float*)((char*)this + 0x1c), (ActorValue::Index)-1);
    }
    else if (pActor == (Actor*)g_thePlayer && (*(EffectItem**)((char*)this + 0xc))->GetDuration() > 0 &&
             *(int*)((char*)this + 0x48) == 16)
    {
        float fPlayerHealthDiff =
            g_thePlayer->GetPermanentActorValueAdjustment((ActorValue::Index)16) -
                g_thePlayer->GetCurrentActorValue((ActorValue::Index)16);
        MagicItem* pMagicItem = (MagicItem*)((InventoryStackRecord*)this)->GetObject();
        bool bpotion = pMagicItem->GetSpellType() == 7;
        AlchemyItem* ppotion = bpotion ? dynamic_cast<AlchemyItem*>(pMagicItem) : 0;
        if (ppotion && ppotion->AlchemyItem_IsFlagSet(2))
            MiscStatManager::AddMiscStat(
                (MiscStatManager::MiscStat)0x12,
                (int)BSMIN((*(EffectItem**)((char*)this + 0xc))->GetDuration() *
                                      *(float*)((char*)this + 0x1c),
                                  fPlayerHealthDiff));
        if (ppotion && ppotion->AlchemyItem_IsFlagSet(4))
            MiscStatManager::AddMiscStat(
                (MiscStatManager::MiscStat)0x10,
                (int)BSMIN((*(EffectItem**)((char*)this + 0xc))->GetDuration() *
                                      *(float*)((char*)this + 0x1c),
                                  fPlayerHealthDiff));
    }

    if (*(int*)((char*)this + 0x48) == 0x36 && (*(EffectItem**)((char*)this + 0xc))->GetEffectSetting()->IsFlagSet(4))
    {
        if (pActor && pActor->GetProcess())
            ((ProcessRads*)pActor->GetProcess())->SetRadsSec(::GetFloatAtOffset1C((char*)this));
        if (pActor == (Actor*)g_thePlayer)
            g_thePlayer->UpdateRadiationEffects();
    }
    ((ValueModifierEffect*)this)->RefreshPlayerActorValue();
}
