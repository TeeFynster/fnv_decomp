#include "../../../include/ProcessLists.h"
// fallout/magic/activeeffect.cpp: Interface, EffectSetting, Self, EffectSaveShell (47 functions)

// Unit-private declarations with layouts verified against the packet PC disassembly.

#include <stddef.h>
#include "../../../include/ActiveEffect.h"
#include "../../../include/TESSaveLoadGame.h"
// Unit-local method adapter: the shared ActiveEffect has no declarations for these
// four nonvirtual methods; their bodies access its checked members at +0x08/+0x18/+0x28.
struct EffectStateAccess : public ActiveEffect
{
    bool HasMatchingActiveEffect();
    void ClearFlags(unsigned int);
    void SetLegacyRevertFlags();
    bool ClearCasterIfMatch(MagicCaster*);
};

#include "../../../include/BSSoundHandle.h"
#define FNV_JOIN_IMPL(a, b) a##b
#define FNV_JOIN(a, b) FNV_JOIN_IMPL(a, b)
#define FNV_STATIC_ASSERT(c) typedef char FNV_JOIN(fnv_static_assert_, __LINE__)[(c) ? 1 : -1]

#include "../../../include/Actor.h"
#include "../../../include/AlchemyItem.h"
#include "../../../include/MagicItem.h"
// MagicEffectSystem_activeeffect: local type (was include/MagicEffectSystem.h, which had no evidence of one real class); its methods are 0x00403ab0 EffectArchetypes::Activate, 0x00403c80 EffectArchetypes::CheckFlag, 0x00810fd0 EffectSetting::GetEffectArchetype
class MagicCaster;
class MagicItem;
class EffectItem;
class TESBoundObject;

class MagicEffectSystem_activeeffect
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
#include "../../../include/MagicHitEffect.h"
#include "../../../include/MagicItemObject.h"
#include "../../../include/MagicTarget.h"
#include "../../../include/SpellItem.h"
#include "../../../include/VampirismEffect.h"
#include "../../../include/ActorMover.h"
#include "../../../include/BGSLoadFormBuffer.h"
#include "../../../include/BSTempEffect.h"
#include "../../../include/EffectSetting.h"
#include "../../../include/LowProcess.h"
#include "../../../include/PerkEntryConditionSet.h"
#include "../../../include/SettingT_GameSettingCollection_.h"

// These ID accessors have no shared member declaration; the single-argument
// fastcall form passes the object in ECX, as in the original member calls.
unsigned int __fastcall GetMagicItemFormID(MagicItem*);
unsigned int __fastcall GetMagicTargetID(MagicTarget*);
FNV_STATIC_ASSERT(sizeof(BSTempEffect) == 0x18);
FNV_STATIC_ASSERT(offsetof(BSTempEffect, m_fParticleParameter5) == 0x8);
FNV_STATIC_ASSERT(offsetof(BSTempEffect, bInitialized) == 0x14);
FNV_STATIC_ASSERT(sizeof(MagicHitEffect) == 0x28);
FNV_STATIC_ASSERT(offsetof(MagicHitEffect, pEffect) == 0x18);
FNV_STATIC_ASSERT(offsetof(MagicHitEffect, pTarget) == 0x1C);
FNV_STATIC_ASSERT(offsetof(MagicHitEffect, m_fFirstFloatValue) == 0x20);
FNV_STATIC_ASSERT(offsetof(MagicHitEffect, bWasPlaying) == 0x24);

class EffectItem;
class MagicCaster;
class TESBoundObject;
class BGSPerkEntry;
class BGSSaveFormBuffer;
template <typename T> class BSSimpleList;

#include "../../../include/BSSimpleList.h"
#include "../../../include/BSSimpleList.h"
#include "../../../include/BSSimpleList.h"
FNV_STATIC_ASSERT(sizeof(ActiveEffect) == 72);

FNV_STATIC_ASSERT(offsetof(ActiveEffect, m_fEffectMagnitude) == 4);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, pSpell) == 8);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, pEffect) == 12);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, bActive) == 16);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, bEffectFlag) == 17);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, bWasPlaying) == 18);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, bPickResultFound) == 19);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, m_bEffectState) == 20);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, iFlags) == 24);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, m_fElapsedTime) == 28);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, fDuration) == 32);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, pTarget) == 36);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, m_pEffectInstance) == 40);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, m_eSpellType) == 44);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, m_kSoundHandle) == 48);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, pSource) == 60);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, pHitEffectList) == 64);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, pMagicItem) == 68);

#include "../../../include/BSSimpleList.h"
void ActiveEffect_RevertActiveEffectList(BGSLoadFormBuffer*, BSSimpleList<ActiveEffect*>*);
void InitLoadGameForEffects(BGSLoadFormBuffer*, BSSimpleList<ActiveEffect*>*);

class GlobalObject_0096d020 : public ProcessLists
{
};
extern GlobalObject_0096d020 g_011e0e80;
class TESObjectREFR;

float FloatFloor(float);

void LogWarning(const char*, ...);
extern const char DAT_010794a8[];
#include "../../../include/BSSimpleList.h"

extern SettingT_GameSettingCollection_ g_011d17dc;
extern "C" double floor(float);

#include "../../../include/BaseFormComponent.h"
#include "../../../include/GO.h"
#include "../../../include/TESBoundObject.h"
#include "../../../include/TESForm.h"
#include "../../../include/BGSSaveFormBuffer.h"
#include "../../../include/EffectItem.h"

// @fnv 0x00804090
void ActiveEffect::CopyData(ActiveEffect* pOther)
{
    pOther->m_fEffectMagnitude = m_fEffectMagnitude;
    pOther->pSpell = pSpell;
    pOther->pEffect = pEffect;
    pOther->bActive = bActive;
    pOther->bEffectFlag = bEffectFlag;
    pOther->bWasPlaying = bWasPlaying;
    pOther->bPickResultFound = bPickResultFound;
    pOther->m_bEffectState = m_bEffectState;
    pOther->m_fElapsedTime = m_fElapsedTime;
    pOther->fDuration = fDuration;
    pOther->pTarget = pTarget;
    pOther->m_pEffectInstance = m_pEffectInstance;
    pOther->m_eSpellType = m_eSpellType;
    pOther->pSource = pSource;
    pOther->iFlags = iFlags;
    pOther->pMagicItem = pMagicItem;
}


// Iterates the list and calls the load dispatch on each ActiveEffect with the given buffer.
// @fnv 0x00806b50
void ActiveEffect::WriteActiveEffectList(BGSLoadFormBuffer* pBuffer, BSSimpleList<ActiveEffect*>* apEffectList)
{
    BSSimpleList<BGSPerkEntry*>* pNode = reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(apEffectList);
    while (pNode)
    {
        ActiveEffect* pEffect = reinterpret_cast<ActiveEffect*>(pNode->GetItem());
        if (pEffect)
        {
            pEffect->ApplyLoadBuffer(pBuffer);
        }
        pNode = pNode->GetNext();
    }
}


// Resolves the caster, target and item pointers from their stored ids, then forwards InitLoadGame to each MagicHitEffect in the list.
// @fnv 0x008066d0
void ActiveEffect::InitLoadGame(BGSLoadFormBuffer* pBuffer)
{
    BSSimpleList<BGSPerkEntry*>* pNode;
    m_pEffectInstance = m_pEffectInstance ? MagicCaster::GetCasterByHandle(reinterpret_cast<unsigned int>(m_pEffectInstance)) : 0;
    pTarget = pTarget ? MagicTarget::GetMagicTargetByID(reinterpret_cast<unsigned int>(pTarget)) : 0;
    pMagicItem = pMagicItem ? MagicItem::GetMagicItemByID(reinterpret_cast<unsigned int>(pMagicItem)) : 0;
    pNode = reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(pHitEffectList);
    while (pNode)
    {
        MagicHitEffect* pEffect = reinterpret_cast<MagicHitEffect*>(pNode->GetItem());
        if (pEffect)
        {
            static_cast<BSTempEffect*>(pEffect)->InitLoadGame(pBuffer);
        }
        pNode = pNode->GetNext();
    }
}

// @fnv 0x00810fd0
int EffectSetting::GetArchetype()
{
    return data.m_eEffectTypeItem;
}

// @fnv 0x00804160
void ActiveEffect::Finalize()
{
    if (HasConditions() || reinterpret_cast<LowProcess*>(this)->LowProcess::GetActiveCombatTarget())
        AdvanceEffect(0.0f, true);
}

// Reads a count from the buffer, then loads that many ActiveEffect objects and inserts each non-null one into the list.
// @fnv 0x00806a90
void ActiveEffect::LoadActiveEffectList(BGSLoadFormBuffer* buffer, BSSimpleList<ActiveEffect*>* list)
{
    ActiveEffect_RevertActiveEffectList(buffer, list);
    unsigned int count = buffer->ReadElementCount();
    for (unsigned int i = 0; i < count; ++i)
    {
        ActiveEffect* effect = ReadActiveEffect(buffer);
        if (effect)
            list->Insert(effect, MagicTarget::CompareActiveEffects);
    }
}

