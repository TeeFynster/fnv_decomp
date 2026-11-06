
// src/fallout_shared/tesidleform_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tesidleform.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "tesidleform_match_decls.h"
// layout_support.h already defines BSSimpleList.
#define FNV64_BSSIMPLELIST_DEFINED
#include "../../include/LowProcess.h"
// strrchr comes from <string.h> (read through include/TESFile.h)
extern "C" int __cdecl stricmp(const char* string1, const char* string2);
template <int N> struct EndianSizeTag
{
};
void __cdecl BSEndian(unsigned short*, EndianSizeTag<2>);
struct FUN_005fea20_shell
{
    void SwapEndian();
};
struct FUN_005ff190_shell
{
    char pad[0x38];
    unsigned char m_0x38;
    void FUN_005ff190(bool set);
};
struct FUN_005ff1d0_shell : public TESIdleForm
{
    bool FUN_005ff1d0();
};
struct FUN_005ff200_shell
{
    unsigned char m_0x38;
    bool IsFlag40Set();
};
struct FUN_005ff220_shell
{
    void SetFlag40(bool bFlag);
};
struct FUN_005ff260_shell
{
    unsigned char m_3e;
    bool FUN_005ff260();
};
struct FUN_005ff4a0_shell : public TESIdleForm
{
    unsigned int FUN_005ff4a0();
};
struct FUN_005ff160_shell : public TESIdleForm
{
    int GetFlagsMasked();
};
struct FUN_00600d90_shell
{
    void FUN_00600d90();
};
struct FUN_00600d70_shell
{
    void FUN_00600d70();
};

// FUN_005ff880 : 8-byte MSVC this-adjusting (virtual) thunk.
//     sub ecx, 0x18 ; jmp FUN_005fe130
//
// MSVC emits such a stub in the vtable of a class that inherits the same
// virtual slot through two bases: the slot of the second base holds a tiny
// stub that moves `this` back onto the complete object (sub ecx, size of the
// primary base) and tail-jumps to the implementation.
//
// The subtracted offset is therefore the size of the primary base: a vtable
// pointer plus 5 int members (4 + 20 = 0x18 bytes).  Both bases declare the
// same virtual function; the derived class redeclares it and defines only its
// constructor, which is what makes the compiler emit the vtables and the
// adjusting thunk.
struct IdlePrimaryBase
{
    virtual void FUN_005ff880();
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
};

struct IdleSecondaryBase
{
    virtual void FUN_005ff880();
};

struct IdleDerived : IdlePrimaryBase, IdleSecondaryBase
{
    IdleDerived();
// @fnv 0x005ff880
    virtual void FUN_005ff880();
};

IdleDerived::IdleDerived()
{}
