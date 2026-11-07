
// src/havok/common/serialize/tagfile/binary/hkbinarytagfilereader.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/tagfile/binary/hkbinarytagfilereader.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkArray.h"
#include "../../../../../../include/hkDataClassImpl.h"
#include "../../../../../../include/hkBinaryTagfileReader.h"

extern "C" void* DAT_010d6ce8;

struct FUN_00dc5d30
{
    void* m_p;
    short m_usTrailingValue;
    short m_f;
    FUN_00dc5d30();
};

// @fnv 0x00dc5d30
FUN_00dc5d30::FUN_00dc5d30()
{
    m_f = 1;
    m_p = &DAT_010d6ce8;
}

struct hkBinaryTagFileReaderVirtualObject
{
    virtual void FreeAllBlocks(int);
};

hkMemoryRouter* __cdecl _D1A0E0GetMemoryRouter();
void __cdecl _FUN_00c856c0(void*, void*);

// Not hkLargeBlockAllocator: 0x00dc6020 destroys a tagfile reader object (owned
// object at +0x14, three hkArrays at +0x18/+0x24/+0x30) and tail-calls the hkIArchive
// destructor body 0x00dd91f0 for the archive at +0. Real class name unknown.
struct FUN_00dc6020_cls
{
    void* m_p00;
    void* m_p04;
    void* m_p08;
    void* m_p0c;
    void* m_p10;
    hkBinaryTagFileReaderVirtualObject* m_p14;
    void* m_p18;
    unsigned int m_n1c;
    unsigned int m_flags20;
    void** m_p24;
    int m_n28;
    unsigned int m_flags2c;
    void* m_p30;
    unsigned int m_n34;
    unsigned int m_flags38;

    void FreeAllBlocks();
    void ReleaseArchiveReader();
};

// @fnv 0x00dc6020
void FUN_00dc6020_cls::FreeAllBlocks()
{
    if (m_p14)
        m_p14->FreeAllBlocks(1);

    int i = 2;
    if (i < m_n28)
    {
        do
        {
            void* item = m_p24[i];
            hkMemoryRouter* router = _D1A0E0GetMemoryRouter();
            _FUN_00c856c0(router->m_heap, item);
            ++i;
        } while (i < m_n28);
    }

    hkMemoryRouter* router = _D1A0E0GetMemoryRouter();
    hkMemoryAllocator* context = router->m_heap;
    unsigned int flags = m_flags38;
    m_n34 = 0;
    if (!(flags & 0x80000000))
        context->bufFree(m_p30, (flags & 0x3fffffff) * 4);
    m_p30 = 0;
    m_flags38 = 0x80000000;

    router = _D1A0E0GetMemoryRouter();
    context = router->m_heap;
    flags = m_flags2c;
    m_n28 = 0;
    if (!(flags & 0x80000000))
        context->bufFree(m_p24, (flags & 0x3fffffff) * 4);
    m_p24 = 0;
    m_flags2c = 0x80000000;

    router = _D1A0E0GetMemoryRouter();
    context = router->m_heap;
    flags = m_flags20;
    m_n1c = 0;
    if (!(flags & 0x80000000))
        context->bufFree(m_p18, (flags & 0x3fffffff) * 4);
    m_p18 = 0;
    m_flags20 = 0x80000000;

    return ReleaseArchiveReader();
}

extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance();

inline hkMemoryAllocator& readerHeap(hkMemoryRouter& router)
{
    return *router.m_heap;
}

void __cdecl ResizeAudioStream(void* pvAlloc, void* apvArray, int iElemSize);

template <class T> __forceinline void constructWithCopyDC5D(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return readerHeap(hkMemoryRouter_getInstance());
}

template <class T> __forceinline void hkArrayBase<T>::_pushBack(hkMemoryAllocator& kAlloc, const T& t)
{
    if (m_iElementCount == getCapacity())
        ResizeAudioStream(&kAlloc, this, sizeof(T));
    constructWithCopyDC5D(m_data + m_iElementCount, 1, t);
    m_iElementCount++;
}

char* __cdecl AllocateWithHeader(hkMemoryAllocator* pkAlloc, int iNumBytes) throw();

// @fnv 0x00dc5d90
char* hkBinaryTagfileReader::ReadString()
{
    int iLen = ReadSignedVarInt32();
    if (iLen > 0)
    {
        char* pcString = AllocateWithHeader(&readerHeap(hkMemoryRouter_getInstance()), iLen + 1);
        ForwardCall_00dd90d0(pcString, iLen);
        pcString[iLen] = 0;
        m_pStringFunctions.pushBack(pcString);
        return pcString;
    }
    return m_pStringFunctions.m_data[-iLen];
}

