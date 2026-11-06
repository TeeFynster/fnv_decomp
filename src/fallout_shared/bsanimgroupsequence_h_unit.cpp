
// Fallout: New Vegas - original source reconstruction.
// Compiled translation unit for the bsanimgroupsequence.h header unit.
//
// The original build compiled fallout_shared/bsanimgroupsequence.h inside a
// fallout_shared translation unit. This translation unit plays that role for
// the matcher build: it includes the header unit and defines the covered
// function's body the same way the original translation unit did.
//
// Compiler: MSVC9 SP1 15.00.30729.01, flags /Od /Oy- /GS /EHsc /Gy
#include "../../include/BSAnimGroupSequence.h"
#include "../../include/NiControllerSequence.h"
#include "../../include/NiRTTI.h"

// @fnv 0x0049bb10
const NiRTTI* BSAnimGroupSequence::GetRTTI() const
{
    return &ms_kRTTI;
}
