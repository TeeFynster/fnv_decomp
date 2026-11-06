
// src/fallout_shared/teskey.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/teskey.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../include/TESKey.h"

extern "C" void __cdecl _Deallocate(void*);

// Destroys the key, then frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0050a670
void* TESKey::Destroy(unsigned int flags)
{
    TESKey::~TESKey();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

// @fnv 0x0050a6a0
TESKey::~TESKey()
{
    TESForm::ClearData();
}
