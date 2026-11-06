// bsshader/imagespaceeffectmenubg_decls.h: local declarations for the menu background effect
#ifndef FNV_IMAGESPACEEFFECTMENUBG_DECLS_H
#define FNV_IMAGESPACEEFFECTMENUBG_DECLS_H
#include "../../include/NiTMallocInterface.h"
#include "../../include/NiTNewInterface.h"
#include "../../include/NiTArray.h"
#include "../../include/NiTexture.h"
#include "../../include/ImageSpaceTexture.h"
#include "../../include/NiPointer.h"
#include "../../include/NiTMap.h"

#include <stddef.h>
#include "../../include/BSShaderManager.h"
#include "../../include/NiD3DShaderConstantMap.h"
#include "../../include/NiTexturingProperty.h"
#include "../../include/NiColorA.h"
#include "MemoryManager.h"
#include "NiRefObject.h"

#include "../../include/NiTNewInterface.h"
#include "../../include/NiTObjectArray.h"

extern MemoryManager g_memoryManager;
extern bool DAT_011f941e;
template <class T> inline NiPointer<T>::NiPointer() : m_pObject(0)
{}

template <class T> inline NiPointer<T>::NiPointer(T* object) : m_pObject(object)
{
    if (m_pObject)
        m_pObject->NiRefObject::IncRefCount();
}

template <class T> inline NiPointer<T>::~NiPointer()
{
    if (m_pObject)
        m_pObject->NiRefObject::DecRefCount();
}
class MenuBgEffectParamLocalForm;
class ImageSpaceEffect;

// PC array layout and the operations used by this effect.

class MenuBgEffectParamLocalForm
{ // local form of ImageSpaceEffectParam: 0x00c04730 needs the 0x24-byte vtable/two-array base; the frozen shared size-1 declaration fails the exe-derived size/offset assertions.
  public:
    void** m_ppVirtualMethodTable;
    NiTArray<int, NiTMallocInterface<int> > m_kTextureTypes;
    NiTArray<NiTexturingProperty::FilterMode, NiTMallocInterface<NiTexturingProperty::FilterMode> > m_kFilterModes;
};
class ImageSpaceShaderParam : public MenuBgEffectParamLocalForm
{
  public:
    NiTexturingProperty::FilterMode m_eShaderFilterMode;  // +0x24
    unsigned int m_eClearFlags;
    NiColorA m_eTextureClampMode;
    float* m_pfVertexShaderConstants;
    int m_iVertexShaderConstantCount;
    float* m_pfPixelShaderConstants;
    int m_iPixelShaderConstantCount;
    NiPointer<NiD3DShaderConstantMap> m_pVertexShaderConstantMap;
    NiPointer<NiD3DShaderConstantMap> m_pPixelShaderConstantMap;
    bool m_bTextureFlags[3];
    NiTObjectArray<NiPointer<NiTexture> > m_kShaderTextures;
    NiTArray<NiTexturingProperty::FilterMode, NiTMallocInterface<NiTexturingProperty::FilterMode> >
        m_kTextureFilterModes;
    NiTMap<unsigned int, unsigned int> m_kRenderStateMap;
    ImageSpaceShaderParam();
    void AllocateShaderConstants(int vertexCount, int pixelCount);
    void SetShaderConstantVector4(int index, float x, float y, float z, float w);
    static void* operator new(unsigned int size)
    {
        return g_memoryManager.Allocate(size);
    }
    static void operator delete(void* pointer)
    {
        g_memoryManager.Deallocate(pointer);
    }
};
class ImageSpaceEffect
{
  public:
    void** m_ppVirtualMethodTable;
    bool bIsActive, bParamsChanged;
    NiTArray<ImageSpaceEffect*, NiTMallocInterface<ImageSpaceEffect*> > pEffectList;
    NiTArray<MenuBgEffectParamLocalForm*, NiTMallocInterface<MenuBgEffectParamLocalForm*> > pEffectParamList;
    NiTArray<ImageSpaceTexture*, NiTMallocInterface<ImageSpaceTexture*> > pTextures;
    NiTArray<void*, NiTMallocInterface<void*> > pEffectInputs;
    NiTArray<int, NiTMallocInterface<int> > pEffectOutput;
    void SetTextureArrayCount(int count);
    void SetTextureArrayAt(int index, int first, int second, NiTexturingProperty::FilterMode firstFilter,
                           NiTexturingProperty::FilterMode secondFilter);
    void SetEffectAt(int index, ImageSpaceEffect* effect, MenuBgEffectParamLocalForm* parameters, int output);
};
// Only the manager prefix accessed by Setup is needed here.
#include "../../include/ImageSpaceManager.h"
class ImageSpaceEffectMenuBackground : public ImageSpaceEffect
{
  public:
    ImageSpaceTexture* m_pBackgroundTexture;
    float m_fBackgroundBlendAmount;
    bool m_bMenuBackgroundEnabled;
    void Setup(ImageSpaceManager* manager, MenuBgEffectParamLocalForm* parameters);
};
typedef char ImageSpaceTexture_size_check[(sizeof(ImageSpaceTexture) == 16) ? 1 : -1];
typedef char ImageSpaceShaderParam_size_check[(sizeof(ImageSpaceShaderParam) == 136) ? 1 : -1];
typedef char ImageSpaceEffect_size_check[(sizeof(ImageSpaceEffect) == 88) ? 1 : -1];
typedef char ImageSpaceShaderParam_textures_offset_check[(offsetof(ImageSpaceShaderParam, m_kShaderTextures) == 88) ? 1 : -1];
typedef char ImageSpaceShaderParam_renderState_offset_check[(offsetof(ImageSpaceShaderParam, m_kRenderStateMap) == 120) ? 1 : -1];
typedef char ImageSpaceEffectMenuBackground_texture_offset_check[(offsetof(ImageSpaceEffectMenuBackground, m_pBackgroundTexture) == 88) ? 1 : -1];
#endif