// @fnv 0x008067b0
void ActiveEffect::ApplyLoadBuffer(BGSLoadFormBuffer* buffer)
{
    BSSimpleList<BGSPerkEntry*>* node;
    if (GetEffectSetting()->IsFlagSet(0x400))
        ResetEffectState();
    node = reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(pHitEffectList);
    while (node)
    {
        MagicHitEffect* effect = reinterpret_cast<MagicHitEffect*>(node->GetItem());
        if (effect)
        {
            effect->ApplyLoadBuffer(buffer);
            g_011e0e80.RegisterTempEffect(reinterpret_cast<BSTempEffect*>(effect));
        }
        node = node->GetNext();
    }
}

// @fnv 0x00804bc0
void ActiveEffect::SetEffectiveness(float effectiveness)
{
    if (GetHavokWorldObjectCountInSceneGraph_0084e3a0()
            ->GetEffectSetting()
            ->HasAllFlags(0x180))
        return;
    if (effectiveness == 1.0)
        return;
    if (GetHavokWorldObjectCountInSceneGraph_0084e3a0()
            ->GetEffectSetting()
            ->IsFlagSet(0x100))
    {
        BaseProcess_SetLastTimeProcessed(FUN_007df1f0() * effectiveness);
    }
    else
    {
        ActiveEffect_SetMagnitude(FloatFloor(GetFloatAtOffset1C() * effectiveness) < 1.0
                         ? 1.0f
                         : FloatFloor(GetFloatAtOffset1C() * effectiveness));
    }
}


// @fnv 0x00806910
ActiveEffect* ActiveEffect::ReadActiveEffect(BGSLoadFormBuffer* buffer)
{
    // These local names preserve the original MSVC9 stack allocation.
    unsigned int archetype;  // saved spell form ID
    unsigned char index;
    MagicItem* spell = 0;
    int formID;  // serialized effect archetype
    buffer->ReadFormIdentifier(&spell);
    archetype = reinterpret_cast<unsigned int>(spell);
    spell = spell ? MagicItem::GetMagicItemByID(reinterpret_cast<unsigned int>(spell)) : 0;
    index = 0;
    buffer->ReadTypedData(static_cast<void*>(&index), 1u);
    formID = buffer->ReadElementCount();
    if (spell)
    {
        EffectItem* effect = spell->GetEffectItemAtIndex(index);
        if (effect && effect->GetEffectSetting()->GetArchetype() == formID)
        {
            buffer->ReadElementCount();
            ActiveEffect* active = MagicEffectSystem_activeeffect::Activate(0, spell, effect, 0);
            active->LoadGame(buffer);
            return active;
        }
    }
    buffer->AddToOffset(buffer->ReadElementCount());
    LogWarning(DAT_010794a8, archetype, index, formID);
    return 0;
}

// @fnv 0x00803d30
ActiveEffect::ActiveEffect(MagicCaster* caster, MagicItem* spell, EffectItem* effect)
{
    pSpell = spell;
    m_eSpellType = pSpell->GetSpellType();
    pEffect = effect;
    m_fEffectMagnitude = 0.0f;
    bActive = true;
    bEffectFlag = false;
    bWasPlaying = false;
    bPickResultFound = false;
    m_fElapsedTime = effect->GetMagnitude();
    fDuration = effect->GetDuration();
    pTarget = 0;
    m_pEffectInstance = caster;
    pSource = 0;
    pHitEffectList = 0;
    iFlags = 0;
    pMagicItem = 0;
    BSSimpleList<const char*>* conditions = reinterpret_cast<BSSimpleList<const char*>*>(
        &reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(effect->GetConditions())->GetItem());
    if (effect && conditions && !conditions->IsEmpty())
        AddFlags(0x80);
}

// @fnv 0x008043f0
void ActiveEffect::AdvanceEffect(float elapsed, bool force)
{
    if (!HasConditions() && !reinterpret_cast<LowProcess*>(this)->LowProcess::GetActiveCombatTarget())
        return;
    MagicTarget* caster =
        reinterpret_cast<MagicTarget*>(reinterpret_cast<ActorMover*>(this)->GetCurrentMoveModeType());
    if (caster && caster->GetMagicTargetReference())
    {
        float interval = g_011d17dc.Float()->f;
        bool evaluate = force || floor(GetAge() / interval) != floor((GetAge() + elapsed) / interval);
        if (evaluate)
        {
            bool result = GetHavokWorldObjectCountInSceneGraph_0084e3a0()
                              ->GetConditions()
                              ->ContainsTrait(caster->GetMagicTargetReference(), 0);
            result &= !IsTerminated();
            if (result && !bActive && bWasPlaying && !bPickResultFound)
            {
                bEffectFlag = false;
                bWasPlaying = false;
            }
            bActive = result;
        }
    }
}

// @fnv 0x00803e80
void ActiveEffect::AddFlags(unsigned int flags)
{
    iFlags |= flags;
}

// @fnv 0x00804b60
bool ActiveEffect::IsFlagged()
{
    return (iFlags & 0x100) != 0;
}

// @fnv 0x00804b80
bool ActiveEffect::HasFlag(unsigned int flags)
{
    return (iFlags & flags) != 0;
}


// Iterates the ActiveEffect list and calls InitLoadGame(pActor) on each non-null effect.
// @fnv 0x00806b00
void InitLoadGameForEffects(BGSLoadFormBuffer* pActor, BSSimpleList<ActiveEffect*>* pEffectList)
{
    BSSimpleList<BGSPerkEntry*>* node = reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(pEffectList);
    while (node)
    {
        ActiveEffect* item = reinterpret_cast<ActiveEffect*>(node->GetItem());
        if (item)
        {
            item->InitLoadGame(pActor);
        }
        node = node->GetNext();
    }
}

struct BGSSaveFormBuffer;
struct BipedAnim;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiAVObject;
struct NiColor;
struct NiPoint3;
struct TESBoundObject;
struct TESFile;
struct TESForm;
struct TESObject;
struct TESFormList;
struct TESObjectREFR;
struct TESWaterForm;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];

int __fastcall _FNV_GetFormType(TESBoundObject*);

// Stores apSource and, if its form type is 0x18 or 0x1A, calls AddFlags with 0x100.
// @fnv 0x008041c0
void ActiveEffect::InitFromSource(TESBoundObject* apSource)
{
    pSource = apSource;
    if (pSource)
    {
        if (_FNV_GetFormType(pSource) == 0x18 || _FNV_GetFormType(pSource) == 0x1A)
            AddFlags(0x100);
    }
}


struct ListNodeFns
{
    ActiveEffect** _ref_006815c0();
    ListNodeFns* _ref_00726070();
};
// Scans the actor's active-effect list for an effect matching the spell or a potion of the same spell, clearing the result if the actor ignores addiction.
// @fnv 0x00804250
bool EffectStateAccess::HasMatchingActiveEffect()
{
    bool bresult = false;
    bool bignoreAddiction = false;
    if (pTarget->IsActor())
    {
        Actor* pactor = (Actor*)pTarget;
        if (pactor)
        {
            if (pactor->GetActorValue(static_cast<ActorValue::Index>(0x48)) > 0)
            {
                bignoreAddiction = true;
            }
        }
    }
    SpellItem* pspell = dynamic_cast<SpellItem*>(pSpell);
    if (pMagicItem && ((ActorMover*)this)->GetCurrentMoveModeType())
    {
        ListNodeFns* node = (ListNodeFns*)((MagicTarget*)((ActorMover*)this)->GetCurrentMoveModeType())->GetActiveEffectList();
        while (node && !bresult)
        {
            ActiveEffect* pitem = *node->_ref_006815c0();
            if (pitem && pitem->ActiveEffect_IsActive())
            {
                if (pitem->pSpell == pMagicItem)
                {
                    bresult = true;
                }
                else if (pitem->pSpell->GetSpellType() == 7)
                {
                    AlchemyItem* ppotion = dynamic_cast<AlchemyItem*>(pitem->pSpell);
                    if (ppotion && ppotion->CombatController_GetTarget() == pspell)
                    {
                        bresult = true;
                    }
                }
            }
            node = node->_ref_00726070();
        }
    }
    if (bresult && bignoreAddiction)
        bresult = false;
    return bresult;
}

// Exe 0x00804560: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct ActiveeffectOffset08View
{
    unsigned int GetFlags();
};
struct TaskQueueInterface
{
    static TaskQueueInterface* __cdecl GetInstance();
    void TaskQueueInterface_QueueMHEInstantiateHitEffects(ActiveEffect*);
};
// Exe 0x00804560: unit-local Interface view; declarations and layout are preserved.
struct ActiveeffectInterfaceView
{
    static bool __cdecl IsSaveLoadActive();
};
struct List_009e03e0
{
    ~List_009e03e0();
    void RemoveAll();
};
struct TSL_008c48d0
{
    static bool __cdecl RemoveSpell(int);
};
bool __cdecl IsConditionMet();
int __cdecl MagicSystem_CheckEffectFlares(EffectSetting*);
struct PC7d;
extern PC7d* g_thePlayer;

