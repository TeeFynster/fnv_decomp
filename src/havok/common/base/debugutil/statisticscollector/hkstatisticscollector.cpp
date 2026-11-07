
// src/havok/common/base/debugutil/statisticscollector/hkstatisticscollector.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/debugutil/statisticscollector/hkstatisticscollector.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/hkMemoryRouter.h"

extern int DAT_0102e388;

struct FUN_00d06f70_s
{
    int* p;
    int x;
    int y;
    void InitializeFields_00d06f70();
};

// @fnv 0x00d06f70
// src: GUESS 0x00d06f70 (confidence: low)
void FUN_00d06f70_s::InitializeFields_00d06f70()
{
    y = 0;
    p = &DAT_0102e388;
}

int __cdecl hkStatisticsCollector_getAllocatedSize(void* apBuffer, int aiCount);

struct FUN_00d06fb0_cls
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void Dispatch(int aiFlag, void* apFirst, void* apSecond, int aiCount, int aiMode);

    void DispatchWithMode(void* apFirst, void* apSecond, int aiCount, int aiMode);
};

// Computes a mode from apSecond and aiCount when aiCount is positive and aiMode is zero, then dispatches with flag 1.
// @fnv 0x00d06fb0
void FUN_00d06fb0_cls::DispatchWithMode(void* apFirst, void* apSecond, int aiCount, int aiMode)
{
    int iMode = aiMode;
    if (aiCount > 0 && iMode == 0)
        iMode = hkStatisticsCollector_getAllocatedSize(apSecond, aiCount);

    Dispatch(1, apFirst, apSecond, aiCount, iMode);
}

extern "C" int __cdecl hkString_strLen(const char* s);
extern "C" int __cdecl hkStatisticsCollector_getAllocatedSize(const char* s, int len);

class Handler
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void Emit(int kind, int a, const char* s, int len, int hash);
    void EmitString(int a, unsigned int* str);
};

// If the string pointer in str is non-null, computes its length and hash and emits it via Emit with kind 3.
// @fnv 0x00d07030
void Handler::EmitString(int a, unsigned int* str)
{
    const char* s = (const char*)(*str & ~1u);
    if (s)
    {
        int len = hkString_strLen(s);
        Emit(3, a, s, len, hkStatisticsCollector_getAllocatedSize(s, len));
    }
}

class Allocator
{
  public:
    virtual void v00();
    virtual void* Alloc(unsigned int size);
    virtual void Free(void* ptr, unsigned int size);
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual int ComputeHash(const void* data, int len);
};

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
void* __cdecl FUN_00ec44d0(void* dst, const void* src, unsigned int count);

struct GrowBuf
{
    void* m_pData;
    unsigned short m_uCap;
    unsigned short m_uiObjectFlags;
};

// @fnv 0x00d06cb0
// src: HAVOK_LIB 0x00d06cb0
void __cdecl hkSmallArrayUtil__reserveMore(GrowBuf* buf, unsigned int elemSize)
{
    unsigned int newCount;
    if (buf->m_uCap != 0)
    {
        newCount = (unsigned int)buf->m_uCap * 2;
    }
    else
    {
        newCount = 1;
    }

    hkMemoryRouter* holder = hkMemoryRouter_getInstance();
    void* newData = holder->m_heap->blockAlloc(newCount * elemSize);
    FUN_00ec44d0(newData, buf->m_pData, (unsigned int)buf->m_uCap * elemSize);

    if ((buf->m_uiObjectFlags & 0x8000u) == 0)
    {
        void* oldData = buf->m_pData;
        unsigned int oldBytes = (buf->m_uiObjectFlags & 0x3fffu) * elemSize;
        hkMemoryRouter* pAllocHolder2 = hkMemoryRouter_getInstance();
        pAllocHolder2->m_heap->blockFree(oldData, oldBytes);
    }

    buf->m_pData = newData;
    buf->m_uiObjectFlags = (unsigned short)((buf->m_uiObjectFlags & 0x4000u) | newCount);
}

struct D06D50Class;

struct D06D50Object
{
    virtual void unk00();
    virtual const D06D50Class* getClassType() const;
};

struct D06D50Registry
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual const D06D50Class* GetClassFromName(const D06D50Object* object) const;
};

struct D06D50Finder
{
    int unk00;
    int unk04;
    int unk08;
    const D06D50Registry* m_registry;

    const D06D50Class* FindClass(const D06D50Object* object) const;
};

// @fnv 0x00d06d50
const D06D50Class* D06D50Finder::FindClass(const D06D50Object* object) const
{
    if (object)
    {
        const D06D50Class* pClass = object->getClassType();
        if (pClass)
            return pClass;
        if (m_registry)
        {
            pClass = m_registry->GetClassFromName(object);
            if (pClass)
                return pClass;
        }
    }
    return 0;
}

struct FUN_00d06d90_cls;

struct Rec
{
    int unk00;
    unsigned short m_04;
};

struct Inner
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void* Query(Rec* a);
};

struct Tail
{
    int Process();
};

struct FUN_00d06d90_cls
{
    int unk00;
    int unk04;
    int unk08;
    Inner* m_0c;
    unsigned char m_10;

