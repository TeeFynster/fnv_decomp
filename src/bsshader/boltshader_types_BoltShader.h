// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BOLTSHADER_H
#define FNV_BOLTSHADER_H

#include <stddef.h>
#include "../../include/BSShader.h"
#include "../../include/BSSimpleArray.h"
#include "../../include/NiD3DDefaultShader.h"
#include "../../include/NiD3DShader.h"
#include "../../include/NiD3DShaderInterface.h"
#include "../../include/NiShader.h"
#include "../../include/NiColorA.h"
class BoltShader;
class BoltShader__SegmentData;
class Direct3DDeviceInterface;
class NiD3DPass;
class NiD3DPixelShader;
class D3DRenderStateGroup;
class NiD3DShaderConstantMap;
class NiD3DVertexDeclaration;
class NiD3DVertexShader;
class NiDynamicEffectState;
class ShaderPassRenderer;
class GraphicsRenderer;
#include "../../include/BSShaderManager.h"
#pragma pack(push, 4)
class BoltShader : public BSShader
{
  public:
    BSShaderManager::eBSSMPassEnum m_ePass;           // +0x6C, 4 bytes
    BoltShader__SegmentData* BoltShaderSegmentState;  // +0x70, 4 bytes
    float m_fPackageValue;                                     // +0x74, 4 bytes
    float BoltShaderPassData[40];                     // +0x78, 160 bytes
    NiColorA EyePosition;                            // +0x118, 16 bytes
    float m_fMatrix[16];                              // +0x128, 64 bytes
    NiPointer<NiD3DPass> BoltShaderRenderData;        // +0x168, 4 bytes
    NiColorA CoreColor;                              // +0x16C, 16 bytes
    NiColorA GlowColor;                              // +0x17C, 16 bytes
    NiPointer<NiD3DVertexShader> BoltShaderPass;      // +0x18C, 4 bytes
    NiPointer<NiD3DPixelShader> BoltShaderResources;  // +0x190, 4 bytes
    virtual void vfn_13c();
    virtual void vfn_140();
    BoltShader(NiD3DVertexDeclaration*);
    BSShader* CreateShader();
    void UpdateShaderConstants();
    static void* operator new(unsigned int);
    // const NiRTTI* __cdecl BoltShader::*()
    // BoltShader
    // void __cdecl BoltShader::*()
    // void __cdecl BoltShader::*()
    // bool __cdecl BoltShader::*()
    // void __cdecl BoltShader::*()
    // void __cdecl BoltShader::*()
    // BoltShaderProperty* __cdecl BoltShader::*(NiNode*, bool)
    // void __cdecl BoltShader::*(NiNode*, BoltShaderProperty*)
    // NiGeometry* __cdecl BoltShader::*()
    // int __cdecl BoltShader::*()
    // int __cdecl BoltShader::*()
    // float* __cdecl BoltShader::*()
    // void __cdecl BoltShader::*()
    // unsigned int __cdecl BoltShader::*()
    // void __cdecl BoltShader::*()
    // void __cdecl BoltShader::*(BSShaderManager::eBSSMPassEnum, bool)
    // void __cdecl BoltShader::*()
    // void __cdecl BoltShader::*(int)
    // int __cdecl BoltShader::*()
    // void __cdecl BoltShader::*()
    // BoltShader& __cdecl BoltShader::*(const BoltShader&)
    // void __cdecl BoltShader::*()
};
#pragma pack(pop)
typedef char BoltShader_size_check[(sizeof(BoltShader) == 404) ? 1 : -1];
typedef char BoltShader_m_ePass_offset_check[(offsetof(BoltShader, m_ePass) == 108) ? 1 : -1];
typedef char BoltShader_BoltShaderSegmentState_offset_check[(offsetof(BoltShader, BoltShaderSegmentState) == 112) ? 1 : -1];
typedef char BoltShader_m_fPackageValue_offset_check[(offsetof(BoltShader, m_fPackageValue) == 116) ? 1 : -1];
typedef char BoltShader_BoltShaderPassData_offset_check[(offsetof(BoltShader, BoltShaderPassData) == 120) ? 1 : -1];
typedef char BoltShader_EyePosition_offset_check[(offsetof(BoltShader, EyePosition) == 280) ? 1 : -1];
typedef char BoltShader_m_fMatrix_offset_check[(offsetof(BoltShader, m_fMatrix) == 296) ? 1 : -1];
typedef char BoltShader_BoltShaderRenderData_offset_check[(offsetof(BoltShader, BoltShaderRenderData) == 360) ? 1 : -1];
typedef char BoltShader_CoreColor_offset_check[(offsetof(BoltShader, CoreColor) == 364) ? 1 : -1];
typedef char BoltShader_GlowColor_offset_check[(offsetof(BoltShader, GlowColor) == 380) ? 1 : -1];
typedef char BoltShader_BoltShaderPass_offset_check[(offsetof(BoltShader, BoltShaderPass) == 396) ? 1 : -1];
typedef char BoltShader_BoltShaderResources_offset_check[(offsetof(BoltShader, BoltShaderResources) == 400) ? 1 : -1];
#endif
