
// src/havok/common/base/memory/allocator/freelist/hkfreelist.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/memory/allocator/freelist/hkfreelist.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkFreeListAllocator.h"
#include "../../../../../../../include/hkFreeListAllocatorServer.h"

// include/hkFreeList.h is absent. Keep one local definition of hkFreeList
// until the shared header supports these methods (0x00dd71c0 through 0x00dd7c40).

struct FreeListStatistics;
namespace memory_walk { class LocalhkBool; }
typedef void(__cdecl* FreeBlockWalkCallback)(void*, int, memory_walk::LocalhkBool, int, void*);

class hkFreeList
{
  public:
    struct Element
    {
        Element* m_next;
    };

    struct Block
    {
        Block* m_next;
        int m_blockSize;
        char* m_start;
        unsigned int m_numElements;
    };

    Element* m_free;
    unsigned int m_elementSize;
    Block* m_incrementalBlock;
    Block* m_blocks;
    Block* m_freeBlocks;
    unsigned int m_blockSize;
    unsigned int m_alignment;
    unsigned int m_maxBlockSize;
    char* m_top;
    char* m_blockEnd;
    int m_numFreeElements;
    int m_numElements;
    hkFreeListAllocatorServer* m_blockServer;

    __declspec(noinline) int FreeBlocks(Block* node);
    __declspec(noinline) void freeAllMemory();
    void freeAllFreeBlocks();
    void CollectFreeNodes(Block** blocks, int unused);
    __declspec(noinline) void _init(int, int, int, int);
    void init_00dd7510(int, int, int, int);
    bool* ValidateFreeList(bool* result);
    unsigned int _calcNumFreeElements();
    __declspec(noinline) int SumNodeCounts(Block* node);
    int _calcTotalNumElements();
    void freeSmallFreeBlocks(unsigned int key);
    void calculateStatistics(FreeListStatistics* info);
    void ResetFreeList();
    __declspec(noinline) void WalkFreeBlocks(Block*, FreeBlockWalkCallback, int, void*);
    int Compact();
    void walkMemory_00dd78f0(hkMemoryWalkCallback callback, int pool, void* param);
    void* AllocateElement();
    int _calcBlockFree(Block*);
    hkBool incrementalFindGarbage(int, int&) throw();
};

// @fnv 0x00dd7280
__declspec(noinline) int __cdecl SumFreeListSizes(hkFreeList::Block* node)
{
    int total = 0;
    while (node)
    {
        total += node->m_numElements;
        node = node->m_next;
    }
    return total;
}

// @fnv 0x00dd7360
// src: HAVOK_LIB 0x00dd7360
void hkFreeList::freeAllFreeBlocks()
{
    FreeBlocks(m_freeBlocks);
    m_freeBlocks = 0;
}

// @fnv 0x00dd73d0
// src: HAVOK_LIB 0x00dd73d0
__declspec(noinline) void* hkFreeList_bestBlockSize(void* p, unsigned int n)
{
    if (n <= 0x10)
        return (char*)p + 0x10;
    return (char*)p + n;
}

// Calls FUN_00dd7200, then forwards the four int arguments to FUN_00dd74b0.
// @fnv 0x00dd7510
// src: HAVOK_LIB 0x00dd7510
void hkFreeList::init_00dd7510(int a, int b, int c, int d)
{
    freeAllMemory();
    _init(a, b, c, d);
}

// @fnv 0x00dd71c0
int hkFreeList::FreeBlocks(Block* node)
{
    int count = 0;

    while (node)
    {
        m_numElements -= node->m_numElements;
        m_numFreeElements -= node->m_numElements;

        hkFreeListAllocatorServer* allocator = m_blockServer;
        Block* next = node->m_next;

        ++count;
        // The shared freeBlock declaration is nonvirtual; this block server's
        // release operation uses vtable slot 2 with a single block argument.
        typedef void(__thiscall* ReleaseFreeListBlock)(hkFreeListAllocatorServer*, Block*);
        reinterpret_cast<ReleaseFreeListBlock>((*reinterpret_cast<void***>(allocator))[2])(allocator, node);
        node = next;
    }

    return count;
}

