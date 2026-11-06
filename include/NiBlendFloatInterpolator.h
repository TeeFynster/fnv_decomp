#pragma once

#include "NiBlendInterpolator.h"

class NiBlendFloatInterpolator : public NiBlendInterpolator
{
public:
    NiBlendFloatInterpolator(bool onlyUseHighestWeight, float weightThreshold, unsigned char arraySize);

    virtual void LoadBinary(NiStream& stream);
    virtual bool UpdateFloat(float time, NiObjectNET* target, float& value);

    bool Update(float time, NiObjectNET* target, float& value);
    bool UpdateAccumulatedTransform(float time, NiObjectNET* target, float& value);
    bool UpdateSingleInterpolator(float time, NiObjectNET* target, float& value);

    float m_fFloatValue;
};
