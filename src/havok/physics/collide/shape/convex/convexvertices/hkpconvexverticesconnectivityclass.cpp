
// src/havok/physics/collide/shape/convex/convexvertices/hkpconvexverticesconnectivityclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/convex/convexvertices/hkpconvexverticesconnectivityclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct E00E40Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct E00E40MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    E00E40Allocator* m_pStreamAllocator;

    E00E40Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" E00E40MemoryRouter& __cdecl hkMemoryRouter_getInstance();

struct FUN_00e00e40
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    FUN_00e00e40();
    virtual ~FUN_00e00e40();

    static void operator delete(void* p, unsigned int nbytes)
    {
        FUN_00e00e40* b = static_cast<FUN_00e00e40*>(p);
        hkMemoryRouter_getInstance().heap().ReleaseBlock(p, b->m_usMemSizeAndFlags);
    }
};

// Constructor with an empty body; the class has a vtable, m_usMemSizeAndFlags and m_sReferenceCount.
// @fnv 0x00e00e40
FUN_00e00e40::FUN_00e00e40()
{}
