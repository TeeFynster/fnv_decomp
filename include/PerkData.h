#pragma once

class PerkData
{
public:
    bool m_bTrait;
    unsigned char cLevel;
    unsigned char m_ucRankCount;
    bool bPlayable;
    bool bHidden;
    unsigned char padding[3];

    int GetType();
    unsigned char GetEntryList();
};
