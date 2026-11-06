
// src/havok/physics/collide/shape/convex/convextranslate/hkpconvextranslateshape_gs_nogs_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/collide/shape/convex/convextranslate/hkpconvextranslateshape.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/shape/convex/convextranslate/hkpconvextranslateshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/convex/convextranslate/hkpconvextranslateshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../../include/hkpConvexTranslateShape.h"
#include "../../../../../../../include/hkpConvexShape.h"
#include "../../../../../../../include/hkVector4.h"

// The old, unused collection/buffer scaffolds described CalcSizeForSpu at slot 0x18,
// not hkpShapeCollection; neither has a function in this variant unit.

// The shared base declares slot 0x44 as vf17() without its output argument.
// Keep only this call signature locally until that declaration is complete.
typedef void (__thiscall* ConvexShapeOutputCall)(const hkpShape*, hkVector4*);

// The shared translate-shape header omits these overrides. An unused EDX argument
// preserves their thiscall ABI while using the shared class without a local copy.
// @fnv 0x00dd5fa0
void __fastcall GetConvexTranslateOutput(const hkpConvexTranslateShape* self, void*, hkVector4* value)
{
    const hkpShape* child = self->m_pContainedShape.m_pContainedShape;
    ConvexShapeOutputCall* vtable = *reinterpret_cast<ConvexShapeOutputCall* const*>(child);
    vtable[0x44 / sizeof(void*)](child, value);
    value->m_vComponents = _mm_add_ps(self->m_vTranslation.m_vComponents, value->m_vComponents);
}

// @fnv 0x00dd5fd0
void __fastcall GetConvexTranslateFirstVertex(const hkpConvexTranslateShape* self, void*, hkVector4* value)
{
    const hkpConvexShape* child = static_cast<const hkpConvexShape*>(self->m_pContainedShape.m_pContainedShape);
    child->GetFirstVertex(*value);
    value->m_vComponents = _mm_add_ps(self->m_vTranslation.m_vComponents, value->m_vComponents);
}
