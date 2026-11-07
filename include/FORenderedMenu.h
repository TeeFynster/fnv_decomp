#pragma once

#include "NiAVObject.h"
#include "NiColor.h"
#include "NiColorA.h"

class NiGeometry;
class NiScreenElements;
class NiTexture;
class NiPointLight;
class NiCamera;
class NiNode;
class Tile;
class ShadowSceneNode;
class BSShaderAccumulator;
class Target82;
class Arg;

class FORenderedMenu
{
public:
    virtual ~FORenderedMenu();
    virtual void vf1();
    virtual void* v2();
    virtual void Render_007fba00(void*, void*, Target82*);
    virtual void vf4();
    virtual bool UpdateScreenEffect();
    virtual bool Pick_007fb790(bool abDown, int a2, int a3);
    virtual void vf7();
    virtual void vf8();
    virtual void OnMenuOpen();
    virtual void ResetNifs();
    virtual float BaseProcess_GetActorAlpha();
    virtual void v12();
    virtual void v13();
    virtual void HandleStaticEffect(float afTime);
    virtual void UpdateVertHold(float a);
    virtual void HandleShudderEffect(float afTime);
    virtual void HandlePulseEffect(float afDuration);
    virtual void UpdateNodePosition(float fTime);
    virtual void UpdateDistortTimer(float dt);
    virtual void DoEffect(Arg*, void*, int);

    bool GetInitialized();
    NiAVObject* GetMenuRoot();
    void ClearMenuLight();
    bool CreateMenuLight(const char*, ShadowSceneNode*);
    void SetDefaultTexture(NiTexture*);
    unsigned int GetCurrentTimeMilliseconds();
    void StartBurst(float duration, float intensity, float soundChance);
    NiNode* GetSceneNode();
    void UpdateSlotSelection(int);
    bool IsUnk28Set();
    void SetScreenTexture(int);
    void OnMenuOpen_007fb040();
    void ResetMenuState();
    bool Pick_007fb790(void* pkUnused, float* pfX, float* pfY);

    NiPointer<NiGeometry> m_pMenuBackgroundScreenGeometry;
    NiPointer<NiAVObject> m_pMenuRoot;
    NiPointer<NiScreenElements> m_pScreenGeometry;
    NiPointer<NiTexture> m_pDefaultTexture;
    NiPointer<NiAVObject> m_pRenderedMenuObject;
    Tile* m_pFourthMenuObject;
    NiPointer<NiPointLight> m_pMenuLight;
    ShadowSceneNode* m_pSecondaryMenuObject;
    NiPointer<NiCamera> m_pMenuLightParameters;
    bool bInitialized;
    bool m_bUseMenuImageSpaceEffects;
    bool m_bEnableFlicker;
    unsigned char unk2B[1];
    NiColor m_kScreenLightColor;
    float fScreenLightBaseIntensity;
    float m_fFlicker;
    float fBlurRadius;
    float fBlurIntensity;
    float m_fScanlineScale;
    bool m_bDoScanlines;
    bool m_bBurstActive;
    unsigned char unk4E[2];
    float m_fBurstElapsedTime;
    float fBurstDuration;
    float m_fBurstIntensity;
    float m_fBurstSoundChance;
    bool m_bBurstSoundPlayed;
    unsigned char unk61[3];
    float m_fShudderIntensity;
    float m_fShudderDuration;
    float m_fShudderFrequency;
    float m_fVerticalHoldDuration;
    bool m_bVerticalHoldActive;
    unsigned char unk75[3];
    float m_fVerticalHoldSpeed;
    float m_fVerticalHoldRate;
    float m_fVerticalHoldChance;
    float m_fShudderChance;
    float m_fPulseRadiusIntensity;
    float m_fPulseBrightenIntensity;
    float m_fPulseRate;
    bool m_bPulseActive;
    bool m_bShudderActive;
    unsigned char unk96[2];
    float m_fDistortHorizontalScale;
    float m_fDistortVerticalScale;
    float fDistortDuration;
    float m_fDistortTimeRemaining;
    NiColorA BackgroundColor;
    bool m_bMenuLightEnabled;
    bool m_bMenuLightCreated;
    unsigned char unkBA[2];
    NiPointer<NiTexture> m_pMenuLightShadowNode;
    NiColorA m_kMenuLightColor;
    bool m_bMenuLightVisible;
    bool m_bMenuLightShadowed;
    bool m_bMenuLightAttached;
    unsigned char unkD3[1];
    NiPointer<BSShaderAccumulator> m_pMenuLightNode;
};
