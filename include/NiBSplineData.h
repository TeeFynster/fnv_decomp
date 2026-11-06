#pragma once

#include "NiObject.h"

class NiBSplineBasisData;

class NiBSplineData : public NiObject
{
  public:
    virtual void LoadBinary(NiStream& stream);

    void ReadGroup(NiStream& stream);
    void CalculateSplineValue(float, float*, unsigned int, NiBSplineBasisData*, unsigned int, float, float);

    float* m_pfControlPoints;
    short* m_psCompactControlPoints;
    unsigned int m_uiControlPointCount;
    unsigned int m_uiCompactControlPointCount;
};
