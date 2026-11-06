// Fallout: New Vegas - original source reconstruction.
// Source unit: d:/_fallout3/platforms/common/code/bsmain/bsstream.h
// Covered function: 0043cfd0 BSStream::BSStream (116 bytes).
#ifndef FNV_BSSTREAM_H
#define FNV_BSSTREAM_H

#include "../../include/BSStream.h"
#include "../../include/NiStream.h"

// @fnv 0x0043cfd0
BSStream::BSStream() : m_spNodeReferences(0)
{
    m_pObjectNameMap = 0;
}

#endif
