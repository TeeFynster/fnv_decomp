// fallout_shared/packagetarget.cpp: PackageTargetRecord, LocationDescriptor, Script (21 functions)

#include "../../include/layout_support.h"
#include "Script.h"
#include "../../include/BGSCameraPath.h"
#include "packagetarget_decls.h"
#include "packagetarget_types_PackageLocation.h"
#include "../../include/PackageTargetRecord.h"
#include "../../include/BGSSaveFormBuffer.h"
#include "../../include/BGSLoadFormBuffer.h"
#include "../../include/TESSaveLoadGame.h"

// @fnv 0x00519b00
int PackageTargetRecord::GetTargetKind()
{
    return (PACK_TARG_TYPE)m_uiTargetType;
}

// @fnv 0x006800b0
void PackageTargetRecord::SetTargetKind(PACK_TARG_TYPE aeTargetType)
{
    if (m_uiTargetType != aeTargetType)
    {
        m_uiTargetType = (unsigned char)aeTargetType;
        switch (m_uiTargetType)
        {
        case PACK_TARG_TYPE_PTT_REFERENCE:
            m_pWorldReferenceInfo = 0;
            break;
        case PACK_TARG_TYPE_PTT_OBJECT:
            m_pWorldReferenceInfo = 0;
            break;
        case PACK_TARG_TYPE_PTT_TYPE:
            m_pWorldReferenceInfo = 0;
            break;
        }
    }
}

// Returns the target reference if the target type is PACK_TARG_TYPE_PTT_REFERENCE, otherwise returns null.
// @fnv 0x00680020
TESObjectREFR* PackageTargetRecord::GetReferenceTarget()
{
    if (GetTargetKind() == PACK_TARG_TYPE_PTT_REFERENCE)
        return m_pWorldReferenceInfo;
    else
        return 0;
}

// If the package target type is PACK_TARG_TYPE_PTT_REFERENCE, stores the given reference as the target.
// @fnv 0x00680110
void PackageTargetRecord::SetTargetObjectReference(TESObjectREFR* reference)
{
    if (GetTargetKind() == PACK_TARG_TYPE_PTT_REFERENCE)
        m_pWorldReferenceInfo = reference;
}

// Returns pObject when the target type is PACK_TARG_TYPE_PTT_OBJECT, otherwise returns null.
// @fnv 0x00680050
TESForm* PackageTargetRecord::GetTargetForm()
{
    if (GetTargetKind() == PACK_TARG_TYPE_PTT_OBJECT)
        return pObject;
    else
        return 0;
}

// @fnv 0x00680080
int PackageTargetRecord::GetTargetObjectType()
{
    if (GetTargetKind() == PACK_TARG_TYPE_PTT_TYPE)
        return eObjType;
    else
        return (PACKAGE_OBJECT_TYPE)0;
}

// Copies location data from source into this object when copy is set or source's location type is valid, dispatching on the location type.
// @fnv 0x0067f4d0
void LocationDescriptor::Copy(LocationDescriptor* source, bool copy)
{
    if (source != 0)
    {
        if (copy || source->GetLocType() != PLT_NONE)
        {
            SetLocationType(source->GetLocType());
            switch (m_ucLocationType)
            {
            case 0:
                SetRadius(source->PackageLocation_GetRadius());
                PackageLocation_SetLocReference(source->GetLocationReference());
                break;
            case 1:
                PackageLocation_SetLocCell(source->GetLocationCellReference());
                break;
            case 4:
                SetRadius(source->PackageLocation_GetRadius());
                SetValue((TESForm*)source->FUN_0067f430());
                break;
            case 5:
                SetRadius(source->PackageLocation_GetRadius());
                PackageLocation_SetLocObjectType(source->GetObjectType());
                break;
            case 2:
            case 3:
            case 7:
                SetRadius(source->PackageLocation_GetRadius());
                break;
            case 6:
                SetRadius(source->PackageLocation_GetRadius());
                break;
            }
        }
    }
}

// @fnv 0x00671d10
char* Script::GetData()
{
    return m_data;
}

