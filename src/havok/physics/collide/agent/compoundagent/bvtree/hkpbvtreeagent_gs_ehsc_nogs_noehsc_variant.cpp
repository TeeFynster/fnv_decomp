#include "../../../../../../../include/hkArray.h"
#include "../../../../../../../include/Transform.h"


// src/havok/physics/collide/agent/compoundagent/bvtree/hkpbvtreeagent_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/agent/compoundagent/bvtree/hkpbvtreeagent.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/agent/compoundagent/bvtree/hkpbvtreeagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/compoundagent/bvtree/hkpbvtreeagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct S_d2f5a0_Obj
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
    virtual void v9(int a);
};
struct S_d2f5a0_Entry
{
    int unk0;
    int unk4;
    S_d2f5a0_Obj* m_obj;
};
typedef hkArrayBase<S_d2f5a0_Entry> S_d2f5a0_Array;
struct S_d2f5a0
{
    int unk0;
    int unk4;
    int unk8;
    S_d2f5a0_Array m_aiIndexedValues;
    void hkpBvTreeAgent_invalidateTim(int a);
};
struct TargetObject
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void Apply(Transform* apTransform, float afAmount, void* apContext);
};
struct Holder
{
    TargetObject* m_pFlagTarget;
    int unk04;
    void* m_pData;
};
struct ValueSource
{
    int unk00;
    int unk04;
    float m_fAmount;
};
void __cdecl ApplyTransformToTarget(Holder* apFirst, Holder* apSecond, ValueSource* apValue, void* apContext);
struct Allocator
{
    virtual void* release();
    virtual void* allocate(int size);
};
struct Global
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Allocator* allocator;
};
struct Built
{
    int field00;
    short field04;
    int field08;
    void __thiscall FUN_00d2f980(int);
};
extern "C" Global* __cdecl hkMemoryRouter_getInstance();
void __cdecl hkpBvTreeAgent_createShapeBvAgent(int arg1, int arg2, int arg3, int arg4);
void __cdecl hkpBvTreeAgent_staticLinearCast(void* apFirst, void* apSecond, void* apThird, void* apFourth, void* apFifth);
void __stdcall hkpBvTreeAgent_linearCast(void* apFirst, void* apSecond, void* apThird, void* apFourth, void* apFifth);
extern "C" void __cdecl hkpBvTreeAgent_staticGetClosestPoints(void* arg0, void* arg1, void* arg2, void* arg3);
// @fnv 0x00d315d0
// src: HAVOK_SRC 0x00d315d0
extern "C" void __stdcall hkpBvTreeAgent_getClosestPoints(void* arg0, void* arg1, void* arg2, void* arg3)
{
    hkpBvTreeAgent_staticGetClosestPoints(arg0, arg1, arg2, arg3);
}

void __cdecl hkpBvTreeAgent_staticGetPenetrations(void* apA, void* apB, void* apC, void* apD);
void __stdcall hkpBvTreeAgent_getPenetrations(void* apA, void* apB, void* apC, void* apD);
struct D2FA00Allocator
{
    virtual void unk00();
    virtual void* AllocateMemoryBlock(int numBytes);
};
struct D2FA00MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D2FA00Allocator* m_pStreamAllocator;

    D2FA00Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace fnvc_adapt {
extern "C" D2FA00MemoryRouter& __cdecl hkMemoryRouter_getInstance();
}

