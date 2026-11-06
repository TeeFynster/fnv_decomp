#pragma once

#include "NiBlendInterpolator.h"

class NiBoolInterpolator;

class NiBlendBoolInterpolator : public NiBlendInterpolator
{
public:
    NiBlendBoolInterpolator(bool onlyUseHighestWeight, float weightThreshold, unsigned char arraySize);

    virtual void LoadBinary(NiStream& stream);
    virtual bool UpdateBool(float time, NiObjectNET* target, bool& value);

    bool Update(float time, NiObjectNET* target, bool& value);
    bool UpdateAccumulatedTransform(float time, NiObjectNET* target, bool& value);
    bool UpdateSingleInterpolator(float time, NiObjectNET* target, bool& value);
    unsigned char FindHighestWeightIndex();
    NiBoolInterpolator* GetValueForIndex(unsigned char index);

    unsigned char m_bBoolValue;
    unsigned char layoutPadding31[3];
};
