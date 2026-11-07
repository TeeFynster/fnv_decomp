// fallout/misc/saveload/bgssaveloadgame.cpp: BGSSaveLoadGame and save/load helpers (59 functions)

// TESFile needs the Windows types before layout_support declares their fallbacks.
#include "../../../../include/QUEUED_SUB_BUFFER_TYPE.h"
#include <windows.h>
#undef GetForm
#undef DeleteForm
#undef LoadString
#include "layout_support.h"
#include "../../../../include/NiTPointerMap.h"
#include "../../../../include/TESWorldSpace.h"
#include "../../../../include/Actor.h"
// TESWorldSpace supplies these shared classes; suppress the legacy header copies.
#define FNV_TESFORM_H
#define FNV_BASEFORMCOMPONENT_H
#include "bgssaveloadgame_decls.h"
#include "../../../../include/BGSLoadGameBuffer.h"
#include "../../../../include/BGSSaveLoadChangesMap.h"
#include "../../../../include/BGSLoadFormBuffer.h"
#include "../../../../include/BGSSaveLoadGame.h"
#include "../../../../include/TESSaveLoadGame.h"
#include "../../../../include/TESFile.h"
#include "../../../../include/TESObjectREFR.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/TES.h"
#include "../../../../include/AutoMemContext.h"
#include "../../../../include/BGSSaveGameBuffer.h"
#include "../../../../include/DummyPointerMap.h"
#include "../../../../include/FormChangeMap.h"
#include "../../../../include/IOManager.h"

// @fnv 0x00847570
unsigned char BGSSaveLoadGame::GetLoadState()
{
    return cCurrentMinorVersion;
}
// @fnv 0x00849ce0
bool BGSSaveLoadGame::ContainsReference(unsigned int formID)
{
    return ((NiTPointerMap<unsigned int, TESObjectREFR*>*)this)->GetAt(formID, (TESObjectREFR*&)formID);
}
// @fnv 0x0084a6d0
bool BGSSaveLoadGame::HasFormChangeFlags(TESForm* form, FormChangeMask flags)
{
    return pChangesMap->ContainsChangeFlags(form->GetFormID(), flags);
}
// Returns true if changes are allowed and the form is not temporary; otherwise false.
// @fnv 0x0084a740
bool BGSSaveLoadGame::IsFormChanged(TESForm* form)
{
    if (!GetAllowChanges() || form->IsTemporary())
        return false;
    return true;
}
// @fnv 0x0084a780
void BGSSaveLoadGame::ClearFormChangeFlags(TESForm* form, FormChangeMask flags)
{
    if (!IsFormChanged(form))
        return;
    pChangesMap->ClearChangeFlags(form->GetFormID(), flags);
}
// @fnv 0x0084a690
void BGSSaveLoadGame::NotifyFormIDChanged(TESForm* form, FormChangeMask flags, bool force)
{
    if (!ShouldSaveForm(form, force))
        return;
    pChangesMap->AddFormChangeFlags(form->GetFormID(), flags);
}
// @fnv 0x0084a7c0
void BGSSaveLoadGame::HasFormChanges(TESForm* form)
{
    struct
    {
        unsigned int formID;
        FormChangeRecord* changes;
    } state;
    state.formID = form->GetFormID();
    state.changes = pChangesMap->FUN_009a4250(state.formID);
    if (state.changes && !state.changes->savedFlags.Modelloader_GetReferencedThis())
        pChangesMap->HasFormChanges(state.formID);
}
// @fnv 0x0084a5b0
void BGSSaveLoadGame::ClearFormChanges()
{
    struct
    {
        unsigned int formID;
        Actor* actor;
        void* pos;
    } state;
    state.pos = ((BGSReconstructFormsInAllFilesMap*)((char*)this + 0x34))->GetFirstPos();
    while (state.pos)
    {
        state.formID = 0;
        state.actor = 0;
        ((BGSReconstructFormsInAllFilesMap*)((char*)this + 0x34))
            ->GetNext(state.pos, (TESFile*&)state.formID, (BGSReconstructFormsInFileMap*&)state.actor);
        if (state.actor->GetProcess())
            state.actor->UpdateActorMovementState(true);
    }
    ((NiTPointerMap<unsigned int, unsigned int>*)((char*)this + 0x34))->RemoveAll();
}
// @fnv 0x0084a620
bool BGSSaveLoadGame::ShouldSaveForm(TESForm* form, bool force)
{
    if ((!GetAllowChanges() && !force) || form->IsTemporary())
        return false;
    unsigned int formID = form->GetFormID();
    if (form->IsDeleted() && reinterpret_cast<TESDataHandlerSaveLoad*>(g_dataHandler)->FormIDExists(formID))
        return false;
    return true;
}
// @fnv 0x00849b10
void BGSSaveLoadGame::FormReconstructionMap(TESObjectCELL* cell)
{
    if (BGSSaveLoadGame_GetSaveGameLoading())
        return;
    LoadForm(reinterpret_cast<TESForm*>(cell));
    BGSReconstructFormsInAllFilesMap forms;
    pReferencesMap->LoadCellReferences(cell, &forms);
    SetLoadingMovedRefs_00849c00(true);
    forms.BuildMap();
    SetLoadingMovedRefs_00849c00(false);
    unsigned int iCount = forms.GetCount_00849c80();
    for (unsigned int index = 0; index < iCount; ++index)
    {
        TESForm* form = forms.GetAt_00849ca0(index);
        LoadForm(form);
    }
}

struct BGSSaveFormBuffer;
struct SaveLoadFile;
struct blob4
{
    char b[4];
};
struct FormBufferContext
{
    void Save(SaveLoadFile*, unsigned int, struct blob4);
    void Load(SaveLoadFile*);
    void SetBuffer(char*);
    char* GetBufferData();
    BGSLoadFormBuffer* CreateFormBuffer();
    void Initialize(char*, unsigned int, int, unsigned char);
    void Initialize(BGSSaveFormBuffer*);
    int GetFormType();
    int GetSizeType();
    unsigned char GetVersion();
    unsigned int GetSize();
    unsigned int GetFormIdentifier();
    void ReleaseBuffer();
    void ResetReadPosition();
    char* pBuffer;
};
typedef char _sizecheck_BGSUnloadedFormBuffer[sizeof(FormBufferContext) == 4 ? 1 : -1];
struct FUN_006665a0_shell : public FormBufferContext
{
    void ClearBuffer_006665a0();
};

// @fnv 0x006665a0
// src: GUESS 0x006665a0 (confidence: medium)
void FUN_006665a0_shell::ClearBuffer_006665a0()
{
    pBuffer = 0;
}

void* __cdecl memset(void*, int, unsigned int);

// @fnv 0x00847d50
void* __fastcall ClearObject(void* apObject)
{
    memset(apObject, 0, 0x6e);
    return apObject;
}


// @fnv 0x00848ca0
void BGSSaveLoadGame::SetDeferInitForms(bool abValue)
{
    if (abValue)
        iGlobalFlags |= 2;
    else
        iGlobalFlags &= ~2;
}


// @fnv 0x00848dd0
// src: COMMUNITY 0x00848dd0
bool BGSLoadFormBuffer::GetSkipForm_00848dd0()
{
    return (iFlags & 1) ? true : false;
}

struct FUN_00848df0_shell : public TESDataHandler
{
    void TESDataHandler_SetDontRemoveIDs(bool);
};

// @fnv 0x00848df0
// src: COMMUNITY 0x00848df0
void FUN_00848df0_shell::TESDataHandler_SetDontRemoveIDs(bool abValue)
{
    *((bool*)((char*)this + 0x621)) = abValue;
}


// @fnv 0x00849540
void BGSSaveLoadGame::SetInitingForms(bool abValue)
{
    if (abValue)
        iGlobalFlags |= 8;
    else
        iGlobalFlags &= ~8;
}

// @fnv 0x00849590
// src: COMMUNITY 0x00849590
bool __fastcall BGSLoadFormBuffer_GetCellChanged(int pObject)
{
    return (*(unsigned int*)(pObject + 0x28) & 0x10) ? true : false;
}

// @fnv 0x008495b0
// src: XBOX_PDB 0x008495b0
void __fastcall IOManager_ForceHighestPriority(char* pThis)
{
    *reinterpret_cast<int*>(pThis + 0x68) = 5;
}


struct TLSData_00849c00
{
    char pad[0x294];
    unsigned int uiFlags;
};

static __declspec(thread) TLSData_00849c00 g_tlsData_00849c00;

// @fnv 0x00849c00
// src: COMMUNITY 0x00849c00
void BGSSaveLoadGame::SetLoadingMovedRefs_00849c00(bool abValue)
{
    if (abValue)
        g_tlsData_00849c00.uiFlags |= 2;
    else
        g_tlsData_00849c00.uiFlags &= ~2;
}


// @fnv 0x00849c80
// src: COMMUNITY 0x00849c80
unsigned int BGSReconstructFormsInAllFilesMap::GetCount_00849c80()
{
    return ((FormChangeMap*)((char*)this + 0x10))->GetCombinedFlags();
}

struct ST_00849cc0
{
    char pad[0x10];
    BGSSaveLoadGame* pGame;
    bool BGSSaveLoadGame_HasReferenceChangedCells(unsigned int id);
};
// @fnv 0x00849cc0
// src: COMMUNITY 0x00849cc0
bool ST_00849cc0::BGSSaveLoadGame_HasReferenceChangedCells(unsigned int id)
{
    return pGame->ContainsReference(id);
}


// Removes the actor's form ID from the pointer map at offset 0x34 of this object.
// @fnv 0x0084a580
void BGSSaveLoadGame::RemoveActorFromMap(TESObjectREFR* apActor)
{
    reinterpret_cast<NiTPointerMap<unsigned int, void*>*>(reinterpret_cast<char*>(this) + 0x34)
        ->RemoveAt(reinterpret_cast<TESForm*>(apActor)->GetFormID());
}

class NiMatrix3;
class NiQuaternion;
class hkVector4;
namespace fnv_0084a810 {
struct SaveLoadFile;
struct blob4
{
    char b[4];
};

typedef char _sizecheck_BGSLoadGameBuffer[sizeof(BGSLoadGameBuffer) == 16 ? 1 : -1];
typedef char _sizecheck_BGSLoadFormBuffer[sizeof(BGSLoadFormBuffer) == 48 ? 1 : -1];

struct LoadGameSubBufferQueue
{
    void ProcessSubBuffer(QUEUED_SUB_BUFFER_TYPE, BGSLoadFormBuffer*, TESForm*);
};
}  // namespace fnv_0084a810

// @fnv 0x0084a810
// src: XBOX_PDB 0x0084a810
void BGSSaveLoadGame::QueueSubBuffer(int type, BGSLoadFormBuffer* buffer, int form)
{
    (*(fnv_0084a810::LoadGameSubBufferQueue**)((char*)this + 0x14))->ProcessSubBuffer((QUEUED_SUB_BUFFER_TYPE)type, buffer, (TESForm*)form);
}


int __fastcall BGSSaveLoadFormInfo_GetFormType(void* pThis);

// @fnv 0x008665b0
// src: COMMUNITY 0x008665b0
unsigned int BGSLoadFormBuffer::GetFormType_008665b0()
{
    return BGSSaveLoadFormInfo_GetFormType((char*)this + 0x1b);
}

void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_00847450(unsigned int flags);
};
// Calls the destructor, frees this when flags has bit 0 set, and returns this.
// @fnv 0x00847450
void* DelStandIn::FUN_00847450(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}

class BSFile;
class NiMatrix3;
class NiQuaternion;
class hkVector4;
namespace fnv_00849d00 {
struct blob4
{
    char b[4];
};
struct SaveLoadFile
{
    unsigned int Read(void*, unsigned int);
    unsigned int Write(void*, unsigned int);
    bool Open();
    unsigned int GetFilePosition();
    unsigned int GetFileSize();
    void SetFilePosition(int);
    void SeekCurrent(int);
    char* GetFileName();
    static SaveLoadFile* CreateFileA(char*, bool, unsigned int);
    void SetSaveFileName(char*);
    char* GetSaveFileName();
    BSFile* QFile();
    unsigned int GetSimulatedFileSize();
    void* __vecDelDtor(unsigned int);
    char m_cFileName[260];
    BSFile* pFile;
    unsigned int m_uiBufferSize;
    unsigned int m_uiFilePosition;
};
typedef char _sizecheck_BGSSaveLoadFile[sizeof(SaveLoadFile) == 272 ? 1 : -1];

typedef char _sizecheck_BGSLoadGameBuffer[sizeof(BGSLoadGameBuffer) == 16 ? 1 : -1];
typedef char _sizecheck_BGSLoadFormBuffer[sizeof(BGSLoadFormBuffer) == 48 ? 1 : -1];
struct FormIDConverter
{
    void Clear();
    unsigned int RegisterFormID(unsigned int);
    unsigned int GetFormID(unsigned int);
    unsigned int ConvertFormID(unsigned int);
    unsigned int ReverseConvertFormID(unsigned int);
    void Save(SaveLoadFile*);
    void Load(SaveLoadFile*);
    void* __vecDelDtor(unsigned int);
    char m_kSourceToTargetFormIDMap[16];
    char m_kTargetToSourceFormIDMap[16];
    unsigned int m_uiFormIDCount;
};
typedef char _sizecheck_BGSSaveLoadFormIDMap[sizeof(FormIDConverter) == 36 ? 1 : -1];


struct ChangeFlagsT
{
    unsigned int iFlags;
    ChangeFlagsT(int flags);
    unsigned int Modelloader_GetReferencedThis();
    static ChangeFlagsT HasFormChanged(FormChangeMask oldFlags, FormChangeMask newFlags, int formType, bool forced);
};
struct FormBufferContext
{
    void* pData;
    FormBufferContext();
    void* Modelloader_GetReferencedThis();
    void* BGSUnloadedFormBuffer_GetAdvancedBuffer();
};
// The classifier at 0x0084e730 is also bound as a free function by TESObjectREFR; it needs no object.
int __cdecl DetermineInitialDataType(unsigned int formID, int formType, FormChangeMask changeFlags);
struct ReferencePlacementData
{
    unsigned int iLocationFormID;
    unsigned int iBaseFormID;
    unsigned int iUnk08;
    int m_iGridPositionX;
    int m_iGridCoordinateY;
    NiPoint3 kTargetPoint;
    NiPoint3 kAngle;
    unsigned char cFlags;
    ReferencePlacementData();
    bool GetCellAndWorld(TESObjectCELL*& cell, TESWorldSpace*& world);
    void ReferenceInitialData_GetOriginalLocationCellAndWorld(TESObjectCELL*& cell, TESWorldSpace*& world);
};
struct TESFormH
{
    int GetFormType();
};
struct TESObjectCELLH
{
    bool IsInterior();
    void RemoveReference(TESObjectREFR* ref);
};


extern TES* g_TES;
extern TESObjectREFR* g_thePlayer;
// The legacy flag constructor must build directly in the argument slot.
// The shared buffer declares only the FormChangeMask overload.
struct LoadFormBufferLegacyFlags
{
    void SetChangeFlags(ChangeFlagsT flags);
};
// Buffer-returning access is not declared by the shared changes map.
struct SaveLoadChangesMapBufferAccess : BGSSaveLoadChangesMap
{
    FormBufferContext BGSSaveLoadChangesMap_GetChangeBuffer(unsigned int formID);
};
struct ReferencesMapH
{
    void ForwardToMember(unsigned int locationID, unsigned int formID);
    void SetAtKey(unsigned int formID);
    void AddReferenceToCell(unsigned int locationID, unsigned int formID, NiPoint3* location);
};
struct ReconstructFormsH
{
    void BGSReconstructFormsInAllFilesMap_AddReference(TESObjectCELL* cell, unsigned int formID, bool unk);
    void BGSReconstructFormsInAllFilesMap_AddReference_008438b0(TESWorldSpace* world, int x, int y, unsigned int formID, bool unk);
};
unsigned int __cdecl BGSSaveLoadInitialData_LoadInitialDataStruct_0(SaveLoadFile* file, int type, ReferencePlacementData* data);
TESForm* __cdecl ResolveReferenceForm(unsigned int formID, ReferencePlacementData* data, TESForm* form);
int __cdecl BGSSaveLoadInitialData_LoadInitialDataStruct(void* buffer, int type, ReferencePlacementData* data);
void __cdecl LogWarning(const char* format, ...);

}  // namespace fnv_00849d00

