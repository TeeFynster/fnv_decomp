#pragma once
#ifndef FNV64_HKARRAY_FINISH_SPEC
#define FNV64_HKARRAY_FINISH_SPEC
#endif
#include <stddef.h>
#include "hkBool.h"
#include "hkTypeTraits.h"   // hkTypeIsPod, hkTypeIsClass
#include "FinishingFlag.h"   // hkFinishLoadedObjectFlag

// Havok 7.1 Common/Base/Container/Array/hkArray.h + hkArray.inl (+ hkArrayUtil.h, hkContainerAllocators.h).
//   hkArrayBase<T>             sizeof 12: T* m_data; int m_size; int m_capacityAndFlags (top 2 bits = flags)
//   hkArray<T, Allocator>      : hkArrayBase<T>, no data of its own (sizeof 12)
//   hkInplaceArray<T, N, A>    : hkArray<T, A> + T m_storage[N]
// Unit stand-ins: HavokElementArray<T> == hkArrayBase<T>; hkArr<T>, hkArrayQ<T>, hkArrayRaw<T> and the plain
// `struct hkArray { T* m_data; int m_iElementCount; int m_iCapacityState; }` copies == hkArray<T>;
// RouterHeapAllocatorProvider == hkContainerHeapAllocator; FUN_00c908c0 == hkArrayUtil::_reserve.
// Member names follow the units (m_iElementCount == m_size, m_iCapacityState == m_capacityAndFlags,
// GetLogicalSize == getSize, GrowArrayCapacity == _reserve). The members are public here (protected in Havok)
// because the units read them directly; access does not change layout or code.
// Bodies that only touch the members are inline here, exactly as hkArray.inl (release: no asserts). Bodies that
// go through an allocator or hkArrayUtil are declared only: a unit defines the ones it uses out of class
// (__forceinline), as it did in its own copy, since their call forms (and bound names) differ per unit.

class hkMemoryAllocator;


// hkContainerAllocators.h: get() is hkMemoryRouter::getInstance().heap() / temp() / debug(); a unit defines it
// (the units' hkMemoryRouter stand-in is hkMemoryRouter).
struct hkContainerTempAllocator
{
    hkMemoryAllocator& get(void*);
};
struct hkContainerHeapAllocator
{
    hkMemoryAllocator& get(const void*);
};
struct hkContainerDebugAllocator
{
    hkMemoryAllocator& get(void*);
};

#include "hkArrayBase.h"

template <typename T, typename Allocator = hkContainerHeapAllocator>
class hkArray : public hkArrayBase<T>
{
  public:
    typedef Allocator AllocatorType;
    typedef hkArray<T, hkContainerHeapAllocator> Heap;
    typedef hkArray<T, hkContainerTempAllocator> Temp;
    typedef hkArray<T, hkContainerDebugAllocator> Debug;
    friend class hkArrayUtil;

    __forceinline hkArray() : hkArrayBase<T>() {}
    __forceinline ~hkArray();   // clearAndDeallocate()
    explicit __forceinline hkArray(int iSize);
    __forceinline hkArray(int iSize, const T& kFill);
    __forceinline hkArray(T* buffer, int size, int capacity) : hkArrayBase<T>(buffer, size, capacity) {}
    hkArray(FinishingFlag f) FNV64_HKARRAY_FINISH_SPEC : hkArrayBase<T>(f) {}

  protected:
    __forceinline hkArray(const hkArray& kFirst);

  public:
    __forceinline hkArray& operator=(const hkArrayBase<T>& kFirst);
    __forceinline hkArray& operator=(const hkArray& kFirst);
    void swap(hkArray& kFirst);

