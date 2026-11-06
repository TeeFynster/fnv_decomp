#pragma once

#include "TESTexture.h"

class TESIcon : public TESTexture
{
public:
    TESIcon();
    ~TESIcon();

    virtual char* GetTextureResourcePath();
};
