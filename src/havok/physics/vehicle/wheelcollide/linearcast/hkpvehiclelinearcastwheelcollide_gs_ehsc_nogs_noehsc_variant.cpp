
// src/havok/physics/vehicle/wheelcollide/linearcast/hkpvehiclelinearcastwheelcollide_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/vehicle/wheelcollide/linearcast/hkpvehiclelinearcastwheelcollide.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/vehicle/wheelcollide/linearcast/hkpvehiclelinearcastwheelcollide.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/wheelcollide/linearcast/hkpvehiclelinearcastwheelcollide.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../include/hkAabb.h"
#include "../../../../../../include/hkArray.h"
#include "../../../../../../include/hkBaseObject.h"
#include "../../../../../../include/hkContactPoint.h"
#include "../../../../../../include/hkReferencedObject.h"
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkpRejectChassisListener.h"
#include "../../../../../../include/hkpRigidBody.h"
#include "../../../../../../include/hkpShape.h"
#include "../../../../../../include/hkpVehicleData.h"
#include "../../../../../../include/hkpCollidable.h"

extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ss(__m128 a, __m128 b);
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_load_ps(const float* p);
extern "C" void _mm_store_ss(float* p, __m128 a);

struct HitStandIn
{
    hkContactPoint m_vContactPoint;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    hkpCollidable* m_kCollidable;  // at 0x48
    unsigned int m_uiCollisionShapeKey;           // at 0x4c
};

struct WheelCollideOutputStandIn
{
    hkContactPoint m_vContactPoint;
    float m_fSlipAngle;
    hkpRigidBody* m_pUserData;
    unsigned int m_uiCollisionShapeKey;
    int m_hardpointIndex;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    float m_suspensionLength;
    float m_suspensionClosingVelocity;
    float m_invSuspensionClosingVelocity;
};

struct WheelSuspensionInfoStandIn
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    float m_fRestLength;  // at 0x20
    int unk24;
    int unk28;
    int unk2c;  // sizeof = 0x30
};

struct SuspensionStandIn
{
    int unk00;
    int unk04;
    WheelSuspensionInfoStandIn* m_wheelData;  // at 0x08
};

struct WheelStateStandIn
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    __m128 m_dir;  // at 0x80
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;  // sizeof = 0xe0
};

struct VehicleInstanceStandIn
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    hkpRigidBody* m_pChassisCollidable;  // at 0x18
    hkpVehicleData* m_data;               // at 0x1c
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    SuspensionStandIn* m_pSuspension;  // at 0x34
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    WheelStateStandIn* m_kWheelStates;  // at 0x48
};

extern "C" void _ReadWriteBarrier(void);

inline float dot3(__m128 a, __m128 b)
{
    __m128 mul = _mm_mul_ps(a, b);
    __m128 y = _mm_shuffle_ps(mul, mul, 0x55);
    __m128 z = _mm_shuffle_ps(mul, mul, 0xaa);
    __m128 sum = _mm_add_ss(y, mul);
    sum = _mm_add_ss(z, sum);
    float res;
    _mm_store_ss(&res, sum);
    return res;
}

// @fnv 0x00e36510
// src: HAVOK_SRC 0x00e36510
void __stdcall hkpVehicleLinearCastWheelCollide_getCollisionOutputFromCastResult(VehicleInstanceStandIn* vehicle, unsigned char wheelIndex, HitStandIn* hit,
                            WheelCollideOutputStandIn* out)
{
    float velChassis = vehicle->m_pSuspension->m_wheelData[wheelIndex].m_fRestLength;
    WheelStateStandIn* velGround = &vehicle->m_kWheelStates[wheelIndex];

    out->m_vContactPoint.m_vContactPosition.m_vComponents = hit->m_vContactPoint.m_vContactPosition.m_vComponents;
    out->m_vContactPoint.m_vSeparatingNormal.m_vComponents = hit->m_vContactPoint.m_vSeparatingNormal.m_vComponents;

    hkpRigidBody* val;
    hkpCollidable* i;
    i = hit->m_kCollidable;
    if (i->m_kBroadPhaseHandle.m_type == 1)
    {
        val = (hkpRigidBody*)((char*)i + i->m_iOwnerOffset);
    }
    else
    {
        val = 0;
    }
    out->m_pUserData = val;
    out->m_fSlipAngle = val->m_iMaterialIndex.m_fSlipAngle;
    out->m_uiCollisionShapeKey = hit->m_uiCollisionShapeKey;
    out->m_hardpointIndex = -1;
    out->m_suspensionLength = hit->m_vContactPoint.m_vSeparatingNormal.w * velChassis;

    float pObj;
    pObj = dot3(velGround->m_dir, out->m_vContactPoint.m_vSeparatingNormal.m_vComponents);
    if (pObj < -vehicle->m_data->m_fChassisUnitInertiaPitch)
    {
        float z[4];
        float len[4];
        vehicle->m_pChassisCollidable->hkpRigidBody_getPointVelocity(reinterpret_cast<const SpringVector*>(&out->m_vContactPoint.m_vContactPosition), reinterpret_cast<SpringVector*>(len));
        out->m_pUserData->hkpRigidBody_getPointVelocity(reinterpret_cast<const SpringVector*>(&out->m_vContactPoint.m_vContactPosition), reinterpret_cast<SpringVector*>(z));
        __m128 idx;
        idx = _mm_load_ps(z);
        __m128 wheelState;
        wheelState = _mm_load_ps(len);
        float vc;
        vc = dot3(_mm_sub_ps(wheelState, idx), out->m_vContactPoint.m_vSeparatingNormal.m_vComponents);
        float q;
        q = (float)(-1.0 / pObj);
        out->m_suspensionClosingVelocity = q * vc;
        out->m_invSuspensionClosingVelocity = q;
    }
    else
    {
        out->m_suspensionClosingVelocity = 0.0f;
        out->m_invSuspensionClosingVelocity = 1.0f / vehicle->m_data->m_fChassisUnitInertiaPitch;
    }
}
