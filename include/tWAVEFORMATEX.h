#pragma once

#pragma pack(push, 1)
class tWAVEFORMATEX
{
public:
    unsigned short wFormatTag;
    unsigned short nChannels;
    unsigned long nSamplesPerSec;
    unsigned long nAvgBytesPerSec;
    unsigned short nBlockAlign;
    unsigned short wBitsPerSample;
    unsigned short cbSize;
};
#pragma pack(pop)