class EffectItemListFoodQuery
{
  public:
    virtual void vfn_00();
    virtual bool HasFoodEffect();
};


// @fnv 0x00804560
void ActiveEffect::UpdateEffect(float afSecondsElapsed)
{
    if (HasConditions() || ((LowProcess*)this)->LowProcess::GetActiveCombatTarget())
        AdvanceEffect(afSecondsElapsed, false);
    if (afSecondsElapsed > 0.0 && !bPickResultFound)
    {
        MagicItem* pspell = (MagicItem*)((ActiveeffectOffset08View*)this)->GetFlags();
        MagicTarget* ptarget = (MagicTarget*)((ActorMover*)this)->GetCurrentMoveModeType();
        TESObjectREFR* ptargetStatsObject = ptarget->GetMagicTargetReference();
        bool bpermanent = TSL_008c48d0::RemoveSpell(m_eSpellType);
        if (!bEffectFlag && !bWasPlaying && bActive)
        {
            if (ptargetStatsObject == (TESObjectREFR*)g_thePlayer && ActiveeffectInterfaceView::IsSaveLoadActive())
                AddFlags(0x20);
            else
                ResetEffectState();
            this->Start();
            if (!bPickResultFound && !bWasPlaying)
            {
                if (!HasFlag(1) && !GetEffectSetting()->IsFlagSet(0x8000000))
                {
                    if (m_eSpellType != MagicSystem__SpellType_ABILITY ||
                        (MagicSystem_CheckEffectFlares(GetEffectSetting()) && GetFloatAtOffset1C() < 100.0))
                    {
                        if (m_eSpellType == MagicSystem__SpellType_ABILITY)
                            AddFlags(4);
                        MagicItemObject* pingredient = pspell->GetSpellType() == MagicSystem__SpellType_WORTCRAFT
                                                           ? static_cast<MagicItemObject*>(pspell)
                                                           : 0;
                        MagicItemObject* ppotion = pspell->GetSpellType() == MagicSystem__SpellType_POTION
                                                       ? static_cast<MagicItemObject*>(pspell)
                                                       : 0;
                        // Address the inherited list without a nullable base-pointer conversion.
                        bool bisFood =
                            pingredient
                                ? ((EffectItemListFoodQuery*)(reinterpret_cast<char*>(pingredient) + (offsetof(MagicItemObject, m_iEffectCount) - offsetof(EffectItemList, m_iEffectCount))))->HasFoodEffect()
                                : (ppotion ? ((EffectItemListFoodQuery*)(reinterpret_cast<char*>(ppotion) + (offsetof(MagicItemObject, m_iEffectCount) - offsetof(EffectItemList, m_iEffectCount))))->HasFoodEffect() : false);
                        if (!bisFood)
                        {
                            if (ptargetStatsObject == (TESObjectREFR*)g_thePlayer && ActiveeffectInterfaceView::IsSaveLoadActive())
                            {
                                AddFlags(0x40);
                            }
                            else
                            {
                                if (pHitEffectList)
                                {
                                    ((List_009e03e0*)pHitEffectList)->RemoveAll();
                                    delete (List_009e03e0*)pHitEffectList;
                                    pHitEffectList = 0;
                                }
                                if (IsConditionMet())
                                    TaskQueueInterface::GetInstance()->TaskQueueInterface_QueueMHEInstantiateHitEffects(this);
                                else
                                    pHitEffectList = MagicHitEffect::GetEffectsForActiveEffect(this);
                            }
                        }
                    }
                }
                bEffectFlag = true;
            }
        }
        if (!bPickResultFound)
        {
            float fupdateTime = afSecondsElapsed;
            if (!bpermanent && !IsFlagged() && GetAge() + fupdateTime > FUN_007df1f0())
            {
                fupdateTime = FUN_007df1f0() - GetAge();
                m_fEffectMagnitude = FUN_007df1f0();
            }
            else
            {
                m_fEffectMagnitude += afSecondsElapsed;
            }
            if (bActive)
            {
                bool bdeferredHitEffect = HasFlag(0x40);
                bool bdeferredSound = HasFlag(0x20);
                if ((bdeferredHitEffect || bdeferredSound) && ptargetStatsObject == (TESObjectREFR*)g_thePlayer &&
                    !ActiveeffectInterfaceView::IsSaveLoadActive())
                {
                    if (bdeferredHitEffect)
                    {
                        if (pHitEffectList)
                        {
                            ((List_009e03e0*)pHitEffectList)->RemoveAll();
                            delete (List_009e03e0*)pHitEffectList;
                            pHitEffectList = 0;
                        }
                        pHitEffectList = MagicHitEffect::GetEffectsForActiveEffect(this);
                        static_cast<EffectStateAccess*>(this)->ClearFlags(0x40);
                    }
                    if (bdeferredSound)
                    {
                        ResetEffectState();
                        static_cast<EffectStateAccess*>(this)->ClearFlags(0x20);
                    }
                }
                this->Update(fupdateTime);
            }
            if (!bpermanent && !IsFlagged())
            {
                if (pEffect->GetEffectSetting()->IsFlagSet(0x80))
                    bPickResultFound = true;
                else if (m_fEffectMagnitude >= FUN_007df1f0())
                    bPickResultFound = true;
            }
            if (pTarget->IsActor())
            {
                Actor* pactor = static_cast<Actor*>(pTarget);
                if (pactor && pactor->HasHealth(true) && !GetEffectSetting()->IsFlagSet(0x10000000))
                    bPickResultFound = true;
            }
        }
    }
    if (bEffectFlag && (bPickResultFound || !bActive) && !bWasPlaying)
    {
        this->Finish();
        bWasPlaying = true;
        if (reinterpret_cast<BSSoundHandle&>(m_kSoundHandle).IsValid())
            reinterpret_cast<BSSoundHandle&>(m_kSoundHandle).Stop();
    }
}

// @fnv 0x00804cb0
// src: XBOX_PDB 0x00804cb0
void __fastcall ActiveEffect_SetMagnitude(void* thisPtr, float value)
{
    *(float*)((char*)thisPtr + 0x1c) = value;
}


// @fnv 0x00805650
void EffectStateAccess::SetLegacyRevertFlags()
{
    AddFlags(2);
    AddFlags(4);
}


// ActiveEffect::Copy (v04)
// Allocates a new ActiveEffect from the spell and effect, copies data into it, and returns it.
// @fnv 0x00803fe0
ActiveEffect* ActiveEffect::Copy()
{
    ActiveEffect* pNewEffect = new ActiveEffect(m_pEffectInstance, pSpell, pEffect);
    CopyData(pNewEffect);
    return pNewEffect;
}

extern TESSaveLoadGame* g_TESSaveLoadGame;


// ActiveEffect::FinishLoadGameTES (v2C)
// @fnv 0x00805760
void ActiveEffect::FinishLoadGameTES(Actor* apActor)
{
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x2a)
    {
        BSSimpleList<MagicHitEffect*>* pCurrentElementNext = pHitEffectList;
        while (pCurrentElementNext && !pCurrentElementNext->IsEmpty())
        {
            MagicHitEffect* phitEffect = pCurrentElementNext->GetItem();
            phitEffect->FinishLoadGameTES(this, reinterpret_cast<TESObjectREFR*>(apActor), 0);
            g_011e0e80.RegisterTempEffect(phitEffect);
            pCurrentElementNext = pCurrentElementNext->GetNext();
        }
    }
    if (GetEffectSetting()->IsFlagSet(0x400))
        ResetEffectState();
}

class TESObjectCELL;
class TESObjectREFR;

struct CF_0081c630
{
    CF_0081c630();
};

struct FUN_0081c530 : MagicHitEffect
{
    bool bFlag28;
    bool bFlag29;
    int iState;
    GO spNode30;
    GO spNode34;
    CF_0081c630 kData;
    FUN_0081c530();
    virtual ~FUN_0081c530();
};

// Initializes the two node handles to null, clears both flags, and sets iState to 0.
// @fnv 0x0081c530
FUN_0081c530::FUN_0081c530() : spNode30(0), spNode34(0)
{
    spNode30 = 0;
    spNode34 = 0;
    bFlag29 = false;
    iState = 0;
    bFlag28 = false;
}

namespace fnv_0081f220 {

struct FUN_00822530
{
    void* pBuffer;
    unsigned int uiSize;
    unsigned int uiAllocSize;
    unsigned int uiGrowSize;
    FUN_00822530();
    ~FUN_00822530();
};

struct FUN_00822580
{
    void* pBuffer;
    unsigned int uiSize;
    unsigned int uiAllocSize;
    FUN_00822580();
    virtual ~FUN_00822580();
};

struct FUN_0081f220 : MagicHitEffect
{
    bool bFlag28;
    int iState;
    void* m_kModelObjectsItem;
    float m_fPackageValue;
    FUN_00822530 kEffects;
    GO spNode48;
    bool bFlag4C;
    FUN_00822580 kObjects;
    float fScale60;
    float fScale64;
    GO spNode68;
    FUN_0081f220();
    virtual ~FUN_0081f220();
};

// Initializes the object's fields: clears pointers and flags, sets state to 0, and sets both scale fields to 1.0.
// @fnv 0x0081f220
FUN_0081f220::FUN_0081f220() : spNode48(0), spNode68(0)
{
    m_kModelObjectsItem = 0;
    spNode68 = 0;
    m_fPackageValue = 0.0f;
    spNode48 = 0;
    bFlag28 = false;
    iState = 0;
    bFlag4C = false;
    fScale60 = 1.0f;
    fScale64 = 1.0f;
}
}  // namespace fnv_0081f220


