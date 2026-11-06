#pragma once

class PoseMatching_DATA__PoseMatching_System_DATA
{
public:
    short m_sFirstRagdollFeedbackIndex;
    short m_sSecondRagdollFeedbackIndex;
    short m_sThirdRagdollFeedbackIndex;
    bool ShortTripleFloatPairRecord;
    unsigned char layoutPadding7[1];
    float ShortFlagFloatRecord;
    float FourFloatRecord;
    float FourFloatParameterBlock;
    float m_fFourthParameter;
};
