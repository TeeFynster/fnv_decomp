#pragma once

#include "ActiveEffect.h"

class InventoryItem;

class DisintegrateArmorEffect : public ActiveEffect
{
public:
    DisintegrateArmorEffect(MagicCaster*, MagicItem*, EffectItem*);
    virtual ~DisintegrateArmorEffect();
    virtual ActiveEffect* Copy() override;
    virtual unsigned short GetSaveSize(Actor*) override;
    virtual void SaveGame(Actor*) override;
    virtual void LoadGame(Actor*) override;
    virtual void Start() override;

    void* Destroy(unsigned int flags);
    InventoryItem* GetItem();
    float GetFloatAtOffset1C(int);
    float GetFloatAtOffset1C();

    InventoryItem* m_pItem;
};
