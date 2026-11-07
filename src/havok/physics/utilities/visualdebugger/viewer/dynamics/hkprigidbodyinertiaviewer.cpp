
// src/havok/physics/utilities/visualdebugger/viewer/dynamics/hkprigidbodyinertiaviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/hkprigidbodyinertiaviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#define FNV_TRANSFORM_NO_SSE
#include "../../../../../../../include/Transform.h"
#undef FNV_TRANSFORM_NO_SSE
#include "../../../../../../../include/hkArray.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkMemoryAllocator.h"

__forceinline hkMemoryAllocator& routerHeap(hkMemoryRouter& router)
{
    return *reinterpret_cast<hkMemoryAllocator*>(router.m_heap);
}

void __cdecl Object_ConstructObject_00d67880();

extern int DAT_01268ffc;
extern int DAT_01269cd0;

struct FUN_00dd9380_StandIn {
    int __thiscall hkProcessFactory_registerProcess(const char* name, void* factory);
};

// @fnv 0x00d678c0
void __cdecl RegisterInertiaTensors()
{
    DAT_01268ffc = ((FUN_00dd9380_StandIn*)DAT_01269cd0)->hkProcessFactory_registerProcess("Inertia Tensors", &Object_ConstructObject_00d67880);
}

struct SubObject {
    char pad[0x48];
    hkArrayBase<void*> arr;
};

struct Arg {
    char pad00[0x20];
    SubObject* m_20;
    char pad24[4];
    SubObject** m_28;
    int m_2c;
    char pad30[4];
    SubObject** m_34;
    int m_38;

    void hkpWorld_addEntityListener(void* p);
    void hkpWorld_addWorldPostSimulationListener(void* p);
};

struct Field28 {
    virtual void vfunc0();
    virtual void vfunc1(void* item);
};

struct FUN_00d67020_class {
    char pad00[0x28];
    Field28 field28;
    int field2c;

    void VisitSubObjects(Arg* arg);
};

// @fnv 0x00d67020
void FUN_00d67020_class::VisitSubObjects(Arg* arg) {
    arg->hkpWorld_addEntityListener(this ? &field28 : 0);
    arg->hkpWorld_addWorldPostSimulationListener(this ? &field2c : 0);

    for (int i = 0; i < arg->m_2c; ++i) {
        hkArrayBase<void*>* arr = &arg->m_28[i]->arr;
        for (int j = 0; j < arr->m_iElementCount; ++j) {
            field28.vfunc1(arr->m_data[j]);
        }
    }

    for (int i = 0; i < arg->m_38; ++i) {
        hkArrayBase<void*>* arr = &arg->m_34[i]->arr;
        for (int j = 0; j < arr->m_iElementCount; ++j) {
            field28.vfunc1(arr->m_data[j]);
        }
    }

    SubObject* pSubObject = arg->m_20;
    if (pSubObject) {
        hkArrayBase<void*>* arr = &pSubObject->arr;
        for (int i = 0; i < arr->m_iElementCount; ++i) {
            field28.vfunc1(arr->m_data[i]);
        }
    }
}

struct Handler { void VisitSubObjects(int); };
struct Collection {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54; int unk58; int unk5C;
    int unk60; int unk64; int unk68;
    int* items;
    int count;
};
struct Owner {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18;
    Collection* collection;
    void __thiscall ProcessCollectionItems();
};
// Iterates the collection's items and passes each to VisitSubObjects on the Handler at this-8, if the collection exists.
// @fnv 0x00d67110
void __thiscall Owner::ProcessCollectionItems() {
    if (collection != 0) {
        int n = collection->count;
        int i = 0;
        if (0 < n) {
            do {
                ((Handler*)((char*)this - 8))->VisitSubObjects(collection->items[i]);
                i = i + 1;
            } while (i < n);
        }
    }
}

struct Prefix32 {
    int unk00; int unk04; int unk08; int unk0C;
    int unk10; int unk14; int unk18; int unk1C;
};
struct SecondaryBase {
    void UpdateFields_00d67160();
};
struct CompleteObject : Prefix32, SecondaryBase {
    void VisitSubObjects();
};
// Adjusts this to the enclosing CompleteObject and calls its VisitSubObjects method.
// @fnv 0x00d67160
// src: GUESS 0x00d67160 (confidence: low)
void SecondaryBase::UpdateFields_00d67160() {
    CompleteObject* pCompleteObject = reinterpret_cast<CompleteObject*>(reinterpret_cast<char*>(this) - sizeof(Prefix32));
    pCompleteObject->VisitSubObjects();
}

