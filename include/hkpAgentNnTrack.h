#pragma once

#include "hkArray.h"

class hkpAgentNnSector;

class hkpAgentNnTrack
{
public:
    unsigned int m_iBytesUsedInLastSector;
    hkInplaceArray<hkpAgentNnSector*, 1> m_kSectors;

    hkpAgentNnTrack()
    {
        m_iBytesUsedInLastSector = 0x200;
    }
};
