// staging/blk_00dc0000_o2.cpp: SpawnedObject, ArrayHost, Lock_dd9, hkOwnerDCB1 and more (96 functions)

#include <windows.h>
#include "../../include/hkMemoryRouter.h"
#include "../../include/hkArray.h"
#include "../../include/hkBool.h"
#include "../../include/hkLargeBlockAllocator.h"
// src/staging/blk_00dc0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

struct FUN_00dd4b10_struct
{
    void __thiscall AssignFromSource(const void* p);
};

// Copies six consecutive unsigned ints from p into this at offsets 8 through 28.
// @fnv 0x00dd4b10
void __thiscall FUN_00dd4b10_struct::AssignFromSource(const void* pSource)
{
    const unsigned int* src = (const unsigned int*)pSource;
    *(unsigned int*)((char*)this + 8) = src[0];
    *(unsigned int*)((char*)this + 12) = src[1];
    *(unsigned int*)((char*)this + 16) = src[2];
    *(unsigned int*)((char*)this + 20) = src[3];
    *(unsigned int*)((char*)this + 24) = src[4];
    *(unsigned int*)((char*)this + 28) = src[5];
}

struct FUN_00dd4b40_Class
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1c;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;
    unsigned int m_2c;
    unsigned int m_30;
    unsigned int m_34;
    void __thiscall SetValues(const unsigned int* p);
};

// Copies six unsigned ints from the array p into fields m_20 through m_34.
// @fnv 0x00dd4b40
void __thiscall FUN_00dd4b40_Class::SetValues(const unsigned int* auiValues)
{
    m_20 = auiValues[0];
    m_24 = auiValues[1];
    m_28 = auiValues[2];
    m_2c = auiValues[3];
    m_30 = auiValues[4];
    m_34 = auiValues[5];
}

struct FUN_00dd5170_class
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
    void __thiscall CopySixInts(const int* p);
};

// Copies six consecutive ints from the pointed-to array into fields c through h.
// @fnv 0x00dd5170
void __thiscall FUN_00dd5170_class::CopySixInts(const int* pSource)
{
    c = pSource[0];
    d = pSource[1];
    e = pSource[2];
    f = pSource[3];
    g = pSource[4];
    h = pSource[5];
}

struct FUN_00dd8c20_class
{
    int m_field;
    int SumListValues();
};

// @fnv 0x00dd8c20
int FUN_00dd8c20_class::SumListValues()
{
    int total = 0;
    void* current = *(void**)((char*)this + 0xa8);
    void* end = (char*)this + 0xa4;
    while (current != end)
    {
        total += *(int*)((char*)current + 0xc);
        current = *(void**)((char*)current + 4);
    }
    return total;
}

template <class K, class V, class O> class HashEntryTable
{
  public:
    void clear();
};
template <class K> struct KeyMarker
{
};

struct FUN_00ddf050_cls
{
    void ClearContainer();
};

// @fnv 0x00ddf050
void FUN_00ddf050_cls::ClearContainer()
{
    ((HashEntryTable<unsigned long, unsigned long, KeyMarker<unsigned long> >*)((char*)this + 0x20))->clear();
    *(unsigned long*)((char*)this + 0x18) = 0;
}

extern "C" void __cdecl hkpConstraintConstructionKit_computeConstraintInfo(int* p1, int* p2);
struct FUN_00dd0420_Class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    FUN_00dd0420_Class* __thiscall hkpGenericConstraintDataScheme_hkpGenericConstraintDataScheme(int arg);
};
// If arg is nonzero, zeroes m_00/m_08/m_0c, sets m_04 to 0x10, calls FUN_00d51760 on m_1c and this, then sets m_00 to m_04; returns this.
// @fnv 0x00dd0420
// src: HAVOK_LIB 0x00dd0420
FUN_00dd0420_Class* __thiscall FUN_00dd0420_Class::hkpGenericConstraintDataScheme_hkpGenericConstraintDataScheme(int aiFlag)
{
    if (aiFlag)
    {
        m_00 = 0;
        m_08 = 0;
        m_0c = 0;
        m_04 = 0x10;
        hkpConstraintConstructionKit_computeConstraintInfo(&m_1c, (int*)this);
        m_00 = m_04;
    }
    return this;
}

struct FUN_00dd4b70_class
{
    void __thiscall hkpMoppCompiler_enableInterleavedBuilding(unsigned char value);
};
// @fnv 0x00dd4b70
// src: HAVOK_LIB 0x00dd4b70
void __thiscall FUN_00dd4b70_class::hkpMoppCompiler_enableInterleavedBuilding(unsigned char value)
{
    *(unsigned char*)(this + 0x1c) = value;
    *(unsigned char*)(this + 0x64) = value;
}

extern int DAT_0102e388;

struct FUN_00dd51d0_class
{
    int m_00;
    int m_04;
    int m_08;
    void InitializeFields_00dd51d0();
};

// @fnv 0x00dd51d0
// src: GUESS 0x00dd51d0 (confidence: low)
void FUN_00dd51d0_class::InitializeFields_00dd51d0()
{
    m_08 = 0;
    m_00 = (int)&DAT_0102e388;
}

struct FUN_00ddfb70_cls
{
    int m_00;
    int m_04;
    FUN_00ddfb70_cls* hkpShapeDisplayBuilder_hkpShapeDisplayBuilderEnvironment_hkpShapeDisplayBuilderEnvironment();
};

// @fnv 0x00ddfb70
// src: HAVOK_LIB 0x00ddfb70
FUN_00ddfb70_cls* FUN_00ddfb70_cls::hkpShapeDisplayBuilder_hkpShapeDisplayBuilderEnvironment_hkpShapeDisplayBuilderEnvironment()
{
    m_00 = 8;
    m_04 = 8;
    return this;
}

struct FUN_00dccb70_Class
{
    void SetTableValue(int arg1, unsigned short value);
};

// @fnv 0x00dccb70
void FUN_00dccb70_Class::SetTableValue(int uiKey, unsigned short value)
{
    unsigned char* p = (unsigned char*)this;
    unsigned int shift = *(unsigned int*)(p + 0x30);
    unsigned int mask = 0xFFFFFFFFu >> shift;
    unsigned int uiIndex = (unsigned int)uiKey >> (32 - shift);
    unsigned int base = *(unsigned int*)(*(unsigned int*)(p + 0x34) + uiIndex * 56 + 0x34);
    unsigned int slot = (mask & (unsigned int)uiKey) + base;
    unsigned short* table = (unsigned short*)*(unsigned int*)(p + 0x40);
    table[slot] = value;
}

struct CountArray
{
    int m_00;
    int m_04;
    int m_08;
    void __thiscall EnsureCapacity(void* p, int n);
};

void* __cdecl _D1A0E0GetMemoryRouter();

struct FUN_00dc9e70_Class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    FUN_00dc9e70_Class* InitializeFields_00dc9e70();
};

// Initializes the object's fields to zero/defaults, sets up the embedded CountArray at m_0c, and returns this.
// @fnv 0x00dc9e70
// src: GUESS 0x00dc9e70 (confidence: low)
FUN_00dc9e70_Class* FUN_00dc9e70_Class::InitializeFields_00dc9e70()
{
    m_00 = 0;
    m_04 = 0;
    m_08 = 0x80000000;
    CountArray* p = (CountArray*)&m_0c;
    p->m_00 = 0;
    p->m_04 = 0;
    p->m_08 = 0xffffffff;
    void* router = _D1A0E0GetMemoryRouter();
    p->EnsureCapacity(*(void**)((char*)router + 0x10), 0);
    m_18 = 0xffffffff;
    return this;
}

struct FUN_00dcc5a0_vt
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(int, int);
};
struct FUN_00dcc5a0_class
{
    int m_00;
    int m_04;
    FUN_00dcc5a0_vt* m_08;
    FUN_00dcc5a0_class* ProcessAndReturnValue_00dcc5a0(int arg);
};
// @fnv 0x00dcc5a0
// src: GUESS 0x00dcc5a0 (confidence: low)
FUN_00dcc5a0_class* FUN_00dcc5a0_class::ProcessAndReturnValue_00dcc5a0(int arg)
{
    m_08->v4(arg, 1);
    return this;
}

struct FUN_00cb0a70
{
    void __thiscall m(int);
};
// @fnv 0x00dccae0
// src: GUESS 0x00dccae0 (confidence: low)
void __cdecl Object_ProcessState_00dccae0(void* a, void* iValue)
{
    if (a)
        ((FUN_00cb0a70*)((char*)a + 4))->m((int)iValue);
}

struct S_00d49310_Lock
{
    ~S_00d49310_Lock();
};

// @fnv 0x00dccb10
// src: GUESS 0x00dccb10 (confidence: low)
void __cdecl Runtime_UpdateState_00dccb10(char* p)
{
    p += 4;
    S_00d49310_Lock* lock = reinterpret_cast<S_00d49310_Lock*>(p);
    lock->S_00d49310_Lock::~S_00d49310_Lock();
}

extern int DAT_010d77b4[];
extern void __cdecl _Deallocate(void* p);

struct FUN_00dcd4b0_Class
{
    void* m_ppVirtualMethodTable;
    FUN_00dcd4b0_Class* __thiscall InitializeAndMaybeFree(int flags);
};

// @fnv 0x00dcd4b0
FUN_00dcd4b0_Class* __thiscall FUN_00dcd4b0_Class::InitializeAndMaybeFree(int flags)
{
    m_ppVirtualMethodTable = DAT_010d77b4;
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct DDA7C0OStream
{
    void __thiscall writeInt32(unsigned int);
};

struct FUN_00dda6b0_Class
{
    void __thiscall WriteUInt32Triple(const unsigned int* p);
};

// Writes the three consecutive unsigned ints pointed to by p to the stream via writeInt32.
// @fnv 0x00dda6b0
void __thiscall FUN_00dda6b0_Class::WriteUInt32Triple(const unsigned int* auiValues)
{
    ((DDA7C0OStream*)this)->writeInt32(auiValues[0]);
    ((DDA7C0OStream*)this)->writeInt32(auiValues[1]);
    ((DDA7C0OStream*)this)->writeInt32(auiValues[2]);
}

struct D2B3D0Map
{
    void clear();
};
struct FUN_00ddf030_Class
{
    void __thiscall Clear_Thunk(int arg);
};
// @fnv 0x00ddf030
// src: GUESS 0x00ddf030 (confidence: medium)
void __thiscall FUN_00ddf030_Class::Clear_Thunk(int arg)
{
    ((D2B3D0Map*)((char*)this + 0x20))->clear();
}

namespace fnv_00ddf040 {
struct D2B3D0Map
{
    void clear();
};

// @fnv 0x00ddf040
// src: GUESS 0x00ddf040 (confidence: medium)
void __fastcall Object_Clear_Thunk(char* ecx, int edx)
{
    ((D2B3D0Map*)(ecx + 0x20))->clear();
}
}  // namespace fnv_00ddf040

extern int DAT_010d8094;

struct FUN_00ddfb80_s
{
    void* m_vt;
    unsigned short m_02;
    unsigned short m_04;
    unsigned short m_06;
    unsigned short m_08;
    void* m_0c;
    void* m_10;
};

// Initialises the object: sets field at offset 6 to 1, assigns the vtable, copies two pointers from src, and zeroes the field at offset 16.
// @fnv 0x00ddfb80
// src: HAVOK_LIB 0x00ddfb80
FUN_00ddfb80_s* __fastcall hkpShapeDisplayBuilder_hkpShapeDisplayBuilder(FUN_00ddfb80_s* self, int, const void* src)
{
    *(unsigned short*)((char*)self + 6) = 1;
    self->m_vt = &DAT_010d8094;
    *(void**)((char*)self + 8) = *(void**)((char*)src + 0);
    *(void**)((char*)self + 12) = *(void**)((char*)src + 4);
    *(unsigned int*)((char*)self + 16) = 0;
    return self;
}

// FUN_00dc1660: __stdcall identity on its single stack parameter.
// @fnv 0x00dc1660
// src: GUESS 0x00dc1660 (confidence: high)
int __stdcall Object_ReturnArgument_00dc1660(int a1)
{
    return a1;
}

extern int DAT_011b7b88;

struct FUN_00dc1670_cls
{
    int m_00;
    FUN_00dc1670_cls* hkStructureLayout_hkStructureLayout();
};

// @fnv 0x00dc1670
// src: COMMUNITY 0x00dc1670
FUN_00dc1670_cls* FUN_00dc1670_cls::hkStructureLayout_hkStructureLayout()
{
    this->m_00 = DAT_011b7b88;
    return this;
}

void __stdcall hkIArchive_readArrayGeneric(float* out, int a, int b);

// @fnv 0x00dc5bb0
// src: HAVOK_LIB 0x00dc5bb0
float hkIArchive_readFloat32()
{
    float value;
    hkIArchive_readArrayGeneric(&value, 4, 1);
    return value;
}

struct ArrayBlock
{
    unsigned int* values;
    int size;
    unsigned int reservedAndFlags;
};
extern "C" hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
extern "C" void __cdecl hkArrayUtil__reserve(void*, ArrayBlock*, int, int);
struct ArrayHost
{
    int unk00, unk04, unk08;
    ArrayBlock array;
    void ResizeArray(int desired);
};
// Grows the array's capacity to at least desired if needed, zero-fills the new elements, and sets the size to desired.
// @fnv 0x00dc9bd0
void ArrayHost::ResizeArray(int desired)
{
    ArrayBlock* values = &array;
    void* pool = (&hkMemoryRouter_getInstance()->heap());
    int capacity = values->reservedAndFlags & 0x3fffffff;
    if (capacity < desired)
    {
        int nextCapacity = capacity * 2;
        if (desired >= nextCapacity)
            nextCapacity = desired;
        hkArrayUtil__reserve(pool, values, nextCapacity, 4);
    }
    int extra = desired - values->size;
    unsigned int* next = values->values + values->size;
    while (extra > 0)
    {
        *next++ = 0;
        --extra;
    }
    values->size = desired;
}

namespace fnv_00dc9e20 {
struct AllocatorIface
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void* Alloc(int* pSize);
    virtual void Free(void* pBuffer, unsigned int size);
};

hkMemoryRouter* hkMemoryRouter_getInstance();
void hkArrayUtil__reserve(AllocatorIface* alloc, void* arr, unsigned int newCap, int elemSize);

struct DwordArray
{
    unsigned int* m_pBuffer;
    unsigned int m_uiLogicalSize;
    unsigned int m_iReserved;
};

class FUN_00dc9e20_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    DwordArray m_aiIndexedValues;

    void ReserveDwordArray(int count);
};

