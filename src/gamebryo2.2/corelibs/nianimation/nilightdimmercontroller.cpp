
// src/gamebryo2.2/corelibs/nianimation/nilightdimmercontroller.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nilightdimmercontroller.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiFloatInterpController.h"
#include "../../../../include/NiLight.h"
#include "../../../../include/NiLightDimmerController.h"

extern "C" char __stdcall FUN_00a57c10(void* a);

// @fnv 0x00a4cf50
char __stdcall FUN_00a4cf50(void* pThis)
{
    return FUN_00a57c10(pThis) != 0;
}

// @fnv 0x00a4cf70
void NiLightDimmerController::GetLightDimmer(float& fValue)
{
    NiLight* apTargetLight = static_cast<NiLight*>(m_pkTarget);
    if (apTargetLight)
    {
        fValue = apTargetLight->m_fDimmer;
    }
}

struct GlobalObjectO2_00a7b610;

extern GlobalObjectO2_00a7b610 g_011f3fa0;

// @fnv 0x00a4cf90
GlobalObjectO2_00a7b610* __cdecl FUN_00a4cf90()
{
    return &g_011f3fa0;
}

extern int DAT_01098ccc;
inline void* __cdecl operator new(unsigned int, void* p)
{
    return p;
}
// @fnv 0x00a4d0d0
void* FUN_00a4d0d0()
{
    void* p = BSFadeNode::operator new(0x38);
    if (p)
    {
        ::new (p) NiFloatInterpController();
        *(void**)p = &DAT_01098ccc;
        return p;
    }
    return 0;
}

#include "../../../../include/NiTPrimitiveArray.h"
void __stdcall FUN_00a576c0(NiTPrimitiveArray<char*>*);
char* __cdecl FUN_00a7d330(const char*);
// @fnv 0x00a4d100
void __stdcall FUN_00a4d100(NiTPrimitiveArray<char*>* pkStrings)
{
    FUN_00a576c0(pkStrings);
    char* pszStr = FUN_00a7d330(*(const char**)&g_011f3fa0);
    unsigned int uIdx = pkStrings->m_usSize;
    if (uIdx >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(uIdx + pkStrings->m_usGrowBy);
    pkStrings->SetAt(uIdx, pszStr);
}

extern "C" void* __cdecl FUN_00aa13e0(unsigned int size);

struct FloatInterpOwner
{
    void FUN_00a57620(void* obj, int arg);
    void* CreateFloatInterpController(int arg);
};

// @fnv 0x00a4d080
void* FloatInterpOwner::CreateFloatInterpController(int arg)
{
    NiFloatInterpController* obj = (NiFloatInterpController*)FUN_00aa13e0(0x38);
    if (obj != 0)
    {
        obj->NiFloatInterpController::NiFloatInterpController();
        *(int*)obj = (int)&DAT_01098ccc;
    }
    else
    {
        obj = 0;
    }
    FUN_00a57620(obj, arg);
    return obj;
}

extern NiRTTI DAT_011f4a28;
extern const float DAT_01096324;

inline bool GetManagerControlled(const NiLightDimmerController* controller)
{
    return ((controller->m_uiObjectFlags >> 5) & 1) != 0;
}

// @fnv 0x00a4cfa0
void __fastcall UpdateDimmer(NiLightDimmerController* controller, void*, const float& fTime)
{
    if (GetManagerControlled(controller))
    {
        controller->m_fControllerTime = DAT_01096324;
    }
    else if (controller->FUN_00a36250(fTime) && (!controller->m_spControllerInterpolator.m_pObject || !controller->m_spControllerInterpolator.m_pObject->AlwaysUpdate()))
    {
        return;
    }

    if (controller->m_spControllerInterpolator.m_pObject)
    {
        float fValue;
        if (controller->m_spControllerInterpolator.m_pObject->UpdateFloat(controller->m_fControllerTime, controller->m_pkTarget, fValue))
        {
            if (controller->m_pkTarget)
            {
                NiLight* pkLight = static_cast<NiLight*>(controller->m_pkTarget->DynamicCast(&DAT_011f4a28));
                pkLight->m_fDimmer = fValue;
                pkLight->revID++;
            }
        }
    }
}

extern void FUN_00a57c70();

// @fnv 0x00a4cf40
void FUN_00a4cf40()
{
    FUN_00a57c70();
}

#include <windows.h>
extern int DAT_01098ccc;

void __cdecl FUN_00aa1460(void* apMemory, unsigned int auiSize);
extern void BaseCleanup();

// Releases the interpolator, cleans up the base, and frees the controller when bit 0 is set.
// @fnv 0x00a4d030
NiLightDimmerController* __fastcall FUN_00a4d030(NiLightDimmerController* controller, void*, unsigned char acFlags)
{
    *(volatile int*)controller = (int)&DAT_01098ccc;
    NiInterpolator* pCounted = *(NiInterpolator* volatile*)&controller->m_spControllerInterpolator.m_pObject;
    if (pCounted != 0)
    {
        if (InterlockedDecrement((long volatile*)&pCounted->m_uiRefCount) == 0)
        {
            pCounted->DeleteThis();
        }
    }
    reinterpret_cast<void (__thiscall*)(NiLightDimmerController*)>(&BaseCleanup)(controller);
    if (acFlags & 1)
    {
        FUN_00aa1460(controller, 0x38);
    }
    return controller;
}
