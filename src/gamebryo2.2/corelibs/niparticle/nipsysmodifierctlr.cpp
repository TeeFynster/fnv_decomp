// gamebryo2.2/corelibs/niparticle/nipsysmodifierctlr.cpp: particle modifier controllers (9 functions)

#include "../../../../include/NiTStringPointerMap.h"
#include "nipsysmodifierctlr_decls.h"
#include "../../../../include/NiPSysModifierCtlr.h"
#include "../../../../include/NiSingleInterpController.h"
#include "../../../../include/NiObjectNET.h"
#include "../../../../include/NiParticleSystem.h"
#include "../../../../include/NiRTTI.h"
#include "../../../../include/NiTimeController.h"
#include "../../../../include/NiStream.h"

// @fnv 0x00c31340
void NiPSysModifierCtlr::ProcessClone(CloningProcess& aCloneProcess)
{
    NiSingleInterpController::ProcessClone(aCloneProcess);
    NiPSysModifierCtlr* clone = 0;
    aCloneProcess.m_pCloneMap->GetAt((const char*)this, (ShaderBufferRecord*&)clone);
    NiPSysModifierCtlr* destination = clone;
    if (m_pkTarget && destination->m_pkTarget)
    {
        aCloneProcess.m_pCloneMap->GetAt((const char*)m_pkTargetModifier, (ShaderBufferRecord*&)clone);
        destination->m_pkTargetModifier = reinterpret_cast<NiPSysModifier*>(clone);
    }
}

// These routines are absent from the shared class declarations. The unused EDX
// parameter preserves their thiscall stack arguments without another class copy.
// @fnv 0x00c31500
void __fastcall SetModifierTarget(NiPSysModifierCtlr* controller, void*, NiObjectNET* pkTarget)
{
    controller->m_pkTargetModifier = 0;
    controller->NiTimeController::SetTarget(pkTarget);
    if (controller->m_pkTarget)
        reinterpret_cast<NiParticleSystem*>(controller)->FindModifier();
}

// @fnv 0x00a57130
void __fastcall SaveModifierController(NiPSysModifierCtlr* controller, void*, NiStream& kStream)
{
    controller->NiSingleInterpController::SaveBinary(kStream);
    kStream.SerializeString(reinterpret_cast<const char*>(&controller->m_kTargetModifierName));
}

// @fnv 0x00c313a0
unsigned char __fastcall IsModifierControllerEquivalent(NiPSysModifierCtlr* controller, void*, NiPSysModifierCtlr* other)
{
    if (!static_cast<const NiSingleInterpController*>(controller)->NiSingleInterpController::IsEqual(other))
        return 0;

    if (controller->m_pkTargetModifier && !other->m_pkTargetModifier)
        return 0;

    if (!controller->m_pkTargetModifier && other->m_pkTargetModifier)
        return 0;

    if (controller->m_pkTargetModifier && other->m_pkTargetModifier)
    {
        if (!controller->m_pkTargetModifier->IsEqual(other->m_pkTargetModifier))
            return 0;
    }

    return controller->m_kTargetModifierName.m_kHandle == other->m_kTargetModifierName.m_kHandle;
}

extern int DAT_010c08ac;
extern int DAT_0109b220;
extern int(__stdcall* DAT_00fdf1c4)(void* apMemory);
void __cdecl FUN_00aa1460(void* apMemory, unsigned int auiSize);

void __fastcall DestroyTimeController(NiTimeController* controller);