// Grows the DwordArray member to hold at least count elements, doubling capacity or using count if larger.
// @fnv 0x00dc9e20
void FUN_00dc9e20_cls::ReserveDwordArray(int count)
{
    DwordArray* arr = &m_aiIndexedValues;
    hkMemoryRouter* holder = hkMemoryRouter_getInstance();
    AllocatorIface* alloc = reinterpret_cast<AllocatorIface*>(holder->m_heap);
    int cap = arr->m_iReserved & 0x3fffffff;
    if (cap < count)
    {
        int newCap = cap * 2;
        if (count >= newCap)
        {
            newCap = count;
        }
        hkArrayUtil__reserve(alloc, arr, (unsigned int)newCap, 4);
    }
}
}  // namespace fnv_00dc9e20

struct FUN_00dcc180_Interface
{
    virtual void FUN_00dcc180_00();
    virtual void FUN_00dcc180_01();
    virtual void FUN_00dcc180_02();
    virtual void FUN_00dcc180_03(unsigned char* value);
};

struct FUN_00dcc180_Class
{
    int unk00;
    int unk04;
    FUN_00dcc180_Interface* unk08;

    unsigned char* __thiscall hkIstream_isOk(unsigned char* value);
};

// If unk08 is set, forwards value to its virtual method; otherwise writes 0 to *value and returns value.
// @fnv 0x00dcc180
// src: HAVOK_LIB 0x00dcc180
unsigned char* __thiscall FUN_00dcc180_Class::hkIstream_isOk(unsigned char* pucValue)
{
    if (unk08)
        unk08->FUN_00dcc180_03(pucValue);
    else
        *pucValue = 0;

    return pucValue;
}

struct Target
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void Forward(int a);
};

struct FUN_00dcc660_cls
{
    int unk00;
    int unk04;
    Target* m_pFlagTarget;
    void InvokeVirtualMethod_00dcc660(int a);
};

// @fnv 0x00dcc660
// src: GUESS 0x00dcc660 (confidence: low)
void FUN_00dcc660_cls::InvokeVirtualMethod_00dcc660(int a)
{
    m_pFlagTarget->Forward(a);
}

struct FUN_00dcc670_Manager
{
    virtual void FUN_00dcc670_v0();
    virtual void FUN_00dcc670_v1();
    virtual void FUN_00dcc670_v2();
    virtual int FUN_00dcc670_v3(int* value);
};

struct FUN_00dcc670_Class
{
    void* unk00;
    unsigned short unk04;
    unsigned short unk06;
    int unk08;

    int* __thiscall InitFromValue(int* value);
};

extern int DAT_010d7540;
extern FUN_00dcc670_Manager* DAT_01268364;

// Sets unk06 to 1, unk00 to &DAT_010d7540, and unk08 to the result of DAT_01268364->FUN_00dcc670_v3(value), then returns this.
// @fnv 0x00dcc670
int* __thiscall FUN_00dcc670_Class::InitFromValue(int* value)
{
    int* local_value = value;

    unk06 = 1;
    unk00 = &DAT_010d7540;
    unk08 = DAT_01268364->FUN_00dcc670_v3(local_value);
    return (int*)this;
}

namespace fnv_00dcc6a0 {
struct AllocIface
{
    virtual void unk00();
    virtual void* Alloc(unsigned int size);
};

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

extern char DAT_010d7540[];

struct SpawnedBlob
{
    int unk00;
    unsigned short m_w04;
    unsigned short unk06;
    void* Init(int a1, int a2, int a3);
};

struct FUN_00dcc6a0_cls
{
    void* m_vptr;
    unsigned short m_w04;
    unsigned short m_w06;
    void* m_p08;

    FUN_00dcc6a0_cls* hkIstream_hkIstream_00dcc6a0(int a1, int a2);
};

// Sets m_w06 to 1 and the vtable, allocates a 0x1c-byte blob via the allocator, stores its Init result in m_p08, and returns this.
// @fnv 0x00dcc6a0
// src: HAVOK_LIB 0x00dcc6a0
FUN_00dcc6a0_cls* FUN_00dcc6a0_cls::hkIstream_hkIstream_00dcc6a0(int a1, int a2)
{
    m_w06 = 1;
    m_vptr = DAT_010d7540;
    hkMemoryRouter* holder = hkMemoryRouter_getInstance();
    SpawnedBlob* blob = (SpawnedBlob*)reinterpret_cast<AllocIface*>(holder->m_heap)->Alloc(0x1c);
    blob->m_w04 = 0x1c;
    m_p08 = blob->Init(a1, a2, 2);
    return this;
}
}  // namespace fnv_00dcc6a0

namespace fnv_00dcc6f0 {
struct AllocIface
{
    virtual void unk00();
    virtual void* Alloc(unsigned int size);
};

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

extern char DAT_010d7540[];

struct SpawnedBlob
{
    int unk00;
    unsigned short m_w04;
    unsigned short unk06;
    void* Init(int a1, int a2);
};

struct FUN_00dcc6f0_cls
{
    void* m_vptr;
    unsigned short m_w04;
    unsigned short m_w06;
    void* m_p08;

    FUN_00dcc6f0_cls* hkIstream_hkIstream_00dcc6f0(int a1);
};

// Sets m_w06 to 1 and the vtable, allocates a 0x14-byte blob via the allocator, sets its m_w04 to 0x14, stores blob->Init(a1, 2) in m_p08 and returns this.
// @fnv 0x00dcc6f0
// src: HAVOK_LIB 0x00dcc6f0
FUN_00dcc6f0_cls* FUN_00dcc6f0_cls::hkIstream_hkIstream_00dcc6f0(int a1)
{
    m_w06 = 1;
    m_vptr = DAT_010d7540;
    hkMemoryRouter* holder = hkMemoryRouter_getInstance();
    SpawnedBlob* blob = (SpawnedBlob*)reinterpret_cast<AllocIface*>(holder->m_heap)->Alloc(0x14);
    blob->m_w04 = 0x14;
    m_p08 = blob->Init(a1, 2);
    return this;
}
}  // namespace fnv_00dcc6f0

namespace fnv_00dcc9c0 {
struct S_00dcc9c0_Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void ReturnMemory(void* p, int numBytes);
};

hkMemoryRouter* hkMemoryRouter_getInstance() throw();

inline S_00dcc9c0_Allocator& temp(hkMemoryRouter* holder)
{
    return *reinterpret_cast<S_00dcc9c0_Allocator*>(holder->m_temp);
}

struct S_00dcc9c0_StringBuf
{
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    unsigned int m_kStorage[32];

    S_00dcc9c0_StringBuf() throw();
    ~S_00dcc9c0_StringBuf() throw()
    {
        S_00dcc9c0_Allocator& a = temp(hkMemoryRouter_getInstance());
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            a.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(char));
    }
};

struct S_00dcc9c0_Target
{
    void __thiscall UpdateState_00cb0c10(const char* name) throw();
};

struct S_00dcc9c0_Class
{
    void __thiscall ReadToken(S_00dcc9c0_StringBuf* buf) throw();
    S_00dcc9c0_Class* __thiscall ProcessAndReturnValue_00dcc9c0(S_00dcc9c0_Target* target) throw();
};

// @fnv 0x00dcc9c0
// src: GUESS 0x00dcc9c0 (confidence: low)
S_00dcc9c0_Class* S_00dcc9c0_Class::ProcessAndReturnValue_00dcc9c0(S_00dcc9c0_Target* target) throw()
{
    S_00dcc9c0_StringBuf buf;
    this->ReadToken(&buf);
    target->UpdateState_00cb0c10(buf.m_data);
    return this;
}
}  // namespace fnv_00dcc9c0

extern int g_unk01269bb4;

// @fnv 0x00dccb00
// src: GUESS 0x00dccb00 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00dccb00()
{
    return &g_unk01269bb4;
}

extern int DAT_01269be4;

// @fnv 0x00dccb30
// src: GUESS 0x00dccb30 (confidence: low)
int* __cdecl Runtime_GetDAT01269be4Address()
{
    return &DAT_01269be4;
}

namespace fnv_00dcd480 {
struct FnvCpu_FUN_00dcd480_CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
struct FnvCpu_FUN_00dcd480_CpuObject
{
    unsigned int unk00;
    unsigned short size;
    void FUN_00d4bd60();
    FnvCpu_FUN_00dcd480_CpuObject* hkpMeshShape_Destroy(unsigned int flags);
};
// @fnv 0x00dcd480
// src: COMMUNITY 0x00dcd480
FnvCpu_FUN_00dcd480_CpuObject* FnvCpu_FUN_00dcd480_CpuObject::hkpMeshShape_Destroy(unsigned int flags)
{
    FUN_00d4bd60();
    if (flags & 1)
    {
        hkMemoryRouter* holder = hkMemoryRouter_getInstance();
        reinterpret_cast<FnvCpu_FUN_00dcd480_CpuAllocator*>(holder->m_heap)->Invoke(this, size);
    }
    return this;
}
}  // namespace fnv_00dcd480

struct FUN_00dced30_cls
{
    virtual void m_v00(int arg);
};

// @fnv 0x00dced30
// src: GUESS 0x00dced30 (confidence: low)
void __cdecl Object_ForwardCall_00dced30(FUN_00dced30_cls* pObject)
{
    pObject->m_v00(0);
}

extern int DAT_01269c44;

// @fnv 0x00dced40
// src: GUESS 0x00dced40 (confidence: low)
int __cdecl Object_ComputeValue_00dced40()
{
    return reinterpret_cast<int>(&DAT_01269c44);
}

struct FUN_00d4dfc0_class
{
    void __thiscall FUN_00d4dfc0(unsigned int value);
};

