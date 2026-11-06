
// src/gamebryo2.2/corelibs/nianimation/nicontrollermanager_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nianimation/nicontrollermanager.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "../../../../include/Actor.h"
#include "../../../../include/TESObjectREFR.h"

struct DATST
{
    void __thiscall FUN_00972840(Actor* a, int b);
};
extern DATST DAT_011e0e80;
// @fnv 0x005c1b00
bool FUN_005c1b00(int a, int b, TESObjectREFR* c)
{
    if (c)
    {
        Actor* pkObject = dynamic_cast<Actor*>(c);
        if (pkObject)
        {
            DAT_011e0e80.FUN_00972840(pkObject, 0);
            pkObject->Unk_10D(0);
        }
    }
    return true;
}
