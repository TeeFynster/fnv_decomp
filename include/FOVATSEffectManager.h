#pragma once

// FOVATSEffectManager: the VATS screen effect (scan, burst, pulse, target highlight), no vtable. InterfaceManager holds
// it by value at +0x1dc and its next own member is at +0x4ac, so 0x2d0 bytes. The constructor 0x007ffec0 constructs
// the VATSEffectTarget at +0x04, VATSEffectTarget[32] at +0x14 (8 bytes each), NiPointers at +0x114, +0x2c4 and +0x2cc
// (0x00633c90), loads a texture into +0x2c4 (BSShaderManager::GetTexture 0x00b55840), news a BSShaderAccumulator into
// +0x2cc, stores 1 at +0x2c8 and -1 at +0x10, and clears the 16-entry arrays at +0x119, +0x12c, +0x16c and +0x1ac.
// Members the constructor does not touch are named after their offset; the accessors (SetTarget 0x00800ac0,
// Update* 0x00800740..0x00800900) use +0x22c, +0x23c, +0x240 and the floats +0x288..+0x2c0.

#include "NiPointer.h"
#include "VATSEffectTarget.h"

class BSShaderAccumulator;
class NiRefObject;
class NiTexture;
class RenderTexture;
class RenderedTextureSource;

class FOVATSEffectManager
{
public:
    unsigned int uiEffectMode;                    // 0x000
    VATSEffectTarget kTarget;                     // 0x004
    unsigned int uiTargetValue;                   // 0x00c ctor: 0
    int iTargetLimb;                              // 0x010 ctor: -1
    VATSEffectTarget akMultiTargets[32];          // 0x014
    NiPointer<NiRefObject> sp114;                 // 0x114 pointee type not established
    bool bFlag118;                                // 0x118
    bool abMultiTargetFlags[16];                  // 0x119
    bool bFlag129;                                // 0x129 ctor: 1
    unsigned int auiMultiTargetValue12C[16];      // 0x12c
    unsigned int auiMultiTargetValue16C[16];      // 0x16c
    bool abMultiTargetFlags1AC[16];               // 0x1ac
    unsigned int unk1BC[28];                      // 0x1bc
    unsigned int unk22C;                          // 0x22c
    unsigned int unk230[3];                       // 0x230
    unsigned int unk23C;                          // 0x23c
    unsigned int unk240;                          // 0x240 ctor: 0
    unsigned int unk244[16];                      // 0x244
    bool bFlag284;                                // 0x284 ctor: 0
    float flt288;                                 // 0x288
    float flt28C;                                 // 0x28c ctor: 0
    float flt290;                                 // 0x290 setting
    float flt294;                                 // 0x294 time-based seed
    bool bFlag298;                                // 0x298 ctor: 0
    float flt29C;                                 // 0x29c
    float flt2A0;                                 // 0x2a0
    float flt2A4;                                 // 0x2a4
    float flt2A8;                                 // 0x2a8
    float flt2AC;                                 // 0x2ac ctor: 0
    float flt2B0;                                 // 0x2b0 ctor: 0
    bool bFlag2B4;                                // 0x2b4 ctor: 0
    bool bFlag2B5;                                // 0x2b5 ctor: 0
    float flt2B8;                                 // 0x2b8
    float flt2BC;                                 // 0x2bc
    float flt2C0;                                 // 0x2c0 ctor: 0
    NiPointer<NiTexture> spTexture;               // 0x2c4
    unsigned int unk2C8;                          // 0x2c8 ctor: 1
    NiPointer<BSShaderAccumulator> spAccumulator; // 0x2cc

    FOVATSEffectManager();                        // 0x007ffec0
    void SetEffectMode(unsigned int);             // 0x0044ac20
    bool IsScanning();                            // 0x007f4810
    void FOVATSEffectManager_OnIdle();
    void OnIdle();                                // 0x00800370
    void FOVATSEffectManager_TriggerDistort();
    void FOVATSEffectManager_UpdateBurst(float);
    void SetScaledValues(float);
    void FOVATSEffectManager_UpdateTargetPulse(float);
    void UpdateProgress(float);
    void FOVATSEffectManager_UpdateScan(float);
    void DisableScan();                           // 0x008009d0
    void FOVATSEffectManager_SetTarget(int, int, int);
    void ClearMultiTargets();                     // 0x00800ed0
    void FOVATSEffectManager_DrawTargetToTexture(RenderTexture*, int, unsigned char, int, int, unsigned char);
    void FOVATSEffectManager_DrawTarget(unsigned char, int);
    void FOVATSEffectManager_DrawSingleTarget(unsigned char, int);
    void FOVATSEffectManager_DrawMultipleTargets();
    void VATSEffect_ShutdownEffect();
    void PrepareScanEffect(int, int, int, unsigned char);
    void FOVATSEffectManager_PrepareHighlightEffect(int, int, int, unsigned char);
    void FOVATSEffectManager_PrepareHighlightEffect(int, RenderedTextureSource*, int, unsigned char);
    void PrepareEffect(int, int, int, unsigned char);
};
