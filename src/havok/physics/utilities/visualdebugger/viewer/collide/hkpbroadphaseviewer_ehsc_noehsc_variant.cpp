#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkMemoryAllocator.h"

// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpbroadphaseviewer_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-30 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/physics/utilities/visualdebugger/viewer/collide/hkpbroadphaseviewer.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpbroadphaseviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/collide/hkpbroadphaseviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct Container { int ClearValue(void* value); };
struct Owner { int ClearAdjustedValue(Container* container); };
struct FUN_00dd9380_StandIn {
    int hkProcessFactory_registerProcess(const char* name, void* constructor);
};
extern FUN_00dd9380_StandIn* DAT_01269cd0;
extern int DAT_01269028;
extern char DAT_010c65b0;
void hkpBroadphaseViewer_Create();
void __cdecl Object_UpdateFields_00d6ad40();
extern int DAT_01269028;
int Object_GetDAT_01269028_00d6ad60();
struct Target {
    void hkpWorld_addWorldPostSimulationListener(void* apArg);
};
struct FUN_00d6a8e0_cls {
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
struct BroadCtx {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68;
    void** arr;   // +0x6c
    int count;    // +0x70
};
// the secondary base at 0x28 - the listener the shapes are told about
struct PostSimListener {
    virtual void ps0();
    virtual void ps1();
    virtual void ps2();
    virtual void ps3();
};
// one shape of the world; 0xc93920 appends a listener to its list at +0x164
struct BroadElem {
    void hkpWorld_addWorldPostSimulationListener(PostSimListener* p);
};
// the primary base at 0x00 (its vptr is the one at 0x00)
struct PrimBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    int unk04;
};
// the secondary base at 0x08, 0x18 bytes long
struct ProcBase {
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual void w5();
    virtual void w6();
    virtual void w7();
    int unk0c; int unk10; int unk14; int unk18; int unk1c;
};
// the secondary base at 0x20
struct CtxListenerBase {
    virtual void x0();
    virtual void x1();
    virtual void x2();
    virtual void x3();
};
// 0xddccb0 - hkpWorldViewerBase's constructor; it fills the three vptrs it
// owns and the shape list at 0x24
struct WorldViewerBase : PrimBase, ProcBase, CtxListenerBase {
    BroadCtx* m_ctx;              // +0x24
    WorldViewerBase(void* a);
};
// hkpBroadphaseViewer itself (the class is named after the function so that
// its constructor's decorated name carries the tag the checker looks for)
struct FUN_00d6a940 : WorldViewerBase, PostSimListener {
    int unk2c;                     // +0x2c
    int unk30;                     // +0x30
    int unk34;                     // +0x34
    FUN_00d6a940(void* a);
private:
    ~FUN_00d6a940();               // never defined: keeps a second tagged
                                   // symbol out of the object file
};
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
struct SpawnedItem {
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
struct OwnerNode {
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
struct PrimaryBase {
    virtual void unk00();
    unsigned int unk04;
    ~PrimaryBase();
};
struct MidBase {
    virtual void unk00();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};
struct TailBase {
    virtual void unk00();
    OwnerNode* m_pSharedOwner;
};
struct SubObject {
    virtual ~SubObject() {}
};
struct FUN_00d6ac40_cls : PrimaryBase, MidBase, TailBase, SubObject {
    SpawnedItem* m_pData;
    int m_iField30;
    unsigned int m_uiObjectFlags;

    ~FUN_00d6ac40_cls() throw();
};
struct D6AD80Primary {
    virtual void vfunc00();
    virtual void AdjustThisAndForward_00d6ad80();

