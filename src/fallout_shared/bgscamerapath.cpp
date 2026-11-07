// fallout_shared/bgscamerapath.cpp: BGSCameraPath and related functions (24 functions)

// Keep the unit support types while using the shared form hierarchy.
#include "layout_support.h"
#define FNV64_BSSIMPLELIST_DEFINED
#include "../../include/BGSCameraShot.h"
#define FNV_BASEFORMCOMPONENT_H
#define FNV_TESFORM_H
#include "../../include/BGSAcousticSpace.h"
#include "../../include/BGSImpactData.h"
#include "../../include/NiFormArray.h"
#include "../../include/CameraShotData.h"
#include "../../include/BGSCameraPath.h"
#include "bgscamerapath.h"
#include "../../include/Script.h"

// @fnv 0x0058a620
void BGSCameraPath::ResetFormData()
{
    data.cFlags = 0;
    m_pFirstCameraPath = 0;
    m_pSecondCameraPath = 0;
}

// @fnv 0x005f4bb0
void BGSCameraPath::AssignParentPath(BGSCameraPath* parent)
{
    m_pFirstCameraPath = parent;
}

// @fnv 0x0058a650
void BGSCameraPath::ClearData()
{
    GetConditions()->InitializeConditionItems();
    m_kCameraShotList.RemoveAll();
}

// @fnv 0x0058a380
BGSCameraPath::BGSCameraPath()
{
    SetFormType(ENUM_FORM_ID_CPTH_ID);
    m_pPathArray = 0;
    ResetFormData();
}

extern int __cdecl Warning(const char* format, ...);
extern "C" const char fnv_MessageWithName[];
extern "C" const char fnv_MessageWithFormID[];

// Initializes conditions and walks the shot list, resolving each form ID to a BGSCameraShot and removing entries that fail to resolve, warning for each.
// @fnv 0x0058ad90
void BGSCameraPath::InitItem()
{
    if (IsFormInitialized())
        return;

    ((TESConditionInit*)GetConditions())->InitItem(this);

    BSSimpleList<BGSCameraShot*>* pShotNode = GetShotList();
    BSSimpleList<BGSCameraShot*>* previous = 0;
    struct InitItemLocals
    {
        BGSCameraShot* cameraShot;
        unsigned int formID;
    } shotEntry;
    while (pShotNode && !pShotNode->IsEmpty())
    {
        shotEntry.formID = (unsigned int)pShotNode->GetItem();
        TESForm::RemapFormIDForFile(shotEntry.formID, GetFile(-1));
        shotEntry.cameraShot = dynamic_cast<BGSCameraShot*>(TESForm::GetFormByID(shotEntry.formID));
        if (!shotEntry.cameraShot)
        {
            if (previous)
            {
                previous->Remove(pShotNode->GetItem());
                pShotNode = previous->GetNext();
            }
            else
                pShotNode->RemoveHead();

            if (HasNameForWarning())
                Warning(fnv_MessageWithName, shotEntry.formID, GetName());
            else
                Warning(fnv_MessageWithFormID, shotEntry.formID, GetFormID());
        }
        else
        {
            pShotNode->SetItem(shotEntry.cameraShot);
            previous = pShotNode;
            pShotNode = pShotNode->GetNext();
        }
    }

    SetInitializationState(true);
}

extern "C" const char fnv_MessageMultipleNext[];

// @fnv 0x0058b190
void BGSCameraPath::SetPathArray(NiFormArray* paths)
{
    if (!paths)
        return;

    struct FixNextLocals
    {
        unsigned int index;
        unsigned int invalidCount;
        unsigned int nextIndex;
        unsigned int currentIndex;
        BGSCameraPath* nextPath;
        unsigned int pathCount;
    } locals;

    locals.invalidCount = 0;
    locals.currentIndex = 0xffffffff;
    locals.pathCount = paths->GetSize();
    locals.nextIndex = 0xffffffff;
    locals.nextPath = 0;
    locals.index = 0;

    for (; locals.index < locals.pathCount; ++locals.index)
    {
        BGSCameraPath* path = dynamic_cast<BGSCameraPath*>(paths->FUN_00877a30(locals.index));
        if (path)
        {
            if (path == this)
                locals.currentIndex = locals.index;
            else if (path->GetPrevPath() == this)
            {
                if (!locals.nextPath)
                {
                    locals.nextPath = path;
                    locals.nextIndex = locals.index;
                }
                else
                {
                    BSStringT<char> name;
                    GetDebugName(&name);
                    Warning(fnv_MessageMultipleNext, name.String());
                }
            }
        }
        else
            ++locals.invalidCount;
    }

    if (locals.currentIndex != 0xffffffff && locals.nextIndex != 0xffffffff &&
        locals.nextIndex != locals.currentIndex + 1)
    {
        unsigned int oldSize = 0;
        paths->SetSize(locals.nextIndex, &oldSize);
        paths->Compact();
        if (locals.nextIndex < locals.currentIndex)
            ++locals.invalidCount;
        locals.currentIndex -= locals.invalidCount;
        paths->SetFormAtIndex(locals.currentIndex + 1, locals.nextPath);
        paths->Compact();
        locals.nextPath->SetPathArray(paths);
    }
}

