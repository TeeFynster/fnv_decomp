#pragma once

#include "MagicTarget.h"

class TESWeather__WeatherSound;

class TESWeather__WeatherSoundList : public BSSimpleList<TESWeather__WeatherSound*>
{
public:
    TESWeather__WeatherSoundList();
    void ClearWeatherSounds();
};
