
// src/havok/common/base/system/io/ostream/hkostream.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/system/io/ostream/hkostream.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/NiBinaryStream.h"
#include "../../../../../../../include/NiStream.h"
#include "../../../../../../../include/HavokError.h"
#include "../../../../../../../include/bhkMoppBvTreeShape.h"
#include "../../../../../../../include/hkArray.h"
#include "../../../../../../../include/hkBaseObject.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkReferencedObject.h"

// hkMemoryRouter is the shared Havok memory-router layout: heap allocator at +0x10.
namespace HavokHeap {
extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance() throw();
}



__declspec(nothrow) inline void* hkReferencedObject::operator new(std::size_t nbytes)
{
    hkReferencedObject* b = static_cast<hkReferencedObject*>(
        HavokHeap::hkMemoryRouter_getInstance().heap().blockAlloc(nbytes));
    b->m_usMemSizeAndFlags = (unsigned short)nbytes;
    return b;
}
inline void hkReferencedObject::operator delete(void* p)
{
    HavokHeap::hkMemoryRouter_getInstance().heap().blockFree(
        p, static_cast<hkReferencedObject*>(p)->m_usMemSizeAndFlags);
}

__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return HavokHeap::hkMemoryRouter_getInstance().heap();
}

template <class T>
__forceinline void hkArrayBase<T>::GrowArrayCapacity(hkMemoryAllocator& kHeap, int iWanted)
{
    const int iHave = getCapacity();
    if (iHave < iWanted)
    {
        int iTwice = 2 * iHave;
        int iGrowTo = (iWanted < iTwice) ? iTwice : iWanted;
        hkArrayUtil::_reserve(kHeap, this, iGrowTo, sizeof(T));
    }
}

template <class T, class Allocator>
__forceinline hkArray<T, Allocator>::~hkArray()
{
    hkMemoryAllocator& alloc = Allocator().get(this);
    this->m_iElementCount = 0;
    if ((this->m_iCapacityState & 0x80000000) == 0)
        alloc.bufFree(this->m_data, (this->m_iCapacityState & 0x3fffffff) * sizeof(T));
    this->m_data = 0;
    this->m_iCapacityState = 0x80000000;
}


extern int DAT_01268108;
extern "C" __declspec(dllimport) void __stdcall free(void*);

// @fnv 0x00c85750
// src: XBOX_PDB 0x00c85750
void __cdecl hkMemoryRouter_getInstance()
{
    free((void*)DAT_01268108);
}

extern char _DAT_010c9314;
extern char _DAT_0102e388;
struct Old
{
    void ReleaseReference();
};
struct FUN_00cc00e0
{
    void* vtbl;
    int m_ref;
    Old* m_pStreamWriter;
    ~FUN_00cc00e0();
};
// @fnv 0x00cc00e0
FUN_00cc00e0::~FUN_00cc00e0()
{
    vtbl = (void*)&_DAT_010c9314;
    if (m_pStreamWriter)
        m_pStreamWriter->ReleaseReference();
    vtbl = (void*)&_DAT_0102e388;
}


struct DDCC60WorldStandIn
{
    int m_uiStandInValue;
    int m_iValueAfterStandIn;
    hkReferencedObject* m_ref;
    void UpdateFields_00cc0480(hkReferencedObject* pNew);
};
// @fnv 0x00cc0480
// src: GUESS 0x00cc0480 (confidence: low)
void DDCC60WorldStandIn::UpdateFields_00cc0480(hkReferencedObject* pNew)
{
    pNew->addReference();
    m_ref->removeReference();
    m_ref = pNew;
}

struct FUN_00cc0680
{
    int tell();
};

// @fnv 0x00cc0680
int FUN_00cc0680::tell()
{
    char* p = *(char**)(this + 8);
    int n = *(int*)(p + 0xc) - 1;
    return *(int*)(p + 4) + *(int*)(p + 0) * n;
}

extern hkMemoryRouter* _D1A0E0GetMemoryRouter();

struct FUN_00cc07f0_StandIn
{
    // Virtual destructor for the stand-in type; does nothing.
// @fnv 0x00cc07f0
    virtual ~FUN_00cc07f0_StandIn()
    {}
    void FUN_00cc0780();
    unsigned short m_nSize;

    FUN_00cc07f0_StandIn* FUN_00cc07f0(unsigned int deletingFlag);
};

FUN_00cc07f0_StandIn* FUN_00cc07f0_StandIn::FUN_00cc07f0(unsigned int deletingFlag)
{
    FUN_00cc0780();

    if (deletingFlag & 1)
    {
        hkMemoryRouter* memoryRouter = _D1A0E0GetMemoryRouter();
        unsigned short size = m_nSize;
        memoryRouter->heap().blockFree(this, size);
    }

    return this;
}