template <typename T>
__forceinline void hkArrayBase<T>::removeAt(int index)
{
    m_iElementCount--;
    if (m_iElementCount != index)
        m_data[index] = m_data[m_iElementCount];
}

struct S_00d67170 {
    int unk0;
    int unk4;
    hkArray<void*> unk8;
    void RemoveItem(void* item);
};

// Finds item in the unk8 array and removes it at its index if present.
// @fnv 0x00d67170
void S_00d67170::RemoveItem(void* item)
{
    int index = unk8.indexOf(item);
    if (index >= 0)
        unk8.removeAt(index);
}

extern int DAT_01268ffc;
// @fnv 0x00d678e0
// src: GUESS 0x00d678e0 (confidence: low)
int __cdecl Object_GetDAT_01268ffc_00d678e0()
{
    return DAT_01268ffc;
}

struct FUN_00d66f30_inner {
    virtual void v00();
    virtual void v04();
    virtual void v08(int aiValue);
};

struct FUN_00d66f30_item {
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
    hkArrayBase<int> m_kList;
};

struct FUN_00d66f30_params {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    FUN_00d66f30_item* m_pExtra;
    int unk24;
    FUN_00d66f30_item** m_ppItems;
    int m_iItemCount;
    int unk30;
    FUN_00d66f30_item** m_ppItems2;
    int m_iItemCount2;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;

    void hkpWorld_removeEntityListener(void* apTarget);
    void ClearValue(void* apTarget);
};

struct FUN_00d66f30_cls {
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
    FUN_00d66f30_inner m_kInner;
    int m_iN;

    void ProcessEntries_00d66f30(FUN_00d66f30_params* apParams);
};

// @fnv 0x00d66f30
// src: GUESS 0x00d66f30 (confidence: low)
void FUN_00d66f30_cls::ProcessEntries_00d66f30(FUN_00d66f30_params* apParams)
{
    apParams->hkpWorld_removeEntityListener(this != 0 ? &m_kInner : 0);
    apParams->ClearValue(this != 0 ? &m_iN : 0);

    for (int i = 0; i < apParams->m_iItemCount; i++) {
        hkArrayBase<int>* pList = &apParams->m_ppItems[i]->m_kList;
        for (int j = 0; j < pList->m_iElementCount; j++) {
            m_kInner.v08(pList->m_data[j]);
        }
    }

    for (int i = 0; i < apParams->m_iItemCount2; i++) {
        hkArrayBase<int>* pList = &apParams->m_ppItems2[i]->m_kList;
        for (int j = 0; j < pList->m_iElementCount; j++) {
            m_kInner.v08(pList->m_data[j]);
        }
    }

    FUN_00d66f30_item* pExtra = apParams->m_pExtra;
    if (pExtra != 0) {
        for (int k = 0; k < pExtra->m_kList.m_iElementCount; k++) {
            m_kInner.v08(pExtra->m_kList.m_data[k]);
        }
    }
}

struct Outer {
    void __thiscall ProcessEntries_00d66f30(void* arg);
};

struct TargetClass {
    void __thiscall ForwardCall_00d67150(void* arg);
};

// @fnv 0x00d67150
// src: GUESS 0x00d67150 (confidence: low)
void TargetClass::ForwardCall_00d67150(void* arg) {
    ((Outer*)((char*)this - 0x20))->ProcessEntries_00d66f30(arg);
}

class D671F0ListenerA {
public:
    virtual void unk00();
};

class D671F0ListenerB {
public:
    virtual void unk00();
};

class D671F0Island {
public:
    void addListener(D671F0ListenerA* listener);
};

struct D671F0World {
    int unk00;
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
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    D671F0Island** m_islands;
    int m_iIslandCount;
};

class D671F0BaseA {
public:
    virtual void unk00();

    int unk04;
};

