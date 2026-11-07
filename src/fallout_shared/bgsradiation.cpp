// fallout_shared/bgsradiation.cpp: BGSRadiationStage (10 functions)

#include "layout_support.h"
#include "../../include/BGSCameraPath.h"
#include "../../include/BGSDehydrationStage.h"
#include "../../include/BGSImpactData.h"
#include "../../include/BGSRadiationStage.h"
#include "../../include/BSShaderPPLightingProperty.h"
#include "../../include/SpellItem.h"
#include "../../include/SpellListEntry.h"
#include "bgsradiation_decls.h"
#include <typeinfo>
#include <new>
#undef IsFormInitialized

// @fnv 0x00591c80
void BGSRadiationStage::ClearData()
{
    ClearStageData(this);
}

#pragma pack(push, 4)
union RadiationLevelValue
{
    __int64 value;
    struct
    {
        unsigned int low;
        unsigned int high;
    } words;
};
#pragma pack(pop)

// @fnv 0x00592220
BGSRadiationStage* BGSRadiationStage::GetStageForLevel(float level)
{
    struct SearchState
    {
        unsigned int index;
        unsigned int result;
    };
    SearchState searchState;
    searchState.result = 0;
    searchState.index = 0;
    for (; searchState.index < DAT_011ca87c && searchState.result == 0; ++searchState.index)
    {
        BGSRadiationStage* stage = BGSRadiationStage_GetStage(searchState.index);
        if (stage != 0)
        {
            RadiationLevelValue value;
            value.words.low = (unsigned int)(reinterpret_cast<NiAVObject*>(stage)->GetParent());
            value.words.high = 0;
            if (level >= value.value)
                searchState.result = (unsigned int)stage;
        }
    }
    return reinterpret_cast<BGSRadiationStage*>(searchState.result);
}

#pragma pack(push, 4)
struct InsertStageLocals
{
    BGSRadiationStage** oldArray;
    unsigned int index;
    unsigned char pad0;
    unsigned char pad1;
    unsigned char pad2;
    unsigned char newCount;
    unsigned int newIndex;
    unsigned char pad3;
    unsigned char pad4;
    unsigned char pad5;
    unsigned char inserted;
    BGSRadiationStage** m_ppNewArray;
};
#pragma pack(pop)

// Inserts stage into the global radiation stage array ordered by condition value, reallocating the array and updating the count.
// @fnv 0x00592010
void InsertRadiationStage(BGSRadiationStage* stage)
{
    InsertStageLocals locals;
    locals.newCount = DAT_011ca87c + 1;
    locals.m_ppNewArray =
        reinterpret_cast<BGSRadiationStage**>(BGSDehydrationStage::AllocateStageArray(locals.newCount));
    locals.newIndex = 0;
    locals.inserted = false;
    for (locals.index = 0; locals.index < DAT_011ca87c; ++locals.index)
    {
        if (*(unsigned int*)reinterpret_cast<BGSCameraPath*>(stage)->GetConditions() >
                *(unsigned int*)reinterpret_cast<BGSCameraPath*>(DAT_011ca880[locals.index])->GetConditions() &&
            !locals.inserted)
        {
            locals.m_ppNewArray[locals.newIndex] = stage;
            ++locals.newIndex;
            locals.inserted = true;
        }
        locals.m_ppNewArray[locals.newIndex] = DAT_011ca880[locals.index];
        ++locals.newIndex;
    }
    if (!locals.inserted)
    {
        locals.m_ppNewArray[locals.newIndex] = stage;
        ++locals.newIndex;
    }
    locals.oldArray = DAT_011ca880;
    ::operator delete(locals.oldArray);
    DAT_011ca87c = locals.newCount;
    DAT_011ca880 = locals.m_ppNewArray;
}

// @fnv 0x00591ca0
void BGSRadiationStage::InitItem()
{
    if (GetInitialized())
    {
    }
    else
    {
        unsigned int formID = reinterpret_cast<BGSDehydrationStage*>(this)->GetSpellFormID();
        if (formID != 0)
        {
            TESForm::RemapFormIDForFile(formID, GetFile(-1));
            reinterpret_cast<BGSDehydrationStage*>(this)->SetSpell(
                dynamic_cast<SpellItem*>(TESForm::GetFormByID(formID)));
        }
        SetInitializationState(true);
        InsertRadiationStage(this);
    }
}

