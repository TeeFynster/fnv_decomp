#pragma once

#include "BSSimpleList.h"

class TESFile;
class TESForm;
class WeatherEntry;

// A list of WeatherEntry (8 bytes, src: XBOX_PDB size): the constructor 0x005822c0 runs the list constructor 0x0096a2d0
// on +0, then ClearWeatherSounds.
class TESWeatherList : public BSSimpleList<WeatherEntry*>
{
public:
    TESWeatherList();
    ~TESWeatherList();

    void ClearWeatherSounds();
    void CopyWeatherList(const TESWeatherList*, bool);
    bool IsDifferentFrom(TESWeatherList*);
    void WriteWeatherList(unsigned int);
    static void LoadWeatherEntries(TESWeatherList* weatherList, TESFile* file, TESForm* form);
};
