#define FNV64_HKVECTOR4_OWN_DEFAULT
#define FNV64_HKVECTOR4_OWN_ASSIGN
#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/hkArray.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../include/hkpPhysicsContext.h"
#include "../../../../../../../include/hkpWorld.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkpPhantomListener.h"
#include "../../../../../../../include/hkpWorldPostSimulationListener.h"
#include "../../../../../../../include/hkpWorldViewerBase.h"
#include "../../../../../../../include/Transform.h"


// src/havok/physics/utilities/visualdebugger/viewer/dynamics/hkpphantomdisplayviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/hkpphantomdisplayviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern int DAT_01269cd0;
extern int DAT_01268ff0;
void* __cdecl hkpPhantomDisplayViewer_create();
struct HKProcessFactory
{
    void* __thiscall RegisterProcess(const char* name, void* creator);
};
void* __cdecl hkProcessFactory_registerProcess(void* factory, const char* name, void* creator);
// @fnv 0x00d66af0
void* __cdecl RegisterPhantomsProcess()
{
    DAT_01268ff0 = (int)((HKProcessFactory*)DAT_01269cd0)->RegisterProcess("Phantoms", (void*)&hkpPhantomDisplayViewer_create);
    return (void*)DAT_01268ff0;
}

struct Container
{
    void __thiscall ClearValue(void*);
};

struct World
{
    void __thiscall hkpWorld_removePhantomListener(void*);
};

struct hkpPhantomDisplayViewer
{
    void removeWorld(void*);
};

// @fnv 0x00d66250
// src: HAVOK_LIB 0x00d66250
void hkpPhantomDisplayViewer::removeWorld(void* arg)
{
    void* p1 = this ? (char*)this + 0x28 : 0;
    ((World*)arg)->hkpWorld_removePhantomListener(p1);
    void* p2 = this ? (char*)this + 0x2c : 0;
    ((Container*)arg)->ClearValue(p2);
    int i = 0;
    if (*(int*)((char*)arg + 0x114) > 0)
    {
        char* base = (char*)this + 0x28;
        do
        {
            void* item = *(void**)(*(int*)((char*)arg + 0x110) + i * 4);
            void* vt = *(void**)base;
            void* fn = *(void**)((char*)vt + 8);
            ((void(__thiscall*)(void*, void*))fn)(base, item);
            ++i;
        } while (i < *(int*)((char*)arg + 0x114));
    }
}

struct FUN_00c93860_stub
{
    void hkpWorld_addPhantomListener(void* arg);
};

struct FUN_00d662c0_stub
{
    void AttachToIsland(void* arg);
};

// @fnv 0x00d662c0
void FUN_00d662c0_stub::AttachToIsland(void* pIsland)
{
    char* pSelf = (char*)this;
    void* p1;
    if (pSelf)
        p1 = pSelf + 0x28;
    else
        p1 = 0;
    hkpWorld* edi = (hkpWorld*)pIsland;
    ((FUN_00c93860_stub*)edi)->hkpWorld_addPhantomListener(p1);
    void* p2;
    if (pSelf)
        p2 = pSelf + 0x2c;
    else
        p2 = 0;
    edi->hkpWorld_addWorldPostSimulationListener(p2);
    int i = 0;
    if (edi->m_kPhantoms.m_iElementCount > 0)
    {
        char* base = pSelf + 0x28;
        do
        {
            void* item = ((void**)edi->m_kPhantoms.m_data)[i];
            void* pVtable = *(void**)base;
            ((void(__thiscall*)(void*, void*)) * (void**)((char*)pVtable + 4))(base, item);
            ++i;
        } while (i < edi->m_kPhantoms.m_iElementCount);
    }
}

void* _D1A0E0GetMemoryRouter();

struct FUN_00d663f0_Class
{
    void* m_unknown0;
    void* m_unknown1;
    hkArray<int> m_ppData;

    void __thiscall AppendInt(int value);
};

// @fnv 0x00d663f0
void __thiscall FUN_00d663f0_Class::AppendInt(int value)
{
    hkArray<int>& array = m_ppData;
    hkMemoryRouter* router = static_cast<hkMemoryRouter*>(_D1A0E0GetMemoryRouter());

    if (array.m_iElementCount == (array.m_iCapacityState & 0x3fffffff))
        hkArrayUtil::_reserveMore(*reinterpret_cast<hkMemoryAllocator*>(router->m_heap), &array, 4);

    int* element = array.m_data + array.m_iElementCount;
    if (element)
        *element = value;

    ++array.m_iElementCount;
}

