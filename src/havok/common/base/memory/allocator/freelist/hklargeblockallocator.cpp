#include "../../../../../../../include/hkLargeBlockAllocator.h"
#include "../../../../../../../include/hkIArchive.h"
#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkReferencedObject.h"

inline unsigned int hkLargeBlockAllocator::Chunk::getChunkSize() const { return head & ~3u; }
inline bool hkLargeBlockAllocator::Chunk::isPinuse() const { return (head & 1) != 0; }
inline bool hkLargeBlockAllocator::Chunk::isCinuse() const { return (head & 2) != 0; }
inline bool hkLargeBlockAllocator::Chunk::isInuse() const { return ((head >> 1) & 1) != 0; }
inline hkLargeBlockAllocator::Chunk* hkLargeBlockAllocator::Chunk::chunkPlusOffset(unsigned int s) { return (Chunk*)((char*)this + s); }
inline hkLargeBlockAllocator::Chunk* hkLargeBlockAllocator::Chunk::chunkMinusOffset(unsigned int s) { return (Chunk*)((char*)this - s); }
inline void hkLargeBlockAllocator::Chunk::setSizeAndPinuseOfFreeChunk(unsigned int s) { head = s | 1; chunkPlusOffset(s)->m_uiPreviousChunkSize = s; }
inline void hkLargeBlockAllocator::Chunk::setFreeWithPinuse(unsigned int s, Chunk* n) { n->head &= ~1u; setSizeAndPinuseOfFreeChunk(s); }
inline void* hkLargeBlockAllocator::Chunk::getPayload() { return (void*)(this + 1); }
inline unsigned int hkLargeBlockAllocator::Chunk::getPayloadSize() const { return getChunkSize() - sizeof(Chunk); }
inline hkLargeBlockAllocator::Chunk* hkLargeBlockAllocator::Chunk::nextChunk() { return (Chunk*)((char*)this + getChunkSize()); }
inline hkLargeBlockAllocator::Chunk* hkLargeBlockAllocator::Page::getFirstChunk() { return (Chunk*)m_kRayStart; }
inline hkLargeBlockAllocator::Chunk* hkLargeBlockAllocator::Page::getFooter() { return (Chunk*)(m_kRayEnd - sizeof(Chunk)); }

// src/havok/common/base/memory/allocator/freelist/hklargeblockallocator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/memory/allocator/freelist/hklargeblockallocator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00dd74b0_cls
{
    void _init(int a, int b, int c, int d);
    void* hkFreeList_hkFreeList(int a, int b, int c, int d);
};
// Calls FUN_00dd74b0 with the four arguments and returns this.
// @fnv 0x00dd7650
// src: HAVOK_LIB 0x00dd7650
void* __thiscall FUN_00dd74b0_cls::hkFreeList_hkFreeList(int a, int b, int c, int d)
{
    _init(a, b, c, d);
    return this;
}

// @fnv 0x00dd8a80
// src: HAVOK_LIB 0x00dd8a80
void* __stdcall hkLargeBlockAllocator_getAllocatedSize(void* p, void* apUnused)
{
    return reinterpret_cast<char*>(reinterpret_cast<size_t*>(p)[-3] & 0xfffffffc) - 0x10;
}

extern int DAT_0102e388;
extern int DAT_010d7c80;

// Not an hkLargeBlockAllocator member: 0x00dd91f0 stores hkIArchive's vftable
// (RTTI 0x010d7c80, base hkReferencedObject), releases m_streamReader at +8 and
// restores hkBaseObject's vftable (0x0102e388), i.e. the hkIArchive destructor body.
// @fnv 0x00dd91f0
// src: GUESS 0x00dd91f0 (confidence: medium)
void hkIArchive::ReleaseArchiveReader()
{
    *(int**)this = (int*)&DAT_010d7c80;
    if (m_streamReader)
        m_streamReader->removeReference();
    *(int**)this = (int*)&DAT_0102e388;
}

// Returns the value at a[-3] with the low two bits cleared.
// @fnv 0x00dd8a90
// src: HAVOK_LIB 0x00dd8a90
int __stdcall hkLargeBlockAllocator_getAllocatedSizeWithOverhead(int* pValues, int iUnused)
{
    return (pValues[-3] & 0xfffffffc);
}

