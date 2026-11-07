
// src/havok/physics/utilities/visualdebugger/viewer/collide/hkptoicountviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/collide/hkptoicountviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/BSAudio.h"
#include "../../../../../../../include/NiPoint3.h"
#include "../../../../../../../include/hkpContactListener.h"
#include "../../../../../../../include/hkpEntityListener.h"
#include "../../../../../../../include/hkpWorldPostSimulationListener.h"


// @fnv 0x00d60b90
void __stdcall ClearTwoInts(int* piFirst, int* piSecond)
{
    *piFirst = 0;
    *piSecond = 0;
}

extern int g_D67960Value;

// @fnv 0x00d67960
// src: GUESS 0x00d67960 (confidence: low)
int __cdecl Object_GetG_D67960Value_00d67960()
{
    return g_D67960Value;
}

struct Item;
struct Sink
{
    void removeEntityListener_00c9c670(Item*);
};
struct Link
{
    void hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_remove(Sink*);
};
struct Item
{
    int value;
    Link link;
    void ProcessState_00d67bc0(Sink*);
};
struct Prefix
{
    float x, y, z, w;
    float ax, ay, az, aw;
    float bx, by, bz, bw;
};
struct Derived : Prefix, Item
{
};
// @fnv 0x00d67bc0
// src: GUESS 0x00d67bc0 (confidence: low)
void Item::ProcessState_00d67bc0(Sink* sink)
{
    sink->removeEntityListener_00c9c670(static_cast<Item*>(reinterpret_cast<Derived*>(reinterpret_cast<char*>(this) - sizeof(Prefix))));
    link.hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_remove(sink);
}

class PrimaryBase
{
  public:
    virtual void primary0();
    int flags;
};
class ProcessBase
{
  public:
    virtual void process0();
    virtual void process1();
    virtual void process2();
    virtual void process3();
    virtual void process4();
    virtual void process5();
    virtual void process6();
    int unk04, unk08, unk0C, unk10, unk14;
};
class WorldListener
{
  public:
    virtual void world0();
    virtual void world1();
    virtual void world2();
    int unk04;
};
class FUN_00ddccb0 : public PrimaryBase, public ProcessBase, public WorldListener
{
  public:
    FUN_00ddccb0(int);
};
struct CountArray
{
    int* data;
    int size;
    int capacity;
    CountArray() : data(0), size(0), capacity(-1)
    {}
    __declspec(nothrow) void EnsureCapacity(void*, int);
};
__declspec(nothrow) hkMemoryRouter* hkMemoryRouter_getInstance();
class FUN_00d67ce0 : public FUN_00ddccb0,
                     public hkpContactListener,
                     public hkpWorldPostSimulationListener,
                     public hkpEntityListener
{
  public:
    virtual void primary0();
    virtual void primary1();
    virtual void primary2();
    virtual void process0();
    virtual void process1();
    virtual void process2();
    virtual void process3();
    virtual void process4();
    virtual void process5();
    virtual void process6();
    virtual void world0();
    virtual void world1();
    virtual void world2();
    virtual void contact0();
    virtual void contact1();
    virtual void contact2();
    virtual ~FUN_00d67ce0() throw();
    virtual void postSimulationCallback(hkpWorld*);
    virtual void EntityRemovalCallback(hkpEntity*);
    virtual void EntityAddedCallback(hkpEntity*);
    virtual void EntityRemovedCallback(hkpEntity*);
    virtual void EntityShapeSetCallback(hkpEntity*);
    virtual void entitySetMotionTypeCallback(hkpEntity*);
    virtual void EntityDeletionCallback(hkpEntity*);
    CountArray counts;
    FUN_00d67ce0(int context);
};

// Constructs the object via FUN_00ddccb0 and initializes counts from the allocator returned by FUN_00c85750.
// @fnv 0x00d67ce0
FUN_00d67ce0::FUN_00d67ce0(int context) : FUN_00ddccb0(context)
{
    hkMemoryRouter* audio = hkMemoryRouter_getInstance();
    counts.EnsureCapacity(audio->m_heap, 0);
}

