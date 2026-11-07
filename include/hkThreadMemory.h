#pragma once

#include "hkMemoryAllocator.h"

class hkMemory;

class hkThreadMemory : public hkMemoryAllocator
{
public:
    virtual ~hkThreadMemory();
    virtual void* blockAlloc(int iNumBytes);
    virtual void blockFree(void* pItem, int iNumBytes);
  public:  // variable-size buffers (slots 3-5)
    virtual void* bufAlloc(int& kReqNumBytesInOut);
    virtual void bufFree(void* pItem, int iNumBytes);
    virtual void* bufRealloc(void* pPold, int iOldNumBytes, int& kReqNumBytesInOut);
  public:  // batches and capacity queries (slots 6-9)
    virtual void blockAllocBatch(void** pPtrsOut, int iNumPtrs, int iBlockSize);
    virtual void blockFreeBatch(void** pPtrsIn, int iNumPtrs, int iBlockSize);
    virtual bool canAllocSingleBlock(int iNumBytes);
    virtual bool canAllocTotal(int iNumBytes);
  public:  // statistics (slots 10-12)
    virtual void getMemoryStatistics(MemoryStatistics& kU);
    virtual int getAllocatedSize(const void* pObj, int iNbytes);
    virtual void resetPeakMemoryStatistics();
    virtual void hkThreadMemory_releaseCachedMemory();

    // The inherited vfptr occupies offset 0.
    int unk04;
    int unk08;
    int unk0c;
    hkMemory* m_pMemoryAllocator;

    void* allocateChunk(int iSize) throw();
    static hkThreadMemory* GetMonitorStream() throw();
    hkMemoryAllocator& heap();
    unsigned int ComputeWeightedSum();
};
