#include "../../../../../../include/hkArray.h"

// src/havok/common/serialize/packfile/binary/hkbinarypackfilewriter.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/packfile/binary/hkbinarypackfilewriter.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/Pair.h"


struct GlobalObjectO2_00d472a0
{
    int x;
};
extern GlobalObjectO2_00d472a0 g_0126ca58;
extern GlobalObjectO2_00d472a0 g_0126ca88;
extern GlobalObjectO2_00d472a0 g_0126cab8;
extern GlobalObjectO2_00d472a0 g_0126cae8;
extern int DAT_011b7a7c;
extern int DAT_011b7aec;
extern void* DAT_010d65bc;
struct FUN_00dbdf30_s
{
    void hkPackfileWriter_setSectionForClass(GlobalObjectO2_00d472a0*, int);
};
struct FUN_00dbc670
{
    void* m_vft;
    void hkPackfileWriter_addSection(int);
    FUN_00dbc670();
};
extern void FUN_00dbe4d0();
// Calls FUN_00dbe4d0, sets m_vft, then calls FUN_00dbdef0 and FUN_00dbdf30 on four global objects with DAT_011b7aec.
// @fnv 0x00dbc670
FUN_00dbc670::FUN_00dbc670()
{
    FUN_00dbe4d0();
    m_vft = &DAT_010d65bc;
    hkPackfileWriter_addSection(DAT_011b7a7c);
    ((FUN_00dbdf30_s*)this)->hkPackfileWriter_setSectionForClass(&g_0126cae8, DAT_011b7aec);
    ((FUN_00dbdf30_s*)this)->hkPackfileWriter_setSectionForClass(&g_0126ca58, DAT_011b7aec);
    ((FUN_00dbdf30_s*)this)->hkPackfileWriter_setSectionForClass(&g_0126cab8, DAT_011b7aec);
    ((FUN_00dbdf30_s*)this)->hkPackfileWriter_setSectionForClass(&g_0126ca88, DAT_011b7aec);
}

// @fnv 0x00dbd720
// src: GUESS 0x00dbd720 (confidence: low)
unsigned int __cdecl Object_ComputeValue_00dbd720(unsigned int arg)
{
    return *reinterpret_cast<unsigned int*>(arg + 4) * 3 * 16;
}

struct FUN_00dbc6e0_s
{
    void* m_vft;
    void FUN_00dbdf60();
    void SetVirtualTableAndProcessState_00dbc6e0();
};
// @fnv 0x00dbc6e0
// src: GUESS 0x00dbc6e0 (confidence: low)
void FUN_00dbc6e0_s::SetVirtualTableAndProcessState_00dbc6e0()
{
    m_vft = &DAT_010d65bc;
    FUN_00dbdf60();
}

struct CallbackTarget
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void Send(void* value);
};
struct FUN_00dbd730_class
{
    int unk00;
    int unk04;
    CallbackTarget* target;
    void* ForwardToTarget(void* value);
};
// @fnv 0x00dbd730
void* FUN_00dbd730_class::ForwardToTarget(void* value)
{
    target->Send(value);
    return value;
}

struct S_00dbd770_Inner
{
    virtual void unk0();
    virtual void unk4();
    virtual void unk8();
    virtual void unkC();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18(void* p);
};

struct S_00dbd770
{
    int unk0;
    int unk4;
    S_00dbd770_Inner* unk8;
    void* ForwardToInner(void* p);
};

// @fnv 0x00dbd770
void* S_00dbd770::ForwardToInner(void* apArg)
{
    unk8->unk18(apArg);
    return apArg;
}

struct Inner
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual int f8();
};
struct FUN_00dbd7d0_Class
{
    int unk00;
    int unk04;
    Inner* object;
    int offset;
    int GetAdjustedValue();
};
// @fnv 0x00dbd7d0
int FUN_00dbd7d0_Class::GetAdjustedValue()
{
    return object->f8() - offset;
}

struct Triple
{
    int x;
    int y;
    int z;
    Triple() : x(0), y(0), z(0x80000000)
    {}
};
struct FUN_00dbd870
{
    Triple first;
    Triple second;
    Triple third;
    Triple fourth;
    int trailing;
    FUN_00dbd870();
};
// Default-constructs four Triple members and sets trailing to 0.
// @fnv 0x00dbd870
FUN_00dbd870::FUN_00dbd870() : trailing(0)
{}

struct FUN_00dbc6f0_cls_callee
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void Write(void* apNode, int aiValue);
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual int Count();
};

struct FUN_00dbc6f0_cls_store
{
    int unk00;
    void Store(void* apNode, int aiDiff);
};

struct FUN_00dbc6f0_cls_owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    FUN_00dbc6f0_cls_callee* m_pCallee;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    FUN_00dbc6f0_cls_store m_store;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    unsigned char m_byReverse;
};

struct FUN_00dbc6f0_cls_source
{
    int Lookup(int aiFlag);
    void* Resolve();
};

struct FUN_00dbc6f0_cls_key
{
    int m_iValue;
    unsigned char m_byTag;
};

struct FUN_00dbc6f0_cls_bytes
{
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
};

union FUN_00dbc6f0_cls_word
{
    int iValue;
    FUN_00dbc6f0_cls_bytes bytes;
};

int __cdecl hkString_strLen(void* apNode);

typedef void(__thiscall* S_WriteFn)(FUN_00dbc6f0_cls_callee*, void*, int);

static inline void S_Swap(unsigned char& a, unsigned char& b)
{
    unsigned char t = a;
    a = b;
    b = t;
}

static inline int S_Rev(int v)
{
    unsigned char* p = (unsigned char*)&v;
    S_Swap(p[0], p[3]);
    S_Swap(p[1], p[2]);
    return v;
}

// @fnv 0x00dbc6f0
void __stdcall WriteNodeDiff(FUN_00dbc6f0_cls_owner* apOwner, FUN_00dbc6f0_cls_source* apSource, int aiDiff)
{
    int x = apSource->Lookup(0);
    if (apOwner->m_byReverse != 0)
        x = S_Rev(x);
    FUN_00dbc6f0_cls_key key;
    key.m_iValue = x;
    key.m_byTag = 9;
    apOwner->m_pCallee->Write(&key, 5);
    void* pNode = apSource->Resolve();
    int iDiff = apOwner->m_pCallee->Count() - aiDiff;
    apOwner->m_store.Store(pNode, iDiff);
    void** pVtable = *(void***)apOwner->m_pCallee;
    ((S_WriteFn)pVtable[4])(apOwner->m_pCallee, pNode, hkString_strLen(pNode) + 1);
}

struct Target
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
};

struct FUN_00dbd760_cls
{
    int unk00;
    int unk04;
    Target* m_08;
    void hkSubStreamWriter_flush();
};

// @fnv 0x00dbd760
// src: XBOX_PDB 0x00dbd760
void FUN_00dbd760_cls::hkSubStreamWriter_flush()
{
    m_08->unk14();
}

struct S_00dbd790_Obj
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7(int a, int b);
};
struct S_00dbd790_Class
{
    int unk00;
    int unk04;
    S_00dbd790_Obj* object;
    int offset;
    void DispatchToObject(int a, int b);
};
// Calls the object's f7 virtual method, passing a plus offset when b is zero and a otherwise, along with b.
// @fnv 0x00dbd790
void S_00dbd790_Class::DispatchToObject(int aiValue, int b)
{
    object->f7(b == 0 ? aiValue + offset : aiValue, b);
}

struct FUN_00dbd820_pair
{
    unsigned int first;
    unsigned int second;
};

struct FUN_00dbd820_cls
{
    FUN_00dbd820_pair* m_data;
    int m_iElementCount;
    unsigned int m_flags;
    void AppendPair(FUN_00dbd820_pair p);
};

extern void* hkMemoryRouter_getInstance();
extern void __cdecl ResizeAudioStream(void* allocator, void* vec, unsigned int elemSize);

// @fnv 0x00dbd820
void FUN_00dbd820_cls::AppendPair(FUN_00dbd820_pair aPair)
{
    FUN_00dbd820_pair entry;
    entry.first = aPair.first;
    entry.second = *(volatile unsigned int*)&aPair.second;
    hkMemoryRouter* holder = (hkMemoryRouter*)hkMemoryRouter_getInstance();
    if (m_iElementCount == (int)(m_flags & 0x3fffffffu))
    {
        ResizeAudioStream(holder->m_heap, this, 8);
    }
    int idx = m_iElementCount;
    FUN_00dbd820_pair* slot = m_data + idx;
    slot->first = entry.first;
    slot->second = entry.second;
    m_iElementCount++;
}

struct S_00dbd8a0_Sub
{
    char unk0;
    char unk1;
};

struct S_00dbd8a0_Arg
{
    int unk00;
    S_00dbd8a0_Sub unk04;
};

struct S_00dbd8a0_Byte
{
    char c;
    S_00dbd8a0_Byte(char v) : c(v)
    {}
};

struct S_00dbd8a0_Mem20
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00dbd8a0_Mem20(S_00dbd8a0_Sub* p);
};

