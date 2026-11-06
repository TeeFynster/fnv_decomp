// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_INTERFACE_REBASE_FNV_INTERFACE_TAIL_FOPIPBOYMANAGER_H
#define FNV_INTERFACE_REBASE_FNV_INTERFACE_TAIL_FOPIPBOYMANAGER_H
#include "interface_rebase_layout_support.h"
#include "interface_rebase_BSSoundHandle.h"
#include "interface_rebase_layout_support.h"
class BSShaderAccumulator;
class FOPipboyManager;
class FORenderedMenu;
class NiAVObject;
class NiCamera;
class NiColor;
class NiColorA;
class NiGeometry;
class NiPointLight;
class NiScreenElements;
class NiTexture;
class ShadowSceneNode;
class NiColor
{
  public:
    float r;  // +0x0, 4 bytes
    float g;  // +0x4, 4 bytes
    float b;  // +0x8, 4 bytes
    // void __cdecl NiColor::*(float, float, float)
    // bool __cdecl NiColor::*(const NiColor&)
    // bool __cdecl NiColor::*(const NiColor&)
    // NiColor __cdecl NiColor::*(const NiColor&)
    // operator-
    // operator*
    // operator/
    // NiColor& __cdecl NiColor::*(const NiColor&)
    // NiColor& __cdecl NiColor::*(const NiColor&)
    // operator*=
    // operator/=
    // void __cdecl NiColor::*()
    // void __cdecl NiColor::*()
    // LoadBinary
    // SaveBinary
    // char* __cdecl NiColor::*(const char*)
    // float __cdecl NiColor::*()
    // void __cdecl NiColor::*()
};
FNV_STATIC_ASSERT(sizeof(NiColor) == 12);
FNV_STATIC_ASSERT(offsetof(NiColor, r) == 0);
FNV_STATIC_ASSERT(offsetof(NiColor, g) == 4);
FNV_STATIC_ASSERT(offsetof(NiColor, b) == 8);
#include "../../../include/NiColorA.h"
FNV_STATIC_ASSERT(sizeof(NiColorA) == 16);
FNV_STATIC_ASSERT(offsetof(NiColorA, r) == 0);
FNV_STATIC_ASSERT(offsetof(NiColorA, g) == 4);
FNV_STATIC_ASSERT(offsetof(NiColorA, b) == 8);
FNV_STATIC_ASSERT(offsetof(NiColorA, a) == 12);
class FORenderedMenu
{
  public:
    bool GetInitialized();
    void** m_ppVirtualMethodTable;                                        // +0x0, 4 bytes
    NiPointer<NiGeometry> m_pMenuBackgroundScreenGeometry;  // +0x4, 4 bytes
    NiPointer<NiAVObject> m_pMenuRoot;                      // +0x8, 4 bytes
    NiPointer<NiScreenElements> m_pScreenGeometry;          // +0xC, 4 bytes
    NiPointer<NiTexture> m_pDefaultTexture;                 // +0x10, 4 bytes
    NiPointer<NiAVObject> m_pRenderedMenuObject;            // +0x14, 4 bytes
    Tile* m_pFourthMenuObject;                              // +0x18, 4 bytes
    NiPointer<NiPointLight> m_pMenuLight;                   // +0x1C, 4 bytes
    ShadowSceneNode* m_pSecondaryMenuObject;                // +0x20, 4 bytes
    NiPointer<NiCamera> m_pMenuLightParameters;                           // +0x24, 4 bytes
    bool bInitialized;                                      // +0x28, 1 bytes
    bool m_bUseMenuImageSpaceEffects;                       // +0x29, 1 bytes
    bool m_bEnableFlicker;                                  // +0x2A, 1 bytes
    unsigned char layoutPadding2B[1];
    NiColor m_kScreenLightColor;      // +0x2C, 12 bytes
    float fScreenLightBaseIntensity;  // +0x38, 4 bytes
    float m_fFlicker;                 // +0x3C, 4 bytes
    float fBlurRadius;                // +0x40, 4 bytes
    float fBlurIntensity;             // +0x44, 4 bytes
    float m_fScanlineScale;           // +0x48, 4 bytes
    bool m_bDoScanlines;              // +0x4C, 1 bytes
    bool m_bBurstActive;              // +0x4D, 1 bytes
    unsigned char layoutPadding4E[2];
    float m_fBurstElapsedTime;  // +0x50, 4 bytes
    float fBurstDuration;       // +0x54, 4 bytes
    float m_fBurstIntensity;    // +0x58, 4 bytes
    float m_fBurstSoundChance;  // +0x5C, 4 bytes
    bool m_bBurstSoundPlayed;   // +0x60, 1 bytes
    unsigned char layoutPadding61[3];
    float m_fShudderIntensity;      // +0x64, 4 bytes
    float m_fShudderDuration;       // +0x68, 4 bytes
    float m_fShudderFrequency;      // +0x6C, 4 bytes
    float m_fVerticalHoldDuration;  // +0x70, 4 bytes
    bool m_bVerticalHoldActive;     // +0x74, 1 bytes
    unsigned char layoutPadding75[3];
    float m_fVerticalHoldSpeed;       // +0x78, 4 bytes
    float m_fVerticalHoldRate;        // +0x7C, 4 bytes
    float m_fVerticalHoldChance;      // +0x80, 4 bytes
    float m_fShudderChance;           // +0x84, 4 bytes
    float m_fPulseRadiusIntensity;    // +0x88, 4 bytes
    float m_fPulseBrightenIntensity;  // +0x8C, 4 bytes
    float m_fPulseRate;               // +0x90, 4 bytes
    bool m_bPulseActive;              // +0x94, 1 bytes
    bool m_bShudderActive;            // +0x95, 1 bytes
    unsigned char layoutPadding96[2];
    float m_fDistortHorizontalScale;  // +0x98, 4 bytes
    float m_fDistortVerticalScale;    // +0x9C, 4 bytes
    float fDistortDuration;           // +0xA0, 4 bytes
    float m_fDistortTimeRemaining;    // +0xA4, 4 bytes
    NiColorA BackgroundColor;        // +0xA8, 16 bytes
    bool m_bMenuLightEnabled;         // +0xB8, 1 bytes
    bool m_bMenuLightCreated;         // +0xB9, 1 bytes
    unsigned char layoutPaddingBA[2];
    NiPointer<NiTexture> m_pMenuLightShadowNode;  // +0xBC, 4 bytes
    NiColorA m_kMenuLightColor;                  // +0xC0, 16 bytes
    bool m_bMenuLightVisible;                     // +0xD0, 1 bytes
    bool m_bMenuLightShadowed;                    // +0xD1, 1 bytes
    bool m_bMenuLightAttached;                    // +0xD2, 1 bytes
    unsigned char layoutPaddingD3[1];
    NiPointer<BSShaderAccumulator> m_pMenuLightNode;  // +0xD4, 4 bytes
    // FORenderedMenu
    // bool __cdecl FORenderedMenu::*()
    // void __cdecl FORenderedMenu::*(const NiColorA&)
    // NiColorA __cdecl FORenderedMenu::*()
    // void __cdecl FORenderedMenu::*(NiColor&)
    // void __cdecl FORenderedMenu::*(const float)
    // void __cdecl FORenderedMenu::*(const float)
    // void __cdecl FORenderedMenu::*(bool)
    // void __cdecl FORenderedMenu::*(NiGeometry*)
    // NiGeometry* __cdecl FORenderedMenu::*()
    // void __cdecl FORenderedMenu::*(NiAVObject*)
    // NiAVObject* __cdecl FORenderedMenu::*()
    // void __cdecl FORenderedMenu::*(NiAVObject*)
    // NiAVObject* __cdecl FORenderedMenu::*()
    // void __cdecl FORenderedMenu::*(Tile*)
    // Tile* __cdecl FORenderedMenu::*()
    // void __cdecl FORenderedMenu::*(NiTexture*)
    // NiTexture* __cdecl FORenderedMenu::*()
    // bool __cdecl FORenderedMenu::*(const char*, ShadowSceneNode*)
    // void __cdecl FORenderedMenu::*()
    // NiPointLight* __cdecl FORenderedMenu::*()
    // void __cdecl FORenderedMenu::*(NiCamera*)
    // NiCamera* __cdecl FORenderedMenu::*()
    // void __cdecl FORenderedMenu::*(const NiColorA&)
    // const NiColorA& __cdecl FORenderedMenu::*()
    // BSShaderNoLightingProperty* __cdecl FORenderedMenu::*()
    // void __cdecl FORenderedMenu::*(const float)
    // void __cdecl FORenderedMenu::*(const float)
    // void __cdecl FORenderedMenu::*(const bool, const float)
    // void __cdecl FORenderedMenu::*(NiTexture*)
    // NiGeometry* __cdecl FORenderedMenu::*()
    // void __cdecl FORenderedMenu::*(float, float, float)
    // void __cdecl FORenderedMenu::*()
    // void __cdecl FORenderedMenu::*(float, float)
    // void __cdecl FORenderedMenu::*(float, float, float)
    // bool __cdecl FORenderedMenu::*()
    // void __cdecl FORenderedMenu::*(NiGeometry*)
    // float __cdecl FORenderedMenu::*()
    // void __cdecl FORenderedMenu::*(float)
    // void __cdecl FORenderedMenu::*(float)
    // void __cdecl FORenderedMenu::*(bool)
    // void __cdecl FORenderedMenu::*()
    // void __cdecl FORenderedMenu::*()
    // FORenderedMenu& __cdecl FORenderedMenu::*(const FORenderedMenu&)
    // void __cdecl FORenderedMenu::*()
};
FNV_STATIC_ASSERT(sizeof(FORenderedMenu) == 216);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, m_ppVirtualMethodTable) == 0);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, m_pMenuBackgroundScreenGeometry) == 4);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, m_pMenuRoot) == 8);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, m_pScreenGeometry) == 12);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, m_pDefaultTexture) == 16);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, m_pRenderedMenuObject) == 20);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, m_pFourthMenuObject) == 24);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, m_pMenuLight) == 28);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, m_pSecondaryMenuObject) == 32);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, m_pMenuLightParameters) == 36);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, bInitialized) == 40);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, m_bUseMenuImageSpaceEffects) == 41);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, m_bEnableFlicker) == 42);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, m_kScreenLightColor) == 44);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, fScreenLightBaseIntensity) == 56);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, m_fFlicker) == 60);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, fBlurRadius) == 64);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, fBlurIntensity) == 68);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, m_fScanlineScale) == 72);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, m_bDoScanlines) == 76);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, m_bBurstActive) == 77);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, m_fBurstElapsedTime) == 80);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, fBurstDuration) == 84);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, m_fBurstIntensity) == 88);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, m_fBurstSoundChance) == 92);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, m_bBurstSoundPlayed) == 96);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, m_fShudderIntensity) == 100);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, m_fShudderDuration) == 104);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, m_fShudderFrequency) == 108);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, m_fVerticalHoldDuration) == 112);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, m_bVerticalHoldActive) == 116);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, m_fVerticalHoldSpeed) == 120);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, m_fVerticalHoldRate) == 124);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, m_fVerticalHoldChance) == 128);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, m_fShudderChance) == 132);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, m_fPulseRadiusIntensity) == 136);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, m_fPulseBrightenIntensity) == 140);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, m_fPulseRate) == 144);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, m_bPulseActive) == 148);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, m_bShudderActive) == 149);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, m_fDistortHorizontalScale) == 152);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, m_fDistortVerticalScale) == 156);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, fDistortDuration) == 160);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, m_fDistortTimeRemaining) == 164);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, BackgroundColor) == 168);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, m_bMenuLightEnabled) == 184);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, m_bMenuLightCreated) == 185);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, m_pMenuLightShadowNode) == 188);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, m_kMenuLightColor) == 192);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, m_bMenuLightVisible) == 208);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, m_bMenuLightShadowed) == 209);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, m_bMenuLightAttached) == 210);
FNV_STATIC_ASSERT(offsetof(FORenderedMenu, m_pMenuLightNode) == 212);
class FOPipboyManager : public FORenderedMenu
{
  public:
    void ActivateButton(const unsigned int button);
    // base FORenderedMenu at +0x0, size 216
    NiPointer<NiNode> m_pPipBoyObject0;                    // +0xD8, 4 bytes
    NiPointer<NiNode> m_pPipBoyObject1;                    // +0xDC, 4 bytes
    NiPointer<NiAVObject> m_pPipBoyObject2;                // +0xE0, 4 bytes
    NiPointer<NiScreenElements> m_pScreenGeometry;         // +0xE4, 4 bytes
    NiPointer<NiAVObject> m_cPipBoyButtonAvailability[3];  // +0xE8, 12 bytes
    NiPointer<NiAVObject> m_pButtonGlowObjects[3];         // +0xF4, 12 bytes
    NiPointer<NiGeometry> m_pGaugeObjects[3];              // +0x100, 12 bytes
    float m_fChartFirstPoint[3];                           // +0x10C, 12 bytes
    float m_fChartSecondPoint[3];                          // +0x118, 12 bytes
    float m_fGaugeValues2[3];                              // +0x124, 12 bytes
    float m_fTabKnobPositions[5];                          // +0x130, 20 bytes
    bool m_bUseMenuImageSpaceEffects;                      // +0x144, 1 bytes
    unsigned char layoutPadding145[3];
    float m_fPipBoyAlpha;        // +0x148, 4 bytes
    float m_fPipBoyTargetAlpha;  // +0x14C, 4 bytes
    bool m_bPipBoyFadeActive;    // +0x150, 1 bytes
    unsigned char layoutPadding151[3];
    BSSoundHandle m_kPipBoyLightData;  // +0x154, 12 bytes
    bool b1stPersonLightOn;            // +0x160, 1 bytes
    bool b3rdPersonLightOn;            // +0x161, 1 bytes
    bool m_bPipBoyLightOn;             // +0x162, 1 bytes
    unsigned char layoutPadding163[1];
    float m_fFirstPersonLightIntensity;  // +0x164, 4 bytes
    float m_fThirdPersonLightIntensity;  // +0x168, 4 bytes
    bool m_bPipBoyLightEnabled;          // +0x16C, 1 bytes
    unsigned char layoutPadding16D[3];
    // FOPipboyManager
    // void __cdecl FOPipboyManager::*()
    // bool __cdecl FOPipboyManager::*()
    // void __cdecl FOPipboyManager::*()
    // void __cdecl FOPipboyManager::*(FOPipboyManager::Knobs, float, float, bool)
    // void __cdecl FOPipboyManager::*(FOPipboyManager::Knobs, float, float)
    // float __cdecl FOPipboyManager::*(FOPipboyManager::Knobs)
    // float __cdecl FOPipboyManager::*(FOPipboyManager::Knobs)
    // void __cdecl FOPipboyManager::*(unsigned int, bool)
    // void __cdecl FOPipboyManager::*(const unsigned int)
    // void __cdecl FOPipboyManager::*(const bool, const bool, const bool)
    // void __cdecl FOPipboyManager::*(float)
    // void __cdecl FOPipboyManager::*(bool)
    // bool __cdecl FOPipboyManager::*()
    // bool __cdecl FOPipboyManager::*()
    // void __cdecl FOPipboyManager::*()
    // void __cdecl FOPipboyManager::*()
    // void __cdecl FOPipboyManager::*()
    // NiAVObject* __cdecl FOPipboyManager::*()
    // NiAVObject* __cdecl FOPipboyManager::*()
    // NiAVObject* __cdecl FOPipboyManager::*(unsigned int)
    // void __cdecl FOPipboyManager::*()
    // void __cdecl FOPipboyManager::*(bool)
    // void __cdecl FOPipboyManager::*(bool)
    // bool __cdecl FOPipboyManager::*()
    // void __cdecl FOPipboyManager::*()
    // void __cdecl FOPipboyManager::*()
    // void __cdecl FOPipboyManager::*()
    // void __cdecl FOPipboyManager::*(float)
    // void __cdecl FOPipboyManager::*()
    // void __cdecl FOPipboyManager::*()
    // void __cdecl FOPipboyManager::*()
    // void __cdecl FOPipboyManager::*()
    // void __cdecl FOPipboyManager::*(float)
    // FOPipboyManager& __cdecl FOPipboyManager::*(const FOPipboyManager&)
    // void __cdecl FOPipboyManager::*()
};
FNV_STATIC_ASSERT(sizeof(FOPipboyManager) == 368);
FNV_STATIC_ASSERT(offsetof(FOPipboyManager, m_pPipBoyObject0) == 216);
FNV_STATIC_ASSERT(offsetof(FOPipboyManager, m_pPipBoyObject1) == 220);
FNV_STATIC_ASSERT(offsetof(FOPipboyManager, m_pPipBoyObject2) == 224);
FNV_STATIC_ASSERT(offsetof(FOPipboyManager, m_pScreenGeometry) == 228);
FNV_STATIC_ASSERT(offsetof(FOPipboyManager, m_cPipBoyButtonAvailability) == 232);
FNV_STATIC_ASSERT(offsetof(FOPipboyManager, m_pButtonGlowObjects) == 244);
FNV_STATIC_ASSERT(offsetof(FOPipboyManager, m_pGaugeObjects) == 256);
FNV_STATIC_ASSERT(offsetof(FOPipboyManager, m_fChartFirstPoint) == 268);
FNV_STATIC_ASSERT(offsetof(FOPipboyManager, m_fChartSecondPoint) == 280);
FNV_STATIC_ASSERT(offsetof(FOPipboyManager, m_fGaugeValues2) == 292);
FNV_STATIC_ASSERT(offsetof(FOPipboyManager, m_fTabKnobPositions) == 304);
FNV_STATIC_ASSERT(offsetof(FOPipboyManager, m_bUseMenuImageSpaceEffects) == 324);
FNV_STATIC_ASSERT(offsetof(FOPipboyManager, m_fPipBoyAlpha) == 328);
FNV_STATIC_ASSERT(offsetof(FOPipboyManager, m_fPipBoyTargetAlpha) == 332);
FNV_STATIC_ASSERT(offsetof(FOPipboyManager, m_bPipBoyFadeActive) == 336);
FNV_STATIC_ASSERT(offsetof(FOPipboyManager, m_kPipBoyLightData) == 340);
FNV_STATIC_ASSERT(offsetof(FOPipboyManager, b1stPersonLightOn) == 352);
FNV_STATIC_ASSERT(offsetof(FOPipboyManager, b3rdPersonLightOn) == 353);
FNV_STATIC_ASSERT(offsetof(FOPipboyManager, m_bPipBoyLightOn) == 354);
FNV_STATIC_ASSERT(offsetof(FOPipboyManager, m_fFirstPersonLightIntensity) == 356);
FNV_STATIC_ASSERT(offsetof(FOPipboyManager, m_fThirdPersonLightIntensity) == 360);
FNV_STATIC_ASSERT(offsetof(FOPipboyManager, m_bPipBoyLightEnabled) == 364);
#endif
