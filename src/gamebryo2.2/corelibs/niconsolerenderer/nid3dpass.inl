
#include <stddef.h>

#include "../../../../include/NiMemObject.h"
#include "../../../../include/NiTPrimitiveSet.h"
#include "../../../../include/NiTSet.h"

class D3DRenderStateGroup : public NiMemObject
{
public:
    struct NiD3DRenderStateEntry
    {
        unsigned int m_uiState;
        unsigned int m_uiCurrentValue;
        NiD3DRenderStateEntry* m_pkNext;
        NiD3DRenderStateEntry* m_pkPrev;
    };

    bool m_bHasBeenApplied;
    unsigned int m_uiRenderStateEntryCount;
    NiD3DRenderStateEntry* m_pkRenderStateEntries;
    unsigned int m_uiFreeEntryCount;
    NiD3DRenderStateEntry* m_pkFreeEntries;

    ~D3DRenderStateGroup();
    static void ReleaseRenderStateGroup(D3DRenderStateGroup* group);
};

template<class T, class Allocator> class ObjectPool
{
public:
    NiTPrimitiveSet<T*> m_kAvailableObjects;
    void* m_pContainerList;
    unsigned int m_uiNextBlockSize;
    unsigned int m_uiInitialBlockSize;

    void FreeObject(T* object)
    {
        m_kAvailableObjects.Add(object);
    }
};

extern ObjectPool<D3DRenderStateGroup, NiTNewInterface<D3DRenderStateGroup> >* DAT_0126f718;
extern ObjectPool<D3DRenderStateGroup::NiD3DRenderStateEntry, NiTNewInterface<D3DRenderStateGroup::NiD3DRenderStateEntry> >* DAT_0126f71c;

// @fnv 0x00e7f6b0
void D3DRenderStateGroup::ReleaseRenderStateGroup(D3DRenderStateGroup* group)
{
    if (!group)
        return;

    if (group->m_bHasBeenApplied)
    {
        NiD3DRenderStateEntry* entry = group->m_pkRenderStateEntries;
        while (entry)
        {
            NiD3DRenderStateEntry* next = entry->m_pkNext;
            DAT_0126f71c->FreeObject(entry);
            entry = next;
        }
        group->m_pkRenderStateEntries = 0;
        group->m_uiRenderStateEntryCount = 0;

        entry = group->m_pkFreeEntries;
        while (entry)
        {
            NiD3DRenderStateEntry* next = entry->m_pkNext;
            DAT_0126f71c->FreeObject(entry);
            entry = next;
        }
        group->m_pkFreeEntries = 0;
        group->m_uiFreeEntryCount = 0;
        DAT_0126f718->FreeObject(group);
    }
    else
    {
        delete group;
    }
}
