// bsshader/imagespaceeffectrefraction_decls.h: local image-space effect declarations
#ifndef IMAGESPACEEFFECTREFRACTION_DECLS_H
#define IMAGESPACEEFFECTREFRACTION_DECLS_H

#include "layout_support.h"
#include "MemoryManager.h"
#include "../../include/BSTextureManager.h"
#include "../../include/NiRenderer.h"
#include "../../include/NiColorA.h"
#define FNV64_NIPOINTER_INLINE_BODIES
#include "NiRefObject_inline.h"
#include "../../include/ImageSpaceTexture.h"
// WaterTintRecord_imagespaceeffectrefraction_decls: local type (was include/WaterTintRecord.h, which had no evidence of one real class); no method of it is bound to a named game function
struct WaterTintRecord_imagespaceeffectrefraction_decls
{
    float r;
    float g;
    float b;
    float a;

    WaterTintRecord_imagespaceeffectrefraction_decls(float fR, float fG, float fB, float fA)
        : r(fR), g(fG), b(fB), a(fA)
    {}
};

class ImageSpaceEffect;
class ImageSpaceManager;
class NiTexture;
extern MemoryManager g_memoryManager;

#include "../../include/NiTPrimitiveArray.h"

extern WaterTintRecord_imagespaceeffectrefraction_decls g_waterTintRecords[];

// The approved shared RefractionEffectParamLocalForm lacks the 0x24-byte data layout used here.
class RefractionEffectParamLocalForm
{ // local form of ImageSpaceEffectParam: 0x00bd9420 needs the 0x24-byte vtable/two-array base; the frozen shared size-1 declaration fails the exe-derived size/offset assertions.
  public:
    void** m_ppVirtualMethodTable;
    NiTPrimitiveArray<int> m_kTextureTypes;
    NiTPrimitiveArray<int> m_kFilterModes;
};

class ImageSpaceShaderParam : public RefractionEffectParamLocalForm
{
  public:
    int m_eShaderFilterMode;
    unsigned int m_eClearFlags;
    NiColorA m_eTextureClampMode;
    float* m_pfVertexShaderConstants;
    int m_iVertexShaderConstantCount;
    float* m_pfPixelShaderConstants;
    int m_iPixelShaderConstantCount;
    void* m_pVertexShaderConstantMap;
    void* m_pPixelShaderConstantMap;
    bool m_bTextureFlags[3];
    NiTObjectArray<void*> m_kShaderTextures;
    NiTPrimitiveArray<int> m_kTextureFilterModes;
    void* m_kRenderStateMap[4];

    ImageSpaceShaderParam();
    void AllocateShaderConstants(int vertexCount, int pixelCount);
    void SetShaderConstantVector4(int index, float x, float y, float z, float w);
    static void* operator new(unsigned int size)
    {
        return g_memoryManager.Allocate(size);
    }
    static void operator delete(void* memory)
    {
        g_memoryManager.Deallocate(memory);
    }
};

class ImageSpaceEffect
{
  public:
    virtual ~ImageSpaceEffect();
    bool bIsActive;
    bool bParamsChanged;
    NiTPrimitiveArray<ImageSpaceEffect*> pEffectList;
    NiTPrimitiveArray<RefractionEffectParamLocalForm*> pEffectParamList;
    NiTPrimitiveArray<ImageSpaceTexture*> pTextures;
    NiTPrimitiveArray<void*> pEffectInputs;
    NiTPrimitiveArray<int> pEffectOutput;

    ImageSpaceEffect();
    void SetTextureArrayCount(int count);
    void SetTextureArrayAt(int index, int first, int second, int firstFilter, int secondFilter);
    void SetEffectAt(int index, ImageSpaceEffect* effect, RefractionEffectParamLocalForm* param, int output);
};

class RefractionImageSpaceEffect : public ImageSpaceEffect
{
  public:
    RefractionImageSpaceEffect();
    virtual ~RefractionImageSpaceEffect();
    ImageSpaceTexture m_kRefractionTexture;
    void Setup(ImageSpaceManager* manager, RefractionEffectParamLocalForm* param);
    BSRenderedTexture* GetRefractionTexture(bool create);
};

#include "../../include/ImageSpaceManager.h"

extern BSTextureManager* DAT_011f91a8;
extern int DAT_011bf400;

FNV_STATIC_ASSERT(sizeof(ImageSpaceShaderParam) == 0x88);
FNV_STATIC_ASSERT(sizeof(ImageSpaceEffect) == 0x58);
FNV_STATIC_ASSERT(offsetof(ImageSpaceEffect, pEffectParamList) == 0x18);
FNV_STATIC_ASSERT(offsetof(ImageSpaceEffect, pTextures) == 0x28);
FNV_STATIC_ASSERT(offsetof(RefractionImageSpaceEffect, m_kRefractionTexture) == 0x58);
#endif
