#pragma once

#include "MagicTarget.h"

class TESObjectREFR;

struct LitWaterRefList : public BSSimpleList<TESObjectREFR*>
{
public:
    int FUN_005ae380();
    bool BSSimpleList_TESLevSpell_IsInList(TESObjectREFR*& item);
};
