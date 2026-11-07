#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkReferencedObject.h"

// src/havok/animation/animation/motionanalysis/hkafootstepanalysisinfo.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/motionanalysis/hkafootstepanalysisinfo.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.



struct BSAudio;
__declspec(nothrow) BSAudio* __cdecl hkMemoryRouter_getInstance();
inline hkMemoryRouter* audio()
{
    return (hkMemoryRouter*)hkMemoryRouter_getInstance();
}

__declspec(nothrow) void __cdecl ResizeAudioStream(void*, void*, int);

struct RefObj
{
    void* vtbl;
    short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    __declspec(nothrow) void FUN_00c90510();
    __declspec(nothrow) void FUN_00c905b0();
};

struct Obj : RefObj
{
    int pad[(0x98 - 8) / 4];
    __declspec(nothrow) Obj* FUN_00e40800(int a0, float a1, float a2, float a3, int a4, int a5, int a6, int a7, int a8);
};

struct ObjRef
{
    Obj* m_pRetainedObject;
    ObjRef(Obj* p)
    {
        if (p)
            p->FUN_00c90510();
        m_pRetainedObject = p;
    }
    ObjRef(const ObjRef& o)
    {
        if (o.m_pRetainedObject)
            o.m_pRetainedObject->FUN_00c90510();
        m_pRetainedObject = o.m_pRetainedObject;
    }
    ~ObjRef()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->FUN_00c905b0();
    }
    Obj* operator->() const
    {
        return m_pRetainedObject;
    }
    operator Obj*() const
    {
        return m_pRetainedObject;
    }
};

inline void* operator new(unsigned int, void* p)
{
    return p;
}

struct ObjArray
{
    ObjRef* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    void AddBack(const ObjRef& e)
    {
        hkMemoryAllocator& alloc = audio()->heap();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(&alloc, this, sizeof(ObjRef));
        new (&m_data[m_iElementCount]) ObjRef(e);
        m_iElementCount++;
    }
    ObjRef& back()
    {
        return m_data[m_iElementCount - 1];
    }
    ObjRef& operator[](int i)
    {
        return m_data[i];
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
};

struct Owner
{
    int unk00, unk04;
    ObjArray m_aiIndexedValues;
    Obj* CreateAndAddObject(int a0, float a1, float a2, float a3, int a4, int a5, int a6, int a7, int a8);
};

inline void* hkAlloc(int n)
{
    RefObj* p = (RefObj*)audio()->heap().blockAlloc(n);
    p->m_usMemSizeAndFlags = (short)n;
    return p;
}

// @fnv 0x00e40ec0
Obj* Owner::CreateAndAddObject(int a0, float a1, float a2, float a3, int a4, int a5, int a6, int a7, int a8)
{
    ObjRef p = ((Obj*)hkAlloc(sizeof(Obj)))->FUN_00e40800(a0, a1, a2, a3, a4, a5, a6, a7, a8);
    m_aiIndexedValues.AddBack(p);
    p->FUN_00c905b0();
    return m_aiIndexedValues[m_aiIndexedValues.GetLogicalSize() - 1];
}

struct E40FA0ReferencedObject
{
    virtual ~E40FA0ReferencedObject();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    E40FA0ReferencedObject() : m_sReferenceCount(1)
    {}
};

struct E40FA0Array
{
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    E40FA0Array() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};

struct FUN_00e40fa0 : E40FA0ReferencedObject
{
    E40FA0Array m_ppData;

