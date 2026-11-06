#pragma once

#include "IMemoryHeap.h"
#include "RecursiveSpinLock.h"

class ZeroOverheadHeap : public IMemoryHeap
{
public:
    virtual ~ZeroOverheadHeap();
    virtual const char* GetName();
    virtual void* Allocate(unsigned int size, unsigned int alignment);
    virtual void Deallocate(void* pointer, unsigned int alignment);
    virtual bool ContainsBlockImpl(const void* pointer);
    virtual void CheckHeapIntegrity();
    virtual void GetHeapStats(MemoryHeapStats* stats, bool full);
    virtual int OutputBucketInfo(IMemoryManagerFile* file);
    virtual int OutputBlockInfo(IMemoryManagerFile* file, bool full);
    virtual unsigned int Size(const void* pointer, unsigned int alignment);
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();

    unsigned int iSize;
    const char* pName;
    void* m_pPoolBase;
    void* m_pCurrent;
    int m_iAllocationCount;
    unsigned int layoutPadding18[2];
    RecursiveSpinLock lock;
};
