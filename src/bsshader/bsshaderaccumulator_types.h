// bsshader/bsshaderaccumulator_types.h: the unit's generated layout support (the classes are the shared include/ ones)
#ifndef FNV_BSSHADERACCUMULATOR_PRIVATE_TYPES_H
#define FNV_BSSHADERACCUMULATOR_PRIVATE_TYPES_H

// Keep only the support this unit uses; layout_support.h also defines an obsolete NiTPointerMap.
#include <stddef.h>
#include "../../include/BSSimpleList.h"

#define FNV_JOIN_IMPL(a, b) a##b
#define FNV_JOIN(a, b) FNV_JOIN_IMPL(a, b)
#define FNV_STATIC_ASSERT(condition) typedef char FNV_JOIN(fnv_static_assert_, __LINE__)[(condition) ? 1 : -1]

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);

class RecursiveSpinLock;

template <class T> class AccumulatorPointer
{
  public:
    T* m_pObject;
    AccumulatorPointer(T* object = 0)
    {
        m_pObject = object;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    AccumulatorPointer(const AccumulatorPointer<T>& other)
    {
        m_pObject = other.m_pObject;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    ~AccumulatorPointer()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
    AccumulatorPointer<T>& operator=(T* object)
    {
        if (m_pObject != object)
        {
            if (m_pObject != 0)
                m_pObject->DecRefCount();
            m_pObject = object;
            if (m_pObject != 0)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    AccumulatorPointer<T>& operator=(const AccumulatorPointer<T>& other)
    {
        if (m_pObject != other.m_pObject)
        {
            if (m_pObject != 0)
                m_pObject->DecRefCount();
            m_pObject = other.m_pObject;
            if (m_pObject != 0)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    bool operator==(T* object) const
    {
        return m_pObject == object;
    }
    bool operator==(const AccumulatorPointer<T>& other) const
    {
        return m_pObject == other.m_pObject;
    }
    bool operator!=(const AccumulatorPointer<T>& other) const
    {
        return m_pObject != other.m_pObject;
    }
};

template <class T> class PoolAllocatorBase
{
  public:
    struct LinkedListEntry
    {
        LinkedListEntry* m_pkNext;
        void* m_pUserData;
        T m_element;
    };
    static LinkedListEntry* ms_pFreeList;
    static RecursiveSpinLock ms_kPoolState;
};

class AccumulatorCriticalSectionSynchronization
{
public:
    unsigned long RawEvent[4];
};
class AccumulatorCriticalSection
{
public:
    AccumulatorCriticalSectionSynchronization Synchronization;
    long LockCount;
    long RecursionCount;
    void* OwningThread;
};
FNV_STATIC_ASSERT(sizeof(AccumulatorCriticalSection) == 0x1C);
enum BSShaderAccumulator__etAccumulationMode
{
    BSShaderAccumulator__etAccumulationMode_BSSA_ACCUMNORMAL = 0,
    BSShaderAccumulator__etAccumulationMode_BSSA_ACCUMDEPTHMAP = 1,
    BSShaderAccumulator__etAccumulationMode_BSSA_ACCUMLOD = 2,
    BSShaderAccumulator__etAccumulationMode_BSSA_ACCUMNONE = 3
};
enum BSShaderManager__etRenderMode
{
    BSShaderManager__etRenderMode_BSSM_RENDER_NORMAL = 0,
    BSShaderManager__etRenderMode_BSSM_RENDER_NUMLIGHTS = 1,
    BSShaderManager__etRenderMode_BSSM_RENDER_NUMPASSES = 2,
    BSShaderManager__etRenderMode_BSSM_RENDER_SINGLEPASS = 3,
    BSShaderManager__etRenderMode_BSSM_RENDER_TEXUSAGE = 4,
    BSShaderManager__etRenderMode_BSSM_RENDER_DEGRADE = 5,
    BSShaderManager__etRenderMode_BSSM_RENDER_OVERDRAW = 6,
    BSShaderManager__etRenderMode_BSSM_RENDER_DEPTHMAP = 7,
    BSShaderManager__etRenderMode_BSSM_RENDER_CONSTALPHA = 8,
    BSShaderManager__etRenderMode_BSSM_RENDER_LOCALMAP = 9,
    BSShaderManager__etRenderMode_BSSM_RENDER_INTERFACE = 10,
    BSShaderManager__etRenderMode_BSSM_RENDER_FROZEN = 11,
    BSShaderManager__etRenderMode_BSSM_RENDER_FIRST_PERSON = 12,
    BSShaderManager__etRenderMode_BSSM_RENDER_SCREEN_SPLATTER = 13,
    BSShaderManager__etRenderMode_BSSM_RENDER_WATER_DEPTH = 14,
    BSShaderManager__etRenderMode_BSSM_RENDER_SILHOUETTE = 15,
    BSShaderManager__etRenderMode_BSSM_RENDER_COUNT = 16
};
#endif
