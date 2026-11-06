#pragma once

class TESRegion;
class TESRegionData;
class RegionDataBlock;
class TESRegionDataWeather;
class TESRegionDataMap;
class TESRegionDataLandscape;
class TESRegionDataGrass;
class TESRegionDataSound;
class TESRegionDataImposter;
class TESFile;
enum REGION_DATA_ID;

class TESRegionDataManager
{
public:
    TESRegion* m_pLastLoadedRegion;

    virtual TESRegion* GetLastLoadedRegion();
    virtual TESRegionData* GetRegionDataForID(REGION_DATA_ID aeID);
    virtual RegionDataBlock* GetRegionDataBlock(TESRegionData* apData);
    virtual TESRegionDataWeather* GetRegionDataWeather(TESRegionData* apData);
    virtual TESRegionDataMap* GetRegionDataMap(TESRegionData* apData);
    virtual TESRegionDataLandscape* GetRegionDataLandscape(TESRegionData* apData);
    virtual TESRegionDataGrass* GetRegionDataGrass(TESRegionData* apData);
    virtual TESRegionDataSound* GetRegionDataSound(TESRegionData* apData);
    virtual TESRegionDataImposter* GetRegionDataImposter(TESRegionData* apData);
    virtual bool ApplyEntry(TESFile* apFile, TESRegion* apRegion);
};
