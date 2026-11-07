
// src/havok/physics/utilities/visualdebugger/viewer/dynamics/hkpconstraintviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/hkpconstraintviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/Transform.h"
#include "../../../../../../../include/hkDisplayGeometry.h"
#include "../../../../../../../include/hkProcessFactory.h"

struct FUN_00d69a80
{
    ~FUN_00d69a80();
};

// Destructs the four hkDisplayGeometry members embedded at offsets 0x280, 0x1f0, 0x160 and 0xd0 of this object.
// @fnv 0x00d69a80
FUN_00d69a80::~FUN_00d69a80()
{
    ((hkDisplayGeometry*)((char*)this + 0x280))->hkDisplayGeometry::~hkDisplayGeometry();
    ((hkDisplayGeometry*)((char*)this + 0x1f0))->hkDisplayGeometry::~hkDisplayGeometry();
    ((hkDisplayGeometry*)((char*)this + 0x160))->hkDisplayGeometry::~hkDisplayGeometry();
    ((hkDisplayGeometry*)((char*)this + 0xd0))->hkDisplayGeometry::~hkDisplayGeometry();
}

class D698B0Listener
{
  public:
    virtual void unk00();
};

struct D698B0ListenerArray
{
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    D698B0ListenerArray() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};

class D698B0Island
{
  public:
    void addListener(D698B0Listener* listener);
};

struct D698B0World
{
    char unk00[0x6c];
    D698B0Island** m_islands;
    int m_iIslandCount;
};

class D698B0BaseA
{
  public:
    virtual void unk00();

    int unk04;
};

class D698B0BaseB
{
  public:
    virtual void unk00();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class D698B0BaseC
{
  public:
    virtual void unk00();
};

class D698B0Base : public D698B0BaseA, public D698B0BaseB, public D698B0BaseC
{
  public:
    D698B0Base(void* info);

    D698B0World* m_pOwningWorld;
};

class FUN_00d698b0 : public D698B0Base, public D698B0Listener
{
  public:
    FUN_00d698b0(void* info);

    D698B0ListenerArray m_entries;
};

// Base constructor then, if a world is set, registers this listener with every island in that world.
// @fnv 0x00d698b0
FUN_00d698b0::FUN_00d698b0(void* info) : D698B0Base(info)
{
    if (m_pOwningWorld)
    {
        for (int i = 0; i < m_pOwningWorld->m_iIslandCount; i++)
            m_pOwningWorld->m_islands[i]->addListener(this);
    }
}


extern hkProcessFactory* hkProcessFactory_registerProcess;
extern void* DAT_0126901c;
void hkpConstraintViewer_Create();
// @fnv 0x00d69a00
void RegisterConstraintsProcessFactory()
{
    DAT_0126901c = hkProcessFactory_registerProcess->RegisterProcess("Constraints", (void*)&hkpConstraintViewer_Create);
}

struct S_00d69a20_Base
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
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
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    S_00d69a20_Base();
};
struct S_00d69a20_Mem
{
    int unk0;
    S_00d69a20_Mem();
};
struct FUN_00d69a20 : S_00d69a20_Base
{
    S_00d69a20_Mem unkD0;
    FUN_00d69a20();
};
// @fnv 0x00d69a20
FUN_00d69a20::FUN_00d69a20()
{}

struct SpawnedTarget
{
    void hkpWorld_addWorldPostSimulationListener(void* p);
};

struct FUN_00d69200_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;

    void ProcessAndTransformResult_00d69200(SpawnedTarget* target);
};

// Passes a pointer derived from this (this+8, or null when this-0x20 is null) to target->FUN_00c93920.
// @fnv 0x00d69200
// src: GUESS 0x00d69200 (confidence: low)
void FUN_00d69200_cls::ProcessAndTransformResult_00d69200(SpawnedTarget* target)
{
    target->hkpWorld_addWorldPostSimulationListener(((char*)this - 0x20) != 0 ? (char*)this + 8 : 0);
}

struct Target
{
    void ClearValue(void* apArg);
};

struct FUN_00d69230_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;

    void InvokeTargetWithSelfOffset(Target* apTarget);
};

