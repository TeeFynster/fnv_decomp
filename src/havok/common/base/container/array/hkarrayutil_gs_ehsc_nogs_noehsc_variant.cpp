
// src/havok/common/base/container/array/hkarrayutil_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/common/base/container/array/hkarrayutil.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/base/container/array/hkarrayutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/container/array/hkarrayutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct CB1BC0Allocator;
typedef unsigned __int64 CB1BC0Key;
struct CB1BC0MapOperations
{
    static unsigned hash(CB1BC0Key key, unsigned mod)
    {
        return (unsigned(key) >> 4) * 2654435761U & mod;
    }
    static bool isValid(CB1BC0Key key)
    {
        return key != CB1BC0Key(-1);
    }
    static bool equal(CB1BC0Key key0, CB1BC0Key key1)
    {
        return key0 == key1;
    }
};
struct CB1BC0Pair
{
    CB1BC0Key key;
    CB1BC0Key val;
};
struct CB1BC0Map
{
    CB1BC0Pair* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    void ResizeStorage(CB1BC0Allocator& alloc, int capacity);
    int InsertKeyValue(CB1BC0Allocator& alloc, CB1BC0Key key, CB1BC0Key val);
};
struct SpawnedObject
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual int v03(int* out);
    virtual void v04();
    virtual int v05(int a, int b, int* out);
};
struct SpawnedArray
{
    int m_00;
    int m_04;
    unsigned int m_08;
};
void __cdecl FUN_00ec44d0(int a, int b, int c);
void __cdecl hkArrayUtil__reserve(SpawnedObject* obj, SpawnedArray* arr, int a, int stride);
// ---------------------------------------------------------------------------
// ResizeAudioStream - reserve/grow the element buffer of an audio stream.
//
// The stream keeps the element pointer at +0, the live item count at +4 and
// the capacity (plus two flag bits) at +8.  The allocator is a polymorphic
// object: slot 3 hands out a fresh block, slot 5 resizes an existing one.
// ---------------------------------------------------------------------------
struct AudioStream
{
    void* m_pData;
    int m_iArrayLength;
    int m_uCapacity;
};
#include "../../../../../../include/hkMemoryAllocator.h"
extern "C" void* __cdecl FNV_block_copy(void* dst, const void* src, unsigned int size);
void ResizeAudioStream(hkMemoryAllocator* pAlloc, AudioStream* pStream, int elemSize);
typedef unsigned int hkUlong;
extern void __cdecl hkArrayUtil__reserve(void* alloc, void* arr, int n, int sizeElem);
extern void __cdecl ResizeAudioStream(void* alloc, void* arr, int sizeElem);
inline void* operator new(unsigned int, void* p)
{
    return p;
}
inline void operator delete(void*, void*)
{}
struct S_00da2bd0_Node
{
    hkUlong m_uiFilterValue;
    int m_parent;
    int m_iFirstChild;
    int m_next;

    S_00da2bd0_Node() : m_uiFilterValue(0), m_parent(-1), m_iFirstChild(-1), m_next(-1)
    {}
};
struct S_00da2bd0_CallTree
{
    S_00da2bd0_Node* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    void* m_pThreadAllocator;

    __forceinline void _setSize(void* alloc, int n)
    {
        int cap = m_iCapacityState & 0x3fffffff;
        if (cap < n)
        {
            int cap2 = cap * 2;
            hkArrayUtil__reserve(alloc, this, n < cap2 ? cap2 : n, sizeof(S_00da2bd0_Node));
        }
        int numNew = n - m_iElementCount;
        S_00da2bd0_Node* p = m_data + m_iElementCount;
        for (int i = 0; i < numNew; ++i)
        {
            new (p + i) S_00da2bd0_Node();
        }
        m_iElementCount = n;
    }

    __forceinline S_00da2bd0_Node& AllocatePair()
    {
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
        {
            ResizeAudioStream(m_pThreadAllocator, this, sizeof(S_00da2bd0_Node));
        }
        new (m_data + m_iElementCount) S_00da2bd0_Node();
        return m_data[m_iElementCount++];
    }

    int __thiscall FindOrAddCallTrace(const hkUlong* trace, int depth);
};
struct Holder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    void* m_pAllocator;
};
Holder* __cdecl hkMemoryRouter_getInstance();
void __cdecl hkArrayUtil__reserve(void* pAllocator, void* pBuf, int newCap, int bFlag);
void __cdecl ResizeAudioStream(void* pAllocator, void* pBuf, int bFlag);
extern "C" void _ReadWriteBarrier(void);
struct FUN_00e108b0_cls
{
    char* m_pData;
    int m_len;
    unsigned int m_cap;

    FUN_00e108b0_cls* InitializeStringBuffer();
};
