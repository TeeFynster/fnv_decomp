#pragma once

#include "NiBSplineFloatInterpolator.h"

class NiBSplineCompFloatInterpolator : public NiBSplineFloatInterpolator
{
  public:
    virtual void LoadBinary(NiStream&);

    float m_afOffsetAndHalfRange[2];
};