// Clears the pool's counters, buckets, free list and sentinel node, then sets the block shift to 3.
// @fnv 0x00dd7f10
// src: HAVOK_LIB 0x00dd7f10
void hkLargeBlockAllocator::_init_00dd7f10()
{
    m_peakBytes = 0;
    m_totalBytes = 0;
    m_numAllocated = 0;
    m_numFree = 0;
    for (int i = 0; i < 32; i++)
        m_buckets[i] = 0;
    m_freeHead = 0;
    m_kFreeListEntries = 0;
    m_blockShift = 3;
    m_freeListPtr = &m_freeHead;
    m_kBlocks.m_pSecondNode = &m_kBlocks;
    m_kBlocks.m_next = &m_kBlocks;
}

struct WorkItem
{
    int unk00;
    WorkItem* next;
    int unk08;
    int value;
};

struct WorkProcessor
{
    virtual void first();
    virtual void second();
    virtual void third();
    virtual void fourth();
    virtual void process(WorkItem*, int);
};

// Iterates the sentinel-linked list from sentinel.next, calling processor->process on each item with its value, then calls FUN_00dd7f10.
// @fnv 0x00dd7fc0
void hkLargeBlockAllocator::ProcessAllItems()
{
    WorkItem* current = ((WorkItem*)&m_kPage)->next;
    if (current != (WorkItem*)&m_kPage)
    {
        do
        {
            int value = current->value;
            WorkProcessor* pProcessor = (WorkProcessor*)m_provider;
            WorkItem* next = current->next;
            pProcessor->process(current, value);
            current = next;
        } while (current != (WorkItem*)&m_kPage);
    }
    _init_00dd7f10();
}

struct TreeChunk
{
    unsigned int m_iWordAt00;
    unsigned int m_pFirstNode;
    int m_8, m_iThirdValue;
    TreeChunk* m_pChildAtom[2];
};

// @fnv 0x00dd8310
unsigned int __stdcall GetMaxChunkSize(TreeChunk* apTreeChunk, unsigned int maxSize)
{
    while (apTreeChunk)
    {
        unsigned int size = apTreeChunk->m_pFirstNode & ~3u;
        if (size > maxSize)
            maxSize = size;
        apTreeChunk = apTreeChunk->m_pChildAtom[1] ? apTreeChunk->m_pChildAtom[1] : apTreeChunk->m_pChildAtom[0];
    }
    return maxSize;
}

int __cdecl hkLargeBlockAllocator__computeTreeIndex(unsigned int size);

// @fnv 0x00dd8350
// src: HAVOK_LIB 0x00dd8350
unsigned int hkLargeBlockAllocator::findLargestBlockSize()
{
    unsigned int size = m_uiChunkSize;
    int idx = hkLargeBlockAllocator__computeTreeIndex(size);
    for (int i = 31; i >= idx; i--)
    {
        void* tree = m_treeBins[i];
        if (tree)
            return GetMaxChunkSize(tree, size);
    }
    return size;
}

// Frees a block: merges it with adjacent free chunks, updates the top chunk or inserts the merged chunk into the free list.
// @fnv 0x00dd89b0
void hkLargeBlockAllocator::Free(void* mem)
{
    if (!mem)
        return;
    hkLargeBlockAllocator::Chunk* p = (hkLargeBlockAllocator::Chunk*)((char*)mem - 16);
    unsigned int uiChunkSize = p->getChunkSize();
    m_uiBufferCapacity -= uiChunkSize;
    m_overhead += 16 - p->getChunkSize();
    hkLargeBlockAllocator::Chunk* next = p->chunkPlusOffset(uiChunkSize);
    if (!p->isPinuse())
    {
        unsigned int prevsize = p->m_uiPreviousChunkSize;
        p = p->chunkMinusOffset(prevsize);
        _unlinkChunk(p);
        uiChunkSize += prevsize;
    }
    if (!next->isCinuse())
    {
        if (next == m_fMinimumV)
        {
            unsigned int uiTopSize = m_uiChunkSize += uiChunkSize;
            m_fMinimumV = p;
            p->head = uiTopSize | 1;
            return;
        }
        unsigned int uiNextSize = next->getChunkSize();
        uiChunkSize += uiNextSize;
        _unlinkChunk(next);
        p->setSizeAndPinuseOfFreeChunk(uiChunkSize);
    }
    else
    {
        p->setFreeWithPinuse(uiChunkSize, next);
    }
    _insertChunk(p, uiChunkSize);
}

typedef void(__cdecl* S_00dd8aa0_Callback)(void* start, unsigned int size, void* param);