// @fnv 0x00dced50
// src: GUESS 0x00dced50 (confidence: low)
void __cdecl Runtime_ProcessState_00dced50(FUN_00d4dfc0_class* object, unsigned int value)
{
    if (object)
        object->FUN_00d4dfc0(value);
}

struct S_00dd4bb0_Class
{
    unsigned char unk00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    unsigned char unk04;
    unsigned int GetPackedValue();
};

// Combines bytes unk01 through unk04 into a single 32-bit value, shifting each successive byte left by 8 bits.
// @fnv 0x00dd4bb0
unsigned int S_00dd4bb0_Class::GetPackedValue()
{
    return (((unk01 << 8) + unk02 << 8) + unk03 << 8) + unk04;
}

extern float DAT_0101e2bc;
extern float DAT_010181bc;
extern float DAT_0101df44;

struct FUN_00dd50f0_cls
{
    float m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    unsigned char m_14;
    FUN_00dd50f0_cls* hkpMoppSplitter_hkpMoppSplitParams_hkpMoppSplitParams(int mode);
};

// Initialises the object's fields to defaults, then overrides m_00 and m_08 depending on mode (0 or 1), and returns this.
// @fnv 0x00dd50f0
// src: HAVOK_LIB 0x00dd50f0
FUN_00dd50f0_cls* FUN_00dd50f0_cls::hkpMoppSplitter_hkpMoppSplitParams_hkpMoppSplitParams(int mode)
{
    m_00 = DAT_0101e2bc;
    m_10 = 5;
    m_0c = 5;
    m_04 = 1000;
    m_08 = 10;
    m_14 = 1;
    switch (mode)
    {
    case 0:
        m_00 = DAT_0101df44;
        break;
    case 1:
        m_00 = DAT_010181bc;
        m_08 = 30;
        break;
    }
    return this;
}

// FUN_00dd5150: initialises six float members of the object: five of them to
// 1.0 and the last one to the global float constant DAT_01016248; returns the
// object pointer.
extern float DAT_01016248;

struct FUN_00dd5150_cls
{
    float m_f00;
    float m_f04;
    float m_f08;
    float m_f0c;
    float m_f10;
    float m_f14;
    void* hkpMoppCostFunction_hkpMoppSplitCostParams_hkpMoppSplitCostParams(int arg);
};

// @fnv 0x00dd5150
// src: HAVOK_LIB 0x00dd5150
void* FUN_00dd5150_cls::hkpMoppCostFunction_hkpMoppSplitCostParams_hkpMoppSplitCostParams(int aiUnused)
{
    this->m_f00 = 1.0f;
    this->m_f04 = 1.0f;
    this->m_f08 = 1.0f;
    this->m_f0c = 1.0f;
    this->m_f10 = 1.0f;
    this->m_f14 = DAT_01016248;
    return this;
}

extern void* DAT_010d7ba8;

struct FUN_00dd5150_component
{
    void hkpMoppCostFunction_hkpMoppSplitCostParams_hkpMoppSplitCostParams(int value);
};

struct FUN_00dd51a0
{
    void** vftable;
    short unk04;
    short enabled06;
    FUN_00dd5150_component component08;

    FUN_00dd51a0(const int* data);
    void CopySixInts(const int* data);
};

// @fnv 0x00dd51a0
FUN_00dd51a0::FUN_00dd51a0(const int* data)
{
    enabled06 = 1;
    vftable = &DAT_010d7ba8;
    component08.hkpMoppCostFunction_hkpMoppSplitCostParams_hkpMoppSplitCostParams(0);
    CopySixInts(data);
}

// @fnv 0x00dd6ea0
unsigned char* __cdecl LessThan(unsigned char* output, const unsigned int* left, const unsigned int* right)
{
    *output = *left < *right;
    return output;
}

// CompareLessThan: compares two unsigned values and writes the 0/1 result into a
// byte out-parameter; the out pointer is also returned (so it lives in eax).
// @fnv 0x00dd70f0
unsigned char* __cdecl CompareLessThan(unsigned char* pResult, unsigned int left, unsigned int right)
{
    *pResult = (unsigned char)(left < right);
    return pResult;
}

// Constructor for the object handled by FUN_00dd7110.
//
// The class holds a run of scalar members; every one of them is zeroed by the
// constructor except m_iUninitialised08, which is left for the caller to fill
// in later.  The ten members cleared through the initialiser list are stored
// first (in declaration order), the two cleared in the constructor body are
// stored afterwards.
struct FUN_00dd7110_cls
{
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0c;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1c;
    int m_i20;
    int m_i24;
    int m_i28;
    int m_i2c;
    int m_i30;
    FUN_00dd7110_cls();
};

// @fnv 0x00dd7110
FUN_00dd7110_cls::FUN_00dd7110_cls()
    : m_i00(0), m_i0c(0), m_i10(0), m_i14(0), m_i18(0), m_i20(0), m_i24(0), m_i28(0), m_i2c(0), m_i30(0)
{
    m_i04 = 0;
    m_i1c = 0;
}

struct FUN_00dd8bc0_Node
{
    int m_00;
    FUN_00dd8bc0_Node* m_next;
    int m_08;
    int m_0c;
    unsigned char* m_pRayStart;
    unsigned char* m_kRayEnd;
};

struct FUN_00dd8bc0_cls
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
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    FUN_00dd8bc0_Node m_kNode;
    void _makeTopValid();
    unsigned int GetUsedMemory();
};

// @fnv 0x00dd8bc0
unsigned int FUN_00dd8bc0_cls::GetUsedMemory()
{
    unsigned int used = 0;
    _makeTopValid();
    FUN_00dd8bc0_Node* node = m_kNode.m_next;
    if (node != &m_kNode)
    {
        do
        {
            unsigned char* cur = node->m_pRayStart;
            unsigned char* last = node->m_kRayEnd;
            last -= 0x10;
            if (cur != last)
            {
                do
                {
                    unsigned int size = *(unsigned int*)(cur + 4);
                    unsigned char flags = (unsigned char)(size >> 1);
                    if (flags & 1)
                    {
                        used += size & 0xfffffffc;
                    }
                    cur += size & 0xfffffffc;
                } while (cur != last);
            }
            node = node->m_next;
        } while (node != &m_kNode);
    }
    return used;
}

struct S_00dd8cf0_Ret
{
    bool v;
    S_00dd8cf0_Ret()
    {}
};
struct S_00dd8cf0
{
    bool __thiscall IsValidChunk(int v);
    S_00dd8cf0_Ret __thiscall AllMatch(const int* arr, int n);
};
// Returns true only if IsValidChunk accepts every element of arr; stops at the first element it rejects.
// @fnv 0x00dd8cf0
S_00dd8cf0_Ret __thiscall S_00dd8cf0::AllMatch(const int* pValues, int iCount)
{
    S_00dd8cf0_Ret r;
    for (int i = 0; i < iCount; i++)
    {
        if (!IsValidChunk(pValues[i]))
        {
            r.v = false;
            return r;
        }
    }
    r.v = true;
    return r;
}

extern int DAT_010d7c34;

// Object built by Construct: it installs its own vtable, clears a couple
// of members and then hands the object over to FUN_00dd7f10 for a full reset.
struct SpawnedObject
{
    int* m_vptr;
    int m_04;
    int m_08;
    int m_0c;
    int* m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    int* m_a4;
    int* m_a8;
    int m_ac;
    int m_b0;
    int m_b4;
    int m_b8;
    int m_bc;
    int m_c0;
    void _init_00dd7f10();
    SpawnedObject* Construct(int value);
};

// src: HAVOK_LIB 0x00dd7f10
void SpawnedObject::_init_00dd7f10()
{
    m_c0 = 0;
    m_bc = 0;
    m_08 = 0;
    m_0c = 0;
    m_18 = 0;
    m_1c = 0;
    m_20 = 0;
    m_24 = 0;
    m_28 = 0;
    m_2c = 0;
    m_30 = 0;
    m_34 = 0;
    m_38 = 0;
    m_3c = 0;
    m_40 = 0;
    m_44 = 0;
    m_48 = 0;
    m_4c = 0;
    m_50 = 0;
    m_54 = 0;
    m_58 = 0;
    m_5c = 0;
    m_60 = 0;
    m_64 = 0;
    m_68 = 0;
    m_6c = 0;
    m_70 = 0;
    m_74 = 0;
    m_78 = 0;
    m_7c = 0;
    m_80 = 0;
    m_84 = 0;
    m_88 = 0;
    m_8c = 0;
    m_90 = 0;
    m_94 = 0;
    m_9c = 0;
    m_14 = 0;
    m_a0 = 3;
    m_10 = (int*)&m_9c;
    m_a8 = (int*)&m_a4;
    m_a4 = (int*)&m_a4;
}

// Sets the vtable, stores value in m_98, then calls FUN_00dd7f10 to reset the remaining fields and returns this.
// @fnv 0x00dd8d40
SpawnedObject* SpawnedObject::Construct(int value)
{
    m_vptr = &DAT_010d7c34;
    m_04 = 0;
    m_98 = value;
    this->_init_00dd7f10();
    return this;
}

namespace fnv_00dd8db0 {
// Array-append helper: grows the buffer when the element count reaches the
// masked capacity, then stores the new value and bumps the count.
struct RecArray
{
    unsigned int* m_pData;
    unsigned int m_uiCount;
    unsigned int m_uiCapacity;
};

extern "C" hkMemoryRouter* hkMemoryRouter_getInstance();
extern "C" void ResizeAudioStream(void* pAllocator, RecArray* pArray, int iElementSize);

// Grows the array via the allocator when full, writes uiValue at the count index, and increments the count.
// @fnv 0x00dd8db0
void AppendToRecArray(unsigned int uiValue, unsigned int uiUnused, RecArray* pArray)
{
    hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();

    if (pArray->m_uiCount == (pArray->m_uiCapacity & 0x3fffffff))
    {
        ResizeAudioStream(pHolder->m_heap, pArray, 4);
    }

    unsigned int* pSlot = (unsigned int*)((unsigned int)pArray->m_pData + *(volatile int*)&pArray->m_uiCount * 4);
    *pSlot = uiValue;
    pArray->m_uiCount++;
}
}  // namespace fnv_00dd8db0

namespace fnv_00dd8fa0 {
typedef struct S_00dd8fa0_S S_00dd8fa0_S;

struct S_00dd8fa0_Vtable
{
    void* unk00;
    S_00dd8fa0_S*(__thiscall* method)(S_00dd8fa0_S*, int);
};

struct S_00dd8fa0_S
{
    S_00dd8fa0_Vtable* vtable;
    unsigned short m_04;
    unsigned short m_06;
};

extern "C" hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
extern "C" S_00dd8fa0_Vtable DAT_010d7c58;

// Gets a caller, calls its object's vtable method with 8, then sets m_04 to 8, m_06 to 1 and the vtable to DAT_010d7c58.
// @fnv 0x00dd8fa0
// src: GUESS 0x00dd8fa0 (confidence: low)
void __cdecl Object_UpdateFields_00dd8fa0()
{
    hkMemoryRouter* caller = hkMemoryRouter_getInstance();
    S_00dd8fa0_S* object = reinterpret_cast<S_00dd8fa0_S*>(caller->m_heap);

    object = object->vtable->method(object, 8);

    object->m_04 = 8;
    object->m_06 = 1;
    object->vtable = &DAT_010d7c58;
}
}  // namespace fnv_00dd8fa0

