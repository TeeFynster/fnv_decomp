// fallout/misc/saveload/bgssaveloadinitialdata.cpp: BGSSaveLoadInitialData, ReferencePlacementData, BGSNumericIDIndex3 (20 functions)

#include "../../../../include/MobileObject.h"
#include "../../../../include/Actor.h"
#include "../../../../include/Explosion.h"
#include "../../../../include/BGSSaveFormBuffer.h"

#include "../../../../include/BGSChangeFlags.h"
#include "../../../../include/BGSLoadFormBuffer.h"
#include "../../../../include/BGSSaveLoadGame.h"
#include "../../../../include/ExtraDataList.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/PlayerCharacter.h"
#include "../../../../include/TES.h"
#include "../../../../include/TESBoundObject.h"
#include "../../../../include/TESDataHandler.h"
#include "../../../../include/TESForm.h"
#include "../../../../include/TESObjectCELL.h"
#include "../../../../include/TESObjectREFR.h"
#include "../../../../include/TESRecipe.h"
#include "../../../../include/TESWorldSpace.h"

#include "bgssaveloadinitialdata_packet.h"
// @fnv 0x0084e700
INITIAL_DATA_TYPE BGSSaveLoadInitialData::DetermineInitialDataType(TESForm* apForm, InitialDataChangeMask eChangeFlags)
{
    return DetermineInitialDataType(apForm->GetFormID(), ((const TESForm*)apForm)->GetFormType(), eChangeFlags);
}

// @fnv 0x00849280
ReferencePlacementData::ReferencePlacementData()
{}

// @fnv 0x0084e610
bool ReferencePlacementData::GetCellAndWorld(TESObjectCELL*& apCell, TESWorldSpace*& apWorld)
{
    bool bResult;
    TESForm* apForm = TESForm::GetFormByID(m_uiLocationFormID);
    bResult = GetCellAndWorldspaceForForm(apForm, apCell, apWorld);
    if (apWorld)
    {
        int x = TruncateFloatToInt(Location.x) >> 12;
        int y = TruncateFloatToInt(Location.y) >> 12;
        apCell = apWorld->GetCellAtGridPosition(x, y);
    }
    return bResult;
}

