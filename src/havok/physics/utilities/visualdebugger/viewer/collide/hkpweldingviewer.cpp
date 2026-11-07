
// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpweldingviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/collide/hkpweldingviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkMemoryRouter.h"


struct FUN_00dd9380_class
{
    void* hkProcessFactory_registerProcess(const char* name, void* factory);
};
extern int DAT_01269cd0;
extern int DAT_01268fbc;
void* __cdecl FUN_00d62e20();
// @fnv 0x00d62e60
void __cdecl RegisterWeldingViewer()
{
    void* result = ((FUN_00dd9380_class*)DAT_01269cd0)->hkProcessFactory_registerProcess("WeldingViewer", (void*)&FUN_00d62e20);
    DAT_01268fbc = (int)result;
}

struct S_00d62650_B1
{
    virtual void vfn1();
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
};
struct S_00d62650_B3
{
    virtual void vfn3();
};
struct S_00d62650_Arg
{
    void __thiscall hkpWorld_addWorldPostSimulationListener(S_00d62650_B3* p);
};
struct S_00d62650_B2
{
    virtual void DispatchToArg(S_00d62650_Arg* arg);
    int unk04;
};
struct S_00d62650_D : S_00d62650_B1, S_00d62650_B2, S_00d62650_B3
{
    virtual void DispatchToArg(S_00d62650_Arg* arg);
};

// Calls FUN_00c93920 on arg, passing this as the argument.
// @fnv 0x00d62650
void S_00d62650_D::DispatchToArg(S_00d62650_Arg* arg)
{
    arg->hkpWorld_addWorldPostSimulationListener(this);
}

// hkpWeldingViewer - virtual slot 2 of the base subobject at +0x20.
// Removes the entity pointer held by this subobject from the world's list.
//   this  -> the base subobject (complete object + 0x20)
//   -0x20 -> the complete object
//   +0x08 -> the pointer that is handed to the list (complete object + 0x28)

struct HKWorldList
{
    void IsEntityAdded(void* entity);
};

struct HKConstraint
{
    int unk00;
    int unk04;
    void* unk08;
    void ProcessAndTransformResult_00d62680(HKWorldList* list);
};

// Passes a pointer to unk08 to the list's add method, or null when the adjusted this pointer is zero.
// @fnv 0x00d62680
// src: GUESS 0x00d62680 (confidence: low)
void HKConstraint::ProcessAndTransformResult_00d62680(HKWorldList* pWorldList)
{
    pWorldList->IsEntityAdded(((char*)this - 0x20) ? (void*)&unk08 : (void*)0);
}

struct S_00d626b0_Item
{
    void hkpWorld_addWorldPostSimulationListener(void* apSub);
};

struct S_00d626b0_Owner
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
    S_00d626b0_Item** m_6c;
    int m_70;
};

struct S_00d626b0_A
{
    virtual void a0();
    int unk04;
};
struct S_00d626b0_B
{
    virtual void b0();
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};
struct S_00d626b0_C
{
    virtual void c0();
    S_00d626b0_Owner* m_24;
};
struct S_00d626b0_R : S_00d626b0_A, S_00d626b0_B, S_00d626b0_C
{
    S_00d626b0_R(int a) throw();
};
struct S_00d626b0_S
{
    virtual void s0();
    S_00d626b0_S() throw()
    {}
};

struct FUN_00d626b0 : S_00d626b0_R, S_00d626b0_S
{
    FUN_00d626b0(int a) throw();
    virtual void a0();
    virtual void b0();
    virtual void c0();
    virtual void s0();
};

// If the owner pointer m_24 is set, calls FUN_00c93920 on each of its m_70 items, passing this object.
// @fnv 0x00d626b0
FUN_00d626b0::FUN_00d626b0(int aiArg) throw() : S_00d626b0_R(aiArg)
{
    if (m_24)
    {
        for (int i = 0; i < m_24->m_70; i++)
            m_24->m_6c[i]->hkpWorld_addWorldPostSimulationListener((S_00d626b0_S*)this);
    }
}

class D62720Listener
{
  public:
    virtual ~D62720Listener() throw()
    {}
};

class D62720Island
{
  public:
    void removeListener(D62720Listener* listener);
};

struct D62720World
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
    D62720Island** m_islands;
    int m_iIslandCount;
};

class D62720BaseA
{
  public:
    virtual ~D62720BaseA();

    int unk04;
};

class D62720BaseB
{
  public:
    virtual void unk00();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class D62720BaseC
{
  public:
    virtual void unk00();
};

class D62720Base : public D62720BaseA, public D62720BaseB, public D62720BaseC
{
  public:
    virtual ~D62720Base();