class D2FA00ReferencedObject
{
  public:
    static void* operator new(unsigned int nbytes)
    {
        D2FA00ReferencedObject* b =
            static_cast<D2FA00ReferencedObject*>(fnvc_adapt::hkMemoryRouter_getInstance().heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    static void operator delete(void* p);
    virtual ~D2FA00ReferencedObject();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
class D2FA00Agent : public D2FA00ReferencedObject
{
  public:
    __declspec(nothrow) D2FA00Agent(void* mgr);

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
};
class D2FA00ShapeAgent : public D2FA00Agent
{
  public:
    D2FA00ShapeAgent(void* mgr) : D2FA00Agent(mgr)
    {}
    virtual ~D2FA00ShapeAgent();
};
D2FA00Agent* __cdecl hkpBvTreeAgent_createBvTreeShapeAgent(const void* bodyA, const void* bodyB, const void* input, void* mgr);
extern char str_010ce9a4[];
extern char str_010ce9ac[];
extern "C" void* __cdecl hkStatisticsCollector_getAllocatedSize(void* apBuffer, int aiCount);
struct S_00d2f8f0_Elem
{
    int unk00;
    int unk04;
    int unk08;
};
struct S_00d2f8f0_Array
{
    S_00d2f8f0_Elem* m_pEntries;
    int m_iArrayLength;

    S_00d2f8f0_Elem* begin() const
    {
        return m_pEntries;
    }
    S_00d2f8f0_Elem* end() const
    {
        return m_pEntries + m_iArrayLength;
    }
};
struct S_00d2f8f0_ArgVtbl
{
    void* unk00;
    void* unk04;
    void* unk08;
    void(__thiscall* unk0c)(void*, char*, int, int);
    void* unk10;
    void(__thiscall* unk14)(void*, int, char*, void*, int, void*);
};
struct S_00d2f8f0_Arg
{
    S_00d2f8f0_ArgVtbl* m_pVtbl;
    int unk04;
    int unk08;
    int unk0c;
    char m_bFlag10;
};
struct S_00d2f8f0
{
    int unk00;
    int unk04;
    int unk08;
    S_00d2f8f0_Array m_aiIndexedValues;
    int m_iFlags;

    void WriteToStream(S_00d2f8f0_Arg* apStream, int aiUnused);
};
class ListenerD2F5
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C(void* pArg);
};
struct EntryD2F5
{
    int unk00;
    int unk04;
    ListenerD2F5* m_pkListener;
};
class OwnerD2F5
{
  public:
    virtual ~OwnerD2F5();

    int unk04[2];
    hkArray<EntryD2F5> m_entries;

    void hkpBvTreeAgent_cleanup(void* pArg);
};

#include <xmmintrin.h>
class SlotObj
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void Eval(void* out, float f, void* box);
};

struct SlotRef
{
    SlotObj* m_ent;
    unsigned int unk04;
    unsigned int m_08;
};

__declspec(align(16)) struct SlotTemp2
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    void Build(unsigned int a, void* b);
};

struct SlotParam
{
    unsigned int unk00;
    unsigned int unk04;
    float m_08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
};

struct SlotBox
{
    __m128 lo;
    __m128 hi;
};

// @fnv 0x00d2f690
// src: XBOX_PDB 0x00d2f690
void hkpBvTreeAgent_calcAabbLinearCast(SlotRef* a, SlotRef* b, SlotParam* p, SlotBox* box)
{
    Transform t1;
    SlotTemp2 t2;
    t1.hkTransform_setMulInverseMul(reinterpret_cast<const Transform*>(b->m_08), reinterpret_cast<const Transform*>(a->m_08));
    SlotObj* obj = a->m_ent;
    obj->Eval(&t1, p->m_08, box);
    t2.Build(b->m_08, (char*)p + 0x50);
    __m128 t = _mm_load_ps((float*)&t2);
    __m128 zero = _mm_setzero_ps();
    __m128 lo = _mm_add_ps(_mm_min_ps(zero, t), box->lo);
    _mm_store_ps((float*)&box->lo, lo);
    box->hi = _mm_add_ps(_mm_max_ps(zero, t), box->hi);
}

class SolBool
{
    char state;