// @fnv 0x00849d00
unsigned int BGSSaveLoadGame::LoadFormRecord(::SaveLoadFile* apFile, BGSLoadFormBuffer* apLoadGameBuffer,
                                               ::FormIDConverter* apOldFormIDMap)
{
    using namespace fnv_00849d00;
    unsigned int idataSizeLoaded = 0;
    int eformType = apLoadGameBuffer->GetFormType_008665b0();
    FormChangeMask ichangeFlags = apLoadGameBuffer->GetChangeFlags();
    FormChangeMask ioldChangeFlags = apLoadGameBuffer->GetOldChangeFlags();
    unsigned int iformID = apLoadGameBuffer->TESMain_GetThread();
    TESForm* pform = apLoadGameBuffer->GetForm();
    int einitialDataType = DetermineInitialDataType(iformID, eformType, ichangeFlags);
    if (einitialDataType == 5 || einitialDataType == 6)
    {
        TESObjectCELL* pcell;
        ReferencePlacementData refData;
        idataSizeLoaded = BGSSaveLoadInitialData_LoadInitialDataStruct_0((fnv_00849d00::SaveLoadFile*)apFile, einitialDataType, &refData);
        TESObjectREFR* pref = 0;
        if (pform)
        {
            bool bclearForm = false;
            if (!((TESObjectREFR*)pform)->GetIsReference())
            {
                if (einitialDataType == 5)
                    bclearForm = true;
            }
            else
            {
                pref = (TESObjectREFR*)pform;
                if (einitialDataType == 5 && reinterpret_cast<TESForm*>(pref->GetObjectReference())->GetFormID() != refData.iBaseFormID)
                    bclearForm = true;
            }
            if (bclearForm)
            {
                ClearForm(pform);
                apLoadGameBuffer->SetForm(0);
                ((LoadFormBufferLegacyFlags*)apLoadGameBuffer)->SetChangeFlags(0);
                pform = 0;
                pref = 0;
            }
        }
        pcell = 0;
        TESWorldSpace* pworld = 0;
        refData.GetCellAndWorld(pcell, pworld);
        if ((pcell && g_TES->IsCellBuffered(pcell, false)) || (refData.cFlags & 2))
        {
            if (einitialDataType == 5)
            {
                if (pform)
                {
                    ChangeFlagsT iunrevertibleChanges =
                        ChangeFlagsT::HasFormChanged(ioldChangeFlags, ichangeFlags, eformType, true);
                    if (iunrevertibleChanges.Modelloader_GetReferencedThis())
                    {
                        DeleteForm(pform);
                        pform = 0;
                        ((LoadFormBufferLegacyFlags*)apLoadGameBuffer)->SetChangeFlags(0);
                    }
                }
                pform = ResolveReferenceForm(iformID, &refData, pform);
                if (pform)
                    apLoadGameBuffer->SetForm(pform);
                else
                    apLoadGameBuffer->SetSkipForm_00848d90(true);
            }
            else if (einitialDataType == 6 && !pform)
            {
                refData.ReferenceInitialData_GetOriginalLocationCellAndWorld(pcell, pworld);
                if (pcell)
                    (*(ReconstructFormsH**)((char*)this + 0x20))->BGSReconstructFormsInAllFilesMap_AddReference(pcell, iformID, false);
                else
                    (*(ReconstructFormsH**)((char*)this + 0x20))
                        ->BGSReconstructFormsInAllFilesMap_AddReference_008438b0(pworld, refData.m_iGridPositionX, refData.m_iGridCoordinateY, iformID, false);
                apLoadGameBuffer->FUN_0042ce50(true);
                apLoadGameBuffer->SetFormPending(true);
            }
        }
        else if (!pref || (!pref->GetReferencePersistence() && pref != g_thePlayer))
        {
            if (pcell && ((TESObjectCELLH*)pcell)->IsInterior())
            {
                ((ReferencesMapH*)pReferencesMap)->ForwardToMember(refData.iLocationFormID, iformID);
                if (einitialDataType == 6)
                    ((ReferencesMapH*)pReferencesMap)->SetAtKey(iformID);
            }
            else if (pworld)
            {
                ((ReferencesMapH*)pReferencesMap)
                    ->AddReferenceToCell(refData.iLocationFormID, iformID, &refData.kTargetPoint);
                if (einitialDataType == 6)
                    ((ReferencesMapH*)pReferencesMap)->SetAtKey(iformID);
            }
            else
            {
                LogWarning(
                    "CELLS: Worldspace or Cell %08X could not be found while loading a %s reference.  Its loading will be skipped.",
                    refData.iLocationFormID, einitialDataType == 5 ? "created" : "moved");
                apLoadGameBuffer->SetSkipForm_00848d90(true);
            }
            if (pref)
            {
                if (pref->GetParentCell())
                    ((TESObjectCELLH*)pref->GetParentCell())->RemoveReference(pref);
                DeleteForm(pform);
                pform = 0;
                apLoadGameBuffer->SetForm(0);
            }
        }
    }
    else
    {
        int eoldInitialDataType =
            DetermineInitialDataType(iformID, eformType, ioldChangeFlags);
        if (eoldInitialDataType == 6)
        {
            if (!pform)
            {
                fnv_00849d00::FormBufferContext unloadedFormBuffer = ((SaveLoadChangesMapBufferAccess*)pChangesMap)->BGSSaveLoadChangesMap_GetChangeBuffer(iformID);
                if (unloadedFormBuffer.Modelloader_GetReferencedThis())
                {
                    ::FormIDConverter* pcurrentFormIDMap = (::FormIDConverter*)pFormIDMap;
                    pFormIDMap = (BGSSaveLoadFormIDMap*)apOldFormIDMap;
                    ReferencePlacementData refData;
                    BGSSaveLoadInitialData_LoadInitialDataStruct(unloadedFormBuffer.BGSUnloadedFormBuffer_GetAdvancedBuffer(), eoldInitialDataType, &refData);
                    TESObjectCELL* pcell = 0;
                    TESWorldSpace* pworld = 0;
                    refData.ReferenceInitialData_GetOriginalLocationCellAndWorld(pcell, pworld);
                    if (pcell && g_TES->IsCellBuffered(pcell, false))
                    {
                        (*(ReconstructFormsH**)((char*)this + 0x20))->BGSReconstructFormsInAllFilesMap_AddReference(pcell, iformID, false);
                        apLoadGameBuffer->FUN_0042ce50(true);
                        apLoadGameBuffer->SetFormPending(true);
                    }
                    pFormIDMap = (BGSSaveLoadFormIDMap*)pcurrentFormIDMap;
                }
            }
            else if (((TESObjectREFR*)pform)->GetIsReference())
            {
                TESObjectREFR* pref = (TESObjectREFR*)pform;
                if (!pref->GetReferencePersistence())
                {
                    TESForm* pspace = 0;
                    NiPoint3 loc = NiPoint3::ZERO;
                    NiPoint3 angle = NiPoint3::ZERO;
                    bool bdeleteRef = false;
                    if (!pref->GetStartingPosition(&loc, &angle, &pspace, 0))
                    {
                        bdeleteRef = true;
                    }
                    else
                    {
                        TESObjectCELL* pcell = 0;
                        if (((TESFormH*)pspace)->GetFormType() == 0x41)
                        {
                            TESWorldSpace* pworld = (TESWorldSpace*)pspace;
                            pcell = pworld->GetCellByWorldPosition(loc);
                        }
                        else
                        {
                            pcell = (TESObjectCELL*)pspace;
                        }
                        if (!pcell || !g_TES->IsCellBuffered(pcell, false))
                            bdeleteRef = true;
                    }
                    if (bdeleteRef)
                    {
                        DeleteForm(pform);
                        apLoadGameBuffer->SetForm(0);
                        ((LoadFormBufferLegacyFlags*)apLoadGameBuffer)->SetChangeFlags(0);
                        pform = 0;
                    }
                }
            }
        }
    }
    return idataSizeLoaded;
}


// @fnv 0x00847d00
void BGSSaveLoadGame::SetSaveGameSaving(bool set)
{
    if (set)
        iGlobalFlags |= 4;
    else
        iGlobalFlags &= ~4;
}


// Sets or clears bit 0 of iFlags according to value.
// @fnv 0x00848d90
// src: COMMUNITY 0x00848d90
void __thiscall BGSLoadFormBuffer::SetSkipForm_00848d90(bool abSet)
{
    if (abSet)
        iFlags |= 1;
    else
        iFlags &= ~1;
}

void* __cdecl operator new(unsigned int);
// The shared game has no ordinary destructor declaration. This API-only view
// preserves its destruction calls without duplicating the game layout.
struct SaveLoadGameMemberDestruction
{
    void DestroyMembers();
    void* Delete(unsigned int flags);
};

extern BGSSaveLoadGame* g_BGSSaveLoadGame;
void __cdecl BGSSaveLoadFormInfo_InitSaveGameFormTypes();


// Allocates a new BGSSaveLoadGame instance, stores it in g_BGSSaveLoadGame, then calls FUN_008535e0.
// @fnv 0x00847480
void BGSSaveLoadGame::Create()
{
    g_BGSSaveLoadGame = new BGSSaveLoadGame;
    BGSSaveLoadFormInfo_InitSaveGameFormTypes();
}

extern BGSSaveLoadGame* g_BGSSaveLoadGame;


// Calls FUN_00847540(1) on g_BGSSaveLoadGame if set, then clears g_BGSSaveLoadGame to null.
// @fnv 0x00847500
void BGSSaveLoadGame::Destroy()
{
    BGSSaveLoadGame* local2 = g_BGSSaveLoadGame;
    BGSSaveLoadGame* local_c = local2;
    BGSSaveLoadGame* local_4;
    if (local_c)
    {
        local_4 = (BGSSaveLoadGame*)((SaveLoadGameMemberDestruction*)local_c)->Delete(1);
    }
    else
    {
        local_4 = 0;
    }
    g_BGSSaveLoadGame = 0;
}


// File-list helpers are absent from the shared API; this extension adds no layout.
class SaveLoadGameFileLists : public BGSSaveLoadGame
{
public:
    void SaveCompiledFileList(void*);
    bool ReadFileIndexMap(void*);
};

// @fnv 0x00847590
void SaveLoadGameFileLists::SaveCompiledFileList(void* apFile)
{
    BGSSaveGameBuffer buffer;
    BGSSaveGameBuffer* pbuffer = &buffer;
    unsigned char ucFileCount = reinterpret_cast<TESDataHandlerSaveLoad*>(g_dataHandler)->GetCompiledFileCount();
    pbuffer->SaveData(&ucFileCount, 1, 0);
    for (unsigned int i = 0; i < ucFileCount; ++i)
    {
        TESFile* pFile = reinterpret_cast<TESDataHandlerSaveLoad*>(g_dataHandler)->GetCompiledFileByIndex(i);
        const char* pFileName = pFile->GetName();
        pbuffer->SaveGameString(pFileName, 0);
    }
    buffer.FUN_00865c40(apFile);
}


struct FormChangeMapElements
{
    TESForm* GetElementAt(unsigned int);
};

// @fnv 0x00849ca0
// src: COMMUNITY 0x00849ca0
TESForm* BGSReconstructFormsInAllFilesMap::GetAt_00849ca0(unsigned int state)
{
    return ((FormChangeMapElements*)((char*)this + 0x10))->GetElementAt(state);
}

extern TESSaveLoadGame* g_TESSaveLoadGame;
// @fnv 0x0049ab00
void __cdecl ReadAndDispatchSaveData(void* apData)
{
    unsigned short s;
    g_TESSaveLoadGame->ReadTypedData(&s, 2);
    if (s)
        g_TESSaveLoadGame->TESSaveLoadGame_QueueAnimationLoad(apData, s);
}

