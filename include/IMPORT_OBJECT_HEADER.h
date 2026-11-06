#pragma once

class IMPORT_OBJECT_HEADER
{
public:
    unsigned short Sig1;
    unsigned short Sig2;
    unsigned short Version;
    unsigned short Machine;
    unsigned long TimeDateStamp;
    unsigned long SizeOfData;

    union
    {
        unsigned short Ordinal;
        unsigned short Hint;
    };

    unsigned short Type : 2;
    unsigned short NameType : 3;
    unsigned short Reserved : 11;
};
