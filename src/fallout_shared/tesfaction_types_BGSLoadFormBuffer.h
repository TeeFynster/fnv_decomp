// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BGSLOADFORMBUFFER_H
#define FNV_BGSLOADFORMBUFFER_H

#include "layout_support.h"
#include "../../include/TESForm.h"
class FormChangeMask;
class BGSLoadFormBuffer;
class BGSLoadGameBuffer;
class PackedFormID;
class FormLoadContext;
class BGSSaveLoadFormInfo;
#pragma pack(push, 4)
class BGSLoadGameBuffer
{
  public:
    void** m_ppVirtualMethodTable;               // +0x0, 4 bytes
    char* pBuffer;                 // +0x4, 4 bytes
    unsigned int iBufferSize;      // +0x8, 4 bytes
    unsigned int m_uiReadOffset;  // +0xC, 4 bytes
    // BGSLoadGameBuffer
    // void __cdecl BGSLoadGameBuffer::*()
    // Load
    // void __cdecl BGSLoadGameBuffer::*()
    // void __cdecl BGSLoadGameBuffer::*(char*, unsigned int, unsigned int)
    // char* __cdecl BGSLoadGameBuffer::*()
    // ReadTypedData
    // char* __cdecl BGSLoadGameBuffer::*(char*)
    // int __cdecl BGSLoadGameBuffer::*()
    // void __cdecl BGSLoadGameBuffer::*(unsigned int)
    // void __cdecl BGSLoadGameBuffer::*(void*, unsigned int, unsigned int)
    // void __cdecl BGSLoadGameBuffer::*(void*, unsigned int)
    // BGSLoadGameBuffer& __cdecl BGSLoadGameBuffer::*(const BGSLoadGameBuffer&)
    // void* __cdecl BGSLoadGameBuffer::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSLoadGameBuffer) == 16);
FNV_STATIC_ASSERT(offsetof(BGSLoadGameBuffer, m_ppVirtualMethodTable) == 0);
FNV_STATIC_ASSERT(offsetof(BGSLoadGameBuffer, pBuffer) == 4);
FNV_STATIC_ASSERT(offsetof(BGSLoadGameBuffer, iBufferSize) == 8);
FNV_STATIC_ASSERT(offsetof(BGSLoadGameBuffer, m_uiReadOffset) == 12);
#pragma pack(push, 4)
class PackedFormID
{
  public:
    unsigned char m_ucIDByte0;  // +0x0, 1 bytes
    unsigned char m_ucIDByte1;  // +0x1, 1 bytes
    unsigned char m_ucIDByte2;  // +0x2, 1 bytes
    // void __cdecl PackedFormID::*()
    // unsigned int __cdecl PackedFormID::*()
    // void __cdecl PackedFormID::*(unsigned int)
    // bool __cdecl PackedFormID::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(PackedFormID) == 3);
FNV_STATIC_ASSERT(offsetof(PackedFormID, m_ucIDByte0) == 0);
FNV_STATIC_ASSERT(offsetof(PackedFormID, m_ucIDByte1) == 1);
FNV_STATIC_ASSERT(offsetof(PackedFormID, m_ucIDByte2) == 2);
#pragma pack(push, 4)
class FormChangeMask
{
  public:
    operator bool() const;
    int iFlags;  // +0x0, 4 bytes
    // FormChangeMask
    // bool __cdecl FormChangeMask::*(int)
    // bool __cdecl FormChangeMask::*(int)
    // bool __cdecl FormChangeMask::*(int)
    // void __cdecl FormChangeMask::*(int)
    // void __cdecl FormChangeMask::*(int)
    // void __cdecl FormChangeMask::*(int)
    // FormChangeMask __cdecl FormChangeMask::*(int)
    // int __cdecl FormChangeMask::*()
    // const char* __cdecl FormChangeMask::*(int, unsigned int, bool)
    // const char* __cdecl FormChangeMask::*(int, unsigned int)
    // bool __cdecl FormChangeMask::*(int, unsigned int, unsigned int)
    // bool __cdecl FormChangeMask::*(TESForm*)
    // FormChangeMask __cdecl FormChangeMask::*(FormChangeMask, FormChangeMask, unsigned int, bool)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(FormChangeMask) == 4);
FNV_STATIC_ASSERT(offsetof(FormChangeMask, iFlags) == 0);
#pragma pack(push, 4)
class BGSSaveLoadFormInfo
{
  public:
    unsigned char cData;  // +0x0, 1 bytes
    // void __cdecl BGSSaveLoadFormInfo::*()
    // ENUM_FORM_ID __cdecl BGSSaveLoadFormInfo::*()
    // void __cdecl BGSSaveLoadFormInfo::*(ENUM_FORM_ID)
    // SIZE_TYPE __cdecl BGSSaveLoadFormInfo::*()
    // void __cdecl BGSSaveLoadFormInfo::*(SIZE_TYPE)
    // void __cdecl BGSSaveLoadFormInfo::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSSaveLoadFormInfo) == 1);
FNV_STATIC_ASSERT(offsetof(BGSSaveLoadFormInfo, cData) == 0);
#pragma pack(push, 1)
class FormLoadContext
{
  public:
    PackedFormID m_kFormIDIndex;   // +0x0, 3 bytes
    FormChangeMask m_pDeathItem;   // +0x3, 4 bytes
    BGSSaveLoadFormInfo FormInfo;  // +0x7, 1 bytes
    unsigned char cVersion;        // +0x8, 1 bytes
    // void __cdecl FormLoadContext::*()
    // void __cdecl FormLoadContext::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(FormLoadContext) == 9);
FNV_STATIC_ASSERT(offsetof(FormLoadContext, m_kFormIDIndex) == 0);
FNV_STATIC_ASSERT(offsetof(FormLoadContext, m_pDeathItem) == 3);
FNV_STATIC_ASSERT(offsetof(FormLoadContext, FormInfo) == 7);
FNV_STATIC_ASSERT(offsetof(FormLoadContext, cVersion) == 8);
#pragma pack(push, 4)
class BGSLoadFormBuffer : public BGSLoadGameBuffer
{
  public:
    // base BGSLoadGameBuffer at +0x0, size 16
    unsigned int iFormID;    // +0x10, 4 bytes
    FormLoadContext Header;  // +0x14, 9 bytes
    unsigned char layoutPadding1D[3];
    unsigned int iSize;               // +0x20, 4 bytes
    TESForm* pForm;                   // +0x24, 4 bytes
    unsigned int iFlags;              // +0x28, 4 bytes
    FormChangeMask m_cReservedBytes;  // +0x2C, 4 bytes
    FormChangeMask GetChangeFlags(unsigned int);
    FormChangeMask GetOldChangeFlags(unsigned int);
    void ReadTypedData(void*, unsigned int);
    // BGSLoadFormBuffer
    // unsigned int __cdecl BGSLoadFormBuffer::*()
    // void __cdecl BGSLoadFormBuffer::*(TESForm*)
    // TESForm* __cdecl BGSLoadFormBuffer::*()
    // TESObjectREFR* __cdecl BGSLoadFormBuffer::*()
    // Actor* __cdecl BGSLoadFormBuffer::*()
    // ENUM_FORM_ID __cdecl BGSLoadFormBuffer::*()
    // FormChangeMask __cdecl BGSLoadFormBuffer::*()
    // void __cdecl BGSLoadFormBuffer::*(FormChangeMask)
    // FormChangeMask __cdecl BGSLoadFormBuffer::*()
    // void __cdecl BGSLoadFormBuffer::*(FormChangeMask)
    // void __cdecl BGSLoadFormBuffer::*(unsigned char)
    // unsigned char __cdecl BGSLoadFormBuffer::*()
    // void __cdecl BGSLoadFormBuffer::*(bool)
    // bool __cdecl BGSLoadFormBuffer::*()
    // void __cdecl BGSLoadFormBuffer::*(bool)
    // bool __cdecl BGSLoadFormBuffer::*()
    // void __cdecl BGSLoadFormBuffer::*(bool)
    // bool __cdecl BGSLoadFormBuffer::*()
    // void __cdecl BGSLoadFormBuffer::*(bool)
    // bool __cdecl BGSLoadFormBuffer::*()
    // void __cdecl BGSLoadFormBuffer::*(bool)
    // bool __cdecl BGSLoadFormBuffer::*()
    // void __cdecl BGSLoadFormBuffer::*()
    // BGSLoadFormBuffer& __cdecl BGSLoadFormBuffer::*(const BGSLoadFormBuffer&)
    // void* __cdecl BGSLoadFormBuffer::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSLoadFormBuffer) == 48);
FNV_STATIC_ASSERT(offsetof(BGSLoadFormBuffer, iFormID) == 16);
FNV_STATIC_ASSERT(offsetof(BGSLoadFormBuffer, Header) == 20);
FNV_STATIC_ASSERT(offsetof(BGSLoadFormBuffer, iSize) == 32);
FNV_STATIC_ASSERT(offsetof(BGSLoadFormBuffer, pForm) == 36);
FNV_STATIC_ASSERT(offsetof(BGSLoadFormBuffer, iFlags) == 40);
FNV_STATIC_ASSERT(offsetof(BGSLoadFormBuffer, m_cReservedBytes) == 44);
#endif
