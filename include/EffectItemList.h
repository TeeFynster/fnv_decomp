#pragma once

#include "BSSimpleList.h"
#include "MagicTarget.h"

class Actor;
class EffectItem;
class TESFile;

class EffectItemList : public BSSimpleList<EffectItem *>
{
public:
    EffectItemList();
    virtual ~EffectItemList();
    virtual void vf01();
    virtual float GetTotalCost(Actor* actor);
    virtual void vf03();
    virtual void vf04();

    int m_iEffectCount;

    EffectItem* GetScriptEffect();
    void AddItem(EffectItem* item);
    EffectItem* FindCostliestEffectItem(int aeRange, bool abAreaOnly);
    EffectItem* FindCostliestEffectItem(int m_eRange, int iUnk);
    void Load(TESFile* file, const char* modelName);
    bool Compare(EffectItemList* other);
    void CopyItemsFromList(EffectItemList* other);
    void RemoveAllEffectItems();
    bool HasNonDetrimentalEffect();
    bool HasNonDetrimentalEffectWithFlag(unsigned int flag);
    bool HasDetrimentalEffect();
    EffectItem* GetEffectItemAtIndex(unsigned char index);
    bool IsHostile_00405d80();
    bool CanBePoison();
    bool HasTouchEffect();
    bool HasSelfEffect();
    void RemoveAllEffects();
};