struct S_00dbd8a0_Mem30
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00dbd8a0_Mem30(S_00dbd8a0_Byte b);
};

extern char DAT_011b7b89;

struct FUN_00dbd8a0
{
    S_00dbd8a0_Arg* unk00;
    Triple first;
    Triple second;
    int unk1c;
    S_00dbd8a0_Mem20 unk20;
    S_00dbd8a0_Mem30 unk30;
    Triple third;
    bool unk4c;
    FUN_00dbd8a0(S_00dbd8a0_Arg* p);
};

// Initialises members from p: stores p, builds unk20 from p->unk04 and unk30 from byte 0, and sets unk4c by comparing DAT_011b7b89 with p->unk04.unk1.
// @fnv 0x00dbd8a0
FUN_00dbd8a0::FUN_00dbd8a0(S_00dbd8a0_Arg* apArg) : unk00(apArg), unk20(&apArg->unk04), unk30(S_00dbd8a0_Byte(0))
{
    unk4c = DAT_011b7b89 != apArg->unk04.unk1;
}

class BDBD910Allocator
{
  public:
    virtual void VFunc00();
    virtual void VFunc04();
    virtual void VFunc08();
    virtual void VFunc0C();
    virtual void ReturnMemory(void* pvData, int iNumBytes);
};


hkMemoryRouter* BDBD910GetRouter();

template <class T> __forceinline void BDBD910Destruct(T* pkData, int iCount)
{
    for (int i = 0; i < iCount; i++)
        pkData[i].~T();
}

template <class T, class A> __forceinline hkArray<T, A>::~hkArray()
{
        BDBD910Allocator& kAlloc = (BDBD910Allocator&)BDBD910GetRouter()->heap();
        BDBD910Destruct(m_data, m_iElementCount);
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    
}

struct BDBD910Entry48
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
};

struct BDBD910Entry8
{
    int unk00;
    int unk04;
};

struct BDBD910Entry52
{
    ~BDBD910Entry52();

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
};

class BDBD910Member20
{
  public:
    ~BDBD910Member20();

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

class BDBD910Member30
{
  public:
    ~BDBD910Member30();

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

class FUN_00dbd910_cls
{
  public:
    ~FUN_00dbd910_cls() throw();

    int unk00;
    hkArray<BDBD910Entry48> m_kArray04;
    hkArray<BDBD910Entry8> m_kArray10;
    int unk1C;
    BDBD910Member20 m_kMember20;
    BDBD910Member30 m_kMember30;
    hkArray<BDBD910Entry52> m_kArray40;
};

// Destructor for the container class; the member arrays and members are destroyed automatically by their own destructors.
// @fnv 0x00dbd910
FUN_00dbd910_cls::~FUN_00dbd910_cls() throw()
{}

namespace fnv_00dbd620 {
struct S_00dbd620_Arg;

struct S_00dbd620_Poly
{
    virtual void* v0();
    virtual void* v1();
    virtual void* v2();
    virtual void* v3();
    virtual void* v4();
    virtual void* v5();
    virtual void* v6();
    virtual void v7(void* a, unsigned int b);
    virtual void* v8();
};

struct S_00dbd620_Writer
{
    void* vtbl;
    char unk04;
    char unk05;
    short unk06;
    S_00dbd620_Poly* unk08;
    void* unk0c;
};

struct S_00dbd620_Obj
{
    void* unk00;
    int unk04;
    void* unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    void* unk1c;
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
    char unk4c;
    S_00dbd620_Obj(S_00dbd620_Arg* p);
    void FUN_00dbd8a0(S_00dbd620_Arg* p);
};

struct S_00dbd620_Dtor
{
    int unk00;
    ~S_00dbd620_Dtor();
};

extern int DAT_010d65ec;
extern int DAT_0102e388;

unsigned int __cdecl Object_ComputeValue_00dbd720(unsigned int arg);

static __declspec(noinline) void S_00dbd620_Helper(void* a, void* b, void* c, void* d)
{
    int n = *(int*)b;
    for (int i = 0; i < n; i++)
        ((S_00dbd620_Poly*)a)->v3();
    *(int*)c += n + *(int*)d;
}

struct S_00dbd620_Owner
{
    void hkBinaryPackfileWriter_fillSectionTags(void* p);
    void hkBinaryPackfileWriter_writeAllObjects(void* p);
    void WriteSectionsAndFixups(void* p, void* q);
    void* ProcessPoly(S_00dbd620_Poly* a1, S_00dbd620_Arg* a2);
};

// @fnv 0x00dbd620
void* S_00dbd620_Owner::ProcessPoly(S_00dbd620_Poly* pPoly, S_00dbd620_Arg* a2)
{
    S_00dbd620_Obj obj(a2);
    S_00dbd620_Writer writer;

    writer.unk06 = 1;
    writer.vtbl = &DAT_010d65ec;
    writer.unk08 = pPoly;
    writer.unk0c = writer.unk08->v8();

    obj.unk1c = &writer;
    hkBinaryPackfileWriter_fillSectionTags(&obj);

    S_00dbd620_Helper((void*)&obj.unk20, (void*)a2, obj.unk1c, obj.unk08);

    void* pSaved = ((S_00dbd620_Poly*)&writer)->v8();

    unsigned int one = 1;
    ((S_00dbd620_Poly*)&writer)->v7((void*)Object_ComputeValue_00dbd720((unsigned int)&obj.unk04), one);

    hkBinaryPackfileWriter_writeAllObjects(&obj);

    void* pSaved2 = ((S_00dbd620_Poly*)&writer)->v8();

    WriteSectionsAndFixups(&obj, pSaved);

    ((S_00dbd620_Poly*)&writer)->v7(pSaved2, 0);

    ((S_00dbd620_Poly*)&writer)->v5();

    writer.vtbl = &DAT_0102e388;

    ((S_00dbd620_Dtor*)&obj)->~S_00dbd620_Dtor();

    return 0;
}
}  // namespace fnv_00dbd620

// Havok patch manager: rebuild patch dependency order (topological sort).
typedef unsigned __int64 S_00db8670_Uint64;
typedef unsigned long S_00db8670_Ulong;

struct S_00db8670_Heap
{
    virtual void unkVfn0();
    virtual void* AllocateMemoryBlock(int n);
    virtual void unkVfn2();
    virtual void unkVfn3();
    virtual void ReturnMemory(void* p, int numBytes);
};


extern void* __cdecl hkMemoryRouter_getInstance();
__forceinline hkMemoryRouter& S_GetRouter() throw()
{
    return *(hkMemoryRouter*)hkMemoryRouter_getInstance();
}
void __cdecl hkArrayUtil__reserve(S_00db8670_Heap& alloc, void* array, int reqCapacity, int sizeElem) throw();

template <typename T> __forceinline void S_ConstructWithCopy(T* p, int n, const T& fill) throw()
{
    for (int i = 0; i < n; ++i)
        p[i] = fill;
}

template <typename T> struct S_00db8670_ArrayLocalForm
{ // local form of hkArray: 0x00db8670 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    S_00db8670_ArrayLocalForm() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    ~S_00db8670_ArrayLocalForm() throw()
    {
        _clearAndDeallocate((S_00db8670_Heap&)S_GetRouter().heap());
    }

    int GetLogicalSize() const throw()
    {
        return m_iElementCount;
    }
    int getCapacity() const throw()
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T& operator[](int i) throw()
    {
        return m_data[i];
    }
    const T& operator[](int i) const throw()
    {
        return m_data[i];
    }

    void _clearAndDeallocate(S_00db8670_Heap& alloc) throw()
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline void GrowArrayCapacity(S_00db8670_Heap& alloc, int n) throw()
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayUtil__reserve(alloc, this, newSize, sizeof(T));
        }
    }
    __forceinline void _setSize(S_00db8670_Heap& alloc, int n) throw()
    {
        GrowArrayCapacity(alloc, n);
        m_iElementCount = n;
    }
    __forceinline void _setSize(S_00db8670_Heap& alloc, int n, const T& fill) throw()
    {
        GrowArrayCapacity(alloc, n);
        S_ConstructWithCopy(m_data + m_iElementCount, n - m_iElementCount, fill);
        m_iElementCount = n;
    }
    void SetSizeAndGrow(int n) throw()
    {
        _setSize((S_00db8670_Heap&)S_GetRouter().heap(), n);
    }
    void SetSizeAndGrow(int n, const T& fill) throw()
    {
        _setSize((S_00db8670_Heap&)S_GetRouter().heap(), n, fill);
    }

    // copy assignment (out of line)
    void SwapThreeInts(const S_00db8670_ArrayLocalForm& other) throw();
};

struct S_00db8670_MapBase64
{
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    S_00db8670_MapBase64() throw() : m_kPrimitiveElement(0), m_iCapacityFlags(0), m_iPairCount(-1)
    {}
    ~S_00db8670_MapBase64() throw();

