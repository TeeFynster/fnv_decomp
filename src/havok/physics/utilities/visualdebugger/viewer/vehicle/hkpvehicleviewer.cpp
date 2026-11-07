#include "../../../../../../../include/hkArray.h"

// src/havok/physics/utilities/visualdebugger/viewer/vehicle/hkpvehicleviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/vehicle/hkpvehicleviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkBuiltinTypeRegistry.h"
#include "../../../../../../../include/hkClass.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkaAnimation.h"  // Shared hkArray layout.
#include "../../../../../../../include/hkProcess.h"
#include "../../../../../../../include/hkpActionListener.h"
#include "../../../../../../../include/hkpWorldPostSimulationListener.h"
#include "../../../../../../../include/hkpPhysicsContext.h"
#include "../../../../../../../include/hkpPhysicsSystem.h"
#include "../../../../../../../include/hkpWorld.h"
#include "../../../../../../../include/hkProcessFactory.h"
#include "../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../include/hkVtableClassRegistry.h"
#include "../../../../../../../include/hkMemoryRouter.h"



void __cdecl hkArrayUtil__reserve(hkMemoryAllocator* alloc, void* array, int numElements, int sizeElem);
void __cdecl D625A0MemMove(void* dst, const void* src, unsigned int nbytes);



// @fnv 0x00d625a0


extern char d_010d17d0;
// @fnv 0x00d634d0
// src: GUESS 0x00d634d0 (confidence: low)
char* Hkpvehicleviewer_GetD010d17d0Address()
{
    return &d_010d17d0;
}

struct ItemSink;

typedef void(__thiscall* ProcessFn)(ItemSink* apThis, void* apItem);

struct ItemSinkVtbl
{
    void* fn00;
    ProcessFn Process;
};

struct ItemSink
{
    ItemSinkVtbl* m_pVtbl;
};

struct FUN_00d634e0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    ItemSink m_kSink;
    hkpPhysicsContext* m_pHolder;

    void ProcessItems();
};

// Iterates m_pHolder's items and passes each to the sink's Process callback when m_pHolder is non-null.
// @fnv 0x00d634e0
void FUN_00d634e0_cls::ProcessItems()
{
    if (m_pHolder != 0)
    {
        for (int i = 0; i < m_pHolder->m_numWorlds; i++)
            m_kSink.m_pVtbl->Process(&m_kSink, m_pHolder->m_ppWorlds[i]);
    }
}

struct OurPart
{
    virtual void o00();

    int m_i04;

    void RegisterAndNotify(hkpWorld* apRegistry);
};

struct NotifyTarget
{
    virtual void v00();
    virtual void Notify(void* apItem);
};

struct SecondTarget
{
    virtual void w00();
};

struct Container : hkReferencedObject, hkProcess, OurPart, NotifyTarget, SecondTarget
{
};

// Listener registration is not declared in hkpWorld's shared header yet.
extern void hkpWorld_addActionListener();

__forceinline void RegisterNotifyTarget(hkpWorld* world, NotifyTarget* target)
{
    typedef void (__thiscall* RegisterFn)(hkpWorld*, NotifyTarget*);
    reinterpret_cast<RegisterFn>(hkpWorld_addActionListener)(world, target);
}

// @fnv 0x00d63520
void OurPart::RegisterAndNotify(hkpWorld* apRegistry)
{
    RegisterNotifyTarget(apRegistry, (Container*)((char*)this - 0x20));
    apRegistry->hkpWorld_addWorldPostSimulationListener(static_cast<SecondTarget*>((Container*)((char*)this - 0x20)));

    hkpPhysicsSystem* pItemList = apRegistry->getWorldAsOneSystem();
    for (int i = 0; i < pItemList->m_ppActions.m_iElementCount; i++)
        ((NotifyTarget*)((char*)this + 8))->Notify(pItemList->m_ppActions.m_data[i]);

    pItemList->removeReference();
}

