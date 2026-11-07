
// src/fallout_shared/tesobjectweap_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tesobjectweap.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "tesobjectweap_decls.h"

// sub ecx, 0x3c ; jmp target  --  MSVC virtual adjustor thunk.
// The thunk converts the pointer to the second base sub-object back into a
// pointer to the complete object before jumping to the implementation.
struct PrimaryBase
{
    virtual void AdjustThisAndForward_00525c00();
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
};

struct SecondaryBase
{
    virtual void AdjustThisAndForward_00525c00();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00525c00
// src: GUESS 0x00525c00 (confidence: low)
    virtual void AdjustThisAndForward_00525c00();
};

Derived::Derived()
{}

#include <math.h>
static float NI_HALF_PI;
float NiFastATan2(float y, float x);

inline float NiASin(float fValue)
{
    if (-1.0f < fValue)
    {
        if (fValue < 1.0f)
            return float(asin(fValue));
        else
            return NI_HALF_PI;
    }
    else
    {
        return -NI_HALF_PI;
    }
}

struct RotationMatrix
{
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
    bool NiMatrix3_ToEulerAnglesZXY(float& x, float& y, float& z);
};

// @fnv 0x00a59400
// src: GAMEBRYO_LIB 0x00a59400
bool RotationMatrix::NiMatrix3_ToEulerAnglesZXY(float& x, float& y, float& z)
{
    y = -NiASin(m21);
    if (y < NI_HALF_PI)
    {
        if (y > -NI_HALF_PI)
        {
            x = -NiFastATan2(-m01, m11);
            z = -NiFastATan2(-m20, m22);
            return true;
        }
        else
        {
            float fRmY = NiFastATan2(m02, m00);
            z = 0.0f;
            x = fRmY - z;
            return false;
        }
    }
    else
    {
        float fRpY = NiFastATan2(m02, m00);
        z = 0.0f;
        x = z - fRpY;
        return false;
    }
}
