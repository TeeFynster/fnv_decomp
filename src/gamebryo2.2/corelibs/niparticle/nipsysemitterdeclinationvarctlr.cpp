// src/gamebryo2.2/corelibs/niparticle/nipsysemitterdeclinationvarctlr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysemitterdeclinationvarctlr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiPSysModifierFloatCtlr.h"
#include "../../../../include/StrArr.h"

extern "C" void* g_01202750;

// @fnv 0x00c2b8b0
// src: COMMUNITY 0x00c2b8b0
void* __cdecl NiPSysEmitterDeclinationVarCtlr_GetRTTI()
{
    return &g_01202750;
}

struct NiPSysEmitterDeclinationVarCtlr : NiPSysModifierFloatCtlr
{
    void SetTargetValueAtOffset24(float fValue);
    void UpdateFields_00c2b8c0(float& fValue);
};

// @fnv 0x00c2a0b0
// src: GUESS 0x00c2a0b0 (confidence: medium)
void NiPSysEmitterDeclinationVarCtlr::SetTargetValueAtOffset24(float fValue)
{
    *(float*)((char*)m_pkTargetModifier + 0x24) = fValue;
}

// @fnv 0x00c2b8c0
// src: GUESS 0x00c2b8c0 (confidence: low)
void NiPSysEmitterDeclinationVarCtlr::UpdateFields_00c2b8c0(float& fValue)
{
    fValue = *(float*)((char*)m_pkTargetModifier + 0x24);
}

void __stdcall NiPSysModifierFloatCtlr_GetViewerStrings(StrArr* pArr);
char* NiViewerStrings_NiGetViewerString_Title(char* s);

// @fnv 0x00c2b920
// src: XBOX_PDB 0x00c2b920
void __stdcall NiPSysEmitterDeclinationVarCtlr_GetViewerStrings(StrArr* pStringArray)
{
    NiPSysModifierFloatCtlr_GetViewerStrings(pStringArray);
    char* s = NiViewerStrings_NiGetViewerString_Title((char*)g_01202750);
    unsigned int uiIndex = pStringArray->m_usSize;
    if (uiIndex >= pStringArray->m_usMaxSize)
        pStringArray->SetSize(uiIndex + pStringArray->m_usGrowBy);
    pStringArray->SetAt(uiIndex, s);
}

extern int DAT_010bfb54;

void* __cdecl Object_DispatchCommandFour(unsigned int size);

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

    SpawnedObject* NiPSysEmitterDeclinationVarCtlr_CreateClone(void* arg);
};

// @fnv 0x00c2b8d0
// src: XBOX_PDB 0x00c2b8d0
SpawnedObject* FUN_00c2b8d0_cls::NiPSysEmitterDeclinationVarCtlr_CreateClone(void* arg)
{
    SpawnedObject* obj = (SpawnedObject*)Object_DispatchCommandFour(0x40);
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