    FUN_00e40fa0();
    virtual ~FUN_00e40fa0();
};

// Default constructor for the referenced object; the array member is default-initialized by its own constructor.
// @fnv 0x00e40fa0
FUN_00e40fa0::FUN_00e40fa0()
{}

namespace fnv_00e40fd0 {
extern int DAT_010e56d4;
extern int DAT_0102e388;
void* __cdecl hkMemoryRouter_getInstance();
struct Allocator;
typedef void(__thiscall* FreeFunction)(Allocator*, void*, unsigned int);
struct AllocatorVTable
{
    void* slot0;
    void* slot1;
    void* slot2;
    void* slot3;
    FreeFunction free;
};
struct Allocator
{
    AllocatorVTable* vtable;
};
struct Owner
{
    int* vtable;
    unsigned int unk04;
    hkReferencedObject** items;
    int count;
    int size;
    void ClearItems();
};
// @fnv 0x00e40fd0
void Owner::ClearItems()
{
    vtable = &DAT_010e56d4;
    Allocator* allocator = (Allocator*)((hkMemoryRouter*)hkMemoryRouter_getInstance())->m_heap;
    hkReferencedObject** pItems = items;
    int n = count;
    for (int i = 0; i < n; ++i)
    {
        hkReferencedObject* item = pItems[i];
        if (item)
            item->removeReference();
        pItems[i] = 0;
    }
    int oldSize = size;
    count = 0;
    if (oldSize & 0x80000000)
    {
    }
    else
    {
        allocator->vtable->free(allocator, items, (oldSize & 0x3fffffff) * 4);
    }
    items = 0;
    size = 0x80000000;
    vtable = &DAT_0102e388;
}
}  // namespace fnv_00e40fd0

struct CbHeap
{
    virtual ~CbHeap();
    virtual void* slot04(int a);
    virtual void* slot08(int a);
    virtual void* slot0c(int a);
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct CbArray
{
    void* m_data;
    int m_iElementCount;
    unsigned int m_iCapacityState;
};

struct CbBase
{
    virtual ~CbBase()
    {}
};

struct FUN_00e40cb0 : CbBase
{
    __declspec(nothrow) virtual ~FUN_00e40cb0();
    int unk04;
    CbArray m_kPointA[11];
};

template <int ELEM> inline void CbRelease(CbArray& a)
{
    CbHeap& heap = (CbHeap&)audio()->heap();
    a.m_iElementCount = 0;
    if (!(a.m_iCapacityState & 0x80000000))
        heap.ReleaseBlock(a.m_data, (a.m_iCapacityState & 0x3fffffff) * ELEM);
    a.m_data = 0;
    a.m_iCapacityState = 0x80000000;
}

// Releases the eleven CbArray members of the object through the audio heap, using element sizes 4 for the last six and 1 for the first five.
// @fnv 0x00e40cb0
__declspec(nothrow) FUN_00e40cb0::~FUN_00e40cb0()
{
    CbRelease<4>(m_kPointA[10]);
    CbRelease<4>(m_kPointA[9]);
    CbRelease<4>(m_kPointA[8]);
    CbRelease<4>(m_kPointA[7]);
    CbRelease<4>(m_kPointA[6]);
    CbRelease<4>(m_kPointA[5]);
    CbRelease<1>(m_kPointA[4]);
    CbRelease<1>(m_kPointA[3]);
    CbRelease<1>(m_kPointA[2]);
    CbRelease<1>(m_kPointA[1]);
    CbRelease<1>(m_kPointA[0]);
}

namespace fnv_00e40800 {
// Havok-style object: hkReferencedObject base, five string arrays, six float arrays, three floats.

struct S_00e40800_Allocator
{
    virtual void vf0() throw();
    virtual void* AllocateMemoryBlock(int n) throw();
    virtual void ReleaseBlock(void* p, int n) throw();
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut) throw();

    template <typename T> __forceinline T* _bufAlloc(int& reqNumInOut) throw()
    {
        const int SIZE_ELEM = sizeof(T);
        int n = reqNumInOut * SIZE_ELEM;
        void* p = AllocateBufferWithSize(n);
        reqNumInOut = n / SIZE_ELEM;
        return static_cast<T*>(p);
    }
};


inline S_00e40800_Allocator& heap(hkMemoryRouter* holder) throw()
{
    return *(S_00e40800_Allocator*)holder->m_heap;
}

hkMemoryRouter* hkMemoryRouter_getInstance() throw();
int hkString_strLen(const char* s) throw();
char* hkString_strCpy(char* dst, const char* src) throw();
void hkArrayUtil__reserve(S_00e40800_Allocator& alloc, void* array, int numElem, int sizeElem) throw();

template <typename T> struct S_00e40800_ArrayLocalForm
{ // local form of hkArray: 0x00e40800 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline S_00e40800_ArrayLocalForm() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}

    __forceinline S_00e40800_ArrayLocalForm(int size, const T& fill) throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {
        S_00e40800_Allocator& a = heap(hkMemoryRouter_getInstance());
        T* p = size ? a._bufAlloc<T>(size) : 0;
        int cap = size ? size : 0x80000000;
        m_data = p;
        m_iElementCount = size;
        m_iCapacityState = cap;
        for (int i = 0; i < size; i++)
        {
            p[i] = fill;
        }
    }

    __forceinline int getCapacity() const throw()
    {
        return m_iCapacityState & 0x3fffffff;
    }

    __forceinline void GrowArrayCapacity(S_00e40800_Allocator& alloc, int n) throw()
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayUtil__reserve(alloc, this, newSize, sizeof(T));
        }
    }

    __forceinline void _setSize(S_00e40800_Allocator& alloc, int n) throw()
    {
        GrowArrayCapacity(alloc, n);
        int& size = m_iElementCount;
        size = n;
    }

    __forceinline void SetSizeAndGrow(int n) throw()
    {
        _setSize(heap(hkMemoryRouter_getInstance()), n);
    }
};

struct S_00e40800_String
{
    S_00e40800_ArrayLocalForm<char> m_kStringBuffer;

    __forceinline void set(const char* s) throw()
    {
        m_kStringBuffer.SetSizeAndGrow(hkString_strLen(s) + 1);
        hkString_strCpy(m_kStringBuffer.m_data, s);
    }
};

