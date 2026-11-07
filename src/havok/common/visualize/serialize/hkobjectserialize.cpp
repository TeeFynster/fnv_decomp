#include "../../../../../include/hkArray.h"

// src/havok/common/visualize/serialize/hkobjectserialize.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/serialize/hkobjectserialize.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/hkBool.h"


typedef unsigned int C68E30size_t;

inline hkMemoryAllocator& GetAudioAllocator(hkMemoryRouter& holder)
{
    return *reinterpret_cast<hkMemoryAllocator*>(holder.m_heap);
}

extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance();
void __cdecl ResizeAudioStream(void* alloc, void* array, int sizeElem);

struct C68E30PrimaryBase
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

struct C68E30Listener
{
    int unk00;
};

struct C68E30Entity : C68E30PrimaryBase, C68E30Listener
{
};

struct C68E30Holder
{
    int unk00;
    int unk04;
    C68E30Entity* m_pEntity;
};

struct C68E30Pair
{
    C68E30Listener* m_kListener;
    int m_uiFilterValue;

    static void* operator new(C68E30size_t, void* p) throw()
    {
        return p;
    }
};

typedef hkArray<C68E30Pair> C68E30PairArray;
__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
return reinterpret_cast<hkMemoryAllocator&>(GetAudioAllocator(hkMemoryRouter_getInstance()));
}
template<> __forceinline void hkArrayBase<C68E30Pair>::_pushBack(hkMemoryAllocator& sharedAlloc, C68E30Pair const& pair)
{
hkMemoryAllocator& alloc = reinterpret_cast<hkMemoryAllocator&>(sharedAlloc);

        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(&alloc, this, sizeof(C68E30Pair));
        new (m_data + m_iElementCount) C68E30Pair(pair);
        m_iElementCount++;
    
}


struct C68E30Owner
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
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    C68E30PairArray m_kListeners;

    void bhkWorld_SetDebugObjectColor(C68E30Holder* holder, int value);
};

// @fnv 0x00c68e30
// src: XBOX_PDB 0x00c68e30
void C68E30Owner::bhkWorld_SetDebugObjectColor(C68E30Holder* holder, int value)
{
    C68E30Pair pair;
    pair.m_uiFilterValue = value;
    C68E30Listener* listener = 0;
    if (holder->m_pEntity)
        listener = holder->m_pEntity;
    pair.m_kListener = listener;
    m_kListeners.pushBack(pair);
}

namespace fnvc_adapt {
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();
}
void __cdecl hkArrayUtil__reserve(void* apOwner, void* apArray, int aiSize, int aiAlign);

extern int DAT_01268fd0;

struct SweptVirtualObj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14(void* apItem, int aiFlag, int aiZero);
};

struct SweptItemArray
{
    void** m_00;
    int m_04;
    unsigned int m_08;
};

struct SweptEntry
{
    int unk00;
    SweptItemArray m_04;
};

struct FUN_00d641f0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    SweptVirtualObj* m_18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    SweptEntry** m_30;
    int m_34;

    void ClearSweptEntry(int aiIndex);
};

// @fnv 0x00d641f0
void FUN_00d641f0_cls::ClearSweptEntry(int aiIndex)
{
    SweptEntry* pEntry = m_30[aiIndex];
    int i = 0;
    if (pEntry->m_04.m_04 > 0)
    {
        do
        {
            m_18->v14(pEntry->m_04.m_00[i], DAT_01268fd0, 0);
            ++i;
        } while (i < pEntry->m_04.m_04);
    }

    SweptItemArray* pArray = &pEntry->m_04;
    hkMemoryRouter* pAudioHolder = fnvc_adapt::hkMemoryRouter_getInstance();
    // Preserve the original volatile allocator read.
    void* pAllocator = *reinterpret_cast<hkMemoryAllocator* volatile*>(&pAudioHolder->m_heap);
    int iCapacity = (int)(pArray->m_08 & 0x3fffffffu);
    if (iCapacity < 0)
    {
        hkArrayUtil__reserve(pAllocator, pArray, (iCapacity * 2) > 0 ? iCapacity * 2 : 0, 4);
    }
    pArray->m_04 = 0;
}

