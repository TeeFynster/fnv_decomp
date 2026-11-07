#include "../../include/Setting.h"
// 0x00408d60 returns the setting value at +4 (or a fallback byte for null this).

// fallout_shared/bgsopencloseform.cpp: BGSOpenCloseForm, AIThreadManager (8 functions)

#include "../../include/TESForm.h"
#include "../../include/ExtraDataList.h"
#include "../../include/LowProcess.h"
#include "../../include/NiControllerManager.h"
#include "../../include/NiControllerSequence.h"
#include "../../include/NiRTTI.h"
#include "../../include/NiUpdateData.h"
#include "../../include/TESObjectDOOR.h"
#include "../../include/TESObjectACTI.h"
#include "../../include/TESObjectCONT.h"

// Form IDs used by this unit.
#include "../../include/ENUM_FORM_ID.h"
#include "../../include/NavMeshObstacleManager.h"

// Private declarations for the remaining animation and event interfaces.
class NiProperty;
class SkyShaderProperty;
SkyShaderProperty* NiObject_DynamicCast(const NiRTTI*, NiProperty*);
extern NiRTTI DAT_011f36ac;
#include "../../include/OBJECT_ACTION.h"
class AIThreadManager
{
  public:
    static TESObjectREFR* IsConditionMet();
};
bool IsConditionMet();
class TaskQueueInterface
{
  public:
    static TaskQueueInterface* GetSingleton();
    void TaskQueueInterface_QueueSetOpenState(TESObjectREFR*, bool, bool);
};

class GlobalObject_0045cf30
{
};
extern GlobalObject_0045cf30 g_011d7188;
extern const char DAT_01011f30[];
extern const char g_011d22b0_arg1[];
extern float DAT_0101ab70;
void bhkNiCollisionObject_ResetSim(NiNode*, bool);

// @fnv 0x0047a490
bool BGSOpenCloseForm::HasOpenCloseComponent(TESForm* apForm)
{
    bool bResult = false;
    bool bIsActivatorForm = false;
    if (apForm)
    {
        switch (static_cast<const TESForm*>(apForm)->GetFormType())
        {
        case ENUM_FORM_ID_ACTI_ID:
        case ENUM_FORM_ID_TERM_ID:
        case ENUM_FORM_ID_CONT_ID:
        case ENUM_FORM_ID_DOOR_ID:
            bResult = true;
            break;
        case ENUM_FORM_ID_TACT_ID:
        case ENUM_FORM_ID_FLOR_ID:
        case ENUM_FORM_ID_FURN_ID:
            bIsActivatorForm = true;
            break;
        default:
            break;
        }
    }
    return bResult;
}

// @fnv 0x0047b250
int BGSOpenCloseForm::GetOpenState(TESObjectREFR* ref)
{
    // Local names preserve MSVC9 stack allocation order.
    OPEN_STATE eState = CLOSED_UNKNOWN;
    if (ref && HasOpenCloseComponent(ref->GetObjectReference()))
    {
        bool pManager = ref->GetAction(OBJECT_ACTION_OBJECT_ACTION_OPEN);  // Saved open action flag.
        if (pManager)
            eState = OPEN;
        else
            eState = CLOSED;
        NiNode* pController = ref->GetNiNode();                                   // Reference scene node.
        NiTimeController* pNode = pController ? pController->NiObjectNET::GetControllers() : 0;  // Controller chain.
        // Runtime RTTI cast to the controller manager.
        NiControllerManager* bOpen = (NiControllerManager*)NiObject_DynamicCast(&DAT_011f36ac, (NiProperty*)pNode);
        if (bOpen)
        {
            NiControllerSequence* pOpenSequence = bOpen->FindSequenceByName(*TESObjectDOOR::GetOpenSequenceName());
            NiControllerSequence* pCloseSequence =
                bOpen->FindSequenceByName(*NiControllerManager::FindSequenceByName());
            if (pOpenSequence && pCloseSequence)
            {
                if (((LowProcess*)pOpenSequence)->LowProcess::GetActiveCombatTarget() == (TESObjectREFR*)1)
                    eState = OPENING;
                else if (((LowProcess*)pCloseSequence)->LowProcess::GetActiveCombatTarget() == (TESObjectREFR*)1)
                    eState = CLOSING;
            }
        }
    }
    return eState;
}

