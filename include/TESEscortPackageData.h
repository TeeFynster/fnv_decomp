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
    void TESFollowPackageData_LoadGame(BGSLoadFormBuffer* buffer);
    void LoadPackageData(BGSLoadFormBuffer* pBuffer);

    void FUN_0067ad20();
    TESEscortPackageData* TESEscortPackageData_0067bbf0();
    void FUN_0067bca0();
    void* DestroyIfFlagged(unsigned int);
    void Save_0067bec0();
    void SaveGame_0067bf40(BGSSaveFormBuffer* buffer);
};
