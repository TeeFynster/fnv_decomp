#pragma once
#include "hkBool.h"
#include "hkTypeTraits.h"
#include "FinishingFlag.h"

class hkMemoryAllocator;

template <typename T>
class hkArrayBase
{
  public:
    typedef hkArrayBase<T> ThisType;

    __forceinline hkArrayBase() : m_data(0), m_iElementCount(0), m_iCapacityState(int(0x80000000)) {}
    __forceinline hkArrayBase(T* buffer, int size, int capacity)
        : m_data(buffer), m_iElementCount(size), m_iCapacityState(capacity | int(0x80000000))
    {
    }

  protected:
    __forceinline hkArrayBase(const hkArrayBase& a) {}
    __forceinline hkArrayBase& operator=(const hkArrayBase& a) { return *this; }

  public:
    __forceinline void _useExternalArray(T* buf, int capacity)
    {
        m_data = static_cast<T*>(buf);
        m_iCapacityState = capacity | DONT_DEALLOCATE_FLAG;
    }
    __forceinline void _useExternalBuffer(void* buf, int numBytes) { _useExternalArray(static_cast<T*>(buf), numBytes / sizeof(T)); }
    __forceinline ~hkArrayBase() {}

    __forceinline T& operator[](int i) { return m_data[i]; }
    __forceinline const T& operator[](int i) const { return m_data[i]; }
    __forceinline T& back() { return m_data[m_iElementCount - 1]; }
    __forceinline const T& back() const { return m_data[m_iElementCount - 1]; }
    __forceinline int GetLogicalSize() const { return m_iElementCount; }   // getSize
    __forceinline int getSize() const { return m_iElementCount; }
    __forceinline int getCapacity() const { return m_iCapacityState & static_cast<int>(CAPACITY_MASK); }
    __forceinline int getCapacityAndFlags() const { return m_iCapacityState; }
    __forceinline hkBool isEmpty() const { return m_iElementCount == 0; }

    // hkArrayUtil::destruct / construct / constructWithCopy / _reserve / _reserveMore based: unit-defined.
    __forceinline void clear();
    __forceinline void _clearAndDeallocate(hkMemoryAllocator& kAlloc);
    __forceinline void _optimizeCapacity(hkMemoryAllocator& kAlloc, int iNumFreeElemsLeft, int iShrinkExact = 0);
    __forceinline void removeAt(int iIndex);
    __forceinline void removeAtAndCopy(int iIndex);
    __forceinline void removeAtAndCopy(int iIndex, int iNumToRemove);
    __forceinline int indexOf(const T& t, int start = 0, int end = -1) const
    {
        if (end < 0)
            end = m_iElementCount;
        for (int i = start; i < end; ++i)
        {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
    __forceinline int lastIndexOf(const T& t) const
    {
        for (int i = m_iElementCount - 1; i >= 0; --i)
        {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
    __forceinline void popBack(int iNumElemsToRemove = 1);
    __forceinline void _pushBack(hkMemoryAllocator& kAlloc, const T& kElem);
    __forceinline void pushBackUnchecked(const T& kElem);
    __forceinline void GrowArrayCapacity(hkMemoryAllocator& kAlloc, int iCount);   // _reserve
    __forceinline void _reserveExactly(hkMemoryAllocator& kAlloc, int iCount);
    __forceinline void _setSize(hkMemoryAllocator& kAlloc, int iSize);
    __forceinline void _setSize(hkMemoryAllocator& kAlloc, int iCount, const T& kFill);
    __forceinline void setSizeUnchecked(int iSize);
    __forceinline T& _expandOne(hkMemoryAllocator& kAlloc);
    __forceinline T* _expandBy(hkMemoryAllocator& kAlloc, int iCount);
    __forceinline T* expandByUnchecked(int iCount);
    __forceinline T* _expandAt(hkMemoryAllocator& kAlloc, int iIndex, int iNumToInsert);
    void _insertAt(hkMemoryAllocator& kAlloc, int iIndex, const T* pFirst, int iNumElems);
    void _insertAt(hkMemoryAllocator& kAlloc, int iIndex, const T& kItem);
    void _append(hkMemoryAllocator& kAlloc, const T* pFirst, int iNumElems);
    void _spliceInto(hkMemoryAllocator& kAlloc, int iIndex, int iNdel, const T* pItem, int iNumElems);
    __forceinline void removeAllAndCopy(const T& kItem);

    typedef T* iterator;
    typedef const T* const_iterator;
    __forceinline iterator begin() { return m_data; }
    __forceinline iterator end() { return m_data + m_iElementCount; }
    __forceinline const_iterator begin() const { return m_data; }
    __forceinline const_iterator end() const { return m_data + m_iElementCount; }

    static __forceinline void __cdecl copy(T* dst, const T* src, int n)
    {
        for (int i = 0; i < n; ++i)
        {
            dst[i] = src[i];
        }
    }
    __forceinline void setOwnedData(T* ptr, int size, int capacity)
    {
        m_data = ptr;
        m_iElementCount = size;
        m_iCapacityState = capacity;
    }

  protected:
    __forceinline hkArrayBase<T>& copyFromArray(hkMemoryAllocator&, const hkArrayBase<T>& kSrc, hkTypeIsPod);
    __forceinline hkArrayBase<T>& copyFromArray(hkMemoryAllocator&, const hkArrayBase<T>& kSrc, hkTypeIsClass);

  public:
    enum
    {
        CAPACITY_MASK = int(0x3FFFFFFF),
        FLAG_MASK = int(0xC0000000),
        DONT_DEALLOCATE_FLAG = int(0x80000000),   // the storage is not the array's to free
        FORCE_SIGNED = -1
    };

    friend class hkArrayUtil;
    friend class hkStatisticsCollector;
    T* m_data;              // +0x0
    int m_iElementCount;    // +0x4 m_size
    int m_iCapacityState;   // +0x8 m_capacityAndFlags

    T& GetIndexedValue_00d87240(int i); // exe: 0x00d87240, out-of-line element access
    T& hkClassMemberAccessor_asReal(int i); // exe: 0x00d87250, out-of-line element access

    hkArrayBase(FinishingFlag eFlag) {}
};
