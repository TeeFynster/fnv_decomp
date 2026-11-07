#include "../../../../../../../include/hkArray.h"

// src/havok/physics/utilities/visualdebugger/viewer/dynamics/hkprigidbodycentreofmassviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/hkprigidbodycentreofmassviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Entries
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
    void** items;
    int count;
};
struct Owner
{
    void ProcessEntries_00d69c10(void* item);
};
struct View
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    Entries* entries;
    void ProcessEntries_00d69f60();
};
// Iterates entries and calls FUN_00d69c10 on each item via the owner at this-8.
// @fnv 0x00d69f60
// src: GUESS 0x00d69f60 (confidence: low)
void View::ProcessEntries_00d69f60()
{
    if (entries)
    {
        for (int i = 0; i < entries->count; ++i)
            reinterpret_cast<Owner*>(reinterpret_cast<char*>(this) - 8)->ProcessEntries_00d69c10(entries->items[i]);
    }
}

struct Target
{
    void ProcessEntries_00d69c10();
};
struct FUN_00d69fb0_cls
{
    void CallTargetMethod();
};
// Calls FUN_00d69c10 on the Target object located 0x20 bytes before this.
// @fnv 0x00d69fb0
void FUN_00d69fb0_cls::CallTargetMethod()
{
    ((Target*)((char*)this - 0x20))->ProcessEntries_00d69c10();
}



struct S_00d69fc0_Item;

struct S_00d69fc0
{
    int unk00;
    int unk04;
    hkArrayBase<S_00d69fc0_Item*> m_items;
    void RemoveItem(S_00d69fc0_Item* item);
};

// Finds item in m_items and, if present, removes it by index.
// @fnv 0x00d69fc0
void S_00d69fc0::RemoveItem(S_00d69fc0_Item* item)
{
    int index = m_items.indexOf(item);
    if (index >= 0)
        m_items.removeAt(index);
}

struct D6A140Allocator
{
    virtual void unk00();
    virtual void* AllocateMemoryBlock(int numBytes);
};

struct D6A140MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D6A140Allocator* m_pStreamAllocator;

    D6A140Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" D6A140MemoryRouter& __cdecl hkMemoryRouter_getInstance();

class D6A140ReferencedObject
{
  public:
    static void* operator new(unsigned int nbytes)
    {
        D6A140ReferencedObject* b =
            static_cast<D6A140ReferencedObject*>(hkMemoryRouter_getInstance().heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    static void operator delete(void* p);

    virtual ~D6A140ReferencedObject();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class D6A140Interface
{
  public:
    virtual ~D6A140Interface();
};

class D6A140Object : public D6A140ReferencedObject, public D6A140Interface
{
  public:
    __declspec(nothrow) D6A140Object(const void* info);

    int unk0C[12];
};

// Allocates a D6A140Object with the given info and returns it as a D6A140Interface pointer.
// @fnv 0x00d6a140
// src: COMMUNITY 0x00d6a140
D6A140Interface* __cdecl hkpRigidBodyCentreOfMassViewer_Create(const void* info)
{
    return new D6A140Object(info);
}

extern void* DAT_01269020;
// @fnv 0x00d6a1a0
// src: GUESS 0x00d6a1a0 (confidence: low)
void* __cdecl Object_GetDAT_01269020_00d6a1a0()
{
    return DAT_01269020;
}

namespace fnv_00d6a1f0 {
struct Allocator
{
    virtual void A();
    virtual void B();
    virtual void Free(void*, unsigned short);
};
struct Manager
{
    int unk00, unk04, unk08, unk0C;
    Allocator* unk10;
};
extern Manager* __cdecl hkMemoryRouter_getInstance();
struct Owner
{
    __declspec(noinline) virtual ~Owner();
    unsigned short unk04;
    unsigned short unk06;
    void* DestroyOwner(unsigned int flags);
};
Owner::~Owner()
{}
// Runs the Owner destructor, and if flags has bit 0 set, frees this object through the allocator obtained from FUN_00c85750 using unk04 as size; returns this.
// @fnv 0x00d6a1f0
void* Owner::DestroyOwner(unsigned int flags)
{
    this->Owner::~Owner();
    if (flags & 1)
    {
        Manager* manager = hkMemoryRouter_getInstance();
        Allocator* allocator = manager->unk10;
        unsigned short size = unk04;
        allocator->Free(this, size);
    }
    return this;
}
Owner force_vtable;
}  // namespace fnv_00d6a1f0

// AttachAndDispatch: thiscall, one stack parameter (ArgOwner*).

struct SubList
{
    void** data;
    int count;
};

struct Fn_SlotObj
{
    virtual void v00();
    virtual void v04();
    virtual void v08(void* p);
};

struct PtrItem
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
    SubList list;
};

struct ArgOwner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    PtrItem* m_20;
    int unk24;
    PtrItem** m_28;
    int m_2c;
    int unk30;
    PtrItem** m_34;
    int m_38;

    void Attach(void* p);
    void Detach(void* p);
};

struct FUN_00d69b20_cls
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
    Fn_SlotObj m_28;
    int m_2c;