extern void* DAT_01268fcc;
extern hkProcessFactory* DAT_01269cd0;
extern const char DAT_010d17c4;
extern void AllocAndInitObject();
// @fnv 0x00d63da0
// src: GUESS 0x00d63da0 (confidence: low)
void __cdecl Object_UpdateFields_00d63da0()
{
    DAT_01268fcc = DAT_01269cd0->RegisterProcess(&DAT_010d17c4, (void*)AllocAndInitObject);
}

extern int g_D63DC0Value;

// @fnv 0x00d63dc0
// src: GUESS 0x00d63dc0 (confidence: low)
int __cdecl Object_GetG_D63DC0Value_00d63dc0()
{
    return g_D63DC0Value;
}

// PassMembersToTarget - forwarding stub for a "container of" style object.
//
// `this` points at a sub-object that lives 0x20 bytes into a bigger object;
// the code recovers the owner pointer (this - 0x20) and passes it on to the
// two Target methods, which are called with the owner as their `this`.
// These two listener-removal methods are absent from the shared hkpWorld declaration.
extern void hkpWorld_removeActionListener();
extern void FUN_00c918e0();

struct FUN_00d63480_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;

    void PassMembersToTarget(hkpWorld* apTarget);
};

// Passes pointers to this object's members at offsets 8 and 0xc to the target's two callbacks, or null if the owner pointer is null.
// @fnv 0x00d63480
void FUN_00d63480_cls::PassMembersToTarget(hkpWorld* apTarget)
{
    char* pOwner = (char*)this - 0x20;
    typedef void (__thiscall* RemoveListenerFn)(hkpWorld*, void*);
    reinterpret_cast<RemoveListenerFn>(hkpWorld_removeActionListener)(apTarget, pOwner ? (void*)((char*)this + 8) : (void*)0);
    reinterpret_cast<RemoveListenerFn>(FUN_00c918e0)(apTarget, pOwner ? (void*)((char*)this + 0xc) : (void*)0);
}

// FUN_00d63c50 - the constructor of the Havok vehicle viewer
// (hkpVehicleViewer).
//
// The base class constructor (hkpWorldViewerBase) is called first with the
// argument that was passed in; afterwards the vtable pointer of the two
// listener bases and the vtable pointers of the viewer's own five base
// sub-objects are stored, and the last three members are initialised.
struct ViewerArg
{
    int unk00;
    int unk04;
};

// hkpWorldViewerBase - its constructor is not defined here, so the call stays
// an external reference and the checker binds it from the original's bytes.
// Retained: the approved hkpWorldViewerBase is 0x30 bytes, while this base must
// end at 0x28 so the vehicle viewer's listener and array offsets stay correct.
struct WorldViewerBase
{
    WorldViewerBase(ViewerArg* arg);
    int* m_vtbl00;  // +0x00
    int unk04;      // +0x04
    int* m_vtbl08;  // +0x08
    int unk0c;      // +0x0c
    int unk10;      // +0x10
    int unk14;      // +0x14
    int unk18;      // +0x18
    int unk1c;      // +0x1c
    int* m_vtbl20;  // +0x20
    int unk24;      // +0x24
};

struct FUN_00d63c50 : public WorldViewerBase
{
    FUN_00d63c50(ViewerArg* arg);
    int* volatile m_vtbl28;  // +0x28
    int* volatile m_vtbl2c;  // +0x2c
    volatile int m_30;       // +0x30
    volatile int m_34;       // +0x34
    volatile int m_38;       // +0x38
};

// the vftables of the class and of its bases
extern int DAT_010cb1d4;
extern int DAT_010ccf7c;
extern int DAT_010d1854;
extern int DAT_010d1834;
extern int DAT_010d1824;
extern int DAT_010d1814;
extern int DAT_010d1804;

// @fnv 0x00d63c50
FUN_00d63c50::FUN_00d63c50(ViewerArg* arg) : WorldViewerBase(arg)
{
    m_vtbl28 = &DAT_010cb1d4;
    m_vtbl2c = &DAT_010ccf7c;
    m_vtbl00 = &DAT_010d1854;
    m_vtbl08 = &DAT_010d1834;
    m_vtbl20 = &DAT_010d1824;
    m_vtbl28 = &DAT_010d1814;
    m_vtbl2c = &DAT_010d1804;
    m_30 = 0;
    m_34 = 0;
    m_38 = 0x80000000;
}

