// bsshader/imagespaceeffecthdr_decls.h: declares MemoryManager, ImageSpaceShaderParam, ImageSpaceManager
#ifndef IMAGESPACEEFFECTHDR_DECLS_H
#define IMAGESPACEEFFECTHDR_DECLS_H

#include <stddef.h>
#include "../../include/NiTArray.h"
#include "../../include/NiTMallocInterface.h"
#include "../../include/MemoryManager.h"
#include "../../include/NiRenderTargetGroup.h"
#include "../../include/NiRenderer.h"
void operator delete(void*);
class ImageSpaceEffect;
class HdrEffectParamLocalForm;
class ImageSpaceManager;
class ImageSpaceTexture;
extern MemoryManager g_memoryManager;
// SetAt consumes the reference without retaining its address.
template <> __declspec(noalias) void NiTArray<HdrEffectParamLocalForm*, NiTMallocInterface<HdrEffectParamLocalForm*> >::SetAt(unsigned int, HdrEffectParamLocalForm* const&);
class HdrEffectParamLocalForm
{ // local form of ImageSpaceEffectParam: 0x00BAD580 needs the 0x24-byte vtable/two-array base; the frozen shared size-1 declaration fails the exe-derived size/offset assertions.
  public:
    void** m_ppVirtualMethodTable;
    unsigned char textureArrays[32];
};
class ImageSpaceShaderParam : public HdrEffectParamLocalForm
{
  public:
    int m_eShaderFilterMode;
    int m_eClearFlags;
    float m_eTextureClampMode[4];
    float* m_pfVertexShaderConstants;
    int m_iVertexShaderConstantCount;
    float* m_pfPixelShaderConstants;
    int m_iPixelShaderConstantCount;
    void* m_pVertexShaderConstantMap;
    void* m_pPixelShaderConstantMap;
    bool m_bTextureFlags[3];
    unsigned char layoutPadding57;
    unsigned char inputArraysAndStates[48];
    ImageSpaceShaderParam();
    static void* operator new(size_t size)
    {
        return g_memoryManager.Allocate(size);
    }
    void AllocateShaderConstants(int, int);
    void SetBlurClearMode();
    void CopyParamData(int, const float*, unsigned int);
};
class ImageSpaceEffect
{
  public:
    void** m_ppVirtualMethodTable;
    bool bIsActive, bParamsChanged;
    unsigned char layoutPadding6[2];
    NiTArray<ImageSpaceEffect*, NiTMallocInterface<ImageSpaceEffect*> > pEffectList;
    NiTArray<HdrEffectParamLocalForm*, NiTMallocInterface<HdrEffectParamLocalForm*> > pEffectParamList;
    NiTArray<ImageSpaceTexture*, NiTMallocInterface<ImageSpaceTexture*> > pTextures;
    unsigned char remainingArrays[32];
    void SetTextureArrayCount(int);
    void SetEffectAt(int, ImageSpaceEffect*, HdrEffectParamLocalForm*, int);
};
class HDRImageSpaceEffect : public ImageSpaceEffect
{
  public:
    float m_afHDRParameters[4];
    bool m_bUseLowResolutionPath;
    unsigned char layoutPadding69[3];
    float* pVector4;
    void Setup(ImageSpaceManager*, HdrEffectParamLocalForm*);
};
#include "../../include/ImageSpaceManager.h"
// inlined into the Setup functions (/O2); the shared header only declares it
inline ImageSpaceEffect* ImageSpaceManager::GetEffect(int index)
{
    return reinterpret_cast<NiTArray<ImageSpaceEffect*, NiTMallocInterface<ImageSpaceEffect*> >*>(pEffectList)->m_pBase[index];
}

extern bool DAT_011f941f;
extern bool DAT_011f9420;
extern const float DAT_011add48[];
extern const float DAT_011add88[];
extern const float DAT_011ade88[];
typedef char shader_param_size[(sizeof(ImageSpaceShaderParam) == 0x88) ? 1 : -1];
typedef char hdr_aniso_offset[(offsetof(HDRImageSpaceEffect, m_bUseLowResolutionPath) == 0x68) ? 1 : -1];
#endif
