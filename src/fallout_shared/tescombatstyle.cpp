// fallout_shared/tescombatstyle.cpp: TESCombatStyle (10 functions)

#include "tescombatstyle_decls.h"
// @fnv 0x00505010
TESCombatStyle::TESCombatStyle()
{
    SetFormType((ENUM_FORM_ID)0x4a);
    ResetFormData();
}
// Copies 0x5c, 0x54 and 0x40 bytes from the combat style returned by FUN_00505000 into Data and two other members, or zeroes them if none.
// @fnv 0x005050d0
void TESCombatStyle::ResetFormData()
{
    TESCombatStyle* style = TESCombatStyle_GetDefaultCombatStyle();
    if (style)
    {
        memcpy(&Data, &GetCombatStyleData(style), 0x5c);
        memcpy(&m_kUInt32ChunkData, GetCombatStyleAdvancedData(style), 0x54);
        memcpy(&m_kUnsignedIntArray16, GetHungerStageData((BGSHungerStage*)style), 0x40);
    }
    else
    {
        memset(&Data, 0, 0x5c);
        memset(&m_kUInt32ChunkData, 0, 0x54);
        memset(&m_kUnsignedIntArray16, 0, 0x40);
    }
}
extern "C" void* __cdecl _alloca(unsigned int);
#pragma intrinsic(_alloca)
// Reads a combat style record from the file, loading its editor ID, OBND, and CSDT/CSAD/CSSD chunks, then applies version-dependent defaults.
// @fnv 0x00505180
bool TESCombatStyle::Load(TESFile* file)
{
    unsigned char type = file->GetTESForm();
    if (type != 0x4a)
        return false;
    ClearData();
    LoadRecordHeader(file);
    SetInitializationState(false);
    int chunk;
    while (chunk = file->GetChunkID())
    {
        switch (chunk)
        {
        case 0x44494445: {
            char* name = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(name, 0x200);
            SetEditorID_AtRuntime(name);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x44545343:
            file->GetChunkData(&Data, 0x5c);
            if (((TESFileExtra*)file)->FUN_00401680())
                Data.SwapEndianFields();
            break;
        case 0x44415343:
            file->GetChunkData(&m_kUInt32ChunkData, 0x54);
            if (((TESFileExtra*)file)->FUN_00401680())
                SwapUInt32ChunkData(&m_kUInt32ChunkData);
            break;
        case 0x44535343:
            file->GetChunkData(&m_kUnsignedIntArray16, 0x40);
            if (((TESFileExtra*)file)->FUN_00401680())
            {
                UnsignedIntArray16 saved;
                unsigned int size = file->GetChunkSize();
                if (size < 0x40)
                    memcpy(&saved, &m_kUnsignedIntArray16, 0x40);
                m_kUnsignedIntArray16.SwapEndianFields();
                if (size < 0x40)
                    memcpy((char*)&m_kUnsignedIntArray16 + size, (char*)&saved + size, 0x40 - size);
            }
            break;
        }
        if (!file->NextChunk())
            break;
    }
    if (((TESFileFormVersion*)file)->GetFormVersion() < 12)
    {
        ((float*)&m_kUnsignedIntArray16)[8] = 1.0f;
        ((float*)&m_kUnsignedIntArray16)[11] = 1.0f;
    }
    return true;
}

extern "C" int __cdecl memcmp(const void*, const void*, unsigned int);

// A one-word aggregate stays on the stack under fastcall, preserving the
// original thiscall argument layout for helpers absent from the shared class.
struct CombatStyleFormArgument
{
    TESForm* form;
};

bool __fastcall CompareCombatStyleBase(TESCombatStyle* self, void*, TESCombatStyle* other);

// @fnv 0x00505550
bool __fastcall IsCombatStyleDifferent(TESCombatStyle* self, CombatStyleFormArgument apCompare)
{
    TESCombatStyle* pcomp = dynamic_cast<TESCombatStyle*>(apCompare.form);
    if (!pcomp)
        return true;
    if (reinterpret_cast<bool (__thiscall*)(TESCombatStyle*, TESCombatStyle*)>(CompareCombatStyleBase)(self, pcomp))
        return true;
    if (memcmp(&GetCombatStyleData(self), &GetCombatStyleData(pcomp), 0x5c))
        return true;
    if (memcmp(GetCombatStyleAdvancedData(self), GetCombatStyleAdvancedData(pcomp), 0x54))
        return true;
    if (memcmp(GetHungerStageData((BGSHungerStage*)self), GetHungerStageData((BGSHungerStage*)pcomp), 0x40))
        return true;
    return false;
}

void __fastcall DestroyCombatStyle(TESCombatStyle* self);
void _Deallocate(void*);
// Destroys the combat style, then deallocates it when flags has bit 0 set.
// @fnv 0x00505080
void* __fastcall DeleteCombatStyle(TESCombatStyle* self, void*, unsigned int flags)
{
    DestroyCombatStyle(self);
    if (flags & 1)
        _Deallocate(self);
    return self;
}

bool __cdecl TESForm_QEndianSwapOnSave();

void __cdecl AppendChunk(unsigned int, void*, unsigned int);

// @fnv 0x005053c0
void __fastcall SaveCombatStyle(TESCombatStyle* self)
{
    self->BeginFormRecord();
    if (TESForm_QEndianSwapOnSave())
        self->Data.SwapEndianFields();
    AppendChunk(0x44545343, &self->Data, 0x5c);
    if (TESForm_QEndianSwapOnSave())
        self->Data.SwapEndianFields();
    if (TESForm_QEndianSwapOnSave())
        SwapUInt32ChunkData(&self->m_kUInt32ChunkData);
    AppendChunk(0x44415343, &self->m_kUInt32ChunkData, 0x54);
    if (TESForm_QEndianSwapOnSave())
        SwapUInt32ChunkData(&self->m_kUInt32ChunkData);
    if (TESForm_QEndianSwapOnSave())
        self->m_kUnsignedIntArray16.SwapEndianFields();
    AppendChunk(0x44535343, &self->m_kUnsignedIntArray16, 0x40);
    if (TESForm_QEndianSwapOnSave())
        self->m_kUnsignedIntArray16.SwapEndianFields();
    self->FinishFormRecord();
}

void __memcpy(void* __dst, const void* __src, unsigned int __n);

void __fastcall CopyCombatStyleBase(TESCombatStyle* self, void*, TESForm* apCopy);

// Casts apCopy to TESCombatStyle, calls FUN_004851b0, then memcpy's three sub-objects (0x5c, 0x54, 0x40 bytes) from the copy into this.
// @fnv 0x005054b0
void __fastcall CopyFromCombatStyle(TESCombatStyle* self, CombatStyleFormArgument apCopy)
{
    TESForm* pcopy = dynamic_cast<TESForm*>(dynamic_cast<TESCombatStyle*>(apCopy.form));
    if (!pcopy)
        return;
    reinterpret_cast<void (__thiscall*)(TESCombatStyle*, TESForm*)>(CopyCombatStyleBase)(self, pcopy);
    __memcpy(&GetCombatStyleData(self), &GetCombatStyleData(reinterpret_cast<TESCombatStyle*>(pcopy)), 0x5c);
    __memcpy(GetCombatStyleAdvancedData(self),
             GetCombatStyleAdvancedData(reinterpret_cast<TESCombatStyle*>(pcopy)), 0x54);
    __memcpy(GetHungerStageData(reinterpret_cast<BGSHungerStage*>(self)),
             GetHungerStageData(reinterpret_cast<BGSHungerStage*>(pcopy)), 0x40);
}

template <int N> struct EndianSizeTag
{
};

typedef EndianSizeTag<0> BSIntToType0;

void __cdecl BSEndian(unsigned char*, BSIntToType0);

// @fnv 0x005057a0
void __fastcall SwapUInt32ChunkData(UInt32ChunkData* self)
{
    BSEndian((unsigned char*)self + 0x00, BSIntToType0());
    BSEndian((unsigned char*)self + 0x04, BSIntToType0());
    BSEndian((unsigned char*)self + 0x08, BSIntToType0());
    BSEndian((unsigned char*)self + 0x0C, BSIntToType0());
    BSEndian((unsigned char*)self + 0x10, BSIntToType0());
    BSEndian((unsigned char*)self + 0x14, BSIntToType0());
    BSEndian((unsigned char*)self + 0x18, BSIntToType0());
    BSEndian((unsigned char*)self + 0x1C, BSIntToType0());
    BSEndian((unsigned char*)self + 0x20, BSIntToType0());
    BSEndian((unsigned char*)self + 0x24, BSIntToType0());
    BSEndian((unsigned char*)self + 0x28, BSIntToType0());
    BSEndian((unsigned char*)self + 0x2C, BSIntToType0());
    BSEndian((unsigned char*)self + 0x30, BSIntToType0());
    BSEndian((unsigned char*)self + 0x34, BSIntToType0());
    BSEndian((unsigned char*)self + 0x38, BSIntToType0());
    BSEndian((unsigned char*)self + 0x3C, BSIntToType0());
    BSEndian((unsigned char*)self + 0x40, BSIntToType0());
    BSEndian((unsigned char*)self + 0x48, BSIntToType0());
    BSEndian((unsigned char*)self + 0x44, BSIntToType0());
    BSEndian((unsigned char*)self + 0x4C, BSIntToType0());
    BSEndian((unsigned char*)self + 0x50, BSIntToType0());
}

namespace fnv_005059c0 {
template <int N> struct EndianSizeTag
{
    unsigned char value;
};

void __cdecl BSEndian(unsigned char*, EndianSizeTag<9>);

}  // namespace fnv_005059c0

// @fnv 0x005059c0
void StatsChunkData::SwapEndianFields()
{

    fnv_005059c0::BSEndian(reinterpret_cast<unsigned char*>(this) + 0x04, fnv_005059c0::EndianSizeTag<9>());
    fnv_005059c0::BSEndian(reinterpret_cast<unsigned char*>(this) + 0x08, fnv_005059c0::EndianSizeTag<9>());
    fnv_005059c0::BSEndian(reinterpret_cast<unsigned char*>(this) + 0x0c, fnv_005059c0::EndianSizeTag<9>());
    fnv_005059c0::BSEndian(reinterpret_cast<unsigned char*>(this) + 0x10, fnv_005059c0::EndianSizeTag<9>());
    fnv_005059c0::BSEndian(reinterpret_cast<unsigned char*>(this) + 0x14, fnv_005059c0::EndianSizeTag<9>());
    fnv_005059c0::BSEndian(reinterpret_cast<unsigned char*>(this) + 0x18, fnv_005059c0::EndianSizeTag<9>());
    fnv_005059c0::BSEndian(reinterpret_cast<unsigned char*>(this) + 0x1c, fnv_005059c0::EndianSizeTag<9>());
    fnv_005059c0::BSEndian(reinterpret_cast<unsigned char*>(this) + 0x20, fnv_005059c0::EndianSizeTag<9>());
    fnv_005059c0::BSEndian(reinterpret_cast<unsigned char*>(this) + 0x28, fnv_005059c0::EndianSizeTag<9>());
    fnv_005059c0::BSEndian(reinterpret_cast<unsigned char*>(this) + 0x2c, fnv_005059c0::EndianSizeTag<9>());
    fnv_005059c0::BSEndian(reinterpret_cast<unsigned char*>(this) + 0x30, fnv_005059c0::EndianSizeTag<9>());
    fnv_005059c0::BSEndian(reinterpret_cast<unsigned char*>(this) + 0x38, fnv_005059c0::EndianSizeTag<9>());
    fnv_005059c0::BSEndian(reinterpret_cast<unsigned char*>(this) + 0x3c, fnv_005059c0::EndianSizeTag<9>());
    fnv_005059c0::BSEndian(reinterpret_cast<unsigned char*>(this) + 0x48, fnv_005059c0::EndianSizeTag<9>());
    fnv_005059c0::BSEndian(reinterpret_cast<unsigned char*>(this) + 0x4c, fnv_005059c0::EndianSizeTag<9>());
    fnv_005059c0::BSEndian(reinterpret_cast<unsigned char*>(this) + 0x58, fnv_005059c0::EndianSizeTag<9>());
    fnv_005059c0::BSEndian(reinterpret_cast<unsigned char*>(this) + 0x50, fnv_005059c0::EndianSizeTag<9>());
}

void __cdecl BSEndianUInt(unsigned int* apData, BSIntToType0);

// Byte-swaps each of the 15 data words in place via BSEndianUInt.
// @fnv 0x00505610
void UnsignedIntArray16::SwapEndianFields()
{
    BSEndianUInt(&data[0], BSIntToType0());
    BSEndianUInt(&data[1], BSIntToType0());
    BSEndianUInt(&data[2], BSIntToType0());
    BSEndianUInt(&data[3], BSIntToType0());
    BSEndianUInt(&data[4], BSIntToType0());
    BSEndianUInt(&data[5], BSIntToType0());
    BSEndianUInt(&data[6], BSIntToType0());
    BSEndianUInt(&data[7], BSIntToType0());
    BSEndianUInt(&data[8], BSIntToType0());
    BSEndianUInt(&data[11], BSIntToType0());
    BSEndianUInt(&data[9], BSIntToType0());
    BSEndianUInt(&data[12], BSIntToType0());
    BSEndianUInt(&data[13], BSIntToType0());
    BSEndianUInt(&data[14], BSIntToType0());
    BSEndianUInt(&data[15], BSIntToType0());
}
