
// src/havok/animation/animation/deform/skinning/hkameshbinding.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/deform/skinning/hkameshbinding.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/hkBaseObject.h"
#include "../../../../../../include/hkReferencedObject.h"
#include "../../../../../../include/hkStringPtr.h"
#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/hkTransform.h"
#include "../../../../../../include/hkArray.h"



// hkMemoryRouter is the shared router returned at 0x00c85750.

namespace hkE348 {
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

// ~hkArray (clearAndDeallocate with element destruction) through the memory router's heap.
template <typename T, typename A> __forceinline hkArray<T, A>::~hkArray()
{
    hkMemoryAllocator& kAlloc = hkMemoryRouter::getInstance().heap();
    hkE348::destruct(this->m_data, this->m_iElementCount);
    this->m_iElementCount = 0;
    if ((this->m_iCapacityState & 0x80000000) == 0)
        kAlloc.bufFree(this->m_data, (this->m_iCapacityState & 0x3fffffff) * sizeof(T));
    this->m_data = 0;
    this->m_iCapacityState = 0x80000000;
}

// No shared hkaMeshBinding header exists yet; retain its complete local layout.
class hkaMeshBinding : public hkReferencedObject
{
  public:
    virtual ~hkaMeshBinding() throw();
    void* FUN_00e34920(int flags);

    hkE348::ReferenceCountedPointer<hkReferencedObject> m_pMesh;
    hkStringPtr m_name;
    hkE348::ReferenceCountedPointer<hkReferencedObject> m_pSkeleton;
    hkArray<hkArray<short> > m_kMappings;
    hkArray<hkTransform> m_kBoneFromSkinningTransforms;
};

// @fnv 0x00e34820
hkaMeshBinding::~hkaMeshBinding() throw()
{}

// Calls the destructor, optionally frees the allocation, and returns this.
// @fnv 0x00e34920
void* hkaMeshBinding::FUN_00e34920(int flags)
{
    hkaMeshBinding::~hkaMeshBinding();

    if (flags & 1)
    {
        hkMemoryRouter* router = &hkMemoryRouter::getInstance();
        router->m_heap->blockFree(this, m_usMemSizeAndFlags);
    }

    return this;
}