namespace fnv_00dd9160 {
// Stand-in for the polymorphic object stored in the game global at 0x01268364.
struct FUN_00dd9160_Global
{
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual unsigned int vfn3(unsigned int arg);  // vtable slot +0x0c
};

extern "C" FUN_00dd9160_Global* DAT_01268364;  // game global (0x01268364)
extern "C" int UNK_010d7c80;                   // game constant (0x010d7c80)

struct FUN_00dd9160_Class
{
    void* unk00;           // +0x00: vtable pointer stand-in
    unsigned short unk04;  // +0x04
    unsigned short unk06;  // +0x06: state, set to 1
    unsigned int unk08;    // +0x08: result of the virtual call
    unsigned char unk0c;   // +0x0c: flag copied from the second parameter
    FUN_00dd9160_Class* hkIArchive_hkIArchive(unsigned int arg, unsigned char flag);
};

// Sets unk06 to 1, unk00 to &UNK_010d7c80, stores flag in unk0c and the result of DAT_01268364->vfn3(arg) in unk08, then returns this.
// @fnv 0x00dd9160
// src: HAVOK_LIB 0x00dd9160
FUN_00dd9160_Class* FUN_00dd9160_Class::hkIArchive_hkIArchive(unsigned int arg, unsigned char flag)
{
    unk06 = 1;
    unk00 = &UNK_010d7c80;
    unk0c = flag;
    unk08 = DAT_01268364->vfn3(arg);
    return this;
}
}  // namespace fnv_00dd9160

namespace fnv_00dd91a0 {
struct DD91A0Allocator
{
    virtual void unk00();
    virtual void* AllocateMemoryBlock(int numBytes);
};

inline DD91A0Allocator& heap(hkMemoryRouter& holder)
{
    return *reinterpret_cast<DD91A0Allocator*>(holder.m_heap);
}

extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance();

class DD91A0ReferencedObject
{
  public:
    DD91A0ReferencedObject()
    {
        m_sReferenceCount = 1;
    }
    virtual void vfunc00();

    static void* operator new(unsigned int nbytes)
    {
        DD91A0ReferencedObject* b =
            static_cast<DD91A0ReferencedObject*>(heap(hkMemoryRouter_getInstance()).AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = static_cast<unsigned short>(nbytes);
        return b;
    }
    static void operator delete(void* p);

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class DD91A0Shape : public DD91A0ReferencedObject
{
  public:
    DD91A0Shape(int a, int b, int type) throw();

    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};

class FUN_00dd91a0 : public DD91A0ReferencedObject
{
  public:
    FUN_00dd91a0(int a, int b, unsigned char flag);

    DD91A0Shape* m_pCollisionShape;
    unsigned char m_flag;
};

// @fnv 0x00dd91a0
FUN_00dd91a0::FUN_00dd91a0(int a, int b, unsigned char flag)
{
    m_flag = flag;
    m_pCollisionShape = new DD91A0Shape(a, b, 2);
}
}  // namespace fnv_00dd91a0

namespace fnv_00ddc160 {
struct DDC160Allocator
{
    virtual void unk00();
    virtual void* AllocateMemoryBlock(int numBytes);
};

inline DDC160Allocator& heap(hkMemoryRouter& holder)
{
    return *reinterpret_cast<DDC160Allocator*>(holder.m_heap);
}

extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance();

class DDC160ReferencedObject
{
  public:
    virtual void unk00();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    static void* operator new(unsigned int nbytes)
    {
        DDC160ReferencedObject* b =
            static_cast<DDC160ReferencedObject*>(heap(hkMemoryRouter_getInstance()).AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = static_cast<unsigned short>(nbytes);
        return b;
    }
    static void operator delete(void* p);
};

class DDC160Interface
{
  public:
    virtual void unk00();
};

class DDC160Impl : public DDC160ReferencedObject, public DDC160Interface
{
  public:
    DDC160Impl(void* pvInfo) throw();

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
};

// @fnv 0x00ddc160
DDC160Interface* __cdecl CreateImpl(void* pvInfo)
{
    return new DDC160Impl(pvInfo);
}
}  // namespace fnv_00ddc160

struct FUN_00ddfbb0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_10;
    void ClearField10();
};

// @fnv 0x00ddfbb0
// src: GUESS 0x00ddfbb0 (confidence: low)
void FUN_00ddfbb0_cls::ClearField10()
{
    m_10 = 0;
}

void __cdecl FUN_00c90510();

struct FUN_00dcc130_Class
{
    int* m_vtbl;
    unsigned short unk04;
    unsigned short enabled06;
    int unk08;
    int* __thiscall hkIstream_hkIstream(int* value);
};

// Sets enabled06 to 1, installs the vtable, stores value in unk08, calls FUN_00c90510, and returns this.
// @fnv 0x00dcc130
// src: HAVOK_LIB 0x00dcc130
int* FUN_00dcc130_Class::hkIstream_hkIstream(int* value)
{
    enabled06 = 1;
    m_vtbl = &DAT_010d7540;
    unk08 = (int)value;
    FUN_00c90510();
    return (int*)this;
}

struct S_00dcc740_Cls
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    S_00dcc740_Cls* __thiscall ReadSignedShort(unsigned short* out);
};

struct IniTokenStream
{
    void* m_vt;
};

extern "C" void ReadIniLine(void);

// Stand-in for the unit's integer parser: its body is not this function's code, it only makes
// the compiler reproduce the original custom convention (stream on the stack, sign flag in eax).
// src: HAVOK_LIB 0x00dcc240
static __declspec(noinline) unsigned short readInteger64(IniTokenStream* stream, unsigned char* negative)
{
    *negative = 0;
    ReadIniLine();
    return (unsigned short)(int)(stream != 0);
}

// @fnv 0x00dcc740
S_00dcc740_Cls* S_00dcc740_Cls::ReadSignedShort(unsigned short* out)
{
    unsigned char flag;
    short r = (short)readInteger64((IniTokenStream*)m_08, &flag);
    *out = flag != 0 ? (unsigned short)(-r) : (unsigned short)r;
    return this;
}

extern void(__stdcall* DAT_00fdf05c)(int*);
extern void(__stdcall* DAT_00fdf100)(int*);

struct Lock_dd9
{
    int unk;
    int unkCur;
    int unkValue;
    int unk0c;
    int uNewnk;
    int uTmpnk;
    int* m_pkCriticalSection;
    int FindEntry(int iKey);
    int InvokeRecord(int iIndex, int iArg);
    int hkProcessFactory_createProcess(int iKey, int iArg);
};

// @fnv 0x00dd9330
// src: HAVOK_LIB 0x00dd9330
int Lock_dd9::hkProcessFactory_createProcess(int iKey, int iArg)
{
    int* pkCS = m_pkCriticalSection;
    DAT_00fdf05c(pkCS);
    int iIndex = FindEntry(iKey);
    int iResult;
    if (iIndex < 0)
        iResult = 0;
    else
        iResult = InvokeRecord(iIndex, iArg);
    DAT_00fdf100(pkCS);
    return iResult;
}

extern int DAT_010d7db8;

struct Bool1
{
    char v;
    Bool1(char x) : v(x)
    {}
};

struct Base_00d60b40
{
    void* vft;
    void __thiscall FUN_00d60b40(int a, Bool1 b);
};

struct FUN_00dda690 : Base_00d60b40
{
    FUN_00dda690(int a);
};

// @fnv 0x00dda690
FUN_00dda690::FUN_00dda690(int a)
{
    FUN_00d60b40(a, 0);
    vft = &DAT_010d7db8;
}

struct S_00dcc240_Reader
{
    int unk00;
    int unk04;
    unsigned short unk08;
};

struct S_00dcc790_Class
{
    unsigned int m_00;
    unsigned int m_04;
    S_00dcc240_Reader* m_08;

    S_00dcc790_Class* __thiscall ReadSignedValue(unsigned short* result);
};

extern "C" void __cdecl SkipWhitespace(void);

// src: HAVOK_LIB 0x00dcc240
static __declspec(noinline) unsigned short readInteger64(unsigned char* ok, S_00dcc240_Reader* reader)
{
    *ok = 0;
    SkipWhitespace();
    return reader->unk08;
}

// Reads a 16-bit value via FUN_00dcc240 and stores it negated into result when ok is set, otherwise as-is; returns this.
// @fnv 0x00dcc790
S_00dcc790_Class* __thiscall S_00dcc790_Class::ReadSignedValue(unsigned short* result)
{
    unsigned char ok;
    unsigned short value = readInteger64(&ok, m_08);

    *result = ok ? (unsigned short)-(int)value : value;
    return this;
}

typedef __int64 FNVInt64;

struct S_00dcc8a0_Reader
{
    virtual int read(int count);
    virtual int charAt(int pos);
};

struct S_00dcc8a0_Handle
{
    S_00dcc8a0_Reader* reader;
};

struct FUN_00dcc8a0_Class
{
    int unk00;
    int unk04;
    S_00dcc8a0_Handle unk08;

    FUN_00dcc8a0_Class* __thiscall ParseSignedInt(FNVInt64* out);
};

static __declspec(noinline) FNVInt64 S_00dcc8a0_ParseInt(S_00dcc8a0_Handle h, unsigned char* neg)
{
    *neg = 0;
    S_00dcc8a0_Reader* reader = h.reader;
    int count = reader->charAt(0);
    if (count < 3)
        return 0;
    return (FNVInt64)reader->read(count);
}

// Parses an integer from the handle's reader, negates it if the sign flag is set, stores it in out and returns this.
// @fnv 0x00dcc8a0
FUN_00dcc8a0_Class* FUN_00dcc8a0_Class::ParseSignedInt(FNVInt64* out)
{
    unsigned char neg;
    FNVInt64 value = S_00dcc8a0_ParseInt(unk08, &neg);
    if (neg)
        value = -value;
    *out = value;
    return this;
}

// GetEntryRef indexes 8-byte records; the Xbox PDB hkEntry is 12 bytes.
struct TableFilterEntry
{
    int m_uiFilterValue;
    int m_04;
};

struct hkTableDCB1
{
    int m_00;
    int m_04;
    int m_08;
    TableFilterEntry* m_entries;
};

class hkOwnerDCB1;

struct hkRefDCB1
{
    const hkOwnerDCB1* m_pOwnerObject;
    int m_uiFilterValue;

    hkRefDCB1(const hkOwnerDCB1* pkOwner, int iValue) : m_pOwnerObject(pkOwner), m_uiFilterValue(iValue)
    {}
};

class hkOwnerDCB1
{
  public:
    int m_00;
    int m_04;
    int m_08;
    hkTableDCB1* m_table;

    hkRefDCB1 GetEntryRef(int iIndex) const;
};

// @fnv 0x00dcb1a0
hkRefDCB1 hkOwnerDCB1::GetEntryRef(int iIndex) const
{
    return hkRefDCB1(this, m_table->m_entries[iIndex].m_uiFilterValue);
}

struct S_00dcc600_Inner
{
    int __thiscall ReadChar();
};

static __declspec(noinline) int S_00dcc600_Reset(S_00dcc600_Inner* stream)
{
    int count = 0;
    int c = stream->ReadChar();

    while (c != -1 && count < 4)
    {
        ++count;
        c = stream->ReadChar();
    }

    return count;
}

struct S_00dcc600_Class
{
    int m_00;
    int m_04;
    S_00dcc600_Inner* m_08;

