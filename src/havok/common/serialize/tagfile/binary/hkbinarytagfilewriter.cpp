#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/BSAudio.h"
#include "../../../../../../include/Pair.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkArray.h"

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
// @fnv 0x00dc0380
FUN_00dc0380::FUN_00dc0380(BSAudio* pAudio)
{
    p = pAudio;
    UnkHolder* h = &unk;
    h->a = 0;
    h->b = 0;
    h->c = -1;
    BSAudio* r = hkMemoryRouter_getInstance();
    h->ProcessEntries_00dbedb0(reinterpret_cast<UnkRet*>(*(reinterpret_cast<int**>(r) + 4)), 0);
    a = 0;
    b = 0;
    c = 0x80000000;
}

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
// @fnv 0x00dbeab0
int __stdcall IsTruthy(Value* value)
{
    if (value->InvokeVirtualMethod_00dbac40() >= 16)
        return value->GetMemberArrayValue().InvokeVirtualMethod_00dbac00();
    switch (value->InvokeVirtualMethod_00dbac40())
    {
    case 0:
        return 0;
    case 1:
    case 2:
        return value->CallVirtualWithArg() != 0;
    case 3:
        return value->ApplyValue() != 0.0f;
    case 4:
    case 6:
    case 7:
        return 1;
    case 8:
    case 9:
        return value->CreateValueInto().hkDataObject_isNull() == 0;
    case 16:
        return value->GetMemberArrayValue().InvokeVirtualMethod_00dbac00() != 0;
    case 10:
        return value->ForwardCall_00dbac70() != 0;
    default:
        return 0;
    }
}

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
// @fnv 0x00dbebe0
void* AudioResourceState::ResolveSound(Receiver* receiver, Description* description)
{
    ResourceKey key;
    if (active && !description->FUN_009ba980())
    {
        description->FUN_009ba810(&key);
        int index = lookup.FUN_009be8c0(key.first, key.second, -1);
        if (index != -1)
        {
            receiver->FUN_009ba760(entries[index]->sound);
            return receiver;
        }
    }
    receiver->FUN_009ba780(description);
    return receiver;
}



inline hkMemoryRouter* audio()
{
    return (hkMemoryRouter*)hkMemoryRouter_getInstance();
}

void __cdecl hkArrayUtil__reserve(hkMemoryAllocator& alloc, void* arr, int numElem, int sizeElem);
void* __cdecl _fnv_zlib_memset(void* dst, int val, int n);

// LocalhkCharArray: include/hkCharArray.h gives an inline constructor and an out-of-line destructor and declares
// reserve/SetSizeAndGrow out of line; 0x00dbef20 and this unit's writers inline them and run no constructor/destructor.
struct LocalhkCharArray
{
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void reserve(int n)
    {
        hkMemoryAllocator& alloc = audio()->temp();
        if (getCapacity() < n)
        {
            int cap = 2 * getCapacity();
            hkArrayUtil__reserve(alloc, this, n < cap ? cap : n, 1);
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(n);
        char* p = m_data + m_iElementCount;
        int num = n - m_iElementCount;
        if (num <= 0)
        {
            m_iElementCount = n;
            return;
        }
        _fnv_zlib_memset(p, 0, num);
        m_iElementCount = n;
    }
    __forceinline void setSizeUnchecked(int n)
    {
        reserve(n);
        m_iElementCount = n;
    }
};

struct FUN_00dbef20 : LocalhkCharArray
{
    FUN_00dbef20(int n);
};

// Initializes the char array to empty, reserves capacity rounded up to a multiple of 8, then sets the size to n.
// @fnv 0x00dbef20
FUN_00dbef20::FUN_00dbef20(int aiSize)
{
    m_data = 0;
    m_iElementCount = 0;
    m_iCapacityState = 0x80000000;
    SetSizeAndGrow((aiSize + 7) & ~7);
    setSizeUnchecked(aiSize);
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

// @fnv 0x00dc03d0
void FUN_00dc03d0_cls::ClearArray()
{
    for (int i = 0; i < m_iArrayLength; i++)
    {
        Element* pElement = m_ppArray[i];
        if (pElement)
        {
            pElement->ReleaseStorage_00dba7f0();
            hkMemoryRouter* pAllocHolder = (hkMemoryRouter*)hkMemoryRouter_getInstance();
            hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pAllocHolder->m_heap);
            reinterpret_cast<hkMemoryAllocator*>(pAllocator)->blockFree(pElement, 4);
        }
    }

    hkMemoryRouter* pArrayHolder = (hkMemoryRouter*)hkMemoryRouter_getInstance();
    ArrayDeallocator* pDealloc = reinterpret_cast<ArrayDeallocator*>(pArrayHolder->m_temp);
    unsigned int uCapacity = m_uCapacity;
    m_iArrayLength = 0;
    if ((uCapacity & 0x80000000) == 0)
        pDealloc->FreeArray(m_ppArray, (uCapacity & 0x3fffffff) * 4);

    m_ppArray = 0;
    m_uCapacity = 0x80000000;

    hkMemoryRouter* pSubHolder = (hkMemoryRouter*)hkMemoryRouter_getInstance();
    hkMemoryAllocator* pSubAllocator = reinterpret_cast<hkMemoryAllocator*>(pSubHolder->m_heap);
    m_kSub.AllocBufferIfNotFlagged(pSubAllocator);
}

namespace fnv_00dc0460 {


BSAudio* __cdecl hkMemoryRouter_getInstance();
inline hkMemoryRouter* audio()
{
    return (hkMemoryRouter*)hkMemoryRouter_getInstance();
}

struct Elem24
{
    int v[6];
};

}  // namespace fnv_00dc0460
// hkContainerTempAllocator::get: the temp allocator of the memory router.
__forceinline hkMemoryAllocator& hkContainerTempAllocator::get(void*)
{
    return fnv_00dc0460::audio()->temp();
}
template <typename T> __forceinline void hkArrayBase<T>::clear()
{
    m_iElementCount = 0;
}
template <typename T> __forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& alloc)
{
    clear();
    if ((m_iCapacityState & 0x80000000) == 0)
    {
        alloc.bufFree(m_data, getCapacity() * sizeof(T));
    }
    m_data = 0;
    m_iCapacityState = 0x80000000;
}
namespace fnv_00dc0460 {

struct MemberA
{
    int pad[4];
    void FreeBuffer();
};
struct MemberB
{
    int pad[3];
    void AllocBufferIfNotFlagged(hkMemoryAllocator* alloc);
};
struct MemberC
{
    void ClearArray();
};

struct BaseObj
{
    int pad[4];
    void ReleaseReference_00d60590();
};

struct Obj : BaseObj
{
    MemberA m10;
    MemberA m20;
    int unk30;
    MemberB m34;
    hkArray<char, hkContainerTempAllocator> m40;
    hkArray<Elem24, hkContainerTempAllocator> m4c;
    MemberC m58;
    void ProcessState_00dc0460();
};

// @fnv 0x00dc0460
// src: GUESS 0x00dc0460 (confidence: low)
void Obj::ProcessState_00dc0460()
{
    m58.ClearArray();
    m4c.clearAndDeallocate();
    m40.clearAndDeallocate();
    m34.AllocBufferIfNotFlagged(&audio()->heap());
    m20.FreeBuffer();
    m10.FreeBuffer();
    ReleaseReference_00d60590();
}
}  // namespace fnv_00dc0460

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
// @fnv 0x00dc05b0
int __stdcall WriteAudioObject(int value, CallbackTarget* target, int source)
{
    FUN_00dc05b0_writer writer;
    writer.FUN_00dc0500((int)target, source);
    writer.WriteInt(0xcab00d1e);
    writer.WriteInt(0xd011face);
    writer.WriteVarint(1, 0);
    writer.WriteVarint(0, 0);
    writer.WriteReferencedObjectRecursively(value, 0);
    writer.ProcessEntries_00dc00b0(value);
    target->Complete();
    writer.ProcessState_00dc0460();
    return 0;
}