namespace fnv_00d66b60 {
struct hkpPhantomDisplayViewer
{
    void* m_vptr;
    unsigned short m_iElementCount;

    void FUN_00d66490();
    void* Destroy(int flags);
};

hkMemoryRouter* __cdecl _D1A0E0GetMemoryRouter();

// @fnv 0x00d66b60
void* hkpPhantomDisplayViewer::Destroy(int flags)
{
    FUN_00d66490();

    if (flags & 1)
    {
        hkMemoryRouter* router = _D1A0E0GetMemoryRouter();
        unsigned short size = m_iElementCount;
        hkMemoryAllocator* manager = reinterpret_cast<hkMemoryAllocator*>(router->m_heap);
        manager->blockFree(this, size);
    }

    return this;
}
}  // namespace fnv_00d66b60

struct FnvCpu_FUN_00d66370_CpuTarget
{
    void removeWorld();
};
struct FnvCpu_FUN_00d66370_CpuOwner
{
    void ProcessState_00d66370();
};
// @fnv 0x00d66370
// src: GUESS 0x00d66370 (confidence: low)
void FnvCpu_FUN_00d66370_CpuOwner::ProcessState_00d66370()
{
    reinterpret_cast<FnvCpu_FUN_00d66370_CpuTarget*>(reinterpret_cast<char*>(this) + (-32))->removeWorld();
}

// add ecx,-0x20; jmp AttachToIsland : override in Derived forwards to the primary base's virtual.
struct PrimaryBase
{
    virtual void AttachToIsland();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

struct SecondaryBase
{
    virtual void AttachToIsland_Thunk();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
    virtual void AttachToIsland_Thunk();
};

Derived::Derived()
{}

// Calls the base constructor AttachToIsland on this object.
// @fnv 0x00d66380
// src: GUESS 0x00d66380 (confidence: medium)
void Derived::AttachToIsland_Thunk()
{
    this->PrimaryBase::AttachToIsland();
}

extern int DAT_01268ff0;

// @fnv 0x00d66b10
// src: GUESS 0x00d66b10 (confidence: low)
int __cdecl Hkpphantomdisplayviewer_GetDAT01268ff0()
{
    return DAT_01268ff0;
}

struct FUN_00d66330_StandIn
{
    void* m_ppVirtualMethodTable;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    hkpPhysicsContext* m_pShapeCollection;
    void ProcessEntries_00d66330();
};
// @fnv 0x00d66330
// src: GUESS 0x00d66330 (confidence: low)
void FUN_00d66330_StandIn::ProcessEntries_00d66330()
{
    if (m_pShapeCollection)
    {
        for (int i = 0; i < m_pShapeCollection->m_numWorlds; ++i)
        {
            reinterpret_cast<FUN_00d662c0_stub*>(reinterpret_cast<char*>(this) - 8)
                ->AttachToIsland(m_pShapeCollection->m_ppWorlds[i]);
        }
    }
}

struct Viewer
{
    int unk00, unk04, unk08, unk0c;
    void* callbackState;
};

struct Callback
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void notify(void* field, int global, void* value);
};

extern int DAT_01268ff0;

struct OwnerBase
{
    Callback* callback;
    int unk04, unk08, unk0c;
};

struct ViewerList
{
    void* unk00;
    void* unk04;
    Viewer** entries;
    volatile int count;
    int capacity;
    void RemoveViewer(Viewer* target);
};

struct ViewerOwner : OwnerBase, ViewerList
{
};

// Scans entries for target, decrements count, moves the last entry into its slot, and notifies the owner's callback with the target's callbackState.
// @fnv 0x00d66390
void ViewerList::RemoveViewer(Viewer* pViewer)
{
    int index = 0;
    int length = count;
    if (length > 0)
    {
        Viewer** cursor = entries;
        do
        {
            if (*cursor == pViewer)
            {
                if (index >= 0)
                {
                    --count;
                    int newCount = count;
                    if (newCount != index)
                        entries[index] = entries[newCount];

                    ViewerOwner* owner = static_cast<ViewerOwner*>(this);
                    owner->callback->notify(&pViewer->callbackState, DAT_01268ff0, pViewer->callbackState);
                    return;
                }
                return;
            }
            ++index;
            ++cursor;
        } while (index < length);
        return;
    }
    return;
}

