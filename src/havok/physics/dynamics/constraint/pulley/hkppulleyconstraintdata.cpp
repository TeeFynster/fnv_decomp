
// src/havok/physics/dynamics/constraint/pulley/hkppulleyconstraintdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/pulley/hkppulleyconstraintdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/hkpPulleyConstraintData.h"

void __cdecl hkpConstraintData_getConstraintInfoUtil(void* a, int b, int c);

// @fnv 0x00deef40
void hkpPulleyConstraintData::vf15(int a)
{
    hkpConstraintData_getConstraintInfoUtil((char*)this + 0x10, 0x70, a);
}

// Writes 1 and 8 into b[1] and b[0] when a is nonzero, otherwise writes 0 into both.
// @fnv 0x00deef60
void hkpPulleyConstraintData::vf09(char a, int* b)
{
    if (a)
    {
        b[1] = 1;
        b[0] = 8;
    }
    else
    {
        b[1] = 0;
        b[0] = 0;
    }
}

// Returns true when both unk70 and m_fRopeLength are greater than zero.
// @fnv 0x00deef90
hkBool hkpPulleyConstraintData::vf07() const
{
    return unk70 > 0.0f && m_fRopeLength > 0.0f;
}

// @fnv 0x00deefc0
int hkpPulleyConstraintData::vf08()
{
    return 15;
}