// Calls apTarget->ClearValue with a pointer to this+8, or null if this-0x20 is null.
// @fnv 0x00d69230
void FUN_00d69230_cls::InvokeTargetWithSelfOffset(Target* apTarget)
{
    apTarget->ClearValue(((char*)this - 0x20) != 0 ? (char*)this + 8 : 0);
}

namespace fnv_00d69920 {
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

struct Target
{
    void ClearValue(void* apArg);
};

struct OwnerNode
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
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    Target** m_ppItems;
    int m_iArrayLength;
};

struct PrimaryBase
{
    virtual void unk00();
    unsigned int unk04;
    ~PrimaryBase();
};

struct MidBase
{
    virtual void unk00();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};

struct TailBase
{
    virtual void unk00();
    OwnerNode* m_pSharedOwner;
};

struct SubObject
{
    virtual ~SubObject()
    {}
};

struct FUN_00d69920_cls : PrimaryBase, MidBase, TailBase, SubObject
{
    void* m_pData;
    int m_iField30;
    unsigned int m_uiObjectFlags;

    ~FUN_00d69920_cls() throw();
};

// @fnv 0x00d69920
FUN_00d69920_cls::~FUN_00d69920_cls() throw()
{
    if (m_pSharedOwner != 0)
    {
        for (int i = 0; i < m_pSharedOwner->m_iArrayLength; ++i)
        {
            m_pSharedOwner->m_ppItems[i]->ClearValue(static_cast<SubObject*>(this));
        }
    }
    hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
    m_iField30 = 0;
    unsigned int uiDataFlags = m_uiObjectFlags;
    if ((uiDataFlags & 0x80000000u) == 0)
    {
        typedef void (__thiscall* FreeDataFunction)(hkMemoryAllocator*, void*, unsigned int);
        reinterpret_cast<FreeDataFunction>((*reinterpret_cast<void***>(pAllocator))[4])(
            pAllocator, m_pData, (uiDataFlags & 0x3fffffffu) * 4);
    }
    m_pData = 0;
    m_uiObjectFlags = 0x80000000u;
}
}  // namespace fnv_00d69920

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();

struct SpawnedObject
{
    int unk00;
    unsigned short m_uSize;
    unsigned short unk06;

    void* InitFrom(void* apSource);
};

// Allocates a 0x38-byte object from the audio allocator, sets its size, initializes it from apSource, and returns a pointer offset by 8 on success.
// @fnv 0x00d699c0
// src: COMMUNITY 0x00d699c0
void* __cdecl hkpConstraintViewer_Create(void* apSource)
{
    hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
    typedef void* (__thiscall* AllocFunction)(hkMemoryAllocator*, unsigned int);
    SpawnedObject* pObject = (SpawnedObject*)reinterpret_cast<AllocFunction>(
        (*reinterpret_cast<void***>(pAllocator))[1])(pAllocator, 0x38);
    pObject->m_uSize = 0x38;
    void* pResult = pObject->InitFrom(apSource);
    if (pResult != 0)
    {
        return (char*)pResult + 8;
    }
    return 0;
}

// FUN_00d69a40 (0x00d69a40, 56 bytes): the constructor of the display-geometry
// object.  It builds the base transform at +0x00, three hkDisplayCone members
// at +0xd0 / +0x160 / +0x1f0 and one hkDisplayPlane member at +0x280, then
// hands `this` back in EAX (the MSVC constructor convention).
//
// The member constructors are only DECLARED here (never defined) so that the
// compiler neither zero-fills the members nor adds any code of its own: the
// checker resolves the four call relocations against the original image.

struct FUN_00d69a40_base
{
    char _pad[0xd0];
    FUN_00d69a40_base();
};

struct FUN_00d69a40_cone
{
    char _pad[0x90];
    FUN_00d69a40_cone();
};

struct FUN_00d69a40_plane
{
    char _pad[0xa0];
    FUN_00d69a40_plane();
};

struct FUN_00d69a40
{
    FUN_00d69a40_base m00;
    FUN_00d69a40_cone m0d0;
    FUN_00d69a40_cone m160;
    FUN_00d69a40_cone m1f0;
    FUN_00d69a40_plane m280;

    FUN_00d69a40();
};

