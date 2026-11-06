#pragma once

#include "TESFullName.h"
#include "PoseMatching_DATA__PoseMatching_System_DATA.h"

class RagdollFeedbackProfile
{
public:
    RagdollFeedbackProfile();
    ~RagdollFeedbackProfile();

    bool bEnabled;
    unsigned char layoutPadding1[3];
    BSStringT<char> m_kAnimationFileName;
    PoseMatching_DATA__PoseMatching_System_DATA m_kRagdollFeedbackData;
};
