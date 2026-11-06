// fallout_shared/region system/tesregiondatamanager.cpp: TESRegionDataManager, RegionDataManager_StandIn, MyMgr (9 functions)

#include <windows.h>
#include "layout_support.h"
// layout_support.h supplies the list template used by the shared region headers.
#define FNV64_BSSIMPLELIST_DEFINED
#include "../../../include/TESFile.h"
#include "../../../include/TESForm.h"
#include <cstring>
#include "../../../include/RegionMusicData.h"
#include "../../../include/TESRegion.h"
#include "../../../include/TESRegionDataImposter.h"
#include "../../../include/TESRegionDataMap.h"
#include "../../../include/TESRegionDataSound.h"
#include "../../../include/TESRegionData.h"
#include "../../../include/TESRegionDataGrass.h"
#include "../../../include/TESRegionDataLandscape.h"
#include "../../../include/TESRegionDataManager.h"
#include "../../../include/TESRegionDataWeather.h"
#include "../../../include/TESWeatherList.h"

class RegionDataBlock;
class TESRegionGrassObjectList;
class WeatherEntry;
class TESTexture;

enum REGION_DATA_ID
{
    REGION_DATA_ID_REGION_DATA_NONE = 0,
    REGION_DATA_ID_REGION_DATA_GENERAL_ID = 1,
    REGION_DATA_ID_REGION_DATA_OBJECTS_ID = 2,
    REGION_DATA_ID_REGION_DATA_WEATHER_ID = 3,
    REGION_DATA_ID_REGION_DATA_MAP_ID = 4,
    REGION_DATA_ID_REGION_DATA_LANDSCAPE_ID = 5,
    REGION_DATA_ID_REGION_DATA_GRASS_ID = 6,
    REGION_DATA_ID_REGION_DATA_SOUND_ID = 7,
    REGION_DATA_ID_REGION_DATA_IMPOSTER_ID = 8,
    REGION_DATA_ID_REGION_DATA_COUNT = 9
};

class RegionDataEntry
{
  public:
    REGION_DATA_ID m_eRegionDataId;    // +0x0, 4 bytes
    bool bOverride;                    // +0x4, 1 bytes
    unsigned char m_ucRegionPriority;  // +0x5, 1 bytes
    // +0x6, 2 bytes compiler padding, unnamed in source
    void Endian();
};
FNV_STATIC_ASSERT(sizeof(RegionDataEntry) == 8);
FNV_STATIC_ASSERT(offsetof(RegionDataEntry, m_eRegionDataId) == 0);
FNV_STATIC_ASSERT(offsetof(RegionDataEntry, bOverride) == 4);
FNV_STATIC_ASSERT(offsetof(RegionDataEntry, m_ucRegionPriority) == 5);

FNV_STATIC_ASSERT(sizeof(TESRegionData) == 8);
FNV_STATIC_ASSERT(offsetof(TESRegionData, bOverride) == 4);
FNV_STATIC_ASSERT(offsetof(TESRegionData, m_bHasRegionData) == 5);
FNV_STATIC_ASSERT(offsetof(TESRegionData, m_ucRegionPriority) == 6);


FNV_STATIC_ASSERT(sizeof(TESRegionDataWeather) == 16);
FNV_STATIC_ASSERT(offsetof(TESRegionDataWeather, weatherList) == 8);

FNV_STATIC_ASSERT(sizeof(TESRegionDataMap) == 16);
FNV_STATIC_ASSERT(offsetof(TESRegionDataMap, m_kMapName) == 8);

FNV_STATIC_ASSERT(sizeof(TESRegionDataLandscape) == 12);
FNV_STATIC_ASSERT(offsetof(TESRegionDataLandscape, m_pLandscapeTexture) == 8);

FNV_STATIC_ASSERT(sizeof(TESRegionDataGrass) == 12);
FNV_STATIC_ASSERT(offsetof(TESRegionDataGrass, m_pObjectList) == 8);

FNV_STATIC_ASSERT(sizeof(RegionMusicData) == 24);
FNV_STATIC_ASSERT(offsetof(RegionMusicData, pType) == 0);
FNV_STATIC_ASSERT(offsetof(RegionMusicData, soundList) == 4);
FNV_STATIC_ASSERT(offsetof(RegionMusicData, uiIncidentalMediaSet) == 12);
FNV_STATIC_ASSERT(offsetof(RegionMusicData, battleMediaSetList) == 16);

