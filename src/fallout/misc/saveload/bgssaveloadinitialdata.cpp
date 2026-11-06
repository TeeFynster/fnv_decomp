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
    if (FUN_0084f860(eType))
    {
        CellDetachTimeData kCellData;
        LoadFormData(apBuffer, eType, &kCellData);
        TESObjectCELL* pLocationCell = (TESObjectCELL*)apForm;
        pLocationCell->SetDetachTime(kCellData.m_uiDetachTime, true);
    }
    else if (FUN_0084f840(eType))
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
                           pBound ? pBound->FUN_00440e30() : DAT_01015890);
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
                if (!g_BGSSaveLoadGame->FUN_0063ef00())
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
                    pActor->FUN_0084f8c0(pOriginal);
                }
            }
            break;
        }
        if (eChangeFlags.ContainsAnyFlags(4))
            g_BGSSaveLoadGame->FUN_0084a810(2, apBuffer, 0);
    }
    else if (eType != INITIAL_DATA_TYPE_INITIAL_DATA_NONE)
    {
        LogWarning(DAT_0107f86c, eType);
    }
    return eType;
}

unsigned int __cdecl FUN_0084e830(int);

// @fnv 0x0084e800
unsigned int __cdecl FUN_0084e800(int aeType)
{
    unsigned int isize = FUN_0084e830(aeType);
    isize += 1;
    return isize;
}

unsigned int __cdecl FUN_0084e830(int);
int __cdecl FUN_0084e930(void*, int, void*);

// If aeType is non-zero, reads isize bytes from apFile into pbuffer and passes them with aeType and apInitialDataBuffer to FUN_0084e930; returns 0 for aeType 0.
// @fnv 0x0084e8c0
int __cdecl LoadFormData(BGSLoadFormBuffer* apFile, int aeType, void* apInitialDataBuffer)
{
    unsigned int isize;
    char pbuffer[128];

    if (aeType == 0)
        return 0;

    isize = FUN_0084e830(aeType);
    apFile->ReadTypedData(pbuffer, isize);
    return FUN_0084e930(pbuffer, aeType, apInitialDataBuffer);
}

extern bool DAT_011a2231[];

// @fnv 0x0084f840
bool __cdecl FUN_0084f840(int aeType)
{
    return DAT_011a2231[aeType * 3];
}

extern bool DAT_011a2232[];

// @fnv 0x0084f860
bool __cdecl FUN_0084f860(int aeType)
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
    BGSNumericIDIndex3* FUN_0084eb20();
    void FUN_0084eac0();
};
struct Dummy84eaf0
{
    void ClearNumericIDIndex();
};

// Calls FUN_0084eac0 on this object, then ClearNumericIDIndex on the sub-object at offset 0x1C, and returns this.
// @fnv 0x0084eb20
BGSNumericIDIndex3* __thiscall BGSNumericIDIndex3::FUN_0084eb20()
{
    FUN_0084eac0();
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
void TESObjectREFR::FUN_0084f8c0(TESForm* value)
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
    bool FUN_0084e6a0(TESObjectCELL*& cell, TESWorldSpace*& world);
};

// @fnv 0x0084e6a0
bool FUN_0084e6a0_shell::FUN_0084e6a0(TESObjectCELL*& cell, TESWorldSpace*& world)
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
unsigned int FUN_0084e830(int aiIndex)
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
    Outer84eac0* FUN_0084eac0();
};
#pragma pack(pop)
// Calls ClearNumericIDIndex, then invokes FUN_006815c0 on m1 and m2, and returns this.
// @fnv 0x0084eac0
Outer84eac0* Outer84eac0::FUN_0084eac0()
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
    void FUN_0084eac0();
};
struct S84eb50
{
    char _pad[0x1B];
    Dummy84eaf0 m;
    S84eb50* FUN_0084eb50();
};
// Calls the base FUN_0084eac0, then calls ClearNumericIDIndex on member m, and returns this.
// @fnv 0x0084eb50
S84eb50* S84eb50::FUN_0084eb50()
{
    ((Base84eac0*)this)->FUN_0084eac0();
    m.ClearNumericIDIndex();
    return this;
}
}  // namespace fnv_0084eb50

