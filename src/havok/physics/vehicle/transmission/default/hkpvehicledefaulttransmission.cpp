
// src/havok/physics/vehicle/transmission/default/hkpvehicledefaulttransmission.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/transmission/default/hkpvehicledefaulttransmission.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/hkBool.h"

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

// Returns zero when the flag is set, otherwise multiplies the value from arg1 by the result of v8.
// @fnv 0x00e43d00
// src: HAVOK_LIB 0x00e43d00
float FUN_00e43d00_class::hkpVehicleDefaultTransmission_calcMainTransmittedTorque(FUN_00e43d00_arg1* pInput, FUN_00e43d00_arg2* arg2)
{
    if (arg2->flag)
        return 0.0f;

    float result = pInput->value;
    result *= this->v8(pInput, arg2);
    return result;
}

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

// @fnv 0x00e43c30
float FUN_00e43c30_class::GetGearRatio(FUN_00e43c30_arg1* pUnused, FUN_00e43c30_state* pState)
{
    if (pState->m_reverse)
    {
        float fRatio = -m_fReverseRatio;
        float fResult = m_fPrimaryRatio * *(volatile const float*)&fRatio;
        return fResult;
    }
    float fRatio = m_pfGearRatios[pState->m_iGearCapacity];
    float fResult = m_fPrimaryRatio * *(volatile const float*)&fRatio;
    return fResult;
}

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
// Computes status, scale and primary values into pOutput, fills m_outputValues scaled by the scale value, then finalizes.
// @fnv 0x00e43c80
void FUN_00e43c80_s::ComputeOutput(float timeValue, E43Arg* pInput, E43Result* pOutput)
{
    pOutput->m_byte13 = m_compute_status(pInput, pOutput).value;
    pOutput->m_vScale = m_scale_value(pInput, pOutput);
    pOutput->m_uiFilterValue = m_primary_value(pInput, pOutput);
    for (int i = 0; i < unk2c; ++i)
    {
        float temp = unk28[i] * pOutput->m_vScale;
        pOutput->m_outputValues[i] = temp;
    }
    m_finalize(timeValue, pInput, pOutput);
}

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

// @fnv 0x00e43ea0
// src: HAVOK_LIB 0x00e43ea0
void FUN_00e43ea0_Class::hkpVehicleDefaultTransmission_updateCurrentGear(float afDelta, int aiUnused, FUN_00e43ea0_State* pState)
{
    float fRemaining = pState->unk10 - afDelta;
    pState->unk10 = fRemaining;
    if (pState->unk0F)
    {
        if (fRemaining <= 0.0f)
        {
            pState->unk0F = 0;
        }
    }
    if (pState->unk0D)
    {
        return;
    }
    if (pState->unk00 < unk08)
    {
        if (pState->unk0E > 0)
        {
            pState->unk0E--;
            pState->unk10 = unk14;
            pState->unk0F = 1;
        }
    }
    if (pState->unk00 > unk0C)
    {
        if (pState->unk0E + 1 < unk20)
        {
            pState->unk0E++;
            pState->unk10 = unk14;
            pState->unk0F = 1;
        }
    }
}

struct ObjAE43C
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84, unk88, unk8C;
    int unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC;
    bool m_bEnableState;
};

struct ObjBE43C
{
    int unk00, unk04, unk08;
    short unk0C;
    signed char m_cLevel;
};

// Returns true if pkA is enabled and pkB's level is not positive, otherwise false.
// @fnv 0x00e43c00
// src: HAVOK_LIB 0x00e43c00
hkBool __stdcall hkpVehicleDefaultTransmission_calcIsReversing(ObjAE43C* pkA, ObjBE43C* pkB)
{
    if (!pkA->m_bEnableState)
        return false;
    if (pkB->m_cLevel > 0)
        return false;
    return true;
}