namespace fnv_00d67d60 {
extern void* hkMemoryRouter_getInstance();
struct hkpToiCountViewer
{
    void* vtable;
    unsigned short size;
    unsigned short unk06;
    hkpToiCountViewer* __thiscall FUN_00d67ce0(unsigned int);
};
// Allocates a 0x40-byte hkpToiCountViewer from the global heap, initializes it with arg, and returns a pointer 8 bytes into it or null.
// @fnv 0x00d67d60
void* __cdecl AllocateToiCountViewer(unsigned int arg)
{
    hkMemoryRouter* global = (hkMemoryRouter*)hkMemoryRouter_getInstance();
    hkpToiCountViewer* pViewer = (hkpToiCountViewer*)reinterpret_cast<hkMemoryAllocator*>(global->m_heap)->blockAlloc(0x40);
    pViewer->size = 0x40;
    pViewer = pViewer->FUN_00d67ce0(arg);
    if (pViewer)
        return (char*)pViewer + 8;
    return 0;
}
}  // namespace fnv_00d67d60

void* AllocateToiCountViewer();

struct S_00d67e10_Registry
{
    int Register(const char* name, void* (*create)());
};

extern S_00d67e10_Registry* g_00d67e10_registry;
extern int g_00d67e10_toiCounterId;

// @fnv 0x00d67e10
void RegisterToiCounter()
{
    g_00d67e10_toiCounterId = g_00d67e10_registry->Register("TOI counter", AllocateToiCountViewer);
}

__declspec(nothrow) hkMemoryRouter* hkMemoryRouter_getInstance();


struct ItemList
{
    char pad[0x6c];
    void** items;
    int count;
};

struct BaseP
{
    virtual void p0();
    int p4;
};
struct BaseQ
{
    virtual void q0();
    char q[0x14];
};
struct BaseC
{
    virtual void c0();
    ItemList* list;
    __declspec(nothrow) void Remove(void* item);
};

struct Base0 : BaseP, BaseQ, BaseC
{
    ~Base0();
};

struct Iface1
{
    virtual void i1();
    ~Iface1()
    {}
};
struct Iface2
{
    virtual void i2();
    ~Iface2()
    {}
};
struct Iface3
{
    virtual void i3();
    ~Iface3()
    {}
};

struct MemberBase
{
    __declspec(nothrow) ~MemberBase();
    int m[4];
};
struct Member : MemberBase
{
    __declspec(nothrow) void Release(void* heap);
    ~Member()
    {
        Release(hkMemoryRouter_getInstance()->m_heap);
    }
};

struct FUN_00d67fa0 : Base0, Iface1, Iface2, Iface3
{
    Member member;
    ~FUN_00d67fa0();
    virtual void p0();
};

// Destructor that removes every item in the list from the owning container before base destruction.
// @fnv 0x00d67fa0
FUN_00d67fa0::~FUN_00d67fa0()
{
    for (int i = 0; list && i < list->count; ++i)
        Remove(list->items[i]);
}

struct EntryListNode
{
    void** entries;
    int count;
};
struct Node
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    EntryListNode entries;
};
struct Query
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    NiPoint3 direction;
    int unk1c;
    Node* direct;
    int unk24;
    Node** groups;
    int groupCount;
};
struct BaseHelper
{
    void hkpToiCountViewer_displayCountForBody(void* entry, int mode);
};
int __cdecl Object_GetSignedLargestComponentIndex(float* direction);
struct Context
{
    void ProcessQuery(Query* query);
};
// Computes a mode from the query direction, then dispatches each group entry and each direct entry to FUN_00d68030 with that mode.
// @fnv 0x00d68130
void Context::ProcessQuery(Query* query)
{
    int mode = Object_GetSignedLargestComponentIndex(&query->direction.x);
    for (int groupIndex = 0; groupIndex < query->groupCount; ++groupIndex)
    {
        EntryListNode* list = &query->groups[groupIndex]->entries;
        for (int entryIndex = 0; entryIndex < list->count; ++entryIndex)
            ((BaseHelper*)((char*)this - 0x2c))->hkpToiCountViewer_displayCountForBody(list->entries[entryIndex], mode);
    }
    EntryListNode* list = &query->direct->entries;
    for (int entryIndex = 0; entryIndex < list->count; ++entryIndex)
        ((BaseHelper*)((char*)this - 0x2c))->hkpToiCountViewer_displayCountForBody(list->entries[entryIndex], mode);
}

struct FUN_00d67970_helper
{
    void __thiscall c93920(void* value);
    void __thiscall c93a20(void* value);
};

