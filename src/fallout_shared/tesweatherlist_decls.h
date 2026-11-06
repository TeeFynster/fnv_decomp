#include "../../include/BSSimpleList.h"
// fallout_shared/tesweatherlist_decls.h: declares WeatherEntry, TESWeatherList, ContainerItemExtraFileData
#ifndef FNV_TESWEATHERLIST_DECLS_H
#define FNV_TESWEATHERLIST_DECLS_H


#include "layout_support.h"

#include "../../include/TESForm.h"
#include "../../include/TESGlobal.h"

class TESWeather;

class WeatherEntry
{
  public:
    TESWeather* m_weather;
    unsigned int m_uiFilterValue;
    TESGlobal* m_otherWeather;
    WeatherEntry();
};



// after the unit's BSSimpleList<WeatherEntry*> specialization above
#include "../../include/TESWeatherList.h"

class FUN_00582570
{
  public:
    unsigned int m_unk00;
    unsigned int m_unk04;
    unsigned int m_unk08;
    FUN_00582570();
};

class ContainerItemExtraFileData
{
  public:
    unsigned int m_unk00;
    unsigned int m_unk04;
    unsigned int m_unk08;
    void Endian();
};

int __cdecl CompareSecondElement(WeatherEntry* left, WeatherEntry* right);
int __cdecl Warning(const char* format, ...);
extern "C" void* __cdecl __RTDynamicCast(void* object, long vfDelta, void* sourceType, void* targetType,
                                         int isReference);
extern "C" const char DAT_010318b4[];
extern "C" const char DAT_01031858[];
extern "C" const char DAT_0118629c[];

void* __cdecl operator new(unsigned int);
void* __cdecl operator new[](unsigned int);
void __cdecl operator delete(void* pointer);
void __cdecl operator delete[](void* pointer);
extern "C" const char DAT_01183028[];
extern "C" const char DAT_01183ad4[];

#endif