// @fnv 0x00dd7200
// src: HAVOK_LIB 0x00dd7200
void hkFreeList::freeAllMemory()
{
    hkFreeList* p = this;

    p->FreeBlocks(p->m_blocks);
    p->m_blocks = 0;
    p->FreeBlocks(p->m_freeBlocks);
    p->m_freeBlocks = 0;
    p->m_free = 0;
    p->m_blockSize = 0;
    p->m_numFreeElements = 0;
    p->m_numElements = 0;
    p->m_top = 0;
    p->m_blockEnd = 0;
    p->m_incrementalBlock = 0;
}

// @fnv 0x00dd7240
// src: HAVOK_LIB 0x00dd7240
unsigned int hkFreeList::_calcNumFreeElements()
{
    unsigned int count = 0;
    Element* node = m_free;

    while (node != 0)
    {
        ++count;
        node = node->m_next;
    }

    count += (reinterpret_cast<unsigned int>(m_blockEnd) - reinterpret_cast<unsigned int>(m_top)) / m_elementSize;

    Block* block = m_freeBlocks;
    while (block != 0)
    {
        count += block->m_numElements;
        block = block->m_next;
    }

    return count;
}

// @fnv 0x00dd73f0
void hkFreeList::ResetFreeList()
{
    m_numFreeElements = m_numElements;

    Block* node = m_blocks;
    if (node != 0)
    {
        m_free = 0;
        while (node->m_next != 0)
            node = node->m_next;

        node->m_next = m_freeBlocks;
        m_freeBlocks = m_blocks;
        m_blocks = 0;
        m_top = 0;
        m_blockEnd = 0;
        m_incrementalBlock = 0;
    }
}

// Writes every node of the two free lists into the blocks array, following each list's next pointer until null.
// @fnv 0x00dd7480
void hkFreeList::CollectFreeNodes(Block** blocks, int)
{
    Block* node = m_blocks;
    while (node != 0)
    {
        *blocks++ = node;
        node = node->m_next;
    }

    node = m_freeBlocks;
    while (node != 0)
    {
        *blocks++ = node;
        node = node->m_next;
    }
}

// Block-server interface: slot 3 returns hkBool in 0x00dd7140; this is not a free-list object.
struct FreeAllocator
{
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual hkBool TestBlock(hkFreeList::Block* block);
};

// Walks the free list, checking each node's alignment and that it lies inside a block accepted by TestBlock; writes true or false to result.
// @fnv 0x00dd7140
bool* hkFreeList::ValidateFreeList(bool* result)
{
    Element* pNode = m_free;
    while (pNode != 0)
    {
        if ((reinterpret_cast<unsigned int>(pNode) & (m_alignment - 1)) != 0)
            goto invalid;
        Block* block = m_blocks;
        if (block == 0)
            goto invalid;
        do
        {
            if (!reinterpret_cast<FreeAllocator*>(m_blockServer)->TestBlock(block))
                goto invalid;
            unsigned int base = reinterpret_cast<unsigned int>(block->m_start);
            unsigned int addr = reinterpret_cast<unsigned int>(pNode);
            if (addr >= base && addr < base + block->m_numElements * m_elementSize)
            {
                if ((addr - base) % m_elementSize != 0)
                    goto invalid;
                break;
            }
            block = block->m_next;
        } while (block != 0);
        if (block == 0)
            goto invalid;
        pNode = pNode->m_next;
    }
    *result = true;
    return result;
invalid:
    *result = false;
    return result;
}

// Walks the linked list from pNode and sums the counter's count for each node, returning the total.
// @fnv 0x00dd72a0
int hkFreeList::SumNodeCounts(Block* pStartNode)
{
    int iSum = 0;
    for (; pStartNode; pStartNode = pStartNode->m_next)
        iSum += reinterpret_cast<int(__thiscall*)(hkFreeListAllocatorServer*, Block*, int)>((*reinterpret_cast<void***>(m_blockServer))[4])(m_blockServer, pStartNode, pStartNode->m_blockSize);
    return iSum;
}

// LocalhkBool: include/hkBool.h has a trivial copy; 0x00dd72f0 passes the flag through a non-trivial copy constructor.
namespace memory_walk {
class LocalhkBool
{
  public:
    LocalhkBool(bool b) { m_cBooleanValue = (char)b; }
    LocalhkBool(const LocalhkBool& o) { m_cBooleanValue = o.m_cBooleanValue; }
    char m_cBooleanValue;
};
}

