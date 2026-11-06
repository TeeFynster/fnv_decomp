// fallout/misc/saveload/bgsloadgamebuffer.h: defines BGSLoadGameBuffer::ResetReadPosition
#ifndef FNV_BGSLOADGAMEBUFFER_H
#define FNV_BGSLOADGAMEBUFFER_H

#include "bgsloadgamebuffer_decls.h"


// @fnv 0x00848d50
void BGSLoadGameBuffer::ResetReadPosition()
{
    void* buffer = pBuffer;
    Deallocate(buffer);
    pBuffer = 0;
    iBufferSize = 0;
    m_uiReadOffset = 0;
}
#endif
