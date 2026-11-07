#pragma once

#include "BSExtraData.h"
#include "LitWaterRefList.h"

class BSExtraDataEx;

class ExtraWaterLightRefs : public BSExtraData
{
public:
    virtual ~ExtraWaterLightRefs();
    virtual bool Compare(BSExtraData* apCompare);

    ExtraWaterLightRefs();
    bool Compare_004349c0(BSExtraData* apCompare);
    void Copy(BSExtraDataEx* apSource);

    LitWaterRefList kRefs;
};
