#include "../../../../../../include/hkArray.h"

// src/havok/physics/dynamics/world/broadphaseborder/hkpbroadphaseborder.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/broadphaseborder/hkpbroadphaseborder.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/hkReferencedObject.h"

// @fnv 0x00d0b5d0
int __cdecl CompareByOffsetD4(const void* apFirst, const void* apSecond)
{
    return *(const char**)((const char*)apFirst + 0xd4) < *(const char**)((const char*)apSecond + 0xd4);
}

struct Item : hkReferencedObject
{
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    void removePhantomOverlapListener_00d07c80(void* owner);
};
struct Manager
{
    void hkpWorld_removePhantomBatch(Item** entries, int count);
};
struct Collection
{
    virtual void slot00();
    virtual void removeItems(Manager* manager);
};
struct AllocatorOwner
{
    int unk00;
    int unk04;
    Collection collection;
    int unk0C;
    int unk10;
    Manager* manager;
    Item* entries[6];
    void ReleaseEntries();
};
// @fnv 0x00d0b570
void AllocatorOwner::ReleaseEntries()
{
    if (manager == 0)
        return;
    manager->hkpWorld_removePhantomBatch(entries, 6);
    Item** pEntry = entries;
    void* owner = &unk0C;
    int count = 6;
    do
    {
        (*pEntry)->removePhantomOverlapListener_00d07c80(owner);
        (*pEntry)->removeReference();
        *pEntry = 0;
        ++pEntry;
        --count;
    } while (count != 0);
    collection.removeItems(manager);
    manager = 0;
}

struct DispatchItem;
struct DispatchOwner
{
    void ProcessTarget(bool*, DispatchItem*);
};
struct DispatchItem
{
    unsigned int unknown00;
    unsigned int unknown04;
    DispatchOwner* owner;
    void hkpRigidBody_setMotionType(unsigned char, unsigned char, unsigned char);
};
struct Dispatcher
{
    unsigned int unknown00;
    unsigned int unknown04;
    unsigned int unknown08;
    unsigned int unknown0c;
    unsigned int unknown10;
    DispatchOwner* owner;
    unsigned int unknown18;
    unsigned int unknown1c;
    unsigned int unknown20;
    unsigned int unknown24;
    unsigned int unknown28;
    unsigned int unknown2c;
    int mode;
    void DispatchItemByMode(DispatchItem* item);
};
// Switches on mode: for modes 0 and 1 calls item->FUN_00ca8420(5,1,0); for mode 2, if item->owner equals owner, calls owner->ProcessTarget(&success, item).
// @fnv 0x00d0b5f0
void Dispatcher::DispatchItemByMode(DispatchItem* item)
{
    switch (mode)
    {
    case 0:
        item->hkpRigidBody_setMotionType(5, 1, 0);
        break;
    case 1:
        item->hkpRigidBody_setMotionType(5, 1, 0);
        break;
    case 2:
        if (item->owner == owner)
        {
            bool success;
            owner->ProcessTarget(&success, item);
        }
        break;
    }
}

template <typename T> inline void S_00e10760_swap(T& x, T& y)
{
    T t = x;
    x = y;
    y = t;
}
struct S_00e10760_Item;
typedef bool (*S_00e10760_Less)(S_00e10760_Item* a, S_00e10760_Item* b);

// Sorts the range [d, h] of pArr in place using a Hoare-partition quicksort with cmpLess, recursing on the left part and looping on the right.
// @fnv 0x00e10760
// src: XBOX_PDB 0x00e10760
void hkAlgorithm_quickSortRecursive_hkMonitorStreamAnalyzerPrintByTypeInfo_bool_cdecl_hkMonitorStreamAnalyzerPrintByTypeInfo_const_hkMonitorStreamAnalyzerPrintByTypeInfo_const(S_00e10760_Item** apItems, int aiLow, int aiHigh, S_00e10760_Less apLess)
{
    int i, iRight;
    __declspec(align(16)) S_00e10760_Item* pPivot;
begin:
    iRight = aiHigh;
    i = aiLow;
    pPivot = apItems[(aiLow + aiHigh) >> 1];
    do
    {
        while (apLess(apItems[i], pPivot))
        {
            i++;
        }
        while (apLess(pPivot, apItems[iRight]))
        {
            iRight--;
        }
        if (i <= iRight)
        {
            if (iRight != i)
            {
                S_00e10760_swap(apItems[iRight], apItems[i]);
            }
            iRight--;
            i++;
        }
    } while (i <= iRight);
    if (aiLow < iRight)
    {
        hkAlgorithm_quickSortRecursive_hkMonitorStreamAnalyzerPrintByTypeInfo_bool_cdecl_hkMonitorStreamAnalyzerPrintByTypeInfo_const_hkMonitorStreamAnalyzerPrintByTypeInfo_const(apItems, aiLow, iRight, apLess);
    }
    if (i < aiHigh)
    {
        aiLow = i;
        goto begin;
    }
}

