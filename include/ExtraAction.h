#pragma once

#include "BSExtraData.h"

class TESObjectREFR;

class ExtraAction : public BSExtraData
{
public:
    virtual ~ExtraAction();

    ExtraAction();
    void* FUN_0041b680(unsigned int flags);

    unsigned char eAction;
    unsigned char layoutPaddingD[3];
    TESObjectREFR* m_pActionReference;
};