struct CpuInterface
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void Invoke();
};
struct CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    CpuInterface* target;
    void InvokeVirtualMethod_00cc0460();
};
// @fnv 0x00cc0460
// src: GUESS 0x00cc0460 (confidence: low)
void CpuObject::InvokeVirtualMethod_00cc0460()
{
    target->Invoke();
}

// FUN_00cc0470 : the stub family - load a sub-object out of `this` and tail-jump to
// one of its virtuals (vtable offset 0x10).
struct Sub_00cc0470
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10(void* a);
};

struct Own_00cc0470
{
    int u00;
    int u04;
    Sub_00cc0470* m_sub;
    void __thiscall ForwardCall_00cc0470(void* a);
};

// @fnv 0x00cc0470
// src: GUESS 0x00cc0470 (confidence: low)
void __thiscall Own_00cc0470::ForwardCall_00cc0470(void* a)
{
    m_sub->v10(a);
}

extern int g_unk01268560;

// @fnv 0x00cc04c0
// src: GUESS 0x00cc04c0 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00cc04c0()
{
    return &g_unk01268560;
}

extern int DAT_01268ad8;

// @fnv 0x00cc0770
// src: GUESS 0x00cc0770 (confidence: low)
int __cdecl hkOstream_EvaluateValue_00cc0770()
{
    return reinterpret_cast<int>(&DAT_01268ad8);
}

// @fnv 0x00e3b490
// src: HAVOK_SRC 0x00e3b490
void __stdcall hkArrayStreamWriter_isOk(bool* p)
{
    *p = true;
}

struct FUN_00cc04a0_Slots
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0C(const char* name, void* value, int flags);
};
struct FUN_00cc04a0_Cls
{
    int unk00;
    int unk04;
    void* unk08;
    void RegisterWriter(FUN_00cc04a0_Slots* target, int unused);
};
// @fnv 0x00cc04a0
void FUN_00cc04a0_Cls::RegisterWriter(FUN_00cc04a0_Slots* apSlots, int unused)
{
    apSlots->slot0C("writer", unk08, 0);
}

class FUN_00cc06f0 : public hkReferencedObject
{
  public:
    int unk08;
    int unk0C;
    int unk10;

    FUN_00cc06f0(void* owner, int flag) throw();
};

class FUN_00cc0630 : public hkReferencedObject
{
  public:
    FUN_00cc06f0* m_pChildAtom;

    FUN_00cc0630(void* owner);
    virtual ~FUN_00cc0630();
};

// @fnv 0x00cc0630
FUN_00cc0630::FUN_00cc0630(void* owner)
{
    m_pChildAtom = new FUN_00cc06f0(owner, 1);
}

namespace fnv_00cc0690 {

class FUN_00d46be0_class
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;

    void UpdateFields_00d46be0() throw();
    ~FUN_00d46be0_class() throw()
    {
        UpdateFields_00d46be0();
    }
    static void operator delete(void* p) throw()
    {
        HavokHeap::hkMemoryRouter_getInstance().heap().blockFree(p, sizeof(FUN_00d46be0_class));
    }
};

class hkStreamCC06 : public hkReferencedObject
{
  public:
    FUN_00d46be0_class* m_stream;
    void* m_external;

    virtual ~hkStreamCC06() throw()
    {
        if (m_external == 0)
            delete m_stream;
    }
    hkStreamCC06* DestroyStream(unsigned int uiFlags) throw();
};

// Destroys the stream object and, when bit 0 of uiFlags is set, frees its memory via operator delete; returns this.
// @fnv 0x00cc0690
hkStreamCC06* hkStreamCC06::DestroyStream(unsigned int uiFlags) throw()
{
    this->hkStreamCC06::~hkStreamCC06();
    if (uiFlags & 1)
        hkStreamCC06::operator delete(this);
    return this;
}
}  // namespace fnv_00cc0690

namespace fnv_00cc06f0 {

class FUN_00cc06f0 : public hkReferencedObject
{
  public:
    hkArray<char>* m_buffer;
    int m_kRayStart;
    int m_flags;

    FUN_00cc06f0(hkArray<char>* buffer, int flags) throw();
    virtual ~FUN_00cc06f0() throw();
};

// Stores the buffer and its size, reserves one extra char, and appends a terminating null byte.
// @fnv 0x00cc06f0
FUN_00cc06f0::FUN_00cc06f0(hkArray<char>* buffer, int flags) throw()
    : m_buffer(buffer), m_kRayStart(buffer->m_iElementCount), m_flags(flags)
{
    buffer->reserve(buffer->m_iElementCount + 1);
    m_buffer->m_data[m_buffer->m_iElementCount] = 0;
}
}  // namespace fnv_00cc06f0

