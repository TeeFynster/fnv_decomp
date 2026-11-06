#pragma once

#include "NiTriBasedGeom.h"

class NiTriStripsData;

class NiTriStrips : public NiTriBasedGeom
{
  public:
    NiTriStrips() throw();
    NiTriStrips(NiTriStripsData* data);
    virtual ~NiTriStrips() throw();

};
