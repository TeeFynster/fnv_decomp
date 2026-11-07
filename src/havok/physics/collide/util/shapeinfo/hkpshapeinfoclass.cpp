
// src/havok/physics/collide/util/shapeinfo/hkpshapeinfoclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/util/shapeinfo/hkpshapeinfoclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00e008e0_Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct FUN_00e008e0_MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    FUN_00e008e0_Allocator* m_pStreamAllocator;

    FUN_00e008e0_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" FUN_00e008e0_MemoryRouter& __cdecl hkMemoryRouter_getInstance();

struct FUN_00e008e0
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    FUN_00e008e0();
    virtual ~FUN_00e008e0();

    static void operator delete(void* p, unsigned int nbytes)
    {
        FUN_00e008e0* b = static_cast<FUN_00e008e0*>(p);
        hkMemoryRouter_getInstance().heap().ReleaseBlock(p, b->m_usMemSizeAndFlags);
    }
};

// Empty default constructor of a class with a vtable, m_usMemSizeAndFlags and m_sReferenceCount, and an operator delete that releases through the heap.
// @fnv 0x00e008e0
FUN_00e008e0::FUN_00e008e0()
{}
