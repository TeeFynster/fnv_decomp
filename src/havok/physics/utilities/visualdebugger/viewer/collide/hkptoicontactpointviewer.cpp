
// src/havok/physics/utilities/visualdebugger/viewer/collide/hkptoicontactpointviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/collide/hkptoicontactpointviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkMemoryRouter.h"

extern int currentState;
// @fnv 0x00d68260
// src: GUESS 0x00d68260 (confidence: high)
int __cdecl Object_GetCurrentState() {
    return currentState;
}

struct Built { int field00; short field04; int field08; int __thiscall hkpToiContactPointViewer_hkpToiContactPointViewer(int); };
extern "C" hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
// Allocates a 0x2c-byte Built via the global allocator, sets its field04 to 0x2c, calls FUN_00d682d0(arg), and returns result+8 or 0.
// @fnv 0x00d686b0
// src: XBOX_PDB 0x00d686b0
int __cdecl hkpToiContactPointViewer_create(int arg)
{
    hkMemoryRouter* global = hkMemoryRouter_getInstance();
    hkMemoryAllocator* allocator = reinterpret_cast<hkMemoryAllocator*>(global->m_heap);
    typedef void* (__thiscall* AllocateFunction)(hkMemoryAllocator*, int);
    Built* pBuilt = (Built*)(*reinterpret_cast<AllocateFunction**>(allocator))[1](allocator, 0x2c);
    pBuilt->field04 = 0x2c;
    int result = pBuilt->hkpToiContactPointViewer_hkpToiContactPointViewer(arg);
    if (result) return result + 8;
    return 0;
}

struct SpawnedChild {
    int unk00;
    int unk04;
    int m_i08;
    void Dispatch(int arg);
};

struct FUN_00d66bf0_cls {
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
    SpawnedChild* m_pChildObject;

    void DispatchToChild(int arg);
};

// @fnv 0x00d66bf0
void FUN_00d66bf0_cls::DispatchToChild(int arg)
{
    SpawnedChild* child = m_pChildObject;
    if (child != 0 && child->m_i08 != 0) {
        child->Dispatch(arg);
    }
}

struct Target {
    void hkpWorld_removeContactListener(void* apArg);
};

struct FUN_00d682a0_cls {
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

// Calls apTarget->FUN_00c91a20 with a pointer to this+8, or null if this-0x20 is null.
// @fnv 0x00d682a0
void FUN_00d682a0_cls::InvokeTargetWithSelfOffset(Target* apTarget)
{
    apTarget->hkpWorld_removeContactListener(((char*)this - 0x20) != 0 ? (char*)this + 8 : 0);
}

extern char DAT_0104dd7c[];
extern char DAT_010d1f0c[];
extern char DAT_010d1eec[];
extern char DAT_010d1edc[];
extern char DAT_010d1ebc[];

void __stdcall FUN_00ddccb0(int a1);

struct FUN_00d682d0_cls {
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
    void* m_vtbl28;

    void* hkpToiContactPointViewer_hkpToiContactPointViewer(int a1);
};

// Calls FUN_00ddccb0 with a1, then stores five DAT_ pointers into this at offsets 0x28, 0x00, 0x08, 0x20 and 0x28, and returns this.
// @fnv 0x00d682d0
// src: HAVOK_LIB 0x00d682d0
void* FUN_00d682d0_cls::hkpToiContactPointViewer_hkpToiContactPointViewer(int aiArg)
{
    FUN_00ddccb0(aiArg);
    *(void* volatile*)((char*)this + 0x28) = (void*)&DAT_0104dd7c;
    *(void* volatile*)((char*)this + 0x00) = (void*)&DAT_010d1f0c;
    *(void* volatile*)((char*)this + 0x08) = (void*)&DAT_010d1eec;
    *(void* volatile*)((char*)this + 0x20) = (void*)&DAT_010d1edc;
    *(void* volatile*)((char*)this + 0x28) = (void*)&DAT_010d1ebc;
    return this;
}

struct ItemList {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c;
    int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68;
    void** items;   // +0x6c
    int count;      // +0x70
};

struct Sub {
    virtual void v0();
    virtual void v1(void* item);
};

class FUN_00d68310_cls {
public:
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14;
    Sub m_sub;          // +0x18
    ItemList* m_kNode;   // +0x1c
    void ProcessEntries_00d68310();
};

// Iterates the item list and calls m_sub.v1 on each item until the list ends or the count is reached.
// @fnv 0x00d68310
// src: GUESS 0x00d68310 (confidence: low)
void FUN_00d68310_cls::ProcessEntries_00d68310() {
    int i = 0;
    while (m_kNode != 0) {
        if (i >= m_kNode->count) break;
        m_sub.v1(m_kNode->items[i]);
        i++;
    }
}

struct Part0_t
{
    virtual ~Part0_t() {}
    int m_i04;
};

struct Part1_t
{
    virtual ~Part1_t() {}
};

struct Part2_t
{
    virtual ~Part2_t() {}
};

struct Part3_t
{
    virtual ~Part3_t() {}
};

struct SubObj_t
{
    virtual ~SubObj_t() {}
    void Add(int aiItem);
};

struct ListBlob_t
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
    int* m_items;
    int m_uiItemCount;
};

