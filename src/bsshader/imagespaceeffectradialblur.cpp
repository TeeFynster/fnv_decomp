
// src/bsshader/imagespaceeffectradialblur.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsshader/imagespaceeffectradialblur.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#define FNV64_NIPOINTER_INLINE_BODIES
#include "../../include/ImageSpaceTexture.h"
// 0x00b5a590 initializes four unaligned scalar matrix rows.
struct RadialShaderRow_00b5a590 { float x, y, z, w; };
#include <string.h>

extern "C" void* __cdecl DeallocateAlias(void*);

struct FUN_00b5a700_shell
{
    void FUN_00b5a110();
    void* FUN_00b5a700(int flag);
};

// Calls FUN_00b5a110, then deallocates this via g_memoryManager if flag has bit 1 set, and returns this.
// @fnv 0x00b5a700
void* FUN_00b5a700_shell::FUN_00b5a700(int flag)
{
    FUN_00b5a110();
    if (flag & 1)
        g_memoryManager.Deallocate(this);
    return this;
}

struct S_00b5a4a0_MM
{
    void* Allocate(unsigned int size);
    void Deallocate(void* p);
};
extern S_00b5a4a0_MM g_00b5a4a0_mm;

struct S_00b5a4a0_EffectParam
{
    int unk0;
};

struct S_00b5a4a0_Param : S_00b5a4a0_EffectParam
{
    S_00b5a4a0_Param();
    static void* operator new(unsigned int size)
    {
        return g_00b5a4a0_mm.Allocate(size);
    }
    static void operator delete(void* p)
    {
        g_00b5a4a0_mm.Deallocate(p);
    }
    void FUN_00b8ab10(int a, int b);
    void FUN_00b8a790(int idx, float x, float y, float z, float w);
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
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

struct S_00b5a4a0_ParamArray
{
    void FUN_00ba3aa0(unsigned int idx, S_00b5a4a0_EffectParam* const& p);
};

struct S_00b5a4a0_Holder
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
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
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    ImageSpaceTexture* unkD8[8];
};

struct S_00b5a4a0_Src
{
    int unk0;
    int unk4;
    S_00b5a4a0_Holder* unk8;
};

extern int g_00b5a4a0_index;

struct S_00b5a4a0
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    S_00b5a4a0_ParamArray m_params;
    void SetTextureArraySize(int n);
    void FUN_00ba3c70(int idx, ImageSpaceTexture* tex, S_00b5a4a0_Param* param, int d);
    void SetEffectParamAt(int a, int b, int c);
    void ImageSpaceEffect__Setup(S_00b5a4a0_Src* src, int unused);
};

// @fnv 0x00b5a4a0
// src: COMMUNITY 0x00b5a4a0
void S_00b5a4a0::ImageSpaceEffect__Setup(S_00b5a4a0_Src* src, int unused)
{
    SetTextureArraySize(1);
    S_00b5a4a0_Param* param = new S_00b5a4a0_Param;
    param->FUN_00b8ab10(0, 2);
    param->FUN_00b8a790(0, 0.1f, 0.0f, 0.0f, 0.0f);
    FUN_00ba3c70(0, src->unk8->unkD8[g_00b5a4a0_index], param, 0);
    m_params.FUN_00ba3aa0(0, param);
    SetEffectParamAt(0, 1, 0);
}

extern float g_f_01013974;
extern float g_f_012023e0;


struct S_EffectArray
{
    void SetSize(unsigned int size);
};

struct ImageSpaceEffect
{
    virtual ~ImageSpaceEffect();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    S_EffectArray m_effectTextures;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;

    ImageSpaceEffect();
};

struct S_00b5a590_Matrix
{
    // The game's vectors are packed at four-byte boundaries; the shared
    // SIMD type requires sixteen-byte alignment when stored as a member.
    float m_vectors[16];
    float m_40;
    int unk44;