void* __cdecl hkMemoryRouter_getInstance();
struct FnvCpu_FUN_00d66770_CpuBlock
{
    unsigned int unk00;
    unsigned short size;
    FnvCpu_FUN_00d66770_CpuBlock* FUN_00d66430(unsigned int value);
};
// @fnv 0x00d66770
// src: XBOX_PDB 0x00d66770
void* __cdecl hkpPhantomDisplayViewer_create(unsigned int value)
{
    hkMemoryRouter* pCpuHolder = static_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance());
    FnvCpu_FUN_00d66770_CpuBlock* pCpuBlock =
        static_cast<FnvCpu_FUN_00d66770_CpuBlock*>(reinterpret_cast<hkMemoryAllocator*>(pCpuHolder->m_heap)->blockAlloc(60));
    pCpuBlock->size = 60;
    pCpuBlock = pCpuBlock->FUN_00d66430(value);
    if (pCpuBlock)
        return reinterpret_cast<char*>(pCpuBlock) + 8;
    return 0;
}

namespace fnv_00e015d0 {
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
extern char DAT_0102e388;
struct HavokArrayOwner : hkReferencedObject
{
    hkArray<unsigned int> m_items;
    HavokArrayOwner* DestroyHavokArrayOwner(unsigned int deletionFlags);
};
// Frees the owned data array through the allocator, resets the owner to empty, and optionally deallocates the object itself.
// @fnv 0x00e015d0
HavokArrayOwner* HavokArrayOwner::DestroyHavokArrayOwner(unsigned int deletionFlags)
{
    hkMemoryRouter* router = hkMemoryRouter_getInstance();
    hkMemoryAllocator* allocator = reinterpret_cast<hkMemoryAllocator*>(router->m_heap);
    int previousCapacity = m_items.m_iCapacityState;
    m_items.m_iElementCount = 0;
    if ((previousCapacity & 0x80000000) == 0)
    {
        allocator->bufFree(m_items.m_data, (previousCapacity & 0x3fffffff) * 4);
    }
    m_items.m_data = 0;
    m_items.m_iCapacityState = 0x80000000;
    *reinterpret_cast<void**>(this) = &DAT_0102e388;
    if (deletionFlags & 1)
    {
        hkMemoryRouter* router2 = hkMemoryRouter_getInstance();
        reinterpret_cast<hkMemoryAllocator*>(router2->m_heap)->blockFree(this, m_usMemSizeAndFlags);
    }
    return this;
}
}  // namespace fnv_00e015d0

class FUN_00d66430 : public hkpWorldViewerBase,
                     protected hkpPhantomListener,
                     protected hkpWorldPostSimulationListener
{
  public:
    FUN_00d66430(const void* contexts);
    hkArray<void*> m_kContexts;
};
// Constructor that passes contexts to the shared viewer base; its own body is empty.
// @fnv 0x00d66430
FUN_00d66430::FUN_00d66430(const void* contexts) : hkpWorldViewerBase(contexts)
{}

namespace phantomViewerMemory {
extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance() throw();
}



inline void* hkReferencedObject::operator new(std::size_t nbytes)
{
    hkReferencedObject* b = static_cast<hkReferencedObject*>(
        reinterpret_cast<hkMemoryAllocator&>(phantomViewerMemory::hkMemoryRouter_getInstance().heap()).blockAlloc(nbytes));
    b->m_usMemSizeAndFlags = (unsigned short)nbytes;
    return b;
}

// Vtable 0x010d1c2c belongs to a 20-byte referenced array owner (8-byte base plus 12-byte array).
class ReferencedArrayOwner : public hkReferencedObject
{
  public:
    hkArray<void*> m_items;
    virtual ~ReferencedArrayOwner();
};

// Allocates the referenced array owner through the shared Havok base.
// @fnv 0x00d66730
hkReferencedObject* __cdecl CreateHkObject()
{
    return new ReferencedArrayOwner();
}