    int __thiscall ReadUntilValue(unsigned char* buffer, int length, signed char value);
};

// Resets the stream, then reads bytes into buffer until the value or end is hit, returning the index or -1.
// @fnv 0x00dcc600
int S_00dcc600_Class::ReadUntilValue(unsigned char* buffer, int length, signed char value)
{
    S_00dcc600_Reset(this->m_08);

    int index = 0;

    if (length > 0)
    {
        do
        {
            int result = this->m_08->ReadChar();

            if (result == -1 || result == value)
            {
                buffer[index] = 0;
                return index;
            }

            buffer[index] = (unsigned char)result;
            ++index;
        } while (index < length);
    }

    return -1;
}

// @fnv 0x00dccb20
// src: COMMUNITY 0x00dccb20
void __cdecl nullsub_121()
{}

// @fnv 0x00dccb40
// src: COMMUNITY 0x00dccb40
void __cdecl nullsub_122()
{}

// @fnv 0x00dd4b00
// src: GUESS 0x00dd4b00 (confidence: high)
void __cdecl Object_DoNothing_00dd4b00()
{}

struct Bool388
{
    unsigned char value;
    Bool388()
    {}
    Bool388(unsigned char v) : value(v)
    {}
};
struct Block388
{
    unsigned int previousSize, sizeAndFlags;
    unsigned char Flags() const
    {
        return reinterpret_cast<const unsigned char*>(&sizeAndFlags)[0];
    }
};
struct Allocator388
{
    unsigned int unk00, unk04, unk08;
    Block388* lower;
    Bool388 ValidateBlock(Block388* block);
};
// @fnv 0x00dd8ca0
Bool388 Allocator388::ValidateBlock(Block388* block)
{
    Bool388 result;
    unsigned char one = 1;
    if ((reinterpret_cast<unsigned int>(block) & 15) != 0)
    {
        result.value = 0;
        return result;
    }
    unsigned int header = block->sizeAndFlags;
    if ((static_cast<unsigned char>(header >> 1) & one) != 0)
    {
        result.value = 0;
        return result;
    }
    if (reinterpret_cast<unsigned int>(block) < reinterpret_cast<unsigned int>(lower))
    {
        result.value = 0;
        return result;
    }
    Block388* next = reinterpret_cast<Block388*>(reinterpret_cast<char*>(block) + (header & ~3u));
    if ((next->Flags() & one) != 0)
    {
        result.value = 0;
        return result;
    }
    if ((static_cast<unsigned char>(next->sizeAndFlags >> 1) & one) == 0)
    {
        result.value = 0;
        return result;
    }
    if ((block->Flags() & one) == 0)
    {
        result.value = 0;
        return result;
    }
    result.value = one;
    return result;
}

// @fnv 0x00dd8fd0
// src: GUESS 0x00dd8fd0 (confidence: low)
static __declspec(noinline) void Runtime_UpdateState_00dd8fd0(unsigned char* a, unsigned char* b)
{
    unsigned char t = *a;
    *a = *b;
    *b = t;
}

extern "C" unsigned char* GetPtr();

void Caller(unsigned char* a)
{
    Runtime_UpdateState_00dd8fd0(a, GetPtr());
}

namespace hkRouterDDFB {
extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance() throw();
}

inline hkMemoryAllocator& heap(hkMemoryRouter& holder)
{
    return *reinterpret_cast<hkMemoryAllocator*>(holder.m_heap);
}

struct hkPairDDFB
{
    void* m_object;
    void* m_key;

    hkPairDDFB(void* object, void* key) : m_object(object), m_key(key)
    {}
    static void* operator new(unsigned int, void* p) throw()
    {
        return p;
    }
};

template <> inline void hkArray<hkPairDDFB>::pushBack(const hkPairDDFB& t)
{
    hkMemoryAllocator& alloc = heap(hkRouterDDFB::hkMemoryRouter_getInstance());
    if (m_iElementCount == getCapacity())
        hkArrayUtil::_reserveMore(alloc, this, sizeof(hkPairDDFB));
    new (m_data + m_iElementCount) hkPairDDFB(t);
    m_iElementCount++;
}

class hkOwnerDDFB
{
  public:
    int unk00;
    int unk04;
    hkArray<hkPairDDFB> m_pairs;

    void AddPairIfKeyAbsent(void* object, void* key);
};

// Scans m_pairs for an entry whose m_key equals key and returns if found; otherwise appends a new hkPairDDFB(object, key).
// @fnv 0x00ddfbc0
void hkOwnerDDFB::AddPairIfKeyAbsent(void* object, void* key)
{
    for (int i = 0; i < m_pairs.m_iElementCount; i++)
    {
        if (m_pairs.m_data[i].m_key == key)
            return;
    }
    m_pairs.pushBack(hkPairDDFB(object, key));
}

struct S_00dcb0b0_Target
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};

struct S_00dcb0b0_Class
{
    int unk00;
    int unk04;
    int unk08;
    S_00dcb0b0_Target* unk0C;

    void __thiscall CallTargetV6();
};

// @fnv 0x00dcb0b0
void S_00dcb0b0_Class::CallTargetV6()
{
    unk0C->v6();
}

struct stub_cls
{
    int unk00;
    int unk04;
};
static stub_cls* volatile g_stub_self;
static int volatile g_stub_v;
static int volatile g_stub_out;
extern "C" int stub_val(void);

// Placeholder body for the unsolved 0x00dcc3b0 (models its call for 0x00dcc5c0); annotated so the target pack drops it.
// @fnv 0x00dcc3b0
// src: HAVOK_LIB 0x00dcc3b0
static __declspec(noinline) float readFloat(int arg)
{
    g_stub_out = arg;
    stub_cls* s = g_stub_self;
    s->unk00 = s->unk04 + g_stub_v;
    return (float)s->unk00;
}

float stub_caller(void)
{
    return readFloat(stub_val());
}

class FUN_00dcc5c0_cls
{
  public:
    int unk00;
    int unk04;
    int m_08;

    FUN_00dcc5c0_cls* __thiscall GetFloatValue(float* out);
};

// @fnv 0x00dcc5c0
FUN_00dcc5c0_cls* __thiscall FUN_00dcc5c0_cls::GetFloatValue(float* out)
{
    *out = readFloat(m_08);
    return this;
}

// ReadSignedInt: thiscall member returning this; parses an int through FUN_00dcc240
// (per-TU private convention: stream on the stack, sign-flag address in EAX),
// negates it when the flag byte is set, and stores it through the int* argument.
struct S_00dcc7e0_Stream
{
    void* m_vt;
};

extern "C" void ReadIniLine(void);

// Stand-in for the unit's integer parser (int flavour): its body is not this
// function's code, it only makes the compiler reproduce the original custom
// convention (stream on the stack, sign flag in eax).
// src: HAVOK_LIB 0x00dcc240
static __declspec(noinline) int readInteger64(S_00dcc7e0_Stream* stream, unsigned char* negative)
{
    *negative = 0;
    ReadIniLine();
    return (int)(stream != 0);
}

struct FUN_00dcc7e0_Class
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;

    FUN_00dcc7e0_Class* __thiscall ReadSignedInt(int* out);
};

// Reads a signed integer from the stream at m_08 via FUN_00dcc240, applies the sign flag, stores the result in out, and returns this.
// @fnv 0x00dcc7e0
FUN_00dcc7e0_Class* FUN_00dcc7e0_Class::ReadSignedInt(int* out)
{
    unsigned char flag;
    int value = readInteger64((S_00dcc7e0_Stream*)m_08, &flag);
    *out = flag != 0 ? -value : value;
    return this;
}

typedef __int64 FNVInt64;

struct S_dcc860_Reader
{
    virtual int read(int count);
    virtual int charAt(int pos);
};

struct S_dcc860_Handle
{
    S_dcc860_Reader* reader;
};

struct FUN_00dcc860_Class
{
    int unk00;
    int unk04;
    S_dcc860_Handle unk08;

    FUN_00dcc860_Class* __thiscall ReadInt64(FNVInt64* out);
};

static __declspec(noinline) FNVInt64 S_dcc860_ParseInt(S_dcc860_Handle h, unsigned char* neg)
{
    *neg = 0;
    S_dcc860_Reader* reader = h.reader;
    int count = reader->charAt(0);
    if (count < 3)
        return 0;
    return (FNVInt64)reader->read(count);
}

// Parses a signed 64-bit integer from the reader handle, applies the sign, stores it in out, and returns this.
// @fnv 0x00dcc860
FUN_00dcc860_Class* FUN_00dcc860_Class::ReadInt64(FNVInt64* out)
{
    unsigned char neg;
    FNVInt64 value = S_dcc860_ParseInt(unk08, &neg);
    if (neg)
        value = -value;
    *out = value;
    return this;
}

struct S00dcd1b0_Pool
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void ReturnMemory(void* p, int size);
};

struct S00dcd1b0_Obj
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
    char* m_34;
    int m_38;
    int unk3C;
    ArrayBlock m_40;
    unsigned char m_4c;
    void hkpMeshShape_initWeldingInfo(int value);
};

// Sets m_4c to value; if value is 6, frees the m_40 array block, otherwise computes cumulative offsets and resizes the block to fit total.
// @fnv 0x00dcd1b0
// src: HAVOK_LIB 0x00dcd1b0
void S00dcd1b0_Obj::hkpMeshShape_initWeldingInfo(int value)
{
    int total;

    m_4c = (unsigned char)value;
    if (value != 6)
    {
        total = 0;
        for (int i = 0; i < m_38; i++)
        {
            *(int*)(m_34 + i * 0x38 + 0x34) = total;
            total += *(int*)(m_34 + i * 0x38 + 0x1c);
        }

        ArrayBlock* block = &m_40;
        hkMemoryRouter* allocator = hkMemoryRouter_getInstance();
        if ((int)(block->reservedAndFlags & 0x3fffffff) < total)
        {
            hkArrayUtil__reserve((&allocator->heap()), block, total, 2);
        }

        allocator = hkMemoryRouter_getInstance();
        void* pool = (&allocator->heap());
        int capacity = (int)(block->reservedAndFlags & 0x3fffffff);
        if (capacity < total)
        {
            int newSize = capacity + capacity;
            if (total >= newSize)
            {
                newSize = total;
            }
            hkArrayUtil__reserve(pool, block, newSize, 2);
        }
        block->size = total;
    }
    else
    {
        S00dcd1b0_Pool* pool = reinterpret_cast<S00dcd1b0_Pool*>((&hkMemoryRouter_getInstance()->heap()));
        total = 0;
        m_40.size = total;
        int flags = (int)m_40.reservedAndFlags;
        if (!(flags & 0x80000000))
        {
            pool->ReturnMemory(m_40.values, (flags & 0x3fffffff) * 2);
        }
        m_40.values = 0;
        m_40.reservedAndFlags = 0x80000000;
    }
}

struct S00dcd270_Rec
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    char unk10;
    char unk11;
    short unk12;
    int unk14;
    int unk18;
    int unk1c;
    void* unk20;
    int unk24;
    void* unk28;
    int unk2c;
    int unk30;
    int unk34;
};
struct S00dcd270_Arr
{
    S00dcd270_Rec* m_data;
    int m_iElementCount;
    int m_cap;
};
extern "C" void __cdecl ResizeAudioStream(void*, S00dcd270_Arr*, int);
extern char DAT_01267e30;
struct S00dcd270_cls
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
    S00dcd270_Arr arr;
    S00dcd270_Rec* AddRecord(const S00dcd270_Rec* a0);
};

// Grows the arr buffer if needed, initializes a new slot, copies a0 into it, and returns a pointer to the added record.
// @fnv 0x00dcd270
S00dcd270_Rec* S00dcd270_cls::AddRecord(const S00dcd270_Rec* apRecord)
{
    S00dcd270_Arr* a = &arr;
    hkMemoryRouter* h = hkMemoryRouter_getInstance();
    if (a->m_iElementCount == (a->m_cap & 0x3fffffff))
        ResizeAudioStream((&h->heap()), a, 0x38);
    S00dcd270_Rec* r = &a->m_data[a->m_iElementCount];
    if (r)
    {
        r->unk11 = 1;
        r->unk24 = 0;
        r->unk2c = 0;
        r->unk30 = 1;
        r->unk28 = 0;
        r->unk20 = 0;
        r->unk34 = -1;
        r->unk18 = 0;
    }
    r = &a->m_data[a->m_iElementCount];
    a->m_iElementCount++;
    *r = *apRecord;
    if (r->unk20 == 0)
    {
        r->unk30 = 1;
        r->unk28 = &DAT_01267e30;
        r->unk20 = &DAT_01267e30;
    }
    return r;
}

inline bool hkLargeBlockAllocator::Chunk::isInuse() const
{
    return (head & 2) != 0;
}

inline bool hkLargeBlockAllocator::Chunk::isPinuse() const
{
    return (head & 1) != 0;
}

inline unsigned int hkLargeBlockAllocator::Chunk::getChunkSize() const
{
    return head & ~3u;
}