void _Deallocate(void*);
// Calls DestroyMembers on this, frees this with _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x00847540
void* SaveLoadGameMemberDestruction::Delete(unsigned int flags)
{
    DestroyMembers();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct CF845
{
    int field0;
    CF845(int);
    CF845 BGSChangeFlags_GetDifference(int);
};
// @fnv 0x00847cd0
// src: COMMUNITY 0x00847cd0
CF845 CF845::BGSChangeFlags_GetDifference(int a)
{
    return CF845(~a & field0);
}

struct S00852950
{
    void GetOrCreateEntryAdd(int, int);
};
struct S00849a70
{
    int _pad[4];
    S00852950 _m;
    void ForwardToMember(int, int);
};
// Calls GetOrCreateEntryAdd on the member _m, forwarding both integer arguments.
// @fnv 0x00849a70
void S00849a70::ForwardToMember(int aiFirst, int aiSecond)
{
    _m.GetOrCreateEntryAdd(aiFirst, aiSecond);
}

// If the changes map is set, checks whether it records a change for the form's FormID with the given value; otherwise returns false.
// @fnv 0x0084a700
bool BGSSaveLoadGame::GetOldChange(TESForm* pForm, FormChangeMask b)
{
    if (pOldChangesMap != 0)
        return pOldChangesMap->ContainsChangeFlags(pForm->GetFormID(), b);
    return 0;
}

namespace fnv_0084a840 {
void __cdecl BGSSaveLoadHistory_Destroy(unsigned char);
}  // namespace fnv_0084a840

// @fnv 0x0084a840
void BGSSaveLoadGame::ClearAllForms()
{
    SetDeferInitForms(true);
    fnv_0084a840::BGSSaveLoadHistory_Destroy(1);
    RevertCurrentChanges(0, 0);
    ClearFormChanges();
    SetDeferInitForms(false);
}


void* __cdecl _GetFormByNumericID(unsigned int);
// Resolves the form for the given numeric ID and forwards it to FUN_0084a880 on this object.
// @fnv 0x0084a9c0
void BGSSaveLoadGame::ClearFormID(unsigned int a1)
{
    ClearForm((TESForm*)_GetFormByNumericID(a1));
}

struct FormDeletionInterface
{
    virtual int v0();
    virtual int v1();
    virtual int v2();
    virtual int v3();
    virtual int Delete(int);
};

// Deletes the passed form if it is non-null.
// @fnv 0x0084a9f0
void BGSSaveLoadGame::DeleteForm(TESForm* apObject)
{
    FormDeletionInterface* b = (FormDeletionInterface*)apObject;
    FormDeletionInterface* a = b;
    a ? a->Delete(1) : 0;
}

struct SaveLoadChangeHistory
{
    void AddNoteWithArguments(char const*, char*);
};
// @fnv 0x0084ab00
// src: XBOX_PDB 0x0084ab00
void BGSSaveLoadGame::SaveGameWarningFunction(const char* apText, char* aList)
{
    ((SaveLoadChangeHistory*)pHistory)->AddNoteWithArguments(apText, aList);
}

struct FUN_0084ba20
{
    virtual ~FUN_0084ba20();
};
struct FUN_0084b9c0 : public FUN_0084ba20
{
    virtual ~FUN_0084b9c0();
};
// Destructor that clears all entries from the object's pointer map via RemoveAll.
// @fnv 0x0084b9c0
FUN_0084b9c0::~FUN_0084b9c0()
{
    ((NiTPointerMap<unsigned int, unsigned int>*)this)->RemoveAll();
}

// The shared changes map does not declare this identity-key helper.
struct SaveLoadChangesMapKeyAccess : BGSSaveLoadChangesMap
{
    void SetAtKey(unsigned int key);
};

// @fnv 0x00849a50
void SaveLoadChangesMapKeyAccess::SetAtKey(unsigned int key)
{
    ((NiTPointerMap<unsigned int, FormChangeRecord*>*)this)->SetAt(key, (FormChangeRecord*)key);
}


// @fnv 0x0084a360
void BGSLoadFormBuffer::SetFormPending(bool abSet)
{
    if (abSet)
        iFlags |= 2;
    else
        iFlags &= ~2;
}

void __cdecl _fnv_call_845cc0(const char*, ...);
// @fnv 0x0084aa30
void BGSSaveLoadGame::ChangeFormID(unsigned int aiOldFormID, unsigned int aiNewFormID)
{
    unsigned int uiExistingFormID = 0;
    if (((DummyPointerMap*)pChangedFormIDMap)->GetAt(aiOldFormID, uiExistingFormID))
        _fnv_call_845cc0(
            "FORMS: Trying to set new form ID %08X for old form ID %08X, but already in map with value %08X",
            aiNewFormID, aiOldFormID, uiExistingFormID);
    ((DummyPointerMap*)pChangedFormIDMap)->SetAt(aiOldFormID, aiNewFormID);
}


struct UnloadFlags
{
    unsigned int flags;
    UnloadFlags(unsigned int auiFlags);
    unsigned int Modelloader_GetReferencedThis() const;
    UnloadFlags BGSChangeFlags_GetDifference(unsigned int auiFlags);
};

struct UnloadFormBuffer
{
    void* vtbl;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    UnloadFormBuffer();
    ~UnloadFormBuffer();
    void InitFormEntry(unsigned int auiFormID, UnloadFlags aFlags, int aiFormType, int aiVersion);
    void FUN_0050f9c0(TESForm* apForm);
    UnloadFlags FUN_00428110();
};

struct UnloadChangeData
{
    UnloadFlags flags;
    void InitFromInput(UnloadFormBuffer* apBuffer);
    unsigned int Modelloader_GetReferencedThis() const;
};

struct UnloadChanges
{
    UnloadFlags flags;
    UnloadChangeData data;
};


struct UnloadRefsMap
{
    void ForwardToMember(unsigned int auiCellID, unsigned int auiFormID);
    void SetAtKey(unsigned int auiFormID);
    void AddReferenceToCell(unsigned int auiWorldID, unsigned int auiFormID, const NiPoint3& arPos);
};

struct UnloadManager
{
    int GetConstant27();
};
extern UnloadManager* DAT_011de134;

bool __fastcall TESDataHandler_GetClearingData(TESDataHandler*);
void __cdecl SaveGameWarning(const char*, ...);
int __fastcall FNV_GetFormType(TESForm*);
int __cdecl BGSSaveLoadInitialData_SaveInitialData(UnloadFormBuffer*, TESForm*, UnloadFlags);
TESWorldSpace* __fastcall TESObjectREFR_GetWorldSpace(TESObjectREFR*);
bool __fastcall FUN_00425fd0(TESObjectCELL*);

// The shared FUN_00849730 takes int; this unit needs its original bool ABI.
struct SaveLoadGameUnloading : public BGSSaveLoadGame
{
    void UnloadForm(TESForm* apForm, bool abForce);
};

// Unloads a form into an UnloadFormBuffer, updates its change data, and records reference cell/worldspace info for reference forms.
// @fnv 0x00849730
void SaveLoadGameUnloading::UnloadForm(TESForm* apForm, bool abForce)
{
    AutoMemContext m_uiMemoryContext(
        MEM_CONTEXT_MEM_CONTEXT_SAVELOAD, true,
        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Misc\\SaveLoad\\BGSSaveLoadGame.cpp", 894);
    if (BGSSaveLoadGame_GetSaveGameLoading() && !abForce)
        return;
    if (TESDataHandler_GetClearingData(g_dataHandler))
        return;
    if (!ShouldUnloadForm(apForm))
        return;

    unsigned int auiFormId = apForm->GetFormID();
    UnloadChanges* changes = (UnloadChanges*)pChangesMap->FUN_009a4250(auiFormId);
    if (changes)
    {
        if (changes->data.Modelloader_GetReferencedThis())
        {
            SaveGameWarning(
                "FORMS: Form '%s' (%08X) is unloading, but it already has a buffer.  This unload will be skipped.",
                apForm->GetName(), auiFormId);
            return;
        }

        UnloadFormBuffer buffer;
        buffer.InitFormEntry(auiFormId, changes->flags, FNV_GetFormType(apForm), DAT_011de134->GetConstant27());
        buffer.FUN_0050f9c0(apForm);
        apForm->Unk_20(&buffer);
        UnloadFlags remainingFlags = changes->flags.BGSChangeFlags_GetDifference(buffer.FUN_00428110().Modelloader_GetReferencedThis());
        if (remainingFlags.Modelloader_GetReferencedThis() &&
            pChangesMap->ClearChangeFlags(auiFormId, reinterpret_cast<FormChangeMask&>(remainingFlags)))
            return;

        int type = BGSSaveLoadInitialData_SaveInitialData(&buffer, apForm, changes->flags);
        apForm->SaveGame(reinterpret_cast<BGSSaveFormBuffer*>(&buffer));
        changes->data.InitFromInput(&buffer);
        if (type == 5 || type == 6)
        {
            TESObjectREFR* ref = (TESObjectREFR*)apForm;
            TESObjectCELL* cell = ref->GetParentCell();
            TESWorldSpace* world = TESObjectREFR_GetWorldSpace(ref);
            if (cell && FUN_00425fd0(cell))
            {
                ((UnloadRefsMap*)pReferencesMap)->ForwardToMember(((TESForm*)cell)->GetFormID(), auiFormId);
                if (type == 6)
                    ((UnloadRefsMap*)pReferencesMap)->SetAtKey(auiFormId);
            }
            else if (world)
            {
                ((UnloadRefsMap*)pReferencesMap)->AddReferenceToCell(world->GetFormID(), auiFormId, *static_cast<const TESObjectREFR*>(ref)->GetPos());
                if (type == 6)
                    ((UnloadRefsMap*)pReferencesMap)->SetAtKey(auiFormId);
            }
            else
            {
                SaveGameWarning("FORMS: No Worldspace or Cell could not be found while unloading reference '%s' (%08X)",
                             ref->GetName(), auiFormId);
            }
        }
    }
}

class FUN_00849a90_Iface
{
  public:
    virtual unsigned char vSlot000();
    virtual unsigned char vSlot001();
    virtual unsigned char vSlot002();
    virtual unsigned char vSlot003();
    virtual unsigned char vSlot004();
    virtual unsigned char vSlot005();
    virtual unsigned char vSlot006();
    virtual unsigned char vSlot007();
    virtual unsigned char vSlot008();
    virtual unsigned char vSlot009();
    virtual unsigned char vSlot010();
    virtual unsigned char vSlot011();
    virtual unsigned char vSlot012();
    virtual unsigned char vSlot013();
    virtual unsigned char vSlot014();
    virtual unsigned char vSlot015();
    virtual unsigned char vSlot016();
    virtual unsigned char vSlot017();
    virtual unsigned char vSlot018();
    virtual unsigned char vSlot019();
    virtual unsigned char vSlot020();
    virtual unsigned char vSlot021();
    virtual unsigned char vSlot022();
    virtual unsigned char vSlot023();
    virtual unsigned char vSlot024();
    virtual unsigned char vSlot025();
    virtual unsigned char vSlot026();
    virtual unsigned char vSlot027();
    virtual unsigned char vSlot028();
    virtual unsigned char vSlot029();
    virtual unsigned char vSlot030();
    virtual unsigned char vSlot031();
    virtual unsigned char vSlot032();
    virtual unsigned char vSlot033();
    virtual unsigned char vSlot034();
    virtual unsigned char vSlot035();
    virtual unsigned char vSlot036();
    virtual unsigned char vSlot037();
    virtual unsigned char vSlot038();
    virtual unsigned char vSlot039();
    virtual unsigned char vSlot040();
    virtual unsigned char vSlot041();
    virtual unsigned char vSlot042();
    virtual unsigned char vSlot043();
    virtual unsigned char vSlot044();
    virtual unsigned char vSlot045();
    virtual unsigned char vSlot046();
    virtual unsigned char vSlot047();
    virtual unsigned char vSlot048();
    virtual unsigned char vSlot049();
    virtual unsigned char vSlot050();
    virtual unsigned char vSlot051();
    virtual unsigned char vSlot052();
    virtual unsigned char vSlot053();
    virtual unsigned char vSlot054();
    virtual unsigned char vSlot055();
    virtual unsigned char vSlot056();
    virtual unsigned char vSlot057();
    virtual unsigned char vSlot058();
    virtual unsigned char vSlot059();
    virtual unsigned char vSlot060();
    virtual unsigned char vSlot061();
    virtual unsigned char vSlot062();
    virtual unsigned char vSlot063();
    virtual unsigned char vSlot064();
    virtual unsigned char vSlot065();
    virtual unsigned char vSlot066();
    virtual unsigned char vSlot067();
    virtual unsigned char vSlot068();
    virtual unsigned char vSlot069();
    virtual unsigned char vSlot070();
    virtual unsigned char vSlot071();
    virtual unsigned char vSlot072();
    virtual unsigned char vSlot073();
    virtual unsigned char vSlot074();
    virtual unsigned char vSlot075();
    virtual unsigned char vSlot076();
    virtual unsigned char vSlot077();
    virtual unsigned char vSlot078();
    virtual unsigned char vSlot079();
    virtual unsigned char vSlot080();
    virtual unsigned char vSlot081();
    virtual unsigned char vSlot082();
    virtual unsigned char vSlot083();
    virtual unsigned char vSlot084();
    virtual unsigned char vSlot085();
    virtual unsigned char vSlot086();
    virtual unsigned char vSlot087();
    virtual unsigned char vSlot088();
    virtual unsigned char vSlot089();
    virtual unsigned char vSlot090();
    virtual unsigned char vSlot091();
    virtual unsigned char vSlot092();
    virtual unsigned char vSlot093();
    virtual unsigned char vSlot094();
    virtual unsigned char vSlot095();
    virtual unsigned char vSlot096();
    virtual unsigned char vSlot097();
    virtual unsigned char vSlot098();
    virtual unsigned char vSlot099();
    virtual unsigned char vSlot100();
    virtual unsigned char vSlot101();
    virtual unsigned char vSlot102();
    virtual unsigned char vSlot103();
    virtual unsigned char vSlot104();
    virtual unsigned char vSlot105();
    virtual unsigned char vSlot106();
    virtual unsigned char vSlot107();
    virtual unsigned char vSlot108();
    virtual unsigned char vSlot109();
    virtual unsigned char vSlot110();
    virtual unsigned char vSlot111();
    virtual unsigned char vSlot112();
    virtual unsigned char vSlot113();
    virtual unsigned char vSlot114();
    virtual unsigned char vSlot115();
    virtual unsigned char vSlot116();
    virtual unsigned char vSlot117();
    virtual unsigned char vSlot118();
    virtual unsigned char vSlot119();
    virtual unsigned char vSlot120();
    virtual unsigned char vSlot121();
    virtual unsigned char vSlot122();
    virtual unsigned char vSlot123();
    virtual unsigned char vSlot124();
    virtual unsigned char vSlot125();
    virtual unsigned char vSlot126();
    virtual unsigned char vSlot127();
    virtual unsigned char vSlot128();
    virtual unsigned char vSlot129();
    virtual unsigned char vSlot130();
    virtual unsigned char vSlot131();
    virtual unsigned char vSlot132();
    virtual unsigned char vSlot133();
    virtual unsigned char vSlot134();
    virtual unsigned char vSlot135();
    virtual unsigned char vSlot136();
    virtual unsigned char vSlot137();
    virtual unsigned char vSlot138();
    virtual unsigned char vSlot139();
    virtual unsigned char vSlot140();
    virtual unsigned char vSlot141();
    virtual unsigned char vSlot142();
    virtual unsigned char vSlot143();
    virtual unsigned char vSlot144();
    virtual unsigned char vSlot145();
    virtual unsigned char vSlot146();
    virtual unsigned char vSlot147();
    virtual unsigned char vSlot148();
    virtual unsigned char vSlot149();
    virtual unsigned char vSlot150();
    virtual unsigned char vSlot151();
    virtual unsigned char vSlot152();
    virtual unsigned char vSlot153();
    virtual unsigned char vSlot154();
    virtual unsigned char vSlot155();
    virtual unsigned char vSlot156();
    virtual unsigned char vSlot157();
    virtual unsigned char vSlot158();
    virtual unsigned char vSlot159();
    virtual unsigned char vSlot160();
    virtual unsigned char vSlot161();
    virtual unsigned char vSlot162();
    virtual unsigned char vSlot163();
    virtual unsigned char vSlot164();
    virtual unsigned char vSlot165();
    virtual unsigned char vSlot166();
    virtual unsigned char vSlot167();
    virtual unsigned char vSlot168();
    virtual unsigned char vSlot169();
    virtual unsigned char vSlot170();
    virtual unsigned char vSlot171();
    virtual unsigned char vSlot172();
    virtual unsigned char vSlot173();
    virtual unsigned char vSlot174();
    virtual unsigned char vSlot175();
    virtual unsigned char vSlot176();
    virtual unsigned char vSlot177();
    virtual unsigned char vSlot178();
    virtual unsigned char vSlot179();
    virtual unsigned char vSlot180();
    virtual unsigned char vSlot181();
    virtual unsigned char vSlot182();
    virtual unsigned char vSlot183();
    virtual unsigned char vSlot184();
    virtual unsigned char vSlot185();
    virtual unsigned char vSlot186();
    virtual unsigned char vSlot187();
    virtual unsigned char vSlot188();
    virtual unsigned char vSlot189();
    virtual unsigned char vSlot190();
    virtual unsigned char vSlot191();
    virtual unsigned char vSlot192();
    virtual unsigned char vSlot193();
    virtual unsigned char vSlot194();
    virtual unsigned char vSlot195();
    virtual unsigned char vSlot196();
    virtual unsigned char vSlot197();
    virtual unsigned char vSlot198();
    virtual unsigned char vSlot199();
    virtual unsigned char vSlot200();
    virtual unsigned char vSlot201();
    unsigned char Probe77c0();
};


// Returns false if obj's Probe77c0 is nonzero, or if vSlot060 is nonzero and either vSlot137 is nonzero with vSlot201 zero; otherwise true.
// @fnv 0x00849a90
bool BGSSaveLoadGame::ShouldUnloadForm(TESForm* pObject)
{
    FUN_00849a90_Iface* first;
    FUN_00849a90_Iface* second;
    if (((FUN_00849a90_Iface*)pObject)->Probe77c0() != 0)
    {
        return false;
    }
    if (((FUN_00849a90_Iface*)pObject)->vSlot060() != 0)
    {
        first = (FUN_00849a90_Iface*)pObject;
        if (first->vSlot137() != 0)
        {
            second = first;
            if (second->vSlot201() == 0)
            {
                return false;
            }
        }
    }
    return true;
}

struct ValueBase
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual double v3(unsigned int a);
};

struct ParamOwner
{
    char* GetHolderBase();
    unsigned int GetHavokWorldObjectCountInSceneGraph_0084e3a0(ParamOwner* a);
};

struct Sub34
{
    void FUN_00844700(unsigned int v);
};


extern const double DAT_01012060;

// Calls v3(0x10) on the ValueBase at p's holder base + 0x100 and, if the result exceeds DAT_01012060, calls m_34.FUN_00844700 with p->FUN_0084e3a0(p).
// @fnv 0x0084a520
void BGSSaveLoadGame::InitializePackageLocations(Actor* apOwner)
{
    if (((ValueBase*)(((ParamOwner*)apOwner)->GetHolderBase() + 0x100))->v3(0x10) > DAT_01012060)
    {
        ((Sub34*)QueuedInitPackageLocationsActorMap)->FUN_00844700(((ParamOwner*)apOwner)->GetHavokWorldObjectCountInSceneGraph_0084e3a0((ParamOwner*)apOwner));
    }
}

extern BGSSaveLoadGame* g_BGSSaveLoadGame;
struct UpdateInfo
{
    float time;
    bool updateControllers;
    bool multithread;
    bool unk06;
    bool unk07;
    bool unk08;
    UpdateInfo(float, bool, bool);
};
struct Scene
{
    void SetPosition(const NiPoint3*);
    void Refresh();
    void Update(UpdateInfo&);
};
struct ScenePointer
{
    Scene* Get();
};
struct LoadedData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    ScenePointer node;
};
struct World
{
    void Remove(void*);
    void Insert(void*);
};
struct Reference
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Mark(int);
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void Slot40();
    virtual void Slot41();
    virtual void Slot42();
    virtual void Slot43();
    virtual void Slot44();
    virtual void Slot45();
    virtual void Slot46();
    virtual void Slot47();
    virtual void Slot48();
    virtual void Slot49();
    virtual void Slot50();
    virtual void Slot51();
    virtual void Slot52();
    virtual void Slot53();
    virtual void Slot54();
    virtual void Slot55();
    virtual void Slot56();
    virtual void Slot57();
    virtual void Slot58();
    virtual void Slot59();
    virtual void Slot60();
    virtual void Slot61();
    virtual void Slot62();
    virtual void Slot63();
    virtual void Slot64();
    virtual void Slot65();
    virtual void Slot66();
    virtual void Slot67();
    virtual void Slot68();
    virtual void Slot69();
    virtual void Slot70();
    virtual void Slot71();
    virtual void Slot72();
    virtual void Slot73();
    virtual void Slot74();
    virtual void Slot75();
    virtual void Slot76();
    virtual void Slot77();
    virtual void GetFallback(NiPoint3*, NiPoint3*, int*, int);
    virtual void Slot79();
    virtual void Slot80();
    virtual void Slot81();
    virtual void Slot82();
    virtual void Slot83();
    virtual void Slot84();
    virtual void Slot85();
    virtual void Slot86();
    virtual void Slot87();
    virtual void Slot88();
    virtual void Slot89();
    virtual void Slot90();
    virtual void Slot91();
    virtual void Slot92();
    virtual void Slot93();
    virtual void Slot94();
    virtual void Slot95();
    virtual void Slot96();
    virtual void Slot97();
    virtual void Slot98();
    virtual void Slot99();
    virtual void Slot100();
    virtual void Slot101();
    virtual void Slot102();
    virtual void Slot103();
    virtual void Slot104();
    virtual void Slot105();
    virtual void Slot106();
    virtual void Slot107();
    virtual void Slot108();
    virtual void Slot109();
    virtual void Slot110();
    virtual void Slot111();
    virtual void Slot112();
    virtual void Slot113();
    virtual void Slot114();
    virtual void Slot115();
    virtual Scene* GetScene();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    NiPoint3 position;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    LoadedData* loaded;
    bool IsExterior();
    void TESObjectREFR_SetLocationOnReference(NiPoint3* input);
};
bool IsPersistent(void*);
World* __fastcall FindWorld(Reference*);
void UpdateScene(Scene*, bool);
// Validates the input position against world bounds, falls back to GetFallback when invalid, removes/reinserts the reference in its world, and updates the scene.
// @fnv 0x00575830
// src: XBOX_PDB 0x00575830
void Reference::TESObjectREFR_SetLocationOnReference(NiPoint3* apPosition)
{
    bool changedVal = false;
    NiPoint3 fallbackX = NiPoint3::ZERO;
    NiPoint3 anglesB = NiPoint3::ZERO;
    if (g_BGSSaveLoadGame && g_BGSSaveLoadGame->BGSSaveLoadGame_GetSaveGameLoading())
    {
        bool unusedFlag7 = false;
        if (apPosition->x == 3.4028234663852886e38 || apPosition->x == -3.4028234663852886e38 ||
            apPosition->y == 3.4028234663852886e38 || apPosition->y == -3.4028234663852886e38 ||
            apPosition->z == 3.4028234663852886e38 || apPosition->z == -3.4028234663852886e38 ||
            !(apPosition->x < 4096000.0 && apPosition->x > -4096000.0 && apPosition->y < 4096000.0 &&
              apPosition->y > -4096000.0))
        {
            int cell8 = 0;
            GetFallback(&fallbackX, &anglesB, &cell8, 0);
            fallbackX.z += 10.0;
            changedVal = true;
        }
    }
    else
    {
        if (apPosition->x > 4096000.0 || apPosition->x < -4096000.0 || apPosition->y > 4096000.0 ||
            apPosition->y < -4096000.0)
        {
            NiPoint3 angles = NiPoint3::ZERO;
            int parent3 = 0;
            GetFallback(&fallbackX, &angles, &parent3, 0);
            fallbackX.z += 10.0;
            changedVal = true;
        }
    }
    World* world7 = 0;
    if (IsExterior() && IsPersistent(this))
    {
        world7 = FindWorld(this);
        if (world7)
            world7->Remove(this);
    }
    if (!changedVal)
        position = *apPosition;
    else
    {
        position = fallbackX;
        if (GetScene())
        {
            GetScene()->SetPosition(&fallbackX);
            UpdateScene(loaded->node.Get(), true);
            loaded->node.Get()->Refresh();
            UpdateInfo info(0.0f, false, false);
            loaded->node.Get()->Update(info);
        }
    }
    if (world7)
        world7->Insert(this);
    Mark(2);
}

