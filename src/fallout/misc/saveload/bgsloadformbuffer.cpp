// fallout/misc/saveload/bgsloadformbuffer.cpp: BGSLoadFormBuffer (16 functions)

#include "../../../../include/BGSLoadFormBuffer.h"
#include "../../../../include/BGSLoadGameBuffer.h"
#include "bgsloadformbuffer_decls.h"
#include "../../../../include/TESChildCell.h"

// @fnv 0x008a81c0
unsigned char BGSLoadFormBuffer::GetVersion()
{
    return reinterpret_cast<FormLoadContext*>(Header)->cVersion;
}

// Initializes the load form buffer by zeroing iFormID, iSize, pForm and iFlags.
// @fnv 0x008643b0
BGSLoadFormBuffer::BGSLoadFormBuffer()
{
    iFormID = 0;
    reinterpret_cast<FormLoadContext*>(Header)->FormLoadContext::FormLoadContext();
    iSize = 0;
    pForm = 0;
    iFlags = 0;
    reinterpret_cast<FormChangeMask*>(&iOldChangeFlags)->FormChangeMask::FormChangeMask();
}

// @fnv 0x00864610
TESObjectREFR* BGSLoadFormBuffer::GetReference()
{
    TESForm* form = GetForm();
    if (form && form->GetIsReference())
        return reinterpret_cast<TESObjectREFR*>(form);
    return 0;
}

// @fnv 0x00864660
Actor* BGSLoadFormBuffer::GetActor()
{
    TESForm* form = reinterpret_cast<TESForm*>(GetReference());
    if (form && form->IsActor())
        return reinterpret_cast<Actor*>(form);
    return 0;
}

// @fnv 0x008645b0
TESForm* BGSLoadFormBuffer::GetForm()
{
    if (!pForm && IsFlag2Set())
        pForm = GetFormByID(iFormID);
    return pForm;
}

// @fnv 0x00864580
void BGSLoadFormBuffer::SkipData(SaveLoadFile* file, unsigned int size)
{
    unsigned int remaining;
    if (remaining = iSize - size)
        file->AdvancePosition(iSize - size);
}

struct Dummy84eaf0
{
    void ClearNumericIDIndex();
};

struct Dummy864490
{
    void MOVABLE_STATIC_DATA_MOVABLE_STATIC_DATA();
};

// @fnv 0x00864450
// src: COMMUNITY 0x00864450
FormLoadContext* __fastcall BGSSaveLoadFormHeader_BGSSaveLoadFormHeader(FormLoadContext* apObject)
{
    reinterpret_cast<Dummy84eaf0*>(apObject)->ClearNumericIDIndex();
    reinterpret_cast<FormChangeMask*>(reinterpret_cast<char*>(apObject) + 3)->FormChangeMask::FormChangeMask();
    reinterpret_cast<Dummy864490*>(reinterpret_cast<char*>(apObject) + 7)->MOVABLE_STATIC_DATA_MOVABLE_STATIC_DATA();
    *(reinterpret_cast<unsigned char*>(apObject) + 8) = 0;
    return apObject;
}

// @fnv 0x00864490
// src: XBOX_PDB 0x00864490
char* __fastcall MOVABLE_STATIC_DATA_MOVABLE_STATIC_DATA(char* p)
{
    *p = 0;
    return p;
}

#include "../../../../include/SIZE_TYPE.h"
unsigned int __cdecl ReadSizedUnsignedInt(SaveLoadFile*, unsigned int&, SIZE_TYPE);
unsigned int __fastcall BGSNumericIDIndex_GetNumericID(void*);
SIZE_TYPE __fastcall BGSSaveLoadFormInfo_GetSizeType(void*);

struct BGSSaveLoadFile_Read_shell : public SaveLoadFile
{
    unsigned int Read(void*, unsigned int);
};

// @fnv 0x008644b0
int BGSLoadFormBuffer::LoadHeader(SaveLoadFile* apFile)
{
    SIZE_TYPE esizeType;
    unsigned int iLoadedSize;

    ((BGSSaveLoadFile_Read_shell*)apFile)->Read(Header, 9);
    iFormID = BGSNumericIDIndex_GetNumericID(Header);
    esizeType = BGSSaveLoadFormInfo_GetSizeType(Header + 7);
    iLoadedSize = ReadSizedUnsignedInt(apFile, iSize, esizeType);
    if (iLoadedSize != iSize)
        return -1;
    return iLoadedSize;
}

struct FUN_00864520_shell : public BGSSaveLoadFormInfo
{
    int BGSSaveLoadFormInfo_GetSizeType();
};

// @fnv 0x00864520
// src: XBOX_PDB 0x00864520
int FUN_00864520_shell::BGSSaveLoadFormInfo_GetSizeType()
{
    return *(unsigned char*)this >> 6;
}

// @fnv 0x00864540
int BGSLoadFormBuffer::ReadFormData(SaveLoadFile* file)
{
    int r = Load(file, iSize);
    if (r != iSize)
        return -1;
    return r;
}

// @fnv 0x008645f0
bool BGSLoadFormBuffer::IsFlag2Set()
{
    return (iFlags & 2) ? true : false;
}

