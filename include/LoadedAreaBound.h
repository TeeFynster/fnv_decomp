#pragma once
#include <cstddef>
#include "NiRefObject.h"

class TESObjectCELL;

class LoadedAreaBound : public NiRefObject
{
  public:
    virtual ~LoadedAreaBound();
    void FUN_006270f0();
    void* FUN_006270c0(unsigned int flags);
    void FUN_00628da0();
    void LoadedAreaBound_Update(TESObjectCELL*, void*);
};
