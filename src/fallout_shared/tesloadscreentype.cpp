// fallout_shared/tesloadscreentype.cpp: TESLoadScreenType, LoadScreenTypeData_FUN (7 functions)

#include "tesloadscreentype_decls.h"
#include "../../include/TESLoadScreenType.h"
#include "../../include/Script.h"

// Reads the record header and chunks (EDID, OBND, DATA) from file, applies endian conversion to data, and returns true.
// @fnv 0x005a72f0
bool TESLoadScreenType::LoadForm(TESFile* file)
{
    LoadRecordHeader(file);
    SetInitializationState(false);
    unsigned int chunk;
    while ((chunk = file->GetChunkID()) != 0)
    {
        switch (chunk)
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
            ReadTypedData(file, formData, 88);
            break;
        }
        if (!file->NextChunk())
            break;
    }
    if (file->IsEndianConversionRequired())
        ((LoadScreenTypeData*)formData)->Endian();
    return true;
}

void* __cdecl __memcpy(void* dst, const void* src, unsigned int size);

// @fnv 0x005a7690
void TESLoadScreenType::CopyFrom(const TESForm* apCopy)
{
    TESLoadScreenType* pmisc = (TESLoadScreenType*)dynamic_cast<TESLoadScreenType*>((TESForm*)apCopy);
    if (!pmisc)
    {
        return;
    }
    __memcpy(formData, pmisc->formData, 0x58);
    TESForm::CopyFrom(apCopy);
}

bool __cdecl FUN_00401500();
// Saves the form data, converting its byte order before and after writing when required.
// @fnv 0x005a7630
void TESLoadScreenType::SaveForm()
{
    FUN_004855a0();
    if (FUN_00401500())
        ((LoadScreenTypeData*)formData)->Endian();
    FUN_00485e20(formData, 0x58);
    if (FUN_00401500())
        ((LoadScreenTypeData*)formData)->Endian();
    FUN_00485680();
}

int __cdecl _memcmp(const void*, const void*, unsigned int);
// Compares the form data and inherited fields, returning true when either differs or the cast fails.
// @fnv 0x005a76f0
bool TESLoadScreenType::Compare(TESForm* apCompare)
{
    TESLoadScreenType* pcomp = dynamic_cast<TESLoadScreenType*>(apCompare);
    if (!pcomp)
        return true;
    if (_memcmp(formData, ((Script*)pcomp)->GetHeader(), 0x58))
        return true;
    if (TESForm::Compare(pcomp))
        return true;
    return false;
}

// @fnv 0x005a72d0
TESLoadScreenType::~TESLoadScreenType()
{}

struct EndianTag
{
};
void __cdecl FUN_00401080(int* apValue, EndianTag aTag);
struct LoadScreenTypeData_FUN
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
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    void SwapEndianFields();
};
// Byte-swaps every integer field of the structure by calling FUN_00401080 on each member.
// @fnv 0x005a7400
void LoadScreenTypeData_FUN::SwapEndianFields()
{
    FUN_00401080(&unk28, EndianTag());
    FUN_00401080(&unk10, EndianTag());
    FUN_00401080(&unk04, EndianTag());
    FUN_00401080(&unk08, EndianTag());
    FUN_00401080(&unk14, EndianTag());
    FUN_00401080(&unk0C, EndianTag());
    FUN_00401080(&unk1C, EndianTag());
    FUN_00401080(&unk20, EndianTag());
    FUN_00401080(&unk24, EndianTag());
    FUN_00401080(&unk38, EndianTag());
    FUN_00401080(&unk2C, EndianTag());
    FUN_00401080(&unk30, EndianTag());
    FUN_00401080(&unk3C, EndianTag());
    FUN_00401080(&unk34, EndianTag());
    FUN_00401080(&unk44, EndianTag());
    FUN_00401080(&unk48, EndianTag());
    FUN_00401080(&unk4C, EndianTag());
    FUN_00401080(&unk50, EndianTag());
    FUN_00401080(&unk00, EndianTag());
    FUN_00401080(&unk18, EndianTag());
    FUN_00401080(&unk40, EndianTag());
    FUN_00401080(&unk54, EndianTag());
}
