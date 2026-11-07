
// src/havok/physics/utilities/dynamics/savecontactpoints/hkpphysicssystemwithcontacts.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/dynamics/savecontactpoints/hkpphysicssystemwithcontacts.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/hkArray.h"
#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/hkReferencedObject.h"
#include "../../../../../../include/hkpPhysicsSystem.h"

class hkpSerializedAgentNnEntry;

// Returns 0.
// @fnv 0x00dceb80
// src: GUESS 0x00dceb80 (confidence: high)
int Object_ReturnZero_00dceb80()
{
    return 0;
}


__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return hkMemoryRouter::getInstance().heap();
}

template <class T>
__forceinline void hkArrayUtil::constructWithCopy(T* p, int n, const T& t, hkTypeIsPod)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T>
__forceinline void hkArrayBase<T>::_pushBack(hkMemoryAllocator& alloc, const T& t)
{
    if (m_iElementCount == getCapacity())
        hkArrayUtil::_reserveMore(alloc, this, sizeof(T));
    hkArrayUtil::constructWithCopy(m_data + m_iElementCount, 1, t, hkTypeIsPod());
    m_iElementCount++;
}

template <class T, class Allocator>
__forceinline hkArray<T, Allocator>::~hkArray()
{
    hkMemoryAllocator& allocator = Allocator().get(this);
    unsigned int flags = m_iCapacityState;
    m_iElementCount = 0;
    if (!(flags & 0x80000000u))
        allocator.bufFree(m_data, sizeof(T) * (flags & 0x3fffffffu));
    m_data = 0;
    m_iCapacityState = 0x80000000;
}

// No shared contacts-system header is available yet; both functions use its array at +0x44.
class hkpPhysicsSystemWithContacts : public hkpPhysicsSystem
{
  public:
    virtual ~hkpPhysicsSystemWithContacts() throw();
    hkArray<hkpSerializedAgentNnEntry*> m_kSerializedAgentEntries;
    void AddObject(hkpSerializedAgentNnEntry* pkObject);
};

// @fnv 0x00dcec70
void hkpPhysicsSystemWithContacts::AddObject(hkpSerializedAgentNnEntry* pkObject)
{
    if (pkObject)
    {
        reinterpret_cast<hkReferencedObject*>(pkObject)->addReference();
        m_kSerializedAgentEntries.pushBack(pkObject);
    }
}

// @fnv 0x00dcecc0
hkpPhysicsSystemWithContacts::~hkpPhysicsSystemWithContacts() throw()
{
    int iAgentCount = m_kSerializedAgentEntries.m_iElementCount;
    for (int i = 0; i < iAgentCount; ++i)
    {
        reinterpret_cast<hkReferencedObject*>(m_kSerializedAgentEntries.m_data[i])->removeReference();
    }
}
