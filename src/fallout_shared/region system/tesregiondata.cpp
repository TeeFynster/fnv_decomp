// fallout_shared/region system/tesregiondata.cpp: TESRegionData (8 functions)

#include "tesregiondata_decls.h"
#include "../../../include/TESForm.h"
#include "../../../include/TESRegionData.h"

// Copies the override form type and priority from the given data into this region data, returning false if data is null.
// @fnv 0x004f1560
bool TESRegionData::ApplyEntry(RegionDataEntry* data)
{
    if (!data)
        return false;
    reinterpret_cast<TESForm*>(this)->SetFormType(static_cast<ENUM_FORM_ID>(data->bOverride));
    SetPriority(data->m_ucRegionPriority);
    return true;
}

// Initializes the override, data-present flag and priority.
// @fnv 0x004f1400
TESRegionData::TESRegionData()
{
    bOverride = false;
    m_ucRegionPriority = 50;
    m_bHasRegionData = false;
}

// Sets the priority when it is at most 100.
// @fnv 0x004f15c0
bool TESRegionData::SetPriority(unsigned char acPriority)
{
    if (acPriority <= 100)
    {
        m_ucRegionPriority = acPriority;
        return true;
    }
    return false;
}

// Also emits the scalar deleting destructor at 0x004f1430.
// @fnv 0x004f14a0
TESRegionData::~TESRegionData()
{
}

// @fnv 0x004f15a0
void TESForm::SetFormType(ENUM_FORM_ID aType)
{
    cFormType = static_cast<unsigned char>(aType);
}

// @fnv 0x004f1460
TESRegionData::TESRegionData(const TESRegionData& other)
{
    bOverride = other.bOverride;
    m_ucRegionPriority = other.m_ucRegionPriority;
    m_bHasRegionData = other.m_bHasRegionData;
}

#include <string.h>
bool __cdecl TESForm_QEndianSwapOnSave();
void __cdecl AppendChunk(unsigned int, const void*, unsigned int);

struct RegionSaveData
{
    unsigned int m_eRegionDataId;
    bool bOverride;
    unsigned char m_ucRegionPriority;
    unsigned short unk06;
    void QuestPerkEntryData_Endian();
};

// Getter entry points not yet declared by the shared header.
// This helper adds no data or virtual slots to the shared layout.
struct RegionDataAccess : TESRegionData
{
    bool TESRegionData_GetOverride();
    unsigned char TESRegionData_GetPriority();
};

// @fnv 0x004f14c0
void TESRegionData::Save()
{
    RegionSaveData data;
    memset(&data, 0, sizeof(data));
    data.m_eRegionDataId = static_cast<unsigned int>(GetType());
    data.bOverride = static_cast<RegionDataAccess*>(this)->TESRegionData_GetOverride();
    data.m_ucRegionPriority = static_cast<RegionDataAccess*>(this)->TESRegionData_GetPriority();
    if (TESForm_QEndianSwapOnSave())
        data.QuestPerkEntryData_Endian();
    AppendChunk(0x54414452, &data, sizeof(data));
    if (TESForm_QEndianSwapOnSave())
        data.QuestPerkEntryData_Endian();
}
