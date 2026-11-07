#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiBoolInterpController.h"
#include "../../../../include/NiBoolInterpolator.h"
#include "../../../../include/NiInterpController.h"
#include "../../../../include/NiInterpolator.h"
#include "../../../../include/NiObjectNET.h"
#include "../../../../include/NiPointer.h"
#include "../../../../include/NiRTTI.h"
#include "../../../../include/NiTransformController.h"
#include "../../../../include/NiVisController.h"
#include "../../../../include/BSFaceGenMorphData.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiUpdateData.h"
#include "../../../../include/StrArr.h"

// src/gamebryo2.2/corelibs/nianimation/niviscontroller.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/niviscontroller.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x00a44d00
void NiVisController::GetVisibility(bool& abVisible)
{
    NiAVObject* target = static_cast<NiAVObject*>(m_pkTarget);
    abVisible = !(target->m_uFlags & 1);
}

extern void* g_011f3f08;

// @fnv 0x00a44eb0
// src: COMMUNITY 0x00a44eb0
void* __cdecl NiVisController_GetRTTI()
{
    return &g_011f3f08;
}

NiBoolInterpController* __fastcall ConstructBoolInterpController(NiBoolInterpController* controller, void*);
typedef NiBoolInterpController* (__thiscall* BoolInterpControllerConstructor)(NiBoolInterpController*);

extern void* DAT_01097e8c;

// Allocates and initializes a visibility controller, returning zero on allocation failure.
// @fnv 0x00a44f10
// src: EXE 0x00a44f10
void* __cdecl NiVisController_CreateObject()
{
    void* mem = BSFadeNode::operator new(0x38);
    if (mem)
    {
        reinterpret_cast<BoolInterpControllerConstructor>(&ConstructBoolInterpController)(static_cast<NiBoolInterpController*>(mem));
        *reinterpret_cast<void**>(mem) = &DAT_01097e8c;
        return mem;
    }
    return 0;
}

extern const char* const g_011f3ec8_arg1;

// @fnv 0x00a57660
// src: COMMUNITY 0x00a57660
const char* __cdecl NiFloatInterpController_GetRTTI()
{
    return (const char*)&g_011f3ec8_arg1;
}

extern const char* const g_011f3f08_arg1;

// @fnv 0x00a577b0
// src: COMMUNITY 0x00a577b0
const char* const* __cdecl NiBoolInterpController_GetRTTI()
{
    return &g_011f3f08_arg1;
}

void __stdcall FUN_00a57c70(void*);
// @fnv 0x00a44d20
// src: XBOX_PDB 0x00a44d20
void __stdcall BSFrustumFOVController_LoadBinary(void* stream)
{
    NiStream* pStream = static_cast<NiStream*>(stream);
    FUN_00a57c70(pStream);
    if (pStream->m_uiNifFileVersion < 0xa010068)
        pStream->ResetStreamState();
}

extern NiRTTI g_011f4428_arg1;
// Walks the target's RTTI base chain and returns true if it reaches g_011f4428_arg1, otherwise false.
// @fnv 0x00a44de0
bool NiTransformController::IsTargetOfType(NiObjectNET* pkTarget) const
{
    if (pkTarget)
    {
        const NiRTTI* pkRTTI = pkTarget->GetRTTI();
        if (pkRTTI)
        {
            do
            {
                if (pkRTTI == &g_011f4428_arg1)
                    return true;
                pkRTTI = pkRTTI->m_pBaseRTTI;
            } while (pkRTTI);
        }
    }
    return false;
}

// The shared header has no declaration for this controller base initializer.
void __cdecl InitializeInterpControllerBase();
typedef void (__thiscall* InterpControllerBaseInitializer)(NiTimeController*);

extern void* DAT_0109ab44;
// @fnv 0x00a57640
NiInterpController* __fastcall ConstructInterpController(NiInterpController* controller, void*)
{
    reinterpret_cast<InterpControllerBaseInitializer>(&InitializeInterpControllerBase)(controller);
    *reinterpret_cast<void**>(controller) = &DAT_0109ab44;
    return controller;
}

extern int DAT_0109ac54;

// @fnv 0x00a57790
NiBoolInterpController* __fastcall ConstructBoolInterpController(NiBoolInterpController* controller, void*)
{
    reinterpret_cast<InterpControllerBaseInitializer>(&InitializeInterpControllerBase)(controller);
    *reinterpret_cast<int**>(controller) = &DAT_0109ac54;
    return controller;
}


void __stdcall NiBoolInterpController_GetViewerStrings(StrArr*);
char* __cdecl _FUN_00a7d330(void*);