    D62720World* m_pOwningWorld;
};

class FUN_00d62720 : public D62720Base, public D62720Listener
{
  public:
    virtual ~FUN_00d62720() throw();
};

// Destructor that unregisters this listener from every island in the world, if a world is set.
// @fnv 0x00d62720
FUN_00d62720::~FUN_00d62720() throw()
{
    if (m_pOwningWorld)
    {
        for (int i = 0; i < m_pOwningWorld->m_iIslandCount; i++)
            m_pOwningWorld->m_islands[i]->removeListener(this);
    }
}

// The factory that creates one hkpWeldingViewer-like record for the physics
// world: it asks the world manager's pool for a 0x2c byte block, stamps the
// block size into the record header and then runs the record's constructor.
struct Viewer;

struct Pool
{
    virtual void dummy0();
    virtual Viewer* alloc0x2c(int n);
};

struct Manager
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Pool* unk10;
};

struct Viewer
{
    int unk00;
    unsigned short unk04;
    void* ctor0d626b0(void* arg);
};

extern "C" void* __cdecl hkMemoryRouter_getInstance();

// Allocates a 0x2c-byte Viewer from the manager's pool, sets its size field, constructs it with arg, and returns a pointer offset by 8 or null.
// @fnv 0x00d62e20
// src: GUESS 0x00d62e20 (confidence: low)
void* __cdecl Object_ProcessAndReturnValue_00d62e20(void* arg)
{
    Manager* pManager = (Manager*)hkMemoryRouter_getInstance();
    Viewer* pViewer = pManager->unk10->alloc0x2c(0x2c);
    pViewer->unk04 = 0x2c;
    void* pResult = pViewer->ctor0d626b0(arg);
    if (pResult)
        return (char*)pResult + 8;
    return 0;
}

extern int g_D62E80Value;

// @fnv 0x00d62e80
// src: GUESS 0x00d62e80 (confidence: low)
int __cdecl Object_GetG_D62E80Value_00d62e80()
{
    return g_D62E80Value;
}

namespace fnv_00d62ec0 {
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

struct FUN_00d62ec0_cls
{
    int unk00;
    unsigned short m_uSize;
    unsigned short m_u06;

    void FUN_00d62720();

    FUN_00d62ec0_cls* Destroy(unsigned char acFlags);
    static void operator delete(void* apMemory) throw();
};

// Calls FUN_00d62720, then if acFlags bit 0 is set frees this via the audio allocator with m_uSize and returns this.
// @fnv 0x00d62ec0
FUN_00d62ec0_cls* FUN_00d62ec0_cls::Destroy(unsigned char acFlags)
{
    FUN_00d62720();
    if (acFlags & 1)
    {
        hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
        pAllocator->blockFree(this, m_uSize);
    }
    return this;
}
}  // namespace fnv_00d62ec0

// FUN_00d62e90 : MSVC this-adjusting thunk  (sub ecx, 0x20 ; jmp <impl>)
struct A1_00d62e90
{
    A1_00d62e90();
    virtual void FUN_00d62e90();
    char pad[0x1c];
};
struct A2_00d62e90
{
    A2_00d62e90();
    virtual void FUN_00d62e90();
};
struct Own_00d62e90 : A1_00d62e90, A2_00d62e90
{
    Own_00d62e90();
    virtual void key_fn();
// @fnv 0x00d62e90
    void FUN_00d62e90();
};
Own_00d62e90::Own_00d62e90()
{}
void Own_00d62e90::key_fn()
{}
Own_00d62e90* make_00d62e90()
{
    static Own_00d62e90 o;
    return &o;
}

struct D62EA0Primary
{
    virtual void vfunc00();
    virtual void AdjustThisAndForward_00d62ea0();

    int unk04;
};

struct D62EA0Secondary
{
    virtual void AdjustThisAndForward_00d62ea0();
};

struct D62EA0Object : D62EA0Primary, D62EA0Secondary
{
    D62EA0Object();

// @fnv 0x00d62ea0
// src: GUESS 0x00d62ea0 (confidence: low)
    virtual void AdjustThisAndForward_00d62ea0();
};

D62EA0Object::D62EA0Object()
{}

// FUN_00d62eb0 : MSVC this-adjusting thunk  (sub ecx, 0x28 ; jmp <impl>)
struct A1_00d62eb0
{
    A1_00d62eb0();
    virtual void FUN_00d62eb0();
    char pad[0x24];
};
struct A2_00d62eb0
{
    A2_00d62eb0();
    virtual void FUN_00d62eb0();
};
struct Own_00d62eb0 : A1_00d62eb0, A2_00d62eb0
{
    Own_00d62eb0();
    virtual void key_fn();
// @fnv 0x00d62eb0
    void FUN_00d62eb0();
};
Own_00d62eb0::Own_00d62eb0()
{}
void Own_00d62eb0::key_fn()
{}
Own_00d62eb0* make_00d62eb0()
{
    static Own_00d62eb0 o;
    return &o;
}
