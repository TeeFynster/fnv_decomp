// fallout/magic/magictarget.cpp: MagicTarget, TESSpellList, MagicCaster, MagicSystem and more (39 functions)

#include <stddef.h>
#include "../../../include/BSStringT.h"
#include "../../../include/EffectItem.h"
#include "../../../include/TESResponse.h"

#include "../../../include/ActiveEffect.h"
#include "../../../include/MagicItem.h"
#include "../../../include/TESForm.h"
#include "../../../include/Actor.h"
#include "../../../include/ActorMover.h"
#include "../../../include/AlchemyItem.h"
// CombatNode_magictarget: local type (was include/CombatNode.h, which had no evidence of one real class); its methods are 0x00505c00 TESCombatStyle::GetPowerAttackF, 0x00505c20 TESCombatStyle::GetPowerAttackB, 0x005524b0 TESCombatStyle::GetPowerAttackChance, 0x006a9560 TESCombatStyle::GetPowerAttackL
class CombatNode_magictarget
{
public:
    unsigned int FUN_00726070();
    signed char GetByteAtOffset8C();
    bool HasCombatFlag(int);
    signed char FUN_0073cb80();
    signed char TESCombatStyle_GetPowerAttackF();
    signed char GetByteAtOffset9A();
    signed char GetByteAtOffset9B();
    signed char FUN_009e8670();
};
// EffectNode_magictarget: local type (was include/EffectNode.h, which had no evidence of one real class); its methods are 0x006815c0 ReturnThis, 0x00726070 TESHealthForm::GetHealth, 0x008256d0 BSSimpleList<Actor *>::IsEmpty

class EffectNode_magictarget
{
public:
    TESForm* form;
    EffectNode_magictarget* next;

    bool __thiscall FUN_008256d0();
    ActiveEffect** __thiscall FUN_006815c0();
    EffectNode_magictarget* __thiscall FUN_00726070();
    EffectItem** GetItem();
    EffectNode_magictarget* GetNext();
};
#include "../../../include/EnchantmentItem.h"
#include "../../../include/MagicTarget.h"
#include "../../../include/TESActorBase.h"
#include "../../../include/BGSDefaultObjectManager.h"
#include "../../../include/BGSImpactData.h"
#include "../../../include/EffectSetting.h"
#include "../../../include/ImageSpaceModifierInstanceForm.h"
#include "../../../include/IngredientItem.h"
#include "../../../include/LimbConditionEffect.h"
#include "../../../include/LowProcess.h"
#include "../../../include/PlayerCharacter.h"
#include "../../../include/Script.h"
#include "../../../include/SpellItem.h"
#include "../../../include/StartMenu.h"
#include "../../../include/TESImageSpaceModifier.h"
#include "../../../include/TESRecipe.h"
#include "../../../include/TESSoundFile.h"
#include "../../../include/TESTopicInfo.h"
#include "../../../include/ValueAndConditionsEffect.h"

// Local support declarations from magictarget_decls.h, excluding shared classes.
// The declarations stay here because that header also defines their dependencies.

class EffectSetting;
class ExtraDataList;
class TESBoundObject;
class BGSPerkEntry;
class PerkButtonEntry;
class TESIdleForm;
#include "../../../include/ActorValue.h"
#include "../../../include/ENUM_FORM_ID.h"

bool GetLimbConditionEffectInitialized();

extern PlayerCharacter* g_thePlayer;
void DebugLog(const char*, ...);
void ApplyPerkModifiers(int, Actor*, ...);
int GetStatusResult();
bool MagicSystem_CheckBoundItemEffects(EffectItem*, EffectItem*);
// Getter bodies are folded in the original executable. These expressions use
// their existing canonical bindings while retaining each receiver's layout.
#define EFFECT_ITEM(e) ((e)->GetHavokWorldObjectCountInSceneGraph_0084e3a0())
#define EFFECT_SPELL(e) ((e)->FUN_0044ddc0())
class BSFileEntry;
class LocationDescriptor
{
  public:
    BSFileEntry* SetLocRef();
};
class PlayerQuestData
{
  public:
    class Date* GetLogDate();
};

extern const StartMenu DAT_011d1fc8, DAT_011d3c04;
extern "C" int sprintf_s(char*, unsigned int, const char*, ...);
// Menu.h does not declare this message helper.
class MagicTargetMessages
{
  public:
    static bool ShowMessage(const char*, int, const char*, const char*, float, bool);
};
extern "C" int sprintf(char*, const char*, ...);
extern "C" int _mbsicmp(const unsigned char*, const unsigned char*);
class MagicTargetFormDispatch
{
  public:
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
    virtual bool GetIsReference();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
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
    virtual MagicTarget* GetMagicTarget();
};
class MagicEffectCollection;

namespace MagicSystem
{
    SpellItem* GetPipBoyLightSpell();
    extern SpellItem* ms_pPipBoyLightSpell;
}

class MagicCaster;
class TESObjectREFR;



// ActiveEffect.h lacks these two nonvirtual helpers; fastcall passes the receiver in ECX.
MagicCaster* __fastcall GetEffectCaster(ActiveEffect*);
void __fastcall SetEffectMagnitude(ActiveEffect*, float);
bool __fastcall IsEffectFlaggedForRemoval(ActiveEffect*);
// Folded getter at 0x008041a0 reads ActiveEffect::pSource (+0x30).
TESBoundObject* __fastcall GetEffectSource(ActiveEffect*);

// Returns the owning Actor when IsActor() is true, otherwise NULL.
// @fnv 0x00822b40
Actor* MagicTarget::GetOwnerActor() const
{
    return const_cast<MagicTarget*>(this)->IsActor() ? (this ? (Actor*)((char*)this - 0x94) : NULL) : NULL;
}

