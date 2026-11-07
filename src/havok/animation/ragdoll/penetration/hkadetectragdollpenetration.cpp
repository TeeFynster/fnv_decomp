#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit keeps the out-of-line hkVector4 form

// src/havok/animation/ragdoll/penetration/hkadetectragdollpenetration.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/ragdoll/penetration/hkadetectragdollpenetration.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Keep the original intrinsic layout; VC9 uses its array members when arranging stack slots.
#define _INCLUDED_MM2
// Exe 0x00d1fb00 FUN_00d1fb00: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C" LocalM128 _mm_set_ps1(float);
extern "C" LocalM128 _mm_min_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_max_ps(LocalM128, LocalM128);

#include <string.h>

#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/hkAabb.h"
#include "../../../../../include/hkBool.h"
#include "../../../../../include/hkArray.h"
#include "../../../../../include/hkVector4.h"

__declspec(nothrow) hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
inline hkMemoryRouter* audio()
{
    return hkMemoryRouter_getInstance();
}

__declspec(nothrow) void __cdecl hkArrayUtil__reserve(hkMemoryAllocator& alloc, void* arr, int numElem, int sizeElem);

inline void* operator new(unsigned int, void* p)
{
    return p;
}

struct hkIntArrayLocalForm
{ // local form of hkArray: 0x00d1fa50 needs the original constructor stores; shared base construction changes bytes.
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline void init()
    {
        m_data = 0;
        m_iElementCount = 0;
        m_iCapacityState = 0x80000000;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void reserve(int n)
    {
        hkMemoryAllocator& alloc = audio()->heap();
        if (getCapacity() < n)
        {
            int cap = 2 * getCapacity();
            hkArrayUtil__reserve(alloc, this, n < cap ? cap : n, sizeof(int));
        }
    }
    __forceinline void SetSizeAndGrow(int n, const int& fill)
    {
        reserve(n);
        int num = n - m_iElementCount;
        int* p = m_data + m_iElementCount;
        for (int i = 0; i < num; i++)
            new (p + i) int(fill);
        m_iElementCount = n;
    }
};

struct Info
{
    int unk00[7];
    int m_uiItemCount;
};

struct Desc
{
    Info* m_info;
    int unk04;
    int unk08;
};

extern "C" char DAT_010ce1a8[];

struct RefObj
{
    void* m_vtbl;
    short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

struct FUN_00d1fa50 : RefObj
{
    Desc m_kCreateDesc;
    int m_uiItemCount;
    hkIntArrayLocalForm m_aiIndexedValues;
    bool m_flag;
    FUN_00d1fa50(const Desc& d);
};

// @fnv 0x00d1fa50
FUN_00d1fa50::FUN_00d1fa50(const Desc& d)
{
    m_vtbl = DAT_010ce1a8;
    m_sReferenceCount = 1;
    m_kCreateDesc = d;
    m_aiIndexedValues.init();
    int n = m_kCreateDesc.m_info->m_uiItemCount;
    m_uiItemCount = n;
    m_aiIndexedValues.SetSizeAndGrow(n, 1);
    m_flag = false;
}

extern float DAT_0104da48;
extern float DAT_0104e148;



__forceinline void hkVector4::SetAllComponents(float f)
{
    m_vComponents = _mm_set_ps1(f);
}

__forceinline void hkVector4::setMin4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents);
}

__forceinline void hkVector4::setMax4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_max_ps(a.m_vComponents, b.m_vComponents);
}

inline hkAabb::hkAabb()
{}

inline void hkAabb::includePoint(const hkVector4& p)
{
    m_kMinimumCorner.setMin4(m_kMinimumCorner, p);
    m_kMaximumCorner.setMax4(m_kMaximumCorner, p);
}

struct hkAllocVt
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void ReturnMemory(void* p, int numBytes) throw();
};

__declspec(nothrow) void __cdecl ResizeAudioStream(void* alloc, void* arr, int sizeElem);

// hkArray bodies (allocator = the memory router's heap).
__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return audio()->heap();
}
template <typename T, typename A> __forceinline hkArray<T, A>::~hkArray()
{
    hkAllocVt& alloc = (hkAllocVt&)audio()->heap();
    this->m_iElementCount = 0;
    if ((this->m_iCapacityState & 0x80000000) == 0)
        alloc.ReturnMemory(this->m_data, (this->m_iCapacityState & 0x3fffffff) * sizeof(T));
    this->m_data = 0;
    this->m_iCapacityState = 0x80000000;
}
template <typename T> __forceinline void hkArrayBase<T>::_pushBack(hkMemoryAllocator& alloc, const T& t)
{
    if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
        ResizeAudioStream(&alloc, this, sizeof(T));
    // Preserve the array's bitwise copy of these records.
    T* p = m_data + m_iElementCount;
    if (p)
        memcpy(p, &t, sizeof(T));
    m_iElementCount++;
}

struct BoxEntry
{
    hkVector4 m_kPoint;
    hkVector4 m_unk10;
    hkVector4 m_unk20;
};

struct BoxSet
{
    int unk00, unk04, unk08, unk0c;
    BoxEntry* m_boxes;
    int unk14, unk18;
    int* m_flags;
    const hkVector4& hkaPose_calculateBoneModelSpace(int idx) throw();
    __forceinline const hkVector4& GetBoxVector(int idx)
    {
        if (!(m_flags[idx] & 2))
            return m_boxes[idx].m_kPoint;
        return hkaPose_calculateBoneModelSpace(idx);
    }
};

