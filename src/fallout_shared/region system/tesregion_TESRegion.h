// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_TESREGION_DECLS_H
#define FNV_TESREGION_DECLS_H

#include "layout_support.h"
#include "../../../include/TESForm.h"
#include "layout_support.h"
#include "../../../include/NiColor.h"
#include "../../../include/TESRegion.h"
class RegionDataList;
class RegionPointList;
class TESWeather;
FNV_STATIC_ASSERT(sizeof(NiColor) == 12);
FNV_STATIC_ASSERT(offsetof(NiColor, r) == 0);
FNV_STATIC_ASSERT(offsetof(NiColor, g) == 4);
FNV_STATIC_ASSERT(offsetof(NiColor, b) == 8);
struct ListProxy;
struct DataProxy;
FNV_STATIC_ASSERT(sizeof(TESRegion) == 56);
FNV_STATIC_ASSERT(offsetof(TESRegion, m_pRegionDataList) == 24);
FNV_STATIC_ASSERT(offsetof(TESRegion, pRegionPointList) == 28);
FNV_STATIC_ASSERT(offsetof(TESRegion, m_pContainingWorldspace) == 32);
FNV_STATIC_ASSERT(offsetof(TESRegion, m_pRegionWeather) == 36);
FNV_STATIC_ASSERT(offsetof(TESRegion, fWeatherChance) == 40);
FNV_STATIC_ASSERT(offsetof(TESRegion, m_kDiffuseColor) == 44);
#endif