// Validates a spell effect against the target, applies perk modifiers, dispels or clones the effect, and inserts the new ActiveEffect into the active effect list.
// @fnv 0x00823210
bool MagicTarget::AddActiveEffect(MagicCaster* caster, MagicItem* spell, ActiveEffect* effect)
{
    // These short local names preserve MSVC9's name-dependent stack ordering.
    TESObjectREFR* i = GetMagicTargetReference();  // target reference
    if (i)
        Script::GetLocalData((TESForm*)EFFECT_ITEM(effect)->GetEffectSetting(), i->GetExtraData(), 0x2000);
    bool permanent = EFFECT_ITEM(effect)->IsScriptEffect_008231f0() ? spell->IgnoreResistance() : false;
    // Resistance scales the cloned effect unless it came from an ingredient.
    float a = spell->GetSpellType() != 4 && !permanent ? GetEffectiveness(caster, spell, effect) : 1.0f;
    if (a <= 0.0)
    {
        if (caster == (g_thePlayer ? (MagicCaster*)((char*)g_thePlayer + 0x88) : 0) &&
            this == (g_thePlayer ? (MagicTarget*)((char*)g_thePlayer + 0x94) : 0))
        {
        }
        if (GetLimbConditionEffectInitialized())
            DebugLog("Target: %s FULLY RESISTED Spell: %s Effect: %s",
                     GetMagicTargetReference() ? GetMagicTargetReference()->GetFullName() : "{NULL}",
                     ((TESSoundFile*)spell)->GetSoundFile(), EFFECT_ITEM(effect)->GetEffectName().String(), a);
        return false;
    }
    if (CanReceiveMagicEffects() && EFFECT_ITEM(effect)->IsHostile())
        return false;
    if (!effect->IsEffectValid(this))
    {
        if (GetLimbConditionEffectInitialized())
            DebugLog("Invalid Target: Target: %s Spell: %s Effect: %s",
                     GetMagicTargetReference() ? GetMagicTargetReference()->GetFullName() : "{NULL}",
                     ((TESSoundFile*)spell)->GetSoundFile(), EFFECT_ITEM(effect)->GetEffectName().String());
        return false;
    }
    EffectItem* usageMonitor = ((EffectItemList*)((char*)spell + sizeof(TESFullName)))->GetScriptEffect();
    if (EFFECT_ITEM(effect) == usageMonitor)
    {
        if (!ContainsSpell(spell, true))
        {
            BSSimpleList<ActiveEffect*>* node = GetActiveEffectList();
            bool found = false;
            while (node && !((BSSimpleList<PerkButtonEntry*>*)node)->IsEmpty() && !found)
            {
                ActiveEffect* current = (ActiveEffect*)((BSSimpleList<BGSPerkEntry*>*)node)->GetItem();
                if (current && EFFECT_ITEM(current) == usageMonitor)
                {
                    current->ActiveEffect_SetMagnitude(current->GetFloatAtOffset1C() + effect->GetFloatAtOffset1C());
                    SetEffectMagnitude(current, 0.0f);
                    found = true;
                }
                node = (BSSimpleList<ActiveEffect*>*)((BSSimpleList<BGSPerkEntry*>*)node)->GetNext();
            }
            if (found)
                return true;
        }
        else
            return false;
    }
    if (spell->GetSpellType() == 10)
    {
        Actor* actor = IsActor() ? (this ? (Actor*)((char*)this - 0x94) : 0) : 0;
        if (actor)
        {
            float duration = effect->FUN_007df1f0();
            ApplyPerkModifiers(24, actor, &duration);
            effect->BaseProcess_SetLastTimeProcessed(duration);
        }
    }
    else if (spell->GetSpellType() == 7)
    {
        AlchemyItem* potion = dynamic_cast<AlchemyItem*>(spell);
        if (potion && !EFFECT_ITEM(effect)->IsHostile())
        {
            Actor* actor = IsActor() ? (this ? (Actor*)((char*)this - 0x94) : 0) : 0;
            if (actor)
            {
                float duration = effect->FUN_007df1f0();
                ApplyPerkModifiers(25, actor, &duration);
                effect->BaseProcess_SetLastTimeProcessed(duration);
            }
        }
    }
    if (effect->GetEffectSetting()->GetArchetype() == 34)
    {
        ValueAndConditionsEffect* parts = dynamic_cast<ValueAndConditionsEffect*>(effect);
        if (parts)
            ((BGSImpactData*)parts)->SetSound1((TESSound*)GetStatusResult());
    }
    else if (effect->GetEffectSetting()->GetArchetype() == 35)
    {
        LimbConditionEffect* limb = dynamic_cast<LimbConditionEffect*>(effect);
        if (limb)
            ((BGSImpactData*)limb)->SetSound1((TESSound*)GetStatusResult());
    }
    bool e = true;   // dispel an existing matching effect
    bool c = false;  // stack its duration
    bool d = false;  // reset its elapsed time
    if (effect->IsFlagged())
    {
        e = false;
        if (effect->GetEffectSetting()->GetFlag(0x30000))
        {
            BSSimpleList<ActiveEffect*>* node = GetActiveEffectList();
            while (node && !((BSSimpleList<PerkButtonEntry*>*)node)->IsEmpty())
            {
                ActiveEffect* current = (ActiveEffect*)((BSSimpleList<BGSPerkEntry*>*)node)->GetItem();
                if (current && MagicSystem_CheckBoundItemEffects(EFFECT_ITEM(effect), EFFECT_ITEM(current)))
                {
                    Dispel(EFFECT_SPELL(current), 0, current);
                    e = false;
                }
                node = (BSSimpleList<ActiveEffect*>*)((BSSimpleList<BGSPerkEntry*>*)node)->GetNext();
            }
        }
    }
    else
    {
        switch (spell->GetSpellType())
        {
        case 5:
        case 7:
            c = effect->FUN_007df1f0() > 0.0 ? true : false;
            e = false;
            break;
        case 8:
            e = false;
            break;
        case 6: {
            SpellItem* source = spell ? (SpellItem*)((char*)spell - 0x18) : 0;
            if (source->ActiveEffect_IsExtendDuration())
            {
                e = false;
                d = true;
            }
            TESForm* f = (TESForm*)((TESTopicInfo*)effect)->GetSpeaker();
            if (f && ((const TESForm*)f)->GetFormType() == 25)
                e = false;
            break;
        }
        }
    }
    if (e)
        Dispel(spell, caster, effect);
    else if (c)
    {
        if (CanAcceptEffect(spell, caster, effect))
            return true;
    }
    else if (d)
    {
        if (CanAddEffect(spell, caster, effect))
            return true;
    }
    ActiveEffect* h = effect->Copy();  // new effect owned by the target list
    if (!h)
        return false;
    ((TESRecipe*)h)->SetSkill((int)this);
    IngredientItem* f = dynamic_cast<IngredientItem*>(spell);  // ingredient source
    if (!f)
        h->SetEffectiveness(a);
    if (GetActiveEffectList())
    {
        GetActiveEffectList()->Insert(h, CompareActiveEffects);
        OnEffectStarted(h);
        h->Finalize();
        if (GetLimbConditionEffectInitialized())
            DebugLog("Effect %s from spell %s added to %s. Mag: %.2f/%d Dur: %.2f/%d",
                     EFFECT_ITEM(h)->GetEffectName().String(), ((TESSoundFile*)spell)->GetSoundFile(),
                     i ? i->GetFullName() : "{NULL}", h->GetFloatAtOffset1C(), EFFECT_ITEM(h)->GetMagnitude(),
                     h->FUN_007df1f0(), EFFECT_ITEM(h)->GetDuration());
        return true;
    }
    else
    {
        delete h;
        return false;
    }
}

