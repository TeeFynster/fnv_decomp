
// src/havok/physics/dynamics/constraint/bilateral/rotational/hkprotationalconstraintdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/bilateral/rotational/hkprotationalconstraintdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpRotationalConstraintData.h"

// Writes 3 and 0x18 into out[1] and out[0] when flag is set, otherwise writes 0 into both.
// @fnv 0x00e3b520
// src: HAVOK_LIB 0x00e3b520
void __stdcall hkpRotationalConstraintData_getRuntimeInfo(char flag, int* out)
{
    if (flag)
    {
        out[1] = 3;
        out[0] = 0x18;
    }
    else
    {
        out[1] = 0;
        out[0] = 0;
    }
}

void* __cdecl hkpConstraintData_getConstraintInfoUtil(void*, int, int);
struct FUN_00e3b500_cls
{
    void __thiscall hkpRotationalConstraintData_getConstraintInfo(int arg);
};
// @fnv 0x00e3b500
// src: HAVOK_LIB 0x00e3b500
void __thiscall FUN_00e3b500_cls::hkpRotationalConstraintData_getConstraintInfo(int arg)
{
    hkpConstraintData_getConstraintInfoUtil((char*)this + 0x10, 0x74, arg);
}

// Returns the constant value 16.
// @fnv 0x00e3b5b0
// src: GUESS 0x00e3b5b0 (confidence: high)
int __cdecl hkpRotationalConstraintData_ReturnConstant_16()
{
    return 16;
}

struct hkBool_ret
{
    char m_cBooleanValue;
    hkBool_ret()
    {}
    hkBool_ret(bool b) : m_cBooleanValue(b)
    {}
};

struct RotationHelper
{
    hkBool_ret __thiscall IsOrthonormal(float eps);
};

struct hkpRotationalConstraintDataHelper : public hkpRotationalConstraintData
{
    hkBool_ret __thiscall hkpRotationalConstraintData_isValid();
};

// @fnv 0x00e3b550
// src: XBOX_PDB 0x00e3b550
hkBool_ret __thiscall hkpRotationalConstraintDataHelper::hkpRotationalConstraintData_isValid()
{
    float eps = 0.001f;
    return ((RotationHelper*)&m_kBridgeAtoms.m_kLocalRotations.m_kRotationA)->IsOrthonormal(eps).m_cBooleanValue &&
           ((RotationHelper*)&m_kBridgeAtoms.m_kLocalRotations.m_kRotationB)->IsOrthonormal(eps).m_cBooleanValue;
}
