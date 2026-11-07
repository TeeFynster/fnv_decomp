#include "../../../../../../include/hkArray.h"

// src/havok/physics/vehicle/brake/default/hkpvehicledefaultbrakeclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/brake/default/hkpvehicledefaultbrakeclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct S_00dfc080_Allocator
{
    virtual void v0();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void* AllocateBufferWithSize(int& reqNumBytes);
    virtual void ReturnMemory(void* p, int numBytes);
};

struct S_00dfc080_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00dfc080_Allocator* m_pStreamAllocator;
    S_00dfc080_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

S_00dfc080_Router* hkMemoryRouter_getInstance();

struct S_00dfc080_RefObj
{
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
    virtual ~S_00dfc080_RefObj() throw()
    {}
    static void operator delete(void* p, size_t)
    {
        S_00dfc080_RefObj* b = static_cast<S_00dfc080_RefObj*>(p);
        hkMemoryRouter_getInstance()->heap().ReleaseBlock(p, b->m_usMemSizeAndFlags);
    }
};

struct S_00dfc080_Elem
{
    int unk0;
    int unk4;
    int unk8;
};

template <class T>
static __forceinline void S_00dfc080_Array__clearAndDeallocate(hkArrayBase<T>& self, S_00dfc080_Allocator& alloc)
{
        self.m_iElementCount = 0;
        if ((self.m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(self.m_data, (self.m_iCapacityState & 0x3fffffff) * sizeof(T));
        self.m_data = 0;
        self.m_iCapacityState = 0x80000000;
    }

template <class T>
static __forceinline void S_00dfc080_Array_destroy(hkArrayBase<T>& self) throw()
{
        S_00dfc080_Array__clearAndDeallocate(self, hkMemoryRouter_getInstance()->heap());
    }

struct S_00dfc080_ArrayPolicy
{
    template <class T>
    static __forceinline void destroy(hkArrayBase<T>& self) { S_00dfc080_Array_destroy(self); }
};

struct __declspec(novtable) S_00dfc080 : S_00dfc080_RefObj
{
    hkArray<S_00dfc080_Elem, S_00dfc080_ArrayPolicy> m_ppData;
    virtual ~S_00dfc080() throw()
    {}
    S_00dfc080* DestroyAndFree(unsigned int flags);
};

// Runs the destructor and, when bit 0 of flags is set, frees the object; returns this.
// @fnv 0x00dfc080
S_00dfc080* S_00dfc080::DestroyAndFree(unsigned int flags)
{
    this->S_00dfc080::~S_00dfc080();
    if (flags & 1)
        operator delete(this, sizeof(S_00dfc080));
    return this;
}


template <class T, class A> __forceinline hkArray<T, A>::~hkArray()
{
    A::destroy(*this);
}