    void AttachAndDispatch(ArgOwner* a1);
};

// Attaches and detaches this object's slots on a1, then dispatches every element of a1's three lists through m_28.v08.
// @fnv 0x00d69b20
void FUN_00d69b20_cls::AttachAndDispatch(ArgOwner* apOwner)
{
    apOwner->Attach(this != 0 ? (void*)&m_28 : 0);
    apOwner->Detach(this != 0 ? (void*)&m_2c : 0);

    for (int i = 0; i < apOwner->m_2c; ++i)
    {
        SubList* list = &apOwner->m_28[i]->list;
        for (int j = 0; j < list->count; ++j)
        {
            m_28.v08(list->data[j]);
        }
    }

    for (int i = 0; i < apOwner->m_38; ++i)
    {
        SubList* list = &apOwner->m_34[i]->list;
        for (int j = 0; j < list->count; ++j)
        {
            m_28.v08(list->data[j]);
        }
    }

    PtrItem* b = apOwner->m_20;
    if (b != 0)
    {
        for (int k = 0; k < b->list.count; ++k)
        {
            m_28.v08(b->list.data[k]);
        }
    }
}

namespace fnv_00d69fa0 {
class SpawnedObject;

class FUN_00d69b20_cls
{
  public:
    void FUN_00d69b20_target();
};

class FUN_00d69fa0_cls
{
  public:
    void ForwardCall_00d69fa0();
};

// @fnv 0x00d69fa0
// src: GUESS 0x00d69fa0 (confidence: low)
void FUN_00d69fa0_cls::ForwardCall_00d69fa0()
{
    ((FUN_00d69b20_cls*)((char*)this - 0x20))->FUN_00d69b20_target();
}
}  // namespace fnv_00d69fa0

extern const char str_0102f13c[];
extern const char DAT_010ccf7c[];
extern const char DAT_010d22a8[];
extern const char DAT_010d2288[];
extern const char DAT_010d2278[];
extern const char DAT_010d225c[];
extern const char DAT_010d224c[];
struct FUN_00ddccb0
{
    void* unk00;
    FUN_00ddccb0(void* input);
};
struct FUN_00d6a040 : FUN_00ddccb0
{
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* unk24;
    void* volatile unk28;
    void* volatile unk2c;
    volatile unsigned int unk30;
    volatile unsigned int unk34;
    volatile unsigned int unk38;
    FUN_00d6a040(void* input);
};
// @fnv 0x00d6a040
FUN_00d6a040::FUN_00d6a040(void* input) : FUN_00ddccb0(input)
{
    unk28 = (void*)str_0102f13c;
    unk2c = (void*)DAT_010ccf7c;
    unk00 = (void*)DAT_010d22a8;
    unk08 = (void*)DAT_010d2288;
    unk20 = (void*)DAT_010d2278;
    unk28 = (void*)DAT_010d225c;
    unk2c = (void*)DAT_010d224c;
    unk30 = 0;
    unk34 = 0;
    unk38 = 0x80000000u;
}

