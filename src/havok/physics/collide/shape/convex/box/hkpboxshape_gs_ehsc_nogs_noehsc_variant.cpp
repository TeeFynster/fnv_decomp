#include <xmmintrin.h>
typedef ::__m128 LocalM128;

// src/havok/physics/collide/shape/convex/box/hkpboxshape_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/shape/convex/box/hkpboxshape.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/shape/convex/box/hkpboxshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/convex/box/hkpboxshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpBoxShape.h"
#include "../../../../../../../include/MemoryManager.h"
#include "../../../../../../../include/hkMemoryRouter.h"
int __cdecl hkpBoxShape_ReturnConstant_8();
float __cdecl NiMin(float a, float b);
extern "C" void* DAT_0102e388;
struct FUN_00c9db80_class
{
    void __thiscall FUN_00c9db80();
};
struct FUN_00c9e1b0_class
{
    void* vftable;
    unsigned short size;

    int FUN_00c9db80();
    void* FUN_00c9e1b0(unsigned char flags);
};
hkMemoryRouter* __cdecl _D1A0E0GetMemoryRouter();
int __stdcall Object_Return0x30(int a1, int a2);
extern "C" int DAT_01268940;
void __cdecl hkReferencedObject_calcContentStatistics(int a, int* b);
void __cdecl hkpBoxShape_calcContentStatistics(int a, int* b);
struct hkAabb;
void __cdecl ComputeAabbFromTransform(const hkTransform& transform, const hkVector4& halfExtents, hkReal tolerance,
                                      hkAabb& out);
struct FUN_00c9dc10_class : public hkpBoxShape
{
    void __thiscall GetAabb(const hkTransform& transform, hkReal tolerance, hkAabb& out) const;
};
extern void* DAT_010c70b4;
struct VectorExtents
{
    float x, y, z, w;
};
struct CenteredPointBounds
{
    void* m_ppVirtualMethodTable;
    unsigned short m_usAllocationSize;
    unsigned short m_sReferenceCount;
    int m_ulUserData;
    int m_iType;
    float m_fSphereRadius;
    float m_localCenterX;
    float m_localCenterY;
    float m_localCenterZ;
    VectorExtents m_vHalfExtents;

    CenteredPointBounds* SetExtentsAndRadius(const float* extents, float radius);
};
typedef ::__m128 LocalM128;
using ::_mm_and_ps;
using ::_mm_xor_ps;
using ::_mm_cmplt_ps;
using ::_mm_setzero_ps;
using ::_mm_load_ps;
using ::_mm_store_ps;
using ::_mm_movemask_ps;
extern float DAT_010c44d0[4];
struct S00c9dc40_Box : public hkpBoxShape
{
    void __thiscall getSupportingVertexImpl(const float* src, float* dst);
};
// @fnv 0x00c9dcb0
extern "C" void __stdcall ZeroResult(LocalM128* result)
{
    *result = _mm_setzero_ps();
}

using ::_mm_mul_ps;

extern "C" const LocalM128 DAT_010c7030[];

struct FUN_00c9dcd0_vertex
{
    union
    {
        LocalM128 quad;
        struct
        {
            float x;
            float y;
            float z;
            unsigned int id;
        };
    };
};

struct FUN_00c9dcd0_object
{
    unsigned char unknown00[0x20];
    LocalM128 halfExtents;

    void __thiscall hkpBoxShape_convertVertexIdsToVerticesImpl(const unsigned short* ids, int count, FUN_00c9dcd0_vertex* output);
};

// @fnv 0x00c9dcd0
// src: HAVOK_SRC 0x00c9dcd0
void __thiscall FUN_00c9dcd0_object::hkpBoxShape_convertVertexIdsToVerticesImpl(const unsigned short* ids, int count, FUN_00c9dcd0_vertex* output)
{
    for (int i = count - 1; i >= 0; --i)
    {
        unsigned int id = *ids;
        LocalM128 value = _mm_mul_ps(DAT_010c7030[id], halfExtents);

        output->quad = value;
        output->id = id | 0x3f000000u;

        ++output;
        ++ids;
    }
}
