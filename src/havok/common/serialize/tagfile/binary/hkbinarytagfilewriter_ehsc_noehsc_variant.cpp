#include "../../../../../../include/hkArrayBase.h"
#include "../../../../../../include/Pair.h"
#include "../../../../../../include/BSAudio.h"
#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkCharArray.h"

// src/havok/common/serialize/tagfile/binary/hkbinarytagfilewriter_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/common/serialize/tagfile/binary/hkbinarytagfilewriter.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/serialize/tagfile/binary/hkbinarytagfilewriter.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/tagfile/binary/hkbinarytagfilewriter.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
BSAudio* __cdecl hkMemoryRouter_getInstance();
struct UnkRet
{
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int h;
    int i;
    int j;
    int k;
    int l;
    int m;
    int n;
    int o;
    int p;
    int q;
    int r;
    int s;
    int t;
    int u;
    int v;
    int w;
    int x;
    int y;
    int z;
};
struct UnkHolder
{
    int a;
    int b;
    int c;
    void __thiscall ProcessEntries_00dbedb0(UnkRet*, int);
};
struct FUN_00dc0380
{
    BSAudio* p;
    UnkHolder unk;
    int a;
    int b;
    int c;
    FUN_00dc0380(BSAudio* v);
};
struct ObjectHandle
{
    void* object;
    __declspec(nothrow) int InvokeVirtualMethod_00dbac00();
    __declspec(nothrow) void ReleaseStorage_00dbab70();
    ~ObjectHandle()
    {
        ReleaseStorage_00dbab70();
    }
};
struct StringHandle
{
    void* object;
    __declspec(nothrow) int hkDataObject_isNull();
    __declspec(nothrow) void ReleaseStorage_00dba7f0();
    ~StringHandle()
    {
        ReleaseStorage_00dba7f0();
    }
};
struct Value
{
    int InvokeVirtualMethod_00dbac40();
    int CallVirtualWithArg();
    float ApplyValue();
    void* ForwardCall_00dbac70();
    __declspec(nothrow) ObjectHandle GetMemberArrayValue();
    __declspec(nothrow) StringHandle CreateValueInto();
};
int __stdcall IsTruthy(Value* value);
struct ResourceKey
{
    int first;
    int second;
};
struct SoundEntry
{
    void* sound;
};
struct Receiver
{
    void __thiscall FUN_009ba760(void* sound);
    void __thiscall FUN_009ba780(void* description);
};
struct Description
{
    int __thiscall FUN_009ba980();
    void __thiscall FUN_009ba810(ResourceKey* key);
};
struct ResourceLookup
{
    int unk00;
    int unk04;
    int unk08;
    int __thiscall FUN_009be8c0(int first, int second, int flags);
};
struct AudioResourceState
{
    void* active;
    ResourceLookup lookup;
    SoundEntry** entries;
    void* __thiscall ResolveSound(Receiver* receiver, Description* description);
};
inline hkMemoryRouter* audio()
{
    return (hkMemoryRouter*)hkMemoryRouter_getInstance();
}
struct ArrayDeallocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void FreeArray(void* apMemory, unsigned int auiSize);
};
struct Element
{
    int m_i00;
    void ReleaseStorage_00dba7f0();
};
struct SubObject
{
    int m_i00;
    int m_i04;
    int m_i08;
    void AllocBufferIfNotFlagged(hkMemoryAllocator* apAllocator);
};
struct FUN_00dc03d0_cls
{
    int unk00;
    SubObject m_kSub;
    Element** m_ppArray;
    int m_iArrayLength;
    unsigned int m_uCapacity;
    void ClearArray();
};
struct AudioObject
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};
struct Dc0380Layout
{
    BSAudio* p;
    UnkHolder unk;
    int a;
    int b;
    int c;
};
struct FUN_00dc05b0_writer
{
    AudioObject first;
    AudioObject second;
    AudioObject third;
    int unk30;
    UnkHolder unk34;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    Dc0380Layout audio;
    void __thiscall FUN_00dc0500(int, int);
    void __thiscall WriteInt(unsigned int);
    void __thiscall WriteVarint(unsigned int, unsigned int);
    void __thiscall WriteReferencedObjectRecursively(int, int);
    void __thiscall ProcessEntries_00dc00b0(int);
    void __thiscall ProcessState_00dc0460();
};
struct CallbackTarget
{
    virtual void Dummy0()
    {}
    virtual void Dummy1()
    {}
    virtual void Dummy2()
    {}
    virtual void Dummy3()
    {}
    virtual void Dummy4()
    {}
    virtual void Complete()
    {}
};
int __stdcall WriteAudioObject(int value, CallbackTarget* target, int source);
struct Obj
{
    void __thiscall hkOArchive_write8u(unsigned char);
    void __thiscall WriteVarint(__int64);
};
struct FUN_00dbe8c0_cls
{
    struct HashEntry
    {
        unsigned int key0;
        unsigned int key1;
        unsigned int value;
    };

