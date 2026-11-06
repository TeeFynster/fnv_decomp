#pragma once

#include "NiBSplineInterpolator.h"

class NiBSplineFloatInterpolator : public NiBSplineInterpolator
{
  public:
    virtual void LoadBinary(NiStream& stream);

    float m_fFloatValue;
    unsigned int m_kFloatCPHandle;
};
