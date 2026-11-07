
// src/havok/common/internal/kdtree/hkkdtree.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/kdtree/hkkdtree.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/hkArray.h"

struct Entry
{
    unsigned short unk00;
    unsigned short unk02;
    unsigned short unk04;
    unsigned short unk06;
    unsigned short unk08;
    unsigned short unk0A;
    unsigned short unk0C;
    unsigned short unk0E;
};
struct FUN_00d97710_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    Entry* entries;
    int count;
    void ClearEntryByKey(int key);
};
// Scans entries for one whose identifier (unk06/unk0E) equals key and, if found, sets its unk00-unk04 words to 0xffff and unk08-unk0C to 0.
// @fnv 0x00d97710
void FUN_00d97710_class::ClearEntryByKey(int key)
{
    int i = 0;
    int n = count;
    if (n > 0)
    {
        Entry* entry = entries;
        do
        {
            union
            {
                int value;
                unsigned short words[2];
            } identifier;
            identifier.words[0] = entry->unk06;
            identifier.words[1] = entry->unk0E;
            if (identifier.value == key)
            {
                entry->unk04 = 0xffff;
                entry->unk02 = 0xffff;
                entry->unk00 = 0xffff;
                entry->unk0C = 0;
                entry->unk0A = 0;
                entry->unk08 = 0;
                return;
            }
            ++i;
            entry = (Entry*)((char*)entry + 0x10);
        } while (i < n);
    }
}

struct DrawParams
{
    int m_i00;
    int m_i04;
    int unk08;
    int m_i0c;
    int m_iArrayLength;
    int unk14;
    int m_i18;
    int m_i1c;
};

void __cdecl MixChannels(void* apTarget, int aiFirst, int aiSecond, int aiThird, int aiCount, int aiFifth,
                         int* apExtra);

// If the count field is positive, forwards the target and the parameter fields to MixChannels.
// @fnv 0x00d9db30
void __cdecl DrawIfCountPositive(void* apTarget, DrawParams* apParams)
{
    if (apParams->m_iArrayLength > 0)
        MixChannels(apTarget, apParams->m_i00, apParams->m_i1c, apParams->m_i04, apParams->m_iArrayLength, apParams->m_i18,
                    &apParams->m_i0c);
}

struct D97770Allocator;

struct D97770MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D97770Allocator* m_pStreamAllocator;

    D97770Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" D97770MemoryRouter& __cdecl hkMemoryRouter_getInstance();
void __cdecl hkArrayUtil__reserve(D97770Allocator* alloc, void* array, int numElements, int sizeElem);

struct D97770Interval
{
    int m_kRayStart;
    int m_data;

    static void* operator new(unsigned int, void* p) throw()
    {
        return p;
    }
    D97770Interval() : m_kRayStart(0x7fffffff), m_data(0)
    {}
};

struct D97770IntervalArrayLocalForm : hkArrayBase<D97770Interval>
{ // local form of hkArrayBase: 0x00d97770 needs the member reserve/construct split; shared specialization with free growth helper differs in 13 bytes of 149. Storage uses the shared base.

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    void reserve(D97770Allocator& alloc, int n)
    {
        const int cap = getCapacity();
        if (cap < n)
        {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayUtil__reserve(&alloc, this, newSize, sizeof(D97770Interval));
        }
    }

    static void construct(D97770Interval* p, int n)
    {
        for (int i = 0; i < n; i++)
            new (p + i) D97770Interval();
    }

    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(hkMemoryRouter_getInstance().heap(), n);
        construct(m_data + m_iElementCount, n - m_iElementCount);
        m_iElementCount = n;
    }

    void hkKdTree_initNodeArray(int minSize);
};

// @fnv 0x00d97770
// src: HAVOK_LIB 0x00d97770
void D97770IntervalArrayLocalForm::hkKdTree_initNodeArray(int minSize)
{
    int n = (minSize > 2) ? minSize : 2;
    if (m_iElementCount < n)
        SetSizeAndGrow(n);
    new (&m_data[0]) D97770Interval();
    m_data[0].m_kRayStart = 0x7fffffff;
    m_data[1].m_kRayStart = 0x7fffffff;
}

struct FUN_00d97770_base
{
    void hkKdTree_initNodeArray(unsigned int aValue);
};

struct FUN_00d97810_cls
{
    volatile unsigned int m_00;
    volatile unsigned int m_04;
    volatile unsigned int m_08;
    volatile unsigned int m_0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    volatile unsigned int m_1c;
    volatile unsigned int m_20;
    volatile unsigned int m_24;

    FUN_00d97810_cls* Initialize(unsigned int aValue);
};

// @fnv 0x00d97810
FUN_00d97810_cls* FUN_00d97810_cls::Initialize(unsigned int aValue)
{
    m_00 = 0;
    m_04 = 0;
    m_08 = 0x80000000u;
    m_0c = 0xffffffffu;
    m_1c = 0;
    m_20 = 0;
    m_24 = 0x80000000u;
    reinterpret_cast<FUN_00d97770_base*>(this)->hkKdTree_initNodeArray(aValue);
    return this;
}

