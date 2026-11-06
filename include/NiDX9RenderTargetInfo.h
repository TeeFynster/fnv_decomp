#pragma once

#include "NiDX9DepthStencilEntry.h"

class NiDX9RenderTargetInfo
{
public:
    NiDX9DepthStencilEntry m_akWindowed[9];
    NiDX9DepthStencilEntry m_akFullscreen[9];
};