extern "C" void* __cdecl _alloca(unsigned int);
#pragma intrinsic(_alloca)
extern "C" void* __cdecl memset(void*, int, unsigned int);
// @fnv 0x0058a9e0
bool BGSCameraPath::Load(TESFile* file)
{
    int chunk;
    if (((CameraFileFormType*)file)->GetTESForm() != 0x5c)
        return false;
    if (this == GetTextureResourcePath())
    {
        struct
        {
            unsigned int index;
            NiFormArray* paths;
        } removalInfo;
        removalInfo.paths = DAT_011ca700->GetPathArray();
        removalInfo.index = removalInfo.paths->GetIndexOfForm(this);
        if (removalInfo.index != 0xffffffff)
        {
            ((NiTLargeArray<TESTopicInfo*, NiTMallocInterface<TESTopicInfo*> >*)removalInfo.paths)
                ->RemoveAt(removalInfo.index);
            removalInfo.paths->Compact();
        }
    }
    LoadRecordHeader(file);
    while ((chunk = file->GetChunkID()) != 0)
    {
        switch (chunk)
        {
        case 0x44494445: {
            char* editorID = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(editorID, 512);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x41544144:
            ((BGSImpactData*)this)->ReadTypedData(file, &data, 1);
            break;
        case 0x41445443:
            ((CameraCondition*)GetConditions())->Load(file);
            break;
        case 0x4d414e53: {
            unsigned int formID = 0;
            file->GetChunkData(&formID);
            ((BSSimpleList<ScriptVariableInfo*>*)&m_kCameraShotList)->AddTail((ScriptVariableInfo*)formID);
            break;
        }
        case 0x4d414e41: {
            FUN_005a71d0 parentInfo;
            memset(&parentInfo, 0, 8);
            file->GetChunkData(&parentInfo, 8);
            if (file->IsEndianConversionRequired())
                parentInfo.TwoValues_Endian();
            m_pFirstCameraPath = (BGSCameraPath*)parentInfo.parent;
            m_pSecondCameraPath = (BGSCameraPath*)parentInfo.previous;
            DAT_011ca700->AddCameraPath(this);
            break;
        }
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

extern "C" const char fnv_MessageMissingParent[];
extern "C" const char fnv_MessageMissingPrevious[];
extern "C" const char fnv_MessageMissingArray[];
// Resolves the parent and previous camera paths by form ID, warns if missing, and inserts this path into the parent's or global path array at the computed index.
// @fnv 0x0058aef0
bool BGSCameraPath::HasMissingPathArray()
{
    struct ParentLocals
    {
        BGSCameraPath* parent;
        unsigned int formID;
        unsigned int index;
        BGSCameraPath* previous;
        NiFormArray* paths;
        char pad0, pad1, pad2;
        bool success;
    } locals;
    locals.success = true;
    locals.parent = 0;
    locals.formID = (unsigned int)m_pFirstCameraPath;
    if (locals.formID)
    {
        TESForm::RemapFormIDForFile(locals.formID, GetFile(-1));
        locals.parent = dynamic_cast<BGSCameraPath*>(TESForm::GetFormByID(locals.formID));
        if (!locals.parent)
        {
            BSStringT<char> name;
            GetDebugName(&name);
            Warning(fnv_MessageMissingParent, locals.formID, name.String());
            locals.success = false;
        }
        AssignParentPath(locals.parent);
    }
    locals.previous = 0;
    locals.formID = (unsigned int)m_pSecondCameraPath;
    if (locals.formID)
    {
        TESForm::RemapFormIDForFile(locals.formID, GetFile(-1));
        locals.previous = dynamic_cast<BGSCameraPath*>(TESForm::GetFormByID(locals.formID));
        if (!locals.previous)
        {
            BSStringT<char> name;
            GetDebugName(&name);
            Warning(fnv_MessageMissingPrevious, locals.formID, name.String());
            locals.success = false;
        }
        ((BGSAcousticSpace*)this)->SetDawnSound((TESSound*)locals.previous);
    }
    locals.index = 0;
    locals.paths = 0;
    if (locals.parent)
        locals.paths = locals.parent->GetEntryObject();
    else
        locals.paths = DAT_011ca700->GetPathArray();
    if (locals.paths)
    {
        if (locals.previous)
        {
            unsigned int previousIndex = locals.paths->GetIndexOfForm(locals.previous);
            if (previousIndex != 0xffffffff)
                ++previousIndex;
            locals.index = previousIndex;
        }
        if (locals.index == 0xffffffff || IsDeleted())
            locals.index = locals.paths->GetSize() + 1;
        locals.paths->SetFormAtIndex(locals.index, this);
        SetPathArray(locals.paths);
    }
    else
    {
        BSStringT<char> name;
        GetDebugName(&name);
        Warning(fnv_MessageMissingArray, name.String());
        locals.success = false;
    }
    return locals.success;
}

// @fnv 0x0058b3f0
NiFormArray::NiFormArray() : NiTLargePrimitiveArray<TESForm*>(0, 1)
{}

// Returns the number of child paths, or 0 if there is no child array.
// @fnv 0x0058b600
unsigned int BGSCameraPath::GetChildCount()
{
    unsigned int result = 0;
    if (m_pPathArray)
        result = m_pPathArray->GetSize();
    return result;
}

// @fnv 0x0058b450
void __fastcall DestroyNiFormArray(NiFormArray* self)
{
    self->NiTLargePrimitiveArray<TESForm*>::~NiTLargePrimitiveArray();
}

// @fnv 0x0058b4f0
bool __thiscall BGSCameraPath::IsFlag2Set()
{
    if (data.cFlags & 2)
        return true;
    return false;
}

// Returns true when the cFlags bit 0x80 is set, otherwise false.
// @fnv 0x0058b470
bool BGSCameraPath::IsFlag80Set()
{
    if (data.cFlags & 0x80)
        return true;
    else
        return false;
}

// Returns true when neither bit 0 nor bit 1 of cFlags is set, otherwise false.
// @fnv 0x0058b4a0
// src: COMMUNITY 0x0058b4a0
bool BGSCameraPath::GetZoomDefault()
{
    if (data.cFlags & 1 || data.cFlags & 2)
        return false;
    return true;
}

// @fnv 0x0058b4d0
// src: COMMUNITY 0x0058b4d0
bool BGSCameraPath::GetZoomDisable()
{
    if (data.cFlags & 1)
        return true;
    return false;
}

struct IdentifierHistoryEntry
{
    unsigned int m_uiCurrentId;
    unsigned int ipreviousID;
};

// TESConditionSave_bgscamerapath: local type (was include/TESConditionSave.h, which had no evidence of one real class); its methods are 0x00680910 TESCondition::Save
class TESConditionSave_bgscamerapath
{
public:
    void ProcessItems();
};
struct BSSimpleList_shell
{
    void** GetItem();
    BSSimpleList_shell* GetNext();
    bool _ref_008256d0();
};

struct FUN_00485e00_shell
{
    void __thiscall TESForm___SaveData(int, int);
};

bool _FUN_00401500();
void _FUN_00485990(unsigned int, void*, unsigned int);
void _FUN_00485910(unsigned int, unsigned int);

// @fnv 0x0058ac10
// src: XBOX_PDB 0x0058ac10
void BGSCameraPath::Save_0058ac10()
{
    BSSimpleList_shell* pShotList;
    IdentifierHistoryEntry ids;

    {
        BGSCameraPath* pprev;
        BGSCameraShot* pshot;
        unsigned int shotFormID;

        TESForm::BeginFormRecord();
        reinterpret_cast<TESConditionSave_bgscamerapath*>(GetConditions())->ProcessItems();

        memset(&ids, 0, 8);

        if (reinterpret_cast<Script*>(this)->GetData())
            ids.m_uiCurrentId = reinterpret_cast<TESForm*>(reinterpret_cast<Script*>(this)->GetData())->GetFormID();

        if (!IsDeleted())
        {
            pprev = GetPrevPath();
            while (pprev && pprev->IsDeleted())
                pprev = pprev->GetPrevPath();

            if (pprev)
                ids.ipreviousID = pprev->GetFormID();
        }

        if (_FUN_00401500())
            reinterpret_cast<FUN_005a71d0*>(&ids)->TwoValues_Endian();

        _FUN_00485990(0x4d414e41, &ids, 8);

        if (_FUN_00401500())
            reinterpret_cast<FUN_005a71d0*>(&ids)->TwoValues_Endian();

        if (_FUN_00401500())
            reinterpret_cast<TESForm*>(&data)->TESForm::ClearData();

        reinterpret_cast<FUN_00485e00_shell*>(this)->TESForm___SaveData(reinterpret_cast<int>(&data), 1);

        if (_FUN_00401500())
            reinterpret_cast<TESForm*>(&data)->TESForm::ClearData();

        pShotList = reinterpret_cast<BSSimpleList_shell*>(reinterpret_cast<TESForm*>(this)->TESForm::GetName());

        while (pShotList && !pShotList->_ref_008256d0())
        {
            pshot = reinterpret_cast<BGSCameraShot*>(pShotList->GetItem()[0]);
            pShotList = pShotList->GetNext();
            shotFormID = pshot->GetFormID();
            _FUN_00485910(0x4d414e53, shotFormID);
        }
    }

    TESForm::FinishFormRecord();
}

void* __cdecl __memcpy(void*, const void*, unsigned int);

struct Cond_58a680
{
    void Copy(PerkEntryConditionSet* src, void* arg);
};

// Casts apForm to BGSCameraPath, copies common data, conditions, data and the shot list into this camera path.
// @fnv 0x0058a680
void BGSCameraPath::CopyFromForm(TESForm* apForm)
{
    BGSCameraPath* p = dynamic_cast<BGSCameraPath*>(apForm);
    if (!p)
        return;
    CopyCommonData(p);
    ((Cond_58a680*)GetConditions())->Copy(p->GetConditions(), 0);
    __memcpy(&data, &p->data, sizeof(CameraShotData));
    BSSimpleList<BGSCameraShot*>* h = 0;
    m_kCameraShotList.RemoveAll();
    h = p->GetShotList();
    while (h && !h->IsEmpty())
    {
        BGSCameraShot* e = h->GetItem();
        h = h->GetNext();
        m_kCameraShotList.AddTail(e);
    }
}

extern "C" int __cdecl memcmp(const void*, const void*, unsigned int);

struct FormCompareStub
{
    bool IsDifferentForm(BGSCameraPath* pathForm);
};
struct ConditionCompareStub
{
    bool IsDifferent(PerkEntryConditionSet* pathForm);
};

// Compares this camera path against another form's camera path: base form, conditions, a data byte, and shot lists; returns true if any differ.
// @fnv 0x0058a750
// src: XBOX_PDB 0x0058a750
bool BGSCameraPath::Compare_0058a750(TESForm* form)
{
    BGSCameraPath* pathForm = dynamic_cast<BGSCameraPath*>(form);
    if (!pathForm)
        return true;
    if (((FormCompareStub*)this)->IsDifferentForm(pathForm))
        return true;
    if (((ConditionCompareStub*)GetConditions())->IsDifferent(pathForm->GetConditions()))
        return true;
    if (memcmp(&data, &pathForm->data, 1))
        return true;
    BSSimpleList<BGSCameraShot*>* pShotNode = GetShotList();
    BSSimpleList<BGSCameraShot*>* pOtherShotNode = pathForm->GetShotList();
    while (pOtherShotNode && !pOtherShotNode->IsEmpty())
    {
        if (!pShotNode || pShotNode->GetItem() != pOtherShotNode->GetItem())
            return true;
        pOtherShotNode = pOtherShotNode->GetNext();
        pShotNode = pShotNode->GetNext();
    }
    if (pShotNode && !pShotNode->IsEmpty())
        return true;
    return false;
}

class DataHandlerStub
{
  public:
    bool IsLoading();
};
extern DataHandlerStub* g_dataHandler;

// Clears data, unlinks the path from its parent or the global path array while not loading, then deletes all children and the child array.
// @fnv 0x0058a450
BGSCameraPath::~BGSCameraPath()
{
    ClearData();
    if (!g_dataHandler->IsLoading())
    {
        if (GetParentPath())
        {
            GetParentPath()->RemoveChild(this);
        }
        else
        {
            NiFormArray* pArray = DAT_011ca700->GetPathArray();
            if (pArray)
            {
                unsigned int uiPathIndex = pArray->GetIndexOfForm(this);
                if (uiPathIndex != -1)
                {
                    BGSCameraPath* pNextPath = (BGSCameraPath*)pArray->GetFormAt(uiPathIndex + 1);
                    if (pNextPath)
                    {
                        pNextPath->SetPrevPathStub(GetPrevPathStub());
                    }
                    ((NiTLargeArray<TESTopicInfo*, NiTMallocInterface<TESTopicInfo*> >*)pArray)->RemoveAt(uiPathIndex);
                    pArray->Compact();
                }
            }
        }
    }
    if (m_pPathArray)
    {
        unsigned int ItemUpdateArray = GetChildCount();
        if (ItemUpdateArray)
        {
            for (unsigned int i = 0; i < ItemUpdateArray; i++)
            {
                BGSCameraPath* pChildPath = GetChildAt(i);
                pChildPath->SetParentStub(0);
                delete pChildPath;
            }
        }
        delete m_pPathArray;
    }
}

struct CameraPathMap
{
    bool GetAt(BGSCameraPath* key, BGSCameraPath*& value);
};

struct CameraPathArrayResize
{
    void Resize(unsigned int size);
};

// Clones the base camera path, remaps its parent and previous paths through apMap, and copies the child form array when present.
// @fnv 0x0058a870
// src: XBOX_PDB 0x0058a870
TESForm* BGSCameraPath::CreateDuplicateForm(bool abPersist, CameraPathMap* apMap)
{
    BGSCameraPath* pClone_ =
        dynamic_cast<BGSCameraPath*>(CreateBaseClone(abPersist, apMap));
    BGSCameraPath* pFound4 = 0;
    if (!apMap->GetAt(m_pFirstCameraPath, pFound4) || !pFound4)
        pFound4 = m_pFirstCameraPath;
    BGSCameraPath* pParent3 = pFound4;
    pClone_->SetParentPath(pParent3);
    pFound4 = 0;
    if (!apMap->GetAt(m_pSecondCameraPath, pFound4) || !pFound4)
        pFound4 = m_pSecondCameraPath;
    BGSCameraPath* pPrev = pFound4;
    pClone_->SetPrevPathForm(pPrev);
    if (m_pPathArray)
    {
        m_pPathArray->Compact();
        unsigned int uiCount5 = m_pPathArray->GetSize();
        NiFormArray* pArray = pClone_->GetEntryObject();
        ((CameraPathArrayResize*)pArray)->Resize(uiCount5);
        TESForm* pLastVal = 0;
        for (unsigned int i5 = 0; i5 < uiCount5; i5++)
        {
            TESForm* pChildA = m_pPathArray->FUN_00877a30(i5);
            TESForm* pNewChildB1 = pChildA->CreateForm((void*)(int)abPersist, apMap);
            unsigned int uiValueC2 = (unsigned int)pNewChildB1;
            pArray->SetSize(i5, &uiValueC2);
            pLastVal = pNewChildB1;
        }
    }
    return pClone_;
}

struct CameraResponse
{
    bool __thiscall FUN_00680c30();
};
struct CameraFlag
{
    bool __thiscall FUN_008256d0();
};

// @fnv 0x0058b510
// src: COMMUNITY 0x0058b510
BGSCameraPath* BGSCameraPath::GetCameraPathToPlay(unsigned int context, unsigned int flags)
{
    BGSCameraPath* result = 0;
    if (!FUN_00440d80())
    {
        if (FUN_00500940(context, flags)->FUN_00680c30())
        {
            if (IsFlag80Set() || !FUN_00891170()->FUN_008256d0())
            {
                result = this;
            }
            unsigned int count = GetChildCount();
            if (count != 0)
            {
                BGSCameraPath* descendant = 0;
                for (unsigned int i = 0; i < count; ++i)
                {
                    BGSCameraPath* child = GetCameraPathAt(i);
                    if (child != 0)
                        descendant = child->GetCameraPathToPlay(context, flags);
                    if (descendant != 0)
                        break;
                }
                if (descendant != 0)
                    result = descendant;
            }
        }
    }
    return result;
}

// Returns the child path array, allocating it if it is null.
// @fnv 0x0058b350
NiFormArray* BGSCameraPath::GetEntryObject()
{
    return m_pPathArray ? m_pPathArray : (m_pPathArray = new NiFormArray);
}
