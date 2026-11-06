#pragma once

#include <cstddef>

// src: HAVOK_SRC
template <typename T> struct hkSizeOfTypeOrVoid { enum { val = sizeof(T) }; };
template <> struct hkSizeOfTypeOrVoid<void> { enum { val = 1 }; };

// Havok 7.1 Common/Base/Memory/Allocator/hkMemoryAllocator.h: the abstract allocator interface, 13 virtual slots
// (destructor 0x00cbf1a0, Xbox PDB). Declarations only: a unit whose original inlines a body defines it out of class.
// src: HAVOK_SRC (class name, MemoryStatistics, the 13 virtual slots and their names; destructor address per
// src: XBOX_PDB)
class hkMemoryAllocator
{
public:
    static void* __cdecl operator new(std::size_t, void* pItem);   // HK_DECLARE_PLACEMENT_ALLOCATOR

    struct MemoryStatistics
    {
        MemoryStatistics();
        std::size_t m_allocated;
        std::size_t m_inUse;
        std::size_t m_peakInUse;
        std::size_t m_available;
        std::size_t m_totalAvailable;
        std::size_t m_largestBlock;
    };

    virtual ~hkMemoryAllocator();
    virtual void* blockAlloc(int iNumBytes) = 0;
    virtual void blockFree(void* pItem, int iNumBytes) = 0;
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
    virtual void getMemoryStatistics(MemoryStatistics& kU) = 0;
    virtual int getAllocatedSize(const void* pObj, int iNbytes) = 0;
    virtual void resetPeakMemoryStatistics();

    template <typename TYPE>
    TYPE* _bufAlloc(int& kReqNumInOut);

    template <typename TYPE>
    void _bufFree(void* pItem, int iNumElem);

    template <typename TYPE>
    __forceinline void _bufFree(TYPE* p, int numElem)
    {
        _bufFree<TYPE>(static_cast<void*>(p), numElem);
    }

    template <typename TYPE>
    TYPE* _bufRealloc(void* pPold, int iOldNum, int& kReqNumInOut);

    template <typename TYPE>
    TYPE* _blockAlloc(int iCount);

    template <typename TYPE>
    void _blockFree(TYPE* pItem, int iCount);

    enum MemoryState
    {
        MEMORY_STATE_OK,
        MEMORY_STATE_OUT_OF_MEMORY
    };
};
