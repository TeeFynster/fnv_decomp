#pragma once

class LightSourceData
{
public:
    int time;
    unsigned int radius;
    unsigned int color;
    unsigned int flags;
    float m_fLightFalloff;
    float fFOV;
};
