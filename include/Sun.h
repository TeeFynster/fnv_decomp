#pragma once

#include "SkyObject.h"
#include "NiAVObject.h"

class Sun : public SkyObject
{
public:
    Sun();
    virtual ~Sun();

    void vfn04();
    void Init(NiNode*);

    NiPointer<NiAVObject> m_pFirstSceneObject;
    NiPointer<NiAVObject> m_pSecondSceneObject;
    NiPointer<NiAVObject> m_pThirdSceneObject;
    NiPointer<NiAVObject> m_pFourthSceneObject;
    void* m_pSunGlarePick;
    NiPointer<NiAVObject> m_pMenuLight;
    float m_fSunGlareIntensity;
    bool bDoOcclusionTests;
    NiPointer<NiAVObject> m_pSunShaderAccumulator;
};
