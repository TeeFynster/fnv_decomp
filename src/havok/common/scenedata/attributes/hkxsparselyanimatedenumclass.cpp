#include "../../../../../include/hkArray.h"
#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkMemoryRouter.h"


template <class Allocator> inline Allocator& heap(hkMemoryRouter* holder)
{
    return *reinterpret_cast<Allocator*>(holder->m_heap);
}

// src/havok/common/scenedata/attributes/hkxsparselyanimatedenumclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/scenedata/attributes/hkxsparselyanimatedenumclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct S_00dfdb90_Allocator
{
    virtual ~S_00dfdb90_Allocator();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
    virtual void ReturnMemory(void* p, int numBytes);
};
hkMemoryRouter* hkMemoryRouter_getInstance();
template <class T, class A> __forceinline hkArray<T, A>::~hkArray()
{
        { S_00dfdb90_Allocator& alloc = heap<S_00dfdb90_Allocator>(hkMemoryRouter_getInstance());
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
     }
    
}
struct S_00dfdb90_Base
{
    virtual ~S_00dfdb90_Base() throw()
    {}
    int unk04;
};
struct __declspec(novtable) FUN_00dfdb90 : S_00dfdb90_Base
{
    hkArray<int> m_kPointA;
    hkArray<int> m_kPointB;
    virtual ~FUN_00dfdb90() throw();
};
// Destructor for the container: implicitly destroys the two int arrays, which deallocate their buffers through the heap allocator.
// @fnv 0x00dfdb90
FUN_00dfdb90::~FUN_00dfdb90() throw()
{}

namespace fnv_00dfdc10 {
struct Helper
{
    void FUN_00dfdb90();
};
struct Owner
{
    int unk00;
    unsigned short unk04;
    unsigned short unk06;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    Owner* DestroyOwner(unsigned int flags);
};
extern hkMemoryRouter* hkMemoryRouter_getInstance();
// Calls FUN_00dfdb90 on this, and if flags has bit 0 set, frees this through the holder's heap using unk04; returns this.
// @fnv 0x00dfdc10
Owner* Owner::DestroyOwner(unsigned int flags)
{
    ((Helper*)this)->FUN_00dfdb90();
    if (flags & 1)
    {
        hkMemoryRouter* holder = hkMemoryRouter_getInstance();
        reinterpret_cast<hkMemoryAllocator*>(holder->m_heap)->blockFree(this, unk04);
    }
    return this;
}
}  // namespace fnv_00dfdc10

namespace fnv_00dfdc40 {
struct S_00dfdc40_Allocator
{
    virtual ~S_00dfdc40_Allocator();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
    virtual void ReturnMemory(void* p, int numBytes);
};
hkMemoryRouter* hkMemoryRouter_getInstance();
template <class T> __forceinline void destruct(T* t, int n)
{
    for (int i = 0; i < n; ++i)
        t[i].~T();
}

struct S_00dfdc40_Str
{
    int unk00;
    ~S_00dfdc40_Str() throw();
};
struct S_00dfdc40_Elem
{
    int unk00;
    S_00dfdc40_Str unk04;
};

} // namespace fnv_00dfdc40
template<> __forceinline hkArray<fnv_00dfdc40::S_00dfdc40_Elem>::~hkArray()
{
    using namespace fnv_00dfdc40;

        { S_00dfdc40_Allocator& alloc = heap<S_00dfdc40_Allocator>(fnv_00dfdc40::hkMemoryRouter_getInstance());
        destruct(m_data, m_iElementCount);
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(fnv_00dfdc40::S_00dfdc40_Elem));
        m_data = 0;
        m_iCapacityState = 0x80000000;
     }
    
}
namespace fnv_00dfdc40 {
struct S_00dfdc40_Base
{
    virtual ~S_00dfdc40_Base() throw()
    {}
    int unk04;
};
struct __declspec(novtable) FUN_00dfdc40 : S_00dfdc40_Base
{
    hkArray<S_00dfdc40_Elem> m_ppData;
    virtual ~FUN_00dfdc40() throw();
};
// Destructor of FUN_00dfdc40; the member array's destructor runs implicitly after this empty body.
// @fnv 0x00dfdc40
FUN_00dfdc40::~FUN_00dfdc40() throw()
{}
}  // namespace fnv_00dfdc40

namespace fnv_00dfdcb0 {
struct Ref
{
    void removeReference();
};
struct Helper
{
    void FUN_00dfdb90();
};
struct Owner
{
    int unk00;
    unsigned short unk04;
    unsigned short unk06;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    Ref* unk20;
    Owner* Destroy(unsigned int flags);
};
extern hkMemoryRouter* hkMemoryRouter_getInstance();
// Releases the reference at unk20, calls FUN_00dfdb90, and if flags bit 0 is set frees this through the holder's heap using unk04.
// @fnv 0x00dfdcb0
Owner* Owner::Destroy(unsigned int flags)
{
    if (unk20)
        unk20->removeReference();
    unk20 = 0;
    ((Helper*)this)->FUN_00dfdb90();
    if (flags & 1)
    {
        hkMemoryRouter* holder = hkMemoryRouter_getInstance();
        reinterpret_cast<hkMemoryAllocator*>(holder->m_heap)->blockFree(this, unk04);
    }
    return this;
}
}  // namespace fnv_00dfdcb0

namespace fnv_00dfdcf0 {

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

struct FUN_00dfdcf0_cls
{
    int unk00;
    unsigned short m_uSize;
    unsigned short m_u06;

    void FUN_00dfdc40();

    FUN_00dfdcf0_cls* FUN_00dfdcf0(unsigned char acFlags);
    static void operator delete(void* apMemory) throw();
};

// Calls FUN_00dfdc40, and if acFlags has bit 0 set, frees this via the hkMemoryAllocator from FUN_00c85750, then returns this.
// @fnv 0x00dfdcf0
FUN_00dfdcf0_cls* FUN_00dfdcf0_cls::FUN_00dfdcf0(unsigned char acFlags)
{
    FUN_00dfdc40();
    if (acFlags & 1)
    {
        hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
        pAllocator->blockFree(this, m_uSize);
    }
    return this;
}
}  // namespace fnv_00dfdcf0
