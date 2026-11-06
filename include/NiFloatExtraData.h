#pragma once

#include "NiExtraData.h"

class NiFloatExtraData : public NiExtraData
{
  public:
    void* Destroy(unsigned int flags);

    float m_fValue;
};