struct FUN_00d67970_class
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;

    void __thiscall hkpToiCountViewer_worldAddedCallback(FUN_00d67970_helper* helper);
};

// Passes pointers to this object's unk0c and unk08 fields to the helper's c93920 and c93a20 methods, or null if the base pointer is null.
// @fnv 0x00d67970
// src: HAVOK_LIB 0x00d67970
void __thiscall FUN_00d67970_class::hkpToiCountViewer_worldAddedCallback(FUN_00d67970_helper* helper)
{
    void* base = reinterpret_cast<char*>(this) - 0x20;
    void* value;

    if (base)
        value = &unk0c;
    else
        value = 0;

    helper->c93920(value);

    if (base)
        value = &unk08;
    else
        value = 0;

    helper->c93a20(value);
}

struct OwnerBinding
{
    void Bind(void* owner);
};

struct SubLink
{
    int unk00;
    void Attach(int* p);
};

struct FUN_00d67b90_cls
{
    int unk00;
    SubLink m_sub;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;

    void BindAndAttach(int* arg);
};

// @fnv 0x00d67b90
void FUN_00d67b90_cls::BindAndAttach(int* arg)
{
    FUN_00d67b90_cls* owner = ((char*)this - 0x30) != 0 ? this : 0;
    ((OwnerBinding*)arg)->Bind(owner);
    m_sub.Attach(arg);
}

struct ListItem;

struct ItemVisitor
{
    virtual void v0();
    virtual void v1(void* item);
};

struct ItemNode
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34,
        unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68;
    ListItem** m_items;  // +0x6c
    int m_uiItemCount;   // +0x70
};

struct FUN_00d67bf0_cls
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14;
    ItemVisitor m_visitor;        // +0x18
    ItemNode* m_pReferencedNode;  // +0x1c

    void VisitItems();
};

// Iterates the node's items up to its count, passing each to m_visitor.v1, stopping early if the node becomes null.
// @fnv 0x00d67bf0
void FUN_00d67bf0_cls::VisitItems()
{
    int i = 0;
    ItemNode* node = m_pReferencedNode;
    if (node != 0)
    {
        do
        {
            if (i >= node->m_uiItemCount)
                break;
            ListItem* item = node->m_items[i];
            m_visitor.v1(item);
            node = m_pReferencedNode;
            ++i;
        } while (node != 0);
    }
}

struct SpawnedObject;

struct Entry
{
    SpawnedObject* obj;
    unsigned int unk04;
};

struct SpawnedObject
{
    unsigned int unk00;
    unsigned int unk04;
    SpawnedObject* m_08;
    void removeEntityListener_00c9c670(void* listener) throw();
    void hkpWorld_removeContactListener(void* listener) throw();
    void ClearValue(void* listener) throw();
};


hkMemoryRouter* hkMemoryRouter_getInstance() throw();

void __cdecl ResizeAudioStream(void* a, void* arr, unsigned int size) throw();

// Exe 0x00d67e30: unit-local Map view; declarations and layout are preserved.
struct HkptoicountviewerMapView
{
    Entry* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_hashModMask;

    int GetFirstIterator() const
    {
        int i = 0;
        for (; i <= m_hashModMask; ++i)
        {
            if (m_kPrimitiveElement[i].obj != (SpawnedObject*)-1)
                break;
        }
        return i;
    }

    int getNext(int it) const
    {
        int i = it + 1;
        for (; i <= m_hashModMask; ++i)
        {
            if (m_kPrimitiveElement[i].obj != (SpawnedObject*)-1)
                break;
        }
        return i;
    }

    bool isValid(int it) const
    {
        return it <= m_hashModMask;
    }

    void hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_remove(SpawnedObject* o) throw();
};

struct Array
{
    SpawnedObject** m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void clear()
    {
        hkMemoryRouter* h = hkMemoryRouter_getInstance();
        hkMemoryAllocator* al = reinterpret_cast<hkMemoryAllocator*>(h->m_heap);
        int cap = m_iCapacityState;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
        {
            al->bufFree(m_data, (cap & 0x3fffffff) * 4);
        }
    }
};

class FUN_00d67e30_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    HkptoicountviewerMapView m_14;

    void RemoveEntriesForObject(SpawnedObject* a1);
};