class RegistryOwner
{
  public:
    void* Register(const char* name, void (*callback)());
};

extern RegistryOwner* DAT_01269cd0;
extern void* DAT_01269020;

extern void hkpRigidBodyCentreOfMassViewer_Create();

// @fnv 0x00d6a180
void RegisterCenterOfMass()
{
    DAT_01269020 = DAT_01269cd0->Register("Center of Mass", hkpRigidBodyCentreOfMassViewer_Create);
}

struct DwordList
{
    unsigned int* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapFlags;
};

struct GlobalHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_pAllocator;
};

namespace fnvc_adapt {
GlobalHolder* __cdecl hkMemoryRouter_getInstance();
}
extern "C" void _ReadWriteBarrier(void);
void __cdecl ResizeAudioStream(void* aAlloc, void* aList, unsigned int aiElemSize);

struct FUN_00d6a000_cls
{
    int unk00;
    int unk04;
    DwordList m_kNode;

    void AppendDword(unsigned int aValue);
};

// Appends aValue to the DwordList, growing it via ResizeAudioStream when full, then increments the element count.
// @fnv 0x00d6a000
void FUN_00d6a000_cls::AppendDword(unsigned int aValue)
{
    DwordList* list = &m_kNode;
    GlobalHolder* pAllocHolder = fnvc_adapt::hkMemoryRouter_getInstance();
    if (list->m_iArrayLength == (int)(list->m_uCapFlags & 0x3fffffffu))
    {
        ResizeAudioStream(pAllocHolder->m_pAllocator, list, 4);
    }

    unsigned int count = (unsigned int)list->m_iArrayLength;
    unsigned int data = (unsigned int)list->m_pData;
    unsigned int pSlot = data + count * 4u;
    *(unsigned int*)pSlot = *(volatile unsigned int*)&aValue;
    list->m_iArrayLength++;
}

namespace fnv_00d6a0a0 {
struct Allocator
{
    virtual void Vfn00();
    virtual void Vfn04();
    virtual void Vfn08();
    virtual void Vfn0C();
    virtual void Free(void* data, unsigned int size) throw();
};

struct Manager
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Allocator* unk10;
};

namespace fnvc_adapt {
void* hkMemoryRouter_getInstance() throw();
}

struct Array
{
    void** data;
    int count;
    unsigned int capacity;
    ~Array() throw()
    {
        Manager* mgr = (Manager*)fnvc_adapt::hkMemoryRouter_getInstance();
        Allocator* alloc = mgr->unk10;
        count = 0;
        if (!(capacity & 0x80000000))
            alloc->Free(data, (capacity & 0x3fffffff) * 4);
        data = 0;
        capacity = 0x80000000;
    }
};

struct Base00
{
    virtual ~Base00() throw();
    int unk04;
};

struct Base08
{
    virtual void Vfn08();
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

struct Source
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
    void** unk6C;
    int unk70;
};

struct Base20
{
    virtual void Vfn20();
    Source* unk24;
};

struct Base28
{
    virtual ~Base28() throw()
    {}
};

struct Base2C
{
    virtual ~Base2C() throw()
    {}
};

struct FUN_00d6a0a0 : Base00, Base08, Base20, Base28, Base2C
{
    Array unk30;
    virtual ~FUN_00d6a0a0();
    void AttachAndDispatch(void* item) throw();
};

// Destructor: iterates the Source's unk70 entries and calls AttachAndDispatch on each pointer in unk6C when unk24 is set.
// @fnv 0x00d6a0a0
FUN_00d6a0a0::~FUN_00d6a0a0()
{
    if (unk24)
    {
        for (int i = 0; i < unk24->unk70; i++)
            AttachAndDispatch(unk24->unk6C[i]);
    }
}
}  // namespace fnv_00d6a0a0

