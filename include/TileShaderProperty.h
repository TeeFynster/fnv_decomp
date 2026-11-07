#pragma once

#include "BSShaderProperty.h"
#include "BSStringT.h"
#include "NiColorA.h"
#include "NiAVObject.h"

class NiTexture;

// Tile shader property: 0x60-byte base and 0x50-byte tile state.
class TileShaderProperty : public BSShaderProperty
{
  public:
    TileShaderProperty(bool bFlag);                // 0x00bb7c30
    virtual ~TileShaderProperty();

    void CopyTileShaderProperty(TileShaderProperty* dst, int flag);
    TileShaderProperty* CreateTilePropertyClone(int flag);
    void LoadBinary_00bb7b60(NiStream* stream);
    void SaveBinary_00bb7be0(NiStream* stream);

    void SetTextureImage(NiTexture* texture);      // 0x00bb7a10 replaces m_spTexture (+0x60)
    void SetTileTexture(NiTexture* texture);         // 0x00bb7a10 (same function)
    void SetAlpha(float alpha);                    // 0x00821600 stores +0x78
    void EffectSetting_SetAreaSound(int value);                  // 0x008cc6d0 stores +0x8C
    NiTexture* BGSCameraShot_GetLocationNode();                     // 0x009c8640 returns m_spTexture
    void FUN_007700d0(bool value);                 // 0x007700d0 stores +0x91

    NiPointer<NiTexture> m_spTexture;              // +0x60
    NiPointer<NiTexture> m_spTexture2;             // +0x64
    NiColorA m_kFogTint;                           // src: XBOX_PDB
                                                  // +0x68
    float m_fAlpha;                                // +0x78
    float m_afUnk7C[4];                            // +0x7C zeroed
    int m_iUnk8C;                                  // +0x8C = 3
    bool m_bUnk90;                                 // +0x90
    bool m_bUnk91;                                 // +0x91
    bool m_bUnk92;                                 // +0x92
    bool m_bUnk93;                                 // +0x93 = constructor argument
    BSStringT<char> m_kName;                       // +0x94
    unsigned int m_auiUnk9C[4];                    // +0x9C not set by the constructor
    bool m_bUnkAC;                                 // +0xAC

    // Array view used by shader constant uploads; the color retains its constructor.
    __declspec(property(get = GetFogTintData)) float* m_afUnk68;
    float* GetFogTintData()
    {
        return &m_kFogTint.r;
    }
};