// Loads a cell or reference change record from the save buffer and applies its location, angle and cell/worldspace to the form.
// @fnv 0x0084f330
INITIAL_DATA_TYPE BGSSaveLoadInitialData::LoadInitialDataForForm(BGSLoadFormBuffer* apBuffer, TESForm* apForm,
                                                                       InitialDataChangeMask eChangeFlags)
{
    INITIAL_DATA_TYPE eType = DetermineInitialDataType(apForm, eChangeFlags);
    if (BGSSaveLoadInitialData_IsInitialDataCellType(eType))
    {
        CellDetachTimeData kCellData;
        LoadFormData(apBuffer, eType, &kCellData);
        TESObjectCELL* pLocationCell = (TESObjectCELL*)apForm;
        pLocationCell->SetDetachTime(kCellData.m_uiDetachTime, true);
    }
    else if (BGSSaveLoadInitialData_IsInitialDataRefType(eType))
    {
        ReferencePlacementData kRefData;
        LoadFormData(apBuffer, eType, &kRefData);
        TESWorldSpace* pWorld = 0;
        TESObjectCELL* pLocationCell = 0;
        kRefData.GetCellAndWorld(pLocationCell, pWorld);
        TESObjectREFR* m_pWorldReferenceInfo = (TESObjectREFR*)apForm;
        switch (eType)
        {
        case INITIAL_DATA_TYPE_INITIAL_DATA_CREATED_REFERENCE: {
            TESBoundObject* pBound =
                dynamic_cast<TESBoundObject*>(TESForm::GetFormByID(kRefData.m_uiBaseFormID));
            if (kRefData.m_ucFlags & 4)
            {
                m_pWorldReferenceInfo->SetLocationOnReference(kRefData.Location);
                m_pWorldReferenceInfo->SetReferencePosition(kRefData.Angle);
                if (pLocationCell)
                    m_pWorldReferenceInfo->SetParentCell(pLocationCell);
                else if (pWorld)
                    m_pWorldReferenceInfo->GetExtraData()->CallExtraDataListMethod35(pWorld->GetInteriorCell());
            }
            else
            {
                g_dataHandler->PlaceReferenceAtLocation(pBound, kRefData.Location, kRefData.Angle, pLocationCell,
                                                        pWorld, m_pWorldReferenceInfo, 0, 0);
            }
            if (!pLocationCell && !pWorld)
            {
                LogWarning(DAT_0107f938, m_pWorldReferenceInfo->GetFormID(), kRefData.m_uiBaseFormID,
                           pBound ? pBound->TESForm_GetFormTypeString() : DAT_01015890);
                m_pWorldReferenceInfo->FUN_0046a010(0);
                g_BGSSaveLoadGame->DeleteForm(m_pWorldReferenceInfo);
                ((TESRecipe*)apBuffer)->SetSkill(0);
                return eType;
            }
            m_pWorldReferenceInfo->PostLoad();
            if (m_pWorldReferenceInfo->IsActor())
                g_BGSSaveLoadGame->RemoveActorFromMap(m_pWorldReferenceInfo);
            break;
        }
        case INITIAL_DATA_TYPE_INITIAL_DATA_REFERENCE_LOCATION:
        case INITIAL_DATA_TYPE_INITIAL_DATA_MOVED_REFERENCE:
            if (m_pWorldReferenceInfo == g_thePlayer)
            {
                if (!g_BGSSaveLoadGame->BGSSaveLoadGame_GetPlayerLocationInvalid())
                {
                    m_pWorldReferenceInfo->SetReferencePosition(kRefData.Angle);
                    m_pWorldReferenceInfo->SetLocationOnReference(kRefData.Location);
                }
            }
            else
            {
                m_pWorldReferenceInfo->SetReferencePosition(kRefData.Angle);
                m_pWorldReferenceInfo->SetLocationOnReference(kRefData.Location);
            }
            m_pWorldReferenceInfo->PostLoad();
            if (m_pWorldReferenceInfo != g_thePlayer)
            {
                if (pLocationCell && pLocationCell->IsCellInterior())
                {
                    if (pLocationCell != m_pWorldReferenceInfo->GetParentCell())
                        TESObjectREFR::SetParentCellAndWorldspace(m_pWorldReferenceInfo, pLocationCell, 0);
                }
                else if (pWorld)
                {
                    if ((pLocationCell && (pLocationCell == m_pWorldReferenceInfo->GetParentCell() ||
                                           g_TES->IsCellBuffered(pLocationCell, false))) ||
                        m_pWorldReferenceInfo->GetReferencePersistence())
                    {
                        if (!pLocationCell || pLocationCell != m_pWorldReferenceInfo->GetParentCell())
                            TESObjectREFR::SetParentCellAndWorldspace(m_pWorldReferenceInfo, 0, pWorld);
                    }
                    else
                    {
                        LogWarning(DAT_0107f8d0, m_pWorldReferenceInfo->GetName(), m_pWorldReferenceInfo->GetFormID(), pWorld->GetName(),
                                   pWorld->GetFormID());
                        apBuffer->SetFlag10(1);
                    }
                }
                else
                {
                    LogWarning(DAT_0107f894, kRefData.m_uiLocationFormID, m_pWorldReferenceInfo->GetName(),
                               m_pWorldReferenceInfo->GetFormID());
                }
                if (m_pWorldReferenceInfo->GetNiNode() && (!pLocationCell || !g_TES->IsCellBuffered(pLocationCell, false)))
                {
                    m_pWorldReferenceInfo->Set3D(0, 0);
                }
                else if (m_pWorldReferenceInfo->GetNiNode() && m_pWorldReferenceInfo->IsActor())
                {
                    m_pWorldReferenceInfo->AnimateNiNode();
                }
            }
            if (m_pWorldReferenceInfo->IsActor())
            {
                TESObjectREFR* pActor = m_pWorldReferenceInfo;
                g_BGSSaveLoadGame->RemoveActorFromMap(pActor);
                // The shared MobileObject slot 0xA4 has a void declaration; this caller consumes its bool result.
                if (eType == INITIAL_DATA_TYPE_INITIAL_DATA_MOVED_REFERENCE && !((bool (__thiscall*)(TESObjectREFR*))(*(void***)pActor)[0xA4])(pActor))
                {
                    TESForm* pOriginal = TESForm::GetFormByID(kRefData.m_uiOriginalBaseFormID);
                    pActor->Actor_SetEditorLocationForm(pOriginal);
                }
            }
            break;
        }
        if (eChangeFlags.ContainsAnyFlags(4))
            g_BGSSaveLoadGame->QueueSubBuffer(2, apBuffer, 0);
    }
    else if (eType != INITIAL_DATA_TYPE_INITIAL_DATA_NONE)
    {
        LogWarning(DAT_0107f86c, eType);
    }
    return eType;
}