void* __cdecl hkMemoryRouter_getInstance() throw();
struct S_B20
{
    virtual void b20v0();
    void PassMembersToTarget(void* child);
};
struct FUN_00ddcc60 : hkReferencedObject, hkProcess, S_B20
{
    hkpPhysicsContext* m24;
    virtual ~FUN_00ddcc60() throw();
};
inline hkpActionListener::~hkpActionListener()
{}

inline hkpWorldPostSimulationListener::~hkpWorldPostSimulationListener() throw()
{}

// hkArray<T>::~hkArray() = clearAndDeallocate() on the heap allocator.
__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return reinterpret_cast<hkMemoryAllocator&>(((hkMemoryRouter*)hkMemoryRouter_getInstance())->heap());
}
template <typename T> __forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& heap)
{
    m_iElementCount = 0;
    if ((m_iCapacityState & 0x80000000) == 0)
        heap.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * (int)sizeof(T));
    m_data = 0;
    m_iCapacityState = 0x80000000;
}
template <typename T, typename A> __forceinline hkArray<T, A>::~hkArray()
{
    clearAndDeallocate();
}

struct FUN_00d63cb0 : FUN_00ddcc60, hkpActionListener, hkpWorldPostSimulationListener
{
    hkArray<void*> m30;
    virtual ~FUN_00d63cb0() throw();
};
// Destroys the object: calls PassMembersToTarget on each of m24->m_ppWorlds up to m24->m_numWorlds, then clears m30.
// @fnv 0x00d63cb0
FUN_00d63cb0::~FUN_00d63cb0() throw()
{
    if (m24)
    {
        for (int i = 0; i < m24->m_numWorlds; i++)
            ((S_B20*)this)->PassMembersToTarget(m24->m_ppWorlds[i]);
    }
}

namespace fnv_00d63d60 {
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

struct FUN_00d63d60_obj
{
    int unk00;
    unsigned short m_wSize;
    unsigned short m_u06;

    void* FUN_00d63c50(int a1);
};

// Allocates a 0x3c-byte object via the global allocator, sets its size, calls FUN_00d63c50(a1), and returns the result offset by 8 or null.
// @fnv 0x00d63d60
void* AllocAndInitObject(int a1)
{
    hkMemoryRouter* pAllocHolder = reinterpret_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance());
    hkMemoryAllocator* pAllocator = pAllocHolder->m_heap;
    typedef void* (__thiscall* AllocFn)(hkMemoryAllocator*, unsigned int);
    FUN_00d63d60_obj* obj = reinterpret_cast<FUN_00d63d60_obj*>(
        reinterpret_cast<AllocFn>((*reinterpret_cast<void***>(pAllocator))[1])(pAllocator, 0x3c));
    obj->m_wSize = 0x3c;
    void* pResult = obj->FUN_00d63c50(a1);
    if (pResult != 0)
    {
        return (char*)pResult + 8;
    }
    return 0;
}
}  // namespace fnv_00d63d60

namespace fnv_00d63e10 {
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

struct FUN_00d63e10_cls
{
    int unk00;
    unsigned short m_uSize;
    unsigned short m_u06;

    void FUN_00d63cb0();

    FUN_00d63e10_cls* Destroy(unsigned char acFlags);
    static void operator delete(void* apMemory) throw();
};

// @fnv 0x00d63e10
FUN_00d63e10_cls* FUN_00d63e10_cls::Destroy(unsigned char acFlags)
{
    FUN_00d63cb0();
    if (acFlags & 1)
    {
        hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
        pAllocator->blockFree(this, m_uSize);
    }
    return this;
}
}  // namespace fnv_00d63e10

namespace hkD635 {
extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance() throw();
}

void __cdecl ResizeAudioStream(void* pvAlloc, void* apvArray, int iSizeElem) throw();

// No shared hkClassNameRegistry header exists yet; keep its interface opaque.
class hkClassNameRegistry;

