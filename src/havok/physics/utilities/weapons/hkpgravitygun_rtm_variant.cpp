// src/havok/physics/utilities/weapons/hkpgravitygun_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/weapons/hkpgravitygun.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/utilities/weapons/hkpgravitygun.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/weapons/hkpgravitygun.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
// Exe 0x00e46080 FUN_00e46080: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C"
{
    LocalM128 _mm_load_ss(const float*);
    LocalM128 _mm_load_ps(const float*);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    void _mm_store_ss(float*, LocalM128);
    void _mm_store_ps(float*, LocalM128);
}
#pragma intrinsic(_mm_load_ss, _mm_load_ps, _mm_shuffle_ps, _mm_mul_ps, _mm_store_ss, _mm_store_ps)

#include "../../../../../include/hkArray.h"
#include "../../../../../include/hkBool.h"
#include "../../../../../include/hkStringPtr.h"
#include "../../../../../include/hkVector4.h"
#include "../../../../../include/hkpFirstPersonGun.h"
#include "../../../../../include/hkpRigidBody.h"
#include "../../../../../include/hkpGravityGun.h"

class hkpWorld;

// The shared hkpGravityGun lacks FUN_00e46000 and FUN_00e46080; retain this class until those methods are approved.

extern double DAT_01012070;

__forceinline void hkVector4::mul4(const float& factor)
{
    hkVector4& out = *this;
    LocalM128 scalar = _mm_load_ss(&factor);
    LocalM128 vector = _mm_load_ps((const float*)&out);
    LocalM128 broadcast = _mm_shuffle_ps(scalar, scalar, 0);
    _mm_store_ps((float*)&out, _mm_mul_ps(broadcast, vector));
}

// @fnv 0x00e46080
// src: XBOX_PDB 0x00e46080
void hkpGravityGun::gravityGunPull(hkTransform* a4, hkpRigidBody* a3, hkpWorld* world)
{
    hkVector4* direction = (hkVector4*)a4;
    int argC = (int)a3;
    int arg10 = (int)world;
    hkpGravityGun* gun = this;
    hkpRigidBody* target = gun->FindVisibleRigidBodyToGrab((int)direction, argC, arg10);

    if (target != 0)
    {
        LocalM128 massVector = _mm_load_ps((const float*)&target->m_pMotionState.m_kInertiaAndMassInv);
        massVector = _mm_shuffle_ps(massVector, massVector, 0xff);

        float mass;
        _mm_store_ss(&mass, massVector);

        if (!(gun->m_fMaxPickMass * mass < DAT_01012070))
        {
            if (gun->m_kPickedBodies.m_iElementCount < gun->m_iMaxPickedBodies)
            {
                gun->takeObject(target);
                return;
            }
        }

        hkVector4 impulse;
        _mm_store_ps((float*)&impulse, _mm_load_ps((const float*)direction));
        impulse.mul4(-gun->m_fPickAngle);
        target->activate_00c9c1d0();
        target->m_pMotionState.SetCollisionShape(impulse);
    }
}
