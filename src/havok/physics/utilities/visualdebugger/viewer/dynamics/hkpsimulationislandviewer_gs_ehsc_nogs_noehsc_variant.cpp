
// src/havok/physics/utilities/visualdebugger/viewer/dynamics/hkpsimulationislandviewer_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-30 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/utilities/visualdebugger/viewer/dynamics/hkpsimulationislandviewer.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/utilities/visualdebugger/viewer/dynamics/hkpsimulationislandviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/hkpsimulationislandviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#define FNV_VEC4_SIMD
#include "../../../../../../../include/Vec4.h"
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
S_00d65180_Base2* hkpSimulationIslandViewer_create(void* arg);
extern int g_D651E0Value;
int __cdecl Object_GetG_D651E0Value_00d651e0();
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
class RegistryOwner
{
  public:
    void* Register(const char* name, void (*callback)());
};
extern RegistryOwner* DAT_01269cd0;
extern void* DAT_01268fdc;
extern const char str_010d19d0[];
extern void RegisterCallback();
void hkpSimulationIslandViewer_registerViewer();
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

#include <xmmintrin.h>
#include <windows.h>
inline void* operator new(unsigned int, void* p)
{
    return p;
}

extern DWORD DAT_0126835c;
extern float DAT_0104da48;
extern float DAT_0104e148;
extern const char str_010c41f8[];
extern void* DAT_01268fdc;
extern "C" void _ReadWriteBarrier(void);
unsigned __int64 __cdecl __rdtsc(void);

struct TraceRecord
{
    const char* m_pTag;
    DWORD m_dwTime;
    DWORD unk08;
};
struct TraceBuffer
{
    DWORD unk00;
    TraceRecord* m_pCurrent;
    DWORD unk08;
    TraceRecord* m_pRecordEnd;
};

struct Count
{
    int value;
    Count(int n) : value(n)
    {}
    ~Count()
    {}
    operator int() const
    {
        return value;
    }
    int operator--()
    {
        return --value;
    }
};
struct hkArrayHeader;
struct DeallocCtx
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(void* pData, int iSize);
    void __cdecl hkArrayUtil__reserve(void*, int, int);
    __forceinline void Grow(hkArrayHeader* v, int need, int elemSize);
};

struct Singleton
{
    int m_00;
    int m_04;
    int m_08;
    DeallocCtx* m_0c;
    DeallocCtx* m_10;
};

// Untyped Havok hkArray<T> header: m_data, m_size, m_capacityAndFlags (0x80000000 = DONT_DEALLOCATE);
// FUN_00c908c0 is the reserve helper. No shared hkArray header exists.
struct hkArrayHeader
{
    void* m_pData;
    int m_iArrayLength;
    int m_iCapacity;
};

__forceinline void DeallocCtx::Grow(hkArrayHeader* v, int need, int elemSize)
{
    _ReadWriteBarrier();
    int cap = v->m_iCapacity & 0x3fffffff;
    if (cap < need)
    {
        int g = cap + cap;
        if (need >= g)
            g = need;
        hkArrayUtil__reserve(v, g, elemSize);
    }
}
inline void GrowVec10(hkArrayHeader* v, int need, int elemSize)
{
    Singleton* router = (Singleton*)hkMemoryRouter_getInstance();
    DeallocCtx* ctx = router->m_10;
    _ReadWriteBarrier();
    ctx->Grow(v, need, elemSize);
}
inline void GrowVec0c(hkArrayHeader* v, int need, int elemSize)
{
    Singleton* router = (Singleton*)hkMemoryRouter_getInstance();
    DeallocCtx* ctx = router->m_0c;
    _ReadWriteBarrier();
    ctx->Grow(v, need, elemSize);
}

struct FUN_00de1210
{
    virtual ~FUN_00de1210();
    FUN_00de1210();
    void hkDisplayAABB_setExtents(Vec4* pLo, Vec4* pHi);
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

typedef FUN_00de1210 Elem;

__forceinline void ConstructRange(Elem* first, int total)
{
    for (int n = 0; n < total; ++n)
    {
        if (first + n)
            new (first + n) Elem;
    }
}

struct Cont
{
    Elem* m_pData;
    int m_iArrayLength;
    int m_iCapacity;
    __forceinline void Resize(int need);
};

__forceinline void Cont::Resize(int need)
{
    Cont* cont = this;
    GrowVec10((hkArrayHeader*)cont, need, 0x80);
    int n = cont->m_iArrayLength - need;
    Elem* e = cont->m_pData + need;
    for (int k = 0; k < n; ++k)
    {
        e->~Elem();
        ++e;
    }
    ConstructRange(cont->m_pData + cont->m_iArrayLength, need - cont->m_iArrayLength);
    cont->m_iArrayLength = need;
}

struct VecI
{
    int* m_pData;
    int m_iArrayLength;
    int m_iCapacity;
};

struct Elem20
{
    Vec4 m_ucLowNibble;
    Vec4 m_ucHighNibble;
};
struct Vec20
{
    Elem20* m_pData;
    int m_iArrayLength;
    int m_iCapacity;
};

struct Obj58
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15(void* pElem, void* pOut);
};

