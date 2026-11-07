// src/fallout_shared/tesvalueform.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/tesvalueform.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Base1
{
    virtual void FUN_004f9c90();
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
};
struct Base2
{
    virtual void FUN_004f9c90();
};
struct Derived : Base1, Base2
{
    Derived();
// @fnv 0x004f9c90
    virtual void FUN_004f9c90();
};
Derived::Derived()
{}

namespace fnv_004f9ca0 {
// sub ecx,0x74; jmp FUN_0051b020 == MSVC adjustor thunk: Derived overrides a virtual that both bases declare;
// the secondary base's vtable gets a thunk moving this back by sizeof(PrimaryBase) = 0x74.
struct PrimaryBase
{
    virtual void AdjustThisAndForward_004f9ca0();
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
};

struct SecondaryBase
{
    virtual void AdjustThisAndForward_004f9ca0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x004f9ca0
// src: GUESS 0x004f9ca0 (confidence: low)
    virtual void AdjustThisAndForward_004f9ca0();
};

Derived::Derived()
{}
}  // namespace fnv_004f9ca0

namespace fnv_004f9cc0 {
// sub ecx,0x74; jmp target == MSVC adjustor thunk: Derived overrides a virtual shared by two bases,
// the secondary base's thunk moves `this` back by sizeof(PrimaryBase) == 0x74.
struct PrimaryBase
{
    virtual void AdjustThisAndForward_004f9cc0();
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
};

struct SecondaryBase
{
    virtual void AdjustThisAndForward_004f9cc0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x004f9cc0
// src: GUESS 0x004f9cc0 (confidence: low)
    virtual void AdjustThisAndForward_004f9cc0();
};

Derived::Derived()
{}
}  // namespace fnv_004f9cc0

namespace fnv_00503bc0 {
struct Base1
{
    virtual void AdjustThisAndForward_00503bc0();
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
};
struct Base2
{
    virtual void AdjustThisAndForward_00503bc0();
};
struct Derived : Base1, Base2
{
    Derived();
// @fnv 0x00503bc0
// src: GUESS 0x00503bc0 (confidence: low)
    virtual void AdjustThisAndForward_00503bc0();
};
Derived::Derived()
{}
}  // namespace fnv_00503bc0

namespace fnv_00504fe0 {
struct PrimaryBase
{
    virtual void AdjustThisAndForward_00504fe0();
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
};

struct SecondaryBase
{
    virtual void AdjustThisAndForward_00504fe0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00504fe0
// src: GUESS 0x00504fe0 (confidence: low)
    virtual void AdjustThisAndForward_00504fe0();
};

Derived::Derived()
{}
}  // namespace fnv_00504fe0

// FUN_005144f0 : MSVC this-adjusting thunk  (sub ecx, 0x58 ; jmp <impl>)
struct A1_005144f0
{
    A1_005144f0();
    virtual void FUN_005144f0();
    char pad[0x54];
};
struct A2_005144f0
{
    A2_005144f0();
    virtual void FUN_005144f0();
};
struct Own_005144f0 : A1_005144f0, A2_005144f0
{
    Own_005144f0();
    virtual void key_fn();
// @fnv 0x005144f0
    void FUN_005144f0();
};
Own_005144f0::Own_005144f0()
{}
void Own_005144f0::key_fn()
{}
Own_005144f0* make_005144f0()
{
    static Own_005144f0 o;
    return &o;
}

namespace fnv_00515410 {
// sub ecx,0x84; jmp target == MSVC adjustor thunk: Derived overrides a virtual shared by both bases; the second base sits at +0x84.
struct PrimaryBase
{
    virtual void FUN_00515410();
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
};

struct SecondaryBase
{
    virtual void FUN_00515410();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00515410
    virtual void FUN_00515410();
};

Derived::Derived()
{}
}  // namespace fnv_00515410

namespace fnv_00515420 {
// sub ecx,0x84; jmp FUN_00515290  ==  MSVC adjustor thunk for the second base's vtable.
// PrimaryBase is vptr + 32 int fields = 0x84 bytes.
struct PrimaryBase
{
    virtual void AdjustThisAndForward_00515420();
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
};

struct SecondaryBase
{
    virtual void AdjustThisAndForward_00515420();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00515420
// src: GUESS 0x00515420 (confidence: low)
    virtual void AdjustThisAndForward_00515420();
};

Derived::Derived()
{}
}  // namespace fnv_00515420