// @fnv 0x00dd8aa0
void hkLargeBlockAllocator::ForEachAllocatedBlock(S_00dd8aa0_Callback callback, void* param)
{
    m_fMinimumV->head = m_uiChunkSize | 1;
    for (hkLargeBlockAllocator::Page* page = m_kPage.m_next; page != &m_kPage; page = page->m_next)
    {
        hkLargeBlockAllocator::Chunk* end = page->getFooter();
        for (hkLargeBlockAllocator::Chunk* cur = page->getFirstChunk(); cur != end;)
        {
            unsigned int size = cur->getChunkSize();
            if (cur->isInuse())
                callback(cur->getPayload(), cur->getPayloadSize(), param);
            cur = (hkLargeBlockAllocator::Chunk*)((char*)cur + size);
        }
    }
}

// @fnv 0x00dd7e70
// src: HAVOK_LIB 0x00dd7e70
int __cdecl hkLargeBlockAllocator__bitToIndex(int aiValue)
{
    unsigned int r = (unsigned int)(aiValue - 1);
    unsigned int t = r >> 12 & 0x10;
    unsigned int kIter = 0;
    kIter += t;
    r >>= t;
    t = r >> 5 & 8;
    kIter += t;
    r >>= t;
    t = r >> 2 & 4;
    kIter += t;
    r >>= t;
    t = r >> 1 & 2;
    kIter += t;
    r >>= t;
    t = r >> 1 & 1;
    kIter += t;
    r >>= t;
    return (int)(r + kIter);
}

// Exe 0x00dd7ec0: unit-local ListNode view; declarations and layout are preserved.
struct HklargeblockallocatorListNodeView
{
    int unk00;
    HklargeblockallocatorListNodeView* next;
    int unk08;
    int value;
};

extern int DAT_010d7c34;
extern int DAT_010d7c10;

struct ListTarget
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10(HklargeblockallocatorListNodeView* node, int value);
};

// Sets the vtable, walks the m_a4 list calling m_98->v10 on each node, then sets the second vtable.
// @fnv 0x00dd7ec0
// src: GUESS 0x00dd7ec0 (confidence: low)
void hkLargeBlockAllocator::ProcessEntries_00dd7ec0()
{
    *(int**)this = &DAT_010d7c34;
    ::HklargeblockallocatorListNodeView* sentinel = (::HklargeblockallocatorListNodeView*)&m_a4;
    ::HklargeblockallocatorListNodeView* node = ((::HklargeblockallocatorListNodeView*)&m_a4)->next;
    if (node != sentinel)
    {
        do
        {
            int value = node->value;
            ::HklargeblockallocatorListNodeView* next = node->next;
            ((ListTarget*)m_provider)->v10(node, value);
            node = next;
        } while (node != sentinel);
    }
    *(int**)this = &DAT_010d7c10;
}

struct tchunk
{
    int prev_foot;
    int head;
    tchunk* fd;
    tchunk* bk;
    tchunk* child[2];
    tchunk* parent;
    int index;
};

int __cdecl hkLargeBlockAllocator__computeTreeIndex(int size);

// Computes a bin index from size, then inserts chunk x into that bin's list or tree, splitting by size bits until a matching chunk or empty slot is found.
// @fnv 0x00dd8010
void hkLargeBlockAllocator::InsertChunk(tchunk* pChunk, int size)
{
    tchunk** ppBin;
    int index;
    index = hkLargeBlockAllocator__computeTreeIndex(size);
    ppBin = &m_apChunkLists[index];
    pChunk->index = index;
    pChunk->child[0] = pChunk->child[1] = 0;
    if ((m_uiChunkCount & (1U << index)) == 0)
    {
        m_uiChunkCount |= (1U << index);
        *ppBin = pChunk;
        pChunk->parent = (tchunk*)ppBin;
        pChunk->fd = pChunk;
        pChunk->bk = pChunk;
    }
    else
    {
        tchunk* pTree = *ppBin;
        int shift = (index == 0x1f) ? 0 : (0x19 - (index >> 1));
        unsigned int uiBits = (unsigned int)size << shift;
        for (;;)
        {
            if ((pTree->head & ~3) != size)
            {
                tchunk** ppChild = &pTree->child[uiBits >> 31];
                uiBits += uiBits;
                if (*ppChild != 0)
                {
                    pTree = *ppChild;
                }
                else
                {
                    *ppChild = pChunk;
                    pChunk->parent = pTree;
                    pChunk->fd = pChunk;
                    pChunk->bk = pChunk;
                    break;
                }
            }
            else
            {
                tchunk* pNext = pTree->fd;
                pNext->bk = pChunk;
                pTree->fd = pChunk;
                pChunk->bk = pTree;
                pChunk->fd = pNext;
                pChunk->parent = 0;
                break;
            }
        }
    }
}

