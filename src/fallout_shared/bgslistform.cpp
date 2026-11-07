// fallout_shared/bgslistform.cpp: BGSListForm and related forms (17 functions)

#include "bgslistform_decls.h"
#include "../../include/BGSListForm.h"

#include "../../include/BGSSaveFormBuffer.h"

// @fnv 0x0058FB00
void BGSListForm::ClearData()
{
    GetList()->RemoveAll();
    m_uiFormCount = 0;
}

// @fnv 0x005901C0
void BGSListForm::Revert(BGSLoadFormBuffer* buffer)
{
    TESForm::Revert(buffer);
    if (buffer->GetOldChangeFlags(0x80000000).operator bool())
        ClearFormList();
}

// @fnv 0x00590010
void BGSListForm::IncludeForm(TESForm* form)
{
    if (form != 0)
    {
        if (!GetList()->IsInList(form))
        {
            GetList()->AddHead(form);
            ++m_uiFormCount;
            MarkAsModified(0x80000000);
        }
    }
}

// @fnv 0x00591B70
BGSRadiationStage::BGSRadiationStage()
{
    reinterpret_cast<BSSimpleList<TESForm*>*>(reinterpret_cast<unsigned char*>(this) + 0x18)->FUN_004019f0();
    SetFormType((ENUM_FORM_ID)0x5A);
    ResetFormData();
}

// @fnv 0x00590120
void BGSListForm::LoadGame(BGSLoadFormBuffer* buffer)
{
    TESForm::LoadGame(buffer);
    if (buffer->GetChangeFlags(0x80000000).operator bool())
    {
        if (m_uiFormCount != 0)
            ClearFormList();

        unsigned int formCount = 0;
        buffer->ReadTypedData(static_cast<void*>(&formCount), 4u);
        for (unsigned int index = 0; index < formCount; ++index)
        {
            TESForm* form = TESForm::GetFormByID(buffer->BGSLoadGameBuffer::ReadFormIdentifier());
            IncludeForm(form);
        }
    }
}

