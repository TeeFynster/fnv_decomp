
// src/havok/physics/vehicle/suspension/default/hkpvehicledefaultsuspensionclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/suspension/default/hkpvehicledefaultsuspensionclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>
#include "../../../../../../include/hkMemoryRouter.h"

__declspec(align(16)) struct VecElem
{
    __m128 m_kPointA;
    __m128 m_kPointB;
    float m_iThirdValue;
};

struct VecList
{
    VecElem* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapBits;
};

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
void __cdecl ResizeAudioStream(void* allocator, VecList* list, unsigned int elemSize);

struct FUN_00e3afb0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    VecList m_kNode;

    void Push(const __m128* a, const __m128* b, float c);
};

// Grows the VecList if full, then appends a VecElem built from two __m128 values and a float.
// @fnv 0x00e3afb0
void FUN_00e3afb0_cls::Push(const __m128* apFirst, const __m128* apSecond, float afValue)
{
    VecList* list = &m_kNode;
    hkMemoryRouter* holder = hkMemoryRouter_getInstance();
    if (list->m_iArrayLength == (int)(list->m_uCapBits & 0x3fffffffu))
    {
        ResizeAudioStream(holder->m_heap, list, sizeof(VecElem));
    }
    VecElem* slot = &list->m_pData[list->m_iArrayLength];
    list->m_iArrayLength++;
    slot->m_kPointA = *apFirst;
    __m128 bv = *apSecond;
    slot->m_iThirdValue = afValue;
    slot->m_kPointB = bv;
}

namespace fnv_00dfbff0 {
struct DFBFF0Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void ReleaseBlock(void* p, int numBytes);
};

extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance();

inline DFBFF0Allocator& heap(hkMemoryRouter& holder)
{
    return *reinterpret_cast<DFBFF0Allocator*>(holder.m_heap);
}

struct FUN_00dfbff0
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    FUN_00dfbff0();
    virtual ~FUN_00dfbff0();

    static void operator delete(void* p, unsigned int nbytes)
    {
        FUN_00dfbff0* b = static_cast<FUN_00dfbff0*>(p);
        heap(hkMemoryRouter_getInstance()).ReleaseBlock(p, b->m_usMemSizeAndFlags);
    }
};

// Empty default constructor; the class's operator delete releases the block through the heap allocator of FUN_00c85750.
// @fnv 0x00dfbff0
FUN_00dfbff0::FUN_00dfbff0()
{}
}  // namespace fnv_00dfbff0
