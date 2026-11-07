
// src/havok/physics/dynamics/world/hkpworldobject.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/hkpworldobject.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/FinishingFlag.h"
#include "../../../../../include/hkArray.h"
#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/hkMultiThreadCheck.h"
#include "../../../../../include/hkReferencedObject.h"
#include "../../../../../include/hkStreamWriter.h"
#include "../../../../../include/hkStringPtr.h"
#include "../../../../../include/hkpCdBody.h"
#include "../../../../../include/hkpCollidable.h"
#include "../../../../../include/hkpCollidableBoundingVolumeData.h"
#include "../../../../../include/hkpLinkedCollidable.h"
#include "../../../../../include/hkpTypedBroadPhaseHandle.h"
#include "../../../../../include/hkpWorldObject.h"

// @fnv 0x00cd2930
// src: COMMUNITY 0x00cd2930
int __stdcall hkpWorldObject_setShape(int a1)
{
    return 1;
}

// The router getter at 0x00c85750 is shared as hkMemoryRouter::GetMonitorStream.

inline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return hkMemoryRouter::getInstance().heap();
}

// m_kProperties has 16-byte records: key at +0, padding at +4, and an 8-byte value at +8.
struct WorldObjectProperty
{
    void* m_key;
    int unk04;
    struct Value
    {
        int m_kPointA;
        int m_kPointB;
    };
    Value m_uiFilterValue;
};

template <class T>
__forceinline T& hkArrayBase<T>::_expandOne(hkMemoryAllocator& alloc)
{
    if (m_iElementCount == getCapacity())
        hkArrayUtil::_reserveMore(alloc, this, sizeof(T));
    return m_data[m_iElementCount++];
}

// Local helper methods absent from the shared world-object interface.
struct FNVWorldObject : hkpWorldObject
{
    void AddEntry(void* key, WorldObjectProperty::Value v);
    void WriteToStream(hkStreamWriter* writer, int unused);
};

// Returns if the property key already exists; otherwise appends an entry storing the key and value.
// @fnv 0x00cd2be0
void FNVWorldObject::AddEntry(void* key, WorldObjectProperty::Value v)
{
    for (int i = 0; i < m_kProperties.m_iElementCount; i++)
    {
        if (reinterpret_cast<WorldObjectProperty*>(m_kProperties.m_data)[i].m_key == key)
            return;
    }
    WorldObjectProperty& e = reinterpret_cast<hkArray<WorldObjectProperty>&>(m_kProperties).expandOne();
    e.m_uiFilterValue = v;
    e.m_key = key;
}

extern char DAT_0105c390;
extern char DAT_010cb2d8;
extern char DAT_01020e44;
extern char DAT_010cb2c8;
void* __cdecl hkStatisticsCollector_getAllocatedSize(void* data, int bytes);

// The serialization mode byte is not declared by the shared writer interface.
static inline unsigned char includesOwnedAllocations(const hkStreamWriter* writer)
{
    return reinterpret_cast<const unsigned char*>(writer)[0x10];
}

// Writes collision shape, collision entries, properties, and bounding volume child shape data to the stream writer.
// @fnv 0x00cd2b00
void FNVWorldObject::WriteToStream(hkStreamWriter* writer, int unused)
{
    writer->WriteField(&DAT_0105c390, m_kCollidable.m_pCollisionShape, 0);

    hkArray<char>& collisionEntries = m_kCollidable.m_kCollisionEntries;
    int entryCap = collisionEntries.m_iCapacityState;
    if ((entryCap & 0x80000000) == 0 || includesOwnedAllocations(writer))
    {
        void* entryData = collisionEntries.m_data;
        void* copy = hkStatisticsCollector_getAllocatedSize(entryData, (entryCap & 0x3fffffff) * 8);
        writer->WriteArray(3, &DAT_010cb2d8, collisionEntries.m_data, collisionEntries.m_iElementCount * 8, copy);
    }

    int propCap = m_kProperties.m_iCapacityState;
    if ((propCap & 0x80000000) == 0 || includesOwnedAllocations(writer))
    {
        void* propData = m_kProperties.m_data;
        void* copy = hkStatisticsCollector_getAllocatedSize(propData, (propCap & 0x3fffffff) * 16);
        writer->WriteArray(3, &DAT_01020e44, m_kProperties.m_data, m_kProperties.m_iElementCount * 16, copy);
    }

    hkpCollidableBoundingVolumeData& bounds = m_kCollidable.m_kBoundingVolumeData;
    void* firstChild = bounds.m_pChildShapeAabbs;
    if (firstChild)
    {
        writer->DispatchWithMode(&DAT_010cb2c8, firstChild, (unsigned int)bounds.m_uiCapacityChildShapeAabbs * 32, 0);
        writer->DispatchWithMode(&DAT_010cb2c8, bounds.m_pChildShapeKeys,
                                 (unsigned int)bounds.m_uiCapacityChildShapeAabbs * 4, 0);
    }
}

