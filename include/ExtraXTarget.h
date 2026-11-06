#pragma once

#include "BSExtraData.h"

class TESObjectREFR;

class ExtraXTarget : public BSExtraData
{
public:
    virtual ~ExtraXTarget();
    virtual bool Compare(BSExtraData*);

    ExtraXTarget();

    TESObjectREFR* pTarget;
};
