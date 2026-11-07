// fallout_shared/bgsbipedmodellist.cpp: BGSBipedModelList (8 functions)

#include "bgsbipedmodellist_decls.h"
#include "../../include/BaseFormComponent.h"
#include "../../include/TESNPC.h"
#include <stddef.h>
// Returns the biped model list of a TESForm if it is an NPC or armor, otherwise null.
// @fnv 0x00475020
BGSBipedModelList* BGSBipedModelList::GetBipedModelList(TESForm* form)
{
    BGSBipedModelList* result = 0;
    if (form)
    {
        switch (static_cast<const TESForm*>(form)->GetFormType())
        {
        case ENUM_FORM_ID_WEAP_ID: {
            TESNPC* npc = static_cast<TESNPC*>(form);
            // Use the shared component view offset without an accessor call in /Od code.
            result = npc ? reinterpret_cast<BGSBipedModelList*>(
                reinterpret_cast<unsigned char*>(npc) + offsetof(TESNPC, data) - 0x34) : 0;
            break;
        }
        case ENUM_FORM_ID_ARMO_ID: {
            TESObjectARMO* armor = static_cast<TESObjectARMO*>(form);
            result = static_cast<BGSBipedModelList*>(armor);
            break;
        }
        }
    }
    return result;
}

// Resolves the list form by ID, warns if it is missing or not a BGSListForm, and validates each entry as a biped model.
// @fnv 0x00474da0
void BGSBipedModelList::InitItem(TESForm* owner)
{
    unsigned int formID = (unsigned int)pListForm;
    if (formID)
    {
        TESFile* file = owner ? owner->GetFile(-1) : 0;
        TESForm::RemapFormIDForFile(formID, file);
        pListForm = dynamic_cast<BGSListForm*>(TESForm::GetFormByID(formID));
        bool bad;
        if (!pListForm)
        {
            if (owner)
            {
                if (((BGSCameraPath*)owner)->HasNameForWarning())
                    Warning(DAT_0101a5f0, formID, owner->GetName());
                else
                    Warning(DAT_0101a5a0, formID, owner->GetFormID());
            }
            else
                Warning(DAT_0101a558, formID);
        }
        else
        {
            bad = false;
            BSSimpleList<BGSPerkEntry*>* iter = (BSSimpleList<BGSPerkEntry*>*)((BGSCameraPath*)pListForm)->GetConditions();
            TESForm* entry;
            while (iter && !((BSSimpleList<BGSCameraShot*>*)iter)->IsEmpty())
            {
                TESBipedModelForm* model;
                entry = (TESForm*)iter->GetItem();
                model = TESBipedModelForm::GetFormAsBipedModel(entry);
                if (!model)
                {
                    Warning(DAT_0101a4d8, entry->GetName(), entry->GetFormID(), pListForm->GetName(), pListForm->GetFormID(),
                            owner->GetName(), owner->GetFormID());
                    pListForm = 0;
                    break;
                }
                else
                    model->TESBipedModelForm_SetAddOnModel(true);
                iter = iter->GetNext();
            }
        }
    }
}

// @fnv 0x00474d10
BGSBipedModelList::BGSBipedModelList()
{
    BGSBipedModelList::Init();
}

extern "C" void __cdecl _FUN_00485910(unsigned int, unsigned int);

// Save is not declared by the shared component; retain it as a typed helper.
// @fnv 0x00474d60
// src: COMMUNITY 0x00474d60
void __fastcall BGSBipedModelList_Save(BGSBipedModelList* component)
{
    if (component->pListForm)
    {
        unsigned int id = component->pListForm->GetFormID();
        _FUN_00485910(0x4c504942, id);
    }
}

void __cdecl _FUN_00485910(unsigned int, unsigned int);
struct FUN_00479350_shell
{
    void BGSEquipType_Save();
};
// @fnv 0x00479350
// src: COMMUNITY 0x00479350
void FUN_00479350_shell::BGSEquipType_Save()
{
    unsigned int tempint;
    tempint = *(unsigned int*)((char*)this + 4);
    _FUN_00485910(0x50595445, tempint);
}

// BaseFormComponent's original out-of-line teardown is not declared in its header.
void __fastcall FUN_00483710(BaseFormComponent* component);

// @fnv 0x00474d40
BGSBipedModelList::~BGSBipedModelList()
{
    FUN_00483710(this);
}

// Returns true if the other component is not a biped model list or references a different list.
// @fnv 0x00474fc0
bool BGSBipedModelList::CompareWithBase(BaseFormComponent* apCompareFC)
{
    BGSBipedModelList* pcomp = dynamic_cast<BGSBipedModelList*>(apCompareFC);
    if (!pcomp)
        return true;
    if (pcomp->GetList() != this->GetList())
        return true;
    return false;
}

// Copies the list reference from another biped model list component.
// @fnv 0x00474f70
void BGSBipedModelList::CopyFromBase(BaseFormComponent* apCopyFC)
{
    BGSBipedModelList* pCopyFC = dynamic_cast<BGSBipedModelList*>(apCopyFC);
    if (!pCopyFC)
        return;
    SetBipedModelList(pCopyFC->GetList());
}
