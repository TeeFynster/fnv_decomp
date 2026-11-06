// Renderer interface used by NiRenderedTexture.cpp.
#ifndef FNV_RENDEREDTEXTURE_DECLARATIONS_H
#define FNV_RENDEREDTEXTURE_DECLARATIONS_H

#include "../include/NiRenderedTexture.h"

#include "../include/NiRenderer.h"
#include "../include/NiDX9Renderer.h"

class NiSourceTexture;

typedef char NiRenderedTexture_size_check[(sizeof(NiRenderedTexture) == 0x48) ? 1 : -1];
typedef char NiRenderedTexture_buffer_check[(offsetof(NiRenderedTexture, m_spRenderTargetBuffer) == 0x30) ? 1 : -1];
typedef char NiRenderedTexture_format_check[(offsetof(NiRenderedTexture, m_ePixelFormat) == 0x44) ? 1 : -1];
#endif