__forceinline const hkClass* GetClassByName(const hkClassNameRegistry* registry, const char* className)
{
    typedef const hkClass* (__thiscall* LookupFn)(const hkClassNameRegistry*, const char*);
    return reinterpret_cast<LookupFn>((*reinterpret_cast<void* const* const*>(registry))[4])(registry, className);
}

// The shared registry has no accessor declarations yet; retain its virtual calls.
__forceinline hkClassNameRegistry* GetClassNameRegistry(hkBuiltinTypeRegistry* registry)
{
    typedef hkClassNameRegistry* (__thiscall* Accessor)(hkBuiltinTypeRegistry*);
    return reinterpret_cast<Accessor>((*reinterpret_cast<void***>(registry))[4])(registry);
}

__forceinline hkVtableClassRegistry* GetVtableClassRegistry(hkBuiltinTypeRegistry* registry)
{
    typedef hkVtableClassRegistry* (__thiscall* Accessor)(hkBuiltinTypeRegistry*);
    return reinterpret_cast<Accessor>((*reinterpret_cast<void***>(registry))[5])(registry);
}

// hkClass's superclass test is external to this unit.
extern void hkClass_isSuperClass();

namespace hkD635 {
extern hkBuiltinTypeRegistry* DAT_01268b08;
}

// Keep the array operations inline here; hkArray's shared declaration supplies its layout.
template <class T>
static __forceinline void constructWithCopy(T* p, int n, const T& tcopy)
{
    for (int i = 0; i < n; ++i)
        p[i] = tcopy;
}

template <class T>
__forceinline void _pushBack(hkArray<T>& array, hkMemoryRouter& router, const T& t)
{
    if (array.m_iElementCount == (array.m_iCapacityState & 0x3fffffff))
        ResizeAudioStream(&router.heap(), &array, sizeof(T));
    constructWithCopy(array.m_data + array.m_iElementCount, 1, t);
    array.m_iElementCount++;
}

template <class T>
__forceinline void AddBack(hkArray<T>& array, const T& t)
{
    _pushBack(array, hkD635::hkMemoryRouter_getInstance(), t);
}

class VehicleViewerD635
{
  public:
    void AddVehicle(hkReferencedObject* pkObj);

    int unk00, unk04;
    hkArray<hkReferencedObject*> m_ppVehicles;
};

// Looks up a class by name and pkObj's class by vtable; if both exist and FUN_00d46d80 is true, calls FUN_00c90510 on pkObj and appends it to m_ppVehicles.
// @fnv 0x00d635e0
void VehicleViewerD635::AddVehicle(hkReferencedObject* pkObj)
{
    hkBuiltinTypeRegistry* pkReg = hkD635::DAT_01268b08;
    const hkClass* pkVehicleClass = GetClassByName(GetClassNameRegistry(pkReg), &d_010d17d0);
    const hkClass* pkObjClass = GetVtableClassRegistry(pkReg)->GetClassFromVirtualInstance(pkObj);
    // The shared hkClass lacks this declaration. A member-function pointer
    // preserves its thiscall convention and hidden hkBool return argument.
    typedef hkBool (hkClass::*IsSuperClassFn)(const hkClass&) const throw();
    union
    {
        void (*address)();
        IsSuperClassFn method;
    } isSuperClass;
    isSuperClass.address = hkClass_isSuperClass;
    if (pkVehicleClass && pkObjClass && (pkVehicleClass->*isSuperClass.method)(*pkObjClass))
    {
        pkObj->addReference();
        AddBack(m_ppVehicles, pkObj);
    }
}

// VC9 adjustor thunk: dual-slot override + static global forces
// [thunk]: TO::FUN_00d63dd0`adjustor{32}' = sub ecx,0x20; jmp TO::FUN_00d63dd0
struct Prim
{
    virtual void FUN_00d63dd0();
    int p04;
    int p08;
    int p0c;
    int p10;
    int p14;
    int p18;
    int p1c;
};

struct B1
{
    virtual void FUN_00d63dd0();
};

struct TO : Prim, B1
{
// @fnv 0x00d63dd0
    virtual void FUN_00d63dd0();
};

static TO g_thunk;

