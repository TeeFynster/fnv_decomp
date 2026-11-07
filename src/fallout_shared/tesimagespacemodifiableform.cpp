// fallout_shared/tesimagespacemodifiableform.cpp: TESImageSpaceModifiableForm (5 functions)

#include "../../include/BaseFormComponent.h"
#include "../../include/BGSCameraPath.h"
#include "../../include/TESForm.h"
#include "../../include/TESImageSpaceModifiableForm.h"
#include "../../include/TESImageSpaceModifier.h"

int Warning(const char*, ...);

// Resolves the stored form ID to a TESImageSpaceModifier via the owner's file and warns if it cannot be found.
// @fnv 0x00487490
void TESImageSpaceModifiableForm::InitItem(TESForm* owner)
{
    if (m_pImageSpaceModifier)
    {
        unsigned int formID = (unsigned int)m_pImageSpaceModifier;
        if (owner)
            TESForm::RemapFormIDForFile(formID, owner->GetFile(-1));
        m_pImageSpaceModifier = dynamic_cast<TESImageSpaceModifier*>(TESForm::GetFormByID(formID));
        if (!m_pImageSpaceModifier)
        {
            if (owner)
            {
                if (((BGSCameraPath*)owner)->HasNameForWarning())
                    Warning("MASTERFILE: Unable to find imagespacemodifier (%08X) on owner object \"%s\".", formID,
                            owner->GetName());
                else
                    Warning("MASTERFILE: Unable to find imagespacemodifier (%08X) on owner object (%08X).", formID,
                            owner->GetFormID());
            }
            else
                Warning("MASTERFILE: Unable to find imagespacemodifier (%08X) on unknown owner.", formID);
        }
    }
}

// Initialises the base component and clears the image space modifier.
// @fnv 0x00487420
TESImageSpaceModifiableForm::TESImageSpaceModifiableForm()
{
    ClearComponent();
}

extern "C" void TESForm_AddChunk_00485910(unsigned int, unsigned int);

// @fnv 0x00487450
void TESImageSpaceModifiableForm::Save()
{
    if (m_pImageSpaceModifier)
    {
        unsigned int id = m_pImageSpaceModifier->GetFormID();
        TESForm_AddChunk_00485910(0x4D414E4D, id);
    }
}

// @fnv 0x00487570
void TESImageSpaceModifiableForm::CopyFromBase(BaseFormComponent* component)
{
    TESImageSpaceModifiableForm* pHelper = dynamic_cast<TESImageSpaceModifiableForm*>(component);
    if (pHelper == 0)
    {
    }
    else
    {
        this->SetFormImageSpaceModifying(pHelper->GetFormImageSpaceModifying());
    }
}

// Returns true if the cast fails or the two modifier getters return different values.
// @fnv 0x004875c0
bool TESImageSpaceModifiableForm::CompareWithBase(BaseFormComponent* apCompareFC)
{
    TESImageSpaceModifiableForm* pCompareImageSpaceForm = dynamic_cast<TESImageSpaceModifiableForm*>(apCompareFC);
    if (!pCompareImageSpaceForm)
        return true;
    if (this->GetFormImageSpaceModifying() != pCompareImageSpaceForm->GetFormImageSpaceModifying())
        return true;
    return false;
}
