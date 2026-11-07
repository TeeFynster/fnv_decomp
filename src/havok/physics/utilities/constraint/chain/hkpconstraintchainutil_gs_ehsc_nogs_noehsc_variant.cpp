#include "../../../../../../include/hkArray.h"
// src/havok/physics/utilities/constraint/chain/hkpconstraintchainutil_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/utilities/constraint/chain/hkpconstraintchainutil.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.


// src/havok/physics/utilities/constraint/chain/hkpconstraintchainutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/constraint/chain/hkpconstraintchainutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/Pair.h"
#include "../../../../../../include/V4.h"

struct CallTarget_00e5c370
{
    int InsertAndDelete(int, int, int, int, int);
};
struct SearchObject
{
    int ProcessAndReturnValue_00e5c420(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3);
};
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();
struct DispatchTarget
{
    void CallWithFlag(void* aValue, int aZero, void* aOut);
};
struct OutObject
{
    void FUN_00c90510();
};
struct FUN_00e5c460_cls
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
    DispatchTarget m_38;

    void hkpConstraintChainInstance_insertEntityAtFront(OutObject* a1);
};
#include <xmmintrin.h>
__declspec(align(16)) struct XfOut_cls
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
};
struct FUN_00c7f690_cls
{
    void hkVector4_setTransformedInversePos(const __m128* m, const __m128* v);
};
struct XfSub_cls
{
    void Push(XfOut_cls* a, XfOut_cls* b);
};
struct XfScene_cls
{
    int unk00;
    int unk04;
    int unk08;
    XfSub_cls* m_0c;
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
    char** m_38;
    int m_3c;
    void AddReferencedObject(XfScene_cls* other);
};
static char* XfSelectRec(char* rec)
{
    if (rec[0x18] == 1)
    {
        return rec + (signed char)rec[0x10];
    }
    return 0;
}
void hkpConstraintChainUtil_addConstraintToBallSocketChain(XfScene_cls* a1, XfScene_cls* a2, const __m128* a3);
// FUN_00e5b8f0: __cdecl, 317 bytes
// Two 16-byte keys are filled by FUN_00e5ad40; the sorted-list tail is compared against
// the owner's keys; the matching branch hands a 32-byte pair to a sub-object or holder.
struct __declspec(align(16)) Tmp16
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
};
struct __declspec(align(16)) Pair32
{
    Tmp16 lo;
    Tmp16 hi;
};
static void CopyTmp16(Tmp16* dst, const Tmp16* src)
{
    _mm_store_ps(reinterpret_cast<float*>(dst), _mm_load_ps(reinterpret_cast<const float*>(src)));
}
struct KeyOwnerA
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int m_14;
    unsigned int m_18;
};
struct Sub18
{
    void ProcessAndReturnValue_00e5c440(hkMemoryAllocator* a, int b, Pair32* c);
};
struct OwnerC
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    Sub18 m_18;
    void Push(Tmp16* a, Tmp16* b);
};
struct ListB
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
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
    unsigned int* m_38;
    unsigned int m_3c;
    void AddReferencedObject(unsigned int key);
    void hkpConstraintChainInstance_insertEntityAtFront(unsigned int key);
};
int hkpConstraintUtils_getConstraintPivots(KeyOwnerA* a, Tmp16* p, Tmp16* q);
int hkpConstraintChainUtil_addConstraintToChain(KeyOwnerA* a1, ListB* a2, OwnerC* a3, ...);
inline void* operator new(unsigned int, void* p)
{
    return p;
}
inline void operator delete(void*, void*)
{}
struct S_00e5c370_Elem
{
    V4 a;
    V4 b;
    S_00e5c370_Elem(const S_00e5c370_Elem& o)
    {
        reinterpret_cast<__m128&>(a) = reinterpret_cast<const __m128&>(o.a);
        reinterpret_cast<__m128&>(b) = reinterpret_cast<const __m128&>(o.b);
    }
};
void __cdecl hkArrayUtil__reserve(hkMemoryAllocator& alloc, void* arr, int numElem, int sizeElem);
void __cdecl hkMemUtil_memMove(void* dst, const void* src, int nbytes);
template <class T>
static __forceinline void S_00e5c370_ArrayBase_GrowArrayCapacity(hkArrayBase<T>& self, hkMemoryAllocator& a, int n);

