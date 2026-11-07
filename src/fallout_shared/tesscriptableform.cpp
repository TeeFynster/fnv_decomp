// fallout_shared/tesscriptableform.cpp: TESScriptableForm (6 functions)

#include "../../include/BGSCameraPath.h"
#include "../../include/Script.h"
#include "../../include/TESScriptableForm.h"
#include "../../include/BGSEquipType.h"
#include "../../include/BGSMessageIcon.h"
#include "../../include/TESFullName.h"
#include "../../include/TESIcon.h"
#include "../../include/TESTexture.h"
#include "../../include/TESWeightForm.h"

TESForm* GetFormByID(unsigned int id);
int Warning(const char*, ...);

// Resolves the stored script ID to a Script and warns if it cannot be found, then marks the item as initialized.
// @fnv 0x0048cd90
void TESScriptableForm::InitItem(TESForm* owner)
{
    if (m_bHasScript)
        return;
    if (m_pFormScript)
    {
        unsigned int scriptID = (unsigned int)m_pFormScript;
        TESForm::RemapFormIDForFile(scriptID, owner->GetFile(-1));
        m_pFormScript = dynamic_cast<Script*>(GetFormByID(scriptID));
        if (!m_pFormScript)
        {
            if (owner)
            {
                if (((BGSCameraPath*)owner)->HasNameForWarning())
                    Warning("MASTERFILE: Unable to find script (%08X) on owner object \"%s\".", scriptID,
                            owner->GetName());
                else
                    Warning("MASTERFILE: Unable to find script (%08X) on owner object (%08X).", scriptID,
                            owner->GetFormID());
            }
            else
                Warning("MASTERFILE: Unable to find script (%08X) on unknown owner.", scriptID);
        }
    }
    m_bHasScript = true;
}

extern int DAT_0101d518;
void __fastcall TESScriptableForm_InitializeDataComponent(void* pThis);

// Initialises a BaseFormComponent: runs its base constructor, installs the vtable at DAT_0101d518, calls FUN_0048cc80, and returns pThis.
// @fnv 0x0048cc50
// src: GUESS 0x0048cc50 (confidence: high)
void* __fastcall TESScriptableForm_InitializeDataComponent_InitializeScriptableFormComponent(BaseFormComponent* apComponent)
{
    apComponent->BaseFormComponent::BaseFormComponent();
    *(int**)apComponent = &DAT_0101d518;
    TESScriptableForm_InitializeDataComponent(apComponent);
    return apComponent;
}

// @fnv 0x0048cc80
// src: XBOX_PDB 0x0048cc80
void __fastcall TESScriptableForm_InitializeDataComponent(void* pThis)
{
    static_cast<TESScriptableForm*>(pThis)->m_pFormScript = 0;
    static_cast<TESScriptableForm*>(pThis)->m_bHasScript = false;
}

void __cdecl TESForm_AddChunk_00485910(unsigned int, unsigned int);
// @fnv 0x0048cca0
// src: COMMUNITY 0x0048cca0
void TESScriptableForm::Save_0048cca0()
{
    if (m_pFormScript)
    {
        unsigned int formID = m_pFormScript->GetFormID();
        TESForm_AddChunk_00485910(0x49524353, formID);
    }
}

// Copies the referenced script from another scriptable form.
// @fnv 0x0048cce0
void TESScriptableForm::CopyFromBase(BaseFormComponent* apCopyFC)
{
    TESScriptableForm* pCopy = dynamic_cast<TESScriptableForm*>(apCopyFC);
    if (!pCopy)
        return;
    Initialize((unsigned int)pCopy->FUN_00726070());
}

// Returns true if the component is not scriptable or references a different script.
// @fnv 0x0048cd30
bool TESScriptableForm::CompareWithBase(BaseFormComponent* apComponent)
{
    TESScriptableForm* b = dynamic_cast<TESScriptableForm*>(apComponent);
    if (!b)
        return true;
    if (FUN_00726070() != b->FUN_00726070())
        return true;
    return false;
}