// Frees the name buffer and modifier reference, calls FUN_00a6d290, and optionally deallocates the object when acFlags bit 0 is set.
// @fnv 0x00c314a0
NiPSysModifierCtlr* __fastcall DestroyModifierController(NiPSysModifierCtlr* controller, void*, unsigned char acFlags)
{
    int(__stdcall * pfnFree)(void*) = DAT_00fdf1c4;
    *(volatile int*)controller = (int)&DAT_010c08ac;
    char* pName = *(char* volatile*)&controller->m_kTargetModifierName.m_kHandle;
    if (pName != (char*)DAT_0109b220)
    {
        pfnFree(pName - 8);
    }
    NiInterpolator* pModifier = controller->m_spControllerInterpolator.m_pObject;
    if (pModifier != 0)
    {
        if (pfnFree(&pModifier->m_uiRefCount) == 0)
        {
            pModifier->DeleteThis();
        }
    }
    DestroyTimeController(controller);
    if (acFlags & 1)
    {
        FUN_00aa1460(controller, 0x40);
    }
    return controller;
}

namespace fnv_00c31530 {
extern NiRTTI DAT_012024e0;
extern void* DAT_0109b220;

struct NiParticleSystemRuntime
{
    virtual void DeleteThis();
    virtual void LoadBinary();
    virtual const NiRTTI* GetRTTI();
    void* FUN_00c1b0f0(const void* pkName);
};

// @fnv 0x00c31530
bool __fastcall IsTargetParticleSystem(NiPSysModifierCtlr* controller, void*, NiParticleSystemRuntime* pkTarget)
{
    if (pkTarget != 0)
    {
        const NiRTTI* pkRTTI = pkTarget->GetRTTI();
        while (pkRTTI != 0)
        {
            if (pkRTTI == &DAT_012024e0)
            {
                if (controller->m_kTargetModifierName.m_kHandle != DAT_0109b220 && controller->m_pkTarget != 0)
                {
                    if (pkTarget->FUN_00c1b0f0(&controller->m_kTargetModifierName))
                    {
                        return true;
                    }
                }
                return false;
            }
            pkRTTI = pkRTTI->m_pBaseRTTI;
        }
    }
    return false;
}
}  // namespace fnv_00c31530

// @fnv 0x00c31590
void NiPSysModifierCtlr::LinkObject(NiStream& stream)
{
    NiObject::LinkObject(stream);
    if (m_pkTarget)
        reinterpret_cast<NiParticleSystem*>(this)->FindModifier();
}

struct FUN_00c315b0_arr
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned short m_iCap;
    unsigned short m_iArrayLength;
    unsigned short unk0C;
    unsigned short m_iGrowBy;
    void FUN_0096ad30(unsigned int newSize);
    void FUN_0096ae90(unsigned int index, void*& item);
};

extern void __stdcall FUN_00a390a0(FUN_00c315b0_arr* arr);
extern void* __cdecl NiViewerStrings_NiGetViewerString_Title(void* p);
extern void* __cdecl NiGetViewerString_00a7d5e0(const char* fmt, void* p);
extern void* DAT_012027c8;

// @fnv 0x00c315b0
void __fastcall AppendModifierInfo(NiPSysModifierCtlr* controller, void*, void* arg)
{
    FUN_00c315b0_arr* arr = (FUN_00c315b0_arr*)arg;
    FUN_00a390a0(arr);
    void* v1 = NiViewerStrings_NiGetViewerString_Title(DAT_012027c8);
    unsigned int count = arr->m_iArrayLength;
    if (count >= arr->m_iCap)
    {
        arg = v1;
        arr->FUN_0096ad30(count + arr->m_iGrowBy);
    }
    else
    {
        arg = v1;
    }
    arr->FUN_0096ae90(count, arg);
    void* pModifierName = controller->m_kTargetModifierName.m_kHandle;
    void* pNameString = NiGetViewerString_00a7d5e0("Modifier Name", pModifierName);
    count = arr->m_iArrayLength;
    if (count >= arr->m_iCap)
    {
        arg = pNameString;
        arr->FUN_0096ad30(count + arr->m_iGrowBy);
    }
    else
    {
        arg = pNameString;
    }
    arr->FUN_0096ae90(count, arg);
}

// @fnv 0x00a57780
bool __fastcall RegisterModifierController(NiPSysModifierCtlr* controller, void*, NiStream& stream)
{
    return controller->NiSingleInterpController::RegisterStreamables(stream);
}