// Constructs the bundle by default-constructing its base, three cone members and one plane member.
// @fnv 0x00d69a40
FUN_00d69a40::FUN_00d69a40() : m00(), m0d0(), m160(), m1f0(), m280()
{}

typedef unsigned long unsigned32;
extern "C"
{
    extern unsigned32 g_0126901c;
// @fnv 0x00d69ab0
// src: GUESS 0x00d69ab0 (confidence: low)
    unsigned32 hkpConstraintViewer_GetGlobalValue(void)
    {
        return g_0126901c;
    }
}

struct D69AC0Primary
{
    virtual void vfunc00();
    virtual void AdjustThisAndForward_00d69ac0();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

struct D69AC0Secondary
{
    virtual void AdjustThisAndForward_00d69ac0();
};

struct D69AC0Object : D69AC0Primary, D69AC0Secondary
{
    D69AC0Object();

// @fnv 0x00d69ac0
// src: GUESS 0x00d69ac0 (confidence: low)
    virtual void AdjustThisAndForward_00d69ac0();
};

D69AC0Object::D69AC0Object()
{}

// sub ecx,8; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (8).
struct PrimaryBase
{
    virtual void FUN_00d69ad0();
    int unk04;
};

struct SecondaryBase
{
    virtual void FUN_00d69ad0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d69ad0
    virtual void FUN_00d69ad0();
};

Derived::Derived()
{}

namespace fnv_00d69ae0 {
struct Base1
{
    virtual void AdjustThisAndForward_00d69ae0();
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
struct Base2
{
    virtual void AdjustThisAndForward_00d69ae0();
};
struct Derived : Base1, Base2
{
    Derived();
// @fnv 0x00d69ae0
// src: GUESS 0x00d69ae0 (confidence: low)
    virtual void AdjustThisAndForward_00d69ae0();
};
Derived::Derived()
{}
}  // namespace fnv_00d69ae0

namespace fnv_00d69af0 {
extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance();

inline hkMemoryAllocator& heap(hkMemoryRouter& holder)
{
    return *reinterpret_cast<hkMemoryAllocator*>(holder.m_heap);
}

struct FUN_00d69af0
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    FUN_00d69af0();
    virtual ~FUN_00d69af0();