// Iterates the active effect list, updating each effect and removing finished ones, with wear-off messages for the player.
// @fnv 0x00823c40
void MagicTarget::UpdateActiveEffects(float delta)
{
    BSSimpleList<ActiveEffect*>* list = GetActiveEffectList();
    BSSimpleList<ActiveEffect*>* node = list;
    if (IsActor())
    {
        TESObjectREFR* target = GetMagicTargetReference();
        Actor* actor = this ? (Actor*)((char*)this - 0x94) : 0;
        if (!actor)
            return;
        if (!((PlayerQuestData*)actor)->GetLogDate())
            return;
    }
    m_bSecondFlag = true;
    while (node && !((BSSimpleList<PerkButtonEntry*>*)node)->IsEmpty())
    {
        BSSimpleList<ActiveEffect*>* nextNode =
            (BSSimpleList<ActiveEffect*>*)((BSSimpleList<BGSPerkEntry*>*)node)->GetNext();
        ActiveEffect* pEffect = (ActiveEffect*)((BSSimpleList<BGSPerkEntry*>*)node)->GetItem();
        if (pEffect)
        {
            bool done = IsEffectFlaggedForRemoval(pEffect);
            bool bShouldUpdate = !done;
            if (bShouldUpdate && TESSpellList::RemoveSpell(((LocationDescriptor*)pEffect)->SetLocRef()) &&
                pEffect->GetEffectSetting()->IsFlagSet_00403e60(2) && pEffect->GetByteAtOffset17())
            {
                bShouldUpdate = pEffect->HasConditions() || ((LowProcess*)pEffect)->LowProcess::GetActiveCombatTarget();
            }
            if (bShouldUpdate)
                pEffect->UpdateEffect(delta);
            if (!done && pEffect->FUN_00705cf0())
            {
                MagicItem* spell = EFFECT_SPELL(pEffect);
                MagicTarget* target = (MagicTarget*)((ActorMover*)pEffect)->GetCurrentMoveModeType();
                pEffect->SetFlag(true);
                if (pEffect->ActiveEffect_IsActive() && !pEffect->IsFlag200Set() &&
                    target == (g_thePlayer ? (MagicTarget*)((char*)g_thePlayer + 0x94) : 0) && spell->GetSpellType() == 7 &&
                    target->IsLastEffect(spell, pEffect))
                {
                    bool show = true;
                    char message[260];
                    if (target->ContainsSpell(spell, true))
                    {
                        if (!g_thePlayer->GetActorValue((ActorValue::Index)72))
                            sprintf_s(message, sizeof(message), DAT_011d1fc8.GetMenuTitle(),
                                      ((TESSoundFile*)spell)->GetSoundFile());
                        else
                            show = false;
                    }
                    else
                    {
                        sprintf_s(message, sizeof(message), DAT_011d3c04.GetMenuTitle(),
                                  ((TESSoundFile*)spell)->GetSoundFile());
                    }
                    if (show)
                    {
                        MagicTargetMessages::ShowMessage(message, 0, 0, "UIHealthChemsWearOff", 2.0f, false);
                        AlchemyItem* potion = dynamic_cast<AlchemyItem*>(spell);
                        if (potion && potion->CombatController_GetTarget())
                        {
                            TESImageSpaceModifier* modifier = dynamic_cast<TESImageSpaceModifier*>(
                                BGSDefaultObjectManager::GetDefaultObjectByIndex(20));
                            if (modifier)
                                ImageSpaceModifierInstanceForm::ApplyImageSpaceModifier(modifier, 1.0f, 0);
                        }
                    }
                }
            }
            if (IsEffectFlaggedForRemoval(pEffect))
            {
                if (node == list)
                    nextNode = node;
                RemoveEffect(pEffect, true);
            }
        }
        node = nextNode;
    }
    m_bSecondFlag = false;
    ClearActiveEffects();
}

// @fnv 0x00825270
int MagicTarget::CompareActiveEffects(ActiveEffect* first, ActiveEffect* second)
{
    char buffer1[256];
    char buffer2[256];
    EffectItem* pEffect = EFFECT_ITEM(first);
    sprintf(buffer1, "%c%.30s%.1f%.1f", 'A', pEffect->GetEffectName().String(),
            pEffect->GetEffectSetting()->IsFlagSet_00403e60(0x100) ? 1000.0f : first->GetFloatAtOffset1C(),
            pEffect->GetEffectSetting()->IsFlagSet_00403e60(0x80) ? 1000.0f : first->FUN_007df1f0());
    pEffect = EFFECT_ITEM(second);
    sprintf(buffer2, "%c%.30s%.1f%.1f", 'A', pEffect->GetEffectName().String(),
            pEffect->GetEffectSetting()->IsFlagSet_00403e60(0x100) ? 1000.0f : second->GetFloatAtOffset1C(),
            pEffect->GetEffectSetting()->IsFlagSet_00403e60(0x80) ? 1000.0f : second->FUN_007df1f0());
    return _mbsicmp((const unsigned char*)buffer1, (const unsigned char*)buffer2);
}

// @fnv 0x00824400
void MagicTarget::Dispel(MagicItem* spell, MagicCaster* caster, ActiveEffect* effect)
{
    BSSimpleList<ActiveEffect*>* node = GetActiveEffectList();
    while (node && !((BSSimpleList<PerkButtonEntry*>*)node)->IsEmpty())
    {
        ActiveEffect* current = (ActiveEffect*)((BSSimpleList<BGSPerkEntry*>*)node)->GetItem();
        BSSimpleList<ActiveEffect*>* nextNode =
            (BSSimpleList<ActiveEffect*>*)((BSSimpleList<BGSPerkEntry*>*)node)->GetNext();
        if (current && !current->FUN_00705cf0() && EFFECT_SPELL(current) == spell &&
            (caster ? (MagicCaster*)((TESResponse*)current)->GetNext() == caster : true) &&
            (effect ? ((TESTopicInfo*)effect)->GetSpeaker() == ((TESTopicInfo*)current)->GetSpeaker() : true))
        {
            if (effect)
            {
                if (!EFFECT_ITEM(current)->Compare(EFFECT_ITEM(effect)))
                {
                    if (m_bSecondFlag)
                        AddWeatherEntry(spell, caster, current);
                    else
                        current->Dispel(true);
                    break;
                }
            }
            else
            {
                if (m_bSecondFlag)
                    AddWeatherEntry(spell, caster, current);
                else
                    current->Dispel(true);
            }
        }
        node = nextNode;
    }
}

// @fnv 0x008230f0
bool MagicTarget::AddEffectToTarget(MagicCaster* caster, MagicItem* spell, ActiveEffect* effect, bool immediate)
{
    if (((TESForm*)EFFECT_ITEM(effect))->GetFormID())
    {
        bool permanent = EFFECT_ITEM(effect)->IsScriptEffect_008231f0() ? spell->IgnoreResistance() : false;
        if (!permanent && !spell->GetNoAbsorbOrReflect())
        {
            if (ExecuteEffect(caster, spell, effect))
            {
                OnEffectAdded(caster, effect);
                return false;
            }
            if (IsImmuneToEffect(caster, spell, effect, false))
            {
                OnEffectRemoved(caster, effect);
                return false;
            }
        }
    }
    return AddActiveEffect(caster, spell, effect);
}

