// Unit-local PC header for fallout_shared/tesweather.cpp.
// Weather-specific declarations not yet supplied by the shared headers.
#ifndef FNV_TESWEATHER_DECLS_H
#define FNV_TESWEATHER_DECLS_H

#include "layout_support.h"
#include "BaseFormComponent.h"
#include "../../include/TESForm.h"
#include "../../include/TESTexture.h"

class TESWeather__WeatherSound;

template <int N> struct EndianSizeTag
{
};
void BSEndian(unsigned int*, EndianSizeTag<4>);
void BSEndian(int*, EndianSizeTag<4>);
void BSEndian(float*, EndianSizeTag<4>);
class TESWeather__WeatherSound
{
  public:
    unsigned int formID;
    unsigned int type;
    TESWeather__WeatherSound();
    void TwoValues_Endian();
};
void* __cdecl operator new(unsigned int);
extern "C" void* memset(void* dst, int val, unsigned int size);
void __cdecl operator delete(void* ptr);

#endif
