#pragma once

#include "MagicTarget.h"

class TESRegion;

class __declspec(align(8)) TESRegionList : public BSSimpleList<TESRegion *>
{
public:
    TESRegionList(int);
    virtual ~TESRegionList();

    bool AddRegion(TESRegion* apRegion);
};
