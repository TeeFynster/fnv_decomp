
// src/havok/physics/vehicle/hkpvehicleinstance_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/vehicle/hkpvehicleinstance.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/vehicle/hkpvehicleinstance.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/hkpvehicleinstance.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../include/hkArray.h"
#include "../../../../include/hkBool.h"
#include "../../../../include/hkMemoryAllocator.h"
#include "../../../../include/hkMemoryRouter.h"
#include "../../../../include/hkReferencedObject.h"
#include "../../../../include/hkStringPtr.h"
#include "../../../../include/hkpEntity.h"
#include "../../../../include/hkpWorld.h"
#include "../../../../include/hkpVehicleInstance.h"

extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" void _mm_store_ss(float*, __m128);

struct WVec4
{
    __m128 m_vComponents;
    void hkVector4_setRotatedDir(const struct hkRotation& r, const WVec4& v);
    float dot3(const WVec4& a) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        __m128 r = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        r = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), r);
        float f;
        _mm_store_ss(&f, r);
        return f;
    }
};
#include "../../../../include/hkRotation.h"

struct WFloat4
{
    float x;
    float y;
    float z;
    float w;
};
struct WRigidBody
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
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
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
    int unkdc;
    int unke0;
    int unke4;
    unsigned char m_bFlag;
    unsigned char unke9;
    unsigned short unkea;
};

struct WChassis
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
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
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
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    hkRotation m_rotation;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    WVec4 m_kTranslationalVelocity;
};
struct WWheelInfo
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
    WRigidBody* m_pUserData;
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
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
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
    float m_fValueAtOffsetC0;
    float m_fSpinAngle;
    float m_fSkidEnergyDensity;
    float m_fSideForce;
    float m_fSuspensionForce;
    float m_fForwardForce;
    int unkd8;
    int unkdc;
};
struct WWheelParams
{
    float m_fSphereRadius;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    signed char m_iAxle;
    char unk25;
    char unk26;
    char unk27;
};
struct WData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    WVec4 m_kGravity;
    signed char m_iWheelCount;
    WVec4 m_chassisOrientation0;
    WVec4 m_chassisOrientation1;
    WVec4 m_chassisOrientation2;
    float unk60;
    float unk64;
    float unk68;
    float unk6c;
    float unk70;
    float unk74;
    float unk78;
    float unk7c;
    float unk80;
    float unk84;
    float unk88;
    WWheelParams* m_kWheelParams;
};
struct WAccum
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    WVec4 m_vLinearVelocity;
};
struct WGround
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
    WAccum* m_accumulator;
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
};
// Partial vehicle view retained: hkpVehicleInstance.h does not declare the wheel-update method at 0x00e38310.
struct WVehicle
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    WChassis* m_pEntity;
    WData* m_data;
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
    WWheelInfo* m_kWheelInfoArray;
    int m_wheelsInfoSize;
    int m_wheelsInfoCap;
    hkpVehicleFrictionStatus m_kFrictionStatus;
    int unk9c;
    hkBool* m_kSecondRealArray;
    void ProcessEntries_00e38310(float deltaTime, const int* groundBody, const WGround* ground);
};

// @fnv 0x00e38310
// src: GUESS 0x00e38310 (confidence: low)
void WVehicle::ProcessEntries_00e38310(float deltaTime, const int* groundBody, const WGround* ground)
{
    for (int w = 0; w < m_data->m_iWheelCount; ++w)
    {
        WWheelInfo& wheel = m_kWheelInfoArray[w];
        const int axle = m_data->m_kWheelParams[w].m_iAxle;
        const hkpVehicleFrictionStatus::AxisStatus& status = m_kFrictionStatus.m_kAxisEndPoints[axle];

        wheel.m_fSkidEnergyDensity =
            (wheel.m_pUserData != 0 && wheel.m_pUserData->m_bFlag == 5) ? status.m_fAxisStatusMetric3 : 0.0f;
        wheel.m_fSideForce = status.m_fAxisStatusMetric4;
        wheel.m_fForwardForce = status.m_fAxisStatusMetric2;
        wheel.m_fSuspensionForce = status.m_fAxisStatusMetric1;

        WVec4 forward;
        forward.hkVector4_setRotatedDir(m_pEntity->m_rotation, m_data->m_chassisOrientation1);
        const float chassisVel = forward.dot3(m_pEntity->m_kTranslationalVelocity);

        if (!m_kSecondRealArray[w])
        {
            const float linVel = chassisVel + wheel.m_fSuspensionForce;
            float forwardVel = linVel;
            if (groundBody[axle] != 0)
            {
                WVec4 groundVel = ground[axle].m_accumulator->m_vLinearVelocity;
                forwardVel = linVel - forward.dot3(groundVel);
            }
            wheel.m_fValueAtOffsetC0 = forwardVel / m_data->m_kWheelParams[w].m_fSphereRadius;
            const float angle = deltaTime * wheel.m_fValueAtOffsetC0;
            wheel.m_fSpinAngle += angle;
        }
        else
        {
            wheel.m_fValueAtOffsetC0 = 0.0f;
        }
    }
}
