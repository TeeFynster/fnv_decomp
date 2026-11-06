#pragma once

#include "NiExtraData.h"

class NiIntegerExtraData : public NiExtraData
{
  public:
    virtual void LoadBinary(NiStream& stream);

    int m_iValue;
};