// Walks the active effect list and returns true if any ActiveEffect's EffectSetting matches setting.
// @fnv 0x00822d80
bool MagicTarget::HasEffect(const EffectSetting* setting)
{
    BSSimpleList<ActiveEffect*>* node = GetActiveEffectList();
    bool found = false;
    while (node && !((BSSimpleList<PerkButtonEntry*>*)node)->IsEmpty() && !found)
    {
        ActiveEffect* effect = (ActiveEffect*)((BSSimpleList<BGSPerkEntry*>*)node)->GetItem();
        if (effect && effect->GetEffectSetting() == setting)
            found = true;
        node = (BSSimpleList<ActiveEffect*>*)((BSSimpleList<BGSPerkEntry*>*)node)->GetNext();
    }
    return found;
}

// Looks up the TESForm for id and, if it is a reference, returns that reference's magic target; otherwise returns null.
// @fnv 0x00825550
MagicTarget* MagicTarget::GetMagicTargetByID(unsigned int id)
{
    TESForm* form = TESForm::GetFormByID(id);
    if (form && ((MagicTargetFormDispatch*)form)->GetIsReference())
    {
        TESObjectREFR* reference = (TESObjectREFR*)form;
        return ((MagicTargetFormDispatch*)reference)->GetMagicTarget();
    }
    return 0;
}

// The coverage entry labels this MagicTarget, but the PC vtable and both
// NonActorMagicCaster constructors identify the receiving class as MagicCaster.
// @fnv 0x00815300
MagicCaster::MagicCaster()
{
    SetSelectedMagicItem((MagicItem*)0);
    SetMagicTarget(0);
    eState = MagicCaster::NO_SPELL;
    apTargetLight = 0;
}

// PC initialization assigns the "spPipBoyLight" form to this static member.
// @fnv 0x0093ccd0
SpellItem* MagicSystem::GetPipBoyLightSpell()
{
    return ms_pPipBoyLightSpell;
}

// @fnv 0x00822f70
// src: COMMUNITY 0x00822f70
bool MagicTarget::HasRecoverableActorValueEffect(ActorValue::Index aeActorValue)
{
    // Short local names retain the original MSVC9 stack layout.
    bool b = false;  // found a hostile effect
    Actor* a = IsActor() ? (this ? (Actor*)((char*)this - 0x94) : NULL) : NULL;
    if (!a || aeActorValue == -1 || aeActorValue == 77)
        return false;
    BSSimpleList<ActiveEffect*>* node = GetActiveEffectList();
    while (node && !b && !((BSSimpleList<PerkButtonEntry*>*)node)->IsEmpty())
    {
        ActiveEffect* effect = (ActiveEffect*)((BSSimpleList<BGSPerkEntry*>*)node)->GetItem();
        if (effect && EFFECT_ITEM(effect)->GetAffectedActorValue() == aeActorValue)
        {
            bool permanent = (int)((LocationDescriptor*)effect)->SetLocRef() == 4 && !effect->HasConditions() ? 1 : 0;
            if (a->IsPlayerRef() && permanent &&
                effect->GetEffectSetting()->IsFlagSet_00403e60(2))
            {
                // Permanent player effects do not count here.
            }
            else if (effect->GetEffectSetting()->IsFlagSet_00403e60(2))
                b = true;
        }
        node = (BSSimpleList<ActiveEffect*>*)((BSSimpleList<BGSPerkEntry*>*)node)->GetNext();
    }
    return b;
}
// @fnv 0x00822b90
bool MagicTarget::HasSpell(MagicItem* spell, bool includeInactive)
{
    BSSimpleList<ActiveEffect*>* node = GetActiveEffectList();
    bool found = false;
    while (node && !found)
    {
        ActiveEffect* effect = (ActiveEffect*)((BSSimpleList<BGSPerkEntry*>*)node)->GetItem();
        if (effect && EFFECT_SPELL(effect) == spell && (includeInactive || effect->ActiveEffect_IsActive()) &&
            !EFFECT_ITEM(effect)->IsScriptBasedEffect())
            found = true;
        node = (BSSimpleList<ActiveEffect*>*)((BSSimpleList<BGSPerkEntry*>*)node)->GetNext();
    }
    return found;
}
// Walks the active effect list and dispels each ActiveEffect with true, advancing to the next node.
// @fnv 0x00824970
void MagicTarget::DispelAllEffects()
{
    BSSimpleList<ActiveEffect*>* node = GetActiveEffectList();
    while (node && !((BSSimpleList<PerkButtonEntry*>*)node)->IsEmpty())
    {
        ActiveEffect* effect = (ActiveEffect*)((BSSimpleList<BGSPerkEntry*>*)node)->GetItem();
        node = (BSSimpleList<ActiveEffect*>*)((BSSimpleList<BGSPerkEntry*>*)node)->GetNext();
        if (effect)
            effect->Dispel(true);
    }
}
// @fnv 0x008231f0
// src: XBOX_PDB 0x008231f0
bool EffectItem::IsScriptEffect_008231f0()
{
    return m_pEffectSetting->FUN_007df1b0();
}

// @fnv 0x004f5d90
void __fastcall SetEffectMagnitude(ActiveEffect* effect, float afValue)
{
    effect->m_fEffectMagnitude = afValue;
}

// @fnv 0x008240f0
bool __fastcall IsEffectFlaggedForRemoval(ActiveEffect* effect)
{
    return ((unsigned int)effect->iFlags & 0x80000000) != 0;
}

// @fnv 0x00822a70
float MagicTarget::GetEffectiveness(MagicCaster* apCaster, MagicItem* apItem, ActiveEffect* apEffect)
{
    return 1.0f;
}

struct FlaggedData
{
    int ContainsAnyFlag(unsigned int);
};

struct FUN_00823c20_shell : FlaggedData
{
    int ActiveEffect_IsExtendDuration();
};

// @fnv 0x00823c20
// src: COMMUNITY 0x00823c20
int FUN_00823c20_shell::ActiveEffect_IsExtendDuration()
{
    return ContainsAnyFlag(2);
}


// Sets or clears bit 31 of iFlags according to abSet.
// @fnv 0x008240a0
void ActiveEffect::SetFlag(bool abSet)
{
    abSet ? iFlags |= 0x80000000 : iFlags &= 0x7fffffff;
}

// MagicTarget.h does not declare the remaining extension routines below.
// Keep those receiver declarations local until the shared interface supports them.
struct FUN_00822cf0_shell : public MagicTarget
{
    bool HasActiveEffectOfArchetype(int archetype, bool include);
};