// Walks the free list and invokes callback on each element of every block, reporting it as not allocated.
// @fnv 0x00dd72f0
void hkFreeList::WalkFreeBlocks(hkFreeList::Block* block, FreeBlockWalkCallback callback, int pool, void* param)
{
    for (; block; block = block->m_next)
    {
        char* p = block->m_start;
        char* end = p + block->m_numElements * m_elementSize;
        for (; p < end; p += m_elementSize)
            callback(p, m_elementSize, memory_walk::LocalhkBool(false), pool, param);
    }
}

// Returns an element from a reused free block or a newly allocated server block.
// @fnv 0x00dd7540
void* hkFreeList::AllocateElement()
{
    hkFreeList::Block* pkBlock = m_freeBlocks;
    if (pkBlock)
    {
        m_freeBlocks = pkBlock->m_next;
        m_top = pkBlock->m_start;
        m_blockEnd = pkBlock->m_start + pkBlock->m_numElements * m_elementSize;
        pkBlock->m_next = m_blocks;
        m_blocks = pkBlock;
        m_numFreeElements--;
        void* p = m_top;
        m_top += m_elementSize;
        return p;
    }

    if (m_blockSize <= 0)
    {
        unsigned int auiCount = 256 / m_elementSize;
        if (auiCount < 1)
            auiCount = 1;
        m_blockSize = reinterpret_cast<unsigned int>(hkFreeList_bestBlockSize(reinterpret_cast<void*>(m_elementSize * auiCount), m_alignment));
    }
    else if (m_blockSize < m_maxBlockSize)
    {
        unsigned int auiCount = m_blockSize / m_elementSize;
        if (auiCount < 8)
            auiCount = 8;
        else
            auiCount += auiCount >> 1;
        m_blockSize = reinterpret_cast<unsigned int>(hkFreeList_bestBlockSize(reinterpret_cast<void*>(m_elementSize * auiCount), m_alignment));
    }

    // The block server allocates at slot 1 and reports allocated size at slot 4;
    // hkMemoryAllocator uses slot 4 for ReturnMemory. The shared server is opaque.
    typedef void*(__thiscall* AllocateBlock)(hkFreeListAllocatorServer*, int);
    typedef int(__thiscall* GetAllocatedSize)(hkFreeListAllocatorServer*, const void*, int);
    pkBlock = (hkFreeList::Block*)reinterpret_cast<AllocateBlock>(
        (*reinterpret_cast<void***>(m_blockServer))[1])(m_blockServer, m_blockSize);
    if (!pkBlock)
        return 0;
    int iAllocatedSize = reinterpret_cast<GetAllocatedSize>(
        (*reinterpret_cast<void***>(m_blockServer))[4])(m_blockServer, pkBlock, m_blockSize);
    pkBlock->m_blockSize = iAllocatedSize;
    char* pcStart = (char*)(((unsigned int)(pkBlock + 1) + m_alignment - 1) & ~(m_alignment - 1));
    pkBlock->m_start = pcStart;
    pkBlock->m_numElements = (unsigned int)((char*)pkBlock + iAllocatedSize - pkBlock->m_start) / m_elementSize;
    m_top = pkBlock->m_start;
    m_blockEnd = pkBlock->m_start + pkBlock->m_numElements * m_elementSize;
    pkBlock->m_next = m_blocks;
    m_blocks = pkBlock;
    m_numElements += pkBlock->m_numElements;
    m_numFreeElements += pkBlock->m_numElements - 1;
    void* p = m_top;
    m_top += m_elementSize;
    return p;
}

// 0x00c85750 returns a thread-local cursor whose first field is the scratch-stack top.
struct StackAllocationCursor
{
    char* m_pcCur;
};
extern "C" StackAllocationCursor* __cdecl hkMemoryRouter_getInstance();

template <class T> inline T* AllocateFreeListScratch(int iCount)
{
    StackAllocationCursor* pkStack = hkMemoryRouter_getInstance();
    T* pResult = (T*)pkStack->m_pcCur;
    pkStack->m_pcCur = (char*)pResult + ((iCount * sizeof(T) + 127) & ~127);
    return pResult;
}

