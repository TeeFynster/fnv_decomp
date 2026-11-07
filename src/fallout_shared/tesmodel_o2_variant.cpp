
// src/fallout_shared/tesmodel_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tesmodel.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// src/fallout_shared/tesmodel.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/tesmodel.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../include/FileEntryList.h"

typedef char _sizecheck_TESTextureList[sizeof(FileEntryList) == 8 ? 1 : -1];
struct FUN_008c1be0_shell
{
    void bhkTTNode_TESObjectREFR_GetFlags(int param_1);
};
struct FUN_004898c0_shell
{
    void BSArchive_GetFlag_(int param_1);
};
extern bool DAT_011acdf8;
bool ArchiveManager_ArchivesEnabled();
struct FUN_004890e0_shell
{
    void ForwardToMember();
};
struct FUN_00489860_shell
{
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    int i4;
    unsigned char* __thiscall BSHash_BSHash_0(unsigned char a, unsigned char b, unsigned char c, unsigned char d, int e);
};

// sub ecx,0x30; jmp FUN_004029f0  ==  MSVC adjustor thunk (multiple inheritance,
// primary base occupies 0x30 bytes; both bases declare the same virtual, the derived
// class only defines its constructor so the compiler emits the this-adjusting thunk).
struct PrimaryBase
{
    virtual void AdjustThisAndForward_00403a40();
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
};

struct SecondaryBase
{
    virtual void AdjustThisAndForward_00403a40();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00403a40
// src: GUESS 0x00403a40 (confidence: low)
    virtual void AdjustThisAndForward_00403a40();
};

Derived::Derived()
{}

namespace fnv_0040a110 {
// sub ecx,0x30; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x30).
struct PrimaryBase
{
    virtual void FUN_0040a110();
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
};

typedef char _sizecheck_PrimaryBase[sizeof(PrimaryBase) == 0x30 ? 1 : -1];

struct SecondaryBase
{
    virtual void FUN_0040a110();
};

struct DerivedThunkHost : PrimaryBase, SecondaryBase
{
    DerivedThunkHost();
// @fnv 0x0040a110
    virtual void FUN_0040a110();
};

DerivedThunkHost::DerivedThunkHost()
{}
}  // namespace fnv_0040a110
