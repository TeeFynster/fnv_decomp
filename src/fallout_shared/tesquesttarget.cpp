// fallout_shared/tesquesttarget.cpp: free functions (5 functions)

#include "tesquesttarget_decls.h"

// Resolves the stored reference form ID against the quest's file, warns if it is missing, then initializes the conditions.
// @fnv 0x00610040
void RegionObjectEntry::InitItem(TESForm* form)
{
    if (m_pReference)
    {
        unsigned int formID = reinterpret_cast<unsigned int>(m_pReference);
        TESForm::RemapFormIDForFile(formID, form->GetFile(-1));
        m_pReference = dynamic_cast<TESObjectREFR*>(TESForm::GetFormByID(formID));
        if (!m_pReference)
            Warning("MASTERFILE: Could not find target reference (%08X) on quest (%08X) '%s'.", formID,
                    form->GetFormID(), form->GetName());
    }
    else
    {
        Warning("MASTERFILE: No reference on target for quest (%08X) '%s'.", form->GetFormID(), form->GetName());
    }
    if (GetConditions())
        GetConditions()->InitItem(form);
}

// @fnv 0x0060f440
void QuestStage::Load(TESFile* file)
{
    if (file && file->GetChunkID() == 0x58444e49)
    {
        if (file->GetChunkSize() == 8)
        {
            TESQuestStageLegacyData legacy;
            file->GetChunkData(&legacy, sizeof(legacy));
            m_Data.m_bCompleted = legacy.data.m_bCompleted;
            m_Data.m_ucClipIdentifier = legacy.data.m_ucClipIdentifier;
        }
        else
        {
            file->GetChunkData(&m_Data, sizeof(m_Data));
        }
    }
}

// Returns the stored reference, replacing it with its extra-data replacement when it is deleted and resolveDeleted is set.
// @fnv 0x006101b0
TESObjectREFR* RegionObjectEntry::GetReference(bool resolveDeleted)
{
    TESObjectREFR* reference = m_pReference;
    if (reference && reference->TESForm::IsDeleted() && resolveDeleted)
    {
        TESObjectREFR* replacement = reference->GetExtraData()->GetReplacementReference();
        if (replacement)
            reference = replacement;
    }
    return reference;
}

#include "../../include/PathingPath.h"
struct FUN_0060ff70
{
    unsigned char cFlags;
    PerkEntryConditionSet m_kInfoConditions;
    void* m_pReference;
    PathingPath m_auiData;
    FUN_0060ff70();
};

// @fnv 0x0060ff70
FUN_0060ff70::FUN_0060ff70()
{
    m_pReference = 0;
    cFlags = 0;
}

struct TeleportPathHelper
{
    char _pad[0x10];
    ~TeleportPathHelper();
};
struct FUN_0060ffe0
{
    unsigned char cFlags;
    PerkEntryConditionSet mCond;
    void* m_pReference;
    TeleportPathHelper mPath;
    ~FUN_0060ffe0();
};
// Destructor for the object; the body is empty, so member destruction is handled by the compiler-generated code.
// @fnv 0x0060ffe0
FUN_0060ffe0::~FUN_0060ffe0()
{}