class GameFileBuf
{
  public:
    void FUN_00846300(void* apBuffer, unsigned int auiModule);
};

unsigned int __cdecl FUN_0084e800(int aeType);
int __cdecl FUN_0084e930(void* apBuffer, int aeType, void* apInitialDataBuffer);

// @fnv 0x0084e850
unsigned int __cdecl FUN_0084e850(GameFileBuf* apFile, int aeType, void* apInitialDataBuffer)
{
    char acBuffer[128];
    if (aeType == 0)
    {
        return 0;
    }
    volatile unsigned int uiModule3 = FUN_0084e800(aeType);
    apFile->FUN_00846300(acBuffer, uiModule3);
    return (unsigned int)FUN_0084e930(acBuffer, aeType, apInitialDataBuffer);
}

struct ProjectileAccess
{
    int GetKindCode();
};

TESForm* __cdecl FUN_004839c0(unsigned int);
TESObjectREFR* __cdecl FUN_00564480(unsigned char, bool);
void __cdecl FUN_00845cc0(const char*, ...);
extern const char DAT_0107fa20[];
extern const char DAT_0107f9b8[];

TESBoundObject* __fastcall FUN_004216f0(ExtraDataList*);

// @fnv 0x0084f8e0
TESForm* __cdecl ResolveReferenceForm(unsigned int formID, ReferencePlacementData* data, TESForm* existing)
{
    TESForm* form = existing;
    {
        unsigned char flags;
        {
            if (!form)
                form = FUN_004839c0(formID);
            if (g_dataHandler->FUN_00469860(data->m_uiBaseFormID))
                data->m_uiBaseFormID = 0;
            TESBoundObject* bound = dynamic_cast<TESBoundObject*>(FUN_004839c0(data->m_uiBaseFormID));
            if (!bound)
            {
                FUN_00845cc0(DAT_0107fa20, data->m_uiBaseFormID, formID);
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
                        TESBoundObject* current = ref->FUN_007af430();
                        if (current != bound)
                        {
                            if (!ref->IsActor() || FUN_004216f0(ref->FUN_005d43c0()) != bound)
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
                            created = FUN_00564480((unsigned char)type, true);
                        ((TESObjectREFR*)created)->FUN_00575690(bound);
                        ((TESObjectREFR*)created)->SetRefID(formID, true);
                        form = created;
                    }
                    else
                        FUN_00845cc0(DAT_0107f9b8, flags, formID, data->m_uiBaseFormID, data->m_uiLocationFormID);
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

void __cdecl FUN_00845cc0(const char*, ...);

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
    char* FUN_00422b90();
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
    void* FUN_00559450();
};

TESWorldSpace* __fastcall FUN_00575d70(TESObjectREFR*);
TESBoundObject* __fastcall FUN_004216f0(ExtraDataList*);

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
    RefLocData* FUN_0084eac0();
};

struct CreatedRefInitialData
{
    RefLocData base;
    unsigned char flags;
    unsigned char bound0, bound1, bound2;
    CreatedRefInitialData* FUN_0084eb20();
};

struct MovedRefInitialData
{
    RefLocData base;
    unsigned char orig0, orig1, orig2;
    short originalCellX;
    short originalCellY;
    MovedRefInitialData* FUN_0084eb50();
};

// Save-specific entry point not declared by the shared TESObjectREFR header.
struct TESObjectREFRSaveAccess : TESObjectREFR
{
    void FUN_00562de0(BGSSaveFormBuffer*);
};

// Determines the initial-data type for a form, writes the matching cell or reference record to the save buffer, and optionally saves extra data.
// @fnv 0x0084eb80
INITIAL_DATA_TYPE __cdecl FUN_0084eb80(BGSSaveFormBuffer* apFile, TESForm* apForm, InitialDataChangeMask eChangeFlags)
{
    INITIAL_DATA_TYPE eType = BGSSaveLoadInitialData::DetermineInitialDataType(apForm, eChangeFlags);
    switch (eType)
    {
    case INITIAL_DATA_TYPE_INITIAL_DATA_EXTERIOR_CELL_CHAR: {
        ExteriorCellCharData data;
        TESObjectCELL* cell = (TESObjectCELL*)apForm;
        data.worldID = ((BGSSaveLoadGame_SubAccessor*)g_BGSSaveLoadGame->FUN_0084e3a0())
                           ->FUN_00846c90(cell->GetParentWorldSpace()->GetFormID());
        data.cellX = (char)cell->GetCellGridX();
        data.cellY = (char)cell->GetCellGridY();
        data.detachTime = cell->FUN_00546af0();
        apFile->SaveData(&data, sizeof(data), 0);
        break;
    }
    case INITIAL_DATA_TYPE_INITIAL_DATA_EXTERIOR_CELL_SHORT: {
        ExteriorCellShortData data;
        TESObjectCELL* cell = (TESObjectCELL*)apForm;
        data.worldID = ((BGSSaveLoadGame_SubAccessor*)g_BGSSaveLoadGame->FUN_0084e3a0())
                           ->FUN_00846c90(cell->GetParentWorldSpace()->GetFormID());
        data.cellX = cell->GetCellGridX();
        data.cellY = cell->GetCellGridY();
        *(unsigned int*)&data.detachTimeLow = cell->FUN_00546af0();
        apFile->SaveData(&data, sizeof(data), 0);
        break;
    }
    case INITIAL_DATA_TYPE_INITIAL_DATA_INTERIOR_CELL: {
        TESObjectCELL* pCell = (TESObjectCELL*)apForm;
        unsigned int detachTime = pCell->FUN_00546af0();
        apFile->SaveData(&detachTime, sizeof(detachTime), 0);
        break;
    }
    case INITIAL_DATA_TYPE_INITIAL_DATA_REFERENCE_LOCATION: {
        TESObjectREFR* pRefr = (TESObjectREFR*)apForm;
        TESForm* cell = (TESForm*)FUN_00575d70(pRefr);
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
                cell = (TESForm*)FUN_00575d70((TESObjectREFR*)g_thePlayer);
                if (!cell)
                {
                    cell = (TESForm*)((TESObjectREFR*)g_thePlayer)->GetParentCell();
                }
                pos3 = *pRefr->GetPos();
                rot_2 = *pRefr->FUN_00430830();
            }
        }
        RefLocData refData;
        refData.FUN_0084eac0();
        ((FUN_00853570_shell*)&refData)->WriteFormIDBytes(cell->GetFormID());
        *(NiPoint3*)&refData.pos = pos3;
        *(NiPoint3*)&refData.rot = rot_2;
        apFile->SaveData(&refData, 0x1b, 0);
        break;
    }
    case INITIAL_DATA_TYPE_INITIAL_DATA_CREATED_REFERENCE: {
        TESObjectREFR* pRefr = (TESObjectREFR*)apForm;
        TESForm* kLoc = (TESForm*)FUN_00575d70(pRefr);
        if (!kLoc)
        {
            kLoc = (TESForm*)pRefr->GetParentCell();
        }
        CreatedRefInitialData createdRefData;
        createdRefData.FUN_0084eb20();
        ((FUN_00853570_shell*)&createdRefData)->WriteFormIDBytes(kLoc->GetFormID());
        *(NiPoint3*)&createdRefData.base.pos = *((const TESObjectREFR*)pRefr)->GetPos();
        *(NiPoint3*)&createdRefData.base.rot = *pRefr->FUN_00430830();
        TESBoundObject* baseObject3 = pRefr->GetObjectReference();
        if (pRefr->IsActor() && ((BGSChangeFlags*)&eChangeFlags)->Test(0x40000))
        {
            TESBoundObject* boundObj4 = FUN_004216f0(pRefr->GetExtraData());
            if (boundObj4)
            {
                baseObject3 = boundObj4;
            }
        }
        ((FUN_00853570_shell*)&createdRefData.bound0)->WriteFormIDBytes(baseObject3->GetFormID());
        createdRefData.flags = 1;
        if (pRefr->FUN_005653d0())
        {
            createdRefData.flags |= 2;
        }
        if (pRefr->IsMobileObject())
        {
            TESObjectREFR* aTalkingRef = pRefr;
            if (((MobileObject*)aTalkingRef)->FUN_00574900())
            {
                createdRefData.flags |= 4;
            }
        }
        apFile->SaveData(&createdRefData, 0x1f, 0);
        break;
    }
    case INITIAL_DATA_TYPE_INITIAL_DATA_MOVED_REFERENCE: {
        TESObjectREFR* pRefr = (TESObjectREFR*)apForm;
        TESForm* locMain = (TESForm*)FUN_00575d70(pRefr);
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
                locMain = (TESForm*)FUN_00575d70((TESObjectREFR*)g_thePlayer);
                if (!locMain)
                {
                    locMain = (TESForm*)((TESObjectREFR*)g_thePlayer)->GetParentCell();
                }
                pos3 = *pRefr->GetPos();
                rot_2 = *pRefr->FUN_00430830();
            }
        }
        MovedRefInitialData movedRefDataTmp;
        movedRefDataTmp.FUN_0084eb50();
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
            FUN_00845cc0("EDITOR: Could not get editor location for reference '%s' (%08X) of type '%s' (%08X)",
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
        CF845 holder_(((ExtraDataListSaveAccess*)pRefr->GetExtraData())->FUN_00422b90());
        if (pRefr->GetNiNode() || !holder_.FUN_00559450())
        {
            unsigned int offsetBefore6;
            unsigned int bookmark8 = apFile->FUN_00865f20();
            offsetBefore6 = apFile->FUN_0084e3a0();
            ((TESObjectREFRSaveAccess*)pRefr)->FUN_00562de0(apFile);
            unsigned int offsetAfter = apFile->FUN_0084e3a0();
            apFile->FUN_00865ff0(offsetAfter - offsetBefore6, bookmark8);
        }
        else
        {
            holder_.WriteToSaveGameBuffer(apFile);
        }
    }

    return eType;
}

