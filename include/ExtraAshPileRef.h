#pragma once

#include "BSExtraData.h"

class TESObjectREFR;

class ExtraAshPileRef : public BSExtraData
{
public:
    ExtraAshPileRef();

    TESObjectREFR* m_pAshPileRef;
};