struct Sink
{
    virtual void v0() throw();
    virtual void v1() throw();
    virtual void v2() throw();
    virtual bool* Get(bool* out) throw();
    virtual void Put(const void* data, unsigned int size) throw();
};

struct Entry8
{
    unsigned int first, second;
};
struct Entry16
{
    unsigned int first, second, third, unused;
};
// hkObjectSerialize fixup arrays: local fixups (8-byte from/to pairs) and global fixups (16-byte entries), written by FUN_00e0b850
struct FixupLists
{
    Entry8* pairs;
    unsigned int pairCount;
    unsigned int pairCapacity;
    Entry16* triples;
    unsigned int tripleCount;
};

struct ByteSwap
{
    bool value;
};

struct Buffer
{
    void* vtable;
    unsigned short state, references;
    Sink* stream;
    bool byteSwap;
    void hkOArchive_InitializeWriterWithByteSwap(Sink*, ByteSwap) throw();
    void hkOArchive_WriteBinaryData_Thunk_00d609e0(unsigned int, unsigned int) throw();
    void WriteInt(unsigned int) throw();
    void hkOArchive_write32u(unsigned int) throw();
    void ReleaseReference_00d60590() throw();
};

// Serializes a1-a4, data pairs/triples, and payload into sink via buffer, returning total bytes written or -1 on failure.
// @fnv 0x00e0b850
// src: HAVOK_LIB 0x00e0b850
static __declspec(noinline) int _writeData(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4,
                                             const void* payload, unsigned int payloadBytes, ByteSwap byteSwap,
                                             FixupLists* data, Sink* sink)
{
    bool status;
    unsigned int bytes;
    unsigned int count;
    Buffer buffer;
    buffer.hkOArchive_InitializeWriterWithByteSwap(sink, byteSwap);
    buffer.hkOArchive_WriteBinaryData_Thunk_00d609e0(a1, a2);
    if (!*sink->Get(&status))
    {
        buffer.ReleaseReference_00d60590();
        return -1;
    }
    buffer.hkOArchive_WriteBinaryData_Thunk_00d609e0(a3, a4);
    if (!*sink->Get(&status))
    {
        buffer.ReleaseReference_00d60590();
        return -1;
    }
    count = data->pairCount;
    buffer.hkOArchive_write32u(count);
    bytes = 0x14;
    for (unsigned int i = 0; i < count; ++i)
    {
        buffer.WriteInt(data->pairs[i].first);
        buffer.WriteInt(data->pairs[i].second);
        if (!*sink->Get(&status))
        {
            buffer.ReleaseReference_00d60590();
            return -1;
        }
        bytes += 8;
    }
    count = data->tripleCount;
    buffer.hkOArchive_write32u(count);
    bytes += 4;
    for (unsigned int i = 0; i < count; ++i)
    {
        buffer.WriteInt(data->triples[i].first);
        buffer.hkOArchive_WriteBinaryData_Thunk_00d609e0(data->triples[i].second, 0);
        buffer.hkOArchive_WriteBinaryData_Thunk_00d609e0(data->triples[i].third, 0);
        if (!*sink->Get(&status))
        {
            buffer.ReleaseReference_00d60590();
            return -1;
        }
        bytes += 20;
    }
    buffer.hkOArchive_write32u(payloadBytes);
    if (!*sink->Get(&status))
    {
        buffer.ReleaseReference_00d60590();
        return -1;
    }
    sink->Put(payload, payloadBytes);
    if (!*sink->Get(&status))
    {
        buffer.ReleaseReference_00d60590();
        return -1;
    }
    buffer.ReleaseReference_00d60590();
    return bytes + payloadBytes + 4;
}

int SerializeData(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4, const void* payload,
                  unsigned int payloadBytes, ByteSwap byteSwap, FixupLists* data, Sink* sink)
{
    return _writeData(a1, a2, a3, a4, payload, payloadBytes, byteSwap, data, sink);
}

void __cdecl hkArrayUtil__reserve(void* alloc, void* array, int numElements, int sizeElem);
void* __cdecl AllocateWithHeader(void* alloc, int size);
void __cdecl hkMemoryRouter_easyFree(void* alloc, void* p);

