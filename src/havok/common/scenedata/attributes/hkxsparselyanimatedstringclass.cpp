#include "../../../../../include/hkArray.h"

// src/havok/common/scenedata/attributes/hkxsparselyanimatedstringclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/scenedata/attributes/hkxsparselyanimatedstringclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct S_00e01900_Allocator
{
    virtual void unk0();
    virtual void unk4();
    virtual void unk8();
    virtual void unkC();
    virtual void ReturnMemory(void* p, int nbytes);
};

struct S_00e01900_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00e01900_Allocator* m_pStreamAllocator;
    static S_00e01900_Router& hkMemoryRouter_getInstance();
    S_00e01900_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

struct S_00e01900_Ref
{
    void* m_ptr;
    void Object_UpdateFields_00cb0c00() throw();
    ~S_00e01900_Ref() throw()
    {
        Object_UpdateFields_00cb0c00();
    }
};

template <class T, class A> __forceinline hkArray<T, A>::~hkArray()
{
        { S_00e01900_Allocator& alloc = S_00e01900_Router::hkMemoryRouter_getInstance().heap();
        T* p = m_data;
        int n = m_iElementCount;
        for (int i = 0; i < n; i++)
        {
            p[i].~T();
        }
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
     }
    
}

struct S_00e01900_Base
{
    short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    virtual ~S_00e01900_Base() throw()
    {}
};

struct __declspec(novtable) FUN_00e01900 : S_00e01900_Base
{
    hkArray<S_00e01900_Ref> m_refs;
    hkArray<int> m_auiHeaderValues;
    ~FUN_00e01900() throw();
};

// @fnv 0x00e01900
FUN_00e01900::~FUN_00e01900() throw()
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
    void FUN_00e01900();
    CpuObject* FUN_00e019a0(unsigned int flags);
};
// Calls FUN_00e01900, then if bit 0 of flags is set, invokes the allocator's virtual method on this with size, and returns this.
// @fnv 0x00e019a0
CpuObject* CpuObject::FUN_00e019a0(unsigned int flags)
{
    FUN_00e01900();
    if (flags & 1)
    {
        CpuAllocatorHolder* holder = hkMemoryRouter_getInstance();
        holder->allocator->Invoke(this, size);
    }
    return this;
}