struct ParentBase_t
{
    void Init();
};

class FUN_00d68350_cls : public Part0_t, public Part1_t
{
public:
    int m_u0c;
    int m_u10;
    int m_u14;
    int m_u18;
    int m_u1c;
    SubObj_t m_sub;
    ListBlob_t* m_pEntries;
    Part2_t m_pTail;

    void ProcessEntries_00d68350();
};

// @fnv 0x00d68350
// src: GUESS 0x00d68350 (confidence: low)
void FUN_00d68350_cls::ProcessEntries_00d68350()
{
    int i = 0;
    this->Part0_t::~Part0_t();
    this->Part1_t::~Part1_t();
    m_sub.SubObj_t::~SubObj_t();
    m_pTail.Part2_t::~Part2_t();
    while (m_pEntries != 0)
    {
        ListBlob_t* p = m_pEntries;
        if (i >= p->m_uiItemCount)
        {
            break;
        }
        m_sub.Add(p->m_items[i]);
        i++;
    }
    ((Part3_t*)&m_pTail)->Part3_t::~Part3_t();
    ((ParentBase_t*)this)->Init();
}

struct StateTarget {
    int __thiscall Dispatch(const char* name, int (__cdecl* handler)(int));
};

extern StateTarget* g_stateTarget;
extern int g_stateResult;
extern const char str_010d1ea0[];

// @fnv 0x00d686f0
void DispatchStateHandler()
{
    g_stateResult = g_stateTarget->Dispatch(str_010d1ea0, hkpToiContactPointViewer_create);
}

struct FUN_00d68270_Base0 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};
struct FUN_00d68270_Base1 {
    int unk00;
    int unk04;
    void ForwardCall_00d68270(struct FUN_00d68270_Arg* arg);
};
struct FUN_00d68270_Base2 {
    int unk00;
};
struct FUN_00d68270_Derived : public FUN_00d68270_Base0, public FUN_00d68270_Base1, public FUN_00d68270_Base2 {
};
struct FUN_00d68270_Arg {
    void hkpWorld_addContactListener(FUN_00d68270_Base2* obj);
};
// Calls arg->FUN_00c93a20 with the address 8 bytes past this, treated as the Base2 part of the enclosing Derived object.
// @fnv 0x00d68270
// src: GUESS 0x00d68270 (confidence: low)
void FUN_00d68270_Base1::ForwardCall_00d68270(FUN_00d68270_Arg* arg)
{
    arg->hkpWorld_addContactListener(reinterpret_cast<FUN_00d68270_Derived*>(reinterpret_cast<char*>(this) - sizeof(FUN_00d68270_Base0)));
}

// sub ecx,0x20; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x20).
struct PrimaryBase
{
    virtual void FUN_00d68710();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};

struct SecondaryBase
{
    virtual void FUN_00d68710();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d68710
    virtual void FUN_00d68710();
};

Derived::Derived()
{
}

// FUN_00d68720 : MSVC this-adjusting thunk  (sub ecx, 0x08 ; jmp <impl>)
struct A1_00d68720 {
    A1_00d68720();
    virtual void AdjustThisAndForward_00d68720();
    char pad[0x04];
};
struct A2_00d68720 {
    A2_00d68720();
    virtual void AdjustThisAndForward_00d68720();
};
struct Own_00d68720 : A1_00d68720, A2_00d68720 {
    Own_00d68720();
    virtual void key_fn();
// @fnv 0x00d68720
// src: GUESS 0x00d68720 (confidence: low)
    void AdjustThisAndForward_00d68720();
};
Own_00d68720::Own_00d68720() { }
void Own_00d68720::key_fn() { }
Own_00d68720* make_00d68720() { static Own_00d68720 o; return &o; }

namespace fnv_00d68730 {
// sub ecx,0x28; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x28).
struct PrimaryBase
{
    virtual void FUN_00d68730();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
};

struct SecondaryBase
{
    virtual void FUN_00d68730();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d68730
    virtual void FUN_00d68730();
};

Derived::Derived()
{
}
}  // namespace fnv_00d68730

