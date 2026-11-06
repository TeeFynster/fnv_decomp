#pragma once

#include "BSExtraData.h"
#include "GO.h"

class NiRenderedTexture;

struct _D3DLOCKED_RECT
{
    int dummy;
};

class ExtraCellCanopyShadowMask : public BSExtraData
{
public:
    int eState;
    GO mGO;
    _D3DLOCKED_RECT rect;
    int layoutPadding;

    ExtraCellCanopyShadowMask(int state, NiRenderedTexture* texture);
};
