#pragma once

#include "../../../../include/NiInterpolator.h"

#pragma pack(push, 4)
class NiBlendInterpolator__InterpArrayItem
{
  public:
    NiInterpolator* m_spControllerInterpolator;
    float m_fWeight;
    float m_fNormalizedWeight;
    char m_cPriority;
    unsigned char layoutPaddingD[3];
    float m_fEaseSpinner;
    float m_fLastEvaluationTime;
};
#pragma pack(pop)

