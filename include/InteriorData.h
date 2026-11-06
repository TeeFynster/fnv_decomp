#pragma once

class InteriorData
{
public:
    unsigned int m_uiAmbientColor;
    unsigned int m_uiDirectionalColor;
    unsigned int m_uiFogColor;
    float m_fFogNear;
    float m_fFogFar;
    unsigned int m_uiDirectionalRotationXY;
    unsigned int m_uiDirectionalRotationZ;
    float m_fDirectionalFade;
    float m_fFogClipDistance;
    float m_fFogPower;
    unsigned int m_uiTrailingValue;

    InteriorData();
    void Endian();
};
