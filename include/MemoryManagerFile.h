#pragma once

#include "IMemoryManagerFile.h"

class MemoryManagerFile : public IMemoryManagerFile
{
public:
    int __thiscall Read(void* apData, unsigned int aSize);
    virtual int __thiscall Write(const void* apData, unsigned int aSize);
    virtual void __thiscall vf04(int aiPos);
};
