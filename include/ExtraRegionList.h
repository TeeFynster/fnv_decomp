#pragma once

#include "BSExtraData.h"

class RegionList;

class ExtraRegionList : public BSExtraData
{
public:
    ExtraRegionList(RegionList* value);

    RegionList* regions;
};