    S_00b5a590_Matrix()
    {
        RadialShaderRow_00b5a590& m_00 = *reinterpret_cast<RadialShaderRow_00b5a590*>(m_vectors);
        RadialShaderRow_00b5a590& m_10 = *reinterpret_cast<RadialShaderRow_00b5a590*>(m_vectors + 4);
        RadialShaderRow_00b5a590& m_20 = *reinterpret_cast<RadialShaderRow_00b5a590*>(m_vectors + 8);
        RadialShaderRow_00b5a590& m_30 = *reinterpret_cast<RadialShaderRow_00b5a590*>(m_vectors + 12);
        float zero = 0.0f;
        m_00.x = zero;
        m_00.y = zero;
        m_00.z = zero;
        m_00.w = zero;
        m_10.x = zero;
        m_10.y = zero;
        m_10.z = zero;
        m_10.w = zero;
        m_20.x = zero;
        m_20.y = zero;
        m_20.z = zero;
        m_20.w = zero;
        m_30.x = zero;
        m_30.y = zero;
        m_30.z = zero;
        m_30.w = zero;
    }
};

struct FUN_00b5a590 : ImageSpaceEffect
{
    int unk58;
    S_00b5a590_Matrix m_5c;
    ImageSpaceTexture m_texA4;
    ImageSpaceTexture m_texB4[2];

    FUN_00b5a590();
    ~FUN_00b5a590();
};

// @fnv 0x00b5a590
FUN_00b5a590::FUN_00b5a590()
{
    m_effectTextures.SetSize(4);

    float values[4] = {1.0f, g_f_01013974, 0.0f, g_f_012023e0};
    memcpy(m_5c.m_vectors + 8, values, sizeof(values));
    values[0] = 0.0f;
    values[1] = 1.0f;
    values[2] = 1.0f;
    values[3] = 0.0f;
    memcpy(m_5c.m_vectors + 4, values, sizeof(values));
    m_5c.m_40 = 600.0f;
    unk58 = 0;
}

extern float DAT_0101e2bc;
extern float DAT_01013974;
extern float DAT_01013d84;
extern float DAT_012023e0;

struct ParamAccessor
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50;
    short unk54;
    char byte56;
};

struct FUN_00b5a720_cls : S_00b5a4a0
{
    void FUN_00ba3ba0(int a, int b, int c, int d, int e, int f, int g);
    void ImageSpaceEffectDepthRadialBlur_Setup(S_00b5a4a0_Src* src, int unused);
};

// Initializes two texture parameters from src, sets their values and flags, and registers them in m_params.
// @fnv 0x00b5a720
// src: XBOX_PDB 0x00b5a720
void FUN_00b5a720_cls::ImageSpaceEffectDepthRadialBlur_Setup(S_00b5a4a0_Src* src, int unused)
{
    S_00b5a4a0_Param* p;

    SetTextureArraySize(2);

    p = new S_00b5a4a0_Param();
    p->FUN_00b8ab10(0, 2);
    p->FUN_00b8a790(0, DAT_0101e2bc, 0.0f, 0.0f, 0.0f);

    ImageSpaceTexture* tex = src->unk8->unkD8[g_00b5a4a0_index];
    FUN_00ba3c70(0, tex, p, 2);

    m_params.FUN_00ba3aa0(0, p);
    SetEffectParamAt(0, 1, 1);

    p = new S_00b5a4a0_Param();
    p->FUN_00b8ab10(0, 3);
    p->FUN_00b8a790(0, 1.0f, DAT_01013974, DAT_01013d84, DAT_012023e0);

    ((ParamAccessor*)p)->byte56 = 0;
    m_params.FUN_00ba3aa0(1, p);

    FUN_00ba3ba0(1, 1, 2, 3, 0, 1, 0);

    FUN_00ba3c70(1, reinterpret_cast<ImageSpaceTexture*>(src->unk8->unkCC), p, 0);
    if (0)
        m_params.FUN_00ba3aa0(0, p);
}
