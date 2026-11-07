// fallout_shared/bgsrepairitemlist.cpp: BGSRepairItemList (6 functions)

#include "../../include/BaseFormComponent.h"
#include "../../include/TESFile.h"

#include "../../include/BGSCameraPath.h"
#include "../../include/BGSListForm.h"
#include "../../include/BGSRepairItemList.h"
#include "../../include/TESForm.h"

int Warning(const char*, ...);

// The shared class has no accessor declaration for this out-of-line getter yet.
BGSListForm* __fastcall GetRepairItemList(BGSRepairItemList* component);

// Resolves pListForm's form ID to a BGSListForm and warns if the lookup fails, naming the owner when available.
// @fnv 0x0047b8e0
void BGSRepairItemList::InitItem(TESForm* owner)
{
    unsigned int formID = (unsigned int)pListForm;
    if (formID)
    {
        TESFile* file = owner ? owner->GetFile(-1) : 0;
        TESForm::RemapFormIDForFile(formID, file);
        pListForm = dynamic_cast<BGSListForm*>(TESForm::GetFormByID(formID));
        if (!pListForm)
        {
            if (owner)
            {
                if (((BGSCameraPath*)owner)->HasNameForWarning())
                    Warning("MASTERFILE: Unable to find repair item list (%08X) for owner object \"%s\".", formID,
                            owner->GetName());
                else
                    Warning("MASTERFILE: Unable to find repair item list (%08X) for owner object (%08X).", formID,
                            owner->GetFormID());
            }
            else
                Warning("MASTERFILE: Unable to find repair item list (%08X) for unknown owner.", formID);
        }
    }
}

// @fnv 0x0047b850
BGSRepairItemList::BGSRepairItemList()
{
    BGSRepairItemList::InitializeComponent();
}

// @fnv 0x0047b880
BGSRepairItemList::~BGSRepairItemList()
{
    BGSRepairItemList::Free();
}

void __cdecl TESForm_AddChunk_00485910(unsigned int, unsigned int);
// @fnv 0x0047b8a0
void __fastcall SaveRepairItemList(BGSRepairItemList* component)
{
    unsigned int formID;
    if (component->pListForm != 0)
    {
        formID = component->pListForm->GetFormID();
        TESForm_AddChunk_00485910(0x4C504552, formID);
    }
}

// Copies the repair list when the source component is a BGSRepairItemList.
// @fnv 0x0047b9d0
void BGSRepairItemList::CopyFromBase(BaseFormComponent* apCopyFC)
{
    BGSRepairItemList* pcopy = dynamic_cast<BGSRepairItemList*>(apCopyFC);
    if (!pcopy)
        return;
    SetRepairItemList(GetRepairItemList(pcopy));
}

// Returns true if the component has a different repair list or component type.
// @fnv 0x0047ba20
bool BGSRepairItemList::CompareWithBase(BaseFormComponent* component)
{
    BGSRepairItemList* other = dynamic_cast<BGSRepairItemList*>(component);
    if (!other)
        return true;
    if (GetRepairItemList(other) != GetRepairItemList(this))
        return true;
    return false;
}