// @fnv 0x0047aec0
bool BGSOpenCloseForm::SetOpenState(TESObjectREFR* ref, bool open, bool immediate)
{
    bool result = false;
    if (ref && HasOpenCloseComponent(ref->GetObjectReference()))
    {
        if (IsConditionMet() && ref != AIThreadManager::IsConditionMet())
        {
            TaskQueueInterface::GetSingleton()->TaskQueueInterface_QueueSetOpenState(ref, open, immediate);
            return true;
        }
        if (open)
            ref->PerformAction(OBJECT_ACTION_OBJECT_ACTION_OPEN);
        else
            ref->CloseReference(OBJECT_ACTION_OBJECT_ACTION_OPEN);
        NiNode* node = ref->GetNiNode();
        NiTimeController* manager = node ? node->NiObjectNET::GetControllers() : 0;  // Controller chain.
        // Runtime RTTI cast to the controller manager.
        NiControllerManager* controller = (NiControllerManager*)NiObject_DynamicCast(&DAT_011f36ac, (NiProperty*)manager);
        if (controller)
        {
            NiControllerSequence* active = 0;
            NiControllerSequence* inactive = 0;
            NiControllerSequence* opening = controller->FindSequenceByName(*TESObjectDOOR::GetOpenSequenceName());
            NiControllerSequence* closing = controller->FindSequenceByName(*NiControllerManager::FindSequenceByName());
            if (opening && closing)
            {
                if (open)
                {
                    active = opening;
                    inactive = closing;
                }
                else
                {
                    active = closing;
                    inactive = opening;
                }
                controller->FUN_0047aa40(true);
                if (immediate)
                {
                    ref->GetExtraData()->CallExtraDataListMethod36(0);
                    controller->StopSequence(active, 0.0f);
                    controller->ActivateControllerSequence(inactive, 0, false, 1.0f, 0.0f, static_cast<NiControllerSequence*>(0));
                    inactive->PathingLOSGridMap_SetSightRadius(-DAT_0101ab70);
                    NiUpdateData data(inactive->NiPSysSpawnModifier_GetLifeSpan(), true, false);
                    ref->GetNiNode()->Update(static_cast<const NiUpdateData&>(data));
                    controller->StopSequence(inactive, 0.0f);
                    ref->TESObjectREFR_SetLastFinishedSequence(static_cast<const NiControllerSequence*>(active)->GetName());
                    bhkNiCollisionObject_ResetSim(ref->GetNiNode(), true);
                }
                else
                {
                    controller->StopSequence(inactive, 0.0f);
                    controller->ActivateControllerSequence(active, 0, false, 1.0f, 0.0f, static_cast<NiControllerSequence*>(0));
                    active->PathingLOSGridMap_SetSightRadius(-DAT_0101ab70);
                    NiUpdateData data(active->NiPSysSpawnModifier_GetLifeSpan(), true, false);
                    ref->GetNiNode()->Update(static_cast<const NiUpdateData&>(data));
                }
                result = true;
            }
        }
        else
        {
            if (open)
                ref->TESObjectREFR_SetLastFinishedSequence(DAT_01011f30);
            else
                ref->TESObjectREFR_SetLastFinishedSequence(g_011d22b0_arg1);
        }
        if (immediate && *((Setting*)&g_011d7188)->FUN_00408d60() &&
            static_cast<const TESForm*>(ref->GetObjectReference())->GetFormType() == ENUM_FORM_ID_DOOR_ID && ref->GetNiNode() &&
            !ref->GetExtraRadioData())
        {
            if (open)
                NavMeshObstacleManager::GetSingleton()->RemoveObstacleReference(ref);
            else
                NavMeshObstacleManager::GetSingleton()->AddObstacleReference(ref);
        }
    }
    return result;
}

// @fnv 0x00759450
// src: XBOX_PDB 0x00759450
float NiControllerSequence::NiPSysSpawnModifier_GetLifeSpan()
{
    return m_fFirstKeyTime;
}

// @fnv 0x0098adb0
// src: XBOX_PDB 0x0098adb0
void NiControllerSequence::PathingLOSGridMap_SetSightRadius(float afValue)
{
    m_fSequenceOffset = afValue;
}

extern NiFixedString* DAT_011c61c4;

