#include "../../../../include/NiTArray.h"

// src/gamebryo2.2/corelibs/niparticle/nipsysinitialrotanglevarctlr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysinitialrotanglevarctlr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void* g_012026e8;

// @fnv 0x00c2a080
// src: COMMUNITY 0x00c2a080
void* __cdecl NiPSysInitialRotAngleVarCtlr_GetRTTI()
{
    return &g_012026e8;
}

extern "C" void* __cdecl Object_DispatchCommandFour(unsigned int uiSize);
extern "C" char DAT_010beebc;

struct Item
{
    void* m_pkVtbl;
    void FUN_00c32d80();
};

struct Creator
{
    void FUN_00c32de0(Item* pkItem, int iArg);
    Item* CreateItem(int iArg);
};

// Allocates a 0x40-byte Item, initialises it, sets its vtable, passes it to FUN_00c32de0 with iArg, and returns it.
// @fnv 0x00c2a0c0
Item* Creator::CreateItem(int iArg)
{
    Item* pkItem = (Item*)Object_DispatchCommandFour(0x40);
    if (pkItem)
    {
        pkItem->FUN_00c32d80();
        pkItem->m_pkVtbl = &DAT_010beebc;
    }
    else
    {
        pkItem = 0;
    }
    FUN_00c32de0(pkItem, iArg);
    return pkItem;
}

struct C2A110RTTI
{
    const char* m_pcName;
    const C2A110RTTI* m_pBaseRTTI;

    const char* GetName() const
    {
        return m_pcName;
    }
};

template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::SetAtGrow(unsigned int uiIndex, const T& element)
{
    if (uiIndex >= m_usMaxSize)
        SetSize(uiIndex + m_usGrowBy);
    SetAt(uiIndex, element);
    return uiIndex;
}
template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::Add(const T& element)
{
    return SetAtGrow(m_usSize, element);
}

typedef NiTArray<char*, NiTMallocInterface<char*> > C2A110StringArray;

extern "C" char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char* pcText);

struct C2A110Base
{
    void NiPSysModifierFloatCtlr_GetViewerStrings(C2A110StringArray* pkStrings);
};

struct C2A110Object : C2A110Base
{
    static C2A110RTTI ms_kRTTI;

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
    float m_fFrequency;

    void AppendRTTIName(C2A110StringArray* pkStrings);
};

// @fnv 0x00c2a110
void C2A110Object::AppendRTTIName(C2A110StringArray* pkStrings)
{
    C2A110Base::NiPSysModifierFloatCtlr_GetViewerStrings(pkStrings);
    char* pcString = NiViewerStrings_NiGetViewerString_Title(ms_kRTTI.GetName());
    pkStrings->Add(pcString);
}
