#pragma once

#include "NiBSplineInterpolator.h"
#include "NiColor.h"

class NiBSplinePoint3Interpolator : public NiBSplineInterpolator
{
public:
    virtual void LoadBinary(NiStream& stream);

    NiColor m_kPoint3Value;
    unsigned int m_kPoint3CPHandle;
};
