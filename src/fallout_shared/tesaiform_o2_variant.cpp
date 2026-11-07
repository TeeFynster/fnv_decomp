
// src/fallout_shared/tesaiform_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tesaiform.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "tesaiform_decls.h"

struct PrimaryBase
{
    virtual void FUN_005fbf90();
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
    virtual void FUN_005fbf90();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x005fbf90
    virtual void FUN_005fbf90();
};

Derived::Derived()
{}

namespace fnv_005fbfc0 {
struct PrimaryBase
{
    virtual void AdjustThisAndForward_005fbfc0();
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
    virtual void AdjustThisAndForward_005fbfc0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x005fbfc0
// src: GUESS 0x005fbfc0 (confidence: low)
    virtual void AdjustThisAndForward_005fbfc0();
};

Derived::Derived()
{}
}  // namespace fnv_005fbfc0

namespace fnv_005fc000 {
struct PrimaryBase
{
    virtual void AdjustThisAndForward_005fc000();
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
    virtual void AdjustThisAndForward_005fc000();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x005fc000
// src: GUESS 0x005fc000 (confidence: low)
    virtual void AdjustThisAndForward_005fc000();
};

Derived::Derived()
{}
}  // namespace fnv_005fc000