// @fnv 0x00d67e30
void FUN_00d67e30_cls::RemoveEntriesForObject(SpawnedObject* a1)
{
    Array out;
    out.m_data = 0;
    out.m_iElementCount = 0;
    out.m_iCapacityState = 0x80000000;

    for (int it = m_14.GetFirstIterator(); m_14.isValid(it); it = m_14.getNext(it))
    {
        SpawnedObject* obj = m_14.m_kPrimitiveElement[it].obj;
        if (obj->m_08 == a1)
        {
            hkMemoryRouter* h = hkMemoryRouter_getInstance();
            if (out.m_iElementCount == (int)(out.m_iCapacityState & 0x3fffffffu))
            {
                ResizeAudioStream(h->m_heap, &out, 4);
            }
            out.m_data[out.m_iElementCount] = obj;
            out.m_iElementCount++;
        }
    }

    int size = out.m_iElementCount;
    for (int iMatch = 0; iMatch < size; iMatch++)
    {
        SpawnedObject** it = &out.m_data[iMatch];
        (*it)->removeEntityListener_00c9c670((char*)this - 0x20 != 0 ? (void*)((char*)this + 0x10) : 0);
        m_14.hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_remove(*it);
    }

    out.clear();

    a1->hkpWorld_removeContactListener((char*)this - 0x20 != 0 ? (void*)((char*)this + 8) : 0);
    a1->ClearValue((char*)this - 0x20 != 0 ? (void*)((char*)this + 0xc) : 0);
}

#include <xmmintrin.h>
extern const __m128 DAT_01017d10;

__declspec(align(16)) struct SquaredLanes
{
    float m_uiX;
    float m_uiY;
    float m_uiZ;
    float m_w;
};

// Finds the index of the largest squared component of a vector and returns it offset by 3 if the original component is positive.
// @fnv 0x00d679c0
// src: GUESS 0x00d679c0 (confidence: medium)
int __cdecl Object_GetSignedLargestComponentIndex(const __m128* apVector)
{
    __m128 vSquared = _mm_and_ps(_mm_mul_ps(*apVector, *apVector), DAT_01017d10);
    SquaredLanes lanes;
    _mm_store_ps((float*)&lanes, vSquared);

    int idx;
    if (lanes.m_uiX < lanes.m_uiY)
    {
        idx = (lanes.m_uiZ > lanes.m_uiY) ? 2 : 1;
    }
    else
    {
        idx = (lanes.m_uiZ > lanes.m_uiX) ? 2 : 0;
    }

    int positive = ((const float*)apVector)[idx] > 0.0f ? 1 : 0;
    return idx + positive * 3;
}

struct PtrMapEntryObj
{
    void removeEntityListener_00c9c670(void* arg);
};

struct PtrMapEntry
{
    PtrMapEntryObj* m_pKey;
    int m_iValue;
};

struct PtrMapStorage
{
    PtrMapEntry* m_pEntries;
    int unk04;
    int m_iArrayLength;

    void clear();
};

struct FUN_00d67da0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int m_i30;
    PtrMapStorage m_kStorage;

    void hkpToiCountViewer_reset();
};

// Walks m_kStorage entries with a key other than -1, calls FUN_00c9c670 on each key with the address of m_i30, then calls m_kStorage.clear().
// @fnv 0x00d67da0
// src: HAVOK_LIB 0x00d67da0
void FUN_00d67da0_cls::hkpToiCountViewer_reset()
{
    PtrMapStorage* st = &m_kStorage;
    int i = 0;
    PtrMapEntry* e;
    if (st->m_iArrayLength >= 0)
    {
        e = st->m_pEntries;
        do
        {
            if (e->m_pKey != (PtrMapEntryObj*)-1)
            {
                break;
            }
            i++;
            e++;
        } while (i <= st->m_iArrayLength);
    }
    if (i <= m_kStorage.m_iArrayLength)
    {
        do
        {
            st->m_pEntries[i].m_pKey->removeEntityListener_00c9c670(&m_i30);
            int j = i + 1;
            int n = st->m_iArrayLength;
            if (j <= n)
            {
                e = st->m_pEntries + j;
                do
                {
                    if (e->m_pKey != (PtrMapEntryObj*)-1)
                    {
                        break;
                    }
                    j++;
                    e++;
                } while (j <= n);
            }
            i = (j <= n) ? j : j;
        } while (i <= m_kStorage.m_iArrayLength);
    }
    st->clear();
}



