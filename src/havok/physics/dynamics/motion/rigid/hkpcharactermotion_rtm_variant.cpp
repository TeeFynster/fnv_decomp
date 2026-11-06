// RTM variant of hkpcharactermotion.cpp: these functions match VC9 RTM (15.00.21022.08).
// Exe 0x00d1efd0 ApplyCharacterForceAtPoint: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C" LocalM128 _mm_load_ss(const float*);
extern "C" LocalM128 _mm_load_ps(const float*);
extern "C" void _mm_store_ps(float*, LocalM128);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);

#include "../../../../../../include/hkBaseObject.h"
#include "../../../../../../include/hkReferencedObject.h"
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkMatrix3.h"
#include "../../../../../../include/hkpCharacterMotion.h"
#include "../../../../../../include/hkpSphereMotion.h"

// The shared class lacks these wrapper declarations; an unused EDX argument preserves the thiscall ABI.
// @fnv 0x00d1efd0
void __fastcall ApplyCharacterForceAtPoint(hkpCharacterMotion* motion, void*, float s,
                                         const hkVector4& v, const hkVector4& point)
{
    __declspec(align(16)) hkVector4 t;
    LocalM128 x = _mm_load_ss(&s);
    LocalM128 k = _mm_shuffle_ps(x, x, 0);
    LocalM128 r = _mm_mul_ps(k, _mm_load_ps(&v.x));
    _mm_store_ps(&t.x, r);
    motion->ApplyImpulseAtPoint(t, point);
}

// @fnv 0x00d1f010
void __fastcall ApplyCharacterTorque(hkpCharacterMotion* motion, void*, float step, const hkVector4& torque)
{
    __declspec(align(16)) hkVector4 angularStep;
    LocalM128 scalar = _mm_load_ss(&step);
    LocalM128 scale = _mm_shuffle_ps(scalar, scalar, 0);
    _mm_store_ps(&angularStep.x, _mm_mul_ps(scale, _mm_load_ps(&torque.x)));
    motion->ApplyAngularImpulseToBodies(angularStep);
}
