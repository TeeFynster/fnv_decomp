// src/havok/physics/collide/shape/hkpshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/hkpshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Preserve the original intrinsic representation: the SDK union's byte arrays
// cause this compiler to add /GS instrumentation.
#define _INCLUDED_MM2
// Exe 0x00c9e560 getMaximumProjection: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;

extern "C" LocalM128 _mm_setzero_ps();
extern "C" LocalM128 _mm_add_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_sub_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_mul_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_and_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_xor_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_add_ss(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128 a, LocalM128 b, unsigned int imm);
extern "C" void _mm_store_ss(float* p, LocalM128 a);
extern "C" LocalM128 _mm_load_ss(const float* p);
extern "C" LocalM128 _mm_rcp_ps(LocalM128 a);

#include "../../../../../include/hkAabb.h"
#include "../../../../../include/hkBaseObject.h"
#include "../../../../../include/hkReferencedObject.h"
#include "../../../../../include/hkTransform.h"
#include "../../../../../include/hkpShape.h"

// @fnv 0x00c9e3f0
// src: HAVOK_SRC 0x00c9e3f0
int __stdcall hkpConvexTransformShapeBase_calcSizeForSpu(void* p, int size)
{
    return -1;
}

extern const LocalM128 DAT_010c71d0;
extern const LocalM128 DAT_010c44d0;

inline hkTransform::hkTransform()
{}

inline void hkTransform::setIdentity()
{
    LocalM128 kZero = _mm_setzero_ps();
    m_row0 = kZero;
    m_row1 = kZero;
    m_row2 = kZero;
    reinterpret_cast<float*>(&m_row0)[0] = 1.0f;
    reinterpret_cast<float*>(&m_row1)[1] = 1.0f;
    reinterpret_cast<float*>(&m_row2)[2] = 1.0f;
    m_row3 = _mm_setzero_ps();
}

// Computes the support point of the shape's AABB along kDirection and returns its dot product with kDirection.
// @fnv 0x00c9e560
float hkpShape::getMaximumProjection(const hkVector4& kDirection) const
{
    hkTransform kLocalToWorld;
    kLocalToWorld.setIdentity();
    const float fTolerance = 0.0f;
    // SIMD output storage avoids invoking vector constructors that were inline
    // in the original unit but are external in the approved shared headers.
    LocalM128 aabbStorage[sizeof(hkAabb) / sizeof(LocalM128)];
    hkAabb& kAabb = reinterpret_cast<hkAabb&>(aabbStorage);
    CalculateAabb(kLocalToWorld, fTolerance, kAabb);

    LocalM128 kTargetCenter = _mm_add_ps(kAabb.m_kMinimumCorner.m_vComponents, kAabb.m_kMaximumCorner.m_vComponents);
    kTargetCenter = _mm_mul_ps(kTargetCenter, DAT_010c71d0);
    LocalM128 kHalfExtent = _mm_sub_ps(kAabb.m_kMaximumCorner.m_vComponents, kAabb.m_kMinimumCorner.m_vComponents);
    kHalfExtent = _mm_mul_ps(kHalfExtent, DAT_010c71d0);

    LocalM128 kSupport = _mm_xor_ps(kHalfExtent, _mm_and_ps(kDirection.m_vComponents, DAT_010c44d0));
    kSupport = _mm_add_ps(kSupport, kTargetCenter);
    const LocalM128 x2 = _mm_mul_ps(kSupport, kDirection.m_vComponents);
    const LocalM128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    float result;
    _mm_store_ss(&result, _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xySum));
    return result;
}