    __forceinline void useExternalArray(T* pItem, int iNumElements);
    __forceinline void useExternalBuffer(void* pBuf, int iNumBytes);
    __forceinline void clearAndDeallocate() { hkArrayBase<T>::_clearAndDeallocate(AllocatorType().get(this)); }
    __forceinline void optimizeCapacity(int iSpare, int iExact = 0)
    {
        hkArrayBase<T>::_optimizeCapacity(AllocatorType().get(this), iSpare, iExact);
    }
    __forceinline void pushBack(const T& kItem) { hkArrayBase<T>::_pushBack(AllocatorType().get(this), kItem); }
    __forceinline void reserve(int iCount) { hkArrayBase<T>::GrowArrayCapacity(AllocatorType().get(this), iCount); }
    __forceinline void reserveExactly(int iCount) { hkArrayBase<T>::_reserveExactly(AllocatorType().get(this), iCount); }
    __forceinline void setSize(int iCount) { hkArrayBase<T>::_setSize(AllocatorType().get(this), iCount); }
    __forceinline void setSize(int iCount, const T& kFill) { hkArrayBase<T>::_setSize(AllocatorType().get(this), iCount, kFill); }
    __forceinline T& expandOne() { return hkArrayBase<T>::_expandOne(AllocatorType().get(this)); }
    __forceinline T* expandBy(int iCount) { return hkArrayBase<T>::_expandBy(AllocatorType().get(this), iCount); }
    __forceinline T* expandAt(int iAt, int iCount) { return hkArrayBase<T>::_expandAt(AllocatorType().get(this), iAt, iCount); }
    __forceinline void insertAt(int iAt, const T& kItem) { hkArrayBase<T>::_insertAt(AllocatorType().get(this), iAt, kItem); }
    __forceinline void insertAt(int iAt, const T* pSrc, int iNum) { hkArrayBase<T>::_insertAt(AllocatorType().get(this), iAt, pSrc, iNum); }
    __forceinline void append(const T* pSrc, int iNum) { hkArrayBase<T>::_append(AllocatorType().get(this), pSrc, iNum); }
    __forceinline void spliceInto(int iAt, int iRemove, const T* pSrc, int iNum)
    {
        hkArrayBase<T>::_spliceInto(AllocatorType().get(this), iAt, iRemove, pSrc, iNum);
    }
};

template <typename T, unsigned N, typename Allocator = hkContainerHeapAllocator>
class hkInplaceArray : public hkArray<T, Allocator>
{
  public:
    explicit __forceinline hkInplaceArray(int iCount = 0) : hkArray<T, Allocator>(m_storage, iCount, N) {}
    __forceinline hkInplaceArray(const hkInplaceArray<T, N, Allocator>& kOther) : hkArray<T, Allocator>(m_storage, 0, N) { *this = kOther; }
    __forceinline ~hkInplaceArray() {}
    typedef hkInplaceArray<T, N, Allocator> mytype;

    __forceinline hkArray<T, Allocator>& operator=(const hkArrayBase<T>& kOther) { return hkArray<T, Allocator>::operator=(kOther); }
    __forceinline hkArray<T, Allocator>& operator=(const hkInplaceArray<T, N, Allocator>& kOther) { return hkArray<T, Allocator>::operator=(kOther); }
    __forceinline void optimizeCapacity(int iNumFreeElemsLeft, int iShrinkExact = 0);
    __forceinline hkBool wasReallocated() const { return this->m_data != m_storage; }
    __forceinline int stillInplaceUsingMask() const { return this->m_iCapacityState & hkArrayBase<T>::DONT_DEALLOCATE_FLAG; }

    T m_storage[N];

    hkInplaceArray(FinishingFlag eFlag) : hkArray<T, Allocator>(eFlag) {}
};

// hkArrayUtil.h: the out-of-line helpers (0x00c908c0 is _reserve). construct / destruct / constructWithCopy /
// constructWithArray are templates on hkTypeIsPod / hkTypeIsClass that a unit defines when it uses them.
class hkArrayUtil
{
  public:
    template <typename T> static __forceinline void construct(T* pItem, int iCount, hkTypeIsPod);
    template <typename T> static __forceinline void construct(T* pItem, int iCount, hkTypeIsClass);
    template <typename T> static __forceinline void constructWithCopy(T* pItem, int iCount, const T& kTcopy, hkTypeIsPod);
    template <typename T> static __forceinline void constructWithCopy(T* pItem, int iCount, const T& kTcopy, hkTypeIsClass);
    template <typename T> static __forceinline void destruct(T* pItem, int iCount, hkTypeIsPod);
    template <typename T> static __forceinline void destruct(T* pItem, int iCount, hkTypeIsClass);
    template <typename T> static __forceinline void constructWithArray(T* pItem, int iCount, const T* pTcopy, hkTypeIsPod);
    template <typename T> static __forceinline void constructWithArray(T* pItem, int iCount, const T* pTcopy, hkTypeIsClass);
    static void __cdecl _reserve(hkMemoryAllocator& kFirst, void*, int iReqElem, int iSizeElem);
    static void __cdecl _reserveMore(hkMemoryAllocator& kFirst, void* pArray, int iSizeElem);
    static void __cdecl _reduce(hkMemoryAllocator& kFirst, void* pArray, int iSizeElem, char* sInplaceMem, int iRequestedCapacity);
};
