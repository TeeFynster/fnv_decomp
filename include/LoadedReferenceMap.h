#pragma once

#include "NiTMap.h"

class TESObjectREFR;

class LoadedReferenceMap : public NiTMap<unsigned int, TESObjectREFR*>
{
public:
    unsigned int iCount;
    unsigned int m_uiLastUpdateTime;

    virtual ~LoadedReferenceMap();
    bool AddReference(TESObjectREFR* pRef);
};
