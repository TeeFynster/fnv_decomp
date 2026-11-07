
// src/havok/physics/dynamics/motion/rigid/hkpkeyframedrigidmotion.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/motion/rigid/hkpkeyframedrigidmotion.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Exe 0x00d1dfa0 0hkpKeyframedRigidMotion: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;

extern "C" LocalM128 _mm_setzero_ps();

#include "../../../../../../include/hkBaseObject.h"
#include "../../../../../../include/hkReferencedObject.h"
#include "../../../../../../include/hkQuaternion.h"
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkpKeyframedRigidMotion.h"


// @fnv 0x00d1df70
void __fastcall SetAndAddReference(hkpKeyframedRigidMotion* motion, void*, hkReferencedObject* apObject)
{
    if (apObject)
        apObject->addReference();
    if (motion->m_pSavedMotion)
        reinterpret_cast<hkReferencedObject*>(motion->m_pSavedMotion)->removeReference();
    motion->m_pSavedMotion = reinterpret_cast<hkpMaxSizeMotion*>(apObject);
}

extern int DAT_010c6bec;
extern int _DAT_0102e388;
// Sets the vtable to DAT_010c6bec, releases the reference at offset 0x118 if present, then sets the vtable to _DAT_0102e388.
// @fnv 0x00d1dff0
void __fastcall ReleaseSavedMotion(hkpKeyframedRigidMotion* motion, void*)
{
    *reinterpret_cast<void**>(motion) = (void*)&DAT_010c6bec;
    if (motion->m_pSavedMotion)
        reinterpret_cast<hkReferencedObject*>(motion->m_pSavedMotion)->removeReference();
    *reinterpret_cast<void**>(motion) = (void*)&_DAT_0102e388;
}

// @fnv 0x00d1dec0
// src: COMMUNITY 0x00d1dec0
void __stdcall nullsub_38(int)
{}

// @fnv 0x00d1ded0
// src: COMMUNITY 0x00d1ded0
void __stdcall nullsub_39(int)
{}

// @fnv 0x00d1dee0
// src: COMMUNITY 0x00d1dee0
void __stdcall nullsub_40(int)
{}

// @fnv 0x00d1def0
// src: COMMUNITY 0x00d1def0
void __stdcall nullsub_41(int)
{}

// @fnv 0x00d1df00
// src: COMMUNITY 0x00d1df00
void __stdcall nullsub_42(int)
{}

// @fnv 0x00d1df10
// src: COMMUNITY 0x00d1df10
void __stdcall nullsub_43(int, int)
{}

// @fnv 0x00d1df20
// src: COMMUNITY 0x00d1df20
void __stdcall nullsub_44(int)
{}

// @fnv 0x00d1df30
// src: COMMUNITY 0x00d1df30
void __stdcall nullsub_46(int, int)
{}

// @fnv 0x00d1df40
// src: COMMUNITY 0x00d1df40
void __stdcall nullsub_45(int a, int b, int c)
{}

// @fnv 0x00d1df50
// src: COMMUNITY 0x00d1df50
void __stdcall nullsub_47(int, int)
{}

// @fnv 0x00d1df60
// src: COMMUNITY 0x00d1df60
void __stdcall nullsub_48(int, int)
{}

template <typename ENUM, typename STORAGE>
__forceinline hkEnum<ENUM, STORAGE>::hkEnum(ENUM value) : m_kStorage(static_cast<STORAGE>(value))
{}

__forceinline void hkVector4::setZero4()
{
    m_vComponents = _mm_setzero_ps();
}

// Calls hkpMotion(kPosition, kRotationBasis, false), zeroes the saved-motion fields and inverse inertia, and selects keyframed motion.
// @fnv 0x00d1dfa0
hkpKeyframedRigidMotion::hkpKeyframedRigidMotion(const hkVector4& kPosition, const hkQuaternion& kRotationBasis) throw()
    : hkpMotion(kPosition, kRotationBasis, false)
{
    m_pSavedMotion = 0;
    m_savedMotionSize = 0;
    m_kInertiaAndMassInv.setZero4();
    m_type = MOTION_KEYFRAMED;
}

struct FUN_00d1e030_t
{
    float f0, f1, f2, f3;
    float f4, f5, f6, f7;
    float f8, f9, fA, fB;
    float fC, fD, fE, fF;
};
// @fnv 0x00d1e030
// src: HAVOK_SRC 0x00d1e030
void __stdcall hkpKeyframedRigidMotion_getInertiaWorld(FUN_00d1e030_t* p)
{
    LocalM128 z = _mm_setzero_ps();
    *(LocalM128*)&p->f0 = z;
    *(LocalM128*)&p->f4 = z;
    *(LocalM128*)&p->f8 = z;
}