// @fnv 0x0058FD40
bool BGSListForm::Load(TESFile* file)
{
    LoadRecordHeader(file);
    SetInitializationState(false);

    unsigned int chunkID;
    while ((chunkID = file->GetChunkID()) != 0)
    {
        switch (chunkID)
        {
        case 0x44494445: {
            char* editorID = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(editorID, 0x200);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4d414e4c: {
            unsigned int formID = 0;
            file->GetChunkData(&formID);
            {
                GetList()->AddTail((TESForm*)formID);
            }
            break;
        }
        default:
            break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

// @fnv 0x0058FE50
void BGSListForm::InitItem()
{
    if (static_cast<const TESForm*>(this)->GetInitialized())
        return;
    BSSimpleList<TESForm*>* current = GetList();
    BSSimpleList<TESForm*>* previous = 0;
    TESForm* form;
    while (current != 0 && !current->IsEmpty())
    {
        unsigned int formID = (unsigned int)current->GetItem();
        RemapFormIDForFile(formID, GetFile(-1));
        form = GetFormByID(formID);
        if (form != 0)
        {
            current->SetItem(form);
            previous = current;
            current = current->GetNext();
        }
        else
        {
            Warning("MASTERFILE: Unable to find form (%08X) on list form %s (%08X).", formID, GetName(), GetFormID());
            if (previous != 0)
            {
                previous->Remove((TESForm*)formID);
                current = previous->GetNext();
            }
            else
            {
                current->RemoveHead();
            }
        }
    }
    SetInitializationState(true);
}

// @fnv 0x0058ffd0
void BGSListForm::ClearFormList()
{
    while (m_uiFormCount != 0)
    {
        GetList()->RemoveHead();
        m_uiFormCount = m_uiFormCount - 1;
    }
}

void _FUN_00485910(unsigned int, unsigned int);
// @fnv 0x0058fcc0
// src: XBOX_PDB 0x0058fcc0
void BGSListForm::Save_0058fcc0()
{
    reinterpret_cast<TESForm*>(this)->BeginFormRecord();
    BSSimpleList<TESForm*>* pCondition = GetList();
    while (pCondition && !pCondition->IsEmpty())
    {
        TESForm* pForm = pCondition->GetItem();
        unsigned int formID6 = pForm->GetFormID();
        _FUN_00485910(0x4d414e4c, formID6);
        pCondition = pCondition->GetNext();
    }
    reinterpret_cast<TESForm*>(this)->FinishFormRecord();
}

// @fnv 0x0058fbc0
bool BGSListForm::IsNotEqual(TESForm* apCompare)
{
    BGSListForm* pcompare = dynamic_cast<BGSListForm*>(apCompare);
    if (!pcompare)
        return true;
    if (GetList()->ItemsInList() != pcompare->GetList()->ItemsInList())
        return true;
    BSSimpleList<TESForm*>* pCurrentElementNext = GetList();
    BSSimpleList<TESForm*>* pcomplist = pcompare->GetList();
    while (pCurrentElementNext && !pCurrentElementNext->IsEmpty() && pcomplist &&
           !pcomplist->IsEmpty())
    {
        if (pCurrentElementNext->GetItem() != pcomplist->GetItem())
            return true;
        pCurrentElementNext = pCurrentElementNext->GetNext();
        pcomplist = pcomplist->GetNext();
    }
    if (TESForm::Compare(pcompare))
        return true;
    return false;
}

// Appends the source list entries, then copies the common form data.
// @fnv 0x0058fb30
void BGSListForm::CopyConditionsFromListForm(TESForm* apCopy)
{
    BGSListForm* pListForm = dynamic_cast<BGSListForm*>(apCopy);
    if (!pListForm)
        return;
    BSSimpleList<TESForm*>* pCurrentElementNext = pListForm->GetList();
    while (pCurrentElementNext && !pCurrentElementNext->IsEmpty())
    {
        TESForm* pform = pCurrentElementNext->GetItem();
        GetList()->AddTail(pform);
        pCurrentElementNext = pCurrentElementNext->GetNext();
    }
    TESForm::CopyFrom(reinterpret_cast<TESForm*>(pListForm));
}

// @fnv 0x0058ff60
int BGSListForm::GetConditionIndex(TESForm* apForm)
{
    int iElementIndex = 0;
    BSSimpleList<TESForm*>* pCurrentElementNext = GetList();
    while (pCurrentElementNext && !pCurrentElementNext->IsEmpty())
    {
        if (pCurrentElementNext->GetItem() == apForm)
            break;
        iElementIndex++;
        pCurrentElementNext = pCurrentElementNext->GetNext();
    }
    if (!pCurrentElementNext)
        iElementIndex = -1;
    return iElementIndex;
}

// @fnv 0x00590080
void BGSListForm::SaveFormList(BGSSaveFormBuffer* apSaveGameBuffer)
{
    TESForm::SaveGame(apSaveGameBuffer);
    if (reinterpret_cast<BGSLoadFormBuffer*>(apSaveGameBuffer)->GetChangeFlags(0x80000000).operator bool())
    {
        BSSimpleList<TESForm*>* pCurrentElementNext = &m_kFormList;
        apSaveGameBuffer->SaveData(static_cast<void*>(&m_uiFormCount), 4, 0);
        for (unsigned int i = 0; i < m_uiFormCount; ++i)
        {
            TESForm* pform = pCurrentElementNext->GetItem();
            pCurrentElementNext = pCurrentElementNext->GetNext();
            apSaveGameBuffer->SerializeFormData(pform, 0);
        }
    }
}

// Initializes the list form and clears its added-form count.
// @fnv 0x0058f9d0
BGSListForm::BGSListForm()
{
    ClearFormData();
    SetFormType((ENUM_FORM_ID)0x55);
    m_uiFormCount = 0;
}

// @fnv 0x0058fa90
BGSListForm::~BGSListForm()
{
    BGSListForm::ClearData();
}

class Member_5effc0
{
  public:
    int unk00;

    Member_5effc0();
    ~Member_5effc0();
};

class FUN_005effc0 : public TESForm
{
  public:
    virtual void v00();
    unsigned char m_18;
    Member_5effc0 m_1c;

    FUN_005effc0();
};

// Initializes the form type and clears its flag.
// @fnv 0x005effc0
FUN_005effc0::FUN_005effc0()
{
    SetFormType((ENUM_FORM_ID)0x5d);
    m_18 = 0;
}
