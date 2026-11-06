// src/gamebryo2.2/corelibs/niparticle/nipsysemitterdeclinationvarctlr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysemitterdeclinationvarctlr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiPSysModifierFloatCtlr.h"
#include "../../../../include/StrArr.h"

extern "C" void* g_01202750;

// @fnv 0x00c2b8b0
void* __cdecl FUN_00c2b8b0()
{
    return &g_01202750;
}

struct NiPSysEmitterDeclinationVarCtlr : NiPSysModifierFloatCtlr
{
    void FUN_00c2a0b0(float fValue);
    void FUN_00c2b8c0(float& fValue);
};

// @fnv 0x00c2a0b0
void NiPSysEmitterDeclinationVarCtlr::FUN_00c2a0b0(float fValue)
{
    *(float*)((char*)m_pkTargetModifier + 0x24) = fValue;
}

// @fnv 0x00c2b8c0
void NiPSysEmitterDeclinationVarCtlr::FUN_00c2b8c0(float& fValue)
{
    fValue = *(float*)((char*)m_pkTargetModifier + 0x24);
}

void __stdcall FUN_00c32f60(StrArr* pArr);
char* FUN_00a7d330(char* s);

// @fnv 0x00c2b920
void __stdcall FUN_00c2b920(StrArr* pStringArray)
{
    FUN_00c32f60(pStringArray);
    char* s = FUN_00a7d330((char*)g_01202750);
    unsigned int uiIndex = pStringArray->m_usSize;
    if (uiIndex >= pStringArray->m_usMaxSize)
        pStringArray->SetSize(uiIndex + pStringArray->m_usGrowBy);
    pStringArray->SetAt(uiIndex, s);
}

extern int DAT_010bfb54;

void* __cdecl FUN_00aa13e0(unsigned int size);

struct SpawnedObject
{
    void* m_vtbl;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;

    void FUN_00c32d80();
};

struct FUN_00c2b8d0_cls
{
    void FUN_00c32de0(SpawnedObject* obj, void* arg);

    SpawnedObject* FUN_00c2b8d0(void* arg);
};

// @fnv 0x00c2b8d0
SpawnedObject* FUN_00c2b8d0_cls::FUN_00c2b8d0(void* arg)
{
    SpawnedObject* obj = (SpawnedObject*)FUN_00aa13e0(0x40);
    if (obj != 0)
    {
        obj->FUN_00c32d80();
        obj->m_vtbl = &DAT_010bfb54;
    }
    else
    {
        obj = 0;
    }
    this->FUN_00c32de0(obj, arg);
    return obj;
}
