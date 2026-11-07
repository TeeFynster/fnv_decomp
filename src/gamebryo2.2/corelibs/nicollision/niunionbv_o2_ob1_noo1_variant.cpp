#include "../../../../include/NiMemObject.h"
#include "../../../../include/NiRefObject.h"
#include "../../../../include/NiGPUProgram.h"
#include "../../../../include/NiD3DShaderProgram.h"
#include "../../../../include/MemoryManager.h"


// src/gamebryo2.2/corelibs/nicollision/niunionbv_o2_ob1_noo1_variant.cpp - flag-variant unit created 2026-10-29 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Oy /GS /EHsc /Gy /O2 /Ob1 (unit src/gamebryo2.2/corelibs/nicollision/niunionbv.cpp lists /MT /O1 /Oy /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// MSVC 2008 cl does not accept the .inl extension as a source file, so this identical unit is compiled as .cpp by the matcher; the .inl is the source of record.
//
//
// gamebryo2.2/corelibs/nicollision/niunionbv.inl
//
// Inline definitions for NiD3DShaderProgram: Nivid3D shader program
// wrappers over D3D9 GPU programs. A program object owns the compiled
// code block and the creator/device handles that produced it; the
// accessors below read out the stored descriptors.
//
// Standalone build: base chain sizes taken from the MSVC 2008 layout
// evidence - NiGPUProgram is 12 bytes and NiD3DShaderProgram is 44
// bytes, with m_uiProgramCodeSize at offset 20.
//
extern MemoryManager g_memoryManager;
struct S
{
    S* NiUnionBV_NiUnionBV(void*);
};
S* __fastcall NiUnionBV_Clone(void* self);
// FUN_00e9ecc0 - 6-byte leaf stub of the retail binary.
//
// The original code is "mov eax, 4 ; ret": the function simply hands the
// constant 4 back to its caller.  A plain "return 4;" is folded by VC9 at the
// pack's /O1 into the shorter "push 4 ; pop eax ; ret" sequence, so the value
// is materialised from a relocated address expression instead.  That keeps
// the original six-byte "mov eax, <imm32> ; ret" shape byte for byte.
extern int g_fnv_00e9ecc0_value_anchor;
int bhkCharacterStateFlying_Update();

class VirtualTextureView_00e9ecd0;
struct Item
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual VirtualTextureView_00e9ecd0* GetTexture();
};
struct TextureVTable
{
    void* vf00;
    void* vf04;
    void* vf08;
    void* vf0C;
    void* vf10;
    void* vf14;
    void* vf18;
    void* vf1C;
    void(__thiscall* Attach)(VirtualTextureView_00e9ecd0*, Item*);
};
// 0x00e9ecd0 reads a vptr at +0 and calls slot +0x20; ImageSpaceTexture has flags at +0 and no vptr.
class VirtualTextureView_00e9ecd0
{
  public:
    TextureVTable* vtable;
};
struct Source
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int GetType();
    unsigned int unk04;
    Item** m_items;
    unsigned short unk0C;
    unsigned short m_uiItemCount;
};
struct TexArray
{
    void SetSize(unsigned int n);
    void SetAt(unsigned int i, VirtualTextureView_00e9ecd0*& t);
};
struct TexCache
{
    void NiUnionBV_RemoveAllBoundingVolumes();
    void NiUnionBV_Copy(Source* src);
    unsigned int unk00;
    TexArray m_textures;
};
// @fnv 0x00e9ecd0
// src: GAMEBRYO_LIB 0x00e9ecd0
void TexCache::NiUnionBV_Copy(Source* src)
{
    if (src->GetType() == 4)
    {
        NiUnionBV_RemoveAllBoundingVolumes();
        m_textures.SetSize(src->m_uiItemCount);
        for (unsigned int i = 0; i < src->m_uiItemCount; i++)
        {
            Item* item = src->m_items[i];
            VirtualTextureView_00e9ecd0* value = item->GetTexture();
            TextureVTable* table = value->vtable;
            VirtualTextureView_00e9ecd0* tex = value;
            table->Attach(value, item);
            m_textures.SetAt(i, tex);
        }
    }
}

struct Element365
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual int vf06();
};

struct Array365
{
    int unk00;
    int* unk04;
    unsigned short unk08;
    unsigned short unk0a;
    unsigned short unk0c;
    unsigned short unk0e;

    void __thiscall FUN_00a90180(unsigned int n);

    __forceinline void SetAt(unsigned int idx, int e)
    {
        if (idx >= unk0a)
        {
            unk0a = (unsigned short)(idx + 1);
            if (e)
                ++unk0c;
        }
        else if (e)
        {
            if (!unk04[idx])
                ++unk0c;
        }
        else
        {
            if (unk04[idx])
                --unk0c;
        }
        unk04[idx] = e;
    }
};

struct State365
{
    int unk00;
    Array365 arr;

    unsigned int unk14;
    State365* __thiscall FUN_00e9edd0();
};

struct Source365
{
    int unk00;
    int unk04;
    Element365** unk08;
    unsigned short unk0c;
    unsigned short unk0e;
    unsigned short GetSize() const
    {
        return unk0e;
    }

    State365* __thiscall NiUnionBV_Create();
};

// @fnv 0x00e9eef0
// src: GAMEBRYO_SRC 0x00e9eef0
State365* __thiscall Source365::NiUnionBV_Create()
{
    State365* state = static_cast<State365*>(g_memoryManager.Allocate(sizeof(State365)));

    unsigned int i = 0;
    if (state)
        state = state->FUN_00e9edd0();

    else
        state = 0;
    state->arr.FUN_00a90180(GetSize());
    for (; i < GetSize(); i++)
        state->arr.SetAt(i, unk08[i]->vf06());
    return state;
}