    void ResizeToFit(S_00db8670_Heap& alloc, int numElements) throw();
    void hkMapBase_unsigned_int64_unsigned_int64_hkMapOperations_unsigned_int64_clearAndDeallocate(S_00db8670_Heap& alloc) throw();
    void ProcessEntries_00cb1e00() throw();
    int hkMapBase_unsigned_int64_unsigned_int64_struct_hkMapOperations_unsigned_int64_findKey(S_00db8670_Uint64 key) const throw();
    void InsertKeyValue(S_00db8670_Heap& alloc, S_00db8670_Uint64 key, S_00db8670_Uint64 val) throw();
    S_00db8670_Uint64 hkMapBase_unsigned_int64_unsigned_int64_struct_hkMapOperations_unsigned_int64_getWithDefault(S_00db8670_Uint64 key, S_00db8670_Uint64 def) const throw();
};

struct S_00db8670_Map64 : S_00db8670_MapBase64
{
    S_00db8670_Map64() throw()
    {
        ResizeToFit((S_00db8670_Heap&)S_GetRouter().heap(), 0);
    }
    ~S_00db8670_Map64() throw()
    {
        hkMapBase_unsigned_int64_unsigned_int64_hkMapOperations_unsigned_int64_clearAndDeallocate((S_00db8670_Heap&)S_GetRouter().heap());
    }

    void clear() throw()
    {
        ProcessEntries_00cb1e00();
    }
    int hasKey(S_00db8670_Uint64 key) const throw()
    {
        return hkMapBase_unsigned_int64_unsigned_int64_struct_hkMapOperations_unsigned_int64_findKey(key) <= m_iPairCount;
    }
    void insert(S_00db8670_Uint64 key, const int& val) throw()
    {
        hkMemoryRouter& router = S_GetRouter();
        InsertKeyValue((S_00db8670_Heap&)router.heap(), key, val);
    }
    S_00db8670_Uint64 FindValueForKey(S_00db8670_Uint64 key, S_00db8670_Uint64 def) const throw()
    {
        return hkMapBase_unsigned_int64_unsigned_int64_struct_hkMapOperations_unsigned_int64_getWithDefault(key, def);
    }
};

struct S_00db8670_MapBaseUlong
{
    Pair* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    S_00db8670_MapBaseUlong() throw() : m_kPrimitiveElement(0), m_iCapacityFlags(0), m_iPairCount(-1)
    {}
    ~S_00db8670_MapBaseUlong() throw();

    void EnsureCapacity(S_00db8670_Heap& alloc, int numElements) throw();
    S_00db8670_Ulong LookupHashEntry(S_00db8670_Ulong key, S_00db8670_Ulong def) const throw();
    void hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(S_00db8670_Heap& alloc, S_00db8670_Ulong key, S_00db8670_Ulong value) throw();
    void ProcessArgument(S_00db8670_Heap& alloc) throw();

    int GetFirstIterator() const throw()
    {
        int i;
        for (i = 0; i <= m_iPairCount; i++)
        {
            if (m_kPrimitiveElement[i].a != S_00db8670_Ulong(-1))
            {
                break;
            }
        }
        return i;
    }
    int getNext(int it) const throw()
    {
        int i;
        for (i = it + 1; i <= m_iPairCount; i++)
        {
            if (m_kPrimitiveElement[i].a != S_00db8670_Ulong(-1))
            {
                break;
            }
        }
        return i;
    }
    int isValid(int it) const throw()
    {
        return it <= m_iPairCount;
    }
    S_00db8670_Ulong GetIteratorKey(int it) const throw()
    {
        return m_kPrimitiveElement[it].a;
    }
};

struct S_00db8670_MapUlong : S_00db8670_MapBaseUlong
{
    S_00db8670_MapUlong() throw()
    {
        EnsureCapacity((S_00db8670_Heap&)S_GetRouter().heap(), 0);
    }
    ~S_00db8670_MapUlong() throw()
    {
        ProcessArgument((S_00db8670_Heap&)S_GetRouter().heap());
    }
};

struct S_00db8670_ChainValue
{
    int value;
    int next;
};

struct S_00db8670_MultiMap64
{
    S_00db8670_ArrayLocalForm<S_00db8670_ChainValue> m_kChainValues;
    S_00db8670_Map64 m_pHashFunction;
    int m_iFreeListHead;

    S_00db8670_MultiMap64() throw() : m_iFreeListHead(-1)
    {}

    int AllocateSlot() throw();
    int CallHelperWithDefaults(S_00db8670_Uint64 key) const throw();
    void Insert(S_00db8670_Uint64 key, const int& value) throw();
    int GetNextChainIndex(int i) const throw()
    {
        return m_kChainValues[i].next;
    }
    int getValue(int i) const throw()
    {
        return m_kChainValues[i].value;
    }
};

struct S_00db8670_MultiMapUlong
{
    S_00db8670_ArrayLocalForm<S_00db8670_ChainValue> m_kChainValues;
    S_00db8670_MapUlong m_pHashFunction;
    int m_iFreeListHead;

    S_00db8670_MultiMapUlong() throw() : m_iFreeListHead(-1)
    {}

    int AllocateSlot() throw();
    int LookupWithDefault(S_00db8670_Ulong key) const throw();
    void hkSerializeMultiMap_hkDataClassDict_hkDataClassDict_insert(S_00db8670_Ulong key, const int& value) throw();
    int GetNextChainIndex(int i) const throw()
    {
        return m_kChainValues[i].next;
    }
    int getValue(int i) const throw()
    {
        return m_kChainValues[i].value;
    }
};

__declspec(noinline) void S_00db8670_MultiMap64::Insert(S_00db8670_Uint64 key, const int& value) throw()
{
    int oldHead = (int)m_pHashFunction.hkMapBase_unsigned_int64_unsigned_int64_struct_hkMapOperations_unsigned_int64_getWithDefault(key, S_00db8670_Uint64(-1));
    int newHead = AllocateSlot();
    m_kChainValues[newHead].value = value;
    m_kChainValues[newHead].next = oldHead;
    m_pHashFunction.InsertKeyValue((S_00db8670_Heap&)S_GetRouter().heap(), key, newHead);
}
// src: XBOX_PDB 0x00dc9ec0
__declspec(noinline) void S_00db8670_MultiMapUlong::hkSerializeMultiMap_hkDataClassDict_hkDataClassDict_insert(S_00db8670_Ulong key, const int& value) throw()
{
    int oldHead = (int)m_pHashFunction.LookupHashEntry(key, S_00db8670_Ulong(-1));
    int newHead = AllocateSlot();
    m_kChainValues[newHead].value = value;
    m_kChainValues[newHead].next = oldHead;
    m_pHashFunction.hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert((S_00db8670_Heap&)S_GetRouter().heap(), key, newHead);
}

struct S_00db8670_StringMapOps
{
};

struct S_00db8670_StringMap
{
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
    S_00db8670_StringMapOps m_pOperations;

    S_00db8670_StringMap(S_00db8670_StringMapOps ops = S_00db8670_StringMapOps()) throw();
    ~S_00db8670_StringMap() throw();

    int GetValue(const char* key, int def) const throw();
    void hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(const char* key, int val) throw();
};

struct S_00db8670_Component
{
    int m_type;
    const void* m_patch;
};

struct S_00db8670_DependsPatch
{
    const char* m_name;
    int m_version;
};

struct S_00db8670_PatchInfo
{
    const char* m_oldName;
    const char* m_newName;
    int m_oldVersion;
    int m_newVersion;
    const S_00db8670_Component* m_component;
    int m_numComponent;
};

struct S_00db8670_UidFromClassVersion
{
    S_00db8670_Uint64 ComputeValue_00db7d60(const char* name, int version) const throw();
};

// src: GUESS 0x00db7cb0 (confidence: low)
__declspec(noinline) int __cdecl Hkversionpatchmanager_EvaluateValue_00db7cb0(const S_00db8670_PatchInfo* p) throw()
{
    if (p->m_oldVersion == -1)
    {
        if (p->m_oldName != 0 || p->m_newVersion == -1 || p->m_newName == 0)
            return 0;
    }
    else if (p->m_newVersion == -1)
    {
        if (p->m_oldName == 0 || p->m_newName != 0)
            return 0;
    }
    else if (p->m_oldName == 0)
        return 0;
    return 1;
}
int __cdecl hkString_strCmp(const char* a, const char* b) throw();
int __cdecl hkMemoryRouter_ProcessEntries_00db7e70(int from, int to, const S_00db8670_MultiMapUlong& deps, S_00db8670_MapUlong& visited) throw();
int __cdecl hkIntArray_ProcessEntries_00db83c0(int index, S_00db8670_ArrayLocalForm<int>& order, const S_00db8670_MultiMapUlong& deps, int next,
                         S_00db8670_ArrayLocalForm<int>& stack,
                         const S_00db8670_ArrayLocalForm<const S_00db8670_PatchInfo*>& patches) throw();

struct S_00db8670_PatchManager
{
    int unk00;
    int unk04;
    S_00db8670_UidFromClassVersion* m_pUidFromClassVersion;
    S_00db8670_ArrayLocalForm<const S_00db8670_PatchInfo*> m_kPatchInfos;
    S_00db8670_Map64 m_kPatchInfoIndexMap;

