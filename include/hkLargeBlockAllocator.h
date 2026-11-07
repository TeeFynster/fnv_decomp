#pragma once

#include "hkFreeListAllocatorServer.h"
#include "hkBool.h"

class hkReferencedObject;
class AllocatorListener;
class MemoryProvider;
class SpanServer;
class Heap;
class hkMemoryManager;
struct tchunk;

class hkLargeBlockAllocator : public hkFreeListAllocatorServer
{
public:
    struct Chunk
    {
        unsigned int m_uiPreviousChunkSize;
        unsigned int head;
        Chunk* fd;
        Chunk* bk;

        unsigned int getChunkSize() const;
        bool isPinuse() const;
        bool isCinuse() const;
        bool isInuse() const;
        Chunk* chunkPlusOffset(unsigned int size);
        Chunk* chunkMinusOffset(unsigned int size);
        void setSizeAndPinuseOfFreeChunk(unsigned int size);
        void setFreeWithPinuse(unsigned int size, Chunk* next);
        void* getPayload();
        unsigned int getPayloadSize() const;
        Chunk* nextChunk();
    };

    struct TreeChunk : public Chunk
    {
        TreeChunk* child[2];
        TreeChunk* parent;
        int index;
    };

    struct Page
    {
        Page* m_pSecondNode;
        union { Page* m_next; Page* next; };
        unsigned int unk08;
        union { unsigned int unk0C; int unkC; void* m_0c; };
        union { char* m_kRayStart; Chunk* m_10; unsigned int start; int key; };
        union { char* m_kRayEnd; char* m_14; unsigned int end; int size; int m_iElementCount; };

        Chunk* getFirstChunk();
        Chunk* getFooter();
    };

    struct ListNode
    {
        ListNode* m_next;
        ListNode* m_pSecondNode;
    };

    struct PageRange
    {
        int key;
        Page* node;
        int size;
    };

    typedef void (__cdecl* BlockCallback)(void* start, unsigned int size, void* param);

    virtual hkLargeBlockAllocator* vf00(int arg);
    virtual void* vf01(unsigned int size);
    virtual void Free(void* mem);
    virtual bool* IsChunkInPageList(bool* result, char* mem);
    virtual void* vf04(void* p, void* apUnused);
    virtual int vf05(int* pValues, int iUnused);
    virtual void* vf06(unsigned int size);
    virtual void vf07(void* apBlock, unsigned int auiSize);

    ~hkLargeBlockAllocator();
    void ProcessEntries_00dd7ec0();
    void _init_00dd7f10();
    void ProcessAllItems();
    void _unlinkChunk(Chunk* chunk);
    void _insertChunk(Chunk* chunk, unsigned int size);
    void InsertChunk(Chunk* chunk, unsigned int size);
    void InsertChunk(void* chunk, unsigned int size);
    void InsertChunk(tchunk* chunk, int size);
    void RemoveNode(Chunk* chunk);
    void RemoveNode(TreeChunk* chunk);
    unsigned int GetMaxChunkSize(void* tree, unsigned int size);
    unsigned int findLargestBlockSize();
    void _makeTopValid();
    void* AllocateBlock(int size);
    void* AllocateBlock(unsigned int size);
    int AllocSlow(int size);
    int Allocate(int size);
    void* Allocate(unsigned int size);
    void* AllocateMemoryBlock(int size);
    hkBool ResizeSegment(unsigned int size);
    void ResizeSegment(unsigned char* result, unsigned int size);
    void PurgeAndSelectBlock();
    void ForEachAllocatedBlock(BlockCallback callback, void* param);
    PageRange getIterator();
    void* _allocLarge(unsigned int size);
    void* alloc_00dd84c0(unsigned int size);
    void* criticalAlloc(unsigned int size);
    void criticalFree(void* block, unsigned int size);
    hkLargeBlockAllocator* EvaluateValue_00dd8df0(int arg);

    // Havok 7.1 hkLargeBlockAllocator.h: m_limitedListener 0x04, m_treemap 0x08,
    // m_leastAddr 0x0C, m_top 0x10, m_topsize 0x14, m_treebins[32] 0x18,
    // m_server 0x98, m_zeroChunk 0x9C, m_pages 0xA4, m_sumAllocatedWithMgrOverhead
    // 0xBC, m_sumAllocatedSize 0xC0; sizeof 0xC4.
    union
    {
        struct
        {
            AllocatorListener* m_kListener;
            union
            {
                unsigned int m_freeMask;
                unsigned int m_uiChunkCount;
                unsigned int treemap;
                int m_numAllocated;
                int m_08;
            };
            union { int unk0C; int m_numFree; };
            union
            {
                Chunk* m_fMinimumV;
                Chunk* m10;
                char* m_next;
                unsigned char* m_base;
                unsigned char* m_10;
                void** m_freeListPtr;
            };
            union
            {
                unsigned int m_uiChunkSize;
                unsigned int m14;
                unsigned int m_14;
                int unk14;
                void* m_kFreeListEntries;
            };
            union
            {
                TreeChunk* m_bins[32];
                TreeChunk* bins[32];
                tchunk* m_apChunkLists[32];
                void* m_treeBins[32];
                void* m_buckets[32];
            };
            union
            {
                MemoryProvider* m_provider;
                SpanServer* m_pServer;
                Heap* m_pHeap;
                hkMemoryManager* unk98;
            };
            union { unsigned int unk9C; int m_9c; void* m_freeHead; };
            union { unsigned int unkA0; int m_blockShift; };
            union
            {
                Page m_kPage;
                Page m_a4;
                ListNode m_kBlocks;
                struct
                {
                    unsigned int unkA4;
                    union { Page* m_seg; Page* ma8; };
                    unsigned int unkAC;
                    unsigned int unkB0;
                    unsigned int unkB4;
                    unsigned int unkB8;
                };
            };
            union
            {
                unsigned int m_uiBufferCapacity;
                unsigned int footprint;
                int m_totalBytes;
                int unkBC;
            };
            union
            {
                int m_overhead;
                unsigned int used;
                int m_peakBytes;
                int unkC0;
            };
        };
    };
};

typedef char hkLargeBlockAllocator_check_size[(sizeof(hkLargeBlockAllocator) == 0xC4) ? 1 : -1];
