// gamebryo2.2/corelibs/nicollision/nisphere.cpp: free functions (1 function)
#include "../../../../include/NiPlane.h"

// Returns true when the plane comparison against other is not unequal, i.e. negates FUN_004390c0.
// @fnv 0x00439090
bool NiPlane::operator==(const NiPlane& other)
{
    return !HasEqualComponents(other);
}
