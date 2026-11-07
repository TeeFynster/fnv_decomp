
// src/fallout_shared/bgsnote_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/bgsnote.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "bgsnote_decls.h"

// Adjustor thunk: the derived class inherits a virtual that is declared by a
// secondary base, so MSVC emits a this-adjusting thunk that moves `this` back
// to the primary sub-object (sizeof(NotePrimaryBase) == 0x30) before jumping
// to the implementation.
struct NotePrimaryBase
{
    virtual void AdjustThisAndForward_005e9520();
    char unk04[0x2c];
};

struct NoteSecondaryBase
{
    virtual void AdjustThisAndForward_005e9520();
};

struct NoteDerived : NotePrimaryBase, NoteSecondaryBase
{
    NoteDerived();
// @fnv 0x005e9520
// src: GUESS 0x005e9520 (confidence: low)
    virtual void AdjustThisAndForward_005e9520();
};

NoteDerived::NoteDerived()
{}