struct hkStreamReader
{
    virtual ~hkStreamReader() throw();
    virtual void unk04() throw();
    virtual void unk08() throw();
    virtual hkBool IsStreamValid() const throw();
    virtual int read(void* buf, int nbytes) throw();
};

struct Reloc
{
    int m_iSourceOffset;
    int toOffset;
};

struct Item24
{
    int field00;
    int field04;
    __int64 field08;
    __int64 field10;
};

// hkArray::clearAndDeallocate / setSize through the audio allocator. The relocation table is a local hkArray in
// Havok; the unit is /EHsc while the original has no EH frame, so it is held as its hkArrayBase and freed by hand.
template <typename T> static __forceinline void ClearAndRelease(hkArrayBase<T>& a, hkMemoryAllocator& alloc) throw()
{
    int cap = a.m_iCapacityState;
    a.m_iElementCount = 0;
    if ((cap & 0x80000000) == 0)
    {
        alloc.bufFree(a.m_data, (cap & 0x3fffffff) * sizeof(T));
    }
}

template <typename T> static __forceinline void SetSizeAndGrow(hkArrayBase<T>& a, hkMemoryAllocator& alloc, int size) throw()
{
    int cap = a.m_iCapacityState & 0x3fffffff;
    if (cap < size)
    {
        int newCap = cap + cap;
        if (size >= newCap)
            newCap = size;
        hkArrayUtil__reserve(&alloc, &a, newCap, sizeof(T));
    }
    a.m_iElementCount = size;
}

// Reads a header, tag, relocation table, item list, and allocated buffer from a stream, applies relocations to the buffer, and returns the header value.
// @fnv 0x00e0ba10
unsigned __int64 __cdecl ReadRelocatedData(hkStreamReader* stream, char** outBuffer, int* outAllocSize,
                                           hkArray<Item24>& outItems, void* tag)
{
    int numRelocs;
    int numItems;
    int i;
    unsigned __int64 header;

    stream->read(&header, 8);
    if (!stream->IsStreamValid())
        return 0;

    stream->read(tag, 8);
    if (!stream->IsStreamValid())
        return 0;

    hkArrayBase<Reloc> relocs;
    stream->read(&numRelocs, 4);
    if (!stream->IsStreamValid())
    {
        ClearAndRelease(relocs, GetAudioAllocator(hkMemoryRouter_getInstance()));
        return 0;
    }

    int count = numRelocs;
    SetSizeAndGrow(relocs, GetAudioAllocator(hkMemoryRouter_getInstance()), count);
    for (i = 0; i < (unsigned int)numRelocs; ++i)
    {
        Reloc& r = relocs[i];
        stream->read(&r.m_iSourceOffset, 4);
        stream->read(&r.toOffset, 4);
        if (!stream->IsStreamValid())
        {
            ClearAndRelease(relocs, GetAudioAllocator(hkMemoryRouter_getInstance()));
            return 0;
        }
    }

    stream->read(&numItems, 4);
    if (!stream->IsStreamValid())
    {
        ClearAndRelease(relocs, GetAudioAllocator(hkMemoryRouter_getInstance()));
        return 0;
    }

    count = numItems;
    SetSizeAndGrow(outItems, GetAudioAllocator(hkMemoryRouter_getInstance()), count);
    for (i = 0; i < (unsigned int)numItems; ++i)
    {
        char* item = (char*)&outItems[i];
        stream->read(item, 4);
        stream->read(item + 8, 8);
        stream->read(item + 16, 8);
        if (!stream->IsStreamValid())
        {
            ClearAndRelease(relocs, GetAudioAllocator(hkMemoryRouter_getInstance()));
            return 0;
        }
    }

    stream->read(outAllocSize, 4);
    if (!stream->IsStreamValid())
    {
        ClearAndRelease(relocs, GetAudioAllocator(hkMemoryRouter_getInstance()));
        return 0;
    }

    int iAllocationSize = *outAllocSize;
    char* buffer = (char*)AllocateWithHeader(&GetAudioAllocator(hkMemoryRouter_getInstance()), iAllocationSize);
    stream->read(buffer, *outAllocSize);
    if (!stream->IsStreamValid())
    {
        hkMemoryRouter_easyFree(&GetAudioAllocator(hkMemoryRouter_getInstance()), buffer);
        ClearAndRelease(relocs, GetAudioAllocator(hkMemoryRouter_getInstance()));
        return 0;
    }

    for (i = 0; i < (unsigned int)numRelocs; ++i)
    {
        int m_iSourceOffset = relocs[i].m_iSourceOffset;
        if (m_iSourceOffset >= 0)
        {
            *(char**)(buffer + m_iSourceOffset) = buffer + relocs[i].toOffset;
        }
    }

    *outBuffer = buffer;
    unsigned __int64 ret = header;
    ClearAndRelease(relocs, GetAudioAllocator(hkMemoryRouter_getInstance()));
    return ret;
}