void* __cdecl memset(void*, int, unsigned int);
int __cdecl CompareSaveFileNames(const char*, const char*);
void __cdecl SaveGameWarning(const char*, ...);

struct SaveDataHandler
{
    unsigned char GetCompiledFileCount();
    TESFile* GetCompiledFileByIndex(unsigned int index);
};


// Reads a count and file names from apData, maps each name to a compiled save file index, and returns false if any name is not found.
// @fnv 0x00847660
bool SaveLoadGameFileLists::ReadFileIndexMap(void* apData)
{
    unsigned char cFileCount2 = ((SaveDataHandler*)g_dataHandler)->GetCompiledFileCount();
    BGSLoadGameBuffer kBuffer;
    kBuffer.Load(reinterpret_cast<::SaveLoadFile*>(apData));
    BGSLoadGameBuffer* pBuffer4 = &kBuffer;
    bool bResult2 = true;
    memset(cFileIndexArray, 0xff, 0xff);
    memset(cReverseFileIndexArray, 0xff, 0xff);
    unsigned char cCount4 = 0;
    pBuffer4->ReadTypedData(&cCount4, 1);
    for (unsigned int aI = 0; aI < cCount4; aI++)
    {
        char acName[260];
        pBuffer4->LoadString(acName);
        bool bFound = false;
        for (unsigned int jA = 0; jA < cFileCount2; jA++)
        {
            TESFile* _pFile = ((SaveDataHandler*)g_dataHandler)->GetCompiledFileByIndex(jA);
            if (!CompareSaveFileNames(acName, _pFile->GetFilename()))
            {
                cFileIndexArray[aI] = jA;
                cReverseFileIndexArray[jA] = aI;
                bFound = true;
                break;
            }
        }
        if (!bFound)
        {
            bResult2 = false;
            cFileIndexArray[aI] = 0xff;
            SaveGameWarning("SAVELOAD: Cannot find file %s referenced in the save game.  Errors may result.", acName);
        }
    }
    return bResult2;
}

namespace fnv_00847850 {
struct W20File
{
    char* _ref_006815c0();
    unsigned int FUN_00846400();
    void WriteToFile(void*, int);
    void FUN_00846440(unsigned int);
};
struct W20Manager
{
    void EnsureFosExtension(char*, char*);
    void FUN_00851120(char*, int);
    unsigned int GetConstant27();
};
struct W20Flags
{
    unsigned int value;
    unsigned int Modelloader_GetReferencedThis();
    W20Flags BGSChangeFlags_GetDifference(unsigned int);
    void BGSUnloadedFormBuffer_Save(W20File*, unsigned int, W20Flags);
};
struct W20Change
{
    W20Flags flags;
    W20Flags savedFlags;
};
struct W20Buffer;
struct W20Form
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v54(W20Buffer*);
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v80(W20Buffer*);
    int FNV_GetFormType();
};

