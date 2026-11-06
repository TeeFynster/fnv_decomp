#pragma once

#include "BSSimpleArray.h"

class ScrapHeapBuffer;
class OffsetData;

template <class T, unsigned int N = 1024>
class BSScrapArray
{
public:
    BSScrapArray();
    T& FUN_006a1440(unsigned int index); // exe 0x006a1440
    BSScrapArray(unsigned int capacity, unsigned int size, unsigned int allocator); // exe 0x006ad1b0/0x006ad250
    virtual ~BSScrapArray();
    virtual T* _Allocate(unsigned int count);
    virtual void _Deallocate(T* items);
    virtual T* _Reallocate(T* items, unsigned int count);

    union
    {
        void* field04;
        T* pBuffer;
    };
    union
    {
        void* field08;
        unsigned int uiSize;
        unsigned int iSize;
    };
    union
    {
        void* field0c;
        unsigned int uiAllocSize;
        unsigned int SimpleArrayStorage;
    };
    union
    {
        ScrapHeapBuffer* m_pPoolBase;
        ScrapHeapBuffer* m_pAllocator;
        unsigned int uiGrowSize;
    };

    void FUN_00822860(unsigned int size, bool freeBuffer);
    void FUN_006b3eb0(unsigned int size, bool freeBuffer);

    unsigned int Add(T& item);
    unsigned int GetTarget();
    void Clear(bool freeBuffer);
    OffsetData* ReallocateBuffer(OffsetData* items, unsigned int count);
    void* __thiscall AllocateElements(unsigned int a1);
    void* __thiscall FUN_006cf670(unsigned int size);
};
