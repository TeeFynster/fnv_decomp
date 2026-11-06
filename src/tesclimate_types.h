// Unit-private weather entries and APIs not yet declared by the shared headers.
#ifndef FNV_TESCLIMATE_TYPES_H
#define FNV_TESCLIMATE_TYPES_H

extern int __cdecl Warning();
extern unsigned int __cdecl SetWarningState(bool);
class WeatherEntry
{
  public:
    TESWeather* m_pWeatherObject;
    unsigned int m_uiWeatherChance;
    TESGlobal* m_pWeatherChanceGlobal;
    WeatherEntry();
};
#include "../include/TESWeatherList.h"
#include "../include/TESClimate.h"
FNV_STATIC_ASSERT(sizeof(TESModel) == 24);
FNV_STATIC_ASSERT(sizeof(TESTexture) == 12);
FNV_STATIC_ASSERT(sizeof(TESWeatherList) == 8);
FNV_STATIC_ASSERT(sizeof(WeatherEntry) == 12);
FNV_STATIC_ASSERT(sizeof(TESClimate) == 88);
FNV_STATIC_ASSERT(offsetof(TESClimate, m_kStarsModel) == 24);
FNV_STATIC_ASSERT(offsetof(TESClimate, weatherList) == 48);
FNV_STATIC_ASSERT(offsetof(TESClimate, m_kSunTextures) == 56);
FNV_STATIC_ASSERT(offsetof(TESClimate, m_ucTimeSettings) == 80);
extern int __cdecl Warning(const char* format, ...);
#endif

