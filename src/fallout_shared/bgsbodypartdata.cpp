// fallout_shared/bgsbodypartdata.cpp: BGSBodyPartData (10 functions)

#define FNV_TESFILE_H  // the shared TESFile below replaces layout_support.h's stub
#include "../../include/NiFile.h"
#include "bgsbodypartdata.h"
#include "../../include/BGSBodyPart.h"
#include "../../include/BGSBodyPartData.h"
#include "../../include/BGSPreloadable.h"
#include "../../include/BGSRagdoll.h"
#include "../../include/BodyPartInfo.h"
#include "../../include/FileEntryList.h"
#include "../../include/TESDataHandler.h"
#include "../../include/TESModel.h"
#include "../../include/TESModelPSA.h"
#include "string.h"
#include <malloc.h>
#include "../../include/TESFile.h"

extern TESDataHandler* g_dataHandler;

BGSBodyPartData* BGSBodyPartData::ms_pBodyPartData;
BGSBodyPartData* BGSBodyPartData::ms_pBodyPartDataInstance;

static const char s_ragdollWarning[] = "MASTERFILE: Could not find ragdoll (%08X) for bodypart data '%s' (%08X).";
static const char s_loadFailedWarning[] = "MASTERFILE: Load failed for body part data '%s' (%08X).";
static const char s_advancedTooFarWarning[] =
    "MASTERFILE: Body part data for '%s' (%08X) advanced file too far. Attempting recovery.";
static const char s_partWarningsWarning[] =
    "MASTERFILE: Warnings encountered loading part '%s' for body part data '%s' (%08X).";
static const char s_alreadyInUseWarning[] = "MODELS: Body part index %i already in use in body part data %s (%08X).";
static const char s_invalidIndexWarning[] = "MODELS: Invalid body part index %i in body part data %s (%08X).";
static const char s_defaultBodyPartData[] = "DefaultBodyPartData";
static const char s_playerBodyPartData[] = "PlayerBodyPartData";

// @fnv 0x005e4af0
BGSBodyPartData::BGSBodyPartData()
{
    SetFormType(ENUM_FORM_ID_BPTD_ID);
    ResetFormData();
}

// @fnv 0x005e4c40
void BGSBodyPartData::ResetFormData()
{
    memset(m_apBodyParts, 0, sizeof(m_apBodyParts));
    m_pRagdoll = 0;
}

// @fnv 0x005e4c70
void BGSBodyPartData::ClearData()
{
    ClearBodyParts();
}

// Deletes all 15 entries in the body part array and sets each pointer to null.
// @fnv 0x005e51b0
void BGSBodyPartData::ClearBodyParts()
{
    for (int i = 0; i < 15; ++i)
    {
        delete m_apBodyParts[i];
        m_apBodyParts[i] = 0;
    }
}

// @fnv 0x005e4c90
void BGSBodyPartData::InitItem()
{
    if (IsFormInitialized())
        return;
    for (int i = 0; i < 15; ++i)
    {
        BGSBodyPart* part = m_apBodyParts[i];
        if (part)
            part->InitItem(this);
    }
    unsigned int ragdollID = reinterpret_cast<unsigned int>(m_pRagdoll);
    if (ragdollID)
    {
        RemapFormIDForFile(ragdollID, GetFile(-1));
        m_pRagdoll = dynamic_cast<BGSRagdoll*>(TESForm::GetFormByID(ragdollID));
        if (!m_pRagdoll)
            Warning(s_ragdollWarning, ragdollID, GetName(), GetFormID());
    }
    SetInitializationState(true);
}

