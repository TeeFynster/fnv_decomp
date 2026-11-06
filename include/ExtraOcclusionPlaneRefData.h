#pragma once

#include "BSExtraData.h"

class PatrolReferenceData;

class ExtraOcclusionPlaneRefData : public BSExtraData
{
public:
    ExtraOcclusionPlaneRefData();
    virtual ~ExtraOcclusionPlaneRefData();
    virtual bool Compare(BSExtraData* extra);

    void Reset();
    void SetSelectedMagicItem(PatrolReferenceData*);
    void FUN_00420060();
    void* FUN_00420030(unsigned int flags);

    PatrolReferenceData* pData;
};
