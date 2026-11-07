
// src/havok/common/base/memory/allocator/solver/hksolverallocator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/memory/allocator/solver/hksolverallocator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkArray.h"
#include "../../../../../../../include/hkCriticalSection.h"
#include "../../../../../../../include/hkCriticalSectionLock.h"

inline hkCriticalSectionLock::hkCriticalSectionLock(hkCriticalSection* pkSection) : m_kCriticalSection(pkSection)
{
    m_kCriticalSection->enter();
}

inline hkCriticalSectionLock::~hkCriticalSectionLock()
{
    m_kCriticalSection->leave();
}


inline void copyArrayWords(void* dst, const void* src, int numBytes)
{
    for (int i = 0; i < numBytes; i += 4)
        *(int*)((char*)dst + i) = *(const int*)((const char*)src + i);
}

template <typename T>
__forceinline void hkArrayBase<T>::removeAtAndCopy(int index)
{
    m_iElementCount--;
    copyArrayWords(m_data + index, m_data + index + 1, (m_iElementCount - index) * sizeof(T));
}

template <typename T>
__forceinline void hkArrayBase<T>::popBack(int numElemsToRemove)
{
    m_iElementCount -= numElemsToRemove;
}

struct hkMemoryStatistics
{
    int m_iAllocated;
    int m_iAvailable;
    int m_iFree;
    int m_uiLogicalSize;
};

struct hkSolverAllocator
{
    int m_iFree;
    int m_iAllocated;
    int m_uiLogicalSize;
    int m_iBlockSize;
    int m_iPadding;
    int m_iBlockSize2;
    void GetMemoryStatistics(hkMemoryStatistics* statistics);
};

// Fills the statistics struct with allocated, available and free memory counts derived from the allocator's fields.
// @fnv 0x00d5e8c0
void hkSolverAllocator::GetMemoryStatistics(hkMemoryStatistics* statistics)
{
    statistics->m_iAllocated = m_uiLogicalSize - m_iAllocated;
    statistics->m_uiLogicalSize = m_uiLogicalSize - m_iBlockSize;
    statistics->m_iAvailable = m_iBlockSize - m_iAllocated;
    statistics->m_iFree = m_iBlockSize2;
}

struct FUN_00d5e8a0_Class : hkSolverAllocator
{
    bool CanAllocate(int size);
};

// @fnv 0x00d5e8a0
bool FUN_00d5e8a0_Class::CanAllocate(int size)
{
    return size <= m_uiLogicalSize - m_iAllocated;
}

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void*);

extern int DAT_010d1110;

struct FUN_00c66560_class
{
    void* m_pVftable;

    __declspec(noinline) void UpdateFields_00cbf1a0();
};

// src: GUESS 0x00cbf1a0 (confidence: low)
void FUN_00c66560_class::UpdateFields_00cbf1a0()
{
    volatile int* p = &DAT_010d1110;
    *p = *p;
}

struct FUN_00cd06a0_class : public FUN_00c66560_class
{
    unsigned char m_aPadding[0x120];
    unsigned char m_CriticalSection[24];

    void ResetVftableAndDeleteCriticalSection();
};

// @fnv 0x00d5e940
void FUN_00cd06a0_class::ResetVftableAndDeleteCriticalSection()
{
    void* criticalSection = &m_CriticalSection;
    m_pVftable = &DAT_010d1110;
    DeleteCriticalSection(criticalSection);
    UpdateFields_00cbf1a0();
}

// @fnv 0x00c661c0
// src: COMMUNITY 0x00c661c0
int __stdcall hkMemoryAllocator_getAllocatedSize(unsigned int arg0, unsigned int arg1)
{
    return (int)arg1;
}

struct S_00d5e8f0
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    void hkSolverAllocator_resetPeakMemoryStatistics();
};
// @fnv 0x00d5e8f0
// src: HAVOK_LIB 0x00d5e8f0
void S_00d5e8f0::hkSolverAllocator_resetPeakMemoryStatistics()
{
    unk14 = unkC - unk4;
}

// @fnv 0x00d5e880
// src: COMMUNITY 0x00d5e880
int __stdcall hkSolverAllocator_blockAlloc(int arg0)
{
    return 0;
}

// @fnv 0x00d5e890
// src: COMMUNITY 0x00d5e890
void __stdcall nullsub_79(void* context, unsigned int flags)
{}

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* cs);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* cs);


struct hkStreamD5E9
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_cur;
    int m_10;

    void init(char* p, int size)
    {
        m_kRayStart = p;
        m_cur = p;
        m_kRayEnd = p + size;
        m_10 = 0;
    }
};

struct hkObjD5E9
{
    int unk00;
    hkStreamD5E9 m_stream;
    int unk14;
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    hkCriticalSection m_kCriticalSection;