// sub ecx,8; jmp Destroy
// MSVC adjustor thunk: a class derives from two bases that both declare the same
// virtual, so the secondary base's vtable entry is an adjustor thunk that moves
// `this` back by the size of the primary base (8 = vptr + one int field).
struct PrimaryBase
{
    virtual void AdjustThisAndForward_00d63de0();
    int unk04;
};

struct SecondaryBase
{
    virtual void AdjustThisAndForward_00d63de0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d63de0
// src: GUESS 0x00d63de0 (confidence: low)
    virtual void AdjustThisAndForward_00d63de0();
};

Derived::Derived()
{}

struct Parent;
struct FirstBase
{
    virtual Parent* FUN_00d63df0(unsigned int flags) = 0;
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
};
struct Receiver
{
    virtual Parent* FUN_00d63df0(unsigned int flags) = 0;
};
struct Parent : FirstBase, Receiver
{
    Parent();
// @fnv 0x00d63df0
    virtual Parent* FUN_00d63df0(unsigned int flags);
};
Parent::Parent()
{}

// FUN_00d63e00 : MSVC this-adjusting thunk  (sub ecx, 0x2c ; jmp <impl>)
struct A1_00d63e00
{
    A1_00d63e00();
    virtual void AdjustThisAndForward_00d63e00();
    char pad[0x28];
};
struct A2_00d63e00
{
    A2_00d63e00();
    virtual void AdjustThisAndForward_00d63e00();
};
struct Own_00d63e00 : A1_00d63e00, A2_00d63e00
{
    Own_00d63e00();
    virtual void key_fn();
// @fnv 0x00d63e00
// src: GUESS 0x00d63e00 (confidence: low)
    void AdjustThisAndForward_00d63e00();
};
Own_00d63e00::Own_00d63e00()
{}
void Own_00d63e00::key_fn()
{}
Own_00d63e00* make_00d63e00()
{
    static Own_00d63e00 o;
    return &o;
}

template <class T>
inline int indexOf(const hkArray<T>& array, T value)
{
    for (int i = 0; i < array.m_iElementCount; ++i)
    {
        if (array.m_data[i] == value)
            return i;
    }
    return -1;
}

template <class T>
inline void removeAt(hkArray<T>& array, int index)
{
    array.m_iElementCount--;
    if (array.m_iElementCount != index)
        array.m_data[index] = array.m_data[array.m_iElementCount];
}

class D63590List
{
  public:
    int unk00;
    int unk04;
    hkArray<unsigned int> m_items;

    void hkpVehicleViewer_actionRemovedCallback(unsigned int value);
};

// Finds value in m_items, removes it at that index, and releases its reference.
// @fnv 0x00d63590
// src: HAVOK_LIB 0x00d63590
void D63590List::hkpVehicleViewer_actionRemovedCallback(unsigned int value)
{
    int index = indexOf(m_items, value);
    if (index != -1)
    {
        removeAt(m_items, index);
        ((hkReferencedObject*)value)->removeReference();
    }
}


template <>
void hkArrayBase<char>::_spliceInto(hkMemoryAllocator& kSharedAlloc, int index, int aiNumDelete, const char* apSource,
                                   int aiNumInsert)
{
    hkMemoryAllocator& alloc = reinterpret_cast<hkMemoryAllocator&>(kSharedAlloc);
    int iNewLength = m_iElementCount - aiNumDelete + aiNumInsert;
    int numtomove = m_iElementCount - index - aiNumDelete;
    const int iCapacity = getCapacity();
    if (iCapacity < iNewLength)
    {
        int iDoubledCapacity = 2 * iCapacity;
        int iNewCapacity = (iNewLength < iDoubledCapacity) ? iDoubledCapacity : iNewLength;
        hkArrayUtil__reserve(&alloc, this, iNewCapacity, sizeof(char));
    }
    D625A0MemMove(m_data + index + aiNumInsert, m_data + index + aiNumDelete, numtomove * sizeof(char));
    char* dst = m_data + index;
    for (int i = 0; i < aiNumInsert; ++i)
        dst[i] = apSource[i];
    m_iElementCount = iNewLength;
}