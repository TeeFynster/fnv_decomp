
// src/havok/physics/dynamics/constraint/atom/hkpconstraintatomutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/atom/hkpconstraintatomutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct D92740Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct D92740MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D92740Allocator* m_pStreamAllocator;

    D92740Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" D92740MemoryRouter& __cdecl hkMemoryRouter_getInstance();

struct D92740Block
{
    unsigned short unk00;
    unsigned short m_sizeClass;
    unsigned short m_iAllocatedCount;
    unsigned short m_pRayCursor;
    unsigned char m_iAgentTypeA;
    unsigned char m_iAgentTypeB;
    unsigned short unk0A;
    unsigned short m_extra;
};

D92740Block* __cdecl AllocateBlock(int capacity, int typeA, int typeB, int extra);
void __cdecl hkpSimpleContactConstraintAtom_ProcessEntries_00d925b0(D92740Block* dst, D92740Block* src);
int __cdecl RoundUpToBucketSize(int sizeClass);

// @fnv 0x00d92740
D92740Block* __cdecl ShrinkBlockIfSparse(D92740Block* block, int numToAdd, bool* pbResized)
{
    if ((block->m_iAllocatedCount + numToAdd) * 2 <= block->m_pRayCursor)
    {
        int newCapacity = block->m_pRayCursor >> 1;
        D92740Block* newBlock = AllocateBlock(newCapacity, block->m_iAgentTypeA, block->m_iAgentTypeB, block->m_extra);
        hkpSimpleContactConstraintAtom_ProcessEntries_00d925b0(newBlock, block);
        int size = RoundUpToBucketSize(block->m_sizeClass);
        hkMemoryRouter_getInstance().heap().ReleaseBlock(block, size);
        *pbResized = true;
        return newBlock;
    }
    return block;
}

// Rounds size up to the next fixed bucket size (16..8192), returning size unchanged when it exceeds 8192.
// @fnv 0x00d92440
int __cdecl RoundUpToBucketSize(int size)
{
    if (size <= 16)
        return 16;
    if (size <= 32)
        return 32;
    if (size <= 48)
        return 48;
    if (size <= 64)
        return 64;
    if (size <= 96)
        return 96;
    if (size <= 128)
        return 128;
    if (size <= 160)
        return 160;
    if (size <= 192)
        return 192;
    if (size <= 256)
        return 256;
    if (size <= 320)
        return 320;
    if (size <= 512)
        return 512;
    if (size <= 640)
        return 640;
    if (size <= 1024)
        return 1024;
    if (size <= 2048)
        return 2048;
    if (size <= 4096)
        return 4096;
    if (size <= 8192)
        return 8192;
    return size;
}

struct MyAlloc
{
    virtual void unk00();
    virtual void* Construct(unsigned int raw);
};

extern "C" D92740MemoryRouter& __cdecl hkMemoryRouter_getInstance();

extern "C" __declspec(noinline) unsigned int __cdecl RoundUpToBucketSize(unsigned int size)
{
    return size;
}

struct Types
{
    unsigned char a;
    unsigned char b;
};

struct Obj
{
    unsigned short f00;
    unsigned short f02;
    unsigned short f04;
    unsigned short f06;
    Types types;
    unsigned char f0A;
    unsigned char unk0B;
    unsigned short f0C;
    unsigned short f0E;
    unsigned short f10;
    unsigned short f12;
    unsigned int f14;
    unsigned int f18;
    unsigned int f1C;
    unsigned int f20;
    unsigned int f24;
    unsigned int f28;
    unsigned int f2C;
};

// @fnv 0x00d92510
D92740Block* __cdecl AllocateBlock(int capacity, int typeA, int typeB, int extra)
{
    unsigned int uiTypeSum = (unsigned int)typeA + (unsigned int)typeB;
    unsigned int stride = uiTypeSum * 4 + 0x14;
    unsigned int size = (unsigned int)capacity * (stride + 0x20);
    size = (size + 0x3f) & 0xfffffff0u;
    D92740MemoryRouter& memoryRouter = hkMemoryRouter_getInstance();
    MyAlloc* alloc = (MyAlloc*)memoryRouter.m_pStreamAllocator;
    unsigned int raw = RoundUpToBucketSize(size);
    Obj* pBlock = (Obj*)alloc->Construct(raw);

    pBlock->types.a = typeA;
    pBlock->types.b = typeB;
    pBlock->f0C = extra;
    pBlock->f02 = size;
    *(volatile unsigned short*)&pBlock->f06 = capacity;
    pBlock->f0A = stride;
    pBlock->f10 = 0;
    pBlock->f12 = 3;
    for (int iIndex = 0; iIndex < 7; ++iIndex)
        ((unsigned int*)&pBlock->f14)[iIndex] = 0;
    pBlock->f00 = 0x16;
    pBlock->f04 = 0;
    return (D92740Block*)pBlock;
}