void __cdecl hkArrayUtil__reserve(hkMemoryAllocator& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();

template <typename T> __forceinline void hkArrayBase<T>::GrowArrayCapacity(hkMemoryAllocator& kAlloc, int n)
{
    const int iCapacity = getCapacity();
    if (iCapacity < n)
    {
        int iCap2 = 2 * iCapacity;
        int iNewSize = (n < iCap2) ? iCap2 : n;
        hkArrayUtil__reserve(kAlloc, this, iNewSize, sizeof(T));
    }
}

template <typename T> __forceinline void hkArrayBase<T>::_setSize(hkMemoryAllocator& kAlloc, int n)
{
    GrowArrayCapacity(kAlloc, n);
    m_iElementCount = n;
}

// Reads iNumBits bits from the tagfile into kBitsOut, unpacking each byte least-significant bit first, then resizes the array to iNumBits.
// @fnv 0x00dc5e10
void hkBinaryTagfileReader::ReadBits(int iNumBits, hkArray<char>& kBitsOut) throw()
{
    int iNumBitsRounded = (iNumBits + 7) & ~7;
    int iNumBytes = iNumBitsRounded / 8;
    unsigned int auiBuf[16];
    kBitsOut.setSize(iNumBitsRounded);
    hkIArchive_readArrayGeneric(auiBuf, 1, iNumBytes);
    for (int i = 0; i < iNumBytes; i++)
    {
        unsigned int uiByte = ((unsigned char*)auiBuf)[i];
        for (int j = 0; j < 8; j++)
        {
            kBitsOut[i * 8 + j] = char(uiByte & 1);
            uiByte >>= 1;
        }
    }
    kBitsOut.setSize(iNumBits);
}

extern "C" char* __fastcall ReadString(void* p);
extern "C" int __fastcall ReadSignedVarInt32(void* p);
void __cdecl hkArrayUtil__reserve(void*, void*, int, int);
void __cdecl ResizeAudioStream(void*, void*, int);

struct Struct3;

struct Field10Class
{
    virtual void dummy0();
    virtual void dummy1();
    virtual void dummy2();
    virtual void* vtable_0c(Struct3* s);
    virtual void dummy4();
    virtual void dummy5();
    virtual int* vtable_18(void* outVal);
    virtual void dummy7();
    virtual void dummy8();
    virtual void vtable_24(char* name);
};

struct Item
{
    char* m_name;
    int m_type;
    int m_extra;
    char* m_altName;
};

static __forceinline void __fastcall callFree(hkMemoryAllocator* ctx, void* p, unsigned int size)
{
    ctx->bufFree(p, size);
}

struct ItemArrayLocalForm
{ // local form of hkArray: 0x00dc6c90 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    Item* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void ClearAndRelease()
    {
        hkMemoryRouter* r = _D1A0E0GetMemoryRouter();
        hkMemoryAllocator* ctx = r->m_heap;
        int cap = m_iCapacityState;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
        {
            callFree(ctx, m_data, (cap & 0x3fffffff) * 16);
        }
    }
};

struct Struct3
{
    char* m_str;
    int m_type;
    const char* m_obj;
    ItemArrayLocalForm m_items;
};

template <class T> inline void constructWithCopy(T* destination, const T* source, int count)
{
    for (int i = 0; i < count; ++i)
        destination[i] = source[i];
}


struct TagFileReader
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    Field10Class* m_p10;
    hkBinaryTagFileReaderVirtualObject* m_p14;
    hkArrayBase<hkDataClassImpl*> m_kTrackedObjects;
    hkArrayBase<void*> m_objects24;
    hkArrayBase<void*> m_objects30;
    Field10Class* getP10()
    {
        return m_p10;
    }
    int ReadTagFileEntry();
};

struct Locals
{
    void* outVal;
    Struct3 s;
};