// @fnv 0x00822cf0
bool FUN_00822cf0_shell::HasActiveEffectOfArchetype(int archetype, bool include)
{
    BSSimpleList<ActiveEffect*>* list = GetActiveEffectList();
    bool found = false;
    while (list && !found)
    {
        ActiveEffect* effect = list->GetItem();
        if (effect && effect->GetEffectSetting()->GetArchetype() == archetype && (include || effect->ActiveEffect_IsActive()))
            found = true;
        list = list->GetNext();
    }
    return found;
}

struct MagicEffectContext
{
    MagicItem* pSpell;
    MagicCaster* m_pEffectInstance;
    ActiveEffect* m_pLinkedEffect;
};
typedef char _sizecheck_SpellDispelData[sizeof(MagicEffectContext) == 12 ? 1 : -1];

void __cdecl Deallocate(void*);
struct List_009e03e0
{
    void RemoveAll();
};

// Iterates the spell dispel list, dispels each entry's spell via its caster and active effect, deallocates the entry, then clears the list.
// @fnv 0x00824370
void MagicTarget::ClearActiveEffects()
{
    BSSimpleList<MagicEffectContext*>* list = &m_kActiveEffectList;
    while (list && !list->IsEmpty())
    {
        MagicEffectContext* data = list->GetItem();
        if (data)
        {
            Dispel(data->pSpell, data->m_pEffectInstance, data->m_pLinkedEffect);
            MagicEffectContext* pEntry = data;
            Deallocate(pEntry);
        }
        list = list->GetNext();
    }
    ((List_009e03e0*)&m_kActiveEffectList)->RemoveAll();
}

// Exe 0x00824570: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct MagictargetOffset08View
{
    unsigned int GetFlags();
};

struct FUN_00824570_shell : MagicTarget
{
    void DispelMatchingActiveEffects(unsigned int formID, unsigned int flags, TESResponse* caster);
};

// Walks the active effect list and dispels each effect whose flags and form ID match, optionally restricted to a given caster.
// @fnv 0x00824570
void FUN_00824570_shell::DispelMatchingActiveEffects(unsigned int formID, unsigned int flags, TESResponse* caster)
{
    BSSimpleList<ActiveEffect*>* effect = GetActiveEffectList();
    while (effect && !effect->IsEmpty())
    {
        ActiveEffect* active = (ActiveEffect*)effect->GetItem();
        BSSimpleList<ActiveEffect*>* next = effect->GetNext();
        if (active && !active->FUN_00705cf0() && ((MagictargetOffset08View*)active)->GetFlags() == flags &&
            ((caster ? ((TESResponse*)active)->GetNext() == caster : true) &&
             ((TESForm*)active)->GetFormID() == formID))
            active->Dispel(true);
        effect = next;
    }
}

struct FUN_008248e0_shell : public MagicTarget
{
    void MagicTarget_Dispel_008248e0(MagicItem* apItem, bool abImmediate);
};

// @fnv 0x008248e0
// src: XBOX_PDB 0x008248e0
void FUN_008248e0_shell::MagicTarget_Dispel_008248e0(MagicItem* apItem, bool abImmediate)
{
    if (!apItem)
        return;

    BSSimpleList<ActiveEffect*>* apList = GetActiveEffectList();
    while (apList && !apList->IsEmpty())
    {
        ActiveEffect* effect = apList->GetItem();
        apList = apList->GetNext();
        if (effect)
        {
            if (!effect->FUN_00705cf0() &&
                reinterpret_cast<TESTopicInfo*>(effect)->GetSpeaker() == reinterpret_cast<TESActorBase*>(apItem))
                effect->Dispel(abImmediate);
        }
    }
}

struct EvalShell : MagicTarget
{
    void MagicTarget_EvaluateSpellConditions();
};
// @fnv 0x008255a0
// src: XBOX_PDB 0x008255a0
void EvalShell::MagicTarget_EvaluateSpellConditions()
{
    BSSimpleList<ActiveEffect*>* current = GetActiveEffectList();
    while (current)
    {
        ActiveEffect* effect = (ActiveEffect*)current->GetItem();
        current = (BSSimpleList<ActiveEffect*>*)current->GetNext();
        if (effect && (effect->HasConditions() || ((LowProcess*)effect)->LowProcess::GetActiveCombatTarget()))
            effect->AdvanceEffect(0.0f, true);
    }
}

float __fastcall GetFloatAtOffset1C(char*);
struct EffectListNode
{
    EffectNode_magictarget* item;
    EffectListNode* next;
    bool _ref_008256d0();
    EffectNode_magictarget* GetItem();
    EffectListNode* GetNext();
};
struct FUN_00822eb0_shell : MagicTarget
{
    float MagicTarget_GetUsageMonitorEffectMagnitude(MagicItem* apSpell);
};
// @fnv 0x00822eb0
// src: XBOX_PDB 0x00822eb0
float FUN_00822eb0_shell::MagicTarget_GetUsageMonitorEffectMagnitude(MagicItem* apSpell)
{
    float fresult = 0.0f;
    EffectItem* pmonitorEffect = apSpell ? ((EffectItemList*)((char*)apSpell + 0xc))->GetScriptEffect() : 0;
    if (pmonitorEffect && HasSpell(apSpell, true))
    {
        EffectListNode* pEffectNode = (EffectListNode*)GetActiveEffectList();
        while (pEffectNode && !pEffectNode->_ref_008256d0())
        {
            TESForm* pForm = pEffectNode->GetItem()->form;
            if (pForm && pForm->GetFormID() == (unsigned int)pmonitorEffect)
                fresult += GetFloatAtOffset1C((char*)pForm);
            pEffectNode = pEffectNode->GetNext();
        }
    }
    return fresult;
}

class S3c60
{
  public:
    bool HasFlag2();
};

struct FUN_00822e00_shell : public MagicTarget
{
    bool MagicTarget_HasDamageHealthEffect();
};

// @fnv 0x00822e00
// src: COMMUNITY 0x00822e00
bool FUN_00822e00_shell::MagicTarget_HasDamageHealthEffect()
{
    BSSimpleList<ActiveEffect*>* list = GetActiveEffectList();
    bool found = false;

    while (list != 0 && !list->IsEmpty() && !found)
    {
        ActiveEffect* effect = list->GetItem();

        if (effect != 0 && reinterpret_cast<S3c60*>(effect->GetEffectSetting())->HasFlag2() &&
            reinterpret_cast<EffectItem*>(reinterpret_cast<TESForm*>(effect)->GetFormID())->GetAffectedActorValue() ==
                0x10 &&
            effect->GetEffectSetting()->IsFlagSet_00403e60(4))
        {
            found = true;
        }

        list = list->GetNext();
    }

    return found;
}