struct BSAudioString
{
    char* m_data;
    int m_fRestLength;
    int m_pRayCursor;
    int buffer00, buffer04, buffer08, buffer0c;
    int buffer10, buffer14, buffer18, buffer1c;
    int buffer20, buffer24, buffer28, buffer2c;
    int buffer30, buffer34, buffer38, buffer3c;
    int buffer40, buffer44, buffer48, buffer4c;
    int buffer50, buffer54, buffer58, buffer5c;
    int buffer60, buffer64, buffer68, buffer6c;
    int buffer70, buffer74, buffer78, buffer7c;

    BSAudioString();
    void Format(const char* format, ...);

    void Release()
    {
        hkMemoryAllocator* allocator = (hkMemoryAllocator*)hkMemoryRouter_getInstance()->m_temp;
        m_fRestLength = 0;
        if ((m_pRayCursor & 0x80000000) == 0)
            allocator->bufFree(m_data, m_pRayCursor & 0x3fffffff);
    }
};

struct BSAudioValue
{
    unsigned char m_flags;
    BSAudioValue() : m_flags(1)
    {}
    BSAudioValue(const BSAudioValue& other) : m_flags(other.m_flags)
    {}
};

struct BSAudioNotifier
{
    virtual void v0();
    virtual int v1();
};

struct ContactEntry
{
    int unk00;
    unsigned int m_flags;
};

struct ContactTable
{
    ContactEntry* m_entries;
    int m_iElementCount;
    int m_pRayCursor;
    int Find(const void* key);
};

struct ContactViewer
{
    int unk00;
    int unk04;
    BSAudioNotifier m_notifier;
    int unk0c;
    int unk10;
    int unk14;
    int m_18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    ContactTable m_table;

    void hkpToiCountViewer_displayCountForBody(void* entry, int mode);
};

extern void __cdecl HkptoicountviewerGsEhscNogsNoehsc_UpdateState_00d67a50(int owner, int id, void* entry, int mode, const char* name, unsigned int info,
                                 float value, BSAudioValue flags);

// @fnv 0x00d68030
// src: HAVOK_LIB 0x00d68030
void ContactViewer::hkpToiCountViewer_displayCountForBody(void* entry, int mode)
{
    unsigned int index = m_table.Find(entry);
    if ((int)index > m_table.m_pRayCursor)
        return;
    unsigned int flags = m_table.m_entries[index].m_flags;
    unsigned int tag = flags >> 0x18;
    BSAudioString name;
    if (tag != 0)
        name.Format("%d(%d)", flags & 0xffffff, tag);
    else
        name.Format("%d", flags & 0xffffff);
    HkptoicountviewerGsEhscNogsNoehsc_UpdateState_00d67a50(m_18, m_notifier.v1(), entry, mode, name.m_data, 0xff800000u, 0.1f, BSAudioValue());
    m_table.m_entries[index].m_flags = flags & 0xffffff;
    name.Release();
}

struct D681E0Primary
{
    virtual void vfunc00();
    virtual void AdjustThisAndForward_00d681e0();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

struct D681E0Secondary
{
    virtual void AdjustThisAndForward_00d681e0();
};

struct D681E0Object : D681E0Primary, D681E0Secondary
{
    D681E0Object();

// @fnv 0x00d681e0
// src: GUESS 0x00d681e0 (confidence: low)
    virtual void AdjustThisAndForward_00d681e0();
};

D681E0Object::D681E0Object()
{}

// FUN_00d68200: thiscall adjustor thunk (sub ecx,0x28; jmp FUN_00d68230).
// Written as multiple inheritance: the primary base is 0x28 bytes (vptr + 9 ints),
// so the secondary base sits at +0x28 and MSVC emits the this-adjusting thunk.
struct AdjPrimaryBase
{
    virtual void AdjustThisAndForward_00d68200();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
};

struct AdjSecondaryBase
{
    virtual void AdjustThisAndForward_00d68200();
};

struct AdjDerived : AdjPrimaryBase, AdjSecondaryBase
{
    AdjDerived();
// @fnv 0x00d68200
// src: GUESS 0x00d68200 (confidence: low)
    virtual void AdjustThisAndForward_00d68200();
};

AdjDerived::AdjDerived()
{}

namespace fnv_00d68230 {


hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();

struct FUN_00d68230
{
    unsigned short m_u04;
    unsigned short m_u06;
    FUN_00d68230();
    virtual ~FUN_00d68230();
    static void operator delete(void* apMemory)
    {
        hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
        unsigned int uiSize = ((FUN_00d68230*)apMemory)->m_u04;
        hkMemoryAllocator* pAllocator = (hkMemoryAllocator*)pHolder->m_heap;
        pAllocator->blockFree(apMemory, uiSize);
    }
};

// Constructs the object, zeroing m_u04 and m_u06.
// @fnv 0x00d68230
FUN_00d68230::FUN_00d68230()
{
    m_u04 = 0;
    m_u06 = 0;
}
}  // namespace fnv_00d68230

namespace fnv_00d67c30 {
extern "C" hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
extern "C" char DAT_01000001;
extern "C" char DAT_00ffffff;

struct Entry
{
    int unk00;
    unsigned int m_flags;
};

struct Table
{
    Entry* m_entries;
    int unk04;

