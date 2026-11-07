// fallout_shared/bgslightingtemplate.cpp: lighting template operations (11 functions)

#define FNV_TESFILE_H  // the shared TESFile below replaces layout_support.h's stub
#include "../../include/NiFile.h"
#include "bgslightingtemplate.h"
#include "../../include/BGSLightingTemplate.h"
#include "../../include/InteriorData.h"
#include <malloc.h>
#include <string.h>
#include "../../include/TESFile.h"

// @fnv 0x005265c0
BGSLightingTemplate::BGSLightingTemplate()
{
    SetFormType(ENUM_FORM_ID_LGTM_ID);
    ResetFormData();
}

// @fnv 0x00526710
void BGSLightingTemplate::ResetFormData()
{
    memset(&Data, 0, sizeof(Data));
}

// Reads the LGTM record header and chunks (EDID, OBND, DATA) into the lighting template, converting endianness if required.
// @fnv 0x005268a0
bool BGSLightingTemplate::Load(TESFile* file)
{
    if (static_cast<TESFileFormInt*>(file)->GetTESForm() != ENUM_FORM_ID_LGTM_ID)
        return false;
    LoadRecordHeader(file);
    int iChunkID;
    while ((iChunkID = file->GetChunkID()) != 0)
    {
        switch (iChunkID)
        {
        case 0x44494445:  // EDID
        {
            char* pEditorID = static_cast<char*>(_alloca(file->GetChunkSize()));
            file->GetChunkData(pEditorID, 0x200);
            SetEditorID_AtRuntime(pEditorID);
            break;
        }
        case 0x444E424F:  // OBND
            readOBNDSubRecord(file);
            break;
        case 0x41544144:  // DATA
            ReadTypedData(file, &Data, sizeof(Data));
            break;
        }
        if (!file->NextChunk())
            break;
    }
    if (file->IsEndianConversionRequired())
        Data.Endian();
    return true;
}

// Initializes the lighting fields, with directional fade and fog power set to 1.0f.
// @fnv 0x00526640
InteriorData::InteriorData()
{
    m_uiAmbientColor = 0;
    m_uiDirectionalColor = 0;
    m_uiFogColor = 0;
    m_fFogNear = 0.0f;
    m_fFogFar = 0.0f;
    m_uiDirectionalRotationXY = 0;
    m_uiDirectionalRotationZ = 0;
    m_fDirectionalFade = 1.0f;
    m_fFogClipDistance = 0.0f;
    m_fFogPower = 1.0f;
    m_uiTrailingValue = 0;
}

// @fnv 0x005266f0
BGSLightingTemplate::~BGSLightingTemplate()
{}

// Method-only adapter for operations not declared on the shared lighting template.
// All object layout comes from BGSLightingTemplate.
struct LightingTemplateOperations : BGSLightingTemplate
{
    void SaveForm();
    void CopyFrom(TESForm* source);
    void ClearData();
    bool Compare(TESForm* form);
};

extern "C" bool __cdecl TESForm_QEndianSwapOnSave();
// @fnv 0x00526730
void LightingTemplateOperations::SaveForm()
{
    BeginFormRecord();
    if (TESForm_QEndianSwapOnSave())
        Data.Endian();
    TESForm___SaveData(&Data, sizeof(Data));
    if (TESForm_QEndianSwapOnSave())
        Data.Endian();
    FinishFormRecord();
}

struct SwapTag
{
};

void SwapInt(int* p, SwapTag tag);

// Swaps the byte order of the ten serialized 32-bit lighting fields.
// @fnv 0x00526790
void InteriorData::Endian()
{
    SwapInt(reinterpret_cast<int*>(&m_uiAmbientColor), SwapTag());
    SwapInt(reinterpret_cast<int*>(&m_uiDirectionalColor), SwapTag());
    SwapInt(reinterpret_cast<int*>(&m_uiFogColor), SwapTag());
    SwapInt(reinterpret_cast<int*>(&m_fFogNear), SwapTag());
    SwapInt(reinterpret_cast<int*>(&m_fFogFar), SwapTag());
    SwapInt(reinterpret_cast<int*>(&m_uiDirectionalRotationXY), SwapTag());
    SwapInt(reinterpret_cast<int*>(&m_uiDirectionalRotationZ), SwapTag());
    SwapInt(reinterpret_cast<int*>(&m_fDirectionalFade), SwapTag());
    SwapInt(reinterpret_cast<int*>(&m_fFogClipDistance), SwapTag());
    SwapInt(reinterpret_cast<int*>(&m_fFogPower), SwapTag());
}

extern "C" void* __cdecl _memcpy(void* dst, const void* src, unsigned int size);

// Copies InteriorData from a BGSLightingTemplate source and calls the base class copy routine.
// @fnv 0x005269f0
void LightingTemplateOperations::CopyFrom(TESForm* apSource)
{
    BGSLightingTemplate* src = dynamic_cast<BGSLightingTemplate*>(apSource);
    if (src == 0)
    {
    }
    else
    {
        _memcpy(&Data, &src->Data, sizeof(InteriorData));
        TESForm::CopyFrom(apSource);
    }
}

// If the form is not yet initialized, clears its data and marks it as initialized.
// @fnv 0x005269c0
void LightingTemplateOperations::ClearData()
{
    if (IsFormInitialized())
        return;
    TESForm::ClearData();
    SetInitializationState(true);
}

extern "C" int __cdecl _memcmp(const void*, const void*, unsigned int);
// Returns true when the cast fails, the InteriorData bytes differ, or TESForm::Compare returns true.
// @fnv 0x00526a50
bool LightingTemplateOperations::Compare(TESForm* form)
{
    BGSLightingTemplate* other = dynamic_cast<BGSLightingTemplate*>(form);
    if (!other)
        return true;
    if (_memcmp(&Data, &other->Data, sizeof(InteriorData)))
        return true;
    if (TESForm::Compare(other))
        return true;
    return false;
}