struct Obj
{
    void __thiscall hkOArchive_write8u(unsigned char);
    void __thiscall WriteVarint(__int64);
};

// @fnv 0x00dbe790
void __thiscall Obj::WriteVarint(__int64 value)
{
    unsigned __int64 u;

    if (value < 0)
    {
        __int64 t = -value;
        u = ((unsigned __int64)t << 1) | 1ULL;
    }
    else
    {
        u = (unsigned __int64)value << 1;
    }

    unsigned char byte = (unsigned char)(u & 0x7f);
    u >>= 7;

    if (u != 0)
    {
        do
        {
            this->hkOArchive_write8u((unsigned char)(byte | 0x80));
            byte = (unsigned char)(u & 0x7f);
            u >>= 7;
        } while (u != 0);
    }

    this->hkOArchive_write8u(byte);
}

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

// Looks up the entry matching aKey0 and aKey1 in the open-addressed hash table and returns its value, or aDefault if not found.
// @fnv 0x00dbe8c0
unsigned int FUN_00dbe8c0_cls::FindEntryValue(unsigned int aKey0, unsigned int aKey1, unsigned int aDefault)
{
    unsigned int mask = m_uMask;
    if ((int)mask > 0)
    {
        unsigned int idx = ((aKey0 >> 4) * 0x9e3779b1u) & mask;
        if (m_pEntries[idx].key0 != 0)
        {
            for (;;)
            {
                HashEntry* e = &m_pEntries[idx];
                if (e->key0 == aKey0 && e->key1 == aKey1)
                {
                    return m_pEntries[idx].value;
                }
                idx = (idx + 1) & mask;
                if (m_pEntries[idx].key0 == 0)
                {
                    break;
                }
            }
        }
    }
    return aDefault;
}

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

// Clears the key field of every entry of the table (the table holds
// @fnv 0x00dbe920
void HashTableBase::ClearEntries()
{
    int n = m_uiItemCount + 1;
    for (int i = 0; i < n; i++)
        m_entries[i].unk00 = 0;
    m_flags &= 0x80000000;
}

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

// @fnv 0x00dbe950
void FUN_00dbe950_cls::AllocBufferIfNotFlagged(AudioIface* apIface)
{
    ClearEntries();
    if ((m_04 & 0x80000000u) == 0)
    {
        unsigned int uCount = m_08 + 1;
        apIface->Alloc(m_00, uCount * 12u);
    }
}

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

// @fnv 0x00dbec60
// src: HAVOK_LIB 0x00dbec60
void FUN_00dbec60_cls::hkMapBase_struct_hkCppTypeInfoHash_struct_hkRttiParser_Node_const_struct_hkCppTypeInfoHash_resizeTable(AllocOwner* alloc, int count)
{
    int newCap = count;
    if (newCap <= 8)
        newCap = 8;

    unsigned int oldFlags = m_04 & 0x80000000u;
    Entry12* pOldEntries = m_00;
    int oldCount = m_08 + 1;

    m_00 = (Entry12*)alloc->Alloc(newCap * 12);
    for (int i = 0; i < newCap; ++i)
        m_00[i].a = 0;

    m_04 = 0;
    m_08 = newCap - 1;

    for (int i = 0; i < oldCount; ++i)
    {
        if (pOldEntries[i].a == 0)
            continue;
        volatile Entry12* v = pOldEntries;
        reinterpret_cast<FUN_00dbe810_cls*>(this)->InsertOrUpdate(alloc, v[i].a, v[i].b, v[i].c);
    }

    if (oldFlags == 0)
        alloc->Free(pOldEntries, oldCount * 12);
}

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