unsigned int __cdecl BGSSaveLoadInitialData_GetInitialDataTypeSize(int);

// @fnv 0x0084e800
// src: COMMUNITY 0x0084e800
unsigned int __cdecl BGSSaveLoadInitialData_GetInitialDataTypeDataSize(int aeType)
{
    unsigned int isize = BGSSaveLoadInitialData_GetInitialDataTypeSize(aeType);
    isize += 1;
    return isize;
}

unsigned int __cdecl BGSSaveLoadInitialData_GetInitialDataTypeSize(int);
int __cdecl BGSSaveLoadInitialData_LoadInitialDataStruct(void*, int, void*);

// If aeType is non-zero, reads isize bytes from apFile into pbuffer and passes them with aeType and apInitialDataBuffer to FUN_0084e930; returns 0 for aeType 0.
// @fnv 0x0084e8c0
int __cdecl LoadFormData(BGSLoadFormBuffer* apFile, int aeType, void* apInitialDataBuffer)
{
    unsigned int isize;
    char pbuffer[128];

    if (aeType == 0)
        return 0;

    isize = BGSSaveLoadInitialData_GetInitialDataTypeSize(aeType);
    apFile->ReadTypedData(pbuffer, isize);
    return BGSSaveLoadInitialData_LoadInitialDataStruct(pbuffer, aeType, apInitialDataBuffer);
}

extern bool DAT_011a2231[];

// @fnv 0x0084f840
// src: XBOX_PDB 0x0084f840
bool __cdecl BGSSaveLoadInitialData_IsInitialDataRefType(int aeType)
{
    return DAT_011a2231[aeType * 3];
}

extern bool DAT_011a2232[];

// @fnv 0x0084f860
// src: XBOX_PDB 0x0084f860
bool __cdecl BGSSaveLoadInitialData_IsInitialDataCellType(int aeType)
{
    return DAT_011a2232[aeType * 3];
}

struct BGSNumericIDIndex3
{
    unsigned char a;
    unsigned char b;
    unsigned char c;
};
// Sets the three bytes of the BGSNumericIDIndex3 to zero and returns the object.
// @fnv 0x0084eaf0
BGSNumericIDIndex3* __fastcall ClearNumericIDIndex(BGSNumericIDIndex3* self)
{
    self->a = 0;
    self->b = 0;
    self->c = 0;
    return self;
}

namespace fnv_0084eb20 {
struct BGSNumericIDIndex3
{
    BGSNumericIDIndex3* CreatedReferenceInitialData_CreatedReferenceInitialData();
    void ReferenceLocationInitialData_ReferenceLocationInitialData();
};
struct Dummy84eaf0
{
    void ClearNumericIDIndex();
};

// Calls FUN_0084eac0 on this object, then ClearNumericIDIndex on the sub-object at offset 0x1C, and returns this.
// @fnv 0x0084eb20
// src: COMMUNITY 0x0084eb20
BGSNumericIDIndex3* __thiscall BGSNumericIDIndex3::CreatedReferenceInitialData_CreatedReferenceInitialData()
{
    ReferenceLocationInitialData_ReferenceLocationInitialData();
    ((Dummy84eaf0*)((char*)this + 0x1C))->ClearNumericIDIndex();
    return this;
}
}  // namespace fnv_0084eb20

// Sets or clears the cell-changed bit in the load buffer flags.
// @fnv 0x0084f880
void BGSLoadFormBuffer::SetCellChanged(bool abSet)
{
    if (abSet)
        iFlags |= 0x10;
    else
        iFlags &= ~0x10;
}

// @fnv 0x0084f8c0
// src: XBOX_PDB 0x0084f8c0
void TESObjectREFR::Actor_SetEditorLocationForm(TESForm* value)
{
    ((Actor*)this)->FormReferenceState = value;
}

struct FUN_0084e6a0_shell
{
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    bool ReferenceInitialData_GetOriginalLocationCellAndWorld(TESObjectCELL*& cell, TESWorldSpace*& world);
};

// @fnv 0x0084e6a0
// src: XBOX_PDB 0x0084e6a0
bool FUN_0084e6a0_shell::ReferenceInitialData_GetOriginalLocationCellAndWorld(TESObjectCELL*& cell, TESWorldSpace*& world)
{
    TESForm* form = TESForm::GetFormByID(f8);
    bool bResolved = GetCellAndWorldspaceForForm(form, cell, world);
    if (world)
    {
        cell = reinterpret_cast<TESWorldSpace*>(world)->GetCellAtGridPosition(fC, f10);
    }
    return bResolved;
}

