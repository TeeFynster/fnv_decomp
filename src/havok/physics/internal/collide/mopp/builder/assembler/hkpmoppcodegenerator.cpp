#include "../../../../../../../../include/hkArray.h"
#include "../../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../../include/hkThreadMemory.h"

// src/havok/physics/internal/collide/mopp/builder/assembler/hkpmoppcodegenerator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/mopp/builder/assembler/hkpmoppcodegenerator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C"
{
    void* __cdecl FUN_00c85750(void);
    void __cdecl FUN_00c856c0(void*, void*);
}
extern int DAT_0102e388;
extern void* DAT_010ea5b4;
inline hkThreadMemory& GetMoppMemoryRouter()
{
    return *static_cast<hkThreadMemory*>(FUN_00c85750());
}

__forceinline hkMemoryAllocator& hkThreadMemory::heap()
{
    return *reinterpret_cast<hkMemoryAllocator*>(m_pMemoryAllocator);
}

template <typename T>
__forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& allocator)
{
    unsigned int flags = m_iCapacityState;
    m_iElementCount = 0;
    if ((flags & 0x80000000u) == 0)
        allocator.bufFree(m_data, (flags & 0x3fffffffu) * sizeof(T));
    m_data = 0;
    m_iCapacityState = 0x80000000u;
}

struct SomeClass
{
    void* vtable;
    int unk04;
    int unk08;
    int unk0c;
    void* unk10;
    hkArray<unsigned __int64> buffer;
    void Destroy();
};
// Resets the vtable, frees unk10 through the allocator if set, clears buffer, then sets the vtable to DAT_0102e388.
// @fnv 0x00e06650
void SomeClass::Destroy()
{
    void* p = unk10;
    vtable = &DAT_010ea5b4;
    if (p)
    {
        void* q = FUN_00c85750();
        FUN_00c856c0(*(void**)((char*)q + 0x10), p);
    }
    void* s = FUN_00c85750();
    void* t = *(void**)((char*)s + 0x10);
    buffer._clearAndDeallocate(*static_cast<hkMemoryAllocator*>(t));
    vtable = &DAT_0102e388;
}

char* __cdecl AllocateWithHeader(hkMemoryAllocator* alloc, int numBytes);
void __cdecl FUN_00c856c0(hkMemoryAllocator* alloc, void* p);
extern "C" void __cdecl FUN_00cb1280(void* dst, int c, int n);
extern "C" void __cdecl FUN_00cb1260(void* dst, const void* src, int nbytes);

struct E06490Stack
{
    int unk00;
    int unk04;
    int m_pRayCursor;
    int unk0C;
    char* m_buffer;

    void GrowBuffer();
};

// @fnv 0x00e06490
void E06490Stack::GrowBuffer()
{
    int newCapacity = m_pRayCursor * 2;
    char* newBuffer = AllocateWithHeader(&GetMoppMemoryRouter().heap(), newCapacity);
    FUN_00cb1280(newBuffer, 0xcd, m_pRayCursor);
    FUN_00cb1260(newBuffer + m_pRayCursor, m_buffer, m_pRayCursor);
    char* oldBuffer = m_buffer;
    m_pRayCursor *= 2;
    FUN_00c856c0(&GetMoppMemoryRouter().heap(), oldBuffer);
    m_buffer = newBuffer;
}


void* __cdecl hkAllocateE06(hkMemory* pkHeap, int iNumBytes) throw();

class FUN_00e065f0 : public hkReferencedObject
{
  public:
    FUN_00e065f0(int iSize);
    virtual ~FUN_00e065f0();

    int m_uiLogicalSize;
    int m_iUsed;
    void* m_pData;
    hkArray<int> m_kArray;
};

// @fnv 0x00e065f0
FUN_00e065f0::FUN_00e065f0(int iSize)
{
    hkMemory* pkHeap = hkThreadMemory::GetMonitorStream()->m_pMemoryAllocator;
    m_pData = hkAllocateE06(pkHeap, iSize);
    m_uiLogicalSize = iSize;
    m_iUsed = 0;
}

