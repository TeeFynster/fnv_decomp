
// BSRenderStateManager_bsrenderstate_h_unit: local type (was include/BSRenderStateManager.h, which had no evidence of one real class); its methods are 0x00b97fa0 BSRenderState::SetAlphaBlendEnable, 0x00b98380 BSRenderState::SetColorWriteEnable (no shared BSRenderState header yet)
#include "../../include/BSRenderedTexture.h"
#include "../../include/BSRENDERSTATE_LOCK.h"
#include "../../include/NiRenderer.h"

class BSRenderStateManager_bsrenderstate_h_unit
{
public:
    static void __cdecl SetDepthBufferEnabled(bool, BSRENDERSTATE_LOCK);
    static void __cdecl SetDepthBufferEnabled(bool, int);
    static void __cdecl SetColorWriteMask(unsigned int, BSRENDERSTATE_LOCK);
    static void __cdecl SetColorWriteMask(unsigned int, unsigned int);
};
#include "bsrenderstate.h"