struct W20OtherMap
{
    void BGSSaveLoadFormIDMap_Save(W20File*);
};
struct W20History
{
    void SaveTo(W20File*);
};
struct W20Header
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    void ClearObject();
};
struct W20Buffer
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    W20Buffer();
    virtual ~W20Buffer();
    void BGSSaveGameBuffer_ClearPosition();
    void InitFormEntry(unsigned int, unsigned int, int, unsigned char);
    void SetSpeakerIdle(W20Form*);
    W20Flags FUN_00428110();
    void FUN_00865a30(W20File*);
};
extern W20Manager* DAT_011de134;
void FUN_0084dff0(W20History*, const char*, ...);
void SaveGameWarning(const char*, ...);
void ForwardToShell(W20File*, void*, int);
unsigned int BGSSaveLoadFile_SaveGlobalDataRange0_C(W20File*);
unsigned int BGSSaveLoadGlobalData_SaveFinalGlobalData(W20File*);
W20Form* TESForm_GetFormByNumericID(unsigned int);
void BGSSaveLoadInitialData_SaveInitialData(W20Buffer*, W20Form*, unsigned int);

}  // namespace fnv_00847850

// Writes the save file: logs the save, writes a header, serializes each changed form, then rewrites the header with offsets and sizes.
// @fnv 0x00847850
void BGSSaveLoadGame::SaveGame(::SaveLoadFile* file)
{
    using namespace fnv_00847850;
    SetSaveGameSaving(true);
    char k[260];
    char ba[260];
    fnv_00847850::DAT_011de134->EnsureFosExtension(((W20File*)file)->_ref_006815c0(), k);
    fnv_00847850::DAT_011de134->FUN_00851120(ba, 260);
    fnv_00847850::FUN_0084dff0(((W20History*)pHistory), "***Saving game: %s (%s)", k, ba);
    unsigned char j = fnv_00847850::DAT_011de134->GetConstant27();
    ForwardToShell(((W20File*)file), &j, 1);
    ((SaveLoadGameFileLists*)this)->SaveCompiledFileList(((W20File*)file));
    unsigned int e = ((W20File*)file)->FUN_00846400();
    W20Header c;
    c.ClearObject();
    ((W20File*)file)->WriteToFile(&c, 110);
    c.unk08 = ((W20File*)file)->FUN_00846400();
    c.unk14 = BGSSaveLoadFile_SaveGlobalDataRange0_C(((W20File*)file));
    c.unk0c = ((W20File*)file)->FUN_00846400();
    W20Buffer l;
    void* p = pChangesMap->GetFirstPos();
    while (p)
    {
        unsigned int j = 0;
        W20Change* e = 0;
        pChangesMap->GetNext(p, j, reinterpret_cast<FormChangeRecord*&>(e));
        if (e->savedFlags.Modelloader_GetReferencedThis())
        {
            e->savedFlags.BGSUnloadedFormBuffer_Save(((W20File*)file), j, e->flags);
            c.unk1c++;
        }
        else
        {
            W20Form* form = fnv_00847850::TESForm_GetFormByNumericID(j);
            if (form)
            {
                l.BGSSaveGameBuffer_ClearPosition();
                l.InitFormEntry(j, e->flags.value, form->FNV_GetFormType(), fnv_00847850::DAT_011de134->GetConstant27());
                l.SetSpeakerIdle(form);
                form->v80(&l);
                W20Flags k = l.FUN_00428110().BGSChangeFlags_GetDifference(e->flags.Modelloader_GetReferencedThis());
                if (k.Modelloader_GetReferencedThis())
                    pChangesMap->AddFormChangeFlags(j, reinterpret_cast<FormChangeMask&>(k));
                W20Flags ba = e->flags.BGSChangeFlags_GetDifference(l.FUN_00428110().Modelloader_GetReferencedThis());
                if (ba.Modelloader_GetReferencedThis() && pChangesMap->ClearChangeFlags(j, reinterpret_cast<FormChangeMask&>(ba)))
                    continue;
                fnv_00847850::BGSSaveLoadInitialData_SaveInitialData(&l, form, e->flags.value);
                form->v54(&l);
                l.FUN_00865a30(((W20File*)file));
                c.unk1c++;
            }
            else
                fnv_00847850::SaveGameWarning(
                    "SAVELOAD: Could not find form %08X with change flags %08X during BGSSaveLoadGame::SaveGame()", j,
                    e->flags.Modelloader_GetReferencedThis());
        }
    }
    c.unk10 = ((W20File*)file)->FUN_00846400();
    c.unk18 = BGSSaveLoadGlobalData_SaveFinalGlobalData(((W20File*)file));
    c.unk00 = ((W20File*)file)->FUN_00846400();
    ((W20OtherMap*)pFormIDMap)->BGSSaveLoadFormIDMap_Save(((W20File*)file));
    ((W20OtherMap*)pWorldspaceFormIDMap)->BGSSaveLoadFormIDMap_Save(((W20File*)file));
    c.unk04 = ((W20File*)file)->FUN_00846400();
    fnv_00847850::FUN_0084dff0(((W20History*)pHistory), "---Finished saving game: %s", k);
    ((W20History*)pHistory)->SaveTo(((W20File*)file));
    ((W20File*)file)->FUN_00846440(e);
    ((W20File*)file)->WriteToFile(&c, 110);
    SetSaveGameSaving(false);
}


struct FUN_00847450
{
    ~FUN_00847450();
};
struct FUN_008473c0
{
    ~FUN_008473c0();
};
struct SaveFile;
struct FUN_0084ded0
{
    unsigned int vtable, capacity;
    void* entries;
    unsigned int size;
    FUN_0084ded0();
    void* FUN_00847450(unsigned int);
    void FUN_0084e190(SaveFile*);
    void AddAllNotes(FUN_0084ded0*);
};
struct FUN_00846b60
{
    unsigned int vtable, capacity;
    void* entries;
    unsigned int size;
    unsigned int secondVtable, secondCapacity;
    void* secondEntries;
    unsigned int secondSize, flags;
    FUN_00846b60(unsigned int);
    void LoadFormIDMap(SaveFile*);
    void* FUN_008473c0(unsigned int);
};
// Load-stage operations absent from the shared changes-map API; no added layout.
struct SaveLoadChangesMapLoadAccess : BGSSaveLoadChangesMap
{
    UnloadFlags GetFirstEntry(unsigned int);
    void SetCombatTargetQuantity(unsigned int, FormChangeMask, unsigned int);
};
struct LoadHeader
{
    unsigned int formOffset, unk04, unk08, unk0c, unk10, firstBlockOffset, lastBlockOffset, formCount, tailOffset;
    unsigned int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58,
        unk5c, unk60, unk64, unk68;
    unsigned short unk6c;
    void ClearObject();
};
struct SaveFile
{
    char* FUN_006815c0(char*);
    void FUN_00846300(void*, unsigned int);
    unsigned int FUN_00846400();
    void FUN_00846440(unsigned int);
    void AdvancePosition(unsigned int);
};
struct FormExtra : TESForm
{
    unsigned int FUN_00401170();
    const char* TESForm_GetFormTypeString();
    void FUN_0046a010(bool);
};
struct ReferenceExtra : FormExtra
{
    unsigned int BGSSaveFormBuffer_GetForm();
};
struct FUN_008c71b0;
struct FlagMethods
{
    unsigned int flags;
    void FUN_00841100(unsigned int);
};
struct FUN_008c71b0
{
    unsigned int value;
    FUN_008c71b0(unsigned int);
    FUN_008c71b0(const FUN_008c71b0&);
};
// This overload preserves construction of the legacy flag in the argument slot.
struct LoadFormBufferLegacyFlags
{
    void FUN_0086cf00(FUN_008c71b0);
};
struct FUN_0044dee0
{
    unsigned int formId;
    FUN_0044dee0();
    void ReadBuffer(SaveFile*);
};
struct BufferArray
{
    unsigned int vtable;
    BGSLoadFormBuffer** entries;
    unsigned int capacity, size;
    void FUN_008454f0(bool);
    void BSSimpleArray_TESObjectREFR_1024_SetReservedSize(unsigned int);
    void FUN_007cb2e0(BGSLoadFormBuffer**);
    BGSLoadFormBuffer*& BSSimpleArray_NiAVObject_1024_GetAt(unsigned int);
    void BSSimpleArray_TESAmmo_1024_SetAt(unsigned int, BGSLoadFormBuffer* const&);
};
struct FormQueue
{
    void BGSReconstructFormsInAllFilesMap_AddForm(FormExtra*, bool);
};
struct ReferenceMap
{
    void FUN_00852b60();
};
struct LoadManagerPrefix
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    struct String
    {
        void FUN_004037f0(char*, unsigned int);
    } name;
};
struct LoadManagerMethods
{
    void EnsureFosExtension(char*);
    void FUN_00851120(char*, unsigned int);
    void FUN_00850c20();
};
struct GlobalTask
{
    void IOManager_Pause();
};
struct PlayerMethods : TESForm
{
    virtual void Reserved138();
    virtual void Reserved13c();
    virtual void Reserved140();
    virtual void Reserved144();
    virtual void Reserved148();
    virtual void Reserved14c();
    virtual void Reserved150();
    virtual void Reserved154();
    virtual void Reserved158();
    virtual void Reserved15c();
    virtual void Reserved160();
    virtual void Reserved164();
    virtual void Reserved168();
    virtual void Reserved16c();
    virtual void Reserved170();
    virtual void Reserved174();
    virtual void Reserved178();
    virtual void Reserved17c();
    virtual void Reserved180();
    virtual void Reserved184();
    virtual void Reserved188();
    virtual void Reserved18c();
    virtual void Reserved190();
    virtual void Reserved194();
    virtual void Reserved198();
    virtual void Reserved19c();
    virtual void Reserved1a0();
    virtual void Reserved1a4();
    virtual void Reserved1a8();
    virtual void Reserved1ac();
    virtual void Reserved1b0();
    virtual void Reserved1b4();
    virtual void Reserved1b8();
    virtual void Reserved1bc();
    virtual void Reserved1c0();
    virtual void Reserved1c4();
    virtual void Reserved1c8();
    virtual void Reserved1cc();
    virtual void Reserved1d0();
    virtual void Reserved1d4();
    virtual void Reserved1d8();
    virtual void Reserved1dc();
    virtual void Reserved1e0();
    virtual void Reserved1e4();
    virtual void Reserved1e8();
    virtual void Reserved1ec();
    virtual void Reserved1f0();
    virtual void Reserved1f4();
    virtual void Reserved1f8();
    virtual void Reserved1fc();
    virtual void Reserved200();
    virtual void Reserved204();
    virtual void Reserved208();
    virtual void Reserved20c();
    virtual void Reserved210();
    virtual void Reserved214();
    virtual void Reserved218();
    virtual void Reserved21c();
    virtual void Reserved220();
    virtual void Reserved224();
    virtual void FinalizeLoad(bool);
    void FUN_00848e10();
};
struct HandlerMethods
{
    bool FUN_00469860(unsigned int);
    void TESDataHandler_SetDontRemoveIDs(bool);
};
struct FinalizeMethods
{
    void Menu_SetRenderedMenu();
};
extern GlobalTask* DAT_01202d98;
extern PlayerMethods* DAT_011dea3c;
extern FinalizeMethods DAT_011de7b8;
extern const char DAT_0107f048[], DAT_0107efd0[], DAT_0107efb0[];
extern void* __cdecl operator new(unsigned int);
void __cdecl FUN_0084dff0(FUN_0084ded0*, const char*, ...);
void __cdecl ReadFileIntoBuffer(SaveFile*, unsigned char*, unsigned int);
void __cdecl StartMenu_SetMissingContentFlag(unsigned int);
void __cdecl FUN_0084c270(unsigned int);
void __cdecl LoadGlobalDataRanges(SaveFile*, unsigned int);
FormExtra* __cdecl TESForm_GetFormByNumericID(unsigned int);
const char* __cdecl GetStringForByte(unsigned int);
void __cdecl SaveGameWarning(const char*, ...);
UnloadFlags __cdecl FUN_00841120(UnloadFlags, FormChangeMask, unsigned int, bool);
void __cdecl FUN_0084f330(BGSLoadFormBuffer*, FormExtra*, FormChangeMask);
void __cdecl ShadowSceneNode_ProcessAllQueuedLights();
void __cdecl BGSSaveLoadGlobalData_InitGlobalData_0();
void __cdecl BGSSaveLoadGlobalData_FinishLoadGlobalData_0();
void __cdecl FUN_00850b40(char*);
// Load-stage helpers and the original constructor-bearing reversion overload
// are absent from the shared game API. This extension adds no layout.
class SaveLoadGameLoadStages : public BGSSaveLoadGame
{
public:
    void BGSSaveLoadGame_SetGlobalAllowChanges(bool);
    bool IsFlag80Set();
    bool RevertReference(FormExtra**, UnloadFlags, bool);
};