// @fnv 0x00a44f40
// src: XBOX_PDB 0x00a44f40
void __stdcall NiVisController_GetViewerStrings(StrArr* pkStrings)
{
    NiBoolInterpController_GetViewerStrings(pkStrings);
    char* pcStr = _FUN_00a7d330(g_011f3f08);
    unsigned int uiElementCount = *(unsigned short*)((char*)pkStrings + 0xa);
    unsigned int uiSize = *(unsigned short*)((char*)pkStrings + 8);
    if (uiElementCount >= uiSize)
    {
        unsigned int uiGrow = *(unsigned short*)((char*)pkStrings + 0xe);
        pkStrings->SetSize(uiGrow + uiElementCount);
    }
    pkStrings->SetAt(uiElementCount, pcStr);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plValue);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plValue);

inline void NiInterpolator::IncRefCount()
{
    InterlockedIncrement((long volatile*)&m_uiRefCount);
}

inline void NiInterpolator::DecRefCount()
{
    if (InterlockedDecrement((long volatile*)&m_uiRefCount) == 0)
        DeleteThis();
}

template <class T> inline NiPointer<T>& NiPointer<T>::operator=(T* pObject)
{
    if (m_pObject != pObject)
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = pObject;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    return *this;
}

template <class T> inline T* NiPointer<T>::operator->() const
{
    return m_pObject;
}

void __cdecl LinkBoolControllerBase();
typedef void (__thiscall* BoolControllerLink)(NiBoolInterpController*, NiStream&);

// @fnv 0x00a44d50
void __fastcall LinkBoolInterpolator(NiVisController* controller, void*, NiStream& kStream)
{
    reinterpret_cast<BoolControllerLink>(&LinkBoolControllerBase)(controller, kStream);
    if (kStream.m_uiNifFileVersion < 0x0A010068)
    {
        NiObject* pkData = kStream.GetLoadedObject();
        controller->m_spControllerInterpolator = new NiBoolInterpolator(pkData);
        controller->m_spControllerInterpolator->Collapse();
    }
}

void __cdecl CopyVisControllerMembers();
typedef void (__thiscall* VisControllerCopy)(NiVisController*, NiVisController*, unsigned int);

__forceinline NiVisController* InitializeVisController(void* memory)
{
    NiVisController* controller = static_cast<NiVisController*>(memory);
    reinterpret_cast<BoolInterpControllerConstructor>(&ConstructBoolInterpController)(controller);
    *reinterpret_cast<void***>(controller) = &DAT_01097e8c;
    return controller;
}

// Allocates and initializes a visibility controller, then copies its members.
// @fnv 0x00a44ec0
NiVisController* __fastcall CloneVisController(NiVisController* controller, void*, unsigned int uiArg)
{
    void* pMem = BSFaceGenMorphData::operator new(0x38);
    NiVisController* pkCtl = pMem ? InitializeVisController(pMem) : 0;
    reinterpret_cast<VisControllerCopy>(&CopyVisControllerMembers)(controller, pkCtl, uiArg);
    return pkCtl;
}

extern const float DAT_01096324;

inline bool GetVisManagerControlled(const NiVisController* controller)
{
    return (bool)((controller->m_uiObjectFlags >> 5) & 1);
}

inline bool GetVisAppCulled(const NiAVObject* target)
{
    return (target->m_uFlags & 1) != 0;
}

inline void SetVisAppCulled(NiAVObject* target, bool appCulled)
{
    if (appCulled)
        target->m_uFlags |= 1;
    else
        target->m_uFlags &= ~1;
}

// @fnv 0x00a44e10
void __fastcall UpdateVisController(NiVisController* controller, void*, NiUpdateData& kUpdateData)
{
    if (GetVisManagerControlled(controller))
    {
        controller->m_fControllerTime = DAT_01096324;
    }
    else if (controller->DontDoUpdate(kUpdateData.fTime) &&
             (!controller->m_spControllerInterpolator.m_pObject || !controller->m_spControllerInterpolator.m_pObject->AlwaysUpdate()))
    {
        return;
    }

    if (controller->m_spControllerInterpolator.m_pObject)
    {
        bool bValue;
        if (controller->m_spControllerInterpolator.m_pObject->UpdateBool(controller->m_fControllerTime, controller->m_pkTarget, bValue))
        {
            NiAVObject* target = static_cast<NiAVObject*>(controller->m_pkTarget);
            bool bOld = GetVisAppCulled(target);
            SetVisAppCulled(target, !bValue);
            if (bOld && bValue)
                // NiUpdateData's visibility-change byte is named pad5 in the shared header (+0x08).
                kUpdateData.pad5 = true;
        }
    }
}
