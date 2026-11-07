
// src/fallout_shared/tescaravan_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tescaravan.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "../../include/BGSImpactData.h"
class RegionDataEntry
{
  public:
    void Endian();
};
extern "C" void* memset(void* dst, int val, unsigned int size);

// Adjustor thunk (MSVC this-adjusting thunk for a secondary base sub-object).
// The secondary base sits at offset 0x3c inside the derived object, so the
// thunk rewinds 'this' to the start of the derived object and tail-jumps to
// the overriding implementation.
class PrimaryBase
{
  public:
    virtual void AdjustThisAndForward_0059bf40();
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
};

class SecondaryBase
{
  public:
    virtual void AdjustThisAndForward_0059bf40();
};

class Derived : public PrimaryBase, public SecondaryBase
{
  public:
// @fnv 0x0059bf40
// src: GUESS 0x0059bf40 (confidence: low)
    virtual void AdjustThisAndForward_0059bf40();
    Derived();
};

Derived::Derived()
{}

namespace fnv_0059bf70 {
// Adjustor (this-adjusting) thunk for FUN_0059bf70: "sub ecx, 0x3c; jmp Release".
//
// The thunk is emitted for a virtual function inherited from a secondary base: it moves the
// secondary-base sub-object pointer back to the derived object pointer (sub ecx, 0x3c) and
// tail jumps to the final overrider. The subtracted offset is the size of the primary base,
// so PrimaryBase is laid out as a vtable pointer plus 14 int members (4 + 56 = 0x3c).
// Both bases declare the same virtual function; the derived class redeclares it and defines
// only its constructor, which is what makes the compiler emit the vtables and the thunk.
struct PrimaryBase
{
    virtual void FUN_0059bf70();
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
};

struct SecondaryBase
{
    virtual void FUN_0059bf70();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x0059bf70
    virtual void FUN_0059bf70();
};

Derived::Derived()
{}
}  // namespace fnv_0059bf70
