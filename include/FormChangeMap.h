#pragma once

#include "nitmapbase_FormMap.h"

class FormChangeMap
{
public:
    nitmapbase_FormMap first;
    nitmapbase_FormMap second;

    FormChangeMap();
    ~FormChangeMap();
    unsigned int GetCombinedFlags();
    bool RemoveForm(unsigned int index);
};