template <class T>
static __forceinline void S_00e5c370_ArrayBase_GrowArrayCapacity(hkArrayBase<T>& self, hkMemoryAllocator& a, int n)
{
        const int cap = self.getCapacity();
        if (cap < n)
        {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayUtil__reserve(a, (&self), newSize, sizeof(T));
        }
    }


__forceinline V4::V4()
{}
__forceinline V4::V4(const V4& other)
{
    m = other.m;
}
__forceinline void V4::operator=(const V4& other)
{
    m = other.m;
}
template <class T> struct ArrayView
{
    T* data;
    int size;
    int capacity;
    __forceinline T& operator[](int index)
    {
        return data[index];
    }
    __forceinline const T& operator[](int index) const
    {
        return data[index];
    }
    __forceinline T& back()
    {
        return data[size - 1];
    }
    __forceinline const T& back() const
    {
        return data[size - 1];
    }
    __forceinline int GetLogicalSize() const
    {
        return size;
    }
};
template <class T> struct Array : ArrayView<T>
{
};
template <class T> inline void exchangeValues(T& a, T& b)
{
    T saved = a;
    a = b;
    b = saved;
}
struct RefObject
{
    virtual ~RefObject();
    virtual void v04();
    virtual void v08();
    unsigned short sizeFlags, refs;
    void FUN_00c905b0() const;
};
struct Node : RefObject
{
    int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc, unke0, unke4, unke8, unkec, unkf0, unkf4, unkf8, unkfc;
    int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c, unk120, unk124, unk128, unk12c, unk130, unk134,
        unk138, unk13c;
    int unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c;
    V4 position;
};
struct Body : RefObject
{
    virtual Body* v0c() const;
};
struct Edge : RefObject
{
    int unk08;
    void* data;
    int unk10;
    Node* a;
    Node* b;
    __forceinline Node* getA() const
    {
        return a;
    }
    __forceinline Node* getB() const
    {
        return b;
    }
    inline const void* getData() const
    {
        return data;
    }
};
struct Edges : Array<Edge*>
{
};
struct ByteFlag
{
    unsigned char value;
    inline operator bool() const
    {
        return value != 0;
    }
};
struct Record
{
    V4 a, b, c, d;
    Body* first;
    Body* second;
    Body* third;
    unsigned char reversed;
};
inline void* allocateObject(unsigned int size)
{
    hkMemoryRouter* holder = hkMemoryRouter_getInstance();
    void* memory = reinterpret_cast<hkMemoryAllocator*>(holder->m_heap)->blockAlloc(size);
    static_cast<RefObject*>(memory)->sizeFlags = (unsigned short)size;
    return memory;
}
struct FUN_00e3b8f0 : RefObject
{
    int unk08, unk0c, unk10, unk14;
    Record* records;
    int count;
    int capacity;
    int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    FUN_00e3b8f0();
    static void* operator new(unsigned int size)
    {
        return allocateObject(size);
    }
    void addConstraintInfoInBodySpace(const V4*, const V4*, const V4*, Body*, Body*, Body*);
};
struct FUN_00dd0530 : Edge
{
    int unk1c, unk20, unk24, unk28, unk2c, unk30, unk34;
    Array<Node*> nodes;
    void* action;
    FUN_00dd0530(FUN_00e3b8f0*);
    static void* operator new(unsigned int size)
    {
        return allocateObject(size);
    }
    void AddReferencedObject(Node*);
};

