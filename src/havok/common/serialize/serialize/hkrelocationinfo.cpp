#include "../../../../../include/hkArray.h"

// src/havok/common/serialize/serialize/hkrelocationinfo.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/serialize/hkrelocationinfo.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/hkMemoryRouter.h"

hkMemoryRouter* hkMemoryRouter_getInstance();

struct S_00e028e0_Alloc
{
    virtual void unk0();
    virtual void unk4();
    virtual void ReleaseBlock(void* p, int n);
    virtual void unkc();
    virtual void ReturnMemory(void* p, int n);
};
struct S_00e028e0_Base
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    ~S_00e028e0_Base() throw();
};
struct S_00e028e0_Obj : S_00e028e0_Base
{
    void hkStorageStringMap_int_struct_hkContainerHeapAllocator_clear() throw();
    ~S_00e028e0_Obj() throw()
    {
        hkStorageStringMap_int_struct_hkContainerHeapAllocator_clear();
    }
    void operator delete(void* p, unsigned int n)
    {
        reinterpret_cast<S_00e028e0_Alloc*>((&hkMemoryRouter_getInstance()->heap()))->ReleaseBlock(p, n);
    }
};

template <class T, class A> __forceinline hkArray<T, A>::~hkArray()
{
        { S_00e028e0_Alloc& a = *reinterpret_cast<S_00e028e0_Alloc*>((&hkMemoryRouter_getInstance()->heap()));
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            a.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
     }
    
}

struct S_00e028e0_8
{
    int unk0;
    int unk4;
};
struct S_00e028e0_16
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
};

struct FUN_00e028e0
{
    hkArray<S_00e028e0_8> m_a0;
    hkArray<S_00e028e0_16> m_ac;
    hkArray<S_00e028e0_8> m_a18;
    hkArray<S_00e028e0_8> m_a24;
    S_00e028e0_Obj* m_obj;
    ~FUN_00e028e0() throw();
};

// Destructor that deletes the owned m_obj object; the array members are destroyed automatically afterwards.
// @fnv 0x00e028e0
FUN_00e028e0::~FUN_00e028e0() throw()
{
    delete m_obj;
}

struct FUN_00e029d0_cls
{
    unsigned int hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_getIterator();
    unsigned int GetEntry(unsigned int a1);
    unsigned int FindNextUsedSlot(unsigned int a1);
    void SetBoolFromThreshold(unsigned char* apFlag, unsigned int a1);
    unsigned int ClearEntries();

    unsigned int hkStorageStringMap_int_struct_hkContainerHeapAllocator_clear();
};

void CallSwappedArgs(unsigned int a1, int a2);

// Iterates handles from FUN_00d87410, passing each item with the holder's allocator to CallSwappedArgs, then returns ClearEntries().
// @fnv 0x00e029d0
// src: HAVOK_LIB 0x00e029d0
unsigned int FUN_00e029d0_cls::hkStorageStringMap_int_struct_hkContainerHeapAllocator_clear()
{
    unsigned int handle = hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_getIterator();
    {
        unsigned char flag;
        SetBoolFromThreshold(&flag, handle);
        if (flag != 0)
        {
            do
            {
                unsigned int item = GetEntry(handle);
                hkMemoryRouter* pAllocHolder = hkMemoryRouter_getInstance();
                CallSwappedArgs(item, reinterpret_cast<int>((&pAllocHolder->heap())));
                handle = FindNextUsedSlot(handle);
                SetBoolFromThreshold(&flag, handle);
            } while (flag != 0);
        }
    }
    return ClearEntries();
}
