// Unit-private complete declaration closure; original accepted header is preserved.
// AddEffectToTarget and SetState identities are qualified whole-covered-body mappings; see NOTES.
#ifndef FNV_MAGICCASTER_PRIVATE_MATCH_H
#define FNV_MAGICCASTER_PRIVATE_MATCH_H

// Local research header for fallout/magic/magiccaster.cpp matching.
//
// The canonical MagicCaster.h in this task only declares the slot-0 virtual,
// so this header declares the complete MagicCaster class: the two data
// members are copied from the canonical MagicCaster.h (same names, order,
// (verified against the PC call sites in this unit: +0x2C
// GetCasterReference, +0x34 GetSelectedMagicItem, +0x40 SetSelectedMagicItem, +0x48
// which this unit calls directly. MagicItem/MagicItemForm/SpellItem model the
// TESForm, MagicItem (the MagicItem base sits at +0x18 on PC since
// sizeof(TESForm) is 0x18), SpellItem : MagicItemForm. The EffectItemList
// secondary base of MagicItem is intentionally omitted: it contributes no
// primary-vtable slots and nothing in this unit touches it, so the emitted
// bytes are identical. MagicItem::CannotCastReason is only used in an
// uncalled declaration slot. The local Actor declares the five real canonical
// bases (members omitted: only the MagicCaster downcast offset is used).
#include "magiccaster_private_layout_support.h"
#include "magiccaster_private_TESForm.h"
#include "magiccaster_private_TESFullName.h"
#include "magiccaster_private_TESObjectREFR.h"
#include "magiccaster_private_MobileObject.h"
#include "magiccaster_private_MagicTarget.h"
#include "magiccaster_private_ActorValueOwner.h"
#include "magiccaster_private_CachedValuesOwner.h"

class EffectItem;
class TESBoundObject;
class ActiveEffect;
class NiNode;
class MagicEffectCollection;

// (canonical generator identifier mapping for MagicSystem::SpellType).
enum MagicSystem__SpellType
{
    MagicSystem__SpellType_SPELL = 0,
    MagicSystem__SpellType_DISEASE = 1,
    MagicSystem__SpellType_POWER = 2,
    MagicSystem__SpellType_LESSER_POWER = 3,
    MagicSystem__SpellType_ABILITY = 4,
    MagicSystem__SpellType_POISON = 5,
    MagicSystem__SpellType_ENCHANTMENT = 6,
    MagicSystem__SpellType_POTION = 7,
    MagicSystem__SpellType_WORTCRAFT = 8,
    MagicSystem__SpellType_LEVELED_SPELL = 9,
    MagicSystem__SpellType_ADDICTION = 10,
    MagicSystem__SpellType_SPELL_TYPE_COUNT = 11
};

namespace MagicSystem {
enum Range
{
    SELF = 0,
    TOUCH = 1,
    TARGET = 2
};
}

class MagicItem : public TESFullName
{
  public:
    typedef int CannotCastReason;
    EffectSetting* GetEffectSettingForRange(MagicSystem::Range range);
    virtual bool IsAutoCalculated();
    virtual void SetPlayable(bool bAutoCalc);
    virtual MagicSystem__SpellType GetSpellType();
    virtual bool IgnoreResistance();
    virtual bool GetNoAbsorbOrReflect();
    virtual unsigned int GetChunkID();
    virtual void* GetData();
    virtual unsigned int GetDataSize();
    virtual bool IsMagicItemEqual(MagicItem* pOther);
    virtual void CopyMagicItemData(MagicItem* pOther);
    virtual void ClearMagicItemData();
    virtual void SaveMagicItemData();
    virtual void LoadMagicItemChunk(TESFile* pFile, unsigned int uiChunk);
    virtual void Endian();
};

class MagicItemForm : public TESForm, public MagicItem
{
  public:
};

class SpellItem : public MagicItemForm
{
  public:
    char _pdbpad_24[16];
    char data_db[16];
};

class MagicEffectSystem
{
  public:
    static ActiveEffect* Activate(MagicCaster* m_pEffectInstance, MagicItem* pItem, EffectItem* pEffect, TESBoundObject* pSource);
};

class MagicCaster
{
  public:
    MagicEffectCollection* apTargetLight;         // +0x4
    MagicCaster__State eState;  // +0x8
    virtual void CastSpellOnCaster(SpellItem* pSpell, bool bImmediate);
    virtual void CastSpellOnSelf(SpellItem* pSpell, bool bImmediate);
    virtual void CastSpellAtLocation(SpellItem* pSpell, bool bImmediate);
    virtual void CastMagicItem(MagicItem* pItem, bool bArg1, MagicTarget* pTarget, float fValue, bool bArg2);
    virtual void CastSpellAtTarget(SpellItem* pSpell, MagicTarget* pTarget, bool bImmediate);
    virtual void CastMagicItemOnObject(MagicItem* pItem, TESBoundObject* pObject, bool bImmediate);
    virtual MagicTarget* GetSpellTarget();
    virtual void UpdateCastState();
    virtual void CompleteCast();
    virtual void SpellCast(MagicItem* pItem, bool bImmediate);
    virtual bool CanCast(MagicItem* pItem, float* pfValue, MagicItem::CannotCastReason* pReason, bool bFlag);
    virtual TESObjectREFR* GetCasterReference();
    virtual NiNode* GetMagicNode();
    virtual MagicItem* GetSelectedMagicItem();
    virtual bool HasActiveEffect(ActiveEffect* pEffect);
    virtual float GetCasterEffectiveness(bool bFlag, float fValue);
    virtual void SetSelectedMagicItem(MagicItem* pItem);
    virtual MagicTarget* GetCurrentMagicTarget();
    virtual void SetMagicTarget(MagicTarget* pTarget);
    virtual ActiveEffect* CreateActiveEffect(MagicItem* pItem, EffectItem* pEffect, TESBoundObject* pSource);
    void RemoveCastingArt();
    Actor* GetCasterActor();
    bool AddEffectToTarget(MagicTarget* target, NiPoint3 position, MagicItem* spell, ActiveEffect* effect,
                           bool immediate);
    void SetState(MagicCaster__State state, char* reason);
    static MagicCaster* GetCasterByHandle(unsigned int formID);
    void LaunchMagicProjectile(float fValue, TESBoundObject* pObject, bool bArg1, float fImpulseRadiusSquared, bool bArg2);
};
FNV_STATIC_ASSERT(sizeof(MagicCaster) == 0xC);
FNV_STATIC_ASSERT(offsetof(MagicCaster, apTargetLight) == 0x4);
FNV_STATIC_ASSERT(offsetof(MagicCaster, eState) == 0x8);

class Actor : public MobileObject,
              public MagicCaster,
              public MagicTarget,
              public ActorValueOwner,
              public CachedValuesOwner
{
};

class NiNode
{
  public:
    int NiNode_GetChildCount();
    void NiNode_RemoveAllChildren();
};
class MagicEffectCollection
{
  public:
    void* FUN_0080fcc0(unsigned int flags);
};
class TESModel
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual const char* GetModelFilePath();
    unsigned int GetModelLength() const;
};
class EffectSetting : public TESForm, public TESModel
{
};
class ModelLoader
{
  public:
    void QueueModelLoad(const char*, bool, unsigned int);
};
extern ModelLoader* g_modelLoader;
#endif
