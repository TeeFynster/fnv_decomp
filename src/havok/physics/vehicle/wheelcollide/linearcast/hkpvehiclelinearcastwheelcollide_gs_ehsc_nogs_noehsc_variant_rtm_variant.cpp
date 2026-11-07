// src/havok/physics/vehicle/wheelcollide/linearcast/hkpvehiclelinearcastwheelcollide_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/vehicle/wheelcollide/linearcast/hkpvehiclelinearcastwheelcollide_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/vehicle/wheelcollide/linearcast/hkpvehiclelinearcastwheelcollide_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/vehicle/wheelcollide/linearcast/hkpvehiclelinearcastwheelcollide.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/vehicle/wheelcollide/linearcast/hkpvehiclelinearcastwheelcollide.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/wheelcollide/linearcast/hkpvehiclelinearcastwheelcollide.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
// The copied skeleton declarations are unused by this RTM variant. Use the
// shared definitions for its Havok types rather than retaining partial copies.
#include "../../../../../../include/hkpVehicleLinearCastWheelCollide.h"
#include "../../../../../../include/hkpPhantom.h"
#include "../../../../../../include/hkpPhantomOverlapListener.h"
#include "../../../../../../include/hkAabb.h"
#include "../../../../../../include/hkArray.h"
#include "../../../../../../include/hkBaseObject.h"
#include "../../../../../../include/hkContactPoint.h"
#include "../../../../../../include/hkReferencedObject.h"
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkpRejectChassisListener.h"
#include "../../../../../../include/hkpRigidBody.h"
#include "../../../../../../include/hkpShape.h"

extern "C" __m128 _mm_load_ss(const float*);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
#include "../../../../../../include/hkRotation.h"
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);

namespace WheelStateUpdate {

struct __declspec(align(16)) LcQuat
{
    float x, y, z, w;
    void setMul(const void* a, const void* b);
};



struct LcTransform
{
    hkRotation m_rotation;
    __m128 m_vTranslation;
};

struct LcWheelInfo
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    __m128 m_vContactPointVelocity;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    __m128 m_vHardPointWs;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    LcQuat m_steeringOrientation;
    __m128 unkC0;
    __m128 unkD0;
};

struct LcWheelState
{
    void* m_pPhantom;
    void* m_pCollisionShape;
    int unk08;
    int unk0C;
    LcTransform m_kMotionTransform;
    __m128 m_vTo;
};

struct LcSuspensionWheel
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    float m_fRestLength;
    int unk24;
    int unk28;
    int unk2C;
};

struct LcSuspension
{
    int unk00;
    int unk04;
    LcSuspensionWheel* m_kWheelParams;
};

struct LcChassis
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    LcQuat m_rotation;
};

struct LcVehicle
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    LcChassis* m_pChassisCollidable;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    LcSuspension* m_pSuspension;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    LcWheelInfo* m_kWheelInfoArray;
};

struct WheelCollide
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    LcWheelState* m_kWheelStates;
    void hkpVehicleLinearCastWheelCollide_updateWheelState(LcVehicle* vehicle, unsigned char wheelNum);
};

static inline __m128 splat(const float& r)
{
    __m128 q = _mm_load_ss((const float*)&r);
    return _mm_shuffle_ps(q, q, 0);
}

// @fnv 0x00e367d0
// src: XBOX_PDB 0x00e367d0
void WheelCollide::hkpVehicleLinearCastWheelCollide_updateWheelState(LcVehicle* vehicle, unsigned char wheelNum)
{
    LcWheelInfo& wheelInfo = vehicle->m_kWheelInfoArray[wheelNum];
    LcWheelState& wheelState = m_kWheelStates[wheelNum];

    LcQuat rotation;
    rotation.setMul(&vehicle->m_pChassisCollidable->m_rotation, &wheelInfo.m_steeringOrientation);

    LcTransform& transform = wheelState.m_kMotionTransform;
    transform.m_rotation.hkRotation_set(*reinterpret_cast<const hkQuaternion*>(&rotation));
    transform.m_vTranslation = wheelInfo.m_vContactPointVelocity;

    __m128 length = splat(vehicle->m_pSuspension->m_kWheelParams[wheelNum].m_fRestLength);
    wheelState.m_vTo = _mm_add_ps(_mm_mul_ps(length, wheelInfo.m_vHardPointWs), wheelInfo.m_vContactPointVelocity);
}

}
