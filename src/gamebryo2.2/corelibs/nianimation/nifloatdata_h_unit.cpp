#include "../../../../include/NiFloatData.h"
#include "../../../../include/NiLODData.h"

// @fnv 0x0052cf30
NiFloatData::NiFloatData()
    : NiObject()
    , m_uiNumKeys(0)
    , m_pKeyArray(0)
    , m_eRequestType(NiAnimationKey::NOINTERP)
    , m_ucKeyDataSize(0)
{
}
