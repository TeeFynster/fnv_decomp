
#include "nitransform_decls.h"
#pragma optimize("gty", on)
// @fnv 0x00a68bf0
void NiAVObject::UpdateWorldLoc()
{
 if (m_pkParent) {
  if ((unsigned char)(m_uFlags >> 9) & 1) m_kWorld = m_pkParent->m_kWorld;
  else m_kWorld = m_pkParent->m_kWorld * m_kLocal;
 } else m_kWorld = m_kLocal;
}
#pragma optimize("", off)
// @fnv 0x004b4880
void NiTransform::CalculateInverse(NiTransform& out)
{
 out.m_Rotate = m_Rotate.Transpose();
 out.m_fScale = 1.0f / m_fScale;
 out.m_Translate = NiPosData::ComputePositionAtTime(out.m_fScale, static_cast<const NiMatrix3&>(out.m_Rotate) * static_cast<const NiPoint3&>(m_Translate).GetNegatedVector());
}
#pragma optimize("", on)
