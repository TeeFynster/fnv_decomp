// fallout_shared/region system/tesregiondataweather.cpp: TESRegionDataWeather (8 functions)

#include "tesregiondataweather_decls.h"
#include "../../../include/TESRegionDataWeather.h"
#include "../../../include/TESForm.h"

// These adapters declare entry points missing from the shared base/list headers.
// They add no data members or virtual slots to the shared layouts.
struct RegionDataAccess : TESRegionData
{
    bool GetOverride();
    unsigned char GetPriority();
};

struct WeatherListAccess : TESWeatherList
{
    void WriteWeatherList(unsigned int);
    void CopyWeatherList(TESWeatherList*, int);
    bool IsEmpty();
};

// @fnv 0x004f51f0
void TESRegionDataWeather::LoadWeatherData(TESFile* file, TESRegion* region)
{
    int warnings = Warning();
    SetWarningState(true);
    TESWeatherList::LoadWeatherEntries(&weatherList, file, region);
    SetWarningState(false);
    if (Warning() > warnings && region)
        Warning("Warnings were encountered while loading weather list chunk from region %s", region->GetName());
}

// Also emits the scalar deleting destructor at 0x004f50b0.
// @fnv 0x004f5040
TESRegionDataWeather::TESRegionDataWeather()
{}

// @fnv 0x004f51c0
void TESRegionDataWeather::Save()
{
    TESRegionData::Save();
    static_cast<WeatherListAccess*>(&weatherList)->WriteWeatherList(0x54574452);
}

void* __cdecl operator new(unsigned int);
// @fnv 0x004f5260
TESRegionData* TESRegionDataWeather::Clone()
{
    TESRegionDataWeather* pdata = new TESRegionDataWeather(*this);
    return pdata;
}

// @fnv 0x004f52e0
TESRegionData* TESRegionDataWeather::CopyFrom(const TESRegionData* apRegionData)
{
    TESRegionData* pdata = Clone();
    pdata->SetFromData(apRegionData, 2);
    return pdata;
}

// @fnv 0x004f5570
bool TESRegionDataWeather::IsValid()
{
    return !static_cast<WeatherListAccess*>(&weatherList)->IsEmpty();
}

double _floor(float);
// @fnv 0x004f5320
void TESRegionDataWeather::SetFromData(const TESRegionData* apOther, unsigned int enabled)
{
    TESRegionDataWeather* other = (TESRegionDataWeather*)apOther;
    if (!apOther || const_cast<TESRegionData*>(apOther)->GetType() != 3 || !enabled)
        return;
    if (m_bHasRegionData)
    {
        reinterpret_cast<TESForm*>(this)->SetFormType(static_cast<ENUM_FORM_ID>(reinterpret_cast<RegionDataAccess*>(other)->GetOverride()));
        SetPriority(reinterpret_cast<RegionDataAccess*>(other)->GetPriority());
        static_cast<WeatherListAccess*>(&weatherList)->CopyWeatherList(&other->weatherList, 0);
    }
    else if (other->m_bHasRegionData)
    {
        return;
    }
    else if (bOverride)
    {
        if (reinterpret_cast<RegionDataAccess*>(other)->GetOverride() && reinterpret_cast<RegionDataAccess*>(other)->GetPriority() > reinterpret_cast<RegionDataAccess*>(this)->GetPriority())
        {
            reinterpret_cast<TESForm*>(this)->SetFormType(static_cast<ENUM_FORM_ID>(reinterpret_cast<RegionDataAccess*>(other)->GetOverride()));
            SetPriority(reinterpret_cast<RegionDataAccess*>(other)->GetPriority());
            static_cast<WeatherListAccess*>(&weatherList)->CopyWeatherList(&other->weatherList, 0);
        }
        return;
    }
    else if (reinterpret_cast<RegionDataAccess*>(other)->GetOverride())
    {
        reinterpret_cast<TESForm*>(this)->SetFormType(static_cast<ENUM_FORM_ID>(reinterpret_cast<RegionDataAccess*>(other)->GetOverride()));
        SetPriority(reinterpret_cast<RegionDataAccess*>(other)->GetPriority());
        static_cast<WeatherListAccess*>(&weatherList)->CopyWeatherList(&other->weatherList, 0);
    }
    else
    {
        static_cast<WeatherListAccess*>(&weatherList)->CopyWeatherList(&other->weatherList, 1);
        float weight = reinterpret_cast<RegionDataAccess*>(this)->GetPriority() * reinterpret_cast<RegionDataAccess*>(this)->GetPriority() + (100 - reinterpret_cast<RegionDataAccess*>(this)->GetPriority()) * reinterpret_cast<RegionDataAccess*>(other)->GetPriority();
        weight += (100 - reinterpret_cast<RegionDataAccess*>(other)->GetPriority()) * reinterpret_cast<RegionDataAccess*>(this)->GetPriority() + reinterpret_cast<RegionDataAccess*>(other)->GetPriority() * reinterpret_cast<RegionDataAccess*>(other)->GetPriority();
        weight *= 0.004999999888241291;
        SetPriority((unsigned char)_floor(weight));
    }
}