struct OwnerDest
{
    void hkpWorld_removeWorldDeletionListener(void* p);
    void ClearValue(void* p);
};

struct FUN_00d0b530_cls
{
    int unk00;
    int unk04;
    int unk08;
    OwnerDest* m_0C;

    void hkpBroadPhaseBorder_worldDeletedCallback(int unused);
};

// @fnv 0x00d0b530
// src: HAVOK_LIB 0x00d0b530
void FUN_00d0b530_cls::hkpBroadPhaseBorder_worldDeletedCallback(int unused)
{
    m_0C->hkpWorld_removeWorldDeletionListener(((char*)this - 8) ? (void*)this : 0);
    m_0C->ClearValue(((char*)this - 8) ? (void*)((char*)this + 8) : 0);
    ((hkReferencedObject*)((char*)this - 8))->removeReference();
}

struct D0B630Entity;

int __cdecl CompareByOffsetD4(const void* a, const void* b);
void __cdecl hkAlgorithm_quickSortRecursive_hkMonitorStreamAnalyzerPrintByTypeInfo_bool_cdecl_hkMonitorStreamAnalyzerPrintByTypeInfo_const_hkMonitorStreamAnalyzerPrintByTypeInfo_const(D0B630Entity** data, int lo, int hi, int(__cdecl* cmp)(const void*, const void*));
void __cdecl hkReferencedObject_removeReferences(D0B630Entity** objects, int numObjects, int strideInBytes);

class D0B630Primary
{
  public:
    virtual void vfunc00();
    virtual void vfunc04();
    virtual void vfunc08();
    virtual void entityAdded(D0B630Entity* entity);

    int unk04;
    int unk08;
    int unk0C;
};

class D0B630Secondary
{
  public:
    virtual void FlushDeferredEntities(const void* event);
};

class D0B630Collector : public D0B630Primary, public D0B630Secondary
{
  public:
    virtual void FlushDeferredEntities(const void* event);

    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    D0B630Entity** m_deferred;
    int m_numDeferred;
};

// @fnv 0x00d0b630
void D0B630Collector::FlushDeferredEntities(const void* event)
{
    if (m_numDeferred)
    {
        if (m_numDeferred > 1)
            hkAlgorithm_quickSortRecursive_hkMonitorStreamAnalyzerPrintByTypeInfo_bool_cdecl_hkMonitorStreamAnalyzerPrintByTypeInfo_const_hkMonitorStreamAnalyzerPrintByTypeInfo_const(m_deferred, 0, m_numDeferred - 1, CompareByOffsetD4);
        for (int i = 0; i < m_numDeferred; i++)
            entityAdded(m_deferred[i]);
        hkReferencedObject_removeReferences(m_deferred, m_numDeferred, sizeof(D0B630Entity*));
        m_numDeferred = 0;
    }
}

extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance();
void __cdecl ResizeAudioStream(void* alloc, void* array, int sizeElem);

struct D0B6A0Collidable
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    signed char m_iOwnerOffset;
    char unk11;
    char unk12;
    char unk13;
    int unk14;
    unsigned char m_type;

    void* getOwner() const
    {
        return const_cast<char*>(reinterpret_cast<const char*>(this)) + m_iOwnerOffset;
    }
};

struct D0B6A0Event
{
    int unk00;
    const D0B6A0Collidable* m_kCollidable;
};

static __forceinline void D0B6A0EntityArray_construct(hkReferencedObject** p, int n, hkReferencedObject* const& e)
{
        for (int i = 0; i < n; i++)
            p[i] = e;
    }