    HashEntry* m_pEntries;
    unsigned int m_u04;
    unsigned int m_uMask;

    unsigned int FindEntryValue(unsigned int aKey0, unsigned int aKey1, unsigned int aDefault);
};
// A 12-byte hash table (as used by the hkPackfileWriter module): a pointer to
// an array of 12-byte entries, a flag word and the number of entries.
struct HashEntry
{
    int unk00;
    int unk04;
    int unk08;
};
struct HashTableBase
{
    HashEntry* m_entries;
    int m_flags;
    int m_uiItemCount;

    void ClearEntries();
};
struct AudioIface
{
    virtual void v00();
    virtual void v04();
    virtual void Alloc(void* apBuf, unsigned int auSize);
};
struct FUN_00dbe950_cls
{
    void* m_00;
    unsigned int m_04;
    unsigned int m_08;

    void ClearEntries();
    void AllocBufferIfNotFlagged(AudioIface* apIface);
};
struct AllocOwner
{
    virtual void v0();
    virtual void* Alloc(unsigned int size);
    virtual void Free(void* p, unsigned int size);
};
struct Entry12
{
    int a;
    int b;
    int c;
};
struct FUN_00dbe810_cls
{
    void InsertOrUpdate(AllocOwner* alloc, int e0, int e1, int e2);
};
struct FUN_00dbec60_cls
{
    Entry12* m_00;
    unsigned int m_04;
    int m_08;

    void hkMapBase_struct_hkCppTypeInfoHash_struct_hkRttiParser_Node_const_struct_hkCppTypeInfoHash_resizeTable(AllocOwner* alloc, int count);
};
extern "C" int __cdecl hkString_strLen(const char* s);
struct DBED30StringMap
{
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    int FindValueForKey(const char* key, int def) const;
    void insert(const char* key, int val);
};
struct DBED30Writer
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    DBED30StringMap m_pStringFunctions;

    void WriteSigned64BitInteger(__int64 i);
    void WriteByteArray(const void* buf, int nbytes);
    void WriteString(const char* s);
};
struct Rec_00dbf0d0
{
    unsigned char* unk00;  // data buffer
    int unk04;             // used size
    int unk08;             // capacity (low 30 bits) + flags
    void __thiscall PackBitsToBytes(unsigned char* dest);
};
void __cdecl fnv_grow_00c908c0(int audioD, Rec_00dbf0d0* self, int newCap, int flag);
void __cdecl fnv_memset_00ec61c0(void* dest, int ch, int count);
extern int DAT_01011584;
struct S_00dc0500_Flag
{
    bool b;
    S_00dc0500_Flag(bool v) : b(v)
    {}
};
struct S_00dc0500_Opt
{
    bool b;
    S_00dc0500_Opt(bool v) : b(v)
    {}
    S_00dc0500_Opt(const S_00dc0500_Opt& o) : b(o.b)
    {}
};
struct FUN_00d60830
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00d60830(BSAudio* a1, S_00dc0500_Opt f);
};
struct S_00dc0500_Str
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void __thiscall hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(int* s, int n);
};
struct FUN_00d87790 : S_00dc0500_Str
{
    FUN_00d87790(S_00dc0500_Flag f);
};
struct S_00dc0500_Holder : UnkHolder
{
    S_00dc0500_Holder()
    {
        a = 0;
        b = 0;
        c = -1;
        BSAudio* p = hkMemoryRouter_getInstance();
        ProcessEntries_00dbedb0((UnkRet*)((hkMemoryRouter*)p)->m_heap, 0);
    }
};
struct S_00dc0500_Arr
{
    int a;
    int b;
    int c;
    S_00dc0500_Arr() : a(0), b(0), c(0x80000000)
    {}
};
struct FUN_00dc0500 : FUN_00d60830
{
    FUN_00d87790 m_10;
    FUN_00d87790 m_20;
    int m_30;
    S_00dc0500_Holder m_34;
    S_00dc0500_Arr m_40;
    S_00dc0500_Arr m_4c;
    FUN_00dc0380 m_58;
    FUN_00dc0500(BSAudio* a1, BSAudio* a2);
};
inline void* operator new(size_t, void* p) throw()
{
    return p;
}
struct S_dbf1a0_Map
{
    int unk00;
    int unk04;
    int __thiscall GetValue(const char* name, int defValue) throw();
    void __thiscall hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(const char* name, int value) throw();
};
struct S_dbf1a0_Handle
{
    void* m_ptr;
    S_dbf1a0_Handle(void* p) throw()
    {
        SetField00(p);
    }
    S_dbf1a0_Handle() throw()
    {
        m_ptr = 0;
    }
    ~S_dbf1a0_Handle() throw()
    {
        Object_DoNothing_00dba660();
    }

