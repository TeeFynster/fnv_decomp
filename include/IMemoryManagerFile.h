#pragma once

class IMemoryManagerFile
{
public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual int Write(const void* buffer, unsigned int size);
    virtual void vf03();
    virtual void vf04(int aiPos);
};
