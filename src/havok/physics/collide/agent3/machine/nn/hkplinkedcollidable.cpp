
// src/havok/physics/collide/agent3/machine/nn/hkplinkedcollidable.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent3/machine/nn/hkplinkedcollidable.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkpLinkedCollidable.h"
#include "../../../../../../../include/hkArray.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkMemoryAllocator.h"

struct FUN_00d08210_Entry
{
    void* collisionAgent;
    unsigned short collisionIndices[2];
    unsigned int metadata08, metadata0C, metadata10;
    hkpLinkedCollidable* owner;
};
struct FUN_00d08210_Pair
{
    FUN_00d08210_Entry* entry;
    unsigned int key;
};
int __cdecl CompareByNestedValue(const FUN_00d08210_Pair*, const FUN_00d08210_Pair*);
void __cdecl QuickSortPairs(FUN_00d08210_Pair*, int, int,
                            int(__cdecl*)(const FUN_00d08210_Pair*, const FUN_00d08210_Pair*));
struct FUN_00d08210_Collidable : hkpLinkedCollidable
{
    void UpdateCollisionIndices();
};
// @fnv 0x00d08210
void FUN_00d08210_Collidable::UpdateCollisionIndices()
{
    if (m_kCollisionEntries.m_iElementCount > 1)
        QuickSortPairs((FUN_00d08210_Pair*)m_kCollisionEntries.m_data, 0, m_kCollisionEntries.m_iElementCount - 1,
                       CompareByNestedValue);
    for (int index = 0; index < m_kCollisionEntries.m_iElementCount; ++index)
    {
        volatile FUN_00d08210_Pair* pair = ((volatile FUN_00d08210_Pair*)m_kCollisionEntries.m_data) + index;
        FUN_00d08210_Entry* entry = pair->entry;
        entry->collisionIndices[this == entry->owner] = (unsigned short)index;
    }
}

inline void* operator new(unsigned int, void* p)
{
    return p;
}
inline void operator delete(void*, void*)
{}

// The router accessor is 0x00c85750, also bound to hkMemoryRouter::GetMonitorStream in other units.

struct ItemD082
{
    int m_kPointA;
    int m_kPointB;
};

bool __cdecl CompareByNestedValue(const ItemD082& a, const ItemD082& b);
void __cdecl QuickSortPairs(ItemD082* pArr, int iLo, int iHi, bool(__cdecl* pfnCmp)(const ItemD082&, const ItemD082&));

template <class T> __forceinline void copyD082(T* pDst, const T* pSrc, int n)
{
    for (int i = 0; i < n; i++)
        pDst[i] = pSrc[i];
}

template <class T> __forceinline void constructWithArrayD082(T* pDst, int n, const T* pSrc)
{
    for (int i = 0; i < n; i++)
        new (pDst + i) T(pSrc[i]);
}

template <typename T>
__forceinline hkArrayBase<T>& hkArrayBase<T>::copyFromArray(hkMemoryAllocator& kAlloc,
                                                         const hkArrayBase<T>& a, hkTypeIsClass)
{
    const int iSize = m_iElementCount;
    const int iSrcSize = a.m_iElementCount;
    int iCopiedCount = (iSrcSize > iSize) ? iSize : iSrcSize;
    if (getCapacity() < iSrcSize)
    {
        int iCap2 = 2 * getCapacity();
        int iNewCap = (iSrcSize < iCap2) ? iCap2 : iSrcSize;
        hkArrayUtil::_reserve(kAlloc, this, iNewCap, sizeof(T));
    }
    copyD082(m_data, a.m_data, iCopiedCount);
    constructWithArrayD082(m_data + iCopiedCount, iSrcSize - iCopiedCount, a.m_data + iCopiedCount);
    m_iElementCount = iSrcSize;
    return *this;
}

__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return hkMemoryRouter::getInstance().heap();
}

template <typename T, typename Allocator>
__forceinline hkArray<T, Allocator>& hkArray<T, Allocator>::operator=(const hkArray& a)
{
    copyFromArray(Allocator().get(this), a, hkTypeIsClass());
    return *this;
}

template <class T> inline void quickSortD082(T* pArr, int iSize, bool(__cdecl* pfnCmp)(const T&, const T&))
{
    if (iSize > 1)
        QuickSortPairs(pArr, 0, iSize - 1, pfnCmp);
}

class ContainerD082
{
  public:
    int unk00, unk04, unk08, unk0C;
    signed char m_cIndex;
    char unk11[0x3f];
    hkArray<ItemD082> m_kUnsortedGeometryList;
    int unk5C, unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84, unk88;
    int unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8;
    int unkBC, unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC, unkE0, unkE4;
    unsigned char m_aucTypes[8];

    void CopyAndSortGeometryList(hkArray<ItemD082>& kOut) const;
};

// Copies m_kUnsortedGeometryList into kOut and quick-sorts it by nested value when m_aucTypes[m_cIndex] is 5.
// @fnv 0x00d08260
void ContainerD082::CopyAndSortGeometryList(hkArray<ItemD082>& kOut) const
{
    kOut = m_kUnsortedGeometryList;
    if (m_aucTypes[m_cIndex] == 5)
        quickSortD082(kOut.begin(), kOut.GetLogicalSize(), CompareByNestedValue);
}
