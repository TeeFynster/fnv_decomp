#pragma once

#include "NiImageReader.h"
#include "NiPixelFormat.h"

class NiBMPReader : public NiImageReader
{
public:
    unsigned int height;
    unsigned int width;
    NiPixelFormat format;
    unsigned short unknown;
    unsigned short padding;
    unsigned int x;
    unsigned int y;
    bool b1;
    bool b2;

    virtual void vfn_0();

    __declspec(nothrow) NiBMPReader() throw();
};
