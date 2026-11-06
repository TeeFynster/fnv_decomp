#pragma once

class ActorBaseAttributes
{
public:
    int m_uiActorFlags;
    unsigned short m_usField04;
    unsigned short m_usField06;
    unsigned short sLevel;
    unsigned short m_usField0A;
    unsigned short m_usField0C;
    unsigned short m_usField0E;
    float m_fField10;
    unsigned short m_usField14;
    unsigned short m_usField16;

    void SwapEndianness();
};