// Unlinks node from its sibling list or replaces it with a successor in the tree, then detaches it from its bin and reattaches its children to the replacement.
// @fnv 0x00dd80d0
void hkLargeBlockAllocator::RemoveNode(hkLargeBlockAllocator::TreeChunk* node)
{
    hkLargeBlockAllocator::TreeChunk* next = (TreeChunk*)node->bk;
    hkLargeBlockAllocator::TreeChunk* tree = node->parent;
    hkLargeBlockAllocator::TreeChunk* r;

    if (next != node)
    {
        hkLargeBlockAllocator::TreeChunk* prev = (TreeChunk*)node->fd;
        prev->bk = next;
        next->fd = prev;
        r = next;
    }
    else
    {
        hkLargeBlockAllocator::TreeChunk** slot = &node->child[1];
        r = node->child[1];
        if (r == 0)
        {
            r = node->child[0];
            slot = &node->child[0];
        }
        if (r != 0)
        {
            for (;;)
            {
                hkLargeBlockAllocator::TreeChunk** cur = &r->child[1];
                if (r->child[1] == 0)
                {
                    cur = &r->child[0];
                    if (r->child[0] == 0)
                    {
                        *slot = 0;
                        break;
                    }
                }
                r = *cur;
                slot = cur;
            }
        }
    }

    if (tree != 0)
    {
        unsigned int bin = node->index;
        hkLargeBlockAllocator::TreeChunk** head = &this->m_bins[bin];
        if (node == *head)
        {
            *head = r;
            if (r == 0)
            {
                this->m_freeMask &= ~(1u << node->index);
                return;
            }
        }
        else
        {
            if (tree->child[0] == node)
            {
                tree->child[0] = r;
            }
            else
            {
                tree->child[1] = r;
            }
            if (r == 0)
            {
                return;
            }
        }
        r->parent = tree;
        hkLargeBlockAllocator::TreeChunk* left = node->child[0];
        if (left != 0)
        {
            r->child[0] = left;
            left->parent = r;
        }
        hkLargeBlockAllocator::TreeChunk* right = node->child[1];
        if (right != 0)
        {
            r->child[1] = right;
            right->parent = r;
        }
    }
}

// @fnv 0x00dd83a0
// src: HAVOK_LIB 0x00dd83a0
__declspec(noinline) void hkLargeBlockAllocator::_makeTopValid()
{
    *(unsigned int*)(m_10 + 4) = m_14 | 1;
    *(unsigned int*)(m_10 + m_14) = m_14;
}

// Advances the allocator's counters and next pointer by a, writes size and flags into the new block header, and returns the previous block's payload.
// @fnv 0x00dd83c0
void* hkLargeBlockAllocator::AllocateBlock(int aiSize)
{
    unkBC += aiSize;
    unkC0 += aiSize - 0x10;
    unk14 -= aiSize;
    char* pBlock = m_next;
    int flags = unk14 | 1;
    char* node = pBlock + aiSize;
    m_next = node;
    *(int*)node = aiSize;
    *(int*)(node + 4) = flags;
    *(int*)(pBlock + 4) = aiSize | 3;
    return pBlock + 0x10;
}

int __stdcall ProbeSmall(int a);

// Tries ProbeSmall when m_08 is set, then AllocSlow if a+0x100 is below m_14, otherwise returns 0.
// @fnv 0x00dd8480
int hkLargeBlockAllocator::Allocate(int aiSize)
{
    if (m_08 != 0)
    {
        int r = ProbeSmall(aiSize);
        if (r != 0)
        {
            return r;
        }
    }
    if ((unsigned int)(aiSize + 0x100) < m_14)
    {
        return AllocSlow(aiSize);
    }
    return 0;
}

struct hkMemoryManager
{
    virtual void* unk00() = 0;
    virtual void* unk04() = 0;
    virtual void* unk08() = 0;
    virtual void* unk0c() = 0;
    virtual void* unk10() = 0;
    virtual void* unk14() = 0;
    virtual void* unk18() = 0;
    virtual void* unk1c() = 0;
    virtual void* unk20() = 0;
    virtual void* allocate(unsigned int size) = 0;
};

