
// src/bsshader/imagespaceeffectwaterfft.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsshader/imagespaceeffectwaterfft.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../include/MemoryManager.h"
#include "../../include/NiRenderer.h"
#include "../../include/NiRenderTargetGroup.h"
#include "../../include/ImageSpaceTexture.h"
#include "../../include/ImageSpaceEffectParam.h"

struct ImageSpaceTextureSet
{
    char _0[0x58];
    ImageSpaceTexture m_kTextureSlot0;
    ImageSpaceTexture m_kTextureSlot1;
    ImageSpaceTexture m_kTextureSlot2;
    ImageSpaceTexture m_kTextureSlot3;
    ImageSpaceTexture m_kTextureSlot4;
    char _5[0x10];
    bool m_bHeaderParsed;
    void ImageSpaceEffectWaterFFT_FreeUpTextureMemory();
};

// @fnv 0x00ba1250
// src: COMMUNITY 0x00ba1250
void ImageSpaceTextureSet::ImageSpaceEffectWaterFFT_FreeUpTextureMemory()
{
    if (m_kTextureSlot2.GetTexture())
        m_kTextureSlot2.AddRenderedTexture();
    if (m_kTextureSlot3.GetTexture())
        m_kTextureSlot3.AddRenderedTexture();
    if (m_kTextureSlot0.GetTexture())
        m_kTextureSlot0.AddRenderedTexture();
    if (m_kTextureSlot1.GetTexture())
        m_kTextureSlot1.AddRenderedTexture();
    if (m_kTextureSlot4.GetTexture())
        m_kTextureSlot4.AddRenderedTexture();
    m_bHeaderParsed = false;
}

extern MemoryManager g_memoryManager;

struct ImageSpaceShaderParam : ImageSpaceEffectParam
{
    ImageSpaceShaderParam();
    void SetSizeEx(int a, int b);
    void SetFloats(int idx, const float* data, unsigned int count);
    void SetReferenceVector(int idx, float x, float y, float z, float w);

    static void* operator new(unsigned int size)
    {
        return g_memoryManager.Allocate(size);
    }
    static void operator delete(void* p)
    {
        g_memoryManager.Deallocate(p);
    }

    // Preserve the unmodeled prefix through offset 0x53 after the shared base.
    int unkBaseTail[0x15 - sizeof(ImageSpaceEffectParam) / sizeof(int)];
    char unk54;
    bool bFlag55;
    bool bFlag56;
    char unk57;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
};

struct ShaderParamArray
{
    __declspec(noalias) void SetAt(unsigned int idx, ImageSpaceEffectParam* const& val);
};

extern NiRenderer* DAT_011f9508;

extern const float DAT_011add48[16];
extern float DAT_012023e0;
extern float DAT_01013d84;
extern float DAT_01013974;

struct TextureArray
{
    virtual ~TextureArray();
    void** m_pBase;
    void* GetAt(unsigned int i) const
    {
        return m_pBase[i];
    }
};

struct EffectSource
{
    int unk00;
    TextureArray textures;
};

// These calls bind to ImageSpaceEffect methods: SetTextureArraySize 0x00ba3f90, SetTexture 0x00ba3c70.
// Retained locally because include/ImageSpaceEffect.h is not available.
struct ImageSpaceEffect
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    ShaderParamArray params;

    void SetTextureArraySize(int count);
    void SetTexture(int idx, void* tex, ImageSpaceEffectParam* param, int mode);
    void SetPass3(int a, int b, int c);
    void SetPass5(int a, int b, int c, int d, int e);
    void SetPass7(int a, int b, int c, int d, int e, int f, int g);
    void SetPass9(int a, int b, int c, int d, int e, int f, int g, int h, int i);
    void SetupShaderPasses(EffectSource* src, int unused);
};

// Configures four shader passes with textures and parameters from src, using the default render target dimensions for inverse scale factors.
// @fnv 0x00bd6bb0
void ImageSpaceEffect::SetupShaderPasses(EffectSource* apSource, int unused)
{
    SetTextureArraySize(4);
    float width = DAT_011f9508->GetDefaultRT()->Unk_23(0);
    float height = reinterpret_cast<unsigned int>(DAT_011f9508->GetDefaultRT()->vf36(0));
    {
        ImageSpaceShaderParam* param = new ImageSpaceShaderParam;
        param->SetSizeEx(0, 0x18);
        param->SetFloats(3, DAT_011add48, 0x40);
        param->SetReferenceVector(2, 1.0f / width, 1.0f / height, 0.0f, 0.0f);
        param->bFlag55 = false;
        SetTexture(0, apSource->textures.GetAt(65), param, 2);
        params.SetAt(0, param);
    }
    SetPass3(0, 1, 1);
    params.SetAt(1, 0);
    SetPass5(1, 2, 3, 0, 0);
    SetTexture(1, apSource->textures.GetAt(18), 0, 2);
    {
        ImageSpaceShaderParam* param = new ImageSpaceShaderParam;
        param->SetSizeEx(0, 3);
        param->SetReferenceVector(0, 1.0f, DAT_01013974, DAT_01013d84, DAT_012023e0);
        param->bFlag56 = false;
        params.SetAt(2, param);
        SetPass7(2, 1, 2, 4, 0, 1, 0);
        SetTexture(2, apSource->textures.GetAt(51), param, 0);
    }
    {
        ImageSpaceShaderParam* param = new ImageSpaceShaderParam;
        param->SetSizeEx(0, 4);
        param->SetReferenceVector(0, 1.0f, DAT_01013974, DAT_01013d84, DAT_012023e0);
        param->bFlag56 = false;
        params.SetAt(3, param);
        SetPass9(3, 1, 2, 4, 5, 0, 1, 0, 0);
        SetTexture(3, apSource->textures.GetAt(52), param, 0);
    }
}