    static void operator delete(void* p, unsigned int nbytes)
    {
        FUN_00d69af0* b = static_cast<FUN_00d69af0*>(p);
        hkMemoryAllocator& allocator = heap(hkMemoryRouter_getInstance());
        typedef void (__thiscall* FreeFunction)(hkMemoryAllocator*, void*, int);
        reinterpret_cast<FreeFunction>((*reinterpret_cast<void***>(&allocator))[2])(
            &allocator, p, b->m_usMemSizeAndFlags);
    }
};

// Constructor with an empty body; the class has a vtable, m_usMemSizeAndFlags and m_sReferenceCount.
// @fnv 0x00d69af0
FUN_00d69af0::FUN_00d69af0()
{}
}  // namespace fnv_00d69af0

#include <windows.h>
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern unsigned int DAT_0126835c;

__forceinline void hkMonitorStream::TimerCommand::setTime()
{
    _ReadWriteBarrier();
    volatile unsigned int t = (unsigned int)__rdtsc();
    m_time0 = t;
}

__forceinline hkMonitorStream& hkMonitorStream::getInstance()
{
    return *(hkMonitorStream*)TlsGetValue(DAT_0126835c);
}

// A unit-local view: the original inlines a differently shaped variant of this Havok accessor.
struct hkMonitorStream_hkpconstraintviewer : hkMonitorStream { bool memoryAvailable() const; };
__forceinline bool hkMonitorStream_hkpconstraintviewer::memoryAvailable() const
{
    return m_end.m_storage < m_capacityMinus16.m_storage;
}

__forceinline char* __cdecl hkMonitorStream::getEnd()
{
    return m_end.m_storage;
}

__forceinline void __cdecl hkMonitorStream::setEnd(char* e)
{
    m_end.m_storage = e;
}

struct ConstraintInternal
{
    int m_pHavokConstraint;
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
};

struct SmallArray
{
    ConstraintInternal* m_data;
    unsigned short m_iElementCount;
    unsigned short m_pRayCursor;
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    const ConstraintInternal& operator[](int i) const
    {
        return m_data[i];
    }
};

struct Entity
{
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
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    SmallArray m_eSmallArraySerializeOverrideType;
    const SmallArray& getConstraintMasters() const
    {
        return m_eSmallArraySerializeOverrideType;
    }
};

struct EntityArray
{
    Entity** m_data;
    int m_iElementCount;
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    Entity* operator[](int i) const
    {
        return m_data[i];
    }
};

struct Island
{
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
    EntityArray m_kActorEntries;
    const EntityArray& GetEntities() const
    {
        return m_kActorEntries;
    }
};

struct IslandArray
{
    Island** m_data;
    int m_iElementCount;
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    Island* operator[](int i) const
    {
        return m_data[i];
    }
};

struct World
{
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
    IslandArray m_kActiveSimulationIslands;
    int unk30;
    IslandArray m_kInactiveSimulationIslands;
    const IslandArray& getActiveSimulationIslands() const
    {
        return m_kActiveSimulationIslands;
    }
    const IslandArray& getInactiveSimulationIslands() const
    {
        return m_kInactiveSimulationIslands;
    }
};

struct ConstraintListener
{
    virtual void hkpConstraintViewer_postSimulationCallback(World* world);
};

struct ViewerBase
{
    virtual void v00();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int m_ucOperationType;
    int unk1C;
    int unk20;
    int unk24;
};

struct ConstraintViewer : public ViewerBase, public ConstraintListener
{
    void hkpConstraintViewer_draw(int constraint, Entity* e, int tag);
    virtual void hkpConstraintViewer_postSimulationCallback(World* world);
};

// Iterates active and inactive simulation islands, calling FUN_00d69260 for each entity's constraint masters, with timing entries.
// @fnv 0x00d69730
// src: HAVOK_LIB 0x00d69730
void ConstraintViewer::hkpConstraintViewer_postSimulationCallback(World* world)
{
    int second_i;
    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (static_cast<const hkMonitorStream_hkpconstraintviewer&>(mStream).memoryAvailable())
        {
            hkMonitorStream::TimerCommand* h = (hkMonitorStream::TimerCommand*)mStream.getEnd();
            h->m_commandAndMonitor = "TthkpConstraintViewer";
            _ReadWriteBarrier();
            *(volatile unsigned int*)&second_i = (unsigned int)__rdtsc();
            h->m_time0 = *(volatile unsigned int*)&second_i;
            mStream.setEnd((char*)(h + 1));
        }
    }
    {
        const IslandArray& islands = world->getActiveSimulationIslands();
        for (int i = 0; i < islands.GetLogicalSize(); i++)
        {
            for (int e = 0; e < islands[i]->GetEntities().GetLogicalSize(); e++)
            {
                Entity* entity = islands[i]->GetEntities()[e];
                const SmallArray& masters = entity->getConstraintMasters();
                for (int c = 0; c < masters.GetLogicalSize(); c++)
                {
                    const ConstraintInternal& ci = masters[c];
                    hkpConstraintViewer_draw(ci.m_pHavokConstraint, entity, m_ucOperationType);
                }
            }
        }
    }
    {
        const IslandArray& islands = world->getInactiveSimulationIslands();
        for (second_i = 0; second_i < islands.GetLogicalSize(); second_i++)
        {
            for (int e = 0; e < islands[second_i]->GetEntities().GetLogicalSize(); e++)
            {
                Entity* entity = islands[second_i]->GetEntities()[e];
                const SmallArray& masters = entity->getConstraintMasters();
                for (int c = 0; c < masters.GetLogicalSize(); c++)
                {
                    const ConstraintInternal& ci = masters[c];
                    hkpConstraintViewer_draw(ci.m_pHavokConstraint, entity, m_ucOperationType);
                }
            }
        }
    }
    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (static_cast<const hkMonitorStream_hkpconstraintviewer&>(mStream).memoryAvailable())
        {
            hkMonitorStream::TimerCommand* h = (hkMonitorStream::TimerCommand*)mStream.getEnd();
            h->m_commandAndMonitor = "Et";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }
}

