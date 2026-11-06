#pragma once

namespace ActorValue
{
    enum Index;
}

class TESClassData
{
public:
    ActorValue::Index m_aeTaggedSkills[4];
    char m_ucClassFlags;
    unsigned char layoutPadding11[3];
    int m_uiField08;
    unsigned char m_ucField0C;
    unsigned char m_ucField0D;
    unsigned char layoutPadding1A[2];

    void SwapEndian();
};
