
// src/speedtree/camera.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/speedtree/camera.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../include/CIdvCamera.h"
#include "../../include/CVec3.h"

// @fnv 0x00b3f0c0
// src: GUESS 0x00b3f0c0 (confidence: low)
CIdvCamera& CIdvCamera::AssignFields_00b3f0c0(const CIdvCamera& other)
{
    if (&other != this)
    {
        m_kTranslation = other.m_kTranslation;
    }
    return *this;
}
