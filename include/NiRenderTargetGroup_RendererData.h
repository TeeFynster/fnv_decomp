#pragma once

#include "NiRenderTargetGroup.h"

// src: XBOX_PDB (NiRenderTargetGroup::RendererData, sizeof 4).
// Exe setter 0x00ee8460 deletes this four-byte polymorphic owner through slot zero.
class NiRenderTargetGroup::RendererData
{
public:
    virtual ~RendererData();
};