    void __thiscall SetField00(void* p) throw();
    void __thiscall Object_DoNothing_00dba660() throw();
    const char* __thiscall hkDataClass_getName() const throw();
    int __thiscall ForwardCall_00dba690() const throw();
    S_dbf1a0_Handle __thiscall SetShiftedValue() const throw();
    int __thiscall ForwardCall_00dba6f0() const throw();
    void __thiscall DispatchRecords(void* arr) const throw();
};
struct S_dbf1a0_Elem
{
    const char* name;
    int unk04;
    int flags;
    void* sub;
    int unk10;

    S_dbf1a0_Elem() throw() : name(0), unk04(0), flags(0), sub(0), unk10(0)
    {}
};
struct hkTempAlloc : hkMemoryAllocator
{
    virtual void* v04() throw();
    virtual void* v08() throw();
    virtual void* bufAlloc(int& numBytes) throw();
    virtual void bufFree(void* p, int numBytes) throw();

    template <typename T> __forceinline T* _bufAlloc(int& reqNumInOut) throw()
    {
        int n = reqNumInOut * (int)sizeof(T);
        T* p = (T*)bufAlloc(n);
        reqNumInOut = n / (int)sizeof(T);
        return p;
    }
    template <typename T> __forceinline void _bufFree(void* p, int numElem) throw()
    {
        bufFree(p, numElem * (int)sizeof(T));
    }
};
struct S_dbf1a0_Router
{
    int unk00, unk04, unk08;
    hkTempAlloc* unk0c;
    hkTempAlloc& heap() throw()
    {
        return *unk0c;
    }
};
template <typename T> struct S_dbf1a0_Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline S_dbf1a0_Array(int n) throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {
        hkTempAlloc& alloc = ((S_dbf1a0_Router*)hkMemoryRouter_getInstance())->heap();
        T* p = n ? alloc._bufAlloc<T>(n) : 0;
        int cap = n ? n : 0x80000000;
        m_data = p;
        m_iElementCount = n;
        m_iCapacityState = cap;
        if (n > 0)
        {
            T* e = p;
            do
            {
                new (e) T();
                ++e;
            } while (--n != 0);
        }
    }

    __forceinline ~S_dbf1a0_Array() throw()
    {
        hkTempAlloc& alloc = ((S_dbf1a0_Router*)hkMemoryRouter_getInstance())->heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc._bufFree<T>(m_data, m_iCapacityState & 0x3fffffff);
    }
};
struct S_dbf1a0_Writer
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    S_dbf1a0_Map m_map;

    void __thiscall WriteVarint(__int64 val) throw();
    void __thiscall WriteString(const char* str) throw();
    int WriteHandle(const S_dbf1a0_Handle& h) throw();
};
class hkMemoryAllocatorDBE8;
struct hkPairKeyDBE8
{
    unsigned int m_k1;
    unsigned int m_k2;
    bool operator==(const hkPairKeyDBE8& o) const
    {
        return m_k1 == o.m_k1 && m_k2 == o.m_k2;
    }
};
struct hkPairMapElemDBE8
{
    hkPairKeyDBE8 m_key;
    unsigned int m_uiFilterValue;
};
class hkPairMapDBE8
{
  public:
    hkPairMapElemDBE8* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    void hkMapBase_struct_hkCppTypeInfoHash_struct_hkRttiParser_Node_const_struct_hkCppTypeInfoHash_resizeTable(hkMemoryAllocatorDBE8& alloc, int iNewCap);
    int InsertOrUpdate(hkMemoryAllocatorDBE8& alloc, hkPairKeyDBE8 key, unsigned int uiValue);
};
struct ObjC;

