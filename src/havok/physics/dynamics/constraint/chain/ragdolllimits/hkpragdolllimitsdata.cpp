
// src/havok/physics/dynamics/constraint/chain/ragdolllimits/hkpragdolllimitsdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/chain/ragdolllimits/hkpragdolllimitsdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkpConstraintData.h"
#include "../../../../../../../include/hkpTwistLimitConstraintAtom.h"
#include "../../../../../../../include/hkpConeLimitConstraintAtom.h"
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;

extern "C" void __cdecl FUN_00d21a60(void* p, unsigned int x, unsigned int y);

struct FUN_00d4f130_StandIn
{
    void FUN_00d4f130(unsigned int a);
};

// @fnv 0x00d4f130
void FUN_00d4f130_StandIn::FUN_00d4f130(unsigned int auiValue)
{
    FUN_00d21a60((char*)this + 0x10, 0xac, auiValue);
}

// @fnv 0x00d4f150
void __stdcall FUN_00d4f150(int aiUnused, int* b)
{
    b[1] = 3;
    b[0] = 0x1c;
}

struct hkPragdollLimitsData
{
    void __thiscall FUN_00d4f270(bool value);
};

// @fnv 0x00d4f270
void __thiscall hkPragdollLimitsData::FUN_00d4f270(bool value)
{
    ((char*)this)[0x9a] = (unsigned char)((value ? 1 : 0) << 4);
}

// @fnv 0x00d4f290
int FUN_00d4f290()
{
    return 0x13;
}

extern float DAT_01017d00;
extern double DAT_01024108;
extern double DAT_0101ff40;

#include "../../../../../../../include/hkRotation.h"


struct FUN_00d4f170_Rotations
{
    hkUint16 unk10;
    hkUint16 unk12;
    hkUint32 unk14;
    hkUint32 unk18;
    hkUint32 unk1C;
    hkRotation m_kRotationA;
    hkRotation m_kRotationB;
};

struct S00d4f170_StandIn : public hkpConstraintData
{
    int unk0C;
    FUN_00d4f170_Rotations m_kLocalRotations;
    hkpTwistLimitConstraintAtom m_kTwistLimit;
    hkpConeLimitConstraintAtom m_kConeLimit;
    hkpConeLimitConstraintAtom m_kPlaneLimit;

    virtual char* __thiscall FUN_00d4f170(char* result);
};
// Sets *result to whether both rotations pass IsOrthonormal and the cone, plane and twist limit angles satisfy the checked comparisons; returns result.
// @fnv 0x00d4f170
char* __thiscall S00d4f170_StandIn::FUN_00d4f170(char* result)
{
    char* __restrict out = result;
    char* p;

    *out = 1;
    p = m_kLocalRotations.m_kRotationA.IsOrthonormal(reinterpret_cast<char*>(&result), DAT_01017d00);
    *out = (*p != 0);
    *out = (*out != 0) &&
           (*(p = m_kLocalRotations.m_kRotationB.IsOrthonormal(reinterpret_cast<char*>(&result), DAT_01017d00)) != 0);
    *out = (*out != 0) && (m_kConeLimit.m_fMinAngle == DAT_01024108);
    *out = (*out != 0) && (m_kConeLimit.m_fMaxAngle >= 0.0f);
    *out = (*out != 0) && (m_kConeLimit.m_fMaxAngle < DAT_0101ff40);
    *out = (*out != 0) && (m_kPlaneLimit.m_fMinAngle <= m_kPlaneLimit.m_fMaxAngle);
    *out = (*out != 0) && (m_kTwistLimit.m_fMinAngle <= m_kTwistLimit.m_fMaxAngle);
    return out;
}