namespace fnv_00d97850 {
struct Allocator
{
    virtual void v00() = 0;
    virtual void v04() = 0;
    virtual void v08() = 0;
    virtual void v0C() = 0;
    virtual void Free(void* p, unsigned int size) = 0;
};

struct Holder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    Allocator* m_pAllocator;
};

Holder* hkMemoryRouter_getInstance();

class FUN_00d97850_cls
{
  public:
    void* m_pData00;
    unsigned int m_nCount04;
    unsigned int m_nFlags08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    void* m_pBuf1C;
    int m_nCount20;
    unsigned int m_nFlags24;

    void ClearBuffers();
};

// Frees the two heap buffers through the global allocator when their flag's high bit is clear, then resets counts, pointers and flags.
// @fnv 0x00d97850
void FUN_00d97850_cls::ClearBuffers()
{
    Holder* pAllocHolder = hkMemoryRouter_getInstance();
    Allocator* alloc = pAllocHolder->m_pAllocator;
    unsigned int flags = m_nFlags24;
    m_nCount20 = 0;
    if ((flags & 0x80000000u) == 0)
    {
        alloc->Free(m_pBuf1C, (flags & 0x3fffffffu) * 16);
    }
    m_pBuf1C = 0;
    m_nFlags24 = 0x80000000u;

    pAllocHolder = hkMemoryRouter_getInstance();
    alloc = pAllocHolder->m_pAllocator;
    flags = m_nFlags08;
    m_nCount04 = 0;
    if ((flags & 0x80000000u) == 0)
    {
        alloc->Free(m_pData00, (flags & 0x3fffffffu) * 8);
    }
    *(volatile unsigned int*)&m_nFlags08 = 0x80000000u;
    *(void* volatile*)&m_pData00 = 0;
}
}  // namespace fnv_00d97850

#include <xmmintrin.h>
extern float DAT_0104da48;
extern float DAT_0104e148;

__declspec(align(16)) struct FUN_00d976d0_cls
{
    int m_00;
    unsigned char m_04;
    unsigned char m_05;
    unsigned short unk06;
    int unk08;
    int unk0c;
    __m128 m_10;
    __m128 m_20;

    void hkKdTreeCinfo_hkKdTreeCinfo();
};
extern "C" void _ReadWriteBarrier(void);
extern "C" void _ReadWriteBarrier(void);
// Sets m_00 to -1, m_04 to 2, and m_05 to 1, then broadcasts the two globals into m_10 and m_20.
// @fnv 0x00d976d0
// src: XBOX_PDB 0x00d976d0
void FUN_00d976d0_cls::hkKdTreeCinfo_hkKdTreeCinfo()
{
    __m128 v = _mm_set1_ps(DAT_0104da48);
    *(volatile int*)&m_00 = -1;
    *(volatile unsigned char*)&m_04 = 2;
    *(volatile unsigned char*)&m_05 = 1;
    _ReadWriteBarrier();
    m_10 = v;
    m_20 = _mm_set1_ps(DAT_0104e148);
}

struct Cinfo_d978
{
    int m_numObjects;
    unsigned char m_numSplits;
    bool m_bExtra;
    unsigned char unk06, unk07;
    int unk08, unk0C;
    __m128 m_kMinimumCorner;
    __m128 m_kMaximumCorner;
};

__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return reinterpret_cast<hkMemoryAllocator&>(hkMemoryRouter_getInstance().heap());
}

// The former array's helper at 0x00c908c0 is hkArrayUtil::_reserve in other units.
template <class T>
__forceinline void hkArrayBase<T>::_setSize(hkMemoryAllocator& heap, int n)
{
    int cap = m_iCapacityState & 0x3fffffff;
    if (cap < n)
    {
        int cap2 = 2 * cap;
        hkArrayUtil::_reserve(heap, this, n < cap2 ? cap2 : n, sizeof(T));
    }
    m_iElementCount = n;
}

struct Node_d978
{
    int a, b, c, d;
};

struct Tree_d978
{
    int unk00, unk04, unk08;
    int m_pTreeNode;
    int m_numObjects;
    int m_iNodeCount;
    int m_numSplits;
    hkArray<Node_d978> m_kNodeCollection;
    int unk28, unk2C;
    __m128 m_kMinimumCorner;
    __m128 m_kMaximumCorner;
    void hkKdTree_initNodeArray(int minSize);
    void hkKdTree_reset(const Cinfo_d978& cinfo);
};

// Copies bounds and object count from cinfo, computes node capacity and per-split size, then allocates the node collection.
// @fnv 0x00d978d0
// src: XBOX_PDB 0x00d978d0
void Tree_d978::hkKdTree_reset(const Cinfo_d978& cinfo)
{
    m_pTreeNode = -1;
    m_kMinimumCorner = cinfo.m_kMinimumCorner;
    m_kMaximumCorner = cinfo.m_kMaximumCorner;
    m_iNodeCount = cinfo.m_bExtra ? 2 * cinfo.m_numObjects + 8 : 2 * cinfo.m_numObjects;
    int numSplits = cinfo.m_numSplits;
    int perSplit = (numSplits == 0) ? 0 : cinfo.m_numObjects / numSplits;
    m_numSplits = perSplit;
    hkKdTree_initNodeArray(m_iNodeCount + perSplit);
    m_numObjects = cinfo.m_numObjects;
    m_kNodeCollection.setSize(m_numObjects);
}