struct Rec
{
    int key;
    int value;
    int enabled;
    int fourth;
    int fifth;
    Rec() : key(0), value(0), enabled(0), fourth(0), fifth(0)
    {}
};
struct Wrap
{
    void* m_p;
    __declspec(nothrow) int ForwardCall_00dbac10() const;
    __declspec(nothrow) Pair CreateResultPair(int idx) const;
    __declspec(nothrow) Pair UpdateState_00dbab90(int idx) const;
    __declspec(nothrow) int InvokeVirtualMethod_00dbac00() const;
    __declspec(nothrow) void ReleaseStorage_00dbab70();
    __declspec(nothrow) void ReleaseStorage_00dba7f0();
    __declspec(nothrow) ObjC ProcessAndReturnValue_00dbac20() const;
    __declspec(nothrow) void Object_DoNothing_00dba660();
    __declspec(nothrow) Wrap InvokeCallbackInto(int v) const;
    ~Wrap()
    {
        ReleaseStorage_00dbab70();
    }
};
struct Node50
{
    int m_00;
    int m_04;
    int m_08;
    float m_0c;
};

struct ObjC
{
    void* m_00;
    __declspec(nothrow) int ForwardCall_00dba730();
    __declspec(nothrow) void DispatchItems(hkArrayBase<Rec>& a);
    __declspec(nothrow) void Object_DoNothing_00dba660();
    ~ObjC()
    {
        Object_DoNothing_00dba660();
    }
};
struct __declspec(align(8)) Obj2
{
    char* m_00;
    int m_04;
    int m_08;
    __declspec(nothrow) void FUN_00dbef20(int n);
    __declspec(nothrow) void PackBitsToBytes(void* data);
};
struct AllocV
{
    virtual void u0();
    virtual void u1();
    virtual void u2();
    virtual void* AllocBytes(int* psize);
    virtual void Free(void* p, unsigned int size);
};
static __forceinline Rec* allocateRecords(AllocV* allocator, int& capacity)
{
    if (capacity)
    {
        int bytes = capacity * (int)sizeof(Rec);
        Rec* data = (Rec*)allocator->AllocBytes(&bytes);
        capacity = bytes / (int)sizeof(Rec);
        return data;
    }
    return 0;
}
__forceinline void initializeRecords(hkArrayBase<Rec>& out,int n)
{
    int capacity = n;
    out.m_data = 0;
    out.m_iElementCount = 0;
    out.m_iCapacityState = (int)0x80000000;
    BSAudio* router = hkMemoryRouter_getInstance();
    AllocV* allocator = (AllocV*)&((hkMemoryRouter*)router)->temp();
    Rec* data = allocateRecords(allocator, capacity);
    int flags = capacity ? capacity : (int)0x80000000;
    out.m_data = data;
    out.m_iElementCount = capacity;
    out.m_iCapacityState = flags;
    for (int k = 0; k < capacity; ++k)
        new (data + k) Rec;
}
extern "C" void __cdecl hkArrayUtil__reserve(void* owner, hkArrayBase<Rec>* arr, int newCap, int stride);
struct Host
{
    __declspec(nothrow) void WriteArray(const Wrap& arg0, int count);
    __declspec(nothrow) void hkOArchive_write8u(int v);
    __declspec(nothrow) void WriteVarint(__int64 v);
    __declspec(nothrow) void HashUInt(float f);
    __declspec(nothrow) void WriteFloatArray(void* p, int v);
    __declspec(nothrow) void ProcessEntries_00dc00b0(const StringHandle& v);
    __declspec(nothrow) void WriteString(int v);
    __declspec(nothrow) void hkOArchive_writeRaw(void* p, int n);
    __declspec(nothrow) int IsTruthy(Pair* p);
};
struct S_00dbfef0_A;
struct S_00dbfef0_B;
struct S_00dbfef0_X
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};
struct S_00dbfef0_Node
{
    int QueryAndWriteResult();
    int ForwardCall_00dba990();
    float InvokeVirtualMethod_00dbaa00();
    int DispatchToInterface(int n);
    int hkDataObject_Value_asString();
    int GetWrappedDataObject(S_00dbfef0_B* out);
    void GetResult(S_00dbfef0_A* out);
};
struct S_00dbfef0_B
{
    S_00dbfef0_X* p;
    void ReleaseStorage_00dba7f0();
    int hkDataClass_getName();
    void Object_DoNothing_00dba660();
};
struct S_00dbfef0_A
{
    S_00dbfef0_Node* p;
    int InvokeVirtualMethod_00dbac00();
    int ForwardCall_00dbac10();
    void ProcessAndReturnValue_00dbac20(S_00dbfef0_B* b);
    void ReleaseStorage_00dbab70();
};
struct S_00dbfef0_Sub
{
    int GetValue(int a, int b);
};
struct S_00dbfef0_Visitor
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    S_00dbfef0_Sub m_sub;
    void hkOArchive_write8u(int v);
    void HashUInt(float v);
    void WriteFloatArray(int p, int n);
    void WriteVarint(__int64 v);
    void WriteString(int v);
    void WriteArray(S_00dbfef0_A* a, int n);
    void ProcessEntries_00dc00b0(int v);
    void WriteNode(S_00dbfef0_Node* node, S_00dbfef0_B b);
};

