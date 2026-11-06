#pragma once

#include "TESPackageData.h"

class LocationDescriptor;

class TESUseItemPackageData : public TESPackageData
{
public:
    virtual ~TESUseItemPackageData();
    virtual bool vf02(TESPackageData* other) override;
    virtual void vf03();

    void vf01(TESPackageData* source);
    void FUN_0067c9d0();

    LocationDescriptor* m_pPackageTarget;
};
