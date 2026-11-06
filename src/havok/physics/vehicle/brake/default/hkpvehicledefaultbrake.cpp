
// src/havok/physics/vehicle/brake/default/hkpvehicledefaultbrake.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/brake/default/hkpvehicledefaultbrake.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpVehicleDefaultBrake.h"

#include <math.h>
class hkpVehicleDefaultBrakeWheelBrakingProperties
{
  public:
    hkReal m_fMaxBrakingTorque;
    hkReal m_fMinPedalInputToBlock;
    hkBool m_bConnectedToHandbrake;
    hkBool unk09;
    hkBool unk0a;
    hkBool unk0b;
};

struct Brk398_WheelData
{
    hkReal m_fSphereRadius;
    hkReal m_fViscosityFriction;
    int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
};

struct Brk398_Data
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    hkInt8 m_iWheelCount;
    hkInt8 unk21, unk22, unk23;
    int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88;
    Brk398_WheelData* m_wheelData;
};

struct Brk398_WheelInfo
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    hkReal m_fValueAtOffsetC0;
    int unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc;
};

struct Brk398_Instance
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    Brk398_Data* m_data;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44;
    Brk398_WheelInfo* m_kWheelInfoArray;
};

struct Brk398_Input
{
    hkReal m_fPrimaryValue;
    hkReal m_fSecondaryValue;
    hkReal m_fThirdValue;
    hkBool m_bFlag;
};

struct Brk398_Output
{
    hkArray<hkReal> m_kFirstRealArray;
    hkArray<hkBool> m_wheelsLocked;
    hkReal m_wheelsBlockingTimer;
};

struct Brake_e398c0 : hkpVehicleDefaultBrake
{
    void UpdateBraking(const hkReal deltaTime, const Brk398_Instance* vehicle, const Brk398_Input& input,
                       Brk398_Output& output);
};

// @fnv 0x00e398c0
void Brake_e398c0::UpdateBraking(const hkReal deltaTime, const Brk398_Instance* vehicle, const Brk398_Input& input,
                                 Brk398_Output& output)
{
    const hkReal brakingInput = input.m_fSecondaryValue;
    const hkBool isHandbrake = input.m_bFlag;
    hkBool isAnyWheelBraking = false;

    for (int i = 0; i < vehicle->m_data->m_iWheelCount; ++i)
    {
        output.m_wheelsLocked.m_data[i] =
            ((*reinterpret_cast<hkpVehicleDefaultBrakeWheelBrakingProperties**>(&m_kWheelBrakingProperties))[i].m_bConnectedToHandbrake != 0) & (isHandbrake != 0);

        if (brakingInput > (*reinterpret_cast<hkpVehicleDefaultBrakeWheelBrakingProperties**>(&m_kWheelBrakingProperties))[i].m_fMinPedalInputToBlock)
        {
            isAnyWheelBraking = true;
        }

        const hkReal r = vehicle->m_data->m_wheelData[i].m_fSphereRadius;
        const hkReal w = vehicle->m_kWheelInfoArray[i].m_fValueAtOffsetC0;
        const hkReal fViscosityFriction = vehicle->m_data->m_wheelData[i].m_fViscosityFriction;

        const hkReal impulse = -(w * r * (fViscosityFriction * (1.0f / deltaTime)));
        hkReal torque = r * impulse;
        const hkReal maxBrakingTorque = (*reinterpret_cast<hkpVehicleDefaultBrakeWheelBrakingProperties**>(&m_kWheelBrakingProperties))[i].m_fMaxBrakingTorque;
        const hkReal maxTorque = maxBrakingTorque * brakingInput;
        const hkReal absTorque = fabsf(torque);

        if (absTorque > maxTorque)
        {
            if (torque > 0.0f)
            {
                torque = maxTorque;
            }
            else
            {
                torque = -maxTorque;
            }
        }
        output.m_kFirstRealArray.m_data[i] = torque;
    }

    if (isAnyWheelBraking)
    {
        if (output.m_wheelsBlockingTimer >= m_fWheelBlockTime)
        {
            const hkArray<hkpVehicleDefaultBrakeWheelBrakingProperties>& props = m_kWheelBrakingProperties;
            for (int i = 0; i < vehicle->m_data->m_iWheelCount; ++i)
            {
                if (brakingInput > (*reinterpret_cast<hkpVehicleDefaultBrakeWheelBrakingProperties* const*>(&props))[i].m_fMinPedalInputToBlock)
                {
                    output.m_wheelsLocked.m_data[i] = true;
                }
            }
        }
        else
        {
            output.m_wheelsBlockingTimer += deltaTime;
        }
    }
    else
    {
        output.m_wheelsBlockingTimer = 0.0f;
    }
}