extern "C" char DAT_011a2230[];

// @fnv 0x0084e830
// src: XBOX_PDB 0x0084e830
unsigned int BGSSaveLoadInitialData_GetInitialDataTypeSize(int aiIndex)
{
    return (unsigned char)DAT_011a2230[aiIndex * 3];
}

struct Dummy84eaf0
{
    void ClearNumericIDIndex();
    char _pad[3];
};

#pragma pack(push, 1)
struct Outer84eac0 : Dummy84eaf0
{
    NiPoint3 m1;
    NiPoint3 m2;
    Outer84eac0* ReferenceLocationInitialData_ReferenceLocationInitialData();
};
#pragma pack(pop)
// Calls ClearNumericIDIndex, then invokes FUN_006815c0 on m1 and m2, and returns this.
// @fnv 0x0084eac0
// src: COMMUNITY 0x0084eac0
Outer84eac0* Outer84eac0::ReferenceLocationInitialData_ReferenceLocationInitialData()
{
    Dummy84eaf0::ClearNumericIDIndex();
    m1.FUN_006815c0();
    m2.FUN_006815c0();
    return this;
}

namespace fnv_0084eb50 {
struct Dummy84eaf0
{
    void ClearNumericIDIndex();
};
struct Base84eac0
{
    void ReferenceLocationInitialData_ReferenceLocationInitialData();
};
struct S84eb50
{
    char _pad[0x1B];
    Dummy84eaf0 m;
    S84eb50* MovedReferenceInitialData_MovedReferenceInitialData();
};
// Calls the base FUN_0084eac0, then calls ClearNumericIDIndex on member m, and returns this.
// @fnv 0x0084eb50
// src: COMMUNITY 0x0084eb50
S84eb50* S84eb50::MovedReferenceInitialData_MovedReferenceInitialData()
{
    ((Base84eac0*)this)->ReferenceLocationInitialData_ReferenceLocationInitialData();
    m.ClearNumericIDIndex();
    return this;
}
}  // namespace fnv_0084eb50

class GameFileBuf
{
  public:
    void FUN_00846300(void* apBuffer, unsigned int auiModule);
};

unsigned int __cdecl BGSSaveLoadInitialData_GetInitialDataTypeDataSize(int aeType);
int __cdecl BGSSaveLoadInitialData_LoadInitialDataStruct(void* apBuffer, int aeType, void* apInitialDataBuffer);

// @fnv 0x0084e850
// src: COMMUNITY 0x0084e850
unsigned int __cdecl BGSSaveLoadInitialData_LoadInitialDataStruct_0(GameFileBuf* apFile, int aeType, void* apInitialDataBuffer)
{
    char acBuffer[128];
    if (aeType == 0)
    {
        return 0;
    }
    volatile unsigned int uiModule3 = BGSSaveLoadInitialData_GetInitialDataTypeDataSize(aeType);
    apFile->FUN_00846300(acBuffer, uiModule3);
    return (unsigned int)BGSSaveLoadInitialData_LoadInitialDataStruct(acBuffer, aeType, apInitialDataBuffer);
}

struct ProjectileAccess
{
    int GetKindCode();
};

TESForm* __cdecl TESForm_GetFormByNumericID(unsigned int);
TESObjectREFR* __cdecl TESObjectREFR_CreateReference(unsigned char, bool);
void __cdecl SaveGameWarning(const char*, ...);
extern const char DAT_0107fa20[];
extern const char DAT_0107f9b8[];

TESBoundObject* __fastcall ExtraDataList_GetLevCreaOriginalBase(ExtraDataList*);

