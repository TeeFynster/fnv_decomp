// src/fallout_shared/tescontainer_rtti2_variant.cpp - RTTI variant unit created 2026-11-01 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (-). The skeleton of src/fallout_shared/tescontainer.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

#include "../../include/BGSPerkEntry.h"
class InventoryStackRecord;
class TESObject;
#include "../../include/TESBoundObject.h"
#include "../../include/TESContainer.h"
#include "../../include/TESForm.h"
class ContainerItemExtra
{
  public:
    void* m_pForm;
    union
    {
        void* m_pGlobal;
        int m_cRank;
        unsigned int bits;
    };
    float m_fHealth;
    ContainerItemExtra();
    void Copy(ContainerItemExtra* other);
    bool IsDefault();
};
class InventoryItemEntry
{
  public:
    int count;
    void* object;
    ContainerItemExtra* extra;
    void Copy(InventoryItemEntry* other);
    void InitItem(TESForm* form);
};
struct ContainerCountState
{
    int count;
    BSSimpleList<InventoryStackRecord*>* list;
};
struct CopyComponentState
{
    BSSimpleList<InventoryStackRecord*>* list;
    TESContainer* source;
};
class B81390Extra
{
  public:
    void ResolveFormReferences(TESForm* pkOwner);
};

void __cdecl ResolveFormID(unsigned int* puiFormID, TESFile* file);
TESForm* __cdecl TESForm_GetFormByNumericID(unsigned int auiFormId);
void __cdecl Warning_005b5e40(const char* pcFormat, ...);

class B81390ContainerObject
{
  public:
    void ContainerObject_InitItem(TESForm* pkOwner);

    int m_iArrayLength;
    TESBoundObject* m_pPointer;
    B81390Extra* m_pkExtra;
};

// @fnv 0x00481390
// src: XBOX_PDB 0x00481390
void B81390ContainerObject::ContainerObject_InitItem(TESForm* pkOwner)
{
    unsigned int auiFormId = (unsigned int)m_pPointer;
    ResolveFormID(&auiFormId, pkOwner->FUN_00484e60(-1));
    m_pPointer = dynamic_cast<TESBoundObject*>(TESForm_GetFormByNumericID(auiFormId));
    if (!m_pPointer)
    {
        if (pkOwner)
        {
            if (pkOwner->GetFormEditorIDLength())
                Warning_005b5e40("MASTERFILE: Unable to find container object (%08X) on owner object \"%s\".", auiFormId,
                             pkOwner->GetName());
            else
                Warning_005b5e40("MASTERFILE: Unable to find container object (%08X) on owner object (%08X).", auiFormId,
                             pkOwner->GetHavokWorldObjectCountInSceneGraph_0084e3a0());
        }
        else
        {
            Warning_005b5e40("MASTERFILE: Unable to find container object (%08X) on unknown owner.", auiFormId);
        }
    }
    if (m_pkExtra)
        m_pkExtra->ResolveFormReferences(pkOwner);
}