// @fnv 0x00804210
void ActiveEffect::Dispel(bool abNow)
{
    bPickResultFound = true;
    AddFlags(0x200);
    if (abNow)
    {
        UpdateEffect(0.0f);
    }
}



// @fnv 0x00804ba0
void EffectStateAccess::ClearFlags(unsigned int mask)
{
    iFlags &= ~mask;
}

struct ListProxy008060e0
{
    bool _ref_008256d0();
    ActiveEffect*& _ref_006815c0();
    BSSimpleList<ActiveEffect*>* _ref_00726070();
};
// @fnv 0x008060e0
// src: XBOX_PDB 0x008060e0
void ActiveEffect_InitLoadGameActiveEffectList(BSSimpleList<ActiveEffect*>* apActiveEffectList, Actor* apActor)
{
    ActiveEffect* pEffect;
    while (apActiveEffectList && !((ListProxy008060e0*)apActiveEffectList)->_ref_008256d0())
    {
        pEffect = ((ListProxy008060e0*)apActiveEffectList)->_ref_006815c0();
        pEffect->InitLoadGame(apActor);
        apActiveEffectList = ((ListProxy008060e0*)apActiveEffectList)->_ref_00726070();
    }
}

struct Node008061b0
{
    bool _ref_008256d0();
    ActiveEffect** _ref_006815c0();
    Node008061b0* _ref_00726070();
};
// Walks the node chain from a, calling s13(b) on each node's item until a node satisfies _ref_008256d0 or the chain ends.
// @fnv 0x008061b0
// src: GUESS 0x008061b0 (confidence: high)
void Actor_RevertActiveEffectsInChain(Node008061b0* pNode, Actor* b)
{
    while (pNode && !pNode->_ref_008256d0())
    {
        ActiveEffect* item = *pNode->_ref_006815c0();
        item->Revert(b);
        pNode = pNode->_ref_00726070();
    }
}

// Clears the stored MagicCaster pointer if it equals apCaster and returns whether it matched.
// @fnv 0x00806200
bool EffectStateAccess::ClearCasterIfMatch(MagicCaster* apCaster)
{
    bool bMatched = 0;
    if (apCaster == m_pEffectInstance)
    {
        m_pEffectInstance = 0;
        bMatched = 1;
    }
    return bMatched;
}

void ActiveEffect_SaveActiveEffectBGS(BGSSaveFormBuffer*, BGSPerkEntry*);

// @fnv 0x00806a10
// src: COMMUNITY 0x00806a10
void ActiveEffect_SaveActiveEffectListBGS(BGSSaveFormBuffer* pBuffer, BSSimpleList<BGSPerkEntry*>* pPerkList)
{
    int count = 0;
    unsigned int size = pBuffer->StartVariableSizedValue();
    BSSimpleList<BGSPerkEntry*>* pCurrent = pPerkList;
    while (pCurrent)
    {
        BGSPerkEntry* pEntry = pCurrent->GetItem();
        if (pEntry)
        {
            ActiveEffect_SaveActiveEffectBGS(pBuffer, pEntry);
            ++count;
        }
        pCurrent = pCurrent->GetNext();
    }
    pBuffer->SaveVariableSizedValue_00865ff0(count, size);
}


extern TESSaveLoadGame* DAT_011de45c;

// @fnv 0x00805810
// src: GUESS 0x00805810 (confidence: low)
unsigned short ActiveEffect_UpdateState_00805810(void* pObject, void* pArg)
{
    unsigned short result = 0;

    if (DAT_011de45c->FUN_008df040() >= 0x2a)
        result += 2;

    result += 4;
    result += 1;

    result += ((unsigned short(__thiscall*)(void*, void*))((*(void***)pObject)[4]))(pObject, pArg);

    return result;
}

struct ChangeFlagBytes
{
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
};
struct SaveChangeHeader
{
    unsigned int formID;
    unsigned char formType;
    ChangeFlagBytes changeFlags;
};
extern TESSaveLoadGame* g_pSaveLoadGameStub;

struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};
extern GlobalObject_0045cf30 g_011de4e8;

struct SaveSizeForm
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
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
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
    virtual void v3A();
    virtual void v3B();
    virtual void v3C();
    virtual void v3D();
    virtual void v3E();
    virtual void v3F();
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
    virtual void v4A();
    virtual void v4B();
    virtual const char* GetEditorName();
};
SaveSizeForm* LookupFormByNumericID(unsigned int id);
unsigned short ActiveEffect_UpdateState_00805810(void* pObject, void* pArg);
void __cdecl DebugSaveSizeOutput(const char* fmt, ...);

struct SaveSizeListNode
{
    bool _ref_008256d0();
    void** _ref_006815c0();
    SaveSizeListNode* _ref_00726070();
};

// Computes a save size by adding fixed header bytes and per-node sizes from FUN_00805810, optionally logging the delta and current form header.
// @fnv 0x00805a00
// src: XBOX_PDB 0x00805a00
unsigned short ActiveEffect_GetActiveEffectListSaveSize(SaveSizeListNode* pNodeList, void* pArg)
{
    unsigned short uiSize = 0;
    unsigned short uiStart = uiSize;
    if (g_pSaveLoadGameStub->TESSaveLoadGame_UseSaveGameBlocks())
    {
        uiSize += 4;
        uiSize += 2;
    }
    uiSize += 2;
    while (pNodeList && !pNodeList->_ref_008256d0())
    {
        uiSize += ActiveEffect_UpdateState_00805810(*pNodeList->_ref_006815c0(), pArg);
        pNodeList = pNodeList->_ref_00726070();
    }
    if (*g_011de4e8.Bool())
    {
        SaveChangeHeader* pHeader = static_cast<SaveChangeHeader*>(g_pSaveLoadGameStub->FUN_004fd3e0());
        if (pHeader)
        {
            SaveSizeForm* pForm = LookupFormByNumericID(pHeader->formID);
            DebugSaveSizeOutput("GetSaveSize(): %-5i for form %08X %s with flags %08X ending at line %i in file %s",
                                uiSize - uiStart, pHeader->formID, pForm->GetEditorName(),
                                *(unsigned int*)&pHeader->changeFlags, 968,
                                "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Magic\\ActiveEffect.cpp");
        }
        else
        {
            DebugSaveSizeOutput("GetSaveSize(): %-5i ending at line %i in file %s", uiSize - uiStart, 968,
                                "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Magic\\ActiveEffect.cpp");
        }
    }
    return uiSize;
}

template <int N> struct VirtualSlotTag
{
};
template <int N> struct OpaqueVirtualInterface : OpaqueVirtualInterface<N - 1>
{
    virtual void UnresolvedVirtual(VirtualSlotTag<N>*);
};
template <> struct OpaqueVirtualInterface<0>
{
    virtual void UnresolvedVirtual(VirtualSlotTag<0>*);
};
struct ProcessRefreshDispatch : OpaqueVirtualInterface<351>
{
    virtual void Refresh(int, int, int);
};

struct ActiveEffectListBridge
{
    bool FUN_008256d0();
    ActiveEffect** FUN_006815c0();
    ActiveEffectListBridge* FUN_00726070();
};
// @fnv 0x00806130
// src: XBOX_PDB 0x00806130
void __cdecl ActiveEffect_FinishInitLoadGameActiveEffectList(ActiveEffectListBridge* pEffectList, Actor* pActor)
{
    while (pEffectList != 0 && !pEffectList->FUN_008256d0())
    {
        ActiveEffect* effect = *pEffectList->FUN_006815c0();
        effect->FinishLoadGameTES(reinterpret_cast<Actor*>(pActor));
        pEffectList = pEffectList->FUN_00726070();
    }
    if (pActor != 0)
    {
        if (pActor->FUN_008d8520())
        {
            ProcessRefreshDispatch* dispatcher = (ProcessRefreshDispatch*)pActor->FUN_008d8520();
            dispatcher->Refresh(1, 1, 1);
        }
    }
}

// MagicHitEffect constructor (no arguments): calls the BSTempEffect base
// constructor with (null cell, 0.0f), stores the derived vtable, clears the
// target/effect pointers and age, sets lifetime from a global constant and
// clears the finished flag. Returns this.

class TESObjectCELL;
class TESObjectREFR;

extern float DAT_01016970;

// @fnv 0x0081b650
MagicHitEffect::MagicHitEffect() : BSTempEffect(0, 0.0f)
{
    pTarget = 0;
    pEffect = 0;
    m_fFirstFloatValue = 0.0f;
    m_fParticleParameter5 = DAT_01016970;
    bWasPlaying = 0;
}