// Resolves the stored form ID against the owner's file and looks up the package target reference or object, warning if it is missing.
// @fnv 0x006803b0
void PackageTargetRecord::InitItem(TESForm* owner)
{
    unsigned int formID = (unsigned int)pTargetForm;
    TESForm::RemapFormIDForFile(formID, owner->GetFile(-1));
    switch (m_uiTargetType)
    {
    case 0:
        m_pWorldReferenceInfo = dynamic_cast<TESObjectREFR*>(GetFormByID(formID));
        if (!m_pWorldReferenceInfo)
        {
            if (owner)
            {
                if (((BGSCameraPath*)owner)->HasNameForWarning())
                    Warning("MASTERFILE: Unable to find Package Target Reference (%08X) on owner object \"%s\".",
                            formID, owner->GetName());
                else
                    Warning("MASTERFILE: Unable to find Package Target Reference (%08X) on owner object (%08X).",
                            formID, owner->GetFormID());
            }
            else
                Warning("MASTERFILE: Unable to find Package Target Reference (%08X) on unknown owner.", formID);
        }
        break;
    case 1:
        pObject = GetFormByID(formID);
        if (!pObject)
        {
            if (owner)
            {
                if (((BGSCameraPath*)owner)->HasNameForWarning())
                    Warning("MASTERFILE: Unable to find Package Target Object (%08X) on owner object \"%s\".", formID,
                            owner->GetName());
                else
                    Warning("MASTERFILE: Unable to find Package Target Object (%08X) on owner object (%08X).", formID,
                            owner->GetFormID());
            }
            else
                Warning("MASTERFILE: Unable to find Package Target Object (%08X) on unknown owner.", formID);
        }
        break;
    }
}

// Initializes an object-type target with zeroed target data, value and radius.
// @fnv 0x0067ff70
PackageTargetRecord::PackageTargetRecord()
{
    m_uiTargetType = 2;
    pTargetForm = 0;
    iValue = 0;
    m_fTargetValue = 0.0f;
}

// The shared Copy declaration returns void; this entry returns the target pointer.
// A pointer aggregate stays on the stack under __fastcall, preserving the original thiscall ABI.
struct PackageTargetCopySource
{
    PackageTargetRecord* record;
};

// @fnv 0x0067ffa0
PackageTargetRecord* __fastcall CopyPackageTargetRecord(PackageTargetRecord* target, PackageTargetCopySource source)
{
    target->SetTargetKind(source.record->m_uiTargetType);
    target->SetTargValue(source.record->iValue);
    target->SetTargAcquireRadius(source.record->m_fTargetValue);
    switch (target->m_uiTargetType)
    {
    case 0:
    case 1:
        target->pTargetForm = source.record->pTargetForm;
        break;
    case 2:
        target->pTargetForm = source.record->pTargetForm;
        break;
    }
    return target;
}

// If the package target type is PTT_OBJECT, stores apObj in pObject.
// @fnv 0x00680140
void PackageTargetRecord::SetTargObject(TESForm* apObj)
{
    if (GetTargetKind() == PACK_TARG_TYPE_PTT_OBJECT)
        pObject = apObj;
}

// Returns true if apCompare is null or any of the compared values differ; returns false when all compared values match.
// @fnv 0x00680220
bool PackageTargetRecord::Compare(PackageTargetRecord* apCompare)
{
    if (apCompare == 0)
        return true;
    if (this->GetTargetKind() != apCompare->GetTargetKind())
        return true;
    if (this->GetReferenceTarget() != apCompare->GetReferenceTarget())
        return true;
    if (this->GetTargetForm() != apCompare->GetTargetForm())
        return true;
    if (this->GetTargetObjectType() != apCompare->GetTargetObjectType())
        return true;
    if (this->GetTargValue() != apCompare->GetTargValue())
        return true;
    if (this->GetTargAcquireRadius() != apCompare->GetTargAcquireRadius())
        return true;
    return false;
}

struct ChunkPayload16
{
    void OBJ_WEAP_VATS_SPECIAL_Endian();
};
struct FormValueEntry
{
    unsigned char m_uiTargetType;
    unsigned int iFormID;
    int iValue;
    float m_fTargetValue;
};
extern "C" void* __cdecl memset(void* dest, int value, unsigned int count);
extern "C" bool __cdecl TESForm_QEndianSwapOnSave();
extern "C" void __cdecl AppendChunk(int id, FormValueEntry* data, unsigned int size);

// @fnv 0x006802f0
// src: XBOX_PDB 0x006802f0
void PackageTargetRecord::PackageTarget_Save(int chunk)
{
    FormValueEntry record;
    memset(&record, 0, 16);
    record.iValue = this->iValue;
    record.m_fTargetValue = this->m_fTargetValue;
    record.m_uiTargetType = this->m_uiTargetType;
    switch (this->m_uiTargetType)
    {
    case 2:
        record.iFormID = this->GetTargetObjectType();
        break;
    case 0:
    case 1:
        if (this->pObject)
            record.iFormID = this->pObject->GetFormID();
        break;
    }
    if (TESForm_QEndianSwapOnSave())
        ((ChunkPayload16*)&record)->OBJ_WEAP_VATS_SPECIAL_Endian();
    AppendChunk(chunk, &record, 16);
    if (TESForm_QEndianSwapOnSave())
        ((ChunkPayload16*)&record)->OBJ_WEAP_VATS_SPECIAL_Endian();
}