// Exe 0x00d69d00 FUN_00d69d00: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    struct
    {
        float x, y, z, w;
    } lanes;
} __m128, LocalM128;

extern "C" LocalM128 _mm_add_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_load_ps(const float*);
extern "C" LocalM128 _mm_load_ss(const float*);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
extern "C" unsigned __int64 __rdtsc(void);

extern "C" void*(__stdcall* DAT_00fdf044)(unsigned long);

extern unsigned int DAT_0126835c;
extern float DAT_011b6194;
extern char DAT_010d2224[];
extern char DAT_010d2210[];
extern char DAT_010d2200[];
extern char DAT_010c41f8[];

extern "C" LocalM128 _mm_set_ss(float);
extern "C" LocalM128 _mm_set_ps1(float);
extern "C" LocalM128 _mm_load_ps1(const float*);
extern "C" LocalM128 _mm_move_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_setzero_ps();
extern "C" float _mm_cvtss_f32(LocalM128);

struct MonRec
{
    const char* name;
    unsigned int tsc;
    unsigned int unk08;
};

struct MonStream
{
    int unk00;
    MonRec* cur;
    int unk08;
    MonRec* end;
};

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
static __forceinline void monBegin(const char* tag, volatile unsigned int* stamped)
{
    MonStream* s = (MonStream*)TlsGetValue(DAT_0126835c);
    MonRec* c = s->cur;
    if (c < s->end)
    {
        c->name = tag;
        _ReadWriteBarrier();
        *stamped = (unsigned int)__rdtsc();
        c->tsc = *stamped;
        s->cur = c + 1;
    }
}
static __forceinline void monEnd(const char* tag, volatile unsigned int* stamped)
{
    MonStream* s = (MonStream*)DAT_00fdf044(DAT_0126835c);
    MonRec* c = s->cur;
    if (c < s->end)
    {
        c->name = tag;
        _ReadWriteBarrier();
        *stamped = (unsigned int)__rdtsc();
        c->tsc = *stamped;
        s->cur = c + 1;
    }
}

static __forceinline LocalM128 makeLine(const LocalM128& pos, const LocalM128& axis, const float& s)
{
    LocalM128 x = _mm_load_ss(&s);
    return _mm_add_ps(pos, _mm_mul_ps(_mm_shuffle_ps(x, x, 0), axis));
}

struct Motion
{
    int m00, m04, m08, m0c;
    LocalM128 axisX;
    LocalM128 axisY;
    LocalM128 axisZ;
    int m40, m44, m48, m4c, m50, m54, m58, m5c;
    LocalM128 pos;
    float FUN_00c86430();
};

struct Body
{
    int unk00, unk04, unk08, unk0c;
    int idAt10;
    int unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
    int unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c;
    int unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c;
    int unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac;
    int unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc;
    int unkd0, unkd4, unkd8, unkdc;
    Motion motion;
};

struct DisplayHandler
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void DisplayLine(const LocalM128& start, const LocalM128& end, unsigned int color, void* id, void* tag);
};

struct HandlerOwner
{
    DisplayHandler* handler;
    int b04, b08, b0c, b10;
};

struct COMViewerPart
{
    int unk00;
    Body** items;
    int count;
    void hkpRigidBodyCentreOfMassViewer_postSimulationCallback(void* unused);
};

struct COMViewer : HandlerOwner, COMViewerPart
{
};

