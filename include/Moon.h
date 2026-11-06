#pragma once

#include "SkyObject.h"
#include "NiTriShape.h"
#include "TESFullName.h"

class Sky;

class Moon : public SkyObject
{
public:
    enum UpdateStatus
    {
        US_NOT_REQUIRED = 0,
        US_WHEN_CULLED = 1,
        US_INITIALIZE = 2
    };

    Moon(const char* name, float fadeStart, float fadeEnd, float shadowEarlyFade,
         float speed, float zOffset, unsigned int size);
    virtual ~Moon();
    virtual void Initialize(NiNode* root, const char* name);
    virtual void Update(Sky* sky, float elapsed);

    static bool IsMoonVisible(const Sky* sky);
    float GetMoonVisibility();
    float GetMoonShadowVisibility();

    NiPointer<NiNode> m_pMoonNode;
    NiPointer<NiNode> m_pMoonShadowNode;
    NiPointer<NiTriShape> m_pMoonShape;
    NiPointer<NiTriShape> m_pMoonShadowShape;
    BSStringT<char> m_kMoonTexturePaths[8];
    float m_fFadeStartAngle;
    float m_fFadeEndAngle;
    float m_fFadeAngleRange;
    float fSpeed;
    float m_fGlyphVerticalOffset;
    unsigned int iSize;
    UpdateStatus m_eUpdateStatus;
    float fPos;
    float m_fValue;
};
