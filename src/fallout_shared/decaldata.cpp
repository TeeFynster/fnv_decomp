// fallout_shared/decaldata.cpp: DecalData (6 functions)

#include "decaldata_decls.h"
#include "TESFile.h"
// @fnv 0x005932b0
void DecalData::Copy(DecalData* source)
{
    if (source)
        memcpy(this, source, sizeof(DecalData::DataRecordView));
}

// @fnv 0x00593450
void DecalData::Load(TESFile* file)
{
    file->GetChunkData(this, sizeof(DecalData::DataRecordView));
    if (file->IsEndianConversionRequired())
        SwapEndianFields();
}

// @fnv 0x00593240
DecalData::DecalData()
{
    Data.m_fDecalMinHeight = 8.0f;
    Data.m_fDecalMaxHeight = 32.0f;
    Data.m_fDecalMinWidth = 8.0f;
    Data.m_fDecalMaxWidth = 32.0f;
    Data.m_ucParallaxPasses = 4;
    Data.m_fParallaxScale = 1.0f;
    Data.m_fProjectionDepth = 32.0f;
    Data.m_fShininess = 4.0f;
    Data.iColor = 0xFFFFFFFF;
}

struct FUN_005932e0_shell
{
    bool __thiscall Compare(void* apCompare);
};

extern int __cdecl _memcmp(const void*, const void*, int);

// Returns true if apCompare is null or the first 0x24 bytes differ from this; otherwise returns false.
// @fnv 0x005932e0
bool __thiscall FUN_005932e0_shell::Compare(void* apCompare)
{
    if (apCompare == 0)
        return true;
    if (_memcmp(this, apCompare, 0x24) != 0)
        return true;
    return false;
}

template <int N> struct EndianSizeTag
{
};

void __cdecl BSEndian(int*, EndianSizeTag<4>);

struct FUN_00593370_shell
{
    void SwapEndianFields();
};

// Byte-swaps eight 4-byte fields of this object via BSEndian, in the order 0,1,2,3,6,4,5,8.
// @fnv 0x00593370
void FUN_00593370_shell::SwapEndianFields()
{
    BSEndian((int*)this, EndianSizeTag<4>());
    BSEndian((int*)this + 1, EndianSizeTag<4>());
    BSEndian((int*)this + 2, EndianSizeTag<4>());
    BSEndian((int*)this + 3, EndianSizeTag<4>());
    BSEndian((int*)this + 6, EndianSizeTag<4>());
    BSEndian((int*)this + 4, EndianSizeTag<4>());
    BSEndian((int*)this + 5, EndianSizeTag<4>());
    BSEndian((int*)this + 8, EndianSizeTag<4>());
}

bool __cdecl TESForm_QEndianSwapOnSave();
void __cdecl AppendChunk(void*, void*, unsigned int);
struct FUN_00593320_shell
{
    void ProcessState_00593320(void*);
};
// @fnv 0x00593320
// src: GUESS 0x00593320 (confidence: low)
void FUN_00593320_shell::ProcessState_00593320(void* a1)
{
    if (TESForm_QEndianSwapOnSave())
        ((DecalData*)this)->SwapEndianFields();
    AppendChunk(a1, this, 0x24);
    if (TESForm_QEndianSwapOnSave())
        ((DecalData*)this)->SwapEndianFields();
}
