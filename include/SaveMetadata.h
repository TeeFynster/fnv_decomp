#pragma once

#pragma pack(push, 2)
class SaveMetadata
{
public:
    union
    {
        void* layoutPointer;
        struct
        {
            unsigned short m_usFootIndexCount;
            unsigned short m_usLegDataCount;
            unsigned short m_usHeadDataCount;
            unsigned short m_usGrabArmDataCount;
            bool m_bRagdollAnimationEnabled;
            bool m_bFootIKEnabled;
            bool m_bLookIKEnabled;
            bool m_bGrabIKEnabled;
            bool m_bRagdollFeedbackEnabled;
            unsigned char layoutPaddingD[1];
        };
    };

    void SwapEndianFourShorts();
};
#pragma pack(pop)