// @fnv 0x00dc6c90
int TagFileReader::ReadTagFileEntry()
{
    Locals entry;

    entry.s.m_items.m_data = 0;
    entry.s.m_items.m_iElementCount = 0;
    entry.s.m_items.m_iCapacityState = 0x80000000;

    entry.s.m_str = ReadString(this);
    entry.s.m_type = ReadSignedVarInt32(this);

    if (!*getP10()->vtable_18(&entry.outVal))
    {
        entry.s.m_items.ClearAndRelease();
        return 1;
    }

    int iObjectIndex = ReadSignedVarInt32(this);
    if (iObjectIndex >= 0 && m_kTrackedObjects[iObjectIndex])
    {
        entry.s.m_obj = m_kTrackedObjects[iObjectIndex]->getName(); // src: HAVOK_SRC
    }
    else
    {
        entry.s.m_obj = 0;
    }

    int iItemCount = ReadSignedVarInt32(this);
    {
        hkMemoryRouter* r = _D1A0E0GetMemoryRouter();
        hkMemoryAllocator* ctx = r->m_heap;
        int iNewCapacity = entry.s.m_items.m_iCapacityState & 0x3fffffff;
        if (iNewCapacity < iItemCount)
        {
            iNewCapacity += iNewCapacity;
            if (iItemCount >= iNewCapacity)
                iNewCapacity = iItemCount;
            hkArrayUtil__reserve(ctx, &entry.s.m_items, iNewCapacity, 16);
        }
    }

    entry.s.m_items.m_iElementCount = iItemCount;

    for (int i = 0; i < entry.s.m_items.m_iElementCount; ++i)
    {
        Item* item = &entry.s.m_items.m_data[i];
        item->m_name = ReadString(this);
        item->m_type = ReadSignedVarInt32(this);
        item->m_extra = (item->m_type & 0x20) ? ReadSignedVarInt32(this) : 0;
        int lowType = item->m_type & 0xf;
        char* pAltName = (lowType == 9 || lowType == 8) ? ReadString(this) : 0;
        item->m_altName = pAltName;
        if (pAltName)
        {
            getP10()->vtable_24(item->m_altName);
        }
    }

    void* pResult = getP10()->vtable_0c(&entry.s);
    {
        hkArrayBase<hkDataClassImpl*>* targetArr = &m_kTrackedObjects;
        hkMemoryRouter* r = _D1A0E0GetMemoryRouter();
        if (targetArr->m_iElementCount == (targetArr->m_iCapacityState & 0x3fffffff))
        {
            ResizeAudioStream(r->m_heap, targetArr, 4);
        }
        hkDataClassImpl* pStoredObject = static_cast<hkDataClassImpl*>(pResult);
        constructWithCopy(targetArr->m_data + targetArr->m_iElementCount, &pStoredObject, 1);
        ++targetArr->m_iElementCount;
    }

    entry.s.m_items.ClearAndRelease();
    return 0;
}

__forceinline void ReadTagfileVarInt(hkBinaryTagfileReader& kReader, __int64& kValue)
{
    unsigned char ucByte;
    kReader.hkIArchive_readArrayGeneric(&ucByte, 1, 1);
    unsigned __int64 uiByte = (int)ucByte;
    unsigned __int64 uiValue = (uiByte & ~0x81) >> 1;
    int bNegative = (int)(uiByte & 1);
    int iShift = 6;
    while (uiByte & 0x80)
    {
        kReader.hkIArchive_readArrayGeneric(&ucByte, 1, 1);
        uiByte = (int)ucByte;
        uiValue |= (uiByte & ~0x80) << iShift;
        iShift += 7;
    }
    if (bNegative)
    {
        kValue = -(__int64)uiValue;
        return;
    }
    kValue = uiValue;
}

// Reads a variable-length integer from the reader and returns it as a 32-bit signed value.
// @fnv 0x00dc5bd0
// src: GUESS 0x00dc5bd0 (confidence: high)
int hkBinaryTagfileReader::ReadSignedVarInt32() throw()
{
    __int64 iVarInt;
    ReadTagfileVarInt(*this, iVarInt);
    return (int)iVarInt;
}

// Reads a variable-length signed integer and returns the decoded value.
// @fnv 0x00dc5c80
__int64 hkBinaryTagfileReader::ReadVarInt()
{
    unsigned char ucByte;
    hkIArchive_readArrayGeneric(&ucByte, 1, 1);
    unsigned __int64 uiByte = (int)ucByte;
    unsigned __int64 uiValue = (uiByte & ~0x81) >> 1;
    int bNegative = (int)(uiByte & 1);
    int iShift = 6;
    while (uiByte & 0x80)
    {
        hkIArchive_readArrayGeneric(&ucByte, 1, 1);
        uiByte = (int)ucByte;
        uiValue |= (uiByte & ~0x80) << iShift;
        iShift += 7;
    }
    if (bNegative)
        uiValue = -(__int64)uiValue;
    return uiValue;
}

struct FUN_00dc5d50_Local
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;

    void Reader_Reader(unsigned int, unsigned int);
    void ProcessEntries_00dc6e50(unsigned int);
    void FreeAllBlocks();
};

// @fnv 0x00dc5d50
// src: HAVOK_SRC 0x00dc5d50
unsigned int __stdcall hkBinaryTagfileReader_load(unsigned int a, unsigned int b, unsigned int c)
{
    FUN_00dc5d50_Local local;
    local.Reader_Reader(b, c);
    local.ProcessEntries_00dc6e50(a);
    local.FreeAllBlocks();
    return a;
}

extern char DAT_01011584;

inline void* operator new(unsigned int, void* p)
{
    return p;
}

struct S00dc5f30_Tag
{
    unsigned char m_kPointB;
    S00dc5f30_Tag()
    {
        m_kPointB = 0;
    }
    S00dc5f30_Tag(const S00dc5f30_Tag& o)
    {
        m_kPointB = o.m_kPointB;
    }
};

