#ifndef FNV_SPEEDTREELEAFSHADER_H
#define FNV_SPEEDTREELEAFSHADER_H

#include "../../include/BSShader.h"
#include <stddef.h>

#pragma pack(push, 4)
class SpeedTreeLeafShader : public BSShader
{
  public:
    SpeedTreeLeafShader();
    void UpdateShaderConstants();
    float m_afShaderConstants[48][4];               // +0x6C, 768 bytes
    NiPointer<NiD3DVertexShader> pVertexShader[4];  // +0x36C, 16 bytes
    NiPointer<NiD3DPixelShader> pPixelShader[2];    // +0x37C, 8 bytes
    NiPointer<NiD3DPass> m_pD3DPasses[2];           // +0x384, 8 bytes
    // SpeedTreeLeafShader
    // void __cdecl SpeedTreeLeafShader::*()
    // const NiRTTI* __cdecl SpeedTreeLeafShader::*()
    // bool __cdecl SpeedTreeLeafShader::*(NiGeometry*)
    // void __cdecl SpeedTreeLeafShader::*()
    // void __cdecl SpeedTreeLeafShader::*(NiGeometry*, const NiSkinInstance*, NiGeometryData::RendererData*, const NiPropertyState*, const NiDynamicEffectState*, const NiTransform&, const NiBound&)
    // unsigned int __cdecl SpeedTreeLeafShader::*(NiGeometry*, const NiSkinInstance*, NiGeometryData::RendererData*, const NiPropertyState*, const NiDynamicEffectState*, const NiTransform&, const NiBound&)
    // unsigned int __cdecl SpeedTreeLeafShader::*(NiGeometry*, const NiSkinInstance*, const NiSkinPartition::Partition*, NiGeometryData::RendererData*, const NiPropertyState*, const NiDynamicEffectState*, const NiTransform&, const NiBound&)
    // void __cdecl SpeedTreeLeafShader::*(unsigned int)
    // void __cdecl SpeedTreeLeafShader::*(unsigned int)
    // void __cdecl SpeedTreeLeafShader::*(unsigned int)
    // void __cdecl SpeedTreeLeafShader::*(const NiPropertyState*)
    // void __cdecl SpeedTreeLeafShader::*(const NiPropertyState*)
    // void __cdecl SpeedTreeLeafShader::*()
    // void __cdecl SpeedTreeLeafShader::*()
    // void __cdecl SpeedTreeLeafShader::*()
    // void __cdecl SpeedTreeLeafShader::*()
    // void __cdecl SpeedTreeLeafShader::*(SpeedTreeLeafShaderProperty*, D3DXMATRIX&, float)
    // void __cdecl SpeedTreeLeafShader::*(float, float, float, float)
    // SpeedTreeLeafShader& __cdecl SpeedTreeLeafShader::*(const SpeedTreeLeafShader&)
    // void __cdecl SpeedTreeLeafShader::*()
};
#pragma pack(pop)
typedef char speedtree_leaf_size[(sizeof(SpeedTreeLeafShader) == 908) ? 1 : -1];
typedef char speedtree_leaf_constants_offset[(offsetof(SpeedTreeLeafShader, m_afShaderConstants) == 108) ? 1 : -1];
typedef char speedtree_leaf_vertex_shaders_offset[(offsetof(SpeedTreeLeafShader, pVertexShader) == 876) ? 1 : -1];
typedef char speedtree_leaf_pixel_shaders_offset[(offsetof(SpeedTreeLeafShader, pPixelShader) == 892) ? 1 : -1];
typedef char speedtree_leaf_passes_offset[(offsetof(SpeedTreeLeafShader, m_pD3DPasses) == 900) ? 1 : -1];
#endif
