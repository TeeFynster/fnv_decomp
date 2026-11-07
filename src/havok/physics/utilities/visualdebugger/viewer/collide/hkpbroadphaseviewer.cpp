
// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpbroadphaseviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/collide/hkpbroadphaseviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkMemoryRouter.h"

struct Container
{
    int ClearValue(void* value);
};
struct Owner
{
    int ClearAdjustedValue(Container* container);
};
// Passes a pointer to this+8 (or null when this equals 0x20) to container->ClearValue and returns its result.
// @fnv 0x00d6a910
// src: GUESS 0x00d6a910 (confidence: medium)
int Owner::ClearAdjustedValue(Container* container)
{
    void* value;
    if ((char*)this - 0x20)
        value = (char*)this + 8;
    else
        value = 0;
    return container->ClearValue(value);
}

struct FUN_00dd9380_StandIn
{
    int hkProcessFactory_registerProcess(const char* name, void* constructor);
};
extern FUN_00dd9380_StandIn* DAT_01269cd0;
extern int DAT_01269028;
extern char DAT_010c65b0;
void hkpBroadphaseViewer_Create();
// @fnv 0x00d6ad40
// src: GUESS 0x00d6ad40 (confidence: low)
void __cdecl Object_UpdateFields_00d6ad40()
{
    DAT_01269028 = DAT_01269cd0->hkProcessFactory_registerProcess(&DAT_010c65b0, (void*)&hkpBroadphaseViewer_Create);
}

extern int DAT_01269028;
// @fnv 0x00d6ad60
// src: GUESS 0x00d6ad60 (confidence: low)
int Object_GetDAT_01269028_00d6ad60()
{
    return DAT_01269028;
}

struct Target
{
    void hkpWorld_addWorldPostSimulationListener(void* apArg);
};

struct FUN_00d6a8e0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;

    void CallTargetWithSelfOffset(Target* apTarget);
};

// Passes a pointer derived from this (this+8, or null when this-0x20 is null) to apTarget's FUN_00c93920.
// @fnv 0x00d6a8e0
void FUN_00d6a8e0_cls::CallTargetWithSelfOffset(Target* apTarget)
{
    apTarget->hkpWorld_addWorldPostSimulationListener(((char*)this - 0x20) != 0 ? (char*)this + 8 : 0);
}

// ---------------------------------------------------------------------------
// FUN_00d6a940  (0x00d6a940, 112 bytes) - the constructor of the game's
// hkpBroadphaseViewer.
//
//   8b442404          mov eax,[esp+4]        ; the ctor argument
//   53 56 57         push ebx / esi / edi
//   50                push eax
//   8bf1              mov esi,ecx             ; this -> esi
//   e861230700        call 0xddccb0           ; hkpWorldViewerBase::hkpWorldViewerBase(arg)
//   c746287ccf0c01   mov [esi+0x28],<hkpWorldPostSimulationListener vftable>
//   8d5e28            lea ebx,[esi+0x28]
//   33ff              xor edi,edi
//   c706b4230d01     mov [esi],<hkpBroadphaseViewer vftable>
//   c7460894230d01   mov [esi+8],<hkpBroadphaseViewer vftable>
//   c7462084230d01   mov [esi+0x20],<hkpBroadphaseViewer vftable>
//   c70374230d01     mov [ebx],<hkpBroadphaseViewer vftable>
//   897e2c 897e30     mov [esi+0x2c],edi / mov [esi+0x30],edi
//   c7463400000080   mov [esi+0x34],0x80000000
//   8b4624            mov eax,[esi+0x24]     ; the shape list of the world
//   3bc7 741f         cmp eax,edi / je end
//   397870 7e1a       cmp [eax+0x70],edi / jle end
//   ...loop: for each shape, shape->FUN_00c93920(this+0x28)
//   5f 8bc6 5e 5b     pop edi / mov eax,esi / pop esi / pop ebx
//   c20400            ret 4
//
// The class therefore has four vptr-bearing base subobjects, at complete
// object offsets 0x00, 0x08, 0x20 and 0x28.  Modelling that hierarchy for
// real makes MSVC emit the vftable-initialisation itself, which is the only
// way to get the two vtable stores at 0x28 (the base's own vtable first, the
// derived's per-base vtable second, the second one through the address
// taken in ebx) and the exact order of the initialisations.
// ---------------------------------------------------------------------------

