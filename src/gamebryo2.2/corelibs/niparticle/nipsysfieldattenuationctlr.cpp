
// src/gamebryo2.2/corelibs/niparticle/nipsysfieldattenuationctlr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysfieldattenuationctlr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiObjectNET.h"
#include "../../../../include/NiPSysModifier.h"
#include "../../../../include/StrArr.h"

extern "C" void* g_01202720;

// @fnv 0x00c2b230
// src: COMMUNITY 0x00c2b230
void* __cdecl NiPSysFieldAttenuationCtlr_GetRTTI()
{
    return &g_01202720;
}

struct BaseStandIn
{
    bool IsTargetParticleSystem(NiObjectNET*);
};
// The shared headers do not yet declare this modifier lookup.
// An explicit-this function pointer preserves its thiscall ABI.
NiPSysModifier* __cdecl FUN_00c1b0f0();
extern char const* const g_01202688_arg1;
struct NiPSysFieldAttenuationCtlr : BaseStandIn
{
    bool InterpTargetIsCorrectType_00c2b290(NiObjectNET*);
};
// Calls the base check on pkTarget, resolves a NiPSysModifier from this+0x38, and returns true if its RTTI chain contains g_01202688_arg1.
// @fnv 0x00c2b290
// src: XBOX_PDB 0x00c2b290
bool NiPSysFieldAttenuationCtlr::InterpTargetIsCorrectType_00c2b290(NiObjectNET* pkTarget)
{
    if (!BaseStandIn::IsTargetParticleSystem(pkTarget))
        return false;
    typedef NiPSysModifier* (__thiscall* FindModifier)(NiObjectNET*, const NiFixedString*);
    NiPSysModifier* pkModifier = ((FindModifier)&FUN_00c1b0f0)(
        pkTarget, reinterpret_cast<const NiFixedString*>((char*)this + 0x38));
    if (!pkModifier)
        return false;
    for (const void* p = pkModifier->GetRTTI(); p; p = *(const void* const*)((const char*)p + 4))
    {
        if (p == (void*)&g_01202688_arg1)
            return true;
    }
    return false;
}

// Candidate for CreateFieldAttenuationController (0x00c2b240, 75 bytes, /MT /O2 /GS /EHsc /Gy)
// __thiscall factory: allocates 0x40 bytes, runs the base ctor (0xc32d80),
// installs the NiPSysFieldAttenuationCtlr vtable, then hands the object to
// this->FUN_00c32de0 along with the caller's NiObjectNET*. Returns the new
// object, or null (passing null through) when allocation fails.

// The game's operator new (0xaa13e0), declared under a stand-in name: the
// shared symbol map binds the global ??2@YAPAXI@Z to a placeholder address.
void* NiMemAlloc(unsigned int uiSize);
inline void* operator new(unsigned int, void* pvWhere)
{
    return pvWhere;
}

// Stand-in for the base whose ctor lives at 0xc32d80.
struct FieldCtlrBase
{
    FieldCtlrBase();
};

// Stand-in carrying the vtable the original installs (DAT_010bf554).
// fnvcheck derives the vtable address from the original image bytes.
struct AttenCtlr
{
    virtual void* _v0()
    {
        return 0;
    }
    virtual void* _v1()
    {
        return 0;
    }
    virtual void* _v2()
    {
        return 0;
    }
    unsigned char _pad[0x40 - 4];
};

struct Owner
{
    void FUN_00c32de0(AttenCtlr* pCtlr, NiObjectNET* pArg);
    NiPSysFieldAttenuationCtlr* CreateFieldAttenuationController(NiObjectNET* pArg);
};

// Allocates and constructs an AttenCtlr, passes it with pArg to FUN_00c32de0, and returns it as a NiPSysFieldAttenuationCtlr.
// @fnv 0x00c2b240
NiPSysFieldAttenuationCtlr* Owner::CreateFieldAttenuationController(NiObjectNET* pArg)
{
    AttenCtlr* pCtlr = (AttenCtlr*)NiMemAlloc(sizeof(AttenCtlr));
    if (pCtlr)
    {
        new (pCtlr) FieldCtlrBase;
        new (pCtlr) AttenCtlr;
    }
    else
    {
        pCtlr = 0;
    }
    this->FUN_00c32de0(pCtlr, pArg);
    return (NiPSysFieldAttenuationCtlr*)pCtlr;
}

char* __cdecl NiViewerStrings_NiGetViewerString_Title(char*);
void __stdcall NiPSysModifierFloatCtlr_GetViewerStrings(StrArr*);
// Appends the string returned by FUN_00a7d330(g_01202720) to the array, growing it if the index reaches capacity.
// @fnv 0x00c2b2e0
// src: XBOX_PDB 0x00c2b2e0
void __stdcall NiPSysFieldAttenuationCtlr_GetViewerStrings(StrArr* array)
{
    NiPSysModifierFloatCtlr_GetViewerStrings(array);
    char* value = NiViewerStrings_NiGetViewerString_Title(static_cast<char*>(g_01202720));
    unsigned int index = array->m_usSize;
    unsigned int capacity = array->m_usMaxSize;
    if (index >= capacity)
        array->SetSize(index + array->m_usGrowBy);
    array->SetAt(index, value);
}
