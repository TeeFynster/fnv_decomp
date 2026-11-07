
// src/gamebryo2.2/corelibs/niparticle/nipsysairfieldspreadctlr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysairfieldspreadctlr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern int DAT_012027a0;
void __stdcall NiPSysModifierFloatCtlr_GetViewerStrings(void* p);
void* __cdecl NiViewerStrings_NiGetViewerString_Title(int v);

struct ObjHdr
{
    int unk0;
    int unk4;
    unsigned short unk8;
    unsigned short unkA;
    unsigned short unkC;
    unsigned short unkE;
    void FUN_0096ad30(int v);
    void FUN_0096ae90(unsigned int count, void** out);
};

// Calls FUN_00c32f60 on p, gets a value from FUN_00a7d330, grows the buffer if unkA >= unk8, then stores the value at index unkA via FUN_0096ae90.
// @fnv 0x00c2f490
void __stdcall AppendElement(ObjHdr* apObj)
{
    ObjHdr* pObj = apObj;
    NiPSysModifierFloatCtlr_GetViewerStrings(pObj);
    void* pValue = NiViewerStrings_NiGetViewerString_Title(DAT_012027a0);
    unsigned int count = pObj->unkA;
    if (count >= pObj->unk8)
    {
        pObj->FUN_0096ad30((int)(pObj->unkE + count));
    }
    pObj->FUN_0096ae90(count, &pValue);
}
