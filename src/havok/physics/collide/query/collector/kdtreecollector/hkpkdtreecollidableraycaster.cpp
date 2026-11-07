
// src/havok/physics/collide/query/collector/kdtreecollector/hkpkdtreecollidableraycaster.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/query/collector/kdtreecollector/hkpkdtreecollidableraycaster.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00d97a10_Class
{
    void hkKdTreeCollidableRayBundleCaster_getHitFractions(float* p) const;
};
// @fnv 0x00d97a10
// src: HAVOK_LIB 0x00d97a10
void FUN_00d97a10_Class::hkKdTreeCollidableRayBundleCaster_getHitFractions(float* afOut) const
{
    const float* m = *(const float**)((const char*)this + 0x10);
    afOut[0] = m[0x10 / 4];
    afOut[1] = m[0x70 / 4];
    afOut[2] = m[0xd0 / 4];
    afOut[3] = m[0x130 / 4];
}

struct S_00d979e0_Inner
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    float unk10;
};

struct S_00d979e0
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00d979e0_Inner* unk10;
    float hkpKdTreeCollidableRaycaster_getHitFraction() const;
};

// Returns the float at offset 0x10 of the inner struct pointed to by unk10.
// @fnv 0x00d979e0
// src: HAVOK_SRC 0x00d979e0
float S_00d979e0::hkpKdTreeCollidableRaycaster_getHitFraction() const
{
    return unk10->unk10;
}

struct S_00d98300_Entry
{
    float m_00;
    int m_04;
    int unk08;
    int unk0C;
    int m_10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int m_30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    void reset()
    {
        m_00 = 1.0f;
        m_04 = -1;
        m_30 = 0;
        m_10 = -1;
    }
};
struct S_00d98300
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S_00d98300_Entry m_entries[4];
    void ResetEntries();
};

// Resets all four entries of the array by calling reset() on each.
// @fnv 0x00d98300
void S_00d98300::ResetEntries()
{
    m_entries[0].reset();
    m_entries[1].reset();
    m_entries[2].reset();
    m_entries[3].reset();
}

struct NestedFlagBlock
{
    unsigned long blk_00;  // 0x00
    unsigned long blk_04;  // 0x04
    unsigned long blk_08;  // 0x08
    unsigned long blk_0c;  // 0x0c
    unsigned long blk_10;  // 0x10
    unsigned long blk_14;  // 0x14
    unsigned long blk_18;  // 0x18
    unsigned long blk_1c;  // 0x1c
    unsigned long blk_20;  // 0x20
    unsigned long blk_24;  // 0x24
    unsigned long blk_28;  // 0x28
    unsigned long blk_2c;  // 0x2c
    unsigned long blk_30;  // 0x30
    unsigned long blk_34;  // 0x34
    unsigned long blk_38;  // 0x38
    unsigned long blk_3c;  // 0x3c
    unsigned long blk_40;  // 0x40
    unsigned long blk_44;  // 0x44
    unsigned long blk_48;  // 0x48
    unsigned long blk_4c;  // 0x4c
    unsigned long flag;    // 0x50
};

struct FUN_00d979c0_Class
{
    unsigned long dword_00;   // 0x00
    unsigned long dword_04;   // 0x04
    unsigned long dword_08;   // 0x08
    unsigned long dword_0c;   // 0x0c
    NestedFlagBlock* nested;  // 0x10

    bool* GetFlag(bool* out);
};

// @fnv 0x00d979c0
bool* FUN_00d979c0_Class::GetFlag(bool* pbFlag)
{
    *pbFlag = (nested->flag != 0);
    return pbFlag;
}

struct SpawnedBase
{
    virtual ~SpawnedBase()
    {}
};

struct FUN_00d979f0_cls : SpawnedBase
{
    int m_i04;
    int m_i08;
    int m_i0C;
    int m_i10;

    FUN_00d979f0_cls* ResetFields() throw();
};

