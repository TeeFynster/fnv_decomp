#include "../../../include/SearchPackage.h"

// src/fallout/ai/searchpackage.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/searchpackage.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern void __cdecl _Deallocate(void*);

// Calls the destructor, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x009f6680
void* SearchPackage::DestroyIfFlagged(unsigned int flags)
{
    SearchPackage::~SearchPackage();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

// Initializes a TESPackage-derived object: sets position from a, b, c, stores d, and zeroes the float fields.
// @fnv 0x009f66b0
SearchPackage::SearchPackage(float afX, float afY, float afZ, int aiValue, int aiUnused) : TESPackage(), unk94(), unka8()
{
    unk80 = 0.0f;
    unk84 = 1;
    unk88 = 0.0f;
    unk90 = 0.0f;
    unk94.y = afY;
    unk94.x = afX;
    unk94.z = afZ;
    unka0 = aiValue;
    unka4 = 1;
    unk8c = 0;
}

// Destructor for the package class; the body is empty, leaving member destruction to the compiler-generated code.
// @fnv 0x009f67b0
SearchPackage::~SearchPackage()
{}
