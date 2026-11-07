#pragma once

#include "TESPackageData.h"

class AF50Location;

class TESAmbushPackageData : public TESPackageData
{
public:
    virtual ~TESAmbushPackageData();

    bool vf02(TESPackageData* pkOtherData);

    void* Destroy(unsigned int flags);
    void SaveWithTag();
    void SetLocationFromPackage(int aiPackageId);
    bool Compare_0067af50(TESPackageData* pkOtherData);

    AF50Location* m_pkLocation;
};