// Loads a save file: reads the header, rebuilds form and change state, loads each form buffer, then finalizes; returns false on failure.
// @fnv 0x00847df0
bool BGSSaveLoadGame::LoadGame(SaveLoadFile* pSaveFile, bool restoreMode)
{
    unsigned int position5;
    FUN_0084ded0* replacementState_2 = ((FUN_0084ded0*&)pHistory);
    unsigned int position;
    ((FUN_0084ded0*&)pHistory) = new FUN_0084ded0;
    char finalName[260];
    char writeName[260];
    ((LoadManagerMethods*)DAT_011de134)->EnsureFosExtension(((SaveFile*)pSaveFile)->FUN_006815c0(finalName));
    ((LoadManagerMethods*)DAT_011de134)->FUN_00851120(writeName, 260);
    FUN_0084dff0(((FUN_0084ded0*&)pHistory), DAT_0107f048, finalName, writeName);
    ReadFileIntoBuffer(((SaveFile*)pSaveFile), &cCurrentMinorVersion, 1);
    {
        FUN_00846b60* oldState5;
        FUN_0084ded0* oldState9;
        bool restoring = ((SaveLoadGameFileLists*)this)->ReadFileIndexMap(((SaveFile*)pSaveFile));
        if (!restoring && !restoreMode)
        {
            delete (FUN_00847450*)((FUN_0084ded0*&)pHistory);
            ((FUN_0084ded0*&)pHistory) = replacementState_2;
            cCurrentMinorVersion = 255;
            StartMenu_SetMissingContentFlag(1);
            return false;
        }
        delete (FUN_00847450*)replacementState_2;
        ((ReferenceMap*&)pReferencesMap)->FUN_00852b60();
        ((LoadManagerMethods*)DAT_011de134)->FUN_00850c20();
        DAT_01202d98->IOManager_Pause();
        SetDeferInitForms(true);
        DAT_011dea3c->FUN_00848e10();
        {
            LoadHeader header;
            {
                char readName[260];
                header.ClearObject();
                ((SaveFile*)pSaveFile)->FUN_00846300(&header, 110);
                position5 = ((SaveFile*)pSaveFile)->FUN_00846400();
                ((SaveFile*)pSaveFile)->FUN_00846440(header.formOffset);
                oldState5 = ((FUN_00846b60*&)pFormIDMap);
                ((FUN_00846b60*&)pFormIDMap) = new FUN_00846b60(5039);
                ((FUN_00846b60*&)pFormIDMap)->LoadFormIDMap(((SaveFile*)pSaveFile));
                ((FUN_00846b60*&)pWorldspaceFormIDMap)->LoadFormIDMap(((SaveFile*)pSaveFile));
                oldState9 = ((FUN_0084ded0*&)pHistory);
                ((FUN_0084ded0*&)pHistory) = new FUN_0084ded0;
                ((FUN_0084ded0*&)pHistory)->FUN_0084e190(((SaveFile*)pSaveFile));
                ((FUN_0084ded0*&)pHistory)->AddAllNotes(oldState9);
                delete (FUN_00847450*)oldState9;
                ((SaveFile*)pSaveFile)->FUN_00846440(position5);
                pOldChangesMap = pChangesMap;
                pChangesMap = new BGSSaveLoadChangesMap;
                FUN_0084c270(0);
                ((HandlerMethods*)g_dataHandler)->TESDataHandler_SetDontRemoveIDs(true);
                LoadGlobalDataRanges(((SaveFile*)pSaveFile), header.firstBlockOffset);
                {
                    SaveLoadChangesMapLoadAccess* pendingChanges = ((SaveLoadChangesMapLoadAccess*&)pChangesMap);
                    pChangesMap = pOldChangesMap;
                    pOldChangesMap = 0;
                    position = ((SaveFile*)pSaveFile)->FUN_00846400();
                    (*(BufferArray*)FormBufferArray).FUN_008454f0(false);
                    (*(BufferArray*)FormBufferArray).BSSimpleArray_TESObjectREFR_1024_SetReservedSize(header.formCount);
                    ((SaveLoadGameLoadStages*)this)->BGSSaveLoadGame_SetGlobalAllowChanges(false);
                    for (unsigned int index2 = 0; index2 < header.formCount; index2++)
                    {
                        BGSLoadFormBuffer* current = new BGSLoadFormBuffer;
                        current->FUN_008644b0(((SaveFile*)pSaveFile));
                        unsigned int typeX = current->GetFormType_008665b0();
                        unsigned int index = current->TESMain_GetThread();
                        FormChangeMask changed = current->FUN_00428110();
                        UnloadFlags currentVal = ((SaveLoadChangesMapLoadAccess*&)pChangesMap)->GetFirstEntry(index);
                        UnloadFlags previous_ = pendingChanges->GetFirstEntry(index);
                        if (previous_.Modelloader_GetReferencedThis())
                        {
                            ((FlagMethods*)&currentVal)->FUN_00841100(previous_.Modelloader_GetReferencedThis());
                            pendingChanges->HasFormChanges(index);
                        }
                        pendingChanges->ApplyFormQuantityChange(index, changed);
                        current->FUN_0086cf00(reinterpret_cast<FormChangeMask&>(currentVal));
                        FormExtra* form_ = TESForm_GetFormByNumericID(index);
                        current->FUN_007037c0(form_);
                        unsigned int position3 = LoadFormRecord(pSaveFile, current, (FormIDConverter*)oldState5);
                        current->FUN_00864580(((SaveFile*)pSaveFile), position3);
                        form_ = (FormExtra*)current->GetForm();
                        currentVal = reinterpret_cast<UnloadFlags&>(current->BGSLoadFormBuffer_GetOldChangeFlags());
                        bool overrideFlag3 = false;
                        if (form_)
                        {
                            bool invalid = false;
                            if (form_->FUN_00401170() != typeX)
                                invalid = true;
                            else if (form_->GetIsReference())
                            {
                                ReferenceExtra* reference = (ReferenceExtra*)form_;
                                if (reference->BGSSaveFormBuffer_GetForm() == 0)
                                    invalid = true;
                            }
                            if (invalid)
                            {
                                if (((HandlerMethods*)g_dataHandler)->FUN_00469860(index))
                                {
                                    ClearForm(form_);
                                    current->FUN_007037c0(0);
                                    ((LoadFormBufferLegacyFlags*)current)->FUN_0086cf00(FUN_008c71b0(0));
                                    overrideFlag3 = true;
                                }
                                else
                                {
                                    if (form_->FUN_00401170() != typeX)
                                        SaveGameWarning(DAT_0107efd0, form_->GetName(), index,
                                                     GetStringForByte((unsigned char)typeX), form_->TESForm_GetFormTypeString());
                                    current->SetSkipForm_00848d90(true);
                                }
                            }
                            else
                            {
                                form_->Revert(current);
                                UnloadFlags combined = FUN_00841120(currentVal, changed, typeX, true);
                                if (combined.Modelloader_GetReferencedThis())
                                {
                                    if (!((SaveLoadGameLoadStages*)this)->RevertReference((FormExtra**)&form_, combined, false))
                                    {
                                        ((FormQueue*&)pReconstructForms)->BGSReconstructFormsInAllFilesMap_AddForm(form_, false);
                                        current->FUN_0042ce50(true);
                                    }
                                }
                                overrideFlag3 = true;
                            }
                        }
                        else
                            overrideFlag3 = true;
                        if (overrideFlag3)
                            pChangesMap->HasFormChanges(index);
                        (*(BufferArray*)FormBufferArray).FUN_007cb2e0(&current);
                    }
                    RevertCurrentChanges((int)pendingChanges, (int)oldState5);
                    ShadowSceneNode_ProcessAllQueuedLights();
                    delete (FUN_008473c0*)oldState5;
                    ((HandlerMethods*)g_dataHandler)->TESDataHandler_SetDontRemoveIDs(false);
                    ClearFormChanges();
                    ((SaveFile*)pSaveFile)->FUN_00846440(position);
                    for (unsigned int index2 = 0; index2 < header.formCount; index2++)
                    {
                        BGSLoadFormBuffer* current = (*(BufferArray*)FormBufferArray).BSSimpleArray_NiAVObject_1024_GetAt(index2);
                        if (current->GetSkipForm_00848dd0())
                        {
                            pChangesMap->HasFormChanges(current->TESMain_GetThread());
                            current->FUN_008644b0(((SaveFile*)pSaveFile));
                            current->FUN_00864580(((SaveFile*)pSaveFile), 0);
                            delete current;
                            (*(BufferArray*)FormBufferArray).BSSimpleArray_TESAmmo_1024_SetAt(index2, (BGSLoadFormBuffer*)0);
                            continue;
                        }
                        unsigned int index = current->TESMain_GetThread();
                        FormExtra* form_ = (FormExtra*)current->GetForm();
                        if (form_)
                        {
                            current->FUN_008644b0(((SaveFile*)pSaveFile));
                            unsigned int typeX = current->GetFormType_008665b0();
                            bool invalid = false;
                            if (form_->FUN_00401170() != typeX)
                            {
                                SaveGameWarning(DAT_0107efd0, form_->GetName(), index,
                                             GetStringForByte((unsigned char)typeX), form_->TESForm_GetFormTypeString());
                                invalid = true;
                            }
                            else if (form_->GetIsReference())
                            {
                                ReferenceExtra* reference = (ReferenceExtra*)form_;
                                if (reference->BGSSaveFormBuffer_GetForm() == 0)
                                    invalid = true;
                            }
                            if (invalid)
                            {
                                pChangesMap->HasFormChanges(current->TESMain_GetThread());
                                current->FUN_00864580(((SaveFile*)pSaveFile), 0);
                                delete current;
                                (*(BufferArray*)FormBufferArray).BSSimpleArray_TESAmmo_1024_SetAt(index2, (BGSLoadFormBuffer*)0);
                                continue;
                            }
                            if (current->CheckValueMatchesField(((SaveFile*)pSaveFile)) < 0 || ((SaveLoadGameLoadStages*)this)->IsFlag80Set())
                            {
                                current->FUN_00864580(((SaveFile*)pSaveFile), 0);
                                delete current;
                                (*(BufferArray*)FormBufferArray).BSSimpleArray_TESAmmo_1024_SetAt(index2, (BGSLoadFormBuffer*)0);
                                (*(BufferArray*)FormBufferArray).FUN_008454f0(true);
                                DAT_011dea3c->FinalizeLoad(false);
                                ((SaveLoadGameLoadStages*)this)->BGSSaveLoadGame_SetGlobalAllowChanges(true);
                                SetDeferInitForms(false);
                                return false;
                            }
                            FUN_0084f330(current, form_, current->FUN_00428110());
                            if (current->GetForm() && !((SaveLoadGameLoadStages*)this)->IsFlag80Set())
                            {
                                form_->FUN_0046a010(true);
                                form_->LoadGame(current);
                            }
                        }
                        else
                        {
                            FUN_0044dee0 subBuffer;
                            subBuffer.ReadBuffer(((SaveFile*)pSaveFile));
                            ((SaveLoadChangesMapLoadAccess*)pChangesMap)->SetCombatTargetQuantity(index, current->FUN_00428110(), subBuffer.formId);
                        }
                        current->FUN_00848d50();
                    }
                    ((SaveFile*)pSaveFile)->AdvancePosition(header.tailOffset);
                    BGSSaveLoadGlobalData_InitGlobalData_0();
                    LoadCellChanges(true);
                    BGSSaveLoadGlobalData_FinishLoadGlobalData_0();
                    LoadGlobalDataRanges(((SaveFile*)pSaveFile), header.lastBlockOffset);
                    cCurrentMinorVersion = 255;
                    FUN_00850b40(readName);
                    ((LoadManagerPrefix*)DAT_011de134)->name.FUN_004037f0(readName, 0);
                    FUN_0084dff0(((FUN_0084ded0*&)pHistory), DAT_0107efb0, finalName);
                    ((SaveLoadGameLoadStages*)this)->BGSSaveLoadGame_SetGlobalAllowChanges(true);
                    DAT_011de7b8.Menu_SetRenderedMenu();
                    SetDeferInitForms(false);
                    return true;
                }
            }
        }
    }
}

namespace fnv_008492b0 {
class GlobalObject_008c71b0
{
  public:
    GlobalObject_008c71b0(int);
    GlobalObject_008c71b0(const GlobalObject_008c71b0&);
    int flags;
};

class LoadBufferArray
{
  public:
    unsigned int GetSize();
    BGSLoadGameBuffer*& BSSimpleArray_NiAVObject_1024_GetAt(unsigned int);
    void Clear(bool);
};
extern IOManager* DAT_01202d98;

extern TES* g_TES;
extern TESObjectREFR* _g_thePlayer;
class CellPhysics
{
  public:
    void* TESObjectCELL_GetbhkWorld();
    void RemoveReference(TESObjectREFR*);
};
class PhysicsWorld
{
  public:
    void bhkWorld_DeactivateAllIslands();
};
class ChangeMap
{
  public:
    void FUN_00865360();
};
class LoadedMap
{
  public:
    void RemoveAll();
};
class LoadReference : public TESObjectREFR
{
  public:
    virtual void V144();
    virtual void V145();
};
bool __fastcall BGSLoadFormBuffer_GetCellChanged(int);
void __cdecl GarbageCollector_Add_TESObjectREFR(TESObjectREFR*);
class FormState
{
  public:
    void FUN_0046a010(bool);
};
// Preserve the original change-mask argument construction absent from the shared API.
class ChangeNotifications
{
public:
    void Notify(TESForm*, GlobalObject_008c71b0, bool);
};

}  // namespace fnv_008492b0

// @fnv 0x008492b0
void BGSSaveLoadGame::LoadCellChanges(bool resetWorld)
{
    using namespace fnv_008492b0;
    SetInitingForms(true);
    if (resetWorld)
        fnv_008492b0::DAT_01202d98->IOManager_ForceHighestPriority();
    for (unsigned int i = 0; i < ((LoadBufferArray*)FormBufferArray)->GetSize(); ++i)
    {
        BGSLoadGameBuffer* buffer = ((LoadBufferArray*)FormBufferArray)->BSSimpleArray_NiAVObject_1024_GetAt(i);
        if (buffer)
        {
            TESForm* form = buffer->GetForm();
            if (form)
                form->Unk_19(buffer);
        }
    }
    if (resetWorld)
    {
        g_TES->TES_QueueReferencesForAttachedCells();
        fnv_008492b0::DAT_01202d98->IOManager_Resume();
        fnv_008492b0::DAT_01202d98->IOManager_LoadAllQueuedPriorities();
        TESObjectCELL* cell = _g_thePlayer->GetParentCell();
        PhysicsWorld* world = cell ? (PhysicsWorld*)((CellPhysics*)cell)->TESObjectCELL_GetbhkWorld() : 0;
        if (world)
            world->bhkWorld_DeactivateAllIslands();
        g_TES->TES_ActivateAllSubmergedReferencesIslands();
    }
    ((ChangeMap*)pQueuedSubBuffersMap)->FUN_00865360();
    for (unsigned int j = 0; j < ((LoadBufferArray*)FormBufferArray)->GetSize(); ++j)
    {
        BGSLoadGameBuffer* buffer = ((LoadBufferArray*)FormBufferArray)->BSSimpleArray_NiAVObject_1024_GetAt(j);
        if (buffer)
        {
            TESForm* form = buffer->GetForm();
            if (form)
            {
                form->Unk_21(reinterpret_cast<BGSLoadFormBuffer*>(buffer));
                if (fnv_008492b0::BGSLoadFormBuffer_GetCellChanged((int)buffer))
                {
                    TESObjectREFR* ref = buffer->GetReference();
                    ((ChangeNotifications*)this)->Notify(ref, GlobalObject_008c71b0(8), true);
                    if (ref->IsActor())
                    {
                        LoadReference* actor = (LoadReference*)ref;
                        if (((Actor*)actor)->GetProcess())
                            actor->V145();
                    }
                    ((SaveLoadGameUnloading*)this)->UnloadForm(ref, true);
                    TESObjectCELL* cell = ref->GetParentCell();
                    if (cell)
                        ((CellPhysics*)cell)->RemoveReference(ref);
                    GarbageCollector_Add_TESObjectREFR(ref);
                }
                ((FormState*)form)->FUN_0046a010(false);
            }
            delete buffer;
        }
    }
    ((LoadBufferArray*)FormBufferArray)->Clear(true);
    ((LoadedMap*)pChangedFormIDMap)->RemoveAll();
    SetInitingForms(false);
}