__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return reinterpret_cast<hkMemoryAllocator&>(phantomViewerMemory::hkMemoryRouter_getInstance().heap());
}

template <typename T>
__forceinline void hkArrayBase<T>::clear()
{
    for (int i = 0; i < m_iElementCount; ++i)
        m_data[i].~T();
    m_iElementCount = 0;
}

template <typename T>
__forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& allocator)
{
    clear();
    if ((m_iCapacityState & 0x80000000) == 0)
        allocator.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
    m_data = 0;
    m_iCapacityState = 0x80000000;
}

template <typename T, typename Allocator>
__forceinline hkArray<T, Allocator>::~hkArray() throw()
{
    clearAndDeallocate();
}

template <typename T>
__forceinline void hkArrayBase<T>::removeAt(int index)
{
    --m_iElementCount;
    if (m_iElementCount != index)
        m_data[index] = m_data[m_iElementCount];
}

template <typename T>
__forceinline void hkArrayUtil::constructWithCopy(T* elements, int count, const T& value, hkTypeIsPod)
{
    for (int i = 0; i < count; ++i)
        elements[i] = value;
}

template <typename T>
__forceinline void hkArrayBase<T>::_pushBack(hkMemoryAllocator& allocator, const T& value)
{
    if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
        hkArrayUtil::_reserveMore(allocator, this, sizeof(T));
    hkArrayUtil::constructWithCopy(m_data + m_iElementCount, 1, value, hkTypeIsPod());
    ++m_iElementCount;
}

inline hkpPhantomListener::~hkpPhantomListener()
{}

inline hkpWorldPostSimulationListener::~hkpWorldPostSimulationListener() throw()
{}

namespace FUN_00d66490 {
class hkpPhantomDisplayViewer : public hkpWorldViewerBase,
                                public hkpPhantomListener,
                                public hkpWorldPostSimulationListener
{
  public:
    virtual ~hkpPhantomDisplayViewer();
    virtual int GetOperationType();
    virtual void WorldRemovedCallback(hkpWorld* pkWorld);
    virtual void PhantomAddedCallback(hkpPhantom* pkPhantom);
    virtual void postSimulationCallback(hkpWorld* pkWorld);

    void removeWorld(hkpWorld* pkWorld) throw();

    hkArray<int> m_kIds;
};

// Destructor that detaches from each world in the physics context when it is set.
// @fnv 0x00d66490
hkpPhantomDisplayViewer::~hkpPhantomDisplayViewer()
{
    if (m_iValueAtOffset0C)
    {
        for (int i = 0; i < m_iValueAtOffset0C->m_numWorlds; i++)
            removeWorld(m_iValueAtOffset0C->m_ppWorlds[i]);
    }
}
}

extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
inline void* operator new(unsigned int, void* p)
{
    return p;
}

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_0126835c;
extern "C" const char str_010d1c38[];
extern "C" const char str_010c41f8[];
struct MonitorCommand
{
    const char* name;
    unsigned int time0, time1;
    void setTime()
    {
        _ReadWriteBarrier();
        volatile unsigned int uiTicks = (unsigned int)__rdtsc();
        time0 = uiTicks;
    }
    void setTime(volatile unsigned int& slot)
    {
        _ReadWriteBarrier();
        slot = (unsigned int)__rdtsc();
        time0 = slot;
    }
};

inline hkMonitorStream& hkMonitorStream::getInstance()
{
    return *(hkMonitorStream*)TlsGetValue(DAT_0126835c);
}

