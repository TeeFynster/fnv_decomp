
// src/havok/common/serialize/serialize/platform/hkplatformobjectwriter.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/serialize/platform/hkplatformobjectwriter.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/hkReferencedObject.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/hkArray.h"

struct E02A40StreamWriter
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual int write(const void* buf, int nbytes);
};

// Calls writer->write with buf and nbytes and returns nonzero if the number of bytes written differs from nbytes.
// @fnv 0x00e02a40
int __stdcall WriteAllOrFail(E02A40StreamWriter* writer, const void* buf, int aiNumBytes)
{
    return writer->write(buf, aiNumBytes) != aiNumBytes;
}

struct OffsetView
{
    int unk00;
    int unk04;
    char* unk08;
    char* hkPlatformObjectWriter_getLayout();
};
// @fnv 0x00e02a70
// src: XBOX_PDB 0x00e02a70
char* OffsetView::hkPlatformObjectWriter_getLayout()
{
    return unk08 + 12;
}

struct FUN_00e02d40_helper
{
    __declspec(nothrow) void ClearAndFreeData();
};
struct FUN_00e02c70_audio_iface
{
    virtual __declspec(nothrow) void v0();
    virtual __declspec(nothrow) void v1();
    virtual __declspec(nothrow) void v2(void* object, unsigned int value);
};
void* __cdecl hkMemoryRouter_getInstance();
struct BaseE02c70
{
    int unk04;
    virtual __declspec(nothrow) ~BaseE02c70()
    {}
};
struct FUN_00e02c70_Class : BaseE02c70
{
    hkReferencedObject* unk08;
    FUN_00e02d40_helper* unk0c;
    virtual __declspec(nothrow) ~FUN_00e02c70_Class();
};
// @fnv 0x00e02c70
FUN_00e02c70_Class::~FUN_00e02c70_Class()
{
    hkReferencedObject* reference = unk08;
    reference->removeReference();
    FUN_00e02d40_helper* pHelper = unk0c;
    if (pHelper)
    {
        pHelper->ClearAndFreeData();
        hkMemoryRouter* pAudioHolder = (hkMemoryRouter*)hkMemoryRouter_getInstance();
        reinterpret_cast<FUN_00e02c70_audio_iface*>(pAudioHolder->m_heap)->v2(pHelper, 0x24);
    }
}

class Allocator
{
  public:
    virtual void unk00();
    virtual void* Alloc(unsigned int size);
};

extern char DAT_010ea370[];
extern char DAT_011b7b88[4];

struct IntTemp
{
    int m_v;
    IntTemp(int v) : m_v(v)
    {}
    IntTemp(const IntTemp& o) : m_v(o.m_v)
    {}
};

struct KeyRef
{
    void* m_p;
    void Set(const void* p);
};

struct SpawnedBlob
{
    int unk00;
    unsigned short m_w04;
    unsigned short unk06;
    void* Init(KeyRef* key, int a1, IntTemp a2);
};

struct SpawnedSmall
{
    int unk00;
    unsigned short m_w04;
    unsigned short unk06;
    void* Make();
};

struct FUN_00e02bb0_cls
{
    void* m_vptr;
    unsigned short unk04;
    unsigned short m_w06;
    void* m_p08;
    void* m_p0c;

    char* hkPlatformObjectWriter_getLayout();
    FUN_00e02bb0_cls* hkPlatformObjectWriter_hkPlatformObjectWriter(int a1);
};

// Sets the vtable and flag, allocates and initialises a blob from a key and a1, and conditionally allocates a small object whose Make result is stored in m_p0c.
// @fnv 0x00e02bb0
// src: XBOX_PDB 0x00e02bb0
FUN_00e02bb0_cls* FUN_00e02bb0_cls::hkPlatformObjectWriter_hkPlatformObjectWriter(int a1)
{
    m_w06 = 1;
    m_vptr = DAT_010ea370;
    hkMemoryRouter* pAllocHolder = (hkMemoryRouter*)hkMemoryRouter_getInstance();
    SpawnedBlob* blob = (SpawnedBlob*)pAllocHolder->m_heap->blockAlloc(0x18);
    blob->m_w04 = 0x18;
    KeyRef key;
    key.Set(&DAT_011b7b88);
    m_p08 = blob->Init(&key, a1, IntTemp(2));

    unsigned char* pucData = (unsigned char*)hkPlatformObjectWriter_getLayout();
    SpawnedSmall* small = 0;
    if (!(pucData[0] == (unsigned char)DAT_011b7b88[0] && pucData[1] == (unsigned char)DAT_011b7b88[1] &&
          pucData[2] == (unsigned char)DAT_011b7b88[2] && pucData[3] == (unsigned char)DAT_011b7b88[3]))
    {
        hkMemoryRouter* pAllocHolder2 = (hkMemoryRouter*)hkMemoryRouter_getInstance();
        small = (SpawnedSmall*)pAllocHolder2->m_heap->blockAlloc(0x24);
    }
    m_p0c = small != 0 ? small->Make() : 0;
    return this;
}