// These small constructor bodies remain here so callers retain the game's inlining.


inline void hkpTypedBroadPhaseHandle::SetOwnerPointer(void* owner)
{
    m_iOwnerOffset = (signed char)((char*)owner - (char*)this);
}

inline void hkpCollidableBoundingVolumeData::invalidate()
{
    m_kMinimumCorner[0] = 1;
    m_kMaximumCorner[0] = 0;
}

inline void hkpCollidable::SetOwnerPointer(void* owner)
{
    m_iOwnerOffset = (signed char)((char*)owner - (char*)this);
}

inline hkpLinkedCollidable::hkpLinkedCollidable(const void* shape, const void* motionState, int type)
    : hkpCollidable(shape, motionState, type)
{
}

inline hkMultiThreadCheck::hkMultiThreadCheck()
{
    m_uiThreadId = 0xfffffff1;
    m_usMarkedForWrite = 0x8000;
}

// The shared constructors still use an incomplete flag type; initialize their shared members here.
// hkpentity.cpp binds the same FinishingFlag helper signature to 0x00cd2c50.
extern const void* worldObjectVtable[];

// The shared string interface's finishing constructor has the same thiscall ABI.
struct StringPtrFinish : hkStringPtr
{
    void Finish(FinishingFlag flag);
};

inline void finishLinkedCollidable(hkpLinkedCollidable& collidable, FinishingFlag flag)
{
    if (flag.m_bFinishing)
    {
        hkpCollidableBoundingVolumeData& bounds = collidable.m_kBoundingVolumeData;
        bounds.m_uiNumChildShapeAabbs = 0;
        bounds.m_uiCapacityChildShapeAabbs = 0;
        bounds.m_pChildShapeAabbs = 0;
        bounds.m_pChildShapeKeys = 0;
        bounds.invalidate();
        collidable.m_kBroadPhaseHandle.SetOwnerPointer(&collidable);
    }
    collidable.m_kCollisionEntries.m_data = 0;
    collidable.m_kCollisionEntries.m_iElementCount = 0;
    collidable.m_kCollisionEntries.m_iCapacityState = 0x80000000;
}

// Constructs hkpWorldObject and, when finishing a load, sets the collidable's owner pointer to this object.
// @fnv 0x00cd2c50
hkpWorldObject* __fastcall finishWorldObject(hkpWorldObject* self, int, FinishingFlag flag)
{
    hkpWorldObject* volatile result = self;
    *reinterpret_cast<const void***>(self) = worldObjectVtable;
    hkpLinkedCollidable* collidable = &self->m_kCollidable;
    finishLinkedCollidable(*collidable, flag);
    self->m_kMultiThreadCheck.m_uiThreadId = 0xfffffff1;
    self->m_kMultiThreadCheck.m_usMarkedForWrite = 0x8000;
    reinterpret_cast<StringPtrFinish*>(&self->m_name)->Finish(flag);
    hkpWorldObject* object = result;
    if (flag.m_bFinishing)
        collidable->SetOwnerPointer(object);
    return object;
}

// Initializes members, sets the collidable's owner pointer, and retains shape when it is non-null.
// @fnv 0x00cd2ce0
hkpWorldObject::hkpWorldObject(const void* shape, int type)
    : m_pOwningWorld(0), m_ulUserData(0), m_kCollidable(shape, 0, type),
      m_kNextStreamField(0),
      m_pWorldObjectOwner(reinterpret_cast<void*>(-1))
{
    m_kCollidable.SetOwnerPointer(this);
    if (shape)
        ((hkReferencedObject*)shape)->addReference();
}
