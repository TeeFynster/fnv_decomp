
// src/gamebryo2.2/corelibs/nimain/nicamera_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nimain/nicamera.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "../../../../include/NiPlane.h"
// The stream scalar operation is expanded in this unit, rather than defining an
// implementation owned by NiBinaryStream or introducing an out-of-line helper.
#define FNV_READ_SCALAR(value)                                                                                         \
    do                                                                                                                 \
    {                                                                                                                  \
        NiBinaryStream* input = stream.m_pUnderlyingStream;                                                            \
        unsigned int componentSize = sizeof(value);                                                                    \
        input->m_uiStreamFlags += input->m_pfnRead(input, &(value), sizeof(value), &componentSize, 1);                 \
    } while (0)
#undef FNV_READ_SCALAR
#pragma optimize("", off)
#pragma optimize("", on)

struct FUN_0045c620
{
    NiPlane arr[6];
    int x;
    FUN_0045c620();
};
// @fnv 0x0045c620
FUN_0045c620::FUN_0045c620()
{
    x = 0x3F;
}
