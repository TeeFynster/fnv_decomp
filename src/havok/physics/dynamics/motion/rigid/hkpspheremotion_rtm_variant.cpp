// RTM variant of hkpspheremotion.cpp: matches the original VC9 RTM build.
// Exe 0x00d1e560 StepMotion: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C" LocalM128 _mm_mul_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128 a, LocalM128 b, unsigned int imm);
extern "C" LocalM128 _mm_load_ss(const float* p);

#include "../../../../../../include/hkBaseObject.h"
#include "../../../../../../include/hkReferencedObject.h"
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkMatrix3.h"
#include "../../../../../../include/hkpMotion.h"
#include "../../../../../../include/hkpSphereMotion.h"

// @fnv 0x00d1e560
void hkpMotion::StepMotion(float fMoveElapsedTime, const hkVector4& kForce)
{
    hkVector4 kImpulse;
    const LocalM128 scalar = _mm_shuffle_ps(_mm_load_ss(&fMoveElapsedTime), _mm_load_ss(&fMoveElapsedTime), 0);
    kImpulse.m_vComponents = _mm_mul_ps(scalar, kForce.m_vComponents);
    ApplyAngularImpulseToBodies(kImpulse);
}