// Writes a string to the stream: emits its length and bytes if new, otherwise emits the negated existing index; null writes -1.
// @fnv 0x00dbed30
void DBED30Writer::WriteString(const char* pcString)
{
    if (pcString)
    {
        int index = m_pStringFunctions.FindValueForKey(pcString, -1);
        if (index == -1)
        {
            int len = hkString_strLen(pcString);
            WriteSigned64BitInteger(len);
            WriteByteArray(pcString, len);
            m_pStringFunctions.insert(pcString, m_pStringFunctions.m_iCapacityFlags + 1);
        }
        else
        {
            WriteSigned64BitInteger(-index);
        }
    }
    else
    {
        WriteSigned64BitInteger(-1);
    }
}

struct S_dbefc0_Heap
{
    int unk;
};
struct S_dbefc0_Router
{
    int unk00;
    int unk04;
    int unk08;
    S_dbefc0_Heap* unk0c;
    S_dbefc0_Heap& heap()
    {
        return *unk0c;
    }
};
void __cdecl hkArrayUtil__reserve(S_dbefc0_Heap* heap, void* arr, int n, int elemSize);
void* __cdecl FUN_00ec61c0(void* dst, int value, unsigned int count);

static __forceinline S_dbefc0_Heap& S_dbefc0_GetHeap()
{
    return ((S_dbefc0_Router*)hkMemoryRouter_getInstance())->heap();
}

struct S_dbefc0_Bytes
{
    char* data;
    int size;
    int cap;

    __forceinline void GrowArrayCapacity(S_dbefc0_Heap& heap, int n)
    {
        int c = cap & 0x3fffffff;
        if (c < n)
        {
            int c2 = c + c;
            hkArrayUtil__reserve(&heap, this, (n < c2) ? c2 : n, 1);
        }
    }
    __forceinline void _setSize(S_dbefc0_Heap& heap, int n)
    {
        GrowArrayCapacity(heap, n);
        char* p = data + size;
        int diff = n - size;
        if (diff <= 0)
        {
            size = n;
            return;
        }
        FUN_00ec61c0(p, 0, diff);
        size = n;
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        _setSize(S_dbefc0_GetHeap(), n);
    }
    __forceinline void trim(int n)
    {
        GrowArrayCapacity(S_dbefc0_GetHeap(), n);
        size = n;
    }
    void ProcessEntries_00dbefc0(const unsigned char* bytes, int count);
};

// @fnv 0x00dbefc0
// src: GUESS 0x00dbefc0 (confidence: low)
void S_dbefc0_Bytes::ProcessEntries_00dbefc0(const unsigned char* bytes, int count)
{
    int oldSize = size;
    SetSizeAndGrow((oldSize + 7) & ~7);
    int iOffset = 0;
    for (int i = 0; i < count; i++)
    {
        unsigned char b = bytes[i];
        data[iOffset + 0] = b & 1;
        b >>= 1;
        data[iOffset + 1] = b & 1;
        b >>= 1;
        data[iOffset + 2] = b & 1;
        b >>= 1;
        data[iOffset + 3] = b & 1;
        b >>= 1;
        data[iOffset + 4] = b & 1;
        b >>= 1;
        data[iOffset + 5] = b & 1;
        b >>= 1;
        data[iOffset + 6] = b & 1;
        b >>= 1;
        data[iOffset + 7] = b & 1;
        iOffset += 8;
    }
    trim(oldSize);
}

struct Rec_00dbf0d0
{
    unsigned char* unk00;  // data buffer
    int unk04;             // used size
    int unk08;             // capacity (low 30 bits) + flags
    void __thiscall PackBitsToBytes(unsigned char* dest);
};

void __cdecl fnv_grow_00c908c0(int audioD, Rec_00dbf0d0* self, int newCap, int flag);
void __cdecl fnv_memset_00ec61c0(void* dest, int ch, int count);

