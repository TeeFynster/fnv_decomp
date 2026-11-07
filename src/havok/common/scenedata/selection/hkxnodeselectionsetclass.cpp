#include "../../../../../include/hkArray.h"

// src/havok/common/scenedata/selection/hkxnodeselectionsetclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/scenedata/selection/hkxnodeselectionsetclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct E01D40Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void ReturnMemory(void* p, int numBytes);
};

struct E01D40MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    E01D40Allocator* m_pStreamAllocator;

    E01D40Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" E01D40MemoryRouter& __cdecl hkMemoryRouter_getInstance();

struct E01D40ReferencedObject
{
    void removeReference();
};

struct E01D40RefPtr
{
    E01D40ReferencedObject* m_pRetainedObject;

    __forceinline void release()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        m_pRetainedObject = 0;
    }
};

__forceinline void destruct(E01D40RefPtr* ptr, int size)
{
    for (int i = 0; i < size; i++)
        ptr[i].release();
}

typedef hkArrayBase<E01D40RefPtr> E01D40RefPtrArray;
template<> __forceinline void hkArrayBase<E01D40RefPtr>::_clearAndDeallocate(hkMemoryAllocator& sharedAlloc)
{
E01D40Allocator& alloc = reinterpret_cast<E01D40Allocator&>(sharedAlloc);

        destruct(m_data, m_iElementCount);
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(E01D40RefPtr));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    
}


struct E01D40StringPtr
{
    const char* m_pcText;

    void release();
};

struct E01D40Base
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;

    void release();
};

struct E01D40Object : E01D40Base
{
    E01D40RefPtrArray m_kTrackedObjects;
    E01D40StringPtr m_name;

    void ProcessState_00e01d40();
};

// Releases m_name, clears the reference array through the global allocator's heap, then calls E01D40Base::release.
// @fnv 0x00e01d40
// src: GUESS 0x00e01d40 (confidence: low)
void E01D40Object::ProcessState_00e01d40()
{
    m_name.release();
    m_kTrackedObjects._clearAndDeallocate(reinterpret_cast<hkMemoryAllocator&>(hkMemoryRouter_getInstance().heap()));
    E01D40Base::release();
}

namespace fnv_00e01dd0 {
struct CpuObject;
struct AudioInterface
{
    virtual void reserved00();
    virtual void reserved04();
    virtual void dispatch(CpuObject* object, unsigned short value);
};
struct AudioSystem
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioInterface* unk10;
};
extern void* __cdecl hkMemoryRouter_getInstance();
struct CpuObject
{
    int unk00;
    unsigned short unk04;
    void ProcessState_00e01d40();
    CpuObject* FUN_00e01dd0(bool enabled);
};
// Calls FUN_00e01d40, and if enabled dispatches this object with unk04 through the audio system's interface, then returns this.
// @fnv 0x00e01dd0
CpuObject* CpuObject::FUN_00e01dd0(bool enabled)
{
    ProcessState_00e01d40();
    if (enabled & 1)
    {
        AudioSystem* system = static_cast<AudioSystem*>(hkMemoryRouter_getInstance());
        system->unk10->dispatch(this, unk04);
    }
    return this;
}
}  // namespace fnv_00e01dd0