  public:
    SolBool()
    {}
    SolBool(bool x) : state((char)x)
    {}
    operator bool() const
    {
        return state != 0;
    }
};
template <class T> class SolField
{
    T data;

  public:
    __forceinline T operator->() const
    {
        return data;
    }
    __forceinline operator T() const
    {
        return val();
    }
    __forceinline T val() const
    {
        return data;
    }
};
struct SolVec
{
    __m128 q;
    __forceinline SolVec& operator=(const SolVec& r)
    {
        q = r.q;
        return *this;
    }
};
struct SolBox
{
    SolVec low, high;
    SolBool contains(const SolBox& rhs) const
    {
        __m128 lo = _mm_cmple_ps(low.q, rhs.low.q);
        __m128 hi = _mm_cmple_ps(rhs.high.q, high.q);
        return (_mm_movemask_ps(_mm_and_ps(lo, hi)) & 7) == 7;
    }
};
template <class T> struct SolArray;
struct SolContainer;
enum SolKind
{
    SolKindInvalid = -1,
    SolKindLast = 31
};
template <class E, class I> class SolEnum
{
    I data;

  public:
    __forceinline operator E() const
    {
        return static_cast<E>(data);
    }
};
struct SolShape
{
    virtual void v00();
    unsigned short GetAllocationSize, refs;
    int user;
    SolEnum<SolKind, unsigned> type;
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual const SolContainer* GetShapeContainer() const;
    virtual void v14();
    virtual void v18();
    virtual void getAabb(const Transform&, float, SolBox&) const;
    __forceinline SolKind getType() const;
};
struct __declspec(align(16)) SolAlignedShape : SolShape
{
};
__forceinline SolKind SolShape::getType() const
{
    return static_cast<const SolAlignedShape*>(this)->type;
}
struct SolTreeShape : SolShape
{
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void GetAabbHits(const SolBox&, SolArray<unsigned>&) const;
};
struct __declspec(align(16)) SolBuffer
{
    unsigned data[128];
};
struct SolContainer
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual const SolShape* GetShapeForKey(unsigned, SolBuffer&) const;
};
struct SolBody
{
    const SolShape* shape;
    unsigned key;
    const Transform* motion;
    const SolBody* parent;
    __forceinline SolBody(const SolBody* p) : parent(p)
    {
        motion = p->motion;
    }
    __forceinline const Transform& getTransform() const
    {
        return *motion;
    }
    __forceinline const SolShape* getShape() const
    {
        return shape;
    }
    __forceinline void SetCollisionShapeAndKey(const SolShape* s, unsigned k)
    {
        shape = s;
        key = k;
    }
};
struct SolInput;
struct SolShapeFilter
{
    virtual void v00();
    virtual SolBool IsCollisionEnabled(const SolInput&, const SolBody&, const SolBody&, const SolContainer&,
                                       unsigned) const;
};
struct SolReferenced
{
    virtual void v00();
    unsigned short size, refs;
};
struct SolPairFilter
{
    virtual void v00();
};
struct SolFilter : SolReferenced, SolPairFilter, SolShapeFilter
{
    virtual SolBool IsCollisionEnabled(const SolInput&, const SolBody&, const SolBody&, const SolContainer&,
                                       unsigned) const;
};
struct SolOwner;
struct SolManager;
struct SolAgent
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void cleanup(SolOwner&);
    unsigned short GetAllocationSize, refs;
    SolManager* m_pContactManager;
};
typedef SolAgent*(__cdecl* SolFactory)(const SolBody&, const SolBody&, const SolInput&, SolManager*);
struct SolFactoryRecord
{
    SolFactory create;
    void* u04;
    void* u08;
    void* u0c;
    void* u10;
};
struct SolDispatcher;
struct SolInput
{
    SolField<SolDispatcher*> m_pCollisionDispatcher;
    SolField<int> weld;
    SolField<float> tolerance;
    SolField<const SolFilter*> m_iFilter;
    SolField<const void*> convexFilter;
    mutable SolField<int> predictive;
    float getTolerance() const
    {
        return tolerance;
    }
};
struct SolDispatcher
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
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

    unsigned char regular[32][32];
    unsigned char predictive[32][32];
    SolFactoryRecord functions[32];
    enum Prediction
    {
        NoPrediction,
        UsePrediction
    };
    __forceinline SolFactory find(SolKind a, SolKind b, const Prediction& predictiveFlag) const
    {
        int kind = (predictiveFlag ? predictive : regular)[a][b];
        return functions[kind].create;
    }
    __forceinline SolAgent* getNewCollisionAgent(const SolBody& a, const SolBody& b, const SolInput& input,
                                                 SolManager* mgr) const
    {
        const SolKind firstKind = a.getShape()->getType();
        const SolKind secondKind = b.getShape()->getType();
        Prediction prediction = static_cast<Prediction>((int)input.predictive.val());
        SolFactory f = find(firstKind, secondKind, prediction);
        return f(a, b, input, mgr);
    }
};

