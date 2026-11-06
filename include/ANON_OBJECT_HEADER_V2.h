#pragma once

#include <guiddef.h>

class ANON_OBJECT_HEADER_V2
{
public:
    unsigned short Sig1;
    unsigned short Sig2;
    unsigned short Version;
    unsigned short Machine;
    unsigned long TimeDateStamp;
    CLSID ClassID;
    unsigned long SizeOfData;
    unsigned long Flags;
    unsigned long MetaDataSize;
    unsigned long MetaDataOffset;
};
