// Unit-private PC declarations from public JohnnyGuitarNVSE layout facts.
// are not used because their padded rows do not describe the PC runtime.
#ifndef FNV_PROCESSLISTS_PRIVATE_IMPACTS_MATH_H
#define FNV_PROCESSLISTS_PRIVATE_IMPACTS_MATH_H

#include "processlists_layout_support.h"
#include "processlists_NiPoint3.h"
#include "../../../../include/NiMatrix3.h"

// Public BSMemObject has allocation operators only and no state or virtuals.
class BSMemObject
{
};


class NiTransform
{
  public:
    NiTransform();
    NiMatrix3 m_kRotate;
    NiPoint3 m_kTranslate;
    float m_fScale;
};

FNV_STATIC_ASSERT(sizeof(BSMemObject) == 1);
FNV_STATIC_ASSERT(sizeof(NiMatrix3) == 0x24);
FNV_STATIC_ASSERT(offsetof(NiMatrix3, m_pEntry) == 0);
FNV_STATIC_ASSERT(sizeof(NiTransform) == 0x34);
FNV_STATIC_ASSERT(offsetof(NiTransform, m_kRotate) == 0);
FNV_STATIC_ASSERT(offsetof(NiTransform, m_kTranslate) == 0x24);
FNV_STATIC_ASSERT(offsetof(NiTransform, m_fScale) == 0x30);
#endif