    void InitStream(char* p, int size);
};

// @fnv 0x00d5e960
void hkObjD5E9::InitStream(char* pBuffer, int size)
{
    EnterCriticalSection(&m_kCriticalSection);
    m_data = &unk24;
    m_iCapacityState = 0x80000020;
    m_stream.init(pBuffer, size);
    LeaveCriticalSection(&m_kCriticalSection);
}

namespace fnv_00d5e9b0 {
struct hkFreeBlockD5E9
{
    char* m_kRayStart;
    int m_iElementCount;
};

class hkBlockAllocatorD5E9
{
  public:
    void* m_ppVirtualMethodTable;
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_cur;
    int m_iCurrentUsage;
    unsigned int m_peakUsage;
    hkArray<hkFreeBlockD5E9> m_pFreeBlocks;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    int m_a4;
    int m_a8;
    int m_ac;
    int m_b0;
    int m_b4;
    int m_b8;
    int m_bc;
    int m_c0;
    int m_c4;
    int m_c8;
    int m_cc;
    int m_d0;
    int m_d4;
    int m_d8;
    int m_dc;
    int m_e0;
    int m_e4;
    int m_e8;
    int m_ec;
    int m_f0;
    int m_f4;
    int m_f8;
    int m_fc;
    int m_100;
    int m_104;
    int m_108;
    int m_10c;
    int m_110;
    int m_114;
    int m_118;
    int m_11c;
    int m_120;
    hkCriticalSection m_pWorldLock;

    void updateStats()
    {
        m_iCurrentUsage++;
        unsigned int uiUsed = m_cur - m_kRayStart;
        if (uiUsed > m_peakUsage)
            m_peakUsage = uiUsed;
    }

    char* Allocate(int* piSizeInOut) throw();
};

// @fnv 0x00d5e9b0
char* hkBlockAllocatorD5E9::Allocate(int* piSizeInOut) throw()
{
    hkCriticalSectionLock kLock(&m_pWorldLock);
    int iSize = *piSizeInOut;
    int iBestIndex = -1;
    int iBestSize = 0x7ffffff;
    if (m_iCurrentUsage + 1 >= m_pFreeBlocks.getCapacity() * 2 - m_pFreeBlocks.GetLogicalSize())
        return 0;

    for (int i = m_pFreeBlocks.GetLogicalSize() - 1; i >= 0; i--)
    {
        int iFreeBlockSize = m_pFreeBlocks[i].m_iElementCount;
        if (iFreeBlockSize >= iSize && iFreeBlockSize < iBestSize)
        {
            iBestSize = iFreeBlockSize;
            iBestIndex = i;
        }
    }

    if (iBestIndex < 0)
    {
        if (m_kRayEnd - m_cur >= iSize)
        {
            char* pResult = m_cur;
            m_cur = pResult + iSize;
            *piSizeInOut = iSize;
            updateStats();
            return pResult;
        }
        return 0;
    }

    hkFreeBlockD5E9& kBlock = m_pFreeBlocks[iBestIndex];
    char* pResult = kBlock.m_kRayStart;
    if (2 * iBestSize > 3 * iSize && iSize > 0x400)
    {
        kBlock.m_iElementCount -= iSize;
        kBlock.m_kRayStart = pResult + iSize;
    }
    else
    {
        *piSizeInOut = kBlock.m_iElementCount;
        m_pFreeBlocks.removeAtAndCopy(iBestIndex);
    }
    updateStats();
    return pResult;
}
}  // namespace fnv_00d5e9b0

inline void* operator new(unsigned int, void* ptr)
{
    return ptr;
}

void __cdecl hkMemUtil_memMove(void* dst, const void* src, unsigned int numBytes);

struct Element
{
    int a;
    int b;
};

// Grows the array if needed, shifts elements to make room, copy-constructs numToInsert elements at index, and updates the size.
// @fnv 0x00d5ecc0
template <>
void hkArrayBase<Element>::_spliceInto(hkMemoryAllocator& allocator, int index, int numToRemove, const Element* elements, int numToInsert)
{
    int newSize = m_iElementCount - numToRemove + numToInsert;
    int numToMove = m_iElementCount - index - numToRemove;

    int iCapacity = m_iCapacityState & 0x3fffffff;
    if (iCapacity < newSize)
    {
        iCapacity += iCapacity;
        if (newSize >= iCapacity)
            iCapacity = newSize;
        hkArrayUtil::_reserve(allocator, this, iCapacity, 8);
    }

    hkMemUtil_memMove(&m_data[index + numToInsert], &m_data[index + numToRemove], numToMove * 8);

    Element* dst = &m_data[index];
    for (int i = 0; i < numToInsert; ++i)
    {
        ::new (&dst[i]) Element(elements[i]);
    }

    m_iElementCount = newSize;
}

