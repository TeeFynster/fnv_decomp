
// src/havok/physics/utilities/visualdebugger/viewer/collide/hkptoicountviewer_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-29 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/utilities/visualdebugger/viewer/collide/hkptoicountviewer.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

void __stdcall ClearTwoInts(int* a, int* b);
extern int g_D67960Value;
int __cdecl Object_GetG_D67960Value_00d67960();
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
class hkpContactListener
{
  public:
    virtual void contact0();
    virtual void contact1();
    virtual void contact2();
};
class hkpWorldPostSimulationListener
{
  public:
    virtual void post0();
    virtual void post1();
    virtual void post2();
};
class hkpEntityListener
{
  public:
    virtual void entity0();
    virtual void entity1();
    virtual void entity2();
    virtual void entity3();
    virtual void entity4();
    virtual void entity5();
};
struct CountArray
{
    int* data;
    int size;
    int capacity;
    CountArray() : data(0), size(0), capacity(-1)
    {}
    void EnsureCapacity(void*, int);
};
struct BSAudio
{
    int unk00, unk04, unk08, unk0C;
    void* allocator;
};
BSAudio* hkMemoryRouter_getInstance();
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
    virtual void post0();
    virtual void post1();
    virtual void post2();
    virtual void entity0();
    virtual void entity1();
    virtual void entity2();
    virtual void entity3();
    virtual void entity4();
    virtual void entity5();
    CountArray counts;
    FUN_00d67ce0(int context);
};
void* AllocateToiCountViewer();
struct S_00d67e10_Registry
{
    int Register(const char* name, void* (*create)());
};
extern S_00d67e10_Registry* g_00d67e10_registry;
extern int g_00d67e10_toiCounterId;
void RegisterToiCounter();
struct BSAudio;
__declspec(nothrow) BSAudio* hkMemoryRouter_getInstance();
struct AudioHeap
{
    char pad[0x10];
    void* heap;
};
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
        Release(((AudioHeap*)hkMemoryRouter_getInstance())->heap);
    }
};
struct FUN_00d67fa0 : Base0, Iface1, Iface2, Iface3
{
    Member member;
    ~FUN_00d67fa0();
    virtual void p0();
};
struct Point3
{
    float x;
    float y;
    float z;
};
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
    Point3 direction;
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
struct Alloc
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Grow(SpawnedObject** out, unsigned int size);
};
struct BSAudio;
BSAudio* hkMemoryRouter_getInstance() throw();
void __cdecl ResizeAudioStream(void* a, void* arr, unsigned int size) throw();
struct Map
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
        BSAudio* h = hkMemoryRouter_getInstance();
        Alloc* al = (Alloc*)h->allocator;
        int cap = m_iCapacityState;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
        {
            al->Grow(m_data, (cap & 0x3fffffff) * 4);
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
    Map m_14;

    void RemoveEntriesForObject(SpawnedObject* a1);
};
#include <xmmintrin.h>
extern const __m128 DAT_01017d10;
__declspec(align(16)) struct SquaredLanes
{
    float m_uiX;
    float m_uiY;
    float m_uiZ;
    float m_w;
};
int __cdecl Object_GetSignedLargestComponentIndex(const __m128* v);
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
#include "../../../../../../../include/hkMemoryAllocator.h"
struct AudioCoreView
{
    int unk00;
    int unk04;
    int unk08;
    hkMemoryAllocator* m_pThreadAllocator;
};
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
        hkMemoryAllocator* allocator = ((AudioCoreView*)hkMemoryRouter_getInstance())->m_pThreadAllocator;
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
