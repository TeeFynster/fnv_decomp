// fallout_shared/bgstextureset_o2_variant.cpp: ThunkDerived (5 functions)

#include <windows.h>
#include "../../include/NiRenderer.h"
// src/fallout_shared/bgstextureset_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/bgstextureset.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// Fallout: New Vegas decompilation: fallout_shared/bgstextureset.cpp.
class BGSTextureSet;
void BGSTextureSet_ClearNullTextureSet();
BGSTextureSet* __cdecl BGSTextureSet_GetNullTextureSet();
void __cdecl _Deallocate(void*);
struct S591140
{
    void FUN_00591170();
    void* FUN_00591140(unsigned int);
};
void __cdecl _delete(void*, unsigned int);
struct Holder
{
    void FUN_005923c0();
    void* FUN_00592380(unsigned int flags);
};
struct FullNameEx
{
    int _m0;
    int _m1;
    int _m2;
    void SetFullName(char const*);
};
struct Holder00592cc0
{
    char _pad[56];
    FullNameEx _arr[6];
    void SetFullNameByType(int, char const*);
};

float __cdecl BSMIN(float, float);
extern float DAT_011f945c;
extern float DAT_011f9460;
extern float DAT_011f9464;
extern float DAT_011f9468;
struct FUN_00b66c40_t
{
    char pad00[0x20];
    unsigned int uiFlags;
    unsigned int uiFlags2;
    char pad28[0xc];
    float fTime;
    float BSShaderPPLightingProperty_GetEnvMapLODFade();
};
// @fnv 0x00b66c40
// src: XBOX_PDB 0x00b66c40
float FUN_00b66c40_t::BSShaderPPLightingProperty_GetEnvMapLODFade()
{
    bool bFadeInActive = (uiFlags & 0x80) > 0 && !((uiFlags2 & 0x800000) > 0) && DAT_011f9460 > 0.0f;
    bool bFadeOut = (uiFlags & 0x20000) > 0 && !((uiFlags2 & 0x800000) > 0) && DAT_011f9468 > 0.0f;
    float fResult = 1.0f;
    if (bFadeOut)
    {
        if (fTime < DAT_011f9464)
            fResult = 1.0f;
        else if (fTime >= DAT_011f9468)
            fResult = 0.0f;
        else
        {
            fResult = (fTime - DAT_011f9464) / (DAT_011f9468 - DAT_011f9464);
            fResult = 1.0f - (1.0f < fResult ? 1.0f : fResult);
        }
    }
    else if (bFadeInActive)
    {
        if (fTime < DAT_011f945c)
            fResult = 1.0f;
        else if (fTime >= DAT_011f9460)
            fResult = 0.0f;
        else
        {
            fResult = (fTime - DAT_011f945c) / (DAT_011f9460 - DAT_011f945c);
            fResult = 1.0f - BSMIN(1.0f, fResult);
        }
    }
    return fResult;
}



struct FUN_00b66db0_Object
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual unsigned short v58();
    virtual void v59();
    virtual void v60();
    virtual void* v61(int, int);
    void BSShaderPPLightingProperty_PrecacheTextures();
};

// @fnv 0x00b66db0
// src: XBOX_PDB 0x00b66db0
void FUN_00b66db0_Object::BSShaderPPLightingProperty_PrecacheTextures()
{
    NiRenderer* pkRenderer = NiRenderer::ms_pRenderer;
    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < v58(); ++j)
        {
            void* pkItem = v61(i, j);
            if (pkItem)
            {
                // Slot 56 is not declared in the shared NiRenderer header yet.
                typedef void (__thiscall *RendererSlot56)(NiRenderer*, void*, int, int);
                reinterpret_cast<RendererSlot56>((*reinterpret_cast<void***>(pkRenderer))[56])(
                    pkRenderer, pkItem, 0, 0);
            }
        }
    }
}

extern float DAT_011f9458;
extern float DAT_011f9454;

class FUN_00b66b80_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned char m_20;
    unsigned char unk21;
    unsigned char unk22;
    unsigned char unk23;
    unsigned int m_24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    float m_34;

    float BSShaderPPLightingProperty_GetSpecularLODFade();
};

// @fnv 0x00b66b80
// src: XBOX_PDB 0x00b66b80
float FUN_00b66b80_cls::BSShaderPPLightingProperty_GetSpecularLODFade()
{
    bool ok = (m_20 & 1u) > 0 && !((m_24 & 0x800000u) > 0) && DAT_011f9458 > 0.0f;
    float result = 1.0f;
    if (ok)
    {
        if (m_34 < DAT_011f9454)
            result = 1.0f;
        else if (m_34 >= DAT_011f9458)
            result = 0.0f;
        else
        {
            float t = (m_34 - DAT_011f9454) / (DAT_011f9458 - DAT_011f9454);
            result = 1.0f - (1.0f < t ? 1.0f : t);
        }
    }
    return result;
}

// FUN_00593230 : sub ecx,0x30 ; jmp FUN_00592380
// MSVC this-adjusting (adjustor) thunk. A derived class inherits a secondary
// base at offset 0x30 inside the primary base; the vftable slot inherited from
// the secondary base still refers to the implementation living in the primary
// base, so the compiler emits a thunk that walks `this` back by the primary
// base's size (0x30) and tail-jumps to that implementation.
struct ThunkPrimaryBase
{
    virtual void* FUN_00593230(unsigned int flags);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
};

struct ThunkSecondaryBase
{
    virtual void* FUN_00593230(unsigned int flags);
};

struct ThunkDerived : ThunkPrimaryBase, ThunkSecondaryBase
{
    ThunkDerived();
// @fnv 0x00593230
    virtual void* FUN_00593230(unsigned int flags);
};

ThunkDerived::ThunkDerived()
{}

struct FnvRefObj
{
    virtual void Init();
    virtual void Free();
    volatile LONG refs;  // +0x04
};

struct FnvTarget
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35(int a);
    virtual void v36(int idx, FnvRefObj** slot);
};

extern "C" __declspec(dllimport) LONG __stdcall InterlockedDecrement(volatile LONG* p);

struct FUN_00b66ad0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
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
    FnvTarget* m_a4;  // +0xa4
    int unkA8;
    FnvRefObj** m_ac[6];  // +0xac

    void BSShaderPPLightingProperty_LoadTextureSet(int a1, FnvTarget* target);
};

// @fnv 0x00b66ad0
// src: COMMUNITY 0x00b66ad0
void FUN_00b66ad0_cls::BSShaderPPLightingProperty_LoadTextureSet(int a1, FnvTarget* target)
{
    if (target == 0)
    {
        target = m_a4;
    }
    FnvTarget* t = target;
    FnvRefObj*** base = m_ac;
    FnvRefObj*** cur = base;
    for (int i = 0; i < 6; ++i)
    {
        FnvRefObj** slot = *cur;
        FnvRefObj* obj = *slot;
        if (obj != 0)
        {
            if (InterlockedDecrement(&obj->refs) == 0)
            {
                obj->Free();
            }
            *slot = 0;
        }
        ++cur;
    }
    if (base != 0 && t != 0)
    {
        int j = 0;
        FnvRefObj*** p = base;
        for (; j < 6; ++j, ++p)
        {
            t->v36(j, *p);
        }
        if (*base[0] != 0)
        {
            t->v35(0);
        }
    }
}