struct Stream
{
    int unk00, unk04, unk08;
    void FUN_00cb1600(void*, int);
    void ProcessAndReturnValue_00cc01c0(const char*);
    void FUN_00cc00e0();
};
struct Reporter;
struct ReporterVtable
{
    void* v00;
    void* v04;
    void* v08;
    void(__thiscall* report)(Reporter*, int, unsigned int, const char*, const char*, int);
};
struct Reporter
{
    ReporterVtable* vtable;
};
extern Reporter* DAT_01268360;
static const char unsupported[] = "Not supported types of constraints used to build a chain!";
static const char* const filename = ".\\Constraint\\Chain\\hkpConstraintChainUtil.cpp";
static const char unordered[] =
    "Constraints are not ordered properly ! Two consecutive constraint share no common hkpEntity.";
static const char nomotors[] = "No motors extracted from the original constraint.";
int __cdecl hkpConstraintUtils_getConstraintPivots(const Edge*, V4&, V4&);
void __cdecl GetConstraintMotorValues(const void*, Body*&, Body*&, Body*&);
struct Buffer
{
    void* words[128];
    operator char*()
    {
        return reinterpret_cast<char*>(words);
    }
};
// Preserve the original helper's ECX result pointer and two stack arguments.
inline void __fastcall SetRelativeRotation(V4* result, void*, const V4* left, const V4* right)
{
    const __m128 a = reinterpret_cast<const __m128&>(*left);
    const __m128 b = reinterpret_cast<const __m128&>(*right);
    __m128 cross = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(b, b, 0xc9), _mm_shuffle_ps(a, a, 0xd2)),
                              _mm_mul_ps(_mm_shuffle_ps(b, b, 0xd2), _mm_shuffle_ps(a, a, 0xc9)));
    const __m128 aw = _mm_shuffle_ps(a, a, 0xff);
    const __m128 bw = _mm_shuffle_ps(b, b, 0xff);
    __m128 imag = _mm_sub_ps(_mm_add_ps(cross, _mm_mul_ps(aw, b)), _mm_mul_ps(bw, a));
    __m128 dot = _mm_mul_ps(a, b);
    dot = _mm_add_ps(dot, _mm_shuffle_ps(dot, dot, 0x4e));
    dot = _mm_add_ps(dot, _mm_shuffle_ps(dot, dot, 0xb1));
    dot = _mm_shuffle_ps(dot, dot, 0);
    __m128 high = _mm_unpackhi_ps(imag, dot);
    result->m = _mm_shuffle_ps(imag, high, 0xc4);
}

