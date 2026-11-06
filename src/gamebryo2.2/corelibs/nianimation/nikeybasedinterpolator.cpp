
// NiQuaternion component-wise inequality comparison.
// Returns true when any of the four quaternion components differs.

#include "../../../../include/NiQuaternion.h"

// Returns true if any of the four quaternion components differs from the corresponding component of kOther.
// @fnv 0x0064a290
bool NiQuaternion::operator!=(const NiQuaternion& kOther) const
{
    return m_fVectorX != kOther.m_fVectorX || m_fVectorY != kOther.m_fVectorY || m_fVectorZ != kOther.m_fVectorZ ||
           m_fScalarPart != kOther.m_fScalarPart;
}
