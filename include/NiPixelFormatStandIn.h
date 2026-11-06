#pragma once

enum TextureSurfaceFormat
{
    TextureFormatForceDword = 0x7fffffff
};

class NiPixelFormatStandIn
{
public:
    unsigned int m_ui00;
    unsigned int m_ui04;
    unsigned int m_ui08;
    TextureSurfaceFormat m_eD3DFormat;
    unsigned int m_ui10;
    unsigned int m_ui14;
    unsigned int m_ui18;
    unsigned int m_ui1c;
    unsigned int m_ui20;
    unsigned int m_ui24;
    unsigned int m_ui28;
    unsigned int m_ui2c;
    unsigned int m_ui30;
    unsigned int m_ui34;
    unsigned int m_ui38;
    unsigned int m_ui3c;
    unsigned int m_ui40;

    NiPixelFormatStandIn& operator=(const NiPixelFormatStandIn& other);
};