struct S00dc5f30_HL
{
    void* m_p;
    unsigned int m_uiValueCount;
    unsigned int m_flags;
};

struct S00dc5f30_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_p10;
    int m_n14;
    S00dc5f30_HL m_hl18;
    S00dc5f30_HL m_hl24;
    S00dc5f30_HL m_hl30;

    void Init(int, S00dc5f30_Tag);

    S00dc5f30_Obj* Reader_Reader(int a0, int a1);
};

// Initializes the object with a0 and a1, sets m_p10 and m_n14, and adds three entries to the m_hl18 and m_hl24 lists.
// @fnv 0x00dc5f30
// src: XBOX_PDB 0x00dc5f30
S00dc5f30_Obj* S00dc5f30_Obj::Reader_Reader(int a0, int a1)
{
    Init(a0, S00dc5f30_Tag());
    m_p10 = (void*)a1;
    m_n14 = 0;
    S00dc5f30_HL* pFirstList = &m_hl18;
    S00dc5f30_HL* pSecondList = &m_hl24;
    pFirstList->m_p = 0;
    pFirstList->m_uiValueCount = 0;
    pFirstList->m_flags = 0x80000000;
    pSecondList->m_p = 0;
    pSecondList->m_uiValueCount = 0;
    pSecondList->m_flags = 0x80000000;
    m_hl30.m_p = 0;
    m_hl30.m_uiValueCount = 0;
    m_hl30.m_flags = 0x80000000;

    hkMemoryRouter& r = hkMemoryRouter_getInstance();
    if (pFirstList->m_uiValueCount == (pFirstList->m_flags & 0x3fffffff))
    {
        ResizeAudioStream(r.m_heap, pFirstList, 4);
    }
    void** pSlot = (void**)pFirstList->m_p + pFirstList->m_uiValueCount;
    __assume(pSlot != 0);
    new (pSlot) void * (0);
    ++pFirstList->m_uiValueCount;

    hkMemoryRouter& r2 = hkMemoryRouter_getInstance();
    if (pSecondList->m_uiValueCount == (pSecondList->m_flags & 0x3fffffff))
    {
        ResizeAudioStream(r2.m_heap, pSecondList, 4);
    }
    void** pSlot2 = (void**)pSecondList->m_p + pSecondList->m_uiValueCount;
    __assume(pSlot2 != 0);
    new (pSlot2) void*(&DAT_01011584);
    pSecondList->m_uiValueCount += 1;

    hkMemoryRouter& r3 = hkMemoryRouter_getInstance();
    if (pSecondList->m_uiValueCount == (pSecondList->m_flags & 0x3fffffff))
    {
        ResizeAudioStream(r3.m_heap, pSecondList, 4);
    }
    void** pSlot3 = (void**)pSecondList->m_p + pSecondList->m_uiValueCount;
    __assume(pSlot3 != 0);
    new (pSlot3) void * (0);
    pSecondList->m_uiValueCount += 1;

    return this;
}

