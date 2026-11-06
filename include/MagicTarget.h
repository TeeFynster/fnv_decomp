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

    bool FUN_00822f70(ActorValue::Index);
    bool FUN_00822c30(MagicItem*, ActiveEffect*);
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
    void FUN_008248e0(MagicItem* apItem, bool abImmediate);
    void FUN_008255a0();
    float FUN_00822eb0(MagicItem* apSpell);
    bool FUN_00822e00();
    void UpdateEffectsByFlags(unsigned int auiFlags);
    void RemoveEffectsByArchetype(int aiArchetype, int iProcessLevel);
    void FUN_008249d0(bool immediate);
    void FUN_00824df0(void* pOwner, int iKind);
    void FUN_00824df0(MagicItem*, MagicItem*);
    void FUN_008251c0(ActiveEffect* pEffect, bool b);
    bool ApplyAddiction(StandinAlchemyItem* apItem);
    void FUN_00824630(int aiType);
};