template <class T> inline void ReleaseFreeListScratch(T* p)
{
    hkMemoryRouter_getInstance()->m_pcCur = (char*)p;
}

bool __cdecl CompareLessThan(const hkFreeList::Element* pkA, const hkFreeList::Element* pkB);
void __cdecl hkAlgorithm_quickSortRecursive_hkFreeList_Block_hkBool_cdecl_hkFreeList_Block_const_hkFreeList_Block_const(hkFreeList::Element** ppArray, int iLow, int iHigh,
                          bool(__cdecl* pfnLess)(const hkFreeList::Element*, const hkFreeList::Element*));

// Removes elements in the block range, then sorts and relinks them; returns 1 for a fully free block.
// @fnv 0x00dd7b40
// src: HAVOK_LIB 0x00dd7b40
int hkFreeList::_calcBlockFree(hkFreeList::Block* pkBlock)
{
    Element** ppElems = AllocateFreeListScratch<Element*>(static_cast<int>(pkBlock->m_numElements));

    int iNumFound = 0;
    char* pcStart = pkBlock->m_start;
    char* pcEnd = pcStart + static_cast<int>(pkBlock->m_numElements) * m_elementSize;
    Element* pkPrev = (Element*)this;
    for (Element* pkNode = m_free; pkNode; pkNode = pkNode->m_next)
    {
        if ((char*)pkNode >= pcStart && (char*)pkNode < pcEnd)
        {
            ppElems[iNumFound++] = pkNode;
            pkPrev->m_next = pkNode->m_next;
        }
        else
            pkPrev = pkNode;
    }

    if (m_top >= pcStart && m_top < pcEnd)
    {
        if (iNumFound + (m_blockEnd - m_top) / m_elementSize == static_cast<int>(pkBlock->m_numElements))
        {
            m_top = 0;
            m_blockEnd = 0;
            ReleaseFreeListScratch(ppElems);
            return 1;
        }
    }
    else if (iNumFound == static_cast<int>(pkBlock->m_numElements))
    {
        ReleaseFreeListScratch(ppElems);
        return 1;
    }

    if (iNumFound > 0)
    {
        if (iNumFound > 1)
            hkAlgorithm_quickSortRecursive_hkFreeList_Block_hkBool_cdecl_hkFreeList_Block_const_hkFreeList_Block_const(ppElems, 0, iNumFound - 1, CompareLessThan);
        Element* pkLast = ppElems[0];
        for (int i = 1; i < iNumFound; i++)
        {
            Element* pkNext = ppElems[i];
            pkLast->m_next = pkNext;
            pkLast = pkNext;
        }
        ppElems[iNumFound - 1]->m_next = m_free;
        m_free = ppElems[0];
    }
    ReleaseFreeListScratch(ppElems);
    return 0;
}

// @fnv 0x00dd7c40
// src: HAVOK_LIB 0x00dd7c40
hkBool hkFreeList::incrementalFindGarbage(int iMaxBlocks, int& iNumBlocksOut) throw()
{
    int i = 0;
    for (; i < iMaxBlocks; i++)
    {
        if (m_incrementalBlock)
        {
            hkFreeList::Block* pkBlock = m_incrementalBlock->m_next;
            if (!pkBlock)
            {
                iNumBlocksOut = i;
                m_incrementalBlock = 0;
                return true;
            }
            if (_calcBlockFree(pkBlock))
            {
                m_incrementalBlock->m_next = pkBlock->m_next;
                pkBlock->m_next = m_freeBlocks;
                m_freeBlocks = pkBlock;
            }
            else
            {
                m_incrementalBlock = pkBlock;
            }
        }
        else
        {
            hkFreeList::Block* pkBlock = m_blocks;
            if (!pkBlock)
            {
                iNumBlocksOut = i;
                m_incrementalBlock = 0;
                return true;
            }
            if (_calcBlockFree(pkBlock))
            {
                m_blocks = pkBlock->m_next;
                pkBlock->m_next = m_freeBlocks;
                m_freeBlocks = pkBlock;
            }
            else
            {
                m_incrementalBlock = pkBlock;
            }
        }
    }
    iNumBlocksOut = i;
    return m_incrementalBlock == 0;
}

struct B60Link
{
    int unk00;
    int unk04;
};

struct B60Large
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct B60State
{
    int current;
    int link;
    int limit;
};