    int FindEntry(S_00db8670_Uint64 uid, int flag) throw();
    int hkVersionPatchManager_recomputePatchDependencies() throw();
};

// Validates patch info, builds dependency and rename maps, topologically sorts m_kPatchInfos, and rebuilds m_kPatchInfoIndexMap.
// @fnv 0x00db8670
// src: XBOX_PDB 0x00db8670
int S_00db8670_PatchManager::hkVersionPatchManager_recomputePatchDependencies() throw()
{
    S_00db8670_Map64 newClassIndexFromUid;
    S_00db8670_Map64& patchIndexFromUid = m_kPatchInfoIndexMap;
    S_00db8670_MultiMap64 patchesFromUid;
    const S_00db8670_UidFromClassVersion* uidFromClassVersion = m_pUidFromClassVersion;
    S_00db8670_MultiMapUlong patchesFromName;

    patchIndexFromUid.clear();

    {
        for (int i = 0; i < m_kPatchInfos.GetLogicalSize(); i++)
        {
            const S_00db8670_PatchInfo* p = m_kPatchInfos[i];
            if (!Hkversionpatchmanager_EvaluateValue_00db7cb0(p))
            {
                return 1;
            }
            if (p->m_oldVersion != -1)
            {
                S_00db8670_Uint64 uid = m_pUidFromClassVersion->ComputeValue_00db7d60(p->m_oldName, p->m_oldVersion);
                if (patchIndexFromUid.hasKey(uid))
                {
                    return 1;
                }
                patchIndexFromUid.insert(uid, i);
                if (p->m_newVersion == -1 || (p->m_newName && hkString_strCmp(p->m_oldName, p->m_newName)))
                {
                    patchesFromName.hkSerializeMultiMap_hkDataClassDict_hkDataClassDict_insert((S_00db8670_Ulong)p->m_oldName, i);
                }
            }
            else
            {
                S_00db8670_Uint64 uid = m_pUidFromClassVersion->ComputeValue_00db7d60(p->m_newName, p->m_newVersion);
                if (newClassIndexFromUid.hasKey(uid))
                {
                    return 1;
                }
                newClassIndexFromUid.insert(uid, i);
            }
            if (p->m_newVersion != -1)
            {
                const char* name = p->m_newName ? p->m_newName : p->m_oldName;
                S_00db8670_Uint64 uid = uidFromClassVersion->ComputeValue_00db7d60(name, p->m_newVersion);
                patchesFromUid.Insert(uid, i);
            }
        }
    }

    S_00db8670_StringMap newClassNames;
    S_00db8670_MultiMapUlong dependencies;
    S_00db8670_MultiMapUlong renames;

    for (int j = 0; j < m_kPatchInfos.GetLogicalSize(); j++)
    {
        const S_00db8670_PatchInfo* p = m_kPatchInfos[j];
        const char* name = p->m_oldName;
        int version = p->m_oldVersion;
        if (version == -1)
        {
            name = p->m_newName;
            version = p->m_newVersion;
            if (name == 0 || version == -1)
            {
                return 1;
            }
        }
        S_00db8670_Uint64 uid = uidFromClassVersion->ComputeValue_00db7d60(name, version);
        int iNewClassIndex;
        if (p->m_oldVersion == -1)
        {
            iNewClassIndex = (int)newClassIndexFromUid.FindValueForKey(uid, S_00db8670_Uint64(-1));
        }
        else
        {
            iNewClassIndex = (int)patchIndexFromUid.FindValueForKey(uid, S_00db8670_Uint64(-1));
            for (int k = patchesFromUid.CallHelperWithDefaults(uid); k != -1; k = patchesFromUid.GetNextChainIndex(k))
            {
                int value = patchesFromUid.getValue(k);
                dependencies.hkSerializeMultiMap_hkDataClassDict_hkDataClassDict_insert(iNewClassIndex, value);
            }
        }

        for (int c = 0; c < p->m_numComponent; c++)
        {
            const S_00db8670_Component& component = p->m_component[c];
            if (component.m_type == 6)
            {
                const S_00db8670_DependsPatch* dep = (const S_00db8670_DependsPatch*)component.m_patch;
                S_00db8670_Uint64 depUid = uidFromClassVersion->ComputeValue_00db7d60(dep->m_name, dep->m_version);
                int depIndex = (int)patchIndexFromUid.FindValueForKey(depUid, S_00db8670_Uint64(-1));
                if (depIndex != -1)
                {
                    dependencies.hkSerializeMultiMap_hkDataClassDict_hkDataClassDict_insert(depIndex, iNewClassIndex);
                }
                for (int k = patchesFromUid.CallHelperWithDefaults(depUid); k != -1;
                     k = patchesFromUid.GetNextChainIndex(k))
                {
                    int value = patchesFromUid.getValue(k);
                    dependencies.hkSerializeMultiMap_hkDataClassDict_hkDataClassDict_insert(iNewClassIndex, value);
                }
            }
        }

        if (p->m_oldVersion == -1)
        {
            if (patchesFromName.LookupWithDefault((S_00db8670_Ulong)name) != -1)
            {
                int k = patchesFromName.LookupWithDefault((S_00db8670_Ulong)name);
                if (k != -1)
                {
                    int lastIndex = FindEntry(uid, 0);
                    S_00db8670_MultiMapUlong* target;
                    if (lastIndex == -1)
                    {
                        if (newClassNames.GetValue(name, -1) != -1)
                        {
                            return 1;
                        }
                        newClassNames.hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(name, j);
                        target = &dependencies;
                    }
                    else
                    {
                        target = &renames;
                    }
                    do
                    {
                        int value = patchesFromName.getValue(k);
                        if (lastIndex != value)
                        {
                            target->hkSerializeMultiMap_hkDataClassDict_hkDataClassDict_insert(iNewClassIndex, value);
                        }
                        k = patchesFromName.GetNextChainIndex(k);
                    } while (k != -1);
                }
            }
        }
    }

    for (int it = renames.m_pHashFunction.GetFirstIterator(); renames.m_pHashFunction.isValid(it);
         it = renames.m_pHashFunction.getNext(it))
    {
        S_00db8670_Ulong key = renames.m_pHashFunction.GetIteratorKey(it);
        for (int k = renames.LookupWithDefault(key); k != -1; k = renames.GetNextChainIndex(k))
        {
            S_00db8670_MapUlong visited;
            int value = renames.getValue(k);
            if (!hkMemoryRouter_ProcessEntries_00db7e70(key, value, dependencies, visited))
            {
                dependencies.hkSerializeMultiMap_hkDataClassDict_hkDataClassDict_insert(key, value);
            }
        }
    }

    S_00db8670_ArrayLocalForm<const S_00db8670_PatchInfo*> sorted;
    sorted.SwapThreeInts(m_kPatchInfos);
    S_00db8670_ArrayLocalForm<int> newIndex;
    newIndex.SetSizeAndGrow(sorted.GetLogicalSize(), -1);
    S_00db8670_ArrayLocalForm<int> stack;
    int next = 0;
    for (int i = 0; i < sorted.GetLogicalSize(); i++)
    {
        next = hkIntArray_ProcessEntries_00db83c0(i, newIndex, dependencies, next, stack, sorted);
    }

    m_kPatchInfos.SetSizeAndGrow(sorted.GetLogicalSize());
    for (int i = 0; i < sorted.GetLogicalSize(); i++)
    {
        int n = newIndex[i];
        if (n < 0)
        {
            m_kPatchInfos.SwapThreeInts(sorted);
            return 1;
        }
        m_kPatchInfos[n] = sorted[i];
    }

    patchIndexFromUid.clear();
    for (int i = 0; i < m_kPatchInfos.GetLogicalSize(); i++)
    {
        const S_00db8670_PatchInfo* p = m_kPatchInfos[i];
        if (p->m_oldName)
        {
            patchIndexFromUid.insert(m_pUidFromClassVersion->ComputeValue_00db7d60(p->m_oldName, p->m_oldVersion), i);
        }
    }
    return 0;
}

struct Dbc860Triple
{
    int x;
    int y;
    int z;
};

struct Dbc860Frame
{
    Dbc860Triple first;
    Dbc860Triple second;
    Dbc860Triple third;
    Dbc860Triple fourth;
    int trailing;
    void FUN_00e028e0();
};

struct Dbc860Src
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    void* m_0c;
};

struct Dbc860Guid
{
    unsigned char b0;
    unsigned char b1;
    unsigned short s2;
    unsigned int d4;
    unsigned int d8;
    unsigned int dc;
};

struct Dbc860Header
{
    unsigned int magic0;
    unsigned int magic1;
    unsigned int id;
    unsigned int type;
    unsigned int data;
    unsigned int extra;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    Dbc860Guid guid;
    unsigned int tail0;
    unsigned int tail1;
};

struct Dbc860Sink
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void Call(int value, void* a, void* b, void* c);
};