// @fnv 0x00d1e050
void __stdcall ZeroFloatArray(float* apFloats)
{
    LocalM128 z = _mm_setzero_ps();
    *reinterpret_cast<LocalM128*>(apFloats) = z;
    *reinterpret_cast<LocalM128*>(apFloats + 4) = z;
    *reinterpret_cast<LocalM128*>(apFloats + 8) = z;
}

// @fnv 0x00d1e070
void __stdcall ZeroFloats(float* apFloats)
{
    LocalM128 z = _mm_setzero_ps();
    *(reinterpret_cast<LocalM128*>(apFloats)) = z;
    *(reinterpret_cast<LocalM128*>(apFloats) + 1) = z;
    *(reinterpret_cast<LocalM128*>(apFloats) + 2) = z;
}

namespace fnv_00d1e090 {
// Exe 0x00d1dfa0 0hkpKeyframedRigidMotion: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C"
{
    LocalM128 _mm_load_ps(const float*);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
    void _mm_store_ss(float*, LocalM128);
}

// Writes transVel.direction + angVel.(direction x (position - center of mass)) to angularResult and 0 to zeroResult.
// @fnv 0x00d1e090
void __fastcall ComputeVelocityAlongDirection(const hkpKeyframedRigidMotion* motion, void*,
                                              hkVector4* position, hkVector4* direction, float* angularResult,
                                              float* zeroResult)
{
    LocalM128 delta =
        _mm_sub_ps(_mm_load_ps(reinterpret_cast<const float*>(position)),
                   _mm_load_ps(reinterpret_cast<const float*>(&motion->m_kMotionState.m_kSweptTransform.m_vCenterOfMass1)));
    LocalM128 a = _mm_mul_ps(_mm_shuffle_ps(_mm_load_ps(reinterpret_cast<const float*>(direction)),
                                         _mm_load_ps(reinterpret_cast<const float*>(direction)), 0xC9),
                          _mm_shuffle_ps(delta, delta, 0xD2));
    LocalM128 b = _mm_mul_ps(_mm_shuffle_ps(_mm_load_ps(reinterpret_cast<const float*>(direction)),
                                         _mm_load_ps(reinterpret_cast<const float*>(direction)), 0xD2),
                          _mm_shuffle_ps(delta, delta, 0xC9));
    LocalM128 lin = _mm_mul_ps(_mm_load_ps(reinterpret_cast<const float*>(&motion->m_kTranslationalVelocity)),
                            _mm_load_ps(reinterpret_cast<const float*>(direction)));
    LocalM128 cross = _mm_mul_ps(_mm_sub_ps(a, b), _mm_load_ps(reinterpret_cast<const float*>(&motion->m_kAngularVelocity)));
    LocalM128 s1 = _mm_add_ss(_mm_shuffle_ps(cross, cross, 0x55), cross);
    LocalM128 s2 = _mm_add_ss(_mm_shuffle_ps(cross, cross, 0xAA), s1);
    LocalM128 t1 = _mm_add_ss(_mm_shuffle_ps(lin, lin, 0x55), lin);
    LocalM128 t2 = _mm_add_ss(_mm_shuffle_ps(lin, lin, 0xAA), t1);
// Exe 0x00d1e010: unit-local Vector4f view; declarations and layout are preserved.
    struct HkpkeyframedrigidmotionVector4fView
    {
        float x, y, z, w;
    } q;
    _mm_store_ss(&q.w, _mm_add_ss(s2, t2));
    *angularResult = q.w;
    *zeroResult = 0.0f;
}
}  // namespace fnv_00d1e090

extern "C" void _mm_store_ps(float*, LocalM128);

// @fnv 0x00d1e010
// src: HAVOK_SRC 0x00d1e010
void __stdcall hkpKeyframedRigidMotion_getInertiaLocal(hkVector4* inertia)
{
    LocalM128 zero = _mm_setzero_ps();
    _mm_store_ps(reinterpret_cast<float*>(inertia), zero);
    _mm_store_ps(reinterpret_cast<float*>(inertia) + 4, zero);
    _mm_store_ps(reinterpret_cast<float*>(inertia) + 8, zero);
}
