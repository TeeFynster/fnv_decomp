#pragma once

class ArmorData
{
public:
    unsigned short m_usArmorRating;
    unsigned char layoutPadding2[2];
    float fArmorProtectionValue;
    unsigned char cFlags;
    unsigned char m_ucSubtype;
    unsigned char layoutPaddingA[2];
};
