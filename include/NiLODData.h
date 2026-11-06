#pragma once

#include "NiObject.h"
#include <cstddef>

class NiLODData : public NiObject
{
  public:
    NiLODData();
    virtual ~NiLODData();

    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();

    unsigned int Write(const void* buffer, unsigned int count);
};