// @fnv 0x00e06480
extern "C" void __cdecl FUN_00e06480()
{}

#include <xmmintrin.h>
extern "C" void __cdecl FUN_00c908c0(void* heap, void* arr, int n, int elemSize);
extern "C" void __cdecl FUN_00cb1260(void* dst, const void* src, int n);

__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return hkThreadMemory::GetMonitorStream()->heap();
}

template <typename T>
__forceinline void hkArrayBase<T>::_reserveExactly(hkMemoryAllocator& a, int n)
{
    if ((m_iCapacityState & 0x3fffffff) < n)
        FUN_00c908c0(&a, this, n, sizeof(T));
}

template <typename T>
__forceinline void hkArrayBase<T>::GrowArrayCapacity(hkMemoryAllocator& a, int n)
{
    int c = m_iCapacityState & 0x3fffffff;
    if (c < n)
    {
        int dbl = c * 2;
        FUN_00c908c0(&a, this, (n < dbl) ? dbl : n, sizeof(T));
    }
}

template <typename T>
__forceinline void hkArrayBase<T>::_setSize(hkMemoryAllocator& a, int n)
{
    GrowArrayCapacity(a, n);
    m_iElementCount = n;
}

__forceinline void* __cdecl hkReferencedObject::operator new(std::size_t n)
{
    char* p = (char*)hkThreadMemory::GetMonitorStream()->heap().blockAlloc(n);
    *(short*)(p + 4) = (short)n;
    return p;
}

__forceinline void hkReferencedObject::operator delete(void*) {}

struct S_00e064f0_Obj : hkReferencedObject
{
    int unk08, unk0C;
    __m128 m10;
    hkArray<char> m_aiIndexedValues;
    char m2c;
    S_00e064f0_Obj() throw()
    {
        m10 = _mm_setzero_ps();
        m2c = 2;
    }
    virtual ~S_00e064f0_Obj() throw();
};

struct FUN_00e064f0_class
{
    int unk00, unk04, unk08, unk0C, unk10;
    S_00e064f0_Obj* FUN_00e064f0();
};

// Allocates an S_00e064f0_Obj, copies unk0C bytes from unk08+(unk10-unk0C) into its array, frees unk10, clears unk10 and unk0C, and sets unk08 to the old count.
// @fnv 0x00e064f0
S_00e064f0_Obj* FUN_00e064f0_class::FUN_00e064f0()
{
    int n = unk0C;
    S_00e064f0_Obj* pNewObj = new S_00e064f0_Obj;
    pNewObj->m_aiIndexedValues.reserveExactly(n);
    pNewObj->m_aiIndexedValues.setSize(n);
    FUN_00cb1260(pNewObj->m_aiIndexedValues.m_data, (char*)unk08 + (unk10 - unk0C), n);
    void* pOldBuffer = (void*)unk10;
    FUN_00c856c0(GetMoppMemoryRouter().m_pMemoryAllocator, pOldBuffer);
    unk10 = 0;
    unk0C = 0;
    unk08 = n;
    return pNewObj;
}

namespace fnv_00e066c0 {
struct CpuObject
{
    unsigned int unk00;
    unsigned short size;
    void Destroy();
    CpuObject* FUN_00e066c0(unsigned int flags);
};
// Calls FUN_00e06650, then if the low bit of flags is set, invokes the global CpuAllocator with this and size, and returns this.
// @fnv 0x00e066c0
CpuObject* CpuObject::FUN_00e066c0(unsigned int flags)
{
    Destroy();
    if (flags & 1)
    {
        hkThreadMemory& holder = GetMoppMemoryRouter();
        reinterpret_cast<hkMemoryAllocator*>(holder.m_pMemoryAllocator)->blockFree(this, size);
    }
    return this;
}
}  // namespace fnv_00e066c0
