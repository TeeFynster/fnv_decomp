#include <xmmintrin.h>


// src/havok/physics/internal/collide/mopp/builder/mediator/shape/hkpmoppshapemediator_gs_nogs_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/internal/collide/mopp/builder/mediator/shape/hkpmoppshapemediator.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include "../../../../../../../../../include/hkpConvexShape.h"
#include "../../../../../../../../../include/hkpShape.h"
#include "../../../../../../../../../include/hkpShapeContainer.h"

int __stdcall ReadIntField(const void* a, int* b);
struct FUN_00dd5260_T
{
    int a;
    int b;
    int c;
    int d;
    int e;
};
void __stdcall hkpMoppShapeMediator_splitPrimitive(FUN_00dd5260_T* pSrc, int a1, int a2, int a3, FUN_00dd5260_T* pDst);
struct FUN_00dd5210_Record
{
    int value;
    int reserved;
    int unk08;
    int unk0c;
    int unk10;
};
struct FUN_00dd5210_Object
{
    int unk00;
    int unk04;
    hkpShapeContainer* unk08;
    int unk0c;
    void FillRecords(FUN_00dd5210_Record* records);
};
struct SpawnedBase
{
    virtual ~SpawnedBase()
    {}
};
class FUN_00dd52a0_cls : public SpawnedBase
{
  public:
    short unk04;
    unsigned short m_flag06;
    hkpShapeContainer* m_src08;
    int m_result0c;

    FUN_00dd52a0_cls* InitFromSource(hkpShapeContainer* src);
};
struct CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    CpuAllocator* allocator;
};
CpuAllocatorHolder* __cdecl hkMemoryRouter_getInstance();
struct CpuObject
{
    unsigned int unk00;
    unsigned short size;
    void InitializeFields_00dd51d0();
    CpuObject* FUN_00dd55a0(unsigned int flags);
};
void __stdcall nullsub_83(int, int);
struct FnvCpu_FUN_00dd5290_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    int value;
    int GetValue();
};
extern "C"
{
    __m128 _mm_xor_ps(__m128, __m128);
}

extern __m128 DAT_010c44d0;
typedef float hkReal;
typedef unsigned int hkpShapeKey;
#include "../../../../../../../../../include/hkVector4.h"
__forceinline void hkVector4::setNeg4(const hkVector4& v) { m_vComponents = _mm_xor_ps(v.m_vComponents, DAT_010c44d0); }

struct __declspec(align(16)) hkpShapeBuffer
{
    int m_data[128];
};
struct ProjectionSample
{
    hkpShapeKey m_key;
    int m_unk04;
    hkReal m_kMinimumCorner;
    hkReal m_kMaximumCorner;
    int m_unk10;
};
struct ProjectionShape
{
    int unk00;
    int unk04;
    hkpShapeContainer* m_container;

    void ComputeProjectionRange(const hkVector4& direction, int unused, ProjectionSample* samples, int numSamples,
                                hkReal* minOut, hkReal* maxOut);
};

namespace fnv_00dd5440 {
struct hkpChildKey
{
    unsigned int m_key;
    int m_unk04;
    int m_unk08;
    int m_unk0c;
    int m_unk10;
};

struct ExtentCalculator
{
    int m_unk00;
    int m_unk04;
    const hkpShapeContainer* m_container;

    void hkpMoppShapeMediator_findExtents(const hkVector4& direction, int unused, const hkpChildKey* keys, int numKeys, float* minOut,
                      float* maxOut) const;
};

// @fnv 0x00dd5440
// src: XBOX_PDB 0x00dd5440
void ExtentCalculator::hkpMoppShapeMediator_findExtents(const hkVector4& direction, int unused, const hkpChildKey* keys, int numKeys,
                                    float* minOut, float* maxOut) const
{
    hkpShapeBuffer buffer;
    float lo;
    float hi;

    unsigned int key = keys[0].m_key;
    const hkpConvexShape* shape = static_cast<const hkpConvexShape*>(m_container->GetShapeForKey(key, buffer));
    if (shape)
    {
        hi = shape->getMaximumProjection(direction);
        hkVector4 negDir;
        negDir.setNeg4(direction);
        lo = -shape->getMaximumProjection(negDir);
    }
    else
    {
        lo = 0.0f;
        hi = 0.0f;
    }

    float fTargetUpperBound = lo;
    float fMinimumInputValue = hi;

    for (int i = 1; i < numKeys; i++)
    {
        key = keys[i].m_key;
        shape = static_cast<const hkpConvexShape*>(m_container->GetShapeForKey(key, buffer));
        if (shape)
        {
            hi = shape->getMaximumProjection(direction);
            hkVector4 negDir;
            negDir.setNeg4(direction);
            lo = -shape->getMaximumProjection(negDir);
        }
        else
        {
            lo = 0.0f;
            hi = 0.0f;
        }

        if (lo < fTargetUpperBound)
        {
            fTargetUpperBound = lo;
        }
        if (hi > fMinimumInputValue)
        {
            fMinimumInputValue = hi;
        }
    }

    *minOut = fTargetUpperBound;
    *maxOut = fMinimumInputValue;
}
}  // namespace fnv_00dd5440