FNV_STATIC_ASSERT(sizeof(TESRegionDataSound) == 32);
FNV_STATIC_ASSERT(offsetof(TESRegionDataSound, sounds) == 8);

FNV_STATIC_ASSERT(sizeof(TESRegionDataImposter) == 16);
FNV_STATIC_ASSERT(offsetof(TESRegionDataImposter, imposters) == 8);

class RegionDataList : public BSSimpleList<TESRegionData*>
{
  protected:
    bool m_bDataFlag;
};


FNV_STATIC_ASSERT(sizeof(TESRegionDataManager) == 8);
FNV_STATIC_ASSERT(offsetof(TESRegionDataManager, m_pLastLoadedRegion) == 4);

TESRegionData* g_pLastLoadedRegionData;

template <class T> void BSSimpleList<T>::AddHead(T& item)
{
    if (!item)
        return;
    if (m_item)
    {
        BSSimpleList<T>* node = new BSSimpleList<T>(m_item);
        node->m_pkNext = m_pkNext;
        m_pkNext = node;
        m_item = item;
    }
    else
        m_item = item;
}

// Allocates and returns a new TESRegionData subclass instance matching the given REGION_DATA_ID, or null for unknown IDs.
// @fnv 0x004f3690
TESRegionData* TESRegionDataManager::GetRegionDataForID(REGION_DATA_ID aeID)
{
    TESRegionData* pData = 0;
    switch (aeID)
    {
    case REGION_DATA_ID_REGION_DATA_WEATHER_ID:
        pData = new TESRegionDataWeather;
        break;
    case REGION_DATA_ID_REGION_DATA_MAP_ID:
        pData = new TESRegionDataMap;
        break;
    case REGION_DATA_ID_REGION_DATA_LANDSCAPE_ID:
        pData = new TESRegionDataLandscape;
        break;
    case REGION_DATA_ID_REGION_DATA_GRASS_ID:
        pData = new TESRegionDataGrass;
        break;
    case REGION_DATA_ID_REGION_DATA_SOUND_ID:
        pData = new TESRegionDataSound;
        break;
    case REGION_DATA_ID_REGION_DATA_IMPOSTER_ID:
        pData = new TESRegionDataImposter;
        break;
    }
    return pData;
}

// Returns apData cast to TESRegionDataWeather if it is non-null and of the weather region data type, otherwise returns 0.
// @fnv 0x004f38e0
TESRegionDataWeather* TESRegionDataManager::GetRegionDataWeather(TESRegionData* apData)
{
    if (!apData || apData->GetType() != REGION_DATA_ID_REGION_DATA_WEATHER_ID)
        return 0;
    return static_cast<TESRegionDataWeather*>(apData);
}

// Returns apData cast to TESRegionDataMap if it is non-null and its type is REGION_DATA_ID_REGION_DATA_MAP_ID, otherwise returns 0.
// @fnv 0x004f3910
TESRegionDataMap* TESRegionDataManager::GetRegionDataMap(TESRegionData* apData)
{
    if (!apData || apData->GetType() != REGION_DATA_ID_REGION_DATA_MAP_ID)
        return 0;
    return static_cast<TESRegionDataMap*>(apData);
}

// Returns apData cast to TESRegionDataLandscape if its type is REGION_DATA_ID_REGION_DATA_LANDSCAPE_ID, otherwise null.
// @fnv 0x004f3940
TESRegionDataLandscape* TESRegionDataManager::GetRegionDataLandscape(TESRegionData* apData)
{
    if (!apData || apData->GetType() != REGION_DATA_ID_REGION_DATA_LANDSCAPE_ID)
        return 0;
    return static_cast<TESRegionDataLandscape*>(apData);
}

// Returns apData cast to TESRegionDataSound if it is non-null and its type is REGION_DATA_ID_REGION_DATA_SOUND_ID, otherwise returns 0.
// @fnv 0x004f39a0
TESRegionDataSound* TESRegionDataManager::GetRegionDataSound(TESRegionData* apData)
{
    if (!apData || apData->GetType() != REGION_DATA_ID_REGION_DATA_SOUND_ID)
        return 0;
    return static_cast<TESRegionDataSound*>(apData);
}

