
// src/havok/physics/dynamics/constraint/chain/hingelimits/hkphingelimitsdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/chain/hingelimits/hkphingelimitsdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkRotation.h"

extern "C" void __cdecl hkpConstraintData_getConstraintInfoUtil(void* a, int b, int c);
struct hkPhingeLimitsData
{
    void __thiscall hkpHingeLimitsData_getConstraintInfo(int arg);
};
// @fnv 0x00d52f10
// src: HAVOK_LIB 0x00d52f10
void __thiscall hkPhingeLimitsData::hkpHingeLimitsData_getConstraintInfo(int arg)
{
    hkpConstraintData_getConstraintInfoUtil((char*)this + 0x10, 0x84, arg);
}

struct hkHingeLimitsData
{
    int m_fMinAngle;
    int m_fMaxAngle;
};

// @fnv 0x00d52f30
void __stdcall InitHingeLimitsData(const char* a, hkHingeLimitsData* pHingeLimitsData)
{
    pHingeLimitsData->m_fMaxAngle = 3;
    pHingeLimitsData->m_fMinAngle = 0x1c;
}

// @fnv 0x00d52fb0
// src: GUESS 0x00d52fb0 (confidence: high)
int __cdecl hkpHingeLimitsData_ReturnConstant_18()
{
    return 18;
}

// Partial hinge-limit validation view: rotations are at +0x20/+0x50; the shared data header lacks this validation method.
class HingeLimitsRotationValidationView
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    hkRotation m_kRotationA;
    hkRotation m_kRotationB;

    hkBool hkpHingeLimitsData_isValid() const;
};

// @fnv 0x00d52f50
// src: XBOX_PDB 0x00d52f50
hkBool HingeLimitsRotationValidationView::hkpHingeLimitsData_isValid() const
{
    return m_kRotationA.IsOrthonormal(0.001f) && m_kRotationB.IsOrthonormal(0.001f);
}
