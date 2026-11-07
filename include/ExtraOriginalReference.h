#pragma once

#include "BSExtraData.h"

class TESObjectREFR;

class ExtraOriginalReference : public BSExtraData
{
public:
    virtual ~ExtraOriginalReference();
    virtual bool Compare(BSExtraData* apCompare);

    ExtraOriginalReference(TESObjectREFR* apReference);

    bool Compare_004319d0(BSExtraData* apCompare);

    TESObjectREFR* m_pWorldReferenceInfo;
};