// Returns false if pkForm is deleted, otherwise counts enabled, non-deleted forms of iType in the list excluding pkForm and returns whether that count is zero.
// @fnv 0x00822c30
// src: COMMUNITY 0x00822c30
bool MagicTarget::IsLastEffect(MagicItem* iType, ActiveEffect* pkForm)
{
    if (pkForm->GetHavokWorldObjectCountInSceneGraph_0084e3a0()->IsScriptBasedEffect())
        return false;

    BSSimpleList<ActiveEffect*>* pkNode = GetActiveEffectList();
    bool bFound = false;
    int iCount6 = 0;
    while (pkNode)
    {
        ActiveEffect* pkItem6 = pkNode->GetItem();
        if (pkItem6 && pkItem6->FUN_0044ddc0() == iType && pkItem6->ActiveEffect_IsActive() && !pkItem6->GetHavokWorldObjectCountInSceneGraph_0084e3a0()->IsScriptBasedEffect() &&
            pkItem6 != pkForm)
            iCount6++;
        pkNode = pkNode->GetNext();
    }
    return iCount6 == 0;
}

class MagicCaster;
class TESObjectREFR;

class BaseProcess;
class NiNode;
class CellS
{
  public:
    NiNode* Get3D_00545cb0();
};

class RefS
{
  public:
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
    virtual NiNode* Get3D();
    CellS* GetParentCell();
};
struct MagicTargetUpd : public MagicTarget
{
    void UpdateEffectsByFlags(unsigned int auiFlags);
};

// @fnv 0x00824110
void MagicTargetUpd::UpdateEffectsByFlags(unsigned int auiFlags)
{
    BSSimpleList<ActiveEffect*>* pIter = GetActiveEffectList();
    if (IsActor())
    {
        Actor* pActor = (Actor*)(MagicTarget*)this;
        if ((pActor && !((const Actor*)pActor)->GetCurrentProcess()) || !((RefS*)GetMagicTargetReference())->Get3D() ||
            !((RefS*)GetMagicTargetReference())->GetParentCell() ||
            !((RefS*)GetMagicTargetReference())->GetParentCell()->Get3D_00545cb0())
            return;
    }
    while (pIter && !pIter->IsEmpty())
    {
        BSSimpleList<ActiveEffect*>* pNextEntry = pIter->GetNext();
        ActiveEffect* pEffect = pIter->GetItem();
        if (pEffect && (unsigned int)pEffect->FUN_0044ddc0() == auiFlags)
        {
            if (!pEffect->GetByteAtOffset17())
            {
                pEffect->UpdateEffect(0.1f);
                pNextEntry = pIter->GetNext();
            }
            else
            {
                pEffect->Continue();
            }
            if (pEffect->FUN_00705cf0())
                RemoveEffect(pEffect, false);
        }
        pIter = pNextEntry;
    }
}



class B824800MagicTarget
{
  public:
    virtual void VFunc00();
    virtual void VFunc04();
    virtual EffectNode_magictarget* GetActiveEffectList();

    void RemoveEffect(ActiveEffect* pkEffect, bool bFlag);
    void RemoveEffectsByArchetype(int m_eEffectTypeItem, int iProcessLevel);
};

// Walks the active effect list and dispels/removes each effect whose archetype matches the given id and whose process level matches when nonzero.
// @fnv 0x00824800
void B824800MagicTarget::RemoveEffectsByArchetype(int aiArchetype, int iProcessLevel)
{
    EffectNode_magictarget* pkPrevious = GetActiveEffectList();
    EffectNode_magictarget* pkEntry = pkPrevious;
    while (pkEntry && !pkEntry->FUN_008256d0())
    {
        ActiveEffect* pkEffectA = (ActiveEffect*)*pkEntry->FUN_006815c0();
        bool bLevelMatch = iProcessLevel ? iProcessLevel == (int)GetEffectCaster(pkEffectA) : true;
        if (pkEffectA && !pkEffectA->IsDone() && pkEffectA->GetEffectSetting()->GetArchetype() == aiArchetype &&
            bLevelMatch)
        {
            pkEffectA->Dispel(true);
            RemoveEffect(pkEffectA, false);
        }
        else
        {
            pkPrevious = pkEntry;
            pkEntry = pkEntry->FUN_00726070();
        }
    }
}

struct MagicTargetDispel : MagicTarget
{
    void MagicTarget_DispelAllSpells(bool immediate);
};

// Iterates the active effect list and dispels each effect whose spell type is 0, 2, 3, 7 or 8, or is an enchantment of type 0.
// @fnv 0x008249d0
// src: XBOX_PDB 0x008249d0
void MagicTargetDispel::MagicTarget_DispelAllSpells(bool immediate)
{
    BSSimpleList<ActiveEffect*>* node = GetActiveEffectList();
    while (node && !node->IsEmpty())
    {
        ActiveEffect* effect = node->GetItem();
        node = node->GetNext();
        if (effect)
        {
            MagicItem* spell = effect->FUN_0044ddc0();
            if (spell->GetSpellType() == 0 || spell->GetSpellType() == 2 || spell->GetSpellType() == 3 || spell->GetSpellType() == 7 ||
                spell->GetSpellType() == 8)
            {
                effect->Dispel(immediate);
            }
            else
            {
                EnchantmentItem* enchantment = dynamic_cast<EnchantmentItem*>(spell);
                if (enchantment && enchantment->GetEnchantmentType() == 0)
                    effect->Dispel(immediate);
            }
        }
    }
}


// @fnv 0x00824af0
bool MagicTarget::CanAddEffect(MagicItem* auiFormID, MagicCaster* apCaster, ActiveEffect* apEffect)
{
    bool bFound4 = false;
    BSSimpleList<ActiveEffect*>* pNode2 = GetActiveEffectList();
    while (!bFound4 && pNode2 && !pNode2->IsEmpty())
    {
        ActiveEffect* pEff = pNode2->GetItem();
        BSSimpleList<ActiveEffect*>* pNext3 = pNode2->GetNext();
        if (pEff && !pEff->FUN_00705cf0() && pEff->FUN_0044ddc0() == auiFormID &&
            (apCaster ? GetEffectCaster(pEff) == apCaster : true) &&
            (apEffect ? !pEff->GetHavokWorldObjectCountInSceneGraph_0084e3a0()->Compare(apEffect->GetHavokWorldObjectCountInSceneGraph_0084e3a0()) : true))
        {
            SetEffectMagnitude(pEff, 0.0f);
            bFound4 = true;
        }
        pNode2 = pNext3;
    }
    return bFound4;
}

class ListObj;
class ListItem
{
  public:
    ListObj* m_pEntryObject;
};

class ListNodeCls
{
  public:
    bool IsDone();
    ListItem* GetItem();
    ListNodeCls* Next();
};

