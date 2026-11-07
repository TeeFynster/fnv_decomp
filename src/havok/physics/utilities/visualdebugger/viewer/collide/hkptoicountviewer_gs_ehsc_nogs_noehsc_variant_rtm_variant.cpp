#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/BSAudio.h"
#include "../../../../../../../include/NiPoint3.h"
#include "../../../../../../../include/hkpContactListener.h"
#include "../../../../../../../include/hkpEntityListener.h"
#include "../../../../../../../include/hkpWorldPostSimulationListener.h"

// src/havok/physics/utilities/visualdebugger/viewer/collide/hkptoicountviewer_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/visualdebugger/viewer/collide/hkptoicountviewer_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


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
struct CountArray
{
    int* data;
    int size;
    int capacity;
    CountArray() : data(0), size(0), capacity(-1)
    {}
    void EnsureCapacity(void*, int);
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
    virtual ~FUN_00d67ce0() throw();
    virtual void postSimulationCallback(hkpWorld* world);
    virtual void EntityRemovalCallback(hkpEntity* entity);
    virtual void EntityAddedCallback(hkpEntity* entity);
    virtual void EntityRemovedCallback(hkpEntity* entity);
    virtual void EntityShapeSetCallback(hkpEntity* entity);
    virtual void entitySetMotionTypeCallback(hkpEntity* entity);
    virtual void EntityDeletionCallback(hkpEntity* entity);
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
__declspec(nothrow) BSAudio* hkMemoryRouter_getInstance();
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
        Release(hkMemoryRouter_getInstance()->pListener);
    }
};
struct FUN_00d67fa0 : Base0, Iface1, Iface2, Iface3
{
    Member member;
    ~FUN_00d67fa0();
    virtual void p0();
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
BSAudio* hkMemoryRouter_getInstance() throw();
void __cdecl ResizeAudioStream(void* a, void* arr, unsigned int size) throw();
// Exe 0x00d681e0: unit-local Map view; declarations and layout are preserved.
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
        BSAudio* h = hkMemoryRouter_getInstance();
        hkMemoryAllocator* al = reinterpret_cast<hkMemoryAllocator*>(h->pListener);
        int cap = m_iCapacityState;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
        {
            // The shared declaration does not expose the virtual free slot.
            (*reinterpret_cast<void (__thiscall***)(hkMemoryAllocator*, SpawnedObject**, unsigned int)>(al))[4](
                al, m_data, (cap & 0x3fffffff) * 4);
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
        hkMemoryAllocator* allocator = *reinterpret_cast<hkMemoryAllocator**>(&hkMemoryRouter_getInstance()->bSeekMusic);
        m_fRestLength = 0;
        if ((m_pRayCursor & 0x80000000) == 0)
            // The shared declaration does not expose the virtual free slot.
            (*reinterpret_cast<void (__thiscall***)(hkMemoryAllocator*, void*, unsigned int)>(allocator))[4](
                allocator, m_data, m_pRayCursor & 0x3fffffff);
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

extern __m128 DAT_01267e30;
extern "C" double __cdecl fabs(double);
class S00d67a50_Shape377
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void GetAabb(void* body, float zero, __m128* out);
};
class S00d67a50_Owner377
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c_unused();
    virtual void v10_unused();
    virtual void v14_unused();
    virtual void v18_unused();
    virtual void v1c_unused();
    virtual void v20_unused();
    virtual void v09(__m128* anchor, void* ctx140, int a1c, void* ctx10, int a2);
    virtual void v0a();
    virtual void v0b();
    virtual void v0c(int a18, __m128* pos, int a1c, void* ctx10, int a2);
};
__declspec(align(16)) struct Bounds377
{
    float mnx;
    float mny;
    float mnz;
    float mnw;
    float mxx;
    float mxy;
    float mxz;
    float mxw;
};
__declspec(align(16)) struct Vector377
{
    float values[4];
};
struct S00d67a50_Context377
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    S00d67a50_Shape377* shape;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    __m128 rotation0, rotation1, rotation2;
    __m128 translation;
    unsigned int unk130, unk134, unk138, unk13c;
    unsigned int unk140;
};
struct S00d67a50_Scalar377
{
    __m128 v;
    S00d67a50_Scalar377(float x) : v(::_mm_load_ss(&x))
    {}
    S00d67a50_Scalar377(__m128 x) : v(x)
    {}
    __m128 all() const
    {
        return ::_mm_shuffle_ps(v, v, 0);
    }
    operator float() const
    {
        float x;
        ::_mm_store_ss(&x, v);
        return x;
    }
};
struct S00d67a50_MathVector377
{
    union
    {
        __m128 v;
        float coordinates[4];
    };
    void sum(const S00d67a50_MathVector377& a, const S00d67a50_MathVector377& b)
    {
        v = ::_mm_add_ps(a.v, b.v);
    }
    void difference(const S00d67a50_MathVector377& a, const S00d67a50_MathVector377& b)
    {
        v = ::_mm_sub_ps(a.v, b.v);
    }
    void scale(const S00d67a50_Scalar377& s)
    {
        v = ::_mm_mul_ps(s.all(), v);
    }
    S00d67a50_Scalar377 dot(const S00d67a50_MathVector377& b) const
    {
        __m128 p = ::_mm_mul_ps(v, b.v);
        __m128 y = ::_mm_shuffle_ps(p, p, 0x55);
        __m128 z = ::_mm_shuffle_ps(p, p, 0xaa);
        return S00d67a50_Scalar377(::_mm_add_ss(z, ::_mm_add_ss(y, p)));
    }
    void offset(const S00d67a50_MathVector377& base, const S00d67a50_Scalar377& amount,
                const S00d67a50_MathVector377& direction)
    {
        v = ::_mm_add_ps(base.v, ::_mm_mul_ps(amount.all(), direction.v));
    }
};
inline double abs377(float x)
{
    return (float)fabs((double)x);
}

// @fnv 0x00d67a50
// src: GUESS 0x00d67a50 (confidence: low)
void HkptoicountviewerGsEhscNogsNoehsc_UpdateState_00d67a50(S00d67a50_Owner377* self, int a2, S00d67a50_Context377* ctx, int i, int a18, int a1c, float dist,
                  unsigned char flag)
{
    Bounds377 box;
    S00d67a50_Shape377** p10 = &ctx->shape;
    (*p10)->GetAabb(&ctx->rotation0, 0.0f, (__m128*)&box);
    S00d67a50_MathVector377 center, extent;
    center.sum(*(S00d67a50_MathVector377*)&box.mxx, *(S00d67a50_MathVector377*)&box.mnx);
    center.scale(S00d67a50_Scalar377(0.5f));
    extent.difference(*(S00d67a50_MathVector377*)&box.mxx, center);
    S00d67a50_MathVector377 direction;
    direction.v = DAT_01267e30;
    int q = i / 3;
    int r = i - q * 3;
    direction.coordinates[r] = 1.0f - 2.0f * (float)q;
    S00d67a50_MathVector377 anchor, pos;
    anchor.offset(center, S00d67a50_Scalar377(abs377((float)extent.dot(direction))), direction);
    pos.offset(anchor, S00d67a50_Scalar377(dist), direction);
    self->v0c(a18, (__m128*)&pos, a1c, p10, a2);
    if (flag)
        self->v09((__m128*)&anchor, &ctx->unk140, a1c, p10, a2);
}