struct UnloadedBuffer_8495d0
{
    char* pBuffer;
    const char* GetBuffer() const;
    int GetFormType();
    BGSLoadFormBuffer* CreateFormBuffer();
    void ResetReadPosition();
};

struct FormChanges_8495d0
{
    FormChangeMask kFlags;
    UnloadedBuffer_8495d0 kUnloaded;
};


struct BufferArray_8495d0
{
    unsigned int Add(BGSLoadFormBuffer*& arpBuffer);
};

struct FormRef_8495d0
{
    unsigned int GetID();
    const char* GetFormTypeName();
    void SetLoaded(bool abLoaded);
};

const char* GetFormTypeNameByID(unsigned char acType);
void __cdecl SaveGameWarning(const char*, ...);
int __fastcall FNV_GetFormType(TESForm*);
void __cdecl ApplyChanges_8495d0(BGSLoadFormBuffer* apBuffer, TESForm* apForm, FormChangeMask aFlags);


// @fnv 0x008495d0
void BGSSaveLoadGame::LoadForm(TESForm* apForm)
{
    if (BGSSaveLoadGame_GetSaveGameLoading())
        return;

    unsigned int auiFormId = ((FormRef_8495d0*)apForm)->GetID();
    FormChanges_8495d0* pChanges = (FormChanges_8495d0*)pChangesMap->FUN_009a4250(auiFormId);
    if (pChanges && pChanges->kUnloaded.GetBuffer())
    {
        int iSavedFormType = pChanges->kUnloaded.GetFormType();
        if (FNV_GetFormType(apForm) != iSavedFormType)
        {
            SaveGameWarning(
                "SAVELOAD: (Load Error) Form '%s' (%08X) was saved with form type %s, but currently has form type %s.  Its loading will be skipped.",
                apForm->GetName(), auiFormId, GetFormTypeNameByID((unsigned char)iSavedFormType),
                ((FormRef_8495d0*)apForm)->GetFormTypeName());
            pChangesMap->HasFormChanges(auiFormId);
            return;
        }
        bool bPrevAllowChanges = SetThreadAllowChanges(false);
        BGSLoadFormBuffer* pBuffer = pChanges->kUnloaded.CreateFormBuffer();
        pChanges->kUnloaded.ResetReadPosition();
        pBuffer->SetForm(apForm);
        pBuffer->SetChangeFlags(pChanges->kFlags);
        ((FormRef_8495d0*)apForm)->SetLoaded(true);
        ApplyChanges_8495d0(pBuffer, apForm, pChanges->kFlags);
        apForm->LoadGame(pBuffer);
        pBuffer->FUN_00848d50();
        ((BufferArray_8495d0*)FormBufferArray)->Add(pBuffer);
        SetThreadAllowChanges(bPrevAllowChanges);
    }
}

struct ChangeFlags84
{
    unsigned int flags;
    bool Test(unsigned int mask);
    void Clear(unsigned int mask);
    unsigned int Get();
};

struct BoundObj84 : TESForm
{
    const char* GetEditorID84();
};

struct Ref84 : TESForm
{
    bool IsChangedLocation84(int unk);
    bool IsPersistent84();
    int HasName84();
    const char* GetFullName84();
    BoundObj84* GetObjectReference84();
};

extern Ref84* g_thePlayer;


// @fnv 0x0084a3a0
bool BGSSaveLoadGame::FindFormByID(TESForm** appRef, unsigned int flags, bool bDelete)
{
    if ((*(Ref84**)appRef) == g_thePlayer)
        return true;
    if (((*(Ref84**)appRef))->GetIsReference())
    {
        Ref84* pRef = (*(Ref84**)appRef);
        if (((ChangeFlags84*)&flags)->Test(0xe))
        {
            if (g_dataHandler->FormIDExists(((*(Ref84**)appRef))->GetFormID()) || pRef->IsChangedLocation84(0))
            {
                ((ChangeFlags84*)&flags)->Clear(0xe);
                if (!((ChangeFlags84*)&flags)->Get() && pRef->IsActor())
                {
                    Ref84* pActor = pRef;
                    InitializePackageLocations((Actor*)pActor);
                }
            }
            else if (bDelete && !pRef->IsPersistent84())
            {
                DeleteForm(pRef);
                pRef = 0;
                (*(Ref84**)appRef) = 0;
            }
            else
            {
                _fnv_call_845cc0(
                    "Reference %s %08X with type %s and with changes %08X could not revert its changed location",
                    pRef->HasName84() ? pRef->GetName() : pRef->GetFullName84(), pRef->GetFormID(),
                    pRef->GetObjectReference84()->GetEditorID84(), ((ChangeFlags84*)&flags)->Get());
            }
        }
    }
    if (!((ChangeFlags84*)&flags)->Get())
        return true;
    return false;
}

namespace fnv_0084ab20 {
struct Pt3f
{
    float x;
    float y;
    float z;
};
struct Obj84
{
    bool FUN_00425fd0();
    unsigned int GetHavokWorldObjectCountInSceneGraph_0084e3a0();
};
struct Form84
{
    virtual void vfn_000();
    virtual void vfn_004();
    virtual void vfn_008();
    virtual void vfn_00c();
    virtual void vfn_010();
    virtual void vfn_014();
    virtual void vfn_018();
    virtual void vfn_01c();
    virtual void vfn_020();
    virtual void vfn_024();
    virtual void vfn_028();
    virtual void vfn_02c();
    virtual void vfn_030();
    virtual void vfn_034();
    virtual void vfn_038();
    virtual void vfn_03c();
    virtual void vfn_040();
    virtual void vfn_044();
    virtual void vfn_048();
    virtual void vfn_04c();
    virtual void vfn_050();
    virtual void vfn_054();
    virtual void vfn_058();
    virtual void vfn_05c();
    virtual void vfn_060();
    virtual void vfn_064();
    virtual void vfn_068();
    virtual void vfn_06c();
    virtual void vfn_070();
    virtual void vfn_074();
    virtual void vfn_078();
    virtual void vfn_07c();
    virtual void vfn_080();
    virtual void vfn_084();
    virtual void vfn_088();
    virtual void vfn_08c();
    virtual void vfn_090();
    virtual void vfn_094();
    virtual void vfn_098();
    virtual void vfn_09c();
    virtual void vfn_0a0();
    virtual void vfn_0a4();
    virtual void vfn_0a8();
    virtual void vfn_0ac();
    virtual void vfn_0b0();
    virtual void vfn_0b4();
    virtual void vfn_0b8();
    virtual void vfn_0bc();
    virtual void vfn_0c0();
    virtual void vfn_0c4();
    virtual void vfn_0c8();
    virtual void vfn_0cc();
    virtual void vfn_0d0();
    virtual void vfn_0d4();
    virtual void vfn_0d8();
    virtual void vfn_0dc();
    virtual void vfn_0e0();
    virtual void vfn_0e4();
    virtual void vfn_0e8();
    virtual void vfn_0ec();
    virtual bool vfn_f0();
    virtual void vfn_0f4();
    virtual void vfn_0f8();
    virtual void vfn_0fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual void vfn_1a0();
    virtual void vfn_1a4();
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc();
    virtual void vfn_1d0();
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual void vfn_1e4();
    virtual void vfn_1e8();
    virtual void vfn_1ec();
    virtual void vfn_1f0();
    virtual Pt3f* vfn_1f4();
    int FUN_00401170();
    unsigned int GetDetachTime();
    bool FUN_00425fd0();
    Obj84* FUN_0054ddd0();
    unsigned int FUN_00544c30();
    unsigned int FUN_00544c60();
    Obj84* FUN_008d6f30();
    Obj84* TESObjectREFR_GetWorldSpace();
    void TESObjectREFR_MoveToEditorLocation(int);
};
struct Buf84
{
    unsigned int Modelloader_GetReferencedThis();
    int BGSUnloadedFormBuffer_GetFormType();
    void* BGSUnloadedFormBuffer_GetAdvancedBuffer();
    void ClearBuffer_006665a0();
    unsigned char BGSUnloadedFormBuffer_GetVersion();
    unsigned int BGSUnloadedFormBuffer_GetSize();
    void BGSUnloadedFormBuffer_Initialize(unsigned int, unsigned int, unsigned int, unsigned char);
};
struct FormChanges84
{
    FormChangeMask flags;
    Buf84 buffer;
    bool FUN_004280f0(unsigned int);
    unsigned int Modelloader_GetReferencedThis();
    bool FUN_00822510(int);
    void FUN_00562210(unsigned int);
};

struct RefMap84 : public BGSSaveLoadReferencesMap
{
    bool BGSSaveLoadReferencesMap_RemoveMovedReference(unsigned int);
    void RemoveReferenceFromCell(unsigned int, unsigned int, const Pt3f&);
    void BGSSaveLoadReferencesMap_RemoveReference(unsigned int, unsigned int);
};
struct Map84 : public FUN_0084ba20
{
    int f04;
    int f08;
    int f0c;
    Map84(int);
    virtual ~Map84();
    void InsertOrUpdate(unsigned __int64, unsigned int);
    bool FindValueByKey(unsigned __int64, unsigned int*);
    void FUN_00438af0();
};
struct S84
{
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    Pt3f pt;
    int f20;
    int f24;
    int f28;
    int f2c;
    void FUN_00849280();
};
struct S84mini
{
    int a;
    int b;
    int c;
    int d;
};
struct Calendar
{
    unsigned int FUN_00867e30();
};
extern Calendar g_calendar;
struct DH84
{
    bool FUN_00469860(unsigned int);
};
Form84* __cdecl TESForm_GetFormByNumericID(unsigned int);
int __cdecl BGSSaveLoadInitialData_GetInitialDataType(unsigned int, int, unsigned int);
int __cdecl BGSSaveLoadInitialData_LoadInitialDataStruct(void*, int, void*);
unsigned int __cdecl TESObjectCELL_GetHoursToRespawnCell();
int __cdecl PackShortPair(short, short);
int __cdecl FloatToInt(float);
unsigned int __cdecl BGSSaveLoadInitialData_GetInitialDataTypeDataSize(int);
unsigned int __cdecl FUN_00846080(unsigned int, unsigned int*);
void __cdecl FUN_0084dff0(void*, const char*, ...);
void __cdecl _fnv_call_845cc0(const char*, ...);


}  // namespace fnv_0084ab20