    int unk04;
};
struct D6AD80Secondary {
    virtual void AdjustThisAndForward_00d6ad80();
};
struct D6AD80Object : D6AD80Primary, D6AD80Secondary {
    D6AD80Object();

// @fnv 0x00d6ad80
// src: GUESS 0x00d6ad80 (confidence: low)
    virtual void AdjustThisAndForward_00d6ad80();
};
D6AD80Object::D6AD80Object()
{
}
struct D6AD90Primary {
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
struct D6AD90Secondary {
    virtual void FUN_00d6ad90();
};
struct D6AD90Object : D6AD90Primary, D6AD90Secondary {
    D6AD90Object();

// @fnv 0x00d6ad90
    virtual void FUN_00d6ad90();
};
D6AD90Object::D6AD90Object()
{
}

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern unsigned long DAT_0126835c;

struct S00d6a9b0_Rec
{
    const char* m_pName;
    unsigned int m_uTick;
    unsigned int unk08;
};

struct S00d6a9b0_Prof
{
    int unk00;
    S00d6a9b0_Rec* m_pCur;
    int unk08;
    S00d6a9b0_Rec* m_pRecordEnd;
};

static inline void S00d6a9b0_Mark(const char* name)
{
    S00d6a9b0_Prof* p = (S00d6a9b0_Prof*)TlsGetValue(DAT_0126835c);
    S00d6a9b0_Rec* r = p->m_pCur;
    if (r < p->m_pRecordEnd)
    {
        r->m_pName = name;
        unsigned int t;
        __asm {
            rdtsc
            mov dword ptr[t], eax
        }
        r->m_uTick = t;
        p->m_pCur = r + 1;
    }
}

// hkMemoryRouter::m_pAllocator (+0x10) is the thread heap, an hkMemoryAllocator (bufAlloc slot 3, bufFree slot 4).
static inline hkMemoryAllocator& __fastcall GetAudioAllocator(hkMemoryRouter* holder)
{
    return *reinterpret_cast<hkMemoryAllocator*>(holder->m_heap);
}

static inline hkMemoryAllocator& S00d6a9b0_heap()
{
    return GetAudioAllocator(hkMemoryRouter_getInstance());
}
void __cdecl hkArrayUtil__reserve(hkMemoryAllocator* a, void* arr, int cap, int elemSize);

template <typename T>
struct S00d6a9b0_Arr
{
    T* m_data;
    int m_iElementCount;
    int m_capFlags;

