#include "../../../../../include/hkArray.h"

// src/havok/common/scenedata/graph/hkxnodeclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/scenedata/graph/hkxnodeclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Destructor: release every (key, object) entry, free the entry array, then the base part goes.

struct DFD840Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void ReturnMemory(void* p, int numBytes) throw();
};

struct DFD840MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    DFD840Allocator* m_pStreamAllocator;

    DFD840Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" DFD840MemoryRouter& __cdecl DFD840GetMemoryRouter() throw();

class DFD840ReferencedObject
{
  public:
    void removeReference() throw();
};

class DFD840Base
{
  public:
    ~DFD840Base() throw();
    int m_iData;
};

template <class T> struct DFD840RefPtr
{
    T* m_pRetainedObject;
    ~DFD840RefPtr() throw()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        m_pRetainedObject = 0;
    }
};

struct DFD840Entry
{
    DFD840Base m_kControlPoint;
    DFD840RefPtr<DFD840ReferencedObject> m_pReferencedObject;
};

template <class T> __forceinline void DFD840Destruct(T* p, int n)
{
    for (int i = 0; i < n; ++i)
        p[i].~T();
}

template <class T, class A> __forceinline hkArray<T, A>::~hkArray()
{
        DFD840Allocator& alloc = DFD840GetMemoryRouter().heap();
        DFD840Destruct(m_data, m_iElementCount);
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    
}

class FUN_00dfd840 : public DFD840Base
{
  public:
    ~FUN_00dfd840() throw();

    hkArray<DFD840Entry> m_kEntries;
};

// @fnv 0x00dfd840
FUN_00dfd840::~FUN_00dfd840() throw()
{}

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
    void FUN_00e3ed80();
    CpuObject* FUN_00dfd900(unsigned int flags);
};
// @fnv 0x00dfd900
CpuObject* CpuObject::FUN_00dfd900(unsigned int flags)
{
    FUN_00e3ed80();
    if (flags & 1)
    {
        CpuAllocatorHolder* holder = hkMemoryRouter_getInstance();
        holder->allocator->Invoke(this, size);
    }
    return this;
}

namespace fnv_00dfd8d0 {
struct FUN_00dfd8d0_Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct FUN_00dfd8d0_MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    FUN_00dfd8d0_Allocator* m_pStreamAllocator;

    FUN_00dfd8d0_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" FUN_00dfd8d0_MemoryRouter& __cdecl hkMemoryRouter_getInstance();

struct FUN_00dfd8d0
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    FUN_00dfd8d0();
    virtual ~FUN_00dfd8d0();

    static void operator delete(void* p, unsigned int nbytes)
    {
        FUN_00dfd8d0* b = static_cast<FUN_00dfd8d0*>(p);
        hkMemoryRouter_getInstance().heap().ReleaseBlock(p, b->m_usMemSizeAndFlags);
    }
};

// @fnv 0x00dfd8d0
FUN_00dfd8d0::FUN_00dfd8d0()
{}
}  // namespace fnv_00dfd8d0
