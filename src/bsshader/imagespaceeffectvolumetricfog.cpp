
// src/bsshader/imagespaceeffectvolumetricfog.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsshader/imagespaceeffectvolumetricfog.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../include/MemoryManager.h"
#include "../../include/ImageSpaceEffectParam.h"

typedef unsigned int size_t;

struct ImageSpaceTexture;

#include "../../include/NiTMallocInterface.h"
#include "../../include/NiTPrimitiveArray.h"

extern MemoryManager g_memoryManager;

void __cdecl _Deallocate(void* p);

struct ImageSpaceShaderParam : public ImageSpaceEffectParam
{
    char pad[0x88];

    void* operator new(size_t size)
    {
        return g_memoryManager.Allocate(size);
    }
    void operator delete(void* p)
    {
        _Deallocate(p);
    }

    ImageSpaceShaderParam();
    void FUN_00b8ab10(int a2, int a3);
    void FUN_00b8a790(int a2, float f1, float f2, float f3, float f4);
};

struct Arg2Inner
{
    char pad[0xa8];
    int field_a8;
};

struct Arg2
{
    char pad[8];
    Arg2Inner* field_8;
};

struct FUN_00c05780_class
{
    char pad_00[0x18];
    NiTPrimitiveArray<ImageSpaceEffectParam*> m_shaderParams;
    NiTPrimitiveArray<ImageSpaceTexture*> m_textures;

    void SetTextureArraySize(int a2);
    void SetArrayEntry(int a2, int a3, int a4, int a5, int a6);
    void FUN_00ba3c70(int a2, int a3, ImageSpaceShaderParam* param, int a5);

    void InitShaderEffect(Arg2* a2, void* a3);
};

// @fnv 0x00c05780
void FUN_00c05780_class::InitShaderEffect(Arg2* a2, void* pUnused)
{
    SetTextureArraySize(1);
    m_textures.SetSize(2);
    ImageSpaceShaderParam* param = new ImageSpaceShaderParam();
    param->FUN_00b8ab10(0, 1);
    param->FUN_00b8a790(0, 1.0f, 1.0f, 1.0f, 1.0f);
    m_shaderParams.SetAt(0, param);
    SetArrayEntry(0, 1, -1, 1, 0);
    FUN_00ba3c70(0, a2->field_8->field_a8, param, 0);
}
