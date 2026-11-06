#pragma once

#include "BaseProcess.h"

enum BGSImpactData__ORIENTATION;

class BGSImpactData__IMPACT_DATA_DATA
{
public:
    float m_fEffectDuration;
    BGSImpactData__ORIENTATION m_eOrientation;
    float m_fAngleThreshold;
    float m_fPlacementRadius;
    SOUND_LEVEL m_eSoundLevel;
    unsigned char cFlags;
    unsigned char layoutPadding15[3];

    void Endian();
};
