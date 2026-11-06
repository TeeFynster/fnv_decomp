#pragma once

class BSFileEntry
{
public:
    unsigned char cLast;
    unsigned char cSecondToLast;
    unsigned char cLength;
    unsigned char cFirst;
    unsigned int uiCRC;
    unsigned int iSize;
    union
    {
        int flags;
        unsigned int iOffset;
    };

    unsigned int Size();
    unsigned int Offset();
    void SetOffset(unsigned int);
    void SetSize(unsigned int);
    bool GetSecondaryArchiveFlag();
    bool GetCheckedFileFlag();
    bool GetCompressionFlag();
    void SetSecondaryArchiveFlag(bool);
    void SetCheckedFileFlag(bool);
    void SetCompressionFlag(bool);
    void Endian();
    void SetFileDataOffset(unsigned int);
};
