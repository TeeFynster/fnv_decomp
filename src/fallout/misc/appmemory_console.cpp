
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/MemoryManager.h"

void* __cdecl operator new(unsigned);
void* __cdecl operator new[](unsigned);
void* __cdecl ourMemset(void*, int, unsigned);
struct Heap
{
    virtual void method0();
};
struct Block
{
    unsigned offset;
    void* memory;
};
struct Bin
{
    int count;
    Block* first;
};
struct Critical
{
    void* debugInfo;
    int lockCount, recursionCount;
    void* owningThread;
    void* semaphore;
    unsigned spinCount;
};
struct FUN_00aa78a0 : Heap
{
    const char* name;
    int alignment, blockHeaderSize;
    unsigned pageSize, reserveSize, commitSize, currentCommit;
    int used, allocations, unk28, unk2C;
    void* base;
    int unk34, unk38, unk3C, unk40;
    Block blocks[1024];
    Block* freeBlock;
    int unk2048, unk204C, allocatedBlocks, freeBlocks;
    Bin bins[16];
    Critical lock;
    bool flag, initialized;
    unsigned short unk20F2;
    FUN_00aa78a0(unsigned, unsigned, const char*, bool);
};
struct FUN_00aa7400 : Heap
{
    int unk4;
    int unk8;
    int unkC;
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
    FUN_00aa7400(unsigned, const char*);
};
extern char DAT_010824fc, DAT_010824f0, DAT_010824e4;
// Clears the context heap array, allocates three heaps, assigns them to context slots, and resets the physical heap count.
// @fnv 0x00866e00
void MemoryManager::InitializeHeaps()
{
    ourMemset(pHeapsByContextA, 0, 0x108);
    iNumHeaps = 3;
    ppHeaps = new IMemoryHeap*[iNumHeaps];
    ppHeaps[0] = reinterpret_cast<IMemoryHeap*>(new FUN_00aa78a0(0xc800000, 0x5500000, &DAT_010824fc, false));
    pHeapsByContextA[65] = ppHeaps[0];
    ppHeaps[1] = reinterpret_cast<IMemoryHeap*>(new FUN_00aa7400(0x183800, &DAT_010824f0));
    pHeapsByContextA[0] = ppHeaps[1];
    pHeapsByContextA[9] = ppHeaps[1];
    pHeapsByContextA[3] = ppHeaps[1];
    ppHeaps[2] = reinterpret_cast<IMemoryHeap*>(new FUN_00aa78a0(0x4000000, 0x200000, &DAT_010824e4, false));
    pHeapsByContextA[23] = ppHeaps[2];
    iNumPhysicalHeaps = 0;
}
