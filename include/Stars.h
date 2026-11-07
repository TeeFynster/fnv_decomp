#pragma once

#include "SkyObject.h"
#include "NiPointer.h"

class Stars : public SkyObject
{
public:
    Stars();
    virtual ~Stars();
    void Initialize(NiNode* pRoot) override;
    void Update(Sky* pWeatherSky, float fSeconds) override;

    void LoadGeometry(const char* path);

    NiPointer<NiNode> m_pStarsNode;
    float fAlpha;
};
