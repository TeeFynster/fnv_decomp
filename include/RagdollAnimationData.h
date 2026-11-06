#pragma once

#include "BSSimpleArray.h"
#include "RagdollFeedbackData__RagdollFeedbackSystemData.h"

class RagdollAnimationData
{
public:
    RagdollAnimationData();
    ~RagdollAnimationData();

    bool bEnabled;
    unsigned char layoutPadding1[3];
    RagdollFeedbackData__RagdollFeedbackSystemData m_kRagdollFeedbackData;
    BSSimpleArray<short, 1024> m_kFootIndices;
};
