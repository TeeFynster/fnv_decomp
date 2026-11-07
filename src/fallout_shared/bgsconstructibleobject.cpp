#include "../../include/BGSConstructibleObject.h"
#include "../../include/TESForm.h"
#include "../../include/TESFile.h"
#include "../../include/TESBoundObject.h"
#include "../../include/BGSPickupPutdownSounds.h"
#include "../../include/BGSMessageIcon.h"
#include "../../include/BGSListForm.h"
#include "../../include/BGSDestructibleObjectForm.h"
#include "../../include/TESFullName.h"
#include "../../include/TESModel.h"
#include "../../include/TESModelTextureSwap.h"
#include "../../include/TESTexture.h"
#include "../../include/TESScriptableForm.h"
#include "../../include/TESValueForm.h"
#include "../../include/TESWeightForm.h"

// Extra operations used by this unit are not declared by the shared headers.
// This extension adds declarations only; all storage comes from the shared class.
class ConstructibleObjectOperations : public BGSConstructibleObject
{
public:
    void Save();
    bool Load(TESFile* file);
    void LoadFormReferences();
    void Copy(unsigned int form);
    bool Compare(void* form);
    unsigned int GetItemList();
    unsigned int GetCreatedItem();
    void SaveEmptyData();
    void CopyMisc(void* form);
    bool CompareMisc(void* form);
};

void* __cdecl _Deallocate(void*);
extern "C" void* __cdecl _alloca(unsigned int);
void __cdecl TESForm_AddChunk_00485910(unsigned int, unsigned int);

struct ModelSave
{
    void ProcessAndFreeData(unsigned int, unsigned int, unsigned int);
};

// @fnv 0x004f9bf0
unsigned int ConstructibleObjectOperations::GetItemList()
{
    return (unsigned int)m_pCreatedObject;
}