// @fnv 0x00d979f0
FUN_00d979f0_cls* FUN_00d979f0_cls::ResetFields() throw()
{
    this->SpawnedBase::~SpawnedBase();
    m_i04 = 0;
    m_i08 = 0;
    m_i0C = 0;
    m_i10 = 0;
    return this;
}

// Scalar deleting destructor of a small polymorphic Havok helper with an empty destructor.

void __cdecl operator delete(void* pvMem);

class FUN_00d979a0
{
// @fnv 0x00d979a0
  public:
    FUN_00d979a0()
    {}
    virtual ~FUN_00d979a0()
    {}

    static void* operator new(unsigned int, void* p)
    {
        return p;
    }
    static void operator delete(void*, void*)
    {}

    int m_iData;
};

// Placement construction so the vtable (and with it the deleting destructor) is emitted.
void* D979A0Make(void* pvMem)
{
    return new (pvMem) FUN_00d979a0;
}

extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);

struct S00d97bf0_Rec
{
    const char* name;
    unsigned int tsc;
    unsigned int unk08;
};

struct S00d97bf0_Pool
{
    void* unk00;
    S00d97bf0_Rec* cur;
    void* unk08;
    S00d97bf0_Rec* end;
};

struct S00d97bf0_Obj;

void __cdecl hkKdTreeUtils_castRayIterative(int* p, int a, int b, int c, S00d97bf0_Obj* d);

struct S00d97bf0_Obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2(int a);

    int m04;
    int m08;
    int m0C;
    int m10;

    int __thiscall hkpKdTreeCollidableRaycaster_castRayIterative(int a0, int a1, int a2, int a3);
};

// Records TtKdTreeCastRayIter and Et timing markers, stores a2 and a3, calls FUN_00d98ca0 and v2, then returns a0.
// @fnv 0x00d97bf0
// src: HAVOK_LIB 0x00d97bf0
int __thiscall S00d97bf0_Obj::hkpKdTreeCollidableRaycaster_castRayIterative(int a0, int a1, int a2, int a3)
{
    extern void* DAT_00fdf044;
    extern unsigned long DAT_0126835c;
    extern const char str_010d406c[];
    extern const char str_010c41f8[];

    typedef S00d97bf0_Pool*(__stdcall * AllocFn)(unsigned long);
    AllocFn alloc = (AllocFn)DAT_00fdf044;

    S00d97bf0_Pool* pool = alloc(DAT_0126835c);
    S00d97bf0_Rec* rec = pool->cur;

    if (rec < pool->end)
    {
        rec->name = "TtKdTreeCastRayIter";
        _ReadWriteBarrier();

        volatile unsigned int ts = (unsigned int)__rdtsc();
        rec->tsc = ts;

        rec++;
        pool->cur = rec;
    }

    m04 = a2;
    m10 = a3;

    hkKdTreeUtils_castRayIterative(&a2, a1, a2, a2 + 0x10, this);

    v2(a0);

    pool = alloc(DAT_0126835c);
    rec = pool->cur;

    if (rec < pool->end)
    {
        rec->name = "Et";
        _ReadWriteBarrier();

        volatile unsigned int* ts = (volatile unsigned int*)&a2;
        *ts = (unsigned int)__rdtsc();
        rec->tsc = *ts;

        rec++;
        pool->cur = rec;
    }

    return a0;
}

struct D98360Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct D98360MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D98360Allocator* m_pStreamAllocator;

    D98360Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" D98360MemoryRouter& __cdecl hkMemoryRouter_getInstance();

struct D98360Base
{
    virtual ~D98360Base()
    {}

    int unk04;
};

struct FUN_00d98360 : D98360Base
{
    int unk08;
    int unk0C;
    int unk10;

    FUN_00d98360();
    virtual ~FUN_00d98360();

    static void operator delete(void* p, unsigned int nbytes)
    {
        hkMemoryRouter_getInstance().heap().ReleaseBlock(p, nbytes);
    }
};

// Empty destructor for the FUN_00d98360 class.
// @fnv 0x00d98360
FUN_00d98360::~FUN_00d98360()
{}

FUN_00d98360::FUN_00d98360()
{}