extern "C" void __cdecl hkString_memSet(void* dst, int a, int b);
extern "C" void __cdecl hkString_memCpy(void* dst, void* src, int n);
extern "C" void __cdecl CopyIfNonEmpty(void* dst, void* src, int n);
extern "C" void __cdecl hkPackfileWriter_getCurrentVersion(void* dst, int n);
extern int DAT_0126c6c8;

// Builds a Dbc860Header and initializes a Dbc860Frame, then calls sink->Call with the value, header, DAT_0126c6c8, and frame.
// @fnv 0x00dbc860
// src: XBOX_PDB 0x00dbc860
static __declspec(noinline) void __cdecl saveFileHeader(Dbc860Src* apSrc, int value, int extra, Dbc860Sink* sink)
{
    Dbc860Header header;
    Dbc860Frame f;

    hkString_memSet(&header, -1, 0x40);
    header.magic0 = 0x57e0e057;
    header.magic1 = 0x10c0c010;
    header.guid.b0 = 0;
    header.id = apSrc->m_00;
    header.type = 7;
    hkString_memCpy(&header.data, &apSrc->m_04, 4);
    header.extra = extra;
    hkString_memSet(&header.tail0, -1, 8);
    if (apSrc->m_0c == 0)
    {
        hkPackfileWriter_getCurrentVersion(&header.guid, 0x10);
    }
    else
    {
        CopyIfNonEmpty(&header.guid, apSrc->m_0c, 0x10);
    }
    f.first.z = (int)0x80000000;
    f.second.z = (int)0x80000000;
    f.third.z = (int)0x80000000;
    f.fourth.z = (int)0x80000000;
    f.first.x = 0;
    f.first.y = 0;
    f.second.x = 0;
    f.second.y = 0;
    f.third.x = 0;
    f.third.y = 0;
    f.fourth.x = 0;
    f.fourth.y = 0;
    f.trailing = 0;
    sink->Call(value, &header, &DAT_0126c6c8, &f);
    f.FUN_00e028e0();
}

volatile int g_dbc860_value;
volatile int g_dbc860_extra;
Dbc860Src* volatile g_dbc860_self;
Dbc860Sink* volatile g_dbc860_sink;
void CallTarget_dbc860()
{
    saveFileHeader(g_dbc860_self, g_dbc860_value, g_dbc860_extra, g_dbc860_sink);
}

struct S00dbcdd0_Obj
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10(void* p, unsigned int n);
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual unsigned int unk20();
};

struct S00dbcdd0_Alloc
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void Free(void* p, unsigned int n);
};


struct S00dbcdd0_Arr
{
    void* m_data;
    int m_iElementCount;
    unsigned int m_capFlags;
    int u0;
    int u1;
    int u2;
    int u3;
    int u4;
    int u5;
    int u6;
    int u7;
};

extern void hkArrayUtil__reserve(void* alloc, void** pData, int newCap, int flag);
extern void FUN_00ec61c0(void* dst, int value, int n);

template <class T> __forceinline void S00dbcdd0_Construct(T* p, int n, const T& fill)
{
    for (int i = 0; i < n; ++i)
    {
        p[i] = fill;
    }
}

// Fills count bytes with -1, calls obj->unk10 when r is nonzero, then frees the buffer if heap-allocated.
// @fnv 0x00dbcdd0
// src: GUESS 0x00dbcdd0 (confidence: low)
static __declspec(noinline) void hkMemoryRouter_UpdateState_00dbcdd0(S00dbcdd0_Obj* obj, unsigned int count)
{
    int value = (int)obj->unk20();
    S00dbcdd0_Arr arr;
    arr.m_data = &arr.u0;
    arr.m_iElementCount = 0;
    arr.m_capFlags = 0x80000020;
    S00dbcdd0_Alloc& heap = (S00dbcdd0_Alloc&)((hkMemoryRouter*)hkMemoryRouter_getInstance())->heap();
    int cap = (int)(arr.m_capFlags & 0x3fffffff);
    if (cap < (int)count)
    {
        int newCap = cap + cap;
        if ((int)count >= newCap)
        {
            newCap = (int)count;
        }
        hkArrayUtil__reserve(&heap, &arr.m_data, newCap, 1);
    }
    S00dbcdd0_Construct((char*)arr.m_data + arr.m_iElementCount, (int)count - arr.m_iElementCount, (char)-1);
    int r = ((int)count - 1) & value;
    arr.m_iElementCount = (int)count;
    if (r != 0)
    {
        obj->unk10(arr.m_data, count - r);
    }
    S00dbcdd0_Alloc& heap2 = (S00dbcdd0_Alloc&)((hkMemoryRouter*)hkMemoryRouter_getInstance())->heap();
    unsigned int capFlags = arr.m_capFlags;
    arr.m_iElementCount = 0;
    if ((capFlags & 0x80000000u) == 0)
    {
        heap2.Free(arr.m_data, capFlags & 0x3fffffff);
    }
}

void S00dbcdd0_Entry(S00dbcdd0_Obj* obj, unsigned int count)
{
    hkMemoryRouter_UpdateState_00dbcdd0(obj, count);
}

namespace fnv_00dbd7f0 {
struct S_00dbd7f0_Allocator
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void ReleaseBlock(void* p, int numBytes);
};
hkMemoryRouter* hkMemoryRouter_getInstance();

struct S_00dbd7f0_RefObj
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    virtual ~S_00dbd7f0_RefObj();
    void operator delete(void* p)
    {
        S_00dbd7f0_RefObj* b = static_cast<S_00dbd7f0_RefObj*>(p);
        ((S_00dbd7f0_Allocator&)hkMemoryRouter_getInstance()->heap()).ReleaseBlock(p, b->m_usMemSizeAndFlags);
    }
};

struct FUN_00dbd7f0 : S_00dbd7f0_RefObj
{
    FUN_00dbd7f0();
    virtual ~FUN_00dbd7f0();
};
// @fnv 0x00dbd7f0
FUN_00dbd7f0::FUN_00dbd7f0()
{}
}  // namespace fnv_00dbd7f0

