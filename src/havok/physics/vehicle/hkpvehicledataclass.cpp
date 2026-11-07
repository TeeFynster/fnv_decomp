
// src/havok/physics/vehicle/hkpvehicledataclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/hkpvehicledataclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct DFC1E0Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct DFC1E0MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    DFC1E0Allocator* m_pStreamAllocator;

    DFC1E0Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" DFC1E0MemoryRouter& __cdecl hkMemoryRouter_getInstance();

struct FUN_00dfc1e0
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    FUN_00dfc1e0();
    virtual ~FUN_00dfc1e0();

    static void operator delete(void* p, unsigned int nbytes)
    {
        FUN_00dfc1e0* b = static_cast<FUN_00dfc1e0*>(p);
        hkMemoryRouter_getInstance().heap().ReleaseBlock(p, b->m_usMemSizeAndFlags);
    }
};

// @fnv 0x00dfc1e0
FUN_00dfc1e0::FUN_00dfc1e0()
{}