struct ItemHeader;
struct Src
{
    ItemHeader** m_pItems;
    int m_iArrayLength;
};

struct SrcOwner
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
    Src items;
};

struct WorldList
{
    SrcOwner** data;
    int count;
    int capacity;
    __forceinline int size() const
    {
        return count;
    }
    __forceinline SrcOwner*& operator[](int i) const
    {
        return data[i];
    }
};

struct Param
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
    WorldList active;
    WorldList inactive;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    Obj58* m_58;
    __forceinline const WorldList& Active() const
    {
        return active;
    }
    __forceinline const WorldList& Inactive() const
    {
        return inactive;
    }
    __forceinline Obj58* Helper() const
    {
        return m_58;
    }
};

struct EmitObj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14(VecI* pVec, int iColor, int iZero, int iGlob);
};

struct Parent
{
    EmitObj* m_00;
    int unk04, unk08, unk0c;
};

struct Item
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
};

struct ItemHeader
{
    int unk00, unk04, unk08, unk0c;
    Item item;
};

struct OutPair
{
    Vec4 m_ucLowNibble;
    Vec4 m_ucHighNibble;
};

struct ParentObject;
struct ParamArg
{
    Param* volatile p;
    ParamArg(Param* arg) : p(arg)
    {}
    ~ParamArg()
    {}
};

struct ThisCls
{
    int m_00;
    char m_04;
    char m_05;
    unsigned short unk06;
    Cont m_contB;
    Cont m_contA;
    void hkpSimulationIslandViewer_postSimulationCallback(Param* pParam);
};

struct ParentObject : Parent, ThisCls
{
};

