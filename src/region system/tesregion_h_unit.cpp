
#include "../../include/NiColor.h"
#include "../../include/TESRegion.h"

// @fnv 0x005d8a70
inline NiColor* TESRegion::GetDiffuseColor()
{
    return reinterpret_cast<NiColor*>(&m_kDiffuseColor);
}

void TESRegion_UnitReference()
{
    TESRegion* pRegion = 0;
    NiColor* pColor = pRegion->GetDiffuseColor();
    (void)pColor;
}