// @fnv 0x005c1490
// src: XBOX_PDB 0x005c1490
NiFixedString* __cdecl FixedStrings_QSpecialIdle_AreaEffect()
{
    return DAT_011c61c4;
}

// @fnv 0x0047a3a0
BGSOpenCloseForm* GetOpenCloseForm(TESForm* apForm)
{
    BGSOpenCloseForm* pOpenCloseForm = 0;

    if (apForm && BGSOpenCloseForm::HasOpenCloseComponent(apForm))
    {
        switch (static_cast<const TESForm*>(apForm)->GetFormType())
        {
        case 0x15:
        case 0x17: {
            TESObjectACTI* pObject = reinterpret_cast<TESObjectACTI*>(apForm);
            pOpenCloseForm = static_cast<BGSOpenCloseForm*>(pObject);
            break;
        }

        case 0x1c: {
            TESObjectDOOR* pObject = reinterpret_cast<TESObjectDOOR*>(apForm);
            pOpenCloseForm = static_cast<BGSOpenCloseForm*>(pObject);
            break;
        }

        case 0x1b: {
            TESObjectCONT* pObject = reinterpret_cast<TESObjectCONT*>(apForm);
            pOpenCloseForm = static_cast<BGSOpenCloseForm*>(pObject);
            break;
        }
        }
    }

    return pOpenCloseForm;
}

struct EventString
{
    operator const char*() const;
};
struct SequenceEvent
{
    EventString& GetName();
};
struct Ref;
struct EventExtra
{
    Ref* GetTarget();
    void ResetTargetPointer(Ref*);
};
struct Ref
{
    EventExtra* Extra();
    TESForm* Base();
    void Reset(bool);
};
struct OpenCloseHandler
{
    virtual void Open(Ref*, Ref*);
    virtual void Close(Ref*, Ref*);
    virtual bool IsSpecial();
};
struct EventSetting
{
    unsigned char* Bool();
};
struct EventQueue
{
    void Open(Ref*);
    void Close(Ref*);
};
struct ObstacleManager
{
    static ObstacleManager* GetSingleton();
    void Open(Ref*);
    void Close(Ref*);
};
extern Ref* player;
extern EventSetting setting;
bool ProcessEvent(Ref*, SequenceEvent*);
int CompareEvent(const char*, const char*);
void SetEventFlags(Ref*, EventExtra*, unsigned int);
OpenCloseHandler* GetHandler(TESForm*);
bool ShouldQueue();
EventQueue* GetQueue();
// @fnv 0x0047ac70
void __cdecl ProcessOpenCloseEvent(Ref* ref, SequenceEvent* sequence)
{
    bool handled = false;
    if (ref && sequence)
    {
        handled = ProcessEvent(ref, sequence);
        if (!CompareEvent(sequence->GetName(), "Open"))
        {
            handled = true;
            SetEventFlags(ref, ref->Extra(), 0x10000);
            Ref* openTarget = ref->Extra()->GetTarget();
            if (openTarget)
            {
                OpenCloseHandler* openHandler = GetHandler(ref->Base());
                if (openHandler)
                    openHandler->Open(ref, openTarget);
                ref->Extra()->ResetTargetPointer(0);
                if (openTarget == player && openHandler && openHandler->IsSpecial())
                    player->Reset(false);
            }
            if (*setting.Bool() && ref->Base()->GetFormType() == 28)
            {
                if (ShouldQueue())
                    GetQueue()->Open(ref);
                else
                    ObstacleManager::GetSingleton()->Open(ref);
            }
        }
        else if (!CompareEvent(sequence->GetName(), "Close"))
        {
            handled = true;
            SetEventFlags(ref, ref->Extra(), 0x20000);
            Ref* closeTarget = ref->Extra()->GetTarget();
            if (closeTarget)
            {
                OpenCloseHandler* closeHandler = GetHandler(ref->Base());
                if (closeHandler)
                    closeHandler->Close(ref, closeTarget);
                ref->Extra()->ResetTargetPointer(0);
            }
            if (*setting.Bool() && ref->Base()->GetFormType() == 28)
            {
                if (ShouldQueue())
                    GetQueue()->Close(ref);
                else
                    ObstacleManager::GetSingleton()->Close(ref);
            }
        }
    }
}