struct B60Owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
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
    int unkA4;

    void AdvanceState(unsigned char* result, B60State* state);
};

// Advances state->current by the masked link offset; when it reaches the limit, moves to the next link or resets, and writes 1 or 0 to result.
// @fnv 0x00dd8b60
void B60Owner::AdvanceState(unsigned char* result, B60State* state)
{
    int current = state->current;

    if (current == 0)
        goto empty;

    current += (*(int*)(current + 4) & 0xFFFFFFFC);
    state->current = current;

    if (current == state->limit)
    {
        int next = ((B60Link*)state->link)->unk04;

        if (next == (int)((char*)this + 0xA4))
        {
            state->current = 0;
            goto empty;
        }

        state->link = next;
        state->current = ((B60Large*)next)->unk10;
        state->limit = ((B60Large*)next)->unk14 - 0x10;
    }

    *result = 1;
    return;

empty:
    *result = 0;
}

// @fnv 0x00dd7380
// src: HAVOK_LIB 0x00dd7380
void hkFreeList::freeSmallFreeBlocks(unsigned int key)
{
    Block** prev = &m_freeBlocks;
    Block* block = m_freeBlocks;
    while (block)
    {
        if (static_cast<unsigned int>(block->m_blockSize) <= key)
        {
            Block* next = block->m_next;
            *prev = next;
            m_numElements -= block->m_numElements;
            hkFreeListAllocatorServer* allocator = m_blockServer;
            m_numFreeElements -= block->m_numElements;
            reinterpret_cast<void(__thiscall*)(hkFreeListAllocatorServer*, Block*)>((*reinterpret_cast<void***>(allocator))[2])(allocator, block);
            block = next;
        }
        else
        {
            prev = &block->m_next;
            block = block->m_next;
        }
    }
}

struct FreeListStatistics
{
    int m_iTotal;
    int m_iSpan;
    int unk08;
    int m_iStart;
    int m_iStartCopy;
    int m_iArrayCapacity;
};

// Fills the statistics record from the block lists, element size and element counts.
// @fnv 0x00dd7430
// src: HAVOK_LIB 0x00dd7430
void hkFreeList::calculateStatistics(FreeListStatistics* pkInfo)
{
    pkInfo->m_iTotal = SumNodeCounts(m_freeBlocks) + SumNodeCounts(m_blocks);
    int iFirst = m_numFreeElements;
    int iLast = m_numElements;
    pkInfo->m_iStart = m_elementSize * iFirst;
    pkInfo->m_iSpan = (iLast - iFirst) * m_elementSize;
    pkInfo->m_iArrayCapacity = m_elementSize;
    pkInfo->m_iStartCopy = pkInfo->m_iStart;
}

// Block-server view: 0x00dd7680 uses virtual slots 6 and 7 for temporary buffers.
struct BlockBufferAllocatorInterface
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void* AllocateBufferWithSize(int numBytes);
    virtual void ReturnMemory(void* p, int numBytes);
};

void __cdecl hkFreeList_quickSortRecursive(void** pArr, int d, int h, bool(__cdecl* cmpLess)(const void*, const void*));
bool __cdecl hkFreeList_comparePointers(const void* a, const void* b);