namespace fnv_00d68740 {
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();

struct FUN_00d68740 {
    unsigned short m_u04;
    unsigned short m_u06;
    FUN_00d68740();
    virtual ~FUN_00d68740();
    static void operator delete(void* apMemory)
    {
        hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
        unsigned int uiSize = ((FUN_00d68740*)apMemory)->m_u04;
        hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
        // This allocator frees through vtable slot 2; the shared Free declaration is nonvirtual.
        typedef void (__thiscall* FreeFunction)(hkMemoryAllocator*, void*, unsigned int);
        (*reinterpret_cast<FreeFunction**>(pAllocator))[2](pAllocator, apMemory, uiSize);
    }
};

// Constructor that zero-initializes m_u04 and m_u06.
// @fnv 0x00d68740
FUN_00d68740::FUN_00d68740()
{
    m_u04 = 0;
    m_u06 = 0;
}
}  // namespace fnv_00d68740

#include <math.h>

// Exe 0x00d683b0 FUN_00d683b0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    struct { float lane0, lane1, lane2, lane3; };
} __m128, LocalM128;

extern "C" LocalM128 _mm_set_ss(float);
extern "C" float _mm_cvtss_f32(LocalM128);
extern "C" LocalM128 _mm_add_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_sub_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_mul_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_mul_ss(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_add_ss(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_sub_ss(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128 a, LocalM128 b, int imm);
extern "C" LocalM128 _mm_load_ps(const float* p);
extern "C" LocalM128 _mm_load_ss(const float* p);
extern "C" void _mm_store_ss(float* p, LocalM128 a);
extern "C" LocalM128 _mm_rsqrt_ss(LocalM128 a);
extern "C" LocalM128 _mm_sqrt_ss(LocalM128 a);
extern "C" LocalM128 _mm_cmpeq_ss(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_andnot_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_setzero_ps(void);


extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

extern float DAT_0104da4c;
extern float DAT_01011d78;
extern float DAT_01017718;
extern float DAT_01016248;
extern float DAT_01019de0;
extern float DAT_010c69c4;
extern const float DAT_010c69c0=(0.85f-1.0f);
extern float DAT_010ec7f0;
extern unsigned long DAT_0126835c;

// The unit keeps its own __m128 (float lanes only, so /GS adds no cookie); hkVector4.h uses it.
#include "../../../../../../../include/hkVector4.h"

struct Handler {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void DisplayLine(const hkVector4& a, const hkVector4& b, int color, int id, int tag);
};

struct TimerCmd {
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
};

struct MonStream {
    int unk00;
    TimerCmd* m_kRayEnd;
    int unk08;
    TimerCmd* m_cap;
};

__forceinline LocalM128 lengthSquared3(LocalM128 v) {
    LocalM128 sq = _mm_mul_ps(v, v);
    LocalM128 y = _mm_shuffle_ps(sq, sq, 0x55);
    LocalM128 xy = _mm_add_ss(y, sq);
    LocalM128 z = _mm_shuffle_ps(sq, sq, 0xAA);
    return _mm_add_ss(z, xy);
}

__forceinline LocalM128 sqrtInverse(LocalM128 len2) {
    LocalM128 y0 = _mm_rsqrt_ss(len2);
    LocalM128 zero = _mm_set_ss(DAT_01011d78);
    LocalM128 three = _mm_set_ss(DAT_01017718);
    LocalM128 half = _mm_set_ss(DAT_01016248);
    LocalM128 r2 = _mm_mul_ss(_mm_mul_ss(len2, y0), y0);
    LocalM128 eq = _mm_cmpeq_ss(len2, zero);
    LocalM128 inv = _mm_mul_ss(_mm_mul_ss(half, y0), _mm_sub_ss(three, r2));
    return _mm_andnot_ps(eq, inv);
}

__forceinline LocalM128 splat(float s) {
    LocalM128 a = _mm_load_ss(&s);
    return _mm_shuffle_ps(a, a, 0);
}

// @fnv 0x00d683b0
// src: XBOX_PDB 0x00d683b0
static __declspec(noinline) void hkToiContactPointViewer_displayArrow(Handler* self, hkVector4* from, hkVector4* dir, int color, int id, int tag) {
    float lenSq;

    _mm_store_ss(&lenSq, lengthSquared3(dir->v));
    if (lenSq > 1.1920928955078125e-07f) {
        { MonStream* s = (MonStream*)TlsGetValue(DAT_0126835c);
        if (s->m_kRayEnd < s->m_cap) {
            TimerCmd* h = s->m_kRayEnd;
            h->m_pCommandName = "TtToiDisplayArrow";
            unsigned t1;
            __asm {
                rdtsc
                mov dword ptr[t1], eax
            }
            h->m_uiStartTicks = t1;
            s->m_kRayEnd = h + 1;
        } }
        struct Endpoints { hkVector4 head1; hkVector4 perp; };
        Endpoints endpoints;
        hkVector4 to;
        hkVector4 head2;
        to.v = _mm_add_ps(from->v, dir->v);
        int iAlt = 0;
        float cur = fabsf(dir->x);
        int i0 = 1;
        float ay = fabsf(dir->y);
        int i2 = i0 + 1;
        float az = fabsf(dir->z);
        if (ay < cur) {
            cur = ay;
            i0 = 0;
            iAlt = 1;
        }
        if (az < cur) i2 = iAlt;
        endpoints.perp.v = _mm_setzero_ps();
        (&endpoints.perp.x)[i0] = (&dir->x)[i2];
        (&endpoints.perp.x)[i2] = -(&dir->x)[i0];
        LocalM128 inv = sqrtInverse(lengthSquared3(endpoints.perp.v));
        LocalM128 len = _mm_sqrt_ss(lengthSquared3(dir->v));
        LocalM128 perpS = _mm_mul_ps(_mm_mul_ps(endpoints.perp.v, _mm_shuffle_ps(inv, inv, 0)), _mm_shuffle_ps(len, len, 0));
        float coeff = DAT_01019de0;
        LocalM128 cb = splat(coeff);
        LocalM128 one = _mm_load_ps(&DAT_010ec7f0);
        LocalM128 base = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(one, cb), from->v), _mm_mul_ps(cb, to.v));
        float scalePos = DAT_010c69c4;
        endpoints.head1.v = _mm_add_ps(base, _mm_mul_ps(splat(scalePos), perpS));
        float scaleNeg = DAT_010c69c0;
        head2.v = _mm_add_ps(base, _mm_mul_ps(splat(scaleNeg), perpS));
        self->DisplayLine(*from, to, color, id, tag);
        self->DisplayLine(to, endpoints.head1, color, id, tag);
        self->DisplayLine(to, head2, color, id, tag);
        { MonStream* s = (MonStream*)TlsGetValue(DAT_0126835c);
        if (s->m_kRayEnd < s->m_cap) {
            TimerCmd* h = s->m_kRayEnd;
            h->m_pCommandName = "Et";
            unsigned t2;
            __asm {
                rdtsc
                mov dword ptr[t2], eax
            }
            h->m_uiStartTicks = t2;
            s->m_kRayEnd = h + 1;
        } }
    }
}

void RenderLine(Handler* handler, hkVector4* direction, hkVector4* origin, int color, int id, int tag) {
    hkToiContactPointViewer_displayArrow(handler, origin, direction, color, id, tag);
}

extern int DAT_01269004;

class S00d68670_hkBool {
public:
    S00d68670_hkBool(bool b) { m_cBooleanValue = (char)b; }
    operator bool() const { return m_cBooleanValue != 0; }
    char m_cBooleanValue;
};

struct S00d68670_ContactPoint {
    hkVector4 m_vContactPosition;
    hkVector4 m_vSeparatingNormal;
    const hkVector4& getPosition() { return m_vContactPosition; }
    const hkVector4& getNormal() const { return m_vSeparatingNormal; }
};

struct S00d68670_Collidable {
    int unk00;
};

struct S00d68670_Entity {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S00d68670_Collidable m_kCollidable;
    const S00d68670_Collidable* getCollidable() const { return &m_kCollidable; }
};

struct S00d68670_ContactPointEvent {
    void* m_pObservedSource;
    S00d68670_Entity* m_apEntities[2];
    void* m_pContactManager;
    int m_type;
    S00d68670_ContactPoint* m_vContactPoint;
    S00d68670_hkBool isToi() const { return m_type <= 0; }
};

struct S00d68670_WorldViewerBase {
    virtual void v00();
    int unk04;
    int unk08;
    Handler* m_pDisplayHandler;
    int unk10;
    int unk14;
    int unk18;
};

struct S00d68670_ContactListener {
    virtual void hkpToiContactPointViewer_contactPointCallback(const S00d68670_ContactPointEvent& event);
};

struct S00d68670_ToiContactPointViewer : S00d68670_WorldViewerBase, S00d68670_ContactListener {
    virtual void hkpToiContactPointViewer_contactPointCallback(const S00d68670_ContactPointEvent& event);
};

// @fnv 0x00d68670
// src: XBOX_PDB 0x00d68670
void S00d68670_ToiContactPointViewer::hkpToiContactPointViewer_contactPointCallback(const S00d68670_ContactPointEvent& event)
{
    if (event.isToi())
    {
        const S00d68670_Collidable* collidable = event.m_apEntities[0]->getCollidable();
        hkToiContactPointViewer_displayArrow(m_pDisplayHandler, (hkVector4*)&event.m_vContactPoint->getPosition(), (hkVector4*)&event.m_vContactPoint->getNormal(), 0xffff0000, (int)collidable, DAT_01269004);
    }
}