extern float DAT_011b6168;
void EnterTlsGuard();
void hkReferencedObject_unlockAll();
namespace ConstraintDrawDetail {


struct Shape
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual unsigned getType();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    Shape* child;
    Shape* hkpMalleableConstraintData_getWrappedConstraintData();
};
struct Collidable
{
    int unk00;
    int unk04;
    int unk08;
    Shape* shape;
    int unk10;
    void* first;
    void* second;
};
struct LocalCollidable : Collidable
{
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    void FUN_00cf3ea0(void*, void*, Shape*, bool);
    void hkpConstraintInstance_ProcessEntries_00cf40b0();
};

struct __declspec(align(16)) Renderer
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
    void InitializeDefaults();
    void hkpConstraintDrawer_setScale(float);
    void FireMotionEvent(Collidable*, void*, void*, void*);
    void UpdateFields_00de7f20(Collidable*, void*, void*, void*);
    void ComputeValues_00de7730(Collidable*, void*, void*, void*);
    void UpdateFields_00de7580(Collidable*, void*, void*, void*);
    void ComputeValues_00de71d0(Collidable*, void*, void*, void*);
    void UpdateViewerAndDrawPointLines(Collidable*, void*, void*, void*);
    void ProcessEntries_00de6d80(Collidable*, void*, void*, void*);
    void ProcessEntries_00de6550(Collidable*, void*, void*, void*);
    void FireChainConstraints(Collidable*, void*, void*, void*);
};
struct __declspec(align(16)) Extended : Renderer
{
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    void FUN_00d69a20();
    void DrawHingeConstraintGeometry(Collidable*, void*, void*, void*);
    void hkpConstraintInstance_DrawHinge_Thunk(Collidable*, void*, void*, void*);
};
struct Tail
{
    void FUN_00da2560();
};
struct ComplexCleanup
{
    void FUN_00d69a80();
};
struct __declspec(align(16)) Complex : Renderer
{
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    void FUN_00d69a40();
    void UpdateState_00de6730(Collidable*, void*, void*, void*);
    void ComputeValues_00de59f0(Collidable*, void*, void*, void*);
    void FUN_00d69a80();
};
struct Viewer : ConstraintViewer
{
    void hkpConstraintViewer_draw(int constraint, Entity* entity, int tag);
};
}
// Records a Ttdraw trace, dispatches on the Collidable shape type to render via renderer or Complex, recurses for compound shapes, then records an Et trace.
// @fnv 0x00d69260
// src: HAVOK_LIB 0x00d69260
void ConstraintDrawDetail::Viewer::hkpConstraintViewer_draw(int aiCollidable, Entity* entity, int tag)
{
    using namespace ConstraintDrawDetail;
    Collidable* object = reinterpret_cast<Collidable*>(aiCollidable);
    Transform* transform = reinterpret_cast<Transform*>(entity);
    void* context = reinterpret_cast<void*>(tag);
    Viewer* owner = this;
    volatile unsigned uiShapeType;
    Extended renderer;
    Complex complexRenderer;
    LocalCollidable child;
    hkMonitorStream* trace = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    if (trace->m_end.m_storage < trace->m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* entry = (hkMonitorStream::TimerCommand*)trace->m_end.m_storage;
        *(const char* volatile*)&entry->m_commandAndMonitor = "Ttdraw";
        _ReadWriteBarrier();
        uiShapeType = (unsigned)__rdtsc();
        entry->m_time0 = uiShapeType;
        trace->m_end.m_storage = (char*)(entry + 1);
    }
    uiShapeType = object->shape->getType();
    EnterTlsGuard();
    void* position = &transform->m_f10;
    switch (uiShapeType)
    {
    case 0: {
        renderer.InitializeDefaults();
        renderer.hkpConstraintDrawer_setScale(DAT_011b6168);
        renderer.FireMotionEvent(object, context, position, DAT_0126901c);
        break;
    }
    case 1: {
        renderer.InitializeDefaults();
        renderer.hkpConstraintDrawer_setScale(DAT_011b6168);
        renderer.UpdateFields_00de7f20(object, context, position, DAT_0126901c);
        break;
    }
    case 2: {
        renderer.FUN_00d69a20();
        renderer.hkpConstraintDrawer_setScale(DAT_011b6168);
        renderer.DrawHingeConstraintGeometry(object, context, position, DAT_0126901c);
        ((Tail*)&renderer.unk0d0)->FUN_00da2560();
        break;
    }
    case 6: {
        renderer.InitializeDefaults();
        renderer.hkpConstraintDrawer_setScale(DAT_011b6168);
        renderer.ComputeValues_00de7730(object, context, position, DAT_0126901c);
        break;
    }
    case 8: {
        renderer.InitializeDefaults();
        renderer.hkpConstraintDrawer_setScale(DAT_011b6168);
        renderer.UpdateFields_00de7580(object, context, position, DAT_0126901c);
        break;
    }
    case 9: {
        renderer.InitializeDefaults();
        renderer.hkpConstraintDrawer_setScale(DAT_011b6168);
        renderer.ComputeValues_00de71d0(object, context, position, DAT_0126901c);
        break;
    }
    case 3: {
        renderer.InitializeDefaults();
        renderer.hkpConstraintDrawer_setScale(DAT_011b6168);
        renderer.UpdateViewerAndDrawPointLines(object, context, position, DAT_0126901c);
        break;
    }
    case 14: {
        renderer.InitializeDefaults();
        renderer.hkpConstraintDrawer_setScale(DAT_011b6168);
        renderer.ProcessEntries_00de6d80(object, context, position, DAT_0126901c);
        break;
    }
    case 7: {
        complexRenderer.FUN_00d69a40();
        complexRenderer.hkpConstraintDrawer_setScale(DAT_011b6168);
        complexRenderer.UpdateState_00de6730(object, context, position, DAT_0126901c);
        complexRenderer.FUN_00d69a80();
        break;
    }
    case 12: {
        child.FUN_00cf3ea0(object->first, object->second, object->shape->child, true);
        owner->hkpConstraintViewer_draw(reinterpret_cast<int>(&child), entity, tag);
        child.hkpConstraintInstance_ProcessEntries_00cf40b0();
        break;
    }
    case 13: {
        Shape* pParentShape = object->shape;
        void* second = object->second;
        void* first = object->first;
        child.FUN_00cf3ea0(first, second, pParentShape->hkpMalleableConstraintData_getWrappedConstraintData(), true);
        owner->hkpConstraintViewer_draw(reinterpret_cast<int>(&child), entity, tag);
        child.hkpConstraintInstance_ProcessEntries_00cf40b0();
        break;
    }
    case 15: {
        renderer.InitializeDefaults();
        renderer.hkpConstraintDrawer_setScale(DAT_011b6168);
        renderer.ProcessEntries_00de6550(object, context, position, DAT_0126901c);
        break;
    }
    case 100:
    case 101:
    case 102: {
        renderer.InitializeDefaults();
        renderer.hkpConstraintDrawer_setScale(DAT_011b6168);
        renderer.FireChainConstraints(object, context, position, DAT_0126901c);
        break;
    }
    case 18: {
        renderer.FUN_00d69a20();
        renderer.hkpConstraintDrawer_setScale(DAT_011b6168);
        renderer.hkpConstraintInstance_DrawHinge_Thunk(object, context, position, DAT_0126901c);
        ((Tail*)&renderer.unk0d0)->FUN_00da2560();
        break;
    }
    case 19: {
        complexRenderer.FUN_00d69a40();
        complexRenderer.hkpConstraintDrawer_setScale(DAT_011b6168);
        complexRenderer.ComputeValues_00de59f0(object, context, position, DAT_0126901c);
        ((ComplexCleanup*)&complexRenderer)->FUN_00d69a80();
        break;
    }
    }
    hkReferencedObject_unlockAll();
    trace = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    if (trace->m_end.m_storage < trace->m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* entry = (hkMonitorStream::TimerCommand*)trace->m_end.m_storage;
        *(const char* volatile*)&entry->m_commandAndMonitor = "Et";
        _ReadWriteBarrier();
        volatile unsigned tick = (unsigned)__rdtsc();
        entry->m_time0 = tick;
        trace->m_end.m_storage = (char*)(entry + 1);
    }
}