// @fnv 0x00dbf0d0
void __thiscall Rec_00dbf0d0::PackBitsToBytes(unsigned char* dest)
{
    int oldSize = this->unk04;
    int newSize = (oldSize + 7) & 0xfffffff8;

    // make sure the buffer can hold the padded size
    {
        BSAudio* audio = hkMemoryRouter_getInstance();
        int audioD = reinterpret_cast<int>(((hkMemoryRouter*)audio)->m_temp);
        int cap = this->unk08 & 0x3fffffff;
        if (cap < newSize)
        {
            int newCap = cap + cap;
            if (newSize >= newCap)
                newCap = newSize;
            fnv_grow_00c908c0(audioD, this, newCap, 1);
        }
    }

    // zero the region that was just added
    {
        int delta = newSize - this->unk04;
        unsigned char* dst = this->unk00 + this->unk04;
        while (delta > 0)
        {
            int chunk = delta;
            fnv_memset_00ec61c0(dst, 0, chunk);
            dst += chunk;
            delta -= chunk;
        }
    }

    this->unk04 = newSize;

    // pack the low bit of every byte into one byte
    for (int i = 0; i < this->unk04; i += 8)
    {
        unsigned char v = this->unk00[i + 7];
        const unsigned char* p = this->unk00 + i;
        v = (unsigned char)((v << 1) | p[6]);
        v = (unsigned char)((v << 1) | p[5]);
        v = (unsigned char)((v << 1) | p[4]);
        v = (unsigned char)((v << 1) | p[3]);
        v = (unsigned char)((v << 1) | p[2]);
        v = (unsigned char)((v << 1) | p[1]);
        v = (unsigned char)((v << 1) | p[0]);
        *dest++ = v;
    }

    // give the memory back
    {
        BSAudio* audio = hkMemoryRouter_getInstance();
        int audioD = reinterpret_cast<int>(((hkMemoryRouter*)audio)->m_temp);
        int cap = this->unk08 & 0x3fffffff;
        if (cap < oldSize)
        {
            int newCap = cap + cap;
            if (oldSize >= newCap)
                newCap = oldSize;
            fnv_grow_00c908c0(audioD, this, newCap, 1);
        }
    }
    this->unk04 = oldSize;
}

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
// @fnv 0x00dc0500
FUN_00dc0500::FUN_00dc0500(BSAudio* pAudio, BSAudio* a2)
    : FUN_00d60830(pAudio, S_00dc0500_Opt(false)), m_10(S_00dc0500_Flag(false)), m_20(S_00dc0500_Flag(false)), m_30(0),
      m_58(a2)
{
    m_20.hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(&DAT_01011584, 0);
    m_10.hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(&DAT_01011584, 0);
}

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
{ // local form of hkArrayBase: 0x00dbf1a0 needs throw() sized owning construction and S_dbf1a0_Router heap cleanup; the shared base is non-owning.
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

// @fnv 0x00dbf1a0
int S_dbf1a0_Writer::WriteHandle(const S_dbf1a0_Handle& ahHandle) throw()
{
    if (!ahHandle.m_ptr)
    {
        return 0;
    }

    const char* name = ahHandle.hkDataClass_getName();
    int id = m_map.GetValue(name, -1);
    if (id >= 0)
    {
        return id;
    }

    int parentId = WriteHandle(ahHandle.SetShiftedValue());

    name = ahHandle.hkDataClass_getName();
    id = m_map.GetValue(name, -1);
    if (id != -1)
    {
        return id;
    }

    int iContactPointId = m_map.unk04;
    const char* curName = ahHandle.hkDataClass_getName();
    m_map.hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(curName, iContactPointId);
    int count = ahHandle.ForwardCall_00dba6f0();

    S_dbf1a0_Array<S_dbf1a0_Elem> arr(count);
    ahHandle.DispatchRecords(&arr);

    WriteVarint(2);
    WriteString(ahHandle.hkDataClass_getName());
    WriteVarint(ahHandle.ForwardCall_00dba690());
    WriteVarint(parentId);
    WriteVarint(count);

    for (int i = 0; i < count; ++i)
    {
        S_dbf1a0_Elem* elem = &arr.m_data[i];
        WriteString(elem->name);
        WriteVarint(elem->flags);
        if (elem->flags & 0x20)
        {
            WriteVarint(arr.m_data[i].unk10);
        }
        int type = elem->flags & 0xf;
        if (type == 9 || type == 8)
        {
            if (elem->sub)
            {
                WriteString(S_dbf1a0_Handle(elem->sub).hkDataClass_getName());
            }
            else
            {
                WriteVarint(-1LL);
            }
        }
    }

    for (int i = 0; i < count; ++i)
    {
        void* sub = arr.m_data[i].sub;
        if (sub)
        {
            WriteHandle(S_dbf1a0_Handle(sub));
        }
    }

    return iContactPointId;
}

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

// Grows the map if needed, finds the slot for key via open addressing, stores uiValue, and returns 1 if the key was newly inserted.
// @fnv 0x00dbe810
int hkPairMapDBE8::InsertOrUpdate(hkMemoryAllocatorDBE8& alloc, hkPairKeyDBE8 key, unsigned int uiValue)
{
    if ((m_iCapacityFlags & 0x7fffffff) * 2 > m_iPairCount)
        hkMapBase_struct_hkCppTypeInfoHash_struct_hkRttiParser_Node_const_struct_hkCppTypeInfoHash_resizeTable(alloc, m_iPairCount * 2 + 2);

    unsigned int i = ((key.m_k1 >> 4) * 0x9e3779b1) & m_iPairCount;
    int isNewKey = 1;
    while (m_kPrimitiveElement[i].m_key.m_k1 != 0)
    {
        if (m_kPrimitiveElement[i].m_key == key)
        {
            isNewKey = 0;
            break;
        }
        i = (i + 1) & m_iPairCount;
    }
    m_iCapacityFlags += isNewKey;
    m_kPrimitiveElement[i].m_key = key;
    m_kPrimitiveElement[i].m_uiFilterValue = uiValue;
    return isNewKey;
}

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
    AllocV* allocator = (AllocV*)((hkMemoryRouter*)router)->m_temp;
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
// Dispatches on the wrapper's type value and writes values or packed member data to the host.
// @fnv 0x00dbf930
void Host::WriteArray(const Wrap& arg0, int count)
{
    long i;
    if (arg0.ForwardCall_00dbac10() & 0x20)
    {
        for (i = 0; i < count; i++)
        {
            Wrap j = arg0.CreateResultPair(i).GetMemberArrayValue();
            int n = j.InvokeVirtualMethod_00dbac00();
            WriteArray(j, n);
        }
        return;
    }
    switch (arg0.ForwardCall_00dbac10())
    {
    case 0:
        return;
    case 5:
        return;
    case 1: {
        for (i = 0; i < count; i++)
        {
            hkOArchive_write8u(arg0.CreateResultPair(i).CallVirtualWithArg());
        }
    }
    break;
    case 2: {
        for (i = 0; i < count; i++)
        {
            WriteVarint((__int64)arg0.CreateResultPair(i).CallVirtualWithArg());
        }
    }
    break;
    case 3: {
        for (i = 0; i < count; i++)
        {
            float fValue = arg0.CreateResultPair(i).ApplyValue();
            HashUInt(fValue);
        }
    }
    break;
    case 4: {
        int n = count;
        int mode = 3;
        int i;
        for (i = 0; i < n; i++)
        {
            Node50* pNode = arg0.CreateResultPair(i).DispatchToVTableSlot8(4);
            if (pNode->m_0c != 0.0f)
            {
                mode = 4;
                break;
            }
        }
        WriteVarint((__int64)mode);
        for (i = 0; i < n; i++)
        {
            Node50* value = arg0.CreateResultPair(i).DispatchToVTableSlot8(4);
            WriteFloatArray(value, mode);
        }
    }
    break;
    case 6:
    case 7: {
        int t = arg0.ForwardCall_00dbac10();
        int off = 4 * t - 12;
        for (i = 0; i < count; i++)
        {
            Node50* value = arg0.CreateResultPair(i).DispatchToVTableSlot8(off);
            WriteFloatArray(value, off);
        }
    }
    break;
    case 9: {
        Obj2 packedBits;
        int iCount = arg0.ProcessAndReturnValue_00dbac20().ForwardCall_00dba730();
        hkArrayBase<Rec> items;
        initializeRecords(items,iCount);
        arg0.ProcessAndReturnValue_00dbac20().DispatchItems(items);
        packedBits.FUN_00dbef20(iCount);
        for (int idx = 0; idx < iCount; idx++)
        {
            Rec* r = (Rec*)((char*)items.m_data + idx * 20);

            if (r->enabled != 0)
            {
                Wrap w9 = arg0.InvokeCallbackInto(r->key);
                int buf = w9.InvokeVirtualMethod_00dbac00();
                for (int j = 0; j < buf; j++)
                {
                    if (IsTruthy(&w9.UpdateState_00dbab90(j)) != 0)
                    {
                        packedBits.m_00[idx] = 1;
                        break;
                    }
                    buf = w9.InvokeVirtualMethod_00dbac00();
                }
            }
        }
        LocalhkCharArray m;
        m.m_data = 0;
        m.m_iElementCount = 0;
        m.m_iCapacityState = (int)0x80000000;
        int need = ((packedBits.m_04 + 7) & ~7) / 8;
        m.setSizeUnchecked(need);
        packedBits.PackBitsToBytes(m.m_data);
        hkOArchive_writeRaw(m.m_data, m.m_iElementCount);
        {
            BSAudio* pRouter = hkMemoryRouter_getInstance();
            AllocV* pAllocator = (AllocV*)(void*)((hkMemoryRouter*)pRouter)->m_temp;
            long cap2 = m.m_iCapacityState;
            m.m_iElementCount = 0;
            if ((cap2 & 0x80000000u) == 0)
                pAllocator->Free(m.m_data, cap2 & 0x3fffffff);
        }
        {
            for (i = 0; i < iCount; i++)
            {
                if (packedBits.m_00[i] != 0)
                {
                    Rec* r;
                    r = (Rec*)((char*)items.m_data + i * 20);

                    Wrap w9b = arg0.InvokeCallbackInto(r->key);
                    WriteArray(w9b, count);
                }
            }
        }
        {
            BSAudio* sn = hkMemoryRouter_getInstance();
            AllocV* mn = (AllocV*)(void*)((hkMemoryRouter*)sn)->m_temp;
            int cap = packedBits.m_08;
            packedBits.m_04 = 0;
            if ((cap & 0x80000000u) == 0)
                mn->Free(packedBits.m_00, cap & 0x3fffffff);
            packedBits.m_00 = 0;
            packedBits.m_08 = (int)0x80000000;
        }
        {
            BSAudio* s4 = hkMemoryRouter_getInstance();
            AllocV* mgr4 = (AllocV*)(void*)((hkMemoryRouter*)s4)->m_temp;
            long cap1 = items.m_iCapacityState;
            items.m_iElementCount = 0;
            if ((cap1 & 0x80000000u) == 0)
                mgr4->Free(items.m_data, (cap1 & 0x3fffffff) * 20);
        }
    }
    break;
    case 8: {
        for (i = 0; i < count; i++)
        {
            ProcessEntries_00dc00b0(arg0.CreateResultPair(i).CreateValueInto());
        }
    }
    break;
    case 10: {
        for (i = 0; i < count; i++)
        {
            WriteString(arg0.CreateResultPair(i).ForwardCall_00dbac70());
        }
    }
    break;
    default:
        break;
    }
}

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

// Writes a node's result to the visitor's output stream, dispatching on the result type to emit varints, floats, strings, or nested values.
// @fnv 0x00dbfef0
void S_00dbfef0_Visitor::WriteNode(S_00dbfef0_Node* node, S_00dbfef0_B b)
{
    if (node->QueryAndWriteResult() & 0x20)
    {
        S_00dbfef0_A a;
        node->GetResult(&a);
        WriteArray(&a, a.InvokeVirtualMethod_00dbac00());
        a.ReleaseStorage_00dbab70();
        return;
    }
    if (node->QueryAndWriteResult() & 0x10)
    {
        S_00dbfef0_A a;
        node->GetResult(&a);
        int n = a.InvokeVirtualMethod_00dbac00();
        WriteVarint(n);
        if (a.ForwardCall_00dbac10() == 9 && b.p->unk0C == 0)
        {
            a.ProcessAndReturnValue_00dbac20(&b);
            int v = b.hkDataClass_getName();
            int r = m_sub.GetValue(v, 0);
            WriteVarint(r);
            b.Object_DoNothing_00dba660();
        }
        WriteArray(&a, n);
        a.ReleaseStorage_00dbab70();
        return;
    }
    switch (node->QueryAndWriteResult())
    {
    case 1:
        hkOArchive_write8u(node->ForwardCall_00dba990());
        break;
    case 2:
        WriteVarint(node->ForwardCall_00dba990());
        break;
    case 3: {
        float f = node->InvokeVirtualMethod_00dbaa00();
        HashUInt(f);
    }
    break;
    case 4:
    case 6:
    case 7: {
        int n = node->QueryAndWriteResult() * 4 - 12;
        int p = node->DispatchToInterface(n);
        WriteFloatArray(p, n);
        break;
    }
    case 8:
    case 9:
        ProcessEntries_00dc00b0(node->GetWrappedDataObject(&b));
        b.ReleaseStorage_00dba7f0();
        break;
    case 10:
        WriteString(node->hkDataObject_Value_asString());
        break;
    }
}

struct HkNodeE980
{
    int QueryAndWriteResult();
    int ForwardCall_00dba990();
    int hkDataObject_Value_asString();
    float InvokeVirtualMethod_00dbaa00();
    __declspec(nothrow) StringHandle GetWrappedDataObject();
    __declspec(nothrow) ObjectHandle GetResult();
};
// Evaluates a node by dispatching on its type code and returning the corresponding boolean result.
// @fnv 0x00dbe980
int __stdcall EvaluateNode(HkNodeE980* node)
{
    if (node->QueryAndWriteResult() >= 0x10)
    {
        return node->GetResult().InvokeVirtualMethod_00dbac00();
    }
    switch (node->QueryAndWriteResult())
    {
    case 0:
        return 0;
    case 1:
    case 2:
        return node->ForwardCall_00dba990() != 0;
    case 3:
        return node->InvokeVirtualMethod_00dbaa00() != 0.0f;
    case 4:
    case 6:
    case 7:
        return 1;
    case 8:
    case 9:
        return node->GetWrappedDataObject().hkDataObject_isNull() == 0;
    case 16:
        return node->GetResult().InvokeVirtualMethod_00dbac00() != 0;
    case 10:
        return node->hkDataObject_Value_asString() != 0;
    }
    return 0;
}

typedef unsigned int size_t;
struct __declspec(nothrow) IHeap
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void* AllocateBufferWithSize(int* pBytes);
    virtual void ReleaseBlock(void* p, int n);
};
inline __declspec(nothrow) IHeap& myAlloc()
{
    typedef BSAudio*(__cdecl * GetAudioFn)();
    GetAudioFn fn = (GetAudioFn)hkMemoryRouter_getInstance;
    hkMemoryRouter* mgr = (hkMemoryRouter*)fn();
    return *(IHeap*)mgr->m_temp;
}
struct FUN_00dba650
{
    void* object;
    __declspec(nothrow) FUN_00dba650()
    {}
    __declspec(nothrow) ~FUN_00dba650()
    {
        Object_DoNothing_00dba660();
    }
    __declspec(nothrow) void __thiscall Object_DoNothing_00dba660();
    __declspec(nothrow) int __thiscall ForwardCall_00dba730();
    __declspec(nothrow) void __thiscall DispatchItems(void* arr);
};
struct MyDesc
{
    void* object;
    __declspec(nothrow) MyDesc()
    {
        object = 0;
    }
    __declspec(nothrow) ~MyDesc()
    {
        ReleaseStorage_00dba7f0();
    }
    __declspec(nothrow) int __thiscall hkDataObject_isNull();
    __declspec(nothrow) void __thiscall ReleaseStorage_00dba7f0();
    __declspec(nothrow) ResourceKey __thiscall GetSourcePair();
    __declspec(nothrow) FUN_00dba650 __thiscall GetObjectValue();
    __declspec(nothrow) ResourceKey __thiscall Get_Thunk(int id);
};
struct AudioResourceState2
{
    __declspec(nothrow) MyDesc __thiscall ResolveSound(MyDesc* obj);
};
struct MyHolder
{
    __declspec(nothrow) int __thiscall FindEntryValue(ResourceKey key, int aDefault);
};
struct Entry24
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};
struct Struct20
{
    int a;
    int b;
    int c;
    int d;
    int e;
    __forceinline __declspec(nothrow) Struct20() : a(0), b(0), c(0), d(0), e(0)
    {}
};
struct MyCharArray : FUN_00dbef20
{
    int unk0c;
    __declspec(nothrow) MyCharArray(int n) : FUN_00dbef20(n)
    {}
    __declspec(nothrow) void __thiscall ProcessEntries_00dbefc0(const void* bytes, int count);
    __forceinline __declspec(nothrow) ~MyCharArray()
    {
        IHeap& heap = myAlloc();
        int cap = m_iCapacityState;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
        {
            heap.ReleaseBlock(m_data, cap & 0x3fffffff);
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};
struct TempArrLocalForm
{ // local form of hkArray: 0x00dc00b0 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline __declspec(nothrow) TempArrLocalForm(char* data, int size, int capacity)
        : m_data(data), m_iElementCount(size), m_iCapacityState(capacity | 0x80000000)
    {}

    __forceinline __declspec(nothrow) ~TempArrLocalForm()
    {
        IHeap& heap = myAlloc();
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            heap.ReleaseBlock(m_data, m_iCapacityState & 0x3fffffff);
        }
    }
};
struct Array20
{ // local form of hkArrayBase: 0x00dc00b0 needs nothrow 20-byte element allocation and IHeap cleanup with reset ordering.
    Struct20* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline __declspec(nothrow) Array20() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}

