#pragma once

#include "TESPackageData.h"

class LocationDescriptor;

class TESEscortPackageData : public TESPackageData
{
public:
    TESEscortPackageData();
    virtual ~TESEscortPackageData();

    LocationDescriptor* m_pPackageTarget;
    int m_iValue;

    TESEscortPackageData* __thiscall ConstructFromForm(TESForm** pForm);
    void FUN_0067c330(BGSLoadFormBuffer* buffer);
    void LoadPackageData(BGSLoadFormBuffer* pBuffer);

    void FUN_0067ad20();
    TESEscortPackageData* FUN_0067bbf0();
    void FUN_0067bca0();
    void* DestroyIfFlagged(unsigned int);
    void FUN_0067bec0();
    void FUN_0067bf40(BGSSaveFormBuffer* buffer);
};