class ListObj
{
  public:
    int GetKind();
    void SetOwner(void* owner);
    void SetValue(float f, int v);
};

class FUN_00824df0_cls
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual ListNodeCls* GetFirst();

    void MagicTarget_SetDisplacementSpell(void* a1, int a2);
};

// Walks the list nodes and, for each item whose object has kind a2, sets its owner to a1 and its value to 0.0f with flag 1.
// @fnv 0x00824df0
// src: COMMUNITY 0x00824df0
void FUN_00824df0_cls::MagicTarget_SetDisplacementSpell(void* pOwner, int iKind)
{
    ListNodeCls* node = GetFirst();
    while (node != 0 && !node->IsDone())
    {
        ListObj* obj = node->GetItem()->m_pEntryObject;
        node = node->Next();
        if (obj != 0 && obj->GetKind() == iKind)
        {
            obj->SetOwner(pOwner);
            obj->SetValue(0.0f, 1);
        }
    }
}

struct FUN_008251c0_obj
{
    virtual void* Release(bool);
};
extern int DAT_011c3ea4;
int* __fastcall Setting_Int(int*);
bool AILinearTaskThreadManager_QRunningThreads();
void* __stdcall FUN_004537b0(ActiveEffect*);
void __fastcall RemoveMatchingItem(void*);
void __fastcall QueueTaskWithValue(void*);

class FUN_008251c0_cls
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void* vfn_8(ActiveEffect** pp);
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18(ActiveEffect* a);
    void MagicTarget_RemoveEffect(ActiveEffect* a, bool b);
};

// @fnv 0x008251c0
// src: COMMUNITY 0x008251c0
void FUN_008251c0_cls::MagicTarget_RemoveEffect(ActiveEffect* pEffect, bool b)
{
    if (!b)
    {
        pEffect->SetFlag(true);
        return;
    }
    RemoveMatchingItem(vfn_8(&pEffect));
    vfn_18(pEffect);
    if (*Setting_Int(&DAT_011c3ea4) > 1 && AILinearTaskThreadManager_QRunningThreads())
    {
        QueueTaskWithValue(FUN_004537b0(pEffect));
        return;
    }
    ActiveEffect* t = pEffect;
    ActiveEffect* p = t;
    (void)(p ? ((FUN_008251c0_obj*)p)->Release(true) : 0);
}

void* __fastcall FUN_00717e50(void*);
void* __fastcall FUN_006815c0(void*);
struct FUN_0095e5f0_node
{
    FUN_0095e5f0_node* FUN_00726070();
};
// Walk the race spell list and dispatch each entry through the player's spell-removal slot.
// @fnv 0x0095e5f0
void __fastcall RefreshPlayerRaceSpells(PlayerCharacter* player)
{
    if (player->GetRace())
    {
        void* node = FUN_00717e50((char*)player->GetRace() + 0x2c);
        while (node != 0 && *(int*)FUN_006815c0(node) != 0)
        {
            // The shared header names this slot Unk_F9 but has no argument declaration.
            ((void (__thiscall **)(PlayerCharacter*, int))*(void**)player)[0xf9](
                player, *(int*)FUN_006815c0(node));
            node = ((FUN_0095e5f0_node*)node)->FUN_00726070();
        }
    }
}

struct Setting_Float
{
    float* Float();
};
extern Setting_Float setting_011d1878;

struct Setting_String
{
    const char* String();
};
extern Setting_String setting_011d4cf0;

void __cdecl ApplyPerkModifiers(int, class Actor*, ...);
unsigned int __cdecl DialogueRandom();
void __cdecl FUN_004d5c60(int);
extern "C" int __cdecl sprintf_s(char*, unsigned int, const char*, ...);

struct StandinISModForm
{
    static void Trigger(TESImageSpaceModifier*, float, void*);
};

// AlchemyItem.h does not yet declare this getter. Its receiver is passed in ECX.
float __fastcall GetAlchemyAddictionChance(AlchemyItem*);

struct MT : public MagicTarget
{
    void MagicTarget_EvaluateSpellConditions();
};

struct FUN_00824e70_shell : public MagicTarget
{
    float MagicTarget_GetUsageMonitorEffectMagnitude(MagicItem*);
    void DispelMatchingActiveEffects(EffectItem*, MagicItem*, void*);
    void MagicTarget_SetDisplacementSpell(MagicItem*, MagicItem*);
    bool ApplyAddiction(AlchemyItem* apItem);
};

// @fnv 0x00824e70
bool FUN_00824e70_shell::ApplyAddiction(AlchemyItem* apItem)
{
    float fAddictionChance2 = apItem ? GetAlchemyAddictionChance(apItem) : 0.0f;
    if (!apItem || !apItem->CombatController_GetTarget() || fAddictionChance2 == 0.0)
    {
        return false;
    }
    Actor* pActor2 = GetOwnerActor();
    if (!pActor2)
    {
        return false;
    }
    EffectItem* pEffectItem = apItem->GetScriptEffect();
    if (pEffectItem)
    {
        float fResistance = MagicTarget_GetUsageMonitorEffectMagnitude(apItem);
        if (fResistance <= *setting_011d1878.Float())
        {
            return false;
        }
        else
        {
            fAddictionChance2 = (fResistance - *setting_011d1878.Float()) / 100.0;
        }
    }
    ApplyPerkModifiers(0x17, pActor2, &fAddictionChance2);
    int roll2 = DialogueRandom() % 100;
    if (fAddictionChance2 * 100.0 <= roll2)
    {
        ((MT*)this)->MagicTarget_EvaluateSpellConditions();
        return false;
    }
    bool bShowMsg = pActor2->IsPlayerRef() && !pActor2->ContainsSpell(apItem, true);
    if (pEffectItem)
    {
        DispelMatchingActiveEffects(pEffectItem, apItem, NULL);
    }
    pActor2->CastSpellOnSelf((SpellItem*)apItem->CombatController_GetTarget(), false);
    MagicTarget_SetDisplacementSpell(apItem, (SpellItem*)apItem->CombatController_GetTarget());
    if (bShowMsg)
    {
        FUN_004d5c60(10);
        TESImageSpaceModifier* pMod2 = dynamic_cast<TESImageSpaceModifier*>(TESForm::GetFormByID(0x19482));
        char szBuffer3[260];
        sprintf_s(szBuffer3, sizeof(szBuffer3), setting_011d4cf0.String(), ((TESSoundFile*)((char*)apItem + sizeof(TESBoundObject)))->GetSoundFile());
        MagicTargetMessages::ShowMessage(szBuffer3, 1, NULL, "UIHealthChemsAddicted", 2.0f, false);
        StandinISModForm::Trigger(pMod2, 1.0f, NULL);
        return true;
    }
    return false;
}




