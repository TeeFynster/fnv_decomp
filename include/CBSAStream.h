#pragma once

#include "CAsyncStream.h"

class CBSAStream : public CAsyncStream
{
public:
    CBSAStream(const char* pathName);
    ~CBSAStream();

    virtual long QueryInterface(void* riid, void** ppv);
    virtual long SetPointer(__int64 llPos);
    virtual long Read(unsigned char* pbBuffer, unsigned long dwBytesToRead, int bAlign,
                      unsigned long* pdwBytesRead);
    virtual __int64 Size(__int64* pSizeAvailable = 0);
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();

    void Unlock_0082f1d0();
    unsigned __int64 GetStreamPosition(unsigned __int64* puiPosition);
};
