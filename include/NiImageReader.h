#pragma once

class NiImageReader
{
public:
    virtual void vfn_0();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();

    unsigned char pad[124];
    unsigned char lock[128];

    NiImageReader();
};
