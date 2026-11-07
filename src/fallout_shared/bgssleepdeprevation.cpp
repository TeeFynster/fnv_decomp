// fallout_shared/bgssleepdeprevation.cpp: BGSSleepDeprevationStage (11 functions)

#include "bgssleepdeprevation.h"
#include "../../include/BGSSleepDeprevationStage.h"
#include <malloc.h>

// @fnv 0x00402200
void BGSSleepDeprevationStage::ClearData()
{
    ClearStageData(this);
}

// @fnv 0x00402220
void BGSSleepDeprevationStage::InitItem()
{
    unsigned int formID;
    if (IsFormInitialized())
        return;
    formID = FUN_00441110();
    if (formID)
    {
        TESForm::RemapFormIDForFile(formID, GetFile(-1));
        FUN_0050f9a0(dynamic_cast<SpellItem*>(TESForm::GetFormByID(formID)));
    }
    SetInitializationState(true);
    BGSSleepDeprevationStage_AddStage(this);
}

struct RemoveStageLocals
{
    BGSSleepDeprevationStage** oldStages;
    unsigned int source;
    unsigned int destination;
    unsigned int index;
    unsigned char padding0;
    unsigned char padding1;
    unsigned char padding2;
    bool found;
    unsigned int newCount;
    BGSDehydrationStage** newStages;
};

// Removes the given stage from the global stage array, reallocating a smaller array and deleting the old one.
// @fnv 0x00402650
void BGSSleepDeprevationStage::ClearStageData(BGSSleepDeprevationStage* stage)
{
    RemoveStageLocals locals;

    if (!DAT_011c31b0)
        return;

    locals.found = false;
    locals.index = 0;
    for (; !locals.found && locals.index < DAT_011c31b0; ++locals.index)
    {
        if (DAT_011c31b4[locals.index] == stage)
            locals.found = true;
    }

    if (!locals.found)
        return;

    locals.newCount = DAT_011c31b0 - 1;
    locals.newStages = BGSDehydrationStage::AllocateStageArray(locals.newCount);
    if (locals.newStages)
    {
        locals.destination = 0;
        locals.source = 0;
        for (; locals.source < DAT_011c31b0; ++locals.source)
        {
            if (DAT_011c31b4[locals.source] != stage)
            {
                reinterpret_cast<BGSSleepDeprevationStage**>(locals.newStages)[locals.destination] =
                    DAT_011c31b4[locals.source];
                ++locals.destination;
            }
        }
    }

    locals.oldStages = DAT_011c31b4;
    ::operator delete(locals.oldStages);
    DAT_011c31b0 = locals.newCount;
    DAT_011c31b4 = reinterpret_cast<BGSSleepDeprevationStage**>(locals.newStages);
}

