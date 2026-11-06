#pragma once

#include "BSExtraData.h"

class TESActorBase;

class ExtraLeveledCreature : public BSExtraData
{
public:
    virtual ~ExtraLeveledCreature();

    TESActorBase* m_pCreatureBase;
    TESActorBase* pTemplate;
};
