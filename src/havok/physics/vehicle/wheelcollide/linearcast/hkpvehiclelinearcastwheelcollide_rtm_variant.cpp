// src/havok/physics/vehicle/wheelcollide/linearcast/hkpvehiclelinearcastwheelcollide_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/vehicle/wheelcollide/linearcast/hkpvehiclelinearcastwheelcollide.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /O2 /GS /EHsc /Gy (unit lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton.

// src/havok/physics/vehicle/wheelcollide/linearcast/hkpvehiclelinearcastwheelcollide.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/wheelcollide/linearcast/hkpvehiclelinearcastwheelcollide.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
// The original reduced SIMD lane declaration preserves VC9 RTM alias analysis;
// the additional integer lane views in xmmintrin.h change this function's code.
#define _INCLUDED_MM2
// Exe 0x00e36700 FUN_00e36700: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C" LocalM128 _mm_setr_ps(float x, float y, float z, float w);

#include "../../../../../../include/hkAabb.h"
#include "../../../../../../include/hkArray.h"
#include "../../../../../../include/hkBaseObject.h"
#include "../../../../../../include/hkContactPoint.h"
#include "../../../../../../include/hkReferencedObject.h"
#include "../../../../../../include/hkTransform.h"
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkpAabbPhantom.h"
#include "../../../../../../include/hkpCollidable.h"

#include "../../../../../../include/hkpVehicleLinearCastWheelCollide.h"
#include "../../../../../../include/hkpVehicleData.h"
#include "../../../../../../include/hkpVehicleInstance.h"

// These reflected vehicle types do not yet have include/ headers. Their value
// members use the shared Havok definitions rather than the generated hkBase copies.
#define FNV_HAVOK_HKBASE_H
#define FNV_HAVOK_HKREFERENCEDOBJECT_H
#include "havok/hkpVehicleLinearCastWheelCollideWheelState.h"

#include "havok/hkpVehicleSuspension.h"
#include "havok/hkpVehicleSuspensionSuspensionWheelParameters.h"

inline void hkVector4::set(float x, float y, float z, float w)
{
    *reinterpret_cast<LocalM128*>(this) = _mm_setr_ps(x, y, z, w);
}

void __cdecl hkAabbUtil_calcAabb_00d26230(int transform, int extents, int center, float tolerance, int output);

// The shared collide class supplies the layout; this unit's bounds method is
// declared here because the shared header does not yet declare that method.
class WheelBoundsCalculator : public hkpVehicleLinearCastWheelCollide
{
public:
    void __thiscall hkpVehicleLinearCastWheelCollide_calcAabbOfWheel(const hkpVehicleInstance* vehicle, unsigned char wheelIndex, hkAabb& output);
};

// @fnv 0x00e36700
// src: XBOX_PDB 0x00e36700
void __thiscall WheelBoundsCalculator::hkpVehicleLinearCastWheelCollide_calcAabbOfWheel(const hkpVehicleInstance* vehicle, unsigned char wheelIndex, hkAabb& output)
{
    int index = wheelIndex;
    const hkpVehicleData::WheelComponentParams* wheel = vehicle->m_data->m_kWheelParams.m_data + index;
    const hkpVehicleSuspensionSuspensionWheelParameters* suspension = vehicle->m_pSuspension->m_kWheelParams.m_data + index;

    double zero = 0.0;
    float halfHeight = static_cast<float>((suspension->m_fRestLength + wheel->m_fSphereRadius) * 0.5);
    float halfWidth = static_cast<float>(0.5 * wheel->m_fMaxFriction);
    hkVector4 extents;
    extents.set(wheel->m_fSphereRadius, halfHeight, halfWidth, 0.0f);
    hkVector4 center;
    center.set(0.0f, -halfHeight, 0.0f, 0.0f);

    int transform = reinterpret_cast<int>(&m_kWheelStates.m_data[index].m_kMotionTransform);
    hkAabbUtil_calcAabb_00d26230(transform, reinterpret_cast<int>(&extents), reinterpret_cast<int>(&center), zero,
                 reinterpret_cast<int>(&output));
}
