#pragma once

#include "BSExtraData.h"

class TESGlobal;

class ExtraGlobal : public BSExtraData
{
public:
    virtual ~ExtraGlobal();
    virtual bool Compare(BSExtraData* extra);

    ExtraGlobal(TESGlobal* aGlobal);

    union
    {
        TESGlobal* pGlobalForm;
        TESGlobal* global;
    };
};