struct ObjectWriteFlag
{
    char value;
    ObjectWriteFlag(bool b) : value(b)
    {}
    ObjectWriteFlag(const ObjectWriteFlag& b) : value(b.value)
    {}
    operator bool() const
    {
        return value != 0;
    }
};

// src: HAVOK_LIB 0x00e0b850
static __declspec(noinline) int _writeData(FixupLists* fixups, Sink* output, unsigned int idLow, unsigned int idHigh,
                                             unsigned int classLow, unsigned int classHigh, const void* payload,
                                             unsigned int payloadSize, ObjectWriteFlag swap)
{
    bool ok;
    unsigned int total;
    unsigned int count;
    Buffer archive;
    ByteSwap endian;
    endian.value = swap;
    archive.hkOArchive_InitializeWriterWithByteSwap(output, endian);
    archive.hkOArchive_WriteBinaryData_Thunk_00d609e0(idLow, idHigh);
    if (!*output->Get(&ok))
    {
        archive.ReleaseReference_00d60590();
        return -1;
    }
    archive.hkOArchive_WriteBinaryData_Thunk_00d609e0(classLow, classHigh);
    if (!*output->Get(&ok))
    {
        archive.ReleaseReference_00d60590();
        return -1;
    }
    count = fixups->pairCount;
    archive.hkOArchive_write32u(count);
    total = 20;
    for (unsigned int j = 0; j < count; ++j)
    {
        archive.WriteInt(fixups->pairs[j].first);
        archive.WriteInt(fixups->pairs[j].second);
        if (!*output->Get(&ok))
        {
            archive.ReleaseReference_00d60590();
            return -1;
        }
        total += 8;
    }
    count = fixups->tripleCount;
    archive.hkOArchive_write32u(count);
    total += 4;
    for (unsigned int j = 0; j < count; ++j)
    {
        archive.WriteInt(fixups->triples[j].first);
        archive.hkOArchive_WriteBinaryData_Thunk_00d609e0(fixups->triples[j].second, 0);
        archive.hkOArchive_WriteBinaryData_Thunk_00d609e0(fixups->triples[j].third, 0);
        if (!*output->Get(&ok))
        {
            archive.ReleaseReference_00d60590();
            return -1;
        }
        total += 20;
    }
    archive.hkOArchive_write32u(payloadSize);
    if (!*output->Get(&ok))
    {
        archive.ReleaseReference_00d60590();
        return -1;
    }
    output->Put(payload, payloadSize);
    if (!*output->Get(&ok))
    {
        archive.ReleaseReference_00d60590();
        return -1;
    }
    archive.ReleaseReference_00d60590();
    return total + payloadSize + 4;
}

struct ObjectWriteTri
{
    int a;
    int b;
    int c;
    int d;
};

struct ObjectWriteItem
{
    int m_00;
    int unk04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
};

struct ObjectWriteArrItem
{
    ObjectWriteItem* m_data;
    int m_iElementCount;
    int m_cap;
};

struct ObjectWriteArrTri
{
    ObjectWriteTri* m_data;
    int m_iElementCount;
    int m_cap;
};

struct ObjectWriteArrByte
{
    char* m_data;
    int m_iElementCount;
    int m_cap;
};

struct ObjectWriteArrInt
{
    int* m_data;
    int m_iElementCount;
    int m_cap;
};

