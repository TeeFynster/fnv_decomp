#pragma once

// Havok 7.1 Common/Base/Object/hkReferencedObject.h (+ .inl).
// Member names follow the units (m_usMemSizeAndFlags == m_memSizeAndFlags,
// m_sReferenceCount == m_referenceCount). FinishingFlag is hkFinishLoadedObjectFlag.
#include <cstddef>
#include "hkBaseObject.h"

class hkClass;
class hkStatisticsCollector;
class hkCriticalSection;

class hkReferencedObject : public hkBaseObject
{
public:
    // HK_DECLARE_CLASS_ALLOCATOR(HK_MEMORY_CLASS_BASE_CLASS): the units define the bodies
    // (each against its own view of the memory router).
    static void* __cdecl operator new(std::size_t nbytes);
    static void operator delete(void* p);
    static void operator delete(void* p, unsigned int nbytes);

    // HK_DECLARE_REFLECTION()
    static const ClassMemberDescriptor Members[];
    static const hkClass& __cdecl staticClass();

    // Creates a new referenced object with an initial reference count of 1.
    __forceinline hkReferencedObject();

    // Copy constructor: the copy starts with a reference count of 1.
    __forceinline hkReferencedObject(const hkReferencedObject& originalObject);

    virtual ~hkReferencedObject() {}

    __forceinline int getAllocatedSize() const;
    __forceinline int getReferenceCount() const;

    void addReference() const;      // 0x00c90510
    void removeReference() const;   // 0x00c905b0
    void addReferenceLockUnchecked() const;
    void removeReferenceLockUnchecked() const;

    static void __cdecl addReferences(const hkReferencedObject* const* objects, int numObjects, int pointerStriding);
    static void __cdecl removeReferences(const hkReferencedObject* const* objects, int numObjects, int pointerStriding);

    enum LockMode
    {
        LOCK_MODE_NONE,
        LOCK_MODE_AUTO,
        LOCK_MODE_MANUAL
    };

    static void __cdecl setLockMode(LockMode mode);
    static LockMode __cdecl getLockMode();
    static void __cdecl lockAll();
    static void __cdecl unlockAll();
    static hkCriticalSection* __cdecl getLockCriticalSection();
    static void __cdecl lockInit(LockMode lockMode);

    virtual const hkClass* getClassType() const;                                                       // 0x00c90350
    virtual void calcContentStatistics(hkStatisticsCollector* collector, const hkClass* cls) const;    // 0x00c90360

public:
    enum
    {
        MASK_MEMSIZE = 0x7fff
    };

    unsigned short m_usMemSizeAndFlags;   // +0x4 m_memSizeAndFlags
    mutable short m_sReferenceCount;      // +0x6 m_referenceCount

public:
    hkReferencedObject(FinishingFlag flag) {}
};

__forceinline hkReferencedObject::hkReferencedObject()
    : m_sReferenceCount(1)
{
}

__forceinline hkReferencedObject::hkReferencedObject(const hkReferencedObject& originalObject)
    : hkBaseObject(), m_sReferenceCount(1)
{
}

__forceinline int hkReferencedObject::getReferenceCount() const
{
    return m_sReferenceCount;
}

__forceinline int hkReferencedObject::getAllocatedSize() const
{
    return m_usMemSizeAndFlags & MASK_MEMSIZE;
}
