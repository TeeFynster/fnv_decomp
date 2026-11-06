#pragma once

// FOHUDEffectManager: the HUD screen effects (shudder, blur, scanlines), no vtable. InterfaceManager holds it by value
// at +0x178 with the next member at +0x1dc, so 0x64 bytes. The constructor 0x007f7610 constructs the NiPointer at
// +0x00, the BGSMenuPacker at +0x04 (0x007002d0) and the NiPoint2s at +0x30/+0x38/+0x40/+0x48, news the 0x88-byte
// ImageSpaceShaderParam into +0x50 (0x00b8a9e0), clears +0x28/+0x54/+0x55/+0x56 and reads three settings into
// +0x5c/+0x60/+0x58. TriggerShudder 0x007f7880/0x007f78f0 and UpdateShudder 0x007f7970 use +0x28..+0x4c;
// SetBlurRadiusHUD 0x005bfbb0 writes +0x58, SetBlurIntensityHUD 0x005bfbd0 writes +0x60.

#include "BGSMenuPacker.h"
#include "NiPoint2.h"
#include "NiPointer.h"

class ImageSpaceShaderParam;
class NiRefObject;

class FOHUDEffectManager
{
public:
    NiPointer<NiRefObject> spEffect;              // 0x00 pointee type not established
    BGSMenuPacker kMenuPacker;                    // 0x04
    bool bShudderActive;                          // 0x28
    float fShudderStartTime;                      // 0x2c
    NiPoint2 kShudderDuration;                    // 0x30
    NiPoint2 kShudderStrength;                    // 0x38
    NiPoint2 kShudderFrequency;                   // 0x40
    NiPoint2 kShudderOffset;                      // 0x48
    ImageSpaceShaderParam* pShaderParam;          // 0x50
    bool bFlag54;                                 // 0x54
    bool bFlag55;                                 // 0x55
    bool bFlag56;                                 // 0x56
    float fBlurRadius;                            // 0x58
    float fScanlineFrequency;                     // 0x5c
    float fBlurIntensity;                         // 0x60

    FOHUDEffectManager();                         // 0x007f7610
    void OnIdle();                                // 0x007f7830
    void UpdateShudder();                         // 0x007f7970
    void SetBlurRadiusHUD(float);                 // 0x005bfbb0
    void SetBlurIntensityHUD(float);              // 0x005bfbd0
};