// @fnv 0x00e5b510
// src: XBOX_PDB 0x00e5b510
FUN_00dd0530* __cdecl hkpConstraintChainUtil_buildPoweredChain(Edges& edges, ByteFlag clone)
{
    FUN_00e3b8f0* chain = new FUN_00e3b8f0;
    FUN_00dd0530* result = new FUN_00dd0530(chain);
    Node* start = edges.data[0]->getA();
    if (edges.size > 1 && (start == edges.data[1]->getA() || start == edges.data[1]->getB()))
        start = edges.data[0]->getB();
    result->AddReferencedObject(start);
    Buffer buffer;
    for (int i = 0; i < edges.size; ++i)
    {
        union
        {
            Stream validationStream;
            struct
            {
                Body* a;
                Body* b;
                Body* c;
            };
        };
        V4 first;
        V4 second;
        if (hkpConstraintUtils_getConstraintPivots(edges[i], first, second) == 1)
        {
            validationStream.FUN_00cb1600(buffer, 512);
            validationStream.ProcessAndReturnValue_00cc01c0(unsupported);
            DAT_01268360->vtable->report(DAT_01268360, 1, 0xabbad88d, buffer, filename, 183);
            validationStream.FUN_00cc00e0();
            chain->FUN_00c905b0();
            result->FUN_00c905b0();
            return 0;
        }
        if (edges[i]->getA() != result->nodes.back())
        {
            exchangeValues(first, second);
            if (edges[i]->getB() != result->nodes.back())
            {
                validationStream.FUN_00cb1600(buffer, 512);
                validationStream.ProcessAndReturnValue_00cc01c0(unordered);
                DAT_01268360->vtable->report(DAT_01268360, 1, 0xabbad88d, buffer, filename, 194);
                validationStream.FUN_00cc00e0();
                chain->FUN_00c905b0();
                result->FUN_00c905b0();
                return 0;
            }
        }
        V4 rotation;
        reinterpret_cast<void (__thiscall*)(V4*, const V4*, const V4*)>(SetRelativeRotation)(
            &rotation, &edges[i]->getA()->position, &edges[i]->getB()->position);
        GetConstraintMotorValues(edges[i]->data, a, b, c);
        if (!a)
        {
            Stream validationStream;
            validationStream.FUN_00cb1600(buffer, 512);
            validationStream.ProcessAndReturnValue_00cc01c0(nomotors);
            DAT_01268360->vtable->report(DAT_01268360, 1, 0xabba88d3, buffer, filename, 207);
            validationStream.FUN_00cc00e0();
            chain->FUN_00c905b0();
            result->FUN_00c905b0();
            return 0;
        }
        if (!b)
            b = a;
        if (!c)
            c = a;
        if (clone)
        {
            a = a->v0c();
            b = b->v0c();
            c = c->v0c();
        }
        chain->addConstraintInfoInBodySpace(&first, &second, &rotation, a, b, c);
        if (edges[i]->getA() == result->nodes.back())
        {
            chain->records[chain->count - 1].reversed = 1;
            result->AddReferencedObject(edges[i]->getB());
        }
        else
            result->AddReferencedObject(edges[i]->getA());
    }
    chain->FUN_00c905b0();
    return result;
}

namespace fnv_anon_00e5ba30 {}
using namespace fnv_anon_00e5ba30;
enum S5ba30_Result
{
    S5ba30_SUCCESS = 0,
    S5ba30_FAILURE = 1
};

inline hkMemoryRouter& GetAudioHolder()
{
    return *hkMemoryRouter_getInstance();
}

inline hkMemoryAllocator& GetAudioHolderAllocator(hkMemoryRouter& holder)
{
    return *reinterpret_cast<hkMemoryAllocator*>(holder.m_heap);
}

struct S5ba30_HeapAllocator
{
    hkMemoryAllocator& get(const void*)
    {
        return GetAudioHolderAllocator(GetAudioHolder());
    }
};

void __cdecl ResizeAudioStream(hkMemoryAllocator& alloc, void* arr, int sizeElem);

struct S5ba30_IsPod
{
};
struct S5ba30_ArrayUtil
{
    template <typename T> static __forceinline void construct(T* t, int n, S5ba30_IsPod)
    {}
    template <typename T> static __forceinline void destruct(T* t, int n, S5ba30_IsPod)
    {}
    template <typename T> static __forceinline void constructWithCopy(T* t, int n, const T& tcopy, S5ba30_IsPod)
    {
        for (int i = 0; i < n; ++i)
        {
            t[i] = tcopy;
        }
    }
};

