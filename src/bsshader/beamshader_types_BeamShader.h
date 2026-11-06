// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BEAMSHADER_H
#define FNV_BEAMSHADER_H

#include "../../include/BSShader.h"
#include "NiFixedString.h"
#include "NiRefObject.h"
class BeamShader;
class Direct3DDeviceInterface;
class NiD3DDefaultShader__PassFogStatus;
class NiD3DPixelShader;
class D3DRenderStateGroup;
class NiD3DVertexShader;
class NiDynamicEffectState;
class ShaderPassRenderer;
class GraphicsRenderer;
#include "../../include/BSShaderManager.h"
#pragma pack(push, 4)
class BeamShader : public BSShader
{
  public:
    BSShaderManager::eBSSMPassEnum m_ePass;            // +0x6C, 4 bytes
    float m_fPackageValue;                                      // +0x70, 4 bytes
    float m_fMatrix[16];                               // +0x74, 64 bytes
    NiPointer<NiD3DPass> m_pD3DPass;                   // +0xB4, 4 bytes
    NiPointer<NiD3DVertexShader> D3DShaderRenderData;  // +0xB8, 4 bytes
    NiPointer<NiD3DPixelShader> D3DShaderPassState;    // +0xBC, 4 bytes
    virtual void InitializeVertexShader();
    virtual void InitializePixelShader();
    // const NiRTTI* __cdecl BeamShader::*()
    // BeamShader
    // void __cdecl BeamShader::*()
    // void __cdecl BeamShader::*()
    // bool __cdecl BeamShader::*()
    // void __cdecl BeamShader::*()
    // void __cdecl BeamShader::*()
    // BeamShaderProperty* __cdecl BeamShader::*(NiAVObject*, NiGeometry*)
    // void __cdecl BeamShader::*(NiAVObject*, BeamShaderProperty*)
    // NiGeometry* __cdecl BeamShader::*()
    // int __cdecl BeamShader::*()
    // int __cdecl BeamShader::*()
    // void __cdecl BeamShader::*()
    // void __cdecl BeamShader::*(BSShaderManager::eBSSMPassEnum, bool)
    // void __cdecl BeamShader::*()
    // void __cdecl BeamShader::*()
    // BeamShader& __cdecl BeamShader::*(const BeamShader&)
    // void __cdecl BeamShader::*()
};
#pragma pack(pop)
#endif