struct hkPairD5E9
{
    int m_key;
    int m_uiFilterValue;
};

// Used only for construction cleanup here: 0x00d5e900 never acquires storage beyond the embedded buffer.
template <>
__forceinline hkArray<hkPairD5E9>::~hkArray()
{}

class FUN_00cf6da0
{
  public:
    int unk00;
    FUN_00cf6da0(int flag);
};

class FUN_00d5e900
{
  public:
    virtual ~FUN_00d5e900();
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    hkInplaceArray<hkPairD5E9, 32> m_pairs;
    FUN_00cf6da0 m_pChildAtom;

    FUN_00d5e900();
};

// @fnv 0x00d5e900
FUN_00d5e900::FUN_00d5e900() : m_04(0), m_08(0), m_0C(0), m_10(0), m_14(0), m_pChildAtom(0)
{}

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);

struct S00d5eb10_Block
{
    void* p;
    int size;
    S00d5eb10_Block()
    {}
    S00d5eb10_Block(void* p_, int s_) : p(p_), size(s_)
    {}
};

struct S00d5eb10_CS
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct S00d5eb10_Alloc : public FUN_00c66560_class
{
    void* unk04;
    void* unk08;
    void* m_pTileTemplate;
    int m_numAllocations;
    int unk14;
    hkInplaceArray<S00d5eb10_Block, 32> m_kBlocks;
    S00d5eb10_CS m_pWorldLock;

    void hkSolverAllocator_bufFree(void* p, int size);
};

// Updates allocation bookkeeping; moves m_pTileTemplate backward for an adjacent block, otherwise merges with or inserts into m_kBlocks.
// @fnv 0x00d5eb10
// src: HAVOK_LIB 0x00d5eb10
void S00d5eb10_Alloc::hkSolverAllocator_bufFree(void* apBlock, int size)
{
    void* cs = &m_pWorldLock;
    EnterCriticalSection(cs);
    m_numAllocations--;
    if ((char*)apBlock + size == m_pTileTemplate)
    {
        m_pTileTemplate = (char*)m_pTileTemplate - size;
        if (m_kBlocks.m_iElementCount == 0)
            goto exit;
        do
        {
            S00d5eb10_Block& freeBlock = m_kBlocks.back();
            if (freeBlock.size + (char*)freeBlock.p != (char*)apBlock)
                goto exit;
            m_pTileTemplate = m_kBlocks.back().p;
            m_kBlocks.popBack();
        } while (m_kBlocks.m_iElementCount != 0);
        LeaveCriticalSection(cs);
        return;
    }

    int iCount = m_kBlocks.m_iElementCount;
    if (iCount == 0)
    {
        int iIndex = m_kBlocks.m_iElementCount++;
        S00d5eb10_Block& newBlock = m_kBlocks.m_data[iIndex];
        newBlock.p = apBlock;
        newBlock.size = size;
        LeaveCriticalSection(cs);
        return;
    }

    int i = iCount - 1;
    while (i >= 0)
    {
        if (m_kBlocks.m_data[i].p < apBlock)
            break;
        --i;
    }

    if (i >= 0)
    {
        S00d5eb10_Block& b = m_kBlocks.m_data[i];
        if (b.size + (char*)b.p == (char*)apBlock)
        {
            b.size += size;
            if (i < m_kBlocks.m_iElementCount - 1 && (char*)apBlock + size == m_kBlocks.m_data[i + 1].p)
            {
                b.size += m_kBlocks.m_data[i + 1].size;
                m_kBlocks.removeAtAndCopy(i + 1);
            }
            LeaveCriticalSection(cs);
            return;
        }
    }

    if (i < iCount - 1)
    {
        S00d5eb10_Block& kNextBlock = m_kBlocks.m_data[i + 1];
        if (kNextBlock.p == (char*)apBlock + size)
        {
            kNextBlock.size += size;
            kNextBlock.p = apBlock;
            LeaveCriticalSection(cs);
            return;
        }
    }

    m_kBlocks._insertAt(*(hkMemoryAllocator*)0, i + 1, S00d5eb10_Block(apBlock, size));
exit:
    LeaveCriticalSection(cs);
}

struct SolverDeletingView : FUN_00cd06a0_class
{
    SolverDeletingView* UpdateState_00d5ed70(unsigned int flags);
};

// @fnv 0x00d5ed70
// src: GUESS 0x00d5ed70 (confidence: low)
SolverDeletingView* SolverDeletingView::UpdateState_00d5ed70(unsigned int)
{
    void (FUN_00cd06a0_class::*destroy)() = &FUN_00cd06a0_class::ResetVftableAndDeleteCriticalSection;
    (this->*destroy)();
    return this;
}