static __forceinline void Monitor(const char* name)
{
    hkMonitorStream& stream = hkMonitorStream::getInstance();
    if (stream.m_end.m_storage < stream.m_capacityMinus16.m_storage)
    {
        MonitorCommand* cmd = (MonitorCommand*)stream.m_end.m_storage;
        cmd->name = name;
        cmd->setTime();
        stream.m_end.m_storage = (char*)(cmd + 1);
    }
}
static __forceinline void Monitor(const char* name, volatile unsigned int& slot)
{
    hkMonitorStream& stream = hkMonitorStream::getInstance();
    if (stream.m_end.m_storage < stream.m_capacityMinus16.m_storage)
    {
        MonitorCommand* cmd = (MonitorCommand*)stream.m_end.m_storage;
        cmd->name = name;
        cmd->setTime(slot);
        stream.m_end.m_storage = (char*)(cmd + 1);
    }
}
void* __cdecl hkMemoryRouter_getInstance();
static __forceinline hkMemoryRouter* S00d667b0_router()
{
    return (hkMemoryRouter*)hkMemoryRouter_getInstance();
}
extern "C" void __cdecl hkArrayUtil__reserve(hkMemoryAllocator*, void*, int, int);
template <class T> struct LocalArray
{
    T* data;
    int size;
    int capacity;
    T* localMemory;
    __forceinline LocalArray(int count)
    {
        data = 0;
        size = 0;
        capacity = 0x80000000;
        hkMemoryRouter* router = S00d667b0_router();
        T* cur = (T*)router->m_stack.m_next.m_storage;
        router->m_stack.m_next.m_storage = (void*)((int)((char*)cur + (((unsigned int)count * sizeof(T) + 127u) & ~127u)));
        capacity = count | 0x80000000;
        data = cur;
        localMemory = cur;
    }
    static __forceinline void destruct(T* t, int n)
    {
        for (int i = 0; i < n; ++i)
            t[i].~T();
    }
    static __forceinline void construct(T* t, int n)
    {
        for (int i = 0; i < n; ++i)
            ::new (t + i) T;
    }
    __forceinline void clear()
    {
        destruct(data, size);
        size = 0;
    }
    __forceinline void reserve(hkMemoryAllocator& a, int n)
    {
        const int cap = capacity & 0x3fffffff;
        if (cap < n)
        {
            int newSize = cap * 2;
            if (n >= newSize)
                newSize = n;
            hkArrayUtil__reserve(&a, this, newSize, sizeof(T));
        }
    }
    __forceinline void SetSizeAndGrow(int count)
    {
        reserve(*reinterpret_cast<hkMemoryAllocator*>(S00d667b0_router()->m_heap), count);
        destruct(data + count, size - count);
        construct(data + size, count - size);
        size = count;
    }
    __forceinline void deallocate(hkMemoryAllocator& allocator)
    {
        clear();
        if ((capacity & 0x80000000) == 0)
            allocator.bufFree(data, (capacity & 0x3fffffff) * sizeof(T));
    }
    __forceinline void releaseLocal()
    {
        if (localMemory == data)
            clear();
        T* lm = localMemory;
        S00d667b0_router()->m_stack.m_next.m_storage =(void*)( (void*)((int)lm));
        deallocate(*reinterpret_cast<hkMemoryAllocator*>(S00d667b0_router()->m_heap));
    }
    __forceinline void releaseAndReset()
    {
        releaseLocal();
        data = 0;
        capacity = 0x80000000;
    }
};
__forceinline hkVector4::hkVector4()
{}

struct __declspec(align(16)) Aabb
{
    hkVector4 min, max;
};
struct DisplayGeometry : hkReferencedObject
{
    virtual ~DisplayGeometry();
    void* geometry;
    Transform transform;
    int type;
};
struct FUN_00de1210 : DisplayGeometry
{
    Aabb bounds;
    FUN_00de1210();
    virtual ~FUN_00de1210();
    void hkDisplayAABB_setExtents(const hkVector4&, const hkVector4&);
};
struct Collidable
{
    void* shape;
    unsigned int shapeKey;
    const Transform* motion;
};
struct Phantom : hkReferencedObject
{
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void getAabb(Aabb&) const;
    void* world;
    unsigned int userData;
    Collidable collidable;
};
struct DisplayHandler
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void m_bUpdateGeometry(const Transform*, const void*, int);
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void DisplayGeometryList(LocalArray<DisplayGeometry*>&, int, int, int);
};
struct ProcessBase
{
    virtual void processSlot0();
    int unk04, unk08;
    DisplayHandler* displayHandler;
    int unk10, unk14, unk18, unk1c;
};

