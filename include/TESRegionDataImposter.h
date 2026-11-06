#pragma once

#include "TESRegionData.h"
#include "BSSimpleList.h"
#include "TESFile.h"

class TESObjectREFR;
class TESForm;

class TESRegionDataImposter : public TESRegionData
{
public:
    BSSimpleList<TESObjectREFR*> imposters;

    TESRegionDataImposter();
    TESRegionDataImposter(const TESRegionDataImposter& other);
    TESRegionDataImposter(const TESRegionDataImposter* apSource);
    virtual ~TESRegionDataImposter();
    virtual void Save();
    virtual TESRegionData* Clone();
    virtual TESRegionData* CopyFrom(const TESRegionData* apSrc);
    virtual void SetFromData(const TESRegionData* apSrc, unsigned int auFlags);
    virtual bool ReadRegionData(TESFile* apFile);

    bool ClearList();
    bool AddImposter(TESObjectREFR* ref);
    void InitItem(TESForm* form);
};
