// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_CHECKLINEOFSIGHTFILTERWATER_H
#define FNV_CHECKLINEOFSIGHTFILTERWATER_H

#include "../../../include/Pathing__CheckLineOfSightFilter.h"
#include "../../../include/CheckLineOfSightFilterWater.h"

// The shared base is polymorphic (RTTI vftable 0x0106c944), so the water filter keeps m_bCheckWater at +4.
#pragma pack(push, 4)
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(CheckLineOfSightFilterWater) == 8);
FNV_STATIC_ASSERT(offsetof(CheckLineOfSightFilterWater, m_bCheckWater) == 4);
#endif
