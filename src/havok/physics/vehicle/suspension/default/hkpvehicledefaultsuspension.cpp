
// src/havok/physics/vehicle/suspension/default/hkpvehicledefaultsuspension.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/suspension/default/hkpvehicledefaultsuspension.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/hkArray.h"

class FUN_00c86430_s
{
  public:
    float FUN_00c86430() const;
};

struct EntityE397
{
    int unk00[0xe0 / 4];
    FUN_00c86430_s m_pMotionState;

    const FUN_00c86430_s* getMotion() const
    {
        return &m_pMotionState;
    }
    float GetMassValue() const
    {
        return getMotion()->FUN_00c86430();
    }
};

struct VehicleDataE397
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    signed char m_iWheelCount;
};

struct VehicleE397
{
    int unk00, unk04, unk08, unk0C, unk10, unk14;
    EntityE397* m_pEntity;
    VehicleDataE397* m_data;
};

struct CdWheelOutputE397
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    void* m_pUserData;
    int unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44;
    float m_fContactFriction;
    float m_fValueAtOffset4C;
    float m_fValueAtOffset50;
    int unk54, unk58, unk5C;
};

struct SuspensionWheelParamsE397
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    float m_fRestLength;
    int unk24, unk28, unk2C;
};

struct WheelSpringParamsE397
{
    float m_fSpringStrength;
    float m_fDampingCompression;
    float m_fDampingRelaxation;
};

class SuspensionE397
{
  public:
    virtual ~SuspensionE397();
    int unk04;
    hkArray<SuspensionWheelParamsE397> m_kWheelParams;
    hkArray<WheelSpringParamsE397> m_kWheelSpringSuspensionParameters;

    void CalculateSuspensionForces(const void* pkStepInfo, const VehicleE397* pkVehicle,
                                   const CdWheelOutputE397* pkCdInfo, float* pfSuspensionForceOut);
};

// Computes per-wheel suspension forces from spring and damping parameters, scaled by chassis mass, and writes them to pfSuspensionForceOut.
// @fnv 0x00e397f0
void SuspensionE397::CalculateSuspensionForces(const void* pkStepInfo, const VehicleE397* pkVehicle,
                                               const CdWheelOutputE397* pkCdInfo, float* pfSuspensionForceOut)
{
    const float fChassisMass = pkVehicle->m_pEntity->GetMassValue();
    for (int w_it = 0; w_it < pkVehicle->m_data->m_iWheelCount; w_it++)
    {
        if (pkCdInfo[w_it].m_pUserData)
        {
            const float fLengthDiff = m_kWheelParams[w_it].m_fRestLength - pkCdInfo[w_it].m_fContactFriction;
            const float fSpringForce = fLengthDiff * m_kWheelSpringSuspensionParameters[w_it].m_fSpringStrength *
                                       pkCdInfo[w_it].m_fValueAtOffset50;
            const float fClosing = pkCdInfo[w_it].m_fValueAtOffset4C;
            const float fDampingCoefficient = fClosing < 0.0f
                                                  ? m_kWheelSpringSuspensionParameters[w_it].m_fDampingCompression
                                                  : m_kWheelSpringSuspensionParameters[w_it].m_fDampingRelaxation;
            const float fForce = fSpringForce - fDampingCoefficient * fClosing;
            pfSuspensionForceOut[w_it] = fForce * fChassisMass;
        }
        else
        {
            pfSuspensionForceOut[w_it] = 0.0f;
        }
    }
}
