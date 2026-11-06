#pragma once

#include "TESBoundObject.h"
#include "TESLeveledList.h"
#include "TESModelTextureSwap.h"

class TESActorBase;

class TESLevCreature : public TESBoundObject, public TESLeveledList, public TESModelTextureSwap
{
public:
    TESLevCreature();
    virtual ~TESLevCreature();

    virtual void InitItem();

    bool Load(TESFile* file);
    bool LoadForm(TESFile* file);

    TESActorBase* pTemplate;
};
