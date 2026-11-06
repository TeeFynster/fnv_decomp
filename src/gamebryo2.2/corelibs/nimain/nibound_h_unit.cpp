#include "../../../../include/NiBound.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiTransform.h"

inline NiPoint3::NiPoint3(float a, float b, float c) : x(a), y(b), z(c)
{}

inline NiPoint3 NiPoint3::operator*(float s) const
{
    NiPoint3 r;
    r.x = x * s;
    // Preserve the original x87 load order for the middle component.
    r.y = (*(volatile const float*)&y) * s;
    r.z = z * s;
    return r;
}

inline NiPoint3 NiPoint3::operator+(const NiPoint3& p) const
{
    return NiPoint3(x + p.x, y + p.y, z + p.z);
}

// M * v: each output coordinate is one matrix row dotted with v (x, y, z terms in that order)
#define M3_ROW_DOT_V(i) m_pEntry[i][0] * kV.x + m_pEntry[i][1] * kV.y + m_pEntry[i][2] * kV.z
inline NiPoint3 NiMatrix3::operator*(const NiPoint3& kV) const
{
    return NiPoint3(M3_ROW_DOT_V(0), M3_ROW_DOT_V(1), M3_ROW_DOT_V(2));
}
#undef M3_ROW_DOT_V

// @fnv 0x00a7fdd0
void NiBound::Update(const NiBound& bound, const NiTransform& transform)
{
    m_kCenter = transform.m_Translate + (transform.m_Rotate * bound.m_kCenter) * transform.m_fScale;
    m_fBoundRadius = bound.m_fBoundRadius * transform.m_fScale;
}