// @fnv 0x00d64c00
// src: XBOX_PDB 0x00d64c00
void ThisCls::hkpSimulationIslandViewer_postSimulationCallback(Param* pParam)
{
    TraceBuffer* pForm = (TraceBuffer*)TlsGetValue(DAT_0126835c);
    if (pForm->m_pCurrent < pForm->m_pRecordEnd)
    {
        TraceRecord* acc = pForm->m_pCurrent;
        acc->m_pTag = "TthkpSimulationIslandViewer";
        _ReadWriteBarrier();
        volatile DWORD tick = (DWORD)__rdtsc();
        acc->m_dwTime = tick;
        pForm->m_pCurrent = acc + 1;
    }
    Vec4 currentLo, currentHi;
    OutPair out;
    __m128 seedLo;
    __m128 seedHi;
    VecI offsets;
    int eo;
    if (m_04)
    {
        eo = 0;
        int freeBounds = pParam->active.count;
        if (freeBounds > m_contA.m_iArrayLength)
            m_contA.Resize(freeBounds);
        int pRec = pParam->active.count;
        offsets.m_pData = 0;
        offsets.m_iArrayLength = 0;
        offsets.m_iCapacity = (int)0x80000000;
        GrowVec0c((hkArrayHeader*)&offsets, pRec, 4);
        offsets.m_iArrayLength = pRec;
        int boundsCount = pParam->active.count;
        Vec20 item;
        item.m_pData = 0;
        item.m_iArrayLength = 0;
        item.m_iCapacity = (int)0x80000000;
        GrowVec0c((hkArrayHeader*)&item, boundsCount, 0x20);
        item.m_iArrayLength = boundsCount;
        int z = 0;
        if (z < pParam->active.count)
        {
            seedHi = _mm_set1_ps(DAT_0104e148);
            seedLo = _mm_set1_ps(DAT_0104da48);
            int off = 0;
            do
            {
                Src* src = &pParam->active.data[z]->items;
                item.m_pData[off].m_ucHighNibble.v = seedHi;
                item.m_pData[off].m_ucLowNibble.v = seedLo;
                currentHi.v = seedHi;
                currentLo.v = seedLo;
                for (int j = 0; j < src->m_iArrayLength; ++j)
                {
                    Item* boundsVec = &src->m_pItems[j]->item;
                    if (!boundsVec->m_00)
                    {
                        continue;
                    }
                    pParam->m_58->v15(&boundsVec->m_14, &out);
                    currentHi.v = _mm_max_ps(currentHi.v, out.m_ucHighNibble.v);
                    currentLo.v = _mm_min_ps(currentLo.v, out.m_ucLowNibble.v);
                }
                Elem* a = m_contA.m_pData + eo;
                a->hkDisplayAABB_setExtents(&currentLo, &currentHi);
                offsets.m_pData[z] = (int)(m_contA.m_pData + eo);
                eo += 1;
                off++;
            } while (++z < pParam->active.count);
        }
        EmitObj* i = static_cast<ParentObject*>(this)->Parent::m_00;
        i->v14(&offsets, (int)0xff0000ff, 0, (int)DAT_01268fdc);
        Singleton* freeBoundsRouter;
        freeBoundsRouter = (Singleton*)hkMemoryRouter_getInstance();
        DeallocCtx* need = freeBoundsRouter->m_0c;
        item.m_iArrayLength = 0;
        if ((item.m_iCapacity & 0x80000000) == 0)
        {
            need->v4(item.m_pData, (item.m_iCapacity & 0x3fffffff) * 32);
        }
        item.m_pData = 0;
        item.m_iCapacity = (int)0x80000000;
        Singleton* offsetCount = (Singleton*)hkMemoryRouter_getInstance();
        DeallocCtx* val = offsetCount->m_0c;
        offsets.m_iArrayLength = 0;
        if ((offsets.m_iCapacity & 0x80000000) == 0)
        {
            val->v4(offsets.m_pData, (offsets.m_iCapacity & 0x3fffffff) * 4);
        }
    }
    if (m_05)
    {
        const WorldList& islandsB = pParam->Inactive();
        int freeBounds = islandsB.size();
        if (freeBounds > m_contB.m_iArrayLength)
            m_contB.Resize(freeBounds);
        int pRec;
        pRec = islandsB.size();
        offsets.m_pData = 0;
        offsets.m_iArrayLength = 0;
        offsets.m_iCapacity = (int)0x80000000;
        GrowVec10((hkArrayHeader*)&offsets, pRec, 4);
        offsets.m_iArrayLength = pRec;
        int z = 0;
        if (z < islandsB.size())
        {
            eo = 0;
            do
            {
                Src* src = &islandsB[z]->items;
                currentLo.v = _mm_set1_ps(-3.402820018375656e+38f);
                currentHi.v = _mm_set1_ps(3.402820018375656e+38f);
                for (int j = 0; j < src->m_iArrayLength; ++j)
                {
                    Item* boundsVec = &src->m_pItems[j]->item;
                    if (!boundsVec->m_00)
                    {
                        continue;
                    }
                    pParam->m_58->v15(&boundsVec->m_14, &out);
                    currentLo.v = _mm_max_ps(currentLo.v, out.m_ucHighNibble.v);
                    currentHi.v = _mm_min_ps(currentHi.v, out.m_ucLowNibble.v);
                }
                Elem* a = m_contB.m_pData + eo;
                a->hkDisplayAABB_setExtents(&currentHi, &currentLo);
                offsets.m_pData[z] = (int)(m_contB.m_pData + eo);
                ++eo;
            } while (++z < islandsB.size());
        }
        EmitObj* i = static_cast<ParentObject*>(this)->Parent::m_00;
        i->v14(&offsets, (int)0xff008000, 0, (int)DAT_01268fdc);
        Singleton* offsetCount = (Singleton*)hkMemoryRouter_getInstance();
        DeallocCtx* val = offsetCount->m_10;
        offsets.m_iArrayLength = 0;
        if ((offsets.m_iCapacity & 0x80000000) == 0)
        {
            val->v4(offsets.m_pData, (offsets.m_iCapacity & 0x3fffffff) * 4);
        }
    }
    TraceBuffer* pBuf2 = (TraceBuffer*)TlsGetValue(DAT_0126835c);
    if (pBuf2->m_pCurrent < pBuf2->m_pRecordEnd)
    {
        TraceRecord* acc = pBuf2->m_pCurrent;
        acc->m_pTag = str_010c41f8;
        _ReadWriteBarrier();
        volatile DWORD tick = (DWORD)__rdtsc();
        acc->m_dwTime = tick;
        pBuf2->m_pCurrent = acc + 1;
    }
}