extern int DAT_01268ff0;
struct S00d667b0_Viewer : ProcessBase, hkpWorldPostSimulationListener
{
    Phantom** tracked;
    int trackedCount;
    int trackedCapacity;
    virtual void postSimulationCallback(hkpWorld*);
    __forceinline void updateTracked()
    {
        for (int i = 0; i < trackedCount; ++i)
        {
            Phantom* phantom = tracked[i];
            displayHandler->m_bUpdateGeometry(phantom->collidable.motion, &phantom->collidable, DAT_01268ff0);
        }
    }
};
extern int DAT_01268ff0;
extern int DAT_01268ff4;
// Builds display geometry boxes from the phantom world's AABBs, submits them to the display handler, and updates tracked phantoms.
// @fnv 0x00d667b0
void S00d667b0_Viewer::postSimulationCallback(hkpWorld* pkWorld)
{
    hkpWorld* world = pkWorld;
    Monitor(str_010d1c38);
    {
        const hkArray<hkpPhantom*>& phantoms = world->m_kPhantoms;
        LocalArray<FUN_00de1210> boxes(phantoms.m_iElementCount);
        boxes.SetSizeAndGrow(phantoms.m_iElementCount);
        LocalArray<DisplayGeometry*> geometries(phantoms.m_iElementCount);
        geometries.SetSizeAndGrow(phantoms.m_iElementCount);
        for (int i = 0; i < phantoms.m_iElementCount; ++i)
        {
            Aabb bounds;
            reinterpret_cast<Phantom*>(phantoms.m_data[i])->getAabb(bounds);
            boxes.data[i].hkDisplayAABB_setExtents(bounds.min, bounds.max);
            geometries.data[i] = boxes.data + i;
        }
        DisplayHandler* handler = displayHandler;
        handler->DisplayGeometryList(geometries, DAT_01268ff4, 0, DAT_01268ff0);
        geometries.releaseAndReset();
        boxes.releaseLocal();
    }
    updateTracked();
    Monitor(str_010c41f8);
}

namespace fnv_00d66b20 {
// sub ecx,0x20; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x20).
struct PrimaryBase
{
    virtual void AdjustThisAndForward_00d66b20();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

struct SecondaryBase
{
    virtual void AdjustThisAndForward_00d66b20();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d66b20
// src: GUESS 0x00d66b20 (confidence: low)
    virtual void AdjustThisAndForward_00d66b20();
};

Derived::Derived()
{}
}  // namespace fnv_00d66b20

namespace fnv_00d66b30 {
// sub ecx,8; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (8).
struct PrimaryBase
{
    virtual void FUN_00d66b30();
    int unk04;
};

struct SecondaryBase
{
    virtual void FUN_00d66b30();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d66b30
    virtual void FUN_00d66b30();
};

Derived::Derived()
{}
}  // namespace fnv_00d66b30

namespace fnv_00d66b40 {
// sub ecx,0x28; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x28).
struct PrimaryBase
{
    virtual void AdjustThisAndForward_00d66b40();
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

struct SecondaryBase
{
    virtual void AdjustThisAndForward_00d66b40();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d66b40
// src: GUESS 0x00d66b40 (confidence: low)
    virtual void AdjustThisAndForward_00d66b40();
};

Derived::Derived()
{}
}  // namespace fnv_00d66b40

// Candidate 2 for FUN_00d66b50: this-adjusting thunk {adjustor 0x2c}. The displacement is the
// distance between the two copies of the host base, so the host base is made 44 bytes:
// Plat(8) + Host(44) at 8, Shim : Host at +0x34 -> copies at 8 and 0x34-8? -> delta 0x2c.
// The final overrider's body lives in the next translation unit (0xd66b60), declared only.

struct ThunkH_Plat
{
    void* t_unk00;
    virtual void vf0_aux(int* pArg);
};

struct ThunkH_Host
{
    void* h_unk04;
    void* h_unk08;
    void* h_unk0c;
    void* h_unk10;
    void* h_unk14;
    void* h_unk18;
    void* h_unk1c;
    void* h_unk20;
    void* h_unk24;
    void* h_unk28;
    virtual void FUN_00d66b50(int* pArg);
};

struct ThunkH_Shim : ThunkH_Host
{
    void* s_unk2c;
};

struct ThunkH_Derived : ThunkH_Plat, ThunkH_Host, ThunkH_Shim
{
    ThunkH_Derived();
// @fnv 0x00d66b50
    void FUN_00d66b50(int* pArg);
    void* d_unk40;
};

ThunkH_Derived::ThunkH_Derived()
{}

namespace fnv_00d66530 {
extern int DAT_01268ff0;
extern int DAT_01268ff4;
extern const char str_010d196c[];
extern const char str_010d1be8[];

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();

struct Vw66530Entry
{
    virtual ~Vw66530Entry();
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
};

struct Vw66530Info
{
    int unk00;
    int unk04;
    int unk08;
};

struct Vw66530Arg
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual int getType();
    int unk04;
    int unk08;
    int unk0C;
    Vw66530Info m_info;
};

struct Vw66530Global
{
    int unk00;
    int unk04;
    hkArray<int> m_types;
};
extern Vw66530Global* DAT_01268fec;

struct Vw66530Logger
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void log(int a, int b, const char* msg, const char* file, int line);
};
extern Vw66530Logger* DAT_01268360;

struct Vw66530Str
{
    int unk00;
    int unk04;
    int unk08;
    void FUN_00cb1600(char* buf, int size);
    void ProcessAndReturnValue_00cc01c0(const char* s);
    void FUN_00cc00e0();
};

struct Vw66530Obj
{
    int unk00;
    int unk04;
    void hkpShapeDisplayBuilder_hkpShapeDisplayBuilderEnvironment_hkpShapeDisplayBuilderEnvironment();
};
struct Vw66530Col
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    void hkpShapeDisplayBuilder_hkpShapeDisplayBuilder(Vw66530Obj* o);
    void UpdateState_00de0f90(int root, hkArrayBase<Vw66530Entry*>* out);
};

