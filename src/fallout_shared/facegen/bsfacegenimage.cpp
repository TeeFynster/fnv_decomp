// src/fallout_shared/facegen/bsfacegenimage.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/facegen/bsfacegenimage.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/BSFaceGenImage.h"

extern "C" void __cdecl __Dummy_00b6fef0(void*, unsigned int);

// An aggregate keeps flags on the stack while __fastcall passes self in ECX.
struct BSFaceGenImageDeleteFlags
{
    unsigned int value;
};

// @fnv 0x0064cdf0
void* __fastcall FUN_0064cdf0(BSFaceGenImage* self, BSFaceGenImageDeleteFlags flags)
{
    self->BSFaceGenImage::~BSFaceGenImage();
    if (flags.value & 1)
        __Dummy_00b6fef0(self, 0x2c);
    return self;
}
