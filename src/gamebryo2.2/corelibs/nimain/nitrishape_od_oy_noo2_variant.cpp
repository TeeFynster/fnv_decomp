
// src/gamebryo2.2/corelibs/nimain/nitrishape_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-25 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Oy- (unit src/gamebryo2.2/corelibs/nimain/nitrishape.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include "../../../../include/NiGeometry.h"
#include "../../../../include/NiTriBasedGeom.h"
#include "../../../../include/NiTriBasedGeomData.h"
#include "../../../../include/NiTriShape.h"
#include "../../../../include/NiTriShapeData.h"
#include "../../../../include/NiBillboardNode.h"

// @fnv 0x0051d000
// src: COMMUNITY 0x0051d000
void NiBillboardNode::SetMode_0051d000(int a)
{
    reinterpret_cast<NiTriBasedGeom*>(this)->SetBitfield(static_cast<unsigned short>(a), 7, 0);
}