// @fnv 0x00680520
unsigned short PackageTargetRecord::GetSaveSize()
{
    unsigned short usSize = 0;
    usSize += 1;
    usSize += 4;
    usSize += 4;
    switch (m_uiTargetType)
    {
    case 3:
        break;
    case 0:
    case 1:
        usSize += 4;
        break;
    case 2:
        usSize += 4;
        break;
    default:;
    }
    return usSize;
}

// Writes the target type, value and radius, then the type-specific target.
// @fnv 0x00680720
void PackageTargetRecord::SaveGame(BGSSaveFormBuffer* pkBuffer)
{
    pkBuffer->SaveData(this, 1, 0);
    pkBuffer->SaveData(&iValue, 4, 0);
    pkBuffer->SaveData(&m_fTargetValue, 4, 0);
    switch (m_uiTargetType)
    {
        break;
    case 0:
    case 1:
        pkBuffer->SerializeFormData(pTargetForm, 0);
        break;
    case 2:
        pkBuffer->SaveData(&eObjType, 4, 0);
        break;
    }
}

// @fnv 0x006807b0
void PackageTargetRecord::LoadGame(BGSLoadFormBuffer* pStream)
{
    pStream->LoadData(this, 1);
    pStream->LoadData(&iValue, 4);
    pStream->LoadData(&m_fTargetValue, 4);
    switch (m_uiTargetType)
    {
        break;
    case 0:
    case 1:
        pStream->FUN_008648e0(&pTargetForm);
        break;
    case 2:
        pStream->LoadData(&pTargetForm, 4);
        break;
    }
}

// @fnv 0x00680830
void PackageTargetRecord::InitLoadGame(BGSLoadFormBuffer* unused)
{
    switch (m_uiTargetType)
    {
    case PACK_TARG_TYPE_PTT_REFERENCE:
    case PACK_TARG_TYPE_PTT_OBJECT:
        pTargetForm = pTargetForm ? TESForm::GetFormByID((unsigned int)pTargetForm) : 0;
        break;
    }
}

extern TESSaveLoadGame* g_TESSaveLoadGame;

// Legacy save/load entry points have no declarations in the shared class.
// __fastcall passes the explicit target in ECX, matching their original no-argument thiscall ABI.
// @fnv 0x00680590
void __fastcall SavePackageTargetRecordOLD(PackageTargetRecord* target)
{
    g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&target->m_uiTargetType, 1);
    g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&target->iValue, 4);
    g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&target->m_fTargetValue, 4);

    switch (target->m_uiTargetType)
    {
        break;
    case 0:
    case 1: {
        unsigned int uiResult = 0;
        if (target->pTargetForm)
        {
            uiResult = target->pTargetForm->GetFormID();
        }
        g_TESSaveLoadGame->TESSaveLoadGame_SaveNumericID((int)&uiResult, 4);
    }
    break;
    case 2:
        g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&target->eObjType, 4);
        break;
    }
}

TESForm* TESForm_GetFormByNumericID(unsigned int formID);

// For reference or object target types, replaces pTargetForm with the TESForm resolved from its formID via FUN_004839c0.
// @fnv 0x006806e0
void __fastcall ResolvePackageTargetForm(PackageTargetRecord* target)
{
    switch (target->m_uiTargetType)
    {
    case PACK_TARG_TYPE_PTT_REFERENCE:
    case PACK_TARG_TYPE_PTT_OBJECT:
        unsigned int formID = reinterpret_cast<unsigned int>(target->pTargetForm);
        target->pTargetForm = TESForm_GetFormByNumericID(formID);
    }
}

struct SaveLoadStub
{
    void TESSaveLoadGame_LoadGameDataOLD(void* data, int size);
    void FUN_00857aa0(void* data, int size);
};
extern SaveLoadStub* g_saveLoad_011de45c;
// @fnv 0x00680640
void __fastcall LoadPackageTargetRecordOLD(PackageTargetRecord* target)
{
    g_saveLoad_011de45c->TESSaveLoadGame_LoadGameDataOLD(target, 1);
    g_saveLoad_011de45c->TESSaveLoadGame_LoadGameDataOLD(&target->iValue, 4);
    g_saveLoad_011de45c->TESSaveLoadGame_LoadGameDataOLD(&target->m_fTargetValue, 4);
    switch (target->m_uiTargetType)
    {
        break;
    case 0:
    case 1: {
        int value;
        g_saveLoad_011de45c->FUN_00857aa0(&value, 4);
        target->eObjType = (PACKAGE_OBJECT_TYPE)value;
    }
    break;
    case 2:
        g_saveLoad_011de45c->TESSaveLoadGame_LoadGameDataOLD(&target->eObjType, 4);
        break;
    }
}
