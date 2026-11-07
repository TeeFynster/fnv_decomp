
// src/gamebryo2.2/corelibs/niparticle/nipsysairfieldinheritvelocityctlr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysairfieldinheritvelocityctlr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiPSysModifierFloatCtlr.h"
#include "../../../../include/StrArr.h"

inline void* __cdecl operator new(unsigned int, void* p)
{
    return p;
}

extern "C" void* g_012027b0;

// @fnv 0x00c30630
// src: COMMUNITY 0x00c30630
void* __cdecl NiPSysAirFieldInheritVelocityCtlr_GetRTTI()
{
    return &g_012027b0;
}

struct NiPSysAirFieldInheritVelocityCtlr : NiPSysModifierFloatCtlr
{
    void GetTargetFloatValue_00c30640(float& fValue);
    void SetModValue(float fValue);
    void FUN_00c32de0(NiPSysModifierFloatCtlr* obj, void* a1);
    NiPSysModifierFloatCtlr* CreateSpawnedCtlr(void* a1);
};

// @fnv 0x00c30640
// src: XBOX_PDB 0x00c30640
void __thiscall NiPSysAirFieldInheritVelocityCtlr::GetTargetFloatValue_00c30640(float& fValue)
{
    float* p = reinterpret_cast<float*>(m_pkTargetModifier);
    fValue = p[0x5c / 4];
}

struct S_00c30650_Mod
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
    float m_fNormalizedValue;
    void Set(float f)
    {
        if (0.0 > f)
            f = 0.0f;
        if (1.0 < f)
            f = 1.0f;
        m_fNormalizedValue = f;
    }
};
// Clamps fValue to [0,1] via the modifier's Set and stores it.
// @fnv 0x00c30650
void NiPSysAirFieldInheritVelocityCtlr::SetModValue(float fValue)
{
    reinterpret_cast<S_00c30650_Mod*>(m_pkTargetModifier)->Set(fValue);
}

extern "C" char DAT_010c05e4;
extern "C" void* __cdecl Object_DispatchCommandFour(unsigned int size);

// Allocates and initialises a controller, copies its members, and returns it.
// @fnv 0x00c306a0
NiPSysModifierFloatCtlr* NiPSysAirFieldInheritVelocityCtlr::CreateSpawnedCtlr(void* a1)
{
    NiPSysModifierFloatCtlr* obj = (NiPSysModifierFloatCtlr*)Object_DispatchCommandFour(0x40);
    if (obj != 0)
    {
        ::new (obj) NiPSysModifierFloatCtlr;
        *(void* volatile*)obj = &DAT_010c05e4;
    }
    else
    {
        obj = 0;
    }
    this->FUN_00c32de0(obj, a1);
    return obj;
}

char* __cdecl NiViewerStrings_NiGetViewerString_Title(char*);
void __stdcall NiPSysModifierFloatCtlr_GetViewerStrings(StrArr*);
// Grows the array if its index has reached capacity, then stores the string returned by FUN_00a7d330 at that index.
// @fnv 0x00c30740
// src: XBOX_PDB 0x00c30740
void __stdcall NiPSysAirFieldInheritVelocityCtlr_GetViewerStrings(StrArr* array)
{
    NiPSysModifierFloatCtlr_GetViewerStrings(array);
    char* value = NiViewerStrings_NiGetViewerString_Title(static_cast<char*>(g_012027b0));
    unsigned int index = array->m_usSize;
    unsigned int capacity = array->m_usMaxSize;
    if (index >= capacity)
        array->SetSize(index + array->m_usGrowBy);
    array->SetAt(index, value);
}
