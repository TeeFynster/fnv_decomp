#pragma once

#include "hkMemoryAllocator.h"

void __cdecl hkArrayUtil__reserve(hkMemoryAllocator& alloc, void* arr, int numElem, int sizeElem);
void* __cdecl _fnv_zlib_memset(void* dst, int val, int n);

class hkCharArray
{
public:
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkCharArray() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    ~hkCharArray();

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    char* begin()
    {
        return m_data;
    }

    void reserve(int n);
    void SetSizeAndGrow(int n);
    void setSizeUnchecked(int n);
};