// FUN_005160d0 - MSVC 2008 adjustor thunk for a *secondary* base.
//
// The original code is exactly:
//     005160d0  83 e9 58        sub ecx, 0x58
//     005160d3  e9 98 ff ff ff  jmp 0x00516070
//
// This is the "virtual adjustor thunk" that MSVC 2008 emits for the
// per-base vftable of a derived class which re-declares (overrides) a
// virtual function that one of its secondary bases also declares: the
// thunk moves `this` back from the secondary base sub-object to the start
// of the complete object and tail-jumps to the derived implementation.
//
// The secondary base sub-object lives 0x58 bytes into the derived object,
// so the primary base has to be exactly 0x58 bytes long.  The overriding
// implementation is only DECLARED here, so the jump target stays an
// unresolved external and the checker resolves the relocation from the
// original image.  The thunk's own mangled name carries the tag, which
// satisfies the canary.

struct ThunkPrimaryBase
{
    ThunkPrimaryBase();
    virtual void FUN_005160d0(int flag, int value);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
};

struct ThunkSecondaryBase
{
    ThunkSecondaryBase();
// @fnv 0x005160d0
    virtual void FUN_005160d0(int flag, int value);
};

struct ThunkDerived : public ThunkPrimaryBase, public ThunkSecondaryBase
{
    ThunkDerived();
    virtual void FUN_005160d0(int flag, int value);  // declared, never defined
};

ThunkPrimaryBase::ThunkPrimaryBase()
{}
ThunkSecondaryBase::ThunkSecondaryBase()
{}
ThunkDerived::ThunkDerived() : ThunkPrimaryBase(), ThunkSecondaryBase()
{}

// Adjustor thunk: the secondary-base (+0x58) entry for an override defined on the derived class.

class X160E0Primary
{
  public:
    virtual void AdjustThisAndForward_005160e0(unsigned int uiValue);
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
};

class X160E0Secondary
{
  public:
    virtual void AdjustThisAndForward_005160e0(unsigned int uiValue);
};

class X160E0Derived : public X160E0Primary, public X160E0Secondary
{
  public:
    X160E0Derived();
// @fnv 0x005160e0
// src: GUESS 0x005160e0 (confidence: low)
    virtual void AdjustThisAndForward_005160e0(unsigned int uiValue);
};

X160E0Derived::X160E0Derived()
{}

// FUN_0051a660 : MSVC this-adjusting thunk  (sub ecx, 0x7c ; jmp <impl>)
struct A1_0051a660
{
    A1_0051a660();
    virtual void AdjustThisAndForward_0051a660();
    char pad[0x78];
};
struct A2_0051a660
{
    A2_0051a660();
    virtual void AdjustThisAndForward_0051a660();
};
struct Own_0051a660 : A1_0051a660, A2_0051a660
{
    Own_0051a660();
    virtual void key_fn();
// @fnv 0x0051a660
// src: GUESS 0x0051a660 (confidence: low)
    void AdjustThisAndForward_0051a660();
};
Own_0051a660::Own_0051a660()
{}
void Own_0051a660::key_fn()
{}
Own_0051a660* make_0051a660()
{
    static Own_0051a660 o;
    return &o;
}

// sub ecx,0x7c; jmp FUN_0051a5d0: adjustor thunk from multiple inheritance.
// PrimaryBase is vptr + 30 dwords = 0x7c bytes.
struct PrimaryBase
{
    virtual void FUN_0051a670();
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
    virtual void FUN_0051a670();
};

struct AdjustedObject : PrimaryBase, SecondaryBase
{
    AdjustedObject();
// @fnv 0x0051a670
    virtual void FUN_0051a670();
};

AdjustedObject::AdjustedObject()
{}

// 0x51a690 = VC9 adjustor thunk (sub ecx,0x7c; jmp ?FUN_0051a5a0@...@@QAEXI@Z).
// Recipe: primary base of size 0x7c, secondary base re-declaring the same virtual,
// derived override declared-only, static instance forces both vftables -> thunk comdat.
struct AdjPrim
{
// @fnv 0x0051a690
    virtual void FUN_0051a690();
    int p04;
    int p08;
    int p0C;
    int p10;
    int p14;
    int p18;
    int p1C;
    int p20;
    int p24;
    int p28;
    int p2C;
    int p30;
    int p34;
    int p38;
    int p3C;
    int p40;
    int p44;
    int p48;
    int p4C;
    int p50;
    int p54;
    int p58;
    int p5C;
    int p60;
    int p64;
    int p68;
    int p6C;
    int p70;
    int p74;
    int p78;
};
struct AdjB1
{
    virtual void FUN_0051a690();
};
struct AdjTO : AdjPrim, AdjB1
{
    virtual void FUN_0051a690();
};
static AdjTO g_adjThunk;

