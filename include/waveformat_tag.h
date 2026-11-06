#pragma once

#pragma pack(push, 1)
class waveformat_tag
{
public:
    unsigned short wFormatTag;
    unsigned short nChannels;
    unsigned long nSamplesPerSec;
    unsigned long nAvgBytesPerSec;
    unsigned short nBlockAlign;
};
#pragma pack(pop)