// IsValidChunk is absent from the shared header; the unused EDX argument retains its thiscall ABI.
// Validates a chunk: 16-aligned, not below the allocator's least address, in use, size >= 16, next chunk's pinuse set, and any free previous chunk's size matches.
// @fnv 0x00dd8c40
bool __fastcall IsValidLargeBlockAllocatorChunk(const hkLargeBlockAllocator* allocator, void*, const void* in)
{
    const hkLargeBlockAllocator::Chunk* p = (const hkLargeBlockAllocator::Chunk*)((const char*)in - 16);
    if (((unsigned int)in & 15) != 0)
        return false;
    if (p < (const hkLargeBlockAllocator::Chunk*)allocator->unk0C)
        return false;
    if (!p->isInuse())
        return false;
    unsigned int size = p->getChunkSize();
    if (size < 16)
        return false;
    if (!((const hkLargeBlockAllocator::Chunk*)((const char*)p + size))->isPinuse())
        return false;
    if (!p->isPinuse())
    {
        unsigned int prevSize = p->m_uiPreviousChunkSize;
        const hkLargeBlockAllocator::Chunk* prev = (const hkLargeBlockAllocator::Chunk*)((const char*)p - prevSize);
        if (prev->isInuse())
            return false;
        if (prev->getChunkSize() != prevSize)
            return false;
    }
    return true;
}

extern "C" int getCstyleArraySize();

// @fnv 0x00dc1be0
// src: GUESS 0x00dc1be0 (confidence: low)
int Object_ProcessAndReturnValue_00dc1be0()
{
    int r = getCstyleArraySize();
    if (r != 0)
        return r;
    return 1;
}

struct S_00dc6fc0_Target
{
    virtual void v00();
    virtual int v01();
};

struct S_00dc6fc0_Class
{
    int unk00;
    int unk04;
    int unk08;
    S_00dc6fc0_Target* m_0c;

    int __thiscall ProcessAndTransformResult_00dc6fc0();
};

// @fnv 0x00dc6fc0
// src: GUESS 0x00dc6fc0 (confidence: low)
int S_00dc6fc0_Class::ProcessAndTransformResult_00dc6fc0()
{
    return m_0c->v01() ^ 0x20;
}

struct TokenReader
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int read(void* buffer, int count);
    virtual void skip(int count);
    virtual void v6();
    virtual void prepare(int count);
    virtual void reset();
};

// Reads 64-byte chunks from stream, skipping whitespace until a non-space character is found, then resets and skips to that position.
// @fnv 0x00dcc1b0
static __declspec(noinline) void SkipWhitespace(TokenReader* stream)
{
    int buffer[16];
    stream->prepare(64);
    int count = stream->read(buffer, 64);
    while (count != 0)
    {
        int index = 0;
        while (index < count)
        {
            char c = reinterpret_cast<char*>(buffer)[index];
            if (c != ' ' && c != '\t' && c != '\r' && c != '\n')
            {
                stream->reset();
                stream->skip(index);
                return;
            }
            ++index;
        }
        stream->prepare(64);
        count = stream->read(buffer, 64);
    }
}

extern TokenReader* volatile inputStream;
void MatchCaller()
{
    SkipWhitespace(inputStream);
}

struct CpuOpaque;
extern CpuOpaque DAT_01269c14;
// @fnv 0x00dccb50
// src: GUESS 0x00dccb50 (confidence: low)
CpuOpaque* __cdecl Runtime_GetDAT01269c14Address()
{
    return &DAT_01269c14;
}

struct RefObj
{
    void __thiscall FUN_00c905b0();
};

inline void memCpy4_d061(void* dst, const void* src, int nbytes)
{
    for (int i = 0; i < nbytes; i += 4)
        *(unsigned int*)((char*)dst + i) = *(const unsigned int*)((const char*)src + i);
}

template <class T> __forceinline void hkArrayBase<T>::removeAt(int index)
{
    m_iElementCount--;
    if (m_iElementCount != index)
        memCpy4_d061(m_data + index, m_data + m_iElementCount, sizeof(T));
}

struct FUN_00dceb90_Class
{
    void* vftable;
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
    hkArray<RefObj*> m_refs;
    void RemoveRef(int index);
};

// Calls FUN_00c905b0 on the RefObj at index, then removes that slot from m_refs.
// @fnv 0x00dceb90
void FUN_00dceb90_Class::RemoveRef(int index)
{
    m_refs[index]->FUN_00c905b0();
    m_refs.removeAt(index);
}

#include <math.h>
struct SubB
{
    float f00;
    float f04;
    float f08;
    float f0c;
    float f10;
};
struct ObjB
{
    float f00;
    SubB* p4;
    int u08;
    float f0c;
    float f10;
    float f14;
};
struct ObjA
{
    int u00;
    int u04;
    signed char m08;
    unsigned char u09;
    unsigned char u0a;
    unsigned char u0b;
    float f0c;
    float f10;
    union
    {
        float f14;
        void* p14;
    } u14;
    float f18;
    float f1c;
    float f20;
};

__forceinline float Limit(const float& current, const float& target, const float& d, const float& limit)
{
    float ad = fabsf(d);
    if (ad > limit)
        return target + (d > 0.0f ? limit : -limit);
    return current;
}
__forceinline float Clamp(const float& value, const float& hi, const float& lo)
{
    return value < lo ? lo : (hi < value ? hi : value);
}

// Switches on a->m08: modes 1 to 3 fill six floats in out from a and b; mode 4 calls the function pointer stored in a.
// @fnv 0x00dcfff0
// src: HAVOK_LIB 0x00dcfff0
void __cdecl _hkCalcMotorData(ObjA* a, ObjB* b, float* out)
{
    float s0, s4, s8, sC, s10, t18;
    switch ((int)a->m08 - 1)
    {
    case 0: {
        float bf = b->f10;
        t18 = b->f14;
        float xyz = a->f1c * t18 * b->p4->f0c;
        float d = t18 - xyz;
        float wz = a->f20 * b->p4->f0c;
        float t;
        if (fabsf(d) > wz)
            t = xyz + (d > 0.0f ? wz : -wz);
        else
            t = t18;
        float ab = fabsf(t18);
        t = Clamp(t, ab - b->f0c, -ab - b->f0c);
        s4 = (t + bf) * b->p4->f10;
        sC = b->f0c;
        s8 = a->f10;
        s10 = -s8;
        t18 = a->u14.f14;
        s0 = a->f18;
        break;
    }
    case 1: {
        if (*(unsigned char*)&a->f1c)
            s4 = (b->f14 + b->f10) * b->p4->f10;
        else
            s4 = a->f18;
        sC = b->f0c;
        t18 = a->u14.f14;
        s0 = a->u14.f14;
        s8 = a->f10;
        s10 = a->f0c;
        break;
    }
    case 2: {
        s4 = 0.0f;
        sC = b->f10 + b->f14;
        float recip = 1.0f / b->f00;
        float P = b->p4->f00;
        float x = a->u14.f14 * P * P * recip;
        t18 = x < 0.0f ? 0.0f : (x > 1.0f ? 1.0f : x);
        float y = P * a->f18 * recip;
        s0 = y < 0.0f ? 0.0f : (y > 1.0f ? 1.0f : y);
        s8 = a->f10;
        s10 = a->f0c;
        break;
    }
    case 3: {
        return ((void(__cdecl*)(ObjA*, ObjB*, float*))a->u14.p14)(a, b, out);
    }
    default:
        return;
    }
    out[1] = s4;
    out[0] = sC;
    out[2] = s8;
    out[3] = s10;
    out[4] = t18;
    out[5] = s0;
}

#ifndef _INCLUDED_MM2
// Exe 0x00dd0ff0 FactorTridiagonal: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
} __m128, LocalM128;
#endif
#ifndef _INCLUDED_MM2
extern "C"
{
    LocalM128 _mm_setzero_ps();
    LocalM128 _mm_cmplt_ps(LocalM128, LocalM128);
    LocalM128 _mm_cmple_ps(LocalM128, LocalM128);
    LocalM128 _mm_and_ps(LocalM128, LocalM128);
    LocalM128 _mm_andnot_ps(LocalM128, LocalM128);
    LocalM128 _mm_or_ps(LocalM128, LocalM128);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, int);
    int _mm_movemask_ps(LocalM128);
}
#endif

extern LocalM128 DAT_010c7170;

static __forceinline LocalM128 choose(LocalM128 mask, LocalM128 yes, LocalM128 no)
{
    return _mm_or_ps(_mm_andnot_ps(mask, no), _mm_and_ps(mask, yes));
}
static __forceinline LocalM128 sum4(LocalM128 v)
{
    LocalM128 pair = _mm_add_ps(_mm_shuffle_ps(v, v, 0x4e), v);
    return _mm_add_ps(_mm_shuffle_ps(pair, pair, 0xb1), pair);
}
static __forceinline LocalM128 dot4(LocalM128 a, LocalM128 b)
{
    return sum4(_mm_mul_ps(a, b));
}

struct OW
{
    const LocalM128* p;
    OW(const LocalM128* q) : p(q)
    {}
};
// @fnv 0x00dd3120
// src: XBOX_PDB 0x00dd3120
static __declspec(noinline) int hkpProcessFlyingColors(const LocalM128* self, OW other, const LocalM128* a)
{
    LocalM128 k = DAT_010c7170;
    LocalM128 av = *a;
    LocalM128 zero = _mm_setzero_ps();
    LocalM128 m = _mm_cmplt_ps(*self, *other.p);
    LocalM128 t0 = _mm_and_ps(m, av);
    LocalM128 s2 = dot4(choose(av, k, zero), k);
    LocalM128 y3 = dot4(choose(t0, k, zero), k);
    LocalM128 b = _mm_shuffle_ps(y3, y3, 0);
    LocalM128 c = _mm_shuffle_ps(s2, s2, 0);
    b = _mm_add_ps(b, b);
    return _mm_movemask_ps(_mm_cmple_ps(c, b));
}
volatile int g_s, g_a, g_o, g_r;
void mask_test_caller()
{
    OW o((const LocalM128*)g_o);
    g_r = hkpProcessFlyingColors((const LocalM128*)g_s, o, (const LocalM128*)g_a);
}

// Converts four unsigned bytes from src to floats stored in dst[0] through dst[3].
// @fnv 0x00dd31d0
static __declspec(noinline) void CopyFloatsFromBytes(float* dst, const unsigned char* src)
{
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
}
unsigned char volatile g_src[4];
float volatile g_dst[4];
void caller()
{
    CopyFloatsFromBytes((float*)g_dst, (const unsigned char*)g_src);
}

struct BEStoreTarget
{
    unsigned char m_00;
    unsigned char m_01;
    unsigned char m_02;
    unsigned char m_03;
    unsigned char m_04;
};

extern "C" unsigned int be_store_value(void);

// @fnv 0x00dd4bd0
static __declspec(noinline) void StoreBigEndian(BEStoreTarget* self, unsigned int value)
{
    self->m_01 = (unsigned char)(value >> 24);
    self->m_02 = (unsigned char)(value >> 16);
    self->m_03 = (unsigned char)(value >> 8);
    self->m_04 = (unsigned char)value;
}

void be_store_caller(BEStoreTarget* self)
{
    StoreBigEndian(self, be_store_value());
}

// Looks up the table entry for i with FUN_00dcb2b0 and calls its forward method with the owner's context value.
// @fnv 0x00dcb460
struct DispatchTarget
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void forward(int value);
};
struct Entry
{
    int key;
    DispatchTarget* target;
};
struct Table
{
    int a, b, c;
    Entry* entries;
    unsigned int StructArrayImplementation__find(unsigned int);
    DispatchTarget* entryAt(unsigned int i)
    {
        return entries[i].target;
    }
};
struct Owner
{
    int a, b, c;
    Table* table;
    int context;
    void StructArrayImplementation_Object_asObject(unsigned int);
};
// src: XBOX_PDB 0x00dcb460
void Owner::StructArrayImplementation_Object_asObject(unsigned int i)
{
    table->entryAt(table->StructArrayImplementation__find(i))->forward(context);
}

#include <stdlib.h>
// Text reader: read the next number as a double.

class DCC5E0Stream
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Skip(int iCount);
    int Peek();
    char* m_pcCursor;
};

// File-static helper (reconstructed separately); MSVC passes the stream to it in a register.
static __declspec(noinline) double DCC5E0ReadNumber(DCC5E0Stream* pkStream)
{
    double dValue = strtod(pkStream->m_pcCursor, &pkStream->m_pcCursor);
    return dValue;
}

class DCC5E0Reader
{
  public:
    int unk00;
    int unk04;
    DCC5E0Stream* m_pDataStream;