template <typename T>
struct S5ba30_ArrayOps
{ // local form of hkArrayBase: 0x00e5ba30 needs the local helper inline/out-of-line split; the shared form changes extent from 2363 to 1869 bytes.
    enum
    {
        CAPACITY_MASK = 0x3fffffff,
        DONT_DEALLOCATE_FLAG = 0x80000000
    };
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    __forceinline int getCapacity() const
    {
        return m_iCapacityState & CAPACITY_MASK;
    }
    __forceinline T& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline const T& operator[](int i) const
    {
        return m_data[i];
    }
    __forceinline T& back()
    {
        return m_data[m_iElementCount - 1];
    }
    __forceinline void clear()
    {
        S5ba30_ArrayUtil::destruct(m_data, m_iElementCount, S5ba30_IsPod());
        m_iElementCount = 0;
    }
    __forceinline void popBack(int numToRemove = 1)
    {
        S5ba30_ArrayUtil::destruct(m_data + m_iElementCount - numToRemove, numToRemove, S5ba30_IsPod());
        m_iElementCount -= numToRemove;
    }
    __forceinline void GrowArrayCapacity(hkMemoryAllocator& alloc, int n)
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayUtil__reserve(alloc, this, newSize, sizeof(T));
        }
    }
    __forceinline void _setSize(hkMemoryAllocator& alloc, int n)
    {
        GrowArrayCapacity(alloc, n);
        S5ba30_ArrayUtil::destruct(m_data + n, m_iElementCount - n, S5ba30_IsPod());
        S5ba30_ArrayUtil::construct(m_data + m_iElementCount, n - m_iElementCount, S5ba30_IsPod());
        m_iElementCount = n;
    }
    __forceinline void _pushBack(hkMemoryAllocator& alloc, const T& t)
    {
        if (m_iElementCount == getCapacity())
        {
            ResizeAudioStream(alloc, this, sizeof(T));
        }
        S5ba30_ArrayUtil::constructWithCopy(m_data + m_iElementCount, 1, t, S5ba30_IsPod());
        m_iElementCount++;
    }
    __forceinline void _clearAndDeallocate(hkMemoryAllocator& alloc)
    {
        clear();
        if ((m_iCapacityState & DONT_DEALLOCATE_FLAG) == 0)
        {
            alloc.bufFree(m_data, getCapacity() * (int)sizeof(T));
        }
        m_data = 0;
        m_iCapacityState = DONT_DEALLOCATE_FLAG;
    }
};

template <typename T> struct S5ba30_ArrayBase : public S5ba30_ArrayOps<T>
{
    __forceinline S5ba30_ArrayBase()
    {
        this->m_data = 0;
        this->m_iElementCount = 0;
        this->m_iCapacityState = this->DONT_DEALLOCATE_FLAG;
    }
    __forceinline S5ba30_ArrayBase(T* ptr, int size, int capacity)
    {
        this->m_data = ptr;
        this->m_iElementCount = size;
        this->m_iCapacityState = capacity | this->DONT_DEALLOCATE_FLAG;
    }
    __forceinline ~S5ba30_ArrayBase()
    {}
};

template <typename T> struct S5ba30_Array : public S5ba30_ArrayBase<T>
{
    __forceinline S5ba30_Array()
    {}
    __forceinline S5ba30_Array(T* ptr, int size, int capacity) : S5ba30_ArrayBase<T>(ptr, size, capacity)
    {}
    __forceinline ~S5ba30_Array()
    {
        ClearAndRelease();
    }
    __forceinline void ClearAndRelease()
    {
        this->_clearAndDeallocate(S5ba30_HeapAllocator().get(this));
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        this->_setSize(S5ba30_HeapAllocator().get(this), n);
    }
    __forceinline void AddBack(const T& t)
    {
        this->_pushBack(S5ba30_HeapAllocator().get(this), t);
    }
};

template <typename T, unsigned N> struct S5ba30_InplaceArray : public S5ba30_Array<T>
{
    explicit __forceinline S5ba30_InplaceArray(int size = 0) : S5ba30_Array<T>(m_kStorage, size, N)
    {}
    __forceinline ~S5ba30_InplaceArray()
    {}
    T m_kStorage[N];
};

// hkInplaceArray<int,N> without a ctor: construction is the explicit init() loop.
template <unsigned N> struct S5ba30_InplaceList : public S5ba30_ArrayOps<int>
{
    int m_kStorage[N];
    __forceinline void init()
    {
        m_data = m_kStorage;
        m_iElementCount = 0;
        m_iCapacityState = N | 0x80000000;
    }
    __forceinline ~S5ba30_InplaceList()
    {
        this->_clearAndDeallocate(S5ba30_HeapAllocator().get(this));
    }
    __forceinline void AddBack(const int& t)
    {
        this->_pushBack(S5ba30_HeapAllocator().get(this), t);
    }
};

