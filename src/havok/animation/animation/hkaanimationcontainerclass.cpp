
// src/havok/animation/animation/hkaanimationcontainerclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/hkaanimationcontainerclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    CpuAllocator* allocator;
};
CpuAllocatorHolder* __cdecl hkMemoryRouter_getInstance();
struct CpuObject
{
    unsigned int unk00;
    unsigned short size;
    void ReleaseAllBucketsAndReset();
    CpuObject* FUN_00dfe940(unsigned int flags);
};
// Calls ReleaseAllBucketsAndReset, then if flags has bit 0 set, invokes the allocator from FUN_00c85750 on this with size, and returns this.
// @fnv 0x00dfe940
CpuObject* CpuObject::FUN_00dfe940(unsigned int flags)
{
    ReleaseAllBucketsAndReset();
    if (flags & 1)
    {
        CpuAllocatorHolder* holder = hkMemoryRouter_getInstance();
        holder->allocator->Invoke(this, size);
    }
    return this;
}

struct CpuItem
{
    void FUN_00c905b0();
};

struct CpuAllocatorSlots
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void Invoke(void* block, unsigned int size);
};

struct CpuBucket
{
    CpuItem** items;
    int count;
    unsigned int cap;
};

struct CpuBody
{
    unsigned int unk00;
    unsigned int unk04;
    CpuBucket buckets[5];
};

struct CpuVtableHolder
{
    CpuVtableHolder()
    {}
    virtual void Vf();
    void* operator new(unsigned int, void* p)
    {
        __assume(p != 0);
        return p;
    }
};

__forceinline static void ReleaseBucket(CpuBucket& b)
{
    CpuAllocatorSlots* alloc = reinterpret_cast<CpuAllocatorSlots*>(hkMemoryRouter_getInstance()->allocator);
    CpuItem** items = b.items;
    int n = b.count;
    for (int i = 0; i < n; ++i)
    {
        CpuItem* p = items[i];
        if (p != 0)
        {
            p->FUN_00c905b0();
        }
        items[i] = 0;
    }
    b.count = 0;
    unsigned int cap = b.cap;
    if (((int)cap >> 31) == 0)
    {
        alloc->Invoke(b.items, (cap & 0x3fffffff) * 4);
    }
    b.items = 0;
    b.cap = 0x80000000;
}

// Releases buckets 4 through 0 via ReleaseBucket, then placement-constructs a CpuVtableHolder over this.
// @fnv 0x00dfe720
void CpuObject::ReleaseAllBucketsAndReset()
{
    CpuBody* self = reinterpret_cast<CpuBody*>(this);
    ReleaseBucket(self->buckets[4]);
    ReleaseBucket(self->buckets[3]);
    ReleaseBucket(self->buckets[2]);
    ReleaseBucket(self->buckets[1]);
    ReleaseBucket(self->buckets[0]);
    new (static_cast<void*>(this)) CpuVtableHolder();
}
