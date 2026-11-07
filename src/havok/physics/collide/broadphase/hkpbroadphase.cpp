// src/havok/physics/collide/broadphase/hkpbroadphase.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/broadphase/hkpbroadphase.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern char DAT_010d3f7c[];

struct SpawnedObject
{
    unsigned int m_i00;
    unsigned short m_w04;
    void Init();
};

struct InitObject
{
    void* m_pGlobal;
    unsigned short unk04;
    unsigned short m_w06;
    SpawnedObject m_sub;
    unsigned int m_i10;
    InitObject* hkpBroadPhase_hkpBroadPhase();
};

// @fnv 0x00d97010
// src: HAVOK_LIB 0x00d97010
InitObject* InitObject::hkpBroadPhase_hkpBroadPhase()
{
    m_w06 = 1;
    m_pGlobal = DAT_010d3f7c;
    SpawnedObject* pSubObject = &m_sub;
    pSubObject->m_i00 = 0xfffffff1u;
    pSubObject->m_w04 = 0x8000;
    m_i10 = 0;
    pSubObject->Init();
    return this;
}

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* apSection);

struct FUN_00d97060_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_pSection;

    void hkpBroadPhase_unlockImplementation();
};

// @fnv 0x00d97060
// src: XBOX_PDB 0x00d97060
void FUN_00d97060_cls::hkpBroadPhase_unlockImplementation()
{
    LeaveCriticalSection(m_pSection);
}

// FUN_00d97070: thiscall, one stack parameter, /MT /O2 /GS /EHsc /Gy

struct SubObj
{
    unsigned int unk00;
    unsigned int unk04;
    void Reset();
};

class Spawned
{
  public:
    virtual void v00();
    Spawned* Init(void* a1);
};

class Obj
{
  public:
    virtual void v00();
    virtual Spawned* v04(unsigned int size);
};

struct Holder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    Obj* m_10;
};

Holder* hkMemoryRouter_getInstance();

class Owner
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    SubObj m_08;
    Spawned* m_10;
    void hkpBroadPhase_enableMultiThreading(void* a1);
};

// @fnv 0x00d97070
// src: HAVOK_LIB 0x00d97070
void Owner::hkpBroadPhase_enableMultiThreading(void* apArg)
{
    if (m_10 == 0)
    {
        Holder* h = hkMemoryRouter_getInstance();
        Obj* obj = h->m_10;
        Spawned* s = obj->v04(0x18);
        m_10 = (s != 0) ? s->Init(apArg) : s;
        m_08.Reset();
    }
}

namespace fnv_00d97100 {
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
    void UpdateFields_00d970c0();
    CpuObject* FUN_00d97100(unsigned int flags);
};
// Calls FUN_00d970c0, then if bit 0 of flags is set, invokes the allocator from FUN_00c85750 on this with size, and returns this.
// @fnv 0x00d97100
CpuObject* CpuObject::FUN_00d97100(unsigned int flags)
{
    UpdateFields_00d970c0();
    if (flags & 1)
    {
        CpuAllocatorHolder* holder = hkMemoryRouter_getInstance();
        holder->allocator->Invoke(this, size);
    }
    return this;
}
}  // namespace fnv_00d97100

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* apSection);

struct FUN_00d97050_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_pSection;

    void hkpBroadPhase_lockImplementation();
};

// @fnv 0x00d97050
// src: XBOX_PDB 0x00d97050
void FUN_00d97050_cls::hkpBroadPhase_lockImplementation()
{
    EnterCriticalSection(m_pSection);
}

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void* apSection);
extern char DAT_0102e388[];

struct FUN_00d970c0_cls
{
    int m_vptr;
    int unk04;
    int unk08;
    int unk0c;
    void* m_pCs;

    void UpdateFields_00d970c0();
};

struct FreeAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
};

// Deletes the critical section m_pCs, frees it via the holder's allocator, clears m_pCs, and sets the vtable pointer to DAT_0102e388.
// @fnv 0x00d970c0
// src: GUESS 0x00d970c0 (confidence: low)
void FUN_00d970c0_cls::UpdateFields_00d970c0()
{
    m_vptr = (int)&DAT_010d3f7c;
    void* pCs = m_pCs;
    if (pCs != 0)
    {
        DeleteCriticalSection(pCs);
        Holder* pHolder = hkMemoryRouter_getInstance();
        FreeAllocator* pAllocator = reinterpret_cast<FreeAllocator*>(pHolder->m_10);
        pAllocator->Free(pCs, 0x18);
        m_pCs = 0;
    }
    m_vptr = (int)&DAT_0102e388;
}