template <typename T> __forceinline void ConstructTF(T* p, int n)
{
    for (int i = 0; i < n; ++i)
        ::new (static_cast<void*>(p + i)) T();
}
template <typename T> __forceinline void ConstructWithCopyTF(T* p, int n, const T& t)
{
    for (int i = 0; i < n; ++i)
        p[i] = t;
}
template <typename T> struct hkArrayTFLocalForm
{ // local form of hkArray: 0x00dc6970 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    hkArrayTFLocalForm() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    __forceinline void clearStorage()
    {
        hkMemoryAllocator& kAlloc = readerHeap(hkMemoryRouter_getInstance());
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
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
        hkMemoryAllocator& kAlloc = readerHeap(hkMemoryRouter_getInstance());
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&kAlloc, this, sizeof(T));
        ConstructWithCopyTF(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
    __forceinline void setSizeUnchecked(int n)
    {
        ConstructTF(m_data + m_iElementCount, n - m_iElementCount);
        m_iElementCount = n;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
template <typename T> struct hkLocalArrayTF : public hkArrayTFLocalForm<T>
{
    __forceinline hkLocalArrayTF(int n)
    {
        hkMemoryRouter& kRouter = hkMemoryRouter_getInstance();
        T* pLocal = (T*)kRouter.m_stack.m_next.m_storage;
        kRouter.m_stack.m_next.m_storage = (void*)((int)((char*)pLocal + ((n * sizeof(T) + 0x7f) & ~0x7f)));
        this->m_data = pLocal;
        this->m_iCapacityState = n | 0x80000000;
        m_pStackAllocation = pLocal;
    }
    __forceinline void clearLocal()
    {
        T* pLocal = m_pStackAllocation;
        if (pLocal == this->m_data)
            this->m_iElementCount = 0;
        hkMemoryRouter_getInstance().m_stack.m_next.m_storage = (void*)((int)pLocal);
    }
    T* m_pStackAllocation;
};
class hkOstreamTF
{
  public:
    hkOstreamTF(void* pvBuffer, int iSize)
    {
        FUN_00cb1600(pvBuffer, iSize);
    }
    void close()
    {
        FUN_00cc00e0();
    }
    hkOstreamTF& operator<<(const char* pcString)
    {
        return ProcessAndReturnValue_00cc01c0(pcString);
    }
    void FUN_00cb1600(void* pvBuffer, int iSize);
    void FUN_00cc00e0();
    hkOstreamTF& ProcessAndReturnValue_00cc01c0(const char* pcString);
    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_pStreamWriter;
};
class hkErrorTF
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int message(int eType, int aiSoundId, const char* pcDescription, const char* pcFile, int iLine);
};
extern hkErrorTF* DAT_01268360;
struct hkDataObjectImplTF;
struct MemberInfoTF
{
    MemberInfoTF() : m_name(0), m_pClassName(0), m_type(0), m_valuePtr(0), m_extra(0)
    {}
    const char* m_name;
    const char* m_pClassName;
    int m_type;
    void* m_valuePtr;
    int m_extra;
};
class hkDataClassTF
{
  public:
    hkDataClassTF(hkDataClassImpl* pkImpl)
    {
        SetField00(pkImpl);
    }
    void close()
    {
        Object_DoNothing_00dba660();
    }
    void SetField00(hkDataClassImpl* pkImpl);
    void Object_DoNothing_00dba660();
    int ForwardCall_00dba730() const;
    void DispatchItems(hkArrayTFLocalForm<MemberInfoTF>& kInfo) const;
    hkDataClassImpl* m_pClassImpl;
};
struct ValueRawTF
{
    hkDataObjectImplTF* m_pClassImpl;
    void* m_handle;
};
struct ValueTF
{
    ValueTF(const ValueRawTF& r)
    {
        m_handle = r.m_handle;
        m_pClassImpl = r.m_pClassImpl;
    }
    hkDataObjectImplTF* m_pClassImpl;
    void* m_handle;
};
class hkDataObjectTF
{
  public:
    hkDataObjectTF(hkDataObjectImplTF* pkImpl)
    {
        hkDataObject_hkDataObject(pkImpl);
    }
    hkDataObjectTF(const hkDataObjectTF& kOther)
    {
        AssignRef(kOther);
    }
    __forceinline hkDataObjectTF(hkDataObjectTF& other, hkLocalArrayTF<MemberInfoTF>& members,
                                 hkLocalArrayTF<bool>& used, hkDataClassTF& pClassInfo)
    {
        AssignRef(other);
        members.clearLocal();
        members.clearStorage();
        used.clearLocal();
        used.clearStorage();
        other.close();
        pClassInfo.close();
    }
    void close()
    {
        ReleaseStorage_00dba7f0();
    }
    void hkDataObject_hkDataObject(hkDataObjectImplTF* pkImpl);
    void AssignRef(const hkDataObjectTF& kOther);
    void ReleaseStorage_00dba7f0();
    ValueRawTF* UpdateState_00dba870(ValueRawTF* out, const char* pcName);
    ValueTF operator[](const char* pcName)
    {
        ValueRawTF raw;
        return *UpdateState_00dba870(&raw, pcName);
    }
    hkDataObjectImplTF* getImplementation() const
    {
        return m_pClassImpl;
    }
    hkDataObjectImplTF* m_pClassImpl;
};
class hkDataWorldTF
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual hkDataObjectImplTF* GetObject(const hkDataClassTF& kClass);
};
class hkBinaryTagfileReaderTF
{
  public:
    int ReadTag()
    {
        return ::ReadSignedVarInt32(this);
    }
    void ReadBits(int iNumMembers, hkArrayTFLocalForm<bool>& kUsed);
    void ReadTypedTagValue(hkDataObjectImplTF* impl, void* handle, const MemberInfoTF& kInfo);
    hkDataObjectTF ReadDataObject(int aiAllocationTag);
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkDataWorldTF* m_pOwningWorld;
    int unk14;
    hkArrayTFLocalForm<hkDataClassImpl*> m_kLookupMap;
    int unk24;
    int unk28;
    int unk2C;
    hkArrayTFLocalForm<hkDataObjectImplTF*> m_remembered;
};
// Reads a data object from the binary tagfile stream, resolves its class and members, reads present values, and returns the object.
// @fnv 0x00dc6970
// src: GUESS 0x00dc6970 (confidence: medium)
hkDataObjectTF hkBinaryTagfileReaderTF::ReadDataObject(int aiAllocationTag)
{
    int iTagType = aiAllocationTag;
    if (iTagType == -1)
        iTagType = ReadTag();
    if (iTagType == 5)
        return hkDataObjectTF(m_remembered[ReadTag()]);
    if (iTagType == 6)
        return hkDataObjectTF(0);
    hkDataClassTF kClass(m_kLookupMap[ReadTag()]);
    int iNumMembers = kClass.ForwardCall_00dba730();
    hkDataObjectTF kObj(m_pOwningWorld->GetObject(kClass));
    switch (iTagType)
    {
    case 4:
        m_remembered.AddBack(kObj.getImplementation());
        break;
    case 3:
        break;
    default: {
        unsigned int auiBuf[128];
        hkOstreamTF kOstr(auiBuf, sizeof(auiBuf));
        kOstr << "corrupt file";
        if (DAT_01268360->message(3, 0x484994d5, (const char*)auiBuf, ".\\Tagfile\\Binary\\hkBinaryTagfileReader.cpp",
                                  376))
            __debugbreak();
        kOstr.close();
        break;
    }
    }
    hkLocalArrayTF<bool> kUsedMembers(128);
    ReadBits(iNumMembers, kUsedMembers);
    hkLocalArrayTF<MemberInfoTF> kMembers(iNumMembers);
    kMembers.setSizeUnchecked(iNumMembers);
    kClass.DispatchItems(kMembers);
    for (int i = 0; i < iNumMembers; ++i)
    {
        const MemberInfoTF& kInfo = kMembers[i];
        if (kUsedMembers[i])
        {
            ValueRawTF raw;
            ValueRawTF* r = kObj.UpdateState_00dba870(&raw, kInfo.m_name);
            ReadTypedTagValue(r->m_pClassImpl, r->m_handle, kInfo);
        }
    }
    return hkDataObjectTF(kObj, kMembers, kUsedMembers, kClass);
}

__forceinline hkMemoryRouter* getTagRouter()
{
    return &hkMemoryRouter_getInstance();
}
template <class T> struct TagArray
{
    T* data;
    int size;
    int capacity;
    __forceinline TagArray() : data(0), size(0), capacity(0x80000000)
    {}
    static __forceinline T* allocateNonzero(hkMemoryAllocator* a, int& count)
    {
        int bytes = count * sizeof(T);
        T* p = static_cast<T*>(a->bufAlloc(bytes));
        count = bytes / int(sizeof(T));
        return p;
    }
    static __forceinline T* allocateChunk(hkMemoryAllocator* a, int& count)
    {
        return count ? allocateNonzero(a, count) : 0;
    }
    __forceinline TagArray(int count) : data(0), size(0), capacity(0x80000000)
    {
        T* p = allocateChunk(reinterpret_cast<hkMemoryAllocator*>(getTagRouter()->m_temp), count);
        int flags = count ? count : 0x80000000;
        data = p;
        size = count;
        capacity = flags;
    }
    __forceinline void reserve(hkMemoryAllocator* a, int count)
    {
        int current = capacity & 0x3fffffff;
        if (current < count)
        {
            int grown = current * 2;
            hkArrayUtil__reserve(a, this, count >= grown ? count : grown, sizeof(T));
        }
    }
    __forceinline void release(hkMemoryAllocator* a)
    {
        size = 0;
        if (!(capacity & 0x80000000))
            a->bufFree(data, (capacity & 0x3fffffff) * sizeof(T));
    }
};
template <class T> struct TagLocalArray : TagArray<T>
{
    T* original;
    __forceinline void allocateLocal(int count)
    {
        hkMemoryRouter* router = getTagRouter();
        T* p = reinterpret_cast<T*>(router->m_stack.m_next.m_storage);
        router->m_stack.m_next.m_storage = (char*)router->m_stack.m_next.m_storage + ((count * sizeof(T) + 127) & ~127);
        data = p;
        original = p;
        capacity = count | 0x80000000;
    }
    __forceinline void releaseLocal()
    {
        T* p = original;
        if (p == data)
            size = 0;
        getTagRouter()->m_stack.m_next.m_storage = (void*)(reinterpret_cast<int>(p));
        release(getTagRouter()->m_heap);
        data = 0;
        capacity = 0x80000000;
    }
};
struct TagArrayValue;
struct TagClass;
struct TagString
{
    void* object;
    void ReleaseStorage_00dba7f0() throw();
    __forceinline ~TagString() throw()
    {
        ReleaseStorage_00dba7f0();
    }
};
struct TagArrayRef
{
    void* object;
    int ForwardCall_00dbac10();
    TagArrayValue UpdateState_00dbab90(int) throw();
    void hkDataArray_setAll_00dbae10(const char*, int);
    void InvokeVirtualMethod_00dbae80(const float*, int);
    void Get_Thunk(int);
    TagClass ProcessAndReturnValue_00dbac20();
    TagArrayRef InvokeCallbackInto(const char*);
    void ReleaseStorage_00dbab70();
};
struct TagArrayValue
{
    void* array;
    int index;
    void InvokeOnInterface(int);
    void InvokeVirtualMethod_00dbad60(const float*, int);
    void InvokeVirtualMethod_00dbad00(const TagString&) throw();
    void InvokeVirtualMethod_00dbadc0(const char*);
    TagArrayRef GetMemberArrayValue();
};
struct TagMember
{
    const char* name;
    void* type;
    void* pClassInfo;
    int flags;
    int tupleSize;
    __forceinline TagMember() : name(0), type(0), pClassInfo(0), flags(0), tupleSize(0)
    {}
};
struct TagClass
{
    void* object;
    int ForwardCall_00dba730();
    void DispatchItems(TagArray<TagMember>&);
    void Object_DoNothing_00dba660();
};
struct TagReader
{
    int ReadSignedVarInt32();
    void hkIArchive_readArrayGeneric(void*, int, int);
    TagString ReadDataObject(int) throw();
    const char* ReadString();
    void ReadBits(int, TagArray<char>&);
    void ReadTypedArray(TagArrayRef*, int);
};
// Reads an array of 'count' elements from the tag stream into the given TagArrayRef, dispatching on the element type code.
// @fnv 0x00dc6100
// src: GUESS 0x00dc6100 (confidence: medium)
void TagReader::ReadTypedArray(TagArrayRef* array, int count)
{
    switch (array->ForwardCall_00dbac10())
    {
    case 1: {
        TagArray<char> values(count);
        values.reserve(reinterpret_cast<hkMemoryAllocator*>(getTagRouter()->m_temp), count);
        hkIArchive_readArrayGeneric(values.data, 1, count);
        array->hkDataArray_setAll_00dbae10(values.data, count);
        values.release(reinterpret_cast<hkMemoryAllocator*>(getTagRouter()->m_temp));
        break;
    }
    case 2:
        for (int i = 0; i < count; ++i)
            array->UpdateState_00dbab90(i).InvokeOnInterface(ReadSignedVarInt32());
        break;
    case 3: {
        TagArray<float> values(count);
        values.reserve(reinterpret_cast<hkMemoryAllocator*>(getTagRouter()->m_temp), count);
        values.size = count;
        hkIArchive_readArrayGeneric(values.data, 4, count);
        array->InvokeVirtualMethod_00dbae80(values.data, values.size);
        values.release(reinterpret_cast<hkMemoryAllocator*>(getTagRouter()->m_temp));
        break;
    }
    case 4: {
        int width = ReadSignedVarInt32();
        float values[4] = {0, 0, 0, 0};
        for (int i = 0; i < count; ++i)
        {
            hkIArchive_readArrayGeneric(values, 4, width);
            array->UpdateState_00dbab90(i).InvokeVirtualMethod_00dbad60(values, 4);
        }
        break;
    }
    case 6:
    case 7: {
        int width = 4 * (array->ForwardCall_00dbac10() - 3);
        for (int i = 0; i < count; ++i)
        {
            float values[16];
            for (int j = 0; j < width; ++j)
            {
                float value;
                hkIArchive_readArrayGeneric(&value, 4, 1);
                values[j] = value;
            }
            array->UpdateState_00dbab90(i).InvokeVirtualMethod_00dbad60(values, width);
        }
        break;
    }
    case 8:
        for (int i = 0; i < count; ++i)
        {
            array->UpdateState_00dbab90(i).InvokeVirtualMethod_00dbad00(ReadDataObject(-1));
        }
        break;
    case 10:
        for (int i = 0; i < count; ++i)
            array->UpdateState_00dbab90(i).InvokeVirtualMethod_00dbadc0(ReadString());
        break;
    case 9: {
        array->Get_Thunk(count);
        TagClass pClassInfo = array->ProcessAndReturnValue_00dbac20();
        int membersCount = pClassInfo.ForwardCall_00dba730();
        TagLocalArray<char> presentBits;
        presentBits.allocateLocal(128);
        ReadBits(membersCount, presentBits);
        TagLocalArray<TagMember> members;
        members.allocateLocal(membersCount);
        int toConstruct = membersCount - members.size;
        TagMember* first = members.data + members.size;
        for (int k = 0; k < toConstruct; ++k)
            new (first + k) TagMember;
        members.size = membersCount;
        pClassInfo.DispatchItems(members);
        int i = 0;
        if (membersCount > 0)
        {
            int byteOffset = 0;
            do
            {
                TagMember& member = *reinterpret_cast<TagMember*>(reinterpret_cast<char*>(members.data) + byteOffset);
                if (presentBits.data[i])
                {
                    TagArrayRef field = array->InvokeCallbackInto(member.name);
                    if (!member.tupleSize)
                    {
                        ReadTypedArray(&field, count);
                    }
                    else
                    {
                        for (int j = 0; j < count; ++j)
                        {
                            TagArrayRef item = field.UpdateState_00dbab90(j).GetMemberArrayValue();
                            ReadTypedArray(&item, member.tupleSize);
                            item.ReleaseStorage_00dbab70();
                        }
                    }
                    field.ReleaseStorage_00dbab70();
                }
                ++i;
                byteOffset += sizeof(TagMember);
            } while (i < membersCount);
        }
        members.releaseLocal();
        presentBits.releaseLocal();
        pClassInfo.Object_DoNothing_00dba660();
        break;
    }
    }
}

struct Item20
{
    void* name;
    int subtype;
    int flags;
    void* objectClass;
    int tupleSize;
};
struct RefA
{
    void* object;
    void hkDataObject_hkDataObject(void*);
    void ReleaseStorage_00dba7f0();
};
struct RefB
{
    void* object;
    void FUN_00dbab50(void*);
    void ReleaseStorage_00dbab70();
    void Get_Thunk(int);
};
struct ParamP
{
    void* object;
    int member;
    int QueryAndWriteResult();
    void ForwardCall_00dbaa30(int);
    void ForwardCall_00dbaa90(int, int);
    void Apply_Thunk(float*, int);
    void DispatchToObject(RefA*);
    void DispatchFloatToVtbl(float);
    void ForwardCall_00dbab30(const char*);
};
extern "C" unsigned __int64 __fastcall ReadVarInt(void*);
extern "C" float __fastcall hkIArchive_readFloat32(void*);
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
struct ValueWorld
{
    virtual void dummy0();
    virtual void dummy1();
    virtual void dummy2();
    virtual void* vtable_0c(Struct3*);
    virtual void dummy4();
    virtual void* vtable_14(RefA*, const Item20*);
    virtual int* vtable_18(void*);
    virtual void dummy7();
    virtual void dummy8();
    virtual void vtable_24(char*);
};
struct ValueReader : TagFileReader
{
    void ReadTypedArray(RefB*, int);
    void hkIArchive_readArrayGeneric(void*, int, int);
    void ReadDataObject(RefA*, int);
    void ReadTypedTagValue(ParamP, const Item20*);
};
// Reads a typed value from the tag file stream into ParamP based on Item20 flags, handling scalars, vectors, objects, and references.
// @fnv 0x00dc6720
// src: GUESS 0x00dc6720 (confidence: medium)
void ValueReader::ReadTypedTagValue(ParamP value, const Item20* item)
{
    RefA owner;
    if (item->flags & 0x20)
    {
        owner.hkDataObject_hkDataObject(value.object);
        void* created = reinterpret_cast<ValueWorld*>(m_p10)->vtable_14(&owner, item);
        RefB reference;
        reference.FUN_00dbab50(created);
        ReadTypedArray(&reference, item->tupleSize);
        reference.ReleaseStorage_00dbab70();
        owner.ReleaseStorage_00dba7f0();
        return;
    }
    if (item->flags & 0x10)
    {
        Item20 local;
        memcpy(&local, item, sizeof(local));
        int index = ReadSignedVarInt32(this);
        if (value.QueryAndWriteResult() == 0x19 && item->objectClass == 0)
        {
            int objectIndex = ReadSignedVarInt32(this);
            local.objectClass = m_kTrackedObjects.m_data[objectIndex];
        }
        owner.hkDataObject_hkDataObject(value.object);
        void* created = reinterpret_cast<ValueWorld*>(m_p10)->vtable_14(&owner, &local);
        RefB reference;
        reference.FUN_00dbab50(created);
        reference.Get_Thunk(index);
        ReadTypedArray(&reference, index);
        reference.ReleaseStorage_00dbab70();
        owner.ReleaseStorage_00dba7f0();
        return;
    }
    switch (item->flags)
    {
    case 1: {
        unsigned char scalar;
        hkIArchive_readArrayGeneric(&scalar, 1, 1);
        value.ForwardCall_00dbaa30(scalar);
        break;
    }
    case 2: {
        unsigned __int64 scalar = ReadVarInt(this);
        value.ForwardCall_00dbaa90((int)scalar, (int)(scalar >> 32));
        break;
    }
    case 3: {
        float scalar = hkIArchive_readFloat32(this);
        value.DispatchFloatToVtbl(scalar);
        break;
    }
    case 4:
    case 6:
    case 7: {
        float values[16];
        float scalar;
        int count = item->flags * 4 - 12;
        for (int i = 0; i < count; ++i)
        {
            hkIArchive_readArrayGeneric(&scalar, 4, 1);
            values[i] = scalar;
        }
        value.Apply_Thunk(values, count);
        break;
    }
    case 8:
    case 9: {
        RefA object;
        ReadDataObject(&object, -1);
        value.DispatchToObject(&object);
        object.ReleaseStorage_00dba7f0();
        break;
    }
    case 10:
        value.ForwardCall_00dbab30(ReadString(this));
        break;
    default:
        break;
    }
}
