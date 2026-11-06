#pragma once

#include "BSExtraData.h"

class TESObjectREFR;

class ExtraMerchantContainer : public BSExtraData
{
public:
    virtual ~ExtraMerchantContainer();
    virtual bool Compare(BSExtraData*);

    ExtraMerchantContainer();

    TESObjectREFR* pContainer;
};