extern "C" void _ReadWriteBarrier();
struct OuterOffsets
{
    int fixup;
    int section;
    void step()
    {
        section += 48;
        fixup += 52;
    }
};
struct WriterBool
{
    unsigned char value;
};
struct BinaryWriter
{
    void* stream;
    int mode;
    int state;
    int extra;
    void hkOArchive_InitializeWriterWithByteSwap(void*, WriterBool);
    void ReleaseReference_00d60590();
    void WriteInt(int);
    void hkOArchive_WriteSwapped_Thunk_00d60b00(int*, int);
};
struct OutputStream
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void seek(int, int);
};
struct HashLookup
{
    int state;
    int LookupHashEntry(int, int);
};
struct KeyLookup
{
    int state;
    int GetValue(int, int);
};
struct RootObject
{
    int FUN_00d46d40();
};
struct RootEntry
{
    RootObject* object;
    int a04;
    int a08;
    int a0c;
    int a10;
    int a14;
};
struct WriterOwner
{
    int a00;
    int a04;
    RootEntry* roots;
    int a0c;
    int a10;
    HashLookup hash;
    int a18;
    int a1c;
    int a20;
    int a24;
    int a28;
    int a2c;
    int a30;
    int a34;
    int a38;
    int a3c;
    int a40;
    int a44;
    int a48;
    int a4c;
    int a50;
    int a54;
    int a58;
    int a5c;
    int a60;
    int a64;
    int a68;
    int a6c;
    int a70;
    int a74;
    int a78;
    int a7c;
    int a80;
    int a84;
    int a88;
    int rootIndex;
    int objectIndex;
    void WriteSectionsAndFixups(struct SourceData*, int);
};
struct PointerPair
{
    int first;
    int second;
};
struct Fixup
{
    int location;
    int key;
    int a08;
    int a0c;
};
struct LocalFixup
{
    int location;
    int key;
};
struct ReserveAllocator;
template <class T> struct ArrayBase
{
    T* data;
    int size;
    int capacity;
    void reserve(ReserveAllocator& allocator, int wanted);
    void resize(int wanted, const int& value);
    void resize(int wanted);
    void clear();
    void releaseOnly();
    T& operator[](int i)
    {
        return data[i];
    }
};
template <class T> struct LocalArray : ArrayBase<T>
{
    LocalArray()
    {
        data = 0;
        size = 0;
        *(volatile int*)&capacity = 0x80000000;
    }
};
struct SectionRecord
{
    int a00;
    int a04;
    int a08;
    int a0c;
    int a10;
    int base;
    int a18;
    int globalOffset;
    int localOffset;
    int a24;
    int a28;
    int a2c;
};
struct SectionFixups
{
    LocalArray<int> first;
    LocalArray<Fixup> globals;
    LocalArray<LocalFixup> locals;
    int a24;
    int a28;
    int a2c;
    int a30;
};
struct SectionContext
{
    Triple first;
    Triple second;
    Triple third;
    Triple fourth;
    int trailing;
    void FUN_00e028e0();
};
extern int DAT_0126c698;
struct Serializer
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void serialize(OutputStream*, SectionRecord*, int*, SectionContext*);
    int a04;
    int a08;
    int a0c;
    int* hkPlatformObjectWriter_getLayout();
};
struct SourceData
{
    int a00;
    LocalArray<SectionRecord> sections;
    LocalArray<PointerPair> pointers;
    OutputStream* stream;
    Serializer serializer;
    KeyLookup keys;
    int a34;
    int a38;
    int a3c;
    LocalArray<SectionFixups> fixups;
    WriterBool reverse;
};
extern void __cdecl hkArrayUtil__reserve(void*, void*, int, int);
struct ReserveAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void release(void*, int);
};
template <class T> __forceinline void ArrayBase<T>::reserve(ReserveAllocator& allocator, int wanted)
{
    int cap = capacity & 0x3fffffff;
    if (cap < wanted)
    {
        int newCapacity = wanted < cap * 2 ? cap * 2 : wanted;
        hkArrayUtil__reserve(&allocator, this, newCapacity, sizeof(T));
    }
}
template <class T> __forceinline void ArrayBase<T>::resize(int wanted, const int& value)
{
    reserve((ReserveAllocator&)((hkMemoryRouter*)hkMemoryRouter_getInstance())->heap(), wanted);
    int remaining = wanted - size;
    T* fill = data + size;
    for (int n = 0; n < remaining; n++)
        fill[n] = value;
    size = wanted;
}
template <class T> __forceinline void ArrayBase<T>::resize(int wanted)
{
    reserve((ReserveAllocator&)((hkMemoryRouter*)hkMemoryRouter_getInstance())->heap(), wanted);
    size = wanted;
}
template <class T> __forceinline void ArrayBase<T>::clear()
{
    ReserveAllocator& allocator = (ReserveAllocator&)((hkMemoryRouter*)hkMemoryRouter_getInstance())->heap();
    size = 0;
    if ((capacity & 0x80000000) == 0)
        allocator.release(data, (capacity & 0x3fffffff) * sizeof(T));
    data = 0;
    capacity = 0x80000000;
}
template <class T> __forceinline void ArrayBase<T>::releaseOnly()
{
    ReserveAllocator& allocator = (ReserveAllocator&)((hkMemoryRouter*)hkMemoryRouter_getInstance())->getHeap();
    size = 0;
    if ((capacity & 0x80000000) == 0)
        allocator.release(data, (capacity & 0x3fffffff) * sizeof(T));
}
// Writes global and local fixup data for each section, then serializes each section and writes the root object header to the stream.
// @fnv 0x00dbc960
// src: GUESS 0x00dbc960 (confidence: medium)
void WriterOwner::WriteSectionsAndFixups(SourceData* source, int position)
{
    BinaryWriter values;
    values.hkOArchive_InitializeWriterWithByteSwap(source->stream, source->reverse);
    SectionRecord* kIter;
    {
        int ptr = 0;
        if (ptr < source->sections.size)
        {
            OuterOffsets offsets;
            offsets.fixup = 0;
            offsets.section = 0;
            do
            {
                SectionFixups* pFixups = ((SectionFixups*)((char*)source->fixups.data + offsets.fixup));
                LocalArray<Fixup>* pGlobals = &pFixups->globals;
                ArrayBase<int> localOut;
                {
                    LocalArray<int> n;

                    kIter = ((SectionRecord*)((char*)source->sections.data + offsets.section));
                    n.resize((*(volatile int*)&pGlobals->size) * 3, -1);
                    _ReadWriteBarrier();
                    int j = 0;
                    unsigned int writer = 0;
                    if (pGlobals->size > 0)
                    {

                        HashLookup* volatile pHash = &hash;

                        do
                        {
                            int q;
                            int key = pGlobals->data[j].key;
                            q = pHash->LookupHashEntry(key, -3);
                            if (0 <= q && source->pointers.data[q].first >= 0)
                            {
                                n.data[writer] = pGlobals->data[j].location - kIter->base;
                                n.data[writer + 1] = source->pointers.data[q].first;
                                n.data[2 + writer] = source->pointers.data[q].second;
                                writer += 3;
                            }
                        } while (++j < pGlobals->size);
                    }
                    source->stream->seek(kIter->base + kIter->globalOffset, 0);
                    values.hkOArchive_WriteSwapped_Thunk_00d60b00(n.data, n.size);
                    n.clear();
                }
                LocalArray<LocalFixup>* b;
                b = &((SectionFixups*)((char*)source->fixups.data + offsets.fixup))->locals;
                kIter = ((SectionRecord*)((char*)source->sections.data + offsets.section));

                ArrayBase<int>& out = localOut;
                out.data = 0;
                out.size = 0;
                out.capacity = 0x80000000;
                out.resize(b->size * 3);
                for (int k = 0, offset = 0; k < b->size; k++, offset += 3)
                {
                    out.data[offset] = b->data[k].location - kIter->base;
                    out.data[offset + 1] = 0;
                    int localKey = b->data[k].key;
                    int mapped = source->keys.GetValue(localKey, -1);
                    out.data[2 + offset] = mapped;
                }
                source->stream->seek(kIter->localOffset + kIter->base, 0);
                values.hkOArchive_WriteSwapped_Thunk_00d60b00(out.data, out.size);
                out.clear();
                offsets.section += 48;
                offsets.fixup += 52;
            } while (++ptr < source->sections.size);
        }
    }
    source->stream->seek(position, 0);
    for (int s = 0; s < source->sections.size; s++)
    {
        SectionContext context;
        context.trailing = 0;
        source->serializer.serialize(source->stream, &source->sections.data[s], &DAT_0126c698, &context);
        context.FUN_00e028e0();
    }
    source->stream->seek(24, 0);
    WriterBool p;
    p.value = (unsigned char)(((unsigned int)*source->serializer.hkPlatformObjectWriter_getLayout()) >> 8) != (unsigned char)DAT_011b7b89;
    BinaryWriter ptr;
    ptr.hkOArchive_InitializeWriterWithByteSwap(source->stream, p);
    ptr.WriteInt(source->pointers.data[rootIndex].first);
    ptr.WriteInt(source->pointers.data[rootIndex].second);
    RootObject* section;
    section = roots[objectIndex].object;
    ptr.WriteInt(0);
    unsigned long index;
    index = section->FUN_00d46d40();
    ptr.WriteInt(source->keys.GetValue(index, -1));
    ptr.ReleaseReference_00d60590();
    values.ReleaseReference_00d60590();
}

// Grouped serialization and offset-table construction.
struct ClockObj
{
    virtual void c00();
    virtual void c04();
    virtual void c08();
    virtual void c0c();
    virtual void c10(int a, int b);
    virtual void c14();
    virtual void c18();
    virtual int c1c(int n, int f);
    virtual int Get20();
};
struct FUN_00d46d40_s
{
    const char* text;
    __declspec(noinline) const char* FUN_00d46d40();
};

