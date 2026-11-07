// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BSDISTANTTREESHADER_H
#define FNV_BSDISTANTTREESHADER_H

#include <stddef.h>
#define FNV_JOIN_IMPL(a, b) a##b
#define FNV_JOIN(a, b) FNV_JOIN_IMPL(a, b)
#define FNV_STATIC_ASSERT(condition) typedef char FNV_JOIN(fnv_static_assert_, __LINE__)[(condition) ? 1 : -1]
#include "NiFixedString.h"
#include "NiRefObject.h"
class BSDistantTreeShader;
class BSDistantTreeShader__InstanceData;
class Direct3DDeviceInterface;
struct _D3DXMACRO;
class NiD3DDefaultShader__PassFogStatus;
class NiD3DPixelShader;
class D3DRenderStateGroup;
class NiD3DVertexShader;
class NiDynamicEffectState;
class ShaderPassRenderer;
class GraphicsRenderer;
class NiD3DVertexDeclaration;
#pragma pack(push, 4)
class BSDistantTreeShader : public BSShader
{
  public:
    NiPointer<NiD3DPass> spRenderPass[2];                     // +0x6C, 8 bytes
    NiPointer<NiD3DVertexShader> m_spTreeVertexShader;        // +0x74, 4 bytes
    NiPointer<NiD3DPixelShader> m_spPixelShaderVariants[2];   // +0x78, 8 bytes
    NiPointer<NiD3DVertexDeclaration> m_spVertexDeclaration;  // +0x80, 4 bytes
    NiColorA m_kFogColors[2];                                // +0x84, 32 bytes
    unsigned int m_uiInstanceCount;                           // +0xA4, 4 bytes
    BSDistantTreeShader__InstanceData* m_pInstances;          // +0xA8, 4 bytes
    NiColorA m_kColor1;                                      // +0xAC, 16 bytes
    NiColorA m_kColor2;                                      // +0xBC, 16 bytes
    NiColorA m_kColor3;                                      // +0xCC, 16 bytes
    NiColorA m_kColor4;                                      // +0xDC, 16 bytes
    NiColorA m_kColor5;                                      // +0xEC, 16 bytes
    virtual BSShader* CreateShader();
    void InitializeShaderData();
    void UpdateShaderConstants();
    BSDistantTreeShader* FUN_00bb6c30(NiD3DVertexDeclaration*);
    void BSDistantTreeShader_LoadStagesAndPasses();
    // const NiRTTI* __cdecl BSDistantTreeShader::*()
    // BSDistantTreeShader
    // void __cdecl BSDistantTreeShader::*()
    // void __cdecl BSDistantTreeShader::*(unsigned int)
    // void __cdecl BSDistantTreeShader::*(unsigned int)
    // void __cdecl BSDistantTreeShader::*(unsigned int)
    // void __cdecl BSDistantTreeShader::*(const NiPropertyState*)
    // void __cdecl BSDistantTreeShader::*(const NiPropertyState*)
    // void __cdecl BSDistantTreeShader::*(const NiPropertyState*)
    // void __cdecl BSDistantTreeShader::*(const NiPropertyState*)
    // void __cdecl BSDistantTreeShader::*()
    // bool __cdecl BSDistantTreeShader::*()
    // NiD3DShaderDeclaration* __cdecl BSDistantTreeShader::*(NiGeometry*, BSShaderProperty*)
    // void __cdecl BSDistantTreeShader::*()
    // void __cdecl BSDistantTreeShader::*()
    // unsigned int __cdecl BSDistantTreeShader::*()
    // void __cdecl BSDistantTreeShader::*(NiTexture*)
    // void __cdecl BSDistantTreeShader::*()
    // bool __cdecl BSDistantTreeShader::*()
    // BSDistantTreeShader& __cdecl BSDistantTreeShader::*(const BSDistantTreeShader&)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BSDistantTreeShader) == 252);
FNV_STATIC_ASSERT(offsetof(BSDistantTreeShader, spRenderPass) == 108);
FNV_STATIC_ASSERT(offsetof(BSDistantTreeShader, m_spTreeVertexShader) == 116);
FNV_STATIC_ASSERT(offsetof(BSDistantTreeShader, m_spPixelShaderVariants) == 120);
FNV_STATIC_ASSERT(offsetof(BSDistantTreeShader, m_spVertexDeclaration) == 128);
FNV_STATIC_ASSERT(offsetof(BSDistantTreeShader, m_kFogColors) == 132);
FNV_STATIC_ASSERT(offsetof(BSDistantTreeShader, m_uiInstanceCount) == 164);
FNV_STATIC_ASSERT(offsetof(BSDistantTreeShader, m_pInstances) == 168);
FNV_STATIC_ASSERT(offsetof(BSDistantTreeShader, m_kColor1) == 172);
FNV_STATIC_ASSERT(offsetof(BSDistantTreeShader, m_kColor2) == 188);
FNV_STATIC_ASSERT(offsetof(BSDistantTreeShader, m_kColor3) == 204);
FNV_STATIC_ASSERT(offsetof(BSDistantTreeShader, m_kColor4) == 220);
FNV_STATIC_ASSERT(offsetof(BSDistantTreeShader, m_kColor5) == 236);
#endif