struct SolHeap
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void freeBuffer(void*, int);
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual bool CanAllocateBytes(int);
};
struct SolStack
{
    char* cursor;
    __forceinline void* allocate(int n, const char*)
    {
        char* p = cursor;
        cursor += n;
        return p;
    }
    __forceinline void deallocate(void* p)
    {
        cursor = (char*)p;
    }
};
struct SolRouter
{
    SolStack local;
    int u04, u08, u0c;
    SolHeap* heapPtr;
    static SolRouter& GetMonitorStream()
    {
        return *reinterpret_cast<SolRouter*>(hkMemoryRouter_getInstance());
    }
    SolHeap& heap()
    {
        return *heapPtr;
    }
    SolStack& stack()
    {
        return local;
    }
};
struct SolHeapSource
{
    SolHeap& get(const void*)
    {
        return SolRouter::GetMonitorStream().heap();
    }
};
template <class T> __forceinline void SolFreeStack(T* p)
{
    SolRouter::GetMonitorStream().stack().deallocate(p);
}
extern void __cdecl hkArrayUtil__reserve(SolHeap&, void*, int, int);
extern void __cdecl hkMemUtil_memMove(void*, const void*, int);
extern void __cdecl hkSetOutOfMemoryState(int);
extern char DAT_011b4284, DAT_01268ad4;
struct SolSortState
{
};
extern void __cdecl QuickSortRange(unsigned*, int, int, SolSortState);
struct SolPlace;
inline void* operator new(unsigned int, SolPlace* p)
{
    return p;
}
struct SolPodTag
{
};
struct SolClassTag
{
};
template <class T> struct SolTypeTag
{
    typedef SolClassTag Type;
};
template <> struct SolTypeTag<unsigned>
{
    typedef SolPodTag Type;
};
namespace SolArrayOps {
template <class T> __forceinline void construct(T*, int, SolPodTag)
{}
template <class T> __forceinline void construct(T* p, int n, SolClassTag)
{
    for (int i = 0; i < n; ++i)
        ::new (reinterpret_cast<SolPlace*>(p + i)) T;
}
template <class T> __forceinline void destroy(T*, int, SolPodTag)
{}
template <class T> __forceinline void destroy(T* p, int n, SolClassTag)
{
    for (int i = 0; i < n; ++i)
        p[i].~T();
}
template <class T> __forceinline void copy(T* d, const T* p, int n)
{
    for (int i = 0; i < n; ++i)
        d[i] = p[i];
}
template <class T> __forceinline void constructFrom(T* d, int n, const T* p, SolClassTag)
{
    for (int i = 0; i < n; ++i)
        ::new (reinterpret_cast<SolPlace*>(d + i)) T(p[i]);
}
__forceinline void move(void* d, const void* p, int n)
{
    hkMemUtil_memMove(d, p, n);
}
__forceinline void copyBytes(void* d, const void* p, int n)
{
    for (int i = 0; i < n; i += 4)
        *reinterpret_cast<unsigned*>((char*)d + i) = *reinterpret_cast<const unsigned*>((const char*)p + i);
}
}
template <class T> struct SolArrayBase
{
    T* data;
    int count;
    int capacity;
    __forceinline SolArrayBase() : data(0), count(0), capacity(0x80000000)
    {}
    __forceinline SolArrayBase(T* p, int n, int c) : data(p), count(n), capacity(c | 0x80000000)
    {}
    inline T* begin()
    {
        return data;
    }
    inline T* end()
    {
        return data + count;
    }
    inline int GetLogicalSize() const
    {
        return count;
    }
    inline int getCapacity() const
    {
        return capacity & 0x3fffffff;
    }
    __forceinline void reserveWith(SolHeap& heap, int n)
    {
        int available = getCapacity();
        if (available < n)
        {
            int twice = 2 * available;
            int target = n < twice ? twice : n;
            hkArrayUtil__reserve(heap, this, target, sizeof(T));
        }
    }
    __forceinline void setSizeWith(SolHeap& heap, int n)
    {
        reserveWith(heap, n);
        SolArrayOps::destroy(data + n, count - n, typename SolTypeTag<T>::Type());
        SolArrayOps::construct(data + count, n - count, typename SolTypeTag<T>::Type());
        count = n;
    }
    __forceinline T* expandWith(SolHeap& heap, int at, int n)
    {
        int total = n + count;
        int shifted = count - at;
        if (total > getCapacity())
            reserveWith(heap, total);
        SolArrayOps::move(data + at + n, data + at, shifted * sizeof(T));
        SolArrayOps::construct(data + at, n, typename SolTypeTag<T>::Type());
        count = total;
        return data + at;
    }
    __forceinline void removeAtAndCopy(int at)
    {
        SolArrayOps::destroy(data + at, 1, typename SolTypeTag<T>::Type());
        --count;
        SolArrayOps::copyBytes(data + at, data + at + 1, (count - at) * sizeof(T));
    }
    __forceinline void clear()
    {
        SolArrayOps::destroy(data, count, typename SolTypeTag<T>::Type());
        count = 0;
    }
    __forceinline void release(SolHeap& heap)
    {
        clear();
        if ((capacity & 0x80000000) == 0)
            heap.freeBuffer(data, getCapacity() * sizeof(T));
        data = 0;
        capacity = 0x80000000;
    }
    __forceinline void assignWith(SolHeap& heap, const SolArrayBase& rhs, SolClassTag)
    {
        int old = count;
        int total = rhs.GetLogicalSize();
        int common = total > old ? old : total;
        reserveWith(heap, total);
        SolArrayOps::destroy(data + total, old - total, SolClassTag());
        SolArrayOps::copy(data, rhs.data, common);
        SolArrayOps::constructFrom(data + common, total - common, rhs.data + common, SolClassTag());
        count = total;
    }
};
template <class T> struct SolArray : SolArrayBase<T>
{
    __forceinline SolArray()
    {}
    __forceinline SolArray(T* p, int n, int c) : SolArrayBase<T>(p, n, c)
    {}
    __forceinline ~SolArray()
    {
        this->release(SolHeapSource().get(this));
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        this->setSizeWith(SolHeapSource().get(this), n);
    }
    __forceinline T* expandAt(int at, int n)
    {
        return this->expandWith(SolHeapSource().get(this), at, n);
    }
    __forceinline SolArray& operator=(const SolArray& rhs)
    {
        this->assignWith(SolHeapSource().get(this), rhs, typename SolTypeTag<T>::Type());
        return *this;
    }
};
template <class T, int N> struct SolFixedArray : SolArray<T>
{
    T storage[N];
    __forceinline SolFixedArray(int n = 0) : SolArray<T>(storage, n, N)
    {}
};
template <class T> struct SolLocalArray : SolArray<T>
{
    T* localMemory;
    __forceinline SolLocalArray(int n)
    {
        this->data = static_cast<T*>(SolRouter::GetMonitorStream().stack().allocate((n * sizeof(T) + 127) & ~127, 0));
        this->capacity = n | 0x80000000;
        localMemory = this->data;
    }
    __forceinline ~SolLocalArray()
    {
        if (localMemory == this->data)
            this->clear();
        SolFreeStack(localMemory);
    }
};
extern D2FA00Agent* __cdecl hkpNullAgent_getNullAgent();
struct SolNull
{
    static D2FA00Agent* getNullAgentOriginal()
    {
        return hkpNullAgent_getNullAgent();
    }
    static SolAgent* GetNullAgent()
    {
        return reinterpret_cast<SolAgent*>(getNullAgentOriginal());
    }
};
namespace SolAlgorithm {
__forceinline void sort(unsigned* p, int n, SolSortState state)
{
    if (n > 1)
        QuickSortRange(p, 0, n - 1, state);
}
__forceinline void quickSort(unsigned* p, int n)
{
    sort(p, n, SolSortState());
}
}
struct SolEntry
{
    unsigned m_key;
    int userInfo;
    SolAgent* m_pCollisionAgent;
    unsigned& GetIteratorKey()
    {
        return m_key;
    }
    void setKey(unsigned& k)
    {
        m_key = k;
    }
};
struct SolUpdater : SolAgent
{
    SolArray<SolEntry> m_kEntries;
    SolBox m_kBoundingBox;
    void hkpBvTreeAgent_prepareCollisionPartners(const SolBody&, const SolBody&, const SolInput&, SolOwner&);
};