struct SoundData36
{
    int f0;
    int f4;
    int f8;
    int f12;
    int f16;
    int f20;
    int f24;
    int f28;
    int f32;
};

struct MidObj
{
    int __thiscall GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    SoundData36 __thiscall CopyBig();
};

struct Obj14
{
    BSSoundHandle __thiscall PlaySoundByFormID(int a, int b, int c, int d);
};
struct ObjC
{
    virtual void M000();
    virtual void M001();
    virtual void M002();
    virtual void M003();
    virtual void M004();
    virtual void M005();
    virtual void M006();
    virtual void M007();
    virtual void M008();
    virtual void M009();
    virtual void M010();
    virtual void M011();
    virtual void M012();
    virtual void M013();
    virtual void M014();
    virtual void M015();
    virtual void M016();
    virtual void M017();
    virtual void M018();
    virtual void M019();
    virtual void M020();
    virtual void M021();
    virtual void M022();
    virtual void M023();
    virtual void M024();
    virtual void M025();
    virtual void M026();
    virtual void M027();
    virtual void M028();
    virtual void M029();
    virtual void M030();
    virtual void M031();
    virtual void M032();
    virtual void M033();
    virtual void M034();
    virtual void M035();
    virtual void M036();
    virtual void M037();
    virtual void M038();
    virtual void M039();
    virtual void M040();
    virtual void M041();
    virtual void M042();
    virtual void M043();
    virtual void M044();
    virtual void M045();
    virtual void M046();
    virtual void M047();
    virtual void M048();
    virtual void M049();
    virtual void M050();
    virtual void M051();
    virtual void M052();
    virtual void M053();
    virtual void M054();
    virtual void M055();
    virtual void M056();
    virtual void M057();
    virtual void M058();
    virtual void M059();
    virtual void M060();
    virtual void M061();
    virtual void M062();
    virtual void M063();
    virtual void M064();
    virtual void M065();
    virtual void M066();
    virtual void M067();
    virtual void M068();
    virtual void M069();
    virtual void M070();
    virtual void M071();
    virtual void M072();
    virtual void M073();
    virtual void M074();
    virtual void M075();
    virtual void M076();
    virtual void M077();
    virtual void M078();
    virtual void M079();
    virtual void M080();
    virtual void M081();
    virtual void M082();
    virtual void M083();
    virtual void M084();
    virtual void M085();
    virtual void M086();
    virtual void M087();
    virtual void M088();
    virtual void M089();
    virtual void M090();
    virtual void M091();
    virtual void M092();
    virtual void M093();
    virtual void M094();
    virtual void M095();
    virtual void M096();
    virtual void M097();
    virtual void M098();
    virtual void M099();
    virtual void M100();
    virtual void M101();
    virtual void M102();
    virtual void M103();
    virtual void M104();
    virtual void M105();
    virtual void M106();
    virtual void M107();
    virtual void M108();
    virtual void M109();
    virtual void M110();
    virtual void M111();
    virtual void M112();
    virtual void M113();
    virtual void M114();
    virtual void M115();
    virtual void M116();
    virtual void M117();
    virtual void M118();
    virtual void M119();
    virtual void M120();
    virtual void M121();
    virtual void M122();
    virtual void M123();
    virtual void M124();
    virtual NiPoint3* GetPoint1f4();
};
struct ObjB
{
    virtual void FirstVirtual();
    virtual ObjC* GetObjC();
    Obj14* __thiscall FUN_00822b40();
};
struct Obj80
{
    virtual void A0();
    virtual void A1();
    virtual void A2();
    virtual void A3();
    virtual void A4();
    virtual void A5();
    virtual int GetVal18();
};
struct AudioSys
{
    BSSoundHandle __thiscall GetSoundHandleByFormID_00ad73b0(int a, int b);
};
AudioSys* __cdecl BSAudio_QInstance();
void* __cdecl GetFlagMask(int v);

// @fnv 0x00804cd0
void __thiscall ActiveEffect::ResetEffectState()
{
    int var10_2;
    Obj14* var4;
    bool flag_;
    var10_2 = reinterpret_cast<MidObj*>(FUN_007df1d0()->GetHitSound()) ? reinterpret_cast<MidObj*>(FUN_007df1d0()->GetHitSound())->GetHavokWorldObjectCountInSceneGraph_0084e3a0() : 0;
    if (var10_2 != 0)
    {
        if (reinterpret_cast<ObjB*>(FUN_0059bb30()))
        {
            if (reinterpret_cast<Obj80*>(FUN_0044ddc0())->GetVal18() != 4)
            {
                BSSoundHandle sound8;
                var4 = reinterpret_cast<ObjB*>(FUN_0059bb30()) ? reinterpret_cast<ObjB*>(FUN_0059bb30())->FUN_00822b40() : 0;
                flag_ = FUN_007df1d0()->IsFlagSet_00403e60(0x400);
                if (reinterpret_cast<MidObj*>(FUN_007df1d0()->GetHitSound()))
                {
                    flag_ = GetFlagMask(reinterpret_cast<MidObj*>(FUN_007df1d0()->GetHitSound())->CopyBig().f4) ? true : false;
                }
                if (var4)
                {
                    int mode8;
                    mode8 = flag_ ? 0x112 : 0x102;
                    sound8 = var4->PlaySoundByFormID(var10_2, flag_, mode8, 0);
                }
                else
                {
                    ObjC* objC2;
                    objC2 = reinterpret_cast<ObjB*>(FUN_0059bb30())->GetObjC();
                    if (objC2)
                    {
                        struct { float x, y, z; } pt5;
                        BSSoundHandle sound2 = BSAudio_QInstance()->GetSoundHandleByFormID_00ad73b0(var10_2, 0x102);
                        *reinterpret_cast<NiPoint3*>(&pt5) = *objC2->GetPoint1f4();
                        sound2.SetPosition(pt5.x, pt5.y, pt5.z);
                        sound2.Play(flag_);
                    }
                }
                if (flag_)
                {
                    if (reinterpret_cast<BSSoundHandle&>(m_kSoundHandle).IsValid())
                    {
                        reinterpret_cast<BSSoundHandle&>(m_kSoundHandle).Stop();
                        reinterpret_cast<BSSoundHandle&>(m_kSoundHandle).Release();
                    }
                    reinterpret_cast<BSSoundHandle&>(m_kSoundHandle) = sound8;
                }
            }
        }
    }
}



// @fnv 0x00804f80
unsigned short ActiveEffect::GetSaveSize(Actor* apActor)
{
    unsigned short usSize = 0;
    usSize += 4;
    usSize += 1;
    usSize += 1;
    usSize += 1;
    usSize += 1;
    usSize += 4;
    usSize += 4;
    usSize += 4;
    usSize += 4;
    usSize += 4;
    if (g_TESSaveLoadGame->FUN_008df040() >= 42)
    {
        usSize += 1;
        BSSimpleList<MagicHitEffect*>* pIter = pHitEffectList;
        while (pIter && !pIter->IsEmpty())
        {
            MagicHitEffect* pHit = pIter->GetItem();
            usSize += 1;
            usSize += pHit->GetSaveSize(this, reinterpret_cast<TESObjectREFR*>(apActor));
            pIter = pIter->GetNext();
        }
    }
    if (g_TESSaveLoadGame->FUN_008df040() >= 72)
    {
        usSize += 4;
    }
    else if (g_TESSaveLoadGame->FUN_008df040() >= 65)
    {
        char b = 0;
        usSize += 1;
    }
    return usSize;
}

struct CasterSaveID
{
    unsigned int MagicCaster_GetMagicCasterFormID();
};
struct TargetSaveID
{
    unsigned int RefreshItem();
};
struct SourceSaveID
{
    unsigned int GetHavokWorldObjectCountInSceneGraph_0084e3a0();
};
struct HitEffectSaveNode
{
    bool FUN_008256d0();
    MagicHitEffect** FUN_006815c0();
    HitEffectSaveNode* FUN_00726070();
};
// @fnv 0x008050d0
void ActiveEffect::SaveGame(Actor* actor)
{
    DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&m_fEffectMagnitude, 4);
    DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&bActive, 1);
    DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&bEffectFlag, 1);
    DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&bWasPlaying, 1);
    DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&bPickResultFound, 1);
    DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&m_bEffectState, 1);
    DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&m_fElapsedTime, 4);
    DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&fDuration, 4);
    unsigned int casterID = 0;
    if (m_pEffectInstance)
        casterID = ((CasterSaveID*)m_pEffectInstance)->MagicCaster_GetMagicCasterFormID();
    DAT_011de45c->TESSaveLoadGame_SaveNumericID(&casterID, 4u);
    unsigned int targetID = 0;
    if (pTarget)
        targetID = ((TargetSaveID*)pTarget)->RefreshItem();
    DAT_011de45c->TESSaveLoadGame_SaveNumericID(&targetID, 4u);
    unsigned int sourceID = 0;
    if (pSource)
        sourceID = ((SourceSaveID*)pSource)->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    DAT_011de45c->TESSaveLoadGame_SaveNumericID(&sourceID, 4u);
    {
        // Local identifiers preserve the original MSVC9 stack allocation.
        unsigned char a;           // hit-effect count
        HitEffectSaveNode* b;      // current list node
        unsigned char c;           // hit-effect type
        MagicHitEffect* d;  // current hit effect
        bool e;                    // legacy flag
        unsigned char* f;          // saved count position
        if (DAT_011de45c->FUN_008df040() >= 42)
        {
            a = 0;
            f = reinterpret_cast<unsigned char*>(DAT_011de45c->FUN_00825c00());
            DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&a, 1);
            b = (HitEffectSaveNode*)pHitEffectList;
            while (b && !b->FUN_008256d0())
            {
                d = *b->FUN_006815c0();
                c = static_cast<unsigned char>(d->GetType());
                DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&c, 1);
                d->SaveGame(this, reinterpret_cast<TESObjectREFR*>(actor));
                ++a;
                b = b->FUN_00726070();
            }
            *f = a;
        }
        if (DAT_011de45c->FUN_008df040() >= 72)
        {
            DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&iFlags, 4);
        }
        else if (DAT_011de45c->FUN_008df040() >= 65)
        {
            e = HasFlag(1);
            DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&e, 1);
        }
    }
}

