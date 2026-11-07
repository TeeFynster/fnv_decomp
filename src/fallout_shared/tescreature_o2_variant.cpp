
// src/fallout_shared/tescreature_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tescreature.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.



// sub ecx,0x7c; jmp target  ==  MSVC adjustor thunk (multiple inheritance, shared virtual).
// PrimaryBase = vptr + 30 named int fields = 0x7c bytes; Derived redeclares the claimed virtual and defines only its ctor.
struct PrimaryBase
{
    virtual void AdjustThisAndForward_005fbf80();
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
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
};

struct SecondaryBase
{
    virtual void AdjustThisAndForward_005fbf80();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x005fbf80
// src: GUESS 0x005fbf80 (confidence: low)
    virtual void AdjustThisAndForward_005fbf80();
};

Derived::Derived()
{}

namespace fnv_005fbfb0 {
// MSVC adjustor thunk: the primary base occupies 0x7c bytes; both bases declare the virtual,
// the derived class defines only its constructor, so the compiler emits the this-adjusting thunk.
struct PrimaryBase
{
    virtual void FUN_005fbfb0();
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
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
};

struct SecondaryBase
{
    virtual void FUN_005fbfb0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x005fbfb0
    virtual void FUN_005fbfb0();
};

Derived::Derived()
{}
}  // namespace fnv_005fbfb0

namespace fnv_005fbfd0 {
// MSVC adjustor thunk: the primary base occupies 0x90 bytes; both bases declare the virtual,
// the derived class defines only its constructor, so the compiler emits the this-adjusting thunk.
struct PrimaryBase
{
    virtual void FUN_005fbfd0();
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
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
};

struct SecondaryBase
{
    virtual void FUN_005fbfd0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x005fbfd0
    virtual void FUN_005fbfd0();
};

Derived::Derived()
{}
}  // namespace fnv_005fbfd0

namespace fnv_005fbff0 {
// Adjustor (this-adjusting) thunk for FUN_005fbff0:
//     sub ecx, 0xdc ; jmp FUN_005f75b0
// MSVC emits such a thunk in the vftable of a class that inherits the same
// virtual from two bases: the thunk converts the secondary base sub-object
// pointer back to the primary base pointer by subtracting the size of the
// primary base (0xdc = 4 byte vptr + 54 int members) and tail jumps to the
// implementation.  Both bases declare the virtual, the derived class
// redeclares it and defines only its constructor, which makes the compiler
// emit the vtables and the adjusting thunk.
struct PrimaryBase
{
    virtual void FUN_005fbff0();
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
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
};

struct SecondaryBase
{
    virtual void FUN_005fbff0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x005fbff0
    virtual void FUN_005fbff0();
};

Derived::Derived()
{}
}  // namespace fnv_005fbff0

// Adjustor thunk: the secondary-base (+0x90) vtable entry for an override defined on the derived class.

class FC010Primary
{
  public:
    virtual void FUN_005fc010(unsigned int uiA, unsigned int uiB);
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
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
};

class FC010Secondary
{
  public:
    virtual void FUN_005fc010(unsigned int uiA, unsigned int uiB);
};

class FC010Derived : public FC010Primary, public FC010Secondary
{
  public:
    FC010Derived();
// @fnv 0x005fc010
    virtual void FUN_005fc010(unsigned int uiA, unsigned int uiB);
};

FC010Derived::FC010Derived()
{}

namespace fnv_005fc030 {
struct PrimaryBase
{
    virtual void FUN_005fc030();
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
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
};

struct SecondaryBase
{
    virtual void FUN_005fc030();
};

struct TESCreatureAdjust : PrimaryBase, SecondaryBase
{
    TESCreatureAdjust();
// @fnv 0x005fc030
    virtual void FUN_005fc030();
};

TESCreatureAdjust::TESCreatureAdjust()
{}
}  // namespace fnv_005fc030

namespace fnv_005fc040 {
// Adjustor thunk for FUN_005fc040: sub ecx,0x90; jmp FUN_005fb1e0
// Primary base = vptr + 35 int fields (0x90 bytes).
struct PrimaryBase
{
    virtual void AdjustThisAndForward_005fc040();
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
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
};

struct SecondaryBase
{
    virtual void AdjustThisAndForward_005fc040();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x005fc040
// src: GUESS 0x005fc040 (confidence: low)
    virtual void AdjustThisAndForward_005fc040();
};

Derived::Derived()
{}
}  // namespace fnv_005fc040
