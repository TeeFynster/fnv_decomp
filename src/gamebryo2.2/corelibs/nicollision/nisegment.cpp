
// src/gamebryo2.2/corelibs/nicollision/nisegment.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nicollision/nisegment.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiPoint3.h"

struct OriginDirectionPair
{
    NiPoint3 m_kStartPoint;
    NiPoint3 m_kLightVector;
    NiPoint3 NiSegment_GetPoint(float fS);
};
// @fnv 0x00eb6090
// src: GAMEBRYO_LIB 0x00eb6090
NiPoint3 OriginDirectionPair::NiSegment_GetPoint(float fS)
{
    NiPoint3 p;
    NiPoint3 s;
    s.x = fS * m_kLightVector.x;
    s.y = fS * m_kLightVector.y;
    s.z = fS * m_kLightVector.z;
    p.x = m_kStartPoint.x + s.x;
    p.y = m_kStartPoint.y + s.y;
    p.z = m_kStartPoint.z + s.z;
    return p;
}