struct ObjImpl;
struct ObjHandle
{
    ObjImpl* p0;
    ObjImpl* p1;
};
struct DataObj
{
    ObjImpl* m_pClassImpl;
    DataObj(ObjImpl* impl);
    DataObj(const DataObj& o);
    ~DataObj();
    int GetObjectKind() const;
    ObjHandle GetObjectHandle() const;
    bool IsStreamValid(const DataObj& src) const;
    static void* operator new(unsigned int n);
};
struct DataWorld
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual DataObj CopyContents(const DataObj& src);
};
struct BlockAlloc
{
    virtual void v00();
    virtual void* AllocateMemoryBlock(int numBytes);
};
struct ContainerHeap;
struct MemRouter
{
    int unk00, unk04, unk08;
    ContainerHeap* m_pStreamAllocator;
    BlockAlloc* m_block;
    ContainerHeap& heap()
    {
        return *m_pStreamAllocator;
    }
    BlockAlloc& block()
    {
        return *m_block;
    }
};
__forceinline MemRouter& router()
{
    return *(MemRouter*)hkMemoryRouter_getInstance();
}
void __cdecl ResizeAudioStream(ContainerHeap& heap, void* arr, int elemSize);
struct HandleMap
{
    int m_kPrimitiveElement, m_iCapacityFlags, m_iPairCount;
    int FindValueForKey(ObjHandle key, int def) const;
    void insert(BlockAlloc& a, ObjImpl* key0, ObjImpl* key1, int val);
    __forceinline void insert(ObjHandle key, int val)
    {
        insert(router().block(), key.p0, key.p1, val);
    }
};
template <typename T> __forceinline void constructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}
template <typename T> struct PtrArrayLocalForm
{ // local form of hkArray: 0x00dbedd0 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline void AddBack(const T& t)
    {
        ContainerHeap& h = router().heap();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(h, this, sizeof(T));
        constructWithCopy(m_data + m_iElementCount++, 1, t);
    }
};
__forceinline void* DataObj::operator new(unsigned int n)
{
    return router().block().AllocateMemoryBlock(n);
}
struct ObjCloner
{
    DataWorld* m_pOwningWorld;
    HandleMap m_kHandleMap;
    PtrArrayLocalForm<DataObj*> m_objs;
    DataObj AllocateStorage_00dbedd0(const DataObj& src);
};
// @fnv 0x00dbedd0
// src: GUESS 0x00dbedd0 (confidence: low)
DataObj ObjCloner::AllocateStorage_00dbedd0(const DataObj& src)
{
    if (m_pOwningWorld && !src.GetObjectKind())
    {
        ObjHandle h = src.GetObjectHandle();
        int idx = m_kHandleMap.FindValueForKey(h, -1);
        if (idx == -1)
        {
            DataObj dst = m_pOwningWorld->CopyContents(src);
            if (dst.IsStreamValid(src))
            {
                m_kHandleMap.insert(h, m_objs.GetLogicalSize());
                m_objs.AddBack(new DataObj(dst));
                return dst;
            }
        }
        else
        {
            return DataObj(m_objs[idx]->m_pClassImpl);
        }
    }
    return src;
}