// @fnv 0x004f9480
void* BGSConstructibleObject::Destroy(unsigned int flags)
{
    FUN_004f94b0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

// @fnv 0x004f9570
// src: XBOX_PDB 0x004f9570
void BGSConstructibleObject::InitializeData()
{
    m_pCreatedObject = 0;
    m_pWorkbenchKeyword = 0;
}

// @fnv 0x004f9a90
void ConstructibleObjectOperations::Save()
{
    TESForm::BeginFormRecord();
    TESFullName::Save_00487010();
    ((ModelSave*)((char*)this + 0x3c))->ProcessAndFreeData(0x4C444f4d, 0x54444f4d, 0x53444f4d);
    TESIcon::Save(0x4e4f4349);
    BGSMessageIcon::Save(0x4f43494d);
    TESScriptableForm::Save();
    BGSDestructibleObjectForm::Save();
    SaveEmptyData();
    if (m_pCreatedObject)
    {
        unsigned int itempint = ((TESForm*)m_pCreatedObject)->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
        TESForm_AddChunk_00485910(0x4d414e52, itempint);
    }
    if (m_pWorkbenchKeyword)
    {
        unsigned int itempint2 = ((TESForm*)m_pWorkbenchKeyword)->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
        TESForm_AddChunk_00485910(0x4d414e43, itempint2);
    }
    TESForm::FinishFormRecord();
}

// Loads a bound object record from the file, dispatching each chunk to the matching loader and returning true.
// @fnv 0x004f96f0
bool ConstructibleObjectOperations::Load(TESFile* apFile)
{
    LoadRecordHeader(apFile);
    SetInitializationState(false);
    int chunkid;
    while ((chunkid = apFile->GetChunkID()) != 0)
    {
        switch (chunkid)
        {
        case 0x44494445: {
            char* pEditorId = (char*)_alloca(apFile->GetChunkSize());
            apFile->GetChunkData(pEditorId, 0x200);
            SetEditorID_AtRuntime(pEditorId);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(apFile);
            break;
        case 0x4c4c5546:
            TESFullName::LoadFullNameChunk(this, apFile);
            break;
        case 0x4c444f4d:
        case 0x54444f4d:
        case 0x44534f4d:
        case 0x44444f4d:
            TESModel::LoadModelData(this, apFile);
            break;
        case 0x53444f4d: {
            unsigned int uiChunkSize = apFile->GetChunkSize();
            void* pChunkData = _alloca(uiChunkSize);
            apFile->GetChunkData(pChunkData, uiChunkSize);
            TESModelTextureSwap::ParseTextureSwapData(pChunkData, uiChunkSize, apFile->GetFormVersion());
            break;
        }
        case 0x4e4f4349:
            TESTexture::ReadTextureData(this, apFile);
            break;
        case 0x4f43494d:
            BGSMessageIcon::LoadMessageIconChunk(this, apFile);
            break;
        case 0x49524353: {
            unsigned int tempint = 0;
            apFile->GetChunkData(&tempint);
            TESScriptableForm::FUN_006ecd40(tempint);
            TESScriptableForm::InitItem(this);
            break;
        }
        case 0x54534544:
        case 0x44545344:
            BGSDestructibleObjectForm::LoadDestructibleData(this, apFile);
            break;
        case 0x41544144:
            ReadTypedData(apFile, 0, 0);
            break;
        case 0x4d414e52: {
            unsigned int itempint = 0;
            apFile->GetChunkData(&itempint);
            m_pCreatedObject = (BGSListForm*)itempint;
            break;
        }
        case 0x4d414e43: {
            unsigned int itempint = 0;
            apFile->GetChunkData(&itempint);
            m_pWorkbenchKeyword = (TESBoundObject*)itempint;
            break;
        }
        }
        if (!apFile->NextChunk())
            break;
    }
    return true;
}

extern char DAT_01183028;
extern char DAT_01189c78;
void* __cdecl FUN_00ec43fb(unsigned int, unsigned int, void*, void*, unsigned int);

// @fnv 0x004f9b80
void ConstructibleObjectOperations::Copy(unsigned int a1)
{
    void* r = FUN_00ec43fb(a1, 0, &DAT_01183028, &DAT_01189c78, 0);
    if (r == 0)
    {
    }
    else
    {
        CopyMisc(r);
        m_pCreatedObject = (void*)reinterpret_cast<ConstructibleObjectOperations*>(r)->GetItemList();
        m_pWorkbenchKeyword = (void*)reinterpret_cast<ConstructibleObjectOperations*>(r)->GetCreatedItem();
    }
}

TESForm* __cdecl TESForm_GetFormByNumericID(unsigned int id);
void __cdecl ResolveFormID(unsigned int* id, void* file);
int __cdecl Warning_005b5e40(const char* fmt, ...);

// @fnv 0x004f95a0
void ConstructibleObjectOperations::LoadFormReferences()
{
    if (GetInitialized())
        return;
    TESObjectMISC::InitItem();
    unsigned int id = (unsigned int)m_pCreatedObject;
    if (id)
    {
        ResolveFormID(&id, FUN_00484e60(-1));
        m_pCreatedObject = dynamic_cast<BGSListForm*>(TESForm_GetFormByNumericID(id));
        if (!m_pCreatedObject)
            Warning_005b5e40("MASTERFILE: Could not find item list (%08X) on constructible object '%s' (%08X).", id, GetName(),
                         GetHavokWorldObjectCountInSceneGraph_0084e3a0());
    }
    id = (unsigned int)m_pWorkbenchKeyword;
    if (id)
    {
        ResolveFormID(&id, FUN_00484e60(-1));
        m_pWorkbenchKeyword = dynamic_cast<TESBoundObject*>(TESForm_GetFormByNumericID(id));
        if (!m_pWorkbenchKeyword)
            Warning_005b5e40("MASTERFILE: Could not find created item (%08X) on constructible object '%s' (%08X).", id,
                         GetName(), GetHavokWorldObjectCountInSceneGraph_0084e3a0());
    }
    SetInitializationState(true);
}

// @fnv 0x004f9c10
bool ConstructibleObjectOperations::Compare(void* apCompare)
{
    void* pcomp = FUN_00ec43fb((unsigned int)apCompare, 0, &DAT_01183028, &DAT_01189c78, 0);
    if (!pcomp)
        return true;
    if (CompareMisc(pcomp))
        return true;
    if (m_pCreatedObject != (BGSListForm*)((ConstructibleObjectOperations*)pcomp)->GetItemList())
        return true;
    if (m_pWorkbenchKeyword != (TESBoundObject*)((ConstructibleObjectOperations*)pcomp)->GetCreatedItem())
        return true;
    return false;
}

// @fnv 0x004f94b0
BGSConstructibleObject::~BGSConstructibleObject()
{
    TESForm::ClearData();
}
