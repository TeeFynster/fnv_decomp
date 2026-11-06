#pragma once

#include "NiBinaryStream.h"

class NiMemStream : public NiBinaryStream
{
public:
    // +0x04..+0x0F are the NiBinaryStream members (SetEndianSwap 0x00aa2f80 installs the reader/writer).
    char* m_kRayStart;
    unsigned int m_pos;
    union
    {
        unsigned int m_kRayEnd;
        int m_uiLogicalSize;
    };
    union
    {
        unsigned int m_uiSize;
        unsigned int unk1C;
    };
    union
    {
        unsigned char m_bFlag20;
        unsigned char unk20;
    };
    union
    {
        unsigned char m_bFlag21;
        unsigned char unk21;
    };

    NiMemStream();
    NiMemStream(void* buffer, unsigned int size);
    virtual ~NiMemStream();
    virtual operator bool();
    virtual void Seek(int iNumBytes);
    virtual void SetEndianSwap(bool bDoSwap);

    void NiMemStreamDestructor();
    void SetSwapMode(bool bDoSwap);
    void __thiscall FUN_00aa2d70(int iNumBytes);
    unsigned int __thiscall FUN_00aa2dd0(const void* data, unsigned int numBytes);
    void FUN_00aa2fb0(char* buffer, int size);
    void FUN_00aa2ff0();
    char* FUN_00aa2d60();
};