// FUN_00525c10: MSVC adjustor thunk (sub ecx,0x84; jmp target) emitted for a virtual that
// lives in the first base but is reached through the second base's vtable slot.
// 0x84 = sizeof(AdjustPrimaryBase) = vptr + 32 int fields.
struct AdjustPrimaryBase
{
    virtual void FUN_00525c10();
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
};

struct AdjustSecondaryBase
{
    virtual void FUN_00525c10();
};

struct AdjustDerived : AdjustPrimaryBase, AdjustSecondaryBase
{
    AdjustDerived();
// @fnv 0x00525c10
    virtual void FUN_00525c10();
};

AdjustDerived::AdjustDerived()
{}

// sub ecx,0x84; jmp FUN_00523020 == MSVC adjustor thunk (multiple inheritance).
struct AdjPrimaryBase
{
    virtual void AdjustThisAndForward_00525c20();
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
};

struct AdjSecondaryBase
{
    virtual void AdjustThisAndForward_00525c20();
};

struct AdjDerived : AdjPrimaryBase, AdjSecondaryBase
{
    AdjDerived();
// @fnv 0x00525c20
// src: GUESS 0x00525c20 (confidence: low)
    virtual void AdjustThisAndForward_00525c20();
};

AdjDerived::AdjDerived()
{}

// Adjustor thunk: the secondary-base (+0x84) vtable entry for an override defined on the derived class.

class C5C30Primary
{
  public:
    virtual void FUN_00525c30(unsigned int uiA, unsigned int uiB);
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
};

class C5C30Secondary
{
  public:
    virtual void FUN_00525c30(unsigned int uiA, unsigned int uiB);
};

class C5C30Derived : public C5C30Primary, public C5C30Secondary
{
  public:
    C5C30Derived();
// @fnv 0x00525c30
    virtual void FUN_00525c30(unsigned int uiA, unsigned int uiB);
};

C5C30Derived::C5C30Derived()
{}

struct BF50Primary
{
    virtual void vfunc00();
    virtual void FUN_0059bf50(unsigned int a, unsigned int b);

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
};

struct BF50Secondary
{
    virtual void FUN_0059bf50(unsigned int a, unsigned int b);
};

struct BF50Object : BF50Primary, BF50Secondary
{
    BF50Object();

// @fnv 0x0059bf50
    virtual void FUN_0059bf50(unsigned int a, unsigned int b);
};

BF50Object::BF50Object()
{}

// FUN_0059bf60 : MSVC this-adjusting thunk  (sub ecx, 0x78 ; jmp <impl>)
//
// Two bases declare the same virtual, so the derived class overrides one
// function for both of them and the compiler emits one adjustor thunk per
// secondary base.  The first base is padded to 120 bytes so the second
// base lands at +0x78.  The override is DECLARED ONLY, so this thunk
// is the single defined function symbol carrying the name FUN_0059bf60; a defined
// key function makes the vftable that references the thunk be emitted here.
struct A1_0059bf60
{
    A1_0059bf60();
    virtual void AdjustThisAndForward_0059bf60();
    char pad[0x74];
};

struct A2_0059bf60
{
    A2_0059bf60();
// @fnv 0x0059bf60
// src: GUESS 0x0059bf60 (confidence: low)
    virtual void AdjustThisAndForward_0059bf60();
};

struct Own_0059bf60 : A1_0059bf60, A2_0059bf60
{
    Own_0059bf60();
    virtual void key_fn();  // key function - defined, so the vftable is emitted
    void AdjustThisAndForward_0059bf60();    // the shared override - declared only
};

Own_0059bf60::Own_0059bf60()
{}
void Own_0059bf60::key_fn()
{}

Own_0059bf60* make_0059bf60()
{
    static Own_0059bf60 o;
    return &o;
}

namespace fnv_0059bf80 {
struct Base1
{
    virtual void AdjustThisAndForward_0059bf80();
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
};
struct Base2
{
    virtual void AdjustThisAndForward_0059bf80();
};
struct Derived : Base1, Base2
{
    Derived();
// @fnv 0x0059bf80
// src: GUESS 0x0059bf80 (confidence: low)
    virtual void AdjustThisAndForward_0059bf80();
};
Derived::Derived()
{}
}  // namespace fnv_0059bf80

struct S_0059bf90_Base1
{
    virtual void FUN_0059bf90();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
};

struct S_0059bf90_Base2
{
    virtual void FUN_0059bf90();
};

struct S_0059bf90_Derived : S_0059bf90_Base1, S_0059bf90_Base2
{
    S_0059bf90_Derived();
// @fnv 0x0059bf90
    virtual void FUN_0059bf90();
};

S_0059bf90_Derived::S_0059bf90_Derived()
{}