    int GetFlagsOrProcess(Rec* a);
};

// Reads the low 15 bits of a->m_04; if zero and m_10 is set, queries m_0c and returns Process() on the result, otherwise returns the flags.
// @fnv 0x00d06d90
int FUN_00d06d90_cls::GetFlagsOrProcess(Rec* pRec)
{
    unsigned int flags = pRec->m_04 & 0x7fff;
    if (flags == 0 && m_10 != 0)
    {
        void* r = m_0c->Query(pRec);
        if (r != 0)
        {
            return ((Tail*)r)->Process();
        }
        flags = 0;
    }
    return flags;
}

namespace fnv_00d06dd0 {
struct S_00d06dd0_Obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void slot14(int a, int b, int c, int d, int e);
    int GetFlagsOrProcess(int a);
    void DispatchIfNotFlagged(int a, unsigned int flags);
};

// When bit 0 of flags is clear, computes a value from a, calls the allocator with both, and passes the results to slot14.
// @fnv 0x00d06dd0
void S_00d06dd0_Obj::DispatchIfNotFlagged(int a, unsigned int flags)
{
    if ((flags & 1) == 0)
    {
        int b = GetFlagsOrProcess(a);
        int r = (&hkMemoryRouter_getInstance()->heap())->getAllocatedSize((const void*)a, b);
        slot14(0, 0, a, b, r);
    }
}
}  // namespace fnv_00d06dd0

namespace fnv_00d06e10 {
struct FUN_00d06e10_src
{
    int Read();
};

class FUN_00d06e10_cls
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void Emit(int kind, int a, const char* s, int len, int hash);

    void hkStatisticsCollector_addObjectMemory(int a1, int a2, unsigned char flag);
};

// When flag bit 0 is clear, reads a length from a1, computes a hash through the allocator, and calls Emit with that length and hash.
// @fnv 0x00d06e10
// src: HAVOK_LIB 0x00d06e10
void FUN_00d06e10_cls::hkStatisticsCollector_addObjectMemory(int pSource, int pData, unsigned char flag)
{
    if ((flag & 1) == 0)
    {
        int len = ((FUN_00d06e10_src*)pSource)->Read();
        hkMemoryRouter* holder = hkMemoryRouter_getInstance();
        int hash = holder->m_heap->getAllocatedSize((const void*)pData, len);
        Emit(0, 0, (const char*)pData, len, hash);
    }
}
}  // namespace fnv_00d06e10

class D06F50ReferencedObject
{
  public:
    D06F50ReferencedObject() : m_sReferenceCount(1)
    {}
    virtual void unk00();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class FUN_00d06f50 : public D06F50ReferencedObject
{
  public:
    FUN_00d06f50(void* owner);
    virtual void unk00();

    int unk08;
    void* m_pOwnerObject;
    bool m_flag;
};

// @fnv 0x00d06f50
FUN_00d06f50::FUN_00d06f50(void* owner) : m_pOwnerObject(owner), m_flag(false)
{}

namespace fnv_00d06f80 {
// If s is non-null, hashes it through the allocator; otherwise returns len.
// @fnv 0x00d06f80
// src: HAVOK_LIB 0x00d06f80
extern "C" int __cdecl hkStatisticsCollector_getAllocatedSize(const char* pcString, int iLength)
{
    if (pcString)
    {
        hkMemoryRouter* holder = hkMemoryRouter_getInstance();
        return holder->m_heap->getAllocatedSize(pcString, iLength);
    }

    return iLength;
}
}  // namespace fnv_00d06f80

int __cdecl hkStatisticsCollector_getAllocatedSize(int aiB, int aiC);

struct FUN_00d06ff0_cls
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void V14(int aiZero, int aiA, int aiB, int aiC, int aiR);

    void hkStatisticsCollector_addObjectChunk(int aiA, int aiB, int aiC, int aiD);
};

// If aiC is positive and aiD is zero, computes a result via FUN_00d06f80(aiB, aiC), then calls V14 with zero, aiA, aiB, aiC and the result.
// @fnv 0x00d06ff0
// src: HAVOK_LIB 0x00d06ff0
void FUN_00d06ff0_cls::hkStatisticsCollector_addObjectChunk(int aiA, int aiB, int aiC, int aiD)
{
    int iResult = aiD;
    if (aiC > 0 && aiD == 0)
        iResult = hkStatisticsCollector_getAllocatedSize(aiB, aiC);
    V14(0, aiA, aiB, aiC, iResult);
}

extern const char str_010cce5c[];
extern const char str_010cce54[];
extern const char str_010cce4c[];
extern const char str_010cce44[];
extern const char str_010cce3c[];
extern const char str_0106f148[];

// Returns one of five fixed string pointers for values 0 through 4, or a fallback pointer otherwise.
// @fnv 0x00d06e60
// src: HAVOK_LIB 0x00d06e60
const char* __cdecl hkStatisticsCollector_memoryTypeToCstring(int value)
{
    switch (value)
    {
    case 0:
        return str_010cce5c;
    case 1:
        return str_010cce54;
    case 2:
        return str_010cce4c;
    case 3:
        return str_010cce44;
    case 4:
        return str_010cce3c;
    default:
        return str_0106f148;
    }
}
