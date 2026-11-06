// Unit-local helpers for fallout_shared/tessound.cpp.
#ifndef FNV_TESSOUND_UNIT_H
#define FNV_TESSOUND_UNIT_H

#include "layout_support.h"
#include "../../include/TESForm.h"
#include "TESFile.h"
// Unit-local copy of the 12-byte legacy SNDX sound header (first fields of
// it, then copies the fields into data.
#pragma pack(push, 4)
class TESSound__SOUND_DATA2
{
  public:
    unsigned char iMin;                    // +0x0
    unsigned char iMax;                    // +0x1
    char m_cPitchAdjustment;               // +0x2
    unsigned char m_ucUnused;              // +0x3
    unsigned int iFlags;                   // +0x4
    unsigned short m_uiFrequency;          // +0x8
    unsigned short m_aucAttenuationBytes;  // +0xA
    void Endian();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESSound__SOUND_DATA2) == 12);
// The 2008 TESSound.cpp saw a 32-bit TESFile::GetTESForm: the Load form
// check compares the call result with cmp eax,imm and no movzx, which is
// unreproducible through the closure's unsigned char declaration (any use of
// a uchar call result in a 32-bit compare extends it). The shim below recovers
// the original static type; it binds the real GetTESForm target.
struct TESFileFormInt : public TESFile
{
    int GetTESForm();
};
// Zero-size tag used to select the 16-bit overload below. The tag is passed
// as a value-initialized temporary, which is why each call site materializes
// a zero byte on the stack.
template <int Value> struct EndianSizeTag
{
};
void BSEndian(unsigned short* data, EndianSizeTag<2> type);
// MEM_CONTEXT as in include/layout_support.h (the unit-local layout_support.h in this directory, which wine resolves
// first, does not declare it).
#include "../../include/MEM_CONTEXT.h"
#endif
