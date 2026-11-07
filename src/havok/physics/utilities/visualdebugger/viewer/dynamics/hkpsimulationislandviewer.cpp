
// src/havok/physics/utilities/visualdebugger/viewer/dynamics/hkpsimulationislandviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/hkpsimulationislandviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkArray.h"

struct Base0
{
    char pad[0x20];
};
struct Base2;
struct Target
{
    void hkpWorld_addWorldPostSimulationListener(Base2* p);
};
struct Base1
{
    int a, b;
    void PassSelfAsBase2ToTarget(Target* t);
};
struct Base2
{
    int c;
};
struct Derived : Base0, Base1, Base2
{
};

// Computes the Derived pointer from this and passes the Base2 subobject (or null) to t->FUN_00c93920.
// @fnv 0x00d649f0
void Base1::PassSelfAsBase2ToTarget(Target* apTarget)
{
    Derived* d = (Derived*)((char*)this - 0x20);
    apTarget->hkpWorld_addWorldPostSimulationListener(d ? (Base2*)((char*)this + 8) : 0);
}

struct S_00d65180_Allocator
{
    virtual void v0();
    virtual void* AllocateMemoryBlock(int nbytes);
};

struct S_00d65180_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00d65180_Allocator* m_pStreamAllocator;
    S_00d65180_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

S_00d65180_Router* hkMemoryRouter_getInstance();

struct S_00d65180_RefObj
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    virtual ~S_00d65180_RefObj() throw()
    {}
    void* operator new(unsigned int nbytes)
    {
        S_00d65180_RefObj* b = static_cast<S_00d65180_RefObj*>(hkMemoryRouter_getInstance()->heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    void operator delete(void*)
    {}
};

struct S_00d65180_Base2
{
    virtual void v0();
};

struct S_00d65180_Obj : S_00d65180_RefObj, S_00d65180_Base2
{
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
    S_00d65180_Obj(void* arg) throw();
};

// Allocates and constructs an S_00d65180_Obj from arg, returning it as an S_00d65180_Base2 pointer.
// @fnv 0x00d65180
// src: XBOX_PDB 0x00d65180
S_00d65180_Base2* hkpSimulationIslandViewer_create(void* arg)
{
    return new S_00d65180_Obj(arg);
}

extern int g_D651E0Value;

// @fnv 0x00d651e0
// src: GUESS 0x00d651e0 (confidence: low)
int __cdecl Object_GetG_D651E0Value_00d651e0()
{
    return g_D651E0Value;
}

namespace fnv_00d65220 {
struct FUN_00d65220_Interface
{
    virtual void unk00();
    virtual void unk04();
    virtual void notify(void*, unsigned short);
};
struct FUN_00d65220_Service
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00d65220_Interface* unk10;
};
FUN_00d65220_Service* __cdecl hkMemoryRouter_getInstance();
struct FUN_00d65220_Class
{
    void* vtable;
    unsigned short unk04;
    void FUN_00d64ae0();
    FUN_00d65220_Class* FUN_00d65220(char flags);
};
// Calls FUN_00d64ae0, then if bit 0 of flags is set, notifies the service interface with this and unk04, and returns this.
// @fnv 0x00d65220
FUN_00d65220_Class* FUN_00d65220_Class::FUN_00d65220(char flags)
{
    FUN_00d64ae0();
    if (flags & 1)
    {
        FUN_00d65220_Service* service = hkMemoryRouter_getInstance();
        service->unk10->notify(this, unk04);
    }
    return this;
}
}  // namespace fnv_00d65220

struct S_Elem2
{
    void ClearValue(void* d) throw();
};
struct S_P
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
    S_Elem2** m6c;
    int m70;
};
struct S_Heap
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void ReturnMemory(void* p, int n) throw();
};
struct S_Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_Heap* m10;
};
struct S_B0
{
    virtual void b0v0();
    int unk04;
};
struct S_B8
{
    virtual void b8v0();
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};
struct S_B20
{
    virtual void b20v0();
};
struct FUN_00ddcc60 : S_B0, S_B8, S_B20
{
    S_P* m24;
    virtual ~FUN_00ddcc60() throw();
};
struct S_D
{
    virtual ~S_D() throw()
    {}
    int unk04;
};
struct S_Elem
{
    virtual ~S_Elem() throw();
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
};
struct S_Arr
{
    S_Elem* m_data;
    int m_iElementCount;
    int m_cap;
    __forceinline void clear() throw()
    {
        S_Heap* heap = ((S_Holder*)hkMemoryRouter_getInstance())->m10;
        int n = m_iElementCount;
        S_Elem* d = m_data;
        for (int i = 0; i < n; i++)
            d[i].~S_Elem();
        m_iElementCount = 0;
        if ((m_cap & 0x80000000) == 0)
            heap->ReturnMemory(m_data, (m_cap & 0x3fffffff) * (int)sizeof(S_Elem));
        m_data = 0;
        m_cap = 0x80000000;
    }
};
struct FUN_00d64ae0 : FUN_00ddcc60, S_D
{
    S_Arr m30;
    S_Arr m3c;
    virtual ~FUN_00d64ae0() throw();
};
// Notifies each element in m24 via ClearValue, then clears the m3c and m30 arrays.
// @fnv 0x00d64ae0
FUN_00d64ae0::~FUN_00d64ae0() throw()
{
    if (m24)
    {
        for (int i = 0; i < m24->m70; i++)
            m24->m6c[i]->ClearValue((S_D*)this);
    }
    m3c.clear();
    m30.clear();
}