// @fnv 0x0084f8e0
TESForm* __cdecl ResolveReferenceForm(unsigned int formID, ReferencePlacementData* data, TESForm* existing)
{
    TESForm* form = existing;
    {
        unsigned char flags;
        {
            if (!form)
                form = TESForm_GetFormByNumericID(formID);
            if (g_dataHandler->FUN_00469860(data->m_uiBaseFormID))
                data->m_uiBaseFormID = 0;
            TESBoundObject* bound = dynamic_cast<TESBoundObject*>(TESForm_GetFormByNumericID(data->m_uiBaseFormID));
            if (!bound)
            {
                SaveGameWarning(DAT_0107fa20, data->m_uiBaseFormID, formID);
                return 0;
            }
            if (form)
            {
                bool remove = false;
                if (!((TESObjectREFR*)form)->GetIsReference())
                    remove = true;
                else
                {
                    TESObjectREFR* ref = (TESObjectREFR*)form;
                    {
                        TESBoundObject* current = ref->BGSSaveFormBuffer_GetForm();
                        if (current != bound)
                        {
                            if (!ref->IsActor() || ExtraDataList_GetLevCreaOriginalBase(ref->BSFile_GetDevice()) != bound)
                                remove = true;
                        }
                    }
                }
                if (remove)
                {
                    g_BGSSaveLoadGame->ClearForm(form);
                    form = 0;
                }
            }
            flags = data->m_ucFlags;
            if (!form)
            {
                TESObjectREFR* created = 0;
                {
                    int type = 58;
                    switch (((const TESForm*)bound)->GetFormType())
                    {
                    case ENUM_FORM_ID_CREA_ID:
                        type = 60;
                        break;
                    case ENUM_FORM_ID_NPC__ID:
                        type = 59;
                        break;
                    case ENUM_FORM_ID_PROJ_ID: {
                        ProjectileAccess* projectile = (ProjectileAccess*)bound;
                        type = projectile->GetKindCode();
                        break;
                    }
                    case ENUM_FORM_ID_EXPL_ID:
                        created = new Explosion;
                        break;
                    }
                    if (flags & 4)
                        type = 22;
                    if (flags & 3)
                    {
                        if (!created)
                            created = TESObjectREFR_CreateReference((unsigned char)type, true);
                        ((TESObjectREFR*)created)->TESObjectREFR_SetObjectReference(bound);
                        ((TESObjectREFR*)created)->SetRefID(formID, true);
                        form = created;
                    }
                    else
                        SaveGameWarning(DAT_0107f9b8, flags, formID, data->m_uiBaseFormID, data->m_uiLocationFormID);
                }
            }
            if (form && (flags & 2))
            {
                TESObjectREFR* deleted = (TESObjectREFR*)form;
                deleted->SetPersistentFlag(true);
            }
            if (form)
                ((TESObjectREFR*)form)->FUN_0046a010(1);
        }
    }
    return form;
}

void __cdecl SaveGameWarning(const char*, ...);

struct BGSSaveLoadGame_SubAccessor
{
    unsigned short FUN_00846c90(unsigned int);
};

struct FUN_00853570_shell
{
    void WriteFormIDBytes(unsigned int);
};

// Save-specific entry point not declared by the shared ExtraDataList header.
struct ExtraDataListSaveAccess : ExtraDataList
{
    char* ExtraDataList_GetSavedHavokData();
};

class FakeBGSLoadGameSubBuffer
{
  public:
    void WriteToSaveGameBuffer(BGSSaveFormBuffer*);
};

class CF845 : public FakeBGSLoadGameSubBuffer
{
  public:
    void* unk0;
    CF845(char*);
    void* Modelloader_GetReferencedThis();
};

TESWorldSpace* __fastcall TESObjectREFR_GetWorldSpace(TESObjectREFR*);
TESBoundObject* __fastcall ExtraDataList_GetLevCreaOriginalBase(ExtraDataList*);

struct ExteriorCellCharData
{
    unsigned short worldID;
    char cellX;
    char cellY;
    unsigned int detachTime;
};

struct ExteriorCellShortData
{
    unsigned short worldID;
    short cellX;
    short cellY;
    unsigned short detachTimeLow;
    unsigned short detachTimeHigh;
};

struct Byte4
{
    unsigned char a, b, c, d;
};
struct Byte12
{
    Byte4 p0, p1, p2;
};

struct RefLocData
{
    unsigned char id0, id1, id2;
    Byte12 pos;
    Byte12 rot;
    RefLocData* ReferenceLocationInitialData_ReferenceLocationInitialData();
};

struct CreatedRefInitialData
{
    RefLocData base;
    unsigned char flags;
    unsigned char bound0, bound1, bound2;
    CreatedRefInitialData* CreatedReferenceInitialData_CreatedReferenceInitialData();
};

struct MovedRefInitialData
{
    RefLocData base;
    unsigned char orig0, orig1, orig2;
    short originalCellX;
    short originalCellY;
    MovedRefInitialData* MovedReferenceInitialData_MovedReferenceInitialData();
};

// Save-specific entry point not declared by the shared TESObjectREFR header.
struct TESObjectREFRSaveAccess : TESObjectREFR
{
    void TESObjectREFR_SaveHavokData(BGSSaveFormBuffer*);
};