class FUN_00cc0780 : public hkReferencedObject
{
  public:
    hkArray<unsigned char>* m_buffer;
    int unk0C;
    int m_external;

    virtual ~FUN_00cc0780() throw();
};

// Destructor that deletes m_buffer unless m_external is set.
// @fnv 0x00cc0780
FUN_00cc0780::~FUN_00cc0780() throw()
{
    if (!m_external)
    {
        hkArray<unsigned char>* buffer = m_buffer;
        if (buffer)
        {
            buffer->~hkArray();
            HavokHeap::hkMemoryRouter_getInstance().heap().blockFree(buffer, sizeof(*buffer));
        }
    }
}

struct GlobalObject_0045cfe0
{
    ~GlobalObject_0045cfe0();
    int unk00;
};

class FUN_00cbf430 : public GlobalObject_0045cfe0
{
  public:
    ~FUN_00cbf430();
    void bhkMultithreadedSystem_QuitMTSystem();
};

// @fnv 0x00cbf430
FUN_00cbf430::~FUN_00cbf430()
{
    bhkMultithreadedSystem_QuitMTSystem();
}

class FUN_00d60b40 : public hkReferencedObject
{
  public:
    FUN_00cc06f0* m_pChildAtom;
    char m_flag;

    FUN_00d60b40(void* owner, char flag) throw();
    virtual ~FUN_00d60b40();
};

// Sets m_flag and assigns m_pChildAtom to a new FUN_00cc06f0 constructed with owner and 1.
// @fnv 0x00d60b40
FUN_00d60b40::FUN_00d60b40(void* owner, char flag) throw()
{
    m_flag = flag;
    m_pChildAtom = new FUN_00cc06f0(owner, 1);
}


extern HavokError* DAT_01268360;

struct BoolType
{
    char m_cBooleanValue;
    BoolType(bool b) : m_cBooleanValue(b)
    {}
    BoolType(const BoolType& o) : m_cBooleanValue(o.m_cBooleanValue)
    {}
};

namespace MoppLoadStream {
struct FUN_00cc00e0
{
    void* vtbl;
    int m_ref;
    Old* m_pStreamWriter;
    __declspec(noinline) ~FUN_00cc00e0();
};
}

struct OStream : public MoppLoadStream::FUN_00cc00e0
{
    OStream(void* mem, int GetAllocationSize, BoolType isArray);
    OStream& operator<<(const char* s);
};

struct MoppCodeHeader
{
    int unk00;
    int unk04;
    int unk08;
    unsigned long m_data;
};


extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);

// Gets a size and buffer, reads binary data and warns for versions below 6, otherwise calls FUN_00c87710 and may byte-swap m_data.
// @fnv 0x00cc9f60
// src: XBOX_PDB 0x00cc9f60
unsigned int bhkMoppBvTreeShape::LoadCInfo(NiStream& stream)
{
    unsigned int size = slotA8();
    char allocated;
    MoppCodeHeader* buffer = slotB4(&allocated);

    // NiStream keeps these fields opaque in the shared header.
    if (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&stream) + 4) < 6)
    {
        NiBinaryStream* pBinaryStream =
            *reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(&stream) + 0x24c);
        // The shared header does not yet declare the position counter or read callback.
        *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(pBinaryStream) + 4) +=
            (*reinterpret_cast<NiBinaryStream::NIBINARYSTREAM_READFN*>(reinterpret_cast<char*>(pBinaryStream) + 8))(
                pBinaryStream, buffer, size -= 4, 0, 0);

        const char* pcFileName = (reinterpret_cast<char*>(&stream) + 0xe0);
        const char* pcAuthor = (reinterpret_cast<char*>(&stream) + 8);
        if (!*pcAuthor)
        {
            pcAuthor = "Please";
        }

        char szWarning[512];
        OStream s(szWarning, sizeof(szWarning), true);
        s << "File " << pcFileName << " contains an old bhkMoppBvTreeShape! " << pcAuthor << " re-export\n";
        DAT_01268360->message(1, 0x234f2250, szWarning,
                              "D:\\_Fallout3\\Platforms\\Common\\Code\\BSHavok\\bhkMoppBvTreeShape.cpp", 187);
    }
    else
    {
        bhkSerializable_LoadCInfo(stream);
        if (*reinterpret_cast<char*>(reinterpret_cast<char*>(&stream) + 0x1e5) != 1)
        {
            buffer->m_data = _byteswap_ulong(buffer->m_data);
        }
    }

    return size;
}