class S5ba30_Dummy;

class S5ba30_Bool
{
  public:
    inline S5ba30_Bool()
    {}
    inline S5ba30_Bool(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
    inline operator bool() const
    {
        return m_cBooleanValue != 0;
    }
    char m_cBooleanValue;
};

struct S5ba30_MapBase
{
    typedef S5ba30_Dummy* Iterator;
    Pair* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    S5ba30_MapBase() : m_kPrimitiveElement(0), m_iCapacityFlags(0), m_iPairCount(-1)
    {}
    ~S5ba30_MapBase();
    unsigned long getValue(Iterator it) const
    {
        int i = (int)(unsigned long)it;
        return m_kPrimitiveElement[i].b;
    }
    S5ba30_Bool isValid(Iterator it) const
    {
        int i = (int)(unsigned long)it;
        return i <= m_iPairCount;
    }
    Iterator FindSlot(unsigned long key) const;
    int hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(hkMemoryAllocator& a, unsigned long key, unsigned long val);
    void ProcessArgument(hkMemoryAllocator& a);
    void EnsureCapacity(hkMemoryAllocator& a, int numElements);
    __forceinline Iterator findKey(unsigned long key) const
    {
        return FindSlot(key);
    }
};

struct S5ba30_Map : public S5ba30_MapBase
{
    S5ba30_Map(int nelem = 0)
    {
        reserve(nelem);
    }
    ~S5ba30_Map()
    {
        ProcessArgument(S5ba30_HeapAllocator().get(this));
    }
    __forceinline int insert(unsigned long key, unsigned long val)
    {
        return hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(S5ba30_HeapAllocator().get(this), key, val);
    }
    __forceinline void reserve(int numElements)
    {
        EnsureCapacity(S5ba30_HeapAllocator().get(this), numElements);
    }
};

struct S5ba30_Entity;

template <typename K, typename V> struct S5ba30_PointerMap
{
    typedef S5ba30_MapBase::Iterator Iterator;
    S5ba30_PointerMap()
    {}
    __forceinline int insert(K key, V val)
    {
        return m_map.insert((unsigned long)key, (unsigned long)val);
    }
    __forceinline Iterator findKey(K key) const
    {
        return m_map.findKey((unsigned long)key);
    }
    V getValue(Iterator i) const
    {
        return (V)m_map.getValue(i);
    }
    S5ba30_Bool isValid(Iterator i) const
    {
        return m_map.isValid(i);
    }
    S5ba30_Map m_map;
};

struct S5ba30_ConstraintInstance
{
    void* m_vtbl;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_pOwnerObject;
    void* m_data;
    void* m_pConstraintModifier;
    S5ba30_Entity* m_kActorEntries[2];
    S5ba30_Entity* getEntityA() const
    {
        return m_kActorEntries[0];
    }
    S5ba30_Entity* getEntityB() const
    {
        return m_kActorEntries[1];
    }
};

void __cdecl CollectConnectedNodesAndEdges(const S5ba30_Array<S5ba30_ConstraintInstance*>& allConstraints,
                                           const S5ba30_Entity* entity, S5ba30_Array<S5ba30_Entity*>& entitiesOut,
                                           S5ba30_Array<S5ba30_ConstraintInstance*>& constraintsOut);

struct S5ba30_ErrStream
{
    void* m_vtbl;
    int m_usMemSizeAndFlags;
    void* m_pStreamWriter;
    S5ba30_ErrStream(void* buf, int bufSize);
    ~S5ba30_ErrStream();
    S5ba30_ErrStream& ProcessAndReturnValue_00cc01c0(const char* str);
    __forceinline S5ba30_ErrStream& operator<<(const char* str)
    {
        return ProcessAndReturnValue_00cc01c0(str);
    }
};

struct S5ba30_Error
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int message(int m, int id, const char* description, const char* file, int line);
    static inline S5ba30_Error& GetMonitorStream();
};
inline S5ba30_Error& S5ba30_Error::GetMonitorStream()
{
    return *reinterpret_cast<S5ba30_Error*>(DAT_01268360);
}

