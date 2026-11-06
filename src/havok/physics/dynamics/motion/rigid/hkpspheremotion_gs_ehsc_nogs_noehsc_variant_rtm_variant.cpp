
// src/havok/physics/dynamics/motion/rigid/hkpspheremotion_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/dynamics/motion/rigid/hkpspheremotion_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/dynamics/motion/rigid/hkpspheremotion_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/dynamics/motion/rigid/hkpspheremotion.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/dynamics/motion/rigid/hkpspheremotion.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/motion/rigid/hkpspheremotion.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../include/hkBaseObject.h"
#include "../../../../../../include/hkReferencedObject.h"
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkMatrix3.h"
#include "../../../../../../include/hkpSphereMotion.h"

extern "C" void _ReadWriteBarrier();

// The shared sphere header has no force overrides; these adapters retain ECX=this and the original stack arguments.
// @fnv 0x00d1e4d0
void __fastcall ApplySphereForce(hkpSphereMotion* motion, void*, float dt, const hkVector4& force)
{
    hkVector4 v;
    __m128 time = _mm_load_ss(&dt);
    _ReadWriteBarrier();
    v.m_vComponents = _mm_mul_ps(_mm_shuffle_ps(time, time, 0), force.m_vComponents);
    _ReadWriteBarrier();
    hkVector4 change;
    __m128 mass = _mm_load_ps(&motion->m_kInertiaAndMassInv.x);
    __m128 inverseMass = _mm_shuffle_ps(mass, mass, 255);
    change.m_vComponents = _mm_mul_ps(_mm_shuffle_ps(inverseMass, inverseMass, 0), v.m_vComponents);
    motion->m_kTranslationalVelocity.add4(change);
}

// @fnv 0x00d1e520
void __fastcall ApplySphereForceAtPoint(hkpSphereMotion* motion, void*, float dt,
                                      const hkVector4& force, const hkVector4& point)
{
    __m128 s = _mm_load_ss(&dt);
    __m128 bc = _mm_shuffle_ps(s, s, 0);
    hkVector4 impulse;
    impulse.m_vComponents = _mm_mul_ps(bc, force.m_vComponents);
    motion->ApplyImpulseAtPoint(impulse, point);
}
