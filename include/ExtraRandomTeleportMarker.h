#pragma once

#include "BSExtraData.h"

class TESObjectREFR;

class ExtraRandomTeleportMarker : public BSExtraData
{
public:
    virtual bool Compare(BSExtraData* apCompare) override;

    TESObjectREFR* pTeleportMarker;
};