struct FUN_00d874b0_class
{
    char* SetBoolFromThreshold(char* buf, int v);
};
struct FUN_00dbdd40_s
{
    int GetOrAddString(int v);
};
struct FUN_00dce8d0_class
{
    int LookupHashEntry(unsigned long a, unsigned long b);
};
struct FUN_00d60940_Class
{
    void WriteInt(unsigned int v);
};
struct FUN_00d607b0_s
{
    void writeVec(int v, int n);
};
struct FUN_00d9ec10_cls
{
    void SwapThreeInts(int* a);
};
extern void __stdcall WriteSwapped(void* data, int elem, int bytes);
struct Ctx
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void hkOArchive_InitializeWriterWithByteSwap(ClockObj* c, int f);
    void ReleaseReference_00d60590();
    void WriteSwapped(void* data, int elem, int count);
};
struct MapBool
{
    char value;
    MapBool(bool v) : value(v)
    {}
    operator bool() const
    {
        return value != 0;
    }
};
struct LocObj
{
    int l00;
    int l04;
    int l08;
    int l0c;
    void FUN_00d87790(MapBool a);
    void hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(const char* s, int f);
    void* FindStringKey(const char* s);
    MapBool SetBoolFromThreshold(int v);
    void FreeBuffer();
    void hkOArchive_InitializeWriterWithByteSwap(ClockObj* c, int f);
    void WriteSwapped(void* data, int elem, int bytes);
    void WriteInt(int v);
    void hkOArchive_writeRaw(int v, int n);
    void ReleaseReference_00d60590();
};
struct Pair8
{
    int p0;
    int p1;
};
struct Record16
{
    int value;
    int key;
    int unk08;
    int unk0c;
    __forceinline int GetIteratorKey() const
    {
        return key;
    }
};
struct Record12
{
    int value;
    int key;
    int unk08;
};
template <class T> struct Vec
{
    T* m_data;
    int m_iElementCount;
    int m_cap;
    __forceinline T& operator[](int i)
    {
        return m_data[i];
    }
    Vec() : m_data(0), m_iElementCount(0), m_cap((int)0x80000000)
    {}
};
typedef Vec<Pair8> Arr8;
struct Stats
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int start;
    int end1;
    int end2;
    int end3;
    int end4;
    int end5;
    int end6;
};
struct SrcOptions
{
    int unk00;
    int unk04;
    unsigned char flag08;
};
struct SubVec
{
    int v00;
    int v04;
    int v08;
    void SwapThreeInts(Arr8* a);
};
inline void* operator new(unsigned int, void* p)
{
    return p;
}
struct Entry52
{
    Triple first;
    Triple second;
    Triple third;
    Triple fourth;
    int trailing;
    Entry52() : trailing(0)
    {}
    void FUN_00e028e0();
};
struct Arr52
{
    Entry52* m_data;
    int m_iElementCount;
    int m_cap;
};
struct Sub20Obj
{
    virtual void c00();
    virtual void c04();
    virtual void c08();
    virtual void write(ClockObj* c, int a, int b, Arr8* arr);
    int unk04;
    int unk08;
    int unk0c;
};
struct Src
{
    SrcOptions* unk00;
    Stats* unk04;
    int count08;
    int unk0c;
    Arr8 arr10;
    ClockObj* clock1c;
    Sub20Obj sub20;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    Arr52 arr40;
    unsigned char flag4c;
    unsigned char unk4d;
    unsigned char unk4e;
    unsigned char unk4f;
};
struct ThisEntry
{
    int t00;
    int t04;
    int t08;
    int t0c;
    int t10;
    int t14;
    __forceinline const char* getName();
};
__forceinline const char* ThisEntry::getName()
{
    return ((FUN_00d46d40_s*)t04)->FUN_00d46d40();
}
struct ThisSub
{
    int d00;
    int d04;
    int d08;
    int LookupHashEntry(int val, int def);
};
struct ThisSub1
{
    int d00;
    int LookupHashEntry(int val, int def);
};
struct PairMap
{
    Pair8* data;
    int size;
    int last;
};
struct ThisCls
{
    int unk00;
    int unk04;
    Vec<ThisEntry> entries;
    ThisSub sub14;
    ThisSub1 sub20o;
    int unk24;
    int unk28;
    PairMap map2c;
    void WriteNodeDiff(Src* src, void* glob, int diff);
    int GetOrAddString(int v);
    void hkBinaryPackfileWriter_writeAllObjects(Src* arg);
};
extern int DAT_011b7aec;
void* hkMemoryRouter_getInstance();
extern void __cdecl ResizeAudioStream(void* allocator, void* vec, unsigned int elemSize);
extern void __cdecl hkArrayUtil__reserve(void* a, void* vec, int n, int elem);
extern int __cdecl hkString_strLen(void* p);
extern void* __cdecl memset(void*, int, unsigned int);
extern "C" void _ReadWriteBarrier();

extern void FUN_00ec61c0(void* dst, int value, int n);
// src: GUESS 0x00dbcdd0 (confidence: low)
static __declspec(noinline) void hkMemoryRouter_UpdateState_00dbcdd0(ClockObj* obj0, unsigned int count)
{
    S00dbcdd0_Obj* obj = (S00dbcdd0_Obj*)obj0;
    int value = (int)obj->unk20();
    S00dbcdd0_Arr arr;
    arr.m_data = &arr.u0;
    arr.m_iElementCount = 0;
    arr.m_capFlags = 0x80000020;
    S00dbcdd0_Alloc& heap = (S00dbcdd0_Alloc&)((hkMemoryRouter*)hkMemoryRouter_getInstance())->heap();
    int cap = (int)(arr.m_capFlags & 0x3fffffff);
    if (cap < (int)count)
    {
        int newCap = cap + cap;
        if ((int)count >= newCap)
        {
            newCap = (int)count;
        }
        hkArrayUtil__reserve(&heap, &arr, newCap, 1);
    }
    int end = (int)arr.m_data + arr.m_iElementCount;
    int fill = (int)count - arr.m_iElementCount;
    if (fill > 0)
    {
        FUN_00ec61c0((void*)end, -1, fill);
    }
    int r = ((int)count - 1) & value;
    arr.m_iElementCount = (int)count;
    if (r != 0)
    {
        obj->unk10(arr.m_data, count - r);
    }
    S00dbcdd0_Alloc& heap2 = (S00dbcdd0_Alloc&)((hkMemoryRouter*)hkMemoryRouter_getInstance())->heap();
    unsigned int capFlags = arr.m_capFlags;
    arr.m_iElementCount = 0;
    if ((capFlags & 0x80000000u) == 0)
    {
        heap2.Free(arr.m_data, capFlags & 0x3fffffff);
    }
}

struct Work
{
    Arr8 a1;
    Vec<Record16> a2;
    Vec<Record12> a3;
    Arr8 a4;
    int extra;
    Work() : extra(0)
    {}
    void FUN_00e028e0();
};

template <class A> __forceinline void Reserve(A& array, BDBD910Allocator& alloc, int n, int size)
{
    int cap = array.m_cap & 0x3fffffff;
    if (cap < n)
    {
        cap *= 2;
        if (n >= cap)
            cap = n;
        hkArrayUtil__reserve(&alloc, &array, cap, size);
    }
}
template <class T> __forceinline void Destroy(T* p, int count)
{
    for (int i = 0; i < count; ++i)
        p[i].FUN_00e028e0();
}
template <class T> __forceinline void Construct(T* p, int count)
{
    for (int i = 0; i < count; ++i)
        new (p + i) T();
}
__forceinline void Resize52(Arr52& a, int n)
{
    BDBD910Allocator& alloc = (BDBD910Allocator&)((hkMemoryRouter*)hkMemoryRouter_getInstance())->heap();
    Reserve(a, alloc, n, 52);
    Destroy(a.m_data + n, a.m_iElementCount - n);
    Construct(a.m_data + a.m_iElementCount, n - a.m_iElementCount);
    a.m_iElementCount = n;
}
__forceinline void Resize8(Arr8& a, int n)
{
    BDBD910Allocator& alloc = (BDBD910Allocator&)((hkMemoryRouter*)hkMemoryRouter_getInstance())->heap();
    Reserve(a, alloc, n, 8);
    a.m_iElementCount = n;
}
template <unsigned Bytes> __forceinline void CopyWords(void* dst, const void* src)
{
    unsigned cursor = 0;
    do
    {
        ((unsigned*)dst)[cursor] = ((const unsigned*)src)[cursor];
    } while (++cursor < Bytes / sizeof(unsigned));
}

