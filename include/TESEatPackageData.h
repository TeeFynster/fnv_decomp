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
    void __thiscall Copy_0067ba40(int flags);
    unsigned char __thiscall Compare_0067bb40(int arg);
    void __thiscall Save_0067bbb0();
    void ProcessState_0067bfa0(BGSLoadFormBuffer* apLoadGameBuffer);
    void PackageLocation_LoadGame_0067fbe0(BGSLoadFormBuffer* apLoadGameBuffer);

    LocationDescriptor* m_pPackageTarget;
};