class RegistryOwner
{
  public:
    void* Register(const char* name, void (*callback)());
};

extern RegistryOwner* DAT_01269cd0;
extern void* DAT_01268fdc;
extern const char str_010d19d0[];

extern void RegisterCallback();

// @fnv 0x00d651c0
// src: XBOX_PDB 0x00d651c0
void hkpSimulationIslandViewer_registerViewer()
{
    DAT_01268fdc = DAT_01269cd0->Register(str_010d19d0, RegisterCallback);
}

class hkListenerD64A
{
  public:
    virtual ~hkListenerD64A() throw();
};
class hkEntityD64A
{
  public:
    void hkpWorld_addWorldPostSimulationListener(hkListenerD64A* pkListener) throw();
};
class hkWorldD64A
{
  public:
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68;
    hkEntityD64A** m_kActorEntries;
    int m_iActorEntryCount;
};
class hkBaseAD64A
{
  public:
    virtual ~hkBaseAD64A() throw();
    int unk04;
};
class hkBaseBD64A
{
  public:
    virtual ~hkBaseBD64A() throw();
    int unk0C, unk10, unk14, unk18, unk1C;
};
class hkBaseCD64A
{
  public:
    virtual ~hkBaseCD64A() throw();
};
class FUN_00ddccb0 : public hkBaseAD64A, public hkBaseBD64A, public hkBaseCD64A
{
  public:
    FUN_00ddccb0(void* pkInfo) throw();
    virtual ~FUN_00ddccb0() throw();
    hkWorldD64A* m_pOwningWorld;
};
struct FlagD64A
{
    bool value;
    FlagD64A() : value(true)
    {}
};
class FUN_00d64a50 : public FUN_00ddccb0, public hkListenerD64A
{
  public:
    FlagD64A m_flagA;
    FlagD64A m_flagB;
    hkArray<void*> m_arrayA;
    hkArray<void*> m_arrayB;
    FUN_00d64a50(void* pkInfo) throw();
    virtual ~FUN_00d64a50() throw();
};
// After the base constructor, calls FUN_00c93920 with this on each actor entry of the owning world, if the world is set.
// @fnv 0x00d64a50
FUN_00d64a50::FUN_00d64a50(void* pkInfo) throw() : FUN_00ddccb0(pkInfo)
{
    if (m_pOwningWorld)
    {
        for (int i = 0; i < m_pOwningWorld->m_iActorEntryCount; i++)
            m_pOwningWorld->m_kActorEntries[i]->hkpWorld_addWorldPostSimulationListener(this);
    }
}

struct Prim
{
    virtual void FUN_00d651f0();
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
    virtual void FUN_00d651f0();
};

struct ThunkOwner : Prim, B1
{
// @fnv 0x00d651f0
    virtual void FUN_00d651f0();
};

static ThunkOwner g_thunk;

// sub ecx,8; jmp target == MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (8).
struct PrimaryBase
{
    virtual void AdjustThisAndForward_00d65200();
    int unk04;
};

struct SecondaryBase
{
    virtual void AdjustThisAndForward_00d65200();
};

struct AdjustedDerived : PrimaryBase, SecondaryBase
{
    AdjustedDerived();
// @fnv 0x00d65200
// src: GUESS 0x00d65200 (confidence: low)
    virtual void AdjustThisAndForward_00d65200();
};

AdjustedDerived::AdjustedDerived()
{}

// FUN_00d65210 : MSVC this-adjusting thunk  (sub ecx, 0x28 ; jmp <impl>)
struct A1_00d65210
{
    A1_00d65210();
    virtual void FUN_00d65210();
    char pad[0x24];
};
struct A2_00d65210
{
    A2_00d65210();
    virtual void FUN_00d65210();
};
struct Own_00d65210 : A1_00d65210, A2_00d65210
{
    Own_00d65210();
    virtual void key_fn();
// @fnv 0x00d65210
    void FUN_00d65210();
};
Own_00d65210::Own_00d65210()
{}
void Own_00d65210::key_fn()
{}
Own_00d65210* make_00d65210()
{
    static Own_00d65210 o;
    return &o;
}

struct IslandRemovalCallback
{
    virtual void ClearValue_Thunk(S_Elem2* world);
};

struct IslandRemovalParent : hkBaseAD64A, hkBaseBD64A, IslandRemovalCallback
{
    hkWorldD64A* m_pOwningWorld;
};

struct IslandWorldRemoval : IslandRemovalParent, hkListenerD64A
{
    virtual void ClearValue_Thunk(S_Elem2* world);
};

// Calls ClearValue on world with this object's listener base.
// @fnv 0x00d64a20
// src: GUESS 0x00d64a20 (confidence: medium)
void IslandWorldRemoval::ClearValue_Thunk(S_Elem2* world)
{
    world->ClearValue(static_cast<hkListenerD64A*>(this));
}