struct ObjectWriteW
{
    ObjectWriteArrInt m_a0;
    ObjectWriteArrTri m_a1;
    ObjectWriteArrInt m_a2;
    ObjectWriteArrInt m_a3;
    int m_30;
    void FUN_00e028e0();
};

struct ObjectWriteZ
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    void FUN_00cc06f0(ObjectWriteArrByte* y, int one);
    void FUN_00cc0780();
};

struct ObjectWriteInfo
{
    char unk00;
    char m_01;
};

struct ObjectWriteX
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void hkPlatformObjectWriter_hkPlatformObjectWriter(ObjectWriteInfo* info);
    void hkPlatformObjectWriter_writeObject(ObjectWriteZ* z, int a, int b, ObjectWriteW* w);
    void FUN_00e02c70();
};

extern char DAT_011b7b89;

// Writes an object record to a sink by serializing its fixups and payload via FUN_00e0b850, returning the total bytes written.
// @fnv 0x00e0bd40
// src: HAVOK_LIB 0x00e0bd40
int __cdecl hkObjectSerialize_writeObject(Sink* p1, ObjectWriteInfo* p2, unsigned int aiIdLow, unsigned int aiIdHigh, int p5,
                         unsigned int p6, ObjectWriteArrItem* out)
{
    ObjectWriteX x;
    x.hkPlatformObjectWriter_hkPlatformObjectWriter(p2);
    ObjectWriteArrByte y;
    y.m_data = 0;
    y.m_iElementCount = 0;
    y.m_cap = 0x80000000;
    ObjectWriteZ z;
    z.FUN_00cc06f0(&y, 1);
    ObjectWriteW w;
    w.m_a0.m_data = 0;
    w.m_a0.m_iElementCount = 0;
    w.m_a0.m_cap = 0x80000000;
    w.m_a1.m_data = 0;
    w.m_a1.m_iElementCount = 0;
    w.m_a1.m_cap = 0x80000000;
    w.m_a2.m_data = 0;
    w.m_a2.m_iElementCount = 0;
    w.m_a2.m_cap = 0x80000000;
    w.m_a3.m_data = 0;
    w.m_a3.m_iElementCount = 0;
    w.m_a3.m_cap = 0x80000000;
    w.m_30 = 0;
    x.hkPlatformObjectWriter_writeObject(&z, p5, p6, &w);

    int need = out->m_iElementCount + w.m_a1.m_iElementCount;
    hkMemoryAllocator& alloc = GetAudioAllocator(hkMemoryRouter_getInstance());
    if ((out->m_cap & 0x3fffffff) < need)
    {
        int iDoubled = (out->m_cap & 0x3fffffff) * 2;
        hkArrayUtil__reserve(&alloc, out, need < iDoubled ? iDoubled : need, 0x18);
    }
    for (int i = 0; i < w.m_a1.m_iElementCount; i++)
    {
        hkMemoryRouter* router = &hkMemoryRouter_getInstance();
        if (out->m_iElementCount == (out->m_cap & 0x3fffffff))
            ResizeAudioStream(router->m_heap, out, 0x18);
        ObjectWriteItem* p = out->m_data + out->m_iElementCount;
        out->m_iElementCount++;
        p->m_00 = w.m_a1.m_data[i].a;
        p->m_08 = w.m_a1.m_data[i].b;
        p->m_0c = 0;
        p->m_10 = w.m_a1.m_data[i].c;
        p->m_14 = 0;
    }
    int r = _writeData((FixupLists*)&w, p1, aiIdLow, aiIdHigh, p6, 0, y.m_data, y.m_iElementCount,
                         ObjectWriteFlag(p2->m_01 != DAT_011b7b89));
    w.FUN_00e028e0();
    z.FUN_00cc0780();
    hkMemoryAllocator& allocY = GetAudioAllocator(hkMemoryRouter_getInstance());
    y.m_iElementCount = 0;
    if ((y.m_cap & 0x80000000) == 0)
        allocY.bufFree(y.m_data, y.m_cap & 0x3fffffff);
    y.m_data = 0;
    y.m_cap = 0x80000000;
    x.FUN_00e02c70();
    return r;
}
