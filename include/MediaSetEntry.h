#pragma once

#include "TESFullName.h"

class MediaSetEntry
{
public:
    BSStringT<char> Name;
    float Attenuation;
    float Percent;

    MediaSetEntry();
    ~MediaSetEntry();
    void Reset();
};
