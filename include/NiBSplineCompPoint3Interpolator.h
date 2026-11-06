#pragma once

#include "NiBSplinePoint3Interpolator.h"

class NiBSplineCompPoint3Interpolator : public NiBSplinePoint3Interpolator
{
public:
    virtual void LoadBinary(NiStream& stream);

    float m_fSequenceOffset;
    float m_fDecodeScale;
};
