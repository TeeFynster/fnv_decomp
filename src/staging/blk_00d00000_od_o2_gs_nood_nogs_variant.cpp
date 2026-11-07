
// src/staging/blk_00d00000_od_o2_gs_nood_nogs_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/staging/blk_00d00000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00d00000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
#include "../../include/hkpShapePhantom.h"
#include "../../include/hkpAabbPhantom.h"
#include "../../include/hkTransform.h"

struct hkVector4f
{
    float x;
    float y;
    float z;
    float w;
};

union hkQuadVector
{
    hkVector4f v;
    __m128 q;
};

struct hkAabbf
{
    hkVector4f m_kMinimumCorner;
    hkVector4f m_kMaximumCorner;
};

union hkAabbQ
{
    hkAabbf f;
    struct
    {
        __m128 m_kMinimumCorner;
        __m128 m_kMaximumCorner;
    } q;
};

// @fnv 0x00d05df0
// src: COMMUNITY 0x00d05df0
void __cdecl tranformPhantom(hkpPhantom* phantom, const hkTransform& transform)
{
    switch (phantom->getType())
    {
    case 1:
    case 2: {
        hkpShapePhantom* sp = static_cast<hkpShapePhantom*>(phantom);
        hkQuadVector c0;
        hkQuadVector c1;
        hkQuadVector c2;
        hkQuadVector t;
        c0.v = reinterpret_cast<const hkVector4f&>(sp->m_kMotionState.m_kMotionTransform.m_kColumn0);
        c1.v = reinterpret_cast<const hkVector4f&>(sp->m_kMotionState.m_kMotionTransform.m_kColumn1);
        c2.v = reinterpret_cast<const hkVector4f&>(sp->m_kMotionState.m_kMotionTransform.m_kColumn2);
        t.v = reinterpret_cast<const hkVector4f&>(sp->m_kMotionState.m_kMotionTransform.m_vTranslation);
        __m128 currentStorage[4];
        hkTransform& current = reinterpret_cast<hkTransform&>(currentStorage);
        current.m_kColumn0 = c0.q;
        current.m_kColumn1 = c1.q;
        current.m_kColumn2 = c2.q;
        current.m_vTranslation = t.q;
        current.ProcessTransformedMatrixCopy_00cb23e0(transform);
        sp->hkpShapePhantom_setTransform(current);
        break;
    }
    case 0: {
        hkpAabbPhantom* ap = static_cast<hkpAabbPhantom*>(phantom);
        hkAabbQ aabb;
        aabb.f = reinterpret_cast<const hkAabbf&>(ap->m_kBounds);
        aabb.q.m_kMinimumCorner = _mm_add_ps(transform.m_vTranslation, aabb.q.m_kMinimumCorner);
        aabb.q.m_kMaximumCorner = _mm_add_ps(transform.m_vTranslation, aabb.q.m_kMaximumCorner);
        ap->hkpAabbPhantom_setAabb(aabb);
        break;
    }
    }
}
