
// src/havok/physics/vehicle/transmission/default/hkpvehicledefaulttransmission_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x00e43d40: the skeleton of src/havok/physics/vehicle/transmission/default/hkpvehicledefaulttransmission.cpp
// with declarations corrected to what the original code does (hkpVehicleDefaultTransmission.h: hkpVehicleDefaultTransmission += float FUN_00e43d40(const struct Vehicle* vehicle, const void* input);; hkpVehicleTransmission.h: hkpVehicleTransmission += virtual void T01(); virtual void T02(); virtual void T03(); virtual void T04(); virtual void T05(); virtual voi). Move the function to its real unit once
// that unit declares it this way.

// src/havok/physics/vehicle/transmission/default/hkpvehicledefaulttransmission.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/transmission/default/hkpvehicledefaulttransmission.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpVehicleDefaultTransmission_decl_hkpvehicledefaulttransmission.h"
struct FUN_00e43d00_arg1
{
    char pad_00[0xb4];
    float value;
};
struct FUN_00e43d00_arg2
{
    char pad_00[0x0f];
    unsigned char flag;
};
struct FUN_00e43d00_class
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual float v8(FUN_00e43d00_arg1*, FUN_00e43d00_arg2*) = 0;

    float hkpVehicleDefaultTransmission_calcMainTransmittedTorque(FUN_00e43d00_arg1*, FUN_00e43d00_arg2*);
};
struct FUN_00e43c30_arg1
{
    char pad_00[0x10];
};
struct FUN_00e43c30_state
{
    char pad_00[0x0d];
    unsigned char m_reverse;
    signed char m_iGearCapacity;
};
struct FUN_00e43c30_class
{
    char pad_00[0x10];
    float m_fPrimaryRatio;
    float m_fClutchDelay;
    float m_fReverseRatio;
    float* m_pfGearRatios;

    float GetGearRatio(FUN_00e43c30_arg1* pUnused, FUN_00e43c30_state* pState);
};
struct E43Arg
{
    char data[0xb4];
    float value;
};
struct E43Result
{
    float m_uiFilterValue, m_vScale;
    float* m_outputValues;
    unsigned char m_byte12, m_byte13, m_byte14, m_byte15;
};
struct StatusResult
{
    unsigned char value;
};
struct FUN_00e43c80_s
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual float m_scale_value(E43Arg*, E43Result*) = 0;
    virtual float m_primary_value(E43Arg*, E43Result*) = 0;
    virtual StatusResult m_compute_status(E43Arg*, E43Result*) = 0;
    virtual void m_finalize(float, E43Arg*, E43Result*) = 0;
    float unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    float* unk28;
    int unk2c;
    void ComputeOutput(float timeValue, E43Arg* pInput, E43Result* pOutput);
};
struct FUN_00e43ea0_State
{
    float unk00;
    int unk04;
    int unk08;
    unsigned char unk0C;
    unsigned char unk0D;
    signed char unk0E;
    unsigned char unk0F;
    float unk10;
};
struct FUN_00e43ea0_Class
{
    int unk00;
    int unk04;
    float unk08;
    float unk0C;
    int unk10;
    float unk14;
    int unk18;
    int unk1C;
    int unk20;
    void hkpVehicleDefaultTransmission_updateCurrentGear(float a, int b, FUN_00e43ea0_State* st);
};

extern "C" const double gModifierZero;
struct VehicleWheelInfo
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
    float spinVelocity;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
};
struct VehicleData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    signed char numWheels;
};
struct Vehicle
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    VehicleData* data;
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
    VehicleWheelInfo* wheels;
};
// @fnv 0x00e43d40
// src: HAVOK_LIB 0x00e43d40
float hkpVehicleDefaultTransmission::calcTransmissionRPM(const Vehicle* vehicle, const void* input)
{
    float rpm = 0.0f;
    for (int i = 0; i < vehicle->data->numWheels; ++i)
    {
        float wheelRpm = vehicle->wheels[i].spinVelocity * 60.0 * double(0.15915494f);
        rpm += wheelRpm * m_kWheelTorqueRatios.m_data[i];
    }
    float engineRpm = rpm * getTransmissionRatio(vehicle, input);
    float result;
    if (engineRpm < gModifierZero)
        result = 0.0f;
    else
        result = engineRpm;
    return result;
}