struct S_00e40800_RefObject
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    S_00e40800_RefObject() throw() : m_sReferenceCount(1)
    {}
    virtual ~S_00e40800_RefObject() throw();
};

struct FUN_00e40800 : S_00e40800_RefObject
{
    S_00e40800_String m_name8;
    S_00e40800_String m_name14;
    S_00e40800_String m_name20;
    S_00e40800_String m_name2c;
    S_00e40800_String m_name38;
    S_00e40800_ArrayLocalForm<float> m_arr44;
    S_00e40800_ArrayLocalForm<float> m_arr50;
    S_00e40800_ArrayLocalForm<float> m_arr5c;
    S_00e40800_ArrayLocalForm<float> m_arr68;
    S_00e40800_ArrayLocalForm<float> m_arr74;
    S_00e40800_ArrayLocalForm<float> m_arr80;
    float m_f8c;
    float m_f90;
    float m_f94;

    FUN_00e40800(int n, float a2, float a3, float a4, const char* s5, const char* s6, const char* s7, const char* s8,
                 const char* s9) throw();
    virtual ~FUN_00e40800() throw();
};

// Initializes string fields from s5-s9, stores a2-a4 into m_f94, m_f8c, m_f90, and sets up six float arrays with given size and fill values.
// @fnv 0x00e40800
FUN_00e40800::FUN_00e40800(int aiSize, float afValue1, float afValue2, float afValue3, const char* apName1,
                           const char* apName2, const char* apName3, const char* apName4, const char* apName5) throw()
    : m_arr44(aiSize, 3.40282e38f), m_arr50(aiSize, -3.40282e38f), m_arr5c(aiSize, 3.40282e38f),
      m_arr68(aiSize, -3.40282e38f), m_arr74(aiSize, 0.0f), m_arr80(aiSize, 1.0f)
{
    m_f8c = afValue2;
    m_f90 = afValue3;
    m_f94 = afValue1;
    m_name8.set(apName1);
    m_name14.set(apName2);
    m_name20.set(apName3);
    m_name2c.set(apName4);
    m_name38.set(apName5);
}
}  // namespace fnv_00e40800

namespace fnv_00e40ca0 {
extern "C" char DAT_010ebd64;
struct Obj
{
    const void* vptr;
    Obj* InitializeFields_00e40ca0(int unused);
};

// @fnv 0x00e40ca0
// src: GUESS 0x00e40ca0 (confidence: low)
Obj* Obj::InitializeFields_00e40ca0(int unused)
{
    vptr = &DAT_010ebd64;
    return this;
}
}  // namespace fnv_00e40ca0

namespace fnv_00e41050 {
struct CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
struct CpuObject
{
    unsigned int unk00;
    unsigned short size;
    void FUN_00e40cb0();
    CpuObject* FUN_00e41050(unsigned int flags);
};
// Calls FUN_00e40cb0, then if flags & 1 invokes the global CpuAllocator on this object with its size, and returns this.
// @fnv 0x00e41050
CpuObject* CpuObject::FUN_00e41050(unsigned int flags)
{
    FUN_00e40cb0();
    if (flags & 1)
    {
        hkMemoryRouter* holder = hkMemoryRouter_getInstance();
        ((CpuAllocator*)holder->m_heap)->Invoke(this, size);
    }
    return this;
}
}  // namespace fnv_00e41050

namespace fnv_00e41e20 {
// The shared allocator declares FreeArray nonvirtual; preserve this call site's vtable dispatch.
inline void FreeAudioArray(hkMemoryAllocator* allocator, void* memory, unsigned int size) throw()
{
    typedef void(__thiscall* FreeArrayFunction)(hkMemoryAllocator*, void*, unsigned int);
    (*(FreeArrayFunction**)allocator)[4](allocator, memory, size);
}


hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();
extern int DAT_010e58c8;
extern int DAT_0102e388;

struct FUN_00e41e20_cls
{
    int m_vptr00;
    unsigned int unk04;
    void* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapBits;

    void ReleaseOwnedArray();
};

// If the capacity flag is clear, calls FreeArray on m_pData; then clears the data and size fields and assigns the final vtable value.
// @fnv 0x00e41e20
// src: GUESS 0x00e41e20 (confidence: medium)
void FUN_00e41e20_cls::ReleaseOwnedArray()
{
    m_vptr00 = (int)&DAT_010e58c8;
    hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
    unsigned int uCapBits = m_uCapBits;
    m_iArrayLength = 0;
    if ((uCapBits & 0x80000000u) == 0)
    {
        FreeAudioArray(pAllocator, m_pData, (uCapBits & 0x3fffffffu) * 4);
    }
    m_pData = 0;
    m_uCapBits = 0x80000000u;
    m_vptr00 = (int)&DAT_0102e388;
}
}  // namespace fnv_00e41e20
