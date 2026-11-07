#include "../../../../../../../include/hkpMidphaseViewer.h"
#include <new>
#include "../../../../../../../include/hkpShape.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkMemoryRouter.h"

// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpmidphaseviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/collide/hkpmidphaseviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FullObject;
struct Receiver;

struct HeadPart
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};

struct FirstBase
{
    int unk00;
    int unk04;
    void ForwardCall_00d6a250(Receiver* apReceiver);
};

struct SecondBase
{
    int unk00;
};

struct FullObject : HeadPart, FirstBase, SecondBase
{
};

typedef char _check_offsets[sizeof(FullObject) == 0x2c ? 1 : -1];

struct Receiver
{
    void ClearValue(SecondBase* apObject);
};

// Passes the enclosing FullObject (this minus 0x20) to the receiver's ClearValue.
// @fnv 0x00d6a250
// src: GUESS 0x00d6a250 (confidence: low)
void FirstBase::ForwardCall_00d6a250(Receiver* apReceiver)
{
    apReceiver->ClearValue((FullObject*)((char*)this - 0x20));
}

hkMemoryRouter* hkMemoryRouter_getInstance() throw();
struct S_00d6a750_Source
{
    void ClearValue(hkpWorldPostSimulationListener* listener) throw();
};
struct S_00d6a750_Owner
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
    S_00d6a750_Source** m_ppSources;
    int m_iNumSources;
};
inline hkpWorldPostSimulationListener::~hkpWorldPostSimulationListener() throw()
{}

template <class T> __forceinline void hkArrayUtil_destruct(T* t, int n)
{
    for (int i = 0; i < n; i++)
        t[i].~T();
}

__forceinline hkpMidphaseViewer::ElementArray::~ElementArray() throw()
{
    hkMemoryAllocator& alloc = hkMemoryRouter_getInstance()->heap();
    hkArrayUtil_destruct(m_data, m_iElementCount);
    m_iElementCount = 0;
    if ((m_iCapacityState & 0x80000000) == 0)
        alloc.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(Element));
    m_data = 0;
    m_iCapacityState = 0x80000000;
}

// @fnv 0x00d6a750
hkpMidphaseViewer::~hkpMidphaseViewer() throw()
{
    if (m_iValueAtOffset0C)
    {
        for (int i = 0; i < ((S_00d6a750_Owner*)m_iValueAtOffset0C)->m_iNumSources; i++)
            ((S_00d6a750_Owner*)m_iValueAtOffset0C)->m_ppSources[i]->ClearValue(this);
    }
}

class BSAudio;
namespace fnv_00d6a810 {


BSAudio* __cdecl hkMemoryRouter_getInstance();
inline hkMemoryRouter* audio()
{
    return (hkMemoryRouter*)hkMemoryRouter_getInstance();
}

struct RefObj
{
    void* vtbl;
    short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

inline void* hkAlloc(int n)
{
    RefObj* p = (RefObj*)audio()->heap().blockAlloc(n);
    p->m_usMemSizeAndFlags = (short)n;
    return p;
}

// @fnv 0x00d6a810
// src: COMMUNITY 0x00d6a810
void* __cdecl hkpMidphaseViewer_Create(int a)
{
    hkpMidphaseViewer* o = ::new (hkAlloc(sizeof(hkpMidphaseViewer))) hkpMidphaseViewer(a);
    return o ? (char*)o + 8 : 0;
}
}  // namespace fnv_00d6a810

struct Registry_00dd9380
{
    void* Register(const char* name, void (*fn)());
};

extern Registry_00dd9380* DAT_01269cd0;
extern char DAT_010d22e0[];
extern void* DAT_01269024;
void hkpMidphaseViewer_Create();

// @fnv 0x00d6a850
// src: GUESS 0x00d6a850 (confidence: low)
void hkpMidphaseViewer_Create_SetDAT01269024()
{
    DAT_01269024 = DAT_01269cd0->Register(DAT_010d22e0, hkpMidphaseViewer_Create);
}

struct Target
{
    int Handle(void* apValue);
};

struct FUN_00d6a220_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;

    int HandleWithSelfOffset(Target* apTarget);
};

// @fnv 0x00d6a220
int FUN_00d6a220_cls::HandleWithSelfOffset(Target* apTarget)
{
    return apTarget->Handle(((char*)this - 0x20) != 0 ? (char*)this + 8 : 0);
}

struct S_d6a280_Elem;

struct S_d6a280_Owner
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
    S_d6a280_Elem** m_items;
    int m_uiItemCount;
};

struct S_d6a280_Elem
{
    void hkpWorld_addWorldPostSimulationListener(hkpWorldPostSimulationListener* listener) throw();
};

// Constructs the base with a, then calls FUN_00c93920 on each item of m_24's m_items array, passing this.
// @fnv 0x00d6a280
hkpMidphaseViewer::hkpMidphaseViewer(int a) : hkpWorldViewerBase((const void*)a)
{
    if (m_iValueAtOffset0C != 0)
    {
        for (int i = 0; i < ((S_d6a280_Owner*)m_iValueAtOffset0C)->m_uiItemCount; i++)
            ((S_d6a280_Owner*)m_iValueAtOffset0C)->m_items[i]->hkpWorld_addWorldPostSimulationListener((hkpWorldPostSimulationListener*)this);
    }
}

namespace fnv_00d6a870 {
extern int DAT_01269024;

// @fnv 0x00d6a870
// src: GUESS 0x00d6a870 (confidence: low)
int __cdecl hkpMidphaseViewer_GetDAT01269024()
{
    return DAT_01269024;
}
}  // namespace fnv_00d6a870

namespace fnv_00d6a8b0 {
// FUN_00d6a8b0 - hkpMidphaseViewer: tears the viewer down and, when the
// deleting flag is set, unregisters it from the physics world.
struct hkpWorldViewerRegistry
{
    virtual void v0();
    virtual void v1();
    virtual void removeViewer(void* viewer, unsigned short viewerId);
};

struct hkpPhysicsWorld
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    hkpWorldViewerRegistry* unk10;
};

extern hkpPhysicsWorld* hkMemoryRouter_getInstance();

}  // namespace fnv_00d6a8b0

// Calls FUN_00d6a750, then if flags & 1 removes this viewer from the physics world registry, and returns this.
// @fnv 0x00d6a8b0
void* hkpMidphaseViewer::FUN_00d6a8b0(int flags)
{
    FUN_00d6a750();
    if (flags & 1)
    {
        fnv_00d6a8b0::hkpPhysicsWorld* world = fnv_00d6a8b0::hkMemoryRouter_getInstance();
        world->unk10->removeViewer(this, m_usMemSizeAndFlags);
    }
    return this;
}