    int FindIndex(int aKey);
    void Attach(int aOwner, int aKey, int aTag);
};

struct Item
{
    void Apply(int aValue);
};

struct ArgBlock
{
    int unk00;
    int m_items[2];
    int unk0c;
    int unk10;
};


struct FUN_00d67c30_cls
{
    int unk00;
    int unk04;
    int unk08;
    Table m_0c;
    int m_14;

    void hkpToiCountViewer_contactPointCallback(ArgBlock* a1);
};

// For each of two items in a1->m_items, increments the high/low counters in the table entry or attaches a new entry and applies the item.
// @fnv 0x00d67c30
// src: HAVOK_LIB 0x00d67c30
void FUN_00d67c30_cls::hkpToiCountViewer_contactPointCallback(ArgBlock* apBlock)
{
    if (apBlock->unk10 > 0)
    {
        return;
    }
    Table* t = &m_0c;
    int* p = apBlock->m_items;
    int n = 2;
    do
    {
        Item* item = (Item*)*p;
        int idx = t->FindIndex((int)item);
        if (idx <= m_14)
        {
            unsigned int* pFlags = &t->m_entries[idx].m_flags;
            unsigned int uiFlags = *pFlags;
            unsigned int uiHigh = (uiFlags >> 0x18) + 1;
            if (uiHigh >= 0xff)
            {
                uiHigh = 0xff;
            }
            unsigned int uiLow = (uiFlags & (unsigned int)&DAT_00ffffff) + 1;
            if (uiLow >= (unsigned int)&DAT_00ffffff)
            {
                uiLow = (unsigned int)&DAT_00ffffff;
            }
            *pFlags = (uiHigh << 0x18) | uiLow;
        }
        else
        {
            hkMemoryRouter* h = hkMemoryRouter_getInstance();
            t->Attach((int)h->m_heap, (int)item, (int)&DAT_01000001);
            char* owner = ((char*)this - 0x28) != 0 ? (char*)this + 8 : 0;
            item->Apply((int)owner);
        }
        p++;
    } while (--n != 0);
}
}  // namespace fnv_00d67c30

struct ToiCountPrimaryInterface : PrimaryBase
{
    virtual void FUN_00d681f0();
};

struct ToiCountProcessInterface
{
    virtual void FUN_00d681f0();
};

struct ToiCountProcessAdjustor : ToiCountPrimaryInterface, ToiCountProcessInterface
{
    ToiCountProcessAdjustor();
// @fnv 0x00d681f0
    virtual void FUN_00d681f0();
};

ToiCountProcessAdjustor::ToiCountProcessAdjustor()
{}

// MSVC adjustor thunk: the primary base occupies 0x2c bytes; both bases declare the virtual,
// the derived class defines only its constructor, so the compiler emits the this-adjusting thunk.
struct ToiCountThunkPrimary
{
    virtual void FUN_00d68210();
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
};

struct ToiCountThunkSecondary
{
    virtual void FUN_00d68210();
};

struct ToiCountThunkObject : ToiCountThunkPrimary, ToiCountThunkSecondary
{
    ToiCountThunkObject();
// @fnv 0x00d68210
    virtual void FUN_00d68210();
};

ToiCountThunkObject::ToiCountThunkObject()
{}
