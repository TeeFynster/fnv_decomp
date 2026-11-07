#pragma once

#include "NiAllocator.h"

class NiStandardAllocator : public NiAllocator
{
public:
    static void* __cdecl operator new(unsigned int);
    void* __thiscall NiStandardObjectAllocHelper(unsigned int);
    void func();
    void* NiStandardAllocator_Reallocate(void* pvMemory, unsigned int& stSizeInBytes, unsigned int& stAlignment,
                       int aiAllocationType, bool bProvideAccurateSizeOnDeallocate,
                       unsigned int stSizeCurrent, const char* pcFile, int iLine,
                       const char* pcFunction);
};