// Rounds size up to a 16-byte multiple, allocates it via this allocator or unk98, writes a tag at the start and returns the block offset by 0x10.
// @fnv 0x00dd8700
// src: HAVOK_LIB 0x00dd8700
void* hkLargeBlockAllocator::criticalAlloc(unsigned int size)
{
    unsigned int uiAlignedSize = (size + 0x1fu) & 0xfffffff0u;
    void* block = vf01(uiAlignedSize);

    if (block != 0)
    {
        *static_cast<int*>(block) = 1;
        return static_cast<unsigned char*>(block) + 0x10;
    }

    block = unk98->allocate(uiAlignedSize);

    if (block != 0)
    {
        *static_cast<int*>(block) = 0;
        return static_cast<unsigned char*>(block) + 0x10;
    }

    return 0;
}

struct Heap
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void V28(void* apBlock, unsigned int auiSize);
};

// @fnv 0x00dd8750
// src: HAVOK_LIB 0x00dd8750
void hkLargeBlockAllocator::criticalFree(void* apBlock, unsigned int auiSize)
{
    int iCount = *(int*)((char*)apBlock - 0x10);
    switch (iCount)
    {
    case 0:
        m_pHeap->V28((char*)apBlock - 0x10, (auiSize + 0x1f) & 0xfffffff0);
        break;
    case 1:
        Free((char*)apBlock - 0x10);
        break;
    }
}

struct FUN_00dd8790_owner
{
    virtual void v00();
    virtual unsigned char* v04(unsigned char* out);
    virtual void v08();
    virtual void v0c();
    virtual void v10(hkLargeBlockAllocator::Page* node, void* data);
};

// @fnv 0x00dd8790
void hkLargeBlockAllocator::PurgeAndSelectBlock()
{
    _makeTopValid();
    hkLargeBlockAllocator::Page* sentinel = &m_a4;
    hkLargeBlockAllocator::Page* n = m_a4.m_next;
    if (n != sentinel)
    {
        do
        {
            hkLargeBlockAllocator::Chunk* h = n->m_10;
            unsigned int uSize = h->head;
            if ((((unsigned char)(uSize >> 1)) & 1) == 0 && (char*)h + (uSize & 0xfffffffcu) == (char*)n->m_14 - 0x10)
            {
                hkLargeBlockAllocator::Page* nx = n->m_next;
                n->m_pSecondNode->m_next = nx;
                n->m_next->m_pSecondNode = n->m_pSecondNode;
                if (h == m_fMinimumV)
                {
                    m_fMinimumV = (hkLargeBlockAllocator::Chunk*)&m_9c;
                    m_14 = 0;
                }
                else
                {
                    RemoveNode(h);
                }
                ((FUN_00dd8790_owner*)m_provider)->v10(n, n->m_0c);
                n = nx;
            }
            else
            {
                n = n->m_next;
            }
        } while (n != sentinel);
    }
    if (m_a4.m_next == sentinel)
    {
        m_fMinimumV = (hkLargeBlockAllocator::Chunk*)&m_9c;
        m_14 = 0;
        return;
    }
    unsigned char b;
    unsigned char* flag = ((FUN_00dd8790_owner*)m_provider)->v04(&b);
    if (*flag != 0)
    {
        if (m_14 < 0x8000)
        {
            return;
        }
        hkLargeBlockAllocator::Page* head = m_a4.m_next;
        ResizeSegment(&b, (unsigned int)m_fMinimumV - (unsigned int)head->m_10 + 0x120);
        return;
    }
    hkLargeBlockAllocator::Chunk* cur = m_fMinimumV;
    if (cur != (hkLargeBlockAllocator::Chunk*)&m_9c)
    {
        InsertChunk(cur, m_14);
        m_fMinimumV = (hkLargeBlockAllocator::Chunk*)&m_9c;
        m_14 = 0;
    }
    n = m_a4.m_next;
    hkLargeBlockAllocator::Chunk* best = 0;
    if (n != sentinel)
    {
        do
        {
            hkLargeBlockAllocator::Chunk* h = (hkLargeBlockAllocator::Chunk*)((char*)n->m_14 - 0x10);
            if ((h->head & 1) == 0)
            {
                h = (hkLargeBlockAllocator::Chunk*)((char*)h - h->m_uiPreviousChunkSize);
                if (best == 0 || (h->head & 0xfffffffcu) > (best->head & 0xfffffffcu))
                {
                    best = h;
                }
            }
            n = n->m_next;
        } while (n != sentinel);
    }
    if (best != 0)
    {
        RemoveNode(best);
        m_fMinimumV = best;
        m_14 = best->head & 0xfffffffcu;
        return;
    }
    m_fMinimumV = (hkLargeBlockAllocator::Chunk*)&m_9c;
    m_14 = 0;
}

