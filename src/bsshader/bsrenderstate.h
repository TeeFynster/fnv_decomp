
#include "bsrenderstate_packet_decls.h"
// @fnv 0x00b6b790
void BSRenderedTexture::EndAllAndResetRendererState()
{
    NiRenderer* renderer = NiRenderer::ms_pRenderer;
    EndAll();
    // NiRenderer.h does not yet declare the end-frame virtual at slot 96.
    typedef bool (__thiscall* EndFrameFunction)(NiRenderer*);
    if (renderer->m_eFrameState == 2 &&
        (*reinterpret_cast<EndFrameFunction**>(renderer))[96](renderer))
        renderer->m_eFrameState = 0;
}
// @fnv 0x00b97fa0
void BSRenderStateManager_bsrenderstate_h_unit::SetDepthBufferEnabled(bool enable, BSRENDERSTATE_LOCK lock)
{
    unsigned int index = DAT_011ffa9c;
    if (DAT_011ff9d8[index] == 0)
        g_pkRenderer->device->SetRenderState(27, enable, 0, 0);
    DAT_011ff9d8[index] += lock;
}
// @fnv 0x00b98380
void BSRenderStateManager_bsrenderstate_h_unit::SetColorWriteMask(unsigned int mask, BSRENDERSTATE_LOCK lock)
{
    unsigned int index = DAT_011ffcd0;
    if (DAT_011ff9d8[index] == 0)
        g_pkRenderer->device->SetRenderState(168, mask, 0, 0);
    DAT_011ff9d8[index] += lock;
}