// Sorts blocks and free elements, collects fully free blocks, and rebuilds the active and free-element lists.
// @fnv 0x00dd7680
int hkFreeList::Compact()
{
    if (!m_blocks)
    {
        return 0;
    }

    int numBlocks = 0;
    for (Block* block = m_blocks; block; block = block->m_next)
    {
        numBlocks++;
    }

    int blocksSize = numBlocks * sizeof(Block*);
    Block** blocks = (Block**)reinterpret_cast<BlockBufferAllocatorInterface*>(m_blockServer)->AllocateBufferWithSize(blocksSize);
    if (!blocks)
    {
        return -1;
    }

    if (m_blocks)
    {
        Block** dst = blocks;
        for (Block* block = m_blocks; block; block = block->m_next)
        {
            *dst++ = block;
        }
    }

    if (numBlocks > 1)
    {
        hkFreeList_quickSortRecursive((void**)blocks, 0, numBlocks - 1, hkFreeList_comparePointers);
    }

    int numElements = int(m_blockEnd - m_top) / m_elementSize;
    for (Element* pElement = m_free; pElement; pElement = pElement->m_next)
    {
        numElements++;
    }

    int elementsSize = numElements * sizeof(Element*);
    Element** elements = (Element**)reinterpret_cast<BlockBufferAllocatorInterface*>(m_blockServer)->AllocateBufferWithSize(elementsSize);
    if (!elements)
    {
        reinterpret_cast<BlockBufferAllocatorInterface*>(m_blockServer)->ReturnMemory(blocks, blocksSize);
        return -1;
    }

    {
        int n = 0;
        for (Element* pElement = m_free; pElement; pElement = pElement->m_next)
        {
            elements[n++] = pElement;
        }
        for (char* p = m_top; p < m_blockEnd; p += m_elementSize)
        {
            elements[n++] = (Element*)p;
        }
    }

    m_top = m_blockEnd = 0;

    if (numElements > 1)
    {
        hkFreeList_quickSortRecursive((void**)elements, 0, numElements - 1, hkFreeList_comparePointers);
    }

    Element** cur = elements;
    Element** end = elements + numElements;
    int numFreed = 0;

    for (unsigned int i = 0; i < (unsigned int)numBlocks && cur < end; i++)
    {
        Block* block = blocks[i];
        int blockElements = block->m_numElements;
        unsigned int elementSize = m_elementSize;
        char* p = block->m_start;
        char* blockEnd = p + blockElements * elementSize;

        while (cur < end)
        {
            if (p != (char*)*cur || p >= blockEnd)
            {
                break;
            }
            cur++;
            p += elementSize;
        }

        if (p == blockEnd)
        {
            numFreed++;
            block->m_next = m_freeBlocks;
            m_freeBlocks = block;
            blocks[i] = 0;
            for (Element** e = cur - blockElements; e < cur; e++)
            {
                *e = 0;
            }
        }
        else
        {
            while (cur < end && (char*)*cur < blockEnd)
            {
                cur++;
            }
        }
    }

    {
        Block** prev = &m_blocks;
        for (unsigned int i = 0; i < (unsigned int)numBlocks; i++)
        {
            Block* block = blocks[i];
            if (block)
            {
                *prev = block;
                prev = &block->m_next;
            }
        }
        *prev = 0;
    }

    {
        Element** prev = &m_free;
        for (Element** e = elements; e < end; e++)
        {
            Element* pElement = *e;
            if (pElement)
            {
                *prev = pElement;
                prev = &pElement->m_next;
            }
        }
        *prev = 0;
    }

    reinterpret_cast<BlockBufferAllocatorInterface*>(m_blockServer)->ReturnMemory(elements, elementsSize);
    reinterpret_cast<BlockBufferAllocatorInterface*>(m_blockServer)->ReturnMemory(blocks, blocksSize);
    m_incrementalBlock = 0;
    return numFreed;
}

// Block-server view: 0x00dd78f0 uses virtual slots 2, 6 and 7; not an hkFreeList.
struct BlockWalkServerInterface
{
    virtual ~BlockWalkServerInterface();
    virtual void* unk04();
    virtual void free(void* p);
    virtual void unk0c();
    virtual void unk10();
    virtual void unk14();
    virtual void* AllocateBufferWithSize(int numBytes);
    virtual void ReturnMemory(void* p, int numBytes);
};

bool __cdecl CompareLessThan(void* a, void* b);
void __cdecl hkAlgorithm_quickSortRecursive_hkFreeList_Block_hkBool_cdecl_hkFreeList_Block_const_hkFreeList_Block_const(void** arr, int lo, int hi, bool(__cdecl* cmpLess)(void*, void*));

inline void quickSortPointers(void** arr, int numElem)
{
    if (numElem > 1)
    {
        hkAlgorithm_quickSortRecursive_hkFreeList_Block_hkBool_cdecl_hkFreeList_Block_const_hkFreeList_Block_const(arr, 0, numElem - 1, CompareLessThan);
    }
}

