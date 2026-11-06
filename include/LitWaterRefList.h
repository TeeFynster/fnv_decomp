#pragma once

#include "MagicTarget.h"

class TESObjectREFR;

struct LitWaterRefList : public BSSimpleList<TESObjectREFR*>
{
public:
    int FUN_005ae380();
    bool FUN_005f65d0(TESObjectREFR*& item);
};