    static __forceinline __declspec(nothrow) Struct20* allocate(IHeap& heap, int& n)
    {
        if (n)
        {
            int bytes = n * 20;
            Struct20* p = (Struct20*)heap.AllocateBufferWithSize(&bytes);
            n = bytes / 20;
            return p;
        }
        return 0;
    }
    __forceinline __declspec(nothrow) Array20(int n) : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {
        IHeap& heap = myAlloc();
        Struct20* data = allocate(heap, n);
        int capacity = n ? n : 0x80000000;
        setData(data, n, capacity);
        for (int i = 0; i < n; ++i)
        {
            new (data + i) Struct20();
        }
    }

    __forceinline __declspec(nothrow) void setData(Struct20* data, int n, int capacity)
    {
        m_data = data;
        m_iElementCount = n;
        m_iCapacityState = capacity;
    }

    __forceinline __declspec(nothrow) ~Array20()
    {
        IHeap& heap = myAlloc();
        int cap = m_iCapacityState;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
        {
            heap.ReleaseBlock(m_data, (cap & 0x3fffffff) * 20);
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};
struct FUN_00d607b0_s
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    __declspec(nothrow) void __thiscall writeVec(int a, int b);
};
struct ResourceWriter : FUN_00d607b0_s
{
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    int m_30;
    FUN_00dbe8c0_cls m_34;
    S_00dc0500_Arr m_40;
    S_00dc0500_Arr m_4c;
    AudioResourceState2 m_58;
    int unk5c, unk60, unk64, unk68, unk6c;

