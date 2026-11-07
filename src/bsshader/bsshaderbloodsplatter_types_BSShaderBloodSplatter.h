#ifndef FNV_BSSHADERBLOODSPLATTER_H
#define FNV_BSSHADERBLOODSPLATTER_H

#include <stddef.h>
#ifndef FNV_STATIC_ASSERT
#define FNV_JOIN_IMPL(a, b) a##b
#define FNV_JOIN(a, b) FNV_JOIN_IMPL(a, b)
#define FNV_STATIC_ASSERT(condition) typedef char FNV_JOIN(fnv_static_assert_, __LINE__)[(condition) ? 1 : -1]
#endif
#include "../../include/BSShader.h"

#pragma pack(push, 4)
class BSShaderBloodSplatter : public BSShader
{
  public:
    NiPointer<NiD3DPass> spRenderPass[2];                    // +0x6C, 8 bytes
    NiPointer<NiD3DVertexShader> m_spTreeVertexShader[2];    // +0x74, 8 bytes
    NiPointer<NiD3DPixelShader> m_spPixelShaderVariants[2];  // +0x7C, 8 bytes
    BSShaderBloodSplatter();
    static void* __cdecl operator new(unsigned int size);
    BSShader* CreateShader();
    void InitializeShaderData();
    bool ConfigureShaderPass();
    void BSShaderBloodSplatterProperty_SetClampD3D(unsigned int);
    void BSShaderBloodSplatter_InitPass(unsigned int);
    void NiD3DPass_SetPixelShader(NiRefObject*);
    void SetupConstantMaps();
    // const NiRTTI* __cdecl BSShaderBloodSplatter::*()
    // BSShaderBloodSplatter
    // void __cdecl BSShaderBloodSplatter::*()
    // void __cdecl BSShaderBloodSplatter::*(unsigned int)
    // void __cdecl BSShaderBloodSplatter::*(unsigned int)
    // void __cdecl BSShaderBloodSplatter::*(unsigned int)
    // void __cdecl BSShaderBloodSplatter::*(const NiPropertyState*)
    // void __cdecl BSShaderBloodSplatter::*(const NiPropertyState*)
    // void __cdecl BSShaderBloodSplatter::*()
    // void __cdecl BSShaderBloodSplatter::*()
    // void __cdecl BSShaderBloodSplatter::*()
    // void __cdecl BSShaderBloodSplatter::*(NiCamera*)
    // void __cdecl BSShaderBloodSplatter::*(float)
    // void __cdecl BSShaderBloodSplatter::*(float)
    // void __cdecl BSShaderBloodSplatter::*(float)
    // float __cdecl BSShaderBloodSplatter::*()
    // void __cdecl BSShaderBloodSplatter::*()
    // bool __cdecl BSShaderBloodSplatter::*()
    // BSShaderBloodSplatter& __cdecl BSShaderBloodSplatter::*(const BSShaderBloodSplatter&)
    // void __cdecl BSShaderBloodSplatter::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BSShaderBloodSplatter) == 132);
FNV_STATIC_ASSERT(offsetof(BSShaderBloodSplatter, spRenderPass) == 108);
FNV_STATIC_ASSERT(offsetof(BSShaderBloodSplatter, m_spTreeVertexShader) == 116);
FNV_STATIC_ASSERT(offsetof(BSShaderBloodSplatter, m_spPixelShaderVariants) == 124);
#endif
