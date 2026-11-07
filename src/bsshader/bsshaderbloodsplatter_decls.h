// Helpers used by the blood splatter shader.
#ifndef BSSHADERBLOODSPLATTER_DECLS_H
#define BSSHADERBLOODSPLATTER_DECLS_H

#include "../../include/BSShaderBloodSplatter.h"
#include "../../include/NiPointer.h"
#include "../../include/NiD3DPass.h"
#include "../../include/NiD3DVertexShader.h"
#include "../../include/NiD3DPixelShader.h"

class BeamStage
{
  public:
    unsigned char layoutPrefix[0x60];
    unsigned int m_uiRefCount;
    void NiD3DTextureStage_SetFilterMode(unsigned int);
    void ReturnToPool();
    void DecRefCount()
    {
        --m_uiRefCount;
        if (m_uiRefCount == 0)
            ReturnToPool();
    }
    static void CreateNewStage(NiPointer<BeamStage>&);
};
class D3DRenderStateGroup
{
  public:
    static D3DRenderStateGroup* GetCurrentRenderStateGroup();
    void SetRenderState(unsigned int, unsigned int, bool);
};
void ConfigureBeamStage(BeamStage*, unsigned int, unsigned int, unsigned int, bool);
#include "../../include/_D3DXMACRO.h"
extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int);
extern "C" int __cdecl sprintf_s(char*, unsigned int, const char*, ...);
extern NiD3DPass* DAT_0126f74c;
FNV_STATIC_ASSERT(offsetof(NiD3DPass, m_uiCurrentStage) == 0x14);
FNV_STATIC_ASSERT(offsetof(NiD3DPass, m_pkRenderStateGroup) == 0x30);
FNV_STATIC_ASSERT(offsetof(NiD3DPass, m_spPixelShader) == 0x44);
FNV_STATIC_ASSERT(offsetof(NiD3DPass, m_spVertexShader) == 0x5c);
FNV_STATIC_ASSERT(offsetof(BeamStage, m_uiRefCount) == 0x60);
#endif
