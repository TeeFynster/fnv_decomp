#pragma once

#include "TESForm.h"
#include "TESFullName.h"
#include "TESModelTextureSwap.h"
#include "TESTexture.h"
#include "EndianConvertibleData.h"

class TESCasino : public TESForm, public TESFullName
{
public:
    TESCasino();

    bool Load(TESFile* apFile);
    // TESForm vtable slot 8 (vftable 0x1026574 slot 8 = 0x5048d0)
    bool LoadForm(TESFile* file);
    void ReadTypedData(TESFile* apFile, void* apData, unsigned short ausSize);

    TESModelTextureSwap m_kModelTextureSwaps[10];
    TESTexture m_kIconTextures[11];
    EndianConvertibleData data;
};