namespace fnv_anon_00e5ba30 {
struct S5ba30_EntityInfo
{
    int m_iFirstValue;
    int m_iSecondValue;
    S5ba30_ConstraintInstance* m_pHavokConstraint;
    int m_fClosestPointDistanceSquared;
};
}

// @fnv 0x00e5ba30
// src: XBOX_PDB 0x00e5ba30
S5ba30_Result __cdecl hkpConstraintChainUtil_findConstraintLinkBetweenEntities(const S5ba30_Array<S5ba30_ConstraintInstance*>& allConstraints,
                                   S5ba30_Entity* entityA, S5ba30_Entity* entityB,
                                   S5ba30_Array<S5ba30_Entity*>& entitiesOut,
                                   S5ba30_Array<S5ba30_ConstraintInstance*>& constraintsOut)
{
    if (entityA == entityB)
    {
        do
        {
            char assertBuf[512];
            S5ba30_ErrStream ostr(assertBuf, sizeof(assertBuf));
            ostr << "Specify two different end bodies.";
            S5ba30_Error::GetMonitorStream().message(1, 0xabba3bb3, assertBuf,
                                                     ".\\Constraint\\Chain\\hkpConstraintChainUtil.cpp", 250);
        } while (false);
        return S5ba30_FAILURE;
    }

    S5ba30_Array<S5ba30_Entity*> entities;
    S5ba30_PointerMap<S5ba30_Entity*, int> entityToIndex;

    for (int c = 0; c < allConstraints.GetLogicalSize(); c++)
    {
        S5ba30_ConstraintInstance* instance = allConstraints[c];
        S5ba30_MapBase::Iterator itA = entityToIndex.findKey(instance->getEntityA());
        if (!entityToIndex.isValid(itA))
        {
            entityToIndex.insert(instance->getEntityA(), entities.GetLogicalSize());
            entities.AddBack(instance->getEntityA());
        }
        S5ba30_MapBase::Iterator itB = entityToIndex.findKey(instance->getEntityB());
        if (!entityToIndex.isValid(itB))
        {
            entityToIndex.insert(instance->getEntityB(), entities.GetLogicalSize());
            entities.AddBack(instance->getEntityB());
        }
    }

    S5ba30_InplaceArray<S5ba30_EntityInfo, 32> infos(0);
    infos.SetSizeAndGrow(entities.GetLogicalSize());
    for (int i = 0; i < infos.GetLogicalSize(); i++)
    {
        infos[i].m_iFirstValue = -1;
    }

    S5ba30_InplaceList<32> toVisit[2];
    int remaining = 1;
    S5ba30_InplaceList<32>* list = toVisit;
    do
    {
        list->init();
        ++list;
    } while (--remaining >= 0);
    int lastVisited[2] = {-1, -1};

    int idxA = entityToIndex.getValue(entityToIndex.findKey(entityA));
    int idxB = entityToIndex.getValue(entityToIndex.findKey(entityB));

    infos[idxA].m_iFirstValue = 0;
    infos[idxA].m_iSecondValue = -1;
    infos[idxA].m_pHavokConstraint = 0;
    infos[idxA].m_fClosestPointDistanceSquared = 0;
    infos[idxB].m_iFirstValue = 1;
    infos[idxB].m_iSecondValue = -1;
    infos[idxB].m_pHavokConstraint = 0;
    infos[idxB].m_fClosestPointDistanceSquared = 0;

    toVisit[0].AddBack(idxA);
    toVisit[1].AddBack(idxB);

    S5ba30_ConstraintInstance* connectingConstraint = 0;
    int endIdx[2];
    int length[2];
    int side = 0;
    S5ba30_InplaceArray<S5ba30_Entity*, 32> adjEntities(0);
    S5ba30_InplaceArray<S5ba30_ConstraintInstance*, 32> adjConstraints(0);
    int done = 0;

    for (; !done; side = 1 - side)
    {
        int otherSide = 1 - side;
        lastVisited[side]++;
        int visitIdx = lastVisited[side];
        if (visitIdx >= toVisit[side].GetLogicalSize())
        {
            return S5ba30_FAILURE;
        }
        int idx = toVisit[side][visitIdx];
        S5ba30_Entity* entity = entities[idx];

        adjEntities.clear();
        adjConstraints.clear();
        CollectConnectedNodesAndEdges(allConstraints, entity, adjEntities, adjConstraints);

        for (int a = 0; a < adjEntities.GetLogicalSize() && !done; a++)
        {
            int adjIdx = entityToIndex.getValue(entityToIndex.findKey(adjEntities[a]));
            int adjSide = infos[adjIdx].m_iFirstValue;
            if (adjSide == side)
            {
                continue;
            }
            if (adjSide == otherSide)
            {
                done = 1;
                length[side] = infos[idx].m_fClosestPointDistanceSquared + 1;
                length[otherSide] = infos[adjIdx].m_fClosestPointDistanceSquared + 1;
                endIdx[side] = idx;
                endIdx[otherSide] = adjIdx;
                connectingConstraint = adjConstraints[a];
                break;
            }
            toVisit[side].AddBack(adjIdx);
            infos[adjIdx].m_iFirstValue = side;
            infos[adjIdx].m_iSecondValue = toVisit[side][lastVisited[side]];
            infos[adjIdx].m_pHavokConstraint = adjConstraints[a];
            infos[adjIdx].m_fClosestPointDistanceSquared = infos[idx].m_fClosestPointDistanceSquared + 1;
        }
    }

    entitiesOut.clear();
    entitiesOut.SetSizeAndGrow(length[0] + length[1]);
    constraintsOut.clear();
    constraintsOut.SetSizeAndGrow(length[0] + length[1]);

    int idx = endIdx[0];
    for (int e = length[0] - 1; e > 0; e--)
    {
        entitiesOut[e] = entities[idx];
        constraintsOut[e - 1] = infos[idx].m_pHavokConstraint;
        idx = infos[idx].m_iSecondValue;
    }
    entitiesOut[0] = entities[idx];
    constraintsOut[length[0] - 1] = connectingConstraint;

    idx = endIdx[1];
    int base = length[0];
    for (int e = 0; e < length[1]; e++)
    {
        entitiesOut[base + e] = entities[idx];
        constraintsOut[base + e] = infos[idx].m_pHavokConstraint;
        idx = infos[idx].m_iSecondValue;
    }
    constraintsOut.popBack(1);
    return S5ba30_SUCCESS;
}


template <>
void hkArrayBase<S_00e5c370_Elem>::_spliceInto(hkMemoryAllocator& alloc, int index, int numdel, const S_00e5c370_Elem* p, int numtoinsert)
{
        int newsize = m_iElementCount + numtoinsert - numdel;
        int numtomove = m_iElementCount - index - numdel;
        if (newsize > getCapacity())
            S_00e5c370_ArrayBase_GrowArrayCapacity(*this, alloc, newsize);
        hkMemUtil_memMove(m_data + index + numtoinsert, m_data + index + numdel, numtomove * sizeof(S_00e5c370_Elem));
        S_00e5c370_Elem* dst = m_data + index;
        for (int i = 0; i < numtoinsert; i++)
            new (dst + i) S_00e5c370_Elem(p[i]);
        m_iElementCount = newsize;
    }
