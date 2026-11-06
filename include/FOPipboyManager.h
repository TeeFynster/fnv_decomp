#pragma once

#include "FORenderedMenu.h"
#include "NiAVObject.h"
#include "BSSoundHandle.h"

class NiNode;
class NiGeometry;
class NiScreenElements;
class NiColorA;

class FOPipboyManager : public FORenderedMenu
{
public:
    FOPipboyManager();
    virtual ~FOPipboyManager();
    virtual void OnMenuOpen();

    void Init(bool);
    void ActivateButton(const unsigned int button);
    bool IsUnk28Set();
    bool GetByteAtOffsetB9();
    void SetScreen(NiAVObject*);
    void InitializeMenuLight();
    void SetScreenLightFlickerIntensity(float);
    void SetIntensity(float);
    void SetQuad(const NiColorA&);
    void SetBlurIntensity(float);
    void SetScanlines(bool, float);
    void SetPipBoyObjectVisibility(bool, bool, bool);
    void SetKnobTargetAndRate(int aiKnob, float afTarget, float afRate);
    void UpdateFade(float now);
    void UpdatePipboyLightFade(float afTime);
    void UpdateScrollKnob();
    void UpdatePipBoyButton();
    void SetDataGlowEnabled(bool);
    void UpdatePipboyLight(int);
    void SetValue(int page, bool abPlaySounds);
    bool FUN_007f8720(bool press, bool release, float& x, float& y, int& button);
    NiAVObject* FUN_007fa950();
    void FUN_00705fc0(NiNode*);
    void FUN_004dc540(NiNode*);
    void FUN_007fc2d0(NiAVObject*);
    void FUN_007f7fb0(const NiColorA&);
    void FUN_00444020(float);
    void FUN_00810530(bool);
    FORenderedMenu* FUN_00704370();
    void FUN_007fa200();

    NiPointer<NiNode> m_pPipBoyObject0;
    NiPointer<NiNode> m_pPipBoyObject1;
    NiPointer<NiAVObject> m_pPipBoyObject2;
    NiPointer<NiScreenElements> m_pScreenGeometry;
    NiPointer<NiAVObject> m_cPipBoyButtonAvailability[3];
    NiPointer<NiAVObject> m_pButtonGlowObjects[3];
    NiPointer<NiGeometry> m_pGaugeObjects[3];
    float m_fChartFirstPoint[3];
    float m_fChartSecondPoint[3];
    float m_fGaugeValues2[3];
    float m_fTabKnobPositions[5];
    bool m_bUseMenuImageSpaceEffects;
    unsigned char layoutPadding145[3];
    float m_fPipBoyAlpha;
    float m_fPipBoyTargetAlpha;
    bool m_bPipBoyFadeActive;
    unsigned char layoutPadding151[3];
    BSSoundHandle m_kPipBoyLightData;
    bool b1stPersonLightOn;
    bool b3rdPersonLightOn;
    bool m_bPipBoyLightOn;
    unsigned char layoutPadding163[1];
    float m_fFirstPersonLightIntensity;
    float m_fThirdPersonLightIntensity;
    bool m_bPipBoyLightEnabled;
    unsigned char layoutPadding16D[3];
};