// Checks that mem is 16-byte aligned, its header flag is set, and the chunk lies in a listed page's chunk chain; writes the result to result.
// @fnv 0x00dd8910
bool* hkLargeBlockAllocator::IsChunkInPageList(bool* result, char* mem)
{
    unsigned int addr = (unsigned int)mem;
    if ((addr & 0xf) != 0)
    {
        *result = false;
        return result;
    }
    char* chunk = mem - 16;
    unsigned int head = *(unsigned int*)(chunk + 4);
    unsigned char flag = (unsigned char)(head >> 1);
    if ((flag & 1) == 0)
    {
        *result = false;
        return result;
    }
    hkLargeBlockAllocator::Page* page = m_kPage.next;
    hkLargeBlockAllocator::Page* sentinel = &m_kPage;
    unsigned int start = 0;
    unsigned int end = 0;
    if (page == sentinel)
    {
        goto fail;
    }
    for (;;)
    {
        start = page->start;
        end = page->end;
        if (addr >= start && addr < end)
        {
            break;
        }
        page = page->next;
        if (page == sentinel)
        {
            goto fail;
        }
    }
    char* last = (char*)end - 16;
    char* c = (char*)start;
    if (c == last)
    {
        goto fail;
    }
    do
    {
        if (c == chunk)
        {
            goto ok;
        }
        c += (*(unsigned int*)(c + 4)) & ~3u;
    } while (c != last);
fail:
    *result = false;
    return result;
ok:
    *result = true;
    return result;
}

// @fnv 0x00dd8b20
// src: HAVOK_LIB 0x00dd8b20
hkLargeBlockAllocator::PageRange hkLargeBlockAllocator::getIterator()
{
    hkLargeBlockAllocator::PageRange r;
    m10->head = m14 | 1;
    hkLargeBlockAllocator::Page* n = ma8;
    if (n == (hkLargeBlockAllocator::Page*)&m_a4)
    {
        r.key = 0;
        return r;
    }
    r.key = n->key;
    r.node = n;
    r.size = n->size - 0x10;
    return r;
}

// @fnv 0x00dd8df0
// src: GUESS 0x00dd8df0 (confidence: low)
hkLargeBlockAllocator* hkLargeBlockAllocator::EvaluateValue_00dd8df0(int arg)
{
    ProcessEntries_00dd7ec0();
    return this;
}

struct SpanSegment
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_kRayEnd;
    unsigned int unk10;
    unsigned int m_iElementCount;
};

struct SpanServer
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual unsigned char* resize(unsigned int* sizePtr, SpanSegment* seg, unsigned int end, unsigned int size,
                                  unsigned int* newEnd);
};

// @fnv 0x00dd8400
hkBool hkLargeBlockAllocator::ResizeSegment(unsigned int size)
{
    SpanSegment* seg = (SpanSegment*)m_seg;
    unsigned int slot;
    unsigned char* result = m_pServer->resize(&size, seg, seg->m_kRayEnd, size, &slot);
    if (*result == 0)
    {
        return hkBool(false);
    }
    unsigned int header = *(unsigned int*)(m_base + m_uiChunkSize + 4) & 0xfffffffcu;
    unsigned int delta = slot - seg->m_kRayEnd;
    delta &= 0xfffffff0u;
    unsigned int newEnd = slot;
    m_uiChunkSize = m_uiChunkSize + delta;
    seg->m_iElementCount = seg->m_iElementCount + delta;
    seg->m_kRayEnd = newEnd;
    *(unsigned int*)(m_base + m_uiChunkSize + 4) = (header - delta) | 2u;
    return hkBool(true);
}

struct AllocatorListener
{
    virtual void v00() = 0;
    virtual void v04(unsigned int size) = 0;
    virtual void v08(unsigned int size) = 0;
};

struct MemoryProvider
{
    virtual void v00() = 0;
    virtual hkBool canExtend() = 0;
    virtual unsigned int v08(unsigned int sizeNeeded) = 0;
    virtual hkLargeBlockAllocator::Page* v0c(unsigned int size, unsigned int* actualSize) = 0;
};

inline char* alignUp(char* p)
{
    return (char*)(((int)p + 15) & -16);
}

inline void alignEnd(char*& p)
{
    *(unsigned int*)&p &= ~15;
}

