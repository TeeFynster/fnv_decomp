
// src/gamebryo2.2/corelibs/nimain/nidepthstencilbuffer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nidepthstencilbuffer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiDepthStencilBuffer.h"

extern const NiRTTI DAT_011f603c;

// @fnv 0x00a9fe50
// src: COMMUNITY 0x00a9fe50
const NiRTTI* __cdecl NiDepthStencilBuffer_GetRTTI()
{
    return &DAT_011f603c;
}

extern int vftable_NiDepthStencilBuffer;
void _delete(void*, unsigned int);
// Sets the vftable, calls the Ni2DBuffer destructor, and if flag bit 0 is set frees this with size 0x14, returning this.
// @fnv 0x00a9fe60
void* NiDepthStencilBuffer::Destroy(unsigned int auiFlags)
{
    *(void**)this = (void*)&vftable_NiDepthStencilBuffer;
    Ni2DBuffer::~Ni2DBuffer();
    if (auiFlags & 1)
        _delete(this, 0x14);
    return this;
}
