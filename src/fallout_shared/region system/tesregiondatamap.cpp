#include "../../../include/BSStringT.h"
// fallout_shared/region system/tesregiondatamap.cpp: TESRegionDataMap, RegionMapMerge (11 functions)

// include/TESFile.h needs the Windows types before layout_support.h stubs them.
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "layout_support.h"
#include "TESFile.h"
#include "../../../include/StrMem.h"
#include <malloc.h>

#include "../../../include/TESRegionData.h"
#include "../../../include/TESRegionDataMap.h"

// These entry points are not declared by the shared map header yet.
// The helper inherits the shared layout and adds no data or virtual slots.
struct RegionMapMerge : TESRegionDataMap
{
    bool TESRegionData_GetOverride();
    void FUN_004f15a0(bool value);
    unsigned char TESRegionData_GetPriority();
    bool FUN_004f15c0(unsigned char value);
    void SaveMapData();
    TESRegionData* CreateRegionData() const;
    void MergeMapData(RegionMapMerge* data, void* context);
};

// Reads the RDMP chunk from apFile into a buffer and stores it in the map string, returning true on success.
// @fnv 0x004f3e90
bool TESRegionDataMap::LoadRegionMapData(TESFile* apFile)
{
    if (!apFile || apFile->GetChunkID() != CHUNK_ID_RDMP_ID)
        return false;

    char* pChunkData = (char*)_alloca(apFile->GetChunkSize());
    apFile->GetChunkData(pChunkData, 0);
    m_kMapName.Set(pChunkData, 0);
    return true;
}

// @fnv 0x005585e0
const char* TESRegionDataMap::GetRegionMapName()
{
    return m_kMapName.String();
}

// Constructs the object and sets its string member to "Default Region Name".
// @fnv 0x004f3ca0
TESRegionDataMap::TESRegionDataMap()
{
    m_kMapName.Set("Default Region Name", 0);
}

struct S7010
{
    unsigned int Length();
};
struct Flt
{
    operator unsigned int();
};
struct H4280
{
    unsigned int GetLengthPlusOne();
};
void __cdecl TESForm_AddChunkArray(unsigned int, void*, unsigned int);
// @fnv 0x004f3e40
void RegionMapMerge::SaveMapData()
{
    TESRegionData::Save();
    if (((S7010*)&m_kMapName)->Length())
        TESForm_AddChunkArray(0x504D4452, (void*)(unsigned int)*(Flt*)&m_kMapName,
                     ((H4280*)&m_kMapName)->GetLengthPlusOne());
}

// @fnv 0x004f3f10
void TESRegionDataMap::vf10(BSStringT<char>& apMapName)
{
    apMapName.Set(m_kMapName.String(), 0);
}


// @fnv 0x004f3f40
bool TESRegionDataMap::vf12(char const* apMapName)
{
    if (((::BSStringT<char>*)&m_kMapName)->StrCmp(apMapName, true))
    {
        m_kMapName.Set(apMapName, 0);
        return true;
    }
    return false;
}

// @fnv 0x004f3de0
TESRegionDataMap::~TESRegionDataMap()
{
}

void* __cdecl operator new(unsigned int);

// @fnv 0x004f3f80
TESRegionData* RegionMapMerge::CreateRegionData() const
{
    TESRegionData* pdata = new TESRegionDataMap(this);
    return pdata;
}

// Constructs the object from a source, initializing the base with it and copying its map name.
// @fnv 0x004f3d50
TESRegionDataMap::TESRegionDataMap(const TESRegionDataMap* apSource) : TESRegionData(*apSource)
{
    TESRegionDataMap::vf12(const_cast<TESRegionDataMap*>(apSource)->GetRegionMapName());
}

float __cdecl floor(float value);

// @fnv 0x004f4000
void RegionMapMerge::MergeMapData(RegionMapMerge* apOther, void* context)
{
    RegionMapMerge* other = apOther;
    if (!apOther || (unsigned int)apOther->GetType() != 4 || !context)
        return;
    if (m_bHasRegionData)
    {
        FUN_004f15a0(other->TESRegionData_GetOverride());
        FUN_004f15c0(other->TESRegionData_GetPriority());
        vf12(other->GetRegionMapName());
    }
    else if (other->m_bHasRegionData)
    {
        return;
    }
    else if (bOverride)
    {
        if (other->TESRegionData_GetOverride() && other->TESRegionData_GetPriority() > TESRegionData_GetPriority())
        {
            FUN_004f15a0(other->TESRegionData_GetOverride());
            FUN_004f15c0(other->TESRegionData_GetPriority());
            vf12(other->GetRegionMapName());
        }
        return;
    }
    else if (other->TESRegionData_GetOverride())
    {
        FUN_004f15a0(other->TESRegionData_GetOverride());
        FUN_004f15c0(other->TESRegionData_GetPriority());
        vf12(other->GetRegionMapName());
    }
    else
    {
        if (other->TESRegionData_GetPriority() > TESRegionData_GetPriority())
            vf12(other->GetRegionMapName());
        float priority = TESRegionData_GetPriority() * TESRegionData_GetPriority() + (100 - TESRegionData_GetPriority()) * other->TESRegionData_GetPriority();
        priority += (100 - other->TESRegionData_GetPriority()) * TESRegionData_GetPriority() + other->TESRegionData_GetPriority() * other->TESRegionData_GetPriority();
        priority *= 0.005f;
        FUN_004f15c0((unsigned char)floor(priority));
    }
}
