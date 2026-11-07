#include "../../../../../../include/hkBaseObject.h"
#include "../../../../../../include/hkReferencedObject.h"
#include "../../../../../../include/hkDataClassNative.h"
#include "../../../../../../include/hkBool.h"
#include "../../../../../../include/hkClass.h"
#include "../../../../../../include/hkClassMember.h"
#include "../../../../../../include/hkError.h"
#include "../../../../../../include/hkMemoryAllocator.h"

// src/havok/common/serialize/data/native/hkdataobjectnative_noehsc_variant.cpp
// The native-world destructor requires /MT /O2 /GS /Gy without /EHsc.
// Unused declarations copied from the parent unit have been removed.



template <class T> class ReferenceCountedPointer
{
  public:
    ~ReferenceCountedPointer() throw()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        m_pRetainedObject = 0;
    }
    T* m_pRetainedObject;
};


// The iterator/value/free methods bound at 0x00d87410..0x00d877d0 operate on this native-class lookup map.
class NativeClassLookupMap
{
  public:
    ~NativeClassLookupMap() throw()
    {
        FreeBuffer();
    }
    int hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_getIterator() throw();
    char* SetBoolFromThreshold(char* result, int it) throw();
    hkDataClassNative* hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_getValue(int it) throw();
    int FindNextUsedSlot(int it) throw();
    void FreeBuffer() throw();

    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
};

// No approved include/hkDataWorldNative.h exists yet; retain the destructor's required layout locally.
class hkDataWorldNative : public hkReferencedObject
{
  public:
    virtual ~hkDataWorldNative();

    ReferenceCountedPointer<hkReferencedObject> m_ppVirtualMethodTable;
    ReferenceCountedPointer<hkReferencedObject> m_infoReg;
    NativeClassLookupMap m_kLookupMap;
};

// @fnv 0x00dbb3f0
hkDataWorldNative::~hkDataWorldNative()
{
    char valid;
    int it = m_kLookupMap.hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_getIterator();
    m_kLookupMap.SetBoolFromThreshold(&valid, it);
    while (valid)
    {
        delete m_kLookupMap.hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_getValue(it);
        it = m_kLookupMap.FindNextUsedSlot(it);
        m_kLookupMap.SetBoolFromThreshold(&valid, it);
    }
}