#include <string.h>
unsigned int FUN_0084e830(int);
unsigned int FUN_0084e800(int);
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
    CreatedRefData* FUN_0084eb20();
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
    MovedRefData* FUN_0084eb50();
};
struct InitDataA
{
    void FUN_0084e340(ExtCellCharData*);
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
    void FUN_0084e460(RefLocData*);
};
struct InitDataE
{
    void FUN_0084e4f0(CreatedRefData*);
};
struct InitDataF
{
    void FUN_0084e580(MovedRefData*);
};
// Copies a type-sized block from a BGSLoadFormBuffer into a matching data struct and dispatches it to the appropriate InitData handler.
// @fnv 0x0084e930
void FUN_0084e930(BGSLoadFormBuffer* pBuffer, INITIAL_DATA_TYPE eType, void* pData)
{
    unsigned int uiSize = FUN_0084e830(eType);
    switch (eType)
    {
    case INITIAL_DATA_TYPE_INITIAL_DATA_EXTERIOR_CELL_CHAR: {
        ExtCellCharData kData;
        memcpy(&kData, pBuffer, uiSize);
        InitDataA* pInit = (InitDataA*)pData;
        pInit->FUN_0084e340(&kData);
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
        kData.FUN_0084eac0();
        memcpy(&kData, pBuffer, uiSize);
        InitDataD* pInit = (InitDataD*)pData;
        pInit->FUN_0084e460(&kData);
        break;
    }
    case INITIAL_DATA_TYPE_INITIAL_DATA_CREATED_REFERENCE: {
        CreatedRefData kData;
        kData.FUN_0084eb20();
        memcpy(&kData, pBuffer, uiSize);
        InitDataE* p = (InitDataE*)pData;
        p->FUN_0084e4f0(&kData);
        break;
    }
    case INITIAL_DATA_TYPE_INITIAL_DATA_MOVED_REFERENCE: {
        MovedRefData kData;
        kData.FUN_0084eb50();
        memcpy(&kData, pBuffer, uiSize);
        InitDataF* p = (InitDataF*)pData;
        p->FUN_0084e580(&kData);
        break;
    }
    }
    FUN_0084e800(eType);
}