class D671F0BaseB {
public:
    virtual void unk00();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class D671F0BaseC {
public:
    virtual void unk00();
};

class D671F0Base : public D671F0BaseA, public D671F0BaseB, public D671F0BaseC {
public:
    D671F0Base(void* info);

    D671F0World* m_pOwningWorld;
};

class FUN_00d671f0 : public D671F0Base, public D671F0ListenerA, public D671F0ListenerB {
public:
    FUN_00d671f0(void* info);

    hkArray<void*> m_arrayA;
    hkArray<void*> m_arrayB;
};

// Constructor that forwards info to the D671F0Base base constructor and initializes the two listener arrays.
// @fnv 0x00d671f0
FUN_00d671f0::FUN_00d671f0(void* info) : D671F0Base(info)
{
}

class D67880ReferencedObject {
public:
    static void* operator new(unsigned int nbytes)
    {
        D67880ReferencedObject* b = static_cast<D67880ReferencedObject*>(routerHeap(hkMemoryRouter::getInstance()).blockAlloc(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    static void operator delete(void* p);

    virtual ~D67880ReferencedObject();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class D67880Interface {
public:
    virtual ~D67880Interface();
};

class D67880Object : public D67880ReferencedObject, public D67880Interface {
public:
    __declspec(nothrow) D67880Object(const void* info);

    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
};

// Allocates a D67880Object from info and returns it as a D67880Interface pointer.
// @fnv 0x00d67880
// src: GUESS 0x00d67880 (confidence: medium)
D67880Interface* __cdecl Object_ConstructObject_00d67880(const void* info)
{
    return new D67880Object(info);
}

void __cdecl ResizeAudioStream(void* allocator, void* array, int elementSize);
template <typename T> inline void D671B0ConstructWithCopy(T* p, int n, const T& t) { for (int i = 0; i < n; i++) p[i] = t; }

template <typename T>
__forceinline void hkArrayBase<T>::_pushBack(hkMemoryAllocator& allocator, const T& val)
{
    if (m_iElementCount == getCapacity())
        ResizeAudioStream(&allocator, this, sizeof(T));
    D671B0ConstructWithCopy<T>(m_data + m_iElementCount, 1, val);
    m_iElementCount++;
}
struct D671B0Owner {
    int unk00;
    int unk04;
    hkArray<void*> m_ppData;
    void AddItem(void* item);
};
// Appends item to the owner's array via the array's push method.
// @fnv 0x00d671b0
void D671B0Owner::AddItem(void* item)
{
    m_ppData.pushBack(item);
}

extern int DAT_010d1d80;
extern int DAT_010d1d60;
extern int DAT_010d1d50;
extern int DAT_010d1d34;
extern int DAT_010d1d24;
extern int DAT_010ccf7c;
extern int DAT_0102f13c;

template <class T> __forceinline void destructArray_d672(T* p, int n)
{
    for (int i = 0; i < n; i++)
        p[i].~T();
}

template <typename T>
__forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& allocator)
{
    destructArray_d672(m_data, m_iElementCount);
    m_iElementCount = 0;
    if ((m_iCapacityState & 0x80000000) == 0)
        allocator.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
    m_data = 0;
    m_iCapacityState = 0x80000000;
}

__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return routerHeap(hkMemoryRouter::getInstance());
}

template <typename T, typename Allocator>
__forceinline hkArray<T, Allocator>::~hkArray()
{
    clearAndDeallocate();
}

struct DisplayGeometry_d672 {
    virtual ~DisplayGeometry_d672() throw();
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
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
};

struct Entity_d672;
struct World_d672 {
    int unk00;
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
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    Entity_d672** m_kActorEntries;
    int m_iActorEntryCount;
};

struct Viewer_d672 {
    int* m_vtbl00;
    int unk04;
    int* m_vtbl08;
    int unk0C, unk10, unk14, unk18, unk1C;
    int* m_vtbl20;
    World_d672* m_pOwningWorld;
    int* m_vtbl28;
    int* m_vtbl2C;
    hkArray<int> m_ids;
    hkArray<DisplayGeometry_d672> m_geometries;
    void ProcessEntries_00d66f30(Entity_d672* entity);
    void FUN_00ddcc60();
    void ProcessEntries_00d67250();
};

// Resets vtable pointers, calls FUN_00d66f30 on each actor entry of the owning world, clears the geometry and id arrays, then calls FUN_00ddcc60.
// @fnv 0x00d67250
// src: GUESS 0x00d67250 (confidence: low)
void Viewer_d672::ProcessEntries_00d67250()
{
    m_vtbl00 = &DAT_010d1d80;
    m_vtbl08 = &DAT_010d1d60;
    m_vtbl20 = &DAT_010d1d50;
    m_vtbl28 = &DAT_010d1d34;
    m_vtbl2C = &DAT_010d1d24;
    if (m_pOwningWorld) {
        int n = m_pOwningWorld->m_iActorEntryCount;
        for (int i = 0; i < n; i++)
            ProcessEntries_00d66f30(m_pOwningWorld->m_kActorEntries[i]);
    }
    m_geometries.clearAndDeallocate();
    m_ids.clearAndDeallocate();
    m_vtbl2C = &DAT_010ccf7c;
    m_vtbl28 = &DAT_0102f13c;
    FUN_00ddcc60();
}

struct D678F0Primary {
    virtual void vfunc00();
    virtual void FUN_00d678f0();

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

struct D678F0Secondary {
    virtual void FUN_00d678f0();
};

struct D678F0Object : D678F0Primary, D678F0Secondary {
    D678F0Object();

// @fnv 0x00d678f0
    virtual void FUN_00d678f0();
};

D678F0Object::D678F0Object()
{
}

struct D67900Primary {
    virtual void vfunc00();
    virtual void AdjustThisAndForward_00d67900();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

struct D67900Secondary {
    virtual void AdjustThisAndForward_00d67900();
};

struct D67900Object : D67900Primary, D67900Secondary {
    D67900Object();

// @fnv 0x00d67900
// src: GUESS 0x00d67900 (confidence: low)
    virtual void AdjustThisAndForward_00d67900();
};

D67900Object::D67900Object()
{
}

// FUN_00d67920 : MSVC this-adjusting thunk.
//
// The original is 8 bytes:  sub ecx, 0x28 ; jmp 0x00d67930
// That is the adjustor thunk MSVC emits for a virtual function that a
// derived class overrides for a SECONDARY base: calling through the
// secondary base's vftable passes the base subobject's 	his, so the
// thunk walks it back to the derived object and tail-jumps to the shared
// override.
//
// Two bases declare the same virtual, so the derived class overrides one
// function for both of them -> one adjustor per secondary base.  The first
// base is padded to 40 bytes so the second base lands at +0x28.
// The override is DECLARED ONLY, so the thunk is the single defined
// function symbol carrying the name FUN_00d67920, and a defined key function in the
// derived class makes the vftable that references the thunk be emitted here.
struct AdjBase1 {
    AdjBase1();
    virtual void AdjustThisAndForward_00d67920();
    char pad[0x24];
};

struct AdjBase2 {
    AdjBase2();
// @fnv 0x00d67920
// src: GUESS 0x00d67920 (confidence: low)
    virtual void AdjustThisAndForward_00d67920();
};

struct AdjOwner : AdjBase1, AdjBase2 {
    AdjOwner();
    virtual void key_fn();    // key function - defined, so the vftable is emitted
    void AdjustThisAndForward_00d67920();              // the shared override - declared only
};

AdjOwner::AdjOwner() { }
void AdjOwner::key_fn() { }

AdjOwner* make_adj_owner() { static AdjOwner o; return &o; }

namespace fnv_00d67930 {
struct FUN_00d67930 {
    virtual ~FUN_00d67930() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    FUN_00d67930();
    static void operator delete(void* p, unsigned int)
    {
        FUN_00d67930* b = static_cast<FUN_00d67930*>(p);
        routerHeap(hkMemoryRouter::getInstance()).blockFree(p, b->m_usMemSizeAndFlags);
    }
};

// Default constructor with an empty body for a type with a virtual destructor, m_usMemSizeAndFlags and m_sReferenceCount.
// @fnv 0x00d67930
FUN_00d67930::FUN_00d67930() {}
}  // namespace fnv_00d67930

#include <math.h>
#include <xmmintrin.h>
#include <windows.h>
extern unsigned long DAT_0126835c;
extern double DAT_010d0f68;
extern float DAT_01011d78;
extern char DAT_010c41f8[], DAT_010d1d8c[];
struct ProfileEvent {
    const char* name;
    unsigned int timestamp;
    unsigned int reserved;
};
struct ProfileStream {
    int unk00;
    ProfileEvent* current;
    ProfileEvent* start;
    ProfileEvent* end;
};
inline void recordEvent(const char* name) {
    ProfileStream* stream = static_cast<ProfileStream*>(TlsGetValue(DAT_0126835c));
    ProfileEvent* event = stream->current;
    if (event < stream->end) {
        event->name = name;
        unsigned int tick;
        __asm {
            rdtsc
            mov dword ptr[tick], eax
        }
        event->timestamp = tick;
        stream->current = event + 1;
    }
}
struct __declspec(align(16)) Vec {
    float x,y,z,w;
    Vec() {}
    __forceinline __m128 get() const { return _mm_load_ps(&x); }
    __forceinline void set(__m128 value) { _mm_store_ps(&x,value); }
    __forceinline void set(float a, float b, float c, float d) { set(_mm_setr_ps(a,b,c,d)); }
    __forceinline Vec(float a, float b, float c, float d) { set(_mm_setr_ps(a,b,c,d)); }
    __forceinline Vec(const Vec& other) { set(other.get()); }
    __forceinline Vec& operator=(const Vec& other) { set(other.get()); return *this; }
    void hkVector4_setRotatedDir(const Transform* transform, const Vec* value);
};
__forceinline Transform::Transform(const Transform& other) {
    __m128 a = _mm_load_ps(&other.m_f00), b = _mm_load_ps(&other.m_f10);
    __m128 c = _mm_load_ps(&other.m_f20), d = _mm_load_ps(&other.m_f30);
    _mm_store_ps(&m_f00, a); _mm_store_ps(&m_f10, b);
    _mm_store_ps(&m_f20, c); _mm_store_ps(&m_f30, d);
}
struct __declspec(align(16)) Inertia {
    float xx, xy, xz, xw;
    float yx, yy, yz, yw;
    float zx, zy, zz, zw;
    Inertia() {}
};
struct MotionHeader {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void getInertia(Inertia* out);
    int unk04, unk08, unk0c;
};
struct Motion : MotionHeader {
    Transform transform;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    Vec centerOfMass;
    float FUN_00c86430();
};
struct Body {
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
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    Motion motion;
    __forceinline Motion* getRigidMotion() { return &motion; }
    __forceinline const Motion* getRigidMotionC() const { return &motion; }
    __forceinline float GetMassValue() { return getRigidMotion()->FUN_00c86430(); }
    __forceinline void GetInverseScaleMatrix(Inertia& m) { getRigidMotion()->getInertia(&m); }
    __forceinline const Transform& getTransform() const { return motion.transform; }
    __forceinline const Vec& getCenterOfMassLocal() const { return motion.centerOfMass; }
};
struct ShapeVec4 { float x, y, z, w; };
struct Shape {
    virtual void destroy(int flags);
    unsigned short memSizeAndFlags;
    short referenceCount;
    int userData;
    int unk0c;
    Transform transform;
    int type;
    int unk54, unk58, unk5c;
    ShapeVec4 halfExtents;
    void FUN_00de1fc0();
    void InitializeFields_00de2010(const Vec* dimensions, const Transform* transform);
};
void __cdecl hkArrayUtil__reserve(void* allocator, void* array, int capacity, int elementSize);
template <typename T>
__forceinline void hkArrayBase<T>::GrowArrayCapacity(hkMemoryAllocator& allocator, int n)
{
    const int capacity = getCapacity();
    if (capacity < n) {
        int twice = capacity * 2;
        int next = n < twice ? twice : n;
        hkArrayUtil__reserve(&allocator, this, next, sizeof(T));
    }
}
inline void destroyShapes(Shape* begin, int count) {
    for (int k=0; k<count; ++k) begin[k].destroy(0);
}
inline void createShapes(Shape* begin, int count) {
    for (int k=0; k<count; ++k) {
        Shape* at = begin+k;
        if (at) at->FUN_00de1fc0();
    }
}
template <>
__forceinline void hkArrayBase<Shape>::_setSize(hkMemoryAllocator& allocator, int n)
{
    GrowArrayCapacity(allocator, n);
    destroyShapes(m_data+n, m_iElementCount-n);
    createShapes(m_data+m_iElementCount, n-m_iElementCount);
    m_iElementCount=n;
}
struct Renderer {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void display(hkArrayBase<Shape*>* shapes, unsigned int color, int id, int tag);
};
struct ViewerPart {
    virtual void v00();
    Body** bodies;
    int bodyCount;
    int bodyCapacity;
    hkArray<Shape> shapes;
    void ProcessEntries_00d67340(float unused);
};
struct ViewerPrefix {
    virtual void v00();
    Renderer* renderer;
    int unk04, unk08, unk0c, unk10;
};
struct Viewer : ViewerPrefix, ViewerPart {};
// @fnv 0x00d67340
// src: GUESS 0x00d67340 (confidence: low)
void ViewerPart::ProcessEntries_00d67340(float unused) {
    recordEvent("TthkpRigidBodyInertiaViewer");
    recordEvent("TtgetProps");
    shapes.setSize(bodyCount);
    int used = 0;
    for (int i = 0; i < bodyCount; ++i) {
        float mass = bodies[i]->GetMassValue();
        if (mass != 0.0f) {
            Inertia inertia;
            bodies[i]->motion.getInertia(&inertia);
            float betaSqrd = float((inertia.xx - inertia.yy + inertia.zz) / mass * 6.0);
            float beta; if (betaSqrd < 0.0f) beta=0.0f; else beta=sqrtf(betaSqrd);
            float gammaSqrd = float(inertia.xx / mass * 12.0 - betaSqrd);
            float gamma; if (gammaSqrd < 0.0f) gamma=0.0f; else gamma=sqrtf(gammaSqrd);
            float alphaSqrd = float(inertia.zz / mass * 12.0 - betaSqrd);
            float alpha; if (alphaSqrd < 0.0f) alpha=0.0f; else alpha=sqrtf(alphaSqrd);
            Vec dimensions;
            dimensions.set(alpha * DAT_010d0f68 * 0.5, beta * DAT_010d0f68 * 0.5, gamma * DAT_010d0f68 * 0.5, DAT_01011d78);
            __declspec(align(16)) Transform transform = bodies[i]->motion.transform;
            Vec rotated;
            {
                Vec center = bodies[i]->motion.centerOfMass;
                rotated.hkVector4_setRotatedDir(&transform, &center);
            }
            rotated.set(_mm_add_ps(reinterpret_cast<const Vec&>(transform.r[3]).get(), rotated.get()));
            reinterpret_cast<Vec&>(transform.r[3]) = rotated;
            shapes.m_data[used++].InitializeFields_00de2010(&dimensions, &transform);
        }
    }
    recordEvent(DAT_010c41f8);
    recordEvent(DAT_010d1d8c);
    shapes.setSize(used);
    hkArrayBase<Shape*> pointers;
    pointers.m_data = 0;
    pointers.m_iElementCount = 0;
    pointers.m_iCapacityState = 0x80000000;
    int count = shapes.m_iElementCount;
    pointers.GrowArrayCapacity(routerHeap(hkMemoryRouter::getInstance()), count);
    pointers.m_iElementCount = count;
    for (int j = shapes.m_iElementCount - 1; j >= 0; --j)
        pointers.m_data[j] = &shapes.m_data[j];
    static_cast<Viewer*>(this)->renderer->display(&pointers, 0xffff00ff, 0, DAT_01268ffc);
    recordEvent(DAT_010c41f8);
    recordEvent(DAT_010c41f8);
    hkMemoryAllocator& allocator = routerHeap(hkMemoryRouter::getInstance());
    pointers.m_iElementCount = 0;
    if ((pointers.m_iCapacityState & 0x80000000)==0)
        allocator.bufFree(pointers.m_data, (pointers.m_iCapacityState & 0x3fffffff) * sizeof(Shape*));
}

struct D67910Primary
{
    virtual void FUN_00d67910();
    int unk04;
};

struct D67910Secondary
{
    virtual void FUN_00d67910();
};

struct D67910Object : D67910Primary, D67910Secondary
{
    D67910Object();
// @fnv 0x00d67910
    virtual void FUN_00d67910();
};

D67910Object::D67910Object()
{
}