// The local array used the hkArray layout and _reserveMore at 0x00c90940.
__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    hkMemoryRouter& kMem = *static_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance());
    return *reinterpret_cast<hkMemoryAllocator*>(kMem.m_heap);
}

template <class T>
__forceinline void hkArrayUtil::constructWithCopy(T* p, int n, const T& t, hkTypeIsPod)
{
    for (int i = 0; i < n; ++i)
        p[i] = t;
}

template <class T>
__forceinline void hkArrayBase<T>::_pushBack(hkMemoryAllocator& alloc, const T& t)
{
    if (m_iElementCount == getCapacity())
        hkArrayUtil::_reserveMore(alloc, this, sizeof(T));
    hkArrayUtil::constructWithCopy(m_data + m_iElementCount, 1, t, hkTypeIsPod());
    m_iElementCount++;
}

struct hkFlagsE02
{
    hkFlagsE02(int iFlags) : m_iFlags(iFlags)
    {}
    hkFlagsE02(const hkFlagsE02& kOther) : m_iFlags(kOther.m_iFlags)
    {}
    int m_iFlags;
};

class hkObjectE02;
class hkRegistryE02;
extern hkRegistryE02 g_kRegistryE02;

class hkLoaderE02;
hkObjectE02* __cdecl CreateObjectE02(const char* pcName, hkRegistryE02* pkRegistry, hkLoaderE02* pkLoader, int iUnk,
                                     int iUnk2, hkFlagsE02 kFlags);

class hkTrackerE02
{
  public:
    void Track(hkObjectE02* pkObject, void* pvOwner, int iUnk);
};

enum hkResultE02
{
    HK_SUCCESS_E02 = 0,
    HK_FAILURE_E02 = 1
};

class hkLoaderE02
{
  public:
    hkResultE02 Get(const char* pcName, hkObjectE02** ppkOut);
    hkObjectE02* GetOrCreateObject(const char* pcName, hkTrackerE02* pkTracker);

    int unk00;
    int unk04;
    int unk08;
    int m_kOwner;
    int unk10;
    int unk14;
    hkArray<hkObjectE02*> m_kThirdFollowingStreamField;
};

// Looks up pcName via Get; if not found, creates the object, appends it to the array, tracks it with pkTracker, and returns it.
// @fnv 0x00e02cb0
hkObjectE02* hkLoaderE02::GetOrCreateObject(const char* pcName, hkTrackerE02* pkTracker)
{
    hkObjectE02* pkObject;
    if (Get(pcName, &pkObject) == HK_SUCCESS_E02)
        return pkObject;

    hkObjectE02* pkNew = CreateObjectE02(pcName, &g_kRegistryE02, this, 0, 0, hkFlagsE02(0));
    m_kThirdFollowingStreamField.pushBack(pkNew);
    pkTracker->Track(pkNew, &m_kOwner, 1);
    return pkNew;
}

struct E02Allocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void FreeArray(void* apMemory, unsigned int auiSize) throw();
};

void __cdecl hkMemoryRouter_easyFree(void* allocator, void* element);

struct E02Sub
{
    int unk00;
    int unk04;
    int unk08;

    void ProcessArgument(void* value);
    void Object_DoNothing();
};

struct FUN_00e02d40_cls
{
    int unk00;
    int unk04;
    int unk08;
    E02Sub m_sub;
    void** m_pData;
    int m_iArrayLength;
    unsigned int m_uCapBits;

    void ClearAndFreeData();
    void ProcessArgument(void* value);
    void Object_DoNothing();
};

// @fnv 0x00e02d40
void FUN_00e02d40_cls::ClearAndFreeData()
{
    int i = 0;
    if (m_iArrayLength > 0)
    {
        do
        {
            void* pElement = m_pData[i];
            hkMemoryRouter* pHolder = (hkMemoryRouter*)hkMemoryRouter_getInstance();
            hkMemoryRouter_easyFree(pHolder->m_heap, pElement);
            ++i;
        } while (i < m_iArrayLength);
    }
    hkMemoryRouter* pHolder = (hkMemoryRouter*)hkMemoryRouter_getInstance();
    E02Allocator* pAllocator = reinterpret_cast<E02Allocator*>(pHolder->m_heap);
    m_iArrayLength = 0;
    unsigned int uCapBits = m_uCapBits;
    if ((uCapBits & 0x80000000u) == 0)
    {
        pAllocator->FreeArray(m_pData, (uCapBits & 0x3fffffffu) * 4);
    }
    m_pData = 0;
    m_uCapBits = 0x80000000u;
    E02Sub* pSub = &m_sub;
    pSub->ProcessArgument(((hkMemoryRouter*)hkMemoryRouter_getInstance())->m_heap);
    pSub->Object_DoNothing();
    ProcessArgument(((hkMemoryRouter*)hkMemoryRouter_getInstance())->m_heap);
    Object_DoNothing();
}