    __declspec(nothrow) void __thiscall WriteVarint(__int64 val);
    __declspec(nothrow) int __thiscall WriteHandle(FUN_00dba650* h);
    __declspec(nothrow) void __thiscall WriteNode(ResourceKey* key, Struct20* item);

    __declspec(nothrow) void __thiscall ProcessEntries_00dc00b0(MyDesc* input);
};
// Resolves a sound, writes a varint tag, handle, and per-item resource keys to the resource stream.
// @fnv 0x00dc00b0
// src: GUESS 0x00dc00b0 (confidence: low)
void __thiscall ResourceWriter::ProcessEntries_00dc00b0(MyDesc* apSoundDesc)
{
    MyDesc desc = m_58.ResolveSound(apSoundDesc);
    if (desc.hkDataObject_isNull())
    {
        WriteVarint(6);
        return;
    }

    int iEntryIndex = ((MyHolder*)&m_34)->FindEntryValue(desc.GetSourcePair(), -1);
    Entry24* kIter = &((Entry24*)m_4c.a)[iEntryIndex];
    if (kIter->unk04 >= 0)
    {
        WriteVarint(5);
        WriteVarint(kIter->unk04);
        return;
    }

    FUN_00dba650 k = desc.GetObjectValue();
    int reqBytes = WriteHandle(&k);
    if (1 < kIter->unk0c)
    {
        WriteVarint(4);
        kIter->unk04 = m_30++;
    }
    else
    {
        WriteVarint(3);
    }
    kIter->unk00 = 1;
    WriteVarint(reqBytes);

    int c;
    c = k.ForwardCall_00dba730();
    MyCharArray charArr(c);

    int res;
    res = kIter->unk08 + (int)m_40.a;
    int count = ((charArr.m_iElementCount + 7) & ~7) / 8;
    {
        TempArrLocalForm temp((char*)res, count, count);
        writeVec((int)temp.m_data, temp.m_iElementCount);
        charArr.ProcessEntries_00dbefc0(temp.m_data, temp.m_iElementCount);
    }

    Array20 ptr(c);

    k.DispatchItems(&ptr);

    for (int i = 0; c > i; ++i)
    {
        if (charArr.m_data[i])
        {
            Struct20* item = &ptr.m_data[i];
            ResourceKey z = desc.Get_Thunk(item->a);
            WriteNode(&z, item);
        }
    }
}

struct ScanKey
{
    int first, second;
    ScanKey& operator=(const ScanKey& k)
    {
        first = k.first;
        second = k.second;
        return *this;
    }
};
struct ScanClass;
struct ScanArray;
struct ScanValue;
struct ScanItem;
struct ScanObject
{
    void* object;
    __declspec(nothrow) int hkDataObject_isNull() const;
    __declspec(nothrow) ScanKey GetSourcePair() const;
    __declspec(nothrow) ScanClass GetObjectValue() const;
    __declspec(nothrow) int ForwardCall_00dba8b0() const;
    __declspec(nothrow) int InvokeVirtualMethod_00dba8c0(int iterator) const;
    __declspec(nothrow) int ForwardCall_00dba8d0(int iterator) const;
    __declspec(nothrow) int InvokeVirtualMethod_00dba8e0(int iterator) const;
    __declspec(nothrow) ScanValue EvaluateValue_00dba8f0(int iterator) const;
    __declspec(nothrow) void ReleaseStorage_00dba7f0();
    ~ScanObject()
    {
        ReleaseStorage_00dba7f0();
    }
};
struct ScanMember
{
    int name, flags, type, className, extra;
    ScanMember() : name(0), flags(0), type(0), className(0), extra(0)
    {}
};
struct ScanClass
{
    void* object;
    __declspec(nothrow) int ForwardCall_00dba730() const;
    __declspec(nothrow) int InvokeVirtualMethod_00dba740(int name) const;
    __declspec(nothrow) void InvokeVirtualMethod_00dba720(int index, ScanMember& member) const;
    __declspec(nothrow) void Object_DoNothing_00dba660();
    ~ScanClass()
    {
        Object_DoNothing_00dba660();
    }
};
struct ScanArray
{
    void* object;
    __declspec(nothrow) int InvokeVirtualMethod_00dbac00() const;
    __declspec(nothrow) ScanClass ProcessAndReturnValue_00dbac20() const;
    __declspec(nothrow) ScanArray InvokeCallbackInto(int name) const;
    __declspec(nothrow) ScanItem UpdateState_00dbab90(int index) const;
    __declspec(nothrow) void ReleaseStorage_00dbab70();
    ~ScanArray()
    {
        ReleaseStorage_00dbab70();
    }
};
struct ScanValue
{
    void* object;
    int index;
    __declspec(nothrow) int QueryAndWriteResult() const;
    __declspec(nothrow) ScanObject GetWrappedDataObject() const;
    __declspec(nothrow) ScanArray GetResult() const;
};
struct ScanItem
{
    void* object;
    int index;
    __declspec(nothrow) ScanObject CreateValueInto() const;
};
struct ScanResources
{
    __declspec(nothrow) ScanObject AllocateStorage_00dbedd0(const ScanObject& source);
};
struct ScanRecord
{
    int first, second, bitOffset, count;
    ScanKey key;
};
extern ScanRecord DAT_010d6848;
void __cdecl ResizeAudioStream(hkMemoryAllocator& heap, void* array, int elementSize);
struct ScanReferences
{
    ScanRecord* data;
    int size, capacity;
    __forceinline ScanRecord& back()
    {
        return data[size - 1];
    }
    __forceinline void append(const ScanRecord& value)
    {
        hkMemoryAllocator& heap = ::audio()->temp();
        if (size == (capacity & 0x3fffffff))
            ResizeAudioStream(heap, this, sizeof(ScanRecord));
        data[size++] = value;
    }
};
struct ScanMap
{
    void* data;
    int size, capacity;
    __declspec(nothrow) int FindEntryValue(ScanKey key, int fallback) const;
    __declspec(nothrow) void InsertOrUpdate(AllocOwner* heap, ScanKey key, int value);
    __forceinline void insert(AllocOwner* heap, ScanKey key, int value)
    {
        InsertOrUpdate(heap, key, value);
    }
};
struct ScanMask : LocalhkCharArray
{
    int unk0c;
    __declspec(nothrow) void FUN_00dbef20(int n);
    __declspec(nothrow) void PackBitsToBytes(void* destination);
    __forceinline char& memberInteresting(int index)
    {
        return m_data[index];
    }
    __forceinline ScanMask(int n)
    {
        FUN_00dbef20(n);
    }
    __forceinline ~ScanMask()
    {
        hkTempAlloc& heap = ((S_dbf1a0_Router*)hkMemoryRouter_getInstance())->heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000u) == 0)
            heap.bufFree(m_data, m_iCapacityState & 0x3fffffff);
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

struct ScanWriter
{
    AudioObject first, second, third;
    int unk30;
    ScanMap map;
    LocalhkCharArray bits;
    ScanReferences references;
    ScanResources resources;
    __declspec(nothrow) void WriteHandle(const ScanClass& type);
    __declspec(nothrow) int EvaluateNode(const ScanValue& value);
    __declspec(nothrow) void WriteReferencedObjectRecursively(const ScanObject& source, int supplemental);
};
// Resolves a ScanObject, deduplicates it in the reference map, and recursively writes its class handle, member mask, and nested values to the writer's bit buffer.
// @fnv 0x00dbf450
// src: GUESS 0x00dbf450 (confidence: medium)
void ScanWriter::WriteReferencedObjectRecursively(const ScanObject& source, int supplemental)
{
    ScanObject object = resources.AllocateStorage_00dbedd0(source);
    if (object.hkDataObject_isNull())
        return;
    {
        int index = map.FindEntryValue(object.GetSourcePair(), -1);
        if (index != -1)
        {
            ++references.data[index].count;
            return;
        }
        if (!supplemental)
        {
            index = map.size & 0x7fffffff;
            map.insert(reinterpret_cast<AllocOwner*>(((hkMemoryRouter*)hkMemoryRouter_getInstance())->m_heap), object.GetSourcePair(), index);
            references.append(DAT_010d6848);
            ScanRecord& record = references.back();
            record.key = object.GetSourcePair();
        }
        ScanClass type = object.GetObjectValue();
        WriteHandle(type);
        ScanMask mask(type.ForwardCall_00dba730());
        for (int iterator = object.ForwardCall_00dba8b0(); object.InvokeVirtualMethod_00dba8c0(iterator);
             iterator = object.ForwardCall_00dba8d0(iterator))
        {
            ScanValue value = object.EvaluateValue_00dba8f0(iterator);
            if (EvaluateNode(value))
            {
                mask.memberInteresting(type.InvokeVirtualMethod_00dba740(object.InvokeVirtualMethod_00dba8e0(iterator))) = 1;
                int kind = value.QueryAndWriteResult() & 15;
                if (kind == 8 || kind == 9)
                {
                    switch (value.QueryAndWriteResult())
                    {
                    case 8:
                    case 9:
                        WriteReferencedObjectRecursively(value.GetWrappedDataObject(), 0);
                        break;
                    case 25:
                    case 41: {
                        ScanClass elementType = value.GetResult().ProcessAndReturnValue_00dbac20();
                        WriteHandle(elementType);
                        for (int member = 0; member < elementType.ForwardCall_00dba730(); ++member)
                        {
                            ScanMember description;
                            elementType.InvokeVirtualMethod_00dba720(member, description);
                            if (description.type == 8)
                            {
                                ScanArray elements = value.GetResult().InvokeCallbackInto(description.name);
                                int count = elements.InvokeVirtualMethod_00dbac00();
                                for (int i = 0; i < count; ++i)
                                {
                                    WriteReferencedObjectRecursively(elements.UpdateState_00dbab90(i).CreateValueInto(), 0);
                                }
                            }
                        }
                        break;
                    }
                    case 24:
                    case 40: {
                        int count = value.GetResult().InvokeVirtualMethod_00dbac00();
                        for (int i = 0; i < count; ++i)
                        {
                            WriteReferencedObjectRecursively(value.GetResult().UpdateState_00dbab90(i).CreateValueInto(), 0);
                        }
                        break;
                    }
                    }
                }
            }
        }
        if (!supplemental)
        {
            references.data[index].bitOffset = bits.m_iElementCount;
            int bytes = ((mask.m_iElementCount + 7) & ~7) / 8;
            LocalhkCharArray& destination = bits;
            hkMemoryAllocator& heap = ::audio()->temp();
            int oldSize = destination.m_iElementCount;
            int newSize = oldSize + bytes;
            int capacity = destination.getCapacity();
            if (capacity < newSize)
            {
                int doubled = capacity * 2;
                hkArrayUtil__reserve(heap, &destination, newSize < doubled ? doubled : newSize, 1);
            }
            destination.m_iElementCount += bytes;
            mask.PackBitsToBytes(destination.m_data + oldSize);
        }
    }
}

struct S00dbedb0_Callee : UnkHolder
{
    void __thiscall hkMapBase_struct_hkCppTypeInfoHash_struct_hkRttiParser_Node_const_struct_hkCppTypeInfoHash_resizeTable(UnkRet*, int);
};
// @fnv 0x00dbedb0
// src: GUESS 0x00dbedb0 (confidence: low)
__declspec(noinline) void __thiscall UnkHolder::ProcessEntries_00dbedb0(UnkRet* value, int count)
{
    int needed = count + count;
    int capacity = 8;
    while (capacity < needed)
        capacity += capacity;
    ((S00dbedb0_Callee*)this)->hkMapBase_struct_hkCppTypeInfoHash_struct_hkRttiParser_Node_const_struct_hkCppTypeInfoHash_resizeTable(value, capacity);
}