typedef void* MapIter;
__forceinline Pair8& ExpandOne(Arr8& a, hkMemoryRouter& router)
{
    if (a.m_iElementCount == (a.m_cap & 0x3fffffff))
        ResizeAudioStream(router.m_heap, &a, 8);
    return a.m_data[a.m_iElementCount++];
}
__forceinline void RemoveAt(Vec<Record16>& a, int index, int byteOffset)
{
    --a.m_iElementCount;
    if (a.m_iElementCount != index)
        CopyWords<16>((char*)a.m_data + byteOffset, a.m_data + a.m_iElementCount);
}
__forceinline MapIter BeginPairs(PairMap* map)
{
    int i = 0;
    while (i <= map->last)
    {
        if (map->data[i].p0 != -1)
            break;
        ++i;
    }
    return (MapIter)i;
}
__forceinline MapIter NextPair(PairMap* map, MapIter previous)
{
    int i = (int)previous + 1;
    while (i <= map->last)
    {
        if (map->data[i].p0 != -1)
            break;
        ++i;
    }
    return (MapIter)i;
}
// Calls WriteNodeDiff for four globals and unseen entries, writes per-counter data, records timings, and resizes two arrays.
// @fnv 0x00dbcea0
// src: XBOX_PDB 0x00dbcea0
void ThisCls::hkBinaryPackfileWriter_writeAllObjects(Src* apSrc)
{
    int i, j, counter, iResult;
    int objectBytes;
    (void)objectBytes;
    (void)counter;
    Stats* stats = apSrc->unk04;
    stats->start = apSrc->clock1c->Get20();
    {
        LocObj locObj;
        locObj.FUN_00d87790(MapBool(false));
        void* tbl[4];
        tbl[0] = &g_0126cae8;
        tbl[1] = &g_0126ca58;
        tbl[2] = &g_0126cab8;
        tbl[3] = &g_0126ca88;
        for (i = 0; i < 4; i++)
        {
            FUN_00d46d40_s* g = (FUN_00d46d40_s*)tbl[i];
            const char* name = g->FUN_00d46d40();
            locObj.hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(name, 1);
            WriteNodeDiff(apSrc, tbl[i], stats->start);
        }
        for (j = 0, objectBytes = 0; j < entries.m_iElementCount; j++, objectBytes += sizeof(ThisEntry))
        {
            void* found = locObj.FindStringKey(((ThisEntry*)((char*)entries.m_data + objectBytes))->getName());
            MapBool has = locObj.SetBoolFromThreshold((int)found);
            if (!has)
            {
                const char* name = ((ThisEntry*)((char*)entries.m_data + objectBytes))->getName();
                locObj.hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(name, 1);
                WriteNodeDiff(apSrc, (void*)((ThisEntry*)((char*)entries.m_data + objectBytes))->t04, stats->start);
            }
        }
        hkMemoryRouter_UpdateState_00dbcdd0(apSrc->clock1c, 16);
        int d = apSrc->clock1c->Get20() - stats->start;
        stats->end1 = d;
        stats->end2 = d;
        stats->end3 = d;
        stats->end4 = d;
        stats->end5 = d;
        stats->end6 = d;
        locObj.FreeBuffer();
    }
    Resize8(apSrc->arr10, entries.m_iElementCount);
    Resize52(apSrc->arr40, apSrc->count08);
    iResult = ((FUN_00dbdd40_s*)this)->GetOrAddString(DAT_011b7aec);
    for (counter = 1; counter < apSrc->count08; counter++)
    {
        stats = apSrc->unk04 + counter;
        stats->start = apSrc->clock1c->Get20();
        Work work;
        SrcOptions* u0 = apSrc->unk00;
        if (u0->flag08 != 0 || counter != iResult)
        {
            for (int idx = 0; idx < entries.m_iElementCount; idx++)
            {
                ThisEntry* pEntry = &entries[idx];
                if (pEntry->t10 == counter)
                {
                    int saved0 = pEntry->t00;
                    int saved4 = pEntry->t04;
                    int ai = idx;
                    apSrc->arr10.m_data[ai].p0 = counter;
                    Pair8* pair = &apSrc->arr10.m_data[ai];
                    pair->p1 = apSrc->clock1c->Get20() - stats->start;
                    if (saved4 != 0)
                    {
                        apSrc->sub20.write(apSrc->clock1c, saved0, saved4, &work.a1);
                    }
                    else
                    {
                        apSrc->clock1c->c10(pEntry->t00, pEntry->t14);
                    }
                }
            }
        }
        else
        {
            int idx = 0;
            if (idx < entries.m_iElementCount)
            {
                objectBytes = 0;
                do
                {
                    if (((ThisEntry*)((char*)entries.m_data + objectBytes))->t10 == iResult)
                    {
                        apSrc->arr10.m_data[idx].p0 = -1;
                        apSrc->arr10.m_data[idx].p1 = -1;
                    }
                    objectBytes += sizeof(ThisEntry);
                } while (++idx < entries.m_iElementCount);
            }
        }
        for (int k = 0; k < work.a1.m_iElementCount; k++)
        {
            work.a1.m_data[k].p0 -= stats->start;
            work.a1.m_data[k].p1 -= stats->start;
        }
        {
            int jfix = work.a2.m_iElementCount - 1;
            if (jfix >= 0)
            {
                FUN_00dce8d0_class* imports = (FUN_00dce8d0_class*)&sub20o;
                objectBytes = jfix * 16;
                for (; jfix >= 0; jfix--, objectBytes -= 16)
                {
                    int found = imports->LookupHashEntry(
                        (unsigned long)((Record16*)((char*)work.a2.m_data + objectBytes))->GetIteratorKey(), 0);
                    if (found != 0)
                    {
                        Record16* elem = (Record16*)((char*)work.a2.m_data + objectBytes);
                        Pair8* out = &ExpandOne(work.a4, *(hkMemoryRouter*)hkMemoryRouter_getInstance());
                        out->p0 = elem->value - stats->start;
                        out->p1 = found;
                        RemoveAt(work.a2, jfix, objectBytes);
                    }
                }
            }
        }
        Ctx ctx;
        ctx.hkOArchive_InitializeWriterWithByteSwap(apSrc->clock1c, apSrc->flag4c);
        stats->end1 = apSrc->clock1c->Get20() - stats->start;
        ctx.WriteSwapped(work.a1.m_data, 4, work.a1.m_iElementCount * 2);
        hkMemoryRouter_UpdateState_00dbcdd0(apSrc->clock1c, 16);
        stats->end2 = apSrc->clock1c->Get20() - stats->start;
        apSrc->clock1c->c1c(work.a2.m_iElementCount * 12, 1);
        ((FUN_00d9ec10_cls*)&apSrc->arr40.m_data[counter].second)->SwapThreeInts((int*)&work.a2);
        hkMemoryRouter_UpdateState_00dbcdd0(apSrc->clock1c, 16);
        stats->end3 = apSrc->clock1c->Get20() - stats->start;
        apSrc->clock1c->c1c(work.a3.m_iElementCount * 12, 1);
        ((FUN_00d9ec10_cls*)&apSrc->arr40.m_data[counter].third)->SwapThreeInts((int*)&work.a3);
        hkMemoryRouter_UpdateState_00dbcdd0(apSrc->clock1c, 16);
        stats->end4 = apSrc->clock1c->Get20() - stats->start;
        {
            MapIter idx = BeginPairs(&map2c);
            bool flag = false;
            if ((int)idx <= map2c.last)
            {
                for (;;)
                {
                    Pair8* pr = map2c.data + (int)idx;
                    int v = pr->p0;
                    int foundIdx = ((FUN_00dce8d0_class*)&sub14)->LookupHashEntry((unsigned long)v, (unsigned long)-1);
                    if (foundIdx >= 0)
                    {
                        ThisEntry* pEntry = &entries[foundIdx];
                        if (pEntry->t10 == counter)
                        {
                            int second = (map2c.data + (int)idx)->p1;
                            int av = apSrc->arr10.m_data[foundIdx].p1;
                            flag = true;
                            ((FUN_00d60940_Class*)&ctx)->WriteInt((unsigned int)av);
                            int r = hkString_strLen((void*)second);
                            ((FUN_00d607b0_s*)&ctx)->writeVec(second, r + 1);
                            hkMemoryRouter_UpdateState_00dbcdd0(apSrc->clock1c, 4);
                        }
                    }
                    idx = NextPair(&map2c, idx);
                    if ((int)idx > map2c.last)
                        break;
                }
            }
            if (flag)
            {
                ((FUN_00d60940_Class*)&ctx)->WriteInt((unsigned int)-1);
                hkMemoryRouter_UpdateState_00dbcdd0(apSrc->clock1c, 16);
            }
        }
        stats->end5 = apSrc->clock1c->Get20() - stats->start;
        for (int k = 0; k < work.a4.m_iElementCount; k++)
        {
            Pair8* pr = work.a4.m_data + k;
            ((FUN_00d60940_Class*)&ctx)->WriteInt((unsigned int)pr->p0);
            int r = hkString_strLen((void*)pr->p1);
            ((FUN_00d607b0_s*)&ctx)->writeVec(pr->p1, r + 1);
            hkMemoryRouter_UpdateState_00dbcdd0(apSrc->clock1c, 4);
        }
        if (work.a4.m_iElementCount != 0)
        {
            ((FUN_00d60940_Class*)&ctx)->WriteInt((unsigned int)-1);
            ((FUN_00d9ec10_cls*)&apSrc->arr40.m_data[counter].fourth)->SwapThreeInts((int*)&work.a4);
            hkMemoryRouter_UpdateState_00dbcdd0(apSrc->clock1c, 16);
        }
        stats->end6 = apSrc->clock1c->Get20() - stats->start;
        ctx.ReleaseReference_00d60590();
        work.FUN_00e028e0();
    }
}

namespace SectionTagsPrivate {

struct Header
{
    char tag[19];
    char terminator;
    int dataStart;
    int localFixups;
    int globalFixups;
    int finishFixups;
    int exports;
    int imports;
    int end;
    Header()
    {
        hkString_memSet(this, 0, 4);
    }
};

struct HeaderArray
{
    Header* data;
    int size;
    int capacity;
    int getCapacity() const
    {
        return capacity & 0x3fffffff;
    }
};

struct Context
{
    void* options;
    HeaderArray headers;
};

extern "C" unsigned int __cdecl Object_ComputeValue_00dbd720(const HeaderArray* headers);
extern "C" void __cdecl CopyIfNonEmpty(char* dst, const char* src, int count);

template <class T> __forceinline void ConstructHeaders(T* first, int count)
{
    for (int i = 0; i < count; ++i)
        new (first + i) T;
}

struct Writer
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60;
    const char** tags;
    int tagCount;
    void hkBinaryPackfileWriter_fillSectionTags(Context* context);
};

// Resizes the header array to tagCount, initializes its data range to -1, and copies 19 bytes from each tag.
// @fnv 0x00dbc7a0
// src: XBOX_PDB 0x00dbc7a0
void Writer::hkBinaryPackfileWriter_fillSectionTags(Context* context)
{
    HeaderArray* headers = &context->headers;
    int count = tagCount;
    BDBD910Allocator& allocator = (BDBD910Allocator&)((hkMemoryRouter*)hkMemoryRouter_getInstance())->heap();
    if (headers->getCapacity() < count)
    {
        int capacity = 2 * headers->getCapacity();
        hkArrayUtil__reserve(&allocator, headers, count < capacity ? capacity : count, 48);
    }
    ConstructHeaders(headers->data + headers->size, count - headers->size);
    headers->size = count;
    unsigned int bytes = (Object_ComputeValue_00dbd720)(headers);
    hkString_memSet(headers->data, -1, (int)bytes);
    for (int i = 0; i < tagCount; ++i)
        (CopyIfNonEmpty)(headers->data[i].tag, tags[i], 19);
}

}