    S00d6a9b0_Arr() : m_data(0), m_iElementCount(0), m_capFlags((int)0x80000000) {}
    ~S00d6a9b0_Arr()
    {
        hkMemoryAllocator& a = S00d6a9b0_heap();
        m_iElementCount = 0;
        if ((m_capFlags & 0x80000000) == 0)
            a.bufFree(m_data, (m_capFlags & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_capFlags = (int)0x80000000;
    }
    void SetSizeAndGrow(int n);
    void setSizePod(int n)
    {
        reserve(n);
        m_iElementCount = n;
    }
    void reserve(int n)
    {
        hkMemoryAllocator& a = S00d6a9b0_heap();
        int cap = m_capFlags & 0x3fffffff;
        if (cap < n)
        {
            int cap2 = 2 * cap;
            int nc = (n < cap2) ? cap2 : n;
            hkArrayUtil__reserve(&a, this, nc, sizeof(T));
        }
    }
};

struct __declspec(align(16)) S00d6a9b0_Vec
{
    float x, y, z, w;
};

struct __declspec(align(16)) S00d6a9b0_Cap
{
    int n;
};

struct S00d6a9b0_Blk
{
    S00d6a9b0_Vec m_kMinimumCorner;
    S00d6a9b0_Vec m_kMaximumCorner;
};

template <typename T>
static inline void S00d6a9b0_destruct(T* t, int n)
{
    for (int i = 0; i < n; i++)
        t[i].v00(0);
}

template <typename T>
static inline void S00d6a9b0_construct(T* t, int n)
{
    for (int i = 0; i < n; i++)
    {
        T* p = t + i;
        if (p)
            p->FUN_00de1210();
    }
}

template <typename T>
__forceinline void S00d6a9b0_Arr<T>::SetSizeAndGrow(int n)
{
    reserve(n);
    S00d6a9b0_destruct(m_data + n, m_iElementCount - n);
    S00d6a9b0_construct(m_data + m_iElementCount, n - m_iElementCount);
    m_iElementCount = n;
}

template <typename T>
static __forceinline T* S00d6a9b0_bufAlloc(hkMemoryAllocator& a, int n, int& nbytes)
{
    int req = n * (int)sizeof(T);
    T* p = (T*)a.bufAlloc(req);
    nbytes = req;
    return p;
}

struct S00d6a9b0_Req : S00d6a9b0_Arr<S00d6a9b0_Blk>
{
    __forceinline S00d6a9b0_Req(int n)
    {
        int nbytes;
        S00d6a9b0_Blk* p = S00d6a9b0_bufAlloc<S00d6a9b0_Blk>(S00d6a9b0_heap(), n, nbytes);
        S00d6a9b0_Cap c;
        c.n = nbytes / (int)sizeof(S00d6a9b0_Blk);
        if (c.n == 0)
            c.n = (int)0x80000000;
        m_data = p;
        m_capFlags = c.n;
    }
};

struct S00d6a9b0_Item
{
    virtual void v00(int flags);
    int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c;
    void FUN_00de1210();
    void hkDisplayAABB_setExtents(void* a, void* b);
};

struct S00d6a9b0_Sub
{
    virtual void p00(); virtual void p04(); virtual void p08(); virtual void p0c();
    virtual void p10(); virtual void p14(); virtual void p18(); virtual void p1c();
    virtual void p20(); virtual void p24(); virtual void p28(); virtual void p2c();
    virtual void p30(); virtual void p34();
    virtual void Run(void* params);
};

struct S00d6a9b0_Ctx
{
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54;
    S00d6a9b0_Sub* m_58;
};

struct S00d6a9b0_Owner
{
    virtual void o00(); virtual void o04(); virtual void o08(); virtual void o0c();
    virtual void o10(); virtual void o14(); virtual void o18(); virtual void o1c();
    virtual void o20(); virtual void o24(); virtual void o28(); virtual void o2c();
    virtual void o30(); virtual void o34();
    virtual void Fill(void* out, unsigned int mask, int zero, int flags);
};

extern int DAT_01269028;

struct S00d6a9b0_Obj
{
    int unk00;
    S00d6a9b0_Arr<S00d6a9b0_Item> m_aiIndexedValues;

    void hkpBroadphaseViewer_postSimulationCallback(S00d6a9b0_Ctx* a1);
};

struct ViewerPrefix { S00d6a9b0_Owner* m_pOwnerObject; int unk04; int unk08; int unk0c; };
struct WholeViewer : ViewerPrefix, S00d6a9b0_Obj {};

// @fnv 0x00d6a9b0
// src: HAVOK_LIB 0x00d6a9b0
void S00d6a9b0_Obj::hkpBroadphaseViewer_postSimulationCallback(S00d6a9b0_Ctx* a1)
{
    S00d6a9b0_Mark("TthkpBroadphaseViewer");

    S00d6a9b0_Req req(0x400);
    req.m_iElementCount = 0x400;
    a1->m_58->Run(&req);

    if (req.m_iElementCount > m_aiIndexedValues.m_iElementCount)
        m_aiIndexedValues.SetSizeAndGrow(req.m_iElementCount);

    S00d6a9b0_Arr<S00d6a9b0_Item*> ptrs;
    ptrs.setSizePod(req.m_iElementCount);
    for (int k = req.m_iElementCount - 1; k >= 0; k--)
    {
        S00d6a9b0_Blk* b = req.m_data + k;
        m_aiIndexedValues.m_data[k].hkDisplayAABB_setExtents(&b->m_kMinimumCorner, &b->m_kMaximumCorner);
        ptrs.m_data[k] = m_aiIndexedValues.m_data + k;
    }

    static_cast<WholeViewer*>(this)->m_pOwnerObject->Fill(&ptrs, 0xffff0000, 0, DAT_01269028);

    S00d6a9b0_Mark("Et");
}