// Walks free blocks, then reports slots in active blocks through the callback with their allocation status.
// @fnv 0x00dd78f0
// src: HAVOK_LIB 0x00dd78f0
void hkFreeList::walkMemory_00dd78f0(hkMemoryWalkCallback callback, int pool, void* param)
{
    WalkFreeBlocks(m_freeBlocks, reinterpret_cast<FreeBlockWalkCallback>(callback), pool, param);

    if (m_blocks == 0 && m_free == 0)
    {
        return;
    }

    int numBlocks = 0;
    for (Block* block = m_blocks; block; block = block->m_next)
    {
        numBlocks++;
    }

    Block** blocks =
        (Block**)reinterpret_cast<BlockWalkServerInterface*>(m_blockServer)->AllocateBufferWithSize(numBlocks * sizeof(Block*));
    if (!blocks)
    {
        return;
    }
    {
        int i = 0;
        for (Block* block = m_blocks; block; block = block->m_next)
        {
            blocks[i++] = block;
        }
    }
    quickSortPointers((void**)blocks, numBlocks);

    int numFree = (m_blockEnd - m_top) / m_elementSize;
    for (Element* elem = m_free; elem; elem = elem->m_next)
    {
        numFree++;
    }

    char** freeElems = (char**)reinterpret_cast<BlockWalkServerInterface*>(m_blockServer)->AllocateBufferWithSize(numFree * sizeof(char*));
    if (!freeElems)
    {
        reinterpret_cast<BlockWalkServerInterface*>(m_blockServer)->free(blocks);
        return;
    }
    {
        int i = 0;
        for (Element* elem = m_free; elem; elem = elem->m_next)
        {
            freeElems[i++] = (char*)elem;
        }
        for (char* p = m_top; p < m_blockEnd; p += m_elementSize)
        {
            freeElems[i++] = p;
        }
    }
    quickSortPointers((void**)freeElems, numFree);

    char** curFree = freeElems;
    char** endFree = freeElems + numFree;

    unsigned int i = 0;
    for (; i < (unsigned int)numBlocks; i++)
    {
        if (curFree >= endFree)
        {
            break;
        }
        Block* block = blocks[i];
        unsigned int numElements = block->m_numElements;
        char* start = block->m_start;
        char* end = start + m_elementSize * numElements;
        for (char* p = start; p < end; p += m_elementSize)
        {
            if (p == *curFree)
            {
                callback(p, m_elementSize, false, pool, param);
                curFree++;
            }
            else
            {
                callback(p, m_elementSize, true, pool, param);
            }
        }
    }
    for (; i < (unsigned int)numBlocks; i++)
    {
        Block* block = blocks[i];
        char* p = block->m_start;
        for (unsigned int j = 0; j < block->m_numElements; j++)
        {
            callback(p, m_elementSize, true, pool, param);
            p += m_elementSize;
        }
    }

    reinterpret_cast<BlockWalkServerInterface*>(m_blockServer)->ReturnMemory(freeElems, numFree * sizeof(char*));
    reinterpret_cast<BlockWalkServerInterface*>(m_blockServer)->ReturnMemory(blocks, numBlocks * sizeof(Block*));
}

// Initializes the list, rounds the element size to its alignment, and records the block-server settings.
// @fnv 0x00dd74b0
// src: HAVOK_LIB 0x00dd74b0
void hkFreeList::_init(int a2, int aiAlignment, int a4, int a5)
{
    m_free = 0;
    m_blocks = 0;
    m_freeBlocks = 0;
    m_blockSize = a4;
    m_top = 0;
    m_blockEnd = 0;
    m_numFreeElements = 0;
    m_numElements = 0;
    m_alignment = aiAlignment;
    m_blockServer = reinterpret_cast<hkFreeListAllocatorServer*>(a5);
    m_incrementalBlock = 0;

    unsigned int size;
    if ((unsigned int)a2 < (unsigned int)aiAlignment)
        size = (unsigned int)aiAlignment;
    else
        size = ((unsigned int)a2 + (unsigned int)aiAlignment - 1u) & ~((unsigned int)aiAlignment - 1u);

    m_elementSize = (int)size;
    m_maxBlockSize = (int)hkFreeList_bestBlockSize((void*)0xFF0u, (unsigned int)aiAlignment);
}

// @fnv 0x00dd72d0
// src: HAVOK_LIB 0x00dd72d0
int hkFreeList::_calcTotalNumElements()
{
    int first = SumFreeListSizes(this->m_freeBlocks);
    return first + SumFreeListSizes(this->m_blocks);
}
