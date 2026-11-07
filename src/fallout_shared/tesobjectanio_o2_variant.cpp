
// src/fallout_shared/tesobjectanio_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tesobjectanio.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "tesobjectanio_decls.h"
struct SFTX
{
    void SetFormType(int);
};
struct B2_4fe
{
    B2_4fe();
    virtual ~B2_4fe();
    unsigned char pad[0x1c];
};
struct FUN_00511950 : public TESForm, public B2_4fe
{
    int pAnim;
    FUN_00511950();
    virtual ~FUN_00511950();
};
void operator delete(void*);
struct FUN_005119e0_obj
{
    void FUN_00511a10();
    void* Destroy(unsigned int flags);
};
struct FUN_004855a0
{
    void __thiscall M();
};
struct FUN_00485680
{
    void __thiscall M();
};
struct S_0048a520
{
    void __thiscall ProcessAndFreeData(unsigned int, unsigned int, unsigned int);
};
struct _ref_0084e3a0_t
{
    unsigned int __thiscall _ref_0084e3a0();
};
unsigned int __cdecl _FUN_00485910(unsigned int, unsigned int);
struct FUN_00511d10_shell
{
    void __thiscall TESObjectANIO_Save();
};

// sub ecx,0x18; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x18).
struct PrimaryBase
{
    virtual void FUN_00511e30();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct SecondaryBase
{
    virtual void FUN_00511e30();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00511e30
    virtual void FUN_00511e30();
};

Derived::Derived()
{}