// For each body whose motion.FUN_00c86430() is nonzero, draws red, green and blue lines from its position along its three axes through the display handler.
// @fnv 0x00d69d00
// src: XBOX_PDB 0x00d69d00
void COMViewerPart::hkpRigidBodyCentreOfMassViewer_postSimulationCallback(void* unused)
{
    (void)unused;
    struct Timings
    {
        volatile unsigned int begin, computeEnd, displayBegin, finalEnd;
    } timers;
    monBegin(DAT_010d2224, &timers.begin);
    int i = 0;
    if (count > i)
    {
        do
        {
            Body* body = items[i];
            if (body->motion.FUN_00c86430() != 0.0f)
            {
                monBegin(DAT_010d2210, &timers.begin);
                const float& scale = DAT_011b6194;
                struct Lines
                {
                    LocalM128 pos, endZ, endX, endY;
                } axisLines;
                axisLines.pos = items[i]->motion.pos;
                Body* const& selected = items[i];
                axisLines.endX = makeLine(axisLines.pos, selected->motion.axisX, scale);
                axisLines.endY = makeLine(axisLines.pos, selected->motion.axisY, scale);
                axisLines.endZ = makeLine(axisLines.pos, selected->motion.axisZ, scale);
                monBegin(DAT_010c41f8, &timers.computeEnd);
                monEnd(DAT_010d2200, &timers.displayBegin);
                void* id = &items[i]->idAt10;
                static_cast<COMViewer*>(this)->handler->DisplayLine(axisLines.pos, axisLines.endX, 0xFFFF0000u, id,
                                                                    DAT_01269020);
                static_cast<COMViewer*>(this)->handler->DisplayLine(axisLines.pos, axisLines.endY, 0xFF008000u, id,
                                                                    DAT_01269020);
                static_cast<COMViewer*>(this)->handler->DisplayLine(axisLines.pos, axisLines.endZ, 0xFF0000FFu, id,
                                                                    DAT_01269020);
                monEnd(DAT_010c41f8, &timers.finalEnd);
            }
            ++i;
        } while (i < count);
    }
    monEnd(DAT_010c41f8, &timers.finalEnd);
}

// MSVC adjustor thunk: the primary base occupies 0x8 bytes; both bases declare the virtual,
// the derived class defines only its constructor, so the compiler emits the this-adjusting thunk.
struct PrimaryBase
{
    virtual void FUN_00d6a1b0();
    int unk04;
};

struct SecondaryBase
{
    virtual void FUN_00d6a1b0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d6a1b0
    virtual void FUN_00d6a1b0();
};

Derived::Derived()
{}

// FUN_00d6a1c0 : MSVC this-adjusting thunk.
//
// The original is 8 bytes:  sub ecx, 0x28 ; jmp 0x00d6a1f0
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
// function symbol carrying the name FUN_00d6a1c0, and a defined key function in the
// derived class makes the vftable that references the thunk be emitted here.
struct AdjBase1
{
    AdjBase1();
    virtual void AdjustThisAndForward_00d6a1c0();
    char pad[0x24];
};

struct AdjBase2
{
    AdjBase2();
// @fnv 0x00d6a1c0
// src: GUESS 0x00d6a1c0 (confidence: low)
    virtual void AdjustThisAndForward_00d6a1c0();
};

struct AdjOwner : AdjBase1, AdjBase2
{
    AdjOwner();
    virtual void key_fn();  // key function - defined, so the vftable is emitted
    void AdjustThisAndForward_00d6a1c0();    // the shared override - declared only
};

AdjOwner::AdjOwner()
{}
void AdjOwner::key_fn()
{}

AdjOwner* make_adj_owner()
{
    static AdjOwner o;
    return &o;
}

