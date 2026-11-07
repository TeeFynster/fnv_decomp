#include "../../../../../../include/hkMemoryAllocator.h"

// src/havok/common/base/container/array/hkarrayutil_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/common/base/container/array/hkarrayutil_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


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

#include <xmmintrin.h>

__forceinline __m128 scalar_0f10(const float& v)
{
    return _mm_load_ss(&v);
}
struct FNVVector_0f10
{
    __m128 quad;
};
struct FNVBounds_0f10
{
    FNVVector_0f10 min;
    FNVVector_0f10 max;
};
struct FNVCloud_0f10
{
    FNVVector_0f10* m_pPts;
    int m_uiItemCount;
};

struct FNVScratchAlloc_0f10
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void* AllocBlock(int* pSize);
    virtual void FreeBlock(void* pData, int size);
    template <class T> __forceinline T* allocate(int& count)
    {
        int bytes = count * sizeof(T);
        T* result = (T*)AllocBlock(&bytes);
        count = bytes / (int)sizeof(T);
        return result;
    }
    template <class T> __forceinline void freeArray(T* data, int count)
    {
        FreeBlock(data, count * sizeof(T));
    }
};

struct FNVRouter_0f10
{
    void* temp;
    void* stack;
    void* debug;
    void* solver;
    FNVScratchAlloc_0f10* heap;
};

__forceinline void copy16_0f10(void* dest, const void* source, int bytes)
{
    const unsigned int* s = (const unsigned int*)source;
    unsigned int* d = (unsigned int*)dest;
    int n = bytes >> 4;
    do
    {
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
        d[3] = s[3];
        s += 4;
        d += 4;
    } while (--n > 0);
}

struct __declspec(align(16)) FNVRec_0f10
{
    unsigned int minX;
    unsigned int minY;
    unsigned int minZ;
    unsigned int vertexKey;
    unsigned int maxX;
    unsigned int maxY;
    unsigned int maxZ;
    unsigned int maxExtra;
    void hk1AxisSweep_AabbInt_set(FNVBounds_0f10* box, int i);
    __forceinline void operator=(const FNVRec_0f10& other)
    {
        copy16_0f10(this, &other, sizeof(FNVRec_0f10));
    }
};
void __cdecl SortRecordsByKey(FNVRec_0f10* arr, int n);

// @fnv 0x00da0f10
// src: GUESS 0x00da0f10 (confidence: low)
void __cdecl hkMemoryRouter_getInstance_ProcessEntries_00da0f10(FNVCloud_0f10* cloud, AudioStream* out, AudioStream* idx, float radius)
{
    int n = cloud->m_uiItemCount;
    FNVRouter_0f10* r = (FNVRouter_0f10*)hkMemoryRouter_getInstance();
    FNVScratchAlloc_0f10* alloc = r->heap;
    int cap = idx->m_uCapacity & 0x3fffffff;
    if (cap < n)
    {
        int cap2 = cap * 2;
        hkArrayUtil__reserve(alloc, idx, n < cap2 ? cap2 : n, 4);
    }
    idx->m_iArrayLength = n;

    int scratchCap = n + 4;
    FNVRouter_0f10* router2 = (FNVRouter_0f10*)hkMemoryRouter_getInstance();
    FNVScratchAlloc_0f10* alloc2 = router2->heap;
    FNVRec_0f10* scratch;
    if (scratchCap)
    {
        int bytes = scratchCap * 32;
        FNVRec_0f10* result = (FNVRec_0f10*)alloc2->AllocBlock(&bytes);
        int c = bytes / 32;
        _ReadWriteBarrier();
        scratch = result;
        scratchCap = c;
    }
    else
        scratch = 0;
    if (scratchCap == 0)
        scratchCap = 0x80000000;

    FNVVector_0f10 h;
    float half = radius * 0.5f;
    __m128 halfScalar = _mm_load_ss(&half);
    h.quad = _mm_shuffle_ps(halfScalar, halfScalar, 0);
    unsigned int offset;
    int i = 0;
    if (n > 0)
    {
        offset = 0;
        FNVRec_0f10* sp = scratch;
        do
        {
            FNVBounds_0f10 box;
            __m128 halfQuad = h.quad;
            box.min.quad = _mm_sub_ps(((FNVVector_0f10*)((char*)cloud->m_pPts + offset))->quad, halfQuad);
            box.max.quad = _mm_add_ps(halfQuad, ((FNVVector_0f10*)((char*)cloud->m_pPts + offset))->quad);
            sp->hk1AxisSweep_AabbInt_set(&box, i);
            ++i;
            offset += 16;
            ++sp;
        } while (i < n);
    }

    {
        FNVRec_0f10 sentinel;
        sentinel.minX = 0xffffffff;
        FNVRec_0f10* end = scratch + n;
        copy16_0f10(end, &sentinel, sizeof(FNVRec_0f10));
        copy16_0f10(end + 1, &sentinel, sizeof(FNVRec_0f10));
        copy16_0f10(end + 2, &sentinel, sizeof(FNVRec_0f10));
        copy16_0f10(end + 3, &sentinel, sizeof(FNVRec_0f10));
    }

    SortRecordsByKey(scratch, n);
    FNVVector_0f10 squaredRadius;
    float rsq = radius * radius;
    squaredRadius.quad = scalar_0f10(rsq);

    if (n > 0)
    {
        int rem = n;
        int next = 1;
        unsigned int* keyp = &scratch[0].vertexKey;
        for (; rem != 0; ++next, keyp += 8, --rem)
        {
            int ci = (int)*keyp;
            if (ci != -1)
            {
                FNVVector_0f10 p = cloud->m_pPts[ci];
                ((int*)idx->m_pData)[ci] = out->m_iArrayLength;
                FNVRouter_0f10* router3 = (FNVRouter_0f10*)hkMemoryRouter_getInstance();
                if (out->m_iArrayLength == (out->m_uCapacity & 0x3fffffff))
                {
                    (ResizeAudioStream)((void*)router3->heap, (void*)out, 0x10);
                }
                ((FNVVector_0f10*)out->m_pData)[out->m_iArrayLength].quad = p.quad;
                ++out->m_iArrayLength;
                int j = next;
                if (j < n)
                {
                    unsigned int* scanp = keyp + 8;
                    do
                    {
                        unsigned int minX = scanp[-3];
                        _ReadWriteBarrier();
                        if (minX > keyp[1])
                            break;
                        int cj = (int)*scanp;
                        if (cj == -1)
                            goto advance;
                        FNVVector_0f10 q = cloud->m_pPts[cj];
                        __m128 d = _mm_sub_ps(p.quad, q.quad);
                        d = _mm_mul_ps(d, d);
                        __m128 xy = _mm_add_ss(_mm_shuffle_ps(d, d, 0x55), d);
                        __m128 dist = _mm_add_ss(_mm_shuffle_ps(d, d, 0xaa), xy);
                        float distance, threshold;
                        _mm_store_ss(&distance, dist);
                        _mm_store_ss(&threshold, squaredRadius.quad);
                        if (distance <= threshold)
                        {
                            ((int*)idx->m_pData)[cj] = ((int*)idx->m_pData)[ci];
                            *scanp = 0xffffffff;
                        }
                    advance:
                        ++j;
                        scanp += 8;
                    } while (j < n);
                }
            }
        }
    }
    FNVRouter_0f10* router4 = (FNVRouter_0f10*)hkMemoryRouter_getInstance();
    FNVScratchAlloc_0f10* a4 = router4->heap;
    if ((scratchCap & 0x80000000) == 0)
        a4->freeArray(scratch, scratchCap & 0x3fffffff);
}
