// Fallout: New Vegas - original source reconstruction.
// Compiled translation unit for the guardpackage.h header unit.
//
// The original build compiled platforms/common/code/fallout/ai/
// guardpackage.h inside a fallout translation unit. This translation
// unit plays that role for the matcher build: it includes the header
// unit and defines the covered function's body the same way the
// original translation unit did.
//
// Compiler: MSVC9 SP1 15.00.30729.01, flags /Od /Oy- /GS /EHsc /Gy
#include "guardpackage.h"
#include "../../../include/GuardActorPackageData.h"

// @fnv 0x009f27f0
PTYPE GuardActorPackageData::GetPackageType()
{
    return PTYPE_GUARD;
}