// Rounds the requested size, tries allocation, then may extend the segment or request a page before allocating.
// @fnv 0x00dd84c0
// src: HAVOK_LIB 0x00dd84c0
void* hkLargeBlockAllocator::alloc_00dd84c0(unsigned int size)
{
    unsigned int uiAlignedSize;
    uiAlignedSize = (size + 31) & ~15;
    if (uiAlignedSize < 256)
    {
        uiAlignedSize = 256;
    }

    void* pAllocated;
    pAllocated = this->Allocate(uiAlignedSize);
    if (pAllocated)
    {
        return pAllocated;
    }

    if (this->m_provider->canExtend().m_cBooleanValue)
    {
        hkLargeBlockAllocator::Page* pNextPage;
        pNextPage = this->m_kPage.m_next;
        if (pNextPage != &this->m_kPage)
        {
            if (this->ResizeSegment(pNextPage->unkC + uiAlignedSize).m_cBooleanValue)
            {
                return this->AllocateBlock(uiAlignedSize);
            }
            if (this->m_kListener)
            {
                this->m_kListener->v04(uiAlignedSize);
                void* prev;
                prev = this->Allocate(uiAlignedSize);
                if (prev)
                {
                    return prev;
                }
                if (this->ResizeSegment(uiAlignedSize + pNextPage->unkC).m_cBooleanValue)
                {
                    return this->AllocateBlock(uiAlignedSize);
                }
                this->m_kListener->v08(uiAlignedSize);
            }
            return 0;
        }
    }

    hkLargeBlockAllocator::Page* pNewPage;
    int i;
    i = uiAlignedSize + 0x138;
    unsigned int start;
    start = this->m_provider->v08(i);
    pNewPage = this->m_provider->v0c(start, &start);
    if (!pNewPage)
    {
        if (this->m_kListener)
        {
            this->m_kListener->v04(uiAlignedSize);
            void* prev;
            prev = this->Allocate(uiAlignedSize);
            if (prev)
            {
                return prev;
            }
            start = this->m_provider->v08(i);
            pNewPage = this->m_provider->v0c(start, &start);
            if (!pNewPage)
            {
                this->m_kListener->v08(uiAlignedSize);
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }

    char* kIter = (char*)pNewPage + 0x18;
    pNewPage->unk08 = 0;
    pNewPage->unkC = start;
    pNewPage->m_kRayStart = kIter;
    kIter = alignUp(kIter);
    pNewPage->m_kRayEnd = (char*)pNewPage + start;
    pNewPage->m_kRayStart = kIter;
    *(unsigned int*)&pNewPage->m_kRayEnd &= ~15u;

    hkLargeBlockAllocator::Page* q;
    q = this->m_kPage.m_next;
    while (q != &this->m_kPage && q < pNewPage)
    {
        q = q->m_next;
    }
    pNewPage->m_next = q;
    hkLargeBlockAllocator::Page* pPrev;
    pPrev = q->m_pSecondNode;
    pNewPage->m_pSecondNode = pPrev;
    pPrev->m_next = pNewPage;
    q->m_pSecondNode = pNewPage;

    if (this->m_fMinimumV != (hkLargeBlockAllocator::Chunk*)&this->m_9c)
    {
        this->_makeTopValid();
        this->InsertChunk(this->m_fMinimumV, this->m_fMinimumV->head & ~3);
    }

    this->m_uiChunkSize = (pNewPage->m_kRayEnd - pNewPage->m_kRayStart) - 0x10;
    this->m_fMinimumV = (hkLargeBlockAllocator::Chunk*)pNewPage->m_kRayStart;
    this->_makeTopValid();

    hkLargeBlockAllocator::Chunk* endChunk;
    endChunk = (hkLargeBlockAllocator::Chunk*)(pNewPage->m_kRayEnd - 0x10);
    endChunk->head = 2;
    if (pNewPage->m_next != &this->m_kPage)
    {
        endChunk->head = (pNewPage->m_next->m_kRayStart - (char*)endChunk) | 2;
    }

    hkLargeBlockAllocator::Page* c;
    c = pNewPage->m_pSecondNode;
    if (c != &this->m_kPage)
    {
        hkLargeBlockAllocator::Chunk* pPrevChunk;
        pPrevChunk = (hkLargeBlockAllocator::Chunk*)(c->m_kRayEnd - 0x10);
        pPrevChunk->head = ((char*)this->m_fMinimumV - (char*)pPrevChunk) | (pPrevChunk->head & 3);
    }

    return this->AllocateBlock(uiAlignedSize);
}

int __cdecl hkLargeBlockAllocator__computeTreeIndex(unsigned int size);
int __cdecl hkLargeBlockAllocator__bitToIndex(unsigned int bit);

// Finds the best-fit free chunk for nb bytes, splits it if the remainder is large enough, and returns a pointer to the allocated block.
// @fnv 0x00dd8180
// src: HAVOK_LIB 0x00dd8180
void* hkLargeBlockAllocator::_allocLarge(unsigned int uiSize)
{
    hkLargeBlockAllocator::TreeChunk* t;
    hkLargeBlockAllocator::TreeChunk* pBest = 0;
    unsigned long uiRemainder = 0 - uiSize;
    int idx = 0;
    idx = hkLargeBlockAllocator__computeTreeIndex(uiSize);
    t = bins[idx];
    if (t != 0)
    {
        unsigned int sizebits = uiSize << ((idx == 31) ? 0 : (25 - (idx >> 1)));
        hkLargeBlockAllocator::TreeChunk* pRight = 0;
        for (;;)
        {
            unsigned int trem = (t->head & 0xfffffffc) - uiSize;
            if (trem < uiRemainder)
            {
                pBest = t;
                uiRemainder = trem;
                if (uiRemainder == 0)
                    break;
            }
            hkLargeBlockAllocator::TreeChunk* right = t->child[1];
            t = (t->child)[(sizebits >> 31) & 1];
            if (right != 0 && right != t)
                pRight = right;
            if (t == 0)
            {
                t = pRight;
                break;
            }
            sizebits <<= 1;
        }
    }
    if (t == 0 && pBest == 0)
    {
        unsigned int leftbit = (1u << idx) << 1;
        unsigned int leftbits = (leftbit | (0 - leftbit)) & treemap;
        if (leftbits != 0)
        {
            unsigned int leastbit = leftbits & (0 - leftbits);
            t = bins[hkLargeBlockAllocator__bitToIndex(leastbit)];
        }
    }
    while (t != 0)
    {
        unsigned int trem = (t->head & 0xfffffffc) - uiSize;
        if (trem < uiRemainder)
        {
            uiRemainder = trem;
            pBest = t;
        }
        t = t->child[0] ? t->child[0] : t->child[1];
    }
    if (pBest == 0)
        return 0;
    hkLargeBlockAllocator::TreeChunk* pRemainder = (hkLargeBlockAllocator::TreeChunk*)((char*)pBest + uiSize);
    RemoveNode(pBest);
    if (uiRemainder < 0x100)
    {
        unsigned int total = uiRemainder + uiSize;
        pBest->head = total | 3;
        hkLargeBlockAllocator::TreeChunk* nx = (hkLargeBlockAllocator::TreeChunk*)((char*)pBest + total);
        nx->head |= 1;
        footprint += uiRemainder + uiSize;
        used += uiRemainder + uiSize - 0x10;
    }
    else
    {
        pBest->head = uiSize | 3;
        footprint += uiSize;
        used += uiSize - 0x10;
        pRemainder->head = uiRemainder | 1;
        *(unsigned int*)((char*)pRemainder + uiRemainder) = uiRemainder;
        InsertChunk((Chunk*)pRemainder, uiRemainder);
    }
    return (char*)pBest + 0x10;
}

inline hkLargeBlockAllocator::~hkLargeBlockAllocator()
{
    *(int**)this = &DAT_010d7c10;
}

// Scalar deleting destructor entry: the shared destructor is nonvirtual.
// @fnv 0x00dd7de0
void* __fastcall deleteLargeBlockAllocator(hkLargeBlockAllocator* allocator, void*, unsigned int flags)
{
    allocator->~hkLargeBlockAllocator();
    if (flags & 1)
        ::operator delete(allocator);
    return allocator;
}

namespace fnv_00dd7e00 {
// FUN_00dd7e00: fast 2*log2-style bit scan of (x >> 8).

// Shifts and tests bits of x, returning 0, 0x1f, or a value computed from the shifted bits.
// @fnv 0x00dd7e00
// src: HAVOK_LIB 0x00dd7e00
unsigned int __cdecl hkLargeBlockAllocator__computeTreeIndex(unsigned int x)
{
    unsigned int hi = x >> 8;
    if (hi == 0)
    {
        return 0;
    }
    if (hi > 0xffff)
    {
        return 0x1f;
    }
    unsigned int a = ((hi - 0x100) >> 16) & 8;
    unsigned int e = hi << a;
    a += ((e - 0x1000) >> 16) & 4;
    e = e << ((e - 0x1000) >> 16 & 4);
    unsigned int c = ((e - 0x4000) >> 16) & 2;
    e = e << c;
    int r = (int)(e >> 15) - (int)c - (int)a + 0xe;
    return (unsigned int)(2 * r) + ((x >> (r + 7)) & 1);
}
}  // namespace fnv_00dd7e00