// MagicTarget has no declaration for this addiction/source query at 0x00825610.
struct AddictionEffectQuery : MagicTarget
{
    bool HasMatchingSource(int iType, bool bAny);
};

// These are active effects, not MediaSet/TESForm: getters bind to ActiveEffect accessors
// 0x0044ddc0/0x00833c20, and virtual slot 0x18 is MagicItem::GetSpellType.
// Returns whether an addiction effect matches the source and active-state filters.
// @fnv 0x00825610
bool AddictionEffectQuery::HasMatchingSource(int iType, bool bAny)
{
    BSSimpleList<ActiveEffect*>* pkNode = GetActiveEffectList();
    bool bFound = false;
    while (pkNode && !bFound)
    {
        ActiveEffect* pkSet = pkNode->GetItem();
        MagicItem* pkForm = pkSet ? pkSet->FUN_0044ddc0() : 0;
        if (pkForm && pkForm->GetSpellType() == 0xa && (!iType || (int)GetEffectSource(pkSet) == iType) &&
            (bAny || pkSet->ActiveEffect_IsActive()))
            bFound = true;
        pkNode = pkNode->GetNext();
    }
    return bFound;
}

unsigned int __fastcall FUN_0044ddc0(void* apEffect);
class MagicCaster;

// Scans the active effect list for a matching effect and, if found, adds apEffect's magnitude to it and returns whether stacking occurred.
// @fnv 0x00824c00
bool MagicTarget::CanAcceptEffect(MagicItem* apItem, MagicCaster* apCaster, ActiveEffect* apEffect)
{
    bool bStackedValue = false;
    BSSimpleList<ActiveEffect*>* pNode = GetActiveEffectList();
    bool bAddictionValue = false;
    if (apItem->GetSpellType() == 7)
    {
        AlchemyItem* pAlchemy = dynamic_cast<AlchemyItem*>(apItem);
        if (pAlchemy && ((CombatNode_magictarget*)((char*)pAlchemy + 0x9c))->FUN_00726070() == 0xd)
            bAddictionValue = true;
    }
    while (!bStackedValue && pNode && !pNode->IsEmpty())
    {
        ActiveEffect* pActive_2 = pNode->GetItem();
        BSSimpleList<ActiveEffect*>* pTmpNext = pNode->GetNext();
        bool bTmpSame = pActive_2 && (MagicItem*)FUN_0044ddc0(pActive_2) == apItem;
        if (bAddictionValue)
        {
            AlchemyItem* pOther = dynamic_cast<AlchemyItem*>(apItem);
            if (pOther)
                bTmpSame = ((CombatNode_magictarget*)((char*)pOther + 0x9c))->FUN_00726070() == 0xd;
        }
        if (pActive_2 && !pActive_2->FUN_00705cf0() && bTmpSame &&
            (apCaster ? GetEffectCaster(pActive_2) == apCaster : true) &&
            (apEffect ? !EFFECT_ITEM(pActive_2)->Compare(EFFECT_ITEM(apEffect)) : true))
        {
            pActive_2->BaseProcess_SetLastTimeProcessed(pActive_2->FUN_007df1f0() + apEffect->FUN_007df1f0());
            bStackedValue = true;
        }
        pNode = pTmpNext;
    }
    return bStackedValue;
}

struct EffectList
{
    EffectNode_magictarget* item;
    EffectList* next;
    bool FUN_008256d0();
    EffectNode_magictarget*& FUN_006815c0();
    EffectList* FUN_00726070();
    void FUN_00470470();
    ~EffectList();
};

// MagicTarget.h does not declare the virtual destructor implemented here.
class MagicTargetImpl
{
  public:
    virtual ~MagicTargetImpl();
    bool m_bLeadingFlag;
    bool m_bSecondFlag;
    unsigned short layoutPadding6;
    EffectList m_kActiveEffectList;
};
// Deletes each non-null EffectNode_magictarget returned while traversing the list, then calls FUN_00470470 on the list.
// @fnv 0x00822a80
MagicTargetImpl::~MagicTargetImpl()
{
    EffectList* iter = &m_kActiveEffectList;
    while (iter && !iter->FUN_008256d0())
    {
        EffectNode_magictarget* effect = iter->FUN_006815c0();
        if (effect)
        {
            delete effect;
        }
        iter = iter->FUN_00726070();
    }
    m_kActiveEffectList.FUN_00470470();
}

struct SpellFormBase
{
    virtual void v000();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct ListedSpell : SpellFormBase, MagicItem
{
};

struct ActorSpellList
{
    BSSimpleList<ListedSpell*>* GetHead();
};


struct MagicTargetTypedDispel : MagicTarget
{
    void MagicTarget_Dispel(int aiType);
};

// For aiType 1, removes type-1 spells; otherwise, dispels matching active effects or flagged alchemy effects when aiType is 5.
// @fnv 0x00824630
// src: XBOX_PDB 0x00824630
void MagicTargetTypedDispel::MagicTarget_Dispel(int aiType)
{
    BSSimpleList<ActiveEffect*>* pIter;
    if (aiType == 1)
    {
        Actor* pActor =
            dynamic_cast<Actor*>((TESObjectREFR*)GetMagicTargetReference());
        if (pActor)
        {
            bool bRemoved = false;
            do
            {
                BSSimpleList<ListedSpell*>* pNode = ((ActorSpellList*)((char*)pActor->GetActorBase() + offsetof(TESActorBase, spellList) - sizeof(void*)))->GetHead();
                bRemoved = false;
                while (pNode && !pNode->IsEmpty())
                {
                    BSSimpleList<ListedSpell*>* pNext = pNode->GetNext();
                    ListedSpell* pSpell = pNode->GetItem();
                    if (pSpell && pSpell->GetSpellType() == 1)
                    {
                        // Actor::Unk_F9 has no parameter declaration in the shared header.
                        ((void (__thiscall **)(Actor*, ListedSpell*))*(void**)pActor)[0xf9](pActor, pSpell);
                        bRemoved = true;
                        break;
                    }
                    pNode = pNext;
                }
            } while (bRemoved);
        }
    }
    else
    {
        pIter = GetActiveEffectList();
        while (pIter && !pIter->IsEmpty())
        {
            ActiveEffect* pEffect = pIter->GetItem();
            BSSimpleList<ActiveEffect*>* pNextEffect = pIter->GetNext();
            if (pEffect && !pEffect->FUN_00705cf0())
            {
                AlchemyItem* pAlch = dynamic_cast<AlchemyItem*>(pEffect->FUN_0044ddc0());
                bool bFlag = pAlch ? pAlch->CanBePoison() : false;
                if (pEffect->FUN_0044ddc0()->GetSpellType() == aiType || (bFlag && aiType == 5))
                {
                    pEffect->Dispel(false);
                }
            }
            pIter = pNextEffect;
        }
    }
}
