//
// NiD3DPass: the Nivid3D render pass object.
//
// NiD3DPass uses the shared layout; D3DRenderStateGroup remains local.
#ifndef NID3DPASS_H
#define NID3DPASS_H


#include <stddef.h>
#include "../include/NiD3DPass.h"

#define NID3DPASS_JOIN_IMPL(a, b) a##b
#define NID3DPASS_JOIN(a, b) NID3DPASS_JOIN_IMPL(a, b)
#define NID3DPASS_STATIC_ASSERT(condition) typedef char NID3DPASS_JOIN(nid3dpass_static_assert_, __LINE__)[(condition) ? 1 : -1]

class NiD3DRenderStateGroup__NiD3DRSEntry;

#pragma pack(push, 4)

// A group of D3D render states owned either by a pass or by the renderer pool.
class D3DRenderStateGroup
{
  public:
    bool m_bHasBeenApplied;  // +0x0, 1 bytes
    unsigned char layoutPadding1[3];
    unsigned int m_uiRenderStateEntryCount;                       // +0x4, 4 bytes
    NiD3DRenderStateGroup__NiD3DRSEntry* m_pkRenderStateEntries;  // +0x8, 4 bytes
    unsigned int m_uiFreeEntryCount;                              // +0xC, 4 bytes
    NiD3DRenderStateGroup__NiD3DRSEntry* m_pkFreeEntries;         // +0x10, 4 bytes

    // Hands out a group owned by the renderer, marking it renderer owned.
    static D3DRenderStateGroup* GetCurrentRenderStateGroup();

    // Records (state, value) and applies it when enabled.
    void SetRenderState(unsigned int state, unsigned int value, bool enable);
};

#pragma pack(pop)
NID3DPASS_STATIC_ASSERT(sizeof(D3DRenderStateGroup) == 20);
NID3DPASS_STATIC_ASSERT(offsetof(D3DRenderStateGroup, m_bHasBeenApplied) == 0);
NID3DPASS_STATIC_ASSERT(offsetof(D3DRenderStateGroup, m_uiRenderStateEntryCount) == 4);
NID3DPASS_STATIC_ASSERT(offsetof(D3DRenderStateGroup, m_pkRenderStateEntries) == 8);
NID3DPASS_STATIC_ASSERT(offsetof(D3DRenderStateGroup, m_uiFreeEntryCount) == 12);
NID3DPASS_STATIC_ASSERT(offsetof(D3DRenderStateGroup, m_pkFreeEntries) == 16);
// @fnv 0x00b80040
void NiD3DPass::SetAlphaBlendMode(unsigned int uiSrcBlend, unsigned int uiDestBlend, bool bSrcAlpha)
{
    if (!m_pkRenderStateGroup)
        m_pkRenderStateGroup = D3DRenderStateGroup::GetCurrentRenderStateGroup();
    m_pkRenderStateGroup->SetRenderState(0x13, uiSrcBlend, true);
    if (!m_pkRenderStateGroup)
        m_pkRenderStateGroup = D3DRenderStateGroup::GetCurrentRenderStateGroup();
    m_pkRenderStateGroup->SetRenderState(0x14, uiDestBlend, true);
}
NID3DPASS_STATIC_ASSERT(sizeof(NiD3DPass) == 104);
NID3DPASS_STATIC_ASSERT(offsetof(NiD3DPass, m_szName) == 4);
NID3DPASS_STATIC_ASSERT(offsetof(NiD3DPass, m_uiCurrentStage) == 20);
NID3DPASS_STATIC_ASSERT(offsetof(NiD3DPass, m_uiStageCount) == 24);
NID3DPASS_STATIC_ASSERT(offsetof(NiD3DPass, m_uiTexturesPerPass) == 28);
NID3DPASS_STATIC_ASSERT(offsetof(NiD3DPass, m_kStages) == 32);
NID3DPASS_STATIC_ASSERT(offsetof(NiD3DPass, m_pkRenderStateGroup) == 48);
NID3DPASS_STATIC_ASSERT(offsetof(NiD3DPass, m_spPixelConstantMap) == 52);
NID3DPASS_STATIC_ASSERT(offsetof(NiD3DPass, m_pcPixelShaderProgramFile) == 56);
NID3DPASS_STATIC_ASSERT(offsetof(NiD3DPass, m_pcPixelShaderEntryPoint) == 60);
NID3DPASS_STATIC_ASSERT(offsetof(NiD3DPass, m_pcPixelShaderTarget) == 64);
NID3DPASS_STATIC_ASSERT(offsetof(NiD3DPass, m_spPixelShader) == 68);
NID3DPASS_STATIC_ASSERT(offsetof(NiD3DPass, m_spVertexConstantMap) == 72);
NID3DPASS_STATIC_ASSERT(offsetof(NiD3DPass, cEnabledStages) == 76);
NID3DPASS_STATIC_ASSERT(offsetof(NiD3DPass, m_pcVertexShaderProgramFile) == 80);
NID3DPASS_STATIC_ASSERT(offsetof(NiD3DPass, m_pcVertexShaderEntryPoint) == 84);
NID3DPASS_STATIC_ASSERT(offsetof(NiD3DPass, m_pcVertexShaderTarget) == 88);
NID3DPASS_STATIC_ASSERT(offsetof(NiD3DPass, m_spVertexShader) == 92);
NID3DPASS_STATIC_ASSERT(offsetof(NiD3DPass, m_bSoftwareVP) == 96);
NID3DPASS_STATIC_ASSERT(offsetof(NiD3DPass, m_bRendererOwned) == 97);
NID3DPASS_STATIC_ASSERT(offsetof(NiD3DPass, m_uiRefCount) == 100);

#undef NID3DPASS_STATIC_ASSERT
#undef NID3DPASS_JOIN
#undef NID3DPASS_JOIN_IMPL

#endif