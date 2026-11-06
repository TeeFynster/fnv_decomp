#pragma once

#include "TESTexture.h"

class TESTexture1024 : public TESTexture
{
public:
    TESTexture1024();
    ~TESTexture1024();

    unsigned int GetModelLength() const;
    const char* GetTextureResourceName();
    void SetTexture(const char* texturePath);
};