static __forceinline void D0B6A0EntityArray_AddBack(hkArrayBase<hkReferencedObject*>& self, hkReferencedObject* const& e)
{
        hkMemoryRouter& holder = hkMemoryRouter_getInstance();
        if (self.m_iElementCount == self.getCapacity())
            ResizeAudioStream(holder.m_heap, (&self), sizeof(hkReferencedObject*));
        D0B6A0EntityArray_construct(self.m_data + self.m_iElementCount, 1, e);
        self.m_iElementCount++;
    }

class D0B6A0Primary
{
  public:
    virtual void vfunc00();
    virtual void vfunc04();
    virtual void vfunc08();
    virtual void entityAdded(hkReferencedObject* entity);

    int unk04;
    int unk08;
};

class D0B6A0Secondary
{
  public:
    virtual void HandleEvent(const D0B6A0Event& event);
};

class D0B6A0Collector : public D0B6A0Primary, public D0B6A0Secondary
{
  public:
    virtual void HandleEvent(const D0B6A0Event& event);

    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    bool m_deferAdds;
    hkArrayBase<hkReferencedObject*> m_deferredEntities;
};

// Handles an event: if the collidable's m_type is 1, gets its owner entity and either defers it into m_deferredEntities or calls entityAdded.
// @fnv 0x00d0b6a0
void D0B6A0Collector::HandleEvent(const D0B6A0Event& event)
{
    const D0B6A0Collidable* collidable = event.m_kCollidable;
    if (collidable->m_type == 1)
    {
        hkReferencedObject* entity = static_cast<hkReferencedObject*>(collidable->getOwner());
        if (entity)
        {
            if (m_deferAdds)
            {
                D0B6A0EntityArray_AddBack(m_deferredEntities, entity);
                entity->addReference();
            }
            else
            {
                entityAdded(entity);
            }
        }
    }
}

class BSAudio;
namespace fnv_00d0bb20 {

BSAudio* __cdecl hkMemoryRouter_getInstance();

extern int DAT_010cd3c4;
extern int DAT_010cd3b4;
extern int DAT_010cd3a4;
extern int DAT_010cd394;
extern int DAT_010ccf7c;
extern int DAT_010c925c;
extern int DAT_010cb1c4;
extern int DAT_0102e388;

struct FUN_00d0bb20_cls
{
    int m_vptr00;
    int unk04;
    int m_vptr08;
    int m_vptr0c;
    int m_vptr10;
    int unk14;
    hkReferencedObject* m_entries[6];
    int unk30;
    int unk34;
    void* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapBits;

    void Destroy();
};

static inline void ResetBaseVptrs(int* vptrs)
{
    vptrs[4] = (int)&DAT_010ccf7c;
    vptrs[3] = (int)&DAT_010c925c;
    vptrs[2] = (int)&DAT_010cb1c4;
    vptrs[0] = (int)&DAT_0102e388;
}

// @fnv 0x00d0bb20
void FUN_00d0bb20_cls::Destroy()
{
    m_vptr00 = (int)&DAT_010cd3c4;
    m_vptr08 = (int)&DAT_010cd3b4;
    m_vptr0c = (int)&DAT_010cd3a4;
    m_vptr10 = (int)&DAT_010cd394;
    hkReferencedObject** pEntry = m_entries;
    int i = 6;
    do
    {
        if (*pEntry != 0)
        {
            (*pEntry)->removeReference();
            *pEntry = 0;
        }
        pEntry++;
        i--;
    } while (i != 0);
    hkMemoryRouter* pAudioHolder = (hkMemoryRouter*)hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAudioAllocator = reinterpret_cast<hkMemoryAllocator*>(pAudioHolder->m_heap);
    m_iArrayLength = i;
    unsigned int uiCapBits = m_uCapBits;
    if ((uiCapBits & 0x80000000u) == 0)
    {
        // This allocator uses virtual slot 0x10; the shared declaration is nonvirtual.
        typedef void (__thiscall* FreeArrayFunction)(hkMemoryAllocator*, void*, unsigned int);
        FreeArrayFunction* vtable = *reinterpret_cast<FreeArrayFunction**>(pAudioAllocator);
        vtable[4](pAudioAllocator, m_pData, (uiCapBits & 0x3fffffffu) * 4);
    }
    unsigned int* puiCap = &m_uCapBits;
    m_pData = 0;
    *puiCap = 0x80000000u;
    m_vptr10 = (int)&DAT_010ccf7c;
    m_vptr0c = (int)&DAT_010c925c;
    m_vptr08 = (int)&DAT_010cb1c4;
    m_vptr00 = (int)&DAT_0102e388;
}
}  // namespace fnv_00d0bb20

