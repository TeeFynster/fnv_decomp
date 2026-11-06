#pragma once

class CAsyncStream
{
public:
    virtual long QueryInterface(void* riid, void** ppv) = 0;
    virtual long SetPointer(__int64 llPos) = 0;
    virtual long Read(unsigned char* pbBuffer, unsigned long dwBytesToRead, int bAlign,
                      unsigned long* pdwBytesRead) = 0;
    virtual __int64 Size(__int64* pSizeAvailable = 0) = 0;
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
};
