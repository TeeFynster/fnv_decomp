
// src/gamebryo2.2/corelibs/niparticle/nipsysairfieldairfrictionctlr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysairfieldairfrictionctlr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiObjectNET.h"
#include "../../../../include/NiPSysAirFieldAirFrictionCtlr.h"
#include "../../../../include/NiPSysModifier.h"
#include "../../../../include/NiPSysModifierFloatCtlr.h"
#include "../../../../include/StrArr.h"
#include "../../../../include/NiRTTI.h"

extern int g_012027b8;

// @fnv 0x00c307c0
// src: COMMUNITY 0x00c307c0
int* __cdecl NiPSysAirFieldAirFrictionCtlr_GetRTTI()
{
    return &g_012027b8;
}

// @fnv 0x00c307d0
// src: XBOX_PDB 0x00c307d0
void NiPSysAirFieldAirFrictionCtlr::GetTargetFloatValue_00c307d0(float& rfValue)
{
    NiPSysModifier* pTarget = m_pkTargetModifier;
    rfValue = *(float*)((char*)pTarget + 0x58);
}

void __stdcall NiPSysModifierFloatCtlr_GetViewerStrings(StrArr*);
char* __cdecl _FUN_00a7d330(int);
// @fnv 0x00c30880
// src: XBOX_PDB 0x00c30880
void __stdcall NiPSysAirFieldAirFrictionCtlr_GetViewerStrings(StrArr* pkStrings)
{
    NiPSysModifierFloatCtlr_GetViewerStrings(pkStrings);
    char* pcStr = _FUN_00a7d330(g_012027b8);
    unsigned int uiSize = pkStrings->m_usSize;
    unsigned int uiAlloc = pkStrings->m_usMaxSize;
    if (uiSize >= uiAlloc)
    {
        pkStrings->SetSize(uiSize + pkStrings->m_usGrowBy);
    }
    pkStrings->SetAt(uiSize, pcStr);
}

// These entry points are not declared by the shared controller headers yet.
// Explicit-this function pointers retain their original thiscall ABI.
bool __cdecl IsTargetParticleSystem();
NiPSysModifier* __cdecl FUN_00c1b0f0();
extern NiRTTI g_012027a8;

// @fnv 0x00c306f0
bool __fastcall HasModifierAfter(NiPSysAirFieldAirFrictionCtlr* controller, void*, NiObjectNET* target)
{
    typedef bool (__thiscall* CheckTarget)(NiPSysAirFieldAirFrictionCtlr*, NiObjectNET*);
    typedef NiPSysModifier* (__thiscall* FindModifier)(NiObjectNET*, const NiFixedString*);
    if (!((CheckTarget)&IsTargetParticleSystem)(controller, target))
        return false;
    NiPSysModifier* modifier = ((FindModifier)&FUN_00c1b0f0)(target, &controller->m_kTargetModifierName);
    if (!modifier)
        return false;
    const NiRTTI* item = modifier->GetRTTI();
    while (item)
    {
        if (item == &g_012027a8)
            return true;
        item = item->m_pBaseRTTI;
    }
    return false;
}

// Clamps the air-field friction to [0,1].
// @fnv 0x00c307e0
void __fastcall SetAirFriction(NiPSysAirFieldAirFrictionCtlr* controller, void*, float value)
{
    NiPSysModifier* pTarget = controller->m_pkTargetModifier;
    float clamped = value;
    if (0.0 > clamped)
        clamped = 0.0f;
    if (1.0 < clamped)
        clamped = 1.0f;
    *(float*)((char*)pTarget + 0x58) = clamped;
}

extern "C" char g_010c06e4;

void* __cdecl Object_DispatchCommandFour(unsigned int size);

void __cdecl FUN_00c32d80();
void __cdecl FUN_00c32de0();

// Allocates and initializes an air-friction controller, then copies its members.
// @fnv 0x00c30830
NiPSysAirFieldAirFrictionCtlr* __fastcall CreateSpawnedObject(NiPSysAirFieldAirFrictionCtlr* controller, void*, unsigned int arg)
{
    typedef void (__thiscall* Initialize)(NiPSysAirFieldAirFrictionCtlr*);
    typedef void (__thiscall* CopyMembers)(NiPSysAirFieldAirFrictionCtlr*, NiPSysAirFieldAirFrictionCtlr*, unsigned int);
    NiPSysAirFieldAirFrictionCtlr* obj = (NiPSysAirFieldAirFrictionCtlr*)Object_DispatchCommandFour(0x40);
    if (obj != 0)
    {
        ((Initialize)&FUN_00c32d80)(obj);
        *(void**)obj = (void*)&g_010c06e4;
    }
    else
    {
        obj = 0;
    }
    ((CopyMembers)&FUN_00c32de0)(controller, obj, arg);
    return obj;
}

void __cdecl LoadBinaryWithVersionCheck(NiPSysModifierCtlr*, int, NiStream&);

// @fnv 0x00c29e80
// src: XBOX_PDB 0x00c29e80
void __cdecl NiPSysAirFieldAirFrictionCtlr_LoadBinary(NiPSysModifierCtlr* a1, int a2, NiStream& a3)
{
    LoadBinaryWithVersionCheck(a1, a2, a3);
}

extern "C" void __cdecl BSFrustumFOVController_RegisterStreamables();

// @fnv 0x00c29f80
// src: XBOX_PDB 0x00c29f80
void __cdecl NiPSysAirFieldAirFrictionCtlr_RegisterStreamables()
{
    BSFrustumFOVController_RegisterStreamables();
}

void __cdecl FUN_00c32e10();

// @fnv 0x00c2b450
// src: XBOX_PDB 0x00c2b450
void __cdecl NiPSysAirFieldAirFrictionCtlr_LinkObject()
{
    FUN_00c32e10();
}

void __cdecl NiColorExtraDataController_SaveBinary();
// @fnv 0x00c2b8a0
// src: XBOX_PDB 0x00c2b8a0
void __cdecl NiPSysAirFieldAirFrictionCtlr_SaveBinary()
{
    NiColorExtraDataController_SaveBinary();
}

bool __cdecl NiPSysModifierBoolCtlr_IsEqual(int, int);

// @fnv 0x00c2a190
// src: XBOX_PDB 0x00c2a190
bool __cdecl NiPSysAirFieldAirFrictionCtlr_IsEqual(int param_1, int param_2)
{
    return NiPSysModifierBoolCtlr_IsEqual(param_1, param_2);
}
