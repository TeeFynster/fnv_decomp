#pragma once

#include "NiPoint2.h"

class ImageSpaceModifierEffectData
{
public:
    bool m_bOverride;
    float fDuration;
    unsigned int m_auiKeyframeCountsByTypeAndChannel[21][2];
    unsigned int m_uiEffectEntryCountFirst;
    unsigned int m_uiEffectEntryCountSecond;
    unsigned int m_uiEffectEntryCountThird;
    unsigned int m_uiEffectEntryCountFourth;
    unsigned int m_uiEffectEntryCountFifth;
    unsigned int m_uiEffectEntryCountSixth;
    bool m_bUseRadialBlur;
    NiPoint2 m_kRadialBlurCenter;
    unsigned int m_uiEffectEntryCountSeventh;
    unsigned int m_uiEffectEntryCountEighth;
    unsigned int m_uiEffectEntryCountNinth;
    bool m_bUseEffectEntries;
    unsigned char m_ucEffectMode;
    unsigned int m_uiEffectEntryCountTenth;
    unsigned int m_uiEffectEntryCountEleventh;
    unsigned int m_uiEffectEntryCountTwelfth;
    unsigned int m_uiEffectEntryCountThirteenth;

    ImageSpaceModifierEffectData();
    void Endian();
};