// the object the world keeps at this+0x24: an array of shapes and a count
struct BroadCtx
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
    void** arr;  // +0x6c
    int count;   // +0x70
};

// the secondary base at 0x28 - the listener the shapes are told about
struct PostSimListener
{
    virtual void ps0();
    virtual void ps1();
    virtual void ps2();
    virtual void ps3();
};

// one shape of the world; 0xc93920 appends a listener to its list at +0x164
struct BroadElem
{
    void hkpWorld_addWorldPostSimulationListener(PostSimListener* p);
};

// the primary base at 0x00 (its vptr is the one at 0x00)
struct PrimBase
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    int unk04;
};

// the secondary base at 0x08, 0x18 bytes long
struct ProcBase
{
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual void w5();
    virtual void w6();
    virtual void w7();
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};

// the secondary base at 0x20
struct CtxListenerBase
{
    virtual void x0();
    virtual void x1();
    virtual void x2();
    virtual void x3();
};

// 0xddccb0 - hkpWorldViewerBase's constructor; it fills the three vptrs it
// owns and the shape list at 0x24
struct WorldViewerBase : PrimBase, ProcBase, CtxListenerBase
{
    BroadCtx* m_ctx;  // +0x24
    WorldViewerBase(void* a);
};

// hkpBroadphaseViewer itself (the class is named after the function so that
// its constructor's decorated name carries the tag the checker looks for)
struct FUN_00d6a940 : WorldViewerBase, PostSimListener
{
    int unk2c;  // +0x2c
    int unk30;  // +0x30
    int unk34;  // +0x34
    FUN_00d6a940(void* a);

  private:
    ~FUN_00d6a940();  // never defined: keeps a second tagged
                      // symbol out of the object file
};

// @fnv 0x00d6a940
FUN_00d6a940::FUN_00d6a940(void* a) : WorldViewerBase(a)
{
    // The three flags are written through a pointer: that gives the stores an
    // unknown member displacement, so MSVC may not hoist the load of the
    // shape list (this+0x24) above them - the original keeps that load below
    // the three stores, this source does the same.
    int* q = (int*)((char*)this + 0x2c);
    q[0] = 0;
    q[1] = 0;
    q[2] = (int)0x80000000;
    if (m_ctx)
    {
        for (int i = 0; i < m_ctx->count; i++)
        {
            BroadElem* e = (BroadElem*)m_ctx->arr[i];
            e->hkpWorld_addWorldPostSimulationListener(this);  // this+0x28: the listener subobject
        }
    }
}

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();

struct SpawnedItem
{
    virtual void v00(int aiFlags);
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
    Container** m_ppItems;
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

struct FUN_00d6ac40_cls : PrimaryBase, MidBase, TailBase, SubObject
{
    SpawnedItem* m_pData;
    int m_iField30;
    unsigned int m_uiObjectFlags;

    ~FUN_00d6ac40_cls() throw();
};

// @fnv 0x00d6ac40
FUN_00d6ac40_cls::~FUN_00d6ac40_cls() throw()
{
    if (m_pSharedOwner != 0)
    {
        for (int i = 0; i < m_pSharedOwner->m_iArrayLength; ++i)
        {
            m_pSharedOwner->m_ppItems[i]->ClearValue(static_cast<SubObject*>(this));
        }
    }
    hkMemoryRouter* pAudioHolder = hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pAudioHolder->m_heap);
    SpawnedItem* p = m_pData;
    if (m_iField30 > 0)
    {
        int iRemaining = m_iField30;
        do
        {
            p->v00(0);
            ++p;
            --iRemaining;
        } while (iRemaining != 0);
    }
    m_iField30 = 0;
    unsigned int uiAllocFlags = m_uiObjectFlags;
    if ((uiAllocFlags & 0x80000000u) == 0)
    {
        // FreeData occupies vtable slot 4 in the game.
        (*reinterpret_cast<void (__thiscall**)(hkMemoryAllocator*, void*, unsigned int)>(
            *reinterpret_cast<char**>(pAllocator) + 0x10))(
                pAllocator, m_pData, (uiAllocFlags & 0x3fffffffu) * 0x80);
    }
    m_pData = 0;
    m_uiObjectFlags = 0x80000000u;
}