// @fnv 0x0084ab20
void BGSSaveLoadGame::CleanupExpiredData()
{
    using namespace fnv_0084ab20;
    bool allowOld = SetThreadAllowChanges(false);
    Map84 map(0x25);
    unsigned int start = g_calendar.FUN_00867e30();
    int count1 = 0;
    void* posA = pChangesMap->GetFirstPos();
    while (posA != 0)
    {
        unsigned int fid = 0;
        FormChanges84* value = 0;
        pChangesMap->GetNext(posA, fid, reinterpret_cast<FormChangeRecord*&>(value));
        unsigned int idCopy = fid;
        if (value->FUN_004280f0(0x40000000))
        {
            unsigned int size = 0;
            unsigned int maxXA = 0x7fffffff;
            unsigned int fi = 0x7fffffff;
            if (value->buffer.Modelloader_GetReferencedThis() != 0)
            {
                if (value->buffer.BGSUnloadedFormBuffer_GetFormType() == 0x39)
                {
                    int res = fnv_0084ab20::BGSSaveLoadInitialData_GetInitialDataType(fid, 0x39, *(unsigned int*)value);
                    if (res != 0)
                    {
                        S84mini mini;
                        fnv_0084ab20::BGSSaveLoadInitialData_LoadInitialDataStruct(value->buffer.BGSUnloadedFormBuffer_GetAdvancedBuffer(), res, &mini);
                        size = (unsigned int)mini.d;
                        if (res != 3)
                        {
                            idCopy = (unsigned int)mini.a;
                            maxXA = (unsigned int)mini.b;
                            fi = (unsigned int)mini.c;
                        }
                    }
                }
            }
            else
            {
                Form84* form = fnv_0084ab20::TESForm_GetFormByNumericID(fid);
                if (form != 0)
                {
                    if (form->FUN_00401170() == 0x39)
                    {
                        Form84* cell = form;
                        size = cell->GetDetachTime();
                        if (!cell->FUN_00425fd0())
                        {
                            idCopy = cell->FUN_0054ddd0()->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
                            maxXA = cell->FUN_00544c30();
                            fi = cell->FUN_00544c60();
                        }
                    }
                }
            }
            if (size != 0)
            {
                if (start - size > TESObjectCELL_GetHoursToRespawnCell())
                {
                    unsigned __int64 key = (unsigned __int64)idCopy;
                    if (maxXA != 0x7fffffff)
                    {
                        __int64 t = PackShortPair((short)maxXA, (short)fi);
                        key |= (t << 32);
                    }
                    map.InsertOrUpdate(key, size);
                    count1 = count1 + 1;
                }
            }
        }
    }
    if (count1 != 0)
    {
        int countA = 0;
        int countB = 0;
        int countC = 0;
        posA = pChangesMap->GetFirstPos();
        while (posA != 0)
        {
            unsigned int fm;
            FormChanges84* ev;
            unsigned int eg;
            unsigned int es;
            unsigned int ej;
            Form84* ft;
            unsigned int ek;
            fm = 0;
            ev = 0;
            pChangesMap->GetNext(posA, fm, reinterpret_cast<FormChangeRecord*&>(ev));
            if (((DH84*)g_dataHandler)->FUN_00469860(fm))
                continue;
            eg = 0;
            es = 0;
            ej = 0;
            ft = 0;
            ek = 0;
            if (ev->buffer.Modelloader_GetReferencedThis() != 0)
            {
                ek = (unsigned int)ev->buffer.BGSUnloadedFormBuffer_GetFormType();
            }
            else
            {
                Form84* formT = fnv_0084ab20::TESForm_GetFormByNumericID(fm);
                if (formT != 0)
                {
                    ek = (unsigned int)formT->FUN_00401170();
                    if (formT->vfn_f0())
                    {
                        ft = formT;
                    }
                }
                else
                {
                    fnv_0084ab20::_fnv_call_845cc0(
                        "During cleanup, form %08X with changeflags %08X and no unloaded form buffer could not be found",
                        fm, ev->Modelloader_GetReferencedThis());
                }
            }
            if (ek == 0x3a)
            {
                if (ev->buffer.Modelloader_GetReferencedThis() != 0)
                {
                    int resA4 = fnv_0084ab20::BGSSaveLoadInitialData_GetInitialDataType(fm, (int)ek, *(unsigned int*)ev);
                    if (resA4 != 0)
                    {
                        S84 info;
                        info.FUN_00849280();
                        fnv_0084ab20::BGSSaveLoadInitialData_LoadInitialDataStruct(ev->buffer.BGSUnloadedFormBuffer_GetAdvancedBuffer(), resA4, &info);
                        eg = (unsigned int)info.f00;
                        es = (unsigned int)(FloatToInt(info.pt.x) >> 12);
                        ej = (unsigned int)(FloatToInt(info.pt.y) >> 12);
                    }
                }
                else if (ft != 0)
                {
                    Obj84* cellB = ft->FUN_008d6f30();
                    Obj84* worldB = ft->TESObjectREFR_GetWorldSpace();
                    if (cellB != 0 && cellB->FUN_00425fd0())
                    {
                        eg = cellB->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
                    }
                    else if (worldB != 0)
                    {
                        eg = worldB->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
                        Pt3f ptT = *ft->vfn_1f4();
                        es = (unsigned int)(FloatToInt(ptT.x) >> 12);
                        ej = (unsigned int)(FloatToInt(ptT.y) >> 12);
                    }
                }
            }
            if (eg != 0)
            {
                unsigned __int64 key2 = (unsigned __int64)eg;
                if (es != 0x7fffffff)
                {
                    __int64 t2 = PackShortPair((short)es, (short)ej);
                    key2 |= (t2 << 32);
                }
                unsigned int outVal = 0;
                if (map.FindValueByKey(key2, &outVal) && ev->FUN_004280f0(4) && !ev->FUN_004280f0(2))
                {
                    countA = countA + 1;
                    int res100 = fnv_0084ab20::BGSSaveLoadInitialData_GetInitialDataType(fm, (int)ek, *(unsigned int*)ev);
                    S84 info2;
                    info2.FUN_00849280();
                    if (ev->buffer.Modelloader_GetReferencedThis() != 0 && res100 == 6)
                    {
                        fnv_0084ab20::BGSSaveLoadInitialData_LoadInitialDataStruct(ev->buffer.BGSUnloadedFormBuffer_GetAdvancedBuffer(), res100, &info2);
                        ((RefMap84*)pReferencesMap)->BGSSaveLoadReferencesMap_RemoveMovedReference(fm);
                        Form84* formX = fnv_0084ab20::TESForm_GetFormByNumericID((unsigned int)info2.f00);
                        if (formX != 0 && formX->FUN_00401170() == 0x41)
                        {
                            ((RefMap84*)pReferencesMap)
                                ->RemoveReferenceFromCell((unsigned int)info2.f00, fm, info2.pt);
                        }
                        else
                        {
                            ((RefMap84*)pReferencesMap)->BGSSaveLoadReferencesMap_RemoveReference((unsigned int)info2.f00, fm);
                        }
                    }
                    if (ev->FUN_00822510(4))
                    {
                        pChangesMap->HasFormChanges(fm);
                        countB = countB + 1;
                    }
                    else
                    {
                        if (ev->buffer.Modelloader_GetReferencedThis() != 0 && res100 != 0)
                        {
                            unsigned int bx;
                            unsigned int bo;
                            unsigned int bb;
                            unsigned int as;
                            unsigned int am;
                            unsigned int ah;
                            unsigned char pC;
                            unsigned int len;
                            unsigned int pA;
                            bb = (unsigned int)ev->buffer.BGSUnloadedFormBuffer_GetAdvancedBuffer();
                            len = BGSSaveLoadInitialData_GetInitialDataTypeDataSize(res100);
                            bb += len;
                            as = 0;
                            am = FUN_00846080(bb, &as);
                            bb = am + as + bb;
                            ah = ev->buffer.Modelloader_GetReferencedThis();
                            pC = ev->buffer.BGSUnloadedFormBuffer_GetVersion();
                            pA = ev->buffer.BGSUnloadedFormBuffer_GetSize();
                            bo = pA - len - am - as;
                            ev->buffer.ClearBuffer_006665a0();
                            ev->buffer.BGSUnloadedFormBuffer_Initialize(bb, bo, ek, pC);
                            bx = ah;
                            operator delete((void*)bx);
                            countC = countC + 1;
                        }
                        ev->FUN_00562210(0xc);
                    }
                    if (ft != 0)
                    {
                        ft->TESObjectREFR_MoveToEditorLocation(0);
                    }
                }
            }
        }
        if (countA != 0)
        {
            fnv_0084ab20::FUN_0084dff0(
                pHistory,
                "CleanupExpiredData removed havok from %i refs: %i removed all changes and %i unloaded refs removed partial changes",
                countA, countB, countC);
        }
    }
    map.FUN_00438af0();
    SetThreadAllowChanges(allowOld);
}


namespace fnv_00848e70 {
class RevertLoadFormBuffer
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    RevertLoadFormBuffer();
    ~RevertLoadFormBuffer();
    void SetForm(TESForm*);
    void SetSource(unsigned int);
    void SetMode(int);
};
class RevertFormChangesView
{
  public:
    unsigned int unk00;
    char* unk04;
    bool TestFormChangeFlags(TESForm*);
    void BGSReconstructFormsInAllFilesMap_AddForm(TESForm*, int);
    void BGSReconstructFormsInAllFilesMap_AddReference(TESForm*, unsigned int, int);
    void FUN_008439e0();
    void Clear();
};
class ReconstructScratch
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    void FUN_00849280();
    void ReferenceInitialData_GetOriginalLocationCellAndWorld(TESForm**, unsigned int*);
};
class SourceData
{
  public:
    unsigned int unk00;
    char* BGSUnloadedFormBuffer_GetAdvancedBuffer();
};
class StringRef
{
  public:
    char* pString;
    const char* String() const;
    char* BGSUnloadedFormBuffer_GetFormType();
};
class DataHandlerOps
{
  public:
    bool FUN_00469860(unsigned int);
};
// The shared map does not declare this buffer-output overload.
class SaveLoadChangesMapSourceAccess : public BGSSaveLoadChangesMap
{
  public:
    void BGSSaveLoadChangesMap_GetChangeBuffer(SourceData*, unsigned int);
};
class FormTypeOps
{
  public:
    int FNV_GetFormType();
};
class CF845
{
  public:
    unsigned int unk00;
    CF845(int);
    CF845(const CF845&);
};

extern TESForm* __cdecl TESForm_GetFormByNumericID(unsigned int);

extern int __cdecl BGSSaveLoadInitialData_GetInitialDataType(unsigned int, const char*, unsigned int);
extern void __cdecl BGSSaveLoadInitialData_LoadInitialDataStruct(char*, int, ReconstructScratch*);
extern void __cdecl FUN_00841120(unsigned int*, unsigned int, CF845, int, int);
extern TES* g_TES;

}  // namespace fnv_00848e70

// Iterates pMap, reverting or reconstructing forms into changes and pFileMap, then clears pFileMap and swaps pMap to changes.
// @fnv 0x00848e70
// src: XBOX_PDB 0x00848e70
void BGSSaveLoadGame::RevertCurrentChanges(int changes, int file)
{
    using namespace fnv_00848e70;
    if (!((BGSSaveLoadChangesMap*&)changes))
        ((BGSSaveLoadChangesMap*&)changes) = new BGSSaveLoadChangesMap;
    void* pos = pChangesMap->GetFirstPos();
    while (pos)
    {
        TESForm* current;
        unsigned int form = 0;
        RevertFormChangesView* key = 0;
        pChangesMap->GetNext(pos, form, reinterpret_cast<FormChangeRecord*&>(key));
        current = fnv_00848e70::TESForm_GetFormByNumericID(form);
        if (current)
        {
            if (((DataHandlerOps*)g_dataHandler)->FUN_00469860(form))
            {
                ClearForm(current);
                ((BGSSaveLoadChangesMap*&)changes)->HasFormChanges(form);
                continue;
            }
            RevertLoadFormBuffer buffer;
            buffer.SetForm(current);
            buffer.SetSource(key->unk00);
            buffer.SetMode(1);
            current->Revert((BGSLoadFormBuffer*)&buffer);
            unsigned int name;
            fnv_00848e70::FUN_00841120(&name, key->unk00, fnv_00848e70::CF845(0), ((FormTypeOps*)current)->FNV_GetFormType(), 0);
            if (((BSStringT<char>*)&name)->String())
            {
                if (!FindFormByID(&current, name, true))
                {
                    if (current)
                        ((RevertFormChangesView*)pReconstructForms)->BGSReconstructFormsInAllFilesMap_AddForm(current, 8);
                }
            }
            if (current && key->TestFormChangeFlags(current))
                ((BGSSaveLoadChangesMap*&)changes)->AddFormChangeFlags(form, reinterpret_cast<FormChangeMask&>(key->unk00));
        }
        else if (!current && ((TESFile*)file))
        {
            StringRef name;
            name.pString = key->unk04;
            if (name.String())
            {
                int type = fnv_00848e70::BGSSaveLoadInitialData_GetInitialDataType(form, name.BGSUnloadedFormBuffer_GetFormType(), key->unk00);
                if (type == 6)
                {
                    TESFile* source = ((TESFile*&)pFormIDMap);
                    ((TESFile*&)pFormIDMap) = ((TESFile*)file);
                    SourceData more;
                    unsigned int old;
                    ((SaveLoadChangesMapSourceAccess*)pChangesMap)->BGSSaveLoadChangesMap_GetChangeBuffer(&more, form);
                    {
                        ReconstructScratch scratch;
                        scratch.FUN_00849280();
                        fnv_00848e70::BGSSaveLoadInitialData_LoadInitialDataStruct(more.BGSUnloadedFormBuffer_GetAdvancedBuffer(), type, &scratch);
                        TESForm* reconstructed = 0;
                        old = 0;
                        scratch.ReferenceInitialData_GetOriginalLocationCellAndWorld(&reconstructed, &old);
                        if (reconstructed)
                        {
                            if (g_TES->FUN_004511e0(reconstructed, 0))
                                ((RevertFormChangesView*)pReconstructForms)->BGSReconstructFormsInAllFilesMap_AddReference(reconstructed, form, 8);
                        }
                    }
                    ((TESFile*&)pFormIDMap) = source;
                }
            }
        }
    }
    ((RevertFormChangesView*)pReconstructForms)->FUN_008439e0();
    ((RevertFormChangesView*)pReconstructForms)->Clear();
    delete pChangesMap;
    pChangesMap = ((BGSSaveLoadChangesMap*&)changes);
}


// Looks up aiOldFormID in the changed-form map and returns its new ID, or 0 on failure.
// @fnv 0x0084aa90
unsigned int BGSSaveLoadGame::GetNewFormID(unsigned int aiOldFormID)
{
    unsigned int value = 0;
    if (((NiTPointerMap<unsigned int, unsigned int>*)pChangedFormIDMap)->GetAt(aiOldFormID, value))
        return value;
    return 0;
}

int __fastcall FNV_GetFormType(TESForm* form);
const char* __cdecl GetStringForByte(unsigned char formType);
void __cdecl _fnv_call_845cc0(const char*, ...);

static const char kRenumberedMsg[] =
    "FORMS: Form %08X with form type %i %s was re-numbered by BGSSaveLoadGame::ClearForm()";


// Deletes forms of listed types, assigns new IDs to listed types and others, and logs for the default case.
// @fnv 0x0084a880
void BGSSaveLoadGame::ClearForm(TESForm* form)
{
    if (!form)
        return;
    int formType = FNV_GetFormType(form);
    switch (formType)
    {
    case ENUM_FORM_ID_REFR_ID:
    case ENUM_FORM_ID_ACHR_ID:
    case ENUM_FORM_ID_ACRE_ID:
    case ENUM_FORM_ID_PMIS_ID:
    case ENUM_FORM_ID_PGRE_ID:
    case ENUM_FORM_ID_PBEA_ID:
    case ENUM_FORM_ID_PFLA_ID:
    case ENUM_FORM_ID_PACK_ID:
    case ENUM_FORM_ID_PCBE_ID:
        DeleteForm(form);
        break;
    case ENUM_FORM_ID_TXST_ID:
    case ENUM_FORM_ID_SCPT_ID:
    case ENUM_FORM_ID_LTEX_ID:
    case ENUM_FORM_ID_NPC__ID:
    case ENUM_FORM_ID_CREA_ID:
    case ENUM_FORM_ID_CELL_ID:
    case ENUM_FORM_ID_LAND_ID:
    case ENUM_FORM_ID_NAVM_ID:
        form->SetRefID(((TESDataHandlerSaveLoad*)g_dataHandler)->GetNextID(), true);
        break;
    default:
        _fnv_call_845cc0(kRenumberedMsg, form->GetFormID(), formType,
                         GetStringForByte(static_cast<unsigned char>(formType)));
        form->SetRefID(((TESDataHandlerSaveLoad*)g_dataHandler)->GetNextID(), true);
        break;
    }
}