namespace fnv_00d6a1d0 {
// sub ecx,0x2c; jmp DestroyOwner: adjustor thunk from multiple inheritance.
// PrimaryBase is vptr + 10 dwords = 0x2c bytes.
struct PrimaryBase
{
    virtual void FUN_00d6a1d0();
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

struct SecondaryBase
{
    virtual void FUN_00d6a1d0();
};

struct AdjDerived : PrimaryBase, SecondaryBase
{
    AdjDerived();
// @fnv 0x00d6a1d0
    virtual void FUN_00d6a1d0();
};

AdjDerived::AdjDerived()
{}
}  // namespace fnv_00d6a1d0

struct Parent;
struct FirstBase
{
    virtual Parent* FUN_00d6a1e0(unsigned int flags) = 0;
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
};
struct Receiver
{
    virtual Parent* FUN_00d6a1e0(unsigned int flags) = 0;
};
struct Parent : FirstBase, Receiver
{
    Parent();
// @fnv 0x00d6a1e0
    virtual Parent* FUN_00d6a1e0(unsigned int flags);
};
Parent::Parent()
{}

#include <math.h>
extern "C" void _mm_store_ss(float*, LocalM128);
extern "C" LocalM128 _mm_add_ss(LocalM128, LocalM128);

struct Vec4Clamp
{
    LocalM128 m_vComponents;
};

// Clamps the vector in v to maxLen by scaling it down when its squared length exceeds maxLen squared.
// @fnv 0x00d6b330
// src: GUESS 0x00d6b330 (confidence: high)
static __declspec(noinline) void __cdecl Hkprigidbodycentreofmassviewer_ClampVectorLength(Vec4Clamp* apVec, float maxLen)
{
    LocalM128 vComponents = apVec->m_vComponents;
    LocalM128 vSquared = _mm_mul_ps(vComponents, vComponents);
    float fLenSq;
    _mm_store_ss(&fLenSq, _mm_add_ss(_mm_shuffle_ps(vSquared, vSquared, 0xaa),
                                     _mm_add_ss(_mm_shuffle_ps(vSquared, vSquared, 0x55), vSquared)));
    float fMaxSq = maxLen * maxLen;
    if (fLenSq > fMaxSq)
    {
        float invLen = 1.0f / sqrtf(fLenSq);
        float s = invLen * maxLen;
        LocalM128 sv = _mm_load_ss(&s);
        apVec->m_vComponents = _mm_mul_ps(_mm_shuffle_ps(sv, sv, 0), vComponents);
    }
}

volatile float g_clampLen;
Vec4Clamp* volatile g_clampVec;
void CallClamp_d6b330()
{
    Hkprigidbodycentreofmassviewer_ClampVectorLength(g_clampVec, g_clampLen);
}

struct Callback
{
    virtual void unused();
    virtual void deliver(int entry);
};
struct RemovalEntityList
{
    int* entries;
    int count;
};
struct Record
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
    RemovalEntityList data48;
};
struct Context
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Record* special20;
    int unk24;
    Record** list28;
    int count2c;
    int unk30;
    Record** list34;
    int count38;
    void hkpWorld_addEntityListener(Callback* ptr);
    void hkpWorld_addWorldPostSimulationListener(int* ptr);
};
struct CenterOfMassRemovalDispatcher
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
    Callback callback28;
    int data2c;
    void ProcessEntries_00d69c10(Context* context);
};
// Passes callback28 and data2c to context, then calls callback28.deliver for each entry in the data48 lists of list28, list34 and special20.
// @fnv 0x00d69c10
// src: GUESS 0x00d69c10 (confidence: low)
void CenterOfMassRemovalDispatcher::ProcessEntries_00d69c10(Context* context)
{
    context->hkpWorld_addEntityListener(this ? &callback28 : 0);
    context->hkpWorld_addWorldPostSimulationListener(this ? &data2c : 0);
    for (int i = 0; i < context->count2c; ++i)
    {
        RemovalEntityList* pRemovalList = &context->list28[i]->data48;
        for (int j = 0; j < pRemovalList->count; ++j)
        {
            callback28.deliver(pRemovalList->entries[j]);
        }
    }
    for (int i = 0; i < context->count38; ++i)
    {
        RemovalEntityList* pRemovalList = &context->list34[i]->data48;
        for (int j = 0; j < pRemovalList->count; ++j)
        {
            callback28.deliver(pRemovalList->entries[j]);
        }
    }
    Record* pSpecialRecord = context->special20;
    if (pSpecialRecord != 0)
    {
        for (int j = 0; j < pSpecialRecord->data48.count; ++j)
        {
            callback28.deliver(pSpecialRecord->data48.entries[j]);
        }
    }
}


template <typename T> __forceinline void hkArrayBase<T>::removeAt(int index)
{
    m_iElementCount--;
    if (m_iElementCount != index)
        m_data[index] = m_data[m_iElementCount];
}