namespace fnv_00d6ad00 {
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();

struct SpawnedObject
{
    int unk00;
    unsigned short m_wSize;
    unsigned short unk06;
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
    int __thiscall Init(int arg);
};

// Allocates a 0x38-byte object from the holder's allocator, sets its size, calls Init(arg), and returns the result plus 8 or 0.
// @fnv 0x00d6ad00
// src: COMMUNITY 0x00d6ad00
int hkpBroadphaseViewer_Create(int arg)
{
    hkMemoryRouter* pAllocHolder = hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pAllocHolder->m_heap);
    SpawnedObject* pObject = (SpawnedObject*)(*reinterpret_cast<void* (__thiscall**)(hkMemoryAllocator*, int)>(
        *reinterpret_cast<char**>(pAllocator) + 4))(pAllocator, 0x38);
    pObject->m_wSize = 0x38;
    int iInitResult = pObject->Init(arg);
    return iInitResult != 0 ? iInitResult + 8 : 0;
}
}  // namespace fnv_00d6ad00

namespace fnv_00d6ad70 {
// MSVC adjustor thunk: the primary base occupies 0x20 bytes; both bases declare the virtual,
// the derived class defines only its constructor, so the compiler emits the this-adjusting thunk.
struct PrimaryBase
{
    virtual void FUN_00d6ad70();
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
    virtual void FUN_00d6ad70();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d6ad70
    virtual void FUN_00d6ad70();
};

Derived::Derived()
{}
}  // namespace fnv_00d6ad70

struct D6AD80Primary
{
    virtual void vfunc00();
    virtual void AdjustThisAndForward_00d6ad80();

    int unk04;
};

struct D6AD80Secondary
{
    virtual void AdjustThisAndForward_00d6ad80();
};

struct D6AD80Object : D6AD80Primary, D6AD80Secondary
{
    D6AD80Object();

// @fnv 0x00d6ad80
// src: GUESS 0x00d6ad80 (confidence: low)
    virtual void AdjustThisAndForward_00d6ad80();
};

D6AD80Object::D6AD80Object()
{}

struct D6AD90Primary
{
    virtual void vfunc00();
    virtual void FUN_00d6ad90();

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

struct D6AD90Secondary
{
    virtual void FUN_00d6ad90();
};

struct D6AD90Object : D6AD90Primary, D6AD90Secondary
{
    D6AD90Object();

// @fnv 0x00d6ad90
    virtual void FUN_00d6ad90();
};

D6AD90Object::D6AD90Object()
{}

namespace fnv_00d6ada0 {
hkMemoryRouter* hkMemoryRouter_getInstance();

inline hkMemoryAllocator& Heap(hkMemoryRouter* holder)
{
    return *reinterpret_cast<hkMemoryAllocator*>(holder->m_heap);
}

inline void ReleaseBlock(hkMemoryAllocator& allocator, void* p, int numBytes)
{
    (*reinterpret_cast<void (__thiscall**)(hkMemoryAllocator*, void*, int)>(
        *reinterpret_cast<char**>(&allocator) + 8))(&allocator, p, numBytes);
}

struct S_00d6ada0_ReferencedObject
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void operator delete(void* p, unsigned int)
    {
        S_00d6ada0_ReferencedObject* b = static_cast<S_00d6ada0_ReferencedObject*>(p);
        ReleaseBlock(Heap(hkMemoryRouter_getInstance()), p, b->m_usMemSizeAndFlags);
    }
    virtual ~S_00d6ada0_ReferencedObject()
    {}
};

struct FUN_00d6ada0 : S_00d6ada0_ReferencedObject
{
    FUN_00d6ada0();
    virtual ~FUN_00d6ada0();
};

// @fnv 0x00d6ada0
FUN_00d6ada0::FUN_00d6ada0()
{}
}  // namespace fnv_00d6ada0