struct E02DE0Allocator;

namespace fnvc_adapt {
extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance();
}

struct E02DE0Map
{
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    E02DE0Map() : m_kPrimitiveElement(0), m_iCapacityFlags(0), m_iPairCount(-1)
    {
        reserve(*reinterpret_cast<E02DE0Allocator*>((&fnvc_adapt::hkMemoryRouter_getInstance().heap())), 0);
    }

    void reserve(E02DE0Allocator& alloc, int numElements);
};

struct FUN_00e02de0
{
    FUN_00e02de0();

    E02DE0Map m_map0;
    E02DE0Map m_map1;
    hkArray<void*> m_ppData;
};

// Initializes the two maps and the array member by running their default constructors.
// @fnv 0x00e02de0
FUN_00e02de0::FUN_00e02de0()
{}

namespace fnv_00e02e40 {
struct E02E40Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void ReleaseBlock(void* p, int numBytes);
};

extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance();

struct FUN_00e02e40
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    FUN_00e02e40();
    virtual ~FUN_00e02e40();

    static void operator delete(void* p, unsigned int nbytes)
    {
        FUN_00e02e40* b = static_cast<FUN_00e02e40*>(p);
        reinterpret_cast<E02E40Allocator*>((&hkMemoryRouter_getInstance().heap()))->ReleaseBlock(p, b->m_usMemSizeAndFlags);
    }
};

// Default constructor with an empty body; the object layout includes m_usMemSizeAndFlags and m_sReferenceCount.
// @fnv 0x00e02e40
FUN_00e02e40::FUN_00e02e40()
{}
}  // namespace fnv_00e02e40

struct E02A80LayoutView : OffsetView
{
    __declspec(noinline) char* hkPlatformObjectWriter_getLayout();
};

// src: XBOX_PDB 0x00e02a70
__declspec(noinline) char* E02A80LayoutView::hkPlatformObjectWriter_getLayout()
{
    return unk08 + 12;
}

extern const char str_010d66fc[];

int __cdecl hkString_strCmp(const char* name, const char* s);

struct E02A80Helper
{
    E02A80Helper* Resolve(void* a, char* p);
    const char* Name();
};

struct E02A80Iface
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual int unk0C(void* a, void* b, void* c, void* d, void* e);
};

struct E02A80Arg
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual char* unk0C(void* out);
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual int unk20();
};

struct E02A80Local
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    E02A80Local();
    int Seek(int pos, int origin);
};

struct E02A80Box
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
    void Finish();
};

struct E02A80_cls
{
    int unk00;
    int unk04;
    E02A80Iface* unk08;
    E02A80Helper* unk0c;

    int hkPlatformObjectWriter_writeObject(E02A80Arg* arg1, int arg2, E02A80Helper* arg3, int arg4);
};

// Resolves a helper, optionally seeks and builds a box via the iface, then calls unk0C and returns whether the result string is empty.
// @fnv 0x00e02a80
// src: HAVOK_SRC 0x00e02a80
int E02A80_cls::hkPlatformObjectWriter_writeObject(E02A80Arg* apArg, int aiValue, E02A80Helper* apHelper, int arg4)
{
    E02A80Helper* pResolvedHelper;
    E02A80Helper* pHelper = unk0c;
    if (pHelper != 0)
    {
        pResolvedHelper = pHelper->Resolve(apHelper, reinterpret_cast<E02A80LayoutView*>(this)->hkPlatformObjectWriter_getLayout());
    }
    else
    {
        pResolvedHelper = apHelper;
    }
    E02A80Local a;
    void* b;
    E02A80Arg* e;
    if (unk0c != 0 && hkString_strCmp(pResolvedHelper->Name(), str_010d66fc) == 0)
    {
        b = unk0c->Resolve(reinterpret_cast<void*>(aiValue), reinterpret_cast<E02A80LayoutView*>(this)->hkPlatformObjectWriter_getLayout());
        e = apArg;
        a.Seek(e->unk20(), 0);
        E02A80Box box;
        box.unk08 = (int)0x80000000;
        box.unk14 = (int)0x80000000;
        box.unk20 = (int)0x80000000;
        box.unk2c = (int)0x80000000;
        box.unk00 = 0;
        box.unk04 = 0;
        box.unk0c = 0;
        box.unk10 = 0;
        box.unk18 = 0;
        box.unk1c = 0;
        box.unk24 = 0;
        box.unk28 = 0;
        box.unk30 = 0;
        unk08->unk0C(b, apHelper, apArg, pResolvedHelper, &box);
        e = reinterpret_cast<E02A80Arg*>(&a);
        box.Finish();
    }
    else
    {
        e = apArg;
    }
    unk08->unk0C(reinterpret_cast<void*>(aiValue), apHelper, e, pResolvedHelper, reinterpret_cast<void*>(arg4));
    char* p = e->unk0C(&apHelper);
    return *p == 0;
}
