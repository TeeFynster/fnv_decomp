#pragma once

#include "waveformat_tag.h"

#pragma pack(push, 1)
class pcmwaveformat_tag
{
public:
    waveformat_tag wf;
    unsigned short wBitsPerSample;
};
#pragma pack(pop)