// Determines the initial-data type for a form, writes the matching cell or reference record to the save buffer, and optionally saves extra data.
// @fnv 0x0084eb80
// src: XBOX_PDB 0x0084eb80
INITIAL_DATA_TYPE __cdecl BGSSaveLoadInitialData_SaveInitialData(BGSSaveFormBuffer* apFile, TESForm* apForm, InitialDataChangeMask eChangeFlags)
{
    INITIAL_DATA_TYPE eType = BGSSaveLoadInitialData::DetermineInitialDataType(apForm, eChangeFlags);
    switch (eType)
    {
    case INITIAL_DATA_TYPE_INITIAL_DATA_EXTERIOR_CELL_CHAR: {
        ExteriorCellCharData data;
        TESObjectCELL* cell = (TESObjectCELL*)apForm;
        data.worldID = ((BGSSaveLoadGame_SubAccessor*)g_BGSSaveLoadGame->GetHavokWorldObjectCountInSceneGraph_0084e3a0())
                           ->FUN_00846c90(cell->GetParentWorldSpace()->GetFormID());
        data.cellX = (char)cell->GetCellGridX();
        data.cellY = (char)cell->GetCellGridY();
        data.detachTime = cell->GetDetachTime();
        apFile->SaveData(&data, sizeof(data), 0);
        break;
    }
    case INITIAL_DATA_TYPE_INITIAL_DATA_EXTERIOR_CELL_SHORT: {
        ExteriorCellShortData data;
        TESObjectCELL* cell = (TESObjectCELL*)apForm;
        data.worldID = ((BGSSaveLoadGame_SubAccessor*)g_BGSSaveLoadGame->GetHavokWorldObjectCountInSceneGraph_0084e3a0())
                           ->FUN_00846c90(cell->GetParentWorldSpace()->GetFormID());
        data.cellX = cell->GetCellGridX();
        data.cellY = cell->GetCellGridY();
        *(unsigned int*)&data.detachTimeLow = cell->GetDetachTime();
        apFile->SaveData(&data, sizeof(data), 0);
        break;
    }
    case INITIAL_DATA_TYPE_INITIAL_DATA_INTERIOR_CELL: {
        TESObjectCELL* pCell = (TESObjectCELL*)apForm;
        unsigned int detachTime = pCell->GetDetachTime();
        apFile->SaveData(&detachTime, sizeof(detachTime), 0);
        break;
    }
    case INITIAL_DATA_TYPE_INITIAL_DATA_REFERENCE_LOCATION: {
        TESObjectREFR* pRefr = (TESObjectREFR*)apForm;
        TESForm* cell = (TESForm*)TESObjectREFR_GetWorldSpace(pRefr);
        if (!cell)
        {
            cell = (TESForm*)pRefr->GetParentCell();
        }
        NiPoint3 pos3 = *pRefr->GetPos();
        NiPoint3 rot_2 = *pRefr->FUN_00430830();
        if (!cell)
        {
            if (!pRefr->GetStartingPosition(&pos3, &rot_2, &cell, 0))
            {
                cell = (TESForm*)TESObjectREFR_GetWorldSpace((TESObjectREFR*)g_thePlayer);
                if (!cell)
                {
                    cell = (TESForm*)((TESObjectREFR*)g_thePlayer)->GetParentCell();
                }
                pos3 = *pRefr->GetPos();
                rot_2 = *pRefr->FUN_00430830();
            }
        }
        RefLocData refData;
        refData.ReferenceLocationInitialData_ReferenceLocationInitialData();
        ((FUN_00853570_shell*)&refData)->WriteFormIDBytes(cell->GetFormID());
        *(NiPoint3*)&refData.pos = pos3;
        *(NiPoint3*)&refData.rot = rot_2;
        apFile->SaveData(&refData, 0x1b, 0);
        break;
    }
    case INITIAL_DATA_TYPE_INITIAL_DATA_CREATED_REFERENCE: {
        TESObjectREFR* pRefr = (TESObjectREFR*)apForm;
        TESForm* kLoc = (TESForm*)TESObjectREFR_GetWorldSpace(pRefr);
        if (!kLoc)
        {
            kLoc = (TESForm*)pRefr->GetParentCell();
        }
        CreatedRefInitialData createdRefData;
        createdRefData.CreatedReferenceInitialData_CreatedReferenceInitialData();
        ((FUN_00853570_shell*)&createdRefData)->WriteFormIDBytes(kLoc->GetFormID());
        *(NiPoint3*)&createdRefData.base.pos = *((const TESObjectREFR*)pRefr)->GetPos();
        *(NiPoint3*)&createdRefData.base.rot = *pRefr->FUN_00430830();
        TESBoundObject* baseObject3 = pRefr->GetObjectReference();
        if (pRefr->IsActor() && ((BGSChangeFlags*)&eChangeFlags)->Test(0x40000))
        {
            TESBoundObject* boundObj4 = ExtraDataList_GetLevCreaOriginalBase(pRefr->GetExtraData());
            if (boundObj4)
            {
                baseObject3 = boundObj4;
            }
        }
        ((FUN_00853570_shell*)&createdRefData.bound0)->WriteFormIDBytes(baseObject3->GetFormID());
        createdRefData.flags = 1;
        if (pRefr->TESObjectREFR_GetRefPersists_005653d0())
        {
            createdRefData.flags |= 2;
        }
        if (pRefr->IsMobileObject())
        {
            TESObjectREFR* aTalkingRef = pRefr;
            if (((MobileObject*)aTalkingRef)->MobileObject_IsTalkingActivator())
            {
                createdRefData.flags |= 4;
            }
        }
        apFile->SaveData(&createdRefData, 0x1f, 0);
        break;
    }
    case INITIAL_DATA_TYPE_INITIAL_DATA_MOVED_REFERENCE: {
        TESObjectREFR* pRefr = (TESObjectREFR*)apForm;
        TESForm* locMain = (TESForm*)TESObjectREFR_GetWorldSpace(pRefr);
        if (!locMain)
        {
            locMain = (TESForm*)pRefr->GetParentCell();
        }
        NiPoint3 pos3 = *pRefr->GetPos();
        NiPoint3 rot_2 = *pRefr->FUN_00430830();
        if (!locMain)
        {
            if (!pRefr->GetStartingPosition(&pos3, &rot_2, &locMain, 0))
            {
                locMain = (TESForm*)TESObjectREFR_GetWorldSpace((TESObjectREFR*)g_thePlayer);
                if (!locMain)
                {
                    locMain = (TESForm*)((TESObjectREFR*)g_thePlayer)->GetParentCell();
                }
                pos3 = *pRefr->GetPos();
                rot_2 = *pRefr->FUN_00430830();
            }
        }
        MovedRefInitialData movedRefDataTmp;
        movedRefDataTmp.MovedReferenceInitialData_MovedReferenceInitialData();
        ((FUN_00853570_shell*)&movedRefDataTmp)->WriteFormIDBytes(locMain->GetFormID());
        *(NiPoint3*)&movedRefDataTmp.base.pos = pos3;
        *(NiPoint3*)&movedRefDataTmp.base.rot = rot_2;
        NiPoint3 editorPos;
        NiPoint3 editorRot5;
        TESForm* editorCell = 0;
        if (pRefr->GetStartingPosition(&editorPos, &editorRot5, &editorCell, 0))
        {
            ((FUN_00853570_shell*)&movedRefDataTmp.orig0)->WriteFormIDBytes(editorCell->GetFormID());
            movedRefDataTmp.originalCellX = (short)(TruncateFloatToInt(editorPos.x) >> 12);
            movedRefDataTmp.originalCellY = (short)(TruncateFloatToInt(editorPos.y) >> 12);
        }
        else
        {
            movedRefDataTmp.originalCellX = 0;
            movedRefDataTmp.originalCellY = 0;
            SaveGameWarning("EDITOR: Could not get editor location for reference '%s' (%08X) of type '%s' (%08X)",
                         pRefr->GetName(), pRefr->GetFormID(), pRefr->GetObjectReference()->GetName(),
                         pRefr->GetObjectReference()->GetFormID());
        }
        apFile->SaveData(&movedRefDataTmp, 0x22, 0);
        break;
    }
    }

    if (((TESObjectREFR*)apForm)->GetIsReference() && ((BGSChangeFlags*)&eChangeFlags)->Test(4))
    {
        TESObjectREFR* pRefr = (TESObjectREFR*)apForm;
        CF845 holder_(((ExtraDataListSaveAccess*)pRefr->GetExtraData())->ExtraDataList_GetSavedHavokData());
        if (pRefr->GetNiNode() || !holder_.Modelloader_GetReferencedThis())
        {
            unsigned int offsetBefore6;
            unsigned int bookmark8 = apFile->StartVariableSizedValue();
            offsetBefore6 = apFile->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
            ((TESObjectREFRSaveAccess*)pRefr)->TESObjectREFR_SaveHavokData(apFile);
            unsigned int offsetAfter = apFile->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
            apFile->SaveVariableSizedValue_00865ff0(offsetAfter - offsetBefore6, bookmark8);
        }
        else
        {
            holder_.WriteToSaveGameBuffer(apFile);
        }
    }

    return eType;
}