// Loads a BGSBodyPartData from a TESFile: validates the BPTD form ID, reads the record header and dispatches EDID/OBND/MODL/MODT/PNAM/BPNN/BPTN/NAM0/RAGA chunks.
// @fnv 0x005e4d80
bool BGSBodyPartData::LoadForm(TESFile* file)
{
    if (static_cast<TESFileFormInt*>(file)->GetTESForm() != ENUM_FORM_ID_BPTD_ID)
        return false;
    LoadRecordHeader(file);
    int chunk;
    bool bRecovered;
read_chunk:
    chunk = file->GetChunkID();
    if (chunk)
    {
        bRecovered = false;
        switch (chunk)
        {
        case 0x44494445:  // EDID
        {
            char* buffer = static_cast<char*>(_alloca(file->GetChunkSize()));
            file->GetChunkData(buffer, 0x200);
            SetEditorID_AtRuntime(buffer);
            break;
        }
        case 0x444E424F:  // OBND
            readOBNDSubRecord(file);
            break;
        case 0x4C444F4D:  // MODL
        case 0x54444F4D:  // MODT
            TESModel::LoadModelData(static_cast<TESModel*>(this), file);
            break;
        case 0x4D414E50:  // PNAM
        case 0x4E4E5042:  // BPNN
        case 0x4E545042:  // BPTN
        {
            BGSBodyPart* part = new BGSBodyPart;
            int warnings = Warning();
            if (!part->Load(file))
            {
                Warning(s_loadFailedWarning, GetName(), GetFormID());
                delete part;
                return false;
                goto check_warnings;
            }
            switch (static_cast<int>(file->GetChunkID()))
            {
            case 0x4E4E5042:  // BPNN
            case 0x41474152:  // RAGA
            case 0x4D414E50:  // PNAM
            case 0x4E545042:  // BPTN
                Warning(s_advancedTooFarWarning, GetName(), GetFormID());
                bRecovered = true;
                break;
            }
        check_warnings:
            if (Warning() != warnings)
                Warning(s_partWarningsWarning, part->GetPartName(), GetName(), GetFormID());
            AddBodyPart(part);
            break;
        }
        case 0x41474152:  // RAGA
        {
            unsigned int ragdollID = 0;
            file->GetChunkData(&ragdollID);
            m_pRagdoll = reinterpret_cast<BGSRagdoll*>(ragdollID);
            break;
        }
        }
        if (!bRecovered && !file->NextChunk())
            goto done;
        goto read_chunk;
    }
done:
    return true;
}

// Stores a body part in the slot given by its limb index, warning and deleting any existing part if the slot is occupied or the index is out of range.
// @fnv 0x005e5220
void BGSBodyPartData::AddBodyPart(BGSBodyPart* part)
{
    if (part)
    {
        int index = part->GetLimb();
        if (index >= 0 && index < 15)
        {
            if (m_apBodyParts[index])
            {
                Warning(s_alreadyInUseWarning, index, GetName(), GetFormID());
                delete m_apBodyParts[index];
            }
            m_apBodyParts[index] = part;
        }
        else
            Warning(s_invalidIndexWarning, index, GetName(), GetFormID());
    }
}

// @fnv 0x005e5590
void BGSBodyPartData::QueueResourceLoad(IO_TASK_PRIORITY priority, QueuedFile* file)
{
    for (int i = 0; i < 15; ++i)
    {
        BGSBodyPart* part = m_apBodyParts[i];
        if (part)
            part->QueueResourceLoad(priority, file);
    }
}

// Looks up BGSBodyPartData forms 0x1D and 0x1C, creating and registering them with editor IDs if missing.
// @fnv 0x005e53a0
void BGSBodyPartData::InitializeBodyPartData()
{
    ms_pBodyPartData = dynamic_cast<BGSBodyPartData*>(TESForm::GetFormByID(0x1D));
    if (!ms_pBodyPartData)
    {
        ms_pBodyPartData = new BGSBodyPartData;
        ms_pBodyPartData->SetRefID(0x1D, true);
        ms_pBodyPartData->SetEditorID_AtRuntime(s_defaultBodyPartData);
        g_dataHandler->AddFormToDataHandler(ms_pBodyPartData);
        ms_pBodyPartData->SetAltered(false);
    }
    ms_pBodyPartDataInstance = dynamic_cast<BGSBodyPartData*>(TESForm::GetFormByID(0x1C));
    if (!ms_pBodyPartDataInstance)
    {
        ms_pBodyPartDataInstance = new BGSBodyPartData;
        ms_pBodyPartDataInstance->SetRefID(0x1C, true);
        ms_pBodyPartDataInstance->SetEditorID_AtRuntime(s_playerBodyPartData);
        g_dataHandler->AddFormToDataHandler(ms_pBodyPartDataInstance);
        ms_pBodyPartDataInstance->SetAltered(false);
        ms_pBodyPartDataInstance = 0;
    }
}

// Searches the entries array for an element whose GetByte63 matches value and returns it, or null if none found.
// @fnv 0x005e5130
BGSBodyPart* BGSBodyPartData::GetValueByIndex(int value)
{
    BGSBodyPart* pFound = 0;
    for (int index = 0; index < 15; ++index)
    {
        BGSBodyPart* pEntry = m_apBodyParts[index];
        if (!pEntry)
            continue;
        if (pEntry->GetByte63() == value)
        {
            pFound = pEntry;
            break;
        }
    }
    return pFound;
}