#pragma pack(push, 4)
struct RemoveStageLocals
{
    BGSRadiationStage** oldArray;
    unsigned int oldIndex;
    unsigned int newIndex;
    unsigned int index;
    unsigned char padding0;
    unsigned char padding1;
    unsigned char padding2;
    unsigned char found;
    unsigned int newCount;
    BGSDehydrationStage** replacement;
};
#pragma pack(pop)

// Removes the given stage from the global stage array, rebuilding the array without it and updating the count.
// @fnv 0x00592110
void BGSRadiationStage::ClearStageData(BGSRadiationStage* stage)
{
    RemoveStageLocals locals;
    if (DAT_011ca87c == 0)
    {
    }
    else
    {
        locals.found = 0;
        locals.index = 0;
        for (; locals.found == 0 && locals.index < DAT_011ca87c; ++locals.index)
        {
            if (DAT_011ca880[locals.index] == stage)
                locals.found = 1;
        }
        if (locals.found == 0)
        {
        }
        else
        {
            locals.newCount = DAT_011ca87c - 1;
            locals.replacement = BGSDehydrationStage::AllocateStageArray(locals.newCount);
            if (locals.replacement != 0)
            {
                locals.newIndex = 0;
                locals.oldIndex = 0;
                for (; locals.oldIndex < DAT_011ca87c; ++locals.oldIndex)
                {
                    if (DAT_011ca880[locals.oldIndex] != stage)
                    {
                        locals.replacement[locals.newIndex] =
                            reinterpret_cast<BGSDehydrationStage*>(DAT_011ca880[locals.oldIndex]);
                        ++locals.newIndex;
                    }
                }
            }
            locals.oldArray = DAT_011ca880;
            ::operator delete(locals.oldArray);
            DAT_011ca87c = locals.newCount;
            DAT_011ca880 = reinterpret_cast<BGSRadiationStage**>(locals.replacement);
        }
    }
}

#include <malloc.h>
// Reads a radiation stage record from the file: validates the 0x5a form type, clears data, loads the header, then handles EDID, OBND and DATA chunks.
// @fnv 0x00591ec0
bool BGSRadiationStage::Load(TESFile* file)
{
    unsigned char ucFormType = file->GetTESForm();
    if (ucFormType != 0x5a)
        return false;
    ClearData();
    LoadRecordHeader(file);
    SetInitializationState(false);
    unsigned int uiChunkID;
    while ((uiChunkID = file->GetChunkID()) != 0)
    {
        switch (uiChunkID)
        {
        case 0x44494445: {
            char* editorID = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(editorID, 512);
            SetEditorID_AtRuntime(editorID);
        }
        break;
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x41544144:
            reinterpret_cast<BGSImpactData*>(this)->ReadTypedData(
                file, reinterpret_cast<BGSCameraPath*>(this)->GetConditions(), 8);
            break;
        }
        if (uiChunkID == 0x41544144 && file->IsEndianConversionRequired())
            reinterpret_cast<DehydrationStageData*>(&data)->SwapEndian();
        if (!file->NextChunk())
            break;
    }
    return true;
}

void __cdecl _Deallocate(void*);
// Destroys the stage and frees it when flags has bit 0 set, then returns this.
// @fnv 0x00591bf0
void* BGSRadiationStage::Destroy(unsigned int flags)
{
    this->~BGSRadiationStage();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

void* __cdecl __memcpy(void*, const void*, unsigned int);
// @fnv 0x00591d30
void BGSRadiationStage::CopyFrom(const TESForm* apCopy)
{
    BGSRadiationStage* pcopy = dynamic_cast<BGSRadiationStage*>(const_cast<TESForm*>(apCopy));
    if (!pcopy)
        return;
    TESForm::CopyFrom(pcopy);
    __memcpy(((BGSCameraPath*)this)->GetConditions(), ((BGSCameraPath*)pcopy)->GetConditions(), 8);
}

int __cdecl _memcmp(const void*, const void*, unsigned int);
// @fnv 0x00591d90
bool BGSRadiationStage::Compare(TESForm* apCompare)
{
    BGSRadiationStage* pOtherStage = dynamic_cast<BGSRadiationStage*>(apCompare);
    if (!pOtherStage)
        return true;
    if (TESForm::Compare(pOtherStage))
        return true;
    if (_memcmp(((BGSCameraPath*)this)->GetConditions(), ((BGSCameraPath*)pOtherStage)->GetConditions(), 8))
        return true;
    return false;
}

// @fnv 0x00591c20
BGSRadiationStage::~BGSRadiationStage()
{
    ClearData();
}
