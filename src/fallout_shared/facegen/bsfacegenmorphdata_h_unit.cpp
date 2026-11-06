
// Fallout: New Vegas - original source reconstruction.
// Compiled translation unit for the bsfacegenmorphdata.h header unit.
//
// The original build compiled fallout_shared/facegen/bsfacegenmorphdata.h
// inside a fallout_shared translation unit. This translation unit plays
// that role for the matcher build: it includes the header unit and defines
// the covered function's body the same way the original translation unit
// did.
//
// Compiler: MSVC9 SP1 15.00.30729.01, flags /Od /Oy- /GS /EHsc /Gy
#include "../../../include/BSFaceGenMorphData.h"
#include "../../../include/BSFaceGenMorphDataHead.h"
#include "../../../include/NiObject.h"
#include "../../../include/NiRTTI.h"
#include "../../../include/NiRefObject.h"

// @fnv 0x00661d90
const NiRTTI* BSFaceGenMorphDataHead::GetRTTI() const
{
    return &ms_kRTTI;
}
