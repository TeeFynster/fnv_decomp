#pragma once

#include "BSExtraData.h"

class TESForm;

class __declspec(novtable) ExtraEmittanceSource : public BSExtraData
{
public:
    virtual ~ExtraEmittanceSource();
    virtual bool Compare(BSExtraData*);

    ExtraEmittanceSource();

    TESForm* pSource;
};