struct ShaderHitEffect : FUN_0081c530
{
    static void* operator new(unsigned int);
    static void operator delete(void*);
    ShaderHitEffect();
};
struct ModelHitEffect : MagicHitEffect
{
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
    static void* operator new(unsigned int);
    static void operator delete(void*);
    ModelHitEffect();
};
struct HitEffectList : BSSimpleList<MagicHitEffect*>
{
    HitEffectList(MagicHitEffect*&);
    void AddHead(MagicHitEffect*&);
};
extern const char hitEffectLoadWarning[];
void __cdecl HitEffectWarning(const char*, ...);
// Reads an active magic effect's fields from the save stream, recreates its hit effects, and reads flags or a version-gated byte.
// @fnv 0x00805330
void ActiveEffect::LoadGame(Actor* actor)
{
    // Local identifiers and declaration order preserve MSVC9 stack slots.
    unsigned int b;     // Hit-effect index.
    unsigned int a;     // Serialized caster form ID.
    unsigned char c;    // Saved hit-effect type.
    unsigned char e;    // Legacy flag byte.
    unsigned int f;     // Serialized source form ID.
    MagicHitEffect* d;  // Hit effect being restored.
    unsigned char g;    // Number of saved hit effects.
    unsigned int h;     // Serialized target form ID.
    DAT_011de45c->TESSaveLoadGame_LoadGameDataOLD(&m_fEffectMagnitude, 4);
    DAT_011de45c->TESSaveLoadGame_LoadGameDataOLD(&bActive, 1);
    DAT_011de45c->TESSaveLoadGame_LoadGameDataOLD(&bEffectFlag, 1);
    DAT_011de45c->TESSaveLoadGame_LoadGameDataOLD(&bWasPlaying, 1);
    DAT_011de45c->TESSaveLoadGame_LoadGameDataOLD(&bPickResultFound, 1);
    DAT_011de45c->TESSaveLoadGame_LoadGameDataOLD(&m_bEffectState, 1);
    DAT_011de45c->TESSaveLoadGame_LoadGameDataOLD(&m_fElapsedTime, 4);
    DAT_011de45c->TESSaveLoadGame_LoadGameDataOLD(&fDuration, 4);
    DAT_011de45c->FUN_00857aa0(&a, 4);
    m_pEffectInstance = (MagicCaster*)a;
    DAT_011de45c->FUN_00857aa0(&h, 4);
    pTarget = (MagicTarget*)h;
    DAT_011de45c->FUN_00857aa0(&f, 4);
    pSource = (TESBoundObject*)f;
    if (DAT_011de45c->FUN_008df040() >= 42)
    {
        DAT_011de45c->TESSaveLoadGame_LoadGameDataOLD(&g, 1);
        for (b = 0; b < g; ++b)
        {
            DAT_011de45c->TESSaveLoadGame_LoadGameDataOLD(&c, 1);
            d = 0;
            switch (c)
            {
            case 5:
                d = (MagicHitEffect*)new ShaderHitEffect;
                break;
            case 6:
                d = new ModelHitEffect;
                break;
            default:
                HitEffectWarning(hitEffectLoadWarning, c);
                break;
            }
            d->LoadGame(this, (TESObjectREFR*)actor);
            if (!pHitEffectList)
                pHitEffectList = new HitEffectList(d);
            else
                ((HitEffectList*)pHitEffectList)->AddHead(d);
        }
    }
    if (DAT_011de45c->FUN_008df040() >= 72)
        DAT_011de45c->TESSaveLoadGame_LoadGameDataOLD(&iFlags, 4);
    else if (DAT_011de45c->FUN_008df040() >= 65)
    {
        DAT_011de45c->TESSaveLoadGame_LoadGameDataOLD(&e, 1);
        if (e)
            static_cast<EffectStateAccess*>(this)->SetLegacyRevertFlags();
    }
}

class SaveSub
{
  public:
    unsigned char CheckValue(unsigned int v);
};

class SaveOwner
{
  public:
    unsigned int GetKey();
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    SaveSub sub;
};


class SaveEffectObj
{
  public:
    virtual void vfn00();
    virtual void vfn01();
    virtual void vfn02();
    virtual void vfn03();
    virtual unsigned short GetSaveWord(unsigned int arg);
    virtual void vfn05();
    virtual void SaveData(unsigned int arg);
    unsigned int m_04;
    SaveOwner* m_08;
    unsigned int m_0c;
};

// Writes the effect's save word (version >= 0x2a), owner key, a checked flag byte, then calls SaveData.
// @fnv 0x00805880
void SaveEffectData(SaveEffectObj* pEffect, unsigned int arg)
{
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x2a)
    {
        unsigned short usSaveWord = pEffect->GetSaveWord(arg);
        g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&usSaveWord, 2);
    }
    unsigned int uiOwnerKey = pEffect->m_08->GetKey();
    g_TESSaveLoadGame->TESSaveLoadGame_SaveNumericID(&uiOwnerKey, 4u);
    unsigned char ucCheckFlag = pEffect->m_08->sub.CheckValue(pEffect->m_0c);
    g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&ucCheckFlag, 1);
    pEffect->SaveData(arg);
}

namespace fnv_00805b40 {
class GlobalObject_0045cf30
{
  public:
    unsigned char* Bool();
};
extern GlobalObject_0045cf30 g_011de4e8;
struct FormIDEntry
{
    unsigned int formID;
    unsigned char formType;
    unsigned char flagsLo;
};
extern TESSaveLoadGame* g_SaveLoadMgr;
struct SaveForm
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
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
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
    virtual void v3A();
    virtual void v3B();
    virtual void v3C();
    virtual void v3D();
    virtual void v3E();
    virtual void v3F();
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
    virtual void v4A();
    virtual void v4B();
    virtual const char* GetName();
};
SaveForm* LookupFormByID(unsigned int id);
void SaveGameLog(const char* fmt, ...);
void SaveGameWarning2(const char* fmt, ...);
struct AENode
{
    bool IsEmpty();
    ActiveEffect*& GetItem();
    AENode* GetNext();
};
void ProcessActiveEffect(ActiveEffect* apEffect, Actor* apActor);