struct SolChildState
{
    const SolContainer* container;
    SolBody child;
    SolBuffer scratch;
    SolChildState(const SolBody& parent) : child(&parent)
    {}
    inline const SolBody* getChild(const SolBody&, const SolInput&, unsigned k)
    {
        child.SetCollisionShapeAndKey(container->GetShapeForKey(k, scratch), k);
        return &child;
    }
    inline const SolContainer* GetShapeContainer()
    {
        return container;
    }
};
template <class E> struct SolMerge
{
    static __forceinline void slow(SolArray<E>& entries, SolArray<unsigned>& keys, const SolBody& first,
                                   const SolBody& second, const SolInput& value, SolManager* owner, SolOwner& context,
                                   SolChildState& w)
    {
        E* old = entries.begin();
        E* oldEnd = entries.end();
        unsigned* key = keys.begin();
        unsigned* keyEnd = keys.end();
        SolLocalArray<E> output(keys.GetLogicalSize());
        output.SetSizeAndGrow(keys.GetLogicalSize());
        const SolContainer* container = w.GetShapeContainer();
        E* out = output.begin();
        while (old != oldEnd && key != keyEnd)
        {
            if (*key == old->GetIteratorKey())
            {
                *out = *old;
                ++out;
                ++old;
                ++key;
                continue;
            }
            if (*key < old->GetIteratorKey())
            {
                const SolBody* a = &first;
                const SolBody* b = &second;
                const SolBody* modified = w.getChild(second, value, *key);
                if (value.m_iFilter->IsCollisionEnabled(value, *a, *b, *container, *key))
                    out->m_pCollisionAgent =
                        value.m_pCollisionDispatcher->getNewCollisionAgent(*a, *modified, value, owner);
                else
                    out->m_pCollisionAgent = SolNull::GetNullAgent();
                out->setKey(*key);
                ++out;
                ++key;
                continue;
            }
            if (old->m_pCollisionAgent)
                old->m_pCollisionAgent->cleanup(context);
            ++old;
        }
        while (old != oldEnd)
        {
            if (old->m_pCollisionAgent)
                old->m_pCollisionAgent->cleanup(context);
            ++old;
        }
        while (key != keyEnd)
        {
            const SolBody* a = &first;
            const SolBody* b = &second;
            const SolBody* modified = w.getChild(second, value, *key);
            if (value.m_iFilter->IsCollisionEnabled(value, *a, *b, *container, *key))
                out->m_pCollisionAgent =
                    value.m_pCollisionDispatcher->getNewCollisionAgent(*a, *modified, value, owner);
            else
                out->m_pCollisionAgent = SolNull::GetNullAgent();
            out->setKey(*key);
            ++out;
            ++key;
        }
        entries = output;
    }
    static __forceinline void fast(SolArray<E>& entries, SolArray<unsigned>& keys, const SolBody& first,
                                   const SolBody& second, const SolInput& value, SolManager* owner, SolOwner& context,
                                   SolChildState& w)
    {
        {
            E* entry = entries.begin();
            E* end = entries.end();
            unsigned* hit = keys.begin();
            unsigned* hitEnd = keys.end();
            for (; entry != end; ++entry)
            {
                if (hit != hitEnd && entry->GetIteratorKey() == *hit)
                {
                    ++hit;
                    continue;
                }
                for (hit = keys.begin(); hit != hitEnd; ++hit)
                {
                    if (entry->GetIteratorKey() == *hit)
                    {
                        ++hit;
                        goto found;
                    }
                }
                entry->m_pCollisionAgent->cleanup(context);
                entries.removeAtAndCopy(int(entry - entries.begin()));
                --entry;
                --end;
            found:;
            }
        }
        const SolContainer* container = w.GetShapeContainer();
        if (keys.GetLogicalSize() != entries.GetLogicalSize())
        {
            E* entry = entries.begin();
            E* end = entries.end();
            unsigned* hit = keys.begin();
            unsigned* hitEnd = keys.end();
            for (; hit != hitEnd; ++hit)
            {
                if (entry != end && entry->GetIteratorKey() == *hit)
                {
                    ++entry;
                    continue;
                }
                int at = int(hit - keys.begin());
                entry = entries.expandAt(at, 1);
                const SolBody* a = &first;
                const SolBody* b = &second;
                const SolBody* modified = w.getChild(second, value, *hit);
                if (value.m_iFilter->IsCollisionEnabled(value, *a, *b, *container, *hit))
                    entry->m_pCollisionAgent =
                        value.m_pCollisionDispatcher->getNewCollisionAgent(*a, *modified, value, owner);
                else
                    entry->m_pCollisionAgent = SolNull::GetNullAgent();
                entry->m_key = *hit;
                end = entries.end();
                ++entry;
            }
        }
    }
};
// @fnv 0x00d2fac0
// src: XBOX_PDB 0x00d2fac0
void SolUpdater::hkpBvTreeAgent_prepareCollisionPartners(const SolBody& first, const SolBody& second, const SolInput& value, SolOwner& context)
{
    SolBox bounds;
    {
        Transform transform;
        {
            const Transform& secondTransform = second.getTransform();
            const Transform& firstTransform = first.getTransform();
            transform.hkTransform_setMulInverseMul(secondTransform, firstTransform);
        }
        float extra = value.getTolerance() * 0.5;
        first.getShape()->getAabb(transform, value.getTolerance() + extra, bounds);
        if (DAT_011b4284)
        {
            if (m_kBoundingBox.contains(bounds))
                return;
            m_kBoundingBox = bounds;
        }
    }
    const SolTreeShape* shape = static_cast<const SolTreeShape*>(second.getShape());
    SolFixedArray<unsigned, 128> keys;
    shape->GetAabbHits(bounds, keys);
    int amount = (keys.GetLogicalSize() - m_kEntries.GetLogicalSize()) * 128;
    if (!SolRouter::GetMonitorStream().heap().CanAllocateBytes(amount))
    {
        hkSetOutOfMemoryState(1);
        return;
    }
    const SolContainer* container = shape->GetShapeContainer();
    SolChildState state(second);
    state.container = container;
    if (DAT_01268ad4)
        SolMerge<SolEntry>::fast(m_kEntries, keys, first, second, value, m_pContactManager, context, state);
    else
    {
        SolAlgorithm::quickSort(keys.begin(), keys.GetLogicalSize());
        SolMerge<SolEntry>::slow(m_kEntries, keys, first, second, value, m_pContactManager, context, state);
    }
}
