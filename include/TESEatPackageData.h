#pragma once

#include "TESPackageData.h"

class LocationDescriptor;
class BGSLoadFormBuffer;

class TESEatPackageData : public TESPackageData
{
public:
    virtual ~TESEatPackageData();
    virtual void vf03();

    void vf07(BGSLoadFormBuffer* apLoadGameBuffer);

    void __thiscall Load(BGSLoadFormBuffer* apLoadGameBuffer);
    void __thiscall FUN_0067ba40(int flags);
    unsigned char __thiscall FUN_0067bb40(int arg);
    void __thiscall FUN_0067bbb0();
    void FUN_0067bfa0(BGSLoadFormBuffer* apLoadGameBuffer);
    void FUN_0067fbe0(BGSLoadFormBuffer* apLoadGameBuffer);

    LocationDescriptor* m_pPackageTarget;
};