// Serializes the active-effect list for an actor, writing a block marker and size, counting entries, and logging the block size when debug output is enabled.
// @fnv 0x00805b40
// src: COMMUNITY 0x00805b40
void ActiveEffect_SaveActiveEffectList(AENode* apList, Actor* apActor)
{
    unsigned short usZero6 = 0;
    char* pSizePos8 = 0;
    char* pStart4 = reinterpret_cast<char*>(g_SaveLoadMgr->FUN_00825c00());
    if (*g_011de4e8.Bool())
        pStart4 = reinterpret_cast<char*>(g_SaveLoadMgr->FUN_00825c00());
    if (g_SaveLoadMgr->TESSaveLoadGame_UseSaveGameBlocks())
    {
        unsigned int uiMarker = 0x424c4f4b;
        g_SaveLoadMgr->TESSaveLoadGame_SaveGameDataOLD(&uiMarker, 4);
        pSizePos8 = reinterpret_cast<char*>(g_SaveLoadMgr->FUN_00825c00());
        g_SaveLoadMgr->TESSaveLoadGame_SaveGameDataOLD(&usZero6, 2);
    }
    unsigned short usCount2 = 0;
    char* pCountPos3 = reinterpret_cast<char*>(g_SaveLoadMgr->FUN_00825c00());
    g_SaveLoadMgr->TESSaveLoadGame_SaveGameDataOLD(&usCount2, 2);
    while (apList && !apList->IsEmpty())
    {
        ProcessActiveEffect(apList->GetItem(), apActor);
        usCount2++;
        apList = apList->GetNext();
    }
    *(unsigned short*)pCountPos3 = usCount2;
    if (*g_011de4e8.Bool())
    {
        char* pEnd6 = reinterpret_cast<char*>(g_SaveLoadMgr->FUN_00825c00());
        FormIDEntry* pHeader2 = static_cast<FormIDEntry*>(g_SaveLoadMgr->FUN_004fd3e0());
        if (pHeader2)
        {
            SaveForm* pForm = LookupFormByID(pHeader2->formID);
            SaveGameLog("SaveGame(): %-5i for form %08X %s with flags %08X ending at line %i in file %s",
                        pEnd6 - pStart4, pHeader2->formID, pForm->GetName(), *(unsigned int*)&pHeader2->flagsLo, 992,
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Magic\\ActiveEffect.cpp");
        }
        else
        {
            SaveGameLog("SaveGame(): %-5i ending at line %i in file %s", pEnd6 - pStart4, 992,
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Magic\\ActiveEffect.cpp");
        }
    }
    if (g_SaveLoadMgr->TESSaveLoadGame_UseSaveGameBlocks())
    {
        char* pCur = reinterpret_cast<char*>(g_SaveLoadMgr->FUN_00825c00());
        {
            char* pBlockStart = pSizePos8;
            if (pCur > pBlockStart + 0xffff)
                SaveGameWarning2("SAVELOAD: Save Game Block in file %s on line %i is greater than maximum short size",
                                 "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Magic\\ActiveEffect.cpp", 992);
            *(unsigned short*)pSizePos8 = pCur - pBlockStart;
        }
    }
}
}  // namespace fnv_00805b40

struct SaveFormBuf : public BGSSaveFormBuffer
{
    void SaveData(void* apData, unsigned int auiSize, int aiFlags);
    void SerializeFormData(unsigned int auiFormID, unsigned int auiFlags);
    void SaveFormPtr(void* apForm, int aiFlags);
};


struct SaveHitNode
{
    MagicHitEffect*& GetItem();
    SaveHitNode* GetNext();
};


// Serializes the active effect's fields, caster/target/spell IDs, source form and hit effects into the save buffer.
// @fnv 0x00806230
void ActiveEffect::SaveGame(BGSSaveFormBuffer* apBuffer)
{
    static_cast<SaveFormBuf*>(apBuffer)->SaveData(&m_fEffectMagnitude, 4, 0);
    static_cast<SaveFormBuf*>(apBuffer)->SaveData(&bActive, 1, 0);
    static_cast<SaveFormBuf*>(apBuffer)->SaveData(&bEffectFlag, 1, 0);
    static_cast<SaveFormBuf*>(apBuffer)->SaveData(&bWasPlaying, 1, 0);
    static_cast<SaveFormBuf*>(apBuffer)->SaveData(&bPickResultFound, 1, 0);
    static_cast<SaveFormBuf*>(apBuffer)->SaveData(&m_bEffectState, 1, 0);
    static_cast<SaveFormBuf*>(apBuffer)->SaveData(&m_fElapsedTime, 4, 0);
    static_cast<SaveFormBuf*>(apBuffer)->SaveData(&fDuration, 4, 0);
    static_cast<SaveFormBuf*>(apBuffer)->SaveData(&iFlags, 4, 0);
    static_cast<SaveFormBuf*>(apBuffer)->SerializeFormData(m_pEffectInstance ? m_pEffectInstance->GetCasterHandle() : 0, 0);
    static_cast<SaveFormBuf*>(apBuffer)->SerializeFormData(pTarget ? GetMagicTargetID(pTarget) : 0, 0);
    static_cast<SaveFormBuf*>(apBuffer)->SerializeFormData(pMagicItem ? GetMagicItemFormID(pMagicItem) : 0, 0);
    static_cast<SaveFormBuf*>(apBuffer)->SaveFormPtr(pSource, 0);
    int iCount7 = 0;
    unsigned int uiOffset2 = apBuffer->StartVariableSizedValue();
    SaveHitNode* pNode = (SaveHitNode*)pHitEffectList;
    while (pNode)
    {
        MagicHitEffect* pHit2 = pNode->GetItem();
        if (pHit2)
        {
            char cType = (char)pHit2->GetType();
            static_cast<SaveFormBuf*>(apBuffer)->SaveData(&cType, 1, 0);
            static_cast<BSTempEffect*>(pHit2)->SaveGame(apBuffer);
            iCount7++;
        }
        pNode = pNode->GetNext();
    }
    apBuffer->SaveVariableSizedValue_00865ff0(iCount7, uiOffset2);
}

class B806840EffectItem;

class B806840EffectItem
{
  public:
    EffectSetting* GetEffectSetting();
};

class B806840EffectList
{
  public:
    bool Contains(B806840EffectItem* pkItem);
};

class B806840SaveBuffer
{
  public:
    void SerializeFormData(unsigned int auiFormId, unsigned int uiFlags);
    void SaveData(void* pvData, int iSize, int iFlags);
    void SaveInt(unsigned int uiValue);
    unsigned int BeginChunk();
    int GetOffset();
    void EndChunk(int iSize, unsigned int uiChunk);
};


// @fnv 0x00806840
// src: COMMUNITY 0x00806840
void __cdecl ActiveEffect_SaveActiveEffectBGS(B806840SaveBuffer* pkBuffer, ActiveEffect* pkEffect)
{
    pkBuffer->SerializeFormData(pkEffect->pSpell ? GetMagicItemFormID(pkEffect->pSpell) : 0, 0);
    bool bInList2 = ((B806840EffectList*)(reinterpret_cast<char*>(pkEffect->pSpell) + (offsetof(MagicItem, m_iEffectCount) - offsetof(EffectItemList, m_iEffectCount))))->Contains(reinterpret_cast<B806840EffectItem*>(pkEffect->pEffect));
    pkBuffer->SaveData(&bInList2, 1, 0);
    int eArchetype2 = pkEffect->pEffect->GetEffectSetting()->GetArchetype();
    pkBuffer->SaveInt(eArchetype2);
    unsigned int uiChunk = pkBuffer->BeginChunk();
    int iStart2 = pkBuffer->GetOffset();
    pkEffect->SaveGame(reinterpret_cast<BGSSaveFormBuffer*>(pkBuffer));
    int iEnd = pkBuffer->GetOffset();
    pkBuffer->EndChunk(iEnd - iStart2, uiChunk);
}


TESForm* TESForm_GetFormByNumericID(unsigned int id);
MagicCaster* FUN_00818c60(MagicCaster* pkCaster);
MagicTarget* FUN_00825550(MagicTarget* pkTarget);

// @fnv 0x00805670
void ActiveEffect::InitLoadGame(Actor* apActor)
{
    MagicTarget* pkTarget;
    MagicCaster* pkCaster;
    TESBoundObject* source;
    pkCaster = m_pEffectInstance;
    if (pkCaster)
        m_pEffectInstance = FUN_00818c60(pkCaster);
    pkTarget = pTarget;
    if (pkTarget)
        pTarget = FUN_00825550(pkTarget);
    source = pSource;
    if (pkTarget)
        pSource = dynamic_cast<TESBoundObject*>(TESForm_GetFormByNumericID((unsigned int)source));
    if (DAT_011de45c->FUN_008df040() >= 0x2a)
    {
        BSSimpleList<MagicHitEffect*>* it = pHitEffectList;
        while (it && !it->IsEmpty())
        {
            MagicHitEffect* hit = it->GetItem();
            hit->InitLoadGame(this, (TESObjectREFR*)apActor);
            it = it->GetNext();
        }
    }
}

struct Shell81c530 : public FUN_0081c530
{
    static void* operator new(unsigned int size);
    Shell81c530();
};
struct FUN_0081f220 : public MagicHitEffect
{
    static void* operator new(unsigned int size);
    int field28;
    int field2c;
    int field30;
    int field34;
    int field38;
    int field3c;
    int field40;
    int field44;
    int field48;
    int field4c;
    int field50;
    int field54;
    int field58;
    int field5c;
    int field60;
    int field64;
    int field68;
    FUN_0081f220();
};
struct FUN_00470440
{
    MagicHitEffect* m_item;
    FUN_00470440* m_pkNext;
    FUN_00470440(BGSPerkEntry* const& item);
};
TESForm* TESForm_GetFormByNumericID(unsigned int id);
void __cdecl FNV_Warning(const char* fmt, ...);

// Reads effect fields and tagged hit effects from the buffer, loads each effect, and adds it to pHitEffectList.
// @fnv 0x00806420
void ActiveEffect::LoadGame(BGSLoadFormBuffer* apBuffer)
{
    apBuffer->ReadTypedData(static_cast<void*>(&m_fEffectMagnitude), 4u);
    apBuffer->ReadTypedData(static_cast<void*>(&bActive), 1u);
    apBuffer->ReadTypedData(static_cast<void*>(&bEffectFlag), 1u);
    apBuffer->ReadTypedData(static_cast<void*>(&bWasPlaying), 1u);
    apBuffer->ReadTypedData(static_cast<void*>(&bPickResultFound), 1u);
    apBuffer->ReadTypedData(static_cast<void*>(&m_bEffectState), 1u);
    apBuffer->ReadTypedData(static_cast<void*>(&m_fElapsedTime), 4u);
    apBuffer->ReadTypedData(static_cast<void*>(&fDuration), 4u);
    apBuffer->ReadTypedData(static_cast<void*>(&iFlags), 4u);
    apBuffer->ReadFormIdentifier(&m_pEffectInstance);
    apBuffer->ReadFormIdentifier(&pTarget);
    apBuffer->ReadFormIdentifier(&pMagicItem);
    pSource = dynamic_cast<TESBoundObject*>(TESForm_GetFormByNumericID(apBuffer->FUN_008648a0()));
    int count = apBuffer->FUN_00864a60();
    for (unsigned int i = 0; i < (unsigned int)count; ++i)
    {
        MagicHitEffect* pHitEffect;
        unsigned char uiTag = 0;
        apBuffer->ReadTypedData(static_cast<void*>(&uiTag), 1u);
        pHitEffect = 0;
        switch (uiTag)
        {
        case 5:
            pHitEffect = (MagicHitEffect*)new Shell81c530();
            break;
        case 6:
            pHitEffect = (MagicHitEffect*)new FUN_0081f220();
            break;
        default:
            FNV_Warning("SAVELOAD: Unknown magic hit effect type: %i", uiTag);
            break;
        }
        pHitEffect->FUN_00984f60(reinterpret_cast<unsigned int>(this));
        ((BSTempEffect*)pHitEffect)->LoadGame(apBuffer);
        if (pHitEffectList == 0)
        {
            pHitEffectList =
                (BSSimpleList<MagicHitEffect*>*)new FUN_00470440(reinterpret_cast<BGSPerkEntry*&>(pHitEffect));
        }
        else
        {
            ((BSSimpleList<TESForm*>*)pHitEffectList)->AddHead(reinterpret_cast<TESForm*&>(pHitEffect));
        }
    }
}

struct LoadEffectFlagBytes_5d40
{
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
};
struct SaveLoadRecord_5d40
{
    unsigned int formID;
    unsigned char formType;
    LoadEffectFlagBytes_5d40 flags;
    unsigned char version;
};


extern TESSaveLoadGame* g_TESSaveLoadGame;

class TESFormStandin_5d40
{
  public:
    virtual void s00();
    virtual void s01();
    virtual void s02();
    virtual void s03();
    virtual void s04();
    virtual void s05();
    virtual void s06();
    virtual void s07();
    virtual void s08();
    virtual void s09();
    virtual void s0A();
    virtual void s0B();
    virtual void s0C();
    virtual void s0D();
    virtual void s0E();
    virtual void s0F();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s1A();
    virtual void s1B();
    virtual void s1C();
    virtual void s1D();
    virtual void s1E();
    virtual void s1F();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s2A();
    virtual void s2B();
    virtual void s2C();
    virtual void s2D();
    virtual void s2E();
    virtual void s2F();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s3A();
    virtual void s3B();
    virtual void s3C();
    virtual void s3D();
    virtual void s3E();
    virtual void s3F();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void s49();
    virtual void s4A();
    virtual void s4B();
    virtual const char* GetName();
};

class TESForm;
TESForm* TESForm_GetFormByNumericID(unsigned int id);
void __cdecl FNV_Warning(const char* fmt, ...);
ActiveEffect* ActiveEffect_LoadActiveEffect(Actor*);

class ActiveEffectList_5d40 : public BSSimpleList<ActiveEffect*>
{
  public:
    bool IsEmpty();
    ActiveEffect*& GetItem();
    ActiveEffectList_5d40* GetNext();
    void RemoveAll();
};

// @fnv 0x00805d40
// src: XBOX_PDB 0x00805d40
void ActiveEffect_LoadActiveEffectList(ActiveEffectList_5d40* apList, Actor* apActor)
{
    float p;
    int h;
    unsigned short a = 0;
    unsigned int i = 0;
    unsigned short s;
    ActiveEffectList_5d40* f;
    unsigned int eb;
    SaveLoadRecord_5d40* cf;
    TESFormStandin_5d40* q;
    VampirismEffect* b;
    ActiveEffect* ba;
    VampirismEffect* k;
    ActiveEffect* l;
    SaveLoadRecord_5d40* c;
    unsigned int e;
    TESFormStandin_5d40* j;

    if (g_TESSaveLoadGame->TESSaveLoadGame_UseSaveGameBlocks())
    {
        g_TESSaveLoadGame->TESSaveLoadGame_LoadGameDataOLD(&eb, 4);
        if (eb != 'BLOK')
        {
            cf = (SaveLoadRecord_5d40*)g_TESSaveLoadGame->BGSProjectile_GetExplosion();
            if (cf)
            {
                q = (TESFormStandin_5d40*)TESForm_GetFormByNumericID(cf->formID);
                FNV_Warning(
                    "SAVELOAD: (LoadGame Buffer error) Block Header is incorrect in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Magic\\ActiveEffect.cpp", 1000, cf->formID,
                    q->GetName(), (int)cf->version, *(unsigned int*)&cf->flags);
            }
            else
            {
                FNV_Warning(
                    "SAVELOAD: (LoadGame Buffer error) Block Header is incorrect in file %s on line %i.  Current version is %i",
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Magic\\ActiveEffect.cpp", 1000,
                    (int)g_TESSaveLoadGame->FUN_008df040());
            }
        }
        i = g_TESSaveLoadGame->FUN_00825c00();
        g_TESSaveLoadGame->TESSaveLoadGame_LoadGameDataOLD(&a, 2);
    }

    p = 0.0f;
    f = apList;
    while (f && !f->IsEmpty())
    {
        ba = f->GetItem();
        b = dynamic_cast<VampirismEffect*>(ba);
        if (b)
        {
            p = ba->GetFloatAtOffset1C();
        }
        delete ba;
        f = f->GetNext();
    }
    apList->RemoveAll();

    g_TESSaveLoadGame->TESSaveLoadGame_LoadGameDataOLD(&s, 2);
    for (h = 0; h < (int)s; ++h)
    {
        l = ActiveEffect_LoadActiveEffect(apActor);
        k = dynamic_cast<VampirismEffect*>(l);
        if (k && apActor)
        {
            apActor->GetCurrentProcess();
        }
        if (l)
        {
            apList->Insert(l, MagicTarget::CompareActiveEffects);
        }
    }

    if (g_TESSaveLoadGame->TESSaveLoadGame_UseSaveGameBlocks())
    {
        e = g_TESSaveLoadGame->FUN_00825c00();
        c = (SaveLoadRecord_5d40*)g_TESSaveLoadGame->BGSProjectile_GetExplosion();
        if (c)
        {
            j = (TESFormStandin_5d40*)TESForm_GetFormByNumericID(c->formID);
            if (e > (unsigned int)a + i)
            {
                FNV_Warning(
                    "SAVELOAD: LoadGame Buffer overrun of %i bytes in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                    e - ((unsigned int)a + i),
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Magic\\ActiveEffect.cpp", 1039, c->formID,
                    j->GetName(), (int)c->version, *(unsigned int*)&c->flags);
            }
            else if (e < (unsigned int)a + i)
            {
                FNV_Warning(
                    "SAVELOAD: LoadGame Buffer underrun of %i bytes in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                    ((unsigned int)a + i) - e,
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Magic\\ActiveEffect.cpp", 1039, c->formID,
                    j->GetName(), (int)c->version, *(unsigned int*)&c->flags);
            }
        }
        else
        {
            if (e > (unsigned int)a + i)
            {
                FNV_Warning(
                    "SAVELOAD: LoadGame Buffer overrun of %i bytes in file %s on line %i.  Current version is %i",
                    e - ((unsigned int)a + i),
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Magic\\ActiveEffect.cpp", 1039,
                    (int)g_TESSaveLoadGame->FUN_008df040());
            }
            else if (e < (unsigned int)a + i)
            {
                FNV_Warning(
                    "SAVELOAD: LoadGame Buffer underrun of %i bytes in file %s on line %i.  Current version is %i",
                    ((unsigned int)a + i) - e,
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Magic\\ActiveEffect.cpp", 1039,
                    (int)g_TESSaveLoadGame->FUN_008df040());
            }
        }
    }
}

struct HitEffectNode
{
    bool _ref_008256d0();
    MagicHitEffect** _ref_006815c0();
    HitEffectNode* _ref_00726070();
};


// @fnv 0x00803ed0
ActiveEffect::~ActiveEffect()
{
    HitEffectNode* pIter = (HitEffectNode*)pHitEffectList;
    while (pIter && !pIter->_ref_008256d0())
    {
        MagicHitEffect* pHitEffect = *pIter->_ref_006815c0();
        pHitEffect->SetByteAt24(1);
        pHitEffect->FUN_00984f60(0);
        pIter = pIter->_ref_00726070();
    }
    if (pHitEffectList)
        pHitEffectList->RemoveAll();
    delete pHitEffectList;
    if (m_kSoundHandle.IsValid())
    {
        m_kSoundHandle.Stop();
        m_kSoundHandle.Release();
    }
}