struct Vw66530Disp
{
    virtual void v00();
    virtual void add(hkArrayBase<Vw66530Entry*>* arr, int a, Vw66530Info* info, int tag, int root);
    virtual void v08();
    virtual void update(int b, Vw66530Info* info, int tag);
};

struct Vw66530Self
{
    int unk00;
    int unk04;
    hkArray<Vw66530Arg*> m_args;
    void hkpPhantomDisplayViewer_phantomAddedCallback(Vw66530Arg* arg);
};

struct Vw66530Outer
{
    Vw66530Disp* m_disp;
    int unk04;
    int unk08;
    int unk0C;
    Vw66530Self self;
};

// For an allowed type and nonzero root, collects entries, drops and logs some, stores arg, then calls the dispatcher's add and update.
// @fnv 0x00d66530
// src: HAVOK_LIB 0x00d66530
void Vw66530Self::hkpPhantomDisplayViewer_phantomAddedCallback(Vw66530Arg* arg)
{
    int root = arg->m_info.unk00;
    Vw66530Info* info = &arg->m_info;
    int type = arg->getType();
    hkArrayBase<Vw66530Entry*> entries;
    Vw66530Str str;
    Vw66530Col col;
    Vw66530Obj o;
    int buf[0x80];
    bool bValid = true;
    if (type != 1 && type != 2)
        bValid = DAT_01268fec->m_types.indexOf(type) != -1;
    if (!bValid || root == 0)
        goto done;
    o.hkpShapeDisplayBuilder_hkpShapeDisplayBuilderEnvironment_hkpShapeDisplayBuilderEnvironment();
    col.hkpShapeDisplayBuilder_hkpShapeDisplayBuilder(&o);
    col.UpdateState_00de0f90(root, &entries);
    for (int i = entries.m_iElementCount - 1; i >= 0; i--)
    {
        Vw66530Entry* pEntry = entries.m_data[i];
        if (pEntry->unk50 == 6 && pEntry->unk08 == 0)
        {
            str.FUN_00cb1600((char*)buf, 0x200);
            str.ProcessAndReturnValue_00cc01c0(str_010d196c);
            DAT_01268360->log(0, -1, (char*)buf, str_010d1be8, 0x91);
            str.FUN_00cc00e0();
            entries.removeAt(i);
        }
    }
    m_args.pushBack(arg);
    Vw66530Outer* outer = reinterpret_cast<Vw66530Outer*>((char*)this - 0x10);
    outer->m_disp->add(&entries, info->unk08, info, DAT_01268ff0, root);
    outer->m_disp->update(DAT_01268ff4, info, DAT_01268ff0);
    for (int k = 0; k < entries.m_iElementCount; k++)
        delete entries.m_data[k];
done:
    entries._clearAndDeallocate(hkContainerHeapAllocator().get(&entries));
}
}  // namespace fnv_00d66530
