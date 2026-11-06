#pragma once

#include "TESRegionData.h"
#include "TESWeatherList.h"

class TESFile;
class TESRegion;

class TESRegionDataWeather : public TESRegionData
{
public:
    TESWeatherList weatherList;

    TESRegionDataWeather();
    TESRegionDataWeather(const TESRegionDataWeather& other);
    virtual ~TESRegionDataWeather();
    virtual void LoadWeatherData(TESFile* apFile, TESRegion* apRegion);
    virtual void Save();
    virtual TESRegionData* Clone();
    virtual TESRegionData* CopyFrom(const TESRegionData* apSrc);
    virtual void SetFromData(const TESRegionData* apSrc, unsigned int auFlags);
    virtual bool IsValid();
};