// @fnv 0x00d0b520
// src: COMMUNITY 0x00d0b520
void __stdcall nullsub_65(int)
{}

// hkpBroadPhaseBorder (the RTTI name in the image) has one primary base and
// several secondary bases; all of them declare the same virtual function and
// the border class overrides it.  MSVC 2008 builds a per-base vftable for
// every secondary base, and the slot of the overridden virtual points at a
// compiler generated adjustor thunk that moves `this' from the secondary base
// back to the border object.  This is the thunk of the base that sits eight
// bytes into the object, so it steps `this' back by eight and jumps to the
// overriding implementation.
//
// The virtual itself is deliberately left undefined: the thunk then jumps to
// an undefined external just like in the image, and the checker resolves that
// relocation from the original bytes instead of comparing a second function.
struct hkBroadPhasePrimary
{
    hkBroadPhasePrimary();
    virtual void AdjustThisAndForward_00d0bbc0(int flag);
    int unk04;
};

struct hkBroadPhaseSecondary
{
    hkBroadPhaseSecondary();
    virtual void AdjustThisAndForward_00d0bbc0(int flag);
};

struct hkBroadPhaseBorder : public hkBroadPhasePrimary, public hkBroadPhaseSecondary
{
    hkBroadPhaseBorder();
// @fnv 0x00d0bbc0
// src: GUESS 0x00d0bbc0 (confidence: low)
    virtual void AdjustThisAndForward_00d0bbc0(int flag);
};

hkBroadPhasePrimary::hkBroadPhasePrimary()
{}
hkBroadPhaseSecondary::hkBroadPhaseSecondary()
{}
hkBroadPhaseBorder::hkBroadPhaseBorder() : hkBroadPhasePrimary(), hkBroadPhaseSecondary()
{}

// sub ecx,0x10; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x10).
struct PrimaryBase
{
    virtual void AdjustThisAndForward_00d0bbe0();
    int unk04;
    int unk08;
    int unk0C;
};

struct SecondaryBase
{
    virtual void AdjustThisAndForward_00d0bbe0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d0bbe0
// src: GUESS 0x00d0bbe0 (confidence: low)
    virtual void AdjustThisAndForward_00d0bbe0();
};

Derived::Derived()
{}

namespace fnv_00d0bbf0 {
struct Allocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Deallocate(void*, unsigned short);
};

struct Manager
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Allocator* allocator;
};

extern "C" Manager* __cdecl hkMemoryRouter_getInstance();

struct FUN_00d0bbf0
{
    __declspec(noinline) virtual ~FUN_00d0bbf0();
    unsigned short unk04;
    unsigned short unk06;
    void* unk08;
    void* unk0c;
    int unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2c;
    static void operator delete(void* object)
    {
        Manager* manager = hkMemoryRouter_getInstance();
        manager->allocator->Deallocate(object, ((FUN_00d0bbf0*)object)->unk04);
    }
};

// Empty destructor; the class's operator delete returns the block to the allocator using the size stored in unk04.
// @fnv 0x00d0bbf0
FUN_00d0bbf0::~FUN_00d0bbf0()
{}
}  // namespace fnv_00d0bbf0

struct BorderDeletePrimary : D0B6A0Primary
{
    virtual void* FUN_00d0bbd0(unsigned int flags);
};

struct BorderDeleteSecondary
{
    virtual void* FUN_00d0bbd0(unsigned int flags);
};

struct BorderDelete : BorderDeletePrimary, BorderDeleteSecondary
{
    BorderDelete();
// @fnv 0x00d0bbd0
    virtual void* FUN_00d0bbd0(unsigned int flags);
};

BorderDelete::BorderDelete()
{}