    DCC5E0Reader& ReadDouble(double& rdValue);
};

// @fnv 0x00dcc5e0
DCC5E0Reader& DCC5E0Reader::ReadDouble(double& rdValue)
{
    rdValue = DCC5E0ReadNumber(m_pDataStream);
    return *this;
}

// Adjustor thunk: the secondary-base (+0x10) vtable entry for an override defined on the derived class.

class DD470Primary
{
  public:
    virtual void FUN_00dcd470();
    int unk04;
    int unk08;
    int unk0C;
};

class DD470Secondary
{
  public:
    virtual void FUN_00dcd470();
};

class DD470Derived : public DD470Primary, public DD470Secondary
{
  public:
    DD470Derived();
// @fnv 0x00dcd470
    virtual void FUN_00dcd470();
};

DD470Derived::DD470Derived()
{}

// Stand-in for the class owning this function.
//   +0x0c : int*   array of packed triples
//   +0x18 : CRITICAL_SECTION*  shared lock
class FUN_00dd9240_cls
{
  public:
    int m_unk00;
    int m_unk04;
    int m_unk08;
    int* m_pEntryData;
    int m_unk10;
    int m_unk14;
    CRITICAL_SECTION* m_pCrit;

    int hkProcessFactory_getProcessName(int index);
};

// Reads the entry at index from m_pEntryData under m_pCrit, clears the lowest bit, and returns the result.
// @fnv 0x00dd9240
// src: HAVOK_LIB 0x00dd9240
int FUN_00dd9240_cls::hkProcessFactory_getProcessName(int index)
{
    EnterCriticalSection(this->m_pCrit);
    int value = this->m_pEntryData[index * 3] & 0xfffffffe;
    LeaveCriticalSection(this->m_pCrit);
    return value;
}

int __cdecl hkString_strCmp(unsigned int entry, unsigned int flag);

// Stand-in for the class owning this function.
//   +0x0c : int*   array of 12-byte records (first dword = flagged pointer)
//   +0x10 : int    record count
//   +0x18 : CRITICAL_SECTION*  shared lock
class FUN_00dd9270_cls
{
  public:
    int m_unk00;
    int m_unk04;
    int m_unk08;
    int* m_pEntryData;
    int m_uiItemCount;
    int m_unk14;
    CRITICAL_SECTION* m_pCrit;

    int FindEntry(unsigned int flag);
};

// Under m_pCrit, returns the first index whose entry makes FUN_00cb0fa0(entry, flag) return 0 (or is null with flag 0), else -1.
// @fnv 0x00dd9270
int FUN_00dd9270_cls::FindEntry(unsigned int flag)
{
    EnterCriticalSection(this->m_pCrit);
    int index = 0;
    if (this->m_uiItemCount > 0)
    {
        for (;;)
        {
            unsigned int entry = (unsigned int)this->m_pEntryData[index * 3] & 0xfffffffe;
            int result;
            if (entry != 0)
            {
                if (flag == 0)
                    goto next;
                result = hkString_strCmp(entry, flag);
            }
            else
            {
                result = (flag != 0) ? -1 : 0;
            }
            if (result == 0)
                goto found;
        next:
            index++;
            if (index >= this->m_uiItemCount)
                break;
        }
    }
    LeaveCriticalSection(this->m_pCrit);
    return -1;

found:
    LeaveCriticalSection(this->m_pCrit);
    return index;
}

// Stand-in for the class owning this function.
//   +0x0c : record*  array of 12-byte records
//   +0x18 : CRITICAL_SECTION*  shared lock
class FUN_00dd92f0_cls
{
  public:
    struct Record
    {
        int m_i00;
        int(__cdecl* m_pFn)(int);
        int m_i08;
    };

    int m_i00;
    int m_i04;
    int m_i08;
    Record* m_pRecords;
    int m_i10;
    int m_i14;
    CRITICAL_SECTION* m_pCrit;

    int InvokeRecord(int index, int arg);
};

// Locks m_pCrit, calls the function pointer in the Record at m_pRecords[index] with arg, unlocks, and returns the result.
// @fnv 0x00dd92f0
int FUN_00dd92f0_cls::InvokeRecord(int index, int arg)
{
    CRITICAL_SECTION* crit = this->m_pCrit;
    EnterCriticalSection(crit);
    Record* rec = &this->m_pRecords[index];
    int result = rec->m_pFn(arg);
    LeaveCriticalSection(crit);
    return result;
}

namespace fnv_00dd9d20 {
extern int DAT_010d7da8;
extern int DAT_010d7d54;
extern int DAT_010d7cfc;

struct FUN_00dd9d20_Target
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08(void* a, int b);
};

struct FUN_00dd9d20_Object
{
    void* unk00;
    int unk04;
    void* unk08;
    int unk0C;
    void* unk10;

    void __thiscall UpdateFields_00dd9d20();
};

// Sets unk00 and unk08 to data pointers, and if unk10 is set deletes that critical section and frees it via vf08 of the object at offset 0x10 of FUN_00c85750().
// @fnv 0x00dd9d20
// src: GUESS 0x00dd9d20 (confidence: low)
void __thiscall FUN_00dd9d20_Object::UpdateFields_00dd9d20()
{
    void* criticalSection = unk10;

    unk00 = reinterpret_cast<void*>(&DAT_010d7da8);
    unk08 = reinterpret_cast<void*>(&DAT_010d7d54);

    if (criticalSection != 0)
    {
        DeleteCriticalSection(static_cast<LPCRITICAL_SECTION>(criticalSection));

        hkMemoryRouter* audio = hkMemoryRouter_getInstance();
        FUN_00dd9d20_Target* target = reinterpret_cast<FUN_00dd9d20_Target*>(audio->m_heap);

        target->vf08(criticalSection, 0x18);
    }

    unk08 = reinterpret_cast<void*>(&DAT_010d7cfc);
    unk00 = reinterpret_cast<void*>(&DAT_0102e388);
}
}  // namespace fnv_00dd9d20

double FUN_00ecdf2d(const char* s, char** end);
// Skips whitespace, reads a numeric token from the stream with commas turned into dots, and returns it as a float, or -1.0f if no token starts.
// @fnv 0x00dcc3b0
// src: HAVOK_LIB 0x00dcc3b0
static float readFloat(TokenReader* stream)
{
    struct Buf256
    {
        int w[64];
    };
    Buf256 buf;
    SkipWhitespace(stream);
    int n = 0;
    stream->prepare(255);
    int len = stream->read(buf.w, 255);
    if (len != 0)
    {
        char c = ((char*)buf.w)[0];
        if ((c >= '0' && c <= '9') || c == '+' || c == '-' || c == '.' || c == ',')
        {
            n = 1;
            for (; n < len; ++n)
            {
                char ch = ((char*)buf.w)[n];
                if (!((ch >= '0' && ch <= '9') || ch == '+' || ch == '-' || ch == 'E' || ch == 'e' || ch == '.' ||
                      ch == ','))
                    break;
                if (ch == '.' || ch == ',')
                    ((char*)buf.w)[n] = '.';
            }
        }
    }
    stream->reset();
    stream->skip(n);
    ((char*)buf.w)[n] = 0;
    if (n > 0)
        return (float)FUN_00ecdf2d((char*)buf.w, 0);
    return -1.0f;
}
float MatchCaller(TokenReader* s)
{
    return readFloat(s);
}

namespace fnv_00dcc8e0 {
struct TokenBuffer
{
    char* m_data;
    unsigned int m_len;
    unsigned int m_cap;
};

struct TokenOwner
{
    int unk00;
    void FUN_00d61cc0();
    TokenBuffer* ReturnSelf();
};

struct TokenStream
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual int v04(char* buffer, int count);
    virtual void v05(int count);
    virtual void v06();
    virtual void v07(int n);
    virtual void v08();
    int ReadChar();
};

extern "C" void _ReadWriteBarrier(void);
void __cdecl ResizeAudioStream(int alloc, TokenBuffer* buf, int n);
namespace TokenParsing {
static __declspec(noinline) void SkipWhitespace(TokenStream* stream)
{
    unsigned __int64 storage[8];
    char* buffer = reinterpret_cast<char*>(storage);
    stream->v07(64);
    int n = stream->v04(buffer, 64);
    while (n != 0)
    {
        int i = 0;
        while (i < n)
        {
            char c = buffer[i];
            if (c != ' ' && c != '\t' && c != '\r' && c != '\n')
            {
                stream->v08();
                stream->v05(i);
                return;
            }
            ++i;
        }
        stream->v07(64);
        n = stream->v04(buffer, 64);
    }
}
}

template <class T> __forceinline void ConstructToken(T* p, int n, const T& value)
{
    for (int i = 0; i < n; ++i)
        p[i] = value;
}

struct TokenReader
{
    int unk00;
    int unk04;
    TokenStream* m_08;
    TokenReader* ReadToken(TokenOwner* owner);
};

// Reads a whitespace-delimited token from the stream into the owner's buffer, appending a null terminator, and returns this.
// @fnv 0x00dcc8e0
TokenReader* TokenReader::ReadToken(TokenOwner* owner)
{
    const int one = 1;
    owner->FUN_00d61cc0();
    TokenBuffer* buf = owner->ReturnSelf();
    TokenParsing::SkipWhitespace(m_08);
    m_08->v07(one);
    int c = m_08->ReadChar();
    if (c != -1)
    {
        do
        {
            if (c == 0x20 || c == 9 || c == 0xd || c == 0xa)
            {
                break;
            }
            hkMemoryRouter* h = hkMemoryRouter_getInstance();
            if (buf->m_len == (buf->m_cap & 0x3fffffff))
            {
                ResizeAudioStream((int)h->m_temp, buf, one);
            }
            char* slot = buf->m_data + buf->m_len;
            char value = (char)c;
            ConstructToken(slot, one, value);
            buf->m_len += one;
            m_08->v07(one);
            c = m_08->ReadChar();
        } while (c != -1);
    }
    m_08->v08();
    hkMemoryRouter* h2 = hkMemoryRouter_getInstance();
    if (buf->m_len == (buf->m_cap & 0x3fffffff))
    {
        ResizeAudioStream((int)h2->m_temp, buf, one);
    }
    char* slot2 = buf->m_data + buf->m_len;
    _ReadWriteBarrier();
    *slot2 = 0;
    buf->m_len += one;
    return this;
}
}  // namespace fnv_00dcc8e0

// @fnv 0x00dccb60
// src: GUESS 0x00dccb60 (confidence: high)
void __stdcall Object_DoNothing_00dccb60(int value)
{}

extern "C"
{
    LocalM128 _mm_unpackhi_ps(LocalM128, LocalM128);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    void _mm_store_ss(float*, LocalM128);
}

class S00dd0ff0_SimdReal
{
  public:
    S00dd0ff0_SimdReal(const LocalM128& x) : m_vValue(x)
    {}
    operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
    LocalM128 m_vValue;
};

class S00dd0ff0_Vector4
{
  public:
    void setMul4(const S00dd0ff0_Vector4& a, const S00dd0ff0_Vector4& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    void mul4(const S00dd0ff0_Vector4& v)
    {
        m_vComponents = _mm_mul_ps(m_vComponents, v.m_vComponents);
    }
    void add4(const S00dd0ff0_Vector4& v)
    {
        m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents);
    }
    void sub4(const S00dd0ff0_Vector4& v)
    {
        m_vComponents = _mm_sub_ps(m_vComponents, v.m_vComponents);
    }
    void setAdd4(const S00dd0ff0_Vector4& a, const S00dd0ff0_Vector4& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    void setW(const S00dd0ff0_Vector4& w)
    {
        m_vComponents = _mm_shuffle_ps(m_vComponents, _mm_unpackhi_ps(m_vComponents, w.m_vComponents), 0xc4);
    }
    void setBroadcast(const S00dd0ff0_Vector4& v, int i)
    {
        if (i == 0)
        {
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x00);
        }
        else if (i == 1)
        {
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x55);
        }
        else if (i == 2)
        {
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xaa);
        }
        else
        {
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xff);
        }
    }
    S00dd0ff0_SimdReal horizontalAdd3() const
    {
        LocalM128 xySum = _mm_add_ss(_mm_shuffle_ps(m_vComponents, m_vComponents, 0x55), m_vComponents);
        return _mm_add_ss(_mm_shuffle_ps(m_vComponents, m_vComponents, 0xaa), xySum);
    }
    S00dd0ff0_SimdReal horizontalAdd4() const
    {
        LocalM128 sum0 = _mm_add_ps(_mm_shuffle_ps(m_vComponents, m_vComponents, 0x4e), m_vComponents);
        LocalM128 sum1 = _mm_shuffle_ps(sum0, sum0, 0xb1);
        return _mm_add_ps(sum0, sum1);
    }
    LocalM128 m_vComponents;
};

