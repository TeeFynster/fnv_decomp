// src/fallout_shared/packagedataescort_rtti2_variant.cpp - escort package RTTI comparison.
// Original source: d:/_fallout3/platforms/common/code/fallout shared/packagedataescort.cpp.
#include "../../include/TESEscortPackageData.h"
#include "../../include/TESPackageData.h"

struct EscortLocationComparison
{
    bool __thiscall IsDifferentFrom(LocationDescriptor* compare);
};

// The shared class does not yet declare this comparison method.
struct EscortComparison : TESEscortPackageData
{
    bool __thiscall TESEscortPackageData_Compare(TESPackageData* compare);
};

// @fnv 0x0067be40
// src: XBOX_PDB 0x0067be40
bool EscortComparison::TESEscortPackageData_Compare(TESPackageData* compare)
{
    TESEscortPackageData* other = dynamic_cast<TESEscortPackageData*>(compare);
    if (!other)
        return true;
    if (m_pPackageTarget)
    {
        if (reinterpret_cast<EscortLocationComparison*>(m_pPackageTarget)->IsDifferentFrom(other->m_pPackageTarget))
            return true;
    }
    else if (other->m_pPackageTarget)
    {
        return true;
    }
    if (m_iValue != other->m_iValue)
        return true;
    return false;
}
