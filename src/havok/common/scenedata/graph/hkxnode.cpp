
// src/havok/common/scenedata/graph/hkxnode.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/scenedata/graph/hkxnode.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/hkBaseObject.h"
#include "../../../../../include/hkReferencedObject.h"
#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkMemoryRouter.h"



// hkMemoryRouter is the shared Havok router: TLS accessor 0x00c85750, heap at +0x10.

namespace hkDFF6 {
template <class T> class ReferenceCountedPointer
{
  public:
    __forceinline ~ReferenceCountedPointer() throw()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        m_pRetainedObject = 0;
    }
    T* m_pRetainedObject;
};

template <class T> __forceinline void destruct(T* ptr, int size)
{
    for (int i = 0; i < size; i++)
        ptr[i].~T();
}

}

#include "../../../../../include/hkArray.h"
// ~hkArray (clearAndDeallocate with element destruction) through the memory router's heap.
template <typename T, typename A> __forceinline hkArray<T, A>::~hkArray()
{
    hkMemoryAllocator& kAlloc = hkMemoryRouter::getInstance().heap();
    hkDFF6::destruct(this->m_data, this->m_iElementCount);
    this->m_iElementCount = 0;
    if ((this->m_iCapacityState & 0x80000000) == 0)
        kAlloc.bufFree(this->m_data, (this->m_iCapacityState & 0x3fffffff) * sizeof(T));
    this->m_data = 0;
    this->m_iCapacityState = 0x80000000;
}

class FUN_00dff6a0
{
  public:
    ~FUN_00dff6a0() throw();

    hkReferencedObject m_kBase;
    hkArray<hkDFF6::ReferenceCountedPointer<hkReferencedObject> > m_kChildList;
    hkDFF6::ReferenceCountedPointer<hkReferencedObject> m_spOwner;
};

// Destructor for a DFF6 node that releases its child list and owner reference.
// @fnv 0x00dff6a0
FUN_00dff6a0::~FUN_00dff6a0() throw()
{}
