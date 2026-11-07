// fallout_shared/tesimagespace.cpp: TESImageSpace (7 functions)

#define FNV_TESFILE_H  // the shared TESFile below replaces layout_support.h's stub
#include "../../include/NiFile.h"
#include "layout_support.h"
#include "../../include/TESImageSpace.h"
#include <malloc.h>
#include <string.h>
#include "../../include/TESFile.h"

// Zeroes out the Data member of the TESImageSpace form using memset.
// @fnv 0x0052b410
void TESImageSpace::ResetFormData()
{
    memset(&Data, 0, sizeof(Data));
}

// Reads a TESImageSpace record from file, handling EDID, OBND and DNAM chunks, and returns false if the form type is not 0x53.
// @fnv 0x0052b440
bool TESImageSpace::Load(TESFile* file)
{
    unsigned char formType;
    int chunk;
    ImageSpaceModifierParameterData data;
    formType = file->GetTESForm();
    if (formType != 0x53)
        return false;
    LoadRecordHeader(file);
    SetInitializationState(false);
    while ((chunk = file->GetChunkID()) != 0)
    {
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
        case 0x4D414E44:  // DNAM
            file->GetChunkData(&data, sizeof(data));
            if (file->GetChunkSize() < sizeof(data))
            {
                memcpy_s(&Data, 0x3C, &data, 0x38);
                Data.m_afFirstParameterSet[14] = 1.0f;
                memcpy_s(&Data.m_afSecondParameterSet, 0x5C, &data.m_afFirstParameterSet[14], 0x5C);
            }
            else
            {
                memcpy_s(&Data, sizeof(data), &data, sizeof(data));
            }
            if (file->IsEndianConversionRequired())
                Data.Endian();
            break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

// @fnv 0x0052b3b0
TESImageSpace::~TESImageSpace()
{
    ClearData();
}

bool __cdecl TESForm_QEndianSwapOnSave();
void __cdecl AppendChunk(unsigned int, char*, unsigned int);
// @fnv 0x0052b630
void TESImageSpace::Save()
{
    BeginFormRecord();
    if (TESForm_QEndianSwapOnSave())
        Data.Endian();
    AppendChunk(0x4d414e44, (char*)&Data, sizeof(Data));
    if (TESForm_QEndianSwapOnSave())
        Data.Endian();
    FinishFormRecord();
}

// @fnv 0x0052b700
bool TESImageSpace::Compare(TESForm* apCompare)
{
    TESImageSpace* pcomp = dynamic_cast<TESImageSpace*>(apCompare);
    if (!pcomp)
        return true;
    if (TESForm::Compare((TESForm*)pcomp))
        return true;
    if (memcmp(&Data, &pcomp->Data, sizeof(Data)))
        return true;
    return false;
}

void __cdecl _Deallocate(void*);
// Runs the base destructor, then frees this object with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0052b380
void* TESImageSpace::DestroyAndDeallocate(unsigned int flags)
{
    TESImageSpace::~TESImageSpace();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

// Copies the TESImageSpace data after copying its base form.
// @fnv 0x0052b6a0
void TESImageSpace::Copy(TESForm* apCopy)
{
    ::TESImageSpace* pcopy = dynamic_cast< ::TESImageSpace*>(apCopy);
    if (!pcopy)
        return;
    TESForm::CopyFrom(pcopy);
    ::memcpy(&Data, &pcopy->Data, sizeof(Data));
}