// Returns apData cast to TESRegionDataImposter if it is non-null and of type REGION_DATA_ID_REGION_DATA_IMPOSTER_ID, otherwise returns 0.
// @fnv 0x004f39d0
TESRegionDataImposter* TESRegionDataManager::GetRegionDataImposter(TESRegionData* apData)
{
    if (!apData || apData->GetType() != REGION_DATA_ID_REGION_DATA_IMPOSTER_ID)
        return 0;
    return static_cast<TESRegionDataImposter*>(apData);
}

// @fnv 0x004f3a00
bool TESRegionDataManager::ApplyEntry(TESFile* apFile, TESRegion* apRegion)
{
    if (!apFile || !apRegion)
        return false;
    m_pLastLoadedRegion = apRegion;
    RegionDataEntry kBase;
    switch ((int)apFile->GetChunkID())
    {
    case CHUNK_ID_RDAT_ID:
        memset(&kBase, 0, sizeof(kBase));
        apFile->GetChunkData(&kBase, sizeof(kBase));
        if (apFile->IsEndianConversionRequired())
            kBase.Endian();
        g_pLastLoadedRegionData = GetRegionDataForID(kBase.m_eRegionDataId);
        if (g_pLastLoadedRegionData)
        {
            g_pLastLoadedRegionData->ApplyEntry(&kBase);
            apRegion->GetDataList()->AddHead(g_pLastLoadedRegionData);
        }
        break;
    case CHUNK_ID_RDWT_ID:
        if (TESRegionDataWeather* pData = GetRegionDataWeather(g_pLastLoadedRegionData))
            pData->LoadWeatherData(apFile, apRegion);
        break;
    case CHUNK_ID_RDMP_ID:
        if (TESRegionDataMap* pData = GetRegionDataMap(g_pLastLoadedRegionData))
            pData->LoadRegionMapData(apFile);
        break;
    case CHUNK_ID_RDGS_ID:
        if (TESRegionDataGrass* pData = GetRegionDataGrass(g_pLastLoadedRegionData))
            pData->ReadGrassData(apFile);
        break;
    case CHUNK_ID_RDMD_ID:
    case CHUNK_ID_RDSB_ID:
    case CHUNK_ID_RDSD_ID:
    case CHUNK_ID_RDSI_ID:
        if (TESRegionDataSound* pData = GetRegionDataSound(g_pLastLoadedRegionData))
            pData->LoadRegionSoundData(apFile);
        break;
    case CHUNK_ID_RDLN_ID:
    case CHUNK_ID_ICON_ID:
        if (TESRegionDataLandscape* pData = GetRegionDataLandscape(g_pLastLoadedRegionData))
            pData->ReadLandscapeData(apFile);
        break;
    case CHUNK_ID_RDID_ID:
        if (TESRegionDataImposter* pData = GetRegionDataImposter(g_pLastLoadedRegionData))
            pData->ReadRegionData(apFile);
        break;
    }
    return true;
}

struct RegionDataManager_StandIn
{
    RegionDataBlock* GetRegionObjectsData(TESRegionData* apData);
};
// @fnv 0x004f38b0
RegionDataBlock* RegionDataManager_StandIn::GetRegionObjectsData(TESRegionData* apData)
{
    if (!apData || apData->GetType() != REGION_DATA_ID_REGION_DATA_OBJECTS_ID)
        return 0;
    return (RegionDataBlock*)apData;
}

struct MyMgr
{
    TESRegionDataGrass* GetGrassData(TESRegionData* apData);
};
// Returns apData cast to TESRegionDataGrass if it is non-null and its type is REGION_DATA_ID_REGION_DATA_GRASS_ID, otherwise returns 0.
// @fnv 0x004f3970
TESRegionDataGrass* MyMgr::GetGrassData(TESRegionData* apData)
{
    if (!apData || apData->GetType() != REGION_DATA_ID_REGION_DATA_GRASS_ID)
        return 0;
    return (TESRegionDataGrass*)apData;
}
