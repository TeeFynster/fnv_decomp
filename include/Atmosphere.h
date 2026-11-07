#pragma once

#include "SkyObject.h"
#include "NiFogProperty.h"

class Atmosphere : public SkyObject
{
public:
    Atmosphere();
    virtual ~Atmosphere();
    virtual void Update(Sky* pWeatherSky, float fSeconds);
    virtual void Init2(NiNode* pRoot, int arg);

    void SetAtmosphere(NiNode* pkRoot, NiFogProperty* pkFog);
    void CreateSortAdjustNode(NiNode* pkRoot);
    void UpdateAtmosphere(Sky* pWeatherSky, float fSeconds);
    void FUN_008d0600(Sky* pWeatherSky, float fSeconds);

    void FUN_00633190();
    void LoadGeometry(void*);

    NiPointer<NiNode> m_spAtmosphere;
    NiPointer<NiFogProperty> m_spFog;
    NiPointer<NiNode> m_spSkyNode;
    NiPointer<NiNode> m_spSkyShape;
    unsigned char unk18;
    unsigned char unk19[3];
};