struct S00dd0ff0_VelocityAccumulator
{
    unsigned char m_type;
    unsigned int m_uiDeactivationClass;
    float m_fGravityFactor;
    S00dd0ff0_Vector4 m_vLinearVelocity;
    S00dd0ff0_Vector4 m_vAngularVelocity;
    S00dd0ff0_Vector4 m_vInverseInertiaAndMass;
};

template <typename TYPE> inline const TYPE* S00dd0ff0_addByteOffsetConst(const TYPE* base, long offset)
{
    return reinterpret_cast<const TYPE*>(reinterpret_cast<const char*>(base) + offset);
}

struct S00dd0ff0_AccumulatorOffset
{
    int m_offset;
    const S00dd0ff0_VelocityAccumulator& getAccumulator(const S00dd0ff0_VelocityAccumulator* base)
    {
        return *S00dd0ff0_addByteOffsetConst(base, m_offset);
    }
};

class S00dd0ff0_Jacobian
{
  public:
    S00dd0ff0_Vector4 m_kLinearJacobian;
    S00dd0ff0_Vector4 m_kAngularVelocity[2];

    float getDiag(const S00dd0ff0_VelocityAccumulator& mA, const S00dd0ff0_VelocityAccumulator& mB) const
    {
        S00dd0ff0_Vector4 ang0;
        ang0.setMul4(m_kAngularVelocity[0], m_kAngularVelocity[0]);
        S00dd0ff0_Vector4 ang1;
        ang1.setMul4(m_kAngularVelocity[1], m_kAngularVelocity[1]);
        ang0.mul4(mA.m_vInverseInertiaAndMass);
        ang1.mul4(mB.m_vInverseInertiaAndMass);
        ang0.add4(ang1);
        S00dd0ff0_Vector4 dw;
        dw.setAdd4(mA.m_vInverseInertiaAndMass, mB.m_vInverseInertiaAndMass);
        ang0.setW(dw);
        float x = ang0.horizontalAdd4();
        return float(x + 1.1920928955078125e-07);
    }

    float getNonDiagDifferentObjects_With2ndBodyFromFirstObject(const S00dd0ff0_VelocityAccumulator& mB,
                                                                const S00dd0ff0_Jacobian& jacB) const
    {
        S00dd0ff0_Vector4 lin;
        lin.setMul4(m_kLinearJacobian, jacB.m_kLinearJacobian);
        S00dd0ff0_Vector4 ang;
        ang.setMul4(m_kAngularVelocity[1], jacB.m_kAngularVelocity[0]);
        S00dd0ff0_Vector4 invMassB;
        invMassB.setBroadcast(mB.m_vInverseInertiaAndMass, 3);
        S00dd0ff0_Vector4 linB;
        linB.setMul4(invMassB, lin);
        ang.mul4(mB.m_vInverseInertiaAndMass);
        ang.sub4(linB);
        return ang.horizontalAdd3();
    }
};

struct S00dd0ff0_Triple
{
    float m_lower;
    float m_diag;
    float m_upper;
};

inline float S00dd0ff0_max2(float a, float b)
{
    return (a > b) ? a : b;
}

// Factors a tridiagonal system by computing diagonal and off-diagonal terms from Jacobians and velocity accumulators, storing results in triple.
// @fnv 0x00dd0ff0
static __declspec(noinline) void FactorTridiagonal(int numConstraints, float cfm, S00dd0ff0_Jacobian* jac,
                                                   S00dd0ff0_AccumulatorOffset* accumsOffsets,
                                                   const S00dd0ff0_VelocityAccumulator* accumsBase,
                                                   S00dd0ff0_Triple* triple, int bufferSize)
{
    float prevNonDiag = 0.0f;
    float prevUpper = 0.0f;
    for (int row = 0; row < numConstraints; row++)
    {
        float diag = jac[row].getDiag(accumsOffsets[row].getAccumulator(accumsBase),
                                      accumsOffsets[row + 1].getAccumulator(accumsBase)) +
                     cfm;
        float nonDiag = 0.0f;
        if (row < numConstraints - 1)
        {
            nonDiag = jac[row].getNonDiagDifferentObjects_With2ndBodyFromFirstObject(
                accumsOffsets[row + 1].getAccumulator(accumsBase), jac[row + 1]);
        }
        triple[row].m_lower = prevNonDiag;
        triple[row].m_diag = diag - prevNonDiag * prevUpper;
        float& d = triple[row].m_diag;
        d = S00dd0ff0_max2(d, 1.192092896e-07F);
        triple[row].m_upper = nonDiag / triple[row].m_diag;
        prevNonDiag = nonDiag;
        prevUpper = triple[row].m_upper;
    }
}

volatile int g_S00dd0ff0_n;
volatile float g_S00dd0ff0_cfm;
volatile int g_S00dd0ff0_jac;
volatile int g_S00dd0ff0_offs;
volatile int g_S00dd0ff0_base;
volatile int g_S00dd0ff0_triple;
volatile int g_S00dd0ff0_size;
void S00dd0ff0_Caller()
{
    FactorTridiagonal(g_S00dd0ff0_n, g_S00dd0ff0_cfm, (S00dd0ff0_Jacobian*)g_S00dd0ff0_jac,
                      (S00dd0ff0_AccumulatorOffset*)g_S00dd0ff0_offs,
                      (const S00dd0ff0_VelocityAccumulator*)g_S00dd0ff0_base, (S00dd0ff0_Triple*)g_S00dd0ff0_triple,
                      g_S00dd0ff0_size);
}

struct S_00dd1180_Hdr
{
    union
    {
        float f00;
        struct
        {
            unsigned char type;
            unsigned char unk01;
            unsigned short n;
        };
    };
    unsigned int size;
    float f08;
    float f0c;
};

// Writes a type 0x1d header and n triples of floats into the buffer at *pp, copies n+1 pointers, and advances *pp by the block size.
// @fnv 0x00dd1180
// src: XBOX_PDB 0x00dd1180
void hkStiffSpringChainBuildJacobian(int n, float a, float b, float c, char** src, int stride, int u1, int u2, char** pp)
{
    char** s = src;
    char* cmd = *pp;
    S_00dd1180_Hdr* h = (S_00dd1180_Hdr*)cmd;
    h->f00 = (float)(h->f00 + 1.1920928955078125e-07);

    unsigned short u = (unsigned short)n;
    h->f08 = a;
    h->f0c = b;
    h->size = (u * 0x44 + 0x27) & 0xfffffff0;
    h->type = 0x1d;
    h->n = (unsigned short)n;

    char** d = (char**)(cmd + 0x14 + ((int)u << 6));
    int count = n + 1;
    if (count > 0)
    {
        unsigned adj = (unsigned)((char*)d - (char*)s);
        do
        {
            *(char**)((char*)s + adj) = *s;
            ++s;
        } while (--count);
    }

    int u3 = h->n;
    float zero = 0.0f;
    float w0 = zero;
    float v0 = zero;
    const LocalM128* v = (const LocalM128*)(*pp + 0x10);
    char** ptrs = (char**)(cmd + 0x14 + (u3 << 6));
    float* out = (float*)(cmd + 0x10 + u3 * 0x30);
    for (int i = 0; i < n; ++i)
    {
        char* q1 = ptrs[i + 1] + stride;
        char* q0 = ptrs[i] + stride;
        LocalM128 t = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v[3 * i + 2], v[3 * i + 2]), *(const LocalM128*)(q1 + 0x30)),
                              _mm_mul_ps(_mm_mul_ps(v[3 * i + 1], v[3 * i + 1]), *(const LocalM128*)(q0 + 0x30)));
        LocalM128 sum = _mm_add_ps(*(const LocalM128*)(q0 + 0x30), *(const LocalM128*)(q1 + 0x30));
        LocalM128 w = _mm_shuffle_ps(t, _mm_unpackhi_ps(t, sum), 0xc4);
        LocalM128 hs = _mm_add_ps(_mm_shuffle_ps(w, w, 0x4e), w);
        hs = _mm_add_ps(_mm_shuffle_ps(hs, hs, 0xb1), hs);
        float r;
        _mm_store_ss(&r, hs);
        float x = (float)(r + 1.1920928955078125e-07) + c;
        float y = zero;
        if (i < n - 1)
        {
            char* q1 = ptrs[i + 1] + stride;
            LocalM128 eq = _mm_mul_ps(_mm_mul_ps(v[3 * i + 3], v[3 * i]),
                                   _mm_shuffle_ps(*(const LocalM128*)(q1 + 0x30), *(const LocalM128*)(q1 + 0x30), 0xff));
            LocalM128 f = _mm_mul_ps(_mm_mul_ps(v[3 * i + 4], v[3 * i + 2]), *(const LocalM128*)(q1 + 0x30));
            LocalM128 diff = _mm_sub_ps(f, eq);
            LocalM128 yy = _mm_add_ss(_mm_shuffle_ps(diff, diff, 0x55), diff);
            LocalM128 zz = _mm_add_ss(_mm_shuffle_ps(diff, diff, 0xaa), yy);
            float tmp;
            _mm_store_ss(&tmp, zz);
            y = tmp;
        }
        out[i * 3] = w0;
        out[i * 3 + 1] = x - w0 * v0;
        float d = *(volatile float*)&out[i * 3 + 1];
        out[i * 3 + 1] = (d > 1.1920928955078125e-07f) ? d : 1.1920928955078125e-07f;
        float quot = y / *(volatile float*)&out[i * 3 + 1];
        out[i * 3 + 2] = quot;
        w0 = y;
        v0 = quot;
    }
    *reinterpret_cast<unsigned int*>(pp) += h->size;
}

typedef LocalM128* V;
struct Wrap
{
    V p;
    Wrap(V q) : p(q)
    {}
};

// For three vector pairs computes B*D + A*E and merges it into C under mask M1 and into O under mask M2, returning O.
// @fnv 0x00dd3020
// src: GUESS 0x00dd3020 (confidence: low)
static __declspec(noinline) V Object_ProcessAndReturnValue_00dd3020(V B, V A, V C, V O, Wrap E, V D, V M1, V M2)
{
    LocalM128 value;
    value = _mm_add_ps(_mm_mul_ps(B[0], *D), _mm_mul_ps(A[0], *E.p));
    C[0] = _mm_or_ps(_mm_and_ps(*M1, value), _mm_andnot_ps(*M1, C[0]));
    O[0] = _mm_or_ps(_mm_and_ps(*M2, value), _mm_andnot_ps(*M2, O[0]));
    value = _mm_add_ps(_mm_mul_ps(B[1], *D), _mm_mul_ps(A[1], *E.p));
    C[1] = _mm_or_ps(_mm_and_ps(*M1, value), _mm_andnot_ps(*M1, C[1]));
    O[1] = _mm_or_ps(_mm_and_ps(*M2, value), _mm_andnot_ps(*M2, O[1]));
    value = _mm_add_ps(_mm_mul_ps(B[2], *D), _mm_mul_ps(A[2], *E.p));
    C[2] = _mm_or_ps(_mm_and_ps(*M1, value), _mm_andnot_ps(*M1, C[2]));
    O[2] = _mm_or_ps(_mm_and_ps(*M2, value), _mm_andnot_ps(*M2, O[2]));
    return O;
}

void call_interleave(V B, V A, V C, V O, Wrap E, V D, V M1, V M2)
{
    Object_ProcessAndReturnValue_00dd3020(B, A, C, O, E, D, M1, M2);
}
