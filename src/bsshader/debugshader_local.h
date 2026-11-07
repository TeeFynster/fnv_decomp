// MSVC9 SP1 layout check: PASS
// CodeView tag codeview-tag-layout:sha256:36e0a9263f6adaa82628844d2452e2877a9895682d5dc437b88709308025b9f0; PC corrections inherited from generate_headers.py.
// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef DEBUGSHADER_LOCAL_H
#define DEBUGSHADER_LOCAL_H

#include <stddef.h>
#define FNV_DEBUG_JOIN_I(a, b) a##b
#define FNV_DEBUG_JOIN(a, b) FNV_DEBUG_JOIN_I(a, b)
#define FNV_STATIC_ASSERT(c) typedef char FNV_DEBUG_JOIN(fnv_debug_assert_, __LINE__)[(c) ? 1 : -1]

#include "NiFixedString.h"
#include "NiMemObject.h"
#include "NiRefObject.h"
#include "NiObjectNET.h"
#include "../../include/NiAVObject.h"
#include "../../include/NiTexture.h"

// This unit uses the Gamebryo inline smart-pointer operations.
template <class T> inline NiPointer<T>::NiPointer() : m_pObject(0) {}
template <class T> inline NiPointer<T>::~NiPointer()
{
    if (m_pObject != 0)
        m_pObject->DecRefCount();
}
template <class T> inline NiPointer<T>& NiPointer<T>::operator=(T* pkNew)
{
    if (m_pObject != pkNew)
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = pkNew;
        if (pkNew != 0)
            pkNew->IncRefCount();
    }
    return *this;
}
template <class T> inline NiPointer<T>& NiPointer<T>::operator=(const NiPointer<T>& kSrc)
{
    if (m_pObject != kSrc.m_pObject)
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = kSrc.m_pObject;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    return *this;
}
#include "../../include/BSShader.h"
#include "../../include/NiD3DDefaultShader.h"
#include "../../include/NiD3DPass.h"
#include "../../include/NiD3DPixelShader.h"
#include "../../include/NiD3DShader.h"
#include "../../include/NiD3DShaderConstantMap.h"
#include "../../include/NiD3DShaderDeclaration.h"
#include "../../include/NiD3DShaderInterface.h"
#include "../../include/NiD3DShaderProgram.h"
#include "../../include/NiD3DVertexShader.h"
#include "../../include/NiGPUProgram.h"
#include "../../include/NiGeometry.h"
#include "../../include/NiScreenElements.h"
#include "../../include/NiShader.h"
#include "../../include/NiTriBasedGeom.h"

class BeamStage;
class Direct3DDeviceInterface;
class BloodSplatterBeamShader;
class NiD3DDefaultShader__PassFogStatus;
class D3DRenderStateGroup;
class NiDynamicEffectState;
class ShaderPassRenderer;
class GraphicsRenderer;

#pragma pack(push, 4)
class BloodSplatterBeamShader : public BSShader
{
  public:
    NiPointer<NiTexture> m_pTextures[16];                         // +0x6C, 64 bytes
    NiPointer<NiScreenElements> m_pMenuBackgroundScreenGeometry;  // +0xAC, 4 bytes
    NiPointer<NiD3DVertexShader> m_spTreeVertexShader;            // +0xB0, 4 bytes
    NiPointer<NiD3DPixelShader> m_spPixelShaderVariants[2];       // +0xB4, 8 bytes
    unsigned int m_uiShaderState;                                 // +0xBC, 4 bytes
    BloodSplatterBeamShader();
    virtual ~BloodSplatterBeamShader();
    static BSShader* CreateShader();
    void InitializeShaderData();
    bool ConfigureShaderPass();
    // BloodSplatterBeamShader
    // void __cdecl BloodSplatterBeamShader::*()
    // bool __cdecl BloodSplatterBeamShader::*(NiGeometry*)
    // unsigned int __cdecl BloodSplatterBeamShader::*(NiGeometry*, const NiSkinInstance*, NiGeometryData::RendererData*, const NiPropertyState*, const NiDynamicEffectState*, const NiTransform&, const NiBound&)
    // unsigned int __cdecl BloodSplatterBeamShader::*(NiGeometry*, const NiSkinInstance*, NiGeometryData::RendererData*, const NiPropertyState*, const NiDynamicEffectState*, const NiTransform&, const NiBound&)
    // void __cdecl BloodSplatterBeamShader::*()
    // bool __cdecl BloodSplatterBeamShader::*()
    // void __cdecl BloodSplatterBeamShader::*(BSRenderedTexture*)
    // void __cdecl BloodSplatterBeamShader::*(BSRenderedTexture*)
    // void __cdecl BloodSplatterBeamShader::*(NiTexture*)
    // void __cdecl BloodSplatterBeamShader::*(BSRenderedTexture*, char*)
    // void __cdecl BloodSplatterBeamShader::*()
    // bool __cdecl BloodSplatterBeamShader::*()
    // BloodSplatterBeamShader& __cdecl BloodSplatterBeamShader::*(const BloodSplatterBeamShader&)
    // void __cdecl BloodSplatterBeamShader::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BloodSplatterBeamShader) == 192);
FNV_STATIC_ASSERT(offsetof(BloodSplatterBeamShader, m_pTextures) == 108);
FNV_STATIC_ASSERT(offsetof(BloodSplatterBeamShader, m_pMenuBackgroundScreenGeometry) == 172);
FNV_STATIC_ASSERT(offsetof(BloodSplatterBeamShader, m_spTreeVertexShader) == 176);
FNV_STATIC_ASSERT(offsetof(BloodSplatterBeamShader, m_spPixelShaderVariants) == 180);
FNV_STATIC_ASSERT(offsetof(BloodSplatterBeamShader, m_uiShaderState) == 188);

class NiRenderer;

class NiD3DVertexDeclaration : public NiD3DShaderDeclaration
{
  public:
    static NiD3DVertexDeclaration* Create(NiRenderer*, unsigned int, unsigned int);
};
extern NiRenderer* DAT_011f9508;

class BeamStage
{
  public:
    unsigned char layoutPadding0[8];
    unsigned int m_uiTextureStage;
    unsigned char layoutPaddingC[0x54];
    unsigned int m_uiRefCount;
    static void CreateNewStage(NiPointer<BeamStage>&);
    void NiD3DTextureStage_SetFilterMode(unsigned int);
    void ReturnToPool();
    void IncRefCount()
    {
        ++m_uiRefCount;
    }
    void DecRefCount()
    {
        if (--m_uiRefCount == 0)
            ReturnToPool();
    }
};
class D3DRenderStateGroup
{
  public:
    static D3DRenderStateGroup* GetCurrentRenderStateGroup();
    void SetRenderState(unsigned int, unsigned int, bool);
};

void ConfigureBeamStage(BeamStage*, unsigned int, unsigned int, unsigned int, bool);

#endif
