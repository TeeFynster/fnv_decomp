#pragma once

namespace ActorValue
{
    enum Index;
}

class EffectItem;
class StandinAlchemyItem;
class TESResponse;
class ActiveEffect;
class Actor;
class EffectSetting;
class MagicCaster;
class MagicEffectContext;
class MagicItem;
class TESBoundObject;
class TESObjectREFR;

#if !defined(FNV64_BSSIMPLELIST_DEFINED) && !defined(FNV_EXTRADATAOBJECTS_PRIVATE_LAYOUT_SUPPORT_H)
#include "BSSimpleList.h"
#endif

class MagicTarget
{
public:
    virtual bool AddEffectToTarget(MagicCaster* apCaster, MagicItem* apItem, ActiveEffect* apEffect, bool abImmediate);
    virtual TESObjectREFR* GetMagicTargetReference() const;
    virtual BSSimpleList<ActiveEffect*>* GetActiveEffectList();
    virtual bool IsActor();
    virtual bool CanReceiveMagicEffects() const;
    virtual void OnEffectStarted(ActiveEffect* apEffect);
    virtual void OnEffectFinished(ActiveEffect* apEffect);
    virtual void OnEffectAdded(MagicCaster* apCaster, ActiveEffect* apEffect);
    virtual void OnEffectRemoved(MagicCaster* apCaster, ActiveEffect* apEffect);
    virtual float GetEffectiveness(MagicCaster* apCaster, MagicItem* apItem, ActiveEffect* apEffect);
    virtual bool IsImmuneToEffect(MagicCaster* apCaster, MagicItem* apItem, ActiveEffect* apEffect, bool abUnknown);
    virtual bool ExecuteEffect(MagicCaster* apCaster, MagicItem* apItem, ActiveEffect* apEffect);

    bool m_bLeadingFlag;
    bool m_bSecondFlag;
    unsigned short layoutPadding6;
    BSSimpleList<MagicEffectContext*> m_kActiveEffectList;

    MagicTarget();
    ~MagicTarget();
    BSSimpleList<ActiveEffect*>* GetActiveEffectList() const;
    bool MagicTargetIsActor() const;

    bool HasRecoverableActorValueEffect(ActorValue::Index);
    bool IsLastEffect(MagicItem*, ActiveEffect*);
    void FUN_00824400(MagicItem*, int, int);
    void FUN_00823c40(float);
    Actor* FUN_00822b40();

    bool HasSpell(MagicItem*, bool);
    void DispelAllEffects();
    void UpdateActiveEffects(float);
    bool HasEffect(const EffectSetting*);
    static MagicTarget* GetMagicTargetByID(unsigned int);
    void ClearActiveEffects();
    void AddWeatherEntry(MagicItem*, MagicCaster*, ActiveEffect*);
    void RemoveEffect(ActiveEffect*, bool);
    Actor* GetOwnerActor() const;
    bool AddActiveEffect(MagicCaster*, MagicItem*, ActiveEffect*);
    void Dispel(MagicItem*, MagicCaster*, ActiveEffect*);
    bool CanAddEffect(MagicItem*, MagicCaster*, ActiveEffect*);
    bool ContainsSpell(MagicItem*, bool);
    static int CompareActiveEffects(ActiveEffect*, ActiveEffect*);
    bool CanAcceptEffect(MagicItem*, MagicCaster*, ActiveEffect*);
    void RemoveSpellStub(TESBoundObject*, bool);
    bool HasActiveEffectOfArchetype(int archetype, bool include);
    void DispelMatchingActiveEffects(unsigned int formID, unsigned int flags, TESResponse* caster);
    void DispelMatchingActiveEffects(EffectItem*, MagicItem*, void*);
    void MagicTarget_Dispel_008248e0(MagicItem* apItem, bool abImmediate);
    void MagicTarget_EvaluateSpellConditions();
    float MagicTarget_GetUsageMonitorEffectMagnitude(MagicItem* apSpell);
    bool MagicTarget_HasDamageHealthEffect();
    void UpdateEffectsByFlags(unsigned int auiFlags);
    void RemoveEffectsByArchetype(int aiArchetype, int iProcessLevel);
    void MagicTarget_DispelAllSpells(bool immediate);
    void MagicTarget_SetDisplacementSpell(void* pOwner, int iKind);
    void MagicTarget_SetDisplacementSpell(MagicItem*, MagicItem*);
    void MagicTarget_RemoveEffect(ActiveEffect* pEffect, bool b);
    bool ApplyAddiction(StandinAlchemyItem* apItem);
    void MagicTarget_Dispel(int aiType);
};