// Reads a TESFile record, requiring form type 0x78, then dispatches EDID, OBND and DATA chunks until the chunk list ends.
// @fnv 0x00402390
bool BGSSleepDeprevationStage::Load(TESFile* file)
{
    unsigned char formType = file->GetTESForm();
    if (formType != 0x78)
        return false;

    ClearData();
    LoadRecordHeader(file);
    SetInitializationState(false);

    unsigned int chunk;
    while ((chunk = file->GetChunkID()) != 0)
    {
        switch (chunk)
        {
        case 0x44494445: {
            char* buffer = static_cast<char*>(_alloca(file->GetChunkSize()));
            file->GetChunkData(buffer, 0x200);
            SetEditorID_AtRuntime(buffer);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x41544144:
            reinterpret_cast<BGSDehydrationStage*>(this)->ReadData(
                file, reinterpret_cast<BGSDehydrationStage*>(this)->GetDataBuffer(8));
            break;
        }

        if (chunk == 0x41544144 && file->IsEndianConversionRequired())
            reinterpret_cast<SleepStageDataOperations*>(&data)->SwapEndian();
        if (!file->NextChunk())
            break;
    }
    return true;
}

// @fnv 0x004020f0
BGSSleepDeprevationStage::BGSSleepDeprevationStage()
{
    // SpellItemValueEntry has no declared constructor; retain the original data initialization call locally.
    reinterpret_cast<SleepStageDataOperations*>(&data)->Initialize();
    SetFormType((ENUM_FORM_ID)0x78);
    ResetFormData();
}

extern unsigned int _DAT_011c31b0;
extern BGSSleepDeprevationStage** _DAT_011c31b4;
struct AddLocals
{
    BGSSleepDeprevationStage** oldStages;
    unsigned int index;
    unsigned char p0, p1, p2;
    unsigned char newCount;
    unsigned int destination;
    unsigned char p3, p4, p5;
    bool inserted;
    BGSSleepDeprevationStage** newStages;
};
// Inserts stage into the global sleep-deprivation-stage array in descending order of FUN_00500940 value, reallocating the array and updating the count.
// @fnv 0x00402550
// src: XBOX_PDB 0x00402550
void BGSSleepDeprevationStage_AddStage(BGSSleepDeprevationStage* stage)
{
    AddLocals locals;
    locals.newCount = (unsigned char)(_DAT_011c31b0 + 1);
    locals.newStages = reinterpret_cast<BGSSleepDeprevationStage**>(BGSDehydrationStage::AllocateStageArray(locals.newCount));
    locals.destination = 0;
    locals.inserted = false;
    locals.index = 0;
    for (; locals.index < _DAT_011c31b0; ++locals.index)
    {
        if (*static_cast<unsigned int*>(stage->FUN_00500940()) > *static_cast<unsigned int*>(_DAT_011c31b4[locals.index]->FUN_00500940()) && !locals.inserted)
        {
            locals.newStages[locals.destination] = stage;
            ++locals.destination;
            locals.inserted = true;
        }
        locals.newStages[locals.destination] = _DAT_011c31b4[locals.index];
        ++locals.destination;
    }
    if (!locals.inserted)
    {
        locals.newStages[locals.destination] = stage;
        ++locals.destination;
    }
    locals.oldStages = _DAT_011c31b4;
    ::operator delete(locals.oldStages);
    _DAT_011c31b0 = locals.newCount;
    _DAT_011c31b4 = locals.newStages;
}

extern unsigned int DAT_011c31b0;
BGSSleepDeprevationStage* __cdecl Object_GetGlobalArrayElement(unsigned int);

class Calendar
{
  public:
    unsigned int GetDaysPassed();
};

// Returns the first sleep-deprivation stage whose days-passed threshold is at or below level, or null if none match.
// @fnv 0x00402760
BGSSleepDeprevationStage* __cdecl GetSleepDeprivationStage(float level)
{
    BGSSleepDeprevationStage* result = 0;
    for (unsigned int index = 0; index < DAT_011c31b0 && !result; ++index)
    {
        BGSSleepDeprevationStage* stage = Object_GetGlobalArrayElement(index);
        if (stage && level >= reinterpret_cast<Calendar*>(stage)->GetDaysPassed())
            result = stage;
    }
    return result;
}

void _Deallocate(void*);
// @fnv 0x00402170
void* BGSSleepDeprevationStage::FUN_00402170(unsigned int flags)
{
    this->BGSSleepDeprevationStage::~BGSSleepDeprevationStage();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

// @fnv 0x004021a0
BGSSleepDeprevationStage::~BGSSleepDeprevationStage()
{
    this->BGSSleepDeprevationStage::ClearData();
}

namespace fnv_004022b0 {
void* __memcpy(void*, const void*, unsigned int);
}

// @fnv 0x004022b0
void BGSSleepDeprevationStage::CopyFromSleepDeprivationStage(TESForm* apCopy)
{
    BGSSleepDeprevationStage* pcopy = dynamic_cast<BGSSleepDeprevationStage*>(apCopy);
    if (!pcopy)
        return;
    TESForm::CopyFrom(pcopy);
    fnv_004022b0::__memcpy(FUN_00500940(), pcopy->FUN_00500940(), 8);
}

extern "C" int __cdecl memcmp(const void* pvA, const void* pvB, unsigned int uiSize);

// @fnv 0x00402310
// src: XBOX_PDB 0x00402310
bool BGSSleepDeprevationStage::Compare_00402310(TESForm* pkForm)
{
    BGSSleepDeprevationStage* pkOther = dynamic_cast<BGSSleepDeprevationStage*>(pkForm);
    if (!pkOther)
        return true;
    if (TESForm::Compare(pkOther))
        return true;
    if (memcmp(GetData(), pkOther->GetData(), 8))
        return true;
    return false;
}