struct IndexInfo
{
    int unk00, unk04, unk08;
    short* m_idx;
};

struct PairRecord
{
    short m_kPointA;
    short m_kPointB;
    int unk04, unk08, unk0c;
    hkVector4 m_p0;
    hkVector4 m_p1;
    PairRecord() throw();
};

struct AabbSink
{
    void hkpAabbPhantom_setAabb(const hkAabb& aabb) throw();
};

struct PairTester
{
    virtual void v00();
    virtual hkBool test(AabbSink* sink, const hkVector4& a, const hkVector4& b, hkVector4& p0, hkVector4& p1) throw();
};

void __cdecl CollectReachableNodes(IndexInfo* info, short idx, hkArray<short>* list, int flags) throw();

struct PairFinder : RefObj
{
    IndexInfo* m_info;
    PairTester* m_tester;
    AabbSink* m_sink;
    int m_uiItemCount;
    hkIntArrayLocalForm m_aiIndexedValues;
    bool m_flag;
    hkBool hkaDetectRagdollPenetration_detectPenetration(BoxSet* boxes, hkArray<PairRecord>* out);
};

// Tests box pairs against m_tester, collects matching PairRecords into out, and marks reachable nodes in m_aiIndexedValues.
// @fnv 0x00d1fb00
// src: COMMUNITY 0x00d1fb00
hkBool PairFinder::hkaDetectRagdollPenetration_detectPenetration(BoxSet* boxes, hkArray<PairRecord>* out)
{
    out->m_iElementCount = 0;
    if (!m_flag)
    {
        {
            hkAabb aabb;
            aabb.m_kMinimumCorner.SetAllComponents(DAT_0104da48);
            aabb.m_kMaximumCorner.SetAllComponents(DAT_0104e148);
            for (short i = 1; i < m_uiItemCount; i++)
            {
                short idx = m_info->m_idx[i];
                if (m_aiIndexedValues.m_data[idx])
                {
                    hkVector4 a;
                    a = boxes->GetBoxVector(idx);
                    hkVector4 b;
                    b = boxes->GetBoxVector(i);
                    aabb.includePoint(a);
                    aabb.includePoint(b);
                }
            }
            if (aabb.ValidateBounds())
                m_sink->hkpAabbPhantom_setAabb(aabb);
        }
        hkVector4 a, b, p0, p1;
        for (short i = 1; i < m_uiItemCount; i++)
        {
            short idx = m_info->m_idx[i];
            if (m_aiIndexedValues.m_data[idx])
            {
                a = boxes->GetBoxVector(idx);
                b = boxes->GetBoxVector(i);
                hkBool res = m_tester->test(m_sink, a, b, p0, p1);
                if (res)
                {
                    PairRecord rec;
                    rec.m_p0 = p0;
                    rec.m_kPointA = idx;
                    rec.m_kPointB = i;
                    rec.m_p1 = p1;
                    out->pushBack(rec);
                }
            }
        }
    }
    for (int k = 0; k < m_aiIndexedValues.m_iElementCount; k++)
        m_aiIndexedValues.m_data[k] = 0;
    if (out->m_iElementCount == 0)
    {
        m_flag = true;
        return false;
    }
    for (int j = 0; j < out->m_iElementCount; j++)
    {
        short c = out->m_data[j].m_kPointA;
        if (m_aiIndexedValues.m_data[c] != 2)
            m_aiIndexedValues.m_data[c] = 1;
        hkArray<short> list;
        CollectReachableNodes(m_info, c, &list, 0);
        for (int k = 0; k < list.m_iElementCount; k++)
        {
            short p = list.m_data[k];
            if (m_aiIndexedValues.m_data[p] != 2)
                m_aiIndexedValues.m_data[p] = 2;
        }
    }
    return true;
}


namespace fnv_00d1fe70 {
extern int DAT_0102e388;

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

struct FUN_00d1fe70_cls
{
    int m_vptr;
    unsigned short m_uSize;
    unsigned short m_u06;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    void* m_p18;
    int m_1c;
    int m_20;

    FUN_00d1fe70_cls* FUN_00d1fe70(unsigned char acFlags);
    static void operator delete(void* apMemory) throw();
};

// Frees the m_p18 array, resets its state, restores the vtable, and optionally frees this when acFlags bit 0 is set.
// @fnv 0x00d1fe70
FUN_00d1fe70_cls* FUN_00d1fe70_cls::FUN_00d1fe70(unsigned char acFlags)
{
    hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
    int count = m_20;
    m_1c = 0;
    if (((unsigned int)count & 0x80000000u) == 0)
    {
        pAllocator->bufFree(m_p18, (unsigned int)(count & 0x3fffffff) * 4);
    }
    m_p18 = 0;
    m_20 = 0x80000000;
    m_vptr = (int)&DAT_0102e388;
    if (acFlags & 1)
    {
        hkMemoryRouter* pHolder2 = hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator2 = reinterpret_cast<hkMemoryAllocator*>(pHolder2->m_heap);
        pAllocator2->blockFree(this, m_uSize);
    }
    return this;
}
}  // namespace fnv_00d1fe70