#include <string.h>
unsigned int BGSSaveLoadInitialData_GetInitialDataTypeSize(int);
unsigned int BGSSaveLoadInitialData_GetInitialDataTypeDataSize(int);
struct ExtCellCharData
{
    int unk00;
    int unk04;
};
struct ExtCellShortData
{
    int unk00;
    int unk04;
    int unk08;
};
struct IntCellData
{
    int unk00;
};

struct CreatedRefData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    CreatedRefData* CreatedReferenceInitialData_CreatedReferenceInitialData();
};
struct MovedRefData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    MovedRefData* MovedReferenceInitialData_MovedReferenceInitialData();
};
struct InitDataA
{
    void CellInitialData_Initialize_CHAR(ExtCellCharData*);
};
struct InitDataB
{
    void LoadFromSaveEntry(ExtCellShortData*);
};
struct InitDataC
{
    void ResetFromValue(IntCellData*);
};
struct InitDataD
{
    void ReferenceInitialData_Initialize_LOCATION(RefLocData*);
};
struct InitDataE
{
    void ReferenceInitialData_Initialize_CREATED(CreatedRefData*);
};
struct InitDataF
{
    void ReferenceInitialData_Initialize_MOVED(MovedRefData*);
};
// Copies a type-sized block from a BGSLoadFormBuffer into a matching data struct and dispatches it to the appropriate InitData handler.
// @fnv 0x0084e930
// src: XBOX_PDB 0x0084e930
void BGSSaveLoadInitialData_LoadInitialDataStruct(BGSLoadFormBuffer* pBuffer, INITIAL_DATA_TYPE eType, void* pData)
{
    unsigned int uiSize = BGSSaveLoadInitialData_GetInitialDataTypeSize(eType);
    switch (eType)
    {
    case INITIAL_DATA_TYPE_INITIAL_DATA_EXTERIOR_CELL_CHAR: {
        ExtCellCharData kData;
        memcpy(&kData, pBuffer, uiSize);
        InitDataA* pInit = (InitDataA*)pData;
        pInit->CellInitialData_Initialize_CHAR(&kData);
        break;
    }
    case INITIAL_DATA_TYPE_INITIAL_DATA_EXTERIOR_CELL_SHORT: {
        ExtCellShortData kData;
        memcpy(&kData, pBuffer, uiSize);
        InitDataB* p = (InitDataB*)pData;
        p->LoadFromSaveEntry(&kData);
        break;
    }
    case INITIAL_DATA_TYPE_INITIAL_DATA_INTERIOR_CELL: {
        IntCellData kData;
        memcpy(&kData, pBuffer, uiSize);
        InitDataC* p = (InitDataC*)pData;
        p->ResetFromValue(&kData);
        break;
    }
    case INITIAL_DATA_TYPE_INITIAL_DATA_REFERENCE_LOCATION: {
        RefLocData kData;
        kData.ReferenceLocationInitialData_ReferenceLocationInitialData();
        memcpy(&kData, pBuffer, uiSize);
        InitDataD* pInit = (InitDataD*)pData;
        pInit->ReferenceInitialData_Initialize_LOCATION(&kData);
        break;
    }
    case INITIAL_DATA_TYPE_INITIAL_DATA_CREATED_REFERENCE: {
        CreatedRefData kData;
        kData.CreatedReferenceInitialData_CreatedReferenceInitialData();
        memcpy(&kData, pBuffer, uiSize);
        InitDataE* p = (InitDataE*)pData;
        p->ReferenceInitialData_Initialize_CREATED(&kData);
        break;
    }
    case INITIAL_DATA_TYPE_INITIAL_DATA_MOVED_REFERENCE: {
        MovedRefData kData;
        kData.MovedReferenceInitialData_MovedReferenceInitialData();
        memcpy(&kData, pBuffer, uiSize);
        InitDataF* p = (InitDataF*)pData;
        p->ReferenceInitialData_Initialize_MOVED(&kData);
        break;
    }
    }
    BGSSaveLoadInitialData_GetInitialDataTypeDataSize(eType);
}